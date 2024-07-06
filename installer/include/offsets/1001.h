#ifndef __OFFSETS_H__
#define __OFFSETS_H__
#pragma once

// 10.01
#define XFAST_SYSCALL_addr              0x000001C0

// Names - Data
#define PRISON0_addr                    0x0111B8B0
#define ROOTVNODE_addr                  0x01B25BD0
#define PMAP_STORE_addr                 0x02182D60
#define DT_HASH_SEGMENT_addr            0x00CE6DC8
#define M_TEMP_addr                     0x00109C20

// Functions
#define pmap_protect_addr               0x000E2420
#define pmap_protect_p_addr             0x000E2467
#define malloc_addr                     0x00109A60
#define printf_addr                     0x000C50F0

// Patches
// debug menu error
#define debug_menu_error_patch1         0x004EC908
#define debug_menu_error_patch2         0x004ED9CE

// disable signature check
#define disable_signature_check_patch   0x006926E0

// enable debug RIFs
#define enable_debug_rifs_patch1        0x0064A510
#define enable_debug_rifs_patch2        0x0064A540

// allow sys_dynlib_dlsym in all processes
#define sys_dynlib_dlsym_patch1         0x0019025F
#define sys_dynlib_dlsym_patch2         0x001BEA40

// enable debug log
#define enable_debug_log_patch          0x000C51D7

// enable uart output
#define enable_uart_patch               0x01A78A78

#endif
