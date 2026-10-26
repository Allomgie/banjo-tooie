#include "common.h"

extern u8 _idtwinklea_entrypoint_3[];

s32 idtwinklea_entrypoint_0(s32 *ret, s32 param_1, s32 param_2, s32 param_3){
    *ret = 0;
    *(ret + 1) = 0;
}

void idtwinklea_entrypoint_1(s32 arg0) 
{
}
void idtwinklea_entrypoint_2(s32 param_0, s32 param_1, s32 param_2) {
    s32 local_0;

    local_0 = _idworld_entrypoint_2(param_2 - 0xC8);
    if (local_0 != 0) {
        _idtwinkle_entrypoint_6(local_0, param_0, param_0 + 4);
        _glid_entrypoint_0(param_1, param_2, &_idtwinklea_entrypoint_3, param_0);
    }
}

void idtwinklea_entrypoint_3(s32 param_0, u8 *param_1, u8 *param_2, s32 param_3, u8 *param_4)
{
    u8 *local_0;
    u8 *local_1;
    u8 *local_2 = param_1 + param_3 * 0x10;
    f32 local_3;

    for (; param_1 < local_2; param_1 += 0x10, param_2 += 0x10) {
        local_0 = *(u8 **)param_4;
        local_1 = *(u8 **)(param_4 + 4);
        for (; local_0 < local_1; local_0 += 0x10) {
            if (*(s16 *)param_1 == *(s16 *)(local_0 + 8) &&
                *(s16 *)(param_1 + 2) == *(s16 *)(local_0 + 10) &&
                *(s16 *)(param_1 + 4) == *(s16 *)(local_0 + 12)) {
                break;
            }
        }
        local_3 = local_0 == local_1 ? 0.0f : 1.0f;
        if (local_3 > 1.0f) local_3 = 1.0f;
        param_2[15] = (u32)(local_3 * 255.0f);
    }
}
