#include "core2/1ECD070.h"

typedef struct { f32 x, y; } LocalEntry;
extern f32 func_800F10B4(f32,f32,f32,f32,f32);

f32 func_800F3780(f32 param_0, LocalEntry *param_1, s16 param_2)
{
    s32 local_0;
    s32 local_1;
    s32 local_2;
    local_1 = param_2 - 1;
    local_0 = 0;
    if (param_0 < param_1[0].x) { local_0 = param_2-1; local_1 = 0; }
    else if ((param_2 + param_1 - 1)->x < param_0) { local_0 = param_2-1; local_1 = 0; }
    else {
        while (local_0 + 1 < local_1) {
            local_2 = (local_1 - local_0) / 2 + local_0;
            if ((local_2 + param_1)->x <= param_0) local_0 = local_2;
            else local_1 = local_2;
        }
    }
    return func_800F10B4(param_0, (local_0 + param_1)->x, (local_1 + param_1)->x, (local_0 + param_1)->y, (local_1 + param_1)->y);
}
