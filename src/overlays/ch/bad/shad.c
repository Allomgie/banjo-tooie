// Probably the drop-shadow actor ("badshad") for actors and NPCs: follows its owner, finds the
// floor below, aligns to it and draws a shadow model that scales and fades with height.
#include "common.h"

extern int D_80800A10_chbadshad[];
typedef struct {
    u8 pad[0x78];
    u32 pad1 : 16;
    u32 mode : 2;
    u32 pad2 : 14;
} BadShadFlags97;
extern void func_8010A800(Actor *, s32);
extern Actor *func_80106790();
extern s32 func_80102F74(Actor *, u32);
typedef struct {
    u8 pad[0x18];
    s32 f18;
    u8 pad1C[0x48];
    u32 pad64 : 14;
    u32 flag : 1;
    u32 rest : 17;
} BadShadS;
typedef struct {
    u8 pad_0[0x70];
    u32 pad_1 : 12;
    u32 unk_70 : 1;
    u32 pad_2 : 19;
    u8 pad_3[4];
    u32 pad_4 : 28;
    u32 unk_78 : 1;
    u32 pad_5 : 3;
} Mass45ShadowActorFlags;
typedef struct {
    u8 pad0[0x7E];
    u16 f : 1;
    u16 pad : 15;
} SignBf7E_0;
extern Actor *func_801084B0(s32, void *);
extern s32 func_8001211C(void);
extern void _chbaddiesetup_entrypoint_5(s32, s32, f32, s32, s32, s32);
extern s32 _chbadshad_entrypoint_4;
typedef struct {
    u8 pad0[0x7E];
    u16 unk7E_15 : 1;
    u16 pad7E_0 : 15;
} BadShadFlag;
typedef struct {
    u8 pad0[0x7A];
    u16 unk7A_14 : 2;
    u16 pad7A_0 : 14;
    u8 pad7C[2];
    s16 unk7E;
} BadShadActor;
typedef struct {
    u8 pad0[0x1A];
    u16 unk1A_5 : 11;
    u16 pad1A_0 : 5;
} BadShadInfo;
extern f32 func_800F0E00(f32, f32);
extern f32 func_800F10B4(f32, f32, f32, f32, f32);
extern void func_800DF428(f32);
extern s32 func_80101918(f32);
extern s32 func_800DE448(void *, void *, f32, s32, s32);
typedef struct {
    u32 pad : 5;
    u32 flag : 1;
    u32 pad2 : 26;
} BitTest5;
typedef struct {
    u32 pad : 19;
    u32 flag : 1;
    u32 pad2 : 12;
} BitTest19;
u8 *func_80800664_chbadshad(u8 *param_0, f32 *param_1, f32 param_2);
s32 func_8080078C_chbadshad();
void func_8080082C_chbadshad();
int func_8080086C_chbadshad();

int chbadshad_entrypoint_0()
{
    return (int) &D_80800A10_chbadshad;
}

void func_8080000C_chbadshad(Actor *actor)
{
    Actor *owner;

    func_8010A800(actor, 5);
    owner = *(void **) ((u8 *) actor + 0x40) ? func_80106790(*(void **) ((u8 *) actor + 0x40))
                                                 : NULL;
    if (owner) {
        if (func_80102F74(owner, 0x82000000)) {
            ((BadShadFlags97 *) actor)->mode = 3;
        } else {
            ((BadShadFlags97 *) actor)->mode = 2;
        }
    }
}

// Removes the shadow if it was not updated in the last frame.
void func_80800090_chbadshad(BadShadS *actor)
{
    if (!actor->flag && actor->f18 < func_8001211C() - 1) {
        func_8080082C_chbadshad(actor);
    }
}

// Draws the shadow model.
void func_808000E0_chbadshad(Actor *actor, s32 unused)
{
    f32 scale;
    Actor *owner;

    owner = 0;
    if (actor->unk64_17) {
        return;
    }
    scale = actor->scale;
    if (actor->pad40) {
        owner = func_80106790(actor->pad40);
    }
    if (owner) {
        func_800DF410(_subaddiefade_entrypoint_0(owner));
    }
    if (!owner || !((BitTest5 *) ((u8 *) owner + 0x74))->flag) {
        scale *= func_800F10B4(((f32 *) actor->actorData)[3], 0.0f, 800.0f, 0.53f, 0.18f);
    } else {
        scale *= 0.5f;
    }
    func_800DF470(1);
    func_800DF428(4000.0f);
    func_800DF830((u32) *(u16 *) ((u8 *) actor + 0x7A) >> 14);
    if (((u32) *(u16 *) ((u8 *) actor + 0x7A) >> 14) == 3) {
        if (func_800DE448(actor->position, actor->rotation, scale, 0,
                          func_801039E4(actor->unk0))) {
            ((BitTest19 *) ((u8 *) actor + 0x7C))->flag = 1;
        } else {
            ((BitTest19 *) ((u8 *) actor + 0x7C))->flag = 0;
        }
    } else {
        if (func_800DE448(actor->position, actor->rotation, scale, func_80101918(scale),
                          func_801039E4(actor->unk0))) {
            ((BitTest19 *) ((u8 *) actor + 0x7C))->flag = 1;
        } else {
            ((BitTest19 *) ((u8 *) actor + 0x7C))->flag = 0;
        }
    }
}

// Computes the floor height at the target position and aligns the shadow to the floor normal.
f32 func_8080028C_chbadshad(Actor *owner, Actor *shadow, f32 *target_pos)
{
    f32 normal[3];
    f32 height;

    height = 0.0f;
    if (!((Mass45ShadowActorFlags *) owner)->unk_78 && !(shadow->actorData[1] & 0x80008000) &&
        ((SignBf7E_0 *) shadow)->f) {
        if ((s32) shadow->position[0] == (s32) target_pos[0] &&
            (s32) shadow->position[2] == (s32) target_pos[2]) {
            shadow->position[0] = target_pos[0];
            shadow->position[2] = target_pos[2];
            goto done;
        }
    }
    if (((Mass45ShadowActorFlags *) owner)->unk_70) {
        func_800EE7F8(shadow->position, target_pos);
        return 0.0f;
    }
    if (*(s16 *) ((u8 *) owner + 0x8E) && !func_80105494(owner) &&
        func_80104668(owner, target_pos, shadow->position, normal, &height)) {
        shadow->actorData[1] = func_8010518C(owner);
        func_8010279C(shadow, normal);
        if ((shadow->actorData[1] & 0x80000000)) {
            shadow->unk64_16 = 0;
        } else {
            shadow->unk64_16 = 1;
        }
        return height;
    } else if (!func_8080086C_chbadshad(shadow, owner, &height, target_pos)) {
        shadow->unk64_16 = 0;
    } else if ((shadow->actorData[1] & 0x80000000)) {
        shadow->unk64_16 = 0;
    } else {
        shadow->unk64_16 = 1;
    }
done:
    return height;
}

// Places the shadow of an owner at a position.
void chbadshad_entrypoint_1(s32 owner, s32 pos, f32 scale)
{
    u8 *shadow = func_80800664_chbadshad(owner, pos, scale);
    if (shadow != NULL) {
        *(f32 *) (shadow + 0x38) = scale;
    }
}

// Places the shadow at a skeleton bone.
s32 chbadshad_entrypoint_2(Actor *actor, s32 bone, f32 scale, f32 *out_pos)
{
    f32 bone_pos[3];

    if (!out_pos)
        out_pos = bone_pos;
    if (_subaddieskeleton_entrypoint_0(actor, bone, out_pos)) {
        chbadshad_entrypoint_1(actor, out_pos, scale);
        if (actor->pad40) {
            func_800EE7F8(out_pos, func_80106790(actor->pad40)->position);
        }
        return 1;
    }
    return 0;
}

// Places the shadow at a bone while the actor is in one of the listed states, else at a position.
void chbadshad_entrypoint_3(Actor *actor, s32 pos, s32 bone, f32 scale, s16 *states)
{
    while (*states != -1) {
        if (actor->unk70_10 == *states) {
            chbadshad_entrypoint_2(actor, bone, scale, 0);
            return;
        }
        states++;
    }
    chbadshad_entrypoint_1(actor, pos, scale);
}

// Spawns a shadow actor for an owner at a position.
void chbadshad_entrypoint_4(s32 id, s32 scale_in, f32 x, f32 y, f32 z)
{
    f32 pos[3];
    s32 owner_id;
    Actor *owner;
    f32 scale;
    Actor *shadow;

    owner_id = id;
    // Matching: the copy and the empty if on the parameter's address are needed for the match.
    if (&id) {
    }
    owner = func_80106790(owner_id);
    pos[0] = x;
    pos[1] = y;
    pos[2] = z;
    if (!owner->unk64_17) {
        scale = *(f32 *) &scale_in;
        shadow = func_801084B0(0x243, &owner);
        if (shadow) {
            shadow->unk14 = owner->unk14;
            ((f32 *) shadow->actorData)[3] = func_8080028C_chbadshad(owner, shadow, pos);
            if (!shadow->unk64_17) {
                owner->pad40 = (s32) shadow->unk0;
                shadow->scale = scale;
                shadow->pad40 = owner_id;
                shadow->actorData[0] = func_8001211C();
            }
        }
    }
}

// Updates the owner's shadow, creating it when missing.
u8 *func_80800664_chbadshad(u8 *owner, f32 *pos, f32 scale)
{
    u8 *shadow;
    u8 *shadow_id;

    if (((Actor *) owner)->unk64_17) {
        shadow_id = *(u8 **) (owner + 0x40);
        if (shadow_id != 0) {
            func_8080082C_chbadshad(func_80106790(shadow_id));
        }
        return 0;
    }
    shadow_id = *(u8 **) (owner + 0x40);
    if (shadow_id == 0) {
        _chbaddiesetup_entrypoint_5((s32) &_chbadshad_entrypoint_4, *(s32 *) owner, scale,
                                    *(s32 *) pos, ((s32 *) pos)[1], ((s32 *) pos)[2]);
    } else {
        shadow = func_80106790(shadow_id);
        if (((Actor *) shadow)->unk64_17) {
            return 0;
        }
        if (func_8080078C_chbadshad(shadow, owner) != 0) {
            *(f32 *) (shadow + 0x24) = func_8080028C_chbadshad(owner, shadow, pos);
        } else {
            *(f32 *) (shadow + 0x4) = pos[0];
            *(f32 *) (shadow + 0xC) = pos[2];
        }
        *(s32 *) (shadow + 0x18) = func_8001211C();
        *(f32 *) (shadow + 0x38) = scale;
        return shadow;
    }
    return 0;
}

// Whether the shadow updates this frame (every 4th frame per actor).
s32 func_8080078C_chbadshad(shadow, owner)
Actor *shadow;
s32 owner;
{
    if (!((BadShadFlag *) shadow)->unk7E_15) {
        return 1;
    }
    if (func_80104544(owner)) {
        return 1;
    }
    if (func_800DB9B0()) {
        return 1;
    }
    if (((BadShadActor *) shadow)->unk7A_14 == 3) {
        return 1;
    }
    return ((func_8001211C() ^ ((BadShadInfo *) shadow->unk0)->unk1A_5) & 3) == 0;
}

// Unlinks the shadow from its owner and removes it.
void func_8080082C_chbadshad(shadow) u8 *shadow;
{
    // Matching: the extra temporary for the offset is needed for the match.
    int offset;
    s32 owner_id;
    offset = 0x40;
    owner_id = *(s32 *) ((s8 *) shadow + 0x40);
    if (owner_id != 0) {
        *(s32 *) ((s8 *) func_80106790(owner_id, *(s32 *) ((s8 *) shadow + 0x40), shadow) +
                  offset) = 0;
    }
    func_800FFAB0(shadow);
}

// Raycasts the floor below pos; returns 0 if nothing is hit.
int func_8080086C_chbadshad(shadow, owner, out_height, pos)
u8 *shadow;
Actor *owner;
f32 *out_height;
f32 *pos;
{
    f32 ray_start[3];
    f32 ray_end[3];
    f32 normal[3];
    f32 angles[3];
    s32 saved;
    u8 *hit;
    saved = func_8010A654(owner, 0);
    func_800EE7F8(ray_start, pos);
    func_800EE7F8(ray_end, pos);
    ray_start[1] += 80.0f;
    ray_end[1] -= 100.0f;
    hit = (u8 *) func_800C6A7C(ray_start, ray_end, normal, *(s32 *) (shadow + 0x14));
    if (!hit) {
        ray_end[1] = pos[1] - 2000.0f;
        hit = (u8 *) func_800C6A7C(ray_start, ray_end, normal, *(s32 *) (shadow + 0x14));
        if (!hit) {
            *out_height = 0.0f;
            func_8010A654(owner, saved);
            *(s32 *) (shadow + 0x1C) = 0;
            return 0;
        }
    }
    *(s32 *) (shadow + 0x1C) = *(s32 *) (hit + 8);
    func_8010A654(owner, saved);
    func_800EE7F8((f32 *) (shadow + 4), ray_end);
    *out_height = func_800F0E00(0.0f, pos[1] - *(f32 *) (shadow + 8));
    func_800F1988(normal, &angles[0], &angles[1]);
    angles[2] = 0.0f;
    func_8010279C(shadow, angles);
    if (*(s16 *) ((u8 *) owner + 0x8E))
        func_801045AC(owner, normal, (f32 *) (shadow + 4), *(s32 *) (hit + 8));
    return 1;
}

extern void func_80105834();
extern void func_80107C2C();
int D_80800A10_chbadshad[20] = {0x9B0243,
                                0x6370001,
                                0x0,
                                (u32) func_80800090_chbadshad,
                                (u32) func_80105834,
                                (u32) func_808000E0_chbadshad,
                                0x0,
                                0x0,
                                0x0,
                                0x4,
                                0x0,
                                0x0,
                                0x0,
                                (u32) func_8080000C_chbadshad,
                                (u32) func_80107C2C,
                                -0x7FFFFFFE,
                                0x0,
                                0x0,
                                0x0,
                                0x0};
