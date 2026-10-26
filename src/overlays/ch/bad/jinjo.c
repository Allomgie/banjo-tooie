#include "common.h"

extern int D_80801288_chbadjinjo;
extern s32 func_800B53A4(int);
extern void func_800BA994();
extern void func_800BA22C(s32, s32);
extern void *func_80100094(Actor *, u32);
typedef struct { f32 local_0[3]; } BadJinjoVector;
extern s32 D_808012D0_chbadjinjo;
extern s32 D_808012DC_chbadjinjo;
extern BadJinjoVector D_80801330_chbadjinjo;
extern BadJinjoVector D_8080133C_chbadjinjo;
extern f32 func_800D8FF8(void);
extern f32 func_8010CD28(Actor *);
extern f32 func_800F2094(f32, f32);
extern u8 D_808012E8_chbadjinjo[];
extern u8 D_8080124C_chbadjinjo[];
typedef union { s32 local_0; s16 local_1[2]; } BadJinjoMessage37;
extern s16 D_80801384_chbadjinjo[];
typedef struct { u8 pad_0[0x64]; u32 local_0 : 1; u32 local_1 : 1; u32 pad_1 : 30; u8 pad_2[8]; u32 local_2 : 7; u32 pad_3 : 15; u32 local_3 : 6; u32 pad_4 : 4; } BadJinjoFlags1818;
extern u8 D_808012F8_chbadjinjo[];
extern s32 func_80101E14(Actor *, f32);
extern u8 _subaddieaudioquick_entrypoint_1(Actor *, f32 *);
extern s32 func_800C3058(u8, u32);
extern void func_800C330C();
extern void func_800C31DC();
extern s32 func_800C4350();
extern void func_800C3BDC();
extern void func_800BA594(s32, f32, f32);
extern void func_800BA7FC(s32, f32, f32);
extern void func_800BA8F8(s32, f32, f32);
extern void func_800BA7C4(s32, f32, f32);
extern s32 func_800DC298(f32);
extern u8 D_8012762C;
typedef struct { u8 pad_0[0x64]; u32 pad_1 : 2; u32 local_0 : 1; u32 pad_2 : 29; u8 pad_3[0x10]; u32 pad_4 : 29; u32 local_1 : 1; u32 pad_5 : 2; } BadJinjoUpdateFlags;
extern f32 func_800DC0C0(void);
extern s32 func_800901CC(void *, f32);
extern f32 func_800F1DCC(f32, f32);
extern f32 func_800F3780(f32, s32 *, s32);
extern f32 func_80101F24(Actor *);
extern f32 func_800F15F8(f32, f32, f32);
extern f32 func_80102D78(Actor *, void *);
extern f32 _subaddiejoy_entrypoint_9(Actor *, s32, s32);
extern void func_801026CC(Actor *, Vec3f, f32);
extern void func_80102BF8(Actor *, f32, f32, f32);
extern void func_8010C3A8(Actor *, s32, f32);
extern void _subaddierouteDll_entrypoint_5(Actor *, void *, s32, f32, f32, f32);
extern void _subaddierouteDll_entrypoint_7(Actor *, void *, f32, f32, f32, s32);
extern s32 func_800EFFB4(void *, f32, void *);
typedef struct { u8 unused[0x64]; u32 high : 2; u32 uses_joy : 1; u32 low : 29; } BadJinjoFlags;
void func_80800E28_chbadjinjo();
void func_80801090_chbadjinjo();
void func_8080000C_chbadjinjo();
void func_808001B0_chbadjinjo(s32 param_0, s32 param_1, f32 param_2, s32 param_3);
float func_80800278_chbadjinjo();
s32 func_80800F7C_chbadjinjo();

int chbadjinjo_entrypoint_0()
{
    return (int)&D_80801288_chbadjinjo;
}

void func_8080000C_chbadjinjo(param_0, param_1, param_2) s32 param_0; s32 param_1; s32 param_2;
{
    func_800BA3FC(param_0, 0x9EA);
    func_800BA450(param_0, 0, -250, 0, 0, -250, 0);
    func_800BA594(param_0, 0.4f, 0.8f);
    func_800BA75C(param_0, param_1);
    func_800BA7FC(param_0, 0.03f, 0.03f);
    func_800BA834(param_0, 0, 0, 200, 0, 0, 240);
    func_800BA8F8(param_0, 0.7f, 0.7f);
    func_800BA5A8(param_0, 0x1000);
    func_800BA7C4(param_0, 0.5f, 0.5f);
}

void func_8080010C_chbadjinjo(s32 param_0, f32 param_1, s32 param_2)
{
    s32 local_2C;
    s32 local_18;
    s32 local_14;
    s32 local_10;

    local_2C = func_800B53A4(0xA);
    func_8080000C_chbadjinjo(local_2C, param_0, param_2);
    local_10 = -5;
    local_18 = 0x1C2;
    func_800BA994(local_2C, -0xF, (s16) ((s32) (-60.0f + param_1)), 0x15E, local_10, (s32) (60.0f + param_1), local_18);
    func_800BA22C(local_2C, 0xA);
}

void func_808001B0_chbadjinjo(s32 param_0, s32 param_1, f32 param_2, s32 param_3)
{
    s32 sp2C;
    s32 temp_v0;

    temp_v0 = func_800B53A4(4);
    sp2C = temp_v0;
    func_8080000C_chbadjinjo(temp_v0, param_1, param_3);
    func_800BA994(sp2C, -0xF, (s16) (s32) (-60.0f + param_2), 0x32, -5, (s32) (60.0f + param_2), 0x96);
    func_800BA22C(sp2C, 4);
    if (func_800DC298(0.1f) != 0) {
        func_80801090_chbadjinjo(param_0, &D_808012D0_chbadjinjo);
    }
}

float func_80800278_chbadjinjo()
{
    switch (D_8012762C) {
    case 19:
        return 420.0f;
    case 16:
        return 440.0f;
    case 15:
        return 460.0f;
    case 18:
        return 450.0f;
    case 20:
        return 500.0f;
    case 21:
        return 550.0f;
    case 22:
        return 600.0f;
    case 23:
        return 650.0f;
    case 24:
        return 700.0f;
    case 25:
        return 630.0f;
    case 26:
        return 600.0f;
    default:
        return 0.0f;
    }
}

void func_80800358_chbadjinjo(Actor *param_0)
{
    u8 *local_0;

    local_0 = func_80100094(param_0, 0);
    if (func_800D395C()) {
        func_800FFAB0(param_0);
        return;
    }
    _subaddierouteDll_entrypoint_3(param_0, local_0, param_0->position);
    *(f32 *)((u8 *)param_0 + 0x24) = 0.0f;
    *(f32 *)((u8 *)param_0 + 0x2C) = 0.0f;
    func_800EE7F8(local_0 + 0x10, param_0->position);
    local_0[0x24] = func_800DC128(0, 9);
    *(f32 *)((u8 *)param_0 + 0x30) = func_80800278_chbadjinjo();
}

void func_808003EC_chbadjinjo(Actor *param_0)
{
    u8 *local_0;
    local_0 = func_80100094(param_0, 0);
    if (*(f32 *)(local_0 + 0x1C) > 0.0f) {
        *(f32 *)(local_0 + 0x1C) -= func_800D8FF8();
        return;
    } else {
        *(f32 *)(local_0 + 0x1C) = 0.5f;
    }
    if (func_800F2094(param_0->rotation[1], func_8010CD28(param_0)) > 120.0f) { return; }
    if (func_8010C9B0(param_0->position, 250)) {
        u8 *local_2 = func_80100094(param_0, 0);
        BadJinjoVector local_3 = D_80801330_chbadjinjo;
        func_800EF04C(local_3.local_0, param_0->position);
        func_8080010C_chbadjinjo(local_3.local_0, func_8010CD28(param_0), local_2[0x24]);
        func_80801090_chbadjinjo(param_0, &D_808012D0_chbadjinjo);
        param_0->unk58 = 0.5f;
        *(f32 *)(local_2 + 0x20) = 0.5f;
        func_80800E28_chbadjinjo(param_0, 6);
    } else {
        u8 *local_4 = func_80100094(param_0, 0);
        BadJinjoVector local_5 = D_8080133C_chbadjinjo;
        func_800EF04C(local_5.local_0, param_0->position);
        func_808001B0_chbadjinjo(param_0, local_5.local_0, param_0->rotation[1], local_4[0x24]);
        if (func_8001210C(7)) { func_80801090_chbadjinjo(param_0, &D_808012DC_chbadjinjo); }
    }
}





































void func_80801118_chbadjinjo();

void func_80801054_chbadjinjo(Actor *param_0, s16 *param_1, f32 param_2);

void func_8080059C_chbadjinjo(Actor *param_0)
{
    extern u8 D_80801308_chbadjinjo[];
    extern u8 D_80801324_chbadjinjo[];
    extern u8 D_80801348_chbadjinjo[];
    extern Vec3f D_80801370_chbadjinjo;
    extern u8 D_8080137C_chbadjinjo[];

    char *local_0;
    f32 local_1;
    f32 local_3;
    f32 local_2;
    f32 local_4[3];
    f32 local_6;
    f32 local_7;

    local_0 = (char *)func_80100094(param_0, 0);
    local_1 = 1.0f;
    local_6 = func_800D8FF8();

    if (((BadJinjoUpdateFlags *)param_0)->local_1) {
        func_80801118_chbadjinjo(param_0);
        return;
    }

    if (*(f32 *)(local_0 + 0x20) > 0.0f) {
        *(f32 *)(local_0 + 0x20) -= local_6;

        *(u16 *)((char *)param_0->unk0 + 0x24) =
            (*(u16 *)((char *)param_0->unk0 + 0x24) & 0x3F) | 0x8C80;
    } else {
        *(u16 *)((char *)param_0->unk0 + 0x24) =
            (*(u16 *)((char *)param_0->unk0 + 0x24) & 0x3F) | 0x8C40;
    }

    func_800D9078((char *)param_0 + 0x58);
    func_8010D254(local_4);

    func_800F1E6C(
        (char *)param_0 + 4,
        local_4,
        &local_3
    );

    local_2 = func_800F1DCC(
        *(f32 *)((char *)param_0 + 0x48),
        local_3
    );

    if (*(s16 *)((char *)param_0 + 0x8C) != 0) {
        local_1 = func_800F3780(
            func_80101F24(param_0),
            D_80801348_chbadjinjo,
            5
        );
    }

    switch (param_0->unk70_10) {
        case 1:
            if (func_800DC0C0() < 0.015f) {
                if (func_800901CC(
                        (char *)param_0 + 4,
                        55.0f)) {
                    func_80102424(param_0, 3);
                } else {
                    func_80102424(param_0, 2);
                }
            }

            if (func_80800F7C_chbadjinjo(param_0)) {
                func_80800E28_chbadjinjo(param_0, 5);
            }
            break;

        case 2:
            func_80801054_chbadjinjo(
                param_0,
                D_80801308_chbadjinjo,
                0.2f
            );

            if (func_80101E14(param_0, 0.999f)) {
                func_80800E28_chbadjinjo(param_0, 1);
            }
            break;

        case 3:
            func_80801054_chbadjinjo(
                param_0,
                D_80801324_chbadjinjo,
                0.2f
            );

            if (func_80101E14(param_0, 0.999f)) {
                func_80800E28_chbadjinjo(param_0, 1);
            }
            break;

        case 4:
            func_80105230(
                param_0,
                D_8080137C_chbadjinjo
            );

            if (func_80101E14(param_0, 0.999f)) {
                func_80800E28_chbadjinjo(param_0, 1);
            } else if (local_2 >= 0.0f) {
                *(f32 *)((char *)param_0 + 0x48) -=
                    80.0f * func_800D8FF8();
            } else {
                *(f32 *)((char *)param_0 + 0x48) +=
                    80.0f * func_800D8FF8();
            }
            break;

        case 5:
            func_8010D254((char *)param_0 + 0x18);

            if (((BadJinjoUpdateFlags *)param_0)->local_0) {
                local_7 = _subaddiejoy_entrypoint_9(
                    param_0,
                    (char *)param_0 + 0x54,
                    3
                );

                *(f32 *)((char *)param_0 + 0x24) =
                    *(f32 *)((char *)param_0 + 0x2C);

                func_80102BF8(
                    param_0,
                    0.2f,
                    8.0f,
                    500.0f
                );

                func_8010C3A8(
                    param_0,
                    0x205015,
                    local_7 * local_1
                );

                if (_subaddiejoy_entrypoint_9(
                        param_0,
                        0,
                        0) < 0.05f) {
                    func_80800E28_chbadjinjo(param_0, 1);
                }

                func_808003EC_chbadjinjo(param_0);
            } else {
                if (_subaddierouteDll_entrypoint_4(param_0)) {
                    *(f32 *)((char *)param_0 + 0x54) =
                        func_80102D78(
                            param_0,
                            (char *)param_0 + 0x18
                        );

                    _subaddierouteDll_entrypoint_7(
                        param_0,
                        local_0,
                        *(f32 *)((char *)param_0 + 0x48),
                        *(f32 *)((char *)param_0 + 0x54),
                        200.0f,
                        0x5800
                    );

                    *(s32 *)(local_0 + 0x0C) =
                        *(u16 *)(local_0 + 6);
                }

                _subaddierouteDll_entrypoint_5(
                    param_0,
                    local_0,
                    *(s32 *)(local_0 + 0x0C),
                    0.15f,
                    8.0f,
                    200.0f
                );

                *(f32 *)((char *)param_0 + 0x24) =
                    func_800F15F8(
                        *(f32 *)((char *)param_0 + 0x24),
                        *(f32 *)((char *)param_0 + 0x2C),
                        func_800D8FF8() * 400.0f
                    );

                func_801026CC(
                    param_0,
                    D_80801370_chbadjinjo,
                    *(f32 *)((char *)param_0 + 0x24)
                );

                func_8010C3A8(
                    param_0,
                    0x305115,
                    local_1
                );

                func_808003EC_chbadjinjo(param_0);

                if (_subaddierouteDll_entrypoint_4(param_0) &&
                    func_800DC298(0.2f) &&
                    (!func_8010C9B0(
                        (char *)param_0 + 4,
                        1000) ||
                     !func_8010C500(param_0))) {
                    func_80800E28_chbadjinjo(param_0, 6);
                }
            }
            break;

        case 6:
            if (func_80800F7C_chbadjinjo(param_0)) {
                func_80800E28_chbadjinjo(param_0, 5);
            }

            if (_subaddierouteDll_entrypoint_4(param_0)) {
                *(f32 *)((char *)param_0 + 0x54) =
                    func_80102D78(
                        param_0,
                        (char *)param_0 + 0x18
                    );

                _subaddierouteDll_entrypoint_7(
                    param_0,
                    local_0,
                    *(f32 *)((char *)param_0 + 0x48),
                    *(f32 *)((char *)param_0 + 0x54),
                    200.0f,
                    0x5800
                );

                *(s32 *)(local_0 + 0x0C) =
                    *(u16 *)(local_0 + 6);
            }

            _subaddierouteDll_entrypoint_5(
                param_0,
                local_0,
                *(s32 *)(local_0 + 0x0C),
                0.15f,
                8.0f,
                200.0f
            );

            *(f32 *)((char *)param_0 + 0x24) =
                func_800F15F8(
                    *(f32 *)((char *)param_0 + 0x24),
                    *(f32 *)((char *)param_0 + 0x2C),
                    func_800D8FF8() * 400.0f
                );

            func_801026CC(
                param_0,
                D_80801370_chbadjinjo,
                *(f32 *)((char *)param_0 + 0x24)
            );

            func_8010C3A8(
                param_0,
                0x305115,
                local_1
            );

            if (_subaddierouteDll_entrypoint_4(param_0) &&
                func_800DC298(0.2f) &&
                func_800EFFB4(
                    (char *)param_0 + 4,
                    100.0f,
                    local_0 + 0x10)) {
                func_80800E28_chbadjinjo(param_0, 1);
            }
            break;

        case 7:
            if (func_80101DDC(param_0)) {
                _subaddieDll_entrypoint_4(param_0, 0);

                if (!func_80107070(param_0, 2)) {
                    _subaddiefade_entrypoint_3(param_0);
                }
            }
            break;
    }

    if (func_801022E4(param_0) == 0x1AD) {
        func_80105230(param_0, 0);
    }

    if (!((BadJinjoUpdateFlags *)param_0)->local_0 &&
        (s32)param_0->unk70_10 < 4 &&
        (local_2 > 45.0f || local_2 < -45.0f)) {
        func_80102424(param_0, 4);
    }

    if ((s32)param_0->unk70_10 < 8) {
        func_8010D690(param_0);
    }

    func_80801118_chbadjinjo(param_0);
}

s32 func_80800C90_chbadjinjo(Actor *param_0, s32 param_1, BadJinjoMessage37 param_2)
{
    u8 *local_0;

    switch (param_1) {
        case 0x95:
            local_0 = func_80100094(param_0, 0);
            _subaddierouteDll_entrypoint_1(param_0);
            func_80103140(param_0, 0x643, (u16)(local_0[0x24] + 0xC31));
            break;
        case 0x40:
            func_80801090_chbadjinjo(param_0, (s16 *)D_808012E8_chbadjinjo);
            func_80800E28_chbadjinjo(param_0, 7);
            break;
        case 1:
            func_80800E28_chbadjinjo(param_0, 5);
            break;
        case 2:
            if (!_subaddieDll_entrypoint_3(param_0)) {
                if (!func_80107070(param_0, 1)) _subaddiefade_entrypoint_3(param_0);
            } else func_80800E28_chbadjinjo(param_0, 6);
            break;
        case 0x1F:
            func_801015D0(param_0);
            func_800DF744(3, 2);
            break;
        case 0x38:
            func_80101074(D_8080124C_chbadjinjo);
            return 5;
        case 0x4D:
            if (!func_80107070(param_0, 3)) return 0;
            break;
        default: return 0;
    }
    return 1;
}

void func_80800DF0_chbadjinjo(s32 arg0) 
{
}
int func_80800DF8_chbadjinjo(int param_0)
{
  s16 *local_0;
  ;
  return D_80801384_chbadjinjo[*((unsigned char *) ((u8 *)func_80100094(param_0, 0) + 0x24))];
}

void func_80800E28_chbadjinjo(param_0, param_1) Actor *param_0; s32 param_1;
{
    u8 *local_0 = (u8 *)func_80100094(param_0, 0);

    func_80102424(param_0, param_1);
    switch (param_1) {
        case 5:
            if (!func_800DA9E4(0x57, 1)) {
                _subaddiedialog_entrypoint_11(param_0->unk0, 0xCE8, 3, param_0->position, func_80800DF8_chbadjinjo(param_0));
            }
            func_80801090_chbadjinjo(param_0, (s16 *)D_808012F8_chbadjinjo);
            *(f32 *)&param_0->actorData[5] = *(f32 *)&param_0->actorData[6];
            break;
        case 6:
            func_800EE7F8(param_0->actorData, local_0 + 0x10);
            *(f32 *)&param_0->actorData[5] *= 0.5f;
            break;
        case 7:
            ((BadJinjoFlags1818 *)param_0)->local_2 =
                ((BadJinjoFlags1818 *)param_0)->local_3 = 0;
            ((BadJinjoFlags1818 *)param_0)->local_0 =
                ((BadJinjoFlags1818 *)param_0)->local_1 = 0;
            func_8010A570(param_0);
            _subaddieDll_entrypoint_4(param_0, 1);
        case 1:
            break;
    }
}

s32 func_80800F7C_chbadjinjo(param_0) Actor *param_0;
{
    if (param_0->unk58 > 0.0f) {
        return 0;
    }
    if (((BadJinjoFlags *)param_0)->uses_joy) {
        if (_subaddiejoy_entrypoint_9(param_0, 0, 0) > 0.1f) {
            return 1;
        }
        return 0;
    }
    if (_subaddierouteDll_entrypoint_4(param_0) &&
        func_8010C9B0(param_0->position, 1000) &&
        _suchase_entrypoint_1(param_0) &&
        func_8010C500(param_0)) {
        return 1;
    }
    return 0;
}

void func_80801054_chbadjinjo(Actor *param_0, s16 *param_1, f32 param_2) {
    if (func_80101E14(param_0, param_2) != 0) {
        func_80801090_chbadjinjo(param_0, param_1);
    }
}

void func_80801090_chbadjinjo(param_0, param_1) Actor *param_0; s16 *param_1;
{
    u8 local_0;

    local_0 = param_0->unk5F;
    if (local_0 == 0) {
        param_0->unk5F = _subaddieaudioquick_entrypoint_1(param_0, param_0->position);
        func_800C330C(param_0->unk5F, 3);
        local_0 = param_0->unk5F;
    }
    func_800C3058(local_0, 0x55F0);
    func_800C31DC(param_0->unk5F, 0x3F800000);
    func_800C4350(param_0->unk5F, param_0->position, param_1);
    func_800C3BDC(param_0->unk5F);
}

void func_80801118_chbadjinjo(u8 *param_0)
{
  u8 temp_a1;
  int new_var;
  new_var = *((u8 *) (((s8 *) param_0) + 0x5F));
  temp_a1 = new_var;
  if ((temp_a1 != (0U * 0)) && (func_800C3D78(temp_a1 & 0xFF, temp_a1) == 0))
  {
    func_800C2FDC(*((u8 *) (((s8 *) param_0) + 0x5F)));
    *((u8 *) (((s8 *) param_0) + 0x5F)) = 0U;
  }
}
