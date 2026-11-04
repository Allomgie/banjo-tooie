#include "common.h"

extern s32 D_80127194[];
extern s32 defrag(s32);
extern void *heap_alloc(s32);
extern u8 *_gccollectDll_entrypoint_6(u8 *, s32 *);
extern u8 *_subaddiestore_entrypoint_0(u8 *, u8 *);
extern u8 *D_80127198[];
extern u8 *_gccollectDll_entrypoint_7();
extern void _subaddiestore_entrypoint_1();

// TU-NOTE: D_80127194[1..0x10A] holds one heap block per map 0xA0..0x1A9; D_80127198[slot] is the
// same table accessed with slot = map - 0xA0.

// Clears the table.
void cosectionstor_entrypoint_0(void)
{
    s32 i;

    for (i = 1; i < 0x10B; i++) {
        D_80127194[i] = 0;
    }
}

// Frees all blocks.
void cosectionstor_entrypoint_1(void)
{
    s32 i;
    for (i = 1; i < 0x10B; i++) {
        if (D_80127194[i] != 0) {
            heap_free(D_80127194[i]);
            D_80127194[i] = 0;
        }
    }
}

// Defragments all blocks.
void cosectionstor_entrypoint_2(void)
{
    s32 i;
    for (i = 1; i < 0x10B; i++) {
        if (D_80127194[i] != 0) {
            D_80127194[i] = defrag(D_80127194[i]);
        }
    }
}

// On map exit: saves the game flags, collectible state and actor snapshot into the map's block.
// map_id becomes the slot index (map - 0xA0).
void cosectionstor_entrypoint_3(s32 map_id)
{
    u32 block_words;
    s32 bit_pos = 0;
    u32 *flags_ptr;
    s32 word_pos;

    if (map_id >= 0xA0) {
        map_id -= 0xA0;
        func_800FF44C(map_id);
        if (D_80127198[map_id]) {
            heap_free(D_80127198[map_id]);
        }
        block_words = 4;
        D_80127198[map_id] = heap_alloc(block_words * sizeof(u32));
        // Matching: empty block, so flags_ptr is reloaded from D_80127198 (uses up the temp the original uses).
        if (1) {
        }
        flags_ptr = (u32 *) D_80127198[map_id];
        *flags_ptr = func_800DAA1C();
        bit_pos += 8 * sizeof(u32);
        word_pos = bit_pos >> 5;
        D_80127198[map_id] = _gccollectDll_entrypoint_6(D_80127198[map_id], &word_pos);
        D_80127198[map_id] = _subaddiestore_entrypoint_0(
            D_80127198[map_id],
            (u8 *) ((s32 *) D_80127198[map_id] + (((word_pos << 5) + 0x7F) >> 7) * 4));
    }
}

// On map start: restores the saved state and frees the map's block.
// map_id becomes the slot index (map - 0xA0).
void cosectionstor_entrypoint_4(s32 map_id)
{
    s32 bit_pos = 0;
    u32 *flags_ptr;
    s32 word_pos;

    if (map_id >= 0xA0) {
        map_id -= 0xA0;
        if (*(s32 *) &D_80127198[map_id]) {
            flags_ptr = (u32 *) D_80127198[map_id];
            func_800DAA28(*flags_ptr);
            bit_pos += 8 * sizeof(u32);
            word_pos = bit_pos >> 5;
            D_80127198[map_id] = _gccollectDll_entrypoint_7(D_80127198[map_id], &word_pos);
            _subaddiestore_entrypoint_1(
                D_80127198[map_id],
                (u8 *) ((s32 *) D_80127198[map_id] + (((word_pos << 5) + 0x7F) >> 7) * 4));
            heap_free(D_80127198[map_id]);
            D_80127198[map_id] = NULL;
        }
    }
}
