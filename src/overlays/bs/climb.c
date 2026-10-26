#include "common.h"
#include "overlays/ba/playerstate.h"
#include "core2/anctrl.h"

typedef struct { s32 a; s32 b; } ClimbPair;
extern u8 D_808008C0_bsclimb[];
extern s32 func_80098634(void);
extern void func_8009DF94(s32, s32, s32, s32);
extern f32 func_800DC0C0(void);
extern f32 func_8009BB0C(PlayerState *);
extern f32 mlAbsF(f32);
extern f32 yaw_get(PlayerState *);
extern f32 yaw_getIdeal(PlayerState *);
extern AnimCtrl *baanim_getAnimCtrlPtr(PlayerState *);
extern f32 func_800D8FF8(void);
extern void func_800956B8(PlayerState *);
extern void baanim_playForDuration_onceSmooth(PlayerState *, s32, f32);
extern s32 D_808008FC_bsclimb[];
extern int baanim_isAt(PlayerState *, f32);
extern f32 baphysics_get_vertical_velocity(PlayerState *);
extern f32 func_800985B8(PlayerState *);
extern f32 func_8009864C(PlayerState *);
extern s32 D_8080090C_bsclimb[];
extern s32 D_8080091C_bsclimb[];
extern f32 bastick_getY(PlayerState *);
extern f32 func_800F1344(f32, f32, f32, f32, f32);
extern void func_8009B94C(PlayerState *, f32 *);
extern void baanim_playForDuration_loopSmooth(void *param_0, int param_1, float param_2);
extern void baanim_setDurationRange(void *param_0, float param_1, float param_2);
extern void func_8008C9F0(void *param_0, float param_1, float param_2, float param_3, float param_4);
extern void func_8008CA4C(void *param_0, int param_1);
void func_8080005C_bsclimb();

void func_80800000_bsclimb(s32 param_0, s32 param_1) {
    u8 *local_0 = D_808008C0_bsclimb + func_80098634() * 20;
    ClimbPair *local_1 = (ClimbPair *)(local_0 - 0x10);
    func_8009DF94(param_0, *(s16 *)(local_0 - 0x12), local_1[param_1].a, local_1[param_1].b);
}

void func_8080005C_bsclimb(param_0) PlayerState *param_0;
{
    f32 local_0[3];
    f32 local_1;
    f32 local_2;
    local_1 = bastick_getY(param_0);
    if (mlAbsF(local_1) < 0.03f) local_2 = 0.0f;
    else local_2 = func_800F1344(local_1, 0.03f, 1.0f, 100.0f, 300.0f);
    local_0[0] = 0.0f;
    local_0[1] = local_2;
    local_0[2] = 0.0f;
    func_8009B94C(param_0, local_0);
}

void func_808000E8_bsclimb(s32 param_0) {
    if (func_8009861C() == 2) {
        func_8009D2D8(param_0, 3);
    } else {
        func_8009D2D8(param_0, 6);
    }
    yaw_setUpdateType(param_0, 3);
    yaw_setVelocityBounded(param_0, 0x43FA0000, 0x41700000);
    bastick_setZoneMax(param_0, 0, 0x3CF5C28F);
    bastick_setZoneMax(param_0, 1, 0x3F800000);
    baphysics_set_type(param_0, 0xA);
    func_8009BC5C(param_0, 0x41200000);
    func_800961AC(param_0, 5);
    func_800959C8(param_0, 0x42A00000, 0x41200000);
    func_800A4DA4(param_0, 0xC);
    if (func_8008E0E8(param_0) != 0) {
        _bapackctrl_entrypoint_5(param_0, 4);
    }
}

int func_808001D0_bsclimb(param_0) s32 param_0;
{
  s32 local_0;
  local_0 = param_0 | 0;
  if (!func_8009E74C(local_0, 0xA))
  {
    func_800A4E30(local_0);
    bastick_resetZones(local_0);
    func_8008CA4C(local_0, 1);
    baphysics_set_type(local_0, 2);
    func_800961AC(local_0, 1);
    func_80095A40(local_0);
    if (func_8008E0E8(local_0))
    {
      _bapackctrl_entrypoint_5(local_0, 3);
    }
  }
}

void func_80800258_bsclimb(u8 *param_0, f32 param_1, f32 param_2) {
    *(f32 *)(param_0 + 0x16C) = func_800DC0C0() * param_2 + param_1;
}

int func_80800298_bsclimb(PlayerState *param_0)
{
    return mlAbsF(func_8009BB0C(param_0)) > 0.0f || yaw_get(param_0) != yaw_getIdeal(param_0);
}

void bsclimb_entrypoint_0(u8 *param_0) {
    s32 local_0;
    f32 local_1[3];
    f32 local_2[3];

    func_8008FE68(local_1);
    func_80098590(param_0, local_2);
    if (func_8009E77C(param_0, 0xA) == 0) {
        func_800F1E6C(local_1, local_2, &local_0);
        yaw_setIdeal(param_0, local_0);
        yaw_applyIdeal(param_0);
    }
    func_800C6DA0(0x40);
    baanim_playForDuration_loopSmooth(param_0, 0xB2, 2.64f);
    func_8008CA4C(param_0, 1);
    func_808000E8_bsclimb(param_0);
    (*(s32 *)((s8 *)(param_0) + (0x160))) = 1;
    func_80800258_bsclimb(param_0, 1.0f, 0.5f);
    (*(s32 *)((s8 *)(param_0) + (0x15C))) = 0;
}

void bsclimb_entrypoint_1(PlayerState *param_0)
{
    s32 local_0;
    AnimCtrl *local_1;

    local_0 = 0;
    local_1 = baanim_getAnimCtrlPtr(param_0);
    func_800956B8(param_0);
    switch (param_0->unk15C.word) {
        case 0:
            param_0->unk16C -= func_800D8FF8();
            if (param_0->unk16C <= 0.0f) {
                baanim_playForDuration_onceSmooth(param_0, 0xB1, 2.96f);
                param_0->unk15C.word = 1;
            }
            break;
        case 1:
            if (anctrl_isStopped(local_1)) {
                baanim_playForDuration_loopSmooth(param_0, 0xB2, 2.64f);
                func_80800258_bsclimb((u8 *)param_0, 3.0f, 4.0f);
                param_0->unk15C.word = 0;
            }
            break;
    }
    func_8080005C_bsclimb(param_0);
    if (func_80800298_bsclimb(param_0)) {
        local_0 = 0x50;
    }
    if (bakey_pressed(param_0, 8)) {
        local_0 = 5;
    }
    if (param_0->unk160.word == 0) {
        local_0 = 1;
    }
    param_0->unk160.word = 0;
    bs_setState(param_0, local_0);
}

void bsclimb_entrypoint_2()
{
    func_808001D0_bsclimb();
}

int bsclimb_entrypoint_3(s32 param_0)
{
  return D_808008FC_bsclimb[param_0];
}

void bsclimb_entrypoint_4(void *param_0)
{
    void *local_0 = param_0;
    baanim_playForDuration_loopSmooth(local_0, 10, 0.9);
    func_8008CA4C(local_0, 3);
    baanim_setDurationRange(local_0, 0.3, 1.5);
    func_8008C9F0(local_0, 100.0f, 300.0f, 0.6, 0.4f);
    func_808000E8_bsclimb(local_0);
}

void bsclimb_entrypoint_5(PlayerState *param_0)
{
    s32 local_0;
    f32 local_1[3];
    f32 local_2[3];

    local_0 = 0;
    func_800956B8(param_0);
    func_8080005C_bsclimb(param_0);
    if (baanim_isAt(param_0, 0.25f)) {
        func_80800000_bsclimb(param_0, 0);
    }
    if (baanim_isAt(param_0, 0.75f)) {
        func_80800000_bsclimb(param_0, 1);
    }
    if (!func_80800298_bsclimb(param_0) && baphysics_get_vertical_velocity(param_0) < 30.0f) {
        local_0 = 0x4F;
    }
    func_8009C128(param_0, local_1);
    if (func_8009BB0C(param_0) < 0.0f && func_800985B8(param_0) == local_1[1]) {
        local_0 = 1;
    }
    if (func_80098640(param_0) == 2 && func_8009BB0C(param_0) > 0.0f
        && func_8009864C(param_0) == local_1[1]) {
        if (func_800985C4(param_0, local_2)) {
            local_0 = _badrone_entrypoint_23(param_0, local_2);
        } else {
            local_0 = 0x51;
        }
    }
    if (bakey_pressed(param_0, 8)) {
        local_0 = 5;
    }
    if (!param_0->unk160.word) {
        local_0 = 1;
    }
    param_0->unk160.word = 0;
    bs_setState(param_0, local_0);
}

void bsclimb_entrypoint_6()
{
    func_808001D0_bsclimb();
}

int bsclimb_entrypoint_7(s32 param_0)
{
  return D_8080090C_bsclimb[param_0];
}

int bsclimb_entrypoint_8(Actor *param_0)
{
  baanim_playForDuration_loopSmooth(param_0, 0xB2, 2.64f);
  func_8008CA4C(param_0, 1);
  func_808000E8_bsclimb(param_0);
  baphysics_set_type(param_0, 7);
}

int bsclimb_entrypoint_9(Actor *param_0)
{
  s32 local_0;
  local_0 = 0;
  if (!func_8009CC68())
  {
    local_0 = 0x4F;
  }
  bs_setState(param_0, local_0);
}

void bsclimb_entrypoint_10()
{
    func_808001D0_bsclimb();
}

int bsclimb_entrypoint_11(s32 param_0)
{
  return D_8080091C_bsclimb[param_0];
}

void bsclimb_entrypoint_12(PlayerState *param_0)
{
    if (func_8009E6EC(param_0) == 0xC) {
        param_0->unk160.word = 1;
    } else {
        func_80099B94(param_0);
        return;
    }
    func_8009E830(param_0, 1);
    bs_setState(param_0, 0);
}
