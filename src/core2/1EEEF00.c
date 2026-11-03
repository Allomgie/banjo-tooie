#include "core2/1EEEF00.h"

// Camera pitch component. State slot at camera+0x3C, size 0x38.
#define STATE(p) (*(LocalState **) ((u8 *) (p) + 0x3C))
extern f32 func_80013728(f32);
extern f32 func_80013A7C(f32);
extern f32 func_800EEAA4(f32 *, f32 *);
extern void func_800EF2A0(f32 *);
extern void func_800EF3DC(f32 *, f32 *);
extern f32 func_800F1DCC(f32, f32);
extern void func_800F5680(s32, f32 *);
extern s32 func_800F6C5C(s32);
extern void func_801107B0();
extern void func_801107F0();
extern s32 func_80110840();
extern f32 func_800D8FF8(void);
extern f32 func_800F1344(f32, f32, f32, u32, f32);
extern f32 func_800136E4(f32);
extern f32 mlAbsF(f32);
extern void func_801160DC(void *, f32);
typedef struct {
    u8 pad_0[0xC];
    s32 mode;
    u8 unk_10, has_min, has_max, pad_13;
    f32 low, high;
    u8 unk_1C, active, pad_1E[2];
    f32 target, current, velocity, elapsed, duration;
} LocalState;
extern f32 func_80013B7C(f32, f32);

typedef struct {
    u8 pad_0[0x1D];
    u8 active;
    u8 pad_1E[2];
    f32 goal, current, velocity, elapsed, duration;
} LocalTurn;
typedef struct {
    u8 pad_0[0x3C];
    LocalTurn *turn;
} LocalActor;

// Component size.
s32 func_80115610()
{
    return 0x38;
}

// Lower pitch limit derived from the floor normal under the player.
void func_80115618(u8 *camera, f32 pitch, f32 offset)
{
    f32 floor_normal[3];
    f32 unk_0[3];
    f32 limit;
    f32 slope_angle;
    s32 player;
    f32 slope_diff;
    f32 unk_1[3];

    player = func_80110840(camera);
    if (func_800F6C5C(player) != 0) {
        func_800F5680(player, floor_normal);
        if (0.6f < floor_normal[1]) {
            func_801107B0(camera, unk_0);
            func_801107F0(camera, unk_1);
            func_800EF3DC(unk_0, unk_1);
            func_800EF2A0(unk_0);
            slope_angle = func_80013A7C(func_800EEAA4(unk_0, floor_normal));
            slope_diff = func_800F1DCC(90.0f, slope_angle);
            limit = func_80013728(pitch + slope_diff + offset);
            if (*(u8 *) ((s8 *) *(u8 **) ((s8 *) camera + 0x3C) + 0x11) != 0) {
                if (*(f32 *) ((s8 *) *(u8 **) ((s8 *) camera + 0x3C) + 0) < limit) {
                    *(f32 *) ((s8 *) *(u8 **) ((s8 *) camera + 0x3C) + 0) = limit;
                }
            } else {
                *(f32 *) ((s8 *) *(u8 **) ((s8 *) camera + 0x3C) + 0) = limit;
                *(u8 *) ((s8 *) *(u8 **) ((s8 *) camera + 0x3C) + 0x11) = 1U;
            }
            if (*(u8 *) ((s8 *) *(u8 **) ((s8 *) camera + 0x3C) + 0x12) != 0) {
                limit = *(f32 *) ((s8 *) *(u8 **) ((s8 *) camera + 0x3C) + 0);
                if (*(f32 *) ((s8 *) *(u8 **) ((s8 *) camera + 0x3C) + 4) < limit) {
                    *(f32 *) ((s8 *) *(u8 **) ((s8 *) camera + 0x3C) + 4) = limit;
                }
            }
        }
    }
}

// Clamp a requested pitch to the active limits.
f32 func_80115750(u8 *camera, f32 pitch)
{
    f32 unk_0;
    f32 unk_1;
    f32 min_pitch;
    f32 max_pitch;
    if ((*(u8 **) (camera + 0x3C))[0x10] && !(*(u8 **) (camera + 0x3C))[0x1C]) {
        func_80115618(camera, pitch, *(f32 *) (*(u8 **) (camera + 0x3C) + 8));
    }
    min_pitch = *(f32 *) (*(u8 **) (camera + 0x3C) + 0);
    max_pitch = *(f32 *) (*(u8 **) (camera + 0x3C) + 4);
    if ((*(u8 **) (camera + 0x3C))[0x11] && func_800F1DCC(pitch, min_pitch) < 0.0f)
        pitch = min_pitch;
    if ((*(u8 **) (camera + 0x3C))[0x12] && func_800F1DCC(max_pitch, pitch) < 0.0f)
        pitch = max_pitch;
    return pitch;
}

void func_80115828(u8 *camera, f32 min_pitch, f32 max_pitch)
{
    *(f32 *) ((s8 *) *(u8 **) ((s8 *) camera + 0x3C) + 0) = min_pitch;
    *(f32 *) ((s8 *) *(u8 **) ((s8 *) camera + 0x3C) + 4) = max_pitch;
    *(s8 *) ((s8 *) *(u8 **) ((s8 *) camera + 0x3C) + 0x11) = 1;
    *(s8 *) ((s8 *) *(u8 **) ((s8 *) camera + 0x3C) + 0x12) = 1;
}

func_80115858(s32 camera, s32 mode)
{
    *(s32 *) (*(s32 *) (camera + 0x3C) + 0xc) = mode;
}

void func_80115864(void *camera, s32 value)
{
    ((s8 *) *(void **) ((char *) camera + 0x3C))[28] = value;
}

void func_80115870(u8 *camera, f32 offset)
{
    if (offset == 0.0f) {
        *(s8 *) ((s8 *) *(u8 **) ((s8 *) camera + 0x3C) + 0x10) = 0;
    } else {
        *(s8 *) ((s8 *) *(u8 **) ((s8 *) camera + 0x3C) + 0x10) = 1;
    }
    *(f32 *) ((s8 *) *(u8 **) ((s8 *) camera + 0x3C) + 8) = offset;
}

void func_801158B0(s32 camera, f32 low, f32 high)
{
    // Matching: the temporary and the stray `;` are needed for the match.
    int byte_offset;
    byte_offset = 0x14;
    (*(f32 **) (camera + 0x3C))[byte_offset / 4] = low;
    ;
    (*(f32 **) (camera + 0x3C))[0x18 / 4] = high;
}

void func_801158CC(PlayerState *camera, f32 *out)
{
    func_80112550(camera, out);
}

// Move *current toward target with a speed limit, easing out near the target.
void func_801158EC(f32 target, f32 *current, f32 *velocity, f32 accel, f32 max_speed, f32 slow_range)
{
    // Matching: pointer temporaries are needed for the match.
    f32 *target_ref;
    f32 diff;
    f32 *current_src;
    f32 dt;
    f32 step;
    f32 step_abs;
    f32 delta;
    if (target == *current) {
        *velocity = 0.0f;
        return;
    }
    dt = func_800D8FF8();
    diff = func_800F1DCC(target, *current);
    if (mlAbsF(diff) < slow_range) {
        *velocity = func_800F1344(diff, 0.0f, slow_range, 0x41200000, max_speed);
    } else {
        delta = accel * dt;
        if (diff < 0.0f) {
            delta = -delta;
        }
        *velocity += delta;
        if (*velocity < 0.0f) {
            if (*velocity < -max_speed) {
                *velocity = -max_speed;
            }
        } else if (max_speed < *velocity) {
            *velocity = max_speed;
        }
    }
    step = *velocity * dt;
    step_abs = mlAbsF(step);
    if ((mlAbsF(diff) < step_abs) && ((step * diff) > 0.0f)) {
        *velocity = 0.0f;
        current_src = &*(target_ref = &target);
        step = 0.0f;
        *current = *current_src;
    }
    *current = func_800136E4(*current + step);
}

void func_80115A9C(void *camera)
{
    f32 unk_0[3];
    f32 delta[3];
    f32 unk_1[3];
    f32 angles[2];
    s32 reached;
    STATE(camera)->has_min = STATE(camera)->has_max = 0;
    switch (STATE(camera)->mode) {
        case 1:
            func_80115828(camera, STATE(camera)->low, STATE(camera)->high);
            break;
        case 2:
            func_80115828(camera, -80.0f, 80.0f);
            break;
    }
    if (STATE(camera)->active) {
        STATE(camera)->elapsed += func_800D8FF8();
        func_801158CC(camera, unk_0);
        func_801107F0(camera, unk_1);
        func_800EFB24(delta, unk_1, unk_0);
        func_800F1A88(delta, angles);
        if (STATE(camera)->duration < STATE(camera)->elapsed)
            angles[0] = STATE(camera)->target;
        reached = mlAbsF(STATE(camera)->target - angles[0]) < 1.0f;
        func_80115828(camera, STATE(camera)->current, STATE(camera)->target);
        func_801158EC(STATE(camera)->target, &STATE(camera)->current, &STATE(camera)->velocity,
                      800.0f, 160.0f, 100.0f);
        func_801160DC(camera, 0);
        if (reached)
            STATE(camera)->active = 0;
    }
}

void func_80115C40(void *camera, float min_pitch)
{
    float max_pitch;
    void *state;

    state = *(void **) ((char *) camera + 0x3C);
    if ((*(u8 *) ((char *) state + 0x11) == 0) ||
        !(min_pitch < *(float *) ((char *) state + 0))) {
        if (*(u8 *) ((char *) state + 0x12) != 0) {
            max_pitch = *(float *) ((char *) state + 4);
            if (max_pitch < min_pitch) {
                min_pitch = max_pitch;
            }
        }
        *(float *) ((char *) state + 0) = min_pitch;
        *(u8 *) ((char *) *(void **) ((char *) camera + 0x3C) + 0x11) = 1U;
    }
}

void func_80115CA4(u8 *camera, f32 max_pitch)
{
    u8 *state;
    f32 min_pitch;
    state = *(u8 **) ((s8 *) camera + 0x3C);
    if (*(u8 *) ((s8 *) state + 0x12) == 0 || !(*(f32 *) ((s8 *) state + 4) < max_pitch)) {
        if (*(u8 *) ((s8 *) state + 0x11) != 0) {
            min_pitch = *(f32 *) (s8 *) state;
            if (max_pitch < min_pitch) {
                max_pitch = min_pitch;
            }
        }
        *(f32 *) ((s8 *) state + 4) = max_pitch;
        *(*(u8 **) ((s8 *) camera + 0x3C) + 0x12) = 1;
    }
}

void func_80115D08(void *camera, s32 unk_1, f32 distance, f32 height, f32 range)
{
    f32 angle;
    f32 low;
    f32 high;
    angle = func_80013B7C(height, distance);
    if (0.0f <= range) {
        low = angle;
        high = angle + range;
    } else {
        low = angle + range;
        high = angle - range;
    }
    func_801158B0(camera, func_800136E4(low), func_800136E4(high));
}

// Matching: no return statement, needed for the match.
int func_80115D88(Actor *camera)
{
    f32 unk_0[3];
    f32 delta[3];
    f32 unk_1[3];

    func_801107F0(camera, unk_0);
    func_801158CC(camera, unk_1);
    func_800EFB24(delta, unk_0, unk_1);
    func_800F1884(delta, *(u8 **) ((u8 *) camera + 0x3c) + 0x24);
    *(f32 *) (*(u8 **) ((u8 *) camera + 0x3c) + 0x28) = 0.0f;
}

// Start a timed smooth pitch rotation toward target.
void func_80115DEC(LocalActor *camera, f32 target, f32 speed)
{
    if (!camera->turn->active)
        func_80115D88(camera);
    camera->turn->goal = target;
    camera->turn->elapsed = 0.0f;
    camera->turn->duration =
        mlAbsF(func_800F1DCC(camera->turn->goal, camera->turn->current)) * 1.2f / speed;
    camera->turn->active = 1;
}

f32 func_80115E88(u32 camera)
{
    return *(f32 *) (*(u32 **) (camera + 0x3C) + 6);
}
