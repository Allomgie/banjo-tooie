#include "common.h"

extern s32 func_8010A6B0(Actor *, s32);
extern void func_80108B04(Actor *, s32);
extern f32 func_800D8FF8(void);
extern u8 unk6A[];
extern void func_800EFA4C(f32 *, f32, f32, f32);
extern void func_801015D0(Actor *);
extern void *func_800DE448(f32 *, f32 *, f32, f32 *, s32);
extern int D_80800770_chjigsaw;
extern int D_808007B8_chjigsaw;
extern f32 func_800DC0C0(void);
extern f32 func_800DC178(f32, f32);
extern void func_800EE7F8(f32[3], f32[3]);
extern void func_800EF214(f32[3], f32, f32, f32);
extern void func_800BABB8(s32, f32[3], f32[3], f32, void *);
extern void *_fxgenlist_entrypoint_1(void);
typedef struct { u32 pad_0 : 28; u32 local_0 : 1; u32 pad_1 : 3; } CodexJigsawFlags65;

void func_80800000_chjigsaw(Actor *param_0, void *param_1)
{
    if (func_8010A6B0(param_0, (u32)*(u16 *)((u8 *)param_1 + 0x1A) >> 5)) {
        if (!func_800DA298(0x665)) {
            func_80108B04(param_0, 0);
            func_800D0BD4((s32)param_0->unk50, 1);
            _suautobaddies_entrypoint_3();
        }
    }
}

void func_80800070_chjigsaw(u8 *param_0) {
    if (func_800D0B68((s32) (*(f32 *)((s8 *)(param_0) + (0x50))), 1) != 0) {
        func_800FFAB0(param_0);
        return;
    }
    func_800D05E4((s32) (*(f32 *)((s8 *)(param_0) + (0x50))), 1, (*(s32 *)((s8 *)(param_0) + (0))));
    if ((*(f32 *)((s8 *)(param_0) + (0x58))) != 0.0f) {
        func_800FC6B0(0x18);
    }
    func_800D0778((s32) (*(f32 *)((s8 *)(param_0) + (0x50))), 1, param_0 + 4);
}

void func_8080011C_chjigsaw(u8 *param_0) {
    *(f32 *)(param_0 + 0x54) += func_800D8FF8() * 230.0f;
    if (*(f32 *)(param_0 + 0x54) >= 360.0f) {
        *(f32 *)(param_0 + 0x54) -= 360.0f;
    }
}

int func_8080017C_chjigsaw(Actor *param_0)
{
  s32 local_0;
  s32 new_var;
  unsigned short new_var2;
  local_0 = *((f32 *) (((char *) param_0) + 0x50));
  func_800D05E4(local_0, 1, 0);
  new_var = *((s32 *) (((char *) param_0) + 0x6C));
  new_var2 = new_var & 0x1FF;
  if (new_var2)
  {
    func_800C8B84(new_var2 | 0);
  }
}

void func_808001D0_chjigsaw(s32 arg0)
{
    func_80105834();
    func_8080011C_chjigsaw(arg0);
}
void func_808001F8_chjigsaw(Actor *param_0)
{
    s32 local_6;
    f32 local_0;
    f32 local_1[3];
    f32 local_2[3];
    f32 local_3[3];
    f32 local_4[3];
    f32 local_7;
    f32 local_5[3];
    s32 local_8;

    local_0 = func_800D8FF8();
    if (((CodexJigsawFlags65 *)((u8 *)param_0 + 0x78))->local_0) {
        func_800D0778((s32)param_0->unk50, 1, param_0->position);
    } else if (param_0->unk64_19) {
        func_800EE7F8(local_1, param_0->position);
        local_1[1] += 100.0f;
        func_800EE7F8(local_2, param_0->position);
        local_2[1] -= 100.0f;
        if (func_800BEF00(local_1, local_2, local_3, param_0->unk14)) {
            param_0->position[1] = local_2[1];
        } else {
            param_0->position[1] += ((f32 *)param_0->actorData)[7] * local_0;
        }
    }
    if (param_0->unk7C_12) {
        for (local_6 = 0; local_6 != 4; local_6++) {
            if (func_800DC0C0() < 0.015f) {
                func_80103DFC(param_0, local_4);
                local_7 = func_800DC178(0.0f, 360.0f);
                func_800EF214(local_4, local_7, func_800DC178(0.0f, 360.0f), 40.0f);
                _fxtwinkle_entrypoint_0(local_4);
            }
        }
        if (param_0->unk58 > 0.0f) {
            if (func_800DC0C0() < 2.0f * (param_0->unk58 / 3.0f)) {
                local_8 = func_800B5BE4(0x10);
                func_800BABB8(local_8, param_0->position, param_0->position, 1.0f, _fxgenlist_entrypoint_1());
                func_800BA22C(local_8, 1);
            }
            param_0->unk58 -= local_0;
        }
    }
    if (param_0->unk70_10 == 1) {
        if (1) {}
        if (((CodexJigsawFlags65 *)((u8 *)param_0 + 0x78))->local_0 && param_0->unk6C_0) {
            func_800EE7F8(local_5, param_0->position);
            local_5[1] += 100.0f;
            func_800C8CB8(param_0->unk6C_0, local_5);
        }
        func_8080011C_chjigsaw(param_0);
    }
}

void func_808004A0_chjigsaw(Actor *param_0, void *param_1)
{
    f32 local_0[3];
    func_800EFA4C(local_0, 0.0f, param_0->unk54, 0.0f);
    func_80101970(param_0);
    func_800DF47C(func_801015D0, param_0);
    func_800DE448(param_0->position, local_0, param_0->scale, NULL,
        func_8010347C(param_0->unk0));
}

s32 func_80800518_chjigsaw(Actor *param_0, s32 param_1, s32 param_2)
{
    f32 local_0[3];

    switch (param_1) {
    case 0x3E:
        func_80800000_chjigsaw(param_0, (*(s32 *)&param_2));
        break;
    case 0x12:
        param_0->unk64_19 = param_2;
        break;
    case 0x13:
        param_0->unk50 = param_2;
        break;
    case 0x14:
        if (param_2) {
            param_0->unk58 = 3.0f;
        } else {
            param_0->unk58 = 0.0f;
        }
        break;
    case 0x3D:
        _chjigsawcollect_entrypoint_1(&param_0, (s32)param_0->unk50, (*(u32 *)((u8 *)param_0 + 0x70) & 1));
        func_800FFAB0(param_0);
        break;
    case 0x55:
        param_0->unk6C_0 = func_800C8A98();
        func_800CF9E4((s32)param_0->unk50, 1, param_0->unk6C_0);
        func_800EE7F8(local_0, param_0->position);
        local_0[1] += 100.0f;
        func_800C8CB8(param_0->unk6C_0, local_0);
        break;
    default:
        return 0;
    }
    return 1;
}

int chjigsaw_entrypoint_0()
{
    return (int)&D_80800770_chjigsaw;
}

int func_808006CC_chjigsaw(s32 param_0)
{
  if (func_800D395C())
  {
    func_800FFAB0(param_0);
  }
  else
  {
    if (_subaddiedialog_entrypoint_16())
    {
      if (_subaddiedialog_entrypoint_11(0, 0xD0A, 0, param_0 + 4, 0x6F) != 0)
      {
        _gcfrontend_entrypoint_9(0x85);
        func_800FFAB0(param_0);
      }
    }
  }
}

int chjigsaw_entrypoint_1()
{
  return (int)&D_808007B8_chjigsaw;
}
