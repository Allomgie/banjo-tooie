// Camera yaw component of the dynamic camera: prioritised timed yaw requests, angular approach
// with acceleration and speed limit, yaw limit clamping and nudge offsets.
// TU-NOTE: first of three objects split from the 0x1EEC090..0x1EEE680 range
// (1EEC090, 1EEC780, 1EED8E0). The .rodata shows the object boundaries; the next
// object starts at func_80112E90.
#include "core2/1EEC090.h"
#include <types.h>

extern f32 func_800F1DCC(f32, f32);
extern f32 func_800FF060(f32, f32 *, f32, f32, f32, f32);
extern f32 func_800D8FF8(void);
extern f32 mlAbsF(f32);
extern f32 func_800F1344(f32, f32, f32, u32, f32);
extern f32 func_800136E4(f32);
// Yaw rotation component at camera+0x60.
typedef struct {
    u8 pad_0[12];
    s16 mode, priority;
    f32 target_yaw, yaw, speed, elapsed, duration;
} State112A84;
typedef struct {
    u8 pad_0[0x60];
    State112A84 *state;
} Actor112A84;
extern void func_801107F0(Actor112A84 *, f32 *);
extern void func_800EFB24(f32 *, f32 *, f32 *);
extern void func_800F1A88(f32 *, f32 *);
extern void func_801160DC(Actor112A84 *, f32);
typedef struct {
    f32 unk_0, unk_4;
    s32 limit_mode;
} LocalAngle;
typedef struct {
    u8 pad_0[0x60];
    LocalAngle *limits;
} LocalActor;
extern f32 func_800F1738(f32, f32, f32);
typedef struct {
    u8 pad_0[0xC];
    s16 mode, priority;
    f32 target_yaw, yaw, speed, elapsed, duration;
} Motion112D90;
typedef struct {
    u8 pad_0[0x60];
    Motion112D90 *state;
} Actor112D90;
void func_80112D08(u8 *param_0, s32 param_1, f32 param_2, f32 param_3);

// Camera yaw component: rotation requests with priority, update and limits.
s32 func_801127A0()
{
    return 0x24;
}

void func_801127A8(PlayerState *camera, f32 *out)
{
    func_80112550(camera, out);
}

// Generic angular approach helpers (accelerate toward a target angle with a speed limit).
void func_801127C8(f32 target_yaw, f32 *yaw, f32 *speed, f32 unk_0, f32 unk_1)
{
    f32 diff;
    f32 abs_diff;
    f32 step;
    diff = func_800F1DCC(target_yaw, *yaw);
    abs_diff = mlAbsF(diff);
    if (0.1f < abs_diff) {
        step = func_800FF060(diff, speed, 1000.0f, -560.0f, 75.0f, func_800D8FF8());
        if (abs_diff < mlAbsF(step) && *speed * diff > 0.0f) {
            step = diff;
            *speed = 0.0f;
        }
        *yaw = func_800136E4(*yaw + step);
    } else {
        *speed = 0.0f;
        *yaw = target_yaw;
    }
}

void func_801128D4(f32 target_yaw, f32 *yaw, f32 *speed, f32 accel, f32 max_speed, f32 slow_range)
{
    f32 *target_ptr;
    f32 diff;
    f32 *target_ptr2;
    f32 dt;
    f32 step;
    f32 abs_step;
    f32 delta;
    if (target_yaw == *yaw) {
        *speed = 0.0f;
        return;
    }
    dt = func_800D8FF8();
    diff = func_800F1DCC(target_yaw, *yaw);
    if (mlAbsF(diff) < slow_range) {
        *speed = func_800F1344(diff, 0.0f, slow_range, 0x41200000, max_speed);
    } else {
        delta = accel * dt;
        if (diff < 0.0f) {
            delta = -delta;
        }
        *speed += delta;
        if (*speed < 0.0f) {
            if (*speed < -max_speed) {
                *speed = -max_speed;
            }
        } else if (max_speed < *speed) {
            *speed = max_speed;
        }
    }
    step = *speed * dt;
    abs_step = mlAbsF(step);
    if ((mlAbsF(diff) < abs_step) && ((step * diff) > 0.0f)) {
        *speed = 0.0f;
        // Matching: the pointer aliasing of target_yaw is needed for the match.
        target_ptr2 = &*(target_ptr = &target_yaw);
        step = 0.0f;
        *yaw = *target_ptr2;
    }
    *yaw = func_800136E4(*yaw + step);
}

void func_80112A84(Actor112A84 *camera)
{
    s32 limit_mode;
    f32 limit_yaw;
    f32 limit_target;
    f32 target_pos[3];
    f32 dir[3];
    f32 cam_pos[3];
    f32 angles[2];
    s32 arrived;
    if (camera->state->mode) {
        limit_mode = 5;
        camera->state->elapsed += func_800D8FF8();
        func_801127A8(camera, target_pos);
        func_801107F0(camera, cam_pos);
        func_800EFB24(dir, cam_pos, target_pos);
        func_800F1A88(dir, angles);
        if (camera->state->elapsed > camera->state->duration)
            angles[1] = camera->state->target_yaw;
        arrived = mlAbsF(camera->state->target_yaw - angles[1]) < 1.0f;
        limit_yaw = camera->state->yaw;
        limit_target = camera->state->target_yaw;
        if (camera->state->mode == 1) {
            func_801127C8(camera->state->target_yaw, &camera->state->yaw,
                          &camera->state->speed, 50.0f, 3.0f);
            func_801160DC(camera, 0.0f);
        } else {
            func_801128D4(camera->state->target_yaw, &camera->state->yaw,
                          &camera->state->speed, 800.0f, 160.0f, 100.0f);
            func_801160DC(camera, 0.0f);
        }
        if (arrived) {
            camera->state->mode = 0;
            camera->state->priority = 0;
        }
    } else {
        limit_mode = 0;
        limit_target = 0.0f;
        limit_yaw = 0.0f;
    }
    func_80112D08(camera, limit_mode, limit_yaw, limit_target);
}

f32 func_80112C3C(LocalActor *camera, f32 yaw)
{
    switch (camera->limits->limit_mode) {
        case 1:
        case 2:
        case 5:
            yaw = func_800F1738(yaw, camera->limits->unk_0, camera->limits->unk_4);
            break;
        case 3:
            if (func_800F1DCC(yaw, camera->limits->unk_0) < 0.0f)
                yaw = camera->limits->unk_0;
            break;
        case 4:
            if (func_800F1DCC(yaw, camera->limits->unk_0) > 0.0f)
                yaw = camera->limits->unk_0;
    }
    return yaw;
}

void func_80112D08(u8 *camera, s32 limit_mode, f32 unk_0, f32 unk_4)
{
    *(s32 *) ((s8 *) *(u8 **) ((s8 *) camera + 0x60) + 8) = limit_mode;
    *(f32 *) ((s8 *) *(u8 **) ((s8 *) camera + 0x60) + 0) = unk_0;
    *(f32 *) ((s8 *) *(u8 **) ((s8 *) camera + 0x60) + 4) = unk_4;
}

void func_80112D2C(s32 camera)
{
    f32 cam_pos[3];
    f32 dir[3];
    f32 target_pos[3];

    func_801107F0(camera, cam_pos);
    func_801127A8(camera, target_pos);
    func_800EFB24(dir, cam_pos, target_pos);
    func_800F1EA4(dir, *(u8 **) (camera + 0x60) + 0x14);
    *(f32 *) ((char *) *(u8 **) (camera + 0x60) + 0x18) = 0.0f;
}

// Requests a rotation to target_yaw; ignored if priority is lower than the active request.
void func_80112D90(Actor112D90 *camera, f32 target_yaw, f32 rate, s32 mode, s32 priority)
{
    if (priority >= camera->state->priority) {
        if (mode != camera->state->mode)
            func_80112D2C(camera);
        camera->state->target_yaw = target_yaw;
        camera->state->elapsed = 0.0f;
        camera->state->duration =
            mlAbsF(func_800F1DCC(camera->state->target_yaw, camera->state->yaw)) * 1.2f /
            rate;
        camera->state->mode = mode;
        camera->state->priority = priority;
    }
}

// Offsets the target yaw of the active request with the given priority.
void func_80112E50(u8 *camera, f32 offset, s32 priority)
{
    u8 *state;

    state = *(u8 **) ((s8 *) camera + 0x60);
    if ((*(s16 *) ((s8 *) state + 0xC) != 0) && (priority == *(s16 *) ((s8 *) state + 0xE))) {
        *(f32 *) ((s8 *) state + 0x10) = (f32) (*(f32 *) ((s8 *) state + 0x14) + offset);
    }
}

short func_80112E84(s16 *camera)
{
    return ((s16 *) *((int *) camera + 0x18))[6];
}
