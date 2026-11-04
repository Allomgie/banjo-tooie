// Probably the heap-defrag hook that re-bases the three vectors in D_80127EF0,
// which seem to belong to the lights overlay.
#include "core2/1E8DC70.h"

extern s32 D_80127EF0[3];

// Heap defrag hook for the three vectors of the lights overlay.
void func_800B4380(void)
{
    s32 i;
    s32 vec;

    for (i = 0; i < 3; i++) {
        vec = D_80127EF0[i];
        if (vec != 0) {
            D_80127EF0[i] = vector_defrag(vec);
        }
    }
}
