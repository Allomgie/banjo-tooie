#include "common.h"

extern u8 D_808000F0_chcrackarchwall[];
extern u8 D_80800130_chcrackarchwall[];
extern void func_800BABB8(s32, f32 *, f32 *, f32, void *);
typedef union { s32 local_0; s16 local_1[2]; } CrackWallEventValue;
extern int D_80800144_chcrackarchwall[];

s32 func_80800000_chcrackarchwall(Actor *param_0, s32 param_1, CrackWallEventValue param_2)
{
    switch (param_1) {
        case 0x95:
            if (func_800DA298((u32)*(u16 *)((u8 *)param_0 + 0x76) >> 7)) func_800FFAB0(param_0);
            break;
        case 0x40:
            func_800DA544((u32)*(u16 *)((u8 *)param_0 + 0x76) >> 7);
            _chexploder_entrypoint_3(param_0, param_0->position, 12);
            break;
        case 0x90:
            func_800BABB8(0, param_0->position, param_0->position, param_0->scale, D_808000F0_chcrackarchwall);
            func_800C4AF0(param_0->position, D_80800130_chcrackarchwall);
            break;
        default: return 0;
    }
    return 1;
}

int chcrackarchwall_entrypoint_0()
{
  return (int)&D_80800144_chcrackarchwall;
}

/* TU-NOTE: the .data of this overlay (formerly asm/data/overlays/ch/crackarwall.data.s) is defined here in C.
 * Its tables hold pointers to functions of this file; IDO's assembler schedules some of these
 * functions differently unless the tables are defined in the same unit. Values are taken from the ROM.
 * extern declarations adjusted to the object (same addresses): D_80800144_chcrackarchwall -> int[] */
extern void func_80102EC0();
extern void func_80105834();
extern void func_80101870();
extern void func_80108ED0();
extern void func_80107C2C();
u8 D_808000F0_chcrackarchwall[64] = { 0x9, 0x10, 0x0, 0x1D, 0x9, 0xDD, 0x0, 0x2B, 0x2, 0x0, 0x3, 0x0, 0x0, 0x22, 0x1, 0x80, 0x2, 0x0, 0x4, 0x80, 0x6, 0x0, 0x0, 0x15, 0x0, 0x0, 0x0, 0x26, 0x0, 0x19, 0x0, 0x0, 0x0, 0x7, 0x0, 0x2D, 0x0, 0x32, 0x0, 0x64, 0x0, 0x20, 0xDE, 0xA7, 0x71, 0xC0, 0x0, 0xA, 0xFF, 0x9C, 0x0, 0x19, 0xFF, 0x9C, 0x0, 0x64, 0x0, 0x4B, 0x0, 0x64, 0x9, 0x1A, 0x0, 0x0 };
u8 D_80800130_chcrackarchwall[20] = { 0x0, 0x13, 0x4, 0x13, 0x0, 0xA, 0x0, 0xE6, 0x0, 0x16, 0x6D, 0x60, 0x0, 0x1, 0x4, 0xE2, 0x9, 0xC4, 0x0, 0x0 };
int D_80800144_chcrackarchwall[19] = { 0xAC012B, 0x8F90001, 0x0, (u32)func_80102EC0, (u32)func_80105834, (u32)func_80101870, 0x0, 0x0, 0x0, 0x800, 0x0, (u32)func_80108ED0, 0x0, 0x0, (u32)func_80107C2C, -0x7FFFD400, (u32)func_80800000_chcrackarchwall, 0x0, 0x0 };
