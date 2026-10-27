#include "common.h"

extern int D_80800200_chbonfirecavern;
extern u8 D_808002A0_chbonfirecavern[];
extern u8 D_80800248_chbonfirecavern[];
extern void func_800BABB8(s32, f32 *, s32, f32, void *);
typedef union { u8 *local_0; s32 local_1; } BonfireEvent;

int chbonfirecavern_entrypoint_0()
{
    return (int)&D_80800200_chbonfirecavern;
}

void func_8080000C_chbonfirecavern(Actor *param_0)
{
    extern void _chfirefx_entrypoint_2(Actor *, f32, f32, s32, s32);
    extern void func_80102FDC(Actor *, f32);

    _chfirefx_entrypoint_2(param_0, param_0->scale, (f32)param_0->unk74_7, 30, 5);
    _chfirefx_entrypoint_6(param_0, 500, 4000);
    func_80102FDC(param_0, 1.0f);
}

s32 func_80800080_chbonfirecavern(Actor *param_0, s32 param_1, BonfireEvent param_2)
{
    Actor *local_0;
    f32 *local_1;
    switch (param_1) {
    case 0x40:
        if (*(u16 *)(param_2.local_0 + 0x18) & 1) func_8010114C(param_2.local_0, 0x92, 0);
        if (param_2.local_0) {
        }
        func_80101FDC(param_0, 2);
        break;
    case 0x3F:
        if (*(u16 *)(param_2.local_0 + 0x18) & 1) func_8010114C(param_2.local_0, 0x92, 0);
        if (param_2.local_0) {
        }
        if (param_0->unk70_10 == 2) {
            local_1 = param_0->position;
            _subaddieaudioquick_entrypoint_2(param_0, local_1, D_808002A0_chbonfirecavern);
            func_800BABB8(0, local_1, 0, 1.0f, D_80800248_chbonfirecavern);
        }
        func_80101FDC(param_0, 1);
        func_8010A570(param_0);
        ((f32 *)param_0->actorData)[3] = 6.0f;
        break;
    default:
        return _chfirefx_entrypoint_5(param_0, param_1, param_2.local_0);
    }
    return 1;
}

void func_80800190_chbonfirecavern(u8 *param_0) {
    s32 local_0;

    local_0 = func_800D9078(param_0 + 0x24);
    _chfirefx_entrypoint_3(param_0);
    if ((local_0 != 0) && (((u32)((u16) (*(u16 *)((s8 *)(param_0) + (0x72)))) >> 0xA) == 1)) {
        func_80101FDC(param_0, 2);
        func_8010A590(param_0);
    }
}
