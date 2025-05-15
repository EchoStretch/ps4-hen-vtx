#ifndef __OFFSETS_H__
#define __OFFSETS_H__
#pragma once

// 12.00
#define XFAST_SYSCALL_addr              0x000001C0

// Names - Data
#define PRISON0_addr                    0x0111FA18
#define ROOTVNODE_addr                  0x02136E90
#define PMAP_STORE_addr                 0x01B2C3A0
#define DT_HASH_SEGMENT_addr            0x00CEB218

// Functions
#define pmap_protect_addr               0x00059DF0
#define pmap_protect_p_addr             0x00059E37

// Patches
// debug menu error
#define debug_menu_error_patch1         0x004E8748
#define debug_menu_error_patch2         0x004E980E

// disable signature check
#define disable_signature_check_patch   0x0069D9A0

// enable debug RIFs
#define enable_debug_rifs_patch1        0x0064EB30
#define enable_debug_rifs_patch2        0x0064EB60

// allow sys_dynlib_dlsym in all processes
#define sys_dynlib_dlsym_patch1         0x001B7718
#define sys_dynlib_dlsym_patch2         0x003BD860

// patch sys_mmap to allow rwx mappings
#define sys_mmap_patch                  0x001FA71A

// Patch setuid: Don't run kernel exploit more than once/privilege escalation
#define enable_setuid_patch             0x003914DF

// Enable RWX (kmem_alloc) mapping
#define kmem_alloc_patch1               0x00465AAC
#define kmem_alloc_patch2               0x00465AB4

// Patch copyin/copyout: Allow userland + kernel addresses in both params
// copyin
#define enable_copyin_patch1            0x002BD6C7
#define enable_copyin_patch2            0x002BD6D3

// copyout
#define enable_copyout_patch1           0x002BD5D2
#define enable_copyout_patch2           0x002BD5DE

// Patch copyinstr
#define enable_copyinstr_patch1         0x002BDB73
#define enable_copyinstr_patch2         0x002BDB7F
#define enable_copyinstr_patch3         0x002BDBB0

// Patch memcpy stack
#define enable_memcpy_patch             0x002BD48D

// ptrace patches
#define enable_ptrace_patch1            0x0036699d
#define enable_ptrace_patch2            0x00366e71

//patch sceSblACMgrIsAllowedSystemLevelDebugging
#define system_level_debugging_patch    0x003B2CD0

// patch ASLR, thanks 2much4u
#define disable_aslr_patch              0x00477C54

// Change directory depth limit from 9 to 64
#define depth_limit_patch               0x00030F66														

// setlogin patch (for autolaunch check)
#define enable_setlogin_patch           0x0039419C

// Patch to remove vm_fault: fault on nofault entry, addr %llx
#define enable_vmfault_patch            0x001E20A6

// Patch mprotect: Allow RWX (mprotect) mapping
#define vm_map_protect_check            0x002FC0EC

// flatz allow mangled symbol in dynlib_do_dlsym
#define dynlib_do_dlsym_patch           0x003BAFC7

// Enable mount for unprivileged user
#define enable_mount_patch              0x00151267

// patch suword_lwpid
// has a check to see if child_tid/parent_tid is in kernel memory, and it in so patch it
// Patch by: JOGolden
#define enable_suword_patch1            0x002BD992
#define enable_suword_patch2            0x002BD9A1

// Enable *all* debugging logs (in vprintf)
// Patch by: SiSTRo
#define enable_debug_log_patch          0x002E04C7

// enable uart output
#define enable_uart_patch               0x01A47F40

#endif
