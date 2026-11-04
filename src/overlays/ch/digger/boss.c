#include "common.h"

// hag1: final boss fight. Gruntilda (dialog-driven phase state machine) rides the Hag 1 drilling
// machine; the two actors point at each other via actor->unk3C.

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
extern void *func_8010262C(void *, s32);
extern void func_800E0AFC(void *, s32, f32, f32, f32, f32);
extern void func_800E0C20(void *, s32, f32, f32, f32, f32);
extern u16 D_80809EE4_chdiggerboss[];
typedef struct {
    u8 pad_0[0xFD];
    u8 local_0[3];
} DiggerFlags1473;
extern u8 unk64[];
extern u8 D_80809F04_chdiggerboss[];
extern void func_800EE7F8(f32 *, f32 *);
extern u8 D_80809F1C_chdiggerboss[];
extern u8 D_80809F10_chdiggerboss[];
extern Actor *func_80106790();
extern void *_gcdialogcamera_entrypoint_0(int, int);
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
typedef struct {
    s16 unk0;
    s16 unk2;
    u8 pad4[0x18];
} DiggerSlot;
extern s16 D_8080A060_chdiggerboss[];
extern void func_800DF744();
typedef struct {
    s16 x0;
    s16 x2;
    s32 x4;
    f32 pos[3];
    u8 x14;
    u8 x15;
    u8 x16;
    u8 pad17[5];
} Elem;
typedef struct {
    u8 pad[0x34];
    Elem e[1];
} Data;
extern void func_8010A570(s32);
typedef struct {
    u8 pad_0[0x25];
    u8 enabled;
    u8 pad_1[6];
    f32 timer;
} DiggerWaitState;
extern s32 func_800D90A4(f32 *);
typedef struct DiggerEffectRecord {
    s32 local_0;
    s16 local_1;
    u8 pad_0[6];
    f32 local_2[3];
    u8 local_3;
    u8 pad_1[3];
} DiggerEffectRecord;
typedef struct DiggerEffects {
    u8 pad_0[0x30];
    DiggerEffectRecord local_0[4];
} DiggerEffects;
extern u32 D_8080A06C_chdiggerboss[][3];
extern s32 func_8001210C(s32 param_0);
extern void func_800C8CB8(s32 param_0, f32 param_1[3]);
extern void func_800C8E84(s32 param_0, u32 param_1[3]);
extern int func_800C8FE0(s32 param_0, s32 param_1);
typedef struct {
    u8 pad[0x36];
    s16 a;
    u8 pad2[0x1C - 0x38 + 0x36 - 0x36];
} DiggerEntry;
typedef struct {
    u8 unused[0x18];
    f32 timer;
    u8 unused1C[9];
    u8 enabled;
} DiggerBossTimerState;
typedef struct {
    u8 pad_0[0x18];
    f32 local_0;
    f32 local_1;
    f32 local_2;
    u8 pad_1;
    u8 local_3;
} DiggerSpin1590;
struct DiggerAttackMotion;
extern int func_800F54E4(void);
extern int func_800F6D24(s32);
extern u8 func_800D9078(f32 *);
extern int D_8080A084_chdiggerboss[];
extern int D_8080A0A8_chdiggerboss[];
extern int D_8080A090_chdiggerboss[];
extern int D_8080A09C_chdiggerboss[];
typedef struct {
    u8 pad_0[0x14];
    f32 local_0;
    f32 local_1;
    u8 pad_1[0xC];
    s16 local_2;
} DiggerAttackState;
typedef struct DiggerAttackMotion {
    u8 pad_0[0x24];
    f32 local_0;
} DiggerAttackMotion;
typedef struct {
    u8 pad_0[8];
    s16 local_0;
    u8 pad_1[6];
    f32 local_1;
} DiggerBossTurn;
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
typedef struct {
    u8 pad_0[0x7C];
    s16 local_0;
    s16 local_1;
    u8 pad_1[4];
    f32 local_2;
    s16 local_3[8];
} DiggerBossPose61;
extern u8 D_8080A160_chdiggerboss[];
typedef struct {
    u8 pad_0[0xA4];
    s16 local_0;
    s16 pad_1;
    void *local_1;
} DiggerCameraState61;
extern u8 D_8080A16C_chdiggerboss[];
extern s32 func_800BBCB8(f32 *, f32 *, f32, s32, void *);
extern void func_800EFA4C(f32 *, f32, f32, f32);
extern s32 position_x;
extern u8 unkD0[];
extern u8 unkCC[];
typedef struct {
    u8 pad_0[0x10];
    f32 local_0;
} DiggerBraceState;
extern void func_800EFE50(f32 *, void *, void *, f32);
typedef struct {
    u8 pad_0[0xB0];
    Unk80132ED0 *local_0[4];
} DiggerCleanupMarkers;
typedef struct {
    u8 pad_0[0xAC];
    s32 enabled;
    Unk80132ED0 *markers[4];
} DiggerBossMarkers;
extern f32 D_8080A1AC_chdiggerboss[];
extern f32 D_8080A1BC_chdiggerboss[];
extern f32 D_8080A1CC_chdiggerboss[];
extern void func_800EEC30(f32 *, f32, f32, f32);
extern void func_800EF04C(f32 *, f32 *);
typedef struct {
    u8 pad_0[0xC0];
    f32 local_0[2];
    u8 pad_1[0xC];
    f32 local_1[3];
    f32 local_2;
} DiggerResetPose;
extern int D_8080A1E8_chdiggerboss[];
extern int D_8080A1DC_chdiggerboss[];
extern s32 func_801065A4(Actor *);
extern void _chdiggerboss_entrypoint_3();
extern void _glid_entrypoint_0(s32, s32, void (*)(), Unk80132ED0 *);
typedef struct {
    s16 position[3];
    u16 unk6;
    s16 unk8;
    s16 unkA;
    u8 padC[4];
} VertexShiftRecord;
typedef struct {
    u8 pad_0[0xC0];
    f32 local_0;
    f32 local_1;
} DiggerBlendState;
extern u8 D_8080A1F4_chdiggerboss[];
extern u8 D_8080A1FA_chdiggerboss[];
extern u8 D_8080A1FC_chdiggerboss[];
extern u8 D_8080A202_chdiggerboss[];
extern void func_800FC74C(u32);
extern void func_800FC6B0(u32);
typedef struct {
    u8 pad_0[0xDC];
    u32 local_0;
    f32 local_1;
    s32 local_2;
} DiggerStageState;
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
typedef struct {
    u8 pad_0[0xCC];
    s8 local_0;
    f32 local_1;
} DiggerPhase59;
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
typedef struct {
    u8 pad_0[0x70];
    u32 pad_1 : 28;
    u32 field_3 : 1;
    u32 pad_2 : 3;
} DiggerExpressionFlags;
typedef struct {
    u8 pad_0[0x7C];
    u32 a : 19;
    u32 f : 1;
    u32 b : 12;
} DB7C;
extern s32 B_8080A300_chdiggerboss;
typedef struct {
    u8 pad_0[12];
    f32 local_0;
    f32 local_1;
} DiggerCameraData;
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
typedef struct {
    u32 pad : 27;
    u32 f : 4;
    u32 b : 1;
} DB18;
typedef struct {
    u32 pad : 23;
    u32 g : 8;
    u32 b : 1;
} DB28;
typedef struct {
    u16 pad : 7;
    u16 g : 8;
    u16 b : 1;
} DB28h;
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
typedef struct {
    u32 pad_0;
    u8 local_0;
    u8 pad_1[0x57];
    u8 local_1;
    u8 pad_2[2];
    u8 local_2;
    f32 local_3;
} DiggerPlayerCommand;
typedef struct {
    u8 pad_0[0x7C];
    s16 local_0;
    s16 local_1;
    u8 pad_1[4];
    f32 local_2;
    u8 pad_2[2];
    s16 local_3;
    s16 local_4;
    u8 pad_3[2];
    f32 local_5;
    s16 local_6;
    s16 local_7;
} DiggerProjectileState;
extern u8 D_8080A140_chdiggerboss[];
extern void func_8010D09C(s32, f32 *, f32);
extern f32 func_800EEFD4(f32 *);
extern void func_800EF368(f32 *, f32);
extern Actor *func_80108528(s32, f32 *, s32, Actor **);
typedef struct {
    u8 pad0[0x98];
    f32 unk98;
    f32 unk9C;
    s16 unkA0;
    u8 unkA2;
    u8 unkA3;
} DiggerBossData;

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
DiggerPhase59 *func_80808560_chdiggerboss(Actor *param_0);
int func_808085E0_chdiggerboss(s32 param_0, s32 param_1);
void func_808086E8_chdiggerboss(u8 *param_0, u8 *param_1);
void func_808088AC_chdiggerboss(s32 arg0);
void func_80808B40_chdiggerboss(Actor *param_0, s32 param_1);
void func_80808CD0_chdiggerboss();
void func_80808D54_chdiggerboss(Actor *param_0, s32 param_1, f32 param_2, f32 *param_3);
void chdiggerboss_entrypoint_3(s32 param_0, VertexShiftRecord *param_1, VertexShiftRecord *param_2,
                               s32 param_3, Unk80132ED0 *param_4);
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

void func_80800000_chdiggerboss(s32 actor)
{
    switch (func_801022E4()) {
        case 0x435:
            _subaddieaudioquick_entrypoint_3(actor, actor + 4, &D_80809DB8_chdiggerboss,
                                             0.300000012f);
            _subaddieaudioquick_entrypoint_3(actor, actor + 4, &D_80809DCC_chdiggerboss,
                                             0.800000012f);
            return;
        case 0x43B:
            _subaddieaudioquick_entrypoint_3(actor, actor + 4, &D_80809DB8_chdiggerboss, 0.5f);
            _subaddieaudioquick_entrypoint_3(actor, actor + 4, &D_80809DCC_chdiggerboss,
                                             0.850000024f);
            return;
        case 0x436:
            if (func_80101DDC(actor) != 0) {
                func_80800180_chdiggerboss(actor, 5);
                return;
            }
            break;
        case 0x437:
            _subaddieaudioquick_entrypoint_3(actor, actor + 4, &D_80809DE4_chdiggerboss,
                                             0.600000024f);
            return;
        case 0x440:
            _subaddieaudioquick_entrypoint_3(actor, actor + 4, &D_80809DFC_chdiggerboss,
                                             0.600000024f);
            _subaddieaudioquick_entrypoint_3(actor, actor + 4, &D_80809E10_chdiggerboss,
                                             0.850000024f);
            if (func_80101E14(actor, 0.5f) != 0) {
                *(s8 *) ((u8 *) func_80100094(func_80802228_chdiggerboss(actor), 0) + 7) = 1;
            }
            break;
    }
}

void func_80800180_chdiggerboss(Actor *actor, s32 anim_id)
{
    func_80102424(actor, anim_id);
    if (func_801022E4(actor) != 0) {
        actor->unk64_16 = 1;
    } else {
        actor->unk64_16 = 0;
    }
    if (actor->unk3C != NULL) {
        func_808008C0_chdiggerboss(func_80802228_chdiggerboss(actor), 5,
                                   (*(u16 *) ((u8 *) actor + 0x64) & 1) == 0);
    }
}

// Matching: the line breaks in this function are needed for the match.
void func_80800200_chdiggerboss(actor) Actor *actor;
{

    u8 *data;
    s32 unk_0;
    u8 *pos;

    data = func_80100094(actor, 0);
    switch (func_801022E4(actor)) {
        case 0x42D:
        unk_0 = func_80102320(actor, 0.2f, 0.9f);
        pos = (u8 *)actor + 4;
        *(u8 *)((char *)data + 0xA0) = _subaddieaudioloop_entrypoint_7(*(u8 *)((char *)data + 0xA0), pos, unk_0, D_80809E24_chdiggerboss, *(s32 *)((char *)actor + 0x70) & 1);
        _subaddieaudioquick_entrypoint_3(actor, pos, D_80809E38_chdiggerboss, 0.85f);
        if (func_80101DDC(actor) != 0) {
            func_808008C0_chdiggerboss(actor, 1, 0);
            func_808008C0_chdiggerboss(actor, 2, 0);
            func_8080041C_chdiggerboss(actor, 0x13);
        }
        break;
        case 0x42E:
        if (func_80101DDC(actor) != 0) {
            *(u8 *)((char *)data + 6) = 1;
            func_8080041C_chdiggerboss(actor, 1);
            func_808041E4_chdiggerboss(actor, 1);
        }
        break;
        case 0x429:
        case 0x42B:
        unk_0 = func_80102320(actor, 0.0f, 0.6f);
        pos = (u8 *)actor + 4;
        *(u8 *)((char *)data + 0xA0) = _subaddieaudioloop_entrypoint_7(*(u8 *)((char *)data + 0xA0), pos, unk_0, D_80809E24_chdiggerboss, *(s32 *)((char *)actor + 0x70) & 1);
        _subaddieaudioquick_entrypoint_3(actor, pos, D_80809E38_chdiggerboss, 0.65f);
        return;
        case 0x42F:
        pos = (u8 *)actor + 4;
        _subaddieaudioquick_entrypoint_3(actor, pos, (u8 *) D_80809DB8_chdiggerboss, 0.3f);
        _subaddieaudioquick_entrypoint_3(actor, pos, (u8 *) D_80809DCC_chdiggerboss, 0.8f);
        if (func_80101DDC(actor) != 0) {
            *(u8 *)((char *)data + 5) = 1;
            func_8080041C_chdiggerboss(actor, 1);
            func_80807DC0_chdiggerboss(func_808026F8_chdiggerboss(actor), 1);
        }
    }
}

void func_8080041C_chdiggerboss(s32 actor, s32 anim_id)
{
    s32 state;
    u8 *data;

    data = func_80100094(func_808026F8_chdiggerboss(), 0);
    func_80102424(actor, anim_id);
    state = func_801022E4(actor);
    switch (state) {
        case 0x429:
            func_808008C0_chdiggerboss(actor, 3, 1);
            func_808008C0_chdiggerboss(actor, 1, 1);
            return;
        case 0x42B:
            *(s16 *) ((s8 *) data + 0x80) = 1;
            func_808008C0_chdiggerboss(actor, 4, 1);
            func_808008C0_chdiggerboss(actor, 2, 1);
            return;
        case 0x42D:
            *(s16 *) ((s8 *) data + 0x80) = 0;
    }
}

int chdiggerboss_entrypoint_0()
{
    return (int) &D_80809E44_chdiggerboss;
}

int chdiggerboss_entrypoint_1()
{
    return &D_80809E8C_chdiggerboss;
}

int func_80800508_chdiggerboss(actor, unk_1)
s32 actor;
s32 unk_1;
{
    s32 unk_0;

    unk_0 = func_800EB854();
    if (unk_0 != 0) {
        if (unk_0 == 3) {
            _gcnewoption_entrypoint_1((u8 *) func_80100094(actor, 0) + 0x10C, unk_1);
        }
    } else {
        func_80101808(actor, &func_801017D0);
    }
}

void func_80800568_chdiggerboss(Actor *actor, s32 unused)
{
    u8 *data;
    s32 i;

    data = func_80100094(actor, 0);
    func_801015D0(actor);
    for (i = 0; i < 1; i++) {
        func_800DF744(((s16 *) D_80809EE0_chdiggerboss)[i], data[i + 0xFC]);
    }
}

void func_808005DC_chdiggerboss(s32 actor, s32 unk_0)
{
    func_80806528_chdiggerboss(actor, func_800AE6BC(func_801040A8()), unk_0);
}

void func_80800618_chdiggerboss(s32 actor, s32 index, s32 value)
{
    s32 data;
    data = func_80100094(actor, 0);
    *(s8 *) ((s8 *) (data + index) + 0xfc) = (s8) value;
}

void func_80800650_chdiggerboss(u8 *actor, s32 unk_1)
{
    s32 unk_0;

    unk_0 = func_800EB854();
    switch (unk_0) {
        case 1:
            func_800DF830(0);
            func_800DF410(0xC0);
            func_800DE498(unk_1, (s32 *) (actor + 4), (s32 *) (actor + 0x44),
                          *(f32 *) (actor + 0x38), 0, func_800D674C(0x959));
            return;
        case 0:
            func_80101808(actor, &func_801017D0);
            return;
        case 2:
            func_80804EFC_chdiggerboss(actor, unk_1);
    }
}

// Matching: the line breaks in this function are needed for the match.
void func_808006F8_chdiggerboss(u8 **actor, s32 unk_1)
{
    s16 *id_ptr;
    s32 unk_0;
    u8 *data;
    u8 *flag_ptr;
    data = func_80100094(actor, 0);
    func_801015D0(actor);
    if (func_801022E4(actor) == 0)
    {
        unk_0 = func_800B27E0(unk_1);
        func_800AE1E8(*(s16 *) ((char *) *actor + 0x10), unk_0, func_801040D0());
        func_800DF72C(func_801040A8(actor));
    }
    flag_ptr = data;
    id_ptr = (s16 *) &D_80809ED4_chdiggerboss; do {
        func_800DF744(*id_ptr, *(u8 *) ((char *) flag_ptr + 0xE4));
        id_ptr += 1;
        flag_ptr += 1;
    }
    while ((u8 *) id_ptr != (u8 *) &D_80809EE0_chdiggerboss);
    func_800DF744(1, 0);
    func_800DF744(2, 0);
    func_800DF744(3, 0);
    func_800DF744(4, 0);
}

void func_808007E0_chdiggerboss(Actor *actor, void *unk_0)
{
    u8 *data;
    void *unk_1;

    data = (u8 *) func_80100094(actor, 0);
    unk_1 = func_8010262C(actor->unk0, 12);
    func_808042FC_chdiggerboss(actor, unk_1, unk_0);
    func_80804A7C_chdiggerboss(actor, unk_1, unk_0);
    func_80809078_chdiggerboss(actor, unk_1, unk_0);
    if (data[5])
        func_800E0AFC(unk_1, 0x52, 1.0f, -129.0f, 0.0f, 0.0f);
    if (data[6])
        func_800E0C20(unk_1, 0x50, 1.0f, 0.0f, 0.5f, 0.0f);
}

void func_808008C0_chdiggerboss(actor, index, value) s32 actor;
s32 index;
s32 value;
{
    s32 data;
    data = func_80100094(actor, 0);
    *(s8 *) ((s8 *) (data + index) + 0xe4) = (s8) value;
}

// Gruntilda init.
void func_808008F8_chdiggerboss(actor) Actor *actor;
{
    s32 i;
    s32 flag;
    u8 *data;

    i = func_800EA05C();

    if (func_800DA298('C') != 0) {
        func_800FFAB0(actor);
        return;
    }
    if ((i == 0x15D) && (func_800EA090() != 6)) {
        func_800FFAB0(actor);
        return;
    }
    i = 0;
    do {
        flag = func_80802158_chdiggerboss(actor, i);
        if ((flag != 0) && (func_800DA298(flag) != 0)) {
            func_80802170_chdiggerboss(actor, i);
        }
        i += 1;
    } while (i != 0xF);
    *(u8 *)((char *)(actor) + 0x75) = (u8) (*(u8 *)((char *)(actor) + 0x75) & 0xFFFD);
    data = func_80100074(actor, 0, _gcnewoption_entrypoint_2() + 0x10C);
    func_80109FE8(actor, 0);
    func_80109EEC(actor, 0x40);
    func_80102FDC(actor, 0.25f);
    *(u8 *)((char *)(data) + 2) = 0x64;
    func_8010A828(actor, 1);
    func_80803BE8_chdiggerboss(actor, 1, 1);
    func_80802CDC_chdiggerboss(actor);
    func_80802BE0_chdiggerboss(actor, 1.0f);
    func_800DA524(0xA4F);
    func_800DA524(0xA50);
}



// Gruntilda update: dialog-driven phase state machine.
void func_80800A4C_chdiggerboss(actor) Actor *actor;
{

    char *data;
    void *hag1;
    void *hag1_b;
    void *hag1_c;
    void *hag1_d;
    void *hag1_e;
    s32 i;
    void *hag1_f;
    void *hag1_g;
    void *unk_0;

    data = (char *)func_80100094(actor, 0);

    func_80800000_chdiggerboss(actor);
    func_80806300_chdiggerboss(actor);
    func_80807B54_chdiggerboss(actor);

    switch (*(s16 *)data) {
        case 2:
            if (func_80101DDC(actor)) {
                func_80803660_chdiggerboss(actor, 0x171E, 0x10E);
                func_80803BE8_chdiggerboss(actor, 3, 8);
            }
            break;

        case 4:
            if (func_80101DDC(actor)) {
                if (!func_80802170_chdiggerboss(actor, 0)) {
                    func_80803BE8_chdiggerboss(actor, 5, 1);
                    func_8080290C_chdiggerboss(actor, 0x2D, 0x20);
                    func_80803660_chdiggerboss(actor, 0x1720, 0x14C);
                } else {
                    func_800FDC28(0x14);
                    func_80805A00_chdiggerboss(actor, 6);
                }
            }
            break;

        case 6:
            if (func_80805A64_chdiggerboss(actor)) {
                func_80802F00_chdiggerboss(actor, 7);
            }
            break;

        case 7:
            if (func_80101DDC(actor)) {
                if (!func_80802170_chdiggerboss(actor, 1)) {
                    func_80803BE8_chdiggerboss(actor, 8, 5);
                    func_80803660_chdiggerboss(actor, 0x172E, 0x10E);
                } else {
                    func_80802FEC_chdiggerboss(actor, 9, 0);
                }
            }
            break;

        case 9:
            if (func_80802D00_chdiggerboss(actor)) {
                func_80806A78_chdiggerboss(actor, 0xA, D_80809C60_chdiggerboss);
            }
            break;

        case 10:
            switch (func_808066A0_chdiggerboss(actor)) {
            case 1:
                func_80802878_chdiggerboss(actor, 3, 1);
                func_80803BE8_chdiggerboss(actor, 0xB, 3);
                break;
            case 2:
                func_80803BE8_chdiggerboss(actor, 8, 8);
                func_80802878_chdiggerboss(actor, 3, 1);
                func_80803660_chdiggerboss(actor, 0x1731, 0x10E);
            }
            break;

        case 11:
            if (func_80101DDC(actor)) {
                func_80805A00_chdiggerboss(actor, 6);
            }
            break;

        case 12:
            if (func_80101DDC(actor)) {
                if (!func_80802170_chdiggerboss(actor, 5)) {
                    func_80803BE8_chdiggerboss(actor, 0xD, 1);
                    func_8080290C_chdiggerboss(actor, 0x30, 0x20);
                    func_80803660_chdiggerboss(actor, 0x1721, 0x14C);
                } else {
                    func_80805A00_chdiggerboss(actor, 0xE);
                }
            }
            break;

        case 14:
            if (func_80805A64_chdiggerboss(actor)) {
                func_80802F00_chdiggerboss(actor, 0xF);
            }
            break;

        case 15:
            if (func_80101DDC(actor)) {
                func_80802FEC_chdiggerboss(actor, 0x11, 0);
            }
            break;

        case 17:
            if (func_80802D00_chdiggerboss(actor)) {
                func_80806A78_chdiggerboss(actor, 0x12, D_80809C70_chdiggerboss);
            }
            break;

        case 18:
            switch (func_808066A0_chdiggerboss(actor)) {
            case 1:
                func_80802878_chdiggerboss(actor, 3, 1);
                func_80803BE8_chdiggerboss(actor, 0x13, 3);
                break;
            case 2:
                func_80803BE8_chdiggerboss(actor, 0x10, 8);
                func_80802878_chdiggerboss(actor, 3, 1);
                func_80803660_chdiggerboss(actor, 0x1732, 0x10E);
            }
            break;

        case 19:
            if (func_80101DDC(actor)) {
                func_80805A00_chdiggerboss(actor, 0xE);
            }
            break;

        case 20:
            if (func_80101DDC(actor)) {
                if (!func_80802170_chdiggerboss(actor, 6)) {
                    func_80803BE8_chdiggerboss(actor, 0x15, 1);
                    func_8080290C_chdiggerboss(actor, 0x33, 0x20);
                    func_80803660_chdiggerboss(actor, 0x1723, 0x14C);
                } else {
                    hag1 = (void *)func_80802228_chdiggerboss(actor);

                    func_8080041C_chdiggerboss(hag1, 0xE);
                    func_80807280_chdiggerboss(actor, 0x16, D_80809CF0_chdiggerboss);
                }
            }
            break;

        case 22:
            if (func_808070B0_chdiggerboss(actor)) {
                func_80802F00_chdiggerboss(actor, 0x17);
            }
            break;

        case 23:
            if (func_80101DDC(actor)) {
                func_80802FEC_chdiggerboss(actor, 0x19, 1);
            }
            break;

        case 25:
            if (func_80802D00_chdiggerboss(actor)) {
                func_80806A78_chdiggerboss(actor, 0x1A, D_80809C80_chdiggerboss);
            }
            break;

        case 26:
            switch (func_808066A0_chdiggerboss(actor)) {
            case 1:
                func_80802878_chdiggerboss(actor, 3, 1);
                func_80803BE8_chdiggerboss(actor, 0x1B, 3);
                break;
            case 2:
                func_80802878_chdiggerboss(actor, 3, 1);
                func_80803BE8_chdiggerboss(actor, 0x1C, 3);
            }
            break;

        case 27:
            if (func_80101DDC(actor)) {
                func_80807280_chdiggerboss(actor, 0x16, D_80809CF0_chdiggerboss);
            }
            break;

        case 28:
            if (func_80101DDC(actor)) {
                if (!func_80802170_chdiggerboss(actor, 7)) {
                    func_80803BE8_chdiggerboss(actor, 0x1D, 1);
                    func_8080290C_chdiggerboss(actor, 0x37, 0x20);
                    func_80803660_chdiggerboss(actor, 0x1724, 0x14C);

                    hag1_b = (void *)func_80802228_chdiggerboss(actor);

                    func_808008C0_chdiggerboss(hag1_b, 3, 1);
                } else {
                    hag1_b = (void *)func_80802228_chdiggerboss(actor);

                    func_8080041C_chdiggerboss(hag1_b, 0x10);
                    func_80807280_chdiggerboss(actor, 0x1E, D_80809D00_chdiggerboss);
                }
            }
            break;

        case 30:
            if (func_808070B0_chdiggerboss(actor)) {
                func_80802F00_chdiggerboss(actor, 0x1F);
            }
            break;

        case 31:
            if (func_80101DDC(actor)) {
                func_80802FEC_chdiggerboss(actor, 0x21, 1);
            }
            break;

        case 33:
            if (func_80802D00_chdiggerboss(actor)) {
                func_80806A78_chdiggerboss(actor, 0x22, D_80809C90_chdiggerboss);
            }
            break;

        case 34:
            switch (func_808066A0_chdiggerboss(actor)) {
            case 1:
                func_80802878_chdiggerboss(actor, 3, 1);
                func_80803BE8_chdiggerboss(actor, 0x23, 3);
                break;
            case 2:
                func_80802878_chdiggerboss(actor, 3, 1);
                func_80803BE8_chdiggerboss(actor, 0x24, 3);
            }
            break;

        case 35:
            if (func_80101DDC(actor)) {
                func_80807280_chdiggerboss(actor, 0x1E, D_80809D00_chdiggerboss);
            }
            break;

        case 36:
            if (func_80101DDC(actor)) {
                if (!func_80802170_chdiggerboss(actor, 8)) {
                    func_80803BE8_chdiggerboss(actor, 0x25, 1);
                    func_8080290C_chdiggerboss(actor, 0x36, 0x20);
                    func_80803660_chdiggerboss(actor, 0x1725, 0x14C);
                } else {
                    hag1_c = (void *)func_80802228_chdiggerboss(actor);

                    func_8080041C_chdiggerboss(hag1_c, 0x12);

                    func_80803BE8_chdiggerboss(actor, 0x26, 1);

                    func_808027F4_chdiggerboss(actor);
                }
            }
            break;

        case 38:
            hag1_d = (void *)func_80802228_chdiggerboss(actor);

            if (func_801022E4(hag1_d) == 0) {
                func_80805448_chdiggerboss(hag1_d, 0, 1);
                func_80805448_chdiggerboss(hag1_d, 3, 1);
                func_80805D64_chdiggerboss(actor, 0x27);
            }
            break;

        case 39:
            if (func_80805DF4_chdiggerboss(actor)) {
                if (*(u8 *)(data + 2) != 0x32) {
                    func_80802F00_chdiggerboss(actor, 0x28);
                } else {
                    func_80807754_chdiggerboss(actor, 0x2D, 10.0f);
                }
            }
            break;

        case 40:
            if (func_80101DDC(actor)) {
                func_80802FEC_chdiggerboss(actor, 0x2A, 2);
            }
            break;

        case 42:
            if (func_80802D00_chdiggerboss(actor)) {
                func_80806A78_chdiggerboss(actor, 0x2B, D_80809CA0_chdiggerboss);
            }
            break;

        case 43:
            if (func_808066A0_chdiggerboss(actor)) {
                func_80802878_chdiggerboss(actor, 3, 1);
                func_80803BE8_chdiggerboss(actor, 0x2C, 3);
            }
            break;

        case 44:
            if (func_80101DDC(actor)) {
                func_80807754_chdiggerboss(actor, 0x2D, 10.0f);

                if (!func_80802170_chdiggerboss(actor, 9)) {
                    func_80803660_chdiggerboss(actor, 0x1727, 0x106);
                }
            }
            break;

        case 45:
            func_8080783C_chdiggerboss(actor, 0x27);
            break;

        case 46:
            if (func_80101DDC(actor)) {
                func_800F82D4(func_800F54E4(), 0);

                func_80803660_chdiggerboss(actor, 0x1733, 0x10E);
                func_80803BE8_chdiggerboss(actor, 0x30, 8);
            }
            break;

        case 47:
            if (func_80101DDC(actor)) {
                func_80805D64_chdiggerboss(actor, 0x31);
            }
            break;

        case 49:
            if (func_80805DF4_chdiggerboss(actor)) {
                if (*(u8 *)(data + 2) != 0x28) {
                    func_80802F00_chdiggerboss(actor, 0x32);
                } else {
                    func_80807754_chdiggerboss(actor, 0x37, 8.0f);
                }
            }
            break;

        case 50:
            if (func_80101DDC(actor)) {
                func_80802FEC_chdiggerboss(actor, 0x34, 2);
            }
            break;

        case 51:
            if (func_80802D00_chdiggerboss(actor)) {
                func_80806A78_chdiggerboss(actor, 0x35, D_80809CB0_chdiggerboss);
            }
            break;

        case 52:
            if (func_80802D00_chdiggerboss(actor)) {
                func_80806A78_chdiggerboss(actor, 0x35, D_80809CB0_chdiggerboss);
            }
            break;

        case 53:
            if (func_808066A0_chdiggerboss(actor)) {
                func_80802878_chdiggerboss(actor, 3, 1);
                func_80803BE8_chdiggerboss(actor, 0x36, 3);
            }
            break;

        case 54:
            if (func_80101DDC(actor)) {
                func_80807754_chdiggerboss(actor, 0x37, 8.0f);
            }
            break;

        case 55:
            func_8080783C_chdiggerboss(actor, 0x31);
            break;

        case 56:
            if (func_80101DDC(actor)) {
                func_800F82D4(func_800F54E4(), 0);

                if (!func_80802170_chdiggerboss(actor, 0xC)) {
                    func_8080290C_chdiggerboss(actor, 0x3C, 0x20);
                    func_80803660_chdiggerboss(actor, 0x1734, 0x14C);
                } else {
                    hag1_e = (void *)func_80802228_chdiggerboss(actor);

                    func_80804A50_chdiggerboss(hag1_e, 0);

                    i = 0;
                    do {
                        func_80805448_chdiggerboss(hag1_e, i, 2);
                        i++;
                    } while (i != 4);

                    func_808041E4_chdiggerboss(hag1_e, 4);

                    func_80802878_chdiggerboss(actor, 3, 1);

                    func_80803660_chdiggerboss(actor, 0x1729, 0x10E);
                }

                func_80803BE8_chdiggerboss(actor, 0x39, 8);
            }
            break;

        case 58:
            switch (func_808066A0_chdiggerboss(actor)) {
            case 1:
                func_80806A78_chdiggerboss(actor, 0x3A, D_80809CC0_chdiggerboss);
                break;
            case 2:
                func_80803BE8_chdiggerboss(actor, 0x3B, 8);

                if (!func_80802170_chdiggerboss(actor, 0xD)) {
                    func_8080290C_chdiggerboss(actor, 0x40, 0x20);
                    func_80803660_chdiggerboss(actor, 0x172A, 0x14C);
                } else {
                    hag1_f = (void *)func_80802228_chdiggerboss(actor);

                    func_8080041C_chdiggerboss(hag1_f, 0x14);

                    func_80806A78_chdiggerboss(actor, 0x3C, D_80809CD0_chdiggerboss);

                    func_80806EE4_chdiggerboss(actor, 1);
                }
            }
            break;

        case 60:
            switch (func_808066A0_chdiggerboss(actor)) {
            case 1:
                func_80806A78_chdiggerboss(actor, 0x3C, D_80809CD0_chdiggerboss);
                break;
            case 2:
                if (!func_80802170_chdiggerboss(actor, 0xE)) {
                    func_80803BE8_chdiggerboss(actor, 0x3D, 8);
                    func_8080290C_chdiggerboss(actor, 0x44, 0x20);
                    func_80803660_chdiggerboss(actor, 0x172B, 0x14C);
                } else {
                    hag1_g = (void *)func_80802228_chdiggerboss(actor);

                    func_80806A78_chdiggerboss(actor, 0x3E, D_80809CE0_chdiggerboss);

                    func_80806EE4_chdiggerboss(actor, 1);
                    func_80807DC0_chdiggerboss(actor, 2);
                    func_808080C0_chdiggerboss(hag1_g, 2);
                }
            }
            break;

        case 62:
            switch (func_808066A0_chdiggerboss(actor)) {
            case 1:
                func_80806A78_chdiggerboss(actor, 0x3E, D_80809CE0_chdiggerboss);
                break;
            case 2:
                func_808080C0_chdiggerboss(func_80802228_chdiggerboss(actor), 0);

                func_80807DF4_chdiggerboss(actor);

                if (!func_808021E8_chdiggerboss(actor, 0xB)) {
                    func_80803BE8_chdiggerboss(actor, 0x3F, 8);
                    func_80802BE0_chdiggerboss(actor, 3.0f);
                    func_80802878_chdiggerboss(actor, 3, 1);
                    func_80803660_chdiggerboss(actor, 0x172C, 0x10E);
                } else {
                    func_80802BE0_chdiggerboss(actor, 1.0f);

                    *(u8 *)(data + 0xCD) = 1;

                    func_80808470_chdiggerboss(actor, 0x40);
                }
            }
            break;

        case 64:
            func_80808258_chdiggerboss(actor);
            break;

        case 65:
            if (func_80101DDC(actor)) {
                func_80803BE8_chdiggerboss(actor, 0x42, 1);
            }
            break;

        case 67:
            if (!func_808091E4_chdiggerboss(actor)) {
                func_80802878_chdiggerboss(actor, 5, 1);

                func_80803BE8_chdiggerboss(actor, 0x44, -1);

                *(f32 *)(data + 0xF8) = 0.4f;
            }
            break;

        case 68:
            if (func_800D9078(data + 0xF8)) {
                unk_0 = (void *)func_80802248_chdiggerboss(actor);

                func_800F7B9C(unk_0, 0x63);
                func_800F7C58(unk_0, 0x61, 2);

                func_80803BE8_chdiggerboss(actor, 0x45, -1);

                *(f32 *)(data + 0xF8) = 1.0f;
            }
            break;

        case 69:
            if (func_800D9078(data + 0xF8)) {
                if (func_800D395C()) {
                    func_800FDC28(0);
                    _gcfrontend_entrypoint_10();
                } else {
                    func_80803660_chdiggerboss(actor, 0x14D8, 0x10E);

                    func_80803BE8_chdiggerboss(actor, 0x46, -1);
                }
            }
            break;

        case 71:
            if (func_80101DDC(actor)) {
                func_80803BE8_chdiggerboss(actor, 0x48, 8);

                if (func_800D395C()) {
                    func_80803660_chdiggerboss(actor, 0xCEB, 0x144);
                }
            }
        case 72:
            break;
    }
if (((DiggerExpressionFlags *) actor)->field_3) {
    _suexpression_entrypoint_10(func_80100094(actor, 1), *(s32 *) actor, 0);
}

}

// Gruntilda free.
s32 func_808019A8_chdiggerboss(actor)
s32 actor;
{
    func_808027F4_chdiggerboss(actor);
    func_80802EF8_chdiggerboss(actor);
    func_80807B4C_chdiggerboss(actor);
    func_8080666C_chdiggerboss(actor);
    func_808059CC_chdiggerboss(actor);
    func_8080843C_chdiggerboss(actor);
    _suexpression_entrypoint_8(actor, 1);
}

// TU-NOTE: .bss is defined here in C, ahead of its first use: IDO places .bss objects used
// before their definition first, the rest in definition order.
s32 B_8080A300_chdiggerboss;

// Gruntilda message handler.
s32 func_80801A04_chdiggerboss(u8 *actor, s32 msg, u32 arg)
{
    s32 *partner;
    s32 unk_0;
    s32 hag1;
    s32 i;
    f32 vec[3];


    switch (msg) {
    case 0x49:
        partner = (s32 *)func_801084B0(0x203, (u32 **)&actor);
        *(s32 *)(actor + 0x3C) = *partner;
        *(s32 *)((u8 *)partner + 0x3C) = *(s32 *)actor;
        break;
    case 0x57:
        return func_80802718_chdiggerboss(actor, *(s32 *)&arg & 0xFFFF, (arg & 0xFFFF0000) >> 16);
    case 0x20:
        func_80803078_chdiggerboss(actor, func_80101080(), ((s16 *)&arg)[0], ((s16 *)&arg)[1]);
        return 1;
    case 0x95:
        func_80801DE0_chdiggerboss(actor);
        return 1;
    case 0xB:
        return func_80802AB8_chdiggerboss(actor, arg);
    case 0x2E:
        func_80803694_chdiggerboss(actor, ((s16 *)&arg)[0], ((s16 *)&arg)[1]);
        return 1;
    case 0x2F:
        func_808039C0_chdiggerboss(actor, ((s16 *)&arg)[0], ((s16 *)&arg)[1]);
        return 1;
    case 0x52:
        func_808029C8_chdiggerboss(actor);
        return 1;
    case 0x1F:
        func_80800568_chdiggerboss(actor, *(u32 *)&arg);
        return 1;
    case 0x9C:
        func_808005DC_chdiggerboss(actor, *(u32 *)&arg);
        return 1;
    case 0x40:
        if (((u8 *)func_80100094(actor, 0))[3] != 0) {
            func_808086E8_chdiggerboss(actor, *(u32 *)&arg);
        } else {
            func_80806DC4_chdiggerboss(actor, *(u32 *)&arg);
            }
        return 1;
    case 0x3D:
        switch (arg) {
        case 0:
            func_80806CF8_chdiggerboss(actor, arg);
            return 1;
        case 1:
        case 2:
            func_80807304_chdiggerboss(actor, arg);
            return 1;
        case 4:
            func_80807E3C_chdiggerboss(actor, arg);
            return 1;
        case 5:
            func_808085E0_chdiggerboss(actor, arg);
        }
        break;
    case 0x96:
        if (func_800D395C() == 0) {
            return 0;
        }
        func_80803660_chdiggerboss(actor, 0xCEB, 0x46);
        return 1;
    case 0x9F:
        hag1 = func_80802228_chdiggerboss(actor);
        i = 0;
        do {
            func_80805448_chdiggerboss(hag1, i, 0);
            i++;
        } while (i != 4);
        func_800FDC28(0);
        func_80800618_chdiggerboss(actor, 0, 0);
        if (func_80802288_chdiggerboss(actor) != 0) {
            func_800D395C();
            func_80803BE8_chdiggerboss(actor, 0x48, 8);
        } else {
            func_80803BE8_chdiggerboss(actor, 0x47, 2);
        }
        return 1;
    case 0x29:
        _suexpression_entrypoint_7(actor, 1, 0x22);
        return 1;
    case 0x2A:
        _suexpression_entrypoint_8(actor, 1);
        return 1;
    case 0xA2:
        if (!((DB7C *)actor)->f || func_80802288_chdiggerboss(actor) == 0) {
            return 0;
        }
        func_80802298_chdiggerboss(actor, &B_8080A300_chdiggerboss);
        func_80101074(&B_8080A300_chdiggerboss);
        return 1;
    case 0x90:
        func_80809310_chdiggerboss(actor);
        return 1;
    case 0x8D:
        func_800EE7F8(vec, actor + 4);
        vec[1] += 250.0f;
        func_80101010(vec);
        return 1;
    case 0xB5:
        func_80806CA4_chdiggerboss(actor, arg);
        return 1;
    default:
        return 0;
    }
return 1;
}

void func_80801DE0_chdiggerboss(u8 *actor)
{
    u8 *data;
    u8 *hag;
    u8 *hag_data;
    s32 unk_0;
    s32 unk_1;
    s16 state;
    s32 map_id;
    u8 *hag_actor;

    data = func_80100094(actor, 0);
    func_80109FE8(actor, 0);
    func_80807B18_chdiggerboss(actor);
    func_80806648_chdiggerboss(actor);
    func_808059A4_chdiggerboss(actor);

if (*(s16 *) ((s8 *) data + 0xA0) == 0) {
    map_id = func_800EA05C();
    switch (map_id) {
        case 0x15D:
            if (func_800DA298(0x44) == 0) {
                func_8080290C_chdiggerboss(actor, 0x1C, 0x20);
                func_80803660_chdiggerboss(actor, 0x171C, 0x144);
                func_800F82D4(func_800F54E4(), 1);
                func_800F8444(func_800F54E4(), actor + 0x44);
                func_80101180(0x4F1, 7, 0);
                return;
            }
            func_800FFAB0(actor);
            func_800FFAB0(func_80802228_chdiggerboss(actor));
            return;
        case 0x19A:
            if (func_800DA298(0x44) == 0) {
                func_800F82D4(func_800F54E4(), 1);
                func_800F8444(func_800F54E4(), actor + 0x44);
                func_8080290C_chdiggerboss(actor, 0xD, 0x2020);
                _chintrotext_entrypoint_1(0x18B9, 0xF, 1, 0);
                func_800FDC28(1);
                func_800C964C(0x14);
                return;
            }
            func_80802878_chdiggerboss(actor, 3, 1);
            func_80800180_chdiggerboss(actor, 8);
            func_80803660_chdiggerboss(actor, 0x171F, 0x10E);
            func_800FDC28(1);
    }
} else {

hag_actor = func_80802228_chdiggerboss(actor);
hag = hag_actor;
hag_data = func_80100094(hag_actor, 0);
state = (*(s16 *) ((s8 *) (data) + (0)));

        switch (state) {                          
        case 0x2D:                                  
            unk_0 = func_80802314_chdiggerboss() < 2;
            func_80804A50_chdiggerboss(hag, 1);
            func_80807698_chdiggerboss(actor, unk_0);
            if (unk_0 != 0) {
                *(s8 *)((s8 *)data + 2) = 0x32;
                func_80803BE8_chdiggerboss(actor, 0x2E, 2);
                func_80802878_chdiggerboss(actor, 3, 1);
                func_808041E4_chdiggerboss(hag, 2);
                func_800F82D4(func_800F54E4(), 2);
                func_800F7C58(func_800F54E4(), 0x8A, 1);
            } else {
                func_808041E4_chdiggerboss(hag, 3);
            }
            break;
        case 0x37:                                  
            unk_1 = func_80802314_chdiggerboss() == 0;
            func_808041E4_chdiggerboss(hag, 2);
            func_80804A50_chdiggerboss(hag, 1);
            func_80807698_chdiggerboss(actor, unk_1);
            if (unk_1 != 0) {
                *(s8 *)((s8 *)data + 2) = 0x28;
                func_80803BE8_chdiggerboss(actor, 0x38, 2);
                func_80802878_chdiggerboss(actor, 3, 1);
                func_800F82D4(func_800F54E4(), 2);
                func_800F7C58(func_800F54E4(), 0x8A, 1);
            } else {
                func_808041E4_chdiggerboss(hag, 3);
            }
        }
(*(s16 *) ((s8 *) (data) + (0xA0))) = 0;
(*(u8 *) ((s8 *) (actor) + (0x75))) = (u8) ((*(u8 *) ((s8 *) (actor) + (0x75))) & 0xFFFD);
(*(s8 *) ((s8 *) (hag_data) + (6))) = 1;
}
}

int func_80802158_chdiggerboss(unused, index)
s32 unused;
s32 index;
{
    u16 *table = &D_80809EE4_chdiggerboss;
    return table[index];
}

s32 func_80802170_chdiggerboss(actor, index)
Actor *actor;
s32 index;
{
    DiggerFlags1473 *data;
    s32 game_flag;

    data = func_80100094(actor, 0);
    if (!data->local_0[index]) {
        game_flag = func_80802158_chdiggerboss((s32) actor, index);

if (game_flag) {
    func_800DA544(game_flag);
}

data->local_0[index] = 1;
return 0;
}
return 1;
}

int func_808021E8_chdiggerboss(s32 actor, s32 index)
{
    u8 *flags;
    flags = (u8 *) func_80100094(actor, 0) + index;
    if (!flags[0xFD]) {
        return 0;
    }
    return 1;
}

int func_80802228_chdiggerboss(actor)
Actor *actor;
{
    func_80106790(actor->unk3C);
}

s32 func_80802248_chdiggerboss(s32 actor)
{
    s32 found;
    s32 player;
    found = func_8010D290(0x10000);
    player = found;
    if (player == (-1)) {
        player = func_800F54E4();
    }
    // Matching: empty block steers IDO's code generation.
    {
    }
    return player;
}

int func_80802288_chdiggerboss(Actor *actor)
{
    return (*(u16 *) ((char *) actor + 0x64) & 1);
}

void func_80802298_chdiggerboss(actor, out_pos) Actor *actor;
f32 *out_pos;
{
    func_800EE7F8(out_pos, actor->position);
    func_800EF1B8(out_pos, actor->rotation[1], actor->scale * 600.0f);
    out_pos[1] += actor->scale * 2500.0f;
}

s32 func_80802314_chdiggerboss(void)
{
    s32 counter;
    counter = func_800DA980(0xA4F, 2);
    return 2 - counter;
}

s32 func_8080233C_chdiggerboss(s32 actor)
{
    func_80102FDC(actor, 0.25f);
    func_8010A828(actor, 3);
    func_80803DC8_chdiggerboss(actor, 1, 1);
    func_808008C0_chdiggerboss(actor, 5, 1);
    func_80803E10_chdiggerboss(actor);
    func_80804784_chdiggerboss(actor);
    func_80804C28_chdiggerboss(actor);
    func_80807640_chdiggerboss(actor);
    func_80807FD8_chdiggerboss(actor);
    func_808088AC_chdiggerboss(actor);
    func_80808C64_chdiggerboss(actor);
    func_80108B04(actor, 7);
}

void func_808023D8_chdiggerboss(Actor *actor)
{
    u8 *data;
    Actor *other;
    s32 i;
    f32 *pos;
    data = func_80100094(actor, 0);
    func_80800200_chdiggerboss(actor);
    func_80803E84_chdiggerboss(actor);
    func_808047A8_chdiggerboss(actor);
    func_80804D44_chdiggerboss(actor);
    func_80808034_chdiggerboss(actor);
    func_808088CC_chdiggerboss(actor);
    func_80808CD0_chdiggerboss(actor);
    pos = actor->position;
    _subaddieaudioloop_entrypoint_4(actor, pos, data[7], &D_80809F04_chdiggerboss);
    if (data[7])
        _subaddieDll_entrypoint_7(actor, 8);
    for (i = 0; i < 8; i++) {
        if (func_800F6438(i))
            func_800F4E5C(i, pos, actor->rotation, &D_80809F10_chdiggerboss,
                          &D_80809F1C_chdiggerboss);
    }
    if (*(s32 *) ((u8 *) actor + 0x3C)) {
        other = (Actor *) func_808026F8_chdiggerboss(actor);
        func_800EE7F8(other->position, pos);
        other->rotation[1] = actor->rotation[1];
    }
    if (*(Unk80132ED0 **) data) {
        other = func_80106790(*(Unk80132ED0 **) data);
        func_800EE7F8(other->position, pos);
        other->position[1] += 300.0f;
    }
}

void func_80802550_chdiggerboss(s32 actor)
{
    s32 *data;

    data = func_80100094(actor, 0);
    func_808040D8_chdiggerboss(actor);
    func_808049A8_chdiggerboss(actor);
    func_808053BC_chdiggerboss(actor);
    func_80807664_chdiggerboss(actor);
    func_80808000_chdiggerboss(actor);
    func_80808948_chdiggerboss(actor);
    if (func_801069A4(*data) != 0) {
        func_800FFA88(*data);
        *data = 0;
    }
}

s32 func_808025D4_chdiggerboss(Actor *actor, s32 msg, s32 msg_arg)
{
    s32 *data;
    s32 *unk_0;

    // Matching: taking the address of msg_arg is needed for the match.
    unk_0 = &msg_arg;
    switch (msg) {
        case 0x1F:
            func_808006F8_chdiggerboss(actor, msg_arg);
            return 1;
        case 0x9C:
            func_808007E0_chdiggerboss(actor, msg_arg);
            return 1;

case 0x3D:
    switch (msg_arg) {
        case 3:
            func_8080815C_chdiggerboss(actor, msg_arg);
            return 1;
        case 6:
            func_808089BC_chdiggerboss(actor, msg_arg);
            return 1;
        case 7:
            data = func_80100094(actor, 0);
            *data = *func_801084B0(0x4FF, &actor);
    }

break;
case 0x3F:
    func_808058B0_chdiggerboss(actor, msg_arg);
case 0x95:
    break;
default:
    return 0;

}
return 1;
}

s32 func_808026F8_chdiggerboss(actor) Actor *actor;
{
    func_80106790(actor->unk3C);
}

s32 func_80802718_chdiggerboss(s32 actor, s32 unk_1, s32 unk_2)
{
    if (_gcdialogcamera_entrypoint_0(unk_1, unk_2) != 0) {
        if (*(s16 *) ((s8 *) func_80100094(actor, 0) + 8) != 2) {
            func_80802878_chdiggerboss(actor, 2, 1);
        }

return 2;
}
return 1;
}

void func_80802778_chdiggerboss(Actor *actor, s32 unk_1)
{
    s16 *data;
    data = func_80100094(actor, 0);
    _capod_entrypoint_2(actor->unk0, 0x22, unk_1 | 0x80000);
    if (data[5] == 0) {
        func_800F7F98(func_80802248_chdiggerboss(actor), 1);
        data[5] = 1;
    }
}

s32 func_808027F4_chdiggerboss(actor)
Actor *actor;
{
    s16 *data;
    s32 player;

    data = func_80100094(actor, 0);
    player = func_80802248_chdiggerboss(actor);
    if (data[5]) {
        func_800F7F98(player, 0);
        data[5] = 0;
    }
    if (data[4]) {
        _capod_entrypoint_3(0);
        _plcamera_entrypoint_8(player);
        data[4] = 0;
        return 1;
    }
    return 0;
}

void func_80802878_chdiggerboss(actor, unk_1, unk_2) s32 actor;
s32 unk_1;
s32 unk_2;
{
    s16 *data;
    s16 state;
    data = func_80100094(actor, 0);
    state = (*(s16 *) ((char *) (data) + 8));
    switch (state) {
        case 0:
            func_80802778_chdiggerboss(actor, 0);
            // fallthrough
        case 1:
            _capod_entrypoint_8(1);
            *((s16 *) ((s8 *) data + 8)) = 2;
            // fallthrough
        case 2:
            func_808029C8_chdiggerboss(actor);
            _gcdialogcamera_entrypoint_8();
            _capod_entrypoint_7(unk_1, unk_2);
    }
}

void func_8080290C_chdiggerboss(actor, unk_1, unk_2) s32 *actor;
s32 unk_1;
s32 unk_2;
{
    func_80802938_chdiggerboss(actor, *actor, unk_1, unk_2);
}

void func_80802938_chdiggerboss(actor, unk_1, unk_2, unk_3) s32 actor;
s32 unk_1;
s32 unk_2;
s32 unk_3;
{
    s32 *data;
    data = (s32 *) func_80100094(actor, 0);
    switch (*(s16 *) ((char *) data + 0x8)) {
        case 0:
            func_80802778_chdiggerboss(actor, unk_3);
            // fallthrough
        case 2:
            *(s16 *) ((char *) data + 0x8) = 1;
            // fallthrough
        case 1:
            _capod_entrypoint_6(unk_1, unk_2, unk_3 | 0x80000);
    }
}

void func_808029C8_chdiggerboss(actor) Actor *actor;
{
    f32 rot[3];
    f32 pos[3];
    f32 unk_0[4];
    f32 size;
    DiggerCameraData *data;

    data = func_80100094(actor, 0);
    func_800EE7F8(rot, actor->rotation);
    rot[1] += data->local_1;
    func_800EE7F8(pos, actor->position);
    func_800EF1B8(pos, actor->rotation[1], actor->scale * 400.0f);
    size = actor->scale * data->local_0;
    unk_0[0] = actor->scale * 2700.0f;
    unk_0[1] = 800.0f * size;
    unk_0[2] = 500.0f * size;
    unk_0[3] = actor->scale * 2100.0f;
    _gcdialogcamera_entrypoint_3(unk_0, 1.0f);
    _gcdialogcamera_entrypoint_4(pos);
    _gcdialogcamera_entrypoint_5(rot);
}

s32 func_80802AB8_chdiggerboss(Actor *actor, s32 state)
{
    switch (state) {
        case 0x1C:
            func_8080290C_chdiggerboss(actor, 0x1F, 0x20);
            return 4;
        case 0x1F:
            func_800F82D4(func_800F54E4(), 0);
            _gcgoto_entrypoint_2(0x19A, 1, 0);
            func_800A7AD4(1, 0x15);
            break;
        case 0xD:
            func_800F82D4(func_800F54E4(), 0);
            func_80803660_chdiggerboss(actor, 0x171D, 0x14C);
            func_8080290C_chdiggerboss(actor, 0x18, 0x20);
            return 4;
        case 0x18:
            func_800DA544(0x44);
            _gcfrontend_entrypoint_9(0x2C);
            func_80802878_chdiggerboss(actor, 3, 1);
            func_80803BE8_chdiggerboss(actor, 2, 2);
            return 4;
        case 0x3B:
            func_80805D64_chdiggerboss(actor, 0x27);
            return 4;
    }
    return 3;
}

void func_80802BE0_chdiggerboss(s32 actor, f32 value)
{
    ((f32 *) func_80100094(actor, 0))[3] = value;
}

void func_80802C0C_chdiggerboss(s32 actor)
{
    func_800F4AF4(func_80802248_chdiggerboss(actor), 0x14);
    func_80802C40_chdiggerboss(actor);
}

void func_80802C40_chdiggerboss(actor) Actor *actor;
{
    f32 pos_buf[3];
    f32 *pos;
    s32 player;

    pos = pos_buf;
    player = func_80802248_chdiggerboss(actor);
    func_800EE7F8(pos, actor->position);
    pos[1] += 500.0f;
    _plcamera_entrypoint_9(player, pos, 0.0f);
    func_80116088(func_80110014(func_800F5EF8(player)), pos);
}

void func_80802CB4_chdiggerboss(s32 actor)
{
    func_800F4B20(func_80802248_chdiggerboss(actor));
}

void func_80802CDC_chdiggerboss(actor) s32 actor;
{
    s8 *data = func_80100094(actor, 0);
    data[0x42] = 0;
}

// Matching: the line breaks in this function are needed for the match.
s32 func_80802D00_chdiggerboss(actor)
Actor *actor;
{
    u8 *data;
    u8 *menu;

    data = func_80100094(actor, 0);
    menu = (u8 *) func_80100094(actor, 0) + 0x10C;
    switch (data[0x40]) {
        case 0:
            break;
        case 1:
            func_80803224_chdiggerboss(actor);
            break;
        case 2:
            _gcnewoption_entrypoint_0(menu);
            break;
        case 3:
            _gcnewoption_entrypoint_0(menu);

if (func_800D9078((f32 *) (data + 0x4C))) {
    _gcnewoption_entrypoint_37(menu, 1);
}

break;
case 4:
    _gcnewoption_entrypoint_7(menu);
    data[0x42] = 0;
    func_8010A828(actor, 1);

        if (data[0x41] && !func_80802170_chdiggerboss(actor, 3)) {
            func_80802878_chdiggerboss(actor, 5, 1);
            func_80803660_chdiggerboss(actor, 0x172F, 0x106);
            data[0x40] = 6;
            *(s16 *)(data + 0x46) = 1;
            break;
        }
        if (!data[0x41] && !func_80802170_chdiggerboss(actor, 4)) {
            func_80802878_chdiggerboss(actor, 5, 1);
            func_80803660_chdiggerboss(actor, 0x1730, 0x106);
            data[0x40] = 6;
            *(s16 *)(data + 0x46) = 1;
            break;
        }
func_80800180_chdiggerboss(actor, 6);
data[0x40] = 5;
break;

case 5:
    if (func_80101DDC(actor)) {
        func_800F82D4(func_800F54E4(), 0);
        func_80800618_chdiggerboss(actor, 0, 0);
        func_80800180_chdiggerboss(actor, 8);
        data[0x40] = 0;
        return 1;
    }

break;

case 6:
    if (*(s16 *) (data + 0x46) == 0) {
        func_80800180_chdiggerboss(actor, 6);
        data[0x40] = 5;
    }

}
return 0;
}

void func_80802EF8_chdiggerboss(s32 unused)
{
}
void func_80802F00_chdiggerboss(actor, state) Actor *actor;
s32 state;
{
    s32 player;
    f32 player_pos[3];
    f32 target_pos[3];

    func_80803BE8_chdiggerboss(actor, state, 2);
    func_80802878_chdiggerboss((s32) actor, 3, 1);
    func_80800618_chdiggerboss(actor, 0, 1);
    func_808056B8_chdiggerboss(func_80802228_chdiggerboss(actor));
    player = func_800F54E4();
    func_800F5A00(player, player_pos);
    if (func_800EFB8C(player_pos, actor->position) < 550.0f) {
        func_800EEB9C(target_pos, func_800F1DF4(actor->position, player_pos), 550.0f);
        func_800EF04C(target_pos, actor->position);
        target_pos[1] = player_pos[1];
        func_800F8418(player, target_pos);
    }
    func_800F7F98(player, 1);
}

void func_80802FEC_chdiggerboss(actor, state, group) s32 actor;
s32 state;
s32 group;
{
    u8 *data;
    u8 *data_tmp;

    data_tmp = func_80100094(actor, 0);
    data = data_tmp;
    (*(s8 *) ((s8 *) (data_tmp) + (0x40))) = 1;
    (*(s8 *) ((s8 *) (data_tmp) + (0x43))) = (s8) group;
    (*(s16 *) ((s8 *) (data) + (0x44))) = func_80803424_chdiggerboss(actor, group);
    func_800F7F98(func_800F54E4(), 0);
    func_800F8300(func_800F54E4(), 2, actor + 4);
    func_80803BE8_chdiggerboss(actor, state, 4);
}

void func_80803078_chdiggerboss(actor, menu, correct_index, event) s32 *actor;
s32 menu;
s32 correct_index;
u32 event;
{
    u8 *data;
    u8 *unk_0;
    s32 correct;
    s32 is_correct;
    u8 *data_tmp;

    data_tmp = func_80100094(actor, 0);
    data = data_tmp;
    switch (event) {
        case 0:
            func_80803338_chdiggerboss(menu, data);
            return;
        case 2:
            func_80803610_chdiggerboss(actor, data);
            (*(s8 *) ((s8 *) (data) + (0x40))) = 4;
            return;
        case 4:
            is_correct = _gcnewoption_entrypoint_3(menu, data) == correct_index;
            correct = is_correct;
            (*(s8 *) ((s8 *) (data) + (0x48))) = 0;
            (*(s8 *) ((s8 *) (data) + (0x41))) = (s8) is_correct;
            func_80803610_chdiggerboss(actor, data);

if (correct != 0) {
    _gcnewoption_entrypoint_38(menu, 1);
    func_800FC660(0xE);
    return;
}

_gcnewoption_entrypoint_37(menu, 1);
func_800FC660(0xF);
return;
case 5:
    (*(s8 *) ((s8 *) (data) + (0x41))) = 0;
    (*(s8 *) ((s8 *) (data) + (0x48))) = 0;
    func_80803610_chdiggerboss(actor, data);
    _gcnewoption_entrypoint_37(menu, 1);
    func_800FC660(0xF);
    return;
case 3:
    func_80803610_chdiggerboss(actor, data);
    (*(s8 *) ((s8 *) (data) + (0x40))) = 4;
    return;
case 9:
    func_800CE8D8(8, 5.0f, 5);
    func_800CE928(8, &_chdiggerboss_entrypoint_2, *actor);
    func_800CEA38(8, 1);
    func_800CE88C(8, 1);
    return;

case 10:
    if (*(u8 *) ((s8 *) data_tmp + 0x48) == 0) {
        *(s8 *) ((s8 *) data_tmp + 0x40) = 3;
        *(f32 *) ((s8 *) data_tmp + 0x4C) = 0.4f;
    }


}
}

void func_80803224_chdiggerboss(Actor *actor)
{
    u8 *data;
    u8 *menu;
    data = (u8 *) func_80100094(actor, 0);
    menu = (u8 *) func_80100094(actor, 0) + 0x10C;
    bzero(menu, _gcnewoption_entrypoint_2());
    _gcnewoption_entrypoint_5(menu, _gcnewoption_entrypoint_35, 0, *(u16 *) (data + 0x44),
                              actor->unk0);
    _gcnewoption_entrypoint_8(menu, 3);
    _gcnewoption_entrypoint_9(menu, 3);
    _gcnewoption_entrypoint_10(menu, 2);
    _gcnewoption_entrypoint_14(menu, 0, 0, 0, 4.0f);
    _gcnewoption_entrypoint_32(menu, 0x22);
    _gcnewoption_entrypoint_30(menu, D_80809F34_chdiggerboss);
    _gcnewoption_entrypoint_28(menu);
    _gcnewoption_entrypoint_29(menu, 1);
    _gcnewoption_entrypoint_11(menu);
    data[0x40] = 2;
    data[0x42] = 1;
    data[0x48] = 1;
    func_8010A828(actor, 9);
}

void func_80803338_chdiggerboss(menu) s32 menu;
{
    s32 i;

    i = 0;
    do {
        _gcnewoption_entrypoint_12(menu, i, (s16) (i + 0xA));
        _gcnewoption_entrypoint_21(menu, i);
        i += 1;
    } while (i != 3);
}

int func_808033A0_chdiggerboss(s32 actor, s32 group, s32 *out_count)
{
    s32 data;
    data = func_80100094(actor, 0);
    switch (group) {
        case 0:
            *out_count = 0x14;
            return data + 0x50;

        case 1:
            *out_count = 0x14;
            return data + 0x53;

        case 2:
            *out_count = 0x14;
            return data + 0x56;

}
return 0;
}

// Picks a random unused entry of the group; clears the used bits once all are taken.
s32 func_80803424_chdiggerboss(actor, group)
Actor *actor;
s32 group;
{
    s32 count;
    s32 index;
    s32 i;
    void *bits;

    bits = func_808033A0_chdiggerboss(actor, group, &count);
    index = func_800DC128(0, count);
    for (i = 0; i < count; i++) {
        if (!func_80803524_chdiggerboss(bits, index)) {
            func_80803558_chdiggerboss(bits, index, 1);
            return D_80809F28_chdiggerboss[group][0] + index;
        }

index++;

if (index == count) {
    index = 0;
}

}
bzero(bits, (count + 7) >> 3);
index = func_800DC128(0, count);
func_80803558_chdiggerboss(bits, index, 1);
return D_80809F28_chdiggerboss[group][0] + index;
}

u8 func_80803524_chdiggerboss(bits, index)
s32 bits;
s32 index;
{
    u8 *ptr;
    u8 val;
    u8 result;
    ptr = (u8 *) bits;
    // Matching: ^ 0 is needed for the match.
    val = ptr[index >> 3] ^ 0;
    if (val & (1 << (index & 7))) {
        result = 1;
    } else {
        result = 0;
    }
    return result;
}

void func_80803558_chdiggerboss(bits, index, set) u8 *bits;
s32 index;
unsigned int set;
{
    // Matching: the comma expression in the index is needed for the match.
    s32 mask = 1 << (index & 7);
    if (set) {
        bits[0, index >> 3] |= mask;
    } else {
        bits[0, index >> 3] &= ~mask;
    }
}

void chdiggerboss_entrypoint_2(s32 unused, s32 handle)
{
    s32 actor;
    u8 *data;
    s32 menu;
    s32 actor_tmp;

    actor_tmp = func_80106790(handle);
    actor = actor_tmp;
    data = func_80100094(actor_tmp, 0);
    menu = (u8 *) func_80100094(actor, 0) + 0x10C;
    if ((*(u8 *) ((s8 *) (data) + (0x40))) == 2) {
        _gcnewoption_entrypoint_37(menu, 1);
    }
}

s32 func_80803610_chdiggerboss(unused)
s32 unused;
{
    if (func_800CEAA8(8)) {
        func_800CE928(8, 0, 0);
        func_800CE88C(8, 0);
        func_800CEBD8(8, 0);
    }
}

int func_80803660_chdiggerboss(actor, dialog_id, unk_2)
s32 actor[4];
s32 dialog_id;
s32 unk_2;
{
    u32 unk_0;
    unk_0 = actor[0];
    return _subaddiedialog_entrypoint_11(unk_0, dialog_id, unk_2, actor + 1, 0x22);
}

void func_80803694_chdiggerboss(actor, dialog_id, unk_2) s32 actor;
s32 dialog_id;
s32 unk_2;
{
    u8 *data;
    u8 *data_tmp;

    data_tmp = func_80100094(actor, 0);
    data = data_tmp;
    switch (dialog_id) {
        case 0x171D:
            break;
        case 0x171E:
        case 0x171F:
            func_80803BE8_chdiggerboss(actor, 4, 3, dialog_id);
            return;
        case 0x1720:
            func_800FDC28(0x14);
            func_80805A00_chdiggerboss(actor, 6);
            return;
        case 0x172E:
            func_80802FEC_chdiggerboss(actor, 9, 0, dialog_id);
            return;
        case 0x172F:;
        case 0x1730:
            func_80802878_chdiggerboss(actor, 3, 1, dialog_id);

if (func_80802170_chdiggerboss(actor, 2) == 0) {
    func_80803660_chdiggerboss(actor, 0x1722, 0x106);
    return;
}

func_800C0850();
(*(s16 *)((s8 *)(data) + (0x46))) = 0;
return;
case 0x1722:
(*(s16 *)((s8 *)(data_tmp) + (0x46))) = 0;
return;
case 0x1721:
func_80805A00_chdiggerboss(actor, 0xE);
return;
case 0x1723:
func_80807280_chdiggerboss(actor, 0x16, &D_80809CF0_chdiggerboss, dialog_id);
return;
case 0x1724:
func_80807280_chdiggerboss(actor, 0x1E, &D_80809D00_chdiggerboss, dialog_id);
return;
case 0x1725:
func_8080290C_chdiggerboss(actor, 0x3B, 0, dialog_id);
func_80803660_chdiggerboss(actor, 0x1726, 0x14C);
return;
case 0x1731:
func_80803BE8_chdiggerboss(actor, 0xC, 3, dialog_id);
return;
case 0x1732:
func_80803BE8_chdiggerboss(actor, 0x14, 3, dialog_id);
return;
case 0x1733:
func_80803BE8_chdiggerboss(actor, 0x2F, 3, dialog_id);
return;
case 0x1734:
func_80802878_chdiggerboss(actor, 3, 1, dialog_id);
func_80803660_chdiggerboss(actor, 0x1729, 0x10E);
return;
case 0x1729:
func_80806A78_chdiggerboss(actor, 0x3A, &D_80809CC0_chdiggerboss, dialog_id);
func_80806EE4_chdiggerboss(actor, 1);
(*(s8 *)((s8 *)(data) + (4))) = 1;
return;
case 0x172A:
func_80806A78_chdiggerboss(actor, 0x3C, &D_80809CD0_chdiggerboss, dialog_id);
func_80806EE4_chdiggerboss(actor, 1);
return;
case 0x172B:
func_80806A78_chdiggerboss(actor, 0x3E, &D_80809CE0_chdiggerboss, dialog_id);
func_80806EE4_chdiggerboss(actor, 1);
func_80807DC0_chdiggerboss(actor, 2);
func_808080C0_chdiggerboss(func_80802228_chdiggerboss(actor), 2);
return;
case 0x172C:
func_80808470_chdiggerboss(actor, 0x40);
return;
case 0x172D:
func_80802BE0_chdiggerboss(actor, 1.0f);
func_80808560_chdiggerboss(actor);
return;
case 0x1735:
func_80809150_chdiggerboss(actor);
return;
case 0x14D8:
func_800FDC28(0);
_gcgoto_entrypoint_1(0x191, 1);
return;

case 0xCEB:
    if (unk_2 > 0) {
        _gcfrontend_entrypoint_11();
        return;
    }

_gcfrontend_entrypoint_10();
}
}

void func_808039C0_chdiggerboss(s32 actor, volatile unsigned int dialog_id, s32 unk_2)
{
    s32 hag;
    s32 i;
    s32 j;

    hag = func_80802228_chdiggerboss(actor);
    switch (dialog_id) {
        case 0x1720:
            func_80805448_chdiggerboss(hag, 0, 1);
            func_80805448_chdiggerboss(hag, 2, 1);
            return;
        case 0x1721:
            i = 0;
            do {
                func_80805448_chdiggerboss(hag, i, 1);
                i += 1;
            } while (i != 4);
            return;
        case 0x1723:
            func_8080041C_chdiggerboss(hag, 0xE);
            return;
        case 0x1724:
            func_8080041C_chdiggerboss(hag, 0x10);
            return;

case 0x1725:
    switch (unk_2) {
        case 1:
            func_8080041C_chdiggerboss(hag, 0x12);
            return;
        case 2:
            func_80805448_chdiggerboss(hag, 0, 1);
            func_80805448_chdiggerboss(hag, 3, 1);
    }

break;

case 0x1726:
    if (unk_2 == 1) {
        func_80804A50_chdiggerboss(hag, 2);
    }

return;

case 0x1734:
    switch (unk_2) {
        case 1:
            func_80804A50_chdiggerboss(hag, 0);
            return;
        case 2:
            j = 0;
            do {
                func_80805448_chdiggerboss(hag, j, 2);
                j += 1;
            } while (j != 4);
            return;
        case 3:
            func_808041E4_chdiggerboss(hag, 4);
    }

break;

case 0x172A:
    switch (unk_2) {
        case 1:
            func_8080041C_chdiggerboss(hag, 0x14);
            return;
        case 2:
            func_80807DC0_chdiggerboss(actor, 1);
    }

break;

case 0x172B:
    if (unk_2 == 1) {
        func_808080C0_chdiggerboss(func_80802228_chdiggerboss(actor), 1);
    }

}
}

// Sets the state and initializes per-state parameters.
void func_80803BE8_chdiggerboss(actor, state, param_2) Actor *actor;
s32 state;
s32 param_2;
{
    u8 *data;
    s32 i;

    data = func_80100094(actor, 0);
    *(s16 *) data = state;
    if (param_2 != -1) {
        func_80800180_chdiggerboss(actor, param_2);
    }
    switch (state) {
        case 6:
            func_80805448_chdiggerboss(func_80802228_chdiggerboss(actor), 0, 1);
            func_80805448_chdiggerboss(func_80802228_chdiggerboss(actor), 2, 1);
            *(f32 *) (data + 0x20) = 40.0f;
            *(f32 *) (data + 0x1C) = 10.0f;
            break;
        case 14:
            for (i = 0; i != 4; i++) {
                func_80805448_chdiggerboss(func_80802228_chdiggerboss(actor), i, 1);
            }
            *(f32 *) (data + 0x1C) = 10.0f;
            *(f32 *) (data + 0x20) = -60.0f;
            break;
        case 39:
            func_80805448_chdiggerboss(func_80802228_chdiggerboss(actor), 0, 1);
            func_80805448_chdiggerboss(func_80802228_chdiggerboss(actor), 3, 1);
            *(f32 *) (data + 0x30) = 5.0f;
            *(f32 *) (data + 0x34) = 5.0f;
            *(f32 *) (data + 0x3C) = 40.0f;
            *(f32 *) (data + 0x20) = 40.0f;
            *(f32 *) (data + 0x38) = 250.0f;
            break;
        case 49:
            for (i = 0; i != 4; i++) {
                func_80805448_chdiggerboss(func_80802228_chdiggerboss(actor), i, 1);
            }
            *(f32 *) (data + 0x30) = 5.0f;
            *(f32 *) (data + 0x34) = 5.0f;
            *(f32 *) (data + 0x3C) = 60.0f;
            *(f32 *) (data + 0x38) = 350.0f;
            *(f32 *) (data + 0x20) = -60.0f;
    }
}

int func_80803DC8_chdiggerboss(actor, state, param_2)
s32 actor;
s32 state;
s32 param_2;
{
    Actor *data;
    data = func_80100094(actor, 0);
    (*(u8 *) ((char *) (data) + 0x4)) = state;
    if (param_2 != -1) {
        func_8080041C_chdiggerboss(actor, param_2);
    }
}

void func_80803E10_chdiggerboss(actor) s32 actor;
{
    u8 *data;
    s8 sound;
    u8 *data_copy;
    u8 **data_ptr;
    u8 *base;
    base = func_80100094(actor, 0);
    data = base;
    *((s8 *) (((s8 *) base) + 0xB)) = 0;
    *((s8 *) (((s8 *) base) + 0xC)) = 0;
    *((s8 *) (((s8 *) base) + 0xD)) = 0;
    *((f32 *) (((s8 *) data) + 0x14)) = func_800DC178(0.85f, 2.5f);
    sound = func_800E8B74(0);
    // Matching: extra pointer and copy of the data local.
    data_ptr = &data;
    data_copy = *data_ptr;
    *((s8 *) (((s8 *) data_copy) + 0xA)) = sound;
    func_800E8D5C(sound & 0xFF, &D_80809F98_chdiggerboss, 3);
}

// Matching: the line breaks in this function are needed for the match.
void func_80803E84_chdiggerboss(Actor *actor)
{
    u8 *data;
    f32 pitch;
    s32 volume;

    data = func_80100094(actor, 0);
    switch (data[8]) {
        case 0:
            break;
        case 1:
            data[0xD] = _subaddieaudioloop_entrypoint_7(data[0xD], actor->position, 1,
                                                           &D_80809FB0_chdiggerboss,
                                                           *(u32 *) ((u8 *) actor + 0x70) & 1);
            if (func_800D9078((f32 *) (data + 0x10))) {
                func_808041E4_chdiggerboss(actor, 2);
            }
            break;
        case 2:
            pitch = func_800F10B4(*(f32 *) ((u8 *) actor + 0x24), 0.0f, 350.0f, 0.85f, 1.1f);
            volume =
                func_800F10B4(*(f32 *) ((u8 *) actor + 0x24), 0.0f, 350.0f, 25000.0f, 32000.0f);
            if (data[0xB] == 0) {
                func_800C4B64(pitch);
                func_800C4B70(volume);
            }
            data[0xB] = _subaddieaudioloop_entrypoint_7(data[0xB], (actor->position), 1,
                                                           &D_80809FC0_chdiggerboss,
                                                           *(u32 *) ((u8 *) actor + 0x70) & 1);
            if (data[0xB] != 0) {
                func_800C31DC(data[0xB], pitch);
                func_800C3058(data[0xB], volume);
            }
            if (func_80802314_chdiggerboss() < 2 && func_800D90A4((f32 *) (data + 0x14))) {
                _subaddieaudioquick_entrypoint_2(actor, (actor->position),
                                                 &D_80809F44_chdiggerboss);
                *(f32 *) (data + 0x14) = func_800DC178(0.85f, 2.5f);
                data[9] = 4;

}
func_80804680_chdiggerboss(actor);
if (func_8001210C(1)) {
    if (data[9]) {
        func_808043D8_chdiggerboss(actor, 1.25f, D_80809F3C_chdiggerboss);
        data[9]--;
    } else {

func_808043D8_chdiggerboss(actor, 1.0f, &D_80809F40_chdiggerboss);
}
}
break;
case 3:
    data[0xC] = _subaddieaudioloop_entrypoint_7(data[0xC], actor->position, 1,
                                                   &D_80809FD0_chdiggerboss,
                                                   *(u32 *) ((u8 *) actor + 0x70) & 1);
    break;
case 4:
    func_80804450_chdiggerboss(actor);
    }
    func_80804140_chdiggerboss(actor);
    }

    void func_808040D8_chdiggerboss(actor) s32 actor;
    {
        u8 *data;

        data = func_80100094(actor, 0);
        if (data[0xA] != 0) {
            func_800E8C08(data[0xA]);
            data[0xA] = 0;
        }
        data[0xB] = _subaddieaudioloop_entrypoint_3(data[0xB]);
        data[0xC] = _subaddieaudioloop_entrypoint_3(data[0xC]);
        data[0xD] = _subaddieaudioloop_entrypoint_3(data[0xD]);
    }

    void func_80804140_chdiggerboss(actor) Actor *actor;
    {
        u8 *data;
        s32 unk_0;
        f32 unk_1;
        data = func_80100094(actor, 0);
        unk_0 = func_800F10B4(*(f32 *) &actor->actorData[3], 0.0f, 350.0f, 15.0f, 25.0f);
        unk_1 = func_800F10B4(*(f32 *) &actor->actorData[3], 0.0f, 350.0f, 0.35f, 0.2f);
        func_800E8DB0(data[0xA], unk_0);
        func_800E8D28(data[0xA], unk_1);
    }

    void func_808041E4_chdiggerboss(actor, state) Actor *actor;
    s32 state;
    {
        u8 *data;

        data = func_80100094(actor, 0);
        data[8] = state;
        switch (state) {
            case 0:
                data[0xB] = _subaddieaudioloop_entrypoint_3(data[0xB]);
                data[0xC] = _subaddieaudioloop_entrypoint_3(data[0xC]);
                data[0xD] = _subaddieaudioloop_entrypoint_3(data[0xD]);
                break;
            case 1:
                *(f32 *) (data + 0x10) = 1.4f;
                break;
            case 2:
                data[0xC] = _subaddieaudioloop_entrypoint_3(data[0xC]);
                data[0xD] = _subaddieaudioloop_entrypoint_3(data[0xD]);
                break;
            case 3:
                data[0xB] = _subaddieaudioloop_entrypoint_3(data[0xB]);
                data[0xD] = _subaddieaudioloop_entrypoint_3(data[0xD]);
                break;
            case 4:
                data[0xB] = _subaddieaudioloop_entrypoint_3(data[0xB]);
                data[0xC] = _subaddieaudioloop_entrypoint_3(data[0xC]);
                data[0xD] = _subaddieaudioloop_entrypoint_3(data[0xD]);
                *(f32 *) (data + 0x10) = 0.0f;
        }
    }

    u8 func_808042D8_chdiggerboss(s32 actor)
    {
        return *(u8 *) ((char *) func_80100094(actor, 0) + 8);
    }

    void func_808042FC_chdiggerboss(actor, param_1, param_2) Actor *actor;
    void *param_1;
    void *param_2;
    {
        u8 *data;
        f32 unk_0;
        f32 unk_1;

        data = (u8 *) func_80100094(actor, 0);
        if (data[8]) {
            unk_0 = (f32) func_800E8C58(data[10]);
            unk_1 = 1.0f / _dbskeleton_entrypoint_1(func_800B27E0(param_2));
            func_800E0C20(param_1, 3, unk_1, 0.0f, unk_0, 0.0f);
            func_800E0C20(param_1, 10, unk_1, 0.0f, -unk_0, 0.0f);
            func_800E0C20(param_1, 24, unk_1, 0.0f, -unk_0, 0.0f);
        }
    }

    void func_808043D8_chdiggerboss(s32 *actor, f32 param_1, u8 *param_2)
    {
        f32 bone_pos[3];
        s32 unk_0;

        if (_subaddieskeleton_entrypoint_2(*actor, 7, bone_pos) != 0) {
            unk_0 = func_800B53A4(1);
            func_800BAB80(unk_0, param_2);
            func_800BABB8(unk_0, bone_pos, (u8 *) actor + 4, param_1, &D_80809FE0_chdiggerboss);
        }
    }

    void func_80804450_chdiggerboss(Actor *actor)
    {
        u8 *data;
        f32 prev_timer;
        s32 finished;

        data = (u8 *) func_80100094(actor, 0);
        prev_timer = *(f32 *) (data + 0x10);
        finished = func_800D91EC((f32 *) (data + 0x10), 4.0f);
        if (func_80804644_chdiggerboss(*(f32 *) (data + 0x10), prev_timer, 0.1f)) {
            _subaddieaudioquick_entrypoint_2(actor, (u8 *) actor + 4, D_80809F44_chdiggerboss);
            func_808043D8_chdiggerboss(actor, 1.0f, D_80809F3C_chdiggerboss);
        }
        if (func_80804644_chdiggerboss(*(f32 *) (data + 0x10), prev_timer, 0.4f)) {
            _subaddieaudioquick_entrypoint_2(actor, (u8 *) actor + 4, D_80809F44_chdiggerboss);
            func_808043D8_chdiggerboss(actor, 1.0f, D_80809F3C_chdiggerboss);
        }
        if (func_80804644_chdiggerboss(*(f32 *) (data + 0x10), prev_timer, 1.2f)) {
            _subaddieaudioquick_entrypoint_2(actor, (u8 *) actor + 4, D_80809F74_chdiggerboss);
            func_808043D8_chdiggerboss(actor, 1.25f, D_80809F3C_chdiggerboss);
        }
        if (func_80804644_chdiggerboss(*(f32 *) (data + 0x10), prev_timer, 2.0f)) {
            _subaddieaudioquick_entrypoint_2(actor, (u8 *) actor + 4, D_80809F44_chdiggerboss);
            func_808043D8_chdiggerboss(actor, 1.0f, D_80809F3C_chdiggerboss);
        }
        if (func_80804644_chdiggerboss(*(f32 *) (data + 0x10), prev_timer, 2.4f)) {
            _subaddieaudioquick_entrypoint_2(actor, (u8 *) actor + 4, D_80809F5C_chdiggerboss);
            func_808043D8_chdiggerboss(actor, 1.0f, D_80809F40_chdiggerboss);
        }
        if (func_80804644_chdiggerboss(*(f32 *) (data + 0x10), prev_timer, 3.4f)) {
            _subaddieaudioquick_entrypoint_2(actor, (u8 *) actor + 4, D_80809F88_chdiggerboss);
            func_808043D8_chdiggerboss(actor, 1.5f, D_80809F3C_chdiggerboss);
        }
        if (finished != 0) {
            func_808041E4_chdiggerboss(actor, 0);
        }
    }

    // True when the threshold was crossed between prev_time and cur_time.
    s32 func_80804644_chdiggerboss(f32 cur_time, f32 prev_time, f32 threshold)
    {
        if ((threshold < cur_time) && (prev_time <= threshold)) {
            return 1;
        }
        return 0;
    }

    void func_80804680_chdiggerboss(Actor *actor)
    {
        s32 player;
        f32 player_pos[3];
        f32 bone_pos[3];
        f32 ray_end[3];
        f32 push_dist;
        f32 push_angle;
        f32 push_vec[3];

        if (_subaddieskeleton_entrypoint_2(actor->unk0, 7, bone_pos)) {
            func_800EF1B8(bone_pos, actor->rotation[1], 150.0f);
            func_800EEB9C(ray_end, actor->rotation[1] - 180.0f, 1000.0f);
            player = func_8010D490(bone_pos, ray_end, 650.0f, 325.0f, -1);
            if (player != -1) {
                func_800F5A00(player, player_pos);
                push_dist =
                    func_800F10B4(func_800EFB8C(bone_pos, player_pos), 0.0f, 650.0f, 1400.0f, 100.0f);
                push_angle = func_800F1DF4(bone_pos, player_pos);
                func_800EEB9C(push_vec, push_angle, push_dist);
                func_800F48BC(player, push_vec);
            }
        }
    }

    void func_80804784_chdiggerboss(actor) s32 actor;
    {
        (*(s8 *) ((s8 *) (func_80100094(actor, 0)) + 0x1A)) = 0;
    }

    void func_808047A8_chdiggerboss(Actor *actor)
    {
        u8 *data;
        s32 active;
        f32 pitch;
        s32 volume;

        data = func_80100094(actor, 0);
        switch (*(s16 *) (data + 0x18)) {
            case 0:
                *(f32 *) (data + 0x20) =
                    func_800F15F8(*(f32 *) (data + 0x20), 0.0f, func_800D8FF8() * 0.4f);
                func_80804AC8_chdiggerboss(actor, 0);
                break;
            case 1:
                *(f32 *) (data + 0x20) =
                    func_800F15F8(*(f32 *) (data + 0x20), 0.2f, func_800D8FF8() * 0.4f);
                func_80804AC8_chdiggerboss(actor, 1);
                break;
            case 2:
                *(f32 *) (data + 0x20) =
                    func_800F15F8(*(f32 *) (data + 0x20), 1.0f, func_800D8FF8() * 0.4f);
                func_80804AC8_chdiggerboss(actor, 1);
        }
        active = *(f32 *) (data + 0x20) > 0.0f;
        func_808049DC_chdiggerboss(actor);
        pitch = func_800F10B4(*(f32 *) (data + 0x20), 0.0f, 1.0f, 0.7f, 1.1f);
        volume = (s32) func_800F10B4(*(f32 *) (data + 0x20), 0.0f, 1.0f, 22000.0f, 32000.0f);
        if (!data[0x1A]) {
            func_800C4B64(pitch);
            func_800C4B70(volume);
        }
        data[0x1A] = _subaddieaudioloop_entrypoint_7(data[0x1A], actor->position, active,
                                                        D_8080A028_chdiggerboss,
                                                        *(u32 *) ((u8 *) actor + 0x70) & 1);
        if (data[0x1A]) {
            func_800C31DC(data[0x1A], pitch);
            func_800C3058(data[0x1A], volume);
        }
    }

    void func_808049A8_chdiggerboss(actor) s32 actor;
    {
        u8 *data_copy;
        u8 *data;

        data = func_80100094(actor, 0);
        // Matching: redundant copy of the data local.
        data_copy = data;
        *(s8 *) ((char *) data_copy + 0x1A) =
            _subaddieaudioloop_entrypoint_3(*(u8 *) ((char *) data + 0x1A));
    }

    void func_808049DC_chdiggerboss(Actor *actor)
    {
        u8 *data;
        f32 spin_speed;

        data = func_80100094(actor, 0);
        spin_speed = func_800F10B4(*(f32 *) (data + 0x20), 0.0f, 1.0f, 0.0f, 300.0f);
        *(f32 *) (data + 0x1C) += spin_speed * func_800D8FF8();
        *(f32 *) (data + 0x1C) = func_800136E4(*(f32 *) (data + 0x1C));
    }

    s32 func_80804A50_chdiggerboss(actor, state)
    s32 actor;
    s32 state;
    {
        *(s16 *) ((char *) func_80100094(actor, 0) + 0x18) = state;
    }

    void func_80804A7C_chdiggerboss(actor, param_1, param_2) s32 actor;
    s32 param_1;
    s32 param_2;
    {
        u8 *data = func_80100094(actor, 0);
        func_800E0AFC(param_1, 0x2A, 1.0f, 0.0f, 0.0f, *(f32 *) (data + 0x1C));
    }

    void func_80804AC8_chdiggerboss(actor, active) Actor *actor;
    s32 active;
    {
        f32 origin[3];
        f32 launch[3];
        f32 player_pos[3];
        f32 target[4];
        s32 player;

        if (active) {
            for (player = 0; player < 8; player++) {
                if (!func_800F6438(player))
                    continue;
                if (!func_800F6478(player))
                    continue;
                if (!(func_800F581C(player) & 0x10000000))
                    continue;
                func_800EE7F8(target, actor->position);
                func_800EF1B8(target, actor->rotation[1], 1300.0f);
                target[1] += 275.0f;
                func_800F5A00(player, player_pos);
                func_800EE7F8(origin, actor->position);
                origin[1] += 275.0f;
                func_800F018C(launch, origin, target, player_pos);
                func_800F7A2C(player, 6, launch);
                func_808062B8_chdiggerboss(func_808026F8_chdiggerboss(actor));
            }
        }
    }

    // Creates the 4 lamp point lights, each with a z-buffer probe.
    void func_80804C28_chdiggerboss(actor) Actor *actor;
    {
        u8 *data;
        s32 i;
        s32 light;
        u8 probe;
        data = func_80100094(actor, 0);
        data[0x24] = 0;
        for (i = 0; i < 4; i++) {
            func_80805448_chdiggerboss(actor, i, 0);
            light = func_800C8A98();
            *(s32 *) (data + 0x30 + i * 0x1C) = light;
            func_800C8F64(light, 9);
            func_800C8D4C(light, D_8080A038_chdiggerboss);
            func_800EE7F8(data + 0x3C + i * 0x1C, actor->position);
            probe = func_800E8714(1);
            data[0x48 + i * 0x1C] = probe;
            func_800E8830(probe, actor->position);
            func_800E8870(probe, 20.0f);
        }
        func_808057D0_chdiggerboss(actor);
        func_808056B8_chdiggerboss(actor);
    }

    void func_80804D44_chdiggerboss(actor) Actor *actor;
    {
        u8 *data;
        s32 active;
        s16 lamp_state;
        s32 variant;
        s32 i;
        s16 *bone_ids = (s16 *) D_8080A058_chdiggerboss;

        data = func_80100094(actor, 0);
        active = 0;
        func_800D9078((f32 *) (data + 0x28));
        for (i = 0; i != 4; i++) {
            lamp_state = *(s16 *) (data + 0x34 + i * 0x1C);
            switch (lamp_state) {
                case 0:
                    break;
                case 1:
                    active = 1;
                    func_80805960_chdiggerboss(actor, i, func_800DC128(1, 5));
                    break;
                case 2:
                    if (func_800DC298(0.5f)) {
                        variant = 0;
                    } else {
                        variant = func_800DC128(1, 5);
                    }
                    active = 1;
                    func_80805960_chdiggerboss(actor, i, variant);
                    if (func_800D9078((f32 *) (data + 0x38 + i * 0x1C))) {
                        func_80805448_chdiggerboss(actor, i, 0);
                    }
            }
            if (data[0x48 + i * 0x1C]) {
                _subaddieskeleton_entrypoint_2(actor->unk0, bone_ids[i],
                                               data + 0x3C + i * 0x1C);
                func_800E8830(data[0x48 + i * 0x1C], data + 0x3C + i * 0x1C);
            }
        }
        func_808056F8_chdiggerboss(actor);
        func_808057D0_chdiggerboss(actor);
        data[0x24] = _subaddieaudioloop_entrypoint_7(data[0x24], actor->position, active,
                                                        D_8080A040_chdiggerboss,
                                                        *(u32 *) ((u8 *) actor + 0x70) & 1);
    }

    void func_80804EFC_chdiggerboss(actor, param_1) Actor *actor;
    s32 param_1;
    {
        u8 *data;
        s32 i;

        data = func_80100094(actor, 0);
        for (i = 0; i < 4; i++) {
            func_800DF744(D_8080A060_chdiggerboss[i], ((DiggerSlot *) (data + 0x34))[i].unk2);
        }
        func_800DF830(1);
        func_800DE498(param_1, actor->position, (u8 *) actor + 0x44,
                      *(f32 *) ((u8 *) actor + 0x38), 0, func_800D674C(0x955));
        for (i = 0; i < 4; i++) {
            if (((DiggerSlot *) (data + 0x34))[i].unk0 != 0) {
                func_80804FE4_chdiggerboss(actor, i, param_1);
            }
        }
    }

    void func_80804FE4_chdiggerboss(actor, lamp, param_2) u8 *actor;
    s32 lamp;
    s32 param_2;
    {
        u8 *base;
        f32 screen_pos[2];
        s32 alpha_add;
        u32 probe;
        s32 result;
        f32 fade_x;
        f32 fade_y;
        s32 unk_0[3];

        base = func_80100094(actor, 0);
        probe = ((Data *) base)->e[lamp].x14;
        alpha_add = 0;
        result = func_800E8918(probe & 0xFF, func_800A89F8(), 0, screen_pos);
        switch (result) {
            case -1:
                if (((Data *) base)->e[lamp].x16 != 0) {
                    fade_x = 1.0f;
                    fade_y = 1.0f;
                    if (screen_pos[0] < -30.0f || screen_pos[0] > 334.0f) {
                        fade_x = -1.0f;
                    } else if (screen_pos[0] <= 0.0f && screen_pos[0] >= -30.0f) {
                        fade_x = func_800F10B4(screen_pos[0], 0.0f, -30.0f, 1.0f, 0.0f);
                    } else if (screen_pos[0] >= 304.0f && screen_pos[0] <= 334.0f) {
                        fade_x = func_800F10B4(screen_pos[0], 304.0f, 334.0f, 1.0f, 0.0f);
                    }
                    if (screen_pos[1] < -30.0f || screen_pos[1] > 258.0f) {
                        fade_y = -1.0f;
                    } else if (screen_pos[1] <= 0.0f && screen_pos[1] >= -30.0f) {
                        fade_y = func_800F10B4(screen_pos[1], 0.0f, -30.0f, 1.0f, 0.0f);
                    } else if (screen_pos[1] >= 228.0f && screen_pos[1] <= 258.0f) {
                        fade_y = func_800F10B4(screen_pos[1], 228.0f, 258.0f, 1.0f, 0.0f);
                    }
                    // Matching: duplicated condition.
                    if (fade_y != -1.0f && fade_y != -1.0f) {
                        alpha_add = (s32) ((fade_x + fade_y) * 0.5f * 255.0f);
                        result = 1;
                        break;
                    }
                }
            case 0:
                alpha_add = (s32) ((f32) ((Data *) base)->e[lamp].x15 * 0.25f);
                if (alpha_add != 0) {
                    result = 1;
                }
                break;
            case 1:
                alpha_add = 0xFF;
        }
        ((Data *) base)->e[lamp].x15 = (s32) (((Data *) base)->e[lamp].x15 + alpha_add) >> 1;
        if (result == 1) {
            func_800E3A58(unk_0);
            func_800DF830(0);
            func_800DF744(1, ((Data *) base)->e[lamp].x2);
            func_800DF410(((Data *) base)->e[lamp].x15);
            func_800DE498(param_2, ((Data *) base)->e[lamp].pos, unk_0, *(f32 *) (actor + 0x38),
                          0, func_800D674C(0x954));
            ((Data *) base)->e[lamp].x16 = 1;
            return;
        }
        ((Data *) base)->e[lamp].x16 = 0;
    }

    void func_808053BC_chdiggerboss(actor) Actor *actor;
    {
        s32 light;
        s32 offset;
        u8 probe;
        u8 *data;
        u8 *entry;

        data = func_80100094(actor, 0);
        data[0x24] = _subaddieaudioloop_entrypoint_3(data[0x24]);
        for (offset = 0, entry = data; offset != 0x70; offset += 0x1C, entry += 0x1C) {
            light = *(s32 *) (entry + 0x30);
            if (light != 0) {
                func_800C8B84(light);
                *(s32 *) (entry + 0x30) = 0;
            }
            probe = entry[0x48];
            if (probe != 0) {
                func_800E87E0(probe);
                entry[0x48] = 0;
            }
        }
    }

    void func_80805448_chdiggerboss(actor, lamp, state) u8 **actor;
    s32 lamp;
    s32 state;
    {
        u8 *data;
        s32 offset;
        s32 lit_count;

        data = func_80100094(actor, 0);
        offset = lamp * 0x1C;
        lit_count = 0;
        *(s16 *) (data + offset + 0x34) = state;
        switch (state) {
            case 0:
                func_80805960_chdiggerboss(actor, lamp, 0);
                ((DB18 *) ((*actor) + 0x18))->f =
                    D_8080A068_chdiggerboss[lamp] | ((DB18 *) ((*actor) + 0x18))->f;
                data[offset + 0x4A] = 0;
                data[offset + 0x49] = 0;
                break;
            case 1:
                func_80805960_chdiggerboss(actor, lamp, func_800DC128(1, 5));
                ((DB18 *) ((*actor) + 0x18))->f =
                    (~D_8080A068_chdiggerboss[lamp]) & ((DB18 *) ((*actor) + 0x18))->f;
                break;
            case 2:
                func_80805960_chdiggerboss(actor, lamp, func_800DC128(1, 5));
                ((DB18 *) ((*actor) + 0x18))->f =
                    D_8080A068_chdiggerboss[lamp] | ((DB18 *) ((*actor) + 0x18))->f;
                *(f32 *) (data + offset + 0x38) = func_800DC178(0.8f, 1.2f);
        }
        for (offset = 0; offset != 0x70; offset += 0x1C) {
            if (*(s16 *) (data + offset + 0x34) == 1) {
                lit_count++;
            }
        }
        data[0x25] = (lit_count > 0);
        func_808056F8_chdiggerboss(actor);
        if ((lit_count > 0)) {
            ((DB28h *) (*actor + 0x2A))->g = ((DB28 *) (*actor + 0x28))->g | 4;
        } else {
            ((DB28h *) (*actor + 0x2A))->g = ((DB28 *) (*actor + 0x28))->g & 0xFFFB;
        }
    }

    void func_808056B8_chdiggerboss(actor) s32 actor;
    {
        u8 *data;
        data = func_80100094(actor, 0);
        func_8010A570(actor);
        *(f32 *) (data + 0x2C) = 1.0f;
    }

    void func_808056F8_chdiggerboss(actor) Actor *actor;
    {
        DiggerWaitState *data;
        s32 active;
        s32 player;
        data = func_80100094(actor, 0);
        active = 0;
        if (data->enabled) {
            player = func_80802248_chdiggerboss(func_808026F8_chdiggerboss(actor));
            if (func_800F6478(player) && !func_800F8004(player)) {
                if (func_800D90A4(&data->timer))
                    active = 1;
            } else {
                data->timer = 1.0f;
            }
        }
        func_8010A5B0(actor, active);
    }

    s16 func_80805798_chdiggerboss(s32 actor, s32 lamp)
    {
        s8 *base;
        base = (s8 *) ((u8 *) func_80100094(actor, 0) + (lamp * 0x1C));
        return *(s16 *) (base + 0x34);
    }

    void func_808057D0_chdiggerboss(actor) Actor *actor;
    {
        DiggerEffects *data;
        s32 i;
        s32 lit;
        s32 light;

        data = (DiggerEffects *) func_80100094(actor, 0);
        for (i = 0; i < 4; i++) {
            lit = data->local_0[i].local_1 == 1 ? 1 : 0;
            light = data->local_0[i].local_0;
            if (!light)
                continue;
            func_800C8FE0(light, lit);
            if (lit) {
                func_800C8CB8(light, data->local_0[i].local_2);
                func_800C8E84(light, D_8080A06C_chdiggerboss[func_8001210C(1)]);
            }
        }
    }

    void func_808058B0_chdiggerboss(actor, param_1) Actor *actor;
    u8 *param_1;
    {
        u8 *data;
        f32 hit_pos[3];

        data = func_80100094(actor, 0);
        func_800F79DC((u32) *(u16 *) (param_1 + 0x1A) >> 5, 6, actor->unk0);
        if (*(f32 *) (data + 0x28) == 0.0f) {
            if (!_subaddiecustomhits_entrypoint_4(actor, hit_pos, 0)) {
                func_800F5BF0((u32) *(u16 *) (param_1 + 0x1A) >> 5, hit_pos);
            }
            _chelectricfence_entrypoint_1(actor, hit_pos);
            *(f32 *) (data + 0x28) = 0.6f;
        }
    }

    void func_80805960_chdiggerboss(actor, lamp, variant) s32 actor;
    s32 lamp;
    s32 variant;
    {
        *(s16 *) ((u8 *) func_80100094(actor, 0) + lamp * 0x1C + 0x36) = variant;
    }

    void func_808059A4_chdiggerboss(actor) s32 actor;
    {
        u8 *data;

        data = func_80100094(actor, 0);
        (*(u8 *) ((u8 *) (data) + 0x24)) = 0;
        (*(u8 *) ((u8 *) (data) + 0x25)) = 0;
    }

    void func_808059CC_chdiggerboss(actor) s32 actor;
    {
        u8 *data_copy;
        u8 *data;

        data = func_80100094(actor, 0);
        // Matching: redundant copy of the data local.
        data_copy = data;
        data_copy[0x24] = _subaddieaudioloop_entrypoint_3(data[0x24]);
    }

    void func_80805A00_chdiggerboss(Actor *actor, s32 state)
    {
        DiggerBossTimerState *data;

        data = func_80100094(actor, 0);
        func_808027F4_chdiggerboss(actor);
        func_80803BE8_chdiggerboss(actor, state, 1);
        func_80802C0C_chdiggerboss(actor);
        data->enabled = 1;
        data->timer = 1.5f;
    }

    int func_80805A64_chdiggerboss(Actor *actor)
    {
        DiggerSpin1590 *data;
        Actor *other;
        s32 done;
        s32 i;

        data = func_80100094(actor, 0);
        other = (Actor *) func_80802228_chdiggerboss(actor);
        done = 0;
        func_80802C40_chdiggerboss(actor);
        if (func_800F6D24(func_800F54E4()))
            return 0;
        switch (data->local_3) {
            case 1:
                if (func_800D9078(&data->local_0))
                    data->local_3 = 2;
                break;
            case 2:
                done = func_800D9078(&data->local_1);
                other->rotation[1] += data->local_2 * func_800D8FF8();
                func_808064CC_chdiggerboss(actor, done == 0);
                func_80805B8C_chdiggerboss(actor, data->local_2);
                if (done) {
                    for (i = 0; i != 4; i++)
                        func_80805448_chdiggerboss(other, i, 0);
                    func_80802CB4_chdiggerboss(actor);
                }
        }
        return done;
    }

    int func_80805B8C_chdiggerboss(Actor *actor, f32 spin)
    {
        if (spin > 0.0f) {
            func_80805C1C_chdiggerboss(actor, 0, &D_8080A084_chdiggerboss, -90.0f);
            func_80805C1C_chdiggerboss(actor, 2, &D_8080A0A8_chdiggerboss, 90.0f);
        } else {
            func_80805C1C_chdiggerboss(actor, 0, &D_8080A090_chdiggerboss, -90.0f);
            func_80805C1C_chdiggerboss(actor, 2, &D_8080A09C_chdiggerboss, 90.0f);
        }
    }

    void func_80805C1C_chdiggerboss(Actor *actor, f32 *param_1, f32 *param_2, f32 angle_offset)
    {
        f32 rand_offset[3];
        f32 spawn_pos[3];
        s32 unk_0;
        Actor *other;
        if (func_800DC298(0.2f)) {
            other = (Actor *) func_80802228_chdiggerboss(actor);
            func_800EFA4C(rand_offset, func_800DC178(10.0f, 15.0f), other->rotation[1] + angle_offset,
                          0.0f);
            rand_offset[1] += func_800DC178(-25.0f, 25.0f);
            func_800EF934(spawn_pos, param_2, other->rotation[1]);
            func_800EF04C(spawn_pos, other->position);
            unk_0 = func_800B53A4(1);
            func_800BABB8(unk_0, spawn_pos, NULL, 1.0f, D_8080A0B4_chdiggerboss);
            func_800BA994(unk_0, (s16) rand_offset[0], (s16) rand_offset[1], 250, (s16) rand_offset[0],
                          (s16) rand_offset[1], 400);
            func_800BA22C(unk_0, 1);
        }
    }

    void func_80805D64_chdiggerboss(actor, state) Actor *actor;
    s32 state;
    {
        DiggerAttackState *data;
        DiggerAttackMotion *other;
        data = func_80100094(actor, 0);
        other = func_80802228_chdiggerboss(actor);
        data->local_0 = 0.0f;
        data->local_1 = 1.5f;
        other->local_0 = 0.0f;
        data->local_2 = 1;
        func_808027F4_chdiggerboss(actor);
        func_80802C0C_chdiggerboss(actor);
        func_80803BE8_chdiggerboss(actor, state, 1);
        func_80804A50_chdiggerboss(other, 2);
    }

    s32 func_80805DF4_chdiggerboss(actor)
    Actor *actor;
    {
        char *data;
        char *linked;
        s32 unk_11;
        s32 done;
        s32 turning;

        data = (char *) func_80100094(actor, 0);
        linked = (char *) func_80802228_chdiggerboss(actor);
        done = 0;
        turning = 0;

        func_80802C40_chdiggerboss(actor);

        if (func_800F6D24(func_800F54E4())) {
            return 0;
        }

        unk_11 = func_800D90A4(data + 0x14) && func_808042D8_chdiggerboss(linked) == 2;

        switch (*(s16 *) (data + 0x28)) {
            case 1:
                if (func_800D9078(data + 0x18)) {
                    *(s16 *) (data + 0x28) = 2;
                }
                break;

            case 2: {
                s32 timer_done;

                timer_done = func_800D9078(data + 0x34);

                if (unk_11) {
                    *(f32 *) (linked + 0x24) =
                        func_800F15F8(*(f32 *) (linked + 0x24), *(f32 *) (data + 0x38),
                                      func_800D8FF8() * 300.0f);

                    func_808063C8_chdiggerboss(actor, 0, *(f32 *) (data + 0x3C));

                    func_8010B990(linked, 5);
                }

                if (timer_done) {
                    *(s16 *) (data + 0x28) = 3;
                }
                break;
            }

            case 3:
                *(f32 *) (linked + 0x24) =
                    func_800F15F8(*(f32 *) (linked + 0x24), 0.0f, func_800D8FF8() * 300.0f);

                func_808063C8_chdiggerboss(actor, 0, *(f32 *) (data + 0x3C));

                func_8010B990(linked, 5);

                if (*(f32 *) (linked + 0x24) == 0.0f) {
                    *(s16 *) (data + 0x28) = 4;
                    *(f32 *) (data + 0x2C) = 360.0f;
                }
                break;

            case 4: {
                f32 step;

                step = *(f32 *) (data + 0x20) * func_800D8FF8();

                *(f32 *) (data + 0x2C) -= mlAbsF(step);
                *(f32 *) (linked + 0x48) += step;

                func_80805B8C_chdiggerboss(actor, *(f32 *) (data + 0x20));

                if (*(f32 *) (data + 0x2C) < 0.0f) {
                    *(s16 *) (data + 0x28) = 5;
                    *(f32 *) (data + 0x34) = *(f32 *) (data + 0x30);
                } else {
                    turning = 1;
                }
                break;
            }

            case 5: {
                s32 timer_done;

                timer_done = func_800D9078(data + 0x34);

                if (unk_11) {
                    *(f32 *) (linked + 0x24) =
                        func_800F15F8(*(f32 *) (linked + 0x24), *(f32 *) (data + 0x38),
                                      func_800D8FF8() * 300.0f);

                    func_808063C8_chdiggerboss(actor, 0, *(f32 *) (data + 0x3C));

                    func_8010B990(linked, 5);
                }

                if (timer_done) {
                    *(s16 *) (data + 0x28) = 6;
                }
                break;
            }

            case 6:
                *(f32 *) (linked + 0x24) =
                    func_800F15F8(*(f32 *) (linked + 0x24), 0.0f, func_800D8FF8() * 300.0f);

                func_808063C8_chdiggerboss(actor, 0, *(f32 *) (data + 0x3C));

                func_8010B990(linked, 5);

                if (*(f32 *) (linked + 0x24) == 0.0f) {
                    *(s16 *) (data + 0x28) = 7;
                    *(f32 *) (data + 0x2C) = 360.0f;
                }
                break;

            case 7: {
                f32 step;

                step = *(f32 *) (data + 0x20) * func_800D8FF8();

                *(f32 *) (data + 0x2C) -= mlAbsF(step);
                *(f32 *) (linked + 0x48) += step;

                func_80805B8C_chdiggerboss(actor, *(f32 *) (data + 0x20));

                if (*(f32 *) (data + 0x2C) < 0.0f) {
                    *(s16 *) (data + 0x28) = 0;

                    func_80802CB4_chdiggerboss(actor);

                    *(f32 *) (linked + 0x24) = 0.0f;

                    func_80804A50_chdiggerboss(linked, 1);

                    done = 1;
                } else {
                    turning = 1;
                }
            }
        }

        func_808064CC_chdiggerboss(actor, turning);

        {
            f32 ref_pos[3];
            f32 dir_a[3];
            f32 dir_b[3];
            f32 max_dist;
            f32 angle;
            f32 saved_y;
            f32 dot;

            func_800EFD24(ref_pos);
            ref_pos[1] = *(f32 *) (linked + 8);

            func_800EEB9C(dir_a, *(f32 *) (linked + 0x48), 1.0f);

            angle = func_800F1DF4(ref_pos, linked + 4);

            func_800EEB9C(dir_b, angle, 1.0f);

            dot = func_800EEAA4(dir_a, dir_b);

            if (dot > 0.0f) {
                max_dist = 1800.0f - dot * 650.0f;
            } else {
                max_dist = 1800.0f - dot * 250.0f;
            }

            if (max_dist * max_dist < func_800EFC7C(ref_pos, linked + 4)) {
                saved_y = *(f32 *) (linked + 8);

                angle = func_800F1DF4(ref_pos, linked + 4);

                func_800EEB9C(linked + 4, angle, max_dist);

                *(f32 *) (linked + 8) = saved_y;
            }
        }

        return done;
    }

    void func_808062B8_chdiggerboss(void *actor)
    {
        void *data;
        void *linked;

        data = func_80100094(actor, 0);
        linked = func_80802228_chdiggerboss(actor);
        (*(f32 *) ((char *) data + 0x14)) = 2.0f;
        (*(f32 *) ((char *) linked + 0x24)) = 0.0f;
    }

    s32 func_80806300_chdiggerboss(Actor *actor)
    {
        DiggerBossTurn *data;
        f32 target_yaw;
        f32 delta_time;

        data = func_80100094(actor, 0);
        delta_time = func_800D8FF8();
        if (data->local_0 == 2)
            return -1;
        target_yaw = func_800136E4(func_8010CD50(actor, func_80802248_chdiggerboss(actor)) -
                                actor->rotation[1]);
        data->local_1 =
            func_800F1FF0(data->local_1, target_yaw, 0.1f, delta_time * 4.0f, delta_time * 100.0f);
        return func_800F20BC(data->local_1, target_yaw, 10.0f);
    }

    s32 func_808063C8_chdiggerboss(Actor *actor, s32 update_audio, f32 turn_speed)
    {
        f32 target_yaw;
        f32 old_yaw;
        f32 yaw_delta;
        f32 delta_time;
        Actor *linked;
        s32 reached;

        delta_time = func_800D8FF8();
        linked = (Actor *) func_80802228_chdiggerboss(actor);
        target_yaw = func_8010CD50(actor, func_80802248_chdiggerboss(actor));
        old_yaw = linked->rotation[1];
        linked->rotation[1] = func_800F1F38(old_yaw, target_yaw, delta_time * turn_speed);
        yaw_delta = func_800F1DCC(linked->rotation[1], old_yaw);
        if (mlAbsF(func_800F1DCC(old_yaw, target_yaw)) > 20.0f) {
            func_80805B8C_chdiggerboss(actor, yaw_delta);
        }
        reached = func_800F20BC(linked->rotation[1], target_yaw, 10.0f);
        if (update_audio) {
            func_808064CC_chdiggerboss(actor, !reached);
        }
        return reached;
    }

    void func_808064CC_chdiggerboss(actor, active) u8 *actor;
    s32 active;
    {
        u8 *data_alias;
        u8 *data;

        data = func_80100094(actor, 0);
        data_alias = data;
        (*(s8 *) ((s8 *) (data_alias) + (0x24))) = _subaddieaudioloop_entrypoint_7(
            (*(u8 *) ((s8 *) (data) + (0x24))), actor + 4, active, &D_8080A0EC_chdiggerboss,
            (*(s32 *) ((s8 *) (actor) + (0x70))) & 1);
    }

    void func_80806528_chdiggerboss(actor, bones, model) Actor *actor;
    void *bones;
    void *model;
    {
        f32 zero;
        f32 scale;
        u8 *linked_data;
        void *skeleton;
        f32 offset;
        f32 inv_len;
        scale = *(f32 *) ((u8 *) func_80100094(actor, 0) + 0x10);
        zero = 0.0f;
        func_800E0AFC(bones, 3, 1.0f, zero, scale, zero);
        func_800E0AFC(bones, 0x5B, 1.0f, zero, scale, zero);
        if (actor->unk3C) {
            linked_data = func_80100094((Actor *) func_80802228_chdiggerboss(actor), 0);
            if (linked_data[8]) {
                offset = func_800E8C58(linked_data[10]);
                skeleton = func_800B27E0(model);
                inv_len = 1.0f / _dbskeleton_entrypoint_1(skeleton);
                func_800E0C20(bones, 3, inv_len, zero, offset, zero);
                func_800E0C20(bones, 0x5B, inv_len, zero, offset, zero);
            }
        }
    }

    void func_80806648_chdiggerboss(actor) s32 actor;
    {
        (*(s8 *) ((s8 *) (func_80100094(actor, 0)) + (0x78))) = 0;
    }

    int func_8080666C_chdiggerboss(actor)
    Actor *actor;
    {
        s32 data = func_80100094(actor, 0);
        *(u8 *) (data + 120) = _subaddieaudioloop_entrypoint_3(*(u8 *) (data + 120));
    }

    s32 func_808066A0_chdiggerboss(actor)
    Actor *actor;
    {
        s32 linked;
        char *proj;
        s16 unk_4;
        s16 target;
        s32 player_id;
        char *data;

        data = (char *) func_80100094(actor, 0);
        proj = (char *) func_80806D84_chdiggerboss(actor);

        func_800D2498(0x10A, *(u8 *) (data + 2), 0);

        switch (*(u8 *) (data + 0x5C)) {
            case 2:
                func_80806B38_chdiggerboss(actor);
                linked = func_80802228_chdiggerboss(actor);
                func_808056B8_chdiggerboss(linked);
                break;
            case 3:
                linked = func_80802228_chdiggerboss(actor);
                func_808056B8_chdiggerboss(linked);
                if (func_800D9078(data + 0x60)) {
                    func_80109FE8(actor, 1);
                    *(u8 *) (data + 0x5C) = 4;
                }
                break;
            case 4:
                func_80108B04(actor, 0);
                break;
            case 5:
                if (proj != 0) {
                    if (_subaddieskeleton_entrypoint_0(actor, 0x1E, proj + 4)) {
                        func_800EF1B8(proj + 4,
                                      (*((f32 *) (data + 0x10))) +
                                          (*((f32 *) (((char *) actor) + 0x48))),
                                      80.0f);
                    }
                }
                if (func_80101E14(actor, 0.33f)) {
                    if (*(u8 *) (data + 0x41) != 0) {
                        unk_4 = *(s16 *) (data + 0x6A);
                    } else {
                        unk_4 = *(s16 *) (data + 0x6C);

}
target = func_80802248_chdiggerboss(actor);
func_8010108C(proj, 0xA, (target << 16) | (u16) unk_4);
*(s32 *) (data + 0x64) = 0;
}
if (func_80101DDC(actor)) {
    if (*(u8 *) (data + 0x5E) == 0) {
        if (--*(u8 *) (data + 0x5D) == 0) {
            *(u8 *) (data + 0x5C) = 8;
            *(f32 *) (data + 0x60) = 1.0f;
            break;
        }

func_80800180_chdiggerboss(actor, 8);
*(u8 *) (data + 0x5C) = 6;
*(u8 *) (data + 0x5E) = 3;
*(f32 *) (data + 0x60) = *(f32 *) (data + 0x74);
}
else
{
    func_80800180_chdiggerboss(actor, 8);
    *(u8 *) (data + 0x5C) = 6;
    *(f32 *) (data + 0x60) = *(f32 *) (data + 0x70);
}
}
break;
case 6:
    if (*(u8 *) (data + 0x69) == *(u8 *) (data + 2)) {
        *(u8 *) (data + 0x5C) = 8;
        *(f32 *) (data + 0x60) = 1.0f;
    } else if (func_800D9078(data + 0x60)) {
        *(u8 *) (data + 0x5C) = 4;
    }
    break;
case 7:
    if (!func_80101DDC(actor)) {
        break;
    }
    if (*(u8 *) (data + 0x69) == *(u8 *) (data + 2)) {
        *(u8 *) (data + 0x5C) = 8;
        *(f32 *) (data + 0x60) = 1.0f;
    } else if (*(u8 *) (data + 0x5E) == 0) {
        if (*(u8 *) (data + 0x5D) == 0) {
            *(u8 *) (data + 0x5C) = 8;
            *(f32 *) (data + 0x60) = 1.0f;
        } else {
            *(u8 *) (data + 0x5C) = 4;
        }
    } else {
        *(u8 *) (data + 0x5C) = 4;
    }
    break;
case 8:
    if (_subaddiefind_entrypoint_2(0x4F2, 0) != 0) {
        break;
    }
    if (!func_800D9078(data + 0x60)) {
        break;
    }
    func_80109FE8(actor, 0);
    if (*(u8 *) (data + 0x5F) != 0 && *(u8 *) (data + 0x69) != *(u8 *) (data + 2)) {
        *(u8 *) (data + 0x5C) = 0;
        return 1;
    }
    player_id = _plsu_entrypoint_1(0x11);
    if (player_id != -1) {
        *(u8 *) (data + 0x5C) = 9;
        func_800F7B9C(player_id, 0x8E);
        break;
    } else {
        func_80806C08_chdiggerboss(actor);
        return 0;
    }
case 10:
    linked = func_80802228_chdiggerboss(actor);
    func_808056B8_chdiggerboss(linked);
    func_80806C08_chdiggerboss(actor);
    break;
case 11:
    linked = func_80802228_chdiggerboss(actor);
    func_808056B8_chdiggerboss(linked);
    if (!func_800D9078(data + 0x60)) {
        break;
    }
    *(u8 *) (data + 0x5C) = 0;
    if (*(u8 *) (data + 0x69) == *(u8 *) (data + 2)) {
        func_80806F8C_chdiggerboss(actor);
        func_80806EE4_chdiggerboss(actor, 0);
        return 2;
    }
    return 1;
    }
    return 0;
    }

    void func_80806A78_chdiggerboss(actor, state, table) s32 actor;
    s32 state;
    u8 *table;
    {
        Actor *data;
        data = func_80100094(actor, 0);
        rare_memcpy((u8 *) data + 0x68, table, 0x10);
        *(u8 *) ((u8 *) data + 0x5E) = 3;
        *(f32 *) ((u8 *) data + 0x60) = 1.75f;
        *(u8 *) ((u8 *) data + 0x5D) = *table;
        func_80803BE8_chdiggerboss(actor, state, 8);
        func_808027F4_chdiggerboss(actor);
        if (func_800F5410(func_800F54E4()) == 0x11) {
            *(u8 *) ((u8 *) data + 0x5C) = 1;
            func_800F7B9C(func_800F54E4(), 0x8E);
        } else {
            func_80806B38_chdiggerboss(actor);
        }
    }

    void func_80806B38_chdiggerboss(actor) Actor *actor;
    {
        DiggerPlayerCommand *data;
        f32 player_pos[3];
        f32 dir[3];
        s32 player;

        data = func_80100094(actor, 0);
        if (data->local_2 || data->local_0) {
            data->local_1 = 3;
            data->local_3 = 0.15f;
        } else {
            player = func_80802248_chdiggerboss(actor);
            data->local_1 = 3;
            data->local_3 = 1.75f;
            func_800F5A00(player, player_pos);
            func_800EFA4C(dir, 0.0f, func_800F1DF4(player_pos, actor->position), 0.0f);
            func_800F8444(player, dir);
            func_800F7C58(player, 0x61, 1);
        }
    }

    void func_80806C08_chdiggerboss(actor) Actor *actor;
    {
        u8 *data;
        s32 player;

        data = func_80100094(actor, 0);
        player = func_80802248_chdiggerboss(actor);
        if (data[4] != 0) {
            data[0x5C] = 0xB;
            *(f32 *) (data + 0x60) = 0.15f;
            return;
        }
        func_800F7B9C(player, 0x63);
        func_800F7C58(player, 0x61, 2);
        func_80802878_chdiggerboss(actor, 5, 1);
        data[0x5C] = 0xB;
        *(f32 *) (data + 0x60) = 1.0f;
    }

    void func_80806CA4_chdiggerboss(s32 actor, s32 param_1)
    {
        void *data = func_80100094(actor, 0);
        switch (*(u8 *) ((char *) data + 0x5C)) {
            case 1:
                *(u8 *) ((char *) data + 0x5C) = 2;
                break;

            case 9:
                *(u8 *) ((char *) data + 0x5C) = 10;
        }
    }

    void func_80806CF8_chdiggerboss(Actor *actor, s32 skip)
    {
        u8 *data;
        Actor *proj;
        data = func_80100094(actor, 0);
        if (!skip) {
            proj = func_801084B0(0x4F2, &actor);
            _subaddieskeleton_entrypoint_0(actor, 0x1E, proj->position);
            *(Unk80132ED0 **) (data + 0x64) = proj->unk0;
            data[0x5C] = 5;
            if (data[0x5E] > 0)
                data[0x5E]--;
            func_80800180_chdiggerboss(actor, 7);
        }
    }

    s32 func_80806D84_chdiggerboss(s32 actor)
    {
        u8 *data;

        data = func_80100094(actor, 0);
        if (*(s32 *) ((s8 *) data + 0x64) != 0) {
            return func_80106790(*(s32 *) ((s8 *) data + 0x64));
        }
        return 0;
    }

    void func_80806DC4_chdiggerboss(Actor *actor, u8 *hit)
    {
        s32 damage;
        u8 *data;
        f32 pos[3];
        data = func_80100094(actor, 0);
        switch (*(u32 *) (hit + 0x24) >> 22) {
            case 0x26C:
                damage = 1;
                break;
            case 0x26D:
            case 0x26E:
                damage = 2;
                break;
            case 0x26F:
                damage = 3;
                break;
            default:
                return;
        }
        data[2] = func_800F0E28(data[2] - damage, data[0x69]);
        data[0x78] = func_80806F10_chdiggerboss(actor, data[0x78]);
        if (data[0x69] == data[2])
            func_80109FE8(actor, 0);
        func_80802298_chdiggerboss(actor, pos);
        func_8010963C(actor, pos, hit);
        switch (data[0x5C]) {
            case 4:
            case 7:
                break;
            case 5:
                if (*(s32 *) (data + 0x64))
                    break;
            default:
                func_80800180_chdiggerboss(actor, 9);
                data[0x5C] = 7;
        }
    }

    void func_80806EE4_chdiggerboss(s32 actor, s32 value)
    {
        s8 *data;
        data = func_80100094(actor, 0);
        data[0x5F] = (s8) value;
    }

    u8 func_80806F10_chdiggerboss(actor, sound_id)
    Actor *actor;
    u8 sound_id;
    {
        if ((*(u8 *) &sound_id) == 0) {
            (*(u8 *) &sound_id) = _subaddieaudioquick_entrypoint_1(actor, actor->position);
        }
        func_800C4B7C(D_8080A11C_chdiggerboss[func_800DC128(0, 2)]);
        func_800C4350((*(u8 *) &sound_id), actor->position, D_8080A104_chdiggerboss);
        return (*(u8 *) &sound_id);
    }

    void func_80806F8C_chdiggerboss(Actor *actor)
    {
        f32 pos[3];
        f32 zero;
        f32 spawn_yaw;
        f32 angle;
        u8 *linked;

        zero = 0.0f;
        linked = (u8 *) func_80802228_chdiggerboss(actor);
        func_80802298_chdiggerboss(actor, pos);
        if (!func_800F1E6C(pos, D_8080A134_chdiggerboss, &angle)) {
            angle = 0.0f;
        }
        if (func_800F2094(*(f32 *) (linked + 0x48) + 90.0f, angle) <
            func_800F2094(*(f32 *) (linked + 0x48) - 90.0f, angle)) {
            spawn_yaw = *(f32 *) (linked + 0x48) + 90.0f;
        } else {
            spawn_yaw = *(f32 *) (linked + 0x48) - 90.0f;
        }
        _chbounce_entrypoint_3(func_800DC178(-30.0f, 30.0f) + spawn_yaw);
        _chbaddiesetup_entrypoint_5(_chbaddiesetup_entrypoint_10, 0x21, ((s32 *) pos)[0],
                                    ((s32 *) pos)[1], ((s32 *) pos)[2], *(s32 *) &zero);
        _subaddieaudioquick_entrypoint_2(actor, actor->position, D_8080A120_chdiggerboss);
    }

    s32 func_808070B0_chdiggerboss(actor)
    Actor *actor;
    {
        u8 *data;
        void *linked;
        void *linked_2;

        data = func_80100094(actor, 0);
        func_80802C40_chdiggerboss(actor);
        switch (*(s16 *) (data + 0x7C)) {
            case 1:
                if (func_800D9078(data + 0x84)) {
                    *(s16 *) (data + 0x7C) = 2;
                }
                break;
            case 2:
                if (func_808063C8_chdiggerboss(actor, 1, 80.0f)) {
                    linked = func_80802228_chdiggerboss(actor);
                    if (func_8080761C_chdiggerboss(actor)) {
                        func_808008C0_chdiggerboss(linked, 3, 1);
                        func_808008C0_chdiggerboss(linked, 4, 1);
                        func_8080041C_chdiggerboss(linked, 0x11);
                    } else {
                        func_808008C0_chdiggerboss(linked, 3, 1);
                        func_8080041C_chdiggerboss(linked, 15);

}
*(s16 *) (data + 0x7C) = 3;
}
break;
case 3:
    linked_2 = func_80802228_chdiggerboss(actor);
    func_808063C8_chdiggerboss(actor, 1, 80.0f);
    if (func_80101E14(linked_2, 0.14f)) {
        func_80108B04(actor, 1);
    }
    if (func_8080761C_chdiggerboss(actor) && func_80101E14(linked_2, 0.28f)) {
        func_80108B04(actor, 2);
    }
    break;
case 4:
    if (func_800D9078(data + 0x84)) {
        *(s16 *) (data + 0x7C) = 2;
    }
    break;
case 5:
    if (!_subaddiefind_entrypoint_2(0x4F3, 0) && !_subaddiefind_entrypoint_2(0x4F4, 0)) {
        *(s16 *) (data + 0x7C) = 0;
        func_80802CB4_chdiggerboss(actor);
        return 1;
    }
    }
    return 0;
    }

    void func_80807280_chdiggerboss(actor, state, table) Actor *actor;
    s32 state;
    s16 *table;
    {
        DiggerBossPose61 *data;

        data = func_80100094(actor, 0);
        rare_memcpy(data->local_3, table, 0x10);
        func_808027F4_chdiggerboss(actor);
        func_80802C0C_chdiggerboss(actor);
        func_80803BE8_chdiggerboss(actor, state, 1);
        data->local_2 = 1.5f;
        data->local_0 = 1;
        data->local_1 = *table;
    }

    void func_80807304_chdiggerboss(actor, side) Actor *actor;
    s32 side;
    {
        DiggerProjectileState *data;
        Actor *linked;
        Actor *shell;
        s32 target;
        Vec3f spawn_pos;
        Vec3f dest;
        f32 base_yaw;
        f32 rand_min;
        f32 rand_max;
        f32 yaw_offset;

        data = func_80100094(actor, 0);
        linked = (Actor *) func_80802228_chdiggerboss(actor);
        target = func_80802248_chdiggerboss(actor);
        if (func_8080761C_chdiggerboss(actor)) {
            base_yaw = func_8010CD50(actor, target);
            rand_min = data->local_3;
            rand_max = data->local_4;
            yaw_offset = side == 2 ? -90.0f : 90.0f;
            func_8010D09C(target, dest.f, 0.0);
            func_800EF1B8(dest.f, func_800DC178(-80.0f, 80.0f) + (base_yaw + yaw_offset),
                          func_800DC178(rand_min, rand_max));
        } else {
            func_8010D09C(target, dest.f, 0.0);
        }
        dest.pos.y = 0.0f;
        if (func_800EEFD4(dest.f) > 3240000.0f) {
            func_800EF368(dest.f, 1800.0f);
        }
        dest.pos.y = actor->position[1];
        switch (side) {
            case 1:
                func_808008C0_chdiggerboss(linked, 3, 0);
                _subaddieskeleton_entrypoint_2(linked->unk0, 11, spawn_pos.f);
                shell = func_80108528(0x4F3, spawn_pos.f, 0, &actor);
                func_800EE7F8((f32 *) shell->actorData, dest.f);
                func_80102FDC(shell, 0.25f);
                shell->unk54 = 0.0f;
                ((f32 *) shell->actorData)[3] = func_800DC178(data->local_6, data->local_7);
                _subaddieaudioquick_entrypoint_2(actor, actor->position,
                                                 D_8080A140_chdiggerboss);
                if (data->local_1 > 0) {
                    data->local_1 = data->local_1 - 1;
                }
                break;
            case 2:
                func_808008C0_chdiggerboss(linked, 4, 0);
                _subaddieskeleton_entrypoint_2(linked->unk0, 10, spawn_pos.f);
                shell = func_80108528(0x4F3, spawn_pos.f, 0, &actor);
                func_800EE7F8((f32 *) shell->actorData, dest.f);
                func_80102FDC(shell, 0.25f);
                shell->unk54 = 45.0f;
                ((f32 *) shell->actorData)[3] = func_800DC178(data->local_6, data->local_7);
                _subaddieaudioquick_entrypoint_2(actor, actor->position,
                                                 D_8080A140_chdiggerboss);
        }
        if (!func_8080761C_chdiggerboss(actor) || side == 2) {
            if (data->local_1 == 0) {
                data->local_0 = 5;
            } else {
                data->local_0 = 4;
                data->local_2 = data->local_5;
            }
        }
    }

    s16 func_8080761C_chdiggerboss(s32 actor)
    {
        return *(s16 *) ((char *) func_80100094(actor, 0) + 0x80);
    }

    void func_80807640_chdiggerboss(actor) s32 actor;
    {
        s8 *data = func_80100094(actor, 0);
        data[0xA0] = 0;
    }

    void func_80807664_chdiggerboss(actor) s32 actor;
    {
        u8 *data_alias;
        u8 *data;

        data = func_80100094(actor, 0);
        data_alias = data;
        *(s8 *) ((char *) data_alias + 0xA0) =
            _subaddieaudioloop_entrypoint_3(*(u8 *) ((char *) data + 0xA0));
    }

    void func_80807698_chdiggerboss(actor, force) Actor *actor;
    s32 force;
    {
        s32 lit;
        u8 *data;
        struct DiggerAttackMotion *linked;
        s32 i;

        data = func_80100094(actor, 0);
        linked = func_80802228_chdiggerboss(actor);
        lit = force ? 1 : (data[0xA3] ? 1 : 0);
        for (i = 0; i != 4; i++) {
            if (data[0xA2] & (1 << i)) {
                func_80805448_chdiggerboss(linked, i, lit);
            }
        }
    }

    void func_80807754_chdiggerboss(Actor *actor, s32 state, f32 timer)
    {
        u8 *data;
        s32 linked;
        s32 i;

        data = func_80100094(actor, 0);
        linked = (s32) func_80802228_chdiggerboss(actor);
        *(f32 *) (data + 0x98) = timer;
        *(f32 *) (data + 0x9C) = 2.0f;
        data[0xA3] = 1;
        data[0xA2] = 0;
        i = 0;
        do {
            if (func_80805798_chdiggerboss(linked, i)) {
                data[0xA2] |= 1 << i;
            }
            i++;
        } while (i != 4);
        func_808027F4_chdiggerboss(actor);
        func_80803BE8_chdiggerboss(actor, state, 1);
        func_808041E4_chdiggerboss(func_80802228_chdiggerboss(actor), 3);
    }

    s32 func_8080783C_chdiggerboss(actor, state)
    Actor *actor;
    s32 state;
    {
        DiggerBossData *data;
        Actor *linked;
        f32 bone_pos[3];
        s32 i;
        Actor *linked_2;
        s32 hud_count;

        data = func_80100094(actor, 0);
        linked = func_80802228_chdiggerboss(actor);
        hud_count = func_80802314_chdiggerboss();
        func_800D2498(0x10B, hud_count, 0);
        if (func_800F64A4(func_800F54E4(), 0x10000)) {
            linked_2 = func_80802228_chdiggerboss(actor);
            if (_subaddieskeleton_entrypoint_2(linked_2->unk0, 7, bone_pos) &&
                func_8010CFBC(bone_pos, 0, 50)) {
                data->unkA0 = 1;
                actor->unk74_17 = data->unkA0;
                func_800FE850();
                _gcgoto_entrypoint_1(0x18A, 1);
            }
        }
        switch (data->unkA3) {
            case 0:
                if (func_800D9078(&data->unk9C)) {
                    for (i = 0; i < 4; i++) {
                        if (data->unkA2 & (1 << i)) {
                            func_80805448_chdiggerboss(linked, i, 1);
                        }

}
data->unkA3 = 1;
data->unk9C = 2.0f;
}
break;
case 1:
    if (func_800D9078(&data->unk9C)) {
        for (i = 0; i < 4; i++) {
            if (data->unkA2 & (1 << i)) {
                func_80805448_chdiggerboss(linked, i, 0);
            }

}
data->unk9C = 0.8f;
data->unkA3 = 2;
}
break;
case 2:
    for (i = 0; i < 4; i++) {
        if (data->unkA2 & (1 << i)) {
            func_80805448_chdiggerboss(linked, i, func_800DC298(0.5f) ? 0 : 1);

}
}
if (func_800D9078(&data->unk9C)) {
    for (i = 0; i < 4; i++) {
        if (data->unkA2 & (1 << i)) {
            func_80805448_chdiggerboss(linked, i, 0);
        }

}
data->unkA3 = 0;
data->unk9C = 2.0f;
}
}
if (func_800D90A4(&data->unk98) && data->unkA0 == 0) {
    if (!func_80802170_chdiggerboss(actor, 10)) {
        func_80803660_chdiggerboss(actor, 0x1728, 0x106);
    }
    func_808041E4_chdiggerboss(func_80802228_chdiggerboss(actor), 2);
    func_80805D64_chdiggerboss(actor, state);
    return 1;
}
return 0;
}

void func_80807B18_chdiggerboss(actor) s32 actor;
{
    u8 *data;

    data = func_80100094(actor, 0);
    (*(s8 *) ((s8 *) (data) + (0xA4))) = 0;
    (*(s32 *) ((s8 *) (data) + (0xC8))) = 0;
    (*(s8 *) ((s8 *) (data) + (0xA6))) = 0;
    (*(s8 *) ((s8 *) (data) + (0xA7))) = 4;
}

void func_80807B4C_chdiggerboss(s32 actor)
{
}
void func_80807B54_chdiggerboss(actor) Actor *actor;
{
    f32 arc;
    s32 done;
    Actor *shell;
    f32 t;
    s32 player;
    s32 iter;
    Actor *child;
    u8 *data;

    data = func_80100094(actor, 0);
    switch (data[0xA4]) {
        case 0:
            if (data[0xA5] && _subaddiefind_entrypoint_9(0x131) < data[0xA6]) {
                data[0xA4] = 1;
                func_80108B04(actor, 4);
            }
        case 1:
            break;
        case 2:
            done = func_800D9078((f32 *) (data + 0xC4));
            shell = func_80106790(*(u32 *) (data + 0xC8));
            t = func_800F10B4(*(f32 *) (data + 0xC4), 0.0f, 1.0f, 1.0f, 0.0f);
            func_800EFE50(shell->position, (f32 *) (data + 0xB4), (f32 *) (data + 0xA8),
                          t);
            arc = func_8001395C(t * 3.141592741f);
            shell->position[1] += arc * 500.0f;
            player = func_800F54E4();
            func_800F4F34(player, shell->position, shell->scale * 90.0f,
                          shell->scale * 100.0f);
            if (done) {
                func_800B4470(shell->position, 0, D_8080A150_chdiggerboss, 1, 0.8f, 0.0f, 100,
                              150, 0);
                func_800C4104(0x419, 1.0f, 28000, shell->position, 1200.0f, 8000.0f);
                shell->unk64_20 = 1;
                data[0xA4] = 3;
            }
            break;
        case 3:
            _sucoaster_entrypoint_4(func_80106790(*(u32 *) (data + 0xC8)));
            if (data[0xA5])
                data[0xA4] = 0;
            else
                data[0xA4] = 4;
            *(u32 *) (data + 0xC8) = 0;
            break;
        case 4:
            if (data[0xA7])
                data[0xA7]--;
            else {
                child = _subaddiefind_entrypoint_2(0x131, &iter);
                while (child) {
                    func_8010108C(child, 0x9A, 0);
                    child = _subaddiefind_entrypoint_3(0x131, &iter);
                }
                data[0xA4] = 0;
            }
    }
}

void func_80807DC0_chdiggerboss(s32 actor, s32 count)
{
    void *data = func_80100094(actor, 0);
    *(u8 *) ((u8 *) data + 0xA5) = 1;
    *(u8 *) ((u8 *) data + 0xA6) = count;
}

int func_80807DF4_chdiggerboss(s32 actor)
{
    u8 *data;
    data = (u8 *) func_80100094(actor, 0);
    *(u8 *) ((char *) (data) + 0xA5) = 0;

    switch (data[0xA4]) {
        case 1:
        case 2:
        case 3:
            break;

        default:
            data[0xA4] = 4;
    }
}

void func_80807E3C_chdiggerboss(actor, event) Actor *actor;
s32 event;
{
    u8 *data;
    f32 sign;
    f32 unk_0[2];
    Actor *spawned;
    s32 player;
    f32 scale;
    f32 angle;

    data = func_80100094(actor, 0);
    if (event == 4) {
        player = func_80802248_chdiggerboss(actor);
        func_800EFD24(unk_0);
        if (!func_800F1E6C(actor->position, unk_0, (f32 *) (data + 0xC0))) {
            angle = func_8010CD50(actor, player);
            if (func_800DC298(0.5f)) {
                sign = 1.0f;
            } else {
                sign = -1.0f;
            }
            *(f32 *) (data + 0xC0) = sign * 45.0f + angle;
        }
        func_800EE7F8((f32 *) (data + 0xB4), actor->position);
        *(f32 *) (data + 0xB8) += 500.0f;
        func_800EE7F8((f32 *) (data + 0xA8), actor->position);
        func_800EF1B8((f32 *) (data + 0xA8), *(f32 *) (data + 0xC0), 600.0f);
        spawned = func_80108528(0x131, (f32 *) (data + 0xB4), (s32) *(f32 *) (data + 0xC0),
                                &actor);
        ((u8 *) spawned)[0x75] &= ~2;
        spawned->rotation[1] = *(f32 *) (data + 0xC0);
        scale = func_800DC178(1.2f, 1.6f);
        func_80102FDC(spawned, scale);
        *(void **) (data + 0xC8) = spawned->unk0;
        *(f32 *) (data + 0xC4) = 1.0f;
        data[0xA4] = 2;
        _subaddieaudioquick_entrypoint_2(actor, actor->position, D_8080A154_chdiggerboss);
    }
}

void func_80807FD8_chdiggerboss(actor) s32 actor;
{
    u8 *data;

    data = func_80100094(actor, 0);
    *(s32 *) ((char *) data + 0xA8) = 0;
    *(s8 *) ((char *) data + 0xA6) = 0;
}

void func_80808000_chdiggerboss(actor) s32 actor;
{
    u8 *data_copy;
    u8 *data;

    data = func_80100094(actor, 0);
    data_copy = data;
    data_copy[0xA6] = _subaddieaudioloop_entrypoint_3(data[0xA6]);
}

void func_80808034_chdiggerboss(actor) Actor *actor;
{
    u8 *data;
    s32 active;
    data = func_80100094(actor, 0);
    active = 0;
    if (*(s16 *) (data + 0xA4) == 1) {
        active = 1;
        if (func_8001210C(1))
            func_808081AC_chdiggerboss(actor);
    }
    data[0xA6] =
        _subaddieaudioloop_entrypoint_7(data[0xA6], actor->position, active,
                                        D_8080A160_chdiggerboss, ((u32 *) actor)[0x1C] & 1);
}

void func_808080C0_chdiggerboss(Actor *actor, s32 mode)
{
    DiggerCameraState61 *state;
    s32 mode_copy;

    mode_copy = mode;
    state = func_80100094(actor, 0);
    state->local_0 = mode_copy;
    switch (mode_copy) {
        case 0:
            if (state->local_1 != NULL) {
                func_8010114C(state->local_1, 0x4F, 0);
                state->local_1 = NULL;
            }
            break;
        case 2:
            if (state->local_1 == NULL) {
                func_80108B04(actor, 3);
            }
        case 1:
            break;
    }
}

void func_8080815C_chdiggerboss(actor, event) s32 actor;
s32 event;
{
    u8 *data;
    u8 *data_copy;
    s32 *spawned;

    data = func_80100094(actor, 0);
    if (event == 3) {
        data_copy = data;
        spawned = func_801084B0(0x178, &actor);
        *(s32 *) ((char *) data_copy + 0xA8) = *spawned;
    }
}

void func_808081AC_chdiggerboss(actor) Actor *actor;
{
    f32 side_pos[3];
    f32 back_pos[3];

    func_800EE7F8(back_pos, actor->position);
    func_800EF1B8(back_pos, actor->rotation[1], -80.0f);
    back_pos[1] += 80.0f;
    func_800EE7F8(side_pos, back_pos);
    func_800EF1B8(side_pos, actor->rotation[1] + 90.0f, 200.0f);
    func_800BBCB8(side_pos, actor->position, 1.0f, 1, D_8080A16C_chdiggerboss);
}

void func_80808258_chdiggerboss(actor) Actor *actor; // Update: state machine for the item carried by the boss.
{
    u8 *data;
    Actor *carried;
    Actor *unk_0;
    Actor *carried_b;
    s16 unk_1;
    s16 player;

    data = func_80100094(actor, 0);
    func_800D2498(0x10A, data[2], 0);
    func_808087F0_chdiggerboss(actor);
    switch (data[0xCC]) {
        case 0:
            break;
        case 1:
            func_80108B04(actor, 5);
            break;
        case 2:
            carried = func_808086A8_chdiggerboss(actor);
            if (carried) {
                func_80102FDC(carried,
                              func_800F10B4(func_80101F24(actor), 0.0f, 1.0f, 0.1f, 0.8f));
            }
            if (func_80101DDC(actor)) {
                if (data[0xCD]) {
                    func_80808560_chdiggerboss(actor);
                    return;
                }
                func_80800180_chdiggerboss(actor, 0xB);
                data[0xCC] = 3;
            }
            break;
        case 3:
            if (data[0xCD])
                func_80808560_chdiggerboss(actor);
            break;
        case 4:
            if (func_800D9078((f32 *) (data + 0xD0))) {
                func_80800180_chdiggerboss(actor, 0xC);
                data[0xCC] = 5;
            }
            break;
        case 5:
            carried_b = func_808086A8_chdiggerboss(actor);
            if (func_80101E14(actor, 0.33f)) {
                player = func_80802248_chdiggerboss(actor);
                func_8010105C(800.0f);
                func_8010108C(carried_b, 0xA, (player << 16) | 0xDAC);
                *((s32 *) (data + 0xD4)) = 0;
            }
            if (func_80101DDC(actor)) {
                func_80800180_chdiggerboss(actor, 8);
                data[0xCC] = 1;
                *((f32 *) (data + 0xD0)) = 0.5f;
            }
    }
}

void func_8080843C_chdiggerboss(actor) s32 actor;
{
    Actor *data;
    u8 handle;

    data = func_80100094(actor, 0);
    handle = data->unk78;
    data->unk78 = _subaddieaudioloop_entrypoint_3(handle);
}

void func_80808470_chdiggerboss(Actor *actor, s32 event)
{
    u8 *data;
    s32 player;
    f32 player_pos[3];
    f32 dir[3];

    data = func_80100094(actor, 0);
    player = func_80802248_chdiggerboss(actor);
    data[3] = 1;
    data[0xD8] = 0;
    func_80803BE8_chdiggerboss(actor, event, 8);
    func_800F5A00(player, player_pos);
    func_800EFA4C(dir, 0.0f, func_800F1DF4(player_pos, actor->position), 0.0f);
    func_800F8444(player, dir);
    if (!func_808021E8_chdiggerboss(actor, 11)) {
        func_80802878_chdiggerboss(actor, 3, 1);
        func_80803660_chdiggerboss(actor, 0x172D, 0x10E);
        data[0xCC] = 1;
    } else {
        func_80109FE8(actor, 1);
        data[0xCC] = 1;
    }
}

DiggerPhase59 *func_80808560_chdiggerboss(Actor *actor)
{
    DiggerPhase59 *data;

    data = func_80100094(actor, 0);
    func_80102FDC(func_808086A8_chdiggerboss(actor), 0.800000012f);
    func_80800180_chdiggerboss(actor, 0xB);
    func_808027F4_chdiggerboss(actor);
    func_80109FE8(actor, 1);
    data->local_0 = 4;
    data->local_1 = 0.5f;
}

int func_808085E0_chdiggerboss(s32 actor, s32 event)
{
    Actor *data;
    Actor *carried;
    data = func_80100094(actor, 0);
    if (event == 5) {
        carried = func_801084B0(1270, &actor);
        *(s32 *) ((char *) (data) + 0xD4) = *(s32 *) ((char *) (carried) + 0x0);
        func_808087F0_chdiggerboss(actor);
        if (!func_80802170_chdiggerboss(actor, 11)) {
            func_80102FDC(carried, 0.100000001f);
            func_80800180_chdiggerboss(actor, 10);
            (*(u8 *) ((char *) (data) + 0xCC)) = 2;
        } else {
            func_80102FDC(carried, 0.800000012f);
            func_80800180_chdiggerboss(actor, 11);
            (*(u8 *) ((char *) (data) + 0xCC)) = 4;
            (*(f32 *) ((char *) (data) + 0xD0)) = 0.5f;
        }
    }
}

s32 func_808086A8_chdiggerboss(actor)
s32 actor;
{
    u8 *data;

    data = func_80100094(actor, 0);
    if ((*(s32 *) ((s8 *) (data) + (0xD4))) != 0) {
        return func_80106790((*(s32 *) ((s8 *) (data) + (0xD4))));
    }
    return 0;
}

void func_808086E8_chdiggerboss(u8 *boss, u8 *other)
{
    u32 type_id;
    u8 *temp_data;
    u8 *actor;
    u8 *data;

    actor = boss;
    temp_data = func_80100094(boss, 0);
    data = temp_data;
    (*(u8 *) ((s8 *) (data) + 0xD8)) = func_80806F10_chdiggerboss(actor, (*(u8 *) ((s8 *) (data) + 0xD8)));
    if (((*(s32 *) ((s8 *) (data) + 0xD4)) != 0) &&
        ((type_id = (u32) (*(u32 *) ((s8 *) (other) + 0x24)) >> 0x16, (type_id == 0x26C)) ||
         (type_id == 0x26D) || (type_id == 0x26E) || (type_id == 0x26F))) {
        func_80109FE8(actor, 0);
        func_80803BE8_chdiggerboss(actor, 0x41, 0xD);
        func_80802878_chdiggerboss(actor, 3, 1);
        func_80803660_chdiggerboss(actor, 0x1735, 0x14C);
        func_800F7B9C(func_80802248_chdiggerboss(actor), 0x63);
        func_8010114C((*(s32 *) ((s8 *) (data) + 0xD4)), 0x9B,
                      (s32) ((*(f32 *) ((s8 *) (actor) + 8)) + 200.0f));
        (*(s32 *) ((s8 *) (data) + 0xD4)) = 0;
        (*(s8 *) ((s8 *) (data) + 0xCC)) = 0;
        (*(s8 *) ((s8 *) (data) + 2)) = 0;
    }
}

void func_808087F0_chdiggerboss(actor) Actor *actor;
{
    DiggerBraceState *data;
    Actor *carried;
    f32 bone_a[3];
    f32 bone_b[3];
    f32 angle;

    data = func_80100094(actor, 0);
    carried = func_808086A8_chdiggerboss(actor);
    if (carried && _subaddieskeleton_entrypoint_0(actor, 0x10, bone_a)) {
        angle = actor->rotation[1] + data->local_0;
        _subaddieskeleton_entrypoint_0(actor, 0x1E, bone_b);
        func_800EFE50(carried->position, bone_a, bone_b, 0.5f);
        func_800EF1B8(carried->position, angle, 80.0f);
        carried->position[1] += 80.0f;
    }
}

void func_808088AC_chdiggerboss(s32 arg0)
{
    func_80808B40_chdiggerboss(arg0, 1);
}

int func_808088CC_chdiggerboss(actor) // Repositions the four deflector actors.
s32 actor;
{
    s32 i;
    Actor *data;
    s32 id;
    data = func_80100094(actor, 0);
    for (i = 0; i < 4; i++) {
        id = *(s32 *) ((char *) data + i * 0x4 + 0xB0);
        if (id != 0) {
            func_80808BE4_chdiggerboss(actor, func_80106790(id), i);
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

void func_808089BC_chdiggerboss(actor, event) Actor *actor; // Spawns four deflector actors (2 large, 2 small and invisible).
s32 event;
{
    u8 *data;
    s32 i;
    Actor *deflector;
    data = (u8 *) func_80100094(actor, 0);
    if (event == 6) {
        for (i = 0; i != 2; i++) {
            deflector = (Actor *) func_80108528(0x50A, actor->position, 10, &actor);
            func_80103110(deflector, 1);
            func_80102FDC(deflector, 1.5f);
            deflector->unk74_17 = 0;
            deflector->unk74_7 = 0x43;
            func_80808BE4_chdiggerboss(actor, deflector, i);
            ((void **) (data + 0xB0))[i] = deflector->unk0;
        }
        for (; i < 4; i++) {
            deflector = (Actor *) func_80108528(0x50A, actor->position, 10, &actor);
            func_80103110(deflector, 1);
            func_80102FDC(deflector, 0.8f);
            _subaddiefade_entrypoint_12(deflector, 0xFF, 0, 0);
            deflector->unk74_17 = 0;
            deflector->unk74_7 = 0x3E;
            func_80808BE4_chdiggerboss(actor, deflector, i);
            ((void **) (data + 0xB0))[i] = deflector->unk0;
        }
    }
}

void func_80808B40_chdiggerboss(Actor *actor, s32 enable)
{
    DiggerBossMarkers *data;
    s32 i;
    data = func_80100094(actor, 0);
    if (data->enabled != enable) {
        data->enabled = enable;
        if (enable) {
            if (data->markers[0] == NULL)
                func_80108B04(actor, 6);
        } else {
            for (i = 0; i < 4; i++) {
                if (data->markers[i] != NULL) {
                    func_800FFA88(data->markers[i]);
                    data->markers[i] = NULL;
                }

}
}
}
}

void func_80808BE4_chdiggerboss(boss, deflector, index) Actor *boss; // Places a deflector at its offset relative to the boss.
Actor *deflector;
s32 index;
{
    func_800EEC30(deflector->position, D_8080A1BC_chdiggerboss[index],
                  boss->rotation[1] + D_8080A1AC_chdiggerboss[index],
                  D_8080A1CC_chdiggerboss[index]);
    func_800EF04C(deflector->position, boss->position);
    func_80103014(deflector);
}

void func_80808C64_chdiggerboss(actor) Actor *actor;
{
    DiggerResetPose *data;
    s32 i;

    data = func_80100094(actor, 0);
    for (i = 0; i < 2; i++) {
        data->local_0[i] = 0.0f;
    }
    func_800EE7F8(data->local_1, actor->position);
    data->local_2 = actor->rotation[1];
}

void func_80808CD0_chdiggerboss(actor) u8 *actor;
{
    u8 *data;

    data = func_80100094(actor, 0);
    func_80808D54_chdiggerboss(actor, 0, -1.0f, &D_8080A1E8_chdiggerboss);
    func_80808D54_chdiggerboss(actor, 1, 1.0f, &D_8080A1DC_chdiggerboss);
    func_80808F44_chdiggerboss(actor);
    func_800EE7F8(data + 0xD4, actor + 4);
    (*(f32 *) ((s8 *) (data) + (0xE0))) = (f32) (*(f32 *) ((s8 *) (actor) + (0x48)));
}

void func_80808D54_chdiggerboss(Actor *actor, s32 index, f32 flip, f32 *offset)
{
    u8 *data;
    f32 dt;
    f32 target_a[3];
    f32 target_b[3];
    f32 delta;
    f32 direction;
    f32 unk_0;
    f32 unk_1;
    s32 angle;

    data = func_80100094(actor, 0);
    dt = func_800D8FF8();
    func_800EF934(target_a, offset, actor->rotation[1]);
    func_800EF04C(target_a, actor->position);
    func_800EF934(target_b, offset, *(f32 *) (data + 0xE0));
    func_800EF04C(target_b, data + 0xD4);
    delta = func_800EEAD4(target_a, target_b);
    if (func_800EECE0(actor->position, data + 0xD4)) {
        direction = (func_800F1DCC(*(f32 *) (data + 0xE0), actor->rotation[1]) <= 0.0f ? 1.0f
                                                                                          : -1.0f) *
                  flip;
    } else {
        direction = 1.0f;
    }
    *(f32 *) (data + 0xC8 + index * 4) += (((delta * 12.0f) * direction) * 64.0f) * dt;
    angle = (s32) *(f32 *) (data + 0xC8 + index * 4);
    if (angle >= 8192) {
        *(f32 *) (data + 0xC8 + index * 4) -= 8192.0f;
    } else if (angle < 0) {
        *(f32 *) (data + 0xC8 + index * 4) += 8192.0f;
    }
    *(s16 *) (data + 0xD0 + index * 2) = (s32) *(f32 *) (data + 0xC8 + index * 4);
    *(f32 *) (data + 0xC0 + index * 4) +=
        ((delta * 0.01333333366f) * direction) * 57.29578018f;
}

void func_80808F44_chdiggerboss(actor) Actor *actor;
{
    s32 glid;

    glid = func_801065A4(actor);
    if (glid) {
        _glid_entrypoint_0(glid, 1, _chdiggerboss_entrypoint_3, actor->unk0);
        _glid_entrypoint_0(glid, 2, _chdiggerboss_entrypoint_3, actor->unk0);
    }
}

void chdiggerboss_entrypoint_3(s32 mode, VertexShiftRecord *src, VertexShiftRecord *dst, // Vertex callback: shifts a texture coordinate by the animated offset.
                               s32 count, Unk80132ED0 *owner)
{
    u8 *data;
    s32 shift;
    VertexShiftRecord *end;

    data = func_80100094(func_80106790(owner), 0);
    switch (mode) {
        case 1:
            shift = *(s16 *) (data + 0xD0);
            end = src + count;
            for (; src < end; src++, dst++) {
                dst->unkA = src->unkA + shift;
            }
            break;
        case 2:
            shift = *(s16 *) (data + 0xD0 + 2);
            end = src + count;
            for (; src < end; src++, dst++) {
                dst->unkA = src->unkA + shift;
            }
    }
}

void func_80809078_chdiggerboss(actor, target, param_2) Actor *actor;
void *target;
s32 param_2;
{
    DiggerBlendState *data;
    s32 i;
    data = func_80100094(actor, 0);
    for (i = 0; i < 3; i++) {
        func_800E0AFC(target, D_8080A1F4_chdiggerboss[i * 2 + 1], 1.0f, data->local_0, 0.0f,
                      0.0f);
    }
    for (i = 0; i < 3; i++) {
        func_800E0AFC(target, D_8080A1FC_chdiggerboss[i * 2 + 1], 1.0f, data->local_1, 0.0f,
                      0.0f);
    }
}

void func_80809150_chdiggerboss(s32 actor)
{
    s32 partner;
    u8 *data;

    partner = func_80802228_chdiggerboss(actor);
    data = func_80100094(actor, 0);
    func_80808B40_chdiggerboss(partner, 0);
    func_80803BE8_chdiggerboss(actor, 0x43, 1);
    func_800DA544(0x43);
    _gcfrontend_entrypoint_9(0x83);
    func_800FDC28(0x16);
    (*(s32 *) ((s8 *) (data) + (0xDC))) = -1;
    (*(s32 *) ((s8 *) (data) + (0xE4))) = 0;
    (*(s32 *) ((s8 *) (data) + (0xE8))) = 0;
    (*(s32 *) ((s8 *) (data) + (0xEC))) = 0;
    (*(s32 *) ((s8 *) (data) + (0xF0))) = 0;
    (*(s32 *) ((s8 *) (data) + (0xF4))) = 0;
    func_80809234_chdiggerboss(actor);
}

s32 func_808091E4_chdiggerboss(Actor *actor)
{
    if ((func_800D9078((u8 *) func_80100094(actor, 0) + 0xE0) != 0) &&
        (func_80809234_chdiggerboss(actor) == 0)) {
        return 0;
    }
    return 1;
}

int func_80809234_chdiggerboss(actor)
Actor *actor;
{
    DiggerStageState *state;

    state = (DiggerStageState *) func_80100094(actor, 0);
    state->local_0++;
    if (state->local_0 >= 5U) {
        func_800FC74C(*(s16 *) (D_8080A1FE_chdiggerboss + state->local_0 * 8));
        state->local_2 = 0;
        return 0;
    }
    state->local_1 = *(f32 *) (D_8080A208_chdiggerboss + state->local_0 * 8);
    _chexploder_entrypoint_5(actor, 0x91C, actor->position, actor->rotation[1], 1.0f, 7);
    if (state->local_0)
        func_800FC74C(*(s16 *) (D_8080A1FE_chdiggerboss + state->local_0 * 8));
    func_800FC6B0(*(s16 *) (D_8080A206_chdiggerboss + state->local_0 * 8));
    return 1;
}

void func_80809310_chdiggerboss(Actor *actor)
{
    Actor *target;
    u8 *data;
    Actor *partner;

    target = func_80106790(func_80101080(actor));
    data = func_80100094(actor, 0);
    func_80802938_chdiggerboss(actor, target->unk0,
                               D_8080A204_chdiggerboss[*(s32 *) (data + 0xDC)][0], 40);
    _chexploder_entrypoint_6(target, 1000.0f, 1200.0f);
    _chexploder_entrypoint_12(target, 250);
    _chexploder_entrypoint_11(target, D_8080A240_chdiggerboss);
    func_808093F8_chdiggerboss(actor);
    if (*(Unk80132ED0 **) (data + 0xE4) != NULL) {
        func_800FFA88(*(Unk80132ED0 **) (data + 0xE4));
    }
    *(Unk80132ED0 **) (data + 0xE4) = target->unk0;
    if (actor->unk3C != NULL) {
        partner = (Actor *) func_80802228_chdiggerboss(actor);
        partner->unk3C = NULL;
        actor->unk3C = NULL;
        func_800FFAB0(partner);
    }
}

void func_808093F8_chdiggerboss(actor) Actor *actor; // Spawns the defeat effects (particles, lights).
{
    f32 center[3];
    f32 angles[3];
    f32 spark_pos[3];
    u8 *data;
    s32 emitter;
    s32 i;

    data = func_80100094(actor, 0);
    func_800EE7F8(center, actor->position);
    center[1] += 300.0f;
    if (*(s32 *) (data + 0xE8)) {
        func_800B5450(*(s32 *) (data + 0xE8));
    }
    *(s32 *) (data + 0xE8) = func_800BBCB8(center, center, 3.0f, 1, D_8080A25C_chdiggerboss);
    if (*(s32 *) (data + 0xEC)) {
        func_800B5450(*(s32 *) (data + 0xEC));
    }
    emitter = func_800B53A4(8);
    *(s32 *) (data + 0xEC) = emitter;
    for (i = 0; i != 8; i++) {
        func_800EEB9C(spark_pos, i * 45.0f, func_800DC178(120.0f, 160.0f));
        func_800EF04C(spark_pos, center);
        spark_pos[1] += func_800DC178(10.0f, 50.0f);
        func_800BABB8(emitter, spark_pos, center, 1.0f, D_8080A2B8_chdiggerboss);
    }
    if (*(s32 *) (data + 0xF0)) {
        func_800B5450(*(s32 *) (data + 0xF0));
    }
    *(s32 *) (data + 0xF0) = func_800BBCB8(center, center, 1.0f, 1, D_8080A294_chdiggerboss);
    if (*(s32 *) (data + 0xF4)) {
        func_800B5450(*(s32 *) (data + 0xF4));
    }
    func_800E3A58(angles);
    emitter = func_800B53A4(1);
    *(s32 *) (data + 0xF4) = emitter;
    func_800BABB8(emitter, center, center, 1.0f, D_8080A294_chdiggerboss);
    func_800BA77C(emitter, (s16) (s32) (angles[0] + 90.0f), (s16) (s32) angles[1],
                  (s16) (s32) angles[2]);
    func_800BA22C(emitter, 1);
    _subaddieaudioquick_entrypoint_2(actor, actor->position, D_8080A250_chdiggerboss);
    func_8010D930(7, -1, actor->position, D_8080A22C_chdiggerboss);
}

// TU-NOTE: .data of this overlay is defined here in C. Its tables hold pointers to functions of
// this file; IDO's assembler schedules some of them differently unless the tables are in the same
// unit. Labels inside an object are linker aliases (D_80809EE2 = D_80809EE0 + 0x2, D_8080A1FA =
// D_8080A1F4 + 0x6, D_8080A1FE = D_8080A1FC + 0x2, D_8080A202 = D_8080A1FC + 0x6, D_8080A206 =
// D_8080A204 + 0x2, D_8080A208 = D_8080A204 + 0x4).
u8 D_80809C60_chdiggerboss[16] = {0x2,  0x5A, 0x3, 0xE8, 0x5,  0xDC, 0x0, 0x0,
                                  0x3F, 0xC0, 0x0, 0x0,  0x40, 0x40, 0x0, 0x0};
u8 D_80809C70_chdiggerboss[16] = {0x2,  0x50, 0x4, 0xB0, 0x7,  0x8,  0x0, 0x0,
                                  0x3F, 0xA0, 0x0, 0x0,  0x40, 0x20, 0x0, 0x0};
u8 D_80809C80_chdiggerboss[16] = {0x2,  0x46, 0x5, 0x78, 0x8,  0x34, 0x0, 0x0,
                                  0x3F, 0x80, 0x0, 0x0,  0x40, 0x0,  0x0, 0x0};
u8 D_80809C90_chdiggerboss[16] = {0x3,  0x3C, 0x6,  0x40, 0x9,  0x60, 0x0,  0x0,
                                  0x3F, 0x66, 0x66, 0x66, 0x3F, 0xE6, 0x66, 0x66};
u8 D_80809CA0_chdiggerboss[16] = {0x3,  0x32, 0x7,  0x8,  0xA,  0x8C, 0x0,  0x0,
                                  0x3F, 0x4C, 0xCC, 0xCD, 0x3F, 0xCC, 0xCC, 0xCD};
u8 D_80809CB0_chdiggerboss[16] = {0x3,  0x28, 0x7,  0xD0, 0xB,  0xB8, 0x0,  0x0,
                                  0x3F, 0x33, 0x33, 0x33, 0x3F, 0xB3, 0x33, 0x33};
u8 D_80809CC0_chdiggerboss[16] = {0x4,  0x1E, 0x7,  0xD0, 0xB,  0xB8, 0x0,  0x0,
                                  0x3F, 0x19, 0x99, 0x9A, 0x3F, 0x99, 0x99, 0x9A};
u8 D_80809CD0_chdiggerboss[16] = {0x4,  0xF, 0x7, 0xD0, 0xB,  0xB8, 0x0, 0x0,
                                  0x3F, 0x0, 0x0, 0x0,  0x3F, 0x80, 0x0, 0x0};
u8 D_80809CE0_chdiggerboss[16] = {0x4,  0x1, 0x7, 0xD0, 0xB,  0xB8, 0x0, 0x0,
                                  0x3F, 0x0, 0x0, 0x0,  0x3F, 0x80, 0x0, 0x0};
u8 D_80809CF0_chdiggerboss[16] = {0x0,  0x4, 0x0, 0x64, 0x1, 0x90, 0x0, 0x0,
                                  0x40, 0x0, 0x0, 0x0,  0x3, 0xE8, 0x5, 0xDC};
u8 D_80809D00_chdiggerboss[16] = {0x0,  0x6,  0x0, 0x64, 0x0, 0xC8, 0x0, 0x0,
                                  0x3F, 0xC0, 0x0, 0x0,  0x3, 0xE8, 0x5, 0xDC};
u8 D_80809D10_chdiggerboss[168] = {
    0x0,  0x0,  0x0,  0x0,  0x0, 0x0,  0x0, 0x0, 0x0,  0x0,  0x0,  0x0,  0x0, 0x0,  0x0, 0x0,
    0x3F, 0x23, 0xD7, 0xA,  0x4, 0x35, 0x0, 0x2, 0x3F, 0xB9, 0x99, 0x9A, 0x4, 0x3B, 0x0, 0x2,
    0x40, 0xBC, 0x28, 0xF6, 0x4, 0x36, 0x0, 0x2, 0x41, 0x9,  0x47, 0xAE, 0x4, 0x37, 0x0, 0x1,
    0x3F, 0x80, 0x0,  0x0,  0x4, 0x38, 0x0, 0x2, 0x3F, 0x9A, 0xE1, 0x48, 0x4, 0x39, 0x0, 0x2,
    0x40, 0xD5, 0x70, 0xA4, 0x4, 0x3F, 0x0, 0x1, 0x3F, 0x86, 0x66, 0x66, 0x4, 0x3A, 0x0, 0x2,
    0x40, 0x4A, 0xE1, 0x48, 0x4, 0x3C, 0x0, 0x2, 0x40, 0x85, 0x70, 0xA4, 0x4, 0x3D, 0x0, 0x1,
    0x3F, 0x90, 0xA3, 0xD7, 0x4, 0x3E, 0x0, 0x2, 0x40, 0x86, 0x66, 0x66, 0x4, 0x40, 0x0, 0x2,
    0x3F, 0xAA, 0x3D, 0x71, 0x4, 0x29, 0x0, 0x2, 0x3E, 0xF0, 0xA3, 0xD7, 0x4, 0x2A, 0x0, 0x42,
    0x3F, 0xAA, 0x3D, 0x71, 0x4, 0x2B, 0x0, 0x2, 0x3E, 0xF0, 0xA3, 0xD7, 0x4, 0x2C, 0x0, 0x42,
    0x3F, 0x90, 0xA3, 0xD7, 0x4, 0x2D, 0x0, 0x2, 0x3F, 0x90, 0xA3, 0xD7, 0x4, 0x2E, 0x0, 0x2,
    0x3F, 0x21, 0x47, 0xAE, 0x4, 0x2F, 0x0, 0x2};
u8 D_80809DB8_chdiggerboss[20] = {0x0, 0x13, 0x5, 0x56, 0x0,  0xD,  0x0, 0xF3, 0x1, 0xC,
                                  0x0, 0x1,  0x4, 0xB0, 0x1F, 0x40, 0x0, 0x0,  0x0, 0x0};
u8 D_80809DCC_chdiggerboss[24] = {0x0,  0x13, 0x4, 0xA0, 0x0, 0xD,  0x0,  0xF3, 0x1, 0xC, 0x0, 0x16,
                                  0x2E, 0xE0, 0x0, 0x1,  0x4, 0xB0, 0x1F, 0x40, 0x0, 0x0, 0x0, 0x0};
u8 D_80809DE4_chdiggerboss[24] = {0x0,  0x13, 0x4, 0x7A, 0x0, 0xD,  0x0,  0xF3, 0x1, 0xC, 0x0, 0x16,
                                  0x6D, 0x60, 0x0, 0x1,  0x4, 0xB0, 0x1F, 0x40, 0x0, 0x0, 0x0, 0x0};
u8 D_80809DFC_chdiggerboss[20] = {0x0, 0x13, 0x4,  0x8A, 0x0, 0x16, 0x6D, 0x60, 0x0, 0x1,
                                  0x4, 0xB0, 0x1F, 0x40, 0x0, 0x20, 0x0,  0x0,  0x0, 0x0};
u8 D_80809E10_chdiggerboss[20] = {0x0, 0x13, 0x4,  0x87, 0x0, 0x16, 0x6D, 0x60, 0x0, 0x1,
                                  0x4, 0xB0, 0x1F, 0x40, 0x0, 0x20, 0x0,  0x0,  0x0, 0x0};
u8 D_80809E24_chdiggerboss[20] = {0x0, 0x13, 0x5, 0xB9, 0x0, 0xC,  0x0, 0x0,  0x0, 0x99,
                                  0x0, 0xCC, 0x1, 0x19, 0x0, 0x18, 0x0, 0x20, 0x0, 0x0};
u8 D_80809E38_chdiggerboss[12] = {0x0, 0x13, 0x4, 0xC7, 0x0, 0x18, 0x0, 0x20, 0x0, 0x0, 0x0, 0x0};
int D_80809E44_chdiggerboss[18] = {0x1A80343,
                                   0x9010001,
                                   (u32) &D_80809D10_chdiggerboss,
                                   (u32) func_80800A4C_chdiggerboss,
                                   (u32) func_80102EC0,
                                   (u32) func_80800508_chdiggerboss,
                                   0x0,
                                   0x0,
                                   0x0,
                                   0x10082528,
                                   (u32) func_808019A8_chdiggerboss,
                                   (u32) func_80108ED0,
                                   0x10C0000,
                                   (u32) func_808008F8_chdiggerboss,
                                   (u32) func_80107C2C,
                                   -0x7FE00000,
                                   (u32) func_80801A04_chdiggerboss,
                                   0x0};
int D_80809E8C_chdiggerboss[18] = {0x3C0203,
                                   0x8FE0001,
                                   (u32) &D_80809D10_chdiggerboss,
                                   (u32) func_808023D8_chdiggerboss,
                                   (u32) func_80102EC0,
                                   (u32) func_80800650_chdiggerboss,
                                   0x0,
                                   0x0,
                                   0x0,
                                   0x20003C64,
                                   (u32) func_80802550_chdiggerboss,
                                   (u32) func_80108ED0,
                                   0xEC0000,
                                   (u32) func_8080233C_chdiggerboss,
                                   (u32) func_80107C2C,
                                   -0x7F7FFFFE,
                                   (u32) func_808025D4_chdiggerboss,
                                   0x0};
u8 D_80809ED4_chdiggerboss[12] = {0x0, 0x5, 0x0, 0x6, 0x0, 0x7, 0x0, 0x8, 0x0, 0x9, 0x0, 0xA};
u8 D_80809EE0_chdiggerboss[4] = {0x0, 0x5, 0x0, 0x0};
u16 D_80809EE4_chdiggerboss[16] = {0x688, 0x689, 0x68A, 0x68B, 0x68C, 0x68D, 0x68E, 0x68F,
                                   0x690, 0x0,   0x0,   0x691, 0x692, 0x693, 0x694, 0x0};
u8 D_80809F04_chdiggerboss[12] = {0x0, 0x13, 0x4, 0xA9, 0x0, 0x16, 0x7D, 0x0, 0x0, 0x2, 0x0, 0x0};
u8 D_80809F10_chdiggerboss[12] = {0xC3, 0xAF, 0x0, 0x0, 0xC2, 0xC8, 0x0, 0x0, 0xC3, 0xC8, 0x0, 0x0};
u8 D_80809F1C_chdiggerboss[12] = {0x43, 0xAF, 0x0, 0x0, 0x44, 0x48, 0x0, 0x0, 0x43, 0xAF, 0x0, 0x0};
u16 D_80809F28_chdiggerboss[3][2] = {0x1C30, 0x1C44, 0x1C44, 0x1C58, 0x1C58, 0x1C6C};
u8 D_80809F34_chdiggerboss[8] = {0x0, 0x9D, 0x0, 0x9F, 0xFF, 0xFF, 0x0, 0x0};
u8 D_80809F3C_chdiggerboss[4] = {0x3C, 0x32, 0x40, 0xFE};
u8 D_80809F40_chdiggerboss[4] = {0xE0, 0xFF, 0xE0, 0x80};
u8 D_80809F44_chdiggerboss[24] = {0x0, 0x13, 0x4,  0xB5, 0x0,  0xD,  0x0, 0xD9,
                                  0x1, 0x26, 0x0,  0x16, 0x6D, 0x60, 0x0, 0x1,
                                  0x4, 0xB0, 0x1F, 0x40, 0x0,  0x0,  0x0, 0x0};
u8 D_80809F5C_chdiggerboss[24] = {0x0, 0x13, 0x4,  0x91, 0x0,  0xD,  0x1, 0x33,
                                  0x1, 0x4C, 0x0,  0x16, 0x6D, 0x60, 0x0, 0x1,
                                  0x4, 0xB0, 0x1F, 0x40, 0x0,  0x0,  0x0, 0x0};
u8 D_80809F74_chdiggerboss[20] = {0x0, 0x13, 0x6, 0x7, 0x0, 0xD,  0x0,  0xF3, 0x1, 0xC,
                                  0x0, 0x18, 0x0, 0x1, 0x4, 0xB0, 0x1F, 0x40, 0x0, 0x0};
u8 D_80809F88_chdiggerboss[16] = {0x0, 0x13, 0x4, 0x13, 0x0,  0x16, 0x6D, 0x60,
                                  0x0, 0x1,  0x4, 0xB0, 0x1F, 0x40, 0x0,  0x0};
u8 D_80809F98_chdiggerboss[24] = {0x0,  0x0,  0x0, 0x0, 0x0,  0x0,  0x0, 0x0, 0x3F, 0x0, 0x0, 0x0,
                                  0x3F, 0x80, 0x0, 0x0, 0x3F, 0x80, 0x0, 0x0, 0x0,  0x0, 0x0, 0x0};
s32 D_80809FB0_chdiggerboss[4] = {0x1305F0, 0x180001, 0x4B01F40, 0x0};
s32 D_80809FC0_chdiggerboss[4] = {0x130527, 0x1D001E, 0x104B0, 0x1F400000};
s32 D_80809FD0_chdiggerboss[4] = {0x1305F0, 0x104B0, 0x1F400018, 0x0};
s32 D_80809FE0_chdiggerboss[18] = {0x1D09DC,  0x320000,  0x162200, 0x220080,  0x800200, 0x2800027,
                                   -0x770078, 0x780078,  0x2D01F4, 0x258001B, 0x28003C, 0x150000,
                                   0x99002B,  0x1000133, 0xE000F,  0x1E011A,  0x3000F3, 0x0};
u8 D_8080A028_chdiggerboss[16] = {0x0, 0x13, 0x5, 0x16, 0x0,  0x1D, 0x0, 0x1E,
                                  0x0, 0x1,  0x4, 0xB0, 0x1F, 0x40, 0x0, 0x0};
u8 D_8080A038_chdiggerboss[8] = {0x43, 0x16, 0x0, 0x0, 0x43, 0x96, 0x0, 0x0};
u8 D_8080A040_chdiggerboss[24] = {0x0, 0x13, 0x4,  0xDF, 0x0, 0xE, 0x0, 0xCC, 0x1,  0x0,  0x0, 0x80,
                                  0x0, 0x16, 0x19, 0x64, 0x0, 0x1, 0x4, 0xB0, 0x1F, 0x40, 0x0, 0x0};
u8 D_8080A058_chdiggerboss[8] = {0x0, 0x4, 0x0, 0x5, 0x0, 0x6, 0x0, 0xD};
s16 D_8080A060_chdiggerboss[4] = {0x4, 0x3, 0x1, 0x2};
u8 D_8080A068_chdiggerboss[4] = {0x8, 0x4, 0x1, 0x2};
u32 D_8080A06C_chdiggerboss[2][3] = {0xFF, 0xFF, 0xFF, 0x20, 0xC0, 0xFF};
int D_8080A084_chdiggerboss[3] = {-0x3C6A0000, 0x0, 0x432F0000};
int D_8080A090_chdiggerboss[3] = {-0x3C6A0000, 0x0, -0x3C448000};
int D_8080A09C_chdiggerboss[3] = {0x43960000, 0x0, 0x432F0000};
int D_8080A0A8_chdiggerboss[3] = {0x43960000, 0x0, -0x3C448000};
s32 D_8080A0B4_chdiggerboss[14] = {0x1D09E2, 0x160200, 0x60000,   0x40099,   0x70003,
                                   0x150000, 0xCC002B, 0x1800200, 0x22004C,  0x590026,
                                   0x33000E, 0x5000A,  0x1BF9C0,  -0x4B00000};
s32 D_8080A0EC_chdiggerboss[6] = {0x13068A, 0xE00F3, 0x10C0019, 0x166D60, 0x104B0, 0x1F400000};
s16 D_8080A104_chdiggerboss[12] = {0x306, 0x21,  0xD,    0xF3, 0x10C, 0x18,
                                   0x1,   0x4B0, 0x1F40, 0x11, 0x0,   0x0};
s16 D_8080A11C_chdiggerboss[2] = {0x48C, 0x48B};
u8 D_8080A120_chdiggerboss[20] = {0x0, 0x13, 0x4,  0x8A, 0x0, 0x16, 0x6D, 0x60, 0x0, 0x1,
                                  0x4, 0xB0, 0x1F, 0x40, 0x0, 0x20, 0x0,  0x0,  0x0, 0x0};
u8 D_8080A134_chdiggerboss[12] = {0x42, 0xC8, 0x0,  0x0,  0x45, 0xEA,
                                  0x60, 0x0,  0x42, 0xC8, 0x0,  0x0};
u8 D_8080A140_chdiggerboss[16] = {0x0, 0x13, 0x6, 0x7, 0x0, 0x18, 0x0, 0xD,
                                  0x0, 0xF3, 0x1, 0xC, 0x0, 0x0,  0x0, 0x0};
u8 D_8080A150_chdiggerboss[4] = {0x6E, 0x64, 0x50, 0xE0};
u8 D_8080A154_chdiggerboss[12] = {0x0, 0x13, 0x4, 0xBE, 0x0, 0xD, 0x0, 0xF3, 0x1, 0xC, 0x0, 0x0};
u8 D_8080A160_chdiggerboss[12] = {0x0, 0x13, 0x4, 0xDC, 0x0, 0x18, 0x0, 0x2, 0x0, 0x20, 0x0, 0x0};
u8 D_8080A16C_chdiggerboss[64] = {
    0x0,  0x1D, 0x9, 0xDC, 0x0, 0x32, 0x0, 0x0,  0x0,  0x16, 0x2,  0x0,  0x0, 0x22, 0x0,  0x80,
    0x0,  0x80, 0x2, 0x0,  0x2, 0x80, 0x0, 0x20, 0xFF, 0x40, 0xE0, 0xC0, 0x0, 0x27, 0xFF, 0x88,
    0xFF, 0x88, 0x0, 0x78, 0x0, 0x78, 0x0, 0x2D, 0x0,  0xFA, 0x1,  0x5E, 0x0, 0x15, 0x0,  0x19,
    0x0,  0x99, 0x0, 0x2B, 0x1, 0x0,  0x1, 0x66, 0x0,  0xE,  0x0,  0xF,  0x0, 0x1E, 0x0,  0x0};
f32 D_8080A1AC_chdiggerboss[4] = {37.5f, -37.5f, 166.0f, -166.0f};
f32 D_8080A1BC_chdiggerboss[4] = {47.5f, 47.5f, 15.5f, 15.5f};
f32 D_8080A1CC_chdiggerboss[4] = {525.0f, 525.0f, 525.0f, 525.0f};
int D_8080A1DC_chdiggerboss[3] = {-0x3C6A0000, 0x0, -0x3D380000};
int D_8080A1E8_chdiggerboss[3] = {0x43960000, 0x0, -0x3D380000};
u8 D_8080A1F4_chdiggerboss[8] = {0x0, 0x44, 0x0, 0x45, 0x0, 0x46, 0x0, 0x0};
u8 D_8080A1FC_chdiggerboss[8] = {0x0, 0x47, 0x0, 0x48, 0x0, 0x49, 0x0, 0x0};
s16 D_8080A204_chdiggerboss[5][4] = {0x21,   0x9C,   0x3F40, 0x0,    0x23,    0x9D, 0x3F26,
                                     0x6666, 0x26,   0x9E,   0x3F0C, -0x3333, 0x28, 0x9F,
                                     0x3EE6, 0x6666, 0x1E,   0xA0,   0x4060,  0x0};
u8 D_8080A22C_chdiggerboss[20] = {0x0, 0x13, 0x4, 0xC8, 0x0, 0x16, 0x6D, 0x60, 0x0, 0x2,
                                  0x0, 0xD,  0x0, 0xCC, 0x0, 0xE6, 0x0,  0x0,  0x0, 0x0};
u8 D_8080A240_chdiggerboss[16] = {0x0, 0x1, 0x0, 0x12, 0x0,  0x18, 0x0, 0x1A,
                                  0x0, 0xA, 0x0, 0xC,  0xFF, 0xFF, 0x0, 0x0};
u8 D_8080A250_chdiggerboss[12] = {0x0, 0x13, 0x4, 0x13, 0x0, 0x18, 0x0, 0x2, 0x0, 0x0, 0x0, 0x0};
u8 D_8080A25C_chdiggerboss[56] = {0x0, 0x1D, 0x7, 0x8F, 0x0, 0x15, 0x0, 0x19, 0x0, 0x66, 0x0, 0x16,
                                  0x2, 0x0,  0x0, 0x32, 0x0, 0x2,  0x0, 0x1E, 0x0, 0x1E, 0x0, 0x1E,
                                  0x0, 0x18, 0x0, 0x0,  0x0, 0x0,  0xF, 0x0,  0xF, 0x0,  0x0, 0x22,
                                  0x1, 0x0,  0x1, 0x0,  0x4, 0x0,  0x4, 0x0,  0x0, 0x2B, 0x1, 0x33,
                                  0x1, 0x33, 0x0, 0x29, 0x0, 0x0,  0x0, 0x0};
u8 D_8080A294_chdiggerboss[36] = {0x0, 0x1D, 0x9, 0x53, 0x0, 0x15, 0x0, 0x0,  0x0, 0xB3, 0x0, 0x16,
                                  0x2, 0x0,  0x0, 0x22, 0x0, 0x80, 0x0, 0x80, 0x8, 0x0,  0x8, 0x0,
                                  0x0, 0x2B, 0x1, 0x66, 0x1, 0x66, 0x0, 0x29, 0x0, 0x0,  0x0, 0x0};
u8 D_8080A2B8_chdiggerboss[72] = {
    0x0,  0x1D, 0x9,  0xDD, 0x0,  0x16, 0x2,  0x0,  0x0,  0x2B, 0x1,  0x80, 0x2,  0x0, 0x0,
    0x22, 0x1,  0x80, 0x2,  0x0,  0x3,  0x80, 0x4,  0x0,  0x0,  0x15, 0x0,  0x0,  0x0, 0x99,
    0x0,  0x27, 0xFF, 0x9C, 0xFF, 0x9C, 0x0,  0x64, 0x0,  0x64, 0x0,  0x19, 0x0,  0x0, 0x0,
    0x7,  0x0,  0x2D, 0x0,  0xFA, 0x1,  0x5E, 0x0,  0x20, 0xC0, 0xC0, 0xC0, 0x80, 0x1, 0x1A,
    0x0,  0x29, 0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0};
