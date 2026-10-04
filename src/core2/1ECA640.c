#include "core2/1ECA640.h"

extern f32 func_80013970(f32);
extern f32 func_800138D0(f32);
extern f32 func_800F2108(void);
extern f32 func_8001395C(f32);
extern f32 func_800F1DCC(f32, f32);
f32 func_800F13C4(f32 param_0, f32 param_1);
f32 func_800F1434(f32 param_0);
void func_800F14AC(f32 param_0);

f32 func_800F0D50(f32 param_0, f32 param_1, f32 param_2){
    if(param_0 < param_1){
        return param_1;
    }else if(param_2 < param_0){
        return param_2;
    }else{
        return param_0;
    }
}

func_800F0D90(s32 param_0, s32 param_1, s32 param_2) {
    if (param_0 < param_1)
        return param_1;
    if (param_2 < param_0)
        return param_2;
    return param_0;
}

f32 func_800F0DC0(f32 param_0, f32 param_1) {
    if (param_1 < param_0) {
        return param_1;
    } else {
        f32 neg_param1 = -param_1;
        if (neg_param1 > param_0) {
            return neg_param1;
        } else {
            return param_0;
        }
    }
}

f32 func_800F0E00(f32 param_0, f32 param_1)
{
  f32 new_var3;
  int new_var2;
  f32 new_var;
  f32 local_0;
  new_var3 = param_0;
  new_var = param_1;
  new_var3 = param_1;
  new_var = param_0;
  new_var2 = new_var3 < ((0, new_var));
  if (new_var2)
  {
    new_var = param_0;
    local_0 = new_var;
  }
  else
  {
    local_0 = new_var3;
  }
  return local_0;
}

func_800F0E28(s32 param_0, s32 param_1) {
    return (param_1 < param_0) ? param_0 : param_1;
}

func_800F0E44(param_0) {
    while (param_0 < 0){
        param_0 += 0x168;
    }

    while (param_0 >= 0x168){
        param_0 -= 0x168;
    }

    return param_0 | 0;
}

f32 func_800F0E7C(f32 param_0, f32 param_1)
{
  if (param_1 + 180.0f < param_0)
    {
        do
        {
            param_0 -= 360.0f;
        }
        while (param_1 + 180.0f < param_0);
    }
  if (param_0 < param_1 - 180.0f)
    {
        do
        {
            param_0 += 360.0f;
        }
        while (param_0 < param_1 - 180.0f);
    }
  return param_0;
}

void func_800F0EF0(s32 param_0, f32 *param_1)
{
  f32 local_0;
  s32 local_1;
  s32 local_2;
  f32 *local_3;
  ;
  local_2 = 0;
  if (((param_0 * 3) - 3) > 0)
  {
    local_3 = param_1;
    do
    {
      local_0 = local_3[0];
      local_2 += 1;
      if ((local_3[3] + 180.0f) <= local_0)
      {
        do
        {
          local_3[3] = (f32) (local_3[3] + 360.0f);
        }
        while ((local_3[3] + 180.0f) <= local_0);
      }
      if (local_0 <= (local_3[3] - 180.0f))
      {
        do
        {
          local_3[3] = (f32) (local_3[3] - 360.0f);
        }
        while (local_0 <= (local_3[3] - 180.0f));
      }
      local_3 += 1;
    }
    while (local_2 != ((param_0 * 3) - 3));
  }
}

f32 func_800F0F9C(f32 param_0, f32 param_1)
{
  f32 local_0;
  local_0 = func_800F13C4(param_0, param_1);
  return local_0 / param_1;
}

f32 func_800F0FC4(f32 param_0, f32 param_1) {
    return (func_80013970(func_800F13C4(param_0, param_1) / param_1 * 360.0f) + 1.0f) * 0.5f;
}

f32 func_800F101C(f32 param_0, f32 param_1) {
    return (func_800138D0(func_800F13C4(param_0, param_1) / param_1 * 360.0f) + 1.0f) * 0.5f;
}

f32 func_800F1074(f32 param_0, f32 param_1) {
    return func_80013970(func_800F13C4(param_0, param_1) / param_1 * 360.0f);
}

f32 func_800F10B4(f32 param_0, f32 param_1, f32 param_2, f32 param_3, f32 param_4)
{
  f32 local_0;
  if (param_2 != param_1)
  {
    if (param_3 < param_4)
    {
      local_0 = (param_0 - param_1) / (param_2 - param_1) * (param_4 - param_3) + param_3;
      if (local_0 > param_4)
      {
        return param_4;
      }
      else if (local_0 < param_3)
      {
        return param_3;
      }
    }
    else
    {
      local_0 = (param_0 - param_1) / (param_2 - param_1) * (param_4 - param_3) + param_3;
      if (local_0 < param_4)
      {
        return param_4;
      }
      else if (local_0 > param_3)
      {
        return param_3;
      }
    }
    return local_0;
  }
  return param_4;
}

f32 func_800F1198(f32 param_0, f32 param_1, f32 param_2, f32 param_3, f32 param_4)
{
  if (param_2 != param_1)
  {
    return (((param_0 - param_1) / (param_2 - param_1)) * (param_4 - param_3)) + param_3;
  }
  return param_4;
}

f32 func_800F11E4(f32 param_0, f32 param_1, f32 param_2, f32 param_3, f32 param_4) {
    f32 local_0;
    f32 local_1;

    local_0 = param_0 - param_1;
    local_1 = param_2 - param_1;
    return ((local_0 / local_1) * (param_4 - param_3)) + param_3;
}

f32 func_800F1214(f32 value, f32 min, f32 max) {
    return ((max - min) * value) + min;
}

f32 func_800F122C(f32 param_0, f32 param_1, f32 param_2) {
    f32 t = func_800F2108();
    param_0 *= t;
    t *= (param_2 - param_1) * param_0 + param_1;
    return t;
}

f32 func_800F1274(f32 p0, f32 p1, f32 p2, f32 p3, f32 p4, f32 (*p5)(f32)) {
    f32 r = func_800F10B4(p0, p1, p2, 0.0f, 1.0f);
    r = p5(r);
    func_800F10B4(r, 0.0f, 1.0f, p3, p4);
}

f32 func_800F12D4(f32 p0, f32 p1, f32 p2, f32 p3, f32 p4) {
    return func_800F1274(p0, p1, p2, p3, p4, func_800F1434);
}

f32 func_800F130C(f32 p0, f32 p1, f32 p2, f32 p3, f32 p4) {
    return func_800F1274(p0, p1, p2, p3, p4, func_800F14AC);
}

void func_800F1344(f32 param_0, f32 param_1, f32 param_2, f32 param_3, f32 param_4) {
    if (param_0 < 0.0f) {
        func_800F10B4(param_0, -param_1, -param_2, -param_3, -param_4);
    } else {
        func_800F10B4(param_0, param_1, param_2, param_3, param_4);
    }
}

f32 func_800F13C4(f32 param_0, f32 param_1)
{
    f32 temp_f2;

    temp_f2 = param_0 / param_1;
    return (temp_f2 - (f32)(s32)temp_f2) * param_1;
}

f32 func_800F13F0(f32 param_0, f32 param_1){
    f32 local_0;
    if(param_0 < param_1)
        local_0 = param_0;
    else
        local_0 = param_1;

    return local_0;
}

s32 func_800F1418(s32 param_0, s32 param_1) {
    return param_0 < param_1 ? param_0 : param_1;
}

f32 func_800F1434(f32 param_0)
{
  return (func_8001395C(param_0 * 3.1415927f + (-1.5707964f)) + 1.0f) * 0.5f;
}

int func_800F1480(f32 param_0)
{
  func_80013970(param_0 * 90.0f);
}

void func_800F14AC(f32 param_0)
{
  f32 local_0;
  local_0 = func_800F1434(param_0);
  func_800F1434(local_0);
}

f32 func_800F14D4(f32 param_0, f32 param_1) {
    f32 local_0;
    if (param_0 <= param_1) {
        local_0 = param_0;
    } else {
        local_0 = param_1;
    }
    return local_0;
}

f32 func_800F14FC(f32 param_0, f32 param_1, f32 param_2)
{
  f32 local_0;
  float new_var;
  if (param_2 < param_0)
  {
    return 0.0f;
  }
  if (param_1 <= param_2)
  {
    return 1.0f;
  }
  local_0 = (param_2 - param_0) / (param_1 - param_0);
  return (local_0 * local_0) * (3.0f - (2.0f * local_0));
}

int func_800F1574(f32 *param_0, f32 param_1)
{
    if (*param_0 > 0) {
        *param_0 -= param_1;

        if (*param_0 <= 0) {
            *param_0 = 0;
            return TRUE;
        }
    }

    return FALSE;

}

f32 func_800F15C4(f32 param_0, u32 param_1)
{
  f32 local_0;
  local_0 = 1.0f;
  while (param_1 != 0)
  {
    if (param_1 & 1)
    {
      local_0 *= param_0;
    }
    param_0 *= param_0;
    (s32)(param_1) >>= 1;
  }
  return local_0;
}

f32 func_800F15F8(f32 param_0, f32 param_1, f32 param_2)
{
    if (param_0 < param_1) {
        return func_800F13F0(param_0 + param_2, param_1);
    }
    if (param_1 < param_0) {
        return func_800F0E00(param_0 - param_2, param_1);
    }
    return param_0;
}

s32 func_800F1660(f32 param_0, f32 param_1){
    if(param_0 < 0.0f)
        param_0 = -param_0;
    if(param_1 < 0.0f)
        param_1 = -param_1;
    return param_1 < param_0;
}

void func_800F16AC(f32 *param_0, f32 *param_1, f32 *param_2, f32 param_3) {
    f32 *local_0 = param_1;
    s32 local_1 = 0;
    f32 *local_2 = param_2;
    f32 *local_3 = param_0;
    for (; local_1 < 3; local_1++) {
        *local_3 = *local_0 - func_800F1DCC(*local_0, *local_2) * param_3;
        local_0++;
        local_2++;
        local_3++;
    }
}

f32 func_800F1738(f32 param_0, f32 param_1, f32 param_2)
{
    f32 local_0;
    f32 local_1;
    local_0 = func_800F1DCC(param_0, param_1);
    local_1 = func_800F1DCC(param_2, param_1);
    if (local_1 > 0.0f) {
        if (local_0 < 0.0f) param_0 = param_1;
        else if (local_1 < local_0) param_0 = param_2;
    } else {
        if (local_0 > 0.0f) param_0 = param_1;
        else if (local_0 < local_1) param_0 = param_2;
    }
    return param_0;
}
