#include "common.h"

extern int D_80800060_chfantasybounce;
extern int D_808000A8_chfantasybounce;

s32 func_80800000_chfantasybounce(f32 param_0[4]){
    func_800EFA4C(param_0 + 1, 0xC62C8A36, 0x4604CA00, 0xC6149236);
}

int *chfantasybounce_entrypoint_0()
{
    return &D_80800060_chfantasybounce;
}

int chfantasybounce_entrypoint_1()
{
  return (int)&D_808000A8_chfantasybounce;
}
