#include "common.h"

typedef struct { u8 pad_0[0x10]; u16 offset; u16 pad_1; s32 count; } LightMesh1400;
extern u8 *func_800B2190(void *);
extern s8 *_dbvtxnormal_entrypoint_0(s32, s32);
extern s32 func_800C8760(s32, s32);
extern void func_800C8800(s32, f32 *);
extern void func_800C8898(s32, f32 *);
extern void func_800C8900(s32, s32 *);
extern s32 func_800C878C(s32, s32, s32);
extern f32 sqrtf(f32);

void dblight_entrypoint_0(LightMesh1400 *param_0, void *param_1, u32 *param_2)
{
    u8 *local_1;
    s32 local_2;
    s32 local_3;
    u8 *local_4;
    s16 *local_0;

    if (param_2[0] != 255 || param_2[1] != 255 || param_2[2] != 255) {
        local_0 = (s16 *)(param_0->offset * 4 + (u8 *)param_0 + 0x18);
        local_1 = func_800B2190(param_1);
        for (local_2 = 0; local_2 < param_0->count; local_2++, local_0++) {
            local_4 = local_1 + *local_0 * 16;
            for (local_3 = 0; local_3 < 3; local_3++) {

                local_4[local_3 + 0xC] = (s32)(local_4[local_3 + 0xC] * param_2[local_3]) >> 8;
            }
        }
    }
}

void dblight_entrypoint_1(u8 *param_0, s32 param_1, s32 param_2)
{
    s32 light;
    s16 *end;
    s32 r;
    u8 *base;
    s32 g;
    s32 b;
    f32 nx;
    f32 ny;
    f32 nz;
    f32 dist;
    f32 f2;
    f32 f0;
    u8 *vtx;
    f32 spA8[3];
    f32 sp9C[3];
    s32 sp90[3];
    f32 sp84[3];
    s16 *idx;
    s8 *nrm;
    s32 fl0;
    base = func_800B2190(param_1);
    idx = (s16 *)(param_0 + *(u16 *)(param_0 + 0x10) * 4 + 0x18);
    end = idx + *(s32 *)(param_0 + 0x14);
    for (; idx < end; idx++) {
        vtx = base + *idx * 16;
        nrm = _dbvtxnormal_entrypoint_0(param_2, *idx);
        if (1) {}
        r = vtx[0xC];
        g = vtx[0xD];
        nx = nrm[0] * 0.007874015f;
        ny = nrm[1] * 0.007874015f;
        b = vtx[0xE];
        nz = nrm[2] * 0.007874015f;
        light = func_800C8760(0, 4);
        if (light != 0) {
            do {
                func_800C8800(light, sp84);
                spA8[0] = sp84[0] - *(s16 *)(vtx + 0);
                spA8[1] = sp84[1] - *(s16 *)(vtx + 2);
                spA8[2] = sp84[2] - *(s16 *)(vtx + 4);
                dist = sqrtf(spA8[0] * spA8[0] + spA8[1] * spA8[1] + spA8[2] * spA8[2]);
                func_800C8898(light, sp9C);
                if (!(sp9C[1] < dist)) {
                    func_800C8900(light, sp90);
                    if (dist != 0.0f) {
                        f0 = 1.0f / dist;
                        spA8[0] = spA8[0] * f0;
                        spA8[1] = spA8[1] * f0;
                        spA8[2] = spA8[2] * f0;
                        f2 = spA8[0] * nx + spA8[1] * ny + spA8[2] * nz;
                        if (f2 < 0) {
                            if (!(*(u16 *)(vtx + 6) & 0x8000)) {
                                goto next;
                            }
                            f2 = -f2;
                        }
                        sp90[0] = (s32)(sp90[0] * f2);
                        sp90[1] = (s32)(sp90[1] * f2);
                        sp90[2] = (s32)(sp90[2] * f2);
                    }
                    if (dist <= sp9C[0]) {
                        r += sp90[0];
                        g += sp90[1];
                        b += sp90[2];
                    } else {
                        f0 = 1.0f - ((dist - sp9C[0]) * sp9C[2]);
                        r += f0 * sp90[0];
                        g += f0 * sp90[1];
                        b += f0 * sp90[2];
                    }
                }
next:
                light = func_800C878C(light, 0, 4);
            } while (light != 0);
        }
        if (r >= 0x100) {
            r = 0xFF;
        }
        if (g >= 0x100) {
            g = 0xFF;
        }
        if (b >= 0x100) {
            b = 0xFF;
        }
        vtx[0xC] = r;
        vtx[0xD] = g;
        vtx[0xE] = b;
    }
}
