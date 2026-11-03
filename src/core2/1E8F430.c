#include "core2/1E8F430.h"
#include <ultra64.h>

// Hand-expanded SDK texture-tile and TEXRECT commands for func_800B62CC.
// Matching: their statement boundaries steer IDO's scheduling.
#define B62CC_RDPHALF_1 0xE1
#define B62CC_RDPHALF_2 0xF1

#define B62CC_UPLOAD_TILE(pkt, c, tile, uls, ult, lrs, lrt)                                        \
    {                                                                                              \
        Gfx *_g = (Gfx *) pkt;                                                                     \
        _g->words.w0 = _SHIFTL(c, 24, 8) | _SHIFTL(uls, 12, 12) | _SHIFTL(ult, 0, 12);             \
        _g->words.w1 = _SHIFTL(lrt, 0, 12) | _SHIFTL(tile, 24, 3) | _SHIFTL(lrs, 12, 12);          \
    }

#define B62CC_GRAD_TILE(pkt, c, tile, uls, ult, lrs, lrt)                                          \
    {                                                                                              \
        Gfx *_g = (Gfx *) pkt;                                                                     \
        _g->words.w0 = _SHIFTL(c, 24, 8) | _SHIFTL(uls, 12, 12) | _SHIFTL(ult, 0, 12);             \
        _g->words.w1 = _SHIFTL(lrs, 12, 12) | _SHIFTL(tile, 24, 3) | _SHIFTL(lrt, 0, 12);          \
    }

#define B62CC_RECT_W0(xh, yh)                                                                      \
    (_SHIFTL(G_TEXRECT, 24, 8) | _SHIFTL(MAX((s16) (xh), 0), 12, 12) |                             \
     _SHIFTL(MAX((s16) (yh), 0), 0, 12))
#define B62CC_RECT_W1(xl, yl)                                                                      \
    (_SHIFTL(0, 24, 3) | _SHIFTL(MAX((s16) (xl), 0), 12, 12) | _SHIFTL(MAX((s16) (yl), 0), 0, 12))
#define B62CC_CLIP_DELTA(v, step)                                                                  \
    (((s16) (step) < 0) ? MAX(((s16) (v) * (s16) (step)) >> 7, 0)                                  \
                        : MIN(((s16) (v) * (s16) (step)) >> 7, 0))
#define B62CC_RECT_ST(xl, yl, step)                                                                \
    (_SHIFTL(0 - (((s16) (xl) < 0) ? B62CC_CLIP_DELTA(xl, step) : 0), 16, 16) |                    \
     _SHIFTL(0 - (((yl) < 0) ? B62CC_CLIP_DELTA(yl, step) : 0), 0, 16))
extern u8 D_80128151[];
extern u8 D_80128179[];
extern u8 D_8011A5C2[];
extern int D_80128150;
typedef struct {
    void *entries;
    s32 unk04;
    s32 gradientRows;
    u8 defRgba[4];
    u8 defUnk10;
    u8 defFont;
    u8 defFixedSpacing;
    u8 defJitter;
    s16 defGradientY;
    u8 pad16[2];
    f32 defScale;
    u8 unk1C;
    u8 unk1D;
    u8 jitter;
    u8 centered;
    u8 font;
    u8 fixedSpacing;
    s16 gradientY;
    u8 pad24[4];
    s16 unk28;
    s16 unk2A;
} PrintState_800B5C7C;
extern s8 D_801281B0[];
extern void vector_free();
typedef struct {
    void *entries;
    s32 unk04;
    s32 gradientRows;
    u8 defRgba[4];
    u8 defUnk10;
    u8 defFont;
    u8 defFixedSpacing;
    u8 defJitter;
    s16 defGradientY;
    u8 pad16[2];
    f32 defScale;
    u8 unk1C;
    u8 unk1D;
    u8 jitter;
    u8 centered;
    u8 font;
    u8 fixedSpacing;
    s16 gradientY;
    u8 unk24;
    u8 unk25;
    u8 unk26;
    u8 unk27;
    s16 unk28;
    s16 unk2A;
} PrintState_800B5E74;

typedef struct {
    void *entries;
    s32 unk04;
    s32 gradientRows;
    u8 defRgba[4];
    u8 defUnk10;
    u8 defFont;
    u8 defFixedSpacing;
    u8 defJitter;
    s16 defGradientY;
    u8 pad16[2];
    f32 defScale;
    u8 unk1C;
    u8 unk1D;
    u8 jitter;
    u8 centered;
    u8 font;
    u8 fixedSpacing;
    s16 gradientY;
    u8 unk24;
    u8 unk25;
    u8 unk26;
    u8 unk27;
    s16 unk28;
    s16 unk2A;
} PrintState_800B60C0;
extern s32 func_800D674C(s32);
extern void func_800AF5B0(s32, s32 *, s32 *);
extern f32 func_800DC178(f32, f32);
extern void func_800E257C(s32);
extern void func_800E24F8(s32, s32, s32);
extern void func_800E2568(s32, s32);
extern void func_800E253C(f32);
extern void func_800E7988(Gfx **, s32);
extern void func_800E2E48(Gfx **, s32, s32, s32 *);
extern void func_800E7A2C(Gfx **);
// w/h describe the source texture, x/y the drawn extent.
typedef struct {
    u8 w, h, x, y;
} B62CCGlyph;
typedef struct {
    s32 entries;
    s32 font_loaded;
    s32 gradient_rows; // vertical extent of the gradient texture strip
    u8 pad_C[0x12];
    u8 jitter;
    u8 centered; // half-advance adjustment already applied
    u8 font;
    u8 fixed_spacing;
    s16 gradient_y; // -0x7FFF disables the gradient
    u8 pad_24[4];
    s16 icon_id;
    s16 unk_2A;
} B62CCState;
extern u8 D_801281A4[];
extern s32 func_800D35BC();
extern void func_800E7694(void);
typedef struct {
    s16 x;
    s16 y;
    s16 gradientY;
    u16 font : 4;
    u16 fixedSpacing : 1;
    u16 unk6_10 : 1;
    u16 jitter : 1;
    u16 unk6_8 : 1;
    u16 unk6_7 : 8;
    f32 scale;
    u8 *string;
    u8 rgba[4];
} PrintEntry_800B7174;
typedef struct {
    void *entries;
    s32 unk04;
    s32 gradientRows;
    u8 defRgba[4];
    u8 defUnk10;
    u8 defFont;
    u8 defFixedSpacing;
    u8 defJitter;
    s16 defGradientY;
    u8 pad16[2];
    f32 defScale;
    u8 unk1C;
    u8 unk1D;
    u8 jitter;
    u8 centered;
    u8 font;
    u8 fixedSpacing;
    s16 gradientY;
    u8 pad24[4];
    s16 unk28;
    s16 unk2A;
} PrintState_800B7174;
void func_800F2EBC();
typedef struct {
    s16 x;
    s16 y;
    s16 gradientY;
    u16 font : 4;
    u16 fixedSpacing : 1;
    u16 unk6_10 : 1;
    u16 jitter : 1;
    u16 unk6_8 : 1;
    u16 unk6_7 : 8;
    f32 scale;
    u8 *string;
    u8 rgba[4];
} PrintEntry_800B71F4;
extern void func_800E78C8(Gfx **, s32);
extern void func_800E7778(Gfx **, s32);
extern void func_800E76A4(Gfx **, s32);
extern void func_800E7828();
extern void func_800E7928(Gfx **, s32);
extern s32 func_800D3524(s32);
extern s32 func_800B0D58(s32);
extern s32 func_800B0D60(s32);
typedef struct {
    s16 x;
    s16 y;
    s16 gradientY;
    u16 font : 4;
    u16 fixedSpacing : 1;
    u16 background : 1;
    u16 jitter : 1;
    u16 unk6_8 : 1;
    u16 unk6_7 : 8;
    f32 scale;
    u8 *string;
    u8 rgba[4];
} PrintEntry_800B7448;
typedef struct {
    void *entries;
    s32 unk04;
    s32 gradientRows;
    u8 defRgba[4];
    u8 defUnk10;
    u8 defFont;
    u8 defFixedSpacing;
    u8 defJitter;
    s16 defGradientY;
    u8 pad16[2];
    f32 defScale;
    u8 unk1C;
    u8 unk1D;
    u8 jitter;
    u8 centered;
    u8 font;
    u8 fixedSpacing;
    s16 gradientY;
    u8 unk24;
    u8 unk25;
    u8 unk26;
    u8 unk27;
    s16 unk28;
    s16 unk2A;
} PrintState_800B7448;
extern void *vector_begin(void *);
extern void *vector_end(void *);
extern s32 vector_size(void *);
extern void vector_clear(void *);
extern s32 func_800D3724(s32);
extern s32 func_800E7188();
extern void func_800E79E8(Gfx **);
extern void func_800E7A4C(Gfx **);
extern u8 D_8011A620[];
typedef struct {
    s16 x;
    s16 y;
    s16 gradientY;
    u16 font : 4;
    u16 fixedSpacing : 1;
    u16 unk6_10 : 1;
    u16 jitter : 1;
    u16 unk6_8 : 1;
    u16 unk6_7 : 8;
    f32 scale;
    u8 *string;
    u8 rgba[4];
} PrintEntry_800B798C;
typedef struct {
    void *entries;
    s32 unk04;
    s32 gradientRows;
    u8 defRgba[4];
    u8 defUnk10;
    u8 defFont;
    u8 defFixedSpacing;
    u8 defJitter;
    s16 defGradientY;
    u8 pad16[2];
    f32 defScale;
    u8 unk1C;
    u8 unk1D;
    u8 jitter;
    u8 centered;
    u8 font;
    u8 fixedSpacing;
    s16 gradientY;
    u8 pad24[4];
    s16 unk28;
    s16 unk2A;
} PrintState_800B798C;
// D_80128180 is the text print state; each function views it through its own struct.
typedef union {
    PrintState_800B5C7C PrintState_800B5C7C;
    void *void_p;
    s32 s32;
    PrintState_800B5E74 PrintState_800B5E74;
    PrintState_800B60C0 PrintState_800B60C0;
    B62CCState B62CCState;
    PrintState_800B7174 PrintState_800B7174;
    PrintState_800B7448 PrintState_800B7448;
    PrintState_800B798C PrintState_800B798C;
    u8 arr[1];
} Union_D_80128180;
extern Union_D_80128180 D_80128180;
extern PrintEntry_800B798C *vector_new(s32, s32);
extern PrintEntry_800B798C *vector_push_back();
extern u8 D_8012818F;
extern u8 D_80128190;
extern s16 D_80128194;
extern u8 D_80128191;
extern s8 D_80128193;
extern u8 D_80128192;
extern float D_80128198;
extern s32 D_801282B0;
extern s32 D_80127128;
extern s32 _fxrain_entrypoint_5(s32);
extern void func_800B8FEC();
extern void func_800B90C8();
extern void func_800B90E8();
void func_800B7A98();
int func_800B7B68();

extern s32 D_801282B4;

// Matching: the line breaks in this function are needed for the match.
// Clear all 40 emitter slots.
void func_800B5B40()
{
    u8 *slot;
    u8 *end;
    do { end = D_80128179; slot = D_80128151; do { func_800B58D4(*slot); slot++; *(slot + -1) = 0; } while (slot != end); } while (0);
}

// Create the 40 emitter slots from the sprite-id table D_8011A5C2.
void func_800B5B88()
{
    u8 *slot = (u8 *) D_80128151, *entry = &D_8011A5C2, *end = (u8 *) D_80128179;
    do {
        s32 handle = func_800B5758(entry[1]);
        entry += 2;
        *slot++ = handle;
    } while (slot != end);
}

// Fetch emitter slot by index.
s32 func_800B5BE4(s32 index)
{
    u8 *slot = &D_80128150;
    slot += index;
    func_800B56D0(*slot);
}

// Look up a glyph: returns its entry, sets the texture format and image address.
u8 *func_800B5C10(s32 font, s32 glyph_id, s32 *format, s32 *image)
{
    s32 tex;
    u8 *glyph;
    tex = func_800D3524(font);
    glyph = func_800B0D6C(tex, glyph_id);
    *format = func_800B0D58(tex);
    *image = *(s32 *) ((s8 *) glyph + 4) + func_800B0D60(tex);
    return glyph;
}

// Fill the gradient texture with count rows ramping 0..0xFF.
void func_800B5C7C(s32 count)
{
    s8 *row;
    s32 i;
    s32 j;
    s32 row_offset;

    D_80128180.PrintState_800B5C7C.gradientRows = count - 1;

    i = 0;
    row_offset = 0;
    while (i < count) {
        row = row_offset + D_801281B0;
        for (j = 0; j < 0x20; j++) {
            row[j] = (s8) ((i * 0xFF) / D_80128180.PrintState_800B5C7C.gradientRows);
        }
        i++;
        row_offset += 0x20;
    }
    osWritebackDCache(&D_801281B0, count * 0x20);
}

void func_800B5DD4()
{
    func_800B5C7C(0x8);
}

void func_800B5DF4(void)
{
}

void func_800B5DFC(void)
{
}

void func_800B5E04(void)
{
    if (D_80128180.void_p != NULL) {
        vector_free(D_80128180.void_p);
        D_80128180.void_p = NULL;
    }
}

int func_800B5E3C()
{
    if (D_80128180.s32 != 0) {
        D_80128180.s32 = vector_defrag(D_80128180.s32);
    }
}

// Print control codes: 0xFD starts an escape ('l','h','j','a','c','i','p'), 0xFE/0xFF set a flag.
// Returns 1 when consumed, 0x21 for an ordinary character.
s32 func_800B5E74(letter)
u8 letter;
{
    s32 mode;

    mode = D_80128180.PrintState_800B5E74.unk1C;
    D_80128180.PrintState_800B5E74.unk1C = 0;
    switch (mode) {
        case 2:
            D_80128180.PrintState_800B5E74.unk24 = letter;
            D_80128180.PrintState_800B5E74.unk1C = 3;
            break;
        case 3:
            D_80128180.PrintState_800B5E74.unk25 = letter;
            D_80128180.PrintState_800B5E74.unk1C = 4;
            break;
        case 4:
            D_80128180.PrintState_800B5E74.unk26 = letter;
            break;
        case 5:
            D_80128180.PrintState_800B5E74.unk27 = letter;
            break;
        case 6:
            D_80128180.PrintState_800B5E74.unk28 = letter;
            D_80128180.PrintState_800B5E74.unk1C = 7;
            break;
        case 7:
            D_80128180.PrintState_800B5E74.unk28 |= letter << 8;
            D_80128180.PrintState_800B5E74.unk1C = 8;
            break;
        case 8:
            D_80128180.PrintState_800B5E74.unk2A = letter;
            break;
        case 1:
            switch (letter) {
                case 'l':
                    D_80128180.PrintState_800B5E74.jitter = 0;
                    break;
                case 'h':
                    D_80128180.PrintState_800B5E74.jitter = 1;
                    break;
                case 'j':
                    D_80128180.PrintState_800B5E74.font = 2;
                    D_80128180.PrintState_800B5E74.unk1D = 0;
                    break;
                case 'a':
                    D_80128180.PrintState_800B5E74.unk1C = 5;
                    break;
                case 'c':
                    D_80128180.PrintState_800B5E74.unk1C = 2;
                    break;
                case 'i':
                    D_80128180.PrintState_800B5E74.unk1C = 6;
                case 'p':
                    break;
                default:
                    return 0;
            }
            break;
        default:
            switch (letter) {
                case 0xFD:
                    D_80128180.PrintState_800B5E74.unk1C = 1;
                    break;
                case 0xFE:
                    D_80128180.PrintState_800B5E74.unk1D = 1;
                    break;
                case 0xFF:
                    D_80128180.PrintState_800B5E74.unk1D = 2;
                    break;
                default:
                    return 0x21;
            }
    }
    return 1;
}

// Returns the glyph index for ch, or -1 for spaces and control codes.
s32 func_800B5FE4(u8 ch, f32 *cursor_x, s32 unk_2, f32 scale)
{
    s32 glyph;
    s32 advance;
    if (D_80128180.arr[0x1C] == 0) {
        glyph = func_800D35D0(D_80128180.arr[0x20], ch);
        if (glyph != -1) {
            return glyph;
        }
        if (ch == 0x20) {
            if (D_80128180.arr[0x21] != 0) {
                advance = func_800D35BC(D_80128180.arr[0x20], ch);
            } else {
                advance = func_800D3574(D_80128180.arr[0x20], ch);
            }
            *cursor_x += (f32) advance * scale;
            return -1;
        }
    }
    if (func_800B5E74(ch) != 0)
        return -1;
    return -1;
}

// Draw an inline sprite icon at the cursor.
void func_800B60C0(Gfx **gfx, f32 *cursor_x, f32 *cursor_y, f32 scale)
{
    f32 x;
    f32 y;
    s32 quarter_w;
    s32 quarter_h;
    s32 w;
    s32 h;
    s32 sprite;
    s32 pos[2];

    sprite = func_800D674C(D_80128180.PrintState_800B60C0.unk28);
    func_800AF5B0(sprite, &w, &h);
    quarter_w = w / 4;
    quarter_h = h / 4;
    if (D_80128180.PrintState_800B60C0.centered == 0) {
        *cursor_x -= (f32) quarter_w * 0.5f * scale;
        D_80128180.PrintState_800B60C0.centered = 1;
    }
    x = *cursor_x;
    y = *cursor_y;
    if (D_80128180.PrintState_800B60C0.jitter != 0) {
        x += func_800DC178(-1.0f, 1.0f) * scale;
        y += func_800DC178(-1.0f, 1.0f) * scale;
    }
    y -= (f32) quarter_h * 0.5f * scale;
    pos[0] = (s32) (x * 4.0f);
    pos[1] = (s32) (y * 4.0f);
    func_800E257C(D_80128180.PrintState_800B60C0.unk27);
    func_800E24F8(D_80128180.PrintState_800B60C0.unk24, D_80128180.PrintState_800B60C0.unk25,
                  D_80128180.PrintState_800B60C0.unk26);
    func_800E2568(w, h);
    func_800E253C(scale);
    func_800E7988(gfx, 0x80000);
    func_800E2E48(gfx, sprite, D_80128180.PrintState_800B60C0.unk2A - 1, pos);
    *cursor_x += (f32) quarter_w * scale;
    func_800E7A2C(gfx);
    func_800E7988(gfx, 0);
    D_80128180.PrintState_800B60C0.unk2A = 0;
    D_80128180.PrintState_800B60C0.unk28 = D_80128180.PrintState_800B60C0.unk2A;
}

// Matching: the line breaks in this function are needed for the match.
// Matching: the local declaration order reproduces the target's stack homes.
// Draw one character (glyph rectangle or inline icon) at the cursor and advance it.
void func_800B62CC(Gfx **gfx, u8 ch, f32 *cursor_x, f32 *cursor_y, f32 scale)
{
    B62CCGlyph *glyph;
    s32 glyph_id;
    s32 format;
    s32 image;
    f32 draw_x;
    f32 draw_y;
    f32 base_y;
    f32 advance;
    Gfx *dl;

    glyph_id = func_800B5FE4(ch, cursor_x, cursor_y, scale);
    if (D_80128180.B62CCState.icon_id != 0 &&D_80128180.B62CCState.unk_2A != 0) {
        func_800B60C0(gfx, cursor_x, cursor_y, scale);
        D_80128180.B62CCState.font_loaded = func_800D3724(D_80128180.B62CCState.font);
        return;
    }
    if (glyph_id >= 0) {
        func_800E7828(gfx, D_801281A4);
        dl = *gfx;
        glyph = func_800B5C10(D_80128180.B62CCState.font, glyph_id, &format, &image);
        if (D_80128180.B62CCState.fixed_spacing != 0) {
            advance = func_800D35BC(D_80128180.B62CCState.font);
        } else {
            advance = glyph->x;
        }
        if (D_80128180.B62CCState.centered == 0) {
            *cursor_x -= advance * 0.5f * scale;
            D_80128180.B62CCState.centered = 1;
        }
        draw_x = *cursor_x;
        draw_y = *cursor_y;
        if (D_80128180.B62CCState.jitter != 0) {
            draw_x += func_800DC178(-1.0f, 1.0f) * scale;
            draw_y += func_800DC178(-1.0f, 1.0f) * scale;
        }
        base_y = draw_y; // jittered baseline, used for the gradient
        draw_x += (advance - glyph->x) * 0.5f * scale;
        draw_y -= glyph->h * 0.5f * scale;

        if (format == 0x800) {
            gDPSetTextureImage(dl++, G_IM_FMT_RGBA, G_IM_SIZ_32b, glyph->w, image + 0x80000000);
            gDPSetTile(dl++, G_IM_FMT_RGBA, G_IM_SIZ_32b, (glyph->x * 2 + 7) >> 3, 0, G_TX_LOADTILE, 0, G_TX_CLAMP, 0, 0, G_TX_CLAMP, 0, 0);
            gDPLoadSync(dl++); B62CC_UPLOAD_TILE(dl++, G_LOADTILE, G_TX_LOADTILE, 0, 0, (glyph->x - 1) << 2, (glyph->y - 1) << 2);
            gDPPipeSync(dl++);
            gDPSetTile(dl++, G_IM_FMT_RGBA, G_IM_SIZ_32b, (glyph->x * 2 + 7) >> 3, 0, G_TX_RENDERTILE, 0, G_TX_CLAMP, 0, 0, G_TX_CLAMP, 0, 0);
            B62CC_UPLOAD_TILE(dl++, G_SETTILESIZE, G_TX_RENDERTILE, 0, 0, (glyph->x - 1) << 2, (glyph->y - 1) << 2);
        } else if (format == 0x200) {
            gDPSetTextureImage(dl++, G_IM_FMT_IA, G_IM_SIZ_16b, glyph->w, image + 0x80000000);
            gDPSetTile(dl++, G_IM_FMT_IA, G_IM_SIZ_16b, (glyph->x * 2 + 7) >> 3, 0, G_TX_LOADTILE, 0, G_TX_CLAMP, 0, 0, G_TX_CLAMP, 0, 0);
            gDPLoadSync(dl++); B62CC_UPLOAD_TILE(dl++, G_LOADTILE, G_TX_LOADTILE, 0, 0, (glyph->x - 1) << 2, (glyph->y - 1) << 2);
            gDPPipeSync(dl++);
            gDPSetTile(dl++, G_IM_FMT_IA, G_IM_SIZ_16b, (glyph->x * 2 + 7) >> 3, 0, G_TX_RENDERTILE, 0, G_TX_CLAMP, 0, 0, G_TX_CLAMP, 0, 0);
            B62CC_UPLOAD_TILE(dl++, G_SETTILESIZE, G_TX_RENDERTILE, 0, 0, (glyph->x - 1) << 2, (glyph->y - 1) << 2);
        } else if (format == 0x100) {
            gDPSetTextureImage(dl++, G_IM_FMT_IA, G_IM_SIZ_8b, glyph->w, image + 0x80000000);
            gDPSetTile(dl++, G_IM_FMT_IA, G_IM_SIZ_8b, (glyph->x * 1 + 7) >> 3, 0, G_TX_LOADTILE, 0, G_TX_CLAMP, 0, 0, G_TX_CLAMP, 0, 0);
            gDPLoadSync(dl++); B62CC_UPLOAD_TILE(dl++, G_LOADTILE, G_TX_LOADTILE, 0, 0, (glyph->x - 1) << 2, (glyph->y - 1) << 2);
            gDPPipeSync(dl++);
            gDPSetTile(dl++, G_IM_FMT_IA, G_IM_SIZ_8b, (glyph->x * 1 + 7) >> 3, 0, G_TX_RENDERTILE, 0, G_TX_CLAMP, 0, 0, G_TX_CLAMP, 0, 0);
            B62CC_UPLOAD_TILE(dl++, G_SETTILESIZE, G_TX_RENDERTILE, 0, 0, (glyph->x - 1) << 2, (glyph->y - 1) << 2);
        } else if (format == 0x40) {
            gDPSetTextureImage(dl++, G_IM_FMT_I, G_IM_SIZ_8b, glyph->w, image + 0x80000000);
            gDPSetTile(dl++, G_IM_FMT_I, G_IM_SIZ_8b, (glyph->x * 1 + 7) >> 3, 0, G_TX_LOADTILE, 0, G_TX_CLAMP, 0, 0, G_TX_CLAMP, 0, 0);
            gDPLoadSync(dl++); B62CC_UPLOAD_TILE(dl++, G_LOADTILE, G_TX_LOADTILE, 0, 0, (glyph->x - 1) << 2, (glyph->y - 1) << 2);
            gDPPipeSync(dl++);
            gDPSetTile(dl++, G_IM_FMT_I, G_IM_SIZ_8b, (glyph->x * 1 + 7) >> 3, 0, G_TX_RENDERTILE, 0, G_TX_CLAMP, 0, 0, G_TX_CLAMP, 0, 0);
            B62CC_UPLOAD_TILE(dl++, G_SETTILESIZE, G_TX_RENDERTILE, 0, 0, (glyph->x - 1) << 2, (glyph->y - 1) << 2);
        } else if (format == 0x20) {
            gDPSetTextureImage(dl++, G_IM_FMT_I, G_IM_SIZ_8b, (glyph->w >> 1), image + 0x80000000);
            gDPSetTile(dl++, G_IM_FMT_I, G_IM_SIZ_8b, ((glyph->x >> 1) + 7) >> 3, 0, G_TX_LOADTILE, 0, G_TX_CLAMP, 0, 0, G_TX_CLAMP, 0, 0);
            gDPLoadSync(dl++); B62CC_UPLOAD_TILE(dl++, G_LOADTILE, G_TX_LOADTILE, 0, 0, (glyph->x - 1) << 1, (glyph->y - 1) << 2);
            gDPPipeSync(dl++);
            gDPSetTile(dl++, G_IM_FMT_I, G_IM_SIZ_4b, ((glyph->x >> 1) + 7) >> 3, 0, G_TX_RENDERTILE, 0, G_TX_CLAMP, 0, 0, G_TX_CLAMP, 0, 0);
            B62CC_UPLOAD_TILE(dl++, G_SETTILESIZE, G_TX_RENDERTILE, 0, 0, (glyph->x - 1) << 2, (glyph->y - 1) << 2);
        } else if (format == 4) {
            gDPSetTextureImage(dl++, G_IM_FMT_CI, G_IM_SIZ_8b, glyph->w, image + 0x80000000);
            gDPSetTile(dl++, G_IM_FMT_CI, G_IM_SIZ_8b, (glyph->x * 1 + 7) >> 3, 0, G_TX_LOADTILE, 0, G_TX_CLAMP, 0, 0, G_TX_CLAMP, 0, 0);
            gDPLoadSync(dl++); B62CC_UPLOAD_TILE(dl++, G_LOADTILE, G_TX_LOADTILE, 0, 0, (glyph->x - 1) << 2, (glyph->y - 1) << 2);
            gDPPipeSync(dl++);
            gDPSetTile(dl++, G_IM_FMT_CI, G_IM_SIZ_8b, (glyph->x * 1 + 7) >> 3, 0, G_TX_RENDERTILE, 0, G_TX_CLAMP, 0, 0, G_TX_CLAMP, 0, 0);
            B62CC_UPLOAD_TILE(dl++, G_SETTILESIZE, G_TX_RENDERTILE, 0, 0, (glyph->x - 1) << 2, (glyph->y - 1) << 2);
        }
        if (D_80128180.B62CCState.gradient_y != -0x7FFF) { // load a strip of the gradient texture at TMEM 0x100
            s32 dst_offset;
            s32 src_start;
            dst_offset = (D_80128180.B62CCState.gradient_y - base_y) - D_80128180.B62CCState.gradient_rows;
            src_start = -dst_offset;
            if (src_start < 0) src_start = 0;
            if (D_80128180.B62CCState.gradient_rows < src_start) src_start = D_80128180.B62CCState.gradient_rows;
            if (dst_offset < 0) dst_offset = 0;
            gDPSetTextureImage(dl++, G_IM_FMT_I, G_IM_SIZ_8b, 32, (u8 *) D_801281B0 - 0x80000000);
            gDPSetTile(dl++, G_IM_FMT_I, G_IM_SIZ_8b, (glyph->x + 8) >> 3, 0x100, 7, 0, G_TX_CLAMP, 0, 0, G_TX_CLAMP, 0, 0);
            gDPLoadSync(dl++); B62CC_GRAD_TILE(dl++, G_LOADTILE, 7, 0, src_start << 2, glyph->x << 2, D_80128180.B62CCState.gradient_rows << 2);
            gDPPipeSync(dl++);
            gDPSetTile(dl++, G_IM_FMT_I, G_IM_SIZ_8b, (glyph->x + 8) >> 3, 0x100, 1, 0, G_TX_CLAMP, 0, 0, G_TX_CLAMP, 0, 0); B62CC_GRAD_TILE(dl++, G_SETTILESIZE, 1, 0, (src_start + dst_offset) << 2, glyph->x << 2, (D_80128180.B62CCState.gradient_rows + dst_offset) << 2);
        }
        { Gfx *_g = dl++; _g->words.w0 = B62CC_RECT_W0((s32)((draw_x + glyph->x * scale) * 4.0f), (s32)((draw_y + glyph->y * scale) * 4.0f));
            _g->words.w1 = B62CC_RECT_W1((s32)(draw_x * 4.0f), (s32)(draw_y * 4.0f));
            { Gfx *_g = dl++; _g->words.w0 = _SHIFTL(B62CC_RDPHALF_1, 24, 8); _g->words.w1 = (u32)B62CC_RECT_ST((s32)(draw_x * 4.0f), (s32)(draw_y * 4.0f), (s32)(1024.0f / scale)); }
            { Gfx *_g = dl++;
                _g->words.w0 = _SHIFTL(B62CC_RDPHALF_2, 24, 8); _g->words.w1 = (u32)(_SHIFTL((s32)(1024.0f / scale), 16, 16) | _SHIFTL((s32)(1024.0f / scale), 0, 16));
            }
        }
        *cursor_x += advance * scale;
        *gfx = dl;
        func_800E7694();
    }
}

// Reset the per-string print state from the queued entry.
void func_800B7174(PrintEntry_800B7174 *entry)
{
    D_80128180.PrintState_800B7174.centered = D_80128180.PrintState_800B7174.unk1C =
        D_80128180.PrintState_800B7174.unk1D = 0;
    D_80128180.PrintState_800B7174.font = entry->font;
    D_80128180.PrintState_800B7174.gradientY = entry->gradientY;
    D_80128180.PrintState_800B7174.fixedSpacing = entry->fixedSpacing;
    D_80128180.PrintState_800B7174.jitter = entry->jitter;
    D_80128180.PrintState_800B7174.unk2A = 0;
    D_80128180.PrintState_800B7174.unk28 = D_80128180.PrintState_800B7174.unk2A;
    func_800F2EBC(D_801281A4, entry->rgba, entry);
}

// Set up render state (gradient, color, palette) for the entry's font.
void func_800B71F4(Gfx **gfx, PrintEntry_800B71F4 *entry)
{
    s32 tex;
    s32 fmt;
    void *pal;

    func_800E78C8(gfx, (entry->font == 1) ? 0x2000 : 0);
    if (entry->gradientY != -0x7FFF) {
        func_800E7778(gfx, 0x100000);
        func_800E76A4(gfx, 1);
    } else {
        func_800E7778(gfx, 0);
        func_800E76A4(gfx, 0);
    }
    func_800E7828(gfx, entry->rgba);
    tex = func_800D3524(entry->font);
    fmt = func_800B0D58(tex);
    if (fmt & 5) {
        pal = func_800B0D60(tex);
        func_800E7928(gfx, 0x8000);
        if (fmt & 1) {
            gDPLoadTLUT_pal16((*gfx)++, 0, pal);
        } else {
            gDPLoadTLUT_pal256((*gfx)++, pal);
        }
    } else {
        func_800E7928(gfx, 0);
    }
}

// Draw all queued strings, then clear the queue and reset the style defaults.
void func_800B7448(Gfx **gfx)
{
    s32 i;
    f32 x;
    f32 y;
    f32 width;
    s32 font_width;
    PrintEntry_800B7448 *end;
    PrintEntry_800B7448 *start;
    PrintEntry_800B7448 *entry;

    if (D_80128180.PrintState_800B7448.entries != NULL &&
        vector_size(D_80128180.PrintState_800B7448.entries) > 0) {
        func_800E79E8(gfx);
        func_800E7988(gfx, 0);
        start = vector_begin(D_80128180.PrintState_800B7448.entries);
        end = vector_end(D_80128180.PrintState_800B7448.entries);
        for (entry = start; entry < end; entry++) {
            D_80128180.PrintState_800B7448.unk04 = func_800D3724(entry->font);
            if (D_80128180.PrintState_800B7448.unk04 != 0) {
                x = (f32) entry->x;
                y = (f32) entry->y;
                if (entry->background) { // filled box behind the text
                    font_width = func_800D35BC(entry->font);
                    width = (f32) ((func_800E7188(entry->string) - 1) * font_width);
                    func_800E7828(gfx, D_8011A620);
                    func_800E7778(gfx, 0);
                    func_800E76A4(gfx, 2);
                    gDPScisFillRectangle((*gfx)++, x - font_width / 2 - 1.0f, y - font_width / 2 - 1.0f,
                                         x + width + font_width / 2, font_width / 2 + y + 1.0f);
                    func_800E7694();
                }
                func_800B71F4(gfx, entry);
                func_800B7174(entry);
                for (i = 0; entry->string[i] != 0 || D_80128180.PrintState_800B7448.unk1D != 0 ||
                            D_80128180.PrintState_800B7448.unk1C != 0;
                     i++) {
                    func_800B62CC(gfx, entry->string[i], &x, &y, entry->scale);
                    if (D_80128180.PrintState_800B7448.unk04 == 0) {
                        break;
                    }
                }
            }
        }
        func_800E7A4C(gfx);
        vector_clear(D_80128180.PrintState_800B7448.entries);
    }
    func_800B7A98();
}

// Queue a string at (x, y) with the current style defaults.
void func_800B798C(s32 x, s32 y, u8 *string)
{
    PrintEntry_800B798C *entry;

    if (string != NULL) {
        if (D_80128180.PrintState_800B798C.entries == NULL) {
            D_80128180.PrintState_800B798C.entries = vector_new(0x14, 8);
        }
        entry = vector_push_back((PrintState_800B798C *) D_80128180.arr);
        entry->x = x;
        entry->y = y;
        entry->string = string;
        entry->font = D_80128180.PrintState_800B798C.defFont;
        entry->fixedSpacing = D_80128180.PrintState_800B798C.defFixedSpacing;
        entry->unk6_10 = D_80128180.PrintState_800B798C.defUnk10;
        entry->jitter = D_80128180.PrintState_800B798C.defJitter;
        entry->gradientY = D_80128180.PrintState_800B798C.defGradientY;
        entry->scale = D_80128180.PrintState_800B798C.defScale;
        entry->rgba[0] = D_80128180.PrintState_800B798C.defRgba[0];
        entry->rgba[1] = D_80128180.PrintState_800B798C.defRgba[1];
        entry->rgba[2] = D_80128180.PrintState_800B798C.defRgba[2];
        entry->rgba[3] = D_80128180.PrintState_800B798C.defRgba[3];
    }
}

// Reset the style defaults: white, font 0, no jitter, no gradient, scale 1.
void func_800B7A98()
{
    // Matching: the 64-bit temporary is needed for the match.
    unsigned long long max_channel;
    max_channel = (D_80128180.arr[0xE] = (D_80128180.arr[0xF] = 0xFF));
    D_80128180.arr[0xD] = max_channel;
    D_80128180.arr[0xC] = 0xFF;
    D_80128180.arr[0x13] = 0;
    D_80128180.arr[0x10] = 0;
    D_80128180.arr[0x12] = 0;
    D_80128180.arr[0x11] = 0;
    *(s16 *) &D_80128180.arr[0x14] = -0x7FFF;
    *(f32 *) &D_80128180.arr[0x18] = 1.0f;
}

// Set the default text alpha.
void func_800B7ADC(s32 alpha)
{
    D_8012818F = alpha;
}

// Set the default background flag; enabling it also forces fixed spacing.
int func_800B7AE8(s32 enabled)
{
    if (enabled != 0) {
        D_80128190 = 1;
    } else {
        D_80128190 = 0;
    }
    if (enabled != 0) {
        func_800B7B68(1);
    }
}

// Set the default gradient Y.
void func_800B7B2C(s32 gradient_y)
{
    D_80128194 = gradient_y;
}

// Set the default font.
void func_800B7B38(s32 font)
{
    D_80128191 = font;
}

// Set the default jitter flag.
int func_800B7B44(s32 enabled)
{
    if (enabled != 0) {
        D_80128193 = 1;
    } else {
        D_80128193 = 0;
    }
}

// Set the default fixed-spacing flag.
int func_800B7B68(enabled)
s32 enabled;
{
    if (enabled != 0) {
        D_80128192 = 1;
    } else {
        D_80128192 = 0;
    }
}

// Set the default text color (RGB).
void func_800B7B8C(s32 r, s32 g, s32 b)
{
    ((u8 *) D_80128180.arr)[0xc] = r;
    ((u8 *) D_80128180.arr)[0xd] = g;
    ((u8 *) D_80128180.arr)[0xe] = b;
}

// Set the default text scale.
void func_800B7BA4(f32 scale)
{
    D_80128198 = scale;
}

// Update the weather effects (fxleaves, fxrain and the in-core effect).
void func_800B7BB0()
{
    if (D_801282B0 != 0) {
        _fxleaves_entrypoint_1(D_801282B0);
    }
    if (D_801282B4 != 0) {
        _fxrain_entrypoint_1(D_801282B4);
    }
    if (D_80127128 != 0) {
        func_800B956C();
    }
}

// Create the fxleaves instance if needed and return its handle.
int func_800B7C10()
{
    if (!D_801282B0) {
        D_801282B0 = _fxleaves_entrypoint_4(0x32);
    }
    return D_801282B0;
}

// Create the fxrain instance if needed and return its handle.
int func_800B7C54()
{
    if (!D_801282B4) {
        D_801282B4 = _fxrain_entrypoint_5(0x1E);
    }
    return D_801282B4;
}

s32 func_800B7C98()
{
    return D_801282B4;
}

void func_800B7CA4()
{
    func_800B9038();
}

s32 func_800B7CC4(void)
{
    if (D_801282B0) {
        _fxleaves_entrypoint_3(D_801282B0);
    }

    if (D_801282B4) {
        _fxrain_entrypoint_4(D_801282B4);
    }

    func_800B8FEC();
}

// Forget both overlay handles.
void func_800B7D14(void)
{
    ((s32 *) &D_801282B0)[0] = 0;
    ((s32 *) &D_801282B0)[1] = 0;
}

s32 func_800B7D28(void)
{
    if (D_801282B0)
        _fxleaves_entrypoint_5(D_801282B0);

    if (D_801282B4)
        _fxrain_entrypoint_7(D_801282B4);

    func_800B90C8();
}

s32 func_800B7D78(void)
{
    if (D_801282B0)
        _fxleaves_entrypoint_6(D_801282B0);

    if (D_801282B4)
        _fxrain_entrypoint_8(D_801282B4);

    func_800B90E8();
}

void func_800B7DC8()
{
    if (D_801282B0 != 0) {
        _fxleaves_entrypoint_0(D_801282B0);
        _fxleaves_entrypoint_6(D_801282B0);
    }
    if (D_801282B4 != 0) {
        _fxrain_entrypoint_0(D_801282B4);
        _fxrain_entrypoint_8(D_801282B4);
    }
    func_800B8FE0();
    func_800B90E8();
}

// Draw the weather effects.
void func_800B7E38()
{
    if (D_801282B0) {
        _fxleaves_entrypoint_7(D_801282B0);
    }
    if (D_801282B4) {
        _fxrain_entrypoint_9(D_801282B4);
    }
    if (D_80127128) {
        func_800B9170();
    }
}

// TU-NOTE: the .data of this file is defined here in C (values from the ROM).
// D_8011A5C2 = D_8011A5C0 + 0x2 is a linker symbol in undefined_syms.us.txt.
u32 D_8011A5C0[24] = {0x11E,      0x2500319,  0x4030514,  0x632071E,  0x81E0928,  0xA1E0B0F,
                      0xC0F0D23,  0xE320F1E,  0x100F1128, 0x12321328, 0x141E151E, 0x161E171E,
                      0x1850191E, 0x1A281B1E, 0x1C141D14, 0x1E141F14, 0x2014211E, 0x22282332,
                      0x24322514, 0x26142714, 0x28140000, 0x0,        0x0,        0x0};
u8 D_8011A620[16] = {0x0, 0x0, 0x0, 0x64, 0x0, 0x0, 0x0, 0x0,
                     0x0, 0x0, 0x0, 0x0,  0x0, 0x0, 0x0, 0x0};
