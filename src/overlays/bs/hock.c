#include "common.h"
#include "overlays/ba/playerstate.h"
#include "core2/anctrl.h"
#include "overlays/ba/yaw.h"
#include "overlays/ba/stick.h"

extern void *baanim_getAnimCtrlPtr();
extern void baphysics_set_target_yaw(PlayerState *, f32);
extern f32 baphysics_get_target_horizontal_velocity(PlayerState *);
extern void baphysics_set_horizontal_velocity(PlayerState *, f32, f32);
extern void func_800C3730(s32, f32, f32, f32);
extern void func_80093300(PlayerState *, f32);
extern void func_8009C1B4(PlayerState *, f32);
typedef struct { f32 local_0; f32 local_1; AnimCtrl *local_2; } ShockMotion61;
extern f32 func_80092BF4(PlayerState *);
extern s32 D_80800870_bsbshock[];
extern f32 bastick_distance(PlayerState *);
extern f32 bastick_getAngleRelativeToBanjo(PlayerState *);
extern f32 yaw_getIdeal(PlayerState *);
extern void yaw_setIdeal(PlayerState *, f32);
extern void baphysics_set_vertical_velocity(PlayerState *, f32);
extern void baphysics_set_gravity(PlayerState *, f32);
extern void func_8009DBF0(PlayerState *, s32, f32);
extern void func_8009DF58(PlayerState *, s32, f32);
extern s32 D_80800880_bsbshock[];
extern void baphysics_set_target_horizontal_velocity(PlayerState *, f32);

void bsbshock_entrypoint_0(PlayerState *param_0)
{
  ShockMotion61 local_4;
  AnimCtrl *local_2;
  s32 local_3;
  local_2 = baanim_getAnimCtrlPtr(param_0);
  local_4.local_2 = local_2;
  anctrl_reset(local_2);
  anctrl_setIndex(local_4.local_2, 0x48);
  func_8008B1C8(local_4.local_2, 0.4f);
  anctrl_setDuration(local_4.local_2, 4.2f);
  anctrl_setSubrange(local_4.local_2, 0.0f, 0.1061f);
  anctrl_setPlaybackType(local_4.local_2, 1);
  anctrl_start(local_4.local_2);
  func_8009FFD8(param_0, 1, 1, 3, 6);
  if (bastick_distance(param_0) != 0.0f)
  {
    yaw_setIdeal(param_0, bastick_getAngleRelativeToBanjo(param_0));
  }
  baphysics_set_target_yaw(param_0, yaw_getIdeal(param_0));
  _bswalk_entrypoint_1(param_0);
  local_4.local_0 = yaw_getIdeal(param_0);
  local_4.local_1 = baphysics_get_target_horizontal_velocity(param_0);
  baphysics_set_horizontal_velocity(param_0, local_4.local_0, local_4.local_1);
  func_800A0CE8(param_0, 1);
  func_800A0CF4(param_0, 1);
  func_8009D874(param_0);
  local_3 = func_800C2E04();
  *((u8 *) (((s8 *) param_0) + 0x164)) = local_3;
  func_800C3418(local_3 & 0xFF, 0);
  func_800C2E40(*((u8 *) (((s8 *) param_0) + 0x164)));
  func_800C330C(*((u8 *) (((s8 *) param_0) + 0x164)), 3);
  func_800C301C(*((u8 *) (((s8 *) param_0) + 0x164)), 0x41D);
  func_800C3730(*((u8 *) (((s8 *) param_0) + 0x164)), 1.4f, 0.4f, -1.2f);
  func_80093300(param_0, -87.0f);
  func_8009C1B4(param_0, -87.0f);
  *((s32 *) (((s8 *) param_0) + 0x15C)) = 1;
  *((s32 *) (((s8 *) param_0) + 0x160)) = 0;
}

void bsbshock_entrypoint_1(PlayerState *param_0)
{
    s32 local_0 = 0;
    AnimCtrl *local_1;
    f32 local_2[3];

    local_1 = baanim_getAnimCtrlPtr(param_0);
    if (player_isStable(param_0)) {
        if (func_8001211C() % 2) {
            func_8009FC80(param_0);
        }
    } else {
        func_8009FC80(param_0);
    }
    _bswalk_entrypoint_1(param_0);
    func_8009BB24(param_0, local_2);
    if (bakey_released(param_0, 8) && local_2[1] > 0.0f) {
        baphysics_reset_gravity(param_0);
    }
    switch (param_0->unk160.word) {
    case 0:
        if (func_8008E260(param_0)) {
            local_0 = 0x3D;
        }
        if (func_8008DF8C(param_0, 0x82)) {
            anctrl_setSubrange(local_1, 0.0f, 1.0f);
            anctrl_setDuration(local_1, 2.8f);
            anctrl_setPlaybackType(local_1, 1);
            param_0->unk160.word = 1;
        }
        break;
    case 1:
        if (anctrl_isAt(local_1, 0.11f)) {
            func_800C3BDC(((u8 *)param_0)[0x164]);
        }
        if (anctrl_isAt(local_1, 0.4036000073f)) {
            anctrl_setDuration(local_1, 1.4f);
        }
        if (anctrl_isStopped(local_1)) {
            local_0 = 1;
        }
        break;
    }
    if (func_8008DF8C(param_0, 0x3C)) {
        if (anctrl_getAnimTimer(local_1) < 0.3637000024f) {
            if (bakey_released(param_0, 8)) {
                param_0->unk15C.word = 0;
            }
        }
        if (player_isStable(param_0)) {
            baphysics_set_target_horizontal_velocity(param_0, 0.0f);
        }
    } else {
        if (bainput_func_80097DF4(param_0)) {
            local_0 = 0x10;
        }
        if (bainput_should_beak_bust(param_0)) {
            local_0 = 0xF;
        }
    }
    if (anctrl_isAt(local_1, 0.3637000024f) && param_0->unk15C.word) {
        local_0 = 0x22;
    }
    if (anctrl_isAt(local_1, 0.4652999938f)) {
        baphysics_set_vertical_velocity(param_0, 180.0f);
        func_80093300(param_0, 0);
        func_8009C1B4(param_0, 87.0f);
    }
    if (local_2[1] < 0.0f && player_inWater(param_0)) {
        local_0 = 0x4C;
    }
    bs_setState(param_0, local_0);
}

void bsbshock_entrypoint_2(PlayerState *param_0)
{
    func_800C2FDC(*((u8 *)param_0 + 0x164));
    func_800A0CE8(param_0, 0);
    func_800A0CF4(param_0, 0);
    if (func_80092BF4(param_0) != 0.0f) {
        func_80093300(param_0, 0.0f);
        func_8009C1B4(param_0, 87.0f);
    }
}

int bsbshock_entrypoint_3(s32 param_0)
{
  return D_80800870_bsbshock[param_0];
}

void bsbshock_entrypoint_4(PlayerState *param_0)
{
    AnimCtrl *local_0;
    f32 local_2;
    f32 local_1;
    f32 local_3;
    local_0 = baanim_getAnimCtrlPtr(param_0);
    anctrl_reset(local_0);
    anctrl_setSmoothTransition(local_0, 0);
    anctrl_setIndex(local_0, 0x49);
    anctrl_setDuration(local_0, 0.8f);
    anctrl_setStart(local_0, 0.6739f);
    anctrl_setSubrange(local_0, 0.0f, 1.0f);
    anctrl_setPlaybackType(local_0, 1);
    anctrl_start(local_0);
    func_8009FFD8(param_0, 1, 1, 3, 6);
    local_2 = bastick_distance(param_0);
    if (local_2 != 0.0f) {
        local_3 = bastick_getAngleRelativeToBanjo(param_0);
        yaw_setIdeal(param_0, local_3);
    }
    baphysics_set_target_yaw(param_0, yaw_getIdeal(param_0));
    _bswalk_entrypoint_1(param_0);
    local_1 = yaw_getIdeal(param_0);
    baphysics_set_horizontal_velocity(param_0, local_1, baphysics_get_target_horizontal_velocity(param_0));
    baphysics_set_vertical_velocity(param_0, 1250.0f);
    baphysics_set_gravity(param_0, -1200.0f);
    func_8009DBF0(param_0, 0x408, 1.0f);
    func_800A0CE8(param_0, 1);
    func_800A0CF4(param_0, 1);
    func_800C6DA0(0x45);
    func_80093300(param_0, -87.0f);
    func_8009C1B4(param_0, -87.0f);
    func_8009DF58(param_0, 0x43A, 1.0f);
    param_0->unk160.word = 0;
}

void bsbshock_entrypoint_5(Actor *param_0)
{
    s32 sp34;
    f32 sp28[3];
    s32 sp24;

    sp34 = 0;
    sp24 = baanim_getAnimCtrlPtr();
    _bswalk_entrypoint_1(param_0);
    func_8009BB24(param_0, sp28);
    if (anctrl_isAt(sp24, 0.7618f) != 0) {
        anctrl_setDuration(sp24, 3.0f);
    }
    if ((bakey_released(param_0, 8) != 0) && (sp28[1] > 0.0f)) {
        baphysics_reset_gravity(param_0);
    }
    if ((*(s32 *)((s8 *)param_0 + 0x160)) == 0) {
        func_8009FC80(param_0);
        if (sp28[1] < 0.0f) {
            sp34 = 0x2F;
        }
    }
    if (player_isStable(param_0) == 0) {
        if (func_8008E260(param_0) != 0) {
            sp34 = 0x3D;
        }
        if (bainput_func_80097DF4(param_0) != 0) {
            sp34 = 0x10;
        }
        if (bainput_should_beak_bust(param_0) != 0) {
            sp34 = 0xF;
        }
        if (func_8008DA24(param_0) != 0) {
            sp34 = 0xA8;
        }
    }
    bs_setState(param_0, sp34);
}

void bsbshock_entrypoint_6(s32 param_0)
{
  if (bs_getNextState() != 0x11)
  {
    baphysics_reset_gravity(param_0);
  }
  func_800A0CE8(param_0, 0);
  func_800A0CF4(param_0, 0);
  func_80093300(param_0, 0 & 0xFFFFFFFFFFFFFFFF);
  func_8009C1B4(param_0, 87.0f);
}

int bsbshock_entrypoint_7(s32 param_0)
{
  return D_80800880_bsbshock[param_0];
}
