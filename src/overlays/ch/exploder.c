// Generic shatter actor (0x1FF): splits a model into one debris piece per bone, throws the pieces
// with spin, bounces them off the map with dust and sounds, and fades them out. Entrypoints are
// the API that many actors use to break walls, doors, crates and boss parts.
#include "common.h"
#include "core1/mlmtx.h"

extern void *D_80801AE0_chexploder;
typedef struct {
    u8 pad_0[0x14];
    u16 unk_14;
    u16 unk_16;
} ExploderAnimation1246;
typedef union {
    s32 value;
    s16 halves[2];
} ExploderMessage1483;
extern void *func_80100094(Actor *, s32);
extern Unk80132ED0 *func_80101080(void);
extern void func_801018A4(Actor *, Unk80132ED0 *);
extern void func_80103140();
typedef struct {
    s16 cfg[8];
    s16 max_bounces;
    u8 impact_sound;
    u8 dust_kind;
    u8 pad_0[4];
    u8 sound_played;
    u8 pad_1[0x3F];
    f32 dust_scale;
} ExploderInit;
extern f32 func_800DC178(f32, f32);
extern void func_800EF368(f32 *, f32);
typedef struct {
    s16 a, b;
} S16Pair;
typedef struct {
    u8 pad[0x70];
    u8 pad70 : 7;
    u8 f70 : 1;
    u8 pad71 : 2;
    u8 f71 : 1;
    u8 rest71 : 5;
} ExplS;
extern s32 func_800B26F0(s32);
typedef struct {
    s16 id;
    s16 x;
    s16 y;
    s16 z;
    f32 yaw;
    f32 scale;
    s32 flags;
} ExploderSpawn;
typedef struct {
    u8 pad0[0x14];
    u16 unk_14;
    u16 unk_16;
    u8 pad18[0x3C];
    u16 options;
} ExploderLocal;
typedef struct {
    u32 pad74_26 : 6;
    u32 unk74_25 : 1;
    u32 pad74_0 : 25;
} ActorFlags74b;
extern Actor *func_80108474(s32, f32 *, s32);
extern Actor *func_80106790();
extern void func_800EE7F8();
extern void func_80101074();
extern s32 func_8010108C(Actor *, s32, s32);
extern void func_80101038(f32 *);
extern void func_80108944(Actor *, Actor *);
extern s32 func_801039E4(Unk80132ED0 *);
extern s32 func_80104248(Actor *);
extern s32 _chexploder_entrypoint_1[];
extern void func_800EE88C(f32 *, s32);
extern s32 _chexploder_entrypoint_2;
extern void func_8010A570();
extern void _chbaddiesetup_entrypoint_6(void *, s32, s32, s32, s32, s32, s32);
typedef struct {
    u8 pad_0[0xE];
    s16 count;
} ExploderPartCount1332;
typedef struct {
    u8 pad_0[0x36];
    u8 pad_1 : 1;
    u8 active : 1;
    u8 pad_2 : 6;
    u8 pad_3[2];
    u8 bone;
    u8 pad_4[2];
} ExploderSelectablePart1332;
typedef struct {
    u8 pad[0xE];
    s16 count;
} ExploderCount;
typedef struct {
    u8 pad[0x36];
    u8 pad_0 : 1;
    u8 active : 1;
    u8 pad_1 : 6;
    u8 pad_37[2];
    u8 bone;
    u8 pad_3A[2];
} ExploderPiece;
typedef struct {
    f32 pos[3];
    f32 rest[3];
    f32 vel[3];
    f32 rot_x;
    f32 rot_y;
    f32 rot_z;
    s16 spin_x;
    s16 spin_z;
    s16 gravity;
    u16 no_collide : 1;
    u16 active : 1;
    u16 can_bounce : 1;
    u16 pad36 : 13;
    u8 bounces;
    u8 pad39[3];
} ExplPart;
typedef struct {
    u8 pad0[0xC];
    s16 radius;
    s16 piece_count;
    s16 max_bounces;
    u8 pad12[0x5C - 0x12];
    f32 sound_timer;
} ExplHead;
extern f32 func_800D8FF8(void);
extern s32 func_8001210C(s32);
extern void func_800EFA20(f32 *, f32 *, f32);
extern void func_800EF04C(f32 *, f32 *);
extern f32 func_800EEB40(f32 *, f32 *);
extern s32 func_800BF340(f32 *, f32 *, f32 *, u32, f32);
extern f32 func_800EEF94(f32 *);
extern void func_800EFDE8(f32 *, f32 *, f32 *);
typedef struct {
    s16 sound_id;
    s16 volume;
    s16 pitch_min;
    s16 pitch_max;
    s16 pitch_step;
} ExpE;
extern ExpE D_80801B28_chexploder[];
extern s32 D_80801BA0_chexploder[];
extern void func_800C4B7C(s32);
extern void func_800C4B64(f32);
extern void func_800C4B70(s32);
extern f32 func_800EEFD4();
extern s32 func_800BABB8(s32, f32 *, f32 *, f32, void *);
extern u8 D_80801BB0_chexploder[];
extern u8 D_80801BD8_chexploder[];
extern u8 D_80801BE4_chexploder[];
extern u8 D_80801BF0_chexploder[];
extern u8 D_80801C00_chexploder[];
typedef struct {
    f32 pos[3];
    f32 rest[3];
    f32 vel[3];
    f32 rot[3];
    u8 pad_0[6];
    u8 no_collide : 1;
    u8 active : 1;
    u8 bl : 6;
    u8 pad_1[2];
    u8 bone;
    u8 pad_2[2];
} CodexExploderPiece65;
extern int func_800EF5A0(f32[3], f32[3], f32, f32, f32);
extern int func_800EF334(f32[3], f32);
extern int func_800EEBF0(f32[3], f32[2], f32);
typedef struct {
    u8 pad_0[0x36];
    u8 no_collide : 1;
    u8 active : 1;
    u8 rest : 6;
} Exp36;
extern void *func_80100074(Actor *, u32, s32);
void func_80800154_chexploder();
void chexploder_entrypoint_9();
s32 func_808002FC_chexploder();
void func_8080067C_chexploder();
void func_80800834_chexploder();

int chexploder_entrypoint_0()
{
    return &D_80801AE0_chexploder;
}

void func_8080000C_chexploder(s32 arg0)
{
}

void func_80800014_chexploder(Actor *actor)
{
    if (actor->unk70_10 == 1 && !func_808002FC_chexploder(actor)) {
        func_80101FDC(actor, 2);
        _subaddiefade_entrypoint_3(actor);
        func_8010A800(actor, 2);
    }
}

void func_80800078_chexploder(u8 **actor)
{
    s16 slot;
    if (*(s16 *) ((s8 *) *actor + 0x10) != 0) {
        slot = *(s16 *) ((s8 *) *actor + 0x10);
        func_800ADFE0(slot, *(s16 *) ((s8 *) *actor + 0x10), actor);
        *(s16 *) ((s8 *) *actor + 0x10) = 0;
    }
}

s32 func_808000C0_chexploder(Actor *actor, s32 msg, ExploderMessage1483 data)
{
    ExploderAnimation1246 *anim;

    switch (msg) {
        case 0xAB:
            func_801018A4(actor, func_80101080());
            break;
        case 0x1F:
            func_80800154_chexploder(actor, data.value);
            break;
        case 0x95:
            anim = func_80100094(actor, 0);
            func_80103140(actor, anim->unk_14, anim->unk_16);
            break;
        default:
            return 0;
    }
    return 1;
}

// Builds the piece pose matrices on the model for the given skeleton.
void func_80800154_chexploder(actor, model_id) Actor *actor;
s32 model_id;
{
    f32 inv_scale;
    MtxF mtx;
    s32 skeleton;
    s32 unk_0;
    s32 model;
    s32 i;
    u8 *cursor;
    u8 *head;
    skeleton = func_800B27E0(model_id);
    cursor = func_80100094(actor, 1);
    head = func_80100094(actor, 0);
    func_801015D0(actor);
    func_800ADD80(*(s16 *) ((u8 *) actor->unk0 + 0x10), skeleton);
    model = func_800AE080(*(s16 *) ((u8 *) actor->unk0 + 0x10));
    inv_scale = 1.0f / actor->scale;
    for (i = 0; i < *(s16 *) (head + 0xE); i++, cursor += 0x3C) {
        func_80019CD4();
        mlMtxTranslate(*(f32 *) (cursor + 0xC), *(f32 *) (cursor + 0x10),
                       *(f32 *) (cursor + 0x14));
        mlMtxTranslate(*(f32 *) cursor * inv_scale, *(f32 *) (cursor + 4) * inv_scale,
                       *(f32 *) (cursor + 8) * inv_scale);
        mlMtxRotatePYR(*(f32 *) (cursor + 0x24), *(f32 *) (cursor + 0x28),
                       *(f32 *) (cursor + 0x2C));
        mlMtxTranslate(-*(f32 *) (cursor + 0xC), -*(f32 *) (cursor + 0x10),
                       -*(f32 *) (cursor + 0x14));
        mlMtxGet(&mtx);
        func_800ADEC4(model, skeleton, cursor[0x39], &mtx);
    }
    func_800DF72C(model);
    i = 1;
    cursor = head + 1;
    for (; i <= head[0x18]; i++, cursor++) {
        func_800DF744(i, cursor[0x18]);
    }
}

// Per-frame piece physics; returns the number of pieces still active.
s32 func_808002FC_chexploder(actor)
Actor *actor;
{
    ExplHead *head;
    ExplPart *piece;
    f32 dt;
    s32 alive;
    f32 normal[3];
    f32 speed;
    s32 hit;
    s32 frame_parity;
    f32 world[3];
    f32 lookahead[3];
    f32 step[3];
    f32 ray_from[3];
    f32 ray_to[3];
    s32 i;

    head = func_80100094(actor, 0);
    piece = func_80100094(actor, 1);
    alive = 0;
    dt = func_800D8FF8();
    frame_parity = func_8001210C(1);
    head->sound_timer += dt;
    for (i = 0; i < head->piece_count; i++, piece++) {
        if (!piece->active) {
            continue;
        }
        piece->rot_x += piece->spin_x * dt;
        piece->rot_z += piece->spin_z * dt;
        piece->vel[1] += dt * piece->gravity;
        func_800EFA20(lookahead, piece->vel, 2.0f * dt);
        func_800EFA20(step, piece->vel, dt);
        func_800EFA20(world, piece->rest, actor->scale);
        func_800EF04C(world, piece->pos);
        func_800EF04C(world, actor->position);
        func_800EE7F8(ray_from, world);
        func_800EE7F8(ray_to, world);
        func_800EF04C(ray_to, lookahead);
        if (func_800EEB40(ray_to, actor->position) > 12250000.0f) {
            piece->active = 0;
            continue;
        }
        if (!piece->no_collide) {
            if (frame_parity == (i & 1)) {
                hit = func_800BF340(ray_from, ray_to, normal, actor->unk14, head->radius);
            } else {
                hit = 0;
            }
            if (hit) {
                if (piece->can_bounce) {
                    speed = func_800EEF94(piece->vel);
                    func_800EFDE8(piece->vel, piece->vel, normal);
                    func_800EF368(piece->vel, speed * 0.35f);
                    piece->spin_x = piece->spin_x * 0.35f;
                    piece->spin_z = piece->spin_z * 0.35f;
                    piece->bounces++;
                    if (head->max_bounces < piece->bounces || 2.0f * (dt * speed) < 10.0f) {
                        piece->active = 0;
                        continue;
                    }
                    func_8080067C_chexploder(actor, piece, ray_to);
                }
            } else if (!piece->can_bounce) {
                piece->can_bounce = 1;
            }
        }
        func_800EF04C(piece->pos, step);
        func_80800834_chexploder(actor, piece, ray_to);
        alive++;
    }
    return alive;
}

// Plays the impact sound for a bounce.
void func_8080067C_chexploder(actor, piece, pos) u8 *actor;
u8 *piece;
s32 pos;
{
    u8 *head;
    s32 idx;
    s32 sound_id;
    s32 volume;
    f32 pitch;
    f32 pitch_step;

    head = func_80100094(actor, 0);
    if (!(*(f32 *) (head + 0x5C) < 0.1f)) {
        if (head[0x12] != 0 && head[0x56] == 0) {
            idx = head[0x12] - 1;
            sound_id = D_80801B28_chexploder[idx].sound_id;
            volume = D_80801B28_chexploder[idx].volume;
            pitch = func_800DC178(D_80801B28_chexploder[idx].pitch_min * 0.00390625f,
                                    D_80801B28_chexploder[idx].pitch_max * 0.00390625f);
            pitch_step = D_80801B28_chexploder[idx].pitch_step * 0.00390625f;
            func_800C4B7C(sound_id);
            func_800C4B64(pitch - ((f32) (u32) piece[0x38] - 1.0f) * pitch_step);
            func_800C4B70(volume - piece[0x38] * 4000 + 4000);
            func_8010D930(7, *(s32 *) (actor + 0x70) & 1, pos, &D_80801BA0_chexploder);
            if (*(s16 *) (head + 0x54) & 0x100) {
                head[0x56] = 1;
            }
        }
        *(f32 *) (head + 0x5C) = 0.0f;
    }
}

// Spawns dust particles for a piece, by dust kind.
void func_80800834_chexploder(actor, piece, pos) Actor *actor;
u8 *piece;
f32 *pos;
{
    u8 *head;
    s32 emitter_1;
    s32 emitter_2;
    s32 emitter_3;
    s32 emitter_4;

    head = func_80100094(actor, 0);
    if (piece[0x38] < 3 && !(func_800EEFD4((f32 *) (piece + 0x18)) < 90000.0f)) {
        switch (head[0x13]) {
            case 1:
                emitter_1 = func_800B5BE4(0x18);
                func_800BABB8(emitter_1, pos, NULL, *(f32 *) (head + 0x58),
                              D_80801BB0_chexploder);
                func_800BABB8(emitter_1, pos, NULL, *(f32 *) (head + 0x58),
                              D_80801BD8_chexploder);
                break;
            case 2:
                emitter_2 = func_800B5BE4(0x18);
                func_800BABB8(emitter_2, pos, NULL, *(f32 *) (head + 0x58),
                              D_80801BB0_chexploder);
                func_800BABB8(emitter_2, pos, NULL, *(f32 *) (head + 0x58),
                              D_80801BE4_chexploder);
                break;
            case 3:
                emitter_3 = func_800B5BE4(0x18);
                func_800BABB8(emitter_3, pos, NULL, *(f32 *) (head + 0x58),
                              D_80801BB0_chexploder);
                func_800BABB8(emitter_3, pos, NULL, *(f32 *) (head + 0x58),
                              D_80801BF0_chexploder);
                break;
            case 4:
                emitter_4 = func_800B5BE4(0x18);
                func_800BABB8(emitter_4, pos, NULL, *(f32 *) (head + 0x58),
                              D_80801BB0_chexploder);
                func_800BABB8(emitter_4, pos, NULL, *(f32 *) (head + 0x58),
                              D_80801C00_chexploder);
        }
    }
}

void func_80800A18_chexploder(Actor *actor)
{
    ExploderInit *head;

    head = func_80100094(actor, 0);
    head->cfg[0] = 0x320;
    head->cfg[1] = 0x3E8;
    head->cfg[2] = 0xC8;
    head->cfg[3] = 0x12C;
    head->cfg[4] = -0x41A;
    head->cfg[5] = -0x3B6;
    head->cfg[6] = actor->scale * 30.0f;
    head->max_bounces = 4;
    head->sound_played = 0;
    head->impact_sound = 0;
    head->dust_kind = 0;
    head->dust_scale = 1.0f;
    chexploder_entrypoint_9(actor, 1, 0);
    chexploder_entrypoint_9(actor, 2, 1);
}

// Creates pieces from the source's animated pose, one per bone.
void func_80800AC8_chexploder(actor, source, center, options) Actor *actor;
s32 source;
f32 *center;
s32 options;
{
    f32 *rotation;
    u8 *head;
    s32 skeleton;
    s32 anim;
    s32 model;
    CodexExploderPiece65 *piece;
    s32 i;
    f32 angles[2];
    f32 world_pos[3];

    head = func_80100094(actor, 0);
    skeleton = func_800B27E0(func_801039E4(actor->unk0));
    anim = func_80104248(source);
    func_8008C238(((s16 *) actor->unk0)[8], skeleton, func_8008AEDC(anim));
    *(s16 *) (head + 0xE) = func_800AE124(((s16 *) actor->unk0)[8]);
    piece = func_80100074(actor, 1, *(s16 *) (head + 0xE) * 0x3C);
    model = func_800AE080(((s16 *) actor->unk0)[8]);
    for (i = 0; i < *(s16 *) (head + 0xE); i++, piece++) {
        piece->bone = _dbskeleton_entrypoint_4(skeleton, i);
        func_800F2C1C(func_800ADE50(model, skeleton, piece->bone), piece->rot);
    }
    piece = func_80100094(actor, 1);
    func_8008C200(((s16 *) actor->unk0)[8], skeleton, func_8008AEDC(anim));
    model = func_800AE080(((s16 *) actor->unk0)[8]);
    rotation = actor->rotation;
    for (i = 0; i < *(s16 *) (head + 0xE); i++, piece++) {
        func_800AE630(model, skeleton, piece->bone, piece->rest);
        func_800EF5A0(world_pos, rotation, piece->rest[0], piece->rest[1],
                      piece->rest[2]);
        func_800EF334(world_pos, actor->scale);
        func_800EF04C(world_pos, actor->position);
        func_800F18FC(center, world_pos, angles);
        func_800EFD24(piece->pos);
        func_800EEBF0(piece->vel, angles, 1000.0f);
        if (options & 0x10) {
            piece->no_collide = 1;
        }
        switch (piece->bone) {
            case 3:
                if (options & 0x20) {
                    piece->active = 1;
                } else {
                    piece->active = 0;
                }
                break;
            default:
                piece->active = 1;
        }
    }
    *(f32 *) (head + 0x5C) = 1e10f;
    func_800EFD24(actor->rotation);
    func_80100094(actor, 1);
}

// Creates pieces from the skeleton's rest pose, one per bone.
void func_80800D7C_chexploder(actor, source, center, options) Actor *actor;
s32 source;
f32 *center;
s32 options;
{
    u8 *head;
    s32 skeleton;
    s32 i;
    u8 *piece;
    f32 angles[3];
    f32 world_pos[3];

    head = func_80100094(actor, 0);
    skeleton = func_800B27E0(func_801039E4(actor->unk0));
    *(s16 *) (head + 0xE) = _dbskeleton_entrypoint_0(skeleton);
    piece = func_80100074(actor, 1, *(s16 *) (head + 0xE) * 60);
    for (i = 0; i < *(s16 *) (head + 0xE); i++, piece += 60) {
        piece[0x39] = _dbskeleton_entrypoint_4(skeleton, i);
        _dbskeleton_entrypoint_2(skeleton, piece[0x39], piece + 0xC);
        func_800EFD24(piece);
        func_800EE780(world_pos, piece + 0xC, actor->position);
        func_800F18FC(center, world_pos, angles);
        func_800EEBF0((f32 *) (piece + 0x18), angles, 1000.0f);
        *(f32 *) (piece + 0x24) = 0.0f;
        *(f32 *) (piece + 0x28) = actor->rotation[1];
        *(f32 *) (piece + 0x2C) = 0.0f;
        if (options & 0x10) {
            ((Exp36 *) piece)->no_collide = 1;
        }
        switch (piece[0x39]) {
            case 3:
                if (options & 0x20) {
                    ((Exp36 *) piece)->active = 1;
                } else {
                    ((Exp36 *) piece)->active = 0;
                }
                break;
            default:
                ((Exp36 *) piece)->active = 1;
        }
    }
    *(f32 *) (head + 0x5C) = 1e10f;
    func_800EFD24(actor->rotation);
}

// Gives each active piece a random speed, spin and gravity.
void func_80800F74_chexploder(Actor *actor, s32 source)
{
    s16 *cfg;
    u8 *piece;
    s32 i;
    f32 speed;
    f32 gravity;
    f32 spin_x;
    f32 spin_z;

    cfg = func_80100094(actor, 0);
    piece = (u8 *) func_80100094(actor, 1);
    for (i = 0; i < cfg[7]; i++, piece += 0x3C) {
        if ((*(u32 *) (piece + 0x34) << 17) >> 31) {
            speed = func_800DC178(cfg[0], cfg[1]);
            gravity = func_800DC178(cfg[4], cfg[5]);
            spin_x = func_800DC178(cfg[2], cfg[3]);
            spin_z = func_800DC178(cfg[2], cfg[3]);
            func_800EF368((f32 *) (piece + 0x18), speed);
            func_800EF368((f32 *) (piece + 0x18), speed);
            *(s16 *) (piece + 0x34) = (s16) gravity;
            *(s16 *) (piece + 0x30) = (s16) spin_x;
            *(s16 *) (piece + 0x32) = (s16) spin_z;
        }
    }
}

// Option bits: 1 rumble, 2 camera shake, 8 delete source, 0x40 clear flag.
void func_808010E0_chexploder(void *actor, s32 source, u32 options)
{
    if (options & 2) {
        func_800E1610(0, 0x41F00000, 0x3F666666, (int) actor + 4);
    }
    if (options & 1) {
        func_80018820(0, 0x40400000, 0x3E800000);
    }
    if ((source != 0) && (options & 8)) {
        func_800FFAB0(source);
    }
    if (options & 0x40) {
        *(u8 *) ((char *) actor + 0x65) = (u8) (*((char *) actor + 0x65) & 0xFFFE);
    }
}

void func_80801188_chexploder(actor, model_id, source) ExplS *actor;
s32 model_id;
S16Pair source;
{

if (func_800B26F0(model_id)) {
    actor->f70 = 1;
    actor->f71 = 0;
}

}

void chexploder_entrypoint_1(s32 marker, f32 x, f32 y, f32 z, s32 options)
{
    s32 unk_0;
    u8 *source;
    u8 *head;
    u8 *actor;

    source = func_80106790();
    actor = func_801084B0(0x1FF, &source);
    head = func_80100094(actor, 0);
    (*(f32 *) ((s8 *) (actor) + (0x18))) = x;
    (*(f32 *) ((s8 *) (actor) + (0x1C))) = y;
    (*(f32 *) ((s8 *) (actor) + (0x20))) = z;
    func_800EE7F8(actor + 0x44, source + 0x44);
    (*(f32 *) ((s8 *) (actor) + (0x38))) = (f32) (*(f32 *) ((s8 *) (source) + (0x38)));

if (*(s16 *) ((s8 *) *(u8 **) ((s8 *) actor + 0) + 0x10) == 0) {
    *(s16 *) ((s8 *) *(u8 **) ((s8 *) actor + 0) + 0x10) = func_800AE020();
}

(*(u16 *) ((s8 *) (head) +
           (0x14))) = (u16) (*(u16 *) ((s8 *) ((*(u8 **) ((s8 *) (source) + (0)))) + (0x14)));
(*(u16 *) ((s8 *) (head) +
           (0x16))) = (u16) (*(u16 *) ((s8 *) ((*(u8 **) ((s8 *) (source) + (0)))) + (0x16)));
(*(s16 *) ((s8 *) (head) + (0x54))) = (s16) options;
(*(u8 *) ((s8 *) (source) + (0x65))) = (u8) ((*(u8 *) ((s8 *) (source) + (0x65))) & 0xFFFE);
func_80108944(actor, source);
func_80801188_chexploder(actor, func_801039E4((*(u8 **) ((s8 *) (source) + (0)))), source);
(*(u8 *) ((s8 *) (actor) + (0x74))) = (u8) ((*(u8 *) ((s8 *) (actor) + (0x74))) & 0xFFFD);
func_80103140(actor, (*(u16 *) ((s8 *) (head) + (0x14))),
              (*(u16 *) ((s8 *) (head) + (0x16))));
func_80800A18_chexploder(actor);

if (func_80104248(source) != 0) {
    func_80800AC8_chexploder(actor, source, actor + 0x18, options);
} else {

func_80800D7C_chexploder(actor, source, actor + 0x18, options);
}
func_80101074((*(u8 **) ((s8 *) (actor) + (0))));
func_8010108C(source, 0x90, (*(u16 *) ((s8 *) (head) + (0x14))));
func_80800F74_chexploder(actor, source);
func_808010E0_chexploder(actor, source, options);
}

void chexploder_entrypoint_2(Unk80132ED0 *marker, ExploderSpawn args)
{
    f32 pos[3];
    Actor *actor;
    Actor *source;
    ExploderSpawn *spawn;
    f32 yaw;
    s32 id;
    f32 scale;
    ExploderLocal *head;

    source = (Actor *) marker;
    spawn = &args;
    id = spawn->id;
    yaw = spawn->yaw;
    pos[0] = spawn->x;
    pos[1] = spawn->y;
    pos[2] = spawn->z;
    scale = spawn->scale;
    actor = func_80108474(0x1FF, pos, yaw);
    // Matching: empty test forces marker to be stored to its home slot.
    if (&marker) {
    }
    head = func_80100094(actor, 0);
    if (source) {
        source = func_80106790((Unk80132ED0 *) source);
    } else {
        source = NULL;
    }
    actor->scale = scale;
    func_800EE7F8((f32 *) actor->actorData, actor->position);
    if (source) {
        func_80101074(actor->unk0);

if (func_8010108C(source, 0x8D, id) > 0) {
    func_80101038((f32 *) actor->actorData);
}

}
head->unk_14 = id;
head->unk_16 = 0;
head->options = args.flags;
if (source) {
    func_80108944(actor, source);
    ((ActorFlags74b *) ((u8 *) actor + 0x74))->unk74_25 = 0;
}
func_80103140(actor, head->unk_14, head->unk_16);
func_80801188_chexploder(actor, func_801039E4(actor->unk0), source);
func_80800A18_chexploder(actor);
if (source && (args.flags & 0x80) && func_80104248(source)) {
    func_80800AC8_chexploder(actor, source, (f32 *) actor->actorData, args.flags);
} else {
    func_80800D7C_chexploder(actor, NULL, (f32 *) actor->actorData, args.flags);
}
if (source) {
    func_80101074(actor->unk0);
    func_8010108C(source, 0x90, head->unk_14);
}
func_80800F74_chexploder(actor, source);
func_808010E0_chexploder(actor, source, args.flags);
}

void chexploder_entrypoint_3(s32 *source, s32 position, s32 options)
{
    s32 pos[3];

    if (position != 0) {
        func_800EE7F8(pos);
    } else {
        func_80103DFC(source, pos);
    }
    if (options & 4) {
        func_8010A570(source);
    }
    _chbaddiesetup_entrypoint_5(&_chexploder_entrypoint_1, *source, pos[0], pos[1], pos[2],
                                options);
}

void chexploder_entrypoint_4(s32 source, s32 param_1, s32 options)
{
    f32 pos[3];

    func_800EE88C(pos, param_1);
    chexploder_entrypoint_3(source, pos, options);
}

void chexploder_entrypoint_5(s32 *source, s32 id, f32 *pos, s32 yaw, s32 scale,
                             s32 options)
{
    s16 id_x[2];
    s16 y_z[2];
    s32 marker[1];

    marker[0] = (source != NULL) ? *source : 0;
    id_x[0] = id;
    id_x[1] = pos[0];
    y_z[0] = pos[1];
    y_z[1] = pos[2];
    if (options & 4) {
        func_8010A570();
    }
    _chbaddiesetup_entrypoint_6(&_chexploder_entrypoint_2, marker[0], *(s32 *) id_x, *(s32 *) y_z,
                                yaw, scale, options);
}

int chexploder_entrypoint_6(f32 actor[3], f32 speed_min, f32 speed_max)
{
    s16 *cfg;
    cfg = func_80100094(actor, 0);
    cfg[0] = speed_min;
    cfg[1] = speed_max;
}

void chexploder_entrypoint_7(s32 actor, f32 gravity_min, f32 gravity_max)
{
    void *head;
    head = func_80100094(actor, 0);
    *(s16 *) ((char *) head + 8) = (s16) gravity_min;
    *(s16 *) ((char *) head + 10) = (s16) gravity_max;
}

int chexploder_entrypoint_8(f32 actor[3], f32 spin_min, f32 spin_max)
{
    s16 *cfg;
    cfg = func_80100094(actor, 0);
    *(s16 *) ((s8 *) cfg + 4) = (s16) (s32) spin_min;
    cfg[3] = spin_max;
}

void chexploder_entrypoint_9(actor, idx, value) s32 actor;
s32 idx;
s32 value;
{
    u8 *head = func_80100094(actor, 0);
    head[idx + 0x18] = value;
    if (head[0x18] < idx) {
        head[0x18] = idx;
    }
}

void chexploder_entrypoint_10(Actor *actor, s16 *ids)
{
    ExploderPartCount1332 *head;
    ExploderSelectablePart1332 *piece;
    s32 i;
    s32 j;
    s32 found;

    head = func_80100094(actor, 0);
    piece = func_80100094(actor, 1);
    for (i = 0; i < head->count; i++) {
        found = 0;
        for (j = 0; ids[j] != -1; j++) {

if (piece->bone == ids[j]) {
    found = 1;
    break;
}

}
piece->active = found;
piece++;
}
}

void chexploder_entrypoint_11(Actor *actor, s16 *ids)
{
    ExploderCount *head;
    ExploderPiece *piece;
    s32 i;
    s16 *entry;

    head = func_80100094(actor, 0);
    piece = func_80100094(actor, 1);
    for (i = 0; i < head->count; i++, piece++) {
        if (*ids != -1) {
            entry = ids;
            do {
                if (piece->bone == *entry) {
                    piece->active = 0;
                    break;
                }
                entry++;
            } while (*entry != -1);
        }
    }
}

int chexploder_entrypoint_12(s32 actor, s32 radius)
{
    Actor *head;
    head = func_80100094(actor, 0);
    *(s16 *) ((char *) (head) + 0xC) = radius * (*(f32 *) ((char *) (actor) + 0x38));
}

void chexploder_entrypoint_13(s32 actor, s32 sound)
{
    s8 *head;
    head = func_80100094(actor, 0);
    head[0x12] = (s8) sound;
}

s32 chexploder_entrypoint_14(s32 actor, s32 max_bounces)
{
    *(s16 *) ((char *) func_80100094(actor, 0) + 0x10) = max_bounces;
}

void chexploder_entrypoint_15(Actor *actor, s32 dust_kind, f32 dust_scale)
{
    u8 *head;

    head = func_80100094(actor, 0);
    *(s8 *) (head + 0x13) = dust_kind;
    *(f32 *) (head + 0x58) = dust_scale;
}

void chexploder_entrypoint_16(Actor *actor, s32 value)
{
    ExploderAnimation1246 *anim;

    anim = func_80100094(actor, 0);
    anim->unk_14 = value;
    func_80103140(actor, anim->unk_14, anim->unk_16);
}

// TU-NOTE: The overlay's .data is defined in C here. The tables point at functions of this
// file, and IDO's assembler schedules some of them differently unless the tables are in the
// same unit. D_80801BA0_chexploder is declared as s32[] to match the object.
extern void func_80102EC0();
extern void func_80107C2C();
void *D_80801AE0_chexploder = (void *) 0x015801FF;
static u32 D_80801AE0_chexploder_rest[17] = {0xFFFF0001,
                                             0x0,
                                             (u32) func_80800014_chexploder,
                                             (u32) func_80102EC0,
                                             (u32) func_801018A4,
                                             0x752F,
                                             0x0,
                                             0x0,
                                             0x420,
                                             (u32) func_80800078_chexploder,
                                             0x0,
                                             0x600000,
                                             (u32) func_8080000C_chexploder,
                                             (u32) func_80107C2C,
                                             0x80802402,
                                             (u32) func_808000C0_chexploder,
                                             0x0};
ExpE D_80801B28_chexploder[12] = {
    0x4A0,  0x61A8, 0x100,  0x100,  0x6,    0x415,  0x61A8, 0x100,  0x100, 0x6,    0x416,  0x61A8,
    0x100,  0x100,  0x6,    0x417,  0x61A8, 0x100,  0x100,  0x6,    0x629, 0x4650, 0xB3,   0xB3,
    0x6,    0x417,  0x4650, 0x100,  0x100,  0x19,   0x5C1,  0x4650, 0x100, 0x100,  0x6,    0x5C1,
    0x2EE0, 0x100,  0x100,  0x19,   0x459,  0x61A8, 0x100,  0x100,  0x19,  0x698,  0x61A8, 0xF3,
    0x10C,  0x0,    0x514,  0x6D60, 0xB3,   0xB3,   0x0,    0x0,    0x0,   0x0,    0x0,    0x0};
s32 D_80801BA0_chexploder[4] = {0x210001, 0x4E209C4, 0x1D001E, 0x0};
u8 D_80801BB0_chexploder[40] = {0x0, 0x1D, 0x9, 0xDD, 0x0, 0x16, 0x2, 0x0,  0x0, 0xE,
                                0x0, 0xA,  0x0, 0x14, 0x0, 0x22, 0x0, 0xF3, 0x1, 0xC,
                                0x0, 0x73, 0x0, 0x8C, 0x0, 0x15, 0x0, 0x19, 0x0, 0xB3,
                                0x0, 0x2B, 0x0, 0x80, 0x0, 0x99, 0x0, 0x0,  0x0, 0x0};
u8 D_80801BD8_chexploder[12] = {0x0, 0x1F, 0xDE, 0xA7, 0x71, 0x0, 0x1, 0x1A, 0x0, 0x0, 0x0, 0x0};
u8 D_80801BE4_chexploder[12] = {0x0, 0x20, 0xC0, 0xC0, 0xC0, 0xC0, 0x1, 0x1A, 0x0, 0x0, 0x0, 0x0};
u8 D_80801BF0_chexploder[16] = {0x0, 0x20, 0x40, 0xFF, 0x40, 0xC0, 0x1, 0x1A,
                                0x0, 0x15, 0x0,  0x19, 0x0,  0x80, 0x0, 0x0};
u8 D_80801C00_chexploder[16] = {0x0, 0x20, 0x40, 0x40, 0x40, 0xC0, 0x1, 0x1A,
                                0x0, 0x0,  0x0,  0x0,  0x0,  0x0,  0x0, 0x0};
