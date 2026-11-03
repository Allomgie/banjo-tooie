#include "common.h"

extern int D_80800918_chbosskogsdoor[];
typedef struct {
    u8 pad0[0x74];
    u8 unk74_7 : 1;
    u8 unk74_6 : 1;
    u8 unk74_0 : 6;
} BossKogsDoor;
extern int D_808009EC_chbosskogsdoor[];
extern s32 D_808008B0_chbosskogsdoor[];
extern u8 D_8080090C_chbosskogsdoor[];
extern u8 D_80800904_chbosskogsdoor[];
extern u8 D_808008F8_chbosskogsdoor[];
extern u8 D_808008E8_chbosskogsdoor[];
extern f32 func_800D8FF8(void);
extern void func_800BBCB8(f32 *, f32 *, f32, s32, void *);
extern s32 func_800D91EC(f32 *, f32);
extern f32 func_80103EF4(Actor *);
extern f32 func_800F10B4(f32, f32, f32, f32, f32);
extern s32 D_80800988_chbosskogsdoor[];
extern s32 D_80800994_chbosskogsdoor[];
extern s32 D_808009A0_chbosskogsdoor[];
extern s32 D_808009B0_chbosskogsdoor[];
extern s32 func_80101E14(Actor *, f32);
extern f32 func_80101F24(Actor *);
extern void func_800EFA4C(f32 *, f32, f32, f32);

void func_80800000_chbosskogsdoor(Actor *param_0)
{
    if (func_800DA298(0x1B8)) {
        param_0->unk58 = param_0->unk74_7 / 10.0f;
        func_80101FDC(param_0, 9);
    } else
        param_0->unk58 = 0.0f;
    ((f32 *) param_0->actorData)[7] = param_0->position[1];
}

void func_80800090_chbosskogsdoor(Actor *param_0)
{
    switch (param_0->unk70_10) {
        case 1:
            break;
        case 2:
            if (func_800D90A4(&param_0->actorData[5])) {
                func_80101FDC(param_0, 3);
                func_800DA544(0x1B8);
            }
            break;
        case 3:
            _subaddieaudioloop_entrypoint_4(param_0, param_0->position, 1,
                                            D_8080090C_chbosskogsdoor);
            ((f32 *) param_0->actorData)[2] += 1200.0f * func_800D8FF8();
            if (((f32 *) param_0->actorData)[2] > -220.0f) {
                ((f32 *) param_0->actorData)[2] = -220.0f;
                func_80101FDC(param_0, 4);
            }
            func_800BBCB8((f32 *) param_0->actorData, (f32 *) param_0->actorData, 1.0f, 1,
                          &D_808008B0_chbosskogsdoor);
            break;
        case 4:
            _subaddieaudioloop_entrypoint_4(param_0, param_0->position, 1,
                                            D_8080090C_chbosskogsdoor);
            ((f32 *) param_0->actorData)[1] += 1200.0f * func_800D8FF8();
            if (((f32 *) param_0->actorData)[1] > 2480.0f) {
                ((f32 *) param_0->actorData)[1] = 2480.0f;
                func_80101FDC(param_0, 5);
            }
            func_800BBCB8((f32 *) param_0->actorData, (f32 *) param_0->actorData, 1.0f, 1,
                          &D_808008B0_chbosskogsdoor);
            break;
        case 5:
            _subaddieaudioloop_entrypoint_4(param_0, param_0->position, 1,
                                            D_8080090C_chbosskogsdoor);
            ((f32 *) param_0->actorData)[2] += 1200.0f * func_800D8FF8();
            if (((f32 *) param_0->actorData)[2] > 0.0f) {
                ((f32 *) param_0->actorData)[2] = 0.0f;
                func_80101FDC(param_0, 6);
            }
            func_800BBCB8((f32 *) param_0->actorData, (f32 *) param_0->actorData, 1.0f, 1,
                          &D_808008B0_chbosskogsdoor);
            break;
        case 6:
            _subaddieaudioloop_entrypoint_4(param_0, param_0->position, 1,
                                            D_8080090C_chbosskogsdoor);
            ((f32 *) param_0->actorData)[1] -= 1200.0f * func_800D8FF8();
            if (((f32 *) param_0->actorData)[1] < 2204.0f) {
                func_80101FDC(param_0, 7);
                _subaddieaudioquick_entrypoint_2(param_0, param_0->position,
                                                 D_80800904_chbosskogsdoor);
                _subaddieaudioloop_entrypoint_2(param_0);
            }
            func_800BBCB8((f32 *) param_0->actorData, (f32 *) param_0->actorData, 1.0f, 4,
                          &D_808008B0_chbosskogsdoor);
            break;
        case 7:
            if (func_800D91EC(&param_0->unk58, (f32) param_0->unk74_7 / 10.0f)) {
                func_80101FDC(param_0, 8);
                _subaddieaudioloop_entrypoint_2(param_0);
                _subaddieaudioquick_entrypoint_2(param_0, param_0->position,
                                                 D_808008F8_chbosskogsdoor);
            } else {
                _subaddieaudioloop_entrypoint_4(param_0, param_0->position, 1,
                                                D_808008E8_chbosskogsdoor);
            }
            break;
        case 9:
            func_80103110(param_0, 0);
    }
    param_0->position[1] = ((f32 *) param_0->actorData)[7] +
                           func_800F10B4(param_0->unk58, 0.0f, (f32) param_0->unk74_7 / 10.0f, 0.0f,
                                         func_80103EF4(param_0));
}

s32 func_80800458_chbosskogsdoor(u8 *param_0, s32 param_1, s32 param_2)
{
    if (param_1 == 0x49) {
        if (param_2 == 0x40) {
            _capod_entrypoint_13(*(s32 *) param_0, 0, 1, 0x930);
            func_80101FDC(param_0, 2);
            func_800EFA4C(param_0 + 0x18, -7472.0f, 2405.0f, -1.24e+03f);
            *(f32 *) (param_0 + 0x2C) = 5.0f;
            return 1;
        }
        return 0;
    }
    return 0;
}

int *chbosskogsdoor_entrypoint_0()
{
    return &D_80800918_chbosskogsdoor;
}

void func_808004F4_chbosskogsdoor(BossKogsDoor *param_0)
{
    if (func_800DA298(0x1B8)) {
        func_80102424(param_0, 4);
        param_0->unk74_6 = 1;
    } else {
        func_80102424(param_0, 1);
    }
}

void func_80800544_chbosskogsdoor(Actor *param_0)
{
    f32 local_0[3];

    switch (param_0->unk70_10) {
        case 1:
            if (param_0->unk64_20) {
                func_80102424(param_0, 2);
                _subaddieaudioquick_entrypoint_2(param_0, param_0->position,
                                                 &D_80800994_chbosskogsdoor);
                *(f32 *) &param_0->actorData[4] = 0.0f;
            } else {
                func_80103110(param_0, 0);
            }
            break;
        case 2:
            if (func_80101E14(param_0, 0.35f)) {
                _subaddieaudioquick_entrypoint_2(param_0, param_0->position,
                                                 &D_80800988_chbosskogsdoor);
            } else if (func_80101E14(param_0, 0.4f)) {
                _subaddieaudioquick_entrypoint_2(param_0, param_0->position,
                                                 &D_808009A0_chbosskogsdoor);
                func_800BBCB8(param_0->position, NULL, param_0->scale, 4,
                              &D_808009B0_chbosskogsdoor);
            }
            if (func_80101F24(param_0) > 0.4f) {
                func_800EFA4C(local_0, -247.0f, *(f32 *) &param_0->actorData[4] + 150.0f, 1720.0f);
                *(f32 *) &param_0->actorData[4] += 1200.0f * func_800D8FF8();
                func_800BBCB8(local_0, local_0, 1.0f, 2, &D_808008B0_chbosskogsdoor);
            }
            if (func_80101DDC(param_0)) {
                param_0->unk58 = 2.0f;
                func_80102424(param_0, 3);
            }
        case 3:
        case 4:
            break;
    }
}

s32 func_80800714_chbosskogsdoor(Actor *param_0, s32 param_1, s32 param_2)
{
    switch (param_1) {
        case 0x91:
            if (func_800F64A4(func_800F54E4(), 0x40) != 0) {
                if ((func_800DA298(0xA06) != 0) && (param_0->unk70_10 == 1)) {
                    param_0->unk64_20 = 1;
                    func_80103110(param_0, 1);
                    _capod_entrypoint_13(param_0->unk0, 0, 0x18, 0x810);
                }
            } else if (!param_0->unk74_30) {
                _subaddiedialog_entrypoint_11(param_0->unk0, 0x1354, 6, (u8 *) param_0 + 4, 0);
                param_0->unk74_30 = 1;
            }
            return 1;
        case 0x95:
            func_80102424(param_0, param_0->unk70_10);
            func_80102204(param_0);
            return 1;
        case 0xB:
            if (param_2 == 0x18) {
                _capod_entrypoint_14();
                func_80102424(param_0, 4);
                _glcutDll_entrypoint_6(0x10F, 0x40);
                return 4;
            }
            return 3;
        default:
            return 0;
    }
}

int chbosskogsdoor_entrypoint_1()
{
    return &D_808009EC_chbosskogsdoor;
}

extern void func_80105834();
extern void func_80101870();
extern void func_80107C2C();
extern void func_80108ED0();
s32 D_808008B0_chbosskogsdoor[14] = {0x1D09CD, 0x1BFC18, -0x31FFFD3, 0x12C0190, 0x161100,
                                     0x180000, 0x41E00,  0x23000022, 0x400059,  0x190033,
                                     0x150000, 0xCC002B, 0x800080,   0x0};
u8 D_808008E8_chbosskogsdoor[16] = {0x0, 0x13, 0x5, 0x28, 0x0,  0xA,  0x0, 0xC0,
                                    0x0, 0x1,  0x0, 0xC8, 0x17, 0x70, 0x0, 0x0};
u8 D_808008F8_chbosskogsdoor[12] = {0x0, 0x13, 0x4, 0xA0, 0x0, 0xA, 0x0, 0x99, 0x0, 0x0, 0x0, 0x0};
u8 D_80800904_chbosskogsdoor[8] = {0x0, 0x13, 0x4, 0xCE, 0x0, 0x0, 0x0, 0x0};
u8 D_8080090C_chbosskogsdoor[12] = {0x0, 0x13, 0x4, 0xE2, 0x0, 0xA, 0x0, 0x66, 0x0, 0x0, 0x0, 0x0};
int D_80800918_chbosskogsdoor[18] = {0x11803FD,
                                     0x8800001,
                                     0x0,
                                     (u32) func_80800090_chbosskogsdoor,
                                     (u32) func_80105834,
                                     (u32) func_80101870,
                                     0x0,
                                     0x0,
                                     0x0,
                                     0xC00,
                                     0x0,
                                     0x0,
                                     0x0,
                                     (u32) func_80800000_chbosskogsdoor,
                                     (u32) func_80107C2C,
                                     -0x7FF7FBFE,
                                     (u32) func_80800458_chbosskogsdoor,
                                     0x0};
u32 D_80800960_chbosskogsdoor[10] = {0x0,      0x0,        0x3F000000, 0xD40044,   0x3F800000,
                                     0xD40042, 0x3F000000, 0xD40084,   0x3F000000, 0xD40084};
s32 D_80800988_chbosskogsdoor[3] = {0x130456, 0xA00CC, 0x0};
s32 D_80800994_chbosskogsdoor[3] = {0x13051B, 0xA0080, 0x0};
s32 D_808009A0_chbosskogsdoor[4] = {0x13051C, 0xA0133, 0x100C8, 0x17700000};
s32 D_808009B0_chbosskogsdoor[15] = {0x1D09C9, 0x2B0200, 0x3000022, 0x1000180,   0x3000400,
                                     0x150000, 0x33000D, 0x640019,  0x7,         0x2CFFEC,
                                     0x140014, 0x140028, 0x140020,  -0x7D919F80, 0x0};
int D_808009EC_chbosskogsdoor[21] = {0x11903FC,
                                     0x87E0001,
                                     (u32) &D_80800960_chbosskogsdoor,
                                     (u32) func_80800544_chbosskogsdoor,
                                     (u32) func_80105834,
                                     (u32) func_80101870,
                                     0x0,
                                     0x0,
                                     0x0,
                                     0xC08,
                                     0x0,
                                     (u32) func_80108ED0,
                                     0x0,
                                     (u32) func_808004F4_chbosskogsdoor,
                                     (u32) func_80107C2C,
                                     -0x7FF7DC00,
                                     (u32) func_80800714_chbosskogsdoor,
                                     0x0,
                                     0x0,
                                     0x0,
                                     0x0};
