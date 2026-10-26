#include "common.h"

typedef struct { u8 pad_0[0xA]; s16 local_0; u8 pad_1[4]; } ScrollVertex;
typedef struct { u8 pad_0[4]; s16 local_0; } ScrollRenderState;
typedef struct { f32 offset; s16 wrapped; s16 pad_0; f32 speed; } ScrollState;
extern f32 func_800D8FF8(void);
extern void _idscroll_entrypoint_0(void);

void idscroll_entrypoint_0(void *param_0, ScrollVertex *param_1, ScrollVertex *param_2,
                          s32 param_3, ScrollRenderState *param_4)
{
    ScrollVertex *local_0;
    s16 local_1;
    s32 local_2;
    local_1 = param_4->local_0;
    local_0 = param_1 + param_3;
    for (; param_1 < local_0; param_1++, param_2++) {
        local_2 = param_1->local_0 + local_1;
        local_2 -= 0x2000;
        param_2->local_0 = local_2;
    }
}

void idscroll_entrypoint_1(s32 arg0) 
{
}
idscroll_entrypoint_2(f32 *param_0, s32 param_1, s32 param_2, s32 param_3)
{
  f32 local_0;
  local_0 = param_1;
  param_0[0] = 0.0f;
  param_0[2] = local_0;
}

void idscroll_entrypoint_3(ScrollState *param_0, void *param_1, void *param_2)
{
    param_0->offset += param_0->speed * 64.0f * func_800D8FF8();
    if ((s32)param_0->offset > 8192) param_0->offset -= 8192.0f;
    param_0->wrapped = (s32)param_0->offset;
    _glid_entrypoint_0(param_1, param_2, _idscroll_entrypoint_0, param_0);
}
