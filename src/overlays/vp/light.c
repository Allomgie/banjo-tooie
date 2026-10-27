#include "common.h"

typedef struct { u8 pad_0[0x10]; u16 local_0; u8 pad_1[2]; s32 local_1; u8 pad_2[4]; s32 local_2; } LightGridDefinition;
typedef struct { u16 local_0; u16 local_1; } LightGridSourceState;
typedef struct { u8 pad_0[0x14]; LightGridSourceState local_0[1]; } LightGridSource;
typedef struct { u8 pad_0[0x10]; s32 local_0; } LightGridRecord;
typedef struct { u8 local_0; u8 local_1; u8 pad_0[14]; } LightGridState;
typedef struct { s16 local_0[3]; s16 local_1[3]; u8 pad_0[12]; f32 local_2; } LightGridBounds;
typedef struct { u8 used; u8 n; u8 h[14]; } VpCell;
typedef struct { u8 pad0[3]; u8 dirty; u8 pad4[16]; } VpCellOut;
typedef struct { u8 pad0[0xC]; u16 w; u16 plane; u8 pad10[4]; s32 count; u8 pad18[4]; s32 outOffset; } VpGrid;
extern s32 func_800C8760(s32, s32);
extern s32 func_800C89D8(s32);
extern s32 func_800C8800(s32, f32 *);
extern void func_800C883C(s32, f32 *);
extern s32 func_800C878C(s32, s32, s32);
extern void func_800C8898(s32, f32[3]);
typedef struct { u8 local_0; u8 local_1; u8 local_2[14]; } VpLightGroup62;
extern void func_800C8900(s32, s32 *);
extern f32 sqrtf(f32);

void *vplight_entrypoint_0(LightGridDefinition *param_0, LightGridSource *param_1)
{
    LightGridState *local_0;
    LightGridState *local_1;
    LightGridRecord *local_2;
    LightGridSourceState *local_3;
    LightGridSourceState *local_4;
    s16 *local_5;
    s16 *local_6;
    s16 *local_7;
    LightGridSourceState *local_9;
    s32 local_8;

    local_8 = param_0->local_0 * sizeof(s16) + param_0->local_1 * sizeof(LightGridState);
    local_0 = heap_alloc(local_8);
    rare_memset(local_0, 0, local_8);
    if (1) {}
    local_5 = (s16 *)((u8 *)local_0 + param_0->local_1 * sizeof(LightGridState));
    local_7 = local_5 + param_0->local_0;
    for (local_6 = local_5; local_6 < local_7;) {
        *local_6++ = -1;
    }
    local_4 = param_0->local_1 + param_1->local_0;
    local_2 = (LightGridRecord *)((u8 *)param_0 + param_0->local_2);
    local_9 = param_1->local_0;
    local_1 = local_0;
    local_3 = local_9;
    for (; local_3 < local_4; local_3++, local_1++) {
        if (local_3->local_1) {
            local_1->local_0 = 1;
            local_1->local_1 = 0;
            local_5[((local_3 - local_9) + local_2)->local_0] = local_3 - local_9;
        }
    }
    return local_0;
}

void vplight_entrypoint_1(void* arg0) 
{
    heap_free(arg0);
}
void func_80800134_vplight(LightGridBounds *param_0, f32 param_1[3],
    f32 param_2, s32 param_3[3], s32 param_4[3])
{
    s32 local_0;
    s32 local_1;
    s32 local_2;
    f32 local_3;
    f32 local_4;
    s32 local_5;
    s32 local_6;

    for (local_0 = 0; local_0 < 3; local_0++) {
        local_3 = param_1[local_0] - param_2;
        local_4 = param_1[local_0] + param_2;
        local_1 = param_0->local_2 * local_3;
        local_2 = param_0->local_2 * local_4;
        if (local_3 < 0.0f) {
            local_1--;
        }
        if (local_4 < 0.0f) {
            local_2--;
        }
        local_5 = param_0->local_0[local_0];
        local_6 = param_0->local_1[local_0];
        if (local_1 < local_5) {
            local_1 = local_5;
        }
        if (local_1 > local_6) {
            local_1 = local_6;
        }
        if (local_2 < local_5) {
            local_2 = local_5;
        }
        if (local_2 > local_6) {
            local_2 = local_6;
        }
        param_3[local_0] = local_1 - local_5;
        param_4[local_0] = local_2 - local_5;
    }
}

void vplight_entrypoint_2(VpCell *param_0, VpGrid *param_1)
{
    VpCellOut *out;
    VpCell *fp;
    VpCell *end;
    s16 *tbl;
    s32 handle;
    s32 flag;
    f32 pos[3];
    f32 range[2];
    s32 lo[3];
    s32 hi[3];
    VpCell *rec;
    s32 k;
    s32 x;
    s32 y;
    s32 z;
    s32 i;
    s32 idx;
    s32 j;
    VpCell *cells;

    cells = param_0;
    end = cells + param_1->count;
    tbl = (s16 *)(cells + param_1->count);
    out = (VpCellOut *)((u8 *)param_1 + param_1->outOffset);
    handle = func_800C8760(2, 2);
    if (handle == 0) {
        return;
    }
    do {
        flag = func_800C89D8(handle);
        for (fp = cells; fp < end; fp++) {
            if (fp->used != 0 && fp->n != 0) {
                for (k = 0; k != 14; k++) {
                    if (fp->h[k] == handle) {
                        if (flag) {
                            fp->h[k] = 0;
                            fp->n--;
                        }
                        out[fp - cells].dirty = 1;
                        break;
                    }
                }
            }
        }
        if (flag) {
            func_800C8800(handle, pos);
            func_800C883C(handle, range);
            func_80800134_vplight(param_1, pos, range[1], lo, hi);
            for (z = lo[2]; z <= hi[2]; z++) {
                for (y = lo[1]; y <= hi[1]; y++) {
                    for (x = lo[0]; x <= hi[0]; x++) {
                        idx = param_1->plane * z + x + y * param_1->w;
                        i = tbl[idx];
                        if (i >= 0) {
                            rec = cells + i;
                            if (rec->used != 0) {
                                for (j = 0; j != 14; j++) {
                                    if (rec->h[j] == 0) {
                                        rec->h[j] = handle;
                                        rec->n++;
                                        ((VpCellOut *)(i * 20 + (s32)out))->dirty = 1;
                                        break;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        handle = func_800C878C(handle, 2, 2);
    } while (handle != 0);
}

s32 func_808004B0_vplight(s32 param_0, s32 *param_1) {
    f32 local_0[3];

    func_800C8800(param_0, local_0);
    param_1[0] = (s32)local_0[0];
    param_1[1] = (s32)local_0[1];
    param_1[2] = (s32)local_0[2];
}

void func_80800518_vplight(s32 param_0, s32 *param_1)
{
    f32 local_0[3];

    func_800C8898(param_0, local_0);
    param_1[0] = (s32)(local_0[0] * 256.0f);
    param_1[1] = (s32)(local_0[1] * local_0[1]);
    param_1[2] = (s32)(local_0[2] * 16384.0f);
}

void vplight_entrypoint_3(VpLightGroup62 *param_0, s32 param_1, Vtx *param_2, s32 param_3)
{
    VpLightGroup62 *local_3;
    s32 local_0[5];
    s32 local_1[3];
    s32 local_2[3];
    Vtx *local_4;
    Vtx *local_5;
    s32 local_6;
    s32 local_7;
    s32 local_8;
    s32 local_9;
    s32 local_10;
    s32 local_11; /* unused, holds a frame slot (removing it: metric 16) */
    s32 local_12;

    local_3 = &(param_0 + 0)[param_1];
    if (local_3->local_1) {
        local_5 = param_2 + param_3;
        local_6 = 0;
        do {
            if (local_3->local_2[local_6]) break;
            local_6++;
        } while (local_6 < 14);
        if (param_2) {} /* PROBE: empty test, raises param_2 priority (s7 vs fp) */
        for (; local_6 < 14; local_6++) {
            if (local_3->local_2[local_6]) {
                func_808004B0_vplight(local_3->local_2[local_6], local_0);
                func_80800518_vplight(local_3->local_2[local_6], local_1);
                func_800C8900(local_3->local_2[local_6], local_2);
                if (local_5) {} /* PROBE: empty test after the 3 calls, splits end ptr into fp + s4 copy */
                for (local_4 = param_2; local_4 < local_5; local_4++) {
                    local_7 = local_0[0] - local_4->v.ob[0];
                    local_8 = local_0[1] - local_4->v.ob[1];
                    local_9 = local_0[2] - local_4->v.ob[2];
                    local_10 = local_7 * local_7 + local_8 * local_8 + local_9 * local_9;
                    if (local_10 < local_1[1]) {
                        if (local_10 != 0) local_10 = sqrtf((f32)local_10) * 256.0f;
                        local_9 = local_1[0];
                        if (local_9 < local_10) {
                            local_7 = 0x4000 - (((local_10 - local_9) * local_1[2]) >> 8);
                            local_8 = local_7 << 2;
                        } else {
                            local_8 = 0x10000;
                        }
                        local_12 = local_4->v.cn[0] + ((local_2[0] * local_8) >> 16);
                        if (local_12 >= 256) local_12 = 255;
                        local_4->v.cn[0] = local_12;
                        local_12 = local_4->v.cn[1] + ((local_2[1] * local_8) >> 16);
                        if (local_12 >= 256) local_12 = 255;
                        local_4->v.cn[1] = local_12;
                        local_12 = local_4->v.cn[2] + ((local_2[2] * local_8) >> 16);
                        if (local_12 >= 256) local_12 = 255;
                        local_4->v.cn[2] = local_12;
                    }
                }
            }
        }
    }
}

void vplight_entrypoint_4(Vtx *param_0, s32 param_1)
{
    Vtx *local_0;
    s32 local_5;
    s32 local_6;
    s32 local_7;
    s32 local_8;
    s32 local_9;
    s32 local_10;
    s32 local_11;
    s32 local_12;
    s32 local_13;
    s32 local_3[3];
    s32 local_2[3];
    s32 local_1[3];
    s32 local_4;
    s32 dz; /* intermediate value for local_10: splits local_10's live ranges */
    local_0 = param_0 + param_1;
    for (; param_0 < local_0; param_0++) {
        local_4 = param_0->v.cn[0];
        local_5 = param_0->v.cn[1];
        local_6 = param_0->v.cn[2];
        local_7 = func_800C8760(0, 4);
        while (local_7) {
            func_808004B0_vplight(local_7, local_3);
            func_80800518_vplight(local_7, local_2);
            func_800C8900(local_7, local_1);
            if (1) {} /* SONDE: leerer Block, ohne ihn Metrik 21 (Registerfaerbung) */
            local_8 = local_3[0] - param_0->v.ob[0];
            local_9 = local_3[1] - param_0->v.ob[1];
            dz = local_3[2] - param_0->v.ob[2];
            local_10 = dz;
            local_11 = local_8 * local_8 + local_9 * local_9 + local_10 * local_10;
            local_12 = local_11;
            if (local_11 < local_2[1]) {
                /* Bedingung = wiederholter Ausdruck statt local_11 (CSE, Permuter-Fund 26.10.) */
                if (local_8 * local_8 + local_9 * local_9 + local_10 * local_10) local_12 = sqrtf((f32)local_11) * 256.0f;
                local_10 = local_2[0];
                if (local_10 < local_12) {
                    local_9 = 0x4000 - (((local_12 - local_10) * local_2[2]) >> 8);
                    local_13 = local_9 << 2;
                } else {
                    local_13 = 0x10000;
                }
                local_4 += (local_1[0] * local_13) >> 16;
                local_5 += (local_1[1] * local_13) >> 16;
                local_6 += (local_1[2] * local_13) >> 16;
            }
            local_7 = func_800C878C(local_7, 0, 4);
        }
        if (local_4 >= 256) local_4 = 255;
        if (local_5 >= 256) local_5 = 255;
        if (local_6 >= 256) local_6 = 255;
        param_0->v.cn[0] = local_4;
        param_0->v.cn[1] = local_5;
        param_0->v.cn[2] = local_6;
    }
}
