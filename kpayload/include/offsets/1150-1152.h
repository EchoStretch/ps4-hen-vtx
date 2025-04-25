#ifndef __OFFSETS_H__
#define __OFFSETS_H__
#pragma once

// 11.50
// data
#define XFAST_SYSCALL_addr               0x000001C0
#define M_TEMP_addr                      0x01520D00
#define MINI_SYSCORE_SELF_BINARY_addr    0x0153D6C8
#define ALLPROC_addr                     0x01B28538
#define SBL_DRIVER_MAPPED_PAGES_addr     0x02647350
#define SBL_PFS_SX_addr                  0x0265C080
#define SBL_KEYMGR_KEY_SLOTS_addr        0x02668040
#define SBL_KEYMGR_KEY_RBTREE_addr       0x02668050
#define SBL_KEYMGR_BUF_VA_addr           0x0266C000
#define SBL_KEYMGR_BUF_GVA_addr          0x0266C808
#define FPU_CTX_addr                     0x026542C0
#define DIPSW_addr                       0x021CC5D0
#define SYSENT_addr                      0x01102B70

// common
#define memcmp_addr                      0x00394060
#define _sx_xlock_addr                   0x000A3840
#define _sx_xunlock_addr                 0x000A3A00
#define malloc_addr                      0x00009520
#define free_addr                        0x000096E0
#define strstr_addr                      0x0021CB70
#define fpu_kern_enter_addr              0x001DFFE0
#define fpu_kern_leave_addr              0x001E00A0
#define memcpy_addr                      0x002BD3A0
#define memset_addr                      0x001FA060
#define strlen_addr                      0x0036A8F0
#define printf_addr                      0x002E01A0
#define eventhandler_register_addr       0x00224030

// Fself
#define sceSblACMgrGetPathId_addr        0x003B2B40
#define sceSblServiceMailbox_addr        0x0062F720
#define sceSblAuthMgrSmIsLoadable2_addr  0x0063C530
#define _sceSblAuthMgrGetSelfInfo_addr   0x0063CD70
#define _sceSblAuthMgrSmStart_addr       0x0063D900
#define sceSblAuthMgrVerifyHeader_addr   0x0063C590

// Fpkg
#define RsaesPkcs1v15Dec2048CRT_addr     0x003C7360
#define Sha256Hmac_addr                  0x001F8C60
#define AesCbcCfb128Encrypt_addr         0x00340BF0
#define AesCbcCfb128Decrypt_addr         0x00340E20
#define sceSblDriverSendMsg_0_addr       0x0061BD60
#define sceSblPfsSetKeys_addr            0x006264A0
#define sceSblKeymgrSetKeyStorage_addr   0x00624500
#define sceSblKeymgrSetKeyForPfs_addr    0x0062ADF0
#define sceSblKeymgrCleartKey_addr       0x0062B130
#define sceSblKeymgrSmCallfunc_addr      0x0062A9C0

// Patch
#define vmspace_acquire_ref_addr         0x002F6CE0
#define vmspace_free_addr                0x002F6B10
#define vm_map_lock_read_addr            0x002F6E70
#define vm_map_unlock_read_addr          0x002F6EC0
#define vm_map_lookup_entry_addr         0x002F74B0
#define proc_rwmem_addr                  0x00365D60

// Fself hooks
#define sceSblAuthMgrIsLoadable__sceSblACMgrGetPathId_hook          0x00641D4C
#define sceSblAuthMgrIsLoadable2_hook                               0x00641E9E
#define sceSblAuthMgrVerifyHeader_hook1                             0x00642636
#define sceSblAuthMgrVerifyHeader_hook2                             0x00643319
#define sceSblAuthMgrSmLoadSelfSegment__sceSblServiceMailbox_hook   0x0063FD4D
#define sceSblAuthMgrSmLoadSelfBlock__sceSblServiceMailbox_hook     0x00640988

// Fpkg hooks
#define sceSblKeymgrSetKeyStorage__sceSblDriverSendMsg_hook         0x006245A5
#define sceSblKeymgrInvalidateKey__sx_xlock_hook                    0x0062BFAD
#define sceSblKeymgrSmCallfunc_npdrm_decrypt_isolated_rif_hook      0x0064C2A0
#define sceSblKeymgrSmCallfunc_npdrm_decrypt_rif_new_hook           0x0064D06E
#define mountpfs__sceSblPfsSetKeys_hook1                            0x006A2919
#define mountpfs__sceSblPfsSetKeys_hook2                            0x006A2B4A

// libkernel_sys.sprx patches - debug patches
#define sceSblRcMgrIsAllowDebugMenuForSettings_patch                0x0001D100
#define sceSblRcMgrIsStoreMode_patch                                0x0001D460

// SceShellUI patches - remote play patches                                
#define CreateUserForIDU_patch                                      0x0018B110  //system_ex\app\NPXS20001\eboot.bin
#define remote_play_menu_patch                                      0x00EC6F92 //system_ex\app\NPXS20001\psm\Application\app.exe.sprx

// SceRemotePlay patches - remote play patches - system\vsh\app\NPXS21006
#define SceRemotePlay_patch1                                        0x000ED1D5
#define SceRemotePlay_patch2                                        0x000ED1F0

// SceShellCore patches - call sceKernelIsGenuineCEX
#define sceKernelIsGenuineCEX_patch1      0x0016E004
#define sceKernelIsGenuineCEX_patch2      0x00870E44
#define sceKernelIsGenuineCEX_patch3      0x008C1142
#define sceKernelIsGenuineCEX_patch4      0x00A228B4

// SceShellCore patches - call nidf_libSceDipsw
#define nidf_libSceDipsw_patch1           0x0016E032
#define nidf_libSceDipsw_patch2           0x0024C72C
#define nidf_libSceDipsw_patch3           0x00870E72
#define nidf_libSceDipsw_patch4           0x00A228E2

// SceShellCore patches - bypass firmware checks
#define app_installer_patch               0x001373F0
#define check_system_version              0x003C8B47
#define check_title_system_update_patch   0x003CBD90

// SceShellCore patches - enable remote pkg installer
#define enable_data_mount_patch           0x00321990

// SceShellCore patches - enable VR without spoof
#define enable_psvr_patch                 0x00D5578F

// SceShellCore patches - enable fpkg
#define enable_fpkg_patch                 0x003DC64F
 
// SceShellCore patches - use `free` prefix instead `fake`
#define fake_free_patch                   0x00FCE619

// SceShellCore patches - enable official external HDD support
#define pkg_installer_patch               0x00A0BE01
#define ext_hdd_patch                     0x00612B6D

// SceShellCore patches - enable debug trophies
#define debug_trophies_patch              0x00746B06

// disable screenshot block
#define disable_screenshot_patch          0x00390EDC

#endif
