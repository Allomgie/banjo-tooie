#include "common.h"

extern u16 D_8011B5B8[][4];
extern u16 D_8011B5BA[][4];
extern u16 D_8011B5BC[][4];
typedef struct { u16 unk0; u16 unk2; u16 unk4; u16 unk6; } S8_D3F58;
extern S8_D3F58 D_8011B5C0[];
extern S8_D3F58 D_8011B608;
extern void func_800DA3B8(s32);
extern void *func_800F54E4(void);
extern void func_800F4924(void *, s32);
extern u16 D_8011B5BE[][4];
typedef struct { s16 key; s16 val; } P8011B620;
extern P8011B620 D_8011B620[];
void func_800D4298();
int func_800D42E8();
int func_800D433C();
int func_800D4398();

int func_800D3DD0(s32 param_0)
{
  u16 *local_0 = &D_8011B5B8[param_0][0];
  if (*local_0)
  {
    return func_800DA298(*local_0);
  }
  return 0;
}

s32 func_800D3E14(param_0) s32 param_0;
{
  u16 *new_var;
  u16 *new_var3;
  u16 *new_var2;
  new_var2 = (new_var = (new_var3 = &D_8011B5BA[param_0][0]));
  new_var = new_var2;
  func_800DA298(*new_var);
}

int func_800D3E40(s32 param_0)
{
  u16 *new_var;
  new_var = &D_8011B5BC[param_0][0];
  func_800DA298(*new_var);
}

s32 func_800D3E6C(s32 param_0)
{
  u16 val;
  if (func_800D3E14())
  {
    return 0;
  }
  val = D_8011B5B8[param_0][0];
  if (val)
  {
    return func_800DA298(val);
  }
  return 1;
}

int func_800D3EC8()
{
  if (func_800D3E14())
  {
    return 0 | 0;
  }
  else
  {
    return 1;
  }
}

int func_800D3EF4(s32 param_0)
{
  u16 *local_0 = &D_8011B5B8[param_0][0];
  if (1)
  {
    if (*local_0)
    {
      func_800DA544(*local_0);
    }
  }
}

int func_800D3F2C(s32 param_0)
{
  u16 *new_var;
  u16 *new_var3;
  u16 *new_var2;
  new_var2 = (new_var = (new_var3 = &D_8011B5BA[param_0][0]));
  new_var = new_var2;
  func_800DA544(*new_var);
}

void func_800D3F58(s32 param_0, s32 param_1) {
    func_800DA3B8(D_8011B5C0[param_0 - 1].unk4);
    if (&D_8011B608 == &D_8011B5C0[param_0]) {
        if (param_1 != 0) {
            func_800F4924(func_800F54E4(), 0x3E7);
        }
    }
}

unsigned short func_800D3FC0(s32 param_0)
{
  unsigned short *new_var;
  new_var = &D_8011B5BE[param_0][0];
  return *new_var;
}

void func_800D3FD4(s32 param_0)
{
  s32 local_0;
  s32 local_1;
  s32 local_2;
  local_0 = 0;
  local_1 = 0;
  local_2 = 0;
  if (0 != func_800D3E40(0xA))
  {
    func_800D42E8(0x40, param_0);
    func_800D42E8(0x41, param_0);
    func_800D42E8(0x42, param_0);
    func_800D42E8(0x43, param_0);
    func_800D42E8(0x44, param_0);
    func_800D42E8(0x46, param_0);
    func_800D42E8(0x47, param_0);
    local_0 = local_1 = local_2 = 1;
  }
  else
  {
    if (func_800D3E40(2) != 0)
    {
      func_800D4398(0x40, param_0);
      func_800D4398(0x41, param_0);
      func_800D4398(0x42, param_0);
      func_800D4398(0x43, param_0);
      func_800D4398(0x44, param_0);
      local_0 = local_1 = 1;
    }
    if (func_800D3E40(1) != 0)
    {
      func_800D4398(0x46, param_0);
      local_0 = 1;
      func_800D4398(0x47, param_0);
      local_2 = 1;
    }
  }
  if (local_0 == 0)
  {
    func_800D433C(0x40, param_0);
    local_1 = 1;
    local_2 = 1;
    func_800D433C(0x41, param_0);
    func_800D433C(0x42, param_0);
    func_800D433C(0x43, param_0);
    func_800D433C(0x44, param_0);
    func_800D433C(0x46, param_0);
    func_800D433C(0x47, param_0);
  }
  if (param_0 == 0)
  {
    local_2 = 0;
    local_1 = 0;
  }
  func_800D4298(0x40, local_1);
  func_800D4298(0x41, local_1);
  func_800D4298(0x42, local_1);
  func_800D4298(0x43, local_1);
  func_800D4298(0x44, local_1);
  func_800D4298(0x46, local_2);
  func_800D4298(0x47, 0);
}

s16 func_800D41D8(param_0) s32 param_0;
{
    s32 i;
    for (i = 0; i < 7; i++) {
        if (param_0 == D_8011B620[i].key) {
            return D_8011B620[i].val;
        }
    }
    return 0x3C;
}

void func_800D4298(param_0, param_1) s32 param_0; s32 param_1; {
    s32 temp_v0;
    temp_v0 = func_800D41D8();
    if ((temp_v0 != 0x3C) && (func_800C6E38(temp_v0) == 0)) {
        param_1 = 0;
    }
    func_800D192C(param_0, param_1);
}

int func_800D42E8(param_0, param_1) s32 param_0; s32 param_1;
{
  s32 local_0;
  local_0 = func_800D41D8();
  if (local_0 != 0x3C && func_800C6E38(local_0) == 0)
  {
    param_1 = 0;
  }
  func_800D1960(param_0, -2, param_1);
}

int func_800D433C(param_0, param_1) s32 param_0; s32 param_1;
{
  s32 local_0;
  local_0 = func_800D41D8(param_0);
  if (local_0 != 0x3C)
  {
    local_0 = func_800C6E38(local_0);
    if (!local_0)
    {
      param_1 = 0;
    }
  }
  func_800D1960(param_0, func_800D1ACC(param_0), param_1);
}

int func_800D4398(param_0, param_1) s32 param_0; s32 param_1;
{
  s32 local_0;
  s32 local_1;
  local_0 = func_800D41D8(param_0);
  if (local_0 != 0x3C)
  {
    local_1 = func_800C6E38(local_0 | 0);
    if (!local_1)
    {
      param_1 = 0;
    }
  }
  local_1 = func_800D1ACC(param_0);
  func_800D1960(param_0, local_1 << 1, param_1);
}
