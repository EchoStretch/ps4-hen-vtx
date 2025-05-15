#ifndef __OFFSETS_H__
#define __OFFSETS_H__
#pragma once

// 6.72
#define	XFAST_SYSCALL_addr              0x000001C0

// Names - Data
#define PRISON0_addr                    0x0113E518
#define ROOTVNODE_addr                  0x02300320
#define PMAP_STORE_addr                 0x01BB7880
#define DT_HASH_SEGMENT_addr            0x00D09FB0

// Functions
#define pmap_protect_addr               0x00050F50
#define pmap_protect_p_addr             0x00050F9C

// Patches
// debug menu error
#define debug_menu_error_patch1         0x00507B09
#define debug_menu_error_patch2         0x00508D5C

// disable signature check
#define disable_signature_check_patch   0x006A8EB0

// enable debug RIFs
#define enable_debug_rifs_patch1        0x0066AEB0
#define enable_debug_rifs_patch2        0x0066AEE0

// allow sys_dynlib_dlsym in all processes
#define sys_dynlib_dlsym_patch1         0x001D895A
#define sys_dynlib_dlsym_patch2         0x0041A2D0

// patch sys_mmap to allow rwx mappings
#define sys_mmap_patch                  0x000AB57A

// Patch setuid: Don't run kernel exploit more than once/privilege escalation
#define enable_setuid_patch             0x0010BED0

// Enable RWX (kmem_alloc) mapping
#define kmem_alloc_patch1               0x002507F5
#define kmem_alloc_patch2               0x00250803

// Patch copyin/copyout: Allow userland + kernel addresses in both params
// copyin
#define enable_copyin_patch1            0x003C17F7
#define enable_copyin_patch2            0x003C1803
// copyout
#define enable_copyout_patch1           0x003C1702
#define enable_copyout_patch2           0x003C170E

// Patch copyinstr
#define enable_copyinstr_patch1         0x003C1CA3
#define enable_copyinstr_patch2         0x003C1CAF
#define enable_copyinstr_patch3         0x003C1CE0

// Patch memcpy stack
#define enable_memcpy_patch             0x003C15BD

// ptrace patches
#define enable_ptrace_patch1            0x0010F892
#define enable_ptrace_patch2            0x0010FD22

//patch sceSblACMgrIsAllowedSystemLevelDebugging
#define system_level_debugging_patch    0x00233BD0

// patch ASLR, thanks 2much4u
#define disable_aslr_patch              0x003CECE1

// Change directory depth limit from 9 to 64
#define depth_limit_patch               0x002D2656

// setlogin patch (for autolaunch check)
#define enable_setlogin_patch           0x0010EC1C

// Patch to remove vm_fault: fault on nofault entry, addr %llx
#define enable_vmfault_patch            0x000BC8F6

// Patch mprotect: Allow RWX (mprotect) mapping
#define vm_map_protect_check            0x00451DB8

// flatz allow mangled symbol in dynlib_do_dlsym
#define dynlib_do_dlsym_patch           0x00417A27

// Enable mount for unprivileged user
#define enable_mount_patch              0x0044026A

// patch suword_lwpid
// has a check to see if child_tid/parent_tid is in kernel memory, and it in so patch it
// Patch by: JOGolden
#define enable_suword_patch1            0x03C1AC2
#define enable_suword_patch2            0x03C1AD1

// Enable *all* debugging logs (in vprintf)
// Patch by: SiSTRo
// enable debug log
#define enable_debug_log_patch          0x00123367

// enable uart output
#define enable_uart_patch               0x01A6EB18

#endif