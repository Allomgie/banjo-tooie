#include "common.h"

extern void *D_80800140_chlightdemon;
typedef union { s32 local_0; void *local_1; } LightDemonEvent;
extern u8 D_80800194_chlightdemon[];
extern u8 D_80800188_chlightdemon[];
extern void func_800C8D4C(s32, void *);
extern void func_800C8CB8();
extern void func_800C8E84(s32, void *);
extern void *D_8080019C_chlightdemon;

int chlightdemon_entrypoint_0()
{
  return &D_80800140_chlightdemon;
}

void func_8080000C_chlightdemon(u8 *param_0) {
    func_80105834();
    func_800C8CB8((*(s32 *)((s8 *)(param_0) + (0x28))), param_0 + 4, param_0);
}

void func_8080003C_chlightdemon(s32 param_0)
{
    func_80105A9C(param_0, 0x44228000);
}

s32 func_80800060_chlightdemon(Actor *param_0, s32 param_1, LightDemonEvent param_2)
{
    if (param_1 == 0x95) {
        param_0->actorData[4] = func_800C8A98();
        func_800C8D4C(param_0->actorData[4], D_80800194_chlightdemon);
        func_800C8CB8(param_0->actorData[4], param_0->position);
        func_800C8E84(param_0->actorData[4], D_80800188_chlightdemon);
        return 1;
    }
    return 0;
}

int func_808000D8_chlightdemon(s32 param_0)
{
  s32 local_0;
  s32 local_1;
  local_0 = func_800F54E4();
  local_1 = func_800F581C(local_0);
  if ((local_1 << 4) < 0)
  {
    func_800F796C(local_0, 3);
  }
}

int chlightdemon_entrypoint_1()
{
  return &D_8080019C_chlightdemon;
}
