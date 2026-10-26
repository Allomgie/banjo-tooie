#include "common.h"

#define DINO_MOTHER_ANIMATION_TYPE
extern s32 func_800DA298(s32);
extern void func_800EE7F8(f32 *, f32 *);
typedef struct { f32 local_0[3]; } DinoMotherVector;
extern DinoMotherVector D_808013EC_chdinofamilymother;
extern DinoMotherVector D_808013F8_chdinofamilymother;
extern void func_8010C93C(Actor *, f32 *, f32);
extern int D_80801474_chdinofamilymother[];
extern s32 D_80801398_chdinofamilymother;
extern s16 D_8080139C_chdinofamilymother[];
extern s32 D_808013B4_chdinofamilymother;
extern s16 D_808013B8_chdinofamilymother[];
extern s32 func_800F5410(s32);
extern s32 func_800F54E4(void);
extern s32 _subaddiedialog_entrypoint_7(Actor *, void *, void *);
extern s32 _subaddiedialog_entrypoint_4(f32 *, s32, s32);
extern void _subaddiedialog_entrypoint_11(Unk80132ED0 *, s32, s32, void *, s32);
typedef struct { u16 local_0; u16 local_1; f32 local_2; } DinoMotherAnimation;
extern void func_800DF744(s32, s32);
extern void _gcdialogcamera_entrypoint_4(f32 *);
extern void _gcdialogcamera_entrypoint_3(f32 *, f32);
extern s32 _gcdialogcamera_entrypoint_0(s32, s32);
extern s32 func_80101E14(Actor *, f32);
extern f32 func_800DC0C0(void);
extern f32 func_800DC178(f32, f32);
extern s32 func_800B53A4(s32);
extern s32 func_800BABB8(s32, f32 *, f32 *, f32, void *);
extern s32 func_800BBCB8(f32 *, s32, f32, s32, void *);
extern void func_800BA670(s32, s32);
extern void func_800BAA60(s32, f32 *, s32, s32);
extern void func_800BA1D0(s32, f32 *, f32 *, s32);
extern void func_800BA22C(s32, s32);
extern void func_800BA930(s32, s32, s32, s32, s32, s32, s32);
extern void func_800BA450(s32, s32, s32, s32, s32, s32, s32);
extern s32 func_800BEF00(f32 *, f32 *, f32 *, s32);
extern void func_800C4140(s32, f32 *, s32);
extern void _subaddieskeleton_entrypoint_0(Actor *, s32, f32 *);
void func_808005EC_chdinofamilymother();
void func_8080096C_chdinofamilymother();
extern void func_801018A4(), func_80105834(), func_80107C2C(), func_80800000_chdinofamilymother(), func_808000A0_chdinofamilymother();
extern u8 D_80801340_chdinofamilymother[];

void func_80800000_chdinofamilymother(param_0) u8 *param_0; {
    if (_glcutDll_entrypoint_20() != 0) {
        func_808005EC_chdinofamilymother(param_0, 0xA);
    } else if ((func_800DA298(0x15E) != 0) && (func_800DA298(0x189) == 0) && (func_800DA298(0x15F) != 0) && (func_800DA298(0x8A) != 0)) {
        func_808005EC_chdinofamilymother(param_0, 9);
    }
    func_800EE7F8(param_0 + 0x18, param_0 + 4);
    (*(s32 *)((s8 *)(param_0) + (0x34))) = 0;
    (*(f32 *)((s8 *)(param_0) + (0x1C))) = 0.0f;
}

void func_8080119C_chdinofamilymother();

void func_808008E4_chdinofamilymother();

void func_808000A0_chdinofamilymother(param_0) Actor *param_0;
{

    switch (param_0->unk70_10) {
        case 1:
            if (func_800DA298(0x8A)) {
                if (func_800F5410(func_800F54E4()) == 11) {
                    D_808013B8_chdinofamilymother[0] = 0x1814;
                }
                if (_subaddiedialog_entrypoint_7(param_0, param_0->actorData, &D_808013B4_chdinofamilymother)) {
                    func_8080119C_chdinofamilymother(param_0, 2, 0, 0);
                }
            } else {
                switch (func_800F5410(func_800F54E4())) {
                    case 10: D_8080139C_chdinofamilymother[0] = 0x1812; break;
                    case 11: D_8080139C_chdinofamilymother[0] = 0x1813; break;
                }
                if (_subaddiedialog_entrypoint_7(param_0, param_0->actorData, &D_80801398_chdinofamilymother)) {
                    func_8080119C_chdinofamilymother(param_0, 2, 0, 0);
                }
            }
            break;
        case 2:
        case 3:
        case 4:
        case 5:
        case 6:
        case 7:
        case 8:
            break;
        case 9:
            if (_subaddiedialog_entrypoint_4((f32 *)param_0->actorData, 0x4B0, 0)) {
                _subaddiedialog_entrypoint_11(param_0->unk0, 0x17C6, 12, param_0->actorData, 0x65);
            }
            break;
    }
    func_808008E4_chdinofamilymother(param_0);
    func_8080096C_chdinofamilymother(param_0);
}

s32 func_80800218_chdinofamilymother(Actor *param_0, s32 param_1, s32 param_2)
{
    extern DinoMotherAnimation D_80801344_chdinofamilymother[];
    extern f32 D_808013D0_chdinofamilymother[3];
    extern f32 D_808013DC_chdinofamilymother[3];

    switch (param_1) {
    case 0x1F:
        func_801015D0(param_0);
        if (D_80801344_chdinofamilymother[param_0->unk70_10].local_0 != 0x3AC) {
            func_800DF744(2, 1);
            func_800DF744(3, 2);
        } else {
            func_800DF744(3, 1);
        }
        return 1;
    case 0x2E:
        switch (*(s16 *)&param_2) {
        case 0x17BA:
        case 0x17BB:
        case 0x1812:
        case 0x1813:
        case 0x1814:
            func_808005EC_chdinofamilymother(param_0, 2);
            break;
        case 0x17BC:
        case 0x1815:
            func_808005EC_chdinofamilymother(param_0, 3);
            break;
        case 0x17BD:
            func_808005EC_chdinofamilymother(param_0, 4);
            break;
        case 0x17BE:
        case 0x1816:
        case 0x1817:
            func_808005EC_chdinofamilymother(param_0, 5);
            break;
        case 0x17BF:
        case 0x17C0:
            func_808005EC_chdinofamilymother(param_0, 1);
            break;
        case 0x17C1:
        case 0x180A:
            func_808005EC_chdinofamilymother(param_0, 7);
            break;
        case 0x17C2:
        case 0x17C6:
        case 0x1818:
            func_808005EC_chdinofamilymother(param_0, 9);
            if (_glcutDll_entrypoint_23()) {
                _glcutDll_entrypoint_17();
            }
            break;
        case 0x1208:
            func_80801228_chdinofamilymother(param_0);
            break;
        case 0x17C3:
        case 0x17C4:
        case 0x17C5:
            func_808005EC_chdinofamilymother(param_0, 1);
            break;
        default:
            func_80801228_chdinofamilymother(param_0);
            break;
        }
        return 1;
    case 0xB:
        switch (param_2) {
        case 9:
            func_808005EC_chdinofamilymother(param_0, 9);
            break;
        case 0:
        case 2:
        case 4:
            func_8080119C_chdinofamilymother(param_0, 2, 1, 0);
            break;
        }
        return 4;
    case 0x52:
        _gcdialogcamera_entrypoint_4(D_808013D0_chdinofamilymother);
        _gcdialogcamera_entrypoint_3(D_808013DC_chdinofamilymother, param_0->scale);
        return 3;
    case 0x57:
        {
            s32 local_0 = param_2 & 0xFFFF;
            s32 local_1 = (param_2 & 0xFFFF0000) >> 16;
            if (_gcdialogcamera_entrypoint_0(local_0, local_1)) {
                func_8080119C_chdinofamilymother(param_0, local_0, local_1, 0);
                return 2;
            }
        }
        return 1;
    case 0x33:
        if (func_800DA298(0x15E) && !func_800DA298(0x189) &&
            func_800DA298(0x15F) && func_800DA298(0x8A)) {
            func_808005EC_chdinofamilymother(param_0, 6);
        } else {
            func_808005EC_chdinofamilymother(param_0, 8);
            switch (param_2) {
            case 0:
                _subaddiedialog_entrypoint_11(param_0->unk0, 0x17C3, 12,
                    param_0->actorData, 0x65);
                break;
            case 1:
                _subaddiedialog_entrypoint_11(param_0->unk0, 0x17C4, 12,
                    param_0->actorData, 0x65);
                func_8080119C_chdinofamilymother(param_0, 3, 1, 0x2000);
                break;
            case 2:
                _subaddiedialog_entrypoint_11(param_0->unk0, 0x17C5, 12,
                    param_0->actorData, 0x65);
                break;
            }
        }
        return 1;
    }
    return 0;
}

void func_80801118_chdinofamilymother();

void func_808005EC_chdinofamilymother(param_0, param_1) Actor *param_0; s32 param_1;
{
    s32 local_0;

    switch (param_1) {
    case 1:
        func_80801228_chdinofamilymother(param_0);
        break;
    case 2:
        if (_subaddiefind_entrypoint_2(0x52D, 0) || _subaddiefind_entrypoint_2(0x291, 0)) {
            func_80801118_chdinofamilymother((s32 *)param_0, (s32)param_0->unk0, 0, 0x10);
            if (func_800F5410(func_800F54E4()) == 10) {
                _subaddiedialog_entrypoint_11(param_0->unk0, 0x1815, 0xC, param_0->actorData, 0x65);
            } else {
                _subaddiedialog_entrypoint_11(param_0->unk0, 0x17BC, 0xC, param_0->actorData, 0x65);
            }
            func_80101180(0x291, 0x37, 0);
            break;
        }
    case 3:
        param_1 = 3;
        if (!func_800DA298(0x15F)) {
            _subaddiedialog_entrypoint_11(param_0->unk0, 0x17BD, 0xC, param_0->actorData, 0x65);
            func_80801118_chdinofamilymother((s32 *)param_0, (s32)param_0->unk0, 2, 0x10);
            break;
        }
    case 4:
        param_1 = 4;
        if (!func_800DA298(0x8A)) {
            switch (func_800F5410(func_800F54E4())) {
            case 1:
                local_0 = 0x17BE;
                break;
            case 10:
                local_0 = 0x1816;
                break;
            case 11:
                local_0 = 0x1817;
                break;
            }
            _subaddiedialog_entrypoint_11(param_0->unk0, local_0, 0xC, param_0->actorData, 0x65);
            func_80801118_chdinofamilymother((s32 *)param_0, (s32)param_0->unk0, 4, 0x10);
            break;
        }
    case 5:
        _subaddiedialog_entrypoint_11(param_0->unk0, 0x17BF, 0xC, param_0->actorData, 0x65);
        break;
    case 6:
        _subaddiedialog_entrypoint_11(param_0->unk0, 0x17C1, 0xC, param_0->actorData, 0x65);
        func_80801118_chdinofamilymother((s32 *)param_0, (s32)param_0->unk0, 0x1D, 0x30);
        break;
    case 7:
        if (func_800F64A4(func_800F54E4(), 0x1000)) {
            func_800D1000(0x2B, 1, 0, 1, 0);
            func_80801118_chdinofamilymother((s32 *)param_0, (s32)param_0->unk0, 9, 0x10);
            _subaddiedialog_entrypoint_11(param_0->unk0, 0x1818, 0xC, param_0->actorData, 0x65);
        } else {
            func_800D0C78(0x2B, 1, 0);
            _subaddiedialog_entrypoint_11(param_0->unk0, 0x17C2, 0xC, param_0->actorData, 0x65);
        }
        break;
    case 9:
        func_80801228_chdinofamilymother(param_0);
        break;
    }
    func_80102424(param_0, param_1);
}

void func_808008E4_chdinofamilymother(Actor *param_0)
{
    DinoMotherVector local_0 = D_808013EC_chdinofamilymother;
    DinoMotherVector local_1 = D_808013F8_chdinofamilymother;
    func_8010C93C(param_0, local_0.local_0, 0.1f);
    func_8010C93C(param_0, local_1.local_0, 0.3f);
}

void func_8080096C_chdinofamilymother(param_0) Actor *param_0;
{
    extern DinoMotherAnimation D_80801344_chdinofamilymother[];
    extern u8 D_80801404_chdinofamilymother[];
    extern u8 D_80801440_chdinofamilymother[];

    if (D_80801344_chdinofamilymother[param_0->unk70_10].local_0 == 0x3AC) {
        if (func_80101E14(param_0, 0.23f) ||
            func_80101E14(param_0, 0.57f) ||
            func_80101E14(param_0, 0.79f) ||
            func_80101E14(param_0, 0.94f) ||
            func_80101E14(param_0, 0.99f)) {
            f32 local_0[3];
            f32 local_1[3];
            s32 local_13;
            s32 local_14;

            local_13 = func_800B53A4(2);
            local_14 = func_800B53A4(3);

            _subaddieskeleton_entrypoint_0(
                param_0,
                0x35,
                local_0
            );

            _subaddieskeleton_entrypoint_0(
                param_0,
                0x37,
                local_1
            );

            func_800BABB8(
                local_13,
                local_0,
                0,
                1.0f,
                D_80801404_chdinofamilymother
            );

            func_800BA1D0(
                local_13,
                local_0,
                local_1,
                2
            );

            local_1[1] -= 50.0f;

            func_800BA670(local_14, func_800DC0C0() < 0.5f ? 0x8A2 : 0x8A3);

            func_800BAA60(
                local_14,
                local_1,
                100,
                200
            );

            local_1[1] += 50.0f;

            func_800BABB8(
                local_14,
                local_1,
                0,
                1.0f,
                D_80801440_chdinofamilymother
            );

            func_800BA22C(local_14, 3);

            func_800C4140(
                0x59957C4B,
                local_1,
                0x0BB80190
            );
        }

        if (func_80101E14(param_0, 0.92f)) {
            f32 local_2[3];
            f32 local_3[3];
            f32 local_4[3];
            s32 local_13;

            local_13 = func_800B53A4(6);

            _subaddieskeleton_entrypoint_0(
                param_0,
                0x10,
                local_2
            );

            func_800EE7F8(local_3, local_2);
            local_3[1] -= 300.0f;

            func_800BEF00(
                local_2,
                local_3,
                local_4,
                0
            );

            func_800BA670(local_13, func_800DC0C0() < 0.5f ? 0x8A2 : 0x8A3);

            func_800BA930(
                local_13,
                -350,
                150,
                -200,
                -300,
                200,
                -150
            );

            func_800BA450(
                local_13,
                100,
                -100,
                50,
                175,
                -200,
                100
            );

            func_800BABB8(
                local_13,
                local_3,
                0,
                1.0f,
                D_80801440_chdinofamilymother
            );

            func_800BA22C(local_13, 6);

            func_800BBCB8(
                local_3,
                0,
                1.0f,
                3,
                D_80801404_chdinofamilymother
            );

            func_800C4140(
                0x4CAEA44B,
                local_3,
                0x0BB80190
            );
        } else if (func_80101E14(param_0, 0.1f) ||
                   func_80101E14(param_0, 0.18f) ||
                   func_80101E14(param_0, 0.25f)) {
            f32 local_5[3];
            f32 local_6[3];
            f32 local_7[3];

            _subaddieskeleton_entrypoint_0(
                param_0,
                0x10,
                local_5
            );

            func_800EE7F8(local_6, local_5);
            local_6[1] -= 300.0f;

            func_800BEF00(
                local_5,
                local_6,
                local_7,
                0
            );

            func_800BBCB8(
                local_6,
                0,
                1.0f,
                1,
                D_80801404_chdinofamilymother
            );

            func_800C4140(
                0x4CAEA44B,
                local_6,
                0x0BB80190
            );
        }

        if (func_80101E14(param_0, 0.42f)) {
            f32 local_8[3];

            _subaddieskeleton_entrypoint_0(
                param_0,
                0x2B,
                local_8
            );

            func_800C4140(
                ((u16)(u32)(func_800DC178(0.45f, 0.55f) * 1023.0f) << 21) + 0xBBCCA,
                local_8,
                0x0BB80190
            );
        }

        if (func_80101E14(param_0, 0.772f)) {
            f32 local_9[3];

            _subaddieskeleton_entrypoint_0(
                param_0,
                0x2B,
                local_9
            );

            func_800C4140(
                ((u16)(u32)(func_800DC178(0.75f, 0.85f) * 1023.0f) << 21) + 0xBBCCA,
                local_9,
                0x0BB80190
            );
        }
    } else {
        if (func_80101E14(param_0, 0.025f) ||
            func_80101E14(param_0, 0.19f) ||
            func_80101E14(param_0, 0.36f) ||
            func_80101E14(param_0, 0.52f) ||
            func_80101E14(param_0, 0.7f) ||
            func_80101E14(param_0, 0.85f)) {
            f32 local_10[3];

            _subaddieskeleton_entrypoint_0(
                param_0,
                0x37,
                local_10
            );

            func_800BBCB8(
                local_10,
                0,
                1.0f,
                1,
                D_80801404_chdinofamilymother
            );

            func_800C4140(
                0x4CB57C4B,
                local_10,
                0x0BB80190
            );
        }

        if (func_80101E14(param_0, 0.5f) ||
            func_80101E14(param_0, 0.7f)) {
            f32 local_11[3];
            f32 local_12[3];
            f32 local_16[3];
            s32 local_13;

            local_13 = func_800B53A4(6);

            _subaddieskeleton_entrypoint_0(
                param_0,
                0x10,
                local_11
            );

            func_800EE7F8(local_12, local_11);
            local_12[1] -= 300.0f;

            func_800BEF00(
                local_11,
                local_12,
                local_16,
                0
            );

            func_800BA930(
                local_13,
                150,
                150,
                300,
                200,
                200,
                350
            );

            func_800BA450(
                local_13,
                -50,
                -100,
                -100,
                -100,
                -200,
                -175
            );

            func_800BABB8(
                local_13,
                local_12,
                0,
                1.0f,
                D_80801440_chdinofamilymother
            );

            func_800BA22C(local_13, 6);

            func_800BBCB8(
                local_12,
                0,
                1.0f,
                1,
                D_80801404_chdinofamilymother
            );

            func_800C4140(
                0x3FEDAC11,
                local_12,
                0x0BB80190
            );
        }
    }
}

void func_80801118_chdinofamilymother(s32 *param_0, s32 param_1, s32 param_2, s32 param_3)
{
    switch (param_0[13]) {
    case 0:
        _capod_entrypoint_2(param_0[0], 0x27, param_3 | 0x10);
    case 1:
        param_0[13] = 2;
    case 2:
        _capod_entrypoint_6(param_1, param_2, param_3);
        break;
    }
}

void func_8080119C_chdinofamilymother(Actor *param_0, s32 param_1, s32 param_2, u32 param_3)
{
    s32 val;

    val = *(s32 *)((s8 *)param_0 + 0x34);
    switch (val) {
    case 0:
        _capod_entrypoint_2(*(s32 *)((s8 *)param_0 + 0), 0x27, param_3 | 0x10);
    case 2:
        _capod_entrypoint_8(1);
        *(s32 *)((s8 *)param_0 + 0x34) = 1;
        _gcdialogcamera_entrypoint_6(*(s32 *)((s8 *)param_0 + 0));
        _gcdialogcamera_entrypoint_8();
    case 1:
        _capod_entrypoint_7(param_1, param_2);
        return;
    }
}

int func_80801228_chdinofamilymother(Actor *param_0)
{
  s32 *field_0x34 = (s32 *)((char *)param_0 + 0x34);
  if (*field_0x34) {
        _capod_entrypoint_3(0, param_0);
        *field_0x34 = 0;
    }
}

void *chdinofamilymother_entrypoint_0()
{
    return &D_80801474_chdinofamilymother;
}

/* TU-NOTE: the .data of this overlay (formerly asm/data/overlays/ch/dino/familymother.data.s) is defined here in C --
 * tables holding function pointers must be in the same unit, otherwise IDO's assembler schedules those functions differently.
 * extern views adjusted to the object (address-neutral): D_8080139C_chdinofamilymother -> s16[] (used as NAME[0]), D_808013B8_chdinofamilymother -> s16[] (used as NAME[0]), D_80801474_chdinofamilymother -> int[] */
u8 D_80801340_chdinofamilymother[4] = { 0x0, 0x0, 0x0, 0x0 };
DinoMotherAnimation D_80801344_chdinofamilymother[10] = { 0x0, 0x0, 7.0f, 0x3AC, 0x1, 7.0f, 0x3AC, 0x1, 7.0f, 0x3AC, 0x1, 7.0f, 0x3AC, 0x1, 7.0f, 0x3AC, 0x1, 7.0f, 0x3AD, 0x1, 7.0f, 0x3AD, 0x1, 7.0f, 0x3AD, 0x1, 7.0f, 0x3AD, 0x1, 7.0f };
static u32 D_80801344_chdinofamilymother_rest[1] = { 0x3AD0001 };
s32 D_80801398_chdinofamilymother = 0x15D04B0;
s16 D_8080139C_chdinofamilymother[12] = { 0x17BA, 0x17C0, 0x0, 0x601, 0x120B, 0x0, 0x65, 0x0, 0xC, 0x203C, 0x0, 0x0 };
s32 D_808013B4_chdinofamilymother = 0x15D04B0;
s16 D_808013B8_chdinofamilymother[12] = { 0x17BB, 0x17C0, 0x0, 0x601, 0x120B, 0x0, 0x65, 0x0, 0xC, 0x203C, 0x0, 0x0 };
f32 D_808013D0_chdinofamilymother[3] = { -8e+02f, 0.0f, -2.3e+03f };
f32 D_808013DC_chdinofamilymother[3] = { 6e+02f, 6e+02f, 7e+02f };
static u32 D_808013DC_chdinofamilymother_rest[1] = { 0x43480000 };
DinoMotherVector D_808013EC_chdinofamilymother = { -5e+02f, 0.0f, -1.8e+03f };
DinoMotherVector D_808013F8_chdinofamilymother = { 3.7e+02f, 0.0f, -1935.0f };
u8 D_80801404_chdinofamilymother[60] = { 0x0, 0x1D, 0x9, 0xC9, 0x0, 0x16, 0x10, 0x4, 0x0, 0x2B, 0x1, 0x0, 0x1, 0x80, 0x0, 0x22, 0x0, 0x80, 0x1, 0x0, 0x2, 0x0, 0x4, 0x0, 0x0, 0x15, 0x0, 0x33, 0x0, 0x33, 0x0, 0x19, 0x0, 0x0, 0x0, 0x7, 0x0, 0x2C, 0xFF, 0xD8, 0x0, 0x28, 0xFF, 0xD8, 0x0, 0x28, 0x0, 0x50, 0x0, 0x28, 0x0, 0x20, 0x8C, 0x78, 0x28, 0xA0, 0x0, 0x0, 0x0, 0x0 };
u8 D_80801440_chdinofamilymother[52] = { 0x0, 0x1D, 0x8, 0xA3, 0x0, 0x16, 0x14, 0x0, 0x0, 0x2B, 0x1, 0x80, 0x2, 0x0, 0x0, 0x22, 0x1, 0x80, 0x1, 0x0, 0x0, 0x33, 0x0, 0x80, 0x0, 0x15, 0x0, 0x19, 0x0, 0xE6, 0x0, 0x1B, 0xFF, 0x38, 0xFE, 0xD4, 0x0, 0x27, 0x0, 0x64, 0x0, 0x64, 0x0, 0xC8, 0x0, 0xC8, 0x0, 0xD, 0x0, 0x32, 0x0, 0x0 };
int D_80801474_chdinofamilymother[19] = { 0x1280290, 0x8990001, (u32)&D_80801340_chdinofamilymother, (u32)func_808000A0_chdinofamilymother, (u32)func_80105834, (u32)func_801018A4, 0x13880000, 0x40000000, 0x0, 0x528, 0x0, 0x0, 0x0, (u32)func_80800000_chdinofamilymother, (u32)func_80107C2C, -0x7FFF8BFA, (u32)func_80800218_chdinofamilymother, 0x0, 0x0 };
