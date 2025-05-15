#ifndef __OFFSETS_H__
#define __OFFSETS_H__
#pragma once

// 505
#define	XFAST_SYSCALL_addr              0x00001C0

// Names - Data
#define PRISON0_addr                    0x10986A0
#define ROOTVNODE_addr                  0x22C1A70
#define PMAP_STORE_addr                 0x22CB570
#define DT_HASH_SEGMENT_addr            0x0B5EF30

// Functions
#define pmap_protect_addr               0x02E3090
#define pmap_protect_p_addr             0x02E30D4

// Patches
// debug menu error
#define debug_menu_error_patch1         0x04F9048
#define debug_menu_error_patch2         0x04FA15C

// disable signature check
#define disable_signature_check_patch   0x06A2700

// enable debug RIFs
#define enable_debug_rifs_patch1        0x064B2B0
#define enable_debug_rifs_patch2        0x064B2D0
	
// allow sys_dynlib_dlsym in all processes
#define sys_dynlib_dlsym_patch1         0x0237F3A
#define sys_dynlib_dlsym_patch2         0x02B2620

// patch sys_mmap to allow rwx mappings
#define sys_mmap_patch                  0x013D620

// Patch setuid: Don't run kernel exploit more than once/privilege escalation
#define enable_setuid_patch             0x0054A72

// Enable RWX (kmem_alloc) mapping
#define kmem_alloc_patch1               0x00FCD48
#define kmem_alloc_patch2               0x00FCD56

// Patch copyin/copyout: Allow userland + kernel addresses in both params
// copyin
#define enable_copyin_patch1            0x01EA767
#define enable_copyin_patch2            0x0

// copyout
#define enable_copyout_patch1           0x01EA682
#define enable_copyout_patch2           0x0

// Patch copyinstr
#define enable_copyinstr_patch1         0x01EAB93
#define enable_copyinstr_patch2         0x0
#define enable_copyinstr_patch3         0x01EABC3

// Patch memcpy stack
#define enable_memcpy_patch             0x01EA53D

// ptrace patches
#define enable_ptrace_patch1            0x030D9C3
#define enable_ptrace_patch2            0x030DE01

// patch sceSblACMgrIsAllowedSystemLevelDebugging
#define system_level_debugging_patch    0x0031A147

// patch ASLR, thanks 2much4u
#define disable_aslr_patch              0x00194875 // Not Sure

// Change directory depth limit from 9 to 64
#define depth_limit_patch               0x00050812

// setlogin patch (for autolaunch check)
#define enable_setlogin_patch           0x005775C

// Patch to remove vm_fault: fault on nofault entry, addr %llx
#define enable_vmfault_patch            0x02A4EB3

// Patch mprotect: Allow RWX (mprotect) mapping
#define vm_map_protect_check            0x01A3C08

// flatz allow mangled symbol in dynlib_do_dlsym
#define dynlib_do_dlsym_patch           0x02AFB47

// Enable mount for unprivileged user
#define enable_mount_patch              0x01DEBFE

// patch suword_lwpid
// has a check to see if child_tid/parent_tid is in kernel memory, and it in so patch it
// Patch by: JOGolden
#define enable_suword_patch1            0x01EA9D2
#define enable_suword_patch2            0x01EA9E1

// Enable *all* debugging logs (in vprintf)
// Patch by: SiSTRo
// enable debug log
#define enable_debug_log_patch          0x043612A

// enable uart output
#define enable_uart_patch               0x19ECEB0

#endif