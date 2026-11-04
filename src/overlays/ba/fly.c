// Shared flight helpers (PlayerState+0x8C) for Banjo-Kazooie, Kazooie, bee flight and glide:
// aiming, height-dependent physics, stick steering, take-off and crash launches, landing,
// red-feather check and first-person toggle.

#include "common.h"
#include "playerstate.h"
#include "core2/anctrl.h"

extern void _baeggfire_entrypoint_3(PlayerState *, f32 *, f32 *);
extern void func_800EF334(f32 *, f32);
extern void *func_800A4C48(PlayerState *);
extern f32 bastick_getX(PlayerState *);
extern void yaw_setVelocityBounded(PlayerState *, f32, f32);
extern void baroll_setIdeal(PlayerState *, f32);
extern f32 yaw_getIdeal(PlayerState *);
extern void yaw_setIdeal(PlayerState *, f32);
extern f32 _bafpctrl_entrypoint_3(PlayerState *);
extern f32 func_800F10B4(f32, f32, f32, f32, f32);
extern f32 bastick_getY(PlayerState *);
extern void func_8009BF5C(PlayerState *, f32);
extern void _suinv_entrypoint_0(s32 *, s32, s32, s32, s32);
extern void func_8009C128(PlayerState *, f32 *);
extern void func_800E1610(s32, f32, f32, f32 *);
extern void baanim_playForDuration_once(PlayerState *, s32, f32);
extern void func_800A32C4(PlayerState *, f32 *);
extern void func_800F1E6C(f32 *, f32 *, f32 *);
extern f32 func_800136E4(f32);
extern void baphysics_set_target_horizontal_velocity(PlayerState *, f32);
extern void baphysics_set_target_yaw(PlayerState *, f32);
extern f32 baphysics_get_target_horizontal_velocity(PlayerState *);
extern void baphysics_set_horizontal_velocity(PlayerState *, f32, f32);
extern void baphysics_set_vertical_velocity(PlayerState *, f32);
extern void baphysics_set_gravity(PlayerState *, f32);
extern void _ncbafly_entrypoint_4(void *, f32, f32, f32);
extern AnimCtrl *baanim_getAnimCtrlPtr(PlayerState *);
extern f32 func_8009BFCC(PlayerState *);
extern f32 yaw_get(PlayerState *);
extern void baphysics_set_terminal_velocity(PlayerState *, f32);
extern f32 mlAbsF(f32);
extern f32 func_800F1DCC(f32, f32);
extern void func_80110818(void *, f32 *);
extern void func_800C31DC(u8, f32);
extern void func_800C3058(u8, s32);
extern s32 func_800C3D78(u8);
extern void func_800C301C(u8, s32);
extern void func_800C330C(u8, s32);
extern void func_800C3BDC(u8);
extern void _bamotor_entrypoint_1(PlayerState *, f32, f32, f32);
extern void func_8009BFE4(PlayerState *, f32, f32);

// Flight data size.
s32 bafly_entrypoint_0()
{
    return 0x10;
}

// Aim vector for shooting while flying.
void bafly_entrypoint_1(PlayerState *state, f32 *aim, s32 *unk_2, f32 unk_3)
{
    f32 unk_0[3];
    if (baflag_isTrue(state, 0x30)) {
        _baeggfire_entrypoint_3(state, unk_0, aim);
        func_800EF334(aim, unk_3);
        func_800CA9D8(func_800A4C48(state), unk_2);
    } else {
        func_800CA740(func_800A4C48(state), aim);
        func_800EF334(aim, unk_3);
        func_800CA9D8(func_800A4C48(state), unk_2);
    }
}

int bafly_entrypoint_2(Actor *actor)
{
    int status;
    if (!player_isStable()) {
        return 0;
    }
    status = func_80096628(actor);
    if (!(status << 11 >= 0)) {
        return 0;
    }
    return 1;
}

s32 bafly_entrypoint_3(s32 state)
{
    return ((u8 *) *(u8 **) (state + 0x8c))[8];
}

// Stop the looping sfx.
void bafly_entrypoint_4(u8 *state)
{
    short sfx_handle;
    sfx_handle = *(u8 *) ((s8 *) *(u8 **) ((s8 *) state + 0x8C) + 9);
    if (sfx_handle != 0) {
        func_800C2FDC(sfx_handle & 0xFF, sfx_handle, state);
        *(s8 *) ((s8 *) *(u8 **) ((s8 *) state + 0x8C) + 9) = 0;
    }
}

// Init flight data; red feathers are unlimited in the Balloon Burst maps.
void bafly_entrypoint_5(u8 *state)
{
    s32 map;

    if (_gcstatusDll_entrypoint_11() >= 2) {
        *(u8 *) ((s8 *) *(u8 **) ((s8 *) state + 0x8C) + 9) = 0U;
    } else {
        *(u8 *) ((s8 *) *(u8 **) ((s8 *) state + 0x8C) + 9) = func_800C2E04();
        func_800C3418(*(u8 *) ((s8 *) *(u8 **) ((s8 *) state + 0x8C) + 9), 0);
    }
    *(f32 *) ((s8 *) *(u8 **) ((s8 *) state + 0x8C) + 4) = 1.0f;
    *(f32 *) ((s8 *) *(u8 **) ((s8 *) state + 0x8C) + 0) = 0.0f;
    *(s8 *) ((s8 *) *(u8 **) ((s8 *) state + 0x8C) + 8) = 0;
    map = func_800EA05C();
    if ((map != 0xE4) && (map != 0x17B)) {
        *(s8 *) ((s8 *) *(u8 **) ((s8 *) state + 0x8C) + 0xE) = 0;
        return;
    }
    *(s8 *) ((s8 *) *(u8 **) ((s8 *) state + 0x8C) + 0xE) = 1;
}

void bafly_entrypoint_6(s32 state, f32 unk_1)
{
    *(f32 *) (*(s32 *) (state + 0x8c) + 0x0) = unk_1;
}

void bafly_entrypoint_7(void *state, s32 flag)
{
    ((s8 *) *(void **) ((char *) state + 0x8C))[8] = flag;
}

// Height-dependent gravity, terminal velocity and speed near the flight ceiling.
void bafly_entrypoint_8(PlayerState *state, f32 hard_ceiling, f32 soft_ceiling, f32 speed, f32 gravity,
                        f32 terminal_velocity, f32 ceiling_gravity, f32 ceiling_terminal_velocity)
{
    f32 unk_0[3];
    f32 height;
    f32 target_speed;
    height = func_8009BFCC(state);
    baphysics_set_gravity(state, gravity);
    bafly_entrypoint_6(state, 0.0f);
    if (baflag_isTrue(state, 9)) {
        baphysics_set_terminal_velocity(state, 0.0f);
        func_8009BA9C(state, 0);
        target_speed = 0.0f;
    } else if (height <= soft_ceiling) {
        baphysics_set_terminal_velocity(
            state, func_800F10B4(height, soft_ceiling - 20.0f, soft_ceiling, terminal_velocity, ceiling_terminal_velocity));
        baphysics_set_gravity(state,
                              func_800F10B4(height, soft_ceiling - 20.0f, soft_ceiling, gravity, ceiling_gravity));
        target_speed = func_800F10B4(height, soft_ceiling - 20.0f, soft_ceiling, speed, speed / 10.0f);
        bafly_entrypoint_6(state, func_800F10B4(height, soft_ceiling - 20.0f, soft_ceiling, 0.0f, 0.35f));
    } else {
        baphysics_set_terminal_velocity(
            state, func_800F10B4(height, hard_ceiling, hard_ceiling + 10.0f, -399.99f, terminal_velocity));
        target_speed = func_800F10B4(height, hard_ceiling, hard_ceiling + 40.0f, 0.0f, speed);
        bafly_entrypoint_6(state, func_800F10B4(height, hard_ceiling, hard_ceiling + 40.0f, -0.25f, 0.0f));
    }
    func_80096394(state, unk_0);
    if (func_8009650C(state) && unk_0[1] > -1.0f)
        target_speed = 0.0f;
    baphysics_set_target_yaw(state, yaw_get(state));
    baphysics_set_target_horizontal_velocity(state, target_speed);
}

// Stick X to roll and yaw.
void bafly_entrypoint_9(PlayerState *state)
{
    f32 yaw_delta;
    f32 turn_rate;
    f32 max_roll;
    f32 stick_x;
    stick_x = bastick_getX(state);
    if (bakey_held(state, 3)) {
        yaw_setVelocityBounded(state, 500.0f, 30.0f);
        turn_rate = 6.0f;
        max_roll = 85.0f;
    } else {
        yaw_setVelocityBounded(state, 500.0f, 2.0f);
        turn_rate = 3.0f;
        max_roll = 75.0f;
    }
    baroll_setIdeal(state, func_800F10B4(stick_x, -1.0f, 1.0f, -max_roll, max_roll));
    yaw_delta = func_800F10B4(stick_x, -1.0f, 1.0f, turn_rate, -turn_rate);
    yaw_delta *= _bafpctrl_entrypoint_3(state);
    yaw_setIdeal(state, yaw_getIdeal(state) + yaw_delta);
}

// Stick Y to pitch.
void bafly_entrypoint_10(PlayerState *state, f32 pitch_neg, f32 pitch_pos)
{
    f32 stick_y;
    stick_y = bastick_getY(state);
    if (stick_y < 0.0f) {
        func_8009BF5C(state, func_800F10B4(stick_y, -1.0f, 0.0f, pitch_neg, 360.0f));
    } else {
        func_8009BF5C(state, func_800F10B4(stick_y, 0.0f, 1.0f, 0.0f, pitch_pos));
    }
}

void bafly_entrypoint_11(PlayerState *state)
{
    u8 sfx_handle;
    f32 delta;
    f32 target;
    f32 unk_0[3];
    target = 1.2f;
    if ((*(u8 **) ((u8 *) state + 0x8C))[8])
        target += 0.4f;
    func_80110818((void *) func_800A4CA8(state), unk_0);
    delta = func_800F1DCC(unk_0[1] + 180.0f, yaw_get(state));
    target -= func_800F10B4(mlAbsF(delta), 0.0f, 50.0f, 0.0f, 0.4f);
    target += *(f32 *) *(u8 **) ((u8 *) state + 0x8C);
    delta = target - *(f32 *) (*(u8 **) ((u8 *) state + 0x8C) + 4);
    if (mlAbsF(delta) > 0.01f) {
        if (delta > 0.0f)
            delta = 0.01f;
        else
            delta = -0.01f;
    }
    *(f32 *) (*(u8 **) ((u8 *) state + 0x8C) + 4) += delta;
    sfx_handle = (*(u8 **) ((u8 *) state + 0x8C))[9];
    if (sfx_handle) {
        func_800C31DC(sfx_handle, *(f32 *) (*(u8 **) ((u8 *) state + 0x8C) + 4));
        func_800C31DC(sfx_handle, *(f32 *) (*(u8 **) ((u8 *) state + 0x8C) + 4));
        func_800C3058(sfx_handle, 6000);
        if (!func_800C3D78(sfx_handle)) {
            func_800C301C(sfx_handle, 0x4A3);
            func_800C330C(sfx_handle, 3);
            func_800C3BDC(sfx_handle);
        }
    }
}

// Has red feathers (always true in the Balloon Burst maps).
s32 bafly_entrypoint_12(u8 *state)
{
    s32 count;
    if ((*(u8 **) (state + 0x8C))[0xE]) {
        return 1;
    }
    _suinv_entrypoint_0(&count, 0, 1, 0x46, 1);
    return count;
}

// Launch with camera shake and fly camera setup.
void bafly_entrypoint_13(PlayerState *state, s32 mode, s32 anim_id, f32 anim_duration)
{
    f32 pos[3];
    f32 unk_0[3];
    f32 gravity;
    f32 yaw;
    f32 unk_1;
    f32 speed;
    f32 unk_2;

    if (mode == 0) {
        gravity = -2200.0f;
        speed = 800.0f;
    } else {
        gravity = -1200.0f;
        speed = 400.0f;
    }
    func_8009C128(state, pos);
    func_800E1610(2, 100.0f, 0.85f, pos);
    baanim_playForDuration_once(state, anim_id, anim_duration);
    func_8009D9D4(state);
    _bamotor_entrypoint_1(state, 1.0f, 0.5f, 0.5f);
    func_800A32C4(state, unk_0);
    func_800F1E6C(unk_0, pos, &yaw);
    yaw_setIdeal(state, func_800136E4(yaw + 180.0f));
    yaw_applyIdeal(state);
    baphysics_set_target_horizontal_velocity(state, speed);
    baphysics_set_target_yaw(state, yaw);
    baphysics_set_horizontal_velocity(state, yaw,
                                      baphysics_get_target_horizontal_velocity(state));
    func_8009FFD8(state, 1, 1, 2, 3);
    baphysics_set_vertical_velocity(state, 800.0f);
    baphysics_set_gravity(state, gravity);
    baphysics_set_terminal_velocity(state, -4000.0f);
    func_800A4DA4(state, 3);
    _ncbafly_entrypoint_4(func_800A4CA8(state), 12.0f, 10000.0f, 800.0f);
    func_8008E944(state);
}

int bafly_entrypoint_14(Actor *actor, s32 anim_done_state, s32 stable_state)
{
    s32 next_state = 0;
    if (anctrl_isStopped(baanim_getAnimCtrlPtr(actor))) {
        next_state = anim_done_state;
    }
    if (player_isStable(actor)) {
        next_state = stable_state;
    }
    bs_setState(actor, next_state);
}

int bafly_entrypoint_15(Actor *actor)
{
    func_8009BC34(actor);
    func_8008E95C(actor);
    func_8009BD88(actor);
    func_800A4E30(actor);
}

// Launch with camera shake and fly camera setup.
void bafly_entrypoint_16(PlayerState *state, s32 anim_id, f32 anim_duration)
{
    f32 yaw;
    f32 pos[3];
    f32 unk_0[3];

    func_8009C128(state, pos);
    func_800E1610(2, 100.0f, 0.85f, pos);
    baanim_playForDuration_once(state, anim_id, anim_duration);
    func_8009DA40(state);
    func_800A32C4(state, unk_0);
    func_800F1E6C(unk_0, pos, &yaw);
    yaw_setIdeal(state, func_800136E4(yaw + 180.0f));
    yaw_applyIdeal(state);
    baphysics_set_target_horizontal_velocity(state, 1300.0f);
    baphysics_set_target_yaw(state, yaw);
    baphysics_set_horizontal_velocity(state, yaw,
                                      baphysics_get_target_horizontal_velocity(state));
    func_8009FFD8(state, 1, 1, 2, 3);
    baphysics_set_vertical_velocity(state, 400.0f);
    baphysics_set_gravity(state, -1800.0f);
    func_8008E944(state);
    func_800A4DA4(state, 3);
    _ncbafly_entrypoint_4(func_800A4CA8(state), 12.0f, 10000.0f, 800.0f);
}

void bafly_entrypoint_17(PlayerState *state, s32 done_state, s32 stable_state, s32 *landed)
{
    s32 next_state = 0;
    AnimCtrl *anim_ctrl;
    anim_ctrl = baanim_getAnimCtrlPtr(state);
    if (player_isStable(state))
        next_state = stable_state;
    if (anctrl_isStopped(anim_ctrl)) {
        if (func_8008DD04(state) || func_8009650C(state)) {
            *landed = 1;
            next_state = done_state;
        }
    }
    bs_setState(state, next_state);
}

void bafly_entrypoint_18(s32 state)
{
    baphysics_reset_gravity();
    func_8008E95C(state);
}

void bafly_entrypoint_19(s32 state)
{
    if (_bafpctrl_entrypoint_4() != 3) {
        if (baflag_isTrue(state, 0x2F) != 0) {
            _bafpctrl_entrypoint_14(state, 3);
        } else {
            _bafpctrl_entrypoint_14(state, 2);
        }
        _bafpctrl_entrypoint_9(state, 1);
        if (func_800C6E38(0x1B) == 0) {
            _bafpctrl_entrypoint_11(state, 4, 1);
        }
    }
}

void bafly_entrypoint_20(PlayerState *state)
{
    f32 input;
    f32 scale;

    input = _bafpctrl_entrypoint_3(state);
    scale = func_800F10B4(input, 0.1f, 1.0f, input * input, 1.0f);
    func_8009BFE4(state, 500.0f * scale, 1.2f);
}

void bafly_entrypoint_21(PlayerState *state)
{
    f32 input;
    f32 scale;

    input = _bafpctrl_entrypoint_3(state);
    scale = func_800F10B4(input, 0.1f, 1.0f, input * input, 1.0f);
    func_8009BFE4(state, 1000.0f * scale, 2.2f);
}
