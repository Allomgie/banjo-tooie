#include "common.h"

int func_800F9F90(s32 *param_0, s32 *param_1)
{
  s32 *local_0;
  s32 *local_1;
  local_1 = param_0 + 2;
  local_0 = (s32 *) (((char *) param_0) + ((*((s32 *) (((char *) param_1) + 0x2C))) * 8) + 8);
  while (local_1 < local_0)
  {
    if ((*((s32 *) (((char *) local_1) + 4))) != 0)
    {
      *((s32 *) (((char *) local_1) + 4)) = defrag(*((s32 *) (((char *) local_1) + 4)));
    }
    local_1 = (s32 *) (((char *) local_1) + 8);
  }

  return defrag(param_0);
}
