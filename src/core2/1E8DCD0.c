#include "common.h"

extern u8 D_80127F03;
extern u8 D_80127F00[];
extern u16 D_8011A5B0[];
extern s32 func_800B56D0(s32);
extern void func_800BA3FC(s32, s32);
extern void func_800BA594(s32, f32, f32);
extern void func_800BA75C(s32, f32 *);
extern void func_800EFA20(f32 *, f32 *, f32);
extern void func_800BA930();
extern void func_800BAB80(s32, s32 *);
extern void func_800BA5A8(s32, s32);
extern void func_800BA8F8(s32, f32, f32);
extern void func_800BA7C4(s32, f32, f32);
extern void func_800BA7FC(s32, f32, f32);
extern void func_800BA5BC(s32, f32, f32);
extern void func_800BA5B0(s32, s32, s32);
extern void func_800BA22C(s32, s32);

void func_800B43E0()
{
  u8 *local_1;
  u8 *local_0 = ((u8 *) D_80127F00);
 local_0++; local_0--; do { *(local_0++) = func_800B5758(0x20 ^ 0);
  }
  while (local_0 != (&D_80127F03));
}

void func_800B4428()
{
  u8 *local_0;
  u8 *local_1;
 local_1 = &D_80127F03; local_0 = D_80127F00;
  do
  {
    func_800B58D4(*local_0);
    local_0 += 1;
  }
  while (local_0 != local_1);
}

void func_800B4470(f32 *param_0, f32 *param_1, s32 *param_2, s32 param_3, f32 param_4, f32 param_5, s32 param_6, s32 param_7, s32 param_8) {
    f32 local_0;
    f32 local_1;
    s32 local_4;
    f32 local_2[3];
    s32 local_3 = 0x228;
    u16 *local_5;
    local_4 = func_800B56D0(D_80127F00[param_8]);
    local_5 = &D_8011A5B0[param_8];
    func_800BA3FC(local_4, *local_5);
    func_800BA594(local_4, 0.075f, 0.4f);
    func_800BA75C(local_4, param_0);
    if (param_1) func_800EFA20(local_2, param_1, 30.0f);
    else local_2[0] = local_2[1] = local_2[2] = 0.0f;
    if (param_5 != 0.0f) local_2[1] += param_5 / param_4;
    func_800BA930(local_4, (s16)local_2[0], (s16)local_2[1], (s16)local_2[2], (s16)local_2[0], (s16)local_2[1], (s16)local_2[2]);
    if (param_2) func_800BAB80(local_4, param_2);
    if (!param_3) local_3 = 0x238;
    func_800BA5A8(local_4, local_3);
    func_800BA8F8(local_4, param_4, param_4);
    func_800BA7C4(local_4, param_6 / 175.0f, param_6 / 175.0f);
    func_800BA7FC(local_4, (param_6 + param_7) / 175.0f, (param_6 + param_7) / 175.0f);
    if (local_5 == D_8011A5B0) func_800BA5BC(local_4, 15.0f / param_4, 15.0f / param_4);
    else func_800BA5B0(local_4, 0, 12);
    func_800BA22C(local_4, 1);
}
