#include "common.h"

extern int D_80800060_chfantasybounce[];
extern int D_808000A8_chfantasybounce[];

s32 func_80800000_chfantasybounce(f32 param_0[4]){
    func_800EFA4C(param_0 + 1, 0xC62C8A36, 0x4604CA00, 0xC6149236);
}

int *chfantasybounce_entrypoint_0()
{
    return &D_80800060_chfantasybounce;
}

int chfantasybounce_entrypoint_1()
{
  return (int)&D_808000A8_chfantasybounce;
}

/* TU-NOTE: the .data of this overlay (formerly asm/data/overlays/ch/fantasy/bounce.data.s) is defined here in C.
 * Its tables hold pointers to functions of this file; IDO's assembler schedules some of these
 * functions differently unless the tables are defined in the same unit. Values are taken from the ROM.
 * extern declarations adjusted to the object (same addresses): D_80800060_chfantasybounce -> int[], D_808000A8_chfantasybounce -> int[] */
extern void func_80102EC0();
extern void func_80101870();
extern void func_80107C2C();
int D_80800060_chfantasybounce[18] = { 0x15804C6, 0x62C0001, 0x0, (u32)func_80102EC0, (u32)func_80102EC0, (u32)func_80101870, 0x0, 0x0, 0x0, 0x1C0C, 0x0, 0x0, 0x0, (u32)func_80800000_chfantasybounce, (u32)func_80107C2C, -0x7FFFD3FE, 0x0, 0x0 };
int D_808000A8_chfantasybounce[18] = { 0x15804C7, 0x62D0001, 0x0, (u32)func_80102EC0, (u32)func_80102EC0, (u32)func_80101870, 0x0, 0x0, 0x0, 0x1C0C, 0x0, 0x0, 0x0, 0x0, (u32)func_80107C2C, -0x7FFFD3FE, 0x0, 0x0 };
