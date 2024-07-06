#ifndef __OFFSETS_H__
#define __OFFSETS_H__
#pragma once

//10.00
// data
#define XFAST_SYSCALL_addr              0x000001C0
#define M_TEMP_addr                     0x01532C00
#define MINI_SYSCORE_SELF_BINARY_addr   0x00D5EC48
#define ALLPROC_addr                    0x022D9B40
#define SBL_DRIVER_MAPPED_PAGES_addr    0x02646258
#define SBL_PFS_SX_addr                 0x0267C088
#define SBL_KEYMGR_KEY_SLOTS_addr       0x026583B8
#define SBL_KEYMGR_KEY_RBTREE_addr      0x026583C8
#define SBL_KEYMGR_BUF_VA_addr          0x0265C000
#define SBL_KEYMGR_BUF_GVA_addr         0x0265C808
#define FPU_CTX_addr                    0x02660040
#define DIPSW_addr                      0x01B9E050

// common
#define memcmp_addr                     0x00109940
#define _sx_xlock_addr                  0x000A9A80
#define _sx_xunlock_addr                0x000A9C40
#define malloc_addr                     0x00109A60
#define free_addr                       0x00109C20
#define strstr_addr                     0x003F7490
#define fpu_kern_enter_addr             0x0026C7D0
#define fpu_kern_leave_addr             0x0026C890
#define memcpy_addr                     0x00472D20
#define memset_addr                     0x0003E6F0
#define strlen_addr                     0x002E0340
#define printf_addr                     0x000C50F0
#define eventhandler_register_addr      0x002269A0

// Fself
#define sceSblACMgrGetPathId_addr       0x000A5D10
#define sceSblServiceMailbox_addr       0x0062DBE0
#define sceSblAuthMgrSmIsLoadable2_addr 0x006415F0
#define _sceSblAuthMgrGetSelfInfo_addr  0x00641E30
#define _sceSblAuthMgrSmStart_addr      0x0063D790
#define sceSblAuthMgrVerifyHeader_addr  0x00641650

// Fpkg
#define RsaesPkcs1v15Dec2048CRT_addr    0x0006CA20
#define Sha256Hmac_addr                 0x0013A3D0
#define AesCbcCfb128Encrypt_addr        0x003B9E00
#define AesCbcCfb128Decrypt_addr        0x003BA030
#define sceSblDriverSendMsg_0_addr      0x006194A0
#define sceSblPfsSetKeys_addr           0x0062CB00
#define sceSblKeymgrSetKeyStorage_addr  0x00624CA0
#define sceSblKeymgrSetKeyForPfs_addr   0x00621220
#define sceSblKeymgrCleartKey_addr      0x00621560
#define sceSblKeymgrSmCallfunc_addr     0x00620DF0

// Patch
#define vmspace_acquire_ref_addr        0x0038CEE0
#define vmspace_free_addr               0x0038CD10
#define vm_map_lock_read_addr           0x0038D070
#define vm_map_unlock_read_addr         0x0038D0C0
#define vm_map_lookup_entry_addr        0x0038D6B0
#define proc_rwmem_addr                 0x0044DC40

// Fself hooks
#define sceSblAuthMgrIsLoadable__sceSblACMgrGetPathId_hook          0x0063A7FC
#define sceSblAuthMgrIsLoadable2_hook                               0x0063A94E
#define sceSblAuthMgrVerifyHeader_hook1                             0x0063B0E6
#define sceSblAuthMgrVerifyHeader_hook2                             0x0063BDC9
#define sceSblAuthMgrSmLoadSelfSegment__sceSblServiceMailbox_hook   0x0063FBBD
#define sceSblAuthMgrSmLoadSelfBlock__sceSblServiceMailbox_hook     0x00640818

// Fpkg hooks
#define sceSblKeymgrSetKeyStorage__sceSblDriverSendMsg_hook         0x00624D45
#define sceSblKeymgrInvalidateKey__sx_xlock_hook                    0x006223DD
#define sceSblKeymgrSmCallfunc_npdrm_decrypt_isolated_rif_hook      0x0064AD10
#define sceSblKeymgrSmCallfunc_npdrm_decrypt_rif_new_hook           0x0064BADE
#define mountpfs__sceSblPfsSetKeys_hook1                            0x0068E4C9
#define mountpfs__sceSblPfsSetKeys_hook2                            0x0068E6FA
                                                                    
// SceShellUI patches - debug patches                               
#define sceSblRcMgrIsAllowDebugMenuForSettings_patch                0x0001CE50
#define sceSblRcMgrIsStoreMode_patch                                0x0001D1B0
                                                                    
// SceShellUI patches - remote play patches
#define CreateUserForIDU_patch                                      0x00185E90 //system_ex\app\NPXS20001\eboot.bin
#define remote_play_menu_patch                                      0x00EC2282 //system_ex\app\NPXS20001\psm\Application\app.exe.sprx

// SceRemotePlay patches - remote play patches - system\vsh\app\NPXS21006
#define SceRemotePlay_patch1                                        0x000ECB55
#define SceRemotePlay_patch2                                        0x000ECB70

// SceShellCore patches - call sceKernelIsGenuineCEX
#define sceKernelIsGenuineCEX_patch1    0x0016B694
#define sceKernelIsGenuineCEX_patch2    0x008594B4
#define sceKernelIsGenuineCEX_patch3    0x008A85F2
#define sceKernelIsGenuineCEX_patch4    0x00A08094

// SceShellCore patches - call nidf_libSceDipsw
#define nidf_libSceDipsw_patch1         0x0016B6C2
#define nidf_libSceDipsw_patch2         0x00247E4C
#define nidf_libSceDipsw_patch3         0x008594E2
#define nidf_libSceDipsw_patch4         0x00A080C2

// SceShellCore patches - bypass firmware checks
#define app_installer_patch             0x00134A90
#define check_system_version            0x003BF7A7
#define check_title_system_update_patch 0x003C29F0

// SceShellCore patches - enable remote pkg installer
#define enable_data_mount_patch         0x0031B310

// SceShellCore patches - enable VR without spoof
#define enable_psvr_patch               0x00D39B4F

// SceShellCore patches - enable fpkg
#define enable_fpkg_patch               0x003D26AF

// SceShellCore patches - use `free` prefix instead `fake`
#define fake_free_patch                 0x00FB08B9

// SceShellCore patches - enable official external HDD support
#define pkg_installer_patch             0x009F15E1
#define ext_hdd_patch                   0x00604FFD

// SceShellCore patches - enable debug trophies
#define debug_trophies_patch            0x007342E9

// SceShellCore patches - disable screenshot block
#define disable_screenshot_patch        0x00389FE6

#endif