#include "common.h"

extern int D_80800220_chtnthut[];
extern void func_800EE7F8(f32 *, f32 *);
extern void func_800EF1B8(f32 *, f32, f32);
extern s32 D_808002D8_chtnthut[];
extern s32 D_80800268_chtnthut[];
extern void _chexploder_entrypoint_10();
extern f32 func_800D8FF8(void);
extern void func_800C4104(s32, f32, s32, f32 *, f32, f32);
void func_80800170_chtnthut();

int *chtnthut_entrypoint_0()
{
    return &D_80800220_chtnthut;
}

void func_8080000C_chtnthut(s32 arg0) 
{
}
void func_80800014_chtnthut(Actor *param_0)
{
    if (param_0->unk70_10 == 2) {
        param_0->unk58 += func_800D8FF8();
        if (param_0->unk58 > 0.5f) {
            func_800C4104(0x43F, 0.9f, 0x6D60, param_0->position, 1250.0f, 2500.0f);
            func_800FFAB0(param_0);
        }
    }
}

s32 func_808000B0_chtnthut(Actor *param_0, s32 param_1, s32 param_2)
{
    f32 local_0[3];
    switch (param_1) {
    case 5:
        func_800EE7F8(local_0, param_0->position);
        func_800EF1B8(local_0, param_0->rotation[1], -100.0f);
        local_0[1] += 75.0f;
        _chexploder_entrypoint_3(param_0, local_0, 0);
        break;
    case 0x90:
        func_80800170_chtnthut(param_0);
        break;
    case 0x95:
        _chtntdetonator_entrypoint_1(param_0, 0x84);
        break;
    default:
        return 0;
    }
    return 1;
}

void func_80800170_chtnthut(param_0) Actor *param_0;
{
  s32 local_0;
  local_0 = func_80106790(func_80101080());
  _chexploder_entrypoint_12(local_0, 0x3C);
  _chexploder_entrypoint_13(local_0, 4);
  _chexploder_entrypoint_10(local_0, &D_808002D8_chtnthut);
  func_800BABB8(0, (u8 *)param_0 + 4, local_0 + 0x18, *((s32 **)((u8 *)param_0 + 0x38)), &D_80800268_chtnthut);
  func_80101FDC(param_0, 2);
  func_80103110(param_0, 1);
  func_800DA544(0x84);
}

/* TU-NOTE: the .data of this overlay (formerly asm/data/overlays/ch/tnt/hut.data.s) is defined here in C.
 * Its tables hold pointers to functions of this file; IDO's assembler schedules some of these
 * functions differently unless the tables are defined in the same unit. Values are taken from the ROM.
 * extern declarations adjusted to the object (same addresses): D_80800220_chtnthut -> int[], D_80800268_chtnthut -> s32[], D_808002D8_chtnthut -> s32[] */
extern void func_80105834();
extern void func_80101870();
extern void func_80107C2C();
int D_80800220_chtnthut[18] = { 0x158014A, 0x6A80001, 0x0, (u32)func_80800014_chtnthut, (u32)func_80105834, (u32)func_80101870, 0xBB8, 0x0, 0x0, 0x800, 0x0, 0x0, 0x0, (u32)func_8080000C_chtnthut, (u32)func_80107C2C, -0x7FFFD3FE, (u32)func_808000B0_chtnthut, 0x0 };
s32 D_80800268_chtnthut[28] = { 0x410001D, 0x9DD002B, 0x8000A00, 0x220200, 0x2800600, 0x8000015, 0x26, 0x190000, 0x7002C, -0x13FFEC, -0x13FFEC, 0x280014, 0x20DEA7, 0x71C0000A, -0xF9FFCE, -0xF9FF06, 0xC800FA, 0x41A0F10, 0x1D06A3, 0x14002D, 0x1F402EE, 0x2200B3, 0xCC0066, 0x99001E, 0x500050, 0xD0064, 0x5FEA7, 0xF1A0000 };
s32 D_808002D8_chtnthut[6] = { 0x2A002B, 0x2C002D, 0x2E002F, 0x300031, 0x320033, 0x34FFFF };
