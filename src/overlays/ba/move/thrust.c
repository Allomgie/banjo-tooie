#include "common.h"

extern f32 func_8009BFCC(s32);
extern f32 yaw_get(s32);
extern void func_800EF4E4(s32, f32, f32, f32, f32, f32);
typedef struct {
    u32 pad_0;
    f32 pos[3];
    f32 vel[3];
    u8 pad_1C[0xC];
    f32 step[3];
    f32 gravity_accel;
    f32 min_vel_y;
    u8 pad_3C[0x48];
    f32 drag;
    u32 pad_88;
    f32 speed;
} MoveThrustState;
typedef struct {
    u8 pad_0[0xC8];
    MoveThrustState *state;
} MoveThrustPlayer;
extern f32 func_800D8FF8(void);
extern void func_800EF334(f32 *, f32);
extern void func_800EFA20(f32 *, f32 *, f32);

// Computes the thrust vector of the given speed from pitch and yaw.
void func_80800000_bamovethrust(s32 player, s32 out_vel, f32 speed)
{
    f32 pitch = func_8009BFCC(player);
    func_800EF4E4(out_vel, pitch, yaw_get(player), 0.0f, 0.0f, speed);
}

void bamovethrust_entrypoint_0(s32 actor)
{
}

void bamovethrust_entrypoint_1(void *actor)
{
    *(f32 *) ((u8 *) *(void **) ((u8 *) actor + 0xC8) + 0x8C) = 1.0f;
    *(f32 *) ((u8 *) *(void **) ((u8 *) actor + 0xC8) + 0x84) = 1.0f;
    *(f32 *) ((u8 *) *(void **) ((u8 *) actor + 0xC8) + 0x88) = 1.0f;
}

void bamovethrust_entrypoint_2(u8 *player, f32 speed)
{
    func_80800000_bamovethrust(player, *(u8 **) (player + 0xC8) + 0x10, speed);
}

int bamovethrust_entrypoint_3(s32 actor, f32 speed)
{
    *(f32 *) (*(s32 *) (actor + 0xC8) + 140) = speed;
}

void bamovethrust_entrypoint_4(u8 *actor, f32 drag)
{
    *(f32 *) ((s8 *) *(u8 **) ((s8 *) actor + 0xC8) + 0x84) = drag;
}

// Steers velocity by thrust along pitch/yaw with drag and a gravity floor, then integrates position.
void bamovethrust_entrypoint_5(MoveThrustPlayer *player)
{
    f32 dt;
    f32 thrust_vel[3];
    f32 damped_vel[3];

    func_80800000_bamovethrust(player, thrust_vel, player->state->speed);
    func_800EE7F8(damped_vel, player->state->vel);
    func_800EF334(damped_vel, player->state->drag);
    func_800EE780(player->state->vel, damped_vel, thrust_vel);
    dt = func_800D8FF8();
    player->state->vel[1] += player->state->gravity_accel * dt;
    if (player->state->vel[1] < player->state->min_vel_y)
        player->state->vel[1] = player->state->min_vel_y;
    func_800EFA20(player->state->step, player->state->vel, dt);
    func_800EF04C(player->state->pos, player->state->step);
}

f32 bamovethrust_entrypoint_6(u8 *actor)
{
    return *(f32 *) ((s8 *) *(u8 **) ((s8 *) actor + 0xC8) + 0x8C);
}
