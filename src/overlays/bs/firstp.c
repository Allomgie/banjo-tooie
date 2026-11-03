#include "bs/firstp.h"
#include "overlays/ba/playerstate.h"
#include "core2/anctrl.h"
#include "overlays/ba/stick.h"
#include "overlays/ba/playerstate.h"
#include "core2/anctrl.h"

#define F(p, o) (*(f32 *)((u8 *)(p) + (o)))
extern void baanim_playForDuration_onceSmooth(PlayerState *, s32, f32);
extern void func_8009E55C(PlayerState *, s32, f32);
extern void _batimer_set(PlayerState *, s32, f32);
extern AnimCtrl *func_8008D04C();
extern void anctrl_reset(AnimCtrl *);
extern void anctrl_setIndex(AnimCtrl *, AssetId);
extern void anctrl_setDuration(AnimCtrl *, f32);
extern void anctrl_setStart(AnimCtrl *, f32);
extern void anctrl_setPlaybackType(AnimCtrl *, s32);
extern void anctrl_start(AnimCtrl *);
extern void anctrl_setSmoothTransition(AnimCtrl *, s32);
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
extern void func_8008B188(AnimCtrl *, s32);
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
typedef struct { u8 pad_0[0x18]; f32 components[4]; u8 pad_1[0x64]; s32 type; f32 strength; } FirstPersonBlend1459;
extern f32 D_8080A5B0_bsfirstp[][4];
extern void func_800E0AFC(void *, s32, f32, f32, f32, f32);
typedef struct { u8 local_0[0x2B]; u8 local_1; u8 local_2[3]; u8 local_3; } Mass47Firstp;
typedef struct { u8 pad_0[0x98]; f32 local_0; f32 local_1; } FirstPersonVolume1536;
extern void func_800C5148(s32, f32);
extern f32 func_800F2108(f32);
extern f32 mlAbsF(f32);
extern void func_80111590(void *, f32, f32, f32, f32);
void func_8010FD38(s32, f32);
extern u8 D_8080A5D0_bsfirstp[];
extern void _baeggcursor_entrypoint_10(u8 *, f32, f32);
extern f32 func_800F0DC0(f32, f32);
typedef struct { u8 pad_0[0xB8]; f32 position[2]; u8 pad_1[8]; f32 output[2]; } FirstPersonProjection;
extern f32 func_800A8AF0(s32);
extern f32 func_80013B7C(f32, f32);
extern f32 func_80013728(f32);
extern struct ActorLocal_FirstPerson { int unkA0; } ActorLocal_FirstPerson;
extern int D_8080ABF0_bsfirstp[];
extern int D_8080A890_bsfirstp[];
extern s16 D_8080AFFC_bsfirstp[][4];
extern int D_8080AFB4_bsfirstp[];
extern s16 D_8080AFCC_bsfirstp[][4];
extern s16 D_8080B02C_bsfirstp[];
extern s32 D_8080B038_bsfirstp;
extern s32 D_8080B080_bsfirstp;
extern s32 D_8080B1B8_bsfirstp;
extern s32 D_8080B1E0_bsfirstp;
extern s32 D_8080B208_bsfirstp;
extern s32 D_8080B230_bsfirstp;
extern s32 D_8080B258_bsfirstp;
extern s32 D_8080B0C8_bsfirstp;
extern s32 D_8080B0F0_bsfirstp;
extern s32 D_8080B118_bsfirstp;
extern s32 D_8080B140_bsfirstp;
extern s32 D_8080B168_bsfirstp;
extern s32 D_8080B190_bsfirstp;
extern int D_8080AC24_bsfirstp[];
typedef struct Mass43EggAimRecord { u16 local_0[7]; } Mass43EggAimRecord;
extern Mass43EggAimRecord D_8080ACF8_bsfirstp[];
extern Mass43EggAimRecord D_8080AD4C_bsfirstp[];
extern Mass43EggAimRecord D_8080ADA0_bsfirstp[];
extern u8 D_8080AC94_bsfirstp[100];
void _badeathmatch_entrypoint_10();
typedef struct { s16 animation; s16 enabled; f32 duration; } FirstPersonAnimation;
extern FirstPersonAnimation *D_8080B45C_bsfirstp[];
extern void func_8009DF18(PlayerState *, s16, f32, s16);
extern u8 D_8080ADF4_bsfirstp[];
extern u8 D_8080AE44_bsfirstp[];
extern void func_80094430(u8 *, f32);
extern void _badeathmatch_entrypoint_8(u8 *, f32);
extern u8 unk158[];
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
extern s32 D_8080B4A4_bsfirstp;
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
extern void anctrl_setSubrange(AnimCtrl *, f32, f32);
extern s32 D_8080B4D0_bsfirstp[];
typedef struct { s16 local_0; s16 pad_0; f32 local_1; } FirstPersonAnimationEvent;
extern void func_8009D89C(PlayerState *, f32);
extern void baphysics_set_target_horizontal_velocity(PlayerState *, f32);
extern s32 D_8080B4E0_bsfirstp[];
extern u8 unk15C[];
extern u8 unk184[];
extern s32 D_8080B4F0_bsfirstp[];
typedef struct Mass46FirstPersonTrend { f32 local_0; f32 local_1; f32 local_2; s32 local_3; f32 local_4; f32 local_5; f32 local_6; } Mass46FirstPersonTrend;
extern s32 baanim_isAt(PlayerState *, f32);
extern void func_8009DE38(PlayerState *, s32, f32);
extern void func_8009DB04(PlayerState *, s32, f32, s32);
extern s32 D_8080B500_bsfirstp[];
extern s32 D_8080B510_bsfirstp[];
extern s32 D_8080B520_bsfirstp[];
extern void baanim_playForDuration_onceSmoothStartingAt(void *param_0, int param_1, float param_2, int param_3);
extern s32 D_8080B530_bsfirstp[];
extern s32 D_8080B540_bsfirstp[];
extern s32 D_8080B550_bsfirstp[];
extern void func_8009BDAC(PlayerState *, f32);
extern f32 baphysics_get_target_horizontal_velocity(PlayerState *);
extern f32 func_8009BB18(PlayerState *);
extern f32 yaw_get();
extern f32 func_800EEFFC(f32 *);
extern f32 func_800F0E00(f32, f32);
typedef struct { u8 pad0[0x2C]; f32 unk2C; } FirstPersonScaleView;
extern f32 func_8009BB5C(PlayerState *);
extern f32 func_800138D0(f32);
typedef struct { f32 unk0; f32 unk4; f32 unk8; s32 unkC; } FpStick;
extern void baphysics_set_target_yaw(PlayerState *, f32);
typedef struct { u8 pad_0[0xC]; s32 local_0; u8 pad_1[0x1D8]; f32 local_1; f32 local_2; u8 pad_2[0x1C]; f32 local_3; } FirstPersonPitchBounds;
typedef struct { u8 pad_0[0x10]; s32 local_0; u8 pad_1[0x170]; f32 local_1; u8 pad_2[0x60]; f32 local_2; f32 local_3; u8 pad_3[0x18]; f32 local_4; f32 local_5; } FirstPersonAim1517;
typedef struct { u8 pad[0x8]; f32 v; } FS_8;
typedef struct { u8 pad_0[0x218]; u8 local_0; } FirstPersonMode;
extern void func_800A16BC();
typedef struct { u8 pad_0[8]; s32 state; u8 pad_1[0x58]; s32 handle; } FirstPersonExitState;
extern s32 D_8080B560_bsfirstp[];
extern f32 func_80099A34(PlayerState *);
extern s32 D_8080B570_bsfirstp[];
extern s32 D_8080B580_bsfirstp[];
extern s32 D_8080B590_bsfirstp[];
extern s32 D_8080B5A0_bsfirstp[];
extern void func_80093230(PlayerState *, f32);
typedef struct { s16 values[2]; } FirstPersonSoundPair;
extern s32 _gcstatusDll_entrypoint_13(s32);
extern void _gcstatusDll_entrypoint_3(s32, s32);
typedef struct { s32 local_0; u8 pad_0[4]; s32 local_1; u8 pad_1[0x58]; s32 local_2; s32 local_3; } FirstPersonInit1493;
extern void func_800947EC(PlayerState *, s32, s32);
typedef struct { u8 pad_0[0x6C]; s16 local_0[3]; u8 local_1; } FirstPersonCamera1527;
extern s32 D_8080B5B0_bsfirstp[];
extern s32 D_8080B5C0_bsfirstp[];
typedef struct FirstPersonScriptStep1612 { s16 local_0; s16 local_1; f32 local_2; } FirstPersonScriptStep1612;
extern f32 D_8080A650_bsfirstp[][5];
extern void baphysics_set_horizontal_velocity(PlayerState *, f32, f32);
extern void baphysics_set_vertical_velocity(PlayerState *, f32);
extern void baphysics_set_gravity(PlayerState *, f32);
typedef struct { u8 pad_0[0x104]; s32 local_0; s32 local_1; f32 local_2; } FirstPersonTimer;
typedef struct { f32 local_0[5]; } FirstPersonTimerPreset;
extern FirstPersonTimerPreset D_8080A660_bsfirstp[];
typedef struct { u8 pad_0[8]; f32 local_1; } FirstPersonCameraOffset;
extern u8 *func_800D674C(s32);
extern void func_800E0050(u8 *, f32, s32, f32 *);
extern s32 D_8080B5D0_bsfirstp[];
extern f32 func_800F0D50(f32, f32, f32);
extern void func_800A2CE8(PlayerState *, f32, s32);
typedef struct FirstPersonAimLimits { u8 pad_0[0x168]; f32 local_0; f32 local_1; s32 local_2; u8 pad_1[0xBC]; f32 local_3; u8 pad_2[4]; f32 local_4; u8 pad_3[4]; f32 local_5; } FirstPersonAimLimits;
typedef struct FirstPersonImpactFlags { u32 pad_0 : 3; u32 local_0 : 1; u32 local_1 : 1; u32 pad_1 : 27; } FirstPersonImpactFlags;
extern void func_800963C0(PlayerState *, f32 *);
extern int func_800F1B78(f32 *, f32 *, f32, f32);
typedef struct { u8 pad0[8]; f32 unk8; s32 unkC; u8 pad10[4]; s32 unk14; u8 pad18[4]; f32 unk1C; u8 pad20[0x24]; f32 unk44; f32 unk48; } FpSub;
typedef struct { u8 pad_0[0xC]; s32 local_0; s32 local_1; s32 local_2; u8 pad_1[0x30]; f32 local_3; f32 local_4; } FirstPersonAcceleration;
extern f32 func_800F1CF0(f32 *, f32 *);
extern f32 sqrtf(f32);
extern f32 func_800136E4(f32);
extern f32 func_80013970(f32);
typedef struct { u8 pad_0[0x30]; f32 fraction; f32 upper; f32 lower; f32 right; f32 left; } FirstPersonSplit;
extern void *func_8009370C(PlayerState *);
extern void func_800E0AF0(void *, f32);
extern void *func_80092AD8(PlayerState *);
extern f32 func_800F1214(f32, f32, f32);
extern void func_8010D930(s32, s32, s32, void *);
extern s32 _baeggcursor_entrypoint_9(void *);
extern s32 _baeggcursor_entrypoint_2(void *);
extern u8 D_8080A630_bsfirstp[];
extern u8 D_8080A640_bsfirstp[];
typedef struct { u8 unused[0x14]; f32 first; f32 second; f32 third; } FirstPersonValues;
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
typedef struct { f32 local_0; f32 local_1; f32 local_2; f32 local_3; } FirstPersonMovementStep;
typedef struct { u8 pad_0[0x1CC]; FirstPersonMovementStep local_0; } FirstPersonMovementData;
extern void func_800EFCD8(f32 *, f32, f32);
typedef struct { f32 unk0; f32 unk4; f32 unk8[3]; } FpSpring;
extern void func_800EF04C(f32 *, f32 *);
extern void func_800EF3DC(f32 *, f32 *);
extern f32 func_800FF060(f32, f32 *, f32, f32, f32, f32);
extern f32 func_800137AC(f32);
extern void func_800EE7F8(f32 *, f32 *);
extern void func_800EFA20(f32 *, f32 *, f32);
extern f32 func_80013B70(f32, f32, f32);
typedef struct { u8 pad_0[0x1F0]; f32 local_0; u8 pad_1[0x1C]; f32 local_1; f32 local_2; } FirstPersonIntegrator1517;
extern void func_8009C128(s32, f32 *);
extern void func_800EE84C(f32 *, s32 *);
extern f32 func_800EEAA4(f32 *, f32 *);
extern s32 func_800F36D4(s32 *, s32 *);
extern void baflag_clear(Actor *, s32);
extern void baflag_set(Actor *, s32);
extern void func_8009E5A4(Actor *, s32, s32);
typedef struct { u8 pad_0[0x24C]; f32 local_0; f32 local_1; } FirstPersonYawStep;
extern void yaw_setIdeal(PlayerState *, f32);
extern void yaw_set(PlayerState *, f32);
typedef struct { u8 pad_0[0x14]; s32 unk14; u8 pad_1[8]; f32 unk20[3]; f32 unk2C[3]; f32 unk38[3]; f32 unk44; f32 unk48; u8 pad_2[4]; s32 unk50; } FirstpAim1828;
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
void func_8080800C_bsfirstp();
unsigned int func_808080A4_bsfirstp();
int func_808080B4_bsfirstp();
int func_808085A8_bsfirstp();
int func_80808B24_bsfirstp();
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
int func_808094A4_bsfirstp();
int func_808094F4_bsfirstp();
void func_80809684_bsfirstp();
int func_80809740_bsfirstp();
void func_808099A8_bsfirstp();
void func_808099B4_bsfirstp();
void func_80809A10_bsfirstp();
s32 func_80809C30_bsfirstp();
int func_80809C90_bsfirstp();
f32 func_80809D94_bsfirstp();
void func_80809F74_bsfirstp();
void func_8080A194_bsfirstp();
void func_8080A250_bsfirstp();
void func_80800978_bsfirstp();
void func_80800F14_bsfirstp();
void func_80801000_bsfirstp();
void func_80801E18_bsfirstp();
void func_80804488_bsfirstp();
void bsfirstp_entrypoint_26();
void func_8080649C_bsfirstp();
void func_80806588_bsfirstp();
void func_80808148_bsfirstp();
void func_808086B0_bsfirstp();
int func_80809540_bsfirstp();
void func_80809DD0_bsfirstp();
void func_8080A03C_bsfirstp();
extern void *D_exp_bsfirstp_entrypoint_26[];

s32 func_80800000_bsfirstp(u8 *param_0);
void func_80800040_bsfirstp();
void bsfirstp_entrypoint_0(PlayerState *param_0, f32 *param_1, f32 *param_2);
void bsfirstp_entrypoint_1(Actor *param_0, s32 param_1);
void func_80800190_bsfirstp(Actor *param_0);
int func_808001D0_bsfirstp(Actor *param_0);
void func_808001FC_bsfirstp();
int func_80800228_bsfirstp();
s32 func_80800264_bsfirstp(PlayerState *map_id, f32 exit_id);
s32 func_80800290_bsfirstp(s32 item_id, s32 param_1, s32 param_2);
void func_808002CC_bsfirstp(Actor *param_0, s32 param_1, f32 param_2, f32 param_3);
void func_80800340_bsfirstp(Actor *param_0, s32 param_1, f32 param_2, f32 param_3);
void func_808003B4_bsfirstp(Actor *param_0, s32 param_1, f32 param_2);
int func_80800424_bsfirstp(Actor *param_0, s32 param_1, f32 param_2);
void func_80800488_bsfirstp(Actor *param_0, s32 param_1, f32 param_2);
void func_808004F8_bsfirstp(u8 *param_0);
int func_8080053C_bsfirstp(Actor *param_0);
void func_8080056C_bsfirstp(PlayerState *param_0, f32 *local_2);
void func_808006DC_bsfirstp(PlayerState *param_0);
void func_80800830_bsfirstp();
s32 func_80800864_bsfirstp();
void func_80800888_bsfirstp(u8 *param_0, s32 param_1);
int func_808008B0_bsfirstp(PlayerState *param_0);
int func_80800900_bsfirstp(PlayerState *param_0, f32 param_1);
void func_80800A18_bsfirstp(PlayerState *param_0, void *param_1);
void func_80800B44_bsfirstp(PlayerState *param_0, void *param_1);
void func_80800C88_bsfirstp(PlayerState *param_0, void *param_1);
void func_80800D18_bsfirstp(PlayerState *param_0, void *param_1);
void func_808015C0_bsfirstp(s32 param_0, u8 *param_1, u8 *param_2);
f32 func_80801640_bsfirstp(s32 param_0);
void func_80801668_bsfirstp(u8 *param_0, f32 param_1);
void func_808016A0_bsfirstp(PlayerState *param_0);
void func_8080175C_bsfirstp(u8 *param_0);
void bsfirstp_entrypoint_2(PlayerState *param_0);
void func_8080187C_bsfirstp(Actor *param_0);
int func_808018E0_bsfirstp(Actor *param_0);
void func_80801928_bsfirstp(Actor *param_0);
int func_808019EC_bsfirstp(Actor *param_0);
void func_80801A34_bsfirstp(s32 arg0);
int func_80801A5C_bsfirstp(Actor *param_0);
int func_80801A98_bsfirstp(Actor *param_0);
int func_80801AC4_bsfirstp(s32 param_0);
void func_80801AEC_bsfirstp(s32 arg0);
int func_80801B0C_bsfirstp(s32 param_0, s32 *param_1, s32 *param_2);
s32 func_80801B64_bsfirstp();
void func_80801BDC_bsfirstp();
void func_80801C18_bsfirstp();
void func_80801D30_bsfirstp();
void func_80801D70_bsfirstp();
void func_80801DC0_bsfirstp(u8 *param_0);
f32 func_8080222C_bsfirstp(f32 param_0, f32 param_1, f32 param_2);
f32 func_80802304_bsfirstp(f32 param_0, f32 param_1, f32 param_2);
s32 func_80802444_bsfirstp(Actor *param_0);
int func_80802458_bsfirstp();
int func_80802484_bsfirstp();
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
void func_80802ED4_bsfirstp(void *param_0);
void func_80802F00_bsfirstp(s32 param_0);
void func_80802F20_bsfirstp(PlayerState *param_0);
void func_80803124_bsfirstp();
void func_80803134_bsfirstp(u8 *param_0);
void func_808031D0_bsfirstp(u8 *param_0);
void func_80803204_bsfirstp(u8 *param_0);
int bsfirstp_entrypoint_8(s32 param_0);
void func_808032C0_bsfirstp(PlayerState *param_0);
void func_80803320_bsfirstp(s32 param_0);
int func_80803340_bsfirstp(s32 param_0);
int bsfirstp_entrypoint_9(s32 param_0);
void bsfirstp_entrypoint_10(s32 param_0);
void func_808035EC_bsfirstp(PlayerState *param_0, f32 *param_1, f32 *param_2);
void func_808036F0_bsfirstp(u8 *param_0);
void func_80803760_bsfirstp(int param_0);
int func_80803784_bsfirstp(Actor *param_0);
int func_808037E4_bsfirstp(Actor *param_0);
void func_80803828_bsfirstp(u8 *param_0);
int bsfirstp_entrypoint_11(s32 param_0);
void bsfirstp_entrypoint_12(s32 param_0);
void bsfirstp_entrypoint_13(PlayerState *param_0, f32 *param_1, s16 param_2);
void func_80803A84_bsfirstp(PlayerState *param_0);
int func_80803B04_bsfirstp(s32 param_0);
void func_80803B58_bsfirstp(u8 *param_0, f32 param_1);
f32 func_80803B68_bsfirstp();
void bsfirstp_entrypoint_14(PlayerState *param_0);
s32 func_80803CD4_bsfirstp(PlayerState *param_0, s32 param_1, s32 param_2, s32 param_3, f32 *param_4);
void func_80803E84_bsfirstp(u8 *param_0);
void func_80803F6C_bsfirstp(s32 arg0);
void func_80803F94_bsfirstp(PlayerState *param_0);
int bsfirstp_entrypoint_15(s32 param_0);
void func_80804104_bsfirstp(PlayerState *param_0, FirstPersonAnimationEvent *param_1, FirstPersonAnimationEvent *param_2);
int func_808041D0_bsfirstp(Actor *param_0);
void func_80804210_bsfirstp(s32 arg0);
void func_80804238_bsfirstp(void *param_0);
int bsfirstp_entrypoint_16(s32 param_0);
int func_8080432C_bsfirstp(Actor *param_0);
void func_8080436C_bsfirstp(s32 arg0);
int func_80804394_bsfirstp(Actor *param_0);
int bsfirstp_entrypoint_17(s32 param_0);
void func_808045FC_bsfirstp(void *param_0, f32 param_1);
void func_808047EC_bsfirstp(Actor *param_0);
int func_8080483C_bsfirstp(Actor *param_0, s32 param_1);
int bsfirstp_entrypoint_18(Actor *param_0, s32 param_1);
void func_80804A34_bsfirstp(s32 arg0);
void func_80804A3C_bsfirstp(u8 *param_0);
void func_80804A64_bsfirstp(PlayerState *param_0);
int func_80804B10_bsfirstp(s32 param_0);
void func_80804B84_bsfirstp(s32 param_0);
void func_80804BA4_bsfirstp(PlayerState *param_0);
int bsfirstp_entrypoint_19(s32 param_0);
s32 func_80804D18_bsfirstp(long param_0);
void func_80804D80_bsfirstp(s32 param_0);
int func_80804DA0_bsfirstp(Actor *param_0);
int bsfirstp_entrypoint_20(s32 param_0);
s32 func_80804E1C_bsfirstp(s32 param_0);
void func_80804EB4_bsfirstp(s32 param_0);
int func_80804ED4_bsfirstp(Actor *param_0);
int bsfirstp_entrypoint_21(s32 param_0);
void func_80804F28_bsfirstp(Actor *param_0);
void func_80804FB4_bsfirstp(s32 param_0);
void func_80804FD4_bsfirstp(void *param_0);
int bsfirstp_entrypoint_22(s32 param_0);
int func_80805058_bsfirstp(Actor *param_0);
void func_808050B0_bsfirstp(s32 arg0);
void func_808050D8_bsfirstp(s32 arg0);
int bsfirstp_entrypoint_23(s32 param_0);
s32 func_8080511C_bsfirstp(s32 param_0);
void func_8080519C_bsfirstp(s32 arg0);
void func_808051C4_bsfirstp(s32 arg0);
int bsfirstp_entrypoint_24(s32 param_0);
void bsfirstp_entrypoint_25(void *param_0, f32 param_1);
s32 func_808052A4_bsfirstp(f32 *param_0, f32 *param_1);
f32 func_808052C8_bsfirstp(f32 *param_0, f32 param_1, f32 param_2, f32 param_3);
void func_80805380_bsfirstp(f32 *param_0, f32 param_1, f32 param_2, f32 param_3);
f32 func_8080549C_bsfirstp(f32 *pos, f32 vel, f32 dist, f32 *time, f32 dt);
f32 func_80805644_bsfirstp(f32 *p0, f32 p1, f32 p2, f32 *p3, f32 p4);
f32 func_808057C8_bsfirstp(f32 *param_0, f32 param_1, f32 param_2, f32 param_3, f32 param_4);
void func_808058F0_bsfirstp(PlayerState *param_0);
void func_80805F48_bsfirstp(s32 arg0);
void func_80805F68_bsfirstp();
void bsfirstp_entrypoint_27(u8 *param_0);
f32 func_80806130_bsfirstp(void *param_0);
f32 func_8080613C_bsfirstp(void *param_0);
s32 func_80806148_bsfirstp(s32 param_0, s32 param_1);
f32 func_80806170_bsfirstp(void *param_0, f32 param_1);
void func_8080633C_bsfirstp(PlayerState *param_0, f32 param_1);
void func_80806774_bsfirstp();
void func_808067B0_bsfirstp(u8 *param_0);
void func_808067E8_bsfirstp(u8 *param_0);
f32 func_808069BC_bsfirstp();
f32 func_80806AD0_bsfirstp(PlayerState *param_0, f32 param_1, f32 param_2);
void bsfirstp_entrypoint_28(u8 *param_0, u8 *param_1);
void func_80806BA0_bsfirstp(PlayerState *param_0);
s32 func_80806C58_bsfirstp(s32 param_0);
void func_80806CC0_bsfirstp(PlayerState *param_0);
void func_80806D64_bsfirstp(s32 param_0);
void func_80806D90_bsfirstp(PlayerState *param_0);
int bsfirstp_entrypoint_29(s32 param_0);
void func_80806E0C_bsfirstp(u8 *param_0);
void func_80806E9C_bsfirstp(s32 arg0);
void func_80806EC4_bsfirstp(PlayerState *param_0);
void func_80807024_bsfirstp(PlayerState *param_0);
int bsfirstp_entrypoint_30(s32 param_0);
void func_808071D8_bsfirstp(s32 arg0);
int func_80807208_bsfirstp(s32 param_0);
void func_80807264_bsfirstp(Actor *param_0);
int bsfirstp_entrypoint_31(s32 param_0);
int func_808072C8_bsfirstp(Actor *param_0);
s32 func_80807328_bsfirstp(s32 param_0);
void func_80807394_bsfirstp(Actor *param_0);
int func_808074D0_bsfirstp(Actor *param_0);
void func_80807504_bsfirstp(u8 *param_0);
void func_8080762C_bsfirstp(u8 *param_0);
int bsfirstp_entrypoint_32(s32 param_0);
int func_808077AC_bsfirstp(Actor *param_0);
s32 func_808077E0_bsfirstp(s32 param_0);
void func_80807864_bsfirstp(Actor *param_0);
int bsfirstp_entrypoint_33(s32 param_0);
void func_808078F4_bsfirstp(PlayerState *param_0);
void func_80807A70_bsfirstp(PlayerState *param_0);
void func_80807AF8_bsfirstp(PlayerState *param_0);
void func_80807C8C_bsfirstp();
void func_80807D48_bsfirstp(s32 arg0);
void func_80807DD4_bsfirstp();
s32 func_80807F5C_bsfirstp();
void func_80807F9C_bsfirstp();
void func_80807FBC_bsfirstp();
void func_80808084_bsfirstp(s32 arg0);
void func_80808100_bsfirstp();
void func_808084AC_bsfirstp(f32 *param_0, f32 param_1);
void func_8080853C_bsfirstp(f32 *param_0, f32 param_1);
int func_80808630_bsfirstp(s32 param_0);
int func_80808678_bsfirstp(s32 param_0, s32 param_1);
void func_80808848_bsfirstp(s32 param_0);
void func_808088A4_bsfirstp(s32 arg0);
void func_808088D0_bsfirstp(PlayerState *param_0);
int bsfirstp_entrypoint_34(s32 param_0);
void func_80808A24_bsfirstp(u8 *param_0);
void func_80808A8C_bsfirstp(s32 param_0);
void func_80808AAC_bsfirstp(s32 param_0);
int bsfirstp_entrypoint_35(s32 param_0);
void func_808090D8_bsfirstp();
s32 func_80809334_bsfirstp(void *param_0);
void func_80809384_bsfirstp(s32 param_0);
void func_808093A4_bsfirstp(u8 *param_0);
int bsfirstp_entrypoint_36(s32 param_0);
s32 func_80809900_bsfirstp();
f32 func_80809938_bsfirstp();
void func_8080995C_bsfirstp();
void func_80809A7C_bsfirstp();
void func_80809AF8_bsfirstp(PlayerState *param_0, f32 param_1, f32 param_2, f32 param_3);
int bsfirstp_entrypoint_37(Actor *param_0);
void func_80809CB4_bsfirstp();
void func_80809CD8_bsfirstp();
void func_80809CF8_bsfirstp();
s32 func_80809D24_bsfirstp();
s32 func_80809D6C_bsfirstp();
void func_80809DA0_bsfirstp();
s32 func_80809EF8_bsfirstp(f32 *param_0, f32 *param_1, s32 param_2);
s32 func_80800000_bsfirstp(u8 *param_0) {
  s32 * _xl;
    s32 sp1C;
    s32 temp_a0;
    _bastatemem_entrypoint_0(param_0, 0x2A8);
    temp_a0 = (_xl = *(s32 *)(param_0 + 0x188));
    sp1C = temp_a0;
    aligned8_memset(temp_a0, 0, 0x2A8);
    return sp1C;
}

void func_80800040_bsfirstp()
{
    _bastatemem_entrypoint_1();
}

void bsfirstp_entrypoint_0(PlayerState *param_0, f32 *param_1, f32 *param_2)
{
    f32 *local_0;
    f32 *local_1;

    local_0 = (f32 *)param_0->kazfly;
    local_1 = func_80802484_bsfirstp(param_0);
    param_2[0] = local_1[7];
    param_2[1] = local_1[8];
    param_2[2] = local_1[9];
    param_1[0] = local_1[4] + local_0[6];
    param_1[1] = local_1[5] + local_0[7];
    param_1[2] = local_1[6];
    func_8080800C_bsfirstp((s32)param_0);
}

void bsfirstp_entrypoint_1(Actor *param_0, s32 param_1)
{
  s32 var_s0;
  s32 var_s0_2;
  switch (param_1)
  {
    case 0:
      var_s0 = baanim_getAnimCtrlPtr(param_0);
      var_s0_2 = var_s0;
      func_80801000_bsfirstp(param_0);
      func_8008B304(var_s0_2);
      func_800DF41C(func_8008B4D4(var_s0_2));
      return;

    case 1:
      var_s0_2 = func_8008D04C(param_0);
      if (func_80800864_bsfirstp(param_0) != 0)
    {
      func_80800F14_bsfirstp(param_0);
    }
      func_8008B304(var_s0_2);
      func_800DF41C(func_8008B4D4(var_s0_2));
      return;

  }

}

void func_80800190_bsfirstp(Actor *param_0)
{
    u8 *local_0;

    local_0 = *(u8 **)((char *)param_0 + 0x188);
    func_80800858_bsfirstp(param_0, 0);
    func_800EFD24(local_0 + 0x2C);
    *(f32 *)((char *)local_0 + 0x50) = 0.0f;
}

int func_808001D0_bsfirstp(Actor *param_0)
{
  func_80808C48_bsfirstp(param_0);
  func_80800858_bsfirstp(param_0, 0 | 0);
}

void func_808001FC_bsfirstp()
{
  AnCtrl *local_0;
  local_0 = func_8008D04C();
  anctrl_setPlaybackType(local_0, 3);
}

int func_80800228_bsfirstp()
{
  s32 local_0;
  s32 local_1;
  local_0 = func_8008D04C();
  if (anctrl_getPlaybackType(local_0 | 0) == 3)
  {
    local_1 = 1;
  }
  else
  {
    local_1 = 0 | 0;
  }
  return local_1 | 0;
}

s32 func_80800264_bsfirstp(PlayerState *map_id, f32 exit_id){
    func_8008B10C(func_8008D04C(map_id), exit_id);
}

s32 func_80800290_bsfirstp(s32 item_id, s32 param_1, s32 param_2) {
    baanim_playForDuration_loopStartingAt(item_id, param_1, param_2, baanim_getTimer(item_id));
}

void func_808002CC_bsfirstp(Actor *param_0, s32 param_1, f32 param_2, f32 param_3)
{
  void *local_0;
  local_0 = func_8008D04C(param_0);
  anctrl_reset(local_0);
  anctrl_setIndex(local_0, param_1);
  anctrl_setDuration(local_0, param_2);
  anctrl_setStart(local_0, param_3);
  anctrl_setPlaybackType(local_0, 2);
  anctrl_start(local_0);
}

void func_80800340_bsfirstp(Actor *param_0, s32 param_1, f32 param_2, f32 param_3)
{
  void *local_0;
  local_0 = func_8008D04C(param_0);
  anctrl_reset(local_0);
  anctrl_setIndex(local_0, param_1);
  anctrl_setDuration(local_0, param_2);
  anctrl_setStart(local_0, param_3);
  anctrl_setPlaybackType(local_0, 1);
  anctrl_start(local_0);
}

void func_808003B4_bsfirstp(Actor *param_0, s32 param_1, f32 param_2)
{
  void *local_0;
  local_0 = func_8008D04C(param_0);
  anctrl_reset(local_0);
  anctrl_setSmoothTransition(local_0, 0);
  anctrl_setIndex(local_0, param_1);
  anctrl_setDuration(local_0, param_2);
  anctrl_setPlaybackType(local_0, 1);
  anctrl_start(local_0);
}

int func_80800424_bsfirstp(Actor *param_0, s32 param_1, f32 param_2)
{
  AnCtrl *local_0;
  extern AnimCtrl *func_8008D04C();
  extern void anctrl_reset(AnimCtrl *);
  extern void anctrl_setIndex(AnimCtrl *, AssetId);
  extern void anctrl_setDuration(AnimCtrl *, f32);
  extern void anctrl_setPlaybackType(AnimCtrl *, s32);
  extern void anctrl_start(AnimCtrl *);

  local_0 = func_8008D04C(param_0);
  anctrl_reset(local_0);
  anctrl_setIndex(local_0, param_1);
  anctrl_setDuration(local_0, param_2);
  anctrl_setPlaybackType(local_0, 1);
  anctrl_start(local_0);
}

void func_80800488_bsfirstp(Actor *param_0, s32 param_1, f32 param_2)
{
  void *local_0;
  local_0 = func_8008D04C(param_0);
  anctrl_reset(local_0);
  anctrl_setSmoothTransition(local_0, 0);
  anctrl_setIndex(local_0, param_1);
  anctrl_setDuration(local_0, param_2);
  anctrl_setPlaybackType(local_0, 2);
  anctrl_start(local_0);
}

void func_808004F8_bsfirstp(u8 *param_0) {
    u8 *local_0 = *(u8 **)(param_0 + 0x188);
    f32 local_1 = *(f32 *)(local_0 + 0x20C);
    func_800EEC70(local_0 + 0x2C, local_1, yaw_get(), 150.0f);
}

int func_8080053C_bsfirstp(Actor *param_0)
{
  s32 local_0;
  extern s32 D_800EFD24; // placeholder — not used directly
  extern Actor* D_808004F8; // placeholder — not used directly
  // Based on offset 0x188, we need to define the struct member properly.
  // Since 'unk188' is undefined, we assume it's part of Actor struct at offset 0x188.
  // In absence of full struct definition, we cast to access raw offset.
  local_0 = *(s32*)((char*)param_0 + 0x188);
  func_808004F8_bsfirstp(param_0);
  func_800EFD24(local_0 + 0x38);
}

void func_8080056C_bsfirstp(PlayerState *param_0, f32 *local_2) /* agV12: local_2 = 2nd (dead, overwritten-before-read) parameter used as holder: no home slot, no entry store (as target); caller arity not verifiable (no jal/table reference found) */
{
    f32 local_0[4];
    f32 local_1;
    f32 local_4;
    f32 local_5;
    f32 local_6;

    local_2 = *(f32 **)((u8 *)param_0 + 0x188);
    local_1 = func_800D9004();
    func_8009B4D0(param_0, local_0);
    func_800EF3DC(local_0, local_2 + 0x2C / 4);
    func_808004F8_bsfirstp(param_0);
    func_800EF04C(local_0, local_2 + 0x2C / 4);
    func_800EF334(local_0, 1.0f / local_1);
    local_2[0x38 / 4] += (local_0[0] - local_2[0x38 / 4]) * 0.2f;
    local_2[0x40 / 4] += (local_0[2] - local_2[0x40 / 4]) * 0.2f;
    {
        local_4 = func_80806170_bsfirstp(param_0, func_800EEFFC(local_2 + 0x38 / 4));
        local_5 = func_800F1CF0(local_2 + 0x38 / 4, local_2 + 0x2C / 4);
        local_6 = sqrtf(1.0f - local_5 * local_5);
        local_2[0x44 / 4] = func_800F0DC0(local_4 * local_5, 1.0f);
        local_2[0x48 / 4] = func_800F0DC0(local_4 * local_6, 1.0f);
        local_1 = func_80809938_bsfirstp(param_0);
        local_2[0x4C / 4] += (func_800F0DC0(local_1, 1.0f) -
            local_2[0x4C / 4]) * 0.2f;
    }
}

void func_808006DC_bsfirstp(PlayerState *param_0)
{
    u8 *local_4 = *(u8 **)((u8 *)param_0 + 0x188);
    f32 local_0;
    f32 local_1;
    f32 local_2;
    f32 local_3;
    f32 local_5;
    local_0 = mlAbsF(*(f32 *)(local_4 + 0x44));
    local_1 = *(f32 *)(local_4 + 0x48);
    if (*(s32 *)local_4 == 3) {
        local_0 *= 1.333f;
        local_1 *= 1.333f;
    }
    local_2 = local_1 * 0.75f;
    local_3 = local_2 < local_0 ? local_0 : local_2;
    if (local_3 != 0.0f) {
        *(f32 *)(local_4 + 0x54) = func_800136E4(*(f32 *)(local_4 + 0x54) + local_3 * 12.5f);
        local_5 = func_80013970(*(f32 *)(local_4 + 0x54));
        *(f32 *)(local_4 + 0x58) = local_5 * local_3;
    } else {
        *(f32 *)(local_4 + 0x54) = 0.0f;
        *(f32 *)(local_4 + 0x58) = 0.0f;
    }
    local_2 = local_0 * 0.75f;
    local_3 = local_2 < local_1 ? local_1 : local_2;
    if (local_3 != 0.0f) {
        *(f32 *)(local_4 + 0x5C) = func_800136E4(*(f32 *)(local_4 + 0x5C) + local_3 * 25.0f);
        local_5 = func_80013970(*(f32 *)(local_4 + 0x5C));
        *(f32 *)(local_4 + 0x60) = local_5 * local_3;
    } else {
        *(f32 *)(local_4 + 0x5C) = 0.0f;
        *(f32 *)(local_4 + 0x60) = 0.0f;
    }
}

void func_80800830_bsfirstp(arg0, arg1) s32 arg0; f32 *arg1;
{
    func_8080056C_bsfirstp(arg0, arg1);
    func_808006DC_bsfirstp(arg0);
}
void func_80800858_bsfirstp(param_0, param_1) u8 *param_0; s32 param_1;
{
  s8 *new_var;
  *((s32 *) ((new_var = (s8 *) (*((u8 **) (((s8 *) param_0) + 0x188)))) + 0x28)) = param_1;
}

s32 func_80800864_bsfirstp(param_0) u8 *param_0; {
    u8 *local_0 = *(u8 **)(param_0 + 0x188);
    return *(s32 *)(local_0 + 0x28) ? 1 : 0;
}

void func_80800888_bsfirstp(u8 *param_0, s32 param_1) {
    u8 *local_0 = *(u8 **)(param_0 + 0x188);
    *(s32 *)(local_0 + 0x8C) = param_1;
    func_80800900_bsfirstp(param_0, 1.0f);
}

int func_808008B0_bsfirstp(PlayerState *param_0)
{
    f32 *local_0 = (f32 *)param_0->kazfly;
    f32 local_1;

    local_1 = local_0[0x24] - func_800D9004() * 5.5f;
    return func_80800900_bsfirstp(param_0, local_1);
}

int func_80800900_bsfirstp(PlayerState *param_0, f32 param_1)
{
    FirstPersonBlend1459 *local_0;
    f32 *local_1;
    s32 local_2;

    local_0 = (FirstPersonBlend1459 *)param_0->kazfly;
    if (param_1 <= 0.0f) {
        local_2 = 0;
        param_1 = 0.0f;
    } else {
        local_2 = 1;
    }
    local_1 = D_8080A5B0_bsfirstp[local_0->type];
    local_0->strength = param_1;
    local_0->components[0] = local_1[0] * param_1;
    local_0->components[1] = local_1[1] * param_1;
    local_0->components[2] = local_1[2] * param_1;
    local_0->components[3] = local_1[3] * param_1;
    return local_2;
}

void func_80800978_bsfirstp(param_0, param_1, param_2, param_3) PlayerState *param_0; void *param_1; f32 *param_2; f32 *param_3;
{
    f32 *local_0;
    FirstPersonSplit *local_1;
    f32 local_2;
    f32 local_3;
    f32 local_4;
    local_0 = (f32 *)param_0->kazfly;
    local_1 = param_1;
    local_2 = local_0[0xC8 / 4] * 0.02712967992f;
    local_3 = local_0[0xCC / 4] * 0.01768659241f;
    if (local_2 > 0.0f) local_4 = -local_1->upper;
    else local_4 = local_1->lower;
    local_2 *= local_4;
    if (local_3 > 0.0f) local_4 = -local_1->right;
    else local_4 = local_1->left;
    local_3 *= local_4;
    param_2[0] = local_1->fraction * local_2;
    param_3[0] = local_1->fraction * local_3;
    param_2[1] = local_2 - param_2[0];
    param_3[1] = local_3 - param_3[0];
}

void func_80800A18_bsfirstp(PlayerState *param_0, void *param_1)
{
    u8 *local_0;
    f32 local_1[2];
    f32 local_2[2];
    f32 *local_5;
    f32 local_3;
    f32 local_4;

    local_0 = func_80802484_bsfirstp(param_0);
    func_80800978_bsfirstp(param_0, local_0, local_1, local_2);
    func_800E0AFC(param_1, local_0[0x2B], 1.0f, local_1[0], local_2[0], 0.0f);
    func_800E0AFC(param_1, local_0[0x2F], 1.0f, 0.0f, local_2[1], -local_1[1]);
    local_5 = (f32 *)param_0->kazfly;
    local_3 = local_5[0x44 / 4] * 20.0f;
    local_4 = local_5[0x60 / 4] * -15.0f;
    func_800E0AFC(param_1, 0x2D, 1.0f, 0.0f, local_3, local_4);
    func_800E0AFC(param_1, 0x2E, 1.0f, 0.0f, local_3, local_4);
    func_800E0AFC(param_1, 0x2F, 1.0f, 0.0f, local_3, local_4);
}

void func_80800B44_bsfirstp(PlayerState *param_0, void *param_1)
{
    u8 *local_0;
    f32 local_1[2];
    f32 local_2[2];
    f32 local_3;
    f32 local_4;

    local_0 = func_80802484_bsfirstp(param_0);
    func_80800978_bsfirstp(param_0, local_0, local_1, local_2);
    func_800E0AFC(param_1, local_0[0x2B], 1.0f, local_1[0], local_2[0], 0.0f);
    func_800E0AFC(param_1, local_0[0x2F], 1.0f, local_1[1], local_2[1], 0.0f);
    local_3 = *(f32 *)((u8 *)param_0->kazfly + 0x44) * 20.0f;
    local_4 = *(f32 *)((u8 *)param_0->kazfly + 0x60) * -15.0f;
    func_800E0AFC(param_1, 0x2B, 0.5f, 0.0f, local_3, local_4);
    func_800E0AFC(param_1, 0x2C, 0.5f, 0.0f, local_3, local_4);
    func_800E0AFC(param_1, 0x2D, 0.5f, 0.0f, local_3, local_4);
    func_800E0AFC(param_1, 0x2E, 0.5f, 0.0f, local_3, local_4);
}

void func_80800C88_bsfirstp(PlayerState *param_0, void *param_1)
{
    u8 *local_0;
    f32 local_1[2];
    f32 local_2[2];
    local_0 = func_80802484_bsfirstp(param_0);
    func_80800978_bsfirstp(param_0, local_0, local_1, local_2);
    func_800E0AFC(param_1, local_0[0x2B], 1.0f, local_1[0], local_2[0], 0.0f);
    func_800E0AFC(param_1, local_0[0x2F], 1.0f, 0.0f, local_2[1], -local_1[1]);
}

void func_80800D18_bsfirstp(PlayerState *param_0, void *param_1)
{
    Mass47Firstp *local_0;
    f32 local_1[2];
    f32 local_2[2];
    f32 local_3;
    f32 local_4;
    u8 *local_5;
    f32 local_6;

    local_0 = (Mass47Firstp *)func_80802484_bsfirstp(param_0);
    func_80800978_bsfirstp(param_0, local_0, local_1, local_2);
    func_800E0AFC(param_1, local_0->local_1, 1.0f, -local_1[0], local_2[0], 0.0f);
    func_800E0AFC(param_1, local_0->local_3, 1.0f, -local_1[1], local_2[1], 0.0f);
    local_5 = (u8 *)param_0->kazfly;
    local_3 = *(f32 *)(local_5 + 0x44) * -20.0f;
    local_4 = *(f32 *)(local_5 + 0x60) * -15.0f;
    local_6 = -local_4;
    func_800E0AFC(param_1, 0x3C, 0.5f, 0.0f, local_3, local_6);
    func_800E0AFC(param_1, 0x3E, 0.5f, 0.0f, local_3, local_6);
    func_800E0AFC(param_1, 0x3F, 0.5f, 0.0f, local_3, local_4);
    func_800E0AFC(param_1, 0x40, 0.5f, 0.0f, local_3, local_4);
    func_800E0AFC(param_1, 0x54, 0.5f, local_4, local_3, 0.0f);
    func_800E0AFC(param_1, 0x5A, 0.5f, local_4, local_3, 0.0f);
    func_800E0AFC(param_1, 0x5B, 0.5f, local_4, local_3, 0.0f);
    func_800E0AFC(param_1, 0x5C, 0.5f, local_4, local_3, 0.0f);
    func_800E0AFC(param_1, 0x5D, 0.5f, local_4, local_3, 0.0f);
}

void func_80800F14_bsfirstp(param_0) PlayerState *param_0;
{
    u8 *local_0;
    void *local_1;

    local_0 = *(u8 **)((u8 *)param_0 + 0x188);
    local_1 = func_8009370C(param_0);
    func_800E0ACC(local_1);
    func_800E0AF0(local_1, 1.0f);
    *(f32 *)(local_0 + 0x18) = *(f32 *)(local_0 + 0x58) * 0.02f;
    *(f32 *)(local_0 + 0x1C) = *(f32 *)(local_0 + 0x60) * 0.03f;
    switch (func_800A3280(param_0)) {
        case 1:
        case 6:
            func_80800A18_bsfirstp(param_0, local_1);
            break;
        case 4:
            func_80800B44_bsfirstp(param_0, local_1);
            break;
        case 5:
            func_80800C88_bsfirstp(param_0, local_1);
            break;
        case 2:
        case 3:
            func_80800D18_bsfirstp(param_0, local_1);
            break;
    }
}

void func_80801000_bsfirstp(param_0) PlayerState *param_0;
{
    u8 *local_0;
    void *local_1;
    f32 local_2[2];
    f32 local_3[2];
    f32 local_4;
    f32 local_5;

    local_0 = *(u8 **)((u8 *)param_0 + 0x188);
    local_1 = func_80092AD8(param_0);
    func_800E0ACC(local_1);
    func_800E0AF0(local_1, 1.0f);
    local_2[0] = func_800F0DC0(func_80806130_bsfirstp(param_0), 80.0f);
    local_4 = func_800F1214(func_8080613C_bsfirstp(param_0), 360.0f, 720.0f);
    func_80805380_bsfirstp((f32 *)(local_0 + 0x50), local_2[0], local_4, local_4 * (1.0f / 24.0f));
    local_2[0] = *(f32 *)(local_0 + 0x50);
    local_2[1] = func_80013728(*(f32 *)(local_0 + 0xCC) + local_2[0]);
    local_3[0] = *(f32 *)(local_0 + 0x20C);
    local_3[1] = func_80013728(*(f32 *)(local_0 + 0xC8) + *(f32 *)(local_0 + 0x20C));
    switch (*(s32 *)local_0) {
    case 1:
    case 5:
    {
        f32 local_6;
        const f32 local_7 = 0.125f;
        f32 local_8;
        local_5 = local_2[0];
        func_800E0AFC(local_1, (u8)(*(s32 *)local_0 == 1 ? 0x2B : 3), 1.0f, 0.0f, local_5, 0.0f);
        local_6 = -local_3[0] * 0.4f;
        local_5 *= -0.5f;
        func_800E0AFC(local_1, 1, 1.0f, local_6, local_5, 0.0f);
        local_6 = -local_3[0] * 0.6f;
        func_800E0AFC(local_1, 0x12, 1.0f, local_6, local_5, 0.0f);
        local_5 = -0.25f * local_2[0] + local_2[1] * local_7;
        func_800E0AFC(local_1, 0x49, 1.0f, -local_3[1] * 0.1f, local_5, 0.0f);
        func_800E0AFC(local_1, 0x4B, 1.0f, -local_3[1] * 0.5f, local_5, 0.0f);
        local_5 = local_2[1] * local_7;
        local_8 = local_2[1] * 0.0625f;
        func_800E0AFC(local_1, 8, 1.0f, 0.0f, local_5, local_8);
        local_5 = -local_3[1] * 0.0625f;
        local_8 = local_3[1] * local_7;
        func_800E0AFC(local_1, 0xE, 1.0f, 0.0f, local_5, local_8);
        break;
    }
    case 4:
    {
        f32 local_9;
        f32 local_10;
        f32 local_11;
        const f32 local_12 = 0.25f;
        local_9 = local_2[0] * 0.5f;
        if (local_9 != 0.0f) {
            func_800E0AFC(local_1, 3, 1.0f, 0.0f, local_9, 0.0f);
            func_800E0AFC(local_1, 6, 1.0f, 0.0f, local_9, 0.0f);
            func_800E0AFC(local_1, 0x14, 1.0f, 0.0f, local_9, 0.0f);
        }
        local_10 = -local_3[0] * 0.4f;
        local_9 = -local_2[0] * 0.25f;
        func_800E0AFC(local_1, 1, 1.0f, local_10, local_9, 0.0f);
        local_10 = -local_3[0] * 0.6f;
        func_800E0AFC(local_1, 0x12, 1.0f, local_10, local_9, 0.0f);
        local_11 = local_3[1] * local_12;
        local_5 = local_12 * local_2[1] - local_2[0] * 0.5f;
        func_800E0AFC(local_1, 0x1E, 1.0f, 0.0f, local_11, local_5);
        func_800E0AFC(local_1, 0x3A, 1.0f, 0.0f, -local_11, local_5);
        break;
    }
    case 2:
    case 3:
    {
        f32 local_13;
        f32 local_14;
        const f32 local_15 = 0.25f;
        func_800E0AFC(local_1, 3, 1.0f, 0.0f, local_2[0], 0.0f);
        func_800E0AFC(local_1, 1, 1.0f, -local_3[0] * 0.4f, -local_2[0] * 0.67f, 0.0f);
        func_800E0AFC(local_1, 0x12, 1.0f, -local_3[0] * 0.6f, -local_2[0] * 0.33f, 0.0f);
        local_13 = local_3[1] * local_15;
        local_14 = local_15 * local_2[1] - local_2[0] * 0.33f;
        func_800E0AFC(local_1, 0x1E, 1.0f, 0.0f, local_13, local_14);
        func_800E0AFC(local_1, 0x3A, 1.0f, -local_13, local_14, 0.0f);
        break;
    }
    case 0:
        func_800E0AFC(local_1, 3, 1.0f, 0, local_2[0], 0);
        func_800E0AFC(local_1, 0x6C, 1.0f, -local_3[0], -local_2[0], 0);
        break;
    }
}

void func_808015C0_bsfirstp(s32 param_0, u8 *param_1, u8 *param_2)
{
  u8 *sp1C;
  f32 temp_f18;
  sp1C = func_80802484_bsfirstp();
  func_8009C128(param_0, param_1);
  *((f32 *) (((s8 *) param_1) + 4)) = (f32) ((*((f32 *) (((s8 *) sp1C) + 8))) + (*((f32 *) (((s8 *) param_1) + 4))));
  *((f32 *) (((s8 *) param_2) + 0)) = 0.0f;
  temp_f18 = yaw_get(param_0) + 180.0f;
  *((f32 *) (((s8 *) param_2) + 4)) = temp_f18;
  *((f32 *) (((s8 *) param_2) + 8)) = 0.0f;
}

extern f32 func_800C517C(s32);
extern int func_800A4C68();

f32 func_80801640_bsfirstp(s32 param_0)
{
    return func_800C517C(func_800A4C68(param_0));
}

void func_80801668_bsfirstp(u8 *param_0, f32 param_1) {
    u8 *local_0 = *(u8 **)(param_0 + 0x188);
    *(f32 *)(local_0 + 0x9C) = func_80801640_bsfirstp(param_0);
    *(f32 *)(local_0 + 0x98) = param_1;
}

void func_808016A0_bsfirstp(PlayerState *param_0)
{
    FirstPersonVolume1536 *local_0;
    f32 local_1;
    f32 local_6;
    f32 local_5;
    f32 local_3;
    f32 local_2;

    local_0 = (FirstPersonVolume1536 *)param_0->kazfly;
    local_6 = local_0->local_0;
    local_1 = local_0->local_1;
    if (local_6 != local_1) {
        local_2 = local_6 - local_1;
        local_3 = func_800F2108(local_2);
        local_6 = mlAbsF(local_2);
        local_5 = local_6 * 0.5f;
        if (local_5 < 0.5f) {
            if (local_6 > 0.5f) local_5 = 0.5f;
            else local_5 = local_6;
        }
        local_1 += local_5 * local_3;
        local_0->local_1 = local_1;
        func_800C5148(func_800A4C68(param_0), local_1);
    }
}

void func_8080175C_bsfirstp(u8 *param_0) {
    u8 *local_0 = *(u8 **)(param_0 + 0x188);
    f32 local_1 = *(f32 *)(local_0 + 0x98);
    *(f32 *)(local_0 + 0x9C) = local_1;
    func_800C5148(func_800A4C68(), local_1);
}

void bsfirstp_entrypoint_2(PlayerState *param_0)
{
    s32 *local_0;
    void *local_3;
    f32 local_1[3];
    f32 local_2[3];

    local_0 = func_80802484_bsfirstp(param_0);
    local_3 = func_800A4CA8(param_0);
    func_80111590(local_3, 0.0f, 0.0f, 360.0f, 360.0f);
    func_80110730(local_3, 1);
    func_808015C0_bsfirstp(param_0, local_1, local_2);
    _ncba1p_entrypoint_6(local_3, local_1);
    _ncba1p_entrypoint_7(local_3, local_2);
    if (func_800A3404(param_0)) {
        _ncba1p_entrypoint_2(local_3);
        _ncba1p_entrypoint_4(local_3, 0);
    }
    func_8010FD60(func_800A4C88(param_0), local_0[0]);
    func_80801668_bsfirstp(param_0, ((f32 *)local_0)[1]);
}

void func_8080187C_bsfirstp(Actor *param_0) {
    if (func_800A5090(param_0) == 0) {
        func_800A5004(param_0);
        func_800CA6C0(func_800A5090(param_0), 0x3F800000, 0x447A0000);
        func_80801668_bsfirstp(param_0, func_80801640_bsfirstp(param_0));
    }
}

int func_808018E0_bsfirstp(Actor *param_0)
{
  func_80110730(func_800A4CA8(param_0), 0);
  func_8010FD38(func_800A4C88(param_0), 0);
  func_800A5044(param_0);
}

void func_80801928_bsfirstp(Actor *param_0) {
    s32 local_2;
    f32 local_0[3];
    f32 local_1[3];

    if (func_800A5090(param_0) != 0) {
        local_2 = *(s32*)((char*)param_0 + 0x188);
        func_808015C0_bsfirstp(param_0, local_0, local_1);
        local_1[0] = *(f32*)((char*)local_2 + 0x20C);
        _ncba1p_entrypoint_6(func_800A4CA8(param_0), local_0);
        _ncba1p_entrypoint_7(func_800A4CA8(param_0), local_1);
        func_808019B0_bsfirstp(param_0);
    }
    func_808016A0_bsfirstp(param_0);
}

int func_808019B0_bsfirstp(param_0) s32 param_0;
{
  s32 *local_1;
  s32 local_0;
  local_1 = func_80802484_bsfirstp(param_0);
  local_0 = func_800A4C88(param_0);
  func_8010FD60(local_0, *local_1);
}

int func_808019EC_bsfirstp(Actor *param_0)
{
  if (func_800A4D40(param_0) && func_800A5090(param_0))
  {
    func_808019B0_bsfirstp(param_0);
    func_8080175C_bsfirstp(param_0);
  }
}

void func_80801A34_bsfirstp(s32 arg0)
{
    func_8080187C_bsfirstp(arg0);
    bsfirstp_entrypoint_2(arg0);
}
int func_80801A5C_bsfirstp(Actor *param_0)
{
  func_8080187C_bsfirstp(param_0);
  func_800A3544(param_0, 1);
  bsfirstp_entrypoint_2(param_0);
  func_8080175C_bsfirstp(param_0);
}

int func_80801A98_bsfirstp(Actor *param_0)
{
  s32 local_0;
  local_0 = func_800A4CA8(param_0);
  return _ncba1p_entrypoint_10(local_0 | 0) == 2;
}

int func_80801AC4_bsfirstp(s32 param_0)
{
  s32 *p = *(s32 **)((char *)param_0 + 0x188);
  p[0x28] = 0;
  func_80801B64_bsfirstp(param_0, 0);
}

void func_80801AEC_bsfirstp(s32 arg0)
{
    func_80801B64_bsfirstp(arg0,0);
}

int func_80801B0C_bsfirstp(s32 param_0, s32 *param_1, s32 *param_2)
{
  if (func_800F424C(param_0))
  {
    *param_1 = bainput_func_80097B28(param_0);
    *param_2 = *param_1;
  }
  else
  {
    *param_1 = 0;
    *param_2 = 0;
  }
}

s32 func_80801B64_bsfirstp(param_0, param_1) s32 param_0; s32 param_1; {
    switch (param_1) {
        case 0:
            func_80801BDC_bsfirstp(param_0);
            break;
        case 1:
            func_80801D30_bsfirstp(param_0);
            break;
        case 2:
            func_80801C18_bsfirstp(param_0);
            break;
        case 3:
            func_80801C74_bsfirstp(param_0);
            break;
    }
}

void func_80801BDC_bsfirstp(param_0) u8 *param_0; {
    u8 *local_0 = *(u8 **)(param_0 + 0x188);
    _baeggcursor_entrypoint_7(param_0, 1);
    func_80801D70_bsfirstp(param_0);
    *(s32 *)(local_0 + 0xA8) = 0;
}

void func_80801C18_bsfirstp(param_0) u8 *param_0; {
    u8 *local_0 = *(u8 **)(param_0 + 0x188);
    s32 local_1 = *(s32 *)(local_0 + 0xA8);
    if (local_1 != 0 && local_1 != 2) {
        _baeggcursor_entrypoint_7(param_0, 1);
        *(s32 *)(local_0 + 0xAC) = *(s32 *)(local_0 + 0xA8);
        *(s32 *)(local_0 + 0xA8) = 2;
        *(s32 *)(local_0 + 0xA4) = *(s32 *)(local_0 + 0xA0);
        *(s32 *)(local_0 + 0xA0) = 0;
    }
}

void func_80801C74_bsfirstp(param_0) void *param_0;
{
  u8 *local_0;
  s32 local_1;
  s32 local_2;
  local_0 = *((u8 **) (((char *) param_0) + 0x188));
  if ((*((s32 *) (((char *) local_0) + 0xA8))) == 2)
  {
    local_1 = *((s32 *) (((char *) local_0) + 0xAC));
    switch (local_1)
    {
      case 0:
        *((s32 *) (((char *) local_0) + 0xA8)) = 0;
        return;

      case 1:
        *((s32 *) (((char *) local_0) + 0xA8)) = 1;
        func_80801D70_bsfirstp(param_0);
        local_2 = *((s32 *) (((char *) local_0) + 0xA4));
        if ((*((s32 *) (((char *) local_0) + 0xA4))) != 0)
      {
        if (local_2 == 1)
        {
          _baeggcursor_entrypoint_7(param_0, 2);
          func_80802438_bsfirstp(param_0, 1);
          return;
        }
      }
      else
      {
        _baeggcursor_entrypoint_7(param_0, 1);
        func_80802438_bsfirstp(param_0, 0);
      }
        break;

    }

  }
}

void func_80801D30_bsfirstp(param_0) u8 *param_0; {
    u8 *local_0;

    local_0 = (*(u8 **)((s8 *)(param_0) + (0x188)));
    (*(s32 *)((s8 *)(local_0) + (0xA8))) = 1;
    (*(s32 *)((s8 *)(local_0) + (0xB0))) = 0;
    _baeggcursor_entrypoint_7(param_0, 1);
    func_80802438_bsfirstp(param_0, 0);
}

void func_80801D70_bsfirstp(param_0) u8 *param_0; {
    u8 *local_0 = *(u8 **)(param_0 + 0x188);
    *(f32 *)(local_0 + 0xB8) = 152.0f;
    *(f32 *)(local_0 + 0xBC) = 114.0f;
    *(f32 *)(local_0 + 0xB4) = 0.0f;
    *(f32 *)(local_0 + 0xC0) = 0.0f;
    *(f32 *)(local_0 + 0xC4) = 0.0f;
    _baeggcursor_entrypoint_10(param_0, 152.0f, 114.0f);
}

void func_80801DC0_bsfirstp(u8 *param_0) {
    u8 *local_0 = *(u8 **)(param_0 + 0x188);
    s32 local_1 = *(s32 *)(local_0 + 0xA8);
    if (local_1 == 1 || local_1 == 2) {
        func_80801E18_bsfirstp(param_0);
        func_80801FD0_bsfirstp(param_0, *(s32 *)(local_0 + 0xC));
        func_808023A0_bsfirstp(param_0);
    }
}

void func_80801E18_bsfirstp(param_0) u8 *param_0;
{
    u8 *obj;
    s32 la;
    s32 lb;
    if (1) {}

    obj = *(u8 **)(param_0 + 0x188);
    func_80801B0C_bsfirstp(param_0, &la, &lb);
    switch (*(s32 *)(obj + 0xB0)) {
    case 0:
        if (la != 0) {
            *(s32 *)(obj + 0xB0) = 1;
            _baeggcursor_entrypoint_10(param_0, *(f32 *)(obj + 0xB8), *(f32 *)(obj + 0xBC));
            _baeggcursor_entrypoint_7(param_0, 3);
            func_8010D930(12, -1, 0, D_8080A630_bsfirstp);
        }
        break;
    case 1:
        if (_baeggcursor_entrypoint_9(param_0) != 0) {
            *(s32 *)(obj + 0xB0) = 2;
            func_80802438_bsfirstp(param_0, 1);
        } else if (lb == 0) {
            *(s32 *)(obj + 0xB0) = 3;
        }
        break;
    case 2:
        if (lb == 0) {
            *(s32 *)(obj + 0xB0) = 5;
            _baeggcursor_entrypoint_7(param_0, 4);
            func_8010D930(12, -1, 0, D_8080A640_bsfirstp);
        }
        break;
    case 3:
        if (_baeggcursor_entrypoint_9(param_0) != 0) {
            *(s32 *)(obj + 0xB0) = 4;
            func_80802438_bsfirstp(param_0, 1);
        }
        break;
    case 4:
        *(s32 *)(obj + 0xB0) = 5;
        _baeggcursor_entrypoint_7(param_0, 4);
        func_8010D930(12, -1, 0, D_8080A640_bsfirstp);
        break;
    case 5:
        if (_baeggcursor_entrypoint_2(param_0) != 4) {
            *(s32 *)(obj + 0xB0) = 0;
            func_80802438_bsfirstp(param_0, 0);
        }
        break;
    default:
        break;
    }
}

void func_80801FD0_bsfirstp(param_0, param_1) PlayerState *param_0; s32 param_1;
{
    u8 *local_6;
    f32 local_7;
    f32 local_0[2];
    f32 local_1[2];
    f32 local_2[2];
    f32 local_3;
    f32 *local_8;
    f32 *local_9;
    f32 *local_10;
    f32 local_5[2];
    f32 local_4[2];
    s32 pad; /* unused: only reserves a stack slot (the spill temp lands 4 bytes higher without it) */

    local_6 = *(u8 **)((u8 *)param_0 + 0x188);
    local_3 = *(f32 *)(local_6 + 0xB4);
    local_9 = (f32 *)(local_6 + 0xB8);
    local_7 = func_800D9004();
    switch (*(s32 *)(local_6 + 0xA0)) {
    case 0:
        local_3 -= local_7 * 4.0f;
        if (local_3 < 0) local_3 = 0;
        break;
    case 1:
        local_3 += local_7 * 4.0f;
        if (local_3 >= 1) local_3 = 1;
        break;
    }
    *(f32 *)(local_6 + 0xB4) = local_3;
    local_8 = (f32 *)(D_8080A5D0_bsfirstp + param_1 * 0x30);
    local_0[0] = local_8[0] + (local_8[6] - local_8[0]) * local_3;
    local_0[1] = local_8[1] + (local_8[7] - local_8[1]) * local_3;
    local_1[0] = local_8[2] + (local_8[8] - local_8[2]) * local_3;
    local_1[1] = local_8[3] + (local_8[9] - local_8[3]) * local_3;
    local_2[0] = local_8[4] + (local_8[10] - local_8[4]) * local_3;
    local_2[1] = local_8[5] + (local_8[11] - local_8[5]) * local_3;
    if (*(s32 *)(local_6 + 0xA8) == 1) {
        local_4[0] = *(f32 *)(local_6 + 0x168);
        local_4[1] = *(f32 *)(local_6 + 0x184);
    } else {
        local_4[0] = 0.0f;
        local_4[1] = 0.0f;
    }
    local_5[0] = local_4[0] * local_0[0] + 152.0f;
    local_5[1] = local_4[1] * local_0[1] + 114.0f;
    local_9[0] = func_8080222C_bsfirstp(local_9[0], local_5[0], local_2[0]);
    local_9[1] = func_8080222C_bsfirstp(local_9[1], local_5[1], local_2[1]);
    _baeggcursor_entrypoint_10(param_0, local_9[0], local_9[1]);
    local_10 = (f32 *)(local_6 + 0xC0);
    local_10[0] = func_80802304_bsfirstp(local_9[0] - 152.0f, local_0[0], local_1[0]);
    local_10[1] = func_80802304_bsfirstp(local_9[1] - 114.0f, local_0[1], local_1[1]);
}

f32 func_8080222C_bsfirstp(f32 param_0, f32 param_1, f32 param_2)
{
    f32 local_0;
    s32 local_1;
    for (local_1 = 0; local_1 < func_800D8FEC() * 5; local_1++) {
        local_0 = func_800F0DC0((param_1 - param_0) * 0.04f, param_2);
        param_0 += local_0;
    }
    if (mlAbsF(local_0) < 0.02f) param_0 = param_1;
    return param_0;
}

f32 func_80802304_bsfirstp(f32 param_0, f32 param_1, f32 param_2)
{
    f32 local_0;
    f32 local_1;
    f32 local_2;

    local_0 = 0.0f;
    if (param_2 != 0) {
        local_1 = param_1 - param_2;
        local_2 = 1.0f / param_2;
        if (local_1 < param_0) {
            local_0 = (param_0 - local_1) * local_2;
        } else if (param_0 < -local_1) {
            local_0 = (param_0 + local_1) * local_2;
        }
        local_0 = func_800F0DC0(local_0, 1.0f);
    }
    return local_0;
}

void func_808023A0_bsfirstp(param_0) PlayerState *param_0;
{
    FirstPersonProjection *local_0;
    f32 *local_1;
    f32 local_2;
    f32 local_3;
    f32 local_4;
    local_0 = (FirstPersonProjection *)param_0->kazfly;
    local_1 = local_0->position;
    local_2 = func_800A8AF0(func_800A4C68(param_0));
    local_3 = 152.0f - local_1[0];
    local_4 = local_2 * 0.75f;
    local_3 *= local_4;
    local_0->output[1] = func_80013728(func_80013B7C(local_3, 152.0f));
    local_0->output[0] = func_80013728(func_80013B7C(114.0f - local_1[1], 114.0f));
}

int func_80802438_bsfirstp(param_0, param_1) Actor *param_0; s32 param_1;
{
  s32 *local_0 = *(s32 **)((char *)param_0 + 0x188);
  local_0[0x28] = param_1;
}

s32 func_80802444_bsfirstp(Actor *param_0){
    struct ActorLocal_FirstPerson **local_0;
    struct ActorLocal_FirstPerson *local_1;
    local_0 = (struct ActorLocal_FirstPerson **)((u8 *)param_0 + 0x188);
    local_1 = *local_0;
    return (*(s32 *)((char *)(local_1) + 160)) == 1;
}

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
    return (s32)&D_8080B038_bsfirstp + (func_800A3280() * 12);
}

s32 func_80802594_bsfirstp()
{
    return (s32)&D_8080B080_bsfirstp + (func_800A3280() * 12);
}

void func_808025C8_bsfirstp(s32 param_0, s32 *param_1, s32 *param_2)
{
  s32 local_0;
  local_0 = func_800A3280(param_0) - 1;
  *param_1 = (s32)&D_8080B1B8_bsfirstp + (local_0 << 3);
  *param_2 = (s32)&D_8080B1E0_bsfirstp + (local_0 << 3);
}

void func_8080261C_bsfirstp(s32 param_0, s32 *param_1, s32 *param_2)
{
  s32 local_0;
  local_0 = func_800A3280(param_0) - 1;
  *param_1 = (s32)&D_8080B208_bsfirstp + (local_0 << 3);
  *param_2 = (s32)&D_8080B230_bsfirstp + (local_0 << 3);
}

void func_80802670_bsfirstp(s32 param_0, s32 *param_1)
{
  s32 local_0;
  local_0 = func_800A3280(param_0) - 1;
  *param_1 = (s32)&D_8080B258_bsfirstp + (local_0 << 3);
}

void func_808026AC_bsfirstp(s32 param_0, s32 *param_1, s32 *param_2)
{
  s32 local_0;
  local_0 = func_800A3280(param_0) - 1;
  *param_1 = (s32)&D_8080B0C8_bsfirstp + (local_0 << 3);
  *param_2 = (s32)&D_8080B0F0_bsfirstp + (local_0 << 3);
}

void func_80802700_bsfirstp(s32 param_0, s32 *param_1, s32 *param_2)
{
  s32 local_0;
  local_0 = func_800A3280(param_0) - 1;
  *param_1 = (s32)&D_8080B118_bsfirstp + (local_0 << 3);
  *param_2 = (s32)&D_8080B140_bsfirstp + (local_0 << 3);
}

void func_80802754_bsfirstp(s32 param_0, s32 *param_1, s32 *param_2)
{
  s32 local_0;
  local_0 = func_800A3280(param_0) - 1;
  *param_1 = (s32)&D_8080B168_bsfirstp + (local_0 << 3);
  *param_2 = (s32)&D_8080B190_bsfirstp + (local_0 << 3);
}

int func_808027A8_bsfirstp(s32 param_0)
{
  int *new_var2;
  int new_var;
  new_var = (param_0 - 1) * 4;
  new_var2 = &D_8080AC24_bsfirstp[new_var];
  if (new_var)
  {
  }
  return new_var2;
}

u32 bsfirstp_entrypoint_3(s32 param_0, s32 param_1, s32 param_2)
{
    Mass43EggAimRecord local_0;
    s32 local_2;
    s32 local_3;
    u32 local_1;
    if (!param_1) return 0;
    switch (param_0) {
    case 0x165: local_0 = D_8080AD4C_bsfirstp[param_1 - 1]; break;
    case 0x164: local_0 = D_8080ADA0_bsfirstp[param_1 - 1]; break;
    case 0x166: local_0 = D_8080ACF8_bsfirstp[param_1 - 1]; break;
    }
    local_2 = param_2 >> 2;
    local_3 = param_2 & 3;
    switch (local_3) {
    case 0: local_1 = (u32)local_0.local_0[local_2] >> 12; break;
    case 1: local_1 = ((u8 *)&local_0.local_0[local_2])[0] & 0xF; break;
    case 2: local_1 = (u32)((u8 *)&local_0.local_0[local_2])[1] >> 4; break;
    case 3: local_1 = local_0.local_0[local_2] & 0xF; break;
    }
    return local_1;
}

void bsfirstp_entrypoint_4(s32 param_0, s32 param_1)
{
  u8 *ptr;
  int new_var;
  s32 i;
  ptr = &D_8080AC94_bsfirstp[0];
  ptr += (param_1 * 14) + 2;
  for (i = 1; i < 8; i++)
  {
    if ((i && i) && i)
    {
    }
    new_var = 2;
    _badeathmatch_entrypoint_10(param_0, i, ptr[-2], ptr[-1]);
    ptr += new_var;
  }

}

void bsfirstp_entrypoint_5(Actor *param_0, s32 param_1, s32 param_2)
{
    s32 pad[2];
    s32 local_0;

    local_0 = ((u8 *) D_8080AC94_bsfirstp)[param_2 * 5 + param_1 - 0x92];
    func_800A18C8(param_0, local_0);
    func_800A1870(param_0, local_0);
}

s32 func_80802A40_bsfirstp(PlayerState *param_0, s32 param_1)
{
    FirstPersonAnimation *local_0;

    local_0 = D_8080B45C_bsfirstp[func_800A3280(param_0)];
    local_0 += param_1;
    if (local_0->enabled == 0) {
        return 0;
    }
    func_8009DF18(param_0, local_0->animation, local_0->duration, local_0->enabled);
    return 1;
}

int func_80802AA8_bsfirstp(s32 param_0, s16 param_1, OSIoMesgHdr *param_2, OSIoMesgHdr *param_3)
{
  u32 local_0;
  s32 local_1;
  u8 *local_2;
  u8 *local_3;
  local_0 = func_800A3280(param_0);
  local_1 = param_1 * 2;
  local_2 = (local_0 << 5) + (local_1 * 4) + D_8080AE44_bsfirstp;
  local_3 = (local_0 * 0x10) + (local_1 * 2) + D_8080ADF4_bsfirstp;
  *(s16*)((char*)param_2 + 0x0) = *(s32*)((char*)local_2 - 0x20);
  *(s16*)((char*)param_2 + 0x2) = *(s16*)((char*)local_3 - 0x10);
  *(s16*)((char*)param_3 + 0x0) = *(s32*)((char*)local_2 - 0x1C);
  *(s16*)((char*)param_3 + 0x2) = *(s16*)((char*)local_3 - 0xE);
}

void bsfirstp_entrypoint_6(PlayerState *param_0, f32 *param_1, f32 *param_2, f32 *param_3)
{
    FirstPersonValues *local_0;

    local_0 = (FirstPersonValues *)func_80802458_bsfirstp(param_0);
    *param_1 = local_0->first;
    *param_3 = local_0->second;
    *param_2 = local_0->third;
    if (!func_800D3948()) {
        *param_1 *= 0.67f;
    }
}

void bsfirstp_entrypoint_7(s32 param_0, f32 *param_1, f32 *param_2) {
    u8 *local_0 = func_80802458_bsfirstp(param_0);
    *param_1 = *(f32 *)(local_0 + 0xC);
    *param_2 = *(f32 *)(local_0 + 0x10);
}

void func_80802BD8_bsfirstp(s32 arg0) 
{
}
void func_80802BE0_bsfirstp(s32 arg0) 
{
}
void func_80802BE8_bsfirstp(u8 *param_0, f32 param_1) {
    if (*(s32 *)(param_0 + 0x158) == 0) {
        func_80094430(param_0, param_1);
    } else {
        _badeathmatch_entrypoint_8(param_0, param_1);
    }
}

s32 func_80802C30_bsfirstp(void *param_0)
{
  if (!(*(s32 *)((char *)param_0 + 0x158))) {
        return func_80094510(param_0);
    }
  else {
        return _badeathmatch_entrypoint_6(param_0);
    }
}

void func_80802C6C_bsfirstp(s32 arg0)
{
    func_800FC660(0xF);
}

int func_80802C90_bsfirstp(Actor *param_0)
{
  if (!(*(s32 *)((char *)(param_0) + 0x158)))
  {
    func_80094BC0();
  }
  else
  {
    _badeathmatch_entrypoint_9(param_0, _badeathmatch_entrypoint_6(param_0));
  }
}

void func_80802CD8_bsfirstp(Actor *param_0, s32 param_1)
{
    if (*(s32 *)((char *)param_0 + 0x158) == 0) {
        func_80094C0C();
    }
    else {
        _badeathmatch_entrypoint_5(param_0, param_1, -1);
    }
}

int func_80802D14_bsfirstp(void *param_0)
{
  if (!(*(s32 *)((char *)param_0 + 0x158))) {
        func_80094A10();
    }
  else {
        _badeathmatch_entrypoint_0(param_0);
    }
}

s32 func_80802D50_bsfirstp(PlayerState *param_0, s32 *param_1)
{
    u8 *local_0;
    s32 local_1;

    local_0 = (u8 *)param_0->kazfly;
    if (func_80802C90_bsfirstp((Actor *)param_0)) {
        local_1 = 1;
    } else {
        local_1 = 0;
    }
    switch (*(s16 *)(local_0 + 0xE2)) {
        case 0:
            return 0;
        case 1:
            if (!local_1) {
                *(s16 *)(local_0 + 0xE2) = 0;
                if (*(s16 *)(local_0 + 0xE6) == 0) {
                    *(s16 *)(local_0 + 0xE6) = 1;
                    func_80802C6C_bsfirstp(param_0);
                }
                return 0;
            }
            break;
        case 2:
            if (!local_1) {
                *(s16 *)(local_0 + 0xE2) = 0;
                switch (*(s16 *)(local_0 + 0xE6)) {
                    case 0:
                        *(s16 *)(local_0 + 0xE6) = 1;
                        func_80802C6C_bsfirstp(param_0);
                        break;
                    case 1:
                        *(s16 *)(local_0 + 0xE8) = func_80802D14_bsfirstp(param_0);
                        func_80802E7C_bsfirstp(local_0);
                        break;
                }
                return 0;
            }
            break;
    }
    switch (func_80802E7C_bsfirstp(local_0)) {
        case 0:
            *param_1 = 0xD8;
            break;
        case 1:
            *param_1 = 0xD6;
            break;
    }
    return 1;
}

int func_80802E7C_bsfirstp(param_0) Actor *param_0;
{
  s16 local_0;
  char *new_var;
  Actor *new_var2;
  Actor *local_1;
  unsigned short new_var3;
  local_1 = func_808027A8_bsfirstp(*((s16 *) (((char *) param_0) + 0xE8)));
  new_var3 = (*((s16 *) (((char *) param_0) + 0xE2))) ^ 0;
  local_0 = new_var3;
  *((s16 *) (0xE0 + ((char *) param_0))) = 2;
  *((s16 *) (((char *) param_0) + 0xE2)) = 0;
  new_var = (char *) local_1;
  *((s16 *) (((char *) param_0) + 0xE6)) = 0;
  *((s16 *) (((char *) param_0) + 0xE4)) = local_0;
  *((f32 *) (((char *) param_0) + 0xD8)) = *((f32 *) (new_var + 8));
  new_var2 = param_0;
  *((f32 *) (((char *) new_var2) + 0xDC)) = *((f32 *) (((char *) local_1) + 0xC));
  return *((s32 *) local_1);
}

void func_80802ED4_bsfirstp(void *param_0)
{
    void *local_0 = *(void **)((u8 *)param_0 + 0x188);
    *(short *)((u8 *)local_0 + 0xE0) = 4;
    func_80803124_bsfirstp(param_0, 0);
}

void func_80802F00_bsfirstp(s32 param_0)
{
    func_80802ED4_bsfirstp(param_0);
}

void func_80802F20_bsfirstp(PlayerState *param_0)
{
    u8 *local_0;
    f32 local_1;
    local_0 = (u8 *)param_0->kazfly;
    if (!func_8009E674(param_0, 0x10000)) {
        if (*(s16 *)(local_0 + 0xE0) != 4) func_80803124_bsfirstp(param_0, 4);
    } else {
        if (*(s16 *)(local_0 + 0xE0) == 4) func_80803124_bsfirstp(param_0, 0);
        if (bakey_pressed(param_0, 1)) *(s16 *)(local_0 + 0xD4) = 1;
        if (bakey_held(param_0, 1)) *(s16 *)(local_0 + 0xD6) = 1;
        else *(s16 *)(local_0 + 0xD6) = 0;
        local_1 = func_800D9004();
        switch (*(s16 *)(local_0 + 0xE0)) {
        case 0:
            if (*(s16 *)(local_0 + 0xD4)) func_808030E0_bsfirstp(param_0, 2);
            else if (*(s16 *)(local_0 + 0xD6)) func_808030E0_bsfirstp(param_0, 1);
            break;
        case 1:
            if (func_800F1574((f32 *)(local_0 + 0xDC), local_1)) *(s16 *)(local_0 + 0xE0) = 0;
            if (*(s16 *)(local_0 + 0xD4)) func_808030E0_bsfirstp(param_0, 2);
            break;
        case 2:
            if (func_800F1574((f32 *)(local_0 + 0xD8), local_1)) *(s16 *)(local_0 + 0xE0) = 1;
            if (func_800F1574((f32 *)(local_0 + 0xDC), local_1)) *(s16 *)(local_0 + 0xE0) = 0;
            break;
        case 3:
            func_800F1574((f32 *)(local_0 + 0xD8), local_1);
            func_800F1574((f32 *)(local_0 + 0xDC), local_1);
            *(s16 *)(local_0 + 0xD4) = 0;
            break;
        }
    }
}

void func_808030E0_bsfirstp(param_0, param_1) u8 *param_0; long param_1;
{
  u8 *temp_v1;
  temp_v1 = *((u8 **) (((u8 *) param_0) + 0x188));
  *((s16 *) (((u8 *) temp_v1) + 0xD4)) = 0;
  if ((*((s16 *) (((u8 *) temp_v1) + 0xE2))) < param_1)
  {
    *((s16 *) (((u8 *) temp_v1) + 0xE2)) = param_1;
    *((s16 *) (((u8 *) temp_v1) + 0xE8)) = func_80802C30_bsfirstp(param_0);
  }
}

void func_80803124_bsfirstp(param_0, param_1) Actor *param_0; s32 param_1; {
    s16 *local_0 = *(s16 **)((char *)param_0 + 0x188);
    local_0[0xE0 / 2] = 0;
}

void func_80803134_bsfirstp(u8 *param_0) {
    u8 *local_0;
    u8 *local_1;
    u8 *local_2;

    local_0 = (*(u8 **)((s8 *)(param_0) + (0x188)));
    func_80807BB8_bsfirstp();
    func_80808DB0_bsfirstp(param_0);
    (*(s32 *)((s8 *)(param_0) + (0x15C))) = 0;
    func_8080261C_bsfirstp(param_0, &local_1, &local_2);
    func_80800424_bsfirstp(param_0, (*(s16 *)((s8 *)(local_1) + (0))), (*(f32 *)((s8 *)(local_1) + (4))));
    baanim_playForDuration_onceSmooth(param_0, (*(s16 *)((s8 *)(local_2) + (0))), (*(f32 *)((s8 *)(local_2) + (4))));
    _baeggsetup_entrypoint_7(param_0, &_bsfirstp_entrypoint_10);
    (*(s16 *)((s8 *)(local_0) + (0xE0))) = 3;
    func_800A0D94(param_0, 1);
}

void func_808031D0_bsfirstp(u8 *param_0) {
    u8 *local_0 = *(u8 **)(param_0 + 0x188);
    *(s16 *)(local_0 + 0xE0) = 0;
    func_800A0D94(param_0, 0);
    func_80807C8C_bsfirstp(param_0);
}

void func_80803204_bsfirstp(u8 *param_0)
{
  s32 temp_v0;
  func_80807D48_bsfirstp(param_0);
  func_80808E78_bsfirstp(param_0);
  func_8080633C_bsfirstp(param_0, 1.0f);
  if (1)
  {
    temp_v0 = *((s32 *) (((u8 *) param_0) + 0x15C));
    switch (temp_v0)
    {
      case 0:
        if (anctrl_isAt(func_8008D04C(param_0), 0.600000024f) != 0)
      {
        func_80803124_bsfirstp(param_0, 0);
        *((s32 *) (((u8 *) param_0) + 0x15C)) = 1;
        return;
      }
        return;

      case 1:
        if (func_80800228_bsfirstp(param_0) != 0)
      {
        bs_setState(param_0, 0xCA);
      }
        break;

    }

  }
}

int bsfirstp_entrypoint_8(s32 param_0)
{
  return D_8080B474_bsfirstp[param_0];
}

void func_808032C0_bsfirstp(PlayerState *param_0)
{
    u8 *local_0;

    func_80807BB8_bsfirstp(param_0);
    func_80808DB0_bsfirstp(param_0);
    func_80802670_bsfirstp(param_0, &local_0);
    func_80800424_bsfirstp((Actor *)param_0, *(s16 *)local_0, *(f32 *)(local_0 + 4));
    _baeggsetup_entrypoint_7(param_0, _bsfirstp_entrypoint_10);
}

void func_80803320_bsfirstp(s32 param_0)
{
    func_80807C8C_bsfirstp(param_0);
}
int func_80803340_bsfirstp(s32 param_0)
{
  s32 local_3C;
  u32 local_38;
  u8 *local_34;
  u8 *local_30;
  s16 local_3;
  u8 *local_4;

  local_3C = 0;
  func_80807D48_bsfirstp(param_0);
  func_80808E78_bsfirstp(param_0);
  func_8080633C_bsfirstp(param_0, 1.0f);
  if (func_80802D50_bsfirstp(param_0, &local_38))
  {
    func_80802670_bsfirstp(param_0, &local_34);
    func_80800424_bsfirstp(param_0, *(s16 *)((char *)(local_34) + 0x0), *(f32 *)((char *)(local_34) + 0x4));
    _baeggsetup_entrypoint_7(param_0, &_bsfirstp_entrypoint_10);
  }
  local_30 = *(u8 **)((char *)(param_0) + 0x188);
  local_3 = func_80809540_bsfirstp(param_0, local_30[0x218]);
  switch (local_3)
  {
    case 0 :
      if (local_30[0x218] != 0)
      {
        func_80808D80_bsfirstp(param_0);
        local_30[0x218] = 0;
      }
      break;
    case 1 :
      if (local_30[0x218] != 1)
      {
        func_80809684_bsfirstp(param_0, 1);
      }
      func_80809740_bsfirstp(param_0);
      break;
    case 2 :
      if (local_30[0x218] != 2)
      {
        func_80809684_bsfirstp(param_0, 2);
      }
      func_80809740_bsfirstp(param_0);
  }
  if (func_80800228_bsfirstp(param_0))
  {
    local_3C = func_808094F4_bsfirstp(param_0);
  }
  if (local_3C != 0)
  {
    bs_setState(param_0, local_3C);
  }
}

int bsfirstp_entrypoint_9(s32 param_0)
{
  return D_8080B484_bsfirstp[param_0];
}

void bsfirstp_entrypoint_10(s32 param_0)
{
    PlayerState *local_4;
    u8 *local_5;
    u8 *local_0;
    f32 local_1[3];
    f32 local_2[3];
    f32 local_3[3];

    local_4 = (PlayerState *)func_800F53D0();
    local_5 = (u8 *)local_4->kazfly;
    local_0 = (u8 *)func_808027A8_bsfirstp(*(s16 *)(local_5 + 0xE8));
    func_808035EC_bsfirstp(local_4, local_1, local_3);
    func_800EF368(local_3, 90.0f);
    func_800EE780(local_2, local_1, local_3);
    func_800EF368(local_3, *(f32 *)(local_0 + 4));
    func_800EF1B8(local_3, yaw_get(local_4) - 90.0f, *(f32 *)(local_5 + 0x1D4) * 0.33f);
    func_8009E0AC(local_4, 0);
    func_80802A40_bsfirstp(local_4, *(s16 *)(local_5 + 0xE8));
    func_8009E0AC(local_4, 1);
    _baeggcursor_entrypoint_8(local_4);
    _bainvisible_entrypoint_7(local_4, 3, 1.0f, 1.0f, 0.25f);
    _baeggsetup_entrypoint_3(param_0, *(s16 *)(local_5 + 0xE8), local_1, local_2, local_3);
    func_80802CD8_bsfirstp(local_4, *(s16 *)(local_5 + 0xE8));
}

void func_808035EC_bsfirstp(PlayerState *param_0, f32 *param_1, f32 *param_2)
{
    f32 local_0[2];
    f32 local_1[2];
    f32 local_2[3];
    f32 local_3[3];
    f32 *local_4;

    local_4 = func_80802484_bsfirstp(param_0);
    _baeggcursor_entrypoint_3(param_0, &local_0[0], &local_0[1]);
    func_800C5008(func_800A4C68(param_0), local_0, local_1);
    func_800EFA4C(local_3, local_1[0], local_1[1], 100.0f);
    func_800C4E58(func_800A4C68(param_0), local_3, local_2);
    func_800A4CE8(param_0, param_1);
    func_800EFB24(param_2, local_2, param_1);
    func_8009C15C(param_0, param_1);
    param_2[1] += local_4[0x12] * 2.5f / func_800EEF94(param_2);
    param_1[1] += local_4[0x12];
    func_800EF368(param_2, 1.0f);
}

void func_808036F0_bsfirstp(u8 *param_0) {
    func_80807BB8_bsfirstp();
    func_800A38F0(param_0, 0, 1);
    func_808061AC_bsfirstp(param_0, 0);
    anctrl_setPlaybackType(baanim_getAnimCtrlPtr(param_0), 3);
    func_808001FC_bsfirstp(param_0);
    _chbaddiesetup_entrypoint_1(&_bsfirstp_entrypoint_12, *(s32 **)(param_0 + 0x184));
}

void func_80803760_bsfirstp(int param_0)
{
  int new_var;
  _batimer_set(param_0, 0, 5.0f);
}

int func_80803784_bsfirstp(Actor *param_0)
{
    s32 *local_0;
    local_0 = *(s32 **)((char *)param_0 + 0x188);
    if ((*(s32 *)((char *)local_0 + 0x114)) != 0)
    {
        func_8010114C(*(s32 *)((char *)local_0 + 0x114), 4, *(s32 *)((char *)param_0 + 0x184));
        (*(s32 *)((char *)local_0 + 0x114)) = 0;
    }
    func_800A38F0(param_0, 1, 1);
    func_80807C8C_bsfirstp(param_0);
}

int func_808037E4_bsfirstp(Actor *param_0)
{
  s32 local_0;
  local_0 = 0;
  if (_batimer_decrement(param_0, 0))
  {
    local_0 = 0xCA;
  }
  if (local_0 != 0)
  {
    bs_setState(param_0, local_0);
  }
}

void func_80803828_bsfirstp(u8 *param_0) {
    u8 *local_0 = *(u8 **)(param_0 + 0x188);
    if (func_8009E6EC(param_0) == 0xF) {
        if (*(s32 *)(local_0 + 0x114)) {
            *(s32 *)(local_0 + 0x114) = 0;
        }
    } else {
        bsfirstp_entrypoint_26(param_0);
    }
}

int bsfirstp_entrypoint_11(s32 param_0)
{
  return D_8080B494_bsfirstp[param_0];
}

void bsfirstp_entrypoint_12(s32 param_0) {
    u8 *local_0;
    u8 *local_1;
    f32 local_2[3];

    local_0 = func_800F53D0();
    if (bs_getCurrentState(local_0) == 0xD9) {
        local_1 = (*(u8 **)((s8 *)(local_0) + (0x188)));
        (*(s32 *)((s8 *)(local_1) + (0x114))) = _ch1pfreeze_entrypoint_1(param_0);
        func_8009C128(local_0, local_2);
        func_8010D930(7, -1, local_2, &D_8080B4A4_bsfirstp);
        _batimer_set(local_0, 0, 5.0f);
    }
}

void bsfirstp_entrypoint_13(PlayerState *param_0, f32 *param_1, s16 param_2)
{
    f32 local_0[3];
    f32 local_1[3];
    f32 local_2[3];

    if (baflag_isTrue(param_0, 0x3B)) {
        switch (param_2) {
        case 1: param_2 = 3; break;
        case 3: param_2 = 1; break;
        }
    }
    if (func_8009E674(param_0, 0x20, param_2)) param_2 = 2;
    switch (param_2) {
    case 1: func_800EE7F8(param_1, D_8080B4AC_bsfirstp); break;
    case 2: func_800EE7F8(param_1, D_8080B4B8_bsfirstp); break;
    case 3:
        func_800EE780(local_1, D_8080B4AC_bsfirstp, D_8080B4B8_bsfirstp);
        func_800EF334(local_1, 0.5f);
        func_800EFB24(local_2, D_8080B4C4_bsfirstp, local_1);
        func_800EF334(local_2, func_80803B68_bsfirstp(param_0));
        func_800EE780(param_1, local_1, local_2);
        break;
    }
    func_8009C128(param_0, local_0);
    func_800EF8BC(param_1, param_1, func_8009BFCC(param_0));
    func_800EF934(param_1, param_1, yaw_get(param_0));
    func_800EF04C(param_1, local_0);
}

void func_80803A84_bsfirstp(PlayerState *param_0)
{
    s32 local_0;

    for (local_0 = 0; local_0 < 2; local_0++) {
        func_8009E4E0(param_0, local_0, _bsfirstp_entrypoint_13);
    }
    func_8009E4E0(param_0, 2, NULL);
    func_80803B58_bsfirstp(param_0, 0.0f);
}

int func_80803B04_bsfirstp(s32 param_0)
{
  s32 local_0;
  int new_var;
  s32 local_1;
  local_1 = param_0 | 0;
  if (local_1)
  {
  }
  new_var = local_1 | 0;
  for (local_0 = 0; local_0 < 3; local_0++)
  {
    func_8009E4E0(new_var, local_0 | 0, 0);
  }

}

void func_80803B58_bsfirstp(u8 *param_0, f32 param_1)
{
  s8 *new_var;
  new_var = (s8 *) (*((u8 **) (((s8 *) param_0) + 0x188)));
  *((f32 *) (new_var + 0x110)) = param_1;
}

f32 func_80803B68_bsfirstp(param_0) void *param_0; {
    f32 *local_0;

    local_0 = *(f32 **)((u8 *)param_0 + 0x188);
    return local_0[0x44];
}

void bsfirstp_entrypoint_14(PlayerState *param_0)
{
    s32 local_8 = *(s32 *)((u8 *)param_0 + 0x184);
    s32 local_9;
    f32 local_0[3];
    f32 local_1;
    f32 local_2;
    f32 local_3[3];
    f32 local_4;
    f32 local_6;
    f32 local_5[3];
    f32 local_7;
    PlayerState *local_10;

    func_8009E154(param_0, 0, local_0);
    local_1 = func_8009E138(param_0, 0);
    for (local_9 = 0; local_9 < func_800F5898(); local_9++) {
        if (local_9 != local_8) {
            local_10 = func_800F53E4(local_9);
            if (local_10 != NULL) {
                local_2 = local_1 * local_1;
                func_8009E154(local_10, 2, local_3);
                func_8009E154(local_10, 1, local_5);
                local_4 = func_8009E138(local_10, 2);
                local_6 = func_8009E138(local_10, 1);
                local_7 = local_6 * local_6 + local_2;
                if (func_800EEB40(local_0, local_3) < local_4 * local_4 + local_2 || func_800EEB40(local_0, local_5) < local_7) func_800F7C58(local_9, 0x6D, local_8);
            }
        }
    }
}

s32 func_80803CD4_bsfirstp(PlayerState *param_0, s32 param_1, s32 param_2, s32 param_3, f32 *param_4)
{
    u8 *local_0;
    f32 local_3;
    int local_1;
    s32 local_2;
    local_0 = *(u8 **)((u8 *)param_0 + 0x188);
    if (func_8009CA70(param_0, bs_getCurrentState(param_0), 4)) return 0;
    if (func_8009BD44(param_0) == 3) return 0;
    if (_gcstatusDll_entrypoint_20() == 1) {
        if (_gcstatusDll_entrypoint_14() == 5) {
            if (_gcstatusDll_entrypoint_15() == *(s32 *)((u8 *)param_0 + 0x184)) {
                param_3 = 0; local_1 = 1; local_2 = 1;
            } else if (param_3) { local_1 = 1; local_2 = 2; }
            else { local_1 = 0; local_2 = 1; }
        } else { param_3 = 0; local_1 = 1; local_2 = 1; }
    } else {
        func_800A17A8(param_0, -param_3);
        if (func_800A1718(param_0)) { local_1 = 0; local_2 = 1; }
        else { local_1 = 1; local_2 = 2; }
    }
    if (local_1) func_80101180(0x2C4, 0x70, (*(s32 *)((u8 *)param_0 + 0x184) << 4) | param_2);
    local_3 = func_800F10B4(param_3, 0.0f, 8.0f, 0.8f, 1.4f);
    _bamotor_entrypoint_0(param_0, local_3, 0.25f);
    *(s32 *)(local_0 + 0xEC) = param_1;
    *(s32 *)(local_0 + 0xF0) = param_2;
    *(s32 *)(local_0 + 0xF4) = param_3;
    func_800EE7F8((f32 *)(local_0 + 0xF8), param_4);
    return local_2;
}

void func_80803E84_bsfirstp(u8 *param_0)
{
    u8 *local_0;
    s32 local_1;
    u8 *local_2;
    u8 *local_3;

    local_0 = *(u8 **)(param_0 + 0x188);
    local_1 = baanim_getAnimCtrlPtr();
    func_80807BB8_bsfirstp(param_0);
    func_808026AC_bsfirstp(param_0, &local_2, &local_3);
    func_80800424_bsfirstp(param_0, *(s16 *)(local_2 + 0), *(f32 *)(local_2 + 4));
    baanim_playForDuration_onceSmooth(param_0, *(s16 *)(local_3 + 0), *(f32 *)(local_3 + 4));
    anctrl_setSubrange(local_1, 0.0f, 0.43f);
    if (func_80802A40_bsfirstp(param_0, 0xA) == 0) {
        func_8009D89C(param_0, 1.0f);
    }
    _bainvisible_entrypoint_7(param_0, 3, 1.0, 1.0, 0.5);
    func_80808F38_bsfirstp(param_0);
    *(s32 *)(local_0 + 4) = 0;
    func_8009BDAC(param_0, 1.25f);
}

void func_80803F6C_bsfirstp(s32 arg0)
{
    func_808090D8_bsfirstp();
    func_80807C8C_bsfirstp(arg0);
}
void func_80803F94_bsfirstp(PlayerState *param_0)
{
    u8 *local_0 = *(u8 **)((u8 *)param_0 + 0x188);
    s32 local_1 = 0;
    AnimCtrl *local_2;

    func_80807D48_bsfirstp(param_0);
    func_80804848_bsfirstp(param_0, *(s32 *)(local_0 + 12));
    func_80801928_bsfirstp(param_0);
    func_80801DC0_bsfirstp(param_0);
    func_80808EF0_bsfirstp(param_0);
    func_80802F20_bsfirstp(param_0);
    func_80809198_bsfirstp(param_0);
    switch (*(s32 *)(local_0 + 4)) {
        case 0:
            if (func_8008DF8C(param_0, 0x5A)) {
                local_2 = baanim_getAnimCtrlPtr(param_0);
                anctrl_setSubrange(local_2, 0.0f, 1.0f);
                anctrl_setPlaybackType(local_2, 1);
                *(s32 *)(local_0 + 4) = 1;
            }
            break;
        case 1:
            if (player_isStable(param_0)) {
                *(s32 *)(local_0 + 4) = 2;
                func_800F7F98(*(s32 *)((u8 *)param_0 + 0x184), 0);
            }
            break;
        case 2:
            func_80809D24_bsfirstp(param_0);
            func_8080682C_bsfirstp(param_0);
            func_808099B4_bsfirstp(param_0);
            local_1 = func_808094F4_bsfirstp(param_0);
            if (local_1 == 0xCA && !baanim_isStopped(param_0)) local_1 = 0;
            break;
    }
    bs_setState(param_0, local_1);
}

int bsfirstp_entrypoint_15(s32 param_0)
{
  return D_8080B4D0_bsfirstp[param_0];
}

void func_80804104_bsfirstp(PlayerState *param_0, FirstPersonAnimationEvent *param_1, FirstPersonAnimationEvent *param_2)
{
    if (param_1->local_0) func_80800424_bsfirstp(param_0, param_1->local_0, param_1->local_1);
    baanim_playForDuration_onceSmooth(param_0, param_2->local_0, param_2->local_1);
    func_800FC660(11);
    if (!func_80802A40_bsfirstp(param_0, 11)) func_8009D89C(param_0, 1.0f);
    _bainvisible_entrypoint_3(param_0);
    baphysics_set_target_horizontal_velocity(param_0, 0.0f);
    param_0->unk15C.word = 0;
    func_80808F38_bsfirstp(param_0);
    if (!func_800D3948()) _basudie_entrypoint_1(param_0);
    if (!func_800EA068(8)) func_800F7E64(param_0->unk184, 1);
}

int func_808041D0_bsfirstp(Actor *param_0)
{
  s32 local_0;
  s32 local_1;
  func_80807BB8_bsfirstp(param_0);
  func_80802700_bsfirstp(param_0, &local_0, &local_1);
  func_80804104_bsfirstp(param_0, local_0, local_1);
}

void func_80804210_bsfirstp(s32 arg0)
{
    func_808090D8_bsfirstp();
    func_80807C8C_bsfirstp(arg0);
}
void func_80804238_bsfirstp(void *param_0) {
    s32 state = ((s32 *) param_0)[0];
    s32 unk184 = ((s32 *) param_0)[0x61];
    s32 local_0;

    local_0 = ((s32 *) param_0)[87];
    switch (local_0) {
    case 0:
        if (anctrl_isStopped(baanim_getAnimCtrlPtr(param_0)) != 0) {
            _batimer_set(param_0, 0, 3.0f);
            func_800A38F0(param_0, 0, 1);
            ((s32 *) param_0)[87] = 1;
        }
        break;
    case 1:
        if (_batimer_decrement(param_0, 0) != 0) {
            if (func_800D3948() != 0) {
                func_80101180(0x2C4, 0x71, ((s32 *) param_0)[0x61]);
            } else {
                _basudie_entrypoint_0(param_0);
            }
            ((s32 *) param_0)[87] = 2;
        }
        break;
    }
    func_80809198_bsfirstp(param_0);
    func_80807D48_bsfirstp(param_0);
    func_80809250_bsfirstp(param_0);
}

int bsfirstp_entrypoint_16(s32 param_0)
{
  return D_8080B4E0_bsfirstp[param_0];
}

int func_8080432C_bsfirstp(Actor *param_0)
{
  s32 local_0;
  s32 local_1;
  func_80807BB8_bsfirstp();
  func_80802754_bsfirstp(param_0, &local_0, &local_1);
  func_80804104_bsfirstp(param_0, local_0, local_1);
}

void func_8080436C_bsfirstp(s32 arg0)
{
    func_808090D8_bsfirstp();
    func_80807C8C_bsfirstp(arg0);
}
int func_80804394_bsfirstp(Actor *param_0)
{
    s32 state = ((s32 *) param_0)[0];
    s32 unk184 = ((s32 *) param_0)[0x61];
    s32 local_0;

    local_0 = ((s32 *) param_0)[87];
    switch (local_0) {
    case 0:
        if (anctrl_isStopped(baanim_getAnimCtrlPtr(param_0)) != 0) {
            _batimer_set(param_0, 0, 3.0f);
            func_800A38F0(param_0, 0, 1);
            ((s32 *) param_0)[87] = 1;
        }
        break;
    case 1:
        if (_batimer_decrement(param_0, 0) != 0) {
            if (func_800D3948() != 0) {
                func_80101180(0x2C4, 0x71, ((s32 *) param_0)[0x61]);
            } else {
                _basudie_entrypoint_0(param_0);
            }
            ((s32 *) param_0)[87] = 2;
        }
        break;
    }
    func_80809198_bsfirstp(param_0);
    func_80809250_bsfirstp(param_0);
    func_80807D48_bsfirstp(param_0);
}

int bsfirstp_entrypoint_17(s32 param_0)
{
  return D_8080B4F0_bsfirstp[param_0];
}

void func_80804488_bsfirstp(param_0, param_1, param_2, param_3) PlayerState *param_0; s32 param_1; s32 param_2; f32 *param_3;
{
    s32 local_0;
    f32 local_1;
    f32 local_2;

    local_0 = bakey_held(param_0, param_1) ? 1 : 0;
    local_0 += bakey_held(param_0, param_2) ? 2 : 0;
    switch (local_0) {
    case 0:
    case 3: local_1 = 0.0f; break;
    case 1: local_1 = -1.0f; break;
    case 2: local_1 = 1.0f; break;
    }
    if (local_1 == -param_3[1]) local_2 = 0.667f;
    else if (local_1 == 0.0f) local_2 = 0.5f;
    else local_2 = 0.333f;
    if (mlAbsF(local_1 - param_3[0]) < local_2) {
        param_3[0] = local_1;
        param_3[1] = local_1;
    } else if (param_3[0] < local_1) param_3[0] += local_2;
    else param_3[0] -= local_2;
}

void func_808045FC_bsfirstp(void *param_0, f32 param_1)
{
    f32 local_0;
    f32 local_1;
    f32 local_2;

    switch (((Mass46FirstPersonTrend *)param_0)->local_3) {
    case -1:
        if (param_1 < ((Mass46FirstPersonTrend *)param_0)->local_0) {
            ((Mass46FirstPersonTrend *)param_0)->local_5 = param_1;
        }
        if (param_1 == ((Mass46FirstPersonTrend *)param_0)->local_0 && param_1 == 0.0f) {
            ((Mass46FirstPersonTrend *)param_0)->local_3 = 0;
        }
        if (param_1 > ((Mass46FirstPersonTrend *)param_0)->local_0 && param_1 > ((Mass46FirstPersonTrend *)param_0)->local_4) {
            ((Mass46FirstPersonTrend *)param_0)->local_6 = param_1;
            ((Mass46FirstPersonTrend *)param_0)->local_3 = 1;
        }
        break;
    case 0:
        if (param_1 < 0.0f) {
            ((Mass46FirstPersonTrend *)param_0)->local_3 = -1;
            ((Mass46FirstPersonTrend *)param_0)->local_5 = param_1;
            ((Mass46FirstPersonTrend *)param_0)->local_6 = 0.0f;
        } else if (param_1 > 0.0f) {
            ((Mass46FirstPersonTrend *)param_0)->local_3 = 1;
            ((Mass46FirstPersonTrend *)param_0)->local_5 = 0.0f;
            ((Mass46FirstPersonTrend *)param_0)->local_6 = param_1;
        }
        break;
    case 1:
        if (param_1 > ((Mass46FirstPersonTrend *)param_0)->local_0) {
            ((Mass46FirstPersonTrend *)param_0)->local_6 = param_1;
        }
        if (param_1 == ((Mass46FirstPersonTrend *)param_0)->local_0 && param_1 == 0.0f) {
            ((Mass46FirstPersonTrend *)param_0)->local_3 = 0;
        }
        if (param_1 < ((Mass46FirstPersonTrend *)param_0)->local_0 && param_1 < ((Mass46FirstPersonTrend *)param_0)->local_4) {
            ((Mass46FirstPersonTrend *)param_0)->local_5 = param_1;
            ((Mass46FirstPersonTrend *)param_0)->local_3 = -1;
        }
        break;
    }
    ((Mass46FirstPersonTrend *)param_0)->local_4 = ((Mass46FirstPersonTrend *)param_0)->local_0;
    ((Mass46FirstPersonTrend *)param_0)->local_0 = param_1;
    ((Mass46FirstPersonTrend *)param_0)->local_2 = ((Mass46FirstPersonTrend *)param_0)->local_6 - ((Mass46FirstPersonTrend *)param_0)->local_5;
    local_0 = func_800F2108(param_1);
    local_1 = param_1 * local_0 + 1.0f;
    local_2 = local_1 * local_1;
    ((Mass46FirstPersonTrend *)param_0)->local_1 = (local_1 * local_2 - 1.0f) * (local_0 / 7.0f);
}

void func_808047EC_bsfirstp(Actor *param_0)
{
    u8 *local_0;

    local_0 = *(u8 **)((char *)param_0 + 0x188);
    bzero(local_0 + 0x12C, 0x38);
    bzero(local_0 + 0x164, 0x38);
    func_80804848_bsfirstp(param_0, *(s32 **)(local_0 + 0xC));
}

int func_8080483C_bsfirstp(Actor *param_0, s32 param_1)
{
    s32 *local_0 = *(s32 **)((char *)(param_0) + 0x188);
    *(s32 *)((char *)(local_0) + 0x118) = param_1;
}

void func_80804848_bsfirstp(param_0, param_1) PlayerState *param_0; s32 param_1;
{
    u8 *local_0;
    f32 local_1;
    f32 local_2;
    f32 local_3;
    local_0 = *(u8 **)((u8 *)param_0 + 0x188);
    func_80804488_bsfirstp(param_0, 10, 13, local_0 + 0x11C);
    func_80804488_bsfirstp(param_0, 11, 12, local_0 + 0x124);
    switch (param_1) {
    case -1:
        func_808045FC_bsfirstp(local_0 + 0x12C, 0.0f);
        func_808045FC_bsfirstp(local_0 + 0x148, 0.0f);
        func_808045FC_bsfirstp(local_0 + 0x164, 0.0f);
        func_808045FC_bsfirstp(local_0 + 0x180, 0.0f);
        break;
    case 0:
        if (*(s32 *)(local_0 + 0x118)) local_1 = 0.0f;
        else local_1 = bastick_getY(param_0);
        if (*(s32 *)(local_0 + 0x118)) local_2 = bastick_getY(param_0);
        else local_2 = *(f32 *)(local_0 + 0x124);
        func_808045FC_bsfirstp(local_0 + 0x12C, *(f32 *)(local_0 + 0x11C));
        func_808045FC_bsfirstp(local_0 + 0x148, local_1);
        func_808045FC_bsfirstp(local_0 + 0x164, bastick_getX(param_0));
        func_808045FC_bsfirstp(local_0 + 0x180, local_2);
        break;
    case 1:
        if (*(s32 *)(local_0 + 0x118)) local_3 = 0.0f;
        else local_3 = *(f32 *)(local_0 + 0x124);
        func_808045FC_bsfirstp(local_0 + 0x12C, *(f32 *)(local_0 + 0x11C));
        func_808045FC_bsfirstp(local_0 + 0x148, local_3);
        func_808045FC_bsfirstp(local_0 + 0x164, bastick_getX(param_0));
        func_808045FC_bsfirstp(local_0 + 0x180, bastick_getY(param_0));
        break;
    }
}

int bsfirstp_entrypoint_18(Actor *param_0, s32 param_1)
{
  Actor *local_0;
  local_0 = func_800F53D0(param_1);
  bs_setState(local_0, 0xC8);
  *(s32 *)((char *)local_0 + 0x15c) = 1;
}

void func_80804A34_bsfirstp(s32 arg0) 
{
}
void func_80804A3C_bsfirstp(u8 *param_0)
{
    func_80101238(0x77, *(s32 **)(param_0 + 0x184), param_0);
}

void func_80804A64_bsfirstp(PlayerState *param_0)
{
    s32 local_0;

    local_0 = 1;
    if (func_8009E6EC(param_0) == 0x62) {
        if (!func_800A3404(param_0)) {
            func_80807EEC_bsfirstp(param_0);
            if (bs_getCurrentState(param_0) == 0xC8) {
                func_80800888_bsfirstp(param_0, 1);
            } else {
                func_80800888_bsfirstp(param_0, 0);
            }
            local_0 = 2;
        }
    } else {
        bsfirstp_entrypoint_26(param_0);
        return;
    }
    func_8009E830(param_0, local_0);
}

int func_80804B10_bsfirstp(s32 param_0)
{
  s32 local_0;
  volatile unsigned int new_var;
  local_0 = param_0 | 0;
  func_80807BB8_bsfirstp();
  func_800A3410(local_0, 9 ^ 0);
  func_80807DD4_bsfirstp(local_0);
  func_800936E8(local_0, 0);
  baanim_playForDuration_onceSmooth((PlayerState *)local_0, 0x30C, 2.0f);
  func_808003B4_bsfirstp(local_0, 0x310, 2.0f);
  func_80804A34_bsfirstp(1);
  *(s32 *)((char *)(param_0) + 0x15C) = 0;
}

void func_80804B84_bsfirstp(s32 param_0)
{
    func_80807C8C_bsfirstp(param_0);
}
void func_80804BA4_bsfirstp(PlayerState *param_0)
{
    func_80807D48_bsfirstp(param_0);
    func_80809D24_bsfirstp(param_0);
    if (!func_800A3404(param_0)) {
        if (baanim_isAt(param_0, 0.1081f)) func_800936E8(param_0, 1);
        if (baanim_isAt(param_0, 0.25f)) func_8009DE38(param_0, 0x442E, 1.117f);
        if (*(s32 *)((u8 *)param_0 + 0x15C) == 0 && baanim_isAt(param_0, 0.4f)) func_80801A34_bsfirstp(param_0);
        if (baanim_isAt(param_0, 0.5f)) func_8009DB04(param_0, 0x4639, 1.0f, 20000);
        if (baanim_isAt(param_0, 0.61f)) func_8009DB04(param_0, 0x463A, 1.0f, 20000);
        if (*(s32 *)((u8 *)param_0 + 0x15C) == 1) {
            if (baanim_isStopped(param_0)) {
                func_80804A3C_bsfirstp(param_0);
                *(s32 *)((u8 *)param_0 + 0x15C) = 2;
            }
            func_80801928_bsfirstp(param_0);
        }
    } else {
        func_80801928_bsfirstp(param_0);
        if (!func_808008B0_bsfirstp(param_0)) {
            bs_setState(param_0, 0xCA);
            func_80804A3C_bsfirstp(param_0);
        }
    }
}

int bsfirstp_entrypoint_19(s32 param_0)
{
  return D_8080B500_bsfirstp[param_0];
}

s32 func_80804D18_bsfirstp(long param_0)
{
  s32 s0;
  func_80807BB8_bsfirstp();
 s0 = param_0; func_80807DD4_bsfirstp(s0);
  baanim_playForDuration_loopStartingAt(s0, 0x30D, 0x40000000, 0.503600001f);
  func_808002CC_bsfirstp(s0, 0x311, 2.0f, 0.503600001f);
  if (((!s0) && (!s0)) && (!s0))
  {
  }
  func_80801A34_bsfirstp(s0);
}

void func_80804D80_bsfirstp(s32 param_0)
{
    func_80807C8C_bsfirstp(param_0);
}
int func_80804DA0_bsfirstp(Actor *param_0)
{
  s32 local_0;
  Actor *local_1 = param_0;
  func_80807D48_bsfirstp(local_1);
  func_80809D24_bsfirstp(local_1);
  if (func_800A3404(local_1))
  {
    func_80801928_bsfirstp(local_1);
    if (!func_808008B0_bsfirstp(local_1))
    {
      bs_setState(local_1, 0xCA);
      func_80804A3C_bsfirstp(local_1);
    }
  }
}

int bsfirstp_entrypoint_20(s32 param_0)
{
  return D_8080B510_bsfirstp[param_0];
}

s32 func_80804E1C_bsfirstp(s32 param_0) {
    if (func_800A3404(param_0) || _glcutDll_entrypoint_1()) {
        func_80807BB8_bsfirstp(param_0);
        func_80807F5C_bsfirstp(param_0);
    } else {
        func_80807BB8_bsfirstp(param_0);
        func_80807DD4_bsfirstp(param_0);
        baanim_playForDuration_loopStartingAt(param_0, 0x30D, 0x40000000, 0.503600001f);
        func_808002CC_bsfirstp(param_0, 0x311, 2.0f, 0.503600001f);
    }
}

void func_80804EB4_bsfirstp(s32 param_0)
{
    func_80807C8C_bsfirstp(param_0);
}
int func_80804ED4_bsfirstp(Actor *param_0)
{
  s32 local_0;
  func_80807D48_bsfirstp(param_0);
  local_0 = func_800EA068(8) ? 0xCB : 0xC9;
  bs_setState(param_0, local_0);
}

int bsfirstp_entrypoint_21(s32 param_0)
{
  return D_8080B520_bsfirstp[param_0];
}

void func_80804F28_bsfirstp(Actor *param_0)
{
  void *local_0;
  ;
  func_80807BB8_bsfirstp();
  baanim_playForDuration_onceSmoothStartingAt(param_0, 0x30C, 2.0f, 0x3EC00000);
  func_8008B188(baanim_getAnimCtrlPtr(param_0), 0);
  func_80800340_bsfirstp(param_0, 0x310, 2.0f, 0.375f);
  func_8008B188(func_8008D04C(param_0), 0);
  func_80804A34_bsfirstp(0);
  func_808061AC_bsfirstp(param_0, 0);
}

void func_80804FB4_bsfirstp(s32 param_0)
{
    func_80807C8C_bsfirstp(param_0);
}
void func_80804FD4_bsfirstp(void *param_0) {
    s32 s0;

    s0 = (s32) param_0;
    func_80807D48_bsfirstp(s0);
    if (baanim_isAt(s0, 0.3f) != 0) {
        func_8009DBF0(s0, 0x45A5, 0x3F800000);
    }
    if (baanim_isStopped(s0) != 0) {
        func_800A3410(s0, 1);
        bs_setState(s0, 1);
    }
}

int bsfirstp_entrypoint_22(s32 param_0)
{
  return D_8080B530_bsfirstp[param_0];
}

int func_80805058_bsfirstp(Actor *param_0)
{
  _bsdrone_entrypoint_0();
  func_80807BB8_bsfirstp(param_0);
  baanim_playForDuration_loopStartingAt(param_0, 0x30D, 0x40000000, 0.503600001f);
  func_808002CC_bsfirstp(param_0, 0x311, 2.0f, 0.503600001f);
}

void func_808050B0_bsfirstp(s32 arg0)
{
    _bsdrone_entrypoint_2();
    func_80807C8C_bsfirstp(arg0);
}
void func_808050D8_bsfirstp(s32 arg0)
{
    _bsdrone_entrypoint_1();
    func_80807D48_bsfirstp(arg0);
    func_80809D24_bsfirstp(arg0);
}

int bsfirstp_entrypoint_23(s32 param_0)
{
  return D_8080B540_bsfirstp[param_0];
}

s32 func_8080511C_bsfirstp(s32 param_0){
    _bsdrone_entrypoint_0(param_0);
    func_80807BB8_bsfirstp(param_0);
    if (func_800A3404(param_0) != 0) {
        func_80807F24_bsfirstp(param_0);
    }
    baanim_playForDuration_loop(param_0, 0x30E, 0x3FC00000);
    func_8008C990(param_0, 0x3F000000);
    func_80800488_bsfirstp(param_0, 0x312, 1.5f);
    func_80800264_bsfirstp(param_0, 0.5f);
}

void func_8080519C_bsfirstp(s32 arg0)
{
    _bsdrone_entrypoint_2();
    func_80807C8C_bsfirstp(arg0);
}
void func_808051C4_bsfirstp(s32 arg0)
{
    _bsdrone_entrypoint_1();
    func_80807D48_bsfirstp(arg0);
    func_80809D24_bsfirstp(arg0);
}

int bsfirstp_entrypoint_24(s32 param_0)
{
  return D_8080B550_bsfirstp[param_0];
}

void bsfirstp_entrypoint_25(void *param_0, f32 param_1)
{
  s32 pad0;
  void *local_0;
  f32 local_1;
  float new_var;
  local_1 = mlAbsF(param_1) * 0.003333333414f;
  new_var = 1.0f;
  if (local_1 > new_var)
  {
    local_1 = new_var;
  }
  anctrl_setDuration(baanim_getAnimCtrlPtr(param_0), (local_1 * (0.75f - new_var)) + new_var);
  anctrl_setDuration(func_8008D04C(param_0), (local_1 * (0.75f - new_var)) + new_var);
}

s32 func_808052A4_bsfirstp(f32 *param_0, f32 *param_1)
{
  f32 local_0;
  local_0 = (*param_0) / 2;
  *param_0 = (*param_1) + local_0;
  *param_1 = local_0;
}

f32 func_808052C8_bsfirstp(f32 *param_0, f32 param_1, f32 param_2, f32 param_3)
{

    f32 local_0;
    f32 local_1;
    f32 local_2;
    f32 local_3;

    local_3 = 0.0f;
    if (param_3 != 0.0f) {
        if (param_1 != (*param_0)) {
            if (param_1 < (*param_0)) param_2 = -param_2;
            local_1 = (param_1 - (*param_0)) / param_2;
            if (local_1 <= param_3) local_2 = param_1;
            else {
                local_1 = param_3;
                local_2 = (*param_0) + param_2 * param_3;
            }
            local_0 = *param_0;
            *param_0 = local_2;
            local_3 += ((local_0 + local_2) * 0.5f) * local_1;
            param_3 -= local_1;
        }
        local_3 += *param_0 * param_3;
    }
    return local_3;
}

void func_80805380_bsfirstp(f32 *param_0, f32 param_1, f32 param_2, f32 param_3)
{
    s32 local_0;
    f32 local_1;
    f32 local_2;
    local_0 = func_800D8FEC();
    while (local_0 != 0) {
        local_1 = func_80013728(param_1 - *param_0);
        local_2 = local_1 * param_3;
        if (local_2 != 0.0f) {
            if (local_2 < 0.0f) local_2 = func_800F0D50(local_2, -param_2, -3.0f);
            else local_2 = func_800F0D50(local_2, 3.0f, param_2);
        }
        *param_0 += func_800F212C(local_2 * (1.0f / 60.0f), local_1);
        local_0--;
    }
    *param_0 = func_80013728(*param_0);
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

f32 func_80805644_bsfirstp(f32 *p0, f32 p1, f32 p2, f32 *p3, f32 p4)
{
    f32 S;
    f32 f22;
    f32 g1;
    f32 r;
    f32 f10;
    f32 ratio2;
    f32 ret;
    f32 f14;
    f32 f12;

    S = p4 * 0.6366198063f;
    f22 = p3[0] / S;
    f14 = p0[0] / p2;
    g1 = func_80013A5C(1.0f - f14);
    ratio2 = p1 / p2;
    r = func_80013A5C(1.0f - ratio2);
    f14 = r;
    if (f22 < (r - g1)) {
        f14 = g1 + f22;
    }
    f22 = f22 - (f14 - g1);
    if (f22 < 9.999999975e-07f) {
        f22 = 0.0f;
    }
    f12 = (f14 - func_800137D4(f14)) - (g1 - func_8001395C(g1));
    if (f12 < 9.999999975e-07f) {
        f12 = 0.0f;
    }
    f14 = 1.0f - (func_80013788(f12));
    f10 = ratio2 - 9.999999975e-07f;
    if (f10 < f14) {
        f14 = ratio2;
    }
    p3[0] = S * f22;
    p0[0] = p2 * f14;
    ret = (S * p2) * f12;
    return ret;
}

f32 func_808057C8_bsfirstp(f32 *param_0, f32 param_1, f32 param_2, f32 param_3, f32 param_4)
{
    f32 local_0;
    f32 local_1;
    f32 local_2;
    f32 local_3;
    f32 local_4;

    local_0 = 0.0f;
    if (*param_0 * (param_1 - *param_0) < 0.0f) {
        local_0 = func_8080549C_bsfirstp(param_0, param_1, param_2, &param_3, param_4);
    }
    if (param_3 != 0.0f) {
        if (param_1 >= 0.0f) {
            local_1 = 1.0f;
        } else {
            local_1 = -1.0f;
        }
        local_2 = *param_0 * local_1;
        if (local_2 < param_1 * local_1) {
            local_0 += local_1 * func_80805644_bsfirstp(&local_2, param_1 * local_1, param_2, &param_3, param_4);
            *param_0 = local_1 * local_2;
        }
    }
    local_0 += *param_0 * param_3;
    return local_0;
}

void func_808058F0_bsfirstp(PlayerState *param_0)
{
    s32 local_0;
    s32 local_2;
    s32 local_1;
    local_0 = 0;
    local_2 = func_8009E6EC(param_0);
    local_1 = 1;
    if (local_2 == 0x83) {
        local_1 = 2;
        local_0 = 0xCA;
        func_8009BDAC(param_0, 1.5f);
        func_80807D70_bsfirstp(param_0);
        func_80801A5C_bsfirstp(param_0);
        func_8009337C(param_0, 0);
        func_800936E8(param_0, 1);
        func_80093370(param_0, 1);
    }
    func_8009E830(param_0, local_1);
    bs_setState(param_0, local_0);
}

void bsfirstp_entrypoint_26(param_0) Actor *param_0;
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
    state = func_8009E6EC(param_0);
    transition = 1;

    switch (state) {
        default:
            func_80099B94(param_0);
            return;

        case 0x99:
            func_808019EC_bsfirstp(param_0);
            break;

        case 0x4C:
            func_80099A7C(param_0, local_vec);
            _baduo_entrypoint_14(param_0, local_vec);

            next_state = 0xD7;
            transition = 2;
            break;

        case 0x4F:
            transition = 2;
            break;

        case 0x61:
            switch (func_80099A58(param_0)) {
                case 0:
                    next_state = 0xCC;
                    break;

                case 1:
                    func_800A3544(param_0, 0);
                    next_state = 0xC8;
                    break;

                case 2:
                    next_state = 0xC9;
                    break;
            }

            func_800F7E64(
                *(s32 *)((char *)param_0 + 0x184),
                9
            );

            transition = 2;
            break;

        case 0x73:
            func_80807EEC_bsfirstp(param_0);
            func_80801A5C_bsfirstp(param_0);
            transition = 2;
            break;

        case 0x62:
            if (func_800A3404(param_0) == 0) {
                func_80807EEC_bsfirstp(param_0);
                transition = 2;
            }
            break;

        case 0x63:
            if (func_800A3404(param_0) != 0) {
                func_80807F24_bsfirstp(param_0);
                transition = 2;
            }
            break;

        case 0x72:
            if (bs_getCurrentState(param_0) == 0xD2) {
                func_80808678_bsfirstp(param_0, func_80099A4C(param_0));
                transition = 2;
            }
            break;

        case 0x5F:
            speed = func_80099A34(param_0);
            func_80802BE8_bsfirstp(param_0, speed);

            transition = 2;
            break;

        case 0x47:
            egg_value = _suegg_entrypoint_6(
                func_80099A4C(param_0),
                egg_pos,
                &egg_type
            );

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
                    if (bs_getCurrentState(param_0) != 0xD9) {
                        primary_state = 0xD9;
                        secondary_state = 0;
                    } else {
                        func_80803760_bsfirstp(param_0);
                        primary_state = 0;
                        secondary_state = 0;
                    }
                    break;
            }

            result = func_80803CD4_bsfirstp(
                param_0,
                state,
                egg_value,
                egg_mode,
                egg_pos
            );

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
                    _badeathmatch_entrypoint_5(param_0, 6, 1);
                    _sueggmisc_entrypoint_2(egg_pos, 6);
                }

                transition = 2;
                break;
            }
            break;

        case 0x6D:
            value_6d = func_80099A58(param_0);
            func_800F5A00(value_6d, temp_vec);

            result = func_80803CD4_bsfirstp(
                param_0,
                state,
                value_6d,
                1,
                temp_vec
            );

            switch (result) {
            case 1:
                next_state = 0xDA;
                transition = 2;
                break;
            case 2:
                next_state = 0xDB;
                transition = 2;
                break;
            }
            break;

        case 0x4E:
            value[0] = func_80099A70(param_0);
            value_2 = func_80099A58(param_0);
            func_80099A7C(param_0, temp_vec_2);

            result = func_80803CD4_bsfirstp(
                param_0,
                state,
                value[0],
                value_2,
                temp_vec_2
            );

            switch (result) {
            case 1:
                next_state = 0xDA;
                transition = 2;
                break;
            case 2:
                next_state = 0xDC;
                transition = 2;
                break;
            }
            break;

        case 0x20:
            func_80099A7C(param_0, temp_vec_3);

            result = func_80803CD4_bsfirstp(
                param_0,
                state,
                -1,
                1,
                temp_vec_3
            );

            switch (result) {
            case 1:
                next_state = 0xDA;
                transition = 2;
                break;
            case 2:
                next_state = 0xDB;
                transition = 2;
                break;
            }
            break;

        case 0x51:
            func_8009C15C(param_0, temp_vec_4);

            result = func_80803CD4_bsfirstp(
                param_0,
                state,
                -1,
                1,
                temp_vec_4
            );

            switch (result) {
            case 1:
                next_state = 0xDA;
                transition = 2;
                break;
            case 2:
                next_state = 0xDC;
                transition = 2;
                break;
            }
            break;

        case 0x45:
            func_800EFD24(temp_vec_5);

            result = func_80803CD4_bsfirstp(
                param_0,
                state,
                -1,
                8,
                temp_vec_5
            );

            if (result != 0) {
                next_state = 0xDB;
                transition = 2;
            }
            break;

        case 0x21:
        case 0x24:
            func_800EFD24(temp_vec_6);

            result = func_80803CD4_bsfirstp(
                param_0,
                state,
                -1,
                1,
                temp_vec_6
            );

            switch (result) {
            case 1:
                next_state = 0xDA;
                transition = 2;
                break;
            case 2:
                next_state = 0xDB;
                transition = 2;
                break;
            }
            break;

    }

    func_8009E830(param_0, transition);
    bs_setState(param_0, next_state);
}

void func_80805F48_bsfirstp(s32 arg0)
{
    func_808061AC_bsfirstp(arg0,0);
}

void func_80805F68_bsfirstp()
{
    func_8009B4FC();
}

void bsfirstp_entrypoint_27(u8 *param_0)
{
  s32 temp_v1;
  u8 *ptr;
  ptr = *((u8 **) (param_0 + 0x188));
  temp_v1 = *((s32 *) (ptr + 0x19C));
  switch (temp_v1)
  {
    case 1:
      break;

    default:
      func_80806774_bsfirstp();
      break;

    case 2:
      func_8080649C_bsfirstp(param_0);
      break;

    case 3:
      func_80806588_bsfirstp(param_0);
      break;

  }

  if (param_0 && param_0)
  {
  }
  func_80806000_bsfirstp(param_0);
}

void func_80806000_bsfirstp(param_0) PlayerState *param_0;
{
    u8 *local_0;
    u8 *local_1;
    f32 *local_2;
    f32 local_3;
    f32 local_4;
    f32 local_5;
    f32 local_6;
    f32 local_7;
    f32 local_8;

    local_0 = *(u8 **)((u8 *)param_0 + 0x188);
    local_1 = (u8 *)func_80802458_bsfirstp(param_0);
    local_2 = (f32 *)(local_0 + 0x1B8);
    local_2[0] = *(f32 *)(local_0 + 0x1D4);
    local_2[1] = 0.0f;
    local_2[2] = baphysics_get_target_horizontal_velocity(param_0);
    local_3 = -func_80013728(func_8009BB18(param_0) - yaw_get(param_0));
    func_800EF934(local_2, local_2, local_3);
    local_4 = func_800EEFFC(local_2);
    local_6 = func_800F0E00(*(f32 *)(local_1 + 0x2C), local_4);
    local_5 = 1.0f / local_6;
    local_2[0] *= local_5;
    local_2[2] *= local_5;
    local_2[3] = local_4 * local_5;
    local_7 = mlAbsF(local_2[0]);
    local_8 = func_80013B7C(local_7, mlAbsF(local_2[2]));
    if (local_2[0] < 0.0f) {
        local_2[4] = local_8;
    } else {
        local_2[4] = -local_8;
    }
}

f32 func_80806130_bsfirstp(void *param_0) {
    f32 *local_0;

    local_0 = *(f32 **)((u8 *)param_0 + 0x188);
    return local_0[0x72];
}

f32 func_8080613C_bsfirstp(void *param_0) {
    f32 *local_0;

    local_0 = *(f32 **)((u8 *)param_0 + 0x188);
    return local_0[0x71];
}

s32 func_80806148_bsfirstp(s32 param_0, s32 param_1)
{
  s32 local_0 = *(s32 *)(param_0 + 0x188);
  func_800EE7F8(param_1, local_0 + 0x1b8);
}

f32 func_80806170_bsfirstp(void *param_0, f32 param_1)
{
    FirstPersonScaleView *local_0;

    local_0 = (FirstPersonScaleView *)func_80802458_bsfirstp(param_0);
    param_1 /= local_0->unk2C;
    return func_800F0DC0(param_1, 1.0f);
}

void func_808061AC_bsfirstp(param_0, param_1) PlayerState *param_0; s32 param_1;
{
    u8 *local_2;
    u8 *local_0;
    f32 local_1;
    local_2 = *(u8 **)((u8 *)param_0 + 0x188);
    local_0 = (u8 *)func_80802458_bsfirstp(param_0);
    switch (param_1) {
        case 0:
            baphysics_set_gravity(param_0, *(f32 *)(local_0 + 0x20));
            func_80806774_bsfirstp(param_0);
            baphysics_set_type(param_0, 0);
            break;
        case 1:
            baphysics_set_gravity(param_0, *(f32 *)(local_0 + 0x20));
            baphysics_set_type(param_0, 0x10);
            baphysics_set_target_horizontal_velocity(param_0, 0);
            break;
        case 2:
            baphysics_set_gravity(param_0, *(f32 *)(local_0 + 0x24));
            *(f32 *)(local_2 + 0x1D8) = 0.0f;
            *(f32 *)(local_2 + 0x1D4) = 0.0f;
            baphysics_set_type(param_0, 0x10);
            break;
        case 3:
            baphysics_set_gravity(param_0, *(f32 *)(local_0 + 0x24));
            if (*(s32 *)(local_2 + 0x19C) != 3) {
                func_800F3BB0(param_0, local_2 + 0x1A0);
                func_800EE7F8(local_2 + 0x1AC, local_2 + 0x1A0);
                *(f32 *)(local_2 + 0x1DC) = 0.0f;
                local_1 = func_8009BB5C(param_0);
                *(f32 *)(local_2 + 0x1E4) = -func_800138D0(func_80013728(
                    (*(f32 *)(*(u8 **)((u8 *)param_0 + 0xC8) + 0x40) - yaw_get(param_0)) - 90.0f)) * local_1;
                *(f32 *)(local_2 + 0x1E0) = *(f32 *)(local_0 + 0x44) * *(f32 *)(local_2 + 0x12C);
            }
            baphysics_set_type(param_0, 0x11);
            break;
    }
    *(s32 *)(local_2 + 0x19C) = param_1;
}

void func_8080633C_bsfirstp(PlayerState *param_0, f32 param_1)
{
    u8 *local_0;
    u8 *local_1;
    FpStick *local_2;
    f32 local_3;
    f32 local_4;
    f32 local_5;
    f32 local_6;
    f32 local_7;

    local_0 = *(u8 **)((u8 *)param_0 + 0x188);
    local_1 = (u8 *)func_80802458_bsfirstp(param_0);
    local_2 = (FpStick *)(local_0 + 0x12C);
    local_4 = 1.0f - *(f32 *)(local_1 + 0x30) * mlAbsF(func_80809938_bsfirstp(param_0));
    local_5 = 1.0f - *(f32 *)(local_1 + 0x40) * mlAbsF(func_80809938_bsfirstp(param_0));
    local_7 = func_800F122C(*(f32 *)(local_0 + 0x148), *(f32 *)(local_1 + 0x28), *(f32 *)(local_1 + 0x2C)) * (local_4 * param_1);
    local_6 = yaw_get(param_0);
    baphysics_set_target_horizontal_velocity(param_0, local_7);
    baphysics_set_target_yaw(param_0, local_6);
    *(f32 *)(local_0 + 0x1CC) = *(f32 *)(local_1 + 0x34) * local_2->unk0;
    *(f32 *)(local_0 + 0x1CC) = *(f32 *)(local_0 + 0x1CC) * (local_5 * param_1);
    if (local_2->unkC) {
        *(f32 *)(local_0 + 0x1D0) = *(f32 *)(local_1 + 0x38) * ((1.0f < local_2->unk8) ? local_2->unk8 : 1.0f);
    } else {
        *(f32 *)(local_0 + 0x1D0) = *(f32 *)(local_1 + 0x3C);
    }
}

void func_8080649C_bsfirstp(param_0) PlayerState *param_0;
{
    FirstPersonMovementData *local_0;
    FirstPersonMovementStep *local_1;
    f32 local_2;
    f32 local_3;
    f32 local_4;
    f32 local_5;
    f32 local_6;
    f32 local_7[3];
    f32 local_8[3];

    local_0 = (FirstPersonMovementData *)param_0->kazfly;
    local_1 = &local_0->local_0;
    local_4 = 1.0f / 30.0f;
    local_5 = func_800D9004() - local_4;
    local_2 = func_808052C8_bsfirstp(&local_1->local_2, local_1->local_0, local_1->local_1, local_4);
    local_3 = func_808052C8_bsfirstp(&local_1->local_2, local_1->local_0, local_1->local_1, local_5);
    func_808052A4_bsfirstp(&local_3, &local_1->local_3);
    local_6 = yaw_get(param_0) - 90.0f;
    func_800EFCD8(local_7, local_6, local_2 + local_3);
    local_7[1] = 0.0f;
    func_8009BC08(param_0, local_8);
    func_800EF04C(local_8, local_7);
    func_8009B98C(param_0, local_8);
}

void func_80806588_bsfirstp(param_0) PlayerState *param_0;
{
    u8 *local_0;
    u8 *local_1;
    f32 local_2;
    f32 local_3;
    f32 local_4;
    f32 *local_5;
    f32 *local_7;
    f32 *local_6;
    f32 *pv;    /* the pointer &F(local_0, 0x1AC) as a variable: keeps the temp at 0x34 and moves local_9 to 0x3C */
    FpSpring *local_8;
    f32 local_10;
    f32 local_11;
    f32 local_9;

    local_0 = *(u8 **)((u8 *)param_0 + 0x188);
    pv = &F(local_0, 0x1AC);
    local_8 = (FpSpring *)(local_0 + 0x1DC);
    local_1 = func_80802458_bsfirstp(param_0);
    local_4 = func_800D9004();
    local_5 = (f32 *)(*(u8 **)((u8 *)param_0 + 0xC8) + 4);
    local_6 = (f32 *)(*(u8 **)((u8 *)param_0 + 0xC8) + 0x28);
    local_7 = (f32 *)(*(u8 **)((u8 *)param_0 + 0xC8) + 0x10);
    func_800EF04C(&F(local_0, 0x1A0), local_5);
    func_800EF3DC(&F(local_0, 0x1A0), pv);
    local_8->unk4 = F(local_1, 0x44) * F(local_0, 0x12C);
    local_8->unk0 += func_800FF060(local_8->unk4 - local_8->unk0, local_8->unk8, F(local_1, 0x4C), F(local_1, 0x50), F(local_1, 0x48), local_4);
    local_9 = local_8->unk0;
    local_2 = yaw_get(param_0);
    local_3 = (6.283185f * local_9);
    local_3 *= (F(local_0, 0x24C) * 0.0027777778f);
    local_10 = func_800137AC(local_2);
    /* As with func_80013788 below: the target does not reload f12 for this call, so it has no argument. */
    local_11 = func_800137C4_noarg();
    F(local_0, 0x1AC) = F(local_0, 0x1A0) - local_9 * local_10;
    F(local_0, 0x1B0) = local_5[1];
    F(local_0, 0x1B4) = F(local_0, 0x1A8) + local_9 * local_11;
    func_800EFB24(local_6, pv, local_5);
    func_800EE7F8(local_5, pv);
    func_800EFA20(local_7, local_6, 1.0f / local_4);
    if (30.0f < mlAbsF(local_8->unk8[0])) {
        local_3 = func_800EEFFC(local_7);
        local_2 = func_80013B70(local_7[0], local_7[2], local_3);
    }
    baphysics_set_target_horizontal_velocity(param_0, local_3);
    baphysics_set_target_yaw(param_0, local_2);
}

void func_80806774_bsfirstp(param_0) Actor *param_0; {
    void *temp_v0;
    void *sp1C;

    temp_v0 = *((void **)((char *)param_0 + 0x188));
    sp1C = temp_v0;
    func_8009B7C0();
    *((f32 *)((char *)temp_v0 + 0x1D8)) = 0.0f;
    *((f32 *)((char *)temp_v0 + 0x1CC)) = 0.0f;
    *((f32 *)((char *)temp_v0 + 0x1D4)) = 0.0f;
}

void func_808067B0_bsfirstp(u8 *param_0) {
    u8 *local_0 = *(u8 **)(param_0 + 0x188);
    *(f32 *)(local_0 + 0x20C) = func_80809D94_bsfirstp(param_0);
    *(f32 *)(local_0 + 0x210) = 0.0f;
    *(f32 *)(local_0 + 0x214) = 0.0f;
}

void func_808067E8_bsfirstp(u8 *param_0)
{
  s32 local_0;
  if (param_0)
  {
  }
  local_0 = *((s32 *) (((s8 *) param_0) + 0x188));
  bcopy(func_80802458_bsfirstp() + 0x54, local_0 + 0x1E8, 0x20);
  func_808067B0_bsfirstp(param_0);
}

void func_8080682C_bsfirstp(param_0) PlayerState *param_0;
{
    FirstPersonPitchBounds *local_0;
    f32 local_1;
    f32 local_2;
    f32 local_3;

    local_0 = (FirstPersonPitchBounds *)param_0->kazfly;
    switch (local_0->local_0) {
    case 0: local_1 = func_808068E8_bsfirstp(param_0); break;
    case 1: local_1 = func_80806928_bsfirstp(param_0); break;
    }
    local_0->local_3 = func_80013728(local_0->local_3 + local_1);
    local_2 = func_80809D94_bsfirstp(param_0);
    local_2 = local_0->local_2 + local_2;
    local_3 = local_0->local_1;
    if (local_0->local_3 < local_2) local_0->local_3 = local_2;
    if (local_3 < local_0->local_3) local_0->local_3 = local_3;
}

f32 func_808068E8_bsfirstp(param_0) Actor *param_0;
{
  if (func_80809D6C_bsfirstp(param_0))
  {
    return func_808069BC_bsfirstp(param_0);
  }
  else
  {
    if ((!param_0) && (!param_0))
    {
    }
    return func_808069FC_bsfirstp(param_0);
  }
}

f32 func_80806928_bsfirstp(param_0) PlayerState *param_0;
{
    FirstPersonAim1517 *local_0;
    f32 local_2;

    local_0 = (FirstPersonAim1517 *)param_0->kazfly;
    if (-local_0->local_1 < 0.0f) local_2 = local_0->local_2 * -local_0->local_1;
    else local_2 = -local_0->local_3 * -local_0->local_1;
    if (local_0->local_0) local_2 += func_80809D94_bsfirstp(param_0);
    local_0->local_4 = local_2;
    return func_80013728(local_2 - local_0->local_5) / 12.0f;
}

f32 func_808069BC_bsfirstp(param_0) u8 *param_0; {
    u8 *local_0 = *(u8 **)(param_0 + 0x188);
    f32 local_1 = func_80809D94_bsfirstp(param_0);
    *(f32 *)(local_0 + 0x208) = local_1;
    return func_80013728(local_1 - *(f32 *)(local_0 + 0x20C)) / 6.0f;
}

f32 func_808069FC_bsfirstp(param_0) u8 *param_0;
{
    u8 *p;
    f32 f0;
    f32 f2;
    f32 *q;

    p = *((u8 **) (param_0 + 0x188));
    if (*((s32 *) (p + 0xA8)) == 0) {
        q = (f32 *) (p + 0x180);
        f2 = func_800F122C(-q[0], 0.0f, *((f32 *) (p + 0x1F0)));
        if (((s32 *) q)[3] != 0) {
            f0 = *((f32 *) (p + 0x1F8)) / (1.0f + ((FS_8 *)(q))->v);
        } else {
            f0 = *((f32 *) (p + 0x200));
        }
    } else {
        f2 = func_800F122C(-*((f32 *) (p + 0xC4)), 0.0f, *((f32 *) (p + 0x1F4)));
        if (*((f32 *) (p + 0xC4)) != 0.0f) {
            f0 = *((f32 *) (p + 0x1FC));
        } else {
            f0 = *((f32 *) (p + 0x204));
        }
    }
    func_80806AD0_bsfirstp(param_0, f2, f0);
}

f32 func_80806AD0_bsfirstp(PlayerState *param_0, f32 param_1, f32 param_2)
{
    FirstPersonIntegrator1517 *local_0;
    f32 *local_5;
    f32 local_4;
    f32 local_1;
    f32 local_2;
    f32 local_3;

    local_0 = (FirstPersonIntegrator1517 *)param_0->kazfly;
    local_4 = func_800D9004();
    local_1 = local_4 - 0.03333333507f;
    local_5 = &local_0->local_1;
    local_2 = func_808057C8_bsfirstp(local_5, param_1, local_0->local_0, 0.03333333507f, param_2);
    if (local_1 != 0.0f) local_3 = func_808057C8_bsfirstp(local_5, param_1, local_0->local_0, local_1, param_2);
    else local_3 = 0.0f;
    func_808052A4_bsfirstp(&local_3, &local_0->local_2);
    return local_2 + local_3;
}

void bsfirstp_entrypoint_28(u8 *param_0, u8 *param_1)
{
  s32 *new_var2;
  u8 *v0;
  u8 *v1;
  s32 *new_var;
  s32 t6;
  s32 t7;
  new_var = (s32 *) (((u8 *) param_0) + 0x184);
  v0 = *((u8 **) (((u8 *) param_0) + 0x188));
  ;
  v1 = *((u8 **) (((u8 *) param_1) + 0x188));
  *((s32 *) (0x64 + v0)) = *((s32 *) (((u8 *) param_1) + 0x184));
  new_var2 = new_var;
  ;
  *((s32 *) (v1 + 0x68)) = *new_var2;
}

void func_80806BA0_bsfirstp(PlayerState *param_0)
{
    FirstPersonMode *local_0;
    local_0 = (FirstPersonMode *)param_0->kazfly;
    switch (func_80809540_bsfirstp(param_0, local_0->local_0)) {
    default:
    case 0:
        if (local_0->local_0) {
            func_80808D80_bsfirstp(param_0);
            local_0->local_0 = 0;
        }
        return;
    case 1:
        if (local_0->local_0 != 1) func_80809684_bsfirstp(param_0, 1);
        break;
    case 2:
        if (local_0->local_0 != 2) func_80809684_bsfirstp(param_0, 2);
        break;
    }
    func_80809740_bsfirstp(param_0);
}

s32 func_80806C58_bsfirstp(s32 param_0) {
    func_80807BB8_bsfirstp(param_0);
    func_800936E8(param_0, 0);
    func_8009337C(param_0, 1);
    func_8009B7C0(param_0);
    func_80801B64_bsfirstp(param_0, 2);
    func_808061AC_bsfirstp(param_0, 0);
    func_800A16BC(1);
}

void func_80806CC0_bsfirstp(PlayerState *param_0)
{
    FirstPersonExitState *local_0;
    local_0 = (FirstPersonExitState *)param_0->kazfly;
    if (local_0->handle >= 0) {
        func_800F7B9C(local_0->handle, 0x4F);
        local_0->handle = -1;
    }
    func_8080175C_bsfirstp(param_0);
    func_800936E8(param_0, 1);
    func_8009337C(param_0, 0);
    func_80801B64_bsfirstp(param_0, 3);
    local_0->state = -1;
    func_80808DB0_bsfirstp(param_0);
    func_80807C8C_bsfirstp(param_0);
    func_800A16BC(0);
    _bababykaz_entrypoint_9(param_0);
}

void func_80806D64_bsfirstp(s32 param_0)
{
  func_8080633C_bsfirstp(param_0, 1.0f);
  func_80801928_bsfirstp(param_0);
}

void func_80806D90_bsfirstp(PlayerState *param_0)
{
    u8 *local_0;

    local_0 = *(u8 **)((u8 *)param_0 + 0x188);
    if (func_8009E6EC(param_0) == 0x4F) {
        *(s32 *)(local_0 + 0x64) = -1;
        bs_setState(param_0, 0xCA);
        func_8009E830(param_0, 2);
    } else {
        bsfirstp_entrypoint_26(param_0);
    }
}

int bsfirstp_entrypoint_29(s32 param_0)
{
  return D_8080B560_bsfirstp[param_0];
}

void func_80806E0C_bsfirstp(u8 *param_0)
{
  u8 *local_0;
  func_80807BB8_bsfirstp();
  local_0 = *((u8 **) (((char *) param_0) + 0x188));
  func_800A34E4(param_0, 0);
  func_800A34A0(param_0, 0);
  *((s32 *) local_0) = 0;
  *((s32 *) (((char *) local_0) + 4)) = 0;
  func_800936CC(param_0, 3);
  func_808061AC_bsfirstp(param_0, 1);
  *((s8 *) (((char *) local_0) - -0x218)) = (0, 0xFF);
  func_80806BA0_bsfirstp(param_0);
  _bsbabykaz_entrypoint_4(param_0);
  func_80801A34_bsfirstp(param_0);
}

void func_80806E9C_bsfirstp(s32 arg0)
{
    _bsbabykaz_entrypoint_3();
    func_80807C8C_bsfirstp(arg0);
}
void func_80806EC4_bsfirstp(PlayerState *param_0)
{
    u8 *local_0 = *(u8 **)((u8 *)param_0 + 0x188);
    s32 local_1;

    _bsbabykaz_entrypoint_5(param_0);
    func_8080800C_bsfirstp(param_0);
    if (func_800D3948()) {
        local_1 = *(s32 *)(local_0 + 0x68);
        func_80101180(0x2C4, 0x75, (_bababykaz_entrypoint_12(param_0) << 16) | (local_1 & 0xFFFF));
    }
    if (_bababykaz_entrypoint_3(param_0)) {
        bs_setState(param_0, 0xA1);
        return;
    }
    switch (*(s32 *)(local_0 + 4)) {
        case 0:
            if (func_80801A98_bsfirstp(param_0)) {
                func_800936E8(param_0, 1);
                func_8009337C(param_0, 1);
                func_80808DB0_bsfirstp(param_0);
                (*(s32 *)(local_0 + 4))++;
            }
            break;
        case 1:
            func_80804848_bsfirstp(param_0, *(void **)(local_0 + 12));
            func_80801DC0_bsfirstp(param_0);
            func_80809D24_bsfirstp(param_0);
            func_8080682C_bsfirstp(param_0);
            func_808099B4_bsfirstp(param_0);
            func_8080633C_bsfirstp(param_0, 1.0f);
            func_80808EF0_bsfirstp(param_0);
            if (bakey_pressed(param_0, 9)) _bsbabykaz_entrypoint_13(param_0);
            break;
    }
    func_80801928_bsfirstp(param_0);
    func_80806BA0_bsfirstp(param_0);
}

void func_80807024_bsfirstp(PlayerState *param_0)
{
    s32 local_5;
    s32 local_6;
    void *local_0;
    s32 local_1;
    u8 *local_3;
    u8 *local_4;
    void *local_2;

    switch (func_8009E6EC(param_0)) {
    case 0x1F:
    case 0x21:
    case 0x24:
    case 0x47:
    case 0x4E:
        _bsbabykaz_entrypoint_13(param_0);
        func_8009E830(param_0, 2);
        break;
    case 0x4F:
        _bsbabykaz_entrypoint_13(param_0);
        func_8009E830(param_0, 2);
        _batimer_set(param_0, 0, 0.0f);
        break;
    case 0x8E:
        param_0->unk160.word = 0;
        bs_setState(param_0, 0xA1);
        func_8009E830(param_0, 2);
        _batimer_set(param_0, 0, 0);
        break;
    case 0x7D:
        if (*(s32 *)((u8 *)param_0 + 0x158)) {
            local_3 = (u8 *)param_0->kazfly;
            local_0 = func_800F53D0(*(s32 *)(local_3 + 0x68));
            local_5 = func_80099A58(param_0);
            local_1 = _badeathmatch_entrypoint_4(local_5);
            local_6 = func_80099A64(param_0);
            _badeathmatch_entrypoint_5(local_0, local_1, local_6);
        } else {
            func_80099B94(param_0);
        }
        break;
    case 0x5F:
        if (*(s32 *)((u8 *)param_0 + 0x158)) {
            local_4 = (u8 *)param_0->kazfly;
            local_2 = func_800F53D0(*(s32 *)(local_4 + 0x68));
            func_80802BE8_bsfirstp(local_2, func_80099A34(param_0));
        }
        break;
    default:
        func_80099B94(param_0);
        break;
    }
}

int bsfirstp_entrypoint_30(s32 param_0)
{
  return D_8080B570_bsfirstp[param_0];
}

void func_808071D8_bsfirstp(s32 arg0)
{
    func_80091E6C();
    _bsbabykaz_entrypoint_3(arg0);
    func_80807C8C_bsfirstp(arg0);
}

int func_80807208_bsfirstp(s32 param_0)
{
  s32 local_0;
  local_0 = param_0 | 0;
  func_80807BB8_bsfirstp(local_0);
  _bsbabykaz_entrypoint_4(local_0);
  _bsbabykaz_entrypoint_0(local_0);
  _bababykaz_entrypoint_9(local_0);
  func_80091E48(local_0, 0x20);
  _batimer_set(local_0, 0, 0.5f);
}

void func_80807264_bsfirstp(Actor *param_0)
{
  s32 local_0;
  _batimer_decrement(param_0, 0);
  local_0 = _batimer_isZero(param_0, 0);
  if (!(local_0 == 0)) {
    local_0 = _bababykaz_entrypoint_4(param_0);
    func_800F9AAC(*(s32 **)((char *)param_0 + 0x184), local_0);
  }
}

int bsfirstp_entrypoint_31(s32 param_0)
{
  return D_8080B580_bsfirstp[param_0];
}

int func_808072C8_bsfirstp(Actor *param_0)
{
  s32 local_0;
  local_0 = func_800A3404();
  if (local_0 != 0 && func_800DB9B0() != 0)
  {
    local_0 = 0;
  }
  else
  {
    local_0 = 1;
  }
  func_8009337C(param_0, 1);
  func_800936E8(param_0, local_0);
}

s32 func_80807328_bsfirstp(s32 param_0){
    func_80807D48_bsfirstp(param_0);
    func_80804848_bsfirstp(param_0, -1);
    func_80801928_bsfirstp(param_0);
    func_80801DC0_bsfirstp(param_0);
    func_80808DB0_bsfirstp(param_0);
    func_80809D24_bsfirstp(param_0);
    func_8080682C_bsfirstp(param_0);
    func_808099B4_bsfirstp(param_0);
    func_80800830_bsfirstp(param_0);
}

void func_80807394_bsfirstp(Actor *param_0) {
    s32 state;
    s32 local_0;

    local_0 = 1;
    state = func_8009E6EC(param_0);
    switch (state) {
    case 0x62:
        if (func_800A3404(param_0) == 0) {
            func_80807EEC_bsfirstp(param_0);
            local_0 = 2;
        }
        goto block_14;
    case 0x64:
        if ((func_800A3404(param_0) != 0) && (func_800D3948() == 0)) {
            func_80807F24_bsfirstp(param_0);
            baanim_playForDuration_loop(param_0, 0x30D, 0x40000000);
            func_80800488_bsfirstp(param_0, 0x311, 2.0f);
            local_0 = 2;
        }
        if (_ncpoddialog_entrypoint_10(func_80099A58(param_0)) != 0) {
            *(s32 *)((char *)param_0 + 0x15C) = 1;
            local_0 = 2;
        }
        goto block_14;
    case 0x63:
        if (func_800A3404(param_0) != 0) {
            func_80807F24_bsfirstp(param_0);
            local_0 = 2;
        }
        goto block_14;
    default:
        bsfirstp_entrypoint_26(param_0);
        return;
    }
block_14:
    func_8009E830(param_0, local_0);
    bs_setState(param_0, 0);
}

int func_808074D0_bsfirstp(Actor *param_0)
{
  func_800936E8(param_0, 1);
  _bsrest_entrypoint_14(param_0);
  func_80807C8C_bsfirstp(param_0);
}

void func_80807504_bsfirstp(u8 *param_0)
{
  s32 local_0;
  if (func_800A3404() != 0)
  {
    if (func_800DB9B0() != 0)
    {
      *((s32 *) (((s8 *) param_0) + 0x15C)) = 2;
    }
    else
    {
      *((s32 *) (((s8 *) param_0) + 0x15C)) = 0;
    }
  }
  else
    if (bs_getPreviousState(param_0) == 0xC8)
  {
    *((s32 *) (((s8 *) param_0) + 0x15C)) = 3;
  }
  else
  {
    *((s32 *) (((s8 *) param_0) + 0x15C)) = 1;
  }
  func_808061AC_bsfirstp(param_0, 0);
 if (1) { } if (1) { }
  local_0 = *((s32 *) (((s8 *) param_0) + 0x15C));
  switch (local_0)
  {
    case 2:
      _bsrest_entrypoint_16(param_0);
      func_80807BB8_bsfirstp(param_0);
      baanim_playForDuration_loop(param_0, 0x272, 0x40000000);
      func_800936E8(param_0, 0);
      func_8009337C(param_0, 1);
      return;

    case 0:
      _bsrest_entrypoint_16(param_0);
      func_80807BB8_bsfirstp(param_0);
      baanim_playForDuration_loop(param_0, 0x272, 0x40000000);
      return;

    case 1:
      _bsrest_entrypoint_16(param_0);
      func_80807BB8_bsfirstp(param_0);

    case 3:
      return;

  }

}

void func_8080762C_bsfirstp(u8 *param_0)
{
  u32 temp_t6;
  ;
  switch (*((u32 *) (((s8 *) param_0) + 0x15C)))
  {
    case 0:
      ;
      ;
      ;

    case 2:
      func_808072C8_bsfirstp(param_0);
      func_80807328_bsfirstp(param_0);
      if (_bsrest_entrypoint_20(param_0) != 0)
    {
      func_80807F5C_bsfirstp(param_0);
      return;
    }

    default:
      return;

    case 1:
      func_80807328_bsfirstp(param_0);
      if (_bsrest_entrypoint_20(param_0) != 0)
    {
      func_80807F5C_bsfirstp(param_0);
      return;
    }
      break;

    case 3:
      if (baanim_isAt(param_0, 0.1081f) != 0)
    {
      func_800936E8(param_0, 1);
    }
      if (baanim_isStopped(param_0) != 0)
    {
      baanim_playForDuration_loopStartingAt(param_0, 0x30D, 0x40000000, 0.503600001f);
      func_808002CC_bsfirstp(param_0, 0x311, 2.0f, 0.503600001f);
      func_8008B1C8(baanim_getAnimCtrlPtr(param_0), 0.75f);
      func_8008B1C8(func_8008D04C(param_0), 0.75f);
      _bsrest_entrypoint_16(param_0);
      *((u32 *) (((s8 *) param_0) + 0x15C)) = 4U;
    }
      func_80807328_bsfirstp(param_0);
      return;

    case 4:
      func_80807328_bsfirstp(param_0);
      if (_bsrest_entrypoint_20(param_0) != 0)
    {
      func_80807EEC_bsfirstp(param_0);
      func_80807F5C_bsfirstp(param_0);
    }
      break;

  }

}

int bsfirstp_entrypoint_32(s32 param_0)
{
  return D_8080B590_bsfirstp[param_0];
}

int func_808077AC_bsfirstp(Actor *param_0)
{
  func_80801B64_bsfirstp(param_0, 3);
  _bsrest_entrypoint_14(param_0);
  func_80807C8C_bsfirstp(param_0);
}

s32 func_808077E0_bsfirstp(s32 param_0)
{
  func_80801B64_bsfirstp(param_0, 2);
  func_80807BB8_bsfirstp(param_0);
  _bsrest_entrypoint_16(param_0);
  if (func_800A3404(param_0) != 0)
  {
    baanim_playForDuration_loopSmooth(param_0, 0x272, 0x40000000);
  }
  else
  {
    baanim_playForDuration_loop(param_0, 0x30D, 0x40000000);
    func_80800488_bsfirstp(param_0, 0x311, 2.0f);
  }
  *(s32 *)(param_0 + 0x15c) = 0;
}

void func_80807864_bsfirstp(Actor *param_0)
{
    s32 local_0;

    if (func_8009CC68() == 0) {
        *(s32 *)((char *)param_0 + 0x15C) = 1;
    }
    local_0 = *(s32 *)((char *)param_0 + 0x15C);
    switch (local_0) {
    case 0:
        _bsrest_entrypoint_20(param_0);
        yaw_update(param_0);
        func_80807328_bsfirstp(param_0);
        return;
    case 1:
        func_80807F5C_bsfirstp(param_0);
        return;
    }
}

int bsfirstp_entrypoint_33(s32 param_0)
{
  return D_8080B5A0_bsfirstp[param_0];
}

void func_808078F4_bsfirstp(PlayerState *param_0)
{
    u8 *local_1;
    u8 *local_0;
    s16 local_2[2];
    s16 local_3[2];
    s16 local_5;
    f32 local_4;
    local_0 = (u8 *)func_80802484_bsfirstp(param_0);
    local_1 = (u8 *)func_80802458_bsfirstp(param_0);
    if (!func_800D3948()) {
        if (func_8009EA2C()) {
            local_2[0] = 0x726;
            local_2[1] = 0x725;
            local_3[0] = 0;
            local_3[1] = 0;
        } else {
            func_80802AA8_bsfirstp(param_0, 0, local_2, local_3);
        }
    } else {
        local_5 = func_800A940C(*(s32 *)((u8 *)param_0 + 0x184));
        func_80802AA8_bsfirstp(param_0, local_5, local_2, local_3);
    }
    if (func_800D3948()) {
        local_4 = *(f32 *)(local_0 + 0x44);
    } else {
        local_4 = 1.0f;
    }
    func_80092EC8(param_0, local_2[0]);
    if (local_3[0]) func_8009312C(param_0, local_3[0]);
    func_80093230(param_0, local_4);
    func_8008CF7C(param_0);
    func_800936CC(param_0, 2);
    func_8009359C(param_0, local_2[1]);
    if (local_3[1]) func_8009316C(param_0, local_3[1]);
    func_800936D8(param_0, *(s32 *)(local_0 + 0xC));
    func_8009E55C(param_0, 0, *(f32 *)local_1);
    func_8009E55C(param_0, 1, *(f32 *)(local_1 + 4));
}

void func_80807A70_bsfirstp(PlayerState *param_0)
{
    s32 *local_0 = (s32 *)param_0->kazfly;
    if (local_0[0] != -1) {
        func_800936CC(param_0, 0);
        func_8009359C(param_0, 0);
        func_80093230(param_0, 1.0f);
        func_8008CFF0(param_0);
        func_80093370(param_0, 1);
        func_8009337C(param_0, 1);
        local_0[0] = -1;
    }
}

void func_80807AF8_bsfirstp(PlayerState *param_0)
{
    FirstPersonInit1493 *local_1;
    s32 local_0;

    local_1 = (FirstPersonInit1493 *)param_0->kazfly;
    local_0 = 1;
    if (func_800D3948()) {
        if (func_800EA068(0x4000)) local_0 = _gcstatusDll_entrypoint_13(param_0->unk184);
        else _gcstatusDll_entrypoint_3(param_0->unk184, 1);
    }
    func_800A34A0(param_0, local_0);
    local_1->local_0 = local_0;
    local_1->local_2 = -1;
    local_1->local_3 = -1;
    local_1->local_1 = -1;
    func_8009B7C0(param_0);
    func_8009FFD8(param_0, 1, 0, 0, 0x10);
    bainput_enable(param_0, 3, 0);
}

void func_80807BB8_bsfirstp(param_0) PlayerState *param_0;
{
    s32 *local_0;

    if (!func_8009E77C(param_0, 5)) {
        local_0 = (s32 *)func_80800000_bsfirstp((u8 *)param_0);
        func_80807AF8_bsfirstp(param_0);
        func_800947EC(param_0, 8, 1);
        local_0[3] = 0;
        local_0[4] = 1;
        func_80801AC4_bsfirstp(param_0);
        func_80805F48_bsfirstp(param_0);
        func_80809CD8_bsfirstp(param_0);
        func_808067E8_bsfirstp(param_0);
        func_8080995C_bsfirstp(param_0);
        func_80803A84_bsfirstp(param_0);
        func_808047EC_bsfirstp(param_0);
        func_80802BD8_bsfirstp(param_0);
        func_80802F00_bsfirstp(param_0);
        func_80809C90_bsfirstp(param_0);
        _bafpctrl_entrypoint_14(param_0, 1);
        func_80800190_bsfirstp(param_0);
        func_80807F9C_bsfirstp(param_0);
    }
}

void func_80807C8C_bsfirstp(param_0) void *param_0; {
    void *local_0;
    s32 local_1;

    local_0 = *(void **)((char *)param_0 + 0x188);
    if (func_8009E74C(param_0, 5) == 0) {
        local_1 = *(s32 *)((char *)local_0 + 0x68);
        if (local_1 >= 0) {
            func_800F7B9C(local_1, 0x4F);
            *(s32 *)((char *)local_0 + 0x68) = -1;
        }
        func_80807A70_bsfirstp(param_0);
        func_80801AEC_bsfirstp(param_0);
        func_80805F68_bsfirstp(param_0);
        bainput_enable(param_0, 3, 1);
        func_800947EC(param_0, 8, 0);
        func_80809CB4_bsfirstp(param_0);
        func_80803B04_bsfirstp(param_0);
        func_808018E0_bsfirstp(param_0);
        func_80808084_bsfirstp(param_0);
        func_80800040_bsfirstp(param_0);
    }
}

void func_80807D48_bsfirstp(s32 arg0)
{
    func_80802BE0_bsfirstp(arg0);
    func_8080800C_bsfirstp(arg0);
}
int func_80807D70_bsfirstp(param_0) s32 param_0;
{
  s32 local_0;
  local_0 = param_0 | 0;
  func_808001D0_bsfirstp(local_0);
  func_80809DA0_bsfirstp(local_0, 1);
  func_808067B0_bsfirstp(local_0);
  func_80801B64_bsfirstp(local_0, 1);
  func_80802ED4_bsfirstp(local_0);
  func_800A34E4(local_0, 0);
  func_8009BD50(local_0);
}

void func_80807DD4_bsfirstp(param_0) s32 param_0; {
    s16 local_0;
    s16 local_1;
    s16 local_2;
    s16 local_3;

    if (func_800A3404() != 0) {
        func_808078F4_bsfirstp(param_0);
        func_80807D70_bsfirstp(param_0);
        func_8080053C_bsfirstp(param_0);
        func_8009B4FC(param_0);
        func_800936E8(param_0, 1);
        func_8009337C(param_0, 0);
        func_80093370(param_0, 1);
        return;
    }
    _bapreload_entrypoint_0(param_0, 0xA, &local_0, &local_1);
    _bapreload_entrypoint_0(param_0, 0xB, &local_2, &local_3);
    func_800936CC(param_0, 1);
    func_80092EC8(param_0, local_0);
    func_80093230(param_0, 1.0f);
    func_8009337C(param_0, 1);
    func_8009359C(param_0, local_2);
    func_800936D8(param_0, 0x3F800000);
    func_800936E8(param_0, 1);
    func_800A34E4(param_0, 1);
    func_8008CF7C(param_0);
    func_808003B4_bsfirstp(param_0, 0x310, 2.0f);
}

int func_80807EEC_bsfirstp(param_0) Actor *param_0;
{
  if (!func_800A3404())
  {
    func_800A3544(param_0, 1);
    func_80807DD4_bsfirstp(param_0);
  }
}

int func_80807F24_bsfirstp(param_0) Actor *param_0;
{
  if (func_800A3404(param_0))
  {
    func_800A3544(param_0, 0);
    func_80807DD4_bsfirstp(param_0);
  }
}

s32 func_80807F5C_bsfirstp(param_0) s32 param_0;{
    func_800A3544(param_0, 1);
    func_80807DD4_bsfirstp(param_0);
    func_80801A5C_bsfirstp(param_0);
    bs_setState(param_0, 0xCA);
}

void func_80807F9C_bsfirstp()
{
    func_80807FBC_bsfirstp();
}

void func_80807FBC_bsfirstp(param_0) u8 *param_0; {
    u8 *local_0 = *(u8 **)(param_0 + 0x188);
    func_80808100_bsfirstp(param_0, local_0 + 0x6C);
    func_808080A4_bsfirstp(param_0, 0xFF);
    func_808080B4_bsfirstp(param_0, local_0 + 0x6C, local_0[0x72]);
}

void func_8080800C_bsfirstp(param_0) s32 param_0;
{
    s16 local_1[3];
    s32 local_2;
    FirstPersonCamera1527 *local_0;

    local_0 = (FirstPersonCamera1527 *)((PlayerState *)param_0)->kazfly;
    func_80808100_bsfirstp((s32)param_0, (s32)local_1);
    for (local_2 = 0; local_2 != 3; local_2++) {
        local_0->local_0[local_2] = (local_0->local_0[local_2] * 3 + local_1[local_2]) >> 2;
    }
    func_808080B4_bsfirstp((s32)param_0, local_0->local_0, local_0->local_1);
}

void func_80808084_bsfirstp(s32 arg0)
{
    func_80092744(arg0,0);
}

unsigned int func_808080A4_bsfirstp(param_0, param_1) u8 *param_0; u8 param_1;
{
  u8 *new_var;
  new_var = *((u8 **) (((s8 *) param_0) + 0x188));
  *((s8 *) (((s8 *) new_var) + 0x72)) = param_1;
}

int func_808080B4_bsfirstp(param_0, param_1, param_2) s32 param_0; s16 *param_1; u8 param_2;
{
  func_80092744(param_0, 1);
  func_80092750(param_0, param_1[0], param_1[1], param_1[2], param_2);
}

void func_80808100_bsfirstp(param_0, param_1) s32 param_0; s32 param_1; {
    f32 local_0[3];
    func_80808148_bsfirstp(param_0, local_0);
    func_8080853C_bsfirstp(local_0, 20.0f);
    func_808084AC_bsfirstp(local_0, 0.5f);
    func_808085A8_bsfirstp(local_0, param_1);
}

void func_80808148_bsfirstp(param_0, param_1) s32 param_0; f32 *param_1;
{
    f32 spFC[3];
    f32 spF0[3];
    f32 spE4[3];
    f32 d;
    f32 tmp;
    f32 u;
    s32 i;
    s32 j;
    f32 spC4[3];
    f32 spB8[3];
    f32 spAC[3];
    u8 spA0[12];
    s32 sp7C[9];
    f32 sp50[11];
    f32 t;

    param_1[2] = 255.0f;
    param_1[1] = 255.0f;
    param_1[0] = 255.0f;
    func_8009C128(param_0, spFC);
    if (!(func_80096628(param_0) & 0x200000)) {
        func_80096604(param_0, sp50);
        func_800965E0(param_0, spA0);
        for (i = 0; i < 3; i++) {
            sp50[i * 3 + 1] = 0.0f;
            for (j = 0; j < 3; j++) {
                sp7C[i * 3 + j] = spA0[i * 4 + j];
            }
            param_1 = (f32 *)((s32)param_1 * 1); /* PROBE: the reassignment inside the loop (frequency 10) raises the register priority of param_1 above
     * that of &sp50, which gives s3/s4 as in the target */
        }
        if (func_800F36D4(sp7C, sp7C + 3) != 0 && func_800F36D4(sp7C, sp7C + 6) != 0) {
            func_800EE84C(param_1, sp7C);
            return;
        }
        spFC[1] = 0.0f;
        func_800EFB24(spF0, spFC, sp50);
        spF0[1] = 0.0f;
        func_800EFB24(spB8, sp50, sp50 + 3);
        spB8[1] = 0.0f;
        func_800EFB24(spC4, sp50 + 6, sp50 + 3);
        tmp = spC4[0];
        spC4[1] = 0.0f;
        spC4[0] = -spC4[2];
        spC4[2] = tmp;
        d = func_800EEAA4(spF0, spC4);
        if (d == 0.0f) {
            d = 0.1f;
        }
        func_800EFA4C(spAC, sp50[0] + (((-((spC4[2] * spB8[2]) + ((spB8[0] * spC4[0]) + (spB8[1] * spC4[1])))) / d) * spF0[0]), 0, sp50[2] + (((-((spB8[2] * spC4[2]) + ((spB8[0] * spC4[0]) + (spB8[1] * spC4[1])))) / d) * spF0[2]));
        func_800EFB24(spE4, spAC, sp50 + 3);
        t = func_800EEF94(spE4);
        u = t / (func_800EEF94(spC4) + 0.01f);
        for (i = 0; i < 3; i++) {
            param_1[i] = (f32)sp7C[3 + i] + (f32)(sp7C[6 + i] - sp7C[3 + i]) * u;
        }
        func_800EFB24(spE4, spAC, sp50);
        t = func_800EEF94(spF0);
        u = 1.0f - t / (func_800EEF94(spE4) + 0.01f);
        for (i = 0; i < 3; i++) {
            param_1[i] = param_1[i] + ((f32)sp7C[i] - param_1[i]) * u;
        }
    }
}

void func_808084AC_bsfirstp(f32 *param_0, f32 param_1)
{
    f32 local_0;
    s32 local_1;

    local_0 = ((param_0[0] + param_0[1]) + param_0[2]) * 0.3333333433f;
    for (local_1 = 0; local_1 != 3; local_1++) {
        param_0[local_1] = func_800F1214(param_1, local_0, param_0[local_1]);
    }
}

void func_8080853C_bsfirstp(f32 *param_0, f32 param_1)
{
    s32 local_0;
    f32 local_1;

    local_1 = 1.0f - param_1 * 0.00390625f;
    for (local_0 = 0; local_0 < 3; local_0++) {
        param_0[local_0] = param_0[local_0] * local_1 + param_1;
    }
}

int func_808085A8_bsfirstp(param_0, param_1) f32 param_0[3]; s16 *param_1;
{
  s32 local_0;
  f32 new_var3;
  float new_var;
  f32 local_1;
  f32 new_var2;
  for (local_0 = 0; local_0 < 3; local_0++)
  {
    new_var2 = param_0[local_0];
    if (new_var2 < 0.0f)
    {
      param_1[local_0] = 0;
    }
    else
    {
      new_var = 255.0;
      new_var3 = (local_1 = 0.5f);
      if (new_var2 > new_var)
      {
        param_1[local_0] = 0xFF;
      }
      else
      {
        param_1[local_0] = (local_1 = new_var2 + new_var3);
      }
    }
  }

}

int func_80808630_bsfirstp(s32 param_0)
{
  if (func_800C6E38(0x1A) && bakey_pressed(param_0, 9))
  {
    return 1;
  }
  return 0;
}

int func_80808678_bsfirstp(s32 param_0, s32 param_1)
{
  func_808086B0_bsfirstp(param_0, 3);
  func_8080633C_bsfirstp(param_0, 0.150000006f);
}

void func_808086B0_bsfirstp(param_0, param_1) Actor *param_0; s32 param_1;
{
  u8 *temp_v1;
  u8 *sp30;
  u8 *sp2C;
  u8 *sp34;
  temp_v1 = func_80802458_bsfirstp(param_0);
  switch (param_1)
  {
    case 1:
      baphysics_set_target_horizontal_velocity(param_0, baphysics_get_target_horizontal_velocity(param_0) * 0.3f);
      func_80802A40_bsfirstp(param_0, 8);
      func_808025C8_bsfirstp(param_0, &sp30, &sp2C);
      func_80800424_bsfirstp(param_0, *((s16 *) (((s8 *) sp30) + 0)), *((f32 *) (((s8 *) sp30) + 4)));
      baanim_playForDuration_onceSmooth(param_0, *((s16 *) (((s8 *) sp2C) + 0)), *((f32 *) (((s8 *) sp2C) + 4)));
      break;

    case 2:
      sp34 = temp_v1;
      baphysics_set_target_horizontal_velocity(param_0, 1000.f);
      func_8009E55C(param_0, 2, *((f32 *) (((s8 *) temp_v1) + 8)));
      func_8009E5A4(param_0, 2, 3);
      func_8009E4E0(param_0, 2, (void *) (&_bsfirstp_entrypoint_13));
      baflag_set(param_0, 0x3B);
      func_80802A40_bsfirstp(param_0, 9);
      break;

    case 3:
      func_8080633C_bsfirstp(param_0, 0.3f);
      if (baphysics_get_target_horizontal_velocity(param_0) < 0.0f)
    {
      baphysics_set_target_horizontal_velocity(param_0, 0);
    }
      func_8009E5A4(param_0, 2, 2);
      func_8009E55C(param_0, 2, 0.0f);
      baflag_clear(param_0, 0x3B);
      break;

  }

  *((s32 *) (((s8 *) param_0) + 0x15C)) = param_1;
}

void func_80808848_bsfirstp(s32 param_0) {
    func_80807BB8_bsfirstp(param_0);
    func_80808DB0_bsfirstp(param_0);
    _bainvisible_entrypoint_7(param_0, 3, 1.0f, 1.0f, 0.4f);
    func_808086B0_bsfirstp(param_0, 1);
}

void func_808088A4_bsfirstp(s32 arg0)
{
    func_808086B0_bsfirstp(arg0,0x3);
    func_80807C8C_bsfirstp(arg0);
}

void func_808088D0_bsfirstp(PlayerState *param_0)
{
    s32 local_0 = 0;
    AnimCtrl *local_1;

    local_1 = func_8008D04C(param_0);
    func_80808E78_bsfirstp(param_0);
    switch (param_0->unk15C.word) {
        case 1:
            if (anctrl_isAt(local_1, 0.285f)) func_808086B0_bsfirstp(param_0, 2);
            break;
        case 2:
            baphysics_set_target_yaw(param_0, yaw_get(param_0));
            if (anctrl_isAt(local_1, 0.8f)) func_808086B0_bsfirstp(param_0, 3);
            break;
        case 3:
            if (anctrl_isStopped(local_1)) local_0 = 0xCA;
            break;
    }
    func_80803B58_bsfirstp(param_0, func_80013970((func_800F0D50(anctrl_getAnimTimer(local_1), 0.285f, 0.8f) - 0.285f) * 1.9417477f * 180.0f));
    bs_setState(param_0, local_0);
}

int bsfirstp_entrypoint_34(s32 param_0)
{
  return D_8080B5B0_bsfirstp[param_0];
}

void func_80808A24_bsfirstp(u8 *param_0) {
    u8 *local_0;

    local_0 = (*(u8 **)((s8 *)(param_0) + (0x188)));
    func_80807BB8_bsfirstp(param_0);
    (*(s32 *)((s8 *)(local_0) + (8))) = -1;
    func_80808DB0_bsfirstp(param_0);
    (*(s32 *)((s8 *)(param_0) + (0x160))) = 0;
    func_80808CAC_bsfirstp(param_0, 1);
    func_80800858_bsfirstp(param_0, 1);
    func_80808D80_bsfirstp(param_0);
}

void func_80808A8C_bsfirstp(s32 param_0)
{
    func_80807C8C_bsfirstp(param_0);
}
void func_80808AAC_bsfirstp(s32 param_0) {
    s32 temp_v0;

    func_80807D48_bsfirstp(param_0);
    func_80808E78_bsfirstp(param_0);
    func_8080633C_bsfirstp(param_0, 1.0f);
    temp_v0 = func_80808B24_bsfirstp(param_0);
    if (temp_v0 != 0) {
        bs_setState(param_0, temp_v0);
        return;
    }
    func_80808B8C_bsfirstp(param_0, temp_v0);
}

int bsfirstp_entrypoint_35(s32 param_0)
{
  return D_8080B5C0_bsfirstp[param_0];
}

int func_80808B24_bsfirstp(param_0) Actor *param_0;
{
  s32 local_0;
  if (func_80802D50_bsfirstp(param_0, &local_0))
  {
    return local_0;
  }
  if (func_80808630_bsfirstp(param_0))
  {
    return 0xD2;
  }
  if (func_80809540_bsfirstp(param_0, 0) != 0)
  {
    return 0xD1;
  }
  return 0;
}

void func_80808B8C_bsfirstp(param_0) PlayerState *param_0;
{
    if (func_80802444_bsfirstp(param_0) == 1) {
        if (param_0->unk15C.word >= 2) {
            param_0->unk160.word = 0;
            func_80808CAC_bsfirstp(param_0, 1);
        }
    } else {
        switch (param_0->unk15C.word) {
        case 0:
            break;
        case 1:
            param_0->unk16C -= func_800D9004();
            if (param_0->unk16C < 0.0f) func_80808CAC_bsfirstp(param_0, 1);
            break;
        default:
            if (func_80800228_bsfirstp(param_0)) func_80808CAC_bsfirstp(param_0, 1);
            break;
        }
    }
}

void func_80808C48_bsfirstp(param_0) s32 param_0;
{
    param_0 = param_0 | 0;
    *((s32 *) (param_0 + 0x160)) = 0;
    *((f32 *) (param_0 + 0x16C)) = 5.0f;
    func_80808CAC_bsfirstp(param_0, 0);
    func_80808D80_bsfirstp(param_0);
    func_8008B304(baanim_getAnimCtrlPtr(param_0));
    func_8008B304(func_8008D04C(param_0));
}

void func_80808CAC_bsfirstp(param_0, param_1) PlayerState *param_0; s32 param_1;
{
    FirstPersonScriptStep1612 *local_0;
    int local_2;

    local_2 = func_808024DC_bsfirstp();
    local_0 = (FirstPersonScriptStep1612 *)((param_0->unk160.word++ * 8) + local_2);
    if (param_1) {
        func_80800424_bsfirstp((Actor *)param_0, local_0->local_0, local_0->local_2);
    } else {
        func_808003B4_bsfirstp((Actor *)param_0, local_0->local_0, local_0->local_2);
    }
    param_0->unk15C.word = 2;
    local_2 = local_0->local_1;
    if (local_2 & 1) {
        func_808001FC_bsfirstp(param_0);
        param_0->unk15C.word = 0;
        local_2 = local_0->local_1;
    }
    if (local_2 & 2) {
        param_0->unk16C = local_0->local_2;
        param_0->unk15C.word = 1;
    }
    local_0++;
    if (local_0->local_0 == 0) {
        param_0->unk160.word = local_0->local_1;
    }
}

int func_80808D80_bsfirstp(param_0) s32 param_0;
{
  s16 *local_0 = func_80802508_bsfirstp();
  baanim_playForDuration_loopSmooth(param_0, local_0[0], *(s32 *)((char *)local_0 + 0x4));
}

void func_80808DB0_bsfirstp(param_0) Actor *param_0;
{
    u8 *local_1 = *(u8 **)((char *)param_0 + 0x188);
    s32 local_0 = func_80802444_bsfirstp(param_0);
    if (local_0 != *(s32 *)((char *)local_1 + 8))
    {
        *(s32 *)((char *)local_1 + 8) = local_0;
        local_0 = func_80802444_bsfirstp(param_0);
        switch (local_0)
        {
        case 0:
            func_808061AC_bsfirstp(param_0, 2);
            func_80809DA0_bsfirstp(param_0, 0);
            func_8080483C_bsfirstp(param_0, 0);
            func_808099A8_bsfirstp(param_0, 1);
            return;
        case 1:
            func_808061AC_bsfirstp(param_0, 3);
            func_80809DA0_bsfirstp(param_0, -1);
            func_8080483C_bsfirstp(param_0, 1);
            func_808099A8_bsfirstp(param_0, 2);
            break;
        }
    }
}

void func_80808E78_bsfirstp(param_0) PlayerState *param_0;
{
    s32 *local_0 = *(s32 **)((u8 *)param_0 + 0x188);

    func_80804848_bsfirstp(param_0, local_0[3]);
    func_80801928_bsfirstp(param_0);
    func_80801DC0_bsfirstp(param_0);
    func_80808DB0_bsfirstp(param_0);
    func_80809D24_bsfirstp(param_0);
    func_8080682C_bsfirstp(param_0);
    func_808099B4_bsfirstp(param_0);
    func_80800830_bsfirstp(param_0);
    func_80808EF0_bsfirstp(param_0);
    func_80802F20_bsfirstp(param_0);
}

int func_80808EF0_bsfirstp(param_0) Actor *param_0;
{
  f32 local_0[4];
  if (bakey_pressed(param_0, 8))
    {
        func_8009C128(param_0, local_0);
        func_801013A8(local_0, 0x6F, *(u8 **)((char *)param_0 + 0x184));
    }
}

void func_80808F38_bsfirstp(param_0) PlayerState *param_0;
{
    u8 *local_0;
    s32 local_1;
    s32 *local_9 = &local_1;
    f32 local_2;
    f32 local_3[3];
    s32 padw;
    f32 *local_4;

    local_0 = (u8 *)param_0->kazfly;
    local_1 = 0;
    if (func_800D3948() && _gcstatusDll_entrypoint_14() == 5 && _gcstatusDll_entrypoint_15() != param_0->unk184) {
        local_1 = 1;
    }
    func_8008E944(param_0);
    func_800F7F98(param_0->unk184, 1);
    _bababykaz_entrypoint_14(param_0);
    if (local_1 == 0) {
        if (*(s32 *)(local_0 + 0xEC) == 0x45) {
            local_1 = 2;
        } else {
            switch (*(s32 *)(local_0 + 0xF4)) {
            default:
            case 1:
                local_1 = 3;
                break;
            case 2:
                local_1 = 4;
                break;
            case 4:
                local_1 = 5;
                break;
            }
        }
    }
    func_8009C128(param_0, local_3);
    func_800F1E6C((f32 *)(local_0 + 0xF8), local_3, &local_2);
    local_4 = D_8080A650_bsfirstp[local_1];
    if (1) {}
    baphysics_set_target_horizontal_velocity(param_0, local_4[0]);
    baphysics_set_target_yaw(param_0, local_2);
    baphysics_set_horizontal_velocity(param_0, local_2, local_4[0]);
    baphysics_set_vertical_velocity(param_0, local_4[1]);
    baphysics_set_gravity(param_0, local_4[2]);
    *(f32 *)(local_0 + 0x10C) = local_4[3];
    func_8080911C_bsfirstp(param_0, 0);
    yaw_applyIdeal(param_0);
}

void func_808090D8_bsfirstp(param_0) Actor *param_0;
{
    s32 *local_0 = *(s32 **)((u8 *)param_0 + 0x188);
    local_0[2] = -1;
    func_80808DB0_bsfirstp(param_0);
    func_8008E95C(param_0);
    func_800F7F98(*(s32 **)((u8 *)param_0 + 0x184), 0);
}

void func_8080911C_bsfirstp(param_0, param_1) u8 *param_0; s32 param_1;
{
    u8 *local_0;
    local_0 = *(u8 **)(param_0 + 0x188);
    switch (param_1) {
    case 0:
        func_8009FFD8(param_0, 1, 1, 2, 3);
        break;
    case 1:
        func_8009FFD8(param_0, 1, 0, 0, 0x10);
        break;
    }
    *(s32 *)(local_0 + 0x108) = param_1;
}

void func_80809198_bsfirstp(param_0) PlayerState *param_0;
{
    FirstPersonTimer *local_0;
    f32 local_1;
    local_0 = (FirstPersonTimer *)param_0->kazfly;
    switch (local_0->local_1) {
    case 0:
        if (func_800F1574(&local_0->local_2, func_800D9004())) func_8080911C_bsfirstp(param_0, 1);
        break;
    case 1:
        if (func_8009E674(param_0, 4)) local_1 = 0.0f;
        else local_1 = D_8080A660_bsfirstp[local_0->local_0].local_0[0];
        func_8080633C_bsfirstp(param_0, local_1);
        break;
    }
}

void func_80809250_bsfirstp(param_0) PlayerState *param_0;
{
    f32 local_0[9];
    void *local_1;
    f32 local_2;
    u8 *local_3;
    s32 local_4;
    f32 local_5[3];
    f32 local_6[3];
    FirstPersonCameraOffset *local_7;

    local_1 = baanim_getAnimCtrlPtr(param_0);
    local_2 = anctrl_getAnimTimer(local_1);
    local_4 = anctrl_getIndex(local_1);
    local_3 = func_800D674C(local_4);
    func_800E0050(local_3, local_2, 3, local_0);
    local_7 = (FirstPersonCameraOffset *)func_80802484_bsfirstp(param_0);
    func_8009C128(param_0, local_6);
    local_6[1] += local_7->local_1;
    local_5[0] = -local_0[0];
    local_5[1] = local_0[1] + yaw_get(param_0) + 180.0f;
    local_5[2] = local_0[2];
    _ncba1p_entrypoint_6(func_800A4CA8(param_0), local_6);
    _ncba1p_entrypoint_7(func_800A4CA8(param_0), local_5);
}

s32 func_80809334_bsfirstp(void *param_0) {
    s32 s0;

    s0 = (s32) param_0;
    func_80807BB8_bsfirstp(s0);
    func_80808DB0_bsfirstp(s0);
    func_80809900_bsfirstp(s0);
    func_80800858_bsfirstp(s0, 1);
    func_80809684_bsfirstp(s0, 0);
}

void func_80809384_bsfirstp(s32 param_0)
{
    func_80807C8C_bsfirstp(param_0);
}
void func_808093A4_bsfirstp(u8 *param_0) {
    u8 *sp24;
    s32 sp20;
    s32 temp_v0;
    s32 temp_v0_2;

    sp24 = (*(u8 **)((s8 *)(param_0) + (0x188)));
    func_80807D48_bsfirstp(param_0);
    func_80808E78_bsfirstp(param_0);
    func_8080633C_bsfirstp(param_0, 1.0f);
    temp_v0 = func_808094A4_bsfirstp(param_0);
    sp20 = temp_v0;
    if (temp_v0 == 0) {
        temp_v0_2 = func_80809540_bsfirstp(param_0, (*(u8 *)((s8 *)(sp24) + (0x218))));
        switch (temp_v0_2) {                        
        case 0:
            sp20 = 0xCA;
            break;
        case 1:
            if ((*(u8 *)((s8 *)(sp24) + (0x218))) != 1) {
                func_80809684_bsfirstp(param_0, 1);
            }
            break;
        case 2:
            if ((*(u8 *)((s8 *)(sp24) + (0x218))) != 2) {
                func_80809684_bsfirstp(param_0, 2);
            }
            break;
        }
        func_80809740_bsfirstp(param_0);
    }
    if (sp20 != 0) {
        bs_setState(param_0, sp20);
    }
}

int bsfirstp_entrypoint_36(s32 param_0)
{
  return D_8080B5D0_bsfirstp[param_0];
}

int func_808094A4_bsfirstp(param_0) Actor *param_0;
{
  s32 local_0;
  if (func_80802D50_bsfirstp(param_0, &local_0))
  {
    return local_0;
  }
  else
  {
    if (func_80808630_bsfirstp(param_0) != 0)
    {
      return 0xD2;
    }
    return 0;
  }
}

int func_808094F4_bsfirstp(param_0) s32 param_0;
{
  s32 local_0;
  local_0 = func_80809540_bsfirstp(param_0, 1);
  switch (local_0)
  {
    case 0 :
      return 0xCA;

    case 1 :
    case 2 :
      return 0xD1;

    default :
      return 0;

  }

}

int func_80809540_bsfirstp(param_0, param_1) PlayerState *param_0; s32 param_1;
{
    u8 *local_0;
    f32 *local_1;
    f32 local_2;
    f32 local_3;
    f32 local_4;
    f32 local_6;
    f32 local_5;

    local_0 = (u8 *)param_0->kazfly;
    local_1 = (f32 *)func_808024B0_bsfirstp(param_0);
    local_2 = func_8080613C_bsfirstp(param_0);
    local_3 = baphysics_get_target_horizontal_velocity(param_0);
    local_4 = *(f32 *)(local_0 + 0x1CC);
    local_5 = mlAbsF(local_3);
    local_6 = mlAbsF(local_4);
    switch (param_1) {
        case 0:
            if (local_6 + local_5 > 0.0f) return 1;
            break;
        case 1:
            if (0.0f - (local_6 + local_5) == 0.0f && local_2 < local_1[0]) return 0;
            if (local_1[1] * 1.05f < local_2) return 2;
            break;
        case 2:
            if (local_2 < local_1[1] * 0.95f) return 1;
            break;
    }
    return param_1;
}

void func_80809684_bsfirstp(param_0, param_1) u8 *param_0; s32 param_1;
{
    u8 *local_2;
    f32 *local_0;
    f32 *local_3;

    local_2 = *(u8 **)(param_0 + 0x188);
    local_0 = func_808024B0_bsfirstp();
    if (param_0) {}
    local_2[0x218] = param_1;
    switch (param_1) {
    case 0:
        return;
    case 1:
        local_3 = func_80802560_bsfirstp(param_0, param_1);
        break;
    case 2:
        local_3 = func_80802594_bsfirstp(param_0, param_1);
        break;
    }
    func_80800290_bsfirstp(param_0, *(s16 *)local_3, *(s32 *)(local_3 + 1));
    *(f32 *)(local_2 + 0x21C) = local_3[1];
    *(f32 *)(local_2 + 0x220) = local_3[2];
    *(f32 *)(local_2 + 0x224) = local_0[0];
    *(f32 *)(local_2 + 0x228) = local_0[1];
}

int func_80809740_bsfirstp(param_0) PlayerState *param_0;
{
    f32 local_6;
    AnimCtrl *local_0;
    f32 local_1[3];
    f32 local_7;
    f32 local_2;
    f32 local_3;
    f32 local_4;
    u8 *local_5;
    local_5 = (u8 *)param_0->kazfly;
    local_0 = baanim_getAnimCtrlPtr(param_0);
    func_80806148_bsfirstp(param_0, local_1);
    if (local_1[2] >= 0.0f) local_5[0x219] = 1;
    else local_5[0x219] = 0;
    func_8008B188(local_0, local_5[0x219]);
    local_2 = func_8080613C_bsfirstp(param_0);
    switch (local_5[0x218]) {
    case 0: local_3 = 0.0f; local_4 = *(f32 *)(local_5 + 0x224); break;
    case 1: local_3 = *(f32 *)(local_5 + 0x224); local_4 = *(f32 *)(local_5 + 0x228); break;
    case 2: local_3 = *(f32 *)(local_5 + 0x228); local_4 = 1.0f; break;
    }
    if (local_3 != local_4) {
        local_7 = local_2 - local_3;
        local_2 = func_800F0D50(local_7 / (local_4 - local_3), 0.0f, 1.0f);
    }
    else local_2 = 1.0f;
    local_3 = *(f32 *)(local_5 + 0x21C);
    local_4 = *(f32 *)(local_5 + 0x220);
    local_6 = (local_4 - local_3) * local_2 + local_3;
    anctrl_setDuration(local_0, local_6);
    if (!func_800EA068(0x20)) {
        switch (local_5[0x218]) {
        case 1: func_800A2CE8(param_0, 0.45f, 4); func_800A2CE8(param_0, 0.9f, 3); break;
        case 2: func_800A2CE8(param_0, 0.45f, 4); func_800A2CE8(param_0, 0.95f, 3); break;
        }
    }
}

s32 func_80809900_bsfirstp(this) Actor *this;{
    func_80800424_bsfirstp(this, func_80802534_bsfirstp(), 1.0f);
    func_808001FC_bsfirstp(this);
}

f32 func_80809938_bsfirstp(param_0) u8 *param_0; {
    u8 *local_0 = *(u8 **)(param_0 + 0x188);
    f32 local_1 = *(f32 *)(local_0 + 0x24C) * (1.0f / *(f32 *)(local_0 + 0x230));
    return local_1;
}

void func_8080995C_bsfirstp(param_0) Actor *param_0; {
    u8 *local_0;

    local_0 = *(u8 **)((char *)param_0 + 0x188);
    bcopy(func_80802458_bsfirstp() + 0x74, local_0 + 0x230, 0x18);
    *(s16 *)((char *)local_0 + 0x248) = 0;
    *(f32 *)((char *)local_0 + 0x24C) = 0.0f;
    *(f32 *)((char *)local_0 + 0x250) = 0.0f;
}

void func_808099A8_bsfirstp(param_0, param_1) Actor *param_0; s32 param_1;
{
  s32 *p = *(s32 **)((char *)param_0 + 0x188);
  *(s16 *)((char *)p + 0x248) = param_1;
}

void func_808099B4_bsfirstp(param_0) u8 *param_0;
{
  s16 *new_var;
  s16 temp_v1;
  temp_v1 = *((s16 *) (((s8 *) (*((u8 **) (((s8 *) param_0) + 0x188)))) + 0x248));
  new_var = (s16 *) (((s8 *) (*((u8 **) (((s8 *) param_0) + 0x188)))) + 0x248);
  switch (temp_v1)
  {
    case 1:
      func_80809A10_bsfirstp();
      return;

    case 2:
      func_80809A7C_bsfirstp();
      temp_v1 = *new_var;

    case 0:
      return;

  }

}

void func_80809A10_bsfirstp(param_0) PlayerState *param_0;
{
    f32 local_0;
    f32 local_1;
    f32 local_2;
    FirstPersonAimLimits *local_3;

    local_3 = (FirstPersonAimLimits *)param_0->kazfly;
    local_2 = local_3->local_3;
    local_0 = -local_2 * local_3->local_0;
    if (local_3->local_2) {
        local_1 = local_3->local_4 / (1.0f + local_3->local_1);
    } else {
        local_1 = local_3->local_5;
    }
    func_80809AF8_bsfirstp(param_0, local_0, local_1, local_2);
}

void func_80809A7C_bsfirstp(param_0) void *param_0; {
    void *temp_v0;
    float temp_a1;
    float var_f0;

    temp_v0 = *(void **)((char *)param_0 + 0x188);
    temp_a1 = func_800F122C(-(*(float *)((char *)temp_v0 + 0xC0)), 5.0f, *(f32 *)((char *)temp_v0 + 0x234));
    if (*(float *)((char *)temp_v0 + 0xC0) != 0.0f) {
        var_f0 = *(float *)((char *)temp_v0 + 0x23C);
    } else {
        var_f0 = *(float *)((char *)temp_v0 + 0x244);
    }
    func_80809AF8_bsfirstp(param_0, temp_a1, var_f0, *(f32 *)((char *)temp_v0 + 0x234));
}

void func_80809AF8_bsfirstp(PlayerState *param_0, f32 param_1, f32 param_2, f32 param_3)
{
    FirstPersonYawStep *local_0;
    f32 local_1;
    f32 local_2;
    f32 local_3;
    f32 local_4;
    f32 local_5;
    f32 local_6;

    local_0 = (FirstPersonYawStep *)param_0->kazfly;
    local_2 = func_800D9004() - (1.0f / 30.0f);
    local_3 = func_808057C8_bsfirstp(&local_0->local_0, param_1, param_3, 1.0f / 30.0f, param_2);
    if (local_2 != 0.0f) {
        local_4 = func_808057C8_bsfirstp(&local_0->local_0, param_1, param_3, local_2, param_2);
    } else {
        local_4 = 0.0f;
    }
    func_808052A4_bsfirstp(&local_4, &local_0->local_1);
    local_5 = local_3 + local_4;
    local_1 = yaw_get(param_0);
    local_6 = func_800136E4(local_1 + local_5);
    yaw_setIdeal(param_0, local_6);
    yaw_set(param_0, local_6);
}

int bsfirstp_entrypoint_37(Actor *param_0)
{
  s32 local_0;
  local_0 = func_800A89F8();
  if (local_0 == func_800A4C68(param_0))
  {
    func_80809C30_bsfirstp(param_0);
  }
}

s32 func_80809C30_bsfirstp(param_0) s32 param_0;
{
  if (func_80093DF4(param_0, 2) != 0 && func_800936F4(param_0) != 0 && func_8009239C(param_0) != 0)
  {
    func_80093E18(param_0, func_800A7180());
  }
}

int func_80809C90_bsfirstp(param_0) int param_0;
{
  int new_var;
  new_var--;
 ;
  new_var = 0;
  new_var++;
  func_8009ADF0(param_0, 0xb, 1);
}

void func_80809CB4_bsfirstp(param_0) s32 param_0; {
    func_8009ADF0(param_0, 0xB, 0);
}

void func_80809CD8_bsfirstp()
{
    func_80809CF8_bsfirstp();
}

void func_80809CF8_bsfirstp(param_0) void *param_0;
{
    void *local_0 = *(void **)((char *)param_0 + 0x188);
    *(float *)((char *)local_0 + 0x29C) = 162.5f;
    *(float *)((char *)local_0 + 0x2A0) = 8.0f;
    *(float *)((char *)local_0 + 0x25C) = 0.0f;
    *(int *)((char *)local_0 + 0x264) = 0;
}

s32 func_80809D24_bsfirstp(param_0) s32 param_0;{
    func_80809DD0_bsfirstp(param_0);
    func_80809F74_bsfirstp(param_0);
    func_8080A03C_bsfirstp(param_0);
    func_8080A194_bsfirstp(param_0);
    func_8080A250_bsfirstp(param_0);
}

s32 func_80809D6C_bsfirstp(param_0) u8 *param_0; {
    u8 *local_0 = *(u8 **)(param_0 + 0x188);
    return *(s32 *)(local_0 + 0x254) == 1 ? 1 : 0;
}

f32 func_80809D94_bsfirstp(param_0) void *param_0;
{
  f32 *new_var2;
  f32 *local_0;
  f32 *new_var;
  new_var2 = *((f32 **) (((u8 *) param_0) + 0x188));
  local_0 = new_var2;
  new_var = (0, new_var2);
  new_var2 = &local_0[0x72];
  return (*(f32 *)((char *)(new_var) + 604));
}

void func_80809DA0_bsfirstp(param_0, param_1) void *param_0; s32 param_1; {
    void *temp_v0;

    temp_v0 = *(void **)((char *)param_0 + 0x188);
    if (param_1 == 0) {
        if (*(s32 *)((char *)temp_v0 + 0x254) < 0) {
            *(s32 *)((char *)temp_v0 + 0x254) = param_1;
            *(s32 *)((char *)temp_v0 + 0x258) = 0;
        }
    } else {
        *(s32 *)((char *)temp_v0 + 0x254) = param_1;
        *(s32 *)((char *)temp_v0 + 0x258) = 0;
    }
}

void func_80809DD0_bsfirstp(param_0) u8 *param_0;
{
    u8 *local_3;
    s32 local_2;
    f32 local_0;
    f32 local_1;

    local_3 = *(u8 **)(param_0 + 0x188);
    local_2 = 0;
    if (*(s32 *)(local_3 + 0xA0) == 1) {
        local_0 = *(f32 *)(local_3 + 0xC4);
    } else {
        local_2 = *(s32 *)(local_3 + 0x10);
        local_0 = *(f32 *)(local_3 + 0x180);
    }
    switch (local_2) {
        case 0:
            *(s32 *)(local_3 + 0x254) = 0;
            break;
        case 1:
            local_1 = mlAbsF(*(f32 *)(local_3 + 0x148));
            if (mlAbsF(local_0) > 0.01f) {
                if (local_1 > 0.5f) {
                    *(s32 *)(local_3 + 0x258) = 1;
                } else {
                    *(s32 *)(local_3 + 0x258) = 0;
                }
                *(s32 *)(local_3 + 0x254) = 0;
            } else if (!*(s32 *)(local_3 + 0x254)) {
                if (*(s32 *)(local_3 + 0x258)) {
                    if (local_1 < 0.25f) {
                        *(s32 *)(local_3 + 0x254) = 1;
                    }
                } else if (local_1 > 0.75f) {
                    *(s32 *)(local_3 + 0x254) = 1;
                }
            }
            break;
    }
}

s32 func_80809EF8_bsfirstp(f32 *param_0, f32 *param_1, s32 param_2)
{
  f32 local_0[3];
  func_800EE7F8(local_0, param_0);
  local_0[1] += 300.0f;
  func_800EE7F8(param_1, param_0);
  param_1[1] += -300.0f;
  func_800BEF00(local_0, param_1, param_2, 0x8020020);
}

void func_80809F74_bsfirstp(param_0) PlayerState *param_0;
{
    u8 *local_0[1];
    u8 *local_5;
    f32 local_3[3];
    f32 local_2[3];
    f32 local_4;
    u32 local_1;
    s32 pad_x[2];

    local_0[0] = *(u8 **)((u8 *)param_0 + 0x188);
    local_1 = func_80096628(param_0);
    local_4 = yaw_get(param_0);
    func_800963C0(param_0, local_3);
    if (func_800F1B78(local_2, local_3, local_4, 1.0f) && (s32)(local_1 << 4) >= 0) {
        local_5 = local_0[0] + 0x254;
        *(f32 *)(local_5 + 0x1C) = -local_2[0];
        if ((s32)(local_1 << 3) < 0) {
            *(s32 *)(local_5 + 0x18) = 3;
        } else {
            *(s32 *)(local_5 + 0x18) = 1;
        }
    } else {
        local_5 = local_0[0] + 0x254;
        *(f32 *)(local_5 + 0x1C) = 0.0f;
        if ((s32)(local_1 << 3) < 0) {
            *(s32 *)(local_5 + 0x18) = 2;
        } else {
            *(s32 *)(local_5 + 0x18) = 0;
        }
    }
}

void func_8080A03C_bsfirstp(param_0) PlayerState *param_0;
{
    u8 *d[1];
    u8 *hit;
    f32 pos[3];
    f32 rot[3];
    f32 dist;
    FirstpAim1828 *aim;
    s32 flag;
    f32 diff[3];
    FirstpAim1828 *aim2;

    d[0] = *(u8 **)((u8 *)param_0 + 0x188);
    func_800F3BB0(param_0, pos);
    aim = (FirstpAim1828 *)(d[0] + 0x254);
    dist = aim->unk48;
    rot[0] = func_800137F4(yaw_get(param_0));
    aim2 = aim; /* a second pointer variable from here on */
    rot[1] = 0.0f;
    /* The target calls func_80013788 without setting f12: no argument here, so this call goes through an
     * unprototyped alias (undefined_syms.us.txt); func_80805644_bsfirstp needs the f32 prototype. */
    rot[2] = func_80013788_noarg();
    func_800EE7B4(aim2->unk20, pos, rot, dist);
    hit = (u8 *)func_80809EF8_bsfirstp(aim2->unk20, aim2->unk2C, aim2->unk38);
    if (hit != NULL) {
        flag = *(s32 *)(hit + 8) & 0x10000000;
        aim2->unk14 = 1;
        if (func_800EF030(aim2->unk38) > 0.01f) {
            if (flag) aim2->unk50 = 3;
            else aim2->unk50 = 1;
        } else {
            if (flag) aim2->unk50 = 2;
            else aim2->unk50 = 0;
        }
    } else {
        aim2->unk14 = 0;
        aim2->unk50 = 0;
    }
    func_800EFB24(diff, aim2->unk2C, pos);
    dist = func_80013728(func_80013B7C(diff[1], func_800EEFFC(diff)));
    aim2->unk44 = func_800F0DC0(dist, 30.0f);
}

void func_8080A194_bsfirstp(param_0) u8 *param_0;
{
    u8 *d;
    s32 m;
    s32 n;
    s32 a;
    s32 b;
    s32 c;
    s32 e;
    FpSub *sub;
    d = *(u8 **)(param_0 + 0x188);
    m = *(s32 *)(d + 0x26C);
    n = *(s32 *)(d + 0x2A4);
    b = m == 3;
    a = b;
    if (!b) b = m == 2;
    sub = (FpSub *)(d + 0x254);
    c = n == 3;
    if (c && !b) sub->unk14 = 0;
    e = c;
    if (!e) e = n == 2;
    if (!e & a) sub->unk14 = 0;
    if (sub->unk14) {
        sub->unk8 = sub->unk44;
        return;
    }
    if (sub->unk48 == 25.0f && sub->unkC >= 5) sub->unk8 = sub->unk1C;
}

void func_8080A250_bsfirstp(param_0) PlayerState *param_0;
{
    u8 *local_0;
    FirstPersonAcceleration *local_1;

    local_0 = *(u8 **)((u8 *)param_0 + 0x188);
    local_1 = (FirstPersonAcceleration *)(local_0 + 0x254);
    switch (*(s32 *)(local_0 + 0x260)) {
    case 0:
        local_1->local_4 *= 0.5f;
        if (local_1->local_4 < 1.0f) local_1->local_4 = 1.0f;
        break;
    case 1:
        break;
    default:
        local_1->local_4 *= 2.0f;
        if (local_1->local_4 > 32.0f) local_1->local_4 = 32.0f;
        break;
    }
    if (local_1->local_2) {
        local_1->local_3 += local_1->local_4;
        if (local_1->local_3 > 300.0f) local_1->local_3 = 300.0f;
    } else {
        local_1->local_3 -= 8.0f;
        if (local_1->local_3 < 25.0f) local_1->local_3 = 25.0f;
    }
    if (local_1->local_1 == local_1->local_2) local_1->local_0++;
    else {
        local_1->local_0 = 0;
        local_1->local_1 = local_1->local_2;
    }
    if (local_1->local_0 >= 5 && local_1->local_2 == 0) local_1->local_3 = 25.0f;
}
