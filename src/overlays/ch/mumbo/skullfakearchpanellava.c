#include "common.h"

extern s32 D_80800160_chmumboskullfakearchpanellava[];
extern u8 D_808001CC_chmumboskullfakearchpanellava[];
extern s32 func_800BABB8(s32, f32 *, f32 *, f32, s32 *);
extern void *D_808001E0_chmumboskullfakearchpanellava;
extern int D_80800228_chmumboskullfakearchpanellava;

int func_80800000_chmumboskullfakearchpanellava()
{
  if (func_800EA05C() == 0x134)
  {
    return 0x39C;
  }
  if (func_800EA05C() == 0xEF)
  {
    return 0x39D;
  }
  return 0;
}

int func_80800054_chmumboskullfakearchpanellava(s32 param_0)
{
  if (func_800DA298(func_80800000_chmumboskullfakearchpanellava(param_0)))
  {
    func_800FFAB0(param_0);
  }
}

s32 func_8080008C_chmumboskullfakearchpanellava(Actor *param_0, s32 param_1, s32 param_2)
{
    f32 *local_0;

    switch (param_1) {
    case 0x40:
        local_0 = param_0->position;
        _chexploder_entrypoint_3(param_0, local_0, 0xC);
        func_800BABB8(0, local_0, local_0, param_0->scale, D_80800160_chmumboskullfakearchpanellava);
        func_800C4AF0(local_0, D_808001CC_chmumboskullfakearchpanellava);
        func_800DA544(func_80800000_chmumboskullfakearchpanellava());
        break;
    default:
        return 0;
    }
    return 1;
}

void *chmumboskullfakearchpanellava_entrypoint_0(void)
{
    return &D_808001E0_chmumboskullfakearchpanellava;
}

s32 func_8080012C_chmumboskullfakearchpanellava(s32 param_0){
    func_800EFD24(param_0 + 4);
}

int chmumboskullfakearchpanellava_entrypoint_1()
{
  return (int)&D_80800228_chmumboskullfakearchpanellava;
}
