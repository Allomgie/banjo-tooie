#include "common.h"

extern void *D_80800100_chfactorysmoke;
extern int D_80800148_chfactorysmoke;
extern void func_800BBCB8(int, int, float, int, int *);
extern f32 func_800DC178(f32, f32);
extern s32 func_800D9078(f32 *);

int chfactorysmoke_entrypoint_0()
{
  return &D_80800100_chfactorysmoke;
}

void func_8080000C_chfactorysmoke(u8 *param_0) {
    *(f32 *)(param_0 + 0x58) = func_800DC178(0.55f, 0.65f);
}

void func_80800044_chfactorysmoke(Actor *param_0)
{
    if (param_0->unk70_10 == 1 && func_800D9078(&param_0->unk58)) {
        func_808000A8_chfactorysmoke(param_0);
        param_0->unk58 = func_800DC178(0.55f, 0.65f);
    }
}

int func_808000A8_chfactorysmoke(s32 param_0)
{
  s32 local_0;
  local_0 = &D_80800148_chfactorysmoke;
  func_800BBCB8(param_0 + 4, 0, 1.0f, 4, local_0);
}
