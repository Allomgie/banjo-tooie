#include "common.h"

extern s32 D_8007DA60;

s32 gleeprom_entrypoint_0(void) {
    return (*(s32 *)((s8 *)&D_8007DA60 + 0xF0)) ^ 0xBD1F0416;
}

int gleeprom_entrypoint_1(s32 param_0, s32 param_1, u32 *param_2)
{
  s32 local_1;
  s32 local_0;

  func_80016934(3);
  local_0 = osEepromLongWrite(func_80016928(), (param_0 / 8) & 0xFF, param_1, param_2);
  func_80016934(0);
  return local_0;
}

int gleeprom_entrypoint_2(s32 param_0, s32 param_1, s32 param_2)
{
  s32 pad0;
  u32 local_0;
  func_80016934(3);
  local_0 = osEepromLongRead(func_80016928(), (param_0 / 8) & 0xFF, param_1, param_2);
  func_80016934(0);
  return local_0;
}
