#include "common.h"

typedef struct { u8 pad_0[0x16]; u16 pad_1 : 15; u16 local_0 : 1; } DBMorphModel;
extern Vtx *func_800B2190(void *);
extern void *func_80100480(s32, s32);
extern void *func_800ADE2C(void *, s32);

u8 *func_80800000_dbmorph(param_0, param_1) s16 *param_0; s32 param_1; {
    s32 i;
    u8 *local_0 = (u8 *)(param_0 + 2);
    for (i = 0; i < *param_0; i++) {
        if (local_0[2] == param_1) {
            return local_0;
        }
        local_0 += *(s32 *)(local_0 + 8);
    }
    return 0;
}

s32 dbmorph_entrypoint_0(s32 param_0) {
    return *(s16 *)(param_0 + 0x2);
}

int dbmorph_entrypoint_1(s16 *param_0) {
    return param_0[0];
}

u8 dbmorph_entrypoint_2(void) {
    return *(u8 *)((u8 *)func_80800000_dbmorph() + 3);
}

void dbmorph_entrypoint_3(void *param_0, DBMorphModel *param_1, void *param_2, s32 param_3, f32 *param_4)
{
    s16 local_14;
    f32 local_23;
    s16 *local_6;
    s32 local_20;
    u8 *local_5;
    Vtx *local_2;
    Vtx *local_7;
    Vtx *local_4;
    u8 *local_0;
    Vtx *local_1;
    s32 local_18;
    s16 local_15;
    s32 local_17;
    s32 local_16;
    s32 local_9;
    s16 local_11;
    s32 local_22;
    s16 local_13;
    s16 local_12;
    Vtx *local_3;
    s32 local_19;
    s32 k = -1;

    local_22 = param_1->local_0;

    local_0 = func_80800000_dbmorph(param_0, param_3);

    local_1 = func_800B2190(param_2);
    local_2 = func_800B2190(param_1);

    local_3 = *(s16 *)(local_0 + 4) + local_1;
    local_4 = *(s16 *)(local_0 + 4) + local_2;

    if (local_22 != 0) {
        local_9 = *(s16 *)(local_0 + 6);

        if (local_9 != 0) {
            do {
                if (local_3->v.flag & 0x4000) {
                    aligned4_memcpy(local_4, local_3, sizeof(Vtx));
                    local_9--;
                }

                local_4++;
                local_3++;
            } while (local_9 != 0);

        }
        local_22 = 0;
    }

    local_5 = local_0 + 0xC;

    for (local_9 = 0; local_9 < local_0[3]; local_9++) {
            local_23 = *param_4++;

            if (local_23 != 0.0f) {
                local_7 = (Vtx *)(local_5 + 4);
                local_6 = (s16 *)(local_5 + *(s16 *)local_5 * 0x10 + 4);
                local_20 = *local_6;
                local_11 = (s16)(local_7->v.ob[0] * local_23);
                local_12 = (s16)(local_7->v.ob[1] * local_23);
                local_13 = (s16)(local_7->v.ob[2] * local_23);
                local_16 = local_7->v.cn[0];
                local_17 = local_7->v.cn[1];
                local_18 = local_7->v.cn[2];
                local_19 = local_7->v.cn[3];
                local_14 = (s16)(local_7->v.tc[0] * local_23);
                local_15 = (s16)(local_7->v.tc[1] * local_23);


                local_22 = 1;


                while (local_20 >= -1) {
                    if (k == local_20) {
                        local_7++;

                        local_11 =
                            (s16)(local_7->v.ob[0] * local_23);
                        local_12 =
                            (s16)(local_7->v.ob[1] * local_23);
                        local_13 =
                            (s16)(local_7->v.ob[2] * local_23);
                        local_14 =
                            (s16)(local_7->v.tc[0] * local_23);
                        local_15 =
                            (s16)(local_7->v.tc[1] * local_23);

                        local_16 = local_7->v.cn[0];
                        local_17 = local_7->v.cn[1];
                        local_18 = local_7->v.cn[2];
                        local_19 = local_7->v.cn[3];
                    } else {
                        local_4 = local_2 + local_20;
                        local_3 = local_1 + local_20;
                        local_20 *= 1;

                        local_4->v.ob[0] += local_11;
                        local_4->v.ob[1] += local_12;
                        local_4->v.ob[2] += local_13;
                        local_4->v.tc[0] += local_14;
                        local_4->v.tc[1] += local_15;

                        local_4->v.cn[0] += (local_16 - local_3->v.cn[0]) * local_23;
                        local_4->v.cn[1] += (local_17 - local_3->v.cn[1]) * local_23;
                        local_4->v.cn[2] += (local_18 - local_3->v.cn[2]) * local_23;
                        local_4->v.cn[3] += (local_19 - local_3->v.cn[3]) * local_23;
                    }

                    local_20 = *++local_6;
                }

                local_6++;
            } else {
                local_6 = (s16 *)(*(s16 *)local_5 * 0x10 + (0, local_5) + 4);
                while (-2 != *local_6++) {}
            }

            if ((u32)local_6 & 3) {
                local_6++;
            }

            local_5 = (u8 *)local_6;
    }

    param_1->local_0 = local_22;
}

void dbmorph_entrypoint_4(void *param_0, u8 *param_1, void *param_2, u32 param_3, void *param_4)
{
    s32 local_6;
    s16 *local_5;
    s16 *local_4;
    s32 local_1;
    Vtx *local_2;
    Vtx *local_3;
    s16 *local_0;

    local_0 = func_80800000_dbmorph(param_0, param_3);
    local_1 = local_0[3];
    local_2 = func_800B2190(param_1);

    if (*(u16 *)(param_1 + 0x16) & 1) local_3 = local_2 + local_0[2];
    else local_3 = local_0[2] + func_800B2190(param_2);
    local_4 = func_80100480(4, local_1);
    local_5 = local_4;
    local_6 = local_1;
    if (local_1) {
        do {
            if (local_3->v.flag & 0x4000) {
                *local_5++ = local_3->v.ob[0];
                *local_5++ = local_3->v.ob[1];
                *local_5++ = local_3->v.ob[2];
                local_6--;
            }
            local_3++;
        } while (local_6);
    }
    local_6 = local_1;
    func_80116568(func_800ADE2C(param_4, local_0[0]), local_4, local_4, local_1);
    local_3 = local_2 + local_0[2];
    local_5 = local_4;
    if (local_1) {
        do {
            if (local_3->v.flag & 0x4000) {
                local_3->v.ob[0] = *local_5++;
                local_3->v.ob[1] = *local_5++;
                local_3->v.ob[2] = *local_5++;
                local_6--;
            }
            local_3++;
        } while (local_6);
    }
}

/* TU-NOTE: the .data of this overlay (formerly asm/data/overlays/db/morph.data.s) is defined here in C.
 * Values are taken from the ROM. */
