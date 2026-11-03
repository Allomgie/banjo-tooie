#include "common.h"

extern void anctrl_reset(void *local_0);
extern void anctrl_setIndex(void *local_0, int index);
extern void anctrl_setDuration(void *local_0, float duration);
extern void anctrl_setPlaybackType(void *local_0, int type);
extern void anctrl_start(void *local_0);
extern void func_8008CA4C(void *param_0, int arg1);
extern void yaw_setUpdateType(void *param_0, int type);
extern void func_8009D2D8(void *param_0, int arg1);
extern void baphysics_set_type(void *param_0, int type);
extern void baphysics_set_target_horizontal_velocity(void *param_0, float velocity);
extern void func_8009BA9C(void *param_0, int arg1);
extern void *baanim_getAnimCtrlPtr();
extern void *_bahold_entrypoint_5(void *);
extern void func_800F1E6C(f32 *, f32 *, f32 *);
extern void yaw_setIdeal(void *, f32);
extern s32 anctrl_isAt(void *, f32);
extern Actor *func_80106790(void *);
extern s32 D_808002F0_bsthrow[];

void bsthrow_entrypoint_0(Actor *player)
{
    void *anim_ctrl;

    anim_ctrl = baanim_getAnimCtrlPtr();
    anctrl_reset(anim_ctrl);
    anctrl_setIndex(anim_ctrl, 0x11B);
    anctrl_setDuration(anim_ctrl, 1.0f);
    anctrl_setPlaybackType(anim_ctrl, 1);
    anctrl_start(anim_ctrl);
    func_8008CA4C(player, 1);
    yaw_setUpdateType(player, 1);
    func_8009D2D8(player, 3);
    baphysics_set_type(player, 3);
    baphysics_set_target_horizontal_velocity(player, 0);
    func_8009BA9C(player, 0);
    *(int *) ((char *) player + 0x15c) = 0;
}

void bsthrow_entrypoint_1(void *player)
{
    s32 next_state;
    void *anim_ctrl;
    f32 target_pos[3];
    f32 player_pos[3];
    f32 yaw;
    void *held;

    next_state = 0;
    anim_ctrl = baanim_getAnimCtrlPtr(player);
    held = _bahold_entrypoint_5(player);
    if (*(s32 *) ((u8 *) player + 0x15C) == 0 && held != NULL) {
        _bahold_entrypoint_6(player, held);
    }
    func_8009C128(player, player_pos);
    func_800A33CC(player, target_pos);
    func_800F1E6C(player_pos, target_pos, &yaw);
    yaw_setIdeal(player, yaw);
    // Release the held actor at 35% of the animation.
    if (anctrl_isAt(anim_ctrl, 0.35f) && held != NULL) {
        *(s32 *) ((u8 *) player + 0x15C) = 1;
        func_80106790(held)->unk64_22 = 1;
    }
    if (anctrl_isStopped(anim_ctrl)) {
        next_state = 1;
    }
    bs_setState(player, next_state);
}

void bsthrow_entrypoint_2(u8 *player)
{
    // Matching: empty block steers IDO's code generation.
    if (!player) {
    }
    *(s32 *) ((s8 *) player + 0x15C) = 0;
    if (bs_getNextState() == 1) {
        bastatetimer_set(player, 0, 0x3E0F5C29);
        bastatetimer_set(player, 1, 0x3E8F5C29);
    }
}

int bsthrow_entrypoint_3(s32 index)
{
    return D_808002F0_bsthrow[index];
}

void bsthrow_entrypoint_4(u8 *player)
{
    s32 interrupt;

    interrupt = func_8009E6EC();
    switch (interrupt) {
        case 18:
            // Not released yet: drop the held actor.
            if (*(s32 *) ((s8 *) player + 0x15C) == 0) {
                func_8008F6B8(player, func_8008E9AC(player));
                return;
            }
            func_8009E830(player, 1);
            return;
        case 21:;
        case 28:
        case 29:;
        case 30:
        case 37:
            func_8009E830(player, 1);
            return;
        default:
            func_80099B94(player);
    }
}

// TU-NOTE: the overlay .data is defined here in C. The table holds pointers to functions of this
// file; IDO's assembler schedules some of them differently unless it is in the same unit. Values
// are taken from the ROM.
extern void _bsthrow_entrypoint_2();
extern void _bsthrow_entrypoint_0();
extern void _bsthrow_entrypoint_1();
extern void _bsthrow_entrypoint_4();
s32 D_808002F0_bsthrow[4] = {(u32) _bsthrow_entrypoint_2, (u32) _bsthrow_entrypoint_0,
                             (u32) _bsthrow_entrypoint_1, (u32) _bsthrow_entrypoint_4};
