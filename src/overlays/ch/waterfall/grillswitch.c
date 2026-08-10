#include "common.h"

extern u8 D_80800090_chwaterfallgrillswitch;

int func_80800000_chwaterfallgrillswitch(s32 param_0, s32 param_1, s32 param_2)
{
  if (param_1 == 7)
  {
    func_80101180(0x11B, 7, 0);
  }
  _chswitch_entrypoint_10(param_0, param_1 | param_1, param_2);
}

s32 func_80800054_chwaterfallgrillswitch(Actor *this){
    _chswitch_entrypoint_7(this, 0);
    _chswitch_entrypoint_8(this, 0x201);
}

int chwaterfallgrillswitch_entrypoint_0()
{
    return (int)&D_80800090_chwaterfallgrillswitch;
}
