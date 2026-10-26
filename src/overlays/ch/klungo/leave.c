#include "common.h"

extern int D_80800130_chklungoleave;
extern s32 D_80800178_chklungoleave;

int chklungoleave_entrypoint_0()
{
    return (int)&D_80800130_chklungoleave;
}

int func_8080000C_chklungoleave(s32 param_0)
{
  func_80105A9C(param_0, 0x43960000);
  func_80105BAC(param_0);
}

void func_808000F0_chklungoleave();

void func_80800038_chklungoleave(s32 arg0)
{
    func_80105834();
    func_808000F0_chklungoleave(arg0);
}
s32 func_80800060_chklungoleave(Actor *param_0, s32 param_1, s32 param_2)
{
    switch (param_1) {
    case 0x95:
        if (_glcutDll_entrypoint_19(0x5B)) {
            _subaddiedialog_entrypoint_11(param_0->unk0, 0x162E, 0x44, param_0->position, 0xAB);
            _capod_entrypoint_13(param_0->unk0, 0, 6, 0x2911);
            break;
        }
        func_800FFAB0(param_0);
        break;
    default:
        return 0;
    }
    return 1;
}

void func_808000F0_chklungoleave(s32 param_0) {
    func_80105230(param_0, &D_80800178_chklungoleave);
}
