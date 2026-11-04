#include "common.h"

typedef struct {
    s16 uv[2];
    f32 time;
    f32 amp;
    s16 level[3];
    u16 pad_0;
    f32 ramp[3];
} WaterEffectState;
extern f32 func_800DC264(f32, f32);
typedef struct {
    s16 x;
    s16 y;
    f32 t;
    f32 amp;
    s16 lo;
    s16 hi;
    s16 out;
    s16 pad12;
    f32 cur;
    f32 prev;
    f32 max;
} WaterState;
extern f32 func_800D8FF8(void);
extern f32 func_800138D0(f32);
extern f32 func_80013970(f32);
extern u8 _idwater_entrypoint_0[];
extern void _glid_entrypoint_2(s32, s32, void *, void *);

// Vertex kernel: adds the water level to Y and the UV offsets to the texture coords.
void idwater_entrypoint_0(s32 unk_0, s16 *src, s16 *dst, s16 *state)
{
    dst[1] = state[8] + src[1];
    dst[4] = src[4] + state[0];
    dst[5] = src[5] + state[1];
}

// Returns the current water height.
int idwater_entrypoint_1(state)
s16 state[5];
{
    return *(s16 *) ((s8 *) state + 16);
}

void idwater_entrypoint_2(s32 unk_0)
{
}

void idwater_entrypoint_3(WaterEffectState *state, s32 amp, s32 unk_0, s32 unk_1)
{
    state->uv[0] = 0;
    state->uv[1] = 0;
    state->time = func_800DC264(0.0f, 1.0f);
    state->amp = (f32) amp;
    state->level[0] = 0;
    state->level[1] = 0;
    state->level[2] = 0;
    state->ramp[0] = 0.0f;
    state->ramp[1] = 0.0f;
    state->ramp[2] = 0.0f;
}

void idwater_entrypoint_4(WaterState *water, s32 unk_0, s32 unk_1)
{
    f32 level;
    f32 dt;
    f32 uv[2];
    f32 bob;
    f32 wave;

    dt = func_800D8FF8();
    water->t += dt;
    wave = func_800138D0(water->t * 0.2f * 180.0f);
    uv[0] = (150.0f * wave + func_80013970(water->t * 0.08f * 180.0f) * 100.0f) * 0.8f;
    wave = func_80013970(water->t * 0.5f * 180.0f);
    uv[1] = (50.0f * wave + func_800138D0(water->t * 0.22f * 180.0f) * 100.0f) * 0.8f;
    if (uv[0] >= 0.0f) {
        water->x = uv[0] + 0.5f;
    } else {
        water->x = uv[0] - 0.5f;
    }
    if (uv[1] >= 0.0f) {
        water->y = uv[1] + 0.5f;
    } else {
        water->y = uv[1] - 0.5f;
    }
    wave = func_800138D0(water->t * 0.5f * 180.0f);
    bob = func_80013970(water->t * 0.11f * 180.0f) * (water->amp * 0.25f) +
          water->amp * 0.75f * wave;
    // Ramp the level from lo to hi over max seconds.
    if (water->cur < water->max) {
        water->prev = water->cur;
        water->cur += dt;
        if (water->max < water->cur) {
            water->cur = water->max;
        }
    }
    if (water->cur < water->max) {
        level = water->lo + water->cur / water->max * (water->hi - water->lo);
    } else {
        level = water->hi;
    }
    level += bob;
    if (level >= 0.0f) {
        water->out = level + 0.5f;
    } else {
        water->out = level - 0.5f;
    }
    _glid_entrypoint_2(unk_0, unk_1, _idwater_entrypoint_0, water);
}
