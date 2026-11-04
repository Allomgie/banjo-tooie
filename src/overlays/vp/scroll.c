#include "common.h"

typedef struct {
    f32 value;
    s16 offset;
    u8 pad_0[2];
    f32 speed;
    s32 count;
    s16 indices[1];
} ScrollState1446;
typedef struct {
    u8 pad_0[0x14];
    s32 count;
} ScrollModel1446;
typedef struct {
    u16 id, enabled;
} ScrollItem1446;
typedef struct {
    s32 seed;
    u8 pad_0[0x10];
    ScrollItem1446 items[1];
} ScrollItems1446;
extern void *heap_alloc(s32);
typedef struct {
    u8 pad_0[0x1C];
    s32 offset;
} ScrollMesh1446;
typedef struct {
    u8 pad_0[3];
    u8 dirty;
    u8 pad_1[16];
} ScrollDirty1446;
extern f32 func_800D8FF8(void);

typedef struct {
    s16 pos[3];
    u16 flag;
    s16 tc[2];
    u8 color[4];
} ScrollVertex1255;
typedef struct {
    u8 pad_0[4];
    s16 offset;
} ScrollOffset1255;

// Allocates the scroll state; speed comes from the definition id (id % 100).
ScrollState1446 *vpscroll_entrypoint_0(ScrollModel1446 *model, ScrollItems1446 *def)
{
    ScrollState1446 *state;
    ScrollItem1446 *item;
    ScrollItem1446 *end;
    ScrollItem1446 *first;

    state = heap_alloc(model->count * 2 + 0x10);
    end = (ScrollItem1446 *) (model->count * sizeof(ScrollItem1446) + (u32) def + 0x14);
    first = def->items;
    state->count = 0;
    state->offset = 0;
    state->value = 0.0f;
    state->speed = def->seed % 100;
    item = first;
    while (item < end) {
        if (item->enabled) {
            state->indices[state->count] = item - first;
            state->count++;
        }
        item++;
    }
    return state;
}

void vpscroll_entrypoint_1(void *arg0)
{
    heap_free(arg0);
}

// Advances the scroll offset (wraps at 8192) and marks the affected groups dirty.
void vpscroll_entrypoint_2(ScrollState1446 *state, ScrollMesh1446 *mesh)
{
    s32 offset;
    s32 i;
    ScrollDirty1446 *dirty;
    s16 *index;

    state->value += state->speed * 64.0f * func_800D8FF8();
    offset = (s32) state->value;
    if (offset >= 0x2001) {
        state->value -= 8192.0f;
        offset = (s32) state->value;
    }
    state->offset = offset;
    dirty = (ScrollDirty1446 *) ((u8 *) mesh + mesh->offset);
    i = 0;
    if (state->count > 0) {
        index = state->indices;
        do {
            dirty[*index].dirty = 1;
            i++;
            index++;
        } while (i < state->count);
    }
}

// Adds the scroll offset to the T texture coordinate of each vertex.
void vpscroll_entrypoint_3(ScrollOffset1255 *scroll, s32 unk_0, ScrollVertex1255 *vtx,
                           s32 count)
{
    s16 offset;
    ScrollVertex1255 *end;

    offset = scroll->offset;
    end = vtx + count;
    if (vtx < end) {
        do {
            vtx->tc[1] += offset;
            vtx++;
        } while (vtx < end);
    }
}
