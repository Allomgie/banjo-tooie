// Most likely the large-font variant of the info-bar number and value/max renderers
// (sc/custom.c), with the same slide/fade logic, plus width functions.
#include "common.h"

extern f32 _scinfobar_entrypoint_18(s32);
extern s32 func_800E7188(s32);

// TU-NOTE: the .bss of this file is defined here in C, ahead of its first use: IDO places .bss
// objects used before their definition first, the rest in definition order.
u8 B_808003F0_sccustom_big[16];
s32 B_80800400_sccustom_big;

int func_80800000_sccustom_big(s32 infobar)
{
    func_800E73D4(&B_808003F0_sccustom_big);
    func_800E6DB4(&B_808003F0_sccustom_big, _scinfobar_entrypoint_19(infobar));
    return (int) &B_808003F0_sccustom_big;
}

s32 *func_80800044_sccustom_big(infobar, sep)
s32 infobar;
u8 sep;
{
    func_800E73D4(&B_80800400_sccustom_big);
    func_800E6DB4(&B_80800400_sccustom_big, _scinfobar_entrypoint_19(infobar));
    func_800E6A58(&B_80800400_sccustom_big, sep);
    func_800E6DB4(&B_80800400_sccustom_big, _scinfobar_entrypoint_20(infobar));
    return &B_80800400_sccustom_big;
}

// Large font (0xC26), 16 px glyph spacing; same slide and fade as the small variant.
int func_808000B4_sccustom_big(s32 gfx, s32 infobar, s32 x, s32 y, u8 *text)
{
    s32 slide;
    f32 scale;
    s32 align;
    f32 slide_f;

    s32 alpha;
    s32 last;
    s32 i;
    f32 offset;
    s32 ch;

    slide = _scinfobar_entrypoint_11(infobar);
    scale = _scinfobar_entrypoint_18(infobar);
    align = _scinfobar_entrypoint_15(infobar);
    func_800B8C50();
    func_800B8C98(1);
    func_800B8CE0(0xC26);
    slide_f = (f32) slide;

if (slide_f < (24.0f * scale + 8.0f)) {
    alpha =
        (s32) ((1.0f - (((24.0f * scale + 8.0f) - slide_f) / (24.0f * scale + 8.0f))) * 255.0f);
} else {

alpha = 255;
}
last = func_800E7188((s32) text) - 1;
func_800B8C8C(alpha);
func_800B7F14(gfx);
for (i = last; i >= 0; i--) {
    offset = (24.0f * scale + 8.0f) + 16.0f * (f32) i;

if (slide_f < offset) {
    offset = slide_f;
}

if (align == 2) {
    offset = -offset;
    ch = text[last - i];
} else {

ch = text[i];
}
func_800B8DEC(gfx, (s32) ((f32) x + offset), y, ch);
}
func_800B811C(gfx);
}

s32 sccustom_big_entrypoint_0(s32 gfx, s32 infobar, s32 x, s32 y)
{
    s32 text;

    text = func_80800000_sccustom_big(infobar);
    return func_808000B4_sccustom_big(gfx, infobar, x, y, text);
}

s32 sccustom_big_entrypoint_1(s32 gfx, s32 infobar, s32 x, s32 y)
{
    s32 text;

    text = func_80800044_sccustom_big(infobar, 0x2F);
    return func_808000B4_sccustom_big(gfx, infobar, x, y, text);
}

// Width of the text, counted as at least 2 glyphs.
s32 func_80800314_sccustom_big(s32 infobar, s32 text)
{
    s32 len;
    f32 scale;

    len = func_800E7188(text);
    scale = _scinfobar_entrypoint_18(infobar);
    if (len < 2) {
        len = 2;
    }
    len--;
    return 24.0f * scale + 8.0f + 16.0f * len;
}

s32 sccustom_big_entrypoint_2(Actor *this)
{
    s32 out;

    out = func_80800000_sccustom_big(this);
    // Matching: needed for the match.
    func_80800314_sccustom_big(this, out | 0);
}

void sccustom_big_entrypoint_3(s32 infobar)
{
    s32 out;
    out = func_80800044_sccustom_big(infobar, 0x2F);
    // Matching: needed for the match.
    out |= func_80800314_sccustom_big(infobar, out);
}
