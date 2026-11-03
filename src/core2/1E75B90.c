#include "common.h"

extern s16 D_80117F02[][2];

int func_8009C2A0(s32 param_0, int param_1)
{
  s16 *new_var;
  short new_var2;
  new_var = D_80117F02[param_1];
  new_var2 = *new_var;
  func_800DBEFC(param_0, new_var2);
}

/* TU-NOTE: the .data of this file (formerly asm/data/core2/1E75B90.data.s) is defined here in C.
 * Values are taken from the ROM.
 * Labels inside an object are linker symbols in undefined_syms.us.txt: D_80117F02 = D_80117F00 + 0x2 */
u32 D_80117F00[12] = { 0xFFFF, 0x10007, 0x20006, 0x30005, 0x40004, 0x50008, 0x6000D, 0x7000A, 0x80009, 0x9000B, 0xA000A, 0x0 };
