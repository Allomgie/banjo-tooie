// Player "talk" state: stop, face the conversation partner, idle until the dialog ends.
#include "common.h"

void baphysics_set_target_horizontal_velocity(s32, f32);
extern void bs_setState();
extern s32 D_80800170_bstalk[];

// Enter: stop, face the conversation partner, play idle animation.
void bstalk_entrypoint_0(u8 *player)
{
    s32 anim_ctrl;
    s32 yaw;
    f32 player_pos[3];
    f32 target_pos[3];

    anim_ctrl = baanim_getAnimCtrlPtr();
    anctrl_reset(anim_ctrl);
    func_800A0110(player, anim_ctrl);
    anctrl_setPlaybackType(anim_ctrl, 2);
    anctrl_start(anim_ctrl);
    func_8009C128(player, player_pos);
    func_800A33A0(player, target_pos);
    func_800F1E6C(player_pos, target_pos, &yaw);
    yaw_setIdeal(player, yaw);
    func_8008CA4C(player, 1);
    yaw_setUpdateType(player, 1);
    func_8009D2D8(player, 3);
    baphysics_set_type(player, 2);
    baphysics_set_target_horizontal_velocity(player, 0.0f);
    *(s32 *) ((s8 *) player + 0x15C) = 1;
}

// Update: return to the default state once the dialog has ended.
void bstalk_entrypoint_1(u8 *player)
{
    s32 done = 0;
    if (*(s32 *) (player + 0x15C) == 0) {
        done = 1;
    }
    *(s32 *) (player + 0x15C) = 0;
    bs_setState(player, done);
}

void bstalk_entrypoint_2(s32 unk_0)
{
}

int bstalk_entrypoint_3(s32 player)
{
    return D_80800170_bstalk[player];
}

// Interrupt: 8 = dialog ended.
void bstalk_entrypoint_4(u8 *player)
{
    if (func_8009E6EC() == 8) {
        *(s32 *) ((s8 *) player + 0x15C) = 1;
        func_8009E830(player, 2);
        return;
    }
    func_80099B94(player);
}

// TU-NOTE: the overlay .data table is defined here so IDO schedules the functions as in the original; values come from the ROM.
extern void _bstalk_entrypoint_2();
extern void _bstalk_entrypoint_0();
extern void _bstalk_entrypoint_1();
extern void _bstalk_entrypoint_4();
s32 D_80800170_bstalk[4] = {(u32) _bstalk_entrypoint_2, (u32) _bstalk_entrypoint_0,
                            (u32) _bstalk_entrypoint_1, (u32) _bstalk_entrypoint_4};
