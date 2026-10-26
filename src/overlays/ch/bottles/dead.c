#include "common.h"

extern int D_808000C0_chbottlesdead;
extern void func_80102FDC(u8 *, f32);

void func_80800000_chbottlesdead(u8 *param_0) {
    func_80102FDC(param_0, *(f32 *)(param_0 + 0x38) * 0.15f);
}

void func_80800034_chbottlesdead()
{
    func_8010C964();
}

s32 func_80800054_chbottlesdead(s32 param_0, s32 param_1){
    func_800DF744(3, 0);
    func_80101870(param_0, param_1);
}

int chbottlesdead_entrypoint_0()
{
    return &D_808000C0_chbottlesdead;
}
