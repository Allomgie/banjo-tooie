#include "common.h"

extern f32 func_800D8FF8(void);
extern void func_800EFA20(f32 *, f32 *, f32);
extern void func_800EE780(f32 *, f32 *, f32 *);
extern void func_800DA298(void);
extern void *func_80100094();
extern void _sueggmove_entrypoint_0();
extern void *func_800FAB50(f32 *, f32 *, f32 *, u32, f32);
extern f32 func_800136E4(f32);
extern f32 func_800F0E00(f32, f32);
extern void func_800EE7F8();
void sueggmove_entrypoint_8();
void func_8080012C_sueggmove();

void func_80800000_sueggmove(Actor *param_0, f32 *param_1, f32 *param_2)
{
    f32 local_1;
    f32 local_0[3];

    local_1 = func_800D8FF8();
    *(f32 *)&param_0->actorData[5] += *(f32 *)&param_0->actorData[7] * local_1;
    if (*(f32 *)&param_0->actorData[5] < param_0->unk54 * local_1) {
        *(f32 *)&param_0->actorData[5] = param_0->unk54 * local_1;
    }
    func_800EFA20(local_0, (f32 *)&param_0->actorData[4], local_1);
    func_800EE780(param_2, param_1, local_0);
}

int sueggmove_entrypoint_0(s32 param_0, s32 param_1)
{
  Actor *local_0;
  local_0 = func_80106790(param_1 | 0);
  if (param_1)
  {
  }
  local_0->unk3C = param_0;
}

int sueggmove_entrypoint_1()
{
  Actor *local_0 = func_80106790();
  return local_0->unk3C;
}

s32 sueggmove_entrypoint_2(void) {
    return (*(s32 *)((s8 *)(func_80100094(func_80106790(), 0)) + (0x34)));
}

func_80800108_sueggmove(u8 *param_0) {
    if (!param_0[0xD]) {
        param_0[0xC] = 1;
        param_0[0xD] = 8;
    }
}

void func_8080012C_sueggmove(param_0) Actor *param_0;
{
    u8 *local_3;
    f32 local_0[3];
    f32 local_1[3];
    u8 *local_2;
    local_3 = func_80100094(param_0, 0);
    local_3[0xC] = 0;
    func_80800000_sueggmove(param_0, param_0->position, local_1);
    func_800EA600(_sueggmove_entrypoint_0, param_0->unk0);
    local_2 = func_800FAB50(param_0->position, local_1, local_0, 0x24200A0, 15.0f);
    func_800EA614();
    if (local_2) {
        if (!local_3[0xE]) {
            func_800EFD24((f32 *)((u8 *)param_0 + 0x28));
            func_800F1988(local_0, &param_0->rotation[0], &param_0->rotation[1]);
            param_0->rotation[0] = func_800136E4(param_0->rotation[0] - 90.0f);
        } else {
            func_800F059C((f32 *)((u8 *)param_0 + 0x28), (f32 *)((u8 *)param_0 + 0x28), local_0);
            *(f32 *)((u8 *)param_0 + 0x2C) = func_800F0E00(*(f32 *)((u8 *)param_0 + 0x2C), 250.0f);
            func_80800108_sueggmove(local_3);
        }
        *(s32 *)(local_3 + 0x34) = *(s32 *)(local_2 + 8);
    }
    func_800EE7F8(param_0->position, local_1);
    *(f32 *)(local_3 + 0x10) = -9000.0f;
}

int sueggmove_entrypoint_3(s32 param_0)
{
  u8 *local_0;
  {
    local_0--;
  }
  local_0 = func_80100094(param_0, 0);
  return local_0[12];
  local_0++;
}

void sueggmove_entrypoint_4(u8 *param_0) {
    u8 *sp1C;
    u8 *temp_v0;

    temp_v0 = func_80100094(param_0, 0);
    (*(f32 *)((s8 *)(param_0) + (0x54))) = 0.0f;
    (*(f32 *)((s8 *)(param_0) + (0x34))) = 0.0f;
    sp1C = temp_v0;
    func_800EFD24(param_0 + 0x18);
    (*(s8 *)((s8 *)(sp1C) + (0xC))) = 0;
    (*(s8 *)((s8 *)(sp1C) + (0xE))) = 0;
    (*(s8 *)((s8 *)(sp1C) + (0xF))) = 0;
    (*(s8 *)((s8 *)(sp1C) + (0xD))) = 0;
    sueggmove_entrypoint_8(param_0, 1);
}

void sueggmove_entrypoint_5(s32 param_0, s32 param_1)
{
  s32 *local_0;
  ;
  *((s8 *) ((s32)func_80100094(param_0, 0) + 0xE)) = param_1;
}

void sueggmove_entrypoint_6(Actor *param_0, f32 param_1, f32 param_2)
{
  *(f32 *)((char *)param_0 + 0x34) = param_1;
  *(f32 *)((char *)param_0 + 0x54) = param_2;
}

s32 sueggmove_entrypoint_7(s32 param_0) {
    func_800EE7F8(param_0 + 0x28);
}

void sueggmove_entrypoint_8(unused, param_1) s32 unused; s32 param_1; {
    *(s8 *)((s32)func_80100094(unused, 0) + 0xF) = (s8) param_1;
}

int sueggmove_entrypoint_9(Actor *param_0)
{
  u8 *local_0;
  f32 local_1[3];
  local_0 = func_80100094(param_0, 0);
  if (local_0[0xD] != 0)
  {
    local_0[0xD]--;
  }
  func_800EE7F8(local_1, (u8 *)param_0 + 4, local_0);
  if (local_0[0xF] == 1)
  {
    func_8080012C_sueggmove(param_0);
  }
  func_800EFB24((u8 *)param_0 + 0x18, (u8 *)param_0 + 4, local_1);
}

void sueggmove_entrypoint_10(s32 param_0, s32 param_1) {
    f32 local_0[3];
    func_800FAB50(param_0, param_1, local_0, 0x24200A0, 15.0f);
}
