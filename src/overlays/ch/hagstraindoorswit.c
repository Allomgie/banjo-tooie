#include "ch/hagstraindoorswit.h"

extern int D_80800080_chhagstraindoorswitch;

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
