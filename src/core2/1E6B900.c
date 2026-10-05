#include "core2/1E6B900.h"

#define MODEL(p) (*(LocalModel **)((u8 *)(p) + 0x50))
#define QQ (*(S_931AC **)((u8 *)param_0 + 0x50))
#define PP ((S93230 *)*(u32 *)((u8 *)param_0 + 0x50))
#define LOCAL_INDEX (*(u8 **)((u8 *)param_0 + 0x64))[1]
typedef struct ActorLocal_CC_0 ActorLocal_CC_0;
typedef struct Actor_80092018 Actor_80092018;
extern void func_80019750();
extern void func_80019CD4();
extern void func_800EE780();
extern void mlMtxGet();
extern void mlMtxRotPitch(f32);
extern f32 func_800136E4(f32);
extern f32 baroll_get();
extern f32 func_8009BFCC();
extern void func_8009C128();
typedef struct Actor_80092258 Actor_80092258;
extern s32 func_8009AD78(Actor_80092258 *param_0, int arg1);
extern s32 func_800A89F8(void);
extern f32 _bainvisible_entrypoint_2(Actor_80092258 *param_0, int arg1);
extern void func_800DF464(f32 param);
extern void func_800DF830(s32 param);
typedef struct { s16 field_0; u8 pad_2[2]; void *field_4; f32 field_8; s16 field_C, field_E; u8 field_10, field_11, field_12, field_13, field_14, field_15; s16 field_16[3]; } LocalSub;
typedef struct { s32 field_0; u8 field_4; u8 pad_5[3]; u8 field_8, field_9; u8 pad_A[2]; void *field_C; } LocalAction;
typedef struct { s16 field_0; u8 pad_2[6]; void *field_8; s16 field_C; u8 pad_E[2]; u8 field_10, field_11, field_12, field_13; u8 pad_14[3]; u8 field_17, field_18, field_19; u8 pad_1A[2]; f32 field_1C; u8 pad_20[12]; f32 field_2C[3]; u8 pad_38[12]; f32 field_44[3]; u8 pad_50[20]; f32 field_64[3]; u8 pad_70[4]; f32 field_74; LocalAction field_78; u8 pad_88[8]; LocalSub field_90; f32 field_AC[3], field_B8[3]; u8 field_C4; u8 pad_C5[3]; f32 field_C8; } LocalModel;
extern int func_80100E18(s16);
extern void func_800ADFE0();
extern void func_800D70F8();
extern void func_800D6CEC();
extern void *func_800AE080(s16);
extern s32 func_800B26F0(void *);
extern s32 func_800A25D0(PlayerState *);
extern s32 func_80100D24();
extern s32 func_800AE020(void);
extern s32 func_800E09B8(s32);
extern void func_800AE6FC(void *, s16);
extern void func_800EE7F8();
extern void func_800EF04C(f32 *, f32 *);
extern void *func_80100AC4(s16);
extern void *func_80100A74(s16, s32);
extern void func_800DF720(void *);
extern void func_800DF818(void *);
extern void func_800DF714(void *);
extern void func_800DF72C(void *);
extern void func_800A06E8(PlayerState *);
extern void func_800DF47C(void (*)(void), PlayerState *);
extern void func_800DF440(s32);
extern void func_800DF574(s32);
extern void func_800DF3E0(void);
extern s32 func_800A946C(void);
extern void func_800A0714(PlayerState *, s32);
extern void func_800DE448(f32 *, f32 *, f32, f32 *, void *);
extern s32 func_800A4C68(PlayerState *);
extern s32 func_800E3E8C(f32 *, f32);
extern void func_800A7108(s32, s32);
extern void func_800A7130(void *, s32);
extern void func_8008CA98(PlayerState *);
extern void func_8008D058(PlayerState *);
extern void *func_8008AEDC(void *);
extern void *baanim_getAnimCtrlPtr(PlayerState *);
extern void func_8008C200();
extern void func_800EFA4C(f32 *, f32, f32, f32);
extern void func_800DF4CC(f32 *);
extern void _babackpack_entrypoint_3(PlayerState *, f32 *, f32 *, f32, f32 *);
extern s32 func_800A3274(void);
extern void _bapreload_entrypoint_0();
typedef struct Actor_800927C4 Actor_800927C4;
extern s32 func_800F6BE4(Actor_800927C4 *);
extern Actor_800927C4 *func_800F53D0(Actor_800927C4 *);
extern void *func_80108474(s32, f32 *, s32);
extern void func_800A70D0(s32, s32);
typedef struct { char pad[0x78]; s32 unk78; char pad2[0x8]; s32 unk84; } Actor_unk50;
extern void func_800EFD24(void *);
typedef struct { u8 pad_0[0x20]; f32 local_0; f32 local_1; f32 local_2; } local_0;
typedef struct { u8 pad_0[0x50]; local_0 *local_0; } local_1;
extern Unkfunc_800E0960_1 *func_800AE6BC(s32);
extern f32 func_800B2354(s32);
typedef struct ActorLocal_CC_50 { u8 pad[12]; s16 unkC; s16 unkE; u8 unk12[2]; } ActorLocal_CC_50;
typedef struct Actor_8009312C { ActorLocal_CC_50 local; } Actor_8009312C;
typedef struct { u8 pad0[0x15]; u8 unk15; } S_931AC;
extern f32 yaw_get(PlayerState *);
extern void yaw_setIdeal(PlayerState *, f32);
extern void yaw_applyIdeal(PlayerState *);
typedef struct { u8 pad0[0x1C]; f32 unk1C; u8 pad20[0x3C]; f32 unk5C; f32 unk60; f32 unk64; u8 pad68[8]; f32 unk70; f32 unk74; } S93230;
extern void func_800EF334(f32 *, f32);
extern f32 mlAbsF(f32);
extern void _chbaddiesetup_entrypoint_5();
extern s32 func_800BEC1C(void);
extern void *func_800BEC28(s32);
extern s32 _dbzone_entrypoint_4();
extern s32 _glzone_entrypoint_6();
extern void _bsfirstp_entrypoint_1(PlayerState *, s32);
extern int D_80117DDC[];
extern int D_80117DD8[];
extern u8 D_80117E00[];
extern u8 D_80117DF0[];
typedef struct { u8 pad[0x10C]; s32 local_0; s32 local_1; s32 local_2; } State94070;
typedef struct { u8 pad[0x50]; State94070 *local_0; } Actor94070;
typedef struct { f32 local_0; u8 pad[12]; } Entry94070;
extern Entry94070 D_80117DD0[];
extern s32 func_800D90A4(void *);
extern void func_800E3980(f32 *);
extern f32 func_800EEAD4(f32 *, f32 *);
extern void func_800E4BB8(s32);
extern s32 func_800E488C(s32);
extern s32 D_80117DD4;
extern s32 func_800C954C(void);
extern int func_800F6774(s32 param_0);
extern float func_8009E9F0(float param_0);
extern void func_80101180(int param_0, int param_1, int param_2);
extern float _batimer_get();
extern void func_800D2498(int param_0, s32 param_1, int param_2);
extern int func_800C0638(void);
extern int _batimer_decrement();
extern void _batimer_set(s32, s32, f32);
extern char D_80117E3C[];
extern char D_80117E3D[];
extern u8 D_80117E30[];
extern s32 _gcegg_entrypoint_6(s32);
typedef struct { u8 pad0[2]; u8 unk2; u8 unk3; } S_94644;
extern s32 func_8009E964(void);
extern f32 func_8009E970(void);
typedef struct { u8 pad0; u8 unk1; } S0_94AB4;
typedef struct { u8 pad0[0x64]; S0_94AB4 *unk64; } S_94AB4;
s32 _gcegg_entrypoint_5(s32 param_0);
s32 func_800D1A04(s32 param_0);
PlayerState *func_80092B04();
void func_80092EC8();
void func_8009312C();
void func_800931AC();
void func_80093230(PlayerState *param_0, f32 param_1);
int func_8009332C(s32 param_0, f32 param_1);
void func_80093370();
void func_8009337C();
void func_80093504();
void func_8009359C();
void func_800936E8();
void func_80093700();
int func_80093738();
void func_80093AB8();
s32 func_80093DF4();
s32 func_80093F7C();
int func_80093FD4();
void func_80094070();
void func_800941C8(u8 *param_0, s32 param_1);
s32 func_800942D0();
void func_80094430(s32 param_0, f32 param_1);
void func_800946C4();
void func_800947EC();
s32 func_80094A10();
u8 func_80094C64();
int func_80094C88();
void func_80094D04();
int func_80094DA8();
int func_80094E40();

s32 func_80092010(void)
{
	return 0x118;
}

struct ActorLocal_CC_0 {
    s32 pad[7];      /* 0x00 - 0x1B */
    s32 unk1C;       /* 0x1C */
    f32 unk20;       /* 0x20 */
    f32 unk24;       /* 0x24 */
    f32 unk28;       /* 0x28 */
    f32 unk2C;       /* 0x2C */
    s32 pad2[5];    /* 0x30 - 0x43 */
    f32 unk44;       /* 0x44 */
    s32 pad3[55];    /* 0x48 - 0xC3 */
    u8 unkC4;        /* 0xC4 */
    f32 unkC8;       /* 0xC8 */
    u8 pad4[156];   /* 0xD0 - 0x14F */
    f32 unkCC;       /* 0xCC */
};

struct Actor_80092018 {
    u8 pad[0x50];
    ActorLocal_CC_0 *local;
};

void func_80092018(Actor_80092018 *param_0) {
    f32 sp34[3];
    f32 sp28[3];
    ActorLocal_CC_0 *local_1;
    f32 var_f0;
    local_1 = param_0->local;
    if ((*(u8 *)((char *)(local_1) + 196)) != 0) {
        var_f0 = (*(f32 *)((char *)(local_1) + 200));
    } else {
        var_f0 = (*(f32 *)((char *)(local_1) + 40));
    }
    func_800EFA4C(sp34, local_1->unk20, var_f0, local_1->unk24);
    local_1 = param_0->local;
    func_800EE780(sp28, &local_1->unk2C, &local_1->unk44);
    func_80019CD4();
    local_1 = param_0->local;
    func_80019750(&local_1->unk44, sp34, local_1->unk1C, sp28);
    local_1 = param_0->local;
    if ((*(u8 *)((char *)(local_1) + 196)) != 0) {
        mlMtxRotPitch(local_1->unk28);
    }
    local_1 = param_0->local;
    mlMtxGet((f32 *)((char *)(local_1) + 0xCC));
}

int func_800920C8(long param_0)
{
  s32 local_0;
  local_0 = *(s32 *)(param_0 + 0x50);
  func_80093504(param_0, local_0 + 0x64, local_0 + 0x50);
}

void func_800920F0(param_0) u8 * param_0; {
    u8 temp_v0;

    temp_v0 = (*(u8 *)((s8 *)((*(u8 **)((s8 *)(param_0) + (0x50)))) + (0x15)));
    switch (temp_v0) {                              
    case 2:
        (*(f32 *)((s8 *)((*(u8 **)((s8 *)(param_0) + (0x50)))) + (0x28))) = func_800136E4(yaw_get(param_0) + 180.0f);
        return;
    default:
        (*(f32 *)((s8 *)((*(u8 **)((s8 *)(param_0) + (0x50)))) + (0x28))) = yaw_get(param_0);
        
    case 3:
        return;
    }
}

void func_8009216C(u8 *param_0, s32 param_1, s32 param_2) {
    u8 *temp_v0;

    func_800920F0();
    (*(f32 *)((s8 *)((*(u8 **)((s8 *)(param_0) + (0x50)))) + (0x24))) = baroll_get(param_0);
    (*(f32 *)((s8 *)((*(u8 **)((s8 *)(param_0) + (0x50)))) + (0x20))) = func_8009BFCC(param_0);
    temp_v0 = (*(u8 **)((s8 *)(param_0) + (0x50)));
    func_800EFA4C(param_2, (*(f32 *)((s8 *)(temp_v0) + (0x20))), (*(f32 *)((s8 *)(temp_v0) + (0x28))), (*(f32 *)((s8 *)(temp_v0) + (0x24))));
    func_8009C128(param_0, param_1);
}

void func_800921E0(u8 *param_0, s32 param_1, s32 param_2)
{
  func_8009C2A0(*((s32 *) (*((u8 **) (param_0 + 0x50)) + 4)), param_1);
  if (func_800EEEA8(param_2) != 0)
  {
    func_8009C128(param_0, param_2);
  }
}

void func_80092224(void *param_0)
{
  s32 val;
  ((u8 *) ((s32 *) param_0)[0x14])[0x1A] = (val = 1);
}

void func_80092234(u8 *param_0) {
    (*(s8 *)((s8 *)((*(u8 **)((s8 *)(param_0) + (0x50)))) + (0x1A))) = 1;
    (*(s8 *)((s8 *)((*(u8 **)((s8 *)(param_0) + (0x50)))) + (0x16))) = 1;
}

s32 func_8009224C(s32 param_0)
{
  int new_var;
  new_var = param_0;
  return ((u8 **) new_var)[20][0x1A];
  new_var = new_var + 0x54;
}

s32 func_80092258(param_0) u8 * param_0; {
    u8 *temp_v0;
    u8 sp33;
    s32 sp2C;
    f32 var_f20;

    temp_v0 = (*(u8 **)((s8 *)param_0 + 0x50));
    if ((*(u8 *)((s8 *)temp_v0 + 0x88)) != 0) {
        var_f20 = (f32)(s32)(*(u8 *)((s8 *)temp_v0 + 0x8C));
    } else {
        var_f20 = (f32)(s32)(*(u8 *)((s8 *)temp_v0 + 0x14));
    }
    if (func_8009AD78(param_0, 0xC) != 0) {
        sp33 = 0;
        if (func_80093DF4(param_0, 2) != 0) {
            sp2C = func_800A89F8();
            if (func_800A4C68(param_0) == sp2C) {
                sp33 = 1;
            }
        }
        var_f20 *= _bainvisible_entrypoint_2(param_0, sp33);
    }
    return (u32)var_f20 & 0xFF;
}

s32 func_8009239C(int param_0)
{
  unsigned int new_var;
  new_var = 0;
  return ((u8 **) (param_0 + 0x50))[new_var][0x19];
}

void func_800923A8(u8 *param_0, s32 param_1)
{
    u8 sp1F;
    int temp_v0;
    u8 *temp_v0_2;
    u8 *temp_v0_3;

    temp_v0 = func_80092258();
    sp1F = temp_v0;
    func_800A2540(param_0, temp_v0);
    func_800DF464(2.0);
    if (param_1 != 0)
    {
        temp_v0_2 = *(u8 **)(param_0 + 0x50);
        if (*(u8 *)(temp_v0_2 + 0x16) == 0)
        {
            func_800DF738(*(s32 *)(temp_v0_2 + 4));
        }
    }
    func_800DF830(1);
    temp_v0_3 = *(u8 **)(param_0 + 0x50);
    if (*(u8 *)(temp_v0_3 + 0x88) != 0)
    {
        func_800DF5D8(*(u8 *)(temp_v0_3 + 0x89), *(u8 *)(temp_v0_3 + 0x8A), *(u8 *)(temp_v0_3 + 0x8B), sp1F);
    }
}

void func_80092444(PlayerState *param_0, s32 param_1)
{
    f32 local_0[3];
    f32 local_1[3];
    f32 local_2[3];
    f32 local_3;
    f32 local_4[3];
    s32 local_6;
    union { void *model; LocalAction *action; } local_5;
    if (MODEL(param_0)->field_90.field_12) {
        func_80093AB8(param_0, param_1);
        return;
    }
    if (func_800A89F8() != func_800A4C68(param_0) || MODEL(param_0)->field_18) {
        if (MODEL(param_0)->field_17) {
            local_5.action = &MODEL(param_0)->field_78;
            if (MODEL(param_0)->field_78.field_C) {
                if (local_5.action->field_4) {
                    local_5.action->field_4 = 0;
                    func_800A7108(local_5.action->field_C, local_5.action->field_0);
                } else if (local_5.action->field_9) {
                    local_5.action->field_9 = 0;
                    func_800A7130(local_5.action->field_C, local_5.action->field_8);
                }
            }
            local_3 = MODEL(param_0)->field_1C;
            func_8009216C(param_0, local_1, local_0);
            func_80094070(param_0, local_1);
            func_800EE7F8(local_2, MODEL(param_0)->field_2C);
            func_800EF04C(local_1, MODEL(param_0)->field_44);
            func_800EF04C(local_2, MODEL(param_0)->field_44);
            if (func_800E3E8C(local_1, MODEL(param_0)->field_1C * MODEL(param_0)->field_74) && MODEL(param_0)->field_C) {
                local_5.model = func_80092B04(param_0, 1);
                if (!MODEL(param_0)->field_10) {
                    func_8008CA98(param_0);
                    func_8008C200(MODEL(param_0)->field_0, func_800B27E0(local_5.model), func_8008AEDC(baanim_getAnimCtrlPtr(param_0)));
                    MODEL(param_0)->field_13 ^= 1;
                }
                MODEL(param_0)->field_10 = 1;
                func_800A06E8(param_0);
                if (MODEL(param_0)->field_C4) {
                    func_800EFA4C(local_4, 0, local_0[1], 0);
                    local_0[1] = MODEL(param_0)->field_C8;
                    func_800DF4CC(local_4);
                }
                if (MODEL(param_0)->field_12) func_800DF818(func_80100A74(MODEL(param_0)->field_12, 0));
                func_800DF72C(func_800AE080(MODEL(param_0)->field_0));
                func_800DF47C(func_80092234, param_0);
                func_800923A8(param_0, 1);
                func_800DF720(func_80100AC4(MODEL(param_0)->field_12));
                func_800DF440(0);
                func_800DE448(local_1, local_0, local_3, local_2, local_5.model);
                if (MODEL(param_0)->field_11) {
                    func_800923A8(param_0, 0);
                    _babackpack_entrypoint_3(param_0, local_1, local_0, local_3, local_2);
                }
            }
        }
    }
}

int func_8009272C(s32 param_0, long param_1)
{
  s32 local_0;
  long new_var2;
  unsigned long long new_var;
  new_var2 = param_1;
  local_0 = new_var;
  local_0 = param_0;
  *((*((u8 **) (local_0 + 0x50))) + 0x11) = new_var2;
}

s32 func_80092738(s32 param_0)
{
    return ((u8 *)(*(u8 **)(param_0 + 0x50)))[0x11];
}

void func_80092744(void *arg, s32 v)
{
    ((s8 *)(*(void **)((char *)arg + 0x50)))[136] = v;
}

void func_80092750(u8 *param_0, s32 param_1, s32 param_2, s32 param_3, s32 param_4) {
    *(s8 *)(*(u8 **)(param_0 + 0x50) + 0x89) = param_1;
    *(s8 *)(*(u8 **)(param_0 + 0x50) + 0x8A) = param_2;
    *(s8 *)(*(u8 **)(param_0 + 0x50) + 0x8B) = param_3;
    *(s8 *)(*(u8 **)(param_0 + 0x50) + 0x8C) = param_4;
}

void func_80092778(PlayerState *param_0)
{
  s16 local_0;
  s16 local_1;
  _bapreload_entrypoint_0(param_0, func_800A3274(), &local_0, &local_1);
  func_80092EC8(param_0, local_0);
  func_8009312C(param_0, local_1);
}

struct Actor_800927C4 {
    char pad[0x50];
    Actor_unk50 *unk50;
    char pad2[0x130];
    s32 unk184;
};

void func_800927C4(s32 param_0, f32 param_1, f32 param_2, f32 param_3, Actor_800927C4 *param_4)
{
  f32 local_0[4];
  void *new_var;
  if (func_800F6BE4(param_4) != 0)
  {
    param_4 = func_800F53D0(param_4);
    func_800EFA4C(local_0, param_1, param_2, param_3);
    new_var = func_80108474(param_0, local_0, 0);
    param_4->unk50->unk84 = *((s32 *) new_var);
    func_800A70D0(param_4->unk50->unk84, param_4->unk184);
    if (param_4)
    {
    }
    func_800A7108(((0, param_4->unk50))->unk84, param_4->unk50->unk78);
  }
}

void func_80092864(PlayerState *param_0, f32 param_1)
{
  char *new_var;
  PlayerState *local_0;
  PlayerState *local_8;
  new_var = (char *) param_0;
  ;
  *((f32 *) (((char *) (*((PlayerState **) (new_var + 0x50)))) + 0x78)) = param_1;
  if (1)
  {
    new_var = ((char *) param_0) + 0x50;
    ;
    *((s8 *) (((char *) (*((PlayerState **) new_var))) + 0x7C)) = 1;
  }
}

void func_80092880(PlayerState *player, s32 param_1) {

    *(u8 *)((char *)(*(struct ba_flag_s **)((char *)player + 80)) + 0x80) = param_1;
    *(u8 *)((char *)(*(struct ba_flag_s **)((char *)player + 80)) + 0x81) = 1;
}

void func_80092898(u8 *param_0)
{
  s32 sp20[2];
  f32 local_2;
  _babackpack_entrypoint_9();
  *((s8 *) (((s8 *) (*((u8 **) (((s8 *) param_0) + 0x50)))) + 0x11)) = 0;
  *((u8 *) (((s8 *) (*((u8 **) (((s8 *) param_0) + 0x50)))) + 0x14)) = 0xFF;
  *((s8 *) (((s8 *) (*((u8 **) (((s8 *) param_0) + 0x50)))) + 0x10)) = 0;
  *((s8 *) (((s8 *) (*((u8 **) (((s8 *) param_0) + 0x50)))) + 0x16)) = 0;
  *((s8 *) (((s8 *) (*((u8 **) (((s8 *) param_0) + 0x50)))) + 0x12)) = 0;
  *((s8 *) (((s8 *) (*((u8 **) (((s8 *) param_0) + 0x50)))) + 0x13)) = 0;
  *((s16 *) (((s8 *) (*((u8 **) (((s8 *) param_0) + 0x50)))) + 0xC)) = 0;
  *((s8 *) (((s8 *) (*((u8 **) (((s8 *) param_0) + 0x50)))) + 0xA2)) = 0;
  *((s16 *) (((s8 *) (*((u8 **) (((s8 *) param_0) + 0x50)))) + 0x9C)) = 0;
  func_800936E8(param_0, 0);
  func_80093700(param_0, 1);
  *((s16 *) (((s8 *) (*((u8 **) (((s8 *) param_0) + 0x50)))) + 0)) = func_800AE020();
  sp20[0] = func_800AE080(*((s16 *) (((s8 *) (*((u8 **) (((s8 *) param_0) + 0x50)))) + 0)));
  func_800AE6FC(sp20[0], (s16) func_800E09B8(0xA));
  *((s8 *) (((s8 *) (*((u8 **) (((s8 *) param_0) + 0x50)))) + 0x88)) = 0;
  *((s32 *) (((s8 *) (*((u8 **) (((s8 *) param_0) + 0x50)))) + 4)) = func_800DBFF8();
  *((s32 *) (((s8 *) (*((u8 **) (((s8 *) param_0) + 0x50)))) + 0x84)) = 0;
  *((s8 *) (((s8 *) (*((u8 **) (((s8 *) param_0) + 0x50)))) + 0x7C)) = 0;
  *((s8 *) (((s8 *) (*((u8 **) (((s8 *) param_0) + 0x50)))) + 0x81)) = 0;
  func_800EFD24((*((u8 **) (((s8 *) param_0) + 0x50))) + 0x2C);
  func_800EFD24((*((u8 **) (((s8 *) param_0) + 0x50))) + 0x38);
  func_800EFD24((*((u8 **) (((s8 *) param_0) + 0x50))) + 0x44);
  *((f32 *) (((s8 *) (*((u8 **) (((s8 *) param_0) + 0x50)))) + 0x20)) = 0.0f;
  local_2 = ((local_1 *) param_0)->local_0->local_0;
  ((local_1 *) param_0)->local_0->local_1 = local_2;
  ((local_1 *) param_0)->local_0->local_2 = local_2;
  func_80093370(param_0, 1);
  func_8009337C(param_0, 1);
  func_80093230(param_0, 1.0f);
  *((s8 *) (((s8 *) (*((u8 **) (((s8 *) param_0) + 0x50)))) + 0x15)) = 0;
  func_800931AC(param_0, 1);
  func_80092778(param_0);
  func_80092864(param_0, 1.0f);
}

void func_80092A1C(u8 *param_0) {
    s32 local_0;

    func_80092EC8(param_0, 0);
    func_8009359C(param_0, 0);
    func_800ADFE0((*(s16 *)((s8 *)((*(u8 **)((s8 *)(param_0) + (0x50)))) + (0))));
    (*(s16 *)((s8 *)((*(u8 **)((s8 *)(param_0) + (0x50)))) + (0))) = 0;
    func_800DBFD8((*(s32 *)((s8 *)((*(u8 **)((s8 *)(param_0) + (0x50)))) + (4))));
    (*(s32 *)((s8 *)((*(u8 **)((s8 *)(param_0) + (0x50)))) + (4))) = 0;
    local_0 = (*(s32 *)((s8 *)((*(u8 **)((s8 *)(param_0) + (0x50)))) + (0x84)));
    if (local_0 != 0) {
        func_800A70B0(local_0);
    }
    (*(s32 *)((s8 *)((*(u8 **)((s8 *)(param_0) + (0x50)))) + (0x84))) = 0;
    _babackpack_entrypoint_8(param_0);
}

void func_80092AA4(param_0)
void *param_0;
{
  void *tmp = param_0;
  void *ptr;
  *((s32 *) (0x84 + ((char *) (*((void **) (((char *) ((0, tmp))) + 0x50)))))) = 0;
}

void func_80092AB0(PlayerState* arg0)
{
    func_800E0ACC(func_80092AD8(arg0));
}

Unkfunc_800E0960_1 *func_80092AD8(PlayerState *param_0) {
    return func_800AE6BC(func_800AE080(*(s16 *)(*(u8 **)((u8 *)param_0 + 0x50))));
}

PlayerState *func_80092B04(param_0, param_1) PlayerState * param_0; s32 param_1;
{
    s32 local_0;
    if (*(s16*)(*(s32*)((u8*)param_0 + 0x50) + 0x0C) == 0x607)
    {
        return (PlayerState *)func_80093F7C(param_0);
    }
    local_0 = func_800D674C(*(s16*)(*(s32*)((u8*)param_0 + 0x50) + 0x0C));
    if (param_1 == 0)
    {
        func_800D62E4(*(s16*)(*(s32*)((u8*)param_0 + 0x50) + 0x0C), param_1);
    }
    return (PlayerState *)local_0;
}

short func_80092B80(s16 *param_0) {
    return ((s16 *)*((int *)param_0 + 0x14))[6];
}

f32 func_80092B8C(PlayerState *param_0, f32 *param_1) {
    func_800EE7F8(param_1, (*(u8 **)((u8 *)param_0 + 0x50)) + 0x64);
    return *(f32 *)((*(u8 **)((u8 *)param_0 + 0x50)) + 0x70);
}

s32 func_80092BC4(s32 param_0)
{
  u8 **new_var2;
  int new_var;
  new_var = param_0 + 0x54;
  new_var2 = (u8 **) new_var;
  return new_var2[0xFFFFFFFF][0xC4];
}

f32 func_80092BD0(u8 *param_0) {
    return (*(f32 *)((s8 *)((*(u8 **)((s8 *)(param_0) + (0x50)))) + (0xC8)));
}

f32 func_80092BDC(void *arg)
{
    return ((f32 *)(*(void **)((char *)arg + 0x50)))[7];
}

f32 func_80092BE8(PlayerState *param_0)
{
  return *(f32 *)(*(s32 *)((char *)param_0 + 0x50) + 0x28);
}

f32 func_80092BF4(PlayerState *param_0) {
    return *(f32 *)((char *)(*(struct ba_alarm_s **)((char *)param_0 + 0x50)) + 0x30);
}

void func_80092C00(PlayerState* arg0, f32* arg1)
{
    func_800921E0(arg0, 0x1, arg1);
}

void func_80092C24(PlayerState* arg0, f32* arg1)
{
    func_800921E0(arg0,0x2,arg1);
}

void func_80092C48(PlayerState* arg0,f32* arg1)
{
    func_800921E0(arg0,0x7,arg1);
}

void func_80092C6C(s32 arg0,s32 arg1)
{
    func_800921E0(arg0,0x6,arg1);
}

void func_80092C90(void *param_0, s32 param_1, u32 param_2)
{
  s32 *local_0;
  local_0 = *((s32 **) (((char *) param_0) + 0x50));
  func_800DBEFC(*((s32 *) (((char *) (*((s32 **) (((char *) param_0) + 0x50)))) + 0x4)), param_2, param_1);
  if (func_800EEEA8(param_1) != 0)
  {
    func_8009C128(param_0, param_1);
  }
}

void func_80092CDC(u8 *param_0, s32 param_1, s32 param_2)
{
    func_800DBEFC((*(s32 *)((s8 *)((*(u8 **)((s8 *)(param_0) + (0x50)))) + (4))), param_2, param_1);
    func_800EEF24(param_1);
}

int func_80092D18(s32 param_0, s32 param_1)
{
    func_800EE7F8(param_1, *(s32 *)(param_0 + 0x50) + 0x44);
}

int func_80092D44(s32 param_0, s32 param_1)
{
  f32 local_1[3];
  f32 local_0[3];
  func_800921E0(param_0, 4, local_0);
  func_800921E0(param_0, 3, local_1);
  func_800EE780(param_1, local_0, local_1);
  func_800EF334(param_1, 0.5f);
}

void func_80092D9C(s32 arg0,s32 arg1)
{
    func_800921E0(arg0,0x3,arg1);
}

void func_80092DC0(s32 arg0,s32 arg1)
{
    func_800921E0(arg0,0x4,arg1);
}

void func_80092DE4(s32 arg0,s32 arg1)
{
    func_800921E0(arg0,0x8,arg1);
}

void func_80092E08(s32 arg0,s32 arg1)
{
    func_800921E0(arg0,0x9,arg1);
}

void func_80092E2C(s32 arg0,s32 arg1)
{
    func_800921E0(arg0,0xA,arg1);
}

u8 func_80092E50(void *param_0)
{
  u8 *local_0;
  ;
  return (*((u8 **) (((u8 *) param_0) + 0x50)))[0x15];
}

void func_80092E5C(s32 arg0,s32 arg1)
{
    func_800921E0(arg0,0x5,arg1);
}

void func_80092E80(s32 param_0)
{
  func_800AE080(**(s16 **)(param_0 + 0x50));
}

s32 func_80092EA4(s32 param_0)
{
    return ((u8 *)(*(u8 **)(param_0 + 0x50)))[0x17];
}

s32 func_80092EB0(s32 param_0)
{
    return ((u8 *)(*(u8 **)(param_0 + 0x50)))[0x18];
}

void func_80092EBC(void *arg, s32 v)
{
    ((s8 *)(*(void **)((char *)arg + 0x50)))[20] = v;
}

void func_80092EC8(param_0, param_1) u8 * param_0; s32 param_1;
{
    s32 sp2C;
    s32 sp28;
    u8 local_1;

    if (param_1 != *(s16 *)((*(u8 **)(param_0 + 0x50)) + 0xC)) {
        if (*(s16 *)((*(u8 **)(param_0 + 0x50)) + 0xC) != 0) {
            func_800D70F8(*(s16 *)((*(u8 **)(param_0 + 0x50)) + 0xC), 0);
            func_800D6CEC(*(s16 *)((*(u8 **)(param_0 + 0x50)) + 0xC));
            *(s16 *)((*(u8 **)(param_0 + 0x50)) + 0xE) = 0;
        }

        local_1 = (*(u8 **)(param_0 + 0x50))[0x12];
        if (local_1 != 0) {
            func_80100E18((s16)local_1);
            (*(u8 **)(param_0 + 0x50))[0x12] = 0;
        }

        *(s16 *)((*(u8 **)(param_0 + 0x50)) + 0xC) = (s16)param_1;
        func_80093FD4(param_0, param_1);

        if (param_1 != 0) {
            sp2C = func_80092B04(param_0, 0);
            func_800D70F8(*(s16 *)((*(u8 **)(param_0 + 0x50)) + 0xC), 1);
            func_800ADD80(*(s16 *)((*(u8 **)(param_0 + 0x50)) + 0),
                func_800B27E0(sp2C));

            if ((*(u8 **)(param_0 + 0x50))[0x12] == 0) {
                if (func_800B26F0(sp2C) != 0) {
                    sp28 = 1;
                } else {
                    sp28 = 0;
                }
                (*(u8 **)(param_0 + 0x50))[0x12] =
                    func_80100D24(sp2C,
                        *(s16 *)((*(u8 **)(param_0 + 0x50)) + 0xC),
                        sp28, func_800A25D0(param_0), 0, 0);
            }

            func_800B237C(func_800B2840(sp2C),
                (*(u8 **)(param_0 + 0x50)) + 0x50,
                (*(u8 **)(param_0 + 0x50)) + 0x5C);
            *(f32 *)((*(u8 **)(param_0 + 0x50)) + 0x58) = 0.0f;
            *(f32 *)((*(u8 **)(param_0 + 0x50)) + 0x50) =
                *(f32 *)((*(u8 **)(param_0 + 0x50)) + 0x58);
            func_800EE7F8((*(u8 **)(param_0 + 0x50)) + 0x64,
                (*(u8 **)(param_0 + 0x50)) + 0x50);
            *(f32 *)((*(u8 **)(param_0 + 0x50)) + 0x70) =
                *(f32 *)((*(u8 **)(param_0 + 0x50)) + 0x5C);
            *(f32 *)((*(u8 **)(param_0 + 0x50)) + 0x60) =
                *(f32 *)((*(u8 **)(param_0 + 0x50)) + 0x74) =
                func_800B2354(func_800B2840(sp2C));
        }
    }
}

void func_80093070(s32 param_0, s32 param_1, s32 param_2, u8 *param_3)
{
  s32 sp34;
  s32 sp30;
  s32 sp2C;
  s32 sp20;
  s32 temp_v0;
  s32 var_a3;
  u8 temp_v1;
  sp34 = func_800D674C(param_2);
  sp30 = func_800D674C(param_1);
  var_a3 = sp20 & 0xFFFFFFFFu;
  temp_v0 = func_800A25D0(param_0);
  var_a3 = temp_v0;
  temp_v1 = *param_3;
  if (temp_v1 != 0)
  {
    sp20 = func_80100E18((s16) temp_v1);
  }
  *param_3 = func_80100D24(sp34, param_2, 1, var_a3, 0, 0);
  sp2C = func_800B2840(sp34);
  func_800B25D8(func_80100A74(*param_3, 0), sp2C, sp30);
}

void func_8009312C(param_0, param_1) Actor_8009312C * param_0; unsigned int param_1;
{
  ActorLocal_CC_50 *local_0;
  if (param_1 != 0)
  {
    local_0 = *(ActorLocal_CC_50 **)((char *)param_0 + 0x50);
    if (param_1 != local_0->unkE)
    {
      local_0->unkE = param_1;
      local_0 = *(ActorLocal_CC_50 **)((char *)param_0 + 0x50);
      func_80093070(param_0, param_1, local_0->unkC, (u8 *)local_0 + 0x12);
    }
  }
}

void func_8009316C(u8 *param_0, int param_1)
{
  u8 *temp_v0;
  u8 *temp_v0_2;
  if (param_1 != 0)
  {
    temp_v0 = *((u8 **) (((char *) param_0) + 0x50));
    if (param_1 != (*((s16 *) (((char *) temp_v0) + 0x9E))))
    {
      *((s16 *) (((char *) temp_v0) + 0x9E)) = param_1;
      if ((!temp_v0) && (!temp_v0))
      {
      }
      temp_v0_2 = *((u8 **) (((char *) param_0) + 0x50));
      func_80093070(param_0, param_1, *((s16 *) (((char *) temp_v0_2) + 0x9C)), temp_v0_2 + 0xA0);
    }
  }
}

void func_800931AC(param_0, param_1) PlayerState * param_0; s32 param_1; {
    if ((param_1 != QQ->unk15) && ((param_1 == 2) || (QQ->unk15 == 2))) {
        yaw_setIdeal(param_0, func_800136E4(yaw_get(param_0) + 180.0f));
        yaw_applyIdeal(param_0);
    }
    QQ->unk15 = param_1;
}

void func_80093230(PlayerState *param_0, f32 param_1) {
    PP->unk1C = param_1;
    PP->unk70 = PP->unk1C * PP->unk5C;
    PP->unk74 = PP->unk1C * PP->unk60;
    func_800EF334(&PP->unk64, PP->unk1C);
}

void func_8009328C(PlayerState *param_0, f32 param_1)
{
    *(f32 *)(*(s32 *)((char *)param_0 + 0x50) + 0x28) = func_800136E4(param_1);
}

func_800932BC(s32 param_0, f32 param_1) {
    *(f32*)(*(s32*)(param_0 + 0x50) + 0xC8) = param_1;
}

void func_800932CC(u8 *param_0, int param_1)
{
  u8 *temp_v0;
  temp_v0 = *((u8 **) (((s8 *) param_0) + 0x50));
  if (param_1 != (*((u8 *) (((s8 *) temp_v0) + 0xC4))))
  {
    if (param_1 != 0)
    {
      *((f32 *) (((s8 *) temp_v0) + 0xC8)) = 0.0f;
    }
    temp_v0 = *((u8 **) (((s8 *) param_0) + 0x50));
    *((s8 *) (((s8 *) temp_v0) + 0xC4)) = param_1;
  }
}

void func_80093300(PlayerState *param_0, f32 param_1) {
    *(f32 *)((*(u8 **)((u8 *)param_0 + 0x50)) + 0x30) = param_1;
    func_8009332C(param_0, param_1);
}

func_8009332C(s32 param_0, f32 param_1) {
    *(f32*)(*(s32*)(param_0 + 0x50) + 0x3c) = param_1;
}

void func_8009333C(void *param_0)
{
  func_800EE7F8(*(s32 *)((char *)param_0 + 80) + 68);

}

void func_80093360(PlayerState *param_0, f32 param_1) {
    *(f32 *)((u8 *)*(s32 **)((u8 *)param_0 + 0x50) + 0x48) = param_1;
}

void func_80093370(arg, v) void * arg; s32 v;
{
    ((s8 *)(*(void **)((char *)arg + 0x50)))[23] = v;
}

void func_8009337C(arg, v) void * arg; s32 v;
{
    ((s8 *)(*(void **)((char *)arg + 0x50)))[24] = v;
}

void func_80093388(u8 *param_0) {
    f32 local_2;
    f32 local_1;
    f32 local_4;
    u8 *local_5;
    u8 *local_6;

    local_5 = *(u8 **)((s8 *)param_0 + 0x50);
    local_2 = *(f32 *)((s8 *)local_5 + 0x3C) - *(f32 *)((s8 *)local_5 + 0x30);
    local_1 = mlAbsF(local_2);
    local_4 = local_1;
    if (local_1 < 0.01f) {
        *(f32 *)((s8 *)*(u8 **)((s8 *)param_0 + 0x50) + 0x30) = *(f32 *)((s8 *)*(u8 **)((s8 *)param_0 + 0x50) + 0x3C);
        return;
    }
    if (local_1 > 5.0f) {
        local_4 = 1.0f;
    }
    if (local_2 > 0.0f) {
        local_6 = *(u8 **)((s8 *)param_0 + 0x50);
        *(f32 *)((s8 *)local_6 + 0x30) = *(f32 *)((s8 *)local_6 + 0x30) + local_4;
        return;
    }
    *(f32 *)((s8 *)*(u8 **)((s8 *)param_0 + 0x50) + 0x30) = *(f32 *)((s8 *)*(u8 **)((s8 *)param_0 + 0x50) + 0x30) - local_4;
}

void func_80093448(s32 *param_0)
{
  s32 local_2;
  s32 local_1;
  s32 local_0;
  s32 local_3;
  if (!(*((s32 *) (((char *) (*((s32 **) (((char *) param_0) + 0x50)))) + 0x84))))
  {
 do { } while (0);
    if (1)
    {
      func_8009C128(param_0, &local_0);
    }
    _chbaddiesetup_entrypoint_5(&func_800927C4, 0x215, local_0, local_1, local_2, *((s32 *) (((char *) param_0) + 0x184)));
  }
  func_80093388(param_0);
  func_80092018(param_0);
  func_800920C8(param_0);
}

void func_800934C4(void *param_0)
{
  s32 temp_a1;
  temp_a1 = *((s32 *) (((char *) (*((u8 **) (((char *) param_0) + 0x50)))) + 4));
  if (temp_a1 != 0)
  {
    *((s32 *) (((char *) (*((u8 **) (((char *) param_0) + 0x50)))) + 4)) = func_800DC060(temp_a1, *((s32 *) (((char *) (*((u8 **) (((char *) param_0) + 0x50)))) + 4)), param_0);
  }
}

void func_80093504(param_0) u8 * param_0; {
    func_800F23D0((*(s32 *)((s8 *)(param_0) + (0x50))) + 0xCC);
}

void func_80093528(u8 *param_0) {
    u8 local_0;
    u8 *local_1;

    (*(s8 *)((s8 *)((*(u8 **)((s8 *)(param_0) + (0x50)))) + (0x1A))) = 0;
    func_800DBEB0((*(s32 *)((s8 *)((*(u8 **)((s8 *)(param_0) + (0x50)))) + (4))), param_0);
    (*(s8 *)((s8 *)((*(u8 **)((s8 *)(param_0) + (0x50)))) + (0x16))) = 0;
    (*(u8 *)((s8 *)((*(u8 **)((s8 *)(param_0) + (0x50)))) + (0xA5))) = 0U;
    local_1 = (*(u8 **)((s8 *)(param_0) + (0x50)));
    local_0 = (*(u8 *)((s8 *)(local_1) + (0xA5)));
    (*(u8 *)((s8 *)(local_1) + (0xA1))) = local_0;
    (*(u8 *)((s8 *)((*(u8 **)((s8 *)(param_0) + (0x50)))) + (0x10))) = local_0;
}

void func_80093584(u8 *param_0) {
    u8 *temp_v0;

    (*(s32 *)((s8 *)((*(u8 **)((s8 *)(param_0) + (0x50)))) + (0x94))) = 0;
    temp_v0 = (*(u8 **)((s8 *)(param_0) + (0x50)));
    (*(s32 *)((s8 *)(temp_v0) + (8))) = (s32) (*(s32 *)((s8 *)(temp_v0) + (0x94)));
}

void func_8009359C(param_0, param_1) PlayerState * param_0; s32 param_1;
{
    void *local_0;
    LocalSub *local_1;
    s32 local_2;
    s32 local_3;
    local_1 = &MODEL(param_0)->field_90;
    if (param_1 != local_1->field_C) {
        if (local_1->field_C) {
            if (local_1->field_10) {
                func_80100E18(local_1->field_10);
                local_1->field_10 = 0;
            }
            func_800ADFE0(local_1->field_0);
            local_1->field_0 = 0;
            func_800D70F8(local_1->field_C, 0);
            func_800D6CEC(local_1->field_C);
            local_1->field_C = 0;
            local_1->field_E = 0;
        }
        if (!param_1) {
            local_1->field_12 = 0;
            return;
        }
        local_1->field_C = param_1;
        local_0 = func_80093738(param_0);
        func_800D70F8(local_1->field_C, 1);
        if (func_800B26F0(local_0)) local_2 = 1;
        else local_2 = 0;
        local_3 = func_800A25D0(param_0);
        local_1->field_10 = func_80100D24(local_0, local_1->field_C, local_2, local_3, 0, 0);
        local_1->field_0 = func_800AE020();
        func_800AE6FC(func_800AE080(local_1->field_0), func_800E09B8(0xC));
    }
}

void func_800936CC(void *arg, s32 v)
{
    ((s8 *)(*(void **)((char *)arg + 0x50)))[162] = v;
}

func_800936D8(s32 param_0, f32 param_1) {
    *(f32*)(*(s32*)(param_0 + 0x50) + 0x98) = param_1;
}

void func_800936E8(arg, v) void * arg; s32 v;
{
    ((s8 *)(*(void **)((char *)arg + 0x50)))[163] = v;
}

s32 func_800936F4(s32 param_0)
{
  if (!param_0)
  {
  }
  return ((u8 **) (param_0 + 0x54))[0xFFFFFFFF ^ 0][0xA3];
}

void func_80093700(arg, v) void * arg; s32 v;
{
    ((s8 *)(*(void **)((char *)arg + 0x50)))[25] = v;
}

void func_8009370C(u8 *param_0) {
    func_800AE6BC(func_800AE080((*(s16 *)((s8 *)((*(u8 **)((s8 *)(param_0) + (0x50)))) + (0x90)))));
}

int func_80093738(param_0) void * param_0;
{
  u32 t6;
  s16 arg;
  t6 = (*((u32 *) (((u8 *) param_0) + 0x50))) & 0xFFFFFFFFFFFFFFFF;
  arg = *((s16 *) (((u8 *) t6) + 0x9C));
  func_800D674C(arg);
}

void func_8009375C(u8 *param_0, u8 *param_1, s32 param_2) {
    s32 local_0;
    s16 local_1;
    s32 local_2;
    s32 local_3;
    s32 local_4;

    local_3 = (*(s32 *)((s8 *)(param_1) + (4))) + 0x40;
    switch (param_2) {                                 
    case 0:
        local_2 = func_80092B04(param_0, 0);
        local_1 = (*(s16 *)((s8 *)((*(u8 **)((s8 *)(param_0) + (0x50)))) + (0)));
        local_0 = baanim_getAnimCtrlPtr(param_0);
        (*(s8 *)((s8 *)((*(u8 **)((s8 *)(param_0) + (0x50)))) + (0x10))) = 1;
        (*(s32 *)((s8 *)((*(u8 **)((s8 *)(param_0) + (0x50)))) + (8))) = local_3;
        break;
    case 1:
        local_2 = func_80093738(param_0);
        local_1 = (*(s16 *)((s8 *)((*(u8 **)((s8 *)(param_0) + (0x50)))) + (0x90)));
        local_0 = func_8008D04C(param_0);
        (*(s8 *)((s8 *)((*(u8 **)((s8 *)(param_0) + (0x50)))) + (0xA1))) = 1;
        (*(s32 *)((s8 *)((*(u8 **)((s8 *)(param_0) + (0x50)))) + (0x94))) = local_3;
        break;
    }
    local_4 = func_800B27E0(local_2);
    func_8008C200(local_1, local_4, func_8008AEDC(local_0));
    func_800AE598(func_800AE080(local_1), param_1 + 4);
}

void func_80093864(PlayerState *param_0, s32 param_1, s32 param_2)
{
    f32 local_0[3];
    f32 local_1[3];
    f32 local_2[3];
    f32 local_3;
    void *local_4;
    void *local_5;
    switch (param_2) {
    case 0:
        func_8009216C(param_0, local_1, local_0);
        local_3 = MODEL(param_0)->field_1C;
        local_4 = func_80092B04(param_0, 1);
        local_5 = func_800AE080(MODEL(param_0)->field_0);
        if (local_4) {
            if (MODEL(param_0)->field_12) {
                func_800DF720(func_80100AC4(MODEL(param_0)->field_12));
                func_800DF818(func_80100A74(MODEL(param_0)->field_12, 0));
            }
            func_800DF714(MODEL(param_0)->field_8);
            func_800DF72C(local_5);
            func_800A06E8(param_0);
            func_800DF47C(func_80092234, param_0);
            func_800DF440(0);
            if (func_800A946C() == 1) func_800DF574(1);
        }
        break;
    case 1:
        local_3 = MODEL(param_0)->field_90.field_8;
        local_4 = func_80093738(param_0);
        local_5 = func_800AE080(MODEL(param_0)->field_90.field_0);
        func_800EE7F8(local_1, MODEL(param_0)->field_AC);
        func_800EE7F8(local_0, MODEL(param_0)->field_B8);
        if (local_4) {
            if (MODEL(param_0)->field_90.field_10) {
                func_800DF720(func_80100AC4(MODEL(param_0)->field_90.field_10));
                func_800DF818(func_80100A74(MODEL(param_0)->field_90.field_10, 0));
            }
            func_800DF714(MODEL(param_0)->field_90.field_4);
            func_800DF72C(local_5);
            func_800DF3E0();
            func_800DF47C(func_80092224, param_0);
            func_800A0714(param_0, MODEL(param_0)->field_90.field_C);
        }
        break;
    }
    func_800EE7F8(local_2, MODEL(param_0)->field_2C);
    func_800EF04C(local_1, MODEL(param_0)->field_44);
    func_800EF04C(local_2, MODEL(param_0)->field_44);
    if (local_4) {
        func_800923A8(param_0, param_2 == 0);
        func_800DE448(local_1, local_0, local_3, local_2, local_4);
    }
}

void func_80093AB8(param_0, param_1) PlayerState * param_0; s32 param_1;
{
    s32 local_0;
    s32 local_1;
    f32 local_2[3];
    LocalModel *local_3;
    s32 local_4;
    if (MODEL(param_0)->field_17) {
        local_0 = func_800A89F8();
        local_3 = MODEL(param_0);
        switch (local_3->field_90.field_12) {
        case 1:
            local_1 = 3;
            break;
        case 2:
        case 3:
            switch (local_3->field_19) {
            case 0:
                local_1 = 3;
                break;
            case 1:
                local_1 = 3;
                if (func_800A4C68(param_0) == local_0) {
                    if (MODEL(param_0)->field_90.field_13) local_1 = 1;
                    else if (!MODEL(param_0)->field_18) local_1 = 0;
                }
                break;
            }
            break;
        }
        switch (local_1) {
        case 0: return;
        case 1: break;
        case 3:
            func_8009C128(param_0, local_2);
            if (!func_800E3E8C(local_2, MODEL(param_0)->field_1C * MODEL(param_0)->field_74)) return;
            local_4 = func_800BEC1C();
            if (local_4) {
                if (!MODEL(param_0)->field_90.field_15) {
                    MODEL(param_0)->field_90.field_15 = 1;
                    func_800EF04C(local_2, MODEL(param_0)->field_64);
                    MODEL(param_0)->field_90.field_14 = _dbzone_entrypoint_4(func_800BEC28(0), local_2, MODEL(param_0)->field_90.field_16);
                }
                if (MODEL(param_0)->field_90.field_14 && !_glzone_entrypoint_6(local_4, MODEL(param_0)->field_90.field_16, MODEL(param_0)->field_90.field_14)) return;
            }
        }
        switch (MODEL(param_0)->field_90.field_12) {
        case 1:
            if (MODEL(param_0)->field_18 || func_800A4C68(param_0) != local_0) {
                if (!MODEL(param_0)->field_10) {
                    func_8008CA98(param_0);
                    func_8009375C(param_0, param_1, 0);
                }
                func_80093864(param_0, param_1, 0);
                if (MODEL(param_0)->field_90.field_13) {
                    func_8009216C(param_0, MODEL(param_0)->field_AC, MODEL(param_0)->field_B8);
                    if (!MODEL(param_0)->field_90.field_11) {
                        func_8008D058(param_0);
                        func_8009375C(param_0, param_1, 1);
                    }
                    func_80093864(param_0, param_1, 1);
                }
            }
            break;
        case 2:
            if (local_1 == 3) {
                if (!MODEL(param_0)->field_10) {
                    _bsfirstp_entrypoint_1(param_0, 0);
                    func_8009375C(param_0, param_1, 0);
                }
                func_80093864(param_0, param_1, 0);
            }
            break;
        case 3:
            if (local_1 == 3) {
                if (!MODEL(param_0)->field_10) {
                    _bsfirstp_entrypoint_1(param_0, 0);
                    func_8009375C(param_0, param_1, 0);
                }
                func_80093864(param_0, param_1, 0);
            }
            break;
        }
    }
}

s32 func_80093DF4(param_0, param_1) u8 * param_0; s32 param_1; {
    return (param_1 == (*(u8 *)((s8 *)((*(u8 **)((s8 *)(param_0) + (0x50)))) + (0xA2)))) ? 1 : 0;
}

void func_80093E18(u8 *param_0, s32 param_1)
{
  s8 _sfpad[4];
  s32 sp28;
  s32 sp24;
  u8 *temp_v0;
  sp24 = func_800A89F8();
  sp28 = func_800A88C4(sp24, func_800A5090(param_0));
  func_800E44FC(param_1);
  if ((*((u8 *) (((s8 *) (*((u8 **) (((s8 *) param_0) + 0x50)))) + 0xA1))) == 0)
  {
    _bsfirstp_entrypoint_1(param_0, 1);
    if (1)
    {
      temp_v0 = *((u8 **) (((s8 *) param_0) + 0x50));
      _bsfirstp_entrypoint_0(param_0, temp_v0 + 0xAC, temp_v0 + 0xB8);
      func_8009375C(param_0, param_1, 1);
    }
  }
  func_80093864(param_0, param_1, 1);
  func_800A88C4(sp24, sp28);
  func_800E44FC(param_1);
}

f32 func_80093ECC(s32 param_0, s32 *param_1, s32 param_2, f32 *param_3)
{
    func_8009216C(param_0, param_1, param_2);
    func_800EE7F8(param_3, (s32 *)((u8 *)(((s32 *)param_0)[0x14]) + 0x2C));
    func_800EF04C(param_1, (s32 *)((u8 *)(((s32 *)param_0)[0x14]) + 0x44));
    func_800EF04C(param_3, (s32 *)((u8 *)(((s32 *)param_0)[0x14]) + 0x44));
    return *(f32 *)((u8 *)(((s32 *)param_0)[0x14]) + 0x1C);
}

s32 func_80093F30(s32 param_0)
{
  int new_var3;
  long long new_var2;
  int new_var;
  new_var2 = param_0 * 4;
  new_var3 = new_var2;
  new_var = new_var3 & 0xFFFFFFFFFFFFFFFF;
  if (func_8009EA2C())
  {
    new_var2 = new_var;
    return D_80117DDC[new_var2];
  }
  else
  {
    return D_80117DD8[new_var2 & 0xFFFFFFFFFFFFFFFF];
  }
}

s32 func_80093F7C(param_0, param_1) s32 param_0; s32 param_1;
{
    s32 local_0;

    local_0 = func_800D674C(*(s32 **)(*(s32 **)(param_0 + 0x50) + 67));
    if (param_1 == 0)
    {
        func_800D62E4(*(s32 **)(*(s32 **)(param_0 + 0x50) + 67));
    }
    return local_0;
}

int func_80093FD4(param_0, param_1) s32 param_0; u32 param_1;
{
    s32 local_0;
    s32 local_1;
    s32 local_2;

    if (param_1 == 0x607)
    {
        local_0 = func_800EA05C();
        local_1 = 0;
        if (*(s16 *)D_80117DF0 != -1)
        {
            do
            {
                if (*(s16 *)(D_80117DF0 + local_1 * 4) == local_0) break;
                local_1++;
            } while (*(s16 *)(D_80117DF0 + local_1 * 4) != -1);
        }
        local_2 = local_1 << 2;
        local_0 = func_80093F30(*(s16 *)(D_80117DF0 + local_2 + 2));
        func_800941C8(param_0, local_0);
        return;
    }
    else
    {
        func_800941C8(param_0, 0);
        return;
    }
}

void func_80094070(param_0, param_1) Actor94070 * param_0; f32 * param_1; {
    f32 local_3;
    f32 local_0[3];
    s32 local_1;
    s32 local_2;
    if (param_0->local_0->local_0 && func_800D90A4(&param_0->local_0->local_2)) {
        func_800E3980(local_0);
        local_3 = func_800EEAD4(param_1, local_0);
        for (local_1 = 0; local_1 < 2; local_1++) {
            if (local_3 < D_80117DD0[local_1].local_0) break;
        }
        local_1--;
        local_2 = func_80093F30(local_1);
        if (local_2 != param_0->local_0->local_0) {
            if (func_800942D0(param_0, local_1)) {
                if (param_0->local_0->local_1 && local_2 != param_0->local_0->local_1) {
                    func_800E4BB8(param_0->local_0->local_1);
                }
                param_0->local_0->local_1 = local_2;
                if (func_800E488C(param_0->local_0->local_1)) {
                    func_800941C8(param_0, param_0->local_0->local_1);
                }
            } else if (param_0->local_0->local_1) {
                func_800E4BB8(param_0->local_0->local_1);
                param_0->local_0->local_1 = 0;
            }
        } else if (param_0->local_0->local_1) {
            func_800E4BB8(param_0->local_0->local_1);
            param_0->local_0->local_1 = 0;
        }
    }
}

void func_800941C8(u8 *param_0, s32 param_1) {
    s32 local_3;
    s32 local_2;
    s32 local_1;
    u8 local_4;
    u8 *local_5;

    local_5 = (*(u8 **)((s8 *)(param_0) + (0x50)));
    local_2 = (*(s32 *)((s8 *)(local_5) + (0x10C)));
    if (local_2 != 0) {
        func_800D70F8(local_2, 0);
        func_800D6CEC((*(s32 *)((s8 *)((*(u8 **)((s8 *)(param_0) + (0x50)))) + (0x10C))));
        local_5 = (*(u8 **)((s8 *)(param_0) + (0x50)));
    }
    local_4 = (*(u8 *)((s8 *)(local_5) + (0x12)));
    if (local_4 != 0) {
        func_80100E18((s16) local_4);
        (*(s8 *)((s8 *)((*(u8 **)((s8 *)(param_0) + (0x50)))) + (0x12))) = 0;
        local_5 = (*(u8 **)((s8 *)(param_0) + (0x50)));
    }
    (*(s32 *)((s8 *)(local_5) + (0x10C))) = param_1;
    (*(s32 *)((s8 *)((*(u8 **)((s8 *)(param_0) + (0x50)))) + (0x110))) = 0;
    if (param_1 != 0) {
        (*(f32 *)((s8 *)((*(u8 **)((s8 *)(param_0) + (0x50)))) + (0x114))) = 0.0f;
        local_1 = func_80093F7C(param_0, 0);
        func_800D70F8((*(s32 *)((s8 *)((*(u8 **)((s8 *)(param_0) + (0x50)))) + (0x10C))), 1);
        if (func_800B26F0(local_1) != 0) {
            local_3 = 1;
        } else {
            local_3 = 0;
        }
        (*(s8 *)((s8 *)((*(u8 **)((s8 *)(param_0) + (0x50)))) + (0x12))) = func_80100D24(local_1, (*(s32 *)((s8 *)((*(u8 **)((s8 *)(param_0) + (0x50)))) + (0x10C))), local_3, func_800A25D0(param_0), 0, 0);
    }
}

s32 func_800942D0(param_0, param_1) u8 * param_0; s32 param_1; {
    s32 local_0;

    func_8001BDAC(&local_0, 1);
    if ((*(s32 *)((s8 *)((*(u8 **)((s8 *)(param_0) + (0x50)))) + (0x110))) != 0) {
        local_0 += *(s32 *)((u8 *)&D_80117DD4 + (param_1 * 0x10));
    }
    return local_0 >= 0x32001;
}

s32 func_80094340(void)
{
	return 0x4;
}

s32 func_80094348(u8 *param_0, s32 param_1) {
    return ((*(u8 *)((s8 *)((*(u8 **)((s8 *)(param_0) + (0x64)))) + (2))) & param_1) ? 1 : 0;
}

void func_80094370(s32 arg0)
{
    func_800946C4(arg0,0);
}

void func_80094390(u8 *param_0) {
    if ((func_800C954C() == 0) && (func_800F6774(*(s32 *)(param_0 + 0x184)) != 0) && (_batimer_decrement(param_0, 0xD) != 0)) {
        func_8009E9F0(0.0f);
        func_80094430(param_0, 0);
        func_80101180(0x1CD, 0x76, 0);
    }
    if (func_800C0638() == 0) {
        func_800D2498(0x105, (s32)_batimer_get(param_0, 0xD), 0);
    }
}

void func_80094430(s32 param_0, f32 param_1) {
    if (param_1 != 0.0f) {
        func_800946C4(param_0, 2);
    } else {
        func_80094370(param_0);
    }
    if (param_1 > 0.0f) {
        func_800947EC(param_0, 0x10, 1);
        _batimer_set(param_0, 0xD, param_1);
        return;
    }
    func_800947EC(param_0, 0x10, 0);
    _batimer_set(param_0, 0xD, 0);
}

s32 func_800944E0(PlayerState *param_0, s32 param_1)
{
  return D_80117E3C[param_1 << 1];

}

u8 func_800944F8(s32 param_0, s32 param_1)
{
  return D_80117E3D[param_1 << 1];
}

s32 func_80094510(PlayerState *param_0)
{
  u8 *local_0 = *((u8 **) (((u8 *) param_0) + 0x64));
  u8 *new_var;
  u32 local_1 = ((u32 *) D_80117E30)[local_0[0]];
  new_var = local_0;
  return *((u8 *) (new_var[1] + ((u32 *) D_80117E30)[local_0[0]]));
}

void func_80094538(s32 param_0)
{
    func_8009E9E4(func_80094510(param_0));
    func_8009E9F0(_batimer_get(param_0, 13));
}

void func_80094574(PlayerState *param_0, s32 param_1) {
    s32 local_0;
    LOCAL_INDEX = 0;
    while ((local_0 = func_80094510(param_0)) != 0) {
        if (_gcegg_entrypoint_6(local_0) && local_0 == param_1) return;
        LOCAL_INDEX++;
    }
    LOCAL_INDEX = 0;
    while ((local_0 = func_80094510(param_0)) != 0) {
        if (_gcegg_entrypoint_6(local_0)) return;
        LOCAL_INDEX++;
    }
    LOCAL_INDEX = 0;
}

void func_80094644(void *param_0) {
    s32 t;
    (*(S_94644 **)((u8 *)param_0 + 0x64))->unk2 = 0;
    func_80094370(param_0);
    func_80094574(param_0, func_8009E964());
    t = (s32)func_8009E970();
    if (t != 0) { func_80094430(param_0, (f32)t); }
    (*(S_94644 **)((u8 *)param_0 + 0x64))->unk3 = 0;
}

void func_800946C4(param_0, param_1) PlayerState * param_0; s32 param_1;
{
  switch (param_1)
  {
    case 0:
      func_800947EC(param_0, 1, 0);
      func_800947EC(param_0, 2, 0);
      func_800947EC(param_0, 4, 0);
      func_800947EC(param_0, 8, 0);
      break;

    case 1:
      func_800947EC(param_0, 1, 1);
      func_800947EC(param_0, 2, 1);
      func_800947EC(param_0, 4, 1);
      func_800947EC(param_0, 8, 0);
      break;

    case 2:
      func_800947EC(param_0, 1, 1);
      func_800947EC(param_0, 2, 1);
      func_800947EC(param_0, 4, 1);
      func_800947EC(param_0, 8, 0);
      break;

  }

  (*(s8 *)((s8 *)((*(u8 **)((s8 *)(param_0) + (0x64)))) + (0))) = (s8) param_1;
  (*(s8 *)((s8 *)((*(u8 **)((s8 *)(param_0) + (0x64)))) + (1))) = 0;
}

void func_800947EC(param_0, param_1, param_2) PlayerState * param_0; s32 param_1; s32 param_2; {
    if (param_2 != 0) {
        (*(u8 **)((u8 *)param_0 + 0x64))[2] |= param_1;
    } else {
        (*(u8 **)((u8 *)param_0 + 0x64))[2] &= ~param_1;
    }
}

int func_80094824(s32 param_0)
{
  if (bainput_func_80097C7C())
  {
    func_80094A10(param_0);
    func_80094C88(param_0);
  }
  func_80094D04(param_0);
}

void func_80094864(PlayerState *param_0)
{
  s32 local_0;
  u8 local_1;
  if (func_800F6774(*((s32 *) (((char *) param_0) + 0x184))))
  {
    if (func_80094348(param_0, 0x10))
    {
      func_80094390(param_0);
    }
    if (func_80094348(param_0, 8))
    {
      local_0 = _gcegg_entrypoint_5(func_80094510(param_0));
      if (func_80094348(param_0, 4) == 0)
      {
        func_800D1824(local_0);
      }
    }
    if (func_80094348(param_0, 1) == 0)
    {
      local_1 = *((u8 *) (((char *) (*((u8 **) (((char *) param_0) + 0x64)))) + 3));
      switch (local_1)
      {
        case 0:
          if (bainput_func_80097C7C(param_0) != 0)
        {
          *((u8 *) (((char *) (*((u8 **) (((char *) param_0) + 0x64)))) + 3)) = 1U;
          func_80094E40(func_80094510(param_0));
          func_80094C88(param_0);
        }
          break;

        case 1:
          func_80094824(param_0);
          if (func_80094DA8(param_0) != 0)
        {
          *((u8 *) (((char *) (*((u8 **) (((char *) param_0) + 0x64)))) + 3)) = 2U;
          func_80094C88(param_0);
          return;
        }
          break;

        case 2:
          func_80094824(param_0);
          if (func_80094DA8(param_0) == 0)
        {
          *((u8 *) (((char *) (*((u8 **) (((char *) param_0) + 0x64)))) + 3)) = 0U;
        }
          break;

      }

    }
  }
}

int func_800949BC(s32 param_0) {
    return func_8009E674(param_0, 0x80000) != 0
        || (_bafpctrl_entrypoint_5(param_0) != 0 && _baeggfire_entrypoint_8(param_0) != 0);
}

s32 func_80094A10(param_0) PlayerState * param_0;
{
    s32 temp_v0_2;
    s32 sp20;
    s32 var_s0;
    u8 *temp_v0;

    sp20 = func_80094510(param_0);
    if (func_800949BC(param_0) != 0) {
        return sp20;
    }
    do {
        temp_v0 = *(u8 **)((u8 *)param_0 + 0x64);
        temp_v0[1] = temp_v0[1] + 1;
        temp_v0_2 = func_80094510(param_0);
        var_s0 = temp_v0_2;
        if (temp_v0_2 == 0) {
            *(*(u8 **)((u8 *)param_0 + 0x64) + 1) = 0;
            var_s0 = func_80094510(param_0);
        }
    } while (_gcegg_entrypoint_6(var_s0) == 0);
    if (var_s0 != sp20) {
        func_80094E40(var_s0);
    }
    return var_s0;
}

void func_80094AB4(S_94AB4 *param_0) {
    s32 sp1C;
    if (func_80094348(param_0, 2) != 0) {
        return;
    }
    sp1C = func_80094C64(param_0, param_0->unk64->unk1);
    if (sp1C == 0) {
        return;
    }
    if (_gcegg_entrypoint_6(sp1C) == 0) {
        return;
    }
    func_800D1824(_gcegg_entrypoint_5(sp1C));
}

s32 func_80094B14(PlayerState *param_0) {
    s32 local_0;
    local_0 = _gcegg_entrypoint_5(func_80094510(param_0));
    if (baflag_isTrue(param_0, 0x34) || (!func_80094348(param_0, 4) && func_800D1C38(local_0))) {
        func_800D1824(local_0);
        func_800FC660(0xF);
        return 0;
    }
    if (func_80094510(param_0) == 5 && _plsu_entrypoint_1(0x11) != -1) return 0;
    return 1;
}

s32 func_80094BC0(PlayerState *param_0)
{
  if (func_80094348(param_0, 4))
  {
    return 1;
  }
  return func_800D1A04(_gcegg_entrypoint_5(func_80094510(param_0)));
}

int func_80094C0C(s32 param_0, s32 param_1)
{
  if (func_80094348(param_0, 4))
  {
    return;
  }
  if (param_1 != 2 || func_8009EA2C() == 0)
  {
    func_800D1804(_gcegg_entrypoint_5(param_1));
  }
}

u8 func_80094C64(param_0, param_1) PlayerState * param_0; s32 param_1; {
    return ((u8 * *) D_80117E30)[*(u8 *)(*(u8 **)((u8 *)param_0 + 0x64))][param_1];
}

int func_80094C88(param_0) s32 param_0;
{
  s32 local_0;
  s32 local_1;
  s32 local_2;
  local_1 = 0;
  local_2 = func_80094C64(param_0, 0);
  while (local_2 != 0)
  {
    if (_gcegg_entrypoint_6(local_2))
    {
      local_0 = _gcegg_entrypoint_5(local_2);
      func_800D1824(local_0);
    }
    local_1++;
    local_2 = func_80094C64(param_0, local_1);
  }

}

void func_80094D04(param_0) u8 * param_0; {
    s32 local_0;
    s32 local_1;
    s32 local_2;
    s32 local_3;
    s32 local_4;

    local_4 = 0;
    local_0 = func_80094C64(param_0, 0);
    local_3 = local_0;
    if (local_0 != 0) {
        do {
            if ((local_4 != (*(u8 *)((s8 *)((*(u8 **)((s8 *)(param_0) + (0x64)))) + (1)))) && (_gcegg_entrypoint_6(local_3) != 0)) {
                local_2 = func_800D27C8(func_800D1C5C(_gcegg_entrypoint_5(local_3)));
                if (local_2 >= 0) {
                    func_800FAA34(local_2);
                }
            }
            local_4 += 1;
            local_1 = func_80094C64(param_0, local_4);
            local_3 = local_1;
        } while (local_1 != 0);
    }
}

int func_80094DA8(param_0) s32 param_0;
{
  s32 local_0;
  s32 local_1;
  s32 local_2;
  s32 local_3;
  local_0 = 0;
  local_1 = 0;
  local_2 = param_0 | 0;
  while ((local_3 = func_80094C64(local_2, local_1)) != 0)
  {
    if (_gcegg_entrypoint_6(local_3) != 0)
    {
      if (func_800D27F4(func_800D1C5C(_gcegg_entrypoint_5(local_3))) == 0)
      {
        return 0;
      }
    }
    local_1++;
  }

  return 1;
}

int func_80094E40()
{
  s32 local_0;
  local_0 = _gcegg_entrypoint_2();
  func_800FC660(local_0 | 0);
}
