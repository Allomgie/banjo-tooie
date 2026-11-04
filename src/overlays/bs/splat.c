// Banjo-Kazooie hard landing ("splat") after a long fall: applies fall damage (helper reused by
// Kazooie flight and Mumbo), dust and camera shake, flop and get-up, then idle, fall, water, death.
#include "common.h"
#include "overlays/ba/playerstate.h"

extern void func_800954E8(PlayerState *, s32 *);
extern void func_8009DB04(PlayerState *, s32, f32, s32);
extern void baanim_playForDuration_once(PlayerState *, s32, f32);
extern void func_8009DF18(PlayerState *, s32, f32, s32);
extern void *baanim_getAnimCtrlPtr(PlayerState *);
extern f32 baphysics_get_target_horizontal_velocity(PlayerState *);
extern f32 func_800F0E00(f32, f32);
extern void baphysics_set_target_horizontal_velocity(PlayerState *, f32);
extern s32 anctrl_isAt(void *, f32);
extern void baanim_playForDuration_onceSmooth(PlayerState *, s32, f32);
extern s32 D_808002B0_bssplat[];

// Fall damage, dust and camera shake; also used by Kazooie flight and Mumbo.
void bssplat_entrypoint_0(PlayerState *player)
{
    s32 damage;
    func_800954E8(player, &damage);
    func_800A17A8(player, -damage);
    // Matching: both branches are identical but the branch is needed for the match.
    if (func_80096694(player) == 3) {
        func_8009DB04(player, 0x417, 0.8f, 0x7FFF);
    } else {
        func_8009DB04(player, 0x417, 0.8f, 0x7FFF);
    }
    _badust_entrypoint_8(player);
    _bashake_entrypoint_0(player, 3, 2);
}

// Enter: flop animation.
void func_8080009C_bssplat(PlayerState *player)
{
    baanim_playForDuration_once(player, 0x46, 1.1f);
    func_8009FFD8(player, 1, 1, 3, 3);
    bssplat_entrypoint_0(player);
    func_8009DF18(player, 0x427, 1.0f, 0x6D60);
    player->unk15C.word = 0;
    func_8008E944(player);
}

// Update: slow down, get up, then pick the next state.
void func_80800114_bssplat(PlayerState *player)
{
    s32 next_state = 0;
    void *anim_ctrl = baanim_getAnimCtrlPtr(player);

    baphysics_set_target_horizontal_velocity(
        player, func_800F0E00(0.0f, baphysics_get_target_horizontal_velocity(player) - 15.0f));
    switch (*(s32 *) ((u8 *) player + 0x15C)) {
        case 0:
            if (baphysics_get_target_horizontal_velocity(player) > 140.0f)
                _badust_entrypoint_9(player);
            if (func_8008DD04(player))
                next_state = 0x2F;
            if (anctrl_isStopped(anim_ctrl)) {
                baanim_playForDuration_onceSmooth(player, 0xD2, 2.25f);
                *(s32 *) ((u8 *) player + 0x15C) = 1;
            }
            break;
        case 1:
            if (anctrl_isAt(anim_ctrl, 0.63f))
                next_state = 0x20;
            if (anctrl_isStopped(anim_ctrl))
                next_state = 1;
            if (func_8008DD04(player))
                next_state = 0x2F;
    }
    if (!player_isStable(player) && player_inWater(player))
        next_state = 0x2D;
    if (!func_800A1718(player))
        next_state = 0x41;
    bs_setState(player, next_state);
}

// Exit.
void func_80800274_bssplat(s32 player)
{
    func_8008E95C();
    func_8009BD88(player);
}

int bssplat_entrypoint_1(s32 index)
{
    return D_808002B0_bssplat[index];
}

// TU-NOTE: this table is defined in C; IDO schedules some functions differently unless it is in the same unit.
extern void func_80099AA8();
s32 D_808002B0_bssplat[4] = {(u32) func_80800274_bssplat, (u32) func_8080009C_bssplat,
                             (u32) func_80800114_bssplat, (u32) func_80099AA8};
