#include "common.h"

typedef struct { u8 pad_0[0xB]; u8 pad_B:6, field_B:1, pad_B1:1; } LocalMarker;
typedef struct { LocalMarker *field_0; void *field_4; u8 pad_8[4]; s32 field_C; s16 field_10; u8 pad_12[2]; u16 field_14, field_16; u16 field_18:11, pad_18:5; u8 pad_1A[4]; s16 field_1E[3]; } LocalObject;
typedef struct { LocalObject *field_0; u8 pad_4[0x5C]; s16 field_60, field_62; u8 pad_64[4]; u16 field_68, field_6A; u8 pad_6C[4]; u32 pad_70:28, field_73:1, pad_73:3; u8 field_74:1, pad_74:7; u8 field_75:1, pad_75:7; u8 pad_76[0xA]; u16 field_80; u8 pad_82[6]; s16 field_88, field_8A, field_8C, field_8E, field_90; } LocalActor_80103140;
typedef struct { u8 pad_0[0x12]; u16 field_12, field_14; } LocalModel;
extern s32 func_800D58FC(s32);
extern s16 func_80104328(void *param_0);
typedef struct { LocalObject *field_0; u8 pad_4[0x5C]; s16 field_60, field_62; u8 pad_64[4]; u16 field_68, field_6A; u8 pad_6C[4]; u32 pad_70:28, field_73:1, pad_73:3; u8 field_74:1, pad_74:7; u8 field_75:1, pad_75:7; u8 pad_76[0xA]; u16 field_80; u8 pad_82[6]; s16 field_88, field_8A, field_8C, field_8E, field_90; } LocalActor_80103328;
extern LocalModel *func_800B2840(void *);
extern s32 func_800B2248(LocalModel *);
extern void func_800B2198(LocalModel *, s32 *, s32 *);
extern void func_800B237C(LocalModel *, f32 *, f32 *);
extern void func_800EE940();
extern s32 func_80106790();
extern void func_800DF7F8(s32, f32, f32);
typedef struct { LocalObject *field_0; u8 pad_4[0x5C]; s16 field_60, field_62; u8 pad_64[4]; u16 field_68, field_6A; u8 pad_6C[4]; u32 pad_70:7, field_70:1, pad_71:2, field_71:1, pad_71b:5, field_72:6, pad_72:6, field_73:1, pad_73:3; u8 field_74:1, pad_74:7; u8 field_75:1, pad_75:7; u8 pad_76[5]; u8 field_7B:2, pad_7B:6; u8 pad_7C[4]; u16 field_80; u8 pad_82[6]; s16 field_88, field_8A, field_8C, field_8E, field_90; u8 pad_92[4]; u16 field_96:1, pad_96:15; } LocalActor_80103508;
extern void *func_80100368(void);
extern void *func_800D674C(s32);
extern void _subaddiefade_entrypoint_9(LocalActor_80103508 *, s32 *);
extern s16 func_80100D24(void *, s32, s32, s32, s32, s32 *);
extern void func_800B25D8(void *, LocalModel *, void *);
extern void func_800D6CEC(s32);
extern s32 func_80102FA0(void *, s32);
extern void *func_800DBFF8(void);
extern void func_80105DFC(LocalActor_80103508 *);
extern s16 func_800AE020(void);
extern s16 func_800D88F8(void);
extern void func_80102424(LocalActor_80103508 *, s32);
extern void func_80104460(LocalActor_80103508 *);
extern void func_8010108C(LocalActor_80103508 *, s32, void *);
typedef struct { LocalObject *field_0; u8 pad_4[0x5C]; s16 field_60, field_62; u8 pad_64[4]; u16 field_68, field_6A; u8 pad_6C[4]; u32 pad_70:28, field_73:1, pad_73:3; u8 field_74:1, pad_74:7; u8 field_75:1, pad_75:7; u8 pad_76[0xA]; u16 field_80; u8 pad_82[6]; s16 field_88, field_8A, field_8C, field_8E, field_90; } LocalActor_8010381C;
extern void func_80100E18(s32);
extern void func_800DBFD8(void *);
extern void func_80106138(LocalActor_8010381C *);
extern void func_800ADFE0(s32);
extern void func_800D8954(s16);
extern void func_80104504();
extern s8 D_80127115;
extern u8 _subaddiecustomhits_entrypoint_1[];
typedef struct { u8 pad0[0x60]; s16 unk60; u8 pad62[0xE]; u8 pad70 : 7; u8 flag70 : 1; u8 flag71 : 1; u32 pad71 : 1; u32 flag71_2 : 1; u32 pad71b : 21; } S80103B24;
extern s32 func_80100A74(s32, s32);
typedef struct {u8 local_0[0x70]; u32 local_1:10; u32 local_2:1; u32 local_3:21;} local_type;
extern void func_800EE7F8(void *, void *);
extern void func_800EE88C(s32, s32);
extern void func_800EF04C();
typedef struct { u8 pad0[0x38]; f32 unk38; u8 pad3C[0x2E]; u16 unk6A; } S_103FB8;
void func_80103930();

extern void func_800D62E4();
extern void func_800EE84C(s32, u32 *);
extern void func_800EF334(s32, f32);
void func_80103328();
void func_8010381C();
void func_80103938();
int func_80103964();
int func_801039A4();
s32 func_801039E4();
int func_80103C94();
s32 func_80103D24();
void func_80103D48();
void func_80103D70();

s32 func_80103140(LocalActor_80103140 *param_0, u16 param_1, u16 param_2)
{
    u16 local_3;
    u32 local_0;
    s32 local_1;
    s32 local_2;
    local_3 = param_0->field_0->field_14;
    local_2 = local_3;
    if (local_2 == param_1 && param_2 == param_0->field_0->field_16) return local_3;
    local_0 = param_0->field_73;
    func_8010381C(param_0);
    func_80103938(param_0);
    param_0->field_74 = 0;
    param_0->field_0->field_C = 0;
    param_0->field_68 = 0;
    param_0->field_6A = 0;
    param_0->field_62 = 0;
    param_0->field_0->field_18 = 0;
    if (param_0->field_8C != 0) func_80104328(param_0);
    local_1 = func_800D58FC(param_1);
    param_0->field_0->field_14 = param_1;
    param_0->field_0->field_16 = param_2;
    if (local_1 == 0) param_0->field_0->field_0->field_B = 1;
    else param_0->field_0->field_0->field_B = 0;
    if (local_1 == 0) func_80103328(param_0);
    func_80103930(param_0);
    if (local_0 && !param_0->field_73 && local_1 == 0) {
        func_801039E4(param_0->field_0);
        func_800D62E4(param_0->field_0->field_14);
    }
    return local_2;
}

unsigned int func_801032B0(void *param_0, u16 param_1, u16 param_2)
{
  s32 local_1;
  s32 local_0;
  local_0 = ((s16 *) param_0)[70];
  ((s16 *) param_0)[70] = 0;
  local_1 = func_80103140(param_0, param_1, param_2);
  if (((s16 *) param_0)[70] != 0)
  {
    func_80104328(param_0);
  }
  ((s16 *) param_0)[70] = local_0;
  return local_1;
}

void func_80103328(param_0) LocalActor_80103328 * param_0;
{
    s32 local_0[3];
    s32 local_1[3];
    f32 local_2[3];
    LocalModel *local_3;
    f32 local_4;
    void *local_5;
    if (param_0->field_68 == 0) {
        local_5 = func_80103964(param_0->field_0);
        if (local_5 != 0) {
            func_800D62E4(param_0->field_0->field_14);
            local_3 = func_800B2840(local_5);
            param_0->field_68 = local_3->field_12;
            param_0->field_6A = local_3->field_14;
            param_0->field_62 = func_800B2248(local_3);
            func_800B2198(local_3, local_0, local_1);
            param_0->field_88 = local_0[1];
            param_0->field_8A = local_1[1];
            func_800B237C(local_3, local_2, &local_4);
            func_800EE940(param_0->field_0->field_1E, local_2);
            param_0->field_0->field_18 = local_4;
        }
    }
}

int func_8010347C(s32 param_0)
{
  s32 local_0;
  u16 local_1;
  local_0 = func_80106790();
  func_80103328(local_0);
  local_1 = *((u16 *) (param_0 + 0x14));
  func_800DF7F8(local_1, (f32) (*((u16 *) (local_0 + 0x68))), (f32) (*((u16 *) (local_0 + 0x6A))));
  return 0;
}

void func_80103508(LocalActor_80103508 *param_0)
{
    void *local_0;
    LocalObject *local_1;
    void *local_2;
    void *local_3;
    s32 local_4;
    s32 local_5;
    s32 local_6[3];
    LocalModel *local_8;
    void *local_7;
    if (!param_0->field_73) {
        local_1 = param_0->field_0;
        local_0 = func_80100368();
        local_3 = func_801039A4(local_1);
        if (!local_3) local_3 = func_801039E4(local_1);
        func_80103328(param_0);
        if (local_1->field_16) local_2 = func_800D674C(local_1->field_16);
        else local_2 = 0;
        local_4 = param_0->field_7B ? 1 : 0;
        local_5 = param_0->field_70 ? 2 : (param_0->field_71 ? 1 : 0);
        if ((local_4 || local_5) && !param_0->field_60) {
            if (param_0->field_96) _subaddiefade_entrypoint_9(param_0, local_6);
            param_0->field_60 = func_80100D24(local_3, local_1->field_14, local_5, local_4, local_1->field_16, param_0->field_96 ? local_6 : 0);
        }
        if (local_2 && local_5 >= 2) {
            local_7 = func_80103D24(param_0);
            local_8 = func_800B2840(local_3);
            func_800B25D8(local_7, local_8, local_2);
        }
        if (local_2) {
            local_7 = func_80103C94(param_0);
            local_8 = func_800B2840(local_3);
            func_800B25D8(local_7, local_8, local_2);
            func_800D6CEC(local_1->field_16);
        }
        if (!local_1->field_4 && func_80102FA0(local_0, 0x40)) local_1->field_4 = func_800DBFF8();
        if (!param_0->field_90 && func_80102FA0(local_0, 0x1000)) func_80105DFC(param_0);
        if (!local_1->field_10 && func_80102FA0(local_0, 0x20)) local_1->field_10 = func_800AE020();
        if (!param_0->field_80 && func_80102FA0(local_0, 0x4000)) param_0->field_80 = func_800D88F8();
        if (!param_0->field_8C && param_0->field_75) func_80102424(param_0, param_0->field_72);
        if (!param_0->field_8E && func_80102FA0(local_0, 0x40000)) func_80104460(param_0);
        param_0->field_73 = 1;
        func_8010108C(param_0, 0x29, local_3);
    }
}

void func_8010381C(param_0) LocalActor_8010381C * param_0;
{
    LocalObject *local_0;
    local_0 = param_0->field_0;
    if (param_0->field_73) {
        if (param_0->field_60) {
            func_80100E18(param_0->field_60);
            param_0->field_60 = 0;
        }
        if (local_0->field_4) {
            func_800DBFD8(local_0->field_4);
            local_0->field_4 = 0;
        }
        if (param_0->field_90) func_80106138(param_0);
        if (local_0->field_10) {
            func_800ADFE0(local_0->field_10);
            local_0->field_10 = 0;
        }
        if (param_0->field_80) {
            func_800D8954(param_0->field_80);
            param_0->field_80 = 0;
        }
        if (param_0->field_75 && param_0->field_8C) func_80104328(param_0);
        if (param_0->field_8E) func_80104504(param_0);
        param_0->field_73 = 0;
        func_8010108C(param_0, 0x2A, 0);
    }
}

void func_80103930(s32 arg0) 
{
}
void func_80103938(param_0) u8 * param_0;
{
    if (*(s16 *)(param_0 + 0x8E) != 0)
    {
        func_80104504();
    }
}

int func_80103964(param_0) Actor * param_0;
{
  u16 local_0;
  extern u16 D_801039A4_unk14_1;
  ;
  if (((*((u16 *) (((char *) param_0) + 0x14))) == 0) || ((*((u16 *) (((char *) param_0) + 0x14))) == 0xFFFF))
  {
    return 0;
  }
  else
  {
    return func_800D674C((*((u16 *) (((char *) param_0) + 0x14))) | 0);
  }
}

int func_801039A4(param_0) Actor * param_0;
{
  int local_0;
  extern u16 D_801039A4_unk14_1;
  local_0 = *((u16 *) (((char *) param_0) + 0x14));
  if (((*((u16 *) (((char *) param_0) + 0x14))) == 0) || (local_0 == 0xFFFF))
  {
    return 0;
  }
  else
  {
    return func_800D6B0C((*((u16 *) (((char *) param_0) + 0x14))) | 0);
  }
}

s32 func_801039E4(param_0) Actor * param_0;
{
  typedef struct {
    u32 pad_0[2];
    u32 pad_8_2 : 30;
    u32 local_0 : 1;
    u32 pad_8_0 : 1;
  } Struct801039E4;
  s32 local_0;
  Actor *local_1;
  local_0 = func_80103964();
  if (local_0 == 0)
  {
    return 0;
  }
  local_1 = func_80106790(param_0);
  func_80103D48(local_1);
  func_80103508(local_1);
  if (((((u32) (*((u32 *) (((char *) local_1) + 0x74)))) >> 0x1F) == 0) && ((*((s32 *) (((char *) param_0) + 0xC))) == 0))
  {
    if ((((Struct801039E4 *)param_0->unk0)->local_0 != 0) && (func_800B2824(local_0) != 0))
    {
      _subaddiecustomhits_entrypoint_0(local_1, &_subaddiecustomhits_entrypoint_1);
    }
    local_1->pad74_31 = 1;
  }
  func_80103D70(local_1);
  return local_0;
}

void func_80103AA0()
{
    func_801039A4();
}

int func_80103AC0(void **param_0)
{
  s32 new_var;
  s32 local_0;
  new_var = ((u16 *)param_0[0])[0xA];
  local_0 = new_var;
  func_800D6C34(local_0);
}

int func_80103AE4(Actor *param_0)
{
  u16 local_0;
  extern u16 D_801039A4_unk14_1;
  ;
  if (((*((u16 *) (((char *) param_0) + 0x14))) == 0) || ((*((u16 *) (((char *) param_0) + 0x14))) == 0xFFFF))
  {
    return 0;
  }
  else
  {
    return func_800D674C((*((u16 *) (((char *) param_0) + 0x14))) | 0);
  }
}

s32 func_80103B24(S80103B24 *param_0, s32 param_1, s32 param_2) {
    if (param_2 == 0) {
        return 0;
    }
    if (param_0->flag70 && param_0->unk60 != 0) {
        return func_80100A74(param_0->unk60, param_0->flag71 ^ param_1);
    }
    if (param_0->flag71_2 && param_0->unk60 != 0) {
        return func_80100A74(param_0->unk60, 0);
    }
    return func_800B2840(param_2);
}

int func_80103BBC(s32 *param_0)
{
  s32 local_0;
  local_0 = func_801039A4(*param_0);
  func_80103B24(param_0, 0, local_0 | 0);
}

int func_80103BF0(s32 *param_0, s32 param_1, s32 param_2) {
    if (param_2 == 0) param_2 = func_80103964(param_0[0]);
    if (param_2 == 0) return 0;
    if (*(u8 *)((u8 *)param_0 + 0x70) & 1) {
        return func_80100A74(*(s16 *)((u8 *)param_0 + 0x60), ((u32)*(u8 *)((u8 *)param_0 + 0x71) >> 7) ^ param_1);
    }
    if (((local_type *)param_0)->local_2) return func_80100A74(*(s16 *)((u8 *)param_0 + 0x60), 0);
    return func_800B2840(param_2);
}

int func_80103C94(p0) s32 p0; {
    func_80103BF0(p0, 0, 0);
}

int func_80103CB8(s32 param_0, s32 param_1)
{
  func_80103BF0(param_0, 0 | 0, param_1 | 0);
}

int func_80103CDC(s32 param_0, s32 param_1)
{
  func_80103B24(param_0, 0 | 0, param_1 | 0);
}

void func_80103D00(s32 arg0,s32 arg1)
{
    func_80103B24(arg0,0x1,arg1);
}

s32 func_80103D24(map) s32 map;{
    func_80103BF0(map, 1, 0);
}

void func_80103D48(param_0) void * param_0;
{
  func_800D70F8(*(u16 *)((char *)*(s32 *)param_0 + 0x14), 1);
}

void func_80103D70(param_0) int param_0; {
    func_800D70F8(*(u16 *)(*(int*)param_0 + 0x14), 0);
}

s32 func_80103D98(void *param_0)
{
    s32 local_0;

    if (func_800AE0E8(*(s16 *)((u8 *)param_0 + 0x10)) == 0) {
        return 0;
    }
    local_0 = func_801039A4(param_0);
    if (local_0 == 0) {
        return 0;
    }
    func_800D62E4(*(u16 *)((u8 *)param_0 + 0x14), local_0);
    return func_800B2824(local_0);
}

void func_80103DFC(Actor *param_0, f32 *param_1) {
    if (*(u16 *)(*(u32 *)(u8 *)param_0 + 0x14) == 0xFFFF) {
        func_800EE7F8(param_1, (u8 *)param_0 + 4);
        return;
    }
    func_80103328(param_0);
    func_800EE7F8(param_1, (u8 *)param_0 + 4);
    *((f32 *)(param_1 + 1)) += *((f32 *)((u8 *)param_0 + 0x38)) * ( *((s16 *)((u8 *)param_0 + 0x88)) + ( *((s16 *)((u8 *)param_0 + 0x8A)) - *((s16 *)((u8 *)param_0 + 0x88)) ) * 0.5f );
}

f32 func_80103EAC(u8 *param_0)
{
  f32 local_0;
  u16 local_1;
  int new_var;
 do { func_80103328(); local_1 = *((u16 *) (((s8 *) param_0) + 0x62)); new_var = *((u16 *) (((s8 *) param_0) + 0x62)); local_1 = new_var; local_0 = (f32) local_1; return (*((f32 *) (((s8 *) param_0) + 0x38))) * local_0; } while (0);
}

f32 func_80103EF4(u8 *param_0)
{
  func_80103328();
  return (*((f32 *) (((s8 *) param_0) + 0x38))) * ((f32) ((*((s16 *) (((s8 *) param_0) + 0x8A))) - (*((s16 *) (((s8 *) param_0) + 0x88)))));
}

f32 func_80103F38(u8 *param_0, s32 param_1) {
    func_80103328(param_0);
    if (param_1 != 0) {
        func_800EE88C(param_1, *(s32 *)param_0 + 0x1E);
        func_800EF334(param_1, *(f32 *)(param_0 + 0x38));
        func_800EF04C(param_1, param_0 + 4);
    }
    return *(f32 *)(param_0 + 0x38) * (u32)*(u16 *)(param_0 + 0x68);
}

f32 func_80103FB8(S_103FB8 *param_0) {
    func_80103328(param_0);
    return (f32)(u32)param_0->unk6A * param_0->unk38;
}

int func_80104004(OSTask_t **param_0, s32 param_1, s32 param_2)
{
  OSTask_t **new_var;
  u32 local_1[2];
  s32 pad0;
  u32 local_2[2];
  OSTask_t *new_var2;
  u32 local_0;
  local_0 = func_801039E4(*param_0);
  if (!local_0)
  {
    return 0;
  }
  new_var = &(*param_0);
  func_800D62E4(*((u16 *) (((u8 *) (*new_var)) + 0x14)), local_0);
  new_var2 = func_800B2840(local_0);
  func_800B2198(new_var2, &local_1, &local_2);
  func_800EE84C(param_1, &local_1);
  func_800EE84C(param_2, &local_2);
  func_800EF334(param_1, *((f32 *) (((char *) param_0) + 56)));
  func_800EF334(param_2, *((f32 *) (((char *) param_0) + 56)));
  return 1;
}

void func_801040A8(u8 **param_0) {
    func_800AE080(*(s16 *)((u8 *)*param_0 + 0x10));
}
