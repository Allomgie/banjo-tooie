#include "common.h"

extern void *func_801040A8(Actor *);
extern void *func_800B27E0(void *);
extern s32 func_800AE630(void *, void *, s32, f32 *);
extern s32 _dbskeleton_entrypoint_2(void *, s32, f32 *);
extern void func_800EF334(f32 *, f32);
extern void func_800EF5A0(f32 *, f32 *, f32, f32, f32);
extern Actor *func_80106790();
extern int func_80102F74(Actor *, s32);
extern void *func_80104130(void);
void *subaddieskeleton_entrypoint_4();

s32 subaddieskeleton_entrypoint_0(Actor *param_0, s32 param_1, f32 *param_2)
{
    f32 local_0[3];
    void *local_1;
    local_1 = func_801040A8(param_0);
    if (func_800AE0D0(local_1)) {
        if (func_800AE630(local_1, func_800B27E0(func_801039E4(param_0->unk0)), param_1, local_0)) {
            func_800EF334(local_0, param_0->scale);
            func_800EF5A0(local_0, param_0->rotation, local_0[0], local_0[1], local_0[2]);
            func_800EE780(param_2, local_0, param_0->position);
            return 1;
        }
    } else if (_dbskeleton_entrypoint_2(func_800B27E0(func_801039E4(param_0->unk0)), param_1, local_0)) {
        func_800EF334(local_0, param_0->scale);
        func_800EF5A0(local_0, param_0->rotation, local_0[0], local_0[1], local_0[2]);
        func_800EE780(param_2, local_0, param_0->position);
        return 1;
    }
    return 0;
}

void subaddieskeleton_entrypoint_1(u8 **param_0)
{
    func_800DBEFC((*(s32 *)((s8 *)(*param_0) + (4))));
}

int subaddieskeleton_entrypoint_2(Unk80132ED0 *param_0, s32 param_1, s32 param_2)
{
    Actor *local_0;
    void *local_1;
    local_0 = func_80106790(param_0);
    if (local_0->unk7C_12) {
        local_1 = subaddieskeleton_entrypoint_4(local_0);
        if (local_1) {
            func_800DBEFC(local_1, param_1, param_2);
            return 1;
        }
    }
    return 0;
}

int subaddieskeleton_entrypoint_3(Unk80132ED0 *param_0, s32 param_1, f32 *param_2)
{
    Actor *local_0;
    void *local_1;

    local_0 = func_80106790(param_0);
    if (local_0->unk7C_12) {
        local_1 = subaddieskeleton_entrypoint_4(local_0);
        if (local_1) {
            func_800DBEFC(local_1, param_1, param_2);
            return 1;
        }
    }
    func_800EE7F8(param_2, local_0->position);
    return 0;
}

void *subaddieskeleton_entrypoint_4(param_0) Actor *param_0;
{
    void *local_0;

    local_0 = param_0->unk0->unk4;
    if (local_0) {
        return local_0;
    }
    local_0 = func_80102F74(param_0, 2) ? func_80104130() : NULL;
    return local_0;
}
