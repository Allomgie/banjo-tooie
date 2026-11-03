#include "common.h"

extern f32 func_80013A7C(f32);
extern f32 func_80013970(f32);

typedef struct {
    s32 unk_0;
    s32 unk_4;
    s32 unk_8;
    f32 unk_C;
} UnkStruct;

// Quaternion helpers: copy, conjugate, to matrix, compare, slerp, identity.
// Quaternions are stored as (x, y, z, w).

func_800D9600(f32 dst[4], f32 src[4])
{
    dst[0] = src[0];
    dst[1] = src[1];
    dst[2] = src[2];
    dst[3] = src[3];
}

// Conjugate: negates x, y, z.
void func_800D9624(f32 *dst, f32 *src)
{
    s32 i;
    for (i = 0; i != 3; i++) {
        dst[i] = -src[i];
    }
    dst[3] = src[3];
}

// Quaternion to 4x4 rotation matrix.
void func_800D965C(f32 *q, f32 mtx[][4])
{
    f32 scale, wx, wy, wz;
    f32 xs, ys, zs;
    f32 xx, xy, xz, yy, yz, zz;
    // Matching: empty block needed for the match.
    if (q[0] == 0.0f && q[1] == 0.0f && q[2] == 0.0f && q[3] == 0.0f) {
    }
    scale = 2.0f / (q[0] * q[0] + q[1] * q[1] + q[2] * q[2] +
                      q[3] * q[3]);
    xs = q[0] * scale;
    ys = q[1] * scale;
    zs = q[2] * scale;
    wx = q[3] * xs;
    wy = q[3] * ys;
    wz = q[3] * zs;
    xx = q[0] * xs;
    xy = q[0] * ys;
    xz = q[0] * zs;
    yy = q[1] * ys;
    yz = q[1] * zs;
    zz = q[2] * zs;
    mtx[0][0] = 1.0f - (yy + zz);
    mtx[0][1] = xy + wz;
    mtx[0][2] = xz - wy;
    mtx[1][0] = xy - wz;
    mtx[1][1] = 1.0f - (xx + zz);
    mtx[1][2] = yz + wx;
    mtx[2][0] = xz + wy;
    mtx[2][1] = yz - wx;
    mtx[2][2] = 1.0f - (xx + yy);
    mtx[3][3] = 1.0f;
    mtx[0][3] = 0;
    mtx[1][3] = 0;
    mtx[2][3] = 0;
    mtx[3][0] = 0;
    mtx[3][1] = 0;
    mtx[3][2] = 0;
}

int func_800D97E8(f32 a[4], f32 b[4])
{
    return a[0] == b[0] && a[1] == b[1] && a[2] == b[2] &&
           a[3] == b[3];
}

// Spherical linear interpolation from q1 to q2 by t.
void func_800D9888(f32 *dst,f32 *q1, f32 *q2, f32 t)
{
    f32 dot, w1, w2, sin_theta, theta;
    dot = q1[0] * q2[0] + q1[1] * q2[1] + q1[2] * q2[2] +
              q1[3] * q2[3];
    if (1.0f + dot > 1e-05f) {
        if (1.0f - dot > 1e-05f) {
            theta = func_80013A7C(dot);
            sin_theta = func_80013970(theta);
            if (sin_theta != 0.0f) {
                w1 = func_80013970((1.0f - t) * theta) / sin_theta;
                w2 = func_80013970(t * theta) / sin_theta;
            } else {
                w1 = 1.0f - t;
                w2 = t;
            }
        } else {
            w1 = 1.0f - t;
            w2 = t;
        }
        dst[0] = w1 * q1[0] + w2 * q2[0];
        dst[1] = w1 * q1[1] + w2 * q2[1];
        dst[2] = w1 * q1[2] + w2 * q2[2];
        dst[3] = w1 * q1[3] + w2 * q2[3];
    } else {
        dst[0] = -q1[1];
        dst[1] = q1[0];
        dst[2] = -q1[3];
        dst[3] = q1[2];
        w1 = func_80013970((1.0f - t) * 90.0f);
        w2 = func_80013970(t * 90.0f);
        dst[0] = w1 * q1[0] + w2 * dst[0];
        dst[1] = w1 * q1[1] + w2 * dst[1];
        dst[2] = w1 * q1[2] + w2 * dst[2];
    }
}

// Slerp along the shortest path: negates q2 if it lies on the far side of q1.
void func_800D9AD4(f32 *dst,f32 *q1, f32 *q2, f32 t)
{
    f32 diff_sq;
    f32 sum_sq;
    f32 tmp[4];

    tmp[0] = q1[0] - q2[0];
    tmp[1] = q1[1] - q2[1];
    tmp[2] = q1[2] - q2[2];
    tmp[3] = q1[3] - q2[3];

    diff_sq = (tmp[0] * tmp[0]) + (tmp[1] * tmp[1]) + (tmp[2] * tmp[2]) +
              (tmp[3] * tmp[3]);

    tmp[0] = q1[0] + q2[0];
    tmp[1] = q1[1] + q2[1];
    tmp[2] = q1[2] + q2[2];
    tmp[3] = q1[3] + q2[3];

    sum_sq = (tmp[0] * tmp[0]) + (tmp[1] * tmp[1]) + (tmp[2] * tmp[2]) +
              (tmp[3] * tmp[3]);

    if (diff_sq <= sum_sq) {
        func_800D9888(dst, q1, q2, t);
        return;
    }

    tmp[0] = -q2[0];
    tmp[1] = -q2[1];
    tmp[2] = -q2[2];
    tmp[3] = -q2[3];

    func_800D9888(dst, q1, tmp, t);
}

// Sets the identity quaternion (0, 0, 0, 1.0f).
void func_800D9C34(UnkStruct *q)
{
    q->unk_0 = 0;
    q->unk_4 = 0;
    q->unk_8 = 0;
    ((s32 *) &q->unk_C)[0] = 0x3F800000;
}

// Returns whether q is the identity quaternion.
int func_800D9C4C(f32 q[4])
{
    // Matching: zero held in a local for the comparisons.
    f32 zero = 0.0f;
    return (((q[0] == zero) && (q[1] == zero)) && (q[2] == zero)) &&
           (q[3] == 1.0f);
}

// Quaternion to 3x3 rotation matrix.
void func_800D9CE8(f32 *q, f32 mtx[][3])
{
    f32 scale, wx, wy, wz;
    f32 xs, ys, zs;
    f32 xx, xy, xz, yy, yz, zz;
    // Matching: empty block needed for the match.
    if (q[0] == 0.0f && q[1] == 0.0f && q[2] == 0.0f && q[3] == 0.0f) {
    }
    scale = 2.0f / (q[0] * q[0] + q[1] * q[1] + q[2] * q[2] +
                      q[3] * q[3]);
    xs = q[0] * scale;
    ys = q[1] * scale;
    zs = q[2] * scale;
    wx = q[3] * xs;
    wy = q[3] * ys;
    wz = q[3] * zs;
    xx = q[0] * xs;
    xy = q[0] * ys;
    xz = q[0] * zs;
    yy = q[1] * ys;
    yz = q[1] * zs;
    zz = q[2] * zs;
    mtx[0][0] = 1.0f - (yy + zz);
    mtx[0][1] = xy + wz;
    mtx[0][2] = xz - wy;
    mtx[1][0] = xy - wz;
    mtx[1][1] = 1.0f - (xx + zz);
    mtx[1][2] = yz + wx;
    mtx[2][0] = xz + wy;
    mtx[2][1] = yz - wx;
    mtx[2][2] = 1.0f - (xx + yy);
}
