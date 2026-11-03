#include "common.h"

extern int D_80800180_chspiralgrill[];
extern u8 D_808001C8_chspiralgrill[];

int *chspiralgrill_entrypoint_0()
{
    return &D_80800180_chspiralgrill;
}

s32 func_8080000C_chspiralgrill(s32 param_0){
    func_8010A800(param_0, 0);
    func_80109EEC(param_0, 0x40);
}

int func_8080003C_chspiralgrill(s32 param_0, s32 param_1, s32 param_2)
{
  f32 local_0[3];
  s32 local_1;
  s32 *local_2;
  s32 local_4;
  switch (param_1)
  {
    case 0x40 :
      local_1 = 0x10;
      func_800EE7F8(local_0, (f32 *)((char *)param_0 + 0x4));
      func_800EF1B8(local_0, (*(s32 *)((char *)(param_0) + 0x48)), 0x43960000);
      local_0[1] += 120.0f;
      _chexploder_entrypoint_3(param_0, local_0, 0xC);
      local_2 = _subaddiefind_entrypoint_2(0x51A, 0);
      if (local_2 != 0)
    {
      local_1 = 0x11;
    }
      _capod_entrypoint_13(local_2 != 0 ? *local_2 : *(s32 *)((char *)param_0 + 0x0),
                           *(s32 *)((char *)param_0 + 0x0), 0x1A, local_1);
      func_800DA544(0x33);
      goto block_11;
    case 0x90 :
      local_4 = func_80106790(func_80101080());
      _subaddieaudioquick_entrypoint_2(param_0, (f32 *)((char *)param_0 + 0x4), &D_808001C8_chspiralgrill);
      _chexploder_entrypoint_6(local_4, 0x44160000, 0x44480000);
      _chexploder_entrypoint_14(local_4, 3);
      goto block_11;
    default :
      return 0;
  }
block_11:
  return 1;
}

/* TU-NOTE: the .data of this overlay (formerly asm/data/overlays/ch/spiralgrill.data.s) is defined here in C.
 * Its tables hold pointers to functions of this file; IDO's assembler schedules some of these
 * functions differently unless the tables are defined in the same unit. Values are taken from the ROM.
 * extern declarations adjusted to the object (same addresses): D_80800180_chspiralgrill -> int[] */
extern void func_80102EC0();
extern void func_80101870();
extern void func_80108ED0();
extern void func_80107C2C();
int D_80800180_chspiralgrill[18] = { 0xB04FA, 0x9520001, 0x0, (u32)func_80102EC0, (u32)func_80102EC0, (u32)func_80101870, 0x0, 0x0, 0x330000, 0xC00, 0x0, (u32)func_80108ED0, 0x0, (u32)func_8080000C_chspiralgrill, (u32)func_80107C2C, -0x7FFFF400, (u32)func_8080003C_chspiralgrill, 0x0 };
u8 D_808001C8_chspiralgrill[24] = { 0x0, 0x13, 0x4, 0xC8, 0x0, 0x16, 0x5D, 0xC0, 0x0, 0x1, 0x0, 0xC8, 0x17, 0x70, 0x0, 0xA, 0x1, 0x4C, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0 };
