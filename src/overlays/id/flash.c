#include "common.h"

extern s32 _idflash_entrypoint_0;

void idflash_entrypoint_0(s32 param_0, Vtx *param_1, Vtx *param_2, s32 param_3, f32 *param_4)
{
    s32 local_0;
    s32 local_1;
    Vtx *local_2;

    local_0 = param_4[0] * 50.0f;
    for (local_2 = param_1 + param_3; param_1 < local_2; param_1++, param_2++) {
        local_1 = param_1->v.cn[0] + local_0;
        if (local_1 >= 256) {
            local_1 = 255;
        }
        param_2->v.cn[0] = local_1;
        local_1 = param_1->v.cn[1] + local_0;
        if (local_1 >= 256) {
            local_1 = 255;
        }
        param_2->v.cn[1] = local_1;
        local_1 = param_1->v.cn[2] + local_0;
        if (local_1 >= 256) {
            local_1 = 255;
        }
        param_2->v.cn[2] = local_1;
    }
}

void idflash_entrypoint_1(s32 arg0) 
{
}
s32 idflash_entrypoint_2(f32 *param_0, s32 param_1, s32 param_2, s32 param_3){
    *param_0 = 0.0f;
}

void idflash_entrypoint_3(f32 *param_0, s32 param_1, s32 param_2) {
    s32 local_0;

    local_0 = _idworld_entrypoint_1(param_2 - 0x64);
    if (local_0 != 0) {
        *param_0 = (f32) _idflasha_entrypoint_1(local_0) * 0.003921569f;
    } else {
        *param_0 = 0.0f;
    }
    _glid_entrypoint_0(param_1, param_2, &_idflash_entrypoint_0, param_0);
}
