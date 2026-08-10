#include "common.h"

void dbpalette_entrypoint_0(s32 param_0, s32 param_1, u8 *param_2)
{
  u32 *local_0;
  local_0 = param_0 + (((unsigned long) param_1) * 4);
  *((s32 *) (((s8 *) param_2) + 0)) = (s32) ((*local_0) & 0xFF);
  *((s32 *) (param_2 - -4)) = (s32) ((((u32) (*local_0)) >> 8) & 0xFF);
  *((s32 *) (((s8 *) param_2) + 8)) = (s32) ((((u32) (*local_0)) >> 0x10) & 0xFF);
  *((s32 *) (((s8 *) param_2) + 0xC)) = (s32) ((((u32) (*local_0)) >> 0x18) & 0xFF);
}

s32 dbpalette_entrypoint_1(u32 *agrs1, int indx, s32 *argb){
    agrs1[indx] = 0;
    agrs1[indx] = (u32)argb[0];
    agrs1[indx] |= (u32)argb[1] << 8;
    agrs1[indx] |= (u32)argb[2] << 0x10;
    agrs1[indx] |= (u32)argb[3] << 0x18;
}
