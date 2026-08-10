#include "common.h"

extern void *D_80800080_chdinotraindoorswitch;

s32 func_80800000_chdinotraindoorswitch(void *this, s32 param_1)
{
  if (param_1 == 7)
  {
    _glcutDll_entrypoint_6(0x114, 0x3c);
    return 1;
  }
  return _chswitch_entrypoint_10(this, param_1);
}

s32 func_8080003C_chdinotraindoorswitch(Actor *this){
    _chswitch_entrypoint_7(this, 0x164);
    _chswitch_entrypoint_9(this);
    func_80104E78(this);
}

int chdinotraindoorswitch_entrypoint_0()
{
  return &D_80800080_chdinotraindoorswitch;
}
