// Rare's float matrix stack (mlMtx*): push/pop, multiply, rotate/translate/scale, point and
// AABB transforms, and conversion to an N64 fixed-point Mtx.
#include "core1/mlmtx.h"

MtxF D_8007B4F0[0x1F];
MtxF *s_mtx_stack;

f32 func_800137F4(f32);
f32 func_80013788(void);

// Float matrix stack, point/vector/AABB transforms and TRS composition helpers.
// Copies the top of the matrix stack to dst.
void mlMtxGet(MtxF *dst)
{
    s32 row, col;

    for (row = 0; row < 4; row++) {
        for (col = 0; col < 4; col++) {
            dst->m[0][0] = s_mtx_stack->m[row][col];
            // Matching: pointer arithmetic needed for the match.
            dst = (MtxF *) &dst->m[0][1];
        }
    }
}

MtxF *mlMtx_get_stack_pointer(void)
{
    return s_mtx_stack;
}

// Returns the matrix below the top of the stack.
MtxF *func_80018BB4(void)
{
    return s_mtx_stack - 1;
}

// Conversion of the top matrix to a fixed-point Mtx, with a translation range check.
// Returns 1 if any translation component is outside the range of a fixed-point Mtx.
s32 func_80018BC4(void)
{
    f32 coord;
    s32 i;

    for (i = 0; i < 3; i++) {
        coord = s_mtx_stack->m[3][i];
        if ((coord > 32767.0f) || (coord < -32768.0f)) {
            return 1;
        }
    }
    return 0;
}

// Converts the top matrix to a fixed-point Mtx.
void mlMtxApply(Mtx *dst)
{
    guMtxF2L(s_mtx_stack->m, dst);
}

// Multiplies mtx by the top matrix; the product replaces the top.
void func_80018C50(MtxF *mtx)
{
    s32 row;
    s32 col;
    s32 i;
    f32 sum;
    f32 prod[4][4];

    for (row = 0; row < 4; row++) {
        for (col = 0; col < 4; col++) {
            sum = 0.0f;
            for (i = 0; i < 4; i++) {
                sum += mtx->m[row][i] * s_mtx_stack->m[i][col];
            }
            prod[row][col] = sum;
        }
    }

    for (row = 0; row < 4; row++) {
        for (col = 0; col < 4; col++) {
            s_mtx_stack->m[row][col] = prod[row][col];
        }
    }
}

// Pops the top matrix.
void mlMtxPop(void)
{
    s_mtx_stack--;
}

// Pushes a copy of the top matrix.
void mlMtx_push_duplicate(void)
{
    s32 i, j;
    f32 *src;
    f32 *dst;

    dst = &(s_mtx_stack + 1)->m[0][0];
    src = &s_mtx_stack->m[0][0];
    for (i = 0; i < 16; i++) {
        dst[i] = src[i];
    }
    s_mtx_stack++;
}

// Pushes a translation matrix.
// Matching: the line breaks in this function are needed for the match.
void mlMtx_push_translation(f32 x, f32 y, f32 z) {
    f32 * out = &(++s_mtx_stack)->m[0][0];
    *out++ = 1.0f; *out++ = 0.0f; *out++ = 0.0f; *out++ = 0.0f;
    *out++ = 0.0f; *out++ = 1.0f; *out++ = 0.0f; *out++ = 0.0f;
    *out++ = 0.0f; *out++ = 0.0f; *out++ = 1.0f; *out++ = 0.0f;
    *out++ = x; *out++ = y; *out++ = z; *out++ = 1.0f;
}

// Resets the stack to a single translation matrix.
// Matching: the line breaks in this function are needed for the match.
void mlMtx_set_translation(f32 x, f32 y, f32 z) {
    f32 * out = &(s_mtx_stack = &D_8007B4F0[0])->m[0][0];
    *out++ = 1.0f; *out++ = 0.0f; *out++ = 0.0f; *out++ = 0.0f;
    *out++ = 0.0f; *out++ = 1.0f; *out++ = 0.0f; *out++ = 0.0f;
    *out++ = 0.0f; *out++ = 0.0f; *out++ = 1.0f; *out++ = 0.0f;
    *out++ = x; *out++ = y; *out++ = z; *out++ = 1.0f;
}

// Resets the stack to a single copy of src.
void mlMtxSet(MtxF *src)
{
    s32 i, j;
    MtxF *dst;

    dst = s_mtx_stack = D_8007B4F0;
    for (i = 0; i < 4 * 4; i += 4) {
        for (j = 0; j < 4; j++) {
            dst->m[0][0] = src->m[0][0];
            // Matching: pointer arithmetic needed for the match.
            dst = (MtxF *) &dst->m[0][1];
            src = (MtxF *) &src->m[0][1];
        }
    }
}

// Multiplies an X-axis rotation by angle into the top matrix.
void mlMtxRotPitch(f32 angle)
{
    f32 cosval;
    f32 sinval;
    f32 e2;
    f32 e1;
    f32(*row1)[4];
    f32(*row2)[4];
    s32 i;

    if (angle != 0.0f) {
        sinval = func_800137F4(angle);
        cosval = func_80013788();
        row1 = &s_mtx_stack->m[1];
        row2 = &s_mtx_stack->m[2];
        for (i = 0; i < 3; i++) {
            e1 = (*row1)[i];
            e2 = (*row2)[i];
            (*row1)[i] = e1 * cosval + e2 * sinval;
            (*row2)[i] = e2 * cosval - e1 * sinval;
        }
    }
}

// Multiplies a Y-axis rotation by angle into the top matrix.
void mlMtxRotYaw(f32 angle)
{
    f32 cosval;
    f32 sinval;
    f32 e2;
    f32 e0;
    f32(*row0)[4];
    f32(*row2)[4];
    s32 i;

    if (angle != 0.0f) {
        sinval = func_800137F4(angle);
        cosval = func_80013788();
        row0 = &s_mtx_stack->m[0];
        row2 = &s_mtx_stack->m[2];
        for (i = 0; i < 3; i++) {
            e0 = (*row0)[i];
            e2 = (*row2)[i];
            (*row0)[i] = e0 * cosval - e2 * sinval;
            (*row2)[i] = e2 * cosval + e0 * sinval;
        }
    }
}

// Multiplies a Z-axis rotation by angle into the top matrix.
void mlMtxRotRoll(f32 angle)
{
    f32 cosval;
    f32 sinval;
    f32 e1;
    f32 e0;
    f32(*row0)[4];
    f32(*row1)[4];
    s32 i;

    if (angle != 0.0f) {
        sinval = func_800137F4(angle);
        cosval = func_80013788();
        row0 = &s_mtx_stack->m[0];
        row1 = &s_mtx_stack->m[1];
        for (i = 0; i < 3; i++) {
            e0 = (*row0)[i];
            e1 = (*row1)[i];
            (*row0)[i] = e0 * cosval + e1 * sinval;
            (*row1)[i] = e1 * cosval - e0 * sinval;
        }
    }
}

void mlMtxRotatePYR(f32 pitch, f32 yaw, f32 roll)
{
    mlMtxRotYaw(yaw);
    mlMtxRotPitch(pitch);
    mlMtxRotRoll(roll);
}

// Scales the top matrix uniformly.
void mlMtxScale(f32 scale)
{
    int i;
    for (i = 0; i < 3; i++) {
        s_mtx_stack->m[0][i] *= scale;
        s_mtx_stack->m[1][i] *= scale;
        s_mtx_stack->m[2][i] *= scale;
    }
}

// Sets the translation of the top matrix.
void func_800191F8(f32 x, f32 y, f32 z)
{
    s_mtx_stack->m[3][0] = x;
    s_mtx_stack->m[3][1] = y;
    s_mtx_stack->m[3][2] = z;
}

// Transforms point in by the top matrix. out may alias in.
void func_80019224(f32 out[3], f32 in[3])
{
    s32 i;
    f32 tmp[3];

    tmp[0] = in[0];
    tmp[1] = in[1];
    tmp[2] = in[2];

    for (i = 0; i < 3; i++) {
        out[i] = tmp[0] * s_mtx_stack->m[0][i] + tmp[1] * s_mtx_stack->m[1][i] +
                  tmp[2] * s_mtx_stack->m[2][i] + s_mtx_stack->m[3][i];
    }
}

// Transforms direction in by the transpose of the top matrix's upper 3x3.
void func_800192FC(f32 out[3], f32 in[3])
{
    s32 i;
    f32 tmp[3];

    tmp[0] = in[0];
    tmp[1] = in[1];
    tmp[2] = in[2];

    for (i = 0; i < 3; i++) {
        out[i] = tmp[0] * s_mtx_stack->m[i][0] + tmp[1] * s_mtx_stack->m[i][1] +
                  tmp[2] * s_mtx_stack->m[i][2];
    }
}

// Transforms point in by the top matrix.
void func_800193C4(f32 out[3], f32 in[3])
{
    s32 i;

    for (i = 0; i < 3; i++) {
        out[i] = in[0] * s_mtx_stack->m[0][i] + in[1] * s_mtx_stack->m[1][i] +
                  in[2] * s_mtx_stack->m[2][i] + s_mtx_stack->m[3][i];
    }
}

// Transforms point (x, y, z) by the top matrix.
void func_80019480(f32 out[3], f32 x, f32 y, f32 z)
{
    s32 i;

    for (i = 0; i < 3; i++) {
        out[i] = x * s_mtx_stack->m[0][i] + y * s_mtx_stack->m[1][i] +
                       z * s_mtx_stack->m[2][i] + s_mtx_stack->m[3][i];
    }
}

// Transforms the box corners by the top matrix and returns the bounds of the result.
void func_8001953C(s32 out_min[3], s32 out_max[3], s32 in_min[3], s32 in_max[3])
{
    s32 i;
    s32 j;
    f32 corners[8][3];
    f32 *corner = corners[0];

    for (i = 0; i < 8; i++) {
        corner[0] = (i & 1) ? in_max[0] : in_min[0];
        corner[1] = (i & 2) ? in_max[1] : in_min[1];
        corner[2] = (i & 4) ? in_max[2] : in_min[2];
        corner += 3;
    }

    for (i = 0; i < 8; i++) {
        func_80019224(corners[i], corners[i]);
    }

    for (i = 0; i < 3; i++) {
        out_min[i] = out_max[i] = corners[0][i];
    }

    for (i = 1; i < 8; i++) {
        for (j = 0; j < 3; j++) {
            if (corners[i][j] < out_min[j]) {
                out_min[j] = corners[i][j];
            } else if (out_max[j] < corners[i][j]) {
                out_max[j] = corners[i][j];
            }
        }
    }
}

// Applies translation, rotation, scale, then a translation by -pivot; NULL parts are skipped.
void func_80019750(f32 position[3], f32 rotation[3], f32 scale, f32 pivot[3])
{
    if (position != NULL) {
        mlMtxTranslate(position[0], position[1], position[2]);
    }

    if (rotation != NULL) {
        mlMtxRotYaw(rotation[1]);
        mlMtxRotPitch(rotation[0]);
        mlMtxRotRoll(rotation[2]);
    }

    if (scale != 1.0f) {
        mlMtxScale_xyz(scale, scale, scale);
    }

    if (pivot != NULL) {
        mlMtxTranslate(-pivot[0], -pivot[1], -pivot[2]);
    }
}

// Inverse of func_80019750.
void func_8001980C(f32 position[3], f32 rotation[3], f32 scale, f32 pivot[3])
{
    if (pivot != NULL) {
        mlMtxTranslate(pivot[0], pivot[1], pivot[2]);
    }

    if (scale != 1.0f) {
        mlMtxScale_xyz(1.0f / scale, 1.0f / scale, 1.0f / scale);
    }

    if (rotation != NULL) {
        mlMtxRotRoll(-rotation[2]);
        mlMtxRotPitch(-rotation[0]);
        mlMtxRotYaw(-rotation[1]);
    }

    if (position != NULL) {
        mlMtxTranslate(-position[0], -position[1], -position[2]);
    }
}

// Applies translation, then rotation.
void func_800198D4(f32 position[3], f32 rotation[3])
{
    mlMtxTranslate(position[0], position[1], position[2]);
    mlMtxRotRoll(rotation[2]);
    mlMtxRotPitch(rotation[0]);
    mlMtxRotYaw(rotation[1]);
}

// Inverse of func_800198D4.
void func_80019924(f32 position[3], f32 rotation[3])
{
    mlMtxRotYaw(-rotation[1]);
    mlMtxRotPitch(-rotation[0]);
    mlMtxRotRoll(-rotation[2]);
    mlMtxTranslate(-position[0], -position[1], -position[2]);
}

// Rotates about position.
void func_80019994(f32 position[3], f32 rotation[3])
{
    mlMtxTranslate(position[0], position[1], position[2]);
    mlMtxRotRoll(rotation[2]);
    mlMtxRotPitch(rotation[0]);
    mlMtxRotYaw(rotation[1]);
    mlMtxTranslate(-position[0], -position[1], -position[2]);
}

// Inverse rotation about position.
void func_80019A10(f32 position[3], f32 rotation[3])
{
    mlMtxTranslate(position[0], position[1], position[2]);
    mlMtxRotYaw(-rotation[1]);
    mlMtxRotPitch(-rotation[0]);
    mlMtxRotRoll(-rotation[2]);
    mlMtxTranslate(-position[0], -position[1], -position[2]);
}
