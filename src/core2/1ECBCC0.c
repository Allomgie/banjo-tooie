// Float 4x4 matrix helpers (transform, rotate, scale, translate, multiply, euler angles),
// a guLookAtReflectF-style LookAt builder, and small int / u8 RGBA colour vector helpers.
#include <ultra64.h>
#include "core1/mlmtx.h"

s32 func_800F274C();

#define F2984_DIR(x) ((x) * 128.0f < 127.0f ? (x) * 128.0f : 127.0f)
extern void func_800EF2A0(f32 *);
extern f32 func_800137F4(f32);
extern f32 func_80013788(void);
typedef struct {
    f32 v[4];
} R_F293C;
// Light entry of a LookAt (libultra Light_t layout): color, color copy, direction.
typedef struct {
    u8 color[8];
    s8 dir[3];
    u8 pad_B[5];
} LightF2984;
extern void func_800EFB24(f32 *, f32 *, f32 *);
extern void func_800EF368(f32 *, f32);
extern void func_800EE97C(f32 *, f32 *, f32 *);
extern f32 func_800EEAA4(f32 *, f32 *);
extern f32 mlAbsF(f32 param_0);
extern f32 func_80013AAC(f32);
extern f32 func_800138D0(f32);
extern f32 func_80013A7C(f32, f32);

// Matrix ops, euler extraction, and int / u8 colour vector copy, lerp and clamp.
// Transforms a point by a matrix (row-vector convention, with translation).
void func_800F23D0(f32 *mtx, f32 *out, s32 in)
{
    s32 i;
    f32 vec[3];

    func_800EE7F8(vec, in);
    for (i = 0; i < 3; i++) {
        out[i] = vec[0] * mtx[i] + vec[1] * mtx[i + 4] +
                 vec[2] * mtx[i + 8] + mtx[i + 12];
    }
}

// Transforms a direction by a matrix (row-vector convention, no translation).
void func_800F2454(u8 *mtx, u8 *out, s32 in)
{
    s32 i;
    f32 vec[3];
    u8 *out_ptr;
    u8 *col_ptr;
    func_800EE7F8(vec, in);
    i = 0;
    out_ptr = out;
    col_ptr = mtx;
    do {
        i++;
        out_ptr += 4;
        *(f32 *) (out_ptr - 4) =
            ((vec[0] * *(f32 *) col_ptr) + (vec[1] * *(f32 *) (col_ptr + 0x10))) +
            (vec[2] * *(f32 *) (col_ptr + 0x20));
        col_ptr += 4;
    } while (i != 3);
}

// Transforms a direction by a matrix (column-vector convention, no translation).
void func_800F24D0(u8 *mtx, u8 *out, s32 in)
{
    s32 i;
    f32 vec[3];
    u8 *out_ptr;
    u8 *row_ptr;
    func_800EE7F8(vec, in);
    // Matching: routing out through row_ptr first is needed for the match.
    row_ptr = out;
    i = 0;
    out_ptr = row_ptr;
    row_ptr = mtx;
    while (i != 3) {
        i++;
        out_ptr += 4;
        *(f32 *) (out_ptr - 4) = ((vec[0] * *(f32 *) row_ptr) + (vec[1] * *(f32 *) (row_ptr + 4))) +
                                (vec[2] * *(f32 *) (row_ptr + 8));
        row_ptr += 16;
    }
}

// Builds a rotation matrix from an axis and an angle in degrees.
void func_800F254C(f32 mtx[4][4], f32 *axis, f32 angle)
{
    f32 sin_a, cos_a, xy, yz, zx;
    f32 one_minus_cos, sq;
    func_800EF2A0(axis);
    sin_a = func_800137F4(angle);
    cos_a = func_80013788();
    one_minus_cos = 1.0f - cos_a;
    xy = axis[0] * axis[1] * one_minus_cos;
    yz = axis[1] * axis[2] * one_minus_cos;
    zx = axis[2] * axis[0] * one_minus_cos;
    func_800F274C(mtx);
    sq = axis[0] * axis[0];
    mtx[0][0] = (1.0f - sq) * cos_a + sq;
    mtx[2][1] = yz - axis[0] * sin_a;
    mtx[1][2] = axis[0] * sin_a + yz;
    sq = axis[1] * axis[1];
    mtx[1][1] = (1.0f - sq) * cos_a + sq;
    mtx[2][0] = axis[1] * sin_a + zx;
    mtx[0][2] = zx - axis[1] * sin_a;
    sq = axis[2] * axis[2];
    mtx[2][2] = (1.0f - sq) * cos_a + sq;
    mtx[1][0] = xy - axis[2] * sin_a;
    mtx[0][1] = axis[2] * sin_a + xy;
}

// Scale matrix.
void func_800F26B0(MtxF *mtx, f32 sx, f32 sy, f32 sz)
{
    func_800F274C(mtx);
    mtx->m[0][0] = sx;
    mtx->m[1][1] = sy;
    mtx->m[2][2] = sz;
    mtx->m[3][3] = 1.0f;
}

// Translation matrix.
int func_800F2704(f32 mtx[4][4], f32 x, f32 y, f32 z)
{
    // Matching: the call without an argument is needed for the match.
    func_800F274C();
    mtx[3][0] = x;
    mtx[3][1] = y;
    mtx[3][2] = z;
}

// Sets a 4x4 matrix to identity.
s32 func_800F274C(float mf[4][4])
{
    int i, j;

    for (i = 0; i < 4; i++)
        for (j = 0; j < 4; j++)
            mf[i][j] = (i == j) ? 1 : 0;
}

// out = a * b
void func_800F27D4(f32 a[4][4], f32 b[4][4], f32 out[4][4])
{
    s32 i;
    s32 j;
    s32 k;
    f32 result[4][4];
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 4; j++) {
            result[i][j] = 0.0f;
            for (k = 0; k < 4; k++) {
                result[i][j] += a[i][k] * b[k][j];
            }
        }
    }
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 4; j++) {
            out[i][j] = result[i][j];
        }
    }
}

// Copies a 4x4 matrix.
void func_800F293C(R_F293C *dst, R_F293C *src)
{
    s32 i;
    s32 j;
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 4; j++) {
            dst[i].v[j] = src[i].v[j];
        }
    }
}

// Look-at view matrix plus the reflection-mapping LookAt light struct.
// LookAt matrix from eye/at/up, like libultra's guLookAtReflectF, plus the two LookAt
// light directions. `up` is overwritten with the matrix y axis.
void func_800F2984(f32 mtx[4][4], LightF2984 *lights, f32 *eye, f32 *at, f32 *up)
{
    s32 i;
    f32 z_axis[3], x_axis[3];
    func_800EFB24(z_axis, at, eye);
    func_800EF368(z_axis, -1.0f);
    func_800EE97C(x_axis, up, z_axis);
    func_800EF2A0(x_axis);
    func_800EE97C(up, z_axis, x_axis);
    func_800EF2A0(up);
    func_800F274C(mtx);
    for (i = 0; i < 3; i++) {
        mtx[i][0] = x_axis[i];
        mtx[i][1] = up[i];
        mtx[i][2] = z_axis[i];
    }
    mtx[3][0] = -func_800EEAA4(eye, x_axis);
    mtx[3][1] = -func_800EEAA4(eye, up);
    mtx[3][2] = -func_800EEAA4(eye, z_axis);
    lights[0].dir[0] = (s32) F2984_DIR(x_axis[0]) & 0xFF;
    lights[0].dir[1] = (s32) F2984_DIR(x_axis[1]) & 0xFF;
    lights[0].dir[2] = (s32) F2984_DIR(x_axis[2]) & 0xFF;
    lights[1].dir[0] = (s32) F2984_DIR(up[0]) & 0xFF;
    lights[1].dir[1] = (s32) F2984_DIR(up[1]) & 0xFF;
    lights[1].dir[2] = (s32) F2984_DIR(up[2]) & 0xFF;
    lights[0].color[0] = 0;
    lights[0].color[1] = 0;
    lights[0].color[2] = 0;
    lights[0].color[3] = 0;
    lights[0].color[4] = 0;
    lights[0].color[5] = 0;
    lights[0].color[6] = 0;
    lights[0].color[7] = 0;
    lights[1].color[0] = 0;
    lights[1].color[1] = 128;
    lights[1].color[2] = 0;
    lights[1].color[3] = 0;
    lights[1].color[4] = 0;
    lights[1].color[5] = 128;
    lights[1].color[6] = 0;
    lights[1].color[7] = 0;
}

// Extracts Euler angles (degrees) from a rotation matrix into out[0..2].
void func_800F2C1C(u8 *mtx, u8 *out)
{
    f32 cos_x;
    f32 angle_x;

    if (1e-05f < (1.0f - mlAbsF(*(f32 *) ((s8 *) mtx + 0x24)))) {
        angle_x = func_80013AAC(-*(f32 *) ((s8 *) mtx + 0x24));
        *(f32 *) ((s8 *) out + 0) = angle_x;
        cos_x = func_800138D0(angle_x);
    } else {
        cos_x = 0.0f;
        if (*(f32 *) ((s8 *) mtx + 0x24) < 0.0f) {
            *(f32 *) ((s8 *) out + 0) = 90.0f;
        } else {
            *(f32 *) ((s8 *) out + 0) = -90.0f;
        }
    }
    if (cos_x != 0.0f) {
        cos_x = 1.0f / cos_x;
        *(f32 *) (out + 4) = func_80013AAC(*(f32 *) (mtx + 0x20) * cos_x);
        *(f32 *) (out + 8) = func_80013AAC(*(f32 *) (mtx + 4) * cos_x);
    } else {
        *(f32 *) (out + 4) = func_80013A7C(*(f32 *) mtx, 0.0f);
        *(f32 *) (out + 8) = 0.0f;
    }
}

// Transforms a Vec4f by a MtxF.
// Matching: the unused pad and the copy of `in` are needed for the match.
void func_800F2D34(MtxF *mat, f32 out[4], f32 in[4])
{
    s32 pad;
    f32 in_copy[4];

    in_copy[0] = in[0];
    in_copy[1] = in[1];
    in_copy[2] = in[2];
    in_copy[3] = in[3];
    out[0] = in_copy[0] * mat->m[0][0] + in_copy[1] * mat->m[1][0] + in_copy[2] * mat->m[2][0] +
             in_copy[3] * mat->m[3][0];
    out[1] = in_copy[0] * mat->m[0][1] + in_copy[1] * mat->m[1][1] + in_copy[2] * mat->m[2][1] +
             in_copy[3] * mat->m[3][1];
    out[2] = in_copy[0] * mat->m[0][2] + in_copy[1] * mat->m[1][2] + in_copy[2] * mat->m[2][2] +
             in_copy[3] * mat->m[3][2];
    out[3] = in_copy[0] * mat->m[0][3] + in_copy[1] * mat->m[1][3] + in_copy[2] * mat->m[2][3] +
             in_copy[3] * mat->m[3][3];
}

void func_800F2E60(s32 arg0[3], s32 arg1[3])
{
    arg0[0] = arg1[0];
    arg0[1] = arg1[1];
    arg0[2] = arg1[2];
}

void func_800F2E7C(s32 arg0[4], s32 arg1[4])
{
    arg0[0] = arg1[0];
    arg0[1] = arg1[1];
    arg0[2] = arg1[2];
    arg0[3] = arg1[3];
}

// Copies an RGB u8 vector.
func_800F2EA0(u8 *dst, u8 *src)
{
    dst[0] = src[0];
    dst[1] = src[1];
    dst[2] = src[2];
}

// Copies an RGBA u8 vector.
func_800F2EBC(u8 *dst, u8 *src)
{
    dst[0] = src[0];
    dst[1] = src[1];
    dst[2] = src[2];
    dst[3] = src[3];
}

s32 func_800F2EE0(s32 dst[3], u8 src[3])
{
    dst[0] = src[0];
    dst[1] = src[1];
    dst[2] = src[2];
}

s32 func_800F2EFC(s32 dst[4], u8 *src)
{
    dst[0] = src[0];
    dst[1] = src[1];
    dst[2] = src[2];
    dst[3] = src[3];
}

// Converts an RGB int vector to u8.
func_800F2F20(u8 *dst, s32 src[3])
{
    dst[0] = src[0];
    dst[1] = src[1];
    dst[2] = src[2];
}

// Converts an RGBA int vector to u8.
func_800F2F3C(u8 *dst, s32 src[4])
{
    dst[0] = src[0];
    dst[1] = src[1];
    dst[2] = src[2];
    dst[3] = src[3];
}

// Scales an int vector.
s32 func_800F2F60(s32 dst[3], s32 src[3], f32 scale)
{
    dst[0] = (s32) (src[0] * scale);
    dst[1] = (s32) (src[1] * scale);
    dst[2] = (s32) (src[2] * scale);
}

// Scales an RGB u8 vector.
void func_800F2FD0(u8 *dst, u8 src[3], f32 scale)
{
    dst[0] = (u8) ((f32) src[0] * scale);
    dst[1] = (u8) ((f32) src[1] * scale);
    dst[2] = (u8) ((f32) src[2] * scale);
}

// Sets an int RGB vector.
s32 func_800F31DC(s32 *dst, s32 r, s32 g, s32 b)
{
    dst[0] = r;
    dst[1] = g;
    dst[2] = b;
}

// Sets a u8 RGB vector.
s32 func_800F31EC(u8 *dst, s32 r, s32 g, s32 b)
{
    dst[0] = r;
    dst[1] = g;
    dst[2] = b;
}

// Sets a u8 RGBA vector.
s32 func_800F31FC(u8 *dst, s32 r, s32 g, s32 b, s32 a)
{
    dst[0] = r;
    dst[1] = g;
    dst[2] = b;
    dst[3] = a;
}

// Lerps two int vectors; returns 1 once t == 1.
int func_800F3214(s32 *dst, s32 *from, s32 *to, f32 t)
{
    dst[0] = from[0] + (to[0] - from[0]) * t;
    dst[1] = from[1] + (to[1] - from[1]) * t;
    dst[2] = from[2] + (to[2] - from[2]) * t;
    return t == 1.0f;
}

// Lerps with t = elapsed / duration (capped at 1); returns 1 when done.
int func_800F32D4(s32 dst, s32 from, s32 to, f32 elapsed, f32 duration)
{
    f32 t;
    t = elapsed / duration;
    if (t > 1.0f) {
        t = 1.0f;
    }
    return func_800F3214(dst, from, to, t);
}

// Lerps two RGB u8 vectors (t capped at 1); returns 1 when t == 1.
// Matching: the separate temporaries and the (s32) cast are needed for the match.
s32 func_800F3320(u8 *dst, u8 *from, u8 *to, f32 t)
{
    u32 from_r, from_g, from_b;
    if (t > 1.0f)
        t = 1.0f;
    from_r = from[0];
    dst[0] = (to[0] - (s32) from_r) * t + from_r;
    from_g = from[1];
    dst[1] = (to[1] - from[1]) * t + from_g;
    from_b = from[2];
    dst[2] = (to[2] - from[2]) * t + from_b;
    return t == 1.0f;
}

// Clamps an int RGB vector to 0..255 into u8.
void func_800F35AC(u8 *dst, s32 src[3])
{
    s32 value;
    s32 clamped;

    value = src[0];
    if (value < 0) {
        dst[0] = 0;
    } else {
        clamped = value >= 0x100 ? 0xff : value;
        dst[0] = clamped;
    }

    value = src[1];
    if (value < 0) {
        dst[1] = 0;
    } else {
        clamped = value >= 0x100 ? 0xff : value;
        dst[1] = clamped;
    }

    value = src[2];
    if (value < 0) {
        dst[2] = 0;
    } else {
        clamped = value >= 0x100 ? 0xff : value;
        dst[2] = clamped;
    }
}

// Clamps an int RGBA vector to 0..255 into u8.
void func_800F362C(u8 *dst, s32 src[4])
{
    s32 value;
    s32 clamped;

    value = src[0];
    if (value < 0) {
        dst[0] = 0;
    } else {
        if (value >= 0x100) {
            clamped = 0xFF;
        } else {
            clamped = value;
        }
        dst[0] = clamped;
    }

    value = src[1];
    if (value < 0) {
        dst[1] = 0;
    } else {
        if (value >= 0x100) {
            clamped = 0xFF;
        } else {
            clamped = value;
        }
        dst[1] = clamped;
    }

    value = src[2];
    if (value < 0) {
        dst[2] = 0;
    } else {
        if (value >= 0x100) {
            clamped = 0xFF;
        } else {
            clamped = value;
        }
        dst[2] = clamped;
    }

    value = src[3];
    if (value < 0) {
        dst[3] = 0;
    } else {
        if (value >= 0x100) {
            clamped = 0xFF;
        } else {
            clamped = value;
        }
        dst[3] = clamped;
    }
}

// Equality of two int RGB vectors.
// Matching: the missing return on the not-equal paths is needed for the match.
int func_800F36D4(s32 *a, s32 *b)
{
    s32 eq_0 = a[0] == b[0];
    if (eq_0) {
        s32 eq_1 = a[1] == b[1];
        if (eq_1) {
            return a[2] == b[2];
        }
    }
}

// Equality of two int RGBA vectors.
int func_800F371C(u32 a[4], u32 b[4])
{
    return a[0] == b[0] && a[1] == b[1] && a[2] == b[2] && a[3] == b[3];
}
