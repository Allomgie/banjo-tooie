#include "common.h"

extern void *D_80800190_chdummyjigsaw;
extern f32 func_800DC0C0(void);
extern f32 func_800DC178(f32, f32);
extern f32 func_800D8FF8(void);
extern f32 func_800136E4(f32);
extern void func_800EF214(f32 *, f32, f32, f32);

void func_80800000_chdummyjigsaw(Actor *param_0)
{
    f32 local_0[3];
    s32 local_1;

    if (param_0->unk7C_12) {
        for (local_1 = 0; local_1 < 4; local_1++) {
            if (func_800DC0C0() < 0.015f) {
                func_80103DFC(param_0, local_0);
                func_800EF214(local_0, func_800DC178(0.0f, 360.0f),
                    func_800DC178(0.0f, 360.0f), 40.0f);
                _fxtwinkle_entrypoint_2(local_0, 0x9E2);
            }
        }
    }
    param_0->rotation[1] += func_800D8FF8() * 230.0f;
    param_0->rotation[1] = func_800136E4(param_0->rotation[1]);
}

int func_80800128_chdummyjigsaw(Actor *param_0, s32 param_1, s32 param_2)
{
  if ((param_1 == 0x3E) && param_0->unk64_20) {
    func_800FFA88(param_0->unk0);
    return 1;
  }
  return 0;
}

int chdummyjigsaw_entrypoint_0()
{
  return &D_80800190_chdummyjigsaw;
}
