#include "common.h"

extern u8 D_808000A0_chsounder[];
extern u8 D_808000AC_chsounder[];
extern int D_808000BC_chsounder;

void func_80800000_chsounder(Actor *param_0)
{
    switch (param_0->unk74_7) {
    case 0x32:
        _subaddieaudioloop_entrypoint_5(param_0, param_0->position, 1, -1, D_808000A0_chsounder);
        break;
    case 0x33:
        _subaddieaudioloop_entrypoint_5(param_0, param_0->position, 1, -1, D_808000AC_chsounder);
        break;
    }
}

void func_80800078_chsounder(s32 arg0) 
{
}
void func_80800080_chsounder(s32 arg0) 
{
}
int chsounder_entrypoint_0()
{
    return (int)&D_808000BC_chsounder;
}
