#include "common.h"

extern f32 func_800EEB40(f32 *, f32 *);
extern void func_800DA3B8();
extern void func_800EE88C();

void sutempleboss_entrypoint_0(void *param_0, s32 *param_1, s32 *param_2)
{
    s32 local_0;
    s32 local_1;
    f32 local_5;
    f32 local_2[3];
    f32 local_3[3];
    f32 local_4;

    if (!func_800F4BE4(func_800F54E4())) {
        *param_2 = 0;
        *param_1 = 0;
        return;
    }
    switch (func_800EA05C()) {
    case 0x177:
        *param_1 = 0x178;
        if (func_800DA298(0x9D2)) *param_2 = 2;
        else *param_2 = 1;
        return;
    case 0x17A:
        *param_1 = 0x178;
        if (func_800DA298(0x9D2)) *param_2 = 1;
        else *param_2 = 2;
        return;
    case 0x178:
        func_800EE88C(local_2, param_0);
        func_800EE88C(local_3, _gccubesearch_entrypoint_15(1, 0, local_2));
        local_4 = func_800EEB40(local_2, local_3);
        func_800EE88C(local_3, _gccubesearch_entrypoint_15(2, 0, local_2));
        local_5 = func_800EEB40(local_2, local_3);
        local_1 = local_4 < local_5 ? 0 : 1;
        if (func_800D0B68(2, 1, local_1)) {
            if (func_800DA298(0x9D2)) local_0 = local_1 ^ 1;
            else local_0 = local_1;
        } else {
            local_0 = 0;
            func_800DA3B8(0x9D2, local_1);
        }
        if (local_0) *param_1 = 0x17A;
        else *param_1 = 0x177;
        *param_2 = 1;
        return;
    }
}
