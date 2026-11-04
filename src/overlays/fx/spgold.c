#include "common.h"

extern u8 D_80127115[];
extern void *D_80800090_fxspgold;
extern s32 func_800B56D0(s32);
extern void func_800BABB8(s32, s32, s32, f32, void *);

void fxspgold_entrypoint_0()
{
    func_800B58D4(*(u8 *) ((u8 *) (u8 *) D_80127115 + 0xb));
}

// Reserves a shared emitter slot (sprite 0x14) and stores its index.
int fxspgold_entrypoint_1()
{
    s32 slot;
    slot = func_800B5758(0x14);
    D_80127115[0xb] = slot;
}

void fxspgold_entrypoint_2(s32 pos)
{
    s32 emitter;
    u8 *slot = &D_80127115[0xB];
    emitter = func_800B56D0(*slot);
    // Matching: `| 0` is needed for the match.
    func_800BABB8(emitter | 0, pos, 0, 1.0f, &D_80800090_fxspgold);
}

// TU-NOTE: the .data of this overlay is defined here in C; values taken from the ROM.
void *D_80800090_fxspgold = (void *) 0x001BFF06;
static u32 D_80800090_fxspgold_rest[11] = {0xFF060015, 0x6600CC,   0x220038, 0x380007,
                                           0x70027,    0xC8,       0xF0,     0x2B00B3,
                                           0xB30016,   0x10000000, 0x0};
