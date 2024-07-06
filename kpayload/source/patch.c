#include <stddef.h>
#include <stdint.h>

#include "sections.h"
#include "sparse.h"
#include "offsets.h"
#include "freebsd_helper.h"
#include "amd_helper.h"

extern int (*proc_rwmem)(struct proc *p, struct uio *uio) PAYLOAD_BSS;
extern struct vmspace *(*vmspace_acquire_ref)(struct proc *p) PAYLOAD_BSS;
extern void (*vmspace_free)(struct vmspace *vm) PAYLOAD_BSS;
extern void (*vm_map_lock_read)(struct vm_map *map) PAYLOAD_BSS;
extern void (*vm_map_unlock_read)(struct vm_map *map) PAYLOAD_BSS;
extern int (*vm_map_lookup_entry)(struct vm_map *map, uint64_t address, struct vm_map_entry **entries) PAYLOAD_BSS;

extern size_t (*strlen)(const char *str) PAYLOAD_BSS;
extern void* (*malloc)(unsigned long size, void* type, int flags) PAYLOAD_BSS;
extern void (*free)(void* addr, void* type) PAYLOAD_BSS;
extern void* (*memcpy)(void* dst, const void* src, size_t len) PAYLOAD_BSS;
extern void* (*memset)(void *s, int c, size_t n) PAYLOAD_BSS;
extern int (*memcmp)(const void *ptr1, const void *ptr2, size_t num) PAYLOAD_BSS;
extern void (*eventhandler_register)(void *list, const char *name, void *func, void *arg, int priority) PAYLOAD_BSS;

extern void* M_TEMP PAYLOAD_BSS;
extern struct proc** ALLPROC PAYLOAD_BSS;

PAYLOAD_CODE static inline void *alloc(uint32_t size)
{
	return malloc(size, M_TEMP, 2);
}

PAYLOAD_CODE static inline void dealloc(void* addr)
{
	free(addr, M_TEMP);
}

PAYLOAD_CODE static struct proc *proc_find_by_name(const char *name)
{
	struct proc *p;

	if (!name)
		return NULL;


	p = *ALLPROC;

	do {
		if (!memcmp(p->p_comm, name, strlen(name)))
			return p;
	} while ((p = p->p_forw));

	return NULL;
}

PAYLOAD_CODE static int proc_get_vm_map(struct proc *p, struct proc_vm_map_entry **entries, size_t *num_entries)
{
	struct proc_vm_map_entry *info = NULL;
	struct vm_map_entry *entry = NULL;

	struct vmspace *vm = vmspace_acquire_ref(p);
	if (!vm)
		return -1;

	struct vm_map *map = &vm->vm_map;

	int num = map->nentries;
	if (!num) {
		vmspace_free(vm);
		return 0;
	}

	vm_map_lock_read(map);

	if (vm_map_lookup_entry(map, 0, &entry)) {
		vm_map_unlock_read(map);
		vmspace_free(vm);
		return -1;
	}

	info = (struct proc_vm_map_entry *)alloc(num * sizeof(struct proc_vm_map_entry));
	if (!info) {
		vm_map_unlock_read(map);
		vmspace_free(vm);
		return -1;
	}

	for (int i = 0; i < num; i++) {
		info[i].start = entry->start;
		info[i].end = entry->end;
		info[i].offset = entry->offset;
		info[i].prot = entry->prot & (entry->prot >> 8);
		memcpy(info[i].name, entry->name, sizeof(info[i].name));

		if (!(entry = entry->next))
			break;
	}

	vm_map_unlock_read(map);
	vmspace_free(vm);

	if (entries)
		*entries = info;

	if (num_entries)
		*num_entries = num;

	return 0;
}

PAYLOAD_CODE static int proc_rw_mem(struct proc *p, void *ptr, size_t size, void *data, size_t *n, int write)
{
	struct thread *td = curthread();
	struct iovec iov;
	struct uio uio;
	int r = 0;

	if (!p)
		return -1;

	if (size == 0) {
		if (n)
			*n = 0;

		return 0;
	}

	memset(&iov, 0, sizeof(iov));
	iov.iov_base = (uint64_t)data;
	iov.iov_len = size;

	memset(&uio, 0, sizeof(uio));
	uio.uio_iov = (uint64_t)&iov;
	uio.uio_iovcnt = 1;
	uio.uio_offset = (uint64_t)ptr;
	uio.uio_resid = (uint64_t)size;
	uio.uio_segflg = UIO_SYSSPACE;
	uio.uio_rw = write ? UIO_WRITE : UIO_READ;
	uio.uio_td = td;

	r = proc_rwmem(p, &uio);

	if (n)
		*n = (size_t)((uint64_t)size - uio.uio_resid);

	return r;
}

PAYLOAD_CODE static inline int proc_write_mem(struct proc *p, void *ptr, size_t size, void *data, size_t *n) 
{
	return proc_rw_mem(p, ptr, size, data, n, 1);
}

PAYLOAD_CODE int shellcore_fpkg_patch(void)
{
	uint8_t *text_seg_base = NULL;
	size_t n;

	struct proc_vm_map_entry *entries = NULL;
	size_t num_entries = 0;

	int ret = 0;

	uint32_t call_ofs_for__xor__eax_eax__3nop[] = {
		// call sceKernelIsGenuineCEX
		sceKernelIsGenuineCEX_patch1, 
		sceKernelIsGenuineCEX_patch2,
		sceKernelIsGenuineCEX_patch3,
		sceKernelIsGenuineCEX_patch4,
		// call nidf_libSceDipsw
		nidf_libSceDipsw_patch1,
		nidf_libSceDipsw_patch2,
		nidf_libSceDipsw_patch3,
		nidf_libSceDipsw_patch4,
	};

	uint8_t xor__eax_eax__inc__eax[5] = { 0x31, 0xC0, 0xFF, 0xC0, 0x90 };

	struct proc *ssc = proc_find_by_name("SceShellCore");

	if (!ssc) {
		ret = -1;
		goto error;
	}

	ret = proc_get_vm_map(ssc, &entries, &num_entries);
	if (ret) {
		goto error;
	}

	for (int i = 0; i < num_entries; i++) {
		if (entries[i].prot == (PROT_READ | PROT_EXEC)) {
			text_seg_base = (uint8_t *)entries[i].start;
			break;
		}
	}

	if (!text_seg_base) {
		ret = -1;
		goto error;
	}

	// enable installing of debug packages
	for (int i = 0; i < COUNT_OF(call_ofs_for__xor__eax_eax__3nop); i++) {
		ret = proc_write_mem(ssc, (void *)(text_seg_base + call_ofs_for__xor__eax_eax__3nop[i]), 5, "\x31\xC0\x90\x90\x90", &n);
		if (ret)
			goto error;
	}

	ret = proc_write_mem(ssc, text_seg_base + enable_data_mount_patch, sizeof(xor__eax_eax__inc__eax), xor__eax_eax__inc__eax, &n);
	if (ret) 
		goto error;

	// enable fpkg for patches
	ret = proc_write_mem(ssc, (void *)(text_seg_base + enable_fpkg_patch), 8, "\xE9\x96\x00\x00\x00\x90\x90\x90", &n);
	if (ret)
		goto error;

        #if FW < 950
	// check_disc_root_param_patch
	ret = proc_write_mem(ssc, (void *)(text_seg_base + check_disc_root_param_patch), 2, "\x90\xE9", &n);
	if (ret)
		goto error;
        #endif

        // app_installer_patch
        ret = proc_write_mem(ssc, (void *)(text_seg_base + app_installer_patch), 1, "\xEB", &n); 
        if (ret)
	        goto error;

        // check_system_version
        ret = proc_write_mem(ssc, (void *)(text_seg_base + check_system_version), 1, "\xEB", &n);
        if (ret)
	        goto error;

        // check_title_system_update_patch
        ret = proc_write_mem(ssc, (void *)(text_seg_base + check_title_system_update_patch), 4, "\x48\x31\xC0\xC3", &n);
        if (ret)
	        goto error;

	// this offset corresponds to "fake\0" string in the Shellcore's memory
	ret = proc_write_mem(ssc, (void *)(text_seg_base + fake_free_patch), 5, "free\0", &n);
	if (ret)
		goto error;

	// make pkgs installer working with external hdd
	ret = proc_write_mem(ssc, (void *)(text_seg_base + pkg_installer_patch), 1, "\0", &n);
	if (ret)
		goto error;

	// enable support with 6.xx external hdd
	ret = proc_write_mem(ssc, (void *)(text_seg_base + ext_hdd_patch), 1, "\xEB", &n);
	if (ret)
		goto error;

	// enable debug trophies on retail
	ret = proc_write_mem(ssc, (void *)(text_seg_base + debug_trophies_patch), 5, "\x31\xc0\x90\x90\x90", &n);
	if (ret)
		goto error;

        // never disable screenshot - credits to Biorn1950
        ret = proc_write_mem(ssc, (void *)(text_seg_base + disable_screenshot_patch), 5, "\x90\x90\x90\x90\x90", &n);
        if (ret) {
                goto error;

       // enable ps vr without spoofer
       ret = proc_write_mem(ssc, (void *)(text_seg_base + enable_psvr_patch), 3, "\x31\xC0\xC3", &n);
       if (ret)
               goto error;
}
error:
	if (entries)
		dealloc(entries);

	return ret;
}

PAYLOAD_CODE int shellui_patch(void)
{
    uint8_t *libkernel_sys_base = NULL,
            *executable_base = NULL,
            *app_base = NULL;

	size_t n;

	struct proc_vm_map_entry *entries = NULL;
	size_t num_entries = 0;

	int ret = 0;

	uint32_t ofs_to_ret_1[] = {
		sceSblRcMgrIsAllowDebugMenuForSettings_patch,
		sceSblRcMgrIsStoreMode_patch,
	};

	uint8_t mov__eax_1__ret[6] = { 0xB8, 0x01, 0x00, 0x00, 0x00, 0xC3 };

	struct proc *ssui = proc_find_by_name("SceShellUI");

	if (!ssui) {
		ret = -1;
		goto error;
	}

	ret = proc_get_vm_map(ssui, &entries, &num_entries);
	if (ret)
		goto error;

	for (int i = 0; i < num_entries; i++) {
        if (!memcmp(entries[i].name, "executable", 10) && (entries[i].prot >= (PROT_READ | PROT_EXEC))) {
            executable_base = (uint8_t *)entries[i].start;
            break;
        }
    }

    if (!executable_base ) {
        ret = 1;
        goto error;
    }

    // disable CreateUserForIDU
    ret = proc_write_mem(ssui, (void *)(executable_base  + CreateUserForIDU_patch), 4, "\x48\x31\xC0\xC3", &n);
    if (ret) {
        goto error;
    }

    for (int i = 0; i < num_entries; i++) {
        if (!memcmp(entries[i].name, "app.exe.sprx", 12) && (entries[i].prot >= (PROT_READ | PROT_EXEC))) {
            app_base  = (uint8_t *)entries[i].start;
            break;
        }
    }

    if (!app_base) {
        ret = 1;
        goto error;
    }

    // enable remote play menu - credits to Aida
    ret = proc_write_mem(ssui, (void *)(app_base  + remote_play_menu_patch), 5, "\xE9\x82\x02\x00\x00", &n);

    for (int i = 0; i < num_entries; i++) {
        if (!memcmp(entries[i].name, "libkernel_sys.sprx", 18) && (entries[i].prot >= (PROT_READ | PROT_EXEC))) {
            libkernel_sys_base = (uint8_t *)entries[i].start;
            break;
        }
    }

    if (!libkernel_sys_base) {
        ret = -1;
        goto error;
    }

    // enable debug settings menu
    for (int i = 0; i < COUNT_OF(ofs_to_ret_1); i++) {
        ret = proc_write_mem(ssui, (void *)(libkernel_sys_base + ofs_to_ret_1[i]), sizeof(mov__eax_1__ret), mov__eax_1__ret, &n);
        if (ret)
            goto error;
    }

error:
    if (entries)
        dealloc(entries);

    return ret;
}

PAYLOAD_CODE int remoteplay_patch() {

    uint8_t *executable_base = NULL;

    struct proc_vm_map_entry *entries = NULL;
    size_t num_entries;
    size_t n;

    int ret = 0;

    struct proc *srp = proc_find_by_name("SceRemotePlay");

    if (!srp) {
        ret = 1;
        goto error;
    }

    if (proc_get_vm_map(srp, &entries, &num_entries)) {
        ret = 1;
        goto error;
    }

    for (int i = 0; i < num_entries; i++) {
        if (!memcmp(entries[i].name, "executable", 10) && (entries[i].prot == (PROT_READ | PROT_EXEC))) {
            executable_base = (uint8_t *)entries[i].start;
            break;
        }
    }

    if (!executable_base) {
        ret = 1;
        goto error;
    }

    // patch SceRemotePlay process
    ret = proc_write_mem(srp, (void *)(executable_base + SceRemotePlay_patch1), 1, "\x01", &n);
    if (ret) {
        goto error;
    }

    ret = proc_write_mem(srp, (void *)(executable_base + SceRemotePlay_patch2), 2, "\xEB\x1E", &n);
    if (ret) {
        goto error;
    }

    error:
    if (entries) {
        dealloc(entries);
    }

    return ret;
}

PAYLOAD_CODE void set_dipsw(int debug_patch) {
	uint64_t kernbase = getkernbase();

	uint64_t cr0 = readCr0();
	writeCr0(cr0 & ~X86_CR0_WP);
	uint64_t flags = intr_disable();

	uint8_t *dipsw = (uint8_t *)(kernbase + DIPSW_addr);
	dipsw[0x36] = debug_patch ? 0x37 : 0x24;
	dipsw[0x59] = debug_patch ? 0x03 : 0x00;
	dipsw[0x5A] = debug_patch ? 0x01 : 0x00;
	dipsw[0x78] = debug_patch ? 0x01 : 0x00;

	intr_restore(flags);
	writeCr0(cr0);
}

PAYLOAD_CODE void patch_debug_dipsw()
{
	set_dipsw(1);
}

PAYLOAD_CODE void restore_retail_dipsw()
{
	set_dipsw(0);
}

PAYLOAD_CODE void apply_patches() {
	shellui_patch();
	remoteplay_patch();
}

PAYLOAD_CODE void install_patches()
{
	apply_patches();
	eventhandler_register(NULL, "system_suspend_phase3", &restore_retail_dipsw, NULL, EVENTHANDLER_PRI_PRE_FIRST);
	eventhandler_register(NULL, "system_resume_phase4", &apply_patches, NULL, EVENTHANDLER_PRI_LAST);
}