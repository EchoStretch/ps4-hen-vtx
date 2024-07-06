#ifndef __OFFSETS_H__
#define __OFFSETS_H__
#pragma once

// 9.04
#define	XFAST_SYSCALL_addr              0x000001C0

// Names - Data
#define PRISON0_addr                    0X0111B840
#define ROOTVNODE_addr                  0X021EBF20
#define PMAP_STORE_addr                 0X01B8C4B0
#define DT_HASH_SEGMENT_addr            0x00CE6BE8

// Functions
#define pmap_protect_addr               0X0012FA40
#define pmap_protect_p_addr             0X0012FA87

// Patches
// debug menu error
#define debug_menu_error_patch1         0X004E6D48
#define debug_menu_error_patch2         0X004E802F

// allow sys_dynlib_dlsym in all processes
#define sys_dynlib_dlsym_patch1         0X0023B34F
#define sys_dynlib_dlsym_patch2         0X00221810

// disable signature check
#define disable_signature_check_patch   0X00686580

// enable debug RIFs
#define enable_debug_rifs_patch1        0X0064E3F0
#define enable_debug_rifs_patch2        0X0064E420

// enable debug log
#define enable_debug_log_patch          0X000B7AC7

// enable uart output
#define enable_uart_patch               0x01527F60

#endif