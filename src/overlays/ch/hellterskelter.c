#include "ch/hellterskelter.h"

extern int D_808007C8_chhellterskelter[];
extern int D_80800810_chhellterskelter[];
extern int D_80800858_chhellterskelter[];
extern f32 func_800DC178(f32, f32);
extern void func_800EE7F8(f32 *, f32 *);
extern void func_800EF1B8(f32 *, f32, f32);
extern u8 D_808008F4_chhellterskelter[];
extern u8 D_80800924_chhellterskelter[];
extern void _subaddieaudioquick_entrypoint_2(Actor *, f32 *, void *);
extern s32 func_800BABB8(s32, f32 *, f32 *, f32, s32 *);
extern u8 D_80800938_chhellterskelter[];
extern u8 D_80800974_chhellterskelter[];
extern Actor *func_8010856C(s32, f32 *, f32 *);
extern Actor *func_80108528(s32, f32 *, s32, Actor **);
extern Actor *func_80106790(Unk80132ED0 *);
extern void func_80102FDC(Actor *, f32);
extern void func_80105A9C(Actor *, f32);
extern void _chappearfx_entrypoint_1(Actor *, s32, s32, f32);
extern s32 _capod_entrypoint_17(f32);
typedef struct Mass45HelterFlags { u32 local_0 : 11; u32 local_1 : 1; u32 local_2 : 20; } Mass45HelterFlags;
extern f32 *func_80105494(Actor *);
extern s32 func_800F4F34(s32, f32 *, f32, f32);
extern s32 func_80105998(Actor *, f32);
extern s32 D_808008A0_chhellterskelter[];
extern s32 D_808008AC_chhellterskelter[];
extern s32 func_800DC298(f32);
extern void func_800BBCB8(f32 *, s32, f32, s32, void *);
extern u8 D_808008C0_chhellterskelter[];
void func_808004D0_chhellterskelter();

int *chhellterskelter_entrypoint_0()
{
    return &D_808007C8_chhellterskelter;
}

int chhellterskelter_entrypoint_1()
{
    return (int)&D_80800810_chhellterskelter;
}

int *chhellterskelter_entrypoint_2()
{
    return &D_80800858_chhellterskelter;
}

int func_80800024_chhellterskelter(s32 param_0)
{
  s32 local_0;
  s32 local_1;
  local_0 = _gccubesearch_entrypoint_0(0x154, param_0);
  local_1 = _gccubesearch_entrypoint_0(0x320, param_0);
  func_800EE88C(param_0 + ((char) 0x18), local_0);
  func_800EE88C(param_0 + 0x28, local_1);
  if (func_800DA298(0xA4B))
  {
    *(((char *) param_0) + 0x65) &= ~0x10;
    func_80108B04(param_0, 0x210);
  }
}

void func_808000A8_chhellterskelter(Actor *param_0)
{
    if (param_0->unk64_19 && !func_800DA298(0xA4B)) {
        if (!func_800DA9E4(0x6A2, 1)) {
            _capod_entrypoint_13(param_0->unk0, 0, 5, 0x10);
        }
        _chshockjump_entrypoint_2(param_0->unk3C);
        param_0->unk3C = NULL;
        param_0->unk64_19 = 0;
    }
    if (func_800D90A4(&param_0->unk58)) {
        func_80108B04(param_0, 0x33A);
        param_0->unk58 = func_800DC178(6.0f, 8.0f);
    }
}

void func_80800680_chhellterskelter();

s32 func_80800158_chhellterskelter(Actor *param_0, s32 param_1, s32 param_2)
{
    switch (param_1) {
    case 0x3D:
        func_80800680_chhellterskelter(param_0, param_2);
        break;
    case 0xE:
        if (param_2 == 1 && _capod_entrypoint_17(0.9f)) {
            param_0->unk64_20 = 1;
            func_80108B04(param_0, 0x210);
        }
        return 3;
    case 0xA:
        if (!func_800DA9E4(0x6A1, 1)) _capod_entrypoint_13(param_0->unk0, 0, 1, 0x10);
        else {
            param_0->unk64_20 = 0;
            func_80108B04(param_0, 0x210);
        }
        break;
    case 0x95:
        if (!param_0->unk3C) _subaddiefind_entrypoint_10(param_0, 0x210, 0);
        break;
    default:
        return 0;
    }
    return 1;
}

void func_80800274_chhellterskelter(s32 arg0)
{
    _chswitch_entrypoint_7(arg0,FLAG3_A4B_UNK);
}

int func_80800294_chhellterskelter(s32 param_0, s32 param_1, s32 param_2)
{
  if (param_1 == 7)
  {
    func_80101180(0x339, 0xA, 0);
  }
  _chswitch_entrypoint_10(param_0, param_1 | param_1, param_2);
}

void func_808002E8_chhellterskelter(s32 arg0) 
{
}
void func_808005E0_chhellterskelter();

void func_80800540_chhellterskelter();

void func_808002F0_chhellterskelter(Actor *param_0)
{
    f32 local_0;
    s32 local_1;
    s32 local_2;
    f32 *local_3;

    local_0 = param_0->position[1];
    local_1 = func_800F54E4();
    if (func_800F64A4(local_1, 0x8000) || !func_800F6478(local_1)) {
        func_800F4F34(local_1, param_0->position, 50.0f, 80.0f);
    }
    func_80105834(param_0);
    func_808004D0_chhellterskelter(param_0);
    if (!((Mass45HelterFlags *)((u8 *)param_0 + 0x64))->local_1) {
        if (func_8010CAC0(param_0->position, 400)) {
            _subaddieaudioquick_entrypoint_2(param_0, param_0->position, &D_808008A0_chhellterskelter);
            param_0->unk64_20 = 1;
        }
    }
    switch (param_0->unk70_10) {
        case 1:
            local_2 = func_8010CAC0(param_0->position, 1500);
            local_3 = func_80105494(param_0);
            if (local_2 || (!local_2 && param_0->unk5F)) {
                _subaddieaudioloop_entrypoint_5(param_0, param_0->position, local_2, 1200,
                    &D_808008AC_chhellterskelter);
            }
            if (local_3[3] > 0.94f) {
                func_80101FDC(param_0, 2);
            }
            break;
        case 2:
            if (local_0 > -110.0f && param_0->position[1] <= -110.0f) {
                func_80800540_chhellterskelter(param_0);
            }
            if (func_80105998(param_0, 0.985f)) {
                func_808005E0_chhellterskelter(param_0);
            }
            if (func_80105A5C(param_0)) {
                func_800FFAB0(param_0);
            }
            break;
    }
}

void func_808004D0_chhellterskelter(param_0) Actor *param_0;
{
    f32 *local_0;
    local_0 = func_80105494(param_0);
    if (!(local_0[3] > 0.9f) && func_800DC298(0.1f)) {
        func_800BBCB8(param_0->position, 0, 1.0f, 1, D_808008C0_chhellterskelter);
    }
}

void func_80800540_chhellterskelter(Actor *param_0)
{
    f32 local_0[3];

    func_800EE7F8(local_0, param_0->position);
    local_0[1] -= 100.0f;
    func_800EF1B8(local_0, param_0->rotation[1] + 180.0f, 50.0f);
    func_800BBCB8(param_0->position, (s32)local_0, 1.0f, 10, D_808008F4_chhellterskelter);
    _subaddieaudioquick_entrypoint_2(param_0, param_0->position, D_80800924_chhellterskelter);
}

void func_808005E0_chhellterskelter(Actor *param_0)
{
    f32 local_0[3];

    func_800EE7F8(local_0, param_0->position);
    local_0[1] -= 100.0f;
    func_800EF1B8(local_0, param_0->rotation[1] + 180.0f, 50.0f);
    func_800BABB8(0, param_0->position, local_0, 1.0f, (s32 *)D_80800938_chhellterskelter);
    _subaddieaudioquick_entrypoint_2(param_0, param_0->position, D_80800974_chhellterskelter);
}

void func_80800680_chhellterskelter(Actor *param_0, s32 param_1)
{
    f32 local_0[2];
    Actor *local_1;
    Unk80132ED0 *local_2;
    Actor *local_3;
    switch (param_1) {
    case 0x33A:
        local_2 = param_0->unk0;
        local_0[0] = 0.0f;
        local_0[1] = param_0->rotation[1];
        local_1 = func_8010856C(param_1, (f32 *)param_0->actorData, local_0);
        param_0 = func_80106790(local_2);
        func_80102FDC(local_1, param_0->scale);
        func_80105A9C(local_1, 700.0f);
        break;
    case 0x210:
        local_3 = func_80108528(param_1, (f32 *)((u8 *)param_0 + 0x28), 0, &param_0);
        func_80102FDC(local_3, 0.7f);
        if (param_0->unk64_20) {
            _subaddiefade_entrypoint_2(local_3);
            _chappearfx_entrypoint_1(local_3, 0x22, 1, 1.0f);
        }
        param_0->unk64_20 = 0;
        param_0->unk64_19 = 1;
        param_0->unk3C = local_3->unk0;
        break;
    }
}

/* TU-NOTE: the .data of this overlay (formerly asm/data/overlays/ch/hellterskelter.data.s) is defined here in C.
 * Its tables hold pointers to functions of this file; IDO's assembler schedules some of these
 * functions differently unless the tables are defined in the same unit. Values are taken from the ROM.
 * extern declarations adjusted to the object (same addresses): D_808007C8_chhellterskelter -> int[], D_80800810_chhellterskelter -> int[], D_80800858_chhellterskelter -> int[], D_808008A0_chhellterskelter -> s32[], D_808008AC_chhellterskelter -> s32[] */
extern int func_80105834();
extern void func_80101870();
extern void func_80107C2C();
extern u8 D_8011A270[];
extern void _chswitch_entrypoint_6();
extern void func_80102EC0();
extern void func_80108ED0();
u32 D_808007B0_chhellterskelter[6] = { 0x0, 0x0, 0x41287AE1, 0x1000400, 0x41287AE1, 0x1000000 };
int D_808007C8_chhellterskelter[18] = { 0x2A00339, 0x1, 0x0, (u32)func_808000A8_chhellterskelter, (u32)func_80105834, (u32)func_80101870, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, (u32)func_80800024_chhellterskelter, (u32)func_80107C2C, -0x7FFFF9FE, (u32)func_80800158_chhellterskelter, 0x0 };
int D_80800810_chhellterskelter[18] = { 0x343033B, 0x7520001, (u32)&D_8011A270, (u32)_chswitch_entrypoint_6, (u32)func_80105834, (u32)func_80101870, 0x0, 0x0, 0x0, 0x808, 0x0, 0x0, 0x0, (u32)func_80800274_chhellterskelter, (u32)func_80107C2C, -0x7FFFD3FE, (u32)func_80800294_chhellterskelter, 0x0 };
int D_80800858_chhellterskelter[18] = { 0x2A1033A, 0x6B80001, (u32)&D_808007B0_chhellterskelter, (u32)func_80102EC0, (u32)func_808002F0_chhellterskelter, (u32)func_80101870, 0x0, 0x0, 0x0, 0x21120, 0x0, (u32)func_80108ED0, 0x0, (u32)func_808002E8_chhellterskelter, (u32)func_80107C2C, -0x7FFFFC00, 0x0, 0x0 };
s32 D_808008A0_chhellterskelter[3] = { 0x13063C, 0xD00F3, 0x10C0000 };
s32 D_808008AC_chhellterskelter[5] = { 0x130410, 0xD00C0, 0xD90018, 0x1012C, 0x4B00000 };
u8 D_808008C0_chhellterskelter[52] = { 0x0, 0x1D, 0x9, 0xDD, 0x0, 0x1B, 0x0, 0x96, 0x0, 0xFA, 0x0, 0x20, 0xC0, 0xC0, 0xC0, 0x7F, 0x0, 0x16, 0x0, 0x8, 0x0, 0x22, 0x0, 0x99, 0x0, 0xB3, 0x0, 0xD9, 0x0, 0xE6, 0x0, 0x15, 0x0, 0x0, 0x0, 0x80, 0x0, 0x1E, 0x0, 0x5, 0x0, 0xA, 0x0, 0x2B, 0x0, 0xC0, 0x1, 0x33, 0x0, 0x0, 0x0, 0x0 };
u8 D_808008F4_chhellterskelter[48] = { 0x0, 0x1D, 0x9, 0xD3, 0x0, 0x14, 0x0, 0x16, 0x0, 0x0, 0x0, 0x7, 0x0, 0x1, 0x0, 0x16, 0x10, 0x0, 0x0, 0x2D, 0x1, 0x90, 0x2, 0x58, 0x0, 0x22, 0x0, 0x19, 0x0, 0x33, 0x0, 0xC, 0x0, 0x19, 0x0, 0xB, 0x0, 0xA, 0x0, 0x28, 0x0, 0xA, 0xFF, 0xF6, 0x0, 0x0, 0x0, 0x0 };
u8 D_80800924_chhellterskelter[20] = { 0x0, 0x13, 0x6, 0xF, 0x0, 0xD, 0x0, 0xF3, 0x1, 0xC, 0x0, 0x1, 0x1, 0xF4, 0x7, 0xD0, 0x0, 0x0, 0x0, 0x0 };
u8 D_80800938_chhellterskelter[60] = { 0x8, 0x10, 0x0, 0x1D, 0x9, 0xDD, 0x0, 0x2D, 0x2, 0x58, 0x3, 0x20, 0x0, 0xB, 0x0, 0x14, 0x0, 0x32, 0x0, 0xA, 0x0, 0x0, 0x0, 0x1F, 0xC0, 0xC0, 0xC0, 0x0, 0x0, 0x22, 0x0, 0x99, 0x1, 0x0, 0x2, 0x0, 0x2, 0x80, 0x0, 0x15, 0x0, 0x0, 0x0, 0x99, 0x0, 0x2A, 0x0, 0x0, 0x0, 0xA, 0x0, 0xCC, 0x1, 0x0, 0x0, 0xF, 0x0, 0x0, 0x0, 0x0 };
u8 D_80800974_chhellterskelter[28] = { 0x0, 0x13, 0x4, 0xDC, 0x0, 0xD, 0x0, 0xCC, 0x0, 0xE6, 0x0, 0x15, 0x0, 0x80, 0x0, 0x66, 0x0, 0x33, 0x0, 0x1, 0x1, 0xF4, 0x7, 0xD0, 0x0, 0x0, 0x0, 0x0 };
