// Two unrelated parts: the asset cache's free-memory threshold and age cutoff, and the
// multiplayer minigame tournament state (selected games, rounds, scores, next round).
#include "common.h"

extern s32 D_8011A480[];
extern s32 D_8011A498[];
extern s32 D_80127770;
// Multiplayer tournament state: round index, flags, per-player values.
typedef struct {
    s16 round;
    s8 unk_2;
    s8 unk_3;
    s16 score[4];
    s16 round_score[4];
} Struct_80127780;
Struct_80127780 D_80127780;
extern char D_80127783;
extern s16 D_80127784[];
extern s16 D_8012778C[];
extern u8 D_80127782;

// Memory budget: free-memory threshold and age cutoff used when trimming the asset cache.
// Looks up the free-memory threshold for an id in D_8011A480 (default 0x3E800).
// Matching: the line breaks in this function are needed for the match.
void func_800A9EC0(s32 id)
{
    s32 *entry;
    s32 value;
    value = id; D_80127770 = 0x3E800;
    do { entry = (s8 *) D_8011A480; loop_1: if (value == *(s16 *) (entry + 0)) { value = 9; value = *(s16 *) ((s8 *) entry + 2) << value; D_80127770 = value << 1; return; } } while (0);
    entry += 1;
    if (entry == D_8011A498)
    {
        return;
    }
    goto loop_1;
}

// Cache age offset for a trim level.
func_800A9F14(level)
{
    if (level == 2)
        return 3;
    return 0x12;
}

// Nonzero when the largest free block exceeds the threshold.
int func_800A9F30()
{
    s32 largest_free;
    func_8001BDAC(&largest_free, 1);
    return D_80127770 < largest_free;
}

// Multiplayer minigame tournament: selected games, round counter, scores, starting the next round.
// Sets the game flag of a minigame.
int func_800A9F60(minigame)
s32 minigame;
{
    func_800DA3B8(minigame + 0xD1B);
}

// Gets the game flag of a minigame.
int func_800A9F80(minigame)
s32 minigame;
{
    func_800DA298(minigame + 0xD1B);
}

// Returns the minigame index of the n-th selected minigame.
s32 func_800A9FA0(n)
s32 n;
{
    s32 seen = 0;
    s32 i;
    for (i = 0x40; i != 0x4E; i++) {
        if (func_800A9F80(i) && seen++ == n)
            break;
    }
    return i;
}

void func_800AA00C(void)
{
    s32 i;
    D_80127780.round = -1;
    D_80127780.unk_3 = 0;
    D_80127780.unk_2 = 0;
    for (i = 0; i < 4; i++) {
        D_80127780.score[i] = D_80127780.round_score[i] = 0;
    }
}

void func_800AA054(s32 minigame)
{
    func_800A9F60(minigame, 1);
}

int func_800AA074()
{
    s32 i;
    for (i = 0x40; i < 0x4E; i++) {
        // Matching: the no-op `| 0` is needed for the match.
        func_800A9F60(i | 0, 0);
    }
}

u8 func_800AA0B8()
{
    return D_80127783;
}

int func_800AA0C4()
{
    return (*((s16 *) &D_80127780));
}

// Number of selected minigames.
s32 func_800AA0D0(void)
{
    s32 i;
    s32 count;

    count = 0;
    for (i = 0x40; i < 0x4E; i++) {
        count += func_800A9F80(i);
    }
    return count;
}

// Minigame of the next round.
s32 func_800AA120(void)
{
    func_800A9FA0((*((s16 *) &D_80127780)) + 1);
}

// Minigame of the current round.
int func_800AA148()
{
    func_800A9FA0((*((s16 *) &D_80127780)));
}

int func_800AA16C(s32 player)
{
    return D_80127784[player];
}

int func_800AA180(s32 player)
{
    return D_8012778C[player];
}

s32 func_800AA194(void)
{
    return (*((u8 *) &D_80127782));
}

// Starts the next round through the gcfrontend overlay.
void func_800AA1A0(void)
{
    s32 i;
    D_80127780.unk_3 = 1;
    D_80127780.round++;
    D_80127780.unk_2 = 0;
    for (i = 0; i < 4; i++) {
        D_80127780.round_score[i] = 0;
    }
    _gcfrontend_entrypoint_7(func_800AA148(), 1);
}

int func_800AA200(unsigned int value)
{
    D_80127782 = value;
}

int func_800AA20C(s32 player, int value)
{
    D_8012778C[player] = value;
}

int func_800AA220(s32 player, s32 delta)
{
    ((s16 *) &D_80127780)[player + 2] += delta;
}

// Nonzero in the last round.
int func_800AA240()
{
    s32 round;
    round = func_800AA0C4();
    return round >= func_800AA0D0() - 1;
}

int func_800AA274()
{
    func_800A9F80();
}

// TU-NOTE: the .data of this file is defined here in C (values from the ROM). The externs
// above declare D_8011A480 and D_8011A498 as s32[] (uses written as NAME[0]).
s32 D_8011A480[6] = {0x1A7015E, 0x1A8015E, 0x1A9015E, 0x112015E, 0x136015E, 0xD6015E};
s32 D_8011A498[2] = {0x0, 0x0};
