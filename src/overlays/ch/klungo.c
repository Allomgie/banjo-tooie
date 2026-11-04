#include "common.h"

// TU-NOTE: the overlay's .data is defined in this file; tables holding function pointers must
// be in the same unit, or IDO's assembler schedules those functions differently. The extern
// views of the D_80803xxx tables are adjusted to the object (address-neutral).
// D_808038A0_chklungo is the per-fight table (0x84 bytes per fight, indexed by the map).
extern int D_80803B6C_chklungo[];
extern void _plcamera_entrypoint_8();
extern void _susubgame_entrypoint_0();
extern void _susubgame_entrypoint_1();
extern void _susubgame_entrypoint_12();
extern void func_800F608C();
extern void func_800FFAB0();
extern void func_80109FE8();
extern void *func_80100094(Actor *, s32);
extern u32 func_800F54E4(void);
typedef struct {
    u8 pad_0[0x78];
    u32 pad_1 : 26;
    u32 local_0 : 1;
    u32 pad_2 : 5;
} Mass63KlungoFlags;
typedef struct {
    u8 pad_0[0x70];
    u32 pad_1 : 7;
    u32 local_0 : 1;
    u32 pad_2 : 24;
} KlungoRouteActiveFlag1161;
typedef struct {
    u8 pad_0[8];
    s16 local_0;
} KlungoCompletion;
typedef struct {
    u8 pad_0[6];
    s16 local_0;
    u8 pad_1[8];
    s16 local_1;
    u8 pad_2[8];
    s16 local_2;
} KlungoDrawingState;
extern s32 _subaddiefade_entrypoint_0(Actor *);
extern void func_801017D0(Actor *);
extern void func_80101808(Actor *, void (*)(Actor *));
extern void func_800EFD24(f32 *);
extern f32 func_80102D78(Actor *, f32 *);
extern void _sudeflect_entrypoint_0(u8 *, f32, f32, s32);
extern void _subaddiefade_entrypoint_1(Actor *, s32);
extern f32 func_800DC178(f32, f32);
extern f32 func_800D8FF8(void);
extern u8 D_808038A0_chklungo[];
typedef struct {
    u32 local_0;
    u32 local_1;
} KlungoMatchEntry1358;
typedef struct {
    u8 pad_0[8];
    KlungoMatchEntry1358 local_0[10];
    u8 pad_1[0x2C];
} KlungoMatchRecord1358;
extern int D_80803BE0_chklungo[];
extern int D_80803BEC_chklungo[];
extern int D_80803C0C_chklungo[];
extern int D_80803C2C_chklungo[];
extern int D_80803BFC_chklungo[];
extern int D_80803C1C_chklungo[];
extern s32 D_80803C54_chklungo[];
extern s32 D_80803C3C_chklungo[];
extern s32 func_80101E4C(Actor *, void *);
extern s32 func_80101E14(Actor *, f32);
extern void func_80018820(s32, f32, f32);
extern void _subaddieaudioquick_entrypoint_2(Actor *, f32[3], void *);
typedef union {
    f32 local_0[3];
    s32 local_1[3];
} KlungoPositionWords1590;
extern s32 D_80803C74_chklungo[];
extern s32 D_80803C6C_chklungo[];
extern s32 _subaddieaudioquick_entrypoint_3(Actor *, f32 *, void *, f32);
extern void func_800EE7F8(f32 *, f32 *);
extern void _chbaddiesetup_entrypoint_10(void);
extern void _chbaddiesetup_entrypoint_5(void (*)(void), s32, s32, s32, s32, s32);
extern u8 D_80803C84_chklungo[];
extern s32 D_80803C98_chklungo[];
extern s32 D_80803CA8_chklungo[];
extern s32 D_80803CB8_chklungo[];
extern u8 D_80803CC0_chklungo[];
extern void func_800EEB9C(f32 *, f32, f32);
extern void func_800BABB8(s32, f32 *, f32 *, f32, void *);
extern s32 D_80803CF4_chklungo[];
extern u8 D_80803D04_chklungo[];
extern u8 D_80803D18_chklungo[];
extern u8 D_80803D28_chklungo[];
extern s32 _subaddieaudioloop_entrypoint_3(s32);
extern s32 _plcamera_entrypoint_10(u32);
extern void _plcamera_entrypoint_9(u32, f32 *, f32);
extern s32 func_800F5EF8(u32);
extern s32 func_80110014(s32);
extern void func_80116088(s32, f32 *);
typedef struct {
    u8 pad[0x24];
    f32 f24;
    u8 pad28[0x4A];
    u16 f72 : 6;
    u16 rest : 10;
} KlungoS;
extern f32 func_8010203C(KlungoS *, s32);
extern void func_80101CDC(KlungoS *, f32);
extern s32 D_80803D38_chklungo[];
extern void func_8010D09C(s32, f32 *, f32);
extern s32 func_800C6A7C(f32 *, f32 *, f32 *, u32);
extern s32 func_800CC5F4(s32);
extern f32 *func_800CC63C(s32, s32);
extern f32 func_800EEB40(f32 *, f32 *);
typedef union {
    s32 word;
    Actor *actor;
} KlungoEventOwner;
typedef struct {
    f32 position[3];
    s16 distance;
} KlungoPathPoint;
extern f32 func_800F1DF4(f32 *, f32 *);
extern void func_800EF1B8(f32 *, f32, f32);
extern f32 func_80101F24(Actor *);
extern f32 func_800F12D4(f32, f32, f32, f32, f32);
extern void func_8008FB58(f32 *, f32, f32);
extern void func_800EFE50(f32 *, void *, void *, f32);
extern void _subaddierouteDll_entrypoint_5(Actor *, void *, u16, f32, f32, f32);
extern void _subaddierouteDll_entrypoint_6(Actor *, void *, u16, u32, f32, s32, s32);
extern void _subaddierouteDll_entrypoint_7(Actor *, void *, f32, f32, f32, s32);
extern void func_801058C4(Actor *, s32, f32, s32);
typedef struct {
    u8 pad0[8];
    s16 unk8;
    u8 padA[0x10];
    s16 unk1A;
    s16 unk1C;
    u8 pad1E[0xA];
    s16 unk28;
    s16 unk2A;
    u8 pad2C[0x14];
    s16 unk40;
} KlungoData;
typedef union {
    s32 i;
    struct {
        s16 a;
        s16 b;
    } h;
} KlungoArg;
typedef struct {
    u8 pad0[2];
    u16 unk2;
    u8 pad4[0x80];
} KlungoTbl;
extern KlungoTbl D_808038A4_chklungo[];
extern u8 D_80803A3C_chklungo[];
extern void func_8010A800(Actor *, s32);
extern void func_80108B04(Actor *, s32);
extern void _gcdialogcamera_entrypoint_3();
extern void func_801032B0(Actor *, s32, s32);
extern void func_800FDC28(s32);
extern void _subaddierouteDll_entrypoint_1(Actor *);
extern s32 _suexpression_entrypoint_7(Actor *, s32, s32);
extern void _suexpression_entrypoint_12(s32, f32, f32);
extern void _suexpression_entrypoint_17(s32, s32);
extern void _suexpression_entrypoint_8(Actor *, s32);
extern s32 func_800D395C(void);
typedef struct {
    u8 pad_0[0x1A];
    s16 local_0;
} KlungoReaction;
extern void func_800F4A58(s32, void *, f32);
extern Actor *func_80108528(s32, f32 *, s32, Actor **);
extern Actor *func_801084B0(s32, Actor **);
extern void func_80102FDC(Actor *, f32);
void func_80801910_chklungo();
void func_808020F0_chklungo();
int func_8080242C_chklungo();
s32 func_80802558_chklungo();
s32 func_80802588_chklungo();
void func_8080299C_chklungo();
u8 func_80802DF4_chklungo();
void func_80802FCC_chklungo();
void func_808030A4_chklungo();
int func_80803158_chklungo();
void func_80803208_chklungo();
int func_80803304_chklungo();
f32 *func_80803390_chklungo();
void func_80803464_chklungo();
void func_80801680_chklungo();
void func_80801744_chklungo();
void func_80801964_chklungo();
void func_8080220C_chklungo();
void func_80802B84_chklungo();
extern void func_80107C2C(), func_80108ED0(), func_8080000C_chklungo(), func_808002D0_chklungo(),
    func_8080101C_chklungo(), func_808011B4_chklungo();

// Returns the inline ActorInfo
int *chklungo_entrypoint_0()
{
    return &D_80803B6C_chklungo;
}

// Spawn: picks the fight from the map, skips it if already defeated
void func_8080000C_chklungo(actor) Actor *actor;
{
    u8 *state;
    s32 player;
    state = func_80100094(actor, 0);
    *(s16 *) ((s8 *) state + 8) = func_8080242C_chklungo();
    if (func_800DA298(*(s16 *) ((s8 *) state + 8) + 0x318) != 0) {
        func_800FFAB0(actor);
        return;
    }
    if (_glcutDll_entrypoint_20() != 0) {
        func_801032B0(actor, 0x90C, 0);
        func_80801964_chklungo(actor, 0xA);
        return;
    }
    func_80109FE8(actor, 0);
    _subaddierouteDll_entrypoint_3(actor, state + 0x7C, actor->position);
    _susubgame_entrypoint_0(actor, (state + 0x88), 0);
    _susubgame_entrypoint_12((state + 0x88), (s32 *) D_80803A3C_chklungo);
    _susubgame_entrypoint_1(actor, (state + 0x88), 0xC);
    func_808020F0_chklungo(actor, 0);
    *(f32 *) ((s8 *) actor + 0x24) =
        (f32) *(f32 *) ((D_808038A0_chklungo + 0x70) + *(s16 *) (state + 8) * 0x84);
    *(s16 *) ((s8 *) state + 2) = 1;
    *(s16 *) ((s8 *) state + 4) = 0;
    *(s16 *) ((s8 *) state + 0) = (s16) *(s16 *) ((s8 *) state + 2);
    *(s16 *) ((s8 *) state + 0x10) = func_80802DF4_chklungo(actor);
    if (*(s16 *) ((s8 *) state + 8) == 0) {
        *(s16 *) ((s8 *) state + 0x22) = 0;
    } else {
        *(s16 *) ((s8 *) state + 0x22) = 1;
    }
    if (((Mass63KlungoFlags *) actor)->local_0) {
        ((KlungoRouteActiveFlag1161 *) actor)->local_0 = 1;
        *(s16 *) ((s8 *) state + 0x2C) = _glsplinefind_entrypoint_0(0x3A1, state + 0x30);
        _subaddiemarker_entrypoint_0(actor, 0x3A1, state + 0x4C, 1);
        _subaddiemarker_entrypoint_0(actor, 0x154, (state + 0x64), 1);
        if (func_800DA298(*(s16 *) ((D_808038A0_chklungo + 0x2) + *(s16 *) (state + 8) * 0x84)) !=
            0) {
            player = func_800F54E4();
            *(s16 *) ((s8 *) state + 0x2A) = 1;
            func_800F608C(player, 1);
            func_800F8294(player, (state + 0x64));
            func_800F497C(player);
            _plcamera_entrypoint_8(player);
            func_80802588_chklungo(actor, 2, 1);
            func_80803158_chklungo(
                actor, *(s16 *) ((D_808038A0_chklungo + 0x76) + *(s16 *) (state + 8) * 0x84),
                0xE);
            func_80801964_chklungo(actor, 8);
            *(s16 *) ((s8 *) state + 0x42) = 1;
            return;
        }
        if (func_800D395C() != 0) {
            if (*(s16 *) ((s8 *) state + 8) == 2) {
                func_80803158_chklungo(actor, 0x1633, 0x44);
                func_80801964_chklungo(actor, 2);
            }
            func_80801964_chklungo(actor, 5);
            return;
        }
        _chintrotext_entrypoint_2(1);
        if (*(s16 *) ((s8 *) state + 8) == 2) {
            func_80801964_chklungo(actor, 2);
        }
    }
}

s32 func_808034CC_chklungo();

f32 func_808031E4_chklungo();

void func_8080318C_chklungo();

void func_80802B10_chklungo();

void func_80802940_chklungo();

void func_80802914_chklungo();

void func_808028E8_chklungo();

void func_80802864_chklungo();

void func_80802798_chklungo();

void func_808026CC_chklungo();

void func_808025CC_chklungo();

void func_808018D4_chklungo();

s32 func_80801888_chklungo();

// Update: per-state behaviour, state in actor->unk70_10
void func_808002D0_chklungo(actor) Actor *actor;
{
    extern u8 D_80803BB4_chklungo[];

    char *state;
    char *expression;
    f32 dt;
    f32 home_y;
    f32 progress;
    f32 scale;
    f32 blend;
    f32 target[3];
    f32 unk_0;
    f32 angle;

    state = (char *) func_80100094(actor, 0);
    expression = (char *) func_80100094(actor, 1);

    func_800D9078(state + 0xC);
    func_8080220C_chklungo(actor);

    switch (actor->unk70_10) {
        case 1:
            func_80801888_chklungo(actor);
            func_80801910_chklungo(actor);
            func_808026CC_chklungo(actor);

            if (func_8010CA74((char *) actor + 4, *(s16 *) ((D_808038A0_chklungo + 0x7C) +
                                                              *(s16 *) (state + 8) * 0x84))) {
                if (func_800F64A4(func_800F54E4(), 1)) {
                    func_80801964_chklungo(actor, 5);
                }
            }
            break;

        case 2:
            func_80801888_chklungo(actor);

            if (func_8010CA74((char *) actor + 4, *(s16 *) ((D_808038A0_chklungo + 0x7C) +
                                                              *(s16 *) (state + 8) * 0x84))) {
                if (func_800F64A4(func_800F54E4(), 1)) {
                    func_80803158_chklungo(actor, 0x1633, 0x44);
                    func_80801964_chklungo(actor, 5);
                }
            }
            break;

        case 3:
            dt = func_800D8FF8();

            *(f32 *) ((char *) actor + 0x34) -= dt * 1000.0f;

            *(f32 *) ((char *) actor + 8) += dt * *(f32 *) ((char *) actor + 0x34);

            home_y = *(f32 *) (state + 0x3C);

            if (*(f32 *) ((char *) actor + 8) < home_y) {
                *(f32 *) ((char *) actor + 8) = home_y;
                func_80801964_chklungo(actor, 4);
                func_80802940_chklungo(actor);
            }
            break;

        case 4:
            if (func_80101DDC(actor)) {
                func_80801964_chklungo(actor, 8);
            }
            break;

        case 5:
            if (*(s16 *) (state + 0x40) != 0) {
                break;
            }

        case 6:
        case 8:
            func_80801888_chklungo(actor);
            func_808026CC_chklungo(actor);
            break;

        case 27:
            func_808026CC_chklungo(actor);
            break;

        case 7:
            func_80801888_chklungo(actor);
            func_808026CC_chklungo(actor);

            if (!func_800DA298(0x6AD)) {
                func_80802588_chklungo(actor, 3, 1);

                func_80803158_chklungo(
                    actor,
                    *(s16 *) ((D_808038A0_chklungo + 0x74) + *(s16 *) (state + 8) * 0x84), 0xE);

                func_80801964_chklungo(actor, 8);
            }
            break;

        case 9:
            func_80802634_chklungo(actor);

            if (func_80101DDC(actor)) {
                func_800FDC28(0xB);

                func_800DA544(
                    *(s16 *) ((D_808038A0_chklungo + 0x2) + *(s16 *) (state + 8) * 0x84));

                _gcfrontend_entrypoint_9(
                    *(s16 *) ((u8 *) D_808038A4_chklungo + *(s16 *) (state + 8) * 0x84));

                func_800DA544(*(s16 *) (state + 0x10) + 0xC07);

                switch (*(s16 *) (state + 0x10)) {
                    case 1:
                        func_80801964_chklungo(actor, 0xB);
                        func_80803158_chklungo(actor, 0x1624, 4);
                        break;
                    case 2:
                        func_80801964_chklungo(actor, 0x10);
                        func_80803158_chklungo(actor, 0x1625, 4);
                        break;
                    case 3:
                        func_80801964_chklungo(actor, 0x14);
                        func_80803158_chklungo(actor, 0x1626, 4);
                }
            }
            break;

        case 10:
            func_808026CC_chklungo(actor);
            break;

        case 11:
            progress = func_80101F24(actor);

            scale = func_800F12D4(progress, 0.0f, 1.0f, 1.0f, 2.5f);

            scale *= *(f32 *) ((char *) actor + 0x38);

            func_8008FB58((char *) actor + 4, scale * 80.0f, scale * 100.0f);

            func_80802864_chklungo(actor);

            if (func_80101DDC(actor)) {
                *(f32 *) (state + 0xC) = func_800DC178(
                    *(f32 *) (D_808038A0_chklungo + *(s16 *) (state + 8) * 0x84 + 0x60),
                    *(f32 *) (D_808038A0_chklungo + *(s16 *) (state + 8) * 0x84 + 0x64));

                func_80802558_chklungo(actor);
                func_80801964_chklungo(actor, 0xC);
            }
            break;

        case 12:
            func_80801888_chklungo(actor);
            func_808026CC_chklungo(actor);

            if (*(f32 *) (state + 0xC) == 0.0f) {
                func_808018D4_chklungo(actor);
                func_80801964_chklungo(actor, 0xF);

                if (*(u8 *) (state + 0x49) == 0) {
                    *(u8 *) (state + 0x49) = 1;
                    func_808025CC_chklungo(actor, 4);
                }
            } else if (func_800D9078((char *) actor + 0x58)) {
                func_80801964_chklungo(actor, 0xD);
            }
            break;

        case 13:
            progress = func_80101F24(actor);

            blend = func_800F12D4(progress, 0.0f, 0.5f, 0.0f, 1.0f);

            func_800EFE50((char *) actor + 4, (char *) actor + 0x28, (char *) actor + 0x18,
                          blend);

            func_80802B10_chklungo(actor);

            if (func_80101DDC(actor)) {
                if (*(f32 *) (state + 0xC) == 0.0f) {
                    func_808018D4_chklungo(actor);
                    func_80801964_chklungo(actor, 0xF);

                    if (*(u8 *) (state + 0x49) == 0) {
                        *(u8 *) (state + 0x49) = 1;
                        func_808025CC_chklungo(actor, 4);
                    }
                } else {
                    func_80801964_chklungo(actor, 0xC);
                }
            }
            break;

        case 14:
            if (func_80101DDC(actor)) {
                func_80801964_chklungo(actor, 0xF);
            }
            break;

        case 15:
            func_808028E8_chklungo(actor);

            if (*(u8 *) (state + 0x12) != 0) {
                func_80801910_chklungo(actor);
            }

            if (func_80101DDC(actor)) {
                if (*(u8 *) (state + 0x12) != 0) {
                    func_80801964_chklungo(actor, 0x1D);
                } else {
                    if (*(s16 *) (state + 0x22) != 0) {
                        func_80802558_chklungo(actor);
                    }

                    func_80801964_chklungo(actor, 0x1C);
                }
            }
            break;

        case 16:
            func_808026CC_chklungo(actor);

            if (_subaddiefade_entrypoint_0(actor) == 0) {
                func_80802558_chklungo(actor);

                *(f32 *) (state + 0xC) = func_800DC178(
                    *(f32 *) (D_808038A0_chklungo + *(s16 *) (state + 8) * 0x84 + 0x60),
                    *(f32 *) (D_808038A0_chklungo + *(s16 *) (state + 8) * 0x84 + 0x64));

                func_80801964_chklungo(actor, 0x11);
            }
            break;

        case 17:
            func_8080318C_chklungo(actor);
            func_80803208_chklungo(actor);

            if (*(f32 *) (state + 0xC) == 0.0f) {
                func_808020F0_chklungo(actor, 5);
                func_80801964_chklungo(actor, 0x1C);
            }

            unk_0 = func_808031E4_chklungo(actor);

            _subaddierouteDll_entrypoint_7(actor, state + 0x7C,
                                           *(f32 *) ((char *) actor + 0x48),
                                           *(f32 *) ((char *) actor + 0x54), unk_0, 0x4802);

            _subaddierouteDll_entrypoint_6(actor, state + 0x7C, *(u16 *) (state + 0x82), 0x3F,
                                           0.7f, 0x28, 0x64);

            _subaddierouteDll_entrypoint_5(actor, state + 0x7C, *(u16 *) (state + 0x82),
                                           0.15f, 4.0f, 120.0f);

            func_8010B990(actor, 0x1305);
            break;

        case 18:
            if (func_80101DDC(actor)) {
                if (*(u8 *) (state + 0x12) != 0) {
                    func_80801964_chklungo(actor, 0x1D);
                } else {
                    func_80802558_chklungo(actor);
                    func_80801964_chklungo(actor, 0x1C);
                }
            }
            break;

        case 19:
            func_800EFD24(target);

            *(f32 *) ((char *) actor + 0x54) = func_80102D78(actor, target);

            _subaddierouteDll_entrypoint_5(actor, state + 0x7C, 0, 0.15f, 4.0f, 120.0f);

            func_8010B990(actor, 0x1305);
            func_80803208_chklungo(actor);

            if (func_808034CC_chklungo(actor)) {
                func_80109FE8(actor, 1);
                func_80801964_chklungo(actor, 0x14);
            }
            break;

        case 20:
            func_808026CC_chklungo(actor);
            break;

        case 21:
        case 22:
            func_80802914_chklungo(actor);

            if (func_80101DDC(actor)) {
                if (!_subaddieskeleton_entrypoint_0(actor, 3, actor->position) ||
                    func_800CBD84(actor->position) == -1) {
                    if (actor->unk70_10 == 0x15) {
                        angle = 90.0f;
                    } else {
                        angle = -90.0f;
                    }

                    func_800EF1B8((char *) actor + 4,
                                  *(f32 *) ((char *) actor + 0x48) + angle, 150.0f);
                }

                func_80101180(0x41E, 0xA, 0);
                func_80801964_chklungo(actor, 0x17);
            }
            break;

        case 23:
            func_8080318C_chklungo(actor);
            func_80803208_chklungo(actor);

            if (*(f32 *) (state + 0xC) == 0.0f && *(s16 *) (state + 0x1A) == 0) {
                func_80101180(0x41E, 0x2C, 0);
            }

            unk_0 = func_808031E4_chklungo(actor);

            _subaddierouteDll_entrypoint_7(actor, state + 0x7C,
                                           *(f32 *) ((char *) actor + 0x48),
                                           *(f32 *) ((char *) actor + 0x54), unk_0, 0x4802);

            _subaddierouteDll_entrypoint_6(actor, state + 0x7C, *(u16 *) (state + 0x82), 0x3F,
                                           0.6f, 0x28, 0x3C);

            _subaddierouteDll_entrypoint_5(actor, state + 0x7C, *(u16 *) (state + 0x82),
                                           0.15f, 4.0f, 120.0f);

            func_8010B990(actor, 0x1325);
            break;

        case 24:
            if (func_80101DDC(actor)) {
                func_80801964_chklungo(actor, *(u8 *) (state + 0x12) ? 0x1D : 0x1A);
            }
            break;

        case 26:
            func_80801888_chklungo(actor);
            func_808026CC_chklungo(actor);

            if (_subaddiefind_entrypoint_9(0x41E) == 1) {
                func_80109FE8(actor, 1);
                func_80801964_chklungo(actor, 0x1C);
            }
            break;

        case 28:
            func_80801888_chklungo(actor);

            if (func_80101E14(actor, 0.75f)) {
                func_80108B04(actor, 0);
            }

            if (*(s16 *) (state + 6) == 1) {
                *(s16 *) (state + 6) = *(s16 *) (state + 6) + 1;
            }

            if (func_80101E14(actor, 0.999f)) {
                *(s16 *) (state + 2) = *(s16 *) (state + 2) - 1;

                if (*(s16 *) (state + 2) == 0) {
                    switch (*(s16 *) (state + 0x10)) {
                        case 1:
                            func_80801964_chklungo(actor, 0xB);
                            break;
                        case 2:
                            func_80801964_chklungo(actor, 0x10);
                            break;
                        case 3:
                            func_80801964_chklungo(actor,
                                                   func_808034CC_chklungo(actor) ? 0x14 : 0x13);
                    }

                    func_80101180(0x421, 0x2C, 0);
                    *(s16 *) (state + 0x44) = 0;
                }

                *(s16 *) (state + 6) = 0;
            }
            break;

        case 29:
            func_80801910_chklungo(actor);
            func_80802798_chklungo(actor);

            if (func_80101DDC(actor)) {
                func_80801964_chklungo(actor, 0x1E);
            }
            break;

        case 31:
            func_80801910_chklungo(actor);

            if (func_800D9078((char *) actor + 0x58)) {
                func_80801964_chklungo(actor, 0x20);
            }
            break;

        case 32:
            func_80801910_chklungo(actor);

            _subaddieaudioquick_entrypoint_3(actor, (char *) actor + 4, D_80803BB4_chklungo,
                                             0.2f);

            if (func_80101DDC(actor)) {
                func_80801964_chklungo(actor, 0x21);
            }
            break;

        case 33:
            func_80801910_chklungo(actor);
            func_808026CC_chklungo(actor);

            if (func_800D9078((char *) actor + 0x58)) {
                func_80801964_chklungo(actor, 0x22);
            }
            break;

        case 34:
            func_808026CC_chklungo(actor);
            func_80801910_chklungo(actor);
            break;

        case 35:
            func_80801910_chklungo(actor);

            *(s16 *) (state + 0x20) = *(s16 *) (state + 0x20) + 1;

            if (*(s16 *) (state + 0x20) == 1) {
                angle = *(f32 *) (state + 0x5C);

                *(f32 *) ((char *) actor + 0x54) = angle;
                *(f32 *) ((char *) actor + 0x48) = angle;

                func_800EE7F8((char *) actor + 4, state + 0x30);

                func_801058C4(actor, *(s16 *) (state + 0x2C), 3e+02f, 1);

                func_80105BAC(actor);
            }
    }

    func_808030A4_chklungo(actor);

    if (expression != 0) {
        if (func_801022E4(actor) != 0x264) {
            _suexpression_entrypoint_18(expression, 1);
        }

        _suexpression_entrypoint_10(expression, *(s32 *) ((char *) actor + 0), 0);
    }
}

// Free: on defeat, leaves via the replay menu or starts the Cauldron Keep cutscene
void func_8080101C_chklungo(actor) Actor *actor;
{
    void *expression;

    expression = func_80100094(actor, 1);
    func_80105834(actor);
    func_80803208_chklungo(actor);
    func_80801910_chklungo(actor);
    if (func_80105A5C(actor)) {
        func_80802558_chklungo(actor);
        if (func_800D395C()) {
            _gcfrontend_entrypoint_10();
        } else if (((KlungoCompletion *) func_80100094(actor, 0))->local_0 == 2) {
            _glcutDll_entrypoint_6(0x15D, 0x5B);
        }
        func_800FFAB0(actor);
    }
    if (expression)
        _suexpression_entrypoint_10(expression, actor->unk0, 0);
}

// Extra draw effects (fade overlay)
void func_808010E0_chklungo(Actor *actor, s32 unk_1)
{
    KlungoDrawingState *state;

    state = func_80100094(actor, 0);
    func_801015D0(actor);
    switch (actor->unk70_10) {
        case 9:
            func_800DF744(3, state->local_1);
            break;
        case 0x1C:
            func_800DF744(3, state->local_0 == 2 ? 0 : 4);
            break;
        default:
            func_800DF744(3, 0);
            break;
    }
    if (state->local_2) {
        func_800DF5D8(0xE0, 0xE0, 0xFF, _subaddiefade_entrypoint_0(actor));
    }
}

void func_808011B4_chklungo(actor, unk_1) Actor *actor;
s32 unk_1;
{
    switch (actor->unk70_10) {
        case 0xD:
        case 0x15:
        case 0x16:
            func_800DF440(0);
            break;
        default:
            func_800DF440(1);
    }
    func_80101808(actor, func_801017D0);
}

s32 func_80801848_chklungo();

// Message handler: returns 1 if handled, 0 if not
s32 func_80801220_chklungo(Actor *actor, s32 msg, KlungoArg arg)
{
    KlungoData *state;
    s32 expression;
    KlungoArg *arg_ptr;

    state = func_80100094(actor, 0);
    switch (msg) {
        case 0x2E:
            arg_ptr = &arg;
            func_80801744_chklungo(actor, arg_ptr->h.a, arg_ptr->h.b);
            break;
        case 0xB:
            switch (func_80802480_chklungo(actor, arg.i)) {
                case 2:
                    func_80801964_chklungo(actor, 9);
                    return 4;
                case 6:
                    func_80801964_chklungo(actor, 0x1F);
                    return 4;
            }
            return 3;
        case 0x40:
            arg_ptr = &arg;
            func_80801680_chklungo(actor, arg_ptr->i);
            break;
        case 0x3D:
            func_80802B84_chklungo(actor, arg.i);
            break;
        case 0x2C:
            if (state->unk1A) {
                func_80801964_chklungo(actor, 0x19);
                break;
            }
            func_8010A800(actor, 0);
            if (arg.i) {
                break;
            }
            if (state->unk28 == 0) {
                state->unk28 = 1;
                func_80803158_chklungo(actor, 0x1631, 0x44);
            }
            func_80801964_chklungo(actor, 0x1A);
            break;
        case 0xA:
            if (state->unk1A) {
                return 0;
            }
            if (state->unk1C == 0) {
                func_80802558_chklungo(actor);
                func_80801964_chklungo(actor, 0x17);
                func_8010A800(actor, 0);
                return 0;
            }
            state->unk1C--;
            func_80108B04(actor, 2);
            break;
        case 0x52:
            _gcdialogcamera_entrypoint_3(D_80803A3C_chklungo, *(s32 *) &actor->scale);
            break;
        case 0x32:
            if (state->unk40 == 0) {
                func_80801964_chklungo(actor, 7);
            }
            break;
        case 0x57:
            return func_80801848_chklungo(actor, arg.i & 0xFFFF,
                                          (arg.i & 0xFFFF0000) >> 16);
        case 0x95:
            func_801032B0(actor, D_808038A4_chklungo[state->unk8].unk2, 0);
            if (state->unk2A) {
                func_800FDC28(1);
                state->unk2A = 0;
            }
            _subaddierouteDll_entrypoint_1(actor);
            break;
        case 0x29:
            if (state->unk1A == 0) {
                expression = _suexpression_entrypoint_7(actor, 1, 0xAB);
                _suexpression_entrypoint_12(expression, 70.0f, 30.0f);
                _suexpression_entrypoint_17(expression, 1000);
            }
            break;
        case 0x2A:
            if (state->unk1A == 0) {
                _suexpression_entrypoint_8(actor, 1);
            }
            break;
        case 0x1F:
            arg_ptr = &arg;
            func_808010E0_chklungo(actor, arg_ptr->i);
            break;
        case 0x96:
            if (state->unk1A || !func_800D395C()) {
                return 0;
            }
            func_80803158_chklungo(actor, 0xCEB, 0x4E);
            break;
        case 0x9F:
            if (state->unk1A) {
                func_80801964_chklungo(actor, 0x19);
                return 0;
            }
            func_800FDC28(0);
            func_80801964_chklungo(actor, 8);
            break;
        default:
            return 0;
    }
    return 1;
}

s32 func_8080162C_chklungo(actor)
s32 actor;
{
    s32 state;

    state = func_80100094(actor, 0);
    func_80802FCC_chklungo(actor);
    func_80802558_chklungo(actor);
    if (*(s16 *) ((char *) state + 0x1A) == 0) {
        _suexpression_entrypoint_8(actor, 1);
    }
}

void func_80801680_chklungo(actor, unk_1) Actor *actor;
s32 unk_1;
{
    KlungoReaction *state;

    state = func_80100094(actor, 0);
    switch (actor->unk70_10) {
        case 12:
        case 13:
            func_80801964_chklungo(actor, 14);
            break;
        case 16:
        case 17:
            func_80801964_chklungo(actor, 18);
            break;
        case 23:
            if (state->local_0 == 0) {
                func_80801964_chklungo(actor, 24);
                func_800FC6B0(14);
                func_80101180(0x41E, 0x2C, 1);
            } else {
                func_800FC6B0(15);
                func_80101180(0x41E, 0x2C, 0);
            }
    }
}

// Dialog finished: switches state depending on the dialog id
void func_80801744_chklungo(actor, dialog_id, choice) Actor *actor;
s32 dialog_id;
s32 choice;
{
    switch (dialog_id) {
        case 0x1622:
        case 0x1623:
        case 0x1628:
        case 0x1629:
        case 0x162B:
        case 0x162C:
            func_80801964_chklungo(actor, 6);
            break;
        case 0x1627:
        case 0x162A:
        case 0x162D:
            func_80801964_chklungo(actor, 35);
            break;
        case 0x162F:
            func_80802558_chklungo(actor);
            func_80801964_chklungo(actor, 28);
            break;
        case 0x1633:
            func_80803158_chklungo(actor, 0x1634, 0x4E);
            func_808025CC_chklungo(actor, 1);
            func_80801964_chklungo(actor, 3);
            break;
        case 0x1634:
            func_80801964_chklungo(actor, 7);
            break;
        case 0xCEB:
            if (choice > 0)
                _gcfrontend_entrypoint_11();
            else
                _gcfrontend_entrypoint_10();
        case 0x1624:
        case 0x1625:
        case 0x1626:
        case 0x1630:
        case 0x1631:
        case 0x1632:
        case 0x1635:
        case 0x1636:
        case 0x1637:
            break;
        default:
            func_80801964_chklungo(actor, 1);
    }
}

s32 func_80801848_chklungo(s32 actor, s32 arg_lo, s32 arg_hi)
{
    s32 state = func_80100094(actor, 0);
    _susubgame_entrypoint_3(actor, state + 0x88, arg_lo, arg_hi);
}

s32 func_80801888_chklungo(Actor *this)
{
    f32 target[3];

    func_8010D600(target);
    *(f32 *) ((char *) this + 0x54) = func_80102D78(this, target);
    return func_80102BF8(this, 0x3e19999a, 0x40800000, 0x43480000);
}

void func_808018D4_chklungo(u8 *actor)
{
    f32 target[3];
    f32 yaw;

    func_800EFD24(target);
    yaw = func_80102D78(actor, target);
    *(f32 *) (actor + 0x54) = yaw;
    *(f32 *) (actor + 0x48) = yaw;
}

void func_80801910_chklungo(actor) u8 *actor;
{
    _sudeflect_entrypoint_0(actor + 4, *(f32 *) (actor + 0x38) * 100.0f,
                            *(f32 *) (actor + 0x38) * 130.0f, 2);
}

void func_8080322C_chklungo(u8 *param_0, f32 param_1);

void func_80803000_chklungo();

void func_80802F30_chklungo();

// Enters new_state and runs its entry actions.
void func_80801964_chklungo(actor, new_state) Actor *actor;
s32 new_state;
{
    extern u8 D_80803A2C_chklungo[];
    extern u8 D_80803BC0_chklungo[];
    extern u8 D_80803BD0_chklungo[];
    extern void func_8010D5DC(void);

    s32 prev_state;
    s32 unk_0;
    s32 unk_1;
    char *data;
    s32 camera;
    f32 side;

    prev_state = actor->unk70_10;
    unk_0 = 0;
    unk_1 = 0;

    data = (char *) func_80100094(actor, 0);

    func_80102424(actor, new_state);
    func_8080305C_chklungo(actor);

switch (new_state) {
    case 2:
        *(f32 *) (data + 0x3C) = *(f32 *) ((char *) actor + 8);
        *(s16 *) (data + 0x40) = 1;
        *(f32 *) ((char *) actor + 8) += 2500.0f;
        break;

    case 5:
        camera = func_800F54E4();

        func_808025CC_chklungo(actor, 0);
        func_800F497C(camera);
        func_800F49A8(camera, 1);

        func_800F49D4(camera, func_8010D5DC,

                      *(s32 *) ((char *) actor + 0));

        func_800F4A58(camera, data + 0x64, *(s16 *) (data + 0x40) ? 0xDC : 0x12C);

        func_800FDC28(1);
        break;

    case 6:
        if (*(s16 *) (data + 0x42) != 0) {
            func_80801964_chklungo(actor, 9);
        } else {
            func_808025CC_chklungo(actor, 2);
        }

        func_80101180(0x41F, 8, 0);
        break;

    case 7:
        _chintrotext_entrypoint_1(0x18B9, *(s16 *) (data + 8) + 0xB, 1, 0);
        break;

    case 9:
        func_808025CC_chklungo(actor, 3);
        break;

    case 12:
        *(f32 *) ((char *) actor + 0x58) =
            func_800DC178(*(f32 *) (D_808038A0_chklungo + *(s16 *) (data + 8) * 0x84 + 0x68),
                          *(f32 *) (D_808038A0_chklungo + *(s16 *) (data + 8) * 0x84 + 0x6C));

        if (prev_state == 0xB) {
            *(f32 *) ((char *) actor + 0x58) = 1.0f;
        }

        unk_0 = 1;
        break;

    case 13:
        side = 0.0f;
        switch (*(s16 *) (data + 8)) {
            case 0:
                side = -1.0f;
                break;
            case 1:
                break;
            case 2:
                side = 1.0f;
                break;
        }

        _subaddieaudioquick_entrypoint_2(actor, (char *) actor + 4, D_80803BC0_chklungo);

        func_8080322C_chklungo(actor, side);

        func_800EE7F8((char *) actor + 0x28, (char *) actor + 4);

        unk_0 = 1;
        break;

    case 14:
        *(s16 *) (data + 4) = *(s16 *) (data + 4) + 1;

        if (*(s16 *) (data + 4) == 3) {
            *(u8 *) (data + 0x12) = 1;
        }

        if (*(u8 *) (data + 0x49) == 0 || *(u8 *) (data + 0x12) != 0) {
            *(u8 *) (data + 0x49) = 1;
            func_808018D4_chklungo(actor);
            func_808025CC_chklungo(actor, 4);
        }

        func_80802FCC_chklungo(actor);

        _subaddieaudioquick_entrypoint_2(actor, (char *) actor + 4, D_80803A2C_chklungo);
        break;

    case 15:
        if (prev_state != 0xE && *(s16 *) (data + 0x26) == 0) {
            func_80803158_chklungo(actor, 0x1632, 0x44);

            *(s16 *) (data + 0x26) = 1;
        }
        break;

    case 16:
        func_80802F30_chklungo(actor);
        func_808020F0_chklungo(actor, 1);
        break;

    case 17:
        *(f32 *) ((char *) actor + 0x24) =
            *(f32 *) ((D_808038A0_chklungo + 0x70) + *(s16 *) (data + 8) * 0x84);

        *(f32 *) ((char *) actor + 0x54) = *(f32 *) ((char *) actor + 0x48);

        unk_0 = 1;
        break;

    case 18:
        *(s16 *) (data + 4) = *(s16 *) (data + 4) + 1;

        if (*(s16 *) (data + 4) == 3) {
            *(u8 *) (data + 0x12) = 1;
        }

        func_80802FCC_chklungo(actor);

        _subaddieaudioquick_entrypoint_2(actor, (char *) actor + 4, D_80803A2C_chklungo);

        func_808020F0_chklungo(actor, 5);
        break;

    case 19:
    case 26:
        func_80109FE8(actor, 0);
        break;

    case 20:
        switch (*(s16 *) (data + 4)) {
            case 0:
                *(s16 *) (data + 0x1C) = 1;
                break;
            case 1:
                *(s16 *) (data + 0x1C) = 2;
                break;
            case 2:
                *(s16 *) (data + 0x1C) = 3;
                break;
        }

        *(s16 *) (data + 0x1C) = *(s16 *) (data + 0x1C) - 1;

        func_80108B04(actor, 2);
        func_8010A800(actor, 2);
        break;

    case 23:
        *(f32 *) (data + 0xC) =
            func_800DC178(*(f32 *) (D_808038A0_chklungo + *(s16 *) (data + 8) * 0x84 + 0x60),
                          *(f32 *) (D_808038A0_chklungo + *(s16 *) (data + 8) * 0x84 + 0x64));

        unk_0 = 1;
        break;

    case 24:
        *(s16 *) (data + 4) = *(s16 *) (data + 4) + 1;

        if (*(s16 *) (data + 4) == 3) {
            *(u8 *) (data + 0x12) = 1;
        }

        func_80802FCC_chklungo(actor);

        _subaddieaudioquick_entrypoint_2(actor, (char *) actor + 4, D_80803A2C_chklungo);
        break;

    case 25:
        func_8010A570(actor);
        _subaddiefade_entrypoint_3(actor);
        func_8010A800(actor, 2);
        break;

    case 28:
        if (*(s16 *) (data + 0x22) == 0) {
            func_80801964_chklungo(actor, 0x1B);
            func_808025CC_chklungo(actor, 9);

            func_80803158_chklungo(actor, 0x162F, 0xE);

            func_80108B04(actor, 1);

            *(s16 *) (data + 0x22) = 1;
        } else {
            unk_1 = 1;

            if (!func_800DA298(0x685)) {
                switch (*(s16 *) (data + 4)) {
                    case 0:
                        *(s16 *) (data + 0) = *(s16 *) (data + 2) = 3;
                        break;
                    case 1:
                        *(s16 *) (data + 0) = *(s16 *) (data + 2) = 5;
                        break;
                    case 2:
                        *(s16 *) (data + 0) = *(s16 *) (data + 2) = 7;
                }
            } else {
                *(s16 *) (data + 2) = 10000;
                *(s16 *) (data + 0) = *(s16 *) (data + 2);
            }

            *(s16 *) (data + 6) = 0;

            if (*(s16 *) (data + 0x44) == 0) {
                func_80108B04(actor, 1);
            }
        }
        break;

    case 29:
        func_800FDC28(0);
        func_80802FCC_chklungo(actor);

        _subaddieaudioquick_entrypoint_2(actor, (char *) actor + 4, D_80803BD0_chklungo);

        func_808018D4_chklungo(actor);
        func_808025CC_chklungo(actor, 5);
        func_8010A570(actor);

        func_80101180(0x423, 0x4F, 0);

        func_800DA544(*(s16 *) (data + 8) + 0x318);
        break;

    case 30:
        func_808025CC_chklungo(actor, 6);
        func_80101180(0x41F, 7, 0);
        func_80101180(0x420, 7, 0);
        break;

    case 31:
        func_808025CC_chklungo(actor, 7);
        *(f32 *) ((char *) actor + 0x58) = 1.4f;
        break;

    case 33:
        *(f32 *) ((char *) actor + 0x58) = 3.0f;
        break;

    case 34:
        func_80802588_chklungo(actor, 3, 1);

        func_80803158_chklungo(
            actor, *(s16 *) ((D_808038A0_chklungo + 0x78) + *(s16 *) (data + 8) * 0x84), 0xE);
        break;

    case 35:
        func_808025CC_chklungo(actor, 8);

        func_80803158_chklungo(
            actor, *(s16 *) ((D_808038A0_chklungo + 0x7A) + *(s16 *) (data + 8) * 0x84), 0x44);
}

func_80109FE8(actor, unk_0);

if (unk_1 != 0) {
    func_80803000_chklungo(actor);
}

}

// Sets the fade state; states 2 and 4 pick a random wait time.
void func_808020F0_chklungo(actor, fade_state) Actor *actor;
s32 fade_state;
{
    u8 *data;
    data = func_80100094(actor, 0);
    *(s16 *) (data + 0x18) = fade_state;

switch (fade_state) {
    case 0:
        _subaddiefade_entrypoint_1(actor, 255);
        break;
    case 2:
        switch (*(s16 *) (data + 8)) {
            case 0:
                *(f32 *) (data + 0x14) = func_800DC178(1.0f, 2.0f);
                break;
            case 1:
                *(f32 *) (data + 0x14) = func_800DC178(2.0f, 3.0f);
                break;
            case 2:
                *(f32 *) (data + 0x14) = func_800DC178(3.0f, 4.0f);
                break;
        }
        break;
    case 4:
        *(f32 *) (data + 0x14) = func_800DC178(1.5f, 2.0f);
}

}

void func_80802F58_chklungo();

s32 func_808023A4_chklungo(Actor *param_0, f32 param_1, f32 param_2);

s32 func_8080231C_chklungo(Actor *param_0, f32 param_1, f32 param_2);

// Fade cycle: out, wait, partly in, wait; state 5 fades fully in.
void func_8080220C_chklungo(actor) Actor *actor;
{
    u8 *data;
    data = (u8 *) func_80100094(actor, 0);

switch (*(u16 *) (data + 0x18)) {
    case 0:
        break;
    case 1:
        if (func_8080231C_chklungo(actor, 0.0f, 150.0f))
            func_808020F0_chklungo(actor, 2);
        break;
    case 2:
        if (func_800D9078((f32 *) (data + 0x14))) {
            func_80802F58_chklungo(actor);
            func_808020F0_chklungo(actor, 3);
        }
        break;
    case 3:
        if (func_808023A4_chklungo(actor, 48.0f, 150.0f))
            func_808020F0_chklungo(actor, 4);
        break;
    case 4:
        if (func_800D9078((f32 *) (data + 0x14)))
            func_808020F0_chklungo(actor, 1);
        break;
    case 5:
        if (func_808023A4_chklungo(actor, 255.0f, 150.0f))
            func_808020F0_chklungo(actor, 0);
}

}

// Fades alpha down to target_alpha; returns 1 when reached.
s32 func_8080231C_chklungo(Actor *actor, f32 target_alpha, f32 speed)
{
    s32 reached;
    f32 alpha;

    reached = 0;
    alpha = (f32) _subaddiefade_entrypoint_0(actor);
    alpha -= func_800D8FF8() * speed;

if (alpha < target_alpha) {
    alpha = target_alpha;
    reached = 1;
}

_subaddiefade_entrypoint_1(actor, (s32) alpha);
return reached;
}

// Fades alpha up to target_alpha; returns 1 when reached.
s32 func_808023A4_chklungo(Actor *actor, f32 target_alpha, f32 speed)
{
    s32 reached;
    f32 alpha;

    reached = 0;
    alpha = (f32) _subaddiefade_entrypoint_0(actor);
    alpha += func_800D8FF8() * speed;

if (target_alpha < alpha) {
    alpha = target_alpha;
    reached = 1;
}

_subaddiefade_entrypoint_1(actor, (s32)alpha);
return reached;
}

// Matching: the line breaks in this function are needed for the match.
// Returns the fight index (0..2) for the current map, or -1.
int func_8080242C_chklungo()
{
    s32 map_id;
    s32 fight;
    do { map_id = func_800EA05C(); fight = 0; while (1) { if (map_id == (*((s16 *) (((char *) D_808038A0_chklungo) + ((22 * fight) * 6))))) { return fight; } fight += 1; if (fight == 3) { return -1; } } } while (0);
}

// Returns the index of id in the current fight's entry table, or -1.
int func_80802480_chklungo(Actor *actor, u32 id)
{
    s16 *data;

    s32 i;

    data = func_80100094(actor, 0);
    for (i = 0; i < 10; i++) {

if (id ==
    (&((KlungoMatchRecord1358 *) D_808038A0_chklungo)[data[4]])->local_0[i].local_0) {
    return i;
}

}
return -1;
}

s32 func_80802558_chklungo(actor)
s32 actor;
{
    s32 data;

    data = func_80100094(actor, 0);
    _susubgame_entrypoint_4(actor, data + 0x88);
}

s32 func_80802588_chklungo(actor, unk_0, unk_1)
s32 actor;
s32 unk_0;
s32 unk_1;
{
    s32 data;
    s32 unk_2;

    data = func_80100094(actor, 0);
    // Matching: extra temporary for the constant argument.
    unk_2 = 0;
    _susubgame_entrypoint_5(actor, data + 0x88, unk_0, unk_1, unk_2);
}

// Passes entry `index` of the current fight's table to the boss framework.
void func_808025CC_chklungo(Actor *actor, s32 index)
{
    u8 *data;
    s32 *entry;
    s32 id;
    s32 arg;

    data = func_80100094(actor, 0);
    entry = (s32 *) (D_808038A0_chklungo + *(s16 *) (data + 8) * 0x84 + index * 8);
    arg = entry[3];
    id = entry[2];
    _susubgame_entrypoint_6(actor, data + 0x88, id, arg, 0);
}

int func_80802634_chklungo(s32 actor)
{
    s32 actor_addr;
    // Matching: `| 0` is needed for the match.
    actor_addr = actor | 0;
    _subaddieaudioquick_entrypoint_3(actor_addr, actor_addr + 4, &D_80803BE0_chklungo, 0.2f);
    _subaddieaudioquick_entrypoint_3(actor_addr, actor_addr + 4, &D_80803BEC_chklungo, 0.78f);
    _subaddieaudioquick_entrypoint_4(actor_addr, actor_addr + 4, &D_80803C0C_chklungo,
                                     &D_80803C2C_chklungo);
    _subaddieaudioquick_entrypoint_4(actor_addr, actor_addr + 4, &D_80803BFC_chklungo,
                                     &D_80803C1C_chklungo);
}

void func_808026CC_chklungo(Actor *actor)
{
    if (func_80101E4C(actor, &D_80803C54_chklungo)) {
        func_80018820(0, 0.8f, 0.3f);
        func_800E15CC(0, 0x40A00000, 0x3F333333);
        _subaddieaudioquick_entrypoint_2(actor, actor->position, &D_80803C3C_chklungo);
        return;
    }
    if (func_80101E14(actor, 0.7f)) {
        func_80018820(0, 1.0f, 0.4f);
        func_800E15CC(0, 0x41200000, 0x3F4CCCCD);
        _subaddieaudioquick_entrypoint_2(actor, actor->position, &D_80803C3C_chklungo);
    }
}

void func_80802798_chklungo(Actor *actor)
{
    KlungoPositionWords1590 spawn_pos;

    _subaddieaudioquick_entrypoint_3(actor, actor->position, &D_80803C74_chklungo, 0.7f);
    if (_subaddieaudioquick_entrypoint_3(actor, actor->position, &D_80803C6C_chklungo, 0.8f)) {
        func_800EE7F8(spawn_pos.local_0, actor->position);
        spawn_pos.local_0[1] += 80.0f;
        _chbaddiesetup_entrypoint_5(_chbaddiesetup_entrypoint_10, 5, spawn_pos.local_1[0],
                                    spawn_pos.local_1[1], spawn_pos.local_1[2],
                                    *(s32 *) &actor->rotation[1]);
        func_80018820(0, 1.0f, 0.4f);
        func_800E15CC(0, 0x41200000, 0x3F4CCCCD);
    }
}

void func_80802864_chklungo(Actor *actor)
{
    u8 *data;

    if (func_80101E14(actor, 0.0f)) {
        data = func_80100094(actor, 0);

if (data[0x48] == 0) {
    data[0x48] = _subaddieaudioquick_entrypoint_1(actor, actor->position);
}

func_800C4350(data[0x48], actor->position, D_80803C84_chklungo);
func_800C3BDC(data[0x48]);
}
}

void func_808028E8_chklungo(u8 *actor)
{
    _subaddieaudioquick_entrypoint_3(actor, actor + 4, &D_80803C98_chklungo, 0.0f);
}

void func_80802914_chklungo(u8 *actor)
{
    _subaddieaudioquick_entrypoint_3(actor, actor + 4, &D_80803CA8_chklungo, 0.0f);
}

void func_80802940_chklungo(s32 actor)
{
    func_8080299C_chklungo(actor);
    func_80018820(0, 1.0f, 0.4f);
    func_800E15CC(0, 0x41200000, 0x3F4CCCCD);
    _subaddieaudioquick_entrypoint_2(actor, actor + 4, &D_80803CB8_chklungo);
}

// Emits a ring of 8 particles around the actor.
void func_8080299C_chklungo(actor) Actor *actor;
{
    s32 emitter;
    s32 i;
    u8 *data;
    f32 offset[2];
    f32 *pos;
    data = func_80100094(actor, 0);
    emitter = func_800B53A4(8);
    func_800BAB80(emitter, D_808038A0_chklungo + *(s16 *) (data + 8) * 0x84 + 0x7E);
    pos = actor->position;
    for (i = 0; i < 8; i++) {
        func_800EEB9C(offset, i * 45.0f, func_800DC178(120.0f, 160.0f));
        func_800EF04C(offset, pos);
        offset[1] += func_800DC178(10.0f, 50.0f);
        func_800BABB8(emitter, offset, pos, 1.0f, &D_80803CC0_chklungo);
    }
}

void func_80802B10_chklungo(Actor *actor)
{
    if (func_80101E14(actor, 0.8f)) {
        func_8080299C_chklungo(actor);
        func_800E15CC(0, 0x41F00000, 0x3F666666);
        func_80018820(0, 1.5f, 0.6f);
        _subaddieaudioquick_entrypoint_2(actor, actor->position, &D_80803CF4_chklungo);

}
}

void func_80802B84_chklungo(actor, kind) Actor *actor;
s32 kind;
{
    u8 *data;
    Actor *projectile;
    f32 hand_pos[3];
    s32 pad;
    f32 spawn_pos[3];
    Actor *other;
    data = func_80100094(actor, 0);
    switch (kind) {
        case 0:
            if (!_subaddieskeleton_entrypoint_2(*(u32 *) actor, 4, hand_pos)) {
                func_80103DFC(actor, hand_pos);
            }

projectile = func_80108528(0x422, hand_pos, (s32) *(f32 *) ((u8 *) actor + 0x48), &actor);
*(f32 *) ((u8 *) projectile + 0x44) = 180.0f;

if (func_800DA298(0x683)) {
    *(f32 *) ((u8 *) projectile + 0x24) =
        *(f32 *) ((D_808038A0_chklungo + 0x58) + *(s16 *) (data + 8) * 0x84);
} else {

*(f32 *) ((u8 *) projectile + 0x24) = 0.3f;
}
if (!func_800DA298(0x684)) {
    *(f32 *) ((u8 *) projectile + 0x58) =
        *(f32 *) ((D_808038A0_chklungo + 0x5C) + *(s16 *) (data + 8) * 0x84);
} else {
    *(f32 *) ((u8 *) projectile + 0x58) = 0.2f;
}
func_80102FDC(projectile, actor->scale);
*(s16 *) (data + 6) = 1;
return;
case 1:
    func_80103DFC(actor, spawn_pos);
    func_80102FDC(func_80108528(0x421, spawn_pos, 0, &actor), actor->scale * 1.4f);
    *(s16 *) (data + 0x44) = 1;
    return;
case 2: {
    u8 *other_data;

if (actor->unk70_10 != 0x14) {
    func_8010A800(actor, 0);
    return;
}

other = func_801084B0(0x41E, &actor);

if ((*(u32 *) ((u8 *) other + 0x70) >> 25) == 0) {
    func_800FFAB0(other);
    func_80101180(0x41E, 0xA, 0);
    return;
}

other_data = func_80100094(other, 0);
*(s16 *) (data + 0x1E) ^= 1;
*(s16 *) (other_data + 0x1A) = 1;
func_80100120(other);
func_80102FDC(other, actor->scale);
func_80801964_chklungo(other, *(s16 *) (data + 0x1E) == 0 ? 0x16 : 0x15);
}
}
}

// Returns the saved variant (1..6) for this fight, choosing and saving one if unset.
u8 func_80802DF4_chklungo(actor)
Actor *actor;
{
    s32 fight;
    s32 variant;
    s32 pick;
    s32 i;
    s32 seen;
    s32 slot;
    u8 result;

    fight = *(s16 *) ((u8 *) func_80100094(actor, 0) + 8);
    variant = func_800DA564(0x315, 3);
    if (variant == 0) {
        if (func_800D395C()) {
            pick = func_800DC128(0, func_800DA980(0xC08, 3));
            i = 0;
            seen = 0;
            for (; i < 3; i++) {

if (func_800DA298(i + 0xC08)) {
    if (seen == pick)
        break;
    seen++;
}

}
slot = i + 1;
for (i = 0; i < 6; i++) {
    if (slot == D_80803D04_chklungo[i * 3 + fight]) {
        variant = i + 1;
        break;
    }

}
func_800DA7A8(0x315, variant, 3);
}
else
{
    variant = func_800DC128(0, 6) + 1;
    func_800DA7A8(0x315, variant, 3);
}
}
// Matching: result temporary is needed for the match.
result = ((u8 *) D_80803CF4_chklungo + 13)[variant * 3 + fight];
return result;
}

void func_80802F30_chklungo(s32 actor)
{
    _subaddieaudioquick_entrypoint_2(actor, actor + 4, &D_80803D18_chklungo);
}

void func_80802F58_chklungo(Actor *actor)
{
    u8 *data;

    data = func_80100094(actor, 0);
    _subaddieaudioquick_entrypoint_2(actor, (char *) actor + 4, &D_80803D28_chklungo);
    if ((*(s16 *) ((char *) data + 0x24) == 0) && (func_800C0638() == 0)) {
        func_80803158_chklungo(actor, 0x1630, 0x44);
        *(s16 *) ((char *) data + 0x24) = 1;
    }
}

void func_80802FCC_chklungo(actor) s32 actor;
{
    s32 data = func_80100094(actor, 0);
    *(u8 *) (data + 0x48) = _subaddieaudioloop_entrypoint_3(*(u8 *) (data + 0x48));
}

void func_80803000_chklungo(Actor *actor)
{
    Actor *data;
    data = func_80100094(actor, 0);
    if (*(s16 *) ((char *) data + 0x46) == 0) {
        func_800F4AF4(func_800F54E4(), 0x14);
        *(s16 *) ((char *) data + 0x46) = 1;
    }
    func_808030A4_chklungo(actor);
}

int func_8080305C_chklungo(s32 actor)
{
    s32 data = func_80100094(actor, 0);
    if (*(s16 *) ((char *) data + 0x46) != 0) {
        s32 camera = func_800F54E4();
        func_800F4B20(camera);
        *(s16 *) ((char *) data + 0x46) = 0;
    }
}

void func_808030A4_chklungo(actor) Actor *actor;
{
    u8 *data;
    f32 cam_target[3];

    data = func_80100094(actor, 0);
    if (*(s16 *) (data + 0x46)) {
        if (_plcamera_entrypoint_10(func_800F54E4()) != 20) {
            *(s16 *) (data + 0x46) = 0;
            return;
        }
        func_800EE7F8(cam_target, actor->position);
        cam_target[1] += 400.0f;
        _plcamera_entrypoint_9(func_800F54E4(), cam_target, 0.0f);
        func_80116088(func_80110014(func_800F5EF8(func_800F54E4())), cam_target);
    }
}

// Starts dialog text_id for the actor.
int func_80803158_chklungo(actor, text_id, unk_0)
s32 actor[4];
s32 text_id;
s32 unk_0;
{
    u32 actor_id;
    actor_id = actor[0];
    return _subaddiedialog_entrypoint_11(actor_id, text_id, unk_0, actor + 1, 0xab);
}

void func_8080318C_chklungo(KlungoS *actor)
{
    f32 speed_scale = 300.0f / actor->f24;
    func_80101CDC(actor, func_8010203C(actor, actor->f72) * speed_scale);
}

f32 func_808031E4_chklungo(f32 *actor)
{
    float ratio;
    ratio = actor[9] / 300.0f;
    return 400.0f * ratio;
}

void func_80803208_chklungo(actor) s32 actor;
{
    func_80105230(actor, &D_80803D38_chklungo);
}

void func_8080322C_chklungo(u8 *actor, f32 offset)
{
    f32 target_pos[3];
    s32 point;

    func_8010D09C(func_800F54E4(), target_pos, offset);
    if (func_80803304_chklungo(actor, target_pos) != 0) {
        if (func_800CC338(target_pos, ((*(u32 *) (actor + 0x70)) >> 0x19) - 1,
                          ((u32) ((*(u32 *) (actor + 0x70)) << 0x16) >> 0x1A) - 1) != -1) {
            func_800EE7F8(actor + 0x18, target_pos);
            return;
        }
    }
    point = func_80803390_chklungo(actor, target_pos);
    func_80803464_chklungo(actor, point, target_pos, actor + 0x18);
    if (func_80803304_chklungo(actor, actor + 0x18) == 0) {
        func_800EE7F8(actor + 0x18, actor + 4);
    }
}

// Casts a vertical probe at pos; on a hit stores the height in pos[1] and returns 1.
int func_80803304_chklungo(actor, pos)
Actor *actor;
f32 *pos;
{
    f32 top[3];
    f32 bottom[3];
    f32 hit[3];
    func_800EE7F8(top, pos);
    func_800EE7F8(bottom, pos);
    top[1] = actor->position[1] + 500.0f;
    bottom[1] = actor->position[1] - 500.0f;
    if (!func_800C6A7C(top, bottom, hit, 0x20020))
        return 0;
    pos[1] = bottom[1];
    return 1;
}

// Returns the point of the actor's zone closest to pos.
f32 *func_80803390_chklungo(actor, pos)
Actor *actor;
f32 *pos;
{
    s32 count;
    s32 i;
    f32 *nearest;
    f32 *point;

    count = func_800CC5F4((((u32 *) actor)[0x70 / 4] >> 25) - 1);
    nearest = NULL;
    for (i = 0; i < count; i++) {
        point = func_800CC63C((((u32 *) actor)[0x70 / 4] >> 25) - 1, i);
        if (nearest == NULL || func_800EEB40(point, pos) < func_800EEB40(nearest, pos)) {
            nearest = point;
        }
    }
    return nearest;
}

// Sets out to point moved by its distance toward target.
void func_80803464_chklungo(KlungoEventOwner owner, KlungoPathPoint *point, f32 *target,
                            f32 *out)
{
    f32 angle;

    angle = func_800F1DF4(point->position, target);
    func_800EE7F8(out, point->position);
    func_800EF1B8(out, angle, (f32) point->distance);
}

s32 func_808034CC_chklungo(Actor *actor)
{
    f32 side_a[3];
    f32 side_b[3];
    f32 *pos;

    pos = actor->position;
    func_800EE7F8(side_a, pos);
    func_800EF1B8(side_a, actor->rotation[1] + 90.0f, 1.5e+02f);
    if (func_800CBD84(side_a) == -1)
        return 0;
    func_800EE7F8(side_b, pos);
    func_800EF1B8(side_b, actor->rotation[1] - 90.0f, 150.0f);
    if (func_800CBD84(side_b) == -1)
        return 0;
    return 1;
}

u8 D_808038A0_chklungo[4] = {0x1, 0x41, 0x0, 0xC1};
KlungoTbl D_808038A4_chklungo[2] = {
    0x0,  0x20, 0x707, 0x0,  0x0,  0x0,  0x12, 0x0,  0x1,  0x0,  0x30, 0xFF, 0xFF, 0xFF,  0xFF,
    0x0,  0x0,  0x0,   0x0,  0x0,  0x0,  0x0,  0x2,  0x0,  0x0,  0x0,  0x30, 0x0,  0x0,   0x0,
    0x5,  0x0,  0x1,   0x4,  0x38, 0x0,  0x0,  0x0,  0x8,  0x0,  0x0,  0x4,  0x38, 0x0,   0x0,
    0x0,  0x4,  0x0,   0x0,  0x4,  0x38, 0x0,  0x0,  0x0,  0x14, 0x0,  0x0,  0x4,  0x38,  0x0,
    0x0,  0x0,  0xA,   0x0,  0x0,  0x4,  0x38, 0x0,  0x0,  0x0,  0xC,  0x0,  0x0,  0x0,   0x30,
    0x0,  0x0,  0x0,   0x5,  0x0,  0x0,  0x4,  0x38, 0x3F, 0x99, 0x99, 0x9A, 0x0,  0x0,   0x0,
    0x0,  0x41, 0x70,  0x0,  0x0,  0x41, 0xA0, 0x0,  0x0,  0x40, 0x40, 0x0,  0x0,  0x40,  0x80,
    0x0,  0x0,  0x43,  0x96, 0x0,  0x0,  0x16, 0x22, 0x16, 0x23, 0x16, 0x27, 0x16, 0x35,  0xF,
    0xA0, 0xDE, 0xA7,  0x71, 0xC0, 0x0,  0x0,  0x1,  0x5B, 0x1,  0xBA, 0x0,  0x21, 0x90C, 0x0,
    0x0,  0x0,  0x11,  0x0,  0x1,  0x0,  0x30, 0xFF, 0xFF, 0xFF, 0xFF, 0x0,  0x0,  0x0,   0x0,
    0x0,  0x0,  0x0,   0x2,  0x0,  0x0,  0x0,  0x30, 0x0,  0x0,  0x0,  0x5,  0x0,  0x1,   0x4,
    0x38, 0x0,  0x0,   0x0,  0x8,  0x0,  0x0,  0x4,  0x38, 0x0,  0x0,  0x0,  0x4,  0x0,   0x0,
    0x4,  0x38, 0x0,   0x0,  0x0,  0x14, 0x0,  0x0,  0x4,  0x38, 0x0,  0x0,  0x0,  0xA,   0x0,
    0x0,  0x4,  0x38,  0x0,  0x0,  0x0,  0xC,  0x0,  0x0,  0x0,  0x30, 0x0,  0x0,  0x0,   0x5,
    0x0,  0x0,  0x4,   0x38, 0x3F, 0x80, 0x0,  0x0,  0x3E, 0xCC, 0xCC, 0xCD, 0x41, 0x70,  0x0,
    0x0,  0x41, 0xA0,  0x0,  0x0,  0x40, 0x0,  0x0,  0x0,  0x40, 0x40, 0x0,  0x0,  0x43,  0xC8,
    0x0,  0x0,  0x16,  0x28, 0x16, 0x29, 0x16, 0x2A, 0x16, 0x36, 0xB,  0xB8, 0xDE, 0xA7,  0x71,
    0xC0, 0x0,  0x0,   0x1,  0x5E, 0x0,  0xB7};
static u32 D_808038A4_chklungo_rest[32] = {
    0x22090D,   0x12,       0x10030,    0x14,       0x10031,    0x2,        0x30,       0x3,
    0x10438,    0x5,        0x438,      0x7,        0x438,      0xB,        0x438,      0xD,
    0x438,      0xF,        0x30,       0x3,        0x438,      0x3F4CCCCD, 0x3F4CCCCD, 0x41700000,
    0x41A00000, 0x3F800000, 0x40000000, 0x43FA0000, 0x162B162C, 0x162D1637, 0x9C480C0,  0xC0C00000};
u8 D_80803A2C_chklungo[16] = {0x0, 0x13, 0x6, 0x14, 0x0, 0xD, 0x0, 0xB3,
                              0x0, 0xCC, 0x0, 0x18, 0x0, 0x2, 0x0, 0x0};
u8 D_80803A3C_chklungo[16] = {0x43, 0x34, 0x0,  0x0, 0x43, 0x7A, 0x0, 0x0,
                              0x43, 0x89, 0x80, 0x0, 0x42, 0xC8, 0x0, 0x0};
u8 D_80803A4C_chklungo[288] = {
    0x0,  0x0,  0x0,  0x0,  0x0, 0x0,  0x0, 0x0,  0x40, 0xF5, 0x70, 0xA4, 0x2, 0x5C, 0x0, 0x1,
    0x3F, 0x0,  0x0,  0x0,  0x4, 0xB2, 0x0, 0x1,  0x3F, 0x0,  0x0,  0x0,  0x4, 0xB2, 0x0, 0x1,
    0x3F, 0x19, 0x99, 0x9A, 0x4, 0xB3, 0x0, 0x2,  0x40, 0xF5, 0x70, 0xA4, 0x2, 0x5C, 0x0, 0x1,
    0x40, 0xF5, 0x70, 0xA4, 0x2, 0x5C, 0x0, 0x1,  0x40, 0xF5, 0x70, 0xA4, 0x2, 0x5C, 0x0, 0x1,
    0x40, 0xF5, 0x70, 0xA4, 0x2, 0x5C, 0x0, 0x1,  0x40, 0xAF, 0xA,  0x3D, 0x2, 0x5D, 0x0, 0x2,
    0x40, 0xF5, 0x70, 0xA4, 0x2, 0x5C, 0x0, 0x1,  0x40, 0x20, 0x0,  0x0,  0x2, 0x5E, 0x0, 0x2,
    0x40, 0xF5, 0x70, 0xA4, 0x2, 0x67, 0x0, 0x1,  0x3F, 0x99, 0x99, 0x9A, 0x2, 0x5F, 0x0, 0x2,
    0x3E, 0xDC, 0x28, 0xF6, 0x2, 0x60, 0x0, 0x2,  0x3F, 0xC0, 0x0,  0x0,  0x2, 0x68, 0x0, 0x2,
    0x40, 0xF5, 0x70, 0xA4, 0x2, 0x5C, 0x0, 0x1,  0x3F, 0x33, 0x33, 0x33, 0x2, 0x64, 0x0, 0x1,
    0x3E, 0xDC, 0x28, 0xF6, 0x2, 0x66, 0x0, 0x2,  0x3F, 0x33, 0x33, 0x33, 0x2, 0x64, 0x0, 0x1,
    0x40, 0xF5, 0x70, 0xA4, 0x2, 0x5C, 0x0, 0x1,  0x3F, 0x9D, 0x70, 0xA4, 0x2, 0x65, 0x0, 0x42,
    0x3F, 0x9D, 0x70, 0xA4, 0x2, 0x6A, 0x0, 0x42, 0x3F, 0x33, 0x33, 0x33, 0x2, 0x64, 0x4, 0x1,
    0x3E, 0xDC, 0x28, 0xF6, 0x2, 0x66, 0x0, 0x2,  0x40, 0xF5, 0x70, 0xA4, 0x2, 0x5C, 0x4, 0x1,
    0x40, 0xF5, 0x70, 0xA4, 0x2, 0x5C, 0x4, 0x1,  0x40, 0xF5, 0x70, 0xA4, 0x2, 0x5C, 0x0, 0x1,
    0x3F, 0x95, 0xC2, 0x8F, 0x2, 0x61, 0x0, 0x1,  0x40, 0x41, 0xEB, 0x85, 0x2, 0x62, 0x0, 0x2,
    0x40, 0x41, 0xEB, 0x85, 0x2, 0x62, 0x0, 0x84, 0x40, 0x41, 0xEB, 0x85, 0x2, 0x62, 0x0, 0x84,
    0x3F, 0x0,  0x0,  0x0,  0x2, 0x63, 0x0, 0x2,  0x40, 0xF5, 0x70, 0xA4, 0x2, 0x5C, 0x0, 0x1,
    0x40, 0xF5, 0x70, 0xA4, 0x2, 0x5C, 0x0, 0x1,  0x3F, 0x33, 0x33, 0x33, 0x2, 0x64, 0x0, 0x1};
int D_80803B6C_chklungo[18] = {0xB3041E,
                               -0xFFFF,
                               (u32) &D_80803A4C_chklungo,
                               (u32) func_808002D0_chklungo,
                               (u32) func_8080101C_chklungo,
                               (u32) func_808011B4_chklungo,
                               0x0,
                               0x40000000,
                               0x0,
                               0x40561,
                               (u32) func_8080162C_chklungo,
                               (u32) func_80108ED0,
                               0xA00000,
                               (u32) func_8080000C_chklungo,
                               (u32) func_80107C2C,
                               -0x7FDFEBFC,
                               (u32) func_80801220_chklungo,
                               0x0};
u8 D_80803BB4_chklungo[12] = {0x0, 0x13, 0x5, 0x67, 0x0, 0xA, 0x0, 0xB3, 0x0, 0x2, 0x0, 0x0};
u8 D_80803BC0_chklungo[16] = {0x0, 0x13, 0x6, 0x15, 0x0, 0xD, 0x0, 0xF3,
                              0x1, 0xC,  0x0, 0x18, 0x0, 0x2, 0x0, 0x0};
u8 D_80803BD0_chklungo[16] = {0x0, 0x13, 0x4, 0xF8, 0x0, 0xA, 0x0, 0xB3,
                              0x0, 0x18, 0x0, 0x2,  0x0, 0x0, 0x0, 0x0};
int D_80803BE0_chklungo[3] = {0x1304A2, 0x180002, 0x0};
int D_80803BEC_chklungo[4] = {0x13049C, 0xA00B3, 0x180002, 0x0};
int D_80803BFC_chklungo[4] = {0x130434, 0xA00B3, 0x180002, 0x0};
int D_80803C0C_chklungo[4] = {0x1305BA, 0xD00F3, 0x10C0018, 0x20000};
int D_80803C1C_chklungo[4] = {0x3EDC28F6, 0x3F000000, 0x3F19999A, -0x40800000};
int D_80803C2C_chklungo[4] = {0x3F4F5C29, 0x3F6147AE, 0x3F733333, -0x40800000};
s32 D_80803C3C_chklungo[6] = {0x130417, 0x164650, 0xD00F3, 0x10C0001, 0x3201D4C, 0x0};
s32 D_80803C54_chklungo[6] = {0x3D75C28F, 0x3E19999A, 0x3E75C28F,
                              0x3F07AE14, 0x3F1C28F6, -0x40800000};
s32 D_80803C6C_chklungo[2] = {0x130417, 0x20000};
s32 D_80803C74_chklungo[4] = {0x130614, 0xA00B3, 0x180002, 0x0};
u8 D_80803C84_chklungo[20] = {0x3, 0x6,  0x0, 0x13, 0x4, 0xF7, 0x0, 0xD,  0x0, 0x8C,
                              0x0, 0xA6, 0x0, 0x18, 0x0, 0x2,  0x0, 0x11, 0x0, 0x0};
s32 D_80803C98_chklungo[4] = {0x1304F8, 0xD00C0, 0xD90018, 0x20000};
s32 D_80803CA8_chklungo[4] = {0x1304ED, 0xD00C0, 0xD90002, 0x0};
s32 D_80803CB8_chklungo[2] = {0x130417, 0x20000};
u8 D_80803CC0_chklungo[52] = {0x0,  0x1D, 0x9,  0xDD, 0x0,  0x2B, 0x1,  0x80, 0x2,  0x0,  0x0,
                              0x22, 0x1,  0x80, 0x2,  0x0,  0x3,  0x80, 0x4,  0x0,  0x0,  0x15,
                              0x0,  0x0,  0x0,  0x99, 0x0,  0x27, 0xFF, 0x9C, 0xFF, 0x9C, 0x0,
                              0x64, 0x0,  0x64, 0x0,  0x19, 0x0,  0x0,  0x0,  0x7,  0x0,  0x2D,
                              0x0,  0xFA, 0x1,  0x5E, 0x1,  0x1A, 0x0,  0x0};
s32 D_80803CF4_chklungo[4] = {0x130413, 0x18000D, 0xC000D9, 0x20000};
u8 D_80803D04_chklungo[20] = {0x1, 0x2, 0x3, 0x1, 0x3, 0x2, 0x2, 0x1, 0x3, 0x2,
                              0x3, 0x1, 0x3, 0x2, 0x1, 0x3, 0x1, 0x2, 0x0, 0x0};
u8 D_80803D18_chklungo[16] = {0x0, 0x13, 0x5, 0xFF, 0x0, 0xD, 0x0, 0xD9,
                              0x0, 0xF3, 0x0, 0x18, 0x0, 0x2, 0x0, 0x0};
u8 D_80803D28_chklungo[16] = {0x0, 0x13, 0x4, 0xB0, 0x0, 0xD, 0x0, 0xF3,
                              0x1, 0xC,  0x0, 0x2,  0x0, 0x0, 0x0, 0x0};
s32 D_80803D38_chklungo[6] = {0x0, 0x3F000000, -0x40800000, 0x0, 0x0, 0x0};
