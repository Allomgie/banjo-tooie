#include "common.h"

extern int D_80800110_changlerbossdoor;
extern void func_800F1A88();
extern void func_80101FDC();
typedef struct AnglerDoorFlags { u8 pad_0 : 7; u8 local_0 : 1; } AnglerDoorFlags;
extern void func_80102FDC(Actor *, f32);
extern void func_800EF6A8(f32 *, f32 *, f32, f32, f32);
extern s32 _chdoormake_entrypoint_3(Actor *, f32, f32, f32, s32, s32);
extern void _chdoormake_entrypoint_5(Actor *, f32);
extern void _chdoormake_entrypoint_6(Actor *, f32);

int *changlerbossdoor_entrypoint_0()
{
    return &D_80800110_changlerbossdoor;
}

void func_8080000C_changlerbossdoor(Actor *param_0)
{
    f32 local_0[3];
    f32 local_1[3];
    s32 local_2;

    local_2 = func_800DA298(0x1AF) != 0;
    if (!local_2) {
        local_2 = _glcutDll_entrypoint_20() != 0;
    }

    if (local_2) {
        func_80101FDC(param_0, 1);
    }
    func_80102FDC(param_0, param_0->scale * 1.75f);
    ((AnglerDoorFlags *)((u8 *)param_0 + 0x73))->local_0 = 1;
    func_800EF6A8(local_1, param_0->rotation, 0.0f, 500.0f, 0.0f);
    func_800F1A88(local_1, local_0);
    if (_chdoormake_entrypoint_3(param_0, local_0[1], local_0[0], 500.0f, 0x802, -1)) {
        _chdoormake_entrypoint_5(param_0, 3.0f);
        _chdoormake_entrypoint_6(param_0, 0.8f);
        _chdoormake_entrypoint_8(param_0, 5);
    }
}
