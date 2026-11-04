#include "common.h"

extern s32 _idflash_entrypoint_0;

// Kernel: brightens vertex colours by level * 50, clamped to 255.
void idflash_entrypoint_0(s32 param_0, Vtx *src, Vtx *dst, s32 count, f32 *state)
{
    s32 boost;
    s32 value;
    Vtx *end;

    boost = state[0] * 50.0f;
    for (end = src + count; src < end; src++, dst++) {
        value = src->v.cn[0] + boost;
        if (value >= 256) {
            value = 255;
        }
        dst->v.cn[0] = value;
        value = src->v.cn[1] + boost;
        if (value >= 256) {
            value = 255;
        }
        dst->v.cn[1] = value;
        value = src->v.cn[2] + boost;
        if (value >= 256) {
            value = 255;
        }
        dst->v.cn[2] = value;
    }
}

void idflash_entrypoint_1(s32 arg0)
{
}

s32 idflash_entrypoint_2(f32 *state, s32 param_1, s32 param_2, s32 param_3)
{
    *state = 0.0f;
}

// Reads the level of the flasha entry with mesh id 100 lower.
void idflash_entrypoint_3(f32 *state, s32 param_1, s32 param_2)
{
    s32 flasha;

    flasha = _idworld_entrypoint_1(param_2 - 0x64);
    if (flasha != 0) {
        *state = (f32) _idflasha_entrypoint_1(flasha) * 0.003921569f;
    } else {
        *state = 0.0f;
    }
    _glid_entrypoint_0(param_1, param_2, &_idflash_entrypoint_0, state);
}
