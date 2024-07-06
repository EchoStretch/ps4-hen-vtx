#ifndef __OFFSETS_H__
#define __OFFSETS_H__
#pragma once

// 10.50
#define	XFAST_SYSCALL_addr              0x000001C0

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

// enable debug log
#define enable_debug_log_patch          0x00450F67

// enable uart output
#define enable_uart_patch               0x01A3BCA0

#endif