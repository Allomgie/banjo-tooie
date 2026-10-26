#include "common.h"
#include "overlays/ba/playerstate.h"
#include "core2/anctrl.h"
#include "overlays/ba/playerstate.h"
#include "core2/anctrl.h"
extern f32 func_800F1214(f32, f32, f32);

extern s32 func_8008DE24(s32);
extern AnimCtrl *baanim_getAnimCtrlPtr();
extern f32 bastick_getZonePosition(PlayerState *);
extern s32 bastick_getZone(PlayerState *);
extern int func_8009CA70(void *param_0, int param_1, int param_2);
extern int bs_getPreviousState(void);
extern void _bashoes_entrypoint_15(void *param_0);
extern void bastick_setZoneMax(void *param_0, int param_1, int param_2);
extern void func_800A0CF4(void *param_0, int param_1);
extern void func_800A0CE8(void *param_0, int param_1);
extern void func_8009BFE4(PlayerState *, f32, f32);
extern void baroll_setAngularVelocity(void *param_0, int param_1, int param_2);
extern void baflag_set(void *param_0, int param_1);
extern void func_80094F14(void *param_0, int param_1, int param_2, f32 param_3);
extern void func_800931AC(void *param_0, int param_1);
extern void func_8009E4AC(void *param_0);
extern s32 bs_getNextState();
extern void func_8009BF5C(PlayerState *, f32);
extern void baroll_setIdeal(PlayerState *, f32);
extern void bastatetimer_set(PlayerState *, s32, f32);
extern f32 anctrl_getAnimTimer(AnimCtrl *);
extern s32 D_80802E50_bsbtrot[];
extern s32 D_80802E60_bsbtrot[];
extern void baanim_playForDuration_onceSmooth(PlayerState *, s32, f32);
extern void baanim_playForDuration_loopSmooth(PlayerState *, s32, f32);
extern void func_8009FFD8(PlayerState *, s32, s32, s32, s32);
extern s32 D_80802E70_bsbtrot[];
extern void yaw_setUpdateType(PlayerState *, s32);
extern void func_8009D2D8(PlayerState *, s32);
extern void baphysics_set_type(PlayerState *, s32);
extern f32 bastick_distance(PlayerState *);
extern f32 bastick_getAngleRelativeToBanjo(PlayerState *);
extern void yaw_setIdeal(PlayerState *, f32);
extern f32 yaw_getIdeal(PlayerState *);
extern void baphysics_set_target_yaw(PlayerState *, f32);
extern f32 baphysics_get_target_horizontal_velocity(PlayerState *);
extern void baphysics_set_horizontal_velocity(PlayerState *, f32, f32);
extern void baphysics_set_vertical_velocity(PlayerState *, f32);
extern void baphysics_set_gravity(PlayerState *, f32);
extern void func_8009DE38(PlayerState *, s32, f32);
extern s32 D_80802E80_bsbtrot[];
extern void func_8008CA4C(s32, s32);
extern s32 D_80802E90_bsbtrot[];
extern f32 func_800D8FF8(void);
extern f32 func_800F0E00(f32, f32);
extern f32 func_8009BFD8(PlayerState *);
extern f32 func_800F10B4(f32, f32, f32, f32, f32);
extern void func_800963C0(PlayerState *, f32 *);
extern void func_800F1EA4(f32 *, f32 *);
extern s32 D_80802EA0_bsbtrot[];
extern s32 D_80802EB0_bsbtrot[];
extern s32 D_80802EC0_bsbtrot[];
extern void baanim_playForDuration_once(PlayerState *, s32, f32);
extern void func_8009D89C(PlayerState *, f32);
extern void func_8009C128(PlayerState *, f32 *);
extern void func_800A32C4(PlayerState *, f32 *);
extern void func_800F1E6C(f32 *, f32 *, f32 *);
extern f32 func_800136E4(f32);
extern f32 _bareact_entrypoint_4(PlayerState *);
extern f32 _bareact_entrypoint_3(PlayerState *);
extern f32 _bareact_entrypoint_5(PlayerState *);
extern s32 D_80802ED0_bsbtrot[];
extern s32 D_80802EE0_bsbtrot[];
extern void func_8009DEC0(PlayerState *, s32, f32, f32, s32, s32);
extern s32 D_80800538_bsbtrot;
extern s32 D_80802380_bsbtrot;
extern s32 D_80802EF0_bsbtrot[];
extern void baanim_setEndAndDuration(PlayerState *, f32, f32);
extern void baanim_setEnd(PlayerState *, f32);
extern s32 D_80802F00_bsbtrot[];
extern void func_800956B8(s32);
extern void _bashoessuck_entrypoint_4(s32);
extern s32 func_8009BCD4(s32, f32);
extern s32 func_8008E40C();
extern s32 bakey_pressed(s32, s32);
extern s32 player_inWater(s32);
extern s32 _bamovespline_entrypoint_1(s32, f32);
extern s32 _bamovespline_entrypoint_3(s32);
extern s32 _bamovespline_entrypoint_2(s32);
extern s32 _bashoes_entrypoint_2(s32);
extern void _bashoessuck_entrypoint_1(s32, s32 *);
extern s32 _badrone_entrypoint_23(s32, s32 *);
extern void bs_setState(s32, s32);
extern s32 D_80802F10_bsbtrot[];
extern s32 D_80802F20_bsbtrot[];
extern f32 func_800F13C4(f32, f32);
extern void func_800A2CE8(PlayerState *, f32, s32);
extern void func_800A2D2C(PlayerState *, f32, s32);
extern void func_8008C9F0(PlayerState *, f32, f32, f32, f32);
extern f32 func_8009BBB8(PlayerState *);
extern void func_8008CA30(PlayerState *, f32);
extern f32 baanim_getTimer(PlayerState *);
extern void func_8009BB24(PlayerState *, f32 *);
extern s32 baanim_isAt(PlayerState *, f32);
void func_808004B4_bsbtrot();
void func_808008D0_bsbtrot();
void func_80800DF4_bsbtrot();

int func_80800000_bsbtrot(s32 param_0, s32 param_1, s32 param_2, s32 param_3, s32 param_4)
{
  if (func_8008E40C(param_0))
  {
    return param_4;
  }
  if (func_8008E3E8(param_0))
  {
    return param_2;
  }
  if (func_8008E430(param_0))
  {
    return param_3;
  }
  return param_1;
}

f32 func_80800070_bsbtrot(f32 param_0[3], f32 param_1, f32 param_2, f32 param_3, f32 param_4)
{
    if (func_8008E40C())
    {
        return param_4;
    }
    if (func_8008E3E8(param_0))
    {
        return param_2;
    }
    if (func_8008E430(param_0))
    {
        return param_3;
    }
    return param_1;
}

void func_808000DC_bsbtrot(s32 param_0, s32 param_1)
{
  if (param_1 != 0) {
    func_8009DE38(param_0, 0x4433, 0.96f);
  } else {
    func_8009DE38(param_0, 0x4433, 1.04f);
  }
}

s32 func_80800120_bsbtrot(param_0) void *param_0;
{
  if (bakey_pressed(param_0, 9) != 0 && func_8008E39C(param_0) != 0) {
        _bashoes_entrypoint_6(param_0, 2);
    }
}

f32 func_80800164_bsbtrot(s32 param_0) {
    if (func_8008DE24(param_0)) {
        return 300.0f;
    }
    return func_80800070_bsbtrot(param_0, 700.0f, 1000.0f, 700.0f, 700.0f);
}

f32 func_808001B8_bsbtrot(s32 param_0) {
    func_80800070_bsbtrot(param_0, 30.0f, 80.0f, 30.0f, 30.0f);
}

f32 func_808001EC_bsbtrot(s32 param_0) {
    if (func_8008DE24(param_0)) {
        return 0.7f;
    }
    return func_80800070_bsbtrot(param_0, 0.34f, 0.29f, 0.7f, 0.53f);
}

f32 func_80800248_bsbtrot(s32 param_0) {
    if (func_8008DE24(param_0)) {
        return 0.8f;
    }
    return func_80800070_bsbtrot(param_0, 0.56f, 0.51f, 1.2f, 1.4f);
}

void func_808002A4_bsbtrot(param_0, param_1) PlayerState *param_0; s32 param_1;
{
    AnimCtrl *local_0;

    local_0 = baanim_getAnimCtrlPtr(param_0);
    if (anctrl_getIndex(local_0) != param_1) {
        anctrl_setIndex(local_0, param_1);
        anctrl_setStart(local_0, anctrl_getAnimTimer(local_0));
        anctrl_start(local_0);
    }
}

void func_80800308_bsbtrot(Actor *param_0) {
    f32 local_0[3];

    switch (func_8009E6EC()) {
    case 0x12:
        *(s32 *)((char *)param_0 + 0x164) = 1;
        return;
    case 0x8D:
        *(s32 *)((char *)param_0 + 0x164) = 1;
        func_8009E830(param_0, 2);
        return;
    case 0x58:
        if ((*(s32 *)((char *)param_0 + 0x160) == 0) && (func_8008E40C(param_0) != 0)) {
            switch (bs_getCurrentState(param_0)) {
            case 0x16:
            case 0x95:
                func_80099A7C(param_0, local_0);
                if (_bashoessuck_entrypoint_5(param_0, local_0) != 0) {
                    *(s32 *)((char *)param_0 + 0x160) = 1;
                    bs_setState(param_0, 0x17C);
                    return;
                }
                break;
            }
        }
        return;
    default:
        func_80099B94(param_0);
        break;
    }
}

s32 func_808003F0_bsbtrot(Actor *this){
  if(func_8009E6EC() == 0x8d){
        *(s32*)((char*)this + 0x164) = 1;
        func_80800308_bsbtrot(this);
    }
  else {
    func_80099B94(this);
  }
}

extern void baphysics_set_target_horizontal_velocity(Actor *a0, f32 a1);

void func_80800438_bsbtrot(PlayerState *param_0)
{
    f32 local_0;
    f32 local_3;
    f32 local_2;
    f32 local_1;

    local_0 = bastick_getZonePosition(param_0);
    if (bastick_getZone(param_0) == 0) baphysics_set_target_horizontal_velocity(param_0, 0.0f);
    else {
        local_1 = func_808001B8_bsbtrot(param_0);
        local_2 = func_80800164_bsbtrot(param_0);
        local_3 = func_800F1214(local_0, local_1, local_2);
        baphysics_set_target_horizontal_velocity(param_0, local_3);
    }
}

void func_808004B4_bsbtrot(param_0)
void *param_0;
{
    if (func_8008E3E8(param_0) && bastick_getZone(param_0) == 1
        && bastick_getZonePosition(param_0) > 0.8f) {
        func_800962B0(param_0, 1);
    } else {
        func_800962B0(param_0, 0);
    }
}

void func_80800538_bsbtrot(param_0) void *param_0;
{
    if (!func_8009CA70(param_0, bs_getPreviousState(), 0x40))
    {
        _bashoes_entrypoint_15(param_0);
        bastick_setZoneMax(param_0, 0, 0x3CF5C28F);
        bastick_setZoneMax(param_0, 1, 0x3F800000);
        func_800A0CF4(param_0, 1);
        func_800A0CE8(param_0, 1);
        func_8009BFE4(param_0, 1000.0f, 12.0f);
        baroll_setAngularVelocity(param_0, 0x447A0000, 0x41400000);
        baflag_set(param_0, 3);
        func_80094F14(param_0, 4, 1, 0.24f);
        func_800931AC(param_0, 2);
        func_8009E4AC(param_0);
        *(int *)((char *)param_0 + 0x160) = 0;
        *(int *)((char *)param_0 + 0x164) = 0;
    }
}

void func_8080061C_bsbtrot(param_0)
PlayerState *param_0;
{
    s32 local_0;

    local_0 = bs_getNextState(param_0);
    if (!func_8009CA70(param_0, local_0, 0x40)) {
        func_8009E474(param_0);
        func_800931AC(param_0, 1);
        bastick_resetZones(param_0);
        func_800A0CF4(param_0, 0);
        func_800A0CE8(param_0, 0);
        func_8009BF5C(param_0, 0.0f);
        baroll_setIdeal(param_0, 0.0f);
        baflag_clear(param_0, 3);
        if (local_0 != 0x5A) bastatetimer_set(param_0, 3, 0.0f);
        func_808004B4_bsbtrot(param_0);
        func_800962B0(param_0, 0);
        func_8008CA4C(param_0, 1);
        func_80094F14(param_0, 4, 0, 0.0f);
        _bashoes_entrypoint_14(param_0);
    }
}

s32 func_80800710_bsbtrot(u8 *param_0)
{
    if (*(s32 *)(param_0 + 0x164) != 0) {
        return 1;
    }
    if (func_8008E39C() != 0) {
        return 0;
    }
    return bakey_released(param_0, 1);
}

int func_8080075C_bsbtrot(s32 param_0, s32 param_1)
{
  if (baflag_isTrue(param_0, 0xF))
  {
    return param_1;
  }
  if (func_8008D3B0(param_0) != 0)
  {
    return 0x23;
  }
  if (func_8008E430(param_0) != 0)
  {
    return 0x9C;
  }
  if (func_8008E40C(param_0) != 0)
  {
    return 0x95;
  }
  return 8;
}

s32 func_808007E0_bsbtrot(PlayerState *param_0, s32 param_1)
{
    if (bastick_getZone(param_0) > 0) {
        param_1 = *(s32 *)((u8 *)param_0 + 0x160) ? 0x17C : 0x16;
    }
    if (bainput_should_enter_first_person(param_0)) {
        param_1 = _badrone_entrypoint_24(param_0);
    }
    if (!*(s32 *)((u8 *)param_0 + 0x160) && func_8008DD04(param_0)) {
        param_1 = 0x71;
    }
    if (func_80800710_bsbtrot(param_0)) {
        param_1 = 0x17;
    }
    if (bakey_pressed(param_0, 8)) {
        param_1 = func_8080075C_bsbtrot(param_0, param_1);
    }
    if (!*(s32 *)((u8 *)param_0 + 0x160) && func_8008DF18(param_0)) {
        param_1 = 0x45;
    }
    if (player_inWater(param_0)) {
        param_1 = 0x2D;
    }
    return param_1;
}

void func_808008D0_bsbtrot(param_0) PlayerState *param_0;
{
    void *local_0;
    f32 local_1;
    f32 local_2;
    s32 local_3;
    local_0 = baanim_getAnimCtrlPtr(param_0);
    local_3 = 1;
    local_1 = 0.7781f;
    local_2 = 0.2781f;
    switch (_bashoes_entrypoint_1(param_0)) {
    case 3: _bashoes_entrypoint_20(param_0); break;
    case 4: local_3 = 0; break;
    case 5:
        local_2 = 0.6583f;
        local_1 = 0.1783f;
        if (anctrl_isAt(local_0, 0.6583f)) _bashoes_entrypoint_19(param_0);
        if (anctrl_isAt(local_0, 0.1783f)) _bashoes_entrypoint_18(param_0);
        break;
    default:
        if (anctrl_isAt(local_0, 0.2115f) || anctrl_isAt(local_0, 0.7115f)) _badust_entrypoint_1(param_0);
        break;
    }
    if (anctrl_isAt(local_0, func_800F13C4(local_2 + 0.2f, 1.0f))) func_808000DC_bsbtrot(param_0, 1);
    if (anctrl_isAt(local_0, func_800F13C4(local_1 + 0.2f, 1.0f))) func_808000DC_bsbtrot(param_0, 0);
    if (local_3) { func_800A2CE8(param_0, local_2, 4); func_800A2CE8(param_0, local_1, 3); }
    else { func_800A2D2C(param_0, local_2, 4); func_800A2D2C(param_0, local_1, 3); }
}

void bsbtrot_entrypoint_0(s32 param_0)
{
  func_80800538_bsbtrot();
  func_808004B4_bsbtrot(param_0);
  baanim_playForDuration_once(param_0, func_80800000_bsbtrot(param_0, 0x16, 0x16, 0x29F, 0xA0), 1.0f);
  func_8009FFD8(param_0, 1, 1, 2, 2);
  baphysics_set_target_horizontal_velocity(param_0, (double) 0);
  func_8009D874(param_0);
  bainput_enable(param_0, 0, 0);
}

void bsbtrot_entrypoint_1(PlayerState *param_0)
{
    s32 local_0 = 0;
    AnimCtrl *local_1;
    local_1 = baanim_getAnimCtrlPtr(param_0);
    bainput_enable(param_0, 0, 1);
    func_8009D3A8(param_0, 1);
    if (anctrl_isStopped(local_1)) local_0 = 0x15;
    if (anctrl_getAnimTimer(local_1) > 0.5f) local_0 = func_808007E0_bsbtrot(param_0, local_0);
    bs_setState(param_0, local_0);
}

int bsbtrot_entrypoint_2(Actor *param_0)
{
  bainput_enable(param_0, 0, 1);
  func_8080061C_bsbtrot(param_0);
}

int bsbtrot_entrypoint_3(s32 param_0)
{
  return D_80802E50_bsbtrot[param_0];
}

int func_80800C20_bsbtrot(param_0) s32 param_0; {
    func_80800000_bsbtrot(param_0, 0x26, 0x26, 0x29B, 0x86);
}

int bsbtrot_entrypoint_4(Actor *param_0)
{
  extern void baphysics_set_target_horizontal_velocity(Actor *a0, f32 a1);
  s32 local_0;
  if (func_8008E430(param_0))
  {
    baanim_playForDuration_loopSmooth(param_0, 0x29B, 1.3f);
    local_0 = 2;
  }
  else
    if (func_8008E40C(param_0) != 0)
  {
    baanim_playForDuration_loopSmooth(param_0, 0x86, 1.3f);
    local_0 = 2;
  }
  else
  {
    baanim_playForDuration_loopSmooth(param_0, 0x26, 1.2f);
  }
  func_8009FFD8(param_0, 1, 1, 1, 2);
  baphysics_set_target_horizontal_velocity(param_0, (double) 0);
  func_80800538_bsbtrot(param_0);
}

void bsbtrot_entrypoint_5(s32 param_0) {
    func_808002A4_bsbtrot(param_0, func_80800C20_bsbtrot());
    func_80800120_bsbtrot(param_0);
    func_808004B4_bsbtrot(param_0);
    if (func_8008E3E8(param_0) != 0) {
        _bashoes_entrypoint_20(param_0);
    }
    func_8009D3A8(param_0, 1);
    bs_setState(param_0, func_800A02DC(param_0, func_808007E0_bsbtrot(param_0, 0)));
}

void bsbtrot_entrypoint_6()
{
    func_8080061C_bsbtrot();
}

int bsbtrot_entrypoint_7(s32 param_0)
{
  return D_80802E60_bsbtrot[param_0];
}

int func_80800DC4_bsbtrot(int arg0)
{
  func_80800000_bsbtrot(arg0, 0x15, 0x44, 0x29C, 0xA1);
}

void func_80800DF4_bsbtrot(param_0) PlayerState *param_0;
{
    f32 local_3;
    f32 local_4;
    f32 local_2;
    f32 local_1;
    f32 local_0;
    local_0 = func_808001B8_bsbtrot(param_0);
    local_1 = func_80800164_bsbtrot(param_0);
    local_2 = func_80800248_bsbtrot(param_0);
    local_3 = func_808001EC_bsbtrot(param_0);
    func_8008C9F0(param_0, local_0, local_1, local_2, local_3);
    if (func_8008E1A0(param_0)) {
        local_4 = func_8009BBB8(param_0);
        func_8008CA30(param_0, func_800F10B4(local_4, 0.0f, 1.0f, 0.6f, 0.9f));
    }
    else func_8008CA30(param_0, 1.0f);
}

void bsbtrot_entrypoint_8(PlayerState *param_0)
{
    baanim_playForDuration_loopSmooth(param_0, func_80800DC4_bsbtrot(param_0), 0.53f);
    func_8009FFD8(param_0, 2, 1, 1, 2);
    func_80800538_bsbtrot(param_0);
    func_80800DF4_bsbtrot(param_0);
}

void bsbtrot_entrypoint_9(s32 param_0) {
    s32 local_0;

    local_0 = 0;
    func_80800120_bsbtrot();
    func_80800DF4_bsbtrot(param_0);
    func_808004B4_bsbtrot(param_0);
    func_808002A4_bsbtrot(param_0, func_80800DC4_bsbtrot(param_0));
    func_8009D3A8(param_0, 1);
    func_80800438_bsbtrot(param_0);
    func_808008D0_bsbtrot(param_0);
    if ((bastick_getZone(param_0) == 0) && (func_8009BCD4(param_0, 1.0f) != 0)) {
        local_0 = 0x15;
    }
    if (func_8008DD04(param_0) != 0) {
        local_0 = 0x71;
    }
    if (func_80800710_bsbtrot(param_0) != 0) {
        local_0 = 0x17;
    }
    if (bakey_pressed(param_0, 8) != 0) {
        local_0 = func_8080075C_bsbtrot(param_0, local_0);
    }
    if (func_8008DF18(param_0) != 0) {
        local_0 = 0x45;
    }
    if (player_inWater(param_0) != 0) {
        local_0 = 0x2D;
    }
    bs_setState(param_0, func_800A02DC(param_0, local_0));
}

void bsbtrot_entrypoint_10()
{
    func_8080061C_bsbtrot();
}

int bsbtrot_entrypoint_11(s32 param_0)
{
  return D_80802E70_bsbtrot[param_0];
}

void bsbtrot_entrypoint_12(PlayerState *param_0)
{
    AnimCtrl *local_0;

    local_0 = baanim_getAnimCtrlPtr(param_0);
    anctrl_reset(local_0);
    anctrl_setIndex(local_0, 0x27);
    anctrl_setDuration(local_0, 1.4f);
    func_8008B1C8(local_0, 0.1f);
    anctrl_setStart(local_0, 0.2f);
    anctrl_setSubrange(local_0, 0.0f, 0.4002f);
    anctrl_setPlaybackType(local_0, 1);
    anctrl_start(local_0);
    func_80800538_bsbtrot(param_0);
    func_8008CA4C(param_0, 1);
    yaw_setUpdateType(param_0, 1);
    func_8009D2D8(param_0, 3);
    baphysics_set_type(param_0, 6);
    if (bastick_distance(param_0) != 0.0f) {
        yaw_setIdeal(param_0, bastick_getAngleRelativeToBanjo(param_0));
    }
    baphysics_set_target_yaw(param_0, yaw_getIdeal(param_0));
    func_80800438_bsbtrot(param_0);
    baphysics_set_horizontal_velocity(param_0, yaw_getIdeal(param_0),
        baphysics_get_target_horizontal_velocity(param_0));
    baphysics_set_vertical_velocity(param_0, 693.5f);
    baphysics_set_gravity(param_0, -1200.0f);
    func_8009DE38(param_0, 0x4432, 1.0f);
    param_0->unk15C.word = 0;
}

void bsbtrot_entrypoint_13(PlayerState *param_0)
{
    s32 local_0 = 0;
    AnimCtrl *local_1;
    f32 local_2[3];

    local_1 = baanim_getAnimCtrlPtr(param_0);
    func_808004B4_bsbtrot(param_0);
    if (func_8008E3E8(param_0)) {
        _bashoes_entrypoint_20(param_0);
    }
    if (baflag_isTrue(param_0, 0xF)) {
        func_8009B7C0(param_0);
    } else {
        func_80800438_bsbtrot(param_0);
    }
    func_8009BB24(param_0, local_2);
    if (bakey_released(param_0, 8) && local_2[1] > 0.0f) {
        baphysics_reset_gravity(param_0);
    }
    switch (param_0->unk15C.word) {
    case 0:
        if (anctrl_isStopped(local_1)) {
            anctrl_setSubrange(local_1, 0.0f, 0.4652999938f);
            anctrl_setDuration(local_1, 10.0f);
            anctrl_setPlaybackType(local_1, 1);
            param_0->unk15C.word = 1;
        }
        break;
    case 1:
        if (func_8008DF8C(param_0, 0x8C)) {
            anctrl_setSubrange(local_1, 0.0f, 0.7328000069f);
            anctrl_setDuration(local_1, 1.4f);
            anctrl_setPlaybackType(local_1, 1);
            param_0->unk15C.word = 2;
        }
        break;
    case 2:
        func_8009D3A8(param_0, 1);
        if (player_isStable(param_0)) {
            func_8009FE58(param_0);
            anctrl_setSubrange(local_1, 0.0f, 0.8798000216f);
            anctrl_setDuration(local_1, 0.9f);
            anctrl_setPlaybackType(local_1, 1);
            func_8009D2D8(param_0, 1);
            param_0->unk15C.word = 3;
            if (baphysics_get_target_horizontal_velocity(param_0) > 220.0f) {
                func_8009D658(param_0);
            }
            _badust_entrypoint_1(param_0);
        }
        break;
    case 3:
        if (baphysics_get_target_horizontal_velocity(param_0) > 220.0f) {
            func_8009D658(param_0);
        }
        func_8009D3A8(param_0, 1);
        if (anctrl_isStopped(local_1)) {
            anctrl_setSubrange(local_1, 0.0f, 0.8898000121f);
            anctrl_setDuration(local_1, 2.0f);
            anctrl_setPlaybackType(local_1, 1);
            param_0->unk15C.word = 4;
        }
        _badust_entrypoint_1(param_0);
        break;
    case 4:
        if (baphysics_get_target_horizontal_velocity(param_0) > 220.0f) {
            func_8009D658(param_0);
        }
        func_8009D3A8(param_0, 1);
        if (anctrl_isStopped(local_1)) {
            anctrl_setSubrange(local_1, 0.0f, 1.0f);
            anctrl_setDuration(local_1, 1.2f);
            anctrl_setPlaybackType(local_1, 1);
            param_0->unk15C.word = 5;
        }
        _badust_entrypoint_1(param_0);
        break;
    case 5:
        if (baphysics_get_target_horizontal_velocity(param_0) > 220.0f) {
            func_8009D658(param_0);
        }
        func_8009D3A8(param_0, 1);
        if (anctrl_isStopped(local_1)) {
            local_0 = 0x15;
        }
        break;
    }
    switch (_bashoes_entrypoint_1(param_0)) {
    case 1:
    case 2:
        if (bainput_func_80097DF4(param_0)) {
            local_0 = 0x10;
        }
        if (bainput_func_80097F08(param_0)) {
            local_0 = 0x11;
        }
        break;
    }
    if (player_inWater(param_0)) {
        local_0 = 0x4C;
    }
    if (player_isStable(param_0)) {
        if (bakey_pressed(param_0, 8)) {
            local_0 = func_8080075C_bsbtrot(param_0, local_0);
        }
        if (func_8008DF18(param_0)) {
            local_0 = 0x45;
        }
    }
    if (func_8008E260(param_0)) {
        local_0 = 0x3D;
    }
    bs_setState(param_0, local_0);
}

void bsbtrot_entrypoint_14(s32 arg0)
{
    baphysics_reset_gravity();
    func_8080061C_bsbtrot(arg0);
}
int bsbtrot_entrypoint_15(s32 param_0)
{
  return D_80802E80_bsbtrot[param_0];
}

void func_8080163C_bsbtrot(Actor *param_0)
{
    int tmp = func_8009E6EC();
    if (tmp == 0x1A || tmp == 0x1B || tmp == 0x29 || tmp == 0x2B) {
        return;
    }
    func_80099B94(param_0);
}

void bsbtrot_entrypoint_16(s32 param_0) {
    baanim_playForDuration_once(param_0, 7, 0.6f);
    func_8008CA4C(param_0, 1);
    baphysics_set_target_horizontal_velocity(param_0, 0.0f);
    func_800931AC(param_0, 1);
}

void bsbtrot_entrypoint_17(PlayerState *param_0)
{
    s32 local_0;

    local_0 = 0;
    if (baanim_isStopped(param_0)) {
        local_0 = 1;
    }
    if (baanim_getTimer(param_0) > 0.3f && bastick_getZone(param_0)) {
        local_0 = 2;
    }
    if (func_8008DD04(param_0)) {
        local_0 = 0x2F;
    }
    if (func_8008E124(param_0)) {
        local_0 = _badata_entrypoint_30(param_0, func_8009CC68(param_0));
    }
    bs_setState(param_0, local_0);
}

int bsbtrot_entrypoint_18(Actor *param_0)
{
  if (func_8009CA70(param_0, bs_getNextState() | 0, 0x40))
  {
    func_800931AC(param_0, 2);
  }
  func_8080061C_bsbtrot(param_0);
}

int bsbtrot_entrypoint_19(s32 param_0)
{
  return D_80802E90_bsbtrot[param_0];
}

void bsbtrot_entrypoint_20(PlayerState *param_0)
{
    AnimCtrl *local_0;
    local_0 = baanim_getAnimCtrlPtr(param_0);
    anctrl_reset(local_0);
    anctrl_setIndex(local_0, 0x27);
    anctrl_setStart(local_0, 0.069f);
    anctrl_setPlaybackType(local_0, 3);
    anctrl_start(local_0);
    func_80800538_bsbtrot(param_0);
    func_8009FFD8(param_0, 1, 1, 3, 3);
    baphysics_set_target_yaw(param_0, yaw_getIdeal(param_0));
    baphysics_set_horizontal_velocity(param_0, yaw_getIdeal(param_0), baphysics_get_target_horizontal_velocity(param_0));
    func_800A0CF4(param_0, 1);
    func_800A0CE8(param_0, 1);
    func_8009BFE4(param_0, 1000.0f, 12.0f);
    baroll_setAngularVelocity(param_0, 0x447A0000, 0x41400000);
    baphysics_set_target_horizontal_velocity(param_0, 0.0f);
    func_8009D658(param_0);
    param_0->unk16C = 1.0f;
}

void bsbtrot_entrypoint_21(PlayerState *param_0)
{
    s32 local_0 = 0;
    f32 local_1[3];
    f32 local_2;

    func_808004B4_bsbtrot();
    if (func_8008E3E8(param_0)) _bashoes_entrypoint_20(param_0);
    func_8009D658(param_0);
    *(f32 *)((u8 *)param_0 + 0x16C) = func_800F0E00(*(f32 *)((u8 *)param_0 + 0x16C) - func_800D8FF8(), 0.0f);
    if (func_8008DF18(param_0)) {
        func_800963C0(param_0, local_1);
        func_800F1EA4(local_1, &local_2);
        func_8009D3A8(param_0, 1);
        baphysics_set_target_horizontal_velocity(param_0, func_800F10B4(func_8009BFD8(param_0), 20.0f, 60.0f, 550.0f, 700.0f));
        baphysics_set_target_yaw(param_0, local_2);
        _badust_entrypoint_1(param_0);
    } else {
        local_0 = 0x15;
    }
    if (player_inWater(param_0)) local_0 = 0x2D;
    if (*(f32 *)((u8 *)param_0 + 0x16C) == 0.0f && bakey_pressed(param_0, 8) && player_isStable(param_0)) local_0 = func_8080075C_bsbtrot(param_0, local_0);
    bs_setState(param_0, local_0);
}

void bsbtrot_entrypoint_22()
{
    func_8080061C_bsbtrot();
}

int bsbtrot_entrypoint_23(s32 param_0)
{
  return D_80802EA0_bsbtrot[param_0];
}

void bsbtrot_entrypoint_24(PlayerState *param_0)
{
    AnimCtrl *local_0;
    f32 local_2;
    f32 local_1;

    local_0 = baanim_getAnimCtrlPtr(param_0);
    anctrl_reset(local_0);
    anctrl_setIndex(local_0, 0x27);
    anctrl_setDuration(local_0, 1.4f);
    anctrl_setStart(local_0, 0.4653f);
    anctrl_setPlaybackType(local_0, 3);
    anctrl_start(local_0);
    func_80800538_bsbtrot(param_0);
    func_8009FFD8(param_0, 1, 1, 3, 6);
    baphysics_set_target_yaw(param_0, yaw_getIdeal(param_0));
    func_80800438_bsbtrot(param_0);
    local_1 = yaw_getIdeal(param_0);
    local_2 = baphysics_get_target_horizontal_velocity(param_0);
    baphysics_set_horizontal_velocity(param_0, local_1, local_2);
    param_0->unk15C.word = 0;
}

void bsbtrot_entrypoint_25(PlayerState *param_0)
{
    s32 local_0;
    AnimCtrl *local_1;
    f32 local_2[3];

    local_0 = 0;
    local_1 = baanim_getAnimCtrlPtr(param_0);
    func_808004B4_bsbtrot(param_0);
    if (func_8008E3E8(param_0)) {
        _bashoes_entrypoint_20(param_0);
    }
    if (baflag_isTrue(param_0, 0xF)) {
        func_8009B7C0(param_0);
    } else {
        func_80800438_bsbtrot(param_0);
    }
    func_8009BB24(param_0, local_2);
    switch (param_0->unk15C.word) {
    case 0:
        if (func_8008DF8C(param_0, 0x8C)) {
            anctrl_setSubrange(local_1, 0.0f, 0.7328f);
            anctrl_setDuration(local_1, 1.4f);
            anctrl_setPlaybackType(local_1, 1);
            param_0->unk15C.word = 1;
        }
        break;
    case 1:
        func_8009D3A8(param_0, 1);
        if (player_isStable(param_0)) {
            func_8009FE58(param_0);
            anctrl_setSubrange(local_1, 0.0f, 0.8798f);
            anctrl_setDuration(local_1, 0.9f);
            anctrl_setPlaybackType(local_1, 1);
            func_8009D2D8(param_0, 1);
            if (baphysics_get_target_horizontal_velocity(param_0) > 220.0f) {
                func_8009D658(param_0);
            }
            _badust_entrypoint_1(param_0);
            param_0->unk15C.word = 2;
        }
        break;
    case 2:
        if (baphysics_get_target_horizontal_velocity(param_0) > 220.0f) {
            func_8009D658(param_0);
        }
        func_8009D3A8(param_0, 1);
        if (anctrl_isStopped(local_1)) {
            anctrl_setSubrange(local_1, 0.0f, 0.8898f);
            anctrl_setDuration(local_1, 2.0f);
            anctrl_setPlaybackType(local_1, 1);
            param_0->unk15C.word = 3;
        }
        _badust_entrypoint_1(param_0);
        break;
    case 3:
        if (baphysics_get_target_horizontal_velocity(param_0) > 220.0f) {
            func_8009D658(param_0);
        }
        func_8009D3A8(param_0, 1);
        if (anctrl_isStopped(local_1)) {
            anctrl_setSubrange(local_1, 0.0f, 1.0f);
            anctrl_setDuration(local_1, 1.2f);
            anctrl_setPlaybackType(local_1, 1);
            param_0->unk15C.word = 4;
        }
        _badust_entrypoint_1(param_0);
        break;
    case 4:
        if (baphysics_get_target_horizontal_velocity(param_0) > 220.0f) {
            func_8009D658(param_0);
        }
        func_8009D3A8(param_0, 1);
        if (anctrl_isStopped(local_1)) {
            local_0 = 0x15;
        }
        break;
    }
    if (player_inWater(param_0)) {
        local_0 = 0x4C;
    }
    if (player_isStable(param_0)) {
        if (bakey_pressed(param_0, 8)) {
            local_0 = func_8080075C_bsbtrot(param_0, local_0);
        }
        if (func_8008DF18(param_0)) {
            local_0 = 0x45;
        }
    }
    if (func_8008E260(param_0)) {
        local_0 = 0x3D;
    }
    bs_setState(param_0, local_0);
}

void bsbtrot_entrypoint_26()
{
    func_8080061C_bsbtrot();
}

int bsbtrot_entrypoint_27(s32 param_0)
{
  return D_80802EB0_bsbtrot[param_0];
}

void bsbtrot_entrypoint_28(s32 arg0)
{
    _bsrest_entrypoint_14();
    func_8080061C_bsbtrot(arg0);
}
void bsbtrot_entrypoint_29(s32 param_0) {
    func_80800538_bsbtrot();
    _bsrest_entrypoint_18(param_0);
    if (func_8008E430(param_0) != 0) {
        baanim_playForDuration_loopSmooth(param_0, 0x29B, 1.3f);
    } else if (func_8008E40C(param_0) != 0) {
        baanim_playForDuration_loopSmooth(param_0, 0x86, 1.3f);
    } else {
        baanim_playForDuration_loopSmooth(param_0, 0x26, 1.2f);
    }
    func_800931AC(param_0, 2);
}

void bsbtrot_entrypoint_30(u8 *param_0) {
    s32 local_0;

    local_0 = 0;
    func_808004B4_bsbtrot();
    func_8009D3A8(param_0, 1);
    if ((*(s32 *)((s8 *)(param_0) + (0x164))) != 0) {
        local_0 = 0x17;
    } else if (_bsrest_entrypoint_20(param_0) != 0) {
        local_0 = _bsrest_entrypoint_13(param_0);
    }
    bs_setState(param_0, local_0);
}

int bsbtrot_entrypoint_31(s32 param_0)
{
  return D_80802EC0_bsbtrot[param_0];
}

void bsbtrot_entrypoint_32(PlayerState *param_0)
{
    f32 local_0;
    f32 local_1[3];
    f32 local_2[3];
    func_80800538_bsbtrot();
    _bareact_entrypoint_1(param_0, func_80099A58(param_0));
    baanim_playForDuration_once(param_0, 0x66, 1.1f);
    func_8009D89C(param_0, 1.0f);
    func_8009C128(param_0, local_1);
    func_800A32C4(param_0, local_2);
    func_800F1E6C(local_2, local_1, &local_0);
    yaw_setIdeal(param_0, func_800136E4(local_0 + 180.0f));
    yaw_applyIdeal(param_0);
    baphysics_set_target_horizontal_velocity(param_0, _bareact_entrypoint_4(param_0));
    baphysics_set_target_yaw(param_0, local_0);
    baphysics_set_horizontal_velocity(param_0, local_0, baphysics_get_target_horizontal_velocity(param_0));
    func_8009FFD8(param_0, 1, 1, 2, 3);
    if (_bareact_entrypoint_2(param_0) == 2) baphysics_set_type(param_0, 6);
    baphysics_set_vertical_velocity(param_0, _bareact_entrypoint_3(param_0));
    baphysics_set_gravity(param_0, _bareact_entrypoint_5(param_0));
    func_8008E944(param_0);
    func_8009514C(param_0);
}

void bsbtrot_entrypoint_33(s32 param_0) {
    s32 local_0;

    local_0 = 0;
    if (_bareact_entrypoint_2() == 2) {
        func_80800438_bsbtrot(param_0);
    }
    if (baanim_isAt(param_0, 0.3f) != 0) {
        func_800951B4(param_0);
    }
    if (func_8008E260(param_0) != 0) {
        local_0 = 0x3D;
    }
    if ((player_isStable(param_0) != 0) && (baanim_isStopped(param_0) != 0)) {
        local_0 = 0x15;
    }
    if ((anctrl_isStopped(baanim_getAnimCtrlPtr(param_0)) != 0) && (player_inWater(param_0) != 0)) {
        local_0 = 0x2D;
    }
    bs_setState(param_0, local_0);
}

int bsbtrot_entrypoint_34(Actor *param_0)
{
  s32 local_0;
  long new_var;
  new_var = (s32) param_0;
  local_0 = new_var;
  func_8009BD88();
  baphysics_reset_gravity(local_0);
  func_8008E95C(local_0);
  if (local_0 == 0)
  {
  }
  func_800951B4(local_0);
  func_8080061C_bsbtrot(local_0);
}

int bsbtrot_entrypoint_35(s32 param_0)
{
  return D_80802ED0_bsbtrot[param_0];
}

void bsbtrot_entrypoint_36(s32 arg0)
{
    func_808004B4_bsbtrot();
    func_80800538_bsbtrot(arg0);
    _bsdrone_entrypoint_0(arg0);
}

void bsbtrot_entrypoint_37(s32 arg0)
{
    _bsdrone_entrypoint_1();
    func_808004B4_bsbtrot(arg0);
}
void bsbtrot_entrypoint_38(s32 arg0)
{
    _bsdrone_entrypoint_2();
    func_8080061C_bsbtrot(arg0);
}
int bsbtrot_entrypoint_39(s32 param_0)
{
  return D_80802EE0_bsbtrot[param_0];
}

void func_80802380_bsbtrot(PlayerState *param_0, s32 param_1)
{
    switch (param_1) {
    case 0:
        baphysics_reset_gravity(param_0);
        break;
    case 1:
        baanim_playForDuration_onceSmooth(param_0, 0x298, 1.9f);
        func_8009FFD8(param_0, 1, 1, 3, 6);
        baphysics_set_target_horizontal_velocity(param_0, 0.0f);
        baphysics_set_gravity(param_0, -2700.0f);
        break;
    case 2:
        _bashoes_entrypoint_17(param_0);
        baphysics_set_type(param_0, 6);
        baphysics_set_vertical_velocity(param_0, 2383.0f);
        func_8009DEC0(param_0, 0x4598, 0.95f, 1.05f, 0x7FFF, 0x7FFF);
        break;
    }
    param_0->unk15C.word = param_1;
}

int bsbtrot_entrypoint_40(Actor *param_0)
{
  func_80802380_bsbtrot(param_0, 0);
  _bashoes_entrypoint_6(param_0, 2);
  _bashoes_entrypoint_5(param_0, 0);
  func_8080061C_bsbtrot(param_0);
}

int bsbtrot_entrypoint_41(Actor *param_0)
{
  func_80800538_bsbtrot();
  _bashoes_entrypoint_5(param_0, 1);
  *(s32*)((char*)param_0 + 0x15c) = 0;
  func_80802380_bsbtrot(param_0, 1);
}

void bsbtrot_entrypoint_42(PlayerState *param_0)
{
    s32 local_0;
    s32 local_1;

    local_0 = 0;
    local_1 = param_0->unk15C.word;
    switch (local_1) {
    case 1:
        if (baanim_isAt(param_0, 0.4744f)) func_80802380_bsbtrot(param_0, 2);
        break;
    case 2:
        if (baanim_getTimer(param_0) < 0.87f) _bashoes_entrypoint_16(param_0);
        func_80800438_bsbtrot(param_0);
        if (baanim_isStopped(param_0)) local_0 = 0x2F;
        break;
    }
    bs_setState(param_0, local_0);
}

int bsbtrot_entrypoint_43(s32 param_0)
{
  return D_80802EF0_bsbtrot[param_0];
}

void func_808025D8_bsbtrot(PlayerState *param_0, s32 param_1)
{
    AnimCtrl *local_0;

    local_0 = baanim_getAnimCtrlPtr(param_0);
    switch (param_1) {
    case 1:
        anctrl_reset(local_0);
        anctrl_setIndex(local_0, 0x11F);
        anctrl_setDuration(local_0, 0.9f);
        func_8008B1C8(local_0, 0.1f);
        anctrl_setStart(local_0, 0.1734f);
        anctrl_setSubrange(local_0, 0.0f, 0.4f);
        anctrl_setPlaybackType(local_0, 1);
        anctrl_start(local_0);
        func_8009FFD8(param_0, 1, 1, 3, 6);
        if (bastick_distance(param_0) != 0.0f) {
            yaw_setIdeal(param_0, bastick_getAngleRelativeToBanjo(param_0));
        }
        baphysics_set_target_yaw(param_0, yaw_getIdeal(param_0));
        func_80800438_bsbtrot(param_0);
        baphysics_set_horizontal_velocity(param_0, (yaw_getIdeal(param_0)), baphysics_get_target_horizontal_velocity(param_0));
        baphysics_set_vertical_velocity(param_0, 693.0f);
        baphysics_set_gravity(param_0, -1200.0f);
        func_8009DE38(param_0, 0x4432, 1.0f);
        break;
    case 2:
        baanim_setEndAndDuration(param_0, 0.6f, 4.0f);
        break;
    case 3:
        baanim_setEndAndDuration(param_0, 0.7734f, 0.9f);
        break;
    case 4:
        func_8009FE58(param_0);
        baanim_setEnd(param_0, 1.0f);
        break;
    }
    param_0->unk15C.word = param_1;
}

void bsbtrot_entrypoint_44(s32 arg0)
{
    baphysics_reset_gravity();
    func_8080061C_bsbtrot(arg0);
}
void bsbtrot_entrypoint_45(s32 param_0) {
    func_80800538_bsbtrot(param_0);
    *(s32 *)(param_0 + 0x15C) = 0;
    func_808025D8_bsbtrot(param_0, 1);
}

void bsbtrot_entrypoint_46(Actor *param_0)
{
    s32 local_0;
    s32 local_2;
    f32 local_1[3];

    local_0 = 0;
    local_2 = baanim_getAnimCtrlPtr();
    func_808004B4_bsbtrot(param_0);
    if (baflag_isTrue(param_0, 0xF) != 0) {
        func_8009B7C0(param_0);
    } else {
        func_80800438_bsbtrot(param_0);
    }
    func_8009BB24(param_0, local_1);
    if ((bakey_released(param_0, 8) != 0) && (local_1[1] > 0.0f)) {
        baphysics_reset_gravity(param_0);
    }
    switch (*(s32 *)((s8 *)(param_0) + (0x15C))) {                              
    case 1:
        if (anctrl_isStopped(local_2) != 0) {
            func_808025D8_bsbtrot(param_0, 2);
        }
        break;
    case 2:
        if (func_8008DF8C(param_0, 0x82) != 0) {
            func_808025D8_bsbtrot(param_0, 3);
        }
        break;
    case 3:
        func_8009D3A8(param_0, 1);
        if (player_isStable(param_0) != 0) {
            func_808025D8_bsbtrot(param_0, 4);
        }
        break;
    case 4:
        if (anctrl_isStopped(local_2) != 0) {
            local_0 = 0x15;
        }
        local_0 = func_808007E0_bsbtrot(param_0, local_0);
        break;
    }
    if (player_isStable(param_0) == 0) {
        if (func_8008E260(param_0) != 0) {
            local_0 = 0x3D;
        }
        if (player_inWater(param_0) != 0) {
            local_0 = 0x4C;
        }
    }
    bs_setState(param_0, local_0);
}

int bsbtrot_entrypoint_47(s32 param_0)
{
  return D_80802F00_bsbtrot[param_0];
}

int func_808029D8_bsbtrot(Actor *param_0)
{
  extern s32 D_808029D8_unk160; // placeholder — but actually, based on mem info, it's at offset 0x160 in Actor
  // So we need to define the struct or cast appropriately.
  // Since the env shows mem[0].base == "s0" and field at off 0x160, and param_0 is passed in a0 (s0),
  // we assume Actor struct has an array or struct member at offset 0x160.
  // Without full struct, safest is to use pointer arithmetic or assume it's an s32 field.
  // But compiler needs struct definition. Since not provided, and error says 'unk160' undefined,
  // we declare extern field access via cast.

  if (!func_8009CA70(param_0, bs_getPreviousState(), 0x800))
  {
    _bashoessuck_entrypoint_3(param_0);
    *(s32*)((char*)param_0 + 0x160) = 1;
    func_80092880(param_0, 0);
    func_800A2018(param_0, 3);
    func_800A4DA4(param_0, 0x19);
  }
}

void func_80802A4C_bsbtrot(param_0) void *param_0; {
    if (func_8009CA70(param_0, bs_getNextState(), 0x800) == 0) {
        _bashoessuck_entrypoint_2(param_0);
        (*(s32 *)((s8 *)(param_0) + (0x160))) = 0;
        func_80092880(param_0, 1);
        func_800A2018(param_0, -1);
        func_800A4E30(param_0);
    }
}

void bsbtrot_entrypoint_48(Actor *param_0)
{
  s32 local_0;
  local_0 = param_0;
  func_80800538_bsbtrot();
  func_808029D8_bsbtrot(local_0);
  baanim_playForDuration_loopSmooth(local_0, func_80800DC4_bsbtrot(local_0), 0.53f);
  func_8009FFD8(local_0, 2, 1, 9, 0x12);
  func_80800DF4_bsbtrot(local_0);
}

void bsbtrot_entrypoint_49(s32 param_0)
{
    s32 local_1;
    s32 local_0[3];

    local_1 = 0;
    func_800956B8(param_0);
    func_80800120_bsbtrot(param_0);
    func_80800DF4_bsbtrot(param_0);
    func_808004B4_bsbtrot(param_0);
    func_808002A4_bsbtrot(param_0, func_80800DC4_bsbtrot(param_0));
    _bashoessuck_entrypoint_4(param_0);
    func_80800438_bsbtrot(param_0);
    func_808008D0_bsbtrot(param_0);
    if (!bastick_getZone(param_0) && func_8009BCD4(param_0, 1.0f)) {
        local_1 = 0x17B;
    }
    if (func_80800710_bsbtrot(param_0) || !func_8008E40C(param_0)) {
        local_1 = 0x17;
    }
    if (bakey_pressed(param_0, 8)) {
        local_1 = func_8080075C_bsbtrot(param_0, local_1);
    }
    if (player_inWater(param_0)) {
        local_1 = 0x2D;
    }
    if (_bamovespline_entrypoint_1(param_0, 100.0f)) {
        local_1 = 0x71;
    }
    if (_bamovespline_entrypoint_3(param_0)) {
        local_1 = 0x16;
    }
    if (_bamovespline_entrypoint_2(param_0)) {
        if (_bashoes_entrypoint_2(param_0) == 2) {
            _bashoessuck_entrypoint_1(param_0, local_0);
            local_1 = _badrone_entrypoint_23(param_0, local_0);
        } else {
            local_1 = 0x16;
        }
    }
    bs_setState(param_0, local_1);
}

void bsbtrot_entrypoint_50(s32 arg0)
{
    func_80802A4C_bsbtrot();
    func_8080061C_bsbtrot(arg0);
}
int bsbtrot_entrypoint_51(s32 param_0)
{
  return D_80802F10_bsbtrot[param_0];
}

int bsbtrot_entrypoint_52(Actor *param_0)
{
  extern void baphysics_set_target_horizontal_velocity(Actor *a0, f32 a1);
  s32 local_0;
  local_0 = param_0;
  func_80800538_bsbtrot(param_0);
  func_808029D8_bsbtrot(local_0);
  baanim_playForDuration_loopSmooth(local_0, 0x86, 1.3f);
  func_8009FFD8(local_0, 1, 1, 9, 0x12);
  baphysics_set_target_horizontal_velocity(local_0, 0);
}

int bsbtrot_entrypoint_53(Actor *param_0)
{
  s32 local_0;
  local_0 = 0;
  func_80800120_bsbtrot(param_0);
  func_808004B4_bsbtrot(param_0);
  _bashoessuck_entrypoint_4(param_0);
  if (!func_8008E40C(param_0))
  {
    local_0 = 0x17;
  }
  bs_setState(param_0, func_808007E0_bsbtrot(param_0, local_0));
}

void bsbtrot_entrypoint_54(s32 arg0)
{
    func_80802A4C_bsbtrot();
    func_8080061C_bsbtrot(arg0);
}
int bsbtrot_entrypoint_55(s32 param_0)
{
  return D_80802F20_bsbtrot[param_0];
}

/* TU-NOTE: the .data of this overlay (formerly asm/data/overlays/bs/btrot.data.s) is defined here in C --
 * tables holding function pointers must be in the same unit, otherwise IDO's assembler schedules those functions differently. */
extern void _bsbtrot_entrypoint_2();
extern void _bsbtrot_entrypoint_0();
extern void _bsbtrot_entrypoint_1();
extern int func_80099B94();
extern void _bsbtrot_entrypoint_6();
extern void _bsbtrot_entrypoint_4();
extern void _bsbtrot_entrypoint_5();
extern void _bsbtrot_entrypoint_10();
extern void _bsbtrot_entrypoint_8();
extern void _bsbtrot_entrypoint_9();
extern void _bsbtrot_entrypoint_14();
extern void _bsbtrot_entrypoint_12();
extern void _bsbtrot_entrypoint_18();
extern void _bsbtrot_entrypoint_16();
extern void _bsbtrot_entrypoint_17();
extern void _bsbtrot_entrypoint_22();
extern void _bsbtrot_entrypoint_20();
extern void _bsbtrot_entrypoint_21();
extern void _bsbtrot_entrypoint_26();
extern void _bsbtrot_entrypoint_24();
extern void _bsbtrot_entrypoint_25();
extern void _bsbtrot_entrypoint_28();
extern void _bsbtrot_entrypoint_29();
extern void _bsbtrot_entrypoint_30();
extern void _bsbtrot_entrypoint_34();
extern void _bsbtrot_entrypoint_32();
extern void _bsbtrot_entrypoint_33();
extern void _bsbtrot_entrypoint_38();
extern void _bsbtrot_entrypoint_36();
extern void _bsbtrot_entrypoint_37();
extern void _bsdrone_entrypoint_3();
extern void _bsbtrot_entrypoint_40();
extern void _bsbtrot_entrypoint_41();
extern void _bsbtrot_entrypoint_42();
extern void _bsbtrot_entrypoint_44();
extern void _bsbtrot_entrypoint_45();
extern void _bsbtrot_entrypoint_46();
extern void _bsbtrot_entrypoint_50();
extern void _bsbtrot_entrypoint_48();
extern void _bsbtrot_entrypoint_49();
extern void _bsbtrot_entrypoint_54();
extern void _bsbtrot_entrypoint_52();
extern void _bsbtrot_entrypoint_53();
s32 D_80802E50_bsbtrot[4] = { (u32)_bsbtrot_entrypoint_2, (u32)_bsbtrot_entrypoint_0, (u32)_bsbtrot_entrypoint_1, (u32)func_80099B94 };
s32 D_80802E60_bsbtrot[4] = { (u32)_bsbtrot_entrypoint_6, (u32)_bsbtrot_entrypoint_4, (u32)_bsbtrot_entrypoint_5, (u32)func_80800308_bsbtrot };
s32 D_80802E70_bsbtrot[4] = { (u32)_bsbtrot_entrypoint_10, (u32)_bsbtrot_entrypoint_8, (u32)_bsbtrot_entrypoint_9, (u32)func_80800308_bsbtrot };
/* TU-NOTE: the original source referenced the overlay's own bsbtrot_entrypoint_13 here. Rare's post-link tool turned
 * every overlay function referenced from data into an export (header export #13 = offset 0x11D8) and redirected the
 * data word to the matching core2 trampoline _bsbtrot_entrypoint_13 (0x80082C28). The local reference matters for
 * codegen: it is what makes as1 fill the delay slot after `beqz v0` in bsbtrot_entrypoint_13 the way the ROM shows.
 * The addend reproduces the tool's redirect with a standard linker. */
s32 D_80802E80_bsbtrot[4] = { (u32)_bsbtrot_entrypoint_14, (u32)_bsbtrot_entrypoint_12, (u32)bsbtrot_entrypoint_13 + (0x80082C28 - 0x808011D8), (u32)func_80099B94 };
s32 D_80802E90_bsbtrot[4] = { (u32)_bsbtrot_entrypoint_18, (u32)_bsbtrot_entrypoint_16, (u32)_bsbtrot_entrypoint_17, (u32)func_8080163C_bsbtrot };
s32 D_80802EA0_bsbtrot[4] = { (u32)_bsbtrot_entrypoint_22, (u32)_bsbtrot_entrypoint_20, (u32)_bsbtrot_entrypoint_21, (u32)func_80099B94 };
s32 D_80802EB0_bsbtrot[4] = { (u32)_bsbtrot_entrypoint_26, (u32)_bsbtrot_entrypoint_24, (u32)_bsbtrot_entrypoint_25, (u32)func_80099B94 };
s32 D_80802EC0_bsbtrot[4] = { (u32)_bsbtrot_entrypoint_28, (u32)_bsbtrot_entrypoint_29, (u32)_bsbtrot_entrypoint_30, (u32)func_808003F0_bsbtrot };
s32 D_80802ED0_bsbtrot[4] = { (u32)_bsbtrot_entrypoint_34, (u32)_bsbtrot_entrypoint_32, (u32)_bsbtrot_entrypoint_33, (u32)func_80099B94 };
s32 D_80802EE0_bsbtrot[4] = { (u32)_bsbtrot_entrypoint_38, (u32)_bsbtrot_entrypoint_36, (u32)_bsbtrot_entrypoint_37, (u32)_bsdrone_entrypoint_3 };
s32 D_80802EF0_bsbtrot[4] = { (u32)_bsbtrot_entrypoint_40, (u32)_bsbtrot_entrypoint_41, (u32)_bsbtrot_entrypoint_42, (u32)func_80099B94 };
s32 D_80802F00_bsbtrot[4] = { (u32)_bsbtrot_entrypoint_44, (u32)_bsbtrot_entrypoint_45, (u32)_bsbtrot_entrypoint_46, (u32)func_80800308_bsbtrot };
s32 D_80802F10_bsbtrot[4] = { (u32)_bsbtrot_entrypoint_50, (u32)_bsbtrot_entrypoint_48, (u32)_bsbtrot_entrypoint_49, (u32)func_80800308_bsbtrot };
s32 D_80802F20_bsbtrot[4] = { (u32)_bsbtrot_entrypoint_54, (u32)_bsbtrot_entrypoint_52, (u32)_bsbtrot_entrypoint_53, (u32)func_80800308_bsbtrot };
