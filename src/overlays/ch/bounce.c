#include "common.h"

// TU-NOTE: the overlay .data is defined here in C (values taken from the ROM). D_80800FE2_chbounce
// and D_80801000_chbounce are linker symbols at D_80800FE0_chbounce + 0x2 and + 0x20.

typedef struct Unk80127188 {
    f32 unk0;
    f32 unk4;
    f32 unk8;
} Unk80127188;
extern Unk80127188 D_80127188;
extern f32 D_8012716C[];
typedef struct {
    u16 flags;
    s16 actor_id;
    s16 count;
    s16 sfx_id;
    f32 unk_8;
    s16 unk_C;
    s16 x_base;
    s16 x_range;
    s16 y_base;
    s16 y_range;
    s16 z_base;
    s16 z_range;
    u8 pad_1A[6];
    f32 angle;
} BE;
typedef struct {
    f32 pos_x;
    f32 pos_y;
    f32 pos_z;
    f32 velocity[3];
    f32 yaw;
    f32 spin;
    f32 age;
    u8 flag80 : 1;
    u8 index : 7;
    u8 unk_25_80 : 1;
    u8 unk_25 : 7;
    u16 state : 3;
    u16 unk_26 : 13;
    s16 sfx_id;
    s16 unk_2A;
    f32 unk_2C;
    s16 bounce_count;
    u16 flags;
} BB;
extern f32 D_808014A8_chbounce;
extern f32 func_800DC178(f32, f32);
extern void func_800EF934(f32 *, f32 *, f32);
extern void func_800EEB9C(f32 *, f32, f32);
extern void func_800EE7F8(void *, void *);
extern u8 *func_80108474(s32, s32, s32);
extern u8 *func_80106790(s32);
extern void func_80100074();
typedef struct {
    u8 pad[0x7B];
    u8 hi : 4;
    u8 f8 : 1;
    u8 lo : 3;
} AX;
typedef struct {
    f32 yaw;
    u8 pad_04[0x20];
} BounceEntry_chbounce_entrypoint_5;
extern BounceEntry_chbounce_entrypoint_5 D_80801000_chbounce[];
extern f32 func_800DC0C0(void);
typedef struct {
    s16 type;
    u8 pad_02[34];
} BounceRecord32;
extern BounceRecord32 D_80800FE2_chbounce[];
extern void *func_80100094(Actor *, u32);
extern f32 func_800EC708(Unk80132ED0 *);
extern s32 func_800BF0E0(f32 *, f32 *, f32, f32 *, s32, u32);
extern s32 func_800C6B78(f32 *, f32 *, f32, f32 *, s32, u32);
typedef struct {
    u8 pad[0x72];
    u16 pa : 6;
    u16 f : 6;
    u16 pb : 4;
} F72;
typedef struct BounceEntry_chbounce_entrypoint_8 {
    u16 flags;
    u8 pad_02[0x10];
    s16 y_base;
    s16 y_range;
    u8 pad_16[0x06];
    f32 damping;
    u8 pad_20[0x04];
} BounceEntry_chbounce_entrypoint_8;
typedef struct BounceLocal {
    f32 pos_x;
    f32 pos_y;
    f32 pos_z;
    f32 velocity[3];
    f32 yaw;
    f32 spin;
    f32 age;
    u8 flag80 : 1;
    u8 index : 7;
    u8 pad_25;
    u16 state : 3;
    u16 unk_26 : 13;
    s16 sfx_id;
    s16 unk_2A;
    f32 unk_2C;
    s16 bounce_count;
    u16 flags;
} BounceLocal;
extern BounceEntry_chbounce_entrypoint_8 D_80800FE0_chbounce[];
extern u8 D_808014AC_chbounce[];
extern f32 func_800D8FF8(void);
extern void func_80104580(void);
extern void func_800EFA20(void *, void *, f32);
extern void func_800EF04C(void *, void *);
extern void func_800EF334(void *, f32);
extern f32 func_800EEAA4(void *, void *);
extern void func_800EFB24(void *, void *, void *);
extern void func_800EFA4C(void *, f32, f32, f32);
extern f32 func_800EEF94(void *);
extern void func_800EF368(void *, f32);
extern void func_8010D930(s32, s32, void *, void *);
extern f32 func_800F10B4(f32, f32, f32, f32, f32);
extern void func_800C4B64(f32);
extern void func_800C4B70();
extern void func_800C4B7C(s32);
extern void func_8010A63C(void *);
extern u8 *func_80105494(void *);
extern f32 mlAbsF(f32);
extern f32 func_800BECCC(void);
extern s32 func_8010108C(void *, s32, s32);
extern void func_800FFAB0(void *);
void chbounce_entrypoint_6();

void func_80800F74_chbounce(u8 *param_0);

void chbounce_entrypoint_0(void)
{
    D_80127188.unk0 = 0.0f;
    D_80127188.unk4 = 1.0f;
    D_80127188.unk8 = 0.00f;
}

void chbounce_entrypoint_1(void)
{
}

void chbounce_entrypoint_2(f32 param_0)
{
    D_8012716C[7] = param_0;
}

void chbounce_entrypoint_3(f32 param_0)
{
    // Matching: the repeated (u8 *) cast is needed for the match.
    *(f32 *) ((u8 *) (u8 *) D_8012716C + 0x24) = param_0;
}

s32 chbounce_entrypoint_4(Actor *this)
{
    f32 vec[3];

    func_800EE84C(vec);
    chbounce_entrypoint_6(this, vec);
}

// Picks the actor to drop: 0x197 / 0x196 (by level ability and RNG) or 0x229 for none.
int func_80800078_chbounce()
{
    f32 roll;
    s32 ability_10;
    s32 ability_12;
    roll = func_800DC0C0();
    ability_10 = _gclevel_entrypoint_3(0x10);
    ability_12 = _gclevel_entrypoint_3(0x12);
    if (func_800D3E40(9))
        return 0x229;
    if (func_800EA068(0x8000))
        return 0x229;
    if (!ability_10 && !ability_12)
        return 0x229;
    if (ability_10) {
        if (!func_800DA9E4(0x31, 1))
            return 0x197;
        if (roll < 0.04998779296875f)
            return 0x197;
    }
    if (ability_12) {
        if (!func_800DA9E4(0x30, 1))
            return 0x196;
        if (roll < 0.04998779296875f)
            return 0x196;
    }
    return 0x229;
}

// Spawns the bouncing actors of table entry type_idx and gives them a random initial velocity.
u8 *func_80800190_chbounce(s32 type_idx, s32 pos, s32 *parent)
{
    BE *entry_dup;
    u8 *actor;
    BE *entry;
    f32 value;
    f32 *vel;
    s32 i;
    s32 first;
    BB *bounce;
    u8 *extra;
    f32 x_val;
    f32 rand_x;
    f32 spin;

    entry = &((BE *) D_80800FE0_chbounce)[type_idx];
    // Matching: the extra copy of entry is needed for the match.
    entry_dup = entry;
    actor = 0;
    if (parent != 0) {
        first = *parent;
    } else {
        first = 0;
    }
    i = 0;
    if (entry->count > 0) {
        do {
            ((f32 *) &D_80127188)[0] = 360.0f / (f32) entry->count + ((f32 *) &D_80127188)[0];
            while (360.0f <= ((f32 *) &D_80127188)[0]) {
                ((f32 *) &D_80127188)[0] = ((f32 *) &D_80127188)[0] - 360.0f;
            }
            if (i == 0 && first != 0) {
                actor = func_80106790(first);
            } else if (entry->actor_id != 0x229) {
                actor = func_80108474(entry->actor_id, pos, 0);
            } else {
                actor = func_80108474(func_80800078_chbounce(entry->actor_id), pos, 0);
                // Matching: the empty tests steer IDO's block structure and register allocation.
                if (first) {
                }
                if (pos) {
                }
            }
            if (actor != 0) {
                func_80100074(actor, 2, 0x34);
                bounce = (BB *) func_80100094(actor, 2);
                ((AX *) actor)->f8 = 1;
                bounce->index = type_idx;
                bounce->state = 1;
                bounce->unk_25 = 1;
                bounce->sfx_id = entry->sfx_id;
                bounce->unk_2C = entry->unk_8;
                bounce->unk_2A = entry->unk_C;
                func_800EE7F8(bounce, actor + 4);
                func_800EE7F8(actor + 4, bounce);
                if (((f32 *) &D_80127188)[1] != 1.0f) {
                    vel = bounce->velocity;
                    func_800EFA4C(vel,
                                  ((f32 *) &D_80127188)[1] * (f32) *(s16 *) ((u8 *) entry + 0xE),
                                  func_800DC178(0.0f, (f32) entry->y_range) + (f32) entry->y_base,
                                  ((f32 *) &D_80127188)[1] * (f32) *(s16 *) ((u8 *) entry + 0x16));
                    ((f32 *) &D_80127188)[1] = 1.0f;
                } else {
                    vel = bounce->velocity;
                    rand_x = func_800DC178(0.0f, (f32) entry->x_range);
                    value = func_800DC178(0.0f, (f32) entry->y_range);
                    func_800EFA4C(vel, (f32) rand_x + entry->x_base, (f32) value + entry->y_base,
                                  func_800DC178(0.0f, (f32) entry->z_range) + (f32) entry->z_base);
                }
                if (entry->flags & 0x400) {
                    x_val = func_800DC178(0.0f, (f32) entry->x_range) + (f32) entry->x_base;
                    func_800EEB9C(vel, ((f32 *) &D_80127188)[2], x_val);
                    bounce->velocity[1] = func_800DC178(0.0f, (f32) entry->y_range) + (f32) entry->y_base;
                } else {
                    spin = D_808014A8_chbounce;
                    spin = spin * -1.0f;
                    bounce->spin = spin;
                    D_808014A8_chbounce = spin;
                    if (entry->flags & 0x20) {
                        value = entry->angle;
                    } else {
                        value = func_800DC178(0.0f, 360.0f);
                    }
                    bounce->yaw = value;
                    *(f32 *) (actor + 0x48) = value;
                    func_800EF934(vel, vel, ((f32 *) &D_80127188)[0] + *(f32 *) (actor + 0x48));
                }
                bounce->age = 0.0f;
                bounce->flag80 = 0;
                bounce->unk_25_80 = 1;
                bounce->flags = entry->flags;
                if (entry->flags & 0x200) {
                    extra = func_80105494(actor);
                    if (extra != 0) {
                        *(f32 *) (extra + 0x1C) = bounce->pos_y;
                    }
                }
            }
            i += 1;
        } while (i < entry_dup->count);
    }
    return actor;
}

void chbounce_entrypoint_5(s32 type_idx, u8 *actor)
{
    D_80801000_chbounce[type_idx].yaw = *(f32 *) (actor + 0x48);
    func_80800190_chbounce(type_idx, actor + 4, actor);
}

void chbounce_entrypoint_6(type_idx, pos) s32 type_idx;
s32 pos;
{
    func_80800190_chbounce(type_idx, pos, 0);
}

s32 chbounce_entrypoint_7(s32 type_idx, s32 pos, s32 actor_id)
{
    s32 actor;
    u8 *bounce;

    D_80800FE2_chbounce[type_idx].type = actor_id;
    actor = func_80800190_chbounce(type_idx, pos, 0);
    bounce = (u8 *) func_80100094(actor, 2);
    switch (actor_id) {
        case 0x1C9:
        case 0x1CA:
        case 0x1CB:
        case 0x1CC:
        case 0x1F4:
            *(s16 *) (bounce + 0x28) = 0x404;
            *(f32 *) (bounce + 0x2C) = 1.8f;
            *(s16 *) (bounce + 0x2A) = 20000;
            break;
        case 0x136:
        case 0x3C6:
            *(s16 *) (bounce + 0x28) = 0x404;
            *(f32 *) (bounce + 0x2C) = 1.8f;
            *(s16 *) (bounce + 0x2A) = 20000;
            break;
        case 0x513:
            *(s16 *) (bounce + 0x28) = 0x3E9;
            *(s16 *) (bounce + 0x2A) = 16000;
            *(f32 *) (bounce + 0x2C) = 1.0f;
            break;
        case 0x517:
            *(s16 *) (bounce + 0x28) = 0x53D;
            *(f32 *) (bounce + 0x2C) = 1.6f;
            *(s16 *) (bounce + 0x2A) = 16000;
        case 0x21F:
            break;
    }
    return actor;
}

s32 func_808007B8_chbounce(Actor *actor, f32 *prev_pos, f32 *pos, f32 *normal, s32 use_map)
{
    s32 hit;
    f32 height;
    u32 actor_bits;
    u32 unk_0;
    s32 saved_state;
    s32 zone;

    if (*(u16 *) ((u8 *) func_80100094(actor, 2) + 0x32) & 0x80) {
        actor_bits = *(u32 *) ((u8 *) actor + 0x70);
        unk_0 = actor_bits >> 25;
        if (unk_0 != 0) {
            zone = func_800CC338(pos, unk_0 - 1, ((actor_bits << 22) >> 26) - 1);
            if (zone == -1) {
                func_800EFB24(normal, pos, prev_pos);
                func_800EF2A0(normal);
                func_800EE7F8(pos, prev_pos);
                return 1;
            }
            ((F72 *) actor)->f = zone + 1;
        }
    }
    height = func_800EC708(actor->unk0) * 0.6666667f;
    prev_pos[1] += height;
    pos[1] += height;
    if (use_map) {
        hit = func_800BF0E0(prev_pos, pos, height, normal, 3, actor->unk14);
        if (!hit) {
            hit = func_800BEF00(prev_pos, pos, normal, actor->unk14);
            if (hit) {
                func_800EF04C(pos, normal);
            }
        }
    } else {
        saved_state = func_8010A698(actor);
        func_8010A654(actor, 0);
        hit = func_800C6B78(prev_pos, pos, height, normal, 3, actor->unk14);
        func_8010A654(actor, saved_state);
        if (!hit) {
            hit = func_800C6A7C(prev_pos, pos, normal, actor->unk14);
            if (hit) {
                func_800EF04C(pos, normal);
            }
        }
    }
    prev_pos[1] -= height;
    pos[1] -= height;
    return hit;
}

// Per-frame update: state 1 = flying (gravity, collision, bounce), state 2 = resting.
void chbounce_entrypoint_8(u8 *actor)
{
    f32 tick;
    BounceLocal *bounce;
    BounceEntry_chbounce_entrypoint_8 *entry;
    f32 prev[3];
    f32 step[3];
    f32 normal[3];
    f32 *vel;
    f32 speed;
    f32 vol;
    u8 *extra;

    func_80104580();
    tick = func_800D8FF8();
    bounce = func_80100094(actor, 2);
    entry = &D_80800FE0_chbounce[bounce->index];

    switch (bounce->state) {
        case 1:
            bounce->age = bounce->age + tick;
            func_800EE7F8(prev, bounce);
            vel = bounce->velocity;
            func_800EFA20(step, vel, tick);
            func_800EF04C(bounce, step);
            if (1.2f < bounce->age) {
                bounce->flag80 = 1;
            }
            if (!((entry->flags & 0x40) && (bounce->age < 1.2f)) &&
                (func_808007B8_chbounce(actor, prev, bounce, normal, entry->flags & 8) ||
                 ((entry->flags & 0x200) && (bounce->velocity[1] < -((entry->y_range / 2) + entry->y_base))))) {
                if (entry->flags & 0x204) {
                    func_800EFA4C(normal, 0.0f, 1.0f, 0.0f);
                }
                func_800EF334(vel, -1.0f);
                speed = func_800EEAA4(vel, normal);
                func_800EF334(normal, speed + speed);
                func_800EFB24(vel, normal, vel);
                bounce->bounce_count += 1;
                if (bounce->sfx_id != 0) {
                    vol = (bounce->flags & 0x2000) ? func_800F10B4((f32) bounce->bounce_count, 1.0f, 4.0f, 1, 0.65f)
                                            : 1.0f;
                    func_800C4B64(bounce->unk_2C * vol);
                    func_800C4B70((s32) ((f32) bounce->unk_2A * vol));
                    func_800C4B7C(bounce->sfx_id);
                    func_8010D930(3, *(s32 *) (actor + 0x70) & 1, bounce, D_808014AC_chbounce);
                }
                func_800EF334(vel, entry->damping);
                speed = func_800EEF94(vel);
                if (800.0f < speed) {
                    speed = 800.0f;
                    func_800EF368(vel, speed);
                }
                if ((speed < 200.0f && normal[1] > 0.75f) || speed < 10.0f) {
                    bounce->state = 2;
                    bounce->flag80 = 1;
                    if (entry->flags & 0x10) {
                        func_8010A63C(actor);
                    }
                }
                if (entry->flags & 0x200) {
                    extra = func_80105494(actor);
                    if (extra != 0) {
                        bounce->pos_y = *(f32 *) (extra + 0x1C);
                    }
                }
            } else {
                if (entry->flags & 0x100) {
                    bounce->velocity[1] -= 4000.0f * tick;
                } else if (entry->flags & 0x800) {
                    bounce->velocity[1] -= 750.0f * tick;
                } else {
                    bounce->velocity[1] -= 1500.0f * tick;
                }
            }
            func_800EE7F8(actor + 4, bounce);
            break;

        case 2:
            if (entry->flags & 2) {
                bounce->yaw += bounce->spin * tick;
                while (bounce->yaw >= 360.0f) {
                    bounce->yaw -= 360.0f;
                }
                while (bounce->yaw < 0.0f) {
                    bounce->yaw += 360.0f;
                }
                *(f32 *) (actor + 0x48) = bounce->yaw;
            }
            if (mlAbsF(bounce->spin) < 0.1f || !(entry->flags & 2)) {
                func_80800F74_chbounce(actor);
            }
    }
    if (*(f32 *) (actor + 8) < func_800BECCC() - 1000.0f) {
        if (func_8010108C(actor, 0x4D, 0) > 0) {
            func_80800F74_chbounce(actor);
        } else {
            func_800FFAB0(actor);
        }
    }
}

int chbounce_entrypoint_9(s32 actor)
{
    return (u8 *) func_80100094(actor, 2) + 0xC;
}

s32 chbounce_entrypoint_10(s32 actor)
{
    return ((u32) *(u32 *) ((s8 *) func_80100094(actor, 2) + 0x24) >> 0x1F) == 0;
}

void func_80800F74_chbounce(u8 *actor)
{
    u8 *actor_alias;
    // Matching: the second pointer to actor is needed for the match.
    actor_alias = actor;
    *(u8 *) (actor_alias + 0x7B) = *(u8 *) (actor + 0x7B) & 0xFFF7;
    func_80100074(actor_alias, 2, 0);
}

BounceEntry_chbounce_entrypoint_8 D_80800FE0_chbounce[34] = {
    0x21,   0x1,  0xF4,  0x0,   0x1,  0x4,  0x4,  0x3F, 0xE6, 0x66, 0x66, 0x4E, 0x20, 0x0,  0x64,
    0x0,    0x32, 0x1F4, 0xFA,  0x0,  0x64, 0x0,  0x32, 0x0,  0x0,  0.6f, 0x0,  0x0,  0x0,  0x0,
    0x2D,   0x2,  0x10,  0x0,   0x1,  0x0,  0x0,  0x3F, 0xA0, 0x0,  0x0,  0x3E, 0x80, 0x0,  0x0,
    0x0,    0x0,  0xC8,  0x0,   0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0.2f, 0x43, 0x9D, 0x80, 0x0,
    0x1,    0x2,  0x29,  0x0,   0x1,  0x3,  0xE9, 0x3F, 0xA0, 0x0,  0x0,  0x46, 0x50, 0x0,  0x32,
    0x0,    0x96, 0x1F4, 0xFA,  0x0,  0x32, 0x0,  0x96, 0x0,  0x0,  0.6f, 0x0,  0x0,  0x0,  0x0,
    0x21,   0x2,  0x29,  0x0,   0x1,  0x3,  0xE9, 0x3F, 0xA0, 0x0,  0x0,  0x46, 0x50, 0x0,  0x0,
    0x0,    0x0,  0x2EE, 0xFA,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0.6f, 0x0,  0x0,  0x0,  0x0,
    0x21,   0x2,  0x29,  0x0,   0x2,  0x3,  0xE9, 0x3F, 0xA0, 0x0,  0x0,  0x46, 0x50, 0x0,  0x32,
    0x0,    0x96, 0x1F4, 0xFA,  0x0,  0x32, 0x0,  0x96, 0x0,  0x0,  0.6f, 0x0,  0x0,  0x0,  0x0,
    0x21,   0x2,  0x29,  0x0,   0x3,  0x3,  0xE9, 0x3F, 0xA0, 0x0,  0x0,  0x46, 0x50, 0x0,  0x32,
    0x0,    0x96, 0x1F4, 0xFA,  0x0,  0x32, 0x0,  0x96, 0x0,  0x0,  0.6f, 0x0,  0x0,  0x0,  0x0,
    0x481,  0x2,  0x29,  0x0,   0x1,  0x4,  0x4,  0x3F, 0x99, 0x99, 0x9A, 0x4E, 0x20, 0x0,  0xFA,
    0x0,    0x0,  0xC8,  0x0,   0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0.6f, 0x0,  0x0,  0x0,  0x0,
    0x481,  0x2,  0x29,  0x0,   0x1,  0x4,  0x4,  0x3F, 0x99, 0x99, 0x9A, 0x4E, 0x20, 0x1,  0x5E,
    0x0,    0x0,  0x15E, 0x0,   0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0.6f, 0x0,  0x0,  0x0,  0x0,
    0x481,  0x2,  0x29,  0x0,   0x1,  0x4,  0x4,  0x3F, 0x99, 0x99, 0x9A, 0x4E, 0x20, 0x1,  0xC2,
    0x0,    0x0,  0x190, 0x0,   0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0.6f, 0x0,  0x0,  0x0,  0x0,
    0x481,  0x2,  0x29,  0x0,   0x1,  0x4,  0x4,  0x3F, 0x99, 0x99, 0x9A, 0x4E, 0x20, 0x2,  0x26,
    0x0,    0x0,  0x1C2, 0x0,   0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0.6f, 0x0,  0x0,  0x0,  0x0,
    0x481,  0x2,  0x29,  0x0,   0x1,  0x4,  0x4,  0x3F, 0x99, 0x99, 0x9A, 0x4E, 0x20, 0x2,  0x8A,
    0x0,    0x0,  0x1F4, 0x0,   0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0.6f, 0x0,  0x0,  0x0,  0x0,
    0x681,  0x2,  0x29,  0x0,   0x1,  0x4,  0x4,  0x3F, 0x99, 0x99, 0x9A, 0x4E, 0x20, 0x0,  0xFA,
    0x0,    0x0,  0xC8,  0x0,   0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0.0f, 0x0,  0x0,  0x0,  0x0,
    0x681,  0x2,  0x29,  0x0,   0x1,  0x4,  0x4,  0x3F, 0x99, 0x99, 0x9A, 0x4E, 0x20, 0x1,  0x5E,
    0x0,    0x0,  0x15E, 0x0,   0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0.0f, 0x0,  0x0,  0x0,  0x0,
    0x681,  0x2,  0x29,  0x0,   0x1,  0x4,  0x4,  0x3F, 0x99, 0x99, 0x9A, 0x4E, 0x20, 0x1,  0xC2,
    0x0,    0x0,  0x190, 0x0,   0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0.0f, 0x0,  0x0,  0x0,  0x0,
    0x681,  0x2,  0x29,  0x0,   0x1,  0x4,  0x4,  0x3F, 0x99, 0x99, 0x9A, 0x4E, 0x20, 0x2,  0x26,
    0x0,    0x0,  0x1C2, 0x0,   0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0.0f, 0x0,  0x0,  0x0,  0x0,
    0x681,  0x2,  0x29,  0x0,   0x1,  0x4,  0x4,  0x3F, 0x99, 0x99, 0x9A, 0x4E, 0x20, 0x2,  0x8A,
    0x0,    0x0,  0x1F4, 0x0,   0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0.0f, 0x0,  0x0,  0x0,  0x0,
    0x480,  0x2,  0x29,  0x0,   0x1,  0x4,  0x4,  0x3F, 0x99, 0x99, 0x9A, 0x4E, 0x20, 0x0,  0xFA,
    0x0,    0x0,  0xC8,  0x0,   0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0.5f, 0x0,  0x0,  0x0,  0x0,
    0x480,  0x2,  0x29,  0x0,   0x1,  0x4,  0x4,  0x3F, 0x99, 0x99, 0x9A, 0x4E, 0x20, 0x1,  0x2C,
    0x0,    0x0,  0xFA,  0x0,   0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0.5f, 0x0,  0x0,  0x0,  0x0,
    0x480,  0x2,  0x29,  0x0,   0x1,  0x4,  0x4,  0x3F, 0x99, 0x99, 0x9A, 0x4E, 0x20, 0x1,  0x90,
    0x0,    0x0,  0x145, 0x0,   0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0.5f, 0x0,  0x0,  0x0,  0x0,
    0x480,  0x2,  0x29,  0x0,   0x1,  0x4,  0x4,  0x3F, 0x99, 0x99, 0x9A, 0x4E, 0x20, 0x2,  0x8A,
    0x0,    0x0,  0x1C2, 0x0,   0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0.5f, 0x0,  0x0,  0x0,  0x0,
    0x480,  0x2,  0x29,  0x0,   0x1,  0x4,  0x4,  0x3F, 0x99, 0x99, 0x9A, 0x4E, 0x20, 0x3,  0xB6,
    0x0,    0x0,  0x1F4, 0x0,   0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0.5f, 0x0,  0x0,  0x0,  0x0,
    0x0,    0x1,  0xC9,  0x0,   0x1,  0x4,  0x18, 0x3F, 0xA0, 0x0,  0x0,  0x3E, 0x80, 0x0,  0x14,
    0x0,    0x1E, 0x1F4, 0x1F4, 0x0,  0x14, 0x0,  0x1E, 0x0,  0x0,  0.6f, 0x0,  0x0,  0x0,  0x0,
    0x0,    0x1,  0xCB,  0x0,   0x1,  0x4,  0x18, 0x3F, 0xA0, 0x0,  0x0,  0x3E, 0x80, 0x0,  0x14,
    0x0,    0x1E, 0x1F4, 0x1F4, 0x0,  0x14, 0x0,  0x1E, 0x0,  0x0,  0.6f, 0x0,  0x0,  0x0,  0x0,
    0x0,    0x1,  0xCC,  0x0,   0x1,  0x4,  0x18, 0x3F, 0xA0, 0x0,  0x0,  0x3E, 0x80, 0x0,  0x14,
    0x0,    0x1E, 0x1F4, 0x1F4, 0x0,  0x14, 0x0,  0x1E, 0x0,  0x0,  0.6f, 0x0,  0x0,  0x0,  0x0,
    0x21,   0x1,  0x97,  0x0,   0x1,  0x3,  0xE9, 0x3F, 0xA0, 0x0,  0x0,  0x46, 0x50, 0x0,  0x0,
    0x0,    0x0,  0x2EE, 0xFA,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0.6f, 0x0,  0x0,  0x0,  0x0,
    0x21,   0x1,  0x96,  0x0,   0x1,  0x3,  0xE9, 0x3F, 0xA0, 0x0,  0x0,  0x46, 0x50, 0x0,  0x0,
    0x0,    0x0,  0x2EE, 0xFA,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0.6f, 0x0,  0x0,  0x0,  0x0,
    0xC80,  0x0,  0x0,   0x0,   0x1,  0x4,  0x4,  0x3F, 0x99, 0x99, 0x9A, 0x4E, 0x20, 0x0,  0xFA,
    0x0,    0x0,  0x3E8, 0x0,   0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0.5f, 0x0,  0x0,  0x0,  0x0,
    0x2400, 0x0,  0x0,   0x0,   0x1,  0x6,  0x29, 0x3F, 0x80, 0x0,  0x0,  0x36, 0xB0, 0x0,  0x32,
    0x0,    0x1E, 0x3E8, 0x32,  0x0,  0x32, 0x0,  0x1E, 0x0,  0x0,  0.5f, 0x0,  0x0,  0x0,  0x0,
    0x1021, 0x2,  0x1F,  0x0,   0x1,  0x3,  0xE9, 0x3F, 0xA0, 0x0,  0x0,  0x3E, 0x80, 0x0,  0x0,
    0x0,    0x0,  0x1F4, 0xFA,  0x0,  0x64, 0x0,  0x32, 0x0,  0x0,  0.6f, 0x0,  0x0,  0x0,  0x0,
    0x1024, 0x2,  0x1F,  0x0,   0x1,  0x3,  0xE9, 0x3F, 0xA0, 0x0,  0x0,  0x3E, 0x80, 0x0,  0x0,
    0x0,    0x0,  0x1F4, 0xFA,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0.6f, 0x0,  0x0,  0x0,  0x0,
    0x1024, 0x2,  0x1F,  0x0,   0x1,  0x3,  0xE9, 0x3F, 0xA0, 0x0,  0x0,  0x3E, 0x80, 0x0,  0x0,
    0x0,    0x0,  0x0,   0x0,   0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0.6f, 0x0,  0x0,  0x0,  0x0,
    0x29,   0x2,  0x1F,  0x0,   0x1,  0x3,  0xE9, 0x3F, 0xA0, 0x0,  0x0,  0x3E, 0x80, 0x1,  0x2C,
    0x0,    0x0,  0x1F4, 0xFA,  0xFE, 0xD4, 0xFF, 0x9C, 0x0,  0x0,  0.6f, 0x43, 0x34, 0x0,  0x0,
    0x29,   0x2,  0x1F,  0x0,   0x1,  0x3,  0xE9, 0x3F, 0xA0, 0x0,  0x0,  0x3E, 0x80, 0xFF, 0x9C,
    0xFF,   0x9C, 0x2EE, 0xFA,  0xFE, 0xD4, 0xFF, 0x9C, 0x0,  0x0,  0.6f, 0x0,  0x0,  0x0,  0x0,
    0x401,  0x2,  0x29,  0x0,   0x1,  0x3,  0xE9, 0x3F, 0xA0, 0x0,  0x0,  0x46, 0x50, 0x1,  0x2C,
    0x0,    0x64, 0x258, 0xFA,  0x1,  0x2C, 0x0,  0x64, 0x0,  0x0,  0.6f, 0x0,  0x0,  0x0,  0x0};
f32 D_808014A8_chbounce = 4e+02f;
u8 D_808014AC_chbounce[20] = {0x0, 0x21, 0x0, 0x1D, 0x0, 0x1E, 0x0, 0x1, 0x0, 0xC8,
                              0xB, 0xB8, 0x0, 0x0,  0x0, 0x0,  0x0, 0x0, 0x0, 0x0};
