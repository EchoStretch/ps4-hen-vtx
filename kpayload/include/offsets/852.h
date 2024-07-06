#ifndef __OFFSETS_H__
#define __OFFSETS_H__
#pragma once

// 8.52
// data
#define XFAST_SYSCALL_addr              0x000001C0
#define M_TEMP_addr                     0x01528FF0
#define MINI_SYSCORE_SELF_BINARY_addr   0x01583618
#define ALLPROC_addr                    0x01BD72D8
#define SBL_DRIVER_MAPPED_PAGES_addr    0x02646238
#define SBL_PFS_SX_addr                 0x0266CA40
#define SBL_KEYMGR_KEY_SLOTS_addr       0x02650078
#define SBL_KEYMGR_KEY_RBTREE_addr      0x02650088
#define SBL_KEYMGR_BUF_VA_addr          0x02654000
#define SBL_KEYMGR_BUF_GVA_addr         0x02654808
#define FPU_CTX_addr                    0x0264C040
#define DIPSW_addr                      0x01C83350

// common
#define memcmp_addr                     0x0020F280
#define _sx_xlock_addr                  0x002BAF10
#define _sx_xunlock_addr                0x002BB0D0
#define malloc_addr                     0x000B5A40
#define free_addr                       0x000B5C00
#define strstr_addr                     0x00456420
#define fpu_kern_enter_addr             0x00081D20
#define fpu_kern_leave_addr             0x00081DE0
#define memcpy_addr                     0x003A40F0
#define memset_addr                     0x003D6710
#define strlen_addr                     0x00270C40
#define printf_addr                     0x0015D570
#define eventhandler_register_addr      0x001ED3D0

// Fself
#define sceSblACMgrGetPathId_addr       0x00293690
#define sceSblServiceMailbox_addr       0x0062F8E0
#define sceSblAuthMgrSmIsLoadable2_addr 0x00641990
#define _sceSblAuthMgrGetSelfInfo_addr  0x006421D0
#define _sceSblAuthMgrSmStart_addr      0x0063E2B0
#define sceSblAuthMgrVerifyHeader_addr  0x006419F0

// Fpkg
#define RsaesPkcs1v15Dec2048CRT_addr    0x00487240
#define Sha256Hmac_addr                 0x00073D90
#define AesCbcCfb128Encrypt_addr        0x002639A0
#define AesCbcCfb128Decrypt_addr        0x00263BD0
#define sceSblDriverSendMsg_0_addr      0x0061B030
#define sceSblPfsSetKeys_addr           0x006295B0
#define sceSblKeymgrSetKeyStorage_addr  0x0062EE90
#define sceSblKeymgrSetKeyForPfs_addr   0x00620D00
#define sceSblKeymgrCleartKey_addr      0x00621040
#define sceSblKeymgrSmCallfunc_addr     0x006208D0

// Patch
#define vmspace_acquire_ref_addr        0x00148530
#define vmspace_free_addr               0x00148360
#define vm_map_lock_read_addr           0x001486D0
#define vm_map_unlock_read_addr         0x00148720
#define vm_map_lookup_entry_addr        0x00148D10
#define proc_rwmem_addr                 0x00131B50

// Fself hooks
#define sceSblAuthMgrIsLoadable__sceSblACMgrGetPathId_hook          0x0064243C
#define sceSblAuthMgrIsLoadable2_hook                               0x0064258E
#define sceSblAuthMgrVerifyHeader_hook1                             0x00642D26
#define sceSblAuthMgrVerifyHeader_hook2                             0x00643A09
#define sceSblAuthMgrSmLoadSelfSegment__sceSblServiceMailbox_hook   0x006406FD
#define sceSblAuthMgrSmLoadSelfBlock__sceSblServiceMailbox_hook     0x00641338

// Fpkg hooks
#define sceSblKeymgrSetKeyStorage__sceSblDriverSendMsg_hook         0x0062EF35
#define sceSblKeymgrInvalidateKey__sx_xlock_hook                    0x00621EBD
#define sceSblKeymgrSmCallfunc_npdrm_decrypt_isolated_rif_hook      0x0064C2F0
#define sceSblKeymgrSmCallfunc_npdrm_decrypt_rif_new_hook           0x0064D0BE
#define mountpfs__sceSblPfsSetKeys_hook1                            0x006A0729
#define mountpfs__sceSblPfsSetKeys_hook2                            0x006A095A

//libkernel_sys.sprx patches - debug patches
#define sceSblRcMgrIsAllowDebugMenuForSettings_patch                0x0001D1C0
#define sceSblRcMgrIsStoreMode_patch                                0x0001D520

// SceShellUI patches - remote play patches                                
#define CreateUserForIDU_patch                                      0x001888C0 //system_ex\app\NPXS20001\eboot.bin
#define remote_play_menu_patch                                      0x00EDA401 //system_ex\app\NPXS20001\psm\Application\app.exe.sprx

// SceRemotePlay patches - remote play patches - system\vsh\app\NPXS21006
#define SceRemotePlay_patch1                                        0x000FC5C8
#define SceRemotePlay_patch2                                        0x000FC5E6

// SceShellCore patches - call sceKernelIsGenuineCEX
#define sceKernelIsGenuineCEX_patch1    0x0016C3D0
#define sceKernelIsGenuineCEX_patch2    0x0084F5C0
#define sceKernelIsGenuineCEX_patch3    0x0089E982
#define sceKernelIsGenuineCEX_patch4    0x00A15CA0

// SceShellCore patches - call nidf_libSceDipsw
#define nidf_libSceDipsw_patch1         0x0016C3FA
#define nidf_libSceDipsw_patch2         0x00247108
#define nidf_libSceDipsw_patch3         0x0084F5EA
#define nidf_libSceDipsw_patch4         0x00A15CCA

// SceShellCore patches - bypass firmware checks
#define check_disc_root_param_patch     0x00136E60
#define app_installer_patch             0x00136F50
#define check_system_version            0x003C1E57
#define check_title_system_update_patch 0x003C44C0

// SceShellCore patches - enable remote pkg installer
#define enable_data_mount_patch         0x00320713

// SceShellCore patches - enable VR without spoof
#define enable_psvr_patch               0x00D4354F

// SceShellCore patches - enable fpkg
#define enable_fpkg_patch               0x003D3ADF

// SceShellCore patches - use `free` prefix instead `fake`
#define fake_free_patch                 0x00FBC371

// SceShellCore patches - enable official external HDD support
#define pkg_installer_patch             0x009FEBB1
#define ext_hdd_patch                   0x00607CAD

// SceShellCore patches - enable debug trophies
#define debug_trophies_patch            0x0072B909

// SceShellCore patches - disable screenshot block
#define disable_screenshot_patch        0x00389976

#endif