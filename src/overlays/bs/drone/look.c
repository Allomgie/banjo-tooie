#include "common.h"
#include "overlays/ba/playerstate.h"

extern f32 func_800F0E00(f32, f32);
extern f32 func_800F13F0(f32, f32);
extern void baanim_playForDuration_loopSmooth(PlayerState *, s32, f32);
extern void baphysics_set_target_horizontal_velocity(PlayerState *, f32);

int bsdronelook_entrypoint_0(int player)
{
    if (_bafpctrl_entrypoint_4() == 2) {
        _bafpctrl_entrypoint_13(player | 0, 1);
    }
    // Matching: the | 0 on the arguments and the empty if below are needed for the match.
    if (_bafpctrl_entrypoint_6(player | 0)) {
        func_800A4EC8(player | 0);
        _bafpctrl_entrypoint_17(player | 0);
    }
    if (player) {
    }
}

// Forced first-person look: play the look anim, stop moving.
void bsdronelook_entrypoint_1(PlayerState *player)
{
    f32 anim_duration;
    s32 anim_id;

    _badata_entrypoint_3(player, &anim_id, &anim_duration);
    baanim_playForDuration_loopSmooth(player, anim_id, anim_duration);
    func_8009FFD8(player, 1, 1, 3, 2);
    baphysics_set_target_horizontal_velocity(player, 0.0f);
    func_8009BA9C(player, 0);
    if (_bafpctrl_entrypoint_4(player) != 3) {
        func_800A4E94(player);
        switch (func_800A3274(player)) {
            case 2:
            case 8:
            case 10:
            case 13:
            case 14:
            case 15:
            case 16:
            case 17:
            case 18:
            case 19:
                _bafpctrl_entrypoint_11(player, 4, 1);
        }
        _bafpctrl_entrypoint_16(player, 3);
    }
}

// First-person pitch clamp (-65..70 degrees), also used by egg aiming and fpctrl.
f32 bsdronelook_entrypoint_2(f32 pitch)
{
    if (pitch > 180.0f) {
        return func_800F0E00(292.0f, pitch);
    }
    if (pitch < -65.0f) {
        return func_800F0E00(-65.0f, pitch);
    }
    return func_800F13F0(70.0f, pitch);
}

int bsdronelook_entrypoint_3(Actor *player)
{
    s32 next_state;
    next_state = 0;
    if (_bafpctrl_entrypoint_4() != 3 && !func_800A3404(player)) {
        next_state = _badata_entrypoint_34(player);
    }
    bs_setState(player, next_state);
}

int bsdronelook_entrypoint_4()
{
    func_80099B94();
}
