#include "common.h"

typedef struct ToxicCloudFlags {
    u32 pad_0 : 26;
    u32 local_0 : 1;
    u32 pad_1 : 5;
} ToxicCloudFlags;
extern void *func_80100094(Actor *, u32);
extern f32 func_800F5F24(s32);
extern void func_800EFE50(f32 *, void *, void *, f32);
extern void func_800EEB9C(f32 *, f32, f32);
extern void func_800EF1B8(f32 *, f32, f32);
typedef struct {
    u8 pad[0x64];
    u32 pad1 : 2;
    u32 big : 1;
    u32 pad2 : 29;
} ToxicFlags97;
extern f32 func_800EEB40(f32 *, f32 *);
typedef struct ToxicCloudNode {
    s32 pad_0;
    f32 local_0;
    u8 pad_1[6];
    s16 local_1;
} ToxicCloudNode;
typedef struct ToxicCloudRoute {
    u32 local_0 : 7;
    u32 pad_0 : 15;
    u32 local_1 : 6;
    u32 pad_1 : 4;
} ToxicCloudRoute;
extern u8 D_80801434_chfactorytoxiccloud[];
extern u8 D_80801518_chfactorytoxiccloud[];
extern u8 D_8080155C_chfactorytoxiccloud[];
extern void func_800BBCB8(f32 *, f32 *, f32, s32, void *);
typedef struct {
    u8 pad_0[0x78];
    u32 pad_1 : 29;
    u32 local_0 : 1;
    u32 pad_2 : 2;
} ToxicCloudFlags26;
extern int D_80801568_chfactorytoxiccloud[];
typedef struct {
    u8 pad_0[0x64];
    u32 pad_1 : 2;
    u32 local_0 : 1;
    u32 pad_2 : 29;
    u8 pad_3[0x10];
    u32 pad_4 : 29;
    u32 local_1 : 1;
    u32 pad_5 : 2;
} ToxicCloudActorFlags;
extern s32 func_800D91EC(f32 *, f32);
extern f32 func_800F10B4(f32, f32, f32, f32, f32);
extern f32 func_800F15F8(f32, f32, f32);
extern f32 func_800D8FF8(void);
extern f32 func_800DC0C0(void);
extern f32 func_800F1DF4(f32 *, f32 *);
extern f32 func_800EEAD4(f32 *, f32 *);
extern f32 func_800EFB8C(f32 *, f32 *);
extern void func_80102BAC(Actor *, f32, f32, f32);
extern void func_800EF334(f32 *, f32);
extern s32 _subaddieDll_entrypoint_11(Actor *, s32, s32);
extern void _subaddiefade_entrypoint_1(Actor *, u32);
extern void func_80102424(Actor *, s32);
typedef struct {
    f32 timer;
    f32 elapsed;
    s32 index;
    f32 first;
    f32 second;
} ToxicCloudParticle;
extern f32 func_800DC178(f32, f32);
typedef struct {
    f32 local_0;
    f32 local_1;
    s32 local_2;
    f32 local_3;
    f32 local_4;
    u8 pad_0[0x10];
} CloudParticle301;
typedef struct {
    f32 local_0[9][2];
} CloudOffsets301;
typedef struct {
    u8 pad_0[0x64];
    u32 pad_1 : 2;
    u32 local_0 : 1;
    u32 pad_2 : 29;
    u8 pad_3[0x10];
    u32 pad_4 : 29;
    u32 local_1 : 1;
    u32 pad_5 : 2;
    u32 pad_6 : 19;
    u32 local_2 : 1;
    u32 pad_7 : 12;
} CloudActorFlags301;
extern CloudOffsets301 D_808014D0_chfactorytoxiccloud;
extern void _subaddiedraw25d_entrypoint_0(void);
extern void *func_800D674C(s32);
extern void func_800E3980(f32 *);
extern void func_800F18FC(f32 *, f32 *, f32 *);
extern void func_800EEC30(f32 *, f32, f32, f32);
extern void func_800EE780(f32 *, f32 *, f32 *);
extern f32 func_800F1214(f32, f32, f32);
extern void func_800E24E4(void (*)(void), Actor *);
extern void func_800E2AA4(void *, void *, s32, s32, f32 *, f32 *);
extern f32 _subaddiejoy_entrypoint_3(Actor *);
extern f32 func_80013728(f32);
extern f32 mlAbsF(f32);
s32 func_80800BF8_chfactorytoxiccloud();
void func_80800FCC_chfactorytoxiccloud();
void func_80800A34_chfactorytoxiccloud();
void func_808010B8_chfactorytoxiccloud();

// Init: fully visible if flagged, otherwise fade in from nothing; reset the nine puffs.
void func_80800000_chfactorytoxiccloud(Actor *actor)
{
    u8 *particles;
    s32 i;

    particles = func_80100094(actor, 0);
    if (((ToxicCloudFlags *) ((u8 *) actor + 0x78))->local_0) {
        actor->scale = 1.0f;
        _subaddiefade_entrypoint_1(actor, 255);
        *(f32 *) ((u8 *) actor + 0x24) = 600.0f;
    } else {
        func_80102424(actor, 1);
        actor->unk58 = 0.0f;
        _subaddiefade_entrypoint_1(actor, 0);
        actor->unk64_16 = 0;
        actor->scale = 0.0f;
        func_8010A570(actor);
    }
    actor->unk64_24 = 1;
    func_80800FCC_chfactorytoxiccloud(actor, 1);
    for (i = 0; i < 9; i++) {
        func_80800A34_chfactorytoxiccloud(actor, particles + i * 0x24);
    }
}

// Returns 1 when the player is inside this cloud's zone and in range.
s32 func_808000F0_chfactorytoxiccloud(u8 *actor, s32 pos)
{
    u32 *zone_info;
    u32 unk_0;
    zone_info = (u32 *) ((s8 *) actor + 0x70);
    if (func_800CC338(pos, (*zone_info >> 0x19) - 1, ((u32) (*zone_info << 0x16) >> 0x1A) - 1) ==
        -1) {
        return 0;
    }
    if (func_80800BF8_chfactorytoxiccloud(actor, pos) == 0) {
        return 0;
    }
    unk_0 = (u16) *(u16 *) ((s8 *) actor + 0x72);
    unk_0 = unk_0 >> 0xA;
    if (unk_0 == 5) {
        return 0;
    }
    if (unk_0 == 1) {
        return 0;
    }
    if (func_800F64A4(func_800F54E4(), 0x1601) == 0) {
        return 0;
    }
    return 1;
}

s32 func_808012C4_chfactorytoxiccloud();

int func_80801164_chfactorytoxiccloud();

void func_80800AD8_chfactorytoxiccloud();

// Update: fade in (state 1), drift in the zone (2), chase the player (3, 4).
void func_808001B8_chfactorytoxiccloud(Actor *actor)
{
    extern u8 D_8080148C_chfactorytoxiccloud[];

    f32 player_pos[3];
    f32 fade;
    s32 result;
    f32 angle;
    f32 steps;
    f32 delta[3];
    char *particles;
    char *particle;
    s32 i;
    f32 dist;

    func_80800AD8_chfactorytoxiccloud(actor, player_pos);

    result = func_808000F0_chfactorytoxiccloud(actor, player_pos);
    if (result) {
        func_80102424(actor, 4);
    } else if (actor->unk64_19) {
        func_800CF494();
        actor->unk64_19 = 0;
    }

    if (!((ToxicCloudActorFlags *) actor)->local_1) {
        switch (actor->unk70_10) {
            case 1:
                if (func_800D91EC((char *) actor + 0x58, 0.3f)) {
                    _subaddiefade_entrypoint_1(actor, 0xFF);
                    *(f32 *) ((char *) actor + 0x38) = 1.0f;

                    if (((ToxicCloudActorFlags *) actor)->local_0) {
                        func_80102424(actor, 3);
                    } else {
                        func_80102424(actor, 2);
                    }
                } else {
                    fade =
                        func_800F10B4(*(f32 *) ((char *) actor + 0x58), 0.0f, 0.3f, 0.0f, 1.0f);

                    _subaddiefade_entrypoint_1(actor, (u16) (u32) (255.0f * fade));

                    *(f32 *) ((char *) actor + 0x38) = fade;
                    actor->unk64_16 = 1;

                    func_8010A590(actor);

                    *(f32 *) ((char *) actor + 8) += 10.0f;
                }
                break;

            case 2:
                if (((ToxicCloudActorFlags *) actor)->local_0) {
                    func_808010B8_chfactorytoxiccloud(actor);
                } else {
                    *(f32 *) ((char *) actor + 0x24) = func_800F15F8(
                        *(f32 *) ((char *) actor + 0x24), 150.0f, func_800D8FF8() * 200.0f);

                    func_80102BAC(actor, 0.5f, 0.05f, 5.0f);

                    result = func_80801164_chfactorytoxiccloud(actor, 0x125, 4);

                    if ((result & 4) != 0 || func_800DC0C0() < 0.004f) {
                        angle = func_800DC0C0() * 360.0f;
                        result = 0;

                        do {
                            if (_subaddieDll_entrypoint_11(actor, (s32) angle,
                                                           (s32) *
                                                               (f32 *) ((char *) actor + 0x24))) {
                                *(f32 *) ((char *) actor + 0x54) = angle;
                                break;
                            }

                            result++;
                        } while (result != 6);
                    }

                    if (func_800CC338(player_pos, (*(u32 *) ((char *) actor + 0x70) >> 25) - 1,
                                      ((*(u32 *) ((char *) actor + 0x70) << 22) >> 26) - 1) !=
                        -1) {
                        if (func_808012C4_chfactorytoxiccloud(actor)) {
                            func_80102424(actor, 3);
                        }
                    }
                }

                func_80800FCC_chfactorytoxiccloud(actor, 0);

                *(f32 *) ((char *) actor + 8) = func_800F15F8(
                    *(f32 *) ((char *) actor + 8), *(f32 *) ((char *) actor + 0x34) + 120.0f,
                    func_800D8FF8() * 100.0f);

                if (*(f32 *) ((char *) actor + 0x28) < *(f32 *) ((char *) actor + 8)) {
                    *(f32 *) ((char *) actor + 8) = *(f32 *) ((char *) actor + 0x28);
                }
                break;

            case 3:
                if (((ToxicCloudActorFlags *) actor)->local_0) {
                    func_808010B8_chfactorytoxiccloud(actor);
                } else {
                    *(f32 *) ((char *) actor + 0x54) =
                        func_800F1DF4((char *) actor + 4, player_pos);

                    func_80102BAC(actor, 1.0f, 0.1f, 10.0f);

                    *(f32 *) ((char *) actor + 0x24) = func_800F15F8(
                        *(f32 *) ((char *) actor + 0x24), 600.0f, func_800D8FF8() * 500.0f);

                    result = func_80801164_chfactorytoxiccloud(actor, 0x125, 4);

                    if (result & 4) {
                        func_80102424(actor, 2);
                    }

                    if (func_800CC338(player_pos, (*(u32 *) ((char *) actor + 0x70) >> 25) - 1,
                                      ((*(u32 *) ((char *) actor + 0x70) << 22) >> 26) - 1) ==
                            -1 ||
                        !func_808012C4_chfactorytoxiccloud(actor)) {
                        func_80102424(actor, 2);
                    }
                }

                func_80800FCC_chfactorytoxiccloud(actor, 0);

                if (*(f32 *) ((char *) actor + 0x34) < player_pos[1] &&
                    player_pos[1] < *(f32 *) ((char *) actor + 0x28)) {
                    *(f32 *) ((char *) actor + 8) = func_800F15F8(
                        *(f32 *) ((char *) actor + 8), player_pos[1], func_800D8FF8() * 100.0f);
                } else {
                    *(f32 *) ((char *) actor + 8) = func_800F15F8(
                        *(f32 *) ((char *) actor + 8),
                        *(f32 *) ((char *) actor + 0x34) + 120.0f, func_800D8FF8() * 100.0f);

                    if (*(f32 *) ((char *) actor + 0x28) < *(f32 *) ((char *) actor + 8)) {
                        *(f32 *) ((char *) actor + 8) = *(f32 *) ((char *) actor + 0x28);
                    }
                }
                break;

            case 4:
                if (((ToxicCloudActorFlags *) actor)->local_0) {
                    func_808010B8_chfactorytoxiccloud(actor);
                } else {
                    dist = func_800EEAD4(player_pos, (char *) actor + 4);
                    steps = dist / func_800D8FF8() / 600.0f;

                    *(f32 *) ((char *) actor + 0x24) =
                        func_800EFB8C((char *) actor + 4, player_pos) / func_800D8FF8();

                    if (600.0f < *(f32 *) ((char *) actor + 0x24)) {
                        *(f32 *) ((char *) actor + 0x24) = 600.0f;
                    }

                    if (1.0f < steps) {
                        func_800EFB24(delta, player_pos, (char *) actor + 4);

                        func_800EF334(delta, 1.0f / steps);

                        func_800EF04C((char *) actor + 4, delta);
                    } else {
                        *(f32 *) ((char *) actor + 4) = player_pos[0];
                        *(f32 *) ((char *) actor + 0xC) = player_pos[2];
                    }

                    *(f32 *) ((char *) actor + 0x54) = func_800F5F24(func_800F54E4());

                    func_80102BAC(actor, 1.0f, 0.1f, 10.0f);
                }

                func_80102424(actor, 3);

                if (!actor->unk64_19) {
                    func_800CF2D4(4);
                    actor->unk64_19 = 1;
                }

                func_80800FCC_chfactorytoxiccloud(actor, 0);

                if (*(f32 *) ((char *) actor + 0x34) < player_pos[1] &&
                    player_pos[1] < *(f32 *) ((char *) actor + 0x28)) {
                    *(f32 *) ((char *) actor + 8) = func_800F15F8(
                        *(f32 *) ((char *) actor + 8), player_pos[1], func_800D8FF8() * 100.0f);
                } else {
                    *(f32 *) ((char *) actor + 8) = func_800F15F8(
                        *(f32 *) ((char *) actor + 8),
                        *(f32 *) ((char *) actor + 0x34) + 120.0f, func_800D8FF8() * 100.0f);

                    if (*(f32 *) ((char *) actor + 0x28) < *(f32 *) ((char *) actor + 8)) {
                        *(f32 *) ((char *) actor + 8) = *(f32 *) ((char *) actor + 0x28);
                    }
                }
                break;

            case 5:
                if (!((ToxicCloudActorFlags *) actor)->local_1) {
                    func_80102424(actor, 2);
                }
        }

        if (actor->unk70_10 != 5 && actor->unk7C_12) {
            particles = (char *) func_80100094(actor, 0);
            for (i = 0; i < 9; i++) {
                particle = particles + i * 0x24;
                if (func_800D91EC((f32 *) (particle + 4), *(f32 *) particle)) {
                    if (func_800DC0C0() < 0.5f) {
                        func_800BBCB8((char *) actor + 4, 0, actor->scale, 1,
                                      D_8080148C_chfactorytoxiccloud);
                    }

                    func_80800A34_chfactorytoxiccloud(actor, particle);
                }
            }
        }
    }
}

void func_80800A34_chfactorytoxiccloud(actor, particle) Actor *actor;
ToxicCloudParticle *particle;
{
    particle->timer = func_800DC178(0.5f, 1.0f);
    particle->elapsed = 0.0f;
    particle->first = func_800DC178(0.4f, 0.5f) + 0.2f;
    particle->second = func_800DC178(0.7f, 0.9f) + 0.2f;
    particle->index = func_800DC128(0, 16);
}

void func_80800AD8_chfactorytoxiccloud(s32 param_0, f32 *out_pos)
{
    f32 pos_a[3];
    f32 pos_b[3];
    s32 state;
    state = func_800F5410(func_800F54E4());
    switch (state) {
        case 1:
        case 10:
        case 11:
            func_800F5A2C(func_800F54E4(), 5, pos_a);
            func_800F5A2C(func_800F54E4(), 2, pos_b);
            func_800EFE50(out_pos, pos_a, pos_b, 0.5f);
            func_800EEB9C(pos_a, func_800F5F24(func_800F54E4()), 20.0f);
            pos_a[1] += 20.0f;
            func_800EF04C(out_pos, pos_a);
            break;
        default:
            func_800F5A00(func_800F54E4(), out_pos);
            func_800EF1B8(out_pos, func_800F5F24(func_800F54E4()), 30.0f);
            out_pos[1] += 140.0f;
    }
}

s32 func_80800BF8_chfactorytoxiccloud(actor, pos)
Actor *actor;
f32 *pos;
{
    f32 radius;
    f32 radius_scale;

    if (((ToxicFlags97 *) actor)->big) {
        radius_scale = 6.0f;
    } else {
        radius_scale = 2.0f;
    }
    radius = radius_scale * 25.0f;
    return func_800EEB40(pos, (f32 *) ((u8 *) actor + 0x18)) < radius * radius;
}

// Matching: the line breaks in this function are needed for the match.
// Draw: nine animated billboard puffs.
void func_80800C7C_chfactorytoxiccloud(Actor *actor, void *param_1)
{
    f32 cam_pos[3];
    f32 puff_pos[3];
    f32 base_xy[2];
    f32 progress;
    void *sprite;
    f32 scale;
    f32 unk_0;
    f32 size[3];
    s32 alpha;
    s32 i;
    CloudOffsets301 offsets;
    f32 *actor_data;
    CloudParticle301 *particles;
    CloudParticle301 *particle;

    func_80101870(actor);
    if (((CloudActorFlags301 *)actor)->local_2) {
        sprite = func_800D674C(0x9D0);
        particles = func_80100094(actor, 0);
        actor_data = (f32 *)actor->actorData;
        _subaddieskeleton_entrypoint_1(actor, 4, actor_data);
        func_800E3980(cam_pos);
        func_800F18FC(actor_data, cam_pos, base_xy);
        for (i = 0, particle = particles; i != 9; i++, particle++) {
            if (particle->local_0 != 0.0f) {
                progress = func_800F10B4(particle->local_1, 0.0f, particle->local_0, 0.0f, 1.0f);
                offsets = D_808014D0_chfactorytoxiccloud;
                func_800EEC30(cam_pos, base_xy[0] + offsets.local_0[i][0],
                base_xy[1] + offsets.local_0[i][1], ((CloudActorFlags301 *)actor)->local_0 ? 75.0f : 25.0f);
                func_800EE780(puff_pos, actor_data, cam_pos);
                if (((CloudActorFlags301 *)actor)->local_0) { scale = actor->scale * 3.0f; } else { scale = actor->scale; } size[0] = size[1] = size[2] = func_800F1214(progress, particle->local_3, particle->local_4) * scale; // Matching: if/else and the call stay on one line (as1 orders the hoisted constants by line number).
                if (progress < 0.2f) {
                    alpha = func_800F10B4(progress, 0.0f, 0.2f, 0.0f, 140.0f);
                } else if (progress < 0.9f) {
                    alpha = 140;
                } else {
                    alpha = func_800F10B4(progress, 0.9f, 1.0f, 140.0f, 0.0f);
                }
                if (((CloudActorFlags301 *)actor)->local_1) {
                    alpha >>= 1;
                }
                func_800E24E4(_subaddiedraw25d_entrypoint_0, actor);
                func_800E24F8(10, 255, 4);
                func_800E2440(4, 140, 2);
                func_800E257C(alpha);
                func_800E24B4(0);
                func_800E2588(1);
                func_800E2AA4(param_1, sprite, particle->local_2, 0, puff_pos, size);
            }
        }
    }
}

void func_80800FCC_chfactorytoxiccloud(actor, force) Actor *actor;
s32 force;
{
    ToxicCloudNode *node;
    f32 top[3];
    f32 bottom[3];
    f32 hit_normal[3];

    if (!func_8001210C(3) || force) {
        func_800EE7F8(top, actor->position);
        top[1] += 400.0f;
        func_800EE7F8(bottom, actor->position);
        bottom[1] -= 1000.0f;
        if (func_800BEF00(top, bottom, hit_normal, 0)) {
            *(f32 *) ((u8 *) actor + 0x34) = bottom[1];
        } else {
            *(f32 *) ((u8 *) actor + 0x34) = actor->position[1];
        }
        node = (ToxicCloudNode *) func_800CC63C(
            ((ToxicCloudRoute *) ((u8 *) actor + 0x70))->local_0 - 1,
            ((ToxicCloudRoute *) ((u8 *) actor + 0x70))->local_1 - 1);
        *(f32 *) ((u8 *) actor + 0x28) = node->local_0 + node->local_1 - 25.0f;
    }
}

void func_808010B8_chfactorytoxiccloud(actor) Actor *actor;
{
    f32 speed;

    speed = _subaddiejoy_entrypoint_3(actor) * 650.0f;
    func_80102BAC(actor, 1.5f, 1.0f, 25.0f);
    if (mlAbsF(func_80013728(actor->unk54 - actor->rotation[1])) < 90.0f) {
        *(f32 *) &actor->actorData[3] = speed;
    } else {
        *(f32 *) &actor->actorData[3] = speed / 10.0f;
    }
    func_8010BA80(actor, 0x200026, 0x20);
}

int func_80801164_chfactorytoxiccloud(u8 *actor)
{
    f32 saved;

    saved = *(f32 *) ((char *) actor + 0x48);
    *(f32 *) ((char *) actor + 0x48) = *(f32 *) ((char *) actor + 0x54);
    func_8010BA80();
    *(f32 *) ((char *) actor + 0x48) = saved;
}

int func_808011A0_chfactorytoxiccloud(Actor *actor, unsigned int msg, s32 param_2)
{
    switch (msg) {
        case 0x40:
            func_800BBCB8((f32 *) actor->actorData, 0, actor->scale, 4,
                          D_80801518_chfactorytoxiccloud);
            func_800FFAB0(actor);
            if (actor->unk64_19) {
                func_800CF494();
                actor->unk64_19 = 0;
            }
            return 1;
        case 1:
            if (actor->unk70_10 != 1) {
                func_80102424(actor, 3);
            }
            return 1;
        case 2:
            if (!func_80107070(actor, 1)) {
                func_80102424(actor, 6);
                _subaddiefade_entrypoint_3(actor);
            }
            return 1;
        case 0x38:
            func_80101074(D_80801434_chfactorytoxiccloud);
            return 2;
        case 0x97:
            func_80101010(D_8080155C_chfactorytoxiccloud);
            return 1;
        default:
            return 0;
    }
}

s32 func_808012C4_chfactorytoxiccloud(Actor *actor)
{
    Actor *clouds[10];
    s32 count;
    s32 i;
    s32 is_nearest;
    f32 own_dist;
    f32 player_pos[3];

    count = _subaddiefind_entrypoint_4(0x3FF, clouds, 10);
    if (count >= 2) {
        is_nearest = 1;
        func_800F5A00(func_800F54E4(), player_pos);
        own_dist = func_800EEB40(actor->position, player_pos);
        for (i = 0; i < count; i++) {
            if (!((ToxicCloudFlags26 *) clouds[i])->local_0) {
                if (actor != clouds[i]) {
                    is_nearest &= own_dist < func_800EEB40(clouds[i]->position, player_pos);
                    if (!is_nearest) {
                        return 0;
                    }
                }
            }
        }
        return is_nearest;
    }
    return 1;
}

int chfactorytoxiccloud_entrypoint_0()
{
    return (int) &D_80801568_chfactorytoxiccloud;
}

// TU-NOTE: the overlay .data is defined here in C; tables holding function pointers must be in
// the same unit, or IDO's assembler schedules those functions differently. D_80801568_chfactorytoxiccloud is int[].
extern void func_80105834();
extern void func_80108ED0();
extern void func_80107C2C();
u32 D_80801420_chfactorytoxiccloud[5] = {0x20000, 0x60000, 0x60000, 0x0, 0x70000};
u8 D_80801434_chfactorytoxiccloud[24] = {0x0,  0x0,  0x0,  0x3,  0x3F, 0xC0, 0x0, 0x0,
                                         0x0,  0x1,  0x0,  0x0,  0x0,  0x0,  0x0, 0x1,
                                         0x3F, 0x99, 0x99, 0x9A, 0x2,  0x3,  0x0, 0x0};
u32 D_8080144C_chfactorytoxiccloud[16] = {
    0x0,        0x0,       0x3F800000, 0x2690001, 0x40000000, 0x2690001, 0x3F800000, 0x2690001,
    0x3F800000, 0x2690001, 0x3F800000, 0x2690021, 0x3F800000, 0x2690001, 0x3F800000, 0x2690001};
u8 D_8080148C_chfactorytoxiccloud[68] = {
    0x0,  0x1D, 0x9,  0xD0, 0x0, 0x16, 0x0, 0x8,  0x0, 0x18, 0x0, 0x0,  0x0,  0xF,
    0x0,  0x0,  0x0,  0x23, 0x0, 0xE,  0x0, 0x0,  0x0, 0x32, 0x0, 0x2B, 0x0,  0xC0,
    0x1,  0x0,  0x0,  0x22, 0x0, 0x66, 0x0, 0x80, 0x1, 0x80, 0x2, 0x0,  0x0,  0x15,
    0x0,  0x73, 0x0,  0x99, 0x0, 0x20, 0xA, 0xFF, 0x3, 0x3C, 0x0, 0x2C, 0xFF, 0xCE,
    0xFF, 0xCE, 0xFF, 0xCE, 0x0, 0x32, 0x0, 0x0,  0x0, 0x32, 0x0, 0x0};
CloudOffsets301 D_808014D0_chfactorytoxiccloud = {0.0f,   -9e+01f, 0.0f,    0.0f, 0.0f,   9e+01f,
                                                  45.0f,  -45.0f,  9e+01f,  0.0f, 45.0f,  45.0f,
                                                  -45.0f, -45.0f,  -9e+01f, 0.0f, -45.0f, 45.0f};
u8 D_80801518_chfactorytoxiccloud[68] = {
    0x0, 0x1D, 0x9,  0xD0, 0x0, 0x16, 0x0, 0x8,  0x0, 0x18, 0x0, 0x0,  0x0,  0xF,
    0x0, 0x0,  0x0,  0x23, 0x0, 0xE,  0x0, 0x0,  0x0, 0x32, 0x0, 0x2B, 0x0,  0xF5,
    0x1, 0x8C, 0x0,  0x22, 0x0, 0x33, 0x0, 0xC0, 0x2, 0x33, 0x2, 0x80, 0x0,  0x15,
    0x0, 0x59, 0x0,  0x99, 0x0, 0x20, 0xA, 0xFF, 0x3, 0x50, 0x0, 0x2C, 0xFF, 0x9C,
    0x0, 0x64, 0xFF, 0x9C, 0x0, 0x64, 0x0, 0xC8, 0x0, 0x64, 0x0, 0x0};
u8 D_8080155C_chfactorytoxiccloud[12] = {0x0, 0x0, 0x0, 0x0, 0x42, 0xC8,
                                         0x0, 0x0, 0x0, 0x0, 0x0,  0x0};
int D_80801568_chfactorytoxiccloud[18] = {0x11603FF,
                                          0x7090002,
                                          (u32) &D_8080144C_chfactorytoxiccloud,
                                          (u32) func_808001B8_chfactorytoxiccloud,
                                          (u32) func_80105834,
                                          (u32) func_80800C7C_chfactorytoxiccloud,
                                          0xFA00000,
                                          0x0,
                                          0x0,
                                          0xA20261,
                                          0x0,
                                          (u32) func_80108ED0,
                                          0x1440000,
                                          (u32) func_80800000_chfactorytoxiccloud,
                                          (u32) func_80107C2C,
                                          -0x7FDFABF3,
                                          (u32) func_808011A0_chfactorytoxiccloud,
                                          (u32) &D_80801420_chfactorytoxiccloud};
