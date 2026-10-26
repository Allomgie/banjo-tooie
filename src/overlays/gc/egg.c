#include "common.h"

extern u8 D_80800200_gcegg[];
extern u8 D_8080020C_gcegg[];
extern int D_80800202_gcegg[];
extern int D_80800206_gcegg[];
extern u8 D_80800209_gcegg[][14];
extern u8 D_8080020A_gcegg[][14];
extern u8 D_8080020B_gcegg[];

u8 gcegg_entrypoint_0(s32 param_0)
{
  int new_var;
  u8 *var_v1;
  u8 *new_var2;
 new_var = 0x32; var_v1 = D_80800200_gcegg; loop_1: if (param_0 == (*((s16 *) (var_v1 + 0)))) {
    return var_v1[8];
  }

  if (param_0 == (*((s16 *) (var_v1 + 0xE))))
  {
    return var_v1[0x16];
  }
  if (param_0 == (*((s16 *) (var_v1 + 0x1C))))
  {
    return var_v1[0x24];
  }
  if (param_0 == (*((s16 *) (var_v1 + 0x2A))))
  {
    return var_v1[new_var];
  }
  new_var2 = D_8080020C_gcegg + 0x64;
  var_v1 += 0x38;
  if (var_v1 == new_var2)
  {
    return 0U;
  }
  goto loop_1;
}

u8 gcegg_entrypoint_1(s32 param_0)
{
  u8 *var_v1;
  u8 *new_var;
  s16 *new_var2;
 var_v1 = &D_80800200_gcegg; loop_1: if (param_0 == (*((s16 *) (var_v1 + 4)))) { return *(var_v1 + 8); }
  if (param_0 == (*((s16 *) (var_v1 + 0x12))))
  {
    return *(var_v1 + 0x16);
  }
  new_var2 = (s16 *) (var_v1 + 0x20);
  if (param_0 == (*new_var2))
  {
    return *(var_v1 + 0x24);
  }
  if (param_0 == (*((s16 *) (var_v1 + 0x2E))))
  {
    return *(var_v1 + 0x32);
  }
  var_v1 += 0x38;
  if ((new_var = var_v1) == (D_8080020C_gcegg + 0x64))
  {
    return 0U;
  }
  goto loop_1;
}

short gcegg_entrypoint_2(s32 param_0)
{
  return *(s16 *)((char *)D_80800202_gcegg + param_0 * 14);
}

s16 gcegg_entrypoint_3(s32 param_0)
{
  return *(s16 *)((char *)D_80800206_gcegg + param_0 * 14);
}

s32 gcegg_entrypoint_4(s32 param_0)
{
    return D_8080020C_gcegg[param_0 * 14];
}

u8 gcegg_entrypoint_5(s32 param_0)
{
  return D_80800209_gcegg[param_0][0];
}

int gcegg_entrypoint_6(s32 param_0) {
    s32 local_0 = D_8080020A_gcegg[param_0][0];
    return local_0 == 0x3C || func_800C6E38(local_0) != 0;
}

u8 gcegg_entrypoint_7(s32 param_0)
{
  u8 new_var;
  if (func_800D3948() == 0U)
  {
    return 1;
  }
  return new_var = D_8080020B_gcegg[param_0 * 0xE];
}
