#include "common.h"

extern s32 D_80800090_chperspexbox;
extern s32 D_80800124_chperspexbox;
extern void *D_80800138_chperspexbox;

int func_80800000_chperspexbox(s32 *param_0, s32 param_1, s32 param_2)
{
    if (param_1 == 7)
    {
        func_800BABB8(0, param_0 + 1, param_0 + 1, param_0[0x0E],
                      &D_80800090_chperspexbox);
        _subaddieaudioquick_entrypoint_2(param_0, param_0 + 1,
                                         &D_80800124_chperspexbox);
        func_800FC6B0(0x18);
        func_800FFAB0(param_0);
        return 1;
    }
    return 0;
}

int chperspexbox_entrypoint_0()
{
  return &D_80800138_chperspexbox;
}
