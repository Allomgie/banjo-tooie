// Probably the actor-model version of the flash effect: brightens an actor model's vertex colours
// by the level of the matching flasha entry, e.g. for enemies lit by lightning.

#include "common.h"

extern int _idflashbaddie_entrypoint_0[];

// Kernel: brightens vertex colours by level * 50, clamped to 255.
void idflashbaddie_entrypoint_0(s32 param_0, Vtx *src, Vtx *dst, s32 count, f32 *state)
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

void idflashbaddie_entrypoint_1(s32 arg0)
{
}

s32 idflashbaddie_entrypoint_2(f32 *state, s32 param_1, s32 param_2, s32 param_3)
{
    *state = 0.0f;
}

// Reads the level of the flasha entry 100 ids lower on the same actor.
void idflashbaddie_entrypoint_3(f32 *state, s32 param_1, s32 param_2)
{
    s32 flasha;
    flasha = func_80106520(param_2 - 0x64);
    if (flasha) {
        *state = _idflasha_entrypoint_1(flasha) * 0.003921568859f;
    } else {
        *state = 0.0f;
    }
    _glid_entrypoint_0(param_1, param_2, &_idflashbaddie_entrypoint_0, state);
}
