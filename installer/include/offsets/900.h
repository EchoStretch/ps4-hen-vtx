#ifndef __OFFSETS_H__
#define __OFFSETS_H__
#pragma once

// 9.00
#define	XFAST_SYSCALL_addr              0x000001C0

// Names - Data
#define PRISON0_addr                    0x0111F870
#define ROOTVNODE_addr                  0x021EFF20
#define PMAP_STORE_addr                 0X01B904B0
#define DT_HASH_SEGMENT_addr            0x00C2C520

// Functions
#define pmap_protect_addr               0x0012FA90
#define pmap_protect_p_addr             0x0012FAD7

// Patches
// debug menu error
#define debug_menu_error_patch1         0x004E8E48
#define debug_menu_error_patch2         0x004EA12F

// flatz disable pfs signature check
#define disable_signature_check_patch   0x006885C0

// flatz enable debug RIFs
#define enable_debug_rifs_patch1        0x00650430
#define enable_debug_rifs_patch2        0x00650460

// allow sys_dynlib_dlsym in all processes
#define sys_dynlib_dlsym_patch1         0x0023B67F
#define sys_dynlib_dlsym_patch2         0x00221B40

// patch sys_mmap to allow rwx mappings
#define sys_mmap_patch                  0x0016632A

// Patch setuid: Don't run kernel exploit more than once/privilege escalation
#define enable_setuid_patch             0x000019FF

// Enable RWX (kmem_alloc) mapping
#define kmem_alloc_patch1               0x0037BF3C
#define kmem_alloc_patch2               0x0037BF44

// Patch copyin/copyout: Allow userland + kernel addresses in both params
// copyin
#define enable_copyin_patch1            0x002716F7
#define enable_copyin_patch2            0x00271703
// copyout
#define enable_copyout_patch1           0x00271602
#define enable_copyout_patch2           0x0027160E

// Patch copyinstr
#define enable_copyinstr_patch1         0x00271BA3
#define enable_copyinstr_patch2         0x00271BAF
#define enable_copyinstr_patch3         0x00271BE0

// Patch memcpy stack
#define enable_memcpy_patch             0x002714BD

// ptrace patches
#define enable_ptrace_patch1            0x0041F4FD
#define enable_ptrace_patch2            0x0041F9D1

// setlogin patch (for autolaunch check)
#define enable_setlogin_patch           0x000046BC

// Patch to remove vm_fault: fault on nofault entry, addr %llx
#define enable_vmfault_patch            0x00152966

// Patch mprotect: Allow RWX (mprotect) mapping
#define vm_map_protect_check            0x00080B8B

// flatz allow mangled symbol in dynlib_do_dlsym
#define dynlib_do_dlsym_patch           0x0021F2A7

// Enable mount for unprivileged user
#define enable_mount_patch              0x0004ADE7

// patch suword_lwpid
// has a check to see if child_tid/parent_tid is in kernel memory, and it in so patch it
// Patch by: JOGolden
#define enable_suword_patch1            0x002719C2
#define enable_suword_patch2            0x002719D1

// Enable *all* debugging logs (in vprintf)
// Patch by: SiSTRo
#define enable_debug_log_patch          0x000B7B17

// enable uart output
#define enable_uart_patch               0x0152BF60

#endif