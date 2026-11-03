#include "common.h"

extern void _badata_entrypoint_6(void *param_0, s32 *local_1, s32 *local_2, f32 *local_3,
                                 f32 *local_4);
extern void _basudie_entrypoint_1(Actor *param_0);
extern void *baanim_getAnimCtrlPtr(Actor *param_0);
extern void anctrl_reset(void *param_0);
extern void anctrl_setIndex(void *param_0, s32 param_1);
extern void anctrl_setDuration(void *param_0, s32 param_1);
extern void anctrl_setStart(void *param_0, f32 param_1);
extern void anctrl_setSubrange(void *param_0, f32 param_1, f32 param_2);
extern void anctrl_setPlaybackType(void *param_0, s32 param_1);
extern void anctrl_start(void *param_0);
extern void func_8009FFD8(Actor *param_0, s32 param_1, s32 param_2, s32 param_3, s32 param_4);
extern void func_800961AC(Actor *param_0, s32 param_1);
extern void func_800A0180(Actor *param_0);
extern void func_800A4DFC(Actor *param_0, s32 param_1);
extern void func_80098B4C(Actor *param_0, s32 param_1);
extern void func_80092880(Actor *param_0, s32 param_1);

// Sets the fall stage; stage 2 runs the shared death sequence.
int func_80800000_bsdronefalldie(Actor *player, s32 stage)
{
    if (stage == 2) {
        _basudie_entrypoint_0();
    }
    *(s32 *) ((char *) player + 0x190) = stage;
}

int bsdronefalldie_entrypoint_0(Actor *player)
{
    func_800961AC(player, 1);
    func_80092880(player, 1);
}

// Plays the fall anim, freezes the camera on the player and turns off the out-of-bounds check.
void bsdronefalldie_entrypoint_1(Actor *player)
{
    // Matching: unused local is needed for the match.
    f32 unk_0;
    f32 range_end;
    f32 range_start;
    s32 duration;
    s32 anim_id;
    void *anim_ctrl;

    _basudie_entrypoint_1(player);
    anim_ctrl = baanim_getAnimCtrlPtr(player);
    _badata_entrypoint_6(player, &anim_id, &duration, &range_start, &range_end);
    if (range_start == range_end) {
        anctrl_reset(anim_ctrl);
        anctrl_setIndex(anim_ctrl, anim_id);
        anctrl_setDuration(anim_ctrl, duration);
        anctrl_setStart(anim_ctrl, range_start);
        anctrl_setSubrange(anim_ctrl, range_start, range_end);
        anctrl_setPlaybackType(anim_ctrl, 1);
        anctrl_start(anim_ctrl);
    } else {
        anctrl_reset(anim_ctrl);
        anctrl_setIndex(anim_ctrl, anim_id);
        anctrl_setDuration(anim_ctrl, duration);
        anctrl_setSubrange(anim_ctrl, range_start, range_end);
        anctrl_setPlaybackType(anim_ctrl, 4);
        anctrl_start(anim_ctrl);
    }
    func_8009FFD8(player, 1, 1, 3, 2);
    func_800961AC(player, 6);
    func_800A0180(player);
    func_800A4DFC(player, 5);
    func_80098B4C(player, 0);
    func_80092880(player, 0);
    *(s32 *) ((char *) player + 0x190) = 0;
    func_80800000_bsdronefalldie(player, 1);
}

// Swallows interrupt 0x91.
int bsdronefalldie_entrypoint_2(Actor *player)
{
    if (func_8009E6EC(player) != 0x91) {
        func_80099AA8(player);
    }
}

// Waits for the falling sound to finish, then runs the death sequence.
void bsdronefalldie_entrypoint_3(u8 *player)
{
    s32 stage;

    stage = *(s32 *) ((s8 *) player + 0x190);
    switch (stage) {
        case 1:
            if (func_800FCCD4(_badata_entrypoint_16()) == 0) {
                func_80800000_bsdronefalldie(player, 2);
            }

        case 2:
            return;
    }
}
