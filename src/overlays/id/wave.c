#include "common.h"

extern f32 func_800136D0(f32);
extern f32 func_8001395C(f32);
extern f32 func_800138BC(f32);
typedef struct { f32 strength; f32 pad_0[2]; f32 center[3]; u8 pad_1[8]; f32 amplitude; f32 diameter; s16 state; s16 counter; f32 phase; } IdWave30;
typedef struct { f32 local_0; f32 local_1; f32 local_2; u8 local_3[0x1C]; s16 local_4; s16 local_5; f32 local_6; } WaveState48;
extern f32 func_800D8FF8(void);
extern f32 func_800138D0(f32);
extern f32 func_80013970(f32);
extern void _idwave_entrypoint_0(void);

void idwave_entrypoint_0(s32 param_0, Vtx *param_1, Vtx *param_2, s32 param_3, u8 *param_4)
{
    f32 local_3;
    f32 local_4;
    f32 local_2;
    f32 local_0;
    f32 local_1;
    f32 local_5;
    f32 local_6;
    f32 local_7;
    f32 local_8;
    s16 local_9;
    s16 local_10;
    s32 local_11;
    Vtx *local_12;
    Vtx *local_13;
    Vtx *local_14;

    local_5 = *(f32 *)(param_4 + 4);
    local_6 = *(f32 *)(param_4 + 8);
    local_8 = *(f32 *)(param_4 + 0x10);
    local_0 = *(f32 *)(param_4 + 0x14);
    local_1 = *(f32 *)(param_4 + 0xC);
    local_14 = param_2;
    local_13 = param_1;
    local_9 = *(s16 *)(param_4 + 0x28);
    local_10 = *(s16 *)(param_4 + 0x2A);
    local_12 = param_1 + param_3;

    while (local_13 < local_12) {
        local_2 = func_800136D0((local_14->v.ob[0] - local_8) * 200.0f + local_5);
        local_4 = func_800136D0((local_14->v.ob[2] - local_0) * 200.0f + local_6);
        local_3 = func_8001395C(local_2);
        local_7 = *(f32 *)(param_4 + 0x20) * (func_800138BC(local_4) + local_3);
        local_14->v.ob[1] = local_1 + local_7;
        local_11 = (local_7 / *(f32 *)(param_4 + 0x24)) * 50.0f + 205.0f;
        local_14->v.cn[0] = (s32)(local_13->v.cn[0] * local_11) / 255;
        local_14->v.cn[1] = (s32)(local_13->v.cn[1] * local_11) / 255;
        local_14->v.cn[2] = (s32)(local_13->v.cn[2] * local_11) / 255;
        local_14->v.tc[0] = local_13->v.tc[0] + local_9;
        local_14->v.tc[1] = local_13->v.tc[1] + local_10;
        local_13++;
        local_14++;
    }
}

void idwave_entrypoint_1(s32 arg0) 
{
}
void idwave_entrypoint_2(IdWave30 *param_0, s32 param_1, s32 param_2, s32 param_3)
{
    s16 local_0[3];
    s16 local_1[3];
    _glidmake_entrypoint_2(param_2, param_3, local_0, local_1);
    param_0->pad_0[0] = 0.0f;
    param_0->pad_0[1] = 0.0f;
    param_0->strength = 1.0f;
    param_0->center[0] = local_0[1] + (local_1[1] - local_0[1]) * 0.5f;
    param_0->center[1] = local_0[0];
    param_0->center[2] = local_0[2];
    param_0->amplitude = (local_1[1] - local_0[1]) * 0.25f;
    param_0->state = 0;
    param_0->counter = 0;
    param_0->phase = 0.0f;
    param_0->diameter = param_0->amplitude + param_0->amplitude;
    if (param_1 >= 0 && param_1 < 11) param_0->strength = param_1 * 0.1f;
}

void idwave_entrypoint_3(WaveState48 *arg0, s32 arg1, s32 arg2)
{
    f32 temp_f0;
    f32 sp2C[2];

    temp_f0 = func_800D8FF8();
    arg0->local_6 += temp_f0;
    arg0->local_1 += temp_f0 * arg0->local_0 * 3;
    arg0->local_2 += temp_f0 * (arg0->local_0 + 0.01f) * 3;
    sp2C[0] = ((150.0f * func_800138D0(arg0->local_6 * 0.2f * 180.0f)) + (func_80013970(arg0->local_6 * 0.08f * 180.0f) * 100.0f)) * 0.8f;
    sp2C[1] = ((50.0f * func_80013970(arg0->local_6 * 0.5f * 180.0f)) + (func_800138D0(arg0->local_6 * 0.22f * 180.0f) * 100.0f)) * 0.8f;
    arg0->local_4 = (sp2C[0] >= 0.0f) ? (sp2C[0] + 0.5f) : (sp2C[0] - 0.5f);
    arg0->local_5 = (sp2C[1] >= 0.0f) ? (sp2C[1] + 0.5f) : (sp2C[1] - 0.5f);
    _glid_entrypoint_0(arg1, arg2, _idwave_entrypoint_0, arg0);
}
