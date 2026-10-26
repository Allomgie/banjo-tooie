#include "common.h"

extern void func_80111094(void *, f32 *);
extern void func_801110C4(void *, f32 *);
extern void func_800EFA4C(f32 *, f32, f32, f32);
extern f32 func_800D8FF8(void);
extern f32 func_800F13F0(f32, f32);
extern f32 func_800DC0C0(void);
extern void func_800EF368(f32 *, f32);
extern void func_800EF04C(f32 *, f32 *);
extern f32 sqrtf(f32);
extern void func_800EFB24(f32 *, f32 *, f32 *);

void ncbadeflect_entrypoint_0(void *param_0, f32 *param_1, f32 param_2, f32 param_3, f32 param_4, f32 param_5)
{
    f32 local_2;
    f32 local_3;
    f32 local_5;
    f32 local_4;
    f32 local_6;
    f32 local_0[3];
    f32 local_1[3];
  s32 pad0;
    func_80111094(param_0, local_0);
    if (local_0[1] + 40.0f < param_1[1] + param_3) return;
    if (param_1[1] + param_2 < local_0[1] - 40.0f) return;
    func_800EFA4C(local_1, local_0[0] - param_1[0], 0.0f, local_0[2] - param_1[2]);
    local_2 = local_1[0] * local_1[0] + local_1[1] * local_1[1] + local_1[2] * local_1[2];
    local_3 = param_4 + 80.0f;
    if (local_3 * local_3 < local_2) return;
    local_2 = sqrtf(local_2);
    local_4 = func_800F13F0(func_800D8FF8() * param_5, local_3 - local_2);
    if (local_2 == 0.0f) {
        local_2 = func_800DC0C0();
        func_800EFA4C(local_1, local_2, 0.0f, func_800DC0C0());
    }
    func_800EF368(local_1, local_4);
    func_800EF04C(local_0, local_1);
    func_801110C4(param_0, local_0);
}

void ncbadeflect_entrypoint_1(s32 param_0, f32 *param_1, f32 param_2, f32 param_3, f32 param_4)
{
    s32 pad[2];
    f32 local_4;
    f32 local_0;
    f32 local_1[3];
    f32 local_2[3];
    f32 local_3[3];
    f32 local_5;
    f32 local_6;

    func_800EFA4C(local_3, param_1[0], param_1[1] + param_2, param_1[2]);
    func_80111094(param_0, local_1);
    func_800EFB24(local_2, local_1, local_3);
    local_4 = (local_2[0] * local_2[0] + local_2[1] * local_2[1]) + local_2[2] * local_2[2];
    local_5 = param_3 + 80.0f;
    if (!(local_5 * local_5 < local_4)) {
        local_4 = sqrtf(local_4);
        local_0 = func_800F13F0(func_800D8FF8() * param_4, local_5 - local_4);
        if (local_4 == 0.0f) {
            local_4 = func_800DC0C0();
            local_6 = func_800DC0C0();
            func_800EFA4C(local_2, local_4, local_6, func_800DC0C0());
        }
        func_800EF368(local_2, local_0);
        func_800EF04C(local_1, local_2);
        func_801110C4(param_0, local_1);
    }
}
