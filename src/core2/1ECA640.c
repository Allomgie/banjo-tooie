// Scalar math helpers: clamps, angle wrapping, remap and lerp, easing, periodic waves,
// power, approach-by-step and countdown timer.
#include "core2/1ECA640.h"

extern f32 func_80013970(f32);
extern f32 func_800138D0(f32);
extern f32 func_800F2108(void);
extern f32 func_8001395C(f32);
extern f32 func_800F1DCC(f32, f32);
f32 func_800F13C4(f32 param_0, f32 param_1);
f32 func_800F1434(f32 param_0);
void func_800F14AC(f32 param_0);

// Clamp/min/max, angle wrapping, remap/lerp/ease/smoothstep, fmod, pow, approach.
// Clamp value to [min, max].
f32 func_800F0D50(f32 value, f32 min, f32 max)
{
    if (value < min) {
        return min;
    } else if (max < value) {
        return max;
    } else {
        return value;
    }
}

// Clamp value to [min, max] (integer).
func_800F0D90(s32 value, s32 min, s32 max)
{
    if (value < min)
        return min;
    if (max < value)
        return max;
    return value;
}

// Clamp value to [-limit, limit].
f32 func_800F0DC0(f32 value, f32 limit)
{
    if (limit < value) {
        return limit;
    } else {
        f32 neg_limit = -limit;
        if (neg_limit > value) {
            return neg_limit;
        } else {
            return value;
        }
    }
}

// Float max.
f32 func_800F0E00(f32 a, f32 b)
{
    f32 second;
    int is_less;
    f32 first;
    f32 result;
    // Matching: the copies and the comma expression are needed for the match.
    second = b;
    first = a;
    is_less = second < (0, first);
    if (is_less) {
        result = first;
    } else {
        result = second;
    }
    return result;
}

// Integer max.
func_800F0E28(s32 a, s32 b)
{
    return (b < a) ? a : b;
}

// Wraps an angle in degrees into [0, 360).
func_800F0E44(angle)
{
    while (angle < 0) {
        angle += 0x168;
    }

    while (angle >= 0x168) {
        angle -= 0x168;
    }

    // Matching: the no-op "| 0" is needed for the match.
    return angle | 0;
}

// Wraps angle by 360 degree steps to within 180 degrees of reference.
f32 func_800F0E7C(f32 angle, f32 reference)
{
    if (reference + 180.0f < angle) {
        do {
            angle -= 360.0f;
        } while (reference + 180.0f < angle);
    }
    if (angle < reference - 180.0f) {
        do {
            angle += 360.0f;
        } while (angle < reference - 180.0f);
    }
    return angle;
}

// Unwraps an array of keyframes (3 angles each) so every angle is within 180 degrees of the
// same angle in the previous keyframe.
void func_800F0EF0(s32 count, f32 *angles)
{
    f32 prev;
    s32 i;
    f32 *cur;
    i = 0;
    if (((count * 3) - 3) > 0) {
        cur = angles;
        do {
            prev = cur[0];
            i += 1;
            if ((cur[3] + 180.0f) <= prev) {
                do {
                    cur[3] = (f32) (cur[3] + 360.0f);
                } while ((cur[3] + 180.0f) <= prev);
            }
            if (prev <= (cur[3] - 180.0f)) {
                do {
                    cur[3] = (f32) (cur[3] - 360.0f);
                } while (prev <= (cur[3] - 180.0f));
            }
            cur += 1;
        } while (i != ((count * 3) - 3));
    }
}

// Position within the period as a fraction.
f32 func_800F0F9C(f32 time, f32 period)
{
    f32 rem;
    rem = func_800F13C4(time, period);
    return rem / period;
}

// Periodic wave over the period, scaled to 0..1.
f32 func_800F0FC4(f32 time, f32 period)
{
    return (func_80013970(func_800F13C4(time, period) / period * 360.0f) + 1.0f) * 0.5f;
}

// Periodic wave over the period, scaled to 0..1.
f32 func_800F101C(f32 time, f32 period)
{
    return (func_800138D0(func_800F13C4(time, period) / period * 360.0f) + 1.0f) * 0.5f;
}

// Periodic wave over the period.
f32 func_800F1074(f32 time, f32 period)
{
    return func_80013970(func_800F13C4(time, period) / period * 360.0f);
}

// Linear remap from [in_min, in_max] to [out_min, out_max], clamped to the output range.
f32 func_800F10B4(f32 value, f32 in_min, f32 in_max, f32 out_min, f32 out_max)
{
    f32 result;
    if (in_max != in_min) {
        if (out_min < out_max) {
            result = (value - in_min) / (in_max - in_min) * (out_max - out_min) + out_min;
            if (result > out_max) {
                return out_max;
            } else if (result < out_min) {
                return out_min;
            }
        } else {
            result = (value - in_min) / (in_max - in_min) * (out_max - out_min) + out_min;
            if (result < out_max) {
                return out_max;
            } else if (result > out_min) {
                return out_min;
            }
        }
        return result;
    }
    return out_max;
}

// Linear remap without clamping.
f32 func_800F1198(f32 value, f32 in_min, f32 in_max, f32 out_min, f32 out_max)
{
    if (in_max != in_min) {
        return (((value - in_min) / (in_max - in_min)) * (out_max - out_min)) + out_min;
    }
    return out_max;
}

// Linear remap without clamping or the zero-range check.
f32 func_800F11E4(f32 value, f32 in_min, f32 in_max, f32 out_min, f32 out_max)
{
    f32 offset;
    f32 range;

    offset = value - in_min;
    range = in_max - in_min;
    return ((offset / range) * (out_max - out_min)) + out_min;
}

// Lerp from min to max by t.
f32 func_800F1214(f32 t, f32 min, f32 max)
{
    return ((max - min) * t) + min;
}

f32 func_800F122C(f32 param_0, f32 param_1, f32 param_2)
{
    f32 rnd = func_800F2108();
    param_0 *= rnd;
    rnd *= (param_2 - param_1) * param_0 + param_1;
    return rnd;
}

// Remaps value to 0..1, applies the easing function, then maps the result to [out_min, out_max].
f32 func_800F1274(f32 value, f32 in_min, f32 in_max, f32 out_min, f32 out_max, f32 (*ease)(f32))
{
    f32 t = func_800F10B4(value, in_min, in_max, 0.0f, 1.0f);
    t = ease(t);
    func_800F10B4(t, 0.0f, 1.0f, out_min, out_max);
}

// Remap with cosine easing.
f32 func_800F12D4(f32 value, f32 in_min, f32 in_max, f32 out_min, f32 out_max)
{
    return func_800F1274(value, in_min, in_max, out_min, out_max, func_800F1434);
}

// Remap with the cosine easing applied twice.
f32 func_800F130C(f32 value, f32 in_min, f32 in_max, f32 out_min, f32 out_max)
{
    return func_800F1274(value, in_min, in_max, out_min, out_max, func_800F14AC);
}

// Clamped remap that mirrors the ranges for negative values.
void func_800F1344(f32 value, f32 in_min, f32 in_max, f32 out_min, f32 out_max)
{
    if (value < 0.0f) {
        func_800F10B4(value, -in_min, -in_max, -out_min, -out_max);
    } else {
        func_800F10B4(value, in_min, in_max, out_min, out_max);
    }
}

// fmod
f32 func_800F13C4(f32 value, f32 divisor)
{
    f32 quotient;

    quotient = value / divisor;
    return (quotient - (f32) (s32) quotient) * divisor;
}

// Float min.
f32 func_800F13F0(f32 a, f32 b)
{
    f32 result;
    if (a < b)
        result = a;
    else
        result = b;

    return result;
}

// Integer min.
s32 func_800F1418(s32 a, s32 b)
{
    return a < b ? a : b;
}

// Cosine ease in/out for t in 0..1.
f32 func_800F1434(f32 t)
{
    return (func_8001395C(t * 3.1415927f + -1.5707964f) + 1.0f) * 0.5f;
}

int func_800F1480(f32 t)
{
    func_80013970(t * 90.0f);
}

void func_800F14AC(f32 t)
{
    f32 eased;
    eased = func_800F1434(t);
    func_800F1434(eased);
}

// Float min.
f32 func_800F14D4(f32 a, f32 b)
{
    f32 result;
    if (a <= b) {
        result = a;
    } else {
        result = b;
    }
    return result;
}

// Smoothstep.
f32 func_800F14FC(f32 edge_min, f32 edge_max, f32 x)
{
    f32 t;
    if (x < edge_min) {
        return 0.0f;
    }
    if (edge_max <= x) {
        return 1.0f;
    }
    t = (x - edge_min) / (edge_max - edge_min);
    return (t * t) * (3.0f - (2.0f * t));
}

// Generic countdown.
// Counts the timer down by delta; returns TRUE once it reaches zero.
int func_800F1574(f32 *timer, f32 delta)
{
    if (*timer > 0) {
        *timer -= delta;

        if (*timer <= 0) {
            *timer = 0;
            return TRUE;
        }
    }

    return FALSE;
}

// Power by squaring.
f32 func_800F15C4(f32 base, u32 power)
{
    f32 result;
    result = 1.0f;
    while (power != 0) {
        if (power & 1) {
            result *= base;
        }
        base *= base;
        // Matching: the cast on the shift target is needed for the match.
        (s32) power >>= 1;
    }
    return result;
}

// Moves value toward target by at most step.
f32 func_800F15F8(f32 value, f32 target, f32 step)
{
    if (value < target) {
        return func_800F13F0(value + step, target);
    }
    if (target < value) {
        return func_800F0E00(value - step, target);
    }
    return value;
}

// Returns whether |a| > |b|.
s32 func_800F1660(f32 a, f32 b)
{
    if (a < 0.0f)
        a = -a;
    if (b < 0.0f)
        b = -b;
    return b < a;
}

// Per-component angle interpolation from from_angles toward to_angles.
void func_800F16AC(f32 *out, f32 *from_angles, f32 *to_angles, f32 factor)
{
    f32 *src = from_angles;
    s32 i = 0;
    f32 *target = to_angles;
    f32 *dst = out;
    for (; i < 3; i++) {
        *dst = *src - func_800F1DCC(*src, *target) * factor;
        src++;
        target++;
        dst++;
    }
}

// Clamps angle to the arc from range_start to range_end.
f32 func_800F1738(f32 angle, f32 range_start, f32 range_end)
{
    f32 angle_offset;
    f32 end_offset;
    angle_offset = func_800F1DCC(angle, range_start);
    end_offset = func_800F1DCC(range_end, range_start);
    if (end_offset > 0.0f) {
        if (angle_offset < 0.0f)
            angle = range_start;
        else if (end_offset < angle_offset)
            angle = range_end;
    } else {
        if (angle_offset > 0.0f)
            angle = range_start;
        else if (angle_offset < end_offset)
            angle = range_end;
    }
    return angle;
}
