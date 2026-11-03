#include "common.h"

extern float D_8012B010;
extern void func_800BD708(s32 *, s32 *, f32 *, f32 *, f32);
extern s32 func_800BDAD4(s32 *);
extern s32 func_800BDC44(void);
extern s32 func_800EA628(s32, f32 *, f32 *, s32, s32);
typedef struct CollisionCD CollisionCD;
extern CollisionCD *func_800EAA2C(void *, f32 *, f32 *, f32, f32 *, s32, u32);
extern s32 func_800EADFC(s32, f32 *, f32, s32, s32);
typedef struct LocalMarker LocalMarker;
typedef struct {
    u8 pad_0[0xC];
    s32 (*field_C)(LocalMarker *, f32 *, f32, f32 *, u32);
} LocalCallbacks_800CD6B4;
extern void func_800EE7F8(f32 *, f32 *);
extern void func_800EF04C(f32 *, f32 *);
extern f32 func_800EC75C(LocalMarker *, f32 *);
extern f32 func_800EEB40(f32 *, f32 *);
typedef struct {
    u8 pad_0[0x10];
    s32 (*field_10)(LocalMarker *, LocalMarker *);
} LocalCallbacks_800CD820;
typedef struct {
    LocalMarker *field_0;
    u8 pad_4[4];
    u32 pad_8 : 27, field_B4 : 1, pad_B : 3, field_B0 : 1;
} LocalEntry;
typedef struct {
    u8 pad_0[0x64];
    u32 pad_64 : 14, field_65 : 1, pad_65 : 1, field_66 : 16;
} LocalActor;
extern s32 func_800CB854(s32);
extern void func_800EFB24(f32 *, f32 *, f32 *);
extern void func_800EF410(f32 *, f32 *);
extern f32 func_800EEF94(f32 *);
extern void func_800EFE50(f32 *, f32 *, f32 *, f32);
extern void **func_800BE444(f32 *);
extern void func_800EFA20(f32 *, f32 *, f32);
extern void func_800EE88C(f32 *, s16 *);
extern LocalEntry *func_800E9E88(void *);
extern LocalEntry *func_800E9EB4(void *);
extern LocalActor *func_80106790(LocalMarker *);
extern f32 _subaddiecustomhits_entrypoint_5(LocalActor *, f32 *);
extern LocalCallbacks_800CD820 *func_800EC3C4(LocalMarker *);
typedef struct {
    u8 pad_0[0xC];
    s32 (*field_C)(LocalMarker *, f32 *, f32, f32 *, u32);
    s32 (*field_10)(LocalMarker *, LocalMarker *);
} LocalCallbacks_800CDBA8;
typedef struct {
    LocalMarker *field_0[32];
    u8 field_80[32];
} LocalResults;
extern LocalResults D_8012AF70;
extern u8 D_8012AFF0[];
extern void func_800EF334(f32 *, f32);
extern f32 func_800EEAD4(f32 *, f32 *);

// TU-NOTE: the .rodata of this file starts with these constants. Each is a
// 16-byte object; its zero words belong to it (see the ROM alignment).
const struct {
    f32 x;
    f32 y;
    f32 pad[2];
} D_801259A0 = {1.1f, 1.1f};

// Sets the margin added to query radii.
void func_800CD230(f32 param_0)
{
    D_8012B010 = param_0;
}

// Line test against the props of every cube the segment touches, plus the global cube.
s32 func_800CD23C(f32 *start, f32 *end, s32 param_2, s32 param_3)
{
    s32 cube[3];
    s32 cube_min[3];
    s32 cube_max[3];
    s32 hit;
    s32 result;
    result = 0;
    func_800BD708(cube_min, cube_max, start, end, D_8012B010);
    cube_min[1]--;
    for (cube[2] = cube_min[2]; cube[2] <= cube_max[2]; cube[2]++) {
        for (cube[1] = cube_min[1]; cube[1] <= cube_max[1]; cube[1]++) {
            for (cube[0] = cube_min[0]; cube[0] <= cube_max[0]; cube[0]++) {
                hit = func_800EA628(func_800BDAD4(cube), start, end, param_2, param_3);
                if (hit)
                    result = hit;
            }
        }
    }
    hit = func_800EA628(func_800BDC44(), start, end, param_2, param_3);
    if (hit)
        result = hit;
    return result;
}

// Swept-sphere test over the same cube range.
CollisionCD *func_800CD3A8(f32 *start, f32 *end, f32 radius, f32 *param_3, s32 param_4,
                           u32 param_5)
{
    s32 cube[3];
    s32 cube_min[3];
    s32 cube_max[3];
    void *global_cube;
    void *cube_props;
    CollisionCD *hit;
    CollisionCD *result = 0;
    func_800BD708(cube_min, cube_max, start, end, radius + D_8012B010);
    cube_min[1]--;
    for (cube[0] = cube_min[0]; cube[0] <= cube_max[0]; cube[0]++) {
        for (cube[1] = cube_min[1]; cube[1] <= cube_max[1]; cube[1]++) {
            for (cube[2] = cube_min[2]; cube[2] <= cube_max[2]; cube[2]++) {
                cube_props = func_800BDAD4(cube);
                hit =
                    func_800EAA2C(cube_props, start, end, radius, param_3, param_4, param_5);
                result = hit ? hit : result;
            }
        }
    }
    global_cube = func_800BDC44();
    hit = func_800EAA2C(global_cube, start, end, radius, param_3, param_4, param_5);
    result = hit ? hit : result;
    return result;
}

// Sphere test over the same cube range.
s32 func_800CD544(f32 *pos, f32 radius, s32 param_2, s32 param_3)
{
    s32 cube[3];
    s32 cube_min[3];
    s32 cube_max[3];
    s32 hit;
    s32 result;
    s32 local_5;
    result = 0;
    func_800BD708(cube_min, cube_max, pos, pos, radius + D_8012B010);
    cube_min[1]--;
    for (cube[0] = cube_min[0]; cube[0] <= cube_max[0]; cube[0]++) {
        for (cube[1] = cube_min[1]; cube[1] <= cube_max[1]; cube[1]++) {
            for (cube[2] = cube_min[2]; cube[2] <= cube_max[2]; cube[2]++) {
                hit = func_800EADFC(func_800BDAD4(cube), pos, radius, param_2, param_3);
                if (hit)
                    result = hit;
            }
        }
    }
    hit = func_800EADFC(func_800BDC44(), pos, radius, param_2, param_3);
    if (hit)
        result = hit;
    return result;
}

struct LocalMarker {
    u8 pad_0[0xC];
    LocalCallbacks_800CD6B4 *(*field_C)(void);
    u8 pad_10[8];
    u32 pad_18 : 11, field_19 : 4, pad_19 : 12, field_1B : 4, pad_1B : 1;
};

// Moves a sphere along step count times; true when the marker is hit by it.
s32 func_800CD6B4(LocalMarker *marker, f32 *pos, f32 radius, f32 *step, s32 count)
{
    s32 i;
    f32 sphere_pos[3];
    s32 hit;
    f32 unk_0[3];
    LocalCallbacks_800CD6B4 *callbacks;
    f32 marker_radius;
    f32 marker_pos[3];
    callbacks = marker->field_C ? marker->field_C() : 0;
    func_800EE7F8(sphere_pos, pos);
    for (i = 0; i < count; i++) {
        if (callbacks && callbacks->field_C) {
            hit = callbacks->field_C(marker, sphere_pos, radius, unk_0, marker->field_1B);
            if (hit) {
                marker->field_19 = hit;
                return 1;
            }
        } else {
            marker_radius = func_800EC75C(marker, marker_pos);
            if (func_800EEB40(sphere_pos, marker_pos) < (marker_radius + radius) * (marker_radius + radius))
                return 1;
        }
        func_800EF04C(sphere_pos, step);
    }
    return 0;
}

struct LocalMarker_800CD820 {
    u8 pad_0[0x14];
    u16 field_14, pad_16;
    u16 pad_18 : 15, field_19 : 1;
    u8 pad_1A[4];
    s16 field_1E[3];
    u8 pad_24[4];
    u32 pad_28 : 22, field_2A : 1, pad_2A : 9;
};

// Sweeps a sphere from start to end through nearby actors; returns the closest actor hit.
struct LocalMarker_800CD820 *func_800CD820(struct LocalMarker_800CD820 *self, f32 *start,
                                           f32 *end, f32 radius)
{
    f32 length;
    f32 tmp_a;
    f32 tmp_b;
    f32 delta[3];
    f32 dir[3];
    f32 offset[3];
    f32 stride[3];
    f32 closest_dist;
    f32 step[3];
    f32 sphere_pos[3];
    void **cube_list;
    f32 center[3];
    f32 unk_0[2];
    u32 attack_mask;
    LocalEntry *entry;
    LocalEntry *entry_end;
    struct LocalMarker_800CD820 *other;
    struct LocalMarker_800CD820 *closest;
    LocalActor *other_actor;
    LocalCallbacks_800CD820 *other_callbacks;
    f32 other_pos[3];
    s32 steps;
    f32 steps_floor;
    if (func_800CB854(0))
        attack_mask = 1 << (func_800CB854(0) + 31);
    else
        attack_mask = 0;
    func_800EFB24(delta, end, start);
    length = func_800EEF94(delta);
    func_800EF410(dir, delta);
    tmp_a = radius + radius;
    tmp_b = length / tmp_a;
    steps = (s32) tmp_b;
    steps_floor = (s32) tmp_b;
    if (steps_floor <= tmp_b)
        steps++;
    func_800EFE50(center, start, end, 0.5f);
    cube_list = func_800BE444(center);
    closest = 0;
    closest_dist = 0.0f;
    func_800EFA20(stride, dir, tmp_a);
    func_800EFA20(offset, stride, (tmp_b - steps_floor) * 0.5f);
    func_800EE7F8(step, offset);
    func_800EE88C(sphere_pos, self->field_1E);
    func_800EF04C(sphere_pos, start);
    func_800EF04C(sphere_pos, step);
    func_800EE7F8(step, stride);
    while (*cube_list) {
        entry = func_800E9E88(*cube_list);
        entry_end = func_800E9EB4(*cube_list);
        for (; entry < entry_end; entry++) {
            if (!entry->field_B4 || !entry->field_B0)
                continue;
            other = entry->field_0;
            if (!other->field_2A || self == other || !other->field_14 ||
                other->field_14 == 0xFFFF || !other->field_19)
                continue;
            other_actor = func_80106790(other);
            if (other_actor->field_65 || (other_actor->field_66 & attack_mask))
                continue;
            tmp_a = steps * radius * D_801259A0.x;
            tmp_b = _subaddiecustomhits_entrypoint_5(other_actor, other_pos);
            if ((tmp_b + tmp_a) * (tmp_b + tmp_a) < func_800EEB40(other_pos, center))
                continue;
            tmp_a = func_800EEB40(other_pos, sphere_pos);
            if (closest && closest_dist < tmp_a)
                continue;
            other_callbacks = func_800EC3C4(other);
            if (other_callbacks->field_10 && !other_callbacks->field_10(other, self))
                continue;
            if (func_800CD6B4(other, sphere_pos, radius, step, steps)) {
                closest = other;
                closest_dist = tmp_a;
            }
        }
        cube_list++;
    }
    return closest;
}

struct LocalMarker_800CDBA8 {
    u8 pad_0[0xC];
    LocalCallbacks_800CDBA8 *(*field_C)(void);
    u8 pad_10[4];
    u16 field_14, pad_16;
    u32 pad_18 : 11, field_19 : 4, field_19b : 1, pad_1A : 11, field_1B : 4, pad_1B : 1;
    u8 pad_1C[0xC];
    u32 pad_28 : 22, field_2A : 1, pad_2A : 9;
};

// Tests count spheres against nearby actors. Records hits in D_8012AF70 and returns
// their number (at most 32).
s32 func_800CDBA8(struct LocalMarker_800CDBA8 *self, f32 centers[][3], f32 *radii, s32 count)
{
    f32 sphere_radius;
    void **cube_list;
    f32 center[3];
    f32 radius;
    f32 other_radius;
    f32 other_pos[3];
    s32 i;
    u32 attack_mask;
    LocalCallbacks_800CDBA8 *other_callbacks;
    struct LocalMarker_800CDBA8 *other;
    LocalActor *other_actor;
    // Matching: one-element array needed for the match.
    LocalEntry *entry[1];
    LocalEntry *entry_end;
    s32 hit;
    LocalCallbacks_800CDBA8 *hit_callbacks;
    f32 unk_0[3];
    s32 num_hits = 0;
    if (func_800CB854(0))
        attack_mask = 1 << (func_800CB854(0) + 31);
    else
        attack_mask = 0;
    func_800EE7F8(center, centers[0]);
    for (i = 1; i < count; i++)
        func_800EF04C(center, centers[i]);
    func_800EF334(center, 1.0f / count);
    radius = radii[0] + func_800EEAD4(center, centers[0]);
    for (i = 1; i < count; i++) {
        sphere_radius = radii[i] + func_800EEAD4(center, centers[i]);
        if (radius < sphere_radius)
            radius = sphere_radius;
    }
    radius *= D_801259A0.y;
    cube_list = func_800BE444(center);
    while (*cube_list) {
        entry[0] = func_800E9E88(*cube_list);
        entry_end = func_800E9EB4(*cube_list);
        for (; entry[0] < entry_end; entry[0]++) {
            if (!entry[0]->field_B4 || !entry[0]->field_B0)
                continue;
            other = entry[0]->field_0;
            if (!other->field_2A || self == other || !other->field_14 ||
                other->field_14 == 0xFFFF || !other->field_19b)
                continue;
            other_actor = func_80106790(other);
            if (other_actor->field_65 || (other_actor->field_66 & attack_mask))
                continue;
            other_radius = _subaddiecustomhits_entrypoint_5(other_actor, other_pos);
            if ((other_radius + radius) * (other_radius + radius) < func_800EEB40(other_pos, center))
                continue;
            other_callbacks = func_800EC3C4(other);
            if (other_callbacks->field_10 && !other_callbacks->field_10(other, self))
                continue;
            hit_callbacks = other->field_C ? other->field_C() : 0;
            for (i = 0; i < count; i++) {
                if (hit_callbacks && hit_callbacks->field_C) {
                    hit = hit_callbacks->field_C(other, centers[i], radii[i],
                                                 unk_0, other->field_1B);
                    if (hit) {
                        other->field_19 = hit;
                        D_8012AFF0[num_hits] = i;
                        D_8012AF70.field_0[num_hits] = other;
                        num_hits++;
                        break;
                    }
                } else {
                    other_radius = func_800EC75C(other, other_pos);
                    if (func_800EEB40(centers[i], other_pos) <
                        (radii[i] + other_radius) * (radii[i] + other_radius)) {
                        D_8012AF70.field_80[num_hits] = i;
                        D_8012AF70.field_0[num_hits] = other;
                        num_hits++;
                        break;
                    }
                }
            }
        }
        cube_list++;
    }
    return num_hits;
}

// Reads hit number index from D_8012AF70: returns the actor, stores the sphere index.
int func_800CDFA8(s32 index, u8 *sphere_out)
{
    *(s32 *) sphere_out = ((u8 *) &D_8012AF70)[index + 0x80];
    return ((s32 *) (u8 *) &D_8012AF70)[index];
}
