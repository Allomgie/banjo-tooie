#include "common.h"

extern int D_80800330_chcheatopage;
extern f32 func_800D8FF8(void);
typedef union { s32 local_0; void *local_1; } CheatoEvent;
extern u8 D_80800378_chcheatopage[];
void func_80800194_chcheatopage();
s32 func_808002F0_chcheatopage();

int chcheatopage_entrypoint_0()
{
    return (int)&D_80800330_chcheatopage;
}

void func_8080000C_chcheatopage(Actor *param_0)
{
    func_80103110(param_0, 0);
    func_8010A5B0(param_0, !func_800DA298(0x666));
    if (param_0->unk64_20) {
        func_800FC660(0x77);
        param_0->unk64_20 = 0;
    }
}

void func_80800070_chcheatopage(Actor *param_0)
{
    switch (param_0->unk70_10) {
    case 1:
        param_0->rotation[1] += 186.0f * func_800D8FF8();
        func_80103110(param_0, 0);
        break;
    case 2:
        if (func_800D9078(&param_0->unk58)) {
            func_800F82D4(func_800F54E4(), 0);
            func_800FFAB0(param_0);
            _glcutDll_entrypoint_6(0xAD, 1);
        }
        break;
    }
}

s32 func_80800124_chcheatopage(Actor *param_0, s32 param_1, CheatoEvent param_2)
{
    switch (param_1) {
    case 0x3E:
        func_80800194_chcheatopage(param_0, param_2.local_0);
        return 1;
    case 0x13:
        *(s32 *)&param_0->unk50 = param_2.local_0;
        break;
    case 0x14:
        param_0->unk64_20 = 1;
        break;
    default:
        return 0;
    }
    return 1;
}

void func_80800194_chcheatopage(param_0, param_1) Actor *param_0; s32 param_1;
{
    if (func_8010A6B0(param_0, (u32)*(u16 *)(param_1 + 0x1A) >> 5)) {
        _fxsparkle_entrypoint_1(param_0->position, 0x14);
        func_800D1844(0x4A);
        func_800D0BD4(*(s32 *)&param_0->unk50, 4);
        func_800FC660(0x72);
        if (func_800D035C(4) == 5) {
            _subaddiedialog_entrypoint_11(param_0->unk0, 0x114A, 4, 0, 0);
        }
        if (!func_808002F0_chcheatopage(param_0) && !func_800DA9E4(0x67, 1)) {
            func_800F82D4(func_800F54E4(), 2);
            func_8010A570(param_0);
            func_80101FDC(param_0, 2);
            param_0->unk58 = 0.75f;
            func_80103110(param_0, 1);
            param_0->unk64_16 = 0;
            *((u8 *)param_0 + 0x75) &= ~0x10;
        } else {
            func_800FFAB0(param_0);
        }
    }
}

int func_808002A0_chcheatopage(Actor *param_0)
{
  func_80101870();
  if (param_0->unk7C_12 && (((u32)(*(u16 *)((u8 *)param_0 + 0x72)) >> 10) == 1)) {
    func_80103110(param_0, 1);
  }
}

s32 func_808002F0_chcheatopage(param_0) u8 *param_0; {
    s32 local_0;

    for (local_0 = 0; local_0 < 1; local_0++) {
        if (D_80800378_chcheatopage[local_0] == *(s32 *)(param_0 + 0x50)) {
            return 1;
        }
    }
    return 0;
}
