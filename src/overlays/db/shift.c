#include "common.h"

extern f32 func_800F2290(f32 *, f32 *);
extern void func_800F2388(f32 *, f32 *, f32 *);

void func_80800000_dbshift(f32 *param_0, f32 *param_1, f32 *param_2, f32 *param_3, f32 *param_4)
{
    f32 local_0;
    f32 local_1[2];
    local_0 = func_800F2290(param_1, param_3);
    func_800F2388(local_1, param_2, param_0);
    param_4[0] = func_800F2290(local_1, param_3) / local_0;
    param_4[1] = func_800F2290(local_1, param_1) / local_0;
}

int dbshift_entrypoint_0(s32 param_0[1])
{
  return param_0[0];
}

void dbshift_entrypoint_1(s32 *param_0, s32 param_1, s32 param_2, s32 param_3)
{
    u8 *local_1;
    u8 *local_2;
    s32 local_3;
    u8 *local_0;
    f32 local_4[2];
    if (param_2 >= 0 && param_2 < *param_0) {
        local_0 = (u8 *)param_0 + 4;
        for (local_3 = 0; local_3 < param_2; local_3++) local_0 += *(s16 *)(local_0 + 0x1A) * 8 + 0x1C;
        local_1 = *(s16 *)(local_0 + 0x18) * 0x10 + (u8 *)func_800B2190(param_1);
        local_2 = local_0 + 0x1C;
        for (local_3 = 0; local_3 < *(s16 *)(local_0 + 0x1A); local_3++, local_2 += 8, local_1 += 0x10) {
            func_80800000_dbshift(local_2, local_0, param_3, local_0 + 8, local_4);
            *(s16 *)(local_1 + 8) = (s32)((-local_4[0] * *(f32 *)(local_0 + 0x10) - 0.5f) * 64.0f);
            *(s16 *)(local_1 + 0xA) = (s32)((local_4[1] * *(f32 *)(local_0 + 0x14) - 0.5f) * 64.0f);
        }
    }
}
