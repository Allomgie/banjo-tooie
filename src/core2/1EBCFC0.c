// Facade over the current viewport: position, rotation and FOV accessors, frustum tests,
// world-to-screen projection, and perspective and ortho matrix builders.
#include <ultra64.h>
#include <PR/gbi.h>
#include "core1/mlmtx.h"
#include "gfx.h"

// Facade over the current viewport object D_8012D500 (implemented in core2/1EA3AA0.c).
extern void func_800CA3A4(void *, f32);
extern void func_800CA704();
extern void func_800CA740(s32, s32);
extern void func_800CA8B4();
extern void func_800CA628();
extern void func_800CA810();
extern void func_800CA934();
extern void func_800CAA1C();
extern void func_800CAA00(void *param_0, s32 param_1, s32 param_2, s32 param_3);
extern void func_800CA440();
extern void func_800CA5B8();
extern void func_800CA5D8();
extern void func_800CA5F8(void *, f32, f32, f32);
extern void func_800CA668();
extern void func_800CA688(void *, f32, f32, f32);
extern void func_800CA6C0(void *arg0, f32 arg1, f32 arg2);
extern void func_800CA6D4();
extern void func_800CAF34();
extern s32 func_800CAA24(void *, f32 *, f32 *);
extern s32 func_800BCC58(void);
extern void func_800BCC28(f32 *, f32 *);
extern s32 func_800CAB70(void *, s32, s32);
extern void func_800EE88C(f32 *, s32);
extern s32 func_800CAD9C(void *, f32, f32, f32);
extern void func_800EFA4C(f32 *, f32, f32, f32);
extern s32 func_800CAEA4(void *, f32, f32, f32);
extern void func_800CA6FC();
extern void func_800CA7B4();
extern void func_800CAF00(void *param_0, f32 param_1);
extern void func_800CA9D8(s32 *a0, s32 a1);
extern void func_800C4E58(s32 a0, f32 *a1, s32 a2);

typedef struct {
    Gfx *gfx;
    Mtx *mtx;
} Unkfunc_800E44FC;

extern s32 D_8012D500;
extern s32 D_8012D504;
extern s32 D_8012D508;
extern MtxF D_8012D510;
extern u16 D_8012D550;
extern Mtx *D_8012D554;
extern Mtx *D_8012D558;

s32 func_80018BC4();
s32 func_800A89F8();
s32 func_800C4C34(s32, s32, s32, s32 *);
void func_800CA314(s32, s32);
s32 func_800CA334();
void func_800CA364(s32);
void func_800CA3F4(s32, s32, f32);
f32 func_800CA6E8(s32);
MtxF *func_800CA7AC(s32);
void func_800CA7E4(s32, f32[3]);
u16 func_800CB124(s32, MtxF *);

// AABB helpers: corner projection along a direction, floor-division of integer bounds.
// Largest projection onto `dir` of the vectors from `origin` to the 8 box corners.
int func_800E36D0(s32 corner_a[3], s32 corner_b[3], f32 origin[3], f32 dir[3])
{
    f32 offset[3];
    f32 dot;
    f32 best;
    s32 i;
    s32 j;
    s32 k;

    best = 0.0f;

    for (i = 0; i < 2; i++) {
        for (j = 0; j < 2; j++) {
            for (k = 0; k < 2; k++) {
                offset[0] = (i ? corner_a[0] : corner_b[0]) - origin[0];
                offset[1] = (j ? corner_a[1] : corner_b[1]) - origin[1];
                offset[2] = (k ? corner_a[2] : corner_b[2]) - origin[2];

                dot =
                    dir[0] * offset[0] + dir[1] * offset[1] + dir[2] * offset[2];

                if (best < dot) {
                    best = dot;
                }
            }
        }
    }

    return best;
}

// Floor-divides the integer AABB bounds by `divisor`.
func_800E37E8(s32 *lo, s32 *hi, s32 divisor)
{
    s32 i;
    for (i = 0; i < 3; i++) {
        if (lo[i] >= 0) {
            lo[i] /= divisor;
        } else {
            lo[i] = lo[i] / divisor - 1;
        }
        if (hi[i] >= 0) {
            hi[i] /= divisor;
        } else {
            hi[i] = hi[i] / divisor - 1;
        }
    }
}

// Viewport accessors, frustum culling, world-to-screen, projection and ortho matrix setup.
void func_800E3900(f32 param_0)
{
    func_800CA3A4((void *) D_8012D500, param_0);
}

s32 func_800E3928(s32 param_0, s32 param_1)
{
    // Matching: extra local copy needed for the match.
    s32 unk_0 = param_1;

    func_800CA704(D_8012D500, param_0, unk_0);
}

void func_800E3958(s32 param_0)
{
    func_800CA740(D_8012D500, param_0);
}

s32 func_800E3980(s32 param_0)
{
    // Matching: extra local copy needed for the match.
    s32 unk_0 = param_0;
    func_800CA7E4(D_8012D500, unk_0);
}

s32 func_800E39A8(enum map_e map_id, s32 param_1)
{
    // Matching: extra locals needed for the match.
    s32 unk_0;
    s32 unk_1;
    unk_1 = map_id;
    unk_0 = param_1;
    func_800CA8B4(D_8012D500, unk_1, unk_0);
}

s32 func_800E39D8(enum map_e map_id, s32 param_1)
{
    // Matching: extra locals needed for the match.
    s32 unk_0 = map_id;
    s32 unk_1 = param_1;

    func_800CA628(D_8012D500, unk_0, unk_1);
}

s32 func_800E3A08(s32 param_0)
{
    // Matching: extra local copy needed for the match.
    s32 unk_0 = param_0;
    func_800CA810(D_8012D500, unk_0);
}

s32 func_800E3A30(s32 param_0)
{
    // Matching: extra local copy needed for the match.
    s32 unk_0 = param_0;
    func_800CA934(D_8012D500, unk_0);
}

s32 func_800E3A58(s32 param_0)
{
    // Matching: extra local copy needed for the match.
    s32 unk_0 = param_0;
    func_800CA9D8(D_8012D500, unk_0);
}

f32 func_800E3A80()
{
    func_800CAA1C((void *) (int) D_8012D500);
}

// Wraps (func_800E3A80() - angle) into [0, 360).
s32 func_800E3AA4(f32 angle)
{
    f32 diff;
    diff = (f32) (s32) (func_800E3A80() - angle);
    if (diff < 0.0f) {
        do {
            diff += 360.0f;
        } while (diff < 0.0f);
    }
    if (diff >= 360.0f) {
        do {
            diff -= 360.0f;
        } while (diff >= 360.0f);
    }
    return (s32) diff;
}

void func_800E3B50(s32 param_0, s32 param_1, s32 param_2)
{
    func_800CAA00((void *) D_8012D500, param_0, param_1, param_2);
}

void func_800E3B88()
{
    func_800CA440((void *) (int) D_8012D500);
}

s32 func_800E3BAC(s32 param_0)
{
    // Matching: extra local copy needed for the match.
    s32 unk_0 = param_0;
    func_800CA5B8(D_8012D500, unk_0);
}

s32 func_800E3BD4(s32 param_0)
{
    // Matching: extra local copy needed for the match.
    s32 unk_0 = param_0;
    func_800CA5D8(D_8012D500, unk_0);
}

void func_800E3BFC(f32 param_0, f32 param_1, f32 param_2)
{
    func_800CA5F8((void *) D_8012D500, param_0, param_1, param_2);
}

s32 func_800E3C30(s32 param_0)
{
    // Matching: extra local copy needed for the match.
    s32 unk_0 = param_0;
    func_800CA668(D_8012D500, unk_0);
}

void func_800E3C58(f32 param_0, f32 param_1, f32 param_2)
{
    func_800CA688((void *) D_8012D500, param_0, param_1, param_2);
}

void func_800E3C8C(f32 param_0, f32 param_1)
{
    func_800CA6C0((void *) D_8012D500, param_0, param_1);
}

s32 func_800E3CB8(s32 param_0, s32 param_1)
{
    // Matching: `| 0` and the local copies are needed for the match.
    s32 unk_0 = param_1 | 0;
    s32 unk_1 = param_0 | 0;

    func_800CA6D4(D_8012D500, unk_1, unk_0);
}

void func_800E3CE8()
{
    func_800CAF34((void *) (int) D_8012D500);
}

// Frustum test for a float AABB; retried in mirrored space when a mirror is active.
s32 func_800E3D0C(f32 *box_min, f32 *box_max)
{
    s32 result;
    s32 i;
    f32 mirror_min[3];
    f32 mirror_max[3];
    f32 tmp;
    result = func_800CAA24((f32 *) D_8012D500, box_min, box_max);
    if (func_800BCC58() && !result) {
        func_800BCC28(mirror_min, box_min);
        func_800BCC28(mirror_max, box_max);
        for (i = 0; i < 3; i++) {
            if (mirror_max[i] < mirror_min[i]) {
                tmp = mirror_min[i];
                mirror_min[i] = mirror_max[i];
                mirror_max[i] = tmp;
            }
        }
        result = func_800CAA24((f32 *) D_8012D500, mirror_min, mirror_max);
    }
    return result;
}

// Frustum test for an integer AABB; retried in mirrored space when a mirror is active.
s32 func_800E3DC0(s32 box_min, s32 box_max)
{
    s32 result;
    f32 tmp;
    f32 min_vec[3];
    f32 max_vec[3];
    f32 *min_ptr;
    f32 *max_ptr;
    f32 *end;
    result = func_800CAB70((void *) D_8012D500, box_min, box_max);
    if (func_800BCC58() && result == 0) {
        func_800EE88C(min_vec, box_min);
        func_800EE88C(max_vec, box_max);
        func_800BCC28(min_vec, min_vec);
        func_800BCC28(max_vec, max_vec);
        max_ptr = max_vec;
        min_ptr = min_vec;
        end = min_vec + 3;
        do {
            if (*max_ptr < *min_ptr) {
                tmp = *min_ptr;
                *min_ptr = *max_ptr;
                *max_ptr = tmp;
            }
            min_ptr++;
            max_ptr++;
        } while (min_ptr != end);
        result = func_800CAA24((void *) D_8012D500, min_vec, max_vec);
    }
    return result;
}

// Frustum test; retried in mirrored space when a mirror is active.
int func_800E3E8C(s32 pos, s32 param_1)
{
    s32 result;
    f32 mirrored[3];
    result = func_800CACEC((int) D_8012D500, pos, param_1);
    if ((func_800BCC58() != 0) && (result == 0)) {
        func_800BCC28(mirrored, pos);
        result = func_800CACEC((int) D_8012D500, mirrored, param_1);
    }
    return result;
}

// Frustum test for a point; retried in mirrored space when a mirror is active.
s32 func_800E3EFC(f32 x, f32 y, f32 z)
{
    s32 result;
    f32 mirrored[3];
    f32 pos[3];

    result = func_800CAD9C((void *) D_8012D500, x, y, z);
    if ((func_800BCC58() != 0) && (result == 0)) {
        func_800EFA4C(pos, x, y, z);
        func_800BCC28(mirrored, pos);
        result = func_800CAD9C((void *) D_8012D500, mirrored[0], mirrored[1], mirrored[2]);
    }
    return result;
}

// Same as func_800E3EFC with a different frustum test (func_800CAEA4).
s32 func_800E3F8C(f32 x, f32 y, f32 z)
{
    s32 result;
    f32 mirrored[3];
    f32 pos[3];

    result = func_800CAEA4((void *) D_8012D500, x, y, z);
    if ((func_800BCC58() != 0) && (result == 0)) {
        func_800EFA4C(pos, x, y, z);
        func_800BCC28(mirrored, pos);
        result = func_800CAEA4((void *) D_8012D500, mirrored[0], mirrored[1], mirrored[2]);
    }
    return result;
}

s32 func_800E401C(void)
{
    int size;
    size = func_800CA7A4(D_8012D500);
}

void func_800E4040()
{
    func_800CA7AC((void *) (int) D_8012D500);
}

void func_800E4064()
{
    func_800CA6FC((void *) (int) D_8012D500);
}

void func_800E4088()
{
    func_800CA7B4((void *) D_8012D500);
}

void func_800E40AC(s32 param_0, f32 param_1)
{
    func_800CAF00((void *) D_8012D500, param_1);
}

f32 func_800E40DC(f32 param_0, f32 param_1, s32 param_2, u32 param_3)
{
    f32 pos[3];
    s32 player;
    func_800CA9D8(D_8012D500, param_3);
    func_800EFA4C(pos, param_0, param_1, 200.0f);
    player = func_800A89F8();
    func_800C4E58(player, pos, param_2);
    return 1.0f;
}

// World-to-screen projection for the current player.
int func_800E4140(s32 arg0, s32 arg1)
{
    int result;
    s32 unk_0;

    result = func_800C4C34(func_800A89F8(), arg0, arg1, &unk_0);
    return result && unk_0;
}

void func_800E4190(s32 arg0, s32 arg1, s32 *arg2)
{
    func_800C4C34(func_800A89F8(), arg0, arg1, arg2);
}

// Pushes: saves a copy of the current viewport.
void func_800E41CC()
{
    D_8012D504 = func_800CA334();
    func_800CA314(D_8012D504, D_8012D500);
}

// Pops: restores the saved viewport.
void func_800E4208()
{
    func_800CA314(D_8012D500, D_8012D504);
    func_800CA364(D_8012D504);
    D_8012D504 = 0;
}

void func_800E4244(s32 arg0, f32 arg1)
{
    func_800CA3F4(D_8012D500, arg0, arg1);
}

void func_800E4278()
{
    D_8012D500 = D_8012D504 = 0;
}

void func_800E4290()
{
    D_8012D500 = D_8012D504 = 0;
}

s32 func_800E42A8()
{
    return D_8012D500;
}

void func_800E42B4(s32 arg0)
{
    D_8012D500 = arg0;
}

f32 func_800E42C0()
{
    return func_800CA6E8(D_8012D500);
}

void func_800E42E4(s32 arg0)
{
    D_8012D508 = arg0;
}

// Builds an orthographic projection matrix and an identity model matrix and loads them
// into the display list; use_widescreen adjusts the projection for anamorphic widescreen.
void func_800E42F0(Unkfunc_800E44FC *ctx, s32 use_widescreen)
{
    Gfx *cur_gfx;
    Mtx *cur_mtx;
    cur_gfx = ctx->gfx;
    cur_mtx = ctx->mtx;

    // Left/right bounds depend on whether widescreen is requested and enabled.
    if (use_widescreen && widescreen_enabled) {
        // Approximately 16:9 (truncated to an integer).
        guOrtho(cur_mtx, -(s32) (SCREEN_WIDTH * 2 * WIDESCREEN_ADJUSTMENT),
                (s32) (SCREEN_WIDTH * 2 * WIDESCREEN_ADJUSTMENT), -SCREEN_HEIGHT * 2,
                SCREEN_HEIGHT * 2, -50.0f, 50.0f, 1.0f);
    } else {
        // 4:3.
        guOrtho(cur_mtx, -SCREEN_WIDTH * 2, SCREEN_WIDTH * 2, -SCREEN_HEIGHT * 2, SCREEN_HEIGHT * 2,
                -50.0f, 50.0f, 1.0f);
    }

    // Load the ortho matrix.
    gSPMatrix(cur_gfx++, OS_K0_TO_PHYSICAL(cur_mtx++),
              G_MTX_PROJECTION | G_MTX_LOAD | G_MTX_NOPUSH);

    // Remember it.
    D_8012D554 = cur_mtx - 1;

    // Identity matrix into the model stack.
    guMtxIdent(cur_mtx);
    gSPMatrix(cur_gfx++, OS_K0_TO_PHYSICAL(cur_mtx++), G_MTX_MODELVIEW | G_MTX_LOAD | G_MTX_NOPUSH);

    ctx->gfx = cur_gfx;
    ctx->mtx = cur_mtx;
}

// Loads base_matrix, multiplies in the view rotation matrix, then multiplies in a
// translation and scale matrix built from the inverse of `translation` and `scale`.
void func_800E443C(MtxF *base_matrix, f32 *translation, f32 scale)
{
    f32 inv_scale;
    MtxF mat;

    mlMtxSet(base_matrix);

    func_80018C50(func_800CA7AC(D_8012D500));

    inv_scale = 1.0f / scale;

    // Diagonal (scale), then zeros.
    mat.m[0][0] = mat.m[1][1] = mat.m[2][2] = inv_scale;
    mat.m[0][1] = mat.m[0][2] = mat.m[0][3] = mat.m[1][0] = mat.m[1][2] = mat.m[1][3] =
        mat.m[2][0] = mat.m[2][1] = mat.m[2][3] = 0.0f;
    // Bottom row: inverse translation with the inverse scale applied.
    mat.m[3][0] = -translation[0] * inv_scale;
    mat.m[3][1] = -translation[1] * inv_scale;
    mat.m[3][2] = -translation[2] * inv_scale;
    mat.m[3][3] = 1.0f;

    func_80018C50(&mat);
}

// Builds the perspective view-projection ("viewproj") matrix and an identity model matrix
// and loads them into the display list. Here "model" and "viewproj" mean G_MTX_MODELVIEW
// and G_MTX_PROJECTION: the view matrix goes in the PROJECTION stack, which gives
// world-space lighting independent of the camera.
void func_800E44FC(Unkfunc_800E44FC *ctx)
{
    u16 persp_norm;
    MtxF proj;
    f32 translation[3];

    // Translation for the view matrix.
    func_800CA7E4(D_8012D500, translation);

    // Projection matrix and its perspnorm value.
    persp_norm = func_800CB124(D_8012D500, &proj);
    gSPPerspNormalize(ctx->gfx++, persp_norm);

    // Viewproj from projection, translation and world scale.
    func_800E443C(&proj, translation, func_800CA6E8(D_8012D500));

    // If it does not fit a fixed-point matrix, rebuild with half the scale.
    if (func_80018BC4()) {
        func_800E443C(&proj, translation, 2.0f * func_800CA6E8(D_8012D500));
    }

    // Convert to fixed point and load as the viewproj matrix.
    mlMtxApply(ctx->mtx);
    gSPMatrix(ctx->gfx++, OS_K0_TO_PHYSICAL(ctx->mtx++),
              G_MTX_PROJECTION | G_MTX_LOAD | G_MTX_NOPUSH);

    // Remember it.
    D_8012D558 = ctx->mtx - 1;

    // Identity matrix into the model stack.
    guMtxIdent(ctx->mtx);
    gSPMatrix(ctx->gfx++, OS_K0_TO_PHYSICAL(ctx->mtx++),
              G_MTX_MODELVIEW | G_MTX_LOAD | G_MTX_NOPUSH);
}

void func_800E4628()
{
    D_8012D558 = D_8012D554 = NULL;
}

void func_800E4640(Gfx **gfx)
{
    if (D_8012D508 != 0) {
        gSPDisplayList((*gfx)++, 0x08000000);
        return;
    }
    gSPMatrix((*gfx)++, OS_K0_TO_PHYSICAL(D_8012D558),
              G_MTX_PROJECTION | G_MTX_LOAD | G_MTX_NOPUSH);
}

void func_800E46A4(f32 out[4], f32 in[4])
{
    func_800F2D34(&D_8012D510, out, in);
}

u16 func_800E46D4()
{
    return D_8012D550;
}

void func_800E46E0(Gfx **gfx, void *addr)
{
    // TODO: figure out what segment 8 is.
    gSPSegment((*gfx)++, 0x08, osVirtualToPhysical(addr));
}
