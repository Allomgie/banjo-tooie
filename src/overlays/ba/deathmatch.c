#include "common.h"
#include "playerstate.h"

extern u8 D_80800550_badeathmatch[];
typedef struct {
    s16 max_ammo[8];
    s16 ammo[8];
    u8 current;
} DeathmatchEggState;
typedef struct {
    u8 pad_0[0x158];
    DeathmatchEggState *eggs;
} DeathmatchEggPlayer;
typedef struct {
    u8 pad_0[0x21];
    u8 unlimited;
    u8 timed;
    u8 unk_23;
} DeathmatchFlags1312;
extern s16 func_800F0D90();
typedef struct {
    u8 pad_0[0x20];
    u8 current;
    u8 unlimited;
} DeathmatchStateView;
typedef struct {
    u8 pad_0[0x158];
    DeathmatchStateView *egg_state;
} DeathmatchPlayerView;
extern void _batimer_set(PlayerState *, s32, f32);
typedef struct {
    s16 states[8];
    s16 scores[8];
    u8 pad_0, countdown;
} DeathmatchScores1446;
typedef struct {
    u8 pad_0[0x158];
    DeathmatchScores1446 *scores;
} DeathmatchPlayer1446;
extern f32 _batimer_get(void *, s32);
void badeathmatch_entrypoint_8(PlayerState *player, f32 duration);

void func_80800000_badeathmatch(void *player)
{
    *(s8 *) ((s8 *) *(u8 **) ((s8 *) player + 0x158) + 0x20) = 1;
    *(s8 *) ((s8 *) *(u8 **) ((s8 *) player + 0x158) + 0x21) = 0;
    *(s8 *) ((s8 *) *(u8 **) ((s8 *) player + 0x158) + 0x22) = 0;
    *(s8 *) ((s8 *) *(u8 **) ((s8 *) player + 0x158) + 0x23) = 0;
}

int func_80800028_badeathmatch(s32 index)
{
    u8 *table;
    table = &D_80800550_badeathmatch;
    table--;
    return table[index];
}

// Selects the next egg type that has ammo.
s32 badeathmatch_entrypoint_0(DeathmatchEggPlayer *player)
{
    DeathmatchEggState *state;
    s32 i;
    s32 type;

    state = player->eggs;
    type = state->current;
    for (i = 1; i < 8; i++) {
        type = func_80800028_badeathmatch(type);
        if (state->ammo[type])
            break;
    }
    while (!state->max_ammo[type]) {
        type = func_80800028_badeathmatch(type);
    }
    player->eggs->current = type;
    func_800FC6B0(_gcegg_entrypoint_2(type));
    return type;
}

// Allocates the egg ammo state, only on maps with flag 0x40.
void badeathmatch_entrypoint_1(u8 *player)
{
    s32 state;

    if (func_800EA068(0x40) != 0) {
        state = heap_alloc(0x30);
        *(s32 *) ((s8 *) player + 0x158) = state;
        aligned8_memset(state, 0, 0x30);
        func_80800000_badeathmatch(player);
    }
}

void badeathmatch_entrypoint_2(u8 *player)
{
    unsigned int state_copy;
    s32 state;
    state = *(s32 *) ((s8 *) player + 0x158);
    // Matching: extra temporary copy for the match.
    state_copy = state;
    if (state != 0) {
        heap_free(state_copy, player, *(s32 *) ((s8 *) player + 0x158));
        *(s32 *) ((s8 *) player + 0x158) = 0;
        func_800C968C(func_800A4C68(player), 9);
    }
}

void badeathmatch_entrypoint_3(PlayerState *player)
{
    DeathmatchFlags1312 *state;
    u8 unk_1;

    if (func_800A3274() != 0x11 && bs_getCurrentState(player) != 0xD7) {
        state = *(DeathmatchFlags1312 **) ((u8 *) player + 0x158);
        if (!state->unlimited) {
            unk_1 = state->unk_23;
            if (((unk_1 == 0) & 1) && bainput_func_80097D28(player)) {
                badeathmatch_entrypoint_0(player);
            }
        } else if (state->timed && _batimer_decrement(player, 0xD)) {
            badeathmatch_entrypoint_8(player, 0.0f);
        }
    }
}

int badeathmatch_entrypoint_4(int item_id)
{
    switch (item_id - 0x40) {
        case 0:
            return 1;

        case 1:
            return 2;

        case 2:
            return 3;

        case 3:
            return 4;

        case 4:
            return 5;

        case 5:
            return 6;
    }

    return 0;
}

s16 badeathmatch_entrypoint_5(u8 *player, s32 egg, s32 delta)
{
    s16 max_ammo;
    s32 value;
    u8 *entry;
    u8 *state;

    entry = (u8 *) (egg * 2 + (s32) *(u8 **) (player + 0x158));
    max_ammo = *(s16 *) entry;
    if (max_ammo < 0) {
        return 1;
    }
    value = *(s16 *) (entry + 0x10) + delta;
    *(s16 *) (*(u8 **) (player + 0x158) + egg * 2 + 0x10) =
        func_800F0D90(value, 0, max_ammo, player);
    if (delta > 0) {
        state = *(u8 **) (player + 0x158);
        value = egg * 16;
        value += *(s32 *) (player + 0x184);
        if (*((s16 *) state + state[0x20] + 8) == 0) {
            state[0x20] = egg;
        }
        func_80101238(0x72, value);
    }
    return *(s16 *) (*(u8 **) (player + 0x158) + egg * 2 + 0x10);
}

u8 badeathmatch_entrypoint_6(DeathmatchPlayerView *player)
{
    DeathmatchStateView *state;
    u8 egg;

    state = player->egg_state;
    if (state->unlimited) {
        egg = 7;
    } else {
        egg = state->current;
    }
    return egg;
}

void badeathmatch_entrypoint_7(s32 player, s32 egg)
{
    *(u8 *) (*(s32 *) (player + 0x158) + 0x20) = egg;
}

void badeathmatch_entrypoint_8(PlayerState *player, f32 duration)
{
    if (duration != 0.0f)
        (*(u8 **) ((u8 *) player + 0x158))[0x21] = 1;
    else
        (*(u8 **) ((u8 *) player + 0x158))[0x21] = 0;
    if (duration > 0.0f)
        (*(u8 **) ((u8 *) player + 0x158))[0x22] = 1;
    else
        (*(u8 **) ((u8 *) player + 0x158))[0x22] = 0;
    _batimer_set(player, 0xD, duration);
    if (!(*(u8 **) ((u8 *) player + 0x158))[0x21])
        func_80101180(0x1CD, 0x76, 0);
}

s32 badeathmatch_entrypoint_9(DeathmatchPlayer1446 *player, s32 egg)
{
    DeathmatchScores1446 *view;
    s32 value;
    s32 score;
    s16 *slot;

    view = player->scores;
    slot = view->states + egg;
    if (view->countdown) {
        return (s32) (_batimer_get(player, 0xD) + 0.5f);
    }
    value = slot[0];
    score = slot[8];
    if (value < 0) {
        value = 1;
    } else {
        value = score;
    }
    return value;
}

void badeathmatch_entrypoint_10(u8 *player, s32 egg, s32 ammo, s32 max_ammo)
{
    (*(s16 **) (player + 0x158))[egg + 8] = ammo;
    (*(s16 **) (player + 0x158))[egg] = max_ammo;
}

void badeathmatch_entrypoint_11(u8 *player, s32 mask, s32 set)
{
    u8 *state_set;
    u8 *state_clear;

    if (set != 0) {
        state_set = *(u8 **) ((s8 *) player + 0x158);
        *(u8 *) ((s8 *) state_set + 0x23) = (u8) (*(u8 *) ((s8 *) state_set + 0x23) | mask);
        return;
    }
    state_clear = *(u8 **) ((s8 *) player + 0x158);
    *(u8 *) ((s8 *) state_clear + 0x23) = (u8) (*(u8 *) ((s8 *) state_clear + 0x23) & ~mask);
}

u8 D_80800550_badeathmatch[16] = {0x2, 0x4, 0x5, 0x3, 0x6, 0x1, 0x0, 0x0,
                                  0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0};
