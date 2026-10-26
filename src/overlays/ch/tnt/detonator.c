#include "common.h"

extern void *D_808006A8_chtntdetonator;
extern void _subaddiefade_entrypoint_14(void *);
extern void func_80102FDC(void *, f32);
extern void func_8010A63C(void *);
extern Actor *func_80106790(Unk80132ED0 *);
extern f32 func_800D8FF8(void);
extern u8 D_808006F0_chtntdetonator[];
extern void func_800E1610(s32, f32, f32, f32 *);
extern void func_80018820(s32, f32, f32);
extern void func_800BBCB8(s32, s32, s32, s32, void *);
extern u8 D_80800704_chtntdetonator[];
extern int D_80800754_chtntdetonator;
extern s16 D_80800790_chtntdetonator[];
extern Actor *_subaddiefind_entrypoint_2(s32, s32);
extern void _capod_entrypoint_13(Unk80132ED0 *, Unk80132ED0 *, s32, s32);
extern void func_80102424(Actor *, s32);
extern void _subaddieDll_entrypoint_4(Actor *, s32);
extern s32 func_800EEEA8(f32 *);
extern void func_80101010(f32 *, f32 *);
typedef struct { u8 pad[0x5F]; u8 f5F; u8 pad60[0x12]; u16 f72:6; u16 rest:10; } TntS;
extern s32 D_80800798_chtntdetonator;
extern void _subaddieaudioloop_entrypoint_4();
extern void *func_800D674C(s32);
extern void func_800EFA4C(f32 *, f32, f32, f32);
extern f32 func_800EFC7C(f32 *, f32 *);
void func_808002D8_chtntdetonator();
void func_80800380_chtntdetonator();
void func_808003C0_chtntdetonator();
void func_80800588_chtntdetonator();
void func_8080021C_chtntdetonator();

int chtntdetonator_entrypoint_0()
{
  return &D_808006A8_chtntdetonator;
}

int func_8080000C_chtntdetonator(Actor *param_0)
{
  f32 local_0;
  f32 *new_var;
  ;
  func_80102FDC(param_0, (*(new_var = (f32 *) (((u8 *) param_0) + 0x38))) / 2.0f);
  _subaddiefade_entrypoint_14(param_0);
  func_8010A63C(param_0);
}

void func_80800054_chtntdetonator(Actor *param_0)
{
    Actor *local_0;

    func_80800588_chtntdetonator(param_0);
    switch (param_0->unk70_10) {
        case 1:
            func_8080021C_chtntdetonator(param_0);
            break;
        case 2:
            param_0->unk50 += func_800D8FF8() * 40.0f;
            if (param_0->unk50 >= 14.0f) {
                param_0->unk50 = 0.0f;
            }
            if (func_80101DDC(param_0)) {
                func_808002D8_chtntdetonator(param_0);
                local_0 = param_0->unk3C ? func_80106790(param_0->unk3C) : NULL;
                if (local_0 != NULL) {
                    func_8010108C(local_0, 5, 0);
                }
                func_800FFAB0(param_0);
            }
            break;
    }
}

void func_80800148_chtntdetonator(Actor *param_0, s32 param_1)
{
    f32 local_0[3];
    void *local_1;

    func_80101870(param_0);
    if (param_0->unk7C_12) {
        func_800DBEFC(func_80104130(), 4, param_0->actorData);
        if (param_0->unk70_10 == 2) {
            local_1 = func_800D674C(0x9C6);
            func_800EFA4C(local_0, 0.4f, 0.4f, 0.4f);
            func_800E2588(1);
            func_800E24D8(1);
            func_800E2AA4(param_1, local_1, (s32)param_0->unk50, 0, param_0->actorData, local_0);
        }
    }
}

void func_8080021C_chtntdetonator(param_0) Actor *param_0;
{
    f32 local_0[3];
    if (func_8010D278() == 15) {
        if (!func_800EEEA8((f32 *)param_0->actorData)) {
            func_8010D254(local_0);
            if (func_800EFC7C((f32 *)param_0->actorData, local_0) < 4900.0f) {
                if (local_0[1] < *(f32 *)&param_0->actorData[1] + 140.0f && *(f32 *)&param_0->actorData[1] + -50.0f < local_0[1]) func_800904F4(0x42, param_0->unk0);
            }
        }
    }
}

void func_808002D8_chtntdetonator(param_0) Actor *param_0;
{
    f32 local_0[3];
    func_800EE7F8(local_0, param_0->position);
    local_0[1] += 270.0f;
    func_800BBCB8(local_0, 0, 0x3FC00000, 1, _fxgenlist_entrypoint_2());
    func_808003C0_chtntdetonator(param_0);
    func_80800380_chtntdetonator(param_0);
    func_800C4AF0(param_0->position, D_808006F0_chtntdetonator);
    func_800E1610(0, 30.0f, 0.9f, param_0->position);
    func_80018820(0, 3.0f, 0.25f);
}

void func_80800380_chtntdetonator(param_0) s32 param_0;
{
  s32 *new_var2;
  int new_var;
  new_var = 4;
  new_var2 = &param_0;
  func_800BBCB8(param_0 + new_var, 0, *((s32 *) ((*new_var2) + 0x38)), 0xC, D_80800704_chtntdetonator);
}

void func_808003C0_chtntdetonator(param_0) u8 *param_0;
{
    func_800BBCB8(param_0 + 4, 0, *(s32 *)(param_0 + 0x38), 0xF, &D_80800754_chtntdetonator);
}

s32 func_80800400_chtntdetonator(Actor *param_0, s32 param_1, s32 param_2)
{
    Actor *local_0;
    s16 local_1;
    Actor *local_3;
    Unk80132ED0 *local_2;
    s32 local_7;

    switch (param_1) {
    case 5:
        if (param_0->unk3C) {
            local_0 = func_80106790(param_0->unk3C);
        } else {
            local_0 = NULL;
        }
        local_1 = -1;
        switch ((local_0->unk6C_9)) {
        case 0x145:
            local_7 = local_0->unk74_7 - 0x32;
            local_1 = D_80800790_chtntdetonator[local_7];
            break;
        case 0x14B:
            local_1 = 0;
            break;
        case 0x14A:
            local_1 = 0x41;
            break;
        }
        if (local_1 != -1) {
            local_2 = NULL;
            if ((local_0->unk6C_9) == 0x145 && (local_7 = local_0->unk74_7 - 0x32) == 2) {
                local_3 = _subaddiefind_entrypoint_2(0x2A3, 0);
                if (local_3) {
                    local_2 = local_3->unk0;
                }
            }
            _capod_entrypoint_13(param_0->unk0, local_2, local_1, 0x10);
        }
        func_80102424(param_0, 2);
        _subaddieDll_entrypoint_4(param_0, 1);
        break;
    case 6:
        func_80101010(func_800EEEA8((f32 *)param_0->actorData) ? param_0->position : (f32 *)param_0->actorData, (f32 *)param_0->actorData);
        break;
    default:
        return 0;
    }
    return 1;
}

void func_80800588_chtntdetonator(param_0) TntS *param_0; {
    s32 local_0 = param_0->f72 == 2;
    if (local_0 || (!local_0 && param_0->f5F)) {
        _subaddieaudioloop_entrypoint_4(param_0, (u8 *)param_0 + 0x18, local_0, &D_80800798_chtntdetonator);
    }
}

s32 chtntdetonator_entrypoint_1(Actor *param_0, s32 param_1)
{
  Actor *local_0;
  s32 local_1;
  if (func_800DA298(param_1) != 0)
  {
    local_1 = _subaddiefind_entrypoint_7(param_0, 0x149, 0x320);
    if (local_1 != -1)
    {
      func_800FFA88(param_0->unk3C);
    }
    func_800FFAB0(param_0);
    return 0;
  }
  if (_subaddiefind_entrypoint_7(param_0, 0x149, 0x320) != 0)
  {
    local_0 = func_80106790(param_0->unk3C);
  }
  else
  {
    local_0 = NULL;
  }
  if (local_0 != NULL)
  {
    local_0->unk3C = param_0->unk0;
  }
  return 1;
}
