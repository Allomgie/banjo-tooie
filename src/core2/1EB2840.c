#include "core2/1EB2840.h"

extern s32 func_800F1574(f32 *param_0, f32 param_1);

extern s32 D_8012C764;
extern f32 D_8012C760;

void func_800D8F50(f32 param_0)
{
  if (param_0 < 0.050000004f)
  {
    D_8012C760 = param_0;
  }
  else
  {
    D_8012C760 = 0.050000004f;
  }
}

void func_800D8F84()
{
  D_8012C760 = 0.01f;
  D_8012C764 = 0;
}

void func_800D8FA0(s32 param_0)
{
  func_800D8F50(((f32) (D_8012C764 = func_800F0D90(param_0, 1, 0xF))) * 0.016666668f);
}

u32 func_800D8FEC()
{
	return D_8012C764;
}
//Get Gamespeed
f32 func_800D8FF8()
{
	return D_8012C760;
}

f32 func_800D9004(void) {
    return (f32)(s32)D_8012C764 * 0.016666668f;
}

f32 func_800D902C(void)
{
    return func_800D8FF8() * 30.0f;
}

func_800D9058(f32 param_0){
    f32 local_0;
    s32 local_1;

    local_0 = param_0 * 30.0f;
    local_1 = local_0;
    return local_1;
}

u8 func_800D9078(f32 *param_0)
{
  f32 local_0;
  local_0 = func_800D8FF8();
  func_800F1574((s32)param_0, local_0);
}

s32 func_800D90A4(f32 *param_0)
{
    if (*param_0 > 0.0f) {
        return func_800F1574(param_0, func_800D8FF8());
    }
    *param_0 = 0.0f;
    return 1;
}

int func_800D90F8(f32 *param_0, f32 param_1)
{
    *param_0 -= func_800D8FF8();
    if (*param_0 < param_1) {
        *param_0 = param_1;
        return 1;
    }
    return 0;
}

int func_800D9154(f32 *param_0, f32 param_1)
{
  *param_0 -= func_800D8FF8();
  if (*param_0 < 0.0f)
  {
    *param_0 += param_1;
    return 1;
  }
  return 0;
}

f32 func_800D91B8(param_0) f32 * param_0; {
    *param_0 += func_800D8FF8();
    return *param_0;
}

s32 func_800D91EC(f32 *param_0, f32 param_1) {
    if (param_1 < func_800D91B8()) {
        *param_0 = param_1;
        return 1;
    }
    return 0;
}
