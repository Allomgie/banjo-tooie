#include "common.h"

typedef struct { s16 position[3]; u16 flags; s16 uv[2]; u8 color[4]; } DbVplVertex;

s32 *dbvpl_entrypoint_0(u8 *param_0, s32 param_1) {
    s32 i;
    s32 *local_0;
    for (i = 0; i < *(s32 *)(param_0 + 0x2C); i++) {
        local_0 = (s32 *)(param_0 + ((s32 *)(param_0 + 0x30))[i]);
        if (*local_0 == param_1) {
            return local_0;
        }
    }
    return 0;
}

void dbvpl_entrypoint_1(s32 param_0, DbVplVertex *param_1, s32 param_2, s32 *param_3)
{
    DbVplVertex *local_0;
    DbVplVertex *local_2;
    DbVplVertex *local_1;
    DbVplVertex *local_3;
    s32 local_6;
    u32 local_7;

    func_800B2324(param_2, &local_0, &local_1);
    for (local_2 = local_0; local_2 < local_1; local_2++) {
        local_7 = local_2->flags & 0x7FFF;
        if (local_7 != 0x7FFF) {
            local_3 = &param_1[local_7];
            if (param_3[0] != 255 || param_3[1] != 255 || param_3[2] != 255) {
                for (local_6 = 0; local_6 < 3; local_6++) {
                    local_2->color[local_6] = (local_2->color[local_6] * param_3[local_6]) >> 8;
                }
            }
            aligned8_memcpy(local_3, local_2, sizeof(DbVplVertex));
            local_3->flags &= 0x8000;
            local_3->flags |= (local_2 - local_0) & 0x7FFF;
        }
    }
}
