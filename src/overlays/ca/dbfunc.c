#include "common.h"

extern void func_800EE7F8(s32, s32);
s32 func_80800000_cadbfunc();
s32 func_80800C9C_cadbfunc();

s32 func_80800000_cadbfunc() {
    s32 temp_v0;

    temp_v0 = func_800A587C();
    switch (temp_v0) {
    case 3:
        return func_800A586C();
    case 1:
        return func_800A586C();
    case 2:
        return func_800A586C();
    case 5:
        return func_800A586C();
    case 6:
        return func_800A586C();
    case 8:
        return func_800A586C();
    default:
        return 0;
    }
}

s32 cadbfunc_entrypoint_0(s32 param_0) {
    s32 local_0 = func_80800000_cadbfunc(param_0);
    if (local_0 == 0) {
        return 0;
    }
    func_800EE7F8(param_0, local_0);
    return 1;
}

int cadbfunc_entrypoint_1(s32 param_0)
{
  s32 local_0;
  local_0 = func_80800000_cadbfunc();
  if (!local_0)
    return 0;
  func_800EE7F8(local_0 | 0, param_0);
  return 1;
}

int func_80800120_cadbfunc()
{
    switch (func_800A587C())
    {
    case 2:
        return func_800A586C() + 0xc;
    case 5:
        return func_800A586C() + 0xc;
    case 6:
        return func_800A586C() + 0xc;
    case 8:
        return func_800A586C() + 0xc;
    default:
        return 0;
    }
}

int cadbfunc_entrypoint_2(Actor *param_0)
{
  s32 local_0;
  local_0 = func_80800120_cadbfunc();
  if (!local_0)
  {
    return 0;
  }
  else
  {
    func_800EE7F8(param_0, local_0);
    return 1;
  }
}

s32 cadbfunc_entrypoint_3(s32 param_0) {
    s32 out;

    out = func_80800120_cadbfunc();
    if (out == 0) {
        return 0;
    }
    func_800EE7F8(out, param_0);
    return 1;
}

int func_80800224_cadbfunc()
{
    switch (func_800A587C())
    {
    case 1:
        return func_800A586C() + 0x1C;
    case 3:
        return func_800A586C() + 0x24;
    default:
        return 0;
    }
}

s32 cadbfunc_entrypoint_4(s32 param_0) {
    s32 out;

    out = func_80800224_cadbfunc();
    if (out == 0) {
        return 0;
    }
    func_800EE7F8(param_0, out | 0);
    return 1;
}

int cadbfunc_entrypoint_5(s32 param_0)
{
  s32 local_0;
  local_0 = func_80800224_cadbfunc();
  if (!local_0)
  {
    return 0;
  }
  func_800EE7F8(local_0 | 0, param_0);
  return 1;
}

int func_808002F8_cadbfunc()
{
    switch (func_800A587C())
    {
        case 1 :
            return func_800A586C() + 0xC;

        case 3 :
            return func_800A586C() + 0xC;

        default :
            return 0;
    }
}

int cadbfunc_entrypoint_6(f32 *param_0, f32 *param_1)
{
  s32 local_0;
  f32 *local_1;
  local_0 = func_808002F8_cadbfunc();
  if (!local_0)
    return 0;
  local_1 = local_0;
  param_0[0] = local_1[0];
  param_1[0] = local_1[1];
  return 1;
}

s32 cadbfunc_entrypoint_7(f32 param_0, f32 param_1) {
    s32 *v1;

    v1 = func_808002F8_cadbfunc();
    if (v1 == 0) {
        return 0;
    }
    *(f32 *)v1 = param_0;
    *(f32 *)(v1 + 1) = param_1;
    return 1;
}

int func_808003EC_cadbfunc()
{
  switch (func_800A587C())
  {
    case 1 :
      return func_800A586C() + 0x14;

    case 3 :
      return func_800A586C() + 0x14;

    default :
      return 0;
  }
}

s32 cadbfunc_entrypoint_8(f32 param_0[3], f32 param_1[3]) {
    f32 *local_0 = func_808003EC_cadbfunc(param_0);

    if (!local_0) {
        return 0;
    }

    param_0[0] = local_0[0];
    param_1[0] = local_0[1];
    return 1;
}

int cadbfunc_entrypoint_9(f32 param_0, f32 param_1)
{
  s32 local_0;
  f32 *local_1 = func_808003EC_cadbfunc();
  if (!local_1)
  {
    return 0;
  }
  local_0 = 1;
  local_1[0] = param_0;
  local_1[1] = param_1;
  return local_0;
}

int func_808004E0_cadbfunc()
{
  switch (func_800A587C())
  {
    case 5 :
      return func_800A586C() + 0x18;

    case 6 :
      return func_800A586C() + 0x1C;

    default :
      break;

  }

  return 0;
}

s32 cadbfunc_entrypoint_10(s32 param_0) {
    f32 *local_0 = func_808004E0_cadbfunc(param_0);
    if (local_0 == 0) {
        return 0;
    }
    *(f32 *)param_0 = *local_0;
    return 1;
}

s32 cadbfunc_entrypoint_11(f32 param_1) {
    f32 *local_0 = func_808004E0_cadbfunc();
    if (local_0 == 0) {
        return 0;
    }
    *local_0 = param_1;
    return 1;
}

int func_808005B8_cadbfunc()
{
  switch (func_800A587C())
  {
    case 5 :
      return func_800A586C() + 0x1C;

    case 6 :
      return func_800A586C() + 0x20;

    case 8 :
      return func_800A586C() + 0x1C;

    default :
      break;

  }

  return 0;
}

s32 cadbfunc_entrypoint_12(void *param_0) {
    void *local_0;

    local_0 = func_808005B8_cadbfunc();
    if (local_0 == 0) {
        return 0;
    }
    *(f32 *)param_0 = *(f32 *)local_0;
    return 1;
}

s32 cadbfunc_entrypoint_13(f32 param_0) {
    f32 local_0;
    f32 *v1;

    v1 = (f32 *)func_808005B8_cadbfunc();
    if (v1 == 0) {
        return 0;
    }
    local_0 = param_0;
    *v1 = local_0;
    return 1;
}

int func_808006A8_cadbfunc()
{
  switch (func_800A587C())
  {
    case 5 :
      return func_800A586C() + 0x20;

    case 6 :
      return func_800A586C() + 0x24;

    case 8 :
      return func_800A586C() + 0x20;

    default :
      break;

  }
  return 0;
}

int cadbfunc_entrypoint_14(f32 param_0[3])
{
  f32 *local_0;
  local_0 = func_808006A8_cadbfunc();
  if (!local_0)
  {
    return 0;
  }
  param_0[0] = local_0[0];
  return 1;
}

int cadbfunc_entrypoint_15(f32 param_0)
{
  s32 local_0;
  f32 *local_1 = func_808006A8_cadbfunc();
  if (!local_1)
  {
    return 0;
  }
  else
  {
    local_0 = 1;
  }
  *local_1 = param_0;
  return local_0;
}

int func_80800798_cadbfunc()
{
  switch (func_800A587C())
  {
    case 5 :
      return func_800A586C() + 0x28;

    case 6 :
      return func_800A586C() + 0x30;

    case 8 :
      return func_800A586C() + 0x2C;

    default :
      break;

  }
  return 0;
}

s32 cadbfunc_entrypoint_16(void *param_0) {
    void *local_0;
    void *local_1;

    local_0 = func_80800798_cadbfunc();
    if (local_0 == 0) {
        return 0;
    }
    local_1 = local_0;
    *(s16 *)param_0 = *(s16 *)local_1;
    return 1;
}

int cadbfunc_entrypoint_17(param_0) s16 param_0;
{
  s16 *local_0;
  local_0 = func_80800798_cadbfunc();
  if (!local_0)
  {
    return 0;
  }
  else
  {
    *local_0 = param_0;
    return 1;
  }
}

int func_80800888_cadbfunc()
{
  s32 local_0;
  switch (func_800A587C())
  {
    case 3 :
      return func_800A586C() + 0x1C;

    case 6 :
      return func_800A586C() + 0x18;

    default :
      local_0 = 0;

  }

  return local_0;
}

int cadbfunc_entrypoint_18(f32 *param_0)
{
    s32 local_0;
    local_0 = func_80800888_cadbfunc();
    if (local_0 == 0) {
        return 0;
    }
    param_0[0] = *(f32 *)local_0;
    return 1;
}

int cadbfunc_entrypoint_19(f32 param_0)
{
  int new_var;
  s32 local_0;
  f32 *local_1 = func_80800888_cadbfunc();
  new_var = !local_1;
  if (new_var)
  {
    return 0;
  }
  else
  {
    local_0 = 1;
    *local_1 = param_0;
    return local_0;
  }
}

int func_80800960_cadbfunc()
{
  s32 local_0;
  if (func_800A587C() == 3)
  {
    return func_800A586C() + 0x20;
  }
  local_0 = 0;
  return local_0;
}

int cadbfunc_entrypoint_20(f32 param_0[3])
{
  f32 *local_0;
  local_0 = func_80800960_cadbfunc();
  if (!local_0)
  {
    return 0;
  }
  param_0[0] = local_0[0];
  return 1;
}

s32 cadbfunc_entrypoint_21(f32 param_0) {
    s32 *v1;

    v1 = func_80800960_cadbfunc();
    if (v1 == 0) {
        return 0;
    }
    *(f32 *)v1 = param_0;
    return 1;
}

s32 func_80800A1C_cadbfunc(void)
{
  int new_var;
  s32 out;
  out = func_800A587C();
  new_var = out == 4;
  if (new_var)
  {
    out = func_800A586C();
  }
  else
  {
    out = 0;
    return out;
  }
}

s32 cadbfunc_entrypoint_22(void *param_0) {
    void *local_0;
    void *local_1;

    local_0 = func_80800A1C_cadbfunc();
    if (local_0 == 0) {
        return 0;
    }
    local_1 = local_0;
    *(void **)param_0 = *(void **)local_1;
    return 1;
}

s32 cadbfunc_entrypoint_23(s32 param_0) {
    s32 *v1;

    v1 = func_80800A1C_cadbfunc();
    if (v1 == 0) {
        return 0;
    }
    *v1 = param_0;
    return 1;
}

int func_80800AD8_cadbfunc()
{
    switch (func_800A587C())
    {
    case 4:
        return func_800A586C() + 8;
    case 6:
        return func_800A586C() + 0x2C;
    case 7:
        return func_800A586C();
    case 8:
        return func_800A586C() + 0x28;
    default:
        return 0;
    }
}

s32 cadbfunc_entrypoint_24(void *param_0) {
    void *local_0;
    void *local_1;

    local_0 = func_80800AD8_cadbfunc();
    if (local_0 == 0) {
        return 0;
    }
    local_1 = local_0;
    *(void **)param_0 = *(void **)local_1;
    return 1;
}

int cadbfunc_entrypoint_25(s32 param_0)
{
  s32 *local_0;
  local_0 = (s32 *)func_80800AD8_cadbfunc();
  if (!local_0)
  {
    return 0;
  }
  else
  {
    *local_0 = param_0;
    return 1;
  }
}

int func_80800BE0_cadbfunc()
{
  s32 local_0;
  if (func_800A587C() == 4)
  {
    return func_800A586C() + 0xC;
  }
  local_0 = 0;
  return local_0;
}

s32 cadbfunc_entrypoint_26(void *param_0) {
    void *local_0;
    void *local_1;

    local_0 = func_80800BE0_cadbfunc();
    if (local_0 == 0) {
        return 0;
    }
    local_1 = local_0;
    *(void **)param_0 = *(void **)local_1;
    return 1;
}

s32 cadbfunc_entrypoint_27(s32 param_0) {
    s32 *v1;

    v1 = func_80800BE0_cadbfunc();
    if (v1 == 0) {
        return 0;
    }
    *v1 = param_0;
    return 1;
}

s32 func_80800C9C_cadbfunc(void) {
    s32 temp_v0;

    temp_v0 = func_800A587C();
    switch (temp_v0) {
    case 4:
        return func_800A586C() + 4;
    case 3:
        return func_800A586C() + 0x30;
    case 1:
        return func_800A586C() + 0x28;
    case 5:
        return func_800A586C() + 0x24;
    case 6:
        return func_800A586C() + 0x28;
    case 8:
        return func_800A586C() + 0x24;
    default:
        return 0;
    }
}

int cadbfunc_entrypoint_28(s32 param_0, s32 param_1)
{
  s32 local_0;
  s32 *local_1;
  local_0 = func_80800C9C_cadbfunc();
  if (!local_0)
  {
    return 0;
  }
  local_1 = local_0;
  if (param_1 != 0)
  {
    *local_1 |= param_0;
  }
  else
  {
    *local_1 &= ~param_0;
  }
  return 1;
}

s32 cadbfunc_entrypoint_29(u32 param_0, s32 *param_1)
{
    u32 *local_0;

    local_0 = func_80800C9C_cadbfunc();
    if (local_0 == NULL) {
        return 0;
    }
    if (local_0[0] & param_0) {
        *param_1 = 1;
    } else {
        *param_1 = 0;
    }
    return 1;
}

s32 cadbfunc_entrypoint_30(void *param_0) {
    void *local_0;
    void *local_1;

    local_0 = func_80800C9C_cadbfunc();
    if (local_0 == 0) {
        return 0;
    }
    local_1 = local_0;
    *(void **)param_0 = *(void **)local_1;
    return 1;
}

s32 cadbfunc_entrypoint_31(s32 param_0) {
    s32 *v1;

    v1 = func_80800C9C_cadbfunc();
    if (v1 == 0) {
        return 0;
    }
    *v1 = param_0;
    return 1;
}

int func_80800E80_cadbfunc()
{
  s32 local_0;
  if (func_800A587C() == 4)
  {
    return func_800A586C() + 0x10;
  }
  local_0 = 0;
  return local_0;
}

s32 cadbfunc_entrypoint_32(f32 *param_0){
    s32 *local_0 = func_80800E80_cadbfunc();
    if(!local_0){
        return 0;
    }
    *param_0 = *(f32*)local_0;
    return 1;
}

s32 cadbfunc_entrypoint_33(f32 param_0) {
    s32 *v1;

    v1 = func_80800E80_cadbfunc();
    if (v1 == 0) {
        return 0;
    }
    *(f32 *)v1 = param_0;
    return 1;
}

int func_80800F3C_cadbfunc()
{
  s32 local_0;
  if (func_800A587C() == 4)
  {
    return func_800A586C() + 0x14;
  }
  local_0 = 0;
  return local_0;
}

s32 cadbfunc_entrypoint_34(void *param_0) {
    void *local_0;
    void *local_1;

    local_0 = func_80800F3C_cadbfunc();
    if (local_0 == 0) {
        return 0;
    }
    local_1 = local_0;
    *(void **)param_0 = *(void **)local_1;
    return 1;
}

int cadbfunc_entrypoint_35(s32 param_0)
{
    int* ptr = func_80800F3C_cadbfunc();
    if (ptr == NULL)
    {
        return 0;
    }
    *ptr = param_0;
    return 1;
}
