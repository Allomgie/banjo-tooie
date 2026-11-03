#include "common.h"

extern int D_808004C0_chklungodoors[];
extern void func_8010A800();
typedef struct { s16 local_0; s16 local_1; s32 local_2; s32 local_3; u16 local_4; u8 local_5; u8 local_6; } KlungoDoorSettings48;
extern KlungoDoorSettings48 D_80800490_chklungodoors[];
extern s32 _chdoormake_entrypoint_3(Actor *, f32, f32, f32, s32, s32);
extern s32 _chdoormake_entrypoint_4(Actor *, s32, s32);
extern void _chdoormake_entrypoint_5(Actor *, f32);
extern void _chdoormake_entrypoint_6(Actor *, f32);
typedef struct { u8 local_0; u8 pad_0[15]; } KlungoDoorFlag;
extern KlungoDoorFlag D_8080049E_chklungodoors[];
extern u8 D_80800550_chklungodoors[];
extern f32 func_800F10B4(f32, f32, f32, f32, f32);
extern void _subaddieaudioloop_entrypoint_0(Actor *, f32);
typedef struct { u16 unk0; u16 unk2; u8 pad4[2]; u8 unk6; u8 pad7[9]; } KlungoDoor;
typedef struct { u8 pad0[0x16]; u16 unk16; } KlungoModel;
extern KlungoDoor D_80800498_chklungodoors[];
extern KlungoDoor D_8080049A_chklungodoors[];
typedef struct { u8 unk0; u8 pad1[15]; } KlungoFlag;
extern void func_80103140();
extern void func_8010A570(Actor *);
extern void func_800EC75C(s32, f32 *);
extern void _chelectricfence_entrypoint_1(Actor *, f32 *);
extern s32 _chdoor_entrypoint_1(Actor *, s32, s32);

int chklungodoors_entrypoint_0()
{
  return (int)&D_808004C0_chklungodoors;
}

int chklungodoors_entrypoint_1()
{
    extern int D_80800508_chklungodoors[];
    return (int)&D_80800508_chklungodoors;
}

void func_80800018_chklungodoors(Actor *param_0)
{
    KlungoDoorSettings48 *local_0;
    KlungoDoorSettings48 *local_1;
    s32 local_2;
    s32 local_3;

    local_0 = NULL;
    for (local_2 = 0, local_1 = D_80800490_chklungodoors; local_2 < 3; local_2++, local_1++) {
        if (func_800EA05C() == local_1->local_0) {
            local_0 = local_1;
            param_0->actorData[4] = local_2;
            break;
        }
    }
    func_80102FDC(param_0, local_0->local_2);
    func_8010A800(param_0, 0);
    if (param_0->unk6C_9 == 0x420) {
        if (local_0->local_5) {
            func_80103110(param_0, 1);
            local_3 = _chdoormake_entrypoint_4(param_0, 0xA82A, local_0->local_4);
        } else {
            local_3 = _chdoormake_entrypoint_3(param_0, 0.0f, 90.0f, (f32)local_0->local_1, 0x122, local_0->local_4);
        }
        if (local_3) {
            _chdoormake_entrypoint_5(param_0, 0.7f);
            _chdoormake_entrypoint_6(param_0, 2.0f);
            _chdoormake_entrypoint_8(param_0, local_0->local_6);
        }
    } else {
        if (local_0->local_5) {
            func_80103110(param_0, 1);
            local_3 = _chdoormake_entrypoint_4(param_0, 0xA82A, -1);
        } else {
            local_3 = _chdoormake_entrypoint_3(param_0, 0.0f, 90.0f, (f32)local_0->local_1, 0x122, -1);
        }
        if (local_3) {
            _chdoormake_entrypoint_5(param_0, 0.7f);
            _chdoormake_entrypoint_6(param_0, 0.25f);
            _chdoormake_entrypoint_8(param_0, local_0->local_6);
        }
    }
    if (local_0->local_5) {
        *(u16 *)&param_0->unk0->unk24 = (*(u16 *)&param_0->unk0->unk24 & 0x3F) | 0xCC40;
        func_80103110(param_0, 1);
        func_8010A5B0(param_0, local_3 == 1);
    }
}

void func_80800234_chklungodoors(Actor *param_0)
{
    s32 local_0;

    _chdoor_entrypoint_0(param_0);
    if (D_8080049E_chklungodoors[param_0->actorData[4]].local_0) {
        local_0 = _subaddiefade_entrypoint_0(param_0);
        _subaddieaudioloop_entrypoint_4(param_0, param_0->position, local_0 > 0, D_80800550_chklungodoors);
        _subaddieaudioloop_entrypoint_0(param_0, func_800F10B4((f32)local_0, 0.0f, 255.0f, 0.7f, 1.4f));
        if (param_0->unk70_10 == 1 && func_800D9078((f32 *)&param_0->actorData[5])) func_8010A590(param_0);
    }
}

s32 func_80800300_chklungodoors(Actor *param_0, s32 param_1, s32 param_2)
{
    f32 local_1[3];
    s32 local_0[1];

    switch (param_1) {
    case 0x95:
        switch (param_0->unk6C_9) {
        case 0x41F:
            func_80103140(param_0, D_80800498_chklungodoors[param_0->actorData[4]].unk0, ((KlungoModel *)param_0->unk0)->unk16);
            break;
        case 0x420:
            func_80103140(param_0, D_8080049A_chklungodoors[param_0->actorData[4]].unk0, ((KlungoModel *)param_0->unk0)->unk16);
            break;
        }
        break;
    case 7:
        if (((KlungoFlag *) D_8080049E_chklungodoors)[param_0->actorData[4]].unk0) {
            func_8010A570(param_0);
        }
        break;
    case 8:
        if (((KlungoFlag *) D_8080049E_chklungodoors)[param_0->actorData[4]].unk0) {
            func_8010A570(param_0);
        }
        break;
    case 0x3F:
        local_0[0] = param_2;
        func_800EC75C(local_0[0], local_1);
        _chelectricfence_entrypoint_1(param_0, local_1);
        *(f32 *)&param_0->actorData[5] = 0.2f;
        func_8010A570(param_0);
        return 1;
    }
    return _chdoor_entrypoint_1(param_0, param_1, param_2);
}

/* TU-NOTE: the .data of this overlay (formerly asm/data/overlays/ch/klungo/doors.data.s) is defined here in C.
 * Its tables hold pointers to functions of this file; IDO's assembler schedules some of these
 * functions differently unless the tables are defined in the same unit. Values are taken from the ROM.
 * Labels inside an object are linker symbols in undefined_syms.us.txt: D_8080049A_chklungodoors = D_80800490_chklungodoors + 0xA, D_8080049E_chklungodoors = D_80800490_chklungodoors + 0xE, D_80800498_chklungodoors = D_80800490_chklungodoors + 0x8
 * extern declarations adjusted to the object (same addresses): D_808004C0_chklungodoors -> int[], D_80800508_chklungodoors -> int[] */
extern void func_80105834();
extern void func_80101870();
extern void func_80108ED0();
extern void func_80107C2C();
KlungoDoorSettings48 D_80800490_chklungodoors[3] = { 0x141, 0x1F4, 0x3FC00000, 0x7AE07AE, 0x318, 0x0, 0x2, 0x15B, 0x1F4, 0x3FA00000, 0x7AE07AE, 0x319, 0x0, 0x2, 0x15E, 0x15E, 0x3F800000, 0x94D094C, 0x31A, 0x1, 0xB };
int D_808004C0_chklungodoors[18] = { 0xAC041F, 0x7AE0004, 0x0, (u32)func_80800234_chklungodoors, (u32)func_80105834, (u32)func_80101870, 0x0, 0x0, 0x0, 0xC00, 0x0, (u32)func_80108ED0, 0x0, (u32)func_80800018_chklungodoors, (u32)func_80107C2C, -0x7FF7D3FE, (u32)func_80800300_chklungodoors, 0x0 };
int D_80800508_chklungodoors[18] = { 0xAC0420, 0x7AE0001, 0x0, (u32)func_80800234_chklungodoors, (u32)func_80105834, (u32)func_80101870, 0x0, 0x0, 0x0, 0xC00, 0x0, (u32)func_80108ED0, 0x0, (u32)func_80800018_chklungodoors, (u32)func_80107C2C, -0x7FF7D3FE, (u32)func_80800300_chklungodoors, 0x0 };
u8 D_80800550_chklungodoors[32] = { 0x0, 0x13, 0x5, 0xB7, 0x0, 0x1, 0x0, 0xC8, 0x7, 0xD0, 0x0, 0xA, 0x1, 0x66, 0x0, 0x16, 0x7D, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0 };
