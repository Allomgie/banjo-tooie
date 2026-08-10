#include "common.h"

s32 func_800B26F0(s32 param_0) {
    s32 local_0 = *(s32 *)(param_0 + 0x28);
    if (local_0 == 0) {
        return 0;
    }
    return param_0 + local_0;
}

func_800B270C(s16 *param_0) {
    return param_0[5];
}

s32 func_800B2714(s32 param_0)
{
  s32 new_var;
  s32 new_var2;
  new_var2 = (*((s32 *) (param_0 + 0xc))) & 0xFFFFFFFFFFFFFFFF;
  new_var2 = new_var2;
  new_var = new_var2;
  return param_0 + new_var;
}

s32 func_800B2720(s32 param_0) {
    s32 temp;
    if (param_0 == 0) {
        return 0;
    }
    temp = *(s32 *)(param_0 + 0x1C);
    if (temp == 0) {
        return 0;
    }
    return param_0 + temp;
}

func_800B274C(param_0) {
    s32 local_0 = *(s32*)(param_0 + 0x24);
    if (local_0 == 0) {
        return 0;
    }
    return param_0 + local_0;
}

func_800B2768(param_0) {
    s32 local_0 = *(s32*)(param_0 + 0x40);
    if (local_0 == 0) {
        return 0;
    }
    return param_0 + local_0;
}

func_800B2784(param_0) {
    s32 local_0 = *(s32*)(param_0 + 0x3c);
    if (local_0 == 0) {
        return 0;
    }
    return param_0 + local_0;
}

func_800B27A0(param_0) {
    s32 local_0 = *(s32*)(param_0 + 0x38);
    if (local_0 == 0) {
        return 0;
    }
    return param_0 + local_0;
}

func_800B27BC(param_0) {
    s32 local_0 = *(s32*)(param_0 + 0x30);
    if (local_0 == 0) {
        return 0;
    }
    return param_0 + local_0;
}

f32 func_800B27D8(f32 *arg0)
{
    return arg0[18];
}

func_800B27E0(param_0) {
    s32 local_0 = *(s32*)(param_0 + 0x18);
    if (local_0 == 0) {
        return 0;
    }
    return param_0 + local_0;
}

int func_800B27FC(s32 param_0)
{
  s16 *new_var;
  new_var = (s16 *) (((int) param_0) + 0x8);
  return (*new_var) + ((0, param_0));
}

func_800B2808(s32 param_0) {
    s32 local_0;
    local_0 = *(s32*)(param_0 + 0x2C);
    if (local_0 == 0) {
        return 0;
    }
    return param_0 + local_0;
}

s32 func_800B2824(Actor *this){
    if(this->unk14 == 0)
        return 0;
    return (Actor *)((s32)this + this->unk14);
}

s32 func_800B2840(s32 param_0)
{
  s32 new_var;
  new_var = param_0;
  return (new_var + (*((volatile s32 *) (new_var + 0x10)))) ^ ((0, 0));
}

s32 func_800B284C(s32 *param_0)
{
  s32 v = param_0[8];
  return v == 0 ? 0 : (s32)param_0 + v;
}

func_800B2868(s32 param_0) {
    s32 local_0;
    local_0 = *(s32 *)(param_0 + 0x34);
    if (local_0 == 0) {
        return 0;
    }
    return param_0 + local_0;
}
