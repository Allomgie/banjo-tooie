#include "common.h"

extern s16 D_80800040_gsproplookup[];
extern s16 D_808000F4_gsproplookup[];

s32 gsproplookup_entrypoint_0(u16 *param_0)
{
  return D_80800040_gsproplookup[(((param_0[0] & 0xFFFFFFFFu) & 0xFFFFFFFFu) & 0xFFFFFFFFu) >> 4];
}

int gsproplookup_entrypoint_1(u16 *param_0)
{
  return D_808000F4_gsproplookup[((u32) (*param_0)) >> 4];
}
