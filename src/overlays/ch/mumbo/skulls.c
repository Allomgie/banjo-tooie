#include "common.h"

extern int D_808000C0_chmumboskulls[];
extern u16 D_80800108_chmumboskulls[];
extern void func_80103140();
void func_8080007C_chmumboskulls();

int chmumboskulls_entrypoint_0()
{
    return (int)&D_808000C0_chmumboskulls;
}

void func_8080000C_chmumboskulls(s32 arg0)
{
    func_8010A800(arg0,1);
}

void func_8080002C_chmumboskulls(s32 arg0) 
{
}
int func_80800034_chmumboskulls(s32 param_0, s32 param_1, s32 param_2)
{
  if (param_1 == 0x95)
  {
    func_8080007C_chmumboskulls(param_0);
    func_8010A63C(param_0);
    } else {
        return 0;
    }
    return 1;
}

void func_8080007C_chmumboskulls(param_0) Actor *param_0;
{
    s32 local_0;

    local_0 = param_0->unk74_7 - 0x32;
    func_80103140(param_0, D_80800108_chmumboskulls[local_0], 0);
}

/* TU-NOTE: the .data of this overlay (formerly asm/data/overlays/ch/mumbo/skulls.data.s) is defined here in C.
 * Its tables hold pointers to functions of this file; IDO's assembler schedules some of these
 * functions differently unless the tables are defined in the same unit. Values are taken from the ROM.
 * extern declarations adjusted to the object (same addresses): D_808000C0_chmumboskulls -> int[] */
extern void func_80105834();
extern void func_80101870();
extern void func_80107C2C();
int D_808000C0_chmumboskulls[18] = { 0x1580463, -0xFFFF, 0x0, (u32)func_8080002C_chmumboskulls, (u32)func_80105834, (u32)func_80101870, 0x0, 0x0, 0x0, 0x400, 0x0, 0x0, 0x0, (u32)func_8080000C_chmumboskulls, (u32)func_80107C2C, -0x7FFFD3FE, (u32)func_80800034_chmumboskulls, 0x0 };
u16 D_80800108_chmumboskulls[4] = { 0x648, 0x8E0, 0x8E1, 0x867 };
