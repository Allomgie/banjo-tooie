#include "common.h"

extern int D_808000C0_chmumboskulls[];
extern u16 D_80800108_chmumboskulls[];
extern void func_80103140();
void func_8080007C_chmumboskulls();

int chmumboskulls_entrypoint_0()
{
    return (int) &D_808000C0_chmumboskulls;
}

void func_8080000C_chmumboskulls(s32 actor)
{
    func_8010A800(actor, 1);
}

void func_8080002C_chmumboskulls(s32 actor)
{
}

int func_80800034_chmumboskulls(s32 actor, s32 msg, s32 payload)
{
    if (msg == 0x95) {
        func_8080007C_chmumboskulls(actor);
        func_8010A63C(actor);
    } else {
        return 0;
    }
    return 1;
}

// The marker variant (0x32 + n) selects the model from the table.
void func_8080007C_chmumboskulls(actor) Actor *actor;
{
    s32 variant;

    variant = actor->unk74_7 - 0x32;
    func_80103140(actor, D_80800108_chmumboskulls[variant], 0);
}

extern void func_80105834();
extern void func_80101870();
extern void func_80107C2C();
// TU-NOTE: the .data of this overlay is defined here in C. Its tables hold pointers to functions of
// this file; IDO's assembler schedules some of them differently unless the tables are in the same
// unit. D_808000C0_chmumboskulls is declared as int[] above.
int D_808000C0_chmumboskulls[18] = {0x1580463,
                                    -0xFFFF,
                                    0x0,
                                    (u32) func_8080002C_chmumboskulls,
                                    (u32) func_80105834,
                                    (u32) func_80101870,
                                    0x0,
                                    0x0,
                                    0x0,
                                    0x400,
                                    0x0,
                                    0x0,
                                    0x0,
                                    (u32) func_8080000C_chmumboskulls,
                                    (u32) func_80107C2C,
                                    -0x7FFFD3FE,
                                    (u32) func_80800034_chmumboskulls,
                                    0x0};
u16 D_80800108_chmumboskulls[4] = {0x648, 0x8E0, 0x8E1, 0x867};
