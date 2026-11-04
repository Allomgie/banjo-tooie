// Most likely the glow vertex effect (pulsing light): brightness ping-pongs between 0.3 and
// 1.0 at a speed from the effect id and scales the vertex RGB of its groups.
#include "common.h"

typedef struct {
    f32 value, speed;
    s32 count;
    s16 indices[1];
} GlowState1446;
typedef struct {
    u8 pad_0[0x1C];
    s32 offset;
} GlowMesh1446;
typedef struct {
    u8 pad_0[3];
    u8 dirty;
    u8 pad_1[16];
} GlowDirty1446;
extern f32 func_800D8FF8(void);

// Creates the state: value 0.5, speed from the effect id, indices of the enabled groups.
u8 *vpglow_entrypoint_0(u8 *arg0, s32 *def)
{
    u8 *first;
    u8 *end;
    u8 *state;
    u8 *entry;
    state = heap_alloc((*(s32 *) ((s8 *) arg0 + 0x14) * 2) + 0xC);
    end = (u8 *) def;
    end = ((*(s32 *) ((s8 *) arg0 + 0x14) * 4) + end) + 0x14;
    *(s32 *) ((s8 *) state + 8) = 0;
    *(f32 *) ((s8 *) state + 0) = 0.5f;
    first = (u8 *) def + 0x14;
    entry = first;
    *(f32 *) ((s8 *) state + 4) = (f32) (((f32) ((s32) *def % 100) + 1.0f) * 0.01f);
    if ((u32) first < (u32) end) {
        do {
            if (*(u16 *) ((s8 *) entry + 2) != 0) {
                *(s16 *) ((s8 *) (state + (*(s32 *) ((s8 *) state + 8) * 2)) + 0xC) =
                    (s16) ((s32) (entry - first) >> 2);
                *(s32 *) ((s8 *) state + 8) = (s32) (*(s32 *) ((s8 *) state + 8) + 1);
            }
            entry += 4;
        } while ((u32) entry < (u32) end);
    }
    return state;
}

void vpglow_entrypoint_1(void *arg0)
{
    heap_free(arg0);
}

// Ping-pongs the value between 0.3 and 1.0 and marks the groups dirty.
void vpglow_entrypoint_2(GlowState1446 *state, GlowMesh1446 *mesh)
{
    s32 i;
    GlowDirty1446 *groups;
    s16 *idx;

    state->value += state->speed * func_800D8FF8();
    if (state->value >= 1.0f) {
        state->value = 1.0f;
        state->speed = -state->speed;
    } else if (state->value < 0.3f) {
        state->value = 0.3f;
        state->speed = -state->speed;
    }
    groups = (GlowDirty1446 *) ((u8 *) mesh + mesh->offset);
    i = 0;
    if (state->count > 0) {
        idx = state->indices;
        do {
            groups[*idx].dirty = 1;
            i++;
            idx++;
        } while (i < state->count);
    }
}

// Scales the vertex colours by the glow value.
void vpglow_entrypoint_3(f32 *state, s32 arg1, Vtx *vtx, s32 count)
{
    Vtx *end;
    f32 value;
    end = vtx + count;
    value = *state;
    for (; vtx < end; vtx++) {
        vtx->v.cn[0] *= value;
        vtx->v.cn[1] *= value;
        vtx->v.cn[2] *= value;
    }
}
