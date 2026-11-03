#include "common.h"

extern int D_808003E0_chchompaslunch[];
typedef union { s32 word; void *pointer; } ChompaLunchEventPayload;
typedef struct { s16 local_0[6]; } ChompaLunchChannel;
extern ChompaLunchChannel D_80800428_chchompaslunch[];
extern s32 D_808004A4_chchompaslunch[];
extern void _subaddieaudioquick_entrypoint_3(u8 *, u8 *, void *, f32);
extern s32 D_8080044C_chchompaslunch[];
extern s32 D_80800458_chchompaslunch[];
extern s32 D_80800498_chchompaslunch[];
extern s32 D_80800468_chchompaslunch[];
extern f32 D_80800478_chchompaslunch[];
extern s16 D_80800488_chchompaslunch[];
extern s16 D_80800490_chchompaslunch[];
extern f32 func_800DC178(f32, f32);
extern void func_800C31DC(u8, f32);
void func_8080017C_chchompaslunch();
void func_8080037C_chchompaslunch();
void func_80800250_chchompaslunch();

int chchompaslunch_entrypoint_0()
{
    return (int)&D_808003E0_chchompaslunch;
}

void func_8080000C_chchompaslunch(Actor *param_0)
{
    if (!_glcutDll_entrypoint_20()) {
        func_800FFAB0(param_0);
    }
    param_0->unk58 = 8.0f;
    param_0->unk6C_0 = func_800DC128(0, 3);
}

void func_80800070_chchompaslunch(u8 *param_0)
{
  u32 temp_t6;
  temp_t6 = (u16) (*((u16 *) (((s8 *) param_0) + 0x72)));
  temp_t6 = temp_t6 >> 0xA;
  switch (temp_t6)
  {
    case 1:
      func_80800250_chchompaslunch(param_0);
      if (func_800D9078(param_0 + 0x58) != 0)
    {
      func_80102424(param_0, 2);
      return;
    }
      return;

    case 2:
      func_8080037C_chchompaslunch(param_0);
      if (func_80101DDC(param_0) != 0)
    {
      func_80102424(param_0, 3);
      return;
    }
      break;

    case 3:
      func_80105230(param_0, 0);
      break;

  }

}

s32 func_80800118_chchompaslunch(Actor *param_0, s32 param_1, ChompaLunchEventPayload param_2)
{
    switch (param_1) {
    case 0x1F:
        func_8080017C_chchompaslunch(param_0);
        break;
    case 0xBC:
        func_800FFAB0(param_0);
        break;
    default:
        return 0;
    }
    return 1;
}

void func_8080017C_chchompaslunch(param_0) Actor *param_0;
{
    func_801015D0(param_0);
    func_800DF744(4, D_80800428_chchompaslunch[param_0->unk6C_0].local_0[0]);
    func_800DF744(5, D_80800428_chchompaslunch[param_0->unk6C_0].local_0[1]);
    func_800DF744(6, D_80800428_chchompaslunch[param_0->unk6C_0].local_0[2]);
    func_800DF744(7, 0);
    func_800DF744(8, D_80800428_chchompaslunch[param_0->unk6C_0].local_0[3]);
}

void func_80800250_chchompaslunch(param_0) Actor *param_0;
{
    s32 local_0;

    if (!param_0->unk5F) {
        param_0->unk5F = func_800C4350(0, param_0->position, &D_80800498_chchompaslunch);
    }
    for (local_0 = 0; local_0 < 4; local_0++) {
        if (func_80101E14(param_0, D_80800468_chchompaslunch[local_0])) {
            func_800C301C(param_0->unk5F, D_80800488_chchompaslunch[local_0]);
            func_800C31DC(param_0->unk5F, D_80800478_chchompaslunch[local_0] + func_800DC178(-0.02f, 0.02f));
            func_800C3058(param_0->unk5F, D_80800490_chchompaslunch[local_0]);
            func_800C3BDC(param_0->unk5F);
            break;
        }
    }
    if (!param_0->unk6C_0) {
        _subaddieaudioquick_entrypoint_4(param_0, param_0->position, &D_8080044C_chchompaslunch, &D_80800458_chchompaslunch);
    }
}

void func_8080037C_chchompaslunch(param_0) u8 *param_0; {
    _subaddieaudioquick_entrypoint_3(param_0, param_0 + 4, &D_808004A4_chchompaslunch, 0.0f);
}

/* TU-NOTE: the .data of this overlay (formerly asm/data/overlays/ch/ompaslun.data.s) is defined here in C.
 * Its tables hold pointers to functions of this file; IDO's assembler schedules some of these
 * functions differently unless the tables are defined in the same unit. Values are taken from the ROM.
 * Labels inside an object are linker symbols in undefined_syms.us.txt: D_8080042A_chchompaslunch = D_80800428_chchompaslunch + 0x2, D_8080042E_chchompaslunch = D_80800428_chchompaslunch + 0x6, D_8080042C_chchompaslunch = D_80800428_chchompaslunch + 0x4
 * extern declarations adjusted to the object (same addresses): D_808003E0_chchompaslunch -> int[], D_8080044C_chchompaslunch -> s32[], D_80800458_chchompaslunch -> s32[], D_80800498_chchompaslunch -> s32[], D_808004A4_chchompaslunch -> s32[] */
extern void func_80102EC0();
extern void func_801018A4();
extern void func_80107C2C();
u32 D_808003C0_chchompaslunch[8] = { 0x0, 0x0, 0x40800000, 0x2EE0001, 0x3FB33333, 0x2EF0002, 0x3F28F5C3, 0x2F00001 };
int D_808003E0_chchompaslunch[18] = { 0x1580501, 0x7EE0001, (u32)&D_808003C0_chchompaslunch, (u32)func_80800070_chchompaslunch, (u32)func_80102EC0, (u32)func_801018A4, 0x0, 0x0, 0x0, 0x128, 0x0, 0x0, 0x0, (u32)func_8080000C_chchompaslunch, (u32)func_80107C2C, -0x7FFFFBFE, (u32)func_80800118_chchompaslunch, 0x0 };
ChompaLunchChannel D_80800428_chchompaslunch[3] = { 0x1, 0x1, 0x1, 0x3, 0x0, 0x0, 0x2, 0x2, 0x2, 0x1, 0x0, 0x0, 0x3, 0x2, 0x2, 0x2, 0x0, 0x0 };
s32 D_8080044C_chchompaslunch[3] = { 0x130417, 0xD00C0, 0xD90000 };
s32 D_80800458_chchompaslunch[4] = { 0x3F23D70A, 0x3F3AE148, 0x3F51EB85, -0x40800000 };
s32 D_80800468_chchompaslunch[4] = { 0x0, 0x3E6B851F, 0x3EA3D70A, 0x3ED70A3D };
f32 D_80800478_chchompaslunch[4] = { 0.9f, 1.1f, 1.05f, 1.0f };
s16 D_80800488_chchompaslunch[4] = { 0x5BE, 0x5BC, 0x5BD, 0x5BD };
s16 D_80800490_chchompaslunch[4] = { 0x7D00, 0x55F0, 0x55F0, 0x55F0 };
s32 D_80800498_chchompaslunch[3] = { 0x3060001, 0xC80BB8, 0x70000 };
s32 D_808004A4_chchompaslunch[7] = { 0x1305B6, 0xD00F3, 0x10C0018, 0x0, 0x0, 0x0, 0x0 };
