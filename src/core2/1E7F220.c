#include "common.h"

typedef struct { s16 local_0; s16 local_1; s16 local_2[9]; } local_type_800A5930;
extern local_type_800A5930 *D_801270F0;
typedef struct { s32 local_0; void *local_1; } local_type_800A5A4C;
extern u8 D_8012762C;
extern u8 D_80119BC0[];
extern local_type_800A5A4C D_80119BD8[];

local_type_800A5930 *func_800A5930(s32 param_0) {
    s32 local_0;
    s32 local_1;
    local_0 = func_800EA05C();
    for (local_1 = 0; D_801270F0[local_1].local_0 != 0; local_1++) {
        if (local_0 == D_801270F0[local_1].local_0 && param_0 == D_801270F0[local_1].local_1) return &D_801270F0[local_1];
    }
    return &D_801270F0[local_1];
}

void func_800A59B8(s32 param_0, s32 *param_1, s32 *param_2, s32 *param_3, s32 *param_4, s32 *param_5, s32 *param_6, s32 *param_7, s32 *param_8, s32 *param_9) {
    u8 *temp_v0;

    temp_v0 = func_800A5930(param_0);
    *param_1 = (s32) (*(s16 *)((s8 *)(temp_v0) + (4)));
    *param_2 = (s32) (*(s16 *)((s8 *)(temp_v0) + (6)));
    *param_3 = (s32) (*(s16 *)((s8 *)(temp_v0) + (8)));
    *param_4 = (s32) (*(s16 *)((s8 *)(temp_v0) + (0xA)));
    *param_5 = (s32) (*(s16 *)((s8 *)(temp_v0) + (0xC)));
    *param_6 = (s32) (*(s16 *)((s8 *)(temp_v0) + (0xE)));
    *param_7 = (s32) (*(s16 *)((s8 *)(temp_v0) + (0x10)));
    *param_8 = (s32) (*(s16 *)((s8 *)(temp_v0) + (0x12)));
    *param_9 = (s32) (*(s16 *)((s8 *)(temp_v0) + (0x14)));
}

void func_800A5A4C(void) {
    s32 i;
    s32 local_1;
    local_1 = D_8012762C;
    D_801270F0 = D_80119BC0;
    for (i = 0; D_80119BD8[i].local_0; i++) {
        if (local_1 == D_80119BD8[i].local_0) D_801270F0 = D_80119BD8[i].local_1;
    }
}
