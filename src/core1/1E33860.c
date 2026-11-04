// Main heap inspection and free-block search helpers: fragmentation test, free-chain walk and
// first-fit searches over the block list.
#include "memory.h"

extern int heap_largest_free();
extern int heap_bytes_free();

struct HeapBlock_8001BDAC {
    struct HeapBlock_8001BDAC *prev;
    struct HeapBlock_8001BDAC *next;
    int unk_8;
    int unk_C;
    struct HeapBlock_8001BDAC *prev_free;
};
struct HeapHeader_8001BE94 {
    struct HeapHeader_8001BE94 *prev;
    struct HeapHeader_8001BE94 *next;
    int unk_8;
    unsigned int allocation_overhead : 24;
    unsigned int state : 2;
    unsigned int unk_C_26 : 2;
    unsigned int unk_C_28 : 1;
    unsigned int unk_C_29 : 1;
    unsigned int unk_C_30 : 2;
};
typedef struct Struct8001BF80 Struct8001BF80;
struct Struct8001BF80 {
    Struct8001BF80 *prev;
    Struct8001BF80 *next;
    signed int unk_8;
    unsigned int unk_C;
    Struct8001BF80 *prev_free;
    Struct8001BF80 *next_free;
    long long unk_18;
};
typedef struct Struct8001C0A0 Struct8001C0A0;

struct Struct8001C0A0 {
    Struct8001C0A0 *prev;
    Struct8001C0A0 *next;
    signed int unk_8;
    unsigned int allocation_overhead : 24;
    unsigned int state : 2;
    unsigned int unk_C_26 : 6;
};

// Rounds up to a multiple of 16.
u32 func_8001BD30(u32 value)
{
    return (value & 0xF) ? (value - (value & 0xF) + 0x10) : value;
}

// Fragmentation test: largest free block is smaller than the given fraction of all free bytes.
int func_8001BD50(float fraction)
{
    int largest;
    heap_largest_free(&largest);

    return largest < fraction * heap_bytes_free();
}

// Walks the free-block chain backwards from the end sentinel by `count` blocks.
// Returns the block body (size in *out_size), or 0 at the start of the heap.
int func_8001BDAC(int *out_size, int count)
{
    struct HeapBlock_8001BDAC *block;

    block = (struct HeapBlock_8001BDAC *) (D_8007E990 + heap_bytes_allocated() - 0x20);
    for (; count != 0; count--) {
        block = block->prev_free;
        if (block == (struct HeapBlock_8001BDAC *) D_8007E990) {
            return 0;
        }
    }

    *out_size = (char *) block->next - (char *) block - 0x10;
    return (int) ((char *) block + 0x10);
}

// First-fit search walking backwards by prev from the end; returns a free block or 0.
signed int func_8001BE94(signed int size)
{
    struct HeapHeader_8001BE94 *block;
    signed int unk_0;
    unsigned int aligned_size;
    signed int req_size;
    block = *(struct HeapHeader_8001BE94 **) ((D_8007E990 + heap_bytes_allocated()) - 0x20);
    if (size > 0) {
        req_size = size;
    } else {
        req_size = 1;
    }
    aligned_size = func_8001BD30(req_size);
    if (((unsigned int) (((char *) block->next - (char *) block) - 0x10) < aligned_size) ||
        (block->state != 0)) {
        unk_0 = (signed int) D_8007E990;
        while ((signed int) block->prev != unk_0) {
            block = block->prev;
            if (((unsigned int) (((char *) block->next - (char *) block) - 0x10) >= aligned_size) &&
                (block->state == 0)) {
                break;
            }
        }
    }
    if (block->state != 0) {
        return 0;
    }
    if ((unk_0 = (unsigned int) (((char *) block->next - (char *) block) - 0x10)) < aligned_size) {
        return 0;
    }
    return (signed int) block;
}

// First-fit search along the free-list link (+0x14); returns a block or 0.
signed int func_8001BF80(size) signed int size;
{
    Struct8001BF80 *block;
    unsigned int aligned_size;
    signed int tmp;

    block = ((Struct8001BF80 *) D_8007E990)->next_free;
    if (size > 0) {
        tmp = size;
    } else {
        tmp = 1;
    }
    aligned_size = func_8001BD30(tmp);
    if ((unsigned int) ((char *) block->next - (char *) block - 0x10) < aligned_size) {
        while ((char *) block->next_free + 0x20 != D_8007E990 + heap_bytes_allocated()) {
            block = block->next_free;
            if ((unsigned int) ((char *) block->next - (char *) block - 0x10) >= aligned_size) {
                break;
            }
        }
    }
    tmp = (unsigned int) ((char *) block->next - (char *) block - 0x10) < aligned_size
              ? 0
              : (signed int) block;
    return tmp;
}

int func_8001C070()
{
    int found;
    if (func_8001BF80()) {
        found = 1;
    } else {
        found = 0;
    }
    return found | 0; // Matching: the `| 0` is needed for the match.
}

// First-fit search forward by next over blocks with state 0; returns a block or 0.
Struct8001C0A0 *func_8001C0A0(signed int size)
{
    Struct8001C0A0 *block;
    unsigned int aligned_size;
    signed int req_size;

    block = ((Struct8001C0A0 *) D_8007E990)->next;
    if (size > 0) {
        req_size = size;
    } else {
        req_size = 1;
    }
    aligned_size = func_8001BD30(req_size);
    if ((unsigned int) ((char *) block->next - (char *) block - 0x10) < aligned_size ||
        block->state != 0) {
        while ((char *) block->next + 0x20 != D_8007E990 + heap_bytes_allocated()) {
            block = block->next;
            if ((unsigned int) ((char *) block->next - (char *) block - 0x10) >= aligned_size &&
                block->state == 0) {
                break;
            }
        }
    }
    if (block->state != 0) {
        return 0;
    }
    if ((unsigned int) ((char *) block->next - (char *) block - 0x10) < aligned_size) {
        return 0;
    }
    return block;
}
