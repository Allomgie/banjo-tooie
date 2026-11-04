#include "common.h"

// Unpacks palette entry idx (R in bits 0-7 ... A in bits 24-31) into four s32 channels.
void dbpalette_entrypoint_0(s32 palette, s32 idx, u8 *channels)
{
    u32 *entry;
    entry = palette + ((unsigned long) idx * 4);
    *(s32 *) ((s8 *) channels + 0) = (s32) (*entry & 0xFF);
    *(s32 *) (channels - -4) = (s32) (((u32) *entry >> 8) & 0xFF);
    *(s32 *) ((s8 *) channels + 8) = (s32) (((u32) *entry >> 0x10) & 0xFF);
    *(s32 *) ((s8 *) channels + 0xC) = (s32) (((u32) *entry >> 0x18) & 0xFF);
}

// Packs four s32 channels into palette entry idx.
s32 dbpalette_entrypoint_1(u32 *palette, int idx, s32 *channels)
{
    palette[idx] = 0;
    palette[idx] = (u32) channels[0];
    palette[idx] |= (u32) channels[1] << 8;
    palette[idx] |= (u32) channels[2] << 0x10;
    palette[idx] |= (u32) channels[3] << 0x18;
}
