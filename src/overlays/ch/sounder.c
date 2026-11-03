#include "common.h"

extern u8 D_808000A0_chsounder[];
extern u8 D_808000AC_chsounder[];
extern int D_808000BC_chsounder[];

void func_80800000_chsounder(Actor *param_0)
{
    switch (param_0->unk74_7) {
        case 0x32:
            _subaddieaudioloop_entrypoint_5(param_0, param_0->position, 1, -1,
                                            D_808000A0_chsounder);
            break;
        case 0x33:
            _subaddieaudioloop_entrypoint_5(param_0, param_0->position, 1, -1,
                                            D_808000AC_chsounder);
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
    return (int) &D_808000BC_chsounder;
}

extern void func_80105834();
extern void func_8010A730();
extern void func_80107C2C();
u8 D_808000A0_chsounder[12] = {0x0, 0x13, 0x6, 0x2C, 0x0, 0x16, 0x46, 0x50, 0x0, 0x0, 0x0, 0x0};
u8 D_808000AC_chsounder[16] = {0x0, 0x13, 0x6, 0x2C, 0x0, 0x16, 0x23, 0x28,
                               0x0, 0x1,  0x0, 0x96, 0x5, 0xDC, 0x0,  0x0};
int D_808000BC_chsounder[21] = {0x1580175,
                                0x1,
                                0x0,
                                (u32) func_80800000_chsounder,
                                (u32) func_80105834,
                                (u32) func_8010A730,
                                0xBB80000,
                                0x0,
                                0x0,
                                0x80004,
                                (u32) func_80800078_chsounder,
                                0x0,
                                0x0,
                                (u32) func_80800080_chsounder,
                                (u32) func_80107C2C,
                                -0x7FFFFDFE,
                                0x0,
                                0x0,
                                0x0,
                                0x0,
                                0x0};
