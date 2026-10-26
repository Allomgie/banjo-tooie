#include "common.h"
#include "overlays/ba/playerstate.h"

extern void baanim_playForDuration_onceSmooth(PlayerState *, s32, f32);
extern void baphysics_set_target_horizontal_velocity(PlayerState *, f32);
extern void _ncbadie_entrypoint_3(s32, f32);
extern void _batimer_set(PlayerState *, s32, f32);
extern void func_800951B4(s32);
extern void func_8009BF5C(s32, f32);
extern void baroll_setIdeal(s32, f32);
extern void func_800A4E30(s32);
extern s32 D_808002B0_bschokedie[];

void bschokedie_entrypoint_0(PlayerState *param_0)
{
    baanim_playForDuration_onceSmooth(param_0, 0xF0, 4.2f);
    func_8009FFD8(param_0, 1, 1, 2, 3);
    func_8009BA9C(param_0, 0);
    baphysics_set_target_horizontal_velocity(param_0, 0.0f);
    func_800A4DFC(param_0, 10);
    _ncbadie_entrypoint_3(func_800A4CA8(param_0), 30.0f);
    func_800A0180(param_0);
    _batimer_set(param_0, 0, 3.8f);
    func_8008E944(param_0);
    func_80090A0C(param_0);
    _basudie_entrypoint_1(param_0);
}

void bschokedie_entrypoint_1(s32 param_0) {
    if (baanim_isAt(param_0, 0x3ECCCCCD) != 0) {
        func_80090A2C(param_0);
    }
    if (baanim_isAt(param_0, 0x3F147AE1) != 0) {
        func_8009514C(param_0);
    }
    if (baanim_isAt(param_0, 0x3D4CCCCD) != 0) {
        func_8009DF18(param_0, 0x574, 0x3F800000, 0x7FFF);
    }
    if (baanim_isAt(param_0, 0x3E4CCCCD) != 0) {
        func_8009DF18(param_0, 0x575, 0x3F800000, 0x7FFF);
    }
    if (baanim_isAt(param_0, 0x3ECCCCCD) != 0) {
        func_8009DF18(param_0, 0x576, 0x3F800000, 0x7FFF);
    }
    if (baanim_isAt(param_0, 0x3F28F5C3) != 0) {
        func_8009DF18(param_0, 0x577, 0x3F800000, 0x7FFF);
    }
    if (baanim_isAt(param_0, 0x3F19930C) != 0) {
        func_8009DF94(param_0, 0x417, 0x3F99999A, 0x3E80);
    }
    if (baanim_isAt(param_0, 0x3F4A0275) != 0) {
        func_8009DF94(param_0, 0x417, 0x3F666666, 0x4E20);
    }
    if (baanim_isAt(param_0, 0x3F6DD97F) != 0) {
        func_8009DF94(param_0, 0x417, 0x3FB33333, 0x2328);
    }
    if (_batimer_decrement(param_0, 0) != 0) {
        _basudie_entrypoint_0(param_0);
    }
}

void bschokedie_entrypoint_2(s32 param_0) {
    func_800951B4(param_0);
    func_8009BF5C(param_0, 0.0f);
    baroll_setIdeal(param_0, 0.0f);
    func_800A4E30(param_0);
}

int bschokedie_entrypoint_3(s32 param_0)
{
  return D_808002B0_bschokedie[param_0];
}
