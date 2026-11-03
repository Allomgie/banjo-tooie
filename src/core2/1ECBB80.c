#include "common.h"

extern f32 func_800137F4(f32);
extern f32 func_80013788(void);
f32 mlAbsF(f32);

// 2D cross product (x at +0, y at +4).
f32 func_800F2290(u8 *a, u8 *b)
{
    return (*(f32 *) ((s8 *) a + 0) * *(f32 *) ((s8 *) b + 4)) -
           (*(f32 *) ((s8 *) a + 4) * *(f32 *) ((s8 *) b + 0));
}

// Unit vector from an angle.
void func_800F22B4(f32 *out, f32 angle)
{
    out[0] = func_800137F4(angle);
    out[1] = func_80013788();
}

// Length of a 2D vector.
// Matching: no return statement, the callee's result is passed through.
void func_800F22EC(u8 *vec)
{
    f32 y;
    f32 x;

    y = *(f32 *) ((s8 *) vec + 4);
    x = *(f32 *) ((s8 *) vec + 0);
    sqrtf((y * y) + (x * x));
}

// Octagonal approximation of the length of a 2D vector.
f32 func_800F2320(f32 vec[3])
{
    f32 abs_x = mlAbsF(vec[0]);
    f32 abs_y = mlAbsF(vec[1]);
    f32 min;
    if (abs_x < abs_y) {
        min = abs_x;
    } else {
        min = abs_y;
    }
    return abs_x + abs_y - min * 0.41421357f;
}

// out = a - b
func_800F2388(f32 *out, f32 a[3], f32 b[3])
{
    out[0] = a[0] - b[0];
    out[1] = a[1] - b[1];
}

// Perpendicular vector: (y, -x).
func_800F23AC(f32 *out, f32 vec[3])
{
    out[0] = vec[1];
    out[1] = -vec[0];
}
