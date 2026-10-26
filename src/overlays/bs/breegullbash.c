#include "common.h"
#include "overlays/ba/playerstate.h"

extern void func_8009E55C(s32, s32, f32);
extern void baanim_playForDuration_onceSmooth(PlayerState *, s32, f32);
extern f32 yaw_getIdeal(PlayerState *);
extern void baphysics_set_target_yaw(PlayerState *, f32);
extern void baphysics_set_target_horizontal_velocity(PlayerState *, f32);
extern void _babackpack_entrypoint_5();
extern s32 D_80800560_bsbreegullbash[];
extern void func_800EFCD8(f32 *, f32, f32);
extern void _badust_entrypoint_2(PlayerState *, f32 *, f32 *, f32, f32, f32);
extern f32 func_800136E4(f32);
void func_808000A4_bsbreegullbash();

void func_80800000_bsbreegullbash(PlayerState *param_0, f32 param_1, f32 param_2, f32 param_3)
{
    f32 local_0[3];
    f32 local_1[3];
    param_2 *= 0.51f;
    _babackpack_entrypoint_5(param_0, local_1, 2);
    local_1[1] -= 20.0f;
    func_800EFCD8(local_0, param_1, param_2);
    local_0[1] = param_3;
    _badust_entrypoint_2(param_0, local_1, local_0, 0.1f, 0.8f, 0.7f);
}

void func_808000A4_bsbreegullbash(param_0) PlayerState *param_0;
{
    f32 local_0;
    for (local_0 = 0.0f; local_0 < 359.0f; local_0 += 60.0f) {
        func_80800000_bsbreegullbash(param_0, local_0, 730.0f, 100.0f);
    }
    for (local_0 = 0.0f; local_0 < 359.0f; local_0 += 60.0f) {
        func_80800000_bsbreegullbash(param_0, func_800136E4(local_0 + 30.0f), 430.0f, 40.0f);
    }
}

void func_808001B4_bsbreegullbash(s32 arg0)
{
    _babackpack_set_state(arg0,0x7);
}

int func_808001D4_bsbreegullbash(Actor *param_0)
{
  if (_babackpack_get_state() != 1)
  {
    _babackpack_set_state(param_0, 1);
    func_8009E4E0(param_0, 2, 0);
    func_8009E55C(param_0, 2, 0);
  }
}

int bsbreegullbash_entrypoint_0(Actor *param_0)
{
  func_8009E474();
  func_808001D4_bsbreegullbash(param_0);
  baflag_clear(param_0, 0x3E);
}

void bsbreegullbash_entrypoint_1(PlayerState *param_0)
{
    baanim_playForDuration_onceSmooth(param_0, 0x20, 1.75f);
    func_8009FFD8(param_0, 1, 1, 3, 6);
    baphysics_set_target_yaw(param_0, yaw_getIdeal(param_0));
    func_8009E4AC(param_0);
    func_8009E4E0(param_0, 2, 0);
    func_8009E55C(param_0, 2, 0.0f);
    baphysics_set_target_horizontal_velocity(param_0, 0.0f);
}

void bsbreegullbash_entrypoint_2(s32 param_0) {
    s32 local_0;

    local_0 = 0;
    if ((baanim_isAt(param_0, 0x3E6147AE) != 0) && (_babackpack_get_state(param_0) == 7)) {
        baflag_set(param_0, 0x3E);
        func_8009E55C(param_0, 2, 60.0f);
        func_8009E4E0(param_0, 2, &_babackpack_entrypoint_5);
        func_8009E5A4(param_0, 2, 2);
    }
    if (baanim_isAt(param_0, 0x3DF34D6A) != 0) {
        func_808001B4_bsbreegullbash(param_0);
    }
    if (baanim_isAt(param_0, 0x3E570A3D) != 0) {
        func_8009DFD4(param_0, 0x4595, 0x3F800000, 0x3F8CCCCD, 0x55F0, 0x55F0);
    }
    if (baanim_isAt(param_0, 0x3EB851EC) != 0) {
        func_8009DB04(param_0, 0x416, 0x3F800000, 0x55F0);
    }
    if (baanim_isAt(param_0, 0x3EBD70A4) != 0) {
        func_8009DFD4(param_0, 0x4596, 0x3F800000, 0x3F8CCCCD, 0x7FFF, 0x7FFF);
    }
    if (baanim_isAt(param_0, 0x3F2BE0DF) != 0) {
        func_8009DF18(param_0, 0x3EA, 0x3F800000, 0x55F0);
    }
    if (baanim_isAt(param_0, 0x3EAB851F) != 0) {
        _bashake_entrypoint_0(param_0, 3, 2);
        func_8009E55C(param_0, 2, 180.0f);
        func_808000A4_bsbreegullbash(param_0);
    }
    if (baanim_isAt(param_0, 0x3EC28F5C) != 0) {
        func_8009E55C(param_0, 2, 0.0f);
        baflag_clear(param_0, 0x3E);
    }
    if (baanim_isAt(param_0, 0x3F641F21) != 0) {
        func_808001D4_bsbreegullbash(param_0);
    }
    if (baanim_isStopped(param_0) != 0) {
        local_0 = 1;
    }
    if (player_inWater(param_0) != 0) {
        local_0 = 0x4C;
    }
    bs_setState(param_0, local_0);
}

int bsbreegullbash_entrypoint_3(s32 param_0)
{
  return D_80800560_bsbreegullbash[param_0];
}
