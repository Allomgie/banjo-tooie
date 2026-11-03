#include "core1/mlmtx.h"
#include "gfx.h"

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
    Gfx *unk0;
    Mtx *unk4;
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

int func_800E36D0(s32 param_0[3], s32 param_1[3], f32 param_2[3], f32 param_3[3])
{
    f32 local_0[3];
    f32 local_1;
    f32 local_2;
    s32 local_3;
    s32 local_4;
    s32 local_5;

    local_2 = 0.0f;

    for (local_3 = 0; local_3 < 2; local_3++) {
        for (local_4 = 0; local_4 < 2; local_4++) {
            for (local_5 = 0; local_5 < 2; local_5++) {
                local_0[0] = (local_3 ? param_0[0] : param_1[0]) - param_2[0];
                local_0[1] = (local_4 ? param_0[1] : param_1[1]) - param_2[1];
                local_0[2] = (local_5 ? param_0[2] : param_1[2]) - param_2[2];

                local_1 =
                    param_3[0] * local_0[0] + param_3[1] * local_0[1] + param_3[2] * local_0[2];

                if (local_2 < local_1) {
                    local_2 = local_1;
                }
            }
        }
    }

    return local_2;
}

func_800E37E8(s32 *param_0, s32 *param_1, s32 param_2)
{
    s32 local_0;
    for (local_0 = 0; local_0 < 3; local_0++) {
        if (param_0[local_0] >= 0) {
            param_0[local_0] /= param_2;
        } else {
            param_0[local_0] = param_0[local_0] / param_2 - 1;
        }
        if (param_1[local_0] >= 0) {
            param_1[local_0] /= param_2;
        } else {
            param_1[local_0] = param_1[local_0] / param_2 - 1;
        }
    }
}

void func_800E3900(f32 param_0)
{
    func_800CA3A4((void *) D_8012D500, param_0);
}

s32 func_800E3928(s32 param_0, s32 param_1)
{
    s32 local_0 = param_1;

    func_800CA704(D_8012D500, param_0, local_0);
}

void func_800E3958(s32 param_0)
{
    func_800CA740(D_8012D500, param_0);
}

s32 func_800E3980(s32 param_0)
{
    s32 local_0 = param_0;
    func_800CA7E4(D_8012D500, local_0);
}

s32 func_800E39A8(enum map_e map_id, s32 param_1)
{
    s32 local_0;
    s32 local_1;
    local_1 = map_id;
    local_0 = param_1;
    func_800CA8B4(D_8012D500, local_1, local_0);
}

s32 func_800E39D8(enum map_e map_id, s32 param_1)
{
    s32 local_0 = map_id;
    s32 local_1 = param_1;

    func_800CA628(D_8012D500, local_0, local_1);
}

s32 func_800E3A08(s32 param_0)
{
    s32 local_0 = param_0;
    func_800CA810(D_8012D500, local_0);
}

s32 func_800E3A30(s32 param_0)
{
    s32 local_0 = param_0;
    func_800CA934(D_8012D500, local_0);
}

s32 func_800E3A58(s32 param_0)
{
    s32 local_0 = param_0;
    func_800CA9D8(D_8012D500, local_0);
}

f32 func_800E3A80()
{
    func_800CAA1C((void *) (int) D_8012D500);
}

s32 func_800E3AA4(f32 param_0)
{
    f32 var_f2;
    var_f2 = (f32) (s32) (func_800E3A80() - param_0);
    if (var_f2 < 0.0f) {
        do {
            var_f2 += 360.0f;
        } while (var_f2 < 0.0f);
    }
    if (var_f2 >= 360.0f) {
        do {
            var_f2 -= 360.0f;
        } while (var_f2 >= 360.0f);
    }
    return (s32) var_f2;
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
    s32 local_0 = param_0;
    func_800CA5B8(D_8012D500, local_0);
}

s32 func_800E3BD4(s32 param_0)
{
    s32 local_0 = param_0;
    func_800CA5D8(D_8012D500, local_0);
}

void func_800E3BFC(f32 param_0, f32 param_1, f32 param_2)
{
    func_800CA5F8((void *) D_8012D500, param_0, param_1, param_2);
}

s32 func_800E3C30(s32 param_0)
{
    s32 local_0 = param_0;
    func_800CA668(D_8012D500, local_0);
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
    s32 local_0 = param_1 | 0;
    s32 local_1 = param_0 | 0;

    func_800CA6D4(D_8012D500, local_1, local_0);
}

void func_800E3CE8()
{
    func_800CAF34((void *) (int) D_8012D500);
}

s32 func_800E3D0C(f32 *param_0, f32 *param_1)
{
    s32 local_0;
    s32 local_3;
    f32 local_1[3];
    f32 local_2[3];
    f32 local_4;
    local_0 = func_800CAA24((f32 *) D_8012D500, param_0, param_1);
    if (func_800BCC58() && !local_0) {
        func_800BCC28(local_1, param_0);
        func_800BCC28(local_2, param_1);
        for (local_3 = 0; local_3 < 3; local_3++) {
            if (local_2[local_3] < local_1[local_3]) {
                local_4 = local_1[local_3];
                local_1[local_3] = local_2[local_3];
                local_2[local_3] = local_4;
            }
        }
        local_0 = func_800CAA24((f32 *) D_8012D500, local_1, local_2);
    }
    return local_0;
}

s32 func_800E3DC0(s32 param_0, s32 param_1)
{
    s32 local_0;
    f32 local_1;
    f32 local_2[3];
    f32 local_3[3];
    f32 *local_4;
    f32 *local_5;
    f32 *local_6;
    local_0 = func_800CAB70((void *) D_8012D500, param_0, param_1);
    if (func_800BCC58() && local_0 == 0) {
        func_800EE88C(local_2, param_0);
        func_800EE88C(local_3, param_1);
        func_800BCC28(local_2, local_2);
        func_800BCC28(local_3, local_3);
        local_5 = local_3;
        local_4 = local_2;
        local_6 = local_2 + 3;
        do {
            if (*local_5 < *local_4) {
                local_1 = *local_4;
                *local_4 = *local_5;
                *local_5 = local_1;
            }
            local_4++;
            local_5++;
        } while (local_4 != local_6);
        local_0 = func_800CAA24((void *) D_8012D500, local_2, local_3);
    }
    return local_0;
}

int func_800E3E8C(s32 param_0, s32 param_1)
{
    s32 local_1;
    f32 new_var[3];
    local_1 = func_800CACEC((int) D_8012D500, param_0, param_1);
    if ((func_800BCC58() != 0) && (local_1 == 0)) {
        func_800BCC28(new_var, param_0);
        local_1 = func_800CACEC((int) D_8012D500, new_var, param_1);
    }
    return local_1;
}

s32 func_800E3EFC(f32 param_0, f32 param_1, f32 param_2)
{
    s32 local_2;
    f32 local_1[3];
    f32 local_0[3];

    local_2 = func_800CAD9C((void *) D_8012D500, param_0, param_1, param_2);
    if ((func_800BCC58() != 0) && (local_2 == 0)) {
        func_800EFA4C(local_0, param_0, param_1, param_2);
        func_800BCC28(local_1, local_0);
        local_2 = func_800CAD9C((void *) D_8012D500, local_1[0], local_1[1], local_1[2]);
    }
    return local_2;
}

s32 func_800E3F8C(f32 param_0, f32 param_1, f32 param_2)
{
    s32 local_2;
    f32 local_1[3];
    f32 local_0[3];

    local_2 = func_800CAEA4((void *) D_8012D500, param_0, param_1, param_2);
    if ((func_800BCC58() != 0) && (local_2 == 0)) {
        func_800EFA4C(local_0, param_0, param_1, param_2);
        func_800BCC28(local_1, local_0);
        local_2 = func_800CAEA4((void *) D_8012D500, local_1[0], local_1[1], local_1[2]);
    }
    return local_2;
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
    f32 local_0[3];
    s32 local_1;
    func_800CA9D8(D_8012D500, param_3);
    func_800EFA4C(local_0, param_0, param_1, 200.0f);
    local_1 = func_800A89F8();
    func_800C4E58(local_1, local_0, param_2);
    return 1.0f;
}

int func_800E4140(s32 arg0, s32 arg1)
{
    int temp_t6;
    s32 sp20;

    temp_t6 = func_800C4C34(func_800A89F8(), arg0, arg1, &sp20);
    return temp_t6 && sp20;
}

void func_800E4190(s32 arg0, s32 arg1, s32 *arg2)
{
    func_800C4C34(func_800A89F8(), arg0, arg1, arg2);
}

void func_800E41CC()
{
    D_8012D504 = func_800CA334();
    func_800CA314(D_8012D504, D_8012D500);
}

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

void func_800E42F0(Unkfunc_800E44FC *arg0, s32 use_widescreen)
{
    Gfx *cur_gfx;
    Mtx *cur_mtx;
    cur_gfx = arg0->unk0;
    cur_mtx = arg0->unk4;

    if (use_widescreen && widescreen_enabled) {
        guOrtho(cur_mtx, -(s32) (SCREEN_WIDTH * 2 * WIDESCREEN_ADJUSTMENT),
                (s32) (SCREEN_WIDTH * 2 * WIDESCREEN_ADJUSTMENT), -SCREEN_HEIGHT * 2,
                SCREEN_HEIGHT * 2, -50.0f, 50.0f, 1.0f);
    } else {
        guOrtho(cur_mtx, -SCREEN_WIDTH * 2, SCREEN_WIDTH * 2, -SCREEN_HEIGHT * 2, SCREEN_HEIGHT * 2,
                -50.0f, 50.0f, 1.0f);
    }

    gSPMatrix(cur_gfx++, OS_K0_TO_PHYSICAL(cur_mtx++),
              G_MTX_PROJECTION | G_MTX_LOAD | G_MTX_NOPUSH);

    D_8012D554 = cur_mtx - 1;

    guMtxIdent(cur_mtx);
    gSPMatrix(cur_gfx++, OS_K0_TO_PHYSICAL(cur_mtx++), G_MTX_MODELVIEW | G_MTX_LOAD | G_MTX_NOPUSH);

    arg0->unk0 = cur_gfx;
    arg0->unk4 = cur_mtx;
}

void func_800E443C(MtxF *base_matrix, f32 *translation, f32 scale)
{
    f32 inv_scale;
    MtxF mat;

    mlMtxSet(base_matrix);

    func_80018C50(func_800CA7AC(D_8012D500));

    inv_scale = 1.0f / scale;

    mat.m[0][0] = mat.m[1][1] = mat.m[2][2] = inv_scale;
    mat.m[0][1] = mat.m[0][2] = mat.m[0][3] = mat.m[1][0] = mat.m[1][2] = mat.m[1][3] =
        mat.m[2][0] = mat.m[2][1] = mat.m[2][3] = 0.0f;
    mat.m[3][0] = -translation[0] * inv_scale;
    mat.m[3][1] = -translation[1] * inv_scale;
    mat.m[3][2] = -translation[2] * inv_scale;
    mat.m[3][3] = 1.0f;

    func_80018C50(&mat);
}

void func_800E44FC(Unkfunc_800E44FC *arg0)
{
    u16 persp_norm;
    MtxF proj;
    f32 translation[3];

    func_800CA7E4(D_8012D500, translation);

    persp_norm = func_800CB124(D_8012D500, &proj);
    gSPPerspNormalize(arg0->unk0++, persp_norm);

    func_800E443C(&proj, translation, func_800CA6E8(D_8012D500));

    if (func_80018BC4()) {
        func_800E443C(&proj, translation, 2.0f * func_800CA6E8(D_8012D500));
    }

    mlMtxApply(arg0->unk4);
    gSPMatrix(arg0->unk0++, OS_K0_TO_PHYSICAL(arg0->unk4++),
              G_MTX_PROJECTION | G_MTX_LOAD | G_MTX_NOPUSH);

    D_8012D558 = arg0->unk4 - 1;

    guMtxIdent(arg0->unk4);
    gSPMatrix(arg0->unk0++, OS_K0_TO_PHYSICAL(arg0->unk4++),
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
    gSPSegment((*gfx)++, 0x08, osVirtualToPhysical(addr));
}
