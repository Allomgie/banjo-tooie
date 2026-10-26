#include "common.h"

#define D ((CactusData *)this)
extern int D_80800D00_chcactusofstrength;
extern int D_80800D48_chcactusofstrength;
extern int D_80800D90_chcactusofstrength;
extern s32 func_800D9058(f32);
typedef union { s32 local_0; void *local_1; } CactusStrengthEvent;
typedef struct { u8 pad0[0x24]; f32 vel; f32 minY; f32 maxY; } CactusData;
extern void func_800EE7F8();
extern void func_800EF1B8(f32 *, f32, f32);
extern void _sudeflect_entrypoint_0(f32 *, f32, f32, s32);
extern s32 func_800D9078(f32 *);
extern void func_80101FDC(Actor *, s32);
extern u8 unk28[];
extern u8 unk50_31[];
extern u8 unk2C[];
extern Actor *_subaddiefind_entrypoint_0(f32 *, s32, s32, s32);
extern Actor *func_80106790();
extern s32 D_80800DD8_chcactusofstrength;
extern f32 func_800DC178(f32, f32);
extern void func_800EEB9C(f32 *, f32, f32);
extern s32 func_800BABB8(s32, f32 *, f32 *, f32, void *);
extern void _subaddieaudioquick_entrypoint_2(Actor *, f32 *, void *);
extern u8 D_80800E18_chcactusofstrength[];
extern f32 _mlwave_entrypoint_5(void *, f32, f32);
extern s32 _mlwave_entrypoint_8(void *, f32);
extern void func_800CE88C(int, int);
extern int func_800CEAA8(int);
extern void func_800D1000(int, int, int, int, int);
extern int D_80800E24_chcactusofstrength;
extern int D_80800E64_chcactusofstrength;
extern u8 unk50[];
extern void func_800B4470(f32 *, f32 *, s32 *, s32, f32, f32, s32, s32, s32);
extern void func_800C4104(s32, f32, s32, f32 *, f32, f32);
extern u8 D_80800E08_chcactusofstrength[];
extern f32 mlAbsF(f32);
extern f32 func_800F13F0(f32, f32);
extern f32 func_800F0E00(f32, f32);
extern f32 func_800F10B4(f32, f32, f32, f32, f32);
extern void func_800C31DC(s32, f32);
void func_808006BC_chcactusofstrength();
void func_80800718_chcactusofstrength();
void func_80800824_chcactusofstrength(Actor *param_0, f32 param_1);
void func_80800C18_chcactusofstrength();
int func_808004F8_chcactusofstrength();
void func_80800780_chcactusofstrength();
void func_8080094C_chcactusofstrength();

int chcactusofstrength_entrypoint_0()
{
  return (int)&D_80800D00_chcactusofstrength;
}

int chcactusofstrength_entrypoint_1()
{
  return (int)&D_80800D48_chcactusofstrength;
}

int *chcactusofstrength_entrypoint_2()
{
    return &D_80800D90_chcactusofstrength;
}

void func_80800024_chcactusofstrength(Actor *param_0)
{
    switch (param_0->unk70_10) {
        case 2:
            if (func_80101DDC(param_0)) {
                if (param_0->unk6C_0 != 0) {
                    param_0->unk6C_0--;
                } else {
                    func_80102424(param_0, 3);
                    param_0->unk6C_0 = func_800D9058(0.5f);
                }
            }
            break;
        case 3:
            if (func_80101DDC(param_0)) {
                func_80102424(param_0, 1);
                _gcaudiolist_entrypoint_0(0);
                func_80103110(param_0, 0);
            }
            break;
    }
}

void func_80800108_chcactusofstrength(s32 arg0) 
{
}
void func_80800110_chcactusofstrength(Actor *param_0, s32 param_1)
{
    s32 local_0;

    if (param_0->unk70_10 == 1) {
        switch (func_8008FCC8(param_0->unk0)) {
        case 1: local_0 = 1; break;
        case 0xB: local_0 = 2; break;
        default: local_0 = 4; break;
        }
        if (local_0 != -1) {
            func_80102424(param_0, 2, local_0);
            _gcaudiolist_entrypoint_0(0);
            func_80103110(param_0, 1);
            param_0->unk6C_0 = 8;
            func_80101180(0x13B, 0xA, local_0);
        }
    }
}

s32 func_808001C4_chcactusofstrength(Actor *param_0, s32 param_1, CactusStrengthEvent param_2)
{
    switch (param_1) {
    case 0x40:
        func_80800110_chcactusofstrength(param_0, param_2.local_0);
        break;
    default:
        return 0;
    }
    return 1;
}

void func_80800200_chcactusofstrength(Actor *this)
{
    f32 pos[3];
    f32 vel;
    f32 dec;

    func_800EE7F8(pos, this->position);
    func_800EF1B8(pos, 135.0f, -55.0f);
    _sudeflect_entrypoint_0(pos, 60.0f, 75.0f, 2);
    func_8080094C_chcactusofstrength(this);
    switch (this->unk70_10) {
    case 1:
        func_808006BC_chcactusofstrength(this);
        break;
    case 2:
        func_80800824_chcactusofstrength(this, 20.0f);
        if (0.0f < this->unk58) {
            if (func_800D9078(&this->unk58)) {
            }
        } else {
            this->position[1] += D->vel;
            if (D->maxY <= this->position[1]) {
                this->position[1] = D->maxY;
                func_80800718_chcactusofstrength(this);
                this->unk64_16 = 0;
                func_80101FDC(this, 4);
            } else {
                D->vel -= 5.0f;
                if (D->vel <= 0.0f) {
                    func_80101FDC(this, 1);
                }
            }
        }
        break;
    case 3:
        func_80800824_chcactusofstrength(this, -20.0f);
        this->position[1] += D->vel;
        if (0 < D->vel) {
            dec = 10.0f;
        } else {
            dec = 5.0f;
        }
        D->vel -= dec;
        if (D->vel < -50.0f) {
            D->vel = -50.0f;
        }
        if (this->position[1] <= D->minY) {
            this->position[1] = D->minY;
            func_80800780_chcactusofstrength(this);
        }
        break;
    }
}

int func_808003EC_chcactusofstrength(f32 param_0[3])
{
    Actor *local_0;
    local_0 = param_0;
    *(s32 *)((char *)local_0 + 0x50) = 0;
    *(f32 *)((char *)local_0 + 0x28) = param_0[2];
    *(f32 *)((char *)local_0 + 0x2C) = 1200.0f;
    if (func_800D0A9C(0x1E, 1, local_0))
    {
        func_800FFAB0(local_0);
    }
}

int func_80800440_chcactusofstrength(Actor *param_0, s32 param_1, s32 param_2)
{
  Actor *local_var;
  switch (param_1)
  {
    case 0xA:
      func_808004F8_chcactusofstrength(param_0, param_2);
      return 1;

    case 0xB:
      if (param_2 == 2)
      {
        func_800FFAB0(param_0);
      }
      func_800F7F98(func_800F54E4(), 0);
      return 3;

    case 0x95:
      local_var = _subaddiefind_entrypoint_0((u8*)param_0 + 4, 0x13A, -1, 0);
      if (local_var != 0)
      {
        param_0->unk3C = local_var->unk0;
      }
      goto block_11;
    default:
      return 0;
  }
block_11:
  return 1;
}

int func_808004F8_chcactusofstrength(param_0, param_1) ALSeqPlayer *param_0; s32 param_1;
{
  f32 local_0;
  f32 local_1;
  s32 local_2;
  s32 *local_3;

  local_0 = 0.0f;
  local_2 = *(s32 *)((char *)(param_0) + 0x50);
  local_3 = (s32 *)((char *)(param_0) + 0x50);
  local_1 = *(f32 *)((char *)(param_0) + 0x2C) - *(f32 *)((char *)(param_0) + 0x28);
  if ((local_2 == 0) || (local_1 = local_1, local_2 = local_2, (func_800CEAA8(0) != 0))) {
    if ((*local_3 & param_1) == 0) {
      switch (param_1) {
      case 1:
        *(s32 *)((char *)(param_0) + 0x50) = *local_3 | 1;
        local_0 = local_1 * 0.25f;
        break;
      case 2:
        *(s32 *)((char *)(param_0) + 0x50) = *local_3 | 2;
        local_0 = local_1 * 0.25f;
        break;
      case 4:
        *(s32 *)((char *)(param_0) + 0x50) = *local_3 | 4;
        local_0 = local_1 * 0.5000100136f;
        break;
      }
      if (local_2 == 0) {
        func_800CE8D8(0, 0x41A00000, 0x14);
        func_800CE88C(0, 1);
        _subaddieDll_entrypoint_4(param_0, 1);
      }
      func_80101FDC(param_0, 2);
      *(f32 *)((char *)(param_0) + 0x24) = sqrtf(10.0f * local_0);
      if ((*(s32 *)((char *)(param_0) + 0x50) & 7) != 7) {
        func_800FC618(0xE, -1);
        *(f32 *)((char *)(param_0) + 0x58) = 0.200000003f;
        _capod_entrypoint_13(*(s32 **)param_0, 0, 0xAA, 0x800);
        func_800F7F98(func_800F54E4(), 1);
        return;
      }
      func_800FC618(0x10, -1);
      _capod_entrypoint_13(*(s32 **)param_0, 0, 2, 0x800);
      func_800F7F98(func_800F54E4(), 1);
    }
  }
}

void func_808006BC_chcactusofstrength(param_0) Actor *param_0;
{
  s32 local_0;
  ;
  if (*((s32 *) (((char *) param_0) + 0x50)))
  {
    if (func_800CEAD0(0) != 0)
    {
      if (func_800CEAA8(0) != 0)
      {
        func_800CE88C(0, 0);
      }
      func_80101FDC(param_0, 3);
    }
  }
}

void func_80800718_chcactusofstrength(param_0) u8 *param_0; {
    u8 *local_0;
    u8 *local_1;

    local_1 = func_80106790((*(s32 *)((s8 *)(param_0) + (0x3C))));
    local_0 = local_1;
    func_80101FDC(local_1, 2);
    func_80103110(local_0, 1);
    (*(f32 *)((s8 *)(local_0) + (0x58))) = 2.5f;
    _mlwave_entrypoint_0(func_80100074(local_0, 1, 0x1C), 0x42C80000, 0x42A00000);
}

void func_80800780_chcactusofstrength(param_0) Actor *param_0;
{
    func_800B4470(param_0->position, NULL, NULL, 1, 0.5f, 0.0f, 125, 250, 0);
    func_800C4104(0x417, 1.0f, 0x7D00, param_0->position, 1250.0f, 2500.0f);
    func_80101FDC(param_0, 1);
    *(s32 *)&param_0->unk50 = 0;
    _subaddieDll_entrypoint_4(param_0, 1);
}

void func_80800824_chcactusofstrength(Actor *param_0, f32 param_1)
{
    s32 local_3;
    f32 local_0[3];
    f32 local_1[3];
    f32 local_2[3];
    s32 local_4;

    func_800EE7F8(local_1, param_0->position);
    func_800EE7F8(local_2, local_1);
    local_2[1] += param_1;
    local_3 = func_800B53A4(2);
    for (local_4 = 0; local_4 < 2; local_4++) {
        func_800EEB9C(local_0, func_800DC178(0.0f, 270.0f), 20.0f);
        func_800EF04C(local_0, local_1);
        func_800BABB8(local_3, local_0, local_2, 1.0f, &D_80800DD8_chcactusofstrength);
    }
}

void func_8080094C_chcactusofstrength(param_0) Actor *param_0;
{
    f32 local_1;
    f32 local_0;
    f32 local_2;

    if (param_0->unk70_10 == 2 || param_0->unk70_10 == 3) {
        if (param_0->unk5F == 0) {
            _subaddieaudioloop_entrypoint_4(param_0, param_0->position, 1, D_80800E08_chcactusofstrength);
        }
        if (param_0->unk5F != 0) {
            local_2 = mlAbsF(((f32 *)param_0->actorData)[3]);
            local_1 = func_800F13F0(local_2, 20.0f);
            local_1 = func_800F0E00(5.0f, local_1);
            local_0 = func_800F10B4(local_1, 5.0f, 20.0f, 1.1f, 1.4f);
            func_800C4350(param_0->unk5F, param_0->position, 0);
            func_800C31DC(param_0->unk5F, local_0);
            func_800C3BDC(param_0->unk5F);
        }
    } else {
        _subaddieaudioloop_entrypoint_2(param_0);
    }
}

void func_80800A44_chcactusofstrength(Actor *param_0)
{
    f32 local_2;
    void *local_0;
    f32 local_1[3];

    if (param_0->unk70_10 == 2) {
        local_0 = (void *)func_80100094(param_0, 1);
        _mlwave_entrypoint_1(local_0);
        local_2 = _mlwave_entrypoint_5(local_0, -2e+01f, 20.0f);
        param_0->rotation[2] = local_2;
        if (_mlwave_entrypoint_8(local_0, 0.75f) || _mlwave_entrypoint_8(local_0, 0.25f)) {
            _subaddieaudioquick_entrypoint_2(param_0, param_0->position, D_80800E18_chcactusofstrength);
        }
        if (func_800D9078(&param_0->unk58)) {
            func_800EE7F8(local_1, param_0->actorData);
            func_800EF1B8(local_1, param_0->rotation[1], -60.0f);
            local_1[1] -= 40.0f;
            _chexploder_entrypoint_3(param_0, local_1, 3);
        }
    }
}

int func_80800B24_chcactusofstrength(s32 param_0)
{
    s32 local_0;
    s32 *local_1 = (s32 *)((char *)param_0 + 0x0);
    if (func_800D0A9C(0x1E, 1))
    {
        func_800FFAB0(local_1);
    }
    else
    {
        local_0 = (s32)((char *)param_0 + 0x4);
        func_800EE7F8((s32 *)((char *)param_0 + 0x18), (s32 *)((char *)param_0 + 0x4));
        *(f32 *)((char *)param_0 + 8) += 225.0f;
    }
}

int func_80800B90_chcactusofstrength(Actor *param_0, s32 param_1, s32 param_2)
{
    Actor *local_0;
    switch (param_1) {
    case 0x90:
        func_80800C18_chcactusofstrength(param_0);
        func_800FFAB0(param_0);
        return 1;
    case 0x95:
        local_0 = _subaddiefind_entrypoint_0(param_0->position, 0x13B, -1, 0);
        if (local_0) param_0->unk3C = local_0->unk0;
        break;
    default:
        return 0;
    }
    return 1;
}

void func_80800C18_chcactusofstrength(param_0) Actor *param_0;
{
  void *local_0;
  local_0 = func_80106790(*(int **)((char *)param_0 + 0x3C));
  func_800BABB8(0, (char *)param_0 + 4, (char *)param_0 + 4, *(f32 *)((char *)param_0 + 0x38), &D_80800E24_chcactusofstrength);
  _subaddieaudioquick_entrypoint_2(param_0, (char *)param_0 + 4, &D_80800E64_chcactusofstrength);
  func_800D1000(0x1E, 1, 0, 1, 0);
  *((int *) (((char *) local_0) + 0x50)) = 0;
  if (func_800CEAA8(0) != 0)
  {
    func_800CE88C(0, 0);
  }
}
