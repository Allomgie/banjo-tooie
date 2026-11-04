// Probably the Hellter Skelter ride: a controller that spawns riders sliding down a spline path,
// a shock-jump-pad spawner, and the switch that enables it.

#include "ch/hellterskelter.h"

extern int D_808007C8_chhellterskelter[];
extern int D_80800810_chhellterskelter[];
extern int D_80800858_chhellterskelter[];
extern f32 func_800DC178(f32, f32);
extern void func_800EE7F8(f32 *, f32 *);
extern void func_800EF1B8(f32 *, f32, f32);
extern u8 D_808008F4_chhellterskelter[];
extern u8 D_80800924_chhellterskelter[];
extern void _subaddieaudioquick_entrypoint_2(Actor *, f32 *, void *);
extern s32 func_800BABB8(s32, f32 *, f32 *, f32, s32 *);
extern u8 D_80800938_chhellterskelter[];
extern u8 D_80800974_chhellterskelter[];
extern Actor *func_8010856C(s32, f32 *, f32 *);
extern Actor *func_80108528(s32, f32 *, s32, Actor **);
extern Actor *func_80106790(Unk80132ED0 *);
extern void func_80102FDC(Actor *, f32);
extern void func_80105A9C(Actor *, f32);
extern void _chappearfx_entrypoint_1(Actor *, s32, s32, f32);
extern s32 _capod_entrypoint_17(f32);
typedef struct Mass45HelterFlags {
    u32 unk_0 : 11;
    u32 sound_played : 1;
    u32 unk_2 : 20;
} Mass45HelterFlags;
extern f32 *func_80105494(Actor *);
extern s32 func_800F4F34(s32, f32 *, f32, f32);
extern s32 func_80105998(Actor *, f32);
extern s32 D_808008A0_chhellterskelter[];
extern s32 D_808008AC_chhellterskelter[];
extern s32 func_800DC298(f32);
extern void func_800BBCB8(f32 *, s32, f32, s32, void *);
extern u8 D_808008C0_chhellterskelter[];
void func_808004D0_chhellterskelter();

int *chhellterskelter_entrypoint_0()
{
    return &D_808007C8_chhellterskelter;
}

int chhellterskelter_entrypoint_1()
{
    return (int) &D_80800810_chhellterskelter;
}

int *chhellterskelter_entrypoint_2()
{
    return &D_80800858_chhellterskelter;
}

int func_80800024_chhellterskelter(s32 actor)
{
    s32 marker_a;
    s32 marker_b;
    marker_a = _gccubesearch_entrypoint_0(0x154, actor);
    marker_b = _gccubesearch_entrypoint_0(0x320, actor);
    func_800EE88C(actor + (char) 0x18, marker_a);
    func_800EE88C(actor + 0x28, marker_b);
    if (func_800DA298(0xA4B)) {
        // Switch already set: show the shock jump pad.
        *((char *) actor + 0x65) &= ~0x10;
        func_80108B04(actor, 0x210);
    }
}

// Controller: spawns riders periodically; the jump pad is shown once the switch is set.
void func_808000A8_chhellterskelter(Actor *actor)
{
    if (actor->unk64_19 && !func_800DA298(0xA4B)) {
        if (!func_800DA9E4(0x6A2, 1)) {
            _capod_entrypoint_13(actor->unk0, 0, 5, 0x10);
        }
        _chshockjump_entrypoint_2(actor->unk3C);
        actor->unk3C = NULL;
        actor->unk64_19 = 0;
    }
    if (func_800D90A4(&actor->unk58)) {
        func_80108B04(actor, 0x33A);
        actor->unk58 = func_800DC178(6.0f, 8.0f);
    }
}

void func_80800680_chhellterskelter();

s32 func_80800158_chhellterskelter(Actor *actor, s32 msg, s32 arg)
{
    switch (msg) {
        case 0x3D:
            func_80800680_chhellterskelter(actor, arg);
            break;
        case 0xE:
            if (arg == 1 && _capod_entrypoint_17(0.9f)) {
                actor->unk64_20 = 1;
                func_80108B04(actor, 0x210);
            }
            return 3;
        case 0xA:
            if (!func_800DA9E4(0x6A1, 1))
                _capod_entrypoint_13(actor->unk0, 0, 1, 0x10);
            else {
                actor->unk64_20 = 0;
                func_80108B04(actor, 0x210);
            }
            break;
        case 0x95:
            if (!actor->unk3C)
                _subaddiefind_entrypoint_10(actor, 0x210, 0);
            break;
        default:
            return 0;
    }
    return 1;
}

void func_80800274_chhellterskelter(s32 actor)
{
    _chswitch_entrypoint_7(actor, FLAG3_A4B_UNK);
}

int func_80800294_chhellterskelter(s32 actor, s32 msg, s32 arg)
{
    if (msg == 7) {
        func_80101180(0x339, 0xA, 0);
    }
    // Matching: `msg | msg` is needed for the match.
    _chswitch_entrypoint_10(actor, msg | msg, arg);
}

void func_808002E8_chhellterskelter(s32 arg0)
{
}

void func_808005E0_chhellterskelter();

void func_80800540_chhellterskelter();

void func_808002F0_chhellterskelter(Actor *actor)
{
    f32 prev_y;
    s32 player;
    s32 in_range;
    f32 *path_data;

    prev_y = actor->position[1];
    player = func_800F54E4();
    if (func_800F64A4(player, 0x8000) || !func_800F6478(player)) {
        func_800F4F34(player, actor->position, 50.0f, 80.0f);
    }
    func_80105834(actor);
    func_808004D0_chhellterskelter(actor);
    if (!((Mass45HelterFlags *) ((u8 *) actor + 0x64))->sound_played) {
        if (func_8010CAC0(actor->position, 400)) {
            _subaddieaudioquick_entrypoint_2(actor, actor->position,
                                             &D_808008A0_chhellterskelter);
            actor->unk64_20 = 1;
        }
    }
    switch (actor->unk70_10) {
        case 1:
            in_range = func_8010CAC0(actor->position, 1500);
            path_data = func_80105494(actor);
            if (in_range || (!in_range && actor->unk5F)) {
                _subaddieaudioloop_entrypoint_5(actor, actor->position, in_range, 1200,
                                                &D_808008AC_chhellterskelter);
            }
            if (path_data[3] > 0.94f) {
                func_80101FDC(actor, 2);
            }
            break;
        case 2:
            if (prev_y > -110.0f && actor->position[1] <= -110.0f) {
                func_80800540_chhellterskelter(actor);
            }
            if (func_80105998(actor, 0.985f)) {
                func_808005E0_chhellterskelter(actor);
            }
            if (func_80105A5C(actor)) {
                func_800FFAB0(actor);
            }
    }
}

void func_808004D0_chhellterskelter(actor) Actor *actor;
{
    f32 *path_data;
    path_data = func_80105494(actor);
    if (!(path_data[3] > 0.9f) && func_800DC298(0.1f)) {
        func_800BBCB8(actor->position, 0, 1.0f, 1, D_808008C0_chhellterskelter);
    }
}

// Particles and sound when a rider hits the water at y=-110.
void func_80800540_chhellterskelter(Actor *actor)
{
    f32 pos[3];

    func_800EE7F8(pos, actor->position);
    pos[1] -= 100.0f;
    func_800EF1B8(pos, actor->rotation[1] + 180.0f, 50.0f);
    func_800BBCB8(actor->position, (s32) pos, 1.0f, 10, D_808008F4_chhellterskelter);
    _subaddieaudioquick_entrypoint_2(actor, actor->position, D_80800924_chhellterskelter);
}

void func_808005E0_chhellterskelter(Actor *actor)
{
    f32 pos[3];

    func_800EE7F8(pos, actor->position);
    pos[1] -= 100.0f;
    func_800EF1B8(pos, actor->rotation[1] + 180.0f, 50.0f);
    func_800BABB8(0, actor->position, pos, 1.0f, (s32 *) D_80800938_chhellterskelter);
    _subaddieaudioquick_entrypoint_2(actor, actor->position, D_80800974_chhellterskelter);
}

void func_80800680_chhellterskelter(Actor *actor, s32 actor_id)
{
    f32 rot[2];
    Actor *rider;
    Unk80132ED0 *handle;
    Actor *jump_pad;
    switch (actor_id) {
        case 0x33A:
            handle = actor->unk0;
            rot[0] = 0.0f;
            rot[1] = actor->rotation[1];
            rider = func_8010856C(actor_id, (f32 *) actor->actorData, rot);
            actor = func_80106790(handle);
            func_80102FDC(rider, actor->scale);
            func_80105A9C(rider, 700.0f);
            break;
        case 0x210:
            jump_pad = func_80108528(actor_id, (f32 *) ((u8 *) actor + 0x28), 0, &actor);
            func_80102FDC(jump_pad, 0.7f);
            if (actor->unk64_20) {
                _subaddiefade_entrypoint_2(jump_pad);
                _chappearfx_entrypoint_1(jump_pad, 0x22, 1, 1.0f);
            }
            actor->unk64_20 = 0;
            actor->unk64_19 = 1;
            actor->unk3C = jump_pad->unk0;
    }
}

// TU-NOTE: the .data of this overlay is defined here in C. Its tables hold pointers to
// functions of this file; IDO assembler schedules some of them differently unless the
// tables are in the same unit. Values are taken from the ROM.
extern int func_80105834();
extern void func_80101870();
extern void func_80107C2C();
extern u8 D_8011A270[];
extern void _chswitch_entrypoint_6();
extern void func_80102EC0();
extern void func_80108ED0();
u32 D_808007B0_chhellterskelter[6] = {0x0, 0x0, 0x41287AE1, 0x1000400, 0x41287AE1, 0x1000000};
int D_808007C8_chhellterskelter[18] = {0x2A00339,
                                       0x1,
                                       0x0,
                                       (u32) func_808000A8_chhellterskelter,
                                       (u32) func_80105834,
                                       (u32) func_80101870,
                                       0x0,
                                       0x0,
                                       0x0,
                                       0x0,
                                       0x0,
                                       0x0,
                                       0x0,
                                       (u32) func_80800024_chhellterskelter,
                                       (u32) func_80107C2C,
                                       -0x7FFFF9FE,
                                       (u32) func_80800158_chhellterskelter,
                                       0x0};
int D_80800810_chhellterskelter[18] = {0x343033B,
                                       0x7520001,
                                       (u32) &D_8011A270,
                                       (u32) _chswitch_entrypoint_6,
                                       (u32) func_80105834,
                                       (u32) func_80101870,
                                       0x0,
                                       0x0,
                                       0x0,
                                       0x808,
                                       0x0,
                                       0x0,
                                       0x0,
                                       (u32) func_80800274_chhellterskelter,
                                       (u32) func_80107C2C,
                                       -0x7FFFD3FE,
                                       (u32) func_80800294_chhellterskelter,
                                       0x0};
int D_80800858_chhellterskelter[18] = {0x2A1033A,
                                       0x6B80001,
                                       (u32) &D_808007B0_chhellterskelter,
                                       (u32) func_80102EC0,
                                       (u32) func_808002F0_chhellterskelter,
                                       (u32) func_80101870,
                                       0x0,
                                       0x0,
                                       0x0,
                                       0x21120,
                                       0x0,
                                       (u32) func_80108ED0,
                                       0x0,
                                       (u32) func_808002E8_chhellterskelter,
                                       (u32) func_80107C2C,
                                       -0x7FFFFC00,
                                       0x0,
                                       0x0};
s32 D_808008A0_chhellterskelter[3] = {0x13063C, 0xD00F3, 0x10C0000};
s32 D_808008AC_chhellterskelter[5] = {0x130410, 0xD00C0, 0xD90018, 0x1012C, 0x4B00000};
u8 D_808008C0_chhellterskelter[52] = {
    0x0,  0x1D, 0x9,  0xDD, 0x0,  0x1B, 0x0,  0x96, 0x0,  0xFA, 0x0,  0x20, 0xC0,
    0xC0, 0xC0, 0x7F, 0x0,  0x16, 0x0,  0x8,  0x0,  0x22, 0x0,  0x99, 0x0,  0xB3,
    0x0,  0xD9, 0x0,  0xE6, 0x0,  0x15, 0x0,  0x0,  0x0,  0x80, 0x0,  0x1E, 0x0,
    0x5,  0x0,  0xA,  0x0,  0x2B, 0x0,  0xC0, 0x1,  0x33, 0x0,  0x0,  0x0,  0x0};
u8 D_808008F4_chhellterskelter[48] = {
    0x0,  0x1D, 0x9, 0xD3, 0x0, 0x14, 0x0, 0x16, 0x0, 0x0,  0x0,  0x7,  0x0, 0x1,  0x0, 0x16,
    0x10, 0x0,  0x0, 0x2D, 0x1, 0x90, 0x2, 0x58, 0x0, 0x22, 0x0,  0x19, 0x0, 0x33, 0x0, 0xC,
    0x0,  0x19, 0x0, 0xB,  0x0, 0xA,  0x0, 0x28, 0x0, 0xA,  0xFF, 0xF6, 0x0, 0x0,  0x0, 0x0};
u8 D_80800924_chhellterskelter[20] = {0x0, 0x13, 0x6, 0xF,  0x0, 0xD,  0x0, 0xF3, 0x1, 0xC,
                                      0x0, 0x1,  0x1, 0xF4, 0x7, 0xD0, 0x0, 0x0,  0x0, 0x0};
u8 D_80800938_chhellterskelter[60] = {
    0x8,  0x10, 0x0,  0x1D, 0x9, 0xDD, 0x0,  0x2D, 0x2,  0x58, 0x3,  0x20, 0x0, 0xB,  0x0,
    0x14, 0x0,  0x32, 0x0,  0xA, 0x0,  0x0,  0x0,  0x1F, 0xC0, 0xC0, 0xC0, 0x0, 0x0,  0x22,
    0x0,  0x99, 0x1,  0x0,  0x2, 0x0,  0x2,  0x80, 0x0,  0x15, 0x0,  0x0,  0x0, 0x99, 0x0,
    0x2A, 0x0,  0x0,  0x0,  0xA, 0x0,  0xCC, 0x1,  0x0,  0x0,  0xF,  0x0,  0x0, 0x0,  0x0};
u8 D_80800974_chhellterskelter[28] = {0x0, 0x13, 0x4, 0xDC, 0x0, 0xD,  0x0, 0xCC, 0x0, 0xE6,
                                      0x0, 0x15, 0x0, 0x80, 0x0, 0x66, 0x0, 0x33, 0x0, 0x1,
                                      0x1, 0xF4, 0x7, 0xD0, 0x0, 0x0,  0x0, 0x0};
