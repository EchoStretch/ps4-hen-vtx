#include "ps4.h"

#include "defines.h"
#include "offsets.h"

#define PS4_UPDATE_FULL_PATH "/update/PS4UPDATE.PUP"
#define PS4_UPDATE_TEMP_PATH "/update/PS4UPDATE.PUP.net.temp"

extern char kpayload[];
extern unsigned kpayload_size;

int install_payload(struct thread *td, struct install_payload_args* args)
{
        UNUSED(td);
	uint8_t* kernel_base = (uint8_t*)(__readmsr(0xC0000082) - XFAST_SYSCALL_addr);

	void (*pmap_protect)(void * pmap, uint64_t sva, uint64_t eva, uint8_t pr) = (void *)(kernel_base + pmap_protect_addr);
	void *kernel_pmap_store = (void *)(kernel_base + PMAP_STORE_addr);

    	uint8_t* payload_data = args->payload_info->buffer;
    	size_t payload_size = args->payload_info->size;
	struct payload_header* payload_header = (struct payload_header*)payload_data;
	uint8_t* payload_buffer = (uint8_t*)&kernel_base[DT_HASH_SEGMENT_addr];

	if (!payload_data || payload_size < sizeof(payload_header) || payload_header->signature != 0x5041594C4F414458ull)
		return -1;

	// Use "kmem" for all patches
        uint8_t *kmem;

	// Disable write protection
	uint64_t cr0 = readCr0();
	writeCr0(cr0 & ~X86_CR0_WP);

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

	// Enable *all* debugging logs (in vprintf)
	// Patch by: SiSTRo
	kmem = (uint8_t *)&kernel_base[enable_debug_log_patch];
	kmem[0] = 0xEB;
	kmem[1] = 0x3B;

	// Enable UART
	kmem = (uint8_t *)&kernel_base[enable_uart_patch];
	kmem[0] = 0x00;
	kmem[1] = 0x00;
	kmem[2] = 0x00;
	kmem[3] = 0x00;

        // patch vm_map_protect check
	memcpy((void *)(kernel_base + vm_map_protect_check), "\x90\x90\x90\x90\x90\x90", 6);

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
        UNUSED(td);
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

        char fw_version[6] = {0};
        get_firmware_string(fw_version);
	printf_notification("Welcome To PS4HEN v"VERSION"\nPS4 Firmware %s", fw_version);

	printf_debug("Done.\n");

	return result;
}