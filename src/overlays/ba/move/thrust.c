#include "common.h"

extern f32 func_8009BFCC(s32);
extern f32 yaw_get(s32);
extern void func_800EF4E4(s32, f32, f32, f32, f32, f32);
typedef struct { u32 pad_0; f32 local_0[3]; f32 local_1[3]; u8 pad_1[0xC]; f32 local_2[3]; f32 local_3; f32 local_4; u8 pad_2[0x48]; f32 local_5; u32 pad_3; f32 local_6; } MoveThrustState;
typedef struct { u8 pad_0[0xC8]; MoveThrustState *local_0; } MoveThrustPlayer;
extern f32 func_800D8FF8(void);
extern void func_800EF334(f32 *, f32);
extern void func_800EFA20(f32 *, f32 *, f32);

void func_80800000_bamovethrust(s32 param_0, s32 param_1, f32 param_2) {
    f32 local_0 = func_8009BFCC(param_0);
    func_800EF4E4(param_1, local_0, yaw_get(param_0), 0.0f, 0.0f, param_2);
}

void bamovethrust_entrypoint_0(s32 arg0) 
{
}
void bamovethrust_entrypoint_1(void *param_0)
{
  void *p;
  ;
  *((f32 *) (((u8 *) (*((void **) (((u8 *) param_0) + 0xC8)))) + 0x8C)) = 1.0f;
  p = *((void **) (((u8 *) param_0) + 0xC8));
  ;
  *((f32 *) (((u8 *) (*((void **) (((u8 *) param_0) + 0xC8)))) + 0x84)) = 1.0f;
  *((f32 *) (((u8 *) (*((void **) (((u8 *) param_0) + 0xC8)))) + 0x88)) = 1.0f;
}

void bamovethrust_entrypoint_2(u8 *param_0, f32 param_1) {
    func_80800000_bamovethrust(param_0, *(u8 **)(param_0 + 0xC8) + 0x10, param_1);
}

int bamovethrust_entrypoint_3(s32 param_0, f32 param_1)
{
  *((f32 *) ((*((s32 *) (param_0 + 0xC8))) + 140)) = param_1;
}

void bamovethrust_entrypoint_4(u8 *param_0, f32 param_1) {
    (*(f32 *)((s8 *)((*(u8 **)((s8 *)(param_0) + (0xC8)))) + (0x84))) = param_1;
}

void bamovethrust_entrypoint_5(MoveThrustPlayer *param_0)
{
    f32 local_2;
    f32 local_0[3];
    f32 local_1[3];

    func_80800000_bamovethrust(param_0, local_0, param_0->local_0->local_6);
    func_800EE7F8(local_1, param_0->local_0->local_1);
    func_800EF334(local_1, param_0->local_0->local_5);
    func_800EE780(param_0->local_0->local_1, local_1, local_0);
    local_2 = func_800D8FF8();
    param_0->local_0->local_1[1] += param_0->local_0->local_3 * local_2;
    if (param_0->local_0->local_1[1] < param_0->local_0->local_4) param_0->local_0->local_1[1] = param_0->local_0->local_4;
    func_800EFA20(param_0->local_0->local_2, param_0->local_0->local_1, local_2);
    func_800EF04C(param_0->local_0->local_0, param_0->local_0->local_2);
}

f32 bamovethrust_entrypoint_6(u8 *param_0) {
    return (*(f32 *)((s8 *)((*(u8 **)((s8 *)(param_0) + (0xC8)))) + (0x8C)));
}
