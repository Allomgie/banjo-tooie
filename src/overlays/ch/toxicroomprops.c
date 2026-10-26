#include "common.h"

#define SPEED (*(f32 *)&this->actorData[3])
extern int D_808009E8_chtoxicroomprops;
extern int D_80800A30_chtoxicroomprops;
extern void func_80101FDC();
extern struct chtoxicroomprops D_80800A84_chtoxicroomprops;
extern Vec3f D_808009A0_chtoxicroomprops;
extern u8 D_808009AC_chtoxicroomprops[];
extern Actor *_subaddiefind_entrypoint_2(s32, s32);
extern f32 func_800DC0C0(void);
extern s32 func_800BABB8(s32, f32 *, f32 *, f32, void *);
extern f32 func_800F1214(f32, f32, f32);
extern u8 D_808009E0_chtoxicroomprops[];
extern f32 func_800D8FF8(void);
extern f32 func_800136E4(f32);
extern f32 func_800F13C4(f32, f32);
extern f32 func_800F10B4(f32, f32, f32, f32, f32);
extern f32 func_800DC178(f32, f32);
extern void func_800C4140(s32, f32 *, s32);
extern void _subaddieaudioloop_entrypoint_0(Actor *, f32);
extern void _subaddieaudioloop_entrypoint_1(Actor *, s32);
extern void _subaddieaudioloop_entrypoint_4(Actor *, f32 *, s32, void *);
extern u8 D_80800A78_chtoxicroomprops[];
extern f32 func_80103EF4(Actor *);
extern s32 func_800E1610(s32, f32, f32, f32 *);
extern void func_800E148C(s32, f32, f32);
void func_80800390_chtoxicroomprops(Actor *this, f32 delta);

void func_80800000_chtoxicroomprops(Actor *param_0)
{
    Actor *local_0;
    Vec3f local_1;
    s32 local_2;
    s32 local_4;
    s32 local_3;

    switch (param_0->unk70_10) {
    case 1:
        func_80103110(param_0, 0);
        break;
    case 2:
        local_0 = _subaddiefind_entrypoint_2(0x178, 0);
        if (!param_0->unk74_30 && param_0->rotation[1] == 193.0f) {
            param_0->unk74_30 = 1;
            _chmrtannoy_entrypoint_0();
            _subaddiedialog_entrypoint_11(param_0->unk0, 0x133D, 7, param_0->position, 0xA3);
        }
        if (func_800DC0C0() < 0.1f && _subaddiefade_entrypoint_0(local_0) >= 0x51) {
            local_1 = D_808009A0_chtoxicroomprops;
            local_2 = func_800B53A4(1);
            func_800BABB8(local_2, local_1.f, NULL, 10.0f, D_808009AC_chtoxicroomprops);
            if (param_0->rotation[1] == 193.0f) {
                local_3 = (s32)func_800F1214(((f32 *)param_0->actorData)[3], 0.0f, 450.0f) * 10;
            } else {
                local_3 = -((s32)func_800F1214(((f32 *)param_0->actorData)[3], 0.0f, 450.0f) * 10);
            }
            if (param_0->rotation[1] == 193.0f) {
                local_4 = (s32)func_800F1214(((f32 *)param_0->actorData)[3], 0.0f, 450.0f) * 10;
            } else {
                local_4 = -((s32)func_800F1214(((f32 *)param_0->actorData)[3], 0.0f, 450.0f) * 10);
            }
            func_800BA450(local_2, 0, 0, (s16)local_3, 0, 0, local_4);
            func_800BA22C(local_2, 1);
        }
        if (!func_800DA298(0x1BC) && param_0->rotation[1] == 193.0f) {
            func_800DA544(0x1BC);
            _capod_entrypoint_13(param_0->unk0, 0, 0, 0x800);
        }
        func_80800390_chtoxicroomprops(param_0, 2.0f);
        if (((f32 *)param_0->actorData)[3] >= 450.0f
            && _subaddiefade_entrypoint_0(local_0) != 0
            && param_0->rotation[1] == 193.0f) {
            _subaddiefade_entrypoint_6(local_0, -1);
        }
        break;
    }
}

int func_8080030C_chtoxicroomprops(Actor *param_0, s32 param_1, s32 param_2)
{
  switch (param_1)
  {
    case 0xB:
      func_800DA524(0xA04);
      func_800DA524(0x1BD);
      _subaddieaudioloop_entrypoint_2(param_0);
      _glcutDll_entrypoint_17();
      return 3;

    case 0x49:
      if (param_2 == 0x41)
      {
        func_80101FDC(param_0, 2);
        return 1;
      }
      return 0;

    default:
      return 0;
  }
}

void func_80800390_chtoxicroomprops(Actor *this, f32 delta)
{

    SPEED += delta;
    if (450.0f < SPEED) {
        SPEED = 450.0f;
    }
    this->unk54 = this->rotation[2];
    this->rotation[2] = func_800136E4(this->rotation[2] + SPEED * func_800D8FF8());
    if (45.0f < SPEED) {
        if (func_800F13C4(this->unk54, 90.0f) > func_800F13C4(this->rotation[2], 90.0f)) {
            func_800C4140((((((s32)((s32)func_800F10B4(SPEED, 45.0f, 450.0f, 18000.0f, 24000.0f) * 0.5f)) >> 5) & 0x3FF) << 11) + ((u16)(u32)((func_800F10B4(SPEED, 45.0f, 450.0f, 0.3f, 0.6f) + func_800DC178(-0.02f, 0.02f)) * 1023.0f) << 21) + 0x3FF, this->position, 0xBB800C8);
        }
        _subaddieaudioloop_entrypoint_0(this, func_800F10B4(SPEED, 45.0f, 450.0f, 0.2f, 0.5f));
        _subaddieaudioloop_entrypoint_1(this, func_800F10B4(SPEED, 45.0f, 450.0f, 18000.0f, 24000.0f));
        _subaddieaudioloop_entrypoint_4(this, this->position, 1, D_808009E0_chtoxicroomprops);
    }
}

int chtoxicroomprops_entrypoint_0()
{
    return (int)&D_808009E8_chtoxicroomprops;
}

void func_80800650_chtoxicroomprops(void *param_0) {
    *(float *)((char *)param_0 + 0x24) = 0.0f;
    *(float *)((char *)param_0 + 0x4C) = 0.0f;
    *(float *)((char *)param_0 + 0x54) = 0.0f;
    *(float *)((char *)param_0 + 0x58) = 10.0f;
}

void func_80800670_chtoxicroomprops(u8 *param_0)
{
    if (func_800D90A4(param_0 + 0x58) != 0)
    {
        func_80800390_chtoxicroomprops(param_0, -2.0f);
        if ((*(f32 *)((s8 *)(param_0) + (0x24))) < 45.0f)
        {
            _subaddieaudioloop_entrypoint_2(param_0);
            (*(f32 *)((s8 *)(param_0) + (0x24))) = 0.0f;
            func_800FFA88((*(s32 *)((s8 *)(param_0) + (0))));
        }
    }
    else
    {
        func_80800390_chtoxicroomprops(param_0, 4.0f);
    }
}

void *chtoxicroomprops_entrypoint_1()
{
    return &D_80800A30_chtoxicroomprops;
}

void func_80800700_chtoxicroomprops(u8 *param_0) {
    *(f32 *)(param_0 + 0x30) = *(f32 *)(param_0 + 8);
    if (func_800DA298(0x1BD) == 0) {
        func_80101FDC(param_0, 3);
    } else {
        func_80101FDC(param_0, 1);
    }
}

void func_80800758_chtoxicroomprops(Actor *param_0)
{
  s32 pad0;
    switch (param_0->unk70_10) {
    case 1:
        if (func_800DA298(0xA04) || !func_800DA298(0x1BD)) {
            func_80101FDC(param_0, 2);
            ((f32 *)param_0->actorData)[4] = 8.0f;
        }
        param_0->position[1] = ((f32 *)param_0->actorData)[6];
        return;
    case 2:
        if (func_800D90A4(&param_0->actorData[4])) {
            func_80101FDC(param_0, 3);
        }
        param_0->position[1] = ((f32 *)param_0->actorData)[6] + func_800F10B4(((f32 *)param_0->actorData)[4], 8.0f, 0.0f, 0.0f,
            func_80103EF4(param_0) * 0.9f);
        return;
    case 3:
        if (func_800DA298(0x1BD) && !func_800DA298(0xA04)) {
            func_80101FDC(param_0, 4);
            ((f32 *)param_0->actorData)[4] = 0.5f;
            _subaddieaudioquick_entrypoint_2(param_0, param_0->position, D_80800A78_chtoxicroomprops);
        }
        param_0->position[1] = ((f32 *)param_0->actorData)[6] + func_80103EF4(param_0) * 0.9f;
        return;
    case 4:
        if (func_800D90A4(&param_0->actorData[4])) {
            func_800E148C(func_800E1610(2, 200.0f, 0.85f, param_0->position), 1000.0f, 4000.0f);
            func_80101FDC(param_0, 1);
            _subaddieaudioquick_entrypoint_2(param_0, param_0->position, D_80800A78_chtoxicroomprops);
        }
        param_0->position[1] = ((f32 *)param_0->actorData)[6] + func_800F10B4(((f32 *)param_0->actorData)[4], 0.5f, 0.0f,
            func_80103EF4(param_0) * 0.9f, 0.0f);
        return;
    }
}

struct chtoxicroomprops *chtoxicroomprops_entrypoint_2()
{
  return &D_80800A84_chtoxicroomprops;
}
