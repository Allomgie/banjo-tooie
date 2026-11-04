// libultra alHeapInit / alHeapDBAlloc: bump allocator for the audio heap, 16-byte rounded.
#include "common.h"
#ifndef M2C_MACROS_H
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr) ((s8 *) (expr) + (offset)))
#endif

typedef struct {
    u8 *base;
    u8 *cur;
    s32 len;
    s32 count;
} TTHeap;

// alHeapInit: sets up the bump allocator (base, len, cur = base, count = 0).
void func_80020EC0(u8 *heap, s32 base, s32 len)
{
    M2C_FIELD(heap, s32 *, 0) = base;
    M2C_FIELD(heap, s32 *, 8) = len;
    M2C_FIELD(heap, s32 *, 4) = (s32) M2C_FIELD(heap, s32 *, 0);
    M2C_FIELD(heap, s32 *, 0xC) = 0;
}

// alHeapDBAlloc: bump-allocates num * size bytes rounded up to 16; returns NULL when exhausted.
void *func_80020EE4(u8 *file, s32 line, TTHeap *hp, s32 num, s32 size)
{
    s32 bytes;
    u8 *ptr = 0;

    bytes = (num * size + 0xF) & ~0xF;

    if ((hp->cur + bytes) <= (hp->base + hp->len)) {
        ptr = hp->cur;
        hp->cur += bytes;
    } else {
    }

    return ptr;
}
