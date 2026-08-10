#include "common.h"

extern u8 D_80127115[];
extern void *D_80800090_fxspgold;
extern s32 func_800B56D0(s32);
extern void func_800BABB8(s32, s32, s32, f32, void *);

void fxspgold_entrypoint_0()
{
  func_800B58D4((*(u8 *)((u8 *)((u8 *) D_80127115) + 0xb)));
}

int fxspgold_entrypoint_1()
{
  s32 local_0;
  local_0 = func_800B5758(0x14);
  D_80127115[0xb] = local_0;
}

void fxspgold_entrypoint_2(s32 param_0)
{
  s32 local_0;
  u8 *local_1 = &D_80127115[0xB];
  local_0 = func_800B56D0(*local_1);
  func_800BABB8(local_0 | 0, param_0, 0, 1.0f, &D_80800090_fxspgold);
}
