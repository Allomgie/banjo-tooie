#include "common.h"

extern void *func_800F5EF8(void *);
extern void *func_80100094(Actor *, u32);
typedef struct {
    u8 unk0[3][4];
    s32 unkC;
    s32 unk10;
    u8 pad14[0xC];
    s32 unk20;
    u8 pad24[0x31];
    u8 unk55;
    u8 pad56[2];
    u8 unk58;
    u8 unk59;
    u8 pad5A[2];
    u8 unk5C;
    u8 unk5D;
    u8 unk5E;
    u8 unk5F;
    u8 unk60;
} DragonData_80800070_chdragonbrothers;
typedef struct {
    u8 pad0[0x16];
    u16 unk16;
} DragonModel;
extern f32 D_80805570_chdragonbrothers[];
extern s32 _glcutDll_entrypoint_20(void);
extern s32 func_800EA05C(void);
extern void func_801032B0(Actor *, s32, s32);
extern s32 func_800DA298(s32);
extern void func_800D1000(s32, s32, f32 *, s32, Unk80132ED0 *);
extern void _chintrotext_entrypoint_2(s32);
extern void func_800FFAB0(Actor *);
extern s32 func_800D395C(void);
extern void _suexpression_entrypoint_7(Actor *, s32, s16);
extern f32 func_800F1DCC(f32, f32);
extern f32 func_800EF030(f32 *);
extern f32 func_800F10B4(f32, f32, f32, f32, f32);
typedef struct {
    u8 pad_0[0x20];
    s32 local_0;
    f32 local_1[3];
    f32 local_2[3];
    f32 local_3;
    f32 local_4;
    f32 local_5;
    f32 local_6;
    u8 pad_1[9];
    u8 local_7;
} DragonBrotherCamera;
extern f32 D_8080557C_chdragonbrothers[3];
extern f32 func_800F1DF4(f32 *, f32 *);
typedef struct {
    u8 unused0[0x20];
    void *player;
    u8 unused24[0x3B];
    u8 active;
} DragonCameraState;
extern void func_80090734(s32, s32);
extern void func_80090708(s32);
extern f32 func_800F2094(f32, f32);
typedef struct {
    u8 pad_0[0x18];
    f32 local_0;
    f32 local_1;
} DragonYaw1482;
extern s32 func_80090248(void);
extern s32 func_8008FA2C(s32, s32);
extern int D_808056A8_chdragonbrothers[];
extern Actor *_subaddiefind_entrypoint_2(s32, s32 *);
extern void func_800EFCD8(f32 *, f32, f32);
typedef struct {
    u8 pad[0x7A];
    u8 p7 : 7;
    u8 b0 : 1;
} B7A;
typedef struct {
    u8 pad[4];
    u8 a[4];
    s8 b[4];
} DrbS;
extern Actor *func_80106790(Unk80132ED0 *);
extern u8 D_8080543C_chdragonbrothers[];
extern int D_8080574C_chdragonbrothers[];
typedef union {
    s32 local_0;
    Unk80132ED0 *local_1;
} DragonMessage1804;
extern u8 D_80805870_chdragonbrothers[];
extern u8 D_80805840_chdragonbrothers[];
extern void _chexploder_entrypoint_15(Actor *, s32, f32);
extern void func_800BBCB8(f32 *, s32, f32, s32, void *);
extern void *D_808058A8_chdragonbrothers;
typedef struct {
    u8 pad_0[0x28];
    u32 pad_1 : 21;
    u32 local_0 : 1;
    u32 pad_2 : 10;
} DragonMarker1864;
extern s16 D_808058F0_chdragonbrothers[];
extern void func_800EEBF0(f32 *, f32 *, f32);
extern f32 func_800DC178(f32, f32);
typedef struct {
    u8 pad_0[4];
    f32 local_0;
    u8 pad_1[4];
    s32 local_1;
} DragonFrameState;
typedef struct {
    u8 pad_0[10];
    u8 local_0 : 5;
    u8 pad_1 : 3;
} DragonFrameModel;
extern f32 func_800D8FF8(void);
extern f32 func_800F13C4(f32, f32);
extern int D_80805918_chdragonbrothers[];
extern int D_80805960_chdragonbrothers[];
extern int D_808059A8_chdragonbrothers[];
extern int D_808059D8_chdragonbrothers[];
extern void func_800EFA20(f32 *, f32 *, f32);
extern u8 D_808059EC_chdragonbrothers[];
extern s32 D_80805A08_chdragonbrothers[];
extern s32 D_80805A50_chdragonbrothers[];
extern int D_80805488_chdragonbrothers[];
extern int D_80805A5C_chdragonbrothers[];
extern void func_800EF334(f32 *, f32);
extern void func_800EEC30(f32 *, f32, f32, f32);
extern void func_800C3FC0(s32, f32, s32);
extern u8 D_80805588_chdragonbrothers[];
extern u8 D_808055C0_chdragonbrothers[];
extern u8 D_808055DC_chdragonbrothers[];
extern f32 func_80101F24(Actor *);
extern void _subaddieskeleton_entrypoint_2(Unk80132ED0 *, s32, f32 *);
typedef struct {
    u8 pad0[0x10];
    s32 unk10;
    u8 pad14[0xC];
    s32 unk20;
    u8 pad24[0x34];
    u8 unk58;
    u8 pad59[2];
    u8 unk5B;
} DragonData_80800D98_chdragonbrothers;
extern s32 _plsu_entrypoint_1(s32);
extern void _gcfrontend_entrypoint_9(s32);
extern s32 func_800DA9E4(s32, s32);
extern void func_800DA544(s32);
extern void func_800DA524(s32);
extern void func_800FDC28(s32);
typedef struct {
    u8 pad0[0x18];
    f32 unk18;
    u8 pad1C[0x38];
    u8 unk54;
    u8 pad55[4];
    u8 unk59;
    u8 unk5A;
    u8 unk5B;
    u8 pad5C;
    u8 unk5D;
    u8 unk5E;
} DragonData_808012B4_chdragonbrothers;
extern u32 D_80805558_chdragonbrothers[];
extern u32 D_808053B0_chdragonbrothers[];
extern void func_80102424(Actor *, s32);
extern void _chintrotext_entrypoint_1(s32, s32, s32, s32);
extern void func_80101EE4(Actor *, f32);
extern void func_8010A570(Actor *);
extern void func_8010A590(Actor *);
extern Actor *func_80108528(s32, f32 *, s32, Actor **);
extern void func_800EF934(f32 *, f32 *, f32);
extern void func_800EF1B8(f32 *, f32, f32);
extern int func_800DC298(f32);
extern void func_800EEB9C(f32 *, f32, f32);
extern void _gcdialogcamera_entrypoint_3(void *, f32);
typedef struct {
    u8 pad_0[0xC];
    s32 field_C;
    s32 field_10;
    s32 field_14;
    f32 field_18;
    u8 pad_1[4];
    s32 field_20;
    u8 pad_2[0x34];
    u8 field_58;
    u8 field_59;
    u8 field_5A;
    u8 field_5B;
    u8 field_5C;
    u8 field_5D;
    s8 field_5E;
    u8 field_5F;
    s8 field_60;
    u8 field_61;
    u8 field_62;
    u8 field_63;
    u8 field_64;
} DragonUpdateData;
extern void func_800F5A00(s32, f32 *);
extern void func_800F1EA4(f32 *, f32 *);
extern s32 func_80090178(s32);
extern s32 _subaddieaudioquick_entrypoint_3(Actor *, f32 *, void *, f32);
typedef struct {
    u8 pad[0x7C];
    u32 pre : 19;
    u32 f : 1;
    u32 rest : 12;
} W7C;
typedef struct {
    u8 pad[0x79];
    u8 hi : 4;
    u8 lo : 4;
} Nib79;
typedef struct {
    u8 pad[0x76];
    u16 idx : 9;
    u16 rest : 7;
} DbIdx76;
typedef struct {
    u8 pad[0x65];
    u8 b7 : 1;
    u8 b6 : 1;
    u8 b5 : 1;
    u8 b4 : 1;
    u8 b3 : 1;
    u8 b2 : 1;
    u8 b1 : 1;
    u8 b0 : 1;
} BitS101;
extern s32 func_80101DDC(void *);
extern void func_80108B04(void *, s32);
extern void _subaddieaudioloop_entrypoint_4(void *, void *, s32, void *);
extern Vec3f D_80805740_chdragonbrothers;
extern Actor *func_801084B0(s32, Actor **);
extern f32 func_800F1828(f32 *, f32 *);
extern void func_800EE780(void *, void *, void *);
extern s32 func_800C6A7C(void *, void *, void *, s32);
extern void func_800EE7F8(void *, void *);
extern void _chexploder_entrypoint_3(void *, void *, s32);
extern void func_800E1610(s32, f32, f32, void *);
extern void _subaddieaudioquick_entrypoint_2(void *, void *, void *);
extern void _subaddiefade_entrypoint_3(void *);
extern void func_800EF04C(void *, void *);
extern u8 D_80805794_chdragonbrothers[];
extern u8 D_80805448_chdragonbrothers[];
extern u8 D_808057A8_chdragonbrothers[];
extern u8 D_808057E0_chdragonbrothers[];
extern u8 D_80805810_chdragonbrothers[];
extern u8 D_80805460_chdragonbrothers[];
extern u8 D_80805474_chdragonbrothers[];
extern f32 func_800DC0C0(void);
extern s32 _fxegg_entrypoint_1(f32 *, f32);
extern s32 _fxegg_entrypoint_2(f32 *, f32);
extern s32 _fxegg_entrypoint_3(f32 *, f32);
extern s32 _fxegg_entrypoint_5(f32 *, f32 *, f32);
extern s32 _fxegg_entrypoint_6(f32 *, f32, f32 *);
extern u8 D_80805900_chdragonbrothers[];
extern s32 _subaddiecustomhits_entrypoint_2(Unk80132ED0 *, f32 *, f32, f32 *, s32);
extern void func_800EFA4C(f32 *, f32, f32, f32);
void func_808012B4_chdragonbrothers();
extern void func_80105834(), func_80107C2C(), func_80108EE8(), func_80800070_chdragonbrothers(),
    func_80802574_chdragonbrothers(), func_808034DC_chdragonbrothers();

void func_808049D4_chdragonbrothers(u8 *param_0);
extern s32 func_80101E14(Actor *, f32);
extern Vec3f D_80805608_chdragonbrothers;
extern Vec3f D_80805614_chdragonbrothers;
extern u8 D_80805620_chdragonbrothers[];
extern u8 D_80805630_chdragonbrothers[];
extern u8 D_80805640_chdragonbrothers[];
extern u8 D_80805650_chdragonbrothers[];
extern u8 D_8080565C_chdragonbrothers[];
extern u8 D_80805668_chdragonbrothers[];
extern u8 D_808053C8_chdragonbrothers[];
extern u8 D_808053E0_chdragonbrothers[];
extern u8 D_80805678_chdragonbrothers[];
extern u8 D_80805410_chdragonbrothers[];
extern u8 D_80805694_chdragonbrothers[];
extern u8 D_80805424_chdragonbrothers[];
extern u8 D_808053A0_chdragonbrothers[];

void func_80800000_chdragonbrothers(Actor *param_0, s32 param_1)
{
    u8 *local_0;
    s32 local_1;
    local_0 = func_80100094(param_0, 0);
    for (local_1 = 0; local_1 < 4; local_1++) {
        if (local_0[local_1] != 2)
            local_0[local_1] = param_1;
    }
}

void func_80800070_chdragonbrothers(param_0) Actor *param_0;
{
    DragonData_80800070_chdragonbrothers *local_0;
    s32 local_1;

    local_0 = func_80100094(param_0, 0);
    local_1 = _glcutDll_entrypoint_20();
    local_0->unk20 = -1;
    param_0->unk74_7 = param_0->unk74_7 - 0x32;
    if (func_800EA05C() == 0x12B) {
        param_0->unk7A_8 = 0;
    } else {
        param_0->unk7A_8 = 1;
    }
    if (param_0->unk7A_8) {
        func_801032B0(param_0, 0x7FD, ((DragonModel *) param_0->unk0)->unk16);
    }
    local_0->unk0[0][1] = 0;
    local_0->unk0[1][1] = 0;
    local_0->unk0[2][1] = 0;
    local_0->unk0[0][2] = 0;
    local_0->unk0[1][2] = 0;
    local_0->unk0[2][2] = 0;
    local_0->unk0[0][3] = 0;
    local_0->unk0[1][3] = 0;
    local_0->unk0[2][3] = 0;
    local_0->unk0[0][0] = 0;
    local_0->unk0[1][0] = 0;
    local_0->unk0[2][0] = 0;
    local_0->unk5C = 8;
    local_0->unk10 = 4;
    if (!local_1) {
        if (func_800DA298(0x1D5) && func_800DA298(0x1D6)) {
            if ((param_0->unk7A_8 && func_800DA298(0x1D2)) ||
                (!param_0->unk7A_8 && !func_800DA298(0x1D2))) {
                func_800D1000(0x3D, 1, D_80805570_chdragonbrothers, 0, param_0->unk0);
            }
        }
        if ((param_0->unk7A_8 && func_800DA298(0x1D5)) ||
            (!param_0->unk7A_8 && func_800DA298(0x1D6))) {
            _chintrotext_entrypoint_2(1);
            func_800FFAB0(param_0);
            return;
        }
        if (func_800D395C()) {
            if (param_0->unk7A_8) {
                param_0->unk64_19 = 1;
            }
        } else if ((param_0->unk7A_8 && func_800DA298(0x1D6)) ||
                   (!param_0->unk7A_8 && func_800DA298(0x1D5))) {
            param_0->unk64_19 = 1;
        }
    }
    if (param_0->unk64_19) {
        local_0->unkC = 12;
    } else {
        local_0->unkC = 6;
    }
    local_0->unk58 = 0;
    local_0->unk59 = 0;
    local_0->unk5D = 0;
    local_0->unk5E = 0;
    local_0->unk60 = 0;
    local_0->unk5F = 0;
    local_0->unk55 = 0;
    _suexpression_entrypoint_7(param_0, 1, param_0->unk7A_8 ? 0x75 : 0x76);
    if (local_1) {
        func_808012B4_chdragonbrothers(param_0, 1);
        return;
    }
    param_0->unk64_16 = 0;
    if ((param_0->unk7A_8 && func_800DA298(0x1D3)) || (!param_0->unk7A_8 && func_800DA298(0x1D4))) {
        func_808012B4_chdragonbrothers(param_0, 4);
    }
}

void func_808003D8_chdragonbrothers(Actor *arg0)
{
    _suexpression_entrypoint_8(arg0, 1);
}

int func_808003F8_chdragonbrothers(param_0)
Actor *param_0;
{
    switch (param_0->unk70_10) {
        case 7:
        case 8:
        case 9:
        case 10:
        case 11:
        case 12:
        case 13:
            return 1;
    }
    return 0;
}

int func_80800438_chdragonbrothers(Actor *param_0)
{
    void *local_0;
    u8 *new_var;
    local_0 = func_80100094(param_0, 0);
    if (param_0->unk74_29 == 0) {
        return 0;
    } else {
        _ncpod_entrypoint_17(func_800F5EF8(*(s32 *) ((u8 *) local_0 + 0x20)), 0);
        new_var = (u8 *) param_0 + 0x74;
        *new_var &= 0xFFDF;
        return 1;
    }
}

void func_808004A4_chdragonbrothers(Actor *param_0, s32 param_1)
{
    u8 *local_0;
    f32 local_1[3];
    f32 local_2[3];
    f32 local_3[3];

    local_0 = func_80100094(param_0, 0);
    if (param_1) {
        func_800F5A2C(*(s32 *) (local_0 + 0x20), 5, local_3);
        func_800EE7F8(local_1, local_3);
        func_800EF334(local_1, 1.25f);
        local_1[1] += 375.0f;
        func_800A516C(local_2, local_3, local_1);
    } else {
        func_800F5A00(*(s32 *) (local_0 + 0x20), local_1);
        func_800F1EA4(local_1, &local_2[1]);
        local_2[2] = 0.0f;
        local_2[0] = 0.0f;
        func_800EEC30(local_1, 0.0f, local_2[1], 4500.0f);
        local_2[1] = -local_2[1];
    }
    func_800A5240(local_1);
    func_800A526C(local_2);
    func_800A51C0();
    func_800A5240(local_1);
    func_800A526C(local_2);
}

void func_808005A4_chdragonbrothers(param_0, param_1) f32 param_0[3];
s32 param_1;
{
    switch (param_1) {
        case 0:
            param_0[0] = 5500.0f;
            param_0[1] = -10.0f;
            param_0[2] = 1200.0f;
            return;
        case 1:
            param_0[0] = 4750.0f;
            param_0[1] = -5.0f;
            param_0[2] = 650.0f;
            return;
        case 2:
            param_0[0] = 4000.0f;
            param_0[1] = 0.0f;
            param_0[2] = 300.0f;
    }
}

f32 func_8080063C_chdragonbrothers(Actor *param_0)
{
    f32 local_0;
    f32 local_1;
    f32 local_3;
    f32 local_2[3];

    local_0 = ((f32 *) func_80100094(param_0, 0))[6];
    local_1 = func_800F1DCC(local_0, ((f32 *) param_0->actorData)[0]) * 20.0f;
    func_8008FFBC(local_2);
    local_3 = func_800EF030(local_2);
    local_2[1] = local_3;
    local_1 *= func_800F10B4(local_2[1], 0.0f, 5000.0f, 0.0f, 1.0f);
    return local_0 + local_1;
}

void func_808006C8_chdragonbrothers(param_0) Actor *param_0;
{
    s32 local_7;
    Vec3f local_0;
    f32 local_1;
    Vec3f local_2;
    Vec3f local_3;
    u8 *local_4;
    f32 local_5;
    f32 local_6;
    local_4 = func_80100094(param_0, 0);
    local_5 = func_800D8FF8();
    if (param_0->unk74_29) {
        func_800F5A00(*(s32 *) (local_4 + 0x20), &local_0);
        local_1 = func_8080063C_chdragonbrothers(param_0);
        local_6 = func_800F1DCC(local_1, *(f32 *) (local_4 + 0x3C));
        *(f32 *) (local_4 + 0x44) += (local_6 - *(f32 *) (local_4 + 0x44)) * 0.085f;
        *(f32 *) (local_4 + 0x40) += *(f32 *) (local_4 + 0x44);
        if (!func_80016B54(0, 0) && func_80016B30(0, 3) == 1) {
            switch (local_4[0x55]) {
                case 2:
                    local_4[0x55] = 1;
                    func_800C3FC0(0x488, 1.0f, 12000);
                    break;
                case 1:
                    local_4[0x55] = 0;
                    func_800C3FC0(0x488, 1.0f, 12000);
                    break;
                case 0:
                    local_4[0x55] = 2;
                    func_800C3FC0(0x487, 1.0f, 12000);
            }
            func_808005A4_chdragonbrothers(local_4 + 0x30, local_4[0x55]);
        }
        for (local_7 = 0; local_7 != 3; local_7++) {
            ((f32 *) (local_4 + 0x24))[local_7] +=
                (((f32 *) (local_4 + 0x30))[local_7] - ((f32 *) (local_4 + 0x24))[local_7]) *
                local_5 * 5.0f;
        }
        func_800EFCD8(local_2.f, *(f32 *) (local_4 + 0x40), *(f32 *) (local_4 + 0x24));
        local_2.f[1] = *(f32 *) (local_4 + 0x2C);
        local_3.f[0] = *(f32 *) (local_4 + 0x28);
        local_3.f[1] = *(f32 *) (local_4 + 0x40);
        local_3.f[2] = 0.0f;
        _ncpod_entrypoint_8(func_80110024(func_800F5EF8(*(s32 *) (local_4 + 0x20))), local_2.f,
                            local_3.f);
        *(f32 *) (local_4 + 0x3C) = local_1;
    }
}

void func_808008C8_chdragonbrothers(Actor *param_0)
{
    DragonBrotherCamera *local_1;
    f32 local_0[3];

    local_1 = func_80100094(param_0, 0);
    if (!param_0->unk74_29) {
        func_800F5A00(local_1->local_0, local_0);
        local_1->local_3 = local_1->local_4 = func_800F1DF4(D_8080557C_chdragonbrothers, local_0);
        local_1->local_5 = 0.0f;
        local_1->local_6 = 0.0f;
        func_808005A4_chdragonbrothers(local_1->local_1, local_1->local_7);
        func_808005A4_chdragonbrothers(local_1->local_2, local_1->local_7);
        _ncpod_entrypoint_16(func_800F5EF8((void *) local_1->local_0), param_0->unk0, 3, 0x804);
        param_0->unk74_29 = 1;
        func_808006C8_chdragonbrothers(param_0);
        func_800A5144();
    }
}

int func_8080098C_chdragonbrothers(s32 param_0[3], s32 param_1, s32 param_2)
{
    Actor *local_0;
    u8 local_1;

    local_0 = func_80100094(param_0, 0);
    local_1 = *(u8 *) ((char *) local_0 + 0x5F);
    switch (local_1) {
        case 0:
            func_80800438_chdragonbrothers(param_0);
            _ncpod_entrypoint_16(func_800F5EF8(*(s32 *) ((char *) local_0 + 0x20)), param_0[0], 3,
                                 0);
        case 1:
            _ncpod_entrypoint_12(func_80110024(func_800F5EF8(*(s32 *) ((char *) local_0 + 0x20))),
                                 1);
            *(u8 *) ((char *) local_0 + 0x5F) = 2;
            _gcdialogcamera_entrypoint_6(param_0[0]);
            _gcdialogcamera_entrypoint_8();
            _ncpod_entrypoint_25(func_80110024(func_800F5EF8(*(s32 *) ((char *) local_0 + 0x20))),
                                 0);
        case 2:
            _ncpod_entrypoint_21(func_800F5EF8(*(s32 *) ((char *) local_0 + 0x20)), param_1,
                                 param_2);
    }
}

void func_80800A80_chdragonbrothers(Actor *param_0, s32 param_1, s32 param_2, s32 param_3)
{
    Actor *local_0;

    local_0 = func_80100094(param_0, 0);
    switch (local_0->unk5F) {
        case 0:
            func_80800438_chdragonbrothers(param_0);
            _ncpod_entrypoint_16(func_800F5EF8((void *) local_0->actorData[2]), param_0->unk0, 3,
                                 0);
        case 2:
            local_0->unk5F = 1;
        case 1:
            _ncpod_entrypoint_20(func_800F5EF8((void *) local_0->actorData[2]), param_3, param_1,
                                 param_2);
    }
}

void func_80800B34_chdragonbrothers(Actor *param_0, s32 param_1)
{
    DragonCameraState *local_0;

    local_0 = func_80100094(param_0, 0);
    if (local_0->active) {
        _ncpod_entrypoint_17(func_800F5EF8(local_0->player), 0);
        local_0->active = 0;
        if (param_1) {
            func_808008C8_chdragonbrothers(param_0);
        }
    }
}

void func_80800B9C_chdragonbrothers(Actor *param_0, s32 param_1, s32 param_2)
{
    if (param_1) {
        if (!*((u8 *) param_0 + 0x64))
            func_80090734(1, param_2);
    } else {
        if (*((u8 *) param_0 + 0x64))
            func_80090708(0);
    }
    *((u8 *) param_0 + 0x64) = param_1;
}

void func_80800C08_chdragonbrothers(Actor *param_0)
{
    f32 local_0;
    f32 local_1[3];
    local_0 = func_80101F24(param_0);
    if (local_0 < 0.1f || local_0 > 0.9f)
        return;
    if (!param_0->unk7C_12)
        return;
    if (func_8001210C(7)) {
        _subaddieskeleton_entrypoint_2(param_0->unk0, 4, local_1);
        if (!(((u8 *) param_0)[0x7A] & 1)) {
            local_1[1] += 100.0f;
            func_800BBCB8(local_1, 0, param_0->scale, 1, D_80805588_chdragonbrothers);
            _subaddieaudioloop_entrypoint_4(param_0, local_1, 1, D_808055C0_chdragonbrothers);
        } else {
            local_1[1] += 200.0f;
            func_800BBCB8(local_1, 0, param_0->scale, 1, D_808055DC_chdragonbrothers);
        }
    }
}

void func_80800D20_chdragonbrothers(u8 *param_0, s16 param_1, u32 param_2)
{
    u8 *new_var2;
    u8 local_0;
    int new_var;
    param_2 |= 6;
    new_var = 0x7A;
    new_var2 = &param_0[new_var];
    if ((*new_var2 & 1) != 0U) {
        local_0 = 0x75;
    } else {
        local_0 = 0x76;
        if ((param_1 && param_1) && param_1) {
        }
    }
    func_800C05B8(param_1, param_2, param_0 + 4, *(s32 *) param_0, 0, 0, local_0);
    param_0[0x74] |= 0x40;
}

void func_80800D98_chdragonbrothers(Actor *param_0, s32 param_1)
{
    DragonData_80800D98_chdragonbrothers *local_0;
    s16 local_2;
    s16 local_1;

    local_0 = func_80100094(param_0, 0);
    if (local_0->unk10 == 4) {
        local_0->unk20 = _plsu_entrypoint_1(1);
    }
    local_0->unk10 = param_1;
    switch (param_1) {
        case 1:
            _gcfrontend_entrypoint_9(param_0->unk7A_8 ? 0x29 : 0x2A);
            if (param_0->unk7A_8) {
                if (!func_800DA9E4(0x1D3, 1)) {
                    if (func_800DA298(0x1D6)) {
                        local_2 = 0x129C;
                    } else if (func_800DA298(0x1D4)) {
                        local_2 = 0x129A;
                    } else {
                        local_2 = 0x1296;
                    }
                } else {
                    local_2 = 0x1298;
                }
            } else {
                if (!func_800DA9E4(0x1D4, 1)) {
                    if (func_800DA298(0x1D5)) {
                        local_2 = 0x129D;
                    } else if (func_800DA298(0x1D3)) {
                        local_2 = 0x129B;
                    } else {
                        local_2 = 0x1297;
                    }
                } else {
                    local_2 = 0x1299;
                }
            }
            if (local_2) {
                func_80800D20_chdragonbrothers(param_0, local_2, 1);
            }
            break;
        case 5:
            local_0->unk58 = 3;
            func_80800B9C_chdragonbrothers(local_0, 1, param_0->position);
            func_80800A80_chdragonbrothers(param_0, 2, 0x420, 0);
            break;
        case 6:
            func_80800D20_chdragonbrothers(param_0, param_0->unk7A_8 ? 0x12A5 : 0x12A6, 1);
            func_8080098C_chdragonbrothers(param_0, 2, 1);
            break;
        case 3:
            if (param_0->unk7A_8) {
                if (func_800DA298(0x1D6)) {
                    func_800DA544(0x1D2);
                    local_1 = 0x12A3;
                } else {
                    local_1 = 0x12A1;
                }
            } else if (func_800DA298(0x1D5)) {
                func_800DA524(0x1D2);
                local_1 = 0x12A4;
            } else {
                local_1 = 0x12A2;
            }
            func_8080098C_chdragonbrothers(param_0, 2, 1);
            func_80800D20_chdragonbrothers(param_0, local_1, 1);
            break;
        case 8:
            func_800FDC28(0);
            local_0->unk58 = 1;
            if (func_800D395C()) {
                func_80800A80_chdragonbrothers(param_0, 0x14, 0x420, 0);
            } else {
                func_80800A80_chdragonbrothers(param_0, 0x14, 0x400, 0);
            }
            break;
        case 11:
            param_0->unk58 = 3.0f;
            break;
        case 12:
            func_80800A80_chdragonbrothers(param_0, 0x1D, 0x430, 0);
            break;
        case 13:
            func_80800B9C_chdragonbrothers(local_0, 1, param_0->position);
            func_80800D20_chdragonbrothers(param_0, param_0->unk7A_8 ? 0x12AE : 0x12AF, 1);
            break;
        case 14:
        case 15:
            local_0->unk5B++;
        case 16:
        case 17:
            param_0->unk58 = 0.0f;
    }
}

s32 func_8080110C_chdragonbrothers(Actor *param_0, f32 param_1, f32 param_2, s32 param_3)
{
    s32 local_0;

    for (local_0 = 0; local_0 != 360; local_0 += 90) {
        if (func_800F2094(local_0, param_1) < 10.0f) {
            return 0;
        }
    }
    if (func_800F2094(param_2, param_1) < 5.0f) {
        return 0;
    }
    return 1;
}

f32 func_808011C0_chdragonbrothers(Actor *param_0, s32 param_1)
{
    f32 local_0;
    f32 local_1;
    f32 local_2;
    f32 local_3;
    s32 local_4;

    local_0 = *(f32 *) ((u8 *) func_80100094(param_0, 0) + 0x18);
    local_2 = 1.0f;
    local_4 = 0;
    local_1 = param_1 ? local_0 : param_0->rotation[1];
    do {
        if (!param_1) {
            local_3 = local_1 + local_2;
            if (func_8080110C_chdragonbrothers(param_0, local_3, local_0, param_1)) {
                return local_3;
            }
        }
        local_3 = local_1 - local_2;
        if (func_8080110C_chdragonbrothers(param_0, local_3, local_0, param_1)) {
            return local_3;
        }
        local_2 += 1.0f;
    } while (!local_4);
    return local_1;
}

void func_808012B4_chdragonbrothers(param_0, param_1) Actor *param_0;
s32 param_1;
{
    DragonData_808012B4_chdragonbrothers *local_0;
    s32 local_2;
    f32 local_1[3];

    local_0 = func_80100094(param_0, 0);
    switch (param_0->unk70_10) {
        case 3:
        case 4:
            param_0->unk64_16 = 1;
            break;
        case 5:
            func_80800B9C_chdragonbrothers(local_0, 0, param_0->position);
            break;
        case 6:
            func_80800B9C_chdragonbrothers(local_0, 0, param_0->position);
            func_80800000_chdragonbrothers(param_0, 1);
            local_0->unk5A = 0;
            local_0->unk59 = 1;
            break;
        case 23:
            param_0->unk64_20 = 0;
            break;
        case 15:
        case 20:
        case 21:
            local_0->unk5A = 0;
            break;
        case 16:
        case 17:
            local_0->unk54 = 0;
    }
    func_80102424(param_0, param_1);
    switch (param_0->unk70_10) {
        case 5:
            func_80800A80_chdragonbrothers(param_0, 0, 0x420, 0);
            func_800FDC28(1);
            if (param_0->unk7A_8) {
                if (!func_800DA298(0x1D3)) {
                    _chintrotext_entrypoint_1(0x18B9, 9, 1, 0);
                }
            } else if (!func_800DA298(0x1D4)) {
                _chintrotext_entrypoint_1(0x18B9, 10, 1, 0);
            }
            break;
        case 6:
            func_80800A80_chdragonbrothers(param_0, 5, 0x420, 0);
            func_80800B9C_chdragonbrothers(local_0, 1, param_0->position);
            func_80101EE4(param_0, 0.5f);
            local_0->unk5A = 1;
            break;
        case 8:
            param_0->unk79_4--;
            break;
        case 9:
            if (param_0->unk64_19) {
                param_0->unk58 = 0.0f;
            } else {
                param_0->unk58 = 0.5f;
            }
            break;
        case 10:
            if (param_0->unk64_19) {
                param_0->unk58 = 1.0f;
            } else {
                param_0->unk58 = 2.0f;
            }
            break;
        case 11:
            local_2 = param_0->unk7A_8 ? 0x406 : 0x407;
            param_0->unk6C_0 = 1;
            if (param_0->unk64_19) {
                param_0->unk58 = 1.5f;
            } else {
                param_0->unk58 = 3.0f;
            }
            local_0->unk5D = 1;
            if (!func_800DA9E4(local_2, 1)) {
                func_80800D98_chdragonbrothers(param_0, 0xC);
            }
        case 12:
            _subaddieaudioquick_entrypoint_2(param_0, param_0->position,
                                             D_80805558_chdragonbrothers);
            break;
        case 14:
            func_8010A570(param_0);
            func_80800000_chdragonbrothers(param_0, 0);
            if (!func_800DA298(param_0->unk7A_8 ? 0x404 : 0x405)) {
                func_80800B9C_chdragonbrothers(local_0, 1, param_0->position);
                func_80800A80_chdragonbrothers(param_0, 0xC, 0x420, 0);
            }
            param_0->unk54 = func_808011C0_chdragonbrothers(param_0, 1);
            local_0->unk5E = 0;
            break;
        case 16:
            param_0->unk6C_0 = 0;
            func_8010A590(param_0);
            ((f32 *) param_0->actorData)[3] = 0.0f;
            local_0->unk54 = 1;
            break;
        case 17:
            if (param_0->unk64_19) {
                ((f32 *) param_0->actorData)[7] = 45.0f;
            } else {
                ((f32 *) param_0->actorData)[7] = 30.0f;
            }
            ((f32 *) param_0->actorData)[1] = 0.0f;
            if (func_800F1DCC(param_0->rotation[1], local_0->unk18) < 0.0f) {
                func_80800D98_chdragonbrothers(param_0, 0x10);
            } else {
                func_80800D98_chdragonbrothers(param_0, 0xE);
            }
            local_0->unk5B = 0;
            local_0->unk54 = 1;
            break;
        case 19:
            func_8010A570(param_0);
            _subaddieaudioquick_entrypoint_2(param_0, param_0->position,
                                             D_808053B0_chdragonbrothers);
            func_80800B9C_chdragonbrothers(local_0, 1, param_0->position);
            func_80800A80_chdragonbrothers(param_0, 9, 0x420, 0);
            func_800DA544(param_0->unk7A_8 ? 0x1D5 : 0x1D6);
            func_80800000_chdragonbrothers(param_0, 2);
            param_0->unk54 = func_808011C0_chdragonbrothers(param_0, 1);
            func_80800D98_chdragonbrothers(param_0, 0xA);
            break;
        case 20:
            local_0->unk59 = 0;
            local_0->unk5A = 1;
            break;
        case 15:
        case 21:
            local_0->unk5A = 1;
            break;
        case 22:
            param_0->unk64_20 = 1;
            param_0->rotation[1] = 0.0f;
            func_80800A80_chdragonbrothers(param_0, 0x18, 0x420, 0);
            break;
        case 23:
            func_80800D20_chdragonbrothers(param_0, param_0->unk7A_8 ? 0x12CA : 0x12CB, 1);
            local_1[1] = 1500.0f;
            func_800EFCD8(local_1, param_0->rotation[1], -600.0f);
            func_800EF04C(param_0->position, local_1);
            func_80800D98_chdragonbrothers(param_0, 7);
            break;
        case 2:
            param_0->unk64_16 = 0;
    }
}

void func_8080183C_chdragonbrothers(Actor *param_0)
{
    s8 *local_0;
    local_0 = func_80100094(param_0, 0);
    if (param_0->unk64_19) {
        param_0->unk79_4 = 3;
    } else {
        param_0->unk79_4 = 3;
    }
    local_0[0x5E]++;
    func_8010A590(param_0);
    func_808012B4_chdragonbrothers(param_0, 8);
}

void func_808018BC_chdragonbrothers(Actor *param_0)
{
    u8 *local_0;

    local_0 = func_80100094(param_0, 0);
    *(s32 *) (local_0 + 0x14) = 0;
    if (param_0->unk64_19) {
        param_0->unk79_4 = 4;
    } else {
        param_0->unk79_4 = 2;
    }
    func_808012B4_chdragonbrothers(param_0, 14);
}

void func_80801924_chdragonbrothers(Actor *param_0, Actor *param_1)
{
    u8 *local_0;
    u32 local_1;

    local_0 = func_80100094(param_0, 0);
    if (param_0->unk64_19) {
        local_1 = 3;
    } else {
        local_1 = 2;
    }
    if (param_0->unk6C_0 < local_1) {
        (*(s32 *) (local_0 + 0xC))--;
        (*(s32 *) (local_0 + 0x14))++;
        if (*(s32 *) (local_0 + 0xC) <= 0) {
            func_808012B4_chdragonbrothers(param_0, 19);
            return;
        }
        local_0[param_1->unk74_7 + 4]++;
        if ((local_0 + 4)[param_1->unk74_7] >= 3) {
            local_0[param_1->unk74_7] = 2;
        }
        switch (param_0->unk70_10) {
            case 8:
            case 9:
            case 10:
                func_808012B4_chdragonbrothers(param_0, 11);
                break;
            case 11:
            case 12:
            case 13:
                param_0->unk6C_0++;
                func_808012B4_chdragonbrothers(param_0, 12);
        }
    }
}

void func_80801A4C_chdragonbrothers(Actor *param_0, f32 param_1)
{
    f32 local_0;
    f32 local_1;

    local_0 = func_800D8FF8();
    if (param_1 > 2.0f) {
        local_1 = param_1 * 15.5f;
        if (local_1 < param_0->unk50) {
            param_0->unk50 -= ((param_0->unk50 - param_1) * 0.006f) * 60.0f;
        } else {
            param_0->unk50 += (param_1 * 0.015f) * 60.0f;
            if (local_1 < param_0->unk50) {
                param_0->unk50 = local_1;
            }
        }
    } else if (param_1 < -2.0f) {
        local_1 = param_1 * 15.5f;
        if (param_0->unk50 < local_1) {
            param_0->unk50 -= ((param_0->unk50 - param_1) * 0.006f) * 60.0f;
        } else {
            param_0->unk50 += (param_1 * 0.015f) * 60.0f;
            if (param_0->unk50 < local_1) {
                param_0->unk50 = local_1;
            }
        }
    } else {
        param_0->unk50 *= 0.9f;
    }
    if (param_0->unk50 > 75.0f) {
        param_0->unk50 = 75.0f;
    } else if (param_0->unk50 < -75.0f) {
        param_0->unk50 = -75.0f;
    }
    param_0->rotation[1] += param_0->unk50 * local_0;
}

void func_80801C44_chdragonbrothers(Actor *param_0, s32 param_1)
{
    f32 local_3;
    f32 local_0;
    f32 local_1 = 0.0f;
    DragonYaw1482 *local_2;

    local_2 = func_80100094(param_0, 0);
    local_0 = local_2->local_0 + param_1;
    if (!param_1)
        local_1 = func_800F1DCC(local_0, ((f32 *) param_0->actorData)[0]) * 10.0f;
    local_2->local_1 = local_0 + local_1;
    local_3 = func_800F1DCC(local_2->local_1, param_0->rotation[1]);
    param_0->unk54 = local_0;
    func_80801A4C_chdragonbrothers(param_0, local_3);
}

void func_80801CEC_chdragonbrothers(u8 *param_0)
{
    func_80801A4C_chdragonbrothers(
        param_0, func_800F1DCC(*(f32 *) (param_0 + 0x54), *(f32 *) (param_0 + 0x48)));
    func_80801A4C_chdragonbrothers(
        param_0, func_800F1DCC(*(f32 *) (param_0 + 0x54), *(f32 *) (param_0 + 0x48)));
}

s32 func_80801D40_chdragonbrothers(Actor *param_0, s32 param_1, s32 param_2)
{
    s8 *local_0;
    Actor *local_1;
    Vec3f local_2;
    Actor *local_3;
    s32 local_4;
    s16 *local_5;
    Vec3f local_6;
    f32 local_7;

    local_0 = func_80100094(param_0, 0);
    switch (param_1) {
        default:
            return 0;
        case 0x96:
            local_0[0x63] = 1;
            if (!func_800D395C()) {
                return 0;
            }
            func_80800D20_chdragonbrothers(param_0, 0xCEB, 0x40);
            break;
        case 0x9F:
            func_800FDC28(0);
            local_0[0x59] = 0;
            if (func_80800438_chdragonbrothers(param_0)) {
                func_808004A4_chdragonbrothers(param_0, 1);
            }
            break;
        case 0x3D: {
            local_2 = D_80805608_chdragonbrothers;
            func_800EF934(local_2.f, local_2.f, param_0->rotation[1]);
            local_1 = func_80108528(0x379, local_2.f, (s32) param_0->rotation[1], &param_0);
            local_1->unk64_19 = param_0->unk64_19;
            local_1->unk3C = param_0->unk0;
            break;
        }
        case 0x54: {
            local_3 = func_80106790((Unk80132ED0 *) param_2);
            if (*(s32 *) (local_0 + 0xC) <= 0) {
                return 1;
            }
            (local_0 + 8)[local_3->unk74_7]--;
            if ((local_3->unk79_4 == 2 && param_0->unk7A_8) ||
                (local_3->unk79_4 == 3 && !param_0->unk7A_8)) {
                func_80801924_chdragonbrothers(param_0, local_3);
                return 1;
            }
            switch (param_0->unk70_10) {
                case 8:
                case 9:
                case 10:
                case 13:
                    if (param_0->unk7A_8) {
                        if (!func_800DA9E4(0x1D7, 1)) {
                            func_80800D20_chdragonbrothers(param_0, 0x129E, 1);
                        }
                    } else {
                        if (!func_800DA9E4(0x1D8, 1)) {
                            func_80800D20_chdragonbrothers(param_0, 0x129F, 1);
                        }
                    }
            }
            break;
        }
        case 0x3E: {
            if (!param_0->unk64_16) {
                break;
            }
            if (((Unk80132ED0 *) param_2)->unk24 >> 22) {
                break;
            }
            switch (param_0->unk70_10) {
                case 8:
                case 9:
                case 10:
                case 11:
                case 12:
                case 13:
                case 14:
                case 15:
                case 16:
                case 17:
                case 18:
                    local_4 = func_800F54E4();
                    if (func_800F6438(local_4) && !func_800F6AA4(local_4) &&
                        func_800F6478(local_4)) {
                        func_800F7B9C(local_4, 0x51);
                    }
            }
            break;
        }
        case 0x2E: {
            local_5 = (s16 *) &param_2;
            if (local_5[0] == 0xCEB) {
                if (local_5[1] == 1) {
                    _gcfrontend_entrypoint_11();
                } else {
                    _gcfrontend_entrypoint_10();
                }
                break;
            }
            switch (*(s32 *) (local_0 + 0x10)) {
                case 7:
                    return 1;
                case 1:
                    switch (local_5[0]) {
                        case 0x1296:
                        case 0x1297:
                        case 0x1298:
                        case 0x1299:
                        case 0x129A:
                        case 0x129B:
                        case 0x129C:
                        case 0x129D:
                            if (param_0->unk7A_8) {
                                func_800FDC28(8);
                            } else {
                                func_800FDC28(9);
                            }
                            func_80800B34_chdragonbrothers(param_0, 1);
                            func_808012B4_chdragonbrothers(param_0, 10);
                            goto dialog_done;
                        default:
                            return 1;
                    }
                case 2:
                    return 1;
                case 3:
                    switch (local_5[0]) {
                        case 0x12A1:
                        case 0x12A2:
                            func_808012B4_chdragonbrothers(param_0, 0x16);
                        case 0x12A3:
                        case 0x12A4:
                            goto dialog_done;
                        default:
                            return 1;
                    }
                case 6:
                    if (local_5[0] == 0x12A5 || local_5[0] == 0x12A6) {
                        func_808012B4_chdragonbrothers(param_0, 16);
                        func_80800B34_chdragonbrothers(param_0, 1);
                        func_80800B9C_chdragonbrothers(local_0, 0, param_0->position);
                    }
                    break;
                case 12:
                case 13:
                    if (local_5[0] == 0x12AE || local_5[0] == 0x12AF) {
                        func_80800B34_chdragonbrothers(param_0, 1);
                        func_80800B9C_chdragonbrothers(local_0, 0, param_0->position);
                        break;
                    }
                    return 1;
                default:
                    return 1;
            }
        dialog_done:
            func_80800D98_chdragonbrothers(param_0, 0);
            param_0->unk74_30 = 0;
            break;
        }
        case 0x2F: {
            local_5 = (s16 *) &param_2;
            if (local_5[1] != 1 || func_800D395C() || func_800D0A9C(0x3D, 1)) {
                break;
            }
            local_6 = D_80805614_chdragonbrothers;
            local_7 = *(f32 *) (local_0 + 0x18);
            if (func_800F2094(0.0f, local_7) < 10.0f) {
                func_800EEB9C(local_6.f, (func_800DC298(0.5f) ? 4 : -4) + local_7, 3100.0f);
            }
            func_800D1000(0x3D, 1, local_6.f, 1, param_0->unk0);
            break;
        }
        case 0xD: {
            func_80800A80_chdragonbrothers(param_0, 0x16, 0x400, func_80101080());
            break;
        }
        case 0xB:
            switch (param_2) {
                case 0x1A:
                    func_80800D98_chdragonbrothers(param_0, 8);
                    return 4;
                case 0x14:
                    if (func_800D395C()) {
                        _gcfrontend_entrypoint_10();
                    } else {
                        func_80800B34_chdragonbrothers(param_0, 0);
                        func_80800B9C_chdragonbrothers(local_0, 0, param_0->position);
                        func_808004A4_chdragonbrothers(param_0, 1);
                    }
                    return 4;
                case 0x16:
                    func_808012B4_chdragonbrothers(param_0, 0x16);
                    return 4;
                default:
                    return 3;
            }
        case 0x52:
            switch (param_0->unk70_10) {
                case 15: {
                    f32 local_9[3];

                    func_800EE7F8(local_9, param_0->position);
                    func_800EF1B8(local_9, param_0->rotation[1], param_0->scale * 650.0f);
                    _gcdialogcamera_entrypoint_3(D_80805620_chdragonbrothers, param_0->scale);
                    _gcdialogcamera_entrypoint_4(local_9);
                    break;
                }
                case 19: {
                    f32 local_10[3];

                    func_800EE7F8(local_10, param_0->position);
                    func_800EF1B8(local_10, param_0->rotation[1], param_0->scale * 600.0f);
                    _gcdialogcamera_entrypoint_3(D_80805630_chdragonbrothers, param_0->scale);
                    _gcdialogcamera_entrypoint_4(local_10);
                    break;
                }
                default:
                    _gcdialogcamera_entrypoint_3(D_80805640_chdragonbrothers, param_0->scale);
            }
    }
    return 1;
}

int func_80802534_chdragonbrothers(s32 param_0)
{
    return func_80090248() && func_8008FA2C(-1, 0);
}

void func_80802574_chdragonbrothers(param_0) Actor *param_0;
{
    f32 local_0;
    DragonUpdateData *local_1;
    f32 local_2[3];
    f32 local_3[3];
    f32 local_4[3];
    s32 local_5;
    f32 local_6;
    f32 local_7[3];
    f32 local_8[3];

    local_0 = func_800D8FF8();
    local_1 = func_80100094(param_0, 0);
    if ((s32) param_0->unk70_10 >= 5 && local_1->field_63 == 0) {
        func_800F5A00(local_1->field_20, local_2);
        func_800F1EA4(local_2, &local_1->field_18);
        ((f32 *) param_0->actorData)[0] = ((f32 *) param_0->actorData)[2];
        ((f32 *) param_0->actorData)[2] = local_1->field_18;
        if (local_1->field_61) {
            if (func_80090178(0x10000)) {
                if (local_1->field_62) {
                    local_1->field_62 = 0;
                    func_80800438_chdragonbrothers(param_0);
                }
            } else if (local_1->field_62 == 0) {
                local_1->field_62 = 1;
                func_808008C8_chdragonbrothers(param_0);
            }
        }
        switch (param_0->unk70_10) {
            case 7:
            case 8:
            case 9:
            case 10:
            case 11:
            case 12:
            case 13:
            case 14:
            case 16:
            case 17:
            case 18:
                if (local_2[1] < -200.0f ||
                    (local_2[1] < -10.0f && func_800EF030(local_2) > 10824100.0f)) {
                    if (local_1->field_61) {
                        local_1->field_61 = 0;
                        func_80800438_chdragonbrothers(param_0);
                        func_808004A4_chdragonbrothers(param_0, 0);
                    }
                } else if (local_1->field_61 == 0) {
                    local_1->field_61 = 1;
                    func_808008C8_chdragonbrothers(param_0);
                }
                break;
        }
    }

    if (param_0->unk70_10 == 23) {
        func_800EFCD8(local_3, param_0->rotation[1], 1000.0f * local_0);
        local_3[1] = 800.0f * local_0;
        func_800EF04C(param_0->position, local_3);
    } else {
        func_800EEB9C(param_0->position, param_0->rotation[1], 250.0f);
        param_0->position[1] = -200.0f;
    }

    if (param_0->unk7A_8) {
        if (local_1->field_5C == 2 && !func_800DA298(0x406)) {
            func_80800B9C_chdragonbrothers(local_1, 1, param_0->position);
            local_1->field_5C = 10;
            func_800C067C(0x129E);
        }
    } else {
        if (local_1->field_5C == 3 && !func_800DA298(0x407)) {
            func_80800B9C_chdragonbrothers(local_1, 1, param_0->position);
            local_1->field_5C = 10;
            func_800C067C(0x129F);
        }
    }

    switch (param_0->unk70_10) {
        case 3:
            switch (local_1->field_10) {
                case 4:
                    if (func_8010CB0C(D_80805650_chdragonbrothers, 0x8FC, 10, -10) &&
                        func_8008FA2C(1, 0)) {
                        func_80800D98_chdragonbrothers(param_0, 5);
                    }
                    break;
                case 5:
                    if (local_1->field_58 == 2) {
                        func_80800D98_chdragonbrothers(param_0, 0);
                        func_808012B4_chdragonbrothers(param_0, 5);
                    }
                    break;
            }
            break;
        case 4:
            if (local_1->field_10 == 4 &&
                func_8010CB0C(D_8080565C_chdragonbrothers, 0x8FC, 10, -10) && func_8008FA2C(1, 0)) {
                local_1->field_58 = 3;
                func_80800D98_chdragonbrothers(param_0, 1);
                func_808012B4_chdragonbrothers(param_0, 6);
            }
            break;
        case 5:
            if (func_80101DDC(param_0)) {
                func_80800D98_chdragonbrothers(param_0, 1);
                func_808012B4_chdragonbrothers(param_0, 6);
            }
            func_80801C44_chdragonbrothers(param_0, 0);
            break;
        case 6:
            if (func_80101E4C(param_0, D_80805668_chdragonbrothers)) {
                if (param_0->unk7C_12) {
                    _subaddieskeleton_entrypoint_2(param_0->unk0, 4, local_4);
                } else {
                    func_800EE7F8(local_4, param_0->position);
                }
                _subaddieaudioquick_entrypoint_2(param_0, local_4, D_808053C8_chdragonbrothers);
            }
            break;
        case 7:
            if (func_800F2094(param_0->rotation[1], local_1->field_18) < 10.0f) {
                func_8080183C_chdragonbrothers(param_0);
            }
            func_80801C44_chdragonbrothers(param_0, 0);
            break;
        case 8:
            func_80801C44_chdragonbrothers(param_0, 0);
            if (func_80101E14(param_0, 0.1f)) {
                _subaddieaudioquick_entrypoint_2(param_0, param_0->position,
                                                 D_808053E0_chdragonbrothers);
            } else if (func_80101E14(param_0, 0.25f)) {
                func_80108B04(param_0, 0);
            } else if (func_80101DDC(param_0)) {
                if ((s32) param_0->unk79_4 > 0) {
                    func_808012B4_chdragonbrothers(param_0, 9);
                } else if (local_1->field_5D && local_1->field_5E == 3 && local_1->field_61) {
                    func_808018BC_chdragonbrothers(param_0);
                } else {
                    func_808012B4_chdragonbrothers(param_0, 10);
                }
            }
            break;
        case 9:
            if (param_0->unk58 > 0.0f) {
                param_0->unk58 -= func_800D8FF8();
            } else if (local_1->field_61 && local_1->field_63 == 0) {
                func_808012B4_chdragonbrothers(param_0, 8);
            }
            func_80801C44_chdragonbrothers(param_0, 0);
            break;
        case 10:
            if (param_0->unk58 > 0.0f) {
                param_0->unk58 -= func_800D8FF8();
            } else if (local_1->field_61 && local_1->field_63 == 0) {
                func_8080183C_chdragonbrothers(param_0);
            }
            func_80801C44_chdragonbrothers(param_0, 0);
            break;
        case 11:
        case 12:
            if (func_80101DDC(param_0)) {
                if (local_1->field_10 == 12) {
                    func_80800D98_chdragonbrothers(param_0, 13);
                }
                func_808012B4_chdragonbrothers(param_0, 13);
            }
            if (local_1->field_10 == 0 && param_0->unk58 > 0.0f) {
                param_0->unk58 -= local_0;
            }
            func_80801C44_chdragonbrothers(param_0, 0);
            break;
        case 13:
            func_80801C44_chdragonbrothers(param_0, 0);
            if (local_1->field_10 == 0) {
                local_5 = param_0->unk64_19 ? 3 : 2;
                if ((param_0->unk6C_0 >= local_5 || local_1->field_14 >= local_5) &&
                    (func_80802534_chdragonbrothers(param_0) ||
                     func_800DA298(param_0->unk7A_8 ? 0x404 : 0x405))) {
                    func_808018BC_chdragonbrothers(param_0);
                    break;
                }
                if (param_0->unk58 > 0.0f) {
                    param_0->unk58 -= local_0;
                } else if (local_1->field_60 > 0) {
                    func_80800000_chdragonbrothers(param_0, 0);
                } else if (func_80802534_chdragonbrothers(param_0) ||
                           func_800DA298(param_0->unk7A_8 ? 0x404 : 0x405)) {
                    func_808018BC_chdragonbrothers(param_0);
                }
            }
            break;
        case 14:
            if (func_80101DDC(param_0)) {
                if (!func_800DA9E4(param_0->unk7A_8 ? 0x404 : 0x405, 1)) {
                    func_808012B4_chdragonbrothers(param_0, 15);
                    func_80800D98_chdragonbrothers(param_0, 6);
                } else {
                    func_808012B4_chdragonbrothers(param_0, 16);
                }
            }
            func_80801CEC_chdragonbrothers(param_0);
            break;
        case 15:
            func_80801CEC_chdragonbrothers(param_0);
            break;
        case 16:
            if (func_80101DDC(param_0)) {
                func_808012B4_chdragonbrothers(param_0, 17);
            }
            func_80801CEC_chdragonbrothers(param_0);
            break;
        case 17:
            func_800EEB9C(local_7, param_0->rotation[1], 2300.0f);
            _subaddieaudioloop_entrypoint_4(param_0, local_7, 1, D_80805678_chdragonbrothers);
            param_0->unk58 += local_0;
            param_0->unk54 = local_1->field_18;
            switch (local_1->field_10) {
                case 14:
                    local_6 = param_0->unk64_19 ? 0.6499938965f : 1.299987793f;
                    ((f32 *) param_0->actorData)[3] = func_800F10B4(
                        param_0->unk58, 0.0f, local_6, 0.0f, ((f32 *) param_0->actorData)[7]);
                    if ((param_0->unk64_19 ? 1.0f : 1.5f) < param_0->unk58 &&
                        func_800F1DCC(param_0->rotation[1], param_0->unk54) <= 0.0f) {
                        func_80800D98_chdragonbrothers(param_0, 15);
                    }
                    break;
                case 15:
                    local_6 = param_0->unk64_19 ? 0.4499969482f : 0.8499908447f;
                    ((f32 *) param_0->actorData)[3] = func_800F10B4(
                        param_0->unk58, 0.0f, local_6, ((f32 *) param_0->actorData)[7], 0.0f);
                    if ((param_0->unk64_19 ? 0.4499969482f : 0.8499908447f) < param_0->unk58) {
                        func_80800D98_chdragonbrothers(param_0, 16);
                    }
                    break;
                case 16:
                    local_6 = param_0->unk64_19 ? 0.6499938965f : 1.299987793f;
                    ((f32 *) param_0->actorData)[3] = func_800F10B4(
                        param_0->unk58, 0.0f, local_6, 0.0f, -((f32 *) param_0->actorData)[7]);
                    if ((param_0->unk64_19 ? 1.0f : 1.5f) < param_0->unk58 &&
                        func_800F1DCC(param_0->rotation[1], param_0->unk54) >= 0.0f) {
                        func_80800D98_chdragonbrothers(param_0, 17);
                    }
                    break;
                case 17:
                    local_6 = param_0->unk64_19 ? 0.4499969482f : 0.8499908447f;
                    ((f32 *) param_0->actorData)[3] = func_800F10B4(
                        param_0->unk58, 0.0f, local_6, -((f32 *) param_0->actorData)[7], 0.0f);
                    if ((param_0->unk64_19 ? 0.4499969482f : 0.8499908447f) < param_0->unk58) {
                        func_80800D98_chdragonbrothers(param_0, 14);
                    }
            }
            param_0->rotation[1] -= ((f32 *) param_0->actorData)[3] * local_0;
            if ((param_0->unk64_19 ? 4 : 2) < local_1->field_5B || local_1->field_63) {
                func_80800D98_chdragonbrothers(param_0, 0);
                func_808012B4_chdragonbrothers(param_0, 18);
            }
            break;
        case 18:
            func_80801C44_chdragonbrothers(param_0, 0);
            if (func_80101E14(param_0, 0.999f)) {
                func_808012B4_chdragonbrothers(param_0, 7);
                func_80800000_chdragonbrothers(param_0, 1);
            }
            break;
        case 19:
            func_80800C08_chdragonbrothers(param_0);
            func_80801CEC_chdragonbrothers(param_0);
            switch (local_1->field_10) {
                case 10:
                    if (func_80101E14(param_0, 0.92f)) {
                        func_800EEB9C(local_8, param_0->rotation[1], 3100.0f);
                        func_800E1610(2, 150.0f, 0.85f, local_8);
                        _subaddieaudioquick_entrypoint_2(param_0, local_8,
                                                         D_80805410_chdragonbrothers);
                    } else if (func_80101DDC(param_0)) {
                        func_80800D98_chdragonbrothers(param_0, 3);
                    }
                    break;
                case 3:
                    if (param_0->unk58 > 0.0f) {
                        param_0->unk58 -= func_800D8FF8();
                    } else {
                        func_808012B4_chdragonbrothers(param_0, 20);
                    }
            }
            break;
        case 20:
            if (func_80101DDC(param_0)) {
                func_808012B4_chdragonbrothers(param_0, 21);
            }
            break;
        case 22:
            if (func_80101E4C(param_0, D_80805694_chdragonbrothers)) {
                _subaddieaudioquick_entrypoint_2(param_0, param_0->position,
                                                 D_80805424_chdragonbrothers);
            }
            if (func_80101DDC(param_0)) {
                func_808012B4_chdragonbrothers(param_0, 23);
                func_80800A80_chdragonbrothers(param_0, 0x1A, 0x420, 0);
            }
            break;
        case 23:
            _subaddieaudioquick_entrypoint_3(param_0, param_0->position,
                                             D_80805424_chdragonbrothers, 0.1f);
            switch (local_1->field_10) {
                case 7:
                    break;
                case 8:
                    if (local_1->field_58 == 0) {
                        func_80800D98_chdragonbrothers(param_0, 9);
                    }
                    break;
                case 9:
                    func_808012B4_chdragonbrothers(param_0, 2);
                    func_80800D98_chdragonbrothers(param_0, 0);
            }
    }

    if (local_1->field_5A == 0) {
        _suexpression_entrypoint_9(func_80100094(param_0, 1));
    }
    _suexpression_entrypoint_10(func_80100094(param_0, 1), param_0->unk0, 0);
    func_808006C8_chdragonbrothers(param_0);
    if (local_1->field_59 == 1) {
        func_800D2498(param_0->unk7A_8 ? 0xF9 : 0xFA, local_1->field_C, 0);
    }
}

void func_808034DC_chdragonbrothers(param_0, param_1) Actor *param_0;
s32 param_1;
{
    if (param_0->unk64_20) {
        func_800DF744(3, 1);
        func_800DF744(4, 1);
        func_800DF744(5, 1);
    } else {
        func_800DF744(3, 0);
        func_800DF744(4, 0);
        func_800DF744(5, 0);
    }
    func_80101870(param_0, param_1);
}

int chdragonbrothers_entrypoint_0()
{
    return (int) &D_808056A8_chdragonbrothers;
}

void func_80803574_chdragonbrothers(param_0) Actor *param_0;
{
    s32 local_0;
    param_0->unk74_7 = param_0->unk74_7 - 50;

    func_800EE7F8(param_0->actorData, param_0->position);
    param_0->position[1] = *(f32 *) ((u8 *) param_0 + 0x1C) - 310.0f;
    if (func_800EA05C() == 0x12B)
        ((B7A *) param_0)->b0 = 0;
    else
        ((B7A *) param_0)->b0 = 1;
    if ((((B7A *) param_0)->b0 && func_800DA298(0x1D5)) ||
        (!((B7A *) param_0)->b0 && func_800DA298(0x1D6))) {
        func_800FFAB0(param_0);
        return;
    }
    *(Unk80132ED0 **) ((u8 *) param_0 + 0x3C) = _subaddiefind_entrypoint_2(0x377, 0)->unk0;
    func_800EFCD8(param_0->position, (s32) param_0->unk74_7 * 90, 2700.0f);
    param_0->rotation[1] = (s32) param_0->unk74_7 * 90;
}

void func_808036E4_chdragonbrothers(s32 arg0)
{
}

void func_808036EC_chdragonbrothers(param_0, param_1) Actor *param_0;
s32 param_1;
{
    if (param_0->unk70_10 == 4)
        func_8010A570(param_0);
    func_80102424(param_0, param_1);
    switch (param_0->unk70_10) {
        case 2:
            *(f32 *) &param_0->actorData[3] = 200.0f;
            break;
        case 4:
            func_8010A590(param_0);
            break;
        case 5:
            param_0->unk58 = 0.0f;
            break;
        case 8:
            *(f32 *) &param_0->actorData[3] = 400.0f;
            break;
        case 9:
            *(f32 *) &param_0->actorData[3] = 400.0f;
    }
}

void func_808037B0_chdragonbrothers(Actor *param_0, s32 param_1)
{
    Actor *local_0;
    s8 *local_1;

    if (local_0) {
    }

    local_0 = func_80106790(param_0->unk3C);
    if (1) {
    }
    local_1 = func_80100094(local_0, 0);
    if (((DrbS *) local_1)->a[param_0->unk74_7] + ((DrbS *) local_1)->b[param_0->unk74_7] < 3) {
        if (param_0->unk70_10 == 4 || param_0->unk70_10 == 5) {
            if (func_808003F8_chdragonbrothers(local_0)) {
                _subaddieaudioquick_entrypoint_2(param_0, param_0->position,
                                                 D_8080543C_chdragonbrothers);
                param_0->unk79_4 = param_1 - 0x26B;
                local_1[0x5C] = param_0->unk79_4;
                func_808036EC_chdragonbrothers(param_0, 5);
                ((DrbS *) local_1)->b[param_0->unk74_7]++;
            }
        }
    }
}

void func_808038AC_chdragonbrothers(Actor *param_0)
{
    f32 local_1;
    f32 local_5;
    char *local_0;
    f32 local_2;
    f32 local_3;
    s32 local_4;

    local_1 = func_800D8FF8();

    local_0 = (char *) func_80100094(func_80106790(*(void **) ((char *) param_0 + 0x3C)), 0);

    if (*(f32 *) ((char *) param_0 + 0x8) <= *(f32 *) ((char *) param_0 + 0x1C) - 450.0f) {
        *(u8 *) ((char *) param_0 + 0x65) &= ~1;
    } else {
        ((BitS101 *) param_0)->b0 = 1;
    }

    if (*(f32 *) ((char *) param_0 + 0x8) <= *(f32 *) ((char *) param_0 + 0x1C) - 310.0f) {
        *(u8 *) ((char *) param_0 + 0x65) &= ~0x10;
    } else {
        ((BitS101 *) param_0)->b4 = 1;
    }

    switch (((u32) *(u16 *) ((char *) param_0 + 0x72) >> 10)) {
        case 1:
            local_4 = *(char *) ((s32) local_0 + ((DbIdx76 *) param_0)->idx);

            switch (local_4) {
                case 0:
                    break;
                case 2:
                    func_808036EC_chdragonbrothers(param_0, 9);
                    break;
                case 1:
                    func_808036EC_chdragonbrothers(param_0, 2);
            }
            break;

        case 2:
            if (*(f32 *) ((char *) param_0 + 0x8) < *(f32 *) ((char *) param_0 + 0x1C)) {
                *(f32 *) ((char *) param_0 + 0x8) += *(f32 *) ((char *) param_0 + 0x24) * local_1;

                if ((*(f32 *) ((char *) param_0 + 0x1C) - 40.0f) <
                    *(f32 *) ((char *) param_0 + 0x8)) {
                    *(f32 *) ((char *) param_0 + 0x24) *= 1.0f - (3.5f * local_1);
                }

                _subaddieaudioloop_entrypoint_4(param_0, (char *) param_0 + 4, 1,
                                                D_808053A0_chdragonbrothers);
            } else {
                func_808036EC_chdragonbrothers(param_0, 3);
            }
            break;

        case 3:
            if (func_80101DDC(param_0)) {
                func_808036EC_chdragonbrothers(param_0, 4);
            }
            break;

        case 4:
            local_4 = *(char *) ((s32) local_0 + ((DbIdx76 *) param_0)->idx);

            switch (local_4) {
                case 2:
                    func_808036EC_chdragonbrothers(param_0, 9);
                    break;
                case 0:
                    func_808036EC_chdragonbrothers(param_0, 6);
            }
            break;

        case 5:
            if (func_80101E14(param_0, 0.5f)) {
                if (((W7C *) param_0)->f) {
                    func_80108B04(param_0, ((Nib79 *) param_0)->hi);
                }
            }

            if (func_80101DDC(param_0)) {
                if (*(f32 *) ((char *) param_0 + 0x58) > 0.0f) {
                    *(f32 *) ((char *) param_0 + 0x58) -= func_800D8FF8();
                } else {
                    func_808036EC_chdragonbrothers(param_0, 4);
                }
            }
            break;

        case 6:
        case 7:
            if (func_80101DDC(param_0)) {
                local_4 = *(char *) ((s32) local_0 + ((DbIdx76 *) param_0)->idx);

                switch (local_4) {
                    case 2:
                        func_808036EC_chdragonbrothers(param_0, 9);
                        break;
                    case 0:
                        func_808036EC_chdragonbrothers(param_0, 8);
                }
            }
            break;

        case 8:
            local_3 = *(f32 *) ((char *) param_0 + 0x1C) - 310.0f;

            if (local_3 < *(f32 *) ((char *) param_0 + 0x8)) {
                *(f32 *) ((char *) param_0 + 0x8) -= *(f32 *) ((char *) param_0 + 0x24) * local_1;

                if ((*(f32 *) ((char *) param_0 + 0x1C) - 75.0f) <
                    *(f32 *) ((char *) param_0 + 0x8)) {
                    *(f32 *) ((char *) param_0 + 0x24) *= 1.0f + (1.5f * local_1);

                    local_3 = *(f32 *) ((char *) ((s32) param_0 ^ 0) + 0x1C) - 310.f;
                }

                if (*(f32 *) ((char *) param_0 + 0x8) < local_3) {
                    *(f32 *) ((char *) param_0 + 0x8) = local_3;
                }

                _subaddieaudioloop_entrypoint_4(param_0, (char *) param_0 + 4, 1,
                                                D_808053A0_chdragonbrothers);
            }

            local_4 = *(char *) ((s32) local_0 + ((DbIdx76 *) param_0)->idx);

            switch (local_4) {
                case 2:
                    func_808036EC_chdragonbrothers(param_0, 9);
                    break;
                case 1:
                    func_808036EC_chdragonbrothers(param_0, 2);
            }
            break;

        case 9:
            local_2 = *(f32 *) ((char *) param_0 + 0x1C) - 450.0f;

            if (local_2 < *(f32 *) ((char *) param_0 + 0x8)) {
                *(f32 *) ((char *) param_0 + 0x8) -= *(f32 *) ((char *) param_0 + 0x24) * local_1;

                if ((local_2 - 150.0f) < *(f32 *) ((char *) param_0 + 0x8)) {
                    *(f32 *) ((char *) param_0 + 0x24) *= 1.0f + (1.5f * local_1);

                    local_2 = *(f32 *) ((char *) param_0 + 0x1C) - 450.f;
                }

                if (*(f32 *) ((char *) param_0 + 0x8) < local_2) {
                    *(f32 *) ((char *) param_0 + 0x8) = local_2;
                }

                _subaddieaudioloop_entrypoint_4(param_0, (char *) param_0 + 4, 1,
                                                D_808053A0_chdragonbrothers);
            }

            local_4 = *(char *) ((s32) local_0 + ((DbIdx76 *) param_0)->idx);

            switch (local_4) {
                case 1:
                    func_808036EC_chdragonbrothers(param_0, 2);
                    break;
                case 0:
                    func_808036EC_chdragonbrothers(param_0, 6);
            }
    }
}

s32 func_80803DC4_chdragonbrothers(param_0, param_1, param_2)
Actor *param_0;
s32 param_1;
s32 param_2;
{
    Actor *local_1;
    Vec3f local_0;
    Unk80132ED0 *local_2;

    switch (param_1) {
        case 0x3D:
            local_0 = D_80805740_chdragonbrothers;
            func_800EF934(local_0.f, local_0.f, param_0->rotation[1]);
            local_1 = func_801084B0(0x37A, &param_0);
            local_1->rotation[0] = 153.5f;
            local_1->unk50 = 63.5f;
            local_1->unk79_4 = param_0->unk79_4;
            local_1->unk74_7 = param_0->unk74_7;
            func_800EE780(local_1->position, param_0->position, local_0.f);
            return 1;
        case 0x3E:
            local_2 = (Unk80132ED0 *) *(s32 *) &param_2;
            if (_sueggmisc_entrypoint_0(local_2)) {
                func_8010114C(local_2, 0x2C, 0);
                func_808037B0_chdragonbrothers(param_0, local_2->unk24 >> 22);
            }
            break;
        default:
            return 0;
    }
    return 1;
}

s32 func_80803EFC_chdragonbrothers(s32 param_0, volatile int param_1)
{
    func_800DF744(1, (u32) (*(s32 *) ((char *) param_0 + 0x64) << 0xb) >> 0x1F);
    func_80101870(param_0, param_1);
}

int chdragonbrothers_entrypoint_1()
{
    return (int) &D_8080574C_chdragonbrothers;
}

void func_80803F4C_chdragonbrothers(Actor *param_0)
{
    Actor *local_3 = func_80106790(param_0->unk3C);
    u8 *local_0 = func_80100094(local_3, 0);
    f32 local_1[3];

    param_0->unk74_7 = param_0->unk74_7 - 0x32;
    func_800F5A00(*(s32 *) (local_0 + 0x20), local_1);
    local_1[1] += 30.0f;
    param_0->rotation[0] = func_800F1828(param_0->position, local_1);
    func_800EEBF0((f32 *) &param_0->actorData[4], param_0->rotation,
                  param_0->unk64_19 ? 6000.0f : 4000.0f);
    if (func_800EA05C() == 0x12B)
        param_0->unk7A_8 = 0;
    else
        param_0->unk7A_8 = 1;
    if (param_0->unk7A_8)
        func_801032B0(param_0, 0x814, *(u16 *) ((u8 *) param_0->unk0 + 0x16));
    *(f32 *) &param_0->actorData[0] = func_800DC178(50.0f, 100.0f);
    *(f32 *) &param_0->actorData[1] = func_800DC178(5.0f, 10.0f);
    *(f32 *) &param_0->actorData[2] = func_800DC178(5.0f, 10.0f);
}

void func_808040A0_chdragonbrothers(s32 arg0)
{
}

void func_808040A8_chdragonbrothers(u8 *param_0)
{
    f32 dt;
    s32 r;
    s32 vec4C[3];
    s32 vec40[3];
    s32 vec34[3];
    if (1) {
    }

    dt = func_800D8FF8();
    *(f32 *) (param_0 + 0x58) = *(f32 *) (param_0 + 0x58) + dt;
    if (((Actor *) param_0)->unk70_10 == 1) {
        func_800EFA20(vec4C, param_0 + 0x28, dt);
        func_800EE780(vec40, param_0 + 4, vec4C);
        r = func_800C6A7C(param_0 + 4, vec40, vec34, 0x20020);
        func_800EE7F8(param_0 + 4, vec40);
        if (r != 0) {
            _chexploder_entrypoint_3(param_0, vec40, 8);
            func_800E1610(2, 100.0f, 0.85f, vec40);
            if (param_0[0x7A] & 1) {
                _subaddieaudioquick_entrypoint_2(param_0, 0, D_80805794_chdragonbrothers);
            } else {
                _subaddieaudioquick_entrypoint_2(param_0, param_0 + 4, D_80805448_chdragonbrothers);
            }
        } else {
            if (*(f32 *) (param_0 + 8) < -400.0f) {
                _subaddiefade_entrypoint_3(param_0);
            }
        }
        func_800EFA20(vec40, param_0 + 0x18, dt);
        func_800EF04C(param_0 + 0x44, param_0 + 0x18);
        if (0.25f < *(f32 *) (param_0 + 0x58)) {
            if (!(param_0[0x7A] & 1)) {
                func_800BBCB8(param_0 + 4, 0, *(f32 *) (param_0 + 0x38), 1,
                              D_808057A8_chdragonbrothers);
                if (!((Actor *) param_0)->unk64_20) {
                    if (0.3f < *(f32 *) (param_0 + 0x58)) {
                        _subaddieaudioquick_entrypoint_2(param_0, param_0 + 4,
                                                         D_80805460_chdragonbrothers);
                        ((Actor *) param_0)->unk64_20 = 1;
                    }
                }
            } else {
                func_800BBCB8(param_0 + 4, 0, *(f32 *) (param_0 + 0x38), 1,
                              D_808057E0_chdragonbrothers);
                func_800BBCB8(param_0 + 4, 0, *(f32 *) (param_0 + 0x38), 2,
                              D_80805810_chdragonbrothers);
                if (!((Actor *) param_0)->unk64_20) {
                    if (0.3f < *(f32 *) (param_0 + 0x58)) {
                        _subaddieaudioquick_entrypoint_2(param_0, param_0 + 4,
                                                         D_80805474_chdragonbrothers);
                        ((Actor *) param_0)->unk64_20 = 1;
                    }
                }
            }
        }
    }
}

s32 func_80804318_chdragonbrothers(s32 param_0, s32 param_1)
{
    func_800DF744(1, 1);
    func_80101870(param_0, param_1);
}

s32 func_80804350_chdragonbrothers(Actor *param_0, s32 param_1, DragonMessage1804 param_2)
{
    Actor *local_0;

    switch (param_1) {
        case 15:
        case 0x90:
            local_0 = func_80106790(func_80101080());
            _chexploder_entrypoint_9(local_0, 1, 2);
            _chexploder_entrypoint_13(local_0, 6);
            if (((u8 *) param_0)[0x7A] & 1)
                _chexploder_entrypoint_15(local_0, 2, 1.0f);
            else
                _chexploder_entrypoint_15(local_0, 4, 1.0f);
            if (((u8 *) param_0)[0x7A] & 1)
                func_800BBCB8(param_0->position, param_0->position, param_0->scale, 6,
                              D_80805840_chdragonbrothers);
            else
                func_800BBCB8(param_0->position, param_0->position, param_0->scale, 6,
                              D_80805870_chdragonbrothers);
            break;
        case 0x3E:
            if (param_2.local_1->unk24 >> 22 == 0)
                func_800F7B9C(func_800F54E4(), 0x51);
            break;
        default:
            return 0;
    }
    return 1;
}

void *chdragonbrothers_entrypoint_2(void)
{
    return &D_808058A8_chdragonbrothers;
}

void func_8080449C_chdragonbrothers(Actor *param_0)
{
    Actor *local_0;
    u8 *local_1;
    u8 *local_2;
    local_1 = func_80100094(param_0, 0);
    func_800EEBF0((f32 *) ((u8 *) param_0 + 0x28), param_0->rotation, 2500.0f);
    *(f32 *) ((u8 *) param_0 + 0x58) = 0.5f;
    func_8010A590(param_0);
    ((DragonMarker1864 *) param_0->unk0)->local_0 = 1;
    local_0 = _subaddiefind_entrypoint_2(0x377, 0);
    local_2 = func_80100094(local_0, 0);
    *(Unk80132ED0 **) ((u8 *) param_0 + 0x3C) = local_0->unk0;
    if (func_800EA05C() == 0x12B)
        param_0->unk7A_8 = 0;
    else
        param_0->unk7A_8 = 1;
    *(s16 *) ((u8 *) param_0->unk0 + 0x14) = D_808058F0_chdragonbrothers[param_0->unk79_4];
    *(f32 *) ((u8 *) param_0 + 0x18) = func_800DC178(50.0f, 100.0f);
    *(f32 *) ((u8 *) param_0 + 0x1C) = func_800DC178(5.0f, 10.0f);
    *(f32 *) ((u8 *) param_0 + 0x20) = func_800DC178(5.0f, 10.0f);
    *(f32 *) (local_1 + 4) = 0.0f;
    *(s32 *) (local_1 + 0xC) = func_800AF5A0(func_800EC3E8(param_0->unk0));
    param_0->unk64_20 = 1;
    param_0->scale = 1.5f;
    (*(s8 *) (local_2 + 0x60))++;
}

void func_80804610_chdragonbrothers(Actor *param_0)
{
    DragonFrameState *local_0;

    local_0 = func_80100094(param_0, 0);
    local_0->local_0 =
        func_800F13C4(func_800D8FF8() * 30.0f + local_0->local_0, (f32) local_0->local_1);
    ((DragonFrameModel *) param_0->unk0->unk0)->local_0 = (s32) local_0->local_0 % local_0->local_1;
}

void func_808046CC_chdragonbrothers(param_0) Actor *param_0;
{
    u8 *local_2;
    Vec3f local_0;
    f32 local_3;
    s32 local_4;
    Vec3f local_1;

    local_2 = func_80100094(param_0, 0);
    *(f32 *) (local_2 + 0x10) -= func_800D8FF8();
    local_3 = func_800F10B4(*(f32 *) (local_2 + 8), 0.0, 2.0f, 0.03330000117f, 0.1f);
    while (*(f32 *) (local_2 + 0x10) <= 0.0f) {
        *(f32 *) (local_2 + 0x10) += local_3;
        local_4 = 0;
        func_800EE7F8(local_0.f, param_0->position);
        switch (param_0->unk79_4) {
            case 1:
            case 3:
            case 5:
                if (func_800DC0C0() < 0.5f) {
                    local_4 = _fxegg_entrypoint_2(local_0.f, param_0->scale);
                } else {
                    local_4 = _fxegg_entrypoint_1(local_0.f, param_0->scale);
                }
                break;
            case 7:
                func_800EFA20(local_1.f, (f32 *) &param_0->actorData[4], 0.5f);
                local_4 = _fxegg_entrypoint_6(param_0->position, param_0->scale, local_1.f);
                break;
            case 4:
                local_4 = _fxegg_entrypoint_5(param_0->position, (f32 *) &param_0->actorData[4],
                                              param_0->scale);
        }
        if (local_4 != 0) {
            func_800BA5A8(local_4, 0x200);
        }
    }
    if (param_0->unk79_4 == 2 && !func_8001210C(1)) {
        _fxegg_entrypoint_3(param_0->position, param_0->scale);
    }
}

void func_808048A4_chdragonbrothers(s32 arg0)
{
}

s32 func_808048AC_chdragonbrothers(param_0)
Actor *param_0;
{
    f32 local_0[3];
    f32 local_1[3];
    Actor *local_2;
    u8 *local_3;

    if (_subaddiecustomhits_entrypoint_2(param_0->unk3C, param_0->position, 90.0f, local_0, 0)) {
        local_2 = func_80106790(param_0->unk3C);
        local_3 = func_80100094(local_2, 0);
        func_800EE780(local_1, param_0->position, (f32 *) ((u8 *) param_0 + 0x28));
        func_808049D4_chdragonbrothers((u8 *) param_0);
        param_0->unk64_20 = 0;
        (*(s8 *) (local_3 + 0x60))--;
        _subaddieaudioquick_entrypoint_2(param_0, param_0->position, D_80805900_chdragonbrothers);
        func_800FFAB0(param_0);
        switch (local_2->unk70_10) {
            case 7:
            case 8:
            case 9:
            case 10:
            case 11:
            case 12:
            case 13:
                func_8010114C(param_0->unk3C, 0x54, param_0->unk0);
                return 1;
            default:
                if (*(s8 *) (local_3 + 8 + param_0->unk74_7) > 0) {
                    (*(s8 *) (local_3 + 8 + param_0->unk74_7))--;
                }
                return 1;
        }
    }
    return 0;
}

void func_808049D4_chdragonbrothers(u8 *param_0)
{
    u8 local_0;
    u8 *local_1 = param_0 + 4;
    int new_var;
    local_0 = param_0[121];
    if (((local_0 & 0xFFu) >> 4) == 4) {
        func_800BABB8(0, local_1, 0, *(s32 *) (param_0 + 0x38), &D_80805918_chdragonbrothers);
        func_800BABB8(0, local_1, 0, *(s32 *) (param_0 + 0x38), &D_80805960_chdragonbrothers);
        func_800BABB8(0, local_1, 0, *(s32 *) (param_0 + 0x38), &D_808059A8_chdragonbrothers);
        func_8010D930(6, -1, local_1, &D_808059D8_chdragonbrothers);
        return;
    }
    do {
    } while (0);
    new_var = (local_0 & 0xFFu) >> 4;
    _fxegg_entrypoint_0(new_var, local_1, *(s32 *) (param_0 + 0x38), (local_0 & 0xFFu) >> 4);
}

void func_80804AA4_chdragonbrothers(Actor *param_0)
{
    u8 *local_0;
    f32 local_1;
    f32 *local_5;
    f32 local_2[3];
    f32 local_3[3];
    f32 local_4[3];
    f32 *local_6;

    local_0 = func_80100094(param_0, 0);
    local_1 = func_800D8FF8();
    *(f32 *) (local_0 + 8) += local_1;
    if (param_0->unk70_10 != 1)
        return;
    if (!(param_0->unk58 > 0.0f) && func_808048AC_chdragonbrothers(param_0))
        return;
    {
        local_6 = (f32 *) param_0->actorData;
        local_5 = param_0->position;
        func_800EE7F8(local_6, local_5);
        func_800EFA20(local_2, (f32 *) &param_0->actorData[4], local_1);
        func_800EE780(local_3, local_5, local_2);
        *(f32 *) &param_0->actorData[5] -= 25.0f;
        if (param_0->unk58 > 0.0f) {
            param_0->unk58 -= local_1;
        } else if (func_800C6A7C(local_5, local_3, local_4, 0x20020)) {
            func_808049D4_chdragonbrothers(param_0);
            func_800FFAB0(param_0);
        }
        func_800EE7F8(local_5, local_3);
        func_800EFA20(local_3, local_6, local_1);
        func_800EF04C(param_0->rotation, local_6);
    }
    func_80804610_chdragonbrothers(param_0);
    func_808046CC_chdragonbrothers(param_0);
    if (param_0->unk79_4 == 2) {
        _subaddieaudioloop_entrypoint_4(param_0, local_5, 1, D_808059EC_chdragonbrothers);
    }
    if (param_0->position[1] < -1000.0f) {
        local_0 = func_80100094(func_80106790(param_0->unk3C), 0);
        param_0->unk64_20 = 0;
        (*(s8 *) (local_0 + 0x60))--;
        _subaddiefade_entrypoint_3(param_0);
    }
}

s32 func_80804C6C_chdragonbrothers(s32 param_0, s32 param_1, s32 param_2)
{
    if (param_1 != 0xF)
        return FALSE;
    return TRUE;
}

s32 func_80804C90_chdragonbrothers(s32 param_0, s32 param_1)
{
    func_800E24D8(1);
    _subaddiedraw25d_entrypoint_2(param_0, param_1);
}

s32 chdragonbrothers_entrypoint_3()
{
    return D_80805A08_chdragonbrothers;
}

void func_80804CD0_chdragonbrothers(Actor *param_0)
{
    func_800EFA4C(param_0->position, 0.0f, -500.0f, 3150.0f);
    param_0->rotation[2] = 180.0f;
    param_0->scale = 1.68f;
    if (func_800EA05C() == 0x12B)
        param_0->unk7A_8 = 0;
    else
        param_0->unk7A_8 = 1;
    if ((param_0->unk7A_8 && !func_800DA298(0x1D5)) ||
        (!param_0->unk7A_8 && !func_800DA298(0x1D6))) {
        param_0->unk3C = _subaddiefind_entrypoint_2(0x377, NULL)->unk0;
        func_80103110(param_0, 1);
    }
}

void func_80804DB0_chdragonbrothers(s32 arg0)
{
}

void func_80804DB8_chdragonbrothers(param_0, param_1) Actor *param_0;
s32 param_1;
{
    switch ((*(Actor **) &param_0)->unk70_10) {
        case 1:
            break;
        case 2:
        case 4:
            _subaddieaudioquick_entrypoint_2(param_0, &D_80805A50_chdragonbrothers,
                                             &D_80805488_chdragonbrothers);
    }
    func_80101FDC(param_0, param_1);
}

void func_80804E1C_chdragonbrothers(Actor *param_0)
{
    Actor *local_1;
    u8 *local_2;
    f32 local_0;
    local_0 = func_800D8FF8();
    if (param_0->unk3C) {
        local_1 = func_80106790(param_0->unk3C);
        local_2 = func_80100094(local_1, 0);
        switch ((s32) param_0->unk70_10) {
            case 1:
                if (local_2[0x58] == 1) {
                    func_80804DB8_chdragonbrothers(param_0, 2, local_2);
                }
                break;
            case 2:
                if (param_0->position[1] > -500.0f) {
                    param_0->position[1] -= 150.0f * local_0;
                    _subaddieaudioloop_entrypoint_4(param_0, (s32 *) &D_80805A50_chdragonbrothers,
                                                    1, &D_808053A0_chdragonbrothers);
                } else {
                    func_80804DB8_chdragonbrothers(param_0, 3, local_2);
                    local_2[0x58] = 0;
                }
                break;
            case 3:
                if (local_2[0x58] == 3) {
                    func_80804DB8_chdragonbrothers(param_0, 4, local_2);
                }
                break;
            case 4:
                if (param_0->position[1] < -200.0f) {
                    param_0->position[1] += 150.0f * local_0;
                    _subaddieaudioloop_entrypoint_4(param_0, (s32 *) &D_80805A50_chdragonbrothers,
                                                    1, &D_808053A0_chdragonbrothers);
                } else {
                    func_80804DB8_chdragonbrothers(param_0, 1, local_2);
                    local_2[0x58] = 2;
                }
        }
    }
}

int chdragonbrothers_entrypoint_4()
{
    return (int) &D_80805A5C_chdragonbrothers;
}

extern void func_80108ED0();
extern int func_80101870();
u8 D_808053A0_chdragonbrothers[16] = {0x0, 0x13, 0x4, 0xAD, 0x0,  0x16, 0x46, 0x50,
                                      0x0, 0x1,  0x7, 0xD0, 0x13, 0x88, 0x0,  0x0};
u32 D_808053B0_chdragonbrothers[6] = {0x130605, 0xD00F3, 0x10C0016, 0x7FFF0001, 0x1F402710, 0x0};
u8 D_808053C8_chdragonbrothers[24] = {0x0,  0x13, 0x6,  0x30, 0x0,  0xD,  0x0, 0xF3,
                                      0x1,  0xC,  0x0,  0x16, 0x5D, 0xC0, 0x0, 0x1,
                                      0x1F, 0x40, 0x27, 0x10, 0x0,  0x0,  0x0, 0x0};
u8 D_808053E0_chdragonbrothers[48] = {
    0x0,  0x13, 0x6,  0x0,  0x0,  0xD,  0x0, 0xF3, 0x1,  0xC,  0x0,  0x16, 0x5D, 0xC0, 0x0, 0x1,
    0x13, 0x88, 0x27, 0x10, 0x0,  0x0,  0x0, 0x0,  0x0,  0x13, 0x4,  0x9E, 0x0,  0xD,  0x0, 0xF3,
    0x1,  0xC,  0x0,  0x16, 0x46, 0x50, 0x0, 0x1,  0x13, 0x88, 0x1D, 0x4C, 0x0,  0x0,  0x0, 0x0};
u8 D_80805410_chdragonbrothers[20] = {0x0,  0x13, 0x4, 0x16, 0x0,  0xA,  0x0,  0xC0, 0x0, 0x16,
                                      0x5D, 0xC0, 0x0, 0x1,  0x1F, 0x40, 0x27, 0x10, 0x0, 0x0};
u8 D_80805424_chdragonbrothers[24] = {0x0, 0x13, 0x3,  0xFF, 0x0,  0xD,  0x0,  0xCC,
                                      0x0, 0xE6, 0x0,  0x19, 0x46, 0x50, 0x5D, 0xC0,
                                      0x0, 0x1,  0x13, 0x88, 0x27, 0x10, 0x0,  0x0};
u8 D_8080543C_chdragonbrothers[12] = {0x0, 0x13, 0x6, 0x86, 0x0, 0x18,
                                      0x0, 0x2,  0x0, 0x0,  0x0, 0x0};
u8 D_80805448_chdragonbrothers[24] = {0x0,  0x13, 0x4,  0x13, 0x0,  0xD,  0x0, 0xF3,
                                      0x1,  0xC,  0x0,  0x16, 0x6D, 0x60, 0x0, 0x1,
                                      0x27, 0x10, 0x3A, 0x98, 0x0,  0x0,  0x0, 0x0};
u8 D_80805460_chdragonbrothers[20] = {0x0, 0x13, 0x6, 0x1, 0x0,  0xD,  0x0,  0xF3, 0x1, 0xC,
                                      0x0, 0x18, 0x0, 0x1, 0x13, 0x88, 0x27, 0x10, 0x0, 0x0};
u8 D_80805474_chdragonbrothers[20] = {0x0, 0x13, 0x6, 0x3, 0x0,  0xD,  0x0,  0xF3, 0x1, 0xC,
                                      0x0, 0x18, 0x0, 0x1, 0x13, 0x88, 0x27, 0x10, 0x0, 0x0};
int D_80805488_chdragonbrothers[4] = {0x1304CC, 0x162EE0, 0x109C4, 0x13880000};
u8 D_80805498_chdragonbrothers[192] = {
    0x0,  0x0,  0x0,  0x0,  0x0, 0x0,  0x0, 0x0,  0x41, 0x40, 0x0,  0x0,  0x4, 0xB6, 0x0, 0x1,
    0x41, 0x40, 0x0,  0x0,  0x4, 0xB6, 0x0, 0x1,  0x3F, 0x80, 0x0,  0x0,  0x3, 0x44, 0x0, 0x44,
    0x41, 0x40, 0x0,  0x0,  0x4, 0xB6, 0x0, 0x1,  0x40, 0xA4, 0x0,  0x0,  0x3, 0x44, 0x0, 0x42,
    0x41, 0x40, 0x0,  0x0,  0x4, 0xB6, 0x0, 0x1,  0x3F, 0x95, 0x60, 0x42, 0x3, 0x5C, 0x0, 0x41,
    0x3F, 0xA5, 0x3F, 0x7D, 0x3, 0x34, 0x0, 0x42, 0x3F, 0x95, 0x60, 0x42, 0x3, 0x5C, 0x0, 0x41,
    0x3F, 0x95, 0x60, 0x42, 0x3, 0x5C, 0x0, 0x41, 0x3F, 0x55, 0x3F, 0x7D, 0x3, 0x35, 0x0, 0x42,
    0x3F, 0x55, 0x3F, 0x7D, 0x3, 0x35, 0x0, 0x2,  0x3F, 0x55, 0x3F, 0x7D, 0x3, 0x36, 0x0, 0x41,
    0x3F, 0x85, 0x1E, 0xB8, 0x3, 0x42, 0x0, 0x42, 0x41, 0x40, 0x0,  0x0,  0x3, 0x46, 0x0, 0x41,
    0x3F, 0xA8, 0x72, 0xB0, 0x3, 0x43, 0x0, 0x42, 0x3F, 0x28, 0xF5, 0xC3, 0x3, 0x37, 0x0, 0x41,
    0x3F, 0x11, 0xEB, 0x85, 0x3, 0x47, 0x0, 0x42, 0x40, 0x4E, 0xB8, 0x52, 0x3, 0x51, 0x0, 0x42,
    0x41, 0x34, 0xCC, 0xCD, 0x3, 0x52, 0x0, 0x42, 0x41, 0x1A, 0xB8, 0x52, 0x3, 0x53, 0x0, 0x41,
    0x40, 0x40, 0x0,  0x0,  0x3, 0x5F, 0x0, 0x42, 0x3F, 0x7,  0xAE, 0x14, 0x3, 0x38, 0x2, 0x41};
u32 D_80805558_chdragonbrothers[6] = {0x130604, 0xD00F3, 0x10C0016, 0x7FFF0001, 0x1F402710, 0x0};
f32 D_80805570_chdragonbrothers[3] = {0.0f, 0.0f, 3.1e+03f};
f32 D_8080557C_chdragonbrothers[3] = {0.0f, 2.5e+02f, 0.0f};
u8 D_80805588_chdragonbrothers[56] = {
    0x0, 0x1D, 0x9, 0xCE, 0x0,  0x16, 0x12, 0x0,  0x0, 0x32, 0x0, 0x2,  0x0, 0x15,
    0x0, 0x0,  0x0, 0x99, 0x0,  0x22, 0x1,  0x99, 0x2, 0x0,  0x1, 0x33, 0x1, 0x99,
    0x0, 0x2B, 0x0, 0xA6, 0x0,  0xA6, 0x0,  0x1B, 0x1, 0x2C, 0x2, 0x58, 0x0, 0x18,
    0x0, 0x0,  0x0, 0x0,  0x19, 0x0,  0x19, 0x0,  0x0, 0x17, 0x0, 0x80, 0x0, 0x0};
u8 D_808055C0_chdragonbrothers[28] = {0x0,  0x13, 0x4,  0x83, 0x2,  0x6,  0x0, 0x7,  0x0, 0x16,
                                      0x46, 0x50, 0x0,  0xE,  0x1,  0x33, 0x1, 0x70, 0x1, 0x80,
                                      0x0,  0x1,  0x13, 0x88, 0x1D, 0x4C, 0x0, 0x0};
u8 D_808055DC_chdragonbrothers[44] = {
    0x0,  0x1D, 0x9,  0xDD, 0x0, 0x16, 0x12, 0x0,  0x0,  0x15, 0x0,  0x0, 0x0,  0x4C, 0x0,
    0x22, 0x1,  0x99, 0x2,  0x0, 0x1,  0x33, 0x1,  0x99, 0x0,  0x2B, 0x0, 0x40, 0x0,  0xA6,
    0x0,  0x1B, 0x1,  0x2C, 0x2, 0x58, 0x0,  0x17, 0x0,  0x80, 0x0,  0x0, 0x0,  0x0};
Vec3f D_80805608_chdragonbrothers = {0.0f, 1.5e+03f, 1.4e+02f};
Vec3f D_80805614_chdragonbrothers = {0.0f, 0.0f, 3.1e+03f};
u8 D_80805620_chdragonbrothers[16] = {0x43, 0x96, 0x0, 0x0, 0x43, 0xAF, 0x0, 0x0,
                                      0x43, 0x7A, 0x0, 0x0, 0x42, 0x48, 0x0, 0x0};
u8 D_80805630_chdragonbrothers[16] = {0x43, 0xAF, 0x0, 0x0, 0x43, 0x48, 0x0, 0x0,
                                      0x43, 0x48, 0x0, 0x0, 0x42, 0x48, 0x0, 0x0};
u8 D_80805640_chdragonbrothers[16] = {0x44, 0x48, 0x0, 0x0, 0x43, 0x7A, 0x0,  0x0,
                                      0x43, 0x7A, 0x0, 0x0, 0x44, 0x22, 0x80, 0x0};
u8 D_80805650_chdragonbrothers[12] = {0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x45, 0x39, 0x0, 0x0};
u8 D_8080565C_chdragonbrothers[12] = {0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x45, 0x39, 0x0, 0x0};
u8 D_80805668_chdragonbrothers[16] = {0x3D, 0x4C, 0xCC, 0xCD, 0x3E, 0x4C, 0xCC, 0xCD,
                                      0x3E, 0x8A, 0x3D, 0x71, 0xBF, 0x80, 0x0,  0x0};
u8 D_80805678_chdragonbrothers[28] = {0x0,  0x13, 0x6,  0x2,  0x2,  0x6,  0x0, 0x7, 0x0, 0x16,
                                      0x46, 0x50, 0x0,  0xE,  0x0,  0xF3, 0x1, 0xC, 0x0, 0x40,
                                      0x0,  0x1,  0x13, 0x88, 0x1D, 0x4C, 0x0, 0x0};
u8 D_80805694_chdragonbrothers[20] = {0x3C, 0xF5, 0xC2, 0x8F, 0x3E, 0x9E, 0xB8, 0x52, 0x3F, 0x11,
                                      0xEB, 0x85, 0x3F, 0x54, 0x7A, 0xE1, 0xBF, 0x80, 0x0,  0x0};
int D_808056A8_chdragonbrothers[18] = {0x2E0377,
                                       0x7FC0003,
                                       (u32) &D_80805498_chdragonbrothers,
                                       (u32) func_80802574_chdragonbrothers,
                                       (u32) func_80105834,
                                       (u32) func_808034DC_chdragonbrothers,
                                       0x0,
                                       0x0,
                                       0x0,
                                       0x8056C,
                                       (u32) func_808003D8_chdragonbrothers,
                                       (u32) func_80108EE8,
                                       0x680000,
                                       (u32) func_80800070_chdragonbrothers,
                                       (u32) func_80107C2C,
                                       -0x7FDFFFFE,
                                       (u32) func_80801D40_chdragonbrothers,
                                       0x0};
u8 D_808056F0_chdragonbrothers[80] = {
    0x0,  0x0,  0x0, 0x0, 0x0, 0x0,  0x0, 0x0,  0x3F, 0x70, 0x0,  0x0,  0x3, 0x32, 0x0, 0x44,
    0x3F, 0x70, 0x0, 0x0, 0x3, 0x32, 0x0, 0x44, 0x3F, 0x70, 0x0,  0x0,  0x3, 0x32, 0x0, 0x4A,
    0x3F, 0x0,  0x0, 0x0, 0x3, 0x33, 0x0, 0x44, 0x3E, 0x19, 0x99, 0x9A, 0x3, 0x33, 0x0, 0x2,
    0x3F, 0x70, 0x0, 0x0, 0x3, 0x32, 0x0, 0x92, 0x3F, 0x70, 0x0,  0x0,  0x3, 0x32, 0x0, 0x92,
    0x3F, 0x70, 0x0, 0x0, 0x3, 0x32, 0x0, 0x44, 0x3F, 0x70, 0x0,  0x0,  0x3, 0x32, 0x0, 0x44};
Vec3f D_80805740_chdragonbrothers = {0.0f, 264.0f, -118.0f};
int D_8080574C_chdragonbrothers[18] = {0x2F0378,
                                       0x8010001,
                                       (u32) &D_808056F0_chdragonbrothers,
                                       (u32) func_808038AC_chdragonbrothers,
                                       (u32) func_80105834,
                                       (u32) func_80803EFC_chdragonbrothers,
                                       0x0,
                                       0x0,
                                       0x0,
                                       0x80C44,
                                       (u32) func_808036E4_chdragonbrothers,
                                       (u32) func_80108ED0,
                                       0x0,
                                       (u32) func_80803574_chdragonbrothers,
                                       (u32) func_80107C2C,
                                       0x0,
                                       (u32) func_80803DC4_chdragonbrothers,
                                       0x0};
u8 D_80805794_chdragonbrothers[20] = {0x0, 0x13, 0x5, 0xB8, 0x0, 0x18, 0x0, 0x1,  0x4, 0xE2,
                                      0x9, 0xC4, 0x0, 0xD,  0x1, 0x33, 0x1, 0x4C, 0x0, 0x0};
u8 D_808057A8_chdragonbrothers[56] = {
    0x0, 0x1D, 0x9, 0xCE, 0x0,  0x16, 0x12, 0x0,  0x0, 0x32, 0x0, 0x2,  0x0, 0x15,
    0x0, 0x0,  0x0, 0x99, 0x0,  0x22, 0x1,  0x99, 0x2, 0x0,  0x1, 0x33, 0x1, 0x99,
    0x0, 0x2B, 0x0, 0xA6, 0x0,  0xA6, 0x0,  0x1B, 0x1, 0x2C, 0x1, 0x2C, 0x0, 0x18,
    0x0, 0x0,  0x0, 0x0,  0x19, 0x0,  0x19, 0x0,  0x0, 0x17, 0x0, 0x80, 0x0, 0x0};
u8 D_808057E0_chdragonbrothers[48] = {
    0x0, 0x1D, 0x9, 0xDD, 0x0, 0x16, 0x12, 0x0,  0x0, 0x32, 0x0, 0x2,  0x0, 0x15, 0x0, 0x0,
    0x0, 0x99, 0x0, 0x22, 0x1, 0x99, 0x2,  0x0,  0x1, 0x33, 0x1, 0x99, 0x0, 0x2B, 0x0, 0xA6,
    0x0, 0xA6, 0x0, 0x1B, 0x1, 0x2C, 0x1,  0x2C, 0x0, 0x17, 0x0, 0x80, 0x0, 0x0,  0x0, 0x0};
u8 D_80805810_chdragonbrothers[48] = {
    0x0,  0x1D, 0x9, 0xE0, 0x0,  0x16, 0x12, 0x0,  0x0, 0xE,  0x0, 0x60, 0x0, 0x60, 0x0, 0x15,
    0x0,  0x19, 0x0, 0x99, 0x0,  0x22, 0x1,  0x0,  0x1, 0x0,  0x0, 0x66, 0x0, 0x66, 0x0, 0x27,
    0xFE, 0x70, 0x1, 0x90, 0xFC, 0xE0, 0x3,  0x20, 0x0, 0x2B, 0x0, 0x4C, 0x0, 0x99, 0x0, 0x0};
u8 D_80805840_chdragonbrothers[48] = {
    0x0, 0x1D, 0x9, 0xDD, 0x0, 0x16, 0x12, 0x0,  0x0, 0xE,  0x0, 0x32, 0x0, 0x96, 0x0, 0x15,
    0x0, 0x40, 0x0, 0xA6, 0x0, 0x22, 0x1,  0x99, 0x2, 0x0,  0x1, 0x33, 0x1, 0x99, 0x0, 0x2B,
    0x0, 0x40, 0x1, 0xC,  0x0, 0x17, 0x0,  0x80, 0x0, 0x2D, 0x0, 0x64, 0x1, 0x2C, 0x0, 0x0};
u8 D_80805870_chdragonbrothers[56] = {
    0x0, 0x1D, 0x9, 0xDD, 0x0, 0x16, 0x12, 0x0,  0x0,  0xE,  0x0, 0x32, 0x0, 0x96,
    0x0, 0x15, 0x0, 0x40, 0x0, 0xA6, 0x0,  0x22, 0x1,  0x99, 0x2, 0x0,  0x1, 0x33,
    0x1, 0x99, 0x0, 0x2B, 0x0, 0x40, 0x1,  0xC,  0x0,  0x17, 0x0, 0x80, 0x0, 0x2D,
    0x0, 0x64, 0x1, 0x2C, 0x0, 0x1F, 0x40, 0x40, 0x40, 0x0,  0x0, 0x0,  0x0, 0x0};
void *D_808058A8_chdragonbrothers = (void *) 0x00300379;
static u32 D_808058A8_chdragonbrothers_rest[17] = {0x8150001,
                                                   0x0,
                                                   (u32) func_808040A8_chdragonbrothers,
                                                   (u32) func_80105834,
                                                   (u32) func_80804318_chdragonbrothers,
                                                   0x0,
                                                   0x3F800000,
                                                   0x0,
                                                   0x1004,
                                                   (u32) func_808040A0_chdragonbrothers,
                                                   (u32) func_80108EE8,
                                                   0x0,
                                                   (u32) func_80803F4C_chdragonbrothers,
                                                   (u32) func_80107C2C,
                                                   0x0,
                                                   (u32) func_80804350_chdragonbrothers,
                                                   0x0};
s16 D_808058F0_chdragonbrothers[8] = {0x0, 0x9D7, 0x9C1, 0x9C0, 0x9C2, 0x9C3, 0x9C4, 0x0};
u8 D_80805900_chdragonbrothers[24] = {0x0,  0x13, 0x4,  0x7,  0x0,  0xD,  0x1, 0x26,
                                      0x1,  0x40, 0x0,  0x16, 0x46, 0x50, 0x0, 0x1,
                                      0x27, 0x10, 0x3A, 0x98, 0x0,  0x0,  0x0, 0x0};
int D_80805918_chdragonbrothers[18] = {
    0x710001D, 0x9D60015, 0x20099, 0x160200, 0x1E0032, 0x32000E,  0x6E0078, 0x260000, 0xFF9C,
    0x0,       0x640019,  0x10001, 0x220099, 0xCC0199, 0x200002A, 0xA000A,  0x80008C, 0xF0000};
int D_80805960_chdragonbrothers[18] = {
    0x510001D, 0x9D60015, 0x20099, 0x160200, 0x1E0032, 0x32000E,  0x1E003C, 0x260000, 0xFF9C,
    0x0,       0x640019,  0x0,     0x220099, 0xCC0200, 0x2CC002A, 0x80008,  0x660066, 0xF0000};
int D_808059A8_chdragonbrothers[12] = {0x110001D, 0x9D60015, 0x200CC,  0x160200,
                                       0x1E0032,  0x320019,  0x0,      0x2200CC,
                                       0xCC0380,  0x380002B, 0x590059, 0x11A0000};
int D_808059D8_chdragonbrothers[5] = {0x130413, 0x166590, 0xD00F3, 0x10C0002, 0x0};
u8 D_808059EC_chdragonbrothers[28] = {0x0,  0x13, 0x4,  0x83, 0x2,  0x6,  0x0, 0x7,  0x0, 0x16,
                                      0x46, 0x50, 0x0,  0xE,  0x1,  0x33, 0x1, 0x70, 0x1, 0x80,
                                      0x0,  0x1,  0x13, 0x88, 0x1D, 0x4C, 0x0, 0x0};
s32 D_80805A08_chdragonbrothers[18] = {0x31037A,
                                       0x9D70001,
                                       0x0,
                                       (u32) func_80804AA4_chdragonbrothers,
                                       (u32) func_80105834,
                                       (u32) func_80804C90_chdragonbrothers,
                                       0x0,
                                       0x3F800000,
                                       0x0,
                                       0x404,
                                       (u32) func_808048A4_chdragonbrothers,
                                       0x0,
                                       0x140000,
                                       (u32) func_8080449C_chdragonbrothers,
                                       (u32) func_80107C2C,
                                       -0x7FFFFFFE,
                                       (u32) func_80804C6C_chdragonbrothers,
                                       0x0};
s32 D_80805A50_chdragonbrothers[3] = {0x43CF0000, -0x3C1A0000, 0x45548000};
int D_80805A5C_chdragonbrothers[21] = {0x33037B,
                                       0x8D80003,
                                       0x0,
                                       (u32) func_80804E1C_chdragonbrothers,
                                       (u32) func_80105834,
                                       (u32) func_80101870,
                                       0x0,
                                       0x0,
                                       0x0,
                                       0xA0C04,
                                       (u32) func_80804DB0_chdragonbrothers,
                                       0x0,
                                       0x0,
                                       (u32) func_80804CD0_chdragonbrothers,
                                       (u32) func_80107C2C,
                                       -0x7FFFF7FE,
                                       0x0,
                                       0x0,
                                       0x0,
                                       0x0,
                                       0x0};
