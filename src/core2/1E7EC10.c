#include "common.h"

extern u8 D_801255C0[];
extern f32 D_801270A0[];
extern f32 D_801270B0[];
extern f32 D_801270C0[];
extern f32 D_801270D0[];
extern f32 D_801270E0[];
extern void func_800EFA4C(f32 *a0, f32 a1, f32 a2, f32 a3);
extern void func_800EF8BC(f32 *a0, f32 *a1, f32 a2);

void func_800A5320(void)
{
    f32 local_0[3];
    f32 local_2[3];
    f32 local_1[3];

    func_800EFA4C(local_0, 0.0f, -1.0f, 0.0f);
    func_800EF8BC(local_1, local_0, 68.0f);
    func_800EFA4C(local_2, *(f32 *)D_801255C0 * local_1[1], 0.0f, local_1[2]);

    D_801270E0[0] = local_1[0];
    D_801270E0[1] = local_1[1];
    D_801270E0[2] = local_1[2];
    D_801270A0[0] = local_2[0] + local_1[0];
    D_801270A0[1] = local_2[1] + local_1[1];
    D_801270A0[2] = local_1[2];
    D_801270B0[0] = local_2[0] - local_1[0];
    D_801270B0[1] = local_2[1] - local_1[1];
    D_801270B0[2] = local_1[2];
    D_801270C0[0] = -local_2[0] - local_1[0];
    D_801270C0[1] = -local_2[1] - local_1[1];
    D_801270C0[2] = local_1[2];
    D_801270D0[0] = -local_2[0] + local_1[0];
    D_801270D0[1] = -local_2[1] + local_1[1];
    D_801270D0[2] = local_1[2];
}

void func_800A5430(s32 param_0[2], volatile s32 param_1, f32 param_2, unsigned int param_3)
{
  extern void func_800EF4E4(void *, s32, s32, f32, f32, f32);
  extern void func_800EE780(s32, void *, s32);
  s8 _sfpad[12];
  s32 *sp_0x30 = param_0;
  func_800EF4E4(_sfpad, sp_0x30[0], sp_0x30[1], 0.0f, 0.0f, -param_2);
  func_800EE780(param_3, sp_0x30 = (s32 *) _sfpad, param_1);
}

int func_800A5490()
{
  s32 local_0;
  local_0 = func_8008FFE8();
  func_8010FFD8(local_0 | 0);
}
