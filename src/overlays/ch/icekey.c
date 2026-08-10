#include "common.h"

extern int D_808000A0_chicekey;
extern int D_808000EC_chicekey;

int func_80800000_chicekey(s32 param_0[4], s32 param_1, s32 param_2)
{
  if (param_1 == 0x3E)
  {
    func_800BBCB8(param_0 + 1, param_0 + 1, 0x3F800000, 0x14, &D_808000A0_chicekey);
    func_800D1844(0x53);
    _subaddiedialog_entrypoint_11(param_0[0], 0x1550, 4, param_0 + 1, 0x6F);
    func_800FC660(0xE);
    func_800FFA88(param_0[0]);
    return 1;
  }
  return 0;
}

int chicekey_entrypoint_0()
{
  return (int)&D_808000EC_chicekey;
}
