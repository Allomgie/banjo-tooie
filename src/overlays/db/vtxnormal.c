#include "common.h"

s32 dbvtxnormal_entrypoint_0(s32 param_0, s32 param_1){
    return param_0 + (param_1 * 4);
}

void dbvtxnormal_entrypoint_1(void* arg0) 
{
    heap_free(arg0);
}
s32 dbvtxnormal_entrypoint_2(void *arg)
{
  s32 dst;
  s32 size;

  size = func_800B2344(func_800B2840()) * 4;
  dst = heap_alloc(size);
  aligned4_memcpy(dst, func_800B27A0(arg), size);
  return dst;
}
