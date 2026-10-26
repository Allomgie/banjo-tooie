#include "common.h"

extern void *func_80100094(Actor *, u32);
extern Actor *func_80106790(Unk80132ED0 *);
extern u8 D_80800BD0_chmoley[];
extern void _gcdialogcamera_entrypoint_3(void *, f32);
extern s32 func_80101E14(Actor *, f32);
extern void _suexpression_entrypoint_7();
extern void _suexpression_entrypoint_12(void *, f32, f32);
typedef struct { u8 pad[0x79]; u8 hi:4; u8 lo:4; } MoleyState;
extern void func_800FCAE0(u32, u32, u32);
extern void func_800FCA90(u32);
extern void func_80102424(Actor *, s32);
extern int D_80800C10_chmoley[];
typedef struct { f32 value[4]; } MoleyAnimationTriggers;
extern MoleyAnimationTriggers D_80800BE0_chmoley;
extern MoleyAnimationTriggers D_80800BF0_chmoley;
extern MoleyAnimationTriggers D_80800C00_chmoley;
extern u32 D_80800A90_chmoley[];
extern u32 D_80800AA8_chmoley[];
extern u32 D_80800AC0_chmoley[];
extern u32 D_80800AD8_chmoley[];
extern u32 D_80800AF0_chmoley[];
extern u32 D_80800B08_chmoley[];
extern u32 D_80800B20_chmoley[];
extern u32 D_80800B38_chmoley[];
extern u32 D_80800B4C_chmoley[];
extern void _suexpression_entrypoint_10(u32 *, Unk80132ED0 *, u32);
extern void _chmolehill_entrypoint_1(Actor *, s32);
extern void _chmolehill_entrypoint_2(Actor *, s32);
extern s32 func_80101DDC(Actor *);
extern s32 func_80101E4C(Actor *, f32 *);
extern f32 func_80101F24(Actor *);
extern s32 func_801022E4(Actor *);
extern s32 func_80104248();
extern s32 func_800DC298(f32);
extern void _subaddiedialog_entrypoint_11(Unk80132ED0 *, s32, s32, f32 *, s32);
extern s32 _subaddieaudioloop_entrypoint_4(Actor *, f32 *, u32, u32 *);
extern void _subaddieaudioquick_entrypoint_2(Actor *, f32 *, void *);
extern void _subaddieaudioquick_entrypoint_3(Actor *, f32 *, u32 *, f32);

s32 func_80800000_chmoley(Actor *param_0, s32 param_1, s32 param_2)
{
    if (param_0->unk64_17) return 0;
    switch (param_1) {
        case 0x2E:
        case 0x2F:
        case 0x30:
            return func_8010114C(_chmolehill_entrypoint_5(func_80106790(param_0->unk3C)), param_1, param_2);
        case 0x52:
            _gcdialogcamera_entrypoint_3(D_80800BD0_chmoley, 1.0f);
            break;
        default: return 0;
    }
    return 1;
}

void func_808000AC_chmoley(Actor *param_0, s32 *param_1)
{
  if (param_0->unk64_20) {
    func_800DF744(3, 1);
    func_800DF744(5, 0);
  } else {
    func_800DF744(3, 0);
    func_800DF744(5, 1);
  }
  if (param_0->unk64_19) {
    func_800DF744(4, 1);
    func_800DF744(6, 0);
    func_800DF744(7, 1);
  } else {
    func_800DF744(4, 0);
    func_800DF744(6, 1);
    func_800DF744(7, 0);
  }
  func_800DF744(8, 0);
  func_80101870(param_0, param_1);
}

s32 func_80800190_chmoley(Actor *param_0)
{
    if (!func_80104248()) {
        return 1;
    }
    switch (func_801022E4(param_0)) {
        case 0x2BC:
        case 0x2C8:
            return 1;
        case 0x2BF:
            if (func_80101E14(param_0, 0.0909f)) {
                param_0->unk64_19 = 1;
            } else if (func_80101E14(param_0, 0.8295f)) {
                param_0->unk64_19 = 0;
            }
            if (func_80101DDC(param_0)) {
                return 1;
            }
            break;
        default:
            if (func_80101E14(param_0, 0.999f)) {
                return 1;
            }
            break;
    }
    return 0;
}

void func_80800274_chmoley(Actor *param_0)
{
    f32 local_0;
    MoleyAnimationTriggers local_1;
    MoleyAnimationTriggers local_2;
    MoleyAnimationTriggers local_3;

    _suexpression_entrypoint_10(func_80100094(param_0, 1), param_0->unk0, 0);
    switch (param_0->unk79_4) {
        case 2:
            if (func_80800190_chmoley(param_0)) {
                _chmolehill_entrypoint_1(param_0, 0);
                _chmolehill_entrypoint_2(func_80106790(param_0->unk3C), 6);
            }
            break;
        case 5:
            if (func_80800190_chmoley(param_0)) {
                _chmolehill_entrypoint_1(param_0, 0);
                _chmolehill_entrypoint_2(func_80106790(param_0->unk3C), 5);
            }
            break;
        case 6:
            if (func_80800190_chmoley(param_0)) {
                _chmolehill_entrypoint_1(param_0, 0);
                _chmolehill_entrypoint_2(func_80106790(param_0->unk3C), 10);
            }
            break;
        case 0:
        case 1:
        case 3:
        case 4:
        default:
            break;
    }
    switch (param_0->unk70_10) {
        case 2:
            if (func_80101E14(param_0, 0.583f)) {
                param_0->unk64_20 = 1;
            } else if (func_80101E14(param_0, 0.931f)) {
                param_0->unk64_20 = 0;
            }
            if (func_80101DDC(param_0)) {
                _chmolehill_entrypoint_2(func_80106790(param_0->unk3C), 10);
            }
            break;
        case 7:
            if (func_80101DDC(param_0)) {
                _chmolehill_entrypoint_2(func_80106790(param_0->unk3C), 9);
            }
            break;
        case 8:
            if (func_80101DDC(param_0)) {
                _chmolehill_entrypoint_2(func_80106790(param_0->unk3C), 1);
            }
            break;
        case 6:
            if (func_80101E14(param_0, 0.0f)) {
                _subaddiedialog_entrypoint_11(param_0->unk0, 0xDBD, 4, param_0->position, 0x6F);
            } else if (func_80101DDC(param_0)) {
                if (func_800DC298(0.09999084473f)) {
                    _chmolehill_entrypoint_2(func_80106790(param_0->unk3C), 11);
                } else {
                    _chmolehill_entrypoint_2(func_80106790(param_0->unk3C), 3);
                }
            }
            break;
        case 3:
            if (func_80101DDC(param_0)) {
                _chmolehill_entrypoint_2(func_80106790(param_0->unk3C), 1);
            }
            break;
        case 11:
            if (func_80101E14(param_0, 0.0921f)) {
                param_0->unk64_20 = 1;
            } else if (func_80101DDC(param_0)) {
                param_0->unk64_20 = 0;
                _chmolehill_entrypoint_2(func_80106790(param_0->unk3C), 1);
            }
            break;
        case 10:
            if (func_80101E14(param_0, 0.999f) && func_800DC298(0.25f)) {
                _chmolehill_entrypoint_2(func_80106790(param_0->unk3C), 4);
            }
            break;
        case 4:
            if (func_80101E14(param_0, 0.0909f)) {
                param_0->unk64_19 = 1;
            } else if (func_80101E14(param_0, 0.8295f)) {
                param_0->unk64_19 = 0;
            } else if (func_80101E14(param_0, 0.999f)) {
                _chmolehill_entrypoint_2(func_80106790(param_0->unk3C), 10);
            }
            break;
    }
    if (func_80104248(param_0)) {
        switch (func_801022E4(param_0)) {
            case 0x2C9:
                local_0 = func_80101F24(param_0);
                if (local_0 >= 0.6f && local_0 <= 0.7f) {
                    _subaddieaudioloop_entrypoint_4(param_0, param_0->position, 1, D_80800B4C_chmoley);
                }
                _subaddieaudioquick_entrypoint_3(param_0, param_0->position, D_80800A90_chmoley, 0.16f);
                _subaddieaudioquick_entrypoint_3(param_0, param_0->position, D_80800AA8_chmoley, 0.3f);
                break;
            case 0x2C8:
                local_1 = D_80800BE0_chmoley;
                local_2 = D_80800BF0_chmoley;
                local_3 = D_80800C00_chmoley;
                if (func_80101E4C(param_0, local_1.value)) {
                    _subaddieaudioquick_entrypoint_2(param_0, param_0->position, D_80800AC0_chmoley);
                } else if (func_80101E4C(param_0, local_2.value)) {
                    _subaddieaudioquick_entrypoint_2(param_0, param_0->position, D_80800AD8_chmoley);
                } else if (func_80101E4C(param_0, local_3.value)) {
                    _subaddieaudioquick_entrypoint_2(param_0, param_0->position, D_80800AF0_chmoley);
                }
                break;
            case 0x2BC:
                if (func_80101E14(param_0, 0.24f)) {
                    _subaddieaudioquick_entrypoint_2(param_0, param_0->position, D_80800B08_chmoley);
                }
                if (func_80101E14(param_0, 0.74f)) {
                    _subaddieaudioquick_entrypoint_2(param_0, param_0->position, D_80800B20_chmoley);
                }
                break;
            case 0x2BB:
                if (func_80101E14(param_0, 0.26f)) {
                    _subaddieaudioquick_entrypoint_2(param_0, param_0->position, D_80800B38_chmoley);
                }
                break;
            case 0x2BE:
            case 0x2BF:
            case 0x2C1:
            case 0x2C2:
            case 0x2C3:
            case 0x2C4:
            default:
                break;
        }
    }
}

void func_8080088C_chmoley(Actor* arg0) 
{
    if (func_80100094(arg0,1) != 0)
    {
        _suexpression_entrypoint_8(arg0, 1);
    }
}
void func_808008C0_chmoley(u8 *param_0) {
    *(f32 *)(param_0 + 0x38) = 0.5f;
    _suexpression_entrypoint_7(param_0, 1, 0x6F);
    _suexpression_entrypoint_12(func_80100094(param_0, 1), 0.0f, 0.0f);
}

void chmoley_entrypoint_0(MoleyState *param_0, s32 param_1) {
    param_0->hi = param_1;
}

void chmoley_entrypoint_1(Actor *param_0, s32 param_1)
{
    if (param_1 != param_0->unk70_10) {
        if (param_0->unk70_10 == 5) {
            func_800FCAE0(0x3A, 0, 0x7D0);
            func_800FCA90(0x3A);
        }
        func_80102424(param_0, param_1);
        switch (param_0->unk70_10) {
        case 5:
            func_800FCAE0(0x3A, -1, 0x7D0);
            break;
        case 1:
            param_0->unk64_16 = 0;
            break;
        default:
            param_0->unk64_16 = 1;
            break;
        }
    }
}

int chmoley_entrypoint_2()
{
  return &D_80800C10_chmoley;
}

/* TU-NOTE: the .data of this overlay (formerly asm/data/overlays/ch/mole/y.data.s) is defined here in C --
 * tables holding function pointers must be in the same unit, otherwise IDO's assembler schedules those functions differently.
 * extern views adjusted to the object (address-neutral): D_80800C10_chmoley -> int[] */
extern void func_80105834();
extern void func_80107C2C();
u32 D_80800A90_chmoley[6] = { 0x130614, 0xD0173, 0x18C0016, 0x6D600001, 0x1F409C4, 0x0 };
u32 D_80800AA8_chmoley[6] = { 0x1305A4, 0xD0173, 0x18C0016, 0x3A980001, 0x1F409C4, 0x0 };
u32 D_80800AC0_chmoley[6] = { 0x130449, 0xD0166, 0x18C0016, 0x1F400001, 0x1F409C4, 0x0 };
u32 D_80800AD8_chmoley[6] = { 0x130449, 0xD0159, 0x1800016, 0x1F400001, 0x1F409C4, 0x0 };
u32 D_80800AF0_chmoley[6] = { 0x130402, 0xD00F3, 0x10C0016, 0x5DC00001, 0x1F409C4, 0x0 };
u32 D_80800B08_chmoley[6] = { 0x13062D, 0xD00F3, 0x10C0016, 0x55F00001, 0x1F409C4, 0x0 };
u32 D_80800B20_chmoley[6] = { 0x13062E, 0xD00F3, 0x10C0016, 0x55F00001, 0x1F409C4, 0x0 };
u32 D_80800B38_chmoley[5] = { 0x130653, 0x166D60, 0x101F4, 0x9C40020, 0x0 };
u32 D_80800B4C_chmoley[5] = { 0x130679, 0xA0133, 0x164650, 0x105DC, 0x9C40000 };
u32 D_80800B60_chmoley[28] = { 0x0, 0x0, 0x3FD9999A, 0x2BE0044, 0x3FD9999A, 0x2BE0002, 0x3FCCCCCD, 0x2C10002, 0x40966666, 0x2BF0002, 0x3F333333, 0x2BC0001, 0x3FA66666, 0x2BB0002, 0x3F4CCCCD, 0x2C20002, 0x3F666666, 0x2C30002, 0x40800000, 0x2C40001, 0x41180000, 0x2C80001, 0x40C00000, 0x2C90002, 0x40800000, 0x2C40001, 0x41180000, 0x2C80201 };
u8 D_80800BD0_chmoley[16] = { 0x43, 0x16, 0x0, 0x0, 0x42, 0x82, 0x0, 0x0, 0x42, 0x82, 0x0, 0x0, 0x41, 0xC8, 0x0, 0x0 };
MoleyAnimationTriggers D_80800BE0_chmoley = { 0.6999f, 0.7399f, 0.7699f, -1.0f };
MoleyAnimationTriggers D_80800BF0_chmoley = { 0.8799f, 0.8999f, 0.9175f, -1.0f };
MoleyAnimationTriggers D_80800C00_chmoley = { 0.1899f, 0.2399f, 0.2699f, -1.0f };
int D_80800C10_chmoley[20] = { 0xB7018F, 0x7D60001, (u32)&D_80800B60_chmoley, (u32)func_80800274_chmoley, (u32)func_80105834, (u32)func_808000AC_chmoley, 0x9C40000, 0x0, 0x0, 0x14C, (u32)func_8080088C_chmoley, 0x0, 0x0, (u32)func_808008C0_chmoley, (u32)func_80107C2C, -0x7FFFDFFE, (u32)func_80800000_chmoley, 0x0, 0x0, 0x0 };
