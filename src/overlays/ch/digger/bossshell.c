#include "common.h"

extern void *D_80800560_chdiggerbossshell;
extern void *D_808005A8_chdiggerbossshell;
typedef union { s32 word; void *pointer; } DiggerBossShellEventPayload;
extern int D_808005F0_chdiggerbossshell;
extern u32 D_80800600_chdiggerbossshell;
extern s32 func_800D9078(f32 *);
typedef struct { s16 a, b; } S16Pair;
extern s32 D_8080060C_chdiggerbossshell;
extern f32 func_800EFB8C(f32 *, f32 *);
extern f32 func_80102D78(Actor *, f32 *);
extern f32 sqrtf(f32);
extern void func_800EEC30(f32 *, f32, f32, f32);
extern f32 func_800D8FF8(void);
extern void _fxegg_entrypoint_5(f32 *, f32 *, f32);
extern void func_800EF174(f32 *, f32 *, f32);
extern void func_800F1A88(f32 *, f32 *);
extern f32 func_8010CD28(void);
extern Actor *func_80108528(s32, f32 *, s32, Actor **);
extern void func_80102FDC(Actor *, f32);
extern f32 func_800136E4(f32);
void func_808001EC_chdiggerbossshell();
int func_808002CC_chdiggerbossshell();
void func_80800504_chdiggerbossshell();
Actor *func_80800330_chdiggerbossshell();

void *chdiggerbossshell_entrypoint_0(void)
{
    return &D_80800560_chdiggerbossshell;
}

int chdiggerbossshell_entrypoint_1()
{
    return (int)&D_808005A8_chdiggerbossshell;
}

void func_80800018_chdiggerbossshell(Actor *param_0)
{
    f32 local_0;
    f32 local_1;
    f32 local_2;
    f32 local_3;
  s32 pad0;

    local_0 = func_800EFB8C(param_0->position, (f32 *)param_0->actorData);
    local_1 = param_0->position[1] - ((f32 *)param_0->actorData)[1];
    param_0->rotation[0] = 45.0f;
    param_0->rotation[1] = func_80102D78(param_0, (f32 *)param_0->actorData);
    local_3 = (local_0 * local_0 * 9800.0f) / (local_0 + local_1);
    local_2 = sqrtf(local_3);
    func_800EEC30((f32 *)&param_0->actorData[4], param_0->rotation[0], param_0->rotation[1], local_2);
}

void func_808000B4_chdiggerbossshell(Actor *param_0)
{
    f32 local_0;

    if (param_0->unk70_10 == 1) {
        local_0 = func_800D8FF8();
        _fxegg_entrypoint_5(param_0->position, (f32 *)&param_0->actorData[4], 1.0f);
        func_800EF174(param_0->position, (f32 *)&param_0->actorData[4], func_800D8FF8());
        if (param_0->position[1] < ((f32 *)param_0->actorData)[1]) {
            param_0->position[1] = ((f32 *)param_0->actorData)[1];
            func_808001EC_chdiggerbossshell(param_0);
        }
        ((f32 *)param_0->actorData)[5] += -9800.0f * local_0;
        func_800F1A88((f32 *)&param_0->actorData[4], param_0->rotation);
        param_0->rotation[0] += 90.0f;
    }
}

s32 func_80800188_chdiggerbossshell(Actor *param_0, s32 param_1, DiggerBossShellEventPayload param_2)
{
    switch (param_1) {
    case 0x40:
        func_808001EC_chdiggerbossshell(param_0);
        break;
    case 0x3D:
        func_800FFAB0(func_80800330_chdiggerbossshell(param_0));
        break;
    default:
        return 0;
    }
    return 1;
}

void func_808001EC_chdiggerbossshell(param_0) s32 param_0;
{
  f32 local_0[3];
  func_800EE7F8(local_0, param_0 + 4);
  local_0[1] += 50.0f;
  func_800BBCB8(local_0, 0, 0x3FB33333, 1, _fxgenlist_entrypoint_2());
  _subaddieaudioquick_entrypoint_2(param_0, local_0, &D_808005F0_chdiggerbossshell);
  func_800E1610(0, 0x41A00000, 0x3F666666, param_0 + 4);
  func_80018820(0, 0x40000000, 0x3E800000);
  local_0[1] += 50.0f;
  func_808002CC_chdiggerbossshell(local_0);
  func_8010A570(param_0);
  func_80101FDC(param_0, 2);
  func_80108B04(param_0, 0);
}

int func_808002CC_chdiggerbossshell(param_0) s32 param_0;
{
  s32 local_0;
  local_0 = func_800C8A98();
  func_800C8CB8(local_0 | 0, param_0);
  func_800C8E84(local_0, &D_80800600_chdiggerbossshell);
  func_800C8E54(local_0, 0x44160000, 0x447A0000);
  _chlightfader_entrypoint_1(local_0, 0x3FB33333, 5);
}

Actor *func_80800330_chdiggerbossshell(param_0) Actor *param_0;
{
    f32 local_0;
    s32 local_2;
    Actor *local_3;
    f32 local_1[3];
    local_0 = func_8010CD28() + param_0->unk54;
    func_800EE7F8(local_1, param_0->position);
    if (local_1[1] < 7500.0f) local_1[1] = 7500.0f;
    local_1[1] += 60.0f;
    for (local_2 = 0; local_2 < 4; local_2++) {
        local_3 = func_80108528(0x4F4, local_1, (s32)local_0, &param_0);
        func_80102FDC(local_3, param_0->scale);
        func_80103140(local_3, (u16)(local_2 + 0x905), 0);
        *(f32 *)((u8 *)local_3 + 0x24) = *(f32 *)((u8 *)param_0 + 0x24);
        local_0 = func_800136E4(local_0 + 90.0f);
    }
    return param_0;
}

void func_8080044C_chdiggerbossshell(void *param_0) {
    ((struct Actor *)param_0)->unk58 = 1.75;
}

void func_8080045C_chdiggerbossshell(Actor *param_0)
{
    if (param_0->unk70_10 == 1) {
        if (func_8010B990(param_0, 0x400005) & 0x20) {
            func_80800504_chdiggerbossshell(param_0);
        }
        if (func_800D9078(&param_0->unk58)) {
            _subaddiefade_entrypoint_3(param_0);
        }
    }
}

s32 func_808004C8_chdiggerbossshell(s32 param_0, s32 param_1, s32 param_2) {
    if (param_1 == 0x40) {
        func_80800504_chdiggerbossshell(param_0);
    } else {
        return 0;
    }
    return 1;
}

void func_80800504_chdiggerbossshell(param_0) s32 param_0; {
    s32 local_0;

    local_0 = param_0 + 4;
    func_800BBCB8(local_0, local_0, 0x3F800000, 3, &D_8080060C_chdiggerbossshell);
    func_8010A570(param_0);
    func_800FFAB0(param_0);
}
