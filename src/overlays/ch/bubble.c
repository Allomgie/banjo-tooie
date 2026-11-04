// Draws a refractive bubble: copies the framebuffer area behind it as a texture onto a
// camera-facing quad with a bubble mask, using raw GBI commands.
#include "common.h"

#define BUBBLE_COMMAND(pkt, first, second)                                                         \
    {                                                                                              \
        Gfx *_g = (pkt);                                                                           \
        _g->words.w0 = (first);                                                                    \
        _g->words.w1 = (u32) (second);                                                             \
    }
typedef struct {
    s16 pos[3];
    u16 flag;
    s16 tex[2];
    u32 color;
} BubbleVertex;
typedef struct {
    Gfx *gfx;
    Mtx *mtx;
    BubbleVertex *verts;
} BubbleDrawContext;
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

// Draws a refractive bubble at world_pos; returns 0 when it is culled.
s32 chbubble_entrypoint_0(BubbleDrawContext *ctx, f32 *world_pos, f32 *size, f32 scale,
                          f32 max_dist)
{
    u16 *framebuffer;
    f32 cam_pos[3];
    f32 translate[3];
    f32 screen[2];
    s32 x;
    s32 y;
    s32 width;
    s32 height;
    s32 tex_w;
    s32 tex_h;
    Gfx *gfx;
    BubbleVertex *verts;

    gfx = ctx->gfx;
    verts = ctx->verts;
    func_800E3980(cam_pos);
    // Cull when farther than max_dist.
    if (max_dist > 0.0f) {
        if (max_dist * max_dist < func_800EEB40(world_pos, cam_pos)) {
            return 0;
        }
    }
    // Move to the bubble position.
    func_800EE7F8(translate, world_pos);
    mlMtxSet(func_800E401C());
    func_800191F8(translate[0], translate[1], translate[2]);
    mlMtxApply(ctx->mtx);
    BUBBLE_COMMAND(gfx++, 0xDA380002, (u32) ctx->mtx + 0x80000000);
    ctx->mtx++;
    width = (s32) (size[0] * 200.0f * scale);
    height = (s32) (size[1] * 200.0f * scale);
    func_800E4140(world_pos, screen);
    x = (s32) (screen[0] + size[0] * 25.0f);
    y = (s32) (screen[1] + size[1] * 25.0f);
    // Keep the framebuffer copy area on screen.
    if (x < 0) {
        x = 0;
    } else if (x > 272) {
        x = 272;
    }
    if (y < 0) {
        y = 0;
    } else if (y > 196) {
        y = 196;
    }
    // Raw GBI commands.
    BUBBLE_COMMAND(gfx++, 0xE7000000, 0);
    BUBBLE_COMMAND(gfx++, 0xD9C0FFFA, 0);
    BUBBLE_COMMAND(gfx++, 0xD9FFFFFF, 0x00200005);
    BUBBLE_COMMAND(gfx++, 0xD7000002, 0x80008000);
    BUBBLE_COMMAND(gfx++, 0xE3000F00, 0);
    BUBBLE_COMMAND(gfx++, 0xE3000A01, 0x00100000);
    BUBBLE_COMMAND(gfx++, 0xFC2219FF, 0xFFFFFE38);
    BUBBLE_COMMAND(gfx++, 0xE200001C, 0x0C184A50);
    // Bubble texture asset 0x9CC.
    func_800AF614(&gfx, func_800D674C(0x9CC), 0, 0, 0, 0, 0, &tex_w, &tex_h);
    // Copy 32x32 of the framebuffer behind the bubble.
    framebuffer = (u16 *) func_80014F00();
    BUBBLE_COMMAND(gfx++, 0xFD10012F,
                   (u32) framebuffer + ((y * 304) << 1) + ((x & 0xFFFC) << 1) +
                       0x80000000);
    {
        Gfx *_g = gfx++;
        _g->words.w0 = 0xF5101280;
        _g->words.w1 = (u32) 0x07080200;
    }
    BUBBLE_COMMAND(gfx++, 0xE6000000, 0);
    {
        Gfx *_g = gfx++;
        _g->words.w0 = 0xF4000000;
        _g->words.w1 = (u32) 0x0708C07C;
    }
    BUBBLE_COMMAND(gfx++, 0xE7000000, 0);
    {
        Gfx *_g = gfx++;
        _g->words.w0 = 0xF5101280;
        _g->words.w1 = (u32) 0x01080200;
    }
    BUBBLE_COMMAND(gfx++, 0xF2000000 | ((((3 - x % 4) << 2) & 0xFFF) << 12),
                   0x01000000 | (((((3 - x % 4) + 31) << 2) & 0xFFF) << 12) | 0x7C);
    BUBBLE_COMMAND(gfx++, 0x01008010, verts);
    BUBBLE_COMMAND(gfx++, 0x06000206, 0x604);
    // Bubble texture asset 0x9CB.
    func_800AF614(&gfx, func_800D674C(0x9CB), 0, 0, 0, 2, 2, &tex_w, &tex_h);
    BUBBLE_COMMAND(gfx++, 0xE7000000, 0);
    BUBBLE_COMMAND(gfx++, 0xFC109804, 0x3FFDFFF8);
    BUBBLE_COMMAND(gfx++, 0xFA000000, 0x50F0FFFF);
    BUBBLE_COMMAND(gfx++, 0x060E080A, 0x000C080E);
    BUBBLE_COMMAND(gfx++, 0xE7000000, 0);
    BUBBLE_COMMAND(gfx++, 0xE3001001, 0);
    BUBBLE_COMMAND(gfx++, 0xD8380002, 0x40);
    for (y = 0; y < 2; y++) {
        for (x = 0; x < 2; x++) {
            verts->pos[0] = (width >> 1) - x * width;
            verts->pos[1] = (height >> 1) - y * height;
            verts->pos[2] = 0;
            verts->tex[0] = (31 - x * 31) << 6;
            verts->tex[1] = (y * 31) << 6;
            verts->color = 0xB4F0FFA0;
            verts++;
        }
    }
    for (y = 0; y < 2; y++) {
        for (x = 0; x < 2; x++) {
            verts->pos[0] = (width >> 1) - x * width;
            verts->pos[1] = (height >> 1) - y * height;
            verts->pos[2] = 0;
            verts->tex[0] = ((x ^ 1) * (tex_w - 1)) << 6;
            verts->tex[1] = ((tex_h - 1) * y) << 6;
            verts->color = 0xFFFFFFFF;
            verts++;
        }
    }
    ctx->gfx = gfx;
    ctx->verts = verts;
    return 1;
}
