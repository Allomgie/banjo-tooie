#include "common.h"

extern f32 func_800F10B4(f32, f32, f32, f32, f32);
extern f32 func_80103EF4(Actor *);
extern s32 func_800D91EC(f32 *, f32);
extern s32 D_80800320_chfactorybtwmdoor[];
extern s32 D_8080032C_chfactorybtwmdoor[];
extern s32 D_80800338_chfactorybtwmdoor[];
extern int D_80800344_chfactorybtwmdoor[];

void func_80800000_chfactorybtwmdoor(f32 *data)
{
    data[13] = data[2];
    if ((func_8010C500() != 0) && (func_800F64A4(func_800F54E4(), 0x40) != 0)) {
        // Matching: empty block needed for the match.
        if (data) {
        }
        data[0x16] = 3.0f;
        return;
    }
    data[0x16] = 0.0f;
}

// Washing Machine door: opens (with sound) when the player has flag 0x40 and is close; first approach triggers a Mr Tannoy line.
void func_80800068_chfactorybtwmdoor(Actor *door)
{
    switch (door->unk70_10) {
        case 1:
            if (func_800D90A4(&((f32 *) door->actorData)[3]) != 0) {
                ((f32 *) door->actorData)[3] = 0.5f;
                if ((func_8010C500(door) != 0) && (door->unk58 != 3.0f)) {
                    if (func_800F64A4(func_800F54E4(), 0x40) != 0) {
                        if (!door->unk74_30) {
                            _subaddiedialog_entrypoint_11(door->unk0, 0x1336, 7,
                                                          door->position, 0xA3);
                            door->unk74_30 = 1;
                            _chmrtannoy_entrypoint_0();
                        }
                        _subaddieaudioquick_entrypoint_2(door, door->position,
                                                         &D_80800338_chfactorybtwmdoor);
                        func_80101FDC(door, 2);
                    } else if (!door->unk74_29) {
                        _subaddiedialog_entrypoint_11(door->unk0, 0x1335, 7, door->position,
                                                      0xA3);
                        door->unk74_29 = 1;
                        _chmrtannoy_entrypoint_0();
                    }
                } else if (((func_8010C500(door) == 0) ||
                            (func_800F64A4(func_800F54E4(), 0x40) == 0)) &&
                           (door->unk58 != 0.0f)) {
                    _subaddieaudioquick_entrypoint_2(door, door->position,
                                                     &D_80800338_chfactorybtwmdoor);
                    func_80101FDC(door, 3);
                }
            }
            break;
        case 2:
            if (func_800D91EC(&door->unk58, 3.0f) != 0) {
                ((f32 *) door->actorData)[3] = 0.5f;
                _subaddieaudioloop_entrypoint_2(door);
                _subaddieaudioquick_entrypoint_2(door, door->position,
                                                 &D_8080032C_chfactorybtwmdoor);
                func_80101FDC(door, 1);
            } else {
                _subaddieaudioloop_entrypoint_4(door, door->position, 1,
                                                &D_80800320_chfactorybtwmdoor);
            }
            break;
        case 3:
            if (func_800D90A4(&door->unk58) != 0) {
                ((f32 *) door->actorData)[3] = 0.5f;
                _subaddieaudioloop_entrypoint_2(door);
                _subaddieaudioquick_entrypoint_2(door, door->position,
                                                 &D_8080032C_chfactorybtwmdoor);
                func_80101FDC(door, 1);
            } else {
                _subaddieaudioloop_entrypoint_4(door, door->position, 1,
                                                &D_80800320_chfactorybtwmdoor);
            }
    }
    *(f32 *) ((s8 *) door + 8) =
        (f32) (((f32 *) door->actorData)[7] +
               func_800F10B4(door->unk58, 0.0f, 3.0f, 0.0f, func_80103EF4(door)));
}

int chfactorybtwmdoor_entrypoint_0()
{
    return (int) &D_80800344_chfactorybtwmdoor;
}

// TU-NOTE: the .data tables below are defined in C so IDO schedules the functions as in the original.
extern void func_80105834();
extern void func_80101870();
extern void func_80107C2C();
s32 D_80800320_chfactorybtwmdoor[3] = {0x130528, 0xA00C0, 0x0};
s32 D_8080032C_chfactorybtwmdoor[3] = {0x1304A0, 0xA0099, 0x0};
s32 D_80800338_chfactorybtwmdoor[3] = {0x1304CE, 0x167D00, 0x0};
int D_80800344_chfactorybtwmdoor[19] = {0x11E03F7,
                                        0x70C0001,
                                        0x0,
                                        (u32) func_80800068_chfactorybtwmdoor,
                                        (u32) func_80105834,
                                        (u32) func_80101870,
                                        0x0,
                                        0x0,
                                        0x0,
                                        0x40000C01,
                                        0x0,
                                        0x0,
                                        0x0,
                                        (u32) func_80800000_chfactorybtwmdoor,
                                        (u32) func_80107C2C,
                                        -0x7FF7FBEE,
                                        0x0,
                                        0x0,
                                        0x0};
