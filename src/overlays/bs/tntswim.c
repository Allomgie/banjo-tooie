#include "common.h"
#include "overlays/ba/playerstate.h"

extern s32 func_80096544(PlayerState *);
extern f32 func_800DC0C0(void);
extern void func_80092C00(PlayerState *, f32[3]);
extern void func_80092C24(PlayerState *, f32[3]);
extern s32 func_8009FBB0(PlayerState *, f32[3], f32);
extern void func_800BA930(s32, s32, s32, s32, s32, s32, s32);
extern void func_800BA22C(s32, s32);
extern f32 bastick_getZonePosition(PlayerState *);
extern s32 bastick_getZone(PlayerState *);
extern f32 func_800F1214(f32, f32, f32);
extern void baphysics_set_gravity(PlayerState *, f32);
extern void baphysics_set_terminal_velocity(PlayerState *, f32);
extern void baphysics_set_vertical_velocity(PlayerState *, f32);
extern void func_8009BC5C(PlayerState *, f32);
extern f32 func_800A3298(PlayerState *);
extern f32 func_800F10B4(f32, f32, f32, f32, f32);
extern s32 D_808009B0_bstntswim[];
extern void *baanim_getAnimCtrlPtr();
extern s32 anctrl_isAt(void *, f32);
extern void func_8009DEC0(PlayerState *, s32, f32, f32, s32, s32);
extern int D_808009C0_bstntswim[];
extern s32 D_808009D0_bstntswim[];
extern s32 D_808009E0_bstntswim[];
extern s32 D_808009F0_bstntswim[];
extern void func_8009C128(PlayerState *, f32 *);
extern f32 mlAbsF(f32);
extern f32 func_800F0E00(f32, f32);
extern f32 baphysics_get_vertical_velocity(PlayerState *);
extern void func_8008CA4C(PlayerState *, s32);
extern void baanim_setDurationRange(PlayerState *, f32, f32);
extern void func_8008C9F0(PlayerState *, f32, f32, f32, f32);
extern void yaw_setUpdateType(PlayerState *, s32);
extern void func_8009D2D8(PlayerState *, s32);
extern void baphysics_set_type(PlayerState *, s32);

void func_80800000_bstntswim(PlayerState *param_0)
{
    f32 local_1[3];
    s32 local_0;

    if (func_80096544(param_0)) {
        if (func_800DC0C0() > 0.5f) {
            func_80092C00(param_0, local_1);
        } else {
            func_80092C24(param_0, local_1);
        }
        local_0 = func_8009FBB0(param_0, local_1, 0.0f);
        func_800BA930(local_0, -60, -100, -60, 60, 0, 60);
        func_800BA22C(local_0, 1);
    }
}

extern void baphysics_set_target_horizontal_velocity(Actor *a0, f32 a1);

void func_808000B0_bstntswim(PlayerState *param_0)
{
    f32 local_0;

    local_0 = bastick_getZonePosition(param_0);
    if (bastick_getZone(param_0) == 0) {
        baphysics_set_target_horizontal_velocity(param_0, 0.0f);
    } else {
        baphysics_set_target_horizontal_velocity(param_0, func_800F1214(local_0, 30.0f, 200.0f));
    }
}

s32 func_80800114_bstntswim(param_0) s32 param_0;
{
    _bstnt_entrypoint_3(param_0);
    if (func_8009E6C4(param_0, 1) == 0) {
        baphysics_set_gravity(param_0, 1e+02f);
        baphysics_set_terminal_velocity(param_0, 133.33f);
        func_800961AC(param_0, 3);
    }
}

int func_80800174_bstntswim(param_0) s32 param_0;
{
  s32 local_0;
  local_0 = param_0 | 0;
  if (!func_8009E69C(local_0, 1))
  {
    baphysics_reset_terminal_velocity(local_0);
    baphysics_reset_gravity(local_0);
    func_800961AC(local_0, 1);
  }
  _bstnt_entrypoint_2(local_0);
}

s32 func_808001CC_bstntswim(Actor *this){
    func_8009BC34();
    func_800961AC(this, 1);
    _bstnt_entrypoint_2(this);
}

void func_80800200_bstntswim(PlayerState *param_0)
{
    f32 local_0;
    f32 local_1;

    _bstnt_entrypoint_3(param_0);
    baphysics_set_gravity(param_0, 0.0f);
    baphysics_set_terminal_velocity(param_0, -399.99f);
    func_800961AC(param_0, 3);
    func_8009BC5C(param_0, 2.0f);
    func_800A046C(param_0);
    local_0 = func_800A3298(param_0);
    baanim_playForDuration_loopSmooth(param_0, 0xE7, 0x40D00000);
    local_1 = func_800F10B4(local_0, 40.0f, 1000.0f, -300.0f, -1200.0f);
    param_0->unk16C = local_1;
    baphysics_set_vertical_velocity(param_0, local_1);
    func_8009FFD8(param_0, 1, 3, 3, 6);
}

void func_808002D0_bstntswim(PlayerState *param_0)
{
    s32 local_0 = 0;
    f32 local_1[3];
    s32 local_2;

    func_8009C128(param_0, local_1);
    local_1[1] += 60.0f;
    local_2 = func_8009FBB0(param_0, local_1, 20.0f);
    func_800BA930(local_2, -30, -30, -30, 30, 30, 30);
    func_800BA22C(local_2, 1);
    if (param_0->unk16C < 0.0f) {
        param_0->unk16C += func_800F0E00(mlAbsF(param_0->unk16C) * 0.1f, 50.0f);
        baphysics_set_vertical_velocity(param_0, param_0->unk16C);
    }
    if (player_isStable(param_0)) local_0 = 0x10F;
    if (!player_inWater(param_0)) local_0 = 0x10C;
    if (baphysics_get_vertical_velocity(param_0) >= 0.0f) local_0 = 0x10F;
    _bstnt_entrypoint_4(param_0);
    bs_setState(param_0, local_0);
}

int bstntswim_entrypoint_0(s32 param_0)
{
  return D_808009B0_bstntswim[param_0];
}

int func_8080042C_bstntswim(Actor *param_0)
{
  extern void baphysics_set_target_horizontal_velocity(Actor *a0, f32 a1);
  s32 local_0;
  int new_var;
  local_0 = param_0;
  func_80800114_bstntswim();
  baanim_playForDuration_loopSmooth(local_0 | 0, 0xE7, 0x40D00000);
  func_8009FFD8(local_0 | 0, 1, 3, 3, 2);
  yaw_setVelocityBounded(local_0 | (0 ^ 0), 0x43FA0000, 0x40A00000);
  new_var = 0;
  baphysics_set_target_horizontal_velocity(local_0 | 0, new_var);
}

void func_8080049C_bstntswim(PlayerState *param_0)
{
    s32 local_0 = 0;
    void *local_1 = baanim_getAnimCtrlPtr(param_0);

    if (!func_8001210C(7) && func_800DC0C0() < 0.5f) func_8009FC34(param_0, 1);
    if (!func_8001210C(7) && func_800DC0C0() < 0.5f) func_80800000_bstntswim(param_0);
    if (anctrl_isAt(local_1, 0.01f)) func_8009DEC0(param_0, 0x46F, 0.85f, 1.15f, 16000, 16000);
    if (bastick_getZone(param_0) == 1) local_0 = 0x110;
    if (!player_inWater(param_0)) local_0 = 0x10C;
    if (_bstnt_entrypoint_8(param_0)) local_0 = 0x10E;
    if (func_80096500(param_0) && bakey_pressed(param_0, 8)) local_0 = 0x107;
    _bstnt_entrypoint_4(param_0);
    bs_setState(param_0, local_0);
}

void func_808005FC_bstntswim()
{
    func_80800174_bstntswim();
}

int bstntswim_entrypoint_1(int param_0)
{
  return D_808009C0_bstntswim[param_0];
}

void func_80800630_bstntswim(PlayerState *param_0)
{
    func_80800114_bstntswim(param_0);
    baanim_playForDuration_loopSmooth(param_0, 0xE8, 0x3F4CCCCD);
    func_8008CA4C(param_0, 2);
    baanim_setDurationRange(param_0, 0.3f, 1.5f);
    func_8008C9F0(param_0, 30.0f, 200.0f, 0.8f, 0.45f);
    yaw_setUpdateType(param_0, 3);
    yaw_setVelocityBounded(param_0, 0x43FA0000, 0x40A00000);
    func_8009D2D8(param_0, 1);
    baphysics_set_type(param_0, 2);
}

void func_808006E4_bstntswim(s32 param_0) {
    s32 local_0;
    s32 local_1;
    s32 local_2;

    local_0 = 0;
    local_2 = baanim_getAnimCtrlPtr();
    local_1 = local_2;
    if (anctrl_isAt(local_2, 0.38f) != 0) {
        func_8009FD24(param_0, 1);
    }
    if (anctrl_isAt(local_1, 0.88f) != 0) {
        func_8009FD24(param_0, 0);
    }
    if (anctrl_isAt(local_1, 0.2f) != 0) {
        func_8009DE74(param_0, 0x40C, 0x3F666666, 0x3F8CCCCD);
    }
    if (anctrl_isAt(local_1, 0.7f) != 0) {
        func_8009DE74(param_0, 0x40C, 0x3F666666, 0x3F8CCCCD);
    }
    func_808000B0_bstntswim(param_0);
    if (bastick_getZone(param_0) == 0) {
        local_0 = 0x10F;
    }
    if (player_inWater(param_0) == 0) {
        local_0 = 0x10C;
    }
    if (_bstnt_entrypoint_8(param_0) != 0) {
        local_0 = 0x10E;
    }
    if ((func_80096500(param_0) != 0) && (bakey_pressed(param_0, 8) != 0)) {
        local_0 = 0x107;
    }
    _bstnt_entrypoint_4(param_0);
    bs_setState(param_0, local_0);
}

void func_80800830_bstntswim()
{
    func_80800174_bstntswim();
}

int bstntswim_entrypoint_2(s32 param_0)
{
  return D_808009D0_bstntswim[param_0];
}

void func_80800864_bstntswim(s32 arg0)
{
    _bsrest_entrypoint_14();
    func_80800174_bstntswim(arg0);
}
void func_8080088C_bstntswim(s32 arg0)
{
    func_80800114_bstntswim();
    _bsrest_entrypoint_16(arg0);
}
int func_808008B4_bstntswim(Actor *param_0)
{
  s32 local_0;
  local_0 = 0;
  if (_bsrest_entrypoint_20())
  {
    local_0 = 0x10F;
  }
  _bstnt_entrypoint_4(param_0);
  bs_setState(param_0, local_0);
}

int bstntswim_entrypoint_3(s32 param_0)
{
  return D_808009E0_bstntswim[param_0];
}

void func_8080090C_bstntswim(s32 arg0)
{
    func_80800114_bstntswim();
    _bsdrone_entrypoint_0(arg0);
}
void func_80800934_bstntswim(s32 arg0)
{
    _bsdrone_entrypoint_1();
    _bstnt_entrypoint_4(arg0);
}
void func_8080095C_bstntswim(s32 arg0)
{
    _bsdrone_entrypoint_2();
    func_80800174_bstntswim(arg0);
}
int bstntswim_entrypoint_4(s32 param_0)
{
  return D_808009F0_bstntswim[param_0];
}
