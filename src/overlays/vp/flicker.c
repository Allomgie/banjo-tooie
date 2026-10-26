#include "common.h"

typedef struct { u16 local_0; u16 local_1; } FlickerVertex;
typedef struct { f32 local_0; s32 local_1; s16 local_2[1]; } FlickerIndices;
extern void *heap_alloc(s32);
typedef struct { f32 local_0; s32 local_1; } VpFlickerState;
typedef struct { u8 pad_0[3]; u8 local_0; u8 pad_1[16]; } VpFlickerVertex;
typedef struct { u8 pad_0[0x1C]; s32 local_0; } VpFlickerModel;
extern f32 func_800DC264(f32, f32);

FlickerIndices *vpflicker_entrypoint_0(u8 *param_0, u8 *param_1)
{
    FlickerIndices *local_0;
    FlickerVertex *local_1;
    FlickerVertex *local_2;
    FlickerVertex *local_3;

    local_0 = heap_alloc(*(s32 *)(param_0 + 0x14) * 2 + 8);
    local_1 = (FlickerVertex *)(param_1 + 0x14);
    local_2 = (FlickerVertex *)(param_1 + *(s32 *)(param_0 + 0x14) * 4 + 0x14);
    local_0->local_1 = 0;
    local_0->local_0 = 1.0f;
    for (local_3 = local_1; local_3 < local_2; local_3++) {
        if (local_3->local_1) {
            local_0->local_2[local_0->local_1] = local_3 - local_1;
            local_0->local_1++;
        }
    }
    return local_0;
}

void vpflicker_entrypoint_1(void* arg0) 
{
    heap_free(arg0);
}
void vpflicker_entrypoint_2(VpFlickerState *param_0, VpFlickerModel *param_1)
{
    VpFlickerVertex *local_0;
    s32 local_1;
    s16 *local_2;

    param_0->local_0 += func_800DC264(-0.04f, 0.04f);
    param_0->local_0 = param_0->local_0 > 1.0f ? 1.0f : param_0->local_0;
    param_0->local_0 = param_0->local_0 < 0.8f ? 0.8f : param_0->local_0;
    local_0 = (VpFlickerVertex *)((u8 *)param_1 + param_1->local_0);
    local_2 = (s16 *)(param_0 + 1);
    for (local_1 = 0; local_1 < param_0->local_1; local_1++) {
        local_0[local_2[local_1]].local_0 = 1;
    }
}

void vpflicker_entrypoint_3(f32 *param_0, s32 param_1, Vtx *param_2, s32 param_3)
{
    Vtx *local_0;
    f32 local_1;
    local_0 = param_2 + param_3;
    local_1 = *param_0;
    for (; param_2 < local_0; param_2++) {
        param_2->v.cn[0] *= local_1;
        param_2->v.cn[1] *= local_1;
        param_2->v.cn[2] *= local_1;
    }
}
