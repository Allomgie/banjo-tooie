#include "common.h"

extern f32 D_80135AA0;
void func_80102424(s32, s32);
typedef struct {
    u8 pad0[0x48];
    f32 yaw;
    u8 pad4C[8];
    f32 target_yaw;
} S_1028C4;
extern void func_800F2094(f32, f32);
extern f32 func_800136E4(f32);
f32 func_800DC0C0(void);
typedef struct {
    u8 pad[0x74];
    u32 pad74_0 : 27;
    u32 snap : 1;
    u32 pad74_28 : 4;
} Actor102A04;
extern f32 func_80013728(f32);
extern f32 func_800F1FF0(f32, f32, f32, f32, f32);
extern f32 func_800D8FF8(void);
extern s32 func_800F20BC(f32, f32, f32);
extern s32 func_800DC298(f32);
void func_80102924(void *param_0, f32 param_1);
void func_80102B2C(void *param_0, f32 param_1);
s32 func_80102CF4(s32, f32);
f32 func_80102D78();

// Reads the actor rotation.
int func_80102780(f32 actor[3], f32 rotation[3])
{
    rotation[0] = actor[17];
    rotation[1] = actor[18];
    rotation[2] = actor[19];
}

// Writes the actor rotation, normalising each angle.
void func_8010279C(f32 *actor, f32 *rotation)
{
    actor[17] = func_800136E4(rotation[0]);
    actor[18] = func_800136E4(rotation[1]);
    actor[19] = func_800136E4(rotation[2]);
}

// Returns the actor rotation, mirrored when the actor is flipped.
f32 *func_801027F4(u8 *actor)
{
    if (((u32) *(u32 *) (actor + 0x94) >> 0x1F) != 0) {
        func_80102780(actor, &D_80135AA0);
        D_80135AA0 = -D_80135AA0;
        return &D_80135AA0;
    }
    return (f32 *) (actor + 0x44);
}

// Turns toward a point and starts animation `anim_index` once facing it.
s32 func_80102844(s32 actor, f32 max_step, s32 anim_index, s32 target)
{
    func_80102924(actor, func_80102D78(actor, target));
    func_80102B2C(actor, max_step);
    if (func_80102CF4(actor, 10.0f) != 0) {
        if (anim_index != -1) {
            func_80102424(actor, anim_index);
        }
        return 1;
    }
    return 0;
}

// Eases yaw toward a point.
void func_801028C4(S_1028C4 *actor, s32 target, f32 param_2, f32 param_3, f32 param_4)
{
    actor->target_yaw = func_80102D78(actor, target);
    actor->yaw = func_800F1FF0(actor->yaw, actor->target_yaw, param_2, param_3, param_4);
    func_800F2094(actor->yaw, actor->target_yaw);
}

// Sets the target yaw.
void func_80102924(void *actor, f32 yaw)
{
    *(f32 *) ((u8 *) actor + 0x54) = func_800136E4(yaw);
}

// Sets the target pitch.
void func_80102950(void *actor, f32 pitch)
{
    *(f32 *) ((u8 *) actor + 0x50) = func_800136E4(pitch);
}

// Sets the target yaw to a random offset from `yaw`.
void func_8010297C(s32 actor, f32 yaw, f32 min_offset, f32 max_offset)
{
    f32 offset;

    offset = 2.0f * ((func_800DC0C0() - 0.5f) * (max_offset - min_offset));
    func_80102924(actor, (offset >= 0.0f ? min_offset : -min_offset) + (yaw + offset));
}

// Steps `current` toward `target` by at most `max_step`; snaps for large differences when the snap flag is set.
f32 func_80102A04(Actor102A04 *actor, f32 current, f32 target, s32 max_step)
{
    f32 diff;
    if (target == current)
        return current;
    diff = func_80013728(target - current);
    if (actor->snap && (diff >= 50.0f || diff < -50.0f))
        return target;
    diff = (diff > 0.0f) ? ((diff < max_step) ? diff : max_step)
                               : ((diff > -max_step) ? diff : -max_step);
    diff += current;
    return func_800136E4(diff);
}

// Turns yaw toward the target yaw.
void func_80102B2C(void *actor, f32 max_step)
{
    *(f32 *) ((char *) actor + 0x48) =
        func_80102A04(actor, *(f32 *) ((char *) actor + 0x48),
                      *(f32 *) ((char *) actor + 0x54), (s32) max_step);
}

// Turns pitch toward the target pitch.
void func_80102B6C(u8 *actor, f32 max_step)
{
    *(f32 *) ((s8 *) actor + 0x44) = func_80102A04(
        actor, *(f32 *) ((s8 *) actor + 0x44), *(f32 *) ((s8 *) actor + 0x50), (s32) max_step);
}

void func_80102BAC(Actor *actor, f32 param_1, f32 param_2, f32 param_3)
{
    *(f32 *) ((u8 *) actor + 0x48) =
        func_800F1FF0(*(f32 *) ((u8 *) actor + 0x48), *(f32 *) ((u8 *) actor + 0x54), param_1,
                      param_2, param_3);
}

void func_80102BF8(u8 *actor, f32 param_1, f32 param_2, f32 param_3)
{
    f32 unk_0;

    unk_0 = func_800D8FF8();
    *(f32 *) ((s8 *) actor + 0x48) =
        func_800F1FF0(*(f32 *) ((s8 *) actor + 0x48), *(f32 *) ((s8 *) actor + 0x54), param_1,
                      unk_0 * param_2, unk_0 * param_3);
}

void func_80102C58(Actor *actor, f32 param_1, f32 param_2, f32 param_3)
{
    *(f32 *) ((u8 *) actor + 0x44) =
        func_800F1FF0(*(f32 *) ((u8 *) actor + 0x44), *(f32 *) ((u8 *) actor + 0x50), param_1,
                      param_2, param_3);
}

void func_80102CA4(long actor)
{
    func_800F20BC(*(float *) ((char *) actor + 0x44), *(float *) ((char *) actor + 0x50), 3.0f);
}

void func_80102CCC(long actor)
{
    func_800F20BC(*(float *) (actor + 0x48), *(float *) (actor + 0x54), 3.0f);
}

// True if yaw is within tolerance of the target yaw.
s32 func_80102CF4(s32 actor, f32 tolerance)
{
    func_800F20BC(*(f32 *) (actor + 0x48), *(f32 *) (actor + 0x54), tolerance);
}

s32 func_80102D20(void *actor, f32 tolerance, f32 angle)
{
    return func_800F20BC(*(f32 *) ((u8 *) actor + 0x48), angle, tolerance);
}

// True if pitch is within tolerance of the target pitch.
s32 func_80102D4C(s32 actor, f32 tolerance)
{
    func_800F20BC(*(f32 *) (actor + 0x44), *(f32 *) (actor + 0x50), tolerance);
}

f32 func_80102D78(actor)
s32 actor;
{
    s32 pos;
    pos = actor + 4;
    func_800F1DF4(pos);
}

s32 func_80102D98(u8 *actor, s32 param_1, s32 param_2, f32 chance, f32 min_offset, f32 max_offset)
{
    if (func_8001210C(((u32) *(u16 *) ((u8 *) *(u8 **) actor + 0x12) >> 1) & param_1) ==
        param_2) {
        if (func_800DC298(chance) != 0) {
            func_8010297C(actor, *(f32 *) ((u8 *) actor + 0x48), min_offset, max_offset);
            return 1;
        }
    }
    return 0;
}

// Aligns pitch and roll to the floor slope using a down raycast.
s32 func_80102E08(u8 *actor)
{
    f32 ray_start[3];
    f32 ray_end[3];
    f32 normal[3];
    s32 aligned;
    f32 angles[3];

    aligned = 0;
    func_800EE7F8(ray_start, actor + 4);
    func_800EE7F8(ray_end, actor + 4);
    ray_start[1] += 50.0f;
    ray_end[1] -= 50.0f;
    if (func_800BEF00(ray_start, ray_end, normal, *(s32 **) ((char *) actor + 0x14)) != 0) {
        *(f32 *) ((char *) actor + 8) = ray_end[1];
        if (func_800F1B78(angles, normal, *(s32 **) ((char *) actor + 0x48), 0x3F800000) != 0) {
            *(f32 *) ((char *) actor + 0x44) = angles[0];
            *(f32 *) ((char *) actor + 0x4C) = angles[2];
            aligned = 1;
        }
    }
    return aligned;
}
