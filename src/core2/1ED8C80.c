#include "core2/1ED8C80.h"

extern s32 D_80135A50;
typedef struct { u8 pad0[0x28]; void (*unk28)(void *); } O_FF3EC;
typedef struct { u8 pad0[0x64]; u32 f0 : 5; u32 flag : 1; u32 f6 : 26; } S_FF3EC;
extern int D_80127194;
extern void func_800EBFF4(s32);
typedef struct { u8 pad[0x24]; u32 pad24:16, local_0:9, pad26:7; u32 local_1:9, local_2:9, pad28:14; } MarkerFF62C;
typedef struct ActorFF62C { MarkerFF62C *local_0; u8 pad4[0x40]; f32 local_1[3]; u8 pad50[0x14]; u32 pad64:14, local_2:1, pad65:17; u8 pad68[0xC]; u32 pad74:4, local_3:1, pad75:21, local_4:1, local_5:1, pad77:4; u32 pad78:14, local_6:2, pad7a:12, local_7:1, pad7b:3; u8 pad7c[0x10]; s16 local_8, local_9, local_10, pad92; u32 pad94:2, local_11:10, pad95:20; } ActorFF62C;
typedef struct { u8 pad[0xC]; void (*local_0)(ActorFF62C *); void (*local_1)(ActorFF62C *); } DataFF62C;
extern s32 func_800BEC1C(void);
extern s32 func_800DB9B0(void);
extern void func_8010D1E8(void);
extern void func_8010DF3C(void);
extern void func_800E3980(f32 *);
extern void func_8010D254(f32 *);
extern ActorFF62C *func_801067C4(s32 *);
extern ActorFF62C *func_8010682C(s32 *);
extern void func_801061D8(ActorFF62C *);
extern void _subaddiefade_entrypoint_7(ActorFF62C *);
extern void func_80106F70(ActorFF62C *);
extern void func_80104780(ActorFF62C *);
extern void _chbounce_entrypoint_8(ActorFF62C *);
extern void func_80103014(ActorFF62C *);
extern void _subaddiezone_entrypoint_0(ActorFF62C *);
extern void func_80103040(ActorFF62C *);
extern void *func_80104248(ActorFF62C *);
extern void func_8008ADE4(void *);
extern f32 func_800136E4(f32);
typedef struct { u8 local_0[0x40]; Unk80132ED0 *local_1; u8 local_2[0x20]; u32 local_3:14; u32 local_4:1; u32 local_5:17; u32 local_6; u32 local_7:11; u32 local_8:12; u32 local_9:9; u32 local_10; u32 local_11:7; u32 local_12:1; u32 local_13:24; u32 local_14:29; u32 local_15:1; u32 local_16:2; } local_type_800FFAB0;
typedef struct { u8 pad0[0x70]; u8 pad70:7; u8 unk70_0:1; u8 unk71_7:1; u8 pad71:7; u8 pad72[0xA]; u32 pad7C_0:19; u32 unk7C_19:1; u32 pad7C_20:12; } S800FFC90;
extern u8 D_80124390[];
extern void *D_80124394;
extern void *func_801068A8(void **);
extern void **func_80106920(void **);
extern int func_800DC060(int);
extern void func_80106630(void);
extern void func_801041C8(void);
extern void func_801043A0(void);
extern void func_8010545C(void);
extern void func_80105CD0(void);
extern void func_80106A60(void);
extern void func_80106E50(void);
extern void func_80107C10(void);
typedef struct { u8 pad[0x82]; s16 local_0[1]; } ActorFFECC;
extern s32 func_8001B7B8();
extern u32 *func_8001B710();
extern s16 func_8001B668(s32, s32);
extern void func_8001B754();
extern void *func_8001B798(s16);
typedef struct {u32 local_0:10; u32 local_1:1; u32 local_2:21;} local_flags_a;
typedef struct {u32 local_0:28; u32 local_1:1; u32 local_2:3;} local_flags_b;
typedef struct {u32 local_0:14; u32 local_1:1; u32 local_2:17;} local_flags_c;
typedef struct {u8 local_0:1; u8 local_1:1; u8 local_2:6;} local_flags_d;
typedef struct {u8 local_0:2; u8 local_1:1; u8 local_2:5;} local_flags_e;
typedef struct {u8 local_0[0x34]; void (*local_1)(Actor *);} local_type_80100120;
extern s32 func_80102F74(Actor *, u32);
extern void func_8010381C(Actor *);
typedef struct { u8 pad0[0x7C]; u32 val : 16; u32 f1 : 1; u32 flag : 1; u32 f3 : 14; } S_100230;
extern f32 func_800EEB40(void *, void *);
extern void func_800819B4(s32 *);
extern s32 func_80081D34(s32 *);
extern void _suautobaddies_entrypoint_1(void);
extern s32 func_800F54E4(void);
extern void func_800F5A00(s32, s32 *);
typedef struct { u8 pad0[0x10]; void *marker; u8 pad1[0x50]; u32 unused0:14; u32 deleted:1; u32 unused1:17; u8 pad2[0x10]; u32 unused2:26; u32 release:1; u32 unused3:5; u32 radius:16; u32 initialized:1; u32 active:1; u32 flag0:1; u32 flag1:1; u32 unused4:12; } LocalActor;
extern s32 func_800EFFB4(void *, f32, f32 *);
extern void func_8010108C();
void func_80100120();
DataFF62C * func_80100368();
s32 func_8010038C();

int func_800FF390()
{
  D_80135A50 = 0;
  func_801065E0();
  func_80104170();
  func_80104350();
  func_80105410();
  func_80105C20();
  func_80106A20();
  func_80106DF0();
  func_80107BB0();
}

void func_800FF3EC(param_0) S_FF3EC * param_0; {
    O_FF3EC *o;
    if (param_0->flag) {
        return;
    }
    o = func_80100368(param_0);
    if (o->unk28 != 0) {
        o->unk28(param_0);
    }
    param_0->flag = 1;
}

void func_800FF44C(void) {
    s32 sp24;
    s32 var_a0;

    func_80101238(0x93, 0);
    var_a0 = func_801067C4(&sp24);
    while (var_a0 != 0) {
        func_800FF3EC(var_a0);
        var_a0 = func_8010682C(&sp24);
    }
}

int func_800FF4A4(Actor *param_0)
{
  u32 *local_0;

  local_0 = *(u32 **)((u8 *)param_0 + 0x0);
  func_8010381C(param_0);
  func_80103938(param_0);
  if (*(s32 *)((u8 *)param_0 + 0x7C) & 0xFFF) {
    func_800D8808((*(u32 *)((u8 *)func_80105494(param_0) + 0x24) << 23) >> 29);
    func_80105634(param_0);
  }
  *(u16 *)((u8 *)local_0 + 0x24) &= 0x3F;
  func_80104328(param_0);
  _subaddieaudioloop_entrypoint_2(param_0);
  func_80104504(param_0);
  func_80106EE0(param_0);
  {
    s32 local_1;

    for (local_1 = 0; local_1 < 3; local_1++) {
      func_80100074(param_0, local_1, 0);
    }
  }
}

void func_800FF564(void) {
    s32 sp2C;
    s32 *var_s0;

    func_80101238(0x93, 0);
    for (var_s0 = func_801067C4(&sp2C); var_s0 != NULL; var_s0 = func_8010682C(&sp2C)) {
        func_800FF3EC(var_s0);
        func_800FF4A4(var_s0);
        if (*var_s0 != 0) {
            func_800EBFF4(*var_s0);
        }
        *var_s0 = 0;
    }
    D_80135A50 = 0;
    D_80127194 = 0;
    func_801041A0();
    func_80104378();
    func_80105438();
    func_80105C48();
    func_80106608();
    func_80106A28();
    func_80106E18();
    func_8010DF98();
}

void func_800FF62C(void)
{
    s32 local_7, local_8;
    s32 local_0;
    f32 local_1[3];
    s32 local_2;
    MarkerFF62C *local_3;
    DataFF62C *local_4;
    ActorFF62C *local_5;
    local_2 = func_800BEC1C();
    if (local_2) local_7 = 1;
    else local_7 = 0;
    func_8010D1E8();
    if (func_800DB9B0()) func_800E3980(local_1);
    else func_8010D254(local_1);
    for (local_5 = func_801067C4(&local_0); local_5 != 0; local_5 = func_8010682C(&local_0)) {
        local_3 = local_5->local_0;
        if (local_5->local_2) continue;
        {
            if (local_5->local_5) {
                if (func_8010038C(local_5, local_1)) func_80100368(local_5)->local_1(local_5);
            } else {
                func_80100120((Actor *)local_5);
                if (func_8010038C(local_5, local_1)) {
                    local_4 = func_80100368(local_5);
                    if (local_4->local_0) local_4->local_0(local_5);
                }
            }
            if (local_5->local_8 && local_5->local_3) func_8008ADE4(func_80104248(local_5));
            if (local_5->local_10) func_801061D8(local_5);
            if (local_5->local_6) _subaddiefade_entrypoint_7(local_5);
            if (local_5->local_11) func_80106F70(local_5);
            if (local_5->local_9) func_80104780(local_5);
            if (local_5->local_7) {
                _chbounce_entrypoint_8(local_5);
                func_80103014(local_5);
                if (local_7) _subaddiezone_entrypoint_0(local_5);
            } else if (!local_5->local_4) {
                func_80103014(local_5);
                if (local_7) _subaddiezone_entrypoint_0(local_5);
            } else {
                local_3->local_1 = func_800136E4(local_5->local_1[1]);
                local_3->local_0 = func_800136E4(local_5->local_1[0]);
                local_3->local_2 = func_800136E4(local_5->local_1[2]);
            }
            func_80103040(local_5);
        }
    }
    func_8010DF3C();
}

int func_800FFA3C(s32 param_0[3])
{
  s32 local_0;
  if (1)
  {
    local_0 = param_0[0];
  }
  func_800FF3EC();
  func_800FF4A4(param_0);
  func_801066C0(((u32) (*((u16 *) (local_0 + 0x1A)))) >> 5);
  func_800EBFF4(local_0);
}

void func_800FFA88(Unk80132ED0* a0)
{
    func_800FFAB0(func_80106790(a0));
}

void func_800FFAB0(Actor *param_0) {
    local_type_800FFAB0 *local_0;
    ((local_type_800FFAB0 *)param_0)->local_4 = 1;
    D_80135A50++;
    if (((local_type_800FFAB0 *)param_0)->local_1 && ((local_type_800FFAB0 *)param_0)->local_8 != 0x243) {
        local_0 = (local_type_800FFAB0 *)func_80106790(((local_type_800FFAB0 *)param_0)->local_1);
        local_0->local_4 = 1;
        ((local_type_800FFAB0 *)param_0)->local_1 = 0;
        local_0->local_1 = 0;
        D_80135A50++;
    }
    ((local_type_800FFAB0 *)param_0)->local_15 = 0;
    ((local_type_800FFAB0 *)param_0)->local_12 = ((local_type_800FFAB0 *)param_0)->local_15;
}

void func_800FFB74()
{
  typedef struct {
    u32 pad_0[0x19];
    u32 pad_64_18 : 14;
    u32 local_17 : 1;
    u32 pad_64_0 : 17;
  } Struct800FFB74;
  s32 local_var;
  u8 *var_v0;
  if (D_80135A50 > 0)
  {
    var_v0 = func_801067C4((&local_var) - 1);
    if (var_v0 != 0)
    {
      do
      {
        if (((Struct800FFB74 *)var_v0)->local_17 != 0)
        {
          func_800FFA3C(var_v0);
        }
        var_v0 = func_8010682C((&local_var) - 1);
      }
      while (var_v0 != 0);
    }
    D_80135A50 = 0;
  }
}

void func_800FFBE4(void) {
}

void func_800FFC3C();

void func_800FFBEC()
{
    func_800FFC3C();
    func_8010DEFC();
}

void func_800FFC14()
{
    func_800FFC3C();
    func_8010DEFC();
}

void func_800FFC3C()
{
    void *local_1;
    s32 local_0;
    local_1 = func_801067C4(&local_0);
    while (local_1 != 0)
    {
        ((u8 *)local_1)[0x7E] &= 0xFFEF;
        local_1 = func_8010682C(&local_0);
    }
}

void func_800FFC90(void)
{
  S800FFC90 *local_2;
  s32 local_0;
  local_2 = func_801067C4(&local_0);
  if (local_2)
  {
    do
    {
      if (local_2->unk7C_19 && local_2->unk70_0)
      {
        local_2->unk71_7 ^= 1;
      }
      local_2 = func_8010682C(&local_0);
    }
    while (local_2 != 0);
  }
}

void func_800FFD10(s32 param_0)
{
  typedef struct {
    u32 pad_0[0x1C];
    u32 pad_70_4 : 28;
    u32 local_3 : 1;
    u32 pad_70_0 : 3;
  } Struct800FFD10;
  s32 var_s1;
  u8 *var_s0;
  u8 *var_v0;
  if (param_0 == 1)
  {
    var_s1 = 0xA;
  }
  else
  {
    var_s1 = func_80106730();
  }
  var_v0 = func_801068A8(&D_80124390);
  var_s0 = var_v0;
  if ((var_v0 != 0) && (var_s1 > 0))
  {
    loop_5:
    if (((Struct800FFD10 *)var_v0)->local_3 != 0)
    {
      if (func_80103AC0(var_s0) == 0)
      {
        func_8010381C(var_s0);
      }
    }

    var_v0 = func_80106920(&D_80124390);
    var_s0 = var_v0;
    var_s1 -= 1;
    if ((var_v0 != 0) && (var_s1 > 0))
    {
 goto loop_5; } }
}

void func_800FFDBC()
{
  s32 local_4;
  s32 local_0;
  local_4 = func_801067C4(&local_0);
  while (local_4 != 0)
  {
    func_8010381C(local_4);
    local_4 = func_8010682C(&local_0);
  }
}

void func_800FFE08()
{
  void **local_0;
  void *local_1;
  int local_2;
  int local_3;
  local_3 = 0;
  local_0 = func_801068A8(&D_80124394);
  if (local_0 != 0)
  {
    do
    {
      local_1 = *local_0;
      local_2 = *((int *) (((char *) local_1) + 4));
      if (local_2 != 0)
      {
        *((int *) (((char *) local_1) + 4)) = func_800DC060(local_2);
      }
      if (!local_1)
      {
      }
      local_0 = func_80106920(&D_80124394);
      local_3 += 1;
    }
    while ((local_0 != 0) && (local_3 != 8));
  }
  func_80106630();
  func_801041C8();
  func_801043A0();
  func_8010545C();
  func_80105CD0();
  func_80106A60();
  func_80106E50();
  func_80107C10();
}

u32 *func_800FFECC(ActorFFECC *param_0, s32 param_1, s32 param_2) {
    u32 *local_1;
    s32 local_2;
    s32 local_3, local_4;
    s32 local_0;
    if (param_2) {
        local_2 = (param_2 + 3) & 0x7FFFFFFC;
        if (param_0->local_0[param_1]) {
            local_0 = func_8001B7B8(param_0->local_0[param_1]);
            local_1 = func_8001B710(param_0->local_0[param_1], local_2);
            if (local_0 < local_2) {
                for (local_3 = (local_2 >> 2) - 1; local_3 >= (local_0 >> 2); local_3--) {
                    local_1[local_3] = 0;
                }
            }
        } else {
            param_0->local_0[param_1] = func_8001B668(4, local_2);
            local_1 = func_8001B798(param_0->local_0[param_1]);
            for (local_3 = (local_2 >> 2) - 1; local_3 >= 0; local_3--) {
                local_1[local_3] = 0;
            }
        }
    } else if (param_0->local_0[param_1]) {
        func_8001B754(param_0->local_0[param_1]);
        param_0->local_0[param_1] = 0;
    }
    if (param_0->local_0[param_1]) return func_8001B798(param_0->local_0[param_1]);
    return 0;
}

u32* func_80100074(Actor* a0, u32 a1, u32 a2)
{
    return func_800FFECC(a0,a1,a2);
}

void *func_80100094(Actor *param_0, u32 param_1) {
    void *rv = 0;
    s16 v = *(s16 *)((u8 *)param_0 + 0x82 + param_1 * 2);
    if (v != 0) { return func_8001B798(v); }
    return rv;
}

s32 func_801000D8(Actor *param_0, s32 param_1, s32 param_2)
{
  if (!func_80100094(param_0, param_1))
  {
    func_80100074(param_0, param_1, param_2);
  }
  return func_80100094(param_0, param_1);
}

void func_80100120(param_0) Actor * param_0; {
    void (*local_0)(Actor *);
    if (!((local_flags_a *)((u8 *)param_0 + 0x74))->local_1) {
        local_0 = ((local_type_80100120 *) func_80100368(param_0))->local_1;
        if (local_0) {
            if (((local_flags_b *)((u8 *)param_0 + 0x70))->local_1 && func_80102F74(param_0, 0x80080000)) func_8010381C(param_0);
            local_0(param_0);
            if (((local_flags_c *)((u8 *)param_0 + 0x64))->local_1) {
                ((local_flags_d *)((u8 *)param_0 + 0x7E))->local_0 = 1;
                ((local_flags_d *)((u8 *)param_0 + 0x7E))->local_1 = 0;
            }
        }
        ((local_flags_e *)((u8 *)param_0 + 0x75))->local_1 = 1;
    }
}

void func_801001D8()
{
  s32 local_0;
  s32 local_1;
  func_8010D1E8();
  local_1 = func_801067C4(&local_0);
  while (local_1 != 0) {
    func_80100120(local_1);
    local_1 = func_8010682C(&local_0);
  }
  func_800FFB74();
}

s32 func_80100230(S_100230 *param_0, void *param_1) {
    if (!param_0->flag) { return 0; }
    if (param_0->val == 0) { return 1; }
    return (f32)(s32)(param_0->val * param_0->val) < func_800EEB40(param_1, (u8 *)param_0 + 4);
}

void func_801002C0()
{
  s32 local_0;
  s32 local_3;
  s32 local_4[3];
  func_801001D8();
  _suautobaddies_entrypoint_1();
  func_800FFB74();
  func_800F5A00(func_800F54E4(), local_4);
  local_0 = func_801067C4(&local_3 + 1);
  while (local_0 != 0)
  {
    if (func_80100230(local_0, &local_4) && func_80081D34(*((s32 **) (local_0 + 0x10))))
    {
      func_800819B4(*((s32 **) (local_0 + 0x10)));
    }
    local_0 = func_8010682C(&local_3 + 1);
  }

}

DataFF62C * func_80100368(arg0) void * arg0; {
    (*(s32 (**)())((u8 *)arg0 + 0x10))();
}

s32 func_8010038C(param_0, param_1) LocalActor * param_0; f32 * param_1;
{
    if (!param_0->initialized) {
        param_0->initialized = 1;
        func_8010108C(param_0, 0x95, 0);
        if (param_0->deleted) return 0;
        if (param_0->release) func_80081D34(param_0->marker);
    }
    if (!param_0->active) return 0;
    if (!param_0->radius) return 1;
    if (param_0->flag0 && param_0->flag1) return 1;
    return func_800EFFB4((u8 *)param_0 + 4, (f32)(s32)param_0->radius, param_1);
}
