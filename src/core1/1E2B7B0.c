#include "common.h"
#include "core2/1EC8070.h"

extern void func_800F2984(f32 param_0[4][4], f32 *param_1, f32 param_2[3], f32 param_3[3], f32 param_4[3]);

void func_80013C80(Mtx *param_0, f32 *param_1, f32 param_2, f32 param_3,
    f32 param_4, f32 param_5, f32 param_6, f32 param_7, f32 param_8,
    f32 param_9, f32 param_10)
{
    f32 local_0[4][4];
    f32 local_1[3];
    f32 local_2[3];
    f32 local_3[3];

    func_800EFA4C(local_1, param_2, param_3, param_4);
    func_800EFA4C(local_2, param_5, param_6, param_7);
    func_800EFA4C(local_3, param_8, param_9, param_10);
    func_800F2984(local_0, param_1, local_1, local_2, local_3);
    guMtxF2L(local_0, param_0);
}
