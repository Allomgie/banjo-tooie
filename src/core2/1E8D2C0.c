// Run pool: stores many small variable-length arrays in one heap block, with push, remove,
// compaction and tail shrinking.
#include "common.h"

// TU-NOTE: run_pool. One heap block {s16 element_size, s16 capacity, s16 free_head}
// followed by elements. Free runs are linked as {s16 next, s16 size}; user handles
// are {s16 start, s16 count}.
struct OSIoMesgHdr {
    s16 next;
    s16 size;
    OSMesgQueue *unk_4;
};
typedef struct {
    s16 unk_0, unk_2;
} BlockLink;
typedef struct {
    s16 element_size, capacity, free_head;
} LocalHeap;
typedef struct {
    s16 next, size;
} LocalBlock;
typedef struct {
    s16 start, count;
} LocalHandle;
typedef struct {
    s16 start;
    s16 count;
} local_9;

// Pointer to element `index`: base + 4 + index * element_size.
LocalBlock *func_800B39D0(s16 *pool, s32 index)
{
    // Matching: the comma expression is needed for the match.
    return ((u8 *) pool + (index * pool[0])) + (0, 4);
}

// Reset the pool to a single free run covering all elements.
void func_800B39E8(u8 *pool)
{
    s16 *link;
    *(s16 *) (pool + 6) = 0;
    link = (s16 *) (pool + 4);
    if (*(s16 *) (pool + 2) != 0) {
        *link = 1;
        link = func_800B39D0(pool, *link);
        *link = 0;
        link[1] = *(s16 *) (pool + 2) - 1;
    } else {
        *link = 0;
    }
}

// Insert the free run [start, start + count) after `prev`, merging with neighbours.
void func_800B3A40(OSMesgQueue *pool, struct OSIoMesgHdr *prev, s32 start, s32 count)
{
    struct OSIoMesgHdr *run;
    struct OSIoMesgHdr *other;
    run = func_800B39D0(pool, start);
    if (prev->next == (start + count)) {
        other = func_800B39D0(pool, prev->next);
        run->next = other->next;
        run->size = other->size + count;
    } else {
        run->next = prev->next;
        run->size = count;
    }
    other = func_800B39D0(pool, start - prev->size);
    if (other == prev) {
        prev->size += run->size;
        prev->next = run->next;
    } else {
        prev->next = start;
    }
}

// Return the elements [start, start + count) to the free list.
void func_800B3B08(s16 *base, s32 start, s32 count)
{
    s16 *prev;
    s16 *pool;
    s32 end_index;
    pool = base;
    prev = pool + 2;
    if (prev[0] == 0) {
        goto end;
    }
    end_index = (s32) start + count;
    while (1) {
        if (prev[0] >= end_index) {
            break;
        }
        prev = func_800B39D0(pool, prev[0]);
        if (prev[0] == 0) {
            break;
        }
    }

end:
    func_800B3A40(pool, prev, start, count);
}

// Take the first `count` elements of `run`; the remainder becomes the new run at *link.
void func_800B3B8C(u8 *pool, s16 *run, s16 *link, s32 count)
{
    u8 *rest;

    *link += count;
    rest = func_800B39D0(pool, *link);
    *(s16 *) rest = *run;
    *(s16 *) (rest + 2) = run[1] - count;
}

// Take the first element of the free run at *link.
u8 *func_800B3BDC(s32 pool, s16 *link)
{
    u8 *run;

    run = func_800B39D0(pool, *link);
    if (*(s16 *) ((s8 *) run + 2) == 1) {
        *link = *(s16 *) ((s8 *) run + 0);
    } else {
        func_800B3B8C(pool, run, link, 1);
    }
    return run;
}

// Grow the pool by `grow` elements; the new tail becomes a free run linked after `prev`.
BlockLink *func_800B3C40(BlockLink **pool_ptr, s32 prev, s32 grow)
{
    BlockLink *pool;
    s32 old_capacity;
    BlockLink *tail;
    s32 new_capacity;
    BlockLink *link;
    pool = *pool_ptr;
    old_capacity = pool->unk_2;
    new_capacity = old_capacity + grow;
    pool = heap_realloc(pool, pool->unk_0 * new_capacity + 4);
    pool->unk_2 = new_capacity;
    *pool_ptr = pool;
    link = func_800B39D0(pool, prev);
    link->unk_0 = old_capacity;
    tail = func_800B39D0(pool, link->unk_0);
    tail->unk_0 = 0;
    tail->unk_2 = grow;
    return link;
}

// Append one element to the handle's run and return it. Grows the run in place when
// the next element is free, otherwise moves the run (growing the pool if needed).
void *func_800B3CDC(LocalHeap **pool_ptr, LocalHandle *handle)
{
    s16 *link;
    s32 unk_0;
    LocalHeap *pool;
    s32 prev_index;
    LocalBlock *result;
    LocalBlock *new_run;
    s32 old_start;
    LocalBlock *old_run;

    pool = *pool_ptr;
    result = 0;
    link = &pool->free_head;
    if (!*link) {
        link = func_800B3C40(pool_ptr, 0, 10);
        pool = *pool_ptr;
    }
    if (handle->start == 0) {
        handle->start = *link;
        result = func_800B3BDC(pool, link);
    } else {
        unk_0 = handle->start + handle->count;
        while (*link) {
            if (*link == unk_0)
                break;
            link = &func_800B39D0(pool, *link)->next;
        }
        if (*link)
            result = func_800B3BDC(pool, link);
        else {
            unk_0 = handle->count + 1;
            old_start = handle->start;
            prev_index = 0;
            link = &pool->free_head;
            while (*link) {
                result = func_800B39D0(pool, *link);
                if (result->size >= unk_0)
                    break;
                prev_index = *link;
                link = &result->next;
            }
            if (!result || result->size < unk_0) {
                link = func_800B3C40(pool_ptr, prev_index, unk_0 + 5);
                pool = *pool_ptr;
            }
            new_run = func_800B39D0(pool, *link);
            old_run = func_800B39D0(pool, handle->start);
            handle->start = *link;
            func_800B3B8C(pool, new_run, link, handle->count);
            aligned4_memcpy(new_run, old_run, handle->count * pool->element_size);
            result = func_800B3BDC(pool, link);
            func_800B3B08(pool, old_start, handle->count);
        }
    }
    handle->count++;
    return result;
}

// Shrink the pool's tail: release `amount` elements of the last free run (0 = all of it).
void func_800B3EDC(LocalHeap **pool_ptr, s32 amount)
{
    s16 *last;
    s32 index;
    LocalHeap *pool;
    s16 *prev_link;

    pool = *pool_ptr;
    index = 0;
    prev_link = 0;
    last = &pool->free_head;
    while (*last) {
        prev_link = last;
        index = *last;
        last = &func_800B39D0(pool, *last)->next;
    }
    if (pool->capacity == last[1] + index && last[1] >= amount) {
        // index now holds the new capacity
        index = pool->capacity - (amount > 0 ? amount : last[1]);
        if (amount == 0 || amount == last[1]) {
            *prev_link = 0;
        } else {
            last[1] -= amount;
        }
        pool = heap_realloc(pool, pool->element_size * index + 4);
        pool->capacity = index;
        *pool_ptr = pool;
    }
}

// Remove the element at `index` of the handle's run, shifting later elements down.
void func_800B3FD0(u8 **pool_ptr, local_9 *handle, s32 index)
{
    // Matching: the array is needed for the match.
    s32 merged[2];
    s16 *dst;
    s16 *run;
    s16 start;
    int run_index;
    s32 remaining;
    u8 *pool;
    pool = *pool_ptr;
    merged[0] = 0;
    if (index == 0) {
        run = pool + 4;
        run_index = 0;
        if (*(s16 *) ((s8 *) pool + 4) != 0) {
        loop_2:
            start = handle->start;

            // A free run directly before the handle: give it the removed first element.
            if (start == (*(s16 *) ((s8 *) run + 2) + run_index)) {
                func_800B3B08(pool, start, 1);
                handle->start = (s16) (handle->start + 1);
                merged[0] = 1;
            } else {
                start = *(s16 *) ((s8 *) run + 0);
                run_index = start;
                run = func_800B39D0(pool, start);
                if (*run != 0) {
                    goto loop_2;
                }
            }
        }
    }
    if (merged[0] == 0) {
        remaining = handle->count;
        remaining -= index;
        remaining -= 1;
        if (remaining > 0) {
            dst = func_800B39D0(pool, handle->start + index);
            aligned4_memcpy(dst, func_800B39D0(pool, (handle->start + index) + 1),
                            *(s16 *) ((s8 *) pool + 0) * remaining);
            // Matching: the dummy label is needed for the match.
            goto dummy_label_870371;
        dummy_label_870371:;
        }
        func_800B3B08(pool, (handle->start + handle->count) - 1, 1);
    }
    func_800B3EDC(pool_ptr, 0xA);
    handle->count = (s16) (handle->count - 1);
    if (handle->count == 0) {
        handle->start = 0;
    }
}

// Move the handle's elements down into the free run just before them. Returns 1 on success.
s32 func_800B4134(LocalHeap **pool_ptr, LocalHandle *handle)
{
    s16 *run;
    s32 run_index;
    LocalHeap *pool;
    s16 *prev_link;
    s32 run_size;

    pool = *pool_ptr;
    prev_link = 0;
    run_index = 0;
    run = &pool->free_head;
    while (*run) {
        if (handle->start == run[1] + run_index) {
            *prev_link = *run;
            run_size = run[1];
            aligned4_memcpy(run, func_800B39D0(pool, handle->start),
                            handle->count * pool->element_size);
            handle->start = run_index;
            func_800B3B08(pool, handle->start + handle->count, run_size);
            return 1;
        }
        prev_link = run;
        run_index = *run;
        run = &func_800B39D0(pool, *run)->next;
    }
    return 0;
}

// Free the handle's elements, shrink the pool tail and clear the handle.
void func_800B422C(void *pool_ptr, s16 *handle)
{
    u32 pool;
    u32 start;
    pool = *(u32 *) pool_ptr;
    if ((start = handle[0]) != 0) {
        func_800B3B08(pool, start, handle[1]);
        func_800B3EDC(pool_ptr, 10);
        handle[1] = 0;
        handle[0] = handle[1];
    }
}

// Clear the handle.
s32 func_800B4290(s16 *handle)
{
    handle[1] = 0;
    handle[0] = handle[1];
}

// Pointer to the handle's first element, or 0 if the handle is empty.
s32 func_800B42A0(void *pool, s16 *handle)
{
    s16 start = *handle;
    s32 result;
    if (start != 0) {
        result = func_800B39D0(pool, start);
    } else {
        result = 0;
    }
    return result;
}

void func_800B42DC(void *pool)
{
    heap_free(pool);
}

u8 *func_800B42FC(s32 element_size, s32 count)
{
    u8 *pool;
    count = count + 1;
    pool = heap_alloc((element_size * count) + 4, count);
    *(s16 *) pool = (s16) element_size;
    *(s16 *) (pool + 2) = (s16) count;
    func_800B39E8(pool);
    return pool;
}

// Release the whole last free run at the pool's tail.
void func_800B4354(s32 pool_ptr)
{
    func_800B3EDC(pool_ptr, 0);
}

func_800B4374(s16 *pool)
{
    return pool[2];
}
