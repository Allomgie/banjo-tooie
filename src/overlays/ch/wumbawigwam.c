#include "common.h"

extern void *func_80100094(Actor *, u32);
extern void func_800EE7F8(f32 *, f32 *);
extern void func_800DF500(f32, f32, f32);
extern u8 B_808011F0_chwumbawigwam[];
extern u8 B_808011E4_chwumbawigwam[];
extern u8 B_808011C0_chwumbawigwam[];
extern int D_8080116C_chwumbawigwam;
extern u32 func_800F54E4(void);
extern s32 func_800F64A4(u32, s32);
extern f32 func_80103EAC(Actor *);
extern void func_800EFA4C(f32 *, f32, f32, f32);
extern void func_80103110(Actor *, s32);
extern void func_800F5A00(u32, f32 *);
extern f32 func_80103EF4(Actor *);
extern s32 func_800F00A4(f32 *, f32, f32, f32, f32 *);
extern f32 func_8010CD28(Actor *);
extern void _gcgoto_entrypoint_5(s32, s32, f32);
extern void _sumumbofx_entrypoint_6(void *, f32, f32, s32, s32, f32 *, f32 *, void *);
extern void _sumumbofx_entrypoint_14(void *);
extern s32 _sumumbofx_entrypoint_27(void *);
extern f32 _sumumbofx_entrypoint_21(void *);
extern void _sumumbofx_entrypoint_5(void *, f32);
extern f32 func_800F12D4(f32, f32, f32, f32, f32);
extern f32 func_800F10B4(f32, f32, f32, f32, f32);
extern f32 func_800F0E00(f32, f32);
extern f32 func_800138D0(f32);
extern f32 func_80013970(f32);
extern void _subaddieaudioquick_entrypoint_2(Actor *, f32 *, void *);
extern void func_800BBCB8(f32 *, f32 *, f32, s32, void *);
extern void func_800C4140(s32, f32 *, s32);
typedef struct { f32 local_0[3]; } WigwamPosition;
extern void _sumumbofx_entrypoint_24(void *, f32);
extern void _sumumbofx_entrypoint_15(void *, f32);
extern void _sumumbofx_entrypoint_18(void *, f32);
extern void _sumumbofx_entrypoint_17(void *, f32);
extern void _sumumbofx_entrypoint_16(void *, f32);
void func_80800B9C_chwumbawigwam();

void func_80800000_chwumbawigwam(Actor *param_0)
{
  s32 pad0;
    f32 local_2;
    f32 local_1;
    f32 local_3;
    f32 local_0;

    if (func_800EA05C() == 0x112) {
        if (func_800DA298(0x18A) && func_800EA05C() == 0x112) param_0->scale = 2.8f;
        else param_0->scale = 1.0f;
        local_0 = func_80103EAC(param_0);
        local_1 = func_800F64A4(func_800F54E4(), 0x40000) ? 1.0f : 0.6f;
        local_2 = func_800F64A4(func_800F54E4(), 0x40000) ? 40.0f : param_0->scale * 280.0f;
        if (func_8010C9FC(param_0->position, (s32)(local_1 * local_0), (s32)local_2, 0)) {
            func_80800B9C_chwumbawigwam(param_0, 2);
        } else {
            func_80800B9C_chwumbawigwam(param_0, 3);
        }
        local_3 = 1.0f;
        func_800EFA4C((f32 *)&param_0->actorData[4], local_3, local_3, local_3);
    }
}

void func_80800158_chwumbawigwam(Actor *param_0)
{
    extern WigwamPosition D_808010E0_chwumbawigwam;
    extern u8 D_808010EC_chwumbawigwam[];
    extern u8 D_80801100_chwumbawigwam[];
    extern u8 D_80801114_chwumbawigwam[];
    extern u8 D_80801158_chwumbawigwam[];

    f32 local_1[3];
    f32 local_2[3];

    switch (param_0->unk70_10) {
        case 1:
            func_80103110(param_0, 0);
            break;

        case 2:
            func_800F5A00(func_800F54E4(), local_1);

            if (!func_800F00A4(
                    param_0->position,
                    func_80103EAC(param_0) * (func_800F64A4(func_800F54E4(), 0x40000) ? 1.0f : 0.6f),
                    func_800F64A4(func_800F54E4(), 0x40000) ? 40.0f : param_0->scale * 280.0f,
                    0,
                    local_1)) {
                func_80800B9C_chwumbawigwam(param_0, 3);
            }
            break;

        case 3:
            func_800F5A00(func_800F54E4(), local_2);

            if (func_800F00A4(
                    param_0->position,
                    func_80103EAC(param_0) * (func_800F64A4(func_800F54E4(), 0x40000) ? 1.0f : 0.6f),
                    func_800F64A4(func_800F54E4(), 0x40000) ? 40.0f : param_0->scale * 280.0f,
                    0,
                    local_2)) {
                func_8010A624(param_0);

                if (func_800DA298(0x18A) &&
                    func_800EA05C() == 0x112) {
                    _gcgoto_entrypoint_5(
                        0x122,
                        1,
                        func_8010CD28(param_0) + 180.0f
                    );
                } else {
                    _gcgoto_entrypoint_5(
                        0x11E,
                        1,
                        func_8010CD28(param_0) + 180.0f
                    );
                }
            }
            break;

        case 4:
            if (func_800DA298(0x9DE)) {
                func_80800B9C_chwumbawigwam(param_0, 5);
            }
            break;

        case 5:

            _sumumbofx_entrypoint_6(
                func_80100094(param_0, 1),
                func_80103EF4(param_0),
                *(f32 *)((char *)param_0 + 0x38) * (f32)(u32)*(u16 *)((char *)param_0 + 0x62),
                0,
                0x28,
                (char *)param_0 + 4,
                0,
                0
            );

            _sumumbofx_entrypoint_14(
                func_80100094(param_0, 1)
            );

            if (_sumumbofx_entrypoint_27(
                    func_80100094(param_0, 1))) {
                func_80800B9C_chwumbawigwam(param_0, 6);
            }
            break;

        case 6:

            _sumumbofx_entrypoint_6(
                func_80100094(param_0, 1),
                func_80103EF4(param_0),
                *(f32 *)((char *)param_0 + 0x38) * (f32)(u32)*(u16 *)((char *)param_0 + 0x62),
                0,
                0x28,
                (char *)param_0 + 4,
                0,
                0
            );

            _sumumbofx_entrypoint_14(
                func_80100094(param_0, 1)
            );

            _sumumbofx_entrypoint_5(
                func_80100094(param_0, 1),
                3.0f
            );

            if (_sumumbofx_entrypoint_27(
                    func_80100094(param_0, 1))) {
                if (func_800DA298(0x18A)) {
                    func_80800B9C_chwumbawigwam(param_0, 8);
                } else {
                    func_80800B9C_chwumbawigwam(param_0, 7);
                }
            }
            break;

        case 7: {
            f32 local_4;
            WigwamPosition local_9;
            if (_sumumbofx_entrypoint_21(func_80100094(param_0, 1)) > 2.5f) {
                if (!param_0->unk64_19) {
                    _subaddieaudioquick_entrypoint_2(
                        param_0,
                        (char *)param_0 + 4,
                        D_808010EC_chwumbawigwam
                    );

                    param_0->unk64_19 = 1;
                }

                local_4 = func_800F12D4(
                    _sumumbofx_entrypoint_21(func_80100094(param_0, 1)),
                    4.0f,
                    2.5f,
                    1.0f,
                    2.0f
                );

                *(f32 *)((char *)param_0 + 0x28) = local_4;
                *(f32 *)((char *)param_0 + 0x2C) = local_4;
                *(f32 *)((char *)param_0 + 0x30) = local_4;
            } else {
                local_4 = func_800F10B4(
                    _sumumbofx_entrypoint_21(func_80100094(param_0, 1)),
                    2.5f,
                    0.0f,
                    1.0f,
                    0.0f
                );

                if (!param_0->unk64_20) {
                    _subaddieaudioquick_entrypoint_2(
                        param_0,
                        (char *)param_0 + 4,
                        D_80801100_chwumbawigwam
                    );

                    param_0->unk64_20 = 1;
                }

                *(f32 *)((char *)param_0 + 0x28) =
                    (func_800138D0(local_4 * 3.0f * 360.0f) * local_4) + 1.0f;

                *(f32 *)((char *)param_0 + 0x2C) =
                    (func_800138D0(local_4 * 5.0f * 360.0f) * local_4) + 1.0f;

                *(f32 *)((char *)param_0 + 0x30) =
                    *(f32 *)((char *)param_0 + 0x28);

                *(f32 *)((char *)param_0 + 0x38) =
                    func_800F12D4(
                        _sumumbofx_entrypoint_21(func_80100094(param_0, 1)),
                        2.5f,
                        0.0f,
                        1.0f,
                        2.8f
                    );
            }





            _sumumbofx_entrypoint_6(
                func_80100094(param_0, 1),
                func_80103EF4(param_0) * *(f32 *)((char *)param_0 + 0x2C),
                ((f32)(u32)*(u16 *)((char *)param_0 + 0x62) * *(f32 *)((char *)param_0 + 0x38)) *
                    func_800F0E00(*(f32 *)((char *)param_0 + 0x28), *(f32 *)((char *)param_0 + 0x30)),
                0,
                0x28,
                (char *)param_0 + 4,
                0,
                0
            );

            _sumumbofx_entrypoint_14(
                func_80100094(param_0, 1)
            );

            if (_sumumbofx_entrypoint_27(
                    func_80100094(param_0, 1))) {
                func_80800B9C_chwumbawigwam(param_0, 9);
            }

            if (_sumumbofx_entrypoint_21(func_80100094(param_0, 1)) <= 2.0f &&
                !param_0->unk74_29) {
                local_9 = D_808010E0_chwumbawigwam;

                func_800BBCB8(
                    local_9.local_0,
                    local_9.local_0,
                    1.0f,
                    0xF,
                    D_80801114_chwumbawigwam
                );

                func_800C4140(
                    0x7FFB5BF2,
                    local_9.local_0,
                    0x1F4003E8
                );

                param_0->unk74_29 = 1;
            }
            break;

        }
        case 8: {
            f32 local_4;
            local_4 = func_800F10B4(
                _sumumbofx_entrypoint_21(func_80100094(param_0, 1)),
                4.0f,
                0.0f,
                1.0f,
                0.0f
            );

            if (!param_0->unk64_20) {
                _subaddieaudioquick_entrypoint_2(
                    param_0,
                    (char *)param_0 + 4,
                    D_80801158_chwumbawigwam
                );

                param_0->unk64_20 = 1;
            }

            *(f32 *)((char *)param_0 + 0x28) =
                (func_80013970(local_4 * 6.0f * 360.0f) * (local_4 * 0.5f)) + 1.0f;

            *(f32 *)((char *)param_0 + 0x2C) =
                (func_80013970(local_4 * 7.0f * 360.0f) * (local_4 * 0.5f)) + 1.0f;

            *(f32 *)((char *)param_0 + 0x30) =
                *(f32 *)((char *)param_0 + 0x28);

            *(f32 *)((char *)param_0 + 0x38) =
                func_800F12D4(
                    _sumumbofx_entrypoint_21(func_80100094(param_0, 1)),
                    4.0f,
                    2.5f,
                    2.8f,
                    1.0f
                );





            _sumumbofx_entrypoint_6(
                func_80100094(param_0, 1),
                func_80103EF4(param_0) * *(f32 *)((char *)param_0 + 0x2C),
                ((f32)(u32)*(u16 *)((char *)param_0 + 0x62) * *(f32 *)((char *)param_0 + 0x38)) *
                    func_800F0E00(*(f32 *)((char *)param_0 + 0x28), *(f32 *)((char *)param_0 + 0x30)),
                0,
                0x28,
                (char *)param_0 + 4,
                0,
                0
            );

            _sumumbofx_entrypoint_14(
                func_80100094(param_0, 1)
            );

            if (_sumumbofx_entrypoint_27(
                    func_80100094(param_0, 1))) {
                func_80800B9C_chwumbawigwam(param_0, 9);
            }
            break;

        }
        case 9:

            _sumumbofx_entrypoint_6(
                func_80100094(param_0, 1),
                func_80103EF4(param_0),
                *(f32 *)((char *)param_0 + 0x38) * (f32)(u32)*(u16 *)((char *)param_0 + 0x62),
                0,
                0x28,
                (char *)param_0 + 4,
                0,
                0
            );

            _sumumbofx_entrypoint_14(
                func_80100094(param_0, 1)
            );

            if (_sumumbofx_entrypoint_27(
                    func_80100094(param_0, 1))) {
                func_80800B9C_chwumbawigwam(param_0, 0xA);
            }
            break;

        case 10:
            func_80800B9C_chwumbawigwam(param_0, 3);
            break;
    }
}

void func_80800B9C_chwumbawigwam(param_0, param_1) Actor *param_0; s32 param_1;
{
    s32 local_0[3];
    s32 local_2;
    s32 local_3;
    void *local_1;

    switch (param_1) {
    case 4:
        _subaddieDll_entrypoint_4(param_0, 1);
        param_0->unk64_20 = 0;
        param_0->unk64_19 = 0;
        param_0->unk74_29 = 0;
        func_8010A800(param_0, 2);
        break;
    case 5:
        local_0[0] = 0;
        local_0[1] = 0;
        local_0[2] = 0;
        _sumumbofx_entrypoint_0(param_0, 1, 0x28, (s16)_chmumbopad_entrypoint_0(9));
        _sumumbofx_entrypoint_2(func_80100094(param_0, 1));
        _sumumbofx_entrypoint_25(func_80100094(param_0, 1), 0x7D, local_0);
        local_1 = func_80100094(param_0, 1);
        func_800DA298(0x18A);
        _sumumbofx_entrypoint_24(local_1, 1.5f);
        _sumumbofx_entrypoint_15(func_80100094(param_0, 1), 3.0f);
        func_80101180(0x2B0, 0xBB, 9);
        _capod_entrypoint_13(*(u32 *)param_0, 0, 0xE, 0x210);
        func_800DA544(0x57D);
        break;
    case 6:
        _sumumbofx_entrypoint_18(func_80100094(param_0, 1), 3.0f);
        break;
    case 7:
        _sumumbofx_entrypoint_17(func_80100094(param_0, 1), 4.0f);
        func_800DA544(0x18A);
        break;
    case 8:
        _sumumbofx_entrypoint_17(func_80100094(param_0, 1), 4.0f);
        func_800DA524(0x18A);
        break;
    case 9:
        _sumumbofx_entrypoint_16(func_80100094(param_0, 1), 3.0f);
        if (func_800DA298(0x18A)) param_0->scale = 2.8f;
        else param_0->scale = 1.0f;
        *(f32 *)((u8 *)param_0 + 0x28) = 1.0f;
        *(f32 *)((u8 *)param_0 + 0x2C) = 1.0f;
        *(f32 *)((u8 *)param_0 + 0x30) = 1.0f;
        _chglowbo_entrypoint_6();
        break;
    case 10:
        _sumumbofx_entrypoint_1(param_0, 1);
        func_8010A800(param_0, 0);
        func_800DA544(0x9DF);
        _subaddieDll_entrypoint_4(param_0, 0);
        break;
    }
    func_80101FDC(param_0, param_1);
}

void func_80800E04_chwumbawigwam(Actor *param_0, s32 param_1)
{
    f32 *local_0;
    f32 *local_1;
    s32 local_2;
    if (func_80100094(param_0, 1) != NULL) {
        _sumumbofx_entrypoint_9(func_80100094(param_0, 1), param_1);
    }
    if (param_0->unk70_10 == 7 || param_0->unk70_10 == 8) {
        for (local_2 = 4, local_0 = (f32 *)B_808011F0_chwumbawigwam, local_1 = (f32 *)B_808011E4_chwumbawigwam;
             local_2 != 0; local_2--, local_0 -= 3, local_1 -= 3) {
            func_800EE7F8(local_0, local_1);
            if (local_0[0] != 0.0f && local_0[1] != 0.0f && local_0[2] != 0.0f) {
                func_800DF500(local_0[0], local_0[1], local_0[2]);
                _subaddiefade_entrypoint_1(param_0, 160 - local_2 * 30);
                *((u8 *)param_0 + 0x7A) = (*((u8 *)param_0 + 0x7A) & 0xFF3F) | 0x80;
                func_80101870(param_0, param_1);
            }
        }
        func_800EE7F8((f32 *)B_808011C0_chwumbawigwam, (f32 *)&param_0->actorData[4]);
        if (((f32 *)param_0->actorData)[4] != 0.0f &&
            ((f32 *)param_0->actorData)[5] != 0.0f && ((f32 *)param_0->actorData)[6] != 0.0f) {
            func_800DF500(((f32 *)param_0->actorData)[4],
                ((f32 *)param_0->actorData)[5], ((f32 *)param_0->actorData)[6]);
        }
        *((u8 *)param_0 + 0x7A) = (*((u8 *)param_0 + 0x7A) & 0xFF3F) | 0x40;
    }
    _subaddiefade_entrypoint_1(param_0, 255);
    func_80101870(param_0, param_1);
    if (func_80100094(param_0, 1) != NULL) {
        _sumumbofx_entrypoint_8(func_80100094(param_0, 1), param_1);
    }
}

s32 func_80800FEC_chwumbawigwam(Actor *param_0, s32 param_1, s32 param_2)
{
    switch (param_1) {
    case 0x4B:
        if (param_2 == 9 && (s32)param_0->unk70_10 < 5) {
            func_80800B9C_chwumbawigwam(param_0, 4);
            return 1;
        }
        return 0;
    case 0x2E:
        return 1;
    case 0xB:
        func_800DA524(0x9DE);
        return 3;
    }
    return 0;
}

int chwumbawigwam_entrypoint_0()
{
  return (int)&D_8080116C_chwumbawigwam;
}
