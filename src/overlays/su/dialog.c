#include "common.h"

typedef struct { s16 id; s16 pad; } DialogEntry;
extern int D_808000E0_sudialog;
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
