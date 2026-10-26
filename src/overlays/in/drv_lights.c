#include "common.h"

extern Actor *func_80106790(Unk80132ED0 *);
extern int _sulights_entrypoint_1(u32, u32[3], f32);
extern int _sulights_entrypoint_3(u32, f32[2], f32);

void indrv_lights_entrypoint_0(u32 param_0, Unk80132ED0 *param_1, s32 param_2)
{
    u32 local_0[5];
    u32 local_1[3];
    f32 local_2[2];
    f32 local_3[2];
    Actor *local_5;
    s32 local_6;
    f32 local_4[3];

    switch (param_0 & 0xFFFF) {
    case 0:
        local_0[0] = (u32)((s32)param_1 & 0xFF000000) >> 24;
        local_0[1] = ((s32)param_1 & 0xFF0000) >> 16;
        local_0[2] = ((s32)param_1 & 0xFF00) >> 8;
        _sulights_entrypoint_1((param_0 & 0xFFFF0000) >> 16, local_0, (f32)param_2 * 0.00390625f);
        break;
    case 5:
        local_1[0] = (u32)((s32)param_1 & 0xFF000000) >> 24;
        local_1[1] = ((s32)param_1 & 0xFF0000) >> 16;
        local_1[2] = ((s32)param_1 & 0xFF00) >> 8;
        func_800C8E84((param_0 & 0xFFFF0000) >> 16, local_1);
        break;
    case 1:
        func_800C8FE0((param_0 & 0xFFFF0000) >> 16, 1);
        break;
    case 2:
        func_800C8FE0((param_0 & 0xFFFF0000) >> 16, 0);
        break;
    case 3:
        local_2[0] = (u32)(param_2 & 0xFFFF);
        local_2[1] = (u32)param_1 & 0xFFFF;
        _sulights_entrypoint_3((param_0 & 0xFFFF0000) >> 16, local_2, (f32)param_2 * 0.00390625f);
        break;
    case 4:
        local_3[0] = (u32)param_2 & 0xFFFF;
        local_3[1] = (u32)param_1 & 0xFFFF;
        func_800C8D4C((param_0 & 0xFFFF0000) >> 16, local_3);
        break;
    case 6:
        local_5 = func_80106790(param_1);
        if (!local_5->unk7C_12 || param_2 == -1) {
            func_800C8CB8((param_0 & 0xFFFF0000) >> 16, local_5->position);
        } else {
            func_800DBEFC(param_1->unk4, param_2, local_4);
            func_800C8CB8((param_0 & 0xFFFF0000) >> 16, local_4);
        }
        break;
    }
}
