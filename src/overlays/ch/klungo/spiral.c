// One reading: a non-fight Klungo encounter in Spiral Mountain. He waits for the player, runs a
// camera pod and dialog, walks off along a path, sets a flag and deletes himself.
#include "common.h"

// TU-NOTE: the .data tables of this overlay are defined in this file. They hold pointers to
// functions of this file; IDO's assembler schedules some functions differently otherwise.
// Values are taken from the ROM. D_80800674 and D_80800688 are declared as s32[] to match the object.

extern void *D_80800620_chklungospiral;
extern void _subaddiemarker_entrypoint_1();
extern void _subaddieDll_entrypoint_2();
extern void func_80105A9C(u8 *, f32);
extern void func_80105BAC();
extern f32 D_80800668_chklungospiral[];
extern void *func_80100094(Actor *, s32);
extern u8 D_808005F0_chklungospiral[];
typedef struct {
    u8 pad[0x6C];
    u32 pad6C : 23;
    u32 f : 9;
} KlungoS;
extern void _capod_entrypoint_3(s32, KlungoS *);
extern s32 D_80800688_chklungospiral[];
extern s32 D_80800674_chklungospiral[];
extern s32 func_80101E4C(Actor *, void *);
extern s32 func_80101E14(Actor *, f32);
extern void func_80018820(s32, f32, f32);
extern void func_800E15CC(s32, f32, f32);
extern void _subaddieaudioquick_entrypoint_2(Actor *, f32[3], void *);
void func_808002FC_chklungospiral();
int func_808003AC_chklungospiral();
s32 func_80800430_chklungospiral();
void func_80800480_chklungospiral();

int chklungospiral_entrypoint_0()
{
    return &D_80800620_chklungospiral;
}

// Setup: registers the marker and collision for the actor.
void func_8080000C_chklungospiral(u8 *actor)
{
    s32 unk_0[6];
    _subaddiemarker_entrypoint_1(actor, 0x154, 0x33, unk_0, 1);
    _subaddieDll_entrypoint_2(actor, unk_0);
    func_80105A9C(actor, 300.0f);
    func_80105BAC(actor);
}

// Update: wait for the player, run the dialog camera, walk off along the path, set flag 0x3C.
void func_80800060_chklungospiral(Actor *actor)
{
    switch (actor->unk70_10) {
        case 1:
            if (func_8010C500(actor)) {
                func_80102424(actor, 2);
                func_808003AC_chklungospiral(actor, 15, 48);
            }
            break;
        case 2:
            func_80800480_chklungospiral(actor);
            break;
        case 3:
            func_80105834(actor);
            func_80105230(actor, D_80800668_chklungospiral);
            if (func_80105A5C(actor)) {
                func_80800430_chklungospiral(actor);
                func_800FFAB0(actor);
                func_800DA544(0x3C);
            }
    }
    if (func_80100094(actor, 1)) {
        _suexpression_entrypoint_10(func_80100094(actor, 1), actor->unk0, 0);
    }
}

s32 func_8080015C_chklungospiral(Actor *actor, s32 msg, u32 arg)
{
    switch (msg) {
        case 11:
            if (arg == 15) {
                func_808002FC_chklungospiral(actor, 3, 1);
                _subaddiedialog_entrypoint_11(actor->unk0, 0x1638, 0xE, 0, 0xAB);
                return 4;
            }
            return 3;
        case 46:
            func_808003AC_chklungospiral(actor, 22, 48);
            func_80102424(actor, 3);
            break;
        case 0x57:
            return func_808002A0_chklungospiral(actor, arg & 0xFFFF,
                                                (arg & 0xFFFF0000) >> 16);
        case 41:
            _suexpression_entrypoint_7(actor, 1, 0xAB);
            break;
        case 42:
            _suexpression_entrypoint_8(actor, 1);
            break;
        case 31:
            func_801015D0(actor);
            func_800DF744(3, 0);
            break;
        default:
            return 0;
    }
    return 1;
}

int func_808002A0_chklungospiral(Actor *actor, s32 lo, s32 hi)
{
    // Matching: the `| 0` is needed for the match.
    if (_gcdialogcamera_entrypoint_0(lo | 0, hi | 0)) {
        if ((*(s32 *) ((char *) actor + 0x6C) & 0x1FF) != 2) {
            func_808002FC_chklungospiral(actor, 2, 1);
        }
        return 2;
    }
    return 1;
}

// Camera pod and dialog camera state machine; the cases fall through on purpose.
void func_808002FC_chklungospiral(actor, unk_0, unk_1) u8 *actor;
s32 unk_0;
s32 unk_1;
{
    s32 state;

    state = *(s32 *) ((s8 *) actor + 0x6C) & 0x1FF;
    switch (state) {
        case 0:
            _capod_entrypoint_2(*(s32 *) ((s8 *) actor + 0), 0xc, 0);

        case 1:
            _capod_entrypoint_8(1);
            *(u16 *) ((s8 *) actor + 0x6E) =
                (u16) ((*(u16 *) ((s8 *) actor + 0x6E) & 0xFE00) | 2);
            _gcdialogcamera_entrypoint_3(&D_808005F0_chklungospiral,
                                         *(s32 *) ((s8 *) actor + 0x38));
            _gcdialogcamera_entrypoint_4(actor + 4);
            _gcdialogcamera_entrypoint_5(actor + 0x44);
            _gcdialogcamera_entrypoint_8();

        case 2:
            _capod_entrypoint_7(unk_0, unk_1);
    }
}

int func_808003AC_chklungospiral(actor, unk_0, unk_1)
Actor *actor;
s32 unk_0;
s32 unk_1;
{
    s32 flags;
    s32 state;
    // Matching: the two temporaries are needed for the match.
    flags = *(s32 *) ((char *) actor + 0x6C);
    state = flags & 0x1FF;
    switch (state & 0xFFFF) {
        case 0:
            _capod_entrypoint_2(*(s32 *) ((char *) actor + 0x0), 0xC, unk_1, actor);

        case 2:
            *(u16 *) ((char *) actor + 0x6E) =
                (u16) ((*(u16 *) ((char *) actor + 0x6E) & 0xFE00) | 1);

        case 1:
            _capod_entrypoint_6(*(s32 *) ((char *) actor + 0x0), unk_0, unk_1, actor);
    }
}

s32 func_80800430_chklungospiral(actor)
KlungoS *actor;
{

if (actor->f) {
    _capod_entrypoint_3(0, actor);
    actor->f = 0;
    return 1;
}

return 0;

}

void func_80800480_chklungospiral(actor) Actor *actor;
{
    if (!actor->unk7C_12) {
        return;
    }

if (func_80101E4C(actor, &D_80800688_chklungospiral)) {
    func_80018820(0, 0.8f, 0.3f);
    func_800E15CC(0, 5.0f, 0.7f);
    _subaddieaudioquick_entrypoint_2(actor, actor->position, &D_80800674_chklungospiral);
    return;
}

if (func_80101E14(actor, 0.7f)) {
    func_80018820(0, 1.0f, 0.4f);
    func_800E15CC(0, 10.0f, 0.8f);
    _subaddieaudioquick_entrypoint_2(actor, actor->position, &D_80800674_chklungospiral);
}

}

extern void func_80102EC0();
extern void func_801018A4();
extern void func_80107C2C();
u8 D_808005F0_chklungospiral[16] = {0x43, 0x34, 0x0, 0x0, 0x43, 0x48, 0x0, 0x0,
                                    0x43, 0x48, 0x0, 0x0, 0x43, 0x2,  0x0, 0x0};
u32 D_80800600_chklungospiral[8] = {0x0,        0x0,       0x40F570A4, 0x25C0001,
                                    0x40F570A4, 0x25C0001, 0x3F333333, 0x2640001};
void *D_80800620_chklungospiral = (void *) 0x015804EC;
static u32 D_80800620_chklungospiral_rest[17] = {0x7070001,
                                                 (u32) &D_80800600_chklungospiral,
                                                 (u32) func_80102EC0,
                                                 (u32) func_80800060_chklungospiral,
                                                 (u32) func_801018A4,
                                                 0x0,
                                                 0x40000000,
                                                 0x3C0000,
                                                 0x40040120,
                                                 0x0,
                                                 0x0,
                                                 0x0,
                                                 (u32) func_8080000C_chklungospiral,
                                                 (u32) func_80107C2C,
                                                 0x80001416,
                                                 (u32) func_8080015C_chklungospiral,
                                                 0x0};
f32 D_80800668_chklungospiral[3] = {0.0f, 0.5f, -1.0f};
s32 D_80800674_chklungospiral[5] = {0x130417, 0xD00F3, 0x10C0001, 0x3201D4C, 0x0};
s32 D_80800688_chklungospiral[6] = {0x3D75C28F, 0x3E19999A, 0x3E75C28F,
                                    0x3F07AE14, 0x3F1C28F6, -0x40800000};
