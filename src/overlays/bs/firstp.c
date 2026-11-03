#include "bs/firstp.h"
#include "overlays/ba/playerstate.h"
#include "core2/anctrl.h"
#include "overlays/ba/stick.h"

#define F(p, o) (*(f32 *) ((u8 *) (p) + (o)))
extern void anctrl_reset(AnimCtrl *);
extern void anctrl_setIndex(AnimCtrl *, AssetId);
extern void anctrl_setDuration(AnimCtrl *, f32);
extern void anctrl_setStart(AnimCtrl *, f32);
extern void anctrl_setPlaybackType(AnimCtrl *, s32);
extern void anctrl_start(AnimCtrl *);
extern void anctrl_setSmoothTransition(AnimCtrl *, s32);
extern void func_8008B188(AnimCtrl *, s32);
extern void anctrl_setSubrange(AnimCtrl *, f32, f32);
extern s32 _gcstatusDll_entrypoint_13(s32);
extern void _gcstatusDll_entrypoint_3(s32, s32);
extern u8 *func_800D674C(s32);
extern void func_800963C0(PlayerState *, f32 *);
extern f32 sqrtf(f32);
extern void func_800EE84C(f32 *, s32 *);
extern s32 func_800F36D4(s32 *, s32 *);
extern void baflag_clear(Actor *, s32);
extern void baflag_set(Actor *, s32);
extern void func_8009E5A4(Actor *, s32, s32);
void func_808015C0_bsfirstp(s32 param_0, u8 *param_1, u8 *param_2);
f32 func_80801640_bsfirstp(s32 param_0);
void func_80801668_bsfirstp(u8 *param_0, f32 param_1);
void func_808016A0_bsfirstp(PlayerState *param_0);
s32 func_80802444_bsfirstp(Actor *param_0);
int func_80802458_bsfirstp();
s16 * func_808024B0_bsfirstp();
int func_808024DC_bsfirstp();
s16 * func_80802508_bsfirstp(void);
int func_80802534_bsfirstp(void);
s32 func_80802560_bsfirstp();
s32 func_80802594_bsfirstp();
void func_808025C8_bsfirstp(s32 param_0, s32 *param_1, s32 *param_2);
void func_8080261C_bsfirstp(s32 param_0, s32 *param_1, s32 *param_2);
void func_80802670_bsfirstp(s32 param_0, s32 *param_1);
void func_808026AC_bsfirstp(s32 param_0, s32 *param_1, s32 *param_2);
void func_80802700_bsfirstp(s32 param_0, s32 *param_1, s32 *param_2);
void func_80802754_bsfirstp(s32 param_0, s32 *param_1, s32 *param_2);
int func_808027A8_bsfirstp(s32 param_0);
u32 bsfirstp_entrypoint_3(s32 param_0, s32 param_1, s32 param_2);
void bsfirstp_entrypoint_4(s32 param_0, s32 param_1);
void bsfirstp_entrypoint_5(Actor *param_0, s32 param_1, s32 param_2);
s32 func_80802A40_bsfirstp(PlayerState *param_0, s32 param_1);
int func_80802AA8_bsfirstp(s32 param_0, s16 param_1, OSIoMesgHdr *param_2, OSIoMesgHdr *param_3);
void bsfirstp_entrypoint_6(PlayerState *param_0, f32 *param_1, f32 *param_2, f32 *param_3);
void bsfirstp_entrypoint_7(s32 param_0, f32 *param_1, f32 *param_2);
void func_80802BD8_bsfirstp(s32 arg0);
void func_80802BE0_bsfirstp(s32 arg0);
void func_80802BE8_bsfirstp(u8 *param_0, f32 param_1);
s32 func_80802C30_bsfirstp(void *param_0);
void func_80802C6C_bsfirstp(s32 arg0);
int func_80802C90_bsfirstp(Actor *param_0);
void func_80802CD8_bsfirstp(Actor *param_0, s32 param_1);
int func_80802D14_bsfirstp(void *param_0);
s32 func_80802D50_bsfirstp(PlayerState *param_0, s32 *param_1);
void func_808047EC_bsfirstp(Actor *param_0);
int func_8080483C_bsfirstp(Actor *param_0, s32 param_1);
int bsfirstp_entrypoint_18(Actor *param_0, s32 param_1);
void func_80804A34_bsfirstp(s32 arg0);
void func_80804A3C_bsfirstp(u8 *param_0);
void func_80804A64_bsfirstp(PlayerState *param_0);
extern f32 func_800C517C(s32);
extern int func_800A4C68();
extern void baanim_playForDuration_onceSmooth(PlayerState *, s32, f32);
extern void func_8009E55C(PlayerState *, s32, f32);
extern void _batimer_set(PlayerState *, s32, f32);
extern AnimCtrl *func_8008D04C();
extern PlayerState *func_800A4CA8();
extern void _baeggcursor_entrypoint_7(PlayerState *, s32);
extern s32 func_800A3280();
extern u8 _badeathmatch_entrypoint_6(void *);
extern s32 func_80094510(void *);
extern void func_800A0D94();
extern void _bsfirstp_entrypoint_10();
extern AnimCtrl *baanim_getAnimCtrlPtr();
extern void bs_setState();
extern void *func_800F53D0();
extern void func_8009B7C0();
extern void func_8009337C();
extern void func_800936E8();
extern void func_800A34A0(void *, s32);
extern void _bainvisible_entrypoint_7(PlayerState *, s32, f32, f32, f32);
extern f32 func_800F122C(f32, f32, f32);
typedef struct _AnCtrl AnCtrl;
extern f32 baanim_getTimer(s32);
extern void baanim_playForDuration_loopStartingAt(s32, s32, s32, f32);
extern void func_800EEC70(u8 *, f32, f32, f32);
extern f32 func_800D9004(void);
typedef struct {
    u8 pad_0[0x18];
    f32 components[4];
    u8 pad_1[0x64];
    s32 type;
    f32 strength;
} FirstPersonBlend1459;
extern f32 D_8080A5B0_bsfirstp[][4];
extern void func_800E0AFC(void *, s32, f32, f32, f32, f32);
typedef struct {
    u8 local_0[0x2B];
    u8 local_1;
    u8 local_2[3];
    u8 local_3;
} Mass47Firstp;
typedef struct {
    u8 pad_0[0x98];
    f32 local_0;
    f32 local_1;
} FirstPersonVolume1536;
extern void func_800C5148(s32, f32);
extern f32 func_800F2108(f32);
extern f32 mlAbsF(f32);
extern void func_80111590(void *, f32, f32, f32, f32);
void func_8010FD38(s32, f32);
extern u8 D_8080A5D0_bsfirstp[];
extern void _baeggcursor_entrypoint_10(u8 *, f32, f32);
extern f32 func_800F0DC0(f32, f32);
typedef struct {
    u8 pad_0[0xB8];
    f32 position[2];
    u8 pad_1[8];
    f32 output[2];
} FirstPersonProjection;
extern f32 func_800A8AF0(s32);
extern f32 func_80013B7C(f32, f32);
extern f32 func_80013728(f32);
extern int D_8080ABF0_bsfirstp[];
extern int D_8080A890_bsfirstp[];
extern s16 D_8080AFFC_bsfirstp[][4];
extern int D_8080AFB4_bsfirstp[];
extern s16 D_8080AFCC_bsfirstp[][4];
extern s16 D_8080B02C_bsfirstp[];
extern s32 D_8080B038_bsfirstp[];
extern s32 D_8080B080_bsfirstp[];
extern s32 D_8080B1B8_bsfirstp[];
extern s32 D_8080B1E0_bsfirstp[];
extern s32 D_8080B208_bsfirstp[];
extern s32 D_8080B230_bsfirstp[];
extern s32 D_8080B258_bsfirstp[];
extern s32 D_8080B0C8_bsfirstp[];
extern s32 D_8080B0F0_bsfirstp[];
extern s32 D_8080B118_bsfirstp[];
extern s32 D_8080B140_bsfirstp[];
extern s32 D_8080B168_bsfirstp[];
extern s32 D_8080B190_bsfirstp[];
extern int D_8080AC24_bsfirstp[];
typedef struct Mass43EggAimRecord {
    u16 local_0[7];
} Mass43EggAimRecord;
extern Mass43EggAimRecord D_8080ACF8_bsfirstp[];
extern Mass43EggAimRecord D_8080AD4C_bsfirstp[];
extern Mass43EggAimRecord D_8080ADA0_bsfirstp[];
extern u8 D_8080AC94_bsfirstp[100];
void _badeathmatch_entrypoint_10();
typedef struct {
    s16 animation;
    s16 enabled;
    f32 duration;
} FirstPersonAnimation;
extern FirstPersonAnimation *D_8080B45C_bsfirstp[];
extern void func_8009DF18(PlayerState *, s16, f32, s16);
extern u8 D_8080ADF4_bsfirstp[];
extern u8 D_8080AE44_bsfirstp[];
extern void func_80094430(u8 *, f32);
extern void _badeathmatch_entrypoint_8(u8 *, f32);
extern void func_80094C0C(void);
extern void _badeathmatch_entrypoint_5(void *param_0, int param_1, int param_2);
extern s32 func_800F1574(f32 *, f32);
extern s32 D_8080B474_bsfirstp[];
extern s32 D_8080B484_bsfirstp[];
extern void func_800EFA4C(f32 *, f32, f32, f32);
extern void func_800EFB24(f32 *, f32 *, f32 *);
extern f32 func_800EEF94(f32 *);
extern void func_800EF368(f32 *, f32);
extern u8 _bsfirstp_entrypoint_12[];
extern s32 func_8009E6EC();
extern s32 D_8080B494_bsfirstp[];
extern s32 D_8080B4A4_bsfirstp[];
extern f32 D_8080B4AC_bsfirstp[];
extern f32 D_8080B4B8_bsfirstp[];
extern f32 D_8080B4C4_bsfirstp[];
extern f32 func_8009BFCC(PlayerState *);
extern void func_800EF334(f32 *, f32);
extern void func_800EF8BC(f32 *, f32 *, f32);
extern void func_800EF934(f32 *, f32 *, f32);
extern void _bsfirstp_entrypoint_13(void);
extern void func_8009E4E0(PlayerState *, s32, void *);
extern void func_8009E154(PlayerState *, s32, f32 *);
extern f32 func_8009E138(PlayerState *, s32);
extern PlayerState *func_800F53E4(s32);
extern f32 func_800EEB40(f32 *, f32 *);
extern s32 D_8080B4D0_bsfirstp[];
typedef struct {
    s16 local_0;
    s16 pad_0;
    f32 local_1;
} FirstPersonAnimationEvent;
extern void func_8009D89C(PlayerState *, f32);
extern void baphysics_set_target_horizontal_velocity(PlayerState *, f32);
extern s32 D_8080B4E0_bsfirstp[];
extern s32 D_8080B4F0_bsfirstp[];
typedef struct Mass46FirstPersonTrend {
    f32 local_0;
    f32 local_1;
    f32 local_2;
    s32 local_3;
    f32 local_4;
    f32 local_5;
    f32 local_6;
} Mass46FirstPersonTrend;
extern s32 baanim_isAt(PlayerState *, f32);
extern void func_8009DE38(PlayerState *, s32, f32);
extern void func_8009DB04(PlayerState *, s32, f32, s32);
extern s32 D_8080B500_bsfirstp[];
extern s32 D_8080B510_bsfirstp[];
extern s32 D_8080B520_bsfirstp[];
extern void baanim_playForDuration_onceSmoothStartingAt(void *param_0, int param_1, float param_2,
                                                        int param_3);
extern s32 D_8080B530_bsfirstp[];
extern s32 D_8080B540_bsfirstp[];
extern s32 D_8080B550_bsfirstp[];
extern void func_8009BDAC(PlayerState *, f32);
extern f32 baphysics_get_target_horizontal_velocity(PlayerState *);
extern f32 func_8009BB18(PlayerState *);
extern f32 yaw_get();
extern f32 func_800EEFFC(f32 *);
extern f32 func_800F0E00(f32, f32);
typedef struct {
    u8 pad0[0x2C];
    f32 unk2C;
} FirstPersonScaleView;
extern f32 func_8009BB5C(PlayerState *);
extern f32 func_800138D0(f32);
typedef struct {
    f32 unk0;
    f32 unk4;
    f32 unk8;
    s32 unkC;
} FpStick;
extern void baphysics_set_target_yaw(PlayerState *, f32);
typedef struct {
    u8 pad_0[0xC];
    s32 local_0;
    u8 pad_1[0x1D8];
    f32 local_1;
    f32 local_2;
    u8 pad_2[0x1C];
    f32 local_3;
} FirstPersonPitchBounds;
typedef struct {
    u8 pad_0[0x10];
    s32 local_0;
    u8 pad_1[0x170];
    f32 local_1;
    u8 pad_2[0x60];
    f32 local_2;
    f32 local_3;
    u8 pad_3[0x18];
    f32 local_4;
    f32 local_5;
} FirstPersonAim1517;
typedef struct {
    u8 pad[0x8];
    f32 v;
} FS_8;
typedef struct {
    u8 pad_0[0x218];
    u8 local_0;
} FirstPersonMode;
extern void func_800A16BC();
typedef struct {
    u8 pad_0[8];
    s32 state;
    u8 pad_1[0x58];
    s32 handle;
} FirstPersonExitState;
extern s32 D_8080B560_bsfirstp[];
extern f32 func_80099A34(PlayerState *);
extern s32 D_8080B570_bsfirstp[];
extern s32 D_8080B580_bsfirstp[];
extern s32 D_8080B590_bsfirstp[];
extern s32 D_8080B5A0_bsfirstp[];
extern void func_80093230(PlayerState *, f32);
typedef struct {
    s32 local_0;
    u8 pad_0[4];
    s32 local_1;
    u8 pad_1[0x58];
    s32 local_2;
    s32 local_3;
} FirstPersonInit1493;
extern void func_800947EC(PlayerState *, s32, s32);
typedef struct {
    u8 pad_0[0x6C];
    s16 local_0[3];
    u8 local_1;
} FirstPersonCamera1527;
extern s32 D_8080B5B0_bsfirstp[];
extern s32 D_8080B5C0_bsfirstp[];
typedef struct FirstPersonScriptStep1612 {
    s16 local_0;
    s16 local_1;
    f32 local_2;
} FirstPersonScriptStep1612;
extern f32 D_8080A650_bsfirstp[][5];
extern void baphysics_set_horizontal_velocity(PlayerState *, f32, f32);
extern void baphysics_set_vertical_velocity(PlayerState *, f32);
extern void baphysics_set_gravity(PlayerState *, f32);
typedef struct {
    u8 pad_0[0x104];
    s32 local_0;
    s32 local_1;
    f32 local_2;
} FirstPersonTimer;
typedef struct {
    f32 local_0[5];
} FirstPersonTimerPreset;
extern FirstPersonTimerPreset D_8080A660_bsfirstp[];
typedef struct {
    u8 pad_0[8];
    f32 local_1;
} FirstPersonCameraOffset;
extern void func_800E0050(u8 *, f32, s32, f32 *);
extern s32 D_8080B5D0_bsfirstp[];
extern f32 func_800F0D50(f32, f32, f32);
extern void func_800A2CE8(PlayerState *, f32, s32);
typedef struct FirstPersonAimLimits {
    u8 pad_0[0x168];
    f32 local_0;
    f32 local_1;
    s32 local_2;
    u8 pad_1[0xBC];
    f32 local_3;
    u8 pad_2[4];
    f32 local_4;
    u8 pad_3[4];
    f32 local_5;
} FirstPersonAimLimits;
extern int func_800F1B78(f32 *, f32 *, f32, f32);
typedef struct {
    u8 pad0[8];
    f32 unk8;
    s32 unkC;
    u8 pad10[4];
    s32 unk14;
    u8 pad18[4];
    f32 unk1C;
    u8 pad20[0x24];
    f32 unk44;
    f32 unk48;
} FpSub;
typedef struct {
    u8 pad_0[0xC];
    s32 local_0;
    s32 local_1;
    s32 local_2;
    u8 pad_1[0x30];
    f32 local_3;
    f32 local_4;
} FirstPersonAcceleration;
extern f32 func_800F1CF0(f32 *, f32 *);
extern f32 func_800136E4(f32);
extern f32 func_80013970(f32);
typedef struct {
    u8 pad_0[0x30];
    f32 fraction;
    f32 upper;
    f32 lower;
    f32 right;
    f32 left;
} FirstPersonSplit;
extern void *func_8009370C(PlayerState *);
extern void func_800E0AF0(void *, f32);
extern void *func_80092AD8(PlayerState *);
extern f32 func_800F1214(f32, f32, f32);
extern void func_8010D930(s32, s32, s32, void *);
extern s32 _baeggcursor_entrypoint_9(void *);
extern s32 _baeggcursor_entrypoint_2(void *);
extern u8 D_8080A630_bsfirstp[];
extern u8 D_8080A640_bsfirstp[];
typedef struct {
    u8 unused[0x14];
    f32 first;
    f32 second;
    f32 third;
} FirstPersonValues;
extern void func_800EF1B8(f32 *, f32, f32);
extern f32 func_800F10B4(f32, f32, f32, f32, f32);
extern void _bamotor_entrypoint_0(PlayerState *, f32, f32);
extern f32 func_800F212C(f32, f32);
extern f32 func_80013AA0(f32);
extern f32 func_80013798(f32);
extern f32 func_800138BC(f32);
extern f32 func_800137C4(f32);
extern f32 func_80013A5C(f32);
extern f32 func_800137D4(f32);
extern f32 func_8001395C(f32);
extern f32 func_80013788(f32);
extern f32 func_80013788_noarg();
extern f32 func_800137C4_noarg();
typedef struct {
    f32 local_0;
    f32 local_1;
    f32 local_2;
    f32 local_3;
} FirstPersonMovementStep;
typedef struct {
    u8 pad_0[0x1CC];
    FirstPersonMovementStep local_0;
} FirstPersonMovementData;
extern void func_800EFCD8(f32 *, f32, f32);
typedef struct {
    f32 unk0;
    f32 unk4;
    f32 unk8[3];
} FpSpring;
extern void func_800EF04C(f32 *, f32 *);
extern void func_800EF3DC(f32 *, f32 *);
extern f32 func_800FF060(f32, f32 *, f32, f32, f32, f32);
extern f32 func_800137AC(f32);
extern void func_800EE7F8(f32 *, f32 *);
extern void func_800EFA20(f32 *, f32 *, f32);
extern f32 func_80013B70(f32, f32, f32);
typedef struct {
    u8 pad_0[0x1F0];
    f32 local_0;
    u8 pad_1[0x1C];
    f32 local_1;
    f32 local_2;
} FirstPersonIntegrator1517;
extern void func_8009C128(s32, f32 *);
extern f32 func_800EEAA4(f32 *, f32 *);
typedef struct {
    u8 pad_0[0x24C];
    f32 local_0;
    f32 local_1;
} FirstPersonYawStep;
extern void yaw_setIdeal(PlayerState *, f32);
extern void yaw_set(PlayerState *, f32);
typedef struct {
    u8 pad_0[0x14];
    s32 unk14;
    u8 pad_1[8];
    f32 unk20[3];
    f32 unk2C[3];
    f32 unk38[3];
    f32 unk44;
    f32 unk48;
    u8 pad_2[4];
    s32 unk50;
} FirstpAim1828;
extern f32 func_800137F4(f32);
extern f32 func_800EF030(f32 *);
extern void func_800EE7B4(f32 *, f32 *, f32 *, f32);
void func_80800858_bsfirstp();
int func_808019B0_bsfirstp();
void func_80801C74_bsfirstp();
void func_80801FD0_bsfirstp();
void func_808023A0_bsfirstp();
int func_80802438_bsfirstp();
int func_80802E7C_bsfirstp();
void func_808030E0_bsfirstp();
void func_80804848_bsfirstp();
void func_80806000_bsfirstp();
void func_808061AC_bsfirstp();
void func_8080682C_bsfirstp();
f32 func_808068E8_bsfirstp();
f32 func_80806928_bsfirstp();
f32 func_808069FC_bsfirstp();
void func_80807BB8_bsfirstp();
int func_80807D70_bsfirstp();
int func_80807EEC_bsfirstp();
int func_80807F24_bsfirstp();
unsigned int func_808080A4_bsfirstp();
void func_80808B8C_bsfirstp();
void func_80808C48_bsfirstp();
void func_80808CAC_bsfirstp();
int func_80808D80_bsfirstp();
void func_80808DB0_bsfirstp();
void func_80808E78_bsfirstp();
int func_80808EF0_bsfirstp();
void func_80808F38_bsfirstp();
void func_8080911C_bsfirstp();
void func_80809198_bsfirstp();
void func_80809250_bsfirstp();
int func_808094F4_bsfirstp();
void func_80809684_bsfirstp();
int func_80809740_bsfirstp();
void func_808099A8_bsfirstp();
void func_808099B4_bsfirstp();
void func_80809A10_bsfirstp();
s32 func_80809C30_bsfirstp();
f32 func_80809D94_bsfirstp();
void func_80809F74_bsfirstp();
void func_8080A194_bsfirstp();
void func_8080A250_bsfirstp();
void func_80800F14_bsfirstp();
void func_80801000_bsfirstp();
void func_80801E18_bsfirstp();
void bsfirstp_entrypoint_26();
void func_8080649C_bsfirstp();
void func_80806588_bsfirstp();
void func_80808148_bsfirstp();
void func_808086B0_bsfirstp();
int func_80809540_bsfirstp();
void func_80809DD0_bsfirstp();
void func_8080A03C_bsfirstp();

s32 func_80800864_bsfirstp();
int func_80800900_bsfirstp(PlayerState *param_0, f32 param_1);
s32 func_80801B64_bsfirstp();
void func_80801BDC_bsfirstp();
void func_80801C18_bsfirstp();
void func_80801D30_bsfirstp();
void func_80801D70_bsfirstp();
f32 func_8080222C_bsfirstp(f32 param_0, f32 param_1, f32 param_2);
f32 func_80802304_bsfirstp(f32 param_0, f32 param_1, f32 param_2);
int func_80802484_bsfirstp();
void func_80803124_bsfirstp();
void func_808035EC_bsfirstp(PlayerState *param_0, f32 *param_1, f32 *param_2);
void func_80803B58_bsfirstp(u8 *param_0, f32 param_1);
f32 func_80803B68_bsfirstp();
void func_80805380_bsfirstp(f32 *param_0, f32 param_1, f32 param_2, f32 param_3);
f32 func_80806130_bsfirstp(void *param_0);
f32 func_8080613C_bsfirstp(void *param_0);
f32 func_80806170_bsfirstp(void *param_0, f32 param_1);
void func_8080633C_bsfirstp(PlayerState *param_0, f32 param_1);
void func_80806774_bsfirstp();
f32 func_808069BC_bsfirstp();
f32 func_80806AD0_bsfirstp(PlayerState *param_0, f32 param_1, f32 param_2);
void func_80807C8C_bsfirstp();
void func_80807DD4_bsfirstp();
s32 func_80807F5C_bsfirstp();
void func_80807F9C_bsfirstp();
void func_80807FBC_bsfirstp();
void func_80808084_bsfirstp(s32 arg0);
void func_80808100_bsfirstp();
void func_808084AC_bsfirstp(f32 *param_0, f32 param_1);
void func_8080853C_bsfirstp(f32 *param_0, f32 param_1);
int func_80808678_bsfirstp(s32 param_0, s32 param_1);
void func_808090D8_bsfirstp();
s32 func_80809900_bsfirstp();
f32 func_80809938_bsfirstp();
void func_8080995C_bsfirstp();
void func_80809A7C_bsfirstp();
void func_80809AF8_bsfirstp(PlayerState *param_0, f32 param_1, f32 param_2, f32 param_3);
void func_80809CB4_bsfirstp();
void func_80809CD8_bsfirstp();
void func_80809CF8_bsfirstp();
s32 func_80809D24_bsfirstp();
s32 func_80809D6C_bsfirstp();
void func_80809DA0_bsfirstp();

// Allocates and clears the 0x2A8-byte first-person state block.
s32 func_80800000_bsfirstp(u8 *player)
{
    s32 *block_ptr;
    s32 block;
    s32 block_addr;
    _bastatemem_entrypoint_0(player, 0x2A8);
    block_addr = (block_ptr = *(s32 *) (player + 0x188));
    block = block_addr;
    aligned8_memset(block_addr, 0, 0x2A8);
    return block;
}

void func_80800040_bsfirstp()
{
    _bastatemem_entrypoint_1();
}

void bsfirstp_entrypoint_0(PlayerState *player, f32 *out_pos, f32 *out_vec)
{
    f32 *kazfly;
    f32 *data;

    kazfly = (f32 *) player->kazfly;
    data = func_80802484_bsfirstp(player);
    out_vec[0] = data[7];
    out_vec[1] = data[8];
    out_vec[2] = data[9];
    out_pos[0] = data[4] + kazfly[6];
    out_pos[1] = data[5] + kazfly[7];
    out_pos[2] = data[6];
    func_8080800C_bsfirstp((s32) player);
}

void bsfirstp_entrypoint_1(Actor *actor, s32 mode)
{
    s32 anim_ctrl_tmp;
    s32 anim_ctrl;
    switch (mode) {
        case 0:
            anim_ctrl_tmp = baanim_getAnimCtrlPtr(actor);
            anim_ctrl = anim_ctrl_tmp;
            func_80801000_bsfirstp(actor);
            func_8008B304(anim_ctrl);
            func_800DF41C(func_8008B4D4(anim_ctrl));
            return;

        case 1:
            anim_ctrl = func_8008D04C(actor);
            if (func_80800864_bsfirstp(actor) != 0) {
                func_80800F14_bsfirstp(actor);
            }
            func_8008B304(anim_ctrl);
            func_800DF41C(func_8008B4D4(anim_ctrl));
    }
}

void func_80800190_bsfirstp(Actor *actor)
{
    u8 *fp;

    fp = *(u8 **) ((char *) actor + 0x188);
    func_80800858_bsfirstp(actor, 0);
    func_800EFD24(fp + 0x2C);
    *(f32 *) ((char *) fp + 0x50) = 0.0f;
}

int func_808001D0_bsfirstp(Actor *actor)
{
    func_80808C48_bsfirstp(actor);
    // Matching: the `| 0` is needed for the match.
    func_80800858_bsfirstp(actor, 0 | 0);
}

void func_808001FC_bsfirstp()
{
    AnCtrl *anim_ctrl;
    anim_ctrl = func_8008D04C();
    anctrl_setPlaybackType(anim_ctrl, 3);
}

int func_80800228_bsfirstp()
{
    s32 anim_ctrl;
    s32 result;
    anim_ctrl = func_8008D04C();
    // Matching: the `| 0` operations are needed for the match.
    if (anctrl_getPlaybackType(anim_ctrl | 0) == 3) {
        result = 1;
    } else {
        result = 0 | 0;
    }
    return result | 0;
}

s32 func_80800264_bsfirstp(PlayerState *player, f32 value)
{
    func_8008B10C(func_8008D04C(player), value);
}

s32 func_80800290_bsfirstp(s32 player, s32 anim_id, s32 flags)
{
    baanim_playForDuration_loopStartingAt(player, anim_id, flags, baanim_getTimer(player));
}

void func_808002CC_bsfirstp(Actor *actor, s32 anim_id, f32 duration, f32 start)
{
    void *anim_ctrl;
    anim_ctrl = func_8008D04C(actor);
    anctrl_reset(anim_ctrl);
    anctrl_setIndex(anim_ctrl, anim_id);
    anctrl_setDuration(anim_ctrl, duration);
    anctrl_setStart(anim_ctrl, start);
    anctrl_setPlaybackType(anim_ctrl, 2);
    anctrl_start(anim_ctrl);
}

void func_80800340_bsfirstp(Actor *actor, s32 anim_id, f32 duration, f32 start)
{
    void *anim_ctrl;
    anim_ctrl = func_8008D04C(actor);
    anctrl_reset(anim_ctrl);
    anctrl_setIndex(anim_ctrl, anim_id);
    anctrl_setDuration(anim_ctrl, duration);
    anctrl_setStart(anim_ctrl, start);
    anctrl_setPlaybackType(anim_ctrl, 1);
    anctrl_start(anim_ctrl);
}

void func_808003B4_bsfirstp(Actor *actor, s32 anim_id, f32 duration)
{
    void *anim_ctrl;
    anim_ctrl = func_8008D04C(actor);
    anctrl_reset(anim_ctrl);
    anctrl_setSmoothTransition(anim_ctrl, 0);
    anctrl_setIndex(anim_ctrl, anim_id);
    anctrl_setDuration(anim_ctrl, duration);
    anctrl_setPlaybackType(anim_ctrl, 1);
    anctrl_start(anim_ctrl);
}

int func_80800424_bsfirstp(Actor *actor, s32 anim_id, f32 duration)
{
    AnCtrl *anim_ctrl;

    anim_ctrl = func_8008D04C(actor);
    anctrl_reset(anim_ctrl);
    anctrl_setIndex(anim_ctrl, anim_id);
    anctrl_setDuration(anim_ctrl, duration);
    anctrl_setPlaybackType(anim_ctrl, 1);
    anctrl_start(anim_ctrl);
}

void func_80800488_bsfirstp(Actor *actor, s32 anim_id, f32 duration)
{
    void *anim_ctrl;
    anim_ctrl = func_8008D04C(actor);
    anctrl_reset(anim_ctrl);
    anctrl_setSmoothTransition(anim_ctrl, 0);
    anctrl_setIndex(anim_ctrl, anim_id);
    anctrl_setDuration(anim_ctrl, duration);
    anctrl_setPlaybackType(anim_ctrl, 2);
    anctrl_start(anim_ctrl);
}

void func_808004F8_bsfirstp(u8 *player)
{
    u8 *fp = *(u8 **) (player + 0x188);
    f32 angle = *(f32 *) (fp + 0x20C);
    func_800EEC70(fp + 0x2C, angle, yaw_get(), 150.0f);
}

int func_8080053C_bsfirstp(Actor *actor)
{
    s32 fp;
    fp = *(s32 *) ((char *) actor + 0x188);
    func_808004F8_bsfirstp(actor);
    func_800EFD24(fp + 0x38);
}

// Matching: the second parameter is dead and overwritten before use; it only acts as a holder.
void func_8080056C_bsfirstp(PlayerState *player, f32 *fp)
{
    f32 vec[4];
    f32 factor;
    f32 speed;
    f32 along;
    f32 across;

    fp = *(f32 **) ((u8 *) player + 0x188);
    factor = func_800D9004();
    func_8009B4D0(player, vec);
    func_800EF3DC(vec, fp + 0x2C / 4);
    func_808004F8_bsfirstp(player);
    func_800EF04C(vec, fp + 0x2C / 4);
    func_800EF334(vec, 1.0f / factor);
    fp[0x38 / 4] += (vec[0] - fp[0x38 / 4]) * 0.2f;
    fp[0x40 / 4] += (vec[2] - fp[0x40 / 4]) * 0.2f;
    {
        speed = func_80806170_bsfirstp(player, func_800EEFFC(fp + 0x38 / 4));
        along = func_800F1CF0(fp + 0x38 / 4, fp + 0x2C / 4);
        across = sqrtf(1.0f - along * along);
        fp[0x44 / 4] = func_800F0DC0(speed * along, 1.0f);
        fp[0x48 / 4] = func_800F0DC0(speed * across, 1.0f);
        factor = func_80809938_bsfirstp(player);
        fp[0x4C / 4] += (func_800F0DC0(factor, 1.0f) - fp[0x4C / 4]) * 0.2f;
    }
}

void func_808006DC_bsfirstp(PlayerState *player)
{
    u8 *fp = *(u8 **) ((u8 *) player + 0x188);
    f32 fwd;
    f32 side;
    f32 scaled;
    f32 amp;
    f32 sine;
    fwd = mlAbsF(*(f32 *) (fp + 0x44));
    side = *(f32 *) (fp + 0x48);
    if (*(s32 *) fp == 3) {
        fwd *= 1.333f;
        side *= 1.333f;
    }
    scaled = side * 0.75f;
    amp = scaled < fwd ? fwd : scaled;
    if (amp != 0.0f) {
        *(f32 *) (fp + 0x54) = func_800136E4(*(f32 *) (fp + 0x54) + amp * 12.5f);
        sine = func_80013970(*(f32 *) (fp + 0x54));
        *(f32 *) (fp + 0x58) = sine * amp;
    } else {
        *(f32 *) (fp + 0x54) = 0.0f;
        *(f32 *) (fp + 0x58) = 0.0f;
    }
    scaled = fwd * 0.75f;
    amp = scaled < side ? side : scaled;
    if (amp != 0.0f) {
        *(f32 *) (fp + 0x5C) = func_800136E4(*(f32 *) (fp + 0x5C) + amp * 25.0f);
        sine = func_80013970(*(f32 *) (fp + 0x5C));
        *(f32 *) (fp + 0x60) = sine * amp;
    } else {
        *(f32 *) (fp + 0x5C) = 0.0f;
        *(f32 *) (fp + 0x60) = 0.0f;
    }
}

void func_80800830_bsfirstp(player, holder) s32 player;
f32 *holder;
{
    func_8080056C_bsfirstp(player, holder);
    func_808006DC_bsfirstp(player);
}

void func_80800858_bsfirstp(player, value) u8 *player;
s32 value;
{
    s8 *fp;
    *(s32 *) ((fp = (s8 *) *(u8 **) ((s8 *) player + 0x188)) + 0x28) = value;
}

s32 func_80800864_bsfirstp(player)
u8 *player;
{
    u8 *fp = *(u8 **) (player + 0x188);
    return *(s32 *) (fp + 0x28) ? 1 : 0;
}

void func_80800888_bsfirstp(u8 *player, s32 value)
{
    u8 *fp = *(u8 **) (player + 0x188);
    *(s32 *) (fp + 0x8C) = value;
    func_80800900_bsfirstp(player, 1.0f);
}

int func_808008B0_bsfirstp(PlayerState *player)
{
    f32 *kazfly = (f32 *) player->kazfly;
    f32 strength;

    strength = kazfly[0x24] - func_800D9004() * 5.5f;
    return func_80800900_bsfirstp(player, strength);
}

int func_80800900_bsfirstp(PlayerState *player, f32 strength)
{
    FirstPersonBlend1459 *blend;
    f32 *row;
    s32 active;

    blend = (FirstPersonBlend1459 *) player->kazfly;

if (strength <= 0.0f) {
    active = 0;
    strength = 0.0f;
} else {

active = 1;
}
row = D_8080A5B0_bsfirstp[blend->type];
blend->strength = strength;
blend->components[0] = row[0] * strength;
blend->components[1] = row[1] * strength;
blend->components[2] = row[2] * strength;
blend->components[3] = row[3] * strength;
return active;
}

void func_80800978_bsfirstp(player, data, out_x, out_y) PlayerState *player;
void *data;
f32 *out_x;
f32 *out_y;
{
    f32 *kazfly;
    FirstPersonSplit *split;
    f32 x_val;
    f32 y_val;
    f32 bound;
    kazfly = (f32 *) player->kazfly;
    split = data;
    x_val = kazfly[0xC8 / 4] * 0.02712967992f;
    y_val = kazfly[0xCC / 4] * 0.01768659241f;
    if (x_val > 0.0f)
        bound = -split->upper;
    else
        bound = split->lower;
    x_val *= bound;
    if (y_val > 0.0f)
        bound = -split->right;
    else
        bound = split->left;
    y_val *= bound;
    out_x[0] = split->fraction * x_val;
    out_y[0] = split->fraction * y_val;
    out_x[1] = x_val - out_x[0];
    out_y[1] = y_val - out_y[0];
}

void func_80800A18_bsfirstp(PlayerState *player, void *pose)
{
    u8 *data;
    f32 part_x[2];
    f32 part_y[2];
    f32 *kazfly;
    f32 sway;
    f32 bob;

    data = func_80802484_bsfirstp(player);
    func_80800978_bsfirstp(player, data, part_x, part_y);
    func_800E0AFC(pose, data[0x2B], 1.0f, part_x[0], part_y[0], 0.0f);
    func_800E0AFC(pose, data[0x2F], 1.0f, 0.0f, part_y[1], -part_x[1]);
    kazfly = (f32 *) player->kazfly;
    sway = kazfly[0x44 / 4] * 20.0f;
    bob = kazfly[0x60 / 4] * -15.0f;
    func_800E0AFC(pose, 0x2D, 1.0f, 0.0f, sway, bob);
    func_800E0AFC(pose, 0x2E, 1.0f, 0.0f, sway, bob);
    func_800E0AFC(pose, 0x2F, 1.0f, 0.0f, sway, bob);
}

void func_80800B44_bsfirstp(PlayerState *player, void *pose)
{
    u8 *data;
    f32 part_x[2];
    f32 part_y[2];
    f32 sway;
    f32 bob;

    data = func_80802484_bsfirstp(player);
    func_80800978_bsfirstp(player, data, part_x, part_y);
    func_800E0AFC(pose, data[0x2B], 1.0f, part_x[0], part_y[0], 0.0f);
    func_800E0AFC(pose, data[0x2F], 1.0f, part_x[1], part_y[1], 0.0f);
    sway = *(f32 *) ((u8 *) player->kazfly + 0x44) * 20.0f;
    bob = *(f32 *) ((u8 *) player->kazfly + 0x60) * -15.0f;
    func_800E0AFC(pose, 0x2B, 0.5f, 0.0f, sway, bob);
    func_800E0AFC(pose, 0x2C, 0.5f, 0.0f, sway, bob);
    func_800E0AFC(pose, 0x2D, 0.5f, 0.0f, sway, bob);
    func_800E0AFC(pose, 0x2E, 0.5f, 0.0f, sway, bob);
}

void func_80800C88_bsfirstp(PlayerState *player, void *pose)
{
    u8 *data;
    f32 part_x[2];
    f32 part_y[2];
    data = func_80802484_bsfirstp(player);
    func_80800978_bsfirstp(player, data, part_x, part_y);
    func_800E0AFC(pose, data[0x2B], 1.0f, part_x[0], part_y[0], 0.0f);
    func_800E0AFC(pose, data[0x2F], 1.0f, 0.0f, part_y[1], -part_x[1]);
}

void func_80800D18_bsfirstp(PlayerState *player, void *pose)
{
    Mass47Firstp *data;
    f32 part_x[2];
    f32 part_y[2];
    f32 sway;
    f32 bob;
    u8 *kazfly;
    f32 bob_neg;

    data = (Mass47Firstp *) func_80802484_bsfirstp(player);
    func_80800978_bsfirstp(player, data, part_x, part_y);
    func_800E0AFC(pose, data->local_1, 1.0f, -part_x[0], part_y[0], 0.0f);
    func_800E0AFC(pose, data->local_3, 1.0f, -part_x[1], part_y[1], 0.0f);
    kazfly = (u8 *) player->kazfly;
    sway = *(f32 *) (kazfly + 0x44) * -20.0f;
    bob = *(f32 *) (kazfly + 0x60) * -15.0f;
    bob_neg = -bob;
    func_800E0AFC(pose, 0x3C, 0.5f, 0.0f, sway, bob_neg);
    func_800E0AFC(pose, 0x3E, 0.5f, 0.0f, sway, bob_neg);
    func_800E0AFC(pose, 0x3F, 0.5f, 0.0f, sway, bob);
    func_800E0AFC(pose, 0x40, 0.5f, 0.0f, sway, bob);
    func_800E0AFC(pose, 0x54, 0.5f, bob, sway, 0.0f);
    func_800E0AFC(pose, 0x5A, 0.5f, bob, sway, 0.0f);
    func_800E0AFC(pose, 0x5B, 0.5f, bob, sway, 0.0f);
    func_800E0AFC(pose, 0x5C, 0.5f, bob, sway, 0.0f);
    func_800E0AFC(pose, 0x5D, 0.5f, bob, sway, 0.0f);
}

void func_80800F14_bsfirstp(player) PlayerState *player;
{
    u8 *fp;
    void *pose;

    fp = *(u8 **) ((u8 *) player + 0x188);
    pose = func_8009370C(player);
    func_800E0ACC(pose);
    func_800E0AF0(pose, 1.0f);
    *(f32 *) (fp + 0x18) = *(f32 *) (fp + 0x58) * 0.02f;
    *(f32 *) (fp + 0x1C) = *(f32 *) (fp + 0x60) * 0.03f;
    switch (func_800A3280(player)) {
        case 1:
        case 6:
            func_80800A18_bsfirstp(player, pose);
            break;
        case 4:
            func_80800B44_bsfirstp(player, pose);
            break;
        case 5:
            func_80800C88_bsfirstp(player, pose);
            break;
        case 2:
        case 3:
            func_80800D18_bsfirstp(player, pose);

}
}

void func_80801000_bsfirstp(player) PlayerState *player;
{
    u8 *fp;
    void *pose;
    f32 vert[2];
    f32 horiz[2];
    f32 rate;
    f32 offset;

    fp = *(u8 **) ((u8 *) player + 0x188);
    pose = func_80092AD8(player);
    func_800E0ACC(pose);
    func_800E0AF0(pose, 1.0f);
    vert[0] = func_800F0DC0(func_80806130_bsfirstp(player), 80.0f);
    rate = func_800F1214(func_8080613C_bsfirstp(player), 360.0f, 720.0f);
    func_80805380_bsfirstp((f32 *) (fp + 0x50), vert[0], rate, rate * (1.0f / 24.0f));
    vert[0] = *(f32 *) (fp + 0x50);
    vert[1] = func_80013728(*(f32 *) (fp + 0xCC) + vert[0]);
    horiz[0] = *(f32 *) (fp + 0x20C);
    horiz[1] = func_80013728(*(f32 *) (fp + 0xC8) + *(f32 *) (fp + 0x20C));
    switch (*(s32 *) fp) {
        case 1:
        case 5: {
            f32 adj_a;
            const f32 eighth = 0.125f;
            f32 adj_b;
            offset = vert[0];
            func_800E0AFC(pose, (u8) (*(s32 *) fp == 1 ? 0x2B : 3), 1.0f, 0.0f, offset,
                          0.0f);
            adj_a = -horiz[0] * 0.4f;
            offset *= -0.5f;
            func_800E0AFC(pose, 1, 1.0f, adj_a, offset, 0.0f);
            adj_a = -horiz[0] * 0.6f;
            func_800E0AFC(pose, 0x12, 1.0f, adj_a, offset, 0.0f);
            offset = -0.25f * vert[0] + vert[1] * eighth;
            func_800E0AFC(pose, 0x49, 1.0f, -horiz[1] * 0.1f, offset, 0.0f);
            func_800E0AFC(pose, 0x4B, 1.0f, -horiz[1] * 0.5f, offset, 0.0f);
            offset = vert[1] * eighth;
            adj_b = vert[1] * 0.0625f;
            func_800E0AFC(pose, 8, 1.0f, 0.0f, offset, adj_b);
            offset = -horiz[1] * 0.0625f;
            adj_b = horiz[1] * eighth;
            func_800E0AFC(pose, 0xE, 1.0f, 0.0f, offset, adj_b);
            break;
        }

case 4: {
    f32 adj_a;
    f32 adj_b;
    f32 adj_c;
    const f32 quarter = 0.25f;
    adj_a = vert[0] * 0.5f;
    if (adj_a != 0.0f) {
        func_800E0AFC(pose, 3, 1.0f, 0.0f, adj_a, 0.0f);
        func_800E0AFC(pose, 6, 1.0f, 0.0f, adj_a, 0.0f);
        func_800E0AFC(pose, 0x14, 1.0f, 0.0f, adj_a, 0.0f);
    }
    adj_b = -horiz[0] * 0.4f;
    adj_a = -vert[0] * 0.25f;
    func_800E0AFC(pose, 1, 1.0f, adj_b, adj_a, 0.0f);
    adj_b = -horiz[0] * 0.6f;
    func_800E0AFC(pose, 0x12, 1.0f, adj_b, adj_a, 0.0f);
    adj_c = horiz[1] * quarter;
    offset = quarter * vert[1] - vert[0] * 0.5f;
    func_800E0AFC(pose, 0x1E, 1.0f, 0.0f, adj_c, offset);
    func_800E0AFC(pose, 0x3A, 1.0f, 0.0f, -adj_c, offset);
    break;
}
case 2:
case 3: {
    f32 adj_a;
    f32 adj_b;
    const f32 quarter = 0.25f;
    func_800E0AFC(pose, 3, 1.0f, 0.0f, vert[0], 0.0f);
    func_800E0AFC(pose, 1, 1.0f, -horiz[0] * 0.4f, -vert[0] * 0.67f, 0.0f);
    func_800E0AFC(pose, 0x12, 1.0f, -horiz[0] * 0.6f, -vert[0] * 0.33f, 0.0f);
    adj_a = horiz[1] * quarter;
    adj_b = quarter * vert[1] - vert[0] * 0.33f;
    func_800E0AFC(pose, 0x1E, 1.0f, 0.0f, adj_a, adj_b);
    func_800E0AFC(pose, 0x3A, 1.0f, -adj_a, adj_b, 0.0f);
    break;
}

case 0:
    func_800E0AFC(pose, 3, 1.0f, 0, vert[0], 0);
    func_800E0AFC(pose, 0x6C, 1.0f, -horiz[0], -vert[0], 0);
    }
    }

    void func_808015C0_bsfirstp(s32 player, u8 *out_pos, u8 *out_rot)
    {
        u8 *data;
        f32 heading;
        data = func_80802484_bsfirstp();
        func_8009C128(player, out_pos);
        *((f32 *) (((s8 *) out_pos) + 4)) =
            (f32) ((*((f32 *) (((s8 *) data) + 8))) + (*((f32 *) (((s8 *) out_pos) + 4))));
        *((f32 *) (((s8 *) out_rot) + 0)) = 0.0f;
        heading = yaw_get(player) + 180.0f;
        *((f32 *) (((s8 *) out_rot) + 4)) = heading;
        *((f32 *) (((s8 *) out_rot) + 8)) = 0.0f;
    }

    extern f32 func_800C517C(s32);
    extern int func_800A4C68();

    f32 func_80801640_bsfirstp(s32 player)
    {
        return func_800C517C(func_800A4C68(player));
    }

    void func_80801668_bsfirstp(u8 *player, f32 volume)
    {
        u8 *fp = *(u8 **) (player + 0x188);
        *(f32 *) (fp + 0x9C) = func_80801640_bsfirstp(player);
        *(f32 *) (fp + 0x98) = volume;
    }

    // Matching: the line breaks in this function are needed for the match.
    void func_808016A0_bsfirstp(PlayerState *player)
    {
        FirstPersonVolume1536 *fp;
        f32 current;
        f32 target;
        f32 step;
        f32 dir;
        f32 diff;

        fp = (FirstPersonVolume1536 *) player->kazfly;
        target = fp->local_0;
        current = fp->local_1;
        if (target != current) {
            diff = target - current;
            dir = func_800F2108(diff);
            target = mlAbsF(diff);
            step = target * 0.5f;

if (step < 0.5f) {
    if (target > 0.5f)
        step = 0.5f;
    else
        step = target;
}

current += step * dir;
fp->local_1 = current;
func_800C5148(func_800A4C68(player), current);
}
}

void func_8080175C_bsfirstp(u8 *player)
{
    u8 *fp = *(u8 **) (player + 0x188);
    f32 volume = *(f32 *) (fp + 0x98);
    *(f32 *) (fp + 0x9C) = volume;
    func_800C5148(func_800A4C68(), volume);
}

void bsfirstp_entrypoint_2(PlayerState *player)
{
    s32 *char_data;
    void *camera;
    f32 position[3];
    f32 rotation[3];

    char_data = func_80802484_bsfirstp(player);
    camera = func_800A4CA8(player);
    func_80111590(camera, 0.0f, 0.0f, 360.0f, 360.0f);
    func_80110730(camera, 1);
    func_808015C0_bsfirstp(player, position, rotation);
    _ncba1p_entrypoint_6(camera, position);
    _ncba1p_entrypoint_7(camera, rotation);
    if (func_800A3404(player)) {
        _ncba1p_entrypoint_2(camera);
        _ncba1p_entrypoint_4(camera, 0);
    }
    func_8010FD60(func_800A4C88(player), char_data[0]);
    func_80801668_bsfirstp(player, ((f32 *) char_data)[1]);
}

void func_8080187C_bsfirstp(Actor *actor)
{
    if (func_800A5090(actor) == 0) {
        func_800A5004(actor);
        func_800CA6C0(func_800A5090(actor), 0x3F800000, 0x447A0000);
        func_80801668_bsfirstp(actor, func_80801640_bsfirstp(actor));
    }
}

int func_808018E0_bsfirstp(Actor *actor)
{
    func_80110730(func_800A4CA8(actor), 0);
    func_8010FD38(func_800A4C88(actor), 0);
    func_800A5044(actor);
}

void func_80801928_bsfirstp(Actor *actor)
{
    s32 fp;
    f32 position[3];
    f32 rotation[3];

    if (func_800A5090(actor) != 0) {
        fp = *(s32 *) ((char *) actor + 0x188);
        func_808015C0_bsfirstp(actor, position, rotation);
        rotation[0] = *(f32 *) ((char *) fp + 0x20C);
        _ncba1p_entrypoint_6(func_800A4CA8(actor), position);
        _ncba1p_entrypoint_7(func_800A4CA8(actor), rotation);
        func_808019B0_bsfirstp(actor);
    }
    func_808016A0_bsfirstp(actor);
}

int func_808019B0_bsfirstp(player)
s32 player;
{
    s32 *data;
    s32 handle;
    data = func_80802484_bsfirstp(player);
    handle = func_800A4C88(player);
    func_8010FD60(handle, *data);
}

int func_808019EC_bsfirstp(Actor *actor)
{
    if (func_800A4D40(actor) && func_800A5090(actor)) {
        func_808019B0_bsfirstp(actor);
        func_8080175C_bsfirstp(actor);
    }
}

void func_80801A34_bsfirstp(s32 actor)
{
    func_8080187C_bsfirstp(actor);
    bsfirstp_entrypoint_2(actor);
}
int func_80801A5C_bsfirstp(Actor *actor)
{
    func_8080187C_bsfirstp(actor);
    func_800A3544(actor, 1);
    bsfirstp_entrypoint_2(actor);
    func_8080175C_bsfirstp(actor);
}

int func_80801A98_bsfirstp(Actor *actor)
{
    s32 camera;
    camera = func_800A4CA8(actor);
    return _ncba1p_entrypoint_10(camera | 0) == 2;
}

int func_80801AC4_bsfirstp(s32 player)
{
    s32 *fp = *(s32 **) ((char *) player + 0x188);
    fp[0x28] = 0;
    func_80801B64_bsfirstp(player, 0);
}

void func_80801AEC_bsfirstp(s32 player)
{
    func_80801B64_bsfirstp(player, 0);
}

int func_80801B0C_bsfirstp(s32 player, s32 *out_a, s32 *out_b)
{
    if (func_800F424C(player)) {
        *out_a = bainput_func_80097B28(player);
        *out_b = *out_a;
    } else {
        *out_a = 0;
        *out_b = 0;
    }
}

s32 func_80801B64_bsfirstp(player, mode)
s32 player;
s32 mode;
{
    switch (mode) {
        case 0:
            func_80801BDC_bsfirstp(player);
            break;
        case 1:
            func_80801D30_bsfirstp(player);
            break;
        case 2:
            func_80801C18_bsfirstp(player);
            break;
        case 3:
            func_80801C74_bsfirstp(player);
    }
}

void func_80801BDC_bsfirstp(player) u8 *player;
{
    u8 *fp = *(u8 **) (player + 0x188);
    _baeggcursor_entrypoint_7(player, 1);
    func_80801D70_bsfirstp(player);
    *(s32 *) (fp + 0xA8) = 0;
}

void func_80801C18_bsfirstp(player) u8 *player;
{
    u8 *fp = *(u8 **) (player + 0x188);
    s32 cursor_state = *(s32 *) (fp + 0xA8);
    if (cursor_state != 0 && cursor_state != 2) {
        _baeggcursor_entrypoint_7(player, 1);
        *(s32 *) (fp + 0xAC) = *(s32 *) (fp + 0xA8);
        *(s32 *) (fp + 0xA8) = 2;
        *(s32 *) (fp + 0xA4) = *(s32 *) (fp + 0xA0);
        *(s32 *) (fp + 0xA0) = 0;
    }
}

// Matching: the line breaks in this function are needed for the match.
void func_80801C74_bsfirstp(player) void *player;
{
    u8 *fp;
    s32 saved_state;
    s32 aim_mode;
    fp = *((u8 **) (((char *) player) + 0x188));
    if ((*((s32 *) (((char *) fp) + 0xA8))) == 2) {
        saved_state = *((s32 *) (((char *) fp) + 0xAC));

switch (saved_state) {
    case 0:
        *(s32 *) ((char *) fp + 0xA8) = 0;
        return;

    case 1:
        *(s32 *) ((char *) fp + 0xA8) = 1;
        func_80801D70_bsfirstp(player);
        aim_mode = *(s32 *) ((char *) fp + 0xA4);
        if (*(s32 *) ((char *) fp + 0xA4) != 0) {
            if (aim_mode == 1) {
                _baeggcursor_entrypoint_7(player, 2);
                func_80802438_bsfirstp(player, 1);
            }
        } else {
            _baeggcursor_entrypoint_7(player, 1);
            func_80802438_bsfirstp(player, 0);
        }
}

}
}

void func_80801D30_bsfirstp(player) u8 *player;
{
    u8 *fp;

    fp = (*(u8 **) ((s8 *) (player) + (0x188)));
    (*(s32 *) ((s8 *) (fp) + (0xA8))) = 1;
    (*(s32 *) ((s8 *) (fp) + (0xB0))) = 0;
    _baeggcursor_entrypoint_7(player, 1);
    func_80802438_bsfirstp(player, 0);
}

void func_80801D70_bsfirstp(player) u8 *player;
{
    u8 *fp = *(u8 **) (player + 0x188);
    *(f32 *) (fp + 0xB8) = 152.0f;
    *(f32 *) (fp + 0xBC) = 114.0f;
    *(f32 *) (fp + 0xB4) = 0.0f;
    *(f32 *) (fp + 0xC0) = 0.0f;
    *(f32 *) (fp + 0xC4) = 0.0f;
    _baeggcursor_entrypoint_10(player, 152.0f, 114.0f);
}

void func_80801DC0_bsfirstp(u8 *player)
{
    u8 *fp = *(u8 **) (player + 0x188);
    s32 cursor_state = *(s32 *) (fp + 0xA8);
    if (cursor_state == 1 || cursor_state == 2) {
        func_80801E18_bsfirstp(player);
        func_80801FD0_bsfirstp(player, *(s32 *) (fp + 0xC));
        func_808023A0_bsfirstp(player);

}
}

// Matching: the line breaks in this function are needed for the match.
void func_80801E18_bsfirstp(player) u8 *player;
{
    u8 *fp;
    s32 input_a;
    s32 input_b;
    if (1) { // Matching: empty block, needed for the match.
    }

    fp = *(u8 **) (player + 0x188);
    func_80801B0C_bsfirstp(player, &input_a, &input_b);
    switch (*(s32 *) (fp + 0xB0)) {
        case 0:
            if (input_a != 0) {
                *(s32 *) (fp + 0xB0) = 1;
                _baeggcursor_entrypoint_10(player, *(f32 *) (fp + 0xB8), *(f32 *) (fp + 0xBC));
                _baeggcursor_entrypoint_7(player, 3);
                func_8010D930(12, -1, 0, D_8080A630_bsfirstp);
            }

break;

case 1:
    if (_baeggcursor_entrypoint_9(player) != 0) {
        *(s32 *) (fp + 0xB0) = 2;
        func_80802438_bsfirstp(player, 1);
    } else if (input_b == 0) {

*(s32 *) (fp + 0xB0) = 3;
}
break;
case 2:
    if (input_b == 0) {
        *(s32 *) (fp + 0xB0) = 5;
        _baeggcursor_entrypoint_7(player, 4);
        func_8010D930(12, -1, 0, D_8080A640_bsfirstp);
    }
    break;
case 3:
    if (_baeggcursor_entrypoint_9(player) != 0) {
        *(s32 *) (fp + 0xB0) = 4;
        func_80802438_bsfirstp(player, 1);
    }
    break;
case 4:
    *(s32 *) (fp + 0xB0) = 5;
    _baeggcursor_entrypoint_7(player, 4);
    func_8010D930(12, -1, 0, D_8080A640_bsfirstp);
    break;
case 5:
    if (_baeggcursor_entrypoint_2(player) != 4) {
        *(s32 *) (fp + 0xB0) = 0;
        func_80802438_bsfirstp(player, 0);
    }
    break;
    }
    }

    void func_80801FD0_bsfirstp(player, preset) PlayerState *player;
    s32 preset;
    {
        u8 *fp;
        f32 dt;
        f32 range[2];
        f32 margin[2];
        f32 speed[2];
        f32 blend;
        f32 *row;
        f32 *cursor;
        f32 *offset;
        f32 target[2];
        f32 input[2];
        s32 pad; // Matching: unused, only reserves a stack slot.

        fp = *(u8 **) ((u8 *) player + 0x188);
        blend = *(f32 *) (fp + 0xB4);
        cursor = (f32 *) (fp + 0xB8);
        dt = func_800D9004();
        switch (*(s32 *) (fp + 0xA0)) {
            case 0:
                blend -= dt * 4.0f;
                if (blend < 0)
                    blend = 0;
                break;
            case 1:
                blend += dt * 4.0f;
                if (blend >= 1)
                    blend = 1;
        }
        *(f32 *) (fp + 0xB4) = blend;
        row = (f32 *) (D_8080A5D0_bsfirstp + preset * 0x30);
        range[0] = row[0] + (row[6] - row[0]) * blend;
        range[1] = row[1] + (row[7] - row[1]) * blend;
        margin[0] = row[2] + (row[8] - row[2]) * blend;
        margin[1] = row[3] + (row[9] - row[3]) * blend;
        speed[0] = row[4] + (row[10] - row[4]) * blend;
        speed[1] = row[5] + (row[11] - row[5]) * blend;
        if (*(s32 *) (fp + 0xA8) == 1) {
            input[0] = *(f32 *) (fp + 0x168);
            input[1] = *(f32 *) (fp + 0x184);
        } else {
            input[0] = 0.0f;
            input[1] = 0.0f;
        }
        target[0] = input[0] * range[0] + 152.0f;
        target[1] = input[1] * range[1] + 114.0f;
        cursor[0] = func_8080222C_bsfirstp(cursor[0], target[0], speed[0]);
        cursor[1] = func_8080222C_bsfirstp(cursor[1], target[1], speed[1]);
        _baeggcursor_entrypoint_10(player, cursor[0], cursor[1]);
        offset = (f32 *) (fp + 0xC0);
        offset[0] = func_80802304_bsfirstp(cursor[0] - 152.0f, range[0], margin[0]);
        offset[1] = func_80802304_bsfirstp(cursor[1] - 114.0f, range[1], margin[1]);
    }

    f32 func_8080222C_bsfirstp(f32 value, f32 target, f32 max_step)
    {
        f32 step;
        s32 i;
        for (i = 0; i < func_800D8FEC() * 5; i++) {
            step = func_800F0DC0((target - value) * 0.04f, max_step);
            value += step;
        }
        if (mlAbsF(step) < 0.02f)
            value = target;
        return value;
    }

    f32 func_80802304_bsfirstp(f32 value, f32 limit, f32 margin)
    {
        f32 result;
        f32 edge;
        f32 inv_margin;

        result = 0.0f;
        if (margin != 0) {
            edge = limit - margin;
            inv_margin = 1.0f / margin;
            if (edge < value) {
                result = (value - edge) * inv_margin;
            } else if (value < -edge) {
                result = (value + edge) * inv_margin;
            }
            result = func_800F0DC0(result, 1.0f);
        }
        return result;
    }

    void func_808023A0_bsfirstp(player) PlayerState *player;
    {
        FirstPersonProjection *proj;
        f32 *cursor;
        f32 aspect;
        f32 x_offset;
        f32 scale;
        proj = (FirstPersonProjection *) player->kazfly;
        cursor = proj->position;
        aspect = func_800A8AF0(func_800A4C68(player));
        x_offset = 152.0f - cursor[0];
        scale = aspect * 0.75f;
        x_offset *= scale;
        proj->output[1] = func_80013728(func_80013B7C(x_offset, 152.0f));
        proj->output[0] = func_80013728(func_80013B7C(114.0f - cursor[1], 114.0f));
    }

    int func_80802438_bsfirstp(player, value)
    Actor *player;
    s32 value;
    {
        s32 *fp = *(s32 **) ((char *) player + 0x188);
        fp[0x28] = value;
    }

    s32 func_80802444_bsfirstp(Actor *actor)
    {
        struct ActorLocal_FirstPerson **fp_ptr;
        struct ActorLocal_FirstPerson *fp;
        fp_ptr = (struct ActorLocal_FirstPerson **) ((u8 *) actor + 0x188);
        fp = *fp_ptr;
        return (*(s32 *) ((char *) (fp) + 160)) == 1;
    }

    // Per-character data lookups, indexed by func_800A3280().
    int func_80802458_bsfirstp()
    {
        return D_8080ABF0_bsfirstp[func_800A3280()];
    }

    int func_80802484_bsfirstp()
    {
        return D_8080A890_bsfirstp[func_800A3280()];
    }

    s16 *func_808024B0_bsfirstp()
    {
        return D_8080AFFC_bsfirstp[func_800A3280()];
    }

    int func_808024DC_bsfirstp()
    {
        return D_8080AFB4_bsfirstp[func_800A3280()];
    }

    s16 *func_80802508_bsfirstp(void)
    {
        return D_8080AFCC_bsfirstp[func_800A3280()];
    }

    int func_80802534_bsfirstp(void)
    {
        return D_8080B02C_bsfirstp[func_800A3280()];
    }

    s32 func_80802560_bsfirstp()
    {
        return (s32) &D_8080B038_bsfirstp + (func_800A3280() * 12);
    }

    s32 func_80802594_bsfirstp()
    {
        return (s32) &D_8080B080_bsfirstp + (func_800A3280() * 12);
    }

    void func_808025C8_bsfirstp(s32 player, s32 *out_first_anim, s32 *out_second_anim)
    {
        s32 char_index;
        char_index = func_800A3280(player) - 1;
        *out_first_anim = (s32) &D_8080B1B8_bsfirstp + (char_index << 3);
        *out_second_anim = (s32) &D_8080B1E0_bsfirstp + (char_index << 3);
    }

    void func_8080261C_bsfirstp(s32 player, s32 *out_first_anim, s32 *out_second_anim)
    {
        s32 char_index;
        char_index = func_800A3280(player) - 1;
        *out_first_anim = (s32) &D_8080B208_bsfirstp + (char_index << 3);
        *out_second_anim = (s32) &D_8080B230_bsfirstp + (char_index << 3);
    }

    void func_80802670_bsfirstp(s32 player, s32 *out_anim)
    {
        s32 char_index;
        char_index = func_800A3280(player) - 1;
        *out_anim = (s32) &D_8080B258_bsfirstp + (char_index << 3);
    }

    void func_808026AC_bsfirstp(s32 player, s32 *out_first_anim, s32 *out_second_anim)
    {
        s32 char_index;
        char_index = func_800A3280(player) - 1;
        *out_first_anim = (s32) &D_8080B0C8_bsfirstp + (char_index << 3);
        *out_second_anim = (s32) &D_8080B0F0_bsfirstp + (char_index << 3);
    }

    void func_80802700_bsfirstp(s32 player, s32 *out_first_anim, s32 *out_second_anim)
    {
        s32 char_index;
        char_index = func_800A3280(player) - 1;
        *out_first_anim = (s32) &D_8080B118_bsfirstp + (char_index << 3);
        *out_second_anim = (s32) &D_8080B140_bsfirstp + (char_index << 3);
    }

    void func_80802754_bsfirstp(s32 player, s32 *out_first_anim, s32 *out_second_anim)
    {
        s32 char_index;
        char_index = func_800A3280(player) - 1;
        *out_first_anim = (s32) &D_8080B168_bsfirstp + (char_index << 3);
        *out_second_anim = (s32) &D_8080B190_bsfirstp + (char_index << 3);
    }

    int func_808027A8_bsfirstp(s32 index)
    {
        int *entry;
        int offset;
        offset = (index - 1) * 4;
        entry = &D_8080AC24_bsfirstp[offset];
        // Matching: empty block steers IDO's register allocation.
        if (offset) {
        }
        return entry;
    }

    u32 bsfirstp_entrypoint_3(s32 state_id, s32 index, s32 field)
    {
        Mass43EggAimRecord record;
        s32 word;
        s32 part;
        u32 value;
        if (!index)
            return 0;
        switch (state_id) {
            case 0x165:
                record = D_8080AD4C_bsfirstp[index - 1];
                break;
            case 0x164:
                record = D_8080ADA0_bsfirstp[index - 1];
                break;
            case 0x166:
                record = D_8080ACF8_bsfirstp[index - 1];
                break;
        }
        word = field >> 2;
        part = field & 3;
        switch (part) {
            case 0:
                value = (u32) record.local_0[word] >> 12;
                break;
            case 1:
                value = ((u8 *) &record.local_0[word])[0] & 0xF;
                break;
            case 2:
                value = (u32) ((u8 *) &record.local_0[word])[1] >> 4;
                break;
            case 3:
                value = record.local_0[word] & 0xF;
                break;
        }
        return value;
    }

    void bsfirstp_entrypoint_4(s32 player, s32 row)
    {
        u8 *entry;
        int step;
        s32 i;
        entry = &D_8080AC94_bsfirstp[0];
        entry += (row * 14) + 2;
        for (i = 1; i < 8; i++) {
            // Matching: the redundant test and the step temp are needed for the match.
            if ((i && i) && i) {
            }
            step = 2;
            _badeathmatch_entrypoint_10(player, i, entry[-2], entry[-1]);
            entry += step;
        }
    }

    void bsfirstp_entrypoint_5(Actor *player, s32 column, s32 row)
    {
        // Matching: unused pad is needed for the match.
        s32 pad[2];
        s32 value;

        value = ((u8 *) D_8080AC94_bsfirstp)[row * 5 + column - 0x92];
        func_800A18C8(player, value);
        func_800A1870(player, value);
    }

    s32 func_80802A40_bsfirstp(PlayerState *player, s32 index)
    {
        FirstPersonAnimation *entry;

        entry = D_8080B45C_bsfirstp[func_800A3280(player)];
        entry += index;
        if (entry->enabled == 0) {
            return 0;
        }
        func_8009DF18(player, entry->animation, entry->duration, entry->enabled);
        return 1;
    }

    int func_80802AA8_bsfirstp(s32 player, s16 index, OSIoMesgHdr *out_a, OSIoMesgHdr *out_b)
    {
        u32 char_id;
        s32 double_index;
        u8 *table_a;
        u8 *table_b;
        char_id = func_800A3280(player);
        double_index = index * 2;
        table_a = (char_id << 5) + (double_index * 4) + D_8080AE44_bsfirstp;
        table_b = (char_id * 0x10) + (double_index * 2) + D_8080ADF4_bsfirstp;
        *(s16 *) ((char *) out_a + 0x0) = *(s32 *) ((char *) table_a - 0x20);
        *(s16 *) ((char *) out_a + 0x2) = *(s16 *) ((char *) table_b - 0x10);
        *(s16 *) ((char *) out_b + 0x0) = *(s32 *) ((char *) table_a - 0x1C);
        *(s16 *) ((char *) out_b + 0x2) = *(s16 *) ((char *) table_b - 0xE);
    }

    void bsfirstp_entrypoint_6(PlayerState *player, f32 *out_first, f32 *out_third, f32 *out_second)
    {
        FirstPersonValues *values;

        values = (FirstPersonValues *) func_80802458_bsfirstp(player);
        *out_first = values->first;
        *out_second = values->second;
        *out_third = values->third;
        if (!func_800D3948()) {
            *out_first *= 0.67f;
        }
    }

    void bsfirstp_entrypoint_7(s32 player, f32 *out_a, f32 *out_b)
    {
        u8 *values = func_80802458_bsfirstp(player);
        *out_a = *(f32 *) (values + 0xC);
        *out_b = *(f32 *) (values + 0x10);
    }

    void func_80802BD8_bsfirstp(s32 player)
    {
    }
    void func_80802BE0_bsfirstp(s32 player)
    {
    }
    // Multiplayer (player + 0x158 != 0) dispatches to the deathmatch code.
    void func_80802BE8_bsfirstp(u8 *player, f32 unk_0)
    {
        if (*(s32 *) (player + 0x158) == 0) {
            func_80094430(player, unk_0);
        } else {
            _badeathmatch_entrypoint_8(player, unk_0);
        }
    }

    s32 func_80802C30_bsfirstp(void *player)
    {
        if (!(*(s32 *) ((char *) player + 0x158))) {
            return func_80094510(player);
        } else {
            return _badeathmatch_entrypoint_6(player);
        }
    }

    void func_80802C6C_bsfirstp(s32 player)
    {
        func_800FC660(0xF);
    }

    int func_80802C90_bsfirstp(Actor *player)
    {
        if (!(*(s32 *) ((char *) (player) + 0x158))) {
            func_80094BC0();
        } else {
            _badeathmatch_entrypoint_9(player, _badeathmatch_entrypoint_6(player));
        }
    }

    void func_80802CD8_bsfirstp(Actor *player, s32 index)
    {
        if (*(s32 *) ((char *) player + 0x158) == 0) {
            func_80094C0C();
        } else {
            _badeathmatch_entrypoint_5(player, index, -1);
        }
    }

    int func_80802D14_bsfirstp(void *player)
    {
        if (!(*(s32 *) ((char *) player + 0x158))) {
            func_80094A10();
        } else {
            _badeathmatch_entrypoint_0(player);
        }
    }

    s32 func_80802D50_bsfirstp(PlayerState *player, s32 *out_value)
    {
        u8 *state;
        s32 unk_0;

        state = (u8 *) player->kazfly;
        if (func_80802C90_bsfirstp((Actor *) player)) {
            unk_0 = 1;
        } else {
            unk_0 = 0;
        }
        switch (*(s16 *) (state + 0xE2)) {
            case 0:
                return 0;
            case 1:
                if (!unk_0) {
                    *(s16 *) (state + 0xE2) = 0;

if (*(s16 *) (state + 0xE6) == 0) {
    *(s16 *) (state + 0xE6) = 1;
    func_80802C6C_bsfirstp(player);
}

return 0;
}
break;
case 2:
    if (!unk_0) {
        *(s16 *) (state + 0xE2) = 0;

switch (*(s16 *) (state + 0xE6)) {
    case 0:
        *(s16 *) (state + 0xE6) = 1;
        func_80802C6C_bsfirstp(player);
        break;
    case 1:
        *(s16 *) (state + 0xE8) = func_80802D14_bsfirstp(player);
        func_80802E7C_bsfirstp(state);
}

return 0;
}
}
switch (func_80802E7C_bsfirstp(state)) {
    case 0:
        *out_value = 0xD8;
        break;
    case 1:
        *out_value = 0xD6;
}
return 1;
}

int func_80802E7C_bsfirstp(state)
Actor *state;
{
    s16 previous;
    char *entry_bytes;
    Actor *state_copy;
    Actor *entry;
    unsigned short previous_raw;
    entry = func_808027A8_bsfirstp(*((s16 *) (((char *) state) + 0xE8)));
    // Matching: the extra copies and `^ 0` are needed for the match.
    previous_raw = (*((s16 *) (((char *) state) + 0xE2))) ^ 0;
    previous = previous_raw;
    *((s16 *) (0xE0 + ((char *) state))) = 2;
    *((s16 *) (((char *) state) + 0xE2)) = 0;
    entry_bytes = (char *) entry;
    *((s16 *) (((char *) state) + 0xE6)) = 0;
    *((s16 *) (((char *) state) + 0xE4)) = previous;
    *((f32 *) (((char *) state) + 0xD8)) = *((f32 *) (entry_bytes + 8));
    state_copy = state;
    *((f32 *) (((char *) state_copy) + 0xDC)) = *((f32 *) (((char *) entry) + 0xC));
    return *((s32 *) entry);
}

void func_80802ED4_bsfirstp(void *player)
{
    void *state = *(void **) ((u8 *) player + 0x188);
    *(short *) ((u8 *) state + 0xE0) = 4;
    func_80803124_bsfirstp(player, 0);
}

void func_80802F00_bsfirstp(s32 player)
{
    func_80802ED4_bsfirstp(player);
}

void func_80802F20_bsfirstp(PlayerState *player)
{
    u8 *state;
    f32 delta;
    state = (u8 *) player->kazfly;
    if (!func_8009E674(player, 0x10000)) {
        if (*(s16 *) (state + 0xE0) != 4)
            func_80803124_bsfirstp(player, 4);
    } else {
        if (*(s16 *) (state + 0xE0) == 4)
            func_80803124_bsfirstp(player, 0);
        if (bakey_pressed(player, 1))
            *(s16 *) (state + 0xD4) = 1;
        if (bakey_held(player, 1))
            *(s16 *) (state + 0xD6) = 1;
        else
            *(s16 *) (state + 0xD6) = 0;
        delta = func_800D9004();
        switch (*(s16 *) (state + 0xE0)) {
            case 0:
                if (*(s16 *) (state + 0xD4))
                    func_808030E0_bsfirstp(player, 2);
                else if (*(s16 *) (state + 0xD6))
                    func_808030E0_bsfirstp(player, 1);
                break;
            case 1:
                if (func_800F1574((f32 *) (state + 0xDC), delta))
                    *(s16 *) (state + 0xE0) = 0;
                if (*(s16 *) (state + 0xD4))
                    func_808030E0_bsfirstp(player, 2);
                break;
            case 2:
                if (func_800F1574((f32 *) (state + 0xD8), delta))
                    *(s16 *) (state + 0xE0) = 1;
                if (func_800F1574((f32 *) (state + 0xDC), delta))
                    *(s16 *) (state + 0xE0) = 0;
                break;
            case 3:
                func_800F1574((f32 *) (state + 0xD8), delta);
                func_800F1574((f32 *) (state + 0xDC), delta);
                *(s16 *) (state + 0xD4) = 0;

}
}
}

void func_808030E0_bsfirstp(player, value) u8 *player;
long value;
{
    u8 *state;
    state = *(u8 **) ((u8 *) player + 0x188);
    *(s16 *) ((u8 *) state + 0xD4) = 0;
    if (*(s16 *) ((u8 *) state + 0xE2) < value) {
        *(s16 *) ((u8 *) state + 0xE2) = value;
        *(s16 *) ((u8 *) state + 0xE8) = func_80802C30_bsfirstp(player);
    }
}

void func_80803124_bsfirstp(player, unused) Actor *player;
s32 unused;
{
    s16 *state = *(s16 **) ((char *) player + 0x188);
    state[0xE0 / 2] = 0;
}

void func_80803134_bsfirstp(u8 *player)
{
    u8 *state;
    u8 *first_anim;
    u8 *second_anim;

    state = *(u8 **) ((s8 *) player + 0x188);
    func_80807BB8_bsfirstp();
    func_80808DB0_bsfirstp(player);
    *(s32 *) ((s8 *) player + 0x15C) = 0;
    func_8080261C_bsfirstp(player, &first_anim, &second_anim);
    func_80800424_bsfirstp(player, *(s16 *) ((s8 *) first_anim + 0), *(f32 *) ((s8 *) first_anim + 4));
    baanim_playForDuration_onceSmooth(player, *(s16 *) ((s8 *) second_anim + 0),
                                      *(f32 *) ((s8 *) second_anim + 4));
    _baeggsetup_entrypoint_7(player, &_bsfirstp_entrypoint_10);
    *(s16 *) ((s8 *) state + 0xE0) = 3;
    func_800A0D94(player, 1);
}

void func_808031D0_bsfirstp(u8 *player)
{
    u8 *state = *(u8 **) (player + 0x188);
    *(s16 *) (state + 0xE0) = 0;
    func_800A0D94(player, 0);
    func_80807C8C_bsfirstp(player);
}

// Matching: the line breaks in this function are needed for the match.
void func_80803204_bsfirstp(u8 *player)
{
    s32 phase;
    func_80807D48_bsfirstp(player);
    func_80808E78_bsfirstp(player);
    func_8080633C_bsfirstp(player, 1.0f);
    {
        phase = *(s32 *) ((u8 *) player + 0x15C);
        switch (phase) {
            case 0:
                if (anctrl_isAt(func_8008D04C(player), 0.600000024f) != 0) {
                    func_80803124_bsfirstp(player, 0);
                    *(s32 *) ((u8 *) player + 0x15C) = 1;
                }

return;

case 1:
    if (func_80800228_bsfirstp(player) != 0) {
        bs_setState(player, 0xCA);
    }

}
}
}

int bsfirstp_entrypoint_8(s32 index)
{
    return D_8080B474_bsfirstp[index];
}

void func_808032C0_bsfirstp(PlayerState *player)
{
    u8 *anim;

    func_80807BB8_bsfirstp(player);
    func_80808DB0_bsfirstp(player);
    func_80802670_bsfirstp(player, &anim);
    func_80800424_bsfirstp((Actor *) player, *(s16 *) anim, *(f32 *) (anim + 4));
    _baeggsetup_entrypoint_7(player, _bsfirstp_entrypoint_10);
}

void func_80803320_bsfirstp(s32 player)
{
    func_80807C8C_bsfirstp(player);
}
int func_80803340_bsfirstp(s32 player)
{
    s32 next_state;
    u32 unk_0;
    u8 *anim_entry;
    u8 *state;
    s16 mode;

    next_state = 0;
    func_80807D48_bsfirstp(player);
    func_80808E78_bsfirstp(player);
    func_8080633C_bsfirstp(player, 1.0f);
    if (func_80802D50_bsfirstp(player, &unk_0)) {
        func_80802670_bsfirstp(player, &anim_entry);
        func_80800424_bsfirstp(player, *(s16 *) ((char *) (anim_entry) + 0x0),
                               *(f32 *) ((char *) (anim_entry) + 0x4));
        _baeggsetup_entrypoint_7(player, &_bsfirstp_entrypoint_10);
    }
    state = *(u8 **) ((char *) (player) + 0x188);
    mode = func_80809540_bsfirstp(player, state[0x218]);
    switch (mode) {
        case 0:
            if (state[0x218] != 0) {
                func_80808D80_bsfirstp(player);
                state[0x218] = 0;
            }
            break;
        case 1:
            if (state[0x218] != 1) {
                func_80809684_bsfirstp(player, 1);
            }
            func_80809740_bsfirstp(player);
            break;
        case 2:
            if (state[0x218] != 2) {
                func_80809684_bsfirstp(player, 2);
            }
            func_80809740_bsfirstp(player);
    }
    if (func_80800228_bsfirstp(player)) {
        next_state = func_808094F4_bsfirstp(player);
    }
    if (next_state != 0) {
        bs_setState(player, next_state);
    }
}

int bsfirstp_entrypoint_9(s32 index)
{
    return D_8080B484_bsfirstp[index];
}

// Egg spawn callback.
void bsfirstp_entrypoint_10(s32 egg)
{
    PlayerState *player;
    u8 *state;
    u8 *entry;
    f32 origin[3];
    f32 unk_0[3];
    f32 direction[3];

    player = (PlayerState *) func_800F53D0();
    state = (u8 *) player->kazfly;
    entry = (u8 *) func_808027A8_bsfirstp(*(s16 *) (state + 0xE8));
    func_808035EC_bsfirstp(player, origin, direction);
    func_800EF368(direction, 90.0f);
    func_800EE780(unk_0, origin, direction);
    func_800EF368(direction, *(f32 *) (entry + 4));
    func_800EF1B8(direction, yaw_get(player) - 90.0f, *(f32 *) (state + 0x1D4) * 0.33f);
    func_8009E0AC(player, 0);
    func_80802A40_bsfirstp(player, *(s16 *) (state + 0xE8));
    func_8009E0AC(player, 1);
    _baeggcursor_entrypoint_8(player);
    _bainvisible_entrypoint_7(player, 3, 1.0f, 1.0f, 0.25f);
    _baeggsetup_entrypoint_3(egg, *(s16 *) (state + 0xE8), origin, unk_0, direction);
    func_80802CD8_bsfirstp(player, *(s16 *) (state + 0xE8));
}

void func_808035EC_bsfirstp(PlayerState *player, f32 *out_pos, f32 *out_dir)
{
    f32 cursor[2];
    f32 unk_0[2];
    f32 unk_1[3];
    f32 unk_2[3];
    f32 *table;

    table = func_80802484_bsfirstp(player);
    _baeggcursor_entrypoint_3(player, &cursor[0], &cursor[1]);
    func_800C5008(func_800A4C68(player), cursor, unk_0);
    func_800EFA4C(unk_2, unk_0[0], unk_0[1], 100.0f);
    func_800C4E58(func_800A4C68(player), unk_2, unk_1);
    func_800A4CE8(player, out_pos);
    func_800EFB24(out_dir, unk_1, out_pos);
    func_8009C15C(player, out_pos);
    out_dir[1] += table[0x12] * 2.5f / func_800EEF94(out_dir);
    out_pos[1] += table[0x12];
    func_800EF368(out_dir, 1.0f);
}

void func_808036F0_bsfirstp(u8 *player)
{
    func_80807BB8_bsfirstp();
    func_800A38F0(player, 0, 1);
    func_808061AC_bsfirstp(player, 0);
    anctrl_setPlaybackType(baanim_getAnimCtrlPtr(player), 3);
    func_808001FC_bsfirstp(player);
    _chbaddiesetup_entrypoint_1(&_bsfirstp_entrypoint_12, *(s32 **) (player + 0x184));
}

void func_80803760_bsfirstp(int player)
{
    _batimer_set(player, 0, 5.0f);
}

int func_80803784_bsfirstp(Actor *player)
{
    s32 *state;
    state = *(s32 **) ((char *) player + 0x188);
    if ((*(s32 *) ((char *) state + 0x114)) != 0) {
        func_8010114C(*(s32 *) ((char *) state + 0x114), 4, *(s32 *) ((char *) player + 0x184));
        (*(s32 *) ((char *) state + 0x114)) = 0;
    }
    func_800A38F0(player, 1, 1);
    func_80807C8C_bsfirstp(player);
}

int func_808037E4_bsfirstp(Actor *player)
{
    s32 next_state;
    next_state = 0;
    if (_batimer_decrement(player, 0)) {
        next_state = 0xCA;
    }
    if (next_state != 0) {
        bs_setState(player, next_state);
    }
}

void func_80803828_bsfirstp(u8 *player)
{
    u8 *state = *(u8 **) (player + 0x188);
    if (func_8009E6EC(player) == 0xF) {
        if (*(s32 *) (state + 0x114)) {
            *(s32 *) (state + 0x114) = 0;
        }
    } else {
        bsfirstp_entrypoint_26(player);
    }
}

int bsfirstp_entrypoint_11(s32 index)
{
    return D_8080B494_bsfirstp[index];
}

void bsfirstp_entrypoint_12(s32 unk_0)
{
    u8 *player;
    u8 *state;
    f32 position[3];

    player = func_800F53D0();
    if (bs_getCurrentState(player) == 0xD9) {
        state = (*(u8 **) ((s8 *) (player) + (0x188)));
        (*(s32 *) ((s8 *) (state) + (0x114))) = _ch1pfreeze_entrypoint_1(unk_0);
        func_8009C128(player, position);
        func_8010D930(7, -1, position, &D_8080B4A4_bsfirstp);
        _batimer_set(player, 0, 5.0f);
    }
}

void bsfirstp_entrypoint_13(PlayerState *player, f32 *out_vec, s16 mode)
{
    f32 player_pos[3];
    f32 midpoint[3];
    f32 offset[3];

    if (baflag_isTrue(player, 0x3B)) {
        switch (mode) {
            case 1:
                mode = 3;
                break;
            case 3:
                mode = 1;
                break;
        }
    }
    if (func_8009E674(player, 0x20, mode))
        mode = 2;
    switch (mode) {
        case 1:
            func_800EE7F8(out_vec, D_8080B4AC_bsfirstp);
            break;
        case 2:
            func_800EE7F8(out_vec, D_8080B4B8_bsfirstp);
            break;
        case 3:
            func_800EE780(midpoint, D_8080B4AC_bsfirstp, D_8080B4B8_bsfirstp);
            func_800EF334(midpoint, 0.5f);
            func_800EFB24(offset, D_8080B4C4_bsfirstp, midpoint);
            func_800EF334(offset, func_80803B68_bsfirstp(player));
            func_800EE780(out_vec, midpoint, offset);
    }
    func_8009C128(player, player_pos);
    func_800EF8BC(out_vec, out_vec, func_8009BFCC(player));
    func_800EF934(out_vec, out_vec, yaw_get(player));
    func_800EF04C(out_vec, player_pos);
}

void func_80803A84_bsfirstp(PlayerState *player)
{
    s32 i;

    for (i = 0; i < 2; i++) {
        func_8009E4E0(player, i, _bsfirstp_entrypoint_13);
    }
    func_8009E4E0(player, 2, NULL);
    func_80803B58_bsfirstp(player, 0.0f);
}

int func_80803B04_bsfirstp(s32 player)
{
    s32 i;
    int player_alias;
    s32 player_copy;
    // Matching: `| 0` and the empty block are needed for the match.
    player_copy = player | 0;
    if (player_copy) {
    }
    player_alias = player_copy | 0;
    for (i = 0; i < 3; i++) {
        func_8009E4E0(player_alias, i | 0, 0);
    }
}

void func_80803B58_bsfirstp(u8 *player, f32 unk_0)
{
    s8 *state;
    state = (s8 *) (*((u8 **) (((s8 *) player) + 0x188)));
    *((f32 *) (state + 0x110)) = unk_0;
}

f32 func_80803B68_bsfirstp(player) void *player;
{
    f32 *state;

    state = *(f32 **) ((u8 *) player + 0x188);
    return state[0x44];
}

// Matching: the line breaks in this function are needed for the match.
void bsfirstp_entrypoint_14(PlayerState *player)
{
    s32 player_index = *(s32 *) ((u8 *) player + 0x184);
    s32 i;
    f32 own_pos[3];
    f32 own_radius;
    f32 own_radius_sq;
    f32 sphere_a_pos[3];
    f32 sphere_a_radius;
    f32 sphere_b_radius;
    f32 sphere_b_pos[3];
    f32 sphere_b_limit;
    PlayerState *other;

    func_8009E154(player, 0, own_pos);
    own_radius = func_8009E138(player, 0);
    for (i = 0; i < func_800F5898(); i++) {
        if (i != player_index) {
            other = func_800F53E4(i);

if (other != NULL) {
    own_radius_sq = own_radius * own_radius;
    func_8009E154(other, 2, sphere_a_pos);
    func_8009E154(other, 1, sphere_b_pos);
    sphere_a_radius = func_8009E138(other, 2);
    sphere_b_radius = func_8009E138(other, 1);
    sphere_b_limit = sphere_b_radius * sphere_b_radius + own_radius_sq;
    if (func_800EEB40(own_pos, sphere_a_pos) < sphere_a_radius * sphere_a_radius + own_radius_sq ||
        func_800EEB40(own_pos, sphere_b_pos) < sphere_b_limit)
        func_800F7C58(i, 0x6D, player_index);
}

}
}
}

s32 func_80803CD4_bsfirstp(PlayerState *player, s32 unk_0, s32 unk_1, s32 damage, f32 *direction)
{
    u8 *state;
    f32 rumble;
    int notify;
    s32 result;
    state = *(u8 **)((u8 *)player + 0x188);
    if (func_8009CA70(player, bs_getCurrentState(player), 4)) return 0;
    if (func_8009BD44(player) == 3) return 0;
    if (_gcstatusDll_entrypoint_20() == 1) {
        if (_gcstatusDll_entrypoint_14() == 5) {
            if (_gcstatusDll_entrypoint_15() == *(s32 *)((u8 *)player + 0x184)) {
                damage = 0; notify = 1; result = 1;
            } else if (damage) { notify = 1; result = 2; }

else
{
    notify = 0;
    result = 1;
}
}
else
{
    damage = 0;
    notify = 1;
    result = 1;
}
}
else
{
    func_800A17A8(player, -damage);

if (func_800A1718(player)) { notify = 0; result = 1; }

else
{
    notify = 1;
    result = 2;
}
}
if (notify)
    func_80101180(0x2C4, 0x70, (*(s32 *) ((u8 *) player + 0x184) << 4) | unk_1);
rumble = func_800F10B4(damage, 0.0f, 8.0f, 0.8f, 1.4f);
_bamotor_entrypoint_0(player, rumble, 0.25f);
*(s32 *) (state + 0xEC) = unk_0;
*(s32 *) (state + 0xF0) = unk_1;
*(s32 *) (state + 0xF4) = damage;
func_800EE7F8((f32 *) (state + 0xF8), direction);
return result;
}

// Matching: the line breaks in this function are needed for the match.
void func_80803E84_bsfirstp(u8 *player)
{
    u8 *state;
    s32 anim_ctrl;
    u8 *first_anim;
    u8 *second_anim;

    state = *(u8 **) (player + 0x188);
    anim_ctrl = baanim_getAnimCtrlPtr();
    func_80807BB8_bsfirstp(player);
    func_808026AC_bsfirstp(player, &first_anim, &second_anim);
    func_80800424_bsfirstp(player, *(s16 *) (first_anim + 0), *(f32 *) (first_anim + 4));
    baanim_playForDuration_onceSmooth(player, *(s16 *) (second_anim + 0), *(f32 *) (second_anim + 4));
    anctrl_setSubrange(anim_ctrl, 0.0f, 0.43f);
    if (func_80802A40_bsfirstp(player, 0xA) == 0) {
        func_8009D89C(player, 1.0f);

}
_bainvisible_entrypoint_7(player, 3, 1.0, 1.0, 0.5);
func_80808F38_bsfirstp(player);
*(s32 *) (state + 4) = 0;
func_8009BDAC(player, 1.25f);
}

void func_80803F6C_bsfirstp(s32 player)
{
    func_808090D8_bsfirstp();
    func_80807C8C_bsfirstp(player);
}
void func_80803F94_bsfirstp(PlayerState *player)
{
    u8 *state = *(u8 **) ((u8 *) player + 0x188);
    s32 next_state = 0;
    AnimCtrl *anim_ctrl;

    func_80807D48_bsfirstp(player);
    func_80804848_bsfirstp(player, *(s32 *) (state + 12));
    func_80801928_bsfirstp(player);
    func_80801DC0_bsfirstp(player);
    func_80808EF0_bsfirstp(player);
    func_80802F20_bsfirstp(player);
    func_80809198_bsfirstp(player);
    switch (*(s32 *) (state + 4)) {
        case 0:
            if (func_8008DF8C(player, 0x5A)) {
                anim_ctrl = baanim_getAnimCtrlPtr(player);
                anctrl_setSubrange(anim_ctrl, 0.0f, 1.0f);
                anctrl_setPlaybackType(anim_ctrl, 1);
                *(s32 *) (state + 4) = 1;
            }

break;

case 1:
    if (player_isStable(player)) {
        *(s32 *) (state + 4) = 2;
        func_800F7F98(*(s32 *) ((u8 *) player + 0x184), 0);
    }

break;
case 2:
    func_80809D24_bsfirstp(player);
    func_8080682C_bsfirstp(player);
    func_808099B4_bsfirstp(player);
    next_state = func_808094F4_bsfirstp(player);
    if (next_state == 0xCA && !baanim_isStopped(player))
        next_state = 0;

}
bs_setState(player, next_state);
}

int bsfirstp_entrypoint_15(s32 index)
{
    return D_8080B4D0_bsfirstp[index];
}

void func_80804104_bsfirstp(PlayerState *player, FirstPersonAnimationEvent *first_anim, FirstPersonAnimationEvent *second_anim)
{
    if (first_anim->local_0) func_80800424_bsfirstp(player, first_anim->local_0, first_anim->local_1);
    baanim_playForDuration_onceSmooth(player, second_anim->local_0, second_anim->local_1);
    func_800FC660(11);
    if (!func_80802A40_bsfirstp(player, 11)) func_8009D89C(player, 1.0f);
    _bainvisible_entrypoint_3(player);
    baphysics_set_target_horizontal_velocity(player, 0.0f);
    player->unk15C.word = 0;
    func_80808F38_bsfirstp(player);
    if (!func_800D3948()) _basudie_entrypoint_1(player);
    if (!func_800EA068(8)) func_800F7E64(player->unk184, 1);
}

int func_808041D0_bsfirstp(Actor *player)
{
    s32 first_anim;
    s32 second_anim;
    func_80807BB8_bsfirstp(player);
    func_80802700_bsfirstp(player, &first_anim, &second_anim);
    func_80804104_bsfirstp(player, first_anim, second_anim);
}

void func_80804210_bsfirstp(s32 player)
{
    func_808090D8_bsfirstp();
    func_80807C8C_bsfirstp(player);
}
void func_80804238_bsfirstp(void *player) {
    s32 phase;

    phase = ((s32 *) player)[87];
    switch (phase) {
        case 0:
        if (anctrl_isStopped(baanim_getAnimCtrlPtr(player)) != 0) {
            _batimer_set(player, 0, 3.0f);
            func_800A38F0(player, 0, 1);
            ((s32 *) player)[87] = 1;
        }

break;

case 1:
    if (_batimer_decrement(player, 0) != 0) {
        if (func_800D3948() != 0) {
            func_80101180(0x2C4, 0x71, ((s32 *) player)[0x61]);
        } else {
            _basudie_entrypoint_0(player);
        }
        ((s32 *) player)[87] = 2;
    }

break;

}
func_80809198_bsfirstp(player);
func_80807D48_bsfirstp(player);
func_80809250_bsfirstp(player);
}

int bsfirstp_entrypoint_16(s32 index)
{
    return D_8080B4E0_bsfirstp[index];
}

int func_8080432C_bsfirstp(Actor *player)
{
    s32 first_anim;
    s32 second_anim;
    func_80807BB8_bsfirstp();
    func_80802754_bsfirstp(player, &first_anim, &second_anim);
    func_80804104_bsfirstp(player, first_anim, second_anim);
}

void func_8080436C_bsfirstp(s32 player)
{
    func_808090D8_bsfirstp();
    func_80807C8C_bsfirstp(player);
}
// Matching: the line breaks in this function are needed for the match.
int func_80804394_bsfirstp(Actor *player)
{
    s32 phase;

    phase = ((s32 *) player)[87];
    switch (phase) {
        case 0:
            if (anctrl_isStopped(baanim_getAnimCtrlPtr(player)) != 0) {
                _batimer_set(player, 0, 3.0f);
                func_800A38F0(player, 0, 1);
                ((s32 *) player)[87] = 1;
            }

break;

case 1:
    if (_batimer_decrement(player, 0) != 0) {
        if (func_800D3948() != 0) {
            func_80101180(0x2C4, 0x71, ((s32 *) player)[0x61]);
        } else {
            _basudie_entrypoint_0(player);
        }
        ((s32 *) player)[87] = 2;
    }

}
func_80809198_bsfirstp(player);
func_80809250_bsfirstp(player);
func_80807D48_bsfirstp(player);
}

int bsfirstp_entrypoint_17(s32 index)
{
    return D_8080B4F0_bsfirstp[index];
}

// Eases a strafe axis toward -1, 0 or 1 depending on which keys are held.
void func_80804488_bsfirstp(player, key_neg, key_pos, axis) PlayerState *player;
s32 key_neg;
s32 key_pos;
f32 *axis;
{
    s32 held;
    f32 target;
    f32 step;

    held = bakey_held(player, key_neg) ? 1 : 0;
    held += bakey_held(player, key_pos) ? 2 : 0;
    switch (held) {
        case 0:
        case 3:
            target = 0.0f;
            break;
        case 1:
            target = -1.0f;
            break;
        case 2:
            target = 1.0f;
            break;
    }
    if (target == -axis[1])
        step = 0.667f;
    else if (target == 0.0f)
        step = 0.5f;
    else
        step = 0.333f;
    if (mlAbsF(target - axis[0]) < step) {
        axis[0] = target;
        axis[1] = target;

}
else if (axis[0] < target) axis[0] += step;
else axis[0] -= step;
}

void func_808045FC_bsfirstp(void *trend, f32 value)
{
    f32 unk_0;
    f32 unk_1;
    f32 unk_2;

    switch (((Mass46FirstPersonTrend *) trend)->local_3) {
        case -1:
            if (value < ((Mass46FirstPersonTrend *) trend)->local_0) {
                ((Mass46FirstPersonTrend *) trend)->local_5 = value;
            }

if (value == ((Mass46FirstPersonTrend *) trend)->local_0 && value == 0.0f) {
    ((Mass46FirstPersonTrend *) trend)->local_3 = 0;
}

if (value > ((Mass46FirstPersonTrend *) trend)->local_0 &&
    value > ((Mass46FirstPersonTrend *) trend)->local_4) {
    ((Mass46FirstPersonTrend *) trend)->local_6 = value;
    ((Mass46FirstPersonTrend *) trend)->local_3 = 1;
}

break;

case 0:
    if (value < 0.0f) {
        ((Mass46FirstPersonTrend *) trend)->local_3 = -1;
        ((Mass46FirstPersonTrend *) trend)->local_5 = value;
        ((Mass46FirstPersonTrend *) trend)->local_6 = 0.0f;
    } else if (value > 0.0f) {

((Mass46FirstPersonTrend *) trend)->local_3 = 1;
((Mass46FirstPersonTrend *) trend)->local_5 = 0.0f;
((Mass46FirstPersonTrend *) trend)->local_6 = value;
}
break;
case 1:
    if (value > ((Mass46FirstPersonTrend *) trend)->local_0) {
        ((Mass46FirstPersonTrend *) trend)->local_6 = value;
    }
    if (value == ((Mass46FirstPersonTrend *) trend)->local_0 && value == 0.0f) {
        ((Mass46FirstPersonTrend *) trend)->local_3 = 0;
    }
    if (value < ((Mass46FirstPersonTrend *) trend)->local_0 &&
        value < ((Mass46FirstPersonTrend *) trend)->local_4) {
        ((Mass46FirstPersonTrend *) trend)->local_5 = value;
        ((Mass46FirstPersonTrend *) trend)->local_3 = -1;
    }
    }
    ((Mass46FirstPersonTrend *) trend)->local_4 = ((Mass46FirstPersonTrend *) trend)->local_0;
    ((Mass46FirstPersonTrend *) trend)->local_0 = value;
    ((Mass46FirstPersonTrend *) trend)->local_2 = ((Mass46FirstPersonTrend *) trend)->local_6 -
                                                    ((Mass46FirstPersonTrend *) trend)->local_5;
    unk_0 = func_800F2108(value);
    unk_1 = value * unk_0 + 1.0f;
    unk_2 = unk_1 * unk_1;
    ((Mass46FirstPersonTrend *) trend)->local_1 = (unk_1 * unk_2 - 1.0f) * (unk_0 / 7.0f);
    }

    void func_808047EC_bsfirstp(Actor *player)
    {
        u8 *state_mem;

        state_mem = *(u8 **) ((char *) player + 0x188);
        bzero(state_mem + 0x12C, 0x38);
        bzero(state_mem + 0x164, 0x38);
        func_80804848_bsfirstp(player, *(s32 **) (state_mem + 0xC));
    }

    int func_8080483C_bsfirstp(Actor *player, s32 value)
    {
        s32 *state_mem = *(s32 **) ((char *) (player) + 0x188);
        *(s32 *) ((char *) (state_mem) + 0x118) = value;
    }

    void func_80804848_bsfirstp(player, mode) PlayerState *player;
    s32 mode;
    {
        u8 *state_mem;
        f32 unk_0;
        f32 unk_1;
        f32 unk_2;
        state_mem = *(u8 **) ((u8 *) player + 0x188);
        func_80804488_bsfirstp(player, 10, 13, state_mem + 0x11C);
        func_80804488_bsfirstp(player, 11, 12, state_mem + 0x124);
        switch (mode) {
            case -1:
                func_808045FC_bsfirstp(state_mem + 0x12C, 0.0f);
                func_808045FC_bsfirstp(state_mem + 0x148, 0.0f);
                func_808045FC_bsfirstp(state_mem + 0x164, 0.0f);
                func_808045FC_bsfirstp(state_mem + 0x180, 0.0f);
                break;
            case 0:
                if (*(s32 *) (state_mem + 0x118))
                    unk_0 = 0.0f;
                else
                    unk_0 = bastick_getY(player);
                if (*(s32 *) (state_mem + 0x118))
                    unk_1 = bastick_getY(player);
                else
                    unk_1 = *(f32 *) (state_mem + 0x124);
                func_808045FC_bsfirstp(state_mem + 0x12C, *(f32 *) (state_mem + 0x11C));
                func_808045FC_bsfirstp(state_mem + 0x148, unk_0);
                func_808045FC_bsfirstp(state_mem + 0x164, bastick_getX(player));
                func_808045FC_bsfirstp(state_mem + 0x180, unk_1);
                break;
            case 1:
                if (*(s32 *) (state_mem + 0x118))
                    unk_2 = 0.0f;
                else
                    unk_2 = *(f32 *) (state_mem + 0x124);
                func_808045FC_bsfirstp(state_mem + 0x12C, *(f32 *) (state_mem + 0x11C));
                func_808045FC_bsfirstp(state_mem + 0x148, unk_2);
                func_808045FC_bsfirstp(state_mem + 0x164, bastick_getX(player));
                func_808045FC_bsfirstp(state_mem + 0x180, bastick_getY(player));
        }
    }

    int bsfirstp_entrypoint_18(Actor *param_0, s32 param_1)
    {
        Actor *player;
        player = func_800F53D0(param_1);
        bs_setState(player, 0xC8);
        *(s32 *) ((char *) player + 0x15c) = 1;
    }

    void func_80804A34_bsfirstp(s32 arg0)
    {
    }
    void func_80804A3C_bsfirstp(u8 *player)
    {
        func_80101238(0x77, *(s32 **) (player + 0x184), player);
    }

// Matching: the line breaks in this function are needed for the match.
    void func_80804A64_bsfirstp(PlayerState *player)
    {
        s32 transition;

        transition = 1;
        if (func_8009E6EC(player) == 0x62) {
            if (!func_800A3404(player)) {
                func_80807EEC_bsfirstp(player);

if (bs_getCurrentState(player) == 0xC8) {
    func_80800888_bsfirstp(player, 1);
} else {

func_80800888_bsfirstp(player, 0);
}
transition = 2;
}
}
else
{
    bsfirstp_entrypoint_26(player);
    return;
}
func_8009E830(player, transition);
}

int func_80804B10_bsfirstp(s32 player)
{
    s32 player_copy;
    // Matching: the `| 0` copy is needed for the match.
    player_copy = player | 0;
    func_80807BB8_bsfirstp();
    // Matching: `^ 0` is needed for the match.
    func_800A3410(player_copy, 9 ^ 0);
    func_80807DD4_bsfirstp(player_copy);
    func_800936E8(player_copy, 0);
    baanim_playForDuration_onceSmooth((PlayerState *) player_copy, 0x30C, 2.0f);
    func_808003B4_bsfirstp(player_copy, 0x310, 2.0f);
    func_80804A34_bsfirstp(1);
    *(s32 *) ((char *) (player) + 0x15C) = 0;
}

void func_80804B84_bsfirstp(s32 player)
{
    func_80807C8C_bsfirstp(player);
}
void func_80804BA4_bsfirstp(PlayerState *player)
{
    func_80807D48_bsfirstp(player);
    func_80809D24_bsfirstp(player);
    if (!func_800A3404(player)) {
        if (baanim_isAt(player, 0.1081f))
            func_800936E8(player, 1);
        if (baanim_isAt(player, 0.25f))
            func_8009DE38(player, 0x442E, 1.117f);
        if (*(s32 *) ((u8 *) player + 0x15C) == 0 && baanim_isAt(player, 0.4f))
            func_80801A34_bsfirstp(player);
        if (baanim_isAt(player, 0.5f))
            func_8009DB04(player, 0x4639, 1.0f, 20000);
        if (baanim_isAt(player, 0.61f))
            func_8009DB04(player, 0x463A, 1.0f, 20000);
        if (*(s32 *) ((u8 *) player + 0x15C) == 1) {
            if (baanim_isStopped(player)) {
                func_80804A3C_bsfirstp(player);
                *(s32 *) ((u8 *) player + 0x15C) = 2;
            }
            func_80801928_bsfirstp(player);
        }
    } else {
        func_80801928_bsfirstp(player);
        if (!func_808008B0_bsfirstp(player)) {
            bs_setState(player, 0xCA);
            func_80804A3C_bsfirstp(player);
        }
    }
}

int bsfirstp_entrypoint_19(s32 index)
{
    return D_8080B500_bsfirstp[index];
}

s32 func_80804D18_bsfirstp(long player)
{
    s32 player_copy;
    func_80807BB8_bsfirstp();
    player_copy = player;
    func_80807DD4_bsfirstp(player_copy);
    baanim_playForDuration_loopStartingAt(player_copy, 0x30D, 0x40000000, 0.503600001f);
    func_808002CC_bsfirstp(player_copy, 0x311, 2.0f, 0.503600001f);
    // Matching: empty block steers IDO's register allocation.
    if (((!player_copy) && (!player_copy)) && (!player_copy)) {
    }
    func_80801A34_bsfirstp(player_copy);
}

void func_80804D80_bsfirstp(s32 player)
{
    func_80807C8C_bsfirstp(player);
}
int func_80804DA0_bsfirstp(Actor *player)
{
    Actor *player_copy = player;
    func_80807D48_bsfirstp(player_copy);
    func_80809D24_bsfirstp(player_copy);
    if (func_800A3404(player_copy)) {
        func_80801928_bsfirstp(player_copy);
        if (!func_808008B0_bsfirstp(player_copy)) {
            bs_setState(player_copy, 0xCA);
            func_80804A3C_bsfirstp(player_copy);
        }
    }
}

int bsfirstp_entrypoint_20(s32 index)
{
    return D_8080B510_bsfirstp[index];
}

s32 func_80804E1C_bsfirstp(s32 player)
{
    if (func_800A3404(player) || _glcutDll_entrypoint_1()) {
        func_80807BB8_bsfirstp(player);
        func_80807F5C_bsfirstp(player);
    } else {
        func_80807BB8_bsfirstp(player);
        func_80807DD4_bsfirstp(player);
        baanim_playForDuration_loopStartingAt(player, 0x30D, 0x40000000, 0.503600001f);
        func_808002CC_bsfirstp(player, 0x311, 2.0f, 0.503600001f);
    }
}

void func_80804EB4_bsfirstp(s32 player)
{
    func_80807C8C_bsfirstp(player);
}
int func_80804ED4_bsfirstp(Actor *player)
{
    s32 next_state;
    func_80807D48_bsfirstp(player);
    next_state = func_800EA068(8) ? 0xCB : 0xC9;
    bs_setState(player, next_state);
}

int bsfirstp_entrypoint_21(s32 index)
{
    return D_8080B520_bsfirstp[index];
}

void func_80804F28_bsfirstp(Actor *player)
{
    func_80807BB8_bsfirstp();
    baanim_playForDuration_onceSmoothStartingAt(player, 0x30C, 2.0f, 0x3EC00000);
    func_8008B188(baanim_getAnimCtrlPtr(player), 0);
    func_80800340_bsfirstp(player, 0x310, 2.0f, 0.375f);
    func_8008B188(func_8008D04C(player), 0);
    func_80804A34_bsfirstp(0);
    func_808061AC_bsfirstp(player, 0);
}

void func_80804FB4_bsfirstp(s32 player)
{
    func_80807C8C_bsfirstp(player);
}
void func_80804FD4_bsfirstp(void *player)
{
    s32 player_copy;

    player_copy = (s32) player;
    func_80807D48_bsfirstp(player_copy);
    if (baanim_isAt(player_copy, 0.3f) != 0) {
        func_8009DBF0(player_copy, 0x45A5, 0x3F800000);
    }
    if (baanim_isStopped(player_copy) != 0) {
        func_800A3410(player_copy, 1);
        bs_setState(player_copy, 1);
    }
}

int bsfirstp_entrypoint_22(s32 index)
{
    return D_8080B530_bsfirstp[index];
}

int func_80805058_bsfirstp(Actor *player)
{
    _bsdrone_entrypoint_0();
    func_80807BB8_bsfirstp(player);
    baanim_playForDuration_loopStartingAt(player, 0x30D, 0x40000000, 0.503600001f);
    func_808002CC_bsfirstp(player, 0x311, 2.0f, 0.503600001f);
}

void func_808050B0_bsfirstp(s32 player)
{
    _bsdrone_entrypoint_2();
    func_80807C8C_bsfirstp(player);
}
void func_808050D8_bsfirstp(s32 player)
{
    _bsdrone_entrypoint_1();
    func_80807D48_bsfirstp(player);
    func_80809D24_bsfirstp(player);
}

int bsfirstp_entrypoint_23(s32 index)
{
    return D_8080B540_bsfirstp[index];
}

s32 func_8080511C_bsfirstp(s32 player)
{
    _bsdrone_entrypoint_0(player);
    func_80807BB8_bsfirstp(player);
    if (func_800A3404(player) != 0) {
        func_80807F24_bsfirstp(player);
    }
    baanim_playForDuration_loop(player, 0x30E, 0x3FC00000);
    func_8008C990(player, 0x3F000000);
    func_80800488_bsfirstp(player, 0x312, 1.5f);
    func_80800264_bsfirstp(player, 0.5f);
}

void func_8080519C_bsfirstp(s32 player)
{
    _bsdrone_entrypoint_2();
    func_80807C8C_bsfirstp(player);
}
void func_808051C4_bsfirstp(s32 player)
{
    _bsdrone_entrypoint_1();
    func_80807D48_bsfirstp(player);
    func_80809D24_bsfirstp(player);
}

int bsfirstp_entrypoint_24(s32 index)
{
    return D_8080B550_bsfirstp[index];
}

void bsfirstp_entrypoint_25(void *player, f32 speed)
{
    s32 pad0;
    void *unk_0;
    f32 speed_ratio;
    // Matching: extra temporary for the constant.
    float one;
    speed_ratio = mlAbsF(speed) * 0.003333333414f;
    one = 1.0f;
    if (speed_ratio > one) {
        speed_ratio = one;
    }
    anctrl_setDuration(baanim_getAnimCtrlPtr(player), (speed_ratio * (0.75f - one)) + one);
    anctrl_setDuration(func_8008D04C(player), (speed_ratio * (0.75f - one)) + one);
}

s32 func_808052A4_bsfirstp(f32 *param_0, f32 *param_1)
{
    f32 half;
    half = (*param_0) / 2;
    *param_0 = (*param_1) + half;
    *param_1 = half;
}

// Moves *value toward target at rate for the given time; returns the distance covered.
f32 func_808052C8_bsfirstp(f32 *value, f32 target, f32 rate, f32 time)
{
    f32 prev;
    f32 step_time;
    f32 end_value;
    f32 integral;

    integral = 0.0f;
    if (time != 0.0f) {
        if (target != (*value)) {
            if (target < (*value))
                rate = -rate;
            step_time = (target - (*value)) / rate;
            if (step_time <= time)
                end_value = target;
            else {
                step_time = time;
                end_value = (*value) + rate * time;
            }
            prev = *value;
            *value = end_value;
            integral += ((prev + end_value) * 0.5f) * step_time;
            time -= step_time;
        }
        integral += *value * time;
    }
    return integral;
}

void func_80805380_bsfirstp(f32 *angle, f32 target, f32 max_speed, f32 gain)
{
    s32 steps;
    f32 delta;
    f32 speed;
    steps = func_800D8FEC();
    while (steps != 0) {
        delta = func_80013728(target - *angle);
        speed = delta * gain;
        if (speed != 0.0f) {
            if (speed < 0.0f)
                speed = func_800F0D50(speed, -max_speed, -3.0f);
            else
                speed = func_800F0D50(speed, 3.0f, max_speed);
        }
        *angle += func_800F212C(speed * (1.0f / 60.0f), delta);
        steps--;
    }
    *angle = func_80013728(*angle);
}

f32 func_8080549C_bsfirstp(f32 *pos, f32 vel, f32 dist, f32 *time, f32 dt)
{
    f32 t;
    f32 d;
    f32 u;
    f32 p;
    f32 a;
    f32 h;
    f32 scale;
    f32 b;
    f32 r;

    scale = dt * 0.6366198063f;
    t = *time / scale;
    if (0.0f < *pos) {
        d = dist;
    } else {
        d = -dist;
    }
    u = vel / d;
    p = *pos / d;
    if (u < 0) {
        u = 0;
    }
    a = func_80013AA0(1.0f - p);
    b = func_80013AA0(1.0f - u);
    if (t < b - a) {
        b = a + t;
    }
    t -= b - a;
    if (t < 9.999999975e-07f) {
        t = 0.0f;
    }
    r = (b + func_80013798(b)) - (func_800138BC(a) + a);
    if (r < 9.999999975e-07f) {
        r = 0.0f;
    }
    h = 1.0f - func_800137C4(r);
    if (h < u + 9.999999975e-07f) {
        h = u;
    }
    *time = scale * t;
    *pos = d * h;
    r = scale * d * r;
    return r;
}

f32 func_80805644_bsfirstp(f32 *pos, f32 vel, f32 dist, f32 *time, f32 dt)
{
    f32 scale;
    f32 t;
    f32 a;
    f32 b;
    f32 limit;
    f32 u;
    f32 result;
    f32 h;
    f32 r;

    scale = dt * 0.6366198063f;
    t = time[0] / scale;
    h = pos[0] / dist;
    a = func_80013A5C(1.0f - h);
    u = vel / dist;
    b = func_80013A5C(1.0f - u);
    h = b;
    if (t < (b - a)) {
        h = a + t;
    }
    t = t - (h - a);
    if (t < 9.999999975e-07f) {
        t = 0.0f;
    }
    r = (h - func_800137D4(h)) - (a - func_8001395C(a));
    if (r < 9.999999975e-07f) {
        r = 0.0f;
    }
    h = 1.0f - (func_80013788(r));
    limit = u - 9.999999975e-07f;
    if (limit < h) {
        h = u;
    }
    time[0] = scale * t;
    pos[0] = dist * h;
    result = (scale * dist) * r;
    return result;
}

f32 func_808057C8_bsfirstp(f32 *pos, f32 vel, f32 dist, f32 time, f32 dt)
{
    f32 result;
    f32 sign;
    f32 signed_pos;
    f32 unk_0;

    result = 0.0f;
    if (*pos * (vel - *pos) < 0.0f) {
        result = func_8080549C_bsfirstp(pos, vel, dist, &time, dt);
    }
    if (time != 0.0f) {
        if (vel >= 0.0f) {
            sign = 1.0f;
        } else {
            sign = -1.0f;
        }
        signed_pos = *pos * sign;
        if (signed_pos < vel * sign) {
            result += sign * func_80805644_bsfirstp(&signed_pos, vel * sign, dist,
                                                        &time, dt);
            *pos = sign * signed_pos;
        }
    }
    result += *pos * time;
    return result;
}

void func_808058F0_bsfirstp(PlayerState *player)
{
    s32 next_state;
    s32 state;
    s32 transition;
    next_state = 0;
    state = func_8009E6EC(player);
    transition = 1;
    if (state == 0x83) {
        transition = 2;
        next_state = 0xCA;
        func_8009BDAC(player, 1.5f);
        func_80807D70_bsfirstp(player);
        func_80801A5C_bsfirstp(player);
        func_8009337C(player, 0);
        func_800936E8(player, 1);
        func_80093370(player, 1);
    }
    func_8009E830(player, transition);
    bs_setState(player, next_state);
}

void bsfirstp_entrypoint_26(player) Actor *player;
{
    s32 next_state;
    s32 state;
    s32 transition;
    f32 local_vec[3];
    f32 speed;
    f32 egg_pos[3];
    s32 egg_value;
    s32 egg_mode;
    s32 egg_type;
    s32 primary_state;
    s32 secondary_state;
    f32 temp_vec[3];
    s32 value_6d;
    s32 value[3];
    s32 value_2;
    f32 temp_vec_2[3];
    f32 temp_vec_3[4];
    f32 temp_vec_4[6];
    f32 temp_vec_5[6];
    f32 temp_vec_6[8];
    s32 result;

    next_state = 0;
    state = func_8009E6EC(player);
    transition = 1;

    switch (state) {
        default:
            func_80099B94(player);
            return;

        case 0x99:
            func_808019EC_bsfirstp(player);
            break;

        case 0x4C:
            func_80099A7C(player, local_vec);
            _baduo_entrypoint_14(player, local_vec);

            next_state = 0xD7;
            transition = 2;
            break;

        case 0x4F:
            transition = 2;
            break;

        case 0x61:
            switch (func_80099A58(player)) {
                case 0:
                    next_state = 0xCC;
                    break;

                case 1:
                    func_800A3544(player, 0);
                    next_state = 0xC8;
                    break;

                case 2:
                    next_state = 0xC9;
            }

            func_800F7E64(*(s32 *) ((char *) player + 0x184), 9);

            transition = 2;
            break;

        case 0x73:
            func_80807EEC_bsfirstp(player);
            func_80801A5C_bsfirstp(player);
            transition = 2;
            break;

        case 0x62:
            if (func_800A3404(player) == 0) {
                func_80807EEC_bsfirstp(player);
                transition = 2;
            }
            break;

        case 0x63:
            if (func_800A3404(player) != 0) {
                func_80807F24_bsfirstp(player);
                transition = 2;
            }
            break;

        case 0x72:
            if (bs_getCurrentState(player) == 0xD2) {
                func_80808678_bsfirstp(player, func_80099A4C(player));
                transition = 2;
            }
            break;

        case 0x5F:
            speed = func_80099A34(player);
            func_80802BE8_bsfirstp(player, speed);

            transition = 2;
            break;

        case 0x47:
            egg_value = _suegg_entrypoint_6(func_80099A4C(player), egg_pos, &egg_type);

            egg_mode = _gcegg_entrypoint_7(egg_type);

            switch (egg_type) {
                case 6:
                    egg_mode = 0;
                case 4:
                case 5:
                    primary_state = 0xDA;
                    secondary_state = 0xDC;
                    break;
                default:
                    primary_state = 0xDA;
                    secondary_state = 0xDB;
                    break;

                case 3:
                    if (bs_getCurrentState(player) != 0xD9) {
                        primary_state = 0xD9;
                        secondary_state = 0;
                    } else {
                        func_80803760_bsfirstp(player);
                        primary_state = 0;
                        secondary_state = 0;
                    }
            }

            result = func_80803CD4_bsfirstp(player, state, egg_value, egg_mode, egg_pos);

            switch (result) {
                case 0:
                    break;
                case 2:
                    next_state = secondary_state;
                    transition = 2;
                    break;
                case 1:
                    next_state = primary_state;

                    if (egg_type == 6) {
                        _badeathmatch_entrypoint_5(player, 6, 1);
                        _sueggmisc_entrypoint_2(egg_pos, 6);
                    }

                    transition = 2;
            }
            break;

        case 0x6D:
            value_6d = func_80099A58(player);
            func_800F5A00(value_6d, temp_vec);

            result = func_80803CD4_bsfirstp(player, state, value_6d, 1, temp_vec);

            switch (result) {
                case 1:
                    next_state = 0xDA;
                    transition = 2;
                    break;
                case 2:
                    next_state = 0xDB;
                    transition = 2;
            }
            break;

        case 0x4E:
            value[0] = func_80099A70(player);
            value_2 = func_80099A58(player);
            func_80099A7C(player, temp_vec_2);

            result = func_80803CD4_bsfirstp(player, state, value[0], value_2, temp_vec_2);

            switch (result) {
                case 1:
                    next_state = 0xDA;
                    transition = 2;
                    break;
                case 2:
                    next_state = 0xDC;
                    transition = 2;
            }
            break;

        case 0x20:
            func_80099A7C(player, temp_vec_3);

            result = func_80803CD4_bsfirstp(player, state, -1, 1, temp_vec_3);

            switch (result) {
                case 1:
                    next_state = 0xDA;
                    transition = 2;
                    break;
                case 2:
                    next_state = 0xDB;
                    transition = 2;
            }
            break;

        case 0x51:
            func_8009C15C(player, temp_vec_4);

            result = func_80803CD4_bsfirstp(player, state, -1, 1, temp_vec_4);

            switch (result) {
                case 1:
                    next_state = 0xDA;
                    transition = 2;
                    break;
                case 2:
                    next_state = 0xDC;
                    transition = 2;
            }
            break;

        case 0x45:
            func_800EFD24(temp_vec_5);

            result = func_80803CD4_bsfirstp(player, state, -1, 8, temp_vec_5);

            if (result != 0) {
                next_state = 0xDB;
                transition = 2;
            }
            break;

        case 0x21:
        case 0x24:
            func_800EFD24(temp_vec_6);

            result = func_80803CD4_bsfirstp(player, state, -1, 1, temp_vec_6);

            switch (result) {
                case 1:
                    next_state = 0xDA;
                    transition = 2;
                    break;
                case 2:
                    next_state = 0xDB;
                    transition = 2;
            }
    }

    func_8009E830(player, transition);
    bs_setState(player, next_state);
}

void func_80805F48_bsfirstp(s32 player)
{
    func_808061AC_bsfirstp(player, 0);
}

void func_80805F68_bsfirstp()
{
    func_8009B4FC();
}

void bsfirstp_entrypoint_27(u8 *player)
{
    s32 mode;
    u8 *state_mem;
    state_mem = *((u8 **) (player + 0x188));
    mode = *((s32 *) (state_mem + 0x19C));
    switch (mode) {
        case 1:
            break;

        default:
            func_80806774_bsfirstp();
            break;

        case 2:
            func_8080649C_bsfirstp(player);
            break;

        case 3:
            func_80806588_bsfirstp(player);
    }

    // Matching: empty block with a redundant test is needed for the match.
    if (player && player) {
    }
    func_80806000_bsfirstp(player);
}

void func_80806000_bsfirstp(player) PlayerState *player;
{
    u8 *state_mem;
    u8 *scale_view;
    f32 *vec;
    f32 yaw_err;
    f32 length;
    f32 inv_denom;
    f32 denom;
    f32 abs_x;
    f32 unk_0;

    state_mem = *(u8 **) ((u8 *) player + 0x188);
    scale_view = (u8 *) func_80802458_bsfirstp(player);
    vec = (f32 *) (state_mem + 0x1B8);
    vec[0] = *(f32 *) (state_mem + 0x1D4);
    vec[1] = 0.0f;
    vec[2] = baphysics_get_target_horizontal_velocity(player);
    yaw_err = -func_80013728(func_8009BB18(player) - yaw_get(player));
    func_800EF934(vec, vec, yaw_err);
    length = func_800EEFFC(vec);
    denom = func_800F0E00(*(f32 *) (scale_view + 0x2C), length);
    inv_denom = 1.0f / denom;
    vec[0] *= inv_denom;
    vec[2] *= inv_denom;
    vec[3] = length * inv_denom;
    abs_x = mlAbsF(vec[0]);
    unk_0 = func_80013B7C(abs_x, mlAbsF(vec[2]));
    if (vec[0] < 0.0f) {
        vec[4] = unk_0;
    } else {
        vec[4] = -unk_0;
    }
}

f32 func_80806130_bsfirstp(void *player)
{
    f32 *state_mem;

    state_mem = *(f32 **) ((u8 *) player + 0x188);
    return state_mem[0x72];
}

f32 func_8080613C_bsfirstp(void *player)
{
    f32 *state_mem;

    state_mem = *(f32 **) ((u8 *) player + 0x188);
    return state_mem[0x71];
}

s32 func_80806148_bsfirstp(s32 player, s32 param_1)
{
    s32 state_mem = *(s32 *) (player + 0x188);
    func_800EE7F8(param_1, state_mem + 0x1b8);
}

f32 func_80806170_bsfirstp(void *player, f32 value)
{
    FirstPersonScaleView *config;

    config = (FirstPersonScaleView *) func_80802458_bsfirstp(player);
    value /= config->unk2C;
    return func_800F0DC0(value, 1.0f);
}

// Switches the movement mode (0-3) and applies its physics settings.
void func_808061AC_bsfirstp(player, mode) PlayerState *player;
s32 mode;
{
    u8 *state_mem;
    u8 *config;
    f32 unk_0;
    state_mem = *(u8 **) ((u8 *) player + 0x188);
    config = (u8 *) func_80802458_bsfirstp(player);
    switch (mode) {
        case 0:
            baphysics_set_gravity(player, *(f32 *) (config + 0x20));
            func_80806774_bsfirstp(player);
            baphysics_set_type(player, 0);
            break;
        case 1:
            baphysics_set_gravity(player, *(f32 *) (config + 0x20));
            baphysics_set_type(player, 0x10);
            baphysics_set_target_horizontal_velocity(player, 0);
            break;
        case 2:
            baphysics_set_gravity(player, *(f32 *) (config + 0x24));
            *(f32 *) (state_mem + 0x1D8) = 0.0f;
            *(f32 *) (state_mem + 0x1D4) = 0.0f;
            baphysics_set_type(player, 0x10);
            break;
        case 3:
            baphysics_set_gravity(player, *(f32 *) (config + 0x24));
            if (*(s32 *) (state_mem + 0x19C) != 3) {
                func_800F3BB0(player, state_mem + 0x1A0);
                func_800EE7F8(state_mem + 0x1AC, state_mem + 0x1A0);
                *(f32 *) (state_mem + 0x1DC) = 0.0f;
                unk_0 = func_8009BB5C(player);
                *(f32 *) (state_mem + 0x1E4) =
                    -func_800138D0(func_80013728(
                        (*(f32 *) (*(u8 **) ((u8 *) player + 0xC8) + 0x40) - yaw_get(player)) -
                        90.0f)) *
                    unk_0;
                *(f32 *) (state_mem + 0x1E0) = *(f32 *) (config + 0x44) * *(f32 *) (state_mem + 0x12C);
            }
            baphysics_set_type(player, 0x11);
    }
    *(s32 *) (state_mem + 0x19C) = mode;
}

void func_8080633C_bsfirstp(PlayerState *player, f32 scale)
{
    u8 *state_mem;
    u8 *config;
    FpStick *stick;
    f32 unk_0;
    f32 unk_1;
    f32 unk_2;
    f32 yaw;
    f32 velocity;

    state_mem = *(u8 **) ((u8 *) player + 0x188);
    config = (u8 *) func_80802458_bsfirstp(player);
    stick = (FpStick *) (state_mem + 0x12C);
    unk_1 = 1.0f - *(f32 *) (config + 0x30) * mlAbsF(func_80809938_bsfirstp(player));
    unk_2 = 1.0f - *(f32 *) (config + 0x40) * mlAbsF(func_80809938_bsfirstp(player));
    velocity = func_800F122C(*(f32 *) (state_mem + 0x148), *(f32 *) (config + 0x28),
                            *(f32 *) (config + 0x2C)) *
              (unk_1 * scale);
    yaw = yaw_get(player);
    baphysics_set_target_horizontal_velocity(player, velocity);
    baphysics_set_target_yaw(player, yaw);
    *(f32 *) (state_mem + 0x1CC) = *(f32 *) (config + 0x34) * stick->unk0;
    *(f32 *) (state_mem + 0x1CC) = *(f32 *) (state_mem + 0x1CC) * (unk_2 * scale);
    if (stick->unkC) {
        *(f32 *) (state_mem + 0x1D0) =
            *(f32 *) (config + 0x38) * ((1.0f < stick->unk8) ? stick->unk8 : 1.0f);
    } else {
        *(f32 *) (state_mem + 0x1D0) = *(f32 *) (config + 0x3C);
    }
}

void func_8080649C_bsfirstp(player) PlayerState *player;
{
    FirstPersonMovementData *data;
    FirstPersonMovementStep *step;
    f32 unk_0;
    f32 unk_1;
    f32 step_dt;
    f32 extra_dt;
    f32 yaw;
    f32 offset[3];
    f32 pos[3];

    data = (FirstPersonMovementData *) player->kazfly;
    step = &data->local_0;
    step_dt = 1.0f / 30.0f;
    extra_dt = func_800D9004() - step_dt;
    unk_0 =
        func_808052C8_bsfirstp(&step->local_2, step->local_0, step->local_1, step_dt);
    unk_1 =
        func_808052C8_bsfirstp(&step->local_2, step->local_0, step->local_1, extra_dt);
    func_808052A4_bsfirstp(&unk_1, &step->local_3);
    yaw = yaw_get(player) - 90.0f;
    func_800EFCD8(offset, yaw, unk_0 + unk_1);
    offset[1] = 0.0f;
    func_8009BC08(player, pos);
    func_800EF04C(pos, offset);
    func_8009B98C(player, pos);
}

void func_80806588_bsfirstp(player) PlayerState *player;
{
    u8 *state_mem;
    u8 *config;
    f32 yaw;
    f32 speed;
    f32 dt;
    f32 *pos;
    f32 *velocity;
    f32 *delta;
    f32 *orbit;
    FpSpring *spring;
    f32 unk_0;
    f32 unk_1;
    f32 swing;

    state_mem = *(u8 **) ((u8 *) player + 0x188);
    orbit = &F(state_mem, 0x1AC);
    spring = (FpSpring *) (state_mem + 0x1DC);
    config = func_80802458_bsfirstp(player);
    dt = func_800D9004();
    pos = (f32 *) (*(u8 **) ((u8 *) player + 0xC8) + 4);
    delta = (f32 *) (*(u8 **) ((u8 *) player + 0xC8) + 0x28);
    velocity = (f32 *) (*(u8 **) ((u8 *) player + 0xC8) + 0x10);
    func_800EF04C(&F(state_mem, 0x1A0), pos);
    func_800EF3DC(&F(state_mem, 0x1A0), orbit);
    spring->unk4 = F(config, 0x44) * F(state_mem, 0x12C);
    spring->unk0 += func_800FF060(spring->unk4 - spring->unk0, spring->unk8, F(config, 0x4C),
                                   F(config, 0x50), F(config, 0x48), dt);
    swing = spring->unk0;
    yaw = yaw_get(player);
    speed = (6.283185f * swing);
    speed *= (F(state_mem, 0x24C) * 0.0027777778f);
    unk_0 = func_800137AC(yaw);
    unk_1 = func_800137C4_noarg();
    F(state_mem, 0x1AC) = F(state_mem, 0x1A0) - swing * unk_0;
    F(state_mem, 0x1B0) = pos[1];
    F(state_mem, 0x1B4) = F(state_mem, 0x1A8) + swing * unk_1;
    func_800EFB24(delta, orbit, pos);
    func_800EE7F8(pos, orbit);
    func_800EFA20(velocity, delta, 1.0f / dt);
    if (30.0f < mlAbsF(spring->unk8[0])) {
        speed = func_800EEFFC(velocity);
        yaw = func_80013B70(velocity[0], velocity[2], speed);
    }
    baphysics_set_target_horizontal_velocity(player, speed);
    baphysics_set_target_yaw(player, yaw);
}

void func_80806774_bsfirstp(player) Actor *player;
{
    void *state_mem;

    state_mem = *((void **) ((char *) player + 0x188));
    func_8009B7C0();
    *((f32 *) ((char *) state_mem + 0x1D8)) = 0.0f;
    *((f32 *) ((char *) state_mem + 0x1CC)) = 0.0f;
    *((f32 *) ((char *) state_mem + 0x1D4)) = 0.0f;
}

void func_808067B0_bsfirstp(u8 *player)
{
    u8 *state_mem = *(u8 **) (player + 0x188);
    *(f32 *) (state_mem + 0x20C) = func_80809D94_bsfirstp(player);
    *(f32 *) (state_mem + 0x210) = 0.0f;
    *(f32 *) (state_mem + 0x214) = 0.0f;
}

void func_808067E8_bsfirstp(u8 *player)
{
    s32 state_mem;
    // Matching: empty block steers IDO's register allocation.
    if (player) {
    }
    state_mem = *((s32 *) (((s8 *) player) + 0x188));
    bcopy(func_80802458_bsfirstp() + 0x54, state_mem + 0x1E8, 0x20);
    func_808067B0_bsfirstp(player);
}

void func_8080682C_bsfirstp(player) PlayerState *player;
{
    FirstPersonPitchBounds *bounds;
    f32 pitch_delta;
    f32 min_pitch;
    f32 max_pitch;

    bounds = (FirstPersonPitchBounds *) player->kazfly;
    switch (bounds->local_0) {
        case 0:
            pitch_delta = func_808068E8_bsfirstp(player);
            break;
        case 1:
            pitch_delta = func_80806928_bsfirstp(player);
            break;
    }
    bounds->local_3 = func_80013728(bounds->local_3 + pitch_delta);
    min_pitch = func_80809D94_bsfirstp(player);
    min_pitch = bounds->local_2 + min_pitch;
    max_pitch = bounds->local_1;
    if (bounds->local_3 < min_pitch)
        bounds->local_3 = min_pitch;
    if (max_pitch < bounds->local_3)
        bounds->local_3 = max_pitch;
}

f32 func_808068E8_bsfirstp(player)
Actor *player;
{
    if (func_80809D6C_bsfirstp(player)) {
        return func_808069BC_bsfirstp(player);
    }
    // Matching: the nested empty block is needed for the match.
    {
        {
        }
        return func_808069FC_bsfirstp(player);
    }
}

f32 func_80806928_bsfirstp(player)
PlayerState *player;
{
    FirstPersonAim1517 *aim;
    f32 target_pitch;

    aim = (FirstPersonAim1517 *) player->kazfly;
    if (-aim->local_1 < 0.0f)
        target_pitch = aim->local_2 * -aim->local_1;
    else
        target_pitch = -aim->local_3 * -aim->local_1;
    if (aim->local_0)
        target_pitch += func_80809D94_bsfirstp(player);
    aim->local_4 = target_pitch;
    return func_80013728(target_pitch - aim->local_5) / 12.0f;
}

f32 func_808069BC_bsfirstp(player)
u8 *player;
{
    u8 *state_mem = *(u8 **) (player + 0x188);
    f32 pitch = func_80809D94_bsfirstp(player);
    *(f32 *) (state_mem + 0x208) = pitch;
    return func_80013728(pitch - *(f32 *) (state_mem + 0x20C)) / 6.0f;
}

f32 func_808069FC_bsfirstp(player)
u8 *player;
{
    u8 *state_mem;
    f32 unk_0;
    f32 unk_1;
    f32 *stick;

    state_mem = *((u8 **) (player + 0x188));
    if (*((s32 *) (state_mem + 0xA8)) == 0) {
        stick = (f32 *) (state_mem + 0x180);
        unk_1 = func_800F122C(-stick[0], 0.0f, *((f32 *) (state_mem + 0x1F0)));
        if (((s32 *) stick)[3] != 0) {
            unk_0 = *((f32 *) (state_mem + 0x1F8)) / (1.0f + ((FS_8 *) (stick))->v);
        } else {
            unk_0 = *((f32 *) (state_mem + 0x200));
        }
    } else {
        unk_1 = func_800F122C(-*((f32 *) (state_mem + 0xC4)), 0.0f, *((f32 *) (state_mem + 0x1F4)));
        if (*((f32 *) (state_mem + 0xC4)) != 0.0f) {
            unk_0 = *((f32 *) (state_mem + 0x1FC));
        } else {
            unk_0 = *((f32 *) (state_mem + 0x204));
        }
    }
    func_80806AD0_bsfirstp(player, unk_1, unk_0);
}

f32 func_80806AD0_bsfirstp(PlayerState *player, f32 unk_0, f32 unk_1)
{
    FirstPersonIntegrator1517 *data;
    f32 *step_state;
    f32 dt;
    f32 extra_dt;
    f32 step;
    f32 extra_step;

    data = (FirstPersonIntegrator1517 *) player->kazfly;
    dt = func_800D9004();
    extra_dt = dt - 0.03333333507f;
    step_state = &data->local_1;
    step = func_808057C8_bsfirstp(step_state, unk_0, data->local_0, 0.03333333507f, unk_1);
    if (extra_dt != 0.0f)
        extra_step = func_808057C8_bsfirstp(step_state, unk_0, data->local_0, extra_dt, unk_1);
    else
        extra_step = 0.0f;
    func_808052A4_bsfirstp(&extra_step, &data->local_2);
    return step + extra_step;
}

void bsfirstp_entrypoint_28(u8 *player, u8 *other)
{
    // Matching: the extra temporaries are needed for the match.
    s32 *unk_0;
    u8 *state_mem;
    u8 *other_mem;
    s32 *unk_1;
    unk_1 = (s32 *) (((u8 *) player) + 0x184);
    state_mem = *((u8 **) (((u8 *) player) + 0x188));
    other_mem = *((u8 **) (((u8 *) other) + 0x188));
    *((s32 *) (0x64 + state_mem)) = *((s32 *) (((u8 *) other) + 0x184));
    unk_0 = unk_1;
    *((s32 *) (other_mem + 0x68)) = *unk_0;
}

void func_80806BA0_bsfirstp(PlayerState *player)
{
    FirstPersonMode *state;
    state = (FirstPersonMode *) player->kazfly;
    switch (func_80809540_bsfirstp(player, state->local_0)) {
        default:
        case 0:
            if (state->local_0) {
                func_80808D80_bsfirstp(player);
                state->local_0 = 0;
            }
            return;
        case 1:
            if (state->local_0 != 1)
                func_80809684_bsfirstp(player, 1);
            break;
        case 2:
            if (state->local_0 != 2)
                func_80809684_bsfirstp(player, 2);
    }
    func_80809740_bsfirstp(player);
}

s32 func_80806C58_bsfirstp(s32 player)
{
    func_80807BB8_bsfirstp(player);
    func_800936E8(player, 0);
    func_8009337C(player, 1);
    func_8009B7C0(player);
    func_80801B64_bsfirstp(player, 2);
    func_808061AC_bsfirstp(player, 0);
    func_800A16BC(1);
}

void func_80806CC0_bsfirstp(PlayerState *player)
{
    FirstPersonExitState *state;
    state = (FirstPersonExitState *) player->kazfly;
    if (state->handle >= 0) {
        func_800F7B9C(state->handle, 0x4F);
        state->handle = -1;
    }
    func_8080175C_bsfirstp(player);
    func_800936E8(player, 1);
    func_8009337C(player, 0);
    func_80801B64_bsfirstp(player, 3);
    state->state = -1;
    func_80808DB0_bsfirstp(player);
    func_80807C8C_bsfirstp(player);
    func_800A16BC(0);
    _bababykaz_entrypoint_9(player);
}

void func_80806D64_bsfirstp(s32 player)
{
    func_8080633C_bsfirstp(player, 1.0f);
    func_80801928_bsfirstp(player);
}

void func_80806D90_bsfirstp(PlayerState *player)
{
    u8 *state_mem;

    state_mem = *(u8 **) ((u8 *) player + 0x188);
    if (func_8009E6EC(player) == 0x4F) {
        *(s32 *) (state_mem + 0x64) = -1;
        bs_setState(player, 0xCA);
        func_8009E830(player, 2);
    } else {
        bsfirstp_entrypoint_26(player);
    }
}

int bsfirstp_entrypoint_29(s32 index)
{
    return D_8080B560_bsfirstp[index];
}

void func_80806E0C_bsfirstp(u8 *player)
{
    u8 *state_mem;
    func_80807BB8_bsfirstp();
    state_mem = *((u8 **) (((char *) player) + 0x188));
    func_800A34E4(player, 0);
    func_800A34A0(player, 0);
    *((s32 *) state_mem) = 0;
    *((s32 *) (((char *) state_mem) + 4)) = 0;
    func_800936CC(player, 3);
    func_808061AC_bsfirstp(player, 1);
    // Matching: the comma expression and "- -" offset are needed for the match.
    *((s8 *) (((char *) state_mem) - -0x218)) = (0, 0xFF);
    func_80806BA0_bsfirstp(player);
    _bsbabykaz_entrypoint_4(player);
    func_80801A34_bsfirstp(player);
}

void func_80806E9C_bsfirstp(s32 player)
{
    _bsbabykaz_entrypoint_3();
    func_80807C8C_bsfirstp(player);
}
void func_80806EC4_bsfirstp(PlayerState *player)
{
    u8 *state_mem = *(u8 **) ((u8 *) player + 0x188);
    s32 handle;

    _bsbabykaz_entrypoint_5(player);
    func_8080800C_bsfirstp(player);
    if (func_800D3948()) {
        handle = *(s32 *) (state_mem + 0x68);
        func_80101180(0x2C4, 0x75, (_bababykaz_entrypoint_12(player) << 16) | (handle & 0xFFFF));
    }
    if (_bababykaz_entrypoint_3(player)) {
        bs_setState(player, 0xA1);
        return;
    }
    switch (*(s32 *) (state_mem + 4)) {
        case 0:
            if (func_80801A98_bsfirstp(player)) {
                func_800936E8(player, 1);
                func_8009337C(player, 1);
                func_80808DB0_bsfirstp(player);
                (*(s32 *) (state_mem + 4))++;
            }
            break;
        case 1:
            func_80804848_bsfirstp(player, *(void **) (state_mem + 12));
            func_80801DC0_bsfirstp(player);
            func_80809D24_bsfirstp(player);
            func_8080682C_bsfirstp(player);
            func_808099B4_bsfirstp(player);
            func_8080633C_bsfirstp(player, 1.0f);
            func_80808EF0_bsfirstp(player);
            if (bakey_pressed(player, 9))
                _bsbabykaz_entrypoint_13(player);
    }
    func_80801928_bsfirstp(player);
    func_80806BA0_bsfirstp(player);
}

void func_80807024_bsfirstp(PlayerState *player)
{
    s32 unk_0;
    s32 unk_1;
    void *unk_2;
    s32 unk_3;
    u8 *state_mem;
    u8 *mem_alt;
    void *unk_4;

    switch (func_8009E6EC(player)) {
        case 0x1F:
        case 0x21:
        case 0x24:
        case 0x47:
        case 0x4E:
            _bsbabykaz_entrypoint_13(player);
            func_8009E830(player, 2);
            break;
        case 0x4F:
            _bsbabykaz_entrypoint_13(player);
            func_8009E830(player, 2);
            _batimer_set(player, 0, 0.0f);
            break;
        case 0x8E:
            player->unk160.word = 0;
            bs_setState(player, 0xA1);
            func_8009E830(player, 2);
            _batimer_set(player, 0, 0);
            break;
        case 0x7D:
            if (*(s32 *) ((u8 *) player + 0x158)) {
                state_mem = (u8 *) player->kazfly;
                unk_2 = func_800F53D0(*(s32 *) (state_mem + 0x68));
                unk_0 = func_80099A58(player);
                unk_3 = _badeathmatch_entrypoint_4(unk_0);
                unk_1 = func_80099A64(player);
                _badeathmatch_entrypoint_5(unk_2, unk_3, unk_1);
            } else {
                func_80099B94(player);
            }
            break;
        case 0x5F:
            if (*(s32 *) ((u8 *) player + 0x158)) {
                mem_alt = (u8 *) player->kazfly;
                unk_4 = func_800F53D0(*(s32 *) (mem_alt + 0x68));
                func_80802BE8_bsfirstp(unk_4, func_80099A34(player));
            }
            break;
        default:
            func_80099B94(player);
    }
}

int bsfirstp_entrypoint_30(s32 index)
{
    return D_8080B570_bsfirstp[index];
}

void func_808071D8_bsfirstp(s32 player)
{
    func_80091E6C();
    _bsbabykaz_entrypoint_3(player);
    func_80807C8C_bsfirstp(player);
}

int func_80807208_bsfirstp(s32 player)
{
    s32 player_copy;
    // Matching: the "| 0" copy is needed for the match.
    player_copy = player | 0;
    func_80807BB8_bsfirstp(player_copy);
    _bsbabykaz_entrypoint_4(player_copy);
    _bsbabykaz_entrypoint_0(player_copy);
    _bababykaz_entrypoint_9(player_copy);
    func_80091E48(player_copy, 0x20);
    _batimer_set(player_copy, 0, 0.5f);
}

void func_80807264_bsfirstp(Actor *player)
{
    s32 value;
    _batimer_decrement(player, 0);
    value = _batimer_isZero(player, 0);
    if (!(value == 0)) {
        value = _bababykaz_entrypoint_4(player);
        func_800F9AAC(*(s32 **) ((char *) player + 0x184), value);
    }
}

int bsfirstp_entrypoint_31(s32 index)
{
    return D_8080B580_bsfirstp[index];
}

int func_808072C8_bsfirstp(Actor *player)
{
    s32 flag;
    flag = func_800A3404();
    if (flag != 0 && func_800DB9B0() != 0) {
        flag = 0;
    } else {
        flag = 1;
    }
    func_8009337C(player, 1);
    func_800936E8(player, flag);
}

s32 func_80807328_bsfirstp(s32 player)
{
    func_80807D48_bsfirstp(player);
    func_80804848_bsfirstp(player, -1);
    func_80801928_bsfirstp(player);
    func_80801DC0_bsfirstp(player);
    func_80808DB0_bsfirstp(player);
    func_80809D24_bsfirstp(player);
    func_8080682C_bsfirstp(player);
    func_808099B4_bsfirstp(player);
    func_80800830_bsfirstp(player);
}

void func_80807394_bsfirstp(Actor *player)
{
    s32 state;
    s32 unk_0;

    unk_0 = 1;
    state = func_8009E6EC(player);
    switch (state) {
        case 0x62:
            if (func_800A3404(player) == 0) {
                func_80807EEC_bsfirstp(player);
                unk_0 = 2;
            }
            goto block_14;
        case 0x64:
            if ((func_800A3404(player) != 0) && (func_800D3948() == 0)) {
                func_80807F24_bsfirstp(player);
                baanim_playForDuration_loop(player, 0x30D, 0x40000000);
                func_80800488_bsfirstp(player, 0x311, 2.0f);
                unk_0 = 2;
            }
            if (_ncpoddialog_entrypoint_10(func_80099A58(player)) != 0) {
                *(s32 *) ((char *) player + 0x15C) = 1;
                unk_0 = 2;
            }
            goto block_14;
        case 0x63:
            if (func_800A3404(player) != 0) {
                func_80807F24_bsfirstp(player);
                unk_0 = 2;
            }
            goto block_14;
        default:
            bsfirstp_entrypoint_26(player);
            return;
    }
block_14:
    func_8009E830(player, unk_0);
    bs_setState(player, 0);
}

int func_808074D0_bsfirstp(Actor *player)
{
    func_800936E8(player, 1);
    _bsrest_entrypoint_14(player);
    func_80807C8C_bsfirstp(player);
}

void func_80807504_bsfirstp(u8 *player)
{
    s32 mode;
    if (func_800A3404() != 0) {
        if (func_800DB9B0() != 0) {
            *((s32 *) (((s8 *) player) + 0x15C)) = 2;
        } else {
            *((s32 *) (((s8 *) player) + 0x15C)) = 0;
        }
    } else if (bs_getPreviousState(player) == 0xC8) {
        *((s32 *) (((s8 *) player) + 0x15C)) = 3;
    } else {
        *((s32 *) (((s8 *) player) + 0x15C)) = 1;
    }
    func_808061AC_bsfirstp(player, 0);
    mode = *((s32 *) (((s8 *) player) + 0x15C));
    switch (mode) {
        case 2:
            _bsrest_entrypoint_16(player);
            func_80807BB8_bsfirstp(player);
            baanim_playForDuration_loop(player, 0x272, 0x40000000);
            func_800936E8(player, 0);
            func_8009337C(player, 1);
            return;

        case 0:
            _bsrest_entrypoint_16(player);
            func_80807BB8_bsfirstp(player);
            baanim_playForDuration_loop(player, 0x272, 0x40000000);
            return;

        case 1:
            _bsrest_entrypoint_16(player);
            func_80807BB8_bsfirstp(player);

        case 3:
            return;
    }
}

void func_8080762C_bsfirstp(u8 *player)
{
    switch (*((u32 *) (((s8 *) player) + 0x15C))) {
        case 0:

        case 2:
            func_808072C8_bsfirstp(player);
            func_80807328_bsfirstp(player);
            if (_bsrest_entrypoint_20(player) != 0) {
                func_80807F5C_bsfirstp(player);
            }

            return;

        case 1:
            func_80807328_bsfirstp(player);
            if (_bsrest_entrypoint_20(player) != 0) {
                func_80807F5C_bsfirstp(player);
            }
            break;

        case 3:
            if (baanim_isAt(player, 0.1081f) != 0) {
                func_800936E8(player, 1);
            }
            if (baanim_isStopped(player) != 0) {
                baanim_playForDuration_loopStartingAt(player, 0x30D, 0x40000000, 0.503600001f);
                func_808002CC_bsfirstp(player, 0x311, 2.0f, 0.503600001f);
                func_8008B1C8(baanim_getAnimCtrlPtr(player), 0.75f);
                func_8008B1C8(func_8008D04C(player), 0.75f);
                _bsrest_entrypoint_16(player);
                *((u32 *) (((s8 *) player) + 0x15C)) = 4U;
            }
            func_80807328_bsfirstp(player);
            return;

        case 4:
            func_80807328_bsfirstp(player);
            if (_bsrest_entrypoint_20(player) != 0) {
                func_80807EEC_bsfirstp(player);
                func_80807F5C_bsfirstp(player);
            }
    }
}

int bsfirstp_entrypoint_32(s32 index)
{
    return D_8080B590_bsfirstp[index];
}

int func_808077AC_bsfirstp(Actor *player)
{
    func_80801B64_bsfirstp(player, 3);
    _bsrest_entrypoint_14(player);
    func_80807C8C_bsfirstp(player);
}

s32 func_808077E0_bsfirstp(s32 player)
{
    func_80801B64_bsfirstp(player, 2);
    func_80807BB8_bsfirstp(player);
    _bsrest_entrypoint_16(player);
    if (func_800A3404(player) != 0) {
        baanim_playForDuration_loopSmooth(player, 0x272, 0x40000000);
    } else {
        baanim_playForDuration_loop(player, 0x30D, 0x40000000);
        func_80800488_bsfirstp(player, 0x311, 2.0f);
    }
    *(s32 *) (player + 0x15c) = 0;
}

void func_80807864_bsfirstp(Actor *player)
{
    s32 mode;

    if (func_8009CC68() == 0) {
        *(s32 *) ((char *) player + 0x15C) = 1;
    }
    mode = *(s32 *) ((char *) player + 0x15C);
    switch (mode) {
        case 0:
            _bsrest_entrypoint_20(player);
            yaw_update(player);
            func_80807328_bsfirstp(player);
            return;
        case 1:
            func_80807F5C_bsfirstp(player);
    }
}

int bsfirstp_entrypoint_33(s32 index)
{
    return D_8080B5A0_bsfirstp[index];
}

void func_808078F4_bsfirstp(PlayerState *player)
{
    u8 *config;
    u8 *unk_0;
    s16 unk_1[2];
    s16 unk_2[2];
    s16 unk_3;
    f32 unk_4;
    unk_0 = (u8 *) func_80802484_bsfirstp(player);
    config = (u8 *) func_80802458_bsfirstp(player);
    if (!func_800D3948()) {
        if (func_8009EA2C()) {
            unk_1[0] = 0x726;
            unk_1[1] = 0x725;
            unk_2[0] = 0;
            unk_2[1] = 0;
        } else {
            func_80802AA8_bsfirstp(player, 0, unk_1, unk_2);
        }
    } else {
        unk_3 = func_800A940C(*(s32 *) ((u8 *) player + 0x184));
        func_80802AA8_bsfirstp(player, unk_3, unk_1, unk_2);
    }
    if (func_800D3948()) {
        unk_4 = *(f32 *) (unk_0 + 0x44);
    } else {
        unk_4 = 1.0f;
    }
    func_80092EC8(player, unk_1[0]);
    if (unk_2[0])
        func_8009312C(player, unk_2[0]);
    func_80093230(player, unk_4);
    func_8008CF7C(player);
    func_800936CC(player, 2);
    func_8009359C(player, unk_1[1]);
    if (unk_2[1])
        func_8009316C(player, unk_2[1]);
    func_800936D8(player, *(s32 *) (unk_0 + 0xC));
    func_8009E55C(player, 0, *(f32 *) config);
    func_8009E55C(player, 1, *(f32 *) (config + 4));
}

void func_80807A70_bsfirstp(PlayerState *player)
{
    s32 *state = (s32 *) player->kazfly;
    if (state[0] != -1) {
        func_800936CC(player, 0);
        func_8009359C(player, 0);
        func_80093230(player, 1.0f);
        func_8008CFF0(player);
        func_80093370(player, 1);
        func_8009337C(player, 1);
        state[0] = -1;
    }
}

void func_80807AF8_bsfirstp(PlayerState *player)
{
    FirstPersonInit1493 *state;
    s32 unk_0;

    state = (FirstPersonInit1493 *) player->kazfly;
    unk_0 = 1;
    if (func_800D3948()) {
        if (func_800EA068(0x4000))
            unk_0 = _gcstatusDll_entrypoint_13(player->unk184);
        else
            _gcstatusDll_entrypoint_3(player->unk184, 1);
    }
    func_800A34A0(player, unk_0);
    state->local_0 = unk_0;
    state->local_2 = -1;
    state->local_3 = -1;
    state->local_1 = -1;
    func_8009B7C0(player);
    func_8009FFD8(player, 1, 0, 0, 0x10);
    bainput_enable(player, 3, 0);
}

// Sets up the first-person state block (0x2A8 bytes at PlayerState+0x188).
void func_80807BB8_bsfirstp(player) PlayerState *player;
{
    s32 *state_mem;

    if (!func_8009E77C(player, 5)) {
        state_mem = (s32 *) func_80800000_bsfirstp((u8 *) player);
        func_80807AF8_bsfirstp(player);
        func_800947EC(player, 8, 1);
        state_mem[3] = 0;
        state_mem[4] = 1;
        func_80801AC4_bsfirstp(player);
        func_80805F48_bsfirstp(player);
        func_80809CD8_bsfirstp(player);
        func_808067E8_bsfirstp(player);
        func_8080995C_bsfirstp(player);
        func_80803A84_bsfirstp(player);
        func_808047EC_bsfirstp(player);
        func_80802BD8_bsfirstp(player);
        func_80802F00_bsfirstp(player);
        func_80809C90_bsfirstp(player);
        _bafpctrl_entrypoint_14(player, 1);
        func_80800190_bsfirstp(player);
        func_80807F9C_bsfirstp(player);
    }
}

// Tears down what func_80807BB8_bsfirstp sets up.
void func_80807C8C_bsfirstp(player) void *player;
{
    void *state_mem;
    s32 handle;

    state_mem = *(void **) ((char *) player + 0x188);
    if (func_8009E74C(player, 5) == 0) {
        handle = *(s32 *) ((char *) state_mem + 0x68);
        if (handle >= 0) {
            func_800F7B9C(handle, 0x4F);
            *(s32 *) ((char *) state_mem + 0x68) = -1;
        }
        func_80807A70_bsfirstp(player);
        func_80801AEC_bsfirstp(player);
        func_80805F68_bsfirstp(player);
        bainput_enable(player, 3, 1);
        func_800947EC(player, 8, 0);
        func_80809CB4_bsfirstp(player);
        func_80803B04_bsfirstp(player);
        func_808018E0_bsfirstp(player);
        func_80808084_bsfirstp(player);
        func_80800040_bsfirstp(player);
    }
}

void func_80807D48_bsfirstp(s32 player)
{
    func_80802BE0_bsfirstp(player);
    func_8080800C_bsfirstp(player);
}
int func_80807D70_bsfirstp(player)
s32 player;
{
    s32 player_copy;
    // Matching: the "| 0" copy is needed for the match.
    player_copy = player | 0;
    func_808001D0_bsfirstp(player_copy);
    func_80809DA0_bsfirstp(player_copy, 1);
    func_808067B0_bsfirstp(player_copy);
    func_80801B64_bsfirstp(player_copy, 1);
    func_80802ED4_bsfirstp(player_copy);
    func_800A34E4(player_copy, 0);
    func_8009BD50(player_copy);
}

void func_80807DD4_bsfirstp(player) s32 player;
{
    s16 unk_0;
    s16 unk_1;
    s16 unk_2;
    s16 unk_3;

    if (func_800A3404() != 0) {
        func_808078F4_bsfirstp(player);
        func_80807D70_bsfirstp(player);
        func_8080053C_bsfirstp(player);
        func_8009B4FC(player);
        func_800936E8(player, 1);
        func_8009337C(player, 0);
        func_80093370(player, 1);
        return;
    }
    _bapreload_entrypoint_0(player, 0xA, &unk_0, &unk_1);
    _bapreload_entrypoint_0(player, 0xB, &unk_2, &unk_3);
    func_800936CC(player, 1);
    func_80092EC8(player, unk_0);
    func_80093230(player, 1.0f);
    func_8009337C(player, 1);
    func_8009359C(player, unk_2);
    func_800936D8(player, 0x3F800000);
    func_800936E8(player, 1);
    func_800A34E4(player, 1);
    func_8008CF7C(player);
    func_808003B4_bsfirstp(player, 0x310, 2.0f);
}

int func_80807EEC_bsfirstp(player)
Actor *player;
{
    if (!func_800A3404()) {
        func_800A3544(player, 1);
        func_80807DD4_bsfirstp(player);
    }
}

int func_80807F24_bsfirstp(player)
Actor *player;
{
    if (func_800A3404(player)) {
        func_800A3544(player, 0);
        func_80807DD4_bsfirstp(player);
    }
}

s32 func_80807F5C_bsfirstp(player)
s32 player;
{
    func_800A3544(player, 1);
    func_80807DD4_bsfirstp(player);
    func_80801A5C_bsfirstp(player);
    bs_setState(player, 0xCA);
}

void func_80807F9C_bsfirstp()
{
    func_80807FBC_bsfirstp();
}

void func_80807FBC_bsfirstp(player) u8 *player;
{
    u8 *state_mem = *(u8 **) (player + 0x188);
    func_80808100_bsfirstp(player, state_mem + 0x6C);
    func_808080A4_bsfirstp(player, 0xFF);
    func_808080B4_bsfirstp(player, state_mem + 0x6C, state_mem[0x72]);
}

void func_8080800C_bsfirstp(player) s32 player;
{
    s16 target[3];
    s32 i;
    FirstPersonCamera1527 *state;

    state = (FirstPersonCamera1527 *) ((PlayerState *) player)->kazfly;
    func_80808100_bsfirstp((s32) player, (s32) target);
    for (i = 0; i != 3; i++) {
        state->local_0[i] = (state->local_0[i] * 3 + target[i]) >> 2;
    }
    func_808080B4_bsfirstp((s32) player, state->local_0, state->local_1);
}

void func_80808084_bsfirstp(s32 player)
{
    func_80092744(player, 0);
}

unsigned int func_808080A4_bsfirstp(player, value)
u8 *player;
u8 value;
{
    u8 *state_mem;
    state_mem = *((u8 **) (((s8 *) player) + 0x188));
    *((s8 *) (((s8 *) state_mem) + 0x72)) = value;
}

int func_808080B4_bsfirstp(player, color, unk_0)
s32 player;
s16 *color;
u8 unk_0;
{
    func_80092744(player, 1);
    func_80092750(player, color[0], color[1], color[2], unk_0);
}

// Writes the light color at the player into color as 0-255 RGB.
void func_80808100_bsfirstp(player, color) s32 player;
s32 color;
{
    f32 light[3];
    func_80808148_bsfirstp(player, light);
    func_8080853C_bsfirstp(light, 20.0f);
    func_808084AC_bsfirstp(light, 0.5f);
    func_808085A8_bsfirstp(light, color);
}

// Interpolates the vertex colors of the floor triangle under the player into color.
void func_80808148_bsfirstp(player, color) s32 player;
f32 *color;
{
    f32 pos[3];
    f32 to_v0[3];
    f32 offset[3];
    f32 denom;
    f32 swap;
    f32 weight;
    s32 i;
    s32 j;
    f32 perp[3];
    f32 edge[3];
    f32 hit[3];
    u8 vert_rgba[12];
    s32 vert_rgb[9];
    f32 verts[11];
    f32 dist;

    color[2] = 255.0f;
    color[1] = 255.0f;
    color[0] = 255.0f;
    func_8009C128(player, pos);
    if (!(func_80096628(player) & 0x200000)) {
        func_80096604(player, verts);
        func_800965E0(player, vert_rgba);
        for (i = 0; i < 3; i++) {
            verts[i * 3 + 1] = 0.0f;
            for (j = 0; j < 3; j++) {
                vert_rgb[i * 3 + j] = vert_rgba[i * 4 + j];
            }
            // Matching: needed for the match.
            color = (f32 *) ((s32) color * 1);
        }
        if (func_800F36D4(vert_rgb, vert_rgb + 3) != 0 && func_800F36D4(vert_rgb, vert_rgb + 6) != 0) {
            func_800EE84C(color, vert_rgb);
            return;
        }
        pos[1] = 0.0f;
        func_800EFB24(to_v0, pos, verts);
        to_v0[1] = 0.0f;
        func_800EFB24(edge, verts, verts + 3);
        edge[1] = 0.0f;
        func_800EFB24(perp, verts + 6, verts + 3);
        swap = perp[0];
        perp[1] = 0.0f;
        perp[0] = -perp[2];
        perp[2] = swap;
        denom = func_800EEAA4(to_v0, perp);
        if (denom == 0.0f) {
            denom = 0.1f;
        }
        func_800EFA4C(
            hit,
            verts[0] +
                (((-((perp[2] * edge[2]) + ((edge[0] * perp[0]) + (edge[1] * perp[1])))) / denom) *
                 to_v0[0]),
            0,
            verts[2] +
                (((-((edge[2] * perp[2]) + ((edge[0] * perp[0]) + (edge[1] * perp[1])))) / denom) *
                 to_v0[2]));
        func_800EFB24(offset, hit, verts + 3);
        dist = func_800EEF94(offset);
        weight = dist / (func_800EEF94(perp) + 0.01f);
        for (i = 0; i < 3; i++) {
            color[i] = (f32) vert_rgb[3 + i] + (f32) (vert_rgb[6 + i] - vert_rgb[3 + i]) * weight;
        }
        func_800EFB24(offset, hit, verts);
        dist = func_800EEF94(to_v0);
        weight = 1.0f - dist / (func_800EEF94(offset) + 0.01f);
        for (i = 0; i < 3; i++) {
            color[i] = color[i] + ((f32) vert_rgb[i] - color[i]) * weight;
        }
    }
}

// Blends each channel toward the channel average.
void func_808084AC_bsfirstp(f32 *color, f32 amount)
{
    f32 average;
    s32 i;

    average = ((color[0] + color[1]) + color[2]) * 0.3333333433f;
    for (i = 0; i != 3; i++) {
        color[i] = func_800F1214(amount, average, color[i]);
    }
}

// Raises each channel toward 255 by amount / 256.
void func_8080853C_bsfirstp(f32 *color, f32 amount)
{
    s32 i;
    f32 scale;

    scale = 1.0f - amount * 0.00390625f;
    for (i = 0; i < 3; i++) {
        color[i] = color[i] * scale + amount;
    }
}

// Clamps each channel to 0-255 and stores it rounded into out.
int func_808085A8_bsfirstp(color, out)
f32 color[3];
s16 *out;
{
    s32 i;
    f32 round_bias;
    float max_value;
    f32 tmp;
    f32 channel;
    for (i = 0; i < 3; i++) {
        channel = color[i];
        if (channel < 0.0f) {
            out[i] = 0;
        } else {
            // Matching: the extra temporaries are needed for the match.
            max_value = 255.0;
            round_bias = (tmp = 0.5f);
            if (channel > max_value) {
                out[i] = 0xFF;
            } else {
                out[i] = (tmp = channel + round_bias);
            }
        }
    }
}

int func_80808630_bsfirstp(s32 player)
{
    if (func_800C6E38(0x1A) && bakey_pressed(player, 9)) {
        return 1;
    }
    return 0;
}

int func_80808678_bsfirstp(s32 player, s32 unk_0)
{
    func_808086B0_bsfirstp(player, 3);
    func_8080633C_bsfirstp(player, 0.150000006f);
}

void func_808086B0_bsfirstp(player, phase) Actor *player;
s32 phase;
{
    u8 *data;
    u8 *anim_a;
    u8 *anim_b;
    data = func_80802458_bsfirstp(player);
    switch (phase) {
        case 1:
            baphysics_set_target_horizontal_velocity(
                player, baphysics_get_target_horizontal_velocity(player) * 0.3f);
            func_80802A40_bsfirstp(player, 8);
            func_808025C8_bsfirstp(player, &anim_a, &anim_b);
            func_80800424_bsfirstp(player, *((s16 *) (((s8 *) anim_a) + 0)),
                                   *((f32 *) (((s8 *) anim_a) + 4)));
            baanim_playForDuration_onceSmooth(player, *((s16 *) (((s8 *) anim_b) + 0)),
                                              *((f32 *) (((s8 *) anim_b) + 4)));
            break;

        case 2:
            baphysics_set_target_horizontal_velocity(player, 1000.f);
            func_8009E55C(player, 2, *((f32 *) (((s8 *) data) + 8)));
            func_8009E5A4(player, 2, 3);
            func_8009E4E0(player, 2, (void *) (&_bsfirstp_entrypoint_13));
            baflag_set(player, 0x3B);
            func_80802A40_bsfirstp(player, 9);
            break;

        case 3:
            func_8080633C_bsfirstp(player, 0.3f);
            if (baphysics_get_target_horizontal_velocity(player) < 0.0f) {
                baphysics_set_target_horizontal_velocity(player, 0);
            }
            func_8009E5A4(player, 2, 2);
            func_8009E55C(player, 2, 0.0f);
            baflag_clear(player, 0x3B);
    }

    *((s32 *) (((s8 *) player) + 0x15C)) = phase;
}

void func_80808848_bsfirstp(s32 player)
{
    func_80807BB8_bsfirstp(player);
    func_80808DB0_bsfirstp(player);
    _bainvisible_entrypoint_7(player, 3, 1.0f, 1.0f, 0.4f);
    func_808086B0_bsfirstp(player, 1);
}

void func_808088A4_bsfirstp(s32 player)
{
    func_808086B0_bsfirstp(player, 0x3);
    func_80807C8C_bsfirstp(player);
}

void func_808088D0_bsfirstp(PlayerState *player)
{
    s32 next_state = 0;
    AnimCtrl *anim_ctrl;

    anim_ctrl = func_8008D04C(player);
    func_80808E78_bsfirstp(player);
    switch (player->unk15C.word) {
        case 1:
            if (anctrl_isAt(anim_ctrl, 0.285f))
                func_808086B0_bsfirstp(player, 2);
            break;
        case 2:
            baphysics_set_target_yaw(player, yaw_get(player));
            if (anctrl_isAt(anim_ctrl, 0.8f))
                func_808086B0_bsfirstp(player, 3);
            break;
        case 3:
            if (anctrl_isStopped(anim_ctrl))
                next_state = 0xCA;
    }
    func_80803B58_bsfirstp(
        player,
        func_80013970((func_800F0D50(anctrl_getAnimTimer(anim_ctrl), 0.285f, 0.8f) - 0.285f) *
                      1.9417477f * 180.0f));
    bs_setState(player, next_state);
}

int bsfirstp_entrypoint_34(s32 index)
{
    return D_8080B5B0_bsfirstp[index];
}

void func_80808A24_bsfirstp(u8 *player)
{
    u8 *state_mem;

    state_mem = (*(u8 **) ((s8 *) (player) + (0x188)));
    func_80807BB8_bsfirstp(player);
    (*(s32 *) ((s8 *) (state_mem) + (8))) = -1;
    func_80808DB0_bsfirstp(player);
    (*(s32 *) ((s8 *) (player) + (0x160))) = 0;
    func_80808CAC_bsfirstp(player, 1);
    func_80800858_bsfirstp(player, 1);
    func_80808D80_bsfirstp(player);
}

void func_80808A8C_bsfirstp(s32 player)
{
    func_80807C8C_bsfirstp(player);
}
void func_80808AAC_bsfirstp(s32 player)
{
    s32 next_state;

    func_80807D48_bsfirstp(player);
    func_80808E78_bsfirstp(player);
    func_8080633C_bsfirstp(player, 1.0f);
    next_state = func_80808B24_bsfirstp(player);
    if (next_state != 0) {
        bs_setState(player, next_state);
        return;
    }
    func_80808B8C_bsfirstp(player, next_state);
}

int bsfirstp_entrypoint_35(s32 index)
{
    return D_8080B5C0_bsfirstp[index];
}

int func_80808B24_bsfirstp(player)
Actor *player;
{
    s32 next_state;
    if (func_80802D50_bsfirstp(player, &next_state)) {
        return next_state;
    }
    if (func_80808630_bsfirstp(player)) {
        return 0xD2;
    }
    if (func_80809540_bsfirstp(player, 0) != 0) {
        return 0xD1;
    }
    return 0;
}

void func_80808B8C_bsfirstp(player) PlayerState *player;
{
    if (func_80802444_bsfirstp(player) == 1) {
        if (player->unk15C.word >= 2) {
            player->unk160.word = 0;
            func_80808CAC_bsfirstp(player, 1);
        }
    } else {
        switch (player->unk15C.word) {
            case 0:
                break;
            case 1:
                player->unk16C -= func_800D9004();
                if (player->unk16C < 0.0f)
                    func_80808CAC_bsfirstp(player, 1);
                break;
            default:
                if (func_80800228_bsfirstp(player))
                    func_80808CAC_bsfirstp(player, 1);
        }
    }
}

void func_80808C48_bsfirstp(player) s32 player;
{
    *((s32 *) (player + 0x160)) = 0;
    *((f32 *) (player + 0x16C)) = 5.0f;
    func_80808CAC_bsfirstp(player, 0);
    func_80808D80_bsfirstp(player);
    func_8008B304(baanim_getAnimCtrlPtr(player));
    func_8008B304(func_8008D04C(player));
}

// Plays the next entry of the animation script.
void func_80808CAC_bsfirstp(player, mode)PlayerState *player;
s32 mode;
{
    FirstPersonScriptStep1612 *step;
    int tmp;

    tmp = func_808024DC_bsfirstp();
    step = (FirstPersonScriptStep1612 *) ((player->unk160.word++ * 8) + tmp);
    if (mode) {
        func_80800424_bsfirstp((Actor *) player, step->local_0, step->local_2);
    } else {
        func_808003B4_bsfirstp((Actor *) player, step->local_0, step->local_2);
    }
    player->unk15C.word = 2;
    tmp = step->local_1;
    if (tmp & 1) {
        func_808001FC_bsfirstp(player);
        player->unk15C.word = 0;
        tmp = step->local_1;
    }
    if (tmp & 2) {
        player->unk16C = step->local_2;
        player->unk15C.word = 1;
    }
    step++;
    if (step->local_0 == 0) {
        player->unk160.word = step->local_1;
    }
}

int func_80808D80_bsfirstp(player)
s32 player;
{
    s16 *anim = func_80802508_bsfirstp();
    baanim_playForDuration_loopSmooth(player, anim[0], *(s32 *) ((char *) anim + 0x4));
}

void func_80808DB0_bsfirstp(player) Actor *player;
{
    u8 *state_mem = *(u8 **) ((char *) player + 0x188);
    s32 mode = func_80802444_bsfirstp(player);
    if (mode != *(s32 *) ((char *) state_mem + 8)) {
        *(s32 *) ((char *) state_mem + 8) = mode;
        mode = func_80802444_bsfirstp(player);
        switch (mode) {
            case 0:
                func_808061AC_bsfirstp(player, 2);
                func_80809DA0_bsfirstp(player, 0);
                func_8080483C_bsfirstp(player, 0);
                func_808099A8_bsfirstp(player, 1);
                return;
            case 1:
                func_808061AC_bsfirstp(player, 3);
                func_80809DA0_bsfirstp(player, -1);
                func_8080483C_bsfirstp(player, 1);
                func_808099A8_bsfirstp(player, 2);
        }
    }
}

void func_80808E78_bsfirstp(player) PlayerState *player;
{
    s32 *state_mem = *(s32 **) ((u8 *) player + 0x188);

    func_80804848_bsfirstp(player, state_mem[3]);
    func_80801928_bsfirstp(player);
    func_80801DC0_bsfirstp(player);
    func_80808DB0_bsfirstp(player);
    func_80809D24_bsfirstp(player);
    func_8080682C_bsfirstp(player);
    func_808099B4_bsfirstp(player);
    func_80800830_bsfirstp(player);
    func_80808EF0_bsfirstp(player);
    func_80802F20_bsfirstp(player);
}

int func_80808EF0_bsfirstp(player)
Actor *player;
{
    f32 pos[4];
    if (bakey_pressed(player, 8)) {
        func_8009C128(player, pos);
        func_801013A8(pos, 0x6F, *(u8 **) ((char *) player + 0x184));
    }
}

void func_80808F38_bsfirstp(player) PlayerState *player;
{
    u8 *fp_state;
    s32 variant;
    s32 *variant_ptr = &variant;
    f32 yaw;
    f32 pos[3];
    s32 pad;
    f32 *row;

    fp_state = (u8 *) player->kazfly;
    variant = 0;
    if (func_800D3948() && _gcstatusDll_entrypoint_14() == 5 &&
        _gcstatusDll_entrypoint_15() != player->unk184) {
        variant = 1;
    }
    func_8008E944(player);
    func_800F7F98(player->unk184, 1);
    _bababykaz_entrypoint_14(player);
    if (variant == 0) {
        if (*(s32 *) (fp_state + 0xEC) == 0x45) {
            variant = 2;
        } else {
            switch (*(s32 *) (fp_state + 0xF4)) {
                default:
                case 1:
                    variant = 3;
                    break;
                case 2:
                    variant = 4;
                    break;
                case 4:
                    variant = 5;
            }
        }
    }
    func_8009C128(player, pos);
    func_800F1E6C((f32 *) (fp_state + 0xF8), pos, &yaw);
    row = D_8080A650_bsfirstp[variant];
    // Matching: needed for the match.
    if (1) {
    }
    baphysics_set_target_horizontal_velocity(player, row[0]);
    baphysics_set_target_yaw(player, yaw);
    baphysics_set_horizontal_velocity(player, yaw, row[0]);
    baphysics_set_vertical_velocity(player, row[1]);
    baphysics_set_gravity(player, row[2]);
    *(f32 *) (fp_state + 0x10C) = row[3];
    func_8080911C_bsfirstp(player, 0);
    yaw_applyIdeal(player);
}

void func_808090D8_bsfirstp(player) Actor *player;
{
    s32 *state_mem = *(s32 **) ((u8 *) player + 0x188);
    state_mem[2] = -1;
    func_80808DB0_bsfirstp(player);
    func_8008E95C(player);
    func_800F7F98(*(s32 **) ((u8 *) player + 0x184), 0);
}

void func_8080911C_bsfirstp(player, mode) u8 *player;
s32 mode;
{
    u8 *state_mem;
    state_mem = *(u8 **) (player + 0x188);
    switch (mode) {
        case 0:
            func_8009FFD8(player, 1, 1, 2, 3);
            break;
        case 1:
            func_8009FFD8(player, 1, 0, 0, 0x10);
    }
    *(s32 *) (state_mem + 0x108) = mode;
}

void func_80809198_bsfirstp(player) PlayerState *player;
{
    FirstPersonTimer *fp_state;
    f32 scale;
    fp_state = (FirstPersonTimer *) player->kazfly;
    switch (fp_state->local_1) {
        case 0:
            if (func_800F1574(&fp_state->local_2, func_800D9004()))
                func_8080911C_bsfirstp(player, 1);
            break;
        case 1:
            if (func_8009E674(player, 4))
                scale = 0.0f;
            else
                scale = D_8080A660_bsfirstp[fp_state->local_0].local_0[0];
            func_8080633C_bsfirstp(player, scale);
    }
}

// Camera position follows the player; camera rotation comes from the current animation.
void func_80809250_bsfirstp(player)PlayerState *player;
{
    f32 rot_sample[9];
    void *anim_ctrl;
    f32 timer;
    u8 *anim_data;
    s32 anim_id;
    f32 cam_rot[3];
    f32 cam_pos[3];
    FirstPersonCameraOffset *cam_offset;

    anim_ctrl = baanim_getAnimCtrlPtr(player);
    timer = anctrl_getAnimTimer(anim_ctrl);
    anim_id = anctrl_getIndex(anim_ctrl);
    anim_data = func_800D674C(anim_id);
    func_800E0050(anim_data, timer, 3, rot_sample);
    cam_offset = (FirstPersonCameraOffset *) func_80802484_bsfirstp(player);
    func_8009C128(player, cam_pos);
    cam_pos[1] += cam_offset->local_1;
    cam_rot[0] = -rot_sample[0];
    cam_rot[1] = rot_sample[1] + yaw_get(player) + 180.0f;
    cam_rot[2] = rot_sample[2];
    _ncba1p_entrypoint_6(func_800A4CA8(player), cam_pos);
    _ncba1p_entrypoint_7(func_800A4CA8(player), cam_rot);
}

s32 func_80809334_bsfirstp(void *player)
{
    s32 player_addr;

    // Matching: the s32 copy of the parameter is needed for the match.
    player_addr = (s32) player;
    func_80807BB8_bsfirstp(player_addr);
    func_80808DB0_bsfirstp(player_addr);
    func_80809900_bsfirstp(player_addr);
    func_80800858_bsfirstp(player_addr, 1);
    func_80809684_bsfirstp(player_addr, 0);
}

void func_80809384_bsfirstp(s32 player)
{
    func_80807C8C_bsfirstp(player);
}
void func_808093A4_bsfirstp(u8 *player)
{
    u8 *state_mem;
    s32 next_state;
    s32 forced_state;
    s32 zone;

    state_mem = (*(u8 **) ((s8 *) (player) + (0x188)));
    func_80807D48_bsfirstp(player);
    func_80808E78_bsfirstp(player);
    func_8080633C_bsfirstp(player, 1.0f);
    forced_state = func_808094A4_bsfirstp(player);
    next_state = forced_state;
    if (forced_state == 0) {
        zone = func_80809540_bsfirstp(player, (*(u8 *) ((s8 *) (state_mem) + (0x218))));
        switch (zone) {
            case 0:
                next_state = 0xCA;
                break;
            case 1:
                if ((*(u8 *) ((s8 *) (state_mem) + (0x218))) != 1) {
                    func_80809684_bsfirstp(player, 1);
                }
                break;
            case 2:
                if ((*(u8 *) ((s8 *) (state_mem) + (0x218))) != 2) {
                    func_80809684_bsfirstp(player, 2);
                }
        }
        func_80809740_bsfirstp(player);
    }
    if (next_state != 0) {
        bs_setState(player, next_state);
    }
}

int bsfirstp_entrypoint_36(s32 index)
{
    return D_8080B5D0_bsfirstp[index];
}

int func_808094A4_bsfirstp(player)
Actor *player;
{
    s32 next_state;
    if (func_80802D50_bsfirstp(player, &next_state)) {
        return next_state;
    }
    {
        if (func_80808630_bsfirstp(player) != 0) {
            return 0xD2;
        }
        return 0;
    }
}

int func_808094F4_bsfirstp(player)
s32 player;
{
    s32 zone;
    zone = func_80809540_bsfirstp(player, 1);
    switch (zone) {
        case 0:
            return 0xCA;

        case 1:
        case 2:
            return 0xD1;

        default:
            return 0;
    }
}

// Returns the next zone (0-2); zones change with 5% hysteresis.
int func_80809540_bsfirstp(player, zone)
PlayerState *player;
s32 zone;
{
    u8 *fp_state;
    f32 *thresholds;
    f32 level;
    f32 forward_vel;
    f32 side_vel;
    f32 abs_side;
    f32 abs_forward;

    fp_state = (u8 *) player->kazfly;
    thresholds = (f32 *) func_808024B0_bsfirstp(player);
    level = func_8080613C_bsfirstp(player);
    forward_vel = baphysics_get_target_horizontal_velocity(player);
    side_vel = *(f32 *) (fp_state + 0x1CC);
    abs_forward = mlAbsF(forward_vel);
    abs_side = mlAbsF(side_vel);
    switch (zone) {
        case 0:
            if (abs_side + abs_forward > 0.0f)
                return 1;
            break;
        case 1:
            if (0.0f - (abs_side + abs_forward) == 0.0f && level < thresholds[0])
                return 0;
            if (thresholds[1] * 1.05f < level)
                return 2;
            break;
        case 2:
            if (level < thresholds[1] * 0.95f)
                return 1;
    }
    return zone;
}

void func_80809684_bsfirstp(player, zone) u8 *player;
s32 zone;
{
    u8 *state_mem;
    f32 *thresholds;
    f32 *entry;

    state_mem = *(u8 **) (player + 0x188);
    thresholds = func_808024B0_bsfirstp();
    // Matching: empty block steers IDO's register allocation.
    if (player) {
    }
    state_mem[0x218] = zone;
    switch (zone) {
        case 0:
            return;
        case 1:
            entry = func_80802560_bsfirstp(player, zone);
            break;
        case 2:
            entry = func_80802594_bsfirstp(player, zone);
    }
    func_80800290_bsfirstp(player, *(s16 *) entry, *(s32 *) (entry + 1));
    *(f32 *) (state_mem + 0x21C) = entry[1];
    *(f32 *) (state_mem + 0x220) = entry[2];
    *(f32 *) (state_mem + 0x224) = thresholds[0];
    *(f32 *) (state_mem + 0x228) = thresholds[1];
}

int func_80809740_bsfirstp(player)
PlayerState *player;
{
    f32 duration;
    AnimCtrl *anim_ctrl;
    f32 move_dir[3];
    f32 rel;
    f32 level;
    f32 lo;
    f32 hi;
    u8 *fp_state;
    fp_state = (u8 *) player->kazfly;
    anim_ctrl = baanim_getAnimCtrlPtr(player);
    func_80806148_bsfirstp(player, move_dir);
    if (move_dir[2] >= 0.0f)
        fp_state[0x219] = 1;
    else
        fp_state[0x219] = 0;
    func_8008B188(anim_ctrl, fp_state[0x219]);
    level = func_8080613C_bsfirstp(player);
    switch (fp_state[0x218]) {
        case 0:
            lo = 0.0f;
            hi = *(f32 *) (fp_state + 0x224);
            break;
        case 1:
            lo = *(f32 *) (fp_state + 0x224);
            hi = *(f32 *) (fp_state + 0x228);
            break;
        case 2:
            lo = *(f32 *) (fp_state + 0x228);
            hi = 1.0f;
            break;
    }
    if (lo != hi) {
        rel = level - lo;
        level = func_800F0D50(rel / (hi - lo), 0.0f, 1.0f);
    } else
        level = 1.0f;
    lo = *(f32 *) (fp_state + 0x21C);
    hi = *(f32 *) (fp_state + 0x220);
    duration = (hi - lo) * level + lo;
    anctrl_setDuration(anim_ctrl, duration);
    if (!func_800EA068(0x20)) {
        switch (fp_state[0x218]) {
            case 1:
                func_800A2CE8(player, 0.45f, 4);
                func_800A2CE8(player, 0.9f, 3);
                break;
            case 2:
                func_800A2CE8(player, 0.45f, 4);
                func_800A2CE8(player, 0.95f, 3);
                break;
        }
    }
}

s32 func_80809900_bsfirstp(player) Actor *player;
{
    func_80800424_bsfirstp(player, func_80802534_bsfirstp(), 1.0f);
    func_808001FC_bsfirstp(player);
}

f32 func_80809938_bsfirstp(player)
u8 *player;
{
    u8 *state_mem = *(u8 **) (player + 0x188);
    f32 ratio = *(f32 *) (state_mem + 0x24C) * (1.0f / *(f32 *) (state_mem + 0x230));
    return ratio;
}

void func_8080995C_bsfirstp(player) Actor *player;
{
    u8 *state_mem;

    state_mem = *(u8 **) ((char *) player + 0x188);
    bcopy(func_80802458_bsfirstp() + 0x74, state_mem + 0x230, 0x18);
    *(s16 *) ((char *) state_mem + 0x248) = 0;
    *(f32 *) ((char *) state_mem + 0x24C) = 0.0f;
    *(f32 *) ((char *) state_mem + 0x250) = 0.0f;
}

void func_808099A8_bsfirstp(player, mode) Actor *player;
s32 mode;
{
    s32 *state_mem = *(s32 **) ((char *) player + 0x188);
    *(s16 *) ((char *) state_mem + 0x248) = mode;
}

void func_808099B4_bsfirstp(player) u8 *player;
{
    s16 *mode_ptr;
    s16 mode;
    mode = *((s16 *) (((s8 *) (*((u8 **) (((s8 *) player) + 0x188)))) + 0x248));
    mode_ptr = (s16 *) (((s8 *) (*((u8 **) (((s8 *) player) + 0x188)))) + 0x248);
    switch (mode) {
        case 1:
            func_80809A10_bsfirstp();
            return;

        case 2:
            func_80809A7C_bsfirstp();
            // Matching: needed for the match.
            mode = *mode_ptr;

        case 0:
            return;
    }
}

void func_80809A10_bsfirstp(player) PlayerState *player;
{
    f32 unk_0;
    f32 unk_1;
    f32 unk_2;
    FirstPersonAimLimits *aim_limits;

    aim_limits = (FirstPersonAimLimits *) player->kazfly;
    unk_2 = aim_limits->local_3;
    unk_0 = -unk_2 * aim_limits->local_0;
    if (aim_limits->local_2) {
        unk_1 = aim_limits->local_4 / (1.0f + aim_limits->local_1);
    } else {
        unk_1 = aim_limits->local_5;
    }
    func_80809AF8_bsfirstp(player, unk_0, unk_1, unk_2);
}

void func_80809A7C_bsfirstp(player) void *player;
{
    void *state_mem;
    float unk_0;
    float unk_1;

    state_mem = *(void **) ((char *) player + 0x188);
    unk_0 = func_800F122C(-(*(float *) ((char *) state_mem + 0xC0)), 5.0f,
                            *(f32 *) ((char *) state_mem + 0x234));
    if (*(float *) ((char *) state_mem + 0xC0) != 0.0f) {
        unk_1 = *(float *) ((char *) state_mem + 0x23C);
    } else {
        unk_1 = *(float *) ((char *) state_mem + 0x244);
    }
    func_80809AF8_bsfirstp(player, unk_0, unk_1, *(f32 *) ((char *) state_mem + 0x234));
}

// Steps the yaw: one fixed 1/30 s step plus the remaining frame time.
void func_80809AF8_bsfirstp(PlayerState *player, f32 param_1, f32 param_2, f32 param_3)
{
    FirstPersonYawStep *yaw_state;
    f32 yaw;
    f32 extra_time;
    f32 step;
    f32 extra_step;
    f32 delta_yaw;
    f32 new_yaw;

    yaw_state = (FirstPersonYawStep *) player->kazfly;
    extra_time = func_800D9004() - (1.0f / 30.0f);
    step = func_808057C8_bsfirstp(&yaw_state->local_0, param_1, param_3, 1.0f / 30.0f, param_2);
    if (extra_time != 0.0f) {
        extra_step = func_808057C8_bsfirstp(&yaw_state->local_0, param_1, param_3, extra_time, param_2);
    } else {
        extra_step = 0.0f;
    }
    func_808052A4_bsfirstp(&extra_step, &yaw_state->local_1);
    delta_yaw = step + extra_step;
    yaw = yaw_get(player);
    new_yaw = func_800136E4(yaw + delta_yaw);
    yaw_setIdeal(player, new_yaw);
    yaw_set(player, new_yaw);
}

int bsfirstp_entrypoint_37(Actor *player)
{
    s32 id;
    id = func_800A89F8();
    if (id == func_800A4C68(player)) {
        func_80809C30_bsfirstp(player);
    }
}

s32 func_80809C30_bsfirstp(player)
s32 player;
{
    if (func_80093DF4(player, 2) != 0 && func_800936F4(player) != 0 &&
        func_8009239C(player) != 0) {
        func_80093E18(player, func_800A7180());
    }
}

int func_80809C90_bsfirstp(player)
int player;
{
    func_8009ADF0(player, 0xb, 1);
}

void func_80809CB4_bsfirstp(player) s32 player;
{
    func_8009ADF0(player, 0xB, 0);
}

void func_80809CD8_bsfirstp()
{
    func_80809CF8_bsfirstp();
}

void func_80809CF8_bsfirstp(player) void *player;
{
    void *state_mem = *(void **) ((char *) player + 0x188);
    *(float *) ((char *) state_mem + 0x29C) = 162.5f;
    *(float *) ((char *) state_mem + 0x2A0) = 8.0f;
    *(float *) ((char *) state_mem + 0x25C) = 0.0f;
    *(int *) ((char *) state_mem + 0x264) = 0;
}

s32 func_80809D24_bsfirstp(player)
s32 player;
{
    func_80809DD0_bsfirstp(player);
    func_80809F74_bsfirstp(player);
    func_8080A03C_bsfirstp(player);
    func_8080A194_bsfirstp(player);
    func_8080A250_bsfirstp(player);
}

s32 func_80809D6C_bsfirstp(player)
u8 *player;
{
    u8 *state_mem = *(u8 **) (player + 0x188);
    return *(s32 *) (state_mem + 0x254) == 1 ? 1 : 0;
}

f32 func_80809D94_bsfirstp(player) void *player;
{
    f32 *state_mem;
    f32 *state_ptr;
    state_mem = *((f32 **) (((u8 *) player) + 0x188));
    // Matching: the comma expression is needed for the match.
    state_ptr = (0, state_mem);
    return (*(f32 *) ((char *) (state_ptr) + 604));
}

void func_80809DA0_bsfirstp(player, value) void *player;
s32 value;
{
    void *state_mem;

    state_mem = *(void **) ((char *) player + 0x188);
    if (value == 0) {
        if (*(s32 *) ((char *) state_mem + 0x254) < 0) {
            *(s32 *) ((char *) state_mem + 0x254) = value;
            *(s32 *) ((char *) state_mem + 0x258) = 0;
        }
    } else {
        *(s32 *) ((char *) state_mem + 0x254) = value;
        *(s32 *) ((char *) state_mem + 0x258) = 0;
    }
}

void func_80809DD0_bsfirstp(player) u8 *player;
{
    u8 *state;
    s32 unk_0;
    f32 unk_1;
    f32 unk_2;

    state = *(u8 **) (player + 0x188);
    unk_0 = 0;
    if (*(s32 *) (state + 0xA0) == 1) {
        unk_1 = *(f32 *) (state + 0xC4);
    } else {
        unk_0 = *(s32 *) (state + 0x10);
        unk_1 = *(f32 *) (state + 0x180);
    }
    switch (unk_0) {
        case 0:
            *(s32 *) (state + 0x254) = 0;
            break;
        case 1:
            unk_2 = mlAbsF(*(f32 *) (state + 0x148));
            if (mlAbsF(unk_1) > 0.01f) {
                if (unk_2 > 0.5f) {
                    *(s32 *) (state + 0x258) = 1;
                } else {
                    *(s32 *) (state + 0x258) = 0;

}
*(s32 *) (state + 0x254) = 0;
}
else if (!*(s32 *) (state + 0x254))
{
    if (*(s32 *) (state + 0x258)) {
        if (unk_2 < 0.25f) {
            *(s32 *) (state + 0x254) = 1;
        }

}
else if (unk_2 > 0.75f)
{
    *(s32 *) (state + 0x254) = 1;
}
}
}
}

// Vertical ray 300 units above and below pos.
s32 func_80809EF8_bsfirstp(f32 *pos, f32 *end, s32 unk_0)
{
    f32 top[3];
    func_800EE7F8(top, pos);
    top[1] += 300.0f;
    func_800EE7F8(end, pos);
    end[1] += -300.0f;
    func_800BEF00(top, end, unk_0, 0x8020020);
}

void func_80809F74_bsfirstp(player) PlayerState *player;
{
    u8 *state[1];
    u8 *block;
    f32 unk_0[3];
    f32 unk_1[3];
    f32 yaw;
    u32 unk_2;
    s32 pad_x[2];

    state[0] = *(u8 **) ((u8 *) player + 0x188);
    unk_2 = func_80096628(player);
    yaw = yaw_get(player);
    func_800963C0(player, unk_0);
    if (func_800F1B78(unk_1, unk_0, yaw, 1.0f) && (s32) (unk_2 << 4) >= 0) {
        block = state[0] + 0x254;
        *(f32 *) (block + 0x1C) = -unk_1[0];
        if ((s32) (unk_2 << 3) < 0) {
            *(s32 *) (block + 0x18) = 3;
        } else {
            *(s32 *) (block + 0x18) = 1;
        }
    } else {
        block = state[0] + 0x254;
        *(f32 *) (block + 0x1C) = 0.0f;
        if ((s32) (unk_2 << 3) < 0) {
            *(s32 *) (block + 0x18) = 2;
        } else {
            *(s32 *) (block + 0x18) = 0;
        }
    }
}

void func_8080A03C_bsfirstp(player) PlayerState *player;
{
    u8 *state[1];
    u8 *hit;
    f32 pos[3];
    f32 rot[3];
    f32 dist;
    FirstpAim1828 *aim;
    s32 flag;
    f32 diff[3];
    FirstpAim1828 *aim2;

    state[0] = *(u8 **) ((u8 *) player + 0x188);
    func_800F3BB0(player, pos);
    aim = (FirstpAim1828 *) (state[0] + 0x254);
    dist = aim->unk48;
    rot[0] = func_800137F4(yaw_get(player));
    // Matching: second pointer variable to the same struct.
    aim2 = aim;
    rot[1] = 0.0f;
    // Matching: the target calls func_80013788 without setting f12, so it goes through a no-argument alias.
    rot[2] = func_80013788_noarg();
    func_800EE7B4(aim2->unk20, pos, rot, dist);
    hit = (u8 *) func_80809EF8_bsfirstp(aim2->unk20, aim2->unk2C, aim2->unk38);
    if (hit != NULL) {
        flag = *(s32 *) (hit + 8) & 0x10000000;
        aim2->unk14 = 1;
        if (func_800EF030(aim2->unk38) > 0.01f) {
            if (flag)
                aim2->unk50 = 3;
            else
                aim2->unk50 = 1;
        } else {
            if (flag)
                aim2->unk50 = 2;
            else
                aim2->unk50 = 0;
        }
    } else {
        aim2->unk14 = 0;
        aim2->unk50 = 0;
    }
    func_800EFB24(diff, aim2->unk2C, pos);
    dist = func_80013728(func_80013B7C(diff[1], func_800EEFFC(diff)));
    aim2->unk44 = func_800F0DC0(dist, 30.0f);
}

void func_8080A194_bsfirstp(player) u8 *player;
{
    u8 *state;
    s32 unk_0;
    s32 unk_1;
    s32 unk_2;
    s32 unk_3;
    s32 unk_4;
    s32 unk_5;
    FpSub *sub;
    state = *(u8 **) (player + 0x188);
    unk_0 = *(s32 *) (state + 0x26C);
    unk_1 = *(s32 *) (state + 0x2A4);
    unk_3 = unk_0 == 3;
    unk_2 = unk_3;
    if (!unk_3)
        unk_3 = unk_0 == 2;
    sub = (FpSub *) (state + 0x254);
    unk_4 = unk_1 == 3;
    if (unk_4 && !unk_3)
        sub->unk14 = 0;
    unk_5 = unk_4;
    if (!unk_5)
        unk_5 = unk_1 == 2;
    if (!unk_5 & unk_2)
        sub->unk14 = 0;
    if (sub->unk14) {
        sub->unk8 = sub->unk44;
        return;
    }
    if (sub->unk48 == 25.0f && sub->unkC >= 5)
        sub->unk8 = sub->unk1C;
}

void func_8080A250_bsfirstp(player) PlayerState *player;
{
    u8 *state;
    FirstPersonAcceleration *accel;

    state = *(u8 **) ((u8 *) player + 0x188);
    accel = (FirstPersonAcceleration *) (state + 0x254);
    switch (*(s32 *) (state + 0x260)) {
        case 0:
            accel->local_4 *= 0.5f;
            if (accel->local_4 < 1.0f)
                accel->local_4 = 1.0f;
            break;
        case 1:
            break;
        default:
            accel->local_4 *= 2.0f;
            if (accel->local_4 > 32.0f)
                accel->local_4 = 32.0f;
    }
    if (accel->local_2) {
        accel->local_3 += accel->local_4;
        if (accel->local_3 > 300.0f)
            accel->local_3 = 300.0f;
    } else {
        accel->local_3 -= 8.0f;
        if (accel->local_3 < 25.0f)
            accel->local_3 = 25.0f;
    }
    if (accel->local_1 == accel->local_2)
        accel->local_0++;
    else {
        accel->local_0 = 0;
        accel->local_1 = accel->local_2;
    }
    if (accel->local_0 >= 5 && accel->local_2 == 0)
        accel->local_3 = 25.0f;
}

extern void _bsfirstp_entrypoint_26();
extern void _bsdrone_entrypoint_3();
f32 D_8080A5B0_bsfirstp[2][4] = {0.0f, -0.1f, -0.1f, 0.0f, 0.0f, -0.2f, -0.15f, 3e+01f};
u8 D_8080A5D0_bsfirstp[96] = {
    0x42, 0x18, 0x0,  0x0,  0x41, 0x64, 0x0,  0x0,  0x42, 0x18, 0x0, 0x0, 0x41, 0x64, 0x0, 0x0,
    0x41, 0x0,  0x0,  0x0,  0x40, 0xE0, 0x0,  0x0,  0x42, 0xE4, 0x0, 0x0, 0x42, 0xAB, 0x0, 0x0,
    0x42, 0x16, 0x7A, 0xE2, 0x41, 0xE1, 0xB8, 0x53, 0x41, 0x0,  0x0, 0x0, 0x40, 0xE0, 0x0, 0x0,
    0x42, 0x98, 0x0,  0x0,  0x41, 0x64, 0x0,  0x0,  0x42, 0x98, 0x0, 0x0, 0x41, 0x64, 0x0, 0x0,
    0x41, 0x0,  0x0,  0x0,  0x40, 0xE0, 0x0,  0x0,  0x42, 0xE4, 0x0, 0x0, 0x42, 0xAB, 0x0, 0x0,
    0x42, 0x16, 0x7A, 0xE2, 0x41, 0xE1, 0xB8, 0x53, 0x41, 0x0,  0x0, 0x0, 0x40, 0xE0, 0x0, 0x0};
u8 D_8080A630_bsfirstp[16] = {0x0, 0x13, 0x4,  0x6B, 0x0, 0xA, 0x1, 0x66,
                              0x0, 0x16, 0x27, 0x10, 0x0, 0x0, 0x0, 0x0};
u8 D_8080A640_bsfirstp[16] = {0x0, 0x13, 0x4,  0x6C, 0x0, 0xA, 0x1, 0x66,
                              0x0, 0x16, 0x27, 0x10, 0x0, 0x0, 0x0, 0x0};
f32 D_8080A650_bsfirstp[6][5] = {
    2e+02f, 1e+02f, -1.2e+03f, 0.125f, 1.0f, 2e+02f, 1e+02f,   -1.2e+03f, 0.1f, 0.5f,
    0.0f,   1e+02f, -1.2e+03f, 0.0f,   0.0f, 2e+02f, 3e+02f,   -1.2e+03f, 0.1f, 0.5f,
    3e+02f, 3e+02f, -1.2e+03f, 0.2f,   0.5f, 5e+02f, 5.1e+02f, -1.2e+03f, 0.3f, 0.5f};
u32 D_8080A6C8_bsfirstp[19] = {0x40D55810, 0x41F00000, 0x42200000, 0x0,        0x0, 0x0, 0x0,
                               0x0,        0x0,        0x0,        0x0,        0x0, 0x0, 0x0,
                               0x0,        0x0,        0x0,        0x3F800000, 0x0};
u32 D_8080A714_bsfirstp[19] = {0x41200000, 0x42700000, 0x42A00000, 0x3C1374BC, 0xBDD70A3D,
                               0xBF000000, 0xBFAA9FBE, 0x41B40000, 0x0,        0x0,
                               0x1,        0x2C,       0x3EA8F5C3, 0xC1F00000, 0x42200000,
                               0xC2480000, 0x42480000, 0x3F666666, 0x42700000};
u32 D_8080A760_bsfirstp[19] = {0x41200000, 0x42700000, 0x42A00000, 0x3C23D70A, 0xBDA3D70A,
                               0xBF170A3D, 0xBFB33333, 0x41A00000, 0x40C00000, 0x0,
                               0x1,        0x3A,       0x3E800000, 0xC1F00000, 0x41C80000,
                               0xC2480000, 0x42700000, 0x3F666666, 0x42700000};
u32 D_8080A7AC_bsfirstp[19] = {0x41200000, 0x42700000, 0x42340000, 0x3C03126F, 0xBDA3D70A,
                               0xBF170A3D, 0xBFB33333, 0x41A00000, 0x40C00000, 0x0,
                               0x1,        0x3A,       0x3E800000, 0xC1F00000, 0x41C80000,
                               0xC2480000, 0x42700000, 0x3F333333, 0x420C0000};
u32 D_8080A7F8_bsfirstp[19] = {0x41200000, 0x42700000, 0x42B40000, 0x3BDB8BAC, 0x3D8F5C29,
                               0xBF07AE14, 0xBFAA9FBE, 0x418C0000, 0x40C00000, 0x0,
                               0x1,        0x6A,       0x3EA8F5C3, 0xC1F00000, 0x42340000,
                               0xC2700000, 0x42700000, 0x3F800000, 0x428C0000};
u32 D_8080A844_bsfirstp[19] = {0x41200000, 0x42200000, 0x42D20000, 0x3C23D70A, 0xBDE147AE,
                               0xBF000000, 0xBFCCCCCD, 0x418C0000, 0x40C00000, 0x0,
                               0x1,        0x2C,       0x3E800000, 0xC2340000, 0x41F00000,
                               0xC2700000, 0x427C0000, 0x3F4CCCCD, 0x42A00000};
int D_8080A890_bsfirstp[6] = {(u32) &D_8080A6C8_bsfirstp, (u32) &D_8080A714_bsfirstp,
                              (u32) &D_8080A760_bsfirstp, (u32) &D_8080A7AC_bsfirstp,
                              (u32) &D_8080A7F8_bsfirstp, (u32) &D_8080A844_bsfirstp};
u32 D_8080A8A8_bsfirstp[35] = {
    0x41A00000, 0x0,        0x41A00000, 0x42200000, 0x42A00000, 0x41C80000, 0x42700000,
    0x41F00000, 0xC528C000, 0xC5A8C000, 0x41C80000, 0x44480000, 0x3E800000, 0x44480000,
    0x449C4000, 0x459C4000, 0x3ECCCCCD, 0x0,        0x0,        0x0,        0x0,
    0x428C0000, 0xC2340000, 0x42700000, 0x42700000, 0x3E800000, 0x3E800000, 0x3E19999A,
    0x3E19999A, 0x43340000, 0x42B40000, 0x3ECCCCCD, 0x3E666666, 0x3D4CCCCD, 0x3E666666};
u32 D_8080A934_bsfirstp[35] = {
    0x42000000, 0x41E00000, 0x41F00000, 0x425C0000, 0x42C80000, 0x428C0000, 0x43160000,
    0x42960000, 0xC528C000, 0xC5A8C000, 0x41C80000, 0x44160000, 0x3E800000, 0x44160000,
    0x447A0000, 0x453B8000, 0x3ECCCCCD, 0x43160000, 0x453B8000, 0x459C4000, 0xC59C4000,
    0x428C0000, 0xC2340000, 0x42700000, 0x42700000, 0x3E800000, 0x3E800000, 0x3E19999A,
    0x3E19999A, 0x43340000, 0x42B40000, 0x3ECCCCCD, 0x3E666666, 0x3D4CCCCD, 0x3E666666};
u32 D_8080A9C0_bsfirstp[35] = {
    0x42180000, 0x42000000, 0x41F00000, 0x425C0000, 0x42C80000, 0x42700000, 0x43160000,
    0x42960000, 0xC528C000, 0xC5A8C000, 0x41C80000, 0x44160000, 0x3E800000, 0x44160000,
    0x447A0000, 0x453B8000, 0x3ECCCCCD, 0x43160000, 0x453B8000, 0x459C4000, 0xC59C4000,
    0x428C0000, 0xC2340000, 0x42700000, 0x42700000, 0x3E800000, 0x3E800000, 0x3E19999A,
    0x3E19999A, 0x43340000, 0x42B40000, 0x3ECCCCCD, 0x3E666666, 0x3D4CCCCD, 0x3E666666};
u32 D_8080AA4C_bsfirstp[35] = {
    0x41A00000, 0x41A00000, 0x41A00000, 0x42200000, 0x42700000, 0x42480000, 0x42F00000,
    0x42700000, 0xC528C000, 0xC5A8C000, 0x41C80000, 0x44480000, 0x3E800000, 0x44480000,
    0x447A0000, 0x457A0000, 0x3ECCCCCD, 0x43160000, 0x453B8000, 0x459C4000, 0xC59C4000,
    0x428C0000, 0xC2340000, 0x42700000, 0x42700000, 0x3E800000, 0x3E800000, 0x3E19999A,
    0x3E19999A, 0x43700000, 0x42F00000, 0x3ECCCCCD, 0x3E666666, 0x3D4CCCCD, 0x3E666666};
u32 D_8080AAD8_bsfirstp[35] = {
    0x42300000, 0x42100000, 0x41F00000, 0x425C0000, 0x42F00000, 0x42700000, 0x43160000,
    0x42960000, 0xC528C000, 0xC5A8C000, 0x41C80000, 0x44160000, 0x3E800000, 0x44160000,
    0x447A0000, 0x453B8000, 0x3ECCCCCD, 0x43160000, 0x453B8000, 0x459C4000, 0xC59C4000,
    0x428C0000, 0xC2340000, 0x42700000, 0x42700000, 0x3E800000, 0x3E800000, 0x3E19999A,
    0x3E19999A, 0x43340000, 0x42B40000, 0x3ECCCCCD, 0x3E666666, 0x3D4CCCCD, 0x3E666666};
u32 D_8080AB64_bsfirstp[35] = {
    0x42820000, 0x425C0000, 0x42200000, 0x42A00000, 0x43160000, 0x42C80000, 0x430C0000,
    0x428C0000, 0xC528C000, 0xC5A8C000, 0x41C80000, 0x43C80000, 0x3E800000, 0x43C80000,
    0x447A0000, 0x44FA0000, 0x3ECCCCCD, 0x43160000, 0x43960000, 0x459C4000, 0xC59C4000,
    0x428C0000, 0xC2340000, 0x42700000, 0x42700000, 0x3E800000, 0x3E800000, 0x3E19999A,
    0x3E19999A, 0x42F00000, 0x42700000, 0x3ECCCCCD, 0x3E666666, 0x3D4CCCCD, 0x3E666666};
int D_8080ABF0_bsfirstp[13] = {(u32) &D_8080A8A8_bsfirstp,
                               (u32) &D_8080A934_bsfirstp,
                               (u32) &D_8080A9C0_bsfirstp,
                               (u32) &D_8080AA4C_bsfirstp,
                               (u32) &D_8080AAD8_bsfirstp,
                               (u32) &D_8080AB64_bsfirstp,
                               0x8010008,
                               0x80100,
                               0x8000401,
                               0x40008,
                               0x1000800,
                               0x10020010,
                               0x0};
int D_8080AC24_bsfirstp[28] = {
    0x0,        0x45EA6000, 0x3DCCCCCD, 0x3E4CCCCD, 0x0,        0x459C4000, 0x3EB33333,
    0x3F333333, 0x0,        0x459C4000, 0x3E4CCCCD, 0x3ECCCCCD, 0x1,        0x453B8000,
    0x3E4CCCCD, 0x3ECCCCCD, 0x1,        0x453B8000, 0x3F800000, 0x3F800000, 0x1,
    0x453B8000, 0x3EB33333, 0x3F333333, 0x0,        0x462FC800, 0x3D99999A, 0x3D99999A};
u8 D_8080AC94_bsfirstp[100] = {
    0x30, 0x30, 0x0,  0x0,  0x0, 0x0,  0x0, 0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,
    0x64, 0x0,  0x0,  0x0,  0x0, 0x0,  0x0, 0x0,  0x0,  0x0,  0x0,  0x1,  0xFF, 0x0,  0x64,
    0x0,  0x32, 0x0,  0x32, 0x0, 0x19, 0x0, 0xA,  0x0,  0xA,  0x1,  0xFF, 0x0,  0x64, 0x0,
    0x32, 0x0,  0x32, 0x0,  0x0, 0x0,  0x0, 0x0,  0x0,  0x1,  0xFF, 0x0,  0x64, 0x0,  0x32,
    0x0,  0x0,  0x0,  0x0,  0x0, 0x0,  0x0, 0xA,  0x1,  0xFF, 0x0,  0x64, 0x0,  0x0,  0x0,
    0x32, 0x0,  0x0,  0x0,  0xA, 0x0,  0x0, 0x1,  0xFF, 0x0,  0x64, 0x0,  0x0,  0x0,  0x32,
    0x0,  0x19, 0x0,  0x0,  0x0, 0x0,  0x1, 0xFF, 0x0,  0x0};
Mass43EggAimRecord D_8080ACF8_bsfirstp[6] = {
    0x7111, 0x1111, 0x1111, 0x1111, 0x1111, 0x1000, 0x0,    0x7664, 0x4332, 0x2552, 0x2111,
    0x1533, 0x4000, 0x0,    0x7223, 0x3332, 0x2312, 0x2111, 0x1133, 0x2000, 0x0,    0x7666,
    0x6112, 0x2212, 0x2111, 0x1111, 0x2000, 0x0,    0x7555, 0x5113, 0x3313, 0x3111, 0x1111,
    0x3000, 0x0,    0x7444, 0x4113, 0x3313, 0x3111, 0x1111, 0x3000, 0x0};
Mass43EggAimRecord D_8080AD4C_bsfirstp[6] = {
    0x7111, 0x1111, 0x1111, 0x1111, 0x1111, 0x1000, 0x0,    0x7661, 0x1115, 0x5344, 0x3232,
    0x2423, 0x5000, 0x0,    0x7331, 0x1112, 0x2233, 0x3132, 0x2213, 0x2000, 0x0,    0x7661,
    0x1112, 0x2166, 0x2121, 0x1112, 0x2000, 0x0,    0x7551, 0x1113, 0x3155, 0x3131, 0x1113,
    0x3000, 0x0,    0x7441, 0x1113, 0x3144, 0x3131, 0x1113, 0x3000, 0x0};
Mass43EggAimRecord D_8080ADA0_bsfirstp[6] = {
    0x7111, 0x1111, 0x1111, 0x1111, 0x1111, 0x1000, 0x0,    0x7556, 0x6344, 0x5211, 0x1332,
    0x2412, 0x3000, 0x0,    0x7332, 0x2322, 0x3311, 0x1112, 0x2313, 0x2000, 0x0,    0x7226,
    0x6111, 0x6211, 0x6112, 0x2112, 0x1000, 0x0,    0x7335, 0x5111, 0x5311, 0x5113, 0x3113,
    0x1000, 0x0,    0x7334, 0x4111, 0x4311, 0x4113, 0x3113, 0x1000, 0x0};
u8 D_8080ADF4_bsfirstp[80] = {
    0x9, 0x82, 0xC, 0x3A, 0x9, 0x82, 0xC, 0x3B, 0x9, 0x82, 0xC, 0x3C, 0x9, 0x82, 0xC, 0x3D,
    0x9, 0x84, 0xC, 0x42, 0x9, 0x84, 0xC, 0x43, 0x9, 0x84, 0xC, 0x44, 0x9, 0x84, 0xC, 0x45,
    0x9, 0x86, 0xC, 0x4A, 0x9, 0x86, 0xC, 0x4B, 0x9, 0x86, 0xC, 0x4C, 0x9, 0x86, 0xC, 0x4D,
    0x9, 0x88, 0xC, 0x52, 0x9, 0x88, 0xC, 0x53, 0x9, 0x88, 0xC, 0x54, 0x9, 0x88, 0xC, 0x55,
    0x9, 0x8D, 0xC, 0x56, 0x9, 0x8D, 0xC, 0x57, 0x9, 0x8D, 0xC, 0x58, 0x9, 0x8D, 0xC, 0x59};
u8 D_8080AE44_bsfirstp[160] = {
    0x0, 0x0, 0x9, 0x83, 0x0, 0x0, 0xC, 0x3E, 0x0, 0x0, 0x9, 0x83, 0x0, 0x0, 0xC, 0x3F,
    0x0, 0x0, 0x9, 0x83, 0x0, 0x0, 0xC, 0x40, 0x0, 0x0, 0x9, 0x83, 0x0, 0x0, 0xC, 0x41,
    0x0, 0x0, 0x9, 0x85, 0x0, 0x0, 0xC, 0x46, 0x0, 0x0, 0x9, 0x85, 0x0, 0x0, 0xC, 0x47,
    0x0, 0x0, 0x9, 0x85, 0x0, 0x0, 0xC, 0x48, 0x0, 0x0, 0x9, 0x85, 0x0, 0x0, 0xC, 0x49,
    0x0, 0x0, 0x9, 0x87, 0x0, 0x0, 0xC, 0x4E, 0x0, 0x0, 0x9, 0x87, 0x0, 0x0, 0xC, 0x4F,
    0x0, 0x0, 0x9, 0x87, 0x0, 0x0, 0xC, 0x50, 0x0, 0x0, 0x9, 0x87, 0x0, 0x0, 0xC, 0x51,
    0x0, 0x0, 0x9, 0x89, 0x0, 0x0, 0x0, 0x0,  0x0, 0x0, 0x9, 0x8A, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x9, 0x8B, 0x0, 0x0, 0x0, 0x0,  0x0, 0x0, 0x9, 0x8C, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x9, 0x8E, 0x0, 0x0, 0x0, 0x0,  0x0, 0x0, 0x9, 0x8F, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x9, 0x90, 0x0, 0x0, 0x0, 0x0,  0x0, 0x0, 0x9, 0x91, 0x0, 0x0, 0x0, 0x0};
u32 D_8080AEE4_bsfirstp[20] = {0x26C0003,  0x40F00000, 0x3180000,  0x40800000, 0x3190000,
                               0x4039999A, 0x26C0003,  0x3F800000, 0x3190000,  0x4039999A,
                               0x26C0003,  0x3F800000, 0x3190000,  0x4039999A, 0x3180000,
                               0x40800000, 0x26C0003,  0x40A00000, 0x1,        0x0};
u32 D_8080AF34_bsfirstp[6] = {0x47F0003, 0x40F00000, 0x4960000, 0x41000000, 0x1, 0x0};
u32 D_8080AF4C_bsfirstp[6] = {0x4E90003, 0x40F00000, 0x4EA0000, 0x41000000, 0x1, 0x0};
u32 D_8080AF64_bsfirstp[20] = {0x4D20003,  0x40F00000, 0x4D10000,  0x40800000, 0x4D20000,
                               0x4039999A, 0x4D20003,  0x3F800000, 0x4D20000,  0x4039999A,
                               0x4D20003,  0x3F800000, 0x4D20000,  0x4039999A, 0x4D10000,
                               0x40800000, 0x4D20003,  0x40A00000, 0x1,        0x0};
int D_8080AFB4_bsfirstp[6] = {0x0,
                              (u32) &D_8080AEE4_bsfirstp,
                              (u32) &D_8080AF34_bsfirstp,
                              (u32) &D_8080AF34_bsfirstp,
                              (u32) &D_8080AF4C_bsfirstp,
                              (u32) &D_8080AF64_bsfirstp};
s16 D_8080AFCC_bsfirstp[6][4] = {0xAD,  0x0, 0x40F0, 0x0,     0x272, 0x0, 0x3F80, 0x0,
                                 0x477, 0x0, 0x40CD, 0x1EB8,  0x477, 0x0, 0x40CD, 0x1EB8,
                                 0x4E2, 0x0, 0x4099, -0x6666, 0x4D6, 0x0, 0x4040, 0x0};
s16 D_8080AFFC_bsfirstp[6][4] = {0x3D4C, -0x3333, 0x3EE6, 0x6666,  0x3D4C, -0x3333,
                                 0x3EF0, -0x5C29, 0x3D4C, -0x3333, 0x3EF0, -0x5C29,
                                 0x3D4C, -0x3333, 0x3EF0, -0x5C29, 0x3D4C, -0x3333,
                                 0x3EF0, -0x5C29, 0x3D4C, -0x3333, 0x3EF0, -0x5C29};
s16 D_8080B02C_bsfirstp[6] = {0x0, 0x26C, 0x47F, 0x47F, 0x4E9, 0x4D0};
s32 D_8080B038_bsfirstp[18] = {0xA70000,   0x3F800000, 0x3F0A3D71, 0x2710000,  0x40000000,
                               0x3F19999A, 0x4780000,  0x40000000, 0x3F19999A, 0x4780000,
                               0x40000000, 0x3F19999A, 0x4E30000,  0x40000000, 0x3F19999A,
                               0x4D70000,  0x40000000, 0x3F19999A};
s32 D_8080B080_bsfirstp[18] = {0xA60000,   0x3F0A3D71, 0x3EB33333, 0x2700000,  0x3F800000,
                               0x3EE147AE, 0x4790000,  0x3F800000, 0x3EE147AE, 0x4790000,
                               0x3F800000, 0x3EE147AE, 0x4E10000,  0x3F800000, 0x3EE147AE,
                               0x4D50000,  0x3F800000, 0x3EE147AE};
s32 D_8080B0C8_bsfirstp[10] = {0x2750000,  0x3F666666, 0x47E0000,  0x3F23D70A, 0x47E0000,
                               0x3F23D70A, 0x4E80000,  0x3F800000, 0x4CF0000,  0x3F666666};
s32 D_8080B0F0_bsfirstp[10] = {0x2730000,  0x3F4CCCCD, 0x47A0000,  0x3FA00000, 0x47A0000,
                               0x3FA00000, 0x4DE0000,  0x3F000000, 0x4D80000,  0x3F4CCCCD};
s32 D_8080B118_bsfirstp[10] = {0x5050000,  0x3F99999A, 0x53D0000,  0x3FF33333, 0x53D0000,
                               0x3FF33333, 0x5070000,  0x3FC00000, 0x5030000,  0x3FF33333};
s32 D_8080B140_bsfirstp[10] = {0x2740000,  0x40000000, 0x47B0000,  0x40128F5C, 0x47B0000,
                               0x40128F5C, 0x4E40000,  0x40266666, 0x4D90000,  0x40000000};
s32 D_8080B168_bsfirstp[10] = {0x5060000,  0x3F333333, 0x53E0000,  0x3F333333, 0x53E0000,
                               0x3F333333, 0x5080000,  0x3F333333, 0x5040000,  0x3F666666};
s32 D_8080B190_bsfirstp[10] = {0x31A0000,  0x3F8CCCCD, 0x47C0000,  0x400CCCCD, 0x47C0000,
                               0x400CCCCD, 0x4E50000,  0x3F99999A, 0x4DA0000,  0x3F8CCCCD};
s32 D_8080B1B8_bsfirstp[10] = {0x26C0000,  0x3F800000, 0x47F0000,  0x3F800000, 0x47F0000,
                               0x3F800000, 0x4E90000,  0x3F800000, 0x4D00000,  0x3F800000};
s32 D_8080B1E0_bsfirstp[10] = {0x3140000,  0x3F800000, 0x4A20000,  0x3F800000, 0x4A20000,
                               0x3F800000, 0x4E00000,  0x3F800000, 0x4D40000,  0x3F800000};
s32 D_8080B208_bsfirstp[10] = {0x26D0000,  0x3F800000, 0x4970000,  0x3F800000, 0x4970000,
                               0x3F800000, 0x4EB0000,  0x3F800000, 0x4CC0000,  0x3F800000};
s32 D_8080B230_bsfirstp[10] = {0x3150000,  0x3F666666, 0x4A30000,  0x3F800000, 0x4A30000,
                               0x3F800000, 0x4DF0000,  0x3F800000, 0x4D30000,  0x3F666666};
s32 D_8080B258_bsfirstp[10] = {0x26E0000,  0x3ECCCCCD, 0x47D0000,  0x3E800000, 0x47D0000,
                               0x3E800000, 0x4E60000,  0x3ECCCCCD, 0x4CD0000,  0x3ECCCCCD};
u32 D_8080B280_bsfirstp[24] = {0x4A57FFF, 0x3F800000, 0x43E7FFF, 0x3F800000, 0x5907FFF, 0x3F800000,
                               0x5977FFF, 0x3F800000, 0x5917FFF, 0x3F800000, 0x58F7FFF, 0x3F800000,
                               0x58F7FFF, 0x3F800000, 0x43E7FFF, 0x3F800000, 0x42A55F0, 0x3F800000,
                               0x5A155F0, 0x3F800000, 0x0,       0x0,        0x0,       0x0};
u32 D_8080B2E0_bsfirstp[24] = {0x4A57FFF, 0x3FA00000, 0x43E7FFF, 0x3FAA3D71, 0x5907FFF, 0x3FA00000,
                               0x5977FFF, 0x3FA00000, 0x5917FFF, 0x3FA00000, 0x58F7FFF, 0x3FA00000,
                               0x58F7FFF, 0x3FA00000, 0x43E7FFF, 0x3FA00000, 0x51155F0, 0x3F800000,
                               0x5A155F0, 0x3F933333, 0x50F55F0, 0x3F800000, 0x50E55F0, 0x3F800000};
u32 D_8080B340_bsfirstp[24] = {0x4A57FFF, 0x3FA00000, 0x43E7FFF, 0x3FAA3D71, 0x5907FFF, 0x3FA00000,
                               0x5977FFF, 0x3FA00000, 0x5917FFF, 0x3FA00000, 0x58F7FFF, 0x3FA00000,
                               0x58F7FFF, 0x3FA00000, 0x43E7FFF, 0x3FA00000, 0x4F255F0, 0x3F800000,
                               0x5A155F0, 0x3FA00000, 0x4F27FFF, 0x3FC00000, 0x4F27FFF, 0x3F333333};
u32 D_8080B3A0_bsfirstp[24] = {0x4A57FFF, 0x3FA00000, 0x43E7FFF, 0x3FAA3D71, 0x5907FFF, 0x3FA00000,
                               0x5977FFF, 0x3FA00000, 0x5917FFF, 0x3FA00000, 0x58F7FFF, 0x3FA00000,
                               0x58F7FFF, 0x3FA00000, 0x43E7FFF, 0x3FA00000, 0x68C7FFF, 0x3F800000,
                               0x5A155F0, 0x3FA66666, 0x68D7FFF, 0x3F800000, 0x6837FFF, 0x3F4CCCCD};
u32 D_8080B400_bsfirstp[23] = {0x4A57FFF, 0x3FA00000, 0x43E7FFF, 0x3FAA3D71, 0x5907FFF, 0x3FA00000,
                               0x5977FFF, 0x3FA00000, 0x5917FFF, 0x3FA00000, 0x58F7FFF, 0x3FA00000,
                               0x58F7FFF, 0x3FA00000, 0x43E7FFF, 0x3FA00000, 0x4857FFF, 0x3F800000,
                               0x5A155F0, 0x3F99999A, 0x48B7FFF, 0x3F800000, 0x4977FFF};
FirstPersonAnimation *D_8080B45C_bsfirstp[6] = {
    (void *) 0x3F800000,           (void *) &D_8080B280_bsfirstp, (void *) &D_8080B2E0_bsfirstp,
    (void *) &D_8080B340_bsfirstp, (void *) &D_8080B3A0_bsfirstp, (void *) &D_8080B400_bsfirstp};
s32 D_8080B474_bsfirstp[4] = {(u32) func_808031D0_bsfirstp, (u32) func_80803134_bsfirstp,
                              (u32) func_80803204_bsfirstp, (u32) _bsfirstp_entrypoint_26};
s32 D_8080B484_bsfirstp[4] = {(u32) func_80803320_bsfirstp, (u32) func_808032C0_bsfirstp,
                              (u32) func_80803340_bsfirstp, (u32) _bsfirstp_entrypoint_26};
s32 D_8080B494_bsfirstp[4] = {(u32) func_80803784_bsfirstp, (u32) func_808036F0_bsfirstp,
                              (u32) func_808037E4_bsfirstp, (u32) func_80803828_bsfirstp};
s32 D_8080B4A4_bsfirstp[2] = {0x13052B, 0x180000};
f32 D_8080B4AC_bsfirstp[3] = {-1.75f, 74.0f, 3.8f};
f32 D_8080B4B8_bsfirstp[3] = {-0.32f, 34.3f, 1.32f};
f32 D_8080B4C4_bsfirstp[3] = {4.1f, 4e+01f, 1.2e+02f};
s32 D_8080B4D0_bsfirstp[4] = {(u32) func_80803F6C_bsfirstp, (u32) func_80803E84_bsfirstp,
                              (u32) func_80803F94_bsfirstp, (u32) _bsfirstp_entrypoint_26};
s32 D_8080B4E0_bsfirstp[4] = {(u32) func_80804210_bsfirstp, (u32) func_808041D0_bsfirstp,
                              (u32) func_80804238_bsfirstp, (u32) func_808058F0_bsfirstp};
s32 D_8080B4F0_bsfirstp[4] = {(u32) func_8080436C_bsfirstp, (u32) func_8080432C_bsfirstp,
                              (u32) func_80804394_bsfirstp, (u32) func_808058F0_bsfirstp};
s32 D_8080B500_bsfirstp[4] = {(u32) func_80804B84_bsfirstp, (u32) func_80804B10_bsfirstp,
                              (u32) func_80804BA4_bsfirstp, (u32) func_80804A64_bsfirstp};
s32 D_8080B510_bsfirstp[4] = {(u32) func_80804D80_bsfirstp, (u32) func_80804D18_bsfirstp,
                              (u32) func_80804DA0_bsfirstp, (u32) func_80804A64_bsfirstp};
s32 D_8080B520_bsfirstp[4] = {(u32) func_80804EB4_bsfirstp, (u32) func_80804E1C_bsfirstp,
                              (u32) func_80804ED4_bsfirstp, (u32) func_80804A64_bsfirstp};
s32 D_8080B530_bsfirstp[4] = {(u32) func_80804FB4_bsfirstp, (u32) func_80804F28_bsfirstp,
                              (u32) func_80804FD4_bsfirstp, (u32) func_80804A64_bsfirstp};
s32 D_8080B540_bsfirstp[4] = {(u32) func_808050B0_bsfirstp, (u32) func_80805058_bsfirstp,
                              (u32) func_808050D8_bsfirstp, (u32) _bsdrone_entrypoint_3};
s32 D_8080B550_bsfirstp[4] = {(u32) func_8080519C_bsfirstp, (u32) func_8080511C_bsfirstp,
                              (u32) func_808051C4_bsfirstp, (u32) _bsdrone_entrypoint_3};
s32 D_8080B560_bsfirstp[4] = {(u32) func_80806CC0_bsfirstp, (u32) func_80806C58_bsfirstp,
                              (u32) func_80806D64_bsfirstp, (u32) func_80806D90_bsfirstp};
s32 D_8080B570_bsfirstp[4] = {(u32) func_80806E9C_bsfirstp, (u32) func_80806E0C_bsfirstp,
                              (u32) func_80806EC4_bsfirstp, (u32) func_80807024_bsfirstp};
s32 D_8080B580_bsfirstp[4] = {(u32) func_808071D8_bsfirstp, (u32) func_80807208_bsfirstp,
                              (u32) func_80807264_bsfirstp, 0x0};
s32 D_8080B590_bsfirstp[4] = {(u32) func_808074D0_bsfirstp, (u32) func_80807504_bsfirstp,
                              (u32) func_8080762C_bsfirstp, (u32) func_80807394_bsfirstp};
s32 D_8080B5A0_bsfirstp[4] = {(u32) func_808077AC_bsfirstp, (u32) func_808077E0_bsfirstp,
                              (u32) func_80807864_bsfirstp, (u32) func_80807394_bsfirstp};
s32 D_8080B5B0_bsfirstp[4] = {(u32) func_808088A4_bsfirstp, (u32) func_80808848_bsfirstp,
                              (u32) func_808088D0_bsfirstp, (u32) _bsfirstp_entrypoint_26};
s32 D_8080B5C0_bsfirstp[4] = {(u32) func_80808A8C_bsfirstp, (u32) func_80808A24_bsfirstp,
                              (u32) func_80808AAC_bsfirstp, (u32) _bsfirstp_entrypoint_26};
s32 D_8080B5D0_bsfirstp[4] = {(u32) func_80809384_bsfirstp, (u32) func_80809334_bsfirstp,
                              (u32) func_808093A4_bsfirstp, (u32) _bsfirstp_entrypoint_26};
