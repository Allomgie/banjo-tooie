#include "common.h"

extern void *D_80800670_chjigsawcollect;
typedef struct {
    f32 arc_angle;
    f32 orbit_angle;
    f32 spin_speed;
    s32 jiggy_index;
    s32 light_slot;
} JigsawCollectionState;
extern void *func_80100094(Actor *, u32);
extern Actor *func_80108528(s32, f32 *, s32, Actor **);
typedef struct {
    u8 unused[0x73];
    u8 unusedBit : 7;
    u8 collect : 1;
} JiggyCollectFlags;
typedef struct {
    u8 pad_0[0x72];
    u16 st : 6;
    u16 rest : 10;
} JigState;
extern u8 D_808006B8_chjigsawcollect[];
extern u8 D_808006C4_chjigsawcollect[];
extern f32 func_800D8FF8(void);
extern f32 func_80013728(f32);
extern f32 func_800136E4(f32);
extern f32 func_800F10B4(f32, f32, f32, f32, f32);
extern f32 func_800F15F8(f32, f32, f32);
extern f32 func_800F1DF4(f32 *, f32 *);
extern f32 func_800DC178(f32, f32);
extern f32 func_800DC0C0(void);
extern void func_800C4B64(f32);
extern void func_800EF214(f32 *, f32, f32, f32);
extern s32 _chlightfader_entrypoint_1(s32, f32, s32);
extern void func_80101870(), func_80105834(), func_80107C2C(), func_8080000C_chjigsawcollect(),
    func_80800524_chjigsawcollect();

int chjigsawcollect_entrypoint_0()
{
    return &D_80800670_chjigsawcollect;
}

// Init: claims a collectible light slot, starts the jingle (track 0x1C) and ducks track 5.
void func_8080000C_chjigsawcollect(actor) Actor *actor;
{
    JigsawCollectionState *state;

    state = func_80100094(actor, 0);
    if (func_800CFA70(state->jiggy_index, 1) != -1) {
        state->light_slot = func_800C8A98();
        func_800CF9E4(state->jiggy_index, 1, state->light_slot);
        func_800C8CB8(state->light_slot, actor->position);
    } else {
        state->light_slot = 0;
    }
    state->orbit_angle = 0.0f;
    state->arc_angle = -70.0f;
    state->spin_speed = 500.0f;
    func_800FC660(0x1C);
    func_800FC660(5);
    actor->unk64_20 = 1;
}

// Per frame: state 1 circles the jiggy above the player on an arc; state 2 spins it up and sparkles it away.
void func_808000CC_chjigsawcollect(Actor *actor)
{
    f32 prev_orbit;
    f32 player_pos[3];
    f32 fx_pos[3];
    f32 rand_a;
    f32 rand_b;
    f32 *state;
    f32 dt;
    s32 i;
    f32 height;

    state = func_80100094(actor, 0);
    dt = func_800D8FF8();
    func_800F5A00(func_800F54E4(), player_pos);
    // Matching: empty block steers IDO's register allocation.
    if (1) {
    }
    player_pos[1] += 120.0f;
    switch (((JigState *) actor)->st) {
        case 1:
            prev_orbit = state[1];
            state[1] += 600.0f * dt;
            state[0] += 60.0f * dt;
            if (90.0f <= state[0]) {
                state[0] = 90.0f;
                func_80101FDC(actor, 2);
                if (actor->unk64_20) {
                    func_800FCAE0(0x1C, 0, 0x1F4);
                    func_800FCA90(0x1C);
                    actor->unk64_20 = 0;
                }
                _subaddieaudioquick_entrypoint_2(actor, actor->position,
                                                 D_808006B8_chjigsawcollect);
            } else if (func_80013728(prev_orbit) <= 0.0f && 0.0f < func_80013728(state[1]) &&
                       func_80013728(state[0]) < 70.0f) {
                func_800C4B64(func_800F10B4(func_80013728(state[0]), -70.0f, 70.0f, 1.0f, 1.2f));
                _subaddieaudioquick_entrypoint_2(actor, actor->position,
                                                 D_808006C4_chjigsawcollect);
            }
            state[0] = func_80013728(state[0]);
            state[1] = func_80013728(state[1]);
            actor->rotation[1] = func_800136E4(func_800F1DF4(actor->position, player_pos));
            func_80103DFC(actor, fx_pos);
            rand_a = func_800DC178(0.0f, 360.0f);
            rand_b = func_800DC178(0.0f, 360.0f);
            func_800EF214(fx_pos, rand_a, rand_b, 20.0f);
            func_808005B8_chjigsawcollect(actor, fx_pos);
            break;
        case 2:
            state[2] = func_800F15F8(state[2], 1600.0f, dt * 1000.0f);
            actor->rotation[1] += dt * state[2];
            for (i = 0; i != 4; i++) {
                if (func_800DC0C0() < 0.08f) {
                    func_80103DFC(actor, fx_pos);
                    func_800EF214(fx_pos, func_800DC178(0.0f, 360.0f), func_800DC178(0.0f, 360.0f),
                                  20.0f);
                    _fxtwinkle_entrypoint_0(fx_pos);
                }
            }
            if (!func_8001210C(3)) {
                func_80103DFC(actor, fx_pos);
                func_808005B8_chjigsawcollect(actor, fx_pos);
            }
            if (state[2] == 1600.0f) {
                _fxsparkle_entrypoint_1(actor->position, 0xA);
                if (*(s32 *) &state[4]) {
                    *(s32 *) &state[4] =
                        _chlightfader_entrypoint_1(*(s32 *) &state[4], 2.2f, 2);
                }
                func_800FFAB0(actor);
            }
            break;
    }
    func_800EE7F8(actor->position, player_pos);
    height = func_800F10B4(state[0], -70.0f, 90.0f, 10.0f, 40.0f);
    func_800EF214(actor->position, state[0], state[1], 120.0f + height);
    if (*(s32 *) &state[4]) {
        func_800EE7F8(fx_pos, actor->position);
        fx_pos[1] += 100.0f;
        func_800C8CB8(*(s32 *) &state[4], fx_pos);
    }
}

// Free: releases the light slot and restores the music.
void func_80800524_chjigsawcollect(actor) Actor *actor;
{
    s32 *data;
    data = func_80100094(actor, 0);
    if (data[4] != 0) {
        func_800C8B84(data[4]);
        data[4] = 0;
    }
    if (actor->unk64_20) {
        func_800FCAE0(0x1C, 0, 0x1F4);
        func_800FCA90(0x1C);
        actor->unk64_20 = 0;
    }
}

s32 func_808005A4_chjigsawcollect(s32 arg0, s32 arg1, s32 arg2)
{
    return 0;
}

// Matching: intentionally returns nothing despite the int type.
int func_808005B8_chjigsawcollect(s32 actor, s32 pos)
{
    extern f32 D_808006D0_chjigsawcollect[];
    func_800BBCB8(pos, 0, 0x3F800000, 1, &D_808006D0_chjigsawcollect);
}

// Spawns the jiggy-collected sequence actor for the given jiggy index.
void chjigsawcollect_entrypoint_1(Actor **spawner, s32 jiggy_index, s32 flag)
{
    Actor *jiggy;

    jiggy = func_80108528(0x4EF, (*spawner)->position, 0, spawner);
    ((JiggyCollectFlags *) jiggy)->collect = flag;
    ((s32 *) func_80100094(jiggy, 0))[3] = jiggy_index;
}

// TU-NOTE: the .data of this overlay is defined here in C; its tables point to functions of this file,
// and IDO schedules some of them differently unless they are in the same unit. Values come from the ROM.
// The extern of D_808006D0 is retyped to f32[].
void *D_80800670_chjigsawcollect = (void *) 0x015804EF;
static u32 D_80800670_chjigsawcollect_rest[17] = {0x6100001,
                                                  0x0,
                                                  (u32) func_808000CC_chjigsawcollect,
                                                  (u32) func_80105834,
                                                  (u32) func_80101870,
                                                  0x0,
                                                  0x0,
                                                  0x0,
                                                  0x4,
                                                  (u32) func_80800524_chjigsawcollect,
                                                  0x0,
                                                  0x140000,
                                                  (u32) func_8080000C_chjigsawcollect,
                                                  (u32) func_80107C2C,
                                                  0x80000002,
                                                  (u32) func_808005A4_chjigsawcollect,
                                                  0x0};
u8 D_808006B8_chjigsawcollect[12] = {0x0,  0x13, 0x6, 0x65, 0x0, 0x16,
                                     0x65, 0x90, 0x0, 0x1B, 0x0, 0x0};
u8 D_808006C4_chjigsawcollect[12] = {0x0, 0x13, 0x6, 0x64, 0x0, 0x1D,
                                     0x0, 0x1B, 0x0, 0x0,  0x0, 0x0};
f32 D_808006D0_chjigsawcollect[12] = {2.666775e-39f, 2.570833e-39f, -1.408986e+38f, 1.8734871e-38f,
                                      3.12255e-39f,  9.36723e-39f,  6.42903e-40f,   3.78e-43f,
                                      3.78e-43f,     0.0f,          0.0f,           0.0f};
