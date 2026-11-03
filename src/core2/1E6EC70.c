#include "core2/1E6EC70.h"

extern s32 D_80117E60[];
typedef struct {
    u8 pad0[0xC];
    u8 unk_C;
} P_95588;
typedef struct {
    u8 pad0[0x7C];
    P_95588 *fall;
} S_95588;
extern void func_8009C128(PlayerState *param_0, s32 param_1);

s32 func_80095380(void)
{
    return 0x18;
}

// Walks the damage table (negative threshold ends it); the first entry whose
// threshold + 1000 + bonus is below the fall height gives the type and amount.
u8 func_80095388(u32 *out_type, s32 fall_height, u8 *table, s32 bonus)
{
    s32 tolerance = bonus + 0x3E8;
    s16 *entry = (s16 *) (table + 12);
    s32 sum;
    s16 val;

    if (entry[0] >= 0) {
        do {
            val = entry[0];
            sum = val + tolerance;
            if (sum < fall_height) {
                *out_type = (u8) ((u8 *) entry)[2];
                return ((u8 *) entry)[3];
            }
            entry += 2;
            val = entry[0];
        } while (val >= 0);
    }
    return 0;
}

// Fall damage for a fall height; one transformation gets +1000 tolerance with an ability.
s32 func_800953E0(s32 player, s32 *out_type, s32 fall_height)
{
    s32 transform;

    *out_type = 0;
    if (fall_height < 0) {
        return 0;
    }
    transform = func_800A3274(player);
    switch (transform) {
        case 10:
            if (func_8009E71C(player, 0x13) != 0) {
                return func_80095388(out_type, fall_height, D_80117E60, 0x3E8);
            }
        default:;
        case 2:
        case 3:;
        case 4:
        case 19:
            return func_80095388(out_type, fall_height, D_80117E60, 0);
    }
}

// Stores the current fall damage computed from the reference height.
void func_80095490(Actor *player)
{
    char *fall_bytes;
    f32 pos_y;
    f32 pos_x;
    func_8009C128(player, &pos_x);
    {
        u8 *fall_state = *(u8 **) ((char *) player + 0x7C);
        fall_bytes = (char *) fall_state;
        *(s32 *) ((char *) *(u8 **) ((char *) player + 0x7C) + 0x14) =
            func_800953E0(player, fall_state + 0x10, (s32) (*(f32 *) (fall_bytes + 0x4) - pos_y));
    }
}

// Returns the fall damage; the type is zeroed when func_800D3E40(3) is set.
s32 func_800954E8(u8 *player, s32 *out_type)
{
    if (func_800D3E40(0x3) != 0) {
        *out_type = 0;
    } else {
        *out_type = *(*(s32 **) (player + 0x7C) + 4);
    }
    return *(*(s32 **) (player + 0x7C) + 5);
}

f32 func_80095534(void *player)
{
    s32 fall_height;
    struct {
        s32 unk_0;
        f32 y;
    } pos;
    func_8009C128(player, &pos);
    fall_height = (s32) (*(f32 *) (*(s32 *) ((char *) player + 0x7C) + 4) - pos.y);
    return (f32) fall_height;
}

// Matching: the chain of temporaries is needed for the match.
s32 func_8009557C(PlayerState *player)
{
    char *unk_0;
    char *unk_1;
    char *unk_2;
    PlayerState *unk_3;
    s32 *fall_tracker;
    s32 **unk_4;
    unk_2 = (char *) (unk_3 = player);
    unk_0 = unk_2;
    unk_1 = unk_0;
    fall_tracker = *(unk_4 = (s32 **) (unk_1 + 0x7C));
    unk_0 = *(unk_4 = (s32 **) (unk_1 + 0x7C));
    return unk_0[0xC];
}

void func_80095588(S_95588 *player, s32 value)
{
    player->fall->unk_C = value;
    if ((player->fall->unk_C == 2) || (player->fall->unk_C == 3)) {
        func_800956B8(player);
    }
}

void func_800955CC(Actor *player)
{
    func_8009C128(player, *(u32 **) ((u8 *) player + 0x7c));
    *(*(u8 **) ((u8 *) player + 0x7c) + 0xc) = 0;
    func_80095588(player, 1);
    *(*(u32 **) ((u8 *) player + 0x7c) + 4) = 0;
    *(*(u32 **) ((u8 *) player + 0x7c) + 5) = *(*(u32 **) ((u8 *) player + 0x7c) + 4);
}

// Resets the reference height when the player is stable, in water or in states 0xBE/0x15C.
void func_8009561C(s32 player)
{
    s32 unk_0;
    s32 stable;
    s32 state;
    unk_0 = func_800F3ED0();
    stable = player_isStable(player);
    state = bs_getCurrentState(player);
    if ((stable != 0) || (func_800F40EC(player) != 0) || (state == 0xBE) ||
        (state == 0x15C) || (unk_0 == 0xA)) {
        func_800956B8(player);
        func_80095588(player, 1);
    }
    func_80095490(player);
}

void func_800956B8(player) PlayerState *player;
{
    func_8009C128(player, *(s32 *) ((char *) player + 0x7c));
}

// TU-NOTE: the .data of this file (formerly asm/data/core2/1E6EC70.data.s) is defined here in C;
// values are taken from the ROM. The extern above is declared as s32[] (same address) and used as NAME[0].
// Entries are {s16 threshold, u8 type, u8 amount}, terminated by a negative threshold.
s32 D_80117E60[12] = {0x3E80000, 0x5DC0000, 0x7D00000, 0x1B580802, 0x17700701, 0x13880601,
                      0xFA00501, 0xBB80401, 0x7D00301, 0x3E80201,  0x101,      -0x10000};
