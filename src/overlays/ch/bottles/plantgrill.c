// Probably a grille in Bottles' house built with the shared door maker; it opens in a
// cutscene and is removed once the Tower of Tragedy is finished or a flag is set.
#include "common.h"

extern int D_808000F0_chbottlesplantgrill[];
extern s32 _chdoormake_entrypoint_3(Actor *, f32, f32, f32, s32, s32);
extern void _chdoormake_entrypoint_6(Actor *, f32);
extern void _chdoormake_entrypoint_5(Actor *, f32);

int chbottlesplantgrill_entrypoint_0()
{
    return (int) &D_808000F0_chbottlesplantgrill;
}

// Door-maker grille that opens in cutscene 0x65.
void func_8080000C_chbottlesplantgrill(Actor *actor)
{
    if (_chdoormake_entrypoint_3(actor, 0.0f, 90.0f, actor->scale * 250.0f, 0, -1)) {
        _chdoormake_entrypoint_6(actor, 1.0f);
        _chdoormake_entrypoint_5(actor, 3.0f);
        _chdoormake_entrypoint_8(actor, 5);
        _chdoormake_entrypoint_12(actor, 0, 0x65);
        _chdoormake_entrypoint_9(actor, 0, 3, 0x2900);
    }
    func_8010A800(actor, 0);
    // Removed once the Tower of Tragedy is finished or flag 0x1A5 is set.
    if (!_glcutDll_entrypoint_19(0x65) && (func_800DA298(0x1A5) || func_800DA298(0x3B))) {
        func_800FFAB0(actor);
    }
}

extern void _chdoor_entrypoint_0();
extern void func_80105834();
extern void func_80101870();
extern void func_80107C2C();
extern void _chdoor_entrypoint_1();
int D_808000F0_chbottlesplantgrill[20] = {0xAC04EA,
                                          0x7810001,
                                          0x0,
                                          (u32) _chdoor_entrypoint_0,
                                          (u32) func_80105834,
                                          (u32) func_80101870,
                                          0x0,
                                          0x0,
                                          0x0,
                                          0x800,
                                          0x0,
                                          0x0,
                                          0x0,
                                          (u32) func_8080000C_chbottlesplantgrill,
                                          (u32) func_80107C2C,
                                          -0x7FF7DBFE,
                                          (u32) _chdoor_entrypoint_1,
                                          0x0,
                                          0x0,
                                          0x0};
