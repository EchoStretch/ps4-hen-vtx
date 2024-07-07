#ifndef __OFFSETS_H__
#define __OFFSETS_H__
#pragma once

// data
#define XFAST_SYSCALL_addr              0x0
#define M_TEMP_addr                     0x0
#define MINI_SYSCORE_SELF_BINARY_addr   0x0
#define ALLPROC_addr                    0x0
#define SBL_DRIVER_MAPPED_PAGES_addr    0x0
#define SBL_PFS_SX_addr                 0x0
#define SBL_KEYMGR_KEY_SLOTS_addr       0x0
#define SBL_KEYMGR_KEY_RBTREE_addr      0x0
#define SBL_KEYMGR_BUF_VA_addr          0x0
#define SBL_KEYMGR_BUF_GVA_addr         0x0
#define FPU_CTX_addr                    0x0
#define DIPSW_addr                      0x0
#define SYSENT_addr                     0x0

// common
#define memcmp_addr                     0x0
#define _sx_xlock_addr                  0x0
#define _sx_xunlock_addr                0x0
#define malloc_addr                     0x0
#define free_addr                       0x0
#define strstr_addr                     0x0
#define fpu_kern_enter_addr             0x0
#define fpu_kern_leave_addr             0x0
#define memcpy_addr                     0x0
#define memset_addr                     0x0
#define strlen_addr                     0x0
#define printf_addr                     0x0
#define eventhandler_register_addr      0x0

// Fself
#define sceSblACMgrGetPathId_addr       0x0
#define sceSblServiceMailbox_addr       0x0
#define sceSblAuthMgrSmIsLoadable2_addr 0x0
#define _sceSblAuthMgrGetSelfInfo_addr  0x0
#define _sceSblAuthMgrSmStart_addr      0x0
#define sceSblAuthMgrVerifyHeader_addr  0x0

// Fpkg
#define RsaesPkcs1v15Dec2048CRT_addr    0x0
#define Sha256Hmac_addr                 0x0
#define AesCbcCfb128Encrypt_addr        0x0
#define AesCbcCfb128Decrypt_addr        0x0
#define sceSblDriverSendMsg_0_addr      0x0
#define sceSblPfsSetKeys_addr           0x0
#define sceSblKeymgrSetKeyStorage_addr  0x0
#define sceSblKeymgrSetKeyForPfs_addr   0x0
#define sceSblKeymgrCleartKey_addr      0x0
#define sceSblKeymgrSmCallfunc_addr     0x0

// Patch
#define vmspace_acquire_ref_addr        0x0
#define vmspace_free_addr               0x0
#define vm_map_lock_read_addr           0x0
#define vm_map_unlock_read_addr         0x0
#define vm_map_lookup_entry_addr        0x0
#define proc_rwmem_addr                 0x0

// Fself hooks
#define sceSblAuthMgrIsLoadable__sceSblACMgrGetPathId_hook          0x0
#define sceSblAuthMgrIsLoadable2_hook                               0x0
#define sceSblAuthMgrVerifyHeader_hook1                             0x0
#define sceSblAuthMgrVerifyHeader_hook2                             0x0
#define sceSblAuthMgrSmLoadSelfSegment__sceSblServiceMailbox_hook   0x0
#define sceSblAuthMgrSmLoadSelfBlock__sceSblServiceMailbox_hook     0x0

// Fpkg hooks
#define sceSblKeymgrSetKeyStorage__sceSblDriverSendMsg_hook         0x0
#define sceSblKeymgrInvalidateKey__sx_xlock_hook                    0x0
#define sceSblKeymgrSmCallfunc_npdrm_decrypt_isolated_rif_hook      0x0
#define sceSblKeymgrSmCallfunc_npdrm_decrypt_rif_new_hook           0x0
#define mountpfs__sceSblPfsSetKeys_hook1                            0x0
#define mountpfs__sceSblPfsSetKeys_hook2                            0x0

//libkernel_sys.sprx patches - debug patches
#define sceSblRcMgrIsAllowDebugMenuForSettings_patch                0x0
#define sceSblRcMgrIsStoreMode_patch                                0x0

// SceShellUI patches - remote play patches
#define CreateUserForIDU_patch                                      0x0 //system_ex\app\NPXS20001\eboot.bin
#define remote_play_menu_patch                                      0x0 //system_ex\app\NPXS20001\psm\Application\app.exe.sprx

// SceRemotePlay patches - remote play patches - system\vsh\app\NPXS21006
#define SceRemotePlay_patch1                                        0x0
#define SceRemotePlay_patch2                                        0x0

// SceShellCore patches - call sceKernelIsGenuineCEX
#define sceKernelIsGenuineCEX_patch1    0x0
#define sceKernelIsGenuineCEX_patch2    0x0
#define sceKernelIsGenuineCEX_patch3    0x0
#define sceKernelIsGenuineCEX_patch4    0x0

// SceShellCore patches - call nidf_libSceDipsw
#define nidf_libSceDipsw_patch1         0x0
#define nidf_libSceDipsw_patch2         0x0
#define nidf_libSceDipsw_patch3         0x0
#define nidf_libSceDipsw_patch4         0x0

// SceShellCore patches - bypass firmware checks
#define check_disc_root_param_patch     0x0
#define app_installer_patch             0x0
#define check_system_version            0x0
#define check_title_system_update_patch 0x0

// SceShellCore patches - enable remote pkg installer
#define enable_data_mount_patch         0x0

// SceShellCore patches - enable VR without spoof
#define enable_psvr_patch               0x0

// SceShellCore patches - enable fpkg
#define enable_fpkg_patch               0x0
 
// SceShellCore patches - use `free` prefix instead `fake`
#define fake_free_patch                 0x0

// SceShellCore patches - enable official external HDD support
#define pkg_installer_patch             0x0
#define ext_hdd_patch                   0x0

// SceShellCore patches - enable debug trophies
#define debug_trophies_patch            0x0

// SceShellCore patches - disable screenshot block
#define disable_screenshot_patch        0x0

#endif