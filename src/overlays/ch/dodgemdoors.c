// The three doors of the Witchyworld Dodgem lobby leading to the 1v1, 1v2 and 1v3 domes; each
// rises after the previous win. After the 1v3 win the third door also spawns the Dodgems jiggy.
#include "common.h"

extern void func_800DA544(s32);
extern int D_80800374_chdodgemdoors[];
extern void func_80103140();
extern s16 D_80800360_chdodgemdoors[];
extern f32 func_800D8FF8(void);

// Init: sets door model and position; starts open if its flag is set.
void func_80800000_chdodgemdoors(Actor *actor)
{
    actor->unk74_7 = (u16) (actor->unk74_7 - 0x32);
    actor->position[2] = -645.0f;
    func_80103140(actor, (u16) (actor->unk74_7 + 0x767), actor->unk0->unk16);
    func_8010A63C(actor);
    if (func_800DA298(actor->unk74_7 + 0xAB)) {
        func_80101FDC(actor, 3);
        actor->position[1] = 275.0f;
    }
}

// Message handler: opens the door when the previous dome was won.
int func_808000A0_chdodgemdoors(Actor *actor, s32 event, s32 unk_0)
{
    switch (event) {
        case 0x49:
            if (func_800DA298(0xA5) && func_800DA298(actor->unk74_7 + 0xA8) &&
                !func_800DA298(actor->unk74_7 + 0xAB)) {
                func_80101FDC(actor, 2);
                _capod_entrypoint_13(actor->unk0, 0, actor->unk74_7 * 2 + 3, 0x2010);
                func_800DA544(actor->unk74_7 + 0xAB);
                switch (actor->unk74_7) {
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
            if (actor->unk74_7 == 2 && func_800DA298(0xB0) && !func_800D0A9C(0x16, 1)) {
                func_800D10D4(0x16, 1, 0, 1, 0);
                _capod_entrypoint_13(actor->unk0, 0, 1, 0x10);
            }
            break;
        case 0xA:
            if (actor->unk74_7 == 0) {
                func_800DA544(actor->unk74_7 + 0xAB);
                func_80101FDC(actor, 2);
                _capod_entrypoint_13(actor->unk0, 0, actor->unk74_7 * 2 + 3, 0x2010);
                _gcfrontend_entrypoint_9(0x64);
            }
            break;
        default:
            return 0;
    }
    return 1;
}

// Per-frame: raises the door to y=275 at 175 units/s.
void func_8080026C_chdodgemdoors(Actor *actor)
{
    switch (actor->unk70_10) {
        case 1:
            break;
        case 2:
            if (!actor->unk74_30) {
                _subaddieaudioquick_entrypoint_2(actor, actor->position,
                                                 D_80800360_chdodgemdoors);
                actor->unk74_30 = 1;
            }
            if (actor->position[1] < 275.0f) {
                actor->position[1] += 175.0f * func_800D8FF8();
            } else {
                func_80101FDC(actor, 3);
                func_800DA544(actor->unk74_7 + 0xAB);
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
