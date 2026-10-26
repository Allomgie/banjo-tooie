#include "common.h"

extern int D_80800300_chicywind;
extern s32 D_80800348_chicywind;
extern s32 D_80800358_chicywind;
extern f32 func_800DC178(f32, f32);
extern void func_800EF1B8(f32 *, f32, f32);
extern void func_800BBCB8(f32 *, f32 *, f32, s32, void *);
extern f32 func_800D8FF8(void);
extern f32 func_800F10B4(f32, f32, f32, f32, f32);
extern f32 func_800EEAD4(f32 *, f32 *);
extern f32 func_800F1DF4(f32 *, f32 *);
extern void func_800EEB9C(f32 *, f32, f32);
void func_808001AC_chicywind();

int chicywind_entrypoint_0()
{
    return (int)&D_80800300_chicywind;
}

s32 func_8080000C_chicywind(Actor *this){
    if(func_800D0B68(0x21, 0) != 0){
        func_800FFAB0(this);
    }
}

void func_80800044_chicywind(Actor *param_0)
{
    s32 local_2;
    f32 local_1[3];

    local_2 = param_0->unk70_10 == 2;
    if (local_2 || (!local_2 && *((u8 *)param_0 + 0x5F))) {
        _subaddieaudioloop_entrypoint_4(param_0, param_0->position, local_2, &D_80800348_chicywind);
    }
    if (func_800D0B68(0x21, 0)) {
        func_800FFAB0(param_0);
        return;
    }
    switch (param_0->unk70_10) {
    case 1:
        if (func_8010C9B0(param_0->position, 1000)) {
            func_80101FDC(param_0, 2);
            param_0->unk58 = func_800DC178(0.15f, 0.2f);
        }
        break;
    case 2:
        if (func_800D9078(&param_0->unk58)) {
            func_800EE7F8(local_1, param_0->position);
            func_800EF1B8(local_1, *(f32 *)((u8 *)param_0 + 0x48), -200.0f);
            func_800BBCB8(param_0->position, local_1, 1.0f, 1, &D_80800358_chicywind);
            param_0->unk58 = func_800DC178(0.15f, 0.2f);
        }
        func_808001AC_chicywind(param_0);
        if (!func_8010C9B0(param_0->position, 1800)) func_80101FDC(param_0, 1);
        break;
    }
}

void func_808001AC_chicywind(param_0) Actor *param_0;
{
    f32 local_0[3];
    f32 local_1[3];
    f32 local_6;
    f32 local_2;
    f32 local_3;
    s32 local_4;

    local_4 = func_800F54E4();
    switch (func_800F5410(local_4)) {
        default:
            local_3 = 0.85f;
            break;
        case 11:
        case 17:
            local_3 = 0.65f;
            break;
        case 2:
            local_3 = func_800F10B4(func_800F5578(local_4), 1.0f, func_800F55A4(local_4), 0.6f, 1.0f);
            break;
    }
    func_800F5A00(local_4, local_1);
    local_6 = func_800EEAD4(local_1, param_0->position);
    local_2 = func_800F10B4(local_6,
        1000.0f, 1800.0f, 1200.0f, 300.0f) * (1.0f / local_3);
    func_800EEB9C(local_0, func_800F1DF4(param_0->position, local_1), local_2);
    func_800F48BC(local_4, local_0);
}
