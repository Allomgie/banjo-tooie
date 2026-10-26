#include "common.h"
#include "vector.h"

extern void *D_80800560_gclightsDll;
extern void *D_8080056C_gclightsDll;
extern void *D_80800578_gclightsDll;
extern void func_800C8C90(void *);
extern void func_800C8F08(void *, void *);
typedef struct { s32 position[3]; u8 pad_0[8]; u8 enabled; u8 active; u8 pad_1; u8 visible; u32 pad_2; } LightEntry29;
extern void func_800EE88C(f32 *, s32 *);
extern f32 func_800EEAD4(f32 *, f32 *);
s32 gclightsDll_entrypoint_4();
s32 gclightsDll_entrypoint_5();

void func_80800000_gclightsDll(s32 arg0)
{
    gclightsDll_entrypoint_1();
    _gclightsDll_entrypoint_0(arg0);
}
void gclightsDll_entrypoint_0(s32 *param_0)
{
    *param_0 = vector_new(0x1C, 1);
    func_800C8C90(&D_80800560_gclightsDll);
    gclightsDll_entrypoint_5(&D_8080056C_gclightsDll);
    func_800C8F08(&D_8080056C_gclightsDll, &D_80800578_gclightsDll);
}

int gclightsDll_entrypoint_1(void *param_0)
{
    vector_free(*(void **)((char *)param_0 + 0x0));
}

void gclightsDll_entrypoint_2(s32 param_0, void *param_1)
{
    s32 unused_slot0;
    s32 *local_13;
    Vector *local_0;
    f32 local_1[3];
    f32 local_2[2];
    s32 local_3[3];
    u8 local_4;
    s32 local_10;
    s32 local_5[3];
    s32 local_6[3];
    s32 *local_12;
    s32 *local_11;
    s32 local_7[3];
    f32 local_8[3];
    s32 local_9[3];


    local_0 = vector_new(4, 0x10);
    func_80800000_gclightsDll(param_0);
    if (!_gsmaker_entrypoint_16(param_1, 0)) {
        do {
            if (_gsmaker_entrypoint_16(param_1, 1)
                && _gsmaker_entrypoint_20(param_1, 2, local_1, 3)
                && _gsmaker_entrypoint_20(param_1, 3, local_2, 2)
                && _gsmaker_entrypoint_22(param_1, 4, local_3, 3)) {
                local_10 = gclightsDll_entrypoint_4();
                func_800C8CB8(local_10, local_1);
                func_800C8D4C(local_10, local_2);
                func_800C8E84(local_10, local_3);
                if (_gsmaker_entrypoint_17(param_1, 7, &local_4)) {
                    func_800C8F64(local_10, local_4);
                }
            } else if (_gsmaker_entrypoint_16(param_1, 5)
                       && _gsmaker_entrypoint_22(param_1, 4, local_5, 3)) {
                func_800C8C90(local_5);
            } else if (_gsmaker_entrypoint_16(param_1, 6)
                       && _gsmaker_entrypoint_22(param_1, 4, local_6, 3)) {
                gclightsDll_entrypoint_5(local_6);
            } else if (_gsmaker_entrypoint_16(param_1, 8)) {
                local_10 = gclightsDll_entrypoint_4();
                local_13 = vector_push_back(&local_0);
                *local_13 = local_10;
            } else if (_gsmaker_entrypoint_16(param_1, 9)
                       && _gsmaker_entrypoint_20(param_1, 2, local_8, 3)
                       && _gsmaker_entrypoint_22(param_1, 4, local_7, 3)) {
                func_800C8F08(local_7, local_8);
            } else if (_gsmaker_entrypoint_16(param_1, 10)) {
                _gsmaker_entrypoint_22(param_1, 4, local_9, 3);
            }
        } while (!_gsmaker_entrypoint_16(param_1, 0));
    }
    local_12 = vector_end(local_0);
    for (local_11 = vector_begin(local_0); local_11 < local_12; local_11++) {
        func_800C8B84(*local_11);
    }
    vector_free(local_0);
}

s32 gclightsDll_entrypoint_3(Vector **param_0, f32 *param_1)
{
    LightEntry29 *local_0;
    LightEntry29 *local_1;
    LightEntry29 *local_2;
    LightEntry29 *local_3;
    f32 local_5;
    f32 local_6;
    f32 local_4[3];
    s32 local_7;
    local_0 = vector_begin(*param_0);
    local_1 = vector_end(*param_0);
    local_6 = -1.0f;
    local_3 = 0;
    for (local_2 = local_0; local_2 < local_1; local_2++) {
        if (local_2->active && local_2->enabled && local_2->visible) {
            func_800EE88C(local_4, local_2->position);
            local_5 = func_800EEAD4(param_1, local_4);
            if (!local_3 || local_5 < local_6) {
                local_3 = local_2;
                local_6 = local_5;
            }
        }
    }
    if (local_3) local_7 = ((s32)((u8 *)local_3 - (u8 *)local_0) + 0x1C) / 28;
    else local_7 = 0;
    return local_7;
}

s32 gclightsDll_entrypoint_4(void) {
    s32 *local_0;
    u32 local_1;
    u32 local_5;
    s32 local_4;
    u8 *local_7;

    local_0 = func_800C911C();
    local_1 = vector_begin(*local_0);
    local_5 = vector_end(*local_0);
    if (local_1 < local_5) {
        do {
            if (*(u8 *)((char *)local_1 + 0x14) == 0) {
                *(s8 *)((char *)local_1 + 0x15) = 0;
            }
            local_1 += 0x1C;
        } while (local_1 < local_5);
    }
    local_4 = func_800C8A98(local_5);
    local_7 = vector_at(*local_0, local_4 - 1);
    *(s8 *)((char *)local_7 + 0x14) = 1;
    *(s8 *)((char *)local_7 + 0x15) = 0xD;
    return local_4;
}

s32 gclightsDll_entrypoint_5(param_0) s32 param_0;
{
  func_800EE830(func_800C911C() + 0x10, param_0);
}
