#include "common.h"

extern void *D_808000D0_chperspexboxswitch;

int func_80800000_chperspexboxswitch(s32 param_0[3], s32 param_1, s32 param_2)
{
  if (param_1 == 7)
  {
    func_80101180(0x4C0, 7, 0);
    _capod_entrypoint_13(param_0[0], 0, 0xE, 0x10);
    _chswitch_entrypoint_10(param_0, param_1, param_2);
  }
  else
  {
    _chswitch_entrypoint_10(param_0, param_1 | 0, param_2);
  }
}

s32 func_80800080_chperspexboxswitch(s32 param_0){
    _chswitch_entrypoint_7(param_0, 0x43A);
    _chswitch_entrypoint_8(param_0, 0x201);
    _chswitch_entrypoint_9(param_0);
    func_80104E78(param_0);
}

int chperspexboxswitch_entrypoint_0()
{
  return &D_808000D0_chperspexboxswitch;
}

/* TU-NOTE: the .data of this overlay (formerly asm/data/overlays/ch/perspexboxswit.data.s) is defined here in C.
 * Its tables hold pointers to functions of this file; IDO's assembler schedules some of these
 * functions differently unless the tables are defined in the same unit. Values are taken from the ROM. */
extern void _chswitch_entrypoint_6();
extern void func_80105834();
extern void func_80101870();
extern void _chswitch_entrypoint_2();
extern void func_80107C2C();
void *D_808000D0_chperspexboxswitch = (void *)0x034304C1;
static u32 D_808000D0_chperspexboxswitch_rest[19] = { 0x7B80001, 0x8011A220, (u32)_chswitch_entrypoint_6, (u32)func_80105834, (u32)func_80101870, 0x0, 0x0, 0x0, 0x40000808, 0x0, (u32)_chswitch_entrypoint_2, 0x0, (u32)func_80800080_chperspexboxswitch, (u32)func_80107C2C, 0x80082C12, (u32)func_80800000_chperspexboxswitch, 0x0, 0x0, 0x0 };
