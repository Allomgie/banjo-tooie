#include "common.h"

// If the texture header has flag 0x100, copy it to a new heap block and load every listed
// texture asset (id + 0x1EF6) behind it. Returns the block, or 0.
u8 *dbtex_entrypoint_0(u8 *header)
{
    s32 *entry;
    s32 header_size;
    u8 *end;
    u8 *block;
    u8 *dst;
    if (header == 0) {
        return 0;
    }
    if (!(*(s16 *) ((char *) header + 6) & 0x100)) {
        return 0;
    }
    header_size = (*(s16 *) ((char *) header + 4) * 8) + 8;
    block = heap_alloc_sided(*(s32 *) ((char *) header + 0) + header_size, 1);
    rare_memcpy(block, header, header_size);
    entry = (s32 *) (block + 8);
    end = 8 + ((*(s16 *) ((char *) block + 4) * 8) + block);
    dst = end;
    if ((u32) entry < (u32) end) {
        do {
            func_800E6950(*entry + 0x1EF6, 0, dst);
            dst += func_800D5944();
            entry += 2;
        } while ((u32) entry < (u32) end);
    }
    return block;
}

// Free the block.
s32 dbtex_entrypoint_1(void *texture)
{
    if (texture != 0) {
        heap_free(texture);
    }
}
