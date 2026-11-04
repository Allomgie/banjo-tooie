// Probably the flicker vertex effect (fire or candle light): a brightness factor random-walks
// by +-0.04 within 0.8..1.0 and scales the vertex RGB of its groups.
#include "common.h"

// Definition entry: one per vertex group.
typedef struct {
    u16 unk_0;
    u16 enabled;
} FlickerVertex;
// Effect state: brightness factor and the indices of the enabled groups.
typedef struct {
    f32 factor;
    s32 count;
    s16 group_idx[1];
} FlickerIndices;
extern void *heap_alloc(s32);
typedef struct {
    f32 factor;
    s32 count;
} VpFlickerState;
// Vertex group record; only the dirty byte is used here.
typedef struct {
    u8 pad_0[3];
    u8 dirty;
    u8 pad_1[16];
} VpFlickerVertex;
typedef struct {
    u8 pad_0[0x1C];
    s32 groups_off;
} VpFlickerModel;
extern f32 func_800DC264(f32, f32);

FlickerIndices *vpflicker_entrypoint_0(u8 *arg0, u8 *def)
{
    FlickerIndices *state;
    FlickerVertex *first;
    FlickerVertex *end;
    FlickerVertex *entry;

    state = heap_alloc(*(s32 *) (arg0 + 0x14) * 2 + 8);
    first = (FlickerVertex *) (def + 0x14);
    end = (FlickerVertex *) (def + *(s32 *) (arg0 + 0x14) * 4 + 0x14);
    state->count = 0;
    state->factor = 1.0f;
    for (entry = first; entry < end; entry++) {
        if (entry->enabled) {
            state->group_idx[state->count] = entry - first;
            state->count++;
        }
    }
    return state;
}

void vpflicker_entrypoint_1(void *arg0)
{
    heap_free(arg0);
}

// Random walk of the brightness factor, clamped to 0.8..1.0; marks all groups dirty.
void vpflicker_entrypoint_2(VpFlickerState *state, VpFlickerModel *model)
{
    VpFlickerVertex *groups;
    s32 i;
    s16 *group_idx;

    state->factor += func_800DC264(-0.04f, 0.04f);
    state->factor = state->factor > 1.0f ? 1.0f : state->factor;
    state->factor = state->factor < 0.8f ? 0.8f : state->factor;
    groups = (VpFlickerVertex *) ((u8 *) model + model->groups_off);
    group_idx = (s16 *) (state + 1);
    for (i = 0; i < state->count; i++) {
        groups[group_idx[i]].dirty = 1;
    }
}

// Scales the vertex colours by the brightness factor.
void vpflicker_entrypoint_3(f32 *state, s32 arg1, Vtx *vtx, s32 count)
{
    Vtx *end;
    f32 factor;
    end = vtx + count;
    factor = *state;
    for (; vtx < end; vtx++) {
        vtx->v.cn[0] *= factor;
        vtx->v.cn[1] *= factor;
        vtx->v.cn[2] *= factor;
    }
}
