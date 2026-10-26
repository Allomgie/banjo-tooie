#include "common.h"

extern f32 _ncpod_entrypoint_30(s32);

s32 capod_entrypoint_0(s32 param_0, s32 param_1, s32 param_2) {
    s32 local_1;

    local_1 = func_80110024(func_8008FFE8());
    if (local_1 != 0) {
        return _ncpod_entrypoint_6(func_8008FFE8(), local_1, param_0, param_1, param_2);
    }
    return -1;
}

s32 capod_entrypoint_1(s32 param_0, s32 param_1) {
    s32 local_0;
    s32 local_1;

    local_0 = func_8008FFE8();
    local_1 = func_80110024(local_0);
    if (local_1) {
        _ncpod_entrypoint_8(local_1, param_0, param_1);
    }
}

int capod_entrypoint_2(s32 param_0, s32 param_1, s32 param_2)
{
  s32 local_0;
  local_0 = func_8008FFE8();
  if (local_0 != 0)
  {
    return _ncpod_entrypoint_16(local_0 | 0, param_0, param_1, param_2);
  }
  return 0;
}

int capod_entrypoint_3(s32 param_0)
{
  s32 local_0;
  local_0 = func_8008FFE8();
  if (local_0 != 0)
  {
    return _ncpod_entrypoint_17(local_0 | 0, param_0);
  }
  else
  {
    return 0;
  }
}

s32 capod_entrypoint_4(void){
    void *v0 = func_8008FFE8();
    if(v0){
        return _ncpod_entrypoint_18(v0);
    }
    return -1;
}

void capod_entrypoint_5(Actor *this)
{
    s32 local_0;

    local_0 = func_80110024(func_8008FFE8());
    if (local_0 != 0) {
        _ncpod_entrypoint_19(local_0, this);
    }
}

int capod_entrypoint_6(s32 param_0, s32 param_1, s32 param_2)
{
  s32 local_0;
  local_0 = func_8008FFE8();
  if (local_0 != 0)
  {
    return _ncpod_entrypoint_20(local_0 | 0, param_0, param_1, param_2);
  }
  else
  {
    return 0;
  }
}

int capod_entrypoint_7(s32 param_0, s32 param_1)
{
  s32 local_0;
  local_0 = func_8008FFE8();
  if (local_0 != 0)
  {
    _ncpod_entrypoint_21(local_0 | 0, param_0, param_1);
  }
}

void capod_entrypoint_8(s32 param_0) {
    s32 local_0;

    local_0 = func_80110024(func_8008FFE8());
    if (local_0 != 0) {
        _ncpod_entrypoint_12(local_0, param_0);
    }
}

s32 capod_entrypoint_9(s32 param_0, s32 param_1) {
    s32 local_0;
    s32 local_1;

    local_0 = func_8008FFE8();
    local_1 = func_80110024(local_0);
    if (local_1) {
        _ncpod_entrypoint_22(local_1, param_0, param_1);
    }
}

s32 capod_entrypoint_10(s32 param_0, s32 param_1) {
    s32 local_0;
    s32 local_1;

    local_0 = func_8008FFE8();
    local_1 = func_80110024(local_0);
    if (local_1) {
        _ncpod_entrypoint_23(local_1, param_0, param_1);
    }
}

s32 capod_entrypoint_11(s32 param_0, s32 param_1) {
    s32 local_0;
    s32 local_1;

    local_0 = func_8008FFE8();
    local_1 = func_80110024(local_0);
    if (local_1) {
        _ncpod_entrypoint_24(local_1, param_0, param_1);
    }
}

void capod_entrypoint_12(s32 param_0) {
    s32 local_0;

    local_0 = func_80110024(func_8008FFE8());
    if (local_0 != 0) {
        _ncpod_entrypoint_25(local_0, param_0);
    }
}

s32 capod_entrypoint_13(s32 param_0, s32 param_1, s32 param_2, s32 param_3) {
    s32 local_0;

    local_0 = func_8008FFE8();
    if ((local_0 != 0) && (_ncpod_entrypoint_26(local_0, param_0, param_1, param_2, param_3) != 0)) {
        return 1;
    }
    return 0;
}

int capod_entrypoint_14()
{
  s32 local_0;
  if ((local_0 = func_8008FFE8()) != 0)
  {
    _ncpod_entrypoint_27(local_0 | 0, 0);
  }
  else
  {
    return 0;
  }
}

int capod_entrypoint_15()
{
  int local_0;
  if ((local_0 = func_8008FFE8()) != 0)
  {
    _ncpod_entrypoint_27(local_0 | 0, 1);
  }
  else
  {
    return 0;
  }
}

s32 capod_entrypoint_16(f32 param_0)
{
  s32 local_0;
  local_0 = func_8008FFE8();
  if (local_0 != 0)
  {
    return _ncpod_entrypoint_28(local_0, *(s32 *)&param_0);
  }
  return 0;
}

s32 capod_entrypoint_17(f32 param_0)
{
  s32 local_0;
  local_0 = func_8008FFE8();
  if (local_0 != 0)
  {
    return _ncpod_entrypoint_29(local_0, *(s32 *)&param_0);
  }
  return 0;
}

f32 capod_entrypoint_18()
{
  s32 v;
  v = func_8008FFE8();
  if (v)
  {
    return _ncpod_entrypoint_30(v);
  }
  return 0.0f;
}

int capod_entrypoint_19(s32 param_0)
{
  s32 local_0;
  local_0 = func_8008FFE8();
  if (local_0 != 0)
  {
    _ncpod_entrypoint_31(local_0 | 0, param_0);
  }
}

int capod_entrypoint_20(s32 param_0, s32 param_1, s32 param_2)
{
  s32 local_0;
  local_0 = func_8008FFE8();
  if (local_0 != 0)
  {
    return _ncpod_entrypoint_32(local_0 | 0, param_0, param_1, param_2);
  }
  else
  {
    return 0;
  }
}

s32 capod_entrypoint_21(s32 param_0, s32 param_1, s32 param_2, s32 param_3) {
    s32 local_0;

    local_0 = func_8008FFE8();
    if ((local_0 != 0) && (_ncpod_entrypoint_33(local_0, param_0, param_1, param_2, param_3) != 0)) {
        return 1;
    }
    return 0;
}

int capod_entrypoint_22()
{
  s32 local_0;
  local_0 = func_8008FFE8();
  if (local_0 != 0)
  {
    _ncpod_entrypoint_27(local_0 | 0, 0);
  }
  else
  {
    return 0;
  }
}
