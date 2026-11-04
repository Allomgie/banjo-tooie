// Probably the choking death: Banjo-Kazooie cough and collapse, then the shared death sequence.
// TU-NOTE: the .data of this overlay is defined in this file; its table points to functions here,
// and IDO schedules some of them differently unless they share a unit. Values come from the ROM.
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

// Init: cough animation, death camera zoom, 3.8 s until the death sequence.
void bschokedie_entrypoint_0(PlayerState *player)
{
    baanim_playForDuration_onceSmooth(player, 0xF0, 4.2f);
    func_8009FFD8(player, 1, 1, 2, 3);
    func_8009BA9C(player, 0);
    baphysics_set_target_horizontal_velocity(player, 0.0f);
    func_800A4DFC(player, 10);
    _ncbadie_entrypoint_3(func_800A4CA8(player), 30.0f);
    func_800A0180(player);
    _batimer_set(player, 0, 3.8f);
    func_8008E944(player);
    func_80090A0C(player);
    _basudie_entrypoint_1(player);
}

// Update: sounds and component toggles on anim marks, then the death sequence.
void bschokedie_entrypoint_1(s32 player)
{
    if (baanim_isAt(player, 0x3ECCCCCD) != 0) {
        func_80090A2C(player);
    }
    if (baanim_isAt(player, 0x3F147AE1) != 0) {
        func_8009514C(player);
    }
    if (baanim_isAt(player, 0x3D4CCCCD) != 0) {
        func_8009DF18(player, 0x574, 0x3F800000, 0x7FFF);
    }
    if (baanim_isAt(player, 0x3E4CCCCD) != 0) {
        func_8009DF18(player, 0x575, 0x3F800000, 0x7FFF);
    }
    if (baanim_isAt(player, 0x3ECCCCCD) != 0) {
        func_8009DF18(player, 0x576, 0x3F800000, 0x7FFF);
    }
    if (baanim_isAt(player, 0x3F28F5C3) != 0) {
        func_8009DF18(player, 0x577, 0x3F800000, 0x7FFF);
    }
    if (baanim_isAt(player, 0x3F19930C) != 0) {
        func_8009DF94(player, 0x417, 0x3F99999A, 0x3E80);
    }
    if (baanim_isAt(player, 0x3F4A0275) != 0) {
        func_8009DF94(player, 0x417, 0x3F666666, 0x4E20);
    }
    if (baanim_isAt(player, 0x3F6DD97F) != 0) {
        func_8009DF94(player, 0x417, 0x3FB33333, 0x2328);
    }
    if (_batimer_decrement(player, 0) != 0) {
        _basudie_entrypoint_0(player);
    }
}

void bschokedie_entrypoint_2(s32 player)
{
    func_800951B4(player);
    func_8009BF5C(player, 0.0f);
    baroll_setIdeal(player, 0.0f);
    func_800A4E30(player);
}

int bschokedie_entrypoint_3(s32 index)
{
    return D_808002B0_bschokedie[index];
}

extern void _bschokedie_entrypoint_2();
extern void _bschokedie_entrypoint_0();
extern void _bschokedie_entrypoint_1();
extern void _basudie_entrypoint_11();
s32 D_808002B0_bschokedie[4] = {(u32) _bschokedie_entrypoint_2, (u32) _bschokedie_entrypoint_0,
                                (u32) _bschokedie_entrypoint_1, (u32) _basudie_entrypoint_11};
