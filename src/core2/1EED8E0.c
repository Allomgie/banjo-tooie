// TU-NOTE: third of the three units of the former 1EEC090 (from func_80113FF0 on); func_80113FF0 is only called from
// func_80114184, and this unit is only used by 1EE92B0 (1EEC780 is also used by 1EE9AB0 and the ba overlays).
// Functions of the earlier units are declared as their definitions are written (prototype for ANSI, empty list for
// K&R), so every call compiles as it did in the combined file.
#include "core2/1EEC090.h"
#include <types.h>

extern void func_800EF334(f32 *, f32);
extern void func_800EFB24(f32 *, f32 *, f32 *);
extern f32 func_800F0E00(f32, f32);
extern f32 func_800EEAD4(f32 *, f32 *);
extern void func_800EE7F8();
s32 func_800C6A7C(s32 param_0, s32 param_1, f32 *param_2, s32 param_3);
extern void *func_8010FF80(void *);
extern void *func_800A940C(void *);
typedef struct {
    s32 pad_0;
    f32 dist;
    u8 valid;
    u8 pad_9[3];
} Entry113FF0;
typedef struct {
    u8 pad_0[0x48];
    Entry113FF0 hits[7];
} State113FF0;
typedef struct {
    u32 flags;
    f32 dist;
    u8 valid;
    u8 pad_9[3];
} Hit114184;
typedef struct {
    s16 ring_pos;
    u8 unk_2, has_hit;
    u8 pad_4[0x10];
    f32 tri_vert[3];
    u8 pad_20[0x18];
    u32 tri_flags;
    f32 tri_normal[3];
    Hit114184 hits[7];
} State114184;
typedef struct {
    u8 pad_0[8];
    u32 flags;
} Surface114184;
extern f32 func_800EEAA4(f32 *, f32 *);
extern void func_800EF04C(f32 *, f32 *);
extern void func_800EF3DC(f32 *, f32 *);
extern void func_800CA8F4(void *, f32 *, f32 *);
extern s32 func_800CACEC(void *, f32 *, f32);
extern PlayerState *func_80110014(PlayerState *);
extern PlayerState *func_800F5EF8(s32);
extern s32 func_800F5898(void);
extern s32 func_800F6BE4(s32);
extern s32 func_800F6438(s32);
extern s32 func_800F6640(s32);
extern s32 func_800F6690(s32);
typedef struct {
    u8 pad_0[0x14];
    u16 unk_14;
    u8 pad_16[2];
    u16 unk_18;
} Marker11458C;
typedef struct {
    Marker11458C *marker;
    s32 pad_4;
    u32 pad_8_5 : 27;
    u32 unk_8_4 : 1;
    u32 unk_8_3 : 1;
    u32 pad_8_1 : 2;
    u32 unk_8_0 : 1;
} Entry11458C;
typedef struct {
    u8 pad_0[0x64];
    u32 pad_64_18 : 14;
    u32 unk_64_17 : 1;
    u32 pad_64_0 : 17;
    u8 pad_68[0x2C];
    u32 pad_94_15 : 17;
    u32 unk_94_14 : 1;
    u32 pad_94_0 : 14;
} Actor11458C;
extern void **func_800BE444(f32 *);
extern Entry11458C *func_800E9E88(void *);
extern Entry11458C *func_800E9EB4(void *);
extern Actor11458C *func_80106790(Marker11458C *);
extern s32 func_801072A8(Actor11458C *);
extern f32 func_800EC75C(Marker11458C *, f32 *);
typedef struct {
    u8 pad_0[2];
    u8 unk_2;
    u8 pad_3[9];
    f32 near_plane;
    u8 pad_10[0x3C];
    f32 hit_dist[1][3];
} Bounds114774;
extern f32 func_800F13F0(f32, f32);
extern f32 func_800C9588(void);
extern s32 func_800C954C(void);
typedef struct {
    u8 pad_0[3];
    u8 has_hit;
    u8 override_once;
    u8 pad_5[3];
    f32 near_override, near_plane, far_plane;
} State149;
extern void func_800BED18(s32 *, s32 *);
extern s32 func_800BCC58(void);
extern s32 func_800E36D0(s32 *, s32 *, f32 *, f32 *);
extern void func_800EE84C(f32 *, s32 *);
extern void func_800BCC28(f32 *, f32 *);
extern f32 func_800C5190(void *);
typedef struct {
    s32 flags;
    f32 dist;
    u8 valid;
    u8 pad_9[3];
} local_record;
typedef struct {
    s16 ring_pos;
    u8 unk_2, has_hit, override_once;
    u8 pad_5[3];
    f32 near_override;
    u8 pad_C[60];
    local_record hits[7];
} local_type;
extern void *heap_alloc(s32);

// Returns the index of the nearest valid hit, or -1.
s32 func_80113FF0(State113FF0 *state)
{
    f32 best_dist;
    s32 best_idx;
    s32 i;
    f32 dist;
    best_dist = -1.0f;
    best_idx = -1;
    for (i = 0; i < 7; i++) {
        if (state->hits[i].valid) {
            dist = state->hits[i].dist;
            if (best_idx == -1 || dist < best_dist) {
                best_dist = dist;
                best_idx = i;
            }
        }
    }
    return best_idx;
}

int func_8011413C(s32 cam, f32 *out, f32 length, s32 dir_index)
{
    if (dir_index != 0) {
        func_800CB0E8(cam, out, dir_index - 1);
    } else {
        func_800CA740(cam, out);
    }
    func_800EF334(out, length);
}

// Casts a probe ray from the camera and records the hit in the history ring.
s32 func_80114184(State114184 *state, s32 cam, f32 length, s32 trace, u32 ray_mask)
{
    f32 ray_end[3], cam_pos[3], cam_dir[3];
    f32 dist;
    f32 hit_pos[3];
    Surface114184 *surface;
    s32 i;
    f32 rel_pos[3];
    if (!trace) {
        func_80113FF0(state);
        return;
    }
    func_800CA8F4(cam, cam_pos, cam_dir);
    if (state->has_hit && func_800EEAA4(cam_dir, state->tri_normal) < 0.1f) {
        func_800EFB24(rel_pos, cam_pos, state->tri_vert);
        dist = func_800EEAA4(rel_pos, state->tri_normal);
        state->hits[6].flags = state->tri_flags;
        state->hits[6].valid = 1;
        state->hits[6].dist = dist;
    } else {
        state->hits[6].flags = 0;
        state->hits[6].dist = -1.0f;
        state->hits[6].valid = 0;
    }
    func_8011413C(cam, ray_end, length, state->ring_pos);
    func_800EF04C(ray_end, cam_pos);
    surface = func_800C6A7C(cam_pos, ray_end, hit_pos, ray_mask);
    if (surface) {
        dist = func_800EEAD4(cam_pos, ray_end);
        func_800EF3DC(ray_end, cam_pos);
        state->hits[state->ring_pos].flags = surface->flags;
        state->hits[state->ring_pos].valid = 1;
    } else {
        state->hits[state->ring_pos].flags = 0;
        dist = -1.0f;
        state->hits[state->ring_pos].valid = 0;
    }
    state->hits[state->ring_pos].dist = dist;
    state->ring_pos++;
    if (state->ring_pos >= 6)
        state->ring_pos = 0;
    state->unk_2 = 0;
    for (i = 0; i < 7; i++) {
        if (state->hits[i].flags) {
            if (state->hits[i].flags & 0x20020)
                state->unk_2 = 1;
            else {
                state->unk_2 = 0;
                break;
            }
        }
    }
    func_80113FF0(state);
}

// Lowers *min_dist to the sphere's distance along the camera direction; returns 1 if it did.
s32 func_801143A4(void *cam, f32 *center, f32 radius, f32 *min_dist)
{
    f32 pos[3];
    f32 dir[3];
    f32 to_center[3];
    f32 dist;
    func_800CA8F4(cam, pos, dir);
    func_800EFB24(to_center, center, pos);
    dist = func_800EEAA4(to_center, dir) - radius;
    if (dist < *min_dist && func_800CACEC(cam, center, radius)) {
        *min_dist = dist;
        return 1;
    }
    return 0;
}

f32 func_80114444()
{
    if (func_800F5410() == 0xD) {
        return 1.1f;
    }
    return 0.8f;
}

// Lowers *min_dist for the other players' camera targets.
int func_8011447C(PlayerState *cam, PlayerState *min_dist)
{
    s32 i;
    s32 found;
    f32 pos[3];
    f32 radius;
    found = 0;
    for (i = 0; i < func_800F5898(); i++) {
        // Matching: the duplicated call is needed for the match.
        if ((((func_800F6BE4(i) && func_800F6BE4(i)) && func_800F6438(i)) &&
             func_800F6640(i)) &&
            func_800F6690(i)) {
            radius = func_80112550(func_80110014(func_800F5EF8(i)), pos);
            found |= func_801143A4(cam, pos, radius * func_80114444(i), min_dist);
        }
    }
    return found;
}

// Lowers *min_dist for nearby marker actors (at least 25 if any).
s32 func_8011458C(f32 *cam, f32 *pos, f32 *min_dist)
{
    s32 found;
    f32 radius, radius_scale;
    Marker11458C *mark;
    Actor11458C *actor;
    f32 center[3];
    Entry11458C *entry, *entries_end;
    void **cells;
    cells = func_800BE444(pos);
    found = 0;
    if (*cells) {
        // Matching: the scale is kept in a local for the match.
        radius_scale = 0.8f;
        do {
            entry = func_800E9E88(*cells);
            entries_end = func_800E9EB4(*cells);
            for (; entry < entries_end; entry++) {
                if (!entry->unk_8_4 || !entry->unk_8_0 || entry->unk_8_3)
                    continue;
                mark = entry->marker;
                if (!(mark->unk_18 & 1))
                    continue;
                if (mark->unk_14 == 0 || mark->unk_14 == 0xFFFF)
                    continue;
                actor = func_80106790(mark);
                if (!actor->unk_94_14 || actor->unk_64_17 || func_801072A8(actor))
                    continue;
                radius = func_800EC75C(mark, center) * radius_scale;
                if (func_801143A4(cam, center, radius, min_dist)) {
                    found = 1;
                    if (*min_dist < 0.0f) {
                        *min_dist = 0.0f;
                        break;
                    }
                }
            }
            if (entry < entries_end)
                break;
            cells++;
        } while (*cells);
    }
    if (found && *min_dist < 25.0f)
        *min_dist = 25.0f;
    return found;
}

// Near plane limited by wall hits, other players and nearby marker actors.
f32 func_80114774(Bounds114774 *state, void *cam, s32 camera, void *pos)
{
    f32 dist;
    f32 near_plane;
    f32 min_near;
    s32 hit_idx;
    f32 ray_len;
    f32 wall_dist;
    ray_len = func_800F0E00(350.0f, state->near_plane);
    hit_idx = func_80114184(state, cam, ray_len, 1, 0x820020);
    near_plane = state->near_plane;
    if (hit_idx != -1) {
        wall_dist = state->hit_dist[hit_idx][0] * 0.8f - 15.0f;
        near_plane = func_800F13F0(near_plane, wall_dist);
    }
    dist = near_plane;
    if (func_8011447C(cam, &dist)) {
        if (dist < 0.0f)
            dist = 0.0f;
        near_plane = func_800F13F0(near_plane, dist);
    }
    dist = near_plane;
    if (near_plane > 25.0f && func_8011458C(cam, pos, &dist))
        near_plane = func_800F13F0(near_plane, dist);
    if (func_800C954C())
        near_plane = func_800F13F0(near_plane, func_800C9588() * 0.8f);
    min_near = state->unk_2 ? 25.0f : 10.0f;
    if (near_plane < min_near)
        near_plane = min_near;
    return near_plane;
}

// Computes the far plane from the map bounds seen from the camera, then the near plane.
void func_8011490C(State149 *state, s32 camera, s32 unk_2)
{
    f32 cam_pos[3];
    f32 cam_dir[3];
    s32 bbox_min[3];
    s32 bbox_max[3];
    void *cam;
    s32 i;
    f32 corner_min[3];
    f32 corner_max[3];
    f32 scale;
    cam = func_8010FF80(camera);
    func_800BED18(bbox_min, bbox_max);
    func_800CA8F4(cam, cam_pos, cam_dir);
    if (func_800BCC58()) {
        func_800EE84C(corner_min, bbox_min);
        func_800EE84C(corner_max, bbox_max);
        func_800BCC28(corner_min, corner_min);
        func_800BCC28(corner_max, corner_max);
        for (i = 0; i < 3; i++) {
            if (corner_min[i] < bbox_min[i])
                bbox_min[i] = corner_min[i];
            if (bbox_max[i] < corner_max[i])
                bbox_max[i] = corner_max[i];
            if (bbox_max[i] < corner_min[i])
                bbox_max[i] = corner_min[i];
            if (corner_max[i] < bbox_min[i])
                bbox_min[i] = corner_max[i];
        }
    }
    state->far_plane = func_800E36D0(bbox_min, bbox_max, cam_pos, cam_dir) + 100.0f;
    if (state->far_plane < 1000.0f)
        state->far_plane = 1000.0f;
    else if (32000.0f < state->far_plane)
        state->far_plane = 32000.0f;
    state->near_plane = state->far_plane * 0.0078125f;
    if (state->near_override > 0.0f)
        state->near_plane = state->near_override;
    else if (state->near_plane < 10.0f)
        state->near_plane = 10.0f;
    else
        state->near_plane =
            func_800F13F0(state->near_plane, func_80114774(state, cam, camera, cam_pos));
    scale = 1.0f / func_800C5190(func_800A940C(unk_2));
    if (scale != 1.0f) {
        state->near_plane *= scale;
        state->far_plane *= scale;
    }
    if (state->near_override > 0.0f && state->override_once) {
        state->override_once = 0;
        state->near_override = 0.0f;
    }
    state->has_hit = 0;
}

// Allocates and initializes the clip-plane state.
local_type *func_80114BD4(void)
{
    local_type *state;
    s32 i;
    state = heap_alloc(sizeof(local_type));
    state->unk_2 = 0;
    state->ring_pos = 0;
    state->has_hit = 0;
    state->override_once = 0;
    state->near_override = 0.0f;
    for (i = 0; i < 7; i++) {
        state->hits[i].flags = 0;
        state->hits[i].dist = -1.0f;
        state->hits[i].valid = 0;
    }
}

void func_80114C7C(void *state)
{
    heap_free(state);
}

// Returns the near and far plane.
int func_80114C9C(f32 state[3], f32 *near_out, f32 *far_out)
{
    *near_out = *(f32 *) ((s8 *) state + 12);
    *far_out = state[4];
}

// Sets the near-plane override.
func_80114CB0(s32 state, f32 value)
{
    *(s8 *) (state + 4) = 0;
    *(f32 *) (state + 8) = value;
}

// Sets a one-shot near-plane override.
func_80114CC0(s32 *state, f32 value)
{
    *(s8 *) ((char *) state + 4) = 1;
    *(f32 *) ((char *) state + 8) = value;
}

void *func_80114CD4(void *state)
{
    return defrag(state);
}

// Records a collision-triangle hit (vertices, flags, normal).
void func_80114CF4(state, verts, flags, normal) u8 *state;
s32 verts;
s32 flags;
s32 normal;
{
    s32 offset;
    s32 dst;
    s32 src;
    if (!(flags & 0x40000)) {
        offset = 0;
        dst = state + 0x14;
        src = verts;
        do {
            func_800EE7F8(dst, src);
            offset += 0xC;
            dst += 0xC;
            src += 0xC;
        } while (offset != 0x24);
        func_800EE7F8(state + 0x3C, normal);
        *(s32 *) ((s8 *) state + 0x38) = flags;
        *(s8 *) ((s8 *) state + 3) = 1;
    }
}
