#include "common.h"

extern f32 func_800D8FF8(void);
extern void _idglow_entrypoint_0(void);

// Kernel: scales vertex colour RGB by the level.
void idglow_entrypoint_0(s32 param_0, Vtx *src, Vtx *dst, s32 count, f32 *state)
{
    Vtx *end;
    f32 level;
    level = *state;
    end = src + count;
    for (; src < end; src++, dst++) {
        dst->v.cn[0] = src->v.cn[0] * level;
        dst->v.cn[1] = src->v.cn[1] * level;
        dst->v.cn[2] = src->v.cn[2] * level;
    }
}

void idglow_entrypoint_1(s32 arg0)
{
}

// Init: level 0.5, speed (param + 1) * 0.01.
int idglow_entrypoint_2(f32 *state, s32 mesh_param, s32 param_2, s32 param_3)
{
    float tmp;
    f32 speed;
    // Matching: tmp is reused for two different values.
    tmp = mesh_param + 1.0f;
    speed = tmp;
    tmp = 0.009999999776;
    speed *= tmp;
    state[0] = 0.5f;
    state[1] = speed;
}

// Bounces the level between 0.3 and 1.0, then runs the kernel.
void idglow_entrypoint_3(f32 *state, void *param_1, void *param_2)
{
    state[0] += state[1] * func_800D8FF8();
    if (state[0] >= 1.0f) {
        state[0] = 1.0f;
        state[1] = -state[1];
    } else if (state[0] < 0.3000000119f) {
        state[0] = 0.3000000119f;
        state[1] = -state[1];
    }
    _glid_entrypoint_0(param_1, param_2, _idglow_entrypoint_0, state);
}
