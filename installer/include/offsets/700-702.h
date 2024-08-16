#ifndef __OFFSETS_H__
#define __OFFSETS_H__
#pragma once

// 7.00-7.02
#define	XFAST_SYSCALL_addr              0x000001C0

// Names - Data
#define PRISON0_addr                    0x00113E398
#define ROOTVNODE_addr                  0x0022C5750
#define PMAP_STORE_addr                 0x0022C5268
#define DT_HASH_SEGMENT_addr            0x000D09F78

// Functions
#define pmap_protect_addr               0x0003E18A0
#define pmap_protect_p_addr             0x0003E18E7

// Patches
// debug menu error
#define debug_menu_error_patch1         0x005016FA
#define debug_menu_error_patch2         0x0050296C

// disable signature check
#define disable_signature_check_patch   0x006BE880

// enable debug RIFs
#define enable_debug_rifs_patch1        0x00668270
#define enable_debug_rifs_patch2        0x006682A0
	
// allow sys_dynlib_dlsym in all processes
#define sys_dynlib_dlsym_patch1         0x0009547B
#define sys_dynlib_dlsym_patch2         0x002F2C20

// patch sys_mmap to allow rwx mappings
#define sys_mmap_patch                  0x001D2336

// disable some check for mmap
#define vm_map_protect_check            0x00264C08

// enable debug log
#define enable_debug_log_patch          0x000BC817

// enable uart output
#define enable_uart_patch               0x01A6EAA0

#endif