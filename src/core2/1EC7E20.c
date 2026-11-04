// Most likely heap-defrag glue for the idworld list D_80127EF8 (map-mesh effect entries of
// the id overlays), plus per-frame hooks that run the idbounce overlay while it is active.
#include "common.h"

extern void *D_80127EF8;
typedef void (*D_80123590Entry)(void *);
extern D_80123590Entry D_80123590[];
extern void *vector_begin();
extern void *vector_defrag(void *);
extern void *vector_end();
extern u8 D_80135483;

// Heap defrag and pointer fixup of the id-effect entries and the blocks they reference.
// Defrags the field at +0x2C of an idworld entry.
int func_800EE530(s32 *entry)
{
    *(s32 *) ((char *) entry + 44) = defrag(*(s32 *) ((char *) entry + 44));
}

// Defrags the block at +0x24 and re-bases the end pointer at +0x2C.
// Matching: the line breaks in this function are needed for the match.
void func_800EE55C(Actor *entry)
{
    unsigned long count;
    s32 old_start;
    s32 new_start;
    old_start = *(s32 *) ((char *) entry + 0x24); count = (s32) (*(s32 *) ((char *) entry + 0x2C) - old_start) >> 2;
    new_start = defrag(old_start);
    *(s32 *) ((char *) entry + 0x24) = new_start;
    *(s32 *) ((char *) entry + 0x2C) = (s32) (new_start + (count * 4));
}

// Defrags the field at +0x24 of an idworld entry.
int func_800EE5AC(s32 *entry)
{
    s32 *block;
    block = *(s32 **) ((char *) entry + 0x24);
    *(s32 **) ((char *) entry + 0x24) = defrag(block);
}

// Defrags a block and patches the matching references in the idworld entries.
s32 func_800EE5D8(s32 old_block)
{
    s32 defragged;
    int new_block;
    u8 *entries_end;
    u8 *entries_begin;
    u8 *entry;
    u8 *limit;
    defragged = defrag();
    // Matching: the do-while(0), the empty if and the extra variable are needed for the match.
    do {
        new_block = defragged;
        if (((s32 *) D_80127EF8 != 0) && (defragged != old_block)) {
            entries_end = vector_end((s32 *) D_80127EF8);
            entries_begin = vector_begin((s32 *) D_80127EF8);
            entry = entries_begin;
            if (entries_begin < (limit = entries_end)) {
                do {
                    if (entry) {
                    }
                    if (old_block == *(s32 *) entry) {
                        *(s32 *) entry = new_block;
                    }
                    entry += 0xA8;
                } while (entry < entries_end);
            }
        }
    } while (0);
    return new_block;
}

// Runs the per-type defrag routine for each idworld entry, then defrags the vector.
void func_800EE670(void)
{
    void (*defrag_fn)(void *);
    void *entries_end;
    void *entries_begin;
    void *entry;

    if (D_80127EF8 != 0) {
        entries_end = vector_end(D_80127EF8);
        entries_begin = vector_begin(D_80127EF8);
        entry = entries_begin;
        if (entries_begin < entries_end) {
            do {
                defrag_fn = D_80123590[*(u8 *) ((char *) entry + 6)];
                if (defrag_fn != NULL) {
                    defrag_fn((void *) ((char *) entry + 8));
                }
                entry = (void *) ((char *) entry + 0xA8);
            } while (entry < entries_end);
        }
        D_80127EF8 = vector_defrag(D_80127EF8);
    }
}

// Per-frame hooks into the idbounce map-mesh effect overlay while it is active.
// Per-frame hook: runs the idbounce overlay when D_80135483 is set.
int func_800EE718()
{
    if (D_80135483 != 0) {
        _idbounce_entrypoint_6();
    }
}

// Per-frame hook: runs the idbounce overlay when D_80135483 is set.
int func_800EE748()
{
    if (D_80135483 != 0) {
        _idbounce_entrypoint_7();
    }
}

// TU-NOTE: the .data of this file (formerly asm/data/core2/1EC7E20.data.s) is defined here in C.
// Its tables hold pointers to functions of this file; IDO's assembler schedules some of these
// functions differently unless the tables are defined in the same unit. Values are taken from the ROM.
D_80123590Entry D_80123590[16] = {0,
                                  0,
                                  0,
                                  0,
                                  0,
                                  0,
                                  0,
                                  0,
                                  0,
                                  0,
                                  0,
                                  (void *) func_800EE55C,
                                  (void *) func_800EE530,
                                  0,
                                  0,
                                  (void *) func_800EE5AC};
