#include "common.h"
#include "overlays/ba/playerstate.h"
#include "overlays/ba/playerstate.h"

extern f32 bastick_getZonePosition(PlayerState *);
extern f32 func_800F1214(f32, f32, f32);
extern void baanim_playForDuration_onceSmooth(PlayerState *, s32, f32);
extern void func_8009FFD8(PlayerState *, s32, s32, s32, s32);
extern void bainput_enable(PlayerState *, s32, s32);
extern s32 baanim_isAt(PlayerState *, f32);
extern void func_8009DF58(PlayerState *, s32, f32);
extern void func_8009DB04(PlayerState *, s32, f32, s32);
extern s32 D_80800A40_bsbansnooze[];
extern s32 D_80800A50_bsbansnooze[];
extern s32 D_80800A60_bsbansnooze;
extern void *baanim_getAnimCtrlPtr(PlayerState *);
extern f32 anctrl_getAnimTimer(void *);
extern f32 func_800F3780(f32, void *, s32);
extern s32 func_8009BCD4(PlayerState *, f32);
extern s32 D_80800A78_bsbansnooze[];
extern s32 D_80800A88_bsbansnooze[];
extern s32 D_80800A98_bsbansnooze[];
extern void anctrl_setDuration(void *, f32);
extern void func_8008B1C8(void *, f32);
extern void _batimer_set(PlayerState *, s32, f32);
extern s32 D_80800AA8_bsbansnooze[];
extern void baanim_playForDuration_loopSmooth(PlayerState *, s32, f32);
extern void baanim_setDurationRange(PlayerState *, f32, f32);
extern void func_8008C9F0(PlayerState *, f32, f32, f32, f32);
extern void func_8008CA30(PlayerState *, f32);
extern void func_8009DEC0(PlayerState *, s32, f32, f32, s32, s32);
extern void func_8009DFD4(PlayerState *, s32, f32, f32, s32, s32);

int func_80800000_bsbansnooze(param_0) s32 param_0;
{
  s32 local_0;
  local_0 = param_0 | 0;
  if (func_8009E74C(local_0, 0x14))
  {
    if (_babackpack_get_state(local_0) != 6)
    {
      _babackpack_set_state(local_0, 6);
    }
  }
  else
  {
    if (_babackpack_get_state(local_0) != 1)
    {
      _babackpack_set_state(local_0, 1);
    }
    func_800A0CD0(local_0, 1);
    func_80095A40(local_0);
    bastick_popZone(local_0);
    func_800A4E30(local_0);
  }
}

int func_80800098_bsbansnooze(param_0) s32 param_0;
{
  s32 local_0;
  local_0 = param_0 | 0;
  if (!func_8009E77C(local_0, 0x14))
  {
    func_800A0CD0(local_0, 0);
    _babackpack_set_state(local_0, 6);
    bastick_pushZone(local_0);
    bastick_setZoneMax(local_0, 0, 0x3DF5C28F);
    bastick_setZoneMax(local_0, 1, 0x3F800000);
    func_800959C8(local_0, 0x42700000, 0x41F00000);
    func_800A4DA4(local_0, 8);
  }
}

extern void baphysics_set_target_horizontal_velocity(Actor *a0, f32 a1);

void func_80800128_bsbansnooze(PlayerState *param_0, f32 param_1)
{
    f32 local_0;
    local_0 = bastick_getZonePosition(param_0);
    if (!bastick_getZone(param_0)) {
        baphysics_set_target_horizontal_velocity(param_0, 0.0f);
    } else {
        baphysics_set_target_horizontal_velocity(param_0,
            func_800F1214(local_0, 50.0f, 100.0f) * param_1);
    }
}

int func_8080019C_bsbansnooze(u8 *param_0)
{
  if (param_0[0x15D])
  {
    if ((param_0 && param_0) && param_0)
    {
    }
    func_80800000_bsbansnooze();
  }
  else
    if (_babackpack_get_state() != 1)
  {
    func_800A0CD0(param_0, 1);
    _babackpack_set_state(param_0, 1);
  }
}

void func_808001FC_bsbansnooze(PlayerState *param_0)
{
    *(u8 *)((u8 *)param_0 + 0x15D) = 0;
    baanim_playForDuration_onceSmooth(param_0, 0x276, 1.5f);
    func_8009FFD8(param_0, 1, 1, 3, 2);
    baphysics_set_target_horizontal_velocity(param_0, 0.0f);
    func_8009DE38(param_0, 0x583, 0x3F800000);
    bainput_enable(param_0, 1, 0);
}

void func_80800278_bsbansnooze(PlayerState *param_0)
{
    s32 local_0 = 0;

    bainput_enable(param_0, 1, 1);
    if (baanim_isAt(param_0, 0.18f)) {
        func_8009DF58(param_0, 0x58C, 1.0f);
    }
    if (baanim_isAt(param_0, 0.22f)) {
        func_8009DB04(param_0, 0x3FF, 1.0f, 0x55F0);
    }
    if (baanim_isAt(param_0, 0.1184f)) {
        func_800A0CD0(param_0, 0);
        _babackpack_set_state(param_0, 2);
    }
    if (baanim_isAt(param_0, 0.3703f)) {
        *((u8 *)param_0 + 0x15D) = 1;
        func_80800098_bsbansnooze(param_0);
    }
    if (baanim_isStopped(param_0)) {
        local_0 = 0x16F;
    }
    bs_setState(param_0, local_0);
}

int bsbansnooze_entrypoint_0(s32 param_0)
{
  return D_80800A40_bsbansnooze[param_0];
}

void func_8080037C_bsbansnooze()
{
    func_80800000_bsbansnooze();
}

int func_8080039C_bsbansnooze(Actor *param_0)
{
  extern void baphysics_set_target_horizontal_velocity(Actor *a0, f32 a1);
  func_80800098_bsbansnooze(param_0);
  baanim_playForDuration_onceSmooth(param_0, 0x279, 1.6f);
  func_8009FFD8(param_0, 1, 1, 3, 2);
  baphysics_set_target_horizontal_velocity(param_0, 0.0f);
  func_8009DF94(param_0, 0x58D, 0x3F800000, 0x7530);
}

int func_80800414_bsbansnooze(s32 param_0)
{
  s32 local_0;
  local_0 = 0;
  if (baanim_isAt(param_0, 0.77f))
  {
    func_8009DE38(param_0, 0x584, 0x3F8CCCCD);
  }
  if (baanim_isAt(param_0, 0.6556f))
  {
    _babackpack_set_state(param_0, 1);
    func_800A0CD0(param_0, 1);
  }
  if (baanim_isStopped(param_0))
  {
    local_0 = 1;
  }
  bs_setState(param_0, local_0);
}

int bsbansnooze_entrypoint_1(int param_0)
{
  return D_80800A50_bsbansnooze[param_0];
}

void func_808004C0_bsbansnooze()
{
    func_80800000_bsbansnooze();
}

void func_808004E0_bsbansnooze(PlayerState *param_0)
{
    func_80800098_bsbansnooze(param_0);
    baanim_playForDuration_loopSmooth(param_0, 0x278, 0.7f);
    func_8009FFD8(param_0, 2, 3, 8, 14);
    yaw_setVelocityBounded(param_0, 0x42C80000, 0x40600000);
    baanim_setDurationRange(param_0, 0.1f, 5.0f);
    func_8008C9F0(param_0, 50.0f, 100.0f, 0.7f, 0.7f);
    func_8008CA30(param_0, 1.0f);
}

void func_80800588_bsbansnooze(PlayerState *param_0)
{
    s32 local_0;
    void *local_1;

    local_1 = baanim_getAnimCtrlPtr(param_0);
    local_0 = 0;
    func_80800128_bsbansnooze(param_0,
        func_800F3780(anctrl_getAnimTimer(local_1), &D_80800A60_bsbansnooze, 3));
    if (!bastick_getZone(param_0) && func_8009BCD4(param_0, 3.0f)) local_0 = 0x16F;
    if (bakey_released(param_0, 1)) local_0 = 0x172;
    if (player_inWater(param_0)) local_0 = 0x4C;
    bs_setState(param_0, local_0);
}

int bsbansnooze_entrypoint_2(int param_0)
{
  return D_80800A78_bsbansnooze[param_0];
}

void func_8080064C_bsbansnooze(s32 arg0)
{
    _bsdrone_entrypoint_2();
    func_80800000_bsbansnooze(arg0);
}
void func_80800674_bsbansnooze(s32 arg0)
{
    func_80800098_bsbansnooze();
    _bsdrone_entrypoint_0(arg0);
}
void func_8080069C_bsbansnooze(PlayerState* self)
{
    _bsdrone_entrypoint_1(self);
}
int bsbansnooze_entrypoint_3(int param_0)
{
  return D_80800A88_bsbansnooze[param_0];
}

void func_808006D0_bsbansnooze(s32 arg0)
{
    _bsrest_entrypoint_14();
    func_80800000_bsbansnooze(arg0);
}
void func_808006F8_bsbansnooze(s32 arg0)
{
    func_80800098_bsbansnooze();
    _bsrest_entrypoint_16(arg0);
}
int func_80800720_bsbansnooze(Actor *param_0)
{
  s32 local_0;
  local_0 = 0;
  if (_bsrest_entrypoint_20(param_0))
  {
    local_0 = 0x16F;
  }
  bs_setState(param_0, local_0);
}

int bsbansnooze_entrypoint_4(s32 param_0)
{
  return D_80800A98_bsbansnooze[param_0];
}

void func_8080076C_bsbansnooze(s32 arg0)
{
    func_800951B4();
    func_80800000_bsbansnooze(arg0);
}
void func_80800794_bsbansnooze(PlayerState *param_0)
{
    void *local_0;
    s32 local_1;
    local_0 = baanim_getAnimCtrlPtr(param_0);
    func_80800098_bsbansnooze(param_0);
    anctrl_reset(local_0);
    anctrl_setIndex(local_0, 0x277);
    anctrl_setDuration(local_0, 2.0f);
    func_8008B1C8(local_0, 0.6f);
    anctrl_setPlaybackType(local_0, 2);
    anctrl_start(local_0);
    func_8009FFD8(param_0, 1, 3, 8, 14);
    yaw_setVelocityBounded(param_0, 0x42C80000, 0x40600000);
    baphysics_set_target_horizontal_velocity(param_0, 0.0f);
    func_8009514C(param_0);
    _batimer_set(param_0, 0, 1.0f);
    local_1 = func_800A1718(param_0);
    if (func_800A1760(param_0) == local_1) func_800A17A8(param_0, 0);
    if (bs_getPreviousState(param_0) == 0x170) param_0->unk15C.bytes[0] = 0;
    else param_0->unk15C.bytes[0] = 1;
}

void func_808008A4_bsbansnooze(PlayerState *param_0)
{
    s32 local_0;
    s32 local_1;

    local_0 = 0;
    if (_batimer_decrement(param_0, 0)) {
        _batimer_set(param_0, 0, 1.0f);
        local_1 = func_800A1718(param_0);
        if (local_1 < func_800A1760(param_0)) {
            func_800FC660(8);
            func_800A17A8(param_0, 1);
        }
    }
    if (param_0->unk15C.bytes[0]) {
        if (baanim_isAt(param_0, param_0->unk15C.bytes[0] == 1 ? 0.1f : 0.01f)) {
            func_8009DEC0(param_0, 0x441, 0.93f, 1.08f, 20000, 22000);
        }
        if (baanim_isAt(param_0, 0.5f)) {
            func_8009DFD4(param_0, 0x442, 0.93f, 1.08f, 20000, 22000);
        }
    }
    if (baanim_isAt(param_0, 0.99f)) param_0->unk15C.bytes[0] = 2;
    if (bakey_released(param_0, 1)) local_0 = 0x172;
    if (player_inWater(param_0)) local_0 = 0x4C;
    bs_setState(param_0, local_0);
}

s32 bsbansnooze_entrypoint_5(s32 param_0) {
    return D_80800AA8_bsbansnooze[param_0];
}
