#include "core2/1ECB0F0.h"

extern f32 func_80013AAC(f32);
extern f32 func_80013B7C(f32, f32);
extern f32 func_80013B70(f32, f32, f32);
extern void func_800EFD24(f32 *);
extern f32 func_800F10B4(f32, f32, f32, f32, f32);
extern f32 func_800EEF94(s32);
extern s32 func_800EE97C(s32 *, s32, s32 *);
extern f32 mlAbsF(f32);
extern void func_80013728(f32);
f32 func_800136E4(f32 param_0);

// Absolute value of the arc function (func_80013AAC) of the input.
f32 func_800F1800(f32 value)
{
    return mlAbsF(func_80013AAC(value));
}

// Pitch from one point to another.
f32 func_800F1828(f32 *from, f32 *to)
{
    float xz_dist_sq;
    f32 dy;
    f32 dx;
    f32 dz;
    dx = to[0] - from[0];
    dy = to[1] - from[1];
    dz = to[2] - from[2];
    xz_dist_sq = (dx * dx) + (dz * dz);
    return func_80013B7C(dy, sqrtf(xz_dist_sq));
}

// Pitch of a vector; returns 0 (and pitch 0) when it has no XZ length.
s32 func_800F1884(u8 *vec, f32 *out_pitch)
{
    f32 z;
    f32 xz_len;
    f32 x;
    z = *(f32 *) ((s8 *) vec + 8);
    x = *(f32 *) ((s8 *) vec + 0);
    xz_len = sqrtf((z * z) + (x * x));
    if (xz_len == 0.0f) {
        *out_pitch = 0.0f;
        return 0;
    }
    *out_pitch = func_80013B7C(*(f32 *) ((s8 *) vec + 4), xz_len);
    return 1;
}

// Pitch (angles[0]) and yaw (angles[1]) from one point to another.
void func_800F18FC(f32 *from, f32 *to, f32 *angles)
{
    f32 dx, dy, dz;
    f32 dist;

    dx = to[0] - from[0];
    dy = to[1] - from[1];
    dz = to[2] - from[2];

    dist = sqrtf(dx * dx + dz * dz);

    angles[1] = func_80013B70(dx, dz, dist);
    angles[0] = func_80013B7C(dy, dist);
}

// Splits a vector into yaw and magnitude; returns 0 when the XZ length is below 0.01.
int func_800F1988(f32 *vec, f32 *out_mag, f32 *out_yaw)
{
    f32 xz_len;
    *out_mag = 0.0f;
    *out_yaw = 0.0f;
    xz_len = sqrtf(vec[2] * vec[2] + vec[0] * vec[0]);
    if (xz_len < 0.01f)
        return 0;
    *out_yaw = func_800F1800(vec[0] / xz_len);
    if (vec[2] < 0.0f)
        *out_yaw = 180.0f - *out_yaw;
    if (vec[0] < 0)
        *out_yaw = 360.0f - *out_yaw;
    *out_mag = func_800F1800(xz_len);
    return 1;
}

// Yaw (angles[1]) and pitch (angles[0]) of a vector.
void func_800F1A88(f32 *vec, f32 *angles)
{
    f32 len = sqrtf(vec[0] * vec[0] + vec[2] * vec[2]);
    angles[1] = func_80013B70(vec[0], vec[2], len);
    angles[0] = func_80013B7C(vec[1], len);
}

// Same as func_800F1A88, and sets angles[2] to 0.
void func_800F1AFC(f32 *vec, f32 *angles)
{
    f32 len = sqrtf(vec[0] * vec[0] + vec[2] * vec[2]);
    angles[1] = func_80013B70(vec[0], vec[2], len);
    angles[0] = func_80013B7C(vec[1], len);
    angles[2] = 0.0f;
}

// Maps a stick-like vector into a velocity relative to the facing yaw.
int func_800F1B78(f32 *out_vel, f32 *stick, f32 facing_yaw, f32 scale)
{
    f32 mag;
    f32 stick_yaw;
    f32 abs_diff;
    f32 yaw_diff;
    s32 has_dir;
    func_800EFD24(out_vel);
    has_dir = func_800F1988(stick, &mag, &stick_yaw);
    mag *= scale;
    if (has_dir) {
        yaw_diff = func_800F1DCC(facing_yaw, stick_yaw);
        abs_diff = mlAbsF(yaw_diff);
        out_vel[0] = func_800F10B4(abs_diff, 0.0f, 180.0f, mag, -mag);
        if (abs_diff < 90.0f)
            out_vel[2] = func_800F10B4(abs_diff, 0.0f, 90.0f, 0.0f, mag);
        else
            out_vel[2] = func_800F10B4(abs_diff, 90.0f, 180.0f, mag, 0.0f);
        if (yaw_diff < 0.0f)
            out_vel[2] = -out_vel[2];
    }
    return has_dir;
}

// Sine of the angle between two vectors.
f32 func_800F1C98(s32 a, s32 *b)
{
    f32 len_a;
    f32 len_b;
    s8 _sfpad[8];
    s32 cross;

    len_a = func_800EEF94(a);
    len_b = func_800EEF94((s32) b);
    func_800EE97C(&cross, a, b);
    return func_800EEF94((s32) &cross) / (len_a * len_b);
}

// Sine of the angle between two vectors in the XZ plane (signed); 0 for near-zero lengths.
f32 func_800F1CF0(f32 *a, f32 *b)
{
    f32 prod;
    f32 cross_z;
    f32 abs_cross;
    f32 len0;
    f32 denom;
    f32 len1;
    len0 = sqrtf((a[2] * a[2]) + (a[0] * a[0]));
    len1 = sqrtf((b[0] * b[0]) + (b[2] * b[2]));
    prod = len1 * len0;
    if (1e-06f < prod) {
        cross_z = (a[2] * b[0]) - (a[0] * b[2]);
        abs_cross = mlAbsF(cross_z);
        // Matching: the redundant assignments to denom are needed for the match.
        if (prod < abs_cross) {
            denom = (prod = abs_cross);
        }
        denom = prod;
        return cross_z / denom;
    }
    return 0.0f;
}

// Signed shortest angle from `from` to `to`, wrapped by func_80013728.
// Matching: no return statement, the callee's result is passed through; the copies and chained assignments are needed for the match.
f32 func_800F1DCC(f32 to, f32 from)
{
    f32 delta;
    f32 to_copy;
    f32 from_copy;
    to_copy = to;
    from_copy = from;

    from_copy = (delta = (1.0f * to_copy) - (delta = (delta = from_copy)));
    func_80013728(delta);
}

// Yaw from one point to another.
// Matching: the line breaks in this function are needed for the match.
f32 func_800F1DF4(f32 from[3], f32 to[3])
{
    f32 dz;
    float dx;
    f32 dx_copy;
    dx = to[0] - from[0]; dz = to[2] - from[2]; dx_copy = dx;
    return func_80013B7C(dx_copy, dz);
}

// Yaw between two s16 points (x at +0, z at +4).
// Matching: no return statement, the callee's result is passed through.
void func_800F1E28(u8 *from, u8 *to)
{
    func_80013B7C((f32) (*(s16 *) ((s8 *) to + 0) - *(s16 *) ((s8 *) from + 0)),
                  (f32) (*(s16 *) ((s8 *) to + 4) - *(s16 *) ((s8 *) from + 4)));
}

// Yaw from one point to another; returns whether they differ in XZ.
// Matching: no return statement, the callee's result is passed through.
s32 func_800F1E6C(f32 from[3], f32 to[3], f32 *out_yaw)
{
    f32 delta[3];
    func_800EFB24(delta, to, from);
    func_800F1EA4(delta, out_yaw);
}

// Yaw of a vector in the XZ plane; yaw 0 and return 0 for a zero vector.
s32 func_800F1EA4(f32 vec[3], f32 *out_yaw)
{
    if ((vec[0] != 0.0f) || (vec[2] != 0.0f)) {
        *out_yaw = func_80013B7C(vec[0], vec[2]);
        return 1;
    } else {
        *out_yaw = 0.0f;
        return 0;
    }
}

// Angle from `ref_yaw` to the yaw from one point to another.
// Matching: no return statement, the callee's result is passed through.
void func_800F1F0C(s32 from, s32 to, f32 ref_yaw)
{
    f32 yaw = func_800F1DF4(from, to);
    func_800F1DCC(yaw, ref_yaw);
}

// Turns `current` toward `target` by at most `max_step`.
f32 func_800F1F38(f32 current, f32 target, f32 max_step)
{
    f32 delta;
    if (target == current)
        return target;
    delta = func_800F1DCC(target, current);
    delta = delta > 0.0f ? (delta < max_step ? delta : max_step)
                         : (-max_step < delta ? delta : -max_step);
    return func_800136E4(current + delta);
}

// Turns `current` toward `target` by factor * difference, capped at `max_step`; snaps to `target` inside the dead zone.
f32 func_800F1FF0(f32 current, f32 target, f32 factor, f32 dead_zone, f32 max_step)
{
    f32 step;
    f32 abs_step;

    step = func_800F1DCC(target, current) * factor;
    abs_step = mlAbsF(step);
    if (abs_step < dead_zone) {
        return target;
    }
    if (max_step < abs_step) {
        if (step < 0.0f) {
            step = -max_step;
        } else {
            step = max_step;
        }
    }
    return func_800136E4(current + step);
}

// Absolute angle difference.
f32 func_800F2094(f32 to, f32 from)
{
    return mlAbsF(func_800F1DCC(to, from));
}

// True when the angle difference is below `tolerance`.
s32 func_800F20BC(f32 to, f32 from, f32 tolerance)
{
    return func_800F2094(to, from) < tolerance;
}
