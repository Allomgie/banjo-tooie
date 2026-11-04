// Wave map-mesh effect: travelling sine/cosine waves in X and Z move vertex heights, shade
// the colours by height (205..255) and scroll the UVs.
#include "common.h"

extern f32 func_800136D0(f32);
extern f32 func_8001395C(f32);
extern f32 func_800138BC(f32);
typedef struct {
    f32 strength;
    f32 pad_0[2];
    f32 center[3];
    u8 pad_1[8];
    f32 amplitude;
    f32 diameter;
    s16 state;
    s16 counter;
    f32 phase;
} IdWave30;
typedef struct {
    f32 strength;
    f32 phase_x;
    f32 phase_z;
    u8 pad_0[0x1C];
    s16 uv_s;
    s16 uv_t;
    f32 time;
} WaveState48;
extern f32 func_800D8FF8(void);
extern f32 func_800138D0(f32);
extern f32 func_80013970(f32);
extern void _idwave_entrypoint_0(void);

// Vertex kernel: travelling sine/cosine waves in X and Z displace Y and shade the
// vertex colour by wave height (BK water-wave effect); the UV offsets are added to tc.
void idwave_entrypoint_0(s32 unk_0, Vtx *src, Vtx *dst, s32 count, u8 *state)
{
    f32 sin_x;
    f32 angle_z;
    f32 angle_x;
    f32 center_z;
    f32 base_y;
    f32 phase_x;
    f32 phase_z;
    f32 height;
    f32 center_x;
    s16 uv_s;
    s16 uv_t;
    s32 shade;
    Vtx *end;
    Vtx *in;
    Vtx *out;

    phase_x = *(f32 *) (state + 4);
    phase_z = *(f32 *) (state + 8);
    center_x = *(f32 *) (state + 0x10);
    center_z = *(f32 *) (state + 0x14);
    base_y = *(f32 *) (state + 0xC);
    out = dst;
    in = src;
    uv_s = *(s16 *) (state + 0x28);
    uv_t = *(s16 *) (state + 0x2A);
    end = src + count;

    while (in < end) {
        angle_x = func_800136D0((out->v.ob[0] - center_x) * 200.0f + phase_x);
        angle_z = func_800136D0((out->v.ob[2] - center_z) * 200.0f + phase_z);
        sin_x = func_8001395C(angle_x);
        height = *(f32 *) (state + 0x20) * (func_800138BC(angle_z) + sin_x);
        out->v.ob[1] = base_y + height;
        shade = (height / *(f32 *) (state + 0x24)) * 50.0f + 205.0f;
        out->v.cn[0] = (s32) (in->v.cn[0] * shade) / 255;
        out->v.cn[1] = (s32) (in->v.cn[1] * shade) / 255;
        out->v.cn[2] = (s32) (in->v.cn[2] * shade) / 255;
        out->v.tc[0] = in->v.tc[0] + uv_s;
        out->v.tc[1] = in->v.tc[1] + uv_t;
        in++;
        out++;
    }
}

void idwave_entrypoint_1(s32 unk_0)
{
}

// Init from the mesh bounding box; param 0..10 sets the wave strength (param * 0.1).
void idwave_entrypoint_2(IdWave30 *wave, s32 param, s32 unk_0, s32 unk_1)
{
    s16 bb_min[3];
    s16 bb_max[3];
    _glidmake_entrypoint_2(unk_0, unk_1, bb_min, bb_max);
    wave->pad_0[0] = 0.0f;
    wave->pad_0[1] = 0.0f;
    wave->strength = 1.0f;
    wave->center[0] = bb_min[1] + (bb_max[1] - bb_min[1]) * 0.5f;
    wave->center[1] = bb_min[0];
    wave->center[2] = bb_min[2];
    wave->amplitude = (bb_max[1] - bb_min[1]) * 0.25f;
    wave->state = 0;
    wave->counter = 0;
    wave->phase = 0.0f;
    wave->diameter = wave->amplitude + wave->amplitude;
    if (param >= 0 && param < 11)
        wave->strength = param * 0.1f;
}

// Advances the wave phases and the UV scroll (same formula as id/water.c).
void idwave_entrypoint_3(WaveState48 *wave, s32 unk_0, s32 unk_1)
{
    f32 dt;
    f32 uv[2];

    dt = func_800D8FF8();
    wave->time += dt;
    wave->phase_x += dt * wave->strength * 3;
    wave->phase_z += dt * (wave->strength + 0.01f) * 3;
    uv[0] = ((150.0f * func_800138D0(wave->time * 0.2f * 180.0f)) +
             (func_80013970(wave->time * 0.08f * 180.0f) * 100.0f)) *
            0.8f;
    uv[1] = ((50.0f * func_80013970(wave->time * 0.5f * 180.0f)) +
             (func_800138D0(wave->time * 0.22f * 180.0f) * 100.0f)) *
            0.8f;
    wave->uv_s = (uv[0] >= 0.0f) ? (uv[0] + 0.5f) : (uv[0] - 0.5f);
    wave->uv_t = (uv[1] >= 0.0f) ? (uv[1] + 0.5f) : (uv[1] - 0.5f);
    _glid_entrypoint_0(unk_0, unk_1, _idwave_entrypoint_0, wave);
}
