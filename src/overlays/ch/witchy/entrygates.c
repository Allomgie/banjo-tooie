#include "ch/witchyentrygates.h"

extern void func_80103140();
extern s32 _chdoor_entrypoint_1(Actor *, s32, s32);

extern u32 D_808001F0_chwitchyentrygates;

void func_80800000_chwitchyentrygates(Actor* arg0)
{
    f32 var_f0;
    s32 var_a3;
    if (_sujiggy_entrypoint_20(2U) != 0)
    {
        func_800DA544(FLAG_394_PROGRESS_OPENED_WORLD_WW);
    }
    if ((func_800D3E40(0xB) != 0) && (_glcutDll_entrypoint_19(0x7CU) == 0))
    {
        var_a3 = -1;
        func_80101FDC(arg0, 4);
    }
    else
    {
        var_a3 = 0x394;
    }
    if (arg0->unk74_7 == 0x33)
    {
        var_f0 = 75.0f;
    }
    else
    {
        var_f0 = -75.0f;
    }
    _chdoormake_entrypoint_0(arg0, var_f0, 0, var_a3);
    _chdoormake_entrypoint_5(arg0, 0.0f);
}

void func_808000B8_chwitchyentrygates(Actor *param_0)
{
  u16 local_0;
  Actor *local_1 = param_0;

  local_0 = *(u16 *)((u8 *)local_1 + 0x72);
  if (((local_0 & 0xFFFFu) >> 10) == 3) {
    if (!local_1->unk64_20) {
      func_800C3F48(0x66509D6D);
      local_1->unk64_20 = 1;
      *(f32 *)((u8 *)local_1 + 0x34) = 1.5f;
    } else if (func_800D90A4((u8 *)local_1 + 0x34) != 0) {
      func_800C3F48(0x66509CA1);
      *(f32 *)((u8 *)local_1 + 0x34) = 1.0f;
    }
  }
  _chdoor_entrypoint_0(param_0);
}

s32 func_80800168_chwitchyentrygates(Actor *param_0, s32 param_1, s32 param_2)
{
    s32 local_0;

    if (param_1 == 0x95) {
        local_0 = param_0->unk74_7 == 0x33 ? 0x96C : 0x96D;
        func_80103140(param_0, (u16)local_0, *(u16 *)((u8 *)param_0->unk0 + 0x16));
    }
    return _chdoor_entrypoint_1(param_0, param_1, param_2);
}

void* chwitchyentrygates_entrypoint_0(void) {
    return &D_808001F0_chwitchyentrygates;
}
