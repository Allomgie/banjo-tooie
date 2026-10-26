#include "common.h"
#include "overlays/ba/playerstate.h"
#include "overlays/ba/playerstate.h"

extern f32 bastick_getZonePosition(PlayerState *);
extern s32 bastick_getZone();
extern f32 func_800F1214(f32, f32, f32);
extern void bastick_setZoneMax(PlayerState *, s32, f32);
extern s32 D_808007B0_bscarry[];
extern s32 D_808007C0_bscarry[];
extern s32 D_808007D0_bscarry[];
extern s32 D_808007E0_bscarry[];
extern s32 D_808007F0_bscarry[];
extern void baanim_playForDuration_loopSmooth(PlayerState *, s32, f32);
extern void func_8009FFD8(PlayerState *, s32, s32, s32, s32);
extern void func_8008C9F0(PlayerState *, f32, f32, f32, f32);

void func_80800000_bscarry(s32 param_0) {
    s32 temp_v0;

    temp_v0 = func_8009E6EC();
    switch (temp_v0) {
    case 8:
        func_8009E830(param_0, 2);
        bs_setState(param_0, 0x3C);
        return;
    case 18:
        func_8008F6B8(param_0, func_8008E9AC(param_0));
        return;
    case 22:
        if (bastatetimer_isDone(param_0, 1) != 0) {
            bs_setState(param_0, 0x5B);
            func_8009E830(param_0, 2);
            return;
        }
        func_8009E830(param_0, 1);
        return;
    default:
        func_80099B94(param_0);
        return;
    }
}

int func_808000D0_bscarry(s32 param_0)
{
  switch (func_8009E6EC())
  {
    case 8:

    case 0x12:

    case 0x16:
      if (!param_0)
    {
    }
      func_80800000_bscarry(param_0);
      break;

    default:
      _bsdrone_entrypoint_3();

  }

}

extern void baphysics_set_target_horizontal_velocity(Actor *a0, f32 a1);

void func_80800128_bscarry(PlayerState *param_0)
{
    f32 local_0;

    local_0 = bastick_getZonePosition(param_0);
    switch (bastick_getZone(param_0)) {
    case 0:
        baphysics_set_target_horizontal_velocity(param_0, 0.0f);
        break;
    case 1:
        baphysics_set_target_horizontal_velocity(param_0, func_800F1214(local_0, 30.0f, 60.0f));
        break;
    case 2:
        baphysics_set_target_horizontal_velocity(param_0, func_800F1214(local_0, 60.0f, 300.0f));
        break;
    }
}

int func_808001D4_bscarry(param_0) s32 param_0;
{
  if (!func_8009E69C(param_0, 0x400))
  {
    bastick_popZone(param_0);
  }
}

void func_80800208_bscarry(param_0)
PlayerState *param_0;
{
    if (!func_8009E6C4(param_0, 0x400)) {
        bastick_pushZone(param_0);
        bastick_setZoneMax(param_0, 0, 0.03f);
        bastick_setZoneMax(param_0, 1, 0.2f);
        bastick_setZoneMax(param_0, 2, 1.0f);
    }
}

void func_8080027C_bscarry()
{
    func_808001D4_bscarry();
}

void func_8080029C_bscarry(PlayerState *param_0)
{
    func_80800208_bscarry(param_0);
    baanim_playForDuration_loopSmooth(param_0, 0x28, 0.8f);
    func_8009FFD8(param_0, 2, 1, 1, 2);
    func_8008C9F0(param_0, 30.0f, 60.0f, 1.8f, 1.2f);
}

void func_80800310_bscarry(s32 param_0) {
    s32 var_s1;
    s32 temp_v0;

    var_s1 = 0;
    func_800A2CE8(param_0, 0x3ECCCCCD, 4);
    func_800A2CE8(param_0, 0x3F666666, 3);
    func_80800128_bscarry(param_0);
    temp_v0 = bastick_getZone(param_0);
    switch (temp_v0) {
    case 0:
        if (func_8009BCD4(param_0, 0x3F800000) != 0) {
            var_s1 = 0x3A;
        }
        break;
    case 2:
        var_s1 = 0x3B;
        break;
    }
    if (_bahold_entrypoint_5(param_0) == 0) {
        var_s1 = 1;
    }
    bs_setState(param_0, var_s1);
}

int bscarry_entrypoint_0(s32 param_0)
{
  return D_808007B0_bscarry[param_0];
}

void func_808003D8_bscarry()
{
    func_808001D4_bscarry();
}

void func_808003F8_bscarry(s32 param_0)
{
  extern void baphysics_set_target_horizontal_velocity(Actor *a0, f32 a1);
  func_80800208_bscarry();
  baanim_playForDuration_loopSmooth(param_0, 0x72, 1.2f);
  func_8009FFD8(param_0, 1, 1, 1, 2);
  baphysics_set_target_horizontal_velocity(param_0, (double) 0);
  func_8009BFE4(param_0, 0x447A0000, 0x41400000);
  baroll_setAngularVelocity(param_0, 0x447A0000, 0x41400000);
}

int func_8080047C_bscarry(Actor *param_0)
{
  s32 local_0;
  local_0 = 0;
  switch (bastick_getZone())
  {
    case 1:
      local_0 = 0x9F;
      break;
    case 2:
      local_0 = 0x3B;
      break;
  }

  if (_bahold_entrypoint_5(param_0, local_0) == 0)
  {
    local_0 = 1;
  }
  bs_setState(param_0, local_0);
}

int bscarry_entrypoint_1(s32 param_0)
{
  return D_808007C0_bscarry[param_0];
}

void func_80800500_bscarry()
{
    func_808001D4_bscarry();
}

void func_80800520_bscarry(PlayerState *param_0)
{
    func_80800208_bscarry(param_0);
    baanim_playForDuration_loopSmooth(param_0, 0x73, 0.8f);
    func_8009FFD8(param_0, 2, 1, 1, 2);
    func_8008C9F0(param_0, 60.0f, 300.0f, 0.84f, 0.4f);
}

void func_80800594_bscarry(Actor *param_0)
{
  s32 local_0;
  u8 local_1 = 0;
  func_800A2CE8(param_0, 0x3ECCCCCD, 4);
  func_800A2CE8(param_0, 0x3F666666, 3);
  func_80800128_bscarry(param_0);
  local_0 = bastick_getZone(param_0);
  switch (local_0)
  {
    case 0:
      if (func_8009BCD4(param_0, 0x3F800000) != 0)
      {
        local_1 = 0x3A;
      }
      break;

    case 1:
      local_1 = 0x9F;
      break;

  }

  if (_bahold_entrypoint_5(param_0) == 0)
  {
    local_1 = 1;
  }
  bs_setState(param_0, local_1);
}

int bscarry_entrypoint_2(s32 param_0)
{
  return D_808007D0_bscarry[param_0];
}

void func_8080065C_bscarry(s32 arg0)
{
    _bsdrone_entrypoint_2();
    func_808001D4_bscarry(arg0);
}
void func_80800684_bscarry(s32 arg0)
{
    func_80800208_bscarry();
    _bsdrone_entrypoint_0(arg0);
}
void func_808006AC_bscarry(PlayerState* self)
{
    _bsdrone_entrypoint_1(self);
}
int bscarry_entrypoint_3(s32 param_0)
{
  return D_808007E0_bscarry[param_0];
}

void func_808006E0_bscarry(s32 arg0)
{
    _bsrest_entrypoint_14();
    func_808001D4_bscarry(arg0);
}
void func_80800708_bscarry(s32 arg0)
{
    func_80800208_bscarry();
    _bsrest_entrypoint_16(arg0);
}
int func_80800730_bscarry(Actor *param_0)
{
  s32 local_0;
  local_0 = 0;
  if (_bsrest_entrypoint_20())
  {
    local_0 = 0x3A;
  }
  if (!_bahold_entrypoint_5(param_0, local_0))
  {
    local_0 = 0x73;
  }
  bs_setState(param_0, local_0);
}

int bscarry_entrypoint_4(s32 param_0)
{
  return D_808007F0_bscarry[param_0];
}
