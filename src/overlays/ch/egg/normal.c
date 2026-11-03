#include "common.h"

typedef struct {
    u8 pad_0[0x30];
    f32 unk_30;
    u8 pad_34[5];
    u8 done : 1;
    u8 pad_39 : 7;
} EggUpdateLocal;
extern void *func_80100094(Actor *, u32);
extern s32 func_800EEEA8(void *);
extern f32 func_800F10B4(f32, f32, f32, f32, f32);
extern s32 _suegg_entrypoint_8(Actor *);
extern void _suegg_entrypoint_16(Actor *);
extern s32 _suegg_entrypoint_14(Actor *);
extern s32 _sueggmove_entrypoint_3(Actor *);
extern void _suegg_entrypoint_23(Actor *);
extern s32 _suegg_entrypoint_13(Actor *);
extern s32 _suegg_entrypoint_12(Actor *);
extern void _sueggmisc_entrypoint_1(Actor *);
extern void _suegg_entrypoint_3(Actor *);
extern int D_808004D0_cheggnormal[];
typedef struct {
    u8 pad_0[0x39];
    u8 pad_1 : 3;
    u8 velocity_trail : 1;
    u8 pad_2 : 4;
} NormalEggFlags;
extern Actor *_suegg_entrypoint_11(s32, f32 *, s32);
extern void _sueggmove_entrypoint_6(Actor *, f32, f32);
extern void _suegg_entrypoint_1(Actor *, f32);
typedef struct {
    u8 pad_0[0x38];
    u32 pad_1 : 11;
    u32 velocity_trail : 1;
    u32 pad_2 : 20;
} EggNormalFlags;
extern f32 func_800D8FF8(void);
extern f32 func_800DC0C0(void);
extern void func_800EFA20(f32 *, f32 *, f32);
extern void _fxegg_entrypoint_7(f32 *, f32 *, f32);
extern void _fxegg_entrypoint_8(f32 *, f32 *, f32);
extern void _fxegg_entrypoint_2(f32 *, f32);
extern void _fxegg_entrypoint_1(f32 *, f32);

typedef struct {
    u8 pad_0[0x38];
    u8 unk_38;
    u8 pad_1 : 3;
    u8 velocity_trail : 1;
    u8 pad_2 : 4;
} NormalEggSpawnState;
typedef struct {
    u8 pad_0[0x72];
    u8 state : 6;
    u8 pad_1 : 2;
} NormalEggActorState;

// Spawns a random sparkle sprite (with velocity when flagged) while the trail timer runs out.
void func_80800000_cheggnormal(actor) Actor *actor;
{
    f32 interval;
    u8 *data;
    f32 pos[3];
    f32 velocity[3];
    data = func_80100094(actor, 0);
    *(f32 *) (data + 0x28) -= func_800D8FF8();
    interval = func_800F10B4(*(f32 *) (data + 0x30), 0.0f, 2.0f, 0.0333f, 0.1f);
    while (*(f32 *) (data + 0x28) <= 0) {
        *(f32 *) (data + 0x28) += interval;
        func_800EE7F8(pos, actor->position);
        if (((EggNormalFlags *) data)->velocity_trail) {
            func_800EFA20(velocity, (f32 *) ((u8 *) actor + 0x28), 0.125f);
            if (func_800DC0C0() < 0.5f) {
                _fxegg_entrypoint_7(pos, velocity, actor->scale);
            } else {
                _fxegg_entrypoint_8(pos, velocity, actor->scale);
            }
        } else if (func_800DC0C0() < 0.5f) {
            _fxegg_entrypoint_2(pos, actor->scale);
        } else {
            _fxegg_entrypoint_1(pos, actor->scale);
        }
    }
}

void func_80800194_cheggnormal(Actor *actor)
{
    EggUpdateLocal *state;

    state = func_80100094(actor, 0);
    switch (actor->unk70_10) {
        case 1:
            if (!_suegg_entrypoint_8(actor)) {
                if (func_800EEEA8(&actor->actorData[4])) {
                    state->done = 1;
                } else {
                    func_80800000_cheggnormal(actor);
                    _suegg_entrypoint_16(actor);
                    if (_suegg_entrypoint_14(actor)) {
                        state->done = 1;
                    }
                }
            }
            break;
        case 2:
            if (!_suegg_entrypoint_8(actor)) {
                actor->scale = func_800F10B4(state->unk_30, 0.0f, 0.134f, 0.1f, 0.25f);
                if (_sueggmove_entrypoint_3(actor)) {
                    _suegg_entrypoint_23(actor);
                }
                if (_suegg_entrypoint_13(actor)) {
                    state->done = 1;
                } else if (_suegg_entrypoint_12(actor)) {
                    _sueggmisc_entrypoint_1(actor);
                } else {
                    func_80800000_cheggnormal(actor);
                    _suegg_entrypoint_16(actor);
                }
            }
            break;
    }
    if (state->done) {
        _suegg_entrypoint_3(actor);
    }
}

void *cheggnormal_entrypoint_0()
{
    return (void *) &D_808004D0_cheggnormal;
}

Actor *cheggnormal_entrypoint_1(void *unk_0, f32 *pos, s32 velocity, s32 player)
{
    Actor *egg;
    NormalEggSpawnState *data;

    _sueggmove_entrypoint_10(unk_0, pos, velocity, player);
    egg = _suegg_entrypoint_11(0x15A, pos, player);
    data = func_80100094(egg, 0);
    data->unk_38 = 1;
    egg->scale = 0.134f;
    _suegg_entrypoint_1(egg, 30.0f);
    _sueggmove_entrypoint_5(egg, 1);
    _sueggmove_entrypoint_6(egg, -2200.0f, -22000.0f);
    _sueggmove_entrypoint_7(egg, velocity);
    ((NormalEggActorState *) egg)->state = 2;
    data->velocity_trail = 0;
    return egg;
}

Actor *cheggnormal_entrypoint_2(void *unk_0, f32 *pos, s32 velocity, s32 player)
{
    Actor *egg;
    NormalEggFlags *data;
    _sueggmove_entrypoint_10(unk_0, pos);
    egg = _suegg_entrypoint_11(0x15A, pos, player);
    data = func_80100094(egg, 0);
    egg->scale = 0.25f;
    _sueggmove_entrypoint_5(egg, 0);
    _sueggmove_entrypoint_6(egg, 0.0f, -100000.0f);
    _suegg_entrypoint_1(egg, 30.0f);
    _sueggmove_entrypoint_7(egg, velocity);
    egg->unk70_10 = 1;
    if (func_800F693C(player))
        data->velocity_trail = 1;
    else
        data->velocity_trail = 0;
    return egg;
}

// TU-NOTE: this overlay's .data is defined here in C. Its tables point at functions of this
// file, and IDO's assembler schedules some of them differently otherwise. Values are from the ROM.
// D_808004D0_cheggnormal is declared int[] to match the object.
extern void func_80105834();
extern void _subaddiedraw25d_entrypoint_2();
extern void _suegg_entrypoint_2();
extern void _suegg_entrypoint_0();
extern void _suegg_entrypoint_5();
extern void func_80107C2C();
extern void _suegg_entrypoint_17();
int D_808004D0_cheggnormal[20] = {0x26C015A,
                                  0x9D70001,
                                  0x0,
                                  (u32) func_80800194_cheggnormal,
                                  (u32) func_80105834,
                                  (u32) _subaddiedraw25d_entrypoint_2,
                                  0x0,
                                  0x3F800000,
                                  0x0,
                                  0x4,
                                  (u32) _suegg_entrypoint_2,
                                  (u32) _suegg_entrypoint_0,
                                  0x4C0000,
                                  (u32) _suegg_entrypoint_5,
                                  (u32) func_80107C2C,
                                  -0x78000000,
                                  (u32) _suegg_entrypoint_17,
                                  0x0,
                                  0x0,
                                  0x0};
