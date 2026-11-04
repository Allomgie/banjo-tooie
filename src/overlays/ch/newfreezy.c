#include "common.h"

typedef struct {
    u8 pad_0[0xE];
    s16 parent;
} NFSlot;
extern void *func_800AE080(s32);
extern void mlMtxRotatePYR(f32, f32, f32);
extern Vec3f D_80801950_chnewfreezy;
extern void func_800EF334(f32 *, f32);
extern void func_800EF5A0(f32 *, f32 *, f32, f32, f32);
extern void func_800EE7F8(f32 *, f32 *);
extern f32 func_800EEAD4(f32 *, f32 *);
typedef struct {
    f32 pos[3];
    f32 rotation[3];
    u8 pad_0[0x30];
    f32 full_scale;
    u8 pad_1[0xC];
    f32 grow_end;
    s8 state;
    s8 model;
    s8 parent;
    u8 pad_2;
} FreezyPart241;
typedef struct {
    s32 bone;
    f32 scale_mul;
    s8 model;
    s8 parent;
    u8 pad_0[2];
} FreezyConfig241;
extern void func_800F18FC(f32 *, f32 *, f32 *);
extern void func_800EF214(f32 *, f32, f32, f32);
typedef struct {
    f32 pos[3];
    u8 pad_0[0x3C];
    f32 full_scale;
    u8 pad_1[0x10];
    s8 state;
    u8 pad_2[3];
} FreezyFragment;
extern Actor *func_80106790(Unk80132ED0 *);
extern Actor *func_801084B0(s32, Actor **);
extern void func_80103DFC(Actor *, f32 *);
extern f32 func_800EC708(Unk80132ED0 *);
extern s32 func_800E3E8C(f32 *, f32);
typedef struct {
    f32 unk_0[15];
    u8 unk_3C[16];
    s32 scale;
    u8 unk_50[12];
    s8 state, model;
    u8 pad_5E[2];
} FreezyDrawPart;
typedef union {
    s32 word;
    void *pointer;
} FreezyMessage;
extern int D_80801978_chnewfreezy[];
typedef struct {
    u8 pad_0[0x18];
    f32 vel[3];
    u8 pad_24[0xC];
    f32 angular_vel[3];
    u8 pad_3C[0x10];
    f32 scale;
    u8 pad_50[0xC];
    s8 state;
    u8 pad_5D[3];
} FreezyPart_808000D4_chnewfreezy;
extern f32 func_800F1DF4(void *, f32 *);
extern void func_8010D254(f32 *);
extern f32 func_800DC178(f32, f32);
extern void func_800EEC30(f32 *, f32, f32, f32);
extern void _sufreezy_entrypoint_4(Unk80132ED0 *, s32);
typedef struct {
    f32 pos[3];
    f32 rotation[3];
    f32 vel[3];
    f32 origin[3];
    f32 angular_vel[3];
    f32 draw_pos[3];
    f32 full_scale;
    f32 scale;
    f32 progress;
    f32 grow_start;
    f32 grow_end;
    s8 state;
    u8 pad_5D[3];
} FreezyPart_808002C0_chnewfreezy;
typedef struct {
    u8 pad_0[0x78];
    u32 pad_1 : 29;
    u32 active : 1;
    u32 pad_2 : 2;
} FreezyLink;
extern FreezyPart_808002C0_chnewfreezy *func_80100094(Actor *, s32);
extern f32 func_800D8FF8(void);
extern void _subaddiefade_entrypoint_3(Actor *);
extern FreezyLink *_subaddielink_entrypoint_4(void *);
extern void _sudeflect_entrypoint_0(f32 *, f32, f32, s32);
extern s32 func_800D9078(f32 *);
extern s32 func_800DC128(s32, s32);
extern void func_800E3980(f32 *);
extern void func_800EEBF0(f32 *, f32 *, f32);
extern void func_800EF04C(f32 *, f32 *);
extern void _fxtwinkle_entrypoint_1(f32 *, s32);
extern f32 func_800F10B4(f32, f32, f32, f32, f32);
extern void func_800EFB24(f32 *, f32 *, f32 *);
extern void func_800EE780(f32 *, f32 *, f32 *);
extern void func_800EFA20(f32 *, f32 *, f32);
extern s32 func_800BEF00(f32 *, f32 *, f32 *, s32);
extern f32 func_800EEF94(f32 *);
extern void func_800EFDE8(f32 *, f32 *, f32 *);
extern void func_800EF368(f32 *, f32);
extern u8 D_8080195C_chnewfreezy[];
extern u8 D_8080196C_chnewfreezy[];
typedef struct {
    f32 q[4];
} FreezyQuaternion35;
extern void func_80105834(), func_80107C2C(), func_80108ED0(), func_80800000_chnewfreezy(),
    func_80800020_chnewfreezy(), func_808016B4_chnewfreezy();

void func_80800000_chnewfreezy()
{
    _sufreezy_entrypoint_1();
}

void func_80800020_chnewfreezy(actor) u8 **actor;
{
    s16 slot;
    if (*(s16 *) ((s8 *) *actor + 0x10) != 0) {
        slot = *(s16 *) ((s8 *) *actor + 0x10);
        func_800ADFE0(slot, *(s16 *) ((s8 *) *actor + 0x10), actor);
        *(s16 *) ((s8 *) *actor + 0x10) = 0;
    }
}

// Restores the frozen actor's saved state.
void func_80800068_chnewfreezy(u8 *actor)
{
    func_8010A828(_subaddielink_entrypoint_4(func_80100094(actor, 1)),
                  (u32) (u8) *(u8 *) ((s8 *) actor + 0x79) >> 4);
}

void func_808000AC_chnewfreezy(s32 actor)
{
    _sufreezy_entrypoint_2();
    func_8010A570(actor);
}

// Shatters the ice: every chunk flies off with random velocity and spin.
void func_808000D4_chnewfreezy(actor) Actor *actor;
{
    f32 unk_0[5];
    FreezyPart_808000D4_chnewfreezy *chunk;
    u32 i;
    f32 unk_1;
    f32 unk_2;
    f32 unk_3;
    f32 unk_4;
    f32 unk_5;

    chunk = func_80100094(actor, 0);
    if (actor->unk64_20) {
        return;
    }
    actor->unk64_20 = 1;
    actor->unk54 = 0.0f;
    func_8010D254(unk_0);
    unk_4 = 20.0f;
    unk_5 = 65.0f;
    for (i = 0; i < actor->unk6C_0; i++) {
        if (chunk->state == 3) {
            chunk++;
        } else {
            unk_1 = func_800F1DF4(chunk, unk_0);
            unk_2 = func_800DC178(-unk_4, unk_4);
            unk_3 = func_800DC178(-unk_5, unk_5);
            func_800EEC30(chunk->vel, unk_2 + 130.0f, unk_3 + unk_1,
                          func_800DC178(800.0f, 1000.0f));
            chunk->angular_vel[0] = func_800DC178(-25.0f, 25.0f);
            chunk->angular_vel[1] = func_800DC178(-25.0f, 25.0f);
            chunk->angular_vel[2] = func_800DC178(-25.0f, 25.0f);
            chunk->state = 4;
            chunk->scale *= 0.6f;
            chunk++;
        }
    }
    _sufreezy_entrypoint_4(actor->unk0, 8);
}

// Per frame: grows the ice chunks, sparkles, moves shattered chunks, and fades out when none are left.
void func_808002C0_chnewfreezy(Actor *actor)
{
    // Matching: unused locals, needed for the match.
    s32 fill0;
    s32 fill1;
    u32 sparkle_index;
    s32 remaining;
    u32 i;
    f32 sparkle_pos[3];
    f32 unk_0[3];
    f32 unk_1[2];
    FreezyPart_808002C0_chnewfreezy *chunk;
    f32 offset[3];
    f32 step[3];
    f32 old_pos[3];
    f32 new_pos[3];
    f32 normal[3];
    s32 j;
    f32 speed;
    f32 unk_2;
    f32 unk_3;
    FreezyLink *link;

    chunk = func_80100094(actor, 0);
    remaining = actor->unk6C_0;
    if (actor->unk64_20) {
        if (actor->unk54 < 5.0f) {
            actor->unk54 += func_800D8FF8();
        } else {
            _subaddiefade_entrypoint_3(actor);
        }
    }
    link = _subaddielink_entrypoint_4(func_80100094(actor, 1));
    if (link) {
        if (!link->active) {
            func_80800068_chnewfreezy(actor);
            func_808000AC_chnewfreezy(actor);
        } else {
            _sudeflect_entrypoint_0(actor->position, 0.0f, actor->unk74_7 * 0.75f, 2);
            if (func_800D9078(&actor->unk58)) {
                func_80800068_chnewfreezy(actor);
                func_808000D4_chnewfreezy(actor);
                func_808000AC_chnewfreezy(actor);
            }
        }
    }
    sparkle_index = func_800DC128(0, actor->unk6C_0 * 5);
    for (i = 0; i < actor->unk6C_0; i++, chunk++) {
        // Matching: needed for the match.
        if (1) {
        }
        switch (chunk->state) {
            case 2:
                if (i == sparkle_index) {
                    func_800E3980(unk_0);
                    func_800F18FC(chunk->pos, unk_0, unk_1);
                    for (j = 0; j < 2; j++) {
                        unk_1[1] += func_800DC178(0.0f, 160.0f) - 80.0f;
                    }
                    func_800EEBF0(sparkle_pos, unk_1, chunk->scale * 25.0f);
                    func_800EF04C(sparkle_pos, chunk->pos);
                    _fxtwinkle_entrypoint_1(sparkle_pos, 0x9E5);
                }
                break;
            case 1:
                chunk->progress = func_800F10B4(*(f32 *) &actor->actorData[3], chunk->grow_start,
                                               chunk->grow_end, 0, 1.0f);
                if (1.0f <= chunk->progress) {
                    chunk->state = 2;
                }
                chunk->scale = chunk->full_scale * chunk->progress;
                func_800EFB24(offset, chunk->pos, chunk->origin);
                func_800EF334(offset, chunk->progress);
                func_800EE780(chunk->draw_pos, chunk->origin, offset);
                break;
            case 4:
                func_800EFA20(step, chunk->vel, func_800D8FF8());
                func_800EE7F8(old_pos, chunk->draw_pos);
                func_800EE780(new_pos, old_pos, step);
                func_800EF04C(new_pos, step);
                if (func_800BEF00(old_pos, new_pos, normal, 0x20020)) {
                    speed = func_800EEF94(chunk->vel);
                    unk_2 = func_800EEF94(step) * 2;
                    unk_3 = func_800EEAD4(old_pos, new_pos);
                    if (unk_3 < unk_2) {
                        func_800EF334(step, unk_3 / unk_2 * 0.9f);
                    }
                    func_800EFDE8(chunk->vel, chunk->vel, normal);
                    func_800EF368(chunk->vel, speed * 0.35f);
                    func_800EF334(chunk->angular_vel, 0.35f);
                    if (speed < 250.0f) {
                        chunk->state = 5;
                    }
                } else {
                    chunk->vel[0] *= 0.95f;
                    chunk->vel[2] *= 0.95f;
                    chunk->vel[1] -= 50.0f;
                    func_800EF04C(chunk->rotation, chunk->angular_vel);
                    func_800EF334(chunk->angular_vel, 0.99f);
                }
                func_800EF04C(chunk->draw_pos, step);
                break;
            case 3:
                remaining--;
                break;
            case 5:
                remaining--;
        }
    }
    if (remaining == 0) {
        _subaddiefade_entrypoint_3(actor);
    } else {
        *(f32 *) &actor->actorData[3] +=
            (func_800D8FF8() * 450.0f) * *(f32 *) &actor->actorData[7];
    }
    actor->unk50 += func_800D8FF8();
}

// Spreads the growth wave from the seed chunk along the skeleton.
void func_80800824_chnewfreezy(s32 actor, s32 skeleton, s32 count, s32 seed)
{
    u8 *chunks;
    NFSlot *bones;
    NFSlot *seed_bone;
    NFSlot *bone;
    u8 *chunk;
    u8 *seed_chunk;
    s32 i;

    chunks = func_80100094(actor, 0);
    i = 0;
    if (count > 0) {
        bones = (NFSlot *) ((skeleton + 8) ^ 0); // Matching: ^ 0 needed for the match.
        seed_bone = &bones[seed];
        do {
            bone = &bones[i];
            // Matching: empty test steers IDO's register priority.
            if (i == 0x60) {
            }
            if (seed_bone != bone) {
                chunk = chunks + i * 0x60;
                if (*(f32 *) (chunk + 0x58) == -1.0f && (seed == bone->parent || i == seed_bone->parent)) {
                    seed_chunk = chunks + seed * 0x60;
                    *(f32 *) (chunk + 0x54) = *(f32 *) (seed_chunk + 0x58);
                    *(f32 *) (chunk + 0x58) = *(f32 *) (seed_chunk + 0x58) + func_800EEAD4(chunk, seed_chunk);
                    func_800EE7F8(chunk + 0x24, seed_chunk);
                    func_80800824_chnewfreezy(actor, skeleton, count, i);
                }
            }
            i++;
        } while (i != count);
        // Matching: empty tests lower the priority of seed_bone.
        if (seed_bone) {
        }
        if (seed_bone) {
        }
        if (seed_bone) {
        }
    }
}

// Reads each chunk's rotation from the bone matrices.
void func_80800974_chnewfreezy(Actor *actor, s32 skeleton)
{
    f32 unk_0;
    void *anim_data;
    u32 i;
    u8 *chunk;
    f32 matrix[4][4];

    chunk = func_80100094(actor, 0);
    func_800AE290(*(s16 *) ((u8 *) actor->unk0 + 0x10), skeleton, func_800DF324());
    anim_data = func_800AE080(*(s16 *) ((u8 *) actor->unk0 + 0x10));
    for (i = 0; i < actor->unk6C_0; i++) {
        mlMtxSet(func_800ADE50(anim_data, skeleton, _dbskeleton_entrypoint_4(skeleton, i)));
        mlMtxRotatePYR(actor->rotation[0], actor->rotation[1], actor->rotation[2]);
        mlMtxGet(matrix);
        func_800F2C1C(matrix, chunk + 0xC);
        *(f32 *) (chunk + 0x10) = *(f32 *) (chunk + 0x10) - 90.0f;
        *(f32 *) (chunk + 0x14) = -*(f32 *) (chunk + 0xC);
        *(f32 *) (chunk + 0xC) = 0.0f;
        chunk += 0x60;
    }
}

// Sets each chunk's size from the bone matrix.
void func_80800AA4_chnewfreezy(Actor *actor, s32 skeleton)
{
    void *anim_data;
    u32 i;
    u8 *chunk = (u8 *) func_80100094(actor, 0);
    s32 bone;
    f32 matrix[4][4];
    Vec3f unit;
    f32 extent[3];

    func_800AE40C(*(s16 *) ((u8 *) actor->unk0 + 0x10), skeleton, func_800DF324());
    anim_data = func_800AE080(*(s16 *) ((u8 *) actor->unk0 + 0x10));
    for (i = 0; i < actor->unk6C_0; i++, chunk += 0x60) {
        bone = _dbskeleton_entrypoint_4(skeleton, i);
        unit = D_80801950_chnewfreezy;
        mlMtxSet(func_800ADE50(anim_data, skeleton, bone));
        mlMtxGet(matrix);
        func_800F23D0(matrix, extent, &unit);
        *(f32 *) (chunk + 0x48) =
            sqrtf(extent[0] * extent[0] + extent[1] * extent[1] + extent[2] * extent[2]);
    }
}

// Sets each chunk's position from the bone pose.
void func_80800BFC_chnewfreezy(Actor *actor, s32 skeleton)
{
    void *anim_data;
    u32 i;
    u8 *chunk;

    chunk = func_80100094(actor, 0);
    func_800AE1E8(*(s16 *) ((u8 *) actor->unk0 + 0x10), skeleton, func_800DF324());
    anim_data = func_800AE080(*(s16 *) ((u8 *) actor->unk0 + 0x10));
    for (i = 0; i < actor->unk6C_0; i++) {
        func_800AE630(anim_data, skeleton, _dbskeleton_entrypoint_4(skeleton, i), chunk);
        func_800EF334((f32 *) chunk, *(f32 *) &actor->actorData[7]);
        func_800EF5A0((f32 *) chunk, actor->rotation, ((f32 *) chunk)[0],
                      ((f32 *) chunk)[1], ((f32 *) chunk)[2]);
        func_800EF04C(chunk, actor->position);
        *(f32 *) (chunk + 0x4C) = 0.0f;
        func_800EE7F8((f32 *) (chunk + 0x24), (f32 *) chunk);
        chunk += 0x60;
    }
}

// Picks the chunk nearest the point in actorData[0..2] as the growth seed.
void func_80800D28_chnewfreezy(Actor *actor, void *skeleton)
{
    u8 *chunk;
    f32 max_dist;
    f32 min_dist;
    f32 dist;
    u32 i;
    s32 seed;
    chunk = func_80100094(actor, 0);
    max_dist = 0.0f;
    min_dist = 0.0f;
    seed = -1;
    for (i = 0; i < (*(u32 *) ((u8 *) actor + 0x6C) & 0x1FF);
         i++, chunk += 0x60) {
        dist = func_800EEAD4((f32 *) actor->actorData, (f32 *) chunk);
        if (!i || max_dist < dist)
            max_dist = dist;
        if (!i || dist < min_dist) {
            min_dist = dist;
            seed = i;
        }
        *(f32 *) (chunk + 0x58) = -1.0f;
    }
    if (seed != -1) {
        chunk = (u8 *) func_80100094(actor, 0) + seed * 0x60;
        *(f32 *) (chunk + 0x58) = 100.0f;
        *(f32 *) (chunk + 0x54) = 0.0f;
        func_80800824_chnewfreezy(actor, skeleton, *(u32 *) ((u8 *) actor + 0x6C) & 0x1FF,
                                  seed);
    }
}

// Applies the per-kind config table: model, scale and parent of each chunk.
void func_80800E74_chnewfreezy(Actor *actor, void *skeleton, FreezyConfig241 *configs, s32 config_count)
{
    FreezyPart241 *chunk;
    s32 bone;
    u32 i;
    s32 j;
    FreezyConfig241 *config;
    u32 k;

    chunk = func_80100094(actor, 0);
    for (i = 0; i < actor->unk6C_0; i++, chunk++) {
        bone = _dbskeleton_entrypoint_4(skeleton, i);
        chunk->state = 3;
        if (chunk->grow_end == -1.0f) {
            chunk->grow_end = 100.0f;
        }
        for (j = 0; j < config_count; j++) {
            config = &configs[j];
            if (bone == config->bone) {
                chunk->full_scale *= config->scale_mul;
                chunk->state = 1;
                chunk->model = config->model;
                chunk->parent = config->parent;
                if (chunk->parent >= 0) {
                    for (k = 0; k < actor->unk6C_0; k++) {
                        if (_dbskeleton_entrypoint_4(skeleton, k) == chunk->parent) {
                            func_800F18FC(
                                chunk->pos,
                                ((FreezyPart241 *) func_80100094(actor, 0))[k].pos,
                                chunk->rotation);
                            chunk->rotation[2] = chunk->rotation[0];
                            chunk->rotation[0] = 0.0f;
                            chunk->rotation[1] -= 90.0f;
                        }
                    }
                } else {
                    switch (chunk->parent) {
                        case -4:
                            func_800EF214(chunk->pos, chunk->rotation[0] + 45.0f,
                                          actor->rotation[1], chunk->full_scale * 25.0f);
                            break;
                        case -5:
                            func_800EF214(chunk->pos, chunk->rotation[0] + 45.0f,
                                          chunk->rotation[1] + 90.0f, chunk->full_scale * 25.0f);
                            break;
                        case -3:
                            func_800EF214(chunk->pos, chunk->rotation[0] + 90.0f,
                                          chunk->rotation[1] + 90.0f, chunk->full_scale * 25.0f);
                            break;
                        case -2:
                            func_800EF214(chunk->pos, chunk->rotation[0] - 90.0f,
                                          chunk->rotation[1] + 90.0f, chunk->full_scale * 25.0f);
                    }
                }
            }
        }
        chunk->full_scale *= *(f32 *) &actor->actorData[7];
    }
}

void func_808011A8_chnewfreezy(f32 angle_y, f32 angle_x)
{
    FreezyQuaternion35 rot = *(FreezyQuaternion35 *) D_8080195C_chnewfreezy;
    Vec3f euler = *(Vec3f *) D_8080196C_chnewfreezy;
    FreezyQuaternion35 orig_a;
    FreezyQuaternion35 orig_b;
    s32 anim;
    anim = func_800DF324();
    func_800DFB40(anim, 0x12, orig_a.q);
    euler.f[1] = angle_y * 0.75f;
    euler.f[0] = -angle_x * 0.9f;
    func_800D93A0(&rot, euler.f);
    func_800D9470(&rot, &rot, orig_a.q);
    func_800DFF2C(anim, 0x12, &rot);
    func_800DFB40(anim, 1, orig_b.q);
    euler.f[1] = angle_y * 0.25f;
    euler.f[0] = -angle_x * 0.1f;
    func_800D93A0(&rot, euler.f);
    func_800D9470(&rot, &rot, orig_b.q);
    func_800DFF2C(anim, 1, &rot);
}

// Returns the largest distance from actorData[4..6] to a chunk edge.
f32 func_808012F8_chnewfreezy(Actor *actor)
{
    f32 radius;
    FreezyFragment *chunk;
    u32 i;
    f32 reach;

    chunk = func_80100094(actor, 0);
    radius = 0.0f;
    for (i = 0; i < actor->unk6C_0; i++, chunk++) {
        if (chunk->state != 3) {
            reach = func_800EEAD4((f32 *) &actor->actorData[4], chunk->pos) +
                      25.0f * chunk->full_scale;
            if (radius < reach)
                radius = reach;
        }
    }
    return radius;
}

// Spawns the skeleton ice for a frozen actor; returns NULL if it has no freeze config.
Actor *chnewfreezy_entrypoint_0(Unk80132ED0 *frozen_handle, s32 x, s32 y, s32 z)
{
    Actor *frozen;
    Actor *ice;
    s32 skeleton;
    s32 configs;
    s32 config_count;
    s32 has_angles = 0;
    f32 angle_x;
    f32 angle_y;
    Vec3f angles;

    frozen = func_80106790(frozen_handle);
    config_count = func_8010108C(frozen, 0x38, 0);
    if (config_count <= 0) {
        return NULL;
    }
    configs = func_80101080();
    ice = func_801084B0(0x2FF, &frozen);
    ((f32 *) ice->actorData)[0] = x;
    ((f32 *) ice->actorData)[1] = y;
    ((f32 *) ice->actorData)[2] = z;
    ice->rotation[0] = frozen->rotation[0];
    ice->rotation[1] = frozen->rotation[1];
    ice->rotation[2] = frozen->rotation[2];
    ((f32 *) ice->actorData)[7] = frozen->scale;
    ice->unk50 = 0.0f;
    func_80103DFC(frozen, (f32 *) &ice->actorData[4]);
    skeleton = func_800B27E0(func_801039E4(frozen->unk0));
    ice->unk6C_0 = _dbskeleton_entrypoint_0(skeleton);
    func_80100074(ice, 0, ice->unk6C_0 * 0x60);
    if (*(s16 *) ((u8 *) ice->unk0 + 0x10) == 0) {
        *(s16 *) ((u8 *) ice->unk0 + 0x10) = func_800AE020();
    }
    func_800DF41C(func_8008B4D4(func_80104248(frozen)));
    if (func_8010108C(frozen, 0x94, 0) > 0) {
        func_80101038(angles.f);
        has_angles = 1;
        angle_x = angles.pos.x;
        angle_y = angles.pos.y;
    }
    if (has_angles) {
        func_808011A8_chnewfreezy(angle_y, angle_x);
    }
    func_80800974_chnewfreezy(ice, skeleton);
    func_80800AA4_chnewfreezy(ice, skeleton);
    func_80800BFC_chnewfreezy(ice, skeleton);
    func_80800D28_chnewfreezy(ice, skeleton);
    func_80800E74_chnewfreezy(ice, skeleton, configs, config_count);
    ice->unk74_7 = func_808012F8_chnewfreezy(ice);
    ice->scale = (f32) ice->unk74_7 / func_800EC708(ice->unk0);
    _sufreezy_entrypoint_3(ice);
    return ice;
}

// Draws one ice model per chunk.
void func_808016B4_chnewfreezy(actor, unk_0) Actor *actor;
s32 unk_0;
{
    FreezyDrawPart *part;
    s32 models[3];
    u32 i;
    if (func_800E3E8C((f32 *) ((u8 *) actor + 0x28), (f32) actor->unk74_7)) {
        part = func_80100094(actor, 0);
        models[0] = func_800D674C(0x74C);
        models[1] = func_800D674C(0x74D);
        models[2] = func_800D674C(0x74E);
        for (i = 0; i < actor->unk6C_0; i++, part++) {
            if (part->state != 3) {
                if (_subaddiefade_entrypoint_0(actor) < 255)
                    func_800DF410(_subaddiefade_entrypoint_0(actor));
                func_800DF830(2);
                func_800DE448((u8 *) part + 0x3C, (u8 *) part + 0xC, part->scale, 0,
                              models[part->model]);
            }
        }
    }
}

s32 func_808017FC_chnewfreezy(Actor *actor, s32 msg, FreezyMessage arg)
{
    switch (msg) {
        case 0x3E:
            if (actor->unk50 > 0.75f) {
                func_80800068_chnewfreezy(actor);
                _sufreezy_entrypoint_5(actor->unk0, arg.word);
                func_808000D4_chnewfreezy(actor);
                func_808000AC_chnewfreezy((s32) actor);
            }
            break;
        case 0x3F:
            _sufreezy_entrypoint_6(actor->unk0, arg.word);
            return 1;
        case 0x40:
            func_80800068_chnewfreezy(actor);
            _sufreezy_entrypoint_7(actor->unk0, arg.word);
            func_808000D4_chnewfreezy(actor);
            func_808000AC_chnewfreezy((s32) actor);
            return 1;
        case 0x95:
            if (!_subaddielink_entrypoint_3(func_80100094(actor, 1)))
                func_800FFAB0(actor);
            break;
        default:
            return 0;
    }
    return 1;
}

int chnewfreezy_entrypoint_1()
{
    return (int) &D_80801978_chnewfreezy;
}

// TU-NOTE: the overlay .data is defined here in C; its tables point to functions of this file,
// and IDO schedules some of them differently unless they share the unit. Values come from the ROM.
// D_80801978_chnewfreezy is declared int[] to match the object.

Vec3f D_80801950_chnewfreezy = {0.577f, 0.577f, 0.577f};
u8 D_8080195C_chnewfreezy[16] = {0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
                                 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0};
u8 D_8080196C_chnewfreezy[12] = {0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0};
int D_80801978_chnewfreezy[18] = {0x2F602FF,
                                  0x75D0001,
                                  0x0,
                                  (u32) func_808002C0_chnewfreezy,
                                  (u32) func_80105834,
                                  (u32) func_808016B4_chnewfreezy,
                                  0x0,
                                  0x0,
                                  0x0,
                                  0x120020,
                                  (u32) func_80800020_chnewfreezy,
                                  (u32) func_80108ED0,
                                  0x8,
                                  (u32) func_80800000_chnewfreezy,
                                  (u32) func_80107C2C,
                                  -0x7FFFE000,
                                  (u32) func_808017FC_chnewfreezy,
                                  0x0};
