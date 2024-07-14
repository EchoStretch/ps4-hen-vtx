#ifndef __OFFSETS_H__
#define __OFFSETS_H__
#pragma once

// 7.00 - 7.02
// data 700-702
#define XFAST_SYSCALL_addr              0x000001C0
#define M_TEMP_addr                     0x01A7AE50
#define MINI_SYSCORE_SELF_BINARY_addr   0x01555BD8
#define ALLPROC_addr                    0x01B48318
#define SBL_DRIVER_MAPPED_PAGES_addr    0x02669E48
#define SBL_PFS_SX_addr                 0x026945C0
#define SBL_KEYMGR_KEY_SLOTS_addr       0x02698848
#define SBL_KEYMGR_KEY_RBTREE_addr      0x02698858
#define SBL_KEYMGR_BUF_VA_addr          0x0269C000
#define SBL_KEYMGR_BUF_GVA_addr         0x0269C808
#define FPU_CTX_addr                    0x02688400
#define DIPSW_addr                      0x022FED50
#define SYSENT_addr                     0x01125660

// common
#define memcmp_addr                     0x00207500
#define _sx_xlock_addr                  0x001AE030
#define _sx_xunlock_addr                0x001AE1F0
#define malloc_addr                     0x00301840
#define free_addr                       0x00301A40
#define strstr_addr                     0x00005740
#define fpu_kern_enter_addr             0x002CEBF0
#define fpu_kern_leave_addr             0x002CECE0
#define memcpy_addr                     0x0002F040
#define memset_addr                     0x002DFC20
#define strlen_addr                     0x00093FF0
#define printf_addr                     0x000BC730
#define eventhandler_register_addr      0x00483810

// Fself
#define sceSblACMgrGetPathId_addr       0x001CB930
#define sceSblServiceMailbox_addr       0x0064C110
#define sceSblAuthMgrSmIsLoadable2_addr 0x00660210
#define _sceSblAuthMgrGetSelfInfo_addr  0x00660A90
#define _sceSblAuthMgrSmStart_addr      0x0065A560
#define sceSblAuthMgrVerifyHeader_addr  0x00660270

// Fpkg
#define RsaesPkcs1v15Dec2048CRT_addr    0x001DD540
#define Sha256Hmac_addr                 0x00205F50
#define AesCbcCfb128Encrypt_addr        0x001DA410
#define AesCbcCfb128Decrypt_addr        0x001DA640
#define sceSblDriverSendMsg_0_addr      0x006376A0
#define sceSblPfsSetKeys_addr           0x00647000
#define sceSblKeymgrSetKeyStorage_addr  0x0063E230
#define sceSblKeymgrSetKeyForPfs_addr   0x00648650
#define sceSblKeymgrCleartKey_addr      0x006489D0
#define sceSblKeymgrSmCallfunc_addr     0x00648220

// Patch
#define vmspace_acquire_ref_addr        0x0025F9F0
#define vmspace_free_addr               0x0025F820
#define vm_map_lock_read_addr           0x0025FB90
#define vm_map_unlock_read_addr         0x0025FBE0
#define vm_map_lookup_entry_addr        0x00260190
#define proc_rwmem_addr                 0x00043E80

// Fself hooks
#define sceSblAuthMgrIsLoadable__sceSblACMgrGetPathId_hook          0x0065E97C
#define sceSblAuthMgrIsLoadable2_hook                               0x0065EACF
#define sceSblAuthMgrVerifyHeader_hook1                             0x0065F256
#define sceSblAuthMgrVerifyHeader_hook2                             0x0065FEF8
#define sceSblAuthMgrSmLoadSelfSegment__sceSblServiceMailbox_hook   0x0065CA0D
#define sceSblAuthMgrSmLoadSelfBlock__sceSblServiceMailbox_hook     0x0065D669

// Fpkg hooks
#define sceSblKeymgrSetKeyStorage__sceSblDriverSendMsg_hook         0x0063E2D5
#define sceSblKeymgrInvalidateKey__sx_xlock_hook                    0x0064989D
#define sceSblKeymgrSmCallfunc_npdrm_decrypt_isolated_rif_hook      0x00668A50
#define sceSblKeymgrSmCallfunc_npdrm_decrypt_rif_new_hook           0x0066985E
#define mountpfs__sceSblPfsSetKeys_hook1                            0x006B534B
#define mountpfs__sceSblPfsSetKeys_hook2                            0x006B557C

// libkernel_sys.sprx patches - debug patches
#define sceSblRcMgrIsAllowDebugMenuForSettings_patch                0x0001D240
#define sceSblRcMgrIsStoreMode_patch                                0x0001D5A0

// SceShellUI patches - remote play patches
#define CreateUserForIDU_patch                                      0x00191220 //system_ex\app\NPXS20001\eboot.bin
#define remote_play_menu_patch                                      0x00ECC9A1 //system_ex\app\NPXS20001\psm\Application\app.exe.sprx

// SceRemotePlay patches - remote play patches - system\vsh\app\NPXS21006
#define SceRemotePlay_patch1                                        0x0010B343
#define SceRemotePlay_patch2                                        0x0010B35E

// SceShellCore patches - call sceKernelIsGenuineCEX
#define sceKernelIsGenuineCEX_patch1                                0x00174260
#define sceKernelIsGenuineCEX_patch2                                0x007F5D00
#define sceKernelIsGenuineCEX_patch3                                0x00840132
#define sceKernelIsGenuineCEX_patch4                                0x009CE100

// SceShellCore patches - call nidf_libSceDipsw
#define nidf_libSceDipsw_patch1                                     0x0017428A
#define nidf_libSceDipsw_patch2                                     0x00318FF1
#define nidf_libSceDipsw_patch3                                     0x007F5D2A
#define nidf_libSceDipsw_patch4                                     0x009CE12A

// SceShellCore patches - bypass firmware checks
#define check_disc_root_param_patch                                 0x0013CE3D
#define app_installer_patch                                         0x0013CF20
#define check_system_version                                        0x003B3B38
#define check_title_system_update_patch                             0x003B6270

// SceShellCore patches - enable remote pkg installer
#define enable_data_mount_patch                                     0x00318FE1

// SceShellCore patches - enable VR without spoof
#define enable_psvr_patch                                           0x00D07C5F

// SceShellCore patches - enable fpkg
#define enable_fpkg_patch                                           0x003C5900

// SceShellCore patches - use `free` prefix instead `fake`
#define fake_free_patch                                             0x00F5E9B1

// SceShellCore patches - enable official external HDD support
#define pkg_installer_patch                                         0x009B6C41
#define ext_hdd_patch                                               0x005C6AAD

// SceShellCore patches - enable debug trophies
#define debug_trophies_patch                                        0x006E44D9

// SceShellCore patches - disable screenshot block
#define disable_screenshot_patch                                    0x000D61F6

#endif