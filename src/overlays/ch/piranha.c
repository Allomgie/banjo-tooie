#include "common.h"

typedef struct {
    u8 pad0[0x6E];
    u16 pad6E : 7;
    u16 f6E : 9;
    u8 pad70[6];
    u16 f76 : 9;
    u16 pad76 : 7;
} PiranhaState;
extern void func_8008FFBC(f32 *);
extern f32 func_800DC178(f32, f32);
extern f32 func_800EFC7C(f32 *, f32 *);
extern void func_800EFA4C(f32 *, f32, f32, f32);
extern void func_800EFB24(f32 *, f32 *, f32 *);
extern void func_800EF04C(f32 *, f32 *);
extern void *func_80100094(Actor *, u32);
extern void func_800EF334(f32 *, f32);
extern f32 func_800D8FF8(void);
extern f32 func_800EEF94(f32 *);
typedef struct {
    u8 pad[0x12];
    u16 f12 : 15;
    u16 r : 1;
} PiranhaSub;
extern Actor *_subaddiefind_entrypoint_0(f32 *, s32, s32, f32 *);
extern void func_800DA3B8();
typedef struct {
    u8 unk_0;
    u8 drawn;
    u16 saved_state;
    f32 target[3];
    f32 floor_y;
    s32 unk_14;
    u32 unk_18;
} PiranhaPlacement49;
extern void func_800EE7F8(f32 *, f32 *);
extern int D_80801B60_chpiranha[];
extern int D_80801BA8_chpiranha[];
extern int D_80801BF0_chpiranha[];
extern void func_800DE448(f32 *, f32 *, f32, s32, s32);
extern Actor *func_80106790(Unk80132ED0 *);
extern void func_800EFA20(f32 *, f32 *, f32);
extern s32 func_800BF0E0(f32 *, f32 *, f32, f32 *, s32, s32);
extern f32 func_800EEAA4(f32 *, f32 *);
extern f32 func_80090010(void);
extern void func_800EFCD8(f32 *, f32, f32);
typedef struct {
    u8 pad_0[0x1C];
    f32 fish[1][12];
} PiranhaPathTop50;
void func_80801420_chpiranha();
void func_8080154C_chpiranha();

int func_80800000_chpiranha(Actor *actor)
{
    func_80100074(actor, 0, 0);
    actor->unk3C = 0;
    func_800DA3B8(0x6A8, 0);
}

// Draws every fish; the first 10 also get a shadow model.
void func_8080003C_chpiranha(Actor *actor, s32 param_1)
{
    u8 *school;
    s32 model;
    s32 i;
    f32 pos[3];
    f32 rot[3];
    u8 *fish;
    s32 shadow_model;

    school = func_80100094(actor, 0);
    model = func_801039E4(actor->unk0);
    for (i = 0, fish = school + 0x1C; i < actor->unk6C_0;
         i++, fish += 0x30) {
        func_800EFA4C(rot, 0.0, *(f32 *) (fish + 0x28) - 90.0f, 0.0f);
        func_800EE780(pos, actor->position, fish);
        func_800DF830(2);
        func_800DF410(255);
        func_800DE448(pos, rot, 0.075f, 0, model);
        school[1] |= func_800DF350();
        if (i < 10) {
            shadow_model = func_800D674C(0x637);
            if (shadow_model) {
                pos[1] = *(f32 *) (school + 0x10) + 6.0f;
                func_800DF410(192);
                func_800DF830(2);
                func_800DE448(pos, rot, 0.1f, 0, shadow_model);
                school[1] |= func_800DF350();
            }
        }
    }
}

void func_80800218_chpiranha(Actor *actor, s32 state)
{
    if (actor->unk70_10 == 7) {
        actor->unk64_16 = 1;
    }
    func_80101FDC(actor, state);
    if (state == 7) {
        actor->unk64_16 = 0;
    }
}

void func_80800280_chpiranha(PiranhaState *actor)
{
    actor->f6E = actor->f76;
}

s32 func_80801638_chpiranha();

s32 func_80801508_chpiranha();

void func_80801250_chpiranha(f32 *param_0, f32 *param_1, f32 *param_2, f32 param_3, f32 param_4,
                             f32 *param_5, f32 *param_6);

void func_80800EFC_chpiranha(u8 *param_0, f32 *param_1, f32 param_2);

f32 func_80800CAC_chpiranha();

// Per-frame update: wall bounce, guard following and the state machine (7 = guarding,
// 3/4 = chase and bite the player).
void func_808002A0_chpiranha(Actor *actor)
{
    f32 accel[3];
    f32 old_pos[3];
    f32 next_pos[3];
    f32 normal[3];
    char *school;
    f32 player_pos[3];
    f32 dt;
    f32 dist_sq;
    f32 dot;

    school = (char *) func_80100094(actor, 0);
    dt = func_800D8FF8();

    if (!func_8010C9B0(actor->position, 0x5DC)) {
        if (actor->unk5F != 0) {
            func_800C2FDC(actor->unk5F);
            actor->unk5F = 0;
            func_800DA3B8(0x6A8, 0);
        }
    }

    if (actor->unk3C != 0) {
        Actor *guard;
        if ((actor->unk3C->unk24 >> 22) == 0x22F) {
            guard = func_80106790(actor->unk3C);
            func_800EE7F8(school + 4, guard->position);
            *(f32 *) (school + 8) += 250.0f;
        }
    }

    func_800EE7F8(old_pos, actor->position);

    func_800EFA20(next_pos, (char *) actor + 0x28, dt);

    func_800EF04C(next_pos, actor->position);

    if (func_800BF0E0(old_pos, next_pos, 75.0f, normal, 3, 0)) {
        func_800EF2A0(normal);

        dot = func_800EEAA4((char *) actor + 0x28, normal);

        // Reflect the velocity off the hit surface.
        func_800EFA20((char *) actor + 0x28, normal, dot * -1.5f);

        func_800EFA20((char *) actor + 0x18, normal, 37.5f);

        func_800EF04C((char *) actor + 0x18, actor->position);

        if (actor->unk70_10 != 6) {
            *(u8 *) (school + 2) = actor->unk70_10;
            func_80800218_chpiranha(actor, 6);
        }
    }

    func_80801250_chpiranha((char *) actor + 0x18, actor->position, (char *) actor + 0x28,
                            *(f32 *) ((char *) actor + 0x24), 100.0f, 0, accel);

    func_8008FE94(5, player_pos);

    dist_sq = func_800EFC7C(actor->position, (char *) actor + 0x18);

    switch (actor->unk70_10) {
        case 7: {
            Actor *guard;
            if (actor->unk3C != 0) {
                guard = func_80106790(actor->unk3C);

                if ((actor->unk3C->unk24 >> 22) == 0x22F) {
                    func_800EE7F8((char *) actor + 0x18, school + 4);

                    func_800EE7F8(actor->position, school + 4);
                }

                if (guard->unk70_10 != 2) {
                    break;
                }

                *(f32 *) (school + 8) += 150.0f;

                func_80800EFC_chpiranha(actor, school + 4, 100.0f);

                func_80800218_chpiranha(actor, 2);

                actor->unk3C = 0;
                actor->unk58 = 0.0f;
            } else {
                *(f32 *) (school + 8) += 150.0f;
                func_80800218_chpiranha(actor, 3);
            }
            break;
        }

        case 1:
            if (func_80801638_chpiranha(actor)) {
                func_80800218_chpiranha(actor, 2);
            }

            if (actor->unk3C != 0) {
                if ((actor->unk3C->unk24 >> 22) == 0x22F) {
                    func_800EE7F8((char *) actor + 0x18, school + 4);

                    func_800EE7F8(actor->position, school + 4);
                }
            }

            if (dist_sq < 2500.0f) {
                func_80800EFC_chpiranha(actor, school + 4, 100.0f);
            }
            break;

        case 2:
            if (dist_sq < 2500.0f) {
                func_80800EFC_chpiranha(actor, school + 4, 100.0f);
            }

            func_80801508_chpiranha(actor);
            break;

        case 3:
            func_800EE7F8((char *) actor + 0x18, player_pos);

            *(f32 *) ((char *) actor + 0x1C) += 50.0f;

            if ((actor->unk0->unk24 >> 22) == 0x2C2) {
                actor->unk58 += dt;

                if (dist_sq < 2500.0f && actor->unk58 > 0.5f && (actor->unk6C_0 > 0.0f) &&
                    func_8010D284() != 3 && func_80800CAC_chpiranha() > 5000.0f) {
                    // Bite: damage the player.
                    func_80090434(0xD);
                    actor->unk58 -= 0.5f;
                }

                if (dist_sq > 2500.0f) {
                    f32 offset[3];
                    offset[1] = 0.0f;
                    func_800EFCD8(offset, func_80090010(), 100.0f);
                    func_800EF04C((char *) actor + 0x18, offset);

                    if (*(f32 *) ((char *) actor + 0x24) < 250.0f) {
                        *(f32 *) ((char *) actor + 0x24) *= 1.1f;
                    }
                }

                if (dist_sq > 7500.0f) {
                    if (*(f32 *) ((char *) actor + 0x24) < 250.0f) {
                        *(f32 *) ((char *) actor + 0x24) *= 1.1f;
                    } else if (*(f32 *) ((char *) actor + 0x24) > 100.0f) {
                        *(f32 *) ((char *) actor + 0x24) *= 0.9f;
                    }
                }

                if (dist_sq < 2750.0f) {
                    func_80800EFC_chpiranha(actor, player_pos, 50.0f);

                    func_80800218_chpiranha(actor, 4);
                }
            } else {
                if (*(f32 *) ((char *) actor + 0x24) < 100.0f) {
                    *(f32 *) ((char *) actor + 0x24) += 5.0f;
                } else if (*(f32 *) ((char *) actor + 0x24) > 100.0f) {
                    *(f32 *) ((char *) actor + 0x24) -= 5.0f;
                }

                if (dist_sq < 2500.0f) {
                    func_80800EFC_chpiranha(actor, player_pos, 50.0f);

                    func_80800218_chpiranha(actor, 4);
                }
            }

            func_8080154C_chpiranha(actor);
            break;

        case 4:
            player_pos[1] += 50.0f;

            actor->unk58 += dt;

            if ((actor->unk0->unk24 >> 22) == 0x2C2) {
                if (actor->unk58 > 0.5f && (actor->unk6C_0 > 0.0f) && func_8010D284() != 3 &&
                    func_80800CAC_chpiranha() > 5000.0f) {
                    func_80090434(0xD);
                    actor->unk58 -= 0.5f;
                }
            } else {
                if (actor->unk58 > 0.5f && (actor->unk6C_0 > 0.0f) && func_8010D284() != 3) {
                    func_80090434(0xD);
                    actor->unk58 -= 0.5f;
                }
            }

            // Player mode 3: lose one fish every 0.2 s.
            if (actor->unk58 > 0.2f && func_8010D284() == 3) {
                f32 fish_pos[3];
                if (actor->unk6C_0-- > 0) {
                    func_800EE780(fish_pos,
                                  ((PiranhaPathTop50 *) school)->fish[actor->unk6C_0],
                                  actor->position);

                    func_80801690_chpiranha(actor, fish_pos);

                    actor->unk58 -= 0.2f;
                }
            }

            if (actor->unk6C_0 == 0) {
                func_800FFA88(actor->unk0);
            }

            if (dist_sq < 2500.0f) {
                func_80800EFC_chpiranha(actor, player_pos, 50.0f);
            }

            if (dist_sq > 2500.0f || func_80800CAC_chpiranha() > 0.0f) {
                func_80800218_chpiranha(actor, 3);
            } else {
                func_8080154C_chpiranha(actor);
            }
            break;

        case 5:
            func_800EE7F8((char *) actor + 0x18, school + 4);

            if ((actor->unk0->unk24 >> 22) != 0x2C2) {
                if (dist_sq < 2500.0f) {
                    func_80800218_chpiranha(actor, 2);
                }

                func_80801508_chpiranha(actor);
            } else {
                if (func_80800CAC_chpiranha() > 7500.0f && dist_sq < 2500.0f) {
                    func_80800218_chpiranha(actor, 2);
                }
            }
            break;

        case 6:
            if (dist_sq < 2500.0f) {
                func_80800218_chpiranha(actor, *(u8 *) (school + 2));
            }
    }

    if (*(u8 *) (school + 1) != 0 && actor->unk70_10 != 7) {
        func_80801420_chpiranha(actor);
    }

    *(u8 *) (school + 1) = 0;
}

// Returns the squared player speed.
f32 func_80800CAC_chpiranha(void)
{
    f32 velocity[3];

    f32 speed_sq;

    func_8008FFBC(velocity);
    // Matching: y goes through the result local so it lands in f2.
    speed_sq = velocity[1];
    speed_sq = velocity[0] * velocity[0] + speed_sq * speed_sq + velocity[2] * velocity[2];
    return speed_sq;
}

void func_80800CEC_chpiranha(f32 *origin, f32 *target, f32 radius, f32 *speed, f32 speed_min,
                             f32 speed_max)
{
    s32 i;

    i = 0;
    do {
        func_800EFA4C(target, func_800DC178(-radius, radius), func_800DC178(-radius, radius),
                      func_800DC178(-radius, radius));
        i++;
    } while (i < 10 && func_800EFC7C(origin, target) < radius * radius);
    *speed = func_800DC178(speed_min, speed_max);
}

void func_80800DD0_chpiranha(Actor *actor, f32 *fish)
{
    f32 radius;
    f32 speed_min;
    f32 speed_max;

    if (actor->unk70_10 != 7) {
        radius = actor->unk70_10 == 4 ? ((actor->unk0->unk24 >> 22) == 0x2C2 ? 150.0f : 50.0f)
                                         : (actor->unk70_10 == 3 ? 100.0f : 150.0f);
        speed_min = actor->unk70_10 == 1 ? 20.0f : 40.0f;
        speed_max = actor->unk70_10 == 1 ? 40.0f : 80.0f;
        func_80800CEC_chpiranha(fish, fish + 6, radius, fish + 11, speed_min, speed_max);
    } else {
        func_80800CEC_chpiranha(fish, fish + 6, 5.0f, fish + 11, 5.0f, 5.0f);
    }
}

void func_80800EFC_chpiranha(u8 *actor, f32 *anchor, f32 radius)
{
    f32 delta[3];
    f32 *target;
    f32 speed_min;
    f32 speed_max;
    f32 unk_0;

    target = (f32 *) (actor + 0x18);
    func_800EFB24(delta, (f32 *) (actor + 4), anchor);
    // Matching: the empty blocks are needed for the match.
    if (1) {
    }
    if (1) {
    }
    if (((Actor *) actor)->unk70_10 != 7) {
        if ((*(u32 *) (*(u8 **) actor + 0x24) >> 22) != 0x2C2) {
            if (((Actor *) actor)->unk70_10 == 5) {
                speed_min = 20.0f;
            } else {
                speed_min = 25.0f;
            }
            if (((Actor *) actor)->unk70_10 == 5) {
                speed_max = 20.0f;
            } else {
                speed_max = 30.0f;
            }
            func_80800CEC_chpiranha(delta, target, radius, (f32 *) (actor + 0x24), speed_min, speed_max);
        } else {
            if (((Actor *) actor)->unk70_10 == 5) {
                speed_min = 20.0f;
            } else {
                speed_min = 25.0f;
            }
            if (((Actor *) actor)->unk70_10 == 5) {
                speed_max = 20.0f;
            } else {
                speed_max = 30.0f;
            }
            func_80800CEC_chpiranha(delta, target, radius, (f32 *) (actor + 0x24), speed_min, speed_max);
        }
    } else {
        func_80800CEC_chpiranha(delta, target, 5.0f, (f32 *) (actor + 0x24), 5.0f, 5.0f);
    }
    func_800EF04C(target, anchor);
}

// Allocates the fish data and gives every fish a start position and first target.
void func_8080106C_chpiranha(Actor *actor)
{
    u32 i;
    u8 *school;
    u8 *fish;
    f32 x;
    f32 y;
    func_80100074(actor, 0, actor->unk6C_0 * 0x30 + 0x1C);
    school = func_80100094(actor, 0);
    i = 0;
    fish = school + 0x1C;
    for (; i < actor->unk6C_0; i++, fish += 0x30) {
        if (*(u32 *) ((u8 *) actor->unk0 + 0x24) >> 22 == 0x2C1) {
            // Matching: x and y are separate temporaries for the match.
            x = func_800DC178(-150.0f, 150.0f);
            y = func_800DC178(-150.0f, 150.0f);
            func_800EFA4C((f32 *) fish, x, y, func_800DC178(-150.0f, 150.0f));
        } else {
            func_800EFA4C((f32 *) fish, 0.0f, -50.0f, 0.0f);
        }
        func_800EFD24(fish + 0xC);
        func_800EFD24(fish + 0x24);
        func_80800DD0_chpiranha(actor, fish);
    }
    func_800EFA4C((f32 *) actor->actorData + 4, 0.0f, 1.0f, 0.0f);
    func_80800EFC_chpiranha(actor, school + 4, 100.0f);
}

// Rescales vec to new_length.
void func_80801210_chpiranha(f32 *vec, f32 length, f32 new_length)
{
    if (length != 0.0f) {
        func_800EF334(vec, new_length / length);
    }
}

// Spring steering: accelerate pos toward target, integrate velocity, clamp to max_speed.
void func_80801250_chpiranha(f32 *target, f32 *pos, f32 *velocity, f32 max_speed, f32 near_dist,
                             f32 *rotation, f32 *accel)
{
    f32 dt;
    f32 len;
    f32 zero[3];

    dt = func_800D8FF8();
    func_800EFB24(accel, target, pos);
    len = func_800EEF94(accel);
    if (len < near_dist + near_dist) {
        func_80801210_chpiranha(accel, len, 8.0f * max_speed);
    } else {
        func_80801210_chpiranha(accel, len, max_speed + max_speed);
    }
    pos[0] += velocity[0] * dt + (accel[0] * dt) * dt;
    pos[1] += velocity[1] * dt + (accel[1] * dt) * dt;
    pos[2] += velocity[2] * dt + (accel[2] * dt) * dt;
    velocity[0] += accel[0] * dt;
    velocity[1] += accel[1] * dt;
    velocity[2] += accel[2] * dt;
    len = func_800EEF94(velocity);
    if (max_speed < len) {
        func_80801210_chpiranha(velocity, len, max_speed);
    }
    if (rotation != NULL) {
        func_800EFD24(zero);
        func_800F18FC(velocity, zero, rotation);
    }
}

// Steers every fish and picks a new target for those that reached theirs.
// Matching: old-style (K&R) definition is needed for the match.
void func_80801420_chpiranha(actor) Actor *actor;
{
    u8 *fish;
    f32 *target;
    u32 i;
    f32 accel[3];

    fish = func_80100094(actor, 0);
    i = 0;
    fish += 0x1C;
    for (; i < actor->unk6C_0; i++, fish += 0x30) {
        target = (f32 *) (fish + 0x18);
        func_80801250_chpiranha(target, (f32 *) fish, (f32 *) (fish + 0xC),
                                *(f32 *) (fish + 0x2C), 150.0f, (f32 *) (fish + 0x24),
                                accel);
        if (func_800EFC7C((f32 *) fish, target) < 2500.0f) {
            func_80800DD0_chpiranha(actor, fish);
        }
    }
}

s32 func_80801508_chpiranha(Actor *this)
{
    if (func_8010C500(this) && func_8010C9B0(this->position, 0x384)) {
        func_80800218_chpiranha(this, 3);
    }
}

// Matching: old-style (K&R) definition is needed for the match.
void func_8080154C_chpiranha(actor) Actor *actor;
{
    s32 give_up = 0;

    if (!func_8010C500(actor)) {
        give_up = 1;
    }
    if (actor->unk0->unk24 >> 22 != 0x2C2) {
        if (!func_8010C9B0(actor->position, 900)) {
            give_up = 1;
        }
    } else if (func_80800CAC_chpiranha() < 2500.0f &&
               (f32) func_800DC128(25, 75) < actor->unk58) {
        give_up = 1;
        actor->unk58 = 0.0f;
    }
    if (give_up) {
        func_80800218_chpiranha(actor, 5);
        func_80800EFC_chpiranha(actor, (u8 *) func_80100094(actor, 0) + 4, 100.0f);
    }
}

s32 func_80801638_chpiranha(u8 *actor)
{
    return (*(PiranhaSub **) (actor + 0x3C) != NULL)
               ? (*(PiranhaSub **) (actor + 0x3C))->f12 !=
                     *(s32 *) ((u8 *) func_80100094((Actor *) actor, 0) + 0x18)
               : 1;
}

int func_80801690_chpiranha(s32 actor, s32 pos)
{
    extern f32 D_80801B10_chpiranha[];
    func_800BBCB8(pos, 0, 0x3F800000, 1, &D_80801B10_chpiranha);
}

// Picks the nearest of actors 0x211/0x199/0x19A within 500 units as guard target.
Actor *func_808016D0_chpiranha(Actor *actor)
{
    Actor *found;
    Actor *nearest;
    f32 nearest_dist;
    f32 found_dist;
    s32 pad;

    nearest = _subaddiefind_entrypoint_0(actor->position, 0x211, -1, &nearest_dist);
    found = _subaddiefind_entrypoint_0(actor->position, 0x199, -1, &found_dist);
    if (found && !nearest)
        nearest = found;
    if (found && nearest && (found_dist < nearest_dist || nearest_dist > 500.0f)) {
        nearest = found;
        nearest_dist = found_dist;
    }
    found = _subaddiefind_entrypoint_0(actor->position, 0x19A, -1, &found_dist);
    if (found && !nearest)
        nearest = found;
    if (found && nearest && (found_dist < nearest_dist || nearest_dist > 500.0f)) {
        nearest = found;
        nearest_dist = found_dist;
    }
    if (nearest)
        actor->unk3C = nearest->unk0;
    else
        actor->unk3C = NULL;
    if (nearest_dist > 500.0f)
        actor->unk3C = NULL;
    return nearest;
}

// Event 0x95: set up the fish and the guard target.
s32 func_8080182C_chpiranha(Actor *actor, s32 event, s32 param_2)
{
    f32 ray_start[3];
    f32 ray_end[3];
    f32 hit[3];
    PiranhaPlacement49 *school;
    Actor *guard;
    if (event == 0x95) {
        func_8080106C_chpiranha(actor);
        school = func_80100094(actor, 0);
        guard = func_808016D0_chpiranha(actor);
        school->floor_y = actor->position[1];
        func_800EE7F8(school->target, actor->unk3C ? guard->position : actor->position);
        if ((actor->unk0->unk24 >> 22) == 0x2C1)
            school->target[1] += 250.0f;
        else
            school->target[1] += 100.0f;
        func_800EE7F8(actor->position, school->target);
        func_800EE7F8((f32 *) actor->actorData, actor->position);
        func_800EE7F8(ray_start, actor->position);
        func_800EE7F8(ray_end, actor->position);
        ray_start[1] += 50.0f;
        ray_end[1] -= 500.0f;
        if (func_800BEF00(ray_start, ray_end, hit, actor->unk14))
            school->floor_y = ray_end[1];
        if (actor->unk3C)
            school->unk_18 = (u32) *(u16 *) ((u8 *) actor->unk3C + 0x12) >> 1;
        else
            school->unk_18 = 0;
        school->drawn = 1;
        if (actor->unk3C)
            func_800DA3B8(0x34, 1);
        if ((actor->unk0->unk24 >> 22) == 0x2C1)
            func_80800218_chpiranha(actor, actor->unk3C ? 1 : 2);
        else
            func_80800218_chpiranha(actor, actor->unk3C ? 7 : 2);
        actor->unk58 = 0.0f;
        actor->unk64_20 = func_800DB9B0() | func_800DA298(0x650);
    } else {
        return 0;
    }
    return 1;
}

int chpiranha_entrypoint_0()
{
    return (int) &D_80801B60_chpiranha;
}

int chpiranha_entrypoint_1()
{
    return (int) &D_80801BA8_chpiranha;
}

int chpiranha_entrypoint_2()
{
    return (int) &D_80801BF0_chpiranha;
}

// TU-NOTE: the overlay .data is defined here in C. Its tables point to functions of this
// file, and IDO schedules some of them differently unless they are in the same unit.
// Values come from the ROM; the externs of these tables were retyped to f32[]/int[].
extern void func_80107C2C();
f32 D_80801B10_chpiranha[20] = {2.665463e-39f,   2.020384e-39f,  3.67521e-40f,   6.42853e-40f,
                                7.3497e-40f,     2.3509895e-38f, 1.7767901e-36f, 3.857091e-39f,
                                1.84388e-40f,    1.8807957e-37f, 2.33e-43f,      2.568872e-39f,
                                -4.0240387e+34f, 5.877526e-39f,  -2.807842e+37f, 1.5869846e-37f,
                                4.132177e-39f,   3.511722e-37f,  3.1593933e-38f, 3.159141e-38f};
// Actor 0x2C1 (wider school).
int D_80801B60_chpiranha[18] = {0x2C102FC,
                                0x73F0001,
                                0x0,
                                (u32) func_808002A0_chpiranha,
                                0x0,
                                (u32) func_8080003C_chpiranha,
                                0xFA00000,
                                0x3F800000,
                                0x0,
                                0x1,
                                (u32) func_80800000_chpiranha,
                                0x0,
                                0x0,
                                (u32) func_80800280_chpiranha,
                                (u32) func_80107C2C,
                                -0x7FFFFFFE,
                                (u32) func_8080182C_chpiranha,
                                0x0};
// Actor 0x2C2 (aggressive).
int D_80801BA8_chpiranha[18] = {0x2C202FD,
                                0x73F0007,
                                0x0,
                                (u32) func_808002A0_chpiranha,
                                0x0,
                                (u32) func_8080003C_chpiranha,
                                0xFA00000,
                                0x3F800000,
                                0x0,
                                0x1,
                                (u32) func_80800000_chpiranha,
                                0x0,
                                0x0,
                                (u32) func_80800280_chpiranha,
                                (u32) func_80107C2C,
                                -0x7FFFFFFE,
                                (u32) func_8080182C_chpiranha,
                                0x0};
// Actor 0x2C3 (default).
int D_80801BF0_chpiranha[20] = {0x2C302FE,
                                0x73F0007,
                                0x0,
                                (u32) func_808002A0_chpiranha,
                                0x0,
                                (u32) func_8080003C_chpiranha,
                                0xFA00000,
                                0x3F800000,
                                0x0,
                                0x1,
                                (u32) func_80800000_chpiranha,
                                0x0,
                                0x0,
                                (u32) func_80800280_chpiranha,
                                (u32) func_80107C2C,
                                -0x7FFFFFFE,
                                (u32) func_8080182C_chpiranha,
                                0x0,
                                0x0,
                                0x0};
