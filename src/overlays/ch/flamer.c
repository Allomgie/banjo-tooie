// The 'on fire' effect attached to actors hit by fire: a flamer actor (0x3A2) linked to the victim
// fills its volume with flame sprites, adds a flickering light and a burning sound loop.
#include "common.h"

// TU-NOTE: The .data of this overlay is defined at the bottom of this file. Its tables point to
// functions of this file, and IDO's assembler schedules some of them differently unless the tables
// are in the same unit. Values are taken from the ROM. The extern declarations are adjusted to the
// object (same addresses): D_80800B20_chflamer is int[], D_80800B68_chflamer is s32[].
extern int D_80800B20_chflamer[];
extern s32 func_800BF8E4(void);
typedef struct {
    u8 pad_0[0x72];
    u16 st : 6;
    u16 rest : 10;
} FlamerState;
typedef struct {
    f32 age;
    s16 vel_y;
    s16 unk_6;
    s16 pos_x;
    s16 pos_y;
    s16 pos_z;
    s16 unk_E;
    u32 unk_10;
} FlamerEnt;
typedef struct {
    s32 light;
    u8 pad_4[0x12];
    s16 count;
    s16 timer;
    s16 pad_1A;
    FlamerEnt ent[1];
} FlamerRec;
extern f32 func_80103F38(void *, s32);
extern f32 func_800D8FF8(void);
extern f32 func_800EFC7C(f32 *, f32 *);
extern void func_800EF368(f32 *, f32);
extern s32 _chlightfader_entrypoint_1(s32, f32, s32);
typedef union {
    s32 word;
    void *pointer;
} FlamerEvent;
extern void *func_80100094(Actor *, u32);
typedef struct {
    u8 pad_0[0x74];
    u32 pad_1 : 7;
    u32 has_flamer : 1;
    u32 pad_2 : 24;
} FlamerActorFlags;
extern void _chflamer_entrypoint_2(void);
extern Actor *func_80106790(Unk80132ED0 *);
extern Actor *func_801084B0(s32, Actor **);
extern f32 func_800DC178(f32, f32);
extern void _subaddielink_entrypoint_0();
typedef struct {
    u8 pad_0[0x16];
    s16 current;
    s16 target;
    u8 pad_1[0x192];
    s32 volume;
} FlamerVolume29;
extern s32 _subaddievolume_entrypoint_0(void *, f32 (*)[3], s32, s32, s32 *);
extern s32 D_80800B68_chflamer[];
extern f32 func_800F10B4(f32, f32, f32, f32, f32);
extern void func_800EFA4C(f32 *, f32, f32, f32);
extern void func_800EE88C();
extern void func_800EF04C(f32 *, f32 *);
typedef struct {
    f32 frame;
    s16 unk_4;
    s16 unk_6;
    s16 pos[3];
    s16 unk_E;
    f32 scale;
} FlamerPart37;
typedef struct {
    f32 frame;
    s16 vel_y;
    s16 unk_6;
    f32 pos[2];
    f32 scale;
} FlamerParticle;
typedef struct {
    u8 pad_0[0x16];
    s16 count;
    s16 max_count;
    u16 pad_1;
    FlamerParticle items[1];
} FlamerParticles;
extern s32 func_800DC298(f32);
extern u8 D_80800B7C_chflamer[];
extern s32 func_800E3E8C(f32 *, f32);
extern void func_800F2F60(s32 *, void *, f32);
extern void func_800EE7F8(f32 *, f32 *);
extern void func_800C8E54(s32, f32, f32);
void func_80800738_chflamer();
s32 func_808007A8_chflamer();
void func_8080098C_chflamer();
void func_808008C0_chflamer();
void func_808009C0_chflamer();
extern void func_80105834(), func_80107C2C(), func_8080000C_chflamer(), func_80800434_chflamer();

int chflamer_entrypoint_0()
{
    return &D_80800B20_chflamer;
}

void func_8080000C_chflamer(actor) s32 actor;
{
    u8 *data = func_80100094(actor, 0);
    *(s16 *) (data + 0x16) = 0;
    *(s16 *) (data + 0x18) = 0;
    *(s32 *) (data + 0x1AC) = 0;

    if (func_800BF8E4() > 0) {
        *(s16 *) (data + 4) = 400;
    }
}

void func_80800050_chflamer(Actor *actor)
{
    FlamerRec *flamer;
    u8 *victim;
    s32 i;
    f32 dt;
    f32 push;
    f32 accel;
    FlamerEnt *ent;
    f32 world_pos[3];
    f32 offset[3];

    flamer = func_80100094(actor, 0);
    victim = _subaddielink_entrypoint_4((u8 *) flamer + 0x1B4);

    // Follow the linked victim.
    if (victim != 0 && !func_801072A8(victim)) {
        *(f32 *) ((u8 *) flamer + 0x1B0) = func_80103F38(victim, 0);
        func_800EE7F8(actor->position, (f32 *) (victim + 4));
        func_800EE7F8(actor->rotation, (f32 *) (victim + 0x44));
        actor->scale = *(f32 *) (victim + 0x38);
    }

    func_8080098C_chflamer(actor);

    // Matching: empty block steers IDO's register allocation.
    if (1) {
    }
    switch (((FlamerState *) actor)->st) {
        case 1:
            if (victim == 0 || !(victim[0x74] & 1)) {
                func_80800738_chflamer(actor);
                victim = 0;
            }
            flamer->timer += 2;
            if (flamer->timer >= 0x14) {
                flamer->timer = 0x14;
                actor->unk70_10 = 2;
            }
            break;
        case 2:
            if (func_800D9078(&actor->unk58) || victim == 0 || !(victim[0x74] & 1)) {
                func_80800738_chflamer(actor);
                victim = 0;
            }
            break;
        case 3:
            flamer->timer -= 1;
            if (flamer->timer <= 0) {
                flamer->timer = 0;
                if (flamer->count == 0) {
                    if (func_800BF8E4() > 0) {
                        flamer->light = _chlightfader_entrypoint_1(flamer->light, 1.0f, 2);
                    }
                    func_800FFA88(actor->unk0);
                    return;
                }
            }
    }

    if (func_808007A8_chflamer(actor, victim)) {
        dt = func_800D8FF8();
        ent = flamer->ent;
        push = dt * 50.0f;
        accel = dt * 300.0f;
        for (i = 0; i < flamer->count;) {
            {
                ent->age += dt * 15.0f;
                if ((s32) ent->age >= 9) {
                    flamer->count -= 1;
                    if (flamer->count > 0) {
                        rare_memcpy(ent, &flamer->ent[flamer->count], 0x14);
                    }
                    continue;
                } else {
                    ent->vel_y += accel;
                    ent->pos_y += dt * ent->vel_y;
                    func_800EE88C(world_pos, &ent->pos_x);
                    func_800EF04C(world_pos, actor->position);
                    // Push flames that drift too far away back toward the actor.
                    if (func_800EFC7C(world_pos, actor->position) > 1600.0f) {
                        func_800EFB24(offset, actor->position, world_pos);
                        offset[1] = 0.0f;
                        func_800EF368(offset, push);
                        ent->pos_x += offset[0];
                        ent->pos_z += offset[2];
                    }
                    ent++;
                    i++;
                }
            }
        }
    }

    if (func_800BF8E4() > 0) {
        func_808009C0_chflamer(actor, victim);
    }
}

void func_80800434_chflamer(actor, gfx) Actor *actor;
s32 gfx;
{
    u8 *data = func_80100094(actor, 0);
    s32 sprite = func_800D674C(0x9CE);
    f32 base_scale;
    f32 part_scale;
    FlamerPart37 *part;
    Vec3f pos;
    Vec3f size;
    s32 i;

    func_800E2588(1);
    func_800E2594(gfx, sprite);
    base_scale = func_800F10B4(*(f32 *) (data + 0x1B0), 50.0f, 200.0f, 0.6f, 1.6f) * 0.5f;
    part = (FlamerPart37 *) (data + 0x1C);
    for (i = 0; i < *(s16 *) (data + 0x16); i++, part++) {
        part_scale = part->scale * base_scale;
        func_800EE88C(pos.f, part->pos);
        func_800EF04C(pos.f, actor->position);
        func_800EFA4C(size.f, part_scale, part_scale, part_scale);
        func_800E2720(gfx, (s32) part->frame, part->unk_6, pos.f, size.f,
                      0xC0);
    }
    func_800E2A14(gfx);
}

s32 func_80800594_chflamer(Actor *actor, s32 msg, FlamerEvent payload)
{
    u8 *data;

    switch (msg) {
        case 0x95:
            data = func_80100094(actor, 0);
            _subaddielink_entrypoint_3(data + 0x1B4);

            if (func_800BF8E4() > 0) {
                *(s32 *) data = func_800C8A98();
                data[0x14] = 0;
            }

            break;
        default:
            return 0;
    }
    return 1;
}

void chflamer_entrypoint_1(Actor *victim, void *other)
{
    if (!victim->unk64_17 && !((FlamerActorFlags *) victim)->has_flamer) {
        if (other) {
            if (*(u16 *) ((u8 *) other + 0x18) & 1)
                func_8010114C(other, 0x92, 0);
        }

        ((FlamerActorFlags *) victim)->has_flamer = 1;
        func_8010108C(victim, 0x2B, 1);
        _chbaddiesetup_entrypoint_2(_chflamer_entrypoint_2, victim->unk0, 0);
    }
}

void chflamer_entrypoint_2(Unk80132ED0 *link_target, s32 unk_1)
{
    Actor *victim;
    Actor *flamer;
    u8 *data;
    victim = func_80106790(link_target);
    if (!victim->unk64_17) {
        flamer = func_801084B0(0x3A2, &victim);

        if (flamer) {
            data = func_80100094(flamer, 0);
            _subaddielink_entrypoint_1(data + 0x1B4, link_target);
            flamer->unk58 = func_800DC178(4.0f, 6.0f);
            flamer->unk70_10 = 1;
        }
    }
}

void func_80800738_chflamer(actor) Actor *actor;
{
    u8 *data;
    Actor *victim;

    data = func_80100094(actor, 0);
    victim = (Actor *) _subaddielink_entrypoint_4(data + 0x1B4);
    if (victim != 0) {
        *(u8 *) ((u8 *) victim + 0x74) &= ~1;
        func_8010108C(victim, 0x2B, 0);
    }
    _subaddielink_entrypoint_0(data + 0x1B4);
    *(u8 *) ((u8 *) actor + 0x72) = (*(u8 *) ((u8 *) actor + 0x72) & 0xFF03) | 0xC;
}

s32 func_808007A8_chflamer(actor, victim)
Actor *actor;
void *victim;
{
    f32 points[20][3];
    FlamerVolume29 *data;
    s32 count;
    s32 i;
    s32 batches;
    data = func_80100094(actor, 0);
    batches = 0;
    if (data->current >= data->target)
        return 1;
    while (data->current < data->target) {
        count = _subaddievolume_entrypoint_0(
            victim, points, 2, func_800F1418(20, data->target - data->current),
            &data->volume);
        if (count >= 0)
            batches++;
        if (count <= 0)
            break;
        for (i = 0; i < count; i++)
            func_808008C0_chflamer(actor, points[i]);
    }
    return batches;
}

void func_808008C0_chflamer(actor, pos) Actor *actor;
f32 pos[3];
{
    FlamerParticles *data;
    FlamerParticle *part;

    data = func_80100094(actor, 0);
    if (data->count < data->max_count) {
        part = &data->items[data->count];
        part->frame = 0.0f;
        part->vel_y = func_800DC128(30, 40);
        part->scale = func_800DC178(0.8f, 1.2f);
        part->unk_6 = func_800DC298(0.5f);
        func_800EF3DC(pos, actor->position);
        func_800EE940(part->pos, pos);
        data->count++;
    }
}

void func_8080098C_chflamer(actor) s32 actor;
{
    _subaddieaudioloop_entrypoint_5(actor, actor + 4, 1, -1, &D_80800B68_chflamer);
}

void func_808009C0_chflamer(actor, victim) Actor *actor;
s32 victim;
{
    u8 *data;
    f32 center[3];
    f32 radius;
    // Matching: unused local, needed for the match.
    s32 pad0;
    s32 color[3];
    data = func_80100094(actor, 0);
    if (victim) {
        radius = func_80103F38(victim, center) * 0.75f;
        *(s16 *) (data + 4) = radius;
    } else {
        radius = *(s16 *) (data + 4);
        func_800EE7F8(center, (f32 *) (data + 8));
    }
    if (!data[0x14] || func_800E3E8C(actor->position, 3.0f * radius) ||
        func_800E3E8C((f32 *) (data + 8), 3.0f * radius)) {
        func_800F2F60(color, D_80800B7C_chflamer, func_800DC178(0.8f, 1.0f));
        func_800EE7F8((f32 *) (data + 8), center);
        func_800C8CB8(*(s32 *) data, center);
        func_800C8E84(*(s32 *) data, color);
        func_800C8E54(*(s32 *) data, radius, 3.0f * radius);
    }
    data[0x14] = 1;
}

int D_80800B20_chflamer[18] = {0x30B03A2,
                               -0xFFFF,
                               0x0,
                               (u32) func_80800050_chflamer,
                               (u32) func_80105834,
                               (u32) func_80800434_chflamer,
                               0x0,
                               0x0,
                               0x0,
                               0x20000,
                               0x0,
                               0x0,
                               0x1BC0000,
                               (u32) func_8080000C_chflamer,
                               (u32) func_80107C2C,
                               -0x7FFFFFFE,
                               (u32) func_80800594_chflamer,
                               0x0};
s32 D_80800B68_chflamer[5] = {0x130483, 0x1636B0, 0xE0133, 0x1700180, 0x0};
u8 D_80800B7C_chflamer[20] = {0x0, 0x0,  0x0, 0xE0, 0x0, 0x0, 0x0, 0xE0, 0x0, 0x0,
                              0x0, 0x80, 0x0, 0x0,  0x0, 0x0, 0x0, 0x0,  0x0, 0x0};
