#include "common.h"

#define BUBBLE_COMMAND(pkt, first, second) { \
    Gfx *_g = (pkt); \
    _g->words.w0 = (first); \
    _g->words.w1 = (u32)(second); \
}
typedef struct { s16 local_0[3]; u16 local_1; s16 local_2[2]; u32 local_3; } BubbleVertex;
typedef struct { Gfx *local_0; Mtx *local_1; BubbleVertex *local_2; } BubbleDrawContext;
extern void func_800E3980(f32 *);
extern f32 func_800EEB40(f32 *, f32 *);
extern void func_800EE7F8(f32 *, f32 *);
extern void *func_800E401C(void);
extern void mlMtxSet(void *);
extern void mlMtxApply(Mtx *);
extern void func_800191F8(f32, f32, f32);
extern void func_800E4140(f32 *, f32 *);
extern void func_800AF614(Gfx **, void *, s32, s32, s32, s32, s32, s32 *, s32 *);
extern s32 func_80014F00(void);

s32 chbubble_entrypoint_0(BubbleDrawContext *param_0, f32 *param_1, f32 *param_2, f32 param_3, f32 param_4)
{
    u16 *local_11;
    f32 local_0[3];
    f32 local_1[3];
    f32 local_2[2];
    s32 local_3;
    s32 local_4;
    s32 local_5;
    s32 local_6;
    s32 local_7;
    s32 local_8;
    Gfx *local_9;
    BubbleVertex *local_10;

    local_9 = param_0->local_0;
    local_10 = param_0->local_2;
    func_800E3980(local_0);
    if (param_4 > 0.0f) {
        if (param_4 * param_4 < func_800EEB40(param_1, local_0)) {
            return 0;
        }
    }
    func_800EE7F8(local_1, param_1);
    mlMtxSet(func_800E401C());
    func_800191F8(local_1[0], local_1[1], local_1[2]);
    mlMtxApply(param_0->local_1);
    BUBBLE_COMMAND(local_9++, 0xDA380002, (u32)param_0->local_1 + 0x80000000);
    param_0->local_1++;
    local_5 = (s32)(param_2[0] * 200.0f * param_3);
    local_6 = (s32)(param_2[1] * 200.0f * param_3);
    func_800E4140(param_1, local_2);
    local_3 = (s32)(local_2[0] + param_2[0] * 25.0f);
    local_4 = (s32)(local_2[1] + param_2[1] * 25.0f);
    if (local_3 < 0) {
        local_3 = 0;
    } else if (local_3 > 272) {
        local_3 = 272;
    }
    if (local_4 < 0) {
        local_4 = 0;
    } else if (local_4 > 196) {
        local_4 = 196;
    }
    BUBBLE_COMMAND(local_9++, 0xE7000000, 0);
    BUBBLE_COMMAND(local_9++, 0xD9C0FFFA, 0);
    BUBBLE_COMMAND(local_9++, 0xD9FFFFFF, 0x00200005);
    BUBBLE_COMMAND(local_9++, 0xD7000002, 0x80008000);
    BUBBLE_COMMAND(local_9++, 0xE3000F00, 0);
    BUBBLE_COMMAND(local_9++, 0xE3000A01, 0x00100000);
    BUBBLE_COMMAND(local_9++, 0xFC2219FF, 0xFFFFFE38);
    BUBBLE_COMMAND(local_9++, 0xE200001C, 0x0C184A50);
    func_800AF614(&local_9, func_800D674C(0x9CC), 0, 0, 0, 0, 0, &local_7, &local_8);
    local_11 = (u16 *)func_80014F00();
    BUBBLE_COMMAND(local_9++, 0xFD10012F, (u32)local_11 + ((local_4 * 304) << 1) + ((local_3 & 0xFFFC) << 1) + 0x80000000);
    {
        Gfx *_g = (local_9++);
        _g->words.w0 = (0xF5101280);
        _g->words.w1 = (u32)(0x07080200);
    }
    BUBBLE_COMMAND(local_9++, 0xE6000000, 0);
    {
        Gfx *_g = (local_9++);
        _g->words.w0 = (0xF4000000);
        _g->words.w1 = (u32)(0x0708C07C);
    }
    BUBBLE_COMMAND(local_9++, 0xE7000000, 0);
    {
        Gfx *_g = (local_9++);
        _g->words.w0 = (0xF5101280);
        _g->words.w1 = (u32)(0x01080200);
    }
    BUBBLE_COMMAND(local_9++, 0xF2000000 | ((((3 - local_3 % 4) << 2) & 0xFFF) << 12), 0x01000000 | (((((3 - local_3 % 4) + 31) << 2) & 0xFFF) << 12) | 0x7C);
    BUBBLE_COMMAND(local_9++, 0x01008010, local_10);
    BUBBLE_COMMAND(local_9++, 0x06000206, 0x604);
    func_800AF614(&local_9, func_800D674C(0x9CB), 0, 0, 0, 2, 2, &local_7, &local_8);
    BUBBLE_COMMAND(local_9++, 0xE7000000, 0);
    BUBBLE_COMMAND(local_9++, 0xFC109804, 0x3FFDFFF8);
    BUBBLE_COMMAND(local_9++, 0xFA000000, 0x50F0FFFF);
    BUBBLE_COMMAND(local_9++, 0x060E080A, 0x000C080E);
    BUBBLE_COMMAND(local_9++, 0xE7000000, 0);
    BUBBLE_COMMAND(local_9++, 0xE3001001, 0);
    BUBBLE_COMMAND(local_9++, 0xD8380002, 0x40);
    for (local_4 = 0; local_4 < 2; local_4++) {
        for (local_3 = 0; local_3 < 2; local_3++) {
            local_10->local_0[0] = (local_5 >> 1) - local_3 * local_5;
            local_10->local_0[1] = (local_6 >> 1) - local_4 * local_6;
            local_10->local_0[2] = 0;
            local_10->local_2[0] = (31 - local_3 * 31) << 6;
            local_10->local_2[1] = (local_4 * 31) << 6;
            local_10->local_3 = 0xB4F0FFA0;
            local_10++;
        }
    }
    for (local_4 = 0; local_4 < 2; local_4++) {
        for (local_3 = 0; local_3 < 2; local_3++) {
            local_10->local_0[0] = (local_5 >> 1) - local_3 * local_5;
            local_10->local_0[1] = (local_6 >> 1) - local_4 * local_6;
            local_10->local_0[2] = 0;
            local_10->local_2[0] = ((local_3 ^ 1) * (local_7 - 1)) << 6;
            local_10->local_2[1] = ((local_8 - 1) * local_4) << 6;
            local_10->local_3 = 0xFFFFFFFF;
            local_10++;
        }
    }
    param_0->local_0 = local_9;
    param_0->local_2 = local_10;
    return 1;
}
