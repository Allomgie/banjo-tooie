#include "common.h"

extern int D_808000C0_chbottlesdead[];
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

/* TU-NOTE: the .data of this overlay (formerly asm/data/overlays/ch/bottles/dead.data.s) is defined here in C.
 * Its tables hold pointers to functions of this file; IDO's assembler schedules some of these
 * functions differently unless the tables are defined in the same unit. Values are taken from the ROM.
 * extern declarations adjusted to the object (same addresses): D_808000C0_chbottlesdead -> int[] */
extern void func_80105834();
extern void func_80107C2C();
u32 D_808000B0_chbottlesdead[4] = { 0x0, 0x0, 0x40000000, 0x4600084 };
int D_808000C0_chbottlesdead[20] = { 0x15804BC, 0x8C30001, (u32)&D_808000B0_chbottlesdead, (u32)func_80800034_chbottlesdead, (u32)func_80105834, (u32)func_80800054_chbottlesdead, 0x12C0000, 0x41155555, 0x3B0000, 0x0, 0x0, 0x0, 0x0, (u32)func_80800000_chbottlesdead, (u32)func_80107C2C, -0x7FFFCBFA, 0x0, 0x0, 0x0, 0x0 };
