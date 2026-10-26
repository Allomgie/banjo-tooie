#include "ch/factory/maindoor.h"

extern int D_808004D4_chfactorymaindoor;
typedef union { s32 word; void *pointer; } FactoryMainDoorEvent;
extern int D_8080051C_chfactorymaindoor;
extern int D_80800564_chfactorymaindoor;
extern f32 func_80103EF4(Actor *);
extern u8 D_808004CC_chfactorymaindoor[];
extern u8 D_808004C0_chfactorymaindoor[];
extern f32 func_800F10B4(f32, f32, f32, f32, f32);

void func_80800000_chfactorymaindoor(Actor *param_0)
{
    if (func_800DA298(0x1AB)) {
        func_80101FDC(param_0, 3);
        param_0->position[1] += func_80103EF4(param_0) * 0.8f;
    } else {
        param_0->unk58 = 8.0f;
    }
    *(f32 *)&param_0->actorData[7] = param_0->position[1];
}

void func_80800078_chfactorymaindoor(Actor *param_0)
{
    f32 local_1;
    f32 local_0;
    switch (param_0->unk70_10) {
    case 1:
        if (func_800DA298(0xA00) && func_800DA298(0xA01)) {
            func_8009EC88(0x102, 2, 0x100, 9);
            func_80101FDC(param_0, 2);
            _capod_entrypoint_13(param_0->unk0, param_0->unk0, 4, 0x830);
        }
        return;
    case 2:
        if (func_800D90A4((u8 *)param_0 + 0x58)) {
            func_80101FDC(param_0, 3);
            _subaddieaudioquick_entrypoint_2(param_0, param_0->position, &D_808004CC_chfactorymaindoor);
            _subaddieaudioloop_entrypoint_2(param_0);
            param_0->position[1] = *(f32 *)((u8 *)param_0 + 0x34) + func_80103EF4(param_0) * 0.8f;
        } else {
            _subaddieaudioloop_entrypoint_4(param_0, param_0->position, 1, &D_808004C0_chfactorymaindoor);
            local_0 = func_80103EF4(param_0);
            param_0->position[1] = *(f32 *)((u8 *)param_0 + 0x34) + func_800F10B4(*(f32 *)((u8 *)param_0 + 0x58), 8.0f, 0.0f, 0.0f, 0.8f) * local_0;
        }
        return;
    case 3:
        func_800DA544(0x1AB);
        func_80103110(param_0, 0);
        break;
    }
}

s32 func_808001F0_chfactorymaindoor(Actor *param_0, s32 param_1, s32 param_2)
{
    switch (param_1) {
        case 0x49:
            if (param_2 == 0x43) {
                func_80101FDC(param_0, 2);
                param_0->unk58 = func_800F10B4(0.4f, 0.0f, 1.0f, 8.0f, 0.0f);
                _capod_entrypoint_13(param_0->unk0, param_0->unk0, 3, 0x2910);
                return 1;
            }
            return 0;
        case 0x95:
            if (func_800EA05C() == 0x101 && param_0->unk70_10 == 2) {
                func_80101FDC(param_0, 2);
                param_0->unk58 = func_800F10B4(0.66f, 0.0f, 1.0f, 8.0f, 0.0f);
                _capod_entrypoint_13(param_0->unk0, param_0->unk0, 29, 0x2810);
            }
            return 1;
        case 11:
            if (param_2 == 4 && func_800EA05C() == 0x101) {
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
    return (int)&D_808004D4_chfactorymaindoor;
}

void func_80800344_chfactorymaindoor(Actor *param_0)
{
    if (param_0->unk74_7 == 0x32) {
        _chswitch_entrypoint_7(param_0, 0xA01);
        _chswitch_entrypoint_8(param_0, 0x200);
    } else {
        _chswitch_entrypoint_7(param_0, 0xA00);
        _chswitch_entrypoint_8(param_0, 0x400);
    }
}

s32 func_808003A8_chfactorymaindoor(Actor *param_0, s32 param_1, FactoryMainDoorEvent param_2)
{
    if (param_1 == 0x95 && param_0->unk74_7 == 0x32) {
        func_80103140(param_0, 0x7B8, param_0->unk0->unk16);
    }
    return _chswitch_entrypoint_10(param_0, param_1, param_2.word);
}

int chfactorymaindoor_entrypoint_1()
{
    return (int)&D_8080051C_chfactorymaindoor;
}

void func_8080041C_chfactorymaindoor(s32 arg0)
{
    _chswitch_entrypoint_3(arg0,FLAG_188_UNK);
}

int func_8080043C_chfactorymaindoor(s32 param_0, s32 param_1, s32 param_2)
{
  if (param_1 == 7)
  {
    _glcutDll_entrypoint_6(0x100, 0x86);
  }
  _chswitch_entrypoint_5(param_0, param_1 | param_1, param_2);
}

int *chfactorymaindoor_entrypoint_2()
{
    return &D_80800564_chfactorymaindoor;
}
