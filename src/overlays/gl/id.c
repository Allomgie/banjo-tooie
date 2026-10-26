#include "common.h"

typedef struct GlIdChunk_glid_entrypoint_0 { s16 local_0; s16 local_1; s32 local_2; } GlIdChunk_glid_entrypoint_0;
typedef struct GlIdItem_glid_entrypoint_0 { s16 local_0; s16 local_1; } GlIdItem_glid_entrypoint_0;
extern void *func_800B2190(s32);
typedef struct { s16 local_0; s16 local_1; s32 local_2; } GlIdChunk_glid_entrypoint_1;
typedef struct { s16 local_0; s16 local_1; } GlIdItem_glid_entrypoint_1;
typedef struct { s16 position[3]; u16 flags; s16 uv[2]; u8 color[4]; } GlIdVertex;

void glid_entrypoint_0(param_0, param_1, param_2, param_3) u8 *param_0; s32 param_1; void (*param_2)(s32, void *, void *, s32, s32); s32 param_3;
{
    u8 *local_0;
    GlIdChunk_glid_entrypoint_0 *local_1;
    GlIdItem_glid_entrypoint_0 *local_2;
    GlIdItem_glid_entrypoint_0 *local_3;
    u8 *local_4;
    s32 local_5;

    local_0 = func_800B2190(*(s32 *)(param_0 + 0x14));
    local_1 = (GlIdChunk_glid_entrypoint_0 *)(param_0 + 0x1C);
    for (local_5 = 0; local_5 < *(s32 *)(param_0 + 4); local_5++) {
        if (param_1 == local_1->local_0) {
            local_2 = (GlIdItem_glid_entrypoint_0 *)(local_1 + 1);
            local_3 = local_2 + local_1->local_1;
            local_4 = (u8 *)local_3;
            for (; local_2 < local_3; local_2++) {
                param_2(local_1->local_0, local_4, local_0 + local_2->local_0 * 16, local_2->local_1, param_3);
                local_4 += local_2->local_1 * 16;
            }
            break;
        }
        local_1 = (GlIdChunk_glid_entrypoint_0 *)((u8 *)local_1 + local_1->local_2);
    }
}

void glid_entrypoint_1(param_0, param_1, param_2, param_3) u8 *param_0; s32 param_1; void (*param_2)(void *, void *, void *, s32, s32); s32 param_3;
{
    GlIdChunk_glid_entrypoint_1 *local_0;
    GlIdItem_glid_entrypoint_1 *local_1;
    GlIdItem_glid_entrypoint_1 *local_2;
    u8 *local_3;
    u8 *local_4;
    u8 *local_5;
    s32 local_6;
    s32 local_7;

    local_3 = func_800B2190(*(s32 *)(param_0 + 0x14));
    local_4 = func_800B2190(*(s32 *)(param_0 + 0x18));
    local_0 = (GlIdChunk_glid_entrypoint_1 *)(param_0 + 0x1C);
    for (local_6 = 0; local_6 < *(s32 *)(param_0 + 4); local_6++) {
        if (param_1 == local_0->local_0) {
            local_1 = (GlIdItem_glid_entrypoint_1 *)(local_0 + 1);
            local_2 = local_1 + local_0->local_1;
            local_5 = (u8 *)local_2;
            for (; local_1 < local_2; local_1++) {
                local_7 = local_1->local_0 * 16;
                param_2(local_5, local_7 + local_3, local_7 + local_4, local_1->local_1, param_3);
                local_5 += local_1->local_1 * 16;
            }
            break;
        }
        local_0 = (GlIdChunk_glid_entrypoint_1 *)((u8 *)local_0 + local_0->local_2);
    }
}

void glid_entrypoint_2(param_0, param_1, param_2, param_3) u8 *param_0; s32 param_1; s32 (*param_2)(s16, u8 *, u8 *, s32); s32 param_3;
{
    u8 *local_0;
    u8 *local_1;
    u8 *local_2;
    u8 *local_3;
    u8 *local_4;
    s16 *local_5;
    s16 *local_6;
    s32 local_7;

    local_0 = func_800B2190(*(s32 *)(param_0 + 0x14));
    local_1 = param_0 + 0x1C;
    for (local_7 = 0; local_7 < *(s32 *)(param_0 + 4); local_7++) {
        if (param_1 == *(s16 *)local_1) {
            local_5 = (s16 *)(local_1 + 8);
            local_6 = (s16 *)(local_1 + *(s16 *)(local_1 + 2) * 4 + 8);
            local_2 = (u8 *)local_6;
            for (; local_5 < local_6; local_5 += 2) {
                local_3 = local_0 + local_5[0] * 16;
                local_4 = local_3 + local_5[1] * 16;
                for (; local_3 < local_4; local_3 += 16) {
                    param_2(*(s16 *)local_1, local_2, local_3, param_3);
                    local_2 += 16;
                }
            }
            break;
        }
        local_1 += *(s32 *)(local_1 + 4);
    }
}

void glid_entrypoint_3(param_0, param_1, param_2, param_3) u8 *param_0; s32 param_1; void (*param_2)(void *, void *, s32, void *); s32 param_3;
{
    u8 *local_0;
    u8 *local_1;
    u8 *local_2;
    u8 *local_3;
    u8 *local_4;
    u8 *local_5;
    u8 *local_6;
    u8 *local_7;
    s32 local_8;
    u8 *local_9;
    local_0 = (u8 *)func_800B2190(*(s32 *)(param_0 + 0x14));
    local_1 = (u8 *)func_800B27A0(func_800D674C(*(s32 *)param_0));
    local_2 = param_0 + 0x1C;
    for (local_8 = 0; local_8 < *(s32 *)(param_0 + 4); local_8++) {
        if (*(s16 *)local_2 == param_1) {
            local_3 = local_2 + 8;
            local_4 = local_2 + 8 + *(s16 *)(local_2 + 2) * 4;
            local_5 = local_4;
            while (local_3 < local_4) {
                local_6 = local_0 + *(s16 *)local_3 * 16;
                local_7 = local_6 + *(s16 *)(local_3 + 2) * 16;
                local_9 = (u8 *)_dbvtxnormal_entrypoint_0(local_1, *(s16 *)local_3);
                while (local_6 < local_7) {
                    param_2(local_5, local_6, param_3, local_9);
                    local_6 += 16;
                    local_5 += 16;
                    local_9 += 4;
                }
                local_3 += 4;
            }
            break;
        }
        local_2 += *(s32 *)(local_2 + 4);
    }
}

void glid_entrypoint_4(param_0, param_1, param_2) u8 *param_0; void (*param_1)(s16, GlIdVertex *, GlIdVertex *, s32); s32 param_2;
{
    GlIdVertex *local_0;
    u8 *local_1;
    GlIdVertex *local_2;
    GlIdVertex *local_3;
    s32 local_7;
    GlIdVertex *local_4;
    s16 *local_5;
    s16 *local_6;

    local_0 = func_800B2190(*(s32 *)(param_0 + 0x14));
    local_1 = param_0 + 0x1C;
    for (local_7 = 0; local_7 < *(s32 *)(param_0 + 4); local_7++) {
        local_5 = (s16 *)(local_1 + 8);
        local_6 = (s16 *)(local_1 + *(s16 *)(local_1 + 2) * 4 + 8);
        local_2 = (GlIdVertex *)local_6;
        for (; local_5 < local_6; local_5 += 2) {
            local_3 = local_0 + local_5[0];
            local_4 = local_3 + local_5[1];
            for (; local_3 < local_4; local_3++) {
                param_1(*(s16 *)local_1, local_2, local_3, param_2);
                local_2++;
            }
        }
        local_1 += *(s32 *)(local_1 + 4);
    }
}

void glid_entrypoint_5(s32 *param_0, s32 param_1) {
    param_0[5] = param_1;
}

void glid_entrypoint_6(void *param_0, s32 param_1)
{
  unsigned int new_var4;
  unsigned int new_var2;
  void *new_var;
  int new_var3;
  new_var3 = 0x32 ^ 0;
  new_var2 = new_var3;
  ;
  new_var2 = 6;
 new_var4 = new_var2; ((s32 *) param_0)[new_var4] = param_1; if (new_var2 ^ 0) { if (new_var2) { } }
}
