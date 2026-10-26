#include "common.h"

extern int D_808004B0_chballoonbomb;
extern void *func_80100094(Actor *, s32);
extern void func_8010D09C(s32, f32 *, f32);
extern s32 func_800DC298(f32);
extern f32 func_800DC178(f32, f32);
extern f32 func_800D8FF8(void);
extern u8 D_808004F8_chballoonbomb[];
extern s32 *_fxgenlist_entrypoint_2(void);
extern void func_800BBCB8(s32, s32, s32, s32, void *);
extern void func_800E1610(s32, f32, f32, f32 *);
extern void func_80018820(s32, f32, f32);
extern s32 D_8080050C_chballoonbomb;
extern s32 D_80800540_chballoonbomb;
extern s32 D_8080057C_chballoonbomb;
extern f32 func_800136E4(f32);
extern f32 func_800F15F8(f32, f32, f32);
typedef union { f32 local_0; s32 local_1; } BalloonUpdateTime;
void func_80800294_chballoonbomb();
s32 func_80800440_chballoonbomb();

int *chballoonbomb_entrypoint_0()
{
    return &D_808004B0_chballoonbomb;
}

void func_8080000C_chballoonbomb(Actor *param_0)
{
    s32 local_2;
    f32 local_1[3];
    f32 *local_0;
    f32 local_4;
    f32 local_3;

    local_0 = func_80100094(param_0, 0);
    func_8010D09C(func_800F54E4(), local_1, param_0->unk58);
    for (local_2 = 0; local_2 < 3; local_2++) {
        ((f32 *)param_0->actorData)[local_2 + 4] = (local_1[local_2] - param_0->position[local_2]) / param_0->unk58;
    }
    ((f32 *)param_0->actorData)[5] += 250.0f * param_0->unk58;
    if (func_800DC298(0.5f)) {
        local_3 = 1.0f;
    } else {
        local_3 = -1.0f;
    }
    local_4 = func_800DC178(300.0f, 400.0f);
    local_0[0] = local_4 * local_3;
}

void func_80800230_chballoonbomb();

void func_80800118_chballoonbomb(Actor *param_0)
{
    f32 *local_0;
    BalloonUpdateTime local_1;

    local_0 = (f32 *)func_80100094(param_0, 0);
    local_1.local_0 = func_800D8FF8();
    if (!param_0->unk64_17) {
        if (func_800DA298(0)) func_80800294_chballoonbomb(param_0);
        else if (!func_800DA298(0x641) && !func_8008FF18()) {
            param_0->rotation[1] = func_800136E4(*local_0 * local_1.local_0 + param_0->rotation[1]);
            func_80800230_chballoonbomb(param_0, local_1.local_1, 1);
            param_0->scale = func_800F15F8(param_0->scale, 1.4f, local_1.local_0 * 1.5f);
        }
    }
}

s32 func_808001F8_chballoonbomb(s32 param_0, s32 param_1, s32 param_2)
{
  if (param_1 == 0x40)
  {
    func_80800294_chballoonbomb(param_0, param_1, param_2);
    if (param_2)
    {
    }
    return 1;
  }
  return 0;
}

void func_80800230_chballoonbomb(Actor *param_0, s32 param_1, s32 param_2)
{
    *(f32 *)&param_0->actorData[5] -= 500.0f * func_800D8FF8();
    if (func_8010B990(param_0, 0x500007) & 0x20) {
        func_80800294_chballoonbomb(param_0);
    }
}

void func_80800294_chballoonbomb(param_0) Actor *param_0;
{
    if (!param_0->unk64_20) {
        func_80800440_chballoonbomb();
        func_800BBCB8(param_0->position, 0, 0x3F800000, 1, _fxgenlist_entrypoint_2());
        func_800C4AF0(param_0->position, D_808004F8_chballoonbomb);
        if (param_0->unk6C_0 >= 4U) {
            func_800E1610(0, 30.0f, 0.9f, param_0->position);
            func_80018820(0, 2.0f, 0.15f);
        }
        param_0->unk64_20 = 1;
        func_800FFAB0(param_0);
    }
}

void func_80800354_chballoonbomb(s32 param_0)
{
  int new_var;
  new_var = param_0 + 4;
  func_800BBCB8(new_var, new_var, *((s32 *) ((param_0 ^ 0) + 0x38)), 8, &D_8080050C_chballoonbomb);
}

void func_80800394_chballoonbomb(s32 *arg0, s32 arg1, s32 arg2)
{
  s32 sp24;
  s32 temp_a1;
  s32 temp_v0;
  if (1)
  {
    temp_v0 = func_800B53A4(arg2);
    sp24 = temp_v0;
    func_800BA670(temp_v0, arg1);
    temp_a1 = arg0 + 1;
  }
  func_800BABB8(sp24, temp_a1, temp_a1, *((s32 *)((u8 *)arg0 + 0x38)), &D_80800540_chballoonbomb);
  func_800BA22C(sp24, arg2);
}

void func_80800400_chballoonbomb(s32 param_0)
{
  func_800BBCB8(param_0 + 4, 0, *((s32 *) ((param_0 + 0x38) ^ 0)), 1, &D_8080057C_chballoonbomb);
}

s32 func_80800440_chballoonbomb(param_0) s32 param_0;{
    func_80800394_chballoonbomb(param_0, 0x93F, 2);
    func_80800394_chballoonbomb(param_0, 0x940, 3);
    func_80800394_chballoonbomb(param_0, 0x941, 4);
    func_80800400_chballoonbomb(param_0);
    func_80800354_chballoonbomb(param_0);
}
