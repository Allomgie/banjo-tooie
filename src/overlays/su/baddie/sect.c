#include "common.h"

typedef struct { u8 pad_0[0x70]; u32 pad_1:28; u32 flag_3:1; u32 pad_2:3; } SectFlags30;
extern void *func_800BF704(void);
extern void *_gcmapsects_entrypoint_25(void *, s32, f32 *, f32 *, f32 *, s32);
extern s32 func_800F1B78(f32 *, f32 *, f32, f32);

s32 subaddiesect_entrypoint_0(Actor *param_0, s32 param_1, u32 param_2)
{
    if (!_gcmapsects_entrypoint_5(param_1)) {
        if ((param_2 & 1) && ((SectFlags30 *)param_0)->flag_3) func_8010381C(param_0);
        if (param_2 & 2) func_8010A570(param_0);
        if (param_2 & 4) func_8010A624(param_0);
        if (param_2 & 8) param_0->unk64_16 = 0;
        return 0;
    } else {
        if (param_2 & 2) func_8010A590(param_0);
        if (param_2 & 4) func_8010A63C(param_0);
        if (param_2 & 8) {
            if ((param_2 & 0x10) && !(*(u16 *)((u8 *)param_0 + 0x64) & 1)) _subaddiefade_entrypoint_2(param_0);
            param_0->unk64_16 = 1;
        }
        return 1;
    }
}

s32 subaddiesect_entrypoint_1(s32 param_0) {
    s32 temp = param_0 + 4;
    _gcmapsects_entrypoint_4(temp);
}

s32 subaddiesect_entrypoint_2(Actor *param_0, s32 param_1, s32 param_2)
{
    f32 local_0[3];
    f32 local_1[3];
    f32 local_2[3];
    void *local_3;
    f32 local_4[3];

    func_800EE7F8(local_0, param_0->position);
    func_800EE7F8(local_1, param_0->position);
    local_0[1] += 100.0f;
    local_1[1] -= 100.0f;
    local_3 = _gcmapsects_entrypoint_25(func_800BF704(), param_1, local_0, local_1, local_2, param_0->unk14);
    if (local_3 != NULL) {
        if (param_2) {
            param_0->position[1] = local_1[1];
            if (func_800F1B78(local_4, local_2, param_0->rotation[1], 1.0f)) {
                param_0->rotation[0] = local_4[0];
                param_0->rotation[2] = local_4[2];
            }
        }
        func_801045AC(param_0, local_2, local_1, *(s32 *)((u8 *)local_3 + 8));
        return 1;
    }
    return 0;
}
