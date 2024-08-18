#ifndef __OFFSETS_H__
#define __OFFSETS_H__
#pragma once

// 9.60
#define XFAST_SYSCALL_addr              0x000001C0

// Names - Data
#define PRISON0_addr                    0x011137D0
#define ROOTVNODE_addr                  0x021A6C30
#define PMAP_STORE_addr                 0x02228E88
#define DT_HASH_SEGMENT_addr            0x00CDEB58

// Functions
#define pmap_protect_addr               0x00431ED0
#define pmap_protect_p_addr             0x00431F17

// Patches
// debug menu error
#define debug_menu_error_patch1         0x004E9038
#define debug_menu_error_patch2         0x004EA06F

// disable signature check
#define disable_signature_check_patch   0x006AAC00

// enable debug RIFs
#define enable_debug_rifs_patch1        0x00643EA0
#define enable_debug_rifs_patch2        0x00643ED0

// allow sys_dynlib_dlsym in all processes
#define sys_dynlib_dlsym_patch1         0x0019FEDF
#define sys_dynlib_dlsym_patch2         0x00011960

// patch sys_mmap to allow rwx mappings
#define sys_mmap_patch                  0x00122D7A

// Patch setuid: Don't run kernel exploit more than once/privilege escalation
#define enable_setuid_patch             0x001FA52F

// Enable RWX (kmem_alloc) mapping
#define kmem_alloc_patch1               0x00188A9C
#define kmem_alloc_patch2               0x00188AA4

// Patch copyin/copyout: Allow userland + kernel addresses in both params
// copyin
#define enable_copyin_patch1            0x00201F07
#define enable_copyin_patch2            0x00201F13
// copyout
#define enable_copyout_patch1           0x00201E12
#define enable_copyout_patch2           0x00201E1E

// Patch copyinstr
#define enable_copyinstr_patch1         0x002023B3
#define enable_copyinstr_patch2         0x002023BF
#define enable_copyinstr_patch3         0x002023F0

// Patch memcpy stack
#define enable_memcpy_patch             0x00201CCD

// ptrace patches
#define enable_ptrace_patch1            0x0047A01D
#define enable_ptrace_patch2            0x0047A4F1

// setlogin patch (for autolaunch check)
#define enable_setlogin_patch           0x001FD1EC

// Patch to remove vm_fault: fault on nofault entry, addr %llx
#define enable_vmfault_patch            0x002C9CA6

// Patch mprotect: Allow RWX (mprotect) mapping
#define vm_map_protect_check            0x00196D3B

// flatz allow mangled symbol in dynlib_do_dlsym
#define dynlib_do_dlsym_patch           0x001BC1A7

// Enable mount for unprivileged user
#define enable_mount_patch              0x001BFD07

// patch suword_lwpid
// has a check to see if child_tid/parent_tid is in kernel memory, and it in so patch it
// Patch by: JOGolden
#define enable_suword_patch1            0x002021D2
#define enable_suword_patch2            0x002021E1

// Enable *all* debugging logs (in vprintf)
// Patch by: SiSTRo
#define enable_debug_log_patch          0x00205557

// enable uart output
#define enable_uart_patch               0x01A50BE0

#endif
