#include "common.h"

extern f32 func_800EEF94();
extern void func_800EF368(f32 *, f32);
extern f32 func_800D8FF8(void);
extern void func_800EF04C(f32 *, f32 *);
extern void func_800EFB24(f32 *, f32 *, f32 *);
typedef struct { u8 pad_0; s8 local_0; u8 pad_1[2]; f32 local_1; u8 local_2; u8 local_3; u8 local_4; u8 pad_2; u8 local_5[1]; } MissileHomeTarget;
extern Actor *_subaddielink_entrypoint_4(void *);
typedef struct { s8 b0; s8 b1; s8 pad2[2]; f32 f4; s8 b8; s8 b9; s8 bA; s8 padB; u8 xC[4]; } MissileS;
extern void _subaddielink_entrypoint_0();

void sumissilehome_entrypoint_0(s32 param_0, MissileS *param_1) {
    param_1->b8 = 0;
    param_1->b9 = 0;
    param_1->b0 = -1;
    param_1->b1 = -1;
    param_1->f4 = 6000.0f;
    param_1->bA = 2;
    _subaddielink_entrypoint_0(param_1->xC, param_1);
}

void sumissilehome_entrypoint_1(s32 param_0, u8 *param_1, unsigned long param_2)
{
  *((u8 *) (param_1 + 8)) = 1;
  *((s16 *) (param_1 + 2)) = param_2;
}

void sumissilehome_entrypoint_2(void *param_0, void *param_1, float param_2)
{
    *(u8 *)((char *)param_1 + 0xA) = 1;
    *(f32 *)((char *)param_1 + 4) = param_2;
}

s32 sumissilehome_entrypoint_3(s32 param_0, u8 *param_1, s32 param_2){
    param_1[0] = param_2;
}

void sumissilehome_entrypoint_4(s32 param_0, s32 *param_1, unsigned long param_2)
{
  *((u8 *) (((s8 *) param_1) + 9)) = param_2;
}

void sumissilehome_entrypoint_5(s32 param_0, u8 *param_1, s32 param_2, s32 param_3)
{
  s32 local_0;
  s32 local_1;

  local_0 = -1;
  if ((param_1[8] != 0) || (param_1[9] != 0))
  {
    if (param_1[8] != 0)
    {
      local_1 = func_8010A01C(param_0 + 4, param_0 + 0x28, param_2, param_3, *((s16 *) (((char *) param_1) + 2)));
      _subaddielink_entrypoint_1(&param_1[0xc], local_1);
      if (_subaddielink_entrypoint_4(&param_1[0xc]) == 0)
      {
        param_1[8] = 0;
      }
    }
    if (param_1[9] != 0)
    {
      if ((param_1[8] == 0) && (func_800EA068(0x4000) != 0))
      {
        local_0 = func_8010D490(param_0 + 4, param_0 + 0x28, param_2, param_3, (s8)param_1[0]);
      }
      param_1[1] = local_0;
    }
  }
}

void func_80800178_sumissilehome(u8 *param_0, s32 param_1) {
    f32 local_1 = func_800EEF94((f32 *)(param_0 + 0x28));
    func_800EFB24((f32 *)(param_0 + 0x28), param_1, param_0 + 4);
    func_800EF368((f32 *)(param_0 + 0x28), local_1);
}

void func_808001C8_sumissilehome(Actor *param_0, f32 *param_1, f32 param_2)
{
    f32 local_0[3];
    f32 local_1;
    local_1 = func_800EEF94((f32 *)&param_0->actorData[4]);
    func_800EFB24(local_0, param_1, param_0->position);
    func_800EF368(local_0, func_800D8FF8() * param_2);
    func_800EF04C((f32 *)&param_0->actorData[4], local_0);
    func_800EF368((f32 *)&param_0->actorData[4], local_1);
}

void sumissilehome_entrypoint_6(Actor *param_0, MissileHomeTarget *param_1)
{
    f32 local_0[3];
    Actor *local_1;

    if (param_1->local_2) {
        local_1 = _subaddielink_entrypoint_4(param_1->local_5);
        if (local_1 == NULL) {
            param_1->local_2 = 0;
            return;
        }
        func_8010A2FC(local_1, local_0, param_0->position);
    } else {
        if (!param_1->local_3 || param_1->local_0 < 0) return;
        func_800F5A00(param_1->local_0, local_0);
        local_0[1] += 60.0f;
    }
    if (param_1->local_4 == 1) func_808001C8_sumissilehome(param_0, local_0, param_1->local_1);
    else func_80800178_sumissilehome(param_0, local_0);
}
