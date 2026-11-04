// Core 3D vector library (vec3): arithmetic, conversions, dot/cross, length and distance,
// normalise, reflection, and rotation about axes or by yaw/pitch/roll.
#include "core2/1EC8070.h"

extern f32 func_800137F4(f32);
extern f32 func_80013788(void);
extern f32 func_800138D0(f32);
extern f32 mlAbsF(f32);
extern f32 func_800137AC(f32);
extern f32 func_800137C4(void);
extern f32 func_800136E4(f32);
int func_800EFA20(f32 *param_0, f32 param_1[3], f32 param_2);

// ml_vec3f_sum
void func_800EE780(f32 dst[3], f32 a[3], f32 b[3])
{
    dst[0] = a[0] + b[0];
    dst[1] = a[1] + b[1];
    dst[2] = a[2] + b[2];
}

// ml_vec3f_scaled_sum
void func_800EE7B4(f32 dst[3], f32 a[3], f32 b[3], f32 scale)
{
    dst[0] = a[0] + b[0] * scale;
    dst[1] = a[1] + b[1] * scale;
    dst[2] = a[2] + b[2] * scale;
}

// ml_vec3f_copy
void func_800EE7F8(f32 dst[3], f32 src[3])
{
    dst[0] = src[0];
    dst[1] = src[1];
    dst[2] = src[2];
}

// ml_vec3s_copy
void func_800EE814(s16 dst[3], s16 src[3])
{
    dst[0] = src[0];
    dst[1] = src[1];
    dst[2] = src[2];
}

// ml_vec3i_copy
void func_800EE830(s32 dst[3], s32 src[3])
{
    dst[0] = src[0];
    dst[1] = src[1];
    dst[2] = src[2];
}

// ml_vec3i_to_vec3f
void func_800EE84C(f32 dst[3], s32 src[3])
{
    dst[0] = src[0];
    dst[1] = src[1];
    dst[2] = src[2];
}

// ml_vec3s_to_vec3f
void func_800EE88C(f32 dst[3], s16 src[3])
{
    dst[0] = src[0];
    dst[1] = src[1];
    dst[2] = src[2];
}

// ml_vec3s_to_vec3i
void func_800EE8CC(s32 dst[3], s16 src[3])
{
    dst[0] = src[0];
    dst[1] = src[1];
    dst[2] = src[2];
}

// ml_vec2f_to_vec3f
void func_800EE8E8(f32 dst[3], f32 src[2])
{
    dst[0] = src[0];
    dst[1] = 0;
    dst[2] = src[1];
}

// ml_vec3f_to_vec3i
void func_800EE904(s32 dst[3], f32 src[3])
{
    dst[0] = src[0];
    dst[1] = src[1];
    dst[2] = src[2];
}

// ml_vec3f_to_vec3s
void func_800EE940(s16 dst[3], f32 src[3])
{
    dst[0] = src[0];
    dst[1] = src[1];
    dst[2] = src[2];
}

// ml_vec3f_cross_product
void func_800EE97C(f32 dst[3], f32 a[3], f32 b[3])
{
    dst[0] = a[1] * b[2] - a[2] * b[1];
    dst[1] = a[2] * b[0] - a[0] * b[2];
    dst[2] = a[0] * b[1] - a[1] * b[0];
}

// ml_vec3i_cross_product
void func_800EE9EC(f32 dst[3], s32 a[3], s32 b[3])
{
    dst[0] = a[1] * b[2] - a[2] * b[1];
    dst[1] = a[2] * b[0] - a[0] * b[2];
    dst[2] = a[0] * b[1] - a[1] * b[0];
}

// ml_vec3f_dot_product
f32 func_800EEAA4(f32 a[3], f32 b[3])
{
    return a[0] * b[0] + a[1] * b[1] + a[2] * b[2];
}

// ml_vec3f_distance
f32 func_800EEAD4(f32 a[3], f32 b[3])
{
    f32 delta[3];
    delta[0] = a[0] - b[0];
    delta[1] = a[1] - b[1];
    delta[2] = a[2] - b[2];
    return sqrtf(SQ(delta[0]) + SQ(delta[1]) + SQ(delta[2]));
}

// ml_vec3f_distance_sq
f32 func_800EEB40(f32 a[3], f32 b[3])
{
    f32 delta[3];
    delta[0] = a[0] - b[0];
    delta[1] = a[1] - b[1];
    delta[2] = a[2] - b[2];
    return SQ(delta[0]) + SQ(delta[1]) + SQ(delta[2]);
}

// XZ direction from yaw, scaled by length
void func_800EEB9C(f32 dst[3], f32 yaw, f32 length)
{
    dst[0] = func_800137F4(yaw) * length;
    dst[1] = 0.0f;
    dst[2] = func_80013788() * length;
}

void func_800EEBF0(f32 *dst, f32 *angles, f32 length)
{
    func_800EFD24(dst);
    func_800EF214(dst, angles[0], angles[1], length);
}

void func_800EEC30(f32 dst[3], f32 pitch, f32 yaw, f32 length)
{
    func_800EFD24(dst);
    func_800EF214(dst, pitch, yaw, length);
}

void func_800EEC70(u8 *dst, f32 pitch, f32 yaw, f32 length)
{
    f32 horizontal;
    horizontal = func_800138D0(pitch) * length;
    *(f32 *) ((s8 *) dst + 4) = 0.0f;
    *(f32 *) ((s8 *) dst + 0) = func_800137F4(yaw) * horizontal;
    *(f32 *) ((s8 *) dst + 8) = func_80013788() * horizontal;
}

int func_800EECE0(f32 a[3], f32 b[3])
{
    return (a[0] == b[0]) && (a[1] == b[1]) && (a[2] == b[2]);
}

int func_800EED58(s32 *a, s32 *b)
{
    int x_equal;
    int y_equal;
    x_equal = a[0] == b[0];
    if (x_equal) {
        y_equal = a[1] == b[1];
        if (y_equal) {
            return a[2] == b[2];
        }
    }
}

int func_800EEDA0(s16 *a, s16 *b)
{
    int y_equal;
    int x_equal;
    x_equal = a[0] == b[0];
    if (x_equal) {
        y_equal = a[1] == b[1];
        if (y_equal) {
            return a[2] == b[2];
        }
    }
}

// near-equality within a tolerance per axis
int func_800EEDE8(f32 *a, f32 *b, f32 tolerance)
{
    return mlAbsF(a[0] - b[0]) < tolerance && mlAbsF(a[1] - b[1]) < tolerance &&
           mlAbsF(a[2] - b[2]) < tolerance;
}

int func_800EEEA8(f32 *vec)
{
    return !((vec[0] != 0.0f) || (vec[1] != 0.0f) || (vec[2] != 0.0f));
}

s32 func_800EEF24(f32 vec[3])
{
    unsigned char nonzero;
    nonzero = 0;
    if (vec[0] != 0.0f) {
        nonzero = 1;
    }
    if (nonzero == 0) {
        nonzero = 0;
        if (vec[1] != 0.0f) {
            nonzero = 1;
        }
        if (nonzero == 0) {
            nonzero = 0;
            if (vec[2] != 0.0f) {
                nonzero = 1;
            }
        }
    }
    // Matching: empty if on vec is needed for the match.
    if (vec) {
    }
    return nonzero;
}

f32 func_800EEF94(f32 vec[3])
{
    f32 sum;
    f32 z;
    f32 y;
    f32 x;
    z = vec[2];
    x = vec[0];
    sum = x * x;
    y = vec[1];
    sum += y * y;
    sum = sum + (z * z);
    return sqrtf(sum);
}

f32 func_800EEFD4(f32 vec[3])
{
    return vec[0] * vec[0] + vec[1] * vec[1] + vec[2] * vec[2];
}

// length in the XZ plane
int func_800EEFFC(f32 vec[3])
{
    f32 z;
    float z_sq;
    f32 z_copy;
    f32 x_copy;
    f32 sum;
    f32 x;
    z = vec[2];
    sum = (z_copy = z);
    z_sq = sum * z_copy;
    x = vec[0];
    z_copy = z_sq;
    // Matching: the extra copies, the inner block and the * 1.0f are needed for the match.
    {
        x_copy = x;
        sum = x_copy;
        sum = sum * x;
        sum = sum + (z_copy * 1.0f);
    }
    sqrtf(sum);
}

// squared length in the XZ plane
f32 func_800EF030(f32 *vec)
{
    f32 z;
    f32 x;

    z = vec[2];
    x = vec[0];
    return (z * z) + (x * x);
}

void func_800EF04C(f32 *dst, f32 *src)
{
    dst[0] += src[0];
    dst[1] += src[1];
    dst[2] += src[2];
}

func_800EF080(s16 *dst, s16 *src)
{
    dst[0] += src[0];
    dst[1] += src[1];
    dst[2] += src[2];
}

func_800EF0B4(s16 *dst, f32 src[3])
{
    dst[0] += src[0];
    dst[1] += src[1];
    dst[2] += src[2];
}

func_800EF11C(f32 dst[3], s16 src[3])
{
    dst[0] += src[0];
    dst[1] += src[1];
    dst[2] += src[2];
}

func_800EF174(f32 dst[3], f32 src[3], f32 scale)
{
    dst[0] += src[0] * scale;
    dst[1] += src[1] * scale;
    dst[2] += src[2] * scale;
}

void func_800EF1B8(f32 *dst, f32 yaw, f32 length)
{
    dst[0] += length * func_800137F4(yaw);
    dst[2] += length * func_80013788();
}

void func_800EF214(f32 dst[3], f32 pitch, f32 yaw, f32 length)
{
    f32 horizontal;
    horizontal = func_800137AC(pitch) * length;
    dst[1] += length * func_800137C4();
    dst[0] += horizontal * func_800137F4(yaw);
    dst[2] += horizontal * func_80013788();
}

// normalise in place
void func_800EF2A0(f32 vec[3])
{
    f32 length;
    if ((length = vec[0] * vec[0] + vec[1] * vec[1] + vec[2] * vec[2]) !=
        0.0f) {
        length = sqrtf(length);
        vec[0] *= 1.0f / length;
        vec[1] *= 1.0f / length;
        vec[2] *= 1.0f / length;
    }
}

// ml_vec3f_apply_scale
void func_800EF334(f32 vec[3], f32 scale)
{
    vec[0] *= scale;
    vec[1] *= scale;
    vec[2] *= scale;
}

// ml_vec3f_set_length
void func_800EF368(f32 vec[3], f32 target_length)
{
    f32 length_sq;

    length_sq = SQ(vec[0]) + SQ(vec[1]) + SQ(vec[2]);
    if (length_sq != 0.0f) {
        func_800EF334(vec, target_length / sqrtf(length_sq));
    }
}

// ml_vec3f_subtract
void func_800EF3DC(f32 dst[3], f32 src[3])
{
    dst[0] -= src[0];
    dst[1] -= src[1];
    dst[2] -= src[2];
}

// normalise src into dst
void func_800EF410(s32 dst, f32 src[3])
{
    f32 length_sq = ((src[0] * src[0]) + (src[1] * src[1])) + (src[2] * src[2]);
    if (length_sq != 0.0f) {
        func_800EFA20(dst, src, 1.0f / sqrtf(length_sq));
    } else {
        func_800EE7F8(dst, src);
    }
}

void func_800EF49C(f32 *vec)
{
    vec[0] = func_800136E4(vec[0]);
    vec[1] = func_800136E4(vec[1]);
    vec[2] = func_800136E4(vec[2]);
}

void func_800EF4E4(f32 *dst, f32 angle_x, f32 angle_y, f32 x, f32 y, f32 z)
{
    f32 sine;
    f32 cosine;
    f32 tmp;
    sine = func_800137F4(angle_x);
    cosine = func_80013788();
    tmp = y * sine + z * cosine;
    dst[1] = y * cosine - z * sine;
    sine = func_800137F4(angle_y);
    cosine = func_80013788();
    dst[0] = tmp * sine + x * cosine;
    dst[2] = tmp * cosine - x * sine;
}

void func_800EF5A0(f32 *dst, f32 *angles, f32 x, f32 y, f32 z)
{
    f32 sine;
    f32 cosine;
    f32 tmp;
    sine = func_800137F4(angles[0]);
    cosine = func_80013788();
    tmp = y * sine + z * cosine;
    dst[1] = y * cosine - z * sine;
    sine = func_800137F4(angles[1]);
    cosine = func_80013788();
    dst[0] = tmp * sine + x * cosine;
    dst[2] = tmp * cosine - x * sine;
    sine = func_800137F4(angles[2]);
    cosine = func_80013788();
    tmp = dst[0] * cosine - dst[1] * sine;
    dst[1] = dst[0] * sine + dst[1] * cosine;
    dst[0] = tmp;
}

void func_800EF6A8(f32 *dst, f32 *angles, f32 x, f32 y, f32 z)
{
    f32 sine;
    f32 cosine;
    f32 tmp;
    f32 old_x;
    sine = func_800137F4(angles[2]);
    cosine = func_80013788();
    dst[1] = x * sine + y * cosine;
    dst[0] = x * cosine - y * sine;
    sine = func_800137F4(angles[0]);
    cosine = func_80013788();
    tmp = dst[1] * sine + z * cosine;
    dst[1] = dst[1] * cosine - z * sine;
    sine = func_800137F4(angles[1]);
    cosine = func_80013788();
    old_x = dst[0];
    dst[2] = tmp * cosine - old_x * sine;
    dst[0] = old_x * cosine + tmp * sine;
}

void func_800EF7B0(f32 *dst, f32 *angles, f32 x, f32 y, f32 z)
{
    f32 sine;
    f32 cosine;
    f32 tmp;
    sine = func_800137AC(angles[1]);
    cosine = func_800137C4();
    tmp = z * cosine + x * sine;
    dst[1] = y;
    dst[2] = z * sine - x * cosine;
    dst[0] = tmp;
    sine = func_800137AC(angles[0]);
    cosine = func_800137C4();
    tmp = dst[1] * sine - dst[2] * cosine;
    dst[2] = dst[1] * cosine + dst[2] * sine;
    dst[1] = tmp;
    sine = func_800137AC(angles[2]);
    cosine = func_800137C4();
    tmp = dst[0] * sine - dst[1] * cosine;
    dst[1] = dst[0] * cosine + dst[1] * sine;
    dst[0] = tmp;
}

// rotate about the X axis
void func_800EF8BC(f32 *dst, f32 *src, f32 angle)
{
    f32 sine;
    f32 cosine;
    f32 new_y;
    sine = func_800137AC(angle);
    cosine = func_800137C4();
    dst[0] = src[0];
    new_y = src[1] * sine - src[2] * cosine;
    dst[2] = src[1] * cosine + src[2] * sine;
    dst[1] = new_y;
}

// rotate about the Y axis
void func_800EF934(f32 dst[3], f32 src[3], f32 angle)
{
    f32 s;
    f32 c;
    f32 x;
    s = func_800137AC(angle);
    c = func_800137C4();
    x = src[2] * c + src[0] * s;
    dst[1] = src[1];
    dst[2] = src[2] * s - src[0] * c;
    dst[0] = x;
}

// rotate about the Z axis
void func_800EF9A8(f32 *dst, f32 *src, f32 angle)
{
    f32 sine;
    f32 cosine;
    f32 new_x;
    sine = func_800137AC(angle);
    cosine = func_800137C4();
    new_x = src[0] * sine - src[1] * cosine;
    dst[1] = src[0] * cosine + src[1] * sine;
    dst[2] = src[2];
    dst[0] = new_x;
}

// dst = src * scale
func_800EFA20(f32 *dst, f32 src[3], f32 scale)
{
    dst[0] = src[0] * scale;
    dst[1] = src[1] * scale;
    dst[2] = src[2] * scale;
}

void func_800EFA4C(f32 dst[3], f32 x, f32 y, f32 z)
{
    dst[0] = x;
    dst[1] = y;
    dst[2] = z;
}

func_800EFA6C(dst_addr, x, y, z) s32 dst_addr;
s16 x;
s16 y;
s16 z;
{
    s16 *dst = dst_addr;

    dst[0] = x;
    dst[1] = y;
    dst[2] = z;
}

s32 func_800EFA88(void *dst, s32 x, s32 y, s32 z)
{
    *(s32 *) ((s32) dst + 0) = x;
    *(s32 *) ((s32) dst + 4) = y;
    *(s32 *) ((s32) dst + 8) = z;
}

// set length, copying src when it has zero length
void func_800EFA98(f32 dst[3], f32 src[3], f32 length)
{
    f32 length_sq_copy;
    f32 length_sq;
    length_sq = ((src[0] * src[0]) + (src[1] * src[1])) + (src[2] * src[2]);
    length_sq_copy = length_sq;

if (length_sq_copy != 0.0f) {
    f32 factor;
    factor = length / sqrtf(length_sq);
    func_800EFA20(dst, src, factor);
}

else
{
    func_800EE7F8(dst, src);
}
}

func_800EFB24(f32 dst[3], f32 a[3], f32 b[3])
{
    dst[0] = a[0] - b[0];
    dst[1] = a[1] - b[1];
    dst[2] = a[2] - b[2];
}

func_800EFB58(s32 *dst, s32 *a, s32 *b)
{
    dst[0] = a[0] - b[0];
    dst[1] = a[1] - b[1];
    dst[2] = a[2] - b[2];
}

// distance in the XZ plane
f32 func_800EFB8C(f32 a[3], f32 b[3])
{
    f32 dx;
    f32 dz;
    int x_zero;
    f32 dist_sq;
    float zero;
    f32 dist;
    dx = a[0] - b[0];
    dz = a[2] - b[2];
    // Matching: the empty blocks and the ^ 0 are needed for the match.
    {
    }
    zero = 0.0f;
    x_zero = dx == zero;

if ((x_zero ^ 0) && (dz == zero)) {
}

else
{
    dist_sq = (dx * dx) + (dz * dz);
    dist = sqrtf(dist_sq);
    return dist;
}
return 0.0f;
}

// octagonal approximation of the XZ distance
f32 func_800EFBFC(f32 a[3], f32 b[3])
{
    f32 abs_dx;
    f32 abs_dz;
    f32 smaller;
    abs_dx = mlAbsF(b[0] - a[0]);
    abs_dz = mlAbsF(b[2] - a[2]);
    smaller = (abs_dx < abs_dz) ? abs_dx : abs_dz;
    return abs_dx + abs_dz - smaller * 0.41421357f;
}

// squared distance in the XZ plane
f32 func_800EFC7C(f32 a[3], f32 b[3])
{
    f32 dx;
    f32 dz;
    f32 dist_sq;
    dx = a[0] - b[0];
    dz = a[2] - b[2];

if ((dx != 0.0f) || (dz != 0.0f)) {
    dist_sq = (dx * dx) + (dz * dz);
    return dist_sq;
}

return 0;
}

void func_800EFCD8(f32 *dst, f32 yaw, f32 length)
{
    f32 sine = func_800137F4(yaw);
    f32 x = sine * length;
    dst[0] = x;
    dst[2] = func_80013788() * length;
}

// ml_vec3f_clear
void func_800EFD24(f32 vec[3])
{
    vec[0] = vec[1] = vec[2] = 0;
}

// ml_vec3i_clear
void func_800EFD3C(s32 vec[3])
{
    vec[0] = vec[1] = vec[2] = 0;
}

// ml_vec3s_clear
void func_800EFD4C(s16 vec[3])
{
    vec[0] = vec[1] = vec[2] = 0;
}

void func_800EFD60(f32 *dst, f32 *src, f32 angle)
{
    f32 abs_sin;
    f32 abs_cos;
    f32 x;
    f32 z;
    abs_sin = mlAbsF(func_800137AC(angle));
    abs_cos = mlAbsF(func_800137C4());
    x = src[0];
    z = src[2];
    dst[0] = x * abs_sin + z * abs_cos;
    dst[1] = src[1];
    dst[2] = z * abs_sin + x * abs_cos;
}

// reflect incident about normal
void func_800EFDE8(f32 *dst, f32 *incident, f32 *normal)
{
    f32 neg_incident[3];
    f32 dot;
    func_800EFA20(neg_incident, incident, -1.0f);
    dot = func_800EEAA4(neg_incident, normal);
    func_800EFA20(dst, normal, dot + dot);
    func_800EF3DC(dst, neg_incident);
}
