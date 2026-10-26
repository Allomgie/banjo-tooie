#include "common.h"

extern void _chwaterfallgrill_entrypoint_0(void);
extern void func_800EE7F8(f32 *, f32 *);
extern s32 _chdoormake_entrypoint_3(Actor *, f32, f32, f32, s32, s32);
extern void _chdoormake_entrypoint_5(Actor *, f32);
extern void _chdoormake_entrypoint_11(Actor *, s32, f32);
extern void func_800CE8D8(s32, f32, s32);
extern void *D_80800330_chwaterfallgrill;

int func_80800000_chwaterfallgrill(Actor *param_0)
{
  _chdoor_entrypoint_0();
 do { } while (0);
  if ((((u32) (*((u16 *)(((char *) param_0) + 0x72)))) >> 10) == 4)
  {
    if (func_8010CB0C((char *)param_0 + 0x18, 0xB4, 0xC8, -350))
    {
      func_800DA544(0x503);
      func_800CE928(0, 0, 0);
      func_800CE88C(0, 0);
      func_800FC660(0x10);
      func_80103110(param_0, 0);
    }
  }
}

void func_8080008C_chwaterfallgrill(Actor *param_0)
{
    if (func_800DA298(0x503)) func_800DA544(0x9F2);
    else if (!func_800CEAA8(0) || (void *)func_800CE95C(0) != (void *)_chwaterfallgrill_entrypoint_0) func_800DA524(0x9F2);
    func_800EE7F8((f32 *)param_0->actorData, param_0->position);
    if (_chdoormake_entrypoint_3(param_0, 0.0f, 90.0f, 440.0f, 0x408A, 0x9F2)) {
        _chdoormake_entrypoint_8(param_0, 2);
        _chdoormake_entrypoint_5(param_0, 2.5f);
        _chdoormake_entrypoint_9(param_0, 0, 0, 16);
        _chdoormake_entrypoint_10(param_0, 0, 0x501);
        _chdoormake_entrypoint_11(param_0, 0, 0.9499969482421875f);
        _chdoormake_entrypoint_9(param_0, 1, 2, 16);
        _chdoormake_entrypoint_10(param_0, 1, 0x502);
        _chdoormake_entrypoint_11(param_0, 1, 0.25f);
    }
    if (func_800DA298(0x503) || !func_800DA298(0x9F2)) func_80103110(param_0, 0);
}

s32 func_808001E0_chwaterfallgrill(Actor *param_0, s32 param_1, s32 param_2)
{
    switch (param_1) {
        case 7:
            if (func_800DA298(0x503)) {
                return 0;
            }
            if (func_800CEAA8(0)) {
                func_800CE8D8(0, 35.0f, 0x23);
                func_800CE928(0, _chwaterfallgrill_entrypoint_0, 0);
            }
            func_80103110(param_0, 1);
            break;
        case 0x9D:
            func_800CE8D8(0, 35.0f, 0x23);
            func_800CE928(0, _chwaterfallgrill_entrypoint_0, 0);
            func_800CE88C(0, 1);
            break;
        case 0x9E:
            func_80103110(param_0, 0);
            break;
    }
    return _chdoor_entrypoint_1(param_0, param_1, param_2);
}

s32 chwaterfallgrill_entrypoint_0(Actor *this, u32 param_1)
{
  if (func_800EA05C(this) == 0xC7)
  {
    func_80101180(0x11B, 8, 0);
  }
  else
  {
    func_800DA524(0x9F2);
    if (this)
    {
    }
  }
}

int chwaterfallgrill_entrypoint_1()
{
  return &D_80800330_chwaterfallgrill;
}
