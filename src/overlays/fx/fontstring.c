// Helpers that append inline text control codes (switch, color, alpha, icon) to a string
// and return the new end.
#include "common.h"

s32 func_80800000_fxfontstring(char *str)
{
    while (*str) {
        str++;
    }
    return str;
}

// Appends text control code 0xFD 'h' (high != 0) or 0xFD 'l' to str.
// Matching: the line breaks in this function are needed for the match.
void fxfontstring_entrypoint_0(s32 str, s32 high)
{
    u8 *end;
    do { do { end = func_80800000_fxfontstring(str); *end = 0xFD; end++; if (high != 0) { *end = 0x68; } else { *end = 0x6C; } end++; *end = 0; } while (0); } while (0);
}

// Appends text control code 0xFD 'a' n, with n clamped to 1..255.
void fxfontstring_entrypoint_1(u8 *str, s32 n)
{
    u8 *end;
    u8 *p;
    s32 clamped;

    end = func_80800000_fxfontstring(str);
    end[0] = 0xFD;
    end[1] = 0x61;
    p = end + 2;
    if (n <= 0) {
        *p = 1;
    } else {
        clamped = n >= 256 ? 255 : n;
        *p = clamped;
    }
    p++;
    *p = 0;
}

// Appends text control code 0xFD 'c' r g b, each clamped to 1..255.
u8 *fxfontstring_entrypoint_2(s32 str, s32 r, s32 g, s32 b)
{
    u8 *p;
    s32 v;

    p = func_80800000_fxfontstring(str);
    *p++ = 0xFD;
    *p++ = 0x63;
    if (r <= 0) {
        *p = 1;
    } else {
        if (r >= 0x100) {
            v = 0xFF;
        } else {
            v = r;
        }
        *p = v;
    }
    p++;
    if (g <= 0) {
        *p = 1;
    } else {
        if (g >= 0x100) {
            v = 0xFF;
        } else {
            v = g;
        }
        *p = v;
    }
    p++;
    if (b <= 0) {
        *p = 1;
    } else {
        if (b >= 0x100) {
            v = 0xFF;
        } else {
            v = b;
        }
        *p = v;
    }
    *++p = 0;
}

// Appends inline icon code 0xFD 'i' id_lo id_hi (size + 1).
int fxfontstring_entrypoint_3(s32 str, u32 icon_id, s32 size)
{
    u8 *p;
    // Matching: the u16 temporary is needed for the match.
    unsigned short id;
    p = func_80800000_fxfontstring(str);
    id = icon_id;
    *p++ = 0xFD;
    *p++ = 0x69;
    *p++ = icon_id & 0xFF;
    *p++ = id >> 8;
    *p++ = size + 1;
    *p++ = 0;
}

// TU-NOTE: .data is defined here in C; values are taken from the ROM.
