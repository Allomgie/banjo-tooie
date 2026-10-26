#include "common.h"

#define SCROLL_STATE_1446
typedef struct { f32 value; s16 offset; u8 pad_0[2]; f32 speed; s32 count; s16 indices[1]; } ScrollState1446;
typedef struct { u8 pad_0[0x14]; s32 count; } ScrollModel1446;
typedef struct { u16 id, enabled; } ScrollItem1446;
typedef struct { s32 seed; u8 pad_0[0x10]; ScrollItem1446 items[1]; } ScrollItems1446;
extern void *heap_alloc(s32);
typedef struct { u8 pad_0[0x1C]; s32 offset; } ScrollMesh1446;
typedef struct { u8 pad_0[3]; u8 dirty; u8 pad_1[16]; } ScrollDirty1446;
extern f32 func_800D8FF8(void);
typedef struct { s16 local_0[3]; u16 local_1; s16 local_2[2]; u8 local_3[4]; } ScrollVertex1255;
typedef struct { u8 pad_0[4]; s16 local_0; } ScrollOffset1255;

ScrollState1446 *vpscroll_entrypoint_0(ScrollModel1446 *param_0, ScrollItems1446 *param_1)
{
    ScrollState1446 *local_0;
    ScrollItem1446 *local_1;
    ScrollItem1446 *local_2;
    ScrollItem1446 *local_3;

    local_0 = heap_alloc(param_0->count * 2 + 0x10);
    local_2 = (ScrollItem1446 *)(param_0->count * sizeof(ScrollItem1446) + (u32)param_1 + 0x14);
    local_3 = param_1->items;
    local_0->count = 0;
    local_0->offset = 0;
    local_0->value = 0.0f;
    local_0->speed = param_1->seed % 100;
    local_1 = local_3;
    while (local_1 < local_2) {
        if (local_1->enabled) {
            local_0->indices[local_0->count] = local_1 - local_3;
            local_0->count++;
        }
        local_1++;
    }
    return local_0;
}

void vpscroll_entrypoint_1(void* arg0) 
{
    heap_free(arg0);
}
void vpscroll_entrypoint_2(ScrollState1446 *param_0, ScrollMesh1446 *param_1)
{
    s32 local_0;
    s32 local_1;
    ScrollDirty1446 *local_2;
    s16 *local_3;

    param_0->value += param_0->speed * 64.0f * func_800D8FF8();
    local_0 = (s32)param_0->value;
    if (local_0 >= 0x2001) {
        param_0->value -= 8192.0f;
        local_0 = (s32)param_0->value;
    }
    param_0->offset = local_0;
    local_2 = (ScrollDirty1446 *)((u8 *)param_1 + param_1->offset);
    local_1 = 0;
    if (param_0->count > 0) {
        local_3 = param_0->indices;
        do {
            local_2[*local_3].dirty = 1;
            local_1++;
            local_3++;
        } while (local_1 < param_0->count);
    }
}

void vpscroll_entrypoint_3(ScrollOffset1255 *param_0, s32 param_1,
                        ScrollVertex1255 *param_2, s32 param_3)
{
    s16 local_0;
    ScrollVertex1255 *local_1;

    local_0 = param_0->local_0;
    local_1 = param_2 + param_3;
    if (param_2 < local_1) {
        do {
            param_2->local_2[1] += local_0;
            param_2++;
        } while (param_2 < local_1);
    }
}
