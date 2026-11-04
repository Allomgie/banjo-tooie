#include "ch/factory/maindoor.h"

extern int D_808004D4_chfactorymaindoor[];
typedef union {
    s32 word;
    void *pointer;
} FactoryMainDoorEvent;
extern int D_8080051C_chfactorymaindoor[];
extern int D_80800564_chfactorymaindoor[];
extern f32 func_80103EF4(Actor *);
extern u8 D_808004CC_chfactorymaindoor[];
extern u8 D_808004C0_chfactorymaindoor[];
extern f32 func_800F10B4(f32, f32, f32, f32, f32);

// Main door init: starts raised if flag 0x1AB (entrance open) is set.
void func_80800000_chfactorymaindoor(Actor *actor)
{
    if (func_800DA298(0x1AB)) {
        func_80101FDC(actor, 3);
        actor->position[1] += func_80103EF4(actor) * 0.8f;
    } else {
        actor->unk58 = 8.0f;
    }
    *(f32 *) &actor->actorData[7] = actor->position[1];
}

// Main door: rises once both entrance switches (0xA00, 0xA01) are pressed.
void func_80800078_chfactorymaindoor(Actor *actor)
{
    f32 unk_0;
    f32 height_scale;
    switch (actor->unk70_10) {
        case 1:
            if (func_800DA298(0xA00) && func_800DA298(0xA01)) {
                func_8009EC88(0x102, 2, 0x100, 9);
                func_80101FDC(actor, 2);
                _capod_entrypoint_13(actor->unk0, actor->unk0, 4, 0x830);
            }
            return;
        case 2:
            if (func_800D90A4((u8 *) actor + 0x58)) {
                func_80101FDC(actor, 3);
                _subaddieaudioquick_entrypoint_2(actor, actor->position,
                                                 &D_808004CC_chfactorymaindoor);
                _subaddieaudioloop_entrypoint_2(actor);
                actor->position[1] =
                    *(f32 *) ((u8 *) actor + 0x34) + func_80103EF4(actor) * 0.8f;
            } else {
                _subaddieaudioloop_entrypoint_4(actor, actor->position, 1,
                                                &D_808004C0_chfactorymaindoor);
                height_scale = func_80103EF4(actor);
                actor->position[1] =
                    *(f32 *) ((u8 *) actor + 0x34) +
                    func_800F10B4(*(f32 *) ((u8 *) actor + 0x58), 8.0f, 0.0f, 0.0f, 0.8f) *
                        height_scale;
            }
            return;
        case 3:
            func_800DA544(0x1AB);
            func_80103110(actor, 0);
    }
}

// Cutscene camera and door-lift triggers.
s32 func_808001F0_chfactorymaindoor(Actor *actor, s32 msg, s32 arg)
{
    switch (msg) {
        case 0x49:
            if (arg == 0x43) {
                func_80101FDC(actor, 2);
                actor->unk58 = func_800F10B4(0.4f, 0.0f, 1.0f, 8.0f, 0.0f);
                _capod_entrypoint_13(actor->unk0, actor->unk0, 3, 0x2910);
                return 1;
            }
            return 0;
        case 0x95:
            if (func_800EA05C() == 0x101 && actor->unk70_10 == 2) {
                func_80101FDC(actor, 2);
                actor->unk58 = func_800F10B4(0.66f, 0.0f, 1.0f, 8.0f, 0.0f);
                _capod_entrypoint_13(actor->unk0, actor->unk0, 29, 0x2810);
            }
            return 1;
        case 11:
            if (arg == 4 && func_800EA05C() == 0x101) {
                _glcutDll_entrypoint_6(0x100, 0x43);
                return 3;
            }
            return 3;
        default:
            return 0;
    }
}

int chfactorymaindoor_entrypoint_0()
{
    return (int) &D_808004D4_chfactorymaindoor;
}

// Entrance switches (variant 0x32 uses flag 0xA01, the other 0xA00).
void func_80800344_chfactorymaindoor(Actor *actor)
{
    if (actor->unk74_7 == 0x32) {
        _chswitch_entrypoint_7(actor, 0xA01);
        _chswitch_entrypoint_8(actor, 0x200);
    } else {
        _chswitch_entrypoint_7(actor, 0xA00);
        _chswitch_entrypoint_8(actor, 0x400);
    }
}

s32 func_808003A8_chfactorymaindoor(Actor *actor, s32 msg, FactoryMainDoorEvent arg)
{
    if (msg == 0x95 && actor->unk74_7 == 0x32) {
        func_80103140(actor, 0x7B8, actor->unk0->unk16);
    }
    return _chswitch_entrypoint_10(actor, msg, arg.word);
}

int chfactorymaindoor_entrypoint_1()
{
    return (int) &D_8080051C_chfactorymaindoor;
}

// Third switch (flag 0x188).
void func_8080041C_chfactorymaindoor(s32 actor)
{
    _chswitch_entrypoint_3(actor, FLAG_188_UNK);
}

// Message 7 starts cutscene 0x86.
int func_8080043C_chfactorymaindoor(s32 actor, s32 msg, s32 arg)
{
    if (msg == 7) {
        _glcutDll_entrypoint_6(0x100, 0x86);
    }
    _chswitch_entrypoint_5(actor, msg | msg, arg);
}

int *chfactorymaindoor_entrypoint_2()
{
    return &D_80800564_chfactorymaindoor;
}

extern void func_80105834();
extern void func_80101870();
extern void func_80107C2C();
extern void _chswitch_entrypoint_6();
extern void _chswitch_entrypoint_4();
u8 D_808004C0_chfactorymaindoor[12] = {0x0, 0x13, 0x5, 0xB0, 0x0, 0x18,
                                       0x0, 0xA,  0x1, 0x33, 0x0, 0x0};
u8 D_808004CC_chfactorymaindoor[8] = {0x0, 0x13, 0x4, 0xC7, 0x0, 0x18, 0x0, 0x0};
int D_808004D4_chfactorymaindoor[18] = {0x11D03F8,
                                        0x87C0001,
                                        0x0,
                                        (u32) func_80800078_chfactorymaindoor,
                                        (u32) func_80105834,
                                        (u32) func_80101870,
                                        0x13880000,
                                        0x0,
                                        0x0,
                                        0xC00,
                                        0x0,
                                        0x0,
                                        0x0,
                                        (u32) func_80800000_chfactorymaindoor,
                                        (u32) func_80107C2C,
                                        -0x7FF7DBFE,
                                        (u32) func_808001F0_chfactorymaindoor,
                                        0x0};
int D_8080051C_chfactorymaindoor[18] = {0x11B03F9,
                                        0x7B90001,
                                        -0x7FEE5DE0,
                                        (u32) _chswitch_entrypoint_6,
                                        (u32) func_80105834,
                                        (u32) func_80101870,
                                        0x0,
                                        0x0,
                                        0x0,
                                        0x40000808,
                                        0x0,
                                        0x0,
                                        0x0,
                                        (u32) func_80800344_chfactorymaindoor,
                                        (u32) func_80107C2C,
                                        -0x7FF7D3EE,
                                        (u32) func_808003A8_chfactorymaindoor,
                                        0x0};
int D_80800564_chfactorymaindoor[19] = {0x34304DA,
                                        0x8890001,
                                        -0x7FEE5DE0,
                                        (u32) _chswitch_entrypoint_4,
                                        (u32) func_80105834,
                                        (u32) func_80101870,
                                        0x0,
                                        0x0,
                                        0x0,
                                        0x40000808,
                                        0x0,
                                        0x0,
                                        0x0,
                                        (u32) func_8080041C_chfactorymaindoor,
                                        (u32) func_80107C2C,
                                        -0x7FF7D3EE,
                                        (u32) func_8080043C_chfactorymaindoor,
                                        0x0,
                                        0x0};
