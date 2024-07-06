// offset900.h
#ifndef OFFSET900_H
#define OFFSET900_H

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

// disable signature check
#define disable_signature_check_patch   0x006885C0

// enable debug RIFs
#define enable_debug_rifs_patch1        0x00650430
#define enable_debug_rifs_patch2        0x00650460

// allow sys_dynlib_dlsym in all processes
#define sys_dynlib_dlsym_patch1         0x0023B67F
#define sys_dynlib_dlsym_patch2         0x00221B40

// enable debug log
#define enable_debug_log_patch          0x000B7B17

// enable uart output
#define enable_uart_patch               0x0152BF5D

#endif