#include "ch/minelightswitch.h"

extern s32 _chswitch_entrypoint_10(Actor *, s32, s32);
extern void *D_808000C0_chminelightswitch;

s32 func_80800000_chminelightswitch(Actor *param_0, s32 param_1, s32 param_2)
{
    switch (param_1) {
    case 7:
        if (!func_800DA298(0x673)) _glcutDll_entrypoint_6(0xCF, 0x15);
        break;
    case 8:
        if (!func_800DA298(0x673)) {
            func_800DA544(0x673);
            _glcutDll_entrypoint_6(0xCF, 0x15);
        }
        break;
    default:
        return _chswitch_entrypoint_10(param_0, param_1, param_2);
    }
    return 1;
}

void func_80800094_chminelightswitch(s32 arg0)
{
    _chswitch_entrypoint_7(arg0,FLAG3_9E0_UNK);
}

int chminelightswitch_entrypoint_0()
{
  return &D_808000C0_chminelightswitch;
}
