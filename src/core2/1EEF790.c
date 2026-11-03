#include "core2/1EEF790.h"

// Camera sway component. State at camera+0x04, size 0x5C.
f32 func_800FF060(f32 param_0, f32 *param_1, f32 param_2, f32 param_3, f32 param_4, f32 param_5);
f32 mlAbsF(f32 param_0);
extern void func_800F2388();
extern f32 func_800F22EC(f32 *);
extern f32 func_800D8FF8(void);
typedef struct {
    u8 pad_0[0x28];
    f32 ref_yaw;
    u8 has_ref_yaw;
    u8 pad_2D;
    s16 enabled;
    f32 pad_30;
    f32 offset;
    f32 pad_38;
    f32 offset_vel;
    f32 target;
    f32 override_target;
    u8 override_set;
    u8 pad_49[3];
    f32 speed_2d;
    f32 pos_2d[2];
    f32 scale;
} Sway116218;
typedef struct {
    s32 pad_0;
    Sway116218 *sway;
} State116218;
extern s32 func_80110840(State116218 *);
extern f32 func_800F5F50(s32);
extern f32 func_800136E4(f32);
extern f32 func_800137AC(f32);
extern f32 func_800137C4(void);
void func_80116218();

// Component size.
s32 func_80115EA0()
{
    return 0x5C;
}

// Spring *value toward target; snaps and zeroes velocity on overshoot.
void func_80115EA8(f32 target, f32 *value, f32 *velocity, f32 unk_3, f32 unk_4, f32 unk_5)
{
    f32 diff;
    f32 dist;
    f32 step;

    diff = target - *value;
    dist = mlAbsF(diff);
    if (0.001f < dist) {
        step = func_800FF060(diff, velocity, unk_4, unk_5, unk_3, func_800D8FF8());
        if (dist < mlAbsF(step)) {
            *velocity = 0.0f;
            *value = target;
            return;
        }
        *value += step;
        return;
    }
    *velocity = 0.0f;
    *value = target;
}

// Matching: K&R parameter list, chained store and missing return are needed for the match.
int func_80115F98(vec)
f32 vec[3];
{
    f32 zero = 0.0;
    vec[1] = (vec[2] = zero);
    vec[0] = zero;
}

void func_80115FB0(u8 *camera)
{
    f32 zero;
    u8 *sway;

    func_80115F98(*(u8 **) ((s8 *) camera + 4), camera);
    func_80115F98(*(u8 **) ((s8 *) camera + 4) + 0x14, camera);
    // Matching: reading the zero back through the pointer is needed for the match.
    *(f32 *) ((s8 *) *(u8 **) ((s8 *) camera + 4) + 0x4C) = 0.0f;
    sway = *(u8 **) ((s8 *) camera + 4);
    zero = *(f32 *) ((s8 *) sway + 0x4C);
    *(f32 *) ((s8 *) sway + 0x54) = zero;
    *(f32 *) ((s8 *) *(u8 **) ((s8 *) camera + 4) + 0x50) = zero;
    *(s16 *) ((s8 *) *(u8 **) ((s8 *) camera + 4) + 0x2E) = 0;
    *(f32 *) ((s8 *) *(u8 **) ((s8 *) camera + 4) + 0x58) = 1.0f;
}

void func_80116024(u8 *camera)
{
    func_80116218();
    *(u8 *) ((u8 *) *(s8 **) ((char *) camera + 4) + 0x2C) = 0;
}

void func_80116050(u8 *camera, f32 amount)
{
    *(f32 *) ((s8 *) *(u8 **) ((s8 *) camera + 4) + 4) = amount;
    *(f32 *) ((s8 *) *(u8 **) ((s8 *) camera + 4) + 0x18) = (f32) (amount * 0.5f);
    *(f32 *) ((s8 *) *(u8 **) ((s8 *) camera + 4) + 0x40) = amount;
}

void func_8011607C(void *camera, s32 enabled)
{
    ((s16 *) *(void **) ((char *) camera + 0x4))[23] = enabled;
}

void func_80116088(u8 *camera, s32 unk_1)
{
    s8 pad[8];
    s32 unk_0;

    func_801107B0(camera, &unk_0);
    if (func_800F1E6C(&unk_0, unk_1, *(u8 **) (camera + 4) + 0x28) != 0) {
        (*(u8 **) (camera + 4))[0x2C] = 1;
    }
}

// Set the rotation override value.
void func_801160DC(PlayerState *camera, f32 value)
{
    u8 *sway;
    char *flag_ptr;
    u8 *sway_copy;
    *(f32 *) (char *) (*(u8 **) ((char *) camera + 4) + 0x20) = value;
    sway = *(u8 **) ((char *) camera + 4);
    *(f32 *) ((char *) sway + 0xC) = (f32) *(f32 *) ((char *) sway + 0x20);
    *(u8 *) (char *) (*(u8 **) ((char *) camera + 4) + 0x24) = 1U;
    // Matching: `if (1)` block is needed for the match.
    if (1) {
        sway_copy = *(u8 **) ((char *) camera + 4);
        *(u8 *) (flag_ptr = (char *) sway_copy + 0x10) = (u8) *(u8 *) ((char *) sway_copy + 0x24);
        *(f32 *) (char *) (*(u8 **) ((char *) camera + 4) + 0x44) = value;
        *(char *) (*(u8 **) ((char *) camera + 4) + 0x48) = 1;
    }
}

// 2D version of the spring approach.
void func_80116120(f32 *target, f32 *value, f32 *velocity, f32 unk_3, f32 unk_4, f32 unk_5)
{
    f32 delta[2];
    f32 dist;
    f32 step;
    f32 ratio;

    func_800F2388(delta, target, value);
    dist = func_800F22EC(delta);
    if (0.01f < dist) {
        step = func_800FF060(dist, velocity, unk_4, unk_5, unk_3, func_800D8FF8());
        if (dist < step) {
            ratio = 1.0f;
            *velocity = 0.0f;
        } else {
            ratio = step / dist;
        }
        value[0] += delta[0] * ratio;
        value[1] += delta[1] * ratio;
        return;
    }
    *velocity = 0.0f;
}

// Smooth the sway offset and apply it to the camera rotation.
void func_80116218(State116218 *camera, f32 *rot)
{
    f32 yaw;
    f32 value;
    f32 sin_yaw;
    f32 dir[3];
    yaw = camera->sway->has_ref_yaw ? camera->sway->ref_yaw
                                        : func_800F5F50(func_80110840(camera));
    yaw = func_800136E4(rot[1] - yaw + 180.0f);
    if (camera->sway->enabled) {
        if (camera->sway->override_set)
            value = camera->sway->override_target;
        else
            value = camera->sway->target;
    } else
        value = 0.0f;
    func_80115EA8(value, &camera->sway->offset, &camera->sway->offset_vel, 20.0f, 40.0f,
                  -10.0f);
    sin_yaw = func_800137AC(yaw);
    value = func_800137C4();
    dir[0] = -value * camera->sway->offset;
    dir[1] = sin_yaw * camera->sway->offset;
    func_80116120(dir, camera->sway->pos_2d, &camera->sway->speed_2d, 20.0f, 40.0f,
                  -10.0f);
    rot[0] += camera->sway->scale * (camera->sway->pos_2d[1] * 0.5f);
    rot[1] += camera->sway->scale * camera->sway->pos_2d[0];
    camera->sway->override_set = 0;
}

func_801163A0(s32 camera, f32 scale)
{
    *(f32 *) (*(s32 *) (camera + 0x4) + 0x58) = scale;
}
