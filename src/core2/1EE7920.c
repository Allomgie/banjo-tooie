#include "common.h"

extern s32 D_80127614;
extern s32 defrag(s32);

int func_8010E030()
{
  if (D_80127614 != 0)
  {
    D_80127614 = defrag(D_80127614);
  }
}
