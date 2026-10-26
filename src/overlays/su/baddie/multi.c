#include "common.h"

extern u8 *_gccubesearch_entrypoint_14(s32, s32);
extern f32 func_800EFC7C(f32 *, f32 *);
extern f32 func_800F1DF4(f32 *, f32 *);
extern f32 sqrtf(f32);
extern void func_800EEB9C(f32 *, f32, f32);

int subaddiemulti_entrypoint_0(s32 param_0)
{
  s32 local_0;
  for (local_0 = 0; local_0 < 8; local_0++)
  {
    if (func_800F6438(local_0))
    {
      func_800F82D4(local_0, 2);
      if (param_0)
      {
        func_800F608C(local_0, param_0);
      }
    }
  }

}

int subaddiemulti_entrypoint_1(s32 param_0, s32 param_1)
{
  s32 local_0;
  for (local_0 = 0; local_0 < 8; local_0++)
  {
    if (func_800F6438(local_0))
    {
      func_800F8300(local_0, 2, param_1);
      if (param_0 != 0)
      {
        func_800F608C(local_0, param_0);
      }
    }
  }

}

s32 subaddiemulti_entrypoint_2(void){
    s32 i;
    for(i = 0; i < 8; i++){
        if(func_800F6438(i)){
            func_800F82D4(i, 0);
        }
    }
}

void subaddiemulti_entrypoint_3(s32 param_0)
{
    s32 local_2;
    u8 *local_3;
    f32 local_0[3];
    f32 local_1[3];

    func_800EFD24(local_1);
    for (local_2 = 0; local_2 < 8; local_2++) {
        if (func_800F6438(local_2)) {
            local_3 = _gccubesearch_entrypoint_14(param_0, 0);
            func_800EE88C(local_0, local_3);
            local_1[1] = (f32)(*(u32 *)(local_3 + 12) >> 23);
            func_800F8294(local_2, local_0);
            func_800F832C(local_2, local_1);
            _plcamera_entrypoint_8(local_2);
        }
        param_0++;
    }
}

int subaddiemulti_entrypoint_4(s32 param_0)
{
  s32 local_0;
  for (local_0 = 0; local_0 < 8; local_0++)
  {
    if (func_800F6438(local_0))
    {
      _ncfixposrot_entrypoint_8(func_800F5EF8(local_0), param_0);
    }
  }

}

u32 subaddiemulti_entrypoint_5(u8 *param_0)
{
  if (_sueggmisc_entrypoint_0() != 0)
  {
    return _suegg_entrypoint_7(param_0);
  }
  if ((((u32) (*((u32 *) (((char *) param_0) + 0x24)))) >> 0x16) == 0)
  {
    return ((((((((((((u16) (*((u16 *) (((char *) param_0) + 0x1A)))) & 0xFFFFFFFFu) & 0xFFFFFFFFu) & 0xFFFFFFFFu) & 0xFFFFFFFFu) & 0xFFFFFFFFu) & 0xFFFFFFFFu) & 0xFFFFFFFFu) & 0xFFFFFFFFu) & 0xFFFFFFFFu) & 0xFFFFFFFFu) >> 5;
  }
  return func_800F54E4(param_0);
}

void subaddiemulti_entrypoint_6(f32 *param_0, f32 param_1)
{
    s32 local_3;
    f32 local_0[3];
    f32 local_1;
    f32 local_2;

    for (local_3 = 0; local_3 < 8; local_3++) {
        if (func_800F6438(local_3)) {
            func_800F5A00(local_3, local_0);
            if (param_1 < func_800EFC7C(param_0, local_0)) {
                local_1 = local_0[1];
                local_2 = func_800F1DF4(param_0, local_0);
                func_800EEB9C(local_0, local_2, sqrtf(param_1));
                func_800EF04C(local_0, param_0);
                local_0[1] = local_1;
                func_800F8418(local_3, local_0);
            }
        }
    }
}
