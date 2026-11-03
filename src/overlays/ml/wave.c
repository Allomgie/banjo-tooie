#include "common.h"

extern f32 func_800DC178(f32, f32);
extern f32 func_8001395C(f32);
extern f32 func_800F13C4(f32, f32);
extern f32 func_800F10B4(f32, f32, f32, f32, f32);
f32 mlwave_entrypoint_6();

void mlwave_entrypoint_0(f32 *param_0, f32 param_1, f32 param_2)
{
    param_0[3] = param_2;
    param_0[4] = param_2;
    param_0[2] = param_1;
    param_0[0] = 0.0f;
    param_0[5] = 100.0f;
    if (param_1) {
        param_0[1] = 6.2831855f / param_1;
    } else {
        param_0[1] = 0.0f;
    }
    param_0[6] = 0.0f;
}

void mlwave_entrypoint_1(f32 *param_0)
{
    extern f32 func_800D8FF8(void);
    extern f32 func_800F15F8(f32, f32, f32);
    f32 local_0;

    local_0 = func_800D8FF8();
    param_0[6] = mlwave_entrypoint_6(param_0);
    param_0[3] = func_800F15F8(param_0[3], param_0[4], param_0[5] * local_0);
    param_0[0] += param_0[3] * local_0;
}

void mlwave_entrypoint_2(f32 *param_0, f32 param_1, f32 param_2)
{
    param_0[0] = func_800DC178(param_1, param_2) * param_0[2];
    param_0[6] = mlwave_entrypoint_6(param_0);
}

void mlwave_entrypoint_3(Actor *param_0, f32 param_1, f32 param_2)
{
    f32 *new_var;
    new_var = (char *) param_0;
    *(f32 *) (new_var + 4) = param_1;
    *(new_var = (f32 *) (new_var + 5)) = param_2;
}

f32 mlwave_entrypoint_4(f32 *param_0, f32 param_1, f32 param_2, f32 param_3)
{
    return func_800F10B4(func_8001395C((param_1 - param_0[0]) * param_0[1]), -1.0f, 1.0f, param_2,
                         param_3);
}

f32 mlwave_entrypoint_5(s32 param_0, f32 param_1, f32 param_2)
{
    return mlwave_entrypoint_4(param_0, 0.0f, param_1, param_2);
}

f32 mlwave_entrypoint_6(param_0)
f32 *param_0;
{
    f32 local_0;
    f32 local_1;

    local_0 = func_800F13C4(param_0[0], param_0[2]);
    if (param_0[0] < 0) {
        local_1 = -param_0[2];
    } else {
        local_1 = param_0[2];
    }
    return func_800F10B4(local_0, 0.0f, local_1, 0.0f, 1.0f);
}

int mlwave_entrypoint_7(f32 param_0[3], f32 param_1)
{
    param_0[0] = param_0[2] * param_1;
    param_0[6] = param_1;
}

s32 mlwave_entrypoint_8(u8 *param_0, f32 param_1)
{
    f32 local_1;
    f32 local_0;
    s32 local_2;

    local_0 = *(f32 *) (param_0 + 0x18);
    local_1 = mlwave_entrypoint_6((f32 *) param_0);

    if (*(f32 *) (param_0 + 12) > 0.0f) {
        if (local_0 < local_1) {
            return local_0 <= param_1 && param_1 < local_1;
        }
        local_2 = local_0 <= param_1 || param_1 < local_1;
        if (local_2 && local_2 && local_2) {
        }
        return local_2 | 0;
    }
    if (local_1 < local_0) {
        local_2 = param_1 <= local_0 && local_1 < param_1;
    } else {
        local_2 = param_1 <= local_0 || local_1 < param_1;
    }
    return local_2 | 0;
}

s32 mlwave_entrypoint_9(s32 param_0, f32 *param_1)
{
    float new_var;
    f32 *var_s0;
    f32 var_f0;
    new_var = -1.0f;
    var_f0 = *param_1;
    var_s0 = param_1;
    if (*param_1 != -1.0f) {
    loop_1:
        if (mlwave_entrypoint_8(param_0 ^ 0, var_f0) != 0) {
            return 1;
        }

        var_f0 = *(f32 *) ((char *) var_s0 + 4);
        var_s0 += 1;
        if (var_f0 == (0, new_var)) {
            goto block_4;
        }
        goto loop_1;
    }
block_4:
    return 0;
}
