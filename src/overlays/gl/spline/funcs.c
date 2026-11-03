#include "common.h"

typedef struct {
    u8 pad[0x77];
    u8 hi : 3;
    u8 f10 : 1;
    u8 lo : 4;
} AF;
typedef struct {
    u16 pad_0;
    s16 pad_1 : 5;
    s16 local_0 : 10;
    s16 pad_2 : 1;
    u8 pad_3[8];
    f32 local_1;
} SplineSpawnState;
extern void *func_80105494(Actor *);
extern Actor *func_80108474(s32, f32 *, s32);
typedef struct {
    f32 local_0;
    u32 local_1;
    u32 local_2;
    u32 local_3;
    u32 local_4;
} SplineLookupNode;
typedef struct {
    s32 local_0;
    SplineLookupNode local_1[1];
} SplineLookupTable;
typedef struct {
    u8 pad_0[0x186];
    s16 local_0;
    s32 local_1;
} SplineLookupLevel;
extern SplineLookupLevel *func_800D7400(void);
extern void *func_8001B798(s32);
extern void func_800C7A68(s32, f32, f32 *);

s32 glsplinefuncs_entrypoint_0(param_0, param_1, param_2, param_3, param_4, param_5, param_6)
s32 param_0;
s32 *param_1;
f32 *param_2;
f32 *param_3;
s32 param_4;
f32 *param_5;
f32 *param_6;
{
    SplineLookupLevel *local_0;
    s16 *local_1;
    SplineLookupTable *local_2;
    f32 local_6;
    SplineLookupNode *local_3;
    SplineLookupNode *local_4;
    s32 local_5;

    local_0 = func_800D7400();
    local_1 = func_8001B798(local_0->local_0);
    local_6 = -9999.0f;
    *param_6 = *param_5 = local_6;
    if (param_4 != -1) {
        local_2 = func_8001B798(local_1[param_4]);
        local_3 = local_2->local_1;
        local_4 = local_2->local_0 + local_2->local_1;
        while ((local_3->local_4 >> 21) != param_0 && local_3 < local_4) {
            local_3++;
        }
        if (local_3 < local_4) {
            if ((local_3->local_1 & 1) == 1) {
                if (!(local_3->local_3 & 1) && (local_3->local_1 << 25 >> 29) == 7) {
                    *param_5 = local_3->local_3 >> 23;
                    *param_6 = (u32) *(u16 *) ((u8 *) local_3 + 6) >> 7;
                }
            }
            *param_1 = param_4;
            *param_2 = local_3->local_0;
            func_800C7A68(func_800D7520(param_4), local_3->local_0, param_3);
            return 1;
        }
    }
    for (local_5 = 0; local_5 < local_0->local_1; local_5++) {
        if (local_5 != param_4) {
            local_2 = func_8001B798(local_1[local_5]);
            local_3 = local_2->local_1;
            local_4 = local_2->local_0 + local_2->local_1;
            while ((local_3->local_4 >> 21) != param_0 && local_3 < local_4) {
                local_3++;
            }
            if (local_3 < local_4) {
                if ((local_3->local_1 & 1) == 1) {
                    if (!(local_3->local_3 & 1) && (local_3->local_1 << 25 >> 29) == 7) {
                        *param_5 = local_3->local_3 >> 23;
                        *param_6 = (u32) *(u16 *) ((u8 *) local_3 + 6) >> 7;
                    }
                }
                *param_1 = local_5;
                *param_2 = local_3->local_0;
                func_800C7A68(func_800D7520(local_5), local_3->local_0, param_3);
                return 1;
            }
        }
    }
    return 0;
}

void glsplinefuncs_entrypoint_1(s32 param_0, s32 param_1, s32 param_2)
{
    s32 local_0;
    s32 fill0;
    s32 fill1;
    s32 local_1;
    s32 local_2;
    f32 local_3;
    f32 local_4[3];
    f32 local_5;
    f32 local_6;
    Actor *local_7;
    SplineSpawnState *local_8;
    s32 local_A;
    local_0 = param_0;
    param_0 = 0;
    local_8 = (SplineSpawnState *) param_2;
    param_2 = 0;
    local_A = param_1;
    param_1 = 0;
    local_2 = (local_A >> 12) & 0x3F;
    local_A &= 0xFFF;
    glsplinefuncs_entrypoint_0(local_A, &local_1, &local_3, local_4, (s32) local_8, &local_5,
                               &local_6);
    local_7 = func_80108474(local_0, local_4, (s32) local_5);
    local_8 = func_80105494(local_7);
    local_8->local_0 = local_1;
    local_8->local_1 = local_3;
    local_7->unk50 = local_6;
    local_7->rotation[0] = local_6;
    ((AF *) local_7)->f10 = 1;
    if (local_2)
        func_800D87D4(local_7, local_2);
}
