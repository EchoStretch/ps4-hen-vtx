#ifndef __OFFSETS_H__
#define __OFFSETS_H__
#pragma once

// data 5.05
#define	XFAST_SYSCALL_addr              0x000001C0
#define M_TEMP_addr                     0x014B4110
#define MINI_SYSCORE_SELF_BINARY_addr   0x014C9D48
#define ALLPROC_addr                    0x02382FF8
#define SBL_DRIVER_MAPPED_PAGES_addr    0x0271E208
#define SBL_PFS_SX_addr                 0x0271E5D8
#define SBL_KEYMGR_KEY_SLOTS_addr       0x02744548
#define SBL_KEYMGR_KEY_RBTREE_addr      0x02744558
#define SBL_KEYMGR_BUF_VA_addr          0x02748000
#define SBL_KEYMGR_BUF_GVA_addr         0x02748800
#define FPU_CTX_addr                    0x0274C040
#define DIPSW_addr                      0x01CD0650
#define SYSENT_addr                     0x0107C610

// common
#define memcmp_addr                     0x00050AC0
#define _sx_xlock_addr                  0x000F5E10
#define _sx_xunlock_addr                0x000F5FD0
#define malloc_addr                     0x0010E250
#define free_addr                       0x0010E460
#define strstr_addr                     0x0017DFB0
#define fpu_kern_enter_addr             0x001BFF90
#define fpu_kern_leave_addr             0x001C0090
#define memcpy_addr                     0x001EA530
#define memset_addr                     0x003205C0
#define strlen_addr                     0x003B71A0
#define printf_addr                     0x00436040
#define eventhandler_register_addr      0x001EC400

// Fself
#define sceSblACMgrGetPathId_addr       0x000117E0
#define sceSblServiceMailbox_addr       0x00632540
#define sceSblAuthMgrSmIsLoadable2_addr 0x0063C4F0
#define _sceSblAuthMgrGetSelfInfo_addr  0x0063CD40
#define _sceSblAuthMgrSmStart_addr      0x006418E0
#define sceSblAuthMgrVerifyHeader_addr  0x0063C550

// Fpkg
#define RsaesPkcs1v15Dec2048CRT_addr    0x001FD7D0
#define Sha256Hmac_addr                 0x002D55B0
#define AesCbcCfb128Encrypt_addr        0x003A2BD0
#define AesCbcCfb128Decrypt_addr        0x003A2E00
#define sceSblDriverSendMsg_0_addr      0x0061D7F0
#define sceSblPfsSetKeys_addr           0x0061EFA0
#define sceSblKeymgrSetKeyStorage_addr  0x00623FC0
#define sceSblKeymgrSetKeyForPfs_addr   0x0062D780
#define sceSblKeymgrCleartKey_addr      0x0062DB10
#define sceSblKeymgrSmCallfunc_addr     0x0062E2A0

// Patch
#define vmspace_acquire_ref_addr        0x0019EF90
#define vmspace_free_addr               0x0019EDC0
#define vm_map_lock_read_addr           0x0019F140
#define vm_map_unlock_read_addr         0x0019F190
#define vm_map_lookup_entry_addr        0x0019F760
#define proc_rwmem_addr                 0x0030D150

// Fself hooks
#define sceSblAuthMgrIsLoadable__sceSblACMgrGetPathId_hook          0x0063E25D
#define sceSblAuthMgrIsLoadable2_hook                               0x0063E3A1
#define sceSblAuthMgrVerifyHeader_hook1                             0x0063EAFC
#define sceSblAuthMgrVerifyHeader_hook2                             0x0063F718
#define sceSblAuthMgrSmLoadSelfSegment__sceSblServiceMailbox_hook   0x0064318B
#define sceSblAuthMgrSmLoadSelfBlock__sceSblServiceMailbox_hook     0x00643DA2

// Fpkg hooks
#define sceSblKeymgrSetKeyStorage__sceSblDriverSendMsg_hook         0x00624065
#define sceSblKeymgrInvalidateKey__sx_xlock_hook                    0x0062E96D
#define sceSblKeymgrSmCallfunc_npdrm_decrypt_isolated_rif_hook      0x0064C720
#define sceSblKeymgrSmCallfunc_npdrm_decrypt_rif_new_hook           0x0064D4FF
#define mountpfs__sceSblPfsSetKeys_hook1                            0x006AAAD5
#define mountpfs__sceSblPfsSetKeys_hook2                            0x006AAD04

// libkernel_sys.sprx patches - debug patches
#define sceSblRcMgrIsAllowDebugMenuForSettings_patch                0x0001BD90
#define sceSblRcMgrIsStoreMode_patch                                0x0001C090

// SceShellUI patches - remote play patches
#define CreateUserForIDU_patch                                      0x001A8FA0 //system_ex\app\NPXS20001\eboot.bin
#define remote_play_menu_patch                                      0x00EE638E //system_ex\app\NPXS20001\psm\Application\app.exe.sprx

// SceRemotePlay patches - remote play patches - system\vsh\app\NPXS21006
#define SceRemotePlay_patch1                                        0x0003C33F
#define SceRemotePlay_patch2                                        0x0003C35A

// SceShellCore patches - call sceKernelIsGenuineCEX
#define sceKernelIsGenuineCEX_patch1                                0x0016D05B
#define sceKernelIsGenuineCEX_patch2                                0x0079980B
#define sceKernelIsGenuineCEX_patch3                                0x007E5A13
#define sceKernelIsGenuineCEX_patch4                                0x0094715B

// SceShellCore patches - call nidf_libSceDipsw
#define nidf_libSceDipsw_patch1                                     0x0016D087
#define nidf_libSceDipsw_patch2                                     0x0023747B
#define nidf_libSceDipsw_patch3                                     0x00799837
#define nidf_libSceDipsw_patch4                                     0x00947187

// SceShellCore patches - bypass firmware checks
#define check_disc_root_param_patch                                 0x0013097F
#define app_installer_patch                                         0x00130A71
#define check_system_version                                        0x003CCB79
#define check_title_system_update_patch                             0x003CF8D0

// SceShellCore patches - enable remote pkg installer
#define enable_data_mount_patch                                     0x00319A53

// SceShellCore patches - enable VR without spoof
#define enable_psvr_patch                                           0x00C0D893

// SceShellCore patches - enable fpkg
#define enable_fpkg_patch                                           0x003E0602
 
// SceShellCore patches - use `free` prefix instead `fake`
#define fake_free_patch                                             0x00EA96A7

// SceShellCore patches - enable official external HDD support
#define pkg_installer_patch                                         0x009312A1
#define ext_hdd_patch                                               0x00593C7D

// SceShellCore patches - enable debug trophies
#define debug_trophies_patch                                        0x006A7C49

// SceShellCore patches - disable screenshot block
#define disable_screenshot_patch                                    0x000CB8C6

#endif