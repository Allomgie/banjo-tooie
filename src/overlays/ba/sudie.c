#include "common.h"
#include "playerstate.h"

extern void func_8009C128(PlayerState *, f32 *);
extern void func_800A32C4(PlayerState *, f32 *);
extern void func_800F1E6C(f32 *, f32 *, f32 *);
extern f32 func_800136E4(f32);
extern void yaw_setIdeal(PlayerState *, f32);
extern void baphysics_set_target_horizontal_velocity(PlayerState *, f32);
extern void baphysics_set_target_yaw(PlayerState *, f32);
extern f32 baphysics_get_target_horizontal_velocity(PlayerState *);
extern void baphysics_set_horizontal_velocity(PlayerState *, f32, f32);
extern void baphysics_set_vertical_velocity(PlayerState *, f32);
extern void baphysics_set_gravity(PlayerState *, f32);
extern void _ncbadie_entrypoint_3(void *, f32);
extern void _batimer_set(PlayerState *, s32, f32);
extern f32 func_800964DC(void *);
extern f32 func_80096364(void *);
extern f32 _batimer_get(void *, s32);
extern s32 func_80096544(void *);
extern s32 player_inWater();
extern f32 func_8009C150(void *);
void basudie_entrypoint_4(PlayerState *param_0, f32 param_1, f32 param_2, f32 param_3, f32 param_4, f32 param_5);

void basudie_entrypoint_0()
{
    func_80091EF0();
}

void basudie_entrypoint_1(u8 *param_0) {
    if (func_800F8B64() == 0) {
        func_80101238(0x9F, (*(s32 *)((s8 *)(param_0) + (0x184))));
        func_800F90F8(1);
        func_800C0658();
    }
}

void basudie_entrypoint_2(s32 param_0, f32 param_1, f32 param_2, f32 param_3) {
    basudie_entrypoint_4(param_0, param_1, param_2, param_3, 30.0f, 3.5f);
}

void basudie_entrypoint_3(void *param_0, f32 param_1, f32 param_2, s32 param_3, f32 param_4)
{
    basudie_entrypoint_4(param_0, param_1, param_2, (*(f32 *)&param_3), param_4, 3.5f);
}

void basudie_entrypoint_4(PlayerState *param_0, f32 param_1, f32 param_2, f32 param_3, f32 param_4, f32 param_5)
{
    f32 local_0;
    f32 local_1[3];
    f32 local_2[3];

    basudie_entrypoint_1(param_0);
    func_8009FFD8(param_0, 1, 1, 2, 3);
    func_8009C128(param_0, local_1);
    func_800A32C4(param_0, local_2);
    func_800F1E6C(local_2, local_1, &local_0);
    yaw_setIdeal(param_0, func_800136E4(local_0 + 180.0f));
    yaw_applyIdeal(param_0);
    baphysics_set_target_horizontal_velocity(param_0, param_1);
    baphysics_set_target_yaw(param_0, local_0);
    baphysics_set_horizontal_velocity(param_0, local_0, baphysics_get_target_horizontal_velocity(param_0));
    baphysics_set_vertical_velocity(param_0, param_2);
    baphysics_set_gravity(param_0, param_3);
    func_8008E944(param_0);
    func_8009514C(param_0);
    func_800A4DFC(param_0, 10);
    func_800C52F4(func_800A4C68(param_0), 2);
    _ncbadie_entrypoint_3(func_800A4CA8(param_0), param_4);
    func_800A0180(param_0);
    _batimer_set(param_0, 9, param_5);
}

s32 basudie_entrypoint_5(Actor *this){
    func_8009D3A8(this, 0);
    if(_batimer_decrement(this, 0x9))
        basudie_entrypoint_0(this);
}

int basudie_entrypoint_6(Actor *param_0)
{
  baphysics_reset_gravity();
  func_800A4E30(param_0);
  func_800C53EC(func_800A4C68(param_0) | 0, 2);
  func_800951B4(param_0);
}

int basudie_entrypoint_7(void *param_0)
{
    f32 local_0;
    f32 local_1;

    local_0 = func_800964DC(param_0);
    local_1 = func_80096364(param_0);
    return _batimer_get(param_0, 9) != 0.0f &&
        func_80096544(param_0) != 0 && player_inWater(param_0) != 0 &&
        func_8009C150(param_0) < local_0 - 150.0f && local_0 - local_1 > 100.0f;
}

int basudie_entrypoint_8(Actor *param_0)
{
  func_80091E6C();
  func_800A4E30(param_0);
  func_800C53EC(func_800A4C68(param_0) | 0, 2);
}

void basudie_entrypoint_9(s32 param_0, f32 param_1) {
    func_80091E48(param_0, 0x20);
    basudie_entrypoint_1(param_0);
    func_8008E944(param_0);
    func_800A4DFC(param_0, 0xA);
    func_800C52F4(func_800A4C68(param_0), 2);
    _ncbadie_entrypoint_3(func_800A4CA8(param_0), param_1);
    func_800A0180(param_0);
    _batimer_set(param_0, 9, 3.6f);
    _bashake_entrypoint_0(param_0, 3, 2);
}

int basudie_entrypoint_10(Actor *param_0)
{
  if (_batimer_decrement(param_0, 9))
  {
    basudie_entrypoint_0(param_0);
  }
}

void basudie_entrypoint_11(s32 arg0)
{
    func_8009E6EC();
    func_80099AA8(arg0);
}
int basudie_entrypoint_12(Actor *param_0)
{
  if (player_inWater())
  {
    baphysics_set_terminal_velocity(param_0, 0xC37A0000);
  }
  else
  {
    baphysics_reset_terminal_velocity();
  }
}
