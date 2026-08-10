#include "common.h"

extern int D_80800030_fxgenlist;
extern int D_8080005C_fxgenlist;
extern int D_808000A0_fxgenlist;
extern s32 D_808000D0_fxgenlist[];

int fxgenlist_entrypoint_0()
{
  return (int)&D_80800030_fxgenlist;
}

int fxgenlist_entrypoint_1()
{
  return (int)&D_8080005C_fxgenlist;
}

int fxgenlist_entrypoint_2()
{
    return (int)&D_808000A0_fxgenlist;
}

int fxgenlist_entrypoint_3()
{
    return (int)D_808000D0_fxgenlist;
}
