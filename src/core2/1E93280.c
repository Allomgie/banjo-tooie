// Draws a screen-space translucent colored rectangle, and fills the current scissor rectangle.
#include "common.h"

extern u8 D_8011A6E0[];
void func_800B9A24(Gfx **param_0, s32 param_1, s32 *param_2, s32 param_3, s32 param_4, s32 param_5,
                   s32 param_6);

// Appends a call to the setup display list D_8011A6E0, then restores fog/render state.
// Matching: the line breaks in this function are needed for the match.
void func_800B9990(u8 **dl)
{
    s32 *word0;
    u8 *cmd;
    cmd = *dl;
    *dl = *dl + 8;
    *(word0 = (s32 *) ((s8 *) cmd + 0)) = 0xDE000000; *(u8 **) ((s8 *) cmd + 4) = (u8 *) (s32 *) D_8011A6E0 - 0x80000000;
    func_800D2CC4();
}

// Tints the whole active scissor (viewport) rectangle.
void func_800B99CC(s32 gfx, s32 alpha, s32 color)
{
    s32 scissor[4];
    func_800E7FCC(scissor);
    func_800B9A24(gfx, alpha, color, scissor[0], scissor[1], scissor[2], scissor[3]);
}

// Draws a translucent screen-space rectangle: color is r,g,b; alpha is a separate argument.
// Matching: the line breaks in this function are needed for the match.
void func_800B9A24(Gfx **gfx, s32 alpha, s32 *color, s32 x, s32 y, s32 width, s32 height) {
    { Gfx *_g = (Gfx *)(*gfx)++; _g->words.w0 = (_SHIFTL(0xde, 24, 8) | _SHIFTL(0x00, 16, 8) | _SHIFTL(0, 0, 16)); _g->words.w1 = (unsigned int)(D_8011A6E0 - 0x80000000); };
    { Gfx *_g = (Gfx *)(*gfx)++; _g->words.w0 = _SHIFTL(0xf8, 24, 8); _g->words.w1 = (unsigned int)(_SHIFTL(color[0], 24, 8) | _SHIFTL(color[1], 16, 8) | _SHIFTL(color[2], 8, 8) | _SHIFTL(alpha, 0, 8)); };
    { Gfx *_g = (Gfx *)(*gfx)++; _g->words.w0 = (_SHIFTL(0xe4, 24, 8) | _SHIFTL((x + width) * 4, 12, 12) | _SHIFTL((y + height) * 4, 0, 12)); _g->words.w1 = (_SHIFTL(0, 24, 3) | _SHIFTL(x * 4, 12, 12) | _SHIFTL(y * 4, 0, 12)); { Gfx *_g = (Gfx *)(*gfx)++; _g->words.w0 = _SHIFTL(0xe1, 24, 8); _g->words.w1 = (unsigned int)(_SHIFTL(0, 16, 16) | _SHIFTL(0, 0, 16)); }; { Gfx *_g = (Gfx *)(*gfx)++; _g->words.w0 = _SHIFTL(0xf1, 24, 8); _g->words.w1 = (unsigned int)(_SHIFTL(0x100, 16, 16) | _SHIFTL(0x100, 0, 16)); };};
    func_800D2CC4();
}

// TU-NOTE: the .data of this file (formerly asm/data/core2/1E93280.data.s) is defined here in C.
// Values are taken from the ROM.
u8 D_8011A6E0[80] = {
    0xE7, 0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0xD9, 0xC0, 0xFF, 0xFA, 0x0,  0x0,  0x0,  0x0,
    0xD7, 0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0xE3, 0x0,  0xA,  0x1,  0x0,  0x0,  0x0,  0x0,
    0xE3, 0x0,  0x8,  0x0,  0x0,  0x0,  0x0,  0x0,  0xE2, 0x0,  0x1E, 0x1,  0x0,  0x0,  0x0,  0x0,
    0xFC, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xE2, 0x0,  0x0,  0x1C, 0xF5, 0x50, 0x43, 0x40,
    0xDF, 0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0};
