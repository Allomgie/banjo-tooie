#include "common.h"

extern int D_80800CB0_sucoasterhit[];
extern u8 *func_80106790(void *);
extern u8 *func_80100094(u8 *, s32);
extern s32 func_800D9058(f32);
extern void _subaddierouteDll_entrypoint_6(Actor *, void *, s32, s32, f32, s32, s32);
typedef struct {
    u8 pad_0[0x78];
    u32 pad_1 : 29;
    u32 unk_78 : 1;
    u32 pad_2 : 2;
} CoasterHitFlags27;
typedef struct {
    u8 pad_0[0x64];
    u32 pad_1 : 2;
    u32 player_controlled : 1;
    u32 pad_2 : 29;
} CoasterHitActive27;
typedef struct {
    u8 pad_0[0x18];
    u8 pad_1 : 4;
    u8 stunned : 1;
    u8 pad_2 : 3;
} CoasterHitState_80800114_sucoasterhit;
typedef struct {
    u8 pad_0[0x78];
    u32 pad_1 : 29;
    u32 unk_78 : 1;
    u32 pad_2 : 2;
} CoasterHitActor;
typedef struct {
    u8 pad[0x78];
    u32 pad78 : 29;
    u32 unk_78 : 1;
    u32 rest : 2;
} CoasterHitState_808001C8_sucoasterhit;
extern int _sucoaster_entrypoint_9(CoasterHitState_808001C8_sucoasterhit *, s32, s32);
typedef struct {
    u8 pad0[0x24];
    u32 kind : 10;
    u32 rest : 22;
} CoasterHitMsg;
extern s32 func_800F0E28();
extern s32 D_80800CC4_sucoasterhit[];
extern s32 _chbaddiesetup_entrypoint_10;
extern s32 func_80108EF4;
extern f32 func_800136E4(f32);
extern f32 func_800DC178(f32, f32);
extern f32 func_800F5F24(s32);
extern f32 func_800EEFD4(f32 *);
extern f32 func_800F1DF4(f32 *, u8 *);
extern f32 func_800EC708(void *);
extern void _chbounce_entrypoint_3(f32);
extern void _chbounce_entrypoint_2(f32);
extern void _chbounce_entrypoint_5(s32, u8 *);
extern void _chbaddiesetup_entrypoint_5(s32 *, s32, s32, f32, s32, s32);
extern void func_800EEB9C(f32 *, f32, f32);
extern void _subaddiejoy_entrypoint_10(u8 *, f32, f32);
typedef struct {
    u8 pad[0x19];
    u8 b7 : 1;
    u8 b6 : 1;
    u8 b5 : 1;
    u8 rest : 5;
} HitFlags;
extern u8 D_80800CE8_sucoasterhit[];
extern u8 D_80800D14_sucoasterhit[];
extern s32 _subaddievolume_entrypoint_0(void *, f32 (*)[3], s32, s32, s32 *);
extern void func_800BABB8(s32, f32 *, f32 *, f32, void *);
extern void func_80103F38(Actor *, f32 *);
typedef struct {
    s16 sound;
    s16 volume;
    s16 pitch;
    s16 pad;
} CoasterHitSoundEntry;
typedef struct {
    u32 header;
    CoasterHitSoundEntry entries[1];
} CoasterHitSoundTable;
extern s16 D_80800CDC_sucoasterhit[];
extern void func_800C31DC(u8, f32);
extern s32 func_800C4350(u8, f32 *, s16 *);
extern void func_800C301C(u8, s32);
extern void func_800C3058(u8, s32);
extern void func_800C3BDC(u8);
extern void func_800C2FDC(u8);

int sucoasterhit_entrypoint_0()
{
    return (int) &D_80800CB0_sucoasterhit;
}

void func_8080000C_sucoasterhit(Unk80132ED0 *collider, u8 *other)
{
    Actor *actor;
    u8 *state;

    actor = func_80106790(collider);
    state = func_80100094(actor, 0);
    if (!((CoasterHitFlags27 *) actor)->unk_78 && !(*((u8 *) actor + 0x74) & 1)) {
        actor->unk6C_0 = func_800D9058(2.0f);
        if (actor->unk70_10 != 2 && actor->unk70_10 != 9 && actor->unk70_10 != 0xE &&
            !((CoasterHitActive27 *) actor)->player_controlled) {
            if (_sucoaster_entrypoint_9(actor, 3, 3) && !(*(u32 *) (other + 0x24) >> 22)) {
                _subaddierouteDll_entrypoint_6(actor, state, state[0x16], 0, 1.0f, 0x46,
                                               0x78);
            }
        }
    }
}

void func_80800114_sucoasterhit(Unk80132ED0 *collider, Unk80132ED0 *other)
{
    Actor *actor;
    CoasterHitState_80800114_sucoasterhit *state;

    actor = func_80106790(collider);
    if (!((CoasterHitActor *) actor)->unk_78) {
        state = func_80100094(actor, 0);
        if (other->unk24 >> 22 == 0x27D) {
            if (actor->unk70_10 != 0xF)
                _sucoaster_entrypoint_9(actor, 0xF, 4);
            state->stunned = 1;
        } else if (func_801021BC(actor, 0xB)) {
            _sucoaster_entrypoint_9(actor, 0xB, 4);
        }
    }
}

void func_808001C8_sucoasterhit(s32 collider, s32 other)
{
    CoasterHitState_808001C8_sucoasterhit *actor = func_80106790(collider);
    if (!actor->unk_78) {
        _sucoaster_entrypoint_9(actor, 0xC, 5);
    }
}

// Returns 7 and doubles the damage for actor 0x27D.
s32 func_80800208_sucoasterhit(s32 actor, CoasterHitMsg *other, s32 unk_2, s32 *damage,
                               s32 *unk_4)
{
    s32 normal = other->kind != 0x27D;
    s32 unk_1 = other->kind == 0;

    if (!normal) {
        *damage *= 2;
        return 7;
    }
    if (*unk_4 == 0) {
        if (*damage != 0 || unk_1) {
            *damage = func_800F0E28(1, *damage, unk_1);
        } else {
            *damage = 0;
        }
    }
    return 0;
}

void func_80800294_sucoasterhit(void *collider, u8 *other, s32 hit)
{
    u8 *actor;
    s32 unk_1;
    s32 knockback;
    s32 damage;
    s32 hit_type;
    s32 flags;
    s32 unk_6;
    s32 unk_7;
    s32 health_loss;
    s32 unk_9;
    u8 *state;
    u32 unk_11;
    f32 knock_angle;
    f32 src_pos[3];
    f32 src_vel[3];
    f32 vel_angle;
    f32 pos_angle;
    u8 *other_actor;
    f32 hit_pos[3];
    f32 spawn[2];
    u8 *entry;

    actor = func_80106790(collider);
    unk_1 = _glhittableDll_entrypoint_10(hit);
    knockback = _glhittableDll_entrypoint_7(hit);
    damage = _glhittableDll_entrypoint_9(hit);
    hit_type = _glhittableDll_entrypoint_6(hit);
    unk_9 = (*(u32 *) (other + 0x24) >> 22) == 0;
    state = func_80100094(actor, 0);
    if (unk_9 == 0 ||
        ((unk_11 = (u32) *(u16 *) (other + 0x1A) >> 5, func_800F70EC(unk_11) != 0) &&
         func_800F6C1C(unk_11) != 0) ||
        _glhittableDll_entrypoint_8(hit) == 0) {
        flags = func_80800208_sucoasterhit(actor, other, &knockback, &damage, &hit_type);
        if (damage != 0) {
            // Matching: empty block needed for the match.
            if (1) {
            }
            if (flags & 1)
                health_loss = damage;
            else
                health_loss = 100 / damage;
            *(u8 *) (actor + hit_type + 0x5C) = func_800F0E28(0, *(u8 *) (actor + hit_type + 0x5C) - health_loss);
            entry = actor + hit_type;
            if (entry[0x5C] != 0 && !(flags & 1) && damage >= 2) {
                knockback = knockback / 2;
            }
            unk_6 = hit_type == 2 && entry[0x5C] == 0;
            if ((flags & 4) && unk_6 == 0) {
                knockback = 0;
            }
            if (knockback != 0) {
                if (_sueggmisc_entrypoint_0(other) != 0) {
                    other_actor = func_80106790(other);
                    _suegg_entrypoint_18(other_actor, src_pos);
                    _suegg_entrypoint_19(other_actor, src_vel);
                } else if (unk_9 != 0) {
                    func_800F57F0((u32) *(u16 *) (other + 0x1A) >> 5, src_pos);
                    func_800F5D70((u32) *(u16 *) (other + 0x1A) >> 5, src_vel);
                    if (func_800EEFD4(src_vel) < 100.0f) {
                        func_800EEB9C(src_vel, func_800F5F24((u32) *(u16 *) (other + 0x1A) >> 5),
                                      200.0f);
                    }
                } else {
                    func_800EC398(other, src_pos);
                    func_800EFD24(src_vel);
                }
                pos_angle = func_800F1DF4(src_pos, actor + 4);
                if (func_800F1EA4(src_vel, &vel_angle) == 0) {
                    vel_angle = pos_angle;
                }
                vel_angle += func_800DC178(-30.0f, 30.0f);
                knock_angle = func_800136E4(vel_angle);
                _chbounce_entrypoint_3(knock_angle);
                _chbounce_entrypoint_2(knock_angle);
                _chbounce_entrypoint_5(knockback + 0xF, actor);
                *(f32 *) (actor + 0x54) = func_800136E4(knock_angle + 180.0f);
                *(f32 *) (actor + 0x48) = *(f32 *) (actor + 0x54);
            }
            // Matching: entry is set early, before unk_7.
            entry = actor;
            unk_7 = (flags & 2) == 0 || unk_6 != 0;
            if (unk_7 != 0) {
                switch (hit_type) {
                    case 2:
                        func_80109600(actor, other);
                        if ((*(u32 *) (other + 0x24) >> 22) == 0x26D) {
                            // Matching: another empty block.
                            if (1) {
                            }
                            _chflamer_entrypoint_1(actor, other);
                        }
                        break;
                    case 1:
                        func_80109600(actor, other);
                        if ((*(u32 *) (other + 0x24) >> 22) == 0x26E) {
                            // Matching: empty block, same trick as above.
                            if (1) {
                            }
                            func_800EC370(other, hit_pos);
                            _chfreezy_entrypoint_1(actor, hit_pos);
                        }
                }
            }
            if (damage != 0 && ((u32) *(u16 *) (actor + 0x72) >> 10) == 9 &&
                ((u32) (*(s32 *) (*(u8 **) actor + 0x18) << 11) >> 28) == 1) {
                func_8010965C(actor);
                ((HitFlags *) state)->b5 = 1;
            }
            entry += hit_type;
            if (entry[0x5C] == 0 || hit_type != 0) {
                if (entry[0x5C] != 0) {
                    hit_type -= 1;
                    entry -= 1;
                }
                if (hit_type != 2) {
                    entry[0x5C] = 0x63;
                }
                if (hit_type == 2 && unk_1 != 0 && func_8010A430(actor) != 0) {
                    spawn[1] = func_800F5F24(func_800F54E4());
                    func_800EB860(&func_80108EF4, actor);
                    spawn[0] = *(f32 *) (actor + 8) + func_800EC708(collider);
                    _chbaddiesetup_entrypoint_5(&_chbaddiesetup_entrypoint_10, unk_1 + 2,
                                                *(s32 *) (actor + 4), spawn[0], *(s32 *) (actor + 0xC),
                                                *(s32 *) &spawn[1]);
                    func_800EB874();
                }
                switch (hit_type) {
                    case 0:
                        func_8080000C_sucoasterhit(*(u8 **) actor, other);
                        break;
                    case 1:
                        func_80800114_sucoasterhit(*(u8 **) actor, other);
                        break;
                    case 2:
                        func_808001C8_sucoasterhit(*(u8 **) actor, other);
                }
            }
            if (unk_7 != 0) {
                func_8010D930(1, *(s32 *) (actor + 0x70) & 1, actor + 4, &D_80800CC4_sucoasterhit);
                _subaddiejoy_entrypoint_10(actor, 1.0f, 0.25f);
            }
        }
    }
}

void func_80800870_sucoasterhit(Actor *actor, u32 *state, s32 sound_idx, s32 play)
{
    CoasterHitSoundTable *table;
    f32 pitch;

    table = (CoasterHitSoundTable *) _sucoasterdata_entrypoint_1(state[6] >> 28);
    if (table->entries[sound_idx].sound) {
        if (play) {
            if (!actor->unk5F) {
                actor->unk5F =
                    func_800C4350(actor->unk5F, actor->position, D_80800CDC_sucoasterhit);
                pitch = func_800DC178(-0.05f, 0.05f);
                pitch += (f32) table->entries[sound_idx].pitch * 0.00390625f;
                func_800C301C(actor->unk5F, table->entries[sound_idx].sound);
                func_800C3058(actor->unk5F, table->entries[sound_idx].volume);
                func_800C31DC(actor->unk5F, pitch);
            }
            if (actor->unk5F) {
                func_800C4350(actor->unk5F, actor->position, 0);
                func_800C3BDC(actor->unk5F);
            }
        } else if (actor->unk5F) {
            func_800C2FDC(actor->unk5F);
            actor->unk5F = 0;
        }
    }
}

s32 func_80800AEC_sucoasterhit();

// Update of the stunned (dizzy) state.
s32 sucoasterhit_entrypoint_1(Actor *actor)
{
    u8 *state;
    s32 stunned;
    s32 stunned_copy;
    s32 dizzy;
    u32 stun_bit;
    state = func_80100094(actor, 0);
    stun_bit = (*(u32 *) (state + 0x18) << 4) >> 31;
    stunned = stun_bit != 0;
    // Matching: extra copies of the flag needed for the match.
    stunned_copy = stunned;
    dizzy = stunned;
    if (!stunned) {
        dizzy = 0;
        if (actor->unk58 > 0.0f)
            dizzy = 1;
    }
    if (stunned_copy)
        actor->unk58 = 0.7f;
    state[0x18] &= ~8;
    func_80800870_sucoasterhit(actor, state, 4, dizzy);
    if (!dizzy) {
        func_80102190(actor, 0);
        _sucoaster_entrypoint_9(actor, 3, 9);
        return 1;
    }
    actor->position[0] += func_8001210C(1) ? -10.0f : 10.0f;
    actor->position[2] += func_8001210C(1) ? 10.0f : -10.0f;
    _sucoaster_entrypoint_22(actor);
    func_80800AEC_sucoasterhit(actor, state);
    return 0;
}

// Spawns a particle ring around the baddie volume.
s32 func_80800AEC_sucoasterhit(Actor *actor, u8 *state)
{
    f32 points[20][3];
    f32 center[3];
    s32 count;
    s32 i;
    s32 particle;
    s32 unk_5;
    unk_5 = state[0x14];
    count = _subaddievolume_entrypoint_0(actor, points, 1, 5, &unk_5);
    state[0x14] = unk_5;
    if (count > 0) {
        func_80103F38(actor, center);
        particle = func_800B5BE4(0x12);
        func_800BABB8(particle, 0, 0, 1.0f, D_80800CE8_sucoasterhit);
    }
    for (i = 0; i < count; i++)
        func_800BABB8(particle, points[i], center, 1.0f, D_80800D14_sucoasterhit);
    return count >= 0;
}

// Heavy stomp: camera shake, rumble and message 0xB6.
void sucoasterhit_entrypoint_2(s32 actor)
{
    if (*(s32 *) ((s8 *) _sucoasterdata_entrypoint_1(
                      (u32) *(u32 *) ((s8 *) func_80100094(actor, 0) + 0x18) >> 0x1C) +
                  0x44) &
        2) {
        func_800E1610(0, 0x41400000, 0x3F59999A, actor + 4);
        func_80018820(0, 0x3FC00000, 0x3ECCCCCD);
        _subaddiejoy_entrypoint_10(actor, 1.5f, 0.6f);
        func_8010108C(actor, 0xB6, 0);
    }
}

// TU-NOTE: the .data of this overlay is defined here in C; its tables hold pointers to functions
// of this file, and IDO's assembler schedules some of them differently otherwise. Values are taken
// from the ROM.
int D_80800CB0_sucoasterhit[5] = {
    (u32) func_8080000C_sucoasterhit, (u32) func_80800114_sucoasterhit,
    (u32) func_808001C8_sucoasterhit, (u32) func_80800294_sucoasterhit, 0x0};
s32 D_80800CC4_sucoasterhit[6] = {0x130417, 0xD010C, 0x1260016, 0x65900001, 0x3201388, 0x0};
s16 D_80800CDC_sucoasterhit[6] = {0x206, 0x1, 0x4E2, 0x9C4, 0x7, 0x0};
u8 D_80800CE8_sucoasterhit[44] = {0x0,  0x1D, 0x9,  0xCD, 0x0,  0x15, 0x0,  0x0, 0x0,  0x4C, 0x0,
                                  0x22, 0x0,  0x19, 0x0,  0x26, 0x0,  0x4C, 0x0, 0x59, 0x0,  0x16,
                                  0x10, 0x0,  0x0,  0x18, 0x0,  0x0,  0x0,  0x4, 0x1E, 0x0,  0x23,
                                  0x0,  0x0,  0x2B, 0x0,  0x40, 0x0,  0x59, 0x0, 0x0,  0x0,  0x0};
u8 D_80800D14_sucoasterhit[28] = {0x0, 0x2D, 0x0, 0xAF, 0x0, 0xFA, 0x0, 0x17, 0x0, 0x80,
                                  0x1, 0x1A, 0x0, 0x0,  0x0, 0x0,  0x0, 0x0,  0x0, 0x0,
                                  0x0, 0x0,  0x0, 0x0,  0x0, 0x0,  0x0, 0x0};
