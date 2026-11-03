#include "common.h"
#include "overlays/ba/playerstate.h"
extern void baphysics_set_target_horizontal_velocity(Actor *a0, f32 a1);
extern void func_8009D658(Actor *a0);

extern f32 yaw_get(PlayerState *);
extern f32 func_800136E4(f32);
extern void baphysics_set_target_yaw(PlayerState *, f32);
extern f32 bastick_distance(PlayerState *);
extern f32 bastick_getAngleRelativeToBanjo(PlayerState *);
extern f32 func_800F1DCC(f32, f32);
extern f32 func_800F0DC0(f32, f32);
extern f32 func_8009BB18(PlayerState *);
extern f32 func_800D8FF8(void);
extern void func_800A4DA4(PlayerState *, s32);
extern f32 func_800F10B4(f32, f32, f32, f32, f32);
extern void yaw_setIdeal(void *, f32);
extern void func_8009BF5C(void *, f32);

int func_80800000_bsdroneslide(Actor *player, s32 anim_id, f32 anim_duration)
{
    extern void baanim_playForDuration_loopSmooth(Actor * a0, s32 a1, f32 a2);
    extern void func_8009BFE4(Actor * a0, s32 a1, s32 a2);
    extern void func_8009FFD8(Actor * a0, s32 a1, s32 a2, s32 a3, s32 a4);
    baanim_playForDuration_loopSmooth(player, anim_id, anim_duration);
    func_8009FFD8(player, 1, 1, 3, 3);
    func_8009BFE4(player, 0x44480000, 0x41000000);
    baphysics_set_target_horizontal_velocity(player, 0);
    func_8009D658(player);
    _batimer_set(player, 10, 0x3F800000);
}

void func_80800080_bsdroneslide(Actor *player, s32 facing)
{
    f32 anim_duration;
    s32 anim_id;

    switch (facing) {
        case 1:
            _badata_entrypoint_13(player, &anim_id, &anim_duration);
            func_80800000_bsdroneslide(player, anim_id, anim_duration);
            break;
        case 2:
            _badata_entrypoint_12(player, &anim_id, &anim_duration);
            func_80800000_bsdroneslide(player, anim_id, anim_duration);
    }
    *(s8 *) ((char *) player + 0x190) = (s8) facing;
}

int func_80800110_bsdroneslide(s32 player, s32 slope_angle, s32 slope_yaw)
{
    f32 normal[3];
    func_800963C0(player, normal);
    func_800F1988(normal, slope_angle, slope_yaw);
}

// Start sliding: face up or down the slope depending on the player yaw.
void bsdroneslide_entrypoint_0(PlayerState *player)
{
    f32 yaw_diff;
    s32 slope_angle;
    f32 slope_yaw;
    s32 facing;
    *((u8 *) player + 0x190) = 0;
    facing = 1;
    if (func_8008E148(player)) {
        func_80800110_bsdroneslide(player, &slope_angle, &slope_yaw);
        yaw_diff = func_800136E4(yaw_get(player) - slope_yaw);
        if (yaw_diff < 90.0f || yaw_diff > 270.0f)
            facing = 2;
        baphysics_set_target_yaw(player, slope_yaw);
    }
    func_80800080_bsdroneslide(player, facing);
}

// Steer the slide yaw with the stick (max 60 degrees).
void func_808001F4_bsdroneslide(PlayerState *player, f32 slope_yaw)
{
    f32 stick_angle;
    f32 steer;
    f32 target_yaw;

    if (bastick_distance(player) != 0.0f) {
        stick_angle = bastick_getAngleRelativeToBanjo(player);
        slope_yaw += func_800F0DC0(func_800F1DCC(stick_angle, slope_yaw), 60.0f);
    }
    target_yaw = func_8009BB18(player);
    steer = func_800F1DCC(slope_yaw, target_yaw);
    steer *= func_800D8FF8();
    target_yaw += steer;
    // Matching: the empty if blocks are needed for the match.
    if (1) {
    }
    if (1) {
    }
    baphysics_set_target_yaw(player, target_yaw);
    func_800A4DA4(player, 8);
}

void bsdroneslide_entrypoint_1(void *player)
{
    s32 next_state;
    f32 slope_yaw;
    f32 slope_angle;
    next_state = 0;
    func_8009D658(player);
    _batimer_decrement(player, 10);
    if (func_8008E148(player)) {
        if (func_80800110_bsdroneslide(player, &slope_angle, &slope_yaw)) {
            if (*((u8 *) player + 0x190) == 1) {
                yaw_setIdeal(player, slope_yaw + 180.0f);
                func_8009BF5C(player, -slope_angle);
            } else {
                yaw_setIdeal(player, slope_yaw);
                func_8009BF5C(player, slope_angle);
            }
            baphysics_set_target_horizontal_velocity(
                player, func_800F10B4(slope_angle, 20.0f, 60.0f, 550.0f, 700.0f));
            func_808001F4_bsdroneslide(player, slope_yaw);
        } else
            baphysics_set_target_horizontal_velocity(player, 500.0f);
        _badust_entrypoint_7(player);
    } else
        next_state = _badata_entrypoint_24(player);
    if (player_inWater(player))
        next_state = _badata_entrypoint_24(player);
    if (_batimer_isZero(player, 10) && bakey_pressed(player, 8))
        next_state = _badata_entrypoint_25(player);
    bs_setState(player, next_state);
}

s32 bsdroneslide_entrypoint_2(Actor *this)
{
    Actor *actor;
    func_8009BF5C(this, 0);
    // Matching: extra copy of this is needed for the match.
    actor = this;
    func_800A4E30(actor);
}
