#include "common.h"

extern void *func_80100094(Actor *, u32);
extern f32 func_800F10B4(f32, f32, f32, f32, f32);
typedef struct {
    u8 pad_0[0x38];
    u32 pad_1 : 12;
    u32 unk_39 : 1;
    u32 pad_2 : 19;
} ClockworkEggEventState;
extern int D_808008C0_cheggclockwork[];
typedef union {
    s32 word;
    f32 value;
} EggFloatWord1446;
extern void _cheggsplode_entrypoint_2(f32 *, f32, s32, s32, s32);
extern void *func_8001B798(s32);
extern void func_800EE7F8(f32 *, f32 *);
typedef struct {
    u8 pad_0[0x2C];
    s16 history_handle;
} ClockworkData;
typedef struct {
    u8 pad_0[0x28];
    f32 timer;
    u32 pad_1;
    f32 age;
} ClockworkEmitState1408;
extern f32 func_800D8FF8(void);
extern void _fxegg_entrypoint_4(f32 *, f32);
typedef struct {
    u8 pad_0[0x39];
    u8 pad_1 : 4;
    u8 unk_39 : 1;
    u8 pad_2 : 3;
} ClockworkEggLaunchState;
extern Actor *_suegg_entrypoint_11(s32, f32 *, s32);
extern void _suegg_entrypoint_1(Actor *, f32);
extern void _sueggmove_entrypoint_6(Actor *, f32, f32);
extern u8 D_80800908_cheggclockwork[];
extern u8 D_80800950_cheggclockwork[];
extern u8 D_80800998_cheggclockwork[];
extern u8 D_808009E0_cheggclockwork[];
extern void _cheggclockwork_entrypoint_2();
extern void func_800C9C70(f32, s32, f32, s32, f32 *, f32, f32);
extern void func_800BBCB8(f32 *, s32, f32, s32, void *);
extern void _chbaddiesetup_entrypoint_6(void (*)(), f32, f32, f32, s32, s32, s32);
int func_80800270_cheggclockwork();
void func_808006E8_cheggclockwork();
void func_808007B4_cheggclockwork();
void func_80800850_cheggclockwork();
void cheggclockwork_entrypoint_3();

void func_80800000_cheggclockwork(s32 *actor)
{
    s16 unk_0 = *(s16 *) ((char *) func_80100094(actor, 0) + 0x3A);
    func_800F7BC8(unk_0, 0x4D, *actor);
    func_808007B4_cheggclockwork(actor);
    _suegg_entrypoint_2(actor);
}

// Emits trail particles while the egg flies
void func_80800048_cheggclockwork(actor) Actor *actor;
{
    ClockworkEmitState1408 *data;
    f32 interval;
    f32 pos[3];

    data = func_80100094(actor, 0);
    data->timer -= func_800D8FF8();
    interval = func_800F10B4(data->age, 0, 2.0f, 0.0333f, 0.1f);
    if (data->timer <= 0.0f) {
        do {
            data->timer += interval;
            func_800EE7F8(pos, actor->position);
            _fxegg_entrypoint_4(pos, actor->scale);
        } while (data->timer <= 0.0f);
    }
}

// Per-frame update; result 3 = no valid player to hand over to
void func_80800124_cheggclockwork(Actor *actor)
{
    u8 *data;
    s32 result;
    data = func_80100094(actor, 0);
    result = 0;
    if (_suegg_entrypoint_9(actor, 0)) {
        if (func_800F693C(*(s16 *) (data + 0x3A)))
            result = 2;
        else
            result = 1;
    } else {
        actor->scale = func_800F10B4(*(f32 *) (data + 0x30), 0.0f, 0.134f, 0.1f, 0.25f);
        if (_sueggmove_entrypoint_3(actor)) {
            _suegg_entrypoint_23(actor);
            result = 1;
        }
        if (func_800EEEA8((f32 *) ((u8 *) actor + 0x28)))
            result = 1;
        if (*(f32 *) (data + 0x30) > 1.0f) {
            _suegg_entrypoint_3(actor);
            result = 2;
        }
        func_80800048_cheggclockwork(actor);
        _suegg_entrypoint_16(actor);
    }
    if ((result == 1 || result == 2) && !func_80800270_cheggclockwork(actor))
        result = 3;
    if (result)
        func_80108B04(actor, result);
    else
        func_80800850_cheggclockwork(actor);
}

int func_80800270_cheggclockwork(actor)
s32 actor;
{
    Actor *data;
    data = func_80100094(actor, 0);
    if (func_800DB9B0() != 0) {
        return 0;
    }
    if (func_800F6D24(*(s16 *) ((char *) data + 0x3A)) != 0) {
        return 0;
    }
    if (func_800F8088(*(s16 *) ((char *) data + 0x3A)) != 0) {
        return 0;
    }
    return 1;
}

void func_808002DC_cheggclockwork(Actor *actor, s32 result)
{
    Actor *data;

    data = func_80100094(actor, 0);
    switch (result) {
        case 1:
            if (func_80800270_cheggclockwork(actor) != 0) {
                func_808006E8_cheggclockwork(actor);
                func_800F7CF4(*(s16 *) ((char *) data + 0x3A), 0x4C,
                              (Actor *) ((char *) actor + 4));
            }
            _suegg_entrypoint_3(actor);
            return;
        case 2:
            cheggclockwork_entrypoint_3(func_8001B798(*(s16 *) ((char *) data + 0x2C)),
                                        *(s32 **) ((char *) actor + 0x48),
                                        *(s16 *) ((char *) data + 0x3A), 1);
            func_800FFAB0(actor);
            return;
        case 3:
            _suegg_entrypoint_3(actor);
    }
}

s32 func_808003B4_cheggclockwork(Actor *actor, s32 msg, s32 result)
{
    ClockworkEggEventState *data;

    data = func_80100094(actor, 0);
    switch (msg) {
        case 5:
            func_808002DC_cheggclockwork(actor, 2);
            break;
        case 0x3D:
            if (result == 1 && !data->unk_39)
                result = 2;
            func_808002DC_cheggclockwork(actor, result);
            break;
        case 0x2C:
            func_808002DC_cheggclockwork(actor, 3);
            break;
        case 0x9F:
            func_808002DC_cheggclockwork(actor, 3);
            break;
        default:
            return 0;
    }
    return 1;
}

int cheggclockwork_entrypoint_0()
{
    return (int) &D_808008C0_cheggclockwork;
}

void func_808007DC_cheggclockwork();

Actor *cheggclockwork_entrypoint_1(f32 *origin, f32 *pos, f32 *unk_2, s32 unk_3,
                                   s32 unk_4)
{
    Actor *egg;
    ClockworkEggLaunchState *data;

    _sueggmove_entrypoint_10(origin, pos, unk_2, unk_3);
    egg = _suegg_entrypoint_11(0x15E, pos, unk_3);
    data = (ClockworkEggLaunchState *) func_80100094(egg, 0);
    func_808007DC_cheggclockwork(egg, origin);
    data->unk_39 = unk_4;
    egg->scale = 0.134f;
    _suegg_entrypoint_1(egg, 30.0f);
    _sueggmove_entrypoint_5(egg, 1);
    _sueggmove_entrypoint_6(egg, -2200.0f, -100000.0f);
    _sueggmove_entrypoint_7(egg, unk_2);
    egg->unk70_10 = 2;
    return egg;
}

void cheggclockwork_entrypoint_2(EggFloatWord1446 x, EggFloatWord1446 y,
                                 EggFloatWord1446 z, s32 unk_3, s32 unk_4, s32 unk_5)
{
    f32 pos[3];
    f32 unk_1;

    unk_1 = *(f32 *) &unk_3;
    pos[0] = x.value;
    pos[1] = y.value;
    pos[2] = z.value;
    _cheggsplode_entrypoint_2(pos, unk_1, unk_4, 5, unk_5);
}

// Explosion: light, particle bursts and the egg explosion
void cheggclockwork_entrypoint_3(pos, unk_1, unk_2, unk_3) f32 *pos;
s32 unk_1;
s32 unk_2;
s32 unk_3;
{
    func_800C9C70(0.4f, 0x5F3, 1.0f, 20000, pos, 250.0f, 5400.0f);
    func_800BBCB8(pos, 0, 1.0f, 1, D_80800908_cheggclockwork);
    func_800BBCB8(pos, 0, 1.0f, 6, D_80800950_cheggclockwork);
    func_800BBCB8(pos, 0, 1.0f, 2, D_80800998_cheggclockwork);
    func_800BBCB8(pos, 0, 1.0f, 1, D_808009E0_cheggclockwork);
    _chbaddiesetup_entrypoint_6(_cheggclockwork_entrypoint_2, pos[0], pos[1], pos[2],
                                unk_1, unk_2, unk_3);
}

// If the egg position is invalid, falls back to the newest valid history point
void func_808006E8_cheggclockwork(actor) Actor *actor;
{
    f32 *history;

    history = func_8001B798(((ClockworkData *) func_80100094(actor, 0))->history_handle);
    if (!func_800F6DE0(actor->position)) {
        if (func_800F6DE0(history)) {
            func_800EE7F8(actor->position, history);
            return;
        }
        if (func_800F6DE0(history + 3)) {
            func_800EE7F8(actor->position, history + 3);
            return;
        }
        if (func_800F6DE0(history + 6)) {
            func_800EE7F8(actor->position, history + 6);
            return;
        }
        func_800EE7F8(actor->position, history + 6);
    }
}

void func_808007B4_cheggclockwork(actor) s32 actor;
{
    func_8001B754((*(s16 *) ((s8 *) (func_80100094(actor, 0)) + 0x2C)));
}

// Allocates the 3-point position history and fills it with pos
void func_808007DC_cheggclockwork(Actor *actor, f32 *pos)
{
    ClockworkData *data;
    f32 *history;
    data = func_80100094(actor, 0);
    data->history_handle = func_8001B668(0, 0x24);
    history = func_8001B798(data->history_handle);
    func_800EE7F8(history, pos);
    func_800EE7F8(history + 3, pos);
    func_800EE7F8(history + 6, pos);
}

// Shifts the position history and stores the current position
void func_80800850_cheggclockwork(actor) Actor *actor;
{
    ClockworkData *data;
    f32 *history;

    data = func_80100094(actor, 0);
    history = func_8001B798(data->history_handle);
    func_800EE7F8(history + 6, history + 3);
    func_800EE7F8(history + 3, history);
    func_800EE7F8(history, actor->position);
}

extern void func_80105834();
extern void _subaddiedraw25d_entrypoint_2();
extern void _suegg_entrypoint_0();
extern void _suegg_entrypoint_5();
extern void func_80107C2C();
int D_808008C0_cheggclockwork[18] = {0x270015E,
                                     0x9C40001,
                                     0x0,
                                     (u32) func_80800124_cheggclockwork,
                                     (u32) func_80105834,
                                     (u32) _subaddiedraw25d_entrypoint_2,
                                     0x0,
                                     0x3F800000,
                                     0x0,
                                     0x4,
                                     (u32) func_80800000_cheggclockwork,
                                     (u32) _suegg_entrypoint_0,
                                     0x4C0000,
                                     (u32) _suegg_entrypoint_5,
                                     (u32) func_80107C2C,
                                     -0x78000000,
                                     (u32) func_808003B4_cheggclockwork,
                                     0x0};
u8 D_80800908_cheggclockwork[72] = {
    0x0,  0x1D, 0x8,  0x34, 0x0,  0x16, 0x0,  0x2,  0x0,  0x15, 0x0,  0x19, 0x0,  0xB3, 0x0,
    0x1E, 0x0,  0x1E, 0x0,  0x1E, 0x0,  0x2E, 0xFF, 0xB0, 0x0,  0x0,  0x2,  0x58, 0xFF, 0xB0,
    0x1,  0x67, 0x2,  0x58, 0x0,  0x1B, 0xFA, 0x24, 0xFA, 0x24, 0x0,  0x4,  0x0,  0x99, 0x0,
    0x7,  0x0,  0x3,  0x0,  0x2B, 0x2,  0x80, 0x2,  0x80, 0x0,  0x26, 0x3,  0x84, 0x0,  0xC8,
    0x0,  0x0,  0x3,  0x84, 0x0,  0xC8, 0x0,  0x0,  0x0,  0x0,  0x0,  0x0};
u8 D_80800950_cheggclockwork[72] = {
    0x0,  0x1D, 0x8,  0x33, 0x0,  0xB,  0x0,  0x1E, 0x0,  0x32, 0x0,  0x50, 0x0,  0x1E, 0x0,
    0x15, 0x0,  0x19, 0x0,  0xB3, 0x0,  0x2E, 0xFF, 0xC4, 0x0,  0x0,  0x0,  0xC8, 0xFF, 0xD8,
    0x1,  0x67, 0x1,  0x90, 0x0,  0x1B, 0xFA, 0x24, 0xFA, 0x24, 0x0,  0x4,  0x0,  0x99, 0x0,
    0x7,  0x0,  0x3,  0x0,  0x2B, 0x2,  0x0,  0x2,  0x80, 0x0,  0x26, 0xFF, 0x38, 0xFF, 0x38,
    0xFF, 0x38, 0x0,  0xC8, 0x0,  0xC8, 0x0,  0xC8, 0x0,  0x0,  0x0,  0x0};
u8 D_80800998_cheggclockwork[72] = {
    0x0,  0x1D, 0x8,  0x35, 0x0,  0x16, 0x0,  0x2,  0x0,  0x15, 0x0,  0x19, 0x0,  0xB3, 0x0,
    0x1E, 0x0,  0x1E, 0x0,  0x1E, 0x0,  0x2E, 0xFF, 0xD8, 0x0,  0x0,  0x1,  0x2C, 0xFF, 0xE2,
    0x1,  0x67, 0x1,  0x90, 0x0,  0x1B, 0xFA, 0x24, 0xFA, 0x24, 0x0,  0x4,  0x0,  0x99, 0x0,
    0x7,  0x0,  0x3,  0x0,  0x2B, 0x2,  0x0,  0x2,  0x80, 0x0,  0x26, 0x0,  0xA,  0x0,  0xC8,
    0x0,  0x14, 0x0,  0xA,  0x0,  0xC8, 0x0,  0x14, 0x0,  0x0,  0x0,  0x0};
u8 D_808009E0_cheggclockwork[80] = {
    0x0, 0x1D, 0x8, 0x36, 0x0,  0x16, 0x0,  0x2,  0x0, 0x15, 0x0, 0x19, 0x0, 0xB3, 0x0, 0x1E,
    0x0, 0x1E, 0x0, 0x1E, 0x0,  0x2C, 0x0,  0x0,  0x1, 0xF4, 0x0, 0x0,  0x0, 0x0,  0x1, 0xF4,
    0x0, 0x0,  0x0, 0x1B, 0xFA, 0x24, 0xFA, 0x24, 0x0, 0x4,  0x0, 0xB3, 0x0, 0x7,  0x0, 0x5,
    0x0, 0x2B, 0x3, 0x0,  0x3,  0x0,  0x0,  0x27, 0x0, 0x32, 0x0, 0x64, 0x0, 0x32, 0x0, 0x64,
    0x0, 0x0,  0x0, 0x0,  0x0,  0x0,  0x0,  0x0,  0x0, 0x0,  0x0, 0x0,  0x0, 0x0,  0x0, 0x0};
