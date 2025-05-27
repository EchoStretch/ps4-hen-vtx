#include "ps4.h"

#include "defines.h"
#include "offsets.h"

#define PS4_UPDATE_FULL_PATH "/update/PS4UPDATE.PUP"
#define PS4_UPDATE_TEMP_PATH "/update/PS4UPDATE.PUP.net.temp"

extern char kpayload[];
extern unsigned kpayload_size;

int install_payload(struct thread *td, struct install_payload_args* args)
{
	struct ucred* cred;
	struct filedesc* fd;

	fd = td->td_proc->p_fd;
	cred = td->td_proc->p_ucred;

	uint8_t* kernel_base = (uint8_t*)(__readmsr(0xC0000082) - XFAST_SYSCALL_addr);
	uint8_t* kernel_ptr = (uint8_t*)kernel_base;
	void** got_prison0 = (void**)&kernel_ptr[PRISON0_addr];
	void** got_rootvnode = (void**)&kernel_ptr[ROOTVNODE_addr];

	void (*pmap_protect)(void * pmap, uint64_t sva, uint64_t eva, uint8_t pr) = (void *)(kernel_base + pmap_protect_addr);
	void *kernel_pmap_store = (void *)(kernel_base + PMAP_STORE_addr);

	uint8_t* payload_data = args->payload_info->buffer;
	size_t payload_size = args->payload_info->size;
	struct payload_header* payload_header = (struct payload_header*)payload_data;
	uint8_t* payload_buffer = (uint8_t*)&kernel_base[DT_HASH_SEGMENT_addr];

	if (!payload_data || payload_size < sizeof(payload_header) || payload_header->signature != 0x5041594C4F414458ull)
		return -1;

	cred->cr_uid = 0;
	cred->cr_ruid = 0;
	cred->cr_rgid = 0;
	cred->cr_groups[0] = 0;

	cred->cr_prison = *got_prison0;
	fd->fd_rdir = fd->fd_jdir = *got_rootvnode;

	// escalate ucred privs, needed for access to the filesystem ie* mounting & decrypting files
	void *td_ucred = *(void **)(((char *)td) + 304); // p_ucred == td_ucred

	// sceSblACMgrIsSystemUcred
	uint64_t *sonyCred = (uint64_t *)(((char *)td_ucred) + 96);
	*sonyCred = 0xffffffffffffffff;

	// sceSblACMgrGetDeviceAccessType
	uint64_t *sceProcType = (uint64_t *)(((char *)td_ucred) + 88);
	*sceProcType = 0x3801000000000013; // Max access

	// sceSblACMgrHasSceProcessCapability
	uint64_t *sceProcCap = (uint64_t *)(((char *)td_ucred) + 104);
	*sceProcCap = 0xffffffffffffffff; // Sce Process

	// Use "kmem" for all patches
        uint8_t *kmem;

	// Disable write protection
	uint64_t cr0 = readCr0();
	writeCr0(cr0 & ~X86_CR0_WP);

	// Enable UART
	kmem = (uint8_t *)&kernel_base[enable_uart_patch];
	kmem[0] = 0x00;
	kmem[1] = 0x00;
	kmem[2] = 0x00;
	kmem[3] = 0x00;

        //flatz Patch sys_dynlib_dlsym: Allow from anywhere
	kmem = (uint8_t *)&kernel_base[sys_dynlib_dlsym_patch1];
	kmem[0] = 0xEB;
	kmem[1] = 0x4C;

	kmem = (uint8_t *)&kernel_base[sys_dynlib_dlsym_patch2];
	kmem[0] = 0x31;
	kmem[1] = 0xC0;
	kmem[2] = 0xC3;

	// Patch sys_mmap: Allow RWX (read-write-execute) mapping
	kmem = (uint8_t *)&kernel_base[sys_mmap_patch];
	kmem[0] = 0x37;
	kmem[3] = 0x37;

	// Patch setuid: Don't run kernel exploit more than once/privilege escalation
	kmem = (uint8_t *)&kernel_base[enable_setuid_patch];
	kmem[0] = 0xB8;
	kmem[1] = 0x00;
	kmem[2] = 0x00;
	kmem[3] = 0x00;
	kmem[4] = 0x00;

	// Enable RWX (kmem_alloc) mapping
	kmem = (uint8_t *)&kernel_base[kmem_alloc_patch1];
	kmem[0] = 0x07;

	kmem = (uint8_t *)&kernel_base[kmem_alloc_patch2];
	kmem[0] = 0x07;

	// Patch copyin/copyout: Allow userland + kernel addresses in both params
	// copyin
	kmem = (uint8_t *)&kernel_base[enable_copyin_patch1];
	kmem[0] = 0x90;
	kmem[1] = 0x90;
	
	if (FW != 505)
	{
	kmem = (uint8_t *)&kernel_base[enable_copyin_patch2];
	kmem[0] = 0x90;
	kmem[1] = 0x90;
	kmem[2] = 0x90;
	}
	
	// copyout
	kmem = (uint8_t *)&kernel_base[enable_copyout_patch1];
	kmem[0] = 0x90;
	kmem[1] = 0x90;

	if (FW != 505)
	{
	kmem = (uint8_t *)&kernel_base[enable_copyout_patch2];
	kmem[0] = 0x90;
	kmem[1] = 0x90;
	kmem[2] = 0x90;
	}
	
	// Patch copyinstr
	kmem = (uint8_t *)&kernel_base[enable_copyinstr_patch1];
	kmem[0] = 0x90;
	kmem[1] = 0x90;
	
	if (FW != 505)
	{
	kmem = (uint8_t *)&kernel_base[enable_copyinstr_patch2];
	kmem[0] = 0x90;
	kmem[1] = 0x90;
	kmem[2] = 0x90;
	}
	

	kmem = (uint8_t *)&kernel_base[enable_copyinstr_patch3];
	kmem[0] = 0x90;
	kmem[1] = 0x90;

	// Patch memcpy stack
	kmem = (uint8_t *)&kernel_base[enable_memcpy_patch];
	kmem[0] = 0xEB;

	// ptrace patches
	kmem = (uint8_t*)&kernel_base[enable_ptrace_patch1];
	kmem[0] = 0x90;
	kmem[1] = 0x90;
	kmem[2] = 0x90;
	kmem[3] = 0x90;
	kmem[4] = 0x90;
	kmem[5] = 0x90;

	// second ptrace patch
	// via DeathRGH
	kmem = (uint8_t *)&kernel_base[enable_ptrace_patch2];
	kmem[0] = 0xE9;
	kmem[1] = 0x7C;
	kmem[2] = 0x02;
	kmem[3] = 0x00;
	kmem[4] = 0x00;

    	//patch sceSblACMgrIsAllowedSystemLevelDebugging
	kmem = (uint8_t *)&kernel_base[system_level_debugging_patch];
	kmem[0] = 0x31;
	kmem[1] = 0xC0;
	kmem[2] = 0xFF;
	kmem[3] = 0xC0;
	kmem[4] = 0xC3;

   	// patch ASLR, thanks 2much4u
   	kmem = (uint8_t *)&kernel_base[disable_aslr_patch];
   	kmem[0] = 0x90;
   	kmem[1] = 0x90;

        // Change directory depth limit from 9 to 64
	kmem = (uint8_t *)&kernel_base[depth_limit_patch];
	kmem[0] = 0x40;

	// setlogin patch (for autolaunch check)
	kmem = (uint8_t *)&kernel_base[enable_setlogin_patch];
	kmem[0] = 0x48;
	kmem[1] = 0x31;
	kmem[2] = 0xC0;
	kmem[3] = 0x90;
	kmem[4] = 0x90;

	// Patch to remove vm_fault: fault on nofault entry, addr %llx
	kmem = (uint8_t *)&kernel_base[enable_vmfault_patch];
	kmem[0] = 0x90;
	kmem[1] = 0x90;
	kmem[2] = 0x90;
	kmem[3] = 0x90;
	kmem[4] = 0x90;
	kmem[5] = 0x90;

	// Patch mprotect: Allow RWX (mprotect) mapping
	kmem = (uint8_t *)&kernel_base[vm_map_protect_check];
	kmem[0] = 0x90;
	kmem[1] = 0x90;
	kmem[2] = 0x90;
	kmem[3] = 0x90;
	kmem[4] = 0x90;
	kmem[5] = 0x90;

	// flatz disable pfs signature check
	kmem = (uint8_t *)&kernel_base[disable_signature_check_patch];
	kmem[0] = 0x31;
	kmem[1] = 0xC0;
	kmem[2] = 0xC3;

	// flatz enable debug RIFs
	kmem = (uint8_t *)&kernel_base[enable_debug_rifs_patch1];
	kmem[0] = 0xB0;
	kmem[1] = 0x01;
	kmem[2] = 0xC3;

	kmem = (uint8_t *)&kernel_base[enable_debug_rifs_patch2];
	kmem[0] = 0xB0;
	kmem[1] = 0x01;
	kmem[2] = 0xC3;

	// Enable *all* debugging logs (in vprintf)
	// Patch by: SiSTRo
	kmem = (uint8_t *)&kernel_base[enable_debug_log_patch];
	kmem[0] = 0xEB;
	kmem[1] = 0x3B;

	// flatz allow mangled symbol in dynlib_do_dlsym
	kmem = (uint8_t *)&kernel_base[dynlib_do_dlsym_patch];
	kmem[0] = 0x90;
	kmem[1] = 0x90;
	kmem[2] = 0x90;
	kmem[3] = 0x90;
	kmem[4] = 0x90;
	kmem[5] = 0x90;


	// Enable mount for unprivileged user
	kmem = (uint8_t *)&kernel_base[enable_mount_patch];
	kmem[0] = 0x90;
	kmem[1] = 0x90;
	kmem[2] = 0x90;
	kmem[3] = 0x90;
	kmem[4] = 0x90;
	kmem[5] = 0x90;

	// patch suword_lwpid
	// has a check to see if child_tid/parent_tid is in kernel memory, and it in so patch it
	// Patch by: JOGolden
	kmem = (uint8_t *)&kernel_base[enable_suword_patch1];
	kmem[0] = 0x90;
	kmem[1] = 0x90;

	kmem = (uint8_t *)&kernel_base[enable_suword_patch2];
	kmem[0] = 0x90;
	kmem[1] = 0x90;


	// Patch debug setting errors
	kmem = (uint8_t *)&kernel_base[debug_menu_error_patch1];
	kmem[0] = 0x00;
	kmem[1] = 0x00;
	kmem[2] = 0x00;
	kmem[3] = 0x00;

	kmem = (uint8_t *)&kernel_base[debug_menu_error_patch2];
	kmem[0] = 0x00;
	kmem[1] = 0x00;
	kmem[2] = 0x00;
	kmem[3] = 0x00;

	// install kpayload
	memset(payload_buffer, 0, PAGE_SIZE);
	memcpy(payload_buffer, payload_data, payload_size);

	uint64_t sss = ((uint64_t)payload_buffer) & ~(uint64_t)(PAGE_SIZE-1);
	uint64_t eee = ((uint64_t)payload_buffer + payload_size + PAGE_SIZE - 1) & ~(uint64_t)(PAGE_SIZE-1);
	kernel_base[pmap_protect_p_addr] = 0xEB;
	pmap_protect(kernel_pmap_store, sss, eee, 7);
	kernel_base[pmap_protect_p_addr] = 0x75;

	// Restore write protection
	writeCr0(cr0);

	int (*payload_entrypoint)();
	*((void**)&payload_entrypoint) = (void*)(&payload_buffer[payload_header->entrypoint_offset]);

	return payload_entrypoint();
}

static inline void patch_update(void)
{
  unlink(PS4_UPDATE_FULL_PATH);
  rmdir(PS4_UPDATE_FULL_PATH);
  if (mkdir(PS4_UPDATE_FULL_PATH, 0777) != 0) {
    printf_debug("Failed to create /update/PS4UPDATE.PUP.");
  }
	
  unlink(PS4_UPDATE_TEMP_PATH);
  rmdir(PS4_UPDATE_TEMP_PATH);
  if (mkdir(PS4_UPDATE_TEMP_PATH, 0777) != 0) {
    printf_debug("Failed to create /update/PS4UPDATE.PUP.net.temp.");
  }
}

int _main(struct thread *td)
 {
	char fw_version[6] = {0};
    	get_firmware_string(fw_version);
	int result;

	initKernel();
	initLibc();

    	printf_debug("Starting...\n");

	struct payload_info payload_info;
	payload_info.buffer = (uint8_t *)kpayload;
	payload_info.size = (size_t)kpayload_size;

	errno = 0;

	result = kexec(&install_payload, &payload_info);
	result = !result ? 0 : errno;
	printf_debug("install_payload: %d\n", result);

	patch_update();
	initSysUtil();

	printf_notification("Welcome To PS4HEN v"VERSION"\nPS4 Firmware %s", fw_version);

	printf_debug("Done.\n");

	return result;
}
