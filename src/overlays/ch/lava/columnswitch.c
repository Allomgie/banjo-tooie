#include "ch/lavacolumnswitch.h"

extern int D_80800080_chlavacolumnswitch;

s32 func_80800000_chlavacolumnswitch(void *this, s32 param_1)
{
  if (param_1 == 7)
  {
    _glcutDll_entrypoint_6(0x127, 0x4e);
    return 1 ^ 0;
  }
  return _chswitch_entrypoint_10(this, param_1);
}

void func_8080003C_chlavacolumnswitch(s32 arg0)
{
    _chswitch_entrypoint_7(arg0,FLAG_390_UNK);
    _chswitch_entrypoint_9(arg0);
}

int chlavacolumnswitch_entrypoint_0()
{
  return &D_80800080_chlavacolumnswitch;
}
