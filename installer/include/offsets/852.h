#ifndef __OFFSETS_H__
#define __OFFSETS_H__
#pragma once

// 8.52
#define XFAST_SYSCALL_addr              0x000001C0

// Names - Data
#define PRISON0_addr                    0x0111A8F0
#define ROOTVNODE_addr                  0x01C66150
#define PMAP_STORE_addr                 0x01BF69B0
#define DT_HASH_SEGMENT_addr            0x00CE6950

// Functions
#define pmap_protect_addr               0x00119460
#define pmap_protect_p_addr             0x001194A7

// Patches
// debug menu error
#define debug_menu_error_patch1         0x004EA0F8
#define debug_menu_error_patch2         0x004EB36C

// disable signature check
#define disable_signature_check_patch   0x00683F40

// enable debug RIFs
#define enable_debug_rifs_patch1        0x0064DC60
#define enable_debug_rifs_patch2        0x0064DC90

// allow sys_dynlib_dlsym in all processes
#define sys_dynlib_dlsym_patch1         0x00017C2F
#define sys_dynlib_dlsym_patch2         0x003AD040

// enable debug log
#define enable_debug_log_patch          0x0015D657

// enable uart output
#define enable_uart_patch               0x0152BF60

#endif
