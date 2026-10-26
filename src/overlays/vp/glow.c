#include "common.h"

typedef struct { f32 value, speed; s32 count; s16 indices[1]; } GlowState1446;
typedef struct { u8 pad_0[0x1C]; s32 offset; } GlowMesh1446;
typedef struct { u8 pad_0[3]; u8 dirty; u8 pad_1[16]; } GlowDirty1446;
extern f32 func_800D8FF8(void);

u8 *vpglow_entrypoint_0(u8 *param_0, s32 *param_1)
{
  u8 *local_0;
  u8 *local_1;
  u8 *local_2;
  f32 new_var;
  u8 *local_3;
  local_2 = heap_alloc(((*((s32 *) (((s8 *) param_0) + 0x14))) * 2) + 0xC);
  local_1 = (u8 *) param_1;
  local_1 = (((*((s32 *) (((s8 *) param_0) + 0x14))) * 4) + local_1) + 0x14;
  *((s32 *) (((s8 *) local_2) + 8)) = 0;
  *((f32 *) (((s8 *) local_2) + 0)) = 0.5f;
  local_0 = ((u8 *) param_1) + 0x14;
  local_3 = local_0;
  ;
  *((f32 *) (((s8 *) local_2) + 4)) = (f32) ((((f32) (((s32) (*param_1)) % 100)) + 1.0f) * 0.01f);
  if (((u32) local_0) < ((u32) local_1))
  {
    do
    {
      if ((*((u16 *) (((s8 *) local_3) + 2))) != 0)
      {
        *((s16 *) (((s8 *) (local_2 + ((*((s32 *) (((s8 *) local_2) + 8))) * 2))) + 0xC)) = (s16) (((s32) (local_3 - local_0)) >> 2);
        *((s32 *) (((s8 *) local_2) + 8)) = (s32) ((*((s32 *) (((s8 *) local_2) + 8))) + 1);
      }
      local_3 += 4;
    }
    while (((u32) local_3) < ((u32) local_1));
  }
  return local_2;
}

void vpglow_entrypoint_1(void* arg0) 
{
    heap_free(arg0);
}
void vpglow_entrypoint_2(GlowState1446 *param_0, GlowMesh1446 *param_1)
{
    s32 local_0;
    GlowDirty1446 *local_1;
    s16 *local_2;

    param_0->value += param_0->speed * func_800D8FF8();
    if (param_0->value >= 1.0f) {
        param_0->value = 1.0f;
        param_0->speed = -param_0->speed;
    } else if (param_0->value < 0.3f) {
        param_0->value = 0.3f;
        param_0->speed = -param_0->speed;
    }
    local_1 = (GlowDirty1446 *)((u8 *)param_1 + param_1->offset);
    local_0 = 0;
    if (param_0->count > 0) {
        local_2 = param_0->indices;
        do {
            local_1[*local_2].dirty = 1;
            local_0++;
            local_2++;
        } while (local_0 < param_0->count);
    }
}

void vpglow_entrypoint_3(f32 *param_0, s32 param_1, Vtx *param_2, s32 param_3)
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
