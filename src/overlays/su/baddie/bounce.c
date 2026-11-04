#include "common.h"

typedef struct {
    s32 unk_0;
    f32 pos[3];
    f32 unk_10[3];
    f32 floor_y;
    f32 unk_20[2];
    f32 velocity[3];
    f32 gravity;
} SubaddieBounceState;
extern f32 func_800D8FF8(void);
extern void func_800EFA20(f32 *, f32 *, f32);
extern void func_800EF04C(f32 *, f32 *);
extern void func_800EF334(f32 *, f32);

// Simulate the jump in 1/60 s steps to get the flight time, then set the velocity to reach the target.
void subaddiebounce_entrypoint_0(Actor *actor)
{
    f32 *velocity;
    f32 flight_time;
    f32 vel_y;
    f32 height;
    f32 inv_time;

    flight_time = 0.0f;
    vel_y = ((f32 *) actor->actorData)[3];
    height = actor->position[1];
    while (vel_y > 0.0f || ((f32 *) actor->actorData)[1] < height) {
        height += vel_y * 0.01666666754f;
        flight_time += 0.01666666754f;
        vel_y += ((f32 *) actor->actorData)[7] * 0.01666666754f;
    }
    velocity = (f32 *) &actor->actorData[4];
    func_800EFB24(velocity, actor->actorData, actor->position);
    inv_time = 1.0f / flight_time;
    func_800EF334(velocity, inv_time);
    ((f32 *) actor->actorData)[5] = ((f32 *) actor->actorData)[3];
}

// Gravity step with bounce (velocity * -0.5) on the floor; returns 1 when landed or at rest.
s32 subaddiebounce_entrypoint_1(SubaddieBounceState *state)
{
    f32 dt;
    f32 delta[3];

    dt = func_800D8FF8();
    if (state->floor_y < state->pos[1] || state->velocity[1] > 0.0f) {
        func_800EFA20(delta, state->velocity, dt);
        func_800EF04C(state->pos, delta);
        if (state->pos[1] < state->floor_y) {
            state->pos[1] = state->floor_y;
            state->velocity[0] = 0.0f;
            state->velocity[2] = 0.0f;
            state->velocity[1] *= -0.5f;
            return 1;
        }
        state->velocity[1] += state->gravity * dt;
        return 0;
    }
    return 1;
}

// Same as entrypoint_1, for an actor.
int subaddiebounce_entrypoint_2(Actor *actor)
{
    f32 dt;

    dt = func_800D8FF8();
    if (((f32 *) actor->actorData)[1] < actor->position[1] ||
        ((f32 *) actor->actorData)[5] > 0.0f) {
        actor->position[1] += ((f32 *) actor->actorData)[5] * dt;
        if (actor->position[1] < ((f32 *) actor->actorData)[1]) {
            actor->position[1] = ((f32 *) actor->actorData)[1];
            ((f32 *) actor->actorData)[5] *= -0.5f;
            return 1;
        } else {
            ((f32 *) actor->actorData)[5] += ((f32 *) actor->actorData)[7] * dt;
            return 0;
        }
    }
    return 1;
}
