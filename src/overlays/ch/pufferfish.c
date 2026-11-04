// Probably the underwater pufferfish baddie: swims around its home, blows bubbles and inflates
// when the player is near. A hit while inflated (or message 0x40) makes it burst into particles.
#include "common.h"

// TU-NOTE: The .data of this overlay is defined here in C (values taken from the ROM). Its tables
// point to functions of this file, and IDO's assembler schedules some of them differently unless
// the tables are defined in the same unit. D_808012A8_chpufferfish is declared as int[].

extern u8 D_8080119C_chpufferfish[];
extern u8 D_808011D0_chpufferfish[];
extern u8 D_80801288_chpufferfish[];
extern u8 D_80801204_chpufferfish[];
extern u8 D_80801238_chpufferfish[];
extern void func_800BBCB8(f32 *, f32 *, f32, s32, void *);
extern void func_80101CDC(Actor *, f32);
extern int func_80107070(void *, s32);
extern void func_80101EE4(Actor *, f32);
extern f32 func_800DC178(f32, f32);
extern void func_800EFA4C(f32 *, f32, f32, f32);
extern s32 _fxairbub_entrypoint_1(f32 *, f32, f32, f32);
extern void func_800BA994(s32, s32, s32, s32, s32, s32, s32);
typedef struct {
    u8 pad_0[0x64];
    u32 unk_64 : 2;
    u32 stick_mode : 1;
    u32 unk_64_rest : 29;
} PufferFishFlags49_80800040_chpufferfish;
typedef struct {
    u32 a : 2;
    u32 stick_mode : 1;
    u32 rest : 29;
} PF64;
extern u8 D_80801298_chpufferfish[];
extern f32 func_80101F24(Actor *);
extern f32 func_800DC0C0(void);
extern f32 func_800F1214(f32, f32, f32);
extern s32 func_80101E14(Actor *, f32);
extern s32 func_800D90A4(f32 *);
extern void _subaddieaudioloop_entrypoint_0(Actor *, f32);
typedef struct {
    u8 pad0[0x70];
    u32 unk70_25 : 7;
    u32 pad70_10 : 15;
    u32 unk70_4 : 6;
    u32 pad70_0 : 4;
} PufferBits;
typedef struct {
    u8 pad0[4];
    f32 unk4;
    u8 pad8[6];
    s16 unkE;
} PufferArea;
typedef struct {
    u8 pad0[0xC];
    f32 unkC;
} PufferData;
extern PufferArea *func_800CC63C(s32, s32);
extern void func_80102950(Actor *, f32);
extern void func_8010CE28(Actor *, f32 *);
extern void func_80102924(Actor *, f32);
extern f32 func_800136E4(f32);
extern s32 _subaddieDll_entrypoint_11(Actor *, s32, s32);
extern f32 func_80102D78(Actor *, PufferArea *);
extern f32 func_800F1DCC(f32, f32);
extern f32 func_800F10B4(f32, f32, f32, f32, f32);
extern void func_80102BAC(Actor *, f32, f32, f32);
extern void func_80102C58(Actor *, f32, f32, f32);
extern f32 func_800F1FF0(f32, f32, f32, f32, f32);
extern f32 func_800F15F8(f32, f32, f32);
extern f32 _subaddiejoy_entrypoint_3(void);
extern f32 func_800F1828(f32 *, f32 *);
void func_8080086C_chpufferfish();
void func_80800518_chpufferfish();
void func_80800AB0_chpufferfish(Actor *actor, s32 mode, f32 speed_min, f32 speed_max);
void func_80800E20_chpufferfish();
void func_80800F30_chpufferfish();

void func_80800000_chpufferfish(u8 *actor)
{
    if (_subaddieDll_entrypoint_1() == 0) {
        func_800FFAB0(actor);
        return;
    }
    *(f32 *) ((s8 *) actor + 0x34) = (f32) *(f32 *) ((s8 *) actor + 0x38);
}

void func_80800274_chpufferfish();

void func_80800040_chpufferfish(Actor *actor)
{
    func_80800518_chpufferfish();
    func_8010D690(actor);
    switch (actor->unk79_4) {
        case 0:
            if (((PufferFishFlags49_80800040_chpufferfish *) actor)->stick_mode) {
                func_80800F30_chpufferfish(actor);
                break;
            }
            func_80800AB0_chpufferfish(actor, 1, 300.0f, 300.0f);
            func_80800E20_chpufferfish(actor);
            if (func_8010BA80(actor, 0x26, 0x10))
                actor->unk54 += 10.0f;
            if (func_8010C500(actor) && actor->unk58 == 0.0f) {
                if (func_8008FCC8(actor->unk0) == 0x14)
                    func_80800274_chpufferfish(actor, 2);
                else
                    func_80800274_chpufferfish(actor, 1);
            }
            break;
        case 1:
            func_80800AB0_chpufferfish(actor, 2, 600.0f, 600.0f);
            func_80800E20_chpufferfish(actor);
            if (func_8010BA80(actor, 0x26, 0x10))
                actor->unk54 += 10.0f;
            if (!func_8010C500(actor))
                func_80800274_chpufferfish(actor, 0);
            break;
        case 2:
            func_80800AB0_chpufferfish(actor, 4, 450.0f, 550.0f);
            func_80800E20_chpufferfish(actor);
            if (func_8010BA80(actor, 0x26, 0x10))
                actor->unk54 += 10.0f;
            if ((!func_8010C500(actor) || func_8008FCC8(actor->unk0) != 0x14) &&
                actor->unk58 == 0.0f)
                func_80800274_chpufferfish(actor, 0);
        case 3:
        case 4:
            break;
    }
}

void func_80800274_chpufferfish(Actor *actor, s32 state)
{
    f32 *pos;
    switch (state) {
        case 0:
            actor->unk58 = 5.0f;
            break;
        case 1:
            break;
        case 3:
            func_8080086C_chpufferfish(actor, 2);
            func_80101CDC(actor, 0.5f);
            func_8010A570(actor);
            break;
        case 4:
            // Explode into particles.
            pos = actor->position;
            _subaddieaudioquick_entrypoint_2(actor, pos, D_80801288_chpufferfish);
            func_800BBCB8(pos, pos, actor->scale, 10, D_80801238_chpufferfish);
            func_800BBCB8(pos, pos, actor->scale, 2, D_8080119C_chpufferfish);
            func_800BBCB8(pos, pos, actor->scale, 16, D_808011D0_chpufferfish);
            func_800BBCB8(pos, pos, actor->scale, 6, D_80801204_chpufferfish);
            if (!func_80107070(actor, 3))
                func_800FFAB0(actor);
    }
    actor->unk79_4 = state;
}

s32 func_808003C8_chpufferfish(u8 *actor, s32 msg, s32 arg)
{
    u32 bits;

    switch (msg) {
        case 0x3E:
            bits = *(u32 *) ((s8 *) actor + 0x70);
            func_80102924(
                actor,
                func_80102D78(actor, func_800CC63C((bits >> 0x19) - 1,
                                                     (s32) ((u32) (bits << 0x16) >> 0x1A) - 1)));
            func_80800274_chpufferfish(actor, 2);
            return 1;
        case 0x40:
            func_80800274_chpufferfish(actor, 3);
            return 1;
        case 0x8F:
            if ((arg == 1) || ((arg != 2) && (arg != 3) && (arg == 4))) {
                func_80800274_chpufferfish(actor, 0);
                func_8080086C_chpufferfish(actor, 1);
            }
            return 1;
        case 0x1:
            func_80800274_chpufferfish(actor, 0);
            if ((s32) ((u32) (u16) *(u16 *) ((s8 *) actor + 0x72) >> 0xA) != 1) {
                func_8080086C_chpufferfish(actor, 4);
            }
            *(f32 *) ((s8 *) actor + 0x2C) = 2.0f;
            return 1;
        case 0x2:
            func_80800274_chpufferfish(actor, 0);
            func_80107070(actor, 1);
            return 1;
        default:
            return 0;
    }
}

void func_8080093C_chpufferfish();

void func_80800518_chpufferfish(actor) Actor *actor;
{
    f32 inflate_t;
    f32 deflate_t;

    switch (actor->unk70_10) {
        case 1:
            if (func_80101F24(actor) > 0.1f && func_80101F24(actor) < 0.7f &&
                func_800DC0C0() < 0.5f) {
                func_8080093C_chpufferfish(actor, 1);
            }
            if (((PF64 *) ((u8 *) actor + 0x64))->stick_mode) {
                if (func_800D90A4((f32 *) &actor->actorData[5]) &&
                    _subaddiejoy_entrypoint_6(actor, 1)) {
                    func_8080086C_chpufferfish(actor, 2);
                }
            } else if (func_800D90A4(&actor->unk58) && func_8010C9B0(actor->position, 500)) {
                func_8080086C_chpufferfish(actor, 2);
            }
            break;
        case 3:
            if (func_80101F24(actor) > 0.1f && func_80101F24(actor) < 0.7f &&
                func_800DC0C0() < 0.5f) {
                func_8080093C_chpufferfish(actor, 1);
            }
            if (((PF64 *) ((u8 *) actor + 0x64))->stick_mode) {
                if (_subaddiejoy_entrypoint_6(actor, 0)) {
                    func_8080086C_chpufferfish(actor, 4);
                }
            } else if (func_80101E14(actor, 0.999f)) {
                func_8080086C_chpufferfish(actor, 4);
            }
            break;
        case 2:
            // Inflating to twice the size.
            inflate_t =func_80101F24(actor);
            actor->scale =
                func_800F1214(inflate_t, *(f32 *) &actor->actorData[7],
                              *(f32 *) &actor->actorData[7] + *(f32 *) &actor->actorData[7]);
            if (func_80101DDC(actor)) {
                _subaddieaudioloop_entrypoint_2(actor);
                if (actor->unk79_4 == 3) {
                    func_80800274_chpufferfish(actor, 4);
                } else {
                    func_8080086C_chpufferfish(actor, 3);
                }
            } else {
                _subaddieaudioloop_entrypoint_4(actor, actor->position, 1,
                                                D_80801298_chpufferfish);
                _subaddieaudioloop_entrypoint_0(actor, func_800F1214(inflate_t, 0.8f, 1.4f));
            }
            break;
        case 4:
            // Deflating back to normal size.
            deflate_t =func_80101F24(actor);
            actor->scale =
                func_800F1214(deflate_t, *(f32 *) &actor->actorData[7],
                              *(f32 *) &actor->actorData[7] + *(f32 *) &actor->actorData[7]);
            if (func_80101E14(actor, 0.1f)) {
                _subaddieaudioloop_entrypoint_2(actor);
                func_8080086C_chpufferfish(actor, 1);
            } else {
                _subaddieaudioloop_entrypoint_4(actor, actor->position, 1,
                                                D_80801298_chpufferfish);
                _subaddieaudioloop_entrypoint_0(actor, func_800F1214(deflate_t, 0.8f, 1.4f));
            }
            func_8080093C_chpufferfish(actor, 1);
    }
}

void func_8080086C_chpufferfish(actor, state) Actor *actor;
s32 state;
{
    s32 prev_state;

    prev_state = actor->unk70_10;
    func_80102424(actor, state);
    switch (state) {
        case 1:
            actor->scale = ((f32 *) actor->actorData)[7];
            break;
        case 2:
            if (prev_state == 1)
                func_80101EE4(actor, 0.0f);
            break;
        case 3:
            actor->scale = 2.0f * ((f32 *) actor->actorData)[7];
            break;
        case 4:
            if (prev_state == 3)
                func_80101EE4(actor, 0.999f);
            actor->unk58 = 5.0f;
            ((f32 *) actor->actorData)[5] = 2.0f;
    }
}

// Spawns an air bubble at skeleton bone 4.
void func_8080093C_chpufferfish(Actor *actor, s32 arg)
{
    f32 bone_pos[3];
    s32 bubble;
    f32 unk_2;
    f32 jitter_y[1];
    f32 jitter_x[1];
    if (_subaddieskeleton_entrypoint_2(actor->unk0, 4, bone_pos)) {
        jitter_x[0] = func_800DC178(-20.0f, 20.0f);
        jitter_y[0] = func_800DC178(-20.0f, 20.0f);

        func_800EFA4C(bone_pos, bone_pos[0] + jitter_x[0], bone_pos[1] + jitter_y[0],
                      bone_pos[2] + func_800DC178(-20.0f, 20.0f));
        bubble = _fxairbub_entrypoint_1(bone_pos, 1.0f, bone_pos[1] + 1000.0f, actor->scale);
        func_800BA994(bubble, (s16) (s32) actor->rotation[0],
                      (s16) (s32) (actor->rotation[1] - 35.0f),
                      (s16) (s32) (*(f32 *) ((u8 *) actor + 0x24) * 1.5f),
                      (s16) (s32) actor->rotation[0], (s32) (actor->rotation[1] + 35.0f),
                      (s32) (*(f32 *) ((u8 *) actor + 0x24) + *(f32 *) ((u8 *) actor + 0x24)));
        func_800BA22C(bubble, arg);
    }
}

void func_80800AB0_chpufferfish(Actor *actor, s32 mode, f32 speed_min, f32 speed_max)
{
    f32 angles[3];
    s32 at_limit;
    PufferArea *area;

    area = func_800CC63C(((PufferBits *) actor)->unk70_25 - 1,
                            ((PufferBits *) actor)->unk70_4 - 1);
    if (area->unk4 + area->unkE <= actor->position[1]) {
        at_limit = 1;
        func_80102950(actor, 355.0f);
    } else if (actor->position[1] <= area->unk4 - area->unkE) {
        at_limit = 1;
        func_80102950(actor, 5.0f);
    } else {
        at_limit = 0;
    }
    if (mode & 6) {
        func_8010CE28(actor, angles);
        if (mode & 2) {
            func_80102924(actor, angles[1]);
        } else {
            func_80102924(actor, func_800136E4(angles[1] - 180.0f));
        }
        angles[0] = func_800136E4(-angles[0]);
        if (25.0f < angles[0] && angles[0] < 180.0f) {
            angles[0] = 25.0f;
        } else if (angles[0] < 335.0f && 180.0f < angles[0]) {
            angles[0] = 335.0f;
        }
        func_80102950(actor, angles[0]);
    }
    if (func_800D90A4((f32 *) &actor->actorData[2])) {
        ((f32 *) actor->actorData)[2] = ((f32 *) actor->actorData)[4] =
            func_800DC178(2.0f, 4.0f);
        ((f32 *) actor->actorData)[0] = func_800DC178(speed_min, speed_max);
        if (!at_limit) {
            func_80102950(actor, func_800DC178(-8.333333f, 8.333333f));
        }
        if (mode & 5) {
            func_80102924(actor, func_800DC178(-35.0f, 35.0f) + actor->rotation[1]);
        }
    }
    if (!_subaddieDll_entrypoint_11(actor, actor->unk54,
                                    actor->scale * 3.0f *
                                        ((PufferData *) actor->actorData)->unkC)) {
        func_80102924(actor, func_80102D78(actor, area));
        ((f32 *) actor->actorData)[2] = ((f32 *) actor->actorData)[4] =
            func_800DC178(2.0f, 4.0f);
    }
    ((f32 *) actor->actorData)[1] = func_800136E4(func_800F10B4(
        func_800F1DCC(actor->rotation[1], actor->unk54), -180.0f, 180.0f, -15.0f, 15.0f));
    func_80102BAC(actor, 0.05f, 0.05f, 4.0f);
    func_80102C58(actor, 0.05f, 0.01f, 0.5f);
    actor->rotation[2] =
        func_800F1FF0(actor->rotation[2], ((f32 *) actor->actorData)[1], 0.01f, 0.005f, 0.1f);
}

void func_80800E20_chpufferfish(actor) Actor *actor;
{
    f32 t;
    f32 target_speed;
    t = func_800F10B4(((f32 *) actor->actorData)[2], ((f32 *) actor->actorData)[4], 0.0f,
                            0.0f, 1.0f);
    if (t < 0.2f) {
        target_speed = func_800F10B4(t, 0.0f, 0.2f, 0.0f, ((f32 *) actor->actorData)[0]);
    } else if (t < 0.5f) {
        target_speed = func_800F10B4(t, 0.2f, 0.5f, ((f32 *) actor->actorData)[0],
                                ((f32 *) actor->actorData)[0] * 0.75f);
    } else {
        target_speed = func_800F10B4(t, 0.5f, 1.0f, ((f32 *) actor->actorData)[0] * 0.75f, 0.0f);
    }
    ((f32 *) actor->actorData)[3] = func_800F15F8(((f32 *) actor->actorData)[3], target_speed, 4.0f);
}

// Stick-controlled variant of the swim movement.
void func_80800F30_chpufferfish(actor) Actor *actor;
{
    f32 unk_0[3];
    f32 stick_speed;
    stick_speed = _subaddiejoy_entrypoint_3() * 300.0f;
    func_8010D254(unk_0);
    actor->unk50 = func_800F1828(actor->position, unk_0);
    if (actor->unk50 > 30.0f && actor->unk50 <= 180.0f)
        actor->unk50 = 30.0f;
    else if (actor->unk50 > 180.0f && actor->unk50 <= 330.0f)
        actor->unk50 = 330.0f;
    if (((f32 *) actor->actorData)[3] <= stick_speed)
        ((f32 *) actor->actorData)[3] = stick_speed;
    else {
        ((f32 *) actor->actorData)[3] -= ((f32 *) actor->actorData)[3] * 0.02f;
        if (((f32 *) actor->actorData)[3] < 30.0f)
            ((f32 *) actor->actorData)[3] = 0.0f;
    }
    ((f32 *) actor->actorData)[0] = ((f32 *) actor->actorData)[3];
    ((f32 *) actor->actorData)[1] = func_800136E4(func_800F10B4(
        func_800F1DCC(actor->rotation[1], actor->unk54), -180.0f, 180.0f, -15.0f, 15.0f));
    func_80102BAC(actor, 0.5f, 0.5, 5.0f);
    func_80102C58(actor, 0.5f, 0.5, 5.0f);
    actor->rotation[2] =
        func_800F1FF0(actor->rotation[2], ((f32 *) actor->actorData)[1], 0.01f, 0.005f, 0.1f);
    func_8010BA80(actor, 0x200006, 0x20);
}

int chpufferfish_entrypoint_0()
{
    extern int D_808012A8_chpufferfish[];
    return &D_808012A8_chpufferfish;
}

extern void func_80105834();
extern void func_80101870();
extern void func_80108ED0();
extern void func_80107C2C();
u32 D_80801160_chpufferfish[5] = {0x10000, 0x10000, 0x10000, 0x10000, 0x10000};
u32 D_80801174_chpufferfish[10] = {0x0,       0x0,        0x3F800000, 0x1C80049,  0x3FB33333,
                                   0x1C9000A, 0x3F400000, 0x1CA0049,  0x3FB33333, 0x1C90012};
u8 D_8080119C_chpufferfish[52] = {0x0,  0x1D, 0x9,  0xDD, 0x0,  0x2B, 0x2,  0x0,  0x4,  0x0,  0x0,
                                  0x22, 0x1,  0x80, 0x2,  0x0,  0x4,  0x80, 0x6,  0x0,  0x0,  0x15,
                                  0x0,  0x0,  0x0,  0x26, 0x0,  0x19, 0x0,  0x0,  0x0,  0x7,  0x0,
                                  0x2D, 0x0,  0x32, 0x0,  0x64, 0x0,  0x20, 0xDE, 0xDE, 0xDE, 0xDE,
                                  0x0,  0xE,  0x0,  0x96, 0x0,  0x96, 0x0,  0x0};
u8 D_808011D0_chpufferfish[52] = {0x0,  0x1D, 0x6,  0xE7, 0x0,  0x14, 0x0,  0x16, 0x14, 0x4,  0x0,
                                  0x2D, 0x1,  0xC2, 0x2,  0x26, 0x0,  0x1B, 0x0,  0x0,  0x0,  0x0,
                                  0x0,  0x22, 0x1,  0x0,  0x1,  0x0,  0x0,  0x80, 0x0,  0x99, 0x0,
                                  0x1E, 0x0,  0x14, 0x0,  0x14, 0x0,  0xE,  0x0,  0x96, 0x0,  0x96,
                                  0x0,  0x15, 0x0,  0x0,  0x0,  0xFD, 0x0,  0x0};
u8 D_80801204_chpufferfish[52] = {0x0,  0x1D, 0x6,  0xF0, 0x0,  0x14, 0x0,  0x16, 0x14, 0x4,  0x0,
                                  0x2D, 0x1,  0xC2, 0x2,  0x26, 0x0,  0x1B, 0x0,  0x0,  0x0,  0x0,
                                  0x0,  0x22, 0x0,  0xCC, 0x0,  0x99, 0x0,  0x66, 0x0,  0x4C, 0x0,
                                  0x1E, 0x0,  0x14, 0x0,  0x14, 0x0,  0xE,  0x0,  0x96, 0x0,  0x96,
                                  0x0,  0x15, 0x0,  0x0,  0x0,  0xFD, 0x0,  0x0};
u8 D_80801238_chpufferfish[80] = {
    0x0, 0x1D, 0x9, 0xD9, 0x0, 0x16, 0x10, 0x4,  0x0, 0x1B, 0x0,  0x96, 0x0,  0x96, 0x0, 0x15,
    0x0, 0x0,  0x0, 0xCC, 0x0, 0x2B, 0x2,  0x0,  0x3, 0x0,  0x0,  0x2C, 0x0,  0x0,  0x0, 0x0,
    0x0, 0x0,  0x0, 0x0,  0x0, 0x64, 0x0,  0x0,  0x0, 0x20, 0xFF, 0xFF, 0xFE, 0xFF, 0x0, 0x22,
    0x0, 0xC,  0x0, 0x17, 0x0, 0xC,  0x0,  0x17, 0x0, 0xE,  0x0,  0x64, 0x0,  0xC8, 0x0, 0x2F,
    0x0, 0x40, 0x0, 0x40, 0x0, 0x0,  0x0,  0x0,  0xA, 0x0,  0x0,  0x0,  0x0,  0x33, 0x0, 0x0};
u8 D_80801288_chpufferfish[16] = {0x0, 0x13, 0x4,  0xFB, 0x0, 0xA,  0x0, 0xCC,
                                  0x0, 0x16, 0x75, 0x30, 0x0, 0x1B, 0x0, 0x0};
u8 D_80801298_chpufferfish[16] = {0x0, 0x13, 0x5, 0xB1, 0x0, 0x1B, 0x0, 0x1,
                                  0x3, 0xE8, 0xB, 0xB8, 0x0, 0x0,  0x0, 0x0};
int D_808012A8_chpufferfish[18] = {0x130029A,
                                   0x6E60001,
                                   (u32) &D_80801174_chpufferfish,
                                   (u32) func_80800040_chpufferfish,
                                   (u32) func_80105834,
                                   (u32) func_80101870,
                                   0x17700000,
                                   0x0,
                                   0x0,
                                   0x200161,
                                   0x0,
                                   (u32) func_80108ED0,
                                   0x0,
                                   (u32) func_80800000_chpufferfish,
                                   (u32) func_80107C2C,
                                   -0x7FBFABF3,
                                   (u32) func_808003C8_chpufferfish,
                                   (u32) &D_80801160_chpufferfish};
