#include "common.h"

extern s32 _chdoormake_entrypoint_3(Actor *, f32, f32, f32, s32, s32);
extern void _chdoormake_entrypoint_6(Actor *, f32);

void func_80800000_chlavatraindoor(Actor *param_0)
{
    f32 local_0;

    if (_chdoormake_entrypoint_3(param_0, 0.0f, 90.0f, param_0->scale * 1007.5f, 0x20, 0x1D0)) {
        _chdoormake_entrypoint_12(param_0, 0, 0x4D);
        _chdoormake_entrypoint_8(param_0, 5);
        if (param_0->unk74_7 == 0x32) local_0 = 0.8f;
        else local_0 = 3.5f;
        _chdoormake_entrypoint_6(param_0, local_0);
        if (param_0->unk74_7 == 0x32) _chdoormake_entrypoint_9(param_0, 0, 8, 0x910);
    }
}

int chlavatraindoor_entrypoint_0()
{
    extern int D_808000F0_chlavatraindoor[];
    return &D_808000F0_chlavatraindoor;
}

/* TU-NOTE: the .data of this overlay (formerly asm/data/overlays/ch/lava/traindoor.data.s) is defined here in C.
 * Its tables hold pointers to functions of this file; IDO's assembler schedules some of these
 * functions differently unless the tables are defined in the same unit. Values are taken from the ROM.
 * extern declarations adjusted to the object (same addresses): D_808000F0_chlavatraindoor -> int[] */
extern void _chdoor_entrypoint_0();
extern void func_80105834();
extern void func_80101870();
extern void func_80107C2C();
extern void _chdoor_entrypoint_1();
int D_808000F0_chlavatraindoor[20] = { 0xAC0281, 0x8F60001, 0x0, (u32)_chdoor_entrypoint_0, (u32)func_80105834, (u32)func_80101870, 0x0, 0x0, 0x0, 0xC00, 0x0, 0x0, 0x0, (u32)func_80800000_chlavatraindoor, (u32)func_80107C2C, -0x7FF7DBEE, (u32)_chdoor_entrypoint_1, 0x0, 0x0, 0x0 };
