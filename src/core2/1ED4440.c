#include "common.h"
void func_800EF368(f32 vec[3], f32 target_length);

extern u8 *func_800C6A7C(f32 *, f32 *, f32 *, void *);
extern void func_800EFA4C(f32 *, f32, f32, f32);
extern s32 func_800C6C94(f32 *, f32, f32 *, s32);
extern f32 func_800EEAA4(OSPiHandle *, f32 *);
extern void func_800EF934(f32 *, f32 *, f32);
extern f32 D_801357C0;
extern void func_800EFB24(f32 *, f32 *, f32 *);
extern void func_800EF410(f32 *, f32 *);
extern void func_800C7A68(s32 *, f32, s32 *);
void func_800EE780(f32 *a0, s32 a1, f32 *a2);
s32 func_800BEF00(f32 *a0, f32 *a1, f32 *a2, s32 a3);
s32 func_800EE7F8();
extern f32 func_800EEB40(void);
extern s32 func_800C6B78(f32 *, f32 *, f32, s32, s32, s32);

int func_800FAB50(s32 param_0, s32 param_1, s32 param_2, s32 param_3, f32 param_4)
{
  f32 local_0[3];
  f32 local_1[3];
  s32 local_2;
  s32 local_3;

  func_800EE7F8(local_1);
  func_800EFB24(local_0, local_1, param_0);
  func_800EF368(local_0, param_4);
  func_800EF04C(local_1, local_0);
  local_3 = func_800C6A7C(param_0, local_1, param_2, param_3);
  local_2 = local_3;
  if (local_3 == 0) {
    return 0;
  }
  func_800EF3DC(local_1, local_0);
  func_800EE7F8(param_1, local_1);
  return local_2;
}

int func_800FABF4(s32 param_0, s32 param_1, f32 *param_2, f32 *param_3, f32 param_4, f32 param_5)
{
  f32 local_0[3];
  f32 local_1[3];
  s32 local_3;
  func_800EE7F8(local_0, param_0 | 0);
  func_800EE7F8(local_1, param_1);
  local_0[1] += param_5;
  local_1[1] += param_5;
  if (!(local_3 = func_800FAB50(local_0, local_1, param_2, param_3, param_4)))
  {
    return 0;
  }
  local_1[1] -= param_5;
  func_800EE7F8(param_1, local_1);
  return local_3;
}

void func_800FACA0(f32 *param_0, f32 param_1, void *param_2) {
    f32 local_0[3];
    f32 local_1[3];
    f32 local_2[3];
    u8 *local_3;
    func_800EE7F8(local_1, param_0);
    func_800EE7F8(local_2, param_0);
    local_1[1] += 100.0f;
    local_2[1] -= 500.0f;
    local_3 = func_800C6A7C(local_1, local_2, local_0, param_2);
    if (local_3) {
        if (local_0[1] < 0.0f && !(*(u32 *)(local_3 + 8) & 0x10000)) return;
        if (param_0[1] < local_2[1]) param_0[1] = local_2[1];
    }
}

void func_800FAD68(f32 *param_0, f32 param_1, f32 param_2, s32 param_3, s32 param_4) {
    f32 local_0[3];
    f32 local_1[3];
    f32 local_2;
    func_800EFA4C(local_1, param_0[0], param_0[1] + param_2, param_0[2]);
    if (func_800C6C94(local_1, param_1, local_0, param_4)) {
        local_2 = 1.3f;
        param_0[0] += local_2 * local_0[0];
        param_0[1] += local_2 * local_0[1];
        param_0[2] += local_2 * local_0[2];
        if (param_3) func_800FACA0(param_0, param_2 + param_1, param_4);
    }
}

void func_800FAE44(f32 *param_0, f32 *param_1, f32 param_2, f32 param_3, s32 param_4, s32 param_5) {
    f32 local_0[3];
    f32 local_1[3];
    f32 local_2[3];
    s32 local_3;
    s32 local_4;
    func_800EFA4C(local_2, param_0[0], param_0[1] + param_3, param_0[2]);
    func_800EE7F8(param_1, param_0);
    if (func_800C6C94(local_2, param_2, local_1, param_5)) {
        param_1[0] = param_0[0] + local_1[0] * 2;
        param_1[1] = param_0[1] + local_1[1] * 2;
        param_1[2] = param_0[2] + local_1[2] * 2;
        local_0[0] = param_0[0] + local_1[0] * 2;
        local_0[1] = param_0[1] + local_1[1] * 2;
        local_0[2] = param_0[2] + local_1[2] * 2;
        func_800EE7F8(param_0, local_0);
        if (param_4) func_800FACA0(param_0, param_3 + param_2, param_5);
    }
}

void func_800FAF78(f32 *param_0, f32 *param_1, u32 param_2, s32 param_3, OSPiHandle *param_4)
{
  f32 local_0[3];
  f32 local_1[3];
  f32 local_2[3];
  f32 local_3;
  func_800EFB24(local_0, (s32)param_1, (u32)param_0);
  func_800EFB24(local_1, param_3, param_2);
  func_800EFB24(local_2, (s32)local_0, (u32)local_1);
  local_3 = func_800EEAA4(param_4, local_2);
  local_3 = -local_3;
  if (local_3 < 5.0f)
    {
        local_3 = 5.0f;
    }
  param_1[0] += local_3 * ((f32 *)param_4)[0];
  param_1[1] += local_3 * ((f32 *)param_4)[1];
  param_1[2] += local_3 * ((f32 *)param_4)[2];
}

void func_800FB040(f32 *param_0, f32 *param_1, f32 *param_2, f32 *param_3, f32 *param_4, s32 param_5) {
    f32 local_0[3];
    f32 local_1[3];
    f32 local_2[3];
    f32 local_3[3];
    f32 local_4[3];
    f32 local_5[3];
    f32 local_6;
    f32 local_7;
    func_800EFB24(local_0, param_1, param_0);
    func_800EFB24(local_1, param_3, param_2);
    func_800EFB24(local_2, local_0, local_1);
    func_800EF410(local_4, local_2);
    func_800EF934(local_5, local_4, 90.0f);
    local_7 = func_800EEAA4(param_4, local_4);
    if (param_5) D_801357C0 = func_800EEAA4(param_4, local_5);
    func_800EF934(local_3, param_4, (D_801357C0 < 0.0f ? -1.0f : 1.0f) * local_7 * 45.0f);
    local_6 = -func_800EEAA4(local_3, local_2);
    if (local_6 < 5.0f) local_6 = 5.0f;
    param_1[0] += local_6 * local_3[0];
    param_1[1] += local_6 * local_3[1];
    param_1[2] += local_6 * local_3[2];
}

int func_800FB1B0(f32 param_0[3], f32 param_1[3], f32 param_2[3])
{
  f32 local_0[3];
  f32 local_1[3];
  func_800EE7F8(local_1, param_1);
  return func_800C6A7C(param_0, local_1, local_0, param_2);
}

f32 func_800FB1EC(s32 *param_0, f32 param_1, s32 param_2, s32 param_3) {
  s8 _sfpad[8];
    s32 local_0;

    func_800C7A68(param_0, param_1, &local_0);
    if (func_800FB1B0(param_2, &local_0, param_3) == 0) {
        return param_1;
    }
    func_800C7A68(param_0, 1.0f, &local_0);
    if (func_800FB1B0(param_2, &local_0, param_3) == 0) {
        return 1.0f;
    }
    func_800C7A68(param_0, 0.0f, &local_0);
    if (func_800FB1B0(param_2, &local_0, param_3) == 0) {
        return 0.0f;
    }
    return param_1;
}

s32 func_800FB2AC(s32 param_0, f32 param_1)
{
    f32 local_3[3];
    f32 local_2[3];
    f32 local_1[3];
    f32 local_0[3];
    s32 local_5;
    s32 local_4;

    func_800EFA4C(local_0, 0.0f, param_1, 0.0f);
    func_800EE780(local_1, param_0, local_0);
    func_800EFB24(local_2, param_0, local_0);
    local_4 = func_800BEF00(local_1, local_2, local_3, 0x1F00);
    local_5 = local_4;
    if (local_4 != 0)
    {
        local_4 = func_800EE7F8(param_0, local_2);
    }
    return local_5;
}

int func_800FB338(f32 param_0[3], f32 param_1[3], f32 param_2[3], f32 param_3[3])
{
  s32 local_0;
  local_0 = 0;
  param_3[0] = param_0[1];
  return local_0;
}

s32 func_800FB350(u8 *param_0, s32 *param_1, f32 *param_2)
{
    s32 local_1;
    f32 local_0[3];

    *param_1 = 0;
    *param_2 = *(f32 *)(param_0 + 4);
    func_800EE7F8(local_0, param_0);
    local_1 = func_800FB2AC(local_0, 20.0f);
    if (local_1 == 0)
    {
        return 0;
    }
    return func_800FB338(local_0, local_1, param_1, param_2);
}

s32 func_800FB3C0(s32 param_0, s32 param_1, float param_2, s32 param_3, s32 param_4, s32 param_5) {
    float local_0 = func_800EEB40();
    if (param_2 * param_2 < local_0) {
        return 0;
    }
    return func_800C6B78(param_0, param_1, param_2, param_3, param_4, param_5);
}

s32 func_800FB434(f32 *param_0, f32 *param_1, f32 param_2, f32 param_3, s32 param_4, s32 param_5, s32 param_6)
{
    s32 local_0;
    f32 local_1[3];
    f32 local_2[3];
    func_800EFA4C(local_1, param_0[0], param_0[1] + param_2, param_0[2]);
    func_800EFA4C(local_2, param_1[0], param_1[1] + param_2, param_1[2]);
    local_0 = func_800C6B78(local_1, local_2, param_3, param_4, param_5, param_6);
    if (local_0) func_800EFA4C(param_1, local_2[0], local_2[1] - param_2, local_2[2]);
    return local_0;
}

void func_800FB508(u8 *param_0, u8 *param_1) {
    *(u16 *)(param_0 + 0) = *(u16 *)(param_1 + 0);
    *(u16 *)(param_0 + 2) = *(u16 *)(param_1 + 2);
    *(u16 *)(param_0 + 4) = *(u16 *)(param_1 + 4);
    *(s32 *)(param_0 + 8) = *(s32 *)(param_1 + 8);
    *(s16 *)(param_0 + 6) = *(s16 *)(param_1 + 6);
}
