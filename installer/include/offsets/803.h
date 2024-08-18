#ifndef __OFFSETS_H__
#define __OFFSETS_H__
#pragma once

// 8.03
#define	XFAST_SYSCALL_addr              0x000001C0

// Names - Data
#define PRISON0_addr                    0x0111A7D0
#define ROOTVNODE_addr                  0x01B8C730
#define PMAP_STORE_addr                 0x02245C40
#define DT_HASH_SEGMENT_addr            0x00CE68A8

// Functions
#define pmap_protect_addr               0x00383600
#define pmap_protect_p_addr             0x00383647

// Patches
// debug menu error
#define debug_menu_error_patch1         0x004E45D8
#define debug_menu_error_patch2         0x004E584C

// disable signature check
#define disable_signature_check_patch   0x00681DD0

// enable debug RIFs
#define enable_debug_rifs_patch1        0x0064DF00
#define enable_debug_rifs_patch2        0x0064DF30

// allow sys_dynlib_dlsym in all processes
#define sys_dynlib_dlsym_patch1         0x0031953F
#define sys_dynlib_dlsym_patch2         0x000951C0

// patch sys_mmap to allow rwx mappings
#define sys_mmap_patch                  0x000FD03A

// Patch setuid: Don't run kernel exploit more than once/privilege escalation
#define enable_setuid_patch             0x0025E407

// Enable RWX (kmem_alloc) mapping
#define kmem_alloc_patch1               0x0021B4BC
#define kmem_alloc_patch2               0x0021B4C4

// Patch copyin/copyout: Allow userland + kernel addresses in both params
// copyin
#define enable_copyin_patch1            0x003A4337
#define enable_copyin_patch2            0x003A4343
// copyout
#define enable_copyout_patch1           0x003A4242
#define enable_copyout_patch2           0x003A424E

// Patch copyinstr
#define enable_copyinstr_patch1         0x003A47E3
#define enable_copyinstr_patch2         0x003A47EF
#define enable_copyinstr_patch3         0x003A4820

// Patch memcpy stack
#define enable_memcpy_patch             0x003A40FD

// ptrace patches
#define enable_ptrace_patch1            0x0017416D
#define enable_ptrace_patch2            0x00174173

// setlogin patch (for autolaunch check)
#define enable_setlogin_patch           0x0035034C

// Patch to remove vm_fault: fault on nofault entry, addr %llx
#define enable_vmfault_patch            0x002773A6

// Patch mprotect: Allow RWX (mprotect) mapping
#define vm_map_protect_check            0x003EC68B

// flatz allow mangled symbol in dynlib_do_dlsym
#define dynlib_do_dlsym_patch           0x003AA7A7

// Enable mount for unprivileged user
#define enable_mount_patch              0x0027D6C7

// patch suword_lwpid
// has a check to see if child_tid/parent_tid is in kernel memory, and it in so patch it
// Patch by: JOGolden
#define enable_suword_patch1            0x003A4602
#define enable_suword_patch2            0x003A4611

// Enable *all* debugging logs (in vprintf)
// Patch by: SiSTRo
#define enable_debug_log_patch          0x00430BC7

// enable uart output
#define enable_uart_patch               0x0155D190

#endif
