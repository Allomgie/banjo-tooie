// Probably a guLookAtReflect equivalent: builds a reflection look-at from eye/at/up vectors.
#include "common.h"
#include "core2/1EC8070.h"

extern void func_800F2984(f32 param_0[4][4], f32 *param_1, f32 param_2[3], f32 param_3[3],
                          f32 param_4[3]);

// guLookAtReflect equivalent.
void func_80013C80(Mtx *mtx, f32 *look_at, f32 eye_x, f32 eye_y, f32 eye_z, f32 at_x,
                   f32 at_y, f32 at_z, f32 up_x, f32 up_y, f32 up_z)
{
    f32 mtx_f[4][4];
    f32 eye[3];
    f32 at[3];
    f32 up[3];

    func_800EFA4C(eye, eye_x, eye_y, eye_z);
    func_800EFA4C(at, at_x, at_y, at_z);
    func_800EFA4C(up, up_x, up_y, up_z);
    func_800F2984(mtx_f, look_at, eye, at, up);
    guMtxF2L(mtx_f, mtx);
}
