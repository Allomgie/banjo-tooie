// Handle table for movable heap blocks (up to 249 handles): alloc, realloc, free, get, plus
// incremental defragmentation that fixes up pointers of blocks that moved.
#include "common.h"

typedef struct {
    s32 *ptr;
    s32 type;
} Ent8001B4B0;
extern Ent8001B4B0 D_8007BF18[];
typedef struct {
    u8 unk0[0x20];
} Cell8001B4E8;
extern Cell8001B4E8 D_8007BF20[];
extern Cell8001B4E8 D_8007C6E0[];
typedef struct {
    s32 *ptr;
    s32 type;
} Struct8001B518;
extern s32 D_8007C6E4;
extern s32 *defrag(s32 *param_0);
typedef struct {
    void *ptr;
    s32 type;
} Struct8001B668;
extern void *heap_alloc_sided(s32, s32);
extern void func_8001B3A0(void *);
typedef union {
    s32 pair[2];
    double value;
} Union8007BF10;
extern Union8007BF10 D_8007BF10[];

void func_8001B4B0(void)
{
    s32 i;
    for (i = 0; i < 249; i++) {
        D_8007BF18[i].ptr = NULL;
    }
}

void func_8001B4E8(void)
{
    s32 i;

    i = 0;
    do {
        i++;
    } while (D_8007C6E0 != &D_8007BF20[i]);
}

void func_8001B50C()
{
    *(int *) D_8007C6E0 = 0;
}

// Defragments handle blocks round-robin (20 steps, or all 250 if full_pass) and fixes
// pointers by block type.
void func_8001B518(s32 full_pass)
{
    s32 *new_ptr;
    s32 *ptr;
    s32 type;
    s32 step;
    s32 steps;
    s32 *old_ptr;
    s32 index;
    Struct8001B518 *entry;
    if ((*(s32 *) D_8007C6E0 == 0) || (full_pass != 0)) {
        step = full_pass != 0;
        *(s32 *) D_8007C6E0 = 1;
        steps = step ? 0xFA : 0x14;
        step = 1;
        if (steps >= 2) {
            do {
                index = ++D_8007C6E4;
                if (index >= 0xFA) {
                    D_8007C6E4 = 0;
                    index = 0;
                }
                if ((ptr = ((Struct8001B518 *) D_8007BF10)[index].ptr) != 0) {
                    new_ptr = defrag(old_ptr = ptr);
                    ptr = new_ptr;
                    entry = &((Struct8001B518 *) D_8007BF10)[D_8007C6E4];
                    entry->ptr = ptr;
                    if (new_ptr != old_ptr) {
                        type = entry->type;
                        if (type != 0) {
                            switch (type) {
                                case 1:
                                    func_800E0040(entry->ptr);
                                    break;

                                case 3:
                                    func_800E0AC0(entry->ptr);
                                    break;

                                case 5:
                                    vector_update_pointers(entry->ptr);
                            }
                        }
                    }
                }
                step += 1;
            } while (step != steps);
        }
    }
}

// Allocates a movable block and returns its handle, or 0 if the table is full.
s16 func_8001B668(s32 type, s32 size)
{
    s32 handle;

    handle = 1;
    if (*(s32 *) D_8007BF18 != 0) {
        do {
            handle++;
        } while (((Struct8001B668 *) D_8007BF10)[handle].ptr != NULL);
    }

    if (handle < 0xFA) {
        ((Struct8001B668 *) D_8007BF10)[handle].ptr = heap_alloc_sided(size, 2);
        ((Struct8001B668 *) D_8007BF10)[handle].type = type;
        func_8001B3A0(((Struct8001B668 *) D_8007BF10)[handle].ptr);
        return handle;
    }

    return 0;
}

// Matching: param_1 is passed through in $a1 untouched, so IDO uses $a2 as scratch for the
// s16 sign extension. No locals: one would move the base pointer spill from 0x1C to 0x18.
void func_8001B710(handle, size) s16 handle;
s32 size;
{
    *(void **) &D_8007BF10[handle].value =
        heap_realloc(*(void **) &D_8007BF10[handle].value, size);
}

void func_8001B754(handle) s16 handle;
{
    heap_free((void *) D_8007BF10[handle].pair[0]);
    D_8007BF10[handle].pair[0] = 0;
}

s32 func_8001B798(handle)
s16 handle;
{
    return D_8007BF10[handle].pair[0];
}

void func_8001B7B8(handle) s16 handle;
{
    heap_get_allocation_size(D_8007BF10[handle].pair[0]);
}

void func_8001B7F0(handle, value, size) s16 handle;
u8 value;
s32 size;
{
    u8 *ptr;
    u32 fill;
    u32 index;

    fill = value;
    index = handle;
    ptr = (u8 *) &((s64 *) D_8007BF10)[index];
    ptr = (u8 *) *(s32 *) ptr;
    rare_memset(ptr, fill, size);
}
