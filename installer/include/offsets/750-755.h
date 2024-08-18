#ifndef __OFFSETS_H__
#define __OFFSETS_H__
#pragma once

// 7.5X
#define	XFAST_SYSCALL_addr              0x000001C0

// Names - Data
#define PRISON0_addr                    0x0113B728
#define ROOTVNODE_addr                  0x01B463E0
#define PMAP_STORE_addr                 0x0215EA40
#define DT_HASH_SEGMENT_addr            0x00D068D0

// Functions
#define pmap_protect_addr               0x001A9800
#define pmap_protect_p_addr             0x001A9847

// Patches
// debug menu error
#define debug_menu_error_patch1         0x004FF322
#define debug_menu_error_patch2         0x0050059C

// disable signature check
#define disable_signature_check_patch   0x006DD9A0

// enable debug RIFs
#define enable_debug_rifs_patch1        0x00668140
#define enable_debug_rifs_patch2        0x00668170
	
// allow sys_dynlib_dlsym in all processes
#define sys_dynlib_dlsym_patch1         0x004523C4
#define sys_dynlib_dlsym_patch2         0x00029A30

// patch sys_mmap to allow rwx mappings
#define sys_mmap_patch                  0x000DB17D

// Patch setuid: Don't run kernel exploit more than once/privilege escalation
#define enable_setuid_patch             0x000019FF

// Enable RWX (kmem_alloc) mapping
#define kmem_alloc_patch1               0x001754AC
#define kmem_alloc_patch2               0x001754B4

// Patch copyin/copyout: Allow userland + kernel addresses in both params
// copyin
#define enable_copyin_patch1            0x0028FA47
#define enable_copyin_patch2            0x0028FA53
// copyout
#define enable_copyout_patch1           0x0028F952
#define enable_copyout_patch2           0x0028F95E

// Patch copyinstr
#define enable_copyinstr_patch1         0x0028FEF3
#define enable_copyinstr_patch2         0x0028FEFF
#define enable_copyinstr_patch3         0x0028FF30

// Patch memcpy stack
#define enable_memcpy_patch             0x0028F80D

// ptrace patches
#define enable_ptrace_patch1            0x00361D0D
#define enable_ptrace_patch2            0x003621CF

// setlogin patch (for autolaunch check)
#define enable_setlogin_patch           0x0037CF6C

// Patch to remove vm_fault: fault on nofault entry, addr %llx
#define enable_vmfault_patch            0x003DF2A6

// Patch mprotect: Allow RWX (mprotect) mapping
#define vm_map_protect_check            0x003014C8

// flatz allow mangled symbol in dynlib_do_dlsym
#define dynlib_do_dlsym_patch           0x000271A7

// Enable mount for unprivileged user
#define enable_mount_patch              0x00076385

// patch suword_lwpid
// has a check to see if child_tid/parent_tid is in kernel memory, and it in so patch it
// Patch by: JOGolden
#define enable_suword_patch1            0x0028FD12
#define enable_suword_patch2            0x0028FD21

// Enable *all* debugging logs (in vprintf)
// Patch by: SiSTRo
#define enable_debug_log_patch          0x0026F827

// enable uart output
#define enable_uart_patch               0x01564910

#endif