// Most likely the quicksand/sludge baddie: lurks submerged, grabs the player and spits them out
// toward a landing point (or swallows them at 1 health), then relocates inside its zone.
#include "common.h"

extern f32 func_800C6920(f32[3], f32, f32, s32);
extern f32 func_800EEB40(f32 *, f32 *);
extern f32 func_800DC0C0(void);
extern s32 func_800B53A4(s32);
extern s32 func_800BABB8(s32, f32 *, f32 *, f32, s32 *);
extern s32 D_80801370_chquicksandbaddy[];
extern s32 D_80801390_chquicksandbaddy[];
extern u8 D_80801394_chquicksandbaddy[];
extern u8 _chquicksandbaddy_entrypoint_0[];
extern u8 D_808013D4_chquicksandbaddy[];
extern void *func_80100094(Actor *, u32);
extern int func_800EEF24(f32 *);
extern void func_800EE7F8(f32 *, f32 *);
extern int D_808013D8_chquicksandbaddy[];
extern void *func_80100074(Actor *, s32, s32);
extern f32 func_800DC178(f32, f32);
typedef struct {
    f32 unk_0;
    u16 unk_4;
    u16 unk_6;
} QuicksandAnimation;
typedef struct {
    f32 time;
    f32 unk_4;
} QuicksandSoundEvent;
extern f32 func_800F1DF4(f32 *, f32 *);
extern void func_800C4140(s32, f32 *, s32);
extern void func_800F7C58(s32, s32, s32);
extern f32 func_800F5628(s32);
extern f32 func_80103EAC(Actor *);
extern f32 *func_800CC63C(s32, s32);
extern void func_800EEB9C(f32 *, f32, f32);
extern void func_800EF334(f32 *, f32);
extern void func_800F4F34(s32, f32 *, f32, f32);
extern s32 func_80101E14(Actor *, f32);
extern void func_80101EE4(Actor *, f32);
extern f32 func_80101F24(Actor *);
extern void *func_800C6A7C(f32 *, f32 *, f32 *, u32);
extern s32 func_800CC338(f32 *, s32, s32);
extern s32 func_800D90A4(f32 *);
extern f32 func_800D91B8(f32 *);
extern s32 func_800E3980(s32);
extern void func_800EF04C(f32 *, f32 *);
extern int func_800F6AA4(s32);
extern void func_800F7D90(s32, s32, s32, s32);
extern void func_800FC660(u32);
extern s32 func_80101DDC(void *);
extern void func_80102424(void *, s32);
extern void func_80103014(s32);
extern void func_8010D254(s32);
typedef struct {
    u8 pad_0[0x78];
    u32 p78 : 8;
    u32 attempt : 4;
    u32 rest : 20;
} QS78;
f32 func_80800CC0_chquicksandbaddy();

extern f32 mlAbsF(f32);
int func_808010A0_chquicksandbaddy();
s32 func_80800CFC_chquicksandbaddy();

// Init: stores the positions of up to 3 marker props (0x510) as landing points.
void func_80800000_chquicksandbaddy(Actor *actor)
{
    s32 prop_ids[3];
    s32 count;
    s32 i;
    f32(*spawn_points)[3];

    count = _gccubesearch_entrypoint_9(0x510, prop_ids, 3);
    if (count) {
        spawn_points = func_80100074(actor, 1, 0x24);
        i = 0;
        for (; i < count; i++) {
            _gspropctrl_entrypoint_11(prop_ids[i], spawn_points[i]);
        }
        for (; i < 3; i++) {
            func_800EFD24(spawn_points[i]);
        }
    }
    if (!_subaddieDll_entrypoint_1(actor)) {
        func_800FFA88(actor->unk0);
        return;
    }
    *(f32 *) ((u8 *) actor + 0x34) = actor->position[1];
    actor->unk58 = 0.2f;
    *(f32 *) ((u8 *) actor + 0x24) = 0.0f;
    actor->unk54 = 0.0f;
    actor->unk54 = actor->position[1] - func_80800CC0_chquicksandbaddy(actor);
    *(f32 *) ((u8 *) actor + 0x28) = func_800DC178(20.0f, 30.0f);
    ((u8 *) actor)[0x65] &= ~1;
}

void func_80800FC8_chquicksandbaddy(s32 param_0, f32 param_1, s32 param_2);

void chquicksandbaddy_entrypoint_0();

s32 func_80800DBC_chquicksandbaddy();

// Matching: the line breaks in this function are needed for the match.
void func_80800140_chquicksandbaddy(Actor *actor)
{
    extern u8 D_808012E0_chquicksandbaddy[];
    extern u8 D_808012F0_chquicksandbaddy[];
    extern u8 D_80801300_chquicksandbaddy[];
    extern u8 D_80801310_chquicksandbaddy[];
    extern QuicksandAnimation D_808012A0_chquicksandbaddy[];
    extern QuicksandSoundEvent D_80801320_chquicksandbaddy[];

    switch (actor->unk70_10) {
        case 1: {
            f32 unk_0[3];
            f32 look_pos[3];
            func_8010D254(unk_0);
            if (func_800D90A4((f32 *)actor->actorData + 4)) {
                func_800E3980(look_pos);
                actor->rotation[1] = func_800F1DF4(actor->position, look_pos);
                func_80102424(actor, 6);
            }
            if (func_80800DBC_chquicksandbaddy(actor)) {
                if (func_800F6AA4(func_800F54E4())) {
                    actor->actorData[5] = 1;
                } else {
                    actor->actorData[5] = 0;
                }
                if (func_800F7B9C(func_800F54E4(), 0x34)) {
                    func_800EE7F8(actor->position, unk_0);
                    _subaddieaudioquick_entrypoint_2(actor, actor->position,
                    D_808012E0_chquicksandbaddy);
                    _subaddieDll_entrypoint_4(actor, 1);
                    func_800F5A00(func_800F54E4(), actor->position);
                    actor->position[1] = func_800F5628(func_800F54E4()) + actor->unk54;
                    if (func_8008FC00() == 1) {
                        func_80102424(actor, 5);
                        actor->unk58 = 0.0f;
                        ((f32 *)actor->actorData)[4] = 0.0f;
                    } else {
                        func_80102424(actor, 2);
                        actor->unk58 = 0.5f;
                    }
                }
            } else if (((f32 *)actor->actorData)[7] < unk_0[1]) {
                actor->unk58 = 0.2f;
                if (func_800D90A4((f32 *)actor->actorData + 3)) {
                    ((f32 *)actor->actorData)[3] = 0.5f;
                    if (func_800F56AC(func_800F54E4()) != 0x14 &&
                        func_800F6C5C(func_800F54E4())) {
                        unk_0[1] = func_800F5628(func_800F54E4());
                        func_800EE7F8(actor->actorData, unk_0);
                        actor->unk64_20 = 1;
                    }
                }
            } else {
                actor->unk58 = 0.2f;
            }
            break;
        }
        case 2: {
            f32 landing_pos[3];
            if (func_800D90A4(&actor->unk58)) {
                _subaddieaudioquick_entrypoint_2(actor, actor->position,
                D_808012F0_chquicksandbaddy);
                if ((func_800EA05C() == 0xB9 || func_800EA05C() == 0xC4) &&
                    func_80800CFC_chquicksandbaddy(actor, actor->position,
                (f32 *)actor->actorData)) {
                    func_800F7D90(func_800F54E4(), 0x52, actor->actorData,
                    actor->actorData[5] ? 0 : 1);
                    actor->unk64_19 = 1;
                } else if (func_80801154_chquicksandbaddy(actor, landing_pos) != -1) {
                    func_800F7D90(func_800F54E4(), 0x52, landing_pos,
                    actor->actorData[5] ? 0 : 1);
                    actor->unk64_19 = 1;
                } else {
                    func_800F7C58(func_800F54E4(), 0x6A,
                    actor->actorData[5] ? 0 : 1);
                    actor->unk64_19 = 0;
                }
                actor->unk74_30 = 0;
                actor->unk79_4 = 0;
                actor->unk50 = 0.0f;
                actor->unk58 = 1.0f;
                func_80102424(actor, 3);
            }
            break;
        }
        case 3: {
            f32 look_pos[3];
            if (func_800D90A4(&actor->unk58)) {
                f32 *spot;
                if (actor->unk64_19) {
                    func_800F5A00(func_800F54E4(), look_pos);
                } else {
                    func_800E3980(look_pos);
                }
                actor->rotation[1] = func_800F1DF4(actor->position, look_pos);
                func_80102424(actor, 4);
                if (!(actor->unk74_30 && actor->unk79_4 >= 6)) {
                    spot = func_800CC63C(
                        (*(u32 *)((u8 *)actor + 0x70) >> 25) - 1,
                    ((*(u32 *)((u8 *)actor + 0x70) << 22) >> 26) - 1);
                    func_800EE7F8(actor->position, spot);
                    actor->position[1] = func_80800CC0_chquicksandbaddy(actor);
                }
            } else if (!(actor->unk74_30 && actor->unk79_4 >= 6)) {
                s32 i;
                f32 ray_start[3];
                f32 ray_end[3];
                f32 hit[3];
                f32 candidate[3];
                f32 angle;
                actor->unk74_30 = 1;
                for (i = 0; i < 3; i++) {
                    angle = actor->unk79_4 * 60.0f;
                    func_800EE7F8(ray_start, actor->position);
                    ray_start[1] += 60.0f;
                    func_800EEB9C(ray_end, angle, func_80103EAC(actor));
                    func_800EF04C(ray_end, ray_start);
                    func_800EE7F8(candidate, ray_end);
                    if (func_800C6A7C(ray_start, ray_end, hit, 0)) {
                        func_800EF334(hit, 300.0f);
                        func_800EF04C(hit, ray_end);
                        func_800EFB24(candidate, ray_end, candidate);
                        func_800EF04C(actor->position, candidate);
                        actor->position[1] = func_80800CC0_chquicksandbaddy(actor);
                        actor->unk74_30 = 0;
                        actor->unk79_4 = 0;
                        break;
                    } else if (func_800CC338(ray_end,
                    (*(u32 *)((u8 *)actor + 0x70) >> 25) - 1,
                    ((*(u32 *)((u8 *)actor + 0x70) << 22) >> 26) - 1) == -1) {
                        func_800EEB9C(hit,
                        func_800F1DF4(actor->position, func_800CC63C(
                            (*(u32 *)((u8 *)actor + 0x70) >> 25) - 1,
                        ((*(u32 *)((u8 *)actor + 0x70) << 22) >> 26) - 1)),
                        func_80103EAC(actor));
                        func_800EF04C(actor->position, hit);
                        actor->position[1] = func_80800CC0_chquicksandbaddy(actor);
                        actor->unk74_30 = 0;
                        actor->unk79_4 = 0;
                        break;
                    } else {
                        ((QS78 *)actor)->attempt += 1; // Matching: bitfield access and the "& 1" below are needed for the match.
                        actor->unk74_30 = (s32)actor->unk74_30 & 1;
                    }
                }
            }
            func_80103014(actor);
            break;
        }
        case 4:
        func_800F4F34(func_800F54E4(), actor->position,
        actor->scale * 50.0f, actor->scale * 150.0f);
        _subaddieaudioquick_entrypoint_4(actor, actor->position,
        D_80801300_chquicksandbaddy, D_80801310_chquicksandbaddy);
        if (func_80101E14(actor, 0.6f)) {
            func_800C4140(0x7FFB5DB2, actor->position, 0x0BB80190);
        } else if (func_80101E14(actor, 0.69f)) {
            func_800C4140(0x797B5DB2, actor->position, 0x0BB80190);
        } else if (func_80101E14(actor, 0.78f)) {
            func_800C4140(0x731B5DB2, actor->position, 0x0BB80190);
        } else if (func_80101E14(actor, 0.87f)) {
            func_800C4140(0x6CBB5DB2, actor->position, 0x0BB80190);
        }
        if (func_80101DDC(actor)) {
            ((f32 *)actor->actorData)[4] = func_800DC178(20.0f, 30.0f);
            func_80102424(actor, 1);
            _subaddieDll_entrypoint_4(actor, 0);
            actor->unk58 = 0.2f;
        }
        break;
        case 5: {
            QuicksandSoundEvent *event;
            ((f32 *)actor->actorData)[4] = actor->unk58;
            func_800D91B8(&actor->unk58);
            event = D_80801320_chquicksandbaddy; do { // Matching: init and "do" must stay on one line (as1 line priority).
                if (event->time < actor->unk58 &&
                    ((f32 *)actor->actorData)[4] <= event->time) {
                    if (event->unk_4 == -1.0f) {
                        func_800F7B9C(func_800F54E4(), 0x26);
                    } else if (event->unk_4 == -2.0f) {
                        func_800FC660(0xB);
                    } else {
                        f32 value = event->unk_4;
                        func_800C4140(((u16)(u32)(value * 1023.0f) << 21) + 0x1B5DB2,
                        actor->position, 0x0BB80190);
                    }
                    break;
                }
                event++;
            } while (event != (QuicksandSoundEvent *)D_80801370_chquicksandbaddy);
            break;
        }
        case 6:
        if (func_80101E14(actor, 0.09f)) {
            func_80101EE4(actor, 0.91f);
            func_80102424(actor, 7);
        }
        break;
        case 7:
        if (func_80101DDC(actor)) {
            ((f32 *)actor->actorData)[4] = func_800DC178(20.0f, 30.0f);
            func_80102424(actor, 1);
        }
        break;
    }

    if (D_808012A0_chquicksandbaddy[actor->unk70_10].unk_4 == 0x1E4) {
        actor->unk64_16 = 1;
        if (func_80101E14(actor, 0.07f) || func_80101E14(actor, 0.92f)) {
            f32 ground_y;
            ground_y = func_800C6920(actor->position, 500.0f, -500.0f, 0)
                + actor->unk54;
            func_80800FC8_chquicksandbaddy(actor->position, ground_y, 5);
            actor->position[1] = ground_y;
            chquicksandbaddy_entrypoint_0(0, actor->position);
        } else if (func_80101F24(actor) > 0.2f &&
            func_80101F24(actor) < 0.55f && func_800DC0C0() < 0.5f) {
            f32 bone_pos[3];
            _subaddieskeleton_entrypoint_0(actor, 0x4D, bone_pos);
            func_80800FC8_chquicksandbaddy(bone_pos,
            func_800C6920(bone_pos, 500.0f, -500.0f, 0) + actor->unk54, 1);
        }
    } else {
        actor->unk64_16 = 0;
    }
}

// Ground height below the actor plus its height offset.
f32 func_80800CC0_chquicksandbaddy(Actor *actor)
{
    f32 ground_y;

    ground_y = func_800C6920(actor->position, 500.0f, -500.0f, 0) + actor->unk54;
    return ground_y;
}

// True if the target point is in reach: close, similar height, clear line of sight.
s32 func_80800CFC_chquicksandbaddy(actor, pos, target)
Actor *actor;
f32 *pos;
f32 *target;
{
    f32 hit_pos[3];

    if (!actor->unk64_20)
        return 0;
    if (func_800EEB40(pos, target) > 4000000.0f)
        return 0;
    if (mlAbsF(target[1] - pos[1]) > 500.0f)
        return 0;
    if (func_800C6A7C(pos, target, hit_pos, 0))
        return 0;
    return 1;
}

// True if the player is in a state to be attacked and this actor is the nearest of its group.
s32 func_80800DBC_chquicksandbaddy(Actor *actor)
{
    f32 player_pos[3];
    Actor *group[20];
    s32 group_count;
    s32 i;
    Actor **other;
    f32 own_dist;

    if (!func_8010C500())
        return 0;
    if (func_800F55D0(func_800F54E4()))
        return 0;
    if (!func_800F6E00(func_800F54E4()))
        return 0;
    if (!func_800F6C5C(func_800F54E4()))
        return 0;
    group_count = _subaddiefind_entrypoint_4(0x1EF, group, 20);
    func_800F5A00(func_800F54E4(), player_pos);
    i = 0;
    if (group_count > 0) {
        other = group;
        do {
            if (actor != *other && (*(u32 *) ((u8 *) actor + 0x70) >> 25) ==
                                           (*(u32 *) ((u8 *) *other + 0x70) >> 25)) {
                own_dist = func_800EEB40(player_pos, actor->position);
                if (func_800EEB40(player_pos, (*other)->position) < own_dist)
                    return 0;
            }
            i++;
            other++;
        } while (i != group_count);
    }
    return func_800D90A4(&actor->unk58) == 0;
}

// Spawns particles at pos (75% chance).
void chquicksandbaddy_entrypoint_0(s32 unk_0, f32 *pos)
{
    s32 emitter;
    if (func_800DC0C0() < 0.75f && func_808010A0_chquicksandbaddy(D_80801390_chquicksandbaddy) &&
        func_8001210C(3)) {
        emitter = func_800B53A4(1);
        func_800BABB8(emitter, pos, NULL, 2.0f, D_80801370_chquicksandbaddy);
        func_800BAB80(emitter, D_80801390_chquicksandbaddy);
        func_800BA22C(emitter, 1);
    }
}

// Spawns sand or sludge particles at pos.
void func_80800FC8_chquicksandbaddy(s32 pos, f32 ground_y, s32 count)
{
    s32 emitter;

    if (func_808010A0_chquicksandbaddy(&D_808013D4_chquicksandbaddy) != 0) {
        emitter = func_800B53A4(count);
        func_800BABB8(emitter, pos, pos, 1.0f, &D_80801394_chquicksandbaddy);
        if (count >= 2) {
            func_800BA714(emitter, 0x32, 0x64);
        }
        func_800BAB80(emitter, &D_808013D4_chquicksandbaddy);
        func_800BA4D0(emitter, (s16) (s32) ground_y);
        func_800BA544(emitter, &_chquicksandbaddy_entrypoint_0);
        func_800BA22C(emitter, count);
    }
}

// Sets the particle colour by map; returns 0 on maps without these particles.
int func_808010A0_chquicksandbaddy(rgb)
Gtexture *rgb;
{
    u8 grey = 0xB4;
    switch (func_800EA05C()) {
        case 0xB9:
        case 0xC4:
            *(u8 *) ((char *) rgb + 0x0) = 0xC8;
            *(u8 *) ((char *) rgb + 0x1) = 0xA0;
            *(u8 *) ((char *) rgb + 0x2) = 0x32;
            return 1;

        case 0x100:
        case 0x10F:
        case 0x15C:
            *(u8 *) ((char *) rgb + 0x0) = grey;
            *(u8 *) ((char *) rgb + 0x1) = grey;
            *(u8 *) ((char *) rgb + 0x2) = grey;
            return 1;

        case 0x106:
            *(u8 *) ((char *) rgb + 0x0) = 0x32;
            *(u8 *) ((char *) rgb + 0x1) = 0xA0;
            *(u8 *) ((char *) rgb + 0x2) = 0x32;
            return 1;

        default:
            return 0;
    }
}

// Finds the landing point nearest to the actor, copies it to out_pos and returns its index (-1 if none).
int func_80801154_chquicksandbaddy(Actor *actor, f32 *out_pos)
{
    // Matching: one-element array keeps the holder in memory.
    f32(*points[1])[3];
    void *points_base;
    f32 *point;
    f32 best_dist;
    f32 dist;
    s32 i;
    s32 best;

    points_base = func_80100094(actor, 1);
    if (points_base) {
        best = -1;
        best_dist = 0.0f;
        i = 0;
        point = points_base;
        points[0] = points_base;
        for (; i != 3; i++, point += 3) {
            // Matching: empty block at loop-body start is needed for the match.
            if (1) {
            }
            if (!func_800EEF24(point)) {
                break;
            }
            if (best != -1) {
                dist = func_800EEB40(actor->position, point);
                if (dist < best_dist) {
                    best_dist = dist;
                    best = i;
                }
            } else {
                best_dist = func_800EEB40(actor->position, point);
                best = i;
            }
        }
        if (best != -1) {
            func_800EE7F8(out_pos, points[0][best]);
        }
        return best;
    }
    return -1;
}

int *chquicksandbaddy_entrypoint_1()
{
    return D_808013D8_chquicksandbaddy;
}

// TU-NOTE: the .data of this overlay is defined here in C, from ROM values. Some tables point to
// functions of this file; IDO schedules those differently unless the tables are in the same unit.
// D_808012A4_chquicksandbaddy = D_808012A0_chquicksandbaddy + 0x4 (linker symbol in undefined_syms.us.txt).
// D_808013D8_chquicksandbaddy is declared as int[] (uses written as NAME[0]).
extern void func_80105834();
extern void func_80101870();
extern void func_80107C2C();
extern u8 boot_thread_stack[];
QuicksandAnimation D_808012A0_chquicksandbaddy[8] = {
    0.0f, 0x0,   0x0,  0.0f, 0x0, 0x0, 0.0f, 0x0,   0x0,  0.0f, 0x0,   0x0,
    4.5f, 0x1E4, 0x4A, 0.0f, 0x0, 0x0, 4.5f, 0x1E4, 0x4A, 4.5f, 0x1E4, 0xA};
u8 D_808012E0_chquicksandbaddy[16] = {0x0, 0x13, 0x4,  0x9C, 0x0, 0xA, 0x1, 0x0,
                                      0x0, 0x16, 0x75, 0x30, 0x0, 0x0, 0x0, 0x0};
u8 D_808012F0_chquicksandbaddy[16] = {0x0, 0x13, 0x5,  0xD1, 0x0, 0xA, 0x1, 0x66,
                                      0x0, 0x16, 0x7D, 0x0,  0x0, 0x0, 0x0, 0x0};
u8 D_80801300_chquicksandbaddy[16] = {0x0, 0x13, 0x4,  0x9E, 0x0, 0xA, 0x0, 0x99,
                                      0x0, 0x16, 0x61, 0xA8, 0x0, 0x0, 0x0, 0x0};
u8 D_80801310_chquicksandbaddy[16] = {0x3E, 0x2E, 0x14, 0x7B, 0x3E, 0x94, 0x7A, 0xE1,
                                      0x3E, 0xE1, 0x47, 0xAE, 0xBF, 0x80, 0x0,  0x0};
QuicksandSoundEvent D_80801320_chquicksandbaddy[10] = {0.0f,  1.0f,  0.4f, 0.95f, 0.8f,  0.9f, 1.2f,
                                                       0.85f, 1.6f,  0.8f, 2.0f,  0.75f, 2.4f, 0.7f,
                                                       2.5f,  -2.0f, 2.8f, 0.65f, 5.5f,  -1.0f};
s32 D_80801370_chquicksandbaddy[8] = {0x1D09DB, 0x161001, 0x2B0280, 0x3000015,
                                      0x4000C0, 0x220080, 0x800180, 0x2000000};
s32 D_80801390_chquicksandbaddy[1] = {0x8C};
u8 D_80801394_chquicksandbaddy[64] = {
    0x0, 0x1D, 0x9,  0xD9, 0x0, 0x1B, 0xFC, 0x18, 0xFC, 0x7C, 0x0, 0x2D, 0x1, 0x2C, 0x1, 0x90,
    0x0, 0x16, 0x10, 0x0,  0x0, 0x23, 0x0,  0x1E, 0x0,  0x15, 0x0, 0xC,  0x0, 0xE6, 0x0, 0x2B,
    0x4, 0x0,  0x4,  0x0,  0x0, 0x2F, 0x0,  0x80, 0x0,  0x80, 0x0, 0x0,  0x0, 0x33, 0x0, 0x59,
    0x0, 0x0,  0x0,  0x99, 0x0, 0x31, 0xFF, 0xF6, 0x0,  0x0,  0x0, 0x7,  0x0, 0x1,  0x0, 0x0};
u8 D_808013D4_chquicksandbaddy[4] = {0x0, 0x0, 0x0, 0xFF};
int D_808013D8_chquicksandbaddy[18] = {0x15801EF,
                                       0x66E0001,
                                       (u32) &D_808012A0_chquicksandbaddy,
                                       (u32) func_80800140_chquicksandbaddy,
                                       (u32) func_80105834,
                                       (u32) func_80101870,
                                       0x1F400000,
                                       0x0,
                                       0x0,
                                       0x21,
                                       0x0,
                                       0x0,
                                       0x0,
                                       (u32) func_80800000_chquicksandbaddy,
                                       (u32) func_80107C2C,
                                       (u32) ((u8 *) boot_thread_stack + 0x1F22),
                                       0x0,
                                       0x0};
