#include "common.h"

extern void *D_80800740_chwaspstatue;
extern void _chdoormake_entrypoint_3(Actor *, f32, f32, f32, s32, s32);
extern void _chdoormake_entrypoint_5(Actor *, f32);
extern void _chdoormake_entrypoint_6(Actor *, f32);
extern void *D_80800788_chwaspstatue;
extern s32 _chwaspstatue_entrypoint_0;
extern f32 func_800F10B4(f32, f32, f32, f32, f32);
void func_80800134_chwaspstatue();

int func_80800000_chwaspstatue(Actor *param_0)
{
  s32 local_0;
  local_0 = func_800DA298(0x35A);
  if (local_0 != 0)
  {
    local_0 = 6;
  }
  else
  {
    local_0 = 1;
  }
  func_80800134_chwaspstatue(param_0, local_0);
}

void func_8080003C_chwaspstatue(u8 *param_0)
{
  u16 new_var2;
  u32 temp_t7;
  temp_t7 = *((u16 *) (param_0 + 0x72));
  new_var2 = temp_t7;
  temp_t7 = (u16) new_var2;
  temp_t7 = temp_t7 >> 0xA;
  switch (temp_t7)
  {
    u8 *new_var;
    case 1:
      ;
      ;
      ;

    case 6:
      break;

    case 2:
      new_var = param_0 + 0x58;
      if ((func_800D91EC(new_var, 0x40000000) != 0) && (func_800DA298(0x6D8) != 0))
    {
      func_80800134_chwaspstatue(param_0, 3);
    }
      func_800D2498(0xFF, (*((s32 *) (param_0 + 0x6C))) & 0x1FF, 0);
      break;

    case 3:
      func_800D2498(0xFF, (*((s32 *) (param_0 + 0x6C))) & 0x1FF, 0);
      break;

    case 4:
      if (func_800D90A4(param_0 + 0x58) != ((long) 0))
    {
      func_80800134_chwaspstatue(param_0, 1);
    }
      break;

    case 5:
      func_80800134_chwaspstatue(param_0, 6);
      break;

  }

  func_8010C93C(param_0, param_0 + 4, 0x3F400000);
}

void func_80800134_chwaspstatue(param_0, param_1) u8 *param_0; s32 param_1; {
    s32 local_0;
    s32 local_1;

    switch (param_1) {
    case 1:
        _subaddieDll_entrypoint_4(param_0, 0);
        break;
    case 2:
        _subaddieDll_entrypoint_4(param_0, 1);
        func_800CE8D8(0, 0x41200000, 0xA);
        func_800CE928(0, &_chwaspstatue_entrypoint_0, (*(s32 *)((s8 *)(param_0) + (0))));
        (*(u16 *)((s8 *)(param_0) + (0x6E))) = (u16) (((*(u16 *)((s8 *)(param_0) + (0x6E))) & 0xFE00) | 0x14);
        (*(f32 *)((s8 *)(param_0) + (0x58))) = 0.0f;
        if (func_800DA298(0x6D8) == 0) {
            local_0 = (*(s32 *)((s8 *)(param_0) + (0)));
            _capod_entrypoint_13(local_0, local_0, 0x15, 0x810);
            _subaddiedialog_entrypoint_11((*(s32 *)((s8 *)(param_0) + (0))), 0x1416, 0xF, param_0 + 4, 0x6D);
        } else {
            func_800CE88C(0, 1);
        }
        break;
    case 3:
        if (func_800DA298(0x6D8) == 0) {
            func_800CE88C(0, 1);
        }
        (*(f32 *)((s8 *)(param_0) + (0x58))) = 2.0f;
        break;
    case 4:
        if (func_800DA298(0x6D9) == 0) {
            func_800DA544(0x6D9);
            _subaddiedialog_entrypoint_11((*(s32 *)((s8 *)(param_0) + (0))), 0x1419, 0xF, param_0 + 4, 0x6D);
            local_1 = (*(s32 *)((s8 *)(param_0) + (0)));
            _capod_entrypoint_13(local_1, local_1, 0x1B, 0x810);
        }
        func_800FC6B0(0x19);
        (*(f32 *)((s8 *)(param_0) + (0x58))) = 2.0f;
        break;
    case 5:
        func_800FC6B0(0x10);
        func_800D2498(0xFF, 0, 0);
        _subaddiedialog_entrypoint_11((*(s32 *)((s8 *)(param_0) + (0))), 0x1418, 0xF, param_0 + 4, 0x6D);
        func_80101180(0x411, 7, 0);
        func_800DA544(0x35A);
        (*(f32 *)((s8 *)(param_0) + (0x58))) = 2.0f;
        func_800CE88C(0, 0);
        break;
    case 6:
        _subaddieDll_entrypoint_4(param_0, 0);
        (*(f32 *)((s8 *)(param_0) + (0x58))) = 2.0f;
        break;
    }
    func_80101FDC(param_0, param_1);
}

int func_80800350_chwaspstatue(Actor *param_0, s32 param_1, s32 param_2)
{
    switch (param_1) {
    case 0x3F:
        if (!func_800DA298(0x6DA)) {
            func_800DA544(0x6DA);
            _subaddiedialog_entrypoint_11(param_0->unk0, 0x1417, 15, param_0->position, 0x6D);
        }
        return 1;
    case 0x40:
        if (param_0->unk70_10 == 1) {
            func_80800134_chwaspstatue(param_0, 2);
            func_800FC660(14);
        } else if (param_0->unk70_10 == 3) {
            param_0->unk6C_0--;
            if (!param_0->unk6C_0) func_80800134_chwaspstatue(param_0, 5);
            func_800FC660(14);
        }
        return 1;
    case 0xB:
        if (param_2 == 21) {
            func_80800134_chwaspstatue(param_0, 3);
            func_800DA544(0x6D8);
        }
        return 3;
    case 0x1F:
        func_801015D0(param_0);
        func_800DF6BC((s32)func_800F10B4(param_0->unk58, 0.0f, 2.0f, 0, 255.0f), 255);
        return 1;
    case 0x30:
        if (((s16 *)&param_2)[0] == 0x1416) {
            if (((s16 *)&param_2)[1]) return 20;
            return 10;
        }
        return 0;
    default: return 0;
    }
}

s32 chwaspstatue_entrypoint_0(s32 param_0, Actor *param_1){
    Actor *local_0 = func_80106790(param_1);
    func_80800134_chwaspstatue(local_0, 4);
}

void *chwaspstatue_entrypoint_1()
{
    return &D_80800740_chwaspstatue;
}

void func_80800544_chwaspstatue(Actor *param_0)
{
    s32 local_0;

    local_0 = func_800F64A4(func_800F54E4(), 0x20) != 0;
    if (local_0) local_0 = func_800DA298(0x35A) != 0;
    func_800DA3B8(0x9FD, local_0);
    _chdoormake_entrypoint_3(param_0, param_0->rotation[1], param_0->rotation[0] + 90.0f, param_0->scale * 346.0f, 0x83, 0x9FD);
    _chdoormake_entrypoint_5(param_0, 2.0f);
    _chdoormake_entrypoint_6(param_0, 0.5f);
    _chdoormake_entrypoint_8(param_0, 5);
    _chdoormake_entrypoint_9(param_0, 0, 0x1D, 0x810);
    _chdoormake_entrypoint_10(param_0, 0, 0x3DF);
}

int chwaspstatue_entrypoint_2()
{
  return &D_80800788_chwaspstatue;
}
