#include "common.h"

extern s32 D_80136EF0;
typedef struct { u8 pad0[0x60]; s16 id; u8 pad1[0x12]; u32 unused0:6, flat:1, unused1:18, negative:1, unused2:6; u32 unused3:24, count:2, unused4:4, active:1, unused5:1; u8 pad2[0x1A]; s16 mode; u8 red, green, blue, alpha; } LocalActor_80106A98;
extern void func_800DF660(s32, s32, s32, u8);
extern void func_800DF720(s32);
extern s32 func_80100AC4(s16);
extern s32 func_800B27A0(s32);
extern void func_800DF5D8(u8, u8, u8, u8);
typedef struct { u8 pad[0x74]; u32 unused:25, special:1, rest:6; u32 unused1:24, count:2, unused2:4, active:1, rest1:1; } LocalActor_80106C4C;
typedef struct { u8 pad[0x18]; f32 radius; } LocalLight;
extern void _subaddiefade_entrypoint_9(LocalActor_80106C4C *, s32 *);
extern f32 func_80103F38(LocalActor_80106C4C *, f32 *);
extern s32 func_800B3494(s32, f32 *, f32);
extern void func_800B37A4(s32, LocalLight **, s32 *);
extern void func_800C8960(s32 *, s32 *);
extern void func_800B36C0(s32, s32 *, s32 *, f32);
s32 func_80106C4C();
int func_80106D60(s32 param_0, s32 param_1, f32 param_2[3]);
int func_80106DA4();

void func_80106A20(void) {
}

int func_80106A28()
{
  if (D_80136EF0 != 0)
  {
    func_800B3370(D_80136EF0);
    D_80136EF0 = 0;
  }
}

void func_80106A60()
{
  if (D_80136EF0 != 0)
  {
    D_80136EF0 = func_800B38E8(D_80136EF0);
  }
}

void func_80106A98(LocalActor_80106A98 *param_0, s32 param_1)
{
    s32 local_0;
    if (param_0->count) {
        if (((s32)param_0->mode >> 15) != 0) {
            func_800DF660(3, param_0->count, 0, param_0->alpha);
            func_800DF720(func_80100AC4(param_0->id));
            return;
        }
        if (param_0->flat) {
            func_800DF660(2, param_0->count, 0, param_0->alpha);
            func_800DF720(func_80100AC4(param_0->id));
            return;
        }
        local_0 = func_80106C4C(param_0);
        if (!func_800B27A0(param_1)) {
            param_0->count = 0;
            param_0->negative = 0;
            return;
        }
        if (local_0) func_800DF660(1, 0, local_0, param_0->alpha);
        else func_800DF660(1, param_0->negative ? -(s32)param_0->count : (s32)param_0->count, 0, param_0->alpha);
        func_800DF720(func_80100AC4(param_0->id));
        return;
    }
    if (param_0->active) func_800DF5D8(param_0->red, param_0->green, param_0->blue, param_0->alpha);
}

int func_80106C08()
{
  if (!D_80136EF0)
  {
    D_80136EF0 = func_800B3310(6);
  }
  return D_80136EF0;
}

s32 func_80106C4C(param_0) LocalActor_80106C4C * param_0;
{
    f32 local_0[3];
    s32 local_1;
    s32 local_2;
    s32 local_3[3];
    LocalLight *local_4;
    s32 local_5;
    s32 local_8;
    s32 local_6[3];
    s32 local_7[3];
    s32 local_9;
    if (!param_0->active) return 0;
    _subaddiefade_entrypoint_9(param_0, local_3);
    local_1 = func_80106C08();
    func_80106D60(param_0, local_1, local_3);
    local_2 = func_800B3494(local_1, local_0, func_80103F38(param_0, local_0));
    func_800B37A4(local_1, &local_4, &local_5);
    if (local_2 < (s32)param_0->count && param_0->special) {
        func_800C8960(local_7, local_6);
        func_80106DA4(local_7, local_3);
        func_800B36C0(local_1, local_6, local_7, local_2 ? local_4->radius : 500.0f);
    }
    return local_1;
}

int func_80106D60(s32 param_0, s32 param_1, f32 param_2[3])
{
  f32 local_0[3];
  func_800C87B8(local_0);
  func_80106DA4(local_0, param_2);
  func_800B38A8(param_1, local_0);
}

func_80106DA4(param_0, param_1) s32 * param_0; s32 * param_1; {
    s32 local_0;
    for(local_0 = 0; local_0 < 3; local_0++){
        param_0[local_0] = param_0[local_0] * param_1[local_0] >> 8;
    }
}
