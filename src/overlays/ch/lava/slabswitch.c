#include "ch/lavaslabswitch.h"

extern int D_808000A0_chlavaslabswitch;

int func_80800000_chlavaslabswitch(s32 param_0[2], s32 param_1)
{
  if (param_1 == 7)
  {
    func_80101180(0x250, 7, 0);
    _capod_entrypoint_13(param_0[0], 0, 0x16, 0x10);
    return 1;
  }
  return _chswitch_entrypoint_10(param_0);
}

void func_8080005C_chlavaslabswitch(s32 arg0)
{
    _chswitch_entrypoint_7(arg0,FLAG_38F_UNK);
    _chswitch_entrypoint_9(arg0);
}

int chlavaslabswitch_entrypoint_0()
{
  return &D_808000A0_chlavaslabswitch;
}
