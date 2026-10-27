#include "common.h"

s32 gldbstring_entrypoint_0(s32 param_0, s32 param_1){
    param_0 = func_800D674C(param_1);
    func_800D70D0(1);
    func_800D71F4(1);
    return param_0 + 1;
}

u8 *gldbstring_entrypoint_1(u8 *param_0, s16 param_1)
{
    u8 *local_0;
    u8 *local_1;
    s32 local_2;
    s32 local_3;
    u8 local_4;
    u8 local_5;
    s32 local_6;

    local_6 = _gldialog_entrypoint_0() * 2;
    local_0 = param_0 + local_6;
    local_6 = local_0[0];
    local_6 += local_0[1] << 8;
    local_1 = param_0 + local_6;
    local_2 = local_1[-1];
    for (local_3 = 0; local_3 < local_2; local_3++) {
        local_4 = local_1[0];
        local_5 = local_1[1];
        local_1 += 2;
        if (param_1 + 0x80 == local_4) {
            return local_1;
        }
        local_1 += local_5;
    }
    return NULL;
}

s32 gldbstring_entrypoint_2(Actor *this){
    func_800D721C(this, 0);
    func_800D70F8(this, 0);
    func_800D6CEC(this);
}
