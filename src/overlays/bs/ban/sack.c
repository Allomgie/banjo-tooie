#include "common.h"
#include "overlays/ba/playerstate.h"
#include "overlays/ba/playerstate.h"
#include "core2/anctrl.h"
#include "overlays/ba/anim.h"
#include "core2/physics.h"
#include "overlays/ba/yaw.h"

extern s32 bakey_pressed(PlayerState *, s32);
extern s32 bakey_released(PlayerState *, s32);
extern s32 func_8008E148(PlayerState *);
extern void func_80099B94();
extern s32 _bsdrone_entrypoint_3;
extern u8 func_80099AA8[];
extern f32 bastick_getZonePosition(PlayerState *);
extern s32 bastick_getZone(PlayerState *);
extern void baphysics_set_target_horizontal_velocity(PlayerState *, f32);
extern f32 func_800F1214(f32, f32, f32);
extern int func_8009E77C(PlayerState *, s32);
extern void func_800A0CD0(PlayerState *, s32);
extern void bastick_setZoneMax(PlayerState *, s32, f32);
extern void func_800A106C(PlayerState *, f32, f32);
extern s32 func_8008DF8C(s32, s32);
extern void func_8009D2F0(s32, s32, f32);
extern s32 D_80801E10_bsbansack[];
extern void func_8009FFD8(PlayerState *, s32, s32, s32, s32);
extern void func_8009DE38(PlayerState *, s32, f32);
extern void bainput_enable(PlayerState *, s32, s32);
extern s32 D_80801E20_bsbansack[];
extern void baphysics_set_gravity(PlayerState *, f32);
extern void baphysics_set_vertical_velocity(PlayerState *, f32);
extern s32 D_80801E30_bsbansack[];
extern f32 baphysics_get_vertical_velocity(PlayerState *);
typedef struct { s8 unk15A; s8 unk15B; } ActorLocal_BSBansack;
extern void func_8009D7A4(PlayerState *, f32, f32);
extern f32 baphysics_get_target_horizontal_velocity(PlayerState *);
extern s32 D_80801E40_bsbansack[];
typedef struct { u8 pad_0[0x15C]; s8 unk15C; u8 pad_15D[19]; f32 unk170; f32 unk174; } BansackStruct;
extern void func_800931AC(BansackStruct *, int);
extern void func_8009328C(BansackStruct *, f32);
extern f32 func_80092BE8(BansackStruct *);
extern f32 func_800F1DCC(f32, f32);
extern void _batimer_set(BansackStruct *, int, u32);
extern f32 _batimer_get(PlayerState *, s32);
extern f32 func_800D8FF8(void);
extern f32 func_800F10B4(f32, f32, f32, f32, f32);
extern f32 func_80013970(f32);
extern s32 D_80801E50_bsbansack[];
extern s32 D_80801E60_bsbansack[];
extern s32 D_80801E70_bsbansack[];
extern s32 D_80801E80_bsbansack[];
extern void func_8009DEC0(PlayerState *, s32, f32, f32, s32, s32);
extern void bs_setState();
extern s32 D_80801E90_bsbansack[];
extern s32 D_80801EA0_bsbansack[];
extern AnimCtrl *baanim_getAnimCtrlPtr();
extern void func_8009DBF0(PlayerState *, s32, f32);
extern f32 func_800964DC(PlayerState *);
extern f32 func_80096364(PlayerState *);
extern f32 func_800DC178(f32, f32);
extern f32 bastick_distance(PlayerState *);
extern f32 bastick_getAngleRelativeToBanjo(PlayerState *);
extern f32 func_8009BB5C(PlayerState *);
extern f32 yaw_getIdeal(PlayerState *);
extern void baphysics_set_target_yaw(PlayerState *, f32);
extern void baphysics_set_horizontal_velocity(PlayerState *, f32, f32);
extern void baanim_setEndAndDuration(PlayerState *, f32, f32);
extern void baroll_setIdeal(PlayerState *, f32);
extern void func_8009DB04(PlayerState *, s32, f32, s32);
extern void func_8009BF5C(PlayerState *, f32);
extern s32 player_inWater(PlayerState *);
extern s32 player_isStable(PlayerState *);
extern void func_800A2EEC(PlayerState *, s32);
extern void func_8009D2D8(PlayerState *, s32);
extern void func_800A2FCC(PlayerState *, s32);
void func_80800AF4_bsbansack();
void func_80801680_bsbansack();

s32 func_80800000_bsbansack(PlayerState *param_0, s32 param_1, s32 param_2)
{
    if (param_2 && bakey_pressed(param_0, 8)) {
        param_1 = 0x169;
    }
    if (func_8008E148(param_0)) {
        param_1 = 1;
    }
    if ((*(u8 *)((u8 *)param_0 + 0x15F) == 0) && bakey_released(param_0, 1)) {
        param_1 = 0x164;
    }
    return param_1;
}

s32 func_80800084_bsbansack(PlayerState *param_0, s32 param_1)
{
    if (bakey_pressed(param_0, 8)) {
        param_1 = 0x169;
    }
    if (func_8008E148(param_0)) {
        param_1 = 1;
    }
    if ((*(u8 *)((u8 *)param_0 + 0x15F) == 0) && bakey_released(param_0, 1)) {
        param_1 = 0x164;
    }
    return param_1;
}

void func_80800100_bsbansack(u8 *param_0, s32 (*param_1)(u8 *)) {
    s32 temp_v0;

    temp_v0 = func_8009E6EC();
    switch (temp_v0) {
    case 0x7F:
        (*(s8 *)((s8 *)(param_0) + 0x15F)) = 1;
        return;
    case 0x80:
        (*(s8 *)((s8 *)(param_0) + 0x15F)) = 0;
        return;
    default:
        param_1(param_0);
    case 0xC:
        return;
    }
}

void func_80800168_bsbansack(s32 param_0) {
    func_80800100_bsbansack(param_0, &func_80099B94);
}

void func_8080018C_bsbansack(s32 param_0) {
    func_80800100_bsbansack(param_0, &_bsdrone_entrypoint_3);
}

void func_808001B0_bsbansack(s32 param_0) {
    func_80800100_bsbansack(param_0, &func_80099AA8);
}

void func_808001D4_bsbansack(PlayerState *param_0)
{
    f32 local_0;

    local_0 = bastick_getZonePosition(param_0);
    if (bastick_getZone(param_0) == 0) {
        baphysics_set_target_horizontal_velocity(param_0, 0.0f);
    } else {
        baphysics_set_target_horizontal_velocity(param_0, func_800F1214(local_0, 100.0f, 500.0f));
    }
}

int func_80800238_bsbansack(param_0) s32 param_0;
{
  s32 local_0;
  local_0 = param_0 | 0;
  if (func_8009E74C(local_0, 0x12))
  {
    if (_babackpack_get_state(local_0) != 4)
    {
      func_800A0CD0(local_0, 0);
      _babackpack_set_state(local_0, 4);
    }
  }
  else
  {
    if (_babackpack_get_state(local_0) != 1)
    {
      _babackpack_set_state(local_0, 1);
    }
    func_800A0CD0(local_0, 1);
    bastick_popZone(local_0);
    func_800A1040(local_0);
  }
}

void func_808002D4_bsbansack(param_0)
PlayerState *param_0;
{
    if (!func_8009E77C(param_0, 0x12)) {
        func_800A0CD0(param_0, 0);
        _babackpack_set_state(param_0, 4);
        bastick_pushZone(param_0);
        bastick_setZoneMax(param_0, 0, 0.12f);
        bastick_setZoneMax(param_0, 1, 1.0f);
        func_800A106C(param_0, -10.0f, 10.0f);
        baphysics_set_target_horizontal_velocity(param_0, 0.0f);
        param_0->unk15C.bytes[3] = 0;
    }
}

void func_80800368_bsbansack(s32 param_0) {
    if (func_8008DF8C(param_0, 0x1E)) {
        func_8009D2F0(param_0, 0, 0.5f);
    } else {
        func_8009BF5C(param_0, 0.0f);
        baroll_setIdeal(param_0, 0.0f);
    }
}

void func_808003C0_bsbansack(s32 param_0) {
    baphysics_set_gravity(param_0, 1e+02f);
    baphysics_set_terminal_velocity(param_0, 0x4305547B);
    func_800961AC(param_0, 3);
}

int func_80800400_bsbansack(param_0) Actor *param_0;
{
  baphysics_reset_terminal_velocity();
  baphysics_reset_gravity(param_0);
  func_800961AC(param_0, 1);
}

void func_80800434_bsbansack(s32 arg0)
{
    func_80800400_bsbansack();
    func_80800238_bsbansack(arg0);
}
void func_8080045C_bsbansack(s32 param_0) {
    func_808002D4_bsbansack(param_0);
    baanim_playForDuration_loopSmooth(param_0, 0x28B, 1.5f);
    func_8009FFD8(param_0, 1, 1, 1, 2);
    func_808003C0_bsbansack(param_0);
}

s32 func_808004B0_bsbansack(s32 param_0){
    s32 local_0 = 0;
    s32 local_1 = bastick_getZone(param_0);
    if(local_1 > 0)
        local_0 = 0x166;
    bs_setState(param_0, func_80800084_bsbansack(param_0, local_0));
}

int bsbansack_entrypoint_0(s32 param_0)
{
  return D_80801E10_bsbansack[param_0];
}

int func_80800508_bsbansack(u8 *param_0)
{
  if (!param_0[0x15E])
  {
    func_808002D4_bsbansack();
  }
  func_80800238_bsbansack(param_0);
}

void func_80800540_bsbansack(PlayerState *param_0)
{
    param_0->unk15C.bytes[2] = 0;
    baanim_playForDuration_onceSmooth(param_0, 0x143, 2.0f);
    func_8009FFD8(param_0, 1, 1, 3, 2);
    baphysics_set_target_horizontal_velocity(param_0, 0.0f);
    func_8009DE38(param_0, 0x583, 1.0f);
    bainput_enable(param_0, 2, 0);
}

void func_808005BC_bsbansack(Actor *param_0) {
    s32 local_0;
    s32 local_1;

    local_0 = baanim_getAnimCtrlPtr(param_0);
    local_1 = 0;
    bainput_enable(param_0, 2, 1);
    if (anctrl_isAt(local_0, 0.19f) != 0) {
        func_8009DE38(param_0, 0x57C, 1.0f);
    }
    if (anctrl_isAt(local_0, 0.2f) != 0) {
        func_8009DBF0(param_0, 0x3FF, 0.9f);
    }
    if (anctrl_isAt(local_0, 0.48f) != 0) {
        func_8009FE58(param_0);
    }
    if (anctrl_isAt(local_0, 0.52f) != 0) {
        func_8009DE38(param_0, 0x584, 1.0f);
    }
    if (anctrl_isAt(local_0, 0.123f) != 0) {
        func_800A0CD0(param_0, 0);
        _babackpack_set_state(param_0, 2);
    }
    if (anctrl_isAt(local_0, 0.5145f) != 0) {
        *(s8 *)((char *)param_0 + 0x15E) = 1;
        func_808002D4_bsbansack(param_0);
    }
    if (baanim_isStopped(param_0) != 0) {
        local_1 = 0x165;
    }
    bs_setState(param_0, local_1);
}

int bsbansack_entrypoint_1(s32 param_0)
{
  return D_80801E20_bsbansack[param_0];
}

void func_80800710_bsbansack(PlayerState *param_0)
{
    if (func_8009E6EC(param_0) == 0xC) {
        if (anctrl_getAnimTimer(baanim_getAnimCtrlPtr(param_0)) > 0.42f) {
            func_80099B94(param_0);
        }
    } else {
        func_80800168_bsbansack(param_0);
    }
}

void func_8080077C_bsbansack(s32 arg0)
{
    baphysics_reset_gravity();
    func_80800238_bsbansack(arg0);
}
void func_808007A4_bsbansack(PlayerState *param_0)
{
    func_808002D4_bsbansack(param_0);
    baanim_playForDuration_onceSmooth(param_0, 0x28A, 1.0f);
    func_8009FFD8(param_0, 1, 1, 3, 6);
    baphysics_set_gravity(param_0, -800.0f);
    baphysics_set_vertical_velocity(param_0, 300.0f);
}

void func_80800810_bsbansack(PlayerState *param_0)
{
    AnimCtrl *local_0;
    s32 local_1;
    f32 local_3;
    f32 local_2;

    local_0 = baanim_getAnimCtrlPtr(param_0);
    local_1 = 0;
    if (anctrl_isAt(local_0, 0.2f)) {
        func_8009DE38(param_0, 0x583, 1.1f);
    }
    if (anctrl_isAt(local_0, 0.2f)) {
        func_8009DBF0(param_0, 0x3FF, 0.9f);
    }
    if (anctrl_isAt(local_0, 0.73f)) {
        func_8009FE58(param_0);
    }
    if (anctrl_isAt(local_0, 0.77f)) {
        func_8009DE38(param_0, 0x584, 1.1f);
    }
    if (anctrl_getAnimTimer(local_0) < 0.515f) {
        func_808001D4_bsbansack(param_0);
    } else {
        baphysics_set_target_horizontal_velocity(param_0, 0.0f);
    }
    if (anctrl_isAt(local_0, 0.7307f)) {
        _babackpack_set_state(param_0, 1);
        func_800A0CD0(param_0, 1);
    }
    if (baanim_isStopped(param_0)) {
        local_1 = 1;
    }
    if (anctrl_getAnimTimer(local_0) > 0.8f && bastick_getZone(param_0) > 0) {
        local_1 = 4;
    }
    if (anctrl_getAnimTimer(local_0) > 0.95f && player_inWater(param_0)) {
        local_2 = func_800964DC(param_0);
        local_3 = func_80096364(param_0);
        if (local_2 - local_3 > 80.0f) {
            local_1 = 0x4C;
        }
    }
    bs_setState(param_0, local_1);
}

int bsbansack_entrypoint_2(s32 param_0)
{
  return D_80801E30_bsbansack[param_0];
}

void func_80800A14_bsbansack(PlayerState *param_0)
{
    if (param_0->unk15C.bytes[1] == 0) {
        param_0->unk15C.bytes[1] = 1;
        if (baphysics_get_vertical_velocity(param_0) < 0.0f) {
            baphysics_set_vertical_velocity(param_0, 0.0f);
        }
        func_808003C0_bsbansack(param_0);
    }
}

void func_80800A78_bsbansack(s32 param_0)
{
  if ((*((u8 *) (param_0 + 0x15D))) != 0)
  {
    *((u8 *) (param_0 + 0x15D)) = 0;
    func_80800400_bsbansack();
  }
}

int func_80800AA4_bsbansack(PlayerState *self)
{
  return player_inWater(self) && (baphysics_get_vertical_velocity(self) < 0.0f);
}

void func_80800AF4_bsbansack(param_0, param_1) PlayerState *param_0; s32 param_1;
{
    AnimCtrl *local_0;
    f32 local_1;

    *((u8 *)param_0 + 0x15C) = param_1;
    switch (param_1) {
    case 1:
        local_0 = baanim_getAnimCtrlPtr(param_0);
        func_80800A78_bsbansack(param_0);
        func_8009DB04(param_0, 0x3F0, func_800DC178(0.96f, 1.04f), 10000);
        func_8009FFD8(param_0, 1, 1, 1, 2);
        baphysics_set_gravity(param_0, -1350.0f);
        if (bastick_distance(param_0) != 0.0f) {
            yaw_setIdeal(param_0, bastick_getAngleRelativeToBanjo(param_0));
        }
        local_1 = func_8009BB5C(param_0);
        baphysics_set_target_horizontal_velocity(param_0, local_1);
        baphysics_set_target_yaw(param_0, yaw_getIdeal(param_0));
        baphysics_set_horizontal_velocity(param_0, yaw_getIdeal(param_0), local_1);
        anctrl_reset(local_0);
        anctrl_setIndex(local_0, 0x144);
        anctrl_setSubrange(local_0, 0.0f, 0.35f);
        anctrl_setDuration(local_0, 0.7f);
        anctrl_setPlaybackType(local_0, 1);
        anctrl_start(local_0);
        baphysics_set_vertical_velocity(param_0, 710.0f);
        break;
    case 2:
        baanim_setEndAndDuration(param_0, 0.65f, 3.0f);
        break;
    case 3:
        if (player_inWater(param_0)) func_80800A14_bsbansack(param_0);
        baanim_setEndAndDuration(param_0, 0.98f, 0.7f);
        break;
    case 4:
        if (player_inWater(param_0)) func_80800A14_bsbansack(param_0);
        func_8009D2D8(param_0, 3);
        func_800A2FCC(param_0, 0);
        baanim_setEndAndDuration(param_0, 0.98f, 0.7f);
        break;
    case 0:
        func_80800A78_bsbansack(param_0);
        baphysics_reset_gravity(param_0);
        func_8009BF5C(param_0, 0.0f);
        baroll_setIdeal(param_0, 0.0f);
        break;
    }
}

void func_80800D4C_bsbansack(s32 arg0)
{
    func_80800AF4_bsbansack(arg0,0);
    func_80800238_bsbansack(arg0);
}

void func_80800D78_bsbansack(Actor *param_0)
{
  ActorLocal_BSBansack *local_0;
  func_808002D4_bsbansack();
  local_0--;
  local_0 = (ActorLocal_BSBansack *) (((u8 *) param_0) + 0x15A);
  local_0++;
  local_0->unk15B = 0;
  local_0->unk15A = 0;
  func_80800AF4_bsbansack(param_0, 1);
}

void func_80800DAC_bsbansack(PlayerState *param_0)
{
    s32 local_0;
    AnimCtrl *local_1;

    local_0 = 0;
    local_1 = baanim_getAnimCtrlPtr(param_0);
    if (bakey_released(param_0, 8) && baphysics_get_vertical_velocity(param_0) > 0.0f) {
        baphysics_reset_gravity(param_0);
    }
    func_808001D4_bsbansack(param_0);
    switch (*((u8 *)param_0 + 0x15C)) {
    case 1:
        if (baanim_isAt(param_0, 0.1f)) func_8009D7A4(param_0, 0.95f, 1.05f);
        if (func_8008DF8C(param_0, 0x82) || func_80800AA4_bsbansack(param_0)) {
            func_80800AF4_bsbansack(param_0, 3);
        } else if (anctrl_isStopped(local_1)) {
            func_80800AF4_bsbansack(param_0, 2);
        }
        local_0 = func_80800000_bsbansack(param_0, 0, 0);
        break;
    case 2:
        if (func_8008DF8C(param_0, 0x5A) || func_80800AA4_bsbansack(param_0)) {
            func_80800AF4_bsbansack(param_0, 3);
        }
        local_0 = func_80800000_bsbansack(param_0, 0, 0);
        break;
    case 3:
        func_80800368_bsbansack(param_0);
        if (player_isStable(param_0) || player_inWater(param_0)) {
            func_80800AF4_bsbansack(param_0, 4);
        }
        local_0 = func_80800000_bsbansack(param_0, 0, 0);
        break;
    case 4:
        func_80800368_bsbansack(param_0);
        if (anctrl_isStopped(local_1)) {
            if (baphysics_get_target_horizontal_velocity(param_0) > 0.0f) local_0 = 0x166;
            else if (player_inWater(param_0)) local_0 = 0x167;
            else local_0 = 0x165;
        } else {
            baphysics_set_target_horizontal_velocity(param_0, 0.0f);
        }
        local_0 = func_80800084_bsbansack(param_0, local_0);
        break;
    }
    if (func_8008E260(param_0)) local_0 = 0x3D;
    bs_setState(param_0, local_0);
}

int bsbansack_entrypoint_3(s32 param_0)
{
  return D_80801E40_bsbansack[param_0];
}

int func_8080101C_bsbansack(BansackStruct *param_0, int param_1) {
    f32 temp_f0;
    f32 temp_f0_2;
    f32 temp_f0_3;
    f32 var_f2;

    switch (param_1) {
    case 0:
        yaw_setIdeal(param_0, param_0->unk174);
        yaw_applyIdeal(param_0);
        func_800931AC(param_0, 1);
        break;
    case 1:
        temp_f0 = yaw_get(param_0);
        param_0->unk174 = temp_f0;
        func_8009328C(param_0, temp_f0);
        func_800931AC(param_0, 3);
        _batimer_set(param_0, 0, 0x3F99999A);
        break;
    case 2:
        temp_f0_2 = func_80092BE8(param_0);
        param_0->unk170 = temp_f0_2;
        temp_f0_3 = func_800F1DCC(param_0->unk174, temp_f0_2);
        var_f2 = temp_f0_3;
        if (temp_f0_3 < 0.0f) {
            var_f2 = 360.0f + temp_f0_3;
        }
        if (var_f2 < 180.0f) {
            var_f2 += 360.0f;
        }
        param_0->unk174 = (f32) (param_0->unk170 + var_f2);
        _batimer_set(param_0, 0, 0x3F000000);
        break;
    }
    param_0->unk15C = (s8) param_1;
}

void func_80801158_bsbansack(s32 arg0)
{
    func_8080101C_bsbansack(arg0,0);
}

s32 func_80801178_bsbansack(s32 param_0) {
    s32 result;
  *(u8 *)((char *)(param_0) + 0x15C) = 0;


    result = func_8080101C_bsbansack(param_0, 1);
    return result;
}

int func_8080119C_bsbansack(PlayerState *param_0)
{
    f32 local_4;
    f32 local_3;
    f32 local_2;
    f32 local_1;
    f32 local_0;

    local_0 = func_80092BE8(param_0);
    local_1 = func_800D8FF8();
    _batimer_decrement(param_0, 0);
    switch (*((u8 *)param_0 + 0x15C)) {
    case 1:
        local_2 = func_800F10B4(_batimer_get(param_0, 0), 0.0f, 1.2f, 700.0f, 1400.0f);
        local_0 += local_2 * local_1;
        func_8009328C(param_0, local_0);
        if (func_8008DF8C(param_0, 1)) {
            param_0->unk16C = local_2;
            func_8080101C_bsbansack(param_0, 2);
        }
        return 0;
    case 2:
        local_3 = func_800F10B4(_batimer_get(param_0, 0), 0.0f, 0.5f, 1.0f, 0.0f);
        local_4 = param_0->unk174 - param_0->unk170;
        local_0 = func_80013970(local_3 * 90.0f) * local_4 + param_0->unk170;
        func_8009328C(param_0, local_0);
        if (_batimer_get(param_0, 0) != 0.0f) return 0;
        return 1;
    default: return 0;
    }
}

void func_80801318_bsbansack(s32 arg0)
{
    func_80801158_bsbansack(arg0);
    _babounce_entrypoint_3(arg0);
    func_80800238_bsbansack(arg0);
}

void func_80801348_bsbansack(Actor *param_0)
{
  func_808002D4_bsbansack();
  baanim_playForDuration_onceSmooth(param_0, 0x28C, 1.2f);
  _babounce_entrypoint_4(param_0, 1);
  func_80801178_bsbansack(param_0);
}

void func_80801390_bsbansack(Actor *param_0)
{
  s32 s0;
  s32 s1;
  s0 = param_0;
  s1 = 0;
  if (_babounce_entrypoint_2(s0))
  {
    func_808001D4_bsbansack(s0);
  }
  _babounce_entrypoint_10(s0);
  if (func_8080119C_bsbansack(s0) != 0)
  {
    s1 = 0x165;
  }
  if (func_8008DF8C(s0, 1) != 0)
  {
    ;
    if (bastick_getZone(s0) > 0)
    {
      s1 = 0x166;
    }
    s1 = func_80800084_bsbansack(s0, s1);
  }
  bs_setState(s0, s1);
}

int bsbansack_entrypoint_4(s32 param_0)
{
  return D_80801E50_bsbansack[param_0];
}

void func_8080143C_bsbansack(s32 arg0)
{
    func_80801158_bsbansack(arg0);
    _babounce_entrypoint_3(arg0);
    func_80800238_bsbansack(arg0);
}

void func_8080146C_bsbansack(Actor *param_0)
{
    func_808002D4_bsbansack();
    baanim_playForDuration_onceSmooth(param_0, 652, 1.2f);
    _babounce_entrypoint_4(param_0, 2);
    func_80801178_bsbansack(param_0);
}

void func_808014B4_bsbansack(Actor *param_0)
{
  s32 s0;
  s32 s1;
  s0 = param_0;
  s1 = 0;
  if (_babounce_entrypoint_2(s0))
  {
    func_808001D4_bsbansack(s0);
  }
  _babounce_entrypoint_10(s0);
  if (func_8080119C_bsbansack(s0) != 0)
  {
    s1 = 0x165;
  }
  if (func_8008DF8C(s0, 1) != 0)
  {
    ;
    if (bastick_getZone(s0) > 0)
    {
      s1 = 0x166;
    }
    s1 = func_80800084_bsbansack(s0, s1);
  }
  bs_setState(s0, s1);
}

int bsbansack_entrypoint_5(s32 param_0)
{
  return D_80801E60_bsbansack[param_0];
}

void func_80801560_bsbansack(s32 arg0)
{
    _bsdrone_entrypoint_2();
    func_80800238_bsbansack(arg0);
}
void func_80801588_bsbansack(s32 arg0)
{
    func_808002D4_bsbansack();
    _bsdrone_entrypoint_0(arg0);
}
void func_808015B0_bsbansack(PlayerState* self)
{
    _bsdrone_entrypoint_1(self);
}
int bsbansack_entrypoint_6(s32 param_0)
{
  return D_80801E70_bsbansack[param_0];
}

void func_808015E4_bsbansack(s32 arg0)
{
    _bsrest_entrypoint_14();
    func_80800238_bsbansack(arg0);
}
void func_8080160C_bsbansack(s32 arg0)
{
    func_808002D4_bsbansack();
    _bsrest_entrypoint_16(arg0);
}
int func_80801634_bsbansack(Actor *param_0)
{
  s32 local_0;
  local_0 = 0;
  if (_bsrest_entrypoint_20(param_0))
  {
    local_0 = 0x165;
  }
  bs_setState(param_0, local_0);
}

int bsbansack_entrypoint_7(s32 param_0)
{
  return D_80801E80_bsbansack[param_0];
}

void func_80801680_bsbansack(this, state) PlayerState *this; s32 state;
{
    AnimCtrl *aCtrl;
    f32 velocity;
    f32 duration;
    f32 jumpVel;
    s32 inWater;
    s32 doJump;
    f32 mult;

    this->unk15C.bytes[0] = state;
    switch (state) {
    case 1:
        aCtrl = baanim_getAnimCtrlPtr(this);
        inWater = player_inWater(this);
        doJump = player_isStable(this) || inWater;
        func_80800A78_bsbansack(this);
        func_8009DB04(this, 0x3F0, func_800DC178(0.96f, 1.04f), 10000);
        func_800A2EEC(this, 4);
        func_8009FFD8(this, 1, 1, 1, 2);
        if (bastick_distance(this) != 0.0f) {
            yaw_setIdeal(this, bastick_getAngleRelativeToBanjo(this));
        }
        func_808001D4_bsbansack(this);
        velocity = baphysics_get_target_horizontal_velocity(this);
        if (inWater) {
            duration = func_800F10B4(velocity, 100.0f, 500.0f, 0.35f, 0.7f * 0.6f);
            jumpVel = func_800F10B4(velocity, 100.0f, 500.0f, 346.75f, 693.5f * 0.6f);
        } else {
            duration = func_800F10B4(velocity, 100.0f, 500.0f, 0.35f, 0.7f);
            jumpVel = func_800F10B4(velocity, 100.0f, 500.0f, 346.75f, 693.5f);
        }
        baphysics_set_target_yaw(this, yaw_getIdeal(this));
        baphysics_set_horizontal_velocity(this, yaw_getIdeal(this), velocity);
        anctrl_reset(aCtrl);
        anctrl_setIndex(aCtrl, 0x144);
        anctrl_setSubrange(aCtrl, 0, 0.6466f);
        anctrl_setDuration(aCtrl, duration);
        anctrl_setPlaybackType(aCtrl, 1);
        anctrl_start(aCtrl);
        if (doJump) {
            baphysics_set_vertical_velocity(this, jumpVel);
        }
        break;
    case 2:
        baanim_setEndAndDuration(this, 0.7965f, 3.0f);
        break;
    case 3:
        if (player_inWater(this)) {
            func_80800A14_bsbansack(this);
        }
        baanim_setEndAndDuration(this, 0.98f, 0.7f);
        break;
    case 4:
        mult = 1.0f;
        this->unk16C = func_8009BB5C(this) * 0.25f;
        func_8009D2D8(this, 3);
        baphysics_set_target_horizontal_velocity(this, this->unk16C);
        func_800A2FCC(this, 0);
        if (player_inWater(this)) {
            func_80800A14_bsbansack(this);
            mult = 0.4f;
        }
        baanim_setEndAndDuration(this, 0.98f, 0.7f * mult);
        break;
    case 0:
        func_80800A78_bsbansack(this);
        func_8009BF5C(this, 0.0f);
        baroll_setIdeal(this, 0.0f);
        break;
    }
}

void func_80801A04_bsbansack(s32 arg0)
{
    func_80801680_bsbansack(arg0,0);
    func_80800238_bsbansack(arg0);
}

void func_80801A30_bsbansack(void *param_0)
{
  func_808002D4_bsbansack();
  *((u8 *) (((char *) param_0) + 0x15D)) = 0;
  *((u8 *) (((char *) param_0) + 0x15C)) = 0;
  func_80801680_bsbansack(param_0, 1);
}

void func_80801A64_bsbansack(PlayerState *param_0)
{
    s32 local_0;
    void *local_1;
    local_0 = 0;
    local_1 = baanim_getAnimCtrlPtr(param_0);
    func_808001D4_bsbansack(param_0);
    switch (param_0->unk15C.bytes[0]) {
    case 1:
        if (baanim_isAt(param_0, 0.05f)) func_8009DEC0(param_0, 0x58A, 0.95f, 1.05f, 9000, 11000);
        if (func_8008DF8C(param_0, 0x82) || func_80800AA4_bsbansack(param_0)) func_80801680_bsbansack(param_0, 3);
        else if (anctrl_isStopped(local_1)) func_80801680_bsbansack(param_0, 2);
        local_0 = func_80800000_bsbansack(param_0, 0, 1);
        break;
    case 2:
        if (func_8008DF8C(param_0, 0x82) || func_80800AA4_bsbansack(param_0)) func_80801680_bsbansack(param_0, 3);
        local_0 = func_80800000_bsbansack(param_0, 0, 1);
        break;
    case 3:
        func_80800368_bsbansack(param_0);
        if (player_isStable(param_0) || player_inWater(param_0)) func_80801680_bsbansack(param_0, 4);
        local_0 = func_80800000_bsbansack(param_0, 0, 1);
        break;
    case 4:
        func_80800368_bsbansack(param_0);
        if (anctrl_isStopped(local_1)) {
            if (baphysics_get_target_horizontal_velocity(param_0) > 0.0f) func_80801680_bsbansack(param_0, 1);
            else if (player_inWater(param_0)) local_0 = 0x167;
            else local_0 = 0x165;
        } else baphysics_set_target_horizontal_velocity(param_0, param_0->unk16C);
        local_0 = func_80800084_bsbansack(param_0, local_0);
        break;
    }
    if (func_8008E260(param_0)) local_0 = 0x3D;
    bs_setState(param_0, local_0);
}

int bsbansack_entrypoint_8(s32 param_0)
{
  return D_80801E90_bsbansack[param_0];
}

void func_80801CB4_bsbansack()
{
    func_80800238_bsbansack();
}

void func_80801CD4_bsbansack(s32 param_0) {
    func_808002D4_bsbansack();
    baanim_playForDuration_loopSmooth(param_0, 0x289, 1.0f);
    func_8009FFD8(param_0, 1, 1, 1, 2);
}

void func_80801D20_bsbansack(PlayerState *param_0)
{
    s32 local_0;
    local_0 = 0;
    if (bastick_getZone(param_0) > 0) local_0 = 0x166;
    if (player_inWater(param_0)) local_0 = 0x167;
    local_0 = func_80800084_bsbansack(param_0, local_0);
    if (func_8008E260(param_0)) local_0 = 0x3D;
    bs_setState(param_0, local_0);
}

s32 bsbansack_entrypoint_9(s32 param_0) {
    return D_80801EA0_bsbansack[param_0];
}
