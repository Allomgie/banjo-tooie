#include "core2/1E76360.h"

extern s32 D_80117F34[];
extern u32 D_80117F38[1202];
extern u16 D_80117F32[];

s32 func_8009CA70(PlayerState *param_0, s32 param_1, s32 param_2) {
    s32 local_0 = param_1 * 12;
    return (*(s32*)((char*)D_80117F34 + local_0) & param_2) ? 1 : 0;
}

s32 func_8009CAAC(s32 param_0, s32 param_1) {
    s32 (*local_0)(s32);

    local_0 = (s32 (*)(s32))*(u32*)&((u8 *) D_80117F38)[param_1 * 0xC];
    if (local_0 != NULL) {
        return local_0(0);
    }
    return 0;
}

int func_8009CAF8(s32 param_0, s32 param_1)
{
  int new_var;
  u32 idx;
  int new_var2;
  new_var = ((((param_1 * 3) & 0xFFFFFFFFFFFFFFFFu) & 0xFFFFFFFFFFFFFFFFu) & 0xFFFFFFFFFFFFFFFFu) & 0xFFFFFFFFFFFFFFFFu;
  new_var2 = (((new_var & 0xFFFFFFFFFFFFFFFFu) & 0xFFFFFFFFFFFFFFFFu) & 0xFFFFFFFFFFFFFFFFu) & 0xFFFFFFFFFFFFFFFFu;
  idx = (new_var2 & 0xFFFFFFFFFFFFFFFFu) & 0xFFFFFFFFFFFFFFFFu;
  if (D_80117F38[idx] != 0)
  {
    return ((int (*)(s32)) D_80117F38[idx])(1);
  }
  return 0;
}

s32 func_8009CB44(s32 param_0, s32 param_1)
{
  s32 *new_var;
  s32 (*local_0)(s32);
  new_var = (s32 *)&((u8 *) D_80117F38)[param_1 * 0xC];
  local_0 = *new_var;
 if (local_0 != 0) { return local_0(3);
  }
  return 0;
}

int func_8009CB90(s32 param_0, s32 param_1)
{
  int new_var3;
  int (*new_var)(s32);
  int new_var2;
  new_var3 = (((3 * param_1) & 0xFFFFFFFFFFFFFFFFu) & 0xFFFFFFFFFFFFFFFFu) & 0xFFFFFFFFFFFFFFFFu;
  new_var2 = (((((new_var3 & 0xFFFFFFFFFFFFFFFFu) & 0xFFFFFFFFFFFFFFFFu) & 0xFFFFFFFFFFFFFFFFu) & 0xFFFFFFFFFFFFFFFFu) & 0xFFFFFFFFFFFFFFFFu) & 0xFFFFFFFFFFFFFFFFu;
  new_var = (int (*)(s32)) D_80117F38[(new_var2 & 0xFFFFFFFFFFFFFFFFu) & 0xFFFFFFFFFFFFFFFFu];
  if (new_var != 0)
  {
    return new_var(2);
  }
  return 0;
}

short func_8009CBDC(s32 param_0, s32 param_1)
{
  return *(s16 *)((char *)D_80117F32 + param_1 * 12);
}

func_8009CBFC(s32 param_0) {
}
