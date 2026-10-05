#include "common.h"

s16 D_8012B260[23];
extern s32 func_800D395C();
extern s32 D_8012B290;

u8 *func_800D1FC0(param_0) s32 param_0;
{
    u8 *var_v1;

    param_0 -= 0x80;
    if (func_800D395C(param_0) != 0)
    {
        var_v1 = (param_0 * 2) + ((u8 *) &D_8012B290);
    }
    else
    {
        var_v1 = (param_0 * 2) + ((u8 *) D_8012B260);
    }
    return var_v1;
}

void func_800D2014(void) {
    s32 i;
    for (i = 0; i < 23; i++) {
        D_8012B260[i] = 0;
    }
}

s32 func_800D2054(s32 param_0, s32 param_1, s32 param_2)
{
    s32 local_0;
    s16 *local_1;
    s32 local_2;
    local_1 = func_800D1FC0(param_1);
    if (*local_1 == 0) local_0 = 1;
    else {
        switch (param_0) {
        case 0: local_2 = param_2 - *local_1; break;
        case 1: local_2 = *local_1 - param_2; break;
        }
        local_0 = local_2 <= 0 ? (local_2 != 0 ? -1 : 0) : 1;
    }
    if (local_0 == 1) {
        if (func_800D395C()) func_800DA544(0xD54);
        *local_1 = param_2;
    }
    return local_0;
}

int func_800D211C()
{
  s16 *local_0;
  local_0 = func_800D1FC0();
  return *local_0;
}

s32 func_800D2140() 
{
    return 0x2E;
}

int func_800D2148(u8 *param_0, u32 param_1)
{
  u32 local_0;
  int local_1 = param_1 >> 1;
  if (0x18 <= local_1)
  {
    local_1 = 0x17;
  }
  local_0 = (u32) param_0;
  rare_memcpy(((s32 *) D_8012B260), local_0, local_1 << 1);
}

s32 func_800D2188(void *param_0) {
    s32 local_0;

    rare_memcpy(param_0, ((s32 *) D_8012B260), 0x2E);
}

int func_800D21B0(s32 *param_0, s32 **param_1)
{
  *param_0 = 0x2E;
  *param_1 = &D_8012B290;
}
