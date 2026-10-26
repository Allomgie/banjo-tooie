#include "common.h"

extern int D_808001F0_chlavaarchgrill3switches;
extern int D_80800238_chlavaarchgrill3switches;
extern int D_80800280_chlavaarchgrill3switches;

void func_80800000_chlavaarchgrill3switches()
{
    _chswitch_entrypoint_7();
}

void func_80800020_chlavaarchgrill3switches(s32 param_0, s32 param_1, s32 param_2, s32 param_3, s32 param_4) {
    switch (param_1) {                                 
    case 7:
        func_80101180(0x288, param_3, 0);
        _chswitch_entrypoint_10(param_0, param_1, param_2);
        return;
    case 8:
        func_80101180(0x288, param_4, 0);
        _chswitch_entrypoint_10(param_0, param_1, param_2);
        return;
    default:
        _chswitch_entrypoint_10(param_0, param_1, param_2);
        return;
    }
}

s32 func_808000C0_chlavaarchgrill3switches(s32 param_0){
    func_80800000_chlavaarchgrill3switches(param_0, 0xA1D);
    _chswitch_entrypoint_8(param_0, 0x200);
}

void func_808000F0_chlavaarchgrill3switches(s32 param_0, s32 param_1, s32 param_2) {
    func_80800020_chlavaarchgrill3switches(param_0, param_1, param_2, 0x63, 0x64);
}

int *chlavaarchgrill3switches_entrypoint_0()
{
    return &D_808001F0_chlavaarchgrill3switches;
}

int func_80800124_chlavaarchgrill3switches(Actor *param_0)
{
  func_80800000_chlavaarchgrill3switches(param_0, 0xA1E);
  _chswitch_entrypoint_8(param_0, 0x400);
}

void func_80800154_chlavaarchgrill3switches(s32 param_0, s32 param_1, s32 param_2) {
    func_80800020_chlavaarchgrill3switches(param_0, param_1, param_2, 0x61, 0x62);
}

int chlavaarchgrill3switches_entrypoint_1()
{
  return &D_80800238_chlavaarchgrill3switches;
}

int func_80800188_chlavaarchgrill3switches(Actor *param_0)
{
  func_80800000_chlavaarchgrill3switches(param_0, 0xA1F);
  _chswitch_entrypoint_8(param_0, 0x200);
}

void func_808001B8_chlavaarchgrill3switches(s32 param_0, s32 param_1, s32 param_2) {
    func_80800020_chlavaarchgrill3switches(param_0, param_1, param_2, 0x5d, 0x5e);
}

int chlavaarchgrill3switches_entrypoint_2(void)
{
    return (int)&D_80800280_chlavaarchgrill3switches;
}
