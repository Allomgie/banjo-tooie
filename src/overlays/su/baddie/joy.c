#include "common.h"

#define BADDIE_JOY_ACTOR_VIEW_DEFINED
typedef struct { u8 pad0[0x64]; u32 pad64_29 : 3; u32 unk64_27 : 2; u32 pad64_0 : 27; } BaddieJoyActorView;
extern s32 func_80016A74(s32, s32);
extern f32 func_800E3A80(void);
extern f32 func_800136E4(f32);
typedef struct { f32 x; f32 y; } JoyStickVector1409;
typedef struct { u32 pad_0:3; u32 controller:2; u32 pad_1:27; } JoyControllerSelector1408;
extern f32 sqrtf(f32);
extern f32 func_80013B70(f32, f32, f32);
extern f32 func_800F13F0(f32, f32);
extern void func_80015F28(s32, s32 *);
extern void func_80015E80(s32, s32 *);
typedef struct JoyControllerFlags { u32 pad_0 : 3; u32 local_0 : 2; u32 pad_1 : 27; } JoyControllerFlags;
typedef struct { u8 pad[0x64]; u32 pad64:2; u32 flag:1; u32 f:2; u32 rest:27; } JoyS;
extern void func_80018820(s32, f32, f32);

s32 subaddiejoy_entrypoint_0(BaddieJoyActorView *param_0, s32 param_1)
{
    s32 local_0;

    local_0 = func_80016A74(param_0->unk64_27, 0);
    if (local_0 == -1) {
        local_0 = param_1;
    } else {
        local_0 = (s32)func_800E3A80() + local_0 + 0x5A;
    }
    return (s32)func_800136E4((f32)local_0);
}

int subaddiejoy_entrypoint_1(Actor *param_0)
{
  u32 local_0[3];
  func_80015F28(((*((u32 *) (((char *) param_0) + 0x64))) << 3) >> 30, local_0);
  return local_0[0] == 1;
}

s32 subaddiejoy_entrypoint_2(BaddieJoyActorView *param_0, s32 param_1, s32 param_2)
{
    s32 local_0;

    local_0 = func_80016A74(param_0->unk64_27, param_2);
    if (local_0 == -1) {
        local_0 = param_1;
    } else {
        local_0 = (s32)func_800E3A80() + local_0 + 0x5A;
    }
    return (s32)func_800136E4((f32)local_0);
}

f32 subaddiejoy_entrypoint_3(Actor *param_0)
{
    JoyStickVector1409 local_0;
    f32 local_1;
    f32 local_3;
    f32 local_2;

    func_80016068(((JoyControllerSelector1408 *)((u8 *)param_0 + 0x64))->controller, (f32 *)&local_0);
    local_1 = sqrtf(local_0.y * local_0.y + local_0.x * local_0.x);
    if (local_1 != 0.0f) {
        local_2 = func_80013B70(local_0.y, local_0.x, local_1);
        local_3 = func_800E3A80();
        param_0->unk54 = func_800136E4(local_3 + local_2 + 90.0f);
        local_1 = func_800F13F0(1.0f, local_1);
    }
    return local_1;
}

s32 subaddiejoy_entrypoint_4(BaddieJoyActorView *param_0)
{
    s32 local_0[3];
    s32 local_1[6];

    func_80015F28(param_0->unk64_27, local_0);
    if (local_0[0] != 0) {
        return 1;
    }
    func_80015E80(param_0->unk64_27, local_1);
    if ((local_1[0] != 0) || (local_1[1] != 0)) {
        return 1;
    }
    return 0;
}

s32 subaddiejoy_entrypoint_5(BaddieJoyActorView *param_0)
{
    s32 local_0[3];
    s32 local_1[6];

    func_80015F28(param_0->unk64_27, local_0);
    if (local_0[0] == 1) {
        return 1;
    }
    func_80015E80(param_0->unk64_27, local_1);
    if ((local_1[0] == 1) || (local_1[1] == 1)) {
        return 1;
    }
    return 0;
}

void subaddiejoy_entrypoint_6(Actor *param_0)
{
  char *new_var;
  new_var = ((char *) param_0) + 0x64;
  func_80016B30((((*((int *) new_var)) << 3) & 0xFFFFFFFF) >> ((unsigned short) 30));
}

void subaddiejoy_entrypoint_7(Actor *param_0)
{
    func_80016B54((u32)(*((s32 *)(((char *)param_0) + 0x64)) * 8) >> 0x1E);
}

void subaddiejoy_entrypoint_8(Actor *param_0)
{
  func_80016068((((*((int *) (((char *) param_0) + 0x64))) & 0xFFFFFFFF) << 3) >> 30);
}

f32 subaddiejoy_entrypoint_9(Actor *param_0, f32 *param_1, s32 param_2)
{
    f32 local_0[2];
    f32 local_2;
    f32 local_1;

    func_80016068(((JoyControllerFlags *)((u8 *)param_0 + 0x64))->local_0, local_0);
    local_2 = sqrtf(local_0[0] * local_0[0] + local_0[1] * local_0[1]);
    if (local_2 != 0.0f) {
        local_1 = func_800136E4(func_80013B70(local_0[1], local_0[0], local_2) + func_800E3A80() + 90.0f);
        local_2 = func_800F13F0(1.0f, local_2);
        if (param_2 & 1) {
            *param_1 = local_1;
        }
    } else if (param_2 & 2) {
        *param_1 = param_0->rotation[1];
    }
    return local_2;
}

void subaddiejoy_entrypoint_10(JoyS *param_0, f32 param_1, f32 param_2) {
    if (param_0->flag) {
        func_80018820(param_0->f, param_1, param_2);
    }
}
