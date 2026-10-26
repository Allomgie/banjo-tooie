#include "common.h"

extern int D_808002B0_chshockjump;
extern int D_808002F8_chshockjump;
extern void func_800F7B9C();
extern void _chexploder_entrypoint_5(void *param_0, int param_1, void *param_2, int param_3, float param_4, int param_5);
extern void _subaddieaudioquick_entrypoint_2(void *param_0, void *param_1, void *param_2);
extern u8 *func_80106790();
extern int D_80800340_chshockjump;
extern f32 func_800F15F8(f32, f32, f32);

int chshockjump_entrypoint_0()
{
  return (int)&D_808002B0_chshockjump;
}

int chshockjump_entrypoint_1()
{
  return (int)&D_808002F8_chshockjump;
}

int func_80800018_chshockjump(char param_0, s32 param_1, s32 param_2)
{
  s32 local_0;
  switch (param_1)
  {
    case 0x90:
      local_0 = func_80106790(func_80101080(param_2));
      _chexploder_entrypoint_6(local_0, 0x43C80000, 0x44160000);
      _chexploder_entrypoint_7(local_0, 0xC4160000, 0xC3C80000);
      goto block_6;

    case 0x91:
      func_800F7B9C(param_2, 0x49);
      goto block_6;

    default:
      return 0;
  }
block_6:
  return 1;
}

s32 func_808000AC_chshockjump(s32 param_0, s32 param_1, s32 param_2) {
    if (param_1 == 0x91) {
        func_800F7B9C(param_2, 0x4A);
    } else {
        return 0;
    }
    return 1;
}

void chshockjump_entrypoint_2(void)
{
    u8 *sp24;
    u8 *temp_v0;

    temp_v0 = func_80106790();
    sp24 = temp_v0;
    _chexploder_entrypoint_5(temp_v0, 0x756, temp_v0 + 4, (*(int *)(temp_v0 + 0x48)), (*(float *)(temp_v0 + 0x38)), 0xC);
    _subaddieaudioquick_entrypoint_2(sp24, sp24 + 4, &D_80800340_chshockjump);
}

void func_80800148_chshockjump(Actor *param_0, s32 param_1)
{
    s32 local_1;
    s32 local_0;
    s32 local_2;

    local_0 = _subaddiefade_entrypoint_0(param_0);
    if (param_0->unk6C_9 == 0x210) local_1 = 13;
    else local_1 = 9;
    if (func_800C6E38(local_1) && func_800F64A4(func_800F54E4(), 0x401)) {
        local_2 = (s32)func_800F15F8((f32)local_0, 255.0f, 5.0f);
    } else {
        local_2 = (s32)func_800F15F8((f32)local_0, 90.0f, 5.0f);
    }
    _subaddiefade_entrypoint_8(param_0, local_2);
    func_80101870(param_0, param_1);
}

void func_80800228_chshockjump(void *param_0)
{
  s32 temp_v0;
  temp_v0 = _subaddiesect_entrypoint_1(param_0);
  *((s32 *) (((char *) param_0) + 0x28)) = temp_v0;
  if (temp_v0 == (-1))
  {
    if ((((u32) (*((u16 *) (((char *) param_0) + 0x76)))) >> 7) != 0x33)
    {
      func_80102E08(param_0);
    }
  }
  else
  {
    temp_v0 = *((u16 *) (((char *) param_0) + 0x76));
    _subaddiesect_entrypoint_2(param_0, *((s32 *) (((char *) param_0) + 0x28)), ((((u32) temp_v0) & 0xFFFFu) >> 7) != 0x33);
  }
  func_8010A654(param_0, func_800DA298(0x661));
}
