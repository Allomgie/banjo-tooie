// Heap-defrag helper for the map-model asset defrag in 1E97EF0: walks an array of
// {key, ptr} pairs sized by a companion asset.
#include "common.h"

// Defrags each non-null pointer in an array of {key, ptr} pairs, then the array itself.
int func_800F9F90(s32 *pairs, s32 *asset)
{
    s32 *end;
    s32 *pair;
    pair = pairs + 2;
    end = (s32 *) ((char *) pairs + (*(s32 *) ((char *) asset + 0x2C) * 8) + 8);
    while (pair < end) {
        if (*(s32 *) ((char *) pair + 4) != 0) {
            *(s32 *) ((char *) pair + 4) = defrag(*(s32 *) ((char *) pair + 4));
        }
        pair = (s32 *) ((char *) pair + 8);
    }

    return defrag(pairs);
}
