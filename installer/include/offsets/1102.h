#ifndef __OFFSETS_H__
#define __OFFSETS_H__
#pragma once

// 11.02
#define XFAST_SYSCALL_addr              0x00001C0

// Names - Data
#define PRISON0_addr                    0x0111F830
#define ROOTVNODE_addr                  0x02116640
#define PMAP_STORE_addr                 0x02162A88
#define DT_HASH_SEGMENT_addr            0x00CEB1A8

// Functions
#define pmap_protect_addr               0x00116CD0
#define pmap_protect_p_addr             0x00116D17

// Patches
// debug menu error
#define debug_menu_error_patch1         0x004EE2B8
#define debug_menu_error_patch2         0x004EF37E

// disable signature check
#define disable_signature_check_patch   0x00684E50

// enable debug RIFs
#define enable_debug_rifs_patch1        0x0064BF70
#define enable_debug_rifs_patch2        0x0064BFA0

// allow sys_dynlib_dlsym in all processes
#define sys_dynlib_dlsym_patch1         0x001E4CC8
#define sys_dynlib_dlsym_patch2         0x00088CE0

// patch sys_mmap to allow rwx mappings
#define sys_mmap_patch                  0x0015628A

// Patch setuid: Don't run kernel exploit more than once/privilege escalation
#define enable_setuid_patch             0x004314AF

// Enable RWX (kmem_alloc) mapping
#define kmem_alloc_patch1               0x00245EFC
#define kmem_alloc_patch2               0x00245F04

// Patch copyin/copyout: Allow userland + kernel addresses in both params
// copyin
#define enable_copyin_patch1            0x002DE057
#define enable_copyin_patch2            0x002DE063
// copyout
#define enable_copyout_patch1           0x002DDF62
#define enable_copyout_patch2           0x002DDF6E

// Patch copyinstr
#define enable_copyinstr_patch1         0x002DE503
#define enable_copyinstr_patch2         0x002DE50F
#define enable_copyinstr_patch3         0x002DE540

// Patch memcpy stack
#define enable_memcpy_patch             0x002DDE1D

// ptrace patches
#define enable_ptrace_patch1            0x003842BD
#define enable_ptrace_patch2            0x00384791

//patch sceSblACMgrIsAllowedSystemLevelDebugging
#define system_level_debugging_patch    0x003D0E00

// patch ASLR, thanks 2much4u
#define disable_aslr_patch              0x003B11C4

// Change directory depth limit from 9 to 64
#define depth_limit_patch               0x0028FF46																							  

// setlogin patch (for autolaunch check)
#define enable_setlogin_patch           0x0043416C

// Patch to remove vm_fault: fault on nofault entry, addr %llx
#define enable_vmfault_patch            0x0031E8C6

// Patch mprotect: Allow RWX (mprotect) mapping
#define vm_map_protect_check            0x0035C90C

// flatz allow mangled symbol in dynlib_do_dlsym
#define dynlib_do_dlsym_patch           0x00086447

// Enable mount for unprivileged user
#define enable_mount_patch              0x00388B57

// patch suword_lwpid
// has a check to see if child_tid/parent_tid is in kernel memory, and it in so patch it
// Patch by: JOGolden																										 
#define enable_suword_patch1            0x002DE322
#define enable_suword_patch2            0x002DE331

// Enable *all* debugging logs (in vprintf)
// Patch by: SiSTRo			   
#define enable_debug_log_patch          0x002FCCD7

// enable uart output
#define enable_uart_patch               0x0152CFF8

#endif
