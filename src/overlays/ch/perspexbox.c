#include "common.h"

extern s32 D_80800090_chperspexbox;
extern s32 D_80800124_chperspexbox;
extern void *D_80800138_chperspexbox;

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/perspexbox/func_80800000_chperspexbox.s")

int chperspexbox_entrypoint_0()
{
  return &D_80800138_chperspexbox;
}
