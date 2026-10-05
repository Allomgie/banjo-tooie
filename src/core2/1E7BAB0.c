#include "common.h"

#define STATE(p) (*(LocalState **)((u8 *)(p)+0xB4))
extern u8 D_80119270[];
typedef struct { u8 pad0[0xC]; s32 color[3]; f32 distance; } LocalHit;
typedef struct { s8 limit; u8 enabled; u8 pad2[2]; void *query; s32 color[3]; } LocalState;
extern f32 func_80092B8C(void *,f32 *);
extern s32 func_800B3494(void *,f32 *,f32);
extern s32 func_800B36C0(void *,s32 *,s32 *,f32);
extern void func_800B37A4(void *,LocalHit **,LocalHit **);
extern s32 func_800B38E8();
s32 func_800A25D0();
void func_800A25DC();

s32 func_800A21C0() 
{
    return 0x14;
}

void func_800A21C8(u8 *param_0) {
    s32 temp_v0;
    s32 var_a1;
    s8 var_a1_2;
    u8 *temp_v0_2;
    u8 *temp_v1;

    temp_v0 = func_800EA05C();
    var_a1 = 0;
    if (*((s16 *)D_80119270) != -1) {
        while (1) {
            if (temp_v0 == *((s16 *)((char *)D_80119270 + var_a1 * 4))) break;
            var_a1++;
            if (*((s16 *)((char *)D_80119270 + var_a1 * 4)) == -1) break;
        }
    }
    temp_v1 = (u8 *)((char *)D_80119270 + (var_a1 * 4));
    (*(u8 *)((char *)*(u8 **)((char *)param_0 + 0xB4) + 0)) = temp_v1[2];
    (*(u8 *)((char *)*(u8 **)((char *)param_0 + 0xB4) + 1)) = temp_v1[3];
    if (*((s16 *)temp_v1) == -1 && func_800C8C18() > 0) {
        (*(u8 *)((char *)*(u8 **)((char *)param_0 + 0xB4) + 0)) = 2;
        (*(u8 *)((char *)*(u8 **)((char *)param_0 + 0xB4) + 1)) = 0;
    }
    temp_v0_2 = *(u8 **)((char *)param_0 + 0xB4);
    var_a1_2 = (s8)temp_v0_2[0];
    if (var_a1_2 >= 3) {
        temp_v0_2[0] = 2U;
        var_a1_2 = (s8)*(*(u8 **)((char *)param_0 + 0xB4));
    }
    func_800A25DC(param_0, var_a1_2);
}

void func_800A22A8(s32 arg0)
{
    func_800A25DC(arg0,0);
}

int func_800A22C8(s32 *param_0, s32 *param_1)
{
  s32 local_0;
  for (local_0 = 0; local_0 < 3; local_0++)
  {
    param_0[local_0] = (param_0[local_0] * param_1[local_0]) / 256;
  }

}

void func_800A2314(s32 param_0, s32 param_1)
{
  f32 local_0[3];
  func_800C87B8(local_0);
  func_800A22C8(local_0, param_1);
  func_800B38A8(((s32 *)*(s32 **)(param_0 + 0xB4))[1], local_0);
}

void func_800A235C(void *param_0)
{
    f32 local_0[3];
    f32 local_1[3];
    f32 local_2;
    s32 local_3;
    s32 local_4[3];
    LocalHit *local_5;
    LocalHit *local_6;
    s32 local_7[3];
    s32 local_8[3];
    s32 local_9;
    s32 local_10[3];
    func_800A1F0C(param_0, local_4);
    func_800A2314(param_0, local_4);
    local_2 = func_80092B8C(param_0, local_1);
    func_8009C128(param_0, local_0);
    func_800EF04C(local_1, local_0);
    local_3 = func_800B3494(STATE(param_0)->query, local_1, local_2);
    func_800B37A4(STATE(param_0)->query, &local_5, &local_6);
    if (local_3 < STATE(param_0)->limit && STATE(param_0)->enabled) {
        func_800C8960(local_8, local_7);
        func_800A22C8(local_8, local_4);
        local_3 += func_800B36C0(STATE(param_0)->query, local_7, local_8, local_3 ? local_5->distance : 500.0f);
    }
    if (local_3) {
        func_800EE830(local_10, local_5->color);
        func_800EE830(local_5->color, STATE(param_0)->color);
        for (local_9 = 0; local_9 < 3; local_9++) {
            if (local_5->color[local_9] < local_10[local_9]) {
                local_5->color[local_9] += 40;
                if (local_10[local_9] < local_5->color[local_9]) local_5->color[local_9] = local_10[local_9];
            } else if (local_10[local_9] < local_5->color[local_9]) {
                local_5->color[local_9] -= 40;
                if (local_5->color[local_9] < local_10[local_9]) local_5->color[local_9] = local_10[local_9];
            }
        }
        func_800EE830(STATE(param_0)->color, local_5->color);
    }
}

void func_800A2534(void *arg)
{
    ((s8 *)(*(void **)((char *)arg + 0xB4)))[3] = 0;
}

void func_800A2540(u8 *param_0, s32 param_1)
{
  s32 sp24;
  s32 sp20;
  s32 sp1C;
  u8 *var_v0;
  if (func_800A25D0() == 0)
  {
    func_800A1F0C(param_0, &sp1C);
    func_800DF5D8(sp1C, sp20, sp24, param_1);
    return;
  }
  var_v0 = *((u8 **) (((s8 *) param_0) + 0xB4));
  if ((*((u8 *) (((s8 *) var_v0) + 3))) == 0)
  {
    func_800A235C(param_0);
    *((s8 *) (((s8 *) (*((u8 **) (((s8 *) param_0) + 0xB4)))) + 3)) = 1;
    if (1)
    {
      var_v0 = *((u8 **) (((s8 *) param_0) + 0xB4));
    }
    if (!sp24)
    {
    }
  }
  func_800DF660(1, 0, *((s32 *) (((s8 *) var_v0) + 4)), param_1);
}

s32 func_800A25D0(param_0) s32 param_0;
{
    return ((u8 *)(*(u8 **)(param_0 + 0xb4)))[2];
}

void func_800A25DC(param_0, param_1) u8 * param_0; s32 param_1; {
    u8 *ptr3;
    s32 ret;

    if (param_1 != 0) {
        (*(u8 **)(param_0 + 0xB4))[2] = 1;
    } else {
        (*(u8 **)(param_0 + 0xB4))[2] = 0;
    }

    ptr3 = *(u8 **)(param_0 + 0xB4);
    if (ptr3[2] != 0) {
        if (*(s32 *)(ptr3 + 4) == 0) {
            ret = func_800B3310((s8)ptr3[0], param_1);
            *(s32 *)((*(u8 **)(param_0 + 0xB4)) + 4) = ret;
        }
    } else {
        if (*(s32 *)(ptr3 + 4) != 0) {
            func_800B3370(*(s32 *)(ptr3 + 4), param_1);
            *(s32 *)((*(u8 **)(param_0 + 0xB4)) + 4) = 0;
        }
    }
}

void func_800A266C(u8 *param_0)
{
  s32 val = *((s32 *) ((*((u8 **) (param_0 + 0xB4))) + 4));
  s32 result;
  if (val)
  {
    result = func_800B38E8(val ^ 0, val, param_0);
    *((s32 *) ((*((u8 **) (param_0 + 0xB4))) + 4)) = result;
  }
}
