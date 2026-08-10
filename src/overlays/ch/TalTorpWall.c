#include "common.h"

extern int D_80800080_chTalTorpWall;
extern u8 D_80800098_chTalTorpWall[];

void func_80800000_chTalTorpWall(s32 arg0) 
{
}
int func_80800008_chTalTorpWall(s32 param_0, s32 param_1, s32 param_2)
{
  if (param_1 == 0x40)
  {
    _chexploder_entrypoint_3(param_0, param_0 + 4, 0xE);
    _subaddieaudioquick_entrypoint_2(param_0, param_0 + 4, &D_80800080_chTalTorpWall);
    func_800DA544(0x3AA);
    return 1;
  }
  return 0;
}

u8 *chTalTorpWall_entrypoint_0(void) {
    return D_80800098_chTalTorpWall;
}
