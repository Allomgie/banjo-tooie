#include "core2/1ECD070.h"

typedef struct {
    f32 x, y;
} LocalEntry;
extern f32 func_800F10B4(f32, f32, f32, f32, f32);

// Evaluates a piecewise-linear curve: binary search in a sorted (x, y) table, then a
// clamped remap between the bracketing points. Outside the table it uses the last and
// first points, which clamps to the end values.
f32 func_800F3780(f32 x, LocalEntry *table, s16 count)
{
    s32 lo;
    s32 hi;
    s32 mid;
    hi = count - 1;
    lo = 0;
    if (x < table[0].x) {
        lo = count - 1;
        hi = 0;
    } else if ((count + table - 1)->x < x) {
        lo = count - 1;
        hi = 0;
    } else {
        while (lo + 1 < hi) {
            mid = (hi - lo) / 2 + lo;
            if ((mid + table)->x <= x)
                lo = mid;
            else
                hi = mid;
        }
    }
    return func_800F10B4(x, (lo + table)->x, (hi + table)->x,
                         (lo + table)->y, (hi + table)->y);
}
