// Sprite renderer: draws distance-culled 3D billboard sprites and 2D screen sprites using a global
// block of current render settings (scale, colors, alpha, combine mode, roll, draw distance).
#include "common.h"
#include "core2/1EBB4F0.h"

#define E1DF4_COMMAND(a, b)                                                                        \
    {                                                                                              \
        Gfx *local_1 = local_0++;                                                                  \
        local_1->words.w0 = (a);                                                                   \
        local_1->words.w1 = (b);                                                                   \
    }

extern s16 D_8012D48C;
extern f32 func_800E3928(s32, s32);
extern f32 func_800E42C0(void);
extern void func_800EE7F8(s32, s32);
typedef struct {
    s32 pad;
    s32 env_color[3], prim_color[3];
    s16 alpha;
    u8 combine_mode, unk_1F, blend_alpha;
} RenderE1DF4;
extern Gfx D_801231B0[];
typedef struct {
    s16 width, height;
    u8 pad[40];
    f32 scale_x, scale_y;
} StateE204C;
typedef struct {
    s16 pad[2];
    s16 width, height;
} SizeE204C;
typedef struct {
    Gfx *dl;
    Mtx *mtx;
} DrawE;
extern f32 D_8012D4A8[4][4];
extern void func_800F26B0(f32[4][4], f32, f32, f32);
typedef struct {
    s16 off_x, off_y, unk_4, unk_6;
} FrameE;
typedef struct {
    s16 width, height;
    s32 env_color[3], prim_color[3];
    s16 alpha;
    u8 combine_mode, unk_1F, blend_alpha, unk_21, fade_enabled, adjust_aspect;
    s32 draw_distance;
    f32 roll, scale_x, scale_y, depth;
    f32 matrix[4][4];
    s32 callback, callback_arg;
    void *unk_80;
    ImageStruct *image;
} StateE;

extern void *func_800AF5D8(void *);
extern void *func_800AF5E4(void *);
extern Gfx *func_800AF5F0(void *);
extern FrameE *func_800AF5FC(void *, s32);
typedef struct {
    s16 width, height;
    s32 env_color[3];
    s32 prim_r, prim_g, prim_b;
    s16 alpha;
    u8 combine_mode, unk_1F, blend_alpha, unk_21, fade_enabled, adjust_aspect;
    s32 draw_distance;
    f32 roll, scale_x, scale_y, depth;
    u8 matrix[64];
    s32 callback, callback_arg;
} local_type;
extern u8 D_8012D490;
extern s32 D_8012D474;
extern s32 D_8012D494;
extern float D_8012D4A4;
extern u8 D_8012D48F;
extern u8 D_8012D492;
extern u8 D_8012D493;
extern u8 D_8012D491;
extern s32 D_8012D480;
extern float D_8012D498;
extern u8 D_8012D48E;
extern s32 D_8012D4F0;
extern void *func_800E401C(void);
extern void mlMtxSet(void *);
extern void mlMtxRotRoll(f32);
extern void func_800191F8(f32, f32, f32);
extern void mlMtxRotatePYR(f32, f32, f32);
extern void mlMtxScale_xyz(f32, f32, f32);
extern void mlMtxApply(Mtx *);
extern void func_80019CD4(void);
extern f32 func_800A8AF0(s32 param_0);
extern s32 func_800A89F8(void);
typedef struct {
    s32 x, y, z;
} LocalPosition;
typedef struct {
    s32 pad;
    s16 width, height, unk_8, unk_A;
} ImageE2E48;
typedef struct {
    s16 width, height;
    u8 pad[0x24];
    f32 roll, scale_x;
    f32 scale_y, depth;
} StateE2E48;
extern void func_800E42F0(DrawE *, s32);
extern void func_800EFA4C(f32 *, f32, f32, f32);
extern void func_800E4640(DrawE *);
extern int D_8012D4F4;
typedef struct {
    s16 off_x, off_y;
    s32 pad;
} FrameE32CC;
typedef struct {
    s16 width, height;
    u8 pad[0xC];
    s32 prim_color[3];
    s16 alpha;
    u8 pad1[0xA];
    f32 roll, scale_x, scale_y;
    u8 pad2[0x50];
    ImageE2E48 *image;
} StateE32CC;
typedef union {
    StateE StateE;
    RenderE1DF4 RenderE1DF4;
    StateE204C StateE204C;
    local_type local_type;
    StateE2E48 StateE2E48;
    StateE32CC StateE32CC;
} Union_D_8012D470;
// Current sprite render settings; the union members are views of the same block.
extern Union_D_8012D470 D_8012D470;
void func_800E23A4();
int func_800E24F8();

// Returns 0 if the sprite is culled by distance or size.
s32 func_800E1C00(u8 *sprite, s32 pos, f32 scale_x, f32 scale_y, s32 out_pos)
{
    f32 dist;
    s8 _sfpad[8]; // Matching: pad local reserves stack space.
    f32 max_dist;
    f32 fade_start;
    f32 height;
    f32 size;
    max_dist = (f32) *(s32 *) ((s8 *) (s32 *) &D_8012D470 + 0x24) * func_800E42C0();
    dist = func_800E3928(pos, out_pos);
    func_800EE7F8(out_pos, pos);
    if ((dist < 0.0f) || (max_dist < dist)) {
        return 0;
    }
    if ((*(u8 *) ((s8 *) (s32 *) &D_8012D470 + 0x21) == 0) &&
        (*(s32 *) ((s8 *) (s32 *) &D_8012D470 + 0x24) == 0x4E20)) {
        size = (f32) *(s16 *) ((s8 *) sprite + 4) * scale_x;
        height = (f32) *(s16 *) ((s8 *) sprite + 6) * scale_y;
        if (size < height) {
            size = height;
        }
        if (((max_dist * 0.15f) < dist) && ((size / dist) < 0.1f)) {
            return 0;
        }
    }
    if ((*(s32 *) ((s8 *) (s32 *) &D_8012D470 + 0x80) == 0) &&
        (*(s32(**)(s32))((s8 *) (s32 *) &D_8012D470 + 0x78) != 0)) {
        (*(s32(**)(s32))((s8 *) (s32 *) &D_8012D470 + 0x78))(
            *(s32 *) ((s8 *) (s32 *) &D_8012D470 + 0x7C));
    }

    if (*(u8 *) ((s8 *) (s32 *) &D_8012D470 + 0x22) != 0) {
        fade_start = max_dist - 500.0f;
        if (fade_start < dist) {
            D_8012D48C = (s16) ((s32) (*(s16 *) ((s8 *) (s32 *) &D_8012D470 + 0x1C) *
                                       (s32) ((1.0f - ((dist - fade_start) / 500.0f)) * 256.0f)) /
                                256);
        }
    }
    return 1;
}

// Emits the GBI setup (colors, render mode) for a sprite draw.
void func_800E1DF4(dl_ptr, sprite) Gfx **dl_ptr;
s32 sprite;
{
    Gfx *local_0 = *dl_ptr;
    E1DF4_COMMAND(0xDE000000, (u32) ((u8 *) D_801231B0 - 0x80000000));

    if (!D_8012D470.RenderE1DF4.unk_1F) {
        E1DF4_COMMAND(0xE3001801, 0xC0);
    }

    E1DF4_COMMAND(0xFA000000, ((D_8012D470.RenderE1DF4.prim_color[0] & 0xFF) << 24) |
                                  ((D_8012D470.RenderE1DF4.prim_color[1] & 0xFF) << 16) |
                                  ((D_8012D470.RenderE1DF4.prim_color[2] & 0xFF) << 8) |
                                  (D_8012D470.RenderE1DF4.alpha & 0xFF));
    E1DF4_COMMAND(0xFB000000, ((D_8012D470.RenderE1DF4.env_color[0] & 0xFF) << 24) |
                                  ((D_8012D470.RenderE1DF4.env_color[1] & 0xFF) << 16) |
                                  ((D_8012D470.RenderE1DF4.env_color[2] & 0xFF) << 8) | 0xFF);

    if (D_8012D470.RenderE1DF4.combine_mode > 0 && D_8012D470.RenderE1DF4.combine_mode < 5) {
        E1DF4_COMMAND(0xD9FFFFFF, 1);
        switch (D_8012D470.RenderE1DF4.combine_mode) {
            case 1:
                E1DF4_COMMAND(0xE200001C, 0x504A50);
                break;
            case 2:
                E1DF4_COMMAND(0xE200001C, 0x504250);
                break;
            case 3:
                E1DF4_COMMAND(0xE200001C, 0x504A70);
                D_8012D470.RenderE1DF4.blend_alpha = 0x80;
                break;
            case 4:
                E1DF4_COMMAND(0xE200001C, 0x504B70);
                break;
        }
    } else if (D_8012D470.RenderE1DF4.combine_mode == 5) {
        E1DF4_COMMAND(0xE200001C, 0x504340);
    } else {
        E1DF4_COMMAND(0xE200001C, 0x504240);
    }
    if (D_8012D470.RenderE1DF4.blend_alpha) {
        E1DF4_COMMAND(0xE2001E01, 1);
        E1DF4_COMMAND(0xF9000000, D_8012D470.RenderE1DF4.blend_alpha & 0xFF);
    }
    *dl_ptr = local_0;
}

void func_800E204C(DrawE *draw, SizeE204C *sprite)
{
    if ((sprite->width != D_8012D470.StateE204C.width && D_8012D470.StateE204C.width) ||
        (sprite->height != D_8012D470.StateE204C.height && D_8012D470.StateE204C.height) ||
        (f32) D_8012D470.StateE204C.scale_x != 1.0f ||
        (f32) D_8012D470.StateE204C.scale_y != 1.0f) {
        func_800F26B0(
            D_8012D4A8,
            (f32) D_8012D470.StateE204C.scale_x * D_8012D470.StateE204C.width / sprite->width,
            (f32) D_8012D470.StateE204C.scale_y * D_8012D470.StateE204C.height / sprite->height,
            1.0f);

        guMtxF2L(D_8012D4A8, draw->mtx);
        {
            Gfx *cmd = draw->dl++;
            cmd->words.w0 = 0xDA380000;
            cmd->words.w1 = (u32) draw->mtx;
        }

        draw->mtx++;
    }
}

void func_800E2180(DrawE *draw, void *sprite, s32 frame_idx)
{
    FrameE *frame;
    Gfx *frame_dl;
    gDma1p(draw->dl++, 0xDB, osVirtualToPhysical(func_800AF5D8(sprite)), 8, 6);
    gDma1p(draw->dl++, 0xDB, osVirtualToPhysical(func_800AF5E4(sprite)), 4, 6);
    frame = func_800AF5FC(sprite, frame_idx);
    frame_dl = func_800AF5F0(sprite);
    frame_dl += frame->unk_4;
    gDma1p(draw->dl++, 0xDE, osVirtualToPhysical(frame_dl), 0, 0);
}

void func_800E2260(DrawE *draw, FrameE *sprite)
{
    if ((sprite->unk_4 != D_8012D470.StateE.width && D_8012D470.StateE.width) ||
        (sprite->unk_6 != D_8012D470.StateE.height && D_8012D470.StateE.height) ||
        D_8012D470.StateE.scale_x != 1.0f || D_8012D470.StateE.scale_y != 1.0f) {
        gDma2p(draw->dl++, 0xD8, sizeof(Mtx), sizeof(Mtx), 2, 0);
    }
}

void func_800E22F0(dl_ptr, sprite) u8 **dl_ptr;
u8 sprite;
{
    u8 *pipe_sync;
    u8 *mode_h;
    u8 *mode_l;

    if ((((u8 *) &D_8012D470)[0x1f] == 0) || (((u8 *) &D_8012D470)[0x20] != 0)) {
        pipe_sync = *dl_ptr;
        *dl_ptr = pipe_sync + 8;
        *(s32 *) (pipe_sync + 4) = 0;
        *(s32 *) pipe_sync = 0xE7000000;

        if (((u8 *) &D_8012D470)[0x1f] == 0) {
            mode_h = *dl_ptr;
            *dl_ptr = mode_h + 8;
            *(s32 *) (mode_h + 4) = 0;
            *(s32 *) mode_h = 0xE3001801;
        }

        if (((u8 *) &D_8012D470)[0x20] != 0) {
            mode_l = *dl_ptr;
            *dl_ptr = mode_l + 8;
            *(s32 *) (mode_l + 4) = 0;
            *(s32 *) mode_l = 0xE2001E01;
        }
    }
    func_800E8078(dl_ptr, ((u8 *) &D_8012D470));
    func_800E23A4();
}

// Reset the render settings to their defaults.
void func_800E23A4(void)
{
    D_8012D470.local_type.width = D_8012D470.local_type.height = 0;
    D_8012D470.local_type.env_color[2] = 0;
    D_8012D470.local_type.env_color[1] = 0;
    D_8012D470.local_type.env_color[0] = 0;
    D_8012D470.local_type.combine_mode = D_8012D470.local_type.unk_21 = D_8012D470.local_type.blend_alpha =
        D_8012D470.local_type.fade_enabled = D_8012D470.local_type.adjust_aspect = 0;
    D_8012D470.local_type.alpha = D_8012D470.local_type.unk_1F = 255;
    D_8012D470.local_type.prim_b = D_8012D470.local_type.alpha;
    D_8012D470.local_type.prim_g = D_8012D470.local_type.alpha;
    D_8012D470.local_type.prim_r = D_8012D470.local_type.alpha;
    D_8012D470.local_type.callback = D_8012D470.local_type.callback_arg = 0;
    D_8012D470.local_type.draw_distance = 20000;
    D_8012D470.local_type.roll = 0.0f;
    D_8012D470.local_type.scale_x = D_8012D470.local_type.scale_y = 1.0f;
    D_8012D470.local_type.depth = -10.0f;
}

int func_800E2434(unsigned int value)
{
    D_8012D490 = value;
}

// Matching: the `| 0` operations are needed for the match.
int func_800E2440(s32 r, s32 g, s32 b)
{
    func_800F31DC(&D_8012D474, r | 0, g, b | 0);
}

void func_800E2478(s32 value)
{
    func_800E24F8(value, value, value);
}

int func_800E249C(s32 distance)
{
    D_8012D494 = distance;
}

void func_800E24A8(f32 depth)
{
    D_8012D4A4 = depth;
}

// Matching: the `^ 0` is needed for the match.
int func_800E24B4(unsigned int value)
{
    D_8012D48F = value ^ 0;
}

// Matching: the `^ 0` is needed for the match.
int func_800E24C0(unsigned long value)
{
    D_8012D492 = value ^ 0;
}

int func_800E24CC(unsigned int value)
{
    D_8012D493 = value;
}

int func_800E24D8(unsigned int value)
{
    // Matching: extra temporary is needed for the match.
    unsigned int value_copy;
    value_copy = value;
    D_8012D491 = value_copy;
}

void func_800E24E4(s32 callback, s32 callback_arg)
{
    *(s32 *) ((char *) ((s32 *) &D_8012D470) + 0x78) = callback;
    *(s32 *) ((char *) ((s32 *) &D_8012D470) + 0x7c) = callback_arg;
}

// Matching: the `| 0` operations are needed for the match.
int func_800E24F8(r, g, b)
s32 r;
s32 g;
s32 b;
{
    func_800F31DC(&D_8012D480, r | 0, g, b | 0);
}

void func_800E2530(f32 roll)
{
    D_8012D498 = roll;
}

int func_800E253C(f32 scale)
{
    // Matching: the index temporary and its decrement are needed for the match.
    int index;
    ((f32 *) &D_8012D470)[12] = scale;
    index = 12;
    index--;
    ((f32 *) &D_8012D470)[index] = ((f32 *) &D_8012D470)[12];
}

void func_800E2554(f32 scale_x, f32 scale_y)
{
    *(f32 *) ((s8 *) ((f32 *) &D_8012D470) + 44) = scale_x;
    *(f32 *) ((s8 *) ((f32 *) &D_8012D470) + 48) = scale_y;
}

void func_800E2568(s32 width, s32 height)
{
    *(s16 *) ((char *) ((s16 *) &D_8012D470) + 0x0) = (s16) width;
    *(s16 *) ((char *) ((s16 *) &D_8012D470) + 0x2) = (s16) height;
}

long func_800E257C(int alpha)
{
    D_8012D48C = alpha;
}

void func_800E2588(u32 mode)
{
    D_8012D48E = mode;
}

// Begins a batch of 3D sprite draws.
void func_800E2594(u32 draw, ImageStruct *sprite)
{
    func_800E1DF4((DrawE *) draw, sprite);
    gDma1p(((DrawE *) draw)->dl++, 0xDB, osVirtualToPhysical(func_800AF5D8(sprite)), 8, 6);
    gDma1p(((DrawE *) draw)->dl++, 0xDB, osVirtualToPhysical(func_800AF5E4(sprite)), 4, 6);
    D_8012D4F0 = sprite;
}

void func_800E2630(DrawE *draw, s32 frame_idx, s32 alpha)
{
    FrameE *frame;
    Gfx *frame_dl;
    if (alpha != D_8012D470.StateE.alpha) {
        D_8012D470.StateE.alpha = alpha;
        gDPSetPrimColor(draw->dl++, 0, 0, D_8012D470.StateE.prim_color[0],
                        D_8012D470.StateE.prim_color[1], D_8012D470.StateE.prim_color[2],
                        D_8012D470.StateE.alpha);
    }
    func_800E204C(draw, D_8012D470.StateE.unk_80);
    frame = func_800AF5FC(D_8012D470.StateE.unk_80, frame_idx);
    frame_dl = func_800AF5F0(D_8012D470.StateE.unk_80);
    frame_dl += frame->unk_4;
    gDma1p(draw->dl++, 0xDE, osVirtualToPhysical(frame_dl), 0, 0);
    func_800E2260(draw, D_8012D470.StateE.unk_80);
}

// Matching: the redundant (f32) casts on D_8012D498 are needed for the match.
s32 func_800E2720(DrawE *draw, s32 frame_idx, s32 flip, f32 *pos, f32 *scale, s32 alpha)
{
    f32 scale_x;
    f32 scale_y;
    f32 scale_z;
    f32 view_pos[3];
    if (scale) {
        scale_x = scale[0];
        scale_y = scale[1];
        scale_z = scale[2];
    } else {
        scale_x = scale_y = scale_z = 1.0f;
    }
    if (!func_800E1C00(D_8012D4F0, pos, scale_x, scale_y, view_pos))
        return 0;
    mlMtxSet(func_800E401C());
    if (((f32) D_8012D498) != 0.0f)
        mlMtxRotRoll(((f32) D_8012D498));
    func_800191F8(view_pos[0], view_pos[1], view_pos[2]);
    if (scale || flip)
        mlMtxScale_xyz(flip ? -scale_x : scale_x, scale_y, scale_z);
    mlMtxApply(draw->mtx);
    gDma2p(draw->dl++, 0xDA, draw->mtx, sizeof(Mtx), 2, 0);
    draw->mtx++;
    func_800E2630(draw, frame_idx, alpha);
    gDma2p(draw->dl++, 0xD8, sizeof(Mtx), sizeof(Mtx), 2, 0);
    return 1;
}

s32 func_800E28A4(DrawE *draw, s32 frame_idx, s32 flip, f32 *pos, f32 *rot,
                  f32 *scale, s32 alpha)
{
    f32 scale_x;
    f32 scale_y;
    f32 scale_z;
    f32 view_pos[3];
    if (scale) {
        scale_x = scale[0];
        scale_y = scale[1];
        scale_z = scale[2];
    } else {
        scale_x = scale_y = scale_z = 1.0f;
    }
    if (!func_800E1C00(D_8012D4F0, pos, scale_x, scale_y, view_pos))
        return 0;
    func_80019CD4();
    func_800191F8(view_pos[0], view_pos[1], view_pos[2]);
    if (rot)
        mlMtxRotatePYR(rot[0], rot[1], rot[2]);
    if (scale || flip)
        mlMtxScale_xyz(flip ? -scale_x : scale_x, scale_y, scale_z);
    mlMtxApply(draw->mtx);
    gDma2p(draw->dl++, 0xDA, draw->mtx, sizeof(Mtx), 2, 0);
    draw->mtx++;
    func_800E2630(draw, frame_idx, alpha);
    gDma2p(draw->dl++, 0xD8, sizeof(Mtx), sizeof(Mtx), 2, 0);
    return 1;
}

// Ends the batch of 3D sprite draws.
void func_800E2A14(s32 draw)
{
    func_800E22F0(draw, ((int) D_8012D4F0));
    D_8012D4F0 = 0;
}

void func_800E2A3C(s32 draw, s32 sprite, s32 frame_idx)
{
    func_800E1DF4(draw, sprite);
    func_800E204C(draw, sprite);
    func_800E2180(draw, sprite, frame_idx);
    func_800E2260(draw, sprite);
    func_800E22F0(draw, sprite);
}

// Matching: the redundant (f32) casts on D_8012D498 are needed for the match.
void func_800E2AA4(DrawE *draw, s32 sprite, s32 frame_idx, s32 flip, f32 *pos,
                   f32 *scale)
{
    f32 scale_x;
    f32 scale_y;
    f32 scale_z;
    f32 view_pos[3];
    if (scale) {
        scale_x = scale[0];
        scale_y = scale[1];
        scale_z = scale[2];
    } else {
        scale_x = scale_y = scale_z = 1.0f;
    }
    if (!func_800E1C00(sprite, pos, scale_x, scale_y, view_pos)) {
        func_800E23A4();
        return;
    }
    func_800E1DF4(draw, sprite);
    mlMtxSet(func_800E401C());
    if (((f32) D_8012D498) != 0.0f)
        mlMtxRotRoll(((f32) D_8012D498));
    func_800191F8(view_pos[0], view_pos[1], view_pos[2]);
    if (scale || flip)
        mlMtxScale_xyz(flip ? -scale_x : scale_x, scale_y, scale_z);
    mlMtxApply(draw->mtx);
    gDma2p(draw->dl++, 0xDA, draw->mtx, sizeof(Mtx), 2, 0);
    draw->mtx++;
    func_800E204C(draw, sprite);
    func_800E2180(draw, sprite, frame_idx);
    func_800E2260(draw, sprite);
    gDma2p(draw->dl++, 0xD8, sizeof(Mtx), sizeof(Mtx), 2, 0);
    func_800E22F0(draw, sprite);
}

void func_800E2C54(DrawE *draw, s32 sprite, s32 frame_idx, s32 flip, f32 *pos,
                   f32 *rot, f32 *scale)
{
    f32 scale_x;
    f32 scale_y;
    f32 scale_z;
    f32 view_pos[3];
    if (scale) {
        scale_x = scale[0];
        scale_y = scale[1];
        scale_z = scale[2];
    } else {
        scale_x = scale_y = scale_z = 1.0f;
    }
    if (!func_800E1C00(sprite, pos, scale_x, scale_y, view_pos)) {
        func_800E23A4();
        return;
    }
    func_800E1DF4(draw, sprite);
    func_80019CD4();
    func_800191F8(view_pos[0], view_pos[1], view_pos[2]);
    if (rot)
        mlMtxRotatePYR(rot[0], rot[1], rot[2]);
    if (scale || flip)
        mlMtxScale_xyz(flip ? -scale_x : scale_x, scale_y, scale_z);
    mlMtxApply(draw->mtx);
    gDma2p(draw->dl++, 0xDA, draw->mtx, sizeof(Mtx), 2, 0);
    draw->mtx++;
    func_800E204C(draw, sprite);
    func_800E2180(draw, sprite, frame_idx);
    func_800E2260(draw, sprite);
    gDma2p(draw->dl++, 0xD8, sizeof(Mtx), sizeof(Mtx), 2, 0);
    func_800E22F0(draw, sprite);
}

// Scale x, aspect-corrected when enabled.
f32 func_800E2DF0(void)
{
    f32 scale_x;
    scale_x = *(f32 *) &((u8 *) &D_8012D470)[0x2C];
    if (((u8 *) &D_8012D470)[0x23] != 0) {
        {
            scale_x *= 1.3333334f / func_800A8AF0(func_800A89F8());
        }
    }
    return scale_x;
}

// Draws a 2D screen sprite.
// Matching: the line breaks in this function are needed for the match.
void func_800E2E48(DrawE *draw, ImageE2E48 *sprite, s32 frame_idx, LocalPosition *pos)
{
    f32 screen_pos[3];
    f32 scaled_w, scaled_h;
    s32 width, height;
    f32 scale_x;
    func_800E42F0(draw, 0);
    func_800E1DF4(draw, sprite);
    width = D_8012D470.StateE2E48.width ? D_8012D470.StateE2E48.width : sprite->unk_8 * 4;
    height = D_8012D470.StateE2E48.height ? D_8012D470.StateE2E48.height : sprite->unk_A * 4;
    scale_x = func_800E2DF0();
    scaled_w = (f32) scale_x * width / sprite->unk_8;
    scaled_h = (f32) D_8012D470.StateE2E48.scale_y * height / sprite->unk_A;
    func_800EFA4C(screen_pos, pos->x - 0x260, 0x1C8 - pos->y,
    D_8012D470.StateE2E48.depth);
    func_80019CD4();
    func_800191F8(screen_pos[0], screen_pos[1], screen_pos[2]);
    if (D_8012D470.StateE2E48.roll != 0.0f)
        mlMtxRotRoll(D_8012D470.StateE2E48.roll);
    if (width != sprite->width || height != sprite->height || scale_x != 1.0f ||
        D_8012D470.StateE2E48.scale_y != 1.0f) {
        mlMtxScale_xyz((f32) scaled_w * sprite->unk_8 / sprite->width,
        (f32) scaled_h * sprite->unk_A / sprite->height, 1.0f);
    }
    mlMtxApply(draw->mtx);
    {
        Gfx *mtx_cmd = draw->dl++;
        mtx_cmd->words.w0 = 0xDA380002;
        mtx_cmd->words.w1 = (u32) draw->mtx;
    }
    draw->mtx++;

    func_800E2180(draw, sprite, frame_idx);
    { Gfx *pop_cmd = draw->dl++; pop_cmd->words.w0 = 0xD8380002; pop_cmd->words.w1 = 0x40; }

    func_800E22F0(draw, sprite);
    func_800E4640(draw);
}

void func_800E30E0(s32 draw, void *sprite, s32 frame_idx, void *pos)
{
    s32 top_left[3];
    FrameE *frame;
    f32 scale_x;
    s32 width, height;
    frame = func_800AF5FC(sprite, frame_idx);

    if (!frame->off_x && !frame->off_y) {
        scale_x = func_800E2DF0();
        width = D_8012D470.StateE.width ? D_8012D470.StateE.width
                                            : ((ImageStruct *) sprite)->unk8 * 4;
        height = D_8012D470.StateE.height ? D_8012D470.StateE.height
                                            : ((ImageStruct *) sprite)->unkA * 4;
        top_left[0] = ((s32 *) pos)[0] - scale_x * width / 2;
        top_left[1] = ((s32 *) pos)[1] - D_8012D470.StateE.scale_y * height / 2;
    } else {
        top_left[0] = ((s32 *) pos)[0];
        top_left[1] = ((s32 *) pos)[1];
    }
    func_800E2E48(draw, sprite, frame_idx, top_left);
}

// Begins a batch of 2D sprite draws.
// Matching: the *_copy aliases are needed for the match.
void func_800E3220(s32 **dl_ptr, s32 sprite)
{
    s32 *cmd_a;
    s32 *cmd_b;
    s32 *cmd_a_copy;
    s32 *cmd_b_copy;
    func_800E1DF4();
    cmd_a = *dl_ptr;
    *dl_ptr = (*dl_ptr) + 2;
    *cmd_a = 0xDB060008;
    cmd_a_copy = cmd_a;
    *((s32 **) (4 + ((u8 *) cmd_a_copy))) = osVirtualToPhysical(func_800AF5D8(sprite));
    cmd_b = *dl_ptr;
    *dl_ptr = (*dl_ptr) + 2;
    *cmd_b = 0xDB060004;
    cmd_b_copy = cmd_b;
    *((s32 **) (((u8 *) cmd_b_copy) + 4)) = osVirtualToPhysical(func_800AF5E4(sprite));
    D_8012D4F4 = sprite;
    func_800E42F0(dl_ptr, 0);
}

void func_800E32CC(DrawE *draw, s32 frame_idx, LocalPosition *pos, s32 alpha)
{
    FrameE32CC *frame;
    f32 screen_pos[3];
    f32 scaled_w, scaled_h;
    s32 width, height;
    Gfx *frame_dl;
    frame = func_800AF5FC(D_8012D470.StateE32CC.image, frame_idx);
    if (alpha != D_8012D470.StateE32CC.alpha) {
        D_8012D470.StateE32CC.alpha = alpha;
        gDPSetPrimColor(draw->dl++, 0, 0, D_8012D470.StateE32CC.prim_color[0],
                        D_8012D470.StateE32CC.prim_color[1], D_8012D470.StateE32CC.prim_color[2],
                        D_8012D470.StateE32CC.alpha);
    }
    width = D_8012D470.StateE32CC.width ? D_8012D470.StateE32CC.width
                                            : D_8012D470.StateE32CC.image->unk_8 * 4;
    height = D_8012D470.StateE32CC.height ? D_8012D470.StateE32CC.height
                                            : D_8012D470.StateE32CC.image->unk_A * 4;
    scaled_w =
        (f32) D_8012D470.StateE32CC.scale_x * width / D_8012D470.StateE32CC.image->unk_8;
    scaled_h =
        (f32) D_8012D470.StateE32CC.scale_y * height / D_8012D470.StateE32CC.image->unk_A;
    func_800EFA4C(screen_pos, frame->off_x * scaled_w + (pos->x - 0x260),
                  (0x1C8 - pos->y) - frame->off_y * scaled_h, -10.0f);
    func_80019CD4();
    func_800191F8(screen_pos[0], screen_pos[1], screen_pos[2]);
    if (D_8012D470.StateE32CC.roll != 0.0f)
        mlMtxRotRoll(D_8012D470.StateE32CC.roll);
    if (width != D_8012D470.StateE32CC.image->width ||
        height != D_8012D470.StateE32CC.image->height ||
        (f32) D_8012D470.StateE32CC.scale_x != 1.0f ||
        (f32) D_8012D470.StateE32CC.scale_y != 1.0f) {
        mlMtxScale_xyz((f32) scaled_w * D_8012D470.StateE32CC.image->unk_8 /
                           D_8012D470.StateE32CC.image->width,
                       (f32) scaled_h * D_8012D470.StateE32CC.image->unk_A /
                           D_8012D470.StateE32CC.image->height,
                       1.0f);
    }
    mlMtxApply(draw->mtx);
    gDma2p(draw->dl++, 0xDA, draw->mtx, sizeof(Mtx), 2, 0);
    draw->mtx++;
    frame_dl = func_800AF5F0(D_8012D470.StateE32CC.image);
    frame_dl += *(s16 *) ((u8 *) frame + 4);
    gDma1p(draw->dl++, 0xDE, osVirtualToPhysical(frame_dl), 0, 0);
    gDma2p(draw->dl++, 0xD8, sizeof(Mtx), sizeof(Mtx), 2, 0);
}

void func_800E35E0(void *draw, s32 frame_idx, s32 *pos, s32 alpha)
{
    s32 width;
    s32 top_left[3];
    s32 height;
    width = D_8012D470.StateE.width ? D_8012D470.StateE.width
                                        : D_8012D470.StateE.image->unk8 * 4;
    height = D_8012D470.StateE.height ? D_8012D470.StateE.height
                                        : D_8012D470.StateE.image->unkA * 4;
    top_left[0] = pos[0] - width / 2;
    top_left[1] = pos[1] - height / 2;
    func_800E32CC(draw, frame_idx, top_left, alpha);
}

// Ends the batch of 2D sprite draws.
s32 func_800E368C(s32 draw)
{
    func_800E22F0(draw, ((s32) D_8012D4F4));
    D_8012D4F4 = 0;
    func_800E4640(draw);
}

// TU-NOTE: former .data of this file, defined here in C; values taken from the ROM.
Gfx D_801231B0[8] = {0xD9C0F9FA, 0x0, 0xD9FFFFFF, 0x200004,   0xD7000002, 0x80008000,
                     0xE7000000, 0x0, 0xFC309661, 0x552EFF7F, 0xE3000A01, 0x0,
                     0xDF000000, 0x0, 0x0,        0x0};
