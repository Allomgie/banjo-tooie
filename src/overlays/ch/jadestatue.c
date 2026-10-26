#include "common.h"

extern void *D_80800310_chjadestatue;
extern void func_80102FDC(Actor *, f32);
extern f32 func_800D8FF8(void);
typedef union { s32 local_0; void *local_1; } JadeStatueEvent;
extern void *D_80800358_chjadestatue;
void func_808001C0_chjadestatue();

int chjadestatue_entrypoint_0()
{
  return &D_80800310_chjadestatue;
}

void func_8080000C_chjadestatue(Actor *param_0)
{
    s32 local_0;
    s32 local_1;
    func_80102FDC(param_0, 0.75f);
    local_0 = func_800D0B68(param_0->unk74_7 - 0x32, 5);
    local_1 = func_800D035C(5);
    if (local_0 || local_1 >= 20) func_800FFA88(param_0->unk0);
    param_0->unk64_20 = 0;
    func_8010A5B0(param_0, !func_800DA298(0x680));
}

void func_80800098_chjadestatue(Actor *param_0)
{
    param_0->rotation[1] -= func_800D8FF8() * 120.0f;
    func_80103110(param_0, 0);
    if (param_0->unk64_20) {
        func_808001C0_chjadestatue(param_0);
        func_800FFA88(param_0->unk0);
    }
}

void func_80800104_chjadestatue(Actor *param_0)
{
  func_80101870();
  if (param_0->unk7C_12) {
    func_80103110(param_0, 1);
  }
}

s32 func_80800140_chjadestatue(Actor *param_0, s32 param_1, JadeStatueEvent param_2)
{
    switch (param_1) {
    case 0x95:
        func_80109EEC(param_0, 0x44);
        break;
    case 0x3E:
        param_0->unk64_20 = 1;
        _subaddieDll_entrypoint_4(param_0, 1);
        break;
    case 0x2C:
        func_800FFAB0(param_0);
        break;
    default:
        return 0;
    }
    return 1;
}

void func_808001C0_chjadestatue(param_0) u8 *param_0;
{
  s32 local_1;
  _fxsparkle_entrypoint_1(param_0 + 4, 0xC);
 do { func_800D0BD4((((u32) ((u16) (*((u16 *) (((s8 *) param_0) + 0x76))))) >> 7) - 0x32, 5); local_1 = func_800D035C(5); func_800D24E8(0xEE, local_1, 0); func_800FC63C(0xE, 0x3E80); } while (0);
  switch (local_1)
  {
    case 10:
      func_80101180(0x2B4, 7, 0);
      return;

    case 20:
      func_80101180(0x2B4, 7, 1);
      return;

  }

}

int func_8080026C_chjadestatue(s32 param_0)
{
  if (func_800D035C(5) >= 0x14)
  {
    func_800FFAB0(param_0);
  }
}

s32 func_808002A4_chjadestatue(Actor *this)
{
  s32 local_0 = func_800D035C(5);
  func_800D24E8(0xEE, local_0, 0);
  if (local_0 >= 0x14)
  {
    func_80101180(0x2B3, 0x2C, 0);
    func_800FFAB0(this);
  }
}

int chjadestatue_entrypoint_1()
{
  return &D_80800358_chjadestatue;
}
