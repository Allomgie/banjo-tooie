#include "core2/1E75710.h"

extern f32 func_800D8FF8(void);
extern f32 func_80013728(f32);
extern f32 func_800F0D50(f32, f32, f32);
extern f32 func_800F212C(f32, f32);
extern f32 func_800136E4(f32);
typedef struct { f32 local_0; f32 local_1; } Struct8009BF04Local;
typedef struct { u8 pad_0[0xDC]; Struct8009BF04Local *local_0; } Struct8009BF04;
void func_8009C000(PlayerState *param_0);

s32 func_8009BE20() 
{
    return 0x10;
}

void func_8009BE28(u8 *param_0, f32 param_1, f32 param_2)
{
  f32 var_f20;
  f32 var_f0;
  f32 sp2C;
  f32 sp28;
  u8 *temp_s0;
  f32 new_var;
  int new_var2;
  f32 temp_f0;
  f32 temp_f2;
  sp28 = func_800D8FF8();
  temp_s0 = *((u8 **) (((s8 *) param_0) + 0xDC));
  new_var2 = 0;
  temp_f0 = func_80013728((*((f32 *) (((s8 *) temp_s0) + 4))) - (*((f32 *) (((s8 *) temp_s0) + new_var2))));
  sp2C = temp_f0;
  temp_f2 = (var_f20 = temp_f0 * param_2);
  var_f20 = temp_f2;
  if (var_f20 != 0.0f)
  {
    if (1)
    {
      if (var_f20 < 0.0f)
      {
 var_f0 = func_800F0D50(var_f20, -param_1, -3.0f); } else { var_f0 = func_800F0D50(var_f20, 3.0f * 1.0f, param_1); } { } } var_f20 = var_f0; } temp_f2 = temp_f2; new_var = func_800F212C(var_f20 * sp28, sp2C);
  *((f32 *) temp_s0) = (*((f32 *) temp_s0)) + new_var;
  *((f32 *) temp_s0) = func_800136E4(*((f32 *) temp_s0));
  if (var_f20)
  {
  }
}

void func_8009BF04(Struct8009BF04 *param_0)
{
    param_0->local_0->local_0 = 0.0f;
    param_0->local_0->local_1 = 0.0f;
    func_8009C000(param_0);
}

void func_8009BF34(u8 *param_0) {
    u8 **local_0;
    local_0 = *(u8 ***)(param_0 + 0xDC);
    func_8009BE28(param_0, *(f32 *)(local_0 + 2), *(f32 *)(local_0 + 3));
}

void func_8009BF5C(PlayerState *param_0, f32 param_1)
{
    *(f32 *)(*(s32 *)((char *)param_0 + 0xDC) + 0x4) = func_800136E4(param_1);
}

void func_8009BF8C(PlayerState *param_0, f32 param_1)
{
    *(f32 *)(*(s32 *)((char *)param_0 + 0xDC) + 0x0) = func_800136E4(param_1);
}

void func_8009BFBC(void *param_0)
{
  f32 *p = *(f32 **)((char *)param_0 + 0xDC);
  p[0] = p[1];
}

f32 func_8009BFCC(PlayerState *param_0)
{

    return *(f32 *)((char *)(*(struct ba_unknown_c_s **)((u8 *)param_0 + 0xDC)) + 0x0);
}

f32 func_8009BFD8(PlayerState *param_0){

    return *(f32 *)((char *)(*(struct ba_unknown_c_s **)((char *)param_0 + 0xDC)) + 0x4);
}

void func_8009BFE4(PlayerState *param_0, f32 param_1, f32 param_2) {
    (*(f32 *)((s8 *)((*(u8 **)((s8 *)(param_0) + (0xDC)))) + (8))) = param_1;
    (*(f32 *)((s8 *)((*(u8 **)((s8 *)(param_0) + (0xDC)))) + (0xC))) = param_2;
}

void func_8009C000(PlayerState *param_0)
{
  float new_var;
  new_var = 500.0f;
  func_8009BFE4(param_0, new_var, 0.8f);
}
