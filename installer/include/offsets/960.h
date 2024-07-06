#ifndef __OFFSETS_H__
#define __OFFSETS_H__
#pragma once

// 9.60
#define	XFAST_SYSCALL_addr              0x000001C0

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

// allow sys_dynlib_dlsym in all processes
#define sys_dynlib_dlsym_patch1         0x0019FEDF
#define sys_dynlib_dlsym_patch2         0x00011960

// disable signature check
#define disable_signature_check_patch   0x006AAC00

// enable debug RIFs
#define enable_debug_rifs_patch1        0x00643EA0
#define enable_debug_rifs_patch2        0x00643ED0

// enable debug log
#define enable_debug_log_patch          0x00205557

// enable uart output
#define enable_uart_patch               0x01A50BE0

#endif
