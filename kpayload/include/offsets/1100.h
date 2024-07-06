#ifndef OFFSET1100_H
#define OFFSET1100_H

// 11.00
// data
#define XFAST_SYSCALL_addr               0x000001C0
#define M_TEMP_addr                      0x015415B0
#define MINI_SYSCORE_SELF_BINARY_addr    0x0155CC48
#define ALLPROC_addr                     0x022D0A98
#define SBL_DRIVER_MAPPED_PAGES_addr     0x02646688
#define SBL_PFS_SX_addr                  0x0264C080
#define SBL_KEYMGR_KEY_SLOTS_addr        0x026606E8
#define SBL_KEYMGR_KEY_RBTREE_addr       0x026606F8
#define SBL_KEYMGR_BUF_VA_addr           0x02664000
#define SBL_KEYMGR_BUF_GVA_addr          0x02664808
#define FPU_CTX_addr                     0x02660180
#define DIPSW_addr                       0x0221C5D0

// common
#define memcmp_addr                      0x000948B0
#define _sx_xlock_addr                   0x000E3200
#define _sx_xunlock_addr                 0x000E33C0
#define malloc_addr                      0x001A4220
#define free_addr                        0x001A43E0
#define strstr_addr                      0x002C5740
#define fpu_kern_enter_addr              0x000C0660
#define fpu_kern_leave_addr              0x000C0720
#define memcpy_addr                      0x002DDDF0
#define memset_addr                      0x000482D0
#define strlen_addr                      0x0021DC40
#define printf_addr                      0x002FCBD0
#define eventhandler_register_addr       0x0043E440

// Fself
#define sceSblACMgrGetPathId_addr        0x003D0E90
#define sceSblServiceMailbox_addr        0x0062F810
#define sceSblAuthMgrSmIsLoadable2_addr  0x00642F90
#define _sceSblAuthMgrGetSelfInfo_addr   0x006437D0
#define _sceSblAuthMgrSmStart_addr       0x0063E9C0
#define sceSblAuthMgrVerifyHeader_addr   0x00642FF0

// Fpkg
#define RsaesPkcs1v15Dec2048CRT_addr     0x003C8060
#define Sha256Hmac_addr                  0x002D1CA0
#define AesCbcCfb128Encrypt_addr         0x002DEAA0
#define AesCbcCfb128Decrypt_addr         0x002DECD0
#define sceSblDriverSendMsg_0_addr       0x0061AF60
#define sceSblPfsSetKeys_addr            0x0061D900
#define sceSblKeymgrSetKeyStorage_addr   0x0062EDC0
#define sceSblKeymgrSetKeyForPfs_addr    0x00625DF0
#define sceSblKeymgrCleartKey_addr       0x00626130
#define sceSblKeymgrSmCallfunc_addr      0x006259C0

// Patch
#define vmspace_acquire_ref_addr         0x00357720
#define vmspace_free_addr                0x00357550
#define vm_map_lock_read_addr            0x003578B0
#define vm_map_unlock_read_addr          0x00357900
#define vm_map_lookup_entry_addr         0x00357EF0
#define proc_rwmem_addr                  0x003838A0

// Fself hooks
#define sceSblAuthMgrIsLoadable__sceSblACMgrGetPathId_hook          0x0063D13C
#define sceSblAuthMgrIsLoadable2_hook                               0x0063D28E
#define sceSblAuthMgrVerifyHeader_hook1                             0x0063DA26
#define sceSblAuthMgrVerifyHeader_hook2                             0x0063E709
#define sceSblAuthMgrSmLoadSelfSegment__sceSblServiceMailbox_hook   0x00640E0D
#define sceSblAuthMgrSmLoadSelfBlock__sceSblServiceMailbox_hook     0x00641A48

// Fpkg hooks
#define sceSblKeymgrSetKeyStorage__sceSblDriverSendMsg_hook         0x0062EE65
#define sceSblKeymgrInvalidateKey__sx_xlock_hook                    0x00626FAD
#define sceSblKeymgrSmCallfunc_npdrm_decrypt_isolated_rif_hook      0x0064D230
#define sceSblKeymgrSmCallfunc_npdrm_decrypt_rif_new_hook           0x0064DFFE
#define mountpfs__sceSblPfsSetKeys_hook1                            0x006993B9
#define mountpfs__sceSblPfsSetKeys_hook2                            0x006995EA

//libkernel_sys.sprx patches - debug patches
#define sceSblRcMgrIsAllowDebugMenuForSettings_patch                0x0001D100
#define sceSblRcMgrIsStoreMode_patch                                0x0001D460

// SceShellUI patches - remote play patches                                
#define CreateUserForIDU_patch                                      0x0018B110  //system_ex\app\NPXS20001\eboot.bin
#define remote_play_menu_patch                                      0x00ECAB92 //system_ex\app\NPXS20001\psm\Application\app.exe.sprx

// SceRemotePlay patches - remote play patches - system\vsh\app\NPXS21006
#define SceRemotePlay_patch1                                        0x000ECCB5
#define SceRemotePlay_patch2                                        0x000ECCD0

// SceShellCore patches - call sceKernelIsGenuineCEX
#define sceKernelIsGenuineCEX_patch1      0x0016B664
#define sceKernelIsGenuineCEX_patch2      0x0086BD24
#define sceKernelIsGenuineCEX_patch3      0x008BC022
#define sceKernelIsGenuineCEX_patch4      0x00A1D6C4

// SceShellCore patches - call nidf_libSceDipsw
#define nidf_libSceDipsw_patch1           0x0016B692
#define nidf_libSceDipsw_patch2           0x00249E0C
#define nidf_libSceDipsw_patch3           0x0086BD52
#define nidf_libSceDipsw_patch4           0x00A1D6F2

// SceShellCore patches - bypass firmware checks
#define app_installer_patch               0x00134A50
#define check_system_version              0x003C41A7
#define check_title_system_update_patch   0x003C73F0

// SceShellCore patches - enable remote pkg installer
#define enable_data_mount_patch           0x0031F070

// SceShellCore patches - enable VR without spoof
#define enable_psvr_patch                 0x00D5019F

// SceShellCore patches - enable fpkg
#define enable_fpkg_patch                 0x003D7C9F
 
// SceShellCore patches - use `free` prefix instead `fake`
#define fake_free_patch                   0x00FC8439

// SceShellCore patches - enable official external HDD support
#define pkg_installer_patch               0x00A06C11
#define ext_hdd_patch                     0x0060E17D

// SceShellCore patches - enable debug trophies
#define debug_trophies_patch              0x007416B6

// disable screenshot block
#define disable_screenshot_patch          0x0038D976

#endif
