#include "common.h"

typedef struct { u8 pad0[0x6E]; u16 pad6E:7; u16 f6E:9; u8 pad70[6]; u16 f76:9; u16 pad76:7; } PiranhaState;
extern void func_8008FFBC(f32 *);
extern f32 func_800DC178(f32, f32);
extern f32 func_800EFC7C(f32 *, f32 *);
extern void func_800EFA4C(f32 *, f32, f32, f32);
extern void func_800EFB24(f32 *, f32 *, f32 *);
extern void func_800EF04C(f32 *, f32 *);
extern void *func_80100094(Actor *, u32);
extern void func_800EF334(f32 *, f32);
extern f32 func_800D8FF8(void);
extern f32 func_800EEF94(f32 *);
typedef struct { u8 pad[0x12]; u16 f12:15; u16 r:1; } PiranhaSub;
extern Actor *_subaddiefind_entrypoint_0(f32 *, s32, s32, f32 *);
extern void func_800DA3B8();
typedef struct { u8 local_0; u8 local_1; u16 local_2; f32 local_3[3]; f32 local_4; s32 local_5; u32 local_6; } PiranhaPlacement49;
extern void func_800EE7F8(f32 *, f32 *);
extern int D_80801B60_chpiranha;
extern int D_80801BA8_chpiranha;
extern int D_80801BF0_chpiranha;
extern void func_800DE448(f32 *, f32 *, f32, s32, s32);
extern Actor *func_80106790(Unk80132ED0 *);
extern void func_800EFA20(f32 *, f32 *, f32);
extern s32 func_800BF0E0(f32 *, f32 *, f32, f32 *, s32, s32);
extern f32 func_800EEAA4(f32 *, f32 *);
extern f32 func_80090010(void);
extern void func_800EFCD8(f32 *, f32, f32);
typedef struct { u8 pad_0[0x1C]; f32 local_0[1][12]; } PiranhaPathTop50;
void func_80801420_chpiranha();
void func_8080154C_chpiranha();

int func_80800000_chpiranha(Actor *param_0)
{
  func_80100074(param_0, 0, 0);
  param_0->unk3C = 0;
  func_800DA3B8(0x6A8, 0);
}

void func_8080003C_chpiranha(Actor *param_0, s32 param_1)
{
    u8 *local_2;
    s32 local_3;
    s32 local_4;
    f32 local_0[3];
    f32 local_1[3];
    u8 *local_5;
    s32 local_6;

    local_2 = func_80100094(param_0, 0);
    local_3 = func_801039E4(param_0->unk0);
    for (local_4 = 0, local_5 = local_2 + 0x1C;
        local_4 < param_0->unk6C_0; local_4++, local_5 += 0x30) {
        func_800EFA4C(local_1, 0.0, *(f32 *)(local_5 + 0x28) - 90.0f, 0.0f);
        func_800EE780(local_0, param_0->position, local_5);
        func_800DF830(2);
        func_800DF410(255);
        func_800DE448(local_0, local_1, 0.075f, 0, local_3);
        local_2[1] |= func_800DF350();
        if (local_4 < 10) {
            local_6 = func_800D674C(0x637);
            if (local_6) {
                local_0[1] = *(f32 *)(local_2 + 0x10) + 6.0f;
                func_800DF410(192);
                func_800DF830(2);
                func_800DE448(local_0, local_1, 0.1f, 0, local_6);
                local_2[1] |= func_800DF350();
            }
        }
    }
}

void func_80800218_chpiranha(Actor *param_0, s32 param_1)
{
    if (param_0->unk70_10 == 7) {
        param_0->unk64_16 = 1;
    }
    func_80101FDC(param_0, param_1);
    if (param_1 == 7) {
        param_0->unk64_16 = 0;
    }
}

void func_80800280_chpiranha(PiranhaState *param_0) {
    param_0->f6E = param_0->f76;
}





































s32 func_80801638_chpiranha();

s32 func_80801508_chpiranha();

void func_80801250_chpiranha(f32 *param_0, f32 *param_1, f32 *param_2, f32 param_3, f32 param_4, f32 *param_5, f32 *param_6);

void func_80800EFC_chpiranha(u8 *param_0, f32 *param_1, f32 param_2);

f32 func_80800CAC_chpiranha();

void func_808002A0_chpiranha(Actor *param_0)
{
    f32 local_5[3];
    f32 local_2[3];
    f32 local_3[3];
    f32 local_4[3];
    char *local_0;
    f32 local_6[3];
    f32 local_7;
    f32 local_9;
    f32 local_8;

    local_0 = (char *)func_80100094(param_0, 0);
    local_7 = func_800D8FF8();

    if (!func_8010C9B0(param_0->position, 0x5DC)) {
        if (param_0->unk5F != 0) {
            func_800C2FDC(param_0->unk5F);
            param_0->unk5F = 0;
            func_800DA3B8(0x6A8, 0);
        }
    }

    if (param_0->unk3C != 0) {
        Actor *local_1;
        if ((param_0->unk3C->unk24 >> 22) == 0x22F) {
            local_1 = func_80106790(param_0->unk3C);
            func_800EE7F8(local_0 + 4, local_1->position);
            *(f32 *)(local_0 + 8) += 250.0f;
        }
    }

    func_800EE7F8(local_2, param_0->position);

    func_800EFA20(
        local_3,
        (char *)param_0 + 0x28,
        local_7
    );

    func_800EF04C(local_3, param_0->position);

    if (func_800BF0E0(
            local_2,
            local_3,
            75.0f,
            local_4,
            3,
            0)) {
        func_800EF2A0(local_4);

        local_8 = func_800EEAA4(
            (char *)param_0 + 0x28,
            local_4
        );

        func_800EFA20(
            (char *)param_0 + 0x28,
            local_4,
            local_8 * -1.5f
        );

        func_800EFA20(
            (char *)param_0 + 0x18,
            local_4,
            37.5f
        );

        func_800EF04C(
            (char *)param_0 + 0x18,
            param_0->position
        );

        if (param_0->unk70_10 != 6) {
            *(u8 *)(local_0 + 2) = param_0->unk70_10;
            func_80800218_chpiranha(param_0, 6);
        }
    }

    func_80801250_chpiranha(
        (char *)param_0 + 0x18,
        param_0->position,
        (char *)param_0 + 0x28,
        *(f32 *)((char *)param_0 + 0x24),
        100.0f,
        0,
        local_5
    );

    func_8008FE94(5, local_6);

    local_9 = func_800EFC7C(
        param_0->position,
        (char *)param_0 + 0x18
    );

    switch (param_0->unk70_10) {
        case 7: {
            Actor *local_1;
            if (param_0->unk3C != 0) {
                local_1 = func_80106790(param_0->unk3C);

                if ((param_0->unk3C->unk24 >> 22) == 0x22F) {
                    func_800EE7F8(
                        (char *)param_0 + 0x18,
                        local_0 + 4
                    );

                    func_800EE7F8(
                        param_0->position,
                        local_0 + 4
                    );
                }

                if (local_1->unk70_10 != 2) {
                    break;
                }

                *(f32 *)(local_0 + 8) += 150.0f;

                func_80800EFC_chpiranha(
                    param_0,
                    local_0 + 4,
                    100.0f
                );

                func_80800218_chpiranha(param_0, 2);

                param_0->unk3C = 0;
                param_0->unk58 = 0.0f;
            } else {
                *(f32 *)(local_0 + 8) += 150.0f;
                func_80800218_chpiranha(param_0, 3);
            }
            break;
        }

        case 1:
            if (func_80801638_chpiranha(param_0)) {
                func_80800218_chpiranha(param_0, 2);
            }

            if (param_0->unk3C != 0) {
                if ((param_0->unk3C->unk24 >> 22) == 0x22F) {
                    func_800EE7F8(
                        (char *)param_0 + 0x18,
                        local_0 + 4
                    );

                    func_800EE7F8(
                        param_0->position,
                        local_0 + 4
                    );
                }
            }

            if (local_9 < 2500.0f) {
                func_80800EFC_chpiranha(
                    param_0,
                    local_0 + 4,
                    100.0f
                );
            }
            break;

        case 2:
            if (local_9 < 2500.0f) {
                func_80800EFC_chpiranha(
                    param_0,
                    local_0 + 4,
                    100.0f
                );
            }

            func_80801508_chpiranha(param_0);
            break;

        case 3:
            func_800EE7F8(
                (char *)param_0 + 0x18,
                local_6
            );

            *(f32 *)((char *)param_0 + 0x1C) += 50.0f;

            if ((param_0->unk0->unk24 >> 22)
                    == 0x2C2) {
                param_0->unk58 += local_7;

                if (local_9 < 2500.0f &&
                    param_0->unk58 > 0.5f &&
                    (param_0->unk6C_0 > 0.0f) &&
                    func_8010D284() != 3 &&
                    func_80800CAC_chpiranha() > 5000.0f) {
                    func_80090434(0xD);
                    param_0->unk58 -= 0.5f;
                }

                if (local_9 > 2500.0f) {
                    f32 local_12[3];
                    local_12[1] = 0.0f;
                    func_800EFCD8(local_12, func_80090010(), 100.0f);
                    func_800EF04C((char *)param_0 + 0x18, local_12);

                    if (*(f32 *)((char *)param_0 + 0x24) < 250.0f) {
                        *(f32 *)((char *)param_0 + 0x24) *= 1.1f;
                    }
                }

                if (local_9 > 7500.0f) {
                    if (*(f32 *)((char *)param_0 + 0x24) < 250.0f) {
                        *(f32 *)((char *)param_0 + 0x24) *= 1.1f;
                    } else if (*(f32 *)((char *)param_0 + 0x24) >
                               100.0f) {
                        *(f32 *)((char *)param_0 + 0x24) *= 0.9f;
                    }
                }

                if (local_9 < 2750.0f) {
                    func_80800EFC_chpiranha(
                        param_0,
                        local_6,
                        50.0f
                    );

                    func_80800218_chpiranha(param_0, 4);
                }
            } else {
                if (*(f32 *)((char *)param_0 + 0x24) < 100.0f) {
                    *(f32 *)((char *)param_0 + 0x24) += 5.0f;
                } else if (*(f32 *)((char *)param_0 + 0x24) >
                           100.0f) {
                    *(f32 *)((char *)param_0 + 0x24) -= 5.0f;
                }

                if (local_9 < 2500.0f) {
                    func_80800EFC_chpiranha(
                        param_0,
                        local_6,
                        50.0f
                    );

                    func_80800218_chpiranha(param_0, 4);
                }
            }

            func_8080154C_chpiranha(param_0);
            break;

        case 4:
            local_6[1] += 50.0f;

            param_0->unk58 += local_7;

            if ((param_0->unk0->unk24 >> 22)
                    == 0x2C2) {
                if (param_0->unk58 > 0.5f &&
                    (param_0->unk6C_0 > 0.0f) &&
                    func_8010D284() != 3 &&
                    func_80800CAC_chpiranha() > 5000.0f) {
                    func_80090434(0xD);
                    param_0->unk58 -= 0.5f;
                }
            } else {
                if (param_0->unk58 > 0.5f &&
                    (param_0->unk6C_0 > 0.0f) &&
                    func_8010D284() != 3) {
                    func_80090434(0xD);
                    param_0->unk58 -= 0.5f;
                }
            }

            if (param_0->unk58 > 0.2f &&
                func_8010D284() == 3) {
                f32 local_13[3];
                if (param_0->unk6C_0-- > 0) {
                    func_800EE780(
                        local_13,
                        ((PiranhaPathTop50 *)local_0)->local_0[param_0->unk6C_0],
                        param_0->position
                    );

                    func_80801690_chpiranha(
                        param_0,
                        local_13
                    );

                    param_0->unk58 -= 0.2f;
                }
            }

            if (param_0->unk6C_0 == 0) {
                func_800FFA88(param_0->unk0);
            }

            if (local_9 < 2500.0f) {
                func_80800EFC_chpiranha(
                    param_0,
                    local_6,
                    50.0f
                );
            }

            if (local_9 > 2500.0f ||
                func_80800CAC_chpiranha() > 0.0f) {
                func_80800218_chpiranha(param_0, 3);
            } else {
                func_8080154C_chpiranha(param_0);
            }
            break;

        case 5:
            func_800EE7F8(
                (char *)param_0 + 0x18,
                local_0 + 4
            );

            if ((param_0->unk0->unk24 >> 22)
                    != 0x2C2) {
                if (local_9 < 2500.0f) {
                    func_80800218_chpiranha(param_0, 2);
                }

                func_80801508_chpiranha(param_0);
            } else {
                if (func_80800CAC_chpiranha() > 7500.0f &&
                    local_9 < 2500.0f) {
                    func_80800218_chpiranha(param_0, 2);
                }
            }
            break;

        case 6:
            if (local_9 < 2500.0f) {
                func_80800218_chpiranha(
                    param_0,
                    *(u8 *)(local_0 + 2)
                );
            }
            break;

    }

    if (*(u8 *)(local_0 + 1) != 0 &&
        (param_0->unk70_10) != 7) {
        func_80801420_chpiranha(param_0);
    }

    *(u8 *)(local_0 + 1) = 0;
}

f32 func_80800CAC_chpiranha(void)
{
    f32 local_1[3];

    f32 local_0;

    func_8008FFBC(local_1);
    local_0 = local_1[1]; /* the target loads local_1[1] into the result local's register (f2) */
    local_0 = local_1[0] * local_1[0] + local_0 * local_0 + local_1[2] * local_1[2];
    return local_0;
}

void func_80800CEC_chpiranha(f32 *param_0, f32 *param_1, f32 param_2, f32 *param_3, f32 param_4, f32 param_5)
{
    s32 local_0;

    local_0 = 0;
    do {
        func_800EFA4C(param_1, func_800DC178(-param_2, param_2), func_800DC178(-param_2, param_2), func_800DC178(-param_2, param_2));
        local_0++;
    } while (local_0 < 10 && func_800EFC7C(param_0, param_1) < param_2 * param_2);
    *param_3 = func_800DC178(param_4, param_5);
}

void func_80800DD0_chpiranha(Actor *param_0, f32 *param_1)
{
    f32 local_1;
    f32 local_2;
    f32 local_3;

    if (param_0->unk70_10 != 7) {
        local_1 = param_0->unk70_10 == 4
            ? ((param_0->unk0->unk24 >> 22) == 0x2C2 ? 150.0f : 50.0f)
            : (param_0->unk70_10 == 3 ? 100.0f : 150.0f);
        local_2 = param_0->unk70_10 == 1 ? 20.0f : 40.0f;
        local_3 = param_0->unk70_10 == 1 ? 40.0f : 80.0f;
        func_80800CEC_chpiranha(param_1, param_1 + 6, local_1, param_1 + 11, local_2, local_3);
    } else {
        func_80800CEC_chpiranha(param_1, param_1 + 6, 5.0f, param_1 + 11, 5.0f, 5.0f);
    }
}

void func_80800EFC_chpiranha(u8 *param_0, f32 *param_1, f32 param_2)
{
    f32 local_vec[3];
    f32 *local_18;
    f32 f2;
    f32 f0;
    f32 zz;

    local_18 = (f32 *)(param_0 + 0x18);
    func_800EFB24(local_vec, (f32 *)(param_0 + 4), param_1);
    if (1) {}
    if (1) {}
    if (((Actor *)param_0)->unk70_10 != 7) {
        if ((*(u32 *)(*(u8 **)param_0 + 0x24) >> 22) != 0x2C2) {
            if (((Actor *)param_0)->unk70_10 == 5) {
                f2 = 20.0f;
            } else {
                f2 = 25.0f;
            }
            if (((Actor *)param_0)->unk70_10 == 5) {
                f0 = 20.0f;
            } else {
                f0 = 30.0f;
            }
            func_80800CEC_chpiranha(local_vec, local_18, param_2, (f32 *)(param_0 + 0x24), f2, f0);
        } else {
            if (((Actor *)param_0)->unk70_10 == 5) {
                f2 = 20.0f;
            } else {
                f2 = 25.0f;
            }
            if (((Actor *)param_0)->unk70_10 == 5) {
                f0 = 20.0f;
            } else {
                f0 = 30.0f;
            }
            func_80800CEC_chpiranha(local_vec, local_18, param_2, (f32 *)(param_0 + 0x24), f2, f0);
        }
    } else {
        func_80800CEC_chpiranha(local_vec, local_18, 5.0f, (f32 *)(param_0 + 0x24), 5.0f, 5.0f);
    }
    func_800EF04C(local_18, param_1);
}

void func_8080106C_chpiranha(Actor *param_0)
{
    u32 local_2;
    u8 *local_0;
    u8 *local_1;
    f32 local_3;
    f32 local_4;
    func_80100074(param_0, 0, param_0->unk6C_0 * 0x30 + 0x1C);
    local_0 = func_80100094(param_0, 0);
    local_2 = 0;
    local_1 = local_0 + 0x1C;
    for (; local_2 < param_0->unk6C_0; local_2++, local_1 += 0x30) {
        if (*(u32 *)((u8 *)param_0->unk0 + 0x24) >> 22 == 0x2C1) {
            local_3 = func_800DC178(-150.0f, 150.0f);
            local_4 = func_800DC178(-150.0f, 150.0f);
            func_800EFA4C((f32 *)local_1, local_3, local_4, func_800DC178(-150.0f, 150.0f));
        } else { func_800EFA4C((f32 *)local_1, 0.0f, -50.0f, 0.0f); }
        func_800EFD24(local_1 + 0xC);
        func_800EFD24(local_1 + 0x24);
        func_80800DD0_chpiranha(param_0, local_1);
    }
    func_800EFA4C((f32 *)param_0->actorData + 4, 0.0f, 1.0f, 0.0f);
    func_80800EFC_chpiranha(param_0, local_0 + 4, 100.0f);
}

void func_80801210_chpiranha(f32 *param_0, f32 param_1, f32 param_2) {
    if (param_1 != 0.0f) {
        func_800EF334(param_0, param_2 / param_1);
    }
}

void func_80801250_chpiranha(f32 *param_0, f32 *param_1, f32 *param_2,
    f32 param_3, f32 param_4, f32 *param_5, f32 *param_6)
{
    f32 local_0;
    f32 local_1;
    f32 local_2[3];

    local_0 = func_800D8FF8();
    func_800EFB24(param_6, param_0, param_1);
    local_1 = func_800EEF94(param_6);
    if (local_1 < param_4 + param_4) {
        func_80801210_chpiranha(param_6, local_1, 8.0f * param_3);
    } else {
        func_80801210_chpiranha(param_6, local_1, param_3 + param_3);
    }
    param_1[0] += param_2[0] * local_0 + (param_6[0] * local_0) * local_0;
    param_1[1] += param_2[1] * local_0 + (param_6[1] * local_0) * local_0;
    param_1[2] += param_2[2] * local_0 + (param_6[2] * local_0) * local_0;
    param_2[0] += param_6[0] * local_0;
    param_2[1] += param_6[1] * local_0;
    param_2[2] += param_6[2] * local_0;
    local_1 = func_800EEF94(param_2);
    if (param_3 < local_1) {
        func_80801210_chpiranha(param_2, local_1, param_3);
    }
    if (param_5 != NULL) {
        func_800EFD24(local_2);
        func_800F18FC(param_2, local_2, param_5);
    }
}

void func_80801420_chpiranha(param_0) Actor *param_0;
{
    u8 *local_1;
    f32 *local_2;
    u32 local_3;
    f32 local_0[3];

    local_1 = func_80100094(param_0, 0);
    local_3 = 0;
    local_1 += 0x1C;
    for (; local_3 < param_0->unk6C_0; local_3++, local_1 += 0x30) {
        local_2 = (f32 *)(local_1 + 0x18);
        func_80801250_chpiranha(local_2, (f32 *)local_1, (f32 *)(local_1 + 0xC),
            *(f32 *)(local_1 + 0x2C), 150.0f, (f32 *)(local_1 + 0x24), local_0);
        if (func_800EFC7C((f32 *)local_1, local_2) < 2500.0f) {
            func_80800DD0_chpiranha(param_0, local_1);
        }
    }
}

s32 func_80801508_chpiranha(Actor *this){
    if(func_8010C500(this) && func_8010C9B0(this->position, 0x384)){
        func_80800218_chpiranha(this, 3);
    }
}

void func_8080154C_chpiranha(param_0) Actor *param_0;
{
    s32 local_0 = 0;

    if (!func_8010C500(param_0)) {
        local_0 = 1;
    }
    if (param_0->unk0->unk24 >> 22 != 0x2C2) {
        if (!func_8010C9B0(param_0->position, 900)) {
            local_0 = 1;
        }
    } else if (func_80800CAC_chpiranha() < 2500.0f && (f32)func_800DC128(25, 75) < param_0->unk58) {
        local_0 = 1;
        param_0->unk58 = 0.0f;
    }
    if (local_0) {
        func_80800218_chpiranha(param_0, 5);
        func_80800EFC_chpiranha(param_0, (u8 *)func_80100094(param_0, 0) + 4, 100.0f);
    }
}

s32 func_80801638_chpiranha(u8 *param_0) {
    return (*(PiranhaSub **)(param_0 + 0x3C) != NULL) ? (*(PiranhaSub **)(param_0 + 0x3C))->f12 != *(s32 *)((u8 *)func_80100094((Actor *)param_0, 0) + 0x18) : 1;
}

int func_80801690_chpiranha(s32 param_0, s32 param_1)
{
  extern f32 D_80801B10_chpiranha;
  func_800BBCB8(param_1, 0, 0x3F800000, 1, &D_80801B10_chpiranha);
}

Actor *func_808016D0_chpiranha(Actor *param_0)
{
    Actor *local_1;
    Actor *local_0;
    f32 local_2;
    f32 local_3;
    s32 pad;

    local_0 = _subaddiefind_entrypoint_0(param_0->position, 0x211, -1, &local_2);
    local_1 = _subaddiefind_entrypoint_0(param_0->position, 0x199, -1, &local_3);
    if (local_1 && !local_0) local_0 = local_1;
    if (local_1 && local_0 && (local_3 < local_2 || local_2 > 500.0f)) {
        local_0 = local_1;
        local_2 = local_3;
    }
    local_1 = _subaddiefind_entrypoint_0(param_0->position, 0x19A, -1, &local_3);
    if (local_1 && !local_0) local_0 = local_1;
    if (local_1 && local_0 && (local_3 < local_2 || local_2 > 500.0f)) {
        local_0 = local_1;
        local_2 = local_3;
    }
    if (local_0) param_0->unk3C = local_0->unk0;
    else param_0->unk3C = NULL;
    if (local_2 > 500.0f) param_0->unk3C = NULL;
    return local_0;
}

s32 func_8080182C_chpiranha(Actor *param_0, s32 param_1, s32 param_2)
{
    f32 local_0[3];
    f32 local_1[3];
    f32 local_2[3];
    PiranhaPlacement49 *local_3;
    Actor *local_4;
    if (param_1 == 0x95) {
        func_8080106C_chpiranha(param_0);
        local_3 = func_80100094(param_0, 0);
        local_4 = func_808016D0_chpiranha(param_0);
        local_3->local_4 = param_0->position[1];
        func_800EE7F8(local_3->local_3, param_0->unk3C ? local_4->position : param_0->position);
        if ((param_0->unk0->unk24 >> 22) == 0x2C1) local_3->local_3[1] += 250.0f;
        else local_3->local_3[1] += 100.0f;
        func_800EE7F8(param_0->position, local_3->local_3);
        func_800EE7F8((f32 *)param_0->actorData, param_0->position);
        func_800EE7F8(local_0, param_0->position);
        func_800EE7F8(local_1, param_0->position);
        local_0[1] += 50.0f;
        local_1[1] -= 500.0f;
        if (func_800BEF00(local_0, local_1, local_2, param_0->unk14)) local_3->local_4 = local_1[1];
        if (param_0->unk3C) local_3->local_6 = (u32)*(u16 *)((u8 *)param_0->unk3C + 0x12) >> 1;
        else local_3->local_6 = 0;
        local_3->local_1 = 1;
        if (param_0->unk3C) func_800DA3B8(0x34, 1);
        if ((param_0->unk0->unk24 >> 22) == 0x2C1)
            func_80800218_chpiranha(param_0, param_0->unk3C ? 1 : 2);
        else func_80800218_chpiranha(param_0, param_0->unk3C ? 7 : 2);
        param_0->unk58 = 0.0f;
        param_0->unk64_20 = func_800DB9B0() | func_800DA298(0x650);
    } else {
        return 0;
    }
    return 1;
}

int chpiranha_entrypoint_0()
{
  return (int)&D_80801B60_chpiranha;
}

int chpiranha_entrypoint_1()
{
  return (int)&D_80801BA8_chpiranha;
}

int chpiranha_entrypoint_2()
{
  return (int)&D_80801BF0_chpiranha;
}
