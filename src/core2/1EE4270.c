#include "common.h"

extern u32 func_8010A698();
extern s32 func_8010A654(void *, s32);
extern u8 D_80136F20[];
typedef struct {
    s32 unk_0;
    f32 unk_4, unk_8;
    s32 unk_C, unk_10, unk_14;
    u8 unk_18;
    u8 pad_19[3];
    void *unk_1C;
    u8 pad_20[0x24];
    f32 normal[3];
    s32 unk_50;
    u8 unk_54, collided, unk_56, unk_57;
} CollisionAAC0;
typedef struct {
    u8 pad_0[0x20];
    s16 unk_20;
} MarkerAAC0;
typedef struct {
    MarkerAAC0 *marker;
    f32 position[3];
    s32 pad_10;
    s32 flags;
} ActorAAC0;
extern f32 D_80136F30[3];
extern void func_8010A624(Actor *);
extern f32 func_800EEAA4(f32 *, f32 *);
extern void func_800D4584(CollisionAAC0 *, f32 *, f32 *, f32 *);
extern void func_800EFB24(f32 *, f32 *, f32 *);
extern void func_800EE7F8();
extern void func_800EF410(f32 *, f32 *);
extern f32 func_800EC708(s32);
extern f32 func_8010A40C();
extern s32 func_800BF340(void *, void *, void *, s32, f32);
extern s32 func_800BF0E0(f32 *, f32 *, f32, f32 *, s32, s32);
extern s32 func_800CC6CC(s32, s32);
void func_800EF214(f32 *, f32, f32, f32);
void func_800EF1B8(f32 *, f32, f32, ...);
f32 func_8010C4AC();
typedef struct {
    s32 pad_0;
    f32 position[3];
    s32 pad_10;
    s32 flags;
    u8 pad_18[28];
    f32 vertical;
    u8 pad_38[86];
    s16 collision;
} Actor10B1F4;
typedef struct {
    s32 pad_0[2];
    s32 unk_8;
} Hit10B1F4;
extern f32 D_80136F40[3];
extern f32 func_800D8FF8(void);
extern f32 func_800F13F0(f32, f32);
extern Hit10B1F4 *func_800BEF00(f32 *, f32 *, f32 *, s32);
typedef struct {
    void *marker;
    f32 position[3];
    void *pad_10;
    s32 flags;
    u8 pad_18[0x1C];
    f32 vertical;
    u8 pad_38[0x56];
    s16 collision;
} LocalActor_8010B330;
extern s32 *func_800C6A7C(f32 *, f32 *, f32 *, s32);
extern void func_801045AC(void *, f32 *, f32 *, s32);
typedef struct {
    void *marker;
    f32 position[3];
    void *pad_10;
    s32 flags;
    u8 pad_18[0x1C];
    f32 vertical;
    u8 pad_38[0x56];
    s16 collision;
} LocalActor_8010B410;
typedef struct {
    s32 pad_0;
    f32 position[3];
    s32 pad_10;
    s32 flags;
    u8 pad_18[0x1C];
    f32 vertical;
    u8 pad_38[0x56];
    s16 collision;
} State10B514;
extern f32 func_800BED50(void *, s32);
typedef struct {
    u8 pad_0[4];
    f32 position[3];
    u8 pad_10[0x60];
    u32 spline_id : 7;
    u32 unk_70_7 : 15;
    u32 spline_node : 6;
    u32 unk_70_28 : 4;
} local_type;
extern s32 func_800CC338(f32 *, s32, s32);
typedef struct {
    u8 pad_0[4];
    f32 position[3];
    u8 pad_10[0x18];
    f32 velocity[3];
    f32 accel_y;
} S_10B8A4;
extern void func_800EFA20(f32 *, f32 *, f32);
extern void func_800EF04C(f32 *, f32 *);
void func_800EF174(s32, s32, f32);
typedef s32 (*LocalCallback)(Actor *, f32 *, s32, s32);
extern LocalCallback *D_80124714[6];
extern void func_80104580(void);
extern void func_800EFA4C(f32 *, f32, f32, f32);
extern f32 func_800DC0C0(void);
extern void func_800EF368(f32 *, f32);
typedef struct {
    u8 pad_0[4];
    f32 position[3];
    u8 pad_10[0x28];
    f32 scale;
    u8 pad_3C[0x24];
    u32 unk_60 : 16;
    u32 radius : 16;
    u8 pad_64[0x24];
    s16 bottom, top;
} LocalBoundsActor;
typedef struct {
    u8 pad_0[0x18];
    u16 flags;
} LocalMarker;
typedef struct {
    LocalMarker *marker;
    f32 position[3];
    u8 pad_10[0x60];
    u16 flags70;
    u8 pad_72[2], flags74;
} LocalActor_8010BDB0;
typedef struct {
    LocalMarker *marker;
    s32 pad_4;
    u32 flags;
} LocalEntry;
extern LocalActor_8010BDB0 *func_80106790(LocalMarker *);
extern s32 func_80102F74(LocalActor_8010BDB0 *, u32);
extern void _chflamer_entrypoint_1(LocalActor_8010BDB0 *, LocalMarker *);
void func_80102844(f32 *param_0, f32 param_1, s32 param_2, s32 param_3);
extern s32 func_800F1EA4(f32 *, f32 *);
extern f32 func_800F1DF4(f32 *, f32 *);
extern f32 func_800F1DCC(f32, f32);
extern f32 func_800136E4(f32);
extern f32 func_800EEF94(f32 *);
extern f32 func_800138D0(f32);
typedef struct {
    u8 pad_0[0x18];
    u16 flags;
} Marker10C100;
typedef struct {
    Marker10C100 *marker;
    f32 position[3];
    u8 pad_10[0x60];
    u16 flags70;
    u8 pad_72[2];
    u8 flags74;
} Actor10C100;
typedef struct {
    Marker10C100 *marker;
    s32 pad_4;
    u32 flags;
} Entry10C100;
extern f32 func_80103F38(Actor10C100 *, f32 *);
extern void **func_800BE3F8(f32 *);
extern Entry10C100 *func_800E9E88(void *);
extern Entry10C100 *func_800E9EB4(void *);
extern f32 func_800EEFD4(s32 *);
f32 func_800BECCC(void);
s32 func_8010108C();
void func_800FFAB0();
s32 func_8010C2D8(s32 param_0, s32 param_1, f32 param_2, Actor10C100 *param_3);
s32 func_8010C3E8();
f32 func_8010C460();

// Wall sweep: ray from the previous to the current position, both raised by 4.
int func_8010A980(void *actor, f32 *prev_pos, u32 move_word, s32 result_mask)
{
    f32 from_pos[3];
    f32 to_pos[3];
    u32 saved_state;
    int hit;
    saved_state = func_8010A698(actor);
    func_8010A624(actor);
    from_pos[0] = *(f32 *) ((char *) prev_pos + 0x0);
    from_pos[1] = *(f32 *) ((char *) prev_pos + 0x4) + 4.0f;
    from_pos[2] = *(f32 *) ((char *) prev_pos + 0x8);
    to_pos[0] = *(f32 *) ((char *) actor + 0x4);
    to_pos[1] = *(f32 *) ((char *) actor + 8) + 4.0f;
    to_pos[2] = *(f32 *) ((char *) actor + 12);
    hit =
        func_800C6A7C(from_pos, to_pos, (u8 *) D_80136F30, *(u32 *) ((char *) actor + 0x14));
    func_800EE7F8(&D_80136F20, to_pos);
    func_8010A654(actor, saved_state);
    return (hit != 0) ? 1 : 0;
}

// Copy the last collision results (D_80136F30, D_80136F20, D_80136F40) to dst.
void func_8010AA54(s32 dst)
{
    func_800EE7F8(dst, (u8 *) D_80136F30);
}

void func_8010AA78(s32 dst)
{
    func_800EE7F8(dst, &D_80136F20);
}

void func_8010AA9C(s32 dst)
{
    func_800EE7F8(dst, (u8 *) D_80136F40);
}

// Sphere sweep from the previous to the current position against level geometry.
s32 func_8010AAC0(Actor *actor, f32 *prev_pos, s32 move_word, s32 result_mask)
{
    CollisionAAC0 query;
    f32 move_delta[3];
    s32 saved_state;
    s32 hit;
    s32 unk_0;
    s32 unk_1;
    f32 move_dir[3];
    s32 unk_2;
    saved_state = func_8010A698();
    func_8010A624(actor);
    query.unk_8 = func_800EC708(((ActorAAC0 *) actor)->marker);
    unk_0 = 0;
    switch (move_word & 0xF000) {
        case 0x1000:
        case 0x3000:
        case 0x5000:
        case 0x6000:
            unk_0 = 1;
            break;
    }
    if (unk_0) {
        query.unk_8 *= 0.6f * func_8010A40C(actor);
        query.unk_4 = query.unk_8 * 1.25f < ((ActorAAC0 *) actor)->marker->unk_20
                              ? ((ActorAAC0 *) actor)->marker->unk_20
                              : query.unk_8 * 1.25f;
    } else {
        query.unk_8 *= 0.5f * func_8010A40C(actor);
        query.unk_4 = query.unk_8 * 1.25f < ((ActorAAC0 *) actor)->marker->unk_20
                              ? ((ActorAAC0 *) actor)->marker->unk_20
                              : query.unk_8 * 1.25f;
    }
    query.unk_0 = 0;
    query.unk_C = 0;
    query.unk_10 = 0;
    query.unk_14 = ((ActorAAC0 *) actor)->flags;
    query.unk_18 = 0;
    query.unk_1C = 0;
    query.unk_50 = 0;
    query.unk_54 = 0;
    query.collided = 0;
    query.unk_56 = 0;
    func_800EFB24(move_delta, ((ActorAAC0 *) actor)->position, prev_pos);
    func_800D4584(&query, prev_pos, ((ActorAAC0 *) actor)->position, move_delta);
    hit = query.collided;
    if (hit) {
        func_800EE7F8(D_80136F30, query.normal);
        if (!query.unk_54) {
            func_800EF410(move_dir, move_delta);
            // Ignore hits whose normal does not face against the movement (cos 20 deg).
            if (func_800EEAA4(query.normal, move_dir) > -0.9396926f)
                hit = 0;
        }
    }
    func_8010A654(actor, saved_state);
    return hit ? 1 : 0;
}

// Like func_8010AAC0, but returns 0 when func_800CC6CC rejects the spline id/node packed at +0x70.
int func_8010ACE0(s32 actor[3], s32 prev_pos, s32 move_word, s32 result_mask)
{
    u32 flags70;
    u32 spline_id;
    u32 shifted;
    u32 spline_node;
    flags70 = actor[28];
    spline_id = flags70 >> 25;
    if (spline_id != 0) {
        shifted = flags70 << 22;
        spline_node = shifted >> 26;
        if (func_800CC6CC(spline_id - 1, spline_node - 1) == 0) {
            return 0;
        }
    }
    return func_8010AAC0(actor, prev_pos, move_word, result_mask);
}

// Sweep with both positions raised by lift; the raise is undone afterwards.
s32 func_8010AD4C(u8 *actor, u8 *prev_pos, s32 move_word, s32 result_mask)
{
    f32 lift;
    s32 hit;
    f32 marker_size;
    marker_size = func_800EC708(*(s32 *) actor);
    lift = func_8010A40C(actor) * (marker_size * 0.666f);
    *(f32 *) (prev_pos + 4) += lift;
    *(f32 *) (actor + 8) += lift;
    hit =
        func_800BF340(prev_pos, actor + 4, (s32 *) D_80136F30, *(s32 *) (actor + 0x14), lift);
    func_800EE7F8((s32 *) D_80136F20, actor + 4);
    *(f32 *) (prev_pos + 4) -= lift;
    *(f32 *) (actor + 8) -= lift;
    return hit ? 1 : 0;
}

// Like func_8010AD4C, but returns 0 when func_800CC6CC rejects the spline id/node packed at +0x70.
int func_8010AE30(s32 actor[3], f32 *prev_pos, f32 *move_word, f32 *result_mask)
{
    u32 flags70;
    u32 spline_id;
    u32 spline_node;
    flags70 = actor[28];
    if ((spline_id = flags70 >> 25) != 0) {
        spline_node = ((u32) flags70 << 22) >> 26;
        if (func_800CC6CC(spline_id - 1, spline_node - 1) == 0) {
            return 0;
        }
    }
    return func_8010AD4C(actor, prev_pos, move_word, result_mask);
}

// Same as func_8010AD4C, with func_800BF0E0 as the test.
s32 func_8010AE9C(u8 *actor, f32 *prev_pos, s32 move_word, s32 result_mask)
{
    f32 lift;
    s32 hit;
    f32 marker_size;
    marker_size = func_800EC708(*(s32 *) actor);
    lift = func_8010A40C(actor) * (marker_size * 0.666f);
    prev_pos[1] += lift;
    *(f32 *) (actor + 8) += lift;
    hit = func_800BF0E0(prev_pos, (f32 *) (actor + 4), lift, D_80136F30, 3,
                            *(s32 *) (actor + 0x14));
    func_800EE7F8((f32 *) D_80136F20, (f32 *) (actor + 4));
    prev_pos[1] -= lift;
    *(f32 *) (actor + 8) -= lift;
    return hit ? 1 : 0;
}

// Like func_8010AE9C, but returns 0 when func_800CC6CC rejects the spline id/node packed at +0x70.
int func_8010AF8C(s32 *actor, s32 prev_pos, s32 move_word, s32 result_mask)
{
    u32 flags70;
    u32 spline_id;
    u32 shifted;
    u32 spline_node;
    flags70 = actor[28];
    spline_id = flags70 >> 25;
    if (spline_id != 0) {
        shifted = flags70 << 22;
        spline_node = shifted >> 26;
        if (func_800CC6CC(spline_id - 1, spline_node - 1) == 0) {
            return 0;
        }
    }
    return func_8010AE9C(actor, prev_pos, move_word, result_mask);
}

// Movement steps: advance the position by the actor speed (func_8010C4AC).
// Some scale the speed by the frame delta time (func_800D8FF8), some negate the angle at +0x44.
s32 func_8010AFF8(u8 *actor, s32 prev_pos, s32 move_word, f32 speed)
{
    speed = func_8010C4AC();
    func_800EF214((f32 *) (actor + 4), *(f32 *) ((char *) actor + 0x44),
                  *(f32 *) ((char *) actor + 0x48), speed);
    return 0;
}

s32 func_8010B040(u8 *actor, s32 prev_pos, s32 move_word, s32 result_mask)
{
    func_800EF1B8((f32 *) (actor + 4), *(f32 *) (actor + 0x48), func_8010C4AC(), actor);
    return 0;
}

s32 func_8010B088(u8 *actor, s32 prev_pos, s32 move_word, s32 result_mask)
{
    f32 speed;
    f32 speed_copy;
    speed = func_8010C4AC();
    // Matching: the extra copy of speed is needed for the match.
    speed_copy = speed;
    func_800EF1B8((f32 *) (actor + 4), *(f32 *) ((s8 *) actor + 0x48), func_800D8FF8() * speed_copy);
    return 0;
}

s32 func_8010B0E0(u8 *actor, s32 prev_pos, s32 move_word, s32 result_mask)
{
    func_800EF214((f32 *) (actor + 4), *(f32 *) (actor + 0x44), *(f32 *) (actor + 0x48),
                  func_8010C4AC() * func_800D8FF8());
    return 0;
}

s32 func_8010B13C(f32 *actor, f32 prev_pos, f32 move_word, f32 result_mask)
{
    f32 speed = func_8010C4AC(actor);
    func_800EF214(actor + 1, -actor[17], actor[18], speed);
    return 0;
}

s32 func_8010B190(void *actor, s32 prev_pos, s32 move_word, s32 result_mask)
{
    f32 delta_time;
    f32 speed;

    speed = func_8010C4AC(actor);
    delta_time = func_800D8FF8();
    func_800EF214((f32 *) ((char *) actor + 4), -((f32 *) actor)[0x11], ((f32 *) actor)[0x12],
                  delta_time * speed);
    return 0;
}

// Fall step: ray from above the actor to its next position (fall speed clamped to -200).
// On a hit it snaps to the floor and stops; otherwise gravity -1200/s applies.
s32 func_8010B1F4(Actor10B1F4 *actor, s32 prev_pos, s32 move_word, s32 result_mask)
{
    f32 ray_start[3];
    f32 ray_end[3];
    f32 probe_height;
    f32 delta_time;
    Hit10B1F4 *hit;
    probe_height = func_8010C460();
    delta_time = func_800D8FF8();
    func_800EE7F8(ray_start, actor->position);
    ray_start[1] += probe_height;
    func_800EE7F8(ray_end, actor->position);
    ray_end[1] += func_800F13F0(actor->vertical * delta_time, -200.0f);
    hit = func_800BEF00(ray_start, ray_end, D_80136F40, actor->flags);
    if (hit) {
        actor->vertical = 0.0f;
        func_800EE7F8(actor->position, ray_end);
        if (actor->collision)
            func_801045AC(actor, D_80136F40, ray_end, hit->unk_8);
        return 1;
    } else {
        actor->vertical -= 1200.0f * delta_time;
        actor->position[1] += actor->vertical;
        if (func_8010C3E8(actor))
            return -1;
    }
    return 0;
}

// Floor snap: ray from above the actor down 100 units.
s32 func_8010B330(LocalActor_8010B330 *actor, s32 prev_pos, f32 *move_word, s32 result_mask)
{
    f32 ray_start[3];
    f32 ray_end[3];
    f32 probe_height;
    s32 *hit;
    probe_height = func_8010C460(actor);
    func_800EE7F8(ray_start, actor->position);
    ray_start[1] += probe_height;
    func_800EE7F8(ray_end, actor->position);
    ray_end[1] -= 100.0f;
    hit = func_800C6A7C(ray_start, ray_end, D_80136F40, actor->flags);
    if (hit) {
        actor->vertical = 0.0f;
        func_800EE7F8(actor->position, ray_end);
        if (actor->collision)
            func_801045AC(actor, D_80136F40, ray_end, hit[2]);
        return 1;
    }
    return 0;
}

// Floor ray down 200 units; lifts the actor just above the floor if it sank below.
s32 func_8010B410(LocalActor_8010B410 *actor, s32 prev_pos, f32 *move_word, s32 result_mask)
{
    f32 ray_start[3];
    f32 ray_end[3];
    f32 probe_height;
    s32 *hit;
    probe_height = func_8010C460(actor);
    func_800EE7F8(ray_start, actor->position);
    ray_start[1] += probe_height;
    func_800EE7F8(ray_end, actor->position);
    ray_end[1] -= 200.0f;
    hit = (s32 *) func_800BEF00(ray_start, ray_end, D_80136F40, actor->flags);
    if (hit) {
        if (actor->collision)
            func_801045AC(actor, D_80136F40, ray_end, hit[2]);
        if (actor->position[1] < ray_end[1]) {
            actor->position[1] = ray_end[1] + 1.0f;
            return 1;
        }
    }
    if (func_8010C3E8(actor))
        return -1;
    return 0;
}

// Like func_8010B1F4, with gravity -300/s and a bounce speed of -50 when the actor sank below the floor.
s32 func_8010B514(State10B514 *actor, s32 prev_pos, s32 move_word, s32 result_mask)
{
    f32 ray_start[3];
    f32 ray_end[3];
    f32 probe_height;
    f32 delta_time;
    s32 hit;
    probe_height = func_8010C460(actor);
    delta_time = func_800D8FF8();
    func_800EE7F8(ray_start, actor->position);
    ray_start[1] += probe_height;
    func_800EE7F8(ray_end, actor->position);
    ray_end[1] += func_800F13F0(actor->vertical * delta_time, -200.0f);
    actor->vertical -= 300.0f * delta_time;
    hit = func_800BEF00(ray_start, ray_end, D_80136F40, actor->flags);
    if (hit) {
        actor->position[1] += actor->vertical;
        if (func_8010C3E8(actor))
            return -1;
        actor->vertical = 0.0f;
        if (actor->position[1] < ray_end[1]) {
            actor->vertical = -50.0f;
            actor->position[1] = ray_end[1];
        }
        if (actor->collision)
            func_801045AC(actor, D_80136F40, ray_end, *(s32 *) (hit + 8));
        return 1;
    } else {
        actor->position[1] += actor->vertical;
        if (func_8010C3E8(actor))
            return -1;
        return 0;
    }
}

// Ceiling clamp: keeps the actor's height 130 units below the ceiling; returns 1 if it was clamped.
s32 func_8010B69C(s32 actor, s32 prev_pos, s32 move_word, s32 result_mask)
{
    f32 height_limit = func_800BED50((void *) ((s32) actor + 4), actor) - 130.0f;
    f32 height = *(f32 *) ((char *) actor + 8);
    if (height < height_limit) {
        *(f32 *) ((char *) actor + 8) = height;
    } else {
        *(f32 *) ((char *) actor + 8) = height_limit;
    }
    return (height_limit == *(f32 *) ((char *) actor + 8));
}

// Velocity integration: height += vertical velocity (+0x2C) * dt, with gravity (+0x34).
// A floor hit zeroes both.
int func_8010B71C(u8 *actor, s32 prev_pos, s32 move_word, s32 result_mask)
{
    f32 ray_start[3];
    f32 probe_height;
    f32 delta_time;
    u8 *hit;
    probe_height = func_8010C460(actor);
    delta_time = func_800D8FF8();
    ray_start[0] = *(f32 *) (actor + 4);
    ray_start[1] = *(f32 *) (actor + 8) + probe_height;
    ray_start[2] = *(f32 *) (actor + 12);
    *(f32 *) (actor + 8) += *(f32 *) (actor + 0x2C) * delta_time;
    hit = func_800BEF00(ray_start, (f32 *) (actor + 4), D_80136F40, *(s32 *) (actor + 0x14));
    if (hit) {
        *(f32 *) (actor + 0x2C) = 0.0f;
        *(f32 *) (actor + 0x34) = 0.0f;
        if (*(s16 *) (actor + 0x8E))
            func_801045AC(actor, D_80136F40, (f32 *) (actor + 4), *(s32 *) (hit + 8));
        return 1;
    }
    *(f32 *) (actor + 0x2C) -= *(f32 *) (actor + 0x34) * delta_time;
    return 0;
}

// Spline following: advances the node; at the end of the spline moves the actor to prev_pos.
int func_8010B800(local_type *actor, f32 *prev_pos, s32 move_word, s32 result_mask)
{
    s32 next_node;
    if (actor->spline_id) {
        next_node = func_800CC338(actor->position, actor->spline_id - 1, actor->spline_node - 1);
        if (next_node == -1) {
            func_800EE7F8(actor->position, prev_pos);
            return 1;
        }
        actor->spline_node = next_node + 1;
        return 0;
    }
    return 0;
}

// Integrates velocity: vertical acceleration first, then position += velocity * dt.
s32 func_8010B8A4(S_10B8A4 *actor, s32 prev_pos, s32 move_word, s32 result_mask)
{
    f32 delta_time;
    f32 step[3];
    delta_time = func_800D8FF8();
    actor->velocity[1] = actor->velocity[1] + (actor->accel_y * delta_time);
    func_800EFA20(step, actor->velocity, delta_time);
    func_800EF04C(actor->position, step);
    return 0;
}

// Adds the velocity at +0x28 to the position, without delta time.
// Matching: the redundant temporaries and constant masking are needed for the match.
int func_8010B910(s32 actor, s32 prev_pos, s32 move_word, s32 result_mask)
{
    int offset;
    int scratch;
    u8 *pos;
    u8 *pos_copy;
    offset = 4;
    scratch = 0x28;
    pos = offset + actor;
    pos_copy = pos;
    offset = scratch;
    scratch = 0 & 0xFFFFFFFFFFFFFFFFu;
    func_800EF04C(pos_copy, (actor + offset) + scratch);
    return (((scratch & 0xFFFFFFFFFFFFFFFFu) & 0xFFFFFFFFFFFFFFFFu) & (0xFFFFFFFFFFFFFFFFu ^ 0)) &
           0xFFFFFFFFFFFFFFFFu;
}

s32 func_8010B94C(s32 actor, s32 prev_pos, s32 move_word, s32 result_mask)
{
    func_800EF174(actor + 4, actor + 0x28, func_800D8FF8());
    return 0;
}

// Movement step runner: each of the six nibbles of move_word selects a callback from
// D_80124714[i]. A step returning -1 aborts (result 0); other nonzero results are
// OR'ed into the returned mask, shifted by the step index.
s32 func_8010B990(Actor *actor, s32 move_word)
{
    s32 i;
    s32 result_mask;
    s32 selector;
    f32 start_pos[3];
    s32 result;
    result_mask = 0;
    func_80104580();
    func_800EE7F8(start_pos, actor->position);
    for (i = 0; i < 6; i++) {
        selector = ((u32) move_word >> (i << 2)) & 0xF;
        if (selector) {
            result = D_80124714[i][selector](actor, start_pos, move_word, result_mask);
            if (result == -1)
                return 0;
            if (result)
                result_mask |= result << i;
        }
    }
    return result_mask;
}

// Runs the steps; restores the position if any bit of mask is set in the result.
s32 func_8010BA80(s32 actor, s32 move_word, s32 mask)
{
    s32 result;
    s32 ret;
    s32 result_copy;
    s32 saved_pos;

    func_800EE7F8(&saved_pos, actor + 4);
    result = func_8010B990(actor, move_word);
    ret = result;
    if (result & mask) {
        // Matching: the extra copy of the result is needed for the match.
        result_copy = result;
        func_800EE7F8(actor + 4, &saved_pos);
        ret = result_copy;
    }
    return ret;
}

// Runs the steps; restores the position unless all bits of mask are set in the result.
s32 func_8010BAEC(s32 actor, s32 move_word, s32 mask)
{
    s32 ret;
    s32 masked;
    s32 unk_0;
    s32 saved_pos;
    func_800EE7F8(&saved_pos, actor + 4);
    ret = func_8010B990(actor, move_word);
    // Matching: the do/while (0) blocks are needed for the match.
    do {
        masked = ret & mask;
        do {
        } while (0);
        if (masked != mask) {
            func_800EE7F8(actor + 4, &saved_pos);
        }
        return ret;
    } while (0);
}

// Cylinder push-out: moves pos horizontally out of the cylinder at base (height, margin, radius).
// Returns 1 if pos was inside.
s32 func_8010BB5C(s32 actor, f32 *pos, f32 *base, f32 height, f32 margin, f32 radius)
{
    f32 offset[3];
    f32 dist;
    f32 unk_0;
    f32 push;
    if (pos[1] < base[1] + margin)
        return 0;
    if (base[1] + height < pos[1])
        return 0;
    func_800EFA4C(offset, pos[0] - base[0], 0.0f, pos[2] - base[2]);
    dist = offset[0] * offset[0] + offset[1] * offset[1] + offset[2] * offset[2];
    if (radius * radius < dist)
        return 0;
    dist = sqrtf(dist);
    push = func_800F13F0(func_800D8FF8() * 400.0f, radius - dist);
    if (dist == 0.0f) {
        dist = func_800DC0C0();
        func_800EFA4C(offset, dist, 0.0f, func_800DC0C0());
    }
    func_800EF368(offset, push);
    func_800EF04C(pos, offset);
    return 1;
}

// Pushes pos out of the other actor's bounding cylinder (bottom/top, radius, scale).
s32 func_8010BCC8(LocalBoundsActor *actor, f32 *pos, LocalBoundsActor *other)
{
    f32 base[3];
    f32 height;
    f32 radius;
    if (!other->radius)
        return 0;
    func_800EE7F8(base, other->position);
    base[1] += other->scale * actor->bottom;
    height = (actor->top - actor->bottom) * other->scale;
    radius = func_8010A40C(actor);
    radius *= other->radius * other->scale;
    return func_8010BB5C(actor, pos, base, height, -30.0f, radius);
}

// Actor separation: pushes the actor out of the first overlapping actor found in the nearby
// marker cubes. If exactly one of the two is burning, burn spread is triggered
// (_chflamer_entrypoint_1). Returns 1 on a push.
s32 func_8010BDB0(LocalActor_8010BDB0 *actor, s32 prev_pos, s32 move_word, s32 result_mask)
{
    void **cube;
    LocalEntry *entry;
    LocalEntry *entry_end;
    LocalMarker *other_marker;
    LocalActor_8010BDB0 *other;
    f32 *pos;
    pos = actor->position;
    for (cube = func_800BE3F8(pos); *cube; cube++) {
        entry = func_800E9E88(*cube);
        entry_end = func_800E9EB4(*cube);
        for (; entry < entry_end; entry++) {
            if (!(entry->flags & 1))
                continue;
            other_marker = entry->marker;
            if (!(other_marker->flags & 1) || other_marker == actor->marker)
                continue;
            other = func_80106790(other_marker);
            if (!(other->flags70 & 1) || !func_8010BCC8(actor, pos, other))
                continue;
            if ((other->flags74 & 1) && !(actor->flags74 & 1) &&
                func_80102F74(actor, 0x80020000)) {
                _chflamer_entrypoint_1(actor, other_marker);
            }
            if (!(other->flags74 & 1) && (actor->flags74 & 1) &&
                func_80102F74(other, 0x80020000)) {
                _chflamer_entrypoint_1(other, actor->marker);
            }
            return 1;
        }
    }
    return 0;
}

// Sets the actor speed, then runs the movement steps.
void func_8010BF4C(f32 *actor, s32 unk_0, f32 speed, s32 unk_1, s32 move_word)
{
    *(f32 *) ((char *) actor + 0x24) = speed;
    func_80102844(actor, (f32) unk_1, -1, unk_0);
    func_8010B990(actor, move_word);
}

// Obstacle avoidance: places pos beside the obstacle (radius), sliding along it
// instead of through it. Returns 1 if it steered.
s32 func_8010BFA4(f32 *pos, f32 *prev_pos, f32 *obstacle, f32 radius)
{
    f32 yaw;
    f32 turn;
    f32 side_diff;
    f32 heading;
    f32 move_delta[3];
    f32 saved_y;
    f32 heading_diff;
    f32 move_len;
    func_800EFB24(move_delta, pos, prev_pos);
    if (!func_800F1EA4(move_delta, &heading)) {
        func_800EE7F8(pos, prev_pos);
        return 0;
    }
    saved_y = prev_pos[1];
    yaw = func_800F1DF4(prev_pos, obstacle);
    side_diff = func_800F1DCC(heading, yaw);
    func_800EE7F8(pos, obstacle);
    func_800EF1B8(pos, yaw + 180.0f, radius + 2.0f);
    turn = side_diff > 0.0f ? 90.0f : -90.0f;
    yaw = func_800136E4(yaw + turn);
    move_len = func_800EEF94(move_delta);
    heading_diff = func_800F1DCC(heading, yaw);
    turn = func_800138D0(heading_diff);
    func_800EF1B8(pos, yaw, turn * move_len);
    pos[1] = saved_y;
    return 1;
}

// Sphere version of func_8010BDB0 (separation done by func_8010C2D8).
s32 func_8010C100(Actor10C100 *actor, s32 prev_pos, s32 move_word, s32 result_mask)
{
    f32 center[3];
    f32 radius;
    Entry10C100 *entry, *entry_end;
    Marker10C100 *other_marker;
    Actor10C100 *other;
    void **cube;
    f32 base_radius;
    base_radius = func_80103F38(actor, center);
    radius = func_8010A40C(actor) * (0.7f * base_radius);
    for (cube = func_800BE3F8(actor->position); *cube; cube++) {
        entry = func_800E9E88(*cube);
        entry_end = func_800E9EB4(*cube);
        for (; entry < entry_end; entry++) {
            if (!(entry->flags & 1))
                continue;
            other_marker = entry->marker;
            if (!(other_marker->flags & 1) || other_marker == actor->marker)
                continue;
            other = func_80106790(other_marker);
            if ((other->flags70 & 1) && func_8010C2D8(actor, center, radius, other)) {
                if ((other->flags74 & 1) && !(actor->flags74 & 1)) {
                    if (func_80102F74(actor, 0x80020000))
                        _chflamer_entrypoint_1(actor, other_marker);
                }
                if (!(other->flags74 & 1) && (actor->flags74 & 1)) {
                    if (func_80102F74(other, 0x80020000))
                        _chflamer_entrypoint_1(other, actor->marker);
                }
                return 1;
            }
        }
    }
    return 0;
}

// Sphere push-out: moves the actor out of other if the spheres overlap. Returns 1 if pushed.
s32 func_8010C2D8(s32 actor, s32 center, f32 radius, Actor10C100 *other)
{
    f32 other_center[3];
    f32 offset[3];
    f32 other_radius;
    f32 dist_sq;

    other_radius = func_80103F38(other, other_center) * func_8010A40C(other);
    func_800EFB24(offset, (f32 *) center, other_center);
    dist_sq = func_800EEFD4((s32 *) offset);
    if (dist_sq < ((other_radius + radius) * (other_radius + radius))) {
        func_800EF368(offset, ((other_radius + radius) + 4.0f) - sqrtf(dist_sq));
        func_800EF04C((f32 *) (actor + 4), offset);
        return 1;
    }
    return 0;
}

// Runs the movement steps with the actor speed (+0x24) temporarily scaled.
int func_8010C3A8(f32 actor[3], f32 move_word[3], f32 speed_scale)
{
    f32 unk_0;
    f32 saved_speed;
    saved_speed = actor[9];
    actor[9] *= speed_scale;
    func_8010B990(actor, move_word);
    actor[9] = saved_speed;
}

// Despawns the actor when it falls 1000 units below the floor (func_800BECCC), unless event
// 0x4D is handled. Returns 1 if despawned.
s32 func_8010C3E8(actor)
u8 *actor;
{
    f32 floor_y = func_800BECCC();
    f32 limit = floor_y - 1000.0f;

if (*(f32 *) (actor + 8) < limit) {
    *(f32 *) (actor + 8) = limit;
    if (func_8010108C(actor, 0x4D, 1) > 0) {
        return 0;
    }
    func_800FFAB0(actor);
    return 1;
}

return 0;
}

// Probe height for ground rays: the larger of 60 and 0.666 * func_80103F38.
f32 func_8010C460(actor)
s32 actor;
{
    f32 scaled;
    f32 height;
    scaled = func_80103F38(actor, 0) * 0.666f;
    height = scaled;
    // Matching: reusing the first temporary for the constant is needed for the match.
    scaled = 60.0f;
    if (height < scaled)
        return scaled;
    return height;

}

// Actor speed (+0x24), times 1.5 while func_800D3E40(8) is nonzero.
f32 func_8010C4AC(actor)
u8 *actor;
{
    if (func_800D3E40(8) != 0) {
        return *(f32 *) ((s8 *) actor + 0x24) * 1.5f;
    }

return (*(f32 *) ((s8 *) (actor) + (0x24)));
}

// TU-NOTE: the .data of this file (formerly asm/data/core2/1EE4270.data.s) is defined here in C.
// Its tables hold pointers to functions of this file; IDO's assembler schedules some of these
// functions differently unless the tables are defined in the same unit. Values come from the ROM.
// D_80124714 is the step table used by func_8010B990: six groups, indexed by a 4-bit selector.
extern void _subaddierouteDll_entrypoint_8();
extern void _subaddierouteDll_entrypoint_9();
u32 D_80124690[10] = {0x0,
                      (u32) func_8010B040,
                      (u32) func_8010AFF8,
                      (u32) func_8010B910,
                      (u32) func_8010B8A4,
                      (u32) func_8010B088,
                      (u32) func_8010B0E0,
                      (u32) func_8010B94C,
                      (u32) func_8010B13C,
                      (u32) func_8010B190};
u32 D_801246B8[5] = {0x0, (u32) func_8010B800, 0x0, (u32) _subaddierouteDll_entrypoint_8,
                     (u32) _subaddierouteDll_entrypoint_9};
u32 D_801246CC[3] = {0x0, (u32) func_8010BDB0, (u32) func_8010C100};
u32 D_801246D8[7] = {0x0,
                     (u32) func_8010B1F4,
                     (u32) func_8010B69C,
                     (u32) func_8010B71C,
                     (u32) func_8010B410,
                     (u32) func_8010B514,
                     (u32) func_8010B330};
u32 D_801246F4[8] = {0x0,
                     (u32) func_8010A980,
                     (u32) func_8010AAC0,
                     (u32) func_8010ACE0,
                     (u32) func_8010AD4C,
                     (u32) func_8010AE30,
                     (u32) func_8010AE9C,
                     (u32) func_8010AF8C};
LocalCallback *D_80124714[6] = {
    (void *) &D_80124690, (void *) &D_801246CC, (void *) &D_801246B8, (void *) &D_801246D8, 0,
    (void *) &D_801246F4};
