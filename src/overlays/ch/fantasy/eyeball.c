#include "common.h"

extern void _subaddielink_entrypoint_0(void *);
extern s32 _subaddiefind_entrypoint_4(s32, Actor **, s32);
extern void func_800EEC30(f32 *, f32, f32, f32);
extern void func_800EF04C(f32 *, f32 *);
extern void func_800EFA4C(f32 *, f32, f32, f32);
extern int func_800D0B68(int, int);
extern void *func_80100094(Actor *, u32);
extern int _subaddielink_entrypoint_4(void *);
extern void func_8010C964(void *);
extern int D_80801F28_chfantasyeyeball;
extern void func_800BA3FC();
extern void func_800EFDE8();
extern f32 func_800D8FF8(void);
extern s32 func_800D91EC(f32 *, f32);
extern f32 func_800F10B4(f32, f32, f32, f32, f32);
extern f32 func_80013970(f32);
extern void func_800EF174(f32 *, f32 *, f32);
extern void func_800EE7F8(f32 *, f32 *);
extern s32 func_800BF340(f32 *, f32 *, f32 *, s32, f32);
extern s32 func_800BABB8(s32, f32 *, f32 *, f32, u8 *);
extern u8 D_80801F70_chfantasyeyeball[];
extern u8 D_80801FB0_chfantasyeyeball[];
extern Actor *func_80106790();
extern f32 func_800DC178(f32, f32);
typedef union { Unk80132ED0 *local_0; s32 local_1; } FantasyEyeEvent39;
extern u8 D_80801FC0_chfantasyeyeball[];
extern int D_80802008_chfantasyeyeball;
typedef struct { u8 pad_0[0x78]; u32 pad_1:29; u32 local_0:1; u32 pad_2:2; } EyeballFlags561;
extern void _sudeflect_entrypoint_0(f32 *, f32, f32, s32);
extern s32 func_80101E14(Actor *, f32);
extern s32 func_800D90A4(f32 *);
extern void _subaddiefade_entrypoint_1(s32, s32);
extern void func_8010C93C(Actor *, f32 *, f32);
extern s32 D_80801E98_chfantasyeyeball;
extern Actor *func_80108528(s32, f32 *, s32, Actor **);
extern f32 func_800EEAD4(f32 *, f32 *);
extern void func_8010D12C(s32, f32 *, f32, s32);
extern void func_800EEBF0(f32 *, f32 *, f32);
extern f32 func_800DC0C0(void);
extern f32 func_800136E4(f32);
extern f32 func_800F1FF0(f32, f32, f32, f32, f32);
extern int func_800E0AF0(s32, f32);
extern int func_800E0AFC(s32, s32, f32, f32, f32, f32);
extern int func_800E0B8C(s32, s32, f32, f32, f32, f32);
extern int func_8010C754(Actor *);
void func_80801740_chfantasyeyeball();
void func_80801BC4_chfantasyeyeball();
void func_80800950_chfantasyeyeball();
void func_808010B0_chfantasyeyeball();
void func_80801290_chfantasyeyeball(Actor *param_0, f32 param_1, s32 param_2);
void func_808013F8_chfantasyeyeball();
s32 func_808017B4_chfantasyeyeball();

void func_80800000_chfantasyeyeball(Actor *param_0)
{
    if (func_800D0B68(0x4C, 1)) {
        func_800FFAB0(param_0);
        return;
    }
    if (!(param_0->unk74_7 - 0x32) && !func_800D0B68(0x4C, 1)) {
        param_0->unk64_20 = 1;
    } else {
        param_0->unk64_20 = 0;
    }
    func_808010B0_chfantasyeyeball(param_0, (f32 *)&param_0->actorData[2], (f32 *)&param_0->actorData[4]);
    func_808010B0_chfantasyeyeball(param_0, (f32 *)&param_0->actorData[0], (f32 *)&param_0->actorData[1]);
    param_0->unk64_19 = 0;
    _subaddielink_entrypoint_0(func_80100094(param_0, 0));
    *(f32 *)&param_0->actorData[6] = 0.0f;
}




































void func_80801378_chfantasyeyeball();

void func_80801314_chfantasyeyeball();

void func_808011D0_chfantasyeyeball(Actor *param_0, f32 param_1, f32 param_2, f32 param_3);

void func_808000D8_chfantasyeyeball(Actor *param_0)
{
    extern u8 D_80801EEC_chfantasyeyeball[];

    f32 local_0[3];
    s32 local_3;
    s32 local_4;
    s32 local_1;
    s32 local_8;
    f32 local_5;
    s32 local_2;
    u16 local_6;

    _sudeflect_entrypoint_0(
        (char *)param_0 + 4,
        *(f32 *)((char *)param_0 + 0x38) * 456.0f,
        *(f32 *)((char *)param_0 + 0x38) * 224.0f,
        0xE
    );

    if (((EyeballFlags561 *)param_0)->local_0) {
        return;
    }

    switch (param_0->unk70_10) {
        case 1:
            if (func_8010C9B0((char *)param_0 + 4, 0x1388) &&
                func_800F6720(func_800F54E4())) {
                func_80800950_chfantasyeyeball(param_0, 2);
            }
            break;

        case 2:
            if (func_80101DDC(param_0)) {
                func_80800950_chfantasyeyeball(param_0, 3);
            }

            if (!func_800DA298(0x6EC)) {
                func_800D90A4((char *)param_0 + 0x58);

                local_5 = func_800F10B4(
                    *(f32 *)((char *)param_0 + 0x58),
                    2.707999945f,
                    0.0f,
                    1.0f,
                    0.0f
                );

                func_808011D0_chfantasyeyeball(
                    param_0,
                    *(f32 *)((char *)param_0 + 0x20),
                    *(f32 *)((char *)param_0 + 0x28),
                    local_5
                );
            }

            if (func_80101E14(param_0, 0.4f)) {
                func_800C4140(
                    0x8CBB5C1E,
                    (char *)param_0 + 4,
                    0x1B5801F4
                );
            } else if (func_80101E14(param_0, 0.0f)) {
                func_800C4140(
                    0x7FFB5C1D,
                    (char *)param_0 + 4,
                    0x1B5801F4
                );
            }
            break;

        case 3:
            if (!func_800DA298(0x6EC)) {
                local_1 = func_800D90A4(
                    (char *)param_0 + 0x58
                );

                if (!local_1 || param_0->unk64_19) {
                    local_5 = func_800F10B4(
                        *(f32 *)((char *)param_0 + 0x58),
                        2.707999945f,
                        0.0f,
                        1.0f,
                        0.0f
                    );

                    func_808011D0_chfantasyeyeball(
                        param_0,
                        *(f32 *)((char *)param_0 + 0x20),
                        *(f32 *)((char *)param_0 + 0x28),
                        local_5
                    );
                } else {
                    func_80801314_chfantasyeyeball(param_0);
                    func_800DA544(0x6EC);
                }
            } else if (func_8010C9B0(
                           (char *)param_0 + 4,
                           0x1388)) {
                if (!func_800F6720(func_800F54E4())) {
                    func_80800950_chfantasyeyeball(
                        param_0,
                        4
                    );
                } else if (func_800D90A4(
                               (char *)param_0 + 0x24) &&
                           func_808017B4_chfantasyeyeball(param_0)) {
                    func_80800950_chfantasyeyeball(
                        param_0,
                        5
                    );
                }
            }
            break;

        case 4:
            if (func_80101DDC(param_0)) {
                func_80800950_chfantasyeyeball(param_0, 1);
            }
            break;

        case 5:
            if (func_80101E14(param_0, 0.55f)) {
                local_6 =
                    (u16)(u32)(func_800DC178(
                        1.15f,
                        1.25f
                    ) * 1023.0f);

                func_800C4140(
                    (local_6 << 21) + 0x1B5E3D,
                    (char *)param_0 + 4,
                    0x1B5801F4
                );

                func_80108B04(param_0, 1);
            } else if (func_80101DDC(param_0)) {
                func_80800950_chfantasyeyeball(param_0, 3);
            }
            break;

        case 7:
        case 10:
            if (func_80101DDC(param_0)) {
                if (param_0->unk64_20) {
                    if (*(s32 *)((char *)param_0 + 0x34) != 0) {
                        if ((param_0->unk70_10)
                            == 7) {
                            local_2 = 8;
                        } else {
                            local_2 = 0xB;
                        }

                        func_80800950_chfantasyeyeball(
                            param_0,
                            local_2
                        );
                    } else {
                        local_1 = _subaddielink_entrypoint_4(
                            func_80100094(param_0, 0)
                        );

                        func_8010A590(local_1);

                        if ((param_0->unk70_10)
                            == 7) {
                            local_2 = 9;
                        } else {
                            local_2 = 0xC;
                        }

                        func_80800950_chfantasyeyeball(
                            param_0,
                            local_2
                        );
                    }
                } else {
                    if ((param_0->unk70_10)
                        == 7) {
                        local_2 = 9;
                    } else {
                        local_2 = 0xC;
                    }

                    func_80800950_chfantasyeyeball(
                        param_0,
                        local_2
                    );
                }
            }

            if (param_0->unk64_20) {
                func_800D90A4((char *)param_0 + 0x58);

                local_5 = func_800F10B4(
                    *(f32 *)((char *)param_0 + 0x58),
                    2.707999945f,
                    0.0f,
                    1.0f,
                    0.0f
                );

                func_808011D0_chfantasyeyeball(
                    param_0,
                    *(f32 *)((char *)param_0 + 0x20),
                    *(f32 *)((char *)param_0 + 0x28),
                    local_5
                );
            }

            if (func_80101E14(param_0, 0.35f)) {
                func_80801740_chfantasyeyeball(
                    param_0,
                    local_0
                );

                local_3 = 0;

                do {
                    local_4 = func_800B53A4(3);

                    func_800BA3FC(
                        local_4,
                        local_3 + 0x9DF
                    );

                    func_800BABB8(
                        local_4,
                        local_0,
                        local_0,
                        3.0f,
                        D_80801EEC_chfantasyeyeball
                    );

                    local_3++;
                } while (local_3 != 8);

                func_800C4140(
                    0xBFDB5C13,
                    (char *)param_0 + 4,
                    0x1B5801F4
                );

                func_80108B04(param_0, 2);
            }
            break;

        case 8:
        case 11:
            local_1 = _subaddielink_entrypoint_4(
                func_80100094(param_0, 0)
            );

            if (func_800D90A4((char *)param_0 + 0x58)) {
                func_80800950_chfantasyeyeball(param_0,
                    param_0->unk70_10 == 8 ? 9 : 0xC);
            } else {
                local_5 = func_800F10B4(
                    *(f32 *)((char *)param_0 + 0x58),
                    2.707999945f,
                    0.0f,
                    1.0f,
                    0.0f
                );

                func_808011D0_chfantasyeyeball(
                    param_0,
                    *(f32 *)((char *)param_0 + 0x20),
                    *(f32 *)((char *)param_0 + 0x28),
                    local_5
                );
            }

            local_5 = func_800F10B4(
                *(f32 *)((char *)param_0 + 0x58),
                1.5f,
                0.0f,
                255.0f,
                0.0f
            );

            _subaddiefade_entrypoint_1(
                local_1,
                (s32)local_5
            );
            break;

        case 6:
            local_8 = _subaddielink_entrypoint_4(
                func_80100094(param_0, 0)
            );

            if (func_800D90A4((char *)param_0 + 0x58)) {
                func_80801314_chfantasyeyeball(param_0);
                func_80800950_chfantasyeyeball(param_0, 1);
            }

            local_5 = func_800F10B4(
                *(f32 *)((char *)param_0 + 0x58),
                1.5f,
                0.0f,
                0.0f,
                1.0f
            );

            _subaddiefade_entrypoint_1(
                local_8,
                (s32)(local_5 * 255.0f)
            );

            func_808011D0_chfantasyeyeball(
                param_0,
                *(f32 *)((char *)param_0 + 0x18),
                *(f32 *)((char *)param_0 + 0x1C),
                local_5
            );
            break;

        case 9:
        case 12:
            if (param_0->unk64_20) {
                func_800D90A4((char *)param_0 + 0x58);
                func_800D90A4((char *)param_0 + 0x2C);

                if (!param_0->unk64_19) {
                    func_80801314_chfantasyeyeball(param_0);
                    func_800FC6B0(0x18);
                    func_800FFA88(
                        *(s32 *)((char *)param_0 + 0)
                    );
                    return;
                }

                local_5 = func_800F10B4(
                    *(f32 *)((char *)param_0 + 0x58),
                    2.707999945f,
                    0.0f,
                    1.0f,
                    0.0f
                );

                func_808011D0_chfantasyeyeball(
                    param_0,
                    *(f32 *)((char *)param_0 + 0x20),
                    *(f32 *)((char *)param_0 + 0x28),
                    local_5
                );
            } else if (func_800D90A4(
                           (char *)param_0 + 0x2C)) {
                func_800FFA88(
                    *(s32 *)((char *)param_0 + 0)
                );
            }

            local_5 = func_800F10B4(
                *(f32 *)((char *)param_0 + 0x2C),
                1.5f,
                0.0f,
                255.0f,
                0.0f
            );

            *(u8 *)((char *)param_0 + 0x9B) =
                (u32)local_5;
            break;
    }

    func_808013F8_chfantasyeyeball(param_0);

    func_8010C93C(
        param_0,
        (char *)param_0 + 4,
        0.75f
    );

    if (param_0->unk70_10 != 9 &&
        param_0->unk70_10 != 0xC &&
        (param_0->unk64_20)) {
        func_80801378_chfantasyeyeball(param_0);
    }
}

f32 func_808016B4_chfantasyeyeball();

s32 func_80800FEC_chfantasyeyeball();

void func_80800F78_chfantasyeyeball();

void func_80800950_chfantasyeyeball(param_0, param_1) Actor *param_0; s32 param_1;
{
    s32 local_0;

    switch (param_1) {
    case 2:
        if (!func_800DA298(0x6EC)) {
            func_80801290_chfantasyeyeball(param_0, 4.0f, 0);
        }
        if (!func_800DA298(0x6D4)) {
            func_800DA544(0x6D4);
            _subaddiedialog_entrypoint_11(param_0->unk0, 0x141A, 0xF, param_0->position, 0x22);
        }
        break;
    case 3:
        *(f32 *)&param_0->actorData[3] = func_808016B4_chfantasyeyeball(param_0);
        break;
    case 7:
    case 10:
        if (param_0->unk64_20 && !func_800DA298(0x6D5)) {
            func_800DA544(0x6D5);
            _subaddiedialog_entrypoint_11(param_0->unk0, 0x141B, 0xF, param_0->position, 0x22);
        }
        func_800C4140(0xB31B5DB8, param_0->position, 0x1B5801F4);
        if (param_0->unk64_20) {
            func_80800FEC_chfantasyeyeball(param_0);
            func_80801290_chfantasyeyeball(param_0, 2.708f, 0);
        }
        break;
    case 8:
    case 11:
        func_800C3F48(0x4CBB5CEE);
        break;
    case 6:
        func_800C3F48(0x4CBB5CED);
        _subaddieDll_entrypoint_4(param_0, 1);
        func_80801290_chfantasyeyeball(param_0, 1.5f, 1);
        break;
    case 9:
    case 12:
        if (param_0->unk64_20) {
            local_0 = param_0->actorData[7];
            if (local_0) {
                func_80800F78_chfantasyeyeball(param_0, func_80106790((Unk80132ED0 *)local_0));
            } else if (!func_800DA298(0x6BD)) {
                func_800DA544(0x6BD);
                _subaddiedialog_entrypoint_11(param_0->unk0, 0x141C, 0xF, param_0->position, 0x22);
            }
        }
        param_0->unk64_19 = 0;
        *(f32 *)&param_0->actorData[5] = 1.5f;
        break;
    }
    func_80102424(param_0, param_1);
}

s32 func_80800B68_chfantasyeyeball(Actor *param_0, s32 param_1, s32 param_2)
{
    Actor *local_0;
    Actor *local_1;
    f32 local_2[2];
    f32 local_3[3];
    f32 local_7;
    f32 local_4[3];
    Actor *local_5;

    switch (param_1) {
    case 0x3F:
        switch (param_0->unk70_10) {
        case 1:
        case 2:
        case 4:
        case 6:
            func_80800950_chfantasyeyeball(param_0, 7);
            break;
        case 3:
        case 5:
            func_80800950_chfantasyeyeball(param_0, 0xA);
            break;
        }
        if (!func_800D0B68(0x4C, 1)) {
            func_800FC6B0(0xE);
        }
        return 1;
    case 0x40:
        if (((f32 *)param_0->actorData)[6] <= 0.0f && !((EyeballFlags561 *)param_0)->local_0) {
            func_800C4140(0x3FEFA49D, param_0->position, 0x04B000FA);
        }
        ((f32 *)param_0->actorData)[6] = 2.0f;
        return 1;
    case 0x38:
        func_80101074(&D_80801E98_chfantasyeyeball);
        return 7;
    case 0x3D:
        switch (param_2) {
        case 0:
            if (!func_800D0B68(0x4C, 1) && !func_800D0A9C(0x4C, 1)) {
                local_0 = func_80106790(func_800D10D4(0x4C, 1, param_0->position, 3, 0));
                _subaddielink_entrypoint_1(func_80100094(param_0, 0), local_0->unk0, local_0);
                ((u8 *)local_0)[0x77] &= ~0x20;
                func_8010A570(local_0);
            }
            return 1;
        case 1:
            func_80801740_chfantasyeyeball(param_0, local_3);
            local_1 = func_80108528(0x483, local_3, 0, &param_0);
            func_800F5A00(func_800F54E4(), local_3);
            local_3[1] += 40.0f;
            local_1->unk58 = func_800EEAD4(local_1->position, local_3) / 1200.0f;
            func_8010D12C(func_800F54E4(), local_3, local_1->unk58, 0);
            local_7 = func_800EEAD4(local_1->position, local_3);
            local_1->unk58 = local_7 / 1200.0f;
            ((f32 *)local_1->actorData)[7] = func_800F10B4(local_7, 500.0f, 5000.0f, 100.0f, 600.0f);
            func_800F18FC(local_1->position, local_3, local_2);
            func_800EEBF0((f32 *)&local_1->actorData[4], local_2, 1200.0f);
            return 1;
        case 2:
            func_80801740_chfantasyeyeball(param_0, local_4);
            local_5 = func_80108528(0x483, local_4, 0, &param_0);
            local_5->scale = 3.0f;
            _chskeletonexplode_entrypoint_7(local_5, local_5->position);
            return 1;
        }
        return 0;
    case 0xF:
        local_5 = func_80106790(func_80101080());
        _chskeletonexplode_entrypoint_3(local_5, 3, 2);
        _chskeletonexplode_entrypoint_4(local_5, 6);
        return 1;
    case 0x1F:
        func_801015D0(param_0);
        func_800DF744(3, 1);
        return 1;
    case 0x2E:
        if (((s16 *)&param_2)[0] == 0x141A || ((s16 *)&param_2)[0] == 0x141B || ((s16 *)&param_2)[0] == 0x141C) {
            param_0->unk64_19 = 0;
        }
        return 1;
    case 0x95:
        if (!_subaddielink_entrypoint_3(func_80100094(param_0, 0)) && !func_800D0B68(0x4C, 1) && param_0->unk64_20) {
            func_80108B04(param_0, 0);
        }
        return 1;
    }
    return 0;
}

void func_80800F78_chfantasyeyeball(u8 *param_0, u8 *param_1)
{
  u8 *new_var;
  s32 local_0;
  *((u8 *) (((s8 *) param_0) + 0x65)) = (u8) ((*((u8 *) (((s8 *) param_0) + 0x65))) & 0xFFEF);
  new_var = param_1;
  *((u8 *) (((s8 *) param_1) + 0x65)) = (u8) (((*((u8 *) (((s8 *) new_var) + 0x65))) & 0xFFFFu) | 0x10);
  func_80800950_chfantasyeyeball(param_1, 6);
  local_0 = func_80100094(param_0, 0);
  _subaddielink_entrypoint_5(local_0, func_80100094(param_1, 0));
}

s32 func_80800FEC_chfantasyeyeball(Actor *param_0)
{
    Actor *local_0[15];
    s32 local_1;
    s32 local_2;
    s32 local_3;
    s32 local_4;
    s32 local_5;

    local_1 = _subaddiefind_entrypoint_4(0x482, local_0, 15);
    local_2 = -1;
    local_3 = 255;
    for (local_4 = 0; local_4 < local_1; local_4++) {
        if ((s32)local_0[local_4]->unk70_10 < 7 && param_0 != local_0[local_4]) {
            local_5 = local_0[local_4]->unk74_7;
            if (local_5 < local_3) {
                local_2 = local_4;
                local_3 = local_5;
            }
        }
    }
    if (local_2 == -1) {
        param_0->actorData[7] = 0;
        return 0;
    }
    param_0->actorData[7] = (s32)local_0[local_2]->unk0;
    return 1;
}

void func_808010B0_chfantasyeyeball(param_0, param_1, param_2) Actor *param_0; f32 *param_1; f32 *param_2;
{
    f32 local_0[3];
    f32 local_2;
    f32 local_1[3];
    f32 local_3;
    local_2 = func_800DC0C0() * 360.0f;
    *param_1 = func_800DC0C0() * 20.0f + 20;
    local_3 = local_2 + 360.0f;
    *param_2 = local_2;
    while (*param_2 < local_3) {
        func_800EEC30(local_1, *param_1, *param_2, 2500.0f);
        func_800EF04C(local_1, param_0->position);
        if (!func_800BEF00(param_0->position, local_1, local_0, 0)) break;
        *param_2 += 30.0f;
    }
}

void func_808011D0_chfantasyeyeball(Actor *param_0, f32 param_1, f32 param_2, f32 param_3)
{
    f32 local_0[3];
    f32 local_1[3];
    f32 local_2[3];

    func_800EEC30(local_1, param_1, param_2, 500.0f * param_3 + 2000.0f);
    func_800EF04C(local_1, param_0->position);
    func_800EFA4C(local_2, param_0->position[0], param_0->position[1] + param_0->scale * 224.0f,
                 param_0->position[2]);
    func_800A516C(local_0, local_2, local_1);
    func_800E39D8(local_1, local_0);
}

void func_80801290_chfantasyeyeball(Actor *param_0, f32 param_1, s32 param_2)
{
    _subaddieDll_entrypoint_4(param_0, 1);
    param_0->unk58 = 2.708f;
    param_0->unk64_19 = 1;
    if (param_2 == 0) {
        func_800F7B9C(func_800F54E4(), 0x6B);
        func_800A50B0(1);
        func_800F82D4(func_800F54E4(), 2);
    }
}

void func_80801314_chfantasyeyeball(u8 *param_0) {
    func_800F82D4(func_800F54E4(), 0);
    _subaddieDll_entrypoint_4(param_0, 0);
    func_800F7B9C(func_800F54E4(), 0x6C);
    func_800A50B0(2);
    param_0[0x65] = param_0[0x65] & 0xFFF7;
}

void func_80801378_chfantasyeyeball(Actor *param_0)
{
    Actor *local_0;
    if (!func_800D0B68(0x4C, 1) && param_0->unk7C_12) {
        local_0 = (Actor *)_subaddielink_entrypoint_4(func_80100094(param_0, 0));
        if (local_0) {
            func_80801740_chfantasyeyeball(param_0, local_0->position);
            local_0->position[1] -= 48.0f;
            func_8010C964(local_0);
        }
    }
}

void func_808013F8_chfantasyeyeball(param_0) Actor *param_0;
{
    s32 local_0;
    f32 local_1[3];
    f32 local_2[3];
    f32 local_3[2];
    f32 local_4;
    f32 local_5;


    local_0 = func_8010262C(param_0->unk0, 3);
    if (local_0) {
        local_4 = func_800D8FF8();
        if ((s32)param_0->unk70_10 < 7) {
            func_800F5A00(func_800F54E4(), local_2);
            func_80801740_chfantasyeyeball(param_0, local_1);
            func_800F18FC(local_1, local_2, local_3);
            if (local_3[0] < 310.0f && local_3[0] > 180.0f) {
                local_3[0] = 320.0f;
            }
            if (param_0->unk70_10 == 1 || param_0->unk70_10 == 4) {
                local_3[0] = func_800136E4(80.0f - local_3[0]);
            } else {
                local_3[0] = func_800136E4(45.0f - local_3[0]);
            }
            local_3[1] = func_800136E4(local_3[1] - param_0->rotation[1]);
            param_0->unk54 = func_800F1FF0(param_0->unk54, local_3[1], 0.75f, local_4 * 2.0f, 90.0f * local_4);
            param_0->unk50 = func_800F1FF0(param_0->unk50, local_3[0], 0.75f, local_4 * 2.0f, 90.0f * local_4);
            func_800E0ACC(local_0);
            func_800E0AF0(local_0, 1.0f);
            func_800E0AFC(local_0, 0x2C, -1.0f, param_0->unk50, 0.0f, 0.0f);
            func_800E0AFC(local_0, 1, -1.0f, 0.0f, param_0->unk54, 0.0f);
            if (!func_800D90A4(&((f32 *)param_0->actorData)[6])) {
                local_5 = func_800F10B4(((f32 *)param_0->actorData)[6], 2.0f, 0.0f, 1.0f, 0.0f);
                func_800E0B8C(local_0, 1, -1.0f,
                    func_80013970(1800.0f * local_5) * 0.25f * local_5 + 1.0f,
                    func_80013970(2520.0f * local_5) * 0.25f * local_5 + 1.0f,
                    func_80013970(1080.0f * local_5) * 0.25f * local_5 + 1.0f);
            }
        }
    }
}

f32 func_808016B4_chfantasyeyeball(Actor *param_0)
{
    Actor *local_0[10];
    s32 local_1 = 0;
    s32 local_2;
    for (local_2 = _subaddiefind_entrypoint_4(0x482, local_0, 10) - 1; local_2 >= 0; local_2--) {
        if ((s32)local_0[local_2]->unk70_10 < 7) local_1++;
    }
    return local_1 * 0.5f;
}

void func_80801740_chfantasyeyeball(param_0, param_1) Actor *param_0; f32 param_1[3];
{
    extern void func_800EE7F8(f32 *, f32 *);

    if (param_0->unk7C_12) {
        _subaddieskeleton_entrypoint_1(param_0, 4, param_1);
    } else {
        func_800EE7F8(param_1, param_0->position);
        param_1[1] += param_0->scale * 224.0f;
    }
}

s32 func_808017B4_chfantasyeyeball(param_0) Actor *param_0; {
    f32 temp_f0;

    temp_f0 = (f32) func_8010C754(param_0);
    if ((temp_f0 > 5000.0f) || (temp_f0 < 500.0f)) {
        return 0;
    }
    return func_8010D248();
}

int chfantasyeyeball_entrypoint_0()
{
    return (int)&D_80801F28_chfantasyeyeball;
}

void func_8080182C_chfantasyeyeball(Actor *param_0)
{
    f32 local_0[3];
    f32 local_1[3];
    s32 local_2;

    if (func_800D91EC(&(*(f32 *)((u8 *)param_0 + 0x24)), 5.0f)) {
        func_80801BC4_chfantasyeyeball(param_0, NULL);
        return;
    }
    func_800EE7F8(local_0, param_0->position);
    if ((*(f32 *)((u8 *)param_0 + 0x24)) <= param_0->unk58) {
        func_800EF174((f32 *)param_0->actorData, (f32 *)&param_0->actorData[4], func_800D8FF8());
        func_800EFA4C(param_0->position, (*(f32 *)&param_0->actorData[0]),
            (*(f32 *)&param_0->actorData[1]) + *(f32 *)&param_0->actorData[7] * func_80013970(func_800F10B4((*(f32 *)((u8 *)param_0 + 0x24)), 0.0f, param_0->unk58, 0.0f, 180.0f)), (*(f32 *)&param_0->actorData[2]));
    } else {
        *(f32 *)&param_0->actorData[5] += -2000.0f * func_800D8FF8();
        func_800EF174(param_0->position, (f32 *)&param_0->actorData[4], func_800D8FF8());
    }
    if (func_800BF340(local_0, param_0->position, local_1, 0x20020, param_0->scale * 33.0f)) {
        func_800EFB24(((f32 *)param_0->actorData), param_0->position, local_0);
        func_800EFDE8(((f32 *)param_0->actorData), ((f32 *)param_0->actorData), local_1);
        func_800EFB24(((f32 *)param_0->actorData), param_0->position, ((f32 *)param_0->actorData));
        func_80801BC4_chfantasyeyeball(param_0, ((f32 *)param_0->actorData));
        return;
    }
    _subaddieaudioloop_entrypoint_4(param_0, param_0->position, 1, D_80801FB0_chfantasyeyeball);
    local_2 = func_800B53A4(1);
    func_800BA3FC(local_2, func_800DC128(0, 9) + 0x9DF);
    func_800BABB8(local_2, param_0->position, NULL, 1.0f, D_80801F70_chfantasyeyeball);
    (*(f32 *)((u8 *)param_0 + 0x44)) += (*(f32 *)((u8 *)param_0 + 0x50)) * func_800D8FF8();
    (*(f32 *)((u8 *)param_0 + 0x48)) += (*(f32 *)((u8 *)param_0 + 0x54)) * func_800D8FF8();
}

int func_80801A50_chfantasyeyeball(Actor *param_0, s32 param_1, FantasyEyeEvent39 param_2)
{
    f32 local_0[3];
    Actor *local_1;
    switch (param_1) {
    case 0x3E:
        func_800F5A00(func_800F54E4(), local_0);
        func_80801BC4_chfantasyeyeball(param_0, local_0);
        return 1;
    case 0x3F:
        if (*(u16 *)((u8 *)(*(Unk80132ED0 * *)&param_2) + 0x18) & 1)
            func_80801BC4_chfantasyeyeball(param_0, func_80106790((*(Unk80132ED0 * *)&param_2))->position);
        else
            func_80801BC4_chfantasyeyeball(param_0, NULL);
        return 1;
    case 0xF:
        local_1 = func_80106790(func_80101080());
        _chskeletonexplode_entrypoint_3(local_1, 3, 2);
        _chskeletonexplode_entrypoint_4(local_1, 6);
        func_800FFA88(param_0->unk0);
        return 1;
    case 0x1F:
        func_801015D0(param_0);
        func_800DF744(3, 1);
        return 1;
    case 0x95:
        *(f32 *)((u8 *)param_0 + 0x54) = func_800DC178(180.0f, 360.0f);
        *(f32 *)((u8 *)param_0 + 0x50) = func_800DC178(180.0f, 360.0f);
        func_800EE7F8(param_0->actorData, param_0->position);
        *(f32 *)((u8 *)param_0 + 0x24) = 0.0f;
        return 1;
    }
    return 0;
}

void func_80801BC4_chfantasyeyeball(param_0, param_1) Actor *param_0; f32 *param_1;
{
    s32 local_0;
    s32 local_1;
    f32 *local_2 = param_0->position;

    for (local_0 = 0; local_0 < 8; local_0++) {
        local_1 = func_800BABB8(0, local_2, param_1 != NULL ? param_1 : local_2, 1.0f, D_80801FC0_chfantasyeyeball);
        func_800BA3FC(local_1, local_0 + 0x9DF);
        func_800BA22C(local_1, 3);
    }
    _chskeletonexplode_entrypoint_7(param_0, param_1 != NULL ? param_1 : local_2);
    func_800C4140(0x7FFF441F, local_2, 0x4B000FA);
}

int chfantasyeyeball_entrypoint_1()
{
    return &D_80802008_chfantasyeyeball;
}
