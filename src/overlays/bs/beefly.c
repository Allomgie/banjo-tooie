#include "common.h"
#include "overlays/ba/playerstate.h"
#include "overlays/ba/playerstate.h"

extern void func_8009C128(PlayerState *, f32 *);
extern f32 func_800DC178(f32, f32);
extern s32 func_800BBCB8(f32 *, s32, f32, s32, s32 *);
extern s32 D_80800DC0_bsbeefly[];
extern s32 D_80800DE8_bsbeefly[];
extern s32 func_800B5BE4(s32);
extern s32 func_800BABB8(s32, f32 *, f32 *, f32, s32 *);
extern f32 bastick_distance(PlayerState *);
extern f32 bastick_getAngleRelativeToBanjo(PlayerState *);
extern f32 yaw_getIdeal(PlayerState *);
extern void baanim_playForDuration_once(PlayerState *, s32, f32);
extern void yaw_setIdeal(PlayerState *, f32);
extern void baphysics_set_target_horizontal_velocity(PlayerState *, f32);
extern void baphysics_set_gravity(PlayerState *, f32);
extern void baphysics_set_vertical_velocity(PlayerState *, f32);
extern f32 baphysics_get_vertical_velocity(PlayerState *);
extern void func_8009DE38(PlayerState *, s32, f32);
extern s32 anctrl_isAt(void *, f32);
extern void _bsbee_entrypoint_2();
extern s32 D_80800E18_bsbeefly[];
extern void func_80093360(PlayerState *, f32);
extern void baroll_setIdeal(PlayerState *, f32);
extern void func_8009BF5C(PlayerState *, f32);
extern int func_8009CA70(Actor *, int, int);
extern void _bafly_entrypoint_5(Actor *);
extern void _babee_entrypoint_6(Actor *);
extern void _babee_entrypoint_7(Actor *, int, int, int);
extern void yaw_setUpdateType(Actor *, int);
extern void baroll_setAngularVelocity(Actor *, int, int);
extern void _bafly_entrypoint_20(Actor *);
extern void baphysics_set_terminal_velocity(Actor *, int);
extern void _baboost_entrypoint_3(Actor *);
extern void _baboost_entrypoint_4(Actor *, int);
extern void _babuzz_entrypoint_2(Actor *);
extern void _bafpctrl_entrypoint_18(Actor *, int);
extern f32 bastick_getX(PlayerState *);
extern void _ncbafly_entrypoint_4(void *, f32, f32, f32);
extern void yaw_setVelocityBounded(PlayerState *, f32, f32);
extern f32 func_800F10B4(f32, f32, f32, f32, f32);
extern f32 _bafpctrl_entrypoint_3(PlayerState *);
extern void _baboost_entrypoint_2(PlayerState *, f32);
extern void _bsbee_entrypoint_1();
extern s32 bs_getPreviousState();
extern void baanim_playForDuration_loopSmooth(void *param_0, s32 param_1, f32 param_2);
extern void func_8009FFD8(void *param_0, s32 param_1, s32 param_2, s32 param_3, s32 param_4);
extern s32 baflag_isTrue(void *param_0, s32 param_1);
extern f32 baphysics_get_target_horizontal_velocity(void *param_0);
extern void baphysics_set_horizontal_velocity(void *param_0, f32 param_1, f32 param_2);
extern void baphysics_set_target_yaw(void *param_0, f32 param_1);
extern void func_800A4DA4(void *param_0, s32 param_1);
extern s32 D_80800E50_bsbeefly[];
extern s32 D_80800E60_bsbeefly[];
extern s32 D_80800E70_bsbeefly[];
extern s32 D_80800E80_bsbeefly[];
extern f32 D_80800E28_bsbeefly[];
extern f32 D_80800E3C_bsbeefly[];
extern f32 func_8009BFCC(PlayerState *);
extern f32 func_8009BFD8(PlayerState *);
extern f32 func_8009C150(PlayerState *);
extern f32 func_800136E4(f32);
extern void _babuzz_entrypoint_3(PlayerState *);
extern void _bafly_entrypoint_10(PlayerState *, f32, f32);
extern void _babuzz_entrypoint_4(PlayerState *, f32);
extern void _bafly_entrypoint_8(PlayerState *, f32, f32, f32, f32, f32, f32, f32);
extern void anctrl_setDuration(void *, f32);

void func_80800000_bsbeefly(PlayerState *param_0)
{
    f32 local_0[3];
    func_8009C128(param_0, local_0);
    local_0[0] += func_800DC178(-30.0f, 30.0f);
    local_0[1] += 30.0f + func_800DC178(0.0f, 30.0f);
    local_0[2] += func_800DC178(-30.0f, 30.0f);
    func_800BBCB8(local_0, 0, 1.0f, 1, D_80800DC0_bsbeefly);
}

void func_808000A4_bsbeefly(PlayerState *param_0)
{
    f32 local_1[3];
    s32 local_0;

    local_0 = func_800B5BE4(0x22);
    func_8009C128(param_0, local_1);
    local_1[1] += 45.0f;
    func_800BABB8(local_0, local_1, NULL, 1.0f, D_80800DE8_bsbeefly);
}

void func_8080010C_bsbeefly(PlayerState *param_0)
{
    _bsbee_entrypoint_1(param_0);
    baanim_playForDuration_once(param_0, 0x1DF, 1.5f);
    func_8009FFD8(param_0, 1, 1, 3, 6);
    if (bastick_distance(param_0) != 0.0f) {
        yaw_setIdeal(param_0, bastick_getAngleRelativeToBanjo(param_0));
    }
    baphysics_set_target_yaw(param_0, yaw_getIdeal(param_0));
    baphysics_set_target_horizontal_velocity(param_0, 0.0f);
    baphysics_set_gravity(param_0, -1200.0f);
    *(s32 *)((u8 *)param_0 + 0x15C) = 0;
}

void func_808001C4_bsbeefly(PlayerState *param_0)
{
    s32 local_0 = 0;
    void *local_1;

    local_1 = baanim_getAnimCtrlPtr(param_0);
    _bsbee_entrypoint_2(param_0);
    switch (*(s32 *)((u8 *)param_0 + 0x15C)) {
        case 0:
            if (anctrl_isAt(local_1, 0.266f)) {
                baphysics_set_vertical_velocity(param_0, 1600.0f);
                func_8009DE38(param_0, 0x406, 0.7f);
                *(s32 *)((u8 *)param_0 + 0x15C) = 1;
            }
            break;
        case 1:
            func_80800000_bsbeefly(param_0);
            if (anctrl_isStopped(local_1)) {
                baanim_playForDuration_loopSmooth(param_0, 0x1DC, 0.38f);
            }
            if (baphysics_get_vertical_velocity(param_0) < 0.0f) {
                local_0 = 0x8C;
            }
            break;
    }
    bs_setState(param_0, local_0);
}

void func_808002B0_bsbeefly()
{
    _bsbee_entrypoint_0();
}

int bsbeefly_entrypoint_0(s32 param_0)
{
  return D_80800E18_bsbeefly[param_0];
}

void func_808002E4_bsbeefly(param_0)
PlayerState *param_0;
{
    s32 local_0;

    local_0 = bs_getNextState(param_0);
    if (!func_8009CA70(param_0, local_0, 0x4000)) {
        func_80093360(param_0, 0.0f);
        baroll_setIdeal(param_0, 0.0f);
        func_8009BF5C(param_0, 0.0f);
        func_800A4E30(param_0);
        baphysics_reset_gravity(param_0);
        baphysics_reset_terminal_velocity(param_0);
        _baboost_entrypoint_4(param_0, 0);
        _babuzz_entrypoint_1(param_0);
        _babee_entrypoint_5(param_0);
        _bafly_entrypoint_4(param_0);
        _bafpctrl_entrypoint_18(param_0, 0);
        func_800947EC(param_0, 1, 1);
    }
}

void func_8080039C_bsbeefly(Actor *param_0)
{
  if (func_8009CA70(param_0, bs_getPreviousState(), 0x4000) == 0) {
    _bafly_entrypoint_5(param_0);
    _babee_entrypoint_6(param_0);
    _babee_entrypoint_7(param_0, 0x45BB8000, 0x3E4CCCCD, 0x463B8000);
    func_80093360(param_0, 65.0f);
    yaw_setUpdateType(param_0, 3);
    baroll_setAngularVelocity(param_0, 0x43FA0000, 0x40000000);
    _bafly_entrypoint_20(param_0);
    baphysics_set_gravity(param_0, -300.0f);
    baphysics_set_terminal_velocity(param_0, 0xC2C7CCCD);
    _baboost_entrypoint_3(param_0);
    _baboost_entrypoint_4(param_0, 1);
    _babuzz_entrypoint_2(param_0);
    _bafpctrl_entrypoint_18(param_0, 1);
  }
}

void func_80800480_bsbeefly(PlayerState *param_0)
{
    f32 local_0;
    f32 local_1;
    f32 local_2;
    f32 local_3;

    local_3 = bastick_getX(param_0);
    _ncbafly_entrypoint_4((void *)func_800A4CA8(param_0), 2.0f, 2000.0f, 350.0f);
    if (bakey_held(param_0, 3)) {
        yaw_setVelocityBounded(param_0, 500.0f, 30.0f);
        local_1 = 6.0f;
        local_2 = 85.0f;
    } else {
        yaw_setVelocityBounded(param_0, 500.0f, 2.0f);
        local_1 = 3.0f;
        local_2 = 65.0f;
    }
    baroll_setIdeal(param_0, func_800F10B4(local_3, -1.0f, 1.0f, -local_2, local_2));
    local_0 = func_800F10B4(local_3, -1.0f, 1.0f, local_1, -local_1);
    local_0 *= _bafpctrl_entrypoint_3(param_0);
    yaw_setIdeal(param_0, yaw_getIdeal(param_0) + local_0);
}

s32 func_808005B0_bsbeefly(s32 param_0)
{
  if (func_8009E6EC() == 0x18)
  {
    _baboost_entrypoint_2(param_0, 1.0f);
    func_8009E830(param_0, 2);
  }
  else
  {
    func_80099B94(param_0);
  }
}

void func_80800600_bsbeefly(void *param_0)
{
    s32 local_0;
    f32 local_2;
    f32 local_1;

    _bsbee_entrypoint_1(param_0);
    local_0 = bs_getPreviousState(param_0);
    baanim_playForDuration_loopSmooth(param_0, 0x1DC, 0.38f);
    func_8009FFD8(param_0, 1, 1, 3, 3);
    if (baflag_isTrue(param_0, 9) != 0) {
        baphysics_set_target_horizontal_velocity(param_0, 0);
    } else {
        baphysics_set_target_horizontal_velocity(param_0, 600.0);
    }
    local_1 = yaw_getIdeal(param_0);
    baphysics_set_horizontal_velocity(param_0, local_1, baphysics_get_target_horizontal_velocity(param_0));
    local_2 = yaw_getIdeal(param_0);
    baphysics_set_target_yaw(param_0, local_2);
    func_800A4DA4(param_0, 0x16);
    func_8080039C_bsbeefly(param_0);
    if (local_0 != 0x8B) {
        _baboost_entrypoint_2(param_0, 1.0f);
        *(s32 *)((char *)param_0 + 0x15C) = 0;
        return;
    }
    *(s32 *)((char *)param_0 + 0x15C) = 1;
}

void func_80800708_bsbeefly(PlayerState *param_0)
{
    s32 local_0;
    void *local_1;
    s32 local_2;
    f32 local_3;
    f32 local_4;
    f32 local_7;
    f32 local_5;
    f32 local_8;
    f32 *local_6;

    local_0 = 0;
    local_1 = baanim_getAnimCtrlPtr(param_0);
    _bsbee_entrypoint_2(param_0);
    _bafly_entrypoint_20(param_0);
    func_80800480_bsbeefly(param_0);
    _bafly_entrypoint_10(param_0, 300.0f, 80.0f);
    _bafly_entrypoint_11(param_0);
    func_8009BFCC(param_0);
    if (bakey_pressed(param_0, 8)) {
        if (func_8009C150(param_0) < 27500.0f) {
            _baboost_entrypoint_2(param_0, 1.0f);
        }
    }
    if (_baboost_entrypoint_1(param_0) == 0 && player_inWater(param_0)) {
        _baboost_entrypoint_2(param_0, 1.0f);
    }
    local_2 = _baboost_entrypoint_1(param_0);
    anctrl_setDuration(local_1, D_80800E28_bsbeefly[local_2]);
    local_6 = &D_80800E3C_bsbeefly[local_2];
    local_3 = 0.9f;
    local_3 += *local_6;
    local_4 = func_8009BFCC(param_0);
    local_5 = 0.0f;
    if (baphysics_get_vertical_velocity(param_0) < 0.0f) {
        if (local_4 < 300.0f) {
            local_5 = func_800F10B4(local_4, 0.0f, 80.0f, 0, 0.23f);
        }
        if (80.0f < local_4) {
            local_5 = func_800F10B4(local_4, 300.0f, 360.0f, -0.2f, 0);
        }
    }
    local_3 += local_5;
    if (local_2 == 0 && bakey_held(param_0, 9)) {
        local_3 += 0.12f;
    }
    _babuzz_entrypoint_4(param_0, local_3);
    _babuzz_entrypoint_3(param_0);
    switch (param_0->unk15C.word) {
    case 0:
        if (local_6 != D_80800E3C_bsbeefly) {
            param_0->unk15C.word = 1;
        }
        break;
    case 1:
        local_7 = func_800136E4(func_8009BFD8(param_0) - 30.0f);
        if (80.0f < local_7 && local_7 < 300.0f) {
            local_7 = 300.0f;
        }
        func_8009BF5C(param_0, local_7);
        _bafly_entrypoint_21(param_0);
        if (local_2 != 0) {
            baphysics_set_vertical_velocity(param_0, local_2 * 400.0f);
            func_80800000_bsbeefly(param_0);
        }
        if (local_6 == D_80800E3C_bsbeefly) {
            _bafly_entrypoint_20(param_0);
            param_0->unk15C.word = 0;
        }
        break;
    }
    if (bakey_held(param_0, 9)) {
        local_8 = -1500.0f;
        local_7 = -1800.0f;
    } else {
        local_8 = -700.0f;
        local_7 = -1000.0f;
    }
    _bafly_entrypoint_8(param_0, 300.0f, 80.0f, 600.0f, -300.0f, -99.9f, local_8, local_7);
    if (bakey_held(param_0, 9)) {
        func_808000A4_bsbeefly(param_0);
        baphysics_set_target_horizontal_velocity(param_0, baphysics_get_target_horizontal_velocity(param_0) * 3.5f);
    }
    if (bakey_held(param_0, 1)) {
        _babee_entrypoint_2(param_0);
    }
    if (_bafly_entrypoint_2(param_0) && !player_inWater(param_0)) {
        local_0 = 0x85;
    }
    _baboost_entrypoint_5(param_0);
    bs_setState(param_0, local_0);
}

void func_80800B18_bsbeefly(s32 arg0)
{
    func_808002E4_bsbeefly();
    _bsbee_entrypoint_0(arg0);
}
int bsbeefly_entrypoint_1(s32 param_0)
{
  return D_80800E50_bsbeefly[param_0];
}

s32 func_80800B54_bsbeefly(void *param_0)
{
  s32 s0;
  s0 = (s32) param_0;
  _bsbee_entrypoint_1(s0);
  func_8080039C_bsbeefly(s0);
  _bsrest_entrypoint_16(s0);
  baphysics_set_gravity(s0, 0);
  func_8009BA9C(s0, 0);
}

int func_80800BA4_bsbeefly(Actor *param_0)
{
  s32 local_0;
  local_0 = 0;
  _bsbee_entrypoint_2();
  if (_bsrest_entrypoint_20(param_0))
  {
    local_0 = 0x8C;
  }
  bs_setState(param_0, local_0);
}

void func_80800BE8_bsbeefly(s32 arg0)
{
    _bsrest_entrypoint_14();
    func_808002E4_bsbeefly(arg0);
    _bsbee_entrypoint_0(arg0);
}

int bsbeefly_entrypoint_2(s32 param_0)
{
  return D_80800E60_bsbeefly[param_0];
}

void func_80800C2C_bsbeefly(s32 arg0)
{
    _bafly_entrypoint_18();
    func_808002E4_bsbeefly(arg0);
    _bsbee_entrypoint_0(arg0);
}

int func_80800C5C_bsbeefly(Actor *param_0)
{
  _bsbee_entrypoint_1();
  func_8080039C_bsbeefly(param_0);
  _bafly_entrypoint_16(param_0, 0x1E0, 0x3F800000);
}

int func_80800C94_bsbeefly(s32 param_0)
{
  s32 local_0;
  local_0 = 0;
  _bsbee_entrypoint_2(param_0);
  _bafly_entrypoint_17(param_0, 0x8C, 0x85, &local_0);
}

int bsbeefly_entrypoint_3(s32 param_0)
{
  return D_80800E70_bsbeefly[param_0];
}

void func_80800CE0_bsbeefly(s32 arg0)
{
    _bafly_entrypoint_15();
    func_808002E4_bsbeefly(arg0);
    _bsbee_entrypoint_0(arg0);
}

int func_80800D10_bsbeefly(Actor *param_0)
{
  _bsbee_entrypoint_1();
  func_8080039C_bsbeefly(param_0);
  _bafly_entrypoint_13(param_0, 1, 0xD3, 0x3F99999A);
}

int func_80800D50_bsbeefly(Actor *param_0)
{
  extern void _bafly_entrypoint_14(Actor*, s32, s32);
  extern void _bsbee_entrypoint_2(void);
  _bsbee_entrypoint_2();
  _bafly_entrypoint_14(param_0, 0x8C, 0x85);
  return;
}

int bsbeefly_entrypoint_4(s32 param_0)
{
  return D_80800E80_bsbeefly[param_0];
}
