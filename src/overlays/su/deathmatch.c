#include "common.h"

extern void *B_80800300_sudeathmatch[40];
extern u8 B_808003A0_sudeathmatch[40];
extern s32 B_808003C8_sudeathmatch;
extern f32 func_800DC0C0(void);
extern f32 func_800DC178(f32, f32);
extern f32 func_800EFC7C(f32 *, f32 *);

s32 sudeathmatch_entrypoint_0(s32 param_0, f32 *param_1, f32 *param_2)
{
    s32 local_0;
    s32 local_1;
    Vec3f local_2[8];
    s32 local_3;
    s32 local_4;
    s32 local_5;
    Vec3f local_6;
    s32 local_7;
    s32 local_8;
    void *local_9;
    s32 local_10;
    Vec3f local_11;

    local_0 = 0;
    local_1 = 0;
    for (; local_0 < func_800F5898(); local_0++) {
        if (local_0 != param_0 && (local_7 = func_800F6438(local_0))) {
            func_800F5A00(local_0, local_2[local_1++].f);
        }
    }
    local_3 = _gccubesearch_entrypoint_9(0x2B7, B_80800300_sudeathmatch, 40);
    if (local_3 == 0) {
        return 0;
    }
    for (local_0 = 0; local_0 < local_3; local_0++) {
        B_808003A0_sudeathmatch[local_0] = local_0;
    }
    local_3--;
    B_808003A0_sudeathmatch[B_808003C8_sudeathmatch] = B_808003A0_sudeathmatch[local_3];
    while (local_3 > 0) {
        local_4 = func_800DC0C0() * (local_3 - 0.5f);
        local_5 = B_808003A0_sudeathmatch[local_4];
        local_9 = B_80800300_sudeathmatch[local_5];
        _gspropctrl_entrypoint_11(local_9, local_6.f);
        for (local_0 = 0; local_0 < local_1; local_0++) {
            if (func_800EFC7C(local_6.f, local_2[local_0].f) < 160000.0f) {
                if (local_3 >= 2) {
                    B_808003A0_sudeathmatch[local_4] = B_808003A0_sudeathmatch[--local_3];
                } else {
                    local_0 = local_1;
                }
                break;
            }
        }
        if (local_0 == local_1) {
            local_10 = _gspropctrl_entrypoint_8(local_9);
            local_8 = _gspropctrl_entrypoint_12(local_9);
            local_11.pos.x = func_800DC178(-1.0f, 1.0f) * local_10;
            local_11.pos.y = 0.0f;
            local_11.pos.z = func_800DC178(-1.0f, 1.0f) * local_10;
            func_800EE780(param_1, local_6.f, local_11.f);
            param_2[0] = param_2[2] = 0.0f;
            param_2[1] = local_8;
            B_808003C8_sudeathmatch = local_5;
            return 1;
        }
    }
    return 0;
}
