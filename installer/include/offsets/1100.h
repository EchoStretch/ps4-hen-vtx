#ifndef OFFSET1100_H
#define OFFSET1100_H

#define	XFAST_SYSCALL_addr              0x000001C0

// Names - Data
#define PRISON0_addr                    0x0111F830
#define ROOTVNODE_addr                  0x02116640
#define PMAP_STORE_addr                 0X02162A88
#define DT_HASH_SEGMENT_addr            0x00CEAC00

// Functions
#define pmap_protect_addr               0x00116CB0
#define pmap_protect_p_addr             0x00116CF7

// Patches
// debug menu error
#define debug_menu_error_patch1         0x004EE328
#define debug_menu_error_patch2         0x004EF3EE

// allow sys_dynlib_dlsym in all processes
#define sys_dynlib_dlsym_patch1         0x001E4CA8
#define sys_dynlib_dlsym_patch2         0x00088CE0

// disable signature check
#define disable_signature_check_patch   0x00684EB0

// enable debug RIFs
#define enable_debug_rifs_patch1        0x0064BFD0
#define enable_debug_rifs_patch2        0x0064C000

// enable debug log
#define enable_debug_log_patch          0x002FCCB7

// enable uart output
#define enable_uart_patch               0x0152CFF8

#endif
