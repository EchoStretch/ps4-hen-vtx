#ifndef __OFFSETS_H__
#define __OFFSETS_H__
#pragma once

// 11.00
#define XFAST_SYSCALL_addr              0x000001C0

// Names - Data
#define PRISON0_addr                    0x0111F830
#define ROOTVNODE_addr                  0x02116640
#define PMAP_STORE_addr                 0x02162A88
#define DT_HASH_SEGMENT_addr            0x00CEAC00

// Functions
#define pmap_protect_addr               0x00116CB0
#define pmap_protect_p_addr             0x00116CF7

// Patches
// debug menu error
#define debug_menu_error_patch1         0x004EE328
#define debug_menu_error_patch2         0x004EF3EE

// disable signature check
#define disable_signature_check_patch   0x00684EB0

// enable debug RIFs
#define enable_debug_rifs_patch1        0x0064BFD0
#define enable_debug_rifs_patch2        0x0064C000

// allow sys_dynlib_dlsym in all processes
#define sys_dynlib_dlsym_patch1         0x001E4CA8
#define sys_dynlib_dlsym_patch2         0x00088CE0

// patch sys_mmap to allow rwx mappings
#define sys_mmap_patch                  0x0015626A

// Patch setuid: Don't run kernel exploit more than once/privilege escalation
#define enable_setuid_patch             0x0043151F

// Enable RWX (kmem_alloc) mapping
#define kmem_alloc_patch1               0x00245EDC
#define kmem_alloc_patch2               0x00245EE4

// Patch copyin/copyout: Allow userland + kernel addresses in both params
// copyin
#define enable_copyin_patch1            0x002DE037
#define enable_copyin_patch2            0x002DE043
// copyout
#define enable_copyout_patch1           0x002DDF42
#define enable_copyout_patch2           0x002DDF4E

// Patch copyinstr
#define enable_copyinstr_patch1         0x002DE4E3
#define enable_copyinstr_patch2         0x002DE4EF
#define enable_copyinstr_patch3         0x002DE520

// Patch memcpy stack
#define enable_memcpy_patch             0x002DDDFD

// ptrace patches
#define enable_ptrace_patch1            0x0038429D
#define enable_ptrace_patch2            0x00384771

// setlogin patch (for autolaunch check)
#define enable_setlogin_patch           0x004341DC

// Patch to remove vm_fault: fault on nofault entry, addr %llx
#define enable_vmfault_patch            0x0031E8A6

// Patch mprotect: Allow RWX (mprotect) mapping
#define vm_map_protect_check            0x0035C8EC

// flatz allow mangled symbol in dynlib_do_dlsym
#define dynlib_do_dlsym_patch           0x00086447

// Enable mount for unprivileged user
#define enable_mount_patch              0x00388B37

// patch suword_lwpid
// has a check to see if child_tid/parent_tid is in kernel memory, and it in so patch it
// Patch by: JOGolden
#define enable_suword_patch1            0x002DE302
#define enable_suword_patch2            0x002DE311

// Enable *all* debugging logs (in vprintf)
// Patch by: SiSTRo
#define enable_debug_log_patch          0x002FCCB7

// enable uart output
#define enable_uart_patch               0x0152CFF8

#endif
