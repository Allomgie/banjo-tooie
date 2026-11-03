#include "common.h"

extern void *D_80800080_chdinotraindoorswitch;

s32 func_80800000_chdinotraindoorswitch(void *this, s32 param_1)
{
  if (param_1 == 7)
  {
    _glcutDll_entrypoint_6(0x114, 0x3c);
    return 1;
  }
  return _chswitch_entrypoint_10(this, param_1);
}

s32 func_8080003C_chdinotraindoorswitch(Actor *this){
    _chswitch_entrypoint_7(this, 0x164);
    _chswitch_entrypoint_9(this);
    func_80104E78(this);
}

int chdinotraindoorswitch_entrypoint_0()
{
  return &D_80800080_chdinotraindoorswitch;
}

/* TU-NOTE: the .data of this overlay (formerly asm/data/overlays/ch/dino/traindoorswitch.data.s) is defined here in C.
 * Its tables hold pointers to functions of this file; IDO's assembler schedules some of these
 * functions differently unless the tables are defined in the same unit. Values are taken from the ROM. */
extern u8 D_8011A248[];
extern void _chswitch_entrypoint_6();
extern void func_80105834();
extern void func_80101870();
extern void func_80107C2C();
void *D_80800080_chdinotraindoorswitch = (void *)0x0343049C;
static u32 D_80800080_chdinotraindoorswitch_rest[19] = { 0x86D0001, (u32)&D_8011A248, (u32)_chswitch_entrypoint_6, (u32)func_80105834, (u32)func_80101870, 0x0, 0x0, 0x0, 0x40000808, 0x0, 0x0, 0x0, (u32)func_8080003C_chdinotraindoorswitch, (u32)func_80107C2C, 0x80082C12, (u32)func_80800000_chdinotraindoorswitch, 0x0, 0x0, 0x0 };
