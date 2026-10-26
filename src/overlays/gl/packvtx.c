#include "common.h"

extern void _dbpalette_entrypoint_0();
typedef struct Mass44PackedVertex { s16 local_0[3]; u8 local_1[3]; u8 local_2; } Mass44PackedVertex;

void *glpackvtx_entrypoint_0(s32 param_0, s32 param_1, s32 *param_2)
{
  s32 pad0;
    Mass44PackedVertex *local_0;
    Mass44PackedVertex *local_1;
    Mass44PackedVertex *local_2;
    u8 *local_3;
    s32 local_4[4];
    s32 local_5;
    local_5 = func_800B2344(param_0);
    local_0 = heap_alloc(local_5 * sizeof(Mass44PackedVertex));
    local_2 = local_0 + local_5;
    local_3 = (u8 *)func_800B2190(param_0);
    for (local_1 = local_0; local_1 < local_2; local_1++, local_3 += 16) {
        if (param_1) {
            _dbpalette_entrypoint_0(param_1, *(u16 *)(local_3 + 6) & 0x1FF, local_4);
            local_1->local_1[0] = (local_3[12] * local_4[0]) >> 8;
            local_1->local_1[1] = (local_3[13] * local_4[1]) >> 8;
            local_1->local_1[2] = (local_3[14] * local_4[2]) >> 8;
        } else {
            local_1->local_1[0] = local_3[12];
            local_1->local_1[1] = local_3[13];
            local_1->local_1[2] = local_3[14];
        }
        if (param_2 && (param_2[0] != 255 || param_2[1] != 255 || param_2[2] != 255)) {
            local_1->local_1[0] = (local_1->local_1[0] * param_2[0]) >> 8;
            local_1->local_1[1] = (local_1->local_1[1] * param_2[1]) >> 8;
            local_1->local_1[2] = (local_1->local_1[2] * param_2[2]) >> 8;
        }
        local_1->local_0[0] = local_1->local_0[1] = local_1->local_0[2] = 0;
    }
    return local_0;
}

s32 glpackvtx_entrypoint_1(void* param_0) {
    heap_free(param_0);
}
