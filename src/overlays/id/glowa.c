#include "common.h"

extern f32 func_800D8FF8(void);
extern s32 func_800F1574(f32 *, f32);
extern void _idglowa_entrypoint_0();

// Kernel: scales vertex alpha by the level.
void idglowa_entrypoint_0(s32 param_0, Vtx *src, Vtx *dst, s32 count, f32 *state)
{
    Vtx *end;
    f32 level;

    level = state[1];
    end = src + count;
    for (; src < end; src++, dst++) {
        dst->v.cn[3] = (u32) ((u32) src->v.cn[3] * level);
    }
}

// Returns the current level.
f32 idglowa_entrypoint_1(Actor *state)
{
    return *(f32 *) ((char *) state + 0x4);
}

// State 2 is the pause between pulses.
void func_808000E8_idglowa(u8 *state, s32 new_state)
{
    if (new_state == 2) {
        *(f32 *) ((s8 *) state + 0xC) = 1.0f;
    }
    *(s32 *) ((s8 *) state + 0) = new_state;
}

void idglowa_entrypoint_2(s32 arg0)
{
}

void idglowa_entrypoint_3(u8 *state, s32 mesh_param, f32 param_2, f32 param_3)
{
    *(s32 *) state = 0;
    *(f32 *) (state + 4) = 0.5f;
    *(f32 *) (state + 8) = (mesh_param + 1) * 0.01f;
    func_808000E8_idglowa(state, 1);
}

// Pulses the level up to 1 and down to 0, then pauses; runs the kernel.
void idglowa_entrypoint_4(u8 *state, s32 param_1, s32 param_2)
{
    f32 dt;

    dt = func_800D8FF8();
    if (*(s32 *) state == 1) {
        *(f32 *) (state + 4) += *(f32 *) (state + 8) * dt;
        if (*(f32 *) (state + 4) >= 1.0f) {
            *(f32 *) (state + 4) = 1.0f;
            *(f32 *) (state + 8) = -*(f32 *) (state + 8);
        } else if (*(f32 *) (state + 4) < 0.0f) {
            *(f32 *) (state + 4) = 0.0f;
            *(f32 *) (state + 8) = -*(f32 *) (state + 8);
            func_808000E8_idglowa(state, 2);
            return;
        }
    }
    if (*(s32 *) state == 2 && func_800F1574((f32 *) (state + 0xC), dt)) {
        func_808000E8_idglowa(state, 1);
    }
    _glid_entrypoint_0(param_1, param_2, _idglowa_entrypoint_0, state);
}
