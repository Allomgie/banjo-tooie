// Probably two unrelated parts: a bitmap-font text printer (style state, glyph upload, string width,
// centered printing) and a falling-weather particle system of up to 100 model particles.
#include "core2/1E91790.h"
#include "common.h"
#include <ultra64.h>

#define SHL(x, n) ((unsigned int) (((unsigned int) (x) & 255) << (n)))

#define CMD(a, b)                                                                                  \
    {                                                                                              \
        GfxB7F14 *local_0 = (*param_0)++;                                                          \
        local_0->local_0 = (a);                                                                    \
        local_0->local_1 = (b);                                                                    \
    }

#define COLOR_SHIFT(x, n) ((unsigned int) (((unsigned int) (x) & ((1 << 8) - 1)) << (n)))

#define B81CC_UPLOAD_TILE(pkt, c, tile, uls, ult, lrs, lrt)                                        \
    {                                                                                              \
        Gfx *_g = (Gfx *) pkt;                                                                     \
        _g->words.w0 = _SHIFTL(c, 24, 8) | _SHIFTL(uls, 12, 12) | _SHIFTL(ult, 0, 12);             \
        _g->words.w1 = _SHIFTL(lrt, 0, 12) | _SHIFTL(tile, 24, 3) | _SHIFTL(lrs, 12, 12);          \
    }

#define B81CC_GRAD_TILE(pkt, c, tile, uls, ult, lrs, lrt) }
typedef struct {
    u8 pad_0[0xA];
    u8 unk_A;
    u8 unk_B;
} G_B7EA0;
extern void func_800AF614(void *, void *, s32, s32, s32, s32, s32, s32 *, s32 *);
// Layout of D_801282C0: RGBA color, shakiness, font, gradient texture index, scale.
typedef struct {
    u8 r, g, b, a, shakiness, unk_5, font, unk_7, unk_8, gradient_id;
    u8 pad_A[10];
    f32 scale;
} TextState;
typedef struct {
    u32 local_0, local_1;
} GfxB7F14;
extern u8 D_8011A630[];
extern s32 func_800D3724(s32);
extern s32 D_8011A668[];
extern s8 D_801282C5;
extern s32 D_801282D0;
typedef struct {
    u8 w, h, x, y;
    s32 offset;
} B81CCGlyph;
extern B81CCGlyph *func_800B0D6C(s32, s32);
extern s32 func_800B0D60(s32);
extern f32 func_800DC178(f32, f32);
extern s32 D_8012712C;
typedef struct {
    f32 pos_x;
    f32 pos_y;
    f32 pos_z;
    f32 move_x;
    f32 move_y;
    f32 move_z;
    u8 state;
    u8 pad_19[3];
    void *particles;
} Struct800B9038Local;
typedef struct {
    Struct800B9038Local *emitter;
    u8 pad_4[8];
    s32 count;
} Struct800B9038;
typedef struct {
    u8 bytes[0x18];
} E_B9108;
typedef struct {
    u8 pad_0[0x1C];
    E_B9108 *particles;
} H_B9108;
typedef struct {
    H_B9108 *emitter;
    s32 count;
} G_B9108;
extern void aligned4_memcpy(void *, void *, s32);
typedef struct LocalParticle {
    f32 position[3], velocity[3];
} LocalParticle;
typedef struct LocalEmitter {
    f32 position[3], movement[3];
    u8 state;
    LocalParticle *particles;
} LocalEmitter;
typedef struct LocalWeather {
    LocalEmitter *emitter;
    s32 count;
    void *model;
    s32 cursor;
    f32 position[3], height;
} LocalWeather;
extern f32 D_80127138[3];
extern s32 func_800A5490(void);
extern f32 func_800D8FF8(void);
extern u32 func_8001211C(void);
extern void func_8008FE68(f32 *);
extern f32 func_800DC0C0(void);
extern f32 func_800EEAD4(f32 *, f32 *);
extern void func_800EFA4C(f32 *, f32, f32, f32);
extern f32 func_800EEFD4(f32 *);
extern f32 func_800E3A80(void);
extern void func_800EF934(f32 *, f32 *, f32);
extern void func_800EF04C(f32 *, f32 *);
extern s32 func_800E3F8C(f32, f32, f32);
extern void func_800EE7F8(f32 *, f32 *);
typedef struct {
    f32 pos[3];
    u8 pad_C[12];
} ParticleB956C;
typedef struct {
    u8 pad_0[0x1C];
    ParticleB956C *particles;
} PoolB956C;
typedef struct {
    PoolB956C *pool;
    s32 count;
    u8 pad_8[0x14];
    f32 height;
    u8 pad_20[0x30];
    f32 radius;
    void *model_dl, *unk_58;
} StateB956C;
typedef struct {
    s32 pad_0;
    s32 unk_4;
    s16 unk_8;
    s16 pad_A;
    s32 unk_C, unk_10;
} AssetB956C;
typedef struct {
    Gfx *dl;
    Mtx *mtx;
} DrawB956C;
// Weather state shared by its functions; each member is one function's view.
typedef union {
    Struct800B9038 alloc;
    LocalWeather update;
    G_B9108 drop;
    StateB956C draw;
} Union80127128;
extern Union80127128 D_80127128;
extern f32 D_80127148[3];
extern f32 D_80127154[3];
extern Gfx D_8011A690[];
extern u8 D_8011A6B0[];
extern DrawB956C *func_800A7180(void);
extern AssetB956C *func_800D674C(s32);
extern void func_800E39A8(f32 *, f32 *);
extern f32 func_800B2354(void *);
extern void mlMtxApply(Mtx *);
extern s32 func_800E3E8C(void *, f32);
extern void mlMtx_set_translation(f32, f32, f32);
extern void mlMtxRotYaw(f32);
extern void mlMtxRotPitch(f32);
extern void mlMtxTranslate(float, float, float);
extern s32 D_80127160;
extern s32 D_8012716C;
s32 func_800B97A4();

// Bitmap font text drawing: style state, glyph upload and texrect, string width, print.
void func_800B7EA0(void *dl, s32 asset_id)
{
    s32 pad;
    s32 unk_0;
    s32 unk_1;
    func_800AF614(dl, func_800D674C(asset_id), 0, 0x100, 1, 2, 2, &unk_0, &unk_1);
    ((G_B7EA0 *) &D_801282C0)->unk_A = unk_0;
    ((G_B7EA0 *) &D_801282C0)->unk_B = unk_1;
}

// Emits the render-state commands for drawing text.
void func_800B7F14(GfxB7F14 **param_0)
{
    CMD(0xDE000000, (u32) (D_8011A630 - 0x80000000));
    CMD(0xE3001201, ((TextState *) &D_801282C0)->font == 1 ? 0x2000 : 0);
    CMD(0xFA000000, SHL(((TextState *) &D_801282C0)->r, 24) |
                        SHL(((TextState *) &D_801282C0)->g, 16) |
                        SHL(((TextState *) &D_801282C0)->b, 8) |
                        SHL(((TextState *) &D_801282C0)->a, 0));
    if (((TextState *) &D_801282C0)->gradient_id) {
        CMD(0xE3000A01, 0x100000);
        CMD(0xFC117E03, 0xFF0FF3FF);
        CMD(0xE200001C, 0x0C184A40);
        func_800B7EA0(param_0, ((TextState *) &D_801282C0)->gradient_id + 0xC24);
    } else {
        CMD(0xE3000A01, 0);
        CMD(0xFC119623, 0xFF2FFFFF);
        CMD(0xE200001C, 0x00504A40);
    }
    ((TextState *) &D_801282C0)->unk_5 = 1;
    D_801282C0.data[12] = func_800D3724(((TextState *) &D_801282C0)->font);
}

// Emits the text color command.
void func_800B80D0(GfxB7F14 **dl)
{
    GfxB7F14 *cmd = (*dl)++;
    cmd->local_0 = 0xFA000000;
    cmd->local_1 = COLOR_SHIFT(((TextState *) &D_801282C0)->r, 24) |
                   COLOR_SHIFT(((TextState *) &D_801282C0)->g, 16) |
                   COLOR_SHIFT(((TextState *) &D_801282C0)->b, 8) |
                   COLOR_SHIFT(((TextState *) &D_801282C0)->a, 0);
}

// Matching: the line breaks in this function are needed for the match.
void func_800B811C(u8 **dl)
{
    u8 *cmd;
    cmd = *dl;
    *dl = *dl + 8;
    do { *(s32 *) ((s8 *) cmd + 0) = 0xDE000000; *(u8 **) ((s8 *) cmd + 4) = (u8 *) D_8011A668 - 0x80000000; D_801282C5 = 0; } while (0);
}

// Looks up the glyph for *ch and replaces *ch with its index. Returns 0 if missing.
s32 func_800B8148(u8 *ch)
{
    s32 glyph;
    s32 font;
    s32 index;
    index = func_800D35D0(D_801282C6, *ch);
    glyph = index;
    if (index == -1) {
        return 0;
    }
    font = func_800D3524(D_801282C6);
    if (font == 0) {
        return 0;
    }
    D_801282D0 = func_800B0D58(font);
    *ch = (u8) glyph;
    return font;
}

// Draws one glyph as a TEXRECT. Returns the scaled glyph width, or 0 on failure.
// Glyph format: RGBA32, IA16, IA8, I8, I4. The I4 path loads half-width bytes as I8,
// then switches the render tile back to I4.
// Matching: the line breaks in this function are needed for the match.
s32 func_800B81CC(Gfx **dl, s32 pos_x, s32 pos_y, u8 ch)
{
    s32 tex_addr;
    B81CCGlyph *glyph;
    Gfx *gfx;
    f32 unused; // Matching: unused local keeps the stack layout.
    f32 left;
    f32 top;
    f32 width;
    f32 height;

    tex_addr = func_800B8148(&ch);
    if (tex_addr == 0) return 0;
    glyph = func_800B0D6C(tex_addr, ch);
    tex_addr = func_800B0D60(tex_addr) + glyph->offset;
    gfx = *dl;
    if (*(s32 *)&D_801282C0.data[0x10] == 0x800) {
        gDPSetTextureImage(gfx++, G_IM_FMT_RGBA, G_IM_SIZ_32b, glyph->w, tex_addr + 0x80000000);
        gDPSetTile(gfx++, G_IM_FMT_RGBA, G_IM_SIZ_32b, (glyph->x * 2 + 7) >> 3, 0, G_TX_LOADTILE, 0, G_TX_CLAMP, 0, 0, G_TX_CLAMP, 0, 0);
        gDPLoadSync(gfx++); B81CC_UPLOAD_TILE(gfx++, G_LOADTILE, G_TX_LOADTILE, 0, 0, (glyph->x - 1) << 2, (glyph->y - 1) << 2); gDPPipeSync(gfx++);
        gDPSetTile(gfx++, G_IM_FMT_RGBA, G_IM_SIZ_32b, (glyph->x * 2 + 7) >> 3, 0, G_TX_RENDERTILE, 0, G_TX_CLAMP, 0, 0, G_TX_CLAMP, 0, 0);
        B81CC_UPLOAD_TILE(gfx++, G_SETTILESIZE, G_TX_RENDERTILE, 0, 0, (glyph->x - 1) << 2, (glyph->y - 1) << 2);
    } else if (*(s32 *)&D_801282C0.data[0x10] == 0x200) {
        gDPSetTextureImage(gfx++, G_IM_FMT_IA, G_IM_SIZ_16b, glyph->w, tex_addr + 0x80000000);
        gDPSetTile(gfx++, G_IM_FMT_IA, G_IM_SIZ_16b, (glyph->x * 2 + 7) >> 3, 0, G_TX_LOADTILE, 0, G_TX_CLAMP, 0, 0, G_TX_CLAMP, 0, 0);
        gDPLoadSync(gfx++); B81CC_UPLOAD_TILE(gfx++, G_LOADTILE, G_TX_LOADTILE, 0, 0, (glyph->x - 1) << 2, (glyph->y - 1) << 2); gDPPipeSync(gfx++);
        gDPSetTile(gfx++, G_IM_FMT_IA, G_IM_SIZ_16b, (glyph->x * 2 + 7) >> 3, 0, G_TX_RENDERTILE, 0, G_TX_CLAMP, 0, 0, G_TX_CLAMP, 0, 0);
        B81CC_UPLOAD_TILE(gfx++, G_SETTILESIZE, G_TX_RENDERTILE, 0, 0, (glyph->x - 1) << 2, (glyph->y - 1) << 2);
    } else if (*(s32 *)&D_801282C0.data[0x10] == 0x100) {
        gDPSetTextureImage(gfx++, G_IM_FMT_IA, G_IM_SIZ_8b, glyph->w, tex_addr + 0x80000000);
        gDPSetTile(gfx++, G_IM_FMT_IA, G_IM_SIZ_8b, (glyph->x * 1 + 7) >> 3, 0, G_TX_LOADTILE, 0, G_TX_CLAMP, 0, 0, G_TX_CLAMP, 0, 0);
        gDPLoadSync(gfx++); B81CC_UPLOAD_TILE(gfx++, G_LOADTILE, G_TX_LOADTILE, 0, 0, (glyph->x - 1) << 2, (glyph->y - 1) << 2); gDPPipeSync(gfx++);
        gDPSetTile(gfx++, G_IM_FMT_IA, G_IM_SIZ_8b, (glyph->x * 1 + 7) >> 3, 0, G_TX_RENDERTILE, 0, G_TX_CLAMP, 0, 0, G_TX_CLAMP, 0, 0);
        B81CC_UPLOAD_TILE(gfx++, G_SETTILESIZE, G_TX_RENDERTILE, 0, 0, (glyph->x - 1) << 2, (glyph->y - 1) << 2);
    } else if (*(s32 *)&D_801282C0.data[0x10] == 0x40) {
        gDPSetTextureImage(gfx++, G_IM_FMT_I, G_IM_SIZ_8b, glyph->w, tex_addr + 0x80000000);
        gDPSetTile(gfx++, G_IM_FMT_I, G_IM_SIZ_8b, (glyph->x * 1 + 7) >> 3, 0, G_TX_LOADTILE, 0, G_TX_CLAMP, 0, 0, G_TX_CLAMP, 0, 0);
        gDPLoadSync(gfx++); B81CC_UPLOAD_TILE(gfx++, G_LOADTILE, G_TX_LOADTILE, 0, 0, (glyph->x - 1) << 2, (glyph->y - 1) << 2); gDPPipeSync(gfx++);
        gDPSetTile(gfx++, G_IM_FMT_I, G_IM_SIZ_8b, (glyph->x * 1 + 7) >> 3, 0, G_TX_RENDERTILE, 0, G_TX_CLAMP, 0, 0, G_TX_CLAMP, 0, 0);
        B81CC_UPLOAD_TILE(gfx++, G_SETTILESIZE, G_TX_RENDERTILE, 0, 0, (glyph->x - 1) << 2, (glyph->y - 1) << 2);
    } else if (*(s32 *)&D_801282C0.data[0x10] == 0x20) { // I4
        gDPSetTextureImage(gfx++, G_IM_FMT_I, G_IM_SIZ_8b, (glyph->w >> 1), tex_addr + 0x80000000);
        gDPSetTile(gfx++, G_IM_FMT_I, G_IM_SIZ_8b, ((glyph->x >> 1) + 7) >> 3, 0, G_TX_LOADTILE, 0, G_TX_CLAMP, 0, 0, G_TX_CLAMP, 0, 0);
        gDPLoadSync(gfx++); B81CC_UPLOAD_TILE(gfx++, G_LOADTILE, G_TX_LOADTILE, 0, 0, (glyph->x - 1) << 1, (glyph->y - 1) << 2); gDPPipeSync(gfx++);
        gDPSetTile(gfx++, G_IM_FMT_I, G_IM_SIZ_4b, ((glyph->x >> 1) + 7) >> 3, 0, G_TX_RENDERTILE, 0, G_TX_CLAMP, 0, 0, G_TX_CLAMP, 0, 0);
        B81CC_UPLOAD_TILE(gfx++, G_SETTILESIZE, G_TX_RENDERTILE, 0, 0, (glyph->x - 1) << 2, (glyph->y - 1) << 2);
    } else {
        return 0;
    }

    left = pos_x; // scale, optional centering, optional jitter
    width = glyph->x * D_801282C0.value;
    height = glyph->y * D_801282C0.value;
    if (D_801282C0.data[7] == 0 || D_801282C0.data[8] == 0) {
        left -= width * 0.5f;
    }
    top = pos_y - glyph->h * 0.5f;
    if (D_801282C0.data[4] != 0) {
        left += func_800DC178(-2.0f, 2.0f);
        top += func_800DC178(-2.0f, 2.0f);
    }
    { Gfx *_g = (Gfx *)gfx++; _g->words.w0 = (_SHIFTL(0xe4, 24, 8) | _SHIFTL(((s16)(s32)((left + width) * 4.0f) > 0 ? (s16)(s32)((left + width) * 4.0f) : 0), 12, 12) | _SHIFTL(((s16)(s32)((top + height) * 4.0f) > 0 ? (s16)(s32)((top + height) * 4.0f) : 0), 0, 12));
        _g->words.w1 = (_SHIFTL(0, 24, 3) | _SHIFTL(((s16)(s32)(left * 4.0f) > 0 ? (s16)(s32)(left * 4.0f) : 0), 12, 12) | _SHIFTL(((s16)(s32)(top * 4.0f) > 0 ? (s16)(s32)(top * 4.0f) : 0), 0, 12));
        { Gfx *_g = (Gfx *)gfx++; _g->words.w0 = _SHIFTL(0xE1, 24, 8); _g->words.w1 = (unsigned int)(_SHIFTL((0 - (((s16)(s32)(left * 4.0f) < 0) ? (((s16)(s32)(1024.0f / D_801282C0.value) < 0) ? ((((s16)(s32)(left * 4.0f)*(s16)(s32)(1024.0f / D_801282C0.value))>>7) > 0 ? (((s16)(s32)(left * 4.0f)*(s16)(s32)(1024.0f / D_801282C0.value))>>7) : 0) : ((((s16)(s32)(left * 4.0f)*(s16)(s32)(1024.0f / D_801282C0.value))>>7) < 0 ? (((s16)(s32)(left * 4.0f)*(s16)(s32)(1024.0f / D_801282C0.value))>>7) : 0)) : 0)), 16, 16) | _SHIFTL((0 - (((s32)(top * 4.0f) < 0) ? (((s16)(s32)(1024.0f / D_801282C0.value) < 0) ? ((((s16)(s32)(top * 4.0f)*(s16)(s32)(1024.0f / D_801282C0.value))>>7) > 0 ? (((s16)(s32)(top * 4.0f)*(s16)(s32)(1024.0f / D_801282C0.value))>>7) : 0) : ((((s16)(s32)(top * 4.0f)*(s16)(s32)(1024.0f / D_801282C0.value))>>7) < 0 ? (((s16)(s32)(top * 4.0f)*(s16)(s32)(1024.0f / D_801282C0.value))>>7) : 0)) : 0)), 0, 16)); }; { Gfx *_g = (Gfx *)gfx++; _g->words.w0 = _SHIFTL(0xF1, 24, 8); _g->words.w1 = (unsigned int)(_SHIFTL((s32)(1024.0f / D_801282C0.value), 16, 16) | _SHIFTL((s32)(1024.0f / D_801282C0.value), 0, 16)); }; };
    *dl = gfx;
    return (s32)width;
}

// Resets the text state: white, no shake, font 0, no gradient, scale 1.
#ifndef NON_MATCHING

void func_800B8C50(void)
{
    u8 *state = (u8 *) &D_801282C0;
    u8 max_val = 0xFF;

    // Matching: the chained byte copies are needed for the match.
    state[2] = max_val;
    state[1] = state[2];
    state[0] = state[1];
    state[3] = state[0];
    state[9] = 0;
    state[7] = 0;
    state[4] = 0;
    state[6] = 0;
    *(f32 *) (state + 0x14) = 1.0f;
}

#else
void func_800B8C50(void)
#endif

// Sets the text transparency (alpha).
void func_800B8C8C(s32 alpha)
{
    D_801282C0.data[3] = alpha;
}

// Sets the text font.
void func_800B8C98(s32 font)
{
    D_801282C0.data[6] = font;
}

// Sets the text shakiness.
void func_800B8CA4(s32 shakiness)
{
    D_801282C0.data[4] = shakiness;
}

void func_800B8CB0(s32 unk_0)
{
    D_801282C0.data[7] = unk_0;
}

// Sets the text color.
void func_800B8CBC(s8 r, s8 g, s8 b)
{
    D_801282C0.data[0] = r;
    D_801282C0.data[1] = g;
    D_801282C0.data[2] = b;
}

// Sets the color gradient texture (asset id).
void func_800B8CE0(s32 asset_id)
{
    D_801282C0.data[9] = asset_id - 0xC24;
}

// Sets the text size.
void func_800B8CF0(f32 size)
{
    D_801282D4 = size;
}

// Returns the scaled width of a string.
int func_800B8CFC(u32 str)
{
    s32 i;
    s32 width;
    s32 prev_width;
    s32 glyph_width;

    width = 0;
    prev_width = 0;
    for (i = 0; i < func_800E7188((u8 *) str); i++) {
        glyph_width = func_800D36C4(*(u8 *) ((char *) &D_801282C0 + 6), ((u8 *) str)[i]);
        width = (s32) ((f32) width + ((f32) (glyph_width + prev_width) * 0.5f));
        prev_width = glyph_width;
    }
    width *= D_801282C0.value;
    return width;
}

// Draws a single character.
int func_800B8DEC(dl, pos_x, pos_y, ch)
s32 dl;
s32 pos_x;
s32 pos_y;
u8 ch;
{
    if (*(u8 *) ((char *) &D_801282C0 + 0xC)) {
        *(u8 *) ((char *) &D_801282C0 + 0x8) = 0;
        func_800B81CC(dl, pos_x, pos_y, ch);
    }
}

// Draws a string at (pos_x, pos_y).
void func_800B8E28(s32 dl, s32 pos_x, s32 pos_y, u8 *str)
{
    s32 fixed_advance;
    s32 default_advance;
    s32 advance;
    u8 ch;

    if (*(u8 *) ((char *) &D_801282C0 + 0xC) != 0) {
        if (*(u8 *) ((char *) &D_801282C0 + 0x7) != 0) {
            default_advance = (s32) ((f32) func_800D3574(D_801282C0.data[6]) * D_801282C0.value);
        } else {
            fixed_advance = (s32) ((f32) func_800D35BC(D_801282C0.data[6]) * D_801282C0.value);
        }
        *(u8 *) ((char *) &D_801282C0 + 0x8) = 0U;
        ch = *str;
        if (ch != 0) {
            do {
                advance = func_800B81CC(dl, pos_x, pos_y, ch);
                str += 1;
                if ((*(u8 *) ((char *) &D_801282C0 + 0x7) != 0) &&
                    (*(u8 *) ((char *) &D_801282C0 + 0x8) == 0)) {
                    pos_x += advance / 2;
                    *(u8 *) ((char *) &D_801282C0 + 0x8) = 1U;
                } else {
                    pos_x += D_801282C0.data[7] ? (advance ? advance : default_advance) : fixed_advance;
                }
                ch = *str;
            } while (ch != 0);
        }
    }
}

// Draws a string horizontally centered on the 304 px wide screen.
void func_800B8F88(s32 dl, s32 pos_y, s32 str)
{
    func_800B8E28(dl, (s32) (0x130 - func_800B8CFC(str)) / 2, pos_y, str);
}

// Falling weather particles: alloc/free, start/stop, simulation, per-particle model draw.
int func_800B8FE0()
{
    D_8012712C = 0;
}

// Frees the weather emitter and its particle buffer.
void func_800B8FEC(void)
{
    if (*(void **) &D_80127128 != NULL) {
        heap_free(*(void **) ((char *) *(void **) &D_80127128 + 0x1C));
        heap_free(*(void **) &D_80127128);
        *(void **) &D_80127128 = NULL;
        *(int *) ((char *) (void **) &D_80127128 + 4) = 0;
    }
}

// Allocates the emitter and a buffer for 100 particles (0x18 bytes each).
void func_800B9038(void)
{
    func_800B8FEC();
    D_80127128.alloc.emitter = heap_alloc(0x20);
    D_80127128.alloc.emitter->pos_x = D_80127128.alloc.emitter->pos_y = D_80127128.alloc.emitter->pos_z =
        0.0f;
    D_80127128.alloc.emitter->move_x = D_80127128.alloc.emitter->move_y = D_80127128.alloc.emitter->move_z =
        0.0f;
    D_80127128.alloc.count = 0;
    D_80127128.alloc.emitter->particles = heap_alloc(0x960);
    D_80127128.alloc.emitter->state = 0;
}

// Starts spawning particles.
void func_800B90C8()
{
    if (D_80127128.update.emitter != NULL) {
        D_80127128.update.emitter->state = 1;
    }
}

// Stops spawning new particles.
void func_800B90E8()
{
    int emitter;
    if (*(int *) &D_80127128 != 0) {
        emitter = *(int *) &D_80127128;
        *(u8 *) (emitter + 0x18) = 2;
    }
}

// Removes a particle by moving the last one into its slot.
void func_800B9108(s32 index)
{
    D_80127128.drop.count -= 1;
    if (index < D_80127128.drop.count) {
        aligned4_memcpy(&D_80127128.drop.emitter->particles[index],
                        &D_80127128.drop.emitter->particles[D_80127128.drop.count], 0x18);
    }
}

// Updates the weather particles: moves them, culls far ones and spawns new ones.
void func_800B9170(void)
{
    f32 dt;
    s32 i;
    s32 j;
    s32 axis;
    LocalParticle *particle;
    f32 dist;
    f32 spawn_pos[3];
    f32 angle_range;
    s32 k;
    LocalParticle *new_particle;

    if (D_80127128.update.emitter != 0) {
        if (func_800A5490() != 0) {
            D_80127128.update.count = 0;
            return;
        }
        dt = func_800D8FF8();
        axis = (func_8001211C() & 1) * 2;
        func_8008FE68(D_80127138);
        D_80127128.update.emitter->movement[0] =
            D_80127128.update.position[0] - D_80127128.update.emitter->position[0];
        D_80127128.update.emitter->movement[1] =
            D_80127128.update.position[1] - D_80127128.update.emitter->position[1];
        D_80127128.update.emitter->movement[2] =
            D_80127128.update.position[2] - D_80127128.update.emitter->position[2];
        D_80127128.update.emitter->position[0] = D_80127128.update.position[0];
        D_80127128.update.emitter->position[1] = D_80127128.update.position[1];
        D_80127128.update.emitter->position[2] = D_80127128.update.position[2];
        D_80127128.update.height = D_80127128.update.position[1] - 300.0f;
        for (i = 0; i < D_80127128.update.count; i++) {
            particle = D_80127128.update.emitter->particles + i;
            for (j = 0; j < 3; j++) {
                particle->position[j] += particle->velocity[j] * dt;
            }
            particle->velocity[axis] += func_800DC0C0() * 30.0f - 15.0f;
        }
        D_80127128.update.cursor++;
        if (D_80127128.update.cursor < D_80127128.update.count) {
            particle = &D_80127128.update.emitter->particles[D_80127128.update.cursor];
            if (func_800EEAD4(particle->position, D_80127138) > 1.3e+03f) {
                func_800B9108(D_80127128.update.cursor);
            }
        } else {
            D_80127128.update.cursor = 0;
        }
        if (D_80127128.update.emitter->state == 1) {
            if (D_80127128.update.count < 100) {
                new_particle = D_80127128.update.emitter->particles + D_80127128.update.count;
                D_80127128.update.count++;
                dist = func_800DC178(100.0f, 1.3e+03f);
                func_800EFA4C(spawn_pos, 0.0f, func_800DC0C0() * 200.0f + 200.0f, -dist);
                if (func_800EEFD4(D_80127128.update.emitter->movement) < 25.0f) {
                    angle_range = 100.0f;
                } else {
                    angle_range = 70.0f;
                }
                func_800EF934(spawn_pos, spawn_pos, func_800E3A80() + func_800DC178(-angle_range, angle_range));
                func_800EF04C(spawn_pos, D_80127138);
                if (dist < 6.5e+02f) {
                    for (k = 0;
                         k < 5 && func_800E3F8C(spawn_pos[0], spawn_pos[1] - 10.0f, spawn_pos[2]);
                         k++) {
                        spawn_pos[1] += 200.0f;
                    }
                }
                func_800EE7F8(new_particle->position, spawn_pos);
                func_800EFA4C(new_particle->velocity, 0.0f, func_800DC178(-150.0f, -50.0f), 0.0f);
            }
        }
    }
}

// Draws the weather particles and culls those below the lowest height.
// Matching: the line breaks in this function are needed for the match.
void func_800B956C(void) {
    DrawB956C *render;
    AssetB956C *asset;
    u8 *model_data;
    Gfx *dl;
    ParticleB956C *particle;
    if (!D_80127128.draw.pool || !D_80127128.draw.count) return;
    render = func_800A7180();
    asset = func_800D674C(0x9F4);
    func_800E39A8(D_80127148, D_80127154);
    D_80127128.draw.model_dl = (u8 *)asset + asset->unk_C + 8;
    model_data = (u8 *)asset + asset->unk_10;
    D_80127128.draw.radius = func_800B2354(model_data);
    dl = render->dl;
    { Gfx *cmd = dl++; cmd->words.w0 = 0xDB060004; cmd->words.w1 = osVirtualToPhysical(model_data + 0x18); }
    { Gfx *cmd = dl++; cmd->words.w0 = 0xDB060008; cmd->words.w1 = osVirtualToPhysical((u8 *)asset + asset->unk_8 + 0x10); }
    { Gfx *cmd = dl++; cmd->words.w0 = 0xD9FFFFFF; cmd->words.w1 = 1; }
    { Gfx *cmd = dl++; cmd->words.w0 = 0xDE000000; cmd->words.w1 = (u32)((u8 *)D_8011A690 - 0x80000000); }
    { Gfx *cmd = dl++; cmd->words.w0 = 0xDB06000C; cmd->words.w1 = osVirtualToPhysical(D_8011A6B0); }
    render->dl = dl;
    D_80127128.draw.unk_58 = (u8 *)asset + asset->unk_4;
    for (particle = D_80127128.draw.pool->particles; particle < D_80127128.draw.pool->particles + D_80127128.draw.count; particle++) {
        if (!func_800B97A4(&render->dl, &render->mtx, particle) && particle->pos[1] < D_80127128.draw.height) {
            func_800B9108(particle - D_80127128.draw.pool->particles);
            particle--;
        }
    }
}

// Draws one particle if it is visible. Returns 1 if drawn.
s32 func_800B97A4(dl, mtx, particle)
Gfx **dl;
s32 *mtx;
u8 *particle;
{
    func_800EFB24(&D_80127160, particle, ((s32 *) D_80127148));

    if ((*(f32 *) ((s8 *) (s32 *) &D_80127128 + 0x38) > -17000.0f) &&
        (*(f32 *) ((s8 *) (s32 *) &D_80127128 + 0x38) < 17000.0f) &&
        (*(f32 *) ((s8 *) particle + 4) > -200.0f) &&
        (*(f32 *) ((s8 *) (s32 *) &D_80127128 + 0x40) > -17000.0f) &&
        (*(f32 *) ((s8 *) (s32 *) &D_80127128 + 0x40) < 17000.0f) &&
        (func_800E3E8C(particle, *(f32 *) ((s8 *) (s32 *) &D_80127128 + 0x50)) != 0)) {
        mlMtx_set_translation(((f32 *) particle)[0], ((f32 *) particle)[1], ((f32 *) particle)[2]);
        mlMtxApply((Mtx *) *mtx);
        func_800193C4(&D_8012716C, *(u8 **) ((s8 *) (s32 *) &D_80127128 + 0x58) + 0xC);
        mlMtx_set_translation(*(f32 *) ((s8 *) (s32 *) &D_80127128 + 0x44),
                              *(f32 *) ((s8 *) (s32 *) &D_80127128 + 0x48),
                              *(f32 *) ((s8 *) (s32 *) &D_80127128 + 0x4C));
        mlMtxRotYaw(*(f32 *) ((s8 *) (s32 *) &D_80127128 + 0x30));
        mlMtxRotPitch(*(f32 *) ((s8 *) (s32 *) &D_80127128 + 0x2C));
        mlMtxTranslate(-*(f32 *) ((s8 *) *(u8 **) ((s8 *) (s32 *) &D_80127128 + 0x58) + 0xC),
                       -*(f32 *) ((s8 *) *(u8 **) ((s8 *) (s32 *) &D_80127128 + 0x58) + 0x10),
                       -*(f32 *) ((s8 *) *(u8 **) ((s8 *) (s32 *) &D_80127128 + 0x58) + 0x14));
        mlMtxApply((Mtx *) *mtx);
        gDma2p((*dl)++, 0xDA, *mtx, sizeof(Mtx), 2, 0);
        *mtx += 0x40;
        gDma1p((*dl)++, 0xDE,
               osVirtualToPhysical(*(s32 *) ((u8 *) (s32 *) &D_80127128 + 0x54)), 0, 0);
        gDma2p((*dl)++, 0xD8, sizeof(Mtx), sizeof(Mtx), 2, 0);
        return 1;
    }

    return 0;
}

// TU-NOTE: the .data of this file (formerly asm/data/core2/1E91790.data.s) is defined here
// in C; values are taken from the ROM. D_8011A668 is declared as s32[] (uses written as NAME[0]).
u8 D_8011A630[56] ={0xE7, 0x0, 0x0, 0x0, 0x0,  0x0,  0x0,  0x0,  0xD9, 0xC0, 0xFF, 0xFA,
                     0x0,  0x0, 0x0, 0x0, 0xD9, 0xFF, 0xFF, 0xFF, 0x0,  0x20, 0x0,  0x4,
                     0xD7, 0x0, 0x0, 0x2, 0x80, 0x0,  0x80, 0x0,  0xE3, 0x0,  0xC,  0x0,
                     0x0,  0x0, 0x0, 0x0, 0xE3, 0x0,  0x10, 0x1,  0x0,  0x0,  0x0,  0x0,
                     0xDF, 0x0, 0x0, 0x0, 0x0,  0x0,  0x0,  0x0};
s32 D_8011A668[10] = {-0x19000000, 0x0,         -0x1CFFF400, 0x80000, -0x1CFFEDFF,
                      0x2000,      -0x21000000, 0x0,         0x0,     0x0};
Gfx D_8011A690[4] = {0xE7000000, 0x0, 0xE3000800, 0x800000, 0xE3000A01, 0x100000, 0xDF000000, 0x0};
u8 D_8011A6B0[48] = {0xE2, 0x0,  0x0,  0x1C, 0xF,  0xA, 0x40, 0x10, 0xDF, 0x0,  0x0,  0x0,
                     0x0,  0x0,  0x0,  0x0,  0xE2, 0x0, 0x0,  0x1C, 0xC,  0x19, 0x20, 0x58,
                     0xDF, 0x0,  0x0,  0x0,  0x0,  0x0, 0x0,  0x0,  0xE2, 0x0,  0x0,  0x1C,
                     0xC,  0x18, 0x42, 0x50, 0xDF, 0x0, 0x0,  0x0,  0x0,  0x0,  0x0,  0x0};
