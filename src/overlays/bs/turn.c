// Banjo-Kazooie skid-turn state: brakes from the previous speed, kicks up dust and snaps the yaw
// by 180 degrees on exit; jump, crouch and attack inputs can cancel it.
#include "common.h"
#include "overlays/ba/playerstate.h"
#include "core2/anctrl.h"

extern f32 yaw_get(s32);
extern f32 func_800136E4(f32);
extern void yaw_set(s32, f32);
extern void func_8009BF5C(s32, f32);
extern void baroll_setIdeal(s32, f32);
extern s32 D_80800360_bsturn[];
extern AnimCtrl *baanim_getAnimCtrlPtr();
extern f32 func_800F10B4(f32, f32, f32, f32, f32);
extern f32 func_8009BB18(PlayerState *);
extern f32 func_8009BB5C(PlayerState *);
extern void _badust_entrypoint_3(PlayerState *, f32, f32);
extern void baphysics_set_target_horizontal_velocity(PlayerState *, f32);

void bsturn_entrypoint_0(void *player)
{
    void *anim_ctrl;
    float velocity[3];

    anim_ctrl = baanim_getAnimCtrlPtr();
    anctrl_reset(anim_ctrl);
    anctrl_setIndex(anim_ctrl, 0xE);
    anctrl_setDuration(anim_ctrl, 0.3f);
    func_8008B1C8(anim_ctrl, 0.1f);
    anctrl_setPlaybackType(anim_ctrl, 1);
    anctrl_start(anim_ctrl);
    func_8008CA4C(player, 1);
    yaw_setUpdateType(player, 1);
    func_8009D2D8(player, 2);
    baphysics_set_type(player, 3);
    func_8009BB24(player, velocity);
    // Remember the horizontal speed at entry.
    *(float *) ((char *) player + 0x16C) =
        sqrtf((velocity[0] * velocity[0]) + (velocity[2] * velocity[2]));
    func_8009DEC0(player, 0x411, 0x3F733333, 0x3F866666, 0x7530, 0x7D00);
    *(int *) ((char *) player + 0x15C) = 0;
}

void bsturn_entrypoint_1(PlayerState *player)
{
    s32 next_state = 0;

    baphysics_set_target_horizontal_velocity(
        player, func_800F10B4(anctrl_getAnimTimer(baanim_getAnimCtrlPtr(player)), 0.18f, 1.0f,
                              player->unk16C, 0.0f));
    player->unk15C.word++;
    if (!((s32) player->unk15C.word < 6)) {
        player->unk15C.word = -1;
    }
    // Dust puffs on alternating frames.
    switch ((s32) player->unk15C.word) {
        case -1:
            _badust_entrypoint_3(player, func_8009BB18(player) - 10.0f,
                                 func_8009BB5C(player) * 0.88f);
            break;
        case 0:
            _badust_entrypoint_3(player, func_8009BB18(player), func_8009BB5C(player));
            break;
        case 1:
            _badust_entrypoint_3(player, func_8009BB18(player) + 10.0f,
                                 func_8009BB5C(player) * 0.88f);
    }
    if (anctrl_isStopped(baanim_getAnimCtrlPtr(player)))
        next_state = 4;
    if (bakey_held(player, 1))
        next_state = 7;
    if (bakey_pressed(player, 9))
        next_state = func_800A055C(player, next_state);
    if (bakey_pressed(player, 8))
        next_state = bs_getTypeOfJump(player);
    bs_setState(player, next_state);
}

// Snap yaw by 180 degrees.
void bsturn_entrypoint_2(s32 player)
{
    yaw_set(player, func_800136E4(yaw_get(player) - 180.0f));
    func_8009BF5C(player, 0.0f);
    baroll_setIdeal(player, 0.0f);
}

int bsturn_entrypoint_3(s32 index)
{
    return D_80800360_bsturn[index];
}

// TU-NOTE: the overlay .data is defined here in C. The table holds pointers to functions of this
// file; IDO's assembler schedules some of them differently unless it is in the same unit. Values
// are taken from the ROM.
extern void _bsturn_entrypoint_2();
extern void _bsturn_entrypoint_0();
extern void _bsturn_entrypoint_1();
extern void func_8009AB78();
s32 D_80800360_bsturn[4] = {(u32) _bsturn_entrypoint_2, (u32) _bsturn_entrypoint_0,
                            (u32) _bsturn_entrypoint_1, (u32) func_8009AB78};
