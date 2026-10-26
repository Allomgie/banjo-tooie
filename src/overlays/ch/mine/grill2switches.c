#include "common.h"

extern int D_80800150_chminegrill2switches;
extern void *D_80800198_chminegrill2switches;

s32 func_80800000_chminegrill2switches(Actor *this, s32 param_1, s32 param_2){
    _chswitch_entrypoint_7(this, param_1);
    _chswitch_entrypoint_8(this, param_2);
}

s32 func_80800030_chminegrill2switches(param_0, param_1, param_2, param_3) s32 param_0; s32 param_1; s32 param_2; s32 param_3; {
    if (param_1 == 7) {
        func_80101180(0x4C2, param_3, 0);
        _chswitch_entrypoint_10(param_0, param_1, param_2);
    } else {
        _chswitch_entrypoint_10(param_0, param_1, param_2);
    }
}

void func_80800094_chminegrill2switches(s32 param_0) {
    func_80800000_chminegrill2switches(param_0, 0xA26, 0x200);
}

void func_808000B8_chminegrill2switches(s32 param_0, s32 param_1, s32 param_2) {
    func_80800030_chminegrill2switches(param_0, param_1, param_2, 0x7A, 0x79);
}

int *chminegrill2switches_entrypoint_0()
{
    return &D_80800150_chminegrill2switches;
}

int func_808000EC_chminegrill2switches(int param_0)
{
  int new_var2;
  int new_var;
  new_var = 0;
  new_var2 = (new_var = 0xA28);
  func_80800000_chminegrill2switches(param_0, new_var2, 0x400);
}

void func_80800110_chminegrill2switches(s32 param_0, s32 param_1, s32 param_2) {
    func_80800030_chminegrill2switches(param_0, param_1, param_2, 0x7c, 0x7b);
}

int chminegrill2switches_entrypoint_1()
{
  return &D_80800198_chminegrill2switches;
}
