#include "common.h"

extern int D_80800050_chwitchytents;
extern int D_80800098_chwitchytents;

s32 func_80800000_chwitchytents(s32 param_0){
    if(func_800EA05C() == 0x124){
        func_8010A624(param_0);
    }
}

int chwitchytents_entrypoint_0()
{
  return &D_80800050_chwitchytents;
}

int chwitchytents_entrypoint_1()
{
  return (int)&D_80800098_chwitchytents;
}
