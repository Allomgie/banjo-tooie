#include "common.h"

extern s16 D_80800EA0_chblackeye[];
extern u8 D_80800E68_chblackeye[];
extern u8 D_80800E80_chblackeye[];
extern f32 func_800D8FF8(void);
extern f32 func_800DC178(f32, f32);
extern f32 D_80800EAC_chblackeye[];
extern void func_800EFA4C(f32 *, f32, f32, f32);
extern void func_800EF334(f32 *, f32);
extern void func_800EF934(f32 *, f32 *, f32);
extern void func_800EF04C(f32 *, f32 *);
extern void func_80102424(Actor *, s32);
extern void func_800EE7F8(f32 *, f32 *);
extern void func_800EF1B8(f32 *, f32, f32);
extern u8 D_80800E20_chblackeye[];
extern s32 D_80800F18_chblackeye[];
extern s32 D_80800F6C_chblackeye[];
extern s32 func_800BBCB8(f32 *, f32 *, f32, s32, s32 *);
typedef struct Mass46BlackeyeFlags {
    u32 local_0 : 11;
    u32 local_1 : 1;
    u32 local_2 : 20;
} Mass46BlackeyeFlags;
extern void _suexpression_entrypoint_12(void *, f32, f32);
extern void _gcdialogcamera_entrypoint_3(void *, f32);
extern s32 D_8080102C_chblackeye[];
extern s32 D_8080103C_chblackeye[];
extern int D_8080104C_chblackeye[];
extern s32 D_80800EB8_chblackeye[];
extern void func_800BA7C4(s32, f32, f32);
extern void func_800BA7FC(s32, f32, f32);
extern int func_800BA6B0(s32, s16, s16, s16, s16, s16, s16);
extern u8 D_80800E10_chblackeye[];
extern u8 D_80800EE0_chblackeye[];
extern s32 func_800BABB8(s32, f32 *, f32 *, f32, void *);
typedef struct {
    u8 pad_0[0x70];
    u32 pad_1 : 28;
    u32 local_0 : 1;
    u32 pad_2 : 3;
} BlackeyeExpression521;
extern s32 D_80800E00_chblackeye[];
extern s32 D_80800E50_chblackeye[];
extern s32 D_80800E60_chblackeye[];
extern s32 D_80800FB8_chblackeye[];
extern s32 D_80800FF8_chblackeye[];
extern s32 D_80801004_chblackeye[];
extern s32 D_8080101C_chblackeye[];
extern s32 D_80801024_chblackeye[];
extern f32 func_80101F24(Actor *);
extern s32 func_80101E14(Actor *, f32);
extern void func_8008FB10(f32 *, f32, f32, f32);

s32 func_80800000_chblackeye(Actor *this, s32 param_1)
{
    if (!func_800DA298(0)) {
        _subaddieaudioquick_entrypoint_2(this, this->position, param_1);
    }
}

void func_8080003C_chblackeye(Actor *param_0)
{
    f32 local_0;

    local_0 = func_800D8FF8();
    if (0.0f < *(f32 *) ((u8 *) param_0 + 0x24)) {
        *(f32 *) ((u8 *) param_0 + 0x24) -= local_0;
    } else {
        func_800C4B7C(D_80800EA0_chblackeye[func_800DC128(0, 5)]);
        func_80800000_chblackeye(param_0, D_80800E68_chblackeye);
        *(f32 *) ((u8 *) param_0 + 0x24) = func_800DC178(2.5f, 5.0f);
    }
    if (0.0f < *(f32 *) ((u8 *) param_0 + 0x34)) {
        *(f32 *) ((u8 *) param_0 + 0x34) -= local_0;
    } else {
        func_80800000_chblackeye(param_0, D_80800E80_chblackeye);
        *(f32 *) ((u8 *) param_0 + 0x34) = func_800DC178(2.5f, 5.0f);
    }
}

void func_80800128_chblackeye(Actor *param_0, s32 param_1)
{
    s16 local_1;
    s32 local_0 = 4;

    if (!func_800DA9E4(0xE4, 1)) {
        local_1 = 0x100C;
        local_0 = 12;
    } else if (param_1 && !func_800D0B68(0x19, 7)) {
        local_1 = param_0->unk6C_0 + 0x1010;
        local_0 = 12;
        if (param_0->unk6C_0 < 2) {
            param_0->unk6C_0++;
        } else {
            param_0->unk6C_0 = 0;
        }
    } else {
        local_1 = func_800DC128(0x100D, 0x1010);
    }
    _subaddiedialog_entrypoint_11(param_0->unk0, local_1, local_0, D_80800EAC_chblackeye, 0x6E);
    param_0->unk74_30 = 1;
}

void func_80800224_chblackeye(Actor *param_0)
{
    f32 local_3;
    s32 i;

    func_800EFA4C((f32 *) ((u8 *) param_0 + 0x18), -250.0f, 0.0f, -200.0f);
    func_800EFA4C((f32 *) ((u8 *) param_0 + 0x28), 250.0f, 450.0f, -950.0f);
    func_800EF334((f32 *) ((u8 *) param_0 + 0x18), param_0->scale);
    func_800EF334((f32 *) ((u8 *) param_0 + 0x28), param_0->scale);
    func_800EF934((f32 *) ((u8 *) param_0 + 0x18), (f32 *) ((u8 *) param_0 + 0x18),
                  param_0->rotation[1]);
    func_800EF934((f32 *) ((u8 *) param_0 + 0x28), (f32 *) ((u8 *) param_0 + 0x28),
                  param_0->rotation[1]);
    func_800EF04C((f32 *) ((u8 *) param_0 + 0x28), param_0->position);
    func_800EF04C((f32 *) ((u8 *) param_0 + 0x18), param_0->position);
    for (i = 0; i < 3; i++) {
        if (((f32 *) ((u8 *) param_0 + 0x18))[i] < ((f32 *) ((u8 *) param_0 + 0x28))[i]) {
            local_3 = ((f32 *) ((u8 *) param_0 + 0x28))[i];
            ((f32 *) ((u8 *) param_0 + 0x28))[i] = ((f32 *) ((u8 *) param_0 + 0x18))[i];
            ((f32 *) ((u8 *) param_0 + 0x18))[i] = local_3;
        }
    }
}

void func_80800314_chblackeye(Actor *param_0, s32 param_1)
{
    func_80102424(param_0, param_1);
    switch (param_1) {
        case 1:
            func_800EE7F8((f32 *) param_0->actorData, param_0->position);
            func_800EF1B8((f32 *) param_0->actorData, param_0->rotation[1] + 180.0f,
                          param_0->scale * 350.0f);
            break;
        case 2:
        case 3:
            func_80800224_chblackeye(param_0);
    }
}

void func_808003C0_chblackeye(Actor *param_0)
{
    param_0->unk64_20 = 1;
    param_0->unk64_19 = func_800D0B68(0x19, 7, param_0);
    if (!param_0->unk64_19) {
        func_80800314_chblackeye(param_0, 1);
    } else {
        func_80800314_chblackeye(param_0, 3);
    }
}

void func_80800444_chblackeye(Actor *arg0)
{
    if (func_80100094(arg0, 1) != 0) {
        _suexpression_entrypoint_8(arg0, 1);
    }
}

void func_80800478_chblackeye(Actor *param_0)
{
    f32 local_1[3];
    s32 local_0;
    local_0 = func_800B53A4(4);
    func_800BA6B0(local_0, (s16) (param_0->scale * -5.0f), -10, (s16) (param_0->scale * -5.0f),
                  (s16) (param_0->scale * 5.0f), -15, (s16) (param_0->scale * 5.0f));
    func_800BA4D0(local_0, (s16) (param_0->scale * 350.0f));
    func_800BA7C4(local_0, param_0->scale * 0.06f, param_0->scale * 0.1f);
    func_800BA7FC(local_0, param_0->scale * 0.03f, param_0->scale * 0.03f);
    func_800BA994(local_0, 25, (s16) (param_0->rotation[1] + 155.0f), 25, 45,
                  (s32) (param_0->rotation[1] + 205.0f), 75);
    func_800DBEFC(*(s32 *) ((u8 *) param_0->unk0 + 4), 4, local_1);
    func_800BABB8(local_0, local_1, 0, 1.0f, &D_80800EB8_chblackeye);
}

void func_8080061C_chblackeye(Actor *param_0)
{
    f32 local_1[3];
    s32 local_0 = func_800B53A4(10);

    func_800BA6B0(local_0, param_0->scale * -30.0f, 0, param_0->scale * -30.0f,
                  param_0->scale * 30.0f, 0, param_0->scale * 30.0f);
    func_800BA4D0(local_0, (s16) (param_0->scale * 350.0f));
    func_800BA7C4(local_0, param_0->scale * 0.06f, param_0->scale * 0.1f);
    func_800BA7FC(local_0, param_0->scale * 0.03f, param_0->scale * 0.03f);
    func_800DBEFC(*(void **) ((u8 *) param_0->unk0 + 4), 4, local_1);
    func_800BABB8(local_0, local_1, 0, 1.0f, D_80800EE0_chblackeye);
    func_80800000_chblackeye(param_0, D_80800E10_chblackeye);
}

void func_80800774_chblackeye(Actor *param_0)
{
    f32 local_0[3];

    func_800EFA4C(local_0, 0.0f, 40.0f, -800.0f);
    func_800EF334(local_0, param_0->scale);
    func_800EF934(local_0, local_0, param_0->rotation[1]);
    func_800EF04C(local_0, param_0->position);
    func_800BBCB8(local_0, local_0, 1.0f, 3, D_80800F18_chblackeye);
    func_800BBCB8(local_0, local_0, 1.0f, 1, D_80800F6C_chblackeye);
    func_80800000_chblackeye(param_0, D_80800E20_chblackeye);
    param_0->unk64_20 = 0;
}

void func_80800838_chblackeye(Actor *param_0)
{
    f32 local_0;
    f32 local_1[3];
    f32 local_2[3];

    if (((BlackeyeExpression521 *) param_0)->local_0) {
        _suexpression_entrypoint_10(func_80100094(param_0, 1), param_0->unk0, 0);
        func_8080003C_chblackeye(param_0);
        switch (param_0->unk70_10) {
            case 1:
                if (param_0->unk7C_12 && func_80101E4C(param_0, &D_80800FB8_chblackeye)) {
                    func_8080061C_chblackeye(param_0);
                }
                if (func_80101E4C(param_0, &D_80800FF8_chblackeye)) {
                    func_80800000_chblackeye(param_0, &D_80800E00_chblackeye);
                } else if (func_80101E4C(param_0, &D_80801004_chblackeye)) {
                    func_80800000_chblackeye(param_0, &D_80800E50_chblackeye);
                }
                func_8008FB10((f32 *) &param_0->actorData[0], param_0->scale * 600.0f, 0.0f,
                              param_0->scale * 250.0f);
                break;
            case 2:
                local_0 = func_80101F24(param_0);
                if (func_80101E4C(param_0, &D_8080101C_chblackeye)) {
                    func_80800000_chblackeye(param_0, &D_80800E00_chblackeye);
                } else if (func_80101E4C(param_0, &D_80801024_chblackeye)) {
                    func_80800000_chblackeye(param_0, &D_80800E50_chblackeye);
                } else if (func_80101E14(param_0, 0.04f)) {
                    func_80800000_chblackeye(param_0, &D_80800E60_chblackeye);
                } else if (func_80101DDC(param_0)) {
                    func_80800314_chblackeye(param_0, 3);
                } else if (func_80101E14(param_0, 0.815f)) {
                    func_80800774_chblackeye(param_0);
                }
                if (param_0->unk7C_12 && local_0 > 0.73f && local_0 < 0.83f) {
                    func_80800478_chblackeye(param_0);
                }
                func_8008FA94(&param_0->actorData[4], &param_0->actorData[0]);
                break;
            case 3:
                func_8008FA94(&param_0->actorData[4], &param_0->actorData[0]);
        }
        if (param_0->unk7C_12) {
            func_800DBEFC(param_0->unk0->unk4, 4, local_1);
            func_8008FB10(local_1, 10.0f, -50.0f, 50.0f);
        }
        if (!param_0->unk74_30 && func_8010CAC0(param_0->position, 500) && func_8008FA60(1, 0)) {
            local_2[0] = param_0->position[0];
            local_2[1] = param_0->position[1] + 100.0f;
            local_2[2] = param_0->position[2];
            if (_subaddiedialog_entrypoint_4(local_2, 500, 0)) {
                func_80800128_chblackeye(param_0, 1);
            } else if (param_0->unk58 <= 0.0f) {
                func_80800128_chblackeye(param_0, 0);
            }
        }
        if (param_0->unk58 > 0.0f && !param_0->unk74_30) {
            param_0->unk58 -= func_800D8FF8();
        }
    }
}

s32 func_80800BC4_chblackeye(Actor *param_0, s32 param_1, s32 param_2)
{
    f32 local_0[3];
    f32 local_1[3];
    switch (param_1) {
        case 0x29:
            _suexpression_entrypoint_7(param_0, 1, 0x6E);
            _suexpression_entrypoint_12(func_80100094(param_0, 1), 60.0f, 15.0f);
            break;
        case 0x2A:
            _suexpression_entrypoint_8(param_0, 1);
            break;
        case 0x2E:
            *((u8 *) param_0 + 0x74) &= ~0x40;
            if (((s16 *) &param_2)[0] == 0x1012) {
                func_800D175C(0x4E, 2);
                func_800D0BD4(0x19, 7);
                func_800D0BD4(0x1A, 7);
                func_800FC660(14);
                param_0->unk64_19 = 1;
                func_80800314_chblackeye(param_0, 2);
            }
            param_0->unk58 = 25.0f;
            break;
        case 0x52:
            switch (param_0->unk70_10) {
                case 1:
                case 2:
                    func_800EE7F8(local_0, param_0->position);
                    func_800EF1B8(local_0, param_0->rotation[1], -150.0f);
                    _gcdialogcamera_entrypoint_3(&D_8080102C_chblackeye, param_0->scale);
                    _gcdialogcamera_entrypoint_4(local_0);
                    break;
                case 3:
                    func_800EE7F8(local_1, param_0->position);
                    func_800EF1B8(local_1, param_0->rotation[1], -450.0f);
                    _gcdialogcamera_entrypoint_3(&D_8080103C_chblackeye, param_0->scale);
                    _gcdialogcamera_entrypoint_4(local_1);
            }
            break;
        case 0x1F:
            func_801015D0(param_0);
            func_800DF744(3, ((Mass46BlackeyeFlags *) ((u8 *) param_0 + 0x64))->local_1);
            func_800DF744(4, 1);
            break;
        default:
            return 0;
    }
    return 1;
}

int *chblackeye_entrypoint_0()
{
    return &D_8080104C_chblackeye;
}

extern void func_80105834();
extern void func_801018A4();
extern void func_80107C2C();
u32 D_80800DE0_chblackeye[8] = {0x0,        0x0,       0x418C0000, 0x1510041,
                                0x41100000, 0x1520042, 0x40B9999A, 0x1530041};
s32 D_80800E00_chblackeye[4] = {0x130541, 0xD00F3, 0x10C0018, 0x0};
u8 D_80800E10_chblackeye[16] = {0x0, 0x13, 0x5, 0x3D, 0x0, 0xD, 0x0, 0xF3,
                                0x1, 0xC,  0x0, 0x18, 0x0, 0x0, 0x0, 0x0};
u8 D_80800E20_chblackeye[48] = {0x0, 0x13, 0x5, 0x45, 0x0, 0xD,  0x0, 0xF3, 0x1, 0xC,  0x0, 0x18,
                                0x0, 0x0,  0x0, 0x0,  0x0, 0x13, 0x5, 0x43, 0x0, 0xD,  0x0, 0xA6,
                                0x0, 0xC0, 0x0, 0x18, 0x0, 0x0,  0x0, 0x0,  0x0, 0x13, 0x5, 0x40,
                                0x0, 0x18, 0x0, 0x0,  0x0, 0x13, 0x5, 0x3E, 0x0, 0x18, 0x0, 0x0};
s32 D_80800E50_chblackeye[4] = {0x130542, 0xD00F3, 0x10C0016, 0x55F00000};
s32 D_80800E60_chblackeye[2] = {0x13053F, 0x180000};
u8 D_80800E68_chblackeye[24] = {0x0,  0x21, 0x0, 0xD, 0x0, 0xD9, 0x0, 0xF3, 0x0, 0x19, 0x17, 0x70,
                                0x1B, 0x58, 0x0, 0x1, 0x0, 0x64, 0x0, 0xFA, 0x0, 0x0,  0x0,  0x0};
u8 D_80800E80_chblackeye[32] = {0x0,  0x13, 0x4, 0x86, 0x0,  0xD,  0x0,  0xC0, 0x0,  0xD9, 0x0,
                                0x15, 0x0,  0xC, 0x0,  0xCC, 0x0,  0x33, 0x0,  0x19, 0x17, 0x70,
                                0x1B, 0x58, 0x0, 0x1,  0x0,  0x64, 0x0,  0xFA, 0x0,  0x0};
s16 D_80800EA0_chblackeye[6] = {0x540, 0x42B, 0x558, 0x559, 0x557, 0x0};
f32 D_80800EAC_chblackeye[3] = {-728.0f, 0.0f, -2621.0f};
s32 D_80800EB8_chblackeye[10] = {0x1D09DA, 0x20FFFF, -0x14BFFE5, -0x1F301F4, 0x70001,
                                 0x150000, 0xCC002B, 0x2000200,  0x161000,   0x41A0000};
u8 D_80800EE0_chblackeye[56] = {
    0x0,  0x1D, 0x9,  0xDA, 0x0, 0x20, 0xFF, 0xFF, 0xFE, 0xB4, 0x0, 0x2C, 0xFF, 0xA6,
    0x0,  0x96, 0xFF, 0xA6, 0x0, 0x5A, 0x1,  0x90, 0x0,  0x5A, 0x0, 0x1B, 0xFA, 0xEC,
    0xFA, 0xEC, 0x0,  0x7,  0x0, 0x1,  0x0,  0x15, 0x0,  0x0,  0x0, 0xCC, 0x0,  0x2B,
    0x2,  0x0,  0x2,  0x0,  0x0, 0x16, 0x10, 0x0,  0xA,  0x1A, 0x0, 0x0,  0x0,  0x0};
s32 D_80800F18_chblackeye[21] = {0x1D06F4,  0xB0032,  0x320000, 0x2E,     0xD2,     0x28A0000,
                                 0x1180320, 0x260000, 0xFF7E,   0x0,      0x820021, 0x5A0000,
                                 0x22,      0x730099, 0x730099, 0x150000, 0xCC002B, 0x2000200,
                                 0x3000CC,  0x167000, 0x0};
s32 D_80800F6C_chblackeye[19] = {0x1D06F5,  0xB0032,  0x320000, 0x2E,      0x3C,
                                 0x28A0000, 0x960320, 0x260000, -0x820000, 0x82,
                                 0x22,      0x730099, 0x730099, 0x150000,  0xCC002B,
                                 0x2000200, 0x3000CC, 0x167000, 0x0};
s32 D_80800FB8_chblackeye[16] = {0x3F170A3D,  0x3F428F5C, 0x3F547AE1, 0x3F666666,
                                 -0x40800000, 0x3E8C49BA, 0x3E9BA5E3, 0x3EAD0E56,
                                 0x3EC10625,  0x3ECB4396, 0x3ED70A3D, 0x3EEE147B,
                                 0x3F010625,  0x3F266666, 0x3F2B851F, -0x40800000};
s32 D_80800FF8_chblackeye[3] = {0x3EDC28F6, 0x3F07AE14, -0x40800000};
s32 D_80801004_chblackeye[6] = {0x3EEB851F, 0x3F0F5C29, -0x40800000,
                                0x3EE38866, 0x3EFB22D1, -0x40800000};
s32 D_8080101C_chblackeye[2] = {0x3F23D70A, -0x40800000};
s32 D_80801024_chblackeye[2] = {0x3F3AE148, -0x40800000};
s32 D_8080102C_chblackeye[4] = {0x444E4000, 0x41F00000, 0x43480000, 0x43FA0000};
s32 D_8080103C_chblackeye[4] = {0x442DC000, 0x43FA0000, 0x43960000, 0x43ADC000};
int D_8080104C_chblackeye[21] = {0x2E2031D,
                                 0x6D40001,
                                 (u32) &D_80800DE0_chblackeye,
                                 (u32) func_80800838_chblackeye,
                                 (u32) func_80105834,
                                 (u32) func_801018A4,
                                 0x9C40000,
                                 0x0,
                                 0x0,
                                 0x1D68,
                                 (u32) func_80800444_chblackeye,
                                 0x0,
                                 0x0,
                                 (u32) func_808003C0_chblackeye,
                                 (u32) func_80107C2C,
                                 -0x7FFFFBFE,
                                 (u32) func_80800BC4_chblackeye,
                                 0x0,
                                 0x0,
                                 0x0,
                                 0x0};
