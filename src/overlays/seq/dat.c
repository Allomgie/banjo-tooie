#include "common.h"

extern s16 D_80800030_seqdat[];

int seqdat_entrypoint_0(s32 param_0, s32 param_1)
{
  short new_var;
  if (!param_1)
  {
    ;
    return D_80800030_seqdat[param_0];
  }
  return (!param_1) * 0;
}
