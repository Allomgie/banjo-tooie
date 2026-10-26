#include "common.h"

extern void *func_80100094(Actor *, u32);
extern f32 func_800F10B4(f32, f32, f32, f32, f32);
typedef struct { u8 pad_0[0x38]; u32 pad_1 : 12; u32 local_0 : 1; u32 pad_2 : 19; } ClockworkEggEventState;
extern int D_808008C0_cheggclockwork;
typedef union { s32 word; f32 value; } EggFloatWord1446;
extern void _cheggsplode_entrypoint_2(f32 *, f32, s32, s32, s32);
extern void *func_8001B798(s32);
extern void func_800EE7F8(f32 *, f32 *);
typedef struct { u8 pad_0[0x2C]; s16 local_0; } ClockworkData;
typedef struct { u8 pad_0[0x28]; f32 timer; u32 pad_1; f32 age; } ClockworkEmitState1408;
extern f32 func_800D8FF8(void);
extern void _fxegg_entrypoint_4(f32 *, f32);
typedef struct { u8 pad_0[0x39]; u8 pad_1:4; u8 local_0:1; u8 pad_2:3; } ClockworkEggLaunchState;
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
void func_80800048_cheggclockwork();
void cheggclockwork_entrypoint_3();

void func_80800000_cheggclockwork(s32 *param_0) {
    s16 val = *(s16 *)((char *)func_80100094(param_0, 0) + 0x3A);
    func_800F7BC8(val, 0x4D, *param_0);
    func_808007B4_cheggclockwork(param_0);
    _suegg_entrypoint_2(param_0);
}

void func_80800048_cheggclockwork(param_0) Actor *param_0;
{
    ClockworkEmitState1408 *local_0;
    f32 local_1;
    f32 local_2[3];

    local_0 = func_80100094(param_0, 0);
    local_0->timer -= func_800D8FF8();
    local_1 = func_800F10B4(local_0->age, 0, 2.0f, 0.0333f, 0.1f);
    if (local_0->timer <= 0.0f) {
        do {
            local_0->timer += local_1;
            func_800EE7F8(local_2, param_0->position);
            _fxegg_entrypoint_4(local_2, param_0->scale);
        } while (local_0->timer <= 0.0f);
    }
}

void func_80800124_cheggclockwork(Actor *param_0)
{
    u8 *local_0;
    s32 local_1;
    local_0 = func_80100094(param_0, 0);
    local_1 = 0;
    if (_suegg_entrypoint_9(param_0, 0)) {
        if (func_800F693C(*(s16 *)(local_0 + 0x3A))) local_1 = 2;
        else local_1 = 1;
    } else {
        param_0->scale = func_800F10B4(*(f32 *)(local_0 + 0x30), 0.0f, 0.134f, 0.1f, 0.25f);
        if (_sueggmove_entrypoint_3(param_0)) {
            _suegg_entrypoint_23(param_0); local_1 = 1;
        }
        if (func_800EEEA8((f32 *)((u8 *)param_0 + 0x28))) local_1 = 1;
        if (*(f32 *)(local_0 + 0x30) > 1.0f) {
            _suegg_entrypoint_3(param_0); local_1 = 2;
        }
        func_80800048_cheggclockwork(param_0);
        _suegg_entrypoint_16(param_0);
    }
    if ((local_1 == 1 || local_1 == 2) && !func_80800270_cheggclockwork(param_0)) local_1 = 3;
    if (local_1) func_80108B04(param_0, local_1);
    else func_80800850_cheggclockwork(param_0);
}

int func_80800270_cheggclockwork(param_0) s32 param_0;
{
  Actor *local_1;
  local_1 = func_80100094(param_0, 0);
  if (func_800DB9B0() != 0)
  {
    return 0;
  }
  if (func_800F6D24(*(s16 *)((char *)(local_1) + 0x3A)) != 0)
  {
    return 0;
  }
  if (func_800F8088(*(s16 *)((char *)(local_1) + 0x3A)) != 0)
  {
    return 0;
  }
  return 1;
}

void func_808002DC_cheggclockwork(Actor *param_0, s32 param_1) {
    Actor *local_0;

    local_0 = func_80100094(param_0, 0);
    switch (param_1) {
    case 1:
        if (func_80800270_cheggclockwork(param_0) != 0) {
            func_808006E8_cheggclockwork(param_0);
            func_800F7CF4(*(s16 *)((char *)local_0 + 0x3A), 0x4C, (Actor *)((char *)param_0 + 4));
        }
        _suegg_entrypoint_3(param_0);
        return;
    case 2:
        cheggclockwork_entrypoint_3(func_8001B798(*(s16 *)((char *)local_0 + 0x2C)), *(s32 **)((char *)param_0 + 0x48), *(s16 *)((char *)local_0 + 0x3A), 1);
        func_800FFAB0(param_0);
        return;
    case 3:
        _suegg_entrypoint_3(param_0);
        return;
    }
}

s32 func_808003B4_cheggclockwork(Actor *param_0, s32 param_1, s32 param_2)
{
    ClockworkEggEventState *local_0;

    local_0 = func_80100094(param_0, 0);
    switch (param_1) {
        case 5:
            func_808002DC_cheggclockwork(param_0, 2);
            break;
        case 0x3D:
            if (param_2 == 1 && !local_0->local_0) param_2 = 2;
            func_808002DC_cheggclockwork(param_0, param_2);
            break;
        case 0x2C:
            func_808002DC_cheggclockwork(param_0, 3);
            break;
        case 0x9F:
            func_808002DC_cheggclockwork(param_0, 3);
            break;
        default:
            return 0;
    }
    return 1;
}

int cheggclockwork_entrypoint_0()
{
  return (int)&D_808008C0_cheggclockwork;
}

void func_808007DC_cheggclockwork();

Actor *cheggclockwork_entrypoint_1(f32 *param_0, f32 *param_1, f32 *param_2, s32 param_3, s32 param_4)
{
    Actor *local_1;
    ClockworkEggLaunchState *local_0;

    _sueggmove_entrypoint_10(param_0, param_1, param_2, param_3);
    local_1 = _suegg_entrypoint_11(0x15E, param_1, param_3);
    local_0 = (ClockworkEggLaunchState *)func_80100094(local_1, 0);
    func_808007DC_cheggclockwork(local_1, param_0);
    local_0->local_0 = param_4;
    local_1->scale = 0.134f;
    _suegg_entrypoint_1(local_1, 30.0f);
    _sueggmove_entrypoint_5(local_1, 1);
    _sueggmove_entrypoint_6(local_1, -2200.0f, -100000.0f);
    _sueggmove_entrypoint_7(local_1, param_2);
    local_1->unk70_10 = 2;
    return local_1;
}

void cheggclockwork_entrypoint_2(EggFloatWord1446 param_0, EggFloatWord1446 param_1,
                               EggFloatWord1446 param_2, s32 param_3,
                               s32 param_4, s32 param_5)
{
    f32 local_0[3];
    f32 local_1;

    local_1 = *(f32 *)&param_3;
    local_0[0] = param_0.value;
    local_0[1] = param_1.value;
    local_0[2] = param_2.value;
    _cheggsplode_entrypoint_2(local_0, local_1, param_4, 5, param_5);
}

void cheggclockwork_entrypoint_3(param_0, param_1, param_2, param_3) f32 *param_0; s32 param_1; s32 param_2; s32 param_3;
{
    func_800C9C70(0.4f, 0x5F3, 1.0f, 20000, param_0, 250.0f, 5400.0f);
    func_800BBCB8(param_0, 0, 1.0f, 1, D_80800908_cheggclockwork);
    func_800BBCB8(param_0, 0, 1.0f, 6, D_80800950_cheggclockwork);
    func_800BBCB8(param_0, 0, 1.0f, 2, D_80800998_cheggclockwork);
    func_800BBCB8(param_0, 0, 1.0f, 1, D_808009E0_cheggclockwork);
    _chbaddiesetup_entrypoint_6(_cheggclockwork_entrypoint_2, param_0[0], param_0[1], param_0[2], param_1, param_2, param_3);
}

void func_808006E8_cheggclockwork(param_0) Actor *param_0;
{
    f32 *local_1;

    local_1 = func_8001B798(((ClockworkData *)func_80100094(param_0, 0))->local_0);
    if (!func_800F6DE0(param_0->position)) {
        if (func_800F6DE0(local_1)) {
            func_800EE7F8(param_0->position, local_1);
            return;
        }
        if (func_800F6DE0(local_1 + 3)) {
            func_800EE7F8(param_0->position, local_1 + 3);
            return;
        }
        if (func_800F6DE0(local_1 + 6)) {
            func_800EE7F8(param_0->position, local_1 + 6);
            return;
        }
        func_800EE7F8(param_0->position, local_1 + 6);
    }
}

void func_808007B4_cheggclockwork(param_0) s32 param_0; {
    func_8001B754((*(s16 *)((s8 *)(func_80100094(param_0, 0)) + 0x2C)));
}

void func_808007DC_cheggclockwork(Actor *param_0, f32 *param_1)
{
    ClockworkData *local_1;
    f32 *local_0;
    local_1 = func_80100094(param_0, 0);
    local_1->local_0 = func_8001B668(0, 0x24);
    local_0 = func_8001B798(local_1->local_0);
    func_800EE7F8(local_0, param_1);
    func_800EE7F8(local_0 + 3, param_1);
    func_800EE7F8(local_0 + 6, param_1);
}

void func_80800850_cheggclockwork(param_0) Actor *param_0;
{
    ClockworkData *local_0;
    f32 *local_1;

    local_0 = func_80100094(param_0, 0);
    local_1 = func_8001B798(local_0->local_0);
    func_800EE7F8(local_1 + 6, local_1 + 3);
    func_800EE7F8(local_1 + 3, local_1);
    func_800EE7F8(local_1, param_0->position);
}
