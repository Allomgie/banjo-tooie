#include "common.h"
#include "core2/1EB5980.h"
#include "core2/1ED8C80.h"
#include "su/baddieaudioquick.h"

extern void *D_80800EB0_chcablecar;
extern void *D_80800EF8_chcablecar;
typedef struct { s16 local_0; s16 local_1; } CableCarEvent;
typedef struct { u8 pad_0[0x2A]; u8 pad_1 : 3; u8 local_0 : 1; u8 pad_2 : 4; } CableCarMarker;
extern void _mlwave_entrypoint_1(void *);
extern f32 _mlwave_entrypoint_5(void *, f32, f32);
extern u8 D_80800F68_chcablecar[];
extern void _subaddieaudioloop_entrypoint_4(Actor *, f32 *, s32, void *);
typedef struct { s16 local_0[3]; s16 local_1[3]; f32 local_2; } CableCarPath;
extern void func_800EFE50(f32 *, f32 *, f32 *, f32);
typedef struct { u8 pad[0x2A]; u8 b7 : 1; u8 b6 : 1; u8 b5 : 1; u8 rest : 5; } CcarS;
extern void func_80015178(s32);
typedef struct { u8 pad_0[0x28]; u32 pad_1 : 18; u32 local_0 : 1; u32 pad_2 : 13; } CableCarMarkerFlags;
typedef struct { u8 pad0[0x28]; u32 pad28_13 : 19; u32 unk28_12 : 1; u32 pad28_0 : 12; } CableCarInfo;
extern Actor *func_80106790(Unk80132ED0 *);
extern s32 func_800F4F34(s32, f32 *, f32, f32);
extern void _subaddieDll_entrypoint_4(void *, s32);
extern f32 func_800D8FF8(void);
extern f32 func_800EEB40(f32 *, f32 *);
extern void func_808005E0_chcablecar(Actor *);
extern void *func_80100094(Actor *, u32);
typedef struct { u8 pad_0[0x28]; u32 pad_1 : 19; u32 local_0 : 1; u32 pad_2 : 12; } Mass63CableMarker;
extern void _mlwave_entrypoint_0(void *, f32, f32);
typedef struct { u8 pad[0xC]; f32 progress; } CableCarProgress;
extern f32 func_800F10B4(f32, f32, f32, f32, f32);
typedef struct Mass45CableFlags { u32 local_0 : 12; u32 local_1 : 1; u32 local_2 : 19; } Mass45CableFlags;
extern void func_800EFA4C(f32 *, f32, f32, f32);
extern void func_800EF04C(f32 *, f32 *);
void func_80800DC8_chcablecar();
void func_808004EC_chcablecar();
void func_80800914_chcablecar();

extern f32 D_80800F40_chcablecar[3];
extern s16 D_80800F4C_chcablecar[];
extern s16 D_80800F58_chcablecar[];

typedef struct {
    u8 pad0[0xC];
    f32 unkC;
    u8 unk10;
} cablecarMemory;

int chcablecar_entrypoint_0()
{
  return &D_80800EB0_chcablecar;
}

int chcablecar_entrypoint_1()
{
  return &D_80800EF8_chcablecar;
}




































void func_80800D14_chcablecar();

s32 func_80800BD0_chcablecar();

void func_80800AF4_chcablecar();

void func_808007C8_chcablecar();

s32 func_8080070C_chcablecar(Actor *param_0, f32 param_1);

void func_8080069C_chcablecar();

void func_80800598_chcablecar();

void func_80800018_chcablecar(Actor *param_0)
{
  u8 *local_0;
  f32 local_1;
  s32 local_2;
  f32 local_3[3];
  f32 local_4[3];
  local_0 = func_80100094(param_0, 0);
  local_1 = func_800D8FF8();
  local_2 = 0;
  func_80800598_chcablecar(param_0);
  func_8080069C_chcablecar(param_0);
  switch (param_0->unk70_10)
  {
    case 1:
      if (func_800DA298(0xD4) != 0)
    {
      func_808007C8_chcablecar(param_0, 1, 4);
    }
      func_808005E0_chcablecar(param_0);
      break;

    case 2:
      if (func_80800BD0_chcablecar(param_0) != 0)
    {
      func_808007C8_chcablecar(param_0, 2, 5);
    }
      func_808005E0_chcablecar(param_0);
      break;

    case 3:
      if (!((Mass63CableMarker *)param_0->unk0)->local_0)
    {
      func_8010D254(local_3);
      func_800EE7F8(local_4, param_0->position);
      local_4[1] -= 400.0f;
      if (func_800EEB40(local_4, local_3) > 3062500.0f)
      {
        func_800DA524(0x67E);
        func_80101FDC(param_0, 6);
      }
    }
    else
      if (func_80800BD0_chcablecar(param_0) != 0)
    {
      func_808007C8_chcablecar(param_0, 4, 4);
    }
      func_808005E0_chcablecar(param_0);
      break;

    case 4:
      local_2 = 1;
      if (func_8080070C_chcablecar(param_0, (*((f32 *) (((s8 *) local_0) + 0xC))) - (local_1 * 0.045f)) != 0)
    {
      _susubgame_entrypoint_4(param_0, local_0 + 0x2C);
      func_800DA524(0x67E);
      func_80800AF4_chcablecar(param_0, 2);
    }
      break;

    case 5:
      local_2 = 1;
      if (func_8080070C_chcablecar(param_0, *((f32 *)(local_0 + 0xC)) + (local_1 * 0.045f)) != 0)
    {
      _susubgame_entrypoint_4(param_0, local_0 + 0x2C);
      func_800DA544(0x67E);
      func_80800AF4_chcablecar(param_0, 3);
      _subaddieDll_entrypoint_4(param_0, 1);
    }
      break;

    case 6:
      local_2 = 1;
      if (func_8080070C_chcablecar(param_0, (*((f32 *) (((s8 *) local_0) + 0xC))) - (local_1 * 0.045f)) != 0)
    {
      _subaddieDll_entrypoint_4(param_0, 0);
      func_80101FDC(param_0, 2);
    }
      break;

    case 7:
      func_808005E0_chcablecar(param_0);
      break;

  }

  func_80800D14_chcablecar(param_0, local_2);
  func_80800914_chcablecar(param_0);
  ((u8 *)param_0->unk0)[0x2A] &= ~0x10;
}

void func_808002E0_chcablecar(Actor *param_0)
{
    u8 *local_0;
    s32 local_1;
    s32 local_2;

    local_0 = func_80100094(param_0, 0);
    _susubgame_entrypoint_0(param_0, local_0 + 0x2C, 0);
    if (func_800EA05C() == 0x124) {
        func_8010A624(param_0);
        ((u8 *)param_0)[0x7E] &= ~0x40;
    }
    func_800EE940(local_0, param_0->position);
    func_800EFA6C(local_0 + 6, -8300, 2675, 0);
    *(s32 *)((u8 *)param_0 + 0x28) = 0;
    local_1 = func_800DA298(0x67E);
    local_2 = func_800DA298(0xD4);
    if (!local_1 && local_2) {
        *(f32 *)(local_0 + 0xC) = 0.0f;
        func_8080070C_chcablecar(param_0, 0.0f);
        func_80101FDC(param_0, 2);
    } else if (local_1) {
        *(f32 *)(local_0 + 0xC) = 1.0f;
        func_8080070C_chcablecar(param_0, 1.0f);
        func_80101FDC(param_0, 3);
        _subaddieDll_entrypoint_4(param_0, 1);
    } else {
        *(f32 *)(local_0 + 0xC) = 0.1f;
        func_8080070C_chcablecar(param_0, 0.1f);
    }
    _mlwave_entrypoint_0(local_0 + 0x10, 100.0f, 15.0f);
}

s32 func_80800B74_chcablecar();

s32 func_80800424_chcablecar(Actor *param_0, s32 param_1, CableCarEvent param_2)
{
    switch (param_1) {
    case 0x3D:
        func_80800DC8_chcablecar(param_0);
        break;
    case 0x2E:
        func_80800B74_chcablecar(param_0, param_2.local_0, param_2.local_1);
        break;
    case 0x1F:
        func_808004EC_chcablecar(param_0);
        break;
    case 0x95:
        if (func_800EA05C() == 0xD6) func_80108B04(param_0, 0);
        break;
    case 0x91:
        ((CableCarMarker *)param_0->unk0)->local_0 = 1;
        break;
    default:
        return 0;
    }
    return 1;
}

void func_808004EC_chcablecar(param_0) Actor *param_0;
{
    CableCarProgress *local_0;
    s32 local_1;

    local_0 = func_80100094(param_0, 0);
    if (local_0->progress < 0.4f) {
        local_1 = 0;
    } else if (local_0->progress > 0.6f) {
        local_1 = 255;
    } else {
        local_1 = (s32)func_800F10B4(local_0->progress, 0.4f, 0.6f, 0.0f, 255.0f);
    }
    func_801015D0(param_0);
    func_800DF6BC(local_1, 255);
}

void func_80800598_chcablecar(Actor *param_0) {
    u8 *local_1 = (u8 *)func_80100094(param_0, 0);
    u8 *local_0 = local_1 + 0x10;
    _mlwave_entrypoint_1(local_0);
    *(f32 *)((u8 *)param_0 + 0x44) = _mlwave_entrypoint_5(local_0, -5.0f, 5.0f);
}

void func_808005E0_chcablecar(Actor* arg0) {
    void* temp_a0;
    cablecarMemory* temp_v0;

    temp_v0 = func_80100094(arg0, 0);
    temp_a0 = &temp_v0->unk10;
    if (temp_v0->unkC < 0.5f) {
        if ((_mlwave_entrypoint_9(temp_a0, D_80800F40_chcablecar) != 0) && (func_800DC298(0.8f) != 0)) {
            _subaddieaudioquick_entrypoint_2(arg0, arg0->position, D_80800F4C_chcablecar);
        }
    } else if ((_mlwave_entrypoint_9(temp_a0, D_80800F40_chcablecar) != 0) && (func_800DC298(0.8f) != 0)) {
        _subaddieaudioquick_entrypoint_2(arg0, arg0->position, D_80800F58_chcablecar);
    }
}

void func_8080069C_chcablecar(Actor *param_0)
{
    s32 local_0;

    switch (param_0->unk70_10) {
    case 4:
    case 5:
    case 6:
        local_0 = 1;
        break;
    default:
        local_0 = 0;
        break;
    }
    if (local_0 || (!local_0 && param_0->unk5F)) {
        _subaddieaudioloop_entrypoint_4(param_0, param_0->position, local_0, D_80800F68_chcablecar);
    }
}

s32 func_8080070C_chcablecar(Actor *param_0, f32 param_1)
{
    CableCarPath *local_0;
    s32 local_1;
    f32 local_2[3];
    f32 local_3[3];
    local_0 = func_80100094(param_0, 0);
    local_1 = 0;
    if (param_1 < 0.0f) { param_1 = 0.0f; local_1 = 1; }
    else if (param_1 > 1.0f) { param_1 = 1.0f; local_1 = 1; }
    func_800EE88C(local_2, local_0->local_1);
    func_800EE88C(local_3, local_0->local_0);
    func_800EFE50(param_0->position, local_3, local_2, param_1);
    local_0->local_2 = param_1;
    return local_1;
}

void func_808007C8_chcablecar(Actor *param_0, s32 param_1, s32 param_2)
{
    u8 *local_0;
    s32 local_1;

    local_0 = func_80100094(param_0, 0);
    _subaddieDll_entrypoint_4(param_0, 1);
    func_801039E4(param_0->unk0);
    func_80103D48(param_0);
    if (*(s32 *)&param_1 == 2 && func_800DA9E4(0xBF, 1)) {
        param_1 = 3;
    }
    switch (param_1) {
    case 3:
        _susubgame_entrypoint_8(param_0, local_0 + 0x2C, 0x2F, 0x10010, 0);
        break;
    case 4:
        _susubgame_entrypoint_8(param_0, local_0 + 0x2C, 0x2E, 0x10010, 0);
        break;
    default:
        local_1 = (param_1 == 1) ? 0x1D : 0x21;
        func_80015178(3);
        ((CcarS *)param_0->unk0)->b5 = 1;
        _susubgame_entrypoint_6(param_0, local_0 + 0x2C, local_1, 0x10070, 0);
        break;
    }
    *(s32 *)((u8 *)param_0 + 0x28) = param_1;
    func_80101FDC(param_0, param_2);
}

void func_80800914_chcablecar(param_0) Actor *param_0;
{
    u8 *local_0;
    s32 local_1;
    f32 local_2[3];
    f32 local_3[3];
    f32 local_4[3];
    f32 local_5[3];

    local_0 = func_80100094(param_0, 0);
    local_1 = func_800F54E4();
    switch (param_0->actorData[4]) {
        case 3:
            if (*(f32 *)(local_0 + 0xC) > 0.15f &&
                !((Mass45CableFlags *)((u8 *)param_0 + 0x64))->local_1) {
                func_8080070C_chcablecar(param_0, 0.85f);
                param_0->unk64_19 = 1;
                _susubgame_entrypoint_8(param_0, local_0 + 0x2C, 0x2E, 0x12010, 0);
                func_800EFA4C(local_2, -80.0f, -425.0f, 0.0f);
                func_800EF04C(local_2, param_0->position);
                func_800F8294(local_1, local_2);
                func_800EFA4C(local_3, 0.0f, 270.0f, 0.0f);
                func_800F8444(local_1, local_3);
            }
            break;
        case 4:
            if (*(f32 *)(local_0 + 0xC) < 0.85f &&
                !((Mass45CableFlags *)((u8 *)param_0 + 0x64))->local_1) {
                func_8080070C_chcablecar(param_0, 0.15f);
                param_0->unk64_19 = 1;
                _susubgame_entrypoint_8(param_0, local_0 + 0x2C, 0x2F, 0x12010, 0);
                func_800EFA4C(local_4, 60.0f, -425.0f, 0.0f);
                func_800EF04C(local_4, param_0->position);
                func_800F8294(local_1, local_4);
                func_800EFA4C(local_5, 0.0f, 90.0f, 0.0f);
                func_800F8444(local_1, local_5);
            }
            break;
    }
}

void func_80800AF4_chcablecar(Actor *param_0, void *param_1)
{
    _subaddieDll_entrypoint_4(param_0, 0);
    func_80103D70(param_0);
    func_80101FDC(param_0, param_1);
    if (((CableCarMarkerFlags *)param_0->unk0)->local_0) {
        func_80015178(2);
        ((CableCarMarkerFlags *)param_0->unk0)->local_0 = 0;
    }
    param_0->actorData[4] = 0;
    param_0->unk64_19 = 0;
}

s32 func_80800B74_chcablecar(Actor *this, enum asset_e text_id, s32 param_2)
{
  if (!func_800DA298(0x67E))
  {
    func_80101FDC(this, 2);
  }
  else
  {
    func_80101FDC(this, 3);
    _subaddieDll_entrypoint_4(this, 1);
  }
}

s32 func_80800BD0_chcablecar(Actor *param_0)
{
    s32 local_0;

    local_0 = func_800F54E4();
    if (!func_800F6438(local_0) || !((CableCarInfo *)param_0->unk0)->unk28_12 || !func_800F6C5C(local_0)) return 0;
    if (!func_800DA298(0x67F)) {
        _subaddiedialog_entrypoint_11(param_0->unk0, 0x10BA, 0xE, 0, 0x22);
        func_80101FDC(param_0, 7);
        func_800DA544(0x67F);
        return 0;
    }
    if (func_80016B30(0, 1) != 1) return 0;
    if (func_800F6B40(local_0)) return 0;
    if (!func_800F4BB8(local_0, -1, 0)) return 0;
    if (func_800F5410(local_0) != 1) {
        _subaddiedialog_entrypoint_11(param_0->unk0, 0x10B9, 0xF, 0, 0x22);
        func_80101FDC(param_0, 7);
        return 0;
    }
    return 1;
}

void func_80800D14_chcablecar(Actor *param_0, s32 param_1)
{
    Actor *local_1;
    s32 local_0;

    if (param_0->unk3C) {
        local_0 = func_800F54E4();
        local_1 = func_80106790(param_0->unk3C);
        local_1->rotation[0] = param_0->rotation[0];
        func_800EE7F8(local_1->position, param_0->position);
        func_80103014(local_1);
        _subaddieDll_entrypoint_4(local_1, *(u16 *)((u8 *)param_0 + 0x7C));
        if (func_800F6C88(local_0) && func_800F4F34(local_0, local_1->position, 0.0f, 80.0f) && param_1) {
            func_800F76B0(local_0, 0xA, local_1->unk0);
        }
    }
}

void func_80800DC8_chcablecar(param_0) Actor *param_0;
{
    u8 *local_0;

    local_0 = func_801084B0(0x33F, &param_0);
    func_80102FDC(local_0, *(s32 *)((u8 *)param_0 + 0x38));
    _subaddieDll_entrypoint_4(local_0, *(u16 *)((u8 *)param_0 + 0x7C));
    *(f32 *)(local_0 + 0x44) = *(f32 *)((u8 *)param_0 + 0x44);
    *(s32 *)((u8 *)param_0 + 0x3C) = *(s32 *)(local_0 + 0);
}

s32 func_80800E30_chcablecar(Actor *this){
    _chswitch_entrypoint_7(this, 0xD4);
    _chswitch_entrypoint_9(this);
}
