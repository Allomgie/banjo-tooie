#include "common.h"

extern f32 func_800DF8C4(s32);
extern u8 *func_8010E810(void);
extern u8 *func_8010E924(s32, f32 *, f32, f32);

void func_80800000_trangler(s32 param_0, s32 param_1, s32 param_2, s32 param_3)
{
    s32 local_5;
    f32 local_0[3];
    f32 local_1;
    f32 local_2;
    s32 local_3;
    u8 *local_4;
    local_4 = func_8010E810();
    local_5 = param_1 < 0 ? -param_1 : param_1;
    *(u8 **)(local_4 + 0x18) = *(u8 **)(local_4 + 0x14) + local_5 * 40;
    func_800B237C(func_800DF8B4(param_0), local_0, &local_1);
    local_2 = func_800DF8C4(param_0);
    func_80019224(local_0, local_0);
    local_1 *= local_2;
    func_800DF900(param_0);
    if (param_2) *(f32 *)(func_8010E924(param_2, local_0, local_1, local_2) + 0x24) = -1.0f;
    local_3 = func_800C8760(0, 1);
    while (local_3) {
        func_8010E924(local_3, local_0, local_1, local_2);
        local_3 = func_800C878C(local_3, 0, 1);
    }
    local_4[0x11] = (*(u8 **)(local_4 + 0x14) - local_4 - 28) / 40;
    mlMtxPop();
}

void trangler_entrypoint_0(s32 param_0, u32 param_1, s32 param_2, s32 param_3)
{
  s32 *local_0;
  s32 local_4;
  s32 local_C;
  s32 local_8;
  local_0 = (s32 *) func_8010E810();
  local_0[0] = param_0;
  local_4 = func_800DF8D4(param_0);
  *(s8 *)(local_0 + 0x4) = local_4;
  local_0[5] = local_0 + 0x7;
  func_80800000_trangler(param_0, ((s32)(param_1) >> 0x10) & 0xFFFF, param_1 & 0xFFFF, param_3);
  func_800C87B8(local_0 + 1);
  local_8 = func_800DF8B4(param_0);
  local_C = func_800DF8CC(param_0);
  func_8010EBE4(local_8, local_C, func_800DF8BC(param_0));
}
