#ifndef __OFFSETS_H__
#define __OFFSETS_H__
#pragma once

// 12.00-12.02
// data
#define XFAST_SYSCALL_addr               0x000001C0
#define M_TEMP_addr                      0x01520D00
#define MINI_SYSCORE_SELF_BINARY_addr    0x0153D6C8
#define ALLPROC_addr                     0x01B284D8
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
#define memcmp_addr                      0x003942A0
#define _sx_xlock_addr                   0x000A3840
#define _sx_xunlock_addr                 0x000A3A00
#define malloc_addr                      0x00009520
#define free_addr                        0x000096E0
#define strstr_addr                      0x0021CC50
#define fpu_kern_enter_addr              0x001DFFE0
#define fpu_kern_leave_addr              0x001E00A0
#define memcpy_addr                      0x002BD480
#define memset_addr                      0x001FA140
#define strlen_addr                      0x0036AB30
#define printf_addr                      0x002E03E0
#define eventhandler_register_addr       0x00224180

// Fself
#define sceSblACMgrGetPathId_addr        0x003B2D80
#define sceSblServiceMailbox_addr        0x0062F960
#define sceSblAuthMgrSmIsLoadable2_addr  0x0063C770
#define _sceSblAuthMgrGetSelfInfo_addr   0x0063CFB0
#define _sceSblAuthMgrSmStart_addr       0x0063DB40
#define sceSblAuthMgrVerifyHeader_addr   0x0063C7D0

// Fpkg
#define RsaesPkcs1v15Dec2048CRT_addr     0x0021B950
#define Sha256Hmac_addr                  0x001F8D40
#define AesCbcCfb128Encrypt_addr         0x00340E30
#define AesCbcCfb128Decrypt_addr         0x00341060
#define sceSblDriverSendMsg_0_addr       0x0061BFA0
#define sceSblPfsSetKeys_addr            0x006266E0
#define sceSblKeymgrSetKeyStorage_addr   0x00624740
#define sceSblKeymgrSetKeyForPfs_addr    0x0062B030
#define sceSblKeymgrCleartKey_addr       0x0062B370
#define sceSblKeymgrSmCallfunc_addr      0x0062AC00

// Patch
#define vmspace_acquire_ref_addr         0x002F6F20
#define vmspace_free_addr                0x002F6D50
#define vm_map_lock_read_addr            0x002F70B0
#define vm_map_unlock_read_addr          0x002F7100
#define vm_map_lookup_entry_addr         0x002F76F0
#define proc_rwmem_addr                  0x00365FA0

// Fself hooks
#define sceSblAuthMgrIsLoadable__sceSblACMgrGetPathId_hook          0x00641F8C
#define sceSblAuthMgrIsLoadable2_hook                               0x006420DE
#define sceSblAuthMgrVerifyHeader_hook1                             0x00642876
#define sceSblAuthMgrVerifyHeader_hook2                             0x00643559
#define sceSblAuthMgrSmLoadSelfSegment__sceSblServiceMailbox_hook   0x0063FF8D
#define sceSblAuthMgrSmLoadSelfBlock__sceSblServiceMailbox_hook     0x00640BC8

// Fpkg hooks
#define sceSblKeymgrSetKeyStorage__sceSblDriverSendMsg_hook         0x006247E5
#define sceSblKeymgrInvalidateKey__sx_xlock_hook                    0x0062C1ED
#define sceSblKeymgrSmCallfunc_npdrm_decrypt_isolated_rif_hook      0x0064C4E0
#define sceSblKeymgrSmCallfunc_npdrm_decrypt_rif_new_hook           0x0064D2AE
#define mountpfs__sceSblPfsSetKeys_hook1                            0x006A2D99
#define mountpfs__sceSblPfsSetKeys_hook2                            0x006A2FCA

// libkernel_sys.sprx patches - debug patches
#define sceSblRcMgrIsAllowDebugMenuForSettings_patch                0x0001D100
#define sceSblRcMgrIsStoreMode_patch                                0x0001D460

// SceShellUI patches - remote play patches
#define CreateUserForIDU_patch                                      0x0018B310  // system_ex\app\NPXS20001\eboot.bin
#define remote_play_menu_patch                                      0x00EC7012  // system_ex\app\NPXS20001\psm\Application\app.exe.sprx

// SceRemotePlay patches - remote play patches - system\vsh\app\NPXS21006
#define SceRemotePlay_patch1                                        0x000ED1F5
#define SceRemotePlay_patch2                                        0x000ED210

// SceShellCore patches - call sceKernelIsGenuineCEX
#define sceKernelIsGenuineCEX_patch1      0x0016F5A4
#define sceKernelIsGenuineCEX_patch2      0x00873754
#define sceKernelIsGenuineCEX_patch3      0x008C3A52
#define sceKernelIsGenuineCEX_patch4      0x00A27304

// SceShellCore patches - call nidf_libSceDipsw
#define nidf_libSceDipsw_patch1           0x0016F5D2
#define nidf_libSceDipsw_patch2           0x0024E14C
#define nidf_libSceDipsw_patch3           0x00873782
#define nidf_libSceDipsw_patch4           0x00A27332

// SceShellCore patches - bypass firmware checks
#define app_installer_patch               0x001389A0
#define check_system_version              0x003CA567
#define check_title_system_update_patch   0x003CD7B0

// SceShellCore patches - enable remote pkg installer
#define enable_data_mount_patch           0x003233B0

// SceShellCore patches - enable VR without spoof
#define enable_psvr_patch                 0x00D568EF

// SceShellCore patches - enable fpkg
#define enable_fpkg_patch                 0x003DE23F

// SceShellCore patches - use `free` prefix instead `fake`
#define fake_free_patch                   0x00FCFDF9

// SceShellCore patches - enable official external HDD support
#define pkg_installer_patch               0x00A10850
#define ext_hdd_patch                     0x0061475D

// SceShellCore patches - enable debug trophies
#define debug_trophies_patch              0x0073F156

// SceShellCore patches - disable screenshot block
#define disable_screenshot_patch          0x00392746

#endif
