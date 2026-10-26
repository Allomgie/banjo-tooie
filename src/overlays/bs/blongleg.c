#include "bs/blongleg.h"
#include "overlays/ba/playerstate.h"
#include "overlays/ba/playerstate.h"
#include "core2/anctrl.h"
#include "core2/anctrl.h"

extern f32 bastick_getZonePosition(PlayerState *);
extern s32 bastick_getZone(PlayerState *);
extern f32 func_800F1214(f32, f32, f32);
extern f32 bastatetimer_getPrevious(PlayerState *, s32);
extern f32 bastatetimer_get(PlayerState *, s32);
extern void _baalarm_entrypoint_3(PlayerState *, f32, f32);
extern s32 bastatetimer_isAt(PlayerState *, s32, f32);
extern void func_8009DE38(PlayerState *, s32, f32);
extern s32 func_8009E74C(PlayerState *, s32);
extern void func_8009E53C(PlayerState *, s32, f32);
extern void _baalarm_free(PlayerState *);
extern void func_8009BF5C(PlayerState *, f32);
extern void baroll_setIdeal(PlayerState *, f32);
extern void _batimer_incrementBy(PlayerState *, s32, f32);
extern AnimCtrl *baanim_getAnimCtrlPtr();
extern f32 func_800A3394(PlayerState *);
extern void bastatetimer_set(PlayerState *, s32, f32);
extern s32 D_80801470_bsblongleg[];
extern s32 D_80801480_bsblongleg[];
extern void func_8009D2F0(PlayerState *, s32, f32);
extern void func_800A2CE8(PlayerState *, f32, s32);
extern f32 baphysics_get_target_horizontal_velocity(PlayerState *);
extern s32 func_8009BCD4(PlayerState *, f32);
extern s32 D_80801490_bsblongleg[];
extern void func_8009D3A8(PlayerState *, s32);
extern s32 D_808014A0_bsblongleg[];
extern s32 D_808014B0_bsblongleg[];
extern f32 yaw_getIdeal(PlayerState *);
extern void baphysics_set_target_yaw(PlayerState *, f32);
extern void baphysics_set_horizontal_velocity(PlayerState *, f32, f32);
extern void func_8009BFE4(PlayerState *, f32, f32);
extern void baroll_setAngularVelocity(PlayerState *, f32, f32);
extern void _batimer_set(PlayerState *, s32, f32);
extern f32 func_8009BFD8(PlayerState *);
extern f32 func_800F10B4(f32, f32, f32, f32, f32);
extern void func_800F1EA4(f32 *, f32 *);
extern s32 D_808014C0_bsblongleg[];
extern s32 _bsrest_entrypoint_20(s32);
extern s32 _bsrest_entrypoint_13(s32);
extern s32 D_808014D0_bsblongleg[];
extern s32 D_808014E0_bsblongleg[];
extern void func_8008C9F0(void *, int, int, int, float);
extern f32 bastick_distance(PlayerState *);
extern f32 bastick_getAngleRelativeToBanjo(PlayerState *);
extern void yaw_setIdeal(PlayerState *, f32);
extern void baphysics_set_vertical_velocity(PlayerState *, f32);
extern void baphysics_set_gravity(PlayerState *, f32);
extern f32 func_8009C150(PlayerState *);
extern f32 func_80096364(PlayerState *);

s32 func_80800000_bsblongleg(PlayerState* arg0)
{
    return player_inWater(arg0);
}

int func_80800020_bsblongleg(Actor *param_0, s32 param_1)
{
  if (param_1 != 0)
  {
    func_8009DE38(param_0, 0x4433, 0.88f);
  }
  else
  {
    func_8009DE38(param_0, 0x4433, 0.96f);
  }
}

extern void baphysics_set_target_horizontal_velocity(Actor *a0, f32 a1);

void func_80800064_bsblongleg(PlayerState *param_0)
{
    f32 local_0;

    local_0 = bastick_getZonePosition(param_0);
    if (bastick_getZone(param_0) == 0) {
        baphysics_set_target_horizontal_velocity(param_0, 0.0f);
    } else {
        baphysics_set_target_horizontal_velocity(param_0, func_800F1214(local_0, 80.0f, 500.0f));
    }
}

extern void func_8080013C_bsblongleg();

void func_808000C8_bsblongleg(param_0) PlayerState *param_0;
{
    _baalarm_entrypoint_3(param_0, bastatetimer_getPrevious(param_0, 2), bastatetimer_get(param_0, 2));
    if (bastatetimer_isAt(param_0, 2, 0.01f)) {
        func_8009DE38(param_0, 0x3EB, 1.0f);
    }
}

extern void func_800931AC(Actor *a0, s32 a1);

void func_8080013C_bsblongleg(param_0) Actor *param_0;
{
  if (!func_8009E77C(param_0, 8))
  {
    func_8009E53C(param_0, 1, -5e+01f);
    bastick_setZoneMax(param_0, 0, 0x3CF5C28F);
    bastick_setZoneMax(param_0, 1, 0x3F800000);
    func_800A0CF4(param_0, 1);
    func_800A0CE8(param_0, 1);
    func_800A0DD0(param_0, 1);
    func_8009BFE4(param_0, 1e+03f, 12.0f);
    baroll_setAngularVelocity(param_0, 1e+03f, 12.0f);
    baflag_set(param_0, 3);
    func_800931AC(param_0, 2);
    _baalarm_new(param_0);
  }
}

void func_80800204_bsblongleg(param_0)
PlayerState *param_0;
{
    if (!func_8009E74C(param_0, 8)) {
        _baalarm_free(param_0);
        func_8009E53C(param_0, 1, 0.0f);
        bastick_resetZones(param_0);
        func_800A0CF4(param_0, 0);
        func_800A0CE8(param_0, 0);
        func_800A0DD0(param_0, 0);
        func_800931AC(param_0, 1);
        func_8009BF5C(param_0, 0.0f);
        baroll_setIdeal(param_0, 0.0f);
        bastatetimer_clear(param_0, 2);
        func_800C77DC(1);
        baflag_clear(param_0, 3);
        _batimer_incrementBy(param_0, 4, 0.5f);
        func_808000C8_bsblongleg(param_0);
    }
}

void func_808002D8_bsblongleg(PlayerState *param_0)
{
    AnimCtrl *local_0;
    local_0 = baanim_getAnimCtrlPtr(param_0);
    anctrl_reset(local_0);
    anctrl_setSmoothTransition(local_0, 0);
    anctrl_setIndex(local_0, 0x40);
    anctrl_setDuration(local_0, 1.0f);
    anctrl_setPlaybackType(local_0, 1);
    anctrl_start(local_0);
    bastatetimer_set(param_0, 2, func_800A3394(param_0));
    func_800C77DC(2);
    func_800C3BDC(param_0->unk160.bytes[0]);
    param_0->unk15C.word = 1;
}

void func_80800378_bsblongleg(u8 *param_0)
{
    void *temp_v0;

    temp_v0 = baanim_getAnimCtrlPtr();
    anctrl_reset(temp_v0);
    anctrl_setSmoothTransition(temp_v0, 0);
    anctrl_setIndex(temp_v0, 0x16);
    anctrl_setDuration(temp_v0, 0.5f);
    anctrl_setPlaybackType(temp_v0, 1);
    anctrl_start(temp_v0);
    (*(s32 *)((s8 *)param_0 + 0x15C)) = 0;
}

extern void func_800C3730(u8, f32, f32, f32);

extern void func_800C330C(u8 param_0, s32 param_1);

extern void func_800C301C(u8 param_0, s32 param_1);

extern s32 func_800C2E04();

extern void func_8009FFD8(Actor *a0, s32 a1, s32 a2, s32 a3, s32 a4);

void bsblongleg_entrypoint_0(PlayerState *param_0)
{
    param_0->unk160.bytes[0] = func_800C2E04();
    func_800C301C(param_0->unk160.bytes[0], 0x41D);
    func_800C330C(param_0->unk160.bytes[0], 3);
    func_800C3730(param_0->unk160.bytes[0], 0.8f, 1.9f, 1.2f);
    baflag_clear(param_0, 14);
    if (func_8009CA70(param_0, bs_getPreviousState(param_0), 0x40)) func_808002D8_bsblongleg(param_0);
    else func_80800378_bsblongleg(param_0);
    func_8009FFD8(param_0, 1, 1, 3, 2);
    baphysics_set_target_horizontal_velocity(param_0, 0.0f);
    func_8080013C_bsblongleg(param_0);
    func_8009D874(param_0);
}

void bsblongleg_entrypoint_1(u8 *param_0)
{
  s32 local_0;
  s32 local_1;
  s32 local_2;
  local_0 = 0;
  local_1 = baanim_getAnimCtrlPtr();
  func_808000C8_bsblongleg(param_0);
  func_8009D2F0(param_0, 1, 0.5f);
 if (0) { }
  local_2 = *((s32 *) (((s8 *) param_0) + 0x15C));
  switch (local_2)
  {
    case 0:
      if (anctrl_isStopped(local_1) != 0)
    {
 func_808002D8_bsblongleg(param_0); }
      break;

    case 1:
      if (anctrl_isStopped(local_1) != 0)
    {
      local_0 = 0x26;
      if (param_0 && param_0)
      {
      }
    }
      break;

  }

  bs_setState(param_0, local_0);
}

void bsblongleg_entrypoint_2(void *param_0)
{
    func_80800204_bsblongleg();
    func_800C2FDC(*(unsigned char *)((char *)param_0 + 0x160));
}

int bsblongleg_entrypoint_3(s32 param_0)
{
  return D_80801470_bsblongleg[param_0];
}

int bsblongleg_entrypoint_4(Actor *param_0)
{
  extern void baanim_playForDuration_loopSmooth(Actor *a0, s32 a1, f32 a2);
  extern void baphysics_set_target_horizontal_velocity(Actor *a0, f32 a1);
  extern void func_800931AC(Actor *a0, s32 a1);
  extern void func_8009FFD8(Actor *a0, s32 a1, s32 a2, s32 a3, s32 a4);
  void func_8080013C_bsblongleg();

  baanim_playForDuration_loopSmooth(param_0, 0x41, 1.0f);
  func_8009FFD8(param_0, 1, 1, 1, 2);
  baphysics_set_target_horizontal_velocity(param_0, 0.0f);
  func_800931AC(param_0, 2);
  func_8080013C_bsblongleg(param_0);
}

void bsblongleg_entrypoint_5(s32 param_0) {
    s32 local_0;

    local_0 = 0;
    func_808000C8_bsblongleg();
    func_8009D2F0(param_0, 1, 0.5f);
    if (bainput_should_enter_first_person(param_0) != 0) {
        local_0 = _badrone_entrypoint_24(param_0);
    }
    if (bakey_pressed(param_0, 9) != 0) {
        bastatetimer_clear(param_0, 2);
    }
    if (bastick_getZone(param_0) > 0) {
        local_0 = 0x27;
    }
    if (func_8008DF18(param_0) != 0) {
        local_0 = 0x55;
    }
    if ((bakey_pressed(param_0, 8) != 0) && (player_isStable(param_0) != 0)) {
        local_0 = 0x28;
    }
    if (bastatetimer_isDone(param_0, 2) != 0) {
        local_0 = 0x29;
    }
    if (func_80800000_bsblongleg(param_0) != 0) {
        local_0 = 0x4C;
    }
    bs_setState(param_0, local_0);
}

void bsblongleg_entrypoint_6()
{
    func_80800204_bsblongleg();
}

int bsblongleg_entrypoint_7(s32 param_0)
{
  return D_80801480_bsblongleg[param_0];
}

void bsblongleg_entrypoint_8(Actor *param_0)
{
    void *sp24;

    sp24 = baanim_getAnimCtrlPtr();
    anctrl_reset(sp24);
    anctrl_setIndex(sp24, 0x42);
    anctrl_setPlaybackType(sp24, 2);
    anctrl_start(sp24);
    func_8009FFD8(param_0, 2, 1, 1, 2);
    func_8008C9F0(param_0, 0x42A00000, 0x43FA0000, 0x3F800000, 0.8f);
}

void bsblongleg_entrypoint_9(PlayerState *param_0)
{
    s32 local_0;
    AnimCtrl *local_1;
    local_0 = 0;
    local_1 = baanim_getAnimCtrlPtr(param_0);
    func_808000C8_bsblongleg(param_0);
    func_8009D2F0(param_0, 1, 0.5f);
    func_800A2CE8(param_0, 0.47f, 4);
    func_800A2CE8(param_0, 0.97f, 3);
    if (anctrl_isAt(local_1, 0.7781f)) func_80800020_bsblongleg(param_0, 0);
    if (anctrl_isAt(local_1, 0.2781f)) func_80800020_bsblongleg(param_0, 1);
    func_80800064_bsblongleg(param_0);
    if (bakey_pressed(param_0, 9) && baphysics_get_target_horizontal_velocity(param_0) == 0.0f) bastatetimer_clear(param_0, 2);
    if (bastick_getZone(param_0) == 0 && func_8009BCD4(param_0, 1.0f)) local_0 = 0x26;
    if (func_8008DF18(param_0)) local_0 = 0x55;
    if (bakey_pressed(param_0, 8) && player_isStable(param_0)) local_0 = 0x28;
    if (bastatetimer_isDone(param_0, 2)) local_0 = 0x29;
    if (func_80800000_bsblongleg(param_0)) local_0 = 0x4C;
    bs_setState(param_0, local_0);
}

void bsblongleg_entrypoint_10()
{
    func_80800204_bsblongleg();
}

int bsblongleg_entrypoint_11(s32 param_0)
{
  return D_80801490_bsblongleg[param_0];
}

void func_80800994_bsblongleg(param_0) u8 *param_0; {
    s32 local_0;

    local_0 = baanim_getAnimCtrlPtr();
    anctrl_reset(local_0);
    anctrl_setSmoothTransition(local_0, 0);
    func_8008B188(local_0, 0);
    anctrl_setIndex(local_0, 0x40);
    anctrl_setDuration(local_0, 0.4f);
    anctrl_setPlaybackType(local_0, 1);
    anctrl_start(local_0);
    (*(s32 *)((s8 *)(param_0) + (0x15C))) = 0;
}

void func_80800A18_bsblongleg(PlayerState *param_0)
{
    AnimCtrl *local_0;

    local_0 = baanim_getAnimCtrlPtr(param_0);
    anctrl_reset(local_0);
    anctrl_setSmoothTransition(local_0, 0);
    anctrl_setIndex(local_0, 7);
    anctrl_setDuration(local_0, 0.3f);
    anctrl_setPlaybackType(local_0, 1);
    anctrl_start(local_0);
    param_0->unk15C.word = 1;
}

int bsblongleg_entrypoint_12(Actor *param_0)
{
    s32 local_0;
    extern void func_8008CA4C(Actor *param_0, s32 param_1);
    extern void func_8009D2D8(Actor *param_0, s32 param_1);
    extern void baphysics_set_target_horizontal_velocity(Actor *param_0, f32 param_1);
    extern s32 func_800C2E04();
    extern void func_800C301C(u8 param_0, s32 param_1);
    extern void func_800C330C(u8 param_0, s32 param_1);
    extern void func_800C3730(u8, f32, f32, f32);

    func_80800994_bsblongleg();
    func_8008CA4C(param_0, 1);
    func_8009D2D8(param_0, 2);
    baphysics_set_target_horizontal_velocity(param_0, 0);
    local_0 = func_800C2E04();
    *(u8 *)((u8 *)param_0 + 0x160) = local_0;
    func_800C301C(local_0, 0x41D);
    func_800C330C(*(u8 *)((u8 *)param_0 + 0x160), 3);
    func_800C3730(*(u8 *)((u8 *)param_0 + 0x160), 1.4f, 0.4f, -1.2f);
}

void bsblongleg_entrypoint_13(PlayerState *param_0)
{
    s32 local_1;
    AnimCtrl *local_0;

    local_1 = 0;
    local_0 = baanim_getAnimCtrlPtr(param_0);
    func_8009D3A8(param_0, 1);
    switch (param_0->unk15C.word) {
    case 0:
        if (anctrl_isAt(local_0, 0.68f)) func_800C3BDC(param_0->unk160.bytes[0]);
        if (anctrl_isStopped(local_0)) func_80800A18_bsblongleg(param_0);
        break;
    case 1:
        if (anctrl_isStopped(local_0)) local_1 = 1;
        break;
    }
    if (func_80800000_bsblongleg(param_0)) local_1 = 0x4C;
    bs_setState(param_0, local_1);
}

int bsblongleg_entrypoint_14(s32 param_0)
{
  func_800C2FDC(*(u8 *)((char *)param_0 + 0x160));
  func_80800204_bsblongleg(param_0);
}

int bsblongleg_entrypoint_15(s32 param_0)
{
  return D_808014A0_bsblongleg[param_0];
}

void bsblongleg_entrypoint_16(PlayerState *param_0)
{
    AnimCtrl *local_0 = baanim_getAnimCtrlPtr(param_0);

    *(f32 *)((u8 *)param_0 + 0x16C) = 0.14f;
    anctrl_reset(local_0);
    anctrl_setIndex(local_0, 0x3D);
    func_8008B1C8(local_0, 0.134f);
    anctrl_setDuration(local_0, 1.0f);
    anctrl_setStart(local_0, *(f32 *)((u8 *)param_0 + 0x16C));
    anctrl_setSubrange(local_0, 0.0f, 0.42f);
    anctrl_setPlaybackType(local_0, 1);
    anctrl_start(local_0);
    func_8009FFD8(param_0, 1, 1, 3, 6);
    if (bastick_distance(param_0) != 0.0f) yaw_setIdeal(param_0, bastick_getAngleRelativeToBanjo(param_0));
    baphysics_set_target_yaw(param_0, yaw_getIdeal(param_0));
    func_80800064_bsblongleg(param_0);
    baphysics_set_horizontal_velocity(param_0, yaw_getIdeal(param_0), baphysics_get_target_horizontal_velocity(param_0));
    baphysics_set_vertical_velocity(param_0, 400.0f);
    baphysics_set_gravity(param_0, -800.0f);
    func_8009DE38(param_0, 0x4432, 0.9f);
    *(s32 *)((u8 *)param_0 + 0x15C) = 0;
}

void bsblongleg_entrypoint_17(PlayerState *param_0)
{
    s32 local_0 = 0;
    AnimCtrl *local_1;
    f32 local_2[3];
    f32 local_4;
    f32 local_3;

    local_1 = baanim_getAnimCtrlPtr(param_0);
    func_808000C8_bsblongleg(param_0);
    func_80800064_bsblongleg(param_0);
    func_8009BB24(param_0, local_2);
    if (bakey_released(param_0, 8) && local_2[1] > 0.0f) {
        baphysics_reset_gravity(param_0);
    }
    local_3 = func_8009C150(param_0);
    local_4 = local_3 - func_80096364(param_0);
    switch (param_0->unk15C.word) {
    case 0:
        if (local_2[1] < 100.0f || local_4 < 10.0f) {
            anctrl_setDuration(local_1, 0.4f);
        }
        if (anctrl_isStopped(local_1)) {
            anctrl_setSubrange(local_1, 0.0f, 0.5281999707f);
            anctrl_setDuration(local_1, 4.5f);
            anctrl_setPlaybackType(local_1, 1);
            param_0->unk15C.word = 1;
        }
        break;
    case 1:
        if (anctrl_getAnimTimer(local_1) > 0.4f && local_4 < 70.0f) {
            param_0->unk16C = anctrl_getAnimTimer(local_1);
            param_0->unk170 = local_4;
            anctrl_setPlaybackType(local_1, 3);
            param_0->unk15C.word = 2;
        }
        break;
    case 2:
        func_8008B10C(local_1, func_800F10B4(local_4, param_0->unk170, 1.0f, param_0->unk16C, 0.6703f));
        func_8009D2F0(param_0, 1, 0.5f);
        if (player_isStable(param_0)) {
            func_8009FE58(param_0);
            anctrl_setSubrange(local_1, 0.0f, 1.0f);
            anctrl_setDuration(local_1, 1.3f);
            anctrl_setPlaybackType(local_1, 1);
            param_0->unk15C.word = 3;
        }
        break;
    case 3:
        func_8009D2F0(param_0, 1, 0.5f);
        if (anctrl_isStopped(local_1)) {
            local_0 = 0x26;
        }
        if (bakey_pressed(param_0, 8)) {
            local_0 = 0x28;
        }
        if (bastatetimer_isDone(param_0, 2)) {
            local_0 = 0x29;
        }
        break;
    }
    if (func_80800000_bsblongleg(param_0)) {
        local_0 = 0x4C;
    }
    bs_setState(param_0, local_0);
}

void bsblongleg_entrypoint_18(s32 arg0)
{
    baphysics_reset_gravity();
    func_80800204_bsblongleg(arg0);
}
int bsblongleg_entrypoint_19(s32 param_0)
{
  return D_808014B0_bsblongleg[param_0];
}

void bsblongleg_entrypoint_20(PlayerState *param_0)
{
    AnimCtrl *local_0;
    local_0 = baanim_getAnimCtrlPtr(param_0);
    anctrl_reset(local_0);
    anctrl_setIndex(local_0, 0x3D);
    anctrl_setPlaybackType(local_0, 3);
    anctrl_setStart(local_0, 0.0865f);
    anctrl_start(local_0);
    func_8009FFD8(param_0, 1, 1, 3, 3);
    baphysics_set_target_yaw(param_0, yaw_getIdeal(param_0));
    baphysics_set_horizontal_velocity(param_0, yaw_getIdeal(param_0), baphysics_get_target_horizontal_velocity(param_0));
    func_800A0CF4(param_0, 1);
    func_800A0CE8(param_0, 1);
    func_8009BFE4(param_0, 1000.0f, 12.0f);
    baroll_setAngularVelocity(param_0, 1000.0f, 12.0f);
    baphysics_set_target_horizontal_velocity(param_0, 0.0f);
    func_8009D658(param_0);
    _batimer_set(param_0, 0, 1.0f);
    func_8080013C_bsblongleg(param_0);
}

void bsblongleg_entrypoint_21(PlayerState *param_0)
{
    s32 local_0 = 0;
    f32 local_1[3];
    f32 local_2;
    func_808000C8_bsblongleg(param_0);
    func_8009D658(param_0);
    _batimer_decrement(param_0, 0);
    if (func_8008E148(param_0)) {
        func_800963C0(param_0, local_1);
        func_800F1EA4(local_1, &local_2);
        func_8009D2F0(param_0, 1, 0.5f);
        baphysics_set_target_horizontal_velocity(param_0, func_800F10B4(func_8009BFD8(param_0), 20.0f, 60.0f, 550.0f, 700.0f));
        baphysics_set_target_yaw(param_0, local_2);
        _badust_entrypoint_1(param_0);
    } else local_0 = 0x26;
    if (_batimer_isZero(param_0, 0) && bakey_pressed(param_0, 8)) local_0 = 0x28;
    if (func_80800000_bsblongleg(param_0)) local_0 = 0x4C;
    bs_setState(param_0, local_0);
}

void bsblongleg_entrypoint_22()
{
    func_80800204_bsblongleg();
}

int bsblongleg_entrypoint_23(s32 param_0)
{
  return D_808014C0_bsblongleg[param_0];
}

void bsblongleg_entrypoint_24(s32 arg0)
{
    _bsrest_entrypoint_14();
    func_80800204_bsblongleg(arg0);
}
void bsblongleg_entrypoint_25(s32 arg0)
{
    func_8080013C_bsblongleg();
    _bsrest_entrypoint_16(arg0);
}
void bsblongleg_entrypoint_26(s32 param_0) {
    s32 local_0 = 0;
    func_808000C8_bsblongleg(param_0);
    func_8009D3A8(param_0, 1);
    if (_bsrest_entrypoint_20(param_0)) {
        local_0 = _bsrest_entrypoint_13(param_0);
    }
    bs_setState(param_0, local_0);
}

int bsblongleg_entrypoint_27(s32 param_0)
{
  return D_808014D0_bsblongleg[param_0];
}

void bsblongleg_entrypoint_28(s32 arg0)
{
    func_8080013C_bsblongleg();
    _bsdrone_entrypoint_0(arg0);
}
int bsblongleg_entrypoint_29(Actor *param_0)
{
  func_808000C8_bsblongleg();
  _bsdrone_entrypoint_1(param_0);
  if (bastatetimer_isDone(param_0, 2))
  {
    bs_setState(param_0, 0x29);
  }
}

void bsblongleg_entrypoint_30(s32 arg0)
{
    _bsdrone_entrypoint_2();
    func_80800204_bsblongleg(arg0);
}
int bsblongleg_entrypoint_31(s32 param_0)
{
  return D_808014E0_bsblongleg[param_0];
}
