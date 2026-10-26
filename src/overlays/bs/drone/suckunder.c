#include "common.h"
#include "overlays/ba/playerstate.h"
void func_80800000_bsdronesuckunder();

extern void func_800EFA4C(f32 *, f32, f32, f32);
extern void func_8009BA9C(s32, f32 *);
extern f32 _batimer_get(PlayerState *, s32);

void func_80800000_bsdronesuckunder(s32 param_0) {
    f32 local_0[3];

    func_800EFA4C(local_0, 0.0f, -333.3333f, 0.0f);
    func_8009BA9C(param_0, local_0);
}

extern void func_800961A0(Actor *a0, s32 a1);

void bsdronesuckunder_entrypoint_0(s32 arg0)
{
    func_800961A0(arg0,0);
}

int bsdronesuckunder_entrypoint_1(Actor *param_0)
{
  extern void _badata_entrypoint_4(Actor *a0, s32 *a1, f32 *a2);
  extern void _batimer_set(Actor *a0, s32 a1, f32 a2);
  extern void baanim_playForDuration_loopSmooth(Actor *a0, s32 a1, f32 a2);
  extern void func_800961A0(Actor *a0, s32 a1);
  extern void func_8009FFD8(Actor *a0, s32 a1, s32 a2, s32 a3, s32 a4);

  f32 local_1;
  s32 local_0;
  _badata_entrypoint_4(param_0, &local_0, &local_1);
  baanim_playForDuration_loopSmooth(param_0, local_0, local_1);
  func_8009FFD8(param_0, 1, 1, 3, 8);
  _batimer_set(param_0, 0xa, 0.3f);
  func_800961A0(param_0, 1);
  func_80800000_bsdronesuckunder(param_0);
}

int bsdronesuckunder_entrypoint_2(Actor *param_0)
{
  switch (func_8009E6EC(param_0))
  {
    case 0x26:

    case 0x51:

    case 0x52:

    if (param_0)
    {
    }
    case 0x6A:
      func_80099B94(param_0);
      break;

    default:
      func_80099AA8();

  }

}

void bsdronesuckunder_entrypoint_3(PlayerState *param_0)
{
    _batimer_decrement(param_0, 0xA);
    if (_batimer_get(param_0, 0xA) != 0.0f) {
        func_80800000_bsdronesuckunder(param_0);
    } else {
        func_8009BA9C(param_0, 0);
    }
}
