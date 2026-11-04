#include "common.h"

extern int D_80800E00_chfloaty[];
extern void _chbaddiesetup_entrypoint_6(void *, void *, s32, s32, s32, s32, s32);
extern void _subaddietaxi_entrypoint_16(void);
extern s32 *_chfloaty_entrypoint_0(void);
extern Actor *func_80108528(s32, f32 *, s32, Actor **);
extern void func_801015D0(Actor *);
extern s32 D_80800EA8_chfloaty[];
typedef struct {
    u8 pad_0[0x64];
    u32 pad_64 : 12;
    u32 music_on : 1;
    u32 rest : 19;
} FloatyS;
extern void func_800FCAE0(s32, s32, s32);
extern void func_800FCA90(s32);
extern int D_80800EF0_chfloaty[];
extern s32 _plsu_entrypoint_3(Unk80132ED0 *);
extern void func_800F7BC8(s32, s32, Unk80132ED0 *);
extern s32 func_80101E14(Actor *, f32);
extern void func_80108B04(Actor *, s32);
extern void func_800C4140(s32, f32 *, s32);
extern s32 func_80101DDC(Actor *);
extern void func_800FFA88(Unk80132ED0 *);
extern s32 func_800D90A4(f32 *);
extern s32 func_800DA298(s32);
extern void func_800DA544(s32);
extern void _subaddiedialog_entrypoint_11(Unk80132ED0 *, s32, s32, f32 *, s32);
extern f32 func_800F10B4(f32, f32, f32, f32, f32);
extern f32 func_80013970(f32);
extern f32 mlAbsF(f32);
extern s32 func_8010262C(Unk80132ED0 *, s32);
extern void func_800E0B8C(s32, s32, f32, f32, f32, f32);
extern void func_8010C964(Actor *);
extern s32 func_800F54E4(void);
extern s32 func_800F64A4(s32, s32);
extern s32 _subaddiedialog_entrypoint_4(f32 *, s32, s32);
extern f32 func_8010CD28(Actor *);
extern void func_80102BAC(Actor *, f32, f32, f32);
extern void _subaddieDll_entrypoint_4(Actor *, s32);
extern void _subaddietaxi_entrypoint_5(Actor *, s32);
extern f32 func_800F12D4(f32, f32, f32, f32, f32);
extern void func_800EFE50(f32 *, f32 *, f32 *, f32);
extern s32 D_80800E84_chfloaty[];
extern f32 func_800C6920(f32 *, f32, f32, s32);
extern void func_800F7C0C(s32, s32, f32);
extern void func_800EEB9C(f32 *, f32, f32);
void func_808006AC_chfloaty();
void func_80800CA0_chfloaty();

int *chfloaty_entrypoint_0()
{
    return &D_80800E00_chfloaty;
}

s32 func_8080000C_chfloaty(s32 unk_0, s32 unk_1, s32 unk_2)
{
    return 1;
}

void func_80800020_chfloaty(s32 unk_0[3], s32 unk_1[3], s32 unk_2, s32 unk_3)
{
    _chbaddiesetup_entrypoint_6(&_subaddietaxi_entrypoint_16, unk_0, unk_1[0], unk_1[1],
                                unk_1[2], unk_2, unk_3);
    // Matching: empty block steers IDO's code generation.
    if (unk_0) {
    }
}

void func_8080007C_chfloaty(Actor *actor, f32 unk_1[3])
{
    s32 result;
    s32 next_state;

    func_80102FDC(actor, 0x3F800000);
    result = func_800CB3E0(unk_1);
    switch (result) {
        case 1:
            if (func_800DA298(((u32) *(u16 *) ((char *) actor + 0x76) >> 7) + 0x320) != 0) {
                next_state = 4;
            } else {
                next_state = 1;
            }
            func_808006AC_chfloaty(actor, next_state);
            return;
        case 3:
        case 4:
        case 6:
            func_808006AC_chfloaty(actor, 6);
    }
}

void func_80800BD8_chfloaty();

void func_80800118_chfloaty(Actor *actor)
{
    s32 player;
    f32 scale;
    f32 wobble_a;
    f32 wobble_b;
    s32 bones;
    f32 blend;

    switch (actor->unk70_10) {
        case 1:
            if ((player = _plsu_entrypoint_3(actor->unk0)) != -1) {
                func_800F7BC8(player, 0x53, actor->unk0);
            }
            break;
        case 2:
            if (func_80101E14(actor, 0.47f)) {
                func_80108B04(actor, 0);
                func_800C4140(0x7FFB5D61, actor->position, 0x4B000FA);
            }
            if (func_80101DDC(actor)) {
                func_800FFA88(actor->unk0);
            }
            break;
        case 3:
            if (func_800D90A4(&actor->unk50)) {
                if (!func_800DA298(0x340)) {
                    func_800DA544(0x340);
                    _subaddiedialog_entrypoint_11(actor->unk0, 0x1431, 0xE, actor->position,
                                                  0x6F);
                }
                func_808006AC_chfloaty(actor, 4);
            } else {
                scale = func_800F10B4(actor->unk50, 1.5f, 0.0f, 0.01f, 1.0f);
                wobble_a = func_800F10B4(actor->unk50, 1.5f, 0.75f, 0.0f, 1.0f);
                wobble_b = func_800F10B4(actor->unk50, 0.75f, 0.0f, 0.0f, 1.0f);
                scale = mlAbsF(func_80013970(scale * 720.0f) * 0.25f) + scale;
                wobble_a = mlAbsF(func_80013970(wobble_a * 180.0f) * 2.0f) + wobble_a;
                wobble_b = mlAbsF(func_80013970(wobble_b * 180.0f) * 2.0f) + wobble_b;
                if ((bones = func_8010262C(actor->unk0, 8))) {
                    func_800E0B8C(bones, 0x2A, -1.0f, wobble_a, wobble_a, wobble_a);
                    func_800E0B8C(bones, 0x2D, -1.0f, wobble_b, wobble_b, wobble_b);
                    func_800E0B8C(bones, 0x30, -1.0f, wobble_a, wobble_a, wobble_a);
                    func_800E0B8C(bones, 0x33, -1.0f, wobble_b, wobble_b, wobble_b);
                    func_800E0B8C(bones, 0x39, -1.0f, wobble_a, wobble_a, wobble_a);
                    func_800E0B8C(bones, 0x3C, -1.0f, wobble_b, wobble_b, wobble_b);
                    func_800E0B8C(bones, 0x3F, -1.0f, wobble_a, wobble_a, wobble_a);
                    func_800E0B8C(bones, 0x36, -1.0f, wobble_b, wobble_b, wobble_b);
                }
                actor->scale = scale;
            }
            func_80800BD8_chfloaty(actor, 1);
            func_8010C964(actor);
            break;
        case 4:
            if (func_800F64A4(func_800F54E4(), 10)) {
                if (!func_800DA298(0x6DD) &&
                    _subaddiedialog_entrypoint_4(actor->position, 500, 0)) {
                    func_800DA544(0x6DD);
                    _subaddiedialog_entrypoint_11(actor->unk0, 0x1432, 0xE, actor->position,
                                                  0x6F);
                }
            } else {
                if (!func_800DA298(0x6DE) &&
                    _subaddiedialog_entrypoint_4(actor->position, 500, 0)) {
                    func_800DA544(0x6DE);
                    _subaddiedialog_entrypoint_11(actor->unk0, 0x1433, 0xE, actor->position,
                                                  0x6F);
                }
            }
            actor->unk54 = func_8010CD28(actor);
            func_80102BAC(actor, 0.1f, 0.5, 8.0f);
            func_8010C964(actor);
            func_80800BD8_chfloaty(actor, 1);
            break;
        case 6:
            if (func_800D90A4((f32 *) &actor->actorData[3])) {
                _subaddieDll_entrypoint_4(actor, 0);
                _subaddietaxi_entrypoint_5(actor, actor->unk74_7 - 0x25);
                func_808006AC_chfloaty(actor, 4);
            } else if (7.0f <= *(f32 *) &actor->actorData[3]) {
                blend = func_800F12D4(*(f32 *) &actor->actorData[3], 8.0f, 7.0f, 0.0f, 1.0f);
                actor->scale = blend / 2.0f + 0.5f;
                func_800EFE50(actor->position, (f32 *) &actor->actorData[4],
                              (f32 *) actor->actorData, blend);
                actor->position[1] += func_80013970(blend * 180.0f) * 100.0f;
            }
            if (*(f32 *) &actor->actorData[3] < 1.0f) {
                ((u8 *) actor)[0x9B] =
                    (s32) func_800F12D4(*(f32 *) &actor->actorData[3], 1.0f, 0.0f, 255.0f, 0.0f);
            }
            func_8010C964(actor);
            func_80800BD8_chfloaty(actor, 1);
    }
}

f32 func_80800B68_chfloaty();

void func_808006AC_chfloaty(actor, state) Actor *actor;
int state;
{
    switch (state) {
        case 1:
            func_8010A63C(actor);
            func_80103140(actor, 0x923, *(u16 *) ((u8 *) actor->unk0 + 0x16));
            func_80102FDC(actor, 0x3F800000);
            func_8010A63C(actor);
            break;
        case 2:
            func_800DA544(actor->unk74_7 + 0x320);
            func_8010A624(actor);
            func_8010A570(actor);
            func_800F77E8(func_800F54E4(),
                          (u8 *) &D_80800E84_chfloaty + actor->unk74_7 * 12 - 600);
            break;
        case 3:
            func_80104580(actor);
            actor->unk50 = 1.5f;
            func_80103140(actor, 0x924, *(u16 *) ((u8 *) actor->unk0 + 0x16));
            actor->rotation[1] = func_8010CD28(actor);
            func_80800BD8_chfloaty(actor, 10);
            actor->position[1] = func_800C6920(actor->position, 1000.0f, -1000.0f, 0) + 100.0f;
            break;
        case 4:
            func_80104580(actor);
            func_8010A624(actor);
            func_80103140(actor, 0x924, *(u16 *) ((u8 *) actor->unk0 + 0x16));
            func_80102FDC(actor, 0x3F800000);
            actor->position[1] = func_800C6920(actor->position, 1000.0f, -1000.0f, 0) + 100.0f;
            break;
        case 5:
            func_800F7C0C(func_800F54E4(), 0x6E, func_80800B68_chfloaty((u8 *) actor));
            break;
        case 6:
            func_800CB698(actor->unk74_7 - 0x25, 5);
            func_800EEB9C((f32 *) &actor->actorData[0], actor->rotation[1], 300.0f);
            func_800EF04C((f32 *) &actor->actorData[0], actor->position);
            *(f32 *) &actor->actorData[1] =
                func_800C6920((f32 *) &actor->actorData[0], 1000.0f, -1000.0f, 0) + 100.0f;
            func_800EE7F8((f32 *) &actor->actorData[4], actor->position);
            *(f32 *) &actor->actorData[3] = 8.0f;
            _subaddieDll_entrypoint_4(actor, 1);
    }
    func_80102424(actor, state);
}

s32 func_8080090C_chfloaty(Actor *actor, s32 msg, s32 msg_arg)
{
    Actor *spawned;
    switch (msg) {
        case 0x18:
            if (actor->unk70_10 != 2)
                func_808006AC_chfloaty(actor, 2);
            return 1;
        case 0x44:
            func_8080007C_chfloaty(actor, msg_arg);
            return 1;
        case 0x3E:
            if (func_800DA298(actor->unk74_7 + 0x320) &&
                _subaddietaxi_entrypoint_2(actor, actor->unk74_7 - 0x25))
                func_808006AC_chfloaty(actor, 5);
            return 1;
        case 0x1F:
            func_801015D0(actor);
            switch (actor->unk70_10) {
                case 1:
                    func_800DF744(3, 1);
                    break;
                case 2:
                    func_800DF744(3, 2);
                    break;
            }
            return 1;
        case 0x3D:
            spawned = func_80108528(0x486, actor->position, (s32) actor->rotation[1], &actor);
            func_808006AC_chfloaty(spawned, 3);
            spawned->unk74_7 = actor->unk74_7;
            return 1;
        case 0x95:
            if (_subaddietaxi_entrypoint_13(actor, actor->unk74_7 - 0x25,
                                            _chfloaty_entrypoint_0, 1)) {
                func_80102FDC(actor, 0x3F800000);
                if (!func_800DA298(actor->unk74_7 + 0x320))
                    func_808006AC_chfloaty(actor, 1);
                else
                    func_808006AC_chfloaty(actor, 4);
            } else if (actor->unk7A_5) {
                func_800FFA88(actor->unk0);
                return 1;
            }
            if (*(u16 *) ((u8 *) actor->unk0 + 0x14) == 0x924) {
                func_8010A3E8(actor, 0x3F000000);
                *(s16 *) ((u8 *) actor->unk0 + 0x20) = -80;
            }
            return 1;
        default:
            return 0;
    }
}

f32 func_80800B68_chfloaty(u8 *actor)
{
    s32 index;

    index = ((u32) (u16) *(u16 *) ((s8 *) actor + 0x76) >> 7) - 0x32;
    switch (index) {
        case 0:
            return 15.0f;
        case 1:
            return 15.0f;
        case 2:
            return 15.0f;
        default:
            return 1000.0f;
    }
}

void func_80800BD8_chfloaty(s32 actor, s32 unk_1)
{
    s32 track_copy;
    s32 pos;
    s32 track;

    if (func_8001210C(1) != 0) {
        track = func_800B5BE4(0x1C);
        pos = actor + 4;
        track_copy = track;
        func_800BABB8(track, pos, pos, 0x3F800000, &D_80800EA8_chfloaty);
        func_800BA22C(track_copy, unk_1);
    }
    func_80800CA0_chfloaty(actor);
}

// Stops the proximity music layer (track 0x1C).
void func_80800C4C_chfloaty(FloatyS *floaty)
{
    if (floaty->music_on) {
        func_800FCAE0(0x1C, 0, 0x7D0);
        func_800FCA90(0x1C);
        floaty->music_on = 0;
    }
}

// Proximity music: fades track 0x1C in and out by distance.
void func_80800CA0_chfloaty(actor) Actor *actor;
{
    f32 dist_sq;
    dist_sq = func_8010C710(actor);
    if (dist_sq > 250000.0f) {
        if (actor->unk64_19) {
            func_800FCAE0(0x1C, 0, 2000);
            func_800FCA90(0x1C);
            actor->unk64_19 = 0;
        }
    } else {
        if (actor->unk64_19) {
            func_800FCAE0(0x1C, (s32) func_800F10B4(dist_sq, 0.0f, 250000.0f, 22000.0f, 0), 2000);
        } else if (!actor->unk64_19) {
            func_800FC618(0x1C, (s32) func_800F10B4(dist_sq, 0.0f, 250000.0f, 22000.0f, 0.0f));
            actor->unk64_19 = 1;
        }
    }
}

int chfloaty_entrypoint_1()
{
    return (int) &D_80800EF0_chfloaty;
}

// TU-NOTE: the .data of this overlay is defined here in C. Its tables point to functions of
// this file; IDO schedules some of them differently unless the tables are in the same unit.
// The extern declarations of D_80800E00/E84/EA8/EF0 are adjusted to the object (same addresses).
extern void func_80105834();
extern void func_801018A4();
extern void func_80108ED0();
extern void func_80107C2C();
int D_80800E00_chfloaty[2] = {(u32) func_8080000C_chfloaty, (u32) func_80800020_chfloaty};
u32 D_80800E08_chfloaty[31] = {
    0x0,        0x0,        0x40B00000, 0x1D40009, 0x3F75C28F, 0x1D5004A, 0x3FE66666, 0x4260009,
    0x3FE66666, 0x4260009,  0x3FE66666, 0x4260009, 0x3FE66666, 0x4260009, 0x1D09E6,   0x1B00C8,
    0x15E0016,  0x1000002C, 0x0,        0x0,       0x640000,   0xE0000,   0x460027,   0x64,
    0xC8,       0x220080,   0x190066,   0x990015,  0xF00CC,    0x2B0100,  0x1000000};
s32 D_80800E84_chfloaty[9] = {0x43E10000,  0x444F0000, -0x3BC48000, -0x3A6B9000, 0x45AD1000,
                              -0x3AB62000, 0x456D8000, 0x45DAC000,  0x450C0000};
s32 D_80800EA8_chfloaty[18] = {0x1D09E6, 0x1BFD44, 0x12C002D, 0x6400C8, 0xD001E,  0x161002,
                               0x270000, 0x640000, 0xC80022,  0x0,      0x4C0099, 0x150033,
                               0xB3002B, 0xC00100, 0x40099,   0x70003,  0x31FFF6, -0xA0000};
int D_80800EF0_chfloaty[20] = {0x1580486,
                               0x9240001,
                               (u32) &D_80800E08_chfloaty,
                               (u32) func_80800118_chfloaty,
                               (u32) func_80105834,
                               (u32) func_801018A4,
                               0x7D00000,
                               0x3F800000,
                               0x0,
                               0x800124,
                               (u32) func_80800C4C_chfloaty,
                               (u32) func_80108ED0,
                               0x0,
                               0x0,
                               (u32) func_80107C2C,
                               -0x79FFC000,
                               (u32) func_8080090C_chfloaty,
                               0x0,
                               0x0,
                               0x0};
