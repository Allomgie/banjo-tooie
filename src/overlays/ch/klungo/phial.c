// Klungo's thrown potion bottle: aimed at the player's predicted position, tumbles, breaks on
// impact with particles and sound. A helper actor 0x423 draws the trail/splash sprites.
#include "common.h"

extern int D_80800C30_chklungophial[];
extern int D_80800C78_chklungophial[];
// Trail/splash sprite record (0x24 bytes) kept by the helper actor 0x423.
typedef struct {
    f32 data[9];
} PhialRecord1826;
typedef struct {
    s32 count;
    PhialRecord1826 entries[1];
} PhialList1826;
extern f32 func_800D8FF8(void);
extern void *func_80100094(Actor *, u32);
extern void func_800E2588();
extern void func_800E2594();
extern void func_800E2A14();
extern void func_800EFA4C(f32 *, f32, f32, f32);
extern void func_800E2530(f32);
extern u32 func_800F54E4(void);
extern void func_8010D12C(u32, f32 *, f32, s32);
extern s32 func_800DC298(f32);
extern void func_800C8E54(s32, f32, f32);
extern f32 func_800DC178(f32, f32);
extern Actor *_subaddiefind_entrypoint_2(s32, s32);
extern Actor *func_80108A30(s32, f32 *, f32, s32);
extern u8 D_80800CC0_chklungophial[];
extern u8 D_80800CCC_chklungophial[];
extern f32 func_800136E4(f32);
extern u8 D_80800CDC_chklungophial[];
extern u8 D_80800D18_chklungophial[];
extern u8 D_80800D28_chklungophial[];
extern u8 D_80800D50_chklungophial[];
extern u8 D_80800D6C_chklungophial[];
extern u8 D_80800D90_chklungophial[];
extern u8 D_80800DCC_chklungophial[];
extern void func_80103DFC(Actor *, f32 *);
extern f32 func_800F1DF4(f32 *, f32 *);
extern void func_800EF1B8(f32 *, f32, f32);
extern void func_800BBCB8(f32 *, f32 *, f32, s32, void *);
extern s32 func_800BABB8(s32, f32 *, f32 *, f32, void *);
extern void func_800EEB9C(f32 *, f32, f32);
extern void func_800EF04C(f32 *, f32 *);
extern s32 _chlightfader_entrypoint_1(s32, f32, s32);
extern f32 mlAbsF(f32);
extern void func_800EF174(f32 *, f32 *, f32);
typedef struct {
    s32 count;
    f32 entries[50][9];
} PhialParticles26;
void func_808003C8_chklungophial();
s32 func_808006B4_chklungophial();
s32 func_80800AEC_chklungophial(Actor *param_0, f32 *param_1, f32 param_2);

int chklungophial_entrypoint_0()
{
    return (int) &D_80800C30_chklungophial;
}

int chklungophial_entrypoint_1()
{
    return (int) &D_80800C78_chklungophial;
}

// Throw the phial at the player's predicted position and attach a light.
void func_80800018_chklungophial(Actor *actor)
{
    s32 i;
    f32 target[3];
    u8 *data;
    f32 trail_pos[3];

    data = func_80100094(actor, 0);
    func_8010D12C(func_800F54E4(), target, actor->unk58, 5);
    for (i = 0; i < 3; i++) {
        ((f32 *) ((u8 *) actor + 0x28))[i] =
            (target[i] - actor->position[i]) / ((f32 *) actor->actorData)[3];
    }
    ((f32 *) actor->actorData)[5] += 400.0f * ((f32 *) actor->actorData)[3];
    actor->unk50 = (func_800DC298(0.5f) ? -1.0f : 1.0f) * func_800DC178(250.0f, 350.0f);
    actor->unk54 = (func_800DC298(0.5f) ? -1.0f : 1.0f) * func_800DC178(150.0f, 250.0f);
    func_800EE7F8((f32 *) data, actor->position);
    *(f32 *) (data + 0x10) = 0.15f;
    *(s32 *) (data + 0xC) = func_800C8A98();
    func_800C8E84(*(s32 *) (data + 0xC), D_80800CC0_chklungophial);
    func_800C8E54(*(s32 *) (data + 0xC), 250.0f, 600.0f);
    func_800C8CB8(*(s32 *) (data + 0xC), actor->position);
    // Spawn the trail actor if none exists yet.
    if (!_subaddiefind_entrypoint_2(0x423, 0)) {
        func_800EFD24(trail_pos);
        func_80108A30(0x423, trail_pos, 0.0f, 0x32);
    }
}

void func_80800204_chklungophial(Actor *actor)
{
    u8 *data;
    f32 dt;
    Actor *trail;
    f32 bone_pos[3];
    data = func_80100094(actor, 0);
    if (func_800D9078(data + 0x10))
        _subaddieaudioquick_entrypoint_2(actor, actor->position, D_80800CCC_chklungophial);
    if (actor->unk70_10 == 1) {
        dt = func_800D8FF8();
        trail = (Actor *) _subaddiefind_entrypoint_2(0x423, 0);
        actor->rotation[1] =
            func_800136E4(dt * *(f32 *) ((u8 *) actor + 0x50) + actor->rotation[1]);
        actor->rotation[0] =
            func_800136E4(dt * *(f32 *) ((u8 *) actor + 0x54) + actor->rotation[0]);
        *(f32 *) ((u8 *) actor + 0x2C) -= 800.0f * dt;
        if (func_8010B990(actor, 0x400007) & 0x20)
            func_808003C8_chklungophial(actor, 1);
        if (func_800DC298(0.6f) && trail) {
            _subaddieskeleton_entrypoint_3(actor->unk0, 4, bone_pos);
            func_80800AEC_chklungophial(trail, bone_pos, 0.0f);
        }
    }
    // Out of map bounds: delete the stray phial and its light.
    if (!func_800BFA1C(actor->position)) {
        func_800FFAB0(actor);
        if (*(s32 *) (data + 12)) {
            func_800C8B84(*(s32 *) (data + 12));
            *(s32 *) (data + 12) = 0;
        }
    }
    if (*(s32 *) (data + 12))
        func_800C8CB8(*(s32 *) (data + 12), actor->position);
}

int func_8080038C_chklungophial(s32 actor, s32 msg, s32 unused)
{
    if (msg == 0x40) {
        func_808003C8_chklungophial(actor, 0);
    } else {
        return 0;
    }
    return 1;
}

// Break the phial: particles, sounds, light fade, then remove it.
// impact == 1: hit by locomotion (splash and trail sprites); otherwise a small puff.
void func_808003C8_chklungophial(actor, impact) Actor *actor;
s32 impact;
{
    Vec3f pos;
    Vec3f unk_0;
    Actor *trail;
    s32 *data;
    Vec3f rot;
    s32 particle;
    s32 i;
    f32 delay;
    f32 angle;
    Vec3f splash_pos;
    f32 radius;
    f32 delay_step;

    data = func_80100094(actor, 0);
    func_80103DFC(actor, pos.f);
    func_800EE7F8(unk_0.f, pos.f);
    func_800EF1B8(unk_0.f, func_800F1DF4(actor->position, (f32 *) data),
                  actor->scale * 60.0f);
    unk_0.pos.y -= actor->scale * 40.0f;
    func_800BBCB8(pos.f, unk_0.f, actor->scale, 10, D_80800CDC_chklungophial);
    _subaddieaudioquick_entrypoint_2(actor, pos.f, D_80800D18_chklungophial);
    _subaddieaudioquick_entrypoint_2(actor, pos.f, D_80800D50_chklungophial);
    if (impact == 1) {
        trail = _subaddiefind_entrypoint_2(0x423, 0);
        if (func_808006B4_chklungophial(actor, pos.f, rot.f)) {
            particle =
                func_800BABB8(0, pos.f, NULL, actor->scale * 0.25f, D_80800D6C_chklungophial);
            func_800BA77C(particle, (s16) rot.pos.x, (s16) rot.pos.y, (s16) rot.pos.z);
            func_800BA22C(particle, 1);
        }
        func_800BABB8(0, pos.f, NULL, actor->scale, D_80800D90_chklungophial);
        _subaddieaudioquick_entrypoint_2(actor, pos.f, D_80800DCC_chklungophial);
        if (trail != NULL) {
            delay = 0.35f;
            for (i = 0; i < 6; i++) {
                angle = func_800DC178(0.0f, 359.0f);
                radius = func_800DC178(5.0f, 80.0f);
                func_800EEB9C(splash_pos.f, angle, radius);
                func_800EF04C(splash_pos.f, pos.f);
                func_80800AEC_chklungophial(trail, splash_pos.f, delay);
                delay_step = func_800DC178(0.1f, 0.2f);
                delay += delay_step;
            }
        }
    } else {
        func_800BBCB8(pos.f, pos.f, 1.0f, 2, D_80800D28_chklungophial);
    }
    if (data[3] != 0) {
        data[3] = _chlightfader_entrypoint_1(data[3], 1.5f, 2);
    }
    func_800FFAB0(actor);
    func_8010A570(actor);
}

// Trace from behind to ahead of the phial; on a hit fill out_pos and out_rot.
s32 func_808006B4_chklungophial(actor, out_pos, out_rot)
Actor *actor;
f32 *out_pos;
f32 *out_rot;
{
    f32 from[3];
    f32 to[3];
    f32 normal[3];
    f32 step;
    f32 *pos;
    pos = actor->position;
    func_800EE7F8(from, pos);
    step = func_800D8FF8() * -6.0f;
    func_800EF174(from, (f32 *) ((u8 *) actor + 0x28), step);
    func_800EE7F8(to, pos);
    step = func_800D8FF8() * 3.0f;
    func_800EF174(to, (f32 *) ((u8 *) actor + 0x28), step);
    if (func_800C6A7C(from, to, normal, *(s32 *) ((u8 *) actor + 0x14))) {
        if (func_800F1988(normal, out_rot, out_rot + 1)) {
            out_rot[2] = 0.0f;
            func_800EE7F8(out_pos, to);
            return 1;
        }
        if (mlAbsF(normal[0]) < 0.0001f && mlAbsF(normal[2]) < 0.0001f &&
            mlAbsF(normal[1]) > 0.9999f) {
            func_800EFD24(out_rot);
            func_800EE7F8(out_pos, to);
            return 1;
        }
    }
    return 0;
}

void func_80800820_chklungophial(s32 unused)
{
}

// Trail actor: ages the sprite records and removes finished ones.
void func_80800828_chklungophial(Actor *actor)
{
    s32 count;
    f32 dt = func_800D8FF8();
    PhialList1826 *list = (PhialList1826 *) func_80100094(actor, 0);
    PhialRecord1826 *entry = list->entries;
    s32 i = 0;

    while (i < list->count) {
        if (func_800D90A4(&entry->data[5])) {
            if (func_800D90A4(&entry->data[3]))
                entry->data[4] += dt * 15.0f;
            if (entry->data[4] > 11.0f) {
                // Remove by copying the last record over this one.
                rare_memcpy(entry, &list->entries[list->count - 1], 0x24);
                list->count--;
                continue;
            }
            entry->data[1] += dt * entry->data[7];
        }
        entry++;
        i++;
    }
    if (actor->unk70_10 == 2) {
        count = list->count;
        switch (count) {
            case 0:
                func_800FFAB0(actor);
        }
    }
}

s32 func_80800980_chklungophial(Actor *actor, s32 msg, s32 unused)
{
    Actor *actor_copy;
    if (msg == 0x4f) {
        // Matching: extra temporary needed for the match.
        actor_copy = actor;
        func_80101FDC(actor_copy, 2);
    } else {
        return 0;
    }
    return 1;
}

void func_808009BC_chklungophial(Actor *actor, s32 gfx)
{
    s32 *data;
    s32 i;
    u8 *entry;
    s32 sprite;
    f32 scale[3];
    s32 unk_0;

    data = func_80100094(actor, 0);
    entry = (u8 *) data + 4;
    actor->unk7C_12 = 1;
    if (*data) {
        sprite = func_800D674C(0x9CF);
        func_800E2588(1);
        func_800E2594(gfx, sprite);
        func_800E24D8(1);
        for (i = 0; i < *data; i++, entry += 0x24) {
            if (*(f32 *) (entry + 0x14) == 0.0f) {
                func_800EFA4C(scale, *(f32 *) (entry + 0x18), *(f32 *) (entry + 0x18),
                              *(f32 *) (entry + 0x18));
                func_800E2530(*(f32 *) (entry + 0x20));
                func_800E2720(gfx, (s32) *(f32 *) (entry + 0x10), 0, entry, scale, 255);
            }
        }
        func_800E2A14(gfx);
    }
}

// Add a sprite record at pos with the given start delay; 0 when the list is full.
s32 func_80800AEC_chklungophial(Actor *actor, f32 *pos, f32 delay)
{
    f32 *entry;
    PhialParticles26 *list;

    list = func_80100094(actor, 0);
    if (list->count == 50) {
        return 0;
    }
    entry = list->entries[list->count];
    bzero(entry, 0x24);
    func_800EE7F8(entry, pos);
    entry[3] = func_800DC178(0.55f, 1.25f);
    entry[4] = 0.0f;
    entry[5] = delay;
    entry[6] = func_800DC178(0.85f, 1.15f);
    entry[7] = func_800DC178(40.0f, 80.0f);
    entry[8] = func_800DC178(0.0f, 359.0f);
    list->count++;
    return 1;
}

extern void func_80105834();
extern void func_80101870();
extern void func_80108ED0();
extern void func_80107C2C();
int D_80800C30_chklungophial[18] = {0x3320422,
                                    0x7080001,
                                    0x0,
                                    (u32) func_80800204_chklungophial,
                                    (u32) func_80105834,
                                    (u32) func_80101870,
                                    0x0,
                                    0x3F800000,
                                    0x0,
                                    0x44,
                                    0x0,
                                    (u32) func_80108ED0,
                                    0x140000,
                                    (u32) func_80800018_chklungophial,
                                    (u32) func_80107C2C,
                                    0x0,
                                    (u32) func_8080038C_chklungophial,
                                    0x0};
int D_80800C78_chklungophial[18] = {0x3330423,
                                    -0xFFFF,
                                    0x0,
                                    (u32) func_80800828_chklungophial,
                                    (u32) func_80105834,
                                    (u32) func_808009BC_chklungophial,
                                    0x0,
                                    0x0,
                                    0x0,
                                    0x20404,
                                    0x0,
                                    0x0,
                                    0x70C0000,
                                    (u32) func_80800820_chklungophial,
                                    (u32) func_80107C2C,
                                    -0x7FFFDFFE,
                                    (u32) func_80800980_chklungophial,
                                    0x0};
u8 D_80800CC0_chklungophial[12] = {0x0, 0x0, 0x0, 0xFF, 0x0, 0x0, 0x0, 0xFF, 0x0, 0x0, 0x0, 0x80};
u8 D_80800CCC_chklungophial[16] = {0x0, 0x13, 0x6, 0x1, 0x0, 0xD, 0x0, 0xF3,
                                   0x1, 0xC,  0x0, 0x2, 0x0, 0x0, 0x0, 0x0};
u8 D_80800CDC_chklungophial[60] = {
    0x0,  0x1D, 0x7,  0xB0, 0x0,  0x16, 0x5,  0x86, 0x0,  0x2B, 0x1,  0x33, 0x1,  0x99, 0x0,
    0x27, 0x0,  0xC8, 0x0,  0xC8, 0x1,  0x90, 0x1,  0x90, 0x0,  0x2D, 0x1,  0xF4, 0x2,  0x58,
    0x0,  0x1B, 0xFC, 0x18, 0xFC, 0xE0, 0x0,  0x22, 0x1,  0x0,  0x1,  0x33, 0x0,  0x80, 0x0,
    0x99, 0x0,  0x15, 0x0,  0x0,  0x0,  0xCC, 0x0,  0xE,  0x0,  0x1E, 0x0,  0x32, 0x0,  0x0};
u8 D_80800D18_chklungophial[16] = {0x0, 0x13, 0x4, 0x8D, 0x0, 0x18, 0x0, 0xD,
                                   0x1, 0x59, 0x1, 0x73, 0x0, 0x0,  0x0, 0x0};
u8 D_80800D28_chklungophial[40] = {0x0, 0x1D, 0x9, 0xDD, 0x0,  0x22, 0x1,  0x80, 0x2, 0x0,
                                   0x2, 0x0,  0x2, 0x80, 0x0,  0x15, 0x0,  0x0,  0x0, 0x99,
                                   0x0, 0x19, 0x0, 0x0,  0x0,  0x7,  0x0,  0x2B, 0x1, 0x33,
                                   0x1, 0x66, 0x0, 0x20, 0xFF, 0xFF, 0x40, 0xE0, 0x0, 0x0};
u8 D_80800D50_chklungophial[28] = {0x0, 0x13, 0x4, 0xDC, 0x0, 0xD,  0x1, 0x0,  0x1, 0x19,
                                   0x0, 0x15, 0x0, 0x26, 0x0, 0x80, 0x0, 0x66, 0x0, 0x1,
                                   0x3, 0x20, 0xD, 0xAC, 0x0, 0x0,  0x0, 0x0};
u8 D_80800D6C_chklungophial[36] = {0x1, 0x10, 0x0, 0x1D, 0x8, 0x21, 0x0, 0x2B, 0x2, 0x0, 0x2, 0x80,
                                   0x0, 0x22, 0x1, 0x80, 0x2, 0x0,  0x4, 0x80, 0x5, 0x0, 0x0, 0x15,
                                   0x0, 0x0,  0x0, 0x80, 0x0, 0x33, 0x0, 0x3,  0x0, 0x0, 0x0, 0x0};
u8 D_80800D90_chklungophial[60] = {
    0x4,  0x10, 0x0,  0x1D, 0x9, 0xDD, 0x0, 0x1B, 0x0,  0x96, 0x0,  0xAF, 0x0,  0xB,  0x0,
    0x14, 0x0,  0x28, 0x0,  0x0, 0x0,  0x0, 0x0,  0x20, 0xFF, 0xFF, 0xC0, 0x60, 0x0,  0x22,
    0x0,  0x66, 0x0,  0x80, 0x0, 0x99, 0x0, 0xB3, 0x0,  0x15, 0x0,  0x0,  0x0,  0x99, 0x0,
    0x2A, 0x0,  0x0,  0x0,  0xA, 0x1,  0x0, 0x1,  0x80, 0x0,  0xF,  0x0,  0x0,  0x0,  0x0};
u8 D_80800DCC_chklungophial[20] = {0x0, 0x13, 0x4, 0x1F, 0x0, 0x18, 0x0, 0xD, 0x0, 0xA6,
                                   0x0, 0xC0, 0x0, 0x0,  0x0, 0x0,  0x0, 0x0, 0x0, 0x0};
