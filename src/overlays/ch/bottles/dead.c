// Probably Bottles' dead body in his house after Grunty kills him: a scaled model with one
// part hidden and no logic beyond a callback.
#include "common.h"

extern int D_808000C0_chbottlesdead[];
extern void func_80102FDC(u8 *, f32);

// Scales the model to 15% of its current scale.
void func_80800000_chbottlesdead(u8 *actor)
{
    func_80102FDC(actor, *(f32 *) (actor + 0x38) * 0.15f);
}

void func_80800034_chbottlesdead()
{
    func_8010C964();
}

// Draw: hides model part 3, then the default draw.
s32 func_80800054_chbottlesdead(s32 param_0, s32 param_1)
{
    func_800DF744(3, 0);
    func_80101870(param_0, param_1);
}

int chbottlesdead_entrypoint_0()
{
    return &D_808000C0_chbottlesdead;
}

extern void func_80105834();
extern void func_80107C2C();
u32 D_808000B0_chbottlesdead[4] = {0x0, 0x0, 0x40000000, 0x4600084};
int D_808000C0_chbottlesdead[20] = {0x15804BC,
                                    0x8C30001,
                                    (u32) &D_808000B0_chbottlesdead,
                                    (u32) func_80800034_chbottlesdead,
                                    (u32) func_80105834,
                                    (u32) func_80800054_chbottlesdead,
                                    0x12C0000,
                                    0x41155555,
                                    0x3B0000,
                                    0x0,
                                    0x0,
                                    0x0,
                                    0x0,
                                    (u32) func_80800000_chbottlesdead,
                                    (u32) func_80107C2C,
                                    -0x7FFFCBFA,
                                    0x0,
                                    0x0,
                                    0x0,
                                    0x0};
