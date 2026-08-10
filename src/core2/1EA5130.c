#include "common.h"

extern s32 D_8012AE74;
extern int D_8012AE70[];

void func_800CB840(s32 param_0, s32 param_1)
{
  *(s16*)((s32 *) D_8012AE70) = (s16)param_0;
  *(s32*)((char*)((s32 *) D_8012AE70) + 4) = param_1;
}

int func_800CB854(s32 *param_0)
{
  if (param_0 != 0)
  {
    *param_0 = D_8012AE74;
  }
  return (*((s16 *) D_8012AE70));
}

int func_800CB870()
{
  *(s16 *)D_8012AE70 = 0;
  D_8012AE70[1] = 0;
}
