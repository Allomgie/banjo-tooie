#include "common.h"

extern int D_80800210_chdrawbridgeswitches;
extern int D_80800258_chdrawbridgeswitches;
extern int D_808002A0_chdrawbridgeswitches;

s32 func_80800000_chdrawbridgeswitches(Actor *this, Gfx **dl, Mtx **m){
    _chswitch_entrypoint_7(this, dl, m);
    _chswitch_entrypoint_8(this, m);
}

int func_80800030_chdrawbridgeswitches(s32 param_0, s32 param_1, s32 param_2, s32 param_3, s32 param_4)
{
  switch (param_1)
  {
    case 7:
      func_80101180(0x49F, param_3, 0);
      _chswitch_entrypoint_10(param_0, param_1, param_2);
      return;

    case 8:
      func_80101180(0x49F, param_4, 0);
      _chswitch_entrypoint_10(param_0, param_1, param_2);
      return;

    default:
      _chswitch_entrypoint_10(param_0, param_1, param_2);
      return;
  }
}

void func_808000D0_chdrawbridgeswitches(s32 param_0) {
    func_80800000_chdrawbridgeswitches(param_0, 0xA20, 0x200);
}

void func_808000F4_chdrawbridgeswitches(s32 param_0, s32 param_1, s32 param_2) {
    func_80800030_chdrawbridgeswitches(param_0, param_1, param_2, 0x69, 0x68);
}

int chdrawbridgeswitches_entrypoint_0()
{
  return &D_80800210_chdrawbridgeswitches;
}

void func_80800128_chdrawbridgeswitches(s32 param_0)
{
  func_80800000_chdrawbridgeswitches(param_0, 0xA21, 0x400);
}

void func_8080014C_chdrawbridgeswitches(s32 param_0, s32 param_1, s32 param_2) {
    func_80800030_chdrawbridgeswitches(param_0, param_1, param_2, 0x6b, 0x6a);
}

int chdrawbridgeswitches_entrypoint_1()
{
    return (int)&D_80800258_chdrawbridgeswitches;
}

s32 func_80800180_chdrawbridgeswitches(s32 param_0){
    func_80800000_chdrawbridgeswitches(param_0, 0x58E, 1);
    _chswitch_entrypoint_9(param_0);
}

int func_808001B0_chdrawbridgeswitches(s32 param_0, s32 param_1, s32 param_2)
{
  if (param_1 == 7)
  {
    func_80101180(0x395, 7, 0);
  }
  _chswitch_entrypoint_10(param_0, param_1 | param_1, param_2);
}

int chdrawbridgeswitches_entrypoint_2()
{
    return &D_808002A0_chdrawbridgeswitches;
}
