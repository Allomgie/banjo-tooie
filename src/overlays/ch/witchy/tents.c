#include "common.h"

extern int D_80800050_chwitchytents[];
extern int D_80800098_chwitchytents[];

s32 func_80800000_chwitchytents(s32 param_0){
    if(func_800EA05C() == 0x124){
        func_8010A624(param_0);
    }
}

int chwitchytents_entrypoint_0()
{
  return &D_80800050_chwitchytents;
}

int chwitchytents_entrypoint_1()
{
  return (int)&D_80800098_chwitchytents;
}

/* TU-NOTE: the .data of this overlay (formerly asm/data/overlays/ch/witchy/tents.data.s) is defined here in C.
 * Its tables hold pointers to functions of this file; IDO's assembler schedules some of these
 * functions differently unless the tables are defined in the same unit. Values are taken from the ROM.
 * extern declarations adjusted to the object (same addresses): D_80800050_chwitchytents -> int[], D_80800098_chwitchytents -> int[] */
extern void func_80102EC0();
extern void func_80101870();
extern void func_80107C2C();
int D_80800050_chwitchytents[18] = { 0x15804C4, 0x85D0001, 0x0, (u32)func_80102EC0, (u32)func_80102EC0, (u32)func_80101870, 0x0, 0x0, 0x0, 0x1C0C, 0x0, 0x0, 0x0, (u32)func_80800000_chwitchytents, (u32)func_80107C2C, -0x7FFFD3FE, 0x0, 0x0 };
int D_80800098_chwitchytents[18] = { 0x15804C5, 0x85D0001, 0x0, (u32)func_80102EC0, (u32)func_80102EC0, (u32)func_80101870, 0x0, 0x0, 0x0, 0x1C0C, 0x0, 0x0, 0x0, (u32)func_80800000_chwitchytents, (u32)func_80107C2C, -0x7FFFD3FE, 0x0, 0x0 };
