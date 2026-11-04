// Most likely the player's per-medium traction override (PlayerState+0x74, 5 ground media):
// func_80094E98 returns the override for the current medium if enabled, else the global default.

#include "common.h"

s32 func_80094E70(void)
{
    return 0x1C;
}

s32 func_80094E78()
{
    func_800964D0();
}

// Returns the traction factor override for the current medium, else the default.
f32 func_80094E98(Actor *player)
{
    s32 medium;
    unsigned int overrides; // flags[5] followed by factors[5] (f32)
    f32 func_800D8840(s32);
    medium = func_80094E78(player);
    {
        overrides = *(s32 *) ((char *) player + 0x74);
        if (*(u8 *) (overrides + medium) != 0) {
            return *(f32 *) ((overrides + (medium * 4)) + 8);
        }
    }
    return func_800D8840(medium);
}

int func_80094EEC(s32 player, s32 medium)
{
    return func_800964D0(player) == medium;
}

void func_80094F14(u8 *player, s32 medium, s32 enabled, f32 factor)
{
    *(u8 *) (*(s32 *) (player + 0x74) + medium) = enabled;
    *(f32 *) ((*(s32 *) (player + 0x74) + (medium * 4)) + 8) = factor;
}

void func_80094F38(void *player)
{
    s32 i;
    for (i = 0; i < 5; i++) {
        ((u8 **) player)[0x1D][i] = 0;
    }
}
