#include "common.h"

extern s32 _cadbmgrDll_entrypoint_0(void *, s32);
struct struct_80119540 { char pad[0x30]; s32 unk30; s32 unk34; };
void func_8001B754();
extern u32 D_8011951C[];
typedef struct { u8 pad_0[0x30]; u32 local_0; u8 pad_34[8]; u8 local_1[1]; } Struct800A587C;

extern s32 D_80119540;

s32 func_800A5550(s32 param_0, s32 param_1)
{
  s32 local_0;
  s32 local_1;
  local_0 = (s32)((u32)(*(u16 *)((char *)param_1 + 0x1A)) >> 5);
  local_1 = func_800A93E4(local_0);
  local_1 = func_80110014(local_1);
  _ncbaspline_entrypoint_5(local_1, param_0, param_1);
}

s32 func_800A5598(s32 param_0, u16 *param_1)
{
  s32 local_0;
  s32 local_1;
  local_0 = (s32)((u32)(*(u16 *)((char *)param_1 + 0x1A)) >> 5);
  local_1 = func_800A93E4(local_0);
  local_1 = func_80110014(local_1);
  _ncbaspline_entrypoint_6(local_1, param_0, param_1);
}

void func_800A55E0(void) {
    _cadbmgrDll_entrypoint_0(((u8 *) &D_80119540), 0x7D);
}

int func_800A5608(s32 param_0)
{
  s32 local_0;
  local_0 = param_0 | 0;
  return _cadbmgrDll_entrypoint_0(&D_80119540, local_0);
}

void func_800A5630()
{
    _cadbmgrDll_entrypoint_1(&D_80119540);
}

void func_800A5654()
{
    if (((u8*) D_80119540) != 0)
    {
        ((u8*) D_80119540) = (s32)defrag((void*)((u8*) D_80119540));
        ((struct struct_80119540*)((u8*) D_80119540))->unk30 = -1;
        ((struct struct_80119540*)((u8*) D_80119540))->unk34 = 0;
    }
}

void func_800A56A4(void)
{
  s32 var_s0;
  s32 var_s1;
  s32 var_v0;
  s32 var_v1;
  s16 temp_a0;
  if (((u8 *) D_80119540) != 0)
  {
    var_s0 = 1;
    var_s1 = 2;
    do
    {
      temp_a0 = *((s16 *) ((((u8 *) D_80119540) + var_s1) + 0x1E));
      if (temp_a0 != 0)
      {
 do { func_8001B754(temp_a0, ((u8 *) D_80119540)); } while (0);
        *((s16 *) ((((u8 *) D_80119540) + var_s1) + 0x1E)) = 0;
        *((s32 *) ((((u8 *) D_80119540) + (var_s0 * 4)) - 4)) = 0;
      }
      var_s0++;
      var_s1 += 2;
    }
    while (var_s0 != 9);
    var_v1 = 0;
    var_v0 = 0;
    if ((*((s32 *) (((u8 *) D_80119540) + 0x38))) >= 0)
    {
      do
      {
        *((u8 *) ((((u8 *) D_80119540) + var_v0) + 0x3C)) = 0;
        var_v1++;
        *((u8 *) ((((u8 *) D_80119540) + var_v0) + 0x3D)) = 0xFF;
        var_v0 += 2;
      }
      while ((*((s32 *) (((u8 *) D_80119540) + 0x38))) >= var_v1);
    }
    *((s32 *) (((u8 *) D_80119540) + 0x30)) = -1;
    *((s32 *) (((u8 *) D_80119540) + 0x34)) = 0;
  }
}

s32 func_800A5790(s32 param_0, s32 param_1)
{
    s32 local_0;
    local_0 = (param_1 * D_8011951C[param_0]) + func_8001B798(*(s16 *)(((s8 *)((s32 *) D_80119540)) + param_0 * 2 + 0x1E));
    return local_0;
}

int func_800A57EC(s32 param_0)
{
  return ((s32 *) D_8011951C)[param_0];
}

s32 func_800A5800(s32 param_0)
{
  unsigned int new_var;
  u8 *local_0;
  new_var = param_0 * 2;
  *((s32 *) (0x30 + ((s8 *) ((u8 *) D_80119540)))) = param_0;
  local_0 = ((u8 *) D_80119540) + new_var;
  *((s32 *) (((s8 *) ((u8 *) D_80119540)) + 0x34)) = func_800A5790(*((u8 *) (((s8 *) local_0) + 0x3C)), *((u8 *) (((s8 *) local_0) + 0x3D)));
  return *((s32 *) (((s8 *) ((u8 *) D_80119540)) + 0x34));
}

u8 func_800A5854(param_0) s32 param_0;
{
  int new_var;
  new_var = (param_0 * 2) + 0x3c;
  return ((u8 *) D_80119540)[new_var];
}

int func_800A586C()
{
  return ((s32*)D_80119540)[0x34 / 4];
}

u8 func_800A587C()
{
  return ((Struct800A587C *) D_80119540)->local_1[((Struct800A587C *) D_80119540)->local_0 * 2];
}

int func_800A5898()
{
  return ((s32*)D_80119540)[0x30 / 4];
}

void func_800A58A8(s32 arg0, s32 arg1)
{
  int new_var2;
  u8 *new_var;
  new_var2 = D_80119540;
  new_var = (u8 *) (new_var2 + (arg0 * 2));
  if ((arg1 != new_var[0x3C]) && (arg1 != 0))
  {
    _cadbmgrDll_entrypoint_2(new_var2, arg1, arg0);
  }
}

s32 func_800A58F0(void) {
    return (*(s32 *)((s8 *)(((s8 *) D_80119540)) + (0x38))) + 1;
}

s32 func_800A5904()
{
  s32 ret = func_800A5854();
  return (ret != 0);
}
