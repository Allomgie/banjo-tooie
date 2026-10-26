#include "common.h"
#include "playerstate.h"

extern f32 func_8009C150(PlayerState *);
extern f32 func_800964DC(PlayerState *);
extern void bastick_setZoneMax(s32, s32, f32);
extern void func_8009BB24(s32, f32 *);
extern f32 func_800EEF94(f32 *);
extern f32 func_800F10B4(f32, f32, f32, f32, f32);
extern f32 func_8009BFCC(PlayerState *);
extern f32 yaw_get(PlayerState *);
extern f32 func_800D8FF8(void);
extern f32 func_800F0E00(f32, f32);
extern void func_800EF4E4(f32 *, f32, f32, f32, f32, f32);
extern f32 bastick_getX(PlayerState *);
extern void yaw_setVelocityBounded(PlayerState *, f32, f32);
extern void baroll_setIdeal(PlayerState *, f32);
extern f32 yaw_getIdeal(PlayerState *);
extern void yaw_setIdeal(PlayerState *, f32);
extern f32 _bafpctrl_entrypoint_3(PlayerState *);
extern f32 bastick_getY(PlayerState *);
extern f32 func_800F1214(f32, f32, f32);
extern void func_8009BFE4(PlayerState *, f32, f32);
extern void func_8009BF5C(PlayerState *, f32);
void baswim_entrypoint_7();
int baswim_entrypoint_8(s32 param_0, f32 param_1);
int baswim_entrypoint_9(s32 param_0, f32 param_1);

s32 baswim_entrypoint_0() 
{
    return 0x8;
}

s32 baswim_entrypoint_1(s32 param_0) {
    f32 local_0 = func_800964DC(param_0);
    return local_0 - func_8009C150(param_0) < 100.0f;
}

int baswim_entrypoint_2(PlayerState *param_0)
{
    f32 local_1;

    return func_80096544(param_0) != 0 && (local_1 = func_8009C150(param_0)) > func_800964DC(param_0) - 130.0f;
}

int baswim_entrypoint_3(s32 param_0)
{
    s32 local_0;
    s32 local_1;
    local_0 = bakey_held(param_0, 8);
    local_1 = bakey_held(param_0, 9);
    if (func_800C6E38(0x30) && local_0 && local_1)
    {
        return 3;
    }
    if (local_1)
    {
        return 2;
    }
    if (local_0)
    {
        return 1;
    }
    return 0;
}

void baswim_entrypoint_4()
{
    bastick_resetZones();
}

void baswim_entrypoint_5(s32 param_0) {
    bastick_setZoneMax(param_0, 0, 0.03f);
    bastick_setZoneMax(param_0, 1, 1.0f);
    baswim_entrypoint_9(param_0, 0.0f);
    baswim_entrypoint_8(param_0, 0.0f);
}

void baswim_entrypoint_6(s32 param_0, s32 param_1){
    baswim_entrypoint_7(param_0, param_1, 0);
}

void baswim_entrypoint_7(param_0, param_1, param_2) s32 param_0; s32 param_1; s32 param_2;
{
  s32 local_0;
  if (param_1 != 0)
  {
    local_0 = 0;
    _bafpctrl_entrypoint_9(param_0, 1);
    if (_bafpctrl_entrypoint_4(param_0) == 3)
    {
      return;
    }
    _bafpctrl_entrypoint_16(param_0, 2);
    if (!func_800C6E38(0x1F))
    {
      local_0 = 1;
    }
    if ((param_2 == 0) && (func_800A3274(param_0) == 0xA))
    {
      local_0++;
    }
    if (local_0 != 0)
    {
      _bafpctrl_entrypoint_11(param_0, 4, 1);
    }
  }
  else
  {
    _bafpctrl_entrypoint_17(param_0);
    _bafpctrl_entrypoint_9(param_0, 0);
  }
}

int baswim_entrypoint_8(s32 param_0, f32 param_1)
{
  *((f32 *) (0x4 + (*((s32 *) (param_0 + 0x134))))) = param_1;
}

baswim_entrypoint_9(s32 param_0, f32 param_1) {
    *(f32*)(*(s32*)(param_0 + 308) + 0) = param_1;
}

void baswim_entrypoint_10(u8 *param_0, f32 param_1) {
    f32 *local_0;

    local_0 = (*(f32 **)((s8 *)(param_0) + (0x134)));
    if (*local_0 < param_1) {
        *local_0 = param_1;
    }
}

void baswim_entrypoint_11(PlayerState *param_0)
{
    f32 local_3;
    f32 local_1;
    f32 local_2;
    f32 local_0;
    local_0 = bastick_getX(param_0);
    local_1 = 4.3f;
    local_2 = 45.0f;
    yaw_setVelocityBounded(param_0, 250.0f, 20.0f);
    baroll_setIdeal(param_0, func_800F10B4(local_0, -1.0f, 1.0f, -local_2, local_2));
    local_3 = func_800F10B4(local_0, -1.0f, 1.0f, local_1, -local_1);
    local_3 *= _bafpctrl_entrypoint_3(param_0);
    yaw_setIdeal(param_0, yaw_getIdeal(param_0) + local_3);
}

f32 func_808003B8_baswim(s32 param_0) {
    f32 local_0[3];
    func_8009BB24(param_0, local_0);
    func_800F10B4(func_800EEF94(local_0), 50.0f, 200.0f, 0.0f, 1.0f);
}

void baswim_entrypoint_12(PlayerState *param_0)
{
    f32 local_0;
    f32 local_1;

    local_0 = func_800F1214(func_808003B8_baswim(param_0), 140.0f, 90.0f);
    local_1 = _bafpctrl_entrypoint_3(param_0);
    local_0 *= func_800F10B4(local_1, 0.1f, 1.0f, local_1 * local_1, 1.0f);
    func_8009BFE4(param_0, local_0, 1.6f);
    local_1 = bastick_getY(param_0);
    if (local_1 < 0.0f) {
        func_8009BF5C(param_0, func_800F10B4(local_1, -1.0f, 0.0f, 275.0f, 360.0f));
    } else {
        func_8009BF5C(param_0, func_800F10B4(local_1, 0.0f, 1.0f, 0.0f, 85.0f));
    }
}

void baswim_entrypoint_13(PlayerState *param_0)
{
    f32 local_0;
    f32 local_1[4];
    local_0 = func_8009BFCC(param_0);
    func_800EF4E4(local_1, local_0, yaw_get(param_0), 0.0f, 0.0f, (*(f32 **)((u8 *)param_0 + 0x134))[0]);
    (*(f32 **)((u8 *)param_0 + 0x134))[0] = func_800F0E00((*(f32 **)((u8 *)param_0 + 0x134))[0] - (*(f32 **)((u8 *)param_0 + 0x134))[1] * func_800D8FF8(), 0.0f);
    func_8009B94C(param_0, local_1);
    func_8009BA9C(param_0, local_1);
}

f32 baswim_entrypoint_14(u8 *param_0) {
    return *(*(f32 **)((s8 *)(param_0) + (0x134)));
}
