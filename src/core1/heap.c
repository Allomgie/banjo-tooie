#include "core1/heap.h"
#include "memory.h"

void *func_8001C0A0(s32);
void func_8001B864(void *);
void heap_merge_free_block(struct EmptyHeapBlock *block);

extern s32 D_8003F750;
extern s32 D_8007BF00;

s32 func_8001A6C0(s32 arg0, s32 size)
{
    func_8001E5DC(5);
    return 0;
}

void heap_update_empty_block(struct EmptyHeapBlock *block)
{
    struct EmptyHeapBlock *to_merge = NULL;

    if (block->header.next->state == HEAP_BLOCK_STATE_EMPTY) {
        struct EmptyHeapBlock *next_block = AS_EMPTY_BLOCK(block->header.next);
        to_merge = block;
        next_block->next_free->prev_free = next_block->prev_free;
        next_block->prev_free->next_free = next_block->next_free;
        next_block->header.next->prev = &block->header;
        block->header.next = next_block->header.next;
    }

    if (block->header.prev->state == HEAP_BLOCK_STATE_EMPTY) {
        to_merge = AS_EMPTY_BLOCK(block->header.prev);
        block->next_free->prev_free = block->prev_free;
        block->prev_free->next_free = block->next_free;
        block->header.prev->next = block->header.next;
        block->header.next->prev = block->header.prev;
    }

    if (to_merge != NULL) {
        heap_merge_free_block(to_merge);
        return;
    }

    heap_merge_free_block(block);
}

void heap_init_empty_block(struct HeapHeader *block)
{
    struct EmptyHeapBlock *block_as_empty = AS_EMPTY_BLOCK(block);
    block->state = HEAP_BLOCK_STATE_EMPTY;
    block->unkC_28 = 0;
    block->unkC_29 = 0;
    block->unkC_30 = 0;
    block->allocation_overhead = 0;

    if (GET_BLOCK_TOTAL_SIZE(block) < 10000) {
        block_as_empty->prev_free = FIRST_BLOCK();
        block_as_empty->next_free = FIRST_BLOCK()->next_free;
        FIRST_BLOCK()->next_free->prev_free = block_as_empty;
        FIRST_BLOCK()->next_free = block_as_empty;
    } else {
        block_as_empty->prev_free = LAST_BLOCK()->prev_free;
        block_as_empty->next_free = LAST_BLOCK();
        LAST_BLOCK()->prev_free->next_free = block_as_empty;
        LAST_BLOCK()->prev_free = block_as_empty;
    }

    heap_update_empty_block(block_as_empty);
}

void heap_setup(s32 zero_contents)
{
    D_8007BF00 = func_8001E830();
    if (zero_contents != 0) {
        bzero(D_8007E990, D_8007BF00);
        osWritebackDCacheAll();
    }
    D_8003F750 = 0;

    FIRST_BLOCK()->header.prev = NULL;
    FIRST_BLOCK()->header.next = &INITIAL_BLOCK()->header;
    FIRST_BLOCK()->header.state = HEAP_BLOCK_STATE_PERM;
    FIRST_BLOCK()->header.allocation_overhead = 0;
    FIRST_BLOCK()->prev_free = NULL;
    FIRST_BLOCK()->next_free = INITIAL_BLOCK();
    FIRST_BLOCK()->header.unkC_28 = 0;
    FIRST_BLOCK()->header.unkC_29 = 0;

    INITIAL_BLOCK()->header.prev = &FIRST_BLOCK()->header;
    INITIAL_BLOCK()->header.next = &LAST_BLOCK()->header;
    INITIAL_BLOCK()->header.state = HEAP_BLOCK_STATE_EMPTY;
    INITIAL_BLOCK()->header.allocation_overhead = 0;
    INITIAL_BLOCK()->prev_free = FIRST_BLOCK();
    INITIAL_BLOCK()->next_free = LAST_BLOCK();
    INITIAL_BLOCK()->header.unkC_28 = 0;
    INITIAL_BLOCK()->header.unkC_29 = 0;

    LAST_BLOCK()->header.prev = &INITIAL_BLOCK()->header;
    LAST_BLOCK()->header.next = &TERMINATOR_BLOCK()->header;
    LAST_BLOCK()->header.state = HEAP_BLOCK_STATE_PERM;
    LAST_BLOCK()->header.allocation_overhead = 0;
    LAST_BLOCK()->prev_free = INITIAL_BLOCK();
    LAST_BLOCK()->next_free = NULL;
    LAST_BLOCK()->header.unkC_28 = 0;
    LAST_BLOCK()->header.unkC_29 = 0;

    func_8001B4B0();
}

s32 heap_bytes_used()
{
    return D_8003F750;
}

struct EmptyHeapBlock *find_free_block(s32 size, s32 alloc_type)
{
    struct EmptyHeapBlock *cur_block;
    struct EmptyHeapBlock *found_block;

    switch (alloc_type) {
        case 1:
            // Find the last free block that can hold the given size
            found_block = NULL;
            cur_block = FIRST_BLOCK()->next_free;

            while (cur_block != LAST_BLOCK()) {
                if (BLOCK_CAN_HOLD(&cur_block->header, size) && (found_block < cur_block)) {
                    found_block = cur_block;
                }
                cur_block = cur_block->next_free;
            }

            if (found_block == NULL) {
                return NULL;
            }

            if (!BLOCK_CAN_HOLD(&found_block->header, size)) {
                return NULL;
            }

            return found_block;
        case 0:
            // Find the first free block that can hold the given size
            cur_block = FIRST_BLOCK()->next_free;

            // Stop at the end of the heap if none fits
            while (!BLOCK_CAN_HOLD(&cur_block->header, size) &&
                   cur_block->next_free != LAST_BLOCK()) {
                cur_block = cur_block->next_free;
            }

            if (!BLOCK_CAN_HOLD(&cur_block->header, size)) {
                return NULL;
            }

            return cur_block;
        case 2:
            return func_8001C0A0(size);
        default:
            // Invalid alloc type
            return NULL;
    }
}

s32 has_free_block_after(s32 size)
{
    return find_free_block(size, 0) != NULL ? TRUE : FALSE;
}

void *heap_alloc(s32 size)
{
    return heap_alloc_sided(size, 0);
}

void *heap_alloc_sided(s32 size, s32 alloc_side)
{
    s32 block_size;
    u32 alloc_size;
    struct EmptyHeapBlock *cur_block;
    struct EmptyHeapBlock *new_block;

    if (FIRST_BLOCK()->next_free == LAST_BLOCK()) {
        func_8001A6C0(1, size);
    }

    // Align the size and prevent 0-byte allocations
    alloc_size = func_8001BD30(size > 0 ? size : 1);

    // Try to find a free block on the given side
    cur_block = find_free_block(size, alloc_side);

    if (cur_block == NULL) {
        alloc_side = 0;
        if (func_800A9D90(size) == 0) {
            func_8001A6C0(1, size);
            return NULL;
        }
        cur_block = find_free_block(size, alloc_side);
    }

    if (alloc_size + sizeof(struct HeapHeader) < GET_BLOCK_MEM_SIZE(&cur_block->header)) {
        if (alloc_side == 1) {
            // Split off the allocation at the end of the free block
            new_block = cur_block;
            cur_block = (struct EmptyHeapBlock *) ((char *) new_block->header.next - alloc_size -
                                                   sizeof(struct HeapHeader));
            cur_block->header.next = new_block->header.next;
            new_block->header.next->prev = &cur_block->header;
            new_block->header.next = &cur_block->header;
            cur_block->header.prev = &new_block->header;
            heap_merge_free_block(new_block);
        } else {
            // Create a new free block after the allocation
            new_block = (struct EmptyHeapBlock *) ((char *) cur_block + alloc_size +
                                                   sizeof(struct HeapHeader));
            // Free list links
            new_block->next_free = cur_block->next_free;
            new_block->prev_free = cur_block->prev_free;
            new_block->next_free->prev_free = new_block;
            new_block->prev_free->next_free = new_block;
            // Block list links
            new_block->header.prev = &cur_block->header;
            new_block->header.next = cur_block->header.next;
            new_block->header.next->prev = &new_block->header;
            new_block->header.state = HEAP_BLOCK_STATE_EMPTY;
            new_block->header.unkC_28 = 0;
            new_block->header.unkC_29 = 0;
            new_block->header.allocation_overhead = 0;
            cur_block->header.next = &new_block->header;
            heap_merge_free_block(new_block);
        }
    } else {
        // Use the whole block: remove it from the free list
        cur_block->next_free->prev_free = cur_block->prev_free;
        cur_block->prev_free->next_free = cur_block->next_free;
    }
    block_size = GET_BLOCK_TOTAL_SIZE(&cur_block->header);
    cur_block->header.allocation_overhead = block_size - size - sizeof(struct HeapHeader);
    cur_block->header.state = HEAP_BLOCK_STATE_USED;
    cur_block->header.unkC_28 = 0;
    cur_block->header.unkC_29 = 0;
    cur_block->header.unkC_30 = alloc_side;
    D_8003F750 += block_size;
    return GET_BLOCK_CONTENTS(cur_block);
}

void heap_merge_free_block(struct EmptyHeapBlock *block)
{
    struct EmptyHeapBlock *cur_block = block;

    while (cur_block->next_free < LAST_BLOCK() &&
           GET_BLOCK_TOTAL_SIZE(&cur_block->next_free->header) <
               GET_BLOCK_TOTAL_SIZE(&cur_block->header)) {
        struct EmptyHeapBlock *next = cur_block->next_free;
        cur_block->next_free = next->next_free;
        next->next_free->prev_free = cur_block;
        next->next_free = cur_block;
        cur_block->prev_free->next_free = next;
        next->prev_free = cur_block->prev_free;
        cur_block->prev_free = next;
    }

    while (FIRST_BLOCK() < cur_block->prev_free &&
           GET_BLOCK_TOTAL_SIZE(&cur_block->header) <
               GET_BLOCK_TOTAL_SIZE(&cur_block->prev_free->header)) {
        struct EmptyHeapBlock *prev = cur_block->prev_free;
        cur_block->next_free->prev_free = prev;
        prev->next_free = cur_block->next_free;
        cur_block->next_free = prev;
        cur_block->prev_free = prev->prev_free;
        prev->prev_free->next_free = cur_block;
        prev->prev_free = cur_block;
    }
}

void heap_free(void *mem)
{
    if (mem != NULL) {
        D_8003F750 -= GET_BLOCK_TOTAL_SIZE(GET_BLOCK_HEADER(mem));
        heap_init_empty_block(GET_BLOCK_HEADER(mem));
    }
}

void heap_resize_block_internal(struct HeapHeader *block, s32 new_size)
{
    struct HeapHeader *new_block;
    u32 size_delta;
    s32 offset;

    // Update the overhead byte count
    block->allocation_overhead = GET_BLOCK_MEM_SIZE(block) - new_size;

    // Bytes the block shrinks by (sizes are aligned to 0x10, minimum 0x10)
    if (new_size > 0) {
        size_delta = GET_BLOCK_MEM_SIZE(block) - func_8001BD30(new_size);
    } else {
        size_delta = GET_BLOCK_MEM_SIZE(block) - 0x10;
    }

    // Offset to the start of the new block
    offset = GET_BLOCK_TOTAL_SIZE(block);
    offset -= size_delta;

    // Only split if the freed space can hold a free block
    if (size_delta >= sizeof(struct EmptyHeapBlock)) {
        new_block = (struct HeapHeader *) ((char *) block + offset);

        D_8003F750 -= size_delta;

        // Link the new block into the block list
        new_block->prev = block;
        new_block->next = block->next;
        block->next = new_block;
        new_block->next->prev = new_block;

        block->allocation_overhead = GET_BLOCK_MEM_SIZE(block) - new_size;

        heap_init_empty_block(new_block);
    }
}

void heap_resize_block(struct HeapHeader *block, s32 new_size)
{
    heap_resize_block_internal(block, new_size);
    if (block->next->state == HEAP_BLOCK_STATE_EMPTY) {
        heap_merge_free_block((struct EmptyHeapBlock *) block->next);
    }
}

void *heap_realloc(void *mem, s32 size)
{
    struct HeapHeader *cur_block;
    void *new_mem;

    // Resize in place if the block already holds the new size
    cur_block = GET_BLOCK_HEADER(mem);
    if (GET_BLOCK_MEM_SIZE(cur_block) >= size) {
        heap_resize_block(cur_block, size);
        return mem;
    }

    // Pin this block
    func_8001B864(mem);

    // Grow in place if the next block is free and merging it fits the size
    if (cur_block->next->state == 0 &&
        (char *) cur_block->next->next - (char *) cur_block - sizeof(struct HeapHeader) >= size) {
        new_mem = cur_block->next;

        // Remove the next block from the free list
        AS_EMPTY_BLOCK(new_mem)->next_free->prev_free = AS_EMPTY_BLOCK(new_mem)->prev_free;
        AS_EMPTY_BLOCK(new_mem)->prev_free->next_free = AS_EMPTY_BLOCK(new_mem)->next_free;

        D_8003F750 += GET_BLOCK_TOTAL_SIZE(&AS_EMPTY_BLOCK(new_mem)->header);

        // Remove the next block from the block list
        cur_block->next = AS_EMPTY_BLOCK(new_mem)->header.next;
        AS_EMPTY_BLOCK(new_mem)->header.next->prev = cur_block;

        heap_resize_block(cur_block, size);

        // Unpin
        func_8001B864(NULL);
        return mem;
    }

    // Otherwise move to new memory
    new_mem = heap_alloc(size);
    if (new_mem == NULL) {
        return NULL;
    }

    // Copy the flags from the original block
    GET_BLOCK_HEADER(new_mem)->unkC_28 = cur_block->unkC_28;
    GET_BLOCK_HEADER(new_mem)->unkC_29 = cur_block->unkC_29;

    aligned8_memcpy(new_mem, mem, func_8001BD30(size));

    // Free the original block and unpin
    heap_free(mem);
    func_8001B864(NULL);
    return new_mem;
}

s32 heap_get_allocation_size(void *mem)
{
    struct HeapHeader *block = GET_BLOCK_HEADER(mem);
    return GET_BLOCK_MEM_SIZE(block) - block->allocation_overhead;
}

// Sets header flag unkC_29 (used for movable handle blocks).
void func_8001B3A0(void *mem)
{
    struct HeapHeader *block = GET_BLOCK_HEADER(mem);
    block->unkC_29 = 1;
}

// Sets header flag unkC_28.
void func_8001B3B0(void *mem)
{
    struct HeapHeader *block = GET_BLOCK_HEADER(mem);
    block->unkC_28 = 1;
}

s32 heap_bytes_free()
{
    return D_8007BF00 - heap_bytes_used();
}

s32 heap_bytes_allocated()
{
    return D_8007BF00;
}

// Returns the number of free blocks; the largest size goes to *size_out.
s32 heap_largest_free(s32 *size_out)
{
    s32 block_count;
    struct EmptyHeapBlock *cur_block;

    cur_block = FIRST_BLOCK()->next_free;

    *size_out = 0;
    block_count = 0;

    while (cur_block != LAST_BLOCK()) {
        block_count++;
        *size_out = MAX(*size_out, GET_BLOCK_TOTAL_SIZE(&cur_block->header));
        cur_block = cur_block->next_free;
    }

    return block_count;
}

// TU-NOTE: the .data of this file (formerly heap.data.s) is defined here in C, values from the ROM.
s32 D_8003F750 = 0x0;
