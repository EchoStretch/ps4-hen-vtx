#ifndef __OFFSETS_H__
#define __OFFSETS_H__
#pragma once
// 9.00

// data
#define	XFAST_SYSCALL_addr               0x000001C0
#define M_TEMP_addr                      0x015621E0
#define MINI_SYSCORE_SELF_BINARY_addr    0x01579DF8
#define ALLPROC_addr                     0x01B946E0
#define SBL_DRIVER_MAPPED_PAGES_addr     0x02646CA8
#define SBL_PFS_SX_addr                  0x0264DB40
#define SBL_KEYMGR_KEY_SLOTS_addr        0x02648238
#define SBL_KEYMGR_KEY_RBTREE_addr       0x02648248
#define SBL_KEYMGR_BUF_VA_addr           0x0264C000
#define SBL_KEYMGR_BUF_GVA_addr          0x0264C808
#define FPU_CTX_addr                     0x026541C0
#define DIPSW_addr                       0x02216850

// common
#define memcmp_addr                      0x00271E20
#define _sx_xlock_addr                   0x0043E610
#define _sx_xunlock_addr                 0x0043E7D0
#define malloc_addr                      0x00301B20
#define free_addr                        0x00301CE0
#define strstr_addr                      0x00487AB0
#define fpu_kern_enter_addr              0x002196D0
#define fpu_kern_leave_addr              0x00219790
#define memcpy_addr                      0x002714B0
#define memset_addr                      0x001496C0
#define strlen_addr                      0x0030F450
#define printf_addr                      0x000B7A30
#define eventhandler_register_addr       0x000F8370

// Fself
#define sceSblACMgrGetPathId_addr        0x0008BCD0
#define sceSblServiceMailbox_addr        0x00630C40
#define sceSblAuthMgrSmIsLoadable2_addr  0x006439A0
#define _sceSblAuthMgrGetSelfInfo_addr   0x006441E0
#define _sceSblAuthMgrSmStart_addr       0x0063FEE0
#define sceSblAuthMgrVerifyHeader_addr   0x00643A00

// Fpkg
#define RsaesPkcs1v15Dec2048CRT_addr     0x004628B0
#define Sha256Hmac_addr                  0x00445060
#define AesCbcCfb128Encrypt_addr         0x001FF2D0
#define AesCbcCfb128Decrypt_addr         0x001FF500
#define sceSblDriverSendMsg_0_addr       0x0061CED0
#define sceSblPfsSetKeys_addr            0x006252D0
#define sceSblKeymgrSetKeyStorage_addr   0x00624970
#define sceSblKeymgrSetKeyForPfs_addr    0x0061F690
#define sceSblKeymgrCleartKey_addr       0x0061F9D0
#define sceSblKeymgrSmCallfunc_addr      0x0061F260

// Patch
#define vmspace_acquire_ref_addr         0x0007B9E0
#define vmspace_free_addr                0x0007B810
#define vm_map_lock_read_addr            0x0007BB80
#define vm_map_unlock_read_addr          0x0007BBD0
#define vm_map_lookup_entry_addr         0x0007C1C0
#define proc_rwmem_addr                  0x0041EB00

#define printf_hook                      0x01A7ED68

// Fself hooks
#define sceSblAuthMgrIsLoadable__sceSblACMgrGetPathId_hook          0x0064473C
#define sceSblAuthMgrIsLoadable2_hook                               0x0064488E
#define sceSblAuthMgrVerifyHeader_hook1                             0x00645026
#define sceSblAuthMgrVerifyHeader_hook2                             0x00645D09
#define sceSblAuthMgrSmLoadSelfSegment__sceSblServiceMailbox_hook   0x0064232D
#define sceSblAuthMgrSmLoadSelfBlock__sceSblServiceMailbox_hook     0x00642F68

// Fpkg hooks
#define sceSblKeymgrSetKeyStorage__sceSblDriverSendMsg_hook         0x00624A15
#define sceSblKeymgrInvalidateKey__sx_xlock_hook                    0x0062084D
#define sceSblKeymgrSmCallfunc_npdrm_decrypt_isolated_rif_hook      0x0064E070
#define sceSblKeymgrSmCallfunc_npdrm_decrypt_rif_new_hook           0x0064EE3E
#define mountpfs__sceSblPfsSetKeys_hook1                            0x006C3EF9
#define mountpfs__sceSblPfsSetKeys_hook2                            0x006C412A

//libkernel_sys.sprx patches - debug patches
#define sceSblRcMgrIsAllowDebugMenuForSettings_patch                0x0001D1C0
#define sceSblRcMgrIsStoreMode_patch                                0x0001D520

// SceShellUI patches - remote play patches                                
#define CreateUserForIDU_patch                                      0x00188c10 //system_ex\app\NPXS20001\eboot.bin
#define remote_play_menu_patch                                      0x00EE55C1 //system_ex\app\NPXS20001\psm\Application\app.exe.sprx

// SceRemotePlay patches - remote play patches - system\vsh\app\NPXS21006
#define SceRemotePlay_patch1                                        0x0010039B
#define SceRemotePlay_patch2                                        0x001003B6

// SceShellCore patches - call sceKernelIsGenuineCEX
#define sceKernelIsGenuineCEX_patch1    0x0016EAA4
#define sceKernelIsGenuineCEX_patch2    0x008621D4
#define sceKernelIsGenuineCEX_patch3    0x008AFBC2
#define sceKernelIsGenuineCEX_patch4    0x00A27BD4

// SceShellCore patches - call nidf_libSceDipsw
#define nidf_libSceDipsw_patch1         0x0016EAD2
#define nidf_libSceDipsw_patch2         0x00249F7B
#define nidf_libSceDipsw_patch3         0x00862202
#define nidf_libSceDipsw_patch4         0x00A27C02

// SceShellCore patches - bypass firmware checks
#define check_disc_root_param_patch     0x00138DA0
#define app_installer_patch             0x00138E90
#define check_system_version            0x003C5EA7
#define check_title_system_update_patch 0x003C8540

// SceShellCore patches - enable remote pkg installer
#define enable_data_mount_patch         0x0032079B

// SceShellCore patches - enable VR without spoof
#define enable_psvr_patch               0x00D57E5F

// SceShellCore patches - enable fpkg
#define enable_fpkg_patch               0x003D7AFF
 
// SceShellCore patches - use `free` prefix instead `fake`
#define fake_free_patch                 0x00FD3211

// SceShellCore patches - enable official external HDD support
#define pkg_installer_patch             0x00A10A81
#define ext_hdd_patch                   0x006180FD

// SceShellCore patches - enable debug trophies
#define debug_trophies_patch            0x0073F159

// SceShellCore patches - disable screenshot block
#define disable_screenshot_patch        0x0038C8B6

#endif