#include "common.h"

extern void func_800C3418(u8, s32);
extern void func_800C32C4(u8, s32);
extern u8 D_808001D0_subaddieaudioquick[];
extern s32 func_80101E14(Actor *, f32);

void subaddieaudioquick_entrypoint_0(param_0, param_1) u8 param_0; s32 param_1; {
    if (param_1) {
        func_800C3418(param_0, 1);
        func_800C32C4(param_0, 0x40);
    } else {
        func_800C3418(param_0, 2);
    }
}

int subaddieaudioquick_entrypoint_1(param_0, param_1) Actor *param_0; s32 param_1;
{
  u8 local_0;
  local_0 = func_800C4350(0, param_1, D_808001D0_subaddieaudioquick);
  return subaddieaudioquick_entrypoint_0(local_0, (*(s32 *)((char *)(param_0) + 0x70)) & 1), local_0;
}

int subaddieaudioquick_entrypoint_2(s32 param_0, s32 param_1, s32 param_2)
{
  u8 local_0;
  local_0 = subaddieaudioquick_entrypoint_1(param_0);
  func_800C4350(local_0, param_1, param_2);
  func_800C3BDC(local_0);
}

s32 subaddieaudioquick_entrypoint_3(s32 param_0, s32 param_1, s32 param_2, f32 param_3) {
    if (func_80101E14(param_0, param_3)) {
        subaddieaudioquick_entrypoint_2(param_0, param_1, param_2);
        return 1;
    }
    return 0;
}

s32 subaddieaudioquick_entrypoint_4(Actor *param_0, f32 *param_1, void *param_2, f32 *param_3)
{
    while (-1.0f != *param_3) {
        if (func_80101E14(param_0, *param_3)) {
            subaddieaudioquick_entrypoint_2((s32)param_0, (s32)param_1, (s32)param_2);
            return 1;
        }
        param_3++;
    }
    return 0;
}
