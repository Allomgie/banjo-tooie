#include "core2/1E91790.h"
#include "common.h"
#include <ultra64.h>

#define SHL(x,n) ((unsigned int)(((unsigned int)(x) & 255) << (n)))
#define CMD(a,b) { GfxB7F14 *local_0 = (*param_0)++; local_0->local_0 = (a); local_0->local_1 = (b); }
#define COLOR_SHIFT(x,n) ((unsigned int)(((unsigned int)(x) & ((1 << 8) - 1)) << (n)))
#define B81CC_UPLOAD_TILE(pkt, c, tile, uls, ult, lrs, lrt) \
{ \
    Gfx *_g = (Gfx *)(pkt); \
    _g->words.w0 = _SHIFTL(c, 24, 8) | _SHIFTL(uls, 12, 12) | _SHIFTL(ult, 0, 12); \
    _g->words.w1 = _SHIFTL(lrt, 0, 12) | _SHIFTL(tile, 24, 3) | _SHIFTL(lrs, 12, 12); \
}
#define B81CC_GRAD_TILE(pkt, c, tile, uls, ult, lrs, lrt) \
{ \
    Gfx *_g = (Gfx *)(pkt); \
    _g->words.w0 = _SHIFTL(c, 24, 8) | _SHIFTL(uls, 12, 12) | _SHIFTL(ult, 0, 12); \
    _g->words.w1 = _SHIFTL(lrs, 12, 12) | _SHIFTL(tile, 24, 3) | _SHIFTL(lrt, 0, 12); \
}
#define B81CC_RECT_W0(xh, yh) (_SHIFTL(G_TEXRECT, 24, 8) | _SHIFTL(MAX((s16)(xh), 0), 12, 12) | _SHIFTL(MAX((s16)(yh), 0), 0, 12))
#define B81CC_RECT_W1(xl, yl) (_SHIFTL(0, 24, 3) | _SHIFTL(MAX((s16)(xl), 0), 12, 12) | _SHIFTL(MAX((s16)(yl), 0), 0, 12))
#define B81CC_CLIP_DELTA(v, step) (((s16)(step) < 0) ? MAX(((s16)(v) * (s16)(step)) >> 7, 0) : MIN(((s16)(v) * (s16)(step)) >> 7, 0))
#define B81CC_RECT_ST(xl, yl, step) (_SHIFTL(0 - (((s16)(xl) < 0) ? B81CC_CLIP_DELTA(xl, step) : 0), 16, 16) | _SHIFTL(0 - (((yl) < 0) ? B81CC_CLIP_DELTA(yl, step) : 0), 0, 16))
typedef struct { u8 pad0[0xA]; u8 unkA; u8 unkB; } G_B7EA0;
extern void func_800AF614(void *, void *, s32, s32, s32, s32, s32, s32 *, s32 *);
typedef struct { u8 field_0, field_1, field_2, field_3, field_4, field_5, field_6, field_7, field_8, field_9; u8 pad[10]; f32 value; } TextState;
typedef struct { u32 local_0, local_1; } GfxB7F14;
extern u8 D_8011A630[];
extern s32 func_800D3724(s32);
extern s32 D_8011A668;
extern s8 D_801282C5;
extern s32 D_801282D0;
typedef struct { u8 w, h, x, y; s32 offset; } B81CCGlyph;
extern B81CCGlyph *func_800B0D6C(s32, s32);
extern s32 func_800B0D60(s32);
extern f32 func_800DC178(f32, f32);
extern s32 D_8012712C;
typedef struct { f32 local_0; f32 local_1; f32 local_2; f32 local_3; f32 local_4; f32 local_5; u8 local_6; u8 pad_19[3]; void *local_7; } Struct800B9038Local;
typedef struct { Struct800B9038Local *local_0; u8 pad_4[8]; s32 local_1; } Struct800B9038;
typedef struct { u8 b[0x18]; } E_B9108;
typedef struct { u8 pad0[0x1C]; E_B9108 *unk1C; } H_B9108;
typedef struct { H_B9108 *unk0; s32 unk4; } G_B9108;
extern void aligned4_memcpy(void *, void *, s32);
typedef struct LocalParticle { f32 position[3], velocity[3]; } LocalParticle;
typedef struct LocalEmitter { f32 position[3], movement[3]; u8 state; LocalParticle *particles; } LocalEmitter;
typedef struct LocalWeather { LocalEmitter *emitter; s32 count; void *model; s32 cursor; f32 position[3], height; } LocalWeather;
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
typedef struct { f32 local_0[3]; u8 pad[12]; } ParticleB956C;
typedef struct { u8 pad[0x1C]; ParticleB956C *local_0; } PoolB956C;
typedef struct { PoolB956C *local_0; s32 local_1; u8 pad[0x14]; f32 local_2; u8 pad2[0x30]; f32 local_3; void *local_4, *local_5; } StateB956C;
typedef struct { s32 pad; s32 local_0; s16 local_1; s16 pad2; s32 local_2, local_3; } AssetB956C;
typedef struct { Gfx *local_0; Mtx *local_1; } DrawB956C;
typedef union {
    Struct800B9038 a;
    LocalWeather w;
    G_B9108 g;
    StateB956C s;
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

void func_800B7EA0(void *param_0, s32 param_1) {
    s32 pad;
    s32 sp38;
    s32 sp34;
    func_800AF614(param_0, func_800D674C(param_1), 0, 0x100, 1, 2, 2, &sp38, &sp34);
    ((G_B7EA0 *)&D_801282C0)->unkA = sp38;
    ((G_B7EA0 *)&D_801282C0)->unkB = sp34;
}

void func_800B7F14(GfxB7F14 **param_0) {
    CMD(0xDE000000, (u32)(D_8011A630 - 0x80000000));
    CMD(0xE3001201, ((TextState *)&D_801282C0)->field_6 == 1 ? 0x2000 : 0);
    CMD(0xFA000000, SHL(((TextState *)&D_801282C0)->field_0,24) | SHL(((TextState *)&D_801282C0)->field_1,16) | SHL(((TextState *)&D_801282C0)->field_2,8) | SHL(((TextState *)&D_801282C0)->field_3,0));
    if (((TextState *)&D_801282C0)->field_9) {
        CMD(0xE3000A01, 0x100000);
        CMD(0xFC117E03, 0xFF0FF3FF);
        CMD(0xE200001C, 0x0C184A40);
        func_800B7EA0(param_0, ((TextState *)&D_801282C0)->field_9 + 0xC24);
    } else {
        CMD(0xE3000A01, 0);
        CMD(0xFC119623, 0xFF2FFFFF);
        CMD(0xE200001C, 0x00504A40);
    }
    ((TextState *)&D_801282C0)->field_5 = 1;
    D_801282C0.data[12] = func_800D3724(((TextState *)&D_801282C0)->field_6);
}

void func_800B80D0(GfxB7F14 **param_0) {
    GfxB7F14 *local_0 = (*param_0)++;
    local_0->local_0 = 0xFA000000;
    local_0->local_1 = COLOR_SHIFT(((TextState *)&D_801282C0)->field_0,24) | COLOR_SHIFT(((TextState *)&D_801282C0)->field_1,16) | COLOR_SHIFT(((TextState *)&D_801282C0)->field_2,8) | COLOR_SHIFT(((TextState *)&D_801282C0)->field_3,0);
}

void func_800B811C(u8 **param_0)
{
  u8 *local_0;
  local_0 = *param_0;
  *param_0 = (*param_0) + 8;
 do { *((s32 *) (((s8 *) local_0) + 0)) = 0xDE000000; *((u8 **) (((s8 *) local_0) + 4)) = ((u8 *) &D_8011A668) - 0x80000000; D_801282C5 = 0; } while (0);
}

s32 func_800B8148(u8 *param_0)
{
  s32 local_0;
  s32 local_2;
  s32 local_3;
  local_3 = func_800D35D0(D_801282C6, *param_0);
  local_0 = local_3;
  if (local_3 == (-1))
  {
    return 0;
  }
  local_2 = func_800D3524(D_801282C6);
  if (local_2 == 0)
  {
    return 0;
  }
  D_801282D0 = func_800B0D58(local_2);
  *param_0 = (u8) local_0;
  return local_2;
}

s32 func_800B81CC(Gfx **param_0, s32 param_1, s32 param_2, u8 param_3)
{
    s32 local_0;
    B81CCGlyph *local_1;
    Gfx *local_2;
    f32 local_7; /* Retained stack home required by the matching layout. */
    f32 local_3;
    f32 local_4;
    f32 local_5;
    f32 local_6;

    local_0 = func_800B8148(&param_3);
    if (local_0 == 0) return 0;
    local_1 = func_800B0D6C(local_0, param_3);
    local_0 = func_800B0D60(local_0) + local_1->offset;
    local_2 = *param_0;
    /* Format selector: RGBA32, IA16, IA8, I8, I4. The I4 path uploads
     * half-width bytes as I8, then switches the render tile back to I4.
     * Likely macro boundaries: texture upload and scissored rectangle below;
     * compare the original GBI macro variants before changing grouping. */
        if ((*(s32 *)&D_801282C0.data[0x10]) == 0x800) {
            gDPSetTextureImage(local_2++, G_IM_FMT_RGBA, G_IM_SIZ_32b, local_1->w, local_0 + 0x80000000);
            gDPSetTile(local_2++, G_IM_FMT_RGBA, G_IM_SIZ_32b, (local_1->x * 2 + 7) >> 3, 0, G_TX_LOADTILE, 0, G_TX_CLAMP, 0, 0, G_TX_CLAMP, 0, 0);
            gDPLoadSync(local_2++); B81CC_UPLOAD_TILE(local_2++, G_LOADTILE, G_TX_LOADTILE, 0, 0, (local_1->x - 1) << 2, (local_1->y - 1) << 2); gDPPipeSync(local_2++);
            gDPSetTile(local_2++, G_IM_FMT_RGBA, G_IM_SIZ_32b, (local_1->x * 2 + 7) >> 3, 0, G_TX_RENDERTILE, 0, G_TX_CLAMP, 0, 0, G_TX_CLAMP, 0, 0);
            B81CC_UPLOAD_TILE(local_2++, G_SETTILESIZE, G_TX_RENDERTILE, 0, 0, (local_1->x - 1) << 2, (local_1->y - 1) << 2);
        } else if ((*(s32 *)&D_801282C0.data[0x10]) == 0x200) {
            gDPSetTextureImage(local_2++, G_IM_FMT_IA, G_IM_SIZ_16b, local_1->w, local_0 + 0x80000000);
            gDPSetTile(local_2++, G_IM_FMT_IA, G_IM_SIZ_16b, (local_1->x * 2 + 7) >> 3, 0, G_TX_LOADTILE, 0, G_TX_CLAMP, 0, 0, G_TX_CLAMP, 0, 0);
            gDPLoadSync(local_2++); B81CC_UPLOAD_TILE(local_2++, G_LOADTILE, G_TX_LOADTILE, 0, 0, (local_1->x - 1) << 2, (local_1->y - 1) << 2); gDPPipeSync(local_2++);
            gDPSetTile(local_2++, G_IM_FMT_IA, G_IM_SIZ_16b, (local_1->x * 2 + 7) >> 3, 0, G_TX_RENDERTILE, 0, G_TX_CLAMP, 0, 0, G_TX_CLAMP, 0, 0);
            B81CC_UPLOAD_TILE(local_2++, G_SETTILESIZE, G_TX_RENDERTILE, 0, 0, (local_1->x - 1) << 2, (local_1->y - 1) << 2);
        } else if ((*(s32 *)&D_801282C0.data[0x10]) == 0x100) {
            gDPSetTextureImage(local_2++, G_IM_FMT_IA, G_IM_SIZ_8b, local_1->w, local_0 + 0x80000000);
            gDPSetTile(local_2++, G_IM_FMT_IA, G_IM_SIZ_8b, (local_1->x * 1 + 7) >> 3, 0, G_TX_LOADTILE, 0, G_TX_CLAMP, 0, 0, G_TX_CLAMP, 0, 0);
            gDPLoadSync(local_2++); B81CC_UPLOAD_TILE(local_2++, G_LOADTILE, G_TX_LOADTILE, 0, 0, (local_1->x - 1) << 2, (local_1->y - 1) << 2); gDPPipeSync(local_2++);
            gDPSetTile(local_2++, G_IM_FMT_IA, G_IM_SIZ_8b, (local_1->x * 1 + 7) >> 3, 0, G_TX_RENDERTILE, 0, G_TX_CLAMP, 0, 0, G_TX_CLAMP, 0, 0);
            B81CC_UPLOAD_TILE(local_2++, G_SETTILESIZE, G_TX_RENDERTILE, 0, 0, (local_1->x - 1) << 2, (local_1->y - 1) << 2);
        } else if ((*(s32 *)&D_801282C0.data[0x10]) == 0x40) {
            gDPSetTextureImage(local_2++, G_IM_FMT_I, G_IM_SIZ_8b, local_1->w, local_0 + 0x80000000);
            gDPSetTile(local_2++, G_IM_FMT_I, G_IM_SIZ_8b, (local_1->x * 1 + 7) >> 3, 0, G_TX_LOADTILE, 0, G_TX_CLAMP, 0, 0, G_TX_CLAMP, 0, 0);
            gDPLoadSync(local_2++); B81CC_UPLOAD_TILE(local_2++, G_LOADTILE, G_TX_LOADTILE, 0, 0, (local_1->x - 1) << 2, (local_1->y - 1) << 2); gDPPipeSync(local_2++);
            gDPSetTile(local_2++, G_IM_FMT_I, G_IM_SIZ_8b, (local_1->x * 1 + 7) >> 3, 0, G_TX_RENDERTILE, 0, G_TX_CLAMP, 0, 0, G_TX_CLAMP, 0, 0);
            B81CC_UPLOAD_TILE(local_2++, G_SETTILESIZE, G_TX_RENDERTILE, 0, 0, (local_1->x - 1) << 2, (local_1->y - 1) << 2);
        } else if ((*(s32 *)&D_801282C0.data[0x10]) == 0x20) {
            gDPSetTextureImage(local_2++, G_IM_FMT_I, G_IM_SIZ_8b, (local_1->w >> 1), local_0 + 0x80000000);
            gDPSetTile(local_2++, G_IM_FMT_I, G_IM_SIZ_8b, ((local_1->x >> 1) + 7) >> 3, 0, G_TX_LOADTILE, 0, G_TX_CLAMP, 0, 0, G_TX_CLAMP, 0, 0);
            gDPLoadSync(local_2++); B81CC_UPLOAD_TILE(local_2++, G_LOADTILE, G_TX_LOADTILE, 0, 0, (local_1->x - 1) << 1, (local_1->y - 1) << 2); gDPPipeSync(local_2++);
            gDPSetTile(local_2++, G_IM_FMT_I, G_IM_SIZ_4b, ((local_1->x >> 1) + 7) >> 3, 0, G_TX_RENDERTILE, 0, G_TX_CLAMP, 0, 0, G_TX_CLAMP, 0, 0);
            B81CC_UPLOAD_TILE(local_2++, G_SETTILESIZE, G_TX_RENDERTILE, 0, 0, (local_1->x - 1) << 2, (local_1->y - 1) << 2);
        } else {
            return 0;
        }

    /* Apply scale, optional horizontal centering, and optional XY jitter. */
    local_3 = param_1;
    local_5 = local_1->x * D_801282C0.value;
    local_6 = local_1->y * D_801282C0.value;
    if (D_801282C0.data[7] == 0 || D_801282C0.data[8] == 0) {
        local_3 -= local_5 * 0.5f;
    }
    local_4 = param_2 - local_1->h * 0.5f;
    if (D_801282C0.data[4] != 0) {
        local_3 += func_800DC178(-2.0f, 2.0f);
        local_4 += func_800DC178(-2.0f, 2.0f);
    }
    { Gfx *_g = (Gfx *)(local_2++); _g->words.w0 = (_SHIFTL(0xe4, 24, 8) | _SHIFTL((((s16)((s32)((local_3 + local_5) * 4.0f))) > (0) ? ((s16)((s32)((local_3 + local_5) * 4.0f))) : (0)), 12, 12) | _SHIFTL((((s16)((s32)((local_4 + local_6) * 4.0f))) > (0) ? ((s16)((s32)((local_4 + local_6) * 4.0f))) : (0)), 0, 12));
 _g->words.w1 = (_SHIFTL((0), 24, 3) | _SHIFTL((((s16)((s32)(local_3 * 4.0f))) > (0) ? ((s16)((s32)(local_3 * 4.0f))) : (0)), 12, 12) | _SHIFTL((((s16)((s32)(local_4 * 4.0f))) > (0) ? ((s16)((s32)(local_4 * 4.0f))) : (0)), 0, 12)); 
{ Gfx *_g = (Gfx *)(local_2++); _g->words.w0 = _SHIFTL((0xE1), 24, 8); _g->words.w1 = (unsigned int)((_SHIFTL(((0) - (((s16)((s32)(local_3 * 4.0f)) < 0) ? (((s16)((s32)(1024.0f / D_801282C0.value)) < 0) ? ((((((s16)((s32)(local_3 * 4.0f))*(s16)((s32)(1024.0f / D_801282C0.value)))>>7)) > (0) ? ((((s16)((s32)(local_3 * 4.0f))*(s16)((s32)(1024.0f / D_801282C0.value)))>>7)) : (0))) : ((((((s16)((s32)(local_3 * 4.0f))*(s16)((s32)(1024.0f / D_801282C0.value)))>>7)) < (0) ? ((((s16)((s32)(local_3 * 4.0f))*(s16)((s32)(1024.0f / D_801282C0.value)))>>7)) : (0)))) : 0)), 16, 16) | _SHIFTL(((0) - ((((s32)(local_4 * 4.0f)) < 0) ? (((s16)((s32)(1024.0f / D_801282C0.value)) < 0) ? ((((((s16)((s32)(local_4 * 4.0f))*(s16)((s32)(1024.0f / D_801282C0.value)))>>7)) > (0) ? ((((s16)((s32)(local_4 * 4.0f))*(s16)((s32)(1024.0f / D_801282C0.value)))>>7)) : (0))) : ((((((s16)((s32)(local_4 * 4.0f))*(s16)((s32)(1024.0f / D_801282C0.value)))>>7)) < (0) ? ((((s16)((s32)(local_4 * 4.0f))*(s16)((s32)(1024.0f / D_801282C0.value)))>>7)) : (0)))) : 0)), 0, 16))); }; { Gfx *_g = (Gfx *)(local_2++); _g->words.w0 = _SHIFTL((0xF1), 24, 8); _g->words.w1 = (unsigned int)((_SHIFTL(((s32)(1024.0f / D_801282C0.value)), 16, 16) | _SHIFTL(((s32)(1024.0f / D_801282C0.value)), 0, 16))); }; };
    *param_0 = local_2;
    return (s32)local_5;
}

#ifndef NON_MATCHING
void func_800B8C50(void)
{
    u8 *local_1 = (u8 *)&D_801282C0;
    u8 local_0 = 0xFF;

    local_1[2] = local_0;
    local_1[1] = local_1[2];
    local_1[0] = local_1[1];
    local_1[3] = local_1[0];
    local_1[9] = 0;
    local_1[7] = 0;
    local_1[4] = 0;
    local_1[6] = 0;
    *(f32 *)(local_1 + 0x14) = 1.0f;
}
#else
//Reset Text Parameters
void func_800B8C50(void)
{
	D_801282C0.data[2] = 0xFF;
	D_801282C0.data[1] = 0xFF;
	D_801282C0.data[0] = 0xFF;
	D_801282C0.data[3] = 0xFF;
	D_801282C0.data[9] = 0; //Color
	D_801282C0.data[7] = 0; 
	D_801282C0.data[4] = 0; //Shakiness
	D_801282C0.data[6] = 0; //Font
	D_801282C0.value = 1.0f; //Size
}
#endif

//Set Text Transparency
void func_800B8C8C(s32 Transparency)
{
	D_801282C0.data[3] = Transparency;
}

//Set Text Font
void func_800B8C98(s32 Font)
{
	D_801282C0.data[6] = Font;
}

//Set Text Shakiness
void func_800B8CA4(s32 shakiness)
{
	D_801282C0.data[4] = shakiness;
}

void func_800B8CB0(s32 unk)
{
	D_801282C0.data[7] = unk;
}

void func_800B8CBC(s8 arg0, s8 arg1, s8 arg2)
{
	D_801282C0.data[0] = arg0;
	D_801282C0.data[1] = arg1;
	D_801282C0.data[2] = arg2;
}

//Set Text Color
void func_800B8CE0(s32 color)
{
	D_801282C0.data[9] = color-0xC24;
}

//Set Text Size
void func_800B8CF0(f32 size)
{
	D_801282D4 = size;
}

int func_800B8CFC(u32 param_0)
{
    s32 local_1;
    s32 local_2;
    s32 local_3;
    s32 local_4;

    local_2 = 0;
    local_3 = 0;
    for (local_1 = 0; local_1 < func_800E7188((u8 *)param_0); local_1++) {
            local_4 = func_800D36C4(*(u8 *)((char *)&D_801282C0 + 6), ((u8 *)param_0)[local_1]);
            local_2 = (s32)((f32)local_2 + ((f32)(local_4 + local_3) * 0.5f));
            local_3 = local_4;
    }
    local_2 *= D_801282C0.value;
    return local_2;
}

int func_800B8DEC(param_0, param_1, param_2, param_3) s32 param_0; s32 param_1; s32 param_2; u8 param_3;
{
  if (*((u8 *) (((char *) (&D_801282C0)) + 0xC)))
  {
    *((u8 *) (((char *) (&D_801282C0)) + 0x8)) = 0;
    func_800B81CC(param_0, param_1, param_2, param_3);
  }
}

void func_800B8E28(s32 param_0, s32 param_1, s32 param_2, u8 *param_3) {
    s32 local_2;
    s32 local_1;
    s32 local_3;
    u8 local_5;

    if (*(u8 *)((char *)&D_801282C0 + 0xC) != 0) {
        if (*(u8 *)((char *)&D_801282C0 + 0x7) != 0) {
            local_1 = (s32) ((f32)func_800D3574(D_801282C0.data[6]) * D_801282C0.value);
        } else {
            local_2 = (s32) ((f32)func_800D35BC(D_801282C0.data[6]) * D_801282C0.value);
        }
        *(u8 *)((char *)&D_801282C0 + 0x8) = 0U;
        local_5 = *param_3;
        if (local_5 != 0) {
            do {
                local_3 = func_800B81CC(param_0, param_1, param_2, local_5);
                param_3 += 1;
                if ((*(u8 *)((char *)&D_801282C0 + 0x7) != 0) && (*(u8 *)((char *)&D_801282C0 + 0x8) == 0)) {
                    param_1 += local_3 / 2;
                    *(u8 *)((char *)&D_801282C0 + 0x8) = 1U;
                } else {
                    param_1 += D_801282C0.data[7] ? (local_3 ? local_3 : local_1) : local_2;
                }
                local_5 = *param_3;
            } while (local_5 != 0);
        }
    }
}

void func_800B8F88(s32 param_0, s32 param_1, s32 param_2) {
    func_800B8E28(param_0, (s32) (0x130 - func_800B8CFC(param_2)) / 2, param_1, param_2);
}

int func_800B8FE0()
{
  D_8012712C = 0;
}

void func_800B8FEC(void)
{
    if ((*((void * *) &D_80127128)) != NULL)
    {
        heap_free(*(void **)((char *)(*((void * *) &D_80127128)) + 0x1C));
        heap_free((*((void * *) &D_80127128)));
        (*((void * *) &D_80127128)) = NULL;
        *(int *)((char *)((void * *) &D_80127128) + 4) = 0;
    }
}

void func_800B9038(void)
{
    func_800B8FEC();
    D_80127128.a.local_0 = heap_alloc(0x20);
    D_80127128.a.local_0->local_0 =
        D_80127128.a.local_0->local_1 =
        D_80127128.a.local_0->local_2 = 0.0f;
    D_80127128.a.local_0->local_3 =
        D_80127128.a.local_0->local_4 =
        D_80127128.a.local_0->local_5 = 0.0f;
    D_80127128.a.local_1 = 0;
    D_80127128.a.local_0->local_7 = heap_alloc(0x960);
    D_80127128.a.local_0->local_6 = 0;
}

void func_800B90C8()
{
    if (D_80127128.w.emitter != NULL)
    {
        D_80127128.w.emitter->state = 1;
    }
}

void func_800B90E8()
{
    int local_0;
    if ((*((int *) &D_80127128)) != 0)
    {
        local_0 = (*((int *) &D_80127128));
        *(u8 *)(local_0 + 0x18) = 2;
    }
    return;
}

void func_800B9108(s32 param_0) {
    D_80127128.g.unk4 -= 1;
    if (param_0 < D_80127128.g.unk4) {
        aligned4_memcpy(&D_80127128.g.unk0->unk1C[param_0], &D_80127128.g.unk0->unk1C[D_80127128.g.unk4], 0x18);
    }
}

void func_800B9170(void)
{
    f32 local_0;
    s32 local_1;
    s32 local_2;
    s32 local_3;
    LocalParticle *local_4;
    f32 local_5;
    f32 local_6[3];
    f32 local_7;
    s32 local_8;
    LocalParticle *local_9;

    if (D_80127128.w.emitter != 0) {
        if (func_800A5490() != 0) {
            D_80127128.w.count = 0;
            return;
        }
        local_0 = func_800D8FF8();
        local_3 = (func_8001211C() & 1) * 2;
        func_8008FE68(D_80127138);
        D_80127128.w.emitter->movement[0] = D_80127128.w.position[0] - D_80127128.w.emitter->position[0];
        D_80127128.w.emitter->movement[1] = D_80127128.w.position[1] - D_80127128.w.emitter->position[1];
        D_80127128.w.emitter->movement[2] = D_80127128.w.position[2] - D_80127128.w.emitter->position[2];
        D_80127128.w.emitter->position[0] = D_80127128.w.position[0];
        D_80127128.w.emitter->position[1] = D_80127128.w.position[1];
        D_80127128.w.emitter->position[2] = D_80127128.w.position[2];
        D_80127128.w.height = D_80127128.w.position[1] - 300.0f;
        for (local_1 = 0; local_1 < D_80127128.w.count; local_1++) {
            local_4 = D_80127128.w.emitter->particles + local_1;
            for (local_2 = 0; local_2 < 3; local_2++) {
                local_4->position[local_2] += local_4->velocity[local_2] * local_0;
            }
            local_4->velocity[local_3] += func_800DC0C0() * 30.0f - 15.0f;
        }
        D_80127128.w.cursor++;
        if (D_80127128.w.cursor < D_80127128.w.count) {
            local_4 = &D_80127128.w.emitter->particles[D_80127128.w.cursor];
            if (func_800EEAD4(local_4->position, D_80127138) > 1.3e+03f) {
                func_800B9108(D_80127128.w.cursor);
            }
        } else {
            D_80127128.w.cursor = 0;
        }
        if (D_80127128.w.emitter->state == 1) {
            if (D_80127128.w.count < 100) {
                local_9 = D_80127128.w.emitter->particles + D_80127128.w.count;
                D_80127128.w.count++;
                local_5 = func_800DC178(100.0f, 1.3e+03f);
                func_800EFA4C(local_6, 0.0f, func_800DC0C0() * 200.0f + 200.0f, -local_5);
                if (func_800EEFD4(D_80127128.w.emitter->movement) < 25.0f) {
                    local_7 = 100.0f;
                } else {
                    local_7 = 70.0f;
                }
                func_800EF934(local_6, local_6, func_800E3A80() + func_800DC178(-local_7, local_7));
                func_800EF04C(local_6, D_80127138);
                if (local_5 < 6.5e+02f) {
                    for (local_8 = 0; local_8 < 5 && func_800E3F8C(local_6[0], local_6[1] - 10.0f, local_6[2]); local_8++) {
                        local_6[1] += 200.0f;
                    }
                }
                func_800EE7F8(local_9->position, local_6);
                func_800EFA4C(local_9->velocity, 0.0f, func_800DC178(-150.0f, -50.0f), 0.0f);
            }
        }
    }
}

void func_800B956C(void) {
    DrawB956C *local_0;
    AssetB956C *local_1;
    u8 *local_2;
    Gfx *local_3;
    ParticleB956C *local_4;
    if (!D_80127128.s.local_0 || !D_80127128.s.local_1) return;
    local_0 = func_800A7180();
    local_1 = func_800D674C(0x9F4);
    func_800E39A8(D_80127148, D_80127154);
    D_80127128.s.local_4 = (u8 *)local_1 + local_1->local_2 + 8;
    local_2 = (u8 *)local_1 + local_1->local_3;
    D_80127128.s.local_3 = func_800B2354(local_2);
    local_3 = local_0->local_0;
    { Gfx *local_5 = local_3++; local_5->words.w0 = 0xDB060004; local_5->words.w1 = osVirtualToPhysical(local_2 + 0x18); }
    { Gfx *local_6 = local_3++; local_6->words.w0 = 0xDB060008; local_6->words.w1 = osVirtualToPhysical((u8 *)local_1 + local_1->local_1 + 0x10); }
    { Gfx *local_7 = local_3++; local_7->words.w0 = 0xD9FFFFFF; local_7->words.w1 = 1; }
    { Gfx *local_8 = local_3++; local_8->words.w0 = 0xDE000000; local_8->words.w1 = (u32)((u8 *)D_8011A690 - 0x80000000); }
    { Gfx *local_9 = local_3++; local_9->words.w0 = 0xDB06000C; local_9->words.w1 = osVirtualToPhysical(D_8011A6B0); }
    local_0->local_0 = local_3;
    D_80127128.s.local_5 = (u8 *)local_1 + local_1->local_0;
    for (local_4 = D_80127128.s.local_0->local_0; local_4 < D_80127128.s.local_0->local_0 + D_80127128.s.local_1; local_4++) {
        if (!func_800B97A4(&local_0->local_0, &local_0->local_1, local_4) && local_4->local_0[1] < D_80127128.s.local_2) {
            func_800B9108(local_4 - D_80127128.s.local_0->local_0);
            local_4--;
        }
    }
}

s32 func_800B97A4(param_0, param_1, param_2) Gfx ** param_0; s32 * param_1; u8 * param_2; {

    func_800EFB24(&D_80127160, param_2, ((s32 *) D_80127148));
    if (((*(f32 *)((s8 *)(((s32 *) &D_80127128)) + (0x38))) > (-17000.0f)) && ((*(f32 *)((s8 *)(((s32 *) &D_80127128)) + (0x38))) < 17000.0f) && ((*(f32 *)((s8 *)(param_2) + (4))) > -200.0f) && ((*(f32 *)((s8 *)(((s32 *) &D_80127128)) + (0x40))) > (-17000.0f)) && ((*(f32 *)((s8 *)(((s32 *) &D_80127128)) + (0x40))) < 17000.0f) && (func_800E3E8C(param_2, (*(f32 *)((s8 *)(((s32 *) &D_80127128)) + (0x50)))) != 0)) {
        mlMtx_set_translation(((f32 *)param_2)[0], ((f32 *)param_2)[1], ((f32 *)param_2)[2]);
        mlMtxApply((Mtx *)*param_1);
        func_800193C4(&D_8012716C, (*(u8 **)((s8 *)(((s32 *) &D_80127128)) + (0x58))) + 0xC);
        mlMtx_set_translation((*(f32 *)((s8 *)(((s32 *) &D_80127128)) + (0x44))), (*(f32 *)((s8 *)(((s32 *) &D_80127128)) + (0x48))), (*(f32 *)((s8 *)(((s32 *) &D_80127128)) + (0x4C))));
        mlMtxRotYaw((*(f32 *)((s8 *)(((s32 *) &D_80127128)) + (0x30))));
        mlMtxRotPitch((*(f32 *)((s8 *)(((s32 *) &D_80127128)) + (0x2C))));
        mlMtxTranslate(-(*(f32 *)((s8 *)((*(u8 **)((s8 *)(((s32 *) &D_80127128)) + (0x58)))) + (0xC))), -(*(f32 *)((s8 *)((*(u8 **)((s8 *)(((s32 *) &D_80127128)) + (0x58)))) + (0x10))), -(*(f32 *)((s8 *)((*(u8 **)((s8 *)(((s32 *) &D_80127128)) + (0x58)))) + (0x14))));
        mlMtxApply((Mtx *)*param_1);
        gDma2p((*param_0)++, 0xDA, *param_1, sizeof(Mtx), 2, 0);
        *param_1 += 0x40;
        gDma1p((*param_0)++, 0xDE, osVirtualToPhysical(*(s32 *)((u8 *)((s32 *) &D_80127128) + 0x54)), 0, 0);
        gDma2p((*param_0)++, 0xD8, sizeof(Mtx), sizeof(Mtx), 2, 0);
        return 1;
    }
    return 0;
}
