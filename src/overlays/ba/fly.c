#include "common.h"
#include "playerstate.h"
#include "core2/anctrl.h"

extern void _baeggfire_entrypoint_3(PlayerState *, f32 *, f32 *);
extern void func_800EF334(f32 *, f32);
extern void *func_800A4C48(PlayerState *);
extern f32 bastick_getX(PlayerState *);
extern void yaw_setVelocityBounded(PlayerState *, f32, f32);
extern void baroll_setIdeal(PlayerState *, f32);
extern f32 yaw_getIdeal(PlayerState *);
extern void yaw_setIdeal(PlayerState *, f32);
extern f32 _bafpctrl_entrypoint_3(PlayerState *);
extern f32 func_800F10B4(f32, f32, f32, f32, f32);
extern f32 bastick_getY(PlayerState *);
extern void func_8009BF5C(PlayerState *, f32);
extern void _suinv_entrypoint_0(s32 *, s32, s32, s32, s32);
extern void func_8009C128(PlayerState *, f32 *);
extern void func_800E1610(s32, f32, f32, f32 *);
extern void baanim_playForDuration_once(PlayerState *, s32, f32);
extern void func_800A32C4(PlayerState *, f32 *);
extern void func_800F1E6C(f32 *, f32 *, f32 *);
extern f32 func_800136E4(f32);
extern void baphysics_set_target_horizontal_velocity(PlayerState *, f32);
extern void baphysics_set_target_yaw(PlayerState *, f32);
extern f32 baphysics_get_target_horizontal_velocity(PlayerState *);
extern void baphysics_set_horizontal_velocity(PlayerState *, f32, f32);
extern void baphysics_set_vertical_velocity(PlayerState *, f32);
extern void baphysics_set_gravity(PlayerState *, f32);
extern void _ncbafly_entrypoint_4(void *, f32, f32, f32);
extern AnimCtrl *baanim_getAnimCtrlPtr(PlayerState *);
extern f32 func_8009BFCC(PlayerState *);
extern f32 yaw_get(PlayerState *);
extern void baphysics_set_terminal_velocity(PlayerState *, f32);
extern f32 mlAbsF(f32);
extern f32 func_800F1DCC(f32, f32);
extern void func_80110818(void *, f32 *);
extern void func_800C31DC(u8, f32);
extern void func_800C3058(u8, s32);
extern s32 func_800C3D78(u8);
extern void func_800C301C(u8, s32);
extern void func_800C330C(u8, s32);
extern void func_800C3BDC(u8);
extern void _bamotor_entrypoint_1(PlayerState *, f32, f32, f32);
extern void func_8009BFE4(PlayerState *, f32, f32);

s32 bafly_entrypoint_0() 
{
    return 0x10;
}

void bafly_entrypoint_1(PlayerState *param_0, f32 *param_1, s32 *param_2, f32 param_3)
{
    f32 local_0[3];
    if (baflag_isTrue(param_0, 0x30)) {
        _baeggfire_entrypoint_3(param_0, local_0, param_1);
        func_800EF334(param_1, param_3);
        func_800CA9D8(func_800A4C48(param_0), param_2);
    } else {
        func_800CA740(func_800A4C48(param_0), param_1);
        func_800EF334(param_1, param_3);
        func_800CA9D8(func_800A4C48(param_0), param_2);
    }
}

int bafly_entrypoint_2(Actor *param_0)
{
    int local_0;
    if (!player_isStable()) {
        return 0;
    }
    local_0 = func_80096628(param_0);
    if (!(local_0 << 11 >= 0)) {
        return 0;
    }
    return 1;
}

s32 bafly_entrypoint_3(s32 param_0)
{
    return ((u8 *)(*(u8 **)(param_0 + 0x8c)))[8];
}

void bafly_entrypoint_4(u8 *param_0)
{
  short local_0;
  local_0 = *((u8 *) (((s8 *) (*((u8 **) (((s8 *) param_0) + 0x8C)))) + 9));
  if (local_0 != 0)
  {
    func_800C2FDC(local_0 & 0xFF, local_0, param_0);
    *((s8 *) (((s8 *) (*((u8 **) (((s8 *) param_0) + 0x8C)))) + 9)) = 0;
  }
}

void bafly_entrypoint_5(u8 *param_0) {
    s32 local_0;

    if (_gcstatusDll_entrypoint_11() >= 2) {
        (*(u8 *)((s8 *)((*(u8 **)((s8 *)(param_0) + (0x8C)))) + (9))) = 0U;
    } else {
        (*(u8 *)((s8 *)((*(u8 **)((s8 *)(param_0) + (0x8C)))) + (9))) = func_800C2E04();
        func_800C3418((*(u8 *)((s8 *)((*(u8 **)((s8 *)(param_0) + (0x8C)))) + (9))), 0);
    }
    (*(f32 *)((s8 *)((*(u8 **)((s8 *)(param_0) + (0x8C)))) + (4))) = 1.0f;
    (*(f32 *)((s8 *)((*(u8 **)((s8 *)(param_0) + (0x8C)))) + (0))) = 0.0f;
    (*(s8 *)((s8 *)((*(u8 **)((s8 *)(param_0) + (0x8C)))) + (8))) = 0;
    local_0 = func_800EA05C();
    if ((local_0 != 0xE4) && (local_0 != 0x17B)) {
        (*(s8 *)((s8 *)((*(u8 **)((s8 *)(param_0) + (0x8C)))) + (0xE))) = 0;
        return;
    }
    (*(s8 *)((s8 *)((*(u8 **)((s8 *)(param_0) + (0x8C)))) + (0xE))) = 1;
}

void bafly_entrypoint_6(s32 param_0, f32 param_1) {
    *(f32*)(*(s32*)(param_0 + 0x8c) + 0x0) = param_1;
}

void bafly_entrypoint_7(void *arg, s32 v)
{
    ((s8 *)(*(void **)((char *)arg + 0x8C)))[8] = v;
}

void bafly_entrypoint_8(PlayerState *param_0, f32 param_1, f32 param_2, f32 param_3, f32 param_4, f32 param_5, f32 param_6, f32 param_7)
{
    f32 local_3[3];
    f32 local_0;
    f32 local_1;
    local_0 = func_8009BFCC(param_0);
    baphysics_set_gravity(param_0, param_4);
    bafly_entrypoint_6(param_0, 0.0f);
    if (baflag_isTrue(param_0, 9)) {
        baphysics_set_terminal_velocity(param_0, 0.0f);
        func_8009BA9C(param_0, 0);
        local_1 = 0.0f;
    } else if (local_0 <= param_2) {
        baphysics_set_terminal_velocity(param_0, func_800F10B4(local_0, param_2 - 20.0f, param_2, param_5, param_7));
        baphysics_set_gravity(param_0, func_800F10B4(local_0, param_2 - 20.0f, param_2, param_4, param_6));
        local_1 = func_800F10B4(local_0, param_2 - 20.0f, param_2, param_3, param_3 / 10.0f);
        bafly_entrypoint_6(param_0, func_800F10B4(local_0, param_2 - 20.0f, param_2, 0.0f, 0.35f));
    } else {
        baphysics_set_terminal_velocity(param_0, func_800F10B4(local_0, param_1, param_1 + 10.0f, -399.99f, param_5));
        local_1 = func_800F10B4(local_0, param_1, param_1 + 40.0f, 0.0f, param_3);
        bafly_entrypoint_6(param_0, func_800F10B4(local_0, param_1, param_1 + 40.0f, -0.25f, 0.0f));
    }
    func_80096394(param_0, local_3);
    if (func_8009650C(param_0) && local_3[1] > -1.0f) local_1 = 0.0f;
    baphysics_set_target_yaw(param_0, yaw_get(param_0));
    baphysics_set_target_horizontal_velocity(param_0, local_1);
}

void bafly_entrypoint_9(PlayerState *param_0)
{
    f32 local_3;
    f32 local_1;
    f32 local_2;
    f32 local_0;
    local_0 = bastick_getX(param_0);
    if (bakey_held(param_0, 3)) {
        yaw_setVelocityBounded(param_0, 500.0f, 30.0f);
        local_1 = 6.0f;
        local_2 = 85.0f;
    } else {
        yaw_setVelocityBounded(param_0, 500.0f, 2.0f);
        local_1 = 3.0f;
        local_2 = 75.0f;
    }
    baroll_setIdeal(param_0, func_800F10B4(local_0, -1.0f, 1.0f, -local_2, local_2));
    local_3 = func_800F10B4(local_0, -1.0f, 1.0f, local_1, -local_1);
    local_3 *= _bafpctrl_entrypoint_3(param_0);
    yaw_setIdeal(param_0, yaw_getIdeal(param_0) + local_3);
}

void bafly_entrypoint_10(PlayerState *param_0, f32 param_1, f32 param_2)
{
    f32 local_0;
    local_0 = bastick_getY(param_0);
    if (local_0 < 0.0f) {
        func_8009BF5C(param_0, func_800F10B4(local_0, -1.0f, 0.0f, param_1, 360.0f));
    } else {
        func_8009BF5C(param_0, func_800F10B4(local_0, 0.0f, 1.0f, 0.0f, param_2));
    }
}

void bafly_entrypoint_11(PlayerState *param_0)
{
    u8 local_3;
    f32 local_2;
    f32 local_1;
    f32 local_0[3];
    local_1 = 1.2f;
    if ((*(u8 **)((u8 *)param_0 + 0x8C))[8]) local_1 += 0.4f;
    func_80110818((void *)func_800A4CA8(param_0), local_0);
    local_2 = func_800F1DCC(local_0[1] + 180.0f, yaw_get(param_0));
    local_1 -= func_800F10B4(mlAbsF(local_2), 0.0f, 50.0f, 0.0f, 0.4f);
    local_1 += *(f32 *)*(u8 **)((u8 *)param_0 + 0x8C);
    local_2 = local_1 - *(f32 *)(*(u8 **)((u8 *)param_0 + 0x8C) + 4);
    if (mlAbsF(local_2) > 0.01f) {
        if (local_2 > 0.0f) local_2 = 0.01f;
        else local_2 = -0.01f;
    }
    *(f32 *)(*(u8 **)((u8 *)param_0 + 0x8C) + 4) += local_2;
    local_3 = (*(u8 **)((u8 *)param_0 + 0x8C))[9];
    if (local_3) {
        func_800C31DC(local_3, *(f32 *)(*(u8 **)((u8 *)param_0 + 0x8C) + 4));
        func_800C31DC(local_3, *(f32 *)(*(u8 **)((u8 *)param_0 + 0x8C) + 4));
        func_800C3058(local_3, 6000);
        if (!func_800C3D78(local_3)) {
            func_800C301C(local_3, 0x4A3);
            func_800C330C(local_3, 3);
            func_800C3BDC(local_3);
        }
    }
}

s32 bafly_entrypoint_12(u8 *param_0) {
    s32 local_0;
    if ((*(u8 **)(param_0 + 0x8C))[0xE]) {
        return 1;
    }
    _suinv_entrypoint_0(&local_0, 0, 1, 0x46, 1);
    return local_0;
}

void bafly_entrypoint_13(PlayerState *param_0, s32 param_1, s32 param_2, f32 param_3)
{
    f32 local_0[3];
    f32 local_1[3];
    f32 local_3;
    f32 local_2;
    f32 local_5;
    f32 local_4;
    f32 local_6;

    if (param_1 == 0) {
        local_3 = -2200.0f;
        local_4 = 800.0f;
    } else {
        local_3 = -1200.0f;
        local_4 = 400.0f;
    }
    func_8009C128(param_0, local_0);
    func_800E1610(2, 100.0f, 0.85f, local_0);
    baanim_playForDuration_once(param_0, param_2, param_3);
    func_8009D9D4(param_0);
    _bamotor_entrypoint_1(param_0, 1.0f, 0.5f, 0.5f);
    func_800A32C4(param_0, local_1);
    func_800F1E6C(local_1, local_0, &local_2);
    yaw_setIdeal(param_0, func_800136E4(local_2 + 180.0f));
    yaw_applyIdeal(param_0);
    baphysics_set_target_horizontal_velocity(param_0, local_4);
    baphysics_set_target_yaw(param_0, local_2);
    baphysics_set_horizontal_velocity(param_0, local_2, baphysics_get_target_horizontal_velocity(param_0));
    func_8009FFD8(param_0, 1, 1, 2, 3);
    baphysics_set_vertical_velocity(param_0, 800.0f);
    baphysics_set_gravity(param_0, local_3);
    baphysics_set_terminal_velocity(param_0, -4000.0f);
    func_800A4DA4(param_0, 3);
    _ncbafly_entrypoint_4(func_800A4CA8(param_0), 12.0f, 10000.0f, 800.0f);
    func_8008E944(param_0);
}

int bafly_entrypoint_14(Actor *param_0, s32 param_1, s32 param_2)
{
  s32 local_0 = 0;
  if (anctrl_isStopped(baanim_getAnimCtrlPtr(param_0)))
  {
    local_0 = param_1;
  }
  if (player_isStable(param_0))
  {
    local_0 = param_2;
  }
  bs_setState(param_0, local_0);
}

int bafly_entrypoint_15(Actor *param_0)
{
  func_8009BC34(param_0);
  func_8008E95C(param_0);
  func_8009BD88(param_0);
  func_800A4E30(param_0);
}

void bafly_entrypoint_16(PlayerState *param_0, s32 param_1, f32 param_2)
{
    f32 local_0;
    f32 local_1[3];
    f32 local_2[3];

    func_8009C128(param_0, local_1);
    func_800E1610(2, 100.0f, 0.85f, local_1);
    baanim_playForDuration_once(param_0, param_1, param_2);
    func_8009DA40(param_0);
    func_800A32C4(param_0, local_2);
    func_800F1E6C(local_2, local_1, &local_0);
    yaw_setIdeal(param_0, func_800136E4(local_0 + 180.0f));
    yaw_applyIdeal(param_0);
    baphysics_set_target_horizontal_velocity(param_0, 1300.0f);
    baphysics_set_target_yaw(param_0, local_0);
    baphysics_set_horizontal_velocity(param_0, local_0, baphysics_get_target_horizontal_velocity(param_0));
    func_8009FFD8(param_0, 1, 1, 2, 3);
    baphysics_set_vertical_velocity(param_0, 400.0f);
    baphysics_set_gravity(param_0, -1800.0f);
    func_8008E944(param_0);
    func_800A4DA4(param_0, 3);
    _ncbafly_entrypoint_4(func_800A4CA8(param_0), 12.0f, 10000.0f, 800.0f);
}

void bafly_entrypoint_17(PlayerState *param_0, s32 param_1, s32 param_2, s32 *param_3)
{
    s32 local_0 = 0;
    AnimCtrl *local_1;
    local_1 = baanim_getAnimCtrlPtr(param_0);
    if (player_isStable(param_0)) local_0 = param_2;
    if (anctrl_isStopped(local_1)) {
        if (func_8008DD04(param_0) || func_8009650C(param_0)) {
            *param_3 = 1;
            local_0 = param_1;
        }
    }
    bs_setState(param_0, local_0);
}

void bafly_entrypoint_18(s32 arg0)
{
    baphysics_reset_gravity();
    func_8008E95C(arg0);
}
void bafly_entrypoint_19(s32 param_0) {
    if (_bafpctrl_entrypoint_4() != 3) {
        if (baflag_isTrue(param_0, 0x2F) != 0) {
            _bafpctrl_entrypoint_14(param_0, 3);
        } else {
            _bafpctrl_entrypoint_14(param_0, 2);
        }
        _bafpctrl_entrypoint_9(param_0, 1);
        if (func_800C6E38(0x1B) == 0) {
            _bafpctrl_entrypoint_11(param_0, 4, 1);
        }
    }
}

void bafly_entrypoint_20(PlayerState *param_0)
{
    f32 local_0;
    f32 local_1;

    local_0 = _bafpctrl_entrypoint_3(param_0);
    local_1 = func_800F10B4(local_0, 0.1f, 1.0f, local_0 * local_0, 1.0f);
    func_8009BFE4(param_0, 500.0f * local_1, 1.2f);
}

void bafly_entrypoint_21(PlayerState *param_0)
{
    f32 local_0;
    f32 local_1;

    local_0 = _bafpctrl_entrypoint_3(param_0);
    local_1 = func_800F10B4(local_0, 0.1f, 1.0f, local_0 * local_0, 1.0f);
    func_8009BFE4(param_0, 1000.0f * local_1, 2.2f);
}
