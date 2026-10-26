#include "common.h"

#define CODEX_WIBBLE_RECORD
typedef struct { s16 ob[3]; u16 flag; s16 tc[2]; u8 cn[4]; } WibVtx;
typedef struct { u8 pad0[0xE]; s16 unkE; } WibbleRecord;
extern WibbleRecord D_80800770_idwibble[];
typedef struct { f32 local_0[3]; f32 local_1[3]; u8 pad_0[0xC]; f32 local_2; s32 pad_1; f32 local_3; s32 pad_2; s16 local_4; u8 pad_3; u8 local_5; } WibbleState;
extern f32 func_800D8FF8(void);
extern void func_800EE7F8(f32 *, f32 *);
extern void _glid_entrypoint_0();
extern void _idwibble_entrypoint_0(void);
extern f32 func_800EEF94(f32 *);
extern f32 func_800136D0(f32);
extern f32 func_800137D4(f32);
extern f32 func_80013788(f32);
typedef struct { f32 local_0[3]; f32 local_1[3]; s16 local_2; s16 local_3; f32 local_4; f32 local_5; f32 local_6; f32 local_7; f32 local_8; u8 local_9; u8 local_10; u8 local_11; u8 local_12; s16 local_13; u8 local_14; u8 local_15; } WibbleData50;
typedef struct { f32 local_0; f32 local_1; f32 local_2; u8 local_3; u8 local_4; s16 local_5; } WibbleSettings50;
f32 func_80800000_idwibble();

f32 func_80800000_idwibble(param_0, param_1, param_2) u8 *param_0; s16 *param_1; f32 *param_2;
{
    f32 local_0;
    f32 local_1;
    f32 local_3;
    f32 local_2[3];
    f32 local_4;

    local_2[0] = param_1[0];
    local_2[1] = param_1[1];
    local_2[2] = param_1[2];
    local_0 = func_800EEF94(local_2);
    local_1 = *(s16 *)(param_0 + 0x1A) *
        func_800137D4(func_800136D0((local_0 - *(f32 *)(param_0 + 0x24)) * *(f32 *)(param_0 + 0x28)));
    if (param_0[0x33]) {
        local_3 = *(f32 *)(param_0 + 0x28) * (*(s16 *)(param_0 + 0x1A) * func_80013788(local_1));
        if (local_0 > 0.0001f) {
            local_4 = local_3 / local_0;
            param_2[0] = local_2[0] * local_4;
            param_2[1] = local_2[2] * local_4;
        } else {
            param_2[0] = local_2[0] * local_3;
            param_2[1] = local_2[2] * local_3;
        }
    }
    return local_1;
}

void idwibble_entrypoint_0(s32 arg0, WibVtx *src, WibVtx *dst, s32 n, u8 *w)
{
    f32 d;
    s32 a;
    f32 off[2];
    WibVtx *end;

    end = src + n;
    for (; src < end; src++, dst++) {
        d = func_80800000_idwibble(w, src->ob, off);
        if (w[0x31] == 1) {
            dst->ob[1] = *(s16 *)(w + 0x34) + (*(s16 *)(w + 0x18) + d);
        } else if (w[0x31] == 2) {
            dst->ob[1] = *(s16 *)(w + 0x34) + (src->ob[1] + d);
        }
        if (w[0x32] == 1) {
            a = d * *(f32 *)(w + 0x20) + (u32)w[0x30];
            dst->cn[0] = (src->cn[0] * a) >> 8;
            dst->cn[1] = (src->cn[1] * a) >> 8;
            dst->cn[2] = (src->cn[2] * a) >> 8;
        }
        if (w[0x33]) {
            dst->tc[0] = src->tc[0] + *(f32 *)(w + 0x1C) * off[0];
            dst->tc[1] = src->tc[1] + *(f32 *)(w + 0x1C) * off[1];
        }
    }
}

void idwibble_entrypoint_1(s32 arg0) 
{
}
WibbleRecord *func_80800324_idwibble(s32 param_0)
{
    s32 local_0;

    param_0 -= param_0 % 100;
    for (local_0 = 0; local_0 < 6; local_0++) {
        if (param_0 == D_80800770_idwibble[local_0].unkE) {
            return &D_80800770_idwibble[local_0];
        }
    }
    return D_80800770_idwibble;
}

void idwibble_entrypoint_2(WibbleData50 *param_0, s32 param_1, s32 param_2, s32 param_3, s32 param_4)
{
    WibbleSettings50 *local_0;
    s16 local_1[3];
    s16 local_2[3];
    f32 local_3;
    f32 local_4;
    f32 k = 0.0f; /* Vergleichswert als Local: Konstante steht links in c.eq.s */
    local_0 = (WibbleSettings50 *)func_80800324_idwibble(param_1);
    param_1 %= 100;
    _glidmake_entrypoint_2(param_2, param_3, local_1, local_2);
    param_0->local_2 = (local_1[1] + local_2[1]) / 2;
    func_800EE88C(param_0->local_0, local_1);
    func_800EE88C(param_0->local_1, local_2);
    param_0->local_4 = local_0->local_4 << 6;
    if (local_0->local_4) param_0->local_12 = 1;
    else param_0->local_12 = 0;
    local_3 = local_0->local_1;
    if (local_3 < 0.0f) {
        param_0->local_3 = -local_3;
        param_0->local_10 = 2;
    } else if (local_3 > 0.0f) {
        param_0->local_10 = 0;
        param_0->local_3 = local_3;
    } else {
        param_0->local_10 = 1;
        param_0->local_3 = (param_0->local_1[1] - param_0->local_0[1]) * 0.5f;
    }
    local_4 = param_0->local_3;
    if (k == local_4) {
        param_0->local_3 = 1;
        local_4 = param_0->local_3;
    }
    param_0->local_5 = (f32)(u32)local_0->local_3 / local_4;
    param_0->local_9 = 255 - local_0->local_3;
    if (local_0->local_3) param_0->local_11 = 1;
    else param_0->local_11 = 0;
    param_0->local_6 = 0.0f;
    param_0->local_7 = 6.2831855f / local_0->local_0;
    local_3 = local_0->local_2;
    if (local_3 < 0.0f) param_0->local_8 = -local_3;
    else param_0->local_8 = param_1 * local_3;
    param_0->local_13 = 0;
    if (param_4 != 1 && param_4 != 2) param_0->local_15 = 1;
    else param_0->local_15 = 0;
}

void idwibble_entrypoint_3(WibbleState *param_0, s32 param_1, s32 param_2)
{
    f32 local_0[3];
    f32 local_1[3];

    param_0->local_2 += func_800D8FF8() * param_0->local_3;
    func_800EE7F8(local_0, param_0->local_0);
    func_800EE7F8(local_1, param_0->local_1);
    local_0[1] += param_0->local_4;
    local_1[1] += param_0->local_4;
    if (param_0->local_5 || func_800E3D0C(param_0->local_0, param_0->local_1)) {
        _glid_entrypoint_0(param_1, param_2, _idwibble_entrypoint_0, param_0);
    }
}

void idwibble_entrypoint_4(f32 *param_0, s32 param_1, s32 param_2) {
    param_0[9] += func_800D8FF8() * param_0[11];
    _glid_entrypoint_0(param_1, param_2, _idwibble_entrypoint_0);
}

void idwibble_entrypoint_5(param_0, param_1) s32 param_0; s16 param_1; {
    *(s16 *)(param_0 + 0x34) = param_1;
}
