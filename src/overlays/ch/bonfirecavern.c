#include "common.h"

extern int D_80800200_chbonfirecavern[];
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

/* TU-NOTE: the .data of this overlay (formerly asm/data/overlays/ch/bonfirecavern.data.s) is defined here in C.
 * Its tables hold pointers to functions of this file; IDO's assembler schedules some of these
 * functions differently unless the tables are defined in the same unit. Values are taken from the ROM.
 * extern declarations adjusted to the object (same addresses): D_80800200_chbonfirecavern -> int[] */
extern void func_80105834();
extern void _chfirefx_entrypoint_4();
extern void func_80108ED0();
extern void func_80107C2C();
int D_80800200_chbonfirecavern[18] = { 0x31103A9, 0x6FB0002, 0x0, (u32)func_80800190_chbonfirecavern, (u32)func_80105834, (u32)_chfirefx_entrypoint_4, 0x0, 0x0, 0x0, 0x400, 0x0, (u32)func_80108ED0, 0x0, (u32)func_8080000C_chbonfirecavern, (u32)func_80107C2C, -0x7FFFBC00, (u32)func_80800080_chbonfirecavern, 0x0 };
u8 D_80800248_chbonfirecavern[88] = { 0x10, 0x10, 0x0, 0x1D, 0x9, 0xDD, 0x0, 0x16, 0x2, 0x0, 0x0, 0x2C, 0x0, 0x0, 0x0, 0xFA, 0x0, 0x0, 0x0, 0x0, 0x1, 0x5E, 0x0, 0x0, 0x0, 0x1B, 0x0, 0x64, 0x0, 0x96, 0x0, 0xB, 0x0, 0x0, 0x1, 0x2C, 0x0, 0x32, 0xFF, 0xF6, 0x0, 0x20, 0xC0, 0xC0, 0xC0, 0xC0, 0x0, 0x22, 0x2, 0x0, 0x2, 0x99, 0x1, 0x33, 0x1, 0x66, 0x0, 0x15, 0x0, 0x19, 0x0, 0x99, 0x0, 0x2A, 0x0, 0xC, 0x0, 0x19, 0x0, 0xCC, 0x1, 0x0, 0x0, 0x27, 0xFF, 0x9C, 0xFF, 0x9C, 0x0, 0x64, 0x0, 0x64, 0x0, 0x28, 0x1, 0xCC, 0x0, 0x0 };
u8 D_808002A0_chbonfirecavern[32] = { 0x0, 0x13, 0x4, 0xDC, 0x0, 0xD, 0x0, 0xB3, 0x0, 0xCC, 0x0, 0x15, 0x0, 0x0, 0x0, 0x80, 0x0, 0x66, 0x0, 0x1, 0x3, 0x20, 0xF, 0xA0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0 };
