#include "common.h"

extern int D_808000A0_chicekey;
extern int D_808000EC_chicekey;

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/icekey/func_80800000_chicekey.s")

int chicekey_entrypoint_0()
{
  return (int)&D_808000EC_chicekey;
}
