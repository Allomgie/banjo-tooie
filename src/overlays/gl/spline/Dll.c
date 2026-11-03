#include "common.h"

typedef struct { s16 local_0; s16 local_1[3]; u16 local_2:1; u16 local_3:1; u16 local_4:1; u16 local_5:10; u16 local_8:1; u16 local_7:1; u16 local_6:1; s16 local_9; u16 local_10:6; u16 local_11:9; u16 pad_0:1; u16 local_12:9; u16 local_13:5; u16 pad_1:2; } SplineDllNode;
typedef struct { f32 local_0; u32 local_1; u8 pad_0[3]; u8 local_2; u32 local_3; u32 local_4; } SplineDllEvent;
typedef struct { s32 local_0; SplineDllEvent local_1[]; } SplineDllEvents;
typedef struct { s16 local_0; u8 local_1; u8 local_2; u8 local_3; u8 pad_0[3]; f32 local_4; f32 local_5; s16 local_6; u8 pad_1[2]; f32 local_7[]; } SplineDllPath;
typedef struct { s8 local_0:1; s8 pad_0:7; u8 pad_1[11]; } SplineDllSlot;
typedef struct { u8 pad_0[0x184]; s16 local_0; s16 local_1; s32 local_2; u8 pad_1[4]; f32 local_3; f32 local_4; s32 local_5; s32 *local_6; s32 local_7; SplineDllSlot *local_8; u8 local_9; } SplineDllState;
extern s32 D_80800FC0_glsplineDll[];
extern s32 func_800E6A00(void);
extern s16 func_8001B668(s32, s32);
extern void *func_8001B798(s16);
extern void *heap_alloc(s32);
extern void heap_free(void *);
extern s32 _gccubeDll_entrypoint_7(void);
extern s32 _gccubesearch_entrypoint_18(s32, s32 *, s32 *, s32 *, s32 *, s32 *, u8 **);
extern SplineDllEvent *_gccubesearch_entrypoint_17(s32, s32 *);
extern void func_800E9EE8(s32);
extern void rare_memcpy(void *, void *, s32);
extern s32 func_800D7488(s16, s16);
extern void func_800D87B0(void);
extern u8 *func_800D674C(s32);
extern SplineDllEvent *func_800D7570(s32);
extern void *func_800D7520(s32);
extern void func_800C84A4(void *, s32);
typedef struct { s16 map; s16 value; } SplineMapRecord;
extern SplineMapRecord D_80800FC8_glsplineDll[];
extern u8 D_8012762C;
typedef struct { u8 pad0[0x184]; s16 unk184; s16 unk186; s32 unk188; u8 pad18C[0xC]; s32 unk198; void *unk19C; s32 unk1A0; void *unk1A4; } SplineSet;
extern void func_8001B754();

s32 func_80800000_glsplineDll(u32 *param_0, s32 *param_1, u32 *param_2, u32 *param_3, u32 *param_4, u32 *param_5, s32 *param_6, u8 *param_7) {
    s32 local_0;

    local_0 = (*(s32 *)((s8 *)(param_7) + (4)));
    if (!(local_0 & 1) && (((u32) (local_0 << 0x19) >> 0x1A) == 0xB)) {
        *param_0 = (u32) ((*(s32 *)((s8 *)(param_7) + (8))) << 0x16) >> 0x1F;
        *param_1 = (*(u8 *)((s8 *)(param_7) + (0xA))) & 1;
        *param_2 = (u32) ((*(u32 *)((s8 *)(param_7) + (0xC))) << 0x12) >> 0x16;
        *param_3 = (u32) ((*(s32 *)((s8 *)(param_7) + (8))) << 0x12) >> 0x1F;
        *param_4 = (u32) (*(u32 *)((s8 *)(param_7) + (0xC))) >> 0x17;
        *param_5 = (u32) ((*(u32 *)((s8 *)(param_7) + (0xC))) << 9) >> 0x17;
        *param_6 = _gspropctrl_entrypoint_6(param_7);
        return 1;
    }
    return 0;
}

void glsplineDll_entrypoint_0(SplineDllState *param_0)
{
    s32 local_0;
    s32 local_1;
    SplineDllNode *local_3;
    s32 local_2;
    s32 local_4[3];
    s32 local_5;
    s32 local_6;
    s32 local_7[3];
    s32 local_8;
    u8 *local_9;
    u32 local_10;
    s32 local_11;
    u32 local_12;
    u32 local_13;
    u32 local_14;
    u32 local_15;
    s32 local_16;
    s32 unused_0; /* frame slot 0xF0, unused */
    u32 local_17;
    u32 local_18;
    s32 local_19;
    s32 local_20;
    s32 local_21;
    SplineDllPath *local_22;
    SplineDllEvents *local_23;
    s32 *local_24;
    s32 local_25 = 0;
    s16 local_26;
    s16 local_27;
    s16 local_28;
    f32 *local_29;
    SplineDllEvent *local_30;
    SplineDllEvent *local_31;
    s32 local_32;
    s32 unused_1; /* frame slot 0xB0, unused */
    SplineDllEvent local_33;
    SplineDllEvent *local_34;
    SplineDllEvent *local_35;
    SplineDllNode *local_36;
    s32 local_37; /* frame slot, unused */
    u8 *local_38;
    s32 *local_39;
    s32 local_40;
    s32 unused_2; /* frame filler, unused */
    s32 unused_3; /* frame filler, unused */
    s32 unused_4;
    param_0->local_9 = func_800E6A00();
    param_0->local_0 = func_8001B668(0, 0);
    param_0->local_1 = func_8001B668(0, 0);
    param_0->local_2 = 0;
    local_0 = _gccubeDll_entrypoint_7() + 1;
    if (local_0 > 1) {
        local_3 = heap_alloc(local_0 * sizeof(SplineDllNode));
        for (local_1 = 0; local_1 < local_0; local_1++) {
            (local_3 + local_1)->local_0 = -1;
        }
        _gccubesearch_entrypoint_18(0, local_4, &local_5, &local_6, local_7, &local_8, &local_9);
        do {
            local_20 = _gccubesearch_entrypoint_18(1, local_4, &local_5, &local_6, local_7, &local_8, &local_9);
            if (local_20 >= 0) {
                local_36 = ((SplineDllNode *)((s32)local_3 ^ 0)) + local_20;
                local_36->local_9 = local_20;
                local_36->local_0 = local_5;
                local_36->local_4 = local_6;
                local_36->local_1[0] = local_4[0];
                local_36->local_1[1] = local_4[1];
                local_36->local_1[2] = local_4[2];
                if (func_80800000_glsplineDll(&local_10, &local_11, &local_12, &local_13, &local_14, &local_15, &local_16, local_9)) {
                    local_36->local_10 = 11;
                    local_36->local_7 = local_10;
                    local_36->local_6 = local_11;
                    local_36->local_5 = local_12;
                    local_36->local_8 = local_13;
                    local_36->local_11 = local_14;
                    local_36->local_12 = local_15;
                    local_36->local_13 = local_16;
                } else {
                    local_36->local_10 = 0;
                }
            }
        } while (local_20 >= 0);
        for (local_1 = 1; local_1 < local_0; local_1++) {
            (local_3 + local_1)->local_2 = 0;
            if ((local_3 + local_1)->local_0 >= local_0 || (local_3 + local_1)->local_0 == -1) {
                (local_3 + local_1)->local_0 = 0;
            }
        }
        for (local_1 = 1; local_1 < local_0; local_1++) {
            if ((local_3 + local_1)->local_0 > 0) {
                (local_3 + (local_3 + local_1)->local_0)->local_2 = 1;
            }
        }
        for (local_1 = 1; local_1 < local_0; local_1++) {
            if ((local_3 + local_1)->local_4 == 1
                && ((local_3 + local_1)->local_2 != 0 || (local_3 + local_1)->local_0 <= 0)
                && ((local_3 + local_1)->local_2 != 1 || (local_3 + local_1)->local_0 <= 0)
                && ((local_3 + local_1)->local_2 != 1 || (local_3 + local_1)->local_0 != 0)) {
                func_800E9EE8(local_1);
                (local_3 + local_1)->local_0 = -1;
                (local_3 + local_1)->local_4 = 0;
            }
        }
        for (local_1 = 1; local_1 < local_0; local_1++) {
            if ((local_3 + local_1)->local_0 > 0 && (local_3 + local_1)->local_2 == 0 && (local_3 + local_1)->local_4 == 0) {
                local_19 = 1;
                local_21 = 5;
                local_17 = 1;
                local_18 = 0;
                local_25 = 0;
                for (; local_19 < local_0; local_19++) {
                    (local_3 + local_19)->local_3 = 0;
                }
                for (local_19 = local_1; (local_3 + local_19)->local_0 != 0 && !(local_3 + local_19)->local_3; local_19 = (local_3 + local_19)->local_0) {
                    (local_3 + local_19)->local_3 = 1;
                    local_17 += (local_3 + local_19)->local_4 == 0 ? 1 : 0;
                    local_18 += (local_3 + local_19)->local_4 == 0 ? 0 : 1;
                    if (param_0) {}
                    if (1) {}
                }
                local_26 = func_8001B668(0, local_17 * sizeof(s32));
                unused_4 = param_0->local_2;
                local_19 = local_1;
                local_24 = func_8001B798(local_26);
                local_37 = local_17 * 3;
                local_27 = func_8001B668(0, 0x14 + local_37 * sizeof(f32));
                local_22 = func_8001B798(local_27);
                local_29 = (f32 *)local_22;
                local_22->local_1 = local_17;
                local_22->local_2 = 0;
                local_22->local_4 = 0.0f;
                if (unused_4) {}
                local_22->local_5 = 0.0f;
                local_28 = func_8001B668(0, 4 + local_18 * sizeof(SplineDllEvent));
                local_23 = func_8001B798(local_28);
                local_23->local_0 = local_18;
                local_31 = local_23->local_1;
                local_2 = local_1;
                local_32 = local_23->local_0;
                for (; local_32 != 0; local_2 = (local_3 + local_2)->local_0) {
                    if ((local_3 + local_2)->local_4 == 1) {
                        local_35 = _gccubesearch_entrypoint_17(local_2, 0);
                        local_35->local_2 = param_0->local_2;
                        rare_memcpy(local_31, local_35, sizeof(SplineDllEvent));
                        local_31++;
                        local_32--;
                    }
                }
                local_34 = local_23->local_0 - 1 + local_23->local_1;
                do {
                    local_32 = 0;
                    for (local_30 = local_23->local_1; local_30 < local_34; local_30++) {
                        local_31 = local_30 + 1;
                        if (local_30->local_0 > local_31->local_0) {
                            rare_memcpy(&local_33, local_30, sizeof(SplineDllEvent));
                            rare_memcpy(local_30, local_31, sizeof(SplineDllEvent));
                            rare_memcpy(local_31, &local_33, sizeof(SplineDllEvent));
                            local_32++;
                        }
                    }
                } while (local_32);
                local_22->local_0 = (local_3 + local_1)->local_9;
                local_22->local_3 = param_0->local_9;
                local_22->local_6 = local_26;
                for (local_2 = local_17; local_2 != 0; local_19 = (local_3 + local_19)->local_0) {
                    if (!(local_3 + local_19)->local_4) {
                        local_29[local_21] = (local_3 + local_19)->local_1[0];
                        local_29[local_21 + 1] = (local_3 + local_19)->local_1[1];
                        local_29[local_21 + 2] = (local_3 + local_19)->local_1[2];
                        local_21 += 3;
                        local_2--;
                        local_24[local_25++] = (local_3 + local_19)->local_9;
                    }
                }
                func_800D7488(local_27, local_28);
            }
        }
        heap_free(local_3);
    }
    param_0->local_5 = 0;
    param_0->local_6 = 0;
    param_0->local_7 = 0;
    param_0->local_3 = 0;
    param_0->local_4 = 0;
    func_800D87B0();
    if (param_0->local_6 != 0) {
        local_38 = func_800D674C(param_0->local_5);
        for (local_1 = 0; local_1 < param_0->local_2; local_1++) {
            local_35 = func_800D7570(local_1);
            if (local_35 && (local_35->local_1 & 1) && (local_35->local_3 & 1) && *(u8 *)&local_35->local_3) {
                local_40 = *(u8 *)&local_35->local_3 - 1;
                local_39 = (s32 *)(param_0->local_6[local_40] + local_38);
                if (local_39[1] == D_80800FC0_glsplineDll[0] && local_39[2] == D_80800FC0_glsplineDll[1]) {
                    func_800C84A4(func_800D7520(local_1), 1);
                }
            }
        }
    }
    param_0->local_8 = heap_alloc(7 * sizeof(SplineDllSlot));
    for (local_2 = 0; local_2 < 7; local_2++) {
        param_0->local_8[local_2].local_0 = 0;
    }
}

s32 func_80800C70_glsplineDll(void)
{
    s32 local_0 = 0;

    while (D_8012762C != D_80800FC8_glsplineDll[local_0].map &&
           D_80800FC8_glsplineDll[local_0].map != -1) {
        local_0++;
    }
    return D_80800FC8_glsplineDll[local_0].value;
}

void glsplineDll_entrypoint_1(SplineSet *param_0)
{
    s16 *local_1;
    s16 *local_0;
    s32 local_2;

    local_0 = func_8001B798(param_0->unk184);
    local_1 = func_8001B798(param_0->unk186);
    for (local_2 = 0; local_2 < param_0->unk188; local_2++) {
        func_8001B754(((s16 *)func_8001B798(local_0[local_2]))[8]);
        func_8001B754(local_0[local_2]);
        func_8001B754(local_1[local_2]);
    }
    func_8001B754(param_0->unk184);
    func_8001B754(param_0->unk186);
    param_0->unk184 = 0;
    param_0->unk186 = 0;
    heap_free(param_0->unk1A4);
    param_0->unk188 = 0;
    param_0->unk1A4 = NULL;
    param_0->unk198 = 0;
    heap_free(param_0->unk19C);
    param_0->unk19C = NULL;
    param_0->unk1A0 = 0;
}

void glsplineDll_entrypoint_2(u8 *param_0)
{
    s32 local_1; /* agV23: ONE int used as byte cursor in loop 1 and as byte offset in loop 2 (same reg a1 in target; first-def order colours loop-2 offset a1, index a2) */
    s32 *local_0;
    s32 local_2;
    s32 local_3;
    s32 local_4;
    s32 local_5;
    s32 *local_6;
    s32 k2 = 2;
    s32 k5 = 0x10005;
    s32 k6 = 0x10006;
    local_5 = func_80800C70_glsplineDll();
    if (local_5) {
        *(s32 *)(param_0 + 0x198) = local_5;
        local_0 = func_800D674C(local_5);
        *(s32 *)(param_0 + 0x1A0) = 0;
        for (local_2 = 0, local_1 = (s32)local_0; local_2 != 3; local_1 += 4) {
            if (local_2 == 2) {
                local_2 = *(s32 *)local_1 == 3 ? 3 : 0;
            }
            local_5 = *(s32 *)local_1; /* agV8: dead local_5 reused as value holder (gets a0 like the target) */
            if (local_2 == 1) {
                local_2 = k2 == local_5 ? 2 : 0;
            }
            if (local_2 == 0) {
                local_2 = local_5 == 0 ? 1 : 0;
            }
            if (k5 == local_5 || k6 == local_5) {
                (*(s32 *)(param_0 + 0x1A0))++;
            }
        }
        *(s32 **)(param_0 + 0x19C) = heap_alloc(*(s32 *)(param_0 + 0x1A0) * 4);
        local_6 = local_0; /* agV8: own cursor for loops 2/3 (target: loop1 cursor a1, loop2 cursor a0) */
        local_2 = 4;
            for (local_3 = 0, local_1 = 0; local_2 != 3; local_1 += 4) {
            if (local_2 == 2) {
                local_2 = *local_6 == 3 ? 3 : *local_6 == 0x10005 || *local_6 == 0x10006 ? 4 : 0;
            }
            if (local_2 == 1) {
                local_2 = *local_6 == 2 ? 2 : 0;
            }
            if (local_2 == 0) {
                local_2 = *local_6 == 0 ? 1 : 0;
            }
            local_6++;
            if (local_2 == 4) {
                local_2 = 0;
                (*(s32 **)(param_0 + 0x19C))[local_3++] = local_1;
            }
        }
        if (local_0) {} /* PROBE (kept from hm) */
        while (*local_6 != 4) {
            param_0[(*local_6 >> 16) & 0x7F] = *local_6 & 0xFF;
            param_0[0x80 + ((*local_6 >> 16) & 0x7F)] = *local_6 & 0xFF;
            local_6++;
        }
    }
}

/* TU-NOTE: the .data of this overlay (formerly asm/data/overlays/gl/spline/Dll.data.s) is defined here in C.
 * Values are taken from the ROM. */
s32 D_80800FC0_glsplineDll[2] = { 0x0, 0x2D0001 };
SplineMapRecord D_80800FC8_glsplineDll[26] = { 0xD, 0xAFF, 0x3, 0x0, 0xA, 0x0, 0x7, 0x0, 0x2, 0x0, 0x1, 0x0, 0x4, 0x0, 0xF, 0x0, 0x5, 0x0, 0x10, 0x0, 0x6, 0x0, 0xC, 0x0, 0x12, 0x0, 0x13, 0x0, 0x14, 0x0, 0x15, 0x0, 0x16, 0x0, 0x17, 0x0, 0x18, 0x0, 0x19, 0x0, 0x1A, 0x0, 0x11, 0x0, -0x1, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0 };
