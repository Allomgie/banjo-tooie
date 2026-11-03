#include "common.h"

#define CODEX_VERTEX_SHIFT_RECORD
extern int D_80809E44_chdiggerboss[];
extern s32 D_80128410;
extern s32 func_801017D0();
extern void *func_80100094(Actor *, u32);
extern u8 D_80809EE0_chdiggerboss[];
extern s16 D_80809EE2_chdiggerboss;
extern void func_80101808();
extern void func_800DF830(s32);
extern void func_800DF410(s32);
extern int func_800DE498(void *, f32 *, f32 *, f32, f32 *, u8 *);
extern s32 func_800D674C(s32);
extern int func_800EB854();
extern u8 D_80809ED4_chdiggerboss[];
extern void * func_8010262C(void *, s32);
extern void func_800E0AFC(void *, s32, f32, f32, f32, f32);
extern void func_800E0C20(void *, s32, f32, f32, f32, f32);
extern u16 D_80809EE4_chdiggerboss[];
typedef struct { u8 pad_0[0xFD]; u8 local_0[3]; } DiggerFlags1473;
extern u8 unk64[];
extern u8 D_80809F04_chdiggerboss[];
extern void func_800EE7F8(f32 *, f32 *);
extern u8 D_80809F1C_chdiggerboss[];
extern u8 D_80809F10_chdiggerboss[];
extern Actor *func_80106790();
extern void * _gcdialogcamera_entrypoint_0(int, int);
extern void _plcamera_entrypoint_9(s32, f32 *, f32);
extern void _gcnewoption_entrypoint_35();
extern u8 D_80809F34_chdiggerboss[];
extern void _gcnewoption_entrypoint_14(void *, s32, s32, s32, f32);
extern void _gcnewoption_entrypoint_11(void *);
extern u16 D_80809F28_chdiggerboss[][2];
extern u8 unk4[];
extern void func_800E8C08();
extern u8 _subaddieaudioloop_entrypoint_3();
extern f32 _dbskeleton_entrypoint_1(void *);
extern void *func_800B27E0(void *);
extern s32 D_80809FE0_chdiggerboss[];
extern s32 func_800D91EC(f32 *, f32);
extern void _subaddieaudioquick_entrypoint_2();
extern u8 D_80809F3C_chdiggerboss[];
extern u8 D_80809F40_chdiggerboss[];
extern u8 D_80809F44_chdiggerboss[];
extern u8 D_80809F5C_chdiggerboss[];
extern u8 D_80809F74_chdiggerboss[];
extern u8 D_80809F88_chdiggerboss[];
extern int _subaddieskeleton_entrypoint_2(Unk80132ED0 *, s32, f32 *);
extern void func_800EF1B8(f32 *, f32, f32);
extern void func_800EEB9C(f32 *, f32, f32);
extern s32 func_8010D490(f32 *, f32 *, f32, f32, s32);
extern f32 func_800EFB8C(f32 *, f32 *);
extern f32 func_800F10B4(f32, f32, f32, f32, f32);
extern f32 func_800F1DF4(f32 *, f32 *);
extern void func_800F48BC(s32, f32 *);
extern f32 func_800D8FF8(void);
extern f32 func_800136E4(f32);
extern u8 D_8080A038_chdiggerboss[];
extern void func_800E8870(u8, f32);
extern u8 D_8080A040_chdiggerboss[];
extern u8 D_8080A058_chdiggerboss[];
typedef struct { s16 unk0; s16 unk2; u8 pad4[0x18]; } DiggerSlot;
extern s16 D_8080A060_chdiggerboss[];
extern void func_800DF744();
typedef struct { s16 x0; s16 x2; s32 x4; f32 pos[3]; u8 x14; u8 x15; u8 x16; u8 pad17[5]; } Elem;
typedef struct { u8 pad[0x34]; Elem e[1]; } Data;
extern void func_8010A570(s32);
typedef struct { u8 pad_0[0x25]; u8 enabled; u8 pad_1[6]; f32 timer; } DiggerWaitState;
extern s32 func_800D90A4(f32 *);
typedef struct DiggerEffectRecord { s32 local_0; s16 local_1; u8 pad_0[6]; f32 local_2[3]; u8 local_3; u8 pad_1[3]; } DiggerEffectRecord;
typedef struct DiggerEffects { u8 pad_0[0x30]; DiggerEffectRecord local_0[4]; } DiggerEffects;
extern u32 D_8080A06C_chdiggerboss[][3];
extern s32 func_8001210C(s32 param_0);
extern void func_800C8CB8(s32 param_0, f32 param_1[3]);
extern void func_800C8E84(s32 param_0, u32 param_1[3]);
extern int func_800C8FE0(s32 param_0, s32 param_1);
typedef struct { u8 pad[0x36]; s16 a; u8 pad2[0x1C - 0x38 + 0x36 - 0x36]; } DiggerEntry;
typedef struct { u8 unused[0x18]; f32 timer; u8 unused1C[9]; u8 enabled; } DiggerBossTimerState;
typedef struct { u8 pad_0[0x18]; f32 local_0; f32 local_1; f32 local_2; u8 pad_1; u8 local_3; } DiggerSpin1590;
struct DiggerAttackMotion;
extern int func_800F54E4(void);
extern int func_800F6D24(s32);
extern u8 func_800D9078(f32 *);
extern int D_8080A084_chdiggerboss[];
extern int D_8080A0A8_chdiggerboss[];
extern int D_8080A090_chdiggerboss[];
extern int D_8080A09C_chdiggerboss[];
typedef struct { u8 pad_0[0x14]; f32 local_0; f32 local_1; u8 pad_1[0xC]; s16 local_2; } DiggerAttackState;
typedef struct DiggerAttackMotion { u8 pad_0[0x24]; f32 local_0; } DiggerAttackMotion;
typedef struct { u8 pad_0[8]; s16 local_0; u8 pad_1[6]; f32 local_1; } DiggerBossTurn;
extern f32 func_8010CD50(Actor *, s32);
extern f32 func_800F1FF0(f32, f32, f32, f32, f32);
extern s32 func_800F20BC(f32, f32, f32);
extern f32 func_800F1F38(f32, f32, f32);
extern f32 func_800F1DCC(f32, f32);
extern f32 mlAbsF(f32);
extern s32 D_8080A0EC_chdiggerboss[];
extern s32 *func_801084B0(s32, Actor **);
extern s16 D_8080A11C_chdiggerboss[];
extern s16 D_8080A104_chdiggerboss[];
extern u8 D_8080A134_chdiggerboss[12];
extern u8 D_8080A120_chdiggerboss[20];
extern void _chbaddiesetup_entrypoint_10();
extern s32 func_800F1E6C(f32 *, void *, f32 *);
extern f32 func_800F2094(f32, f32);
extern f32 func_800DC178(f32, f32);
extern void _chbounce_entrypoint_3(f32);
extern int _chbaddiesetup_entrypoint_5(void *, s32, s32, s32, s32, s32);
typedef struct { u8 pad_0[0x7C]; s16 local_0; s16 local_1; u8 pad_1[4]; f32 local_2; s16 local_3[8]; } DiggerBossPose61;
extern u8 D_8080A160_chdiggerboss[];
typedef struct { u8 pad_0[0xA4]; s16 local_0; s16 pad_1; void *local_1; } DiggerCameraState61;
extern u8 D_8080A16C_chdiggerboss[];
extern s32 func_800BBCB8(f32 *, f32 *, f32, s32, void *);
extern void func_800EFA4C(f32 *, f32, f32, f32);
extern s32 position_x;
extern u8 unkD0[];
extern u8 unkCC[];
typedef struct { u8 pad_0[0x10]; f32 local_0; } DiggerBraceState;
extern void func_800EFE50(f32 *, void *, void *, f32);
typedef struct { u8 pad_0[0xB0]; Unk80132ED0 *local_0[4]; } DiggerCleanupMarkers;
typedef struct { u8 pad_0[0xAC]; s32 enabled; Unk80132ED0 *markers[4]; } DiggerBossMarkers;
extern f32 D_8080A1AC_chdiggerboss[];
extern f32 D_8080A1BC_chdiggerboss[];
extern f32 D_8080A1CC_chdiggerboss[];
extern void func_800EEC30(f32 *, f32, f32, f32);
extern void func_800EF04C(f32 *, f32 *);
typedef struct { u8 pad_0[0xC0]; f32 local_0[2]; u8 pad_1[0xC]; f32 local_1[3]; f32 local_2; } DiggerResetPose;
extern int D_8080A1E8_chdiggerboss[];
extern int D_8080A1DC_chdiggerboss[];
extern s32 func_801065A4(Actor *);
extern void _chdiggerboss_entrypoint_3();
extern void _glid_entrypoint_0(s32, s32, void (*)(), Unk80132ED0 *);
typedef struct { s16 position[3]; u16 unk6; s16 unk8; s16 unkA; u8 padC[4]; } VertexShiftRecord;
typedef struct { u8 pad_0[0xC0]; f32 local_0; f32 local_1; } DiggerBlendState;
extern u8 D_8080A1F4_chdiggerboss[];
extern u8 D_8080A1FA_chdiggerboss[];
extern u8 D_8080A1FC_chdiggerboss[];
extern u8 D_8080A202_chdiggerboss[];
extern void func_800FC74C(u32);
extern void func_800FC6B0(u32);
typedef struct { u8 pad_0[0xDC]; u32 local_0; f32 local_1; s32 local_2; } DiggerStageState;
extern u8 D_8080A1FE_chdiggerboss[];
extern u8 D_8080A206_chdiggerboss[];
extern u8 D_8080A208_chdiggerboss[];
extern void _chexploder_entrypoint_5(Actor *, s32, f32 *, f32, f32, s32);
extern s16 D_8080A204_chdiggerboss[][4];
extern u8 D_8080A240_chdiggerboss[];
extern void _chexploder_entrypoint_6(Actor *, f32, f32);
extern u8 D_8080A250_chdiggerboss[];
extern u8 D_8080A25C_chdiggerboss[];
extern u8 D_8080A22C_chdiggerboss[];
extern u8 D_8080A294_chdiggerboss[];
extern u8 D_8080A2B8_chdiggerboss[];
extern s32 func_800B53A4(s32);
extern s32 func_800BABB8(s32, f32 *, f32 *, f32, s32 *);
extern void func_800BA77C();
extern void func_8010D930(s32, s32, f32 *, void *);
typedef struct { u8 pad_0[0xCC]; s8 local_0; f32 local_1; } DiggerPhase59;
extern s32 func_80102320(Actor *param_0, f32 param_1, f32 param_2);
extern void _subaddieaudioquick_entrypoint_3(Actor *, u8 *, u8 *, f32);
extern void _gcdialogcamera_entrypoint_3(f32 *, f32);
extern void _gcdialogcamera_entrypoint_4(f32 *);
extern void _gcdialogcamera_entrypoint_5(f32 *);
extern void func_800F5A00(void *, f32 *);
extern void func_800F8418(void *, f32 *);
extern s32 func_800E8B74(s32);
extern void func_800E8D5C();
extern void func_800E8DB0();
extern void func_800E8D28(u8, f32);
extern int func_800DC298(f32);
extern void func_800EF934(f32 *, f32 *, f32);
extern void func_800BA994();
extern s32 func_80101E14(Actor *, f32);
extern void func_80102FDC(Actor *, f32);
extern u8 D_80809DB8_chdiggerboss[20];
extern u8 D_80809DCC_chdiggerboss[24];
extern u8 D_80809DE4_chdiggerboss[24];
extern u8 D_80809DFC_chdiggerboss[20];
extern u8 D_80809E10_chdiggerboss[20];
extern u8 D_80809E24_chdiggerboss[];
extern u8 D_80809E38_chdiggerboss[];
typedef struct { u8 pad_0[0x70]; u32 pad_1 : 28; u32 field_3 : 1; u32 pad_2 : 3; } DiggerExpressionFlags;
typedef struct { u8 pad_0[0x7C]; u32 a : 19; u32 f : 1; u32 b : 12; } DB7C;
extern s32 B_8080A300_chdiggerboss;
typedef struct { u8 pad_0[12]; f32 local_0; f32 local_1; } DiggerCameraData;
extern void func_800CE8D8(s32, f32, s32);
extern void _chdiggerboss_entrypoint_2();
extern u8 D_80809F98_chdiggerboss[];
extern void func_800C31DC(u8, f32);
extern s32 D_80809FB0_chdiggerboss[];
extern s32 D_80809FC0_chdiggerboss[];
extern s32 D_80809FD0_chdiggerboss[];
extern void func_800C4B64(f32);
extern u8 _subaddieaudioloop_entrypoint_7(u8, f32 *, s32, void *, s32);
extern u8 D_8080A028_chdiggerboss[];
extern f32 func_800F15F8(f32, f32, f32);
extern s32 func_800F6438(s32);
extern s32 func_800F6478(s32);
extern u32 func_800F581C(s32);
extern void func_800F018C(f32 *, f32 *, f32 *, f32 *);
extern void func_800F7A2C(s32, s32, f32 *);
typedef struct { u32 pad : 27; u32 f : 4; u32 b : 1; } DB18;
typedef struct { u32 pad : 23; u32 g : 8; u32 b : 1; } DB28;
typedef struct { u16 pad : 7; u16 g : 8; u16 b : 1; } DB28h;
extern u8 D_8080A068_chdiggerboss[];
extern s32 D_8080A0B4_chdiggerboss[];
extern void func_800EFD24(f32 *);
extern f32 func_800EEAA4(f32 *, f32 *);
extern f32 func_800EFC7C(f32 *, void *);
extern void func_8010B990(void *, s32);
extern void func_800D2498(s32, s32, s32);
extern void func_80109FE8(void *, s32);
extern s32 func_80101DDC(void *);
extern void func_80108B04(void *, s32);
extern s32 _subaddieskeleton_entrypoint_0(void *, s32, void *);
extern void func_8010108C(void *, s32, s32);
extern s32 _subaddiefind_entrypoint_2(s32, s32);
extern s32 _plsu_entrypoint_1(s32);
extern void func_800F7B9C(s32, s32);
typedef struct { u32 pad_0; u8 local_0; u8 pad_1[0x57]; u8 local_1; u8 pad_2[2]; u8 local_2; f32 local_3; } DiggerPlayerCommand;
typedef struct { u8 pad_0[0x7C]; s16 local_0; s16 local_1; u8 pad_1[4]; f32 local_2; u8 pad_2[2]; s16 local_3; s16 local_4; u8 pad_3[2]; f32 local_5; s16 local_6; s16 local_7; } DiggerProjectileState;
extern u8 D_8080A140_chdiggerboss[];
extern void func_8010D09C(s32, f32 *, f32);
extern f32 func_800EEFD4(f32 *);
extern void func_800EF368(f32 *, f32);
extern Actor *func_80108528(s32, f32 *, s32, Actor **);
typedef struct { u8 pad0[0x98]; f32 unk98; f32 unk9C; s16 unkA0; u8 unkA2; u8 unkA3; } DiggerBossData;

extern s32 func_800F64A4(s32, s32);
extern s32 func_8010CFBC(f32 *, s32, s32);
extern void func_800FE850(void);
extern void _gcgoto_entrypoint_1(s32, s32);
extern u8 D_8080A150_chdiggerboss[];
extern f32 func_8001395C(f32);
extern void func_800F4F34(s32, f32 *, f32, f32);
extern void func_800B4470(f32 *, s32, void *, s32, f32, f32, s32, s32, s32);
extern void func_800C4104(s32, f32, s32, f32 *, f32, f32);
extern u8 D_8080A154_chdiggerboss[];
extern f32 func_80101F24(Actor *);
extern void func_8010105C(f32);
extern f32 func_800EEAD4(f32 *, f32 *);
int func_80802158_chdiggerboss();
s32 func_80802170_chdiggerboss();
int func_80802228_chdiggerboss();
s32 func_808027F4_chdiggerboss();
void func_80802878_chdiggerboss();
void func_80802938_chdiggerboss();
void func_80802C40_chdiggerboss();
s32 func_80803424_chdiggerboss();
u8 func_80803524_chdiggerboss();
void func_80803558_chdiggerboss();
int func_80803660_chdiggerboss();
void func_80803BE8_chdiggerboss();
int func_80803DC8_chdiggerboss();
void func_808040D8_chdiggerboss();
void func_808042FC_chdiggerboss();
void func_808049A8_chdiggerboss();
s32 func_80804A50_chdiggerboss();
void func_80804C28_chdiggerboss();
void func_80804D44_chdiggerboss();
void func_80804EFC_chdiggerboss();
void func_80804FE4_chdiggerboss();
void func_808053BC_chdiggerboss();
void func_808056B8_chdiggerboss();
void func_808056F8_chdiggerboss();
void func_808057D0_chdiggerboss();
void func_808059CC_chdiggerboss();
void func_80805D64_chdiggerboss();
void func_80806528_chdiggerboss();
int func_8080666C_chdiggerboss();
u8 func_80806F10_chdiggerboss();
void func_80807664_chdiggerboss();
void func_80807698_chdiggerboss();
void func_80807FD8_chdiggerboss();
void func_80808034_chdiggerboss();
void func_808081AC_chdiggerboss();
void func_8080843C_chdiggerboss();
s32 func_808086A8_chdiggerboss();
void func_808087F0_chdiggerboss();
int func_808088CC_chdiggerboss();
void func_80808948_chdiggerboss();
void func_80808BE4_chdiggerboss();
void func_80808C64_chdiggerboss();
void func_80808F44_chdiggerboss();
void func_80809078_chdiggerboss();
int func_80809234_chdiggerboss();
void func_808093F8_chdiggerboss();
void func_80800200_chdiggerboss();
void func_80802298_chdiggerboss();
void func_808029C8_chdiggerboss();
s32 func_80802D00_chdiggerboss();
void func_80802F00_chdiggerboss();
void func_80803E10_chdiggerboss();
void func_80803E84_chdiggerboss();
void func_80804140_chdiggerboss();
void func_808041E4_chdiggerboss();
void func_808047A8_chdiggerboss();
void func_80804AC8_chdiggerboss();
void func_80805448_chdiggerboss();
void func_808058B0_chdiggerboss();
s32 func_80805DF4_chdiggerboss();
s32 func_808066A0_chdiggerboss();
void func_80806B38_chdiggerboss();
void func_80806C08_chdiggerboss();
s32 func_808070B0_chdiggerboss();
void func_80807304_chdiggerboss();
s32 func_8080783C_chdiggerboss();
void func_80807B54_chdiggerboss();
void func_80807E3C_chdiggerboss();
void func_80808258_chdiggerboss();
void func_808089BC_chdiggerboss();
extern void func_80102EC0(), func_80107C2C(), func_80108ED0(), func_80800A4C_chdiggerboss();
extern u8 D_80809D10_chdiggerboss[];

void func_80800000_chdiggerboss(s32 param_0);
void func_80800180_chdiggerboss(Actor *param_0, s32 param_1);
void func_8080041C_chdiggerboss(s32 param_0, s32 param_1);
int chdiggerboss_entrypoint_0();
int chdiggerboss_entrypoint_1();
void func_80800568_chdiggerboss(Actor *param_0, s32 param_1);
void func_808005DC_chdiggerboss(s32 arg0, s32 arg1);
void func_80800618_chdiggerboss(s32 unused, s32 param_1, s32 param_2);
void func_80800650_chdiggerboss(u8 *param_0, s32 param_1);
void func_808006F8_chdiggerboss(u8 **arg0, s32 arg1);
void func_808007E0_chdiggerboss(Actor *param_0, void *param_1);
void func_808008C0_chdiggerboss();
void func_808008F8_chdiggerboss();
s32 func_808019A8_chdiggerboss();
s32 func_80801A04_chdiggerboss(u8 *param_0, s32 param_1, u32 param_2);
void func_80801DE0_chdiggerboss(u8 *param_0);
int func_808021E8_chdiggerboss(s32 param_0, s32 param_1);
s32 func_80802248_chdiggerboss(s32 param_0);
int func_80802288_chdiggerboss(Actor *param_0);
s32 func_80802314_chdiggerboss(void);
s32 func_8080233C_chdiggerboss(s32 param_0);
void func_808023D8_chdiggerboss(Actor *param_0);
void func_80802550_chdiggerboss(s32 arg0);
s32 func_808025D4_chdiggerboss(Actor *param_0, s32 param_1, s32 param_2);
s32 func_808026F8_chdiggerboss();
s32 func_80802718_chdiggerboss(s32 param_0, s32 param_1, s32 param_2);
void func_80802778_chdiggerboss(Actor *param_0, s32 param_1);
void func_8080290C_chdiggerboss();
s32 func_80802AB8_chdiggerboss(Actor *param_0, s32 param_1);
void func_80802BE0_chdiggerboss(s32 param_0, f32 param_1);
void func_80802C0C_chdiggerboss(s32 param_0);
void func_80802CB4_chdiggerboss(s32 param_0);
void func_80802CDC_chdiggerboss();
void func_80802EF8_chdiggerboss(s32 arg0);
void func_80802FEC_chdiggerboss();
void func_80803078_chdiggerboss();
void func_80803224_chdiggerboss(Actor *param_0);
void func_80803338_chdiggerboss();
int func_808033A0_chdiggerboss(s32 param_0, s32 param_1, s32 *param_2);
void chdiggerboss_entrypoint_2(s32 param_0, s32 param_1);
s32 func_80803610_chdiggerboss();
void func_80803694_chdiggerboss();
void func_808039C0_chdiggerboss(s32 param_0, volatile unsigned int param_1, s32 param_2);
u8 func_808042D8_chdiggerboss(s32 param_0);
void func_808043D8_chdiggerboss(s32 *param_0, f32 param_1, u8 *param_2);
void func_80804450_chdiggerboss(Actor *param_0);
s32 func_80804644_chdiggerboss(f32 param_0, f32 param_1, f32 param_2);
void func_80804680_chdiggerboss(Actor *param_0);
void func_80804784_chdiggerboss();
extern void func_808049DC_chdiggerboss(Actor *);
void func_80804A7C_chdiggerboss();
s16 func_80805798_chdiggerboss(s32 unused, s32 param_1);
void func_80805960_chdiggerboss();
void func_808059A4_chdiggerboss();
void func_80805A00_chdiggerboss(Actor *param_0, s32 param_1);
int func_80805A64_chdiggerboss(Actor *param_0);
int func_80805B8C_chdiggerboss(Actor *param_0, f32 param_1);
void func_80805C1C_chdiggerboss(Actor *param_0, f32 *param_1, f32 *param_2, f32 param_3);
void func_808062B8_chdiggerboss(void *param_0);
s32 func_80806300_chdiggerboss(Actor *param_0);
s32 func_808063C8_chdiggerboss(Actor *param_0, s32 param_1, f32 param_2);
void func_808064CC_chdiggerboss();
void func_80806648_chdiggerboss();
void func_80806A78_chdiggerboss();
void func_80806CA4_chdiggerboss(s32 param_0, s32 param_1);
void func_80806CF8_chdiggerboss(Actor *param_0, s32 param_1);
s32 func_80806D84_chdiggerboss(s32 param_0);
void func_80806DC4_chdiggerboss(Actor *param_0, u8 *param_1);
void func_80806EE4_chdiggerboss(s32 unused, s32 param_1);
void func_80806F8C_chdiggerboss(Actor *param_0);
void func_80807280_chdiggerboss();
s16 func_8080761C_chdiggerboss(s32 param_0);
void func_80807640_chdiggerboss();
void func_80807754_chdiggerboss(Actor *param_0, s32 param_1, f32 param_2);
void func_80807B18_chdiggerboss();
void func_80807B4C_chdiggerboss(s32 arg0);
void func_80807DC0_chdiggerboss(s32 param_0, s32 param_1);
int func_80807DF4_chdiggerboss(s32 param_0);
void func_80808000_chdiggerboss();
void func_808080C0_chdiggerboss(Actor *param_0, s32 param_1);
void func_8080815C_chdiggerboss();
void func_80808470_chdiggerboss(Actor *param_0, s32 param_1);
DiggerPhase59 * func_80808560_chdiggerboss(Actor *param_0);
int func_808085E0_chdiggerboss(s32 param_0, s32 param_1);
void func_808086E8_chdiggerboss(u8 *param_0, u8 *param_1);
void func_808088AC_chdiggerboss(s32 arg0);
void func_80808B40_chdiggerboss(Actor *param_0, s32 param_1);
void func_80808CD0_chdiggerboss();
void func_80808D54_chdiggerboss(Actor *param_0, s32 param_1, f32 param_2, f32 *param_3);
void chdiggerboss_entrypoint_3(s32 param_0, VertexShiftRecord *param_1, VertexShiftRecord *param_2, s32 param_3, Unk80132ED0 *param_4);
void func_80809150_chdiggerboss(s32 param_0);
s32 func_808091E4_chdiggerboss(Actor *this);
void func_80809310_chdiggerboss(Actor *param_0);
extern int D_80809E8C_chdiggerboss[];
extern u8 D_80809C60_chdiggerboss[];
extern u8 D_80809C70_chdiggerboss[];
extern u8 D_80809C80_chdiggerboss[];
extern u8 D_80809C90_chdiggerboss[];
extern u8 D_80809CA0_chdiggerboss[];
extern u8 D_80809CB0_chdiggerboss[];
extern u8 D_80809CC0_chdiggerboss[];
extern u8 D_80809CD0_chdiggerboss[];
extern u8 D_80809CE0_chdiggerboss[];
extern u8 D_80809CF0_chdiggerboss[];
extern u8 D_80809D00_chdiggerboss[];
void func_80800000_chdiggerboss(s32 param_0)
{
    switch (func_801022E4())
    {
    case 0x435:
        _subaddieaudioquick_entrypoint_3(param_0, param_0 + 4, &D_80809DB8_chdiggerboss, 0.300000012f);
        _subaddieaudioquick_entrypoint_3(param_0, param_0 + 4, &D_80809DCC_chdiggerboss, 0.800000012f);
        return;
    case 0x43B:
        _subaddieaudioquick_entrypoint_3(param_0, param_0 + 4, &D_80809DB8_chdiggerboss, 0.5f);
        _subaddieaudioquick_entrypoint_3(param_0, param_0 + 4, &D_80809DCC_chdiggerboss, 0.850000024f);
        return;
    case 0x436:
        if (func_80101DDC(param_0) != 0)
        {
            func_80800180_chdiggerboss(param_0, 5);
            return;
        }
        break;
    case 0x437:
        _subaddieaudioquick_entrypoint_3(param_0, param_0 + 4, &D_80809DE4_chdiggerboss, 0.600000024f);
        return;
    case 0x440:
        _subaddieaudioquick_entrypoint_3(param_0, param_0 + 4, &D_80809DFC_chdiggerboss, 0.600000024f);
        _subaddieaudioquick_entrypoint_3(param_0, param_0 + 4, &D_80809E10_chdiggerboss, 0.850000024f);
        if (func_80101E14(param_0, 0.5f) != 0)
        {
            *(s8 *)((u8 *)func_80100094(func_80802228_chdiggerboss(param_0), 0) + 7) = 1;
        }
        break;
    }
}

void func_80800180_chdiggerboss(Actor *param_0, s32 param_1)
{
    func_80102424(param_0, param_1);
    if (func_801022E4(param_0) != 0) {
        param_0->unk64_16 = 1;
    } else {
        param_0->unk64_16 = 0;
    }
    if (param_0->unk3C != NULL) {
        func_808008C0_chdiggerboss(func_80802228_chdiggerboss(param_0), 5,
            (*(u16 *)((u8 *)param_0 + 0x64) & 1) == 0);
    }
}


void func_80800200_chdiggerboss(param_0) Actor *param_0;
{

    u8 *local_0;
    s32 local_3;
    u8 *local_1;

    local_0 = func_80100094(param_0, 0);
    switch (func_801022E4(param_0)) {
    case 0x42D:
        local_3 = func_80102320(param_0, 0.2f, 0.9f);
        local_1 = (u8 *)param_0 + 4;
        *(u8 *)((char *)local_0 + 0xA0) = _subaddieaudioloop_entrypoint_7(*(u8 *)((char *)local_0 + 0xA0), local_1, local_3, D_80809E24_chdiggerboss, (*(s32 *)((char *)param_0 + 0x70)) & 1);
        _subaddieaudioquick_entrypoint_3(param_0, local_1, D_80809E38_chdiggerboss, 0.85f);
        if (func_80101DDC(param_0) != 0) {
            func_808008C0_chdiggerboss(param_0, 1, 0);
            func_808008C0_chdiggerboss(param_0, 2, 0);
            func_8080041C_chdiggerboss(param_0, 0x13);
            return;
        }
        break;
    case 0x42E:
        if (func_80101DDC(param_0) != 0) {
            *(u8 *)((char *)local_0 + 6) = 1;
            func_8080041C_chdiggerboss(param_0, 1);
            func_808041E4_chdiggerboss(param_0, 1);
            return;
        }
        break;
    case 0x429:
    case 0x42B:
        local_3 = func_80102320(param_0, 0.0f, 0.6f);
        local_1 = (u8 *)param_0 + 4;
        *(u8 *)((char *)local_0 + 0xA0) = _subaddieaudioloop_entrypoint_7(*(u8 *)((char *)local_0 + 0xA0), local_1, local_3, D_80809E24_chdiggerboss, (*(s32 *)((char *)param_0 + 0x70)) & 1);
        _subaddieaudioquick_entrypoint_3(param_0, local_1, D_80809E38_chdiggerboss, 0.65f);
        return;
    case 0x42F:
        local_1 = (u8 *)param_0 + 4;
        _subaddieaudioquick_entrypoint_3(param_0, local_1, ((u8 *) D_80809DB8_chdiggerboss), 0.3f);
        _subaddieaudioquick_entrypoint_3(param_0, local_1, ((u8 *) D_80809DCC_chdiggerboss), 0.8f);
        if (func_80101DDC(param_0) != 0) {
            *(u8 *)((char *)local_0 + 5) = 1;
            func_8080041C_chdiggerboss(param_0, 1);
            func_80807DC0_chdiggerboss(func_808026F8_chdiggerboss(param_0), 1);
        }
        break;
    default:
        break;
    }
}

void func_8080041C_chdiggerboss(s32 param_0, s32 param_1) {
    s32 local_1;
    u8 *local_0;

    local_0 = func_80100094(func_808026F8_chdiggerboss(), 0);
    func_80102424(param_0, param_1);
    local_1 = func_801022E4(param_0);
    switch (local_1) {                              
    case 0x429:
        func_808008C0_chdiggerboss(param_0, 3, 1);
        func_808008C0_chdiggerboss(param_0, 1, 1);
        return;
    case 0x42B:
        (*(s16 *)((s8 *)(local_0) + (0x80))) = 1;
        func_808008C0_chdiggerboss(param_0, 4, 1);
        func_808008C0_chdiggerboss(param_0, 2, 1);
        return;
    case 0x42D:
        (*(s16 *)((s8 *)(local_0) + (0x80))) = 0;
        return;
    }
}

int chdiggerboss_entrypoint_0()
{
    return (int)&D_80809E44_chdiggerboss;
}

int chdiggerboss_entrypoint_1()
{
    return &D_80809E8C_chdiggerboss;
}

int func_80800508_chdiggerboss(param_0, param_1) s32 param_0; s32 param_1;
{
    s32 local_0;

    local_0 = func_800EB854();
    if (local_0 != 0) {
        if (local_0 == 3) {
            _gcnewoption_entrypoint_1((u8 *)func_80100094(param_0, 0) + 0x10C, param_1);
        }
    } else {
        func_80101808(param_0, &func_801017D0);
    }
}

void func_80800568_chdiggerboss(Actor *param_0, s32 param_1)
{
    u8 *local_0;
    s32 local_1;
    u8 *local_2;

    local_0 = func_80100094(param_0, 0);
    func_801015D0(param_0);
    for (local_1 = 0; local_1 < 1; local_1++) {
        func_800DF744(((s16 *)D_80809EE0_chdiggerboss)[local_1], local_0[local_1 + 0xFC]);
    }
}

void func_808005DC_chdiggerboss(s32 arg0, s32 arg1)
{
  func_80806528_chdiggerboss(arg0, func_800AE6BC(func_801040A8()), arg1);
}

void func_80800618_chdiggerboss(s32 unused, s32 param_1, s32 param_2) {
    s32 local_0;
    local_0 = func_80100094(unused, 0);
    *(s8 *)((s8 *)(local_0 + param_1) + 0xfc) = (s8) param_2;
}

void func_80800650_chdiggerboss(u8 *param_0, s32 param_1)
{
    s32 temp_v0;

    temp_v0 = func_800EB854();
    switch (temp_v0) {
    case 1:
        func_800DF830(0);
        func_800DF410(0xC0);
        func_800DE498(param_1, (s32 *)(param_0 + 4), (s32 *)(param_0 + 0x44), 
                      (*(f32 *)(param_0 + 0x38)), 0, func_800D674C(0x959));
        return;
    case 0:
        func_80101808(param_0, &func_801017D0);
        return;
    case 2:
        func_80804EFC_chdiggerboss(param_0, param_1);
        return;
    }
}

void func_808006F8_chdiggerboss(u8 **arg0, s32 arg1)
{
  s16 *var_s0;
  s32 temp_s1;
  u8 *temp_s2;
  u8 *var_s1;
  temp_s2 = func_80100094(arg0, 0);
  func_801015D0(arg0);
  if (func_801022E4(arg0) == 0)
  {
    temp_s1 = func_800B27E0(arg1);
    func_800AE1E8(*((s16 *) (((char *) (*arg0)) + 0x10)), temp_s1, func_801040D0());
    func_800DF72C(func_801040A8(arg0));
  }
  var_s1 = temp_s2;
 var_s0 = (s16 *) (&D_80809ED4_chdiggerboss); do {
    func_800DF744(*var_s0, *((u8 *) (((char *) var_s1) + 0xE4)));
    var_s0 += 1;
    var_s1 += 1;
  }
  while (((u8 *) var_s0) != ((u8 *) (&D_80809EE0_chdiggerboss)));
  func_800DF744(1, 0);
  func_800DF744(2, 0);
  func_800DF744(3, 0);
  func_800DF744(4, 0);
}

void func_808007E0_chdiggerboss(Actor *param_0, void *param_1)
{
    u8 *local_0;
    void *local_1;

    local_0 = (u8 *)func_80100094(param_0, 0);
    local_1 = func_8010262C(param_0->unk0, 12);
    func_808042FC_chdiggerboss(param_0, local_1, param_1);
    func_80804A7C_chdiggerboss(param_0, local_1, param_1);
    func_80809078_chdiggerboss(param_0, local_1, param_1);
    if (local_0[5]) func_800E0AFC(local_1, 0x52, 1.0f, -129.0f, 0.0f, 0.0f);
    if (local_0[6]) func_800E0C20(local_1, 0x50, 1.0f, 0.0f, 0.5f, 0.0f);
}

void func_808008C0_chdiggerboss(unused, param_1, param_2) s32 unused; s32 param_1; s32 param_2; {
    s32 local_0;
    local_0 = func_80100094(unused, 0);
    *(s8 *)((s8 *)(local_0 + param_1) + 0xe4) = (s8) param_2;
}

void func_808008F8_chdiggerboss(param_0) Actor *param_0; {
    s32 local_0;
    s32 local_1;
    s32 local_2;
    u8 *local_3;

    local_0 = func_800EA05C();
    if (func_800DA298('C') != 0) {
        func_800FFAB0(param_0);
        return;
    }
    if ((local_0 == 0x15D) && (func_800EA090() != 6)) {
        func_800FFAB0(param_0);
        return;
    }
    local_0 = 0;
    do {
        local_1 = func_80802158_chdiggerboss(param_0, local_0);
        if ((local_1 != 0) && (func_800DA298(local_1) != 0)) {
            func_80802170_chdiggerboss(param_0, local_0);
        }
        local_0 += 1;
    } while (local_0 != 0xF);
    *(u8 *)((char *)(param_0) + 0x75) = (u8) (*(u8 *)((char *)(param_0) + 0x75) & 0xFFFD);
    local_3 = func_80100074(param_0, 0, _gcnewoption_entrypoint_2() + 0x10C);
    func_80109FE8(param_0, 0);
    func_80109EEC(param_0, 0x40);
    func_80102FDC(param_0, 0.25f);
    *(u8 *)((char *)(local_3) + 2) = 0x64;
    func_8010A828(param_0, 1);
    func_80803BE8_chdiggerboss(param_0, 1, 1);
    func_80802CDC_chdiggerboss(param_0);
    func_80802BE0_chdiggerboss(param_0, 1.0f);
    func_800DA524(0xA4F);
    func_800DA524(0xA50);
}



void func_80800A4C_chdiggerboss(param_0) Actor *param_0;
{

    char *local_0;
    void *local_1;
    void *local_2;
    void *local_3;
    void *local_4;
    void *local_5;
    s32 local_6;
    void *local_7;
    void *local_8;
    void *local_9;

    local_0 = (char *)func_80100094(param_0, 0);

    func_80800000_chdiggerboss(param_0);
    func_80806300_chdiggerboss(param_0);
    func_80807B54_chdiggerboss(param_0);

    switch (*(s16 *)local_0) {
        case 2:
            if (func_80101DDC(param_0)) {
                func_80803660_chdiggerboss(param_0, 0x171E, 0x10E);
                func_80803BE8_chdiggerboss(param_0, 3, 8);
            }
            break;

        case 4:
            if (func_80101DDC(param_0)) {
                if (!func_80802170_chdiggerboss(param_0, 0)) {
                    func_80803BE8_chdiggerboss(param_0, 5, 1);
                    func_8080290C_chdiggerboss(param_0, 0x2D, 0x20);
                    func_80803660_chdiggerboss(param_0, 0x1720, 0x14C);
                } else {
                    func_800FDC28(0x14);
                    func_80805A00_chdiggerboss(param_0, 6);
                }
            }
            break;

        case 6:
            if (func_80805A64_chdiggerboss(param_0)) {
                func_80802F00_chdiggerboss(param_0, 7);
            }
            break;

        case 7:
            if (func_80101DDC(param_0)) {
                if (!func_80802170_chdiggerboss(param_0, 1)) {
                    func_80803BE8_chdiggerboss(param_0, 8, 5);
                    func_80803660_chdiggerboss(param_0, 0x172E, 0x10E);
                } else {
                    func_80802FEC_chdiggerboss(param_0, 9, 0);
                }
            }
            break;

        case 9:
            if (func_80802D00_chdiggerboss(param_0)) {
                func_80806A78_chdiggerboss(param_0, 0xA, D_80809C60_chdiggerboss);
            }
            break;

        case 10:
            switch (func_808066A0_chdiggerboss(param_0)) {
            case 1:
                func_80802878_chdiggerboss(param_0, 3, 1);
                func_80803BE8_chdiggerboss(param_0, 0xB, 3);
                break;
            case 2:
                func_80803BE8_chdiggerboss(param_0, 8, 8);
                func_80802878_chdiggerboss(param_0, 3, 1);
                func_80803660_chdiggerboss(param_0, 0x1731, 0x10E);
                break;
            }
            break;

        case 11:
            if (func_80101DDC(param_0)) {
                func_80805A00_chdiggerboss(param_0, 6);
            }
            break;

        case 12:
            if (func_80101DDC(param_0)) {
                if (!func_80802170_chdiggerboss(param_0, 5)) {
                    func_80803BE8_chdiggerboss(param_0, 0xD, 1);
                    func_8080290C_chdiggerboss(param_0, 0x30, 0x20);
                    func_80803660_chdiggerboss(param_0, 0x1721, 0x14C);
                } else {
                    func_80805A00_chdiggerboss(param_0, 0xE);
                }
            }
            break;

        case 14:
            if (func_80805A64_chdiggerboss(param_0)) {
                func_80802F00_chdiggerboss(param_0, 0xF);
            }
            break;

        case 15:
            if (func_80101DDC(param_0)) {
                func_80802FEC_chdiggerboss(param_0, 0x11, 0);
            }
            break;

        case 17:
            if (func_80802D00_chdiggerboss(param_0)) {
                func_80806A78_chdiggerboss(param_0, 0x12, D_80809C70_chdiggerboss);
            }
            break;

        case 18:
            switch (func_808066A0_chdiggerboss(param_0)) {
            case 1:
                func_80802878_chdiggerboss(param_0, 3, 1);
                func_80803BE8_chdiggerboss(param_0, 0x13, 3);
                break;
            case 2:
                func_80803BE8_chdiggerboss(param_0, 0x10, 8);
                func_80802878_chdiggerboss(param_0, 3, 1);
                func_80803660_chdiggerboss(param_0, 0x1732, 0x10E);
                break;
            }
            break;

        case 19:
            if (func_80101DDC(param_0)) {
                func_80805A00_chdiggerboss(param_0, 0xE);
            }
            break;

        case 20:
            if (func_80101DDC(param_0)) {
                if (!func_80802170_chdiggerboss(param_0, 6)) {
                    func_80803BE8_chdiggerboss(param_0, 0x15, 1);
                    func_8080290C_chdiggerboss(param_0, 0x33, 0x20);
                    func_80803660_chdiggerboss(param_0, 0x1723, 0x14C);
                } else {
                    local_1 = (void *)func_80802228_chdiggerboss(param_0);

                    func_8080041C_chdiggerboss(local_1, 0xE);
                    func_80807280_chdiggerboss(param_0, 0x16, D_80809CF0_chdiggerboss);
                }
            }
            break;

        case 22:
            if (func_808070B0_chdiggerboss(param_0)) {
                func_80802F00_chdiggerboss(param_0, 0x17);
            }
            break;

        case 23:
            if (func_80101DDC(param_0)) {
                func_80802FEC_chdiggerboss(param_0, 0x19, 1);
            }
            break;

        case 25:
            if (func_80802D00_chdiggerboss(param_0)) {
                func_80806A78_chdiggerboss(param_0, 0x1A, D_80809C80_chdiggerboss);
            }
            break;

        case 26:
            switch (func_808066A0_chdiggerboss(param_0)) {
            case 1:
                func_80802878_chdiggerboss(param_0, 3, 1);
                func_80803BE8_chdiggerboss(param_0, 0x1B, 3);
                break;
            case 2:
                func_80802878_chdiggerboss(param_0, 3, 1);
                func_80803BE8_chdiggerboss(param_0, 0x1C, 3);
                break;
            }
            break;

        case 27:
            if (func_80101DDC(param_0)) {
                func_80807280_chdiggerboss(param_0, 0x16, D_80809CF0_chdiggerboss);
            }
            break;

        case 28:
            if (func_80101DDC(param_0)) {
                if (!func_80802170_chdiggerboss(param_0, 7)) {
                    func_80803BE8_chdiggerboss(param_0, 0x1D, 1);
                    func_8080290C_chdiggerboss(param_0, 0x37, 0x20);
                    func_80803660_chdiggerboss(param_0, 0x1724, 0x14C);

                    local_2 = (void *)func_80802228_chdiggerboss(param_0);

                    func_808008C0_chdiggerboss(local_2, 3, 1);
                } else {
                    local_2 = (void *)func_80802228_chdiggerboss(param_0);

                    func_8080041C_chdiggerboss(local_2, 0x10);
                    func_80807280_chdiggerboss(param_0, 0x1E, D_80809D00_chdiggerboss);
                }
            }
            break;

        case 30:
            if (func_808070B0_chdiggerboss(param_0)) {
                func_80802F00_chdiggerboss(param_0, 0x1F);
            }
            break;

        case 31:
            if (func_80101DDC(param_0)) {
                func_80802FEC_chdiggerboss(param_0, 0x21, 1);
            }
            break;

        case 33:
            if (func_80802D00_chdiggerboss(param_0)) {
                func_80806A78_chdiggerboss(param_0, 0x22, D_80809C90_chdiggerboss);
            }
            break;

        case 34:
            switch (func_808066A0_chdiggerboss(param_0)) {
            case 1:
                func_80802878_chdiggerboss(param_0, 3, 1);
                func_80803BE8_chdiggerboss(param_0, 0x23, 3);
                break;
            case 2:
                func_80802878_chdiggerboss(param_0, 3, 1);
                func_80803BE8_chdiggerboss(param_0, 0x24, 3);
                break;
            }
            break;

        case 35:
            if (func_80101DDC(param_0)) {
                func_80807280_chdiggerboss(param_0, 0x1E, D_80809D00_chdiggerboss);
            }
            break;

        case 36:
            if (func_80101DDC(param_0)) {
                if (!func_80802170_chdiggerboss(param_0, 8)) {
                    func_80803BE8_chdiggerboss(param_0, 0x25, 1);
                    func_8080290C_chdiggerboss(param_0, 0x36, 0x20);
                    func_80803660_chdiggerboss(param_0, 0x1725, 0x14C);
                } else {
                    local_3 = (void *)func_80802228_chdiggerboss(param_0);

                    func_8080041C_chdiggerboss(local_3, 0x12);

                    func_80803BE8_chdiggerboss(param_0, 0x26, 1);

                    func_808027F4_chdiggerboss(param_0);
                }
            }
            break;

        case 38:
            local_4 = (void *)func_80802228_chdiggerboss(param_0);

            if (func_801022E4(local_4) == 0) {
                func_80805448_chdiggerboss(local_4, 0, 1);
                func_80805448_chdiggerboss(local_4, 3, 1);
                func_80805D64_chdiggerboss(param_0, 0x27);
            }
            break;

        case 39:
            if (func_80805DF4_chdiggerboss(param_0)) {
                if (*(u8 *)(local_0 + 2) != 0x32) {
                    func_80802F00_chdiggerboss(param_0, 0x28);
                } else {
                    func_80807754_chdiggerboss(param_0, 0x2D, 10.0f);
                }
            }
            break;

        case 40:
            if (func_80101DDC(param_0)) {
                func_80802FEC_chdiggerboss(param_0, 0x2A, 2);
            }
            break;

        case 42:
            if (func_80802D00_chdiggerboss(param_0)) {
                func_80806A78_chdiggerboss(param_0, 0x2B, D_80809CA0_chdiggerboss);
            }
            break;

        case 43:
            if (func_808066A0_chdiggerboss(param_0)) {
                func_80802878_chdiggerboss(param_0, 3, 1);
                func_80803BE8_chdiggerboss(param_0, 0x2C, 3);
            }
            break;

        case 44:
            if (func_80101DDC(param_0)) {
                func_80807754_chdiggerboss(param_0, 0x2D, 10.0f);

                if (!func_80802170_chdiggerboss(param_0, 9)) {
                    func_80803660_chdiggerboss(param_0, 0x1727, 0x106);
                }
            }
            break;

        case 45:
            func_8080783C_chdiggerboss(param_0, 0x27);
            break;

        case 46:
            if (func_80101DDC(param_0)) {
                func_800F82D4(func_800F54E4(), 0);

                func_80803660_chdiggerboss(param_0, 0x1733, 0x10E);
                func_80803BE8_chdiggerboss(param_0, 0x30, 8);
            }
            break;

        case 47:
            if (func_80101DDC(param_0)) {
                func_80805D64_chdiggerboss(param_0, 0x31);
            }
            break;

        case 49:
            if (func_80805DF4_chdiggerboss(param_0)) {
                if (*(u8 *)(local_0 + 2) != 0x28) {
                    func_80802F00_chdiggerboss(param_0, 0x32);
                } else {
                    func_80807754_chdiggerboss(param_0, 0x37, 8.0f);
                }
            }
            break;

        case 50:
            if (func_80101DDC(param_0)) {
                func_80802FEC_chdiggerboss(param_0, 0x34, 2);
            }
            break;

        case 51:
            if (func_80802D00_chdiggerboss(param_0)) {
                func_80806A78_chdiggerboss(param_0, 0x35, D_80809CB0_chdiggerboss);
            }
            break;

        case 52:
            if (func_80802D00_chdiggerboss(param_0)) {
                func_80806A78_chdiggerboss(param_0, 0x35, D_80809CB0_chdiggerboss);
            }
            break;

        case 53:
            if (func_808066A0_chdiggerboss(param_0)) {
                func_80802878_chdiggerboss(param_0, 3, 1);
                func_80803BE8_chdiggerboss(param_0, 0x36, 3);
            }
            break;

        case 54:
            if (func_80101DDC(param_0)) {
                func_80807754_chdiggerboss(param_0, 0x37, 8.0f);
            }
            break;

        case 55:
            func_8080783C_chdiggerboss(param_0, 0x31);
            break;

        case 56:
            if (func_80101DDC(param_0)) {
                func_800F82D4(func_800F54E4(), 0);

                if (!func_80802170_chdiggerboss(param_0, 0xC)) {
                    func_8080290C_chdiggerboss(param_0, 0x3C, 0x20);
                    func_80803660_chdiggerboss(param_0, 0x1734, 0x14C);
                } else {
                    local_5 = (void *)func_80802228_chdiggerboss(param_0);

                    func_80804A50_chdiggerboss(local_5, 0);

                    local_6 = 0;
                    do {
                        func_80805448_chdiggerboss(local_5, local_6, 2);
                        local_6++;
                    } while (local_6 != 4);

                    func_808041E4_chdiggerboss(local_5, 4);

                    func_80802878_chdiggerboss(param_0, 3, 1);

                    func_80803660_chdiggerboss(param_0, 0x1729, 0x10E);
                }

                func_80803BE8_chdiggerboss(param_0, 0x39, 8);
            }
            break;

        case 58:
            switch (func_808066A0_chdiggerboss(param_0)) {
            case 1:
                func_80806A78_chdiggerboss(param_0, 0x3A, D_80809CC0_chdiggerboss);
                break;
            case 2:
                func_80803BE8_chdiggerboss(param_0, 0x3B, 8);

                if (!func_80802170_chdiggerboss(param_0, 0xD)) {
                    func_8080290C_chdiggerboss(param_0, 0x40, 0x20);
                    func_80803660_chdiggerboss(param_0, 0x172A, 0x14C);
                } else {
                    local_7 = (void *)func_80802228_chdiggerboss(param_0);

                    func_8080041C_chdiggerboss(local_7, 0x14);

                    func_80806A78_chdiggerboss(param_0, 0x3C, D_80809CD0_chdiggerboss);

                    func_80806EE4_chdiggerboss(param_0, 1);
                }
                break;
            }
            break;

        case 60:
            switch (func_808066A0_chdiggerboss(param_0)) {
            case 1:
                func_80806A78_chdiggerboss(param_0, 0x3C, D_80809CD0_chdiggerboss);
                break;
            case 2:
                if (!func_80802170_chdiggerboss(param_0, 0xE)) {
                    func_80803BE8_chdiggerboss(param_0, 0x3D, 8);
                    func_8080290C_chdiggerboss(param_0, 0x44, 0x20);
                    func_80803660_chdiggerboss(param_0, 0x172B, 0x14C);
                } else {
                    local_8 = (void *)func_80802228_chdiggerboss(param_0);

                    func_80806A78_chdiggerboss(param_0, 0x3E, D_80809CE0_chdiggerboss);

                    func_80806EE4_chdiggerboss(param_0, 1);
                    func_80807DC0_chdiggerboss(param_0, 2);
                    func_808080C0_chdiggerboss(local_8, 2);
                }
                break;
            }
            break;

        case 62:
            switch (func_808066A0_chdiggerboss(param_0)) {
            case 1:
                func_80806A78_chdiggerboss(param_0, 0x3E, D_80809CE0_chdiggerboss);
                break;
            case 2:
                func_808080C0_chdiggerboss(func_80802228_chdiggerboss(param_0), 0);

                func_80807DF4_chdiggerboss(param_0);

                if (!func_808021E8_chdiggerboss(param_0, 0xB)) {
                    func_80803BE8_chdiggerboss(param_0, 0x3F, 8);
                    func_80802BE0_chdiggerboss(param_0, 3.0f);
                    func_80802878_chdiggerboss(param_0, 3, 1);
                    func_80803660_chdiggerboss(param_0, 0x172C, 0x10E);
                } else {
                    func_80802BE0_chdiggerboss(param_0, 1.0f);

                    *(u8 *)(local_0 + 0xCD) = 1;

                    func_80808470_chdiggerboss(param_0, 0x40);
                }
                break;
            }
            break;

        case 64:
            func_80808258_chdiggerboss(param_0);
            break;

        case 65:
            if (func_80101DDC(param_0)) {
                func_80803BE8_chdiggerboss(param_0, 0x42, 1);
            }
            break;

        case 67:
            if (!func_808091E4_chdiggerboss(param_0)) {
                func_80802878_chdiggerboss(param_0, 5, 1);

                func_80803BE8_chdiggerboss(param_0, 0x44, -1);

                *(f32 *)(local_0 + 0xF8) = 0.4f;
            }
            break;

        case 68:
            if (func_800D9078(local_0 + 0xF8)) {
                local_9 = (void *)func_80802248_chdiggerboss(param_0);

                func_800F7B9C(local_9, 0x63);
                func_800F7C58(local_9, 0x61, 2);

                func_80803BE8_chdiggerboss(param_0, 0x45, -1);

                *(f32 *)(local_0 + 0xF8) = 1.0f;
            }
            break;

        case 69:
            if (func_800D9078(local_0 + 0xF8)) {
                if (func_800D395C()) {
                    func_800FDC28(0);
                    _gcfrontend_entrypoint_10();
                } else {
                    func_80803660_chdiggerboss(param_0, 0x14D8, 0x10E);

                    func_80803BE8_chdiggerboss(param_0, 0x46, -1);
                }
            }
            break;

        case 71:
            if (func_80101DDC(param_0)) {
                func_80803BE8_chdiggerboss(param_0, 0x48, 8);

                if (func_800D395C()) {
                    func_80803660_chdiggerboss(param_0, 0xCEB, 0x144);
                }
            }
            break;
        case 72:
            break;
    }

    if (((DiggerExpressionFlags *)param_0)->field_3) {
        _suexpression_entrypoint_10(func_80100094(param_0, 1), *(s32 *)param_0, 0);
    }
}


s32 func_808019A8_chdiggerboss(param_0) s32 param_0; {
    func_808027F4_chdiggerboss(param_0);
    func_80802EF8_chdiggerboss(param_0);
    func_80807B4C_chdiggerboss(param_0);
    func_8080666C_chdiggerboss(param_0);
    func_808059CC_chdiggerboss(param_0);
    func_8080843C_chdiggerboss(param_0);
    _suexpression_entrypoint_8(param_0, 1);
}




s32 func_80801A04_chdiggerboss(u8 *param_0, s32 param_1, u32 param_2) {
    s32 *local_5;
    s32 local_x;
    s32 local_v;
    s32 local_i;
    f32 local_vec[3];

    switch (param_1) {
    case 0x49:
        local_5 = (s32 *)func_801084B0(0x203, (u32 **)&param_0);
        *(s32 *)(param_0 + 0x3C) = *local_5;
        *(s32 *)((u8 *)local_5 + 0x3C) = *(s32 *)param_0;
        break;
    case 0x57:
        return func_80802718_chdiggerboss(param_0, *(s32 *)&param_2 & 0xFFFF, (param_2 & 0xFFFF0000) >> 16);
    case 0x20:
        func_80803078_chdiggerboss(param_0, func_80101080(), ((s16 *)&param_2)[0], ((s16 *)&param_2)[1]);
        return 1;
    case 0x95:
        func_80801DE0_chdiggerboss(param_0);
        return 1;
    case 0xB:
        return func_80802AB8_chdiggerboss(param_0, param_2);
    case 0x2E:
        func_80803694_chdiggerboss(param_0, ((s16 *)&param_2)[0], ((s16 *)&param_2)[1]);
        return 1;
    case 0x2F:
        func_808039C0_chdiggerboss(param_0, ((s16 *)&param_2)[0], ((s16 *)&param_2)[1]);
        return 1;
    case 0x52:
        func_808029C8_chdiggerboss(param_0);
        return 1;
    case 0x1F:
        func_80800568_chdiggerboss(param_0, *(u32 *)&param_2);
        return 1;
    case 0x9C:
        func_808005DC_chdiggerboss(param_0, *(u32 *)&param_2);
        return 1;
    case 0x40:
        if (((u8 *)func_80100094(param_0, 0))[3] != 0) {
            func_808086E8_chdiggerboss(param_0, *(u32 *)&param_2);
        } else {
            func_80806DC4_chdiggerboss(param_0, *(u32 *)&param_2);
            }
        return 1;
    case 0x3D:
        switch (param_2) {
        case 0:
            func_80806CF8_chdiggerboss(param_0, param_2);
            return 1;
        case 1:
        case 2:
            func_80807304_chdiggerboss(param_0, param_2);
            return 1;
        case 4:
            func_80807E3C_chdiggerboss(param_0, param_2);
            return 1;
        case 5:
            func_808085E0_chdiggerboss(param_0, param_2);
            return 1;
        }
        break;
    case 0x96:
        if (func_800D395C() == 0) {
            return 0;
        }
        func_80803660_chdiggerboss(param_0, 0xCEB, 0x46);
        return 1;
    case 0x9F:
        local_v = func_80802228_chdiggerboss(param_0);
        local_i = 0;
        do {
            func_80805448_chdiggerboss(local_v, local_i, 0);
            local_i++;
        } while (local_i != 4);
        func_800FDC28(0);
        func_80800618_chdiggerboss(param_0, 0, 0);
        if (func_80802288_chdiggerboss(param_0) != 0) {
            func_800D395C();
            func_80803BE8_chdiggerboss(param_0, 0x48, 8);
        } else {
            func_80803BE8_chdiggerboss(param_0, 0x47, 2);
        }
        return 1;
    case 0x29:
        _suexpression_entrypoint_7(param_0, 1, 0x22);
        return 1;
    case 0x2A:
        _suexpression_entrypoint_8(param_0, 1);
        return 1;
    case 0xA2:
        if (!((DB7C *)param_0)->f || func_80802288_chdiggerboss(param_0) == 0) {
            return 0;
        }
        func_80802298_chdiggerboss(param_0, &B_8080A300_chdiggerboss);
        func_80101074(&B_8080A300_chdiggerboss);
        return 1;
    case 0x90:
        func_80809310_chdiggerboss(param_0);
        return 1;
    case 0x8D:
        func_800EE7F8(local_vec, param_0 + 4);
        local_vec[1] += 250.0f;
        func_80101010(local_vec);
        return 1;
    case 0xB5:
        func_80806CA4_chdiggerboss(param_0, param_2);
        return 1;
    default:
        return 0;
    }
    return 1;
}

void func_80801DE0_chdiggerboss(u8 *param_0) {
    u8 *local_0;
    u8 *local_1;
    u8 *local_2;
    s32 local_3;
    s32 local_4;
    s16 local_5;
    s32 local_6;
    u8 *local_7;

    local_0 = func_80100094(param_0, 0);
    func_80109FE8(param_0, 0);
    func_80807B18_chdiggerboss(param_0);
    func_80806648_chdiggerboss(param_0);
    func_808059A4_chdiggerboss(param_0);
    if ((*(s16 *)((s8 *)(local_0) + (0xA0))) == 0) {
        local_6 = func_800EA05C();
        switch (local_6) {                          
        case 0x15D:                                 
            if (func_800DA298(0x44) == 0) {
                func_8080290C_chdiggerboss(param_0, 0x1C, 0x20);
                func_80803660_chdiggerboss(param_0, 0x171C, 0x144);
                func_800F82D4(func_800F54E4(), 1);
                func_800F8444(func_800F54E4(), param_0 + 0x44);
                func_80101180(0x4F1, 7, 0);
                return;
            }
            func_800FFAB0(param_0);
            func_800FFAB0(func_80802228_chdiggerboss(param_0));
            return;
        case 0x19A:                                 
            if (func_800DA298(0x44) == 0) {
                func_800F82D4(func_800F54E4(), 1);
                func_800F8444(func_800F54E4(), param_0 + 0x44);
                func_8080290C_chdiggerboss(param_0, 0xD, 0x2020);
                _chintrotext_entrypoint_1(0x18B9, 0xF, 1, 0);
                func_800FDC28(1);
                func_800C964C(0x14);
                return;
            }
            func_80802878_chdiggerboss(param_0, 3, 1);
            func_80800180_chdiggerboss(param_0, 8);
            func_80803660_chdiggerboss(param_0, 0x171F, 0x10E);
            func_800FDC28(1);
            return;
        }
    } else {
        local_7 = func_80802228_chdiggerboss(param_0);
        local_1 = local_7;
        local_2 = func_80100094(local_7, 0);
        local_5 = (*(s16 *)((s8 *)(local_0) + (0)));
        switch (local_5) {                          
        case 0x2D:                                  
            local_3 = func_80802314_chdiggerboss() < 2;
            func_80804A50_chdiggerboss(local_1, 1);
            func_80807698_chdiggerboss(param_0, local_3);
            if (local_3 != 0) {
                (*(s8 *)((s8 *)(local_0) + (2))) = 0x32;
                func_80803BE8_chdiggerboss(param_0, 0x2E, 2);
                func_80802878_chdiggerboss(param_0, 3, 1);
                func_808041E4_chdiggerboss(local_1, 2);
                func_800F82D4(func_800F54E4(), 2);
                func_800F7C58(func_800F54E4(), 0x8A, 1);
            } else {
                func_808041E4_chdiggerboss(local_1, 3);
            }
            break;
        case 0x37:                                  
            local_4 = func_80802314_chdiggerboss() == 0;
            func_808041E4_chdiggerboss(local_1, 2);
            func_80804A50_chdiggerboss(local_1, 1);
            func_80807698_chdiggerboss(param_0, local_4);
            if (local_4 != 0) {
                (*(s8 *)((s8 *)(local_0) + (2))) = 0x28;
                func_80803BE8_chdiggerboss(param_0, 0x38, 2);
                func_80802878_chdiggerboss(param_0, 3, 1);
                func_800F82D4(func_800F54E4(), 2);
                func_800F7C58(func_800F54E4(), 0x8A, 1);
            } else {
                func_808041E4_chdiggerboss(local_1, 3);
            }
            break;
        }
        (*(s16 *)((s8 *)(local_0) + (0xA0))) = 0;
        (*(u8 *)((s8 *)(param_0) + (0x75))) = (u8) ((*(u8 *)((s8 *)(param_0) + (0x75))) & 0xFFFD);
        (*(s8 *)((s8 *)(local_2) + (6))) = 1;
    }
}

int func_80802158_chdiggerboss(param_0, param_1) s32 param_0; s32 param_1;
{
  u16 *local_0 = &D_80809EE4_chdiggerboss;
  return local_0[param_1];
}

s32 func_80802170_chdiggerboss(param_0, param_1) Actor *param_0; s32 param_1;
{
    DiggerFlags1473 *local_0;
    s32 local_1;

    local_0 = func_80100094(param_0, 0);
    if (!local_0->local_0[param_1]) {
        local_1 = func_80802158_chdiggerboss((s32)param_0, param_1);
        if (local_1) {
            func_800DA544(local_1);
        }
        local_0->local_0[param_1] = 1;
        return 0;
    }
    return 1;
}

int func_808021E8_chdiggerboss(s32 param_0, s32 param_1)
{
  u8 *local_0;
  local_0 = (u8 *)func_80100094(param_0, 0) + param_1;
  if (!local_0[0xFD])
  {
    return 0;
  }
  return 1;
}

int func_80802228_chdiggerboss(param_0) Actor *param_0;
{
  func_80106790(param_0->unk3C);
}

s32 func_80802248_chdiggerboss(s32 param_0)
{
  s32 v0;
  s32 v1;
  v0 = func_8010D290(0x10000);
  v1 = v0;
  if (v1 == (-1))
  {
    v1 = func_800F54E4();
  }
  else
  {
    v1 = v1;
  }
  return v1;
}

int func_80802288_chdiggerboss(Actor *param_0)
{
    return (*(u16 *)((char *)param_0 + 0x64) & 1);
}

void func_80802298_chdiggerboss(param_0, param_1) Actor *param_0; f32 *param_1;
{
    func_800EE7F8(param_1, param_0->position);
    func_800EF1B8(param_1, param_0->rotation[1], param_0->scale * 600.0f);
    param_1[1] += param_0->scale * 2500.0f;
}

s32 func_80802314_chdiggerboss(void){
    s32 out;
    out = func_800DA980(0xA4F, 2);
    return 2 - out;
}

s32 func_8080233C_chdiggerboss(s32 param_0)
{
  unsigned short new_var;
  func_80102FDC(param_0, 0.25f);
  func_8010A828(param_0, 3);
  func_80803DC8_chdiggerboss(param_0, 1, 1);
  func_808008C0_chdiggerboss(param_0, 5, 1);
  func_80803E10_chdiggerboss(param_0);
  func_80804784_chdiggerboss(param_0);
  func_80804C28_chdiggerboss(param_0);
  func_80807640_chdiggerboss(param_0);
  func_80807FD8_chdiggerboss(param_0);
  new_var = param_0;
  func_808088AC_chdiggerboss(param_0);
  func_80808C64_chdiggerboss(param_0);
  func_80108B04(param_0, 7);
}

void func_808023D8_chdiggerboss(Actor *param_0)
{
    u8 *local_0;
    Actor *local_1;
    s32 local_2;
    f32 *local_3;
    local_0 = func_80100094(param_0, 0);
    func_80800200_chdiggerboss(param_0);
    func_80803E84_chdiggerboss(param_0);
    func_808047A8_chdiggerboss(param_0);
    func_80804D44_chdiggerboss(param_0);
    func_80808034_chdiggerboss(param_0);
    func_808088CC_chdiggerboss(param_0);
    func_80808CD0_chdiggerboss(param_0);
    local_3 = param_0->position;
    _subaddieaudioloop_entrypoint_4(param_0, local_3, local_0[7], &D_80809F04_chdiggerboss);
    if (local_0[7]) _subaddieDll_entrypoint_7(param_0, 8);
    for (local_2 = 0; local_2 < 8; local_2++) {
        if (func_800F6438(local_2)) func_800F4E5C(local_2, local_3, param_0->rotation, &D_80809F10_chdiggerboss, &D_80809F1C_chdiggerboss);
    }
    if (*(s32 *)((u8 *)param_0 + 0x3C)) {
        local_1 = (Actor *)func_808026F8_chdiggerboss(param_0);
        func_800EE7F8(local_1->position, local_3);
        local_1->rotation[1] = param_0->rotation[1];
    }
    if (*(Unk80132ED0 **)local_0) {
        local_1 = func_80106790(*(Unk80132ED0 **)local_0);
        func_800EE7F8(local_1->position, local_3);
        local_1->position[1] += 300.0f;
    }
}

void func_80802550_chdiggerboss(s32 arg0)
{
    s32 *sp24;

    sp24 = func_80100094(arg0, 0);
    func_808040D8_chdiggerboss(arg0);
    func_808049A8_chdiggerboss(arg0);
    func_808053BC_chdiggerboss(arg0);
    func_80807664_chdiggerboss(arg0);
    func_80808000_chdiggerboss(arg0);
    func_80808948_chdiggerboss(arg0);
    if (func_801069A4(*sp24) != 0)
    {
        func_800FFA88(*sp24);
        *sp24 = 0;
    }
}

s32 func_808025D4_chdiggerboss(Actor *param_0, s32 param_1, s32 param_2)
{
    s32 *local_0;
    s32 *local_1;

    local_1 = &param_2;
    switch (param_1) {
    case 0x1F:
        func_808006F8_chdiggerboss(param_0, param_2);
        return 1;
    case 0x9C:
        func_808007E0_chdiggerboss(param_0, param_2);
        return 1;
    case 0x3D:
        switch (param_2) {
        case 3:
            func_8080815C_chdiggerboss(param_0, param_2);
            return 1;
        case 6:
            func_808089BC_chdiggerboss(param_0, param_2);
            return 1;
        case 7:
            local_0 = func_80100094(param_0, 0);
            *local_0 = *func_801084B0(0x4FF, &param_0);
            break;
        }
        break;
    case 0x3F:
        func_808058B0_chdiggerboss(param_0, param_2);
        return 1;
    case 0x95:
        break;
    default:
        return 0;
    }
    return 1;
}

s32 func_808026F8_chdiggerboss(this) Actor *this;{
    func_80106790(this->unk3C);
}

s32 func_80802718_chdiggerboss(s32 param_0, s32 param_1, s32 param_2)
{
    if (_gcdialogcamera_entrypoint_0(param_1, param_2) != 0)
    {
        if ((*(s16 *)((s8 *)func_80100094(param_0, 0) + 8)) != 2)
        {
            func_80802878_chdiggerboss(param_0, 2, 1);
        }
        return 2;
    }
    return 1;
}

void func_80802778_chdiggerboss(Actor *param_0, s32 param_1)
{
    s16 *local_0;
    local_0 = func_80100094(param_0, 0);
    _capod_entrypoint_2(param_0->unk0, 0x22, param_1 | 0x80000);
    if (local_0[5] == 0) {
        func_800F7F98(func_80802248_chdiggerboss(param_0), 1);
        local_0[5] = 1;
    }
}

s32 func_808027F4_chdiggerboss(param_0) Actor *param_0;
{
    s16 *local_0;
    s32 local_1;

    local_0 = func_80100094(param_0, 0);
    local_1 = func_80802248_chdiggerboss(param_0);
    if (local_0[5]) {
        func_800F7F98(local_1, 0);
        local_0[5] = 0;
    }
    if (local_0[4]) {
        _capod_entrypoint_3(0);
        _plcamera_entrypoint_8(local_1);
        local_0[4] = 0;
        return 1;
    }
    return 0;
}

void func_80802878_chdiggerboss(param_0, param_1, param_2) s32 param_0; s32 param_1; s32 param_2;
{
  s16 *local_0;
  s16 var1;
  s16 **new_var;
  new_var = &local_0;
  local_0 = func_80100094(param_0, 0);
  var1 = (*(s16 *)((char *)(local_0) + 8));
  switch (var1)
  {
    case 0:
      func_80802778_chdiggerboss(param_0, 0);
    case 1:
      _capod_entrypoint_8(1);
      *((s16*)((s8*)local_0 + 8)) = 2;
    case 2:
      func_808029C8_chdiggerboss(param_0);
      _gcdialogcamera_entrypoint_8();
      _capod_entrypoint_7(param_1, param_2);
      return;
  }
}

void func_8080290C_chdiggerboss(param_0, param_1, param_2) s32 *param_0; s32 param_1; s32 param_2; {
    func_80802938_chdiggerboss(param_0, *param_0, param_1, param_2);
}

void func_80802938_chdiggerboss(param_0, param_1, param_2, param_3) s32 param_0; s32 param_1; s32 param_2; s32 param_3;
{
    s32 *local_0;
    local_0 = (s32 *)func_80100094(param_0, 0);
    switch (*(s16 *)((char *)local_0 + 0x8))
    {
    case 0:
        func_80802778_chdiggerboss(param_0, param_3);
        /* fallthrough */
    case 2:
        *(s16 *)((char *)local_0 + 0x8) = 1;
        /* fallthrough */
    case 1:
        _capod_entrypoint_6(param_1, param_2, param_3 | 0x80000);
        return;
    }
}

void func_808029C8_chdiggerboss(param_0) Actor *param_0;
{
    f32 local_0[3];
    f32 local_1[3];
    f32 local_2[4];
    f32 local_3;
    DiggerCameraData *local_4;

    local_4 = func_80100094(param_0, 0);
    func_800EE7F8(local_0, param_0->rotation);
    local_0[1] += local_4->local_1;
    func_800EE7F8(local_1, param_0->position);
    func_800EF1B8(local_1, param_0->rotation[1], param_0->scale * 400.0f);
    local_3 = param_0->scale * local_4->local_0;
    local_2[0] = param_0->scale * 2700.0f;
    local_2[1] = 800.0f * local_3;
    local_2[2] = 500.0f * local_3;
    local_2[3] = param_0->scale * 2100.0f;
    _gcdialogcamera_entrypoint_3(local_2, 1.0f);
    _gcdialogcamera_entrypoint_4(local_1);
    _gcdialogcamera_entrypoint_5(local_0);
}

s32 func_80802AB8_chdiggerboss(Actor *param_0, s32 param_1)
{
    switch (param_1) {
        case 0x1C:
            func_8080290C_chdiggerboss(param_0, 0x1F, 0x20);
            return 4;
        case 0x1F:
            func_800F82D4(func_800F54E4(), 0);
            _gcgoto_entrypoint_2(0x19A, 1, 0);
            func_800A7AD4(1, 0x15);
            break;
        case 0xD:
            func_800F82D4(func_800F54E4(), 0);
            func_80803660_chdiggerboss(param_0, 0x171D, 0x14C);
            func_8080290C_chdiggerboss(param_0, 0x18, 0x20);
            return 4;
        case 0x18:
            func_800DA544(0x44);
            _gcfrontend_entrypoint_9(0x2C);
            func_80802878_chdiggerboss(param_0, 3, 1);
            func_80803BE8_chdiggerboss(param_0, 2, 2);
            return 4;
        case 0x3B:
            func_80805D64_chdiggerboss(param_0, 0x27);
            return 4;
    }
    return 3;
}

void func_80802BE0_chdiggerboss(s32 param_0, f32 param_1)
{
  ((f32 *)func_80100094(param_0, 0))[3] = param_1;
}

void func_80802C0C_chdiggerboss(s32 param_0) {
    func_800F4AF4(func_80802248_chdiggerboss(param_0), 0x14);
    func_80802C40_chdiggerboss(param_0);
}

void func_80802C40_chdiggerboss(param_0) Actor *param_0;
{
    f32 local_0[3];
    f32 *local_1;
    s32 local_2;

    local_1 = local_0;
    local_2 = func_80802248_chdiggerboss(param_0);
    func_800EE7F8(local_1, param_0->position);
    local_1[1] += 500.0f;
    _plcamera_entrypoint_9(local_2, local_1, 0.0f);
    func_80116088(func_80110014(func_800F5EF8(local_2)), local_1);
}

void func_80802CB4_chdiggerboss(s32 param_0)
{
    func_800F4B20(func_80802248_chdiggerboss(param_0));
}

void func_80802CDC_chdiggerboss(param_0) s32 param_0; {
    s8 *var_v0 = func_80100094(param_0, 0);
    var_v0[0x42] = 0;
}


s32 func_80802D00_chdiggerboss(param_0) Actor *param_0;
{
    u8 *local_0;
    u8 *local_1;

    local_0 = func_80100094(param_0, 0);
    local_1 = (u8 *)func_80100094(param_0, 0) + 0x10C;
    switch (local_0[0x40]) {
    case 0:
        break;
    case 1:
        func_80803224_chdiggerboss(param_0);
        break;
    case 2:
        _gcnewoption_entrypoint_0(local_1);
        break;
    case 3:
        _gcnewoption_entrypoint_0(local_1);
        if (func_800D9078((f32 *)(local_0 + 0x4C))) {
            _gcnewoption_entrypoint_37(local_1, 1);
            return 0;
        }
        break;
    case 4:
        _gcnewoption_entrypoint_7(local_1);
        local_0[0x42] = 0;
        func_8010A828(param_0, 1);
        if (local_0[0x41] && !func_80802170_chdiggerboss(param_0, 3)) {
            func_80802878_chdiggerboss(param_0, 5, 1);
            func_80803660_chdiggerboss(param_0, 0x172F, 0x106);
            local_0[0x40] = 6;
            *(s16 *)(local_0 + 0x46) = 1;
            break;
        }
        if (!local_0[0x41] && !func_80802170_chdiggerboss(param_0, 4)) {
            func_80802878_chdiggerboss(param_0, 5, 1);
            func_80803660_chdiggerboss(param_0, 0x1730, 0x106);
            local_0[0x40] = 6;
            *(s16 *)(local_0 + 0x46) = 1;
            break;
        }
        func_80800180_chdiggerboss(param_0, 6);
        local_0[0x40] = 5;
        break;
    case 5:
        if (func_80101DDC(param_0)) {
            func_800F82D4(func_800F54E4(), 0);
            func_80800618_chdiggerboss(param_0, 0, 0);
            func_80800180_chdiggerboss(param_0, 8);
            local_0[0x40] = 0;
            return 1;
        }
        break;
    case 6:
        if (*(s16 *)(local_0 + 0x46) == 0) {
            func_80800180_chdiggerboss(param_0, 6);
            local_0[0x40] = 5;
        }
    }
    return 0;
}

void func_80802EF8_chdiggerboss(s32 arg0) 
{
}
void func_80802F00_chdiggerboss(param_0, param_1) Actor *param_0; s32 param_1;
{
    s32 local_0;
    f32 local_1[3];
    f32 local_2[3];

    func_80803BE8_chdiggerboss(param_0, param_1, 2);
    func_80802878_chdiggerboss((s32)param_0, 3, 1);
    func_80800618_chdiggerboss(param_0, 0, 1);
    func_808056B8_chdiggerboss(func_80802228_chdiggerboss(param_0));
    local_0 = func_800F54E4();
    func_800F5A00(local_0, local_1);
    if (func_800EFB8C(local_1, param_0->position) < 550.0f) {
        func_800EEB9C(local_2, func_800F1DF4(param_0->position, local_1), 550.0f);
        func_800EF04C(local_2, param_0->position);
        local_2[1] = local_1[1];
        func_800F8418(local_0, local_2);
    }
    func_800F7F98(local_0, 1);
}

void func_80802FEC_chdiggerboss(param_0, param_1, param_2) s32 param_0; s32 param_1; s32 param_2; {
    u8 *sp1C;
    u8 *temp_v0;

    temp_v0 = func_80100094(param_0, 0);
    sp1C = temp_v0;
    (*(s8 *)((s8 *)(temp_v0) + (0x40))) = 1;
    (*(s8 *)((s8 *)(temp_v0) + (0x43))) = (s8) param_2;
    (*(s16 *)((s8 *)(sp1C) + (0x44))) = func_80803424_chdiggerboss(param_0, param_2);
    func_800F7F98(func_800F54E4(), 0);
    func_800F8300(func_800F54E4(), 2, param_0 + 4);
    func_80803BE8_chdiggerboss(param_0, param_1, 4);
}



void func_80803078_chdiggerboss(param_0, param_1, param_2, param_3) s32 *param_0; s32 param_1; s32 param_2; u32 param_3; {
    u8 *local_3;
    u8 *local_0;
    s32 local_1;
    s32 local_2;
    u8 *local_4;

    local_4 = func_80100094(param_0, 0);
    local_3 = local_4;
    switch (param_3) {
    case 0:
        func_80803338_chdiggerboss(param_1, local_3);
        return;
    case 2:
        local_0 = local_3;
        func_80803610_chdiggerboss(param_0, local_3);
        (*(s8 *)((s8 *)(local_3) + (0x40))) = 4;
        return;
    case 4:
        local_0 = local_3;
        local_2 = _gcnewoption_entrypoint_3(param_1, local_3) == param_2;
        local_1 = local_2;
        (*(s8 *)((s8 *)(local_3) + (0x48))) = 0;
        (*(s8 *)((s8 *)(local_3) + (0x41))) = (s8) local_2;
        func_80803610_chdiggerboss(param_0, local_3);
        if (local_1 != 0) {
            _gcnewoption_entrypoint_38(param_1, 1);
            func_800FC660(0xE);
            return;
        }
        _gcnewoption_entrypoint_37(param_1, 1);
        func_800FC660(0xF);
        return;
    case 5:
        (*(s8 *)((s8 *)(local_3) + (0x41))) = 0;
        (*(s8 *)((s8 *)(local_3) + (0x48))) = 0;
        func_80803610_chdiggerboss(param_0, local_3);
        _gcnewoption_entrypoint_37(param_1, 1);
        func_800FC660(0xF);
        return;
    case 3:
        local_0 = local_3;
        func_80803610_chdiggerboss(param_0, local_3);
        (*(s8 *)((s8 *)(local_3) + (0x40))) = 4;
        return;
    case 9:
        func_800CE8D8(8, 5.0f, 5);
        func_800CE928(8, &_chdiggerboss_entrypoint_2, *param_0);
        func_800CEA38(8, 1);
        func_800CE88C(8, 1);
        return;
    case 10:
        if ((*(u8 *)((s8 *)(local_4) + (0x48))) == 0) {
            (*(s8 *)((s8 *)(local_4) + (0x40))) = 3;
            (*(f32 *)((s8 *)(local_4) + (0x4C))) = 0.4f;
        }
        
    default:
        return;
    }
}

void func_80803224_chdiggerboss(Actor *param_0)
{
    u8 *local_0;
    u8 *local_1;
    local_0 = (u8 *)func_80100094(param_0, 0);
    local_1 = (u8 *)func_80100094(param_0, 0) + 0x10C;
    bzero(local_1, _gcnewoption_entrypoint_2());
    _gcnewoption_entrypoint_5(local_1, _gcnewoption_entrypoint_35, 0, *(u16 *)(local_0 + 0x44), param_0->unk0);
    _gcnewoption_entrypoint_8(local_1, 3);
    _gcnewoption_entrypoint_9(local_1, 3);
    _gcnewoption_entrypoint_10(local_1, 2);
    _gcnewoption_entrypoint_14(local_1, 0, 0, 0, 4.0f);
    _gcnewoption_entrypoint_32(local_1, 0x22);
    _gcnewoption_entrypoint_30(local_1, D_80809F34_chdiggerboss);
    _gcnewoption_entrypoint_28(local_1);
    _gcnewoption_entrypoint_29(local_1, 1);
    _gcnewoption_entrypoint_11(local_1);
    local_0[0x40] = 2;
    local_0[0x42] = 1;
    local_0[0x48] = 1;
    func_8010A828(param_0, 9);
}

void func_80803338_chdiggerboss(param_0) s32 param_0;
{
    s32 var_s0;

    var_s0 = 0;
    do {
        _gcnewoption_entrypoint_12(param_0, var_s0, (s16)(var_s0 + 0xA));
        _gcnewoption_entrypoint_21(param_0, var_s0);
        var_s0 += 1;
    } while (var_s0 != 3);
}

int func_808033A0_chdiggerboss(s32 param_0, s32 param_1, s32 *param_2)
{
  s32 local_0;
  local_0 = func_80100094(param_0, 0);
  switch (param_1)
  {
    case 0 :
      *param_2 = 0x14;
      return local_0 + 0x50;

    case 1 :
      *param_2 = 0x14;
      return local_0 + 0x53;

    case 2 :
      *param_2 = 0x14;
      return local_0 + 0x56;

    default :
      break;

  }
  return 0;
}

s32 func_80803424_chdiggerboss(param_0, param_1) Actor *param_0; s32 param_1;
{
    s32 local_3;
    s32 local_0;
    s32 local_1;
    void *local_2;

    local_2 = func_808033A0_chdiggerboss(param_0, param_1, &local_3);
    local_0 = func_800DC128(0, local_3);
    for (local_1 = 0; local_1 < local_3; local_1++) {
        if (!func_80803524_chdiggerboss(local_2, local_0)) {
            func_80803558_chdiggerboss(local_2, local_0, 1);
            return D_80809F28_chdiggerboss[param_1][0] + local_0;
        }
        local_0++;
        if (local_0 == local_3) {
            local_0 = 0;
        }
    }
    bzero(local_2, (local_3 + 7) >> 3);
    local_0 = func_800DC128(0, local_3);
    func_80803558_chdiggerboss(local_2, local_0, 1);
    return D_80809F28_chdiggerboss[param_1][0] + local_0;
}

u8 func_80803524_chdiggerboss(param_0, param_1) s32 param_0; s32 param_1;
{
  u8 *ptr;
  u8 val;
  u8 result;
  ptr = (u8 *) param_0;
  val = ptr[param_1 >> 3] ^ 0;
  if (val & (1 << (param_1 & 7)))
  {
    result = 1;
  }
  else
  {
    result = 0;
  }
  return result;
}

void func_80803558_chdiggerboss(param_0, param_1, param_2) u8 *param_0; s32 param_1; unsigned int param_2;
{
  s32 idx = (0, param_1 >> 3);
  s32 mask = 1 << (param_1 & 7);
  if (param_2)
  {
    param_0[0, param_1 >> 3] |= mask;
  }
  else
  {
    param_0[0, param_1 >> 3] &= ~mask;
  }
  return;
}

void chdiggerboss_entrypoint_2(s32 param_0, s32 param_1) {
    s32 sp1C;
    u8 *sp18;
    s32 temp_a0;
    s32 temp_v0;

    temp_v0 = func_80106790(param_1);
    sp1C = temp_v0;
    sp18 = func_80100094(temp_v0, 0);
    temp_a0 = (u8 *)func_80100094(sp1C, 0) + 0x10C;
    if ((*(u8 *)((s8 *)(sp18) + (0x40))) == 2) {
        _gcnewoption_entrypoint_37(temp_a0, 1);
    }
}

s32 func_80803610_chdiggerboss(param_0) s32 param_0; {
    if(func_800CEAA8(8)){
        func_800CE928(8, 0, 0);
        func_800CE88C(8, 0);
        func_800CEBD8(8, 0);
    }
}

int func_80803660_chdiggerboss(param_0, param_1, param_2) s32 param_0[4]; s32 param_1; s32 param_2;
{
  u32 local_0;
  local_0 = param_0[0];
  return _subaddiedialog_entrypoint_11(local_0, param_1, param_2, param_0 + 1, 0x22);
}

void func_80803694_chdiggerboss(param_0, param_1, param_2) s32 param_0; s32 param_1; s32 param_2; {
    u8 *sp24;
    u8 *temp_v0;

    temp_v0 = func_80100094(param_0, 0);
    sp24 = temp_v0;
    switch (param_1) {                                 
    case 0x171D:
        break;
    case 0x171E:
    case 0x171F:
        func_80803BE8_chdiggerboss(param_0, 4, 3, param_1);
        return;
    case 0x1720:
        func_800FDC28(0x14);
        func_80805A00_chdiggerboss(param_0, 6);
        return;
    case 0x172E:
        func_80802FEC_chdiggerboss(param_0, 9, 0, param_1);
        return;
    case 0x172F: ;
    case 0x1730:
        func_80802878_chdiggerboss(param_0, 3, 1, param_1);
        if (func_80802170_chdiggerboss(param_0, 2) == 0) {
            func_80803660_chdiggerboss(param_0, 0x1722, 0x106);
            return;
        }
        func_800C0850();
        (*(s16 *)((s8 *)(sp24) + (0x46))) = 0;
        return;
    case 0x1722:
        (*(s16 *)((s8 *)(temp_v0) + (0x46))) = 0;
        return;
    case 0x1721:
        func_80805A00_chdiggerboss(param_0, 0xE);
        return;
    case 0x1723:
        func_80807280_chdiggerboss(param_0, 0x16, &D_80809CF0_chdiggerboss, param_1);
        return;
    case 0x1724:
        func_80807280_chdiggerboss(param_0, 0x1E, &D_80809D00_chdiggerboss, param_1);
        return;
    case 0x1725:
        func_8080290C_chdiggerboss(param_0, 0x3B, 0, param_1);
        func_80803660_chdiggerboss(param_0, 0x1726, 0x14C);
        return;
    case 0x1731:
        func_80803BE8_chdiggerboss(param_0, 0xC, 3, param_1);
        return;
    case 0x1732:
        func_80803BE8_chdiggerboss(param_0, 0x14, 3, param_1);
        return;
    case 0x1733:
        func_80803BE8_chdiggerboss(param_0, 0x2F, 3, param_1);
        return;
    case 0x1734:
        func_80802878_chdiggerboss(param_0, 3, 1, param_1);
        func_80803660_chdiggerboss(param_0, 0x1729, 0x10E);
        return;
    case 0x1729:
        func_80806A78_chdiggerboss(param_0, 0x3A, &D_80809CC0_chdiggerboss, param_1);
        func_80806EE4_chdiggerboss(param_0, 1);
        (*(s8 *)((s8 *)(sp24) + (4))) = 1;
        return;
    case 0x172A:
        func_80806A78_chdiggerboss(param_0, 0x3C, &D_80809CD0_chdiggerboss, param_1);
        func_80806EE4_chdiggerboss(param_0, 1);
        return;
    case 0x172B:
        func_80806A78_chdiggerboss(param_0, 0x3E, &D_80809CE0_chdiggerboss, param_1);
        func_80806EE4_chdiggerboss(param_0, 1);
        func_80807DC0_chdiggerboss(param_0, 2);
        func_808080C0_chdiggerboss(func_80802228_chdiggerboss(param_0), 2);
        return;
    case 0x172C:
        func_80808470_chdiggerboss(param_0, 0x40);
        return;
    case 0x172D:
        func_80802BE0_chdiggerboss(param_0, 1.0f);
        func_80808560_chdiggerboss(param_0);
        return;
    case 0x1735:
        func_80809150_chdiggerboss(param_0);
        return;
    case 0x14D8:
        func_800FDC28(0);
        _gcgoto_entrypoint_1(0x191, 1);
        return;
    case 0xCEB:
        if (param_2 > 0) {
            _gcfrontend_entrypoint_11();
            return;
        }
        _gcfrontend_entrypoint_10();
        return;
    }
}

void func_808039C0_chdiggerboss(s32 param_0, volatile unsigned int param_1, s32 param_2) {
    s32 local_0;
    s32 local_1;
    s32 local_2;

    local_0 = func_80802228_chdiggerboss(param_0);
    switch (param_1) {
    case 0x1720:
        func_80805448_chdiggerboss(local_0, 0, 1);
        func_80805448_chdiggerboss(local_0, 2, 1);
        return;
    case 0x1721:
        local_1 = 0;
        do {
            func_80805448_chdiggerboss(local_0, local_1, 1);
            local_1 += 1;
        } while (local_1 != 4);
        return;
    case 0x1723:
        func_8080041C_chdiggerboss(local_0, 0xE);
        return;
    case 0x1724:
        func_8080041C_chdiggerboss(local_0, 0x10);
        return;
    case 0x1725:
        switch (param_2) {
        case 1:
            func_8080041C_chdiggerboss(local_0, 0x12);
            return;
        case 2:
            func_80805448_chdiggerboss(local_0, 0, 1);
            func_80805448_chdiggerboss(local_0, 3, 1);
            return;
        }
        break;
    case 0x1726:
        if (param_2 == 1) {
            func_80804A50_chdiggerboss(local_0, 2);
            return;
        }
    default:
        return;
    case 0x1734:
        switch (param_2) {
        case 1:
            func_80804A50_chdiggerboss(local_0, 0);
            return;
        case 2:
            local_2 = 0;
            do {
                func_80805448_chdiggerboss(local_0, local_2, 2);
                local_2 += 1;
            } while (local_2 != 4);
            return;
        case 3:
            func_808041E4_chdiggerboss(local_0, 4);
            return;
        }
        break;
    case 0x172A:
        switch (param_2) {
        case 1:
            func_8080041C_chdiggerboss(local_0, 0x14);
            return;
        case 2:
            func_80807DC0_chdiggerboss(param_0, 1);
            return;
        }
        break;
    case 0x172B:
        if (param_2 == 1) {
            func_808080C0_chdiggerboss(func_80802228_chdiggerboss(param_0), 1);
        }
        break;
    }
}

void func_80803BE8_chdiggerboss(param_0, param_1, param_2) Actor *param_0; s32 param_1; s32 param_2;
{
    u8 *local_0;
    s32 local_1;

    local_0 = func_80100094(param_0, 0);
    *(s16 *)local_0 = param_1;
    if (param_2 != -1) {
        func_80800180_chdiggerboss(param_0, param_2);
    }
    switch (param_1) {
        case 6:
            func_80805448_chdiggerboss(func_80802228_chdiggerboss(param_0), 0, 1);
            func_80805448_chdiggerboss(func_80802228_chdiggerboss(param_0), 2, 1);
            *(f32 *)(local_0 + 0x20) = 40.0f;
            *(f32 *)(local_0 + 0x1C) = 10.0f;
            break;
        case 14:
            for (local_1 = 0; local_1 != 4; local_1++) {
                func_80805448_chdiggerboss(func_80802228_chdiggerboss(param_0), local_1, 1);
            }
            *(f32 *)(local_0 + 0x1C) = 10.0f;
            *(f32 *)(local_0 + 0x20) = -60.0f;
            break;
        case 39:
            func_80805448_chdiggerboss(func_80802228_chdiggerboss(param_0), 0, 1);
            func_80805448_chdiggerboss(func_80802228_chdiggerboss(param_0), 3, 1);
            *(f32 *)(local_0 + 0x30) = 5.0f;
            *(f32 *)(local_0 + 0x34) = 5.0f;
            *(f32 *)(local_0 + 0x3C) = 40.0f;
            *(f32 *)(local_0 + 0x20) = 40.0f;
            *(f32 *)(local_0 + 0x38) = 250.0f;
            break;
        case 49:
            for (local_1 = 0; local_1 != 4; local_1++) {
                func_80805448_chdiggerboss(func_80802228_chdiggerboss(param_0), local_1, 1);
            }
            *(f32 *)(local_0 + 0x30) = 5.0f;
            *(f32 *)(local_0 + 0x34) = 5.0f;
            *(f32 *)(local_0 + 0x3C) = 60.0f;
            *(f32 *)(local_0 + 0x38) = 350.0f;
            *(f32 *)(local_0 + 0x20) = -60.0f;
            break;
    }
}

int func_80803DC8_chdiggerboss(param_0, param_1, param_2) s32 param_0; s32 param_1; s32 param_2;
{
  Actor *local_0;
  local_0 = func_80100094(param_0, 0);
  (*(u8 *)((char *)(local_0) + 0x4)) = param_1;
  if (param_2 != -1)
  {
    func_8080041C_chdiggerboss(param_0, param_2);
  }
}

void func_80803E10_chdiggerboss(param_0) s32 param_0;
{
  u8 *sp1C;
  s8 temp_v0_2;
  u8 *new_var;
  u8 **new_var2;
  u8 *temp_v0;
  temp_v0 = func_80100094(param_0, 0);
  sp1C = temp_v0;
  *((s8 *) (((s8 *) temp_v0) + 0xB)) = 0;
  *((s8 *) (((s8 *) temp_v0) + 0xC)) = 0;
  *((s8 *) (((s8 *) temp_v0) + 0xD)) = 0;
  *((f32 *) (((s8 *) sp1C) + 0x14)) = func_800DC178(0.85f, 2.5f);
  temp_v0_2 = func_800E8B74(0);
  new_var2 = &sp1C;
  new_var = *new_var2;
  *((s8 *) (((s8 *) new_var) + 0xA)) = temp_v0_2;
  func_800E8D5C(temp_v0_2 & 0xFF, &D_80809F98_chdiggerboss, 3);
}

void func_80803E84_chdiggerboss(Actor *param_0)
{
    u8 *local_3;
    f32 local_0;
    s32 local_1;

    local_3 = func_80100094(param_0, 0);
    switch (local_3[8]) {
    case 0:
        break;
    case 1:
        local_3[0xD] = _subaddieaudioloop_entrypoint_7(local_3[0xD], param_0->position, 1, &D_80809FB0_chdiggerboss, *(u32 *)((u8 *)param_0 + 0x70) & 1);
        if (func_800D9078((f32 *)(local_3 + 0x10))) {
            func_808041E4_chdiggerboss(param_0, 2);
        }
        break;
    case 2:
        local_0 = func_800F10B4(*(f32 *)((u8 *)param_0 + 0x24), 0.0f, 350.0f, 0.85f, 1.1f);
        local_1 = func_800F10B4(*(f32 *)((u8 *)param_0 + 0x24), 0.0f, 350.0f, 25000.0f, 32000.0f);
        if (local_3[0xB] == 0) {
            func_800C4B64(local_0);
            func_800C4B70(local_1);
        }
        local_3[0xB] = _subaddieaudioloop_entrypoint_7(local_3[0xB], (param_0->position), 1, &D_80809FC0_chdiggerboss, *(u32 *)((u8 *)param_0 + 0x70) & 1);
        if (local_3[0xB] != 0) {
            func_800C31DC(local_3[0xB], local_0);
            func_800C3058(local_3[0xB], local_1);
        }
        if (func_80802314_chdiggerboss() < 2 && func_800D90A4((f32 *)(local_3 + 0x14))) {
            _subaddieaudioquick_entrypoint_2(param_0, (param_0->position), &D_80809F44_chdiggerboss);
            *(f32 *)(local_3 + 0x14) = func_800DC178(0.85f, 2.5f);
            local_3[9] = 4;
        }
        func_80804680_chdiggerboss(param_0);
        if (func_8001210C(1)) {
            if (local_3[9]) {
                func_808043D8_chdiggerboss(param_0, 1.25f, D_80809F3C_chdiggerboss);
                local_3[9]--;
            } else {
                func_808043D8_chdiggerboss(param_0, 1.0f, &D_80809F40_chdiggerboss);
            }
        }
        break;
    case 3:
        local_3[0xC] = _subaddieaudioloop_entrypoint_7(local_3[0xC], param_0->position, 1, &D_80809FD0_chdiggerboss, *(u32 *)((u8 *)param_0 + 0x70) & 1);
        break;
    case 4:
        func_80804450_chdiggerboss(param_0);
        break;
    }
    func_80804140_chdiggerboss(param_0);
}

void func_808040D8_chdiggerboss(param_0) s32 param_0;
{
    u8 *local_0;

    local_0 = func_80100094(param_0, 0);
    if (local_0[0xA] != 0) {
        func_800E8C08(local_0[0xA]);
        local_0[0xA] = 0;
    }
    local_0[0xB] = _subaddieaudioloop_entrypoint_3(local_0[0xB]);
    local_0[0xC] = _subaddieaudioloop_entrypoint_3(local_0[0xC]);
    local_0[0xD] = _subaddieaudioloop_entrypoint_3(local_0[0xD]);
}

void func_80804140_chdiggerboss(param_0) Actor *param_0;
{
    u8 *local_0;
    s32 local_1;
    f32 local_2;
    local_0 = func_80100094(param_0, 0);
    local_1 = func_800F10B4(*(f32 *)&param_0->actorData[3], 0.0f, 350.0f, 15.0f, 25.0f);
    local_2 = func_800F10B4(*(f32 *)&param_0->actorData[3], 0.0f, 350.0f, 0.35f, 0.2f);
    func_800E8DB0(local_0[0xA], local_1);
    func_800E8D28(local_0[0xA], local_2);
}

void func_808041E4_chdiggerboss(param_0, param_1) Actor *param_0; s32 param_1;
{
    u8 *local_0;

    local_0 = func_80100094(param_0, 0);
    local_0[8] = param_1;
    switch (param_1) {
        case 0:
            local_0[0xB] = _subaddieaudioloop_entrypoint_3(local_0[0xB]);
            local_0[0xC] = _subaddieaudioloop_entrypoint_3(local_0[0xC]);
            local_0[0xD] = _subaddieaudioloop_entrypoint_3(local_0[0xD]);
            break;
        case 1:
            *(f32 *)(local_0 + 0x10) = 1.4f;
            break;
        case 2:
            local_0[0xC] = _subaddieaudioloop_entrypoint_3(local_0[0xC]);
            local_0[0xD] = _subaddieaudioloop_entrypoint_3(local_0[0xD]);
            break;
        case 3:
            local_0[0xB] = _subaddieaudioloop_entrypoint_3(local_0[0xB]);
            local_0[0xD] = _subaddieaudioloop_entrypoint_3(local_0[0xD]);
            break;
        case 4:
            local_0[0xB] = _subaddieaudioloop_entrypoint_3(local_0[0xB]);
            local_0[0xC] = _subaddieaudioloop_entrypoint_3(local_0[0xC]);
            local_0[0xD] = _subaddieaudioloop_entrypoint_3(local_0[0xD]);
            *(f32 *)(local_0 + 0x10) = 0.0f;
            break;
    }
}

u8 func_808042D8_chdiggerboss(s32 param_0) {
    return *(u8 *)((char *)func_80100094(param_0, 0) + 8);
}

void func_808042FC_chdiggerboss(param_0, param_1, param_2) Actor *param_0; void *param_1; void *param_2;
{
    u8 *local_2;
    f32 local_0;
    f32 local_1;

    local_2 = (u8 *)func_80100094(param_0, 0);
    if (local_2[8]) {
        local_0 = (f32)func_800E8C58(local_2[10]);
        local_1 = 1.0f / _dbskeleton_entrypoint_1(func_800B27E0(param_2));
        func_800E0C20(param_1, 3, local_1, 0.0f, local_0, 0.0f);
        func_800E0C20(param_1, 10, local_1, 0.0f, -local_0, 0.0f);
        func_800E0C20(param_1, 24, local_1, 0.0f, -local_0, 0.0f);
    }
}

void func_808043D8_chdiggerboss(s32 *param_0, f32 param_1, u8 *param_2) {
    f32 local_0[3];
    s32 local_2;

    if (_subaddieskeleton_entrypoint_2(*param_0, 7, local_0) != 0) {
        local_2 = func_800B53A4(1);
        func_800BAB80(local_2, param_2);
        func_800BABB8(local_2, local_0, (u8 *)param_0 + 4, param_1, &D_80809FE0_chdiggerboss);
    }
}

void func_80804450_chdiggerboss(Actor *param_0)
{
    u8 *local_0;
    f32 local_1;
    s32 local_2;

    local_0 = (u8 *)func_80100094(param_0, 0);
    local_1 = *(f32 *)(local_0 + 0x10);
    local_2 = func_800D91EC((f32 *)(local_0 + 0x10), 4.0f);
    if (func_80804644_chdiggerboss(*(f32 *)(local_0 + 0x10), local_1, 0.1f)) {
        _subaddieaudioquick_entrypoint_2(param_0, (u8 *)param_0 + 4, D_80809F44_chdiggerboss);
        func_808043D8_chdiggerboss(param_0, 1.0f, D_80809F3C_chdiggerboss);
    }
    if (func_80804644_chdiggerboss(*(f32 *)(local_0 + 0x10), local_1, 0.4f)) {
        _subaddieaudioquick_entrypoint_2(param_0, (u8 *)param_0 + 4, D_80809F44_chdiggerboss);
        func_808043D8_chdiggerboss(param_0, 1.0f, D_80809F3C_chdiggerboss);
    }
    if (func_80804644_chdiggerboss(*(f32 *)(local_0 + 0x10), local_1, 1.2f)) {
        _subaddieaudioquick_entrypoint_2(param_0, (u8 *)param_0 + 4, D_80809F74_chdiggerboss);
        func_808043D8_chdiggerboss(param_0, 1.25f, D_80809F3C_chdiggerboss);
    }
    if (func_80804644_chdiggerboss(*(f32 *)(local_0 + 0x10), local_1, 2.0f)) {
        _subaddieaudioquick_entrypoint_2(param_0, (u8 *)param_0 + 4, D_80809F44_chdiggerboss);
        func_808043D8_chdiggerboss(param_0, 1.0f, D_80809F3C_chdiggerboss);
    }
    if (func_80804644_chdiggerboss(*(f32 *)(local_0 + 0x10), local_1, 2.4f)) {
        _subaddieaudioquick_entrypoint_2(param_0, (u8 *)param_0 + 4, D_80809F5C_chdiggerboss);
        func_808043D8_chdiggerboss(param_0, 1.0f, D_80809F40_chdiggerboss);
    }
    if (func_80804644_chdiggerboss(*(f32 *)(local_0 + 0x10), local_1, 3.4f)) {
        _subaddieaudioquick_entrypoint_2(param_0, (u8 *)param_0 + 4, D_80809F88_chdiggerboss);
        func_808043D8_chdiggerboss(param_0, 1.5f, D_80809F3C_chdiggerboss);
    }
    if (local_2 != 0) {
        func_808041E4_chdiggerboss(param_0, 0);
    }
}

s32 func_80804644_chdiggerboss(f32 param_0, f32 param_1, f32 param_2){
    if((param_2 < param_0) && (param_1 <= param_2)){
        return 1;
    }
    return 0;
}

void func_80804680_chdiggerboss(Actor *param_0)
{
    s32 local_0;
    f32 local_1[3];
    f32 local_2[3];
    f32 local_3[3];
    f32 local_4;
    f32 local_5;
    f32 local_6[3];

    if (_subaddieskeleton_entrypoint_2(param_0->unk0, 7, local_2)) {
        func_800EF1B8(local_2, param_0->rotation[1], 150.0f);
        func_800EEB9C(local_3, param_0->rotation[1] - 180.0f, 1000.0f);
        local_0 = func_8010D490(local_2, local_3, 650.0f, 325.0f, -1);
        if (local_0 != -1) {
            func_800F5A00(local_0, local_1);
            local_4 = func_800F10B4(func_800EFB8C(local_2, local_1), 0.0f, 650.0f, 1400.0f, 100.0f);
            local_5 = func_800F1DF4(local_2, local_1);
            func_800EEB9C(local_6, local_5, local_4);
            func_800F48BC(local_0, local_6);
        }
    }
}

void func_80804784_chdiggerboss(param_0) s32 param_0; {
    (*(s8 *)((s8 *)(func_80100094(param_0, 0)) + 0x1A)) = 0;
}

void func_808047A8_chdiggerboss(Actor *param_0)
{
    u8 *local_3;
    s32 local_0;
    f32 local_1;
    s32 local_2;

    local_3 = func_80100094(param_0, 0);
    switch (*(s16 *)(local_3 + 0x18)) {
    case 0:
        *(f32 *)(local_3 + 0x20) = func_800F15F8(*(f32 *)(local_3 + 0x20), 0.0f, func_800D8FF8() * 0.4f);
        func_80804AC8_chdiggerboss(param_0, 0);
        break;
    case 1:
        *(f32 *)(local_3 + 0x20) = func_800F15F8(*(f32 *)(local_3 + 0x20), 0.2f, func_800D8FF8() * 0.4f);
        func_80804AC8_chdiggerboss(param_0, 1);
        break;
    case 2:
        *(f32 *)(local_3 + 0x20) = func_800F15F8(*(f32 *)(local_3 + 0x20), 1.0f, func_800D8FF8() * 0.4f);
        func_80804AC8_chdiggerboss(param_0, 1);
        break;
    }
    local_0 = *(f32 *)(local_3 + 0x20) > 0.0f;
    func_808049DC_chdiggerboss(param_0);
    local_1 = func_800F10B4(*(f32 *)(local_3 + 0x20), 0.0f, 1.0f, 0.7f, 1.1f);
    local_2 = (s32)func_800F10B4(*(f32 *)(local_3 + 0x20), 0.0f, 1.0f, 22000.0f, 32000.0f);
    if (!local_3[0x1A]) {
        func_800C4B64(local_1);
        func_800C4B70(local_2);
    }
    local_3[0x1A] = _subaddieaudioloop_entrypoint_7(local_3[0x1A], param_0->position,
        local_0, D_8080A028_chdiggerboss, *(u32 *)((u8 *)param_0 + 0x70) & 1);
    if (local_3[0x1A]) {
        func_800C31DC(local_3[0x1A], local_1);
        func_800C3058(local_3[0x1A], local_2);
    }
}

void func_808049A8_chdiggerboss(param_0) s32 param_0;
{
    u8 *local_0;
    u8 *local_1;

    local_1 = func_80100094(param_0, 0);
    local_0 = local_1;
    *(s8 *)((char *)local_0 + 0x1A) = _subaddieaudioloop_entrypoint_3(*(u8 *)((char *)local_1 + 0x1A));
}

void func_808049DC_chdiggerboss(Actor *param_0)
{
    u8 *local_0;
    f32 local_1;

    local_0 = func_80100094(param_0, 0);
    local_1 = func_800F10B4(*(f32 *)(local_0 + 0x20), 0.0f, 1.0f, 0.0f, 300.0f);
    *(f32 *)(local_0 + 0x1C) += local_1 * func_800D8FF8();
    *(f32 *)(local_0 + 0x1C) = func_800136E4(*(f32 *)(local_0 + 0x1C));
}

s32 func_80804A50_chdiggerboss(param_0, param_1) s32 param_0; s32 param_1;
{
  *(s16 *)((char *)func_80100094(param_0, 0) + 0x18) = param_1;
}

void func_80804A7C_chdiggerboss(param_0, param_1, param_2) s32 param_0; s32 param_1; s32 param_2; {
    u8 *local_0 = func_80100094(param_0, 0);
    func_800E0AFC(param_1, 0x2A, 1.0f, 0.0f, 0.0f, *(f32 *)(local_0 + 0x1C));
}

void func_80804AC8_chdiggerboss(param_0, param_1) Actor *param_0; s32 param_1;
{
    f32 local_0[3];
    f32 local_1[3];
    f32 local_2[3];
    f32 local_3[4];
    s32 local_4;

    if (param_1) {
        for (local_4 = 0; local_4 < 8; local_4++) {
            if (!func_800F6438(local_4)) continue;
            if (!func_800F6478(local_4)) continue;
            if (!(func_800F581C(local_4) & 0x10000000)) continue;
            func_800EE7F8(local_3, param_0->position);
            func_800EF1B8(local_3, param_0->rotation[1], 1300.0f);
            local_3[1] += 275.0f;
            func_800F5A00(local_4, local_2);
            func_800EE7F8(local_0, param_0->position);
            local_0[1] += 275.0f;
            func_800F018C(local_1, local_0, local_3, local_2);
            func_800F7A2C(local_4, 6, local_1);
            func_808062B8_chdiggerboss(func_808026F8_chdiggerboss(param_0));

        }
    }
}

void func_80804C28_chdiggerboss(param_0) Actor *param_0;
{
    u8 *local_0;
    s32 local_1;
    s32 local_2;
    u8 local_3;
    local_0 = func_80100094(param_0, 0);
    local_0[0x24] = 0;
    for (local_1 = 0; local_1 < 4; local_1++) {
        func_80805448_chdiggerboss(param_0, local_1, 0);
        local_2 = func_800C8A98();
        *(s32 *)(local_0 + 0x30 + local_1 * 0x1C) = local_2;
        func_800C8F64(local_2, 9);
        func_800C8D4C(local_2, D_8080A038_chdiggerboss);
        func_800EE7F8(local_0 + 0x3C + local_1 * 0x1C, param_0->position);
        local_3 = func_800E8714(1);
        local_0[0x48 + local_1 * 0x1C] = local_3;
        func_800E8830(local_3, param_0->position);
        func_800E8870(local_3, 20.0f);
    }
    func_808057D0_chdiggerboss(param_0);
    func_808056B8_chdiggerboss(param_0);
}

void func_80804D44_chdiggerboss(param_0) Actor *param_0;
{
    u8 *local_0;
    s32 local_1;
    s16 local_2;
    s32 local_3;
    s32 local_4;
    s16 *local_7 = (s16 *)D_8080A058_chdiggerboss;

    local_0 = func_80100094(param_0, 0);
    local_1 = 0;
    func_800D9078((f32 *)(local_0 + 0x28));
    for (local_4 = 0; local_4 != 4; local_4++) {
        local_2 = *(s16 *)(local_0 + 0x34 + local_4 * 0x1C);
        switch (local_2) {
        case 0:
            break;
        case 1:
            local_1 = 1;
            func_80805960_chdiggerboss(param_0, local_4, func_800DC128(1, 5));
            break;
        case 2:
            if (func_800DC298(0.5f)) {
                local_3 = 0;
            } else {
                local_3 = func_800DC128(1, 5);
            }
            local_1 = 1;
            func_80805960_chdiggerboss(param_0, local_4, local_3);
            if (func_800D9078((f32 *)(local_0 + 0x38 + local_4 * 0x1C))) {
                func_80805448_chdiggerboss(param_0, local_4, 0);
            }
            break;
        }
        if (local_0[0x48 + local_4 * 0x1C]) {
            _subaddieskeleton_entrypoint_2(param_0->unk0,
                local_7[local_4], local_0 + 0x3C + local_4 * 0x1C);
            func_800E8830(local_0[0x48 + local_4 * 0x1C], local_0 + 0x3C + local_4 * 0x1C);
        }
    }
    func_808056F8_chdiggerboss(param_0);
    func_808057D0_chdiggerboss(param_0);
    local_0[0x24] = _subaddieaudioloop_entrypoint_7(local_0[0x24],
        param_0->position, local_1, D_8080A040_chdiggerboss,
        *(u32 *)((u8 *)param_0 + 0x70) & 1);
}

void func_80804EFC_chdiggerboss(param_0, param_1) Actor *param_0; s32 param_1;
{
    u8 *local_0;
    s32 i;

    local_0 = func_80100094(param_0, 0);
    for (i = 0; i < 4; i++) {
        func_800DF744(D_8080A060_chdiggerboss[i], ((DiggerSlot *)(local_0 + 0x34))[i].unk2);
    }
    func_800DF830(1);
    func_800DE498(param_1, param_0->position, (u8 *)param_0 + 0x44, *(f32 *)((u8 *)param_0 + 0x38), 0, func_800D674C(0x955));
    for (i = 0; i < 4; i++) {
        if (((DiggerSlot *)(local_0 + 0x34))[i].unk0 != 0) {
            func_80804FE4_chdiggerboss(param_0, i, param_1);
        }
    }
}

void func_80804FE4_chdiggerboss(param_0, param_1, param_2) u8 *param_0; s32 param_1; s32 param_2;
{
    u8 *base;
    f32 sp5C[2];
    s32 add;
    u32 s0v;
    s32 sp50;
    f32 sp4C;
    f32 f2;
    s32 sp3C[3];

    base = func_80100094(param_0, 0);
    s0v = ((Data *)base)->e[param_1].x14;
    add = 0;
    sp50 = func_800E8918(s0v & 0xFF, func_800A89F8(), 0, sp5C);
    switch (sp50) {
    default:
        break;
    case -1:
        if (((Data *)base)->e[param_1].x16 != 0) {
            sp4C = 1.0f;
            f2 = 1.0f;
            if (sp5C[0] < -30.0f || sp5C[0] > 334.0f) {
                sp4C = -1.0f;
            } else if (sp5C[0] <= 0.0f && sp5C[0] >= -30.0f) {
                sp4C = func_800F10B4(sp5C[0], 0.0f, -30.0f, 1.0f, 0.0f);
            } else if (sp5C[0] >= 304.0f && sp5C[0] <= 334.0f) {
                sp4C = func_800F10B4(sp5C[0], 304.0f, 334.0f, 1.0f, 0.0f);
            }
            if (sp5C[1] < -30.0f || sp5C[1] > 258.0f) {
                f2 = -1.0f;
            } else if (sp5C[1] <= 0.0f && sp5C[1] >= -30.0f) {
                f2 = func_800F10B4(sp5C[1], 0.0f, -30.0f, 1.0f, 0.0f);
            } else if (sp5C[1] >= 228.0f && sp5C[1] <= 258.0f) {
                f2 = func_800F10B4(sp5C[1], 228.0f, 258.0f, 1.0f, 0.0f);
            }
            if (f2 != -1.0f && f2 != -1.0f) {
                add = (s32)((sp4C + f2) * 0.5f * 255.0f);
                sp50 = 1;
                break;
            }
        }
    case 0:
        add = (s32)((f32)((Data *)base)->e[param_1].x15 * 0.25f);
        if (add != 0) {
            sp50 = 1;
        }
        break;
    case 1:
        add = 0xFF;
        break;
    }
    ((Data *)base)->e[param_1].x15 = (s32)(((Data *)base)->e[param_1].x15 + add) >> 1;
    if (sp50 == 1) {
        func_800E3A58(sp3C);
        func_800DF830(0);
        func_800DF744(1, ((Data *)base)->e[param_1].x2);
        func_800DF410(((Data *)base)->e[param_1].x15);
        func_800DE498(param_2, ((Data *)base)->e[param_1].pos, sp3C, *(f32 *)(param_0 + 0x38), 0, func_800D674C(0x954));
        ((Data *)base)->e[param_1].x16 = 1;
        return;
    }
    ((Data *)base)->e[param_1].x16 = 0;
}

void func_808053BC_chdiggerboss(param_0) Actor *param_0;
{
    s32 local_0;
    s32 local_1;
    u8 local_2;
    u8 *local_3;
    u8 *local_4;

    local_3 = func_80100094(param_0, 0);
    local_3[0x24] = _subaddieaudioloop_entrypoint_3(local_3[0x24]);
    for (local_1 = 0, local_4 = local_3; local_1 != 0x70; local_1 += 0x1C, local_4 += 0x1C) {
        local_0 = *(s32 *)(local_4 + 0x30);
        if (local_0 != 0) {
            func_800C8B84(local_0);
            *(s32 *)(local_4 + 0x30) = 0;
        }
        local_2 = local_4[0x48];
        if (local_2 != 0) {
            func_800E87E0(local_2);
            local_4[0x48] = 0;
        }
    }
}

void func_80805448_chdiggerboss(param_0, param_1, param_2) u8 **param_0; s32 param_1; s32 param_2;
{
    u8 *local_0;
    s32 local_2;
    s32 local_4;

    local_0 = func_80100094(param_0, 0);
    local_2 = param_1 * 0x1C;
    local_4 = 0;
    *(s16 *)(local_0 + local_2 + 0x34) = param_2;
    switch (param_2) {
    case 0:
        func_80805960_chdiggerboss(param_0, param_1, 0);
        ((DB18 *) ((*param_0) + 0x18))->f = D_8080A068_chdiggerboss[param_1] | ((DB18 *) ((*param_0) + 0x18))->f;
        local_0[local_2 + 0x4A] = 0;
        local_0[local_2 + 0x49] = 0;
        break;
    case 1:
        func_80805960_chdiggerboss(param_0, param_1, func_800DC128(1, 5));
        ((DB18 *) ((*param_0) + 0x18))->f = (~D_8080A068_chdiggerboss[param_1]) & ((DB18 *) ((*param_0) + 0x18))->f;
        break;
    case 2:
        func_80805960_chdiggerboss(param_0, param_1, func_800DC128(1, 5));
        ((DB18 *) ((*param_0) + 0x18))->f = D_8080A068_chdiggerboss[param_1] | ((DB18 *) ((*param_0) + 0x18))->f;
        *(f32 *)(local_0 + local_2 + 0x38) = func_800DC178(0.8f, 1.2f);
        break;
    }
    for (local_2 = 0; local_2 != 0x70; local_2 += 0x1C) {
        if (*(s16 *)(local_0 + local_2 + 0x34) == 1) {
            local_4++;
        }
    }
    local_0[0x25] = (local_4 > 0);
    func_808056F8_chdiggerboss(param_0);
    if ((local_4 > 0)) {
        ((DB28h *)(*param_0 + 0x2A))->g = ((DB28 *)(*param_0 + 0x28))->g | 4;
    } else {
        ((DB28h *)(*param_0 + 0x2A))->g = ((DB28 *)(*param_0 + 0x28))->g & 0xFFFB;
    }
}

void func_808056B8_chdiggerboss(param_0) s32 param_0;
{
    u8 *sp1C;
    sp1C = func_80100094(param_0, 0);
    func_8010A570(param_0);
    *(f32 *)(sp1C + 0x2C) = 1.0f;
}

void func_808056F8_chdiggerboss(param_0) Actor *param_0;
{
    DiggerWaitState *local_0;
    s32 local_1;
    s32 local_2;
    local_0 = func_80100094(param_0, 0);
    local_1 = 0;
    if (local_0->enabled) {
        local_2 = func_80802248_chdiggerboss(func_808026F8_chdiggerboss(param_0));
        if (func_800F6478(local_2) && !func_800F8004(local_2)) {
            if (func_800D90A4(&local_0->timer)) local_1 = 1;
        } else {
            local_0->timer = 1.0f;
        }
    }
    func_8010A5B0(param_0, local_1);
}

s16 func_80805798_chdiggerboss(s32 unused, s32 param_1) {
    s8 *base;
    base = (s8 *)((u8 *)func_80100094(unused, 0) + (param_1 * 0x1C));
    return *(s16 *)(base + 0x34);
}

void func_808057D0_chdiggerboss(param_0) Actor *param_0;
{
    DiggerEffects *local_0;
    s32 local_1;
    s32 local_2;
    s32 local_3;

    local_0 = (DiggerEffects *)func_80100094(param_0, 0);
    for (local_1 = 0; local_1 < 4; local_1++) {
        local_2 = local_0->local_0[local_1].local_1 == 1 ? 1 : 0;
        local_3 = local_0->local_0[local_1].local_0;
        if (!local_3) continue;
        func_800C8FE0(local_3, local_2);
        if (local_2) {
            func_800C8CB8(local_3, local_0->local_0[local_1].local_2);
            func_800C8E84(local_3, D_8080A06C_chdiggerboss[func_8001210C(1)]);
        }
    }
}

void func_808058B0_chdiggerboss(param_0, param_1) Actor *param_0; u8 *param_1;
{
    u8 *local_0;
    f32 local_1[3];

    local_0 = func_80100094(param_0, 0);
    func_800F79DC((u32)*(u16 *)(param_1 + 0x1A) >> 5, 6, param_0->unk0);
    if (*(f32 *)(local_0 + 0x28) == 0.0f) {
        if (!_subaddiecustomhits_entrypoint_4(param_0, local_1, 0)) {
            func_800F5BF0((u32)*(u16 *)(param_1 + 0x1A) >> 5, local_1);
        }
        _chelectricfence_entrypoint_1(param_0, local_1);
        *(f32 *)(local_0 + 0x28) = 0.6f;
    }
}

void func_80805960_chdiggerboss(param_0, param_1, param_2) s32 param_0; s32 param_1; s32 param_2; {
    *(s16 *)((u8 *)func_80100094(param_0, 0) + param_1 * 0x1C + 0x36) = param_2;
}

void func_808059A4_chdiggerboss(param_0) s32 param_0; {
    u8 *temp_v0;

    temp_v0 = func_80100094(param_0, 0);
    (*(u8 *)((u8 *)(temp_v0) + 0x24)) = 0;
    (*(u8 *)((u8 *)(temp_v0) + 0x25)) = 0;
}

void func_808059CC_chdiggerboss(param_0) s32 param_0;
{
    u8 *local_0;
    u8 *local_1;

    local_1 = func_80100094(param_0, 0);
    local_0 = local_1;
    local_0[0x24] = _subaddieaudioloop_entrypoint_3(local_1[0x24]);
}

void func_80805A00_chdiggerboss(Actor *param_0, s32 param_1)
{
    DiggerBossTimerState *local_0;

    local_0 = func_80100094(param_0, 0);
    func_808027F4_chdiggerboss(param_0);
    func_80803BE8_chdiggerboss(param_0, param_1, 1);
    func_80802C0C_chdiggerboss(param_0);
    local_0->enabled = 1;
    local_0->timer = 1.5f;
}

int func_80805A64_chdiggerboss(Actor *param_0)
{
    DiggerSpin1590 *local_0;
    Actor *local_1;
    s32 local_2;
    s32 local_3;

    local_0 = func_80100094(param_0, 0);
    local_1 = (Actor *)func_80802228_chdiggerboss(param_0);
    local_2 = 0;
    func_80802C40_chdiggerboss(param_0);
    if (func_800F6D24(func_800F54E4())) return 0;
    switch (local_0->local_3) {
        case 1:
            if (func_800D9078(&local_0->local_0)) local_0->local_3 = 2;
            break;
        case 2:
            local_2 = func_800D9078(&local_0->local_1);
            local_1->rotation[1] += local_0->local_2 * func_800D8FF8();
            func_808064CC_chdiggerboss(param_0, local_2 == 0);
            func_80805B8C_chdiggerboss(param_0, local_0->local_2);
            if (local_2) {
                for (local_3 = 0; local_3 != 4; local_3++) func_80805448_chdiggerboss(local_1, local_3, 0);
                func_80802CB4_chdiggerboss(param_0);
            }
            break;
    }
    return local_2;
}

int func_80805B8C_chdiggerboss(Actor *param_0, f32 param_1)
{
  if (param_1 > 0.0f)
  {
    func_80805C1C_chdiggerboss(param_0, 0, &D_8080A084_chdiggerboss, -90.0f);
    func_80805C1C_chdiggerboss(param_0, 2, &D_8080A0A8_chdiggerboss, 90.0f);
  }
  else
  {
    func_80805C1C_chdiggerboss(param_0, 0, &D_8080A090_chdiggerboss, -90.0f);
    func_80805C1C_chdiggerboss(param_0, 2, &D_8080A09C_chdiggerboss, 90.0f);
  }
}

void func_80805C1C_chdiggerboss(Actor *param_0, f32 *param_1, f32 *param_2, f32 param_3)
{
    f32 local_0[3];
    f32 local_1[3];
    s32 local_2;
    Actor *local_3;
    if (func_800DC298(0.2f)) {
        local_3 = (Actor *)func_80802228_chdiggerboss(param_0);
        func_800EFA4C(local_0, func_800DC178(10.0f, 15.0f), local_3->rotation[1] + param_3, 0.0f);
        local_0[1] += func_800DC178(-25.0f, 25.0f);
        func_800EF934(local_1, param_2, local_3->rotation[1]);
        func_800EF04C(local_1, local_3->position);
        local_2 = func_800B53A4(1);
        func_800BABB8(local_2, local_1, NULL, 1.0f, D_8080A0B4_chdiggerboss);
        func_800BA994(local_2, (s16)local_0[0], (s16)local_0[1], 250,
            (s16)local_0[0], (s16)local_0[1], 400);
        func_800BA22C(local_2, 1);
    }
}

void func_80805D64_chdiggerboss(param_0, param_1) Actor *param_0; s32 param_1;
{
    DiggerAttackState *local_0;
    DiggerAttackMotion *local_1;
    local_0 = func_80100094(param_0, 0);
    local_1 = func_80802228_chdiggerboss(param_0);
    local_0->local_0 = 0.0f;
    local_0->local_1 = 1.5f;
    local_1->local_0 = 0.0f;
    local_0->local_2 = 1;
    func_808027F4_chdiggerboss(param_0);
    func_80802C0C_chdiggerboss(param_0);
    func_80803BE8_chdiggerboss(param_0, param_1, 1);
    func_80804A50_chdiggerboss(local_1, 2);
}

s32 func_80805DF4_chdiggerboss(param_0) Actor *param_0;
{
    char *local_0;
    char *local_1;
    s32 local_11;
    s32 local_9;
    s32 local_10;

    local_0 = (char *)func_80100094(param_0, 0);
    local_1 = (char *)func_80802228_chdiggerboss(param_0);
    local_9 = 0;
    local_10 = 0;

    func_80802C40_chdiggerboss(param_0);

    if (func_800F6D24(func_800F54E4())) {
        return 0;
    }

    local_11 = func_800D90A4(local_0 + 0x14) && func_808042D8_chdiggerboss(local_1) == 2;

    switch (*(s16 *)(local_0 + 0x28)) {
        case 1:
            if (func_800D9078(local_0 + 0x18)) {
                *(s16 *)(local_0 + 0x28) = 2;
            }
            break;

        case 2: {
            s32 local_12;

            local_12 = func_800D9078(local_0 + 0x34);

            if (local_11) {
                *(f32 *)(local_1 + 0x24) =
                    func_800F15F8(
                        *(f32 *)(local_1 + 0x24),
                        *(f32 *)(local_0 + 0x38),
                        func_800D8FF8() * 300.0f
                    );

                func_808063C8_chdiggerboss(
                    param_0,
                    0,
                    *(f32 *)(local_0 + 0x3C)
                );

                func_8010B990(local_1, 5);
            }

            if (local_12) {
                *(s16 *)(local_0 + 0x28) = 3;
            }
            break;
        }

        case 3:
            *(f32 *)(local_1 + 0x24) =
                func_800F15F8(
                    *(f32 *)(local_1 + 0x24),
                    0.0f,
                    func_800D8FF8() * 300.0f
                );

            func_808063C8_chdiggerboss(
                param_0,
                0,
                *(f32 *)(local_0 + 0x3C)
            );

            func_8010B990(local_1, 5);

            if (*(f32 *)(local_1 + 0x24) == 0.0f) {
                *(s16 *)(local_0 + 0x28) = 4;
                *(f32 *)(local_0 + 0x2C) = 360.0f;
            }
            break;

        case 4: {
            f32 local_13;

            local_13 =
                *(f32 *)(local_0 + 0x20) *
                func_800D8FF8();

            *(f32 *)(local_0 + 0x2C) -= mlAbsF(local_13);
            *(f32 *)(local_1 + 0x48) += local_13;

            func_80805B8C_chdiggerboss(
                param_0,
                *(f32 *)(local_0 + 0x20)
            );

            if (*(f32 *)(local_0 + 0x2C) < 0.0f) {
                *(s16 *)(local_0 + 0x28) = 5;
                *(f32 *)(local_0 + 0x34) =
                    *(f32 *)(local_0 + 0x30);
            } else {
                local_10 = 1;
            }
            break;
        }

        case 5: {
            s32 local_14;

            local_14 = func_800D9078(local_0 + 0x34);

            if (local_11) {
                *(f32 *)(local_1 + 0x24) =
                    func_800F15F8(
                        *(f32 *)(local_1 + 0x24),
                        *(f32 *)(local_0 + 0x38),
                        func_800D8FF8() * 300.0f
                    );

                func_808063C8_chdiggerboss(
                    param_0,
                    0,
                    *(f32 *)(local_0 + 0x3C)
                );

                func_8010B990(local_1, 5);
            }

            if (local_14) {
                *(s16 *)(local_0 + 0x28) = 6;
            }
            break;
        }

        case 6:
            *(f32 *)(local_1 + 0x24) =
                func_800F15F8(
                    *(f32 *)(local_1 + 0x24),
                    0.0f,
                    func_800D8FF8() * 300.0f
                );

            func_808063C8_chdiggerboss(
                param_0,
                0,
                *(f32 *)(local_0 + 0x3C)
            );

            func_8010B990(local_1, 5);

            if (*(f32 *)(local_1 + 0x24) == 0.0f) {
                *(s16 *)(local_0 + 0x28) = 7;
                *(f32 *)(local_0 + 0x2C) = 360.0f;
            }
            break;

        case 7: {
            f32 local_15;

            local_15 =
                *(f32 *)(local_0 + 0x20) *
                func_800D8FF8();

            *(f32 *)(local_0 + 0x2C) -= mlAbsF(local_15);
            *(f32 *)(local_1 + 0x48) += local_15;

            func_80805B8C_chdiggerboss(
                param_0,
                *(f32 *)(local_0 + 0x20)
            );

            if (*(f32 *)(local_0 + 0x2C) < 0.0f) {
                *(s16 *)(local_0 + 0x28) = 0;

                func_80802CB4_chdiggerboss(param_0);

                *(f32 *)(local_1 + 0x24) = 0.0f;

                func_80804A50_chdiggerboss(
                    local_1,
                    1
                );

                local_9 = 1;
            } else {
                local_10 = 1;
            }
            break;
        }
    }

    func_808064CC_chdiggerboss(param_0, local_10);

    {
        f32 local_2[3];
        f32 local_3[3];
        f32 local_4[3];
        f32 local_8;
        f32 local_6;
        f32 local_5;
        f32 local_7;

        func_800EFD24(local_2);
        local_2[1] = *(f32 *)(local_1 + 8);

        func_800EEB9C(
            local_3,
            *(f32 *)(local_1 + 0x48),
            1.0f
        );

        local_6 = func_800F1DF4(
            local_2,
            local_1 + 4
        );

        func_800EEB9C(
            local_4,
            local_6,
            1.0f
        );

        local_7 = func_800EEAA4(local_3, local_4);

        if (local_7 > 0.0f) {
            local_8 = 1800.0f - local_7 * 650.0f;
        } else {
            local_8 = 1800.0f - local_7 * 250.0f;
        }

        if (local_8 * local_8 <
            func_800EFC7C(local_2, local_1 + 4)) {
            local_5 = *(f32 *)(local_1 + 8);

            local_6 = func_800F1DF4(
                local_2,
                local_1 + 4
            );

            func_800EEB9C(
                local_1 + 4,
                local_6,
                local_8
            );

            *(f32 *)(local_1 + 8) = local_5;
        }
    }

    return local_9;
}

void func_808062B8_chdiggerboss(void *param_0) {
    void *sp1C;
    void *temp_v0;

    sp1C = func_80100094(param_0, 0);
    temp_v0 = func_80802228_chdiggerboss(param_0);
    (*(f32 *)((char *)sp1C + 0x14)) = 2.0f;
    (*(f32 *)((char *)temp_v0 + 0x24)) = 0.0f;
}

s32 func_80806300_chdiggerboss(Actor *param_0)
{
    DiggerBossTurn *local_0;
    f32 local_2;
    f32 local_1;

    local_0 = func_80100094(param_0, 0);
    local_1 = func_800D8FF8();
    if (local_0->local_0 == 2) return -1;
    local_2 = func_800136E4(func_8010CD50(param_0, func_80802248_chdiggerboss(param_0)) - param_0->rotation[1]);
    local_0->local_1 = func_800F1FF0(local_0->local_1, local_2, 0.1f, local_1 * 4.0f, local_1 * 100.0f);
    return func_800F20BC(local_0->local_1, local_2, 10.0f);
}

s32 func_808063C8_chdiggerboss(Actor *param_0, s32 param_1, f32 param_2)
{
    f32 local_0;
    f32 local_1;
    f32 local_3;
    f32 local_2;
    Actor *local_4;
    s32 local_5;

    local_2 = func_800D8FF8();
    local_4 = (Actor *)func_80802228_chdiggerboss(param_0);
    local_0 = func_8010CD50(param_0, func_80802248_chdiggerboss(param_0));
    local_1 = local_4->rotation[1];
    local_4->rotation[1] = func_800F1F38(local_1, local_0, local_2 * param_2);
    local_3 = func_800F1DCC(local_4->rotation[1], local_1);
    if (mlAbsF(func_800F1DCC(local_1, local_0)) > 20.0f) {
        func_80805B8C_chdiggerboss(param_0, local_3);
    }
    local_5 = func_800F20BC(local_4->rotation[1], local_0, 10.0f);
    if (param_1) {
        func_808064CC_chdiggerboss(param_0, !local_5);
    }
    return local_5;
}

void func_808064CC_chdiggerboss(param_0, param_1) u8 *param_0; s32 param_1; {
    u8 *local_0;
    u8 *local_1;

    local_1 = func_80100094(param_0, 0);
    local_0 = local_1;
    (*(s8 *)((s8 *)(local_0) + (0x24))) = _subaddieaudioloop_entrypoint_7((*(u8 *)((s8 *)(local_1) + (0x24))), param_0 + 4, param_1, &D_8080A0EC_chdiggerboss, (*(s32 *)((s8 *)(param_0) + (0x70))) & 1);
}

void func_80806528_chdiggerboss(param_0, param_1, param_2) Actor *param_0; void *param_1; void *param_2;
{
    f32 local_4;
    f32 local_0;
    u8 *local_3;
    void *local_5;
    f32 local_1;
    f32 local_2;
    local_0 = *(f32 *)((u8 *)func_80100094(param_0, 0) + 0x10);
    local_4 = 0.0f;
    func_800E0AFC(param_1, 3, 1.0f, local_4, local_0, local_4);
    func_800E0AFC(param_1, 0x5B, 1.0f, local_4, local_0, local_4);
    if (param_0->unk3C) {
        local_3 = func_80100094((Actor *)func_80802228_chdiggerboss(param_0), 0);
        if (local_3[8]) {
            local_1 = func_800E8C58(local_3[10]);
            local_5 = func_800B27E0(param_2);
            local_2 = 1.0f / _dbskeleton_entrypoint_1(local_5);
            func_800E0C20(param_1, 3, local_2, local_4, local_1, local_4);
            func_800E0C20(param_1, 0x5B, local_2, local_4, local_1, local_4);
        }
    }
}

void func_80806648_chdiggerboss(param_0) s32 param_0; {
    (*(s8 *)((s8 *)(func_80100094(param_0, 0)) + (0x78))) = 0;
}

int func_8080666C_chdiggerboss(param_0) Actor *param_0;
{
    s32 local_0 = func_80100094(param_0, 0);
    *(u8 *)(local_0 + 120) = _subaddieaudioloop_entrypoint_3(*(u8 *)(local_0 + 120));
}

s32 func_808066A0_chdiggerboss(param_0) Actor *param_0;
{
    s32 local_2;
    char *local_1;
    s16 local_4;
    s16 local_5;
    s32 local_3;
    char *local_0;

    local_0 = (char *)func_80100094(param_0, 0);
    local_1 = (char *)func_80806D84_chdiggerboss(param_0);

    func_800D2498(0x10A, *(u8 *)(local_0 + 2), 0);

    switch (*(u8 *)(local_0 + 0x5C)) {
    case 2:
        func_80806B38_chdiggerboss(param_0);
        local_2 = func_80802228_chdiggerboss(param_0);
        func_808056B8_chdiggerboss(local_2);
        break;
    case 3:
        local_2 = func_80802228_chdiggerboss(param_0);
        func_808056B8_chdiggerboss(local_2);
        if (func_800D9078(local_0 + 0x60)) {
            func_80109FE8(param_0, 1);
            *(u8 *)(local_0 + 0x5C) = 4;
        }
        break;
    case 4:
        func_80108B04(param_0, 0);
        break;
    case 5:
        if (local_1 != 0) {
            if (_subaddieskeleton_entrypoint_0(param_0, 0x1E, local_1 + 4)) {
                func_800EF1B8(local_1 + 4, (*((f32 *) (local_0 + 0x10))) + (*((f32 *) (((char *) param_0) + 0x48))), 80.0f);
            }
        }
        if (func_80101E14(param_0, 0.33f)) {
            if (*(u8 *)(local_0 + 0x41) != 0) {
                local_4 = *(s16 *)(local_0 + 0x6A);
            } else {
                local_4 = *(s16 *)(local_0 + 0x6C);
            }
            local_5 = func_80802248_chdiggerboss(param_0);
            func_8010108C(local_1, 0xA, (local_5 << 16) | ((u16)local_4));
            *(s32 *)(local_0 + 0x64) = 0;
        }
        if (func_80101DDC(param_0)) {
            if (*(u8 *)(local_0 + 0x5E) == 0) {
                if (--*(u8 *)(local_0 + 0x5D) == 0) {
                    *(u8 *)(local_0 + 0x5C) = 8;
                    *(f32 *)(local_0 + 0x60) = 1.0f;
                    break;
                }
                func_80800180_chdiggerboss(param_0, 8);
                *(u8 *)(local_0 + 0x5C) = 6;
                *(u8 *)(local_0 + 0x5E) = 3;
                *(f32 *)(local_0 + 0x60) = *(f32 *)(local_0 + 0x74);
            } else {
                func_80800180_chdiggerboss(param_0, 8);
                *(u8 *)(local_0 + 0x5C) = 6;
                *(f32 *)(local_0 + 0x60) = *(f32 *)(local_0 + 0x70);
            }
            break;
        }
        break;
    case 6:
        if (*(u8 *)(local_0 + 0x69) == *(u8 *)(local_0 + 2)) {
            *(u8 *)(local_0 + 0x5C) = 8;
            *(f32 *)(local_0 + 0x60) = 1.0f;
        } else if (func_800D9078(local_0 + 0x60)) {
            *(u8 *)(local_0 + 0x5C) = 4;
        }
        break;
    case 7:
        if (!func_80101DDC(param_0)) {
            break;
        }
        if (*(u8 *)(local_0 + 0x69) == *(u8 *)(local_0 + 2)) {
            *(u8 *)(local_0 + 0x5C) = 8;
            *(f32 *)(local_0 + 0x60) = 1.0f;
        } else if (*(u8 *)(local_0 + 0x5E) == 0) {
            if (*(u8 *)(local_0 + 0x5D) == 0) {
                *(u8 *)(local_0 + 0x5C) = 8;
                *(f32 *)(local_0 + 0x60) = 1.0f;
            } else {
                *(u8 *)(local_0 + 0x5C) = 4;
            }
        } else {
            *(u8 *)(local_0 + 0x5C) = 4;
        }
        break;
    case 8:
        if (_subaddiefind_entrypoint_2(0x4F2, 0) != 0) {
            break;
        }
        if (!func_800D9078(local_0 + 0x60)) {
            break;
        }
        func_80109FE8(param_0, 0);
        if (*(u8 *)(local_0 + 0x5F) != 0 && *(u8 *)(local_0 + 0x69) != *(u8 *)(local_0 + 2)) {
            *(u8 *)(local_0 + 0x5C) = 0;
            return 1;
        }
        local_3 = _plsu_entrypoint_1(0x11);
        if (local_3 != -1) {
            *(u8 *)(local_0 + 0x5C) = 9;
            func_800F7B9C(local_3, 0x8E);
            break;
        } else {
            func_80806C08_chdiggerboss(param_0);
            return 0;
        }
    case 10:
        local_2 = func_80802228_chdiggerboss(param_0);
        func_808056B8_chdiggerboss(local_2);
        func_80806C08_chdiggerboss(param_0);
        break;
    case 11:
        local_2 = func_80802228_chdiggerboss(param_0);
        func_808056B8_chdiggerboss(local_2);
        if (!func_800D9078(local_0 + 0x60)) {
            break;
        }
        *(u8 *)(local_0 + 0x5C) = 0;
        if (*(u8 *)(local_0 + 0x69) == *(u8 *)(local_0 + 2)) {
            func_80806F8C_chdiggerboss(param_0);
            func_80806EE4_chdiggerboss(param_0, 0);
            return 2;
        }
        return 1;
    }
    return 0;
}

void func_80806A78_chdiggerboss(param_0, param_1, param_2) s32 param_0; s32 param_1; u8 *param_2;
{
    Actor *local_0;
    local_0 = func_80100094(param_0, 0);
    rare_memcpy((u8 *)local_0 + 0x68, param_2, 0x10);
    *(u8 *)((u8 *)local_0 + 0x5E) = 3;
    *(f32 *)((u8 *)local_0 + 0x60) = 1.75f;
    *(u8 *)((u8 *)local_0 + 0x5D) = *param_2;
    func_80803BE8_chdiggerboss(param_0, param_1, 8);
    func_808027F4_chdiggerboss(param_0);
    if (func_800F5410(func_800F54E4()) == 0x11)
    {
        *(u8 *)((u8 *)local_0 + 0x5C) = 1;
        func_800F7B9C(func_800F54E4(), 0x8E);
    }
    else
    {
        func_80806B38_chdiggerboss(param_0);
    }
}

void func_80806B38_chdiggerboss(param_0) Actor *param_0;
{
    DiggerPlayerCommand *local_0;
    f32 local_1[3];
    f32 local_2[3];
    s32 local_3;

    local_0 = func_80100094(param_0, 0);
    if (local_0->local_2 || local_0->local_0) {
        local_0->local_1 = 3;
        local_0->local_3 = 0.15f;
    } else {
        local_3 = func_80802248_chdiggerboss(param_0);
        local_0->local_1 = 3;
        local_0->local_3 = 1.75f;
        func_800F5A00(local_3, local_1);
        func_800EFA4C(local_2, 0.0f, func_800F1DF4(local_1, param_0->position), 0.0f);
        func_800F8444(local_3, local_2);
        func_800F7C58(local_3, 0x61, 1);
    }
}

void func_80806C08_chdiggerboss(param_0) Actor *param_0;
{
    u8 *local_1;
    s32 local_0;

    local_1 = func_80100094(param_0, 0);
    local_0 = func_80802248_chdiggerboss(param_0);
    if (local_1[4] != 0) {
        local_1[0x5C] = 0xB;
        *(f32 *)(local_1 + 0x60) = 0.15f;
        return;
    }
    func_800F7B9C(local_0, 0x63);
    func_800F7C58(local_0, 0x61, 2);
    func_80802878_chdiggerboss(param_0, 5, 1);
    local_1[0x5C] = 0xB;
    *(f32 *)(local_1 + 0x60) = 1.0f;
}

void func_80806CA4_chdiggerboss(s32 param_0, s32 param_1)
{
    void *local_0 = func_80100094(param_0, 0);
    switch (*(u8 *)((char *)local_0 + 0x5C))
    {
        case 1 :
            *(u8 *)((char *)local_0 + 0x5C) = 2;
            break;

        case 9 :
            *(u8 *)((char *)local_0 + 0x5C) = 10;

    }

}

void func_80806CF8_chdiggerboss(Actor *param_0, s32 param_1)
{
    u8 *local_0;
    Actor *local_1;
    local_0 = func_80100094(param_0, 0);
    if (!param_1) {
        local_1 = func_801084B0(0x4F2, &param_0);
        _subaddieskeleton_entrypoint_0(param_0, 0x1E, local_1->position);
        *(Unk80132ED0 **)(local_0 + 0x64) = local_1->unk0;
        local_0[0x5C] = 5;
        if (local_0[0x5E] > 0) local_0[0x5E]--;
        func_80800180_chdiggerboss(param_0, 7);
    }
}

s32 func_80806D84_chdiggerboss(s32 param_0)
{
    u8 *temp_v0;

    temp_v0 = func_80100094(param_0, 0);
    if (*(s32 *)((s8 *)temp_v0 + 0x64) != 0)
    {
        return func_80106790(*(s32 *)((s8 *)temp_v0 + 0x64));
    }
    return 0;
}

void func_80806DC4_chdiggerboss(Actor *param_0, u8 *param_1)
{
    s32 local_1;
    u8 *local_2;
    f32 local_0[3];
    local_2 = func_80100094(param_0, 0);
    switch (*(u32 *)(param_1 + 0x24) >> 22) {
    case 0x26C: local_1 = 1; break;
    case 0x26D: case 0x26E: local_1 = 2; break;
    case 0x26F: local_1 = 3; break;
    default: return;
    }
    local_2[2] = func_800F0E28(local_2[2] - local_1, local_2[0x69]);
    local_2[0x78] = func_80806F10_chdiggerboss(param_0, local_2[0x78]);
    if (local_2[0x69] == local_2[2]) func_80109FE8(param_0, 0);
    func_80802298_chdiggerboss(param_0, local_0);
    func_8010963C(param_0, local_0, param_1);
    switch (local_2[0x5C]) {
    case 4: case 7: break;
    case 5: if (*(s32 *)(local_2 + 0x64)) break;
    default:
        func_80800180_chdiggerboss(param_0, 9);
        local_2[0x5C] = 7;
        break;
    }
}

void func_80806EE4_chdiggerboss(s32 unused, s32 param_1) {
    s8 *local_0;
    local_0 = func_80100094(unused, 0);
    local_0[0x5F] = (s8) param_1;
}

u8 func_80806F10_chdiggerboss(param_0, param_1) Actor *param_0; u8 param_1;
{
    if ((*(u8 *)&param_1) == 0) {
        (*(u8 *)&param_1) = _subaddieaudioquick_entrypoint_1(param_0, param_0->position);
    }
    func_800C4B7C(D_8080A11C_chdiggerboss[func_800DC128(0, 2)]);
    func_800C4350((*(u8 *)&param_1), param_0->position, D_8080A104_chdiggerboss);
    return (*(u8 *)&param_1);
}

void func_80806F8C_chdiggerboss(Actor *param_0)
{
    f32 local_0[3];
    f32 local_1;
    f32 local_2;
    f32 local_3;
    u8 *local_5;

    local_1 = 0.0f;
    local_5 = (u8 *)func_80802228_chdiggerboss(param_0);
    func_80802298_chdiggerboss(param_0, local_0);
    if (!func_800F1E6C(local_0, D_8080A134_chdiggerboss, &local_3)) {
        local_3 = 0.0f;
    }
    if (func_800F2094(*(f32 *)(local_5 + 0x48) + 90.0f, local_3) <
        func_800F2094(*(f32 *)(local_5 + 0x48) - 90.0f, local_3)) {
        local_2 = *(f32 *)(local_5 + 0x48) + 90.0f;
    } else {
        local_2 = *(f32 *)(local_5 + 0x48) - 90.0f;
    }
    _chbounce_entrypoint_3(func_800DC178(-30.0f, 30.0f) + local_2);
    _chbaddiesetup_entrypoint_5(_chbaddiesetup_entrypoint_10, 0x21,
        ((s32 *)local_0)[0], ((s32 *)local_0)[1], ((s32 *)local_0)[2], *(s32 *)&local_1);
    _subaddieaudioquick_entrypoint_2(param_0, param_0->position, D_8080A120_chdiggerboss);
}

s32 func_808070B0_chdiggerboss(param_0) Actor *param_0;
{
    u8 *local_0;
    void *local_1;
    void *local_2;

    local_0 = func_80100094(param_0, 0);
    func_80802C40_chdiggerboss(param_0);
    switch (*(s16 *)(local_0 + 0x7C)) {
    case 1:
        if (func_800D9078(local_0 + 0x84)) {
            *(s16 *)(local_0 + 0x7C) = 2;
        }
        break;
    case 2:
        if (func_808063C8_chdiggerboss(param_0, 1, 80.0f)) {
            local_1 = func_80802228_chdiggerboss(param_0);
            if (func_8080761C_chdiggerboss(param_0)) {
                func_808008C0_chdiggerboss(local_1, 3, 1);
                func_808008C0_chdiggerboss(local_1, 4, 1);
                func_8080041C_chdiggerboss(local_1, 0x11);
            } else {
                func_808008C0_chdiggerboss(local_1, 3, 1);
                func_8080041C_chdiggerboss(local_1, 15);
            }
            *(s16 *)(local_0 + 0x7C) = 3;
        }
        break;
    case 3:
        local_2 = func_80802228_chdiggerboss(param_0);
        func_808063C8_chdiggerboss(param_0, 1, 80.0f);
        if (func_80101E14(local_2, 0.14f)) {
            func_80108B04(param_0, 1);
        }
        if (func_8080761C_chdiggerboss(param_0) && func_80101E14(local_2, 0.28f)) {
            func_80108B04(param_0, 2);
        }
        break;
    case 4:
        if (func_800D9078(local_0 + 0x84)) {
            *(s16 *)(local_0 + 0x7C) = 2;
        }
        break;
    case 5:
        if (!_subaddiefind_entrypoint_2(0x4F3, 0)
            && !_subaddiefind_entrypoint_2(0x4F4, 0)) {
            *(s16 *)(local_0 + 0x7C) = 0;
            func_80802CB4_chdiggerboss(param_0);
            return 1;
        }
        break;
    }
    return 0;
}

void func_80807280_chdiggerboss(param_0, param_1, param_2) Actor *param_0; s32 param_1; s16 *param_2;
{
    DiggerBossPose61 *local_0;

    local_0 = func_80100094(param_0, 0);
    rare_memcpy(local_0->local_3, param_2, 0x10);
    func_808027F4_chdiggerboss(param_0);
    func_80802C0C_chdiggerboss(param_0);
    func_80803BE8_chdiggerboss(param_0, param_1, 1);
    local_0->local_2 = 1.5f;
    local_0->local_0 = 1;
    local_0->local_1 = *param_2;
}

void func_80807304_chdiggerboss(param_0, param_1) Actor *param_0; s32 param_1;
{
    DiggerProjectileState *local_0;
    Actor *local_1;
    Actor *local_2;
    s32 local_3;
    Vec3f local_4;
    Vec3f local_5;
    f32 local_6;
    f32 local_7;
    f32 local_8;
    f32 local_9;

    local_0 = func_80100094(param_0, 0);
    local_1 = (Actor *)func_80802228_chdiggerboss(param_0);
    local_3 = func_80802248_chdiggerboss(param_0);
    if (func_8080761C_chdiggerboss(param_0)) {
        local_6 = func_8010CD50(param_0, local_3);
        local_7 = local_0->local_3;
        local_8 = local_0->local_4;
        local_9 = param_1 == 2 ? -90.0f : 90.0f;
        func_8010D09C(local_3, local_5.f, 0.0);
        func_800EF1B8(local_5.f, func_800DC178(-80.0f, 80.0f) + (local_6 + local_9),
            func_800DC178(local_7, local_8));
    } else {
        func_8010D09C(local_3, local_5.f, 0.0);
    }
    local_5.pos.y = 0.0f;
    if (func_800EEFD4(local_5.f) > 3240000.0f) {
        func_800EF368(local_5.f, 1800.0f);
    }
    local_5.pos.y = param_0->position[1];
    switch (param_1) {
    case 1:
        func_808008C0_chdiggerboss(local_1, 3, 0);
        _subaddieskeleton_entrypoint_2(local_1->unk0, 11, local_4.f);
        local_2 = func_80108528(0x4F3, local_4.f, 0, &param_0);
        func_800EE7F8((f32 *)local_2->actorData, local_5.f);
        func_80102FDC(local_2, 0.25f);
        local_2->unk54 = 0.0f;
        ((f32 *)local_2->actorData)[3] = func_800DC178(local_0->local_6, local_0->local_7);
        _subaddieaudioquick_entrypoint_2(param_0, param_0->position, D_8080A140_chdiggerboss);
        if (local_0->local_1 > 0) {
            local_0->local_1 = local_0->local_1 - 1;
        }
        break;
    case 2:
        func_808008C0_chdiggerboss(local_1, 4, 0);
        _subaddieskeleton_entrypoint_2(local_1->unk0, 10, local_4.f);
        local_2 = func_80108528(0x4F3, local_4.f, 0, &param_0);
        func_800EE7F8((f32 *)local_2->actorData, local_5.f);
        func_80102FDC(local_2, 0.25f);
        local_2->unk54 = 45.0f;
        ((f32 *)local_2->actorData)[3] = func_800DC178(local_0->local_6, local_0->local_7);
        _subaddieaudioquick_entrypoint_2(param_0, param_0->position, D_8080A140_chdiggerboss);
        break;
    }
    if (!func_8080761C_chdiggerboss(param_0) || param_1 == 2) {
        if (local_0->local_1 == 0) {
            local_0->local_0 = 5;
        } else {
            local_0->local_0 = 4;
            local_0->local_2 = local_0->local_5;
        }
    }
}

s16 func_8080761C_chdiggerboss(s32 param_0)
{
    return *(s16 *)((char *)func_80100094(param_0, 0) + 0x80);
}

void func_80807640_chdiggerboss(param_0) s32 param_0; {
    s8 *var_a0 = func_80100094(param_0, 0);
    var_a0[0xA0] = 0;
}

void func_80807664_chdiggerboss(param_0) s32 param_0;
{
    u8 *local_0;
    u8 *local_1;

    local_1 = func_80100094(param_0, 0);
    local_0 = local_1;
    *(s8 *)((char *)local_0 + 0xA0) = _subaddieaudioloop_entrypoint_3(*(u8 *)((char *)local_1 + 0xA0));
}

void func_80807698_chdiggerboss(param_0, param_1) Actor *param_0; s32 param_1;
{
    s32 local_2;
    u8 *local_0;
    struct DiggerAttackMotion *local_1;
    s32 local_3;

    local_0 = func_80100094(param_0, 0);
    local_1 = func_80802228_chdiggerboss(param_0);
    local_2 = param_1 ? 1 : (local_0[0xA3] ? 1 : 0);
    for (local_3 = 0; local_3 != 4; local_3++) {
        if (local_0[0xA2] & (1 << local_3)) {
            func_80805448_chdiggerboss(local_1, local_3, local_2);
        }
    }
}

void func_80807754_chdiggerboss(Actor *param_0, s32 param_1, f32 param_2)
{
    u8 *local_0;
    s32 local_1;
    s32 local_2;

    local_0 = func_80100094(param_0, 0);
    local_1 = (s32)func_80802228_chdiggerboss(param_0);
    *(f32 *)(local_0 + 0x98) = param_2;
    *(f32 *)(local_0 + 0x9C) = 2.0f;
    local_0[0xA3] = 1;
    local_0[0xA2] = 0;
    local_2 = 0;
    do {
        if (func_80805798_chdiggerboss(local_1, local_2)) {
            local_0[0xA2] |= 1 << local_2;
        }
        local_2++;
    } while (local_2 != 4);
    func_808027F4_chdiggerboss(param_0);
    func_80803BE8_chdiggerboss(param_0, param_1, 1);
    func_808041E4_chdiggerboss(func_80802228_chdiggerboss(param_0), 3);
}

s32 func_8080783C_chdiggerboss(param_0, param_1) Actor *param_0; s32 param_1;
{
    DiggerBossData *local_0;
    Actor *local_1;
    f32 local_2[3];
    s32 local_3;
    Actor *local_4;
    s32 local_5;

    local_0 = func_80100094(param_0, 0);
    local_1 = func_80802228_chdiggerboss(param_0);
    local_5 = func_80802314_chdiggerboss();
    func_800D2498(0x10B, local_5, 0);
    if (func_800F64A4(func_800F54E4(), 0x10000)) {
        local_4 = func_80802228_chdiggerboss(param_0);
        if (_subaddieskeleton_entrypoint_2(local_4->unk0, 7, local_2) && func_8010CFBC(local_2, 0, 50)) {
            local_0->unkA0 = 1;
            param_0->unk74_17 = local_0->unkA0;
            func_800FE850();
            _gcgoto_entrypoint_1(0x18A, 1);
        }
    }
    switch (local_0->unkA3) {
    case 0:
        if (func_800D9078(&local_0->unk9C)) {
            for (local_3 = 0; local_3 < 4; local_3++) {
                if (local_0->unkA2 & (1 << local_3)) {
                    func_80805448_chdiggerboss(local_1, local_3, 1);
                }
            }
            local_0->unkA3 = 1;
            local_0->unk9C = 2.0f;
        }
        break;
    case 1:
        if (func_800D9078(&local_0->unk9C)) {
            for (local_3 = 0; local_3 < 4; local_3++) {
                if (local_0->unkA2 & (1 << local_3)) {
                    func_80805448_chdiggerboss(local_1, local_3, 0);
                }
            }
            local_0->unk9C = 0.8f;
            local_0->unkA3 = 2;
        }
        break;
    case 2:
        for (local_3 = 0; local_3 < 4; local_3++) {
            if (local_0->unkA2 & (1 << local_3)) {
                func_80805448_chdiggerboss(local_1, local_3, func_800DC298(0.5f) ? 0 : 1);
            }
        }
        if (func_800D9078(&local_0->unk9C)) {
            for (local_3 = 0; local_3 < 4; local_3++) {
                if (local_0->unkA2 & (1 << local_3)) {
                    func_80805448_chdiggerboss(local_1, local_3, 0);
                }
            }
            local_0->unkA3 = 0;
            local_0->unk9C = 2.0f;
        }
        break;
    }
    if (func_800D90A4(&local_0->unk98) && local_0->unkA0 == 0) {
        if (!func_80802170_chdiggerboss(param_0, 10)) {
            func_80803660_chdiggerboss(param_0, 0x1728, 0x106);
        }
        func_808041E4_chdiggerboss(func_80802228_chdiggerboss(param_0), 2);
        func_80805D64_chdiggerboss(param_0, param_1);
        return 1;
    }
    return 0;
}

void func_80807B18_chdiggerboss(param_0) s32 param_0; {
    u8 *temp_v0;

    temp_v0 = func_80100094(param_0, 0);
    (*(s8 *)((s8 *)(temp_v0) + (0xA4))) = 0;
    (*(s32 *)((s8 *)(temp_v0) + (0xC8))) = 0;
    (*(s8 *)((s8 *)(temp_v0) + (0xA6))) = 0;
    (*(s8 *)((s8 *)(temp_v0) + (0xA7))) = 4;
}

void func_80807B4C_chdiggerboss(s32 arg0) 
{
}
void func_80807B54_chdiggerboss(param_0) Actor *param_0;
{
    f32 local_0;
    s32 local_1;
    Actor *local_2;
    f32 local_3;
    s32 local_4;
    s32 local_5;
    Actor *local_6;
    u8 *local_7;

    local_7 = func_80100094(param_0, 0);
    switch (local_7[0xA4]) {
    case 0:
        if (local_7[0xA5] && _subaddiefind_entrypoint_9(0x131) < local_7[0xA6]) {
            local_7[0xA4] = 1;
            func_80108B04(param_0, 4);
        }
        break;
    case 1:
        break;
    case 2:
        local_1 = func_800D9078((f32 *)(local_7 + 0xC4));
        local_2 = func_80106790(*(u32 *)(local_7 + 0xC8));
        local_3 = func_800F10B4(*(f32 *)(local_7 + 0xC4), 0.0f, 1.0f, 1.0f, 0.0f);
        func_800EFE50(local_2->position, (f32 *)(local_7 + 0xB4), (f32 *)(local_7 + 0xA8), local_3);
        local_0 = func_8001395C(local_3 * 3.141592741f);
        local_2->position[1] += local_0 * 500.0f;
        local_4 = func_800F54E4();
        func_800F4F34(local_4, local_2->position, local_2->scale * 90.0f, local_2->scale * 100.0f);
        if (local_1) {
            func_800B4470(local_2->position, 0, D_8080A150_chdiggerboss, 1, 0.8f, 0.0f, 100, 150, 0);
            func_800C4104(0x419, 1.0f, 28000, local_2->position, 1200.0f, 8000.0f);
            local_2->unk64_20 = 1;
            local_7[0xA4] = 3;
        }
        break;
    case 3:
        _sucoaster_entrypoint_4(func_80106790(*(u32 *)(local_7 + 0xC8)));
        if (local_7[0xA5]) local_7[0xA4] = 0;
        else local_7[0xA4] = 4;
        *(u32 *)(local_7 + 0xC8) = 0;
        break;
    case 4:
        if (local_7[0xA7]) local_7[0xA7]--;
        else {
            local_6 = _subaddiefind_entrypoint_2(0x131, &local_5);
            while (local_6) {
                func_8010108C(local_6, 0x9A, 0);
                local_6 = _subaddiefind_entrypoint_3(0x131, &local_5);
            }
            local_7[0xA4] = 0;
        }
        break;
    }
}

void func_80807DC0_chdiggerboss(s32 param_0, s32 param_1)
{
    void *local_0 = func_80100094(param_0, 0);
    *(u8 *)((u8 *)local_0 + 0xA5) = 1;
    *(u8 *)((u8 *)local_0 + 0xA6) = param_1;
}

int func_80807DF4_chdiggerboss(s32 param_0)
{
    u8 *local_0;
    local_0 = (u8 *)func_80100094(param_0, 0);
  *(u8 *)((char *)(local_0) + 0xA5) = 0;

    switch (local_0[0xA4])
    {
        case 1:
        case 2:
        case 3:
            break;

        default:
            local_0[0xA4] = 4;
    }
}

void func_80807E3C_chdiggerboss(param_0, param_1) Actor *param_0; s32 param_1;
{
    u8 *local_5;
    f32 local_4;
    f32 local_0[2];
    Actor *local_1;
    s32 local_2;
    f32 local_x;
    f32 local_3;

    local_5 = func_80100094(param_0, 0);
    if (param_1 == 4) {
        local_2 = func_80802248_chdiggerboss(param_0);
        func_800EFD24(local_0);
        if (!func_800F1E6C(param_0->position, local_0, (f32 *)(local_5 + 0xC0))) {
            local_3 = func_8010CD50(param_0, local_2);
            if (func_800DC298(0.5f)) {
                local_4 = 1.0f;
            } else {
                local_4 = -1.0f;
            }
            *(f32 *)(local_5 + 0xC0) = local_4 * 45.0f + local_3;
        }
        func_800EE7F8((f32 *)(local_5 + 0xB4), param_0->position);
        *(f32 *)(local_5 + 0xB8) += 500.0f;
        func_800EE7F8((f32 *)(local_5 + 0xA8), param_0->position);
        func_800EF1B8((f32 *)(local_5 + 0xA8), *(f32 *)(local_5 + 0xC0), 600.0f);
        local_1 = func_80108528(0x131, (f32 *)(local_5 + 0xB4), (s32)*(f32 *)(local_5 + 0xC0), &param_0);
        ((u8 *)local_1)[0x75] &= ~2;
        local_1->rotation[1] = *(f32 *)(local_5 + 0xC0);
        local_x = func_800DC178(1.2f, 1.6f);
        func_80102FDC(local_1, local_x);
        *(void **)(local_5 + 0xC8) = local_1->unk0;
        *(f32 *)(local_5 + 0xC4) = 1.0f;
        local_5[0xA4] = 2;
        _subaddieaudioquick_entrypoint_2(param_0, param_0->position, D_8080A154_chdiggerboss);
    }
}

void func_80807FD8_chdiggerboss(param_0) s32 param_0;
{
    u8 *local_0;

    local_0 = func_80100094(param_0, 0);
    *(s32 *)((char *)local_0 + 0xA8) = 0;
    *(s8 *)((char *)local_0 + 0xA6) = 0;
}

void func_80808000_chdiggerboss(param_0) s32 param_0; {
    u8 *local_0;
    u8 *local_1;

    local_1 = func_80100094(param_0, 0);
    local_0 = local_1;
    local_0[0xA6] = _subaddieaudioloop_entrypoint_3(local_1[0xA6]);
}

void func_80808034_chdiggerboss(param_0) Actor *param_0;
{
    u8 *local_0;
    s32 local_1;
    local_0 = func_80100094(param_0, 0);
    local_1 = 0;
    if (*(s16 *)(local_0 + 0xA4) == 1) {
        local_1 = 1;
        if (func_8001210C(1)) func_808081AC_chdiggerboss(param_0);
    }
    local_0[0xA6] = _subaddieaudioloop_entrypoint_7(local_0[0xA6], param_0->position, local_1,
        D_8080A160_chdiggerboss, ((u32 *)param_0)[0x1C] & 1);
}

void func_808080C0_chdiggerboss(Actor *param_0, s32 param_1)
{
    DiggerCameraState61 *local_0;
    s32 local_1;

    local_1 = param_1;
    local_0 = func_80100094(param_0, 0);
    local_0->local_0 = local_1;
    switch (local_1) {
    case 0:
        if (local_0->local_1 != NULL) {
            func_8010114C(local_0->local_1, 0x4F, 0);
            local_0->local_1 = NULL;
        }
        break;
    case 2:
        if (local_0->local_1 == NULL) {
            func_80108B04(param_0, 3);
        }
        break;
    case 1:
        break;
    }
}

void func_8080815C_chdiggerboss(param_0, param_1) s32 param_0; s32 param_1; {
    u8 *temp_v0;
    u8 *sp1C;
    s32 *temp_v1;

    temp_v0 = func_80100094(param_0, 0);
    if (param_1 == 3) {
        sp1C = temp_v0;
        temp_v1 = func_801084B0(0x178, &param_0);
        *(s32 *)((char *)sp1C + 0xA8) = *temp_v1;
    }
}

void func_808081AC_chdiggerboss(param_0) Actor *param_0;
{
    f32 local_1[3];
    f32 local_0[3];

    func_800EE7F8(local_0, param_0->position);
    func_800EF1B8(local_0, param_0->rotation[1], -80.0f);
    local_0[1] += 80.0f;
    func_800EE7F8(local_1, local_0);
    func_800EF1B8(local_1, param_0->rotation[1] + 90.0f, 200.0f);
    func_800BBCB8(local_1, param_0->position, 1.0f, 1, D_8080A16C_chdiggerboss);
}

void func_80808258_chdiggerboss(param_0) Actor *param_0;
{
    u8 *local_0;
    Actor *local_1;
    Actor *local_x;
    Actor *local_2;
    s16 local_y;
    s16 local_3;

    local_0 = func_80100094(param_0, 0);
    func_800D2498(0x10A, local_0[2], 0);
    func_808087F0_chdiggerboss(param_0);
    switch (local_0[0xCC]) {
    case 0:
        break;
    case 1:
        func_80108B04(param_0, 5);
        break;
    case 2:
        local_1 = func_808086A8_chdiggerboss(param_0);
        if (local_1) {
            func_80102FDC(local_1, func_800F10B4(func_80101F24(param_0),
                0.0f, 1.0f, 0.1f, 0.8f));
        }
        if (func_80101DDC(param_0)) {
            if (local_0[0xCD]) {
                func_80808560_chdiggerboss(param_0);
                return;
            }
            func_80800180_chdiggerboss(param_0, 0xB);
            local_0[0xCC] = 3;
        }
        break;
    case 3:
        if (local_0[0xCD]) func_80808560_chdiggerboss(param_0);
        break;
    case 4:
        if (func_800D9078((f32 *)(local_0 + 0xD0))) {
            func_80800180_chdiggerboss(param_0, 0xC);
            local_0[0xCC] = 5;
        }
        break;
    case 5:
        local_2 = func_808086A8_chdiggerboss(param_0);
        if (func_80101E14(param_0, 0.33f)) {
            local_3 = func_80802248_chdiggerboss(param_0);
            func_8010105C(800.0f);
            func_8010108C(local_2, 0xA, (local_3 << 16) | 0xDAC);
            *((s32 *)(local_0 + 0xD4)) = 0;
        }
        if (func_80101DDC(param_0)) {
            func_80800180_chdiggerboss(param_0, 8);
            local_0[0xCC] = 1;
            *((f32 *)(local_0 + 0xD0)) = 0.5f;
        }
        break;
    }
}

void func_8080843C_chdiggerboss(param_0) s32 param_0;
{
  Actor *local_0;
  u8 local_1;

  local_0 = func_80100094(param_0, 0);
  local_1 = local_0->unk78;
  local_0->unk78 = _subaddieaudioloop_entrypoint_3(local_1);
}

void func_80808470_chdiggerboss(Actor *param_0, s32 param_1)
{
    u8 *local_3;
    s32 local_0;
    f32 local_1[3];
    f32 local_2[3];

    local_3 = func_80100094(param_0, 0);
    local_0 = func_80802248_chdiggerboss(param_0);
    local_3[3] = 1;
    local_3[0xD8] = 0;
    func_80803BE8_chdiggerboss(param_0, param_1, 8);
    func_800F5A00(local_0, local_1);
    func_800EFA4C(local_2, 0.0f, func_800F1DF4(local_1, param_0->position), 0.0f);
    func_800F8444(local_0, local_2);
    if (!func_808021E8_chdiggerboss(param_0, 11)) {
        func_80802878_chdiggerboss(param_0, 3, 1);
        func_80803660_chdiggerboss(param_0, 0x172D, 0x10E);
        local_3[0xCC] = 1;
    } else {
        func_80109FE8(param_0, 1);
        local_3[0xCC] = 1;
    }
}

DiggerPhase59 *func_80808560_chdiggerboss(Actor *param_0)
{
    DiggerPhase59 *local_0;

    local_0 = func_80100094(param_0, 0);
    func_80102FDC(func_808086A8_chdiggerboss(param_0), 0.800000012f);
    func_80800180_chdiggerboss(param_0, 0xB);
    func_808027F4_chdiggerboss(param_0);
    func_80109FE8(param_0, 1);
    local_0->local_0 = 4;
    local_0->local_1 = 0.5f;
    return local_0;
}

int func_808085E0_chdiggerboss(s32 param_0, s32 param_1)
{
  Actor *local_0;
  Actor *local_1;
  local_0 = func_80100094(param_0, 0);
  if (param_1 == 5)
  {
    local_1 = func_801084B0(1270, &param_0);
    *(s32 *)((char *)(local_0) + 0xD4) = *(s32 *)((char *)(local_1) + 0x0);
    func_808087F0_chdiggerboss(param_0);
    if (!func_80802170_chdiggerboss(param_0, 11))
    {
      func_80102FDC(local_1, 0.100000001f);
      func_80800180_chdiggerboss(param_0, 10);
      (*(u8 *)((char *)(local_0) + 0xCC)) = 2;
    }
    else
    {
      func_80102FDC(local_1, 0.800000012f);
      func_80800180_chdiggerboss(param_0, 11);
      (*(u8 *)((char *)(local_0) + 0xCC)) = 4;
      (*(f32 *)((char *)(local_0) + 0xD0)) = 0.5f;
    }
  }
}

s32 func_808086A8_chdiggerboss(param_0) s32 param_0;
{
    u8 *temp_v0;

    temp_v0 = func_80100094(param_0, 0);
    if ((*(s32 *)((s8 *)(temp_v0) + (0xD4))) != 0)
    {
        return func_80106790((*(s32 *)((s8 *)(temp_v0) + (0xD4))));
    }
    return 0;
}

void func_808086E8_chdiggerboss(u8 *param_0, u8 *param_1) {
    u32 temp_t8;
    u8 *temp_v0;
    u8 *s0;
    u8 *s1;

    s0 = param_0;
    temp_v0 = func_80100094(param_0, 0);
    s1 = temp_v0;
    (*(u8 *)((s8 *)(s1) + 0xD8)) = func_80806F10_chdiggerboss(s0, (*(u8 *)((s8 *)(s1) + 0xD8)));
    if (((*(s32 *)((s8 *)(s1) + 0xD4)) != 0) && ((temp_t8 = (u32) (*(u32 *)((s8 *)(param_1) + 0x24)) >> 0x16, (temp_t8 == 0x26C)) || (temp_t8 == 0x26D) || (temp_t8 == 0x26E) || (temp_t8 == 0x26F))) {
        func_80109FE8(s0, 0);
        func_80803BE8_chdiggerboss(s0, 0x41, 0xD);
        func_80802878_chdiggerboss(s0, 3, 1);
        func_80803660_chdiggerboss(s0, 0x1735, 0x14C);
        func_800F7B9C(func_80802248_chdiggerboss(s0), 0x63);
        func_8010114C((*(s32 *)((s8 *)(s1) + 0xD4)), 0x9B, (s32) ((*(f32 *)((s8 *)(s0) + 8)) + 200.0f));
        (*(s32 *)((s8 *)(s1) + 0xD4)) = 0;
        (*(s8 *)((s8 *)(s1) + 0xCC)) = 0;
        (*(s8 *)((s8 *)(s1) + 2)) = 0;
    }
}

void func_808087F0_chdiggerboss(param_0) Actor *param_0;
{
    DiggerBraceState *local_0;
    Actor *local_1;
    f32 local_2[3];
    f32 local_3[3];
    f32 local_4;

    local_0 = func_80100094(param_0, 0);
    local_1 = func_808086A8_chdiggerboss(param_0);
    if (local_1 && _subaddieskeleton_entrypoint_0(param_0, 0x10, local_2)) {
        local_4 = param_0->rotation[1] + local_0->local_0;
        _subaddieskeleton_entrypoint_0(param_0, 0x1E, local_3);
        func_800EFE50(local_1->position, local_2, local_3, 0.5f);
        func_800EF1B8(local_1->position, local_4, 80.0f);
        local_1->position[1] += 80.0f;
    }
}

void func_808088AC_chdiggerboss(s32 arg0)
{
    func_80808B40_chdiggerboss(arg0,1);
}

int func_808088CC_chdiggerboss(param_0) s32 param_0;
{
  s32 local_0;
  Actor *local_1;
  s32 local_2;
  local_1 = func_80100094(param_0, 0);
  for (local_0 = 0;
  local_0 < 4;
  local_0++)
    {
        local_2 = *(s32 *)((char *)local_1 + local_0 * 0x4 + 0xB0);
        if (local_2 != 0)
        {
            func_80808BE4_chdiggerboss(param_0, func_80106790(local_2), local_0);
        }
    }
}

void func_80808948_chdiggerboss(param_0) Actor *param_0;
{
    s32 local_0;
    DiggerCleanupMarkers *local_1;

    local_1 = func_80100094(param_0, 0);
    for (local_0 = 0; local_0 < 4; local_0++) {
        if (local_1->local_0[local_0]) {
            if (func_801069A4(local_1->local_0[local_0])) {
                func_800FFA88(local_1->local_0[local_0]);
            }
            local_1->local_0[local_0] = 0;
        }
    }
}

void func_808089BC_chdiggerboss(param_0, param_1) Actor *param_0; s32 param_1;
{
    u8 *local_0;
    s32 local_1;
    Actor *local_2;
    local_0 = (u8 *)func_80100094(param_0, 0);
    if (param_1 == 6) {
        for (local_1 = 0; local_1 != 2; local_1++) {
            local_2 = (Actor *)func_80108528(0x50A, param_0->position, 10, &param_0);
            func_80103110(local_2, 1);
            func_80102FDC(local_2, 1.5f);
            local_2->unk74_17 = 0;
            local_2->unk74_7 = 0x43;
            func_80808BE4_chdiggerboss(param_0, local_2, local_1);
            ((void **)(local_0 + 0xB0))[local_1] = local_2->unk0;
        }
        for (; local_1 < 4; local_1++) {
            local_2 = (Actor *)func_80108528(0x50A, param_0->position, 10, &param_0);
            func_80103110(local_2, 1);
            func_80102FDC(local_2, 0.8f);
            _subaddiefade_entrypoint_12(local_2, 0xFF, 0, 0);
            local_2->unk74_17 = 0;
            local_2->unk74_7 = 0x3E;
            func_80808BE4_chdiggerboss(param_0, local_2, local_1);
            ((void **)(local_0 + 0xB0))[local_1] = local_2->unk0;
        }
    }
}

void func_80808B40_chdiggerboss(Actor *param_0, s32 param_1)
{
    DiggerBossMarkers *local_0;
    s32 local_1;
    local_0 = func_80100094(param_0, 0);
    if (local_0->enabled != param_1) {
        local_0->enabled = param_1;
        if (param_1) {
            if (local_0->markers[0] == NULL) func_80108B04(param_0, 6);
        } else {
            for (local_1 = 0; local_1 < 4; local_1++) {
                if (local_0->markers[local_1] != NULL) {
                    func_800FFA88(local_0->markers[local_1]);
                    local_0->markers[local_1] = NULL;
                }
            }
        }
    }
}

void func_80808BE4_chdiggerboss(param_0, param_1, param_2) Actor *param_0; Actor *param_1; s32 param_2;
{
    func_800EEC30(param_1->position, D_8080A1BC_chdiggerboss[param_2],
        param_0->rotation[1] + D_8080A1AC_chdiggerboss[param_2],
        D_8080A1CC_chdiggerboss[param_2]);
    func_800EF04C(param_1->position, param_0->position);
    func_80103014(param_1);
}

void func_80808C64_chdiggerboss(param_0) Actor *param_0;
{
    DiggerResetPose *local_0;
    s32 local_1;

    local_0 = func_80100094(param_0, 0);
    for (local_1 = 0; local_1 < 2; local_1++) {
        local_0->local_0[local_1] = 0.0f;
    }
    func_800EE7F8(local_0->local_1, param_0->position);
    local_0->local_2 = param_0->rotation[1];
}

void func_80808CD0_chdiggerboss(param_0) u8 *param_0; {
    u8 *sp24;

    sp24 = func_80100094(param_0, 0);
    func_80808D54_chdiggerboss(param_0, 0, -1.0f, &D_8080A1E8_chdiggerboss);
    func_80808D54_chdiggerboss(param_0, 1, 1.0f, &D_8080A1DC_chdiggerboss);
    func_80808F44_chdiggerboss(param_0);
    func_800EE7F8(sp24 + 0xD4, param_0 + 4);
    (*(f32 *)((s8 *)(sp24) + (0xE0))) = (f32) (*(f32 *)((s8 *)(param_0) + (0x48)));
}

void func_80808D54_chdiggerboss(Actor *param_0, s32 param_1, f32 param_2, f32 *param_3)
{
    u8 *local_4;
    f32 local_0;
    f32 local_1[3];
    f32 local_2[3];
    f32 local_3;
    f32 local_5;
    /* Unused float slots preserve the original IDO stack layout.
     * Their original source-level purpose is not yet established. */
    f32 local_7;
    f32 local_8;
    s32 local_6;

    local_4 = func_80100094(param_0, 0);
    local_0 = func_800D8FF8();
    func_800EF934(local_1, param_3, param_0->rotation[1]);
    func_800EF04C(local_1, param_0->position);
    func_800EF934(local_2, param_3, *(f32 *)(local_4 + 0xE0));
    func_800EF04C(local_2, local_4 + 0xD4);
    local_3 = func_800EEAD4(local_1, local_2);
    if (func_800EECE0(param_0->position, local_4 + 0xD4)) {
        local_5 = (func_800F1DCC(*(f32 *)(local_4 + 0xE0), param_0->rotation[1]) <= 0.0f ? 1.0f : -1.0f) * param_2;
    } else {
        local_5 = 1.0f;
    }
    *(f32 *)(local_4 + 0xC8 + param_1 * 4) += (((local_3 * 12.0f) * local_5) * 64.0f) * local_0;
    local_6 = (s32)*(f32 *)(local_4 + 0xC8 + param_1 * 4);
    if (local_6 >= 8192) {
        *(f32 *)(local_4 + 0xC8 + param_1 * 4) -= 8192.0f;
    } else if (local_6 < 0) {
        *(f32 *)(local_4 + 0xC8 + param_1 * 4) += 8192.0f;
    }
    *(s16 *)(local_4 + 0xD0 + param_1 * 2) = (s32)*(f32 *)(local_4 + 0xC8 + param_1 * 4);
    *(f32 *)(local_4 + 0xC0 + param_1 * 4) += ((local_3 * 0.01333333366f) * local_5) * 57.29578018f;
}

void func_80808F44_chdiggerboss(param_0) Actor *param_0;
{
    s32 local_0;

    local_0 = func_801065A4(param_0);
    if (local_0) {
        _glid_entrypoint_0(local_0, 1, _chdiggerboss_entrypoint_3, param_0->unk0);
        _glid_entrypoint_0(local_0, 2, _chdiggerboss_entrypoint_3, param_0->unk0);
    }
}

void chdiggerboss_entrypoint_3(s32 param_0, VertexShiftRecord *param_1, VertexShiftRecord *param_2, s32 param_3, Unk80132ED0 *param_4)
{
    u8 *local_0;
    s32 local_2;
    VertexShiftRecord *local_1;

    local_0 = func_80100094(func_80106790(param_4), 0);
    switch (param_0) {
        case 1:
            local_2 = *(s16 *)(local_0 + 0xD0);
            local_1 = param_1 + param_3;
            for (; param_1 < local_1; param_1++, param_2++) {
                param_2->unkA = param_1->unkA + local_2;
            }
            break;
        case 2:
            local_2 = *(s16 *)(local_0 + 0xD0 + 2);
            local_1 = param_1 + param_3;
            for (; param_1 < local_1; param_1++, param_2++) {
                param_2->unkA = param_1->unkA + local_2;
            }
            break;
    }
}

void func_80809078_chdiggerboss(param_0, param_1, param_2) Actor *param_0; void *param_1; s32 param_2;
{
    DiggerBlendState *local_0;
    s32 i;
    local_0 = func_80100094(param_0, 0);
    for (i = 0; i < 3; i++) {
        func_800E0AFC(param_1, D_8080A1F4_chdiggerboss[i * 2 + 1], 1.0f, local_0->local_0, 0.0f, 0.0f);
    }
    for (i = 0; i < 3; i++) {
        func_800E0AFC(param_1, D_8080A1FC_chdiggerboss[i * 2 + 1], 1.0f, local_0->local_1, 0.0f, 0.0f);
    }
}

void func_80809150_chdiggerboss(s32 param_0) {
    s32 local_0;
    u8 *local_1;

    local_0 = func_80802228_chdiggerboss(param_0);
    local_1 = func_80100094(param_0, 0);
    func_80808B40_chdiggerboss(local_0, 0);
    func_80803BE8_chdiggerboss(param_0, 0x43, 1);
    func_800DA544(0x43);
    _gcfrontend_entrypoint_9(0x83);
    func_800FDC28(0x16);
    (*(s32 *)((s8 *)(local_1) + (0xDC))) = -1;
    (*(s32 *)((s8 *)(local_1) + (0xE4))) = 0;
    (*(s32 *)((s8 *)(local_1) + (0xE8))) = 0;
    (*(s32 *)((s8 *)(local_1) + (0xEC))) = 0;
    (*(s32 *)((s8 *)(local_1) + (0xF0))) = 0;
    (*(s32 *)((s8 *)(local_1) + (0xF4))) = 0;
    func_80809234_chdiggerboss(param_0);
}

s32 func_808091E4_chdiggerboss(Actor *this){
    if ((func_800D9078((u8 *)func_80100094(this, 0) + 0xE0) != 0) && (func_80809234_chdiggerboss(this) == 0)) {
        return 0;
    }
    return 1;
}

int func_80809234_chdiggerboss(param_0) Actor *param_0;
{
    DiggerStageState *local_0;

    local_0 = (DiggerStageState *)func_80100094(param_0, 0);
    local_0->local_0++;
    if (local_0->local_0 >= 5U) {
        func_800FC74C(*(s16 *)(D_8080A1FE_chdiggerboss + local_0->local_0 * 8));
        local_0->local_2 = 0;
        return 0;
    }
    local_0->local_1 = *(f32 *)(D_8080A208_chdiggerboss + local_0->local_0 * 8);
    _chexploder_entrypoint_5(param_0, 0x91C, param_0->position, param_0->rotation[1], 1.0f, 7);
    if (local_0->local_0) func_800FC74C(*(s16 *)(D_8080A1FE_chdiggerboss + local_0->local_0 * 8));
    func_800FC6B0(*(s16 *)(D_8080A206_chdiggerboss + local_0->local_0 * 8));
    return 1;
}

void func_80809310_chdiggerboss(Actor *param_0)
{
    Actor *local_0;
    u8 *local_1;
    Actor *local_2;

    local_0 = func_80106790(func_80101080(param_0));
    local_1 = func_80100094(param_0, 0);
    func_80802938_chdiggerboss(param_0, local_0->unk0, D_8080A204_chdiggerboss[*(s32 *)(local_1 + 0xDC)][0], 40);
    _chexploder_entrypoint_6(local_0, 1000.0f, 1200.0f);
    _chexploder_entrypoint_12(local_0, 250);
    _chexploder_entrypoint_11(local_0, D_8080A240_chdiggerboss);
    func_808093F8_chdiggerboss(param_0);
    if (*(Unk80132ED0 **)(local_1 + 0xE4) != NULL) {
        func_800FFA88(*(Unk80132ED0 **)(local_1 + 0xE4));
    }
    *(Unk80132ED0 **)(local_1 + 0xE4) = local_0->unk0;
    if (param_0->unk3C != NULL) {
        local_2 = (Actor *)func_80802228_chdiggerboss(param_0);
        local_2->unk3C = NULL;
        param_0->unk3C = NULL;
        func_800FFAB0(local_2);
    }
}

void func_808093F8_chdiggerboss(param_0) Actor *param_0;
{
    f32 local_0[3];
    f32 local_1[3];
    f32 local_2[3];
    u8 *local_3;
    s32 local_4;
    s32 local_5;

    local_3 = func_80100094(param_0, 0);
    func_800EE7F8(local_0, param_0->position);
    local_0[1] += 300.0f;
    if (*(s32 *)(local_3 + 0xE8)) {
        func_800B5450(*(s32 *)(local_3 + 0xE8));
    }
    *(s32 *)(local_3 + 0xE8) = func_800BBCB8(local_0, local_0, 3.0f, 1, D_8080A25C_chdiggerboss);
    if (*(s32 *)(local_3 + 0xEC)) {
        func_800B5450(*(s32 *)(local_3 + 0xEC));
    }
    local_4 = func_800B53A4(8);
    *(s32 *)(local_3 + 0xEC) = local_4;
    for (local_5 = 0; local_5 != 8; local_5++) {
        func_800EEB9C(local_2, local_5 * 45.0f, func_800DC178(120.0f, 160.0f));
        func_800EF04C(local_2, local_0);
        local_2[1] += func_800DC178(10.0f, 50.0f);
        func_800BABB8(local_4, local_2, local_0, 1.0f, D_8080A2B8_chdiggerboss);
    }
    if (*(s32 *)(local_3 + 0xF0)) {
        func_800B5450(*(s32 *)(local_3 + 0xF0));
    }
    *(s32 *)(local_3 + 0xF0) = func_800BBCB8(local_0, local_0, 1.0f, 1, D_8080A294_chdiggerboss);
    if (*(s32 *)(local_3 + 0xF4)) {
        func_800B5450(*(s32 *)(local_3 + 0xF4));
    }
    func_800E3A58(local_1);
    local_4 = func_800B53A4(1);
    *(s32 *)(local_3 + 0xF4) = local_4;
    func_800BABB8(local_4, local_0, local_0, 1.0f, D_8080A294_chdiggerboss);
    func_800BA77C(local_4, (s16)(s32)(local_1[0] + 90.0f),
        (s16)(s32)local_1[1], (s16)(s32)local_1[2]);
    func_800BA22C(local_4, 1);
    _subaddieaudioquick_entrypoint_2(param_0, param_0->position, D_8080A250_chdiggerboss);
    func_8010D930(7, -1, param_0->position, D_8080A22C_chdiggerboss);
}

/* TU-NOTE: the .data of this overlay (formerly asm/data/overlays/ch/digger/boss.data.s) is defined here in C.
 * Its tables hold pointers to functions of this file; IDO's assembler schedules some of these
 * functions differently unless the tables are defined in the same unit. Values are taken from the ROM.
 * Labels inside an object are linker symbols in undefined_syms.us.txt: D_80809EE2_chdiggerboss = D_80809EE0_chdiggerboss + 0x2, D_8080A1FA_chdiggerboss = D_8080A1F4_chdiggerboss + 0x6, D_8080A1FE_chdiggerboss = D_8080A1FC_chdiggerboss + 0x2, D_8080A202_chdiggerboss = D_8080A1FC_chdiggerboss + 0x6, D_8080A206_chdiggerboss = D_8080A204_chdiggerboss + 0x2, D_8080A208_chdiggerboss = D_8080A204_chdiggerboss + 0x4
 * extern declarations adjusted to the object (same addresses): D_80809E44_chdiggerboss -> int[], D_80809E8C_chdiggerboss -> int[], D_80809EE4_chdiggerboss -> u16[], D_80809F98_chdiggerboss -> u8[], D_80809FB0_chdiggerboss -> s32[], D_80809FC0_chdiggerboss -> s32[], D_80809FD0_chdiggerboss -> s32[], D_80809FE0_chdiggerboss -> s32[], D_8080A084_chdiggerboss -> int[], D_8080A090_chdiggerboss -> int[], D_8080A09C_chdiggerboss -> int[], D_8080A0A8_chdiggerboss -> int[], D_8080A0EC_chdiggerboss -> s32[], D_8080A1DC_chdiggerboss -> int[], D_8080A1E8_chdiggerboss -> int[] */
u8 D_80809C60_chdiggerboss[16] = { 0x2, 0x5A, 0x3, 0xE8, 0x5, 0xDC, 0x0, 0x0, 0x3F, 0xC0, 0x0, 0x0, 0x40, 0x40, 0x0, 0x0 };
u8 D_80809C70_chdiggerboss[16] = { 0x2, 0x50, 0x4, 0xB0, 0x7, 0x8, 0x0, 0x0, 0x3F, 0xA0, 0x0, 0x0, 0x40, 0x20, 0x0, 0x0 };
u8 D_80809C80_chdiggerboss[16] = { 0x2, 0x46, 0x5, 0x78, 0x8, 0x34, 0x0, 0x0, 0x3F, 0x80, 0x0, 0x0, 0x40, 0x0, 0x0, 0x0 };
u8 D_80809C90_chdiggerboss[16] = { 0x3, 0x3C, 0x6, 0x40, 0x9, 0x60, 0x0, 0x0, 0x3F, 0x66, 0x66, 0x66, 0x3F, 0xE6, 0x66, 0x66 };
u8 D_80809CA0_chdiggerboss[16] = { 0x3, 0x32, 0x7, 0x8, 0xA, 0x8C, 0x0, 0x0, 0x3F, 0x4C, 0xCC, 0xCD, 0x3F, 0xCC, 0xCC, 0xCD };
u8 D_80809CB0_chdiggerboss[16] = { 0x3, 0x28, 0x7, 0xD0, 0xB, 0xB8, 0x0, 0x0, 0x3F, 0x33, 0x33, 0x33, 0x3F, 0xB3, 0x33, 0x33 };
u8 D_80809CC0_chdiggerboss[16] = { 0x4, 0x1E, 0x7, 0xD0, 0xB, 0xB8, 0x0, 0x0, 0x3F, 0x19, 0x99, 0x9A, 0x3F, 0x99, 0x99, 0x9A };
u8 D_80809CD0_chdiggerboss[16] = { 0x4, 0xF, 0x7, 0xD0, 0xB, 0xB8, 0x0, 0x0, 0x3F, 0x0, 0x0, 0x0, 0x3F, 0x80, 0x0, 0x0 };
u8 D_80809CE0_chdiggerboss[16] = { 0x4, 0x1, 0x7, 0xD0, 0xB, 0xB8, 0x0, 0x0, 0x3F, 0x0, 0x0, 0x0, 0x3F, 0x80, 0x0, 0x0 };
u8 D_80809CF0_chdiggerboss[16] = { 0x0, 0x4, 0x0, 0x64, 0x1, 0x90, 0x0, 0x0, 0x40, 0x0, 0x0, 0x0, 0x3, 0xE8, 0x5, 0xDC };
u8 D_80809D00_chdiggerboss[16] = { 0x0, 0x6, 0x0, 0x64, 0x0, 0xC8, 0x0, 0x0, 0x3F, 0xC0, 0x0, 0x0, 0x3, 0xE8, 0x5, 0xDC };
u8 D_80809D10_chdiggerboss[168] = { 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x3F, 0x23, 0xD7, 0xA, 0x4, 0x35, 0x0, 0x2, 0x3F, 0xB9, 0x99, 0x9A, 0x4, 0x3B, 0x0, 0x2, 0x40, 0xBC, 0x28, 0xF6, 0x4, 0x36, 0x0, 0x2, 0x41, 0x9, 0x47, 0xAE, 0x4, 0x37, 0x0, 0x1, 0x3F, 0x80, 0x0, 0x0, 0x4, 0x38, 0x0, 0x2, 0x3F, 0x9A, 0xE1, 0x48, 0x4, 0x39, 0x0, 0x2, 0x40, 0xD5, 0x70, 0xA4, 0x4, 0x3F, 0x0, 0x1, 0x3F, 0x86, 0x66, 0x66, 0x4, 0x3A, 0x0, 0x2, 0x40, 0x4A, 0xE1, 0x48, 0x4, 0x3C, 0x0, 0x2, 0x40, 0x85, 0x70, 0xA4, 0x4, 0x3D, 0x0, 0x1, 0x3F, 0x90, 0xA3, 0xD7, 0x4, 0x3E, 0x0, 0x2, 0x40, 0x86, 0x66, 0x66, 0x4, 0x40, 0x0, 0x2, 0x3F, 0xAA, 0x3D, 0x71, 0x4, 0x29, 0x0, 0x2, 0x3E, 0xF0, 0xA3, 0xD7, 0x4, 0x2A, 0x0, 0x42, 0x3F, 0xAA, 0x3D, 0x71, 0x4, 0x2B, 0x0, 0x2, 0x3E, 0xF0, 0xA3, 0xD7, 0x4, 0x2C, 0x0, 0x42, 0x3F, 0x90, 0xA3, 0xD7, 0x4, 0x2D, 0x0, 0x2, 0x3F, 0x90, 0xA3, 0xD7, 0x4, 0x2E, 0x0, 0x2, 0x3F, 0x21, 0x47, 0xAE, 0x4, 0x2F, 0x0, 0x2 };
u8 D_80809DB8_chdiggerboss[20] = { 0x0, 0x13, 0x5, 0x56, 0x0, 0xD, 0x0, 0xF3, 0x1, 0xC, 0x0, 0x1, 0x4, 0xB0, 0x1F, 0x40, 0x0, 0x0, 0x0, 0x0 };
u8 D_80809DCC_chdiggerboss[24] = { 0x0, 0x13, 0x4, 0xA0, 0x0, 0xD, 0x0, 0xF3, 0x1, 0xC, 0x0, 0x16, 0x2E, 0xE0, 0x0, 0x1, 0x4, 0xB0, 0x1F, 0x40, 0x0, 0x0, 0x0, 0x0 };
u8 D_80809DE4_chdiggerboss[24] = { 0x0, 0x13, 0x4, 0x7A, 0x0, 0xD, 0x0, 0xF3, 0x1, 0xC, 0x0, 0x16, 0x6D, 0x60, 0x0, 0x1, 0x4, 0xB0, 0x1F, 0x40, 0x0, 0x0, 0x0, 0x0 };
u8 D_80809DFC_chdiggerboss[20] = { 0x0, 0x13, 0x4, 0x8A, 0x0, 0x16, 0x6D, 0x60, 0x0, 0x1, 0x4, 0xB0, 0x1F, 0x40, 0x0, 0x20, 0x0, 0x0, 0x0, 0x0 };
u8 D_80809E10_chdiggerboss[20] = { 0x0, 0x13, 0x4, 0x87, 0x0, 0x16, 0x6D, 0x60, 0x0, 0x1, 0x4, 0xB0, 0x1F, 0x40, 0x0, 0x20, 0x0, 0x0, 0x0, 0x0 };
u8 D_80809E24_chdiggerboss[20] = { 0x0, 0x13, 0x5, 0xB9, 0x0, 0xC, 0x0, 0x0, 0x0, 0x99, 0x0, 0xCC, 0x1, 0x19, 0x0, 0x18, 0x0, 0x20, 0x0, 0x0 };
u8 D_80809E38_chdiggerboss[12] = { 0x0, 0x13, 0x4, 0xC7, 0x0, 0x18, 0x0, 0x20, 0x0, 0x0, 0x0, 0x0 };
int D_80809E44_chdiggerboss[18] = { 0x1A80343, 0x9010001, (u32)&D_80809D10_chdiggerboss, (u32)func_80800A4C_chdiggerboss, (u32)func_80102EC0, (u32)func_80800508_chdiggerboss, 0x0, 0x0, 0x0, 0x10082528, (u32)func_808019A8_chdiggerboss, (u32)func_80108ED0, 0x10C0000, (u32)func_808008F8_chdiggerboss, (u32)func_80107C2C, -0x7FE00000, (u32)func_80801A04_chdiggerboss, 0x0 };
int D_80809E8C_chdiggerboss[18] = { 0x3C0203, 0x8FE0001, (u32)&D_80809D10_chdiggerboss, (u32)func_808023D8_chdiggerboss, (u32)func_80102EC0, (u32)func_80800650_chdiggerboss, 0x0, 0x0, 0x0, 0x20003C64, (u32)func_80802550_chdiggerboss, (u32)func_80108ED0, 0xEC0000, (u32)func_8080233C_chdiggerboss, (u32)func_80107C2C, -0x7F7FFFFE, (u32)func_808025D4_chdiggerboss, 0x0 };
u8 D_80809ED4_chdiggerboss[12] = { 0x0, 0x5, 0x0, 0x6, 0x0, 0x7, 0x0, 0x8, 0x0, 0x9, 0x0, 0xA };
u8 D_80809EE0_chdiggerboss[4] = { 0x0, 0x5, 0x0, 0x0 };
u16 D_80809EE4_chdiggerboss[16] = { 0x688, 0x689, 0x68A, 0x68B, 0x68C, 0x68D, 0x68E, 0x68F, 0x690, 0x0, 0x0, 0x691, 0x692, 0x693, 0x694, 0x0 };
u8 D_80809F04_chdiggerboss[12] = { 0x0, 0x13, 0x4, 0xA9, 0x0, 0x16, 0x7D, 0x0, 0x0, 0x2, 0x0, 0x0 };
u8 D_80809F10_chdiggerboss[12] = { 0xC3, 0xAF, 0x0, 0x0, 0xC2, 0xC8, 0x0, 0x0, 0xC3, 0xC8, 0x0, 0x0 };
u8 D_80809F1C_chdiggerboss[12] = { 0x43, 0xAF, 0x0, 0x0, 0x44, 0x48, 0x0, 0x0, 0x43, 0xAF, 0x0, 0x0 };
u16 D_80809F28_chdiggerboss[3][2] = { 0x1C30, 0x1C44, 0x1C44, 0x1C58, 0x1C58, 0x1C6C };
u8 D_80809F34_chdiggerboss[8] = { 0x0, 0x9D, 0x0, 0x9F, 0xFF, 0xFF, 0x0, 0x0 };
u8 D_80809F3C_chdiggerboss[4] = { 0x3C, 0x32, 0x40, 0xFE };
u8 D_80809F40_chdiggerboss[4] = { 0xE0, 0xFF, 0xE0, 0x80 };
u8 D_80809F44_chdiggerboss[24] = { 0x0, 0x13, 0x4, 0xB5, 0x0, 0xD, 0x0, 0xD9, 0x1, 0x26, 0x0, 0x16, 0x6D, 0x60, 0x0, 0x1, 0x4, 0xB0, 0x1F, 0x40, 0x0, 0x0, 0x0, 0x0 };
u8 D_80809F5C_chdiggerboss[24] = { 0x0, 0x13, 0x4, 0x91, 0x0, 0xD, 0x1, 0x33, 0x1, 0x4C, 0x0, 0x16, 0x6D, 0x60, 0x0, 0x1, 0x4, 0xB0, 0x1F, 0x40, 0x0, 0x0, 0x0, 0x0 };
u8 D_80809F74_chdiggerboss[20] = { 0x0, 0x13, 0x6, 0x7, 0x0, 0xD, 0x0, 0xF3, 0x1, 0xC, 0x0, 0x18, 0x0, 0x1, 0x4, 0xB0, 0x1F, 0x40, 0x0, 0x0 };
u8 D_80809F88_chdiggerboss[16] = { 0x0, 0x13, 0x4, 0x13, 0x0, 0x16, 0x6D, 0x60, 0x0, 0x1, 0x4, 0xB0, 0x1F, 0x40, 0x0, 0x0 };
u8 D_80809F98_chdiggerboss[24] = { 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x3F, 0x0, 0x0, 0x0, 0x3F, 0x80, 0x0, 0x0, 0x3F, 0x80, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0 };
s32 D_80809FB0_chdiggerboss[4] = { 0x1305F0, 0x180001, 0x4B01F40, 0x0 };
s32 D_80809FC0_chdiggerboss[4] = { 0x130527, 0x1D001E, 0x104B0, 0x1F400000 };
s32 D_80809FD0_chdiggerboss[4] = { 0x1305F0, 0x104B0, 0x1F400018, 0x0 };
s32 D_80809FE0_chdiggerboss[18] = { 0x1D09DC, 0x320000, 0x162200, 0x220080, 0x800200, 0x2800027, -0x770078, 0x780078, 0x2D01F4, 0x258001B, 0x28003C, 0x150000, 0x99002B, 0x1000133, 0xE000F, 0x1E011A, 0x3000F3, 0x0 };
u8 D_8080A028_chdiggerboss[16] = { 0x0, 0x13, 0x5, 0x16, 0x0, 0x1D, 0x0, 0x1E, 0x0, 0x1, 0x4, 0xB0, 0x1F, 0x40, 0x0, 0x0 };
u8 D_8080A038_chdiggerboss[8] = { 0x43, 0x16, 0x0, 0x0, 0x43, 0x96, 0x0, 0x0 };
u8 D_8080A040_chdiggerboss[24] = { 0x0, 0x13, 0x4, 0xDF, 0x0, 0xE, 0x0, 0xCC, 0x1, 0x0, 0x0, 0x80, 0x0, 0x16, 0x19, 0x64, 0x0, 0x1, 0x4, 0xB0, 0x1F, 0x40, 0x0, 0x0 };
u8 D_8080A058_chdiggerboss[8] = { 0x0, 0x4, 0x0, 0x5, 0x0, 0x6, 0x0, 0xD };
s16 D_8080A060_chdiggerboss[4] = { 0x4, 0x3, 0x1, 0x2 };
u8 D_8080A068_chdiggerboss[4] = { 0x8, 0x4, 0x1, 0x2 };
u32 D_8080A06C_chdiggerboss[2][3] = { 0xFF, 0xFF, 0xFF, 0x20, 0xC0, 0xFF };
int D_8080A084_chdiggerboss[3] = { -0x3C6A0000, 0x0, 0x432F0000 };
int D_8080A090_chdiggerboss[3] = { -0x3C6A0000, 0x0, -0x3C448000 };
int D_8080A09C_chdiggerboss[3] = { 0x43960000, 0x0, 0x432F0000 };
int D_8080A0A8_chdiggerboss[3] = { 0x43960000, 0x0, -0x3C448000 };
s32 D_8080A0B4_chdiggerboss[14] = { 0x1D09E2, 0x160200, 0x60000, 0x40099, 0x70003, 0x150000, 0xCC002B, 0x1800200, 0x22004C, 0x590026, 0x33000E, 0x5000A, 0x1BF9C0, -0x4B00000 };
s32 D_8080A0EC_chdiggerboss[6] = { 0x13068A, 0xE00F3, 0x10C0019, 0x166D60, 0x104B0, 0x1F400000 };
s16 D_8080A104_chdiggerboss[12] = { 0x306, 0x21, 0xD, 0xF3, 0x10C, 0x18, 0x1, 0x4B0, 0x1F40, 0x11, 0x0, 0x0 };
s16 D_8080A11C_chdiggerboss[2] = { 0x48C, 0x48B };
u8 D_8080A120_chdiggerboss[20] = { 0x0, 0x13, 0x4, 0x8A, 0x0, 0x16, 0x6D, 0x60, 0x0, 0x1, 0x4, 0xB0, 0x1F, 0x40, 0x0, 0x20, 0x0, 0x0, 0x0, 0x0 };
u8 D_8080A134_chdiggerboss[12] = { 0x42, 0xC8, 0x0, 0x0, 0x45, 0xEA, 0x60, 0x0, 0x42, 0xC8, 0x0, 0x0 };
u8 D_8080A140_chdiggerboss[16] = { 0x0, 0x13, 0x6, 0x7, 0x0, 0x18, 0x0, 0xD, 0x0, 0xF3, 0x1, 0xC, 0x0, 0x0, 0x0, 0x0 };
u8 D_8080A150_chdiggerboss[4] = { 0x6E, 0x64, 0x50, 0xE0 };
u8 D_8080A154_chdiggerboss[12] = { 0x0, 0x13, 0x4, 0xBE, 0x0, 0xD, 0x0, 0xF3, 0x1, 0xC, 0x0, 0x0 };
u8 D_8080A160_chdiggerboss[12] = { 0x0, 0x13, 0x4, 0xDC, 0x0, 0x18, 0x0, 0x2, 0x0, 0x20, 0x0, 0x0 };
u8 D_8080A16C_chdiggerboss[64] = { 0x0, 0x1D, 0x9, 0xDC, 0x0, 0x32, 0x0, 0x0, 0x0, 0x16, 0x2, 0x0, 0x0, 0x22, 0x0, 0x80, 0x0, 0x80, 0x2, 0x0, 0x2, 0x80, 0x0, 0x20, 0xFF, 0x40, 0xE0, 0xC0, 0x0, 0x27, 0xFF, 0x88, 0xFF, 0x88, 0x0, 0x78, 0x0, 0x78, 0x0, 0x2D, 0x0, 0xFA, 0x1, 0x5E, 0x0, 0x15, 0x0, 0x19, 0x0, 0x99, 0x0, 0x2B, 0x1, 0x0, 0x1, 0x66, 0x0, 0xE, 0x0, 0xF, 0x0, 0x1E, 0x0, 0x0 };
f32 D_8080A1AC_chdiggerboss[4] = { 37.5f, -37.5f, 166.0f, -166.0f };
f32 D_8080A1BC_chdiggerboss[4] = { 47.5f, 47.5f, 15.5f, 15.5f };
f32 D_8080A1CC_chdiggerboss[4] = { 525.0f, 525.0f, 525.0f, 525.0f };
int D_8080A1DC_chdiggerboss[3] = { -0x3C6A0000, 0x0, -0x3D380000 };
int D_8080A1E8_chdiggerboss[3] = { 0x43960000, 0x0, -0x3D380000 };
u8 D_8080A1F4_chdiggerboss[8] = { 0x0, 0x44, 0x0, 0x45, 0x0, 0x46, 0x0, 0x0 };
u8 D_8080A1FC_chdiggerboss[8] = { 0x0, 0x47, 0x0, 0x48, 0x0, 0x49, 0x0, 0x0 };
s16 D_8080A204_chdiggerboss[5][4] = { 0x21, 0x9C, 0x3F40, 0x0, 0x23, 0x9D, 0x3F26, 0x6666, 0x26, 0x9E, 0x3F0C, -0x3333, 0x28, 0x9F, 0x3EE6, 0x6666, 0x1E, 0xA0, 0x4060, 0x0 };
u8 D_8080A22C_chdiggerboss[20] = { 0x0, 0x13, 0x4, 0xC8, 0x0, 0x16, 0x6D, 0x60, 0x0, 0x2, 0x0, 0xD, 0x0, 0xCC, 0x0, 0xE6, 0x0, 0x0, 0x0, 0x0 };
u8 D_8080A240_chdiggerboss[16] = { 0x0, 0x1, 0x0, 0x12, 0x0, 0x18, 0x0, 0x1A, 0x0, 0xA, 0x0, 0xC, 0xFF, 0xFF, 0x0, 0x0 };
u8 D_8080A250_chdiggerboss[12] = { 0x0, 0x13, 0x4, 0x13, 0x0, 0x18, 0x0, 0x2, 0x0, 0x0, 0x0, 0x0 };
u8 D_8080A25C_chdiggerboss[56] = { 0x0, 0x1D, 0x7, 0x8F, 0x0, 0x15, 0x0, 0x19, 0x0, 0x66, 0x0, 0x16, 0x2, 0x0, 0x0, 0x32, 0x0, 0x2, 0x0, 0x1E, 0x0, 0x1E, 0x0, 0x1E, 0x0, 0x18, 0x0, 0x0, 0x0, 0x0, 0xF, 0x0, 0xF, 0x0, 0x0, 0x22, 0x1, 0x0, 0x1, 0x0, 0x4, 0x0, 0x4, 0x0, 0x0, 0x2B, 0x1, 0x33, 0x1, 0x33, 0x0, 0x29, 0x0, 0x0, 0x0, 0x0 };
u8 D_8080A294_chdiggerboss[36] = { 0x0, 0x1D, 0x9, 0x53, 0x0, 0x15, 0x0, 0x0, 0x0, 0xB3, 0x0, 0x16, 0x2, 0x0, 0x0, 0x22, 0x0, 0x80, 0x0, 0x80, 0x8, 0x0, 0x8, 0x0, 0x0, 0x2B, 0x1, 0x66, 0x1, 0x66, 0x0, 0x29, 0x0, 0x0, 0x0, 0x0 };
u8 D_8080A2B8_chdiggerboss[72] = { 0x0, 0x1D, 0x9, 0xDD, 0x0, 0x16, 0x2, 0x0, 0x0, 0x2B, 0x1, 0x80, 0x2, 0x0, 0x0, 0x22, 0x1, 0x80, 0x2, 0x0, 0x3, 0x80, 0x4, 0x0, 0x0, 0x15, 0x0, 0x0, 0x0, 0x99, 0x0, 0x27, 0xFF, 0x9C, 0xFF, 0x9C, 0x0, 0x64, 0x0, 0x64, 0x0, 0x19, 0x0, 0x0, 0x0, 0x7, 0x0, 0x2D, 0x0, 0xFA, 0x1, 0x5E, 0x0, 0x20, 0xC0, 0xC0, 0xC0, 0x80, 0x1, 0x1A, 0x0, 0x29, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0 };
