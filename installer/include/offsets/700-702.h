#ifndef __OFFSETS_H__
#define __OFFSETS_H__
#pragma once

// 7.00-7.02
#define	XFAST_SYSCALL_addr              0x000001C0

// Names - Data
#define PRISON0_addr                    0x00113E398
#define ROOTVNODE_addr                  0x0022C5750
#define PMAP_STORE_addr                 0x0022C5268
#define DT_HASH_SEGMENT_addr            0x000D09F78

// Functions
#define pmap_protect_addr               0x0003E18A0
#define pmap_protect_p_addr             0x0003E18E7

// Patches
// debug menu error
#define debug_menu_error_patch1         0x005016FA
#define debug_menu_error_patch2         0x0050296C

// disable signature check
#define disable_signature_check_patch   0x006BE880

// enable debug RIFs
#define enable_debug_rifs_patch1        0x00668270
#define enable_debug_rifs_patch2        0x006682A0
	
// allow sys_dynlib_dlsym in all processes
#define sys_dynlib_dlsym_patch1         0x0009547B
#define sys_dynlib_dlsym_patch2         0x002F2C20

// patch sys_mmap to allow rwx mappings
#define sys_mmap_patch                  0x001D2336

// Patch setuid: Don't run kernel exploit more than once/privilege escalation
#define enable_setuid_patch             0x00087B70

// Enable RWX (kmem_alloc) mapping
#define kmem_alloc_patch1               0x001171BE
#define kmem_alloc_patch2               0x001171C4

// Patch copyin/copyout: Allow userland + kernel addresses in both params
// copyin
#define enable_copyin_patch1            0x0002F287
#define enable_copyin_patch2            0x0002F293
// copyout
#define enable_copyout_patch1           0x0002F192
#define enable_copyout_patch2           0x0002F19E

// Patch copyinstr
#define enable_copyinstr_patch1         0x0002F733
#define enable_copyinstr_patch2         0x0002F73F
#define enable_copyinstr_patch3         0x0002F770

// Patch memcpy stack
#define enable_memcpy_patch             0x0002F04D

// ptrace patches
#define enable_ptrace_patch1            0x000448ED
#define enable_ptrace_patch2            0x00044DAF

// setlogin patch (for autolaunch check)
#define enable_setlogin_patch           0x0008A8EC

// Patch to remove vm_fault: fault on nofault entry, addr %llx
#define enable_vmfault_patch            0x002BF756

// Patch mprotect: Allow RWX (mprotect) mapping
#define vm_map_protect_check            0x0036B05B

// flatz allow mangled symbol in dynlib_do_dlsym
#define dynlib_do_dlsym_patch           0x002F0367

// Enable mount for unprivileged user
#define enable_mount_patch              0x0029636A

// patch suword_lwpid
// has a check to see if child_tid/parent_tid is in kernel memory, and it in so patch it
// Patch by: JOGolden
#define enable_suword_patch1            0x0002F552
#define enable_suword_patch2            0x0002F561

// Enable *all* debugging logs (in vprintf)
// Patch by: SiSTRo
// enable debug log
#define enable_debug_log_patch          0x000BC817

// enable uart output
#define enable_uart_patch               0x01A6EAA0

#endif