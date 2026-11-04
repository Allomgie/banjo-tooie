#include "common.h"

extern int D_80800030_fxgenlist[];
extern int D_8080005C_fxgenlist[];
extern int D_808000A0_fxgenlist[];
extern s32 D_808000D0_fxgenlist[];

// Getters for the static particle-preset lists.
int fxgenlist_entrypoint_0()
{
    return (int) &D_80800030_fxgenlist;
}

int fxgenlist_entrypoint_1()
{
    return (int) &D_8080005C_fxgenlist;
}

int fxgenlist_entrypoint_2()
{
    return (int) &D_808000A0_fxgenlist;
}

int fxgenlist_entrypoint_3()
{
    return (int) D_808000D0_fxgenlist;
}

// TU-NOTE: the overlay's .data is defined here in C; values taken from the ROM. The extern
// declarations above are adjusted to int[] for the first three lists (same addresses).
int D_80800030_fxgenlist[11] = {0x1D06A5, 0x14002D, 0x12C0190, 0x220017, 0x1C000F, 0x11001E,
                                0xF000F,  0xAFFF6,  0xFFF6,    0xA0014,  0xA0000};
int D_8080005C_fxgenlist[17] = {0x1D09E2, 0x161004,   0x27FF38, -0xC7FF38, 0xC8002D, 0x12C01F4,
                                0x1BFDA8, -0x18FFFDE, 0x470042, 0x26001E,  0x2B00C0, 0xD90015,
                                0xCC,     0x1E000F,   0xF000E,  0x14001E,  0x0};
int D_808000A0_fxgenlist[12] = {0x1D078F,  0x150000, 0x990016,  0x2000032, 0x20018,  0x0,
                                0xF000F00, 0x220199, 0x1CC0280, 0x380002B, 0xCC0100, 0x0};
s32 D_808000D0_fxgenlist[20] = {0x810001D, 0x78F0015, 0x200B3,   0x320002, 0x161000,
                                0x1E0032,  0x32000E,  0x4B0078,  0x180000, 0xC38,
                                0xC380022, 0x1000100, 0x1E60233, 0x2A0002, 0x200E6,
                                0xE6000F,  0x0,       0x0,       0x0,      0x0};
