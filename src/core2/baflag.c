// Per-player boolean flag array (0x42 bytes at PlayerState+0x80): set, clear, test, clear all.
#include "common.h"
#include "overlays/ba/flag.h"

// Size of the per-player flag array.
s32 baflag_getStuctSize(void)
{
    return sizeof(BaFlag);
}

// Clears every flag except index 0.
void baflag_clearAll(PlayerState *player)
{
    BaFlagId id;
    for (id = 1; id < NUM_BA_FLAGS; id++) {
        baflag_clear(player, id);
    }
}

int baflag_isTrue(PlayerState *player, BaFlagId id)
{
    return player->flag->bytes[id];
}

int baflag_isFalse(PlayerState *player, BaFlagId id)
{
    return !player->flag->bytes[id];
}

void baflag_set(PlayerState *player, BaFlagId id)
{
    player->flag->bytes[id] = 1;
}

void baflag_clear(PlayerState *player, BaFlagId id)
{
    player->flag->bytes[id] = 0;
}
