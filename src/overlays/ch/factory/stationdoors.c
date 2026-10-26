#include "common.h"

extern int D_80800268_chfactorystationdoors;
extern u8 D_80800250_chfactorystationdoors[];
extern u8 D_8080025C_chfactorystationdoors[];
extern f32 func_80103EF4(Actor *);
extern f32 func_800F10B4(f32, f32, f32, f32, f32);
extern void func_800DF500(f32, f32, f32);
extern void func_80101870(s32, s32);

int func_80800000_chfactorystationdoors(s32 param_0)
{
  if (_glcutDll_entrypoint_19(0x44) == 0)
  {
    if (func_800DA298(0x163))
    {
      func_800FFAB0(param_0);
    }
    else
    {
      func_80101FDC(param_0, 1);
    }
  }
}

void func_80800054_chfactorystationdoors(Actor *param_0)
{
    switch (param_0->unk70_10) {
        case 1:
            func_80103110(param_0, 0);
            break;
        case 2:
            if (func_800D90A4(&param_0->unk58)) {
                _subaddieaudioloop_entrypoint_2(param_0);
                _subaddieaudioquick_entrypoint_2(param_0, param_0->position, D_8080025C_chfactorystationdoors);
                func_80101FDC(param_0, 3);
            } else {
                _subaddieaudioloop_entrypoint_4(param_0, param_0->position, 1, D_80800250_chfactorystationdoors);
            }
            param_0->position[1] = *(f32 *)&param_0->actorData[7] + func_800F10B4(param_0->unk58, 9.0f, 0.0f, 0.0f, func_80103EF4(param_0) * 1.65f);
            break;
        case 3:
            func_80103110(param_0, 0);
            break;
    }
}

void func_80800158_chfactorystationdoors(s32 param_0, s32 param_1) {
    func_800DF500(1.07f, 1.65f, 1.0f);
    func_80101870(param_0, param_1);
}

int func_8080019C_chfactorystationdoors(s32 param_0, s32 param_1, s32 param_2)
{
  float new_var;
  if ((param_1 == 0x49) && _glcutDll_entrypoint_19(0x44))
  {
    s32 local_0 = param_0;
    f32 local_1;
    *((f32 *) (((char *) local_0) + 0x34)) = *((f32 *) (((char *) local_0) + 8));
    func_80101FDC(local_0, 2);
    *((f32 *) (((char *) local_0) + 0x58)) = 9.0f;
    new_var = 90.0f;
    if ((*((f32 *) (((char *) local_0) + 0x48))) == new_var)
    {
      _capod_entrypoint_13(*((s32 *) local_0), 0, 5, 0x900);
    }
    return 1;
  }
  return 0;
}

int chfactorystationdoors_entrypoint_0()
{
    return (int)&D_80800268_chfactorystationdoors;
}
