// Accessors for placed prop records in the cube grid: position, radius, control type, ids, and
// the per-prop parameter word.
#include "common.h"

extern s16 D_80800140_gspropctrl[];

int gspropctrl_entrypoint_0(u8 *prop)
{
    return prop[10];
}

// Position as s32 into out; returns the radius.
u32 gspropctrl_entrypoint_1(u8 *prop, u8 *out)
{
    *(s32 *) ((s8 *) out + 0) = (s32) *(s16 *) ((s8 *) prop + 0);
    *(s32 *) ((s8 *) out + 4) = (s32) *(s16 *) ((s8 *) prop + 2);
    *(s32 *) ((s8 *) out + 8) = (s32) *(s16 *) ((s8 *) prop + 4);
    return (u32) *(u16 *) ((s8 *) prop + 6) >> 7;
}

// Control type (6-bit field at +4).
int gspropctrl_entrypoint_2(s32 prop[3])
{
    return ((u32) prop[1] << 0x19) >> 26;
}

// Returns the parameter word at +0xC.
int gspropctrl_entrypoint_3(Actor *prop)
{
    return *(s32 *) ((char *) prop + 0xC);
}

int gspropctrl_entrypoint_4(int prop)
{
    return *(unsigned short *) (prop + 8);
}

// Sets the parameter word at +0xC.
void gspropctrl_entrypoint_5(void *prop, s32 value)
{
    *(s32 *) ((char *) prop + 0xC) = value;
}

// Combines a 3-bit field at +0x10 with a 2-bit field at +8.
int gspropctrl_entrypoint_6(Actor *prop)
{
    return ((*(s32 *) ((char *) prop + 0x10) & 7) * 4) +
           (((u32) *(s32 *) ((char *) prop + 0x8) << 19) >> 30);
}

// Looks up an entry of the small type table.
s32 gspropctrl_entrypoint_7(s32 type)
{
    return D_80800140_gspropctrl[type];
}

// Radius of the prop (u16 at +6, >> 7).
s32 gspropctrl_entrypoint_8(void *prop)
{
    return (u32) *(u16 *) ((char *) prop + 0x6) >> 7 | 0;
}

// Copy a position as s16 to s32.
s32 gspropctrl_entrypoint_9(s16 src[3], s32 dst[3])
{
    dst[0] = src[0];
    dst[1] = src[1];
    dst[2] = src[2];
}

// Copy a position as s16 to s16.
s32 gspropctrl_entrypoint_10(s16 src[3], s16 dst[3])
{
    dst[0] = src[0];
    dst[1] = src[1];
    dst[2] = src[2];
}

// Copy a position as s16 to f32.
s32 gspropctrl_entrypoint_11(s16 src[3], f32 dst[3])
{
    dst[0] = (f32) src[0];
    dst[1] = (f32) src[1];
    dst[2] = (f32) src[2];
}

// High 9 bits of the parameter word at +0xC.
int gspropctrl_entrypoint_12(Actor *prop)
{
    return (*(s32 *) ((char *) prop + 0xC) & 0xFFFFFFFF) >> 23;
}

// Low 23 bits of the parameter word at +0xC.
int gspropctrl_entrypoint_13(Actor *prop)
{
    u32 value;
    value = (value = *(s32 *) ((char *) prop + 0xC) & 0x007FFFFF);
}

s16 D_80800140_gspropctrl[32] = {0x0,    0x32,   0x64,   0xC8,   0x15E,  0x1F4,  0x28A,  0x320,
                                 0x3B6,  0x44C,  0x578,  0x6A4,  0x7D0,  0x8FC,  0xA28,  0xB54,
                                 0xC80,  0xDAC,  0xED8,  0x1004, 0x1130, 0x125C, 0x1388, 0x157C,
                                 0x1770, 0x1964, 0x1B58, 0x1D4C, 0x1F40, 0x2134, 0x2328, 0x251C};
