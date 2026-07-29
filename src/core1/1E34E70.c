#include "common.h"

extern s32 D_8007D160;
extern void func_8001DA00(s32, s32);
extern void _Printf(void *param_0, ...);
extern void func_8001D9CC();

int func_8001D340(s32 param_0, s32 param_1, s32 param_2)
{
  if (D_8007D160 & 1)
  {
    func_8001DA00(param_1 | 0, param_2 | 0);
  }
  return 1;
}

void func_8001D37C(s32 param_0, ...) {
    s32 local_0;

    D_8007D160 = 1;
    local_0 = (s32)&param_0;
    local_0 += 7;
    local_0 &= ~3;
    _Printf(&func_8001D340, 0, param_0, local_0);
}

void func_8001D3D8(s16 param_0, s16 param_1, s32 param_2, ...) {
    s32 local_0;

    D_8007D160 = 1;
    func_8001D9CC((u16)param_0, (u16)param_1);
    local_0 = (s32)&param_2;
    local_0 += 7;
    local_0 &= ~3;
    _Printf(&func_8001D340, 0, param_2, local_0);
}
