// Drone mode "fired": the player is probably launched on a bounce trajectory away from the
// source with a per-form yelp, and returns to the form's fall/landing state afterwards.
#include "common.h"
#include "overlays/ba/playerstate.h"

extern f32 yaw_getIdeal(PlayerState *);
extern void yaw_setIdeal(PlayerState *, f32);
extern f32 _badata_entrypoint_18(PlayerState *);
extern void func_8009DF18(PlayerState *, s32, f32, s32);
extern void baanim_playForDuration_loopSmooth(PlayerState *, s32, f32);

void bsdronefired_entrypoint_0()
{
    _babounce_entrypoint_3();
}

// Launch on a bounce trajectory facing away, with a per-form yelp.
void bsdronefired_entrypoint_1(PlayerState *player)
{
    f32 anim_duration;
    s32 anim_id;
    s32 yelp_id;

    _badata_entrypoint_7(player, &anim_id, &anim_duration);
    baanim_playForDuration_loopSmooth(player, anim_id, anim_duration);
    _babounce_entrypoint_4(player, 2);
    yaw_setIdeal(player, yaw_getIdeal(player) + 180.0f);
    yaw_applyIdeal(player);
    switch (func_800A3274(player)) {
        case 1:
        case 10:
            yelp_id = 0x420;
            break;
        case 11:
            yelp_id = 0x598;
            break;
        case 13:
            yelp_id = 0x5A3;
            break;
        default:
            return;
    }
    func_8009DF18(player, yelp_id, _badata_entrypoint_18(player) + 1.0f, 0x6D60);
}

void bsdronefired_entrypoint_2()
{
    func_80099AA8();
}

s32 bsdronefired_entrypoint_3(Actor *this)
{
    if (_babounce_entrypoint_10(this) != 0) {
        bs_setState(this, _badata_entrypoint_24(this));
    }
}
