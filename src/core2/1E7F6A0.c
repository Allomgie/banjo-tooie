#include "common.h"

#define A6250_CMD(head, first, second) { \
    A6250Command *local_command = (*(head))++; \
    local_command->word0 = (first); \
    local_command->word1 = (second); \
}
extern f32 func_800F10B4(f32, f32, f32, f32, f32);
extern void func_800EF334(f32 *, f32);
extern void func_800EE780(f32 *, f32 *, f32 *);
extern void *func_800D674C(s32);
extern void *func_800DE448(f32 *, f32 *, f32, f32 *, s32);
extern f32 func_800F554C(s32);
extern int func_800F1988(f32 *, f32 *, f32 *);
extern void func_800DF830(s32);
extern Gfx D_8011A2F8[];
extern Gfx D_8011A350[];
struct __OSBlockInfo { u32 field0; u32 field4; u32 field8; u32 fieldC; };
extern struct __OSBlockInfo D_8011A380;
extern struct __OSBlockInfo D_8011A390;
extern void func_800DF580(struct __OSBlockInfo *, struct __OSBlockInfo *);
typedef struct { u32 word0, word1; } A6250Command;
extern s32 func_800F53D0(u32);
extern s32 func_800F5410(u32);
extern s32 _bapreload_entrypoint_1(s32, s32 *);
extern void *func_80092B04(s32, s32);
extern void func_800F274C(f32 [4][4]);
extern f32 func_800EEAA4(f32 *, f32 *);
extern f32 func_80013A7C(f32);
extern void func_800EE97C(f32 *, f32 *, f32 *);
extern void func_800F254C(f32 [4][4], f32 *, f32);
extern void func_800F23D0(f32 [4][4], f32 *, f32 *);
extern void func_80019CD4(void);
extern f32 func_80092BE8(s32);
extern f32 func_8009BFCC(s32);
extern f32 baroll_get(s32);
extern void mlMtxRotYaw(f32);
extern void mlMtxRotPitch(f32);
extern void mlMtxRotRoll(f32);
extern void mlMtxGet(f32 [4][4]);
extern void func_800F27D4(f32 [4][4], f32 [4][4], f32 [4][4]);
extern void *func_8008CA74(s32);
extern void func_800DF41C(void *);
extern void **func_800DF330(void);
extern void *func_800B27E0(void *);
extern void *func_80092E80(s32);
extern void func_800AE708(void *, void *, void **, void *);
extern void func_800DF72C(void *);
extern void func_800A06E8(s32);
extern void func_800DF540(f32 [4][4]);
extern A6250Command **func_800A7180(void);
extern void *func_8001575C(void);
extern f32 func_80092BDC(s32);
extern s32 func_80092738(s32);
extern void _babackpack_entrypoint_2(s32);
extern f32 _babackpack_get_scale(s32);
extern void *_babackpack_entrypoint_1(s32);
extern void func_800E7CF4(A6250Command **);
extern void *func_800B2840(void *);
extern f32 func_800B2354(void *);
extern void func_800EF04C(f32 *, f32 *);
extern void func_800E4190(f32 *, f32 *, s32 *);
extern s32 func_800C6A7C(s32 *param_0, s32 *param_1, f32 *param_2, s32 param_3);
extern void func_800EE7F8();
extern void func_800F5680(s32 param_0, f32 *param_1);
extern f32 mlAbsF(f32 param_0);
extern void func_800EF174();
typedef struct { u8 pad_0[0x7E]; u8 local_0 : 3; u8 local_1 : 1; u8 local_2 : 4; } Struct800A69F0;
typedef struct { s32 pad; f32 local_0[3]; u8 pad1[0x14]; f32 local_1; u8 pad2[0x4E]; u16 local_2; } ActorA6B24;
extern f32 func_800F5BC4(s32, f32 *);
extern f32 sqrtf(f32);
extern void func_800EFB24(f32 *, f32 *, f32 *);
extern void func_800EFD24(f32 *);
extern void func_800EFA4C(f32 *, f32, f32, f32);
extern void *func_800C8760(s32, s32);
extern void *func_800C878C(void *, s32, s32);
extern s32 func_800C89A8(void *);
extern void func_800C8800(void *, f32 *);
extern void func_800C8898(void *, f32 *);
typedef struct { u8 pad[0x58]; f32 scale; u8 pad1[0x18]; u32 unused:2, blocked:1, rest:29; } LocalActor;
extern s16 D_8011A2E0[];
typedef struct { u8 pad0[4]; f32 unk4[3]; u8 pad10[0x14]; f32 unk24; u8 pad28[0x3C]; u32 pad64 : 11; u32 flag64 : 1; u32 pad64b : 20; u8 pad68[0xC]; u32 pad74 : 1; u32 flag74_1 : 1; u32 flag74_2 : 1; u32 pad74b : 13; u16 id : 9; u16 pad76 : 7; } S800A6FF0;
extern void func_800F5A00(s32, f32 *);
extern f32 func_800F5628(s32);
extern s32 func_800F8874(s32);
typedef struct { u8 pad0[0x65]; u8 f0 : 7; u8 bit : 1; u8 pad66[0x10]; u16 hi : 9; u16 lo : 7; } S_A70D0;
extern S_A70D0 *func_80106790(s32);
extern s32 D_8011A3A0;

void func_800A5DB0(u8 *param_0) {
    s32 local_6;
    f32 local_0[3];
    f32 local_1[3];
    f32 local_2;
    f32 local_3;
    f32 local_4[3];
    f32 local_5;
    func_800EE7F8(local_0, (f32 *)(param_0 + 4));
    local_3 = *(f32 *)(param_0 + 0x24);
    local_5 = func_800F10B4(local_0[1] - local_3, 0.0f, 300.0f, 0.43f, 0.28f);
    local_2 = func_800F554C((u32)*(u16 *)(param_0 + 0x76) >> 7);
    local_2 *= local_5 * *(f32 *)(param_0 + 0x58);
    local_0[1] = local_3;
    func_800F5680((u32)*(u16 *)(param_0 + 0x76) >> 7, local_4);
    func_800F1988(local_4, (f32 *)(param_0 + 0x44), (f32 *)(param_0 + 0x48));
    local_1[0] = *(f32 *)(param_0 + 0x44);
    local_1[1] = *(f32 *)(param_0 + 0x48);
    local_1[2] = 0.0f;
    func_800EF334(local_4, 0);
    func_800EE780((f32 *)(param_0 + 4), local_0, local_4);
    func_800DF830(3);
    func_800DE448((f32 *)(param_0 + 4), local_1, local_2, 0, (s32)func_800D674C(0x637));
}

void func_800A5EC4(Gfx **param_0, void *param_1, s32 param_2, s32 param_3, s32 param_4, s32 param_5, s32 param_6)
{
    Gfx *local_0;
    s32 local_1;
    s32 local_2;

    local_0 = *param_0;
    if (param_4) {
        param_4 = (param_4 + 15) & 0xFFF0;
        if (param_5) {
            local_1 = 4096 / param_4;
            /* SPDisplayList, DPSetBlendColor, DPSetPrimColor */
            do {
                { Gfx *_g = local_0++; _g->words.w0 = 0xDE000000; _g->words.w1 = (u32)((u8 *)D_8011A2F8 - 0x80000000); } { Gfx *_g = local_0++; _g->words.w0 = 0xF9000000; _g->words.w1 = 1; }
                { Gfx *_g = local_0++; _g->words.w0 = 0xFA000000; _g->words.w1 = ((param_6 << 7) / 255) & 0xFF; }
            } while (0);
            local_2 = param_3 + param_5;
            /* DPSetTextureImage (CI, 8b, Breite 304), DPSetTile 7 und 0 */
            { Gfx *_g = local_0++; _g->words.w0 = 0xFD48012F; _g->words.w1 = osVirtualToPhysical(param_1); }
            { Gfx *_g = local_0++; _g->words.w0 = 0xF5480000 | ((((param_4 + 7) >> 3) & 0x1FF) << 9); _g->words.w1 = 0x07080200; }
            { Gfx *_g = local_0++; _g->words.w0 = 0xF5480000 | ((((param_4 + 7) >> 3) & 0x1FF) << 9); _g->words.w1 = 0x00080200; }
            for (; param_3 < local_2; param_3 += local_1) {
                if (local_2 - param_3 < local_1) {
                    local_1 = local_2 - param_3;
                }
                /* DPLoadSync, DPLoadTile 7, DPSetTileSize 0 */
                { Gfx *_g = local_0++; _g->words.w0 = 0xE6000000; _g->words.w1 = 0; } { Gfx *_g = local_0++; _g->words.w0 = 0xF4000000 | (((param_2 << 2) & 0xFFF) << 12) | ((param_3 << 2) & 0xFFF); _g->words.w1 = (7 << 24) | ((((param_2 + param_4 - 1) << 2) & 0xFFF) << 12) | (((param_3 + local_1 - 1) << 2) & 0xFFF); } { Gfx *_g = local_0++; _g->words.w0 = 0xF2000000 | (((param_2 << 2) & 0xFFF) << 12) | ((param_3 << 2) & 0xFFF); _g->words.w1 = (0 << 24) | ((((param_2 + param_4 - 1) << 2) & 0xFFF) << 12) | (((param_3 + local_1 - 1) << 2) & 0xFFF); }
                /* SPTextureRectangle: TEXRECT, RDPHALF_1 (s, t), RDPHALF_2 (dsdx, dtdy = 1.0) */
                { Gfx *_g = local_0++; _g->words.w0 = 0xE4000000 | ((((param_2 + param_4) * 4) & 0xFFF) << 12) | (((param_3 + local_1) * 4) & 0xFFF);
                  _g->words.w1 = (((param_2 * 4) & 0xFFF) << 12) | ((param_3 * 4) & 0xFFF); }
                { Gfx *_g = local_0++; _g->words.w0 = 0xE1000000; _g->words.w1 = (((param_2 << 5) & 0xFFFF) << 16) | ((param_3 << 5) & 0xFFFF); }
                { Gfx *_g = local_0++; _g->words.w0 = 0xF1000000; _g->words.w1 = 0x04000400; }
            }
            /* SPDisplayList */
            { Gfx *_g = local_0++; _g->words.w0 = 0xDE000000; _g->words.w1 = (u32)((u8 *)D_8011A350 - 0x80000000); }
            *param_0 = local_0;
        }
    }
}

void func_800A61D4(void) {
    struct __OSBlockInfo local_0 = D_8011A380;
    struct __OSBlockInfo local_1 = D_8011A390;
    func_800DF580(&local_0, &local_1);
    func_800DF830(3);
}

void func_800A6250(u8 *param_0, f32 *param_1, f32 *param_2, f32 *param_3, s32 param_4)
{
    f32 local_0[4][4];
    f32 local_1[4][4];
    s32 local_2;
    void *local_3;
    void *local_4;
    f32 local_6;
    s32 local_5;
    f32 local_28;
    f32 local_7[3];
    union { f32 matrix[4][4]; u64 alignment; } local_8;
    void **local_9;
    void *local_10;
    void *local_11;
    s32 local_25, local_26, local_27;

    local_2 = func_800F53D0((u32)*(u16 *)(param_0 + 0x76) >> 7);
    /* Keep this call separate: nesting it creates a hidden frontend stack home. */
    local_25 = func_800F5410((u32)*(u16 *)(param_0 + 0x76) >> 7);
    local_3 = func_800D674C(_bapreload_entrypoint_1(local_25, &local_5));
    local_4 = func_80092B04(local_2, 0);
    func_800F274C(local_0);
    local_6 = func_800EEAA4(param_3, param_2);
    /* Reject the degenerate/back-facing direction and limit shallow angles. */
    if (local_6 < 0.01f) return;
    if (local_6 < 0.4f) {
        local_28 = func_80013A7C(0.4f);
        func_800EE97C(local_7, param_2, param_3);
        func_800F254C(local_8.matrix, local_7, local_28);
        func_800F23D0(local_8.matrix, param_3, param_2);
        local_6 = func_800EEAA4(param_3, param_2);
    }
    /* Oblique projection: subtract the scaled outer product from identity.
     * Preserve the operand order used by the engine's matrix convention. */
    local_6 = 1.0f / local_6;
    local_0[0][0] = 1.0f - param_2[0] * param_3[0] * local_6;
    local_0[0][1] = -param_2[0] * param_3[1] * local_6;
    local_0[0][2] = -param_2[0] * param_3[2] * local_6;
    local_0[1][0] = -param_2[1] * param_3[0] * local_6;
    local_0[1][1] = 1.0f - param_2[1] * param_3[1] * local_6;
    local_0[1][2] = -param_2[1] * param_3[2] * local_6;
    local_0[2][0] = -param_2[2] * param_3[0] * local_6;
    local_0[2][1] = -param_2[2] * param_3[1] * local_6;
    local_0[2][2] = 1.0f - param_2[2] * param_3[2] * local_6;
    func_80019CD4();
    mlMtxRotYaw(func_80092BE8(local_2));
    mlMtxRotPitch(func_8009BFCC(local_2));
    mlMtxRotRoll(baroll_get(local_2));
    mlMtxGet(local_1);
    func_800F27D4(local_1, local_0, local_0);
    /* Select or transfer render data when the requested model is not current. */
    if (local_3 != local_4) {
        if (local_5) func_800DF41C(func_8008CA74(local_2));
        else {
            local_9 = func_800DF330();
            local_10 = func_800B27E0(local_4);
            local_11 = func_800B27E0(local_3);
            if (*local_9) {
                func_800AE708(func_80092E80(local_2), local_10, local_9, local_11);
                func_800DF72C(*local_9);
            }
        }
    } else func_800DF72C(func_80092E80(local_2));
    func_800A06E8(local_2);
    func_800DF540(local_0);
    func_800A61D4();
    {
    A6250Command **local_12;
    local_12 = func_800A7180();
    /* Synchronize, select the offscreen image, and configure its fill pass. */
    A6250_CMD(local_12, 0xE7000000, 0);
    A6250_CMD(local_12, 0xFF48012F, (u32)func_8001575C() + 0x80000000);
    A6250_CMD(local_12, 0xE3000800, 0);
    A6250_CMD(local_12, 0xE3000A01, 0x00300000);
    A6250_CMD(local_12, 0xF7000000, 0xFFFEFFFE);
    A6250_CMD(local_12, 0xE200001C, 0);
    A6250_CMD(local_12, 0xF64BC38C, 0);
    func_800DE448(param_1, 0, func_80092BDC(local_2), 0, local_3);
    /* Render the optional backpack through the same projection. */
    if (func_80092738(local_2)) {
        _babackpack_entrypoint_2(local_2);
        func_800DF540(local_0);
        func_800A61D4();
        func_800DE448(param_1, 0, _babackpack_get_scale(local_2), 0, _babackpack_entrypoint_1(local_2));
    }
    }
    {
    A6250Command **local_13;
    local_13 = func_800A7180();
    A6250_CMD(local_13, 0xE7000000, 0);
    func_800E7CF4(local_13);
    {
    f32 local_14[8][3];
    f32 local_15[8][2];
    s32 local_32;
    f32 local_min[2];
    f32 local_max[2];
    f32 local_30;
    f32 (*local_31)[2]; /* Retained unused frontend stack home. */
    f32 local_29;
    s32 local_imin[2];
    s32 local_imax[2];
    s32 local_33; /* Retained home: keeps the visibility output at sp+0x50. */
    s32 local_24;
    /* Build eight model-bound corners: x/z span +/-radius, y spans 0..radius. */
    local_29 = func_800B2354(func_800B2840(local_3)) * func_80092BDC(local_2);
    for (local_25 = 0; local_25 < 2; local_25++) {
        for (local_26 = 0; local_26 < 2; local_26++) {
            for (local_27 = 0; local_27 < 2; local_27++) {
                local_32 = local_25 * 4 + local_26 * 2 + local_27;
                local_14[local_32][0] = (local_25 ? -1.0f : 1.0f) * local_29;
                local_14[local_32][1] = (local_26 ? 0 : 1.0f) * local_29;
                local_14[local_32][2] = (local_27 ? -1.0f : 1.0f) * local_29;
            }
        }
    }
    for (local_25 = 0; local_25 < 8; local_25++) {
        func_800F23D0(local_0, local_14[local_25], local_14[local_25]);
        func_800EF04C(local_14[local_25], param_1);
    }
    for (local_25 = 0; local_25 < 8; local_25++) {
        /* Abort if any corner cannot supply a valid projected screen point. */
        func_800E4190(local_14[local_25], local_15[local_25], &local_24);
        if (!local_24) return;
    }
    /* Bound the projected corners, clip to 304x228, then truncate to pixels. */
    local_min[0] = local_max[0] = local_15[0][0];
    local_min[1] = local_max[1] = local_15[0][1];
    for (local_25 = 1; local_25 < 8; local_25++) {
        local_30 = local_15[local_25][0];
        if (local_30 < local_min[0]) local_min[0] = local_30;
        else if (local_max[0] < local_30) local_max[0] = local_30;
        local_30 = local_15[local_25][1];
        if (local_30 < local_min[1]) local_min[1] = local_30;
        else if (local_max[1] < local_30) local_max[1] = local_30;
    }
    if (local_min[0] < 0.0f) local_min[0] = 0.0f;
    if (local_min[0] > 304.0f) local_min[0] = 304.0f;
    if (local_max[0] < 0.0f) local_max[0] = 0.0f;
    if (local_max[0] > 304.0f) local_max[0] = 304.0f;
    if (local_min[1] < 0.0f) local_min[1] = 0.0f;
    if (local_min[1] > 228.0f) local_min[1] = 228.0f;
    if (local_max[1] < 0.0f) local_max[1] = 0.0f;
    if (local_max[1] > 228.0f) local_max[1] = 228.0f;
    local_imin[0] = local_min[0];
    local_imin[1] = local_min[1];
    local_imax[0] = local_max[0];
    local_imax[1] = local_max[1];
    /* Submit the resulting rectangle; the last two dimensions are extents. */
    func_800A5EC4(local_13, func_8001575C(), local_imin[0], local_imin[1], local_imax[0] - local_imin[0], local_imax[1] - local_imin[1], param_4);
    }
    }
}

s32 func_800A69F0(u8 *param_0, s32 *param_1, u8 *param_2, s32 param_3) {
    f32 local_0[3];
    f32 temp_f0;
    f32 local_2[3];
    f32 local_1;

    func_800EE7F8(param_1, param_0 + 4);
    temp_f0 = (*(f32 *)((s8 *)(param_0) + (0x24)));
    local_1 = temp_f0;
    if ((mlAbsF((*(f32 *)((s8 *)(param_1) + (4))) - temp_f0)
        < 0.1f)
        || (0.99f < (*(f32 *)((s8 *)(param_2) + (4))))) {
        func_800F5680((u32) (*(u16 *)((s8 *)(param_0) + (0x76))) >> 7, local_0);
        (*(f32 *)((s8 *)(param_1) + (4))) = temp_f0;
        func_800A6250(param_0, param_1, local_0, param_2, param_3);
        goto block_6;
    }
    func_800EE7F8(local_2, param_1);
    func_800EF174(param_1, param_2, 0xC4FA0000);
    if (func_800C6A7C(local_2, param_1, local_0, 0x20020) == 0) {
        return 1;
    }
    func_800A6250(param_0, param_1, local_0, param_2, param_3);
block_6:
    ((Struct800A69F0 *)param_0)->local_1 = 1;
    return 1;
}

void func_800A6B24(ActorA6B24 *param_0) {
    void *local_11;
    s32 local_12;
    f32 local_0[3];
    f32 local_8, local_9, local_10;
    f32 local_2[3], local_3[3], local_4[3];
    s32 local_14;
    s32 local_13;
    f32 local_6[3], local_7[3];
    if (param_0->local_0[1] - param_0->local_1 > 2000.0f) return;
    local_8 = func_800F5BC4((u32)param_0->local_2 >> 7, local_0);
    func_800EF04C(local_0, param_0->local_0);
    local_12 = 0;
    for (local_11 = func_800C8760(0, 1); local_11 && local_12 < 2; local_11 = func_800C878C(local_11, 0, 1)) {
        local_13 = 255;
        if (func_800C89A8(local_11) & 8) continue;
        func_800C8800(local_11, local_3);
        func_800C8898(local_11, local_4);
        func_800EFB24(local_2, local_3, local_0);
        local_9 = sqrtf(local_2[0] * local_2[0] + local_2[1] * local_2[1] + local_2[2] * local_2[2]);
        if (local_9 == 0.0f || local_9 >= local_4[1] + local_8) continue;
        local_10 = -1.0f / local_9;
        local_2[0] *= local_10;
        local_2[2] *= local_10;
        local_2[1] *= -local_10;
        local_2[0] = -local_2[0];
        local_2[2] = -local_2[2];
        local_9 -= local_8;
        if (local_9 > local_4[0]) {
            local_10 = 1.0f - (local_9 - local_4[0]) * local_4[2];
            local_13 = 255.0f * local_10;
        }
        func_800A69F0(param_0, local_3, local_2, local_13);
        local_12++;
    }
    if (!local_12) {
        func_800EFD24(local_6);
        func_800EFA4C(local_7, 0, 1.0f, 0);
        func_800A69F0(param_0, local_6, local_7, 255);
    }
}

void func_800A6DAC(u8 *param_0, s32 param_1)
{
    if ((func_800F6438(((u32)((u16) (*(u16 *)((s8 *)(param_0) + 0x76)))) >> 7) != 0) &&
        (func_800F6640(((u32)((u16) (*(u16 *)((s8 *)(param_0) + 0x76)))) >> 7) != 0) &&
        (func_800F6E80(((u32)((u16) (*(u16 *)((s8 *)(param_0) + 0x76)))) >> 7) != 0) &&
        !(func_800F55FC(((u32)((u16) (*(u16 *)((s8 *)(param_0) + 0x76)))) >> 7) & 0x80000000) &&
        ((func_800F65D0(((u32)((u16) (*(u16 *)((s8 *)(param_0) + 0x76)))) >> 7) != 0) ||
         (((u32)(*(s32 *)((s8 *)(param_0) + 0x74) << 1) >> 31) &&
          ((func_800F8B88() < 2) ||
           ((func_800F5410(((u32)((u16) (*(u16 *)((s8 *)(param_0) + 0x76)))) >> 7) == 0xB) &&
            (_plsu_entrypoint_1(0x11) != -1))))))
    {
        func_800F5A00(((u32)((u16) (*(u16 *)((s8 *)(param_0) + 0x76)))) >> 7, param_0 + 4);
        (*(f32 *)((s8 *)(param_0) + 0x24)) =
            func_800F5628(((u32)((u16) (*(u16 *)((s8 *)(param_0) + 0x76)))) >> 7);
        if (((u32)(*(s32 *)((s8 *)(param_0) + 0x64) << 11) >> 31))
        {
            func_800A5DB0(param_0);
            return;
        }
        func_800A6B24(param_0);
    }
}

void func_800A6EF4(LocalActor *param_0)
{
    s32 local_1;
    s32 local_0;
    local_0 = func_800EA05C();
    func_8010A800(param_0, 5);
    param_0->blocked = 0;
    param_0->scale = 1.0f;
    for (local_1 = 0; D_8011A2E0[local_1] != -1; local_1++) {
        if (local_0 == D_8011A2E0[local_1]) {
            param_0->blocked = 1;
            break;
        }
    }
    if ((func_800A9C98() && func_800A9CD0() != 2) || func_800BCC84() || func_800D3948() || func_800A946C() >= 2) param_0->blocked = 1;
}

void func_800A6FF0(S800A6FF0 *param_0) {
    func_800F5A00(param_0->id, param_0->unk4);
    param_0->unk24 = func_800F5628(param_0->id);
    param_0->flag64 = param_0->flag74_2;
    param_0->flag74_1 = func_800F8874(param_0->id);
}

int func_800A7088(Actor *param_0)
{
  Actor *new_var3;
  int new_var2;
  s32 local_0;
  Actor *new_var;
 do { } while (0);
  new_var2 = 2;
  new_var3 = param_0;
  new_var = new_var3;
  local_0 = (((u16 *) new_var)[0x76 / new_var2] & 0xFFFFFFFFu) >> 7;
  func_800F7364(local_0);
}

void func_800A70B0()
{
    func_800FFA88();
}

void func_800A70D0(s32 param_0, s32 param_1) {
    func_80106790(param_0)->hi = param_1;
}

int func_800A7108(s32 param_0, f32 param_1)
{
  Actor *local_0;
  local_0 = func_80106790(param_0);
  local_0->unk58 = param_1;
}

void func_800A7130(s32 param_0, s32 param_1) {
    func_80106790(param_0)->bit = param_1;
}

int func_800A7168()
{
    return (int)&D_8011A3A0;
}
