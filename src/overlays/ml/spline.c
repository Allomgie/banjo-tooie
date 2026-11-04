// Spline maths (mlspline): linear and quadratic evaluators, Catmull-Rom and clamped cubic
// B-spline positions with derivatives, plus Simpson and Newton arc-length stepping.
#include "common.h"

extern f32 func_800F0D50(f32, f32, f32);
extern void func_800EE7F8(f32 *, f32 *);
extern f32 func_800EEF94(f32[3]);
typedef void (*SplineFn)(f32, s32, f32 *, f32 *);
extern f32 mlAbsF(f32);

// Linear interpolation of two 3D points.
void mlspline_entrypoint_0(f32 t, s32 count, f32 points[2][3], f32 out[3])
{
    s32 i;
    f32 *src;
    f32 *dst;

    for (i = 0, src = points[0], dst = out; i < 3;
         i++, src++, dst++) {
        *dst = src[0] + (src[3] - src[0]) * t;
    }
}

// Linear interpolation of two 1D values.
void mlspline_entrypoint_1(f32 t, s32 count, f32 *points, f32 *out)
{
    f32 p0;
    f32 p1;

    p0 = points[0];
    p1 = points[1];
    *out = (p1 - p0) * t + p0;
}

// Quadratic interpolation of three 3D points.
void mlspline_entrypoint_2(f32 t, s32 count, f32 points[][3], f32 *out)
{
    s32 i;
    f32 a;
    f32 b;
    f32 c;

    for (i = 0; i < 3; i++) {
        a = points[0][i];
        b = points[1][i];
        c = points[2][i];
        out[i] = ((c + a) - 2.0f * b) * (t + t) + ((4.0f * b - 3.0f * a) - c);
        // Matching: empty block steers IDO's register allocation.
        if (1) {
        }
        out[i] *= t;
        out[i] += a;
    }
}

// Quadratic interpolation of three 1D values.
void mlspline_entrypoint_3(f32 t, s32 count, u8 *points, f32 *out)
{
    f32 a;
    f32 c;
    f32 b;

    a = *(f32 *) ((s8 *) points + 0);
    b = *(f32 *) ((s8 *) points + 4);
    c = *(f32 *) ((s8 *) points + 8);
    *out = (((((c + a) - (2.0f * b)) * (2.0f * t)) +
                 (((4.0f * b) - (3.0f * a)) - c)) *
                t) +
               a;
}

// Catmull-Rom position along a multi-point 3D path; t in [0, 1].
// Matching: k0/k1, the extra temporaries and the trailing continue statements are needed for the match.
void mlspline_entrypoint_4(f32 t, s32 count, f32 points[][3], volatile f32 *out)
{
    s32 idx;
    s32 last;
    f32 scaled;
    f32 p0;
    f32 p0_b;
    f32 p1;
    f32 p2;
    f32 p2_b;
    f32 p3;

    s32 k0 = 2;
    s32 k1 = 3;
    f32 p1_tmp;
    f32 p0_tmp;
    last = count - 1;
    scaled = func_800F0D50(t, 0.0f, 1.0f) * last;
    idx = scaled;
    t = scaled - idx;

    if (idx == 0) {
        for (; idx < 3; idx++) {
            p0 = points[0][idx];
            p1_tmp = points[1][idx];
            p1 = p1_tmp;
            p2 = points[2][idx];
            out[idx] = ((p2 - p0) * 0.5f + (p0 - p1) * 1.5f) * t +
                               ((2.0f * p1 - p2 * 0.5f) - 1.5f * p0);
            out[idx] *= t;
            out[idx] += (p1 - p0) * 0.5f;
            out[idx] *= t;
            out[idx] += p0;
            continue;
        }
    } else {
        idx--;
        if (count == idx + k0) {
            points = (f32(*)[3])((f32 *) points + (count - 1) * 3);
            func_800EE7F8(out, (f32 *) points);
            return;
        }
        points = (f32(*)[3])((f32 *) points + idx * 3);
        if (count == idx + k1) {
            for (idx = 0; idx < 3; idx++) {
                p0_tmp = points[0][idx];
                p0 = p0_tmp;
                p1 = points[1][idx];
                p2_b = points[2][idx];
                out[idx] =
                    ((p2_b - p0) * 0.5f + (p1 - p2_b) * 1.5f) * t +
                    (p0 - p1 * 2.5f + p2_b * 1.5f);
                out[idx] *= t;
                out[idx] += (p2_b - p0) * 0.5f;
                out[idx] *= t;
                out[idx] += p1;
                continue;
            }
        } else {
            for (idx = 0; idx < 3; idx++) {
                p0_b = points[0][idx];
                p1 = points[1][idx];
                p2 = points[2][idx];
                p3 = points[3][idx];
                out[idx] =
                    ((p3 - p0_b) * 0.5f + (p1 - p2) * 1.5f) * t +
                    ((p0_b - p1 * 2.5f + 2.0f * p2) - p3 * 0.5f);
                out[idx] *= t;
                out[idx] += (p2 - p0_b) * 0.5f;
                out[idx] *= t;
                out[idx] += p1;
                continue;
            }
        }
    }
}

// Clamped uniform cubic B-spline position along a 3D path; t in [0, 1].
void mlspline_entrypoint_5(f32 t, s32 count, f32 points[][3], volatile f32 *out)
{
    s32 idx;
    s32 last = count - 1;
    f32 scaled;
    f32 p0;
    f32 p1;
    f32 p2;
    f32 p3;
    f32 p0_tmp;
    f32 p2_tmp;
    f32 p1_b;
    f32 p1_c;
    s32 k1 = 3;
    s32 j;
    f32 sum;

    scaled = func_800F0D50(t, 0.0f, 1.0f) * last;
    idx = scaled;
    t = scaled - idx;
    if (idx == 0) {
        for (; idx < 3; idx++) {
            p0 = points[0][idx];
            p1 = points[1][idx];
            p2_tmp = points[2][idx];
            p2 = p2_tmp;
            out[idx] =
                ((p2 - p0) * 0.16666667f - (p1 - p0) * 0.5f) * t +
                (p1 - p0) * 0.5f;
            out[idx] *= t;
            out[idx] += (p1 - p0) * 0.5f;
            out[idx] *= t;
            out[idx] += (p0 * 5.0f + p1) * 0.16666667f;
            // Matching: empty block triggers the byte-offset loop test.
            if (points) {
            }
        }
        return;
    }
    idx--;
    if (count - 2 == idx) {
        func_800EE7F8(out, &((f32 *) points)[(count - 1) * 3]);
        return;
    }
    points = (f32(*)[3])((f32 *) points + idx * 3);
    if (count == idx + k1) {
        for (idx = 0; idx != 3; idx++) {
            p0_tmp = points[0][idx];
            p0 = p0_tmp;
            p2 = points[2][idx];
            p1_b = points[1][idx];
            sum = p0 + p2;
            out[idx] =
                ((p2 - p0) * 0.16666667f + (p1_b - p2) * 0.5f) * t +
                (sum * 0.5f - p1_b);
            out[idx] *= t;
            out[idx] += (p2 - p0) * 0.5f;
            out[idx] *= t;
            out[idx] += sum * 0.16666667f + p1_b * 0.6666667f;
            // Matching: dead reload at the loop end is needed for the match.
            p0 = points[0][idx];
        }
        return;
    }
    for (idx = 0; idx != 3; idx++) {
        p0 = points[0][idx];
        p1_c = points[1][idx];
        p2 = points[2][idx];
        p3 = points[3][idx];
        out[idx] = ((p3 - p0) * 0.16666667f + (p1_c - p2) * 0.5f) * t;
        out[idx] += (p0 + p2) * 0.5f - p1_c;
        // Matching: the copy j of idx is needed for the match.
        j = idx;
        out[j] *= t;
        out[j] += (p2 - p0) * 0.5f;
        out[j] *= t;
        out[j] += (p0 + p2) * 0.16666667f + p1_c * 0.6666667f;
    }
}

// Linear derivative: difference of the two points.
int mlspline_entrypoint_6(f32 t, s32 count, s32 points, s32 out)
{
    // Matching: `| 0` is needed for the match.
    func_800EFB24(out | 0, points + 0xC);
}

// Derivative of the quadratic 3D evaluator.
void mlspline_entrypoint_7(f32 t, s32 count, f32 points[][3], f32 *out)
{
    s32 i;
    f32 p0;
    f32 p1;
    f32 p2;
    f32 term_a;
    f32 term_b;

    for (i = 0; i != 3; i++) {
        p0 = points[0][i];
        p1 = points[1][i];
        p2 = points[2][i];
        term_a = (p0 - 2.0f * p1 + p2) * (4.0f * t);
        term_b = 4.0f * p1 - 3.0f * p0 - p2;
        out[i] = term_a + term_b;
        // Matching: empty block gives the byte-offset loop test (as in entrypoint_5).
        if (points) {
        }
    }
}

// Derivative of the Catmull-Rom position (entrypoint_4).
void mlspline_entrypoint_8(f32 t, s32 count, f32 *points, volatile f32 *out)
{
    s32 idx;
    s32 last;
    f32 scaled;
    s32 j;
    f32 a;
    f32 b;
    f32 a1;
    f32 b1;
    f32 c1;
    f32 a3;
    f32 b3;
    f32 c3;
    f32 a4;
    f32 b4;
    f32 c4;
    f32 d4;
    s32 k0 = 2;
    s32 k1 = 3;

    last = count - 1;
    scaled = func_800F0D50(t, 0.0f, 1.0f) * last;
    idx = scaled;
    t = scaled - idx;
    if (idx == 0) {
        for (; idx < 3; idx++) {
            a1 = points[idx];
            b1 = points[idx + 3];
            c1 = points[idx + 6];
            out[idx] = (((a1 - b1) * 4.5f + 1.5f * (c1 - a1)) * t) +
                               (((4.0f * b1) - c1) - (3.0f * a1));
            out[idx] *= t;
            out[idx] += 0.5f * (b1 - a1);
        }
        return;
    }
    idx--;
    points += idx * 3;
    if (count == idx + k0) {
        for (idx = 0; idx != 3; idx++) {
            a = points[idx];
            b = points[idx + 3];
            out[idx] = (b - a) * 0.5f;
        }
    } else if (count == idx + k1) {
        for (j = 0; j != 3; j++) {
            a3 = points[j];
            b3 = points[j + 3];
            c3 = points[j + 6];
            out[j] = ((b3 - c3) * 4.5f + 1.5f * (c3 - a3)) * t +
                                 (((a3 + a3) - 5.0f * b3) + 3.0f * c3);
            out[j] *= t;
            out[j] += 0.5f * (c3 - a3);
        }
    } else {
        for (j = 0; j != 3; j++) {
            a4 = points[j];
            b4 = points[j + 3];
            c4 = points[j + 6];
            d4 = points[j + 9];
            out[j] = ((b4 - c4) * 4.5f + 1.5f * (d4 - a4)) * t +
                                 ((((a4 + a4) - 5.0f * b4) + 4.0f * c4) - d4);
            out[j] *= t;
            out[j] += 0.5f * (c4 - a4);
        }
    }
}

// 1D version of entrypoint_4.
// Matching: k0/k1, the extra temporaries and the trailing continue statements are needed for the match.
void mlspline_entrypoint_9(f32 t, s32 count, f32 points[][1], volatile f32 *out)
{
    s32 idx;
    s32 last;
    f32 scaled;
    f32 p0;
    f32 p0_b;
    f32 p1;
    f32 p2;
    f32 p2_b;
    f32 p3;

    s32 k0 = 2;
    s32 k1 = 3;
    f32 p1_tmp;
    f32 p0_tmp;
    last = count - 1;
    scaled = func_800F0D50(t, 0.0f, 1.0f) * last;
    idx = scaled;
    t = scaled - idx;

    if (idx == 0) {
        for (; idx < 1; idx++) {
            p0 = points[0][idx];
            p1_tmp = points[1][idx];
            p1 = p1_tmp;
            p2 = points[2][idx];
            out[idx] = ((p2 - p0) * 0.5f + (p0 - p1) * 1.5f) * t +
                               ((2.0f * p1 - p2 * 0.5f) - 1.5f * p0);
            out[idx] *= t;
            out[idx] += (p1 - p0) * 0.5f;
            out[idx] *= t;
            out[idx] += p0;
            continue;
        }
    } else {
        idx--;
        if (count == idx + k0) {
            points = (f32(*)[1])((f32 *) points + (count - 1) * 1);
            out[0] = points[0][0];
            return;
        }
        points = (f32(*)[1])((f32 *) points + idx * 1);
        if (count == idx + k1) {
            for (idx = 0; idx < 1; idx++) {
                p0_tmp = points[0][idx];
                p0 = p0_tmp;
                p1 = points[1][idx];
                p2_b = points[2][idx];
                out[idx] =
                    ((p2_b - p0) * 0.5f + (p1 - p2_b) * 1.5f) * t +
                    (p0 - p1 * 2.5f + p2_b * 1.5f);
                out[idx] *= t;
                out[idx] += (p2_b - p0) * 0.5f;
                out[idx] *= t;
                out[idx] += p1;
                continue;
            }
        } else {
            for (idx = 0; idx < 1; idx++) {
                p0_b = points[0][idx];
                p1 = points[1][idx];
                p2 = points[2][idx];
                p3 = points[3][idx];
                out[idx] =
                    ((p3 - p0_b) * 0.5f + (p1 - p2) * 1.5f) * t +
                    ((p0_b - p1 * 2.5f + 2.0f * p2) - p3 * 0.5f);
                out[idx] *= t;
                out[idx] += (p2 - p0_b) * 0.5f;
                out[idx] *= t;
                out[idx] += p1;
                continue;
            }
        }
    }
}

// Derivative of the B-spline position (entrypoint_5).
void mlspline_entrypoint_10(f32 t, int count, f32 *points, volatile f32 *out)
{
    s32 idx;
    s32 last = count - 1;
    f32 scaled;
    f32 first;
    f32 slope;
    f32 p0;
    f32 p1;
    f32 p2;
    f32 p3;
    scaled = func_800F0D50(t, 0.0f, 1.0f) * last;
    idx = scaled;
    t = scaled - idx;
    if (idx == 0) {
        for (; idx < 3; idx++) {
            p0 = points[idx];
            p1 = points[idx + 3];
            p2 = points[idx + 6];
            slope = p1 - p0;
            out[idx] =
                ((((p2 - p0) * 0.5f) - ((p1 - p0) * 1.5f)) * t) + slope;
            out[idx] *= t;
            out[idx] += (p1 - p0) * 0.5f;
        }

        return;
    }
    idx--;
    points += idx * 3;
    if (count == (idx + 2)) {
        for (idx = 0; idx != 3; idx++) {
            first = points[idx];
            t = (points[idx + 3] - first) * 0.5f;
            out[idx] = t;
        }

        return;
    }
    if (count == (idx + 3)) {
        for (idx = 0; idx != 3; idx++) {
            p0 = points[idx];
            p2 = points[idx + 6];
            p1 = points[idx + 3];
            slope = (p2 - p0) * 0.5f;
            out[idx] = ((((p1 - p2) * 1.5f) + slope) * t) +
                               ((p0 + p2) - (p1 + p1));
            out[idx] *= t;
            out[idx] += slope;
        }

        return;
    }
    for (idx = 0; idx != 3; idx++) {
        p0 = points[idx];
        p1 = points[idx + 3];
        p2 = points[idx + 6];
        p3 = points[idx + 9];
        out[idx] =
            ((((p3 - p0) * 0.5f) + ((p1 - p2) * 1.5f)) * t) +
            ((p0 + p2) - (p1 + p1));
        out[idx] *= t;
        out[idx] += (p2 - p0) * 0.5f;
    }
}

// Speed (length of the derivative vector) at t.
f32 func_8080145C_mlspline(f32 t, s32 count, f32 *points,
                           void (*fn)(f32, s32, f32 *, f32 *))
{
    f32 vec[3];

    fn(t, count, points, vec);
    return func_800EEF94(vec);
}

// Adaptive Simpson integration of the speed over [lo, hi] (arc length).
f32 func_80801488_mlspline(f32 *pts, s32 cnt, f32 lo, f32 hi, s32 max_iter, f32 tol, SplineFn fn)
{
    // Matching: the unused pad locals are needed for the match.
    s32 pad[2];
    f32 h6;
    f32 f_ends;
    s32 pad2[3];
    f32 simpson;
    f32 prev;
    f32 half;
    f32 old_sum;
    f32 f_mid;
    f32 f_lo;
    f32 h;
    s32 n;
    s32 m;
    s32 i;

    n = 1;
    h = hi - lo;
    h6 = h * 0.1666666567f;
    f_lo = func_8080145C_mlspline(lo, cnt, pts, fn);
    f_ends = func_8080145C_mlspline(hi, cnt, pts, fn) + f_lo;
    old_sum = 0.0f;
    half = h * 0.5f;
    f_mid = func_8080145C_mlspline(lo + half, cnt, pts, fn);
    simpson = (2.0f * old_sum + f_ends + 4.0f * f_mid) * h6;
    prev = simpson + simpson;
    while (n < max_iter && 0.0f < mlAbsF(simpson) && tol < mlAbsF((simpson - prev) / simpson)) {
        m = n * 2;
        h6 *= 0.5f;
        old_sum += f_mid;
        half *= 0.5f;
        prev = simpson;
        n = m;
        f_mid = 0.0f;
        for (i = 1; i < n * 2; i += 2) {
            f_mid += func_8080145C_mlspline(i * half + lo, cnt, pts, fn);
        }
        simpson = (2 * old_sum + f_ends + 4 * f_mid) * h6;
    }
    if (cnt >= 4) {
        simpson *= cnt - 1;
    }
    return simpson;
}

// Absolute arc length over [lo, hi].
f32 mlspline_entrypoint_11(s32 count, s32 points, f32 lo, f32 hi, s32 fn)
{
    return mlAbsF(
        func_80801488_mlspline(points, count, lo, hi, 0x800, 0.001f, fn));
}

// Same as entrypoint_11 with a caller-supplied iteration limit.
f32 mlspline_entrypoint_12(s32 count, s32 points, f32 lo, f32 hi, s32 max_iter,
                           s32 fn)
{
    return mlAbsF(
        func_80801488_mlspline(points, count, lo, hi, max_iter, 0.001f, fn));
}

// Newton stepping along the path: finds the t that is arc_len further from start_t.
f32 mlspline_entrypoint_13(s32 count, s32 points, f32 start_t, f32 arc_len, f32 unk_4,
                           s32 (*deriv_fn)(f32, s32, s32, f32 *))
{
    f32 step;
    f32 val;
    f32 d;
    s32 n;
    f32 t;
    f32 cur;
    f32 vec[3];
    s32 done;
    s32 iter;
    f32 x;
    f32 target;
    done = 0;
    if (count >= 4) {
        n = count - 1;
    } else {
        n = 1;
    }
    iter = 0;
    if (mlAbsF(arc_len) < 0.01f) {
        return start_t;
    }
    deriv_fn(start_t, count, points, vec);
    step = arc_len / (func_800EEF94(vec) * (f32) n);
    target = mlAbsF(arc_len);
    cur = start_t + step;
    do {
        t = cur;
        if (0.0f < step) {
            if (1.0f <= t) {
                if (unk_4 == 1.0f) {
                    t = 1.0f;
                    val = func_80801488_mlspline(points, count, start_t, 1.0f, 0x400, 0.01f,
                                                 (s32) deriv_fn);
                    if (val < arc_len) {
                        done = 1;
                    }
                } else {
                    t = t + unk_4;
                    t = t - (f32) (s32) t;
                    val = func_80801488_mlspline(points, count, start_t, 1.0f, 0x400, 0.01f,
                                                 (s32) deriv_fn);
                    val += func_80801488_mlspline(points, count, unk_4, t, 0x400, 0.01f,
                                                  (s32) deriv_fn);
                }
            } else {
                val = func_80801488_mlspline(points, count, start_t, t, 0x400, 0.01f,
                                             (s32) deriv_fn);
            }
        } else if (unk_4 == 1.0f) {
            if (t < 0.0f) {
                t = 0.0f;
                val = func_80801488_mlspline(points, count, start_t, 0.0f, 0x400, 0.01f,
                                             (s32) deriv_fn);
                if (arc_len < val) {
                    done = 1;
                }
            } else {
                val = func_80801488_mlspline(points, count, start_t, t, 0x400, 0.01f,
                                             (s32) deriv_fn);
            }
        } else if (t < unk_4) {
            t = t - unk_4;
            t = t - (f32) (s32) t;
            t = t + 1.0f;
            val = func_80801488_mlspline(points, count, start_t, unk_4, 0x400, 0.01f,
                                         (s32) deriv_fn);
            val += func_80801488_mlspline(points, count, 1.0f, t, 0x400, 0.01f, (s32) deriv_fn);
        } else {
            val = func_80801488_mlspline(points, count, start_t, t, 0x400, 0.01f, (s32) deriv_fn);
        }
        if (!done && (mlAbsF(val - target) > 0.01f)) {
            deriv_fn(t, count, points, vec);
            d = (val - arc_len) / (func_800EEF94(vec) * (f32) n);
            cur = t - d;
            if (mlAbsF(d) < 0.000001f) {
                done = 1;
            }
            if (0.0f < step) {
                if (cur < start_t) {
                    cur += 1.0f - unk_4;
                }
            } else if (start_t < cur) {
                cur -= 1.0f - unk_4;
            }
        } else {
            done = 1;
        }
        iter++;
    } while (!done && (iter < 10));
    return t;
}
