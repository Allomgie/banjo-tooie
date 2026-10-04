#include "core2/1E76880.h"

extern f32 bastick_getX(PlayerState *);
extern f32 mlAbsF(f32);
extern f32 func_800F1344(f32, f32, f32, f32, f32);
extern f32 yaw_getIdeal(PlayerState *);
extern void yaw_setIdeal(PlayerState *, f32);
f32 bastick_distance();
f32 bastick_getAngleRelativeToBanjo();
void yaw_update();
void yaw_set(void *, f32);
f32 func_800F1DCC(f32 a, f32 b);
extern f32 yaw_get(PlayerState *);
extern f32 func_800136E4(f32);
extern void func_800F1B78(f32 *, f32 *, f32, f32);
extern void func_8009BF5C(PlayerState *, f32);
extern void baroll_setIdeal(PlayerState *, f32);
void func_8009D2D8();

s32 func_8009CF90() 
{
    return 0x8;
}

void func_8009CF98(PlayerState *param_0)
{
  yaw_init();
  *((f32 *) (((u8 *) (*((u8 **) (((u8 *) param_0) + 0xFC)))) + 4)) = 0.0f;
  *((s32 *) (((u8 *) (*((u8 **) (((u8 *) param_0) + 0xFC)))) + 0)) = 0;
  func_8009D2D8(param_0, 1);
}

void func_8009CFD8(PlayerState *param_0, f32 param_1)
{
    *(f32*)(*(s32*)((s8*)param_0 + 252) + 4) = param_1;
}

void func_8009CFE8(PlayerState *param_0) {
    f32 x = bastick_getX(param_0);
    f32 d;
    if (0.03f < mlAbsF(x)) {
        d = func_800F1344(x, 0.0f, 1.0f, 1.0f, 6.0f);
    } else {
        d = 0.0f;
    }
    yaw_setIdeal(param_0, yaw_getIdeal(param_0) + d);
}

void func_8009D088(u8 *param_0) {
    switch (*(*(u32 **)((s8 *)(param_0) + (0xFC)))) {
    case 0:
        break;
    case 1:
        if (bastick_distance(param_0) != 0.0f) {
            yaw_setIdeal(param_0, bastick_getAngleRelativeToBanjo(param_0));
        }
        yaw_update(param_0);
        return;
    case 5:
        if (bastick_distance(param_0) != 0.0f) {
            yaw_setIdeal(param_0, bastick_getAngleRelativeToBanjo(param_0) + 180.0f);
        }
        yaw_update(param_0);
        return;
    case 3:
        yaw_update(param_0);
        return;
    case 6:
        func_8009CFE8(param_0);
        yaw_update(param_0);
        return;
    case 4:
        if (bastick_distance(param_0) != 0.0f) {
            yaw_setIdeal(param_0, bastick_getAngleRelativeToBanjo(param_0));
            yaw_set(param_0, yaw_getIdeal(param_0));
        }
        yaw_update(param_0);
        return;
    case 7:
        if (bastick_distance(param_0) != 0.0f) {
            f32 sp24 = bastick_getAngleRelativeToBanjo(param_0);
            if ((*(f32 *)((s8 *)((*(u32 **)((s8 *)(param_0) + (0xFC)))) + (4))) <= mlAbsF(func_800F1DCC(yaw_getIdeal(param_0), sp24))) {
                yaw_setIdeal(param_0, bastick_getAngleRelativeToBanjo(param_0));
            }
        }
        yaw_update(param_0);
        return;
    case 8:
        if (bastick_distance(param_0) != 0.0f) {
            yaw_setIdeal(param_0, bastick_getAngleRelativeToBanjo(param_0));
        } else {
            yaw_setIdeal(param_0, yaw_get(param_0));
        }
        yaw_update(param_0);
        return;
    case 9:
        yaw_update(param_0);
    default:
        return;
    }
}

void func_8009D2D8(param_0, param_1) PlayerState * param_0; s32 param_1;
{
  *(*(s32 **)((u8 *)param_0 + 0xFC)) = param_1;
}

u32 func_8009D2E4(u8 *param_0)
{
  s32 **ptr;
  return *(*((s32 ***) (param_0 + 0xFC)));
}

void func_8009D2F0(PlayerState *param_0, s32 param_1, f32 param_2)
{
  f32 in[3];
  f32 out[3];
  if ((func_80096628(param_0) & 2) == 0)
  {
    func_800963C0(param_0, in);
    if (param_1 != 0)
    {
      func_800F1B78(out, in, func_800136E4(yaw_get(param_0) + 180.0f), param_2);
    }
    else
    {
      func_800F1B78(out, in, yaw_get(param_0), param_2);
    }
    func_8009BF5C(param_0, out[0]);
    baroll_setIdeal(param_0, out[2]);
  }
}

void func_8009D3A8(PlayerState *param_0, s32 param_1)
{
    func_8009D2F0(param_0, param_1, 1.0f);
}
