#include "common.h"

extern int D_80800130_chklungoleave[];
extern s32 D_80800178_chklungoleave[];

int chklungoleave_entrypoint_0()
{
    return (int)&D_80800130_chklungoleave;
}

int func_8080000C_chklungoleave(s32 param_0)
{
  func_80105A9C(param_0, 0x43960000);
  func_80105BAC(param_0);
}

void func_808000F0_chklungoleave();

void func_80800038_chklungoleave(s32 arg0)
{
    func_80105834();
    func_808000F0_chklungoleave(arg0);
}
s32 func_80800060_chklungoleave(Actor *param_0, s32 param_1, s32 param_2)
{
    switch (param_1) {
    case 0x95:
        if (_glcutDll_entrypoint_19(0x5B)) {
            _subaddiedialog_entrypoint_11(param_0->unk0, 0x162E, 0x44, param_0->position, 0xAB);
            _capod_entrypoint_13(param_0->unk0, 0, 6, 0x2911);
            break;
        }
        func_800FFAB0(param_0);
        break;
    default:
        return 0;
    }
    return 1;
}

void func_808000F0_chklungoleave(s32 param_0) {
    func_80105230(param_0, &D_80800178_chklungoleave);
}

/* TU-NOTE: the .data of this overlay (formerly asm/data/overlays/ch/klungo/leave.data.s) is defined here in C.
 * Its tables hold pointers to functions of this file; IDO's assembler schedules some of these
 * functions differently unless the tables are defined in the same unit. Values are taken from the ROM.
 * extern declarations adjusted to the object (same addresses): D_80800130_chklungoleave -> int[], D_80800178_chklungoleave -> s32[] */
extern void func_80102EC0();
extern void func_80101870();
extern void func_80107C2C();
u32 D_80800120_chklungoleave[4] = { 0x0, 0x0, 0x3F333333, 0x2640001 };
int D_80800130_chklungoleave[18] = { 0x1580323, 0x90D0001, (u32)&D_80800120_chklungoleave, (u32)func_80102EC0, (u32)func_80800038_chklungoleave, (u32)func_80101870, 0x0, 0x40000000, 0x0, 0x40100, 0x0, 0x0, 0x0, (u32)func_8080000C_chklungoleave, (u32)func_80107C2C, -0x7FFFFBFE, (u32)func_80800060_chklungoleave, 0x0 };
s32 D_80800178_chklungoleave[6] = { 0x0, 0x3F000000, -0x40800000, 0x0, 0x0, 0x0 };
