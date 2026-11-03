// TU-NOTE: maps to BK core2/code_9290.c
#include "common.h"
#include "core2/1E75920.h"
#include "core2/1E7D460.h"

s32 func_80090B90(void)
{
    return sizeof(BaUnknown2C);
}

void func_80090B98(PlayerState *self)
{
    self->unk2C->unk0 = self->unk2C->unk4 = -1;
    self->unk2C->unk18 = 0;
    self->unk2C->unk8 = -1;
    func_8009C128(self, self->unk2C->unkC);
    self->unk2C->unk19 = self->unk2C->unk1A = 0;
}

void func_80090C00(PlayerState *self, s32 arg1, s32 arg2)
{
    func_800CBB70(arg1, arg2);
}

void func_80090C28(PlayerState *self, s32 arg1)
{
    self->unk2C->unk18 = arg1;
}

#ifndef NONMATCHING

// Per-frame zone lookup: radius 300, then radius 900 restricted to the previous zone id.
void func_80090C34(u8 *player)
{
    s32 in_zone;
    s32 unk_0;
    s32 hit;
    // Matching: offset in a variable is needed for the match.
    int offset;
    s32 unk_1;
    s32 unk_2;
    f32 pos[3];
    s32 unk_3;
    (*(u8 **) (player + 0x2C))[0x1A] = (*(u8 **) (player + 0x2C))[0x19];
    (*(u8 **) (player + 0x2C))[0x19] = 0;
    // Matching: the "&& 1" is needed for the match.
    unk_3 = func_8008E37C(player) != 0 && 1;
    if ((((((*(u8 **) (player + 0x2C))[0x18] != 0) || (player_isStable(player) != 0)) ||
          (unk_3 != 0)) ||
         (func_800F3ED0(player) == 5)) ||
        (bs_getCurrentState(player) == 0xB)) {
        func_8009C128(player, *(u8 **) (player + 0x2C) + 0xC);
    }
    if (func_800F3ED0(player) == 0xA) {
        *(s32 *) (*(u8 **) (player + 0x2C) + 8) = -1;
        return;
    }
    unk_0 = func_8008E37C(player) ? 6 : 1;
    unk_1 = *(s32 *) (*(u8 **) (player + 0x2C) + 0);
    offset = 4;
    unk_2 = *(s32 *) (*(u8 **) (player + 0x2C) + 4);
    hit = func_800CCDF4(*(u8 **) (player + 0x2C) + 0xC, *(u8 **) (player + 0x2C),
                        *(u8 **) (player + 0x2C) + offset, 0x12C, unk_0);
    in_zone = hit != 0;
    if (in_zone != 0) {
        (*(u8 **) (player + 0x2C))[0x19] = 1;
    }
    if ((in_zone == 0) && (*(s32 *) (*(u8 **) (player + 0x2C) + 8) != -1)) {
        func_801107F0(func_800A4CA8(player), pos);
        hit = func_800CCDF4(pos, &unk_1, &unk_2, 0x384, unk_0);
        if (hit != 0) {
            if (func_800CBBC0(unk_1) != *(s32 *) (*(u8 **) (player + 0x2C) + 8)) {
                hit = 0;
            } else {
                *(s32 *) (*(u8 **) (player + 0x2C) + 0) = unk_1;
                *(s32 *) (*(u8 **) (player + 0x2C) + offset) = unk_2;
            }
        }
    }
    if (hit != 0) {
        *(s32 *) (*(u8 **) (player + 0x2C) + 8) =
            func_800CBBC0(*(s32 *) (*(u8 **) (player + 0x2C) + 0));
    } else {
        *(s32 *) (*(u8 **) (player + 0x2C) + 8) = -1;
    }
}

#else
s32 func_80090C34(0)
{
#endif

    s32 func_80090E24(PlayerState * self)
    {
        return self->unk2C->unk8;
    }

    s32 func_80090E30(PlayerState * self)
    {
        return self->unk2C->unk1A;
    }
