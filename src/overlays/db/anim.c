#include "common.h"

extern void *func_800B2190(s32);
extern void *func_80100480(s32, s32);
extern void *func_800ADE2C(void *, s32);
typedef struct { s16 local_0[3]; u8 local_1[10]; } Mass47DBAnimVertex;

void dbanim_entrypoint_0(s16 *param_0, s32 param_1, void *param_2)
{
    s16 *local_0;
    s32 local_1;
    s16 *local_2;
    s16 *local_3;
    s16 *local_4;
    u8 *local_5;
    s16 *local_6;

    local_5 = func_800B2190(param_1);
    local_2 = param_0 + 2;
    for (local_1 = 0; local_1 < param_0[1]; local_1++) {
        local_3 = func_80100480(4, local_2[1]);
        local_4 = local_2 + 3;
        func_80116568(func_800ADE2C(param_2, local_2[0]), local_4, local_3, local_2[1]);
        local_0 = local_4;
        local_0 += local_2[1] * 3;
        if (param_0[0]) local_0 += local_2[2] * 2;
        while (*local_0 >= -1) {
            if (*local_0 == -1) local_3 += 3;
            else {
                local_6 = (s16 *)(local_5 + *local_0 * 0x10);
                local_6[0] = local_3[0];
                local_6[1] = local_3[1];
                local_6[2] = local_3[2];
            }
            local_0++;
        }
        local_2 = local_0 + 1;
    }
    osWritebackDCache(local_5, func_800B2344(param_1) * 0x10);
}

void dbanim_entrypoint_1(s16 *param_0, s32 param_1, void *param_2, u8 *param_3)
{
    s16 *local_0;
    s16 *local_1;
    s16 *local_2;
    f32 *local_3;
    Mass47DBAnimVertex *local_4;
    Mass47DBAnimVertex *local_5;
    u8 *local_6;
    s32 local_7;
    s32 local_8;

    local_4 = func_800B2190(param_1);
    local_7 = 0;
    local_0 = param_0 + 2;
    while (local_7 < param_0[1]) {
        local_1 = func_80100480(4, local_0[1]);
        local_2 = local_0 + 3;
        func_80116568(func_800ADE2C(param_2, local_0[0]), local_2, local_1, local_0[1]);
        local_2 += local_0[1] * 3;
        local_3 = func_80100480(2, local_0[2]);
        func_801163B0(local_2, func_800ADE2C(param_2, local_0[0]), local_3, local_0[2]);
        local_2 += local_0[2] * 2;
        while (*local_2 >= -1) {
            if (*local_2 == -1) {
                local_1 += 3;
            } else {
                local_5 = local_4 + *local_2;
                local_5->local_0[0] = local_1[0];
                local_5->local_0[1] = local_1[1];
                local_5->local_0[2] = local_1[2];
                local_3 += 3;
                local_6 = param_3 + *local_2 * 4;
                local_6[0] = (s32)(local_3[-3] * 127.0f);
                local_6[1] = (s32)(local_3[-2] * 127.0f);
                local_6[2] = (s32)(local_3[-1] * 127.0f);
            }
            local_2++;
        }
        local_7++;
        local_0 = local_2 + 1;
    }
    local_8 = func_800B2344(param_1);
    osWritebackDCache(local_4, local_8 * 16);
    osWritebackDCache(param_3, local_8 * 4);
}
