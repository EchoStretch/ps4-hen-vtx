#ifndef __OFFSETS_H__
#define __OFFSETS_H__
#pragma once

// 9.03 - 9.04
#define	XFAST_SYSCALL_addr              0x000001C0

// Names - Data
#define PRISON0_addr                    0x0111B840
#define ROOTVNODE_addr                  0x021EBF20
#define PMAP_STORE_addr                 0x01B8C4B0
#define DT_HASH_SEGMENT_addr            0x00CE6BE8

// Functions
#define pmap_protect_addr               0x0012FA40
#define pmap_protect_p_addr             0x0012FA87

// Patches
// debug menu error
#define debug_menu_error_patch1         0x004E6D48
#define debug_menu_error_patch2         0x004E802F

// disable signature check
#define disable_signature_check_patch   0x00686580

// enable debug RIFs
#define enable_debug_rifs_patch1        0x0064E3F0
#define enable_debug_rifs_patch2        0x0064E420

// allow sys_dynlib_dlsym in all processes
#define sys_dynlib_dlsym_patch1         0x0023B34F
#define sys_dynlib_dlsym_patch2         0x00221810

// patch sys_mmap to allow rwx mappings
#define sys_mmap_patch                  0x001662DA

// Patch setuid: Don't run kernel exploit more than once/privilege escalation
#define enable_setuid_patch             0x000019FF

// Enable RWX (kmem_alloc) mapping
#define kmem_alloc_patch1               0x0037A13C
#define kmem_alloc_patch2               0x0037A144

// Patch copyin/copyout: Allow userland + kernel addresses in both params
// copyin
#define enable_copyin_patch1            0x00271377
#define enable_copyin_patch2            0x00271383
// copyout
#define enable_copyout_patch1           0x00271282
#define enable_copyout_patch2           0x0027128E

// Patch copyinstr
#define enable_copyinstr_patch1         0x00271823
#define enable_copyinstr_patch2         0x0027182F
#define enable_copyinstr_patch3         0x00271860

// Patch memcpy stack
#define enable_memcpy_patch             0x0027113D

// ptrace patches
#define enable_ptrace_patch1            0x0041D46D
#define enable_ptrace_patch2            0x0041D941

// setlogin patch (for autolaunch check)
#define enable_setlogin_patch           0x000046BC

// Patch to remove vm_fault: fault on nofault entry, addr %llx
#define enable_vmfault_patch            0x00152916

// Patch mprotect: Allow RWX (mprotect) mapping
#define vm_map_protect_check            0x00080B8B

// flatz allow mangled symbol in dynlib_do_dlsym
#define dynlib_do_dlsym_patch           0x0021EF77

// Enable mount for unprivileged user
#define enable_mount_patch              0x0004ADE7

// patch suword_lwpid
// has a check to see if child_tid/parent_tid is in kernel memory, and it in so patch it
// Patch by: JOGolden
#define enable_suword_patch1            0x00271642
#define enable_suword_patch2            0x00271651

// Enable *all* debugging logs (in vprintf)
// Patch by: SiSTRo
#define enable_debug_log_patch          0x000B7AC7

// enable uart output
#define enable_uart_patch               0x01527F60

#endif
