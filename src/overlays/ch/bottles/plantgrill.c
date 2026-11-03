#include "common.h"

extern int D_808000F0_chbottlesplantgrill[];
extern s32 _chdoormake_entrypoint_3(Actor *, f32, f32, f32, s32, s32);
extern void _chdoormake_entrypoint_6(Actor *, f32);
extern void _chdoormake_entrypoint_5(Actor *, f32);

int chbottlesplantgrill_entrypoint_0()
{
    return (int)&D_808000F0_chbottlesplantgrill;
}

void func_8080000C_chbottlesplantgrill(Actor *param_0)
{
    if (_chdoormake_entrypoint_3(param_0, 0.0f, 90.0f, param_0->scale * 250.0f, 0, -1)) {
        _chdoormake_entrypoint_6(param_0, 1.0f);
        _chdoormake_entrypoint_5(param_0, 3.0f);
        _chdoormake_entrypoint_8(param_0, 5);
        _chdoormake_entrypoint_12(param_0, 0, 0x65);
        _chdoormake_entrypoint_9(param_0, 0, 3, 0x2900);
    }
    func_8010A800(param_0, 0);
    if (!_glcutDll_entrypoint_19(0x65) && (func_800DA298(0x1A5) || func_800DA298(0x3B))) {
        func_800FFAB0(param_0);
    }
}

/* TU-NOTE: the .data of this overlay (formerly asm/data/overlays/ch/bottles/plantgrill.data.s) is defined here in C.
 * Its tables hold pointers to functions of this file; IDO's assembler schedules some of these
 * functions differently unless the tables are defined in the same unit. Values are taken from the ROM.
 * extern declarations adjusted to the object (same addresses): D_808000F0_chbottlesplantgrill -> int[] */
extern void _chdoor_entrypoint_0();
extern void func_80105834();
extern void func_80101870();
extern void func_80107C2C();
extern void _chdoor_entrypoint_1();
int D_808000F0_chbottlesplantgrill[20] = { 0xAC04EA, 0x7810001, 0x0, (u32)_chdoor_entrypoint_0, (u32)func_80105834, (u32)func_80101870, 0x0, 0x0, 0x0, 0x800, 0x0, 0x0, 0x0, (u32)func_8080000C_chbottlesplantgrill, (u32)func_80107C2C, -0x7FF7DBFE, (u32)_chdoor_entrypoint_1, 0x0, 0x0, 0x0 };
