#ifndef __OFFSETS_H__
#define __OFFSETS_H__
#pragma once

// 10.00- 10.01
#define XFAST_SYSCALL_addr              0x000001C0

// Names - Data
#define PRISON0_addr                    0x0111B8B0
#define ROOTVNODE_addr                  0x01B25BD0
#define PMAP_STORE_addr                 0x02182D60
#define DT_HASH_SEGMENT_addr            0x00CE6DC8

// Functions
#define pmap_protect_addr               0x000E2420
#define pmap_protect_p_addr             0x000E2467

// Patches
// debug menu error
#define debug_menu_error_patch1         0x004EC908
#define debug_menu_error_patch2         0x004ED9CE

// disable signature check
#define disable_signature_check_patch   0x006926E0

// enable debug RIFs
#define enable_debug_rifs_patch1        0x0064A510
#define enable_debug_rifs_patch2        0x0064A540

// allow sys_dynlib_dlsym in all processes
#define sys_dynlib_dlsym_patch1         0x0019025F
#define sys_dynlib_dlsym_patch2         0x001BEA40

// patch sys_mmap to allow rwx mappings
#define sys_mmap_patch                  0x000ED59A

// Patch setuid: Don't run kernel exploit more than once/privilege escalation
#define enable_setuid_patch             0x0026774F

// Enable RWX (kmem_alloc) mapping
#define kmem_alloc_patch1               0x0033B10C
#define kmem_alloc_patch2               0x0033B114

// Patch copyin/copyout: Allow userland + kernel addresses in both params
// copyin
#define enable_copyin_patch1            0x00472F67
#define enable_copyin_patch2            0x00472F73
// copyout
#define enable_copyout_patch1           0x00472E72
#define enable_copyout_patch2           0x00472E7E

// Patch copyinstr
#define enable_copyinstr_patch1         0x00473413
#define enable_copyinstr_patch2         0x0047341F
#define enable_copyinstr_patch3         0x00473450

// Patch memcpy stack
#define enable_memcpy_patch             0x00472D2D

// ptrace patches
#define enable_ptrace_patch1            0x0044E63D
#define enable_ptrace_patch2            0x0044EB11

// setlogin patch (for autolaunch check)
#define enable_setlogin_patch           0x0026A40C

// Patch to remove vm_fault: fault on nofault entry, addr %llx
#define enable_vmfault_patch            0x0042CEC6

// Patch mprotect: Allow RWX (mprotect) mapping
#define vm_map_protect_check            0x0039207B

// flatz allow mangled symbol in dynlib_do_dlsym
#define dynlib_do_dlsym_patch           0x001BC1A7

// Enable mount for unprivileged user
#define enable_mount_patch              0x001934F7

// patch suword_lwpid
// has a check to see if child_tid/parent_tid is in kernel memory, and it in so patch it
// Patch by: JOGolden
#define enable_suword_patch1            0x00473232
#define enable_suword_patch2            0x004EC908

// Enable *all* debugging logs (in vprintf)
// Patch by: SiSTRo
#define enable_debug_log_patch          0x000C51D7

// enable uart output
#define enable_uart_patch               0x01A78A78

#endif
