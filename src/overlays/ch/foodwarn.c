#include "common.h"

extern f32 func_800EFC7C();
extern u8 D_80800270_chfoodwarn[];
extern u8 D_8080028C_chfoodwarn[];
extern int D_808002A8_chfoodwarn;

int func_80800000_chfoodwarn(s32 param_0, s32 param_1, s32 param_2)
{
  _gspropctrl_entrypoint_11(_gccubesearch_entrypoint_1(param_1 + 0x521, param_0 + 4) | 0, param_2);
}

int func_8080003C_chfoodwarn(s32 param_0)
{
  func_80800000_chfoodwarn(param_0, 0, param_0 + 0x28);
  func_80800000_chfoodwarn(param_0, 1, param_0 + 0x18);
}

s32 func_80800074_chfoodwarn(u8 *param_0, f32 *param_1) {
    f32 local_0 = func_800EFC7C(param_1, param_0 + 0x28);
    if (local_0 < func_800EFC7C(param_1, param_0 + 0x18)) {
        return 1;
    }
    return 0;
}

void func_808000D4_chfoodwarn(Actor *param_0)
{
    f32 local_0[3];
    s32 local_1;
    s32 local_2;
    local_2 = func_800D1A04(0x4B) != 0 || func_800D1A04(0x4C) != 0;
    func_8010D254(local_0);
    local_1 = func_8010C500(param_0);
    if (local_1 && !param_0->unk6C_0) param_0->unk64_20 = func_80800074_chfoodwarn(param_0, local_0);
    if (local_1) {
        if (param_0->unk64_20 && !param_0->unk6C_0 && local_2) {
            *(u16 *)D_80800270_chfoodwarn = param_0->unk74_7 + 0x541;
            _subaddiedialog_entrypoint_7(param_0, param_0->position, D_80800270_chfoodwarn);
        } else _subaddiedialog_entrypoint_7(param_0, param_0->position, D_8080028C_chfoodwarn);
    }
    param_0->unk6C_0 = (u16)local_1;
}

int func_808001F4_chfoodwarn(Actor *param_0, s32 param_1, s32 param_2)
{
  if (param_1 != 0x2E)
  {
    if (param_1 == 0x95)
    {
      if (((!(param_1 & 0xFF)) && (!param_1)) && (!param_1))
      {
      }
      func_80105010();
      *((u16 *) (((char *) param_0) + 0x6E)) = (u16) (((*((u16 *) (((char *) param_0) + 0x6E))) & 0xFE00) | (func_8010C500(param_0) & 0x1FF));
      goto block_4;
    }
    return 0;
  }
  block_4:
  return 1;

}

int *chfoodwarn_entrypoint_0()
{
    return &D_808002A8_chfoodwarn;
}
