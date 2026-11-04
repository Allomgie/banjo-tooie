// Model vertex-normal array helpers: index into the array, copy it to the heap, free the copy.
#include "common.h"

// Address of the normal of vertex `index` (4 bytes each).
s32 dbvtxnormal_entrypoint_0(s32 normals, s32 index)
{
    return normals + (index * 4);
}

// Free a normal array copy.
void dbvtxnormal_entrypoint_1(void *normals)
{
    heap_free(normals);
}

// Heap copy of the model's normal array.
s32 dbvtxnormal_entrypoint_2(void *model)
{
    s32 dst;
    s32 size;

    size = func_800B2344(func_800B2840()) * 4;
    dst = heap_alloc(size);
    aligned4_memcpy(dst, func_800B27A0(model), size);
    return dst;
}
