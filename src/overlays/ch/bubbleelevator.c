#include "ch/bubbleelevator.h"

#define ELEVATOR_DATA(arg0) ((BubbleElevatorActorData *) (arg0->actorData))

extern f32 func_80013970(f32);
extern f32 func_800138D0(f32);
extern BubbleWarpData D_80800C20_chbubbleelevator[2];
extern u32 D_80800C50_chbubbleelevator[2];
extern u32 D_80800C58_chbubbleelevator[];

void func_80800000_chbubbleelevator(Actor *arg0)
{
    s32 sp24;
    Prop *temp_v0;
    s32 var_a1;
    MapId temp_v0_2;

    ELEVATOR_DATA(arg0)->unkC = arg0->position[1];
    temp_v0 = _gccubesearch_entrypoint_0(0x299, arg0);
    if (temp_v0 != 0) {
        _gspropctrl_entrypoint_11(temp_v0, ELEVATOR_DATA(arg0)->unk0);
    }
    temp_v0_2 = func_800EA05C();
    if (temp_v0_2 != MAP_136_CCL_CLOUD_CUCKOOLAND) {
        if (temp_v0_2 == MAP_15A_IOH_WASTELAND) {
            arg0->unk79_4 = 0;
        }
    } else {
        arg0->unk79_4 = 1;
    }
    if (_sujiggy_entrypoint_20(7) != 0) {
        func_800DA544(FLAG_399_PROGRESS_OPENED_WORLD_CCL);
    }
    var_a1 = func_800D3E40(0xB) != 0;
    if (var_a1 != 0) {
        var_a1 = _glcutDll_entrypoint_19(0x81) == 0;
    }
    if ((func_800DA298(FLAG_399_PROGRESS_OPENED_WORLD_CCL) == 0) && (var_a1 == 0)) {
        func_808004DC_chbubbleelevator(arg0, 8);
    } else if (func_800DA298(FLAG2_6CA_USING_BUBBLEELEVATOR) != 0) {
        func_808004DC_chbubbleelevator(arg0, 1);
    } else {
        func_808004DC_chbubbleelevator(arg0, 4);
    }
    arg0->unk50 = 0.0f;
    arg0->unk54 = 0.0f;
}

void func_80800124_chbubbleelevator(Actor *arg0)
{
    s32 sp44;
    f32 sp38[3];

    func_808008A8_chbubbleelevator(arg0);
    switch (arg0->unk70_10) {
        case 1:
            if (func_800D90A4(&arg0->unk58) != 0) {
                func_808004DC_chbubbleelevator(arg0, 2);
            }
            _subaddieaudioloop_entrypoint_4(arg0, arg0->position, 1, D_80800C50_chbubbleelevator);
            _subaddieaudioloop_entrypoint_0(
                arg0, func_800F12D4(arg0->unk58, 0.0f, 5.0f,
                                    D_80800C20_chbubbleelevator[(u32) arg0->unk79_4].unk10,
                                    D_80800C20_chbubbleelevator[(u32) arg0->unk79_4].unk14));
            func_800F8294(func_800F54E4(), arg0->position);
            return;
        case 2:
            func_800F8294(func_800F54E4(), arg0->position);
            return;
        case 3:
            if (ELEVATOR_DATA(arg0)->unk1C < 1.0f) {
                _sudeflect_entrypoint_0(arg0->position, 75.0f, 140.0f, 0x1E);
            }
            if (func_800D90A4(&ELEVATOR_DATA(arg0)->unk1C) != 0) {
                func_808004DC_chbubbleelevator(arg0, 4);
            }
            return;
        case 4:
            sp44 = 0;
            if (func_8010C500(arg0) != 0) {
                if (func_800F64A4(func_800F54E4(), ALLOW_BK) != 0) {
                    func_808004DC_chbubbleelevator(arg0, 5);
                } else {
                    if (func_800DA298(FLAG2_6EA_BUBBLE_AS_BK_WARNING) == 0) {
                        func_800DA544(FLAG2_6EA_BUBBLE_AS_BK_WARNING);
                        _subaddiedialog_entrypoint_11(arg0->unk0, 0x1229, 3, arg0->position, 0x6F);
                    }
                    sp44 = 1;
                }
            } else {
                sp44 = 1;
            }
            if (sp44 != 0) {
                _sudeflect_entrypoint_0(arg0->position, 75.0f, 140.0f, 0x1E);
            }
            break;
        case 5:
            func_800F5A00(func_800F54E4(), sp38);
            if (func_800EFFB4(arg0->position, 50.0f, sp38) != 0) {
                func_808004DC_chbubbleelevator(arg0, 6);
            }
            break;
        case 6:
            if (func_800D91EC(&arg0->unk58, 4.75f) != 0) {
                func_808004DC_chbubbleelevator(arg0, 7);
            }
            _subaddieaudioloop_entrypoint_4(arg0, arg0->position, 1, D_80800C50_chbubbleelevator);
            _subaddieaudioloop_entrypoint_0(
                arg0, func_800F12D4(arg0->unk58, 0.0f, 5.0f,
                                    D_80800C20_chbubbleelevator[(u32) arg0->unk79_4].unk10,
                                    D_80800C20_chbubbleelevator[(u32) arg0->unk79_4].unk14));
            func_800F8294(func_800F54E4(), arg0->position);
            return;
        case 7:
            func_800D91EC(&arg0->unk58, 5.0f);
            func_808004DC_chbubbleelevator(arg0, 1);
            _subaddieaudioloop_entrypoint_4(arg0, arg0->position, 1, D_80800C50_chbubbleelevator);
            _subaddieaudioloop_entrypoint_0(
                arg0, func_800F12D4(arg0->unk58, 0.0f, 5.0f,
                                    D_80800C20_chbubbleelevator[(u32) arg0->unk79_4].unk10,
                                    D_80800C20_chbubbleelevator[(u32) arg0->unk79_4].unk14));
            func_800F8294(func_800F54E4(), arg0->position);
            return;
        case 9:
            if (func_800D90A4(&ELEVATOR_DATA(arg0)->unk10) != 0) {
                func_800DA544(FLAG_399_PROGRESS_OPENED_WORLD_CCL);
                func_808004DC_chbubbleelevator(arg0, 4);
            }
            arg0->scale = func_800F12D4(ELEVATOR_DATA(arg0)->unk10, ELEVATOR_DATA(arg0)->unk14,
                                        0.0f, 0.05f, 1.0f);
    }
}

void func_808004DC_chbubbleelevator(Actor *arg0, s32 arg1)
{
    int new_var2;
    Actor *new_var;
    f32 sp2C;
    switch (arg1) {
        case 1:
            arg0->unk58 = 5.0f;
            func_808008A8_chbubbleelevator(arg0);
            func_800F7B9C(func_800F54E4(), 0x7C);
            func_800F8294(func_800F54E4(), arg0->position);
            func_800EFA4C(&sp2C, 0.0f, func_800F1DF4(arg0->position, ELEVATOR_DATA(arg0)->unk0),
                          0.0f);
            func_800F832C(func_800F54E4(), &sp2C);
            func_800F80E4(func_800F54E4(), 0);
            _capod_entrypoint_13(arg0->unk0, arg0->unk0,
                                 D_80800C20_chbubbleelevator[(u32) arg0->unk79_4].unk0, 0x2001);
            arg0->unk6C_0 = func_80015184();
            func_80015178(3);
            new_var2 = 0;
            ELEVATOR_DATA(arg0)->unk1C = new_var2;
            _subaddieDll_entrypoint_4(arg0, 1U);
            func_800FC6B0(0x4A);
            break;

        case 3:
            func_800C3F48(0x665F44B1);
            func_800DA524(FLAG2_6CA_USING_BUBBLEELEVATOR);
            arg0->unk58 = 0.0f;
            func_808008A8_chbubbleelevator(arg0);
            func_800F78EC(func_800F54E4(), ELEVATOR_DATA(arg0)->unk0, 840.0f, -1500.0f);
            ELEVATOR_DATA(arg0)->unk1C = 2.0f;
            arg0->unk50 = 3.0f;
            _subaddieaudioloop_entrypoint_2(arg0);
            func_800FC74C(0x4A);
            func_800F80E4(func_800F54E4(), 1);
            break;

        case 4:
            ELEVATOR_DATA(arg0)->unk1C = 0.0f;
            arg0->unk58 = 0.0f;
            _subaddieDll_entrypoint_4(arg0, 0U);
            if (arg0->unk6C_0 != 0) {
                func_80015178(arg0->unk6C_0);
            }
            break;

        case 5:
            func_800C3F48(0x7FF194D5);
            func_800F78EC(func_800F54E4(), arg0->position, 840.0f, -1500.0f);
            new_var = arg0;
            _subaddieDll_entrypoint_4(new_var, 1U);
            break;

        case 6:
            func_800C3F48(0x665F44B1);
            func_800FC6B0(0x4A);
            func_800DA544(FLAG2_6CA_USING_BUBBLEELEVATOR);
            arg0->unk58 = 0.0f;
            func_808008A8_chbubbleelevator(arg0);
            func_800F7B9C(func_800F54E4(), 0x7C);
            func_800F80E4(func_800F54E4(), 0);
            func_800F8294(func_800F54E4(), arg0->position);
            _capod_entrypoint_13(arg0->unk0, arg0->unk0,
                                 D_80800C20_chbubbleelevator[(u32) arg0->unk79_4].unk1, 0x4001);
            arg0->unk6C_0 = func_80015184();
            func_80015178(3);
            arg0->unk50 = 3.0f;
            break;

        case 7:
            _gcgoto_entrypoint_1(D_80800C20_chbubbleelevator[(u32) arg0->unk79_4].mapId,
                                 D_80800C20_chbubbleelevator[(u32) arg0->unk79_4].entranceId);
            _subaddieaudioloop_entrypoint_2(arg0);
            func_800FC74C(0x4A);
            break;

        case 8:
            func_80103110(arg0, 0);
            break;

        case 9:
            func_80103110(arg0, 1);
            _subaddieDll_entrypoint_4(arg0, 1U);
            arg0->scale = 0.05f;
            arg0->unk50 = 3.0f;
            ELEVATOR_DATA(arg0)->unk10 = ELEVATOR_DATA(arg0)->unk14;
            func_800C3F48(0x7FFF468B);
    }
    func_80101FDC(arg0, (u32) arg1);
}

void func_808008A8_chbubbleelevator(Actor *arg0)
{
    arg0->position[1] = func_800F12D4(arg0->unk58, 0.0f, 5.0f, 0.0f,
                                      D_80800C20_chbubbleelevator[arg0->unk79_4].unkC) +
                        ELEVATOR_DATA(arg0)->unkC;
}

s32 func_8080090C_chbubbleelevator(Actor *arg0, s32 arg1, s32 arg2)
{
    switch (arg1) {
        case 7:
            ELEVATOR_DATA(arg0)->unk14 = arg2;
            func_808004DC_chbubbleelevator(arg0, 9);
            return 1;
        case 11:
            if (arg2 == D_80800C20_chbubbleelevator[(u32) arg0->unk79_4].unk0) {
                func_808004DC_chbubbleelevator(arg0, 3);
            }
            if ((func_800EA05C() == MAP_136_CCL_CLOUD_CUCKOOLAND) &&
                (arg2 == D_80800C20_chbubbleelevator[(u32) arg0->unk79_4].unk0 &&
                 (func_800DA298(FLAG_504_PROGRESS_CANARY_MARY_IN_CCL) == 0))) {
                return func_80101180(0x383, 0xB, arg2);
            }
            return 2;
        default:
            return 0;
    }
}

void func_80800A10_chbubbleelevator(Actor *arg0, s32 arg1)
{
    f32 sp5C;
    f32 sp58;
    f32 sp4C[3];
    f32 sp40[3];
    f32 sp38[2];

    if (arg0->unk70_10 != 8) {
        func_800D90A4(&arg0->unk50);
        arg0->unk54 += (func_800D8FF8() * func_800F10B4(arg0->unk50, 0.0f, 3.0f, 1.0f, 3.0f));
        if (arg0->unk54 > 1.0f) {
            arg0->unk54 = (arg0->unk54 - 1.0f);
        }
        sp5C = arg0->unk54 * 360.0f;
        sp58 = func_800F10B4(arg0->unk50, 0.0f, 3.0f, 0.075f, 0.200000003f);
        func_800EE7F8(sp4C, arg0->position);
        sp4C[1] += 75.0f;
        func_800E3980(sp40);
        func_800F18FC(sp4C, sp40, sp38);
        func_800EEBF0(sp40, sp38, 75.0f);
        func_800EF04C(sp4C, sp40);
        sp38[0] = (func_80013970(sp5C) * sp58) + 1.0f;
        sp38[1] = (func_800138D0(sp5C) * sp58) + 1.0f;
        arg0->unk7C_12 = _chbubble_entrypoint_0(arg1, sp4C, sp38, arg0->scale, 4000.0f);
    }
}

u32 *chbubbleelevator_entrypoint_0(void)
{
    return &D_80800C58_chbubbleelevator;
}

extern void func_80105834();
extern void func_80108ED0();
extern void func_80107C2C();
BubbleWarpData D_80800C20_chbubbleelevator[2] = {0x0,    0x2,  0x0,   0x0,     0x14, 0x136,
                                                 3e+03f, 0.5f, 1.0f,  0x1F,    0x21, 0x0,
                                                 0x0,    0x5,  0x15A, -3e+03f, 1.5f, 1.0f};
u32 D_80800C50_chbubbleelevator[2] = {0x130486, 0x20000};
u32 D_80800C58_chbubbleelevator[18] = {0x3560412,
                                       0xFFFF0001,
                                       0x0,
                                       (u32) func_80800124_chbubbleelevator,
                                       (u32) func_80105834,
                                       (u32) func_80800A10_chbubbleelevator,
                                       0x3E80000,
                                       0x0,
                                       0x0,
                                       0x20001,
                                       0x0,
                                       (u32) func_80108ED0,
                                       0x0,
                                       (u32) func_80800000_chbubbleelevator,
                                       (u32) func_80107C2C,
                                       0x80000400,
                                       (u32) func_8080090C_chbubbleelevator,
                                       0x0};
