#ifndef __OFFSETS_H__
#define __OFFSETS_H__
#pragma once

// data 6.72
#define	XFAST_SYSCALL_addr              0x000001C0
#define M_TEMP_addr                     0x01540EB0
#define MINI_SYSCORE_SELF_BINARY_addr   0x0156A588
#define ALLPROC_addr                    0x022BBE80
#define SBL_DRIVER_MAPPED_PAGES_addr    0x0266AC68
#define SBL_PFS_SX_addr                 0x02679040
#define SBL_KEYMGR_KEY_SLOTS_addr       0x02694570
#define SBL_KEYMGR_KEY_RBTREE_addr      0x02694580
#define SBL_KEYMGR_BUF_VA_addr          0x02698000
#define SBL_KEYMGR_BUF_GVA_addr         0x02698808
#define FPU_CTX_addr                    0x02694080
#define DIPSW_addr                      0x01BD7FD0
#define SYSENT_addr                     0x0111E000

// common
#define memcmp_addr                     0x00207E40
#define _sx_xlock_addr                  0x000426C0
#define _sx_xunlock_addr                0x00042880
#define malloc_addr                     0x0000D7A0
#define free_addr                       0x0000D9A0
#define strstr_addr                     0x004817F0
#define fpu_kern_enter_addr             0x0036B6E0
#define fpu_kern_leave_addr             0x0036B7D0
#define memcpy_addr                     0x003C15B0
#define memset_addr                     0x001687D0
#define strlen_addr                     0x002433E0
#define printf_addr                     0x00123280
#define eventhandler_register_addr      0x00402E80

// Fself
#define sceSblACMgrGetPathId_addr       0x00233C70
#define sceSblServiceMailbox_addr       0x0064CC20
#define sceSblAuthMgrSmIsLoadable2_addr 0x0065D7A0
#define _sceSblAuthMgrGetSelfInfo_addr  0x0065E010
#define _sceSblAuthMgrSmStart_addr      0x0065E490
#define sceSblAuthMgrVerifyHeader_addr  0x00660260

// Fpkg
#define RsaesPkcs1v15Dec2048CRT_addr    0x001D6050
#define Sha256Hmac_addr                 0x00335B70
#define AesCbcCfb128Encrypt_addr        0x003C0320
#define AesCbcCfb128Decrypt_addr        0x003C0550
#define sceSblDriverSendMsg_0_addr      0x00637AE0
#define sceSblPfsSetKeys_addr           0x00641520
#define sceSblKeymgrSetKeyStorage_addr  0x00646E00
#define sceSblKeymgrSetKeyForPfs_addr   0x00649800
#define sceSblKeymgrCleartKey_addr      0x00649B80
#define sceSblKeymgrSmCallfunc_addr     0x006493D0

// Patch
#define vmspace_acquire_ref_addr        0x0044CB90
#define vmspace_free_addr               0x0044C9C0
#define vm_map_lock_read_addr           0x0044CD40
#define vm_map_unlock_read_addr         0x0044CD90
#define vm_map_lookup_entry_addr        0x0044D330
#define proc_rwmem_addr                 0x0010EE10

// Fself hooks
#define sceSblAuthMgrIsLoadable__sceSblACMgrGetPathId_hook          0x006591BC
#define sceSblAuthMgrIsLoadable2_hook                               0x0065930F
#define sceSblAuthMgrVerifyHeader_hook1                             0x00659AC6
#define sceSblAuthMgrVerifyHeader_hook2                             0x0065A758
#define sceSblAuthMgrSmLoadSelfSegment__sceSblServiceMailbox_hook   0x0066092A
#define sceSblAuthMgrSmLoadSelfBlock__sceSblServiceMailbox_hook     0x00661571

// Fpkg hooks
#define sceSblKeymgrSetKeyStorage__sceSblDriverSendMsg_hook         0x00646EA5
#define sceSblKeymgrInvalidateKey__sx_xlock_hook                    0x0064AA3D
#define sceSblKeymgrSmCallfunc_npdrm_decrypt_isolated_rif_hook      0x00669500
#define sceSblKeymgrSmCallfunc_npdrm_decrypt_rif_new_hook           0x0066A313
#define mountpfs__sceSblPfsSetKeys_hook1                            0x006CDF15
#define mountpfs__sceSblPfsSetKeys_hook2                            0x006CE141

// libkernel_sys.sprx patches - debug patches
#define sceSblRcMgrIsAllowDebugMenuForSettings_patch                0x0001D670
#define sceSblRcMgrIsStoreMode_patch                                0x0001D9D0

// SceShellUI patches - remote play patches
#define CreateUserForIDU_patch                                      0x001A0900 //system_ex\app\NPXS20001\eboot.bin
#define remote_play_menu_patch                                      0x00EC8291 //system_ex\app\NPXS20001\psm\Application\app.exe.sprx

// SceRemotePlay patches - remote play patches - system\vsh\app\NPXS21006
#define SceRemotePlay_patch1                                        0x0010C6D4
#define SceRemotePlay_patch2                                        0x0010C6EF

// SceShellCore patches - call sceKernelIsGenuineCEX
#define sceKernelIsGenuineCEX_patch1                                0x00189602
#define sceKernelIsGenuineCEX_patch2                                0x00835642
#define sceKernelIsGenuineCEX_patch3                                0x00880492
#define sceKernelIsGenuineCEX_patch4                                0x00A12B92

// SceShellCore patches - call nidf_libSceDipsw
#define nidf_libSceDipsw_patch1                                     0x00189630
#define nidf_libSceDipsw_patch2                                     0x00254107
#define nidf_libSceDipsw_patch3                                     0x00835670
#define nidf_libSceDipsw_patch4                                     0x00A12BC0

// SceShellCore patches - bypass firmware checks
#define check_disc_root_param_patch                                 0x00149AFD
#define app_installer_patch                                         0x00149BF0
#define check_system_version                                        0x003DB6F8
#define check_title_system_update_patch                             0x003DECC0

// SceShellCore patches - enable remote pkg installer
#define enable_data_mount_patch                                     0x0033943E

// SceShellCore patches - enable VR without spoof
#define enable_psvr_patch                                           0x00D718B1

// SceShellCore patches - enable fpkg
#define enable_fpkg_patch                                           0x003EFCF0
 
// SceShellCore patches - use `free` prefix instead `fake`
#define fake_free_patch                                             0x00FD2BF1

// SceShellCore patches - enable official external HDD support
#define pkg_installer_patch                                         0x009FB311
#define ext_hdd_patch                                               0x00606A0D

// SceShellCore patches - enable debug trophies
#define debug_trophies_patch                                        0x007226DF

// SceShellCore patches - disable screenshot block
#define disable_screenshot_patch                                    0x000DD2A6

#endif