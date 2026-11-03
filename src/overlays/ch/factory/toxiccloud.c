#include "common.h"

typedef struct ToxicCloudFlags {
    u32 pad_0 : 26;
    u32 local_0 : 1;
    u32 pad_1 : 5;
} ToxicCloudFlags;
extern void *func_80100094(Actor *, u32);
extern f32 func_800F5F24(s32);
extern void func_800EFE50(f32 *, void *, void *, f32);
extern void func_800EEB9C(f32 *, f32, f32);
extern void func_800EF1B8(f32 *, f32, f32);
typedef struct {
    u8 pad[0x64];
    u32 pad1 : 2;
    u32 big : 1;
    u32 pad2 : 29;
} ToxicFlags97;
extern f32 func_800EEB40(f32 *, f32 *);
typedef struct ToxicCloudNode {
    s32 pad_0;
    f32 local_0;
    u8 pad_1[6];
    s16 local_1;
} ToxicCloudNode;
typedef struct ToxicCloudRoute {
    u32 local_0 : 7;
    u32 pad_0 : 15;
    u32 local_1 : 6;
    u32 pad_1 : 4;
} ToxicCloudRoute;
extern u8 D_80801434_chfactorytoxiccloud[];
extern u8 D_80801518_chfactorytoxiccloud[];
extern u8 D_8080155C_chfactorytoxiccloud[];
extern void func_800BBCB8(f32 *, f32 *, f32, s32, void *);
typedef struct {
    u8 pad_0[0x78];
    u32 pad_1 : 29;
    u32 local_0 : 1;
    u32 pad_2 : 2;
} ToxicCloudFlags26;
extern int D_80801568_chfactorytoxiccloud[];
typedef struct {
    u8 pad_0[0x64];
    u32 pad_1 : 2;
    u32 local_0 : 1;
    u32 pad_2 : 29;
    u8 pad_3[0x10];
    u32 pad_4 : 29;
    u32 local_1 : 1;
    u32 pad_5 : 2;
} ToxicCloudActorFlags;
extern s32 func_800D91EC(f32 *, f32);
extern f32 func_800F10B4(f32, f32, f32, f32, f32);
extern f32 func_800F15F8(f32, f32, f32);
extern f32 func_800D8FF8(void);
extern f32 func_800DC0C0(void);
extern f32 func_800F1DF4(f32 *, f32 *);
extern f32 func_800EEAD4(f32 *, f32 *);
extern f32 func_800EFB8C(f32 *, f32 *);
extern void func_80102BAC(Actor *, f32, f32, f32);
extern void func_800EF334(f32 *, f32);
extern s32 _subaddieDll_entrypoint_11(Actor *, s32, s32);
extern void _subaddiefade_entrypoint_1(Actor *, u32);
extern void func_80102424(Actor *, s32);
typedef struct {
    f32 timer;
    f32 elapsed;
    s32 index;
    f32 first;
    f32 second;
} ToxicCloudParticle;
extern f32 func_800DC178(f32, f32);
typedef struct {
    f32 local_0;
    f32 local_1;
    s32 local_2;
    f32 local_3;
    f32 local_4;
    u8 pad_0[0x10];
} CloudParticle301;
typedef struct {
    f32 local_0[9][2];
} CloudOffsets301;
typedef struct {
    u8 pad_0[0x64];
    u32 pad_1 : 2;
    u32 local_0 : 1;
    u32 pad_2 : 29;
    u8 pad_3[0x10];
    u32 pad_4 : 29;
    u32 local_1 : 1;
    u32 pad_5 : 2;
    u32 pad_6 : 19;
    u32 local_2 : 1;
    u32 pad_7 : 12;
} CloudActorFlags301;
extern CloudOffsets301 D_808014D0_chfactorytoxiccloud;
extern void _subaddiedraw25d_entrypoint_0(void);
extern void *func_800D674C(s32);
extern void func_800E3980(f32 *);
extern void func_800F18FC(f32 *, f32 *, f32 *);
extern void func_800EEC30(f32 *, f32, f32, f32);
extern void func_800EE780(f32 *, f32 *, f32 *);
extern f32 func_800F1214(f32, f32, f32);
extern void func_800E24E4(void (*)(void), Actor *);
extern void func_800E2AA4(void *, void *, s32, s32, f32 *, f32 *);
extern f32 _subaddiejoy_entrypoint_3(Actor *);
extern f32 func_80013728(f32);
extern f32 mlAbsF(f32);
s32 func_80800BF8_chfactorytoxiccloud();
void func_80800FCC_chfactorytoxiccloud();
void func_80800A34_chfactorytoxiccloud();
void func_808010B8_chfactorytoxiccloud();

void func_80800000_chfactorytoxiccloud(Actor *param_0)
{
    u8 *local_0;
    s32 local_1;

    local_0 = func_80100094(param_0, 0);
    if (((ToxicCloudFlags *) ((u8 *) param_0 + 0x78))->local_0) {
        param_0->scale = 1.0f;
        _subaddiefade_entrypoint_1(param_0, 255);
        *(f32 *) ((u8 *) param_0 + 0x24) = 600.0f;
    } else {
        func_80102424(param_0, 1);
        param_0->unk58 = 0.0f;
        _subaddiefade_entrypoint_1(param_0, 0);
        param_0->unk64_16 = 0;
        param_0->scale = 0.0f;
        func_8010A570(param_0);
    }
    param_0->unk64_24 = 1;
    func_80800FCC_chfactorytoxiccloud(param_0, 1);
    for (local_1 = 0; local_1 < 9; local_1++) {
        func_80800A34_chfactorytoxiccloud(param_0, local_0 + local_1 * 0x24);
    }
}

s32 func_808000F0_chfactorytoxiccloud(u8 *param_0, s32 param_1)
{
    u32 *new_var;
    u32 temp_t9;
    new_var = (u32 *) ((s8 *) param_0 + 0x70);
    if (func_800CC338(param_1, (*new_var >> 0x19) - 1, ((u32) (*new_var << 0x16) >> 0x1A) - 1) ==
        -1) {
        return 0;
    }
    if (func_80800BF8_chfactorytoxiccloud(param_0, param_1) == 0) {
        return 0;
    }
    temp_t9 = (u16) *(u16 *) ((s8 *) param_0 + 0x72);
    temp_t9 = temp_t9 >> 0xA;
    if (temp_t9 == 5) {
        return 0;
    }
    if (temp_t9 == 1) {
        return 0;
    }
    if (func_800F64A4(func_800F54E4(), 0x1601) == 0) {
        return 0;
    }
    return 1;
}

s32 func_808012C4_chfactorytoxiccloud();

int func_80801164_chfactorytoxiccloud();

void func_80800AD8_chfactorytoxiccloud();

void func_808001B8_chfactorytoxiccloud(Actor *param_0)
{
    extern u8 D_8080148C_chfactorytoxiccloud[];

    f32 local_0[3];
    f32 local_3;
    s32 local_8;
    f32 local_2;
    f32 local_4;
    f32 local_1[3];
    char *local_6;
    char *local_7;
    s32 local_11;
    f32 local_12;

    func_80800AD8_chfactorytoxiccloud(param_0, local_0);

    local_8 = func_808000F0_chfactorytoxiccloud(param_0, local_0);
    if (local_8) {
        func_80102424(param_0, 4);
    } else if (param_0->unk64_19) {
        func_800CF494();
        param_0->unk64_19 = 0;
    }

    if (!((ToxicCloudActorFlags *) param_0)->local_1) {
        switch (param_0->unk70_10) {
            case 1:
                if (func_800D91EC((char *) param_0 + 0x58, 0.3f)) {
                    _subaddiefade_entrypoint_1(param_0, 0xFF);
                    *(f32 *) ((char *) param_0 + 0x38) = 1.0f;

                    if (((ToxicCloudActorFlags *) param_0)->local_0) {
                        func_80102424(param_0, 3);
                    } else {
                        func_80102424(param_0, 2);
                    }
                } else {
                    local_3 =
                        func_800F10B4(*(f32 *) ((char *) param_0 + 0x58), 0.0f, 0.3f, 0.0f, 1.0f);

                    _subaddiefade_entrypoint_1(param_0, (u16) (u32) (255.0f * local_3));

                    *(f32 *) ((char *) param_0 + 0x38) = local_3;
                    param_0->unk64_16 = 1;

                    func_8010A590(param_0);

                    *(f32 *) ((char *) param_0 + 8) += 10.0f;
                }
                break;

            case 2:
                if (((ToxicCloudActorFlags *) param_0)->local_0) {
                    func_808010B8_chfactorytoxiccloud(param_0);
                } else {
                    *(f32 *) ((char *) param_0 + 0x24) = func_800F15F8(
                        *(f32 *) ((char *) param_0 + 0x24), 150.0f, func_800D8FF8() * 200.0f);

                    func_80102BAC(param_0, 0.5f, 0.05f, 5.0f);

                    local_8 = func_80801164_chfactorytoxiccloud(param_0, 0x125, 4);

                    if ((local_8 & 4) != 0 || func_800DC0C0() < 0.004f) {
                        local_2 = func_800DC0C0() * 360.0f;
                        local_8 = 0;

                        do {
                            if (_subaddieDll_entrypoint_11(param_0, (s32) local_2,
                                                           (s32) *
                                                               (f32 *) ((char *) param_0 + 0x24))) {
                                *(f32 *) ((char *) param_0 + 0x54) = local_2;
                                break;
                            }

                            local_8++;
                        } while (local_8 != 6);
                    }

                    if (func_800CC338(local_0, (*(u32 *) ((char *) param_0 + 0x70) >> 25) - 1,
                                      ((*(u32 *) ((char *) param_0 + 0x70) << 22) >> 26) - 1) !=
                        -1) {
                        if (func_808012C4_chfactorytoxiccloud(param_0)) {
                            func_80102424(param_0, 3);
                        }
                    }
                }

                func_80800FCC_chfactorytoxiccloud(param_0, 0);

                *(f32 *) ((char *) param_0 + 8) = func_800F15F8(
                    *(f32 *) ((char *) param_0 + 8), *(f32 *) ((char *) param_0 + 0x34) + 120.0f,
                    func_800D8FF8() * 100.0f);

                if (*(f32 *) ((char *) param_0 + 0x28) < *(f32 *) ((char *) param_0 + 8)) {
                    *(f32 *) ((char *) param_0 + 8) = *(f32 *) ((char *) param_0 + 0x28);
                }
                break;

            case 3:
                if (((ToxicCloudActorFlags *) param_0)->local_0) {
                    func_808010B8_chfactorytoxiccloud(param_0);
                } else {
                    *(f32 *) ((char *) param_0 + 0x54) =
                        func_800F1DF4((char *) param_0 + 4, local_0);

                    func_80102BAC(param_0, 1.0f, 0.1f, 10.0f);

                    *(f32 *) ((char *) param_0 + 0x24) = func_800F15F8(
                        *(f32 *) ((char *) param_0 + 0x24), 600.0f, func_800D8FF8() * 500.0f);

                    local_8 = func_80801164_chfactorytoxiccloud(param_0, 0x125, 4);

                    if (local_8 & 4) {
                        func_80102424(param_0, 2);
                    }

                    if (func_800CC338(local_0, (*(u32 *) ((char *) param_0 + 0x70) >> 25) - 1,
                                      ((*(u32 *) ((char *) param_0 + 0x70) << 22) >> 26) - 1) ==
                            -1 ||
                        !func_808012C4_chfactorytoxiccloud(param_0)) {
                        func_80102424(param_0, 2);
                    }
                }

                func_80800FCC_chfactorytoxiccloud(param_0, 0);

                if (*(f32 *) ((char *) param_0 + 0x34) < local_0[1] &&
                    local_0[1] < *(f32 *) ((char *) param_0 + 0x28)) {
                    *(f32 *) ((char *) param_0 + 8) = func_800F15F8(
                        *(f32 *) ((char *) param_0 + 8), local_0[1], func_800D8FF8() * 100.0f);
                } else {
                    *(f32 *) ((char *) param_0 + 8) = func_800F15F8(
                        *(f32 *) ((char *) param_0 + 8),
                        *(f32 *) ((char *) param_0 + 0x34) + 120.0f, func_800D8FF8() * 100.0f);

                    if (*(f32 *) ((char *) param_0 + 0x28) < *(f32 *) ((char *) param_0 + 8)) {
                        *(f32 *) ((char *) param_0 + 8) = *(f32 *) ((char *) param_0 + 0x28);
                    }
                }
                break;

            case 4:
                if (((ToxicCloudActorFlags *) param_0)->local_0) {
                    func_808010B8_chfactorytoxiccloud(param_0);
                } else {
                    local_12 = func_800EEAD4(local_0, (char *) param_0 + 4);
                    local_4 = local_12 / func_800D8FF8() / 600.0f;

                    *(f32 *) ((char *) param_0 + 0x24) =
                        func_800EFB8C((char *) param_0 + 4, local_0) / func_800D8FF8();

                    if (600.0f < *(f32 *) ((char *) param_0 + 0x24)) {
                        *(f32 *) ((char *) param_0 + 0x24) = 600.0f;
                    }

                    if (1.0f < local_4) {
                        func_800EFB24(local_1, local_0, (char *) param_0 + 4);

                        func_800EF334(local_1, 1.0f / local_4);

                        func_800EF04C((char *) param_0 + 4, local_1);
                    } else {
                        *(f32 *) ((char *) param_0 + 4) = local_0[0];
                        *(f32 *) ((char *) param_0 + 0xC) = local_0[2];
                    }

                    *(f32 *) ((char *) param_0 + 0x54) = func_800F5F24(func_800F54E4());

                    func_80102BAC(param_0, 1.0f, 0.1f, 10.0f);
                }

                func_80102424(param_0, 3);

                if (!param_0->unk64_19) {
                    func_800CF2D4(4);
                    param_0->unk64_19 = 1;
                }

                func_80800FCC_chfactorytoxiccloud(param_0, 0);

                if (*(f32 *) ((char *) param_0 + 0x34) < local_0[1] &&
                    local_0[1] < *(f32 *) ((char *) param_0 + 0x28)) {
                    *(f32 *) ((char *) param_0 + 8) = func_800F15F8(
                        *(f32 *) ((char *) param_0 + 8), local_0[1], func_800D8FF8() * 100.0f);
                } else {
                    *(f32 *) ((char *) param_0 + 8) = func_800F15F8(
                        *(f32 *) ((char *) param_0 + 8),
                        *(f32 *) ((char *) param_0 + 0x34) + 120.0f, func_800D8FF8() * 100.0f);

                    if (*(f32 *) ((char *) param_0 + 0x28) < *(f32 *) ((char *) param_0 + 8)) {
                        *(f32 *) ((char *) param_0 + 8) = *(f32 *) ((char *) param_0 + 0x28);
                    }
                }
                break;

            case 5:
                if (!((ToxicCloudActorFlags *) param_0)->local_1) {
                    func_80102424(param_0, 2);
                }
        }

        if (param_0->unk70_10 != 5 && param_0->unk7C_12) {
            local_6 = (char *) func_80100094(param_0, 0);
            for (local_11 = 0; local_11 < 9; local_11++) {
                local_7 = local_6 + local_11 * 0x24;
                if (func_800D91EC((f32 *) (local_7 + 4), *(f32 *) local_7)) {
                    if (func_800DC0C0() < 0.5f) {
                        func_800BBCB8((char *) param_0 + 4, 0, param_0->scale, 1,
                                      D_8080148C_chfactorytoxiccloud);
                    }

                    func_80800A34_chfactorytoxiccloud(param_0, local_7);
                }
            }
        }
    }
}

void func_80800A34_chfactorytoxiccloud(param_0, param_1) Actor *param_0;
ToxicCloudParticle *param_1;
{
    param_1->timer = func_800DC178(0.5f, 1.0f);
    param_1->elapsed = 0.0f;
    param_1->first = func_800DC178(0.4f, 0.5f) + 0.2f;
    param_1->second = func_800DC178(0.7f, 0.9f) + 0.2f;
    param_1->index = func_800DC128(0, 16);
}

void func_80800AD8_chfactorytoxiccloud(s32 param_0, f32 *param_1)
{
    f32 local_0[3];
    f32 local_1[3];
    s32 local_2;
    local_2 = func_800F5410(func_800F54E4());
    switch (local_2) {
        case 1:
        case 10:
        case 11:
            func_800F5A2C(func_800F54E4(), 5, local_0);
            func_800F5A2C(func_800F54E4(), 2, local_1);
            func_800EFE50(param_1, local_0, local_1, 0.5f);
            func_800EEB9C(local_0, func_800F5F24(func_800F54E4()), 20.0f);
            local_0[1] += 20.0f;
            func_800EF04C(param_1, local_0);
            break;
        default:
            func_800F5A00(func_800F54E4(), param_1);
            func_800EF1B8(param_1, func_800F5F24(func_800F54E4()), 30.0f);
            param_1[1] += 140.0f;
    }
}

s32 func_80800BF8_chfactorytoxiccloud(param_0, param_1)
Actor *param_0;
f32 *param_1;
{
    f32 local_1;
    f32 local_0;

    if (((ToxicFlags97 *) param_0)->big) {
        local_0 = 6.0f;
    } else {
        local_0 = 2.0f;
    }
    local_1 = local_0 * 25.0f;
    return func_800EEB40(param_1, (f32 *) ((u8 *) param_0 + 0x18)) < local_1 * local_1;
}

void func_80800C7C_chfactorytoxiccloud(Actor *param_0, void *param_1)
{
    f32 local_0[3];
    f32 local_1[3];
    f32 local_2[2];
    f32 local_6;
    void *local_3;
    f32 local_7;
    f32 local_8;
    f32 local_4[3];
    s32 local_9;
    s32 local_10;
    CloudOffsets301 local_5;
    f32 *local_11;
    CloudParticle301 *local_12;
    CloudParticle301 *local_13;

    func_80101870(param_0);
    if (((CloudActorFlags301 *)param_0)->local_2) {
        local_3 = func_800D674C(0x9D0);
        local_12 = func_80100094(param_0, 0);
        local_11 = (f32 *)param_0->actorData;
        _subaddieskeleton_entrypoint_1(param_0, 4, local_11);
        func_800E3980(local_0);
        func_800F18FC(local_11, local_0, local_2);
        for (local_10 = 0, local_13 = local_12; local_10 != 9; local_10++, local_13++) {
            if (local_13->local_0 != 0.0f) {
                local_6 = func_800F10B4(local_13->local_1, 0.0f, local_13->local_0, 0.0f, 1.0f);
                local_5 = D_808014D0_chfactorytoxiccloud;
                func_800EEC30(local_0, local_2[0] + local_5.local_0[local_10][0],
                local_2[1] + local_5.local_0[local_10][1], ((CloudActorFlags301 *)param_0)->local_0 ? 75.0f : 25.0f);
                func_800EE780(local_1, local_11, local_0);
                if (((CloudActorFlags301 *)param_0)->local_0) { local_7 = param_0->scale * 3.0f; } else { local_7 = param_0->scale; } local_4[0] = local_4[1] = local_4[2] = func_800F1214(local_6, local_13->local_3, local_13->local_4) * local_7;
                if (local_6 < 0.2f) {
                    local_9 = func_800F10B4(local_6, 0.0f, 0.2f, 0.0f, 140.0f);
                } else if (local_6 < 0.9f) {
                    local_9 = 140;
                } else {
                    local_9 = func_800F10B4(local_6, 0.9f, 1.0f, 140.0f, 0.0f);
                }
                if (((CloudActorFlags301 *)param_0)->local_1) {
                    local_9 >>= 1;
                }
                func_800E24E4(_subaddiedraw25d_entrypoint_0, param_0);
                func_800E24F8(10, 255, 4);
                func_800E2440(4, 140, 2);
                func_800E257C(local_9);
                func_800E24B4(0);
                func_800E2588(1);
                func_800E2AA4(param_1, local_3, local_13->local_2, 0, local_1, local_4);
            }
        }
    }
}

void func_80800FCC_chfactorytoxiccloud(param_0, param_1) Actor *param_0;
s32 param_1;
{
    ToxicCloudNode *local_3;
    f32 local_0[3];
    f32 local_1[3];
    f32 local_2[3];

    if (!func_8001210C(3) || param_1) {
        func_800EE7F8(local_0, param_0->position);
        local_0[1] += 400.0f;
        func_800EE7F8(local_1, param_0->position);
        local_1[1] -= 1000.0f;
        if (func_800BEF00(local_0, local_1, local_2, 0)) {
            *(f32 *) ((u8 *) param_0 + 0x34) = local_1[1];
        } else {
            *(f32 *) ((u8 *) param_0 + 0x34) = param_0->position[1];
        }
        local_3 = (ToxicCloudNode *) func_800CC63C(
            ((ToxicCloudRoute *) ((u8 *) param_0 + 0x70))->local_0 - 1,
            ((ToxicCloudRoute *) ((u8 *) param_0 + 0x70))->local_1 - 1);
        *(f32 *) ((u8 *) param_0 + 0x28) = local_3->local_0 + local_3->local_1 - 25.0f;
    }
}

void func_808010B8_chfactorytoxiccloud(param_0) Actor *param_0;
{
    f32 local_0;

    local_0 = _subaddiejoy_entrypoint_3(param_0) * 650.0f;
    func_80102BAC(param_0, 1.5f, 1.0f, 25.0f);
    if (mlAbsF(func_80013728(param_0->unk54 - param_0->rotation[1])) < 90.0f) {
        *(f32 *) &param_0->actorData[3] = local_0;
    } else {
        *(f32 *) &param_0->actorData[3] = local_0 / 10.0f;
    }
    func_8010BA80(param_0, 0x200026, 0x20);
}

int func_80801164_chfactorytoxiccloud(u8 *param_0)
{
    f32 local_0;

    local_0 = *(f32 *) ((char *) param_0 + 0x48);
    *(f32 *) ((char *) param_0 + 0x48) = *(f32 *) ((char *) param_0 + 0x54);
    func_8010BA80();
    *(f32 *) ((char *) param_0 + 0x48) = local_0;
}

int func_808011A0_chfactorytoxiccloud(Actor *param_0, unsigned int param_1, s32 param_2)
{
    switch (param_1) {
        case 0x40:
            func_800BBCB8((f32 *) param_0->actorData, 0, param_0->scale, 4,
                          D_80801518_chfactorytoxiccloud);
            func_800FFAB0(param_0);
            if (param_0->unk64_19) {
                func_800CF494();
                param_0->unk64_19 = 0;
            }
            return 1;
        case 1:
            if (param_0->unk70_10 != 1) {
                func_80102424(param_0, 3);
            }
            return 1;
        case 2:
            if (!func_80107070(param_0, 1)) {
                func_80102424(param_0, 6);
                _subaddiefade_entrypoint_3(param_0);
            }
            return 1;
        case 0x38:
            func_80101074(D_80801434_chfactorytoxiccloud);
            return 2;
        case 0x97:
            func_80101010(D_8080155C_chfactorytoxiccloud);
            return 1;
        default:
            return 0;
    }
}

s32 func_808012C4_chfactorytoxiccloud(Actor *param_0)
{
    Actor *local_0[10];
    s32 local_1;
    s32 local_2;
    s32 local_3;
    f32 local_5;
    f32 local_4[3];

    local_1 = _subaddiefind_entrypoint_4(0x3FF, local_0, 10);
    if (local_1 >= 2) {
        local_3 = 1;
        func_800F5A00(func_800F54E4(), local_4);
        local_5 = func_800EEB40(param_0->position, local_4);
        for (local_2 = 0; local_2 < local_1; local_2++) {
            if (!((ToxicCloudFlags26 *) local_0[local_2])->local_0) {
                if (param_0 != local_0[local_2]) {
                    local_3 &= local_5 < func_800EEB40(local_0[local_2]->position, local_4);
                    if (!local_3) {
                        return 0;
                    }
                }
            }
        }
        return local_3;
    }
    return 1;
}

int chfactorytoxiccloud_entrypoint_0()
{
    return (int) &D_80801568_chfactorytoxiccloud;
}

extern void func_80105834();
extern void func_80108ED0();
extern void func_80107C2C();
u32 D_80801420_chfactorytoxiccloud[5] = {0x20000, 0x60000, 0x60000, 0x0, 0x70000};
u8 D_80801434_chfactorytoxiccloud[24] = {0x0,  0x0,  0x0,  0x3,  0x3F, 0xC0, 0x0, 0x0,
                                         0x0,  0x1,  0x0,  0x0,  0x0,  0x0,  0x0, 0x1,
                                         0x3F, 0x99, 0x99, 0x9A, 0x2,  0x3,  0x0, 0x0};
u32 D_8080144C_chfactorytoxiccloud[16] = {
    0x0,        0x0,       0x3F800000, 0x2690001, 0x40000000, 0x2690001, 0x3F800000, 0x2690001,
    0x3F800000, 0x2690001, 0x3F800000, 0x2690021, 0x3F800000, 0x2690001, 0x3F800000, 0x2690001};
u8 D_8080148C_chfactorytoxiccloud[68] = {
    0x0,  0x1D, 0x9,  0xD0, 0x0, 0x16, 0x0, 0x8,  0x0, 0x18, 0x0, 0x0,  0x0,  0xF,
    0x0,  0x0,  0x0,  0x23, 0x0, 0xE,  0x0, 0x0,  0x0, 0x32, 0x0, 0x2B, 0x0,  0xC0,
    0x1,  0x0,  0x0,  0x22, 0x0, 0x66, 0x0, 0x80, 0x1, 0x80, 0x2, 0x0,  0x0,  0x15,
    0x0,  0x73, 0x0,  0x99, 0x0, 0x20, 0xA, 0xFF, 0x3, 0x3C, 0x0, 0x2C, 0xFF, 0xCE,
    0xFF, 0xCE, 0xFF, 0xCE, 0x0, 0x32, 0x0, 0x0,  0x0, 0x32, 0x0, 0x0};
CloudOffsets301 D_808014D0_chfactorytoxiccloud = {0.0f,   -9e+01f, 0.0f,    0.0f, 0.0f,   9e+01f,
                                                  45.0f,  -45.0f,  9e+01f,  0.0f, 45.0f,  45.0f,
                                                  -45.0f, -45.0f,  -9e+01f, 0.0f, -45.0f, 45.0f};
u8 D_80801518_chfactorytoxiccloud[68] = {
    0x0, 0x1D, 0x9,  0xD0, 0x0, 0x16, 0x0, 0x8,  0x0, 0x18, 0x0, 0x0,  0x0,  0xF,
    0x0, 0x0,  0x0,  0x23, 0x0, 0xE,  0x0, 0x0,  0x0, 0x32, 0x0, 0x2B, 0x0,  0xF5,
    0x1, 0x8C, 0x0,  0x22, 0x0, 0x33, 0x0, 0xC0, 0x2, 0x33, 0x2, 0x80, 0x0,  0x15,
    0x0, 0x59, 0x0,  0x99, 0x0, 0x20, 0xA, 0xFF, 0x3, 0x50, 0x0, 0x2C, 0xFF, 0x9C,
    0x0, 0x64, 0xFF, 0x9C, 0x0, 0x64, 0x0, 0xC8, 0x0, 0x64, 0x0, 0x0};
u8 D_8080155C_chfactorytoxiccloud[12] = {0x0, 0x0, 0x0, 0x0, 0x42, 0xC8,
                                         0x0, 0x0, 0x0, 0x0, 0x0,  0x0};
int D_80801568_chfactorytoxiccloud[18] = {0x11603FF,
                                          0x7090002,
                                          (u32) &D_8080144C_chfactorytoxiccloud,
                                          (u32) func_808001B8_chfactorytoxiccloud,
                                          (u32) func_80105834,
                                          (u32) func_80800C7C_chfactorytoxiccloud,
                                          0xFA00000,
                                          0x0,
                                          0x0,
                                          0xA20261,
                                          0x0,
                                          (u32) func_80108ED0,
                                          0x1440000,
                                          (u32) func_80800000_chfactorytoxiccloud,
                                          (u32) func_80107C2C,
                                          -0x7FDFABF3,
                                          (u32) func_808011A0_chfactorytoxiccloud,
                                          (u32) &D_80801420_chfactorytoxiccloud};
