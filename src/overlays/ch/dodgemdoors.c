#include "common.h"

extern void func_800DA544(s32);
extern int D_80800374_chdodgemdoors[];
extern void func_80103140();
extern s16 D_80800360_chdodgemdoors[];
extern f32 func_800D8FF8(void);

void func_80800000_chdodgemdoors(Actor *param_0)
{
    param_0->unk74_7 = (u16) (param_0->unk74_7 - 0x32);
    param_0->position[2] = -645.0f;
    func_80103140(param_0, (u16) (param_0->unk74_7 + 0x767), param_0->unk0->unk16);
    func_8010A63C(param_0);
    if (func_800DA298(param_0->unk74_7 + 0xAB)) {
        func_80101FDC(param_0, 3);
        param_0->position[1] = 275.0f;
    }
}

int func_808000A0_chdodgemdoors(Actor *param_0, s32 param_1, s32 param_2)
{
    switch (param_1) {
        case 0x49:
            if (func_800DA298(0xA5) && func_800DA298(param_0->unk74_7 + 0xA8) &&
                !func_800DA298(param_0->unk74_7 + 0xAB)) {
                func_80101FDC(param_0, 2);
                _capod_entrypoint_13(param_0->unk0, 0, param_0->unk74_7 * 2 + 3, 0x2010);
                func_800DA544(param_0->unk74_7 + 0xAB);
                switch (param_0->unk74_7) {
                    case 0:
                        _gcfrontend_entrypoint_9(0x64);
                        break;
                    case 1:
                        _gcfrontend_entrypoint_9(0x65);
                        break;
                    case 2:
                        _gcfrontend_entrypoint_9(0x66);
                        break;
                }
            }
            if (param_0->unk74_7 == 2 && func_800DA298(0xB0) && !func_800D0A9C(0x16, 1)) {
                func_800D10D4(0x16, 1, 0, 1, 0);
                _capod_entrypoint_13(param_0->unk0, 0, 1, 0x10);
            }
            break;
        case 0xA:
            if (param_0->unk74_7 == 0) {
                func_800DA544(param_0->unk74_7 + 0xAB);
                func_80101FDC(param_0, 2);
                _capod_entrypoint_13(param_0->unk0, 0, param_0->unk74_7 * 2 + 3, 0x2010);
                _gcfrontend_entrypoint_9(0x64);
            }
            break;
        default:
            return 0;
    }
    return 1;
}

void func_8080026C_chdodgemdoors(Actor *param_0)
{
    switch (param_0->unk70_10) {
        case 1:
            break;
        case 2:
            if (!param_0->unk74_30) {
                _subaddieaudioquick_entrypoint_2(param_0, param_0->position,
                                                 D_80800360_chdodgemdoors);
                param_0->unk74_30 = 1;
            }
            if (param_0->position[1] < 275.0f) {
                param_0->position[1] += 175.0f * func_800D8FF8();
            } else {
                func_80101FDC(param_0, 3);
                func_800DA544(param_0->unk74_7 + 0xAB);
            }
        case 3:
            break;
    }
}

int *chdodgemdoors_entrypoint_0()
{
    return &D_80800374_chdodgemdoors;
}

extern void func_80105834();
extern void func_80101870();
extern void func_80107C2C();
s16 D_80800360_chdodgemdoors[10] = {0x13, 0x51C, 0xA, 0x100, 0x16, 0x6D60, 0x1, 0x1F4, 0x1388, 0x0};
int D_80800374_chdodgemdoors[19] = {0xAC0307,
                                    0x7670001,
                                    0x0,
                                    (u32) func_8080026C_chdodgemdoors,
                                    (u32) func_80105834,
                                    (u32) func_80101870,
                                    0x0,
                                    0x0,
                                    0x0,
                                    0x81004,
                                    0x0,
                                    0x0,
                                    0x0,
                                    (u32) func_80800000_chdodgemdoors,
                                    (u32) func_80107C2C,
                                    -0x7FF7FFEE,
                                    (u32) func_808000A0_chdodgemdoors,
                                    0x0,
                                    0x0};
