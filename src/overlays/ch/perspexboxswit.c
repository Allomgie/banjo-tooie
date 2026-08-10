#include "common.h"

extern void *D_808000D0_chperspexboxswitch;

int func_80800000_chperspexboxswitch(s32 param_0[3], s32 param_1, s32 param_2)
{
  if (param_1 == 7)
  {
    func_80101180(0x4C0, 7, 0);
    _capod_entrypoint_13(param_0[0], 0, 0xE, 0x10);
    _chswitch_entrypoint_10(param_0, param_1, param_2);
  }
  else
  {
    _chswitch_entrypoint_10(param_0, param_1 | 0, param_2);
  }
}

s32 func_80800080_chperspexboxswitch(s32 param_0){
    _chswitch_entrypoint_7(param_0, 0x43A);
    _chswitch_entrypoint_8(param_0, 0x201);
    _chswitch_entrypoint_9(param_0);
    func_80104E78(param_0);
}

int chperspexboxswitch_entrypoint_0()
{
  return &D_808000D0_chperspexboxswitch;
}
