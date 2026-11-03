#include "common.h"

extern void *D_80802E50_chinflatableboss;
struct anctrl_s;
extern s16 D_80802D8C_chinflatableboss[];
extern void *func_80100094(Actor *, u32);
extern void *func_80104248(Actor *);
extern void func_8008B1C8(struct anctrl_s *, f32);
typedef struct { u8 pad_0[0x18]; u32 pad_1 : 11; u32 section : 4; u32 pad_2 : 17; } InflatableBossMarker;
extern u8 D_80802F08_chinflatableboss[];
typedef struct { u8 local_0[0x10]; f32 local_1[3]; u8 pad_0[0x478]; u8 local_2; u8 pad_1[2]; u8 local_3; } InflatableBossDestination;
extern f32 func_800DC178(f32, f32);
extern u8 D_80802F68_chinflatableboss[];
extern void func_800EE7F8(f32 *, f32 *);
extern f32 func_80102D78(Actor *, void *);
extern f32 func_800D8FF8(void);
extern f32 func_800F15F8(f32, f32, f32);
extern f32 func_80101F24(Actor *);
extern f32 func_800F3780(f32, void *, s32);
extern void func_80102BF8(Actor *, f32, f32, f32);
extern void func_8010C3A8(Actor *, s32, f32);
extern s32 func_800F0064(f32 *, f32, f32 *);
extern Actor *func_80108528(s32, f32 *, s32, Actor **);
extern void func_80102FDC(Actor *, f32);
extern f32 D_80802D98_chinflatableboss[];
typedef struct { u8 pad_0[0x254]; f32 local_0[3]; u8 pad_1[4]; f32 local_1; } InflatableSpawnAnchor;
extern void _chappearfx_entrypoint_1(Actor *, s32, s32, f32);
typedef struct { f32 position[3]; f32 unused; f32 yaw; s32 flags; } InflatableBossSpawn;
typedef struct { u8 pad[0x6C]; s32 count; InflatableBossSpawn spawns[1]; } InflatableBossSpawnList;
extern Actor *func_80108474(s32, f32 *, s32);
extern void _chappearfx_entrypoint_2(Actor *, s32, s32, f32);
extern s32 D_80802F90_chinflatableboss[];
extern s32 D_80802FC4_chinflatableboss[];
typedef struct { u8 pad_0[0x40]; f32 local_0; u8 pad_1[0x453]; u8 local_1; } InflatableBossAttackDuration;
extern s16 D_80802D80_chinflatableboss[];
extern void func_80101CDC(Actor *, f32);
extern void func_800EFA4C(f32 *, f32, f32, f32);
extern s32 func_800B0D80(s32, s32, f32 *, f32 *, f32, s32, s32, f32 *, f32 *);
extern u8 func_8010D5DC[];
extern void func_800F4A58(s32, f32 *, f32);
typedef struct { f32 local_0[3]; s32 local_1; u8 pad_0[8]; } InflatableMarker481;
typedef struct { u32 a : 1; u32 b : 1; u32 rest : 30; } BF74;
extern s32 D_80802E98_chinflatableboss[];
extern s32 D_80802EA0_chinflatableboss[];
extern s32 D_80802EB4_chinflatableboss[];
extern s32 D_80802EC4_chinflatableboss[];
extern s32 D_80802ED0_chinflatableboss[];
extern s32 D_80802EDC_chinflatableboss[];
extern s32 D_80802EE8_chinflatableboss[];
extern s32 func_80102CF4(u8 *, f32);
extern f32 func_8010CD28();
extern f32 func_800F10B4(f32, f32, f32, f32, f32);
extern void func_800C4B64(f32);
extern void _subaddieaudioquick_entrypoint_3(u8 *, u8 *, s32 *, f32);
typedef struct { u8 pad0[0x1C]; f32 unk1C[3]; u8 pad28[0x20]; f32 unk48[3]; f32 unk54[3]; u8 pad60[0x427]; u8 unk487[12]; u8 pad493[3]; u8 unk496; u8 pad497; u8 unk498; u8 unk499; u8 unk49A; u8 pad49B; u8 unk49C; u8 unk49D; } BalloonData;
typedef union { s32 i; struct { s16 a; s16 b; } h; } BalloonArg;
typedef struct { s32 v[3]; } BalloonEntry;
extern BalloonEntry B_80803020_chinflatableboss[];
extern void func_80101180(s32, s32, s32);
extern void func_800FFAB0(Actor *);
extern void func_80108B04(Actor *, s32);
extern s32 func_800F54E4(void);
extern void func_800F497C(s32);
extern void func_800F49D4(s32, void *, Unk80132ED0 *);
extern void _subaddiedialog_entrypoint_11(Unk80132ED0 *, s32, s32, f32 *, s32);
extern void func_800F8300(s32, s32, f32 *);
extern void func_80101010(f32 *);
extern void func_800F49A8(s32, s32);
extern void func_800FDC28(s32);
extern s32 func_800D395C(void);
extern void func_80101074(BalloonEntry *);
extern s32 D_80802F2C_chinflatableboss[];
extern s16 D_80802F0E_chinflatableboss[];
extern void func_800EFB24(f32 *, f32 *, f32 *);
extern void func_800EF368(f32 *, f32);
extern void func_800EF04C(f32 *, f32 *);
extern int func_800BABB8(s32, f32 *, f32 *, f32, void *);
extern void func_800BA714();
extern s32 func_800AE630(void *, u8 *, s32, f32 *);
extern s32 func_801017D0(s32 *);
extern void *func_80101808(Actor *, s32 (*)(s32 *));
extern void *func_80104130(void);
extern void func_800DBEFC(void *, s32, f32 *);
extern void *func_801040A8(Actor *);
extern void *func_800B27E0(void *);
extern void *func_800D674C(s32);
extern void func_800EFD24(f32 *);
extern void func_800EF334(f32 *, f32);
extern void func_800EF5A0(f32 *, f32 *, f32, f32, f32);
extern void *func_800DE448(f32 *, f32 *, f32, f32 *, s32);
extern void func_800BC358();
extern s32 D_80802FF8_chinflatableboss[];
extern void func_800BBD18(s32, f32 *, f32 *, f32, s32);
extern u8 func_800C4350(u8, f32 *, void *);
extern u8 D_80803008_chinflatableboss[];
extern void func_800C3868(u8, f32, f32, f32, f32);
typedef struct { u8 pad_0[0x487]; u8 states[12]; } InflatablePartStates;
int func_80801904_chinflatableboss();
s32 func_80801C7C_chinflatableboss();
s32 func_80801CB4_chinflatableboss();
void func_80801EA0_chinflatableboss();
int func_80801FC0_chinflatableboss();
s32 func_80802590_chinflatableboss();
void func_8080267C_chinflatableboss();
void func_80802A00_chinflatableboss();
int func_80802A2C_chinflatableboss();
void func_80802A9C_chinflatableboss();
void func_80802AD8_chinflatableboss();
void func_808004A0_chinflatableboss();
s32 func_80800A98_chinflatableboss(Actor *param_0, s32 param_1, BalloonArg param_2);
void func_808012EC_chinflatableboss();
void func_80801554_chinflatableboss();
void func_80801958_chinflatableboss();
void func_80801F4C_chinflatableboss();
void func_80802058_chinflatableboss();
void func_80802264_chinflatableboss(Actor *param_0, f32 param_1, f32 param_2, s32 *param_3, s16 param_4);
f32 func_808023B0_chinflatableboss();
extern void func_80105834(), func_80107C2C(), func_80108ED0(), func_80800408_chinflatableboss(), func_808004A0_chinflatableboss(), func_80801554_chinflatableboss();
extern u8 D_80802DB0_chinflatableboss[];

int chinflatableboss_entrypoint_0()
{
  return &D_80802E50_chinflatableboss;
}

void func_8080183C_chinflatableboss();

void func_80800F84_chinflatableboss();

void func_8080000C_chinflatableboss(param_0) Actor *param_0;
{
    u8 *local_6;
    s32 local_0;
    InflatableMarker481 local_1[3];
    s32 local_2;
    s32 local_4;
    s32 local_3;
    f32 *local_7;
    s32 local_5;

    local_6 = func_80100094(param_0, 0);
    func_800DA524(1);
    func_800DA524(2);
    func_800DA524(4);
    func_800DA524(3);
    func_800DA524(5);
    if (func_800DA298(0x9C) && !_glcutDll_entrypoint_20()) {
        func_800DA544(3);
        _chintrotext_entrypoint_2(1);
        func_800FFAB0(param_0);
        return;
    }
    func_80102FDC(param_0, 1.4f);
    local_6[0x494] = 1;
    local_6[0x495] = D_80802D8C_chinflatableboss[0];
    *(f32 *)((u8 *)param_0 + 0x28) = 0.35f;
    func_80109FE8(param_0, 0);
    local_7 = param_0->position;
    func_800EE7F8((f32 *)(local_6 + 0x1C), local_7);
    func_800EE7F8((f32 *)(local_6 + 0x28), local_7);
    func_800EE7F8((f32 *)(local_6 + 0x34), local_7);
    for (local_0 = 0; local_0 != 12; local_0++) {
        func_80802AD8_chinflatableboss(param_0, local_0, 1);
    }
    _subaddieDll_entrypoint_10(0x154, local_6);
    _subaddieDll_entrypoint_10(0x320, local_6 + 8);
    func_8080183C_chinflatableboss(param_0);
    func_8010A85C(param_0, 2);
    _suexpression_entrypoint_7(param_0, 1, 0x3A);
    *(s32 *)(local_6 + 0x6C) = _subaddiemarker_entrypoint_1(param_0, 0x437, 0x32, local_6 + 0x70, 0x14);
    *(s32 *)(local_6 + 0x250) = _subaddiemarker_entrypoint_1(param_0, 0x437, 0x35, local_6 + 0x254, 0x14);
    local_3 = _subaddiemarker_entrypoint_0(param_0, 0x3DA, local_1, 0x14);
    for (local_2 = 0; local_2 < local_3; local_2++) {
        for (local_4 = 0; local_4 < local_3; local_4++) {
            if (local_1[local_4].local_1 - 0x32 == local_2) {
                break;
            }
        }
        func_800EE7F8(((Vec3f *)(local_6 + 0x48))[local_2].f, local_1[local_4].local_0);
    }
    if (func_800DA298(0x17F)) {
        local_6[0x498] = 5;
    } else {
        local_6[0x498] = 1;
    }
    if (!func_800F64A4(func_800F54E4(), 1)) {
        local_6[0x498] = 0;
    }
    if (_glcutDll_entrypoint_20()) {
        func_8010A85C(param_0, 1);
        func_80800F84_chinflatableboss(param_0,
            _chcredits_entrypoint_1() == 0x36 ? 0x12 : 0x13);
        return;
    }
    if (local_6[0x498] == 5) {
        local_5 = func_800F54E4();
        local_6[0x49C] = 1;
        local_6[0x496] = 1;
        func_800F608C(local_5, 1);
        func_800F8294(local_5, local_6 + 0x54);
        func_800F8300(local_5, 2, local_7);
        func_800F497C(local_5);
        _plcamera_entrypoint_8(local_5);
        func_800DA544(2);
        func_80802A00_chinflatableboss(param_0, 0x22, 0x20);
        _subaddiedialog_entrypoint_11(param_0->unk0, 0x1087, 0x107, local_7, 0x3A);
        func_80800F84_chinflatableboss(param_0, 3);
        func_8010A85C(param_0, 1);
        return;
    }
    if (func_800D395C()) {
        param_0->unk64_16 = 1;
        local_6[0x498] = 2;
        func_800F497C(func_800F54E4());
        func_800F49D4(func_800F54E4(), func_8010D5DC, param_0->unk0);
        func_800F4A58(func_800F54E4(), (f32 *)(local_6 + 0x48), 300.0f);
        func_80802A00_chinflatableboss(param_0, 0x2F, 0x20);
        return;
    }
    ((u8 *)param_0)[0x65] &= ~1;
    _chintrotext_entrypoint_2(1);
}

void func_80800408_chinflatableboss(param_0) s32 param_0; {
    u8 *local_0;
    s32 local_1;
    s32 local_2;
    s32 local_3;
    u8 *local_4;

    local_0 = func_80100094(param_0, 0);
    _suexpression_entrypoint_8(param_0, 1);
    local_3 = 0;
    local_4 = local_0;
    do {
        local_1 = (*(s32 *)((s8 *)(local_4) + (0x43C)));
        if (local_1 != 0) {
            (*(s32 *)((s8 *)(local_4) + (0x43C))) = func_800BA2C4(local_1);
        }
        local_3 += 4;
        local_4 += 4;
    } while (local_3 != 0x30);
    local_2 = (*(s32 *)((s8 *)(local_0) + (0x434)));
    if (local_2 != 0) {
        (*(s32 *)((s8 *)(local_0) + (0x434))) = func_800BA2C4(local_2);
    }
}

void func_80802910_chinflatableboss();

s32 func_8080272C_chinflatableboss();

void func_808024BC_chinflatableboss();

void func_80802450_chinflatableboss();

int func_8080200C_chinflatableboss();

void func_80801B04_chinflatableboss();

void func_808004A0_chinflatableboss(param_0) u8 *param_0;
{
    u8 *local_0;
    u8 *local_3;
    s32 pad2;
    f32 sp30[3];

    local_0 = func_80100094(param_0, 0);
    func_80802058_chinflatableboss(param_0);
    _suexpression_entrypoint_10(func_80100094(param_0, 1), *(s32 *)param_0, 0);
    func_8080272C_chinflatableboss(param_0);
    func_808029AC_chinflatableboss(param_0);
    switch ((u32)*(u16 *)(param_0 + 0x72) >> 10) {
        case 2:
            func_80802264_chinflatableboss(param_0, 0.3f, 0.3f, &D_80802E98_chinflatableboss, 2);
            func_80802264_chinflatableboss(param_0, 0.3f, 0.5f, &D_80802EA0_chinflatableboss, 5);
            if (func_80101DDC(param_0) != 0) {
                _subaddiedialog_entrypoint_11(*(s32 *)param_0, 0x1082, 0x106, param_0 + 4, 0x3A);
                func_80800F84_chinflatableboss(param_0, 3);
                func_8008B1C8(func_80104248(param_0), 0.8f);
            }
            break;
        case 4:
            func_80802264_chinflatableboss(param_0, 0.5f, 0.8f, &D_80802EB4_chinflatableboss, 4);
            if (func_80101E14(param_0, 0x3F000000) != 0) {
                func_800DA544(4);
            }
            if (func_80101DDC(param_0) != 0) {
                local_3 = param_0 + 4;
                if (*(u8 *)(local_0 + 0x49C) != 0) {
                    func_80802910_chinflatableboss(param_0);
                } else {
                    _subaddiedialog_entrypoint_11(*(s32 *)param_0, 0x1083, 0x106, local_3, 0x3A);
                    func_80800F84_chinflatableboss(param_0, 5);
                    func_8008B1C8(func_80104248(param_0), 0.8f);
                }
            }
            break;
        case 9:
            *(f32 *)(param_0 + 0x54) = func_8010CD28(param_0);
            func_80102BF8(param_0, 0.1f, 3.0f, 90.0f);
            if (func_800D9078(param_0 + 0x58) != 0) {
                func_8080183C_chinflatableboss(param_0);
                func_808024BC_chinflatableboss(param_0);
                *(f32 *)(param_0 + 0x54) = func_80102D78(param_0, param_0 + 0x18);
            }
            break;
        case 10:
            *(f32 *)(param_0 + 0x54) = func_8010CD28(param_0);
            func_80102BF8(param_0, 0.1f, 3.0f, 90.0f);
            if (func_80102CF4(param_0, 8.0f) != 0) {
                func_80800F84_chinflatableboss(param_0, 0xB);
            }
            break;
        case 6:
            if (!((BF74 *)(param_0 + 0x74))->b) {
                func_80801B04_chinflatableboss(param_0);
            }
            break;
        case 7:
            if (func_800D9078(param_0 + 0x58) != 0) {
                func_808024BC_chinflatableboss(param_0);
            }
            break;
        case 8:
            if (!((BF74 *)(param_0 + 0x74))->b) {
                func_80801B04_chinflatableboss(param_0);
            }
            break;
        case 11:
            *(f32 *)(param_0 + 0x54) = func_8010CD28(param_0);
            func_80102BF8(param_0, 0.1f, 3.0f, 90.0f);
            if (func_80101E14(param_0, 0x3E99999A) != 0) {
                func_800C4B64(func_800F10B4(*(f32 *)(param_0 + 0x38), 1.4f, 0.19913846f, 0.9f, 1.2f));
                _subaddieaudioquick_entrypoint_2(param_0, local_0 + 0x1C, &D_80802EC4_chinflatableboss);
            } else if (func_80101E14(param_0, 0x3EE66666) != 0) {
                func_80108B04(param_0, 1);
                *(f32 *)(param_0 + 0x58) = 1.0f;
                *(u8 *)(local_0 + 0x495) = *(u8 *)(local_0 + 0x495) - 1;
            } else if (func_80101E14(param_0, 0x3F7FBE77) != 0 && *(u8 *)(local_0 + 0x495) == 0) {
                func_8080183C_chinflatableboss(param_0);
                func_808024BC_chinflatableboss(param_0);
                *(f32 *)(param_0 + 0x54) = func_80102D78(param_0, param_0 + 0x18);
            }
            break;
        case 12:
            if (func_80101E14(param_0, 0x3E800000) != 0) {
                func_800C4B64(func_800F10B4(*(f32 *)(param_0 + 0x38), 1.4f, 0.19913846f, 1.0f, 1.4f) * 0.8f);
                _subaddieaudioquick_entrypoint_2(param_0, local_0 + 0x1C, &D_80802ED0_chinflatableboss);
            }
            if (func_80101DDC(param_0) != 0) {
                func_80800F84_chinflatableboss(param_0, 0xD);
            }
            break;
        case 13:
            func_80802450_chinflatableboss(param_0);
            if (func_80101DDC(param_0) != 0) {
                if (func_80801CB4_chinflatableboss(param_0) == 0) {
                    func_80800F84_chinflatableboss(param_0, 0xE);
                } else {
                    func_808024BC_chinflatableboss(param_0);
                }
            }
            break;
        case 15:
            _subaddieaudioquick_entrypoint_3(param_0, param_0 + 4, &D_80802EDC_chinflatableboss, 0.03f);
            if (func_80101E14(param_0, 0x3D75C28F) != 0) {
                _subaddieskeleton_entrypoint_3(*(s32 *)param_0, 7, sp30);
                *(s32 *)(local_0 + 0x434) = func_8080200C_chinflatableboss(param_0, sp30, local_0 + 0x28);
            }
            if (func_80101E14(param_0, 0x3EDC28F6) != 0) {
                func_800C4AF0(local_0 + 0x34, &D_80802EE8_chinflatableboss);
            }
            if (func_80101DDC(param_0) != 0) {
                func_800FDC28(0);
                func_800DA544(3);
                if (func_800D395C() != 0) {
                    func_80800F84_chinflatableboss(param_0, 0x10);
                    func_80802A9C_chinflatableboss(param_0);
                    _gcfrontend_entrypoint_10();
                } else {
                    func_800DA544(0x9C);
                    func_80108B04(param_0, 3);
                    func_80800F84_chinflatableboss(param_0, 0x10);
                }
            }
            break;
        case 18:
            func_80802264_chinflatableboss(param_0, 0.5f, 0.8f, &D_80802EB4_chinflatableboss, 4);
            if (func_80101DDC(param_0) != 0) {
                func_80800F84_chinflatableboss(param_0, 0x13);
            }
            break;
    }
    func_8080267C_chinflatableboss(param_0);
}

void func_80801DE0_chinflatableboss();

void func_80801D38_chinflatableboss();

s32 func_80801AD8_chinflatableboss();

void func_80801418_chinflatableboss();

void func_80801164_chinflatableboss();

void func_808010BC_chinflatableboss();

/* TU-NOTE: the .bss of this file (formerly asm/data/overlays/ch/inflatableboss.bss.s) is defined here in C, ahead of
 * its first use: IDO places .bss objects used before their definition first, the rest in definition
 * order. */
BalloonEntry B_80803020_chinflatableboss[12];


s32 func_80800A98_chinflatableboss(Actor *param_0, s32 param_1, BalloonArg param_2)
{
    BalloonData *local_0;
    s32 local_1;
    s32 local_2;
    s32 local_3;

    local_0 = func_80100094(param_0, 0);
    switch (param_1) {
    case 0xB:
        switch (param_2.i) {
        case 0x14:
            func_80800F84_chinflatableboss(param_0, 0x11);
            func_80802A00_chinflatableboss(param_0, 0x31, 0x10);
            func_80101180(0x46E, 7, 0);
            return 4;
        case 0x31:
            local_0->unk49D = 0;
            func_800FFAB0(param_0);
        default:
        ret3:
            return 3;
        case 3:
            if (local_0->unk49C) {
                goto ret3;
            }
            func_80802A00_chinflatableboss(param_0, 0xC, 0x20);
            return 4;
        case 0xA:
            local_0->unk49D = 0;
            if (param_0) {} /* PROBE (agV5): load-bearing, removing = 48 */
            return 3;
        case 0xC:
        case 0x19:
        case 0x22:
            local_0->unk49A = 1;
            if (1) {} /* PROBE: load-bearing, removing = 47 */
            return 3;
        case 8:
            func_80108B04(param_0, 2);
            func_80802A00_chinflatableboss(param_0, 0xA, 0x10);
            return 4;
        }
    case 0x2E:
        func_80801958_chinflatableboss(param_0, ((s16 *)&param_2)[0], ((s16 *)&param_2)[1]);
        break;
    case 0x2F:
        func_80801AD8_chinflatableboss(param_0, ((s16 *)&param_2)[0], ((s16 *)&param_2)[1]);
        break;
    case 0x3D:
        switch (param_2.i) {
        case 0:
            func_80801DE0_chinflatableboss(param_0);
            return 1;
        case 1:
            func_80801D38_chinflatableboss(param_0);
            return 1;
        case 2:
            func_80801EA0_chinflatableboss(param_0);
            return 1;
        case 3:
            func_80801F4C_chinflatableboss(param_0);
            return 1;
        }
        break;
    case 0x32:
        if (local_0->unk498 == 2) {
            local_0->unk498 = 3;
            local_0->unk49A = 0;
            func_800F497C(func_800F54E4());
            func_800F49D4(func_800F54E4(), func_8010D5DC, param_0->unk0);
            func_800F4A58(func_800F54E4(), local_0->unk54, 300.0f);
            func_80802A00_chinflatableboss(param_0, 0x19, 0x20);
            _subaddiedialog_entrypoint_11(param_0->unk0, 0x10CC, 0x44, param_0->position, 0x3A);
            func_80101180(0x46E, 8, 0);
            return 1;
        }
        local_0->unk499 = 1;
        func_800F8300(func_800F54E4(), 2, param_0->position);
        break;
    case 0x3F:
        func_808010BC_chinflatableboss(param_0, *(s32 *)&param_2);
        break;
    case 0x40:
        func_80801164_chinflatableboss(param_0, *(s32 *)&param_2);
        break;
    case 6:
        func_80101010(local_0->unk1C);
        break;
    case 0xA:
        local_1 = func_800F54E4();
        param_0->unk64_16 = 1;
        local_0->unk498 = 2;
        func_800F497C(local_1);
        func_800F49A8(local_1, 1);
        func_800F49D4(local_1, func_8010D5DC, param_0->unk0);
        func_800F4A58(local_1, local_0->unk48, 300.0f);
        func_80802A00_chinflatableboss(param_0, 0x2F, 0x20);
        break;
    case 0x95:
        if (local_0->unk496) {
            local_0->unk496 = 0;
            func_800FDC28(1);
        }
        break;
    case 0x96:
        if (!func_800D395C()) {
            return 0;
        }
        _subaddiedialog_entrypoint_11(param_0->unk0, 0xCEB, 0x146, param_0->position, 0x3A);
        break;
    case 0x9F:
        func_800FDC28(0);
        func_80800F84_chinflatableboss(param_0, 5);
        break;
    case 0x1F:
        func_80801418_chinflatableboss(param_0, *(s32 *)&param_2);
        break;
    case 0xA2:
        local_3 = 0;
        local_2 = 0;
        if (!param_0->unk7C_12) {
            return 0;
        }
        for (local_2 = 0; local_2 != 12; local_2++) {
            if (local_0->unk487[local_2] == 1) {
                func_80802590_chinflatableboss(param_0, &B_80803020_chinflatableboss[local_3], local_2 + 3);
                local_3++;
            }
        }
        func_80101074(B_80803020_chinflatableboss);
        return local_3;
    default:
        return 0;
    }
    return 1;
}

void func_80800F84_chinflatableboss(Actor *param_0, s32 param_1)
{
    u8 *local_0;

    local_0 = func_80100094(param_0, 0);
    func_80102424(param_0, param_1);
    switch (param_1) {
        case 11:
            func_8008B1C8(func_80104248(param_0), 0.8f);
            local_0[0x495] = D_80802D8C_chinflatableboss[func_80801C7C_chinflatableboss(param_0)];
            break;
        case 13:
            func_8008B1C8(func_80104248(param_0), 0.8f);
            *(f32 *)(local_0 + 0x44) = param_0->scale;
            break;
        case 14:
            func_80802A00_chinflatableboss(param_0, 0x2B, 0x30);
            _subaddiedialog_entrypoint_11(param_0->unk0, 0x1084, 0x10C, param_0->position, 0x3A);
            func_8010A570(param_0);
            func_8008B1C8(func_80104248(param_0), 0.8f);
            break;
        case 16:
            ((u8 *)param_0)[0x65] &= ~1;
            break;
    }
}

void func_808010BC_chinflatableboss(Actor *param_0, s32 param_1)
{
    u8 *local_0;
    s32 local_1;
    u32 sec;
    s32 idx;
    local_0 = func_80100094(param_0, 0);
    if (!func_800DA298(5)) {
        sec = ((InflatableBossMarker *)param_0->unk0)->section;
        local_1 = sec;
        if (local_1 >= 3 && local_1 < 15) {
            local_1 -= 3;
            idx = 0x487 + local_1;
            if (local_0[idx] != 2) {
            _subaddiedialog_entrypoint_11(param_0->unk0, 0x1086, 0x10E, param_0->position, 0x3A);
            func_800DA544(5);
            param_0->unk74_30 = 1;
            }
        }
    }
}

void func_80801164_chinflatableboss(Actor *param_0, s32 param_1)
{
    u8 *local_0;
    s32 local_6;
    f32 local_2[3];
    f32 local_3[3];
    s32 local_4;
    u32 local_1; /* unused: only holds the stack slot (frame and slots match only with it) */
    s32 local_5;

    local_0 = func_80100094(param_0, 0);
    /* param_1 is dead in the original and serves as the holder for the bitfield; local_6 only after the first range test
       (its own block, otherwise uopt folds -3 and 0x487 together). */
    param_1 = (*(u32 *)((u8 *)param_0->unk0 + 0x18) << 11) >> 28;
    if (param_1 >= 3) {
    local_6 = param_1 - 3;
    if (param_1 < 15 && (local_0 + 0x487)[local_6] != 2) {
        local_4 = func_80802590_chinflatableboss(param_0, local_2, param_1);
        _subaddieaudioquick_entrypoint_2(param_0, local_2, D_80802F08_chinflatableboss);
        func_808012EC_chinflatableboss(param_0, local_2, local_4);
        func_80801904_chinflatableboss(param_0, local_6, local_3);
        *(s32 *)(local_0 + local_6 * 4 + 0x43C) = func_80801FC0_chinflatableboss(param_0, local_2, local_3);
        func_80802AD8_chinflatableboss(param_0, local_6, 2);
        func_80800F84_chinflatableboss(param_0, 12);
        local_5 = func_80104248(param_0);
        func_8008B1C8(local_5, 0.8f);
        local_0[0x493] = 1;
        local_5 = func_80801CB4_chinflatableboss(param_0);
        if (local_5 != 0) {
            if (local_5 == 11) {
                func_800DA544(5);
                _subaddiedialog_entrypoint_11(param_0->unk0, 0x1085, 0x10E, param_0->position, 0x3A);
                func_80802A00_chinflatableboss(param_0, 0x2D, 0x20);
                param_0->unk74_30 = 1;
            }
        } else {
            func_800DA544(0);
            func_80802A00_chinflatableboss(param_0, 0x29, 0x30);
        }
    }
    }
}

void func_808012EC_chinflatableboss(param_0, param_1, param_2) Actor *param_0; f32 *param_1; s32 param_2;
{
    f32 local_0[2][3];
    s32 local_2;

    func_80801904_chinflatableboss((s32)param_0, ((*(u32 *)((u8 *)param_0->unk0 + 0x18) << 11) >> 28) - 3, (s32)local_0[0]);
    func_800EFB24(local_0[1], param_1, local_0[0]);
    func_800EF368(local_0[1], param_2 * 0.5f);
    func_800EF04C(local_0[1], param_1);
    local_2 = func_800BABB8(0, param_1, local_0[1], param_0->scale, D_80802F2C_chinflatableboss);
    func_800BA714(local_2, (s16)(s32)(param_2 * 0.4f), (s16)(s32)(param_2 * 0.6f));
    func_800BA670(local_2, D_80802F0E_chinflatableboss[(*(u32 *)((u8 *)param_0->unk0 + 0x18) << 11) >> 28]);
    func_800BA22C(local_2, 8);
}

void func_80801418_chinflatableboss(Actor *param_0, void *param_1)
{
    u8 *local_0;
    u8 *local_1;
    s32 local_2;

    local_0 = func_80100094(param_0, 0);
    func_80103D48(param_0);
    _suexpression_entrypoint_19(func_80100094(param_0, 1), param_0);
    if (!param_0->unk64_20) func_8080267C_chinflatableboss(param_0);
    func_800DF72C(func_801040A8(param_0));
    func_800DF830(1);
    func_800DF738(func_80104130());
    func_800DF818(func_80103CDC(param_0, param_1));
    func_800DF660(2, (u32)((u8 *)param_0)[0x7B] >> 6, 0, _subaddiefade_entrypoint_0(param_0));
    func_800DF720(func_80100AC4(*(s16 *)((u8 *)param_0 + 0x60)));
    func_80101934(param_0);
    func_80103D70(param_0);
    for (local_2 = 0, local_1 = local_0; local_2 < 0xF; local_2++, local_1++) {
        func_800DF744(local_2 + 3, local_1[0x478]);
    }
    param_0->unk7C_12 = 1;
    param_0->unk64_20 = 0;
}

void func_80801554_chinflatableboss(param_0, param_1) Actor *param_0; s32 param_1;
{
    u8 *local_0;
    s32 local_10 = 0;
    void *local_1;
    void *local_2;
    f32 local_3[3];
    f32 local_4[3];
    void *local_5;
    void *local_6;

    local_0 = func_80100094(param_0, 0);
    local_1 = func_80101808(param_0, func_801017D0);
    if (param_0->unk7C_12) {
        local_2 = func_80104130();
        func_800DBEFC(local_2, 4, (f32 *)(local_0 + 0x1C));
        func_800DBEFC(local_2, 5, (f32 *)(local_0 + 0x28));
        func_800DBEFC(local_2, 6, (f32 *)(local_0 + 0x34));
    }
    if (local_1 && (s32)param_0->unk70_10 < 16) {
        local_5 = func_800B27E0(local_1);
        local_6 = func_800D674C(0x637);
        func_800EFD24(local_3);
        if (func_800AE630(func_801040A8(param_0), (u8 *)local_5, 12, local_4)) {
            func_800EF334(local_4, *(f32 *)&param_0->actorData[4]);
            func_800EF5A0(local_4, param_0->rotation, local_4[0], local_4[1], local_4[2]);
            func_800EF04C(local_4, param_0->position);
            local_4[1] = param_0->position[1];
            func_800DF410(_subaddiefade_entrypoint_0(param_0));
            func_800DF830(3);
            func_800DE448(local_4, local_3, *(f32 *)&param_0->actorData[4] * 9.0f, 0, (s32)local_6);
        }
        if (func_800AE630(func_801040A8(param_0), (u8 *)local_5, 26, local_4)) {
            func_800EF334(local_4, *(f32 *)&param_0->actorData[4]);
            func_800EF5A0(local_4, param_0->rotation, local_4[0], local_4[1], local_4[2]);
            func_800EF04C(local_4, param_0->position);
            local_4[1] = param_0->position[1];
            func_800DF410(_subaddiefade_entrypoint_0(param_0));
            func_800DF830(3);
            func_800DE448(local_4, local_3, *(f32 *)&param_0->actorData[4] * 9.0f, 0, (s32)local_6);
        }
        func_800DF410(_subaddiefade_entrypoint_0(param_0));
        func_800DF830(3);
        func_800DE448(param_0->position, local_3, *(f32 *)&param_0->actorData[4] * 1.4f * 9.0f, 0, (s32)local_6);
    }
    for (local_10 = 0; local_10 < 12; local_10++) {
        if (((s32 *)(local_0 + 0x43C))[local_10]) {
            func_800BC358(((s32 *)(local_0 + 0x43C))[local_10], param_1, 0);
        }
    }
    if (*(s32 *)(local_0 + 0x434)) {
        func_800BC358(*(s32 *)(local_0 + 0x434), param_1, 0);
    }
}

void func_8080183C_chinflatableboss(Actor *param_0)
{
    InflatableBossDestination *local_1;
    s16 local_0[2];

    local_1 = func_80100094(param_0, 0);
    local_1->local_2 ^= 1;
    _subaddieDll_entrypoint_12(local_1->local_2 ? local_1->local_0 : local_1->local_0 + 8, local_0);
    local_1->local_1[0] = local_0[0];
    local_1->local_1[1] = param_0->position[1];
    local_1->local_1[2] = local_0[1];
    *(f32 *)&param_0->actorData[0] = func_800DC178(0.0f, 1000.0f);
    *(f32 *)&param_0->actorData[1] = param_0->position[1];
    *(f32 *)&param_0->actorData[2] = func_800DC178(0.0f, 1000.0f);
    local_1->local_3 = 1;
}

int func_80801904_chinflatableboss(param_0, param_1, param_2) s32 param_0; s32 param_1; s32 param_2;
{
  s32 local_0;
  local_0 = func_80100094(param_0, 0);
  if (param_1 >= 3 && param_1 < 6)
  {
    local_0 += 0x34;
  }
  else
  {
    local_0 += 0x28;
  }
  func_800EE7F8(param_2, local_0);
}

void func_80801958_chinflatableboss(param_0, param_1, param_2) Actor *param_0; s32 param_1; s32 param_2;
{
    switch (param_1) {
        case 0x10CC: return;
        case 0x1082: _chintrotext_entrypoint_1(0x18B9, 3, 1, 0);
        case 0x1087:
            func_80800F84_chinflatableboss(param_0, 4);
            func_8008B1C8(func_80104248(param_0), 0.8f);
            func_80802A00_chinflatableboss(param_0, 3, 0x20);
            break;
        case 0x1083: func_80802910_chinflatableboss(param_0); break;
        case 0x1085:
        case 0x1086: *((u8 *)param_0 + 0x74) &= 0xFFBF; break;
        case 0x1084:
            func_801020DC(param_0, 0);
            func_80102FDC(param_0, param_0->scale * 4.0f);
            func_80800F84_chinflatableboss(param_0, 15);
            func_8080267C_chinflatableboss(param_0);
            func_80802A00_chinflatableboss(param_0, 11, 0x38);
            break;
        case 0xCEB:
        if (param_2 > 0) _gcfrontend_entrypoint_11();
        else _gcfrontend_entrypoint_10();
        break;
    }
    func_8008B1C8(func_80104248(param_0), 0.8f);
}

s32 func_80801AD8_chinflatableboss(s32 param_0, s32 param_1, s32 param_2){
    if(param_1 == 0x1085){
        func_80108B04(param_0, 0);
    }
}

void func_80801B04_chinflatableboss(Actor *param_0)
{
    u8 *local_0;
    local_0 = func_80100094(param_0, 0);
    *(f32 *)((u8 *)param_0 + 0x54) = func_80102D78(param_0, (f32 *)param_0->actorData);
    *(f32 *)((u8 *)param_0 + 0x24) = func_800F15F8(*(f32 *)((u8 *)param_0 + 0x24), *(f32 *)(local_0 + 0x40), func_800D8FF8() * 200.0f);
    func_80102BF8(param_0, 0.1f, 3.0f, 60.0f);
    func_8010C3A8(param_0, 5, func_800F3780(func_80101F24(param_0), &D_80802F68_chinflatableboss, 5));
    if (func_800F0064((f32 *)param_0->actorData, 400.0f, param_0->position)) {
        if (local_0[0x497]) {
            func_80800F84_chinflatableboss(param_0, 7);
            func_800EE7F8((f32 *)param_0->actorData, local_0 + 0x10);
            local_0[0x497] = 0;
            *(f32 *)((u8 *)param_0 + 0x58) = func_800DC178(4.0f, 6.0f);
        } else if (local_0[0x493] == 0) {
            func_80800F84_chinflatableboss(param_0, 9);
            *(f32 *)((u8 *)param_0 + 0x58) = func_800DC178(6.0f, 8.0f);
        } else func_80800F84_chinflatableboss(param_0, 10);
        func_8008B1C8(func_80104248(param_0), 0.8f);
    }
}

s32 func_80801C7C_chinflatableboss() {
    return (s32) (0xC - func_80801CB4_chinflatableboss()) / 2;
}

s32 func_80801CB4_chinflatableboss(param_0) Actor *param_0;
{
    u8 *local_0;
    s32 local_1;
    s32 local_2;

    local_0 = func_80100094(param_0, 0);
    local_1 = 12;
    for (local_2 = 0; local_2 < 12; local_2++) {
        if (local_0[local_2 + 0x487] == 2) {
            local_1--;
        }
    }
    return local_1;
}

void func_80801D38_chinflatableboss(Actor *param_0)
{
    f32 *local_0;
    Actor *local_1;
    s32 local_2;
    local_0 = func_80100094(param_0, 0);
    local_2 = func_80801C7C_chinflatableboss(param_0);
    local_1 = func_80108528(0x13D, &local_0[7], 0, &param_0);
    func_80102FDC(local_1, param_0->scale);
    local_1->unk3C = param_0->unk0;
    local_1->unk6C_0 = func_80801CB4_chinflatableboss(param_0);
    local_1->unk58 = D_80802D98_chinflatableboss[local_2];
}

void func_80801DE0_chinflatableboss(Actor *param_0)
{
    InflatableSpawnAnchor *local_0;

    local_0 = func_80100094(param_0, 0);
    _chappearfx_entrypoint_1(func_80108528(0x13E, local_0->local_0, (s32)local_0->local_1, &param_0),
                           0x22, 0, 1.0f);
    func_80108528(0x36E, local_0->local_0, (s32)local_0->local_1, &param_0);
    if (!func_800DA298(0x6AC)) {
        func_800DA544(0x6AC);
        func_80802A00_chinflatableboss(param_0, 8, 0x30);
    } else {
        func_80802A9C_chinflatableboss(param_0);
        func_80801EA0_chinflatableboss(param_0);
    }
}

void func_80801EA0_chinflatableboss(param_0) Actor *param_0;
{
    InflatableBossSpawnList *local_0;
    s32 local_1;

    local_0 = func_80100094(param_0, 0);
    for (local_1 = 0; local_1 < local_0->count; local_1++) {
        _chappearfx_entrypoint_2(func_80108474(0x234, local_0->spawns[local_1].position,
            (s32)local_0->spawns[local_1].yaw), 0x20, 2, 1.0f);
    }
}

void func_80801F4C_chinflatableboss(param_0) Actor *param_0;
{
    f32 local_0[3];
    s32 local_1;
    Unk80132ED0 *local_2;

    local_2 = param_0->unk0;
    func_800EE7F8(local_0, param_0->position);
    local_0[1] = 5000.0f;
    local_1 = func_800D10D4(0x17, 1, local_0, 0, 0);
    func_80802A2C_chinflatableboss(func_80106790(local_2), local_1, 0x14, 0x438);
}

int func_80801FC0_chinflatableboss(param_0, param_1, param_2) u8 *param_0; s32 param_1; s32 param_2; {
    func_800BABB8(0, param_1, param_2, *(f32 *)(param_0 + 0x38) * 0.75f, &D_80802F90_chinflatableboss);
}

int func_8080200C_chinflatableboss(u8 *param_0, s32 param_1, s32 param_2) {
    func_800BABB8(0, param_1, param_2, *(f32 *)(param_0 + 0x38) * 0.75f, &D_80802FC4_chinflatableboss);
}

void func_80802058_chinflatableboss(param_0) Actor *param_0;
{
    u8 *local_5;
    u8 *local_4;
    s32 local_6;
    s32 local_7;
    f32 local_0[3];
    f32 local_1[3];
    f32 local_2[3];
    s32 *local_3;
    s32 local_8;

    local_5 = func_80100094(param_0, 0);
    local_3 = (s32 *)(local_5 + 0x43C);
    local_4 = local_5 + 0x46C;
    local_6 = 0;
    do {
        local_7 = local_6 + 3;
        if (*local_3 || *local_4) {
            func_80801904_chinflatableboss(param_0, local_7, local_1);
            func_80802590_chinflatableboss(param_0, local_0, local_7);
            local_8 = *local_3 != 0;
            if (local_8) {
                local_8 = func_800BA198(*local_3) >= 8;
            }
            *local_4 = _subaddieaudioloop_entrypoint_7(*local_4, local_0, local_8,
                &D_80802FF8_chinflatableboss, *(u32 *)((u8 *)param_0 + 0x70) & 1);
            if (*local_3) {
                func_800BBD18(*local_3, local_0, local_1, param_0->scale, 0);
                if (func_800BA28C(*local_3)) {
                    ((s32 *)(local_5 + 0x43C))[local_6] = func_800BA2C4(*local_3);
                }
            }
        }
        local_6++;
        local_3++;
        local_4++;
    } while (local_6 != 12);
    if (*(s32 *)(local_5 + 0x434) || local_5[0x438]) {
        _subaddieskeleton_entrypoint_3(param_0->unk0, 7, local_2);
        local_8 = *(s32 *)(local_5 + 0x434) != 0;
        if (local_8) {
            local_8 = func_80101F24(param_0) < 0.43f;
        }
        local_5[0x438] = _subaddieaudioloop_entrypoint_7(local_5[0x438], local_2, local_8,
            &D_80802FF8_chinflatableboss, *(u32 *)((u8 *)param_0 + 0x70) & 1);
        if (*(s32 *)(local_5 + 0x434)) {
            func_800BBD18(*(s32 *)(local_5 + 0x434), local_2, (f32 *)(local_5 + 0x28), param_0->scale, 0);
            if (func_800BA28C(*(s32 *)(local_5 + 0x434))) {
                *(s32 *)(local_5 + 0x434) = func_800BA2C4(*(s32 *)(local_5 + 0x434));
            }
        }
    }
}

void func_80802264_chinflatableboss(Actor *param_0, f32 param_1, f32 param_2, s32 *param_3, s16 param_4)
{
    s32 local_0;
    f32 local_1;
    u8 local_2;
    for (local_0 = 0; local_0 < param_4; local_0++) {
        if (func_80101E14(param_0, param_3[local_0])) {
            local_1 = func_800F10B4((f32)local_0, 0.0f, (f32)param_4, param_1, param_2);
            local_2 = _subaddieaudioquick_entrypoint_1(param_0, param_0->position);
            func_800C3868(local_2, 0.15f, 0.25f, local_1, local_1 + 0.12f);
            func_800C4350(local_2, param_0->position, D_80803008_chinflatableboss);
        }
    }
}

f32 func_808023B0_chinflatableboss(param_0) Actor *param_0;
{
    InflatablePartStates *local_0;
    f32 local_1;
    s32 local_2;
    local_0 = func_80100094(param_0, 0);
    local_1 = 1.4f;
    for (local_2 = 0; local_2 < 12; local_2++) {
        if (local_0->states[local_2] == 2) local_1 *= 0.85f;
    }
    return local_1;
}

void func_80802450_chinflatableboss(Actor *param_0)
{
    f32 *local_1;
    f32 local_0;
    local_1 = func_80100094(param_0, 0);
    local_0 = local_1[0x11] - func_808023B0_chinflatableboss(param_0);
    func_80102FDC(param_0, local_1[0x11] - local_0 * func_80101F24(param_0));
}

void func_808024BC_chinflatableboss(Actor *param_0)
{
    InflatableBossAttackDuration *local_0;
    f32 local_1;

    local_0 = func_80100094(param_0, 0);
    local_0->local_0 = D_80802D80_chinflatableboss[func_80801C7C_chinflatableboss(param_0)];
    ((f32 *)param_0->actorData)[3] = 0.0f;
    func_80800F84_chinflatableboss(param_0, local_0->local_1 ? 6 : 8);
    local_1 = ((f32)D_80802D80_chinflatableboss[0] / local_0->local_0) * 5.0f;
    func_80101CDC(param_0, local_1);
    func_8008B1C8(func_80104248(param_0), 0.8f);
}

s32 func_80802590_chinflatableboss(param_0, param_1, param_2) Actor *param_0; f32 *param_1; s32 param_2;
{
    f32 local_0[3];
    f32 local_1;
    s32 local_2;

    if (!func_800AE0B8(func_801040A8(param_0))) {
        func_800EE7F8(param_1, param_0->position);
        return 0;
    }
    local_2 = func_801039E4(param_0->unk0);
    func_800EFA4C(local_0, 0.0f, param_0->rotation[1], 0.0f);
    if (!func_800B0D80(func_800B2824(local_2), param_2, param_0->position, local_0, param_0->scale, 0, func_801040A8(param_0), param_1, &local_1)) {
        func_800EE7F8(param_1, param_0->position);
        return 0;
    }
    return (s32)local_1;
}

void func_8080267C_chinflatableboss(param_0) Actor *param_0;
{
    s32 local_3;
    s32 local_4;
    s32 local_0;
    f32 local_1[3];
    s32 local_2;

    local_0 = func_80104248(param_0);
    if (param_0->unk64_16) {
        local_4 = func_801039E4(param_0->unk0);
        local_2 = func_800B27E0(local_4);
        func_8008B304(local_0);
        func_8008C200(*(s16 *)&param_0->unk0->unk10, local_2, func_8008AEDC(local_0));
        local_3 = func_8008C27C(func_8008AEDC(local_0));
        func_800DFBE0(local_3, 3, local_1);
        ((f32 *)param_0->actorData)[4] = local_1[0] * param_0->scale;
        param_0->unk64_20 = 1;
    }
}

s32 func_8080272C_chinflatableboss(Actor *param_0)
{
    u8 *local_0;

    local_0 = func_80100094(param_0, 0);
    switch (local_0[0x498]) {
        case 1:
        case 6:
            break;
        case 3:
            if (local_0[0x49A] && local_0[0x499]) {
                if (!local_0[0x49B]) {
                    func_800DA544(2);
                    func_80800F84_chinflatableboss(param_0, 2);
                    func_8008B1C8(func_80104248(param_0), 0.8f);
                    func_8010A85C(param_0, 1);
                    func_80802A00_chinflatableboss(param_0, 1, 0x20);
                    local_0[0x49B] = 1;
                    func_800FDC28(1);
                }
                if (param_0->unk70_10 == 4) {
                    local_0[0x49A] = local_0[0x499] = 0;
                    func_800F82D4(func_800F54E4(), 0);
                    func_800F497C(func_800F54E4());
                    func_800F49D4(func_800F54E4(), func_8010D5DC, param_0->unk0);
                    func_800F4A58(func_800F54E4(), (f32 *)(local_0 + 0x60), 400.0f);
                    local_0[0x498] = 4;
                }
            }
            break;
        case 5:
            if (param_0->unk70_10 == 4) {
                local_0[0x49A] = 0;
                local_0[0x499] = 1;
                func_800F82D4(func_800F54E4(), 0);
                func_800F497C(func_800F54E4());
                func_800F49D4(func_800F54E4(), func_8010D5DC, param_0->unk0);
                func_800F4A58(func_800F54E4(), (f32 *)(local_0 + 0x60), 400.0f);
                local_0[0x498] = 4;
            }
            break;
    }
    return 0;
}

void func_80802910_chinflatableboss(Actor *param_0)
{
    u8 *local_0;

    local_0 = func_80100094(param_0, 0);
    func_800FDC28(4);
    func_80802A9C_chinflatableboss(param_0);
    func_800A51C0();
    func_808024BC_chinflatableboss(param_0);
    func_800DA544(1);
    func_800DA544(0x17F);
    _gcfrontend_entrypoint_9(0x25);
    func_800F82D4(func_800F54E4(), 0);
    local_0[0x498] = 6;
    func_8010A590(param_0);
    func_80109FE8(param_0, 1);
}

int func_808029AC_chinflatableboss(s32 param_0)
{
  if (func_800DA298(1) != 0 && func_800DA298(3) == 0)
  {
    func_800D2498(0xEC, func_80801CB4_chinflatableboss(param_0), 0);
  }
}

void func_80802A00_chinflatableboss(param_0, param_1, param_2) s32 *param_0; s32 param_1; s32 param_2; {
    func_80802A2C_chinflatableboss(param_0, *param_0, param_1, param_2);
}

int func_80802A2C_chinflatableboss(param_0, param_1, param_2, param_3) s32 param_0[3]; s32 param_1; s32 param_2; s32 param_3;
{
  u8 *local_0;
  local_0 = func_80100094(param_0, 0);
  if (local_0[0x49D])
  {
    param_3 |= 0x2000;
    _capod_entrypoint_14();
  }
  _capod_entrypoint_13(param_1, *param_0, param_2, param_3);
  local_0[0x49D] = 1;
}

void func_80802A9C_chinflatableboss(param_0) s32 param_0; {
    u8 *sp1C;

    sp1C = func_80100094(param_0, 0);
    if (sp1C[0x49d] != 0) {
        _capod_entrypoint_14();
        sp1C[0x49d] = 0;
    }
}

void func_80802AD8_chinflatableboss(param_0, param_1, param_2) Actor *param_0; s32 param_1; s32 param_2;
{
    u8 *local_0;

    local_0 = func_80100094(param_0, 0);
    local_0[0x487 + param_1] = param_2;
    if (param_1 >= 9) {
        param_1 = param_1 + param_1 - 9;
        local_0[0x478 + param_1] = param_2;
        local_0[0x479 + param_1] = param_2;
    } else {
        local_0[0x478 + param_1] = param_2;
    }
}

/* TU-NOTE: the .data of this overlay (formerly asm/data/overlays/ch/inflatableboss.data.s) is defined here in C.
 * Its tables hold pointers to functions of this file; IDO's assembler schedules some of these
 * functions differently unless the tables are defined in the same unit. Values are taken from the ROM.
 * Labels inside an object are linker symbols in undefined_syms.us.txt: D_80802F0E_chinflatableboss = D_80802F08_chinflatableboss + 0x6
 * extern declarations adjusted to the object (same addresses): D_80802E98_chinflatableboss -> s32[], D_80802EA0_chinflatableboss -> s32[], D_80802EB4_chinflatableboss -> s32[], D_80802EC4_chinflatableboss -> s32[], D_80802ED0_chinflatableboss -> s32[], D_80802EDC_chinflatableboss -> s32[], D_80802EE8_chinflatableboss -> s32[], D_80802F90_chinflatableboss -> s32[], D_80802FC4_chinflatableboss -> s32[], D_80802FF8_chinflatableboss -> s32[] */
s16 D_80802D80_chinflatableboss[6] = { 0x190, 0x1F4, 0x258, 0x2BC, 0x320, 0x384 };
s16 D_80802D8C_chinflatableboss[6] = { 0x1, 0x1, 0x2, 0x2, 0x3, 0x3 };
f32 D_80802D98_chinflatableboss[6] = { 3.0f, 2.8f, 2.6f, 2.4f, 2.2f, 2.0f };
u8 D_80802DB0_chinflatableboss[160] = { 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x41, 0x10, 0x0, 0x0, 0x2, 0x4, 0x0, 0x44, 0x41, 0x10, 0x0, 0x0, 0x2, 0x4, 0x0, 0x2, 0x40, 0x90, 0x0, 0x0, 0x2, 0x8, 0x0, 0x1, 0x40, 0xF0, 0x0, 0x0, 0x2, 0x5, 0x0, 0x2, 0x40, 0x90, 0x0, 0x0, 0x2, 0x2, 0x0, 0x1, 0x40, 0xA0, 0x0, 0x0, 0x2, 0x3, 0x0, 0x1, 0x40, 0x90, 0x0, 0x0, 0x2, 0x2, 0x0, 0x1, 0x40, 0xA0, 0x0, 0x0, 0x2, 0x3, 0x0, 0x1, 0x40, 0x90, 0x0, 0x0, 0x2, 0x2, 0x0, 0x1, 0x40, 0x90, 0x0, 0x0, 0x2, 0x2, 0x0, 0x1, 0x3F, 0xE6, 0x66, 0x66, 0x2, 0x9, 0x0, 0x1, 0x40, 0x0, 0x0, 0x0, 0x2, 0x6, 0x0, 0x2, 0x40, 0x40, 0x0, 0x0, 0x2, 0x2, 0x0, 0x2, 0x40, 0x90, 0x0, 0x0, 0x2, 0x2, 0x0, 0x1, 0x40, 0xCC, 0xCC, 0xCD, 0x2, 0xA, 0x0, 0x2, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x40, 0xF0, 0x0, 0x0, 0x2, 0x5, 0x0, 0x2, 0x40, 0x90, 0x0, 0x0, 0x2, 0x2, 0x0, 0x1 };
void *D_80802E50_chinflatableboss = (void *)0x018E013C;
static u32 D_80802E50_chinflatableboss_rest[17] = { 0x7940001, (u32)&D_80802DB0_chinflatableboss, (u32)func_808004A0_chinflatableboss, (u32)func_80105834, (u32)func_80801554_chinflatableboss, 0x0, 0x0, 0x0, 0x3000042A, (u32)func_80800408_chinflatableboss, (u32)func_80108ED0, 0x4A00000, (u32)func_8080000C_chinflatableboss, (u32)func_80107C2C, 0x80200402, (u32)func_80800A98_chinflatableboss, 0x0 };
s32 D_80802E98_chinflatableboss[2] = { 0x3D4CCCCD, 0x3E6147AE };
s32 D_80802EA0_chinflatableboss[5] = { 0x3EB33333, 0x3EDC28F6, 0x3F0CCCCD, 0x3F23D70A, 0x3F3D70A4 };
s32 D_80802EB4_chinflatableboss[4] = { 0x3C23D70A, 0x3E19999A, 0x3ECCCCCD, 0x3F333333 };
s32 D_80802EC4_chinflatableboss[3] = { 0x1304FF, 0x18001D, 0x20000 };
s32 D_80802ED0_chinflatableboss[3] = { 0x1304FE, 0x18001D, 0x20000 };
s32 D_80802EDC_chinflatableboss[3] = { 0x1304B1, 0x180002, 0x0 };
s32 D_80802EE8_chinflatableboss[8] = { 0x1304FD, 0x176D60, 0x7D0001F4, 0x150000, 0x33300A3, 0xE0100, 0x14C0180, 0x20000 };
u8 D_80802F08_chinflatableboss[36] = { 0x0, 0x13, 0x4, 0xFB, 0x0, 0x18, 0x0, 0x2, 0x0, 0x0, 0x0, 0x0, 0x7, 0x9A, 0x7, 0x98, 0x7, 0x99, 0x7, 0x98, 0x7, 0x97, 0x7, 0x97, 0x7, 0x99, 0x7, 0x97, 0x7, 0x97, 0x7, 0x98, 0x7, 0x99, 0x7, 0x9A };
s32 D_80802F2C_chinflatableboss[15] = { 0x1130810, 0x2200C0, 0xD90073, 0x8C0015, 0x99, 0x27FE0C, -0x1F3FE0C, 0x1F4002D, 0x6A40898, 0x1BFC18, -0x4AFFFFB, 0x16, 0x204002B, 0x4000500, 0x0 };
u8 D_80802F68_chinflatableboss[40] = { 0x0, 0x0, 0x0, 0x0, 0x3F, 0x19, 0x99, 0x9A, 0x3E, 0x80, 0x0, 0x0, 0x3F, 0x80, 0x0, 0x0, 0x3F, 0x0, 0x0, 0x0, 0x3F, 0x19, 0x99, 0x9A, 0x3F, 0x40, 0x0, 0x0, 0x3F, 0x80, 0x0, 0x0, 0x3F, 0x80, 0x0, 0x0, 0x3F, 0x19, 0x99, 0x9A };
s32 D_80802F90_chinflatableboss[13] = { 0x1130A1C, 0x1D09DD, 0x160200, 0x2D05DC, 0x7080022, 0x2800300, 0x7000880, 0x150000, 0x99002A, 0x0, 0xCC00E6, 0x280500, 0x0 };
s32 D_80802FC4_chinflatableboss[13] = { 0x113141C, 0x1D09DD, 0x160200, 0x2D04B0, 0x5DC0022, 0x1800200, 0x4000500, 0x150000, 0x99002A, 0x0, 0x660080, 0x28051E, 0x0 };
s32 D_80802FF8_chinflatableboss[4] = { 0x1304DC, 0x18000D, 0x1190133, 0x20000 };
u8 D_80803008_chinflatableboss[24] = { 0x0, 0xF, 0x0, 0x13, 0x4, 0xFA, 0x0, 0x18, 0x0, 0x2, 0x0, 0x11, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0 };
