#include "common.h"

typedef struct { s16 box_count; s16 cylinder_count; s16 sphere_count; s16 pad; } VolumeHeader;
typedef struct { s16 min[3]; s16 max[3]; s16 position[3]; u8 rotation[3]; u8 pad_15; s8 bone; u8 pad_17; } VolumeBox;
typedef struct { s16 radius; s16 height; s16 position[3]; u8 rotation[3]; u8 pad_D; s8 bone; u8 pad_F; } VolumeCylinder;
typedef struct { s16 radius; s16 position[3]; u8 pad_8; s8 bone; u8 pad_A[2]; } VolumeSphere;
extern void *func_80103D98(void *);
extern void *func_801040A8(Actor *);
extern f32 func_80103F38(Actor *, f32 *);
extern f32 *func_801027F4(Actor *);
extern void *func_800ADE2C(void *, s32);
extern void func_80019AA0(void *, void *);
extern void func_80019750(f32 *, f32 *, f32, void *);
extern void func_80019994(f32 *, f32 *);
extern void func_800198D4(f32 *, f32 *);
extern void func_800EE88C();
extern void func_800EEC30(f32 *, f32, f32, f32);
extern void func_800EEB9C(f32 *, f32, f32);
extern void func_800EF04C(f32 *, f32 *);
extern void func_80019224(f32 *, f32 *);
extern f32 func_800DC178(f32, f32);
extern s32 func_800DC298(f32);
extern s32 func_800DC128(s32, s32);
extern s32 func_800F1418(s32, s32);
extern void mlMtxGet(void *);
extern void mlMtxPop(void);
extern void mlMtxTranslate(f32, f32, f32);

s32 subaddievolume_entrypoint_0(Actor *param_0, f32 (*param_1)[3], s32 param_2, s32 param_3, s32 *param_4)
{
    f32 local_0[4][4];
    s32 local_1;
    s32 local_2;
    void *local_3;
    VolumeHeader *local_4;
    VolumeBox *local_5;
    VolumeCylinder *local_6;
    VolumeSphere *local_7;
    s32 local_8;
    s32 local_9;
    f32 local_10[3];
    VolumeBox *local_11;
    s32 local_12;
    f32 local_13[3];
    f32 local_14[3];
    s32 local_15;
    VolumeCylinder *local_16;
    f32 local_17;
    f32 local_18[3];
    f32 local_19[3];
    VolumeSphere *local_20;
    f32 local_21[3];
    s32 local_22;

    if (param_0 == 0) {
        return 0;
    }
    if (!param_0->unk7C_12) {
        return -1;
    }

    local_4 = func_80103D98(param_0->unk0);
    local_3 = func_801040A8(param_0);
    if (local_3 == 0 || local_4 == 0) {
        local_22 = func_800F1418(param_2 * 3, param_3);
        local_17 = func_80103F38(param_0, local_10);
        for (local_1 = 0; local_1 < local_22; local_1++) {
            func_800EEC30(param_1[local_1], func_800DC178(0.0f, 359.0f),
                         func_800DC178(0.0f, 359.0f), local_17);
            func_800EF04C(param_1[local_1], local_10);
        }
        return local_22;
    }

    local_5 = (VolumeBox *)(local_4 + 1);
    local_6 = (VolumeCylinder *)(local_5 + local_4->box_count);
    local_7 = (VolumeSphere *)(local_6 + local_4->cylinder_count);
    local_9 = local_4->box_count + local_4->cylinder_count + local_4->sphere_count;
    local_8 = param_4 ? *param_4 : 0;
    if (local_8 >= local_9) {
        local_8 = 0;
    }
    func_80019CD4();
    func_80019750(param_0->position, func_801027F4(param_0), param_0->scale, 0);
    mlMtxGet(local_0);

    for (local_1 = 0; local_1 < param_3; ) {
        if (param_4) {
            *param_4 = local_8 + 1;
        }
        if (local_8 < local_4->box_count) {

            local_11 = &local_5[local_4->box_count - local_8 - 1];
            for (local_2 = 0; local_2 < param_2; local_2++) {
                func_800EE88C(local_13, local_11->position);
                local_14[0] = (f32)(u32)local_11->rotation[0] * 2.0f;
                local_14[1] = (f32)(u32)local_11->rotation[1] * 2.0f;
                local_14[2] = (f32)(u32)local_11->rotation[2] * 2.0f;
                func_80019AA0(local_0, func_800ADE2C(local_3, local_11->bone));
                func_80019994(local_13, local_14);
                for (local_12 = 0; local_12 != 3; local_12++) {
                    param_1[local_1][local_12] = func_800DC178(local_11->min[local_12],
                                                              local_11->max[local_12]);
                }
                local_15 = func_800DC128(0, 3);
                if (func_800DC298(0.5f)) {
                    param_1[local_1][local_15] = local_11->min[local_15];
                } else {
                    param_1[local_1][local_15] = local_11->max[local_15];
                }
                func_80019224(param_1[local_1], param_1[local_1]);
                local_1++;
                if (local_1 >= param_3) {
                    return local_1;
                }
                mlMtxPop();
            }
        } else if (local_8 < local_4->box_count + local_4->cylinder_count) {
            local_16 = &local_6[local_4->box_count + local_4->cylinder_count - local_8 - 1];
            for (local_2 = 0; local_2 < param_2; local_2++) {
                func_800EE88C(local_18, local_16->position);
                local_19[0] = (f32)(u32)local_16->rotation[0] * 2.0f;
                local_19[1] = (f32)(u32)local_16->rotation[1] * 2.0f;
                local_19[2] = (f32)(u32)local_16->rotation[2] * 2.0f;
                local_19[0] += 90.0f;
                func_80019AA0(local_0, func_800ADE2C(local_3, local_16->bone));
                func_800198D4(local_18, local_19);
                func_800EEB9C(param_1[local_1], func_800DC178(0.0f, 359.0f), local_16->radius);
                param_1[local_1][1] = func_800DC178(local_16->height * -0.5f, local_16->height * 0.5f);
                func_80019224(param_1[local_1], param_1[local_1]);
                local_1++;
                if (local_1 >= param_3) {
                    return local_1;
                }
                mlMtxPop();
            }
        } else {
            local_20 = &local_7[local_9 - local_8 - 1];
            for (local_2 = 0; local_2 < param_2; local_2++) {
                func_800EE88C(local_21, local_20->position);
                func_80019AA0(local_0, func_800ADE2C(local_3, local_20->bone));
                mlMtxTranslate(local_21[0], local_21[1], local_21[2]);
                func_800EEC30(param_1[local_1], func_800DC178(0.0f, 359.0f),
                             func_800DC178(0.0f, 359.0f), local_20->radius);
                func_80019224(param_1[local_1], param_1[local_1]);
                local_1++;
                if (local_1 >= param_3) {
                    return local_1;
                }
                mlMtxPop();
            }
        }
        local_8++;
        if (local_8 >= local_9) {
            local_8 = 0;
        }
    }
    return local_1;
}
