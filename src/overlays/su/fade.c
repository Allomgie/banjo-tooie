#include "common.h"

extern s32 D_80127EF4;

// Queues a full-screen flash: color points to r, g, b (s32 each).
void sufade_entrypoint_0(s32 alpha, u8 *color)
{
    u8 *entry;
    if ((void *) D_80127EF4 == 0) {
        D_80127EF4 = vector_new(4, 1, color);
    }
    entry = vector_push_back((void **) &D_80127EF4);
    *(s8 *) ((s8 *) entry + 0) = (s8) *(s32 *) ((s8 *) color + 0);
    *(s8 *) ((s8 *) entry + 1) = (s8) *(s32 *) ((s8 *) color + 4);
    *(s8 *) ((s8 *) entry + 2) = (s8) *(s32 *) ((s8 *) color + 8);
    *(s8 *) ((s8 *) entry + 3) = (s8) alpha;
    // Matching: empty blocks needed for the match.
    if (!(void *) D_80127EF4) {
    }
    if (0) {
    }
}

// TU-NOTE: this .bss object is defined here, ahead of its first use; IDO places .bss objects used before their definition first.
s32 B_80800160_sufade;

// Draws every queued flash, then clears the queue.
void sufade_entrypoint_1(s32 unk_0)
{
    u32 end;
    u32 cur;

    cur = vector_begin(D_80127EF4);
    end = vector_end(D_80127EF4);
    if (cur < end) {
        do {
            *(s32 *) ((s8 *) &B_80800160_sufade + 0) = (s32) *(u8 *) ((s8 *) cur + 0);
            *(s32 *) ((s8 *) &B_80800160_sufade + 4) = (s32) *(u8 *) ((s8 *) cur + 1);
            *(s32 *) ((s8 *) &B_80800160_sufade + 8) = (s32) *(u8 *) ((s8 *) cur + 2);
            func_800B99CC(unk_0, *(u8 *) ((s8 *) cur + 3), &B_80800160_sufade);
            cur += 4;
        } while (cur < end);
    }
    vector_clear(D_80127EF4);
}

// Frees the flash queue.
s32 sufade_entrypoint_2(void)
{
    if (D_80127EF4 != 0) {
        vector_free(D_80127EF4);
        D_80127EF4 = 0;
    }
}
