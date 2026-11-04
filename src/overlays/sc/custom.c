// Probably the info-bar value renderers: number, value/max and h:mm:ss time text, aligned
// left or right with slide-in offset and fade, plus the width of each format.
#include "common.h"

extern void func_800B8CBC(u8, u8, u8);
extern s32 func_800E7188(s32);
extern f32 _scinfobar_entrypoint_18(s32);
extern void func_800B8DEC(void *, s32, s32, u8);
extern int D_80800920_sccustom;

// Draws a counter string glyph by glyph (8 px apart), sliding in and fading with the bar.
void func_80800000_sccustom(void *gfx, s32 infobar, s32 x, s32 y, u8 *text)
{
    s32 slide;
    f32 scale;
    s32 align;
    s32 pulse;
    u8 tint;
    f32 slide_f;
    f32 base_x;
    s32 alpha;
    s32 i;
    s32 last;
    f32 offset;
    u8 ch;

    slide = _scinfobar_entrypoint_11(infobar);
    scale = _scinfobar_entrypoint_18(infobar);
    align = _scinfobar_entrypoint_15(infobar);
    func_800B8C50();
    switch (_scinfobar_entrypoint_17(infobar)) {
        case 0:
            break;
        case 1:
            func_800B8CBC(0x80, 0x80, 0x80);
            break;
        case 2:
            // Tint mode 2: grey level pulses with the frame counter.
            pulse = (func_8001211C() << 5) & 0x1FF;
            if (pulse >= 0x100)
                pulse = 0x200 - pulse;
            pulse *= 0.5f;
            tint = pulse + 0x7F;
            func_800B8CBC(tint, tint, tint);
    }
    slide_f = slide;
    base_x = 24.0f * scale + 4.0f;
    if (slide_f < base_x) {
        alpha = (1.0f - (base_x - slide_f) / base_x) * 255.0f;
    } else {
        alpha = 0xFF;
    }
    last = func_800E7188((s32) text) - 1;
    func_800B8C8C(alpha);
    func_800B7F14(gfx);
    for (i = last; i >= 0; i--) {
        offset = base_x;
        offset += 8.0f * i;
        if (slide_f < offset)
            offset = slide_f;
        if (align == 2) {
            offset = -offset;
            ch = text[last - i];
        } else {
            ch = text[i];
        }
        func_800B8DEC(gfx, (s32) (x + offset), y, ch);
    }
    func_800B811C(gfx);
}

// Same as above with 10 px glyph spacing (used for the fixed string).
void func_80800264_sccustom(void *gfx, s32 infobar, s32 x, s32 y, u8 *text)
{
    s32 slide;
    f32 scale;
    s32 align;
    s32 pulse;
    u8 tint;
    f32 slide_f;
    f32 base_x;
    s32 alpha;
    s32 i;
    s32 last;
    f32 offset;
    u8 ch;

    slide = _scinfobar_entrypoint_11(infobar);
    scale = _scinfobar_entrypoint_18(infobar);
    align = _scinfobar_entrypoint_15(infobar);
    func_800B8C50();
    switch (_scinfobar_entrypoint_17(infobar)) {
        case 0:
            break;
        case 1:
            func_800B8CBC(0x80, 0x80, 0x80);
            break;
        case 2:
            pulse = (func_8001211C() << 5) & 0x1FF;
            if (pulse >= 0x100)
                pulse = 0x200 - pulse;
            pulse *= 0.5f;
            tint = pulse + 0x7F;
            func_800B8CBC(tint, tint, tint);
    }
    slide_f = slide;
    base_x = 24.0f * scale + 4.0f;
    if (slide_f < base_x) {
        alpha = (1.0f - (base_x - slide_f) / base_x) * 255.0f;
    } else {
        alpha = 0xFF;
    }
    last = func_800E7188((s32) text) - 1;
    func_800B8C8C(alpha);
    func_800B7F14(gfx);
    for (i = last; i >= 0; i--) {
        offset = base_x;
        offset += 10.0f * i;
        if (slide_f < offset)
            offset = slide_f;
        if (align == 2) {
            offset = -offset;
            ch = text[last - i];
        } else {
            ch = text[i];
        }
        func_800B8DEC(gfx, (s32) (x + offset), y, ch);
    }
    func_800B811C(gfx);
}

// TU-NOTE: the .bss of this file is defined here in C, ahead of its first use: IDO places .bss
// objects used before their definition first, the rest in definition order. The _pad objects
// fill bytes that no code names.
s32 B_80800930_sccustom;
u8 B_80800930_sccustom_pad[4];
u8 B_80800930_sccustom_pad1[8];
u8 B_80800940_sccustom[16];
s32 B_80800950_sccustom;

// Builds the plain number string.
s32 *func_808004C8_sccustom(s32 infobar)
{
    func_800E73D4(&B_80800930_sccustom);
    func_800E6DB4(&B_80800930_sccustom, _scinfobar_entrypoint_19(infobar));
    return &B_80800930_sccustom;
}

// Builds the "value<sep>max" string.
int func_8080050C_sccustom(infobar, sep)
s32 infobar;
u8 sep;
{
    func_800E73D4(&B_80800940_sccustom);
    func_800E6DB4(&B_80800940_sccustom, _scinfobar_entrypoint_19(infobar));
    func_800E6A58(&B_80800940_sccustom, sep);
    func_800E6DB4(&B_80800940_sccustom, _scinfobar_entrypoint_20(infobar));
    return &B_80800940_sccustom;
}

void sccustom_entrypoint_0(s32 gfx, s32 infobar, s32 x, s32 y)
{
    s32 text;

    // Matching: needed for the match.
    text = func_808004C8_sccustom(infobar | 0);
    func_80800000_sccustom(gfx, infobar, x, y, text);
}

s32 sccustom_entrypoint_1(s32 gfx, s32 infobar, s32 x, s32 y)
{
    // Value 999 shows the fixed string.
    if (_scinfobar_entrypoint_19(infobar) == 0x3E7) {
        func_80800264_sccustom(gfx, infobar, x, y, D_80800920_sccustom);
        return;
    }
    func_80800000_sccustom(gfx, infobar, x, y, func_808004C8_sccustom(infobar));
}

int sccustom_entrypoint_2(s32 gfx, s32 infobar, s32 x, s32 y)
{
    s32 value;
    s32 max_value;
    // Matching: needed for the match.
    value = _scinfobar_entrypoint_19(infobar | 0);
    max_value = _scinfobar_entrypoint_20(infobar | 0);
    // Mark the counter full when value equals max.
    if (max_value == value) {
        _scinfobar_entrypoint_5(infobar | 0, 1);
    }
    value = func_8080050C_sccustom(infobar | 0, 0x2F);
    func_80800000_sccustom(gfx, infobar | 0, x, y, value);
}

// Width of the text, counted as at least 3 glyphs.
s32 func_808006C4_sccustom(s32 infobar, s32 text)
{
    s32 len;
    f32 scale;

    len = func_800E7188(text);
    scale = _scinfobar_entrypoint_18(infobar);
    if (len < 3) {
        len = 3;
    }
    len--;
    return 24.0f * scale + 4.0f + 8.0f * len;
}

s32 sccustom_entrypoint_3(s32 infobar)
{
    s32 text;
    text = func_808004C8_sccustom(infobar);
    // Matching: needed for the match.
    func_808006C4_sccustom(infobar, text | 0);
}

// Width for the plain number; the fixed string for value 999.
s32 sccustom_entrypoint_4(s32 infobar)
{
    s32 len;
    f32 scale;

    if (_scinfobar_entrypoint_19() == 0x3E7) {
        len = func_800E7188(D_80800920_sccustom);
        scale = _scinfobar_entrypoint_18(infobar);
        if (len < 3) {
            len = 3;
        }
        len--;
        return (s32) (24.0f * scale + 4.0f + 10.0f * len);
    }
    return func_808006C4_sccustom(infobar, func_808004C8_sccustom(infobar));
}

s32 sccustom_entrypoint_5(s32 infobar)
{
    func_808006C4_sccustom(infobar, func_8080050C_sccustom(infobar, 0x2F));
}

s32 *func_8080084C_sccustom(s32 infobar)
{
    func_800E73D4(&B_80800950_sccustom);
    func_800DB8BC(&B_80800950_sccustom, _scinfobar_entrypoint_19(infobar));
    return &B_80800950_sccustom;
}

void sccustom_entrypoint_6(s32 gfx, s32 infobar, s32 x, s32 y)
{
    s32 text;

    text = func_8080084C_sccustom(infobar);
    func_80800000_sccustom(gfx, infobar, x, y, text);
}

int sccustom_entrypoint_7(s32 infobar)
{
    u32 text;
    text = func_8080084C_sccustom(infobar);
    // Matching: needed for the match.
    func_808006C4_sccustom(infobar, text | 0);
}

// TU-NOTE: the .data of this overlay is defined here in C. Values are taken from the ROM.
int D_80800920_sccustom = (u32) "LOTS";
