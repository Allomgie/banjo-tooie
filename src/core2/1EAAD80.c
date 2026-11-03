#include "core2/1EAAD80.h"

extern void *heap_alloc_sided(s32, s32);
typedef struct {
    s16 *counts;
    s32 side;
} G_D154C;
extern G_D154C D_8012B250;
extern s32 func_8001210C(s32);
extern void rare_memcpy(void *, void *, s32);
extern void heap_free();
s32 defrag();
extern u8 D_8011AF50[];
extern void func_800D24E8(s32, s32, s32);
typedef struct {
    s16 hud_id;
    s16 capacity;
} S8011AF50;
extern void func_800D2770(s32, s32);
extern s16 D_8011AF52[][2];
extern u8 D_8011AE50[11];

// Item counts are stored XORed with code words of func_800D1A04.
void func_800D1490(void)
{
    s32 i;
    for (i = 0; i < 21; i++) {
        D_8012B250.counts[i] = ((s16 *) &func_800D1A04)[i * 4];
    }
}

s32 func_800D1510(void)
{
    D_8012B250.side = 0;
    D_8012B250.counts = heap_alloc_sided(42, D_8012B250.side);
    func_800D1490();
}

// Every 0x200 frames or so, moves the counts to the next heap side.
void func_800D154C(void)
{
    void *old;
    s32 new_side;
    if (func_8001210C(0x3FF) != 0x1FF) {
        return;
    }
    old = D_8012B250.counts;
    D_8012B250.side++;
    new_side = D_8012B250.side;
    if (new_side == 3) {
        D_8012B250.side = 0;
        new_side = 0;
    }
    D_8012B250.counts = heap_alloc_sided(0x2A, new_side);
    rare_memcpy(D_8012B250.counts, old, 0x2A);
    heap_free(old);
}

void func_800D15CC()
{
    if ((s32) D_8012B250.counts != 0) {
        D_8012B250.counts = defrag((s32) D_8012B250.counts);
    }
}

void func_800D1604(void)
{
    heap_free((s32) D_8012B250.counts);
    D_8012B250.counts = 0;
}

// Matching: the line breaks in this function are needed for the match.
void func_800D162C(void)
{
    s32 counts_off;
    u8 *entry;
    s32 key_off;
    do { entry = D_8011AF50; counts_off = 0; key_off = 0; do { func_800D2770(*(s16 *) entry, *(s16 *) ((u8 *) D_8012B250.counts + counts_off) ^ *(s16 *) ((u8 *) &func_800D1A04 + key_off)); counts_off += 2; entry += 4; key_off += 8; } while (counts_off != 0x2A); } while (0);
}

int func_800D16C4(item_id)
s32 item_id;
{
    s32 index;
    index = item_id - 0x40;
    return index;
}

// Stores a count, clamped to 0..capacity (-2 = infinite, stored as 999).
void func_800D16CC(s32 index, s32 value)
{
    s16 capacity;
    s32 entry_off;

    entry_off = index * 4;
    // Matching: the doubled (u8 *) cast is needed for the match.
    capacity = *(s16 *) ((u8 *) (u8 *) D_8011AF52 + entry_off);
    if (capacity == -2) {
        *(s16 *) ((u8 *) D_8012B250.counts + index * 2) =
            *(s16 *) ((u8 *) func_800D1A04 + entry_off * 2) ^ 0x3E7;
        return;
    }
    if (value < 0) {
        value = 0;
    }
    if (capacity >= 0 && capacity < value) {
        value = capacity;
    }
    *(s16 *) ((u8 *) D_8012B250.counts + index * 2) =
        *(s16 *) ((u8 *) func_800D1A04 + entry_off * 2) ^ value;
}

void func_800D175C(s32 item_id, s32 delta)
{
    s32 index;
    index = func_800D16C4(item_id);
    func_800D16CC(index,
                  (D_8012B250.counts[index] ^ ((s16 *) &func_800D1A04)[index * 4]) + delta);
    func_800D24E8(((s16(*)[2]) D_8011AF50)[index][0],
                  D_8012B250.counts[index] ^ ((s16 *) &func_800D1A04)[index * 4], 0);
}

void func_800D1804(s32 item_id)
{
    func_800D175C(item_id, -1);
}

void func_800D1824(s32 item_id)
{
    func_800D175C(item_id, 0);
}

void func_800D1844(s32 item_id)
{
    func_800D175C(item_id, 1);
}

void func_800D1864(u32 item_id, u32 count, u32 unk_2)
{
    s32 index;
    index = func_800D16C4(item_id);
    func_800D16CC(index, count);
    if (unk_2 != 0) {
        func_800D2498(((S8011AF50 *) D_8011AF50)[index].hud_id,
                      D_8012B250.counts[index] ^ ((s16 *) &func_800D1A04)[index * 4],
                      ((S8011AF50 *) D_8011AF50)[index].capacity);
        return;
    }
    func_800D2770(((S8011AF50 *) D_8011AF50)[index].hud_id,
                  D_8012B250.counts[index] ^ ((s16 *) &func_800D1A04)[index * 4]);
}

s32 func_800D192C(s32 item_id, s32 unk_1)
{
    s32 count = func_800D1A04(item_id);
    // Matching: `| 0` is needed for the match.
    func_800D1864(item_id, count | 0, unk_1);
}

// Sets the capacity of an item (-2 = infinite); fill also sets the count to the capacity.
void func_800D1960(s32 item_id, s32 capacity, s32 fill)
{
    s32 index;
    s32 count;
    index = func_800D16C4();
    // Matching: the empty block is needed for the match.
    if (capacity > 0) {
    } else if (capacity != -2) {
        capacity = 1;
    }
    *(s16 *) ((u8 *) D_8011AF52 + index * 4) = capacity;
    if (fill != 0) {
        count = func_800D1A6C(item_id);
    } else {
        count = D_8012B250.counts[index] ^ ((s16 *) &func_800D1A04)[index * 4];
    }
    func_800D16CC(index, count);
}

// Returns the current count of an item (999 if infinite).
s32 func_800D1A04(item_id)
s32 item_id;
{
    s32 index;
    index = func_800D16C4(item_id);
    if (D_8011AF52[index][0] == -2)
        return 999;
    return D_8012B250.counts[index] ^ ((s16 *) &func_800D1A04)[index * 4];
}

u32 func_800D1A6C(item_id)
u32 item_id;
{
    u32 index;
    s16 capacity;
    index = func_800D16C4(item_id);
    capacity = *((s16 *) ((((char *) D_8011AF50) + (index * 4)) + 2));

if (capacity != -2) {
    if (capacity == -1) {
        return 0x32;
    }
}

else
{
    return 999;
}
return *((s16 *) ((((char *) D_8011AF50) + (index * 4)) + 2));

}

// Default capacity per item.
int func_800D1ACC(s32 item_id)
{
    switch (item_id - 0x40) {
        case 0:
            return 0x64;

        case 1:
            return 0x32;

        case 2:
            return 0x32;

        case 3:
            return 0x19;

        case 4:
            return 0xA;

        case 6:
            return 0x64;

        case 7:
            return 0xA;

        default:
            return 0;
    }

}

// Maps an actor id to an item id.
int func_800D1B34(s32 actor_id)
{
    switch (actor_id) {
        case 0x29F:
            return 0x48;

        case 0x523:
            return 0x54;

        case 0x1D9:
            return 0x4F;

        case 0x3CA:
            return 0x4B;

        case 0x3CB:
            return 0x4C;

        case 0x40D:
        case 0x481:
            return 0x50;

        case 0x4E2:
            return 0x4D;

        case 0x4E3:
            return 0x4A;

        case 0x4E4:
            return 0x4E;

        case 0x4BA:
        case 0x4D7:
            return 0x51;

        case 0x515:
        case 0x516:
            return 0x52;

        case 0x4B7:
            return 0x49;

        default:
            return 0;
    }

}

s32 func_800D1C38(s32 item_id)
{
    s32 is_empty;
    is_empty = func_800D1A04(item_id) == 0;
    // Matching: `| 0` is needed for the match.
    return is_empty | 0;
}

s32 func_800D1C5C(u32 index)
{
    return (s32) *(s16 *) &D_8011AE50[index * 4];
}

s32 func_800D1C70()
{
    return 0x2A;
}

// Loads counts from a big-endian save blob.
void func_800D1C78(u8 *blob, u32 size)
{
    s32 i;
    s32 count;
    s32 value;
    func_800D1490();
    count = size >> 1;
    if (count > 21)
        count = 21;
    for (i = 0; i < count; i++) {
        value = (blob[i * 2] << 8) | blob[i * 2 + 1];
        D_8012B250.counts[i] = value ^ ((s16 *) &func_800D1A04)[i * 4];
    }
}

// Writes counts to a big-endian save blob.
void func_800D1DFC(u8 *blob)
{
    s32 i;
    for (i = 0; i < 21; i++) {
        blob[i * 2] =
            (D_8012B250.counts[i] ^ ((s16 *) &func_800D1A04)[i * 4]) >> 8 & 0xFF;
        blob[i * 2 + 1] =
            (D_8012B250.counts[i] ^ ((s16 *) &func_800D1A04)[i * 4]) & 0xFF;
    }
}

u32 func_800D1F34(s32 blob, s32 item_id)
{
    u32 offset;
    u32 size;
    if (_glgamedata_entrypoint_3(blob, 4, &offset, &size)) {
        item_id -= 0x40;

if ((s32) (size >> 1) < item_id) {
    return -1;
}
{
    u32 addr = (u32) blob + offset + (u32) item_id * 2;
    u32 result = ((u32) (*(u8 *) addr) << 8) | (*(u8 *) (addr + 1));
    return result;
}

}
return -1;
}

// TU-NOTE: the .data of this file is defined here in C, values taken from the ROM.
// Linker symbols (undefined_syms.us.txt): D_8011AE5B = D_8011AE50 + 0xB,
// D_8011AE76 = D_8011AE74 + 0x2, D_8011AF52 = D_8011AF50 + 0x2.
u8 D_8011AE50[11] = {0x3, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0};
static u32 D_8011AE50_rest[1] = {0x1020304};
u32 D_8011AE60[1] = {0x0};
u32 D_8011AE64[2] = {0x170001, 0xA0001};
u32 D_8011AE6C[2] = {0xB0001, 0x470001};
u32 D_8011AE74[4] = {0xB0001, 0x43FA0000, 0x443B8000, 0xFFFF9603};
u32 D_8011AE84[32] = {
    0x130001, 0x43FA0000, 0x443B8000, 0xFFFF9603, 0x140001, 0x43FA0000, 0x443B8000, 0xFFFF9603,
    0x170001, 0x43FA0000, 0x443B8000, 0xFFFF9603, 0x1F0001, 0x43FA0000, 0x443B8000, 0xFFFF9603,
    0x250001, 0x43FA0000, 0x443B8000, 0xFFFF9603, 0x2D0001, 0x43FA0000, 0x443B8000, 0xFFFF9603,
    0x3B0001, 0x43FA0000, 0x443B8000, 0xFFFF9603, 0x3E0001, 0x43FA0000, 0x443B8000, 0xFFFF9603};
u32 D_8011AF04[9] = {0x1F4, 0x250, 0x222, 0x23F, 0x2DB, 0x2FC, 0x44F, 0x13F, 0x50C};
u32 D_8011AF28[10] = {0x221, 0x2AA, 0x23B, 0x250, 0x2F4, 0x0, 0x0, 0x509, 0x510, 0x0};
u8 D_8011AF50[96] = {0x0, 0xD1, 0x0, 0x64, 0x0, 0xD2, 0x0, 0x32, 0x0, 0xD3, 0x0, 0x32, 0x0, 0xD4,
                     0x0, 0x19, 0x0, 0xD5, 0x0, 0xA,  0x1, 0x1A, 0x0, 0x0,  0x0, 0xD7, 0x0, 0x64,
                     0x0, 0xD8, 0x0, 0xA,  0x0, 0xD9, 0x0, 0x10, 0x0, 0xDA, 0x0, 0x19, 0x0, 0xDB,
                     0x0, 0x19, 0x0, 0xDC, 0x0, 0x5,  0x0, 0xDD, 0x0, 0x5,  0x0, 0xDE, 0x0, 0x4,
                     0x0, 0xDF, 0x0, 0x1E, 0x0, 0xE0, 0x0, 0x1,  0x0, 0xED, 0x0, 0x2,  0x1, 0x8,
                     0x0, 0x1,  0x1, 0x9,  0x0, 0x2,  0x1, 0xC,  0x0, 0x1,  0x1, 0xD,  0x0, 0x1,
                     0x0, 0x0,  0x0, 0x0,  0x0, 0x0,  0x0, 0x0,  0x0, 0x0,  0x0, 0x0};
