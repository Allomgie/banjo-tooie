// Skeleton explode effect: copies another actor's model, splits it into one piece per bone, throws
// the pieces with random spin, bounce sounds per material, and fades them out. Used by few actors.
#include "common.h"
#include "core2/1EC8070.h"

typedef struct {
    u8 pad_0[0x74];
    u32 pad_1 : 28, flags : 4;
    u32 pad_2 : 18, phase : 2, step : 3, pad_3 : 9;
} SkeletonFlags1436;
extern s32 func_80103140();
// One piece (bone) of the exploded skeleton.
typedef struct {
    f32 pos[3];
    f32 pivot[3];
    f32 rot[3];
    f32 vel[3];
    f32 spin[3];
    u8 state; // 1 = flying, 2 = finished
    u8 pad_3D[3];
} CodexSkeletonPiece65;
extern f32 func_800F1DF4(f32[3], f32[3]);
extern f32 func_800DC178(f32, f32);
extern f32 _dbskeleton_entrypoint_1(s32);
typedef struct Mass47SkeletonPiece {
    Vec3f pos;
    Vec3f pivot;
    Vec3f rot;
    Vec3f vel;
    f32 spin[3];
    u8 state;
    u8 pad_3D[3];
} Mass47SkeletonPiece;
extern void *func_800B27E0(void *);
extern void *func_801039E4(Unk80132ED0 *);
extern void *func_80100094(Actor *, u32);
extern Actor *func_80106790(Unk80132ED0 *);
extern Actor *func_801084B0(s32, Actor **);
extern void _chskeletonexplode_entrypoint_0();
extern void _chbaddiesetup_entrypoint_6(void (*)(), Unk80132ED0 *, s32, s32, s32, s32, s32);
extern void func_800ADD80();
extern void func_800ADEC4();
extern void func_800DF6BC();
extern void func_800DF758();
extern void mlMtxTranslate(f32, f32, f32);
extern void mlMtxRotatePYR(f32, f32, f32);
extern int D_80801138_chskeletonexplode[];
extern u8 D_80801090_chskeletonexplode[];
extern u8 D_808010C0_chskeletonexplode[];
extern u8 D_80801120_chskeletonexplode[];
extern u8 D_808010F0_chskeletonexplode[];
extern u8 D_808010D8_chskeletonexplode[];
extern u8 D_808010A8_chskeletonexplode[];
extern u8 D_80801108_chskeletonexplode[];
extern f32 func_800D8FF8(void);
extern s32 func_800BEF00(f32 *, f32 *, f32 *, u32);
extern void func_800EFDE8(f32 *, f32 *, f32 *);
extern void func_800EFA20(f32 *, f32 *, f32);
extern void func_801018A4(), func_80105834(), func_80107C2C(), func_80800000_chskeletonexplode(),
    func_80800034_chskeletonexplode();

void func_80800000_chskeletonexplode(actor) Actor *actor;
{
    f32 *state;

    state = func_80100094(actor, 1);
    actor->unk58 = 0.0f;
    *state = 0.0f;
}

void func_80800034_chskeletonexplode(actor) u8 **actor;
{
    // Matching: the extra temporary is needed for the match.
    s16 list_id;
    if (*(s16 *) ((s8 *) *actor + 0x10) != 0) {
        list_id = *(s16 *) ((s8 *) *actor + 0x10);
        func_800ADFE0(list_id, *(s16 *) ((s8 *) *actor + 0x10), actor);
        *(s16 *) ((s8 *) *actor + 0x10) = 0;
    }
}

// Plays the bounce sound of the selected sound set, at most every 0.25 s.
void func_8080007C_chskeletonexplode(Actor *actor, f32 *pos)
{
    u8 *state;

    state = func_80100094(actor, 1);
    if (*(f32 *) state > 0.0f) {
        *(f32 *) state -= func_800D8FF8();
    } else {
        switch (state[0xF4]) {
            case 0:
                break;
            case 1:
                _subaddieaudioquick_entrypoint_2(actor, pos, D_80801090_chskeletonexplode);
                break;
            case 2:
                _subaddieaudioquick_entrypoint_2(actor, pos, D_808010A8_chskeletonexplode);
                break;
            case 3:
                _subaddieaudioquick_entrypoint_2(actor, pos, D_808010C0_chskeletonexplode);
                break;
            case 4:
                _subaddieaudioquick_entrypoint_2(actor, pos, D_808010D8_chskeletonexplode);
                break;
            case 5:
                _subaddieaudioquick_entrypoint_2(actor, pos, D_808010F0_chskeletonexplode);
                break;
            case 6:
                _subaddieaudioquick_entrypoint_2(actor, pos, D_80801108_chskeletonexplode);
                break;
            case 7:
                _subaddieaudioquick_entrypoint_2(actor, pos, D_80801120_chskeletonexplode);
                break;
        }
        *(f32 *) state = 0.25f;
    }
}

// Per-frame update: moves each flying piece, bounces it off the ground and fades the actor out
// when all pieces are finished.
void func_808001BC_chskeletonexplode(Actor *actor)
{
    CodexSkeletonPiece65 *piece;
    f32 world_pos[3];
    f32 step[3];
    f32 normal[3];
    f32 speed;
    f32 ray_start[3];
    f32 ray_end[3];
    f32 reach;
    s32 all_done;
    f32 dt;
    f32 dist;
    u32 i;

    piece = func_80100094(actor, 0);
    all_done = 1;
    dt = func_800D8FF8();
    if (actor->unk58 < 5.0f) {
        actor->unk58 += dt;
    } else {
        _subaddiefade_entrypoint_3(actor);
    }
    for (i = 0; i < actor->unk6C_0; i++) {
        if (piece->state != 1) {
            piece++;
            continue;
        }
        func_800EFA20(step, piece->vel, dt);
        func_800EE780(world_pos, piece->pivot, piece->pos);
        func_800EF04C(world_pos, actor->position);
        all_done = 0;
        func_800EE7F8(ray_start, world_pos);
        func_800EE7F8(ray_end, ray_start);
        func_800EF04C(ray_end, step);
        func_800EF04C(ray_end, step);
        if (actor->position[1] - ray_end[1] > 2000.0f) {
            piece->state = 2;
        } else if (func_800BEF00(ray_start, ray_end, normal, 0x20020)) {
            speed = func_800EEF94(piece->vel);
            reach = func_800EEF94(step) * 2;
            dist = func_800EEAD4(ray_start, ray_end);
            if (dist < reach) {
                func_800EF334(step, dist / reach * 0.9f);
            }
            func_800EFDE8(piece->vel, piece->vel, normal);
            func_800EF368(piece->vel, speed * 0.35f);
            func_800EF334(piece->spin, 0.35f);
            if (speed < 250.0f) {
                piece->state = 2;
            }
            func_8080007C_chskeletonexplode(actor, ray_end);
        } else {
            piece->vel[0] *= 0.95f;
            piece->vel[2] *= 0.95f;
            piece->vel[1] += ((f32 *) actor->actorData)[7] * func_800D8FF8();
            func_800EF04C(piece->rot, piece->spin);
            func_800EF334(piece->spin, 0.99f);
        }
        func_800EF04C(piece->pos, step);
        piece++;
    }
    if (all_done) {
        _subaddiefade_entrypoint_3(actor);
    }
}

// Copies rotation, scale and flag fields from src to dst.
void func_808004DC_chskeletonexplode(Actor *dst, Actor *src, s32 unk_0, s32 unk_1)
{
    dst->rotation[0] = src->rotation[0];
    dst->rotation[2] = src->rotation[2];
    dst->rotation[1] = src->rotation[1];
    dst->scale = src->scale;
    func_80103140(dst, (u16) unk_0, (u16) unk_1);
    ((SkeletonFlags1436 *) dst)->flags = ((SkeletonFlags1436 *) src)->flags;
    ((SkeletonFlags1436 *) dst)->step = ((SkeletonFlags1436 *) src)->step;
    ((SkeletonFlags1436 *) dst)->phase = ((SkeletonFlags1436 *) src)->phase;
}

// Sets the default speed range, spin range and gravity.
void func_80800594_chskeletonexplode(u8 *actor)
{
    *(f32 *) (actor + 0x30) = 15.0f;
    *(f32 *) (actor + 0x18) = 15.0f;
    *(f32 *) (actor + 0x28) = 800.0f;
    *(f32 *) (actor + 0x2C) = 1000.0f;
    *(f32 *) (actor + 0x34) = -2000.0f;
}

void func_808005CC_chskeletonexplode(Actor *actor, s32 src, f32 *origin)
{
    s32 skeleton;
    s32 unk_0;
    s32 bone_list;
    s32 pose;
    CodexSkeletonPiece65 *piece;
    u32 i;
    s32 bone;
    f32 yaw;
    f32 rand_offset;
    f32 world_pos[3];
    f32 unk_1[4];

    skeleton = func_800B27E0(func_801039E4(actor->unk0));
    unk_0 = func_80104248(src);
    func_8008C200(((s16 *) actor->unk0)[8], skeleton, func_8008AEDC(unk_0));
    pose = func_8008C27C(func_8008AEDC(unk_0));
    actor->unk6C_0 = func_800AE124(((s16 *) actor->unk0)[8]);
    bone_list = func_800AE080(((s16 *) actor->unk0)[8]);
    func_80100074(actor, 0, actor->unk6C_0 << 6);
    piece = func_80100094(actor, 0);
    for (i = 0; i < actor->unk6C_0; i++, piece++) {
        bone = _dbskeleton_entrypoint_4(skeleton, i);
        func_800F2C1C(func_800ADE50(bone_list, skeleton, bone), piece->rot);
        func_800AE630(bone_list, skeleton, bone, piece->pos);
        func_800EE780(world_pos, actor->position, piece->pos);
        yaw = func_800F1DF4(world_pos, origin) - actor->rotation[1];
        _dbskeleton_entrypoint_2(skeleton, bone, piece->pivot);
        func_800EF3DC(piece->pos, piece->pivot);
        rand_offset = func_800DC178(-20.0f, 20.0f);
        func_800EEC30(piece->vel, rand_offset + 130.0f, func_800DC178(-65.0f, 65.0f) + yaw,
                      1000.0f);
        piece->state = 1;
    }
    for (i = 0; i < actor->unk6C_0; i++) {
        piece = (CodexSkeletonPiece65 *) func_80100094(actor, 0) + i;
        if (piece->state == 4) {
            func_800DFC20(pose, _dbskeleton_entrypoint_4(skeleton, i), piece->pos);
            func_800EF334(piece->pos, _dbskeleton_entrypoint_1(skeleton));
        }
    }
}

void func_80800894_chskeletonexplode(Actor *actor, u32 src, void *origin)
{
    f32 yaw;
    f32 rand_offset;
    void *skeleton;
    Mass47SkeletonPiece *piece;
    u32 i;
    f32 *actor_pos;
    f32 world_pos[3];

    skeleton = func_800B27E0(func_801039E4(actor->unk0));
    actor->unk6C_0 = _dbskeleton_entrypoint_0(skeleton);
    func_80100074(actor, 0, actor->unk6C_0 << 6);
    piece = func_80100094(actor, 0);
    i = 0;
    actor_pos = actor->position;
    if (actor->unk6C_0 != 0) {
        do {
            _dbskeleton_entrypoint_2(skeleton, _dbskeleton_entrypoint_4(skeleton, i),
                                     &piece->pivot);
            func_800EFD24(&piece->pos);
            func_800EE780(world_pos, &piece->pivot, actor_pos);
            yaw = func_800F1DF4(world_pos, origin);
            piece->rot.f[0] = 0.0f;
            piece->rot.f[1] = actor->rotation[1];
            piece->rot.f[2] = 0.0f;
            rand_offset = func_800DC178(-20.0f, 20.0f);
            func_800EEC30(piece->vel.f, rand_offset + 130.0f,
                          func_800DC178(-65.0f, 65.0f) + yaw, 1000.0f);
            piece->state = 1;
            i++;
            piece++;
        } while (i < actor->unk6C_0);
    }
    actor->rotation[1] = 0.0f;
    actor->rotation[0] = 0.0f;
    actor->rotation[2] = 0.0f;
}

// Deferred-spawn init callback: creates the exploder actor from the source actor, then
// throws the pieces with random speed and spin.
void chskeletonexplode_entrypoint_0(Unk80132ED0 *spawn, s32 x, s32 y, s32 z,
                                    s32 unk_0, s32 unk_1)
{
    Actor *exploder;
    Actor *src;
    u8 *state;
    u8 *piece_data;
    u32 i;
    f32 origin[3];
    Unk80132ED0 *spawn_ref;

    // Matching: the parameter copy and the empty if on its address are needed for the match.
    spawn_ref = spawn;
    if (&spawn) {
    }
    origin[0] = x;
    origin[1] = y;
    origin[2] = z;
    src = func_80106790(spawn_ref);
    exploder = func_801084B0(0x304, &src);
    src = func_80106790(spawn_ref);
    state = func_80100094(exploder, 1);
    func_808004DC_chskeletonexplode(exploder, src, unk_0, unk_1);
    if (!*(s16 *) ((u8 *) exploder->unk0 + 0x10)) {
        *(s16 *) ((u8 *) exploder->unk0 + 0x10) = func_800AE020();
    }
    src->unk64_16 = 0;
    func_80800594_chskeletonexplode(exploder);
    if (func_80104248(src))
        func_808005CC_chskeletonexplode(exploder, src, origin);
    else
        func_80800894_chskeletonexplode(exploder, src, origin);
    *(s32 *) (state + 4) = 0;
    state[0xF4] = 0;
    state[0xF5] = 0;
    if (*(u16 *) ((u8 *) spawn_ref + 0x18) & 1) {
        func_80101074(exploder->unk0);
        func_8010114C(spawn_ref, 0xF, 0);
    }
    piece_data = func_80100094(exploder, 0);
    for (i = 0; i < exploder->unk6C_0; i++, piece_data += 0x40) {
        func_800EF334((f32 *) (piece_data + 0x24), func_800DC178(*(f32 *) &exploder->actorData[4],
                                                                 *(f32 *) &exploder->actorData[5]) /
                                                       1000.0f);
        *(f32 *) (piece_data + 0x30) =
            func_800DC178(*(f32 *) &exploder->actorData[6], *(f32 *) &exploder->actorData[0]);
        *(f32 *) (piece_data + 0x34) =
            func_800DC178(*(f32 *) &exploder->actorData[6], *(f32 *) &exploder->actorData[0]);
        *(f32 *) (piece_data + 0x38) =
            func_800DC178(*(f32 *) &exploder->actorData[6], *(f32 *) &exploder->actorData[0]);
    }
}

// Sets the speed range of the pieces.
void chskeletonexplode_entrypoint_1(Actor *actor, f32 speed_min, f32 speed_max)
{
    // Matching: the extra pointer temporary is needed for the match.
    f32 *field;
    field = (char *) actor;
    *(f32 *) (field + 10) = speed_min;
    field = (f32 *) ((char *) actor + 44);

    *field = speed_max;
}

// Sets the spin range of the pieces.
void chskeletonexplode_entrypoint_2(Actor *actor, f32 spin_min, f32 spin_max)
{
    *(f32 *) ((char *) actor + 0x30) = spin_min;
    *(f32 *) ((char *) actor + 0x18) = spin_max;
}

void chskeletonexplode_entrypoint_3(s32 actor, s32 index, s32 value)
{
    s32 *state = func_80100094(actor, 1);
    state[index + 1] = value;
    if (state[1] < index) {
        state[1] = index;
    }
}

// Selects the bounce sound set (1-7, 0 = none).
void chskeletonexplode_entrypoint_4(s32 actor, s32 sound_set)
{
    void *state;
    state = func_80100094(actor, 1);
    *(u8 *) ((char *) state + 0xF4) = sound_set;
}

void chskeletonexplode_entrypoint_5(s32 actor, s32 light_group)
{
    Actor *state;
    state = func_80100094(actor, 1);
    *((char *) state + 0xF5) = light_group;
}

void chskeletonexplode_entrypoint_6(Actor *actor, f32 pos[3], s32 unk_0, s32 unk_1)
{
    s32 spawn_pos[3];

    func_800EE904(spawn_pos, pos);
    _chbaddiesetup_entrypoint_6(_chskeletonexplode_entrypoint_0, actor->unk0, spawn_pos[0],
                                spawn_pos[1], spawn_pos[2], unk_0, unk_1);
}

void chskeletonexplode_entrypoint_7(Actor *actor, s32 pos)
{
    s32 spawn_pos[3];
    s32 unk_0[2];

    unk_0[1] = *(u16 *) ((u8 *) actor->unk0 + 0x14);
    unk_0[0] = *(u16 *) ((u8 *) actor->unk0 + 0x16);
    func_800EE904(spawn_pos, pos);
    _chbaddiesetup_entrypoint_6(_chskeletonexplode_entrypoint_0, actor->unk0, spawn_pos[0],
                                spawn_pos[1], spawn_pos[2], unk_0[1], unk_0[0]);
}

void chskeletonexplode_entrypoint_8(u8 **actor, s16 *pos)
{
    s32 position[3];
    s32 unk_0[2];

    unk_0[1] = *(u16 *) (*actor + 0x14);
    unk_0[0] = *(u16 *) (*actor + 0x16);
    position[0] = pos[0];
    position[1] = pos[1];
    position[2] = pos[2];
    _chbaddiesetup_entrypoint_6(&_chskeletonexplode_entrypoint_0, *actor, position[0],
                                position[1], position[2], unk_0[1], unk_0[0]);
}

// Draws the pieces: builds each bone matrix from the piece transform.
void func_80800E88_chskeletonexplode(Actor *actor)
{
    u8 *state;
    s32 skeleton;
    s32 bone_list;
    f32 mtx[4][4];
    s32 bone;
    u32 i;
    u8 *piece;
    state = func_80100094(actor, 1);
    skeleton = func_800B27E0(func_801039E4(actor->unk0));
    piece = func_80100094(actor, 0);
    func_801015D0(actor);
    func_800ADD80(*(s16 *) ((u8 *) actor->unk0 + 0x10), skeleton);
    bone_list = func_800AE080(*(s16 *) ((u8 *) actor->unk0 + 0x10));
    for (i = 0; i < actor->unk6C_0; i++, piece += 0x40) {
        bone = _dbskeleton_entrypoint_4(skeleton, i);
        func_80019CD4();
        mlMtxTranslate(*(f32 *) (piece + 12), *(f32 *) (piece + 16), *(f32 *) (piece + 20));
        mlMtxTranslate(*(f32 *) piece, *(f32 *) (piece + 4), *(f32 *) (piece + 8));
        mlMtxRotatePYR(*(f32 *) (piece + 24), *(f32 *) (piece + 28), *(f32 *) (piece + 32));
        mlMtxTranslate(-*(f32 *) (piece + 12), -*(f32 *) (piece + 16),
                       -*(f32 *) (piece + 20));
        mlMtxGet(mtx);
        func_800ADEC4(bone_list, skeleton, bone, mtx);
    }
    func_800DF72C(bone_list);
    func_800DF758(state + 4);
    if (!state[0xF5])
        return;
    func_800DF6BC(state[0xF5], *((u8 *) actor + 0x9B));
}

s32 func_8080100C_chskeletonexplode(actor, unk_0, unk_1)
s32 actor;
s32 unk_0;
s32 unk_1;
{
    if (unk_0 == 0x1F) {
        func_80800E88_chskeletonexplode(actor);
    } else {
        return 0;
    }
    return 1;
}

int *chskeletonexplode_entrypoint_9()
{
    return &D_80801138_chskeletonexplode;
}

// TU-NOTE: the overlay .data is defined here in C; IDO schedules some functions differently
// unless these tables (which point to functions of this file) share the unit. The extern of
// D_80801138_chskeletonexplode is declared int[] to match the object.
u8 D_80801090_chskeletonexplode[24] = {0x0, 0x13, 0x4, 0x15, 0x0,  0xD,  0x0, 0xE6,
                                       0x1, 0x0,  0x0, 0x16, 0x1F, 0x40, 0x0, 0x1,
                                       0x5, 0xDC, 0x9, 0xC4, 0x0,  0x0,  0x0, 0x0};
u8 D_808010A8_chskeletonexplode[24] = {0x0, 0x13, 0x4, 0x16, 0x0,  0xD,  0x0, 0xE6,
                                       0x1, 0x0,  0x0, 0x16, 0x1F, 0x40, 0x0, 0x1,
                                       0x5, 0xDC, 0x9, 0xC4, 0x0,  0x0,  0x0, 0x0};
u8 D_808010C0_chskeletonexplode[24] = {0x0, 0x13, 0x4, 0x17, 0x0,  0xD,  0x0, 0xE6,
                                       0x1, 0x0,  0x0, 0x16, 0x1F, 0x40, 0x0, 0x1,
                                       0x5, 0xDC, 0x9, 0xC4, 0x0,  0x0,  0x0, 0x0};
u8 D_808010D8_chskeletonexplode[24] = {0x0, 0x13, 0x4, 0x5A, 0x0,  0xD,  0x0, 0xE6,
                                       0x1, 0x0,  0x0, 0x16, 0x1F, 0x40, 0x0, 0x1,
                                       0x5, 0xDC, 0x9, 0xC4, 0x0,  0x0,  0x0, 0x0};
u8 D_808010F0_chskeletonexplode[24] = {0x0, 0x13, 0x4, 0xB,  0x0,  0xD,  0x0, 0xF3,
                                       0x1, 0xC,  0x0, 0x16, 0x1F, 0x40, 0x0, 0x1,
                                       0x5, 0xDC, 0x9, 0xC4, 0x0,  0x0,  0x0, 0x0};
u8 D_80801108_chskeletonexplode[24] = {0x0, 0x13, 0x4, 0x1F, 0x0,  0xD,  0x0, 0xF3,
                                       0x1, 0xC,  0x0, 0x16, 0x1F, 0x40, 0x0, 0x1,
                                       0x5, 0xDC, 0x9, 0xC4, 0x0,  0x0,  0x0, 0x0};
u8 D_80801120_chskeletonexplode[24] = {0x0, 0x13, 0x4, 0xA0, 0x0,  0xD,  0x0, 0xF3,
                                       0x1, 0xC,  0x0, 0x16, 0x1F, 0x40, 0x0, 0x1,
                                       0x5, 0xDC, 0x9, 0xC4, 0x0,  0x0,  0x0, 0x0};
int D_80801138_chskeletonexplode[18] = {0x2C40304,
                                        -0xFFFF,
                                        0x0,
                                        (u32) func_808001BC_chskeletonexplode,
                                        (u32) func_80105834,
                                        (u32) func_801018A4,
                                        0x0,
                                        0x0,
                                        0x0,
                                        0x800424,
                                        (u32) func_80800034_chskeletonexplode,
                                        0x0,
                                        0xF8,
                                        (u32) func_80800000_chskeletonexplode,
                                        (u32) func_80107C2C,
                                        -0x7F7FFFFE,
                                        (u32) func_8080100C_chskeletonexplode,
                                        0x0};
