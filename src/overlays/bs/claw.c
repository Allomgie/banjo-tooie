// TU-NOTE: the .data of this overlay is defined in this file; its table points to functions here,
// and IDO schedules some of them differently unless they share a unit. Values come from the ROM.
#include "common.h"
#include "overlays/ba/playerstate.h"
#include "core2/anctrl.h"
#include "overlays/ba/timer.h"
#include "overlays/ba/yaw.h"
#include "core2/1E76CC0.h"

extern s32 D_80800400_bsclaw[];
extern void baanim_playForDuration_onceSmooth(PlayerState *, s32, f32);
extern void baphysics_set_target_yaw(PlayerState *, f32);
extern void baphysics_set_target_horizontal_velocity(PlayerState *, f32);
extern void func_8009E55C(PlayerState *, s32, f32);
extern AnimCtrl *baanim_getAnimCtrlPtr(PlayerState *);
extern void baphysics_set_horizontal_velocity(PlayerState *, f32, f32);

// End.
int bsclaw_entrypoint_0(Actor *player)
{
    func_8009E474();
    func_800C6DA0(0x47);
    baflag_clear(player, 0x1F);
    func_800A0CF4(player, 0);
}

// Init: the combo window (0.24 s) only opens if ability 0x32 is learned.
void bsclaw_entrypoint_1(PlayerState *player)
{
    f32 combo_window;

    baanim_playForDuration_onceSmooth(player, 5, 1.4f);
    func_8009FFD8(player, 1, 1, 1, 2);
    baphysics_set_target_yaw(player, yaw_getIdeal(player));
    baphysics_set_target_horizontal_velocity(player, 80.0f);
    baflag_clear(player, 0x1F);
    func_800A0CF4(player, 1);
    if (func_800C6E38(0x32))
        combo_window = 0.24f;
    else
        combo_window = 0.0f;
    _batimer_set(player, 0, combo_window);
    func_8009E4AC(player);
    func_8009E5A4(player, 2, 3);
    func_8009E55C(player, 2, 40.0f);
}

// Update: three swipe windows set attack flag 0x1F; B again in the window chains into state 0x189.
void bsclaw_entrypoint_2(PlayerState *player)
{
    AnimCtrl *anim_ctrl;
    s32 next_state;
    f32 anim_time;

    anim_ctrl = baanim_getAnimCtrlPtr(player);
    next_state = 0;
    anim_time = anctrl_getAnimTimer(anim_ctrl);
    if ((_batimer_get(player, 0) != 0.0f) && (bakey_pressed(player, 9) != 0)) {
        next_state = 0x189;
    }
    _batimer_decrement(player, 0);
    if (anctrl_isAt(anim_ctrl, 0.512899995f)) {
        baphysics_set_horizontal_velocity(player, yaw_get(player), 360.0f);
    }
    if (anctrl_isAt(anim_ctrl, 0.653900027f) != 0) {
        baphysics_set_target_horizontal_velocity(player, 0);
    }
    if ((anctrl_isAt(anim_ctrl, 0.148800001f) != 0) ||
        ((anim_time > 0.0488f) && (anim_time < 0.24880001f)) ||
        (anctrl_isAt(anim_ctrl, 0.328799993f) != 0) || ((anim_time > 0.2288f) && (anim_time < 0.4288f)) ||
        (anctrl_isAt(anim_ctrl, 0.578800023f) != 0) ||
        ((anim_time > 0.47880003f) && (anim_time < 0.67880005f))) {
        baflag_set(player, 0x1F);
    } else {
        baflag_clear(player, 0x1F);
    }
    if (anctrl_isAt(anim_ctrl, 0.578800023f) != 0) {
        baphysics_set_target_horizontal_velocity(player, 0);
    }
    if (anctrl_isAt(anim_ctrl, 0.118799999f) != 0) {
        func_8009DE38(player, 0x442C, 1.13f);
    }
    if (anctrl_isAt(anim_ctrl, 0.288800001f) != 0) {
        func_8009DE38(player, 0x442C, 1.10000002f);
    }
    if (anctrl_isAt(anim_ctrl, 0.5f) != 0) {
        func_8009DE38(player, 0x442C, 1.32000005f);
    }
    if (anctrl_isStopped(anim_ctrl) != 0) {
        next_state = 1;
    }
    if (player_inWater(player) != 0) {
        next_state = 0x4C;
    }
    if (bakey_pressed(player, 8) != 0) {
        next_state = bs_getTypeOfJump(player);
    }
    bs_setState(player, next_state);
}

int bsclaw_entrypoint_3(s32 index)
{
    return D_80800400_bsclaw[index];
}

extern void _bsclaw_entrypoint_0();
extern void _bsclaw_entrypoint_1();
extern void _bsclaw_entrypoint_2();
extern void func_80099B94();
s32 D_80800400_bsclaw[4] = {(u32) _bsclaw_entrypoint_0, (u32) _bsclaw_entrypoint_1,
                            (u32) _bsclaw_entrypoint_2, (u32) func_80099B94};
