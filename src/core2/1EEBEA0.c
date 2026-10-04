#include "common.h"

extern s32 func_80110840(void);
extern f32 func_800F5CC0(s32);
extern f32 func_80013728(f32);
extern f32 func_800F5CEC(s32);
extern void func_800F5D70(s32, f32 *);
extern f32 func_800EEFFC(f32 *);
extern s32 func_800F5B0C(s32);

s32 func_801125B0() 
{
    return 0x10;
}

void func_801125B8(Actor *param_0)
{
  f32 *ptr;
  ptr = ptr;
  *(*((f32 **) (((u8 *) param_0) + 0x4C))) = (0, 0.0f);
  *((*((f32 **) (((u8 *) param_0) + 0x4C))) + 1) = 0.0f;
  ;
  *((*((f32 **) (((u8 *) param_0) + 0x4C))) + 2) = 0.0f;
}

int func_801125D8(s32 param_0, f32 param_1)
{
  s32 new_var;
  new_var = -0x4C;
  *((f32 *) ((*((s32 *) (param_0 - new_var))) + 8)) = param_1;
 dummy_label_588917: ;
}

f32 func_801125E8(void *param_0) {

    return *(f32 *)((char *)(*(void **)((char *)param_0 + 0x4C)) + 0xC);
}

int func_801125F4() {
    s32 local_2;
    s32 local_3;
    s32 local_4;

    local_2 = func_800F53D0();
    local_3 = func_8009D2E4(local_2);
    local_4 = func_8009BAF4(local_2);
    return local_3 == 1 && local_4 == 2;
}

void func_80112648(u8 *param_0) {
    f32 local_0;
    f32 local_1[3];
    s32 local_2;
    u8 *local_3;
    f32 *local_4;

    local_2 = func_80110840();
    (*(f32 *)((s8 *)((*(u8 **)((s8 *)(param_0) + (0x4C)))) + (0))) = func_80013728(func_800F5CC0(local_2) + 90.0f);
    local_3 = (*(u8 **)((s8 *)(param_0) + (0x4C)));
    local_0 = (*(f32 *)((s8 *)(local_3) + (0)));
    if (local_0 > 90.0f) {
        (*(f32 *)((s8 *)(local_3) + (0))) = (f32) (180.0f - local_0);
    } else if (local_0 < -90.0f) {
        (*(f32 *)((s8 *)(local_3) + (0))) = (f32) (-180.0f - local_0);
    }
    (*(f32 *)((s8 *)((*(u8 **)((s8 *)(param_0) + (0x4C)))) + (4))) = func_800F5CEC(local_2);
    func_800F5D70(local_2, local_1);
    if ((func_800EEFFC(local_1) < 0.01f) || (func_800F5B0C(local_2) != 0) || (func_801125F4(local_2) == 0)) {
        (*(f32 *)((s8 *)((*(u8 **)((s8 *)(param_0) + (0x4C)))) + (4))) = 0.0f;
    }
    local_4 = *(f32 **)(param_0 + 0x4C);
    local_4[3] = local_4[2] * (local_4[1] * -local_4[0]);
}

f32 func_80112788(u8* param_0) {
  return *(f32*)(*(u32*)(param_0 + 0x4c) + 8);
}
