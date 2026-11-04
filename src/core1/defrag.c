// Heap defragmentation: moves a used block into an adjacent free block within a per-pass
// byte budget, skipping a pinned block, and returns the new address.
#include "types.h"
#include "memory.h"

// Bytes moved in the current pass (budget 1,000,000).
s32 D_8007C6F0;

// Block that must not be moved.
void *D_8007C6F4;

// Set when any block was moved.
s32 D_8007C6F8;

void func_8001B840(void)
{
    D_8007C6F0 = 0;
}

void func_8001B84C(void)
{
    D_8007C6F8 = FALSE;
}

s32 func_8001B858(void)
{
    return D_8007C6F8;
}

void func_8001B864(void *mem)
{
    D_8007C6F4 = mem;
}

void *defrag_next(void *mem)
{
    struct HeapHeader *cur_block;
    s32 block_size;
    struct HeapHeader *new_block;
    struct EmptyHeapBlock *prev_free;
    struct HeapHeader *next_block;
    struct EmptyHeapBlock *next_block_as_empty;
    struct HeapHeader *next_next;
    struct EmptyHeapBlock *next_free;
    struct EmptyHeapBlock *cur_block_as_empty;
    s32 stack_padding1; // Matching: unused local, needed for the stack frame.

    if (mem == D_8007C6F4) {
        return mem;
    }

    cur_block = GET_BLOCK_HEADER(mem);
    block_size = GET_BLOCK_TOTAL_SIZE(cur_block);
    if (D_8007C6F0 + block_size >= 1000000) {
        return mem;
    }

    // Only move if the next block is free and large enough
    next_block = cur_block->next;
    if (next_block->state != HEAP_BLOCK_STATE_EMPTY ||
        GET_BLOCK_TOTAL_SIZE(next_block) - sizeof(struct HeapHeader) < 0x74u) {
        return mem;
    }

    D_8007C6F8 = TRUE;
    D_8007C6F0 = D_8007C6F0 + block_size;

    // Remember the free block's neighbors before it is overwritten
    next_block_as_empty = (struct EmptyHeapBlock *) cur_block->next;
    next_next = next_block_as_empty->header.next;
    prev_free = next_block_as_empty->prev_free;
    next_free = next_block_as_empty->next_free;

    // Copy the block to the end of the free block
    new_block = (struct HeapHeader *) ((char *) next_next - block_size);

    aligned4_memmove(new_block, cur_block, block_size);

    new_block->prev = cur_block;
    cur_block->next = new_block;
    next_next->prev = new_block;
    new_block->next = next_next;

    // The old position becomes the free block
    cur_block_as_empty = (struct EmptyHeapBlock *) cur_block;
    prev_free->next_free = cur_block_as_empty;
    cur_block_as_empty->prev_free = prev_free;
    cur_block_as_empty->next_free = next_free;
    next_free->prev_free = cur_block_as_empty;

    cur_block_as_empty->header.state = HEAP_BLOCK_STATE_EMPTY;
    cur_block_as_empty->header.unkC_28 = FALSE;
    cur_block_as_empty->header.unkC_29 = FALSE;
    cur_block_as_empty->header.allocation_overhead = 0;

    // Matching: empty block, needed for the match.
    if (0) {
    }

    // Merge the freed block with adjacent free blocks
    heap_update_empty_block(cur_block);

    return (void *) ((char *) new_block + sizeof(struct HeapHeader));
}

void *defrag_prev(void *mem)
{
    struct HeapHeader *prev_block;
    struct EmptyHeapBlock *new_free_block;
    struct HeapHeader *cur_block;
    struct EmptyHeapBlock *prev_free;
    struct EmptyHeapBlock *next_free;
    void *prev_prev;
    s32 block_size;

    cur_block = GET_BLOCK_HEADER(mem);
    block_size = GET_BLOCK_TOTAL_SIZE(cur_block);
    if (D_8007C6F0 + block_size >= 1000000) {
        return mem;
    }

    // Only move if the previous block is free and large enough
    prev_block = cur_block->prev;
    if (prev_block->state != HEAP_BLOCK_STATE_EMPTY ||
        GET_BLOCK_TOTAL_SIZE(prev_block) - sizeof(struct HeapHeader) < 0x74) {
        return mem;
    }

    D_8007C6F8 = TRUE;
    D_8007C6F0 = D_8007C6F0 + block_size;

    // Remember the free block's neighbors before it is overwritten
    next_free = ((struct EmptyHeapBlock *) prev_block)->next_free;
    prev_free = ((struct EmptyHeapBlock *) prev_block)->prev_free;
    prev_prev = prev_block->prev;

    // Copy the block to the start of the free block
    aligned8_memcpy(prev_block, cur_block, block_size);

    // A new free block follows the moved block
    new_free_block = (struct EmptyHeapBlock *) ((char *) prev_block + block_size);

    new_free_block->header.prev = prev_block;
    new_free_block->header.next = prev_block->next;
    prev_block->next = &new_free_block->header;
    prev_block->prev = prev_prev;
    new_free_block->header.next->prev = &new_free_block->header;

    prev_free->next_free = new_free_block;
    next_free->prev_free = new_free_block;
    new_free_block->next_free = next_free;
    new_free_block->prev_free = prev_free;

    new_free_block->header.state = HEAP_BLOCK_STATE_EMPTY;
    new_free_block->header.unkC_28 = FALSE;
    new_free_block->header.unkC_29 = FALSE;
    new_free_block->header.allocation_overhead = 0;

    // Matching: empty block, needed for the match.
    if (0) {
    }

    // Merge the new free block with adjacent free blocks
    heap_update_empty_block(new_free_block);

    return GET_BLOCK_CONTENTS(prev_block);
}

// Moves a block into an adjacent free block depending on its side; returns the new address.
void *defrag(void *mem)
{
    switch (GET_BLOCK_HEADER(mem)->unkC_30) {
        case 0:
        case 2:
            return defrag_prev(mem);
        case 1:
            return defrag_next(mem);
        default:
            return mem;
    }
}

s32 is_prev_free(void *mem)
{
    s32 ret;

    if (mem == D_8007C6F4) {
        return FALSE;
    }

    if (GET_BLOCK_HEADER(mem)->prev->state != HEAP_BLOCK_STATE_EMPTY) {
        ret = FALSE;
    } else {
        ret = TRUE;
    }

    return ret;
}
