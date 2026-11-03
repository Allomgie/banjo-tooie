#include "common.h"

// Font header: first s16.
func_800B0D50(s16 *font)
{
    return font[0];
}

// Font header: second s16 (format flags).
func_800B0D58(s16 *font)
{
    return font[1];
}

// Palette/data base: font + offset stored at +8.
s32 func_800B0D60(s32 font)
{
    int addr;
    s32 offset;
    long data_offset;
    s32 *offset_ptr;
    offset = 8;
    // Matching: the extra temporaries and the redundant &* are needed for the match.
    offset_ptr = &*(s32 *) (addr = font + offset);
    offset = *offset_ptr;
    data_offset = *offset_ptr;
    return font + data_offset;
}

// Address of the 8-byte glyph entry at +0xC for the given index.
int func_800B0D6C(s32 font, s32 index)
{
    return (s32) & ((char *) font)[0xC + index * 8];
}
