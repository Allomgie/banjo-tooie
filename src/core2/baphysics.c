#include "overlays/ba/physics.h"

#define QQ (*(S_9B450 **) ((u8 *) param_0 + 0xC8))
typedef struct {
    s32 mode;
    f32 position[3], velocity[3], target_velocity[3], delta[3];
    f32 gravity, terminal_velocity, target_speed, target_yaw;
    u8 pad_44[0xC];
    f32 scale;
} Physics9AE08;
typedef struct {
    u8 pad_0[0xC8];
    Physics9AE08 *physics;
} Player9AE08;
extern void func_800EEB9C(f32 *, f32, f32);
extern void func_800EF410(f32 *, f32 *);
extern void func_800EF3DC(f32 *, f32 *);
extern void func_800F2168(f32 *, f32);
extern f32 func_800EEAA4(f32 *, f32 *);
extern f32 func_800A3378(PlayerState *);
extern f32 func_80094E98(PlayerState *);
extern f32 func_800F10B4(f32, f32, f32, f32, f32);
extern s32 func_80096518(PlayerState *);
extern s32 func_8008E1C4(PlayerState *);
extern void func_800963C0(PlayerState *, f32 *);
typedef struct {
    s32 mode;
    f32 position[3], velocity[3], target[3], delta[3];
    u8 pad_34[0x10];
    f32 rate;
} LocalState_8009B08C;
extern void func_800EFA20(f32 *, f32 *, f32, ...);
struct Actor {
    char _pad[0xC8];
    struct ActorLocal_CC_1 *local_1;
    char _pad2[0x40];
};
typedef struct {
    f32 mode;
    f32 position[3];
    f32 velocity[3];
    f32 target_velocity[3];
} State9B27C;
typedef struct {
    u8 pad_0[0xC8];
    State9B27C *state;
} Actor9B27C;
extern void func_80098590(Actor9B27C *, f32 *);
extern s32 func_8009861C(Actor9B27C *);
extern f32 func_80098610(Actor9B27C *);
extern f32 func_80098628(Actor9B27C *);
extern f32 func_800136E4(f32);
extern void func_800EF334(f32 *, f32);
extern void func_800EE7F8();
extern void func_800EF04C(s32 arg0, s32 arg1);
typedef struct {
    u8 pad_0[8];
    f32 pos_y;
    u8 pad_C[0x3C];
    f32 base_y;
    f32 phase;
} S_9B450;
extern f32 func_800D8FF8();
extern f32 func_800F0F9C(f32, f32);
extern f32 func_80013970(f32);
extern void func_800EFA4C(s32 param_1, f32 param_2, s32 param_3, f32 param_4);
typedef struct {
    s32 mode;
    f32 position[3];
    u8 pad_10[0x40];
    f32 scale;
} LocalState_8009B590;
extern f32 func_800A3048(PlayerState *);
extern f32 bastick_distance(PlayerState *);
extern f32 bastick_getAngleRelativeToBanjo(PlayerState *);
extern void func_800EFD24(void *param_0);
extern f32 D_80117EF0;
extern f32 D_80117EF4;

// The first six functions handle a 15-byte array of on/off flags at PlayerState+0xC4
// that enable optional ba subsystems in the player update loop.
s32 func_8009AD70()
{
    return 0xF;
}

u8 func_8009AD78(u8 *player, s32 index)
{
    return *(u8 *) (*(s32 *) ((char *) player + 0xC4) + index);
}

void func_8009AD88(s32 arg0)
{
}

// Clears all flags.
void func_8009AD90(u8 *player)
{
    s32 i;

    i = 3;
    *(s8 *) ((s8 *) *(u8 **) ((s8 *) player + 0xC4) + 0) = 0;
    *(s8 *) ((s8 *) *(u8 **) ((s8 *) player + 0xC4) + 1) = 0;
    *(s8 *) ((s8 *) *(u8 **) ((s8 *) player + 0xC4) + 2) = 0;
    do {
        *(*(u8 **) ((s8 *) player + 0xC4) + i) = 0;
        *(s8 *) ((s8 *) (*(u8 **) ((s8 *) player + 0xC4) + i) + 1) = 0;
        *(s8 *) ((s8 *) (*(u8 **) ((s8 *) player + 0xC4) + i) + 2) = 0;
        *(s8 *) ((s8 *) (*(u8 **) ((s8 *) player + 0xC4) + i) + 3) = 0;
        i += 4;
    } while (i != 0xF);
}

void func_8009ADF0(u8 *player, s32 index, unsigned int enabled)
{
    *(*(u8 **) (player + 0xC4) + index) = enabled;
}

s32 func_8009AE00()
{
    return 0xC4;
}

// Walking-style integrator: blends velocity toward the target velocity, applies gravity,
// then integrates the position.
void func_8009AE08(PlayerState *player)
{
    f32 target_scaled[3], velocity_scaled[3], horiz_velocity[3], horiz_target[3], unk_0[3], unk_1[3];
    f32 unk_2, unk_3;
    f32 one;
    func_800EEB9C(
        ((Player9AE08 *) player)->physics->target_velocity, ((Player9AE08 *) player)->physics->target_yaw,
        ((Player9AE08 *) player)->physics->target_speed * ((Player9AE08 *) player)->physics->scale);
    horiz_velocity[0] = ((Player9AE08 *) player)->physics->velocity[0];
    horiz_velocity[1] = 0.0f;
    horiz_velocity[2] = ((Player9AE08 *) player)->physics->velocity[2];
    func_800EE7F8(horiz_target, ((Player9AE08 *) player)->physics->target_velocity);
    horiz_target[1] = 0.0f;
    if (func_80096518(player)) {
        func_800963C0(player, unk_0);
        func_800EF410(unk_1, horiz_target);
        unk_2 = func_800EEAA4(unk_1, unk_0);
        unk_3 = func_800A3378(player);
        if (unk_2 != 0.0f) {
            if (unk_2 < 0.0f) {
                if (func_8008E1C4(player))
                    unk_3 = func_800F10B4(unk_3, 0.0f, 1.0f, unk_2 * 0.5f, -1.0f);
                else
                    unk_3 = unk_2 * 0.5f;
                func_800EF334(horiz_target, 1.0f + unk_3);
            } else {
                // Matching: the assignment to `one` is needed for the match.
                func_800EF334(horiz_target, (one = 1.0f) + unk_2 * 0.2f);
            }
        }
    }
    func_800EFA20(target_scaled, horiz_target, func_80094E98(player));
    func_800EFA20(velocity_scaled, horiz_velocity, func_80094E98(player));
    func_800EF3DC(target_scaled, velocity_scaled);
    func_800EF334(target_scaled, func_800D8FF8() * 30.0f);
    func_800EF04C(((Player9AE08 *) player)->physics->velocity, target_scaled);
    ((Player9AE08 *) player)->physics->velocity[1] +=
        ((Player9AE08 *) player)->physics->gravity * func_800D8FF8();
    if (((Player9AE08 *) player)->physics->velocity[1] <
        ((Player9AE08 *) player)->physics->terminal_velocity)
        ((Player9AE08 *) player)->physics->velocity[1] =
            ((Player9AE08 *) player)->physics->terminal_velocity;
    func_800EFA20(((Player9AE08 *) player)->physics->delta,
                  ((Player9AE08 *) player)->physics->velocity, func_800D8FF8());
    func_800EF04C(((Player9AE08 *) player)->physics->position,
                  ((Player9AE08 *) player)->physics->delta);
    func_800F2168(((Player9AE08 *) player)->physics->velocity, 0.0001f);
}

// Moves velocity toward the target at `rate`, then integrates the position.
void func_8009B08C(void *player)
{
    f32 blend[3];
    f32 dt;
    dt = func_800D8FF8();
    func_800EFB24(blend, (*(LocalState_8009B08C **) ((u8 *) player + 0xC8))->target,
                  (*(LocalState_8009B08C **) ((u8 *) player + 0xC8))->velocity);
    func_800EF334(blend, (*(LocalState_8009B08C **) ((u8 *) player + 0xC8))->rate * dt);
    if ((blend[0] * blend[0] + blend[1] * blend[1]) + blend[2] * blend[2] < 0.02f) {
        func_800EE7F8((*(LocalState_8009B08C **) ((u8 *) player + 0xC8))->velocity,
                      (*(LocalState_8009B08C **) ((u8 *) player + 0xC8))->target);
    } else {
        func_800EF04C((*(LocalState_8009B08C **) ((u8 *) player + 0xC8))->velocity, blend);
    }
    func_800EFA20((*(LocalState_8009B08C **) ((u8 *) player + 0xC8))->delta,
                  (*(LocalState_8009B08C **) ((u8 *) player + 0xC8))->velocity, dt);
    func_800EF04C((*(LocalState_8009B08C **) ((u8 *) player + 0xC8))->position,
                  (*(LocalState_8009B08C **) ((u8 *) player + 0xC8))->delta);
}

// Applies gravity to the vertical velocity (clamped at terminal velocity), then integrates
// the position.
void func_8009B170(u8 *player)
{
    f32 dt;

    dt = func_800D8FF8();
    *(f32 *) (*(u8 **) (player + 0xC8) + 0x14) +=
        *(f32 *) (*(u8 **) (player + 0xC8) + 0x34) * dt;
    if (*(f32 *) (*(u8 **) (player + 0xC8) + 0x14) < *(f32 *) (*(u8 **) (player + 0xC8) + 0x38)) {
        *(f32 *) (*(u8 **) (player + 0xC8) + 0x14) = *(f32 *) (*(u8 **) (player + 0xC8) + 0x38);
    }
    func_800EFA20((f32 *) (*(u8 **) (player + 0xC8) + 0x28),
                  (f32 *) (*(u8 **) (player + 0xC8) + 0x10), dt, player);
    func_800EF04C(*(u8 **) (player + 0xC8) + 4, *(u8 **) (player + 0xC8) + 0x28);
}

// Same as func_8009B170, written with locals.
void func_8009B1FC(struct Actor *player)
{
    f32 dt = func_800D8FF8();
    struct ActorLocal_CC_1 *physics;
    f32 vel_y;
    f32 terminal;
    physics = *(struct ActorLocal_CC_1 **) ((char *) player + 0xC8);
    *(f32 *) ((char *) physics + 0x14) += *(f32 *) ((char *) physics + 0x34) * dt;
    physics = *(struct ActorLocal_CC_1 **) ((char *) player + 0xC8);
    vel_y = *(f32 *) ((char *) physics + 0x14);
    terminal = *(f32 *) ((char *) physics + 0x38);
    if (vel_y < terminal) {
        *(f32 *) ((char *) physics + 0x14) = terminal;
        physics = *(struct ActorLocal_CC_1 **) ((char *) player + 0xC8);
        vel_y = *(f32 *) ((char *) physics + 0x14);
    }
    *(f32 *) ((char *) physics + 0x2C) = vel_y * dt;
    physics = *(struct ActorLocal_CC_1 **) ((char *) player + 0xC8);
    *(f32 *) ((char *) physics + 0x8) += *(f32 *) ((char *) physics + 0x2C);
}

void func_8009B27C(Actor9B27C *player)
{
    f32 offset[3];
    f32 unk_0[3];
    func_80098590(player, unk_0);
    player->state->position[0] = unk_0[0];
    player->state->position[2] = unk_0[2];
    if (func_8009861C(player) == 2) {
        func_800EEB9C(offset, func_800136E4(func_80098610(player) + 180.0f),
                      -func_80098628(player));
    } else {
        func_800EEB9C(offset, yaw_get(player), -func_80098628(player));
    }
    player->state->position[0] += offset[0];
    player->state->position[1] += offset[1];
    player->state->position[2] += offset[2];
    player->state->target_velocity[0] = player->state->target_velocity[2] = player->state->velocity[0] =
        player->state->velocity[2] = 0.0f;
    func_8009B08C(player);
}

// Integrates the position from the velocity.
void func_8009B3B8(s32 *player)
{
    func_800EE7F8(player[50] + 0x28, player[50] + 0x10);
    func_800EF334(player[50] + 0x28, func_800D8FF8());
    func_800EF04C(player[50] + 4, player[50] + 0x28);
}

void func_8009B414(u8 *player)
{
    // Matching: the padding array is needed for the match.
    s8 _sfpad[8];
    s32 pos;
    s32 physics;

    func_8009C128(player, &pos);
    physics = *(s32 *) ((s8 *) player + 0xC8);
    func_800EFB24(physics + 0x28, physics + 4, &pos);
}

// Hover bobbing: advances the phase and offsets the height from the base height.
void func_8009B450(void *param_0)
{
    QQ->phase += func_800D8FF8(param_0);
    QQ->pos_y = QQ->base_y + func_80013970(func_800F0F9C(QQ->phase, 1.2f) * 360.0f) * 5.0f;
}

void func_8009B4D0(u8 *player, s32 out)
{
    func_800EE7F8(out, *(s32 *) ((s8 *) player + 0xC8) + 0x28);
}

void func_8009B4FC(u8 *player)
{
    *(s32 *) ((s8 *) *(u8 **) ((s8 *) player + 0xC8) + 0) = 0;
    *(f32 *) ((s8 *) *(u8 **) ((s8 *) player + 0xC8) + 0x50) = 1.0f;
    func_800EFA4C(*(u8 **) ((s8 *) player + 0xC8) + 0x10, 0.0f, 0xBF800000, 0.0f);
    func_800EFD24(*(u8 **) ((s8 *) player + 0xC8) + 0x1C);
    func_800EFD24(*(u8 **) ((s8 *) player + 0xC8) + 0x28);
    func_800EFD24(*(u8 **) ((s8 *) player + 0xC8) + 4);
    *(f32 *) ((s8 *) *(u8 **) ((s8 *) player + 0xC8) + 0x44) = 2.0f;
    func_8009BC34(player);
}

// Per-frame update: runs the integrator of the current physics type and writes the
// position back.
s32 func_8009B590(PlayerState *player)
{
    func_8009C128(player, (*(LocalState_8009B590 **) ((u8 *) player + 0xC8))->position);
    (*(LocalState_8009B590 **) ((u8 *) player + 0xC8))->scale *= func_800A3048(player);
    switch ((*(LocalState_8009B590 **) ((u8 *) player + 0xC8))->mode) {
        case 0:
            break;
        case 12:
            _bamovegoto_entrypoint_14(player);
            break;
        case 11:
            func_8009B450(player);
            break;
        case 8:
            func_8009B3B8(player);
            break;
        case 1:
            func_8009B170(player);
            break;
        case 9:
            func_8009B08C(player);
            break;
        case 2:
            baphysics_set_target_yaw(player, yaw_getIdeal(player));
            func_8009AE08(player);
            break;
        case 5:
            baphysics_set_target_yaw(player, func_800136E4(yaw_getIdeal(player) + 180.0f));
            func_8009AE08(player);
            break;
        case 3:
            func_8009AE08(player);
            break;
        case 13:
            _bamoveledge_entrypoint_3(player);
            break;
        case 6:
            if (bastick_distance(player) > 0.0f)
                baphysics_set_target_yaw(player, bastick_getAngleRelativeToBanjo(player));
            func_8009AE08(player);
            break;
        case 10:
            func_8009B27C(player);
            break;
        case 16:
            _bsfirstp_entrypoint_27(player);
            func_8009AE08(player);
            func_8009B414(player);
            break;
        case 17:
            _bsfirstp_entrypoint_27(player);
            func_8009B1FC(player);
            break;
        case 14:
            baphysics_set_target_yaw(player, yaw_get(player));
            func_8009AE08(player);
            break;
        case 15:
            _bamovethrust_entrypoint_5(player);
            break;
        case 18:
            _bamovespline_entrypoint_10(player);
            break;
        case 19:
            _bamovehover_entrypoint_2(player);
            break;
    }
    func_8009C0F8(player, (*(LocalState_8009B590 **) ((u8 *) player + 0xC8))->position);
    (*(LocalState_8009B590 **) ((u8 *) player + 0xC8))->scale = 1.0f;
}

void func_8009B7C0(PlayerState *player)
{
    u8 *physics;
    baphysics_set_target_horizontal_velocity(player, 0);
    // Matching: the do-while(0) with empty statements is needed for the match.
    do {
        ;
        *(f32 *) (*(u8 **) ((u8 *) player + 0xC8) + 0x18) = 0.0f;
        physics = *(u8 **) ((u8 *) player + 0xC8);
        ;
    } while (0);
    *(f32 *) (physics + 0x10) = *(f32 *) (physics + 0x18);
}

// Switches the physics type, running the exit and enter hooks of the ba overlays.
void baphysics_set_type(PlayerState *player, BaPhysicsType type)
{
    BaPhysicsType old_type;
    old_type = *(BaPhysicsType *) *(char **) ((char *) player + 0xC8);
    if (old_type == type)
        return;
    {
        switch (old_type) {
            case 13:
                _bamoveledge_entrypoint_1(player);
                break;
            case 15:
                _bamovethrust_entrypoint_0(player);
                break;
            case 12:
                _bamovegoto_entrypoint_5(player);
                break;
            case 18:
                _bamovespline_entrypoint_5(player);
                break;
            case 19:
                _bamovehover_entrypoint_0(player);
        }
        *(s32 *) *(char **) ((char *) player + 0xC8) = type;
        switch (type) {
            case 12:
                _bamovegoto_entrypoint_6(player);
                break;
            case 13:
                _bamoveledge_entrypoint_2(player);
                break;
            case 11:
                if (old_type != type) {
                    *(f32 *) (*(char **) ((char *) player + 0xC8) + 0x48) =
                        *(f32 *) (*(char **) ((char *) player + 0xC8) + 8);
                    *(f32 *) (*(char **) ((char *) player + 0xC8) + 0x4C) = 0.0f;
                }
                break;
            case 15:
                _bamovethrust_entrypoint_1(player);
                break;
            case 18:
                _bamovespline_entrypoint_6(player);
                break;
            case 19:
                _bamovehover_entrypoint_1(player);
        }
    }
}

void func_8009B94C(void *player, s32 flag)
{
    if (flag) {
        func_800EE7F8(*(s32 *) ((char *) player + 0xC8) + 0x1c);
    } else {
        func_800EFD24(*(s32 *) ((char *) player + 0xC8) + 0x1c);
    }
}

void func_8009B98C(void *player)
{
    func_800EE7F8(*(s32 *) ((char *) player + 0xC8) + 4);
}

void baphysics_set_target_horizontal_velocity(PlayerState *player, f32 speed)
{
    *(f32 *) (*(s32 *) ((char *) player + 0xC8) + 0x3C) = speed;
}

void baphysics_set_target_yaw(PlayerState *player, f32 yaw)
{
    *(f32 *) (*(s32 *) ((char *) player + 0xC8) + 0x40) = func_800136E4(yaw);
}

void func_8009B9F0(PlayerState *player, f32 speed)
{
    baphysics_set_target_horizontal_velocity(player, speed);
    func_800EEB9C(*(f32 **) ((u8 *) player + 0xC8) + 7, (*(f32 **) ((u8 *) player + 0xC8))[16],
                  (*(f32 **) ((u8 *) player + 0xC8))[15]);
    (*(f32 **) ((u8 *) player + 0xC8))[8] = 0.0f;
    (*(f32 **) ((u8 *) player + 0xC8))[4] = (*(f32 **) ((u8 *) player + 0xC8))[7];
    (*(f32 **) ((u8 *) player + 0xC8))[6] = (*(f32 **) ((u8 *) player + 0xC8))[9];
}

void baphysics_set_vertical_velocity(PlayerState *player, f32 velocity)
{
    *(f32 *) (*(s32 *) ((char *) player + 0xC8) + 0x14) = velocity;
}

void baphysics_set_horizontal_velocity(PlayerState *player, f32 yaw, f32 vel)
{
    func_800EEB9C((char *) *(s32 *) ((char *) player + 0xC8) + 0x10, yaw, vel);
}

void func_8009BA9C(PlayerState *player, f32 *src)
{
    if (src) {
        func_800EE7F8(*(s32 *) ((char *) player + 0xC8) + 0x10);
    } else {
        func_800EFD24(*(s32 *) ((char *) player + 0xC8) + 0x10);
    }
}

f32 func_8009BADC(PlayerState *player)
{
    return ((f32 *) *(f32 **) ((char *) player + 0xC8))[0xD];
}

f32 func_8009BAE8(PlayerState *player)
{
    return *(f32 *) ((char *) *(struct ba_state_timer_list_s **) ((char *) player + 0xC8) + 0x38);
}

s32 func_8009BAF4(struct SomeStruct *player)
{
    return **(s32 **) ((char *) player + 0xC8);
}

float baphysics_get_target_horizontal_velocity(PlayerState *player)
{
    return *(f32 *) (*(s32 *) ((char *) player + 0xC8) + 0x3C);
}

f32 func_8009BB0C(u8 *player)
{
    return *(f32 *) ((s8 *) *(u8 **) ((s8 *) player + 0xC8) + 0x20);
}

f32 func_8009BB18(u8 *player)
{
    return *(f32 *) ((s8 *) *(u8 **) ((s8 *) player + 0xC8) + 0x40);
}

void func_8009BB24(PlayerState *player, f32 *out)
{
    char *ptr;
    // Matching: `if (1)` and the reused temporary are needed for the match.
    if (1) {
        ptr = out;
    }
    func_800EE7F8(ptr,
                  ptr = (char *) *(struct ba_unknown_C0_s **) ((char *) player + 0xC8) + 16);
}

f32 baphysics_get_vertical_velocity(PlayerState *player)
{
    return ((f32 *) ((u8 **) player)[50])[0x5];
}

// Horizontal speed.
f32 func_8009BB5C(PlayerState *player)
{
    // Matching: the temporary pointer and the `0;` statement are needed for the match.
    f32 *vel;
    f32 *physics;
    physics = *(f32 **) ((char *) player + 0xC8);
    0;
    return sqrtf((*vel * *(vel = (f32 *) ((char *) physics + 16))) +
                 (*(f32 *) ((char *) physics + 24) * *(f32 *) ((char *) physics + 24)));
}

f32 func_8009BB94(PlayerState *player)
{
    func_800EEF94(*(s32 *) ((char *) player + 200) + 16);
}

// Horizontal speed as a fraction of the target speed, at most 1.
f32 func_8009BBB8(struct PlayerState *player)
{
    f32 speed;
    f32 max_speed;
    f32 ratio;

    speed = func_8009BB5C(player);
    max_speed = baphysics_get_target_horizontal_velocity(player);
    if (speed < max_speed) {
        ratio = speed / max_speed;
    } else {
        ratio = 1.0f;
    }
    return ratio;
}

void func_8009BC08(u8 *player, s32 out)
{
    func_800EE7F8(out, *(s32 *) ((s8 *) player + 0xC8) + 4);
}

void func_8009BC34(PlayerState *player)
{
    baphysics_reset_gravity(player);
    baphysics_reset_terminal_velocity(player);
}

void func_8009BC5C(PlayerState *player, f32 rate)
{
    *(*(f32 **) ((u8 *) player + 0xC8) + 17) = rate;
}

void baphysics_reset_gravity(PlayerState *player)
{
    baphysics_set_gravity(player, D_80117EF0);
}

void baphysics_reset_terminal_velocity(PlayerState *player)
{
    baphysics_set_terminal_velocity(player, D_80117EF4);
}

void baphysics_set_gravity(PlayerState *player, f32 gravity)
{
    *(f32 *) (*(s32 *) ((char *) player + 0xC8) + 0x34) = gravity;
}

void baphysics_set_terminal_velocity(PlayerState *player, f32 terminal_velocity)
{
    *(f32 *) (*(s32 *) ((char *) player + 0xC8) + 0x38) = terminal_velocity;
}

// True if the horizontal speed is at most max_speed.
s32 func_8009BCD4(PlayerState *player, f32 max_speed)
{
    f32 *physics = *(f32 **) ((char *) player + 0xC8);
    return physics[4] * physics[4] + physics[6] * physics[6] <= max_speed * max_speed;
}

int func_8009BD18(s32 player, f32 scale)
{
    f32 scale_copy;
    // Matching: the extra temporary is needed for the match.
    scale_copy = scale;
    *(f32 *) (*(s32 *) (player + 0xC8) + 0x50) = scale_copy;
}

// TU-NOTE: the .data of this file (formerly asm/data/core2/baphysics.data.s) is defined
// here in C. Values are taken from the ROM.
f32 D_80117EF0 = -2.7e+03f;
f32 D_80117EF4 = -4e+03f;
