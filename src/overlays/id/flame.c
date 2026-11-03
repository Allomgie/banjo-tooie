#include "common.h"

typedef struct FlameModifier {
    u8 pad_0[8];
    s16 local_0;
    u8 pad_1[0x12];
    f32 local_1[8];
    f32 local_2[8];
    f32 local_3[8];
    f32 local_4[8];
} FlameModifier;
extern f32 func_8001395C(f32);
typedef struct {
    f32 local_0;
    f32 local_1;
    s16 local_2;
    u8 local_3;
    u8 pad_0[17];
    f32 local_4[16];
    f32 local_5[16];
} FlameScrollState;
extern f32 func_800D8FF8(void);
extern void _idflame_entrypoint_0(void);
typedef struct {
    f32 unk0;
    f32 unk4;
    u8 pad8[2];
    u8 count;
    u8 padB;
    s16 peaks[8];
    f32 unk1C[8];
    f32 unk3C[8];
    f32 unk5C[8];
    f32 unk7C[8];
} IdFlame;
extern void _glidmake_entrypoint_2();
extern s16 _glidmake_entrypoint_3(s32, s32);
extern void *heap_alloc(s32);
extern void heap_free();
extern void _glid_entrypoint_2(s32, s32, void *, void *);
extern void _idflame_entrypoint_1();
extern f32 func_800DC264(f32, f32);

int func_80800000_idflame(u8 *param_0, s16 param_1)
{
    s32 local_0;
    s16 new_var3;
    u8 *new_var2;
    u8 *new_var;
    new_var3 = param_1;
    local_0 = 0;
    if ((s32) param_0[0xA] > 0) {
        new_var = param_0;
        new_var2 = new_var;
        while (1) {
            if (new_var3 >= *(s16 *) (new_var2 + 12)) {
                local_0 += 1;
                new_var2 += 2;
                if (local_0 >= (s32) param_0[0xA]) {
                    break;
                }
            } else {
                break;
            }
        }
    }
    return local_0;
}

void idflame_entrypoint_0(void *param_0, Vtx *param_1, Vtx *param_2, s32 param_3,
                          FlameModifier *param_4)
{
    Vtx *local_0;
    Vtx *local_1;
    Vtx *local_2;
    s32 local_3;
    s32 local_4;

    local_3 = param_4->local_0;
    local_2 = param_3 + param_1;
    local_0 = param_1;
    local_1 = param_2;
    while (local_0 < local_2) {
        local_1->v.tc[1] = local_0->v.tc[1] + local_3;
        local_4 = func_80800000_idflame(param_4, local_0->v.ob[0]);
        local_1->v.ob[0] =
            local_0->v.ob[0] + param_4->local_4[local_4] *
                                   func_8001395C((param_4->local_1[local_4] - local_0->v.ob[1]) *
                                                 param_4->local_2[local_4]);
        local_0++;
        local_1++;
    }
}

s16 *B_80800560_idflame[2];

void idflame_entrypoint_1(s32 param_0, s16 *param_1, s32 param_2, s32 param_3)
{
    s16 *local_0;
    s16 *local_1;
    s16 local_2;
    local_2 = *param_1;
    for (local_0 = B_80800560_idflame[0]; local_0 < B_80800560_idflame[1]; local_0++) {
        if (local_2 < *local_0)
            break;
    }
    if (local_0 == B_80800560_idflame[1]) {
        *local_0 = local_2;
        B_80800560_idflame[1]++;
        return;
    }
    param_1 = B_80800560_idflame[1] - 1;
    for (local_1 = B_80800560_idflame[1]; local_0 < local_1; local_1--, param_1--) {
        *local_1 = *param_1;
    }
    *local_0 = local_2;
    B_80800560_idflame[1]++;
}

void idflame_entrypoint_2(s32 arg0)
{
}

void idflame_entrypoint_3(IdFlame *param_0, s32 param_1, s32 param_2, s32 param_3)
{
    s16 *u0;
    s32 n;
    f32 dy;
    s16 *p;
    f32 thr;
    s16 a[3];
    s16 b[3];
    f32 scale;
    f32 x;
    s32 i;
    f32 w;

    n = _glidmake_entrypoint_3(param_2, param_3);
    scale = param_1;
    param_0->unk0 = 0;
    param_0->unk4 = scale;
    _glidmake_entrypoint_2(param_2, param_3, a, b);
    u0 = heap_alloc(n * 2);
    if (param_1 && param_1) {
    }
    ((s16 **) B_80800560_idflame)[0] = u0;
    ((s16 **) B_80800560_idflame)[1] = u0;
    ((s16 **) B_80800560_idflame)[2] = u0 + n;
    _glid_entrypoint_2(param_2, param_3, _idflame_entrypoint_1, param_0);
    thr = (b[0] - a[0]) * 0.11f;
    param_0->count = 0;
    for (p = ((s16 **) B_80800560_idflame)[0] + 1; p < ((s16 **) B_80800560_idflame)[1]; p++) {
        x = p[0] - p[-1];
        if (x <= thr) {
            continue;
        }
        if (param_0->count < 8) {
            param_0->peaks[param_0->count] = p[0];
            param_0->count++;
        }
    }
    heap_free((s16 **) B_80800560_idflame[0]);
    if ((s16 **) B_80800560_idflame[0] && (s16 **) B_80800560_idflame[0]) {
    }
    ((s16 **) B_80800560_idflame)[2] = NULL;
    ((s16 **) B_80800560_idflame)[1] = ((s16 **) B_80800560_idflame)[2];
    ((s16 **) B_80800560_idflame)[0] = ((s16 **) B_80800560_idflame)[1];
    dy = b[1] - a[1];
    x = (b[0] - a[0]) * 0.0125f;
    w = param_1 * dy * 0.03125f;
    for (i = 0; i <= param_0->count; i++) {
        param_0->unk1C[i] = 0.0f;
        param_0->unk3C[i] = 6.2831855f / func_800DC264(dy * 0.5f, dy);
        param_0->unk5C[i] = func_800DC264(w * 0.5f, w);
        param_0->unk7C[i] = func_800DC264(x * 2.0f, x * 5.0f);
    }
}

void idflame_entrypoint_4(FlameScrollState *param_0, s32 param_1, s32 param_2)
{
    f32 local_0;
    s32 local_1;
    s32 local_2;

    local_0 = func_800D8FF8();
    param_0->local_0 += param_0->local_1 * 64.0f * local_0;
    local_1 = (s32) param_0->local_0;
    if (local_1 > 8192) {
        param_0->local_0 -= 8192.0f;
        local_1 = (s32) param_0->local_0;
    }
    param_0->local_2 = local_1;
    for (local_2 = 0; local_2 <= param_0->local_3; local_2++) {
        param_0->local_4[local_2] += param_0->local_5[local_2] * local_0;
    }
    _glid_entrypoint_0(param_1, param_2, _idflame_entrypoint_0, param_0);
}
