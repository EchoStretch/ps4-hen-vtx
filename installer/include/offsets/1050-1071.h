#ifndef __OFFSETS_H__
#define __OFFSETS_H__
#pragma once

// 10.70 - 10.71
#define XFAST_SYSCALL_addr              0x000001C0

// Names - Data
#define PRISON0_addr                    0x0111B910
#define ROOTVNODE_addr                  0x01BF81F0
#define PMAP_STORE_addr                 0x01B2CEE0
#define DT_HASH_SEGMENT_addr            0x00CE7008

// Functions
#define pmap_protect_addr               0x00046EF0
#define pmap_protect_p_addr             0x00046F37

// Patches
// debug menu error
#define debug_menu_error_patch1         0x004E6DA8
#define debug_menu_error_patch2         0x004E7E6E

// disable signature check
#define disable_signature_check_patch   0x006C4C00

// enable debug RIFs
#define enable_debug_rifs_patch1        0x0064E930
#define enable_debug_rifs_patch2        0x0064E960

// allow sys_dynlib_dlsym in all processes
#define sys_dynlib_dlsym_patch1         0x00213088
#define sys_dynlib_dlsym_patch2         0x002DAB60

// patch sys_mmap to allow rwx mappings
#define sys_mmap_patch                  0x0019C42A

// Patch setuid: Don't run kernel exploit more than once/privilege escalation
#define enable_setuid_patch             0x0008C1BF

// Enable RWX (kmem_alloc) mapping
#define kmem_alloc_patch1               0x00428A2C
#define kmem_alloc_patch2               0x00428A34

// Patch copyin/copyout: Allow userland + kernel addresses in both params
// copyin
#define enable_copyin_patch1            0x000D75B7
#define enable_copyin_patch2            0x000D75C3
// copyout
#define enable_copyout_patch1           0x000D74C2
#define enable_copyout_patch2           0x000D74CE

// Patch copyinstr
#define enable_copyinstr_patch1         0x000D7A63
#define enable_copyinstr_patch2         0x000D7A6F
#define enable_copyinstr_patch3         0x000D7AA0

// Patch memcpy stack
#define enable_memcpy_patch             0x000D737D

// ptrace patches
#define enable_ptrace_patch1            0x00424E9D
#define enable_ptrace_patch2            0x00425371

// setlogin patch (for autolaunch check)
#define enable_setlogin_patch           0x0008EE7C

// Patch to remove vm_fault: fault on nofault entry, addr %llx
#define enable_vmfault_patch            0x00303FA6

// Patch mprotect: Allow RWX (mprotect) mapping
#define vm_map_protect_check            0x0047B2EC

// flatz allow mangled symbol in dynlib_do_dlsym
#define dynlib_do_dlsym_patch           0x002D82C7

// Enable mount for unprivileged user
#define enable_mount_patch              0x00249EC7

// patch suword_lwpid
// has a check to see if child_tid/parent_tid is in kernel memory, and it in so patch it
// Patch by: JOGolden
#define enable_suword_patch1            0x000D7882
#define enable_suword_patch2            0x000D7891

// Enable *all* debugging logs (in vprintf)
// Patch by: SiSTRo
#define enable_debug_log_patch          0x00450F67

// enable uart output
#define enable_uart_patch               0x01A3BCA0

#endif
