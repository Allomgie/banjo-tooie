// Player "time's up" states for a failed timed challenge: turn away, die camera, jingle, then
// warp back to the stored return map (after the animation, or 2.9 s in the generic variant).
#include "common.h"
#include "overlays/ba/playerstate.h"
#include "core2/anctrl.h"

extern void baanim_playForDuration_onceSmooth(PlayerState *, s32, f32);
extern void baphysics_set_target_horizontal_velocity(PlayerState *, f32);
extern f32 func_8009F308(PlayerState *);
extern void yaw_setIdeal(PlayerState *, f32);
extern void _ncbadie_entrypoint_3(s32, f32);
extern AnimCtrl *baanim_getAnimCtrlPtr();
extern void func_8009DF18(PlayerState *, s32, f32, s32);
extern void func_8009518C(PlayerState *, s32, f32);
extern s32 D_80800330_bstimeout[];
extern s32 D_80800340_bstimeout[];

void bstimeout_entrypoint_0(PlayerState *player)
{
    baanim_playForDuration_onceSmooth(player, 0x77, 3.2f);
    func_8009FFD8(player, 1, 1, 3, 2);
    baphysics_set_target_horizontal_velocity(player, 0.0f);
    func_800A4DA4(player, 10);
    yaw_setIdeal(player, func_8009F308(player) + 35.0f);
    _ncbadie_entrypoint_3(func_800A4CA8(player), 80.0f);
    func_800FC6B0(0x17);
    func_800A0CF4(player, 1);
    func_8008E944(player);
}

void bstimeout_entrypoint_1(PlayerState *player)
{
    AnimCtrl *anim_ctrl;

    anim_ctrl = baanim_getAnimCtrlPtr(player);
    if (anctrl_isAt(anim_ctrl, 0.0625f))
        func_8009514C(player);
    if (anctrl_isAt(anim_ctrl, 0.18f))
        func_8009DF18(player, 0x3EB, 1.0f, 0x4650);
    if (anctrl_isAt(anim_ctrl, 0.8421f)) {
        func_8009518C(player, 0, 0.3f);
        func_8009518C(player, 1, 0.3f);
    }
    // Warp back to the stored return map.
    if (anctrl_isAt(anim_ctrl, 0.84f))
        func_800A05DC(player);
}

void bstimeout_entrypoint_2(s32 player)
{
    func_800951B4();
    func_800A4E30(player);
}

int bstimeout_entrypoint_3(s32 index)
{
    return D_80800330_bstimeout[index];
}

void bstimeout_entrypoint_4(s32 player)
{
    s32 anim_ctrl;
    s32 anim_ctrl_ptr;
    int timer_index;
    anim_ctrl_ptr = baanim_getAnimCtrlPtr();
    anim_ctrl = anim_ctrl_ptr;
    anctrl_reset(anim_ctrl_ptr);
    func_800A0110(player, anim_ctrl);
    anctrl_setPlaybackType(anim_ctrl, 2);
    anctrl_start(anim_ctrl);
    func_8009FFD8(player, 1, 1, 3, 7);
    baphysics_set_target_horizontal_velocity(player, 0.0f);
    func_800A4DA4(player, 0xA);
    yaw_setIdeal(player, func_8009F308(player) + 35.0f);
    _ncbadie_entrypoint_3(func_800A4CA8(player), 8e+01f);
    func_800FC6B0(0x17);
    func_8008E944(player);
    // Matching: the timer index goes through a temporary.
    timer_index = 0;
    _batimer_set(player, timer_index, 0x4039999A);
}

s32 bstimeout_entrypoint_5(Actor *player)
{
    if (_batimer_decrement(player, 0)) {
        func_800A05DC(player);
    }
}

s32 bstimeout_entrypoint_6(Actor *player)
{
    func_800A0CF4(player, 0);
    func_800A4E30(player);
    func_800FC7C4();
}

int bstimeout_entrypoint_7(s32 index)
{
    return D_80800340_bstimeout[index];
}

// TU-NOTE: the overlay .data is defined here in C. The tables hold pointers to functions of this
// file; IDO's assembler schedules some of them differently unless they are in the same unit.
// Values are taken from the ROM.
extern void _bstimeout_entrypoint_2();
extern void _bstimeout_entrypoint_0();
extern void _bstimeout_entrypoint_1();
extern void func_80099AA8();
extern void _bstimeout_entrypoint_6();
extern void _bstimeout_entrypoint_4();
extern void _bstimeout_entrypoint_5();
s32 D_80800330_bstimeout[4] = {(u32) _bstimeout_entrypoint_2, (u32) _bstimeout_entrypoint_0,
                               (u32) _bstimeout_entrypoint_1, (u32) func_80099AA8};
s32 D_80800340_bstimeout[4] = {(u32) _bstimeout_entrypoint_6, (u32) _bstimeout_entrypoint_4,
                               (u32) _bstimeout_entrypoint_5, (u32) func_80099AA8};
