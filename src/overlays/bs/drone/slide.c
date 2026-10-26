#include "common.h"
#include "overlays/ba/playerstate.h"
extern void baphysics_set_target_horizontal_velocity(Actor *a0, f32 a1);
extern void func_8009D658(Actor *a0);

extern f32 yaw_get(PlayerState *);
extern f32 func_800136E4(f32);
extern void baphysics_set_target_yaw(PlayerState *, f32);
extern f32 bastick_distance(PlayerState *);
extern f32 bastick_getAngleRelativeToBanjo(PlayerState *);
extern f32 func_800F1DCC(f32, f32);
extern f32 func_800F0DC0(f32, f32);
extern f32 func_8009BB18(PlayerState *);
extern f32 func_800D8FF8(void);
extern void func_800A4DA4(PlayerState *, s32);
extern f32 func_800F10B4(f32, f32, f32, f32, f32);
extern void yaw_setIdeal(void *, f32);
extern void func_8009BF5C(void *, f32);

int func_80800000_bsdroneslide(Actor *param_0, s32 param_1, f32 param_2)
{
  extern void baanim_playForDuration_loopSmooth(Actor *a0, s32 a1, f32 a2);
  extern void func_8009BFE4(Actor *a0, s32 a1, s32 a2);
  extern void func_8009FFD8(Actor *a0, s32 a1, s32 a2, s32 a3, s32 a4);
  baanim_playForDuration_loopSmooth(param_0, param_1, param_2);
  func_8009FFD8(param_0, 1, 1, 3, 3);
  func_8009BFE4(param_0, 0x44480000, 0x41000000);
  baphysics_set_target_horizontal_velocity(param_0, 0);
  func_8009D658(param_0);
  _batimer_set(param_0, 10, 0x3F800000);
}

void func_80800080_bsdroneslide(Actor *param_0, s32 param_1)
{
    f32 local_0;
    s32 local_1;

    switch (param_1) {
    case 1:
        _badata_entrypoint_13(param_0, &local_1, &local_0);
        func_80800000_bsdroneslide(param_0, local_1, local_0);
        break;
    case 2:
        _badata_entrypoint_12(param_0, &local_1, &local_0);
        func_80800000_bsdroneslide(param_0, local_1, local_0);
        break;
    }
    *(s8 *)((char *)param_0 + 0x190) = (s8) param_1;
}

int func_80800110_bsdroneslide(s32 param_0, s32 param_1, s32 param_2)
{
  f32 local_0[3];
  func_800963C0(param_0, local_0);
  func_800F1988(local_0, param_1, param_2);
}

void bsdroneslide_entrypoint_0(PlayerState *param_0)
{
    f32 local_3;
    s32 local_0;
    f32 local_1;
    s32 local_2;
    *((u8 *)param_0 + 0x190) = 0;
    local_2 = 1;
    if (func_8008E148(param_0)) {
        func_80800110_bsdroneslide(param_0, &local_0, &local_1);
        local_3 = func_800136E4(yaw_get(param_0) - local_1);
        if (local_3 < 90.0f || local_3 > 270.0f) local_2 = 2;
        baphysics_set_target_yaw(param_0, local_1);
    }
    func_80800080_bsdroneslide(param_0, local_2);
}

void func_808001F4_bsdroneslide(PlayerState *param_0, f32 param_1)
{
    f32 local_2;
    f32 local_0;
    f32 local_1;

    if (bastick_distance(param_0) != 0.0f) {
        local_2 = bastick_getAngleRelativeToBanjo(param_0);
        param_1 += func_800F0DC0(func_800F1DCC(local_2, param_1), 60.0f);
    }
    local_1 = func_8009BB18(param_0);
    local_0 = func_800F1DCC(param_1, local_1);
    local_0 *= func_800D8FF8();
    local_1 += local_0;
    if (1) {}
    if (1) {}
    baphysics_set_target_yaw(param_0, local_1);
    func_800A4DA4(param_0, 8);
}

void bsdroneslide_entrypoint_1(void *param_0)
{
    s32 local_0;
    f32 local_1;
    f32 local_2;
    local_0 = 0;
    func_8009D658(param_0);
    _batimer_decrement(param_0, 10);
    if (func_8008E148(param_0)) {
        if (func_80800110_bsdroneslide(param_0, &local_2, &local_1)) {
            if (*((u8 *)param_0 + 0x190) == 1) {
                yaw_setIdeal(param_0, local_1 + 180.0f);
                func_8009BF5C(param_0, -local_2);
            } else {
                yaw_setIdeal(param_0, local_1);
                func_8009BF5C(param_0, local_2);
            }
            baphysics_set_target_horizontal_velocity(param_0, func_800F10B4(local_2, 20.0f, 60.0f, 550.0f, 700.0f));
            func_808001F4_bsdroneslide(param_0, local_1);
        } else baphysics_set_target_horizontal_velocity(param_0, 500.0f);
        _badust_entrypoint_7(param_0);
    } else local_0 = _badata_entrypoint_24(param_0);
    if (player_inWater(param_0)) local_0 = _badata_entrypoint_24(param_0);
    if (_batimer_isZero(param_0, 10) && bakey_pressed(param_0, 8)) local_0 = _badata_entrypoint_25(param_0);
    bs_setState(param_0, local_0);
}

s32 bsdroneslide_entrypoint_2(Actor *this)
{
  int new_var;
  Actor *new_var2;
  int new_var3;
  new_var3 = 0xFF;
  new_var = (((((((0xFF & 0xFF) & new_var3) & new_var3) & 0xFF) & new_var3) & 0xFF) & new_var3) & 0xFF;
  func_8009BF5C(this, 0);
  new_var2 = this;
  func_800A4E30(new_var2);
}
