#include "common.h"

extern void *func_80100094(Actor *, s32);
typedef struct { s32 pad_0; f32 local_0[6][9]; } EelMotion;
typedef struct { u8 pad_0[0x70]; u32 pad_1 : 31; u32 local_0 : 1; } EelActorFlags;
extern void func_800EE7F8(f32 *, f32 *);
typedef struct { u8 pad_0[0x64]; u32 pad_1 : 2; u32 enabled : 1; u32 pad_2 : 29; } EelEnabledState;
extern void func_80102B6C(Actor *, f32);
extern void func_80102B2C(Actor *, f32);
typedef struct { u8 pad_0[0x70]; u32 pad_70_10 : 22; u32 unk70_4 : 6; u32 pad_70_0 : 4; } EelRouteActor;
extern void func_800EEC30(f32[3], f32, f32, f32);
extern void func_800EF04C(f32[3], f32[3]);
extern s32 func_800CC338(f32[3], s32, s32);
extern f32 func_800F1DCC(f32, f32);
extern s32 func_800EFFB4(f32 *, f32, f32 *);
typedef struct { f32 local_0[3]; s16 pad_0; s16 local_1; f32 local_2; } EelHomePoint;
extern void *func_800CC63C(s32, s32);
extern f32 func_800EEB40(f32 *, void *);
typedef struct { u8 pad0[0x24]; u32 unk24_22 : 10; u32 pad24 : 22; } EelHit;
extern u8 D_808015F4_cheel[];
extern u8 D_80801638_cheel[];
extern void func_80101010(void *);
extern void func_800DF744(s32, s32);
extern void func_800DF5D8(s32, s32, s32, s32);
extern void func_801015D0(Actor *);
extern s32 func_8008FD48(void);
extern void func_800904C8(s32);
extern void func_80090460(s32, s32);
extern void _subaddieaudioquick_entrypoint_2(Actor *, f32 *, void *);
extern u32 D_80801644_cheel[];
typedef struct { f32 local_0; } EelBlendTop50;
typedef struct { u8 pad_0[0x64]; u32 pad_1:2; u32 local_0:1; u32 pad_2:29; } EelControl441;
extern f32 func_800D8FF8(void);
extern void *func_8010262C(Unk80132ED0 *, s32);
extern void func_800E0AF0(void *, f32);
extern void func_800E0AFC(void *, s32, f32, f32, f32, f32);
extern f32 func_800136E4(f32);
extern f32 func_800F1DF4(f32 *, f32 *);
extern f32 func_800F1828(f32 *, f32 *);
extern f32 _subaddiejoy_entrypoint_9(Actor *, f32 *, s32);
extern f32 func_800DC178(f32, f32);
extern s32 func_800DC298(f32);
typedef struct { u8 pad_0[0xDC]; s32 local_0; } EelEmitter441;
extern u8 D_808015DC_cheel[];
extern u8 D_80801608_cheel[];
extern f32 func_800DC0C0(void);
extern void func_800BABB8(s32, f32 *, f32 *, f32, void *);
extern void func_800C8E54(s32, f32, f32);
extern void func_80102424(Actor *, s32);
void func_80800D60_cheel();
int func_80801200_cheel();
extern void func_801018A4(), func_80105834(), func_80107C2C(), func_80108ED0(), func_808000B4_cheel(), func_80800128_cheel();
extern u8 D_80801560_cheel[], D_808015C8_cheel[];

void func_80800000_cheel(Actor *param_0)
{
    EelMotion *local_0;
    s32 local_1;

    local_0 = func_80100094(param_0, 0);
    for (local_1 = 0; local_1 < 9; local_1++) {
        local_0->local_0[1][local_1] = 0.0f;
        local_0->local_0[0][local_1] = 0.0f;
        local_0->local_0[4][local_1] = 0.0f;
        local_0->local_0[3][local_1] = 0.0f;
        local_0->local_0[2][local_1] = 0.0f;
        local_0->local_0[5][local_1] = 0.0f;
    }
}

void func_808000B4_cheel(param_0) Actor *param_0;
{
    func_80800000_cheel(param_0);
    *(f32 *)((u8 *)param_0 + 0x34) = 0.0f;
    func_80801200_cheel(param_0, 1);
    func_800EE7F8((f32 *)((u8 *)param_0 + 0x28), param_0->position);
    *(f32 *)((u8 *)param_0 + 0x24) = param_0->scale * 1000.0f;
    ((EelActorFlags *)param_0)->local_0 = 1;
    param_0->unk64_25 = 1;
}

void func_80800128_cheel(param_0) s32 param_0; {
    u8 *sp1C;

    sp1C = func_80100094(param_0, 0);
    if ((*(s32 *)((s8 *)(sp1C) + (0xDC))) != 0) {
        func_800C8B84((*(s32 *)((s8 *)(sp1C) + (0xDC))));
        (*(s32 *)((s8 *)(sp1C) + (0xDC))) = 0;
    }
}

void func_80800168_cheel(Actor *param_0)
{
    if (((EelEnabledState *)param_0)->enabled) {
        func_80102B6C(param_0, 8.0f);
        func_80102B2C(param_0, 4.0f);
    } else {
        func_80102B6C(param_0, 5.0f);
        func_80102B2C(param_0, 3.0f);
    }
    if ((func_8010B990(param_0, 0x500006) & 0x24) && param_0->unk70_10 != 2) {
        func_80801200_cheel(param_0, 2);
    }
}

s32 func_8080020C_cheel(Actor *param_0)
{
    f32 local_0[3];
    s32 local_1;

    func_800EEC30(local_0, param_0->rotation[0], param_0->rotation[1], 200.0f);
    func_800EF04C(local_0, param_0->position);
    local_1 = func_800CC338(local_0, (*(u32 *)((u8 *)param_0 + 0x70) >> 25) - 1,
        ((*(u32 *)((u8 *)param_0 + 0x70) << 22) >> 26) - 1);
    if (local_1 != -1) {
        ((EelRouteActor *)param_0)->unk70_4 = local_1 + 1;
        return 1;
    }
    return 0;
}

int func_808002A0_cheel(Actor *param_0)
{
    f32 local_0;
    local_0 = func_800F1DCC(param_0->rotation[1], param_0->unk54);
    if (local_0 < 0.0f) local_0 = -local_0;
    if (local_0 < 30.0f || func_800EFFB4((f32 *)param_0->actorData, 200.0f, param_0->position)) return 1;
    return 0;
}

void func_80801120_cheel();

void func_8080031C_cheel(Actor *param_0)
{
    void *local_1;
    s32 local_7;
    char *local_0;
    f32 local_2;
    local_0 = (char *)func_80100094(param_0, 0);
    local_2 = func_800D8FF8();

    local_1 = (void *)func_8010262C(
        *(s32 *)((char *)param_0 + 0x0),
        0xA
    );

    if (local_1 != 0) {
        if (param_0->unk64_20) {
            if (((EelBlendTop50 *)local_0)->local_0 < 1.0f) {
                ((EelBlendTop50 *)local_0)->local_0 += local_2;
                if (((EelBlendTop50 *)local_0)->local_0 > 1.0f) {
                    ((EelBlendTop50 *)local_0)->local_0 = 1.0f;
                }
            }
        } else {
            if (((EelBlendTop50 *)local_0)->local_0 > 0) {
                ((EelBlendTop50 *)local_0)->local_0 -= local_2;
                if (((EelBlendTop50 *)local_0)->local_0 < 0) {
                    ((EelBlendTop50 *)local_0)->local_0 = 0;
                }
            }
        }

        func_800E0AF0(local_1, ((EelBlendTop50 *)local_0)->local_0);

        for (local_7 = 8; local_7 >= 0; local_7--) {
            *(f32 *)(local_0 + 8 + local_7 * 4) += func_800F1DCC(
                *(f32 *)(local_0 + 4 + local_7 * 4),
                *(f32 *)(local_0 + 8 + local_7 * 4)
            ) * 0.25f;

            *(f32 *)(local_0 + 0x74 + local_7 * 4) += func_800F1DCC(
                *(f32 *)(local_0 + 0x70 + local_7 * 4),
                *(f32 *)(local_0 + 0x74 + local_7 * 4)
            ) * 0.25f;
        }

        *(f32 *)(local_0 + 0x4) =
            func_800136E4(*(f32 *)(local_0 + 0x4));

        *(f32 *)(local_0 + 0x4) += func_800F1DCC(
            param_0->rotation[1],
            *(f32 *)(local_0 + 0x4)
        ) * 0.25f;

        *(f32 *)(local_0 + 0x28) =
            func_800F1DCC(
                *(f32 *)(local_0 + 0x4),
                param_0->rotation[1]
            );

        *(f32 *)(local_0 + 0x70) =
            func_800136E4(*(f32 *)(local_0 + 0x70));

        *(f32 *)(local_0 + 0x70) += func_800F1DCC(
            param_0->rotation[0],
            *(f32 *)(local_0 + 0x70)
        ) * 0.25f;

        *(f32 *)(local_0 + 0x94) =
            -func_800F1DCC(
                *(f32 *)(local_0 + 0x70),
                param_0->rotation[0]
            );

        for (local_7 = 1; local_7 < 9; local_7++) {
            *(f32 *)(local_0 + 0x28 + local_7 * 4) =
                func_800F1DCC(
                    *(f32 *)(local_0 + 4 + local_7 * 4),
                    *(f32 *)(local_0 + local_7 * 4)
                );

            *(f32 *)(local_0 + 0x94 + local_7 * 4) =
                -func_800F1DCC(
                    *(f32 *)(local_0 + 0x70 + local_7 * 4),
                    *(f32 *)(local_0 + 0x6C + local_7 * 4)
                );
        }

        for (local_7 = 0; local_7 < 9; local_7++) {
            *(f32 *)(local_0 + 0x4C + local_7 * 4) += func_800F1DCC(
                *(f32 *)(local_0 + 0x28 + local_7 * 4),
                *(f32 *)(local_0 + 0x4C + local_7 * 4)
            ) * 0.25f;

            *(f32 *)(local_0 + 0xB8 + local_7 * 4) += func_800F1DCC(
                *(f32 *)(local_0 + 0x94 + local_7 * 4),
                *(f32 *)(local_0 + 0xB8 + local_7 * 4)
            ) * 0.25f;
        }

        func_800E0AFC(
            local_1,
            3,
            -1.0f,
            0.0f,
            0.0f,
            0.0f
        );

        func_800E0AFC(
            local_1,
            0x2A,
            1.0f,
            *(f32 *)(local_0 + 0xB8),
            *(f32 *)(local_0 + 0x4C),
            0.0f
        );

        func_800E0AFC(
            local_1,
            0x2B,
            1.0f,
            *(f32 *)(local_0 + 0xBC),
            *(f32 *)(local_0 + 0x50),
            0.0f
        );

        func_800E0AFC(
            local_1,
            0x2C,
            1.0f,
            *(f32 *)(local_0 + 0xC0),
            *(f32 *)(local_0 + 0x54),
            0.0f
        );

        func_800E0AFC(
            local_1,
            0x2D,
            1.0f,
            *(f32 *)(local_0 + 0xC4),
            *(f32 *)(local_0 + 0x58),
            0.0f
        );

        func_800E0AFC(
            local_1,
            0x2E,
            1.0f,
            *(f32 *)(local_0 + 0xC8),
            *(f32 *)(local_0 + 0x5C),
            0.0f
        );

        func_800E0AFC(
            local_1,
            0x2F,
            1.0f,
            *(f32 *)(local_0 + 0xCC),
            *(f32 *)(local_0 + 0x60),
            0
        );

        func_800E0AFC(
            local_1,
            0x30,
            1.0f,
            *(f32 *)(local_0 + 0xD0),
            *(f32 *)(local_0 + 0x64),
            0.0f
        );

        func_800E0AFC(
            local_1,
            0x31,
            1.0f,
            *(f32 *)(local_0 + 0xD4),
            *(f32 *)(local_0 + 0x68),
            0.0f
        );

        func_800E0AFC(
            local_1,
            0x32,
            1.0f,
            *(f32 *)(local_0 + 0xD8),
            *(f32 *)(local_0 + 0x6C),
            0.0f
        );
    }

    switch (param_0->unk70_10) {
        case 1:
            func_80800168_cheel(param_0);

            if (!func_8080020C_cheel(param_0)) {
                func_80801200_cheel(param_0, 2);
            } else if (func_8010C500(param_0)) {
                func_80801200_cheel(param_0, 3);
            } else {
                if ((1000.0f * param_0->scale) < *(f32 *)((char *)param_0 + 0x24)) {
                    *(f32 *)((char *)param_0 + 0x24) =
                        *(f32 *)((char *)param_0 + 0x24) - (10.0f * param_0->scale);
                }
            }

            func_80800D60_cheel(param_0);

            if (((EelControl441 *)param_0)->local_0) {
                *(f32 *)((char *)param_0 + 0x24) =
                    _subaddiejoy_entrypoint_9(param_0, &param_0->unk54, 3)
                    * 1000.0f * param_0->scale;
                if (*(f32 *)((char *)param_0 + 0x24) < 250.0f * param_0->scale) {
                    *(f32 *)((char *)param_0 + 0x24) = 250.0f * param_0->scale;
                }
            }
            break;

        case 2:
            func_80801120_cheel(param_0);

            param_0->unk54 =
                func_800F1DF4(
                    param_0->position,
                    (char *)param_0 + 0x18
                );

            param_0->unk50 =
                func_800F1828(
                    param_0->position,
                    (char *)param_0 + 0x18
                );

            func_80800168_cheel(param_0);

            if (func_808002A0_cheel(param_0)) {
                if (func_8080020C_cheel(param_0)) {
                    func_80801200_cheel(param_0, 1);
                }
            } else {
                if ((800.0f * param_0->scale) < *(f32 *)((char *)param_0 + 0x24)) {
                    *(f32 *)((char *)param_0 + 0x24) =
                        *(f32 *)((char *)param_0 + 0x24) - (30.0f * param_0->scale);
                }
            }

            func_80800D60_cheel(param_0);
            break;

        case 3: {
            f32 local_3[2];
            func_8010CE28(param_0, local_3);

            param_0->unk50 = -local_3[0];

            if (((EelControl441 *)param_0)->local_0) {
                *(f32 *)((char *)param_0 + 0x24) =
                    _subaddiejoy_entrypoint_9(param_0, &param_0->unk54, 3)
                    * 1000.0f * param_0->scale;
                if (*(f32 *)((char *)param_0 + 0x24) < 250.0f * param_0->scale) {
                    *(f32 *)((char *)param_0 + 0x24) = 250.0f * param_0->scale;
                }
            } else {
                param_0->unk54 = local_3[1];

                if (func_800DC298(0.05f)) {
                    param_0->unk54 +=
                        func_800DC178(-90.0f, 90.0f);
                }
            }

            func_80800168_cheel(param_0);

            if (!func_8010C500(param_0)) {
                func_80801200_cheel(param_0, 1);
            } else if (!func_8080020C_cheel(param_0)) {
                func_80801200_cheel(param_0, 4);
            } else {
                if (*(f32 *)((char *)param_0 + 0x24) < (1600.0f * param_0->scale)) {
                    *(f32 *)((char *)param_0 + 0x24) =
                        *(f32 *)((char *)param_0 + 0x24) + (10.0f * param_0->scale);
                }
            }

            func_80800D60_cheel(param_0);
            break;

        }
        case 4:
            func_80801120_cheel(param_0);

            param_0->unk54 =
                func_800F1DF4(
                    param_0->position,
                    (char *)param_0 + 0x18
                );

            param_0->unk50 =
                func_800F1828(
                    param_0->position,
                    (char *)param_0 + 0x18
                );

            func_80800168_cheel(param_0);

            if (func_808002A0_cheel(param_0)) {
                if (func_8080020C_cheel(param_0)) {
                    func_80801200_cheel(param_0, 1);
                }
            } else {
                if ((800.0f * param_0->scale) < *(f32 *)((char *)param_0 + 0x24)) {
                    *(f32 *)((char *)param_0 + 0x24) =
                        *(f32 *)((char *)param_0 + 0x24) - (30.0f * param_0->scale);
                }
            }

            func_80800D60_cheel(param_0);
            break;

        case 5: {
            f32 local_3[2];
            func_8010CE28(param_0, local_3);
            param_0->unk50 = local_3[0];
            param_0->unk54 = -local_3[1];
            func_80800168_cheel(param_0);
            if (!func_8010C500(param_0)) {
                func_80801200_cheel(param_0, 1);
            } else if (!func_8080020C_cheel(param_0)) {
                func_80801200_cheel(param_0, 2);
            } else if (*(f32 *)((char *)param_0 + 0x24) < 1600.0f * param_0->scale) {
                *(f32 *)((char *)param_0 + 0x24) += 10.0f * param_0->scale;
            }
            func_80800D60_cheel(param_0);
            break;
        }
        case 6: {
            f32 local_3[2];
            func_8010CE28(param_0, local_3);

            param_0->unk50 = local_3[0];
            param_0->unk54 = -local_3[1];

            func_80800168_cheel(param_0);

            if (param_0->unk58 > 0.0f) {
                param_0->unk58 -=
                    func_800D8FF8();

                if (!func_8080020C_cheel(param_0)) {
                    func_80801200_cheel(param_0, 7);
                    break;
                }

                if (*(f32 *)((char *)param_0 + 0x24) < (1600.0f * param_0->scale)) {
                    *(f32 *)((char *)param_0 + 0x24) =
                        *(f32 *)((char *)param_0 + 0x24) + (10.0f * param_0->scale);
                }
            } else {
                func_80801200_cheel(param_0, 1);
            }
            break;

        }
        case 7:
            func_80801120_cheel(param_0);

            param_0->unk54 =
                func_800F1DF4(
                    param_0->position,
                    (char *)param_0 + 0x18
                );

            param_0->unk50 =
                func_800F1828(
                    param_0->position,
                    (char *)param_0 + 0x18
                );

            func_80800168_cheel(param_0);

            if (param_0->unk58 > 0.0f) {
                param_0->unk58 -=
                    func_800D8FF8();
            } else {
                func_80801200_cheel(param_0, 1);
            }

            if ((800.0f * param_0->scale) < *(f32 *)((char *)param_0 + 0x24)) {
                *(f32 *)((char *)param_0 + 0x24) =
                    *(f32 *)((char *)param_0 + 0x24) - (30.0f * param_0->scale);
            }

            if (func_808002A0_cheel(param_0)
                && func_8080020C_cheel(param_0)) {
                func_80801200_cheel(param_0, 6);
            }
            break;

        case 8:
            if (func_80101DDC(param_0)) {
                func_80801200_cheel(param_0, 2);
            }
            break;

        case 9:
            if (func_80101DDC(param_0)) {
                if (!func_80107070(param_0, 2)) {
                    func_800FFAB0(param_0);
                }
            }
            break;

    }
}

void func_80800D60_cheel(param_0) Actor *param_0;
{
    EelEmitter441 *local_0;
    f32 local_1[3];
    s32 local_2;
    s32 local_3;

    local_0 = func_80100094(param_0, 0);
    if (func_8010A610(param_0)) {
        _subaddieaudioloop_entrypoint_4(param_0, param_0->position, 1, D_808015DC_cheel);
        if (!((EelControl441 *)param_0)->local_0) {
            if (func_800DC0C0() < 0.5f && param_0->unk70_10 != 3) {
                func_8010A570(param_0);
                param_0->unk64_19 = 0;
            }
        } else if (!_subaddiejoy_entrypoint_6(param_0, 1)) {
            func_8010A570(param_0);
            param_0->unk64_19 = 0;
        }
        if (!func_8010A610(param_0)) {
            if (local_0->local_0) {
                func_800C8B84(local_0->local_0);
                local_0->local_0 = 0;
            }
        } else {
            if (func_800DC0C0() < 0.5f) {
                param_0->unk64_19 = (s32)param_0->unk64_19 ^ 1;
            }
            if (param_0->unk58 > -0.15f) {
                param_0->unk58 -= func_800D8FF8();
            } else {
                param_0->unk58 = func_800DC178(0.15f, 0.5f);
                if (param_0->unk7C_12) {
                    local_2 = func_800B53A4(4);
                    local_3 = func_800B53A4(4);
                    func_800DBEFC(param_0->unk0->unk4, 4, local_1);
                    func_800DBEFC(param_0->unk0->unk4, 5, (f32 *)&param_0->actorData[4]);
                    func_800BABB8(local_2, param_0->position, NULL, 1.0f, D_80801608_cheel);
                    func_800BA3FC(local_2, 0x9E7);
                    func_800BA1D0(local_2, param_0->position, (f32 *)&param_0->actorData[4], 4);
                    func_800BABB8(local_3, (f32 *)&param_0->actorData[4], NULL, 1.0f, D_80801608_cheel);
                    func_800BA3FC(local_3, 0x9E7);
                    func_800BA1D0(local_3, (f32 *)&param_0->actorData[4], local_1, 4);
                }
            }
            if (local_0->local_0) {
                if (param_0->unk64_19) {
                    func_800C8FB0(local_0->local_0, 0x60, 0x60, 0x80);
                } else {
                    func_800C8FB0(local_0->local_0, 0x40, 0x40, 0x60);
                }
                func_800C8CB8(local_0->local_0, (f32 *)&param_0->actorData[4]);
            }
        }
    } else {
        if (((EelControl441 *)param_0)->local_0) {
            if (_subaddiejoy_entrypoint_6(param_0, 1)) {
                func_8010A590(param_0);
            }
        } else if (func_800DC0C0() < 0.5f || (param_0->unk70_10 == 3 && func_800DC0C0() < 0.2f)) {
            func_8010A590(param_0);
        }
        if (func_8010A610(param_0) && !local_0->local_0) {
            local_0->local_0 = func_800C8A98();
            func_800C8E54(local_0->local_0, 200.0f, 500.0f);
            func_800C8CB8(local_0->local_0, (f32 *)&param_0->actorData[4]);
        }
    }
}

void func_80801120_cheel(Actor *param_0)
{
    EelHomePoint *local_0;
    f32 local_1;

    local_0 = func_800CC63C((*(u32 *)((u8 *)param_0 + 0x70) >> 25) - 1, ((*(u32 *)((u8 *)param_0 + 0x70) << 22) >> 26) - 1);
    local_1 = local_0->local_0[1];
    if (local_1 + local_0->local_1 <= param_0->position[1] || param_0->position[1] <= local_1 - local_0->local_1) {
        ((f32 *)param_0->actorData)[1] = local_1;
    }
    if ((f32)(func_800EEB40(param_0->position, local_0) == 0.0f) < local_0->local_2) {
        ((f32 *)param_0->actorData)[0] = local_0->local_0[0];
        ((f32 *)param_0->actorData)[2] = local_0->local_0[2];
    }
}

int func_80801200_cheel(param_0, param_1) Actor *param_0; s32 param_1;
{
    param_0->unk64_20 = 1;
    func_80102424(param_0, param_1);
    switch (param_1) {
        case 1:
            param_0->unk54 = param_0->rotation[1] + func_800DC178(-90.0f, 90.0f);
            param_0->unk50 = param_0->rotation[0] + func_800DC178(-90.0f, 90.0f);
            break;
        case 2:
            func_80801120_cheel(param_0);
            break;
        case 3:
            if (func_8008FD48() == 12) {
                param_0->unk70_10 = 5;
            }
            break;
        case 4:
            func_80801120_cheel(param_0);
            break;
        case 8:
            func_8010A570(param_0);
            break;
        case 6:
            func_8010A570(param_0);
            param_0->unk64_19 = 0;
            break;
        case 9:
        case 10:
        case 11:
        case 12:
            func_8010A570(param_0);
            param_0->unk64_20 = 0;
            break;
    }
}

s32 func_80801330_cheel(param_0, param_1, param_2) Actor *param_0; s32 param_1; s32 param_2;
{
    switch (param_1) {
    case 0x97:
        if (1) {}
        func_80101010(D_80801638_cheel);
        break;
    case 0x1F:
        func_800DF744(3, param_0->unk64_19);
        if (param_0->unk64_19) {
            func_800DF5D8(0xFF, 0xFF, 0xFF, 0xFF);
        } else {
            func_800DF5D8(0x60, 0x60, 0x60, 0xFF);
        }
        func_801015D0(param_0);
        break;
    case 0x3F:
        if (((EelHit *)param_2)->unk24_22 == 0x26E) {
            func_80801200_cheel(param_0, 6);
            param_0->unk58 = 10.0f;
        } else {
            func_80801200_cheel(param_0, 8);
        }
        break;
    case 0x3E:
        if (((EelHit *)param_2)->unk24_22 == 0) {
            if (func_8008FD48() == 0xC) {
                func_800904C8(0x54);
            } else {
                func_80090460(0xF, *((s32 *) (((char *) param_0) + 0x0)));
            }
        }
        break;
    case 0x40:
        _subaddieaudioquick_entrypoint_2(param_0, param_0->position, D_808015F4_cheel);
        func_80801200_cheel(param_0, 9);
        break;
    case 0x8F:
        if (param_2 == 4) {
            func_80800000_cheel(param_0);
        }
        break;
    default:
        return 0;
    }
    return 1;
}

char *cheel_entrypoint_0()
{
  return &D_80801644_cheel;
}

/* TU-NOTE: the .data of this overlay (formerly asm/data/overlays/ch/eel.data.s) is defined here in C.
 * Its tables hold pointers to functions of this file; IDO's assembler schedules some of these
 * functions differently unless the tables are defined in the same unit. Values are taken from the ROM.
 * extern declarations adjusted to the object (same addresses): D_80801644_cheel -> u32[] */
u8 D_80801560_cheel[104] = { 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x3F, 0x26, 0x66, 0x66, 0x1, 0x7E, 0x0, 0x0, 0x3F, 0x26, 0x66, 0x66, 0x1, 0x7E, 0x0, 0x0, 0x3F, 0x26, 0x66, 0x66, 0x1, 0x7D, 0x0, 0x0, 0x3F, 0x26, 0x66, 0x66, 0x1, 0x7D, 0x0, 0x0, 0x3F, 0x26, 0x66, 0x66, 0x1, 0x7E, 0x0, 0x0, 0x3F, 0x26, 0x66, 0x66, 0x1, 0x7E, 0x0, 0x0, 0x3F, 0x26, 0x66, 0x66, 0x1, 0x7E, 0x0, 0x0, 0x3E, 0xCC, 0xCC, 0xCD, 0x4, 0xAB, 0x0, 0x2, 0x3F, 0x40, 0x0, 0x0, 0x4, 0xAC, 0x0, 0x2, 0x3F, 0x40, 0x0, 0x0, 0x4, 0xAC, 0x0, 0x84, 0x3F, 0x26, 0x66, 0x66, 0x1, 0x7E, 0x0, 0x0, 0x3F, 0x26, 0x66, 0x66, 0x1, 0x7E, 0x0, 0x0 };
u8 D_808015C8_cheel[20] = { 0x0, 0x1, 0x0, 0x0, 0x0, 0xA, 0x0, 0x0, 0x0, 0xA, 0x0, 0x0, 0x0, 0xB, 0x0, 0x0, 0x0, 0xC, 0x0, 0x0 };
u8 D_808015DC_cheel[24] = { 0x0, 0x13, 0x5, 0x2E, 0x0, 0xD, 0x1, 0x33, 0x1, 0x66, 0x0, 0x1, 0x1, 0xF4, 0x7, 0xD0, 0x0, 0x16, 0x46, 0x50, 0x0, 0x0, 0x0, 0x0 };
u8 D_808015F4_cheel[20] = { 0x0, 0x13, 0x5, 0xE1, 0x0, 0xA, 0x2, 0x0, 0x0, 0x16, 0xFF, 0xFF, 0x0, 0x1, 0x9, 0xC4, 0x13, 0x88, 0x0, 0x0 };
u8 D_80801608_cheel[48] = { 0x0, 0x2B, 0x0, 0x26, 0x0, 0x33, 0x0, 0x22, 0x0, 0x80, 0x0, 0xB3, 0x0, 0x6, 0x0, 0x13, 0x0, 0x26, 0xFF, 0x4C, 0xFF, 0x4C, 0xFF, 0x4C, 0x8, 0x84, 0x0, 0xB4, 0x0, 0xB4, 0x0, 0x2C, 0xFE, 0xD4, 0xFE, 0xD4, 0xFE, 0xD4, 0x1, 0x2C, 0x1, 0x2C, 0x1, 0x2C, 0x0, 0x0, 0x0, 0x0 };
u8 D_80801638_cheel[12] = { 0x0, 0x0, 0x0, 0x0, 0x43, 0x48, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0 };
u32 D_80801644_cheel[19] = { 0x2E3031E, 0x6CB0001, (u32)&D_80801560_cheel, (u32)func_8080031C_cheel, (u32)func_80105834, (u32)func_801018A4, 0x1D4C0000, 0x0, 0x0, 0x10069, (u32)func_80800128_cheel, (u32)func_80108ED0, 0xE00000, (u32)func_808000B4_cheel, (u32)func_80107C2C, 0x80600003, (u32)func_80801330_cheel, (u32)&D_808015C8_cheel, 0x0 };
