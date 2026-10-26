#include "common.h"

extern f32 func_800F10B4(f32, f32, f32, f32, f32);
extern f32 func_80103EF4(Actor *);
extern s32 func_800D91EC(f32 *, f32);
extern s32 D_80800320_chfactorybtwmdoor;
extern s32 D_8080032C_chfactorybtwmdoor;
extern s32 D_80800338_chfactorybtwmdoor;
extern int D_80800344_chfactorybtwmdoor;

void func_80800000_chfactorybtwmdoor(f32 *param_0)
{
  param_0[13] = param_0[2];
  if ((func_8010C500() != 0) && (func_800F64A4(func_800F54E4(), 0x40) != 0))
  {
    if (param_0)
    {
    }
    param_0[0x16] = 3.0f;
    return;
  }
  param_0[0x16] = 0.0f;
}

void func_80800068_chfactorybtwmdoor(Actor *param_0) {
    switch (param_0->unk70_10) {                              
    case 1:
        if (func_800D90A4(&((f32 *)param_0->actorData)[3]) != 0) {
            ((f32 *)param_0->actorData)[3] = 0.5f;
            if ((func_8010C500(param_0) != 0) && (param_0->unk58 != 3.0f)) {
                if (func_800F64A4(func_800F54E4(), 0x40) != 0) {
                    if (!param_0->unk74_30) {
                        _subaddiedialog_entrypoint_11(param_0->unk0, 0x1336, 7, param_0->position, 0xA3);
                        param_0->unk74_30 = 1;
                        _chmrtannoy_entrypoint_0();
                    }
                    _subaddieaudioquick_entrypoint_2(param_0, param_0->position, &D_80800338_chfactorybtwmdoor);
                    func_80101FDC(param_0, 2);
                } else if (!param_0->unk74_29) {
                    _subaddiedialog_entrypoint_11(param_0->unk0, 0x1335, 7, param_0->position, 0xA3);
                    param_0->unk74_29 = 1;
                    _chmrtannoy_entrypoint_0();
                }
            } else if (((func_8010C500(param_0) == 0) || (func_800F64A4(func_800F54E4(), 0x40) == 0)) && (param_0->unk58 != 0.0f)) {
                _subaddieaudioquick_entrypoint_2(param_0, param_0->position, &D_80800338_chfactorybtwmdoor);
                func_80101FDC(param_0, 3);
            }
        }
        break;
    case 2:
        if (func_800D91EC(&param_0->unk58, 3.0f) != 0) {
            ((f32 *)param_0->actorData)[3] = 0.5f;
            _subaddieaudioloop_entrypoint_2(param_0);
            _subaddieaudioquick_entrypoint_2(param_0, param_0->position, &D_8080032C_chfactorybtwmdoor);
            func_80101FDC(param_0, 1);
        } else {
            _subaddieaudioloop_entrypoint_4(param_0, param_0->position, 1, &D_80800320_chfactorybtwmdoor);
        }
        break;
    case 3:
        if (func_800D90A4(&param_0->unk58) != 0) {
            ((f32 *)param_0->actorData)[3] = 0.5f;
            _subaddieaudioloop_entrypoint_2(param_0);
            _subaddieaudioquick_entrypoint_2(param_0, param_0->position, &D_8080032C_chfactorybtwmdoor);
            func_80101FDC(param_0, 1);
        } else {
            _subaddieaudioloop_entrypoint_4(param_0, param_0->position, 1, &D_80800320_chfactorybtwmdoor);
        }
        break;
    }
    (*(f32 *)((s8 *)(param_0) + (8))) = (f32) (((f32 *)param_0->actorData)[7] + func_800F10B4(param_0->unk58, 0.0f, 3.0f, 0.0f, func_80103EF4(param_0)));
}

int chfactorybtwmdoor_entrypoint_0()
{
    return (int)&D_80800344_chfactorybtwmdoor;
}
