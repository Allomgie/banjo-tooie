#include "common.h"

// Extra health pieces are stored as a 3-bit field at game flag 0x4EA.
s32 gcextra_entrypoint_0(void)
{
    func_800DA564(0x4EA, 3);
}

// Maximum number of extra health pieces.
s32 gcextra_entrypoint_1()
{
    return 0x5;
}

// Adds extra health pieces, clamped to the maximum, then refreshes health.
void gcextra_entrypoint_2(s32 amount)
{
    s32 total;
    s32 max_pieces;

    total = gcextra_entrypoint_0() + amount;
    max_pieces = gcextra_entrypoint_1();
    if (max_pieces < total) {
        total = max_pieces;
    }
    func_800DA7A8(0x4EA, total, 3);
    func_800D517C();
}

// TU-NOTE: the .data of this overlay (formerly asm/data/overlays/gc/extra.data.s) is defined
// here in C. Values are taken from the ROM.
