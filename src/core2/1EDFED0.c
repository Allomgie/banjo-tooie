#include "common.h"

extern void *D_80136EE0;
extern s32 vector_defrag();
// Global actor array: a vector of 0x9C-byte actors. Each actor keeps its own
// index in the upper 11 bits of the u16 at +0x1A.
typedef struct {
    u8 pad0[0x1A];
    u16 index : 11;
    u16 unk_1A : 5;
} E_1066C0;
extern void vector_erase_unordered(void *, s32);
extern s32 vector_size();
extern E_1066C0 **vector_at();

typedef struct {
    u8 pad0[0x18];
    u16 unk_18;
    u16 index_bits;
} S_1069A4;

// Creates the actor array.
void func_801065E0()
{
    D_80136EE0 = vector_new(0x9C, 0x1E);
}

void func_80106608()
{
    vector_free(D_80136EE0);
    D_80136EE0 = 0;
}

void func_80106630()
{
    if ((s32) D_80136EE0 != 0) {
        D_80136EE0 = vector_defrag((s32) D_80136EE0);
    }
}

// Appends a zeroed actor; returns it and stores its index in *out_index.
s32 func_80106668(s32 *out_index)
{
    s32 actor;

    *out_index = 0;
    actor = vector_push_back((s32 *) &D_80136EE0);
    *out_index = vector_index_of((s32) D_80136EE0, actor);
    bzero(actor, 0x9C);
    return actor;
}

// Removes the actor at index by swapping in the last one, then fixes that actor's stored index.
void func_801066C0(s32 index)
{
    vector_erase_unordered(D_80136EE0, index);
    if (index < vector_size(D_80136EE0)) {
        (*vector_at(D_80136EE0, index))->index = index;
    }
}

// Returns the number of actors.
s32 func_80106730(void)
{
    if ((s32) D_80136EE0 == 0) {
        return 0;
    } else {
        return vector_size((s32) D_80136EE0);
    }
}

// Returns the actor at index.
s32 func_80106768(s32 index)
{
    // Matching: the extra copy is needed for the match.
    s32 i = index;
    vector_at((s32) D_80136EE0, i);
}

// Returns the actor a marker refers to (the marker stores the actor index).
void func_80106790(void *marker)
{
    vector_at(D_80136EE0, (u32) ((u16 *) marker)[13] >> 5, marker);
}

// Starts a reverse iteration: sets *cursor to the last index and returns that actor.
int func_801067C4(int *cursor)
{
    if ((int) D_80136EE0 == 0) {
        return 0;
    }
    cursor[0] = vector_size((int) D_80136EE0) - 1;
    if (cursor[0] >= 0) {
        return vector_at((int) D_80136EE0, cursor[0]);
    }
    return 0;
}

// Reverse iteration step; copes with actors removed meanwhile. Returns 0 at the end.
void *func_8010682C(s32 *cursor)
{
    s32 count;
    if (D_80136EE0 == 0) {
        return 0;
    }
    count = vector_size(D_80136EE0);
    if (*cursor >= count) {
        *cursor = count;
    }
    if (*cursor > 0) {
        *cursor = *cursor - 1;
        return vector_at(D_80136EE0, *cursor);
    }
    return 0;
}

// Round-robin: returns the actor at *cursor, wrapping to 0 if out of range.
int func_801068A8(s32 *cursor)
{
    s32 count;
    int index;
    if ((int) D_80136EE0 == 0) {
        return 0;
    }
    // Matching: `^ 0` needed for the match.
    count = vector_size((int) D_80136EE0 ^ 0, (int) D_80136EE0, cursor);
    if (count > 0) {
        index = *cursor;
        if ((index < 0) || (index >= count)) {
            *cursor = 0;
            index = 0;
        }
        return vector_at((int) D_80136EE0, index, cursor);
    }
    return 0;
}

// Reverse round-robin: steps *cursor back (wrapping to the last actor) and returns that actor.
void *func_80106920(s32 *cursor)
{
    s32 count;
    if (D_80136EE0 == 0) {
        return 0;
    }
    count = vector_size(D_80136EE0);
    *cursor = *cursor - 1;
    if ((*cursor < 0) || (*cursor >= count)) {
        *cursor = count - 1;
    }
    if (*cursor >= 0) {
        return vector_at(D_80136EE0, *cursor);
    }
    return 0;
}

// Returns whether the marker's actor index is within the array.
s32 func_801069A4(S_1069A4 *marker)
{
    s32 rv;
    if (D_80136EE0 == 0) {
        return 0;
    }
    if ((marker == 0) || ((marker->unk_18 & 1) == 0)) {
        return 0;
    }
    rv = (s32) ((u32) marker->index_bits >> 5) < vector_size(D_80136EE0);
    return rv;
}
