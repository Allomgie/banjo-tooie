#include "common.h"

extern s32 B_80800160_sufade;
extern s32 D_80127EF4;

void sufade_entrypoint_0(s32 param_0, u8 *param_1)
{
  u8 *temp_v0;
  if (((void *) D_80127EF4) == 0)
  {
    D_80127EF4 = vector_new(4, 1, param_1);
  }
  temp_v0 = vector_push_back(((void * *) &D_80127EF4));
  *((s8 *) (((s8 *) temp_v0) + 0)) = (s8) (*((s32 *) (((s8 *) param_1) + 0)));
  *((s8 *) (((s8 *) temp_v0) + 1)) = (s8) (*((s32 *) (((s8 *) param_1) + 4)));
  *((s8 *) (((s8 *) temp_v0) + 2)) = (s8) (*((s32 *) (((s8 *) param_1) + 8)));
  *((s8 *) (((s8 *) temp_v0) + 3)) = (s8) param_0;
  if (!((void *) D_80127EF4))
  {
  }
 if (0) { }
}

void sufade_entrypoint_1(s32 param_0) {
    u32 local_0;
    u32 local_1;

    local_1 = vector_begin(D_80127EF4);
    local_0 = vector_end(D_80127EF4);
    if (local_1 < local_0) {
        do {
            (*(s32 *)((s8 *)(&B_80800160_sufade) + (0))) = (s32) (*(u8 *)((s8 *)(local_1) + (0)));
            (*(s32 *)((s8 *)(&B_80800160_sufade) + (4))) = (s32) (*(u8 *)((s8 *)(local_1) + (1)));
            (*(s32 *)((s8 *)(&B_80800160_sufade) + (8))) = (s32) (*(u8 *)((s8 *)(local_1) + (2)));
            func_800B99CC(param_0, (*(u8 *)((s8 *)(local_1) + (3))), &B_80800160_sufade);
            local_1 += 4;
        } while (local_1 < local_0);
    }
    vector_clear(D_80127EF4);
}

s32 sufade_entrypoint_2(void){
    if(D_80127EF4 != 0){
        vector_free(D_80127EF4);
        D_80127EF4 = 0;
    }
}
