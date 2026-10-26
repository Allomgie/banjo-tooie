#include "common.h"

extern void func_800F5A00(s32, f32 *);
extern f32 func_800EEAD4(f32 *, f32 *);
extern void func_800EE7F8(f32 *, f32 *);
extern f32 func_80103EAC(Actor *);
extern void _chdoormake_entrypoint_2(Actor *, f32, f32, f32, s32, s32);
extern void _chdoormake_entrypoint_5(Actor *, f32);
extern void _chdoormake_entrypoint_6(Actor *, f32);
extern f32 func_800F1DF4(f32 *, f32 *);
extern f32 func_800F2094(f32, f32);
extern int D_808002E0_chsmalltrexdoor;

void func_80800000_chsmalltrexdoor(Actor *param_0)
{
    f32 local_0[3];
    f32 local_1[3];
    if (func_800F5410(func_800F54E4()) == 0x12) {
        func_800F5A00(func_800F54E4(), local_0);
        if (func_800EEAD4(local_0, param_0->position) < 500.0f) {
            param_0->unk64_20 = 1;
            func_80101FDC(param_0, 4);
        }
    }
    func_800EE7F8(local_0, param_0->position);
    local_0[1] += 100.0f;
    param_0->position[1] -= 100.0f;
    func_800BEF00(local_0, param_0->position, local_1, 0);
    param_0->position[1] += func_80103EAC(param_0);
    _chdoormake_entrypoint_2(param_0, param_0->rotation[1] + 90.0f, 0.0f, param_0->scale * 200.0f, 10, -1);
    _chdoormake_entrypoint_5(param_0, 1.0f);
    _chdoormake_entrypoint_6(param_0, 0.5f);
    _chdoormake_entrypoint_8(param_0, 5);
}

void func_80800150_chsmalltrexdoor(Actor *param_0)
{
    f32 local_0[3];
    f32 local_1;

    if (param_0->unk70_10 == 4 && func_800D90A4((f32 *)((u8 *)param_0 + 0x34))) {
        func_800F5A00(func_800F54E4(), local_0);
        local_1 = func_800F1DF4(param_0->position, local_0);
        if (func_800EEAD4(local_0, param_0->position) < 400.0f) {
            if (func_800F2094(param_0->rotation[1] - 90.0f, local_1) > 30.0f) {
                func_8010108C(param_0, 8, 0);
            }
        } else {
            func_8010108C(param_0, 8, 0);
        }
    }
    _chdoor_entrypoint_0(param_0);
}

void func_80800244_chsmalltrexdoor(Actor *param_0, s32 param_1, s32 param_2)
{
    if (param_1 == 0x1D || param_1 == 0x1E) {
        if (func_800F52B8(func_800F54E4(), param_0->unk0) == 0x18) {
            ((f32 *)param_0->actorData)[7] = 4.0f;
            _chdoor_entrypoint_1(param_0, 7, 0);
            return;
        }
    }
    _chdoor_entrypoint_1(param_0, param_1, param_2);
}

int *chsmalltrexdoor_entrypoint_0()
{
    return &D_808002E0_chsmalltrexdoor;
}
