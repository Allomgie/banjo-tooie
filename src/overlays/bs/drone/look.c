#include "common.h"
#include "overlays/ba/playerstate.h"

extern f32 func_800F0E00(f32, f32);
extern f32 func_800F13F0(f32, f32);
extern void baanim_playForDuration_loopSmooth(PlayerState *, s32, f32);
extern void baphysics_set_target_horizontal_velocity(PlayerState *, f32);

int bsdronelook_entrypoint_0(int param_0)
{
  s32 local_0;
  ;
  if (_bafpctrl_entrypoint_4() == 2)
  {
    _bafpctrl_entrypoint_13(param_0 | 0, 1);
  }
  if (_bafpctrl_entrypoint_6(param_0 | 0))
  {
    func_800A4EC8(param_0 | 0);
    _bafpctrl_entrypoint_17(param_0 | 0);
  }
  if (param_0)
  {
  }
}

void bsdronelook_entrypoint_1(PlayerState *param_0)
{
    f32 local_1;
    s32 local_0;

    _badata_entrypoint_3(param_0, &local_0, &local_1);
    baanim_playForDuration_loopSmooth(param_0, local_0, local_1);
    func_8009FFD8(param_0, 1, 1, 3, 2);
    baphysics_set_target_horizontal_velocity(param_0, 0.0f);
    func_8009BA9C(param_0, 0);
    if (_bafpctrl_entrypoint_4(param_0) != 3) {
        func_800A4E94(param_0);
        switch (func_800A3274(param_0)) {
            case 2: case 8: case 10:
            case 13: case 14: case 15: case 16: case 17: case 18: case 19:
                _bafpctrl_entrypoint_11(param_0, 4, 1);
                break;
        }
        _bafpctrl_entrypoint_16(param_0, 3);
    }
}

f32 bsdronelook_entrypoint_2(f32 param_0)
{
    if (param_0 > 180.0f) {
        return func_800F0E00(292.0f, param_0);
    }
    if (param_0 < -65.0f) {
        return func_800F0E00(-65.0f, param_0);
    }
    return func_800F13F0(70.0f, param_0);
}

int bsdronelook_entrypoint_3(Actor *param_0)
{
  s32 local_0;
  local_0 = 0;
  if (_bafpctrl_entrypoint_4() != 3 && !func_800A3404(param_0))
  {
    local_0 = _badata_entrypoint_34(param_0);
  }
  bs_setState(param_0, local_0);
}

int bsdronelook_entrypoint_4()
{
  func_80099B94();
}
