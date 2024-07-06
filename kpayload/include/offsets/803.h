#ifndef __OFFSETS_H__
#define __OFFSETS_H__
#pragma once

// 8.03
// data
#define	XFAST_SYSCALL_addr              0x000001C0
#define M_TEMP_addr                     0x01A77E10
#define MINI_SYSCORE_SELF_BINARY_addr   0x01577F28
#define ALLPROC_addr                    0x01B244E0
#define SBL_DRIVER_MAPPED_PAGES_addr    0x0263FAE8
#define SBL_PFS_SX_addr                 0x02644008
#define SBL_KEYMGR_KEY_SLOTS_addr       0x02648848
#define SBL_KEYMGR_KEY_RBTREE_addr      0x02648858
#define SBL_KEYMGR_BUF_VA_addr          0x0264C000
#define SBL_KEYMGR_BUF_GVA_addr         0x0264C808
#define FPU_CTX_addr                    0x0266C500
#define DIPSW_addr                      0x01B51550

// common
#define memcmp_addr                     0x00195A90
#define _sx_xlock_addr                  0x0043A340
#define _sx_xunlock_addr                0x0043A500
#define malloc_addr                     0x0046F7F0
#define free_addr                       0x0046F9B0
#define strstr_addr                     0x00439C10
#define fpu_kern_enter_addr             0x001714B0
#define fpu_kern_leave_addr             0x00171570
#define memcpy_addr                     0x0025E1C0
#define memset_addr                     0x000F6C60
#define strlen_addr                     0x002F6090
#define printf_addr                     0x00430AE0
#define eventhandler_register_addr      0x0026E270

// Fself
#define sceSblACMgrGetPathId_addr       0x001D57C0
#define sceSblServiceMailbox_addr       0x0062F6E0
#define sceSblAuthMgrSmIsLoadable2_addr 0x00641F40
#define _sceSblAuthMgrGetSelfInfo_addr  0x00642780
#define _sceSblAuthMgrSmStart_addr      0x0063D140
#define sceSblAuthMgrVerifyHeader_addr  0x00641FA0

// Fpkg
#define RsaesPkcs1v15Dec2048CRT_addr    0x0038F5A0
#define Sha256Hmac_addr                 0x00126B90
#define AesCbcCfb128Encrypt_addr        0x001665B0
#define AesCbcCfb128Decrypt_addr        0x001667E0
#define sceSblDriverSendMsg_0_addr      0x00619BE0
#define sceSblPfsSetKeys_addr           0x0061CBA0
#define sceSblKeymgrSetKeyStorage_addr  0x00627FB0
#define sceSblKeymgrSetKeyForPfs_addr   0x0061E250
#define sceSblKeymgrCleartKey_addr      0x0061E590
#define sceSblKeymgrSmCallfunc_addr     0x0061DE20

// Patch
#define vmspace_acquire_ref_addr        0x003E74E0
#define vmspace_free_addr               0x003E7310
#define vm_map_lock_read_addr           0x003E7680
#define vm_map_unlock_read_addr         0x003E76D0
#define vm_map_lookup_entry_addr        0x003E7CC0
#define proc_rwmem_addr                 0x00173770

// Fself hooks
#define sceSblAuthMgrIsLoadable__sceSblACMgrGetPathId_hook          0x0063B8BC
#define sceSblAuthMgrIsLoadable2_hook                               0x0063BA0E
#define sceSblAuthMgrVerifyHeader_hook1                             0x0063C1A6
#define sceSblAuthMgrVerifyHeader_hook2                             0x0063CE89
#define sceSblAuthMgrSmLoadSelfSegment__sceSblServiceMailbox_hook   0x0063F59D
#define sceSblAuthMgrSmLoadSelfBlock__sceSblServiceMailbox_hook     0x006401D8

// Fpkg hooks
#define sceSblKeymgrSetKeyStorage__sceSblDriverSendMsg_hook         0x00628055
#define sceSblKeymgrInvalidateKey__sx_xlock_hook                    0x0061F40D
#define sceSblKeymgrSmCallfunc_npdrm_decrypt_isolated_rif_hook      0x0064C590
#define sceSblKeymgrSmCallfunc_npdrm_decrypt_rif_new_hook           0x0064D35E
#define mountpfs__sceSblPfsSetKeys_hook1                            0x0068D509
#define mountpfs__sceSblPfsSetKeys_hook2                            0x0068D73A

//libkernel_sys.sprx patches - debug patches
#define sceSblRcMgrIsAllowDebugMenuForSettings_patch                0x0001D130
#define sceSblRcMgrIsStoreMode_patch                                0x0001D490

//ShellUI patches - remote play patches                                
#define CreateUserForIDU_patch                                      0x00187300 //system_ex\app\NPXS20001\eboot.bin
#define remote_play_menu_patch                                      0x00EDB6B1 //system_ex\app\NPXS20001\psm\Application\app.exe.sprx

// SceRemotePlay patches - remote play patches - system\vsh\app\NPXS21006
#define SceRemotePlay_patch1                                        0x0010C4C8
#define SceRemotePlay_patch2                                        0x0010C4E6

// SceShellCore patches - call sceKernelIsGenuineCEX
#define sceKernelIsGenuineCEX_patch1    0x00168D20
#define sceKernelIsGenuineCEX_patch2    0x0084D080
#define sceKernelIsGenuineCEX_patch3    0x0089C1E2
#define sceKernelIsGenuineCEX_patch4    0x00A236A0

// SceShellCore patches - call nidf_libSceDipsw
#define nidf_libSceDipsw_patch1         0x00168D4A
#define nidf_libSceDipsw_patch2         0x00242978
#define nidf_libSceDipsw_patch3         0x0084D0AA
#define nidf_libSceDipsw_patch4         0x00A236CA

// SceShellCore patches - bypass firmware checks
#define check_disc_root_param_patch     0x00133480
#define app_installer_patch             0x00133570
#define check_system_version            0x003C02E7
#define check_title_system_update_patch 0x003C2970

// SceShellCore patches - enable remote pkg installer
#define enable_data_mount_patch         0x0031C503

// SceShellCore patches - enable VR without spoof
#define enable_psvr_patch               0x00D4F52F

// SceShellCore patches - enable fpkg
#define enable_fpkg_patch               0x003D1A2F

// SceShellCore patches - use `free` prefix instead `fake`
#define fake_free_patch                 0x00FC62B1

// SceShellCore patches - enable official external HDD support
#define pkg_installer_patch             0x00A0C681
#define ext_hdd_patch                   0x0060761D

// SceShellCore patches - enable debug trophies
#define debug_trophies_patch            0x00729659

// SceShellCore patches - disable screenshot block
#define disable_screenshot_patch        0x003862F6

#endif