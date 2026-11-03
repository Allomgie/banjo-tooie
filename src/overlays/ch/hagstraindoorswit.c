#include "ch/hagstraindoorswit.h"

extern int D_80800080_chhagstraindoorswitch[];

s32 func_80800000_chhagstraindoorswitch(void *this, s32 next_state)
{
  if (next_state == 7)
  {
    func_80101180(0x38C, 7, 0);
    return 1;
  }
  _chswitch_entrypoint_10(this, next_state);
}

void func_80800040_chhagstraindoorswitch(s32 arg0)
{
    _chswitch_entrypoint_7(arg0,FLAG_403_STATION_UNLOCKED_IoH);
    _chswitch_entrypoint_9(arg0);
}

int chhagstraindoorswitch_entrypoint_0()
{
    return (int)&D_80800080_chhagstraindoorswitch;
}

/* TU-NOTE: the .data of this overlay (formerly asm/data/overlays/ch/hagstraindoorswit.data.s) is defined here in C.
 * Its tables hold pointers to functions of this file; IDO's assembler schedules some of these
 * functions differently unless the tables are defined in the same unit. Values are taken from the ROM.
 * extern declarations adjusted to the object (same addresses): D_80800080_chhagstraindoorswitch -> int[] */
extern void _chswitch_entrypoint_6();
extern void func_80105834();
extern void func_80101870();
extern void func_80107C2C();
int D_80800080_chhagstraindoorswitch[20] = { 0x343038D, 0x86D0001, -0x7FEE5D40, (u32)_chswitch_entrypoint_6, (u32)func_80105834, (u32)func_80101870, 0x0, 0x0, 0x0, 0x808, 0x0, 0x0, 0x0, (u32)func_80800040_chhagstraindoorswitch, (u32)func_80107C2C, -0x7FFED3FE, (u32)func_80800000_chhagstraindoorswitch, 0x0, 0x0, 0x0 };
