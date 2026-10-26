#include "common.h"

typedef struct { s32 local_0; f32 local_1[3]; f32 local_2[3]; f32 local_3; f32 local_4[2]; f32 local_5[3]; f32 local_6; } SubaddieBounceState;
extern f32 func_800D8FF8(void);
extern void func_800EFA20(f32 *, f32 *, f32);
extern void func_800EF04C(f32 *, f32 *);
extern void func_800EF334(f32 *, f32);

void subaddiebounce_entrypoint_0(Actor *param_0)
{
    f32 *local_0;
    f32 local_1;
    f32 local_2;
    f32 local_3;
    f32 local_4;

    local_1 = 0.0f;
    local_2 = ((f32 *)param_0->actorData)[3];
    local_3 = param_0->position[1];
    while (local_2 > 0.0f || ((f32 *)param_0->actorData)[1] < local_3) {
        local_3 += local_2 * 0.01666666754f;
        local_1 += 0.01666666754f;
        local_2 += ((f32 *)param_0->actorData)[7] * 0.01666666754f;
    }
    local_0 = (f32 *)&param_0->actorData[4];
    func_800EFB24(local_0, param_0->actorData, param_0->position);
    local_4 = 1.0f / local_1;
    func_800EF334(local_0, local_4);
    ((f32 *)param_0->actorData)[5] = ((f32 *)param_0->actorData)[3];
}

s32 subaddiebounce_entrypoint_1(SubaddieBounceState *param_0)
{
    f32 local_1;
    f32 local_0[3];

    local_1 = func_800D8FF8();
    if (param_0->local_3 < param_0->local_1[1] || param_0->local_5[1] > 0.0f) {
        func_800EFA20(local_0, param_0->local_5, local_1);
        func_800EF04C(param_0->local_1, local_0);
        if (param_0->local_1[1] < param_0->local_3) {
            param_0->local_1[1] = param_0->local_3;
            param_0->local_5[0] = 0.0f;
            param_0->local_5[2] = 0.0f;
            param_0->local_5[1] *= -0.5f;
            return 1;
        }
        param_0->local_5[1] += param_0->local_6 * local_1;
        return 0;
    }
    return 1;
}

int subaddiebounce_entrypoint_2(Actor *param_0)
{
    f32 local_0;

    local_0 = func_800D8FF8();
    if (((f32 *)param_0->actorData)[1] < param_0->position[1] || ((f32 *)param_0->actorData)[5] > 0.0f) {
        param_0->position[1] += ((f32 *)param_0->actorData)[5] * local_0;
        if (param_0->position[1] < ((f32 *)param_0->actorData)[1]) {
            param_0->position[1] = ((f32 *)param_0->actorData)[1];
            ((f32 *)param_0->actorData)[5] *= -0.5f;
            return 1;
        } else {
            ((f32 *)param_0->actorData)[5] += ((f32 *)param_0->actorData)[7] * local_0;
            return 0;
        }
    }
    return 1;
}
