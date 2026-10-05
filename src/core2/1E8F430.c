#include "core2/1E8F430.h"
#include <ultra64.h>

#define B62CC_RDPHALF_1 0xE1
#define B62CC_RDPHALF_2 0xF1
#define B62CC_UPLOAD_TILE(pkt, c, tile, uls, ult, lrs, lrt) \
{ \
    Gfx *_g = (Gfx *)(pkt); \
    _g->words.w0 = _SHIFTL(c, 24, 8) | _SHIFTL(uls, 12, 12) | _SHIFTL(ult, 0, 12); \
    _g->words.w1 = _SHIFTL(lrt, 0, 12) | _SHIFTL(tile, 24, 3) | _SHIFTL(lrs, 12, 12); \
}
#define B62CC_GRAD_TILE(pkt, c, tile, uls, ult, lrs, lrt) \
{ \
    Gfx *_g = (Gfx *)(pkt); \
    _g->words.w0 = _SHIFTL(c, 24, 8) | _SHIFTL(uls, 12, 12) | _SHIFTL(ult, 0, 12); \
    _g->words.w1 = _SHIFTL(lrs, 12, 12) | _SHIFTL(tile, 24, 3) | _SHIFTL(lrt, 0, 12); \
}
#define B62CC_RECT_W0(xh, yh) (_SHIFTL(G_TEXRECT, 24, 8) | _SHIFTL(MAX((s16)(xh), 0), 12, 12) | _SHIFTL(MAX((s16)(yh), 0), 0, 12))
#define B62CC_RECT_W1(xl, yl) (_SHIFTL(0, 24, 3) | _SHIFTL(MAX((s16)(xl), 0), 12, 12) | _SHIFTL(MAX((s16)(yl), 0), 0, 12))
#define B62CC_CLIP_DELTA(v, step) (((s16)(step) < 0) ? MAX(((s16)(v) * (s16)(step)) >> 7, 0) : MIN(((s16)(v) * (s16)(step)) >> 7, 0))
#define B62CC_RECT_ST(xl, yl, step) (_SHIFTL(0 - (((s16)(xl) < 0) ? B62CC_CLIP_DELTA(xl, step) : 0), 16, 16) | _SHIFTL(0 - (((yl) < 0) ? B62CC_CLIP_DELTA(yl, step) : 0), 0, 16))
extern u8 D_80128151[];
extern u8 D_80128179[];
extern u8 D_8011A5C2[];
extern int D_80128150;
typedef struct { /* 0x00 */ s16 x; /* 0x02 */ s16 y; /* 0x04 */ s16 gradientY; /* 0x06 */ u16 font : 4; /* */ u16 fixedSpacing : 1; /* */ u16 unk6_10 : 1; /* */ u16 jitter : 1; /* */ u16 unk6_8 : 1; /* */ u16 unk6_7 : 8; /* 0x08 */ f32 scale; /* 0x0C */ u8 *string; /* 0x10 */ u8 rgba[4]; } PrintEntry_800B5C7C;
typedef struct { /* 0x00 */ void *entries; /* 0x04 */ s32 unk04; /* 0x08 */ s32 gradientRows; /* 0x0C */ u8 defRgba[4]; /* 0x10 */ u8 defUnk10; /* 0x11 */ u8 defFont; /* 0x12 */ u8 defFixedSpacing; /* 0x13 */ u8 defJitter; /* 0x14 */ s16 defGradientY; /* 0x16 */ u8 pad16[2]; /* 0x18 */ f32 defScale; /* 0x1C */ u8 unk1C; /* 0x1D */ u8 unk1D; /* 0x1E */ u8 jitter; /* 0x1F */ u8 centered; /* 0x20 */ u8 font; /* 0x21 */ u8 fixedSpacing; /* 0x22 */ s16 gradientY; /* 0x24 */ u8 pad24[4]; /* 0x28 */ s16 unk28; /* 0x2A */ s16 unk2A; } PrintState_800B5C7C;
extern s8 D_801281B0[];
extern void vector_free();
typedef struct { /* 0x00 */ s16 x; /* 0x02 */ s16 y; /* 0x04 */ s16 gradientY; /* 0x06 */ u16 font : 4; /* */ u16 fixedSpacing : 1; /* */ u16 unk6_10 : 1; /* */ u16 jitter : 1; /* */ u16 unk6_8 : 1; /* */ u16 unk6_7 : 8; /* 0x08 */ f32 scale; /* 0x0C */ u8 *string; /* 0x10 */ u8 rgba[4]; } PrintEntry_800B5E74;
typedef struct { /* 0x00 */ void *entries; /* 0x04 */ s32 unk04; /* 0x08 */ s32 gradientRows; /* 0x0C */ u8 defRgba[4]; /* 0x10 */ u8 defUnk10; /* 0x11 */ u8 defFont; /* 0x12 */ u8 defFixedSpacing; /* 0x13 */ u8 defJitter; /* 0x14 */ s16 defGradientY; /* 0x16 */ u8 pad16[2]; /* 0x18 */ f32 defScale; /* 0x1C */ u8 unk1C; /* 0x1D */ u8 unk1D; /* 0x1E */ u8 jitter; /* 0x1F */ u8 centered; /* 0x20 */ u8 font; /* 0x21 */ u8 fixedSpacing; /* 0x22 */ s16 gradientY; /* 0x24 */ u8 unk24; /* 0x25 */ u8 unk25; /* 0x26 */ u8 unk26; /* 0x27 */ u8 unk27; /* 0x28 */ s16 unk28; /* 0x2A */ s16 unk2A; } PrintState_800B5E74;

typedef struct { /* 0x00 */ s16 x; /* 0x02 */ s16 y; /* 0x04 */ s16 gradientY; /* 0x06 */ u16 font : 4; /* */ u16 fixedSpacing : 1; /* */ u16 unk6_10 : 1; /* */ u16 jitter : 1; /* */ u16 unk6_8 : 1; /* */ u16 unk6_7 : 8; /* 0x08 */ f32 scale; /* 0x0C */ u8 *string; /* 0x10 */ u8 rgba[4]; } PrintEntry_800B60C0;
typedef struct { /* 0x00 */ void *entries; /* 0x04 */ s32 unk04; /* 0x08 */ s32 gradientRows; /* 0x0C */ u8 defRgba[4]; /* 0x10 */ u8 defUnk10; /* 0x11 */ u8 defFont; /* 0x12 */ u8 defFixedSpacing; /* 0x13 */ u8 defJitter; /* 0x14 */ s16 defGradientY; /* 0x16 */ u8 pad16[2]; /* 0x18 */ f32 defScale; /* 0x1C */ u8 unk1C; /* 0x1D */ u8 unk1D; /* 0x1E */ u8 jitter; /* 0x1F */ u8 centered; /* 0x20 */ u8 font; /* 0x21 */ u8 fixedSpacing; /* 0x22 */ s16 gradientY; /* 0x24 */ u8 unk24; /* 0x25 */ u8 unk25; /* 0x26 */ u8 unk26; /* 0x27 */ u8 unk27; /* 0x28 */ s16 unk28; /* 0x2A */ s16 unk2A; } PrintState_800B60C0;
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
typedef struct { /* BK texture-block names: w/h describe the source, x/y the drawn extent. */ u8 w, h, x, y; } B62CCGlyph;
typedef struct { s32 local_0; s32 local_1; /* Result of the special draw path's font-resource update. */ s32 local_2; /* Vertical extent used when loading the gradient texture. */ u8 pad_C[0x12]; u8 jitter; u8 centered; /* Initial half-advance adjustment has already been applied. */ u8 font; u8 fixed_spacing; s16 gradient_y; /* -0x7FFF disables the gradient texture. */ u8 pad_24[4]; s16 local_3; /* Resource ID used by the alternate drawing helper. */ s16 local_4; /* Additional alternate-path condition; exact meaning unknown. */ } B62CCState;
extern u8 D_801281A4[];
extern s32 func_800D35BC();
extern void func_800E7694(void);
typedef struct { /* 0x00 */ s16 x; /* 0x02 */ s16 y; /* 0x04 */ s16 gradientY; /* 0x06 */ u16 font : 4; /* */ u16 fixedSpacing : 1; /* */ u16 unk6_10 : 1; /* */ u16 jitter : 1; /* */ u16 unk6_8 : 1; /* */ u16 unk6_7 : 8; /* 0x08 */ f32 scale; /* 0x0C */ u8 *string; /* 0x10 */ u8 rgba[4]; } PrintEntry_800B7174;
typedef struct { /* 0x00 */ void *entries; /* 0x04 */ s32 unk04; /* 0x08 */ s32 gradientRows; /* 0x0C */ u8 defRgba[4]; /* 0x10 */ u8 defUnk10; /* 0x11 */ u8 defFont; /* 0x12 */ u8 defFixedSpacing; /* 0x13 */ u8 defJitter; /* 0x14 */ s16 defGradientY; /* 0x16 */ u8 pad16[2]; /* 0x18 */ f32 defScale; /* 0x1C */ u8 unk1C; /* 0x1D */ u8 unk1D; /* 0x1E */ u8 jitter; /* 0x1F */ u8 centered; /* 0x20 */ u8 font; /* 0x21 */ u8 fixedSpacing; /* 0x22 */ s16 gradientY; /* 0x24 */ u8 pad24[4]; /* 0x28 */ s16 unk28; /* 0x2A */ s16 unk2A; } PrintState_800B7174;
void func_800F2EBC();
typedef struct { /* 0x00 */ s16 x; /* 0x02 */ s16 y; /* 0x04 */ s16 gradientY; /* 0x06 */ u16 font : 4; /* */ u16 fixedSpacing : 1; /* */ u16 unk6_10 : 1; /* */ u16 jitter : 1; /* */ u16 unk6_8 : 1; /* */ u16 unk6_7 : 8; /* 0x08 */ f32 scale; /* 0x0C */ u8 *string; /* 0x10 */ u8 rgba[4]; } PrintEntry_800B71F4;
typedef struct { /* 0x00 */ void *entries; /* 0x04 */ u8 pad04[8]; /* 0x0C */ u8 defRgba[4]; /* 0x10 */ u8 defUnk10; /* 0x11 */ u8 defFont; /* 0x12 */ u8 defFixedSpacing; /* 0x13 */ u8 defJitter; /* 0x14 */ s16 defGradientY; /* 0x16 */ u8 pad16[2]; /* 0x18 */ f32 defScale; /* 0x1C */ u8 unk1C; /* 0x1D */ u8 unk1D; /* 0x1E */ u8 jitter; /* 0x1F */ u8 centered; /* 0x20 */ u8 font; /* 0x21 */ u8 fixedSpacing; /* 0x22 */ s16 gradientY; /* 0x24 */ u8 pad24[4]; /* 0x28 */ s16 unk28; /* 0x2A */ s16 unk2A; } PrintState_800B71F4;
extern void func_800E78C8(Gfx **, s32);
extern void func_800E7778(Gfx **, s32);
extern void func_800E76A4(Gfx **, s32);
extern void func_800E7828();
extern void func_800E7928(Gfx **, s32);
extern s32 func_800D3524(s32);
extern s32 func_800B0D58(s32);
extern s32 func_800B0D60(s32);
typedef struct { /* 0x00 */ s16 x; /* 0x02 */ s16 y; /* 0x04 */ s16 gradientY; /* 0x06 */ u16 font : 4; /* */ u16 fixedSpacing : 1; /* */ u16 background : 1; /* */ u16 jitter : 1; /* */ u16 unk6_8 : 1; /* */ u16 unk6_7 : 8; /* 0x08 */ f32 scale; /* 0x0C */ u8 *string; /* 0x10 */ u8 rgba[4]; } PrintEntry_800B7448;
typedef struct { /* 0x00 */ void *entries; /* 0x04 */ s32 unk04; /* 0x08 */ s32 gradientRows; /* 0x0C */ u8 defRgba[4]; /* 0x10 */ u8 defUnk10; /* 0x11 */ u8 defFont; /* 0x12 */ u8 defFixedSpacing; /* 0x13 */ u8 defJitter; /* 0x14 */ s16 defGradientY; /* 0x16 */ u8 pad16[2]; /* 0x18 */ f32 defScale; /* 0x1C */ u8 unk1C; /* 0x1D */ u8 unk1D; /* 0x1E */ u8 jitter; /* 0x1F */ u8 centered; /* 0x20 */ u8 font; /* 0x21 */ u8 fixedSpacing; /* 0x22 */ s16 gradientY; /* 0x24 */ u8 unk24; /* 0x25 */ u8 unk25; /* 0x26 */ u8 unk26; /* 0x27 */ u8 unk27; /* 0x28 */ s16 unk28; /* 0x2A */ s16 unk2A; } PrintState_800B7448;
extern void *vector_begin(void *);
extern void *vector_end(void *);
extern s32 vector_size(void *);
extern void vector_clear(void *);
extern s32 func_800D3724(s32);
extern s32 func_800E7188();
extern void func_800E79E8(Gfx **);
extern void func_800E7A4C(Gfx **);
extern u8 D_8011A620[];
typedef struct { /* 0x00 */ s16 x; /* 0x02 */ s16 y; /* 0x04 */ s16 gradientY; /* 0x06 */ u16 font : 4; /* */ u16 fixedSpacing : 1; /* */ u16 unk6_10 : 1; /* */ u16 jitter : 1; /* */ u16 unk6_8 : 1; /* */ u16 unk6_7 : 8; /* 0x08 */ f32 scale; /* 0x0C */ u8 *string; /* 0x10 */ u8 rgba[4]; } PrintEntry_800B798C;
typedef struct { /* 0x00 */ void *entries; /* 0x04 */ s32 unk04; /* 0x08 */ s32 gradientRows; /* 0x0C */ u8 defRgba[4]; /* 0x10 */ u8 defUnk10; /* 0x11 */ u8 defFont; /* 0x12 */ u8 defFixedSpacing; /* 0x13 */ u8 defJitter; /* 0x14 */ s16 defGradientY; /* 0x16 */ u8 pad16[2]; /* 0x18 */ f32 defScale; /* 0x1C */ u8 unk1C; /* 0x1D */ u8 unk1D; /* 0x1E */ u8 jitter; /* 0x1F */ u8 centered; /* 0x20 */ u8 font; /* 0x21 */ u8 fixedSpacing; /* 0x22 */ s16 gradientY; /* 0x24 */ u8 pad24[4]; /* 0x28 */ s16 unk28; /* 0x2A */ s16 unk2A; } PrintState_800B798C;
typedef union {
    PrintState_800B5C7C PrintState_800B5C7C;
    void * void_p;
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

void func_800B5B40()
{
  u8 *s0;
  short pad;
  u8 *s1;
 do { s1 = D_80128179; s0 = D_80128151; do { func_800B58D4(*s0); s0++; *(s0 + -1) = 0; } while (s0 != s1); } while (0);
}

void func_800B5B88()
{
  u8 *s0 = ((u8 *) D_80128151), *s1 = &D_8011A5C2, *s2 = ((u8 *) D_80128179);
  do
  {
    s32 res = func_800B5758(s1[1]);
    s1 += 2;
    *(s0++) = res;
  }
  while (s0 != s2);
}

s32 func_800B5BE4(s32 param_0)
{
  u8 *local_0 = &D_80128150;
  local_0 += param_0;
  func_800B56D0(*local_0);
}

u8 *func_800B5C10(s32 param_0, s32 param_1, s32 *param_2, s32 *param_3)
{
  s32 local_0;
  u8 *local_1;
  local_0 = func_800D3524(param_0);
  local_1 = func_800B0D6C(local_0, param_1);
  *param_2 = func_800B0D58(local_0);
  *param_3 = (*((s32 *) (((s8 *) local_1) + 4))) + func_800B0D60(local_0);
  return local_1;
}

void func_800B5C7C(s32 count)
{
    s8 *p;
    s32 i;
    s32 j;
    s32 offset;

    D_80128180.PrintState_800B5C7C.gradientRows = count - 1;

    i = 0;
    offset = 0;
    while (i < count) {
        p = offset + D_801281B0;
        for (j = 0; j < 0x20; j++) {
            p[j] = (s8) ((i * 0xFF) / D_80128180.PrintState_800B5C7C.gradientRows);
        }
        i++;
        offset += 0x20;
    }
    osWritebackDCache(&D_801281B0, count * 0x20);
}

void func_800B5DD4()
{
    func_800B5C7C(0x8);
}

void func_800B5DF4(void) {
}

void func_800B5DFC(void) {
}

void func_800B5E04(void) {
    if (D_80128180.void_p != NULL) {
        vector_free(D_80128180.void_p);
        D_80128180.void_p = NULL;
    }
}

int func_800B5E3C()
{
  if (D_80128180.s32 != 0)
  {
    D_80128180.s32 = vector_defrag(D_80128180.s32);
  }
}

s32 func_800B5E74(letter) u8 letter;
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
                    break;
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
            break;
    }
    return 1;
}

s32 func_800B5FE4(u8 param_0, f32 *param_1, s32 param_2, f32 param_3)
{
  s32 local_0;
  s32 local_1;
  if (D_80128180.arr[0x1C] == 0)
  {
    local_0 = func_800D35D0(D_80128180.arr[0x20], param_0);
    if (local_0 != -1)
    {
      return local_0;
    }
    if (param_0 == 0x20)
    {
      if (D_80128180.arr[0x21] != 0)
      {
        local_1 = func_800D35BC(D_80128180.arr[0x20], param_0);
      }
      else
      {
        local_1 = func_800D3574(D_80128180.arr[0x20], param_0);
      }
      *param_1 += (f32)local_1 * param_3;
      return -1;
    }
  }
  if (func_800B5E74(param_0) != 0) return -1;
  return -1;
}

void func_800B60C0(Gfx **gfx, f32 *xPtr, f32 *yPtr, f32 scale)
{
    f32 x;
    f32 y;
    s32 wq;
    s32 hq;
    s32 w;
    s32 h;
    s32 res;
    s32 pos[2];

    res = func_800D674C(D_80128180.PrintState_800B60C0.unk28);
    func_800AF5B0(res, &w, &h);
    wq = w / 4;
    hq = h / 4;
    if (D_80128180.PrintState_800B60C0.centered == 0) {
        *xPtr -= (f32) wq * 0.5f * scale;
        D_80128180.PrintState_800B60C0.centered = 1;
    }
    x = *xPtr;
    y = *yPtr;
    if (D_80128180.PrintState_800B60C0.jitter != 0) {
        x += func_800DC178(-1.0f, 1.0f) * scale;
        y += func_800DC178(-1.0f, 1.0f) * scale;
    }
    y -= (f32) hq * 0.5f * scale;
    pos[0] = (s32) (x * 4.0f);
    pos[1] = (s32) (y * 4.0f);
    func_800E257C(D_80128180.PrintState_800B60C0.unk27);
    func_800E24F8(D_80128180.PrintState_800B60C0.unk24, D_80128180.PrintState_800B60C0.unk25, D_80128180.PrintState_800B60C0.unk26);
    func_800E2568(w, h);
    func_800E253C(scale);
    func_800E7988(gfx, 0x80000);
    func_800E2E48(gfx, res, D_80128180.PrintState_800B60C0.unk2A - 1, pos);
    *xPtr += (f32) wq * scale;
    func_800E7A2C(gfx);
    func_800E7988(gfx, 0);
    D_80128180.PrintState_800B60C0.unk2A = 0;
    D_80128180.PrintState_800B60C0.unk28 = D_80128180.PrintState_800B60C0.unk2A;
}

void func_800B62CC(Gfx **param_0, u8 param_1, f32 *param_2, f32 *param_3, f32 param_4)
{
    /* Keep declaration order: it reproduces the target's stack homes.
     * local_0: glyph; local_1: decoded glyph index; local_2: texture format;
     * local_3: image address; local_4/local_5: drawing X/Y;
     * local_8: Y before glyph centering; local_6: unscaled advance;
     * local_7: local display-list cursor.
     */
    B62CCGlyph *local_0;
    s32 local_1;
    s32 local_2;
    s32 local_3;
    f32 local_4;
    f32 local_5;
    f32 local_8;
    f32 local_6;
    Gfx *local_7;

    /* The decoder may process formatting/control input without drawing. */
    local_1 = func_800B5FE4(param_1, param_2, param_3, param_4);
    if (D_80128180.B62CCState.local_3 != 0 &&D_80128180.B62CCState.local_4 != 0) {
        func_800B60C0(param_0, param_2, param_3, param_4);
        D_80128180.B62CCState.local_1 = func_800D3724(D_80128180.B62CCState.font);
        return;
    }
    if (local_1 >= 0) {
        func_800E7828(param_0, D_801281A4);
        local_7 = *param_0;
        local_0 = func_800B5C10(D_80128180.B62CCState.font, local_1, &local_2, &local_3);
        /* Fixed spacing uses the font table; otherwise use this glyph width. */
        if (D_80128180.B62CCState.fixed_spacing != 0) {
            local_6 = func_800D35BC(D_80128180.B62CCState.font);
        } else {
            local_6 = local_0->x;
        }
        if (D_80128180.B62CCState.centered == 0) {
            *param_2 -= local_6 * 0.5f * param_4;
            D_80128180.B62CCState.centered = 1;
        }
        local_4 = *param_2;
        local_5 = *param_3;
        if (D_80128180.B62CCState.jitter != 0) {
            local_4 += func_800DC178(-1.0f, 1.0f) * param_4;
            local_5 += func_800DC178(-1.0f, 1.0f) * param_4;
        }
        /* Preserve the jittered baseline for the gradient calculation. */
        local_8 = local_5;
        local_4 += (local_6 - local_0->x) * 0.5f * param_4;
        local_5 -= local_0->h * 0.5f * param_4;

        /* SDK gDPLoadTextureTile family, expanded into readable primitives.
         * Keep load-sync/load-tile pairs on one line: IDO scheduling depends
         * on these boundaries. RGBA32 uses two-byte tile-line units; I4 is
         * loaded through an eight-bit tile and rendered as four-bit data.
         */
        if (local_2 == 0x800) {
            gDPSetTextureImage(local_7++, G_IM_FMT_RGBA, G_IM_SIZ_32b, local_0->w, local_3 + 0x80000000);
            gDPSetTile(local_7++, G_IM_FMT_RGBA, G_IM_SIZ_32b, (local_0->x * 2 + 7) >> 3, 0, G_TX_LOADTILE, 0, G_TX_CLAMP, 0, 0, G_TX_CLAMP, 0, 0);
            gDPLoadSync(local_7++); B62CC_UPLOAD_TILE(local_7++, G_LOADTILE, G_TX_LOADTILE, 0, 0, (local_0->x - 1) << 2, (local_0->y - 1) << 2);
            gDPPipeSync(local_7++);
            gDPSetTile(local_7++, G_IM_FMT_RGBA, G_IM_SIZ_32b, (local_0->x * 2 + 7) >> 3, 0, G_TX_RENDERTILE, 0, G_TX_CLAMP, 0, 0, G_TX_CLAMP, 0, 0);
            B62CC_UPLOAD_TILE(local_7++, G_SETTILESIZE, G_TX_RENDERTILE, 0, 0, (local_0->x - 1) << 2, (local_0->y - 1) << 2);
        } else if (local_2 == 0x200) {
            gDPSetTextureImage(local_7++, G_IM_FMT_IA, G_IM_SIZ_16b, local_0->w, local_3 + 0x80000000);
            gDPSetTile(local_7++, G_IM_FMT_IA, G_IM_SIZ_16b, (local_0->x * 2 + 7) >> 3, 0, G_TX_LOADTILE, 0, G_TX_CLAMP, 0, 0, G_TX_CLAMP, 0, 0);
            gDPLoadSync(local_7++); B62CC_UPLOAD_TILE(local_7++, G_LOADTILE, G_TX_LOADTILE, 0, 0, (local_0->x - 1) << 2, (local_0->y - 1) << 2);
            gDPPipeSync(local_7++);
            gDPSetTile(local_7++, G_IM_FMT_IA, G_IM_SIZ_16b, (local_0->x * 2 + 7) >> 3, 0, G_TX_RENDERTILE, 0, G_TX_CLAMP, 0, 0, G_TX_CLAMP, 0, 0);
            B62CC_UPLOAD_TILE(local_7++, G_SETTILESIZE, G_TX_RENDERTILE, 0, 0, (local_0->x - 1) << 2, (local_0->y - 1) << 2);
        } else if (local_2 == 0x100) {
            gDPSetTextureImage(local_7++, G_IM_FMT_IA, G_IM_SIZ_8b, local_0->w, local_3 + 0x80000000);
            gDPSetTile(local_7++, G_IM_FMT_IA, G_IM_SIZ_8b, (local_0->x * 1 + 7) >> 3, 0, G_TX_LOADTILE, 0, G_TX_CLAMP, 0, 0, G_TX_CLAMP, 0, 0);
            gDPLoadSync(local_7++); B62CC_UPLOAD_TILE(local_7++, G_LOADTILE, G_TX_LOADTILE, 0, 0, (local_0->x - 1) << 2, (local_0->y - 1) << 2);
            gDPPipeSync(local_7++);
            gDPSetTile(local_7++, G_IM_FMT_IA, G_IM_SIZ_8b, (local_0->x * 1 + 7) >> 3, 0, G_TX_RENDERTILE, 0, G_TX_CLAMP, 0, 0, G_TX_CLAMP, 0, 0);
            B62CC_UPLOAD_TILE(local_7++, G_SETTILESIZE, G_TX_RENDERTILE, 0, 0, (local_0->x - 1) << 2, (local_0->y - 1) << 2);
        } else if (local_2 == 0x40) {
            gDPSetTextureImage(local_7++, G_IM_FMT_I, G_IM_SIZ_8b, local_0->w, local_3 + 0x80000000);
            gDPSetTile(local_7++, G_IM_FMT_I, G_IM_SIZ_8b, (local_0->x * 1 + 7) >> 3, 0, G_TX_LOADTILE, 0, G_TX_CLAMP, 0, 0, G_TX_CLAMP, 0, 0);
            gDPLoadSync(local_7++); B62CC_UPLOAD_TILE(local_7++, G_LOADTILE, G_TX_LOADTILE, 0, 0, (local_0->x - 1) << 2, (local_0->y - 1) << 2);
            gDPPipeSync(local_7++);
            gDPSetTile(local_7++, G_IM_FMT_I, G_IM_SIZ_8b, (local_0->x * 1 + 7) >> 3, 0, G_TX_RENDERTILE, 0, G_TX_CLAMP, 0, 0, G_TX_CLAMP, 0, 0);
            B62CC_UPLOAD_TILE(local_7++, G_SETTILESIZE, G_TX_RENDERTILE, 0, 0, (local_0->x - 1) << 2, (local_0->y - 1) << 2);
        } else if (local_2 == 0x20) {
            gDPSetTextureImage(local_7++, G_IM_FMT_I, G_IM_SIZ_8b, (local_0->w >> 1), local_3 + 0x80000000);
            gDPSetTile(local_7++, G_IM_FMT_I, G_IM_SIZ_8b, ((local_0->x >> 1) + 7) >> 3, 0, G_TX_LOADTILE, 0, G_TX_CLAMP, 0, 0, G_TX_CLAMP, 0, 0);
            gDPLoadSync(local_7++); B62CC_UPLOAD_TILE(local_7++, G_LOADTILE, G_TX_LOADTILE, 0, 0, (local_0->x - 1) << 1, (local_0->y - 1) << 2);
            gDPPipeSync(local_7++);
            gDPSetTile(local_7++, G_IM_FMT_I, G_IM_SIZ_4b, ((local_0->x >> 1) + 7) >> 3, 0, G_TX_RENDERTILE, 0, G_TX_CLAMP, 0, 0, G_TX_CLAMP, 0, 0);
            B62CC_UPLOAD_TILE(local_7++, G_SETTILESIZE, G_TX_RENDERTILE, 0, 0, (local_0->x - 1) << 2, (local_0->y - 1) << 2);
        } else if (local_2 == 4) {
            gDPSetTextureImage(local_7++, G_IM_FMT_CI, G_IM_SIZ_8b, local_0->w, local_3 + 0x80000000);
            gDPSetTile(local_7++, G_IM_FMT_CI, G_IM_SIZ_8b, (local_0->x * 1 + 7) >> 3, 0, G_TX_LOADTILE, 0, G_TX_CLAMP, 0, 0, G_TX_CLAMP, 0, 0);
            gDPLoadSync(local_7++); B62CC_UPLOAD_TILE(local_7++, G_LOADTILE, G_TX_LOADTILE, 0, 0, (local_0->x - 1) << 2, (local_0->y - 1) << 2);
            gDPPipeSync(local_7++);
            gDPSetTile(local_7++, G_IM_FMT_CI, G_IM_SIZ_8b, (local_0->x * 1 + 7) >> 3, 0, G_TX_RENDERTILE, 0, G_TX_CLAMP, 0, 0, G_TX_CLAMP, 0, 0);
            B62CC_UPLOAD_TILE(local_7++, G_SETTILESIZE, G_TX_RENDERTILE, 0, 0, (local_0->x - 1) << 2, (local_0->y - 1) << 2);
        }
        /* Load a clipped strip of the second (gradient) texture at TMEM 0x100.
         * Use the pre-centering Y, clamp the source start to the strip extent,
         * and keep the destination offset for the render-tile coordinates.
         * The two paired command lines below are also scheduling-sensitive.
         */
        if (D_80128180.B62CCState.gradient_y != -0x7FFF) {
            s32 local_9;
            s32 local_10;
            local_9 = (D_80128180.B62CCState.gradient_y - local_8) - D_80128180.B62CCState.local_2;
            local_10 = -local_9;
            if (local_10 < 0) local_10 = 0;
            if (D_80128180.B62CCState.local_2 < local_10) local_10 = D_80128180.B62CCState.local_2;
            if (local_9 < 0) local_9 = 0;
            gDPSetTextureImage(local_7++, G_IM_FMT_I, G_IM_SIZ_8b, 32, ((u8 *) D_801281B0) - 0x80000000);
            gDPSetTile(local_7++, G_IM_FMT_I, G_IM_SIZ_8b, (local_0->x + 8) >> 3, 0x100, 7, 0, G_TX_CLAMP, 0, 0, G_TX_CLAMP, 0, 0);
            gDPLoadSync(local_7++); B62CC_GRAD_TILE(local_7++, G_LOADTILE, 7, 0, local_10 << 2, local_0->x << 2, D_80128180.B62CCState.local_2 << 2);
            gDPPipeSync(local_7++);
            gDPSetTile(local_7++, G_IM_FMT_I, G_IM_SIZ_8b, (local_0->x + 8) >> 3, 0x100, 1, 0, G_TX_CLAMP, 0, 0, G_TX_CLAMP, 0, 0); B62CC_GRAD_TILE(local_7++, G_SETTILESIZE, 1, 0, (local_10 + local_9) << 2, local_0->x << 2, (D_80128180.B62CCState.local_2 + local_9) << 2);
        }
        /* SDK scissored rectangle, kept in three explicit command blocks.
         * These statement boundaries are required by the matching IDO schedule.
         */
        { Gfx *_g = local_7++; _g->words.w0 = B62CC_RECT_W0((s32)((local_4 + local_0->x * param_4) * 4.0f), (s32)((local_5 + local_0->y * param_4) * 4.0f));
            _g->words.w1 = B62CC_RECT_W1((s32)(local_4 * 4.0f), (s32)(local_5 * 4.0f));
            { Gfx *_g = local_7++; _g->words.w0 = _SHIFTL(B62CC_RDPHALF_1, 24, 8); _g->words.w1 = (u32)B62CC_RECT_ST((s32)(local_4 * 4.0f), (s32)(local_5 * 4.0f), (s32)(1024.0f / param_4)); }
            { Gfx *_g = local_7++;
                _g->words.w0 = _SHIFTL(B62CC_RDPHALF_2, 24, 8); _g->words.w1 = (u32)(_SHIFTL((s32)(1024.0f / param_4), 16, 16) | _SHIFTL((s32)(1024.0f / param_4), 0, 16));
            }
        }
        *param_2 += local_6 * param_4;
        *param_0 = local_7;
        func_800E7694();
    }
}

void func_800B7174(PrintEntry_800B7174 *e)
{
    D_80128180.PrintState_800B7174.centered = D_80128180.PrintState_800B7174.unk1C = D_80128180.PrintState_800B7174.unk1D = 0;
    D_80128180.PrintState_800B7174.font = e->font;
    D_80128180.PrintState_800B7174.gradientY = e->gradientY;
    D_80128180.PrintState_800B7174.fixedSpacing = e->fixedSpacing;
    D_80128180.PrintState_800B7174.jitter = e->jitter;
    D_80128180.PrintState_800B7174.unk2A = 0;
    D_80128180.PrintState_800B7174.unk28 = D_80128180.PrintState_800B7174.unk2A;
    func_800F2EBC(D_801281A4, e->rgba, e);
}

void func_800B71F4(Gfx **gfx, PrintEntry_800B71F4 *e)
{
    s32 tex;
    s32 fmt;
    void *pal;

    func_800E78C8(gfx, (e->font == 1) ? 0x2000 : 0);
    if (e->gradientY != -0x7FFF) {
        func_800E7778(gfx, 0x100000);
        func_800E76A4(gfx, 1);
    } else {
        func_800E7778(gfx, 0);
        func_800E76A4(gfx, 0);
    }
    func_800E7828(gfx, e->rgba);
    tex = func_800D3524(e->font);
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

void func_800B7448(Gfx **gfx)
{
    s32 i;
    f32 _x;
    f32 _y;
    f32 width;
    s32 fw;
    PrintEntry_800B7448 *end;
    PrintEntry_800B7448 *start;
    PrintEntry_800B7448 *e;

    if (D_80128180.PrintState_800B7448.entries != NULL && vector_size(D_80128180.PrintState_800B7448.entries) > 0) {
        func_800E79E8(gfx);
        func_800E7988(gfx, 0);
        start = vector_begin(D_80128180.PrintState_800B7448.entries);
        end = vector_end(D_80128180.PrintState_800B7448.entries);
        for (e = start; e < end; e++) {
            D_80128180.PrintState_800B7448.unk04 = func_800D3724(e->font);
            if (D_80128180.PrintState_800B7448.unk04 != 0) {
                _x = (f32) e->x;
                _y = (f32) e->y;
                if (e->background) {
                    fw = func_800D35BC(e->font);
                    width = (f32) ((func_800E7188(e->string) - 1) * fw);
                    func_800E7828(gfx, D_8011A620);
                    func_800E7778(gfx, 0);
                    func_800E76A4(gfx, 2);
                    gDPScisFillRectangle((*gfx)++, _x - fw / 2 - 1.0f, _y - fw / 2 - 1.0f,
                                         _x + width + fw / 2, fw / 2 + _y + 1.0f);
                    func_800E7694();
                }
                func_800B71F4(gfx, e);
                func_800B7174(e);
                for (i = 0; e->string[i] != 0 || D_80128180.PrintState_800B7448.unk1D != 0 || D_80128180.PrintState_800B7448.unk1C != 0; i++) {
                    func_800B62CC(gfx, e->string[i], &_x, &_y, e->scale);
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

void func_800B798C(s32 x, s32 y, u8 *string)
{
    PrintEntry_800B798C *e;

    if (string != NULL) {
        if (D_80128180.PrintState_800B798C.entries == NULL) {
            D_80128180.PrintState_800B798C.entries = vector_new(0x14, 8);
        }
        e = vector_push_back(((PrintState_800B798C *) D_80128180.arr));
        e->x = x;
        e->y = y;
        e->string = string;
        e->font = D_80128180.PrintState_800B798C.defFont;
        e->fixedSpacing = D_80128180.PrintState_800B798C.defFixedSpacing;
        e->unk6_10 = D_80128180.PrintState_800B798C.defUnk10;
        e->jitter = D_80128180.PrintState_800B798C.defJitter;
        e->gradientY = D_80128180.PrintState_800B798C.defGradientY;
        e->scale = D_80128180.PrintState_800B798C.defScale;
        e->rgba[0] = D_80128180.PrintState_800B798C.defRgba[0];
        e->rgba[1] = D_80128180.PrintState_800B798C.defRgba[1];
        e->rgba[2] = D_80128180.PrintState_800B798C.defRgba[2];
        e->rgba[3] = D_80128180.PrintState_800B798C.defRgba[3];
    }
}

void func_800B7A98()
{
  unsigned long long new_var;
  new_var = (D_80128180.arr[0xE] = (D_80128180.arr[0xF] = 0xFF));
  D_80128180.arr[0xD] = new_var;
  D_80128180.arr[0xC] = 0xFF;
  D_80128180.arr[0x13] = 0;
  D_80128180.arr[0x10] = 0;
  D_80128180.arr[0x12] = 0;
  D_80128180.arr[0x11] = 0;
  *((s16 *) (&D_80128180.arr[0x14])) = -0x7FFF;
  *((f32 *) (&D_80128180.arr[0x18])) = 1.0f;
}

void func_800B7ADC(s32 param_0)
{
    D_8012818F = param_0;
}

int func_800B7AE8(s32 param_0)
{
  if (param_0 != 0)
  {
    D_80128190 = 1;
  }
  else
  {
    D_80128190 = 0;
  }
  if (param_0 != 0)
  {
    func_800B7B68(1);
  }
}

void func_800B7B2C(s32 param_0)
{
    D_80128194 = param_0;
}

void func_800B7B38(s32 param_0)
{
    D_80128191 = param_0;
}

int func_800B7B44(s32 param_0)
{
  if (param_0 != 0)
  {
    D_80128193 = 1;
  }
  else
  {
    D_80128193 = 0;
  }
}

int func_800B7B68(param_0) s32 param_0;
{
  if (param_0 != 0)
  {
    D_80128192 = 1;
  }
  else
  {
    D_80128192 = 0;
  }
}

void func_800B7B8C(s32 param_0, s32 param_1, s32 param_2)
{
  ((u8 *) D_80128180.arr)[0xc] = param_0;
  ((u8 *) D_80128180.arr)[0xd] = param_1;
  ((u8 *) D_80128180.arr)[0xe] = param_2;
}

void func_800B7BA4(f32 param_0)
{
  D_80128198 = param_0;
}

void func_800B7BB0()
{
  if (D_801282B0 != 0)
  {
    _fxleaves_entrypoint_1(D_801282B0);
  }
  if (D_801282B4 != 0)
  {
    _fxrain_entrypoint_1(D_801282B4);
  }
  if (D_80127128 != 0)
  {
    func_800B956C();
  }
}

int func_800B7C10()
{
  if (!D_801282B0)
  {
    D_801282B0 = _fxleaves_entrypoint_4(0x32);
  }
  return D_801282B0;
}

int func_800B7C54()
{
  if (!D_801282B4)
  {
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

s32 func_800B7CC4(void){
    if(D_801282B0){
        _fxleaves_entrypoint_3(D_801282B0);
    }

    if(D_801282B4){
        _fxrain_entrypoint_4(D_801282B4);
    }

    func_800B8FEC();
}

void func_800B7D14(void) {
    ((s32 *) &D_801282B0)[0] = 0;
    ((s32 *) &D_801282B0)[1] = 0;
}

s32 func_800B7D28(void){
    if(D_801282B0)
        _fxleaves_entrypoint_5(D_801282B0);
    
    if(D_801282B4)
        _fxrain_entrypoint_7(D_801282B4);

    func_800B90C8();
}

s32 func_800B7D78(void){
    if(D_801282B0)
        _fxleaves_entrypoint_6(D_801282B0);
    
    if(D_801282B4)
        _fxrain_entrypoint_8(D_801282B4);

    func_800B90E8();
}

void func_800B7DC8()
{
  if (D_801282B0 != 0)
  {
    _fxleaves_entrypoint_0(D_801282B0);
    _fxleaves_entrypoint_6(D_801282B0);
  }
  if (D_801282B4 != 0)
  {
    _fxrain_entrypoint_0(D_801282B4);
    _fxrain_entrypoint_8(D_801282B4);
  }
  func_800B8FE0();
  func_800B90E8();
}

void func_800B7E38()
{
  if (D_801282B0)
  {
    _fxleaves_entrypoint_7(D_801282B0);
  }
  if (D_801282B4)
  {
    _fxrain_entrypoint_9(D_801282B4);
  }
  if (D_80127128)
  {
    func_800B9170();
  }
}
