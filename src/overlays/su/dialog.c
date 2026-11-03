#include "common.h"

typedef struct { s16 id; s16 pad; } DialogEntry;
extern int D_808000E0_sudialog[];
extern int D_808000E2_sudialog[];

s32 func_80800000_sudialog(DialogEntry *param_0, s32 param_1) {
    s32 i;
    for (i = 0; param_0[i].id >= 0; i++) {
        if (param_0[i].id == param_1) {
            return i;
        }
    }
    return -1;
}

int sudialog_entrypoint_0(s32 param_0, s32 param_1)
{
  s32 local_0;
  if (func_800DA298(param_0))
  {
    return 0;
  }
  local_0 = func_80800000_sudialog(&D_808000E0_sudialog, param_0);
  if (local_0 != -1)
  {
    if (func_800C05B8(*(s16 *)((char *)D_808000E2_sudialog + local_0 * 4), param_1, 0, 0, 0, 0, 0))
    {
      func_800DA544(param_0);
    }
    func_800DA298(param_0);
  }
  else
  {
    return 0;
  }
}

/* TU-NOTE: the .data of this overlay (formerly asm/data/overlays/su/dialog.data.s) is defined here in C.
 * Values are taken from the ROM.
 * Labels inside an object are linker symbols in undefined_syms.us.txt: D_808000E2_sudialog = D_808000E0_sudialog + 0x2
 * extern declarations adjusted to the object (same addresses): D_808000E0_sudialog -> int[] */
int D_808000E0_sudialog[20] = { 0x290CDB, 0x2A0CDC, 0x2B0CDD, 0x2C0CDE, 0x2D0CDF, 0x2F0CE0, 0x320CE1, 0xE80D8C, 0x19F10C4, 0x1651013, 0x3641369, 0x4F50D81, 0x5011E7, 0x4E121F, 0x4F1220, 0x2E0D04, -0x1, 0x0, 0x0, 0x0 };
