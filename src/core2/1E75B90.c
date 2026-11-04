// Probably a single helper: maps a player body part to a model bone and fetches its position.
#include "common.h"

// TU-NOTE: D_80117F02 is a linker symbol (undefined_syms) = D_80117F00 + 0x2; data is defined below.
extern s16 D_80117F02[][2];

// Maps a player body-part index to a model bone and fetches that bone's position.
int func_8009C2A0(s32 param_0, int part)
{
    s16 *entry;
    short bone;
    entry = D_80117F02[part];
    bone = *entry;
    func_800DBEFC(param_0, bone);
}

u32 D_80117F00[12] = {0xFFFF,  0x10007, 0x20006, 0x30005, 0x40004, 0x50008,
                      0x6000D, 0x7000A, 0x80009, 0x9000B, 0xA000A, 0x0};
