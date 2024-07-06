#ifndef __OFFSETS_H__
#define __OFFSETS_H__
#pragma once

// 7.55
#define	XFAST_SYSCALL_addr              0x000001C0

// Names - Data
#define PRISON0_addr                    0x0113B728
#define ROOTVNODE_addr                  0x01B463E0
#define PMAP_STORE_addr                 0x0215EA40
#define DT_HASH_SEGMENT_addr            0x00C05068

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

// enable debug log
#define enable_debug_log_patch          0x0026F827

// enable uart output
#define enable_uart_patch               0x01564910

#endif