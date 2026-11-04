#include "common.h"

extern f32 _scinfobar_entrypoint_18(s32);
extern void func_800E253C(f32);
extern s32 _scinfobar_entrypoint_20(s32);

// Icon row: the first `value` icons are bright, the rest dim; slides in with the bar.
void sccustom_banjo_entrypoint_0(s32 gfx, s32 infobar, s32 x, s32 y)
{
    s32 sprite;
    s32 slide;
    f32 scale;
    int value;
    s32 count;
    s32 mode;
    s32 fade;
    s32 slide_len;
    s32 i;
    s32 offset;
    s32 xy[2];
    s32 alpha;

    sprite = func_800D674C(0xB4D);
    slide = _scinfobar_entrypoint_11(infobar);
    scale = _scinfobar_entrypoint_18(infobar);
    value = _scinfobar_entrypoint_19(infobar);
    count = _scinfobar_entrypoint_20(infobar);
    mode = _scinfobar_entrypoint_14(infobar);
    // Matching: needed for the match.
    slide_len = (s32) ((f32) (count * 0 + 0x28) * scale);
    if (slide < slide_len) {
        // Matching: empty blocks steer IDO's register allocation.
        if (1) {
        }
        if (1) {
        }
        fade = (s32) ((1.0f - (f32) (slide_len - slide) / (f32) slide_len) * 256.0f);
    } else {
        fade = 0x100;
    }
    i = count - 1;
    if (i >= 0) {
        do {
            offset = (s32) ((f32) (i * 0x14 + 0x28) * scale);
            if (slide < offset) {
                offset = slide;
            }
            switch (mode) {
                case 1:
                    if (value == i + 1) {
                        alpha = 0xFF;
                    } else {
                        alpha = 0x78;
                    }
                    break;
                case 2:
                    alpha = 0x78;
                    break;
                default:
                    if (i < value) {
                        alpha = 0xFF;
                    } else {
                        alpha = 0x78;
                    }
                    break;
            }
            func_800E257C((alpha * fade) >> 8);
            func_800E253C(scale);
            xy[1] = y * 4;
            xy[0] = (x + offset) * 4;
            func_800E30E0(gfx, sprite, 0, xy);
            i--;
        } while (i >= 0);
    }
}

// Vertical air meter: icons up to the remaining air are bright and tinted blue.
void sccustom_banjo_entrypoint_1(s32 gfx, s32 infobar, s32 x, s32 y)
{
    s32 sprite;
    s32 slide;
    f32 scale;
    s32 air;
    s32 count;
    s32 fade;
    s32 slide_len;
    s32 i;
    s32 offset;
    s32 xy[2];
    s32 alpha;

    sprite = func_800D674C(0x9DA);
    slide = _scinfobar_entrypoint_11(infobar);
    scale = _scinfobar_entrypoint_18(infobar);
    air = func_800CF6B0();
    count = func_800CF6D0();
    // Matching: needed for the match.
    slide_len = (s32) ((f32) (count * 0 + 0x28) * scale);
    if (slide < slide_len) {
        fade = (s32) ((1.0f - (f32) (slide_len - slide) / (f32) slide_len) * 256.0f);
    } else {
        fade = 0x100;
    }
    i = count - 1;
    if (i >= 0) {
        do {
            offset = (s32) ((f32) (i * 0x14 + 0x28) * scale);
            if (slide < offset) {
                offset = slide;
            }
            if (i < air) {
                alpha = 0xFF;
                func_800E24F8(0x80, 0x80, 0xFF);
            } else {
                alpha = 0x78;
            }
            func_800E257C((alpha * fade) >> 8);
            func_800E253C(scale);
            xy[0] = x * 4;
            xy[1] = (y + offset) * 4;
            func_800E30E0(gfx, sprite, 0, xy);
            i--;
        } while (i >= 0);
    }
}

// Width of the icon row.
s32 sccustom_banjo_entrypoint_2(s32 infobar)
{
    s32 last = _scinfobar_entrypoint_20(infobar) - 1;
    f32 scale = _scinfobar_entrypoint_18(infobar);
    return (last * 20 + 0x28) * scale;
}

// Height of the air meter.
s32 sccustom_banjo_entrypoint_3(s32 infobar)
{
    s32 last;
    f32 scale;

    last = func_800CF6D0() - 1;
    scale = _scinfobar_entrypoint_18(infobar);
    scale = (last * 20 + 40) * scale;
    return (s32) scale;
}
