#include "core2/1EB93C0.h"

void func_800D9600(s32, s32);
s32 func_800D97E8(void *param_0, void *param_1);
void func_800D9AD4(s32 param_0, void *param_1, void *param_2, f32 param_3);

void func_800DFAD0(u8 *param_0) {
    u32 temp_v1;
    u32 var_v0;

    var_v0 = (*(u32 *)((s8 *)(param_0) + (0)));
    temp_v1 = ((*(s32 *)((s8 *)(param_0) + (4))) * 0x28) + var_v0;
    if (var_v0 < temp_v1) {
        do {
            var_v0 += 0x28;
            *(f32 *)(var_v0 - 0x28) = *(f32 *)(var_v0 - 0x24) = *(f32 *)(var_v0 - 0x20) = 0.0f;
            *(f32 *)(var_v0 - 0x1C) = 1.0f;
            *(f32 *)(var_v0 - 0x18) = *(f32 *)(var_v0 - 0x14) = *(f32 *)(var_v0 - 0x10) = (f32)1;
            *(f32 *)(var_v0 - 0xC) = *(f32 *)(var_v0 - 0x8) = *(f32 *)(var_v0 - 0x4) = 0.0f;
        } while (var_v0 < temp_v1);
    }
}

void func_800DFB40(s32 param_0, s32 param_1, s32 param_2)
{
    s32 *local_0;
    local_0 = (s32 *)param_0;
    func_800D9600(param_2, *local_0 + param_1 * 40);
}

void func_800DFB7C(s32 *param_0, unsigned int param_1, unsigned long param_2, s32 param_3, s32 param_4)
{
  volatile s32 local_1;
  s32 local_0;
  s32 new_var2;
  s32 new_var;
  new_var = *param_0;
  local_0 = new_var + ((10 * param_1) * 4);
  func_800D9600(param_2, local_0);
  new_var = param_4;
  new_var2 = local_0;
  func_800EE7F8(param_3, new_var2 + 0x10);
  func_800EE7F8(new_var, local_0 + 0x1C);
}

void func_800DFBE0(s32 *param_0, s32 param_1, s32 param_2) {
    func_800EE7F8(param_2, *param_0 + (param_1 * 0x28) + 0x10, param_2, param_0);
}

void func_800DFC20(s32 *param_0, s32 param_1, s32 param_2) {
    func_800EE7F8(param_2, *param_0 + (param_1 * 0x28) + 0x1C, param_2, param_0);
}

void func_800DFC60(void* arg0) 
{
    heap_free(arg0);
}
int func_800DFC80()
{
  s32 *local_0;
  local_0 = heap_alloc(0x1110);
  local_0[0] = &local_0[2];
  local_0[1] = 0x6D;
  func_800DFAD0(local_0);
  return local_0;
}

int func_800DFCC0(param_0) s16 param_0;
{
  func_8001B754(param_0);
}

int func_800DFCE8(param_0) s16 param_0;
{
  func_8001B798(param_0);
}

s16 func_800DFD10(void) {
    s16 local_1;
    s16 local_0;
    u8 *local_2;

    local_1 = func_8001B668(1, 0x1110);
    local_0 = local_1;
    local_2 = func_8001B798(local_1);
    (*(s32 *)((s8 *)(local_2) + (0))) = (s32) (local_2 + 8);
    (*(s32 *)((s8 *)(local_2) + (4))) = 0x6D;
    func_800DFAD0(local_2);
    return local_1;
}

void func_800DFD64(void *param_0, void **param_1, void **param_2, f32 param_3) {
    u32 var_s0;
    u8 *var_s1, *var_s2;
    s32 temp_s3;

    var_s0 = *((u32 *) param_0);
    temp_s3 = (((s32) *((u32 *) param_0 + 1)) * 40) + var_s0;
    var_s1 = *((u8 **) param_1);
    var_s2 = *((u8 **) param_2);

    if (var_s0 < temp_s3) {
        do {
            if (func_800D97E8(var_s1, var_s2)) {
                func_800D9600(var_s0, var_s1);
            } else {
                func_800D9AD4(var_s0, var_s1, var_s2, param_3);
            }
            var_s0 += 0x28;
            *(f32 *)(var_s0 - 0x18) = *(f32 *)(var_s1 + 0x10) + (*(f32 *)(var_s2 + 0x10) - *(f32 *)(var_s1 + 0x10)) * param_3;
            var_s1 += 0x28;
            var_s2 += 0x28;
            *(f32 *)(var_s0 - 0x14) = *(f32 *)(var_s1 - 0x14) + (*(f32 *)(var_s2 - 0x14) - *(f32 *)(var_s1 - 0x14)) * param_3;
            *(f32 *)(var_s0 - 0x10) = *(f32 *)(var_s1 - 0x10) + (*(f32 *)(var_s2 - 0x10) - *(f32 *)(var_s1 - 0x10)) * param_3;
            *(f32 *)(var_s0 - 0xC) = *(f32 *)(var_s1 - 0xC) + (*(f32 *)(var_s2 - 0xC) - *(f32 *)(var_s1 - 0xC)) * param_3;
            *(f32 *)(var_s0 - 8) = *(f32 *)(var_s1 - 8) + (*(f32 *)(var_s2 - 8) - *(f32 *)(var_s1 - 8)) * param_3;
            *(f32 *)(var_s0 - 4) = *(f32 *)(var_s1 - 4) + (*(f32 *)(var_s2 - 4) - *(f32 *)(var_s1 - 4)) * param_3;
        } while (var_s0 < temp_s3);
    }
}

void func_800DFEA8(u8 *param_0, s32 *param_1)
{
  int new_var;
  s32 var_s1;
  u32 temp_s2;
  u32 var_s0;
  var_s0 = *((u32 *) param_0);
  var_s1 = *param_1;
  temp_s2 = ((*((u32 *) (param_0 + 4))) * 0x28) + var_s0;
  if (var_s0 < temp_s2)
  {
    new_var = 0x10;
    do
    {
      func_800D9600(var_s1, var_s0);
      func_800EE7F8(var_s1 + new_var, var_s0 + new_var);
      func_800EE7F8(var_s1 + 0x1C, var_s0 + 0x1C);
      var_s1 += 0x28;
      var_s0 += 0x28;
    }
    while (var_s0 < temp_s2);
  }
}

void func_800DFF2C(s32 param_0, s32 param_1, f32 param_2[4]) {
    func_800D9600(*(s32 *)param_0 + param_1 * 40, param_2);
}

void func_800DFF64(s32 *param_0, s32 param_1, s32 param_2) {
    func_800EE7F8(param_0[0] + (param_1 * 0x28) + 0x10, param_2);
}

void func_800DFFA0(s32 *param_0, unsigned int param_1, s32 param_2)
{
  unsigned int new_var;
  new_var = param_1;
  func_800EE7F8(((*param_0) + (new_var * 0x28)) + 0x1C, param_2);
}

int func_800DFFDC(s32 param_0, s32 param_1, s32 param_2)
{
  s32 pad;
  f32 local_0[3];
  func_800D93A0(local_0, param_2 | 0);
  func_800DFF2C(param_0, param_1, local_0);
}

int func_800E0018()
{
  s32 *local_0;
  local_0 = defrag();
  local_0[0] = local_0 + 2;
}

func_800E0040(param_0){
    *(s32*)param_0 = (s32)(param_0 + 8);
}
