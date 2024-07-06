#ifndef __OFFSETS_H__
#define __OFFSETS_H__
#pragma once

// 9.04
// data
#define XFAST_SYSCALL_addr               0x000001C0
#define M_TEMP_addr                      0x0155E1E0
#define MINI_SYSCORE_SELF_BINARY_addr    0x01575DF8
#define ALLPROC_addr                     0x01B906E0
#define SBL_DRIVER_MAPPED_PAGES_addr     0x02642CA8
#define SBL_PFS_SX_addr                  0x02649B40
#define SBL_KEYMGR_KEY_SLOTS_addr        0x02644238
#define SBL_KEYMGR_KEY_RBTREE_addr       0x02644248
#define SBL_KEYMGR_BUF_VA_addr           0x02648000
#define SBL_KEYMGR_BUF_GVA_addr          0x02648808
#define FPU_CTX_addr                     0x026501C0
#define DIPSW_addr                       0x02212850

// common
#define memcmp_addr                      0x00271AA0
#define _sx_xlock_addr                   0x0043C530
#define _sx_xunlock_addr                 0x0043C6F0
#define malloc_addr                      0x003017B0
#define free_addr                        0x00301970
#define strstr_addr                      0x004859B0
#define fpu_kern_enter_addr              0x002193A0
#define fpu_kern_leave_addr              0x00219460
#define memcpy_addr                      0x00271130
#define memset_addr                      0x00149670
#define strlen_addr                      0x0030F0F0
#define printf_addr                      0x000B79E0
#define eventhandler_register_addr       0x000F8320

// Fself                                 
#define sceSblACMgrGetPathId_addr        0x0008BCD0
#define sceSblServiceMailbox_addr        0x0062EC00
#define sceSblAuthMgrSmIsLoadable2_addr  0x00641960
#define _sceSblAuthMgrGetSelfInfo_addr   0x006421A0
#define _sceSblAuthMgrSmStart_addr       0x0063DEA0
#define sceSblAuthMgrVerifyHeader_addr   0x006419C0

// Fpkg                                  
#define RsaesPkcs1v15Dec2048CRT_addr     0x004607B0
#define Sha256Hmac_addr                  0x00442F80
#define AesCbcCfb128Encrypt_addr         0x001FF000
#define AesCbcCfb128Decrypt_addr         0x001FF230
#define sceSblDriverSendMsg_0_addr       0x0061AE90
#define sceSblPfsSetKeys_addr            0x00623290
#define sceSblKeymgrSetKeyStorage_addr   0x00622930
#define sceSblKeymgrSetKeyForPfs_addr    0x0061D650
#define sceSblKeymgrCleartKey_addr       0x0061D990
#define sceSblKeymgrSmCallfunc_addr      0x0061D220

// Patch                                 
#define vmspace_acquire_ref_addr         0x0007B9E0
#define vmspace_free_addr                0x0007B810
#define vm_map_lock_read_addr            0x0007BB80
#define vm_map_unlock_read_addr          0x0007BBD0
#define vm_map_lookup_entry_addr         0x0007C1C0
#define proc_rwmem_addr                  0x0041CA70

// Fself hooks
#define sceSblAuthMgrIsLoadable__sceSblACMgrGetPathId_hook          0x006426FC
#define sceSblAuthMgrIsLoadable2_hook                               0x0064284E
#define sceSblAuthMgrVerifyHeader_hook1                             0x00642FE6
#define sceSblAuthMgrVerifyHeader_hook2                             0x00643CC9
#define sceSblAuthMgrSmLoadSelfSegment__sceSblServiceMailbox_hook   0x006402ED
#define sceSblAuthMgrSmLoadSelfBlock__sceSblServiceMailbox_hook     0x00640F28

// Fpkg hooks                                                       
#define sceSblKeymgrSetKeyStorage__sceSblDriverSendMsg_hook         0x006229D5
#define sceSblKeymgrInvalidateKey__sx_xlock_hook                    0x0061E80D
#define sceSblKeymgrSmCallfunc_npdrm_decrypt_isolated_rif_hook      0x0064C030
#define sceSblKeymgrSmCallfunc_npdrm_decrypt_rif_new_hook           0x0064CDFE
#define mountpfs__sceSblPfsSetKeys_hook1                            0x006C1EB9
#define mountpfs__sceSblPfsSetKeys_hook2                            0x006C20EA

//SceShellUI patches - debug patches
#define sceSblRcMgrIsAllowDebugMenuForSettings_patch                0x0001D1C0
#define sceSblRcMgrIsStoreMode_patch                                0x0001D520

// SceShellUI patches - remote play patches
#define CreateUserForIDU_patch                                      0x00188C10 //system_ex\app\NPXS20001\eboot.bin
#define remote_play_menu_patch                                      0x00EE5651 //system_ex\app\NPXS20001\psm\Application\app.exe.sprx

// SceRemotePlay patches - remote play patches - system\vsh\app\NPXS21006
#define SceRemotePlay_patch1                                        0x0010039B
#define SceRemotePlay_patch2                                        0x001003B6

// SceShellCore patches - call sceKernelIsGenuineCEX
#define sceKernelIsGenuineCEX_patch1    0x0016F014
#define sceKernelIsGenuineCEX_patch2    0x00864774
#define sceKernelIsGenuineCEX_patch3    0x008B2262
#define sceKernelIsGenuineCEX_patch4    0x00A2A274

// SceShellCore patches - call nidf_libSceDipsw
#define nidf_libSceDipsw_patch1         0x0016F042
#define nidf_libSceDipsw_patch2         0x0024A4EB
#define nidf_libSceDipsw_patch3         0x008647A2
#define nidf_libSceDipsw_patch4         0x00A2A2A2

// SceShellCore patches - bypass firmware checks
#define check_disc_root_param_patch     0x00139310
#define app_installer_patch             0x00139400
#define check_system_version            0x003C8417
#define check_title_system_update_patch 0x003CAAB0

// SceShellCore patches - enable remote pkg installer
#define enable_data_mount_patch         0x00321F2B

// SceShellCore patches - enable VR without spoof
#define enable_psvr_patch               0x00D5A4D1

// SceShellCore patches - enable fpkg
#define enable_fpkg_patch               0x003DA06F
 
// SceShellCore patches - use `free` prefix instead `fake`
#define fake_free_patch                 0x00FD5BF1

// SceShellCore patches - enable official external HDD support
#define pkg_installer_patch             0x00A13121
#define ext_hdd_patch                   0x0061A69D

// SceShellCore patches - enable debug trophies
#define debug_trophies_patch            0x00741839

// SceShellCore patches - disable screenshot block
#define disable_screenshot_patch        0x0038EE26

#endif