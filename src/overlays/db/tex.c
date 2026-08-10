#include "common.h"

u8 *dbtex_entrypoint_0(u8 *param_0)
{
  s32 *local_0;
  s32 local_1;
  u8 *local_2;
  u8 *local_3;
  u8 *local_4;
  if (param_0 == 0)
  {
    return 0;
  }
  if (!((*((s16 *) (((char *) param_0) + 6))) & 0x100))
  {
    return 0;
  }
  local_1 = ((*((s16 *) (((char *) param_0) + 4))) * 8) + 8;
  local_3 = heap_alloc_sided((*((s32 *) (((char *) param_0) + 0))) + local_1, 1);
  rare_memcpy(local_3, param_0, local_1);
  local_0 = (s32 *) (local_3 + 8);
  local_2 = 8 + (((*((s16 *) (((char *) local_3) + 4))) * 8) + local_3);
  local_4 = local_2;
  if (((u32) local_0) < ((u32) local_2))
  {
    do
    {
      func_800E6950((*local_0) + 0x1EF6, 0, local_4);
      local_4 += func_800D5944();
      local_0 += 2;
    }
    while (((u32) local_0) < ((u32) local_2));
  }
  return local_3;
}

s32 dbtex_entrypoint_1(void *texture){
    if(texture != 0){
        heap_free(texture);
    }
}
