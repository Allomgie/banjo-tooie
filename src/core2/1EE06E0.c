#include "common.h"

extern s32 D_80136F00;
extern u8 D_801244F0[];
extern u8 unkA[];
typedef struct { u8 pad_0[0x94]; u16 local_0 : 2; u16 local_1 : 10; u16 local_2 : 4; } local_2;
typedef struct { u8 local_0[0x5C]; u8 local_1[3]; u8 local_2[5]; u32 local_3:1; u32 local_4:1; u32 local_5:5; u32 local_6:1; u32 local_7:7; u32 local_8:1; u32 local_9:16; u32 local_10; u32 local_11; u32 local_12:15; u32 local_13:1; u32 local_14:16; u32 local_15:7; u32 local_16:1; u32 local_17:3; u32 local_18:1; u32 local_19:20; u32 local_20:14; u32 local_21:2; u32 local_22:16; u32 local_23:19; u32 local_24:1; u32 local_25:12; } local_type_80107448;
extern void func_8010A570(local_type_80107448 *);
extern void func_8010A624(local_type_80107448 *);
extern void func_80104580(local_type_80107448 *);
typedef struct { u8 pad_0[0xC]; u32 kind:12, variant:12, pad_18:8; s16 pad_10, rotation; } LocalProp;
typedef struct { u8 pad_0[4]; f32 position[3]; u8 pad_10[0x38]; f32 rotation; u8 pad_4C[0x24]; u32 kind:7, pad_77:9, pad_80:6, variant:6, pad_90:4; } LocalActor_8010754C;
extern void func_800EE88C(f32 *,void *);
extern void func_80103014(LocalActor_8010754C *);
typedef struct { u8 pad0[4]; f32 position[3]; u32 pad10, flags; u8 pad18[0x4C]; u32 flag0:1, flag1:1, unused0:13, flag2:1, unused1:16; u8 pad68[8]; u32 unused2:15, flag3:1, unused3:16; u32 unused4:11, flag4:1, unused5:20; } LocalActor_801075E4;
typedef struct { u8 pad0[0x1C]; f32 value; } LocalDesc;
typedef struct { f32 value; u8 pad4[0x10]; s16 value14; } LocalState;
extern LocalDesc *func_80100368();
extern s32 func_80102FA0(LocalDesc *, u32);
extern f32 D_801244FC[];
typedef struct { u32 local_0 : 7; u32 local_1 : 1; u32 local_2 : 24; } local_type_80107784;
extern s32 _subaddiefade_entrypoint_0(s32);
extern s32 func_800D90A4();
extern s32 func_80102F74(s32, s32);
extern void func_8010A590(s32);
extern void func_8010A63C(s32);
extern s32 _subaddievolume_entrypoint_0(void *,f32 (*)[3],s32,s32,s32 *);
extern s32 func_800B5BE4(s32);
extern void func_800BABB8(s32,f32 *,f32 *,f32,void *);
extern void func_800EF368(f32 *,f32);
extern void func_800EF334(f32 *,f32);
extern u8 D_80124508[];
extern u8 D_80124538[];
extern u8 D_8012762C;
extern f32 D_80136F10;
extern f32 _gspropmarker_entrypoint_3(s32);
int func_80107070();
s32 func_80107320();
int func_801073AC();
s32 func_801073F8();
void func_80107448();
void func_8010754C();
void func_801075E4();
int func_80107750();
s32 func_80107784();
s32 func_80107858();
int func_801078AC();
s32 func_801078DC();
float func_80107A80();

void func_80106DF0()
{
  D_80136F00 = freelist_new(0x18, 0xC);
}

int func_80106E18()
{
  if (D_80136F00 != 0)
  {
    freelist_free(D_80136F00);
    D_80136F00 = 0;
  }
}

void func_80106E50()
{
  if (D_80136F00 != 0)
  {
    D_80136F00 = freelist_defrag(D_80136F00);
  }
}

int func_80106E88(Actor *param_0)
{
  s32 local_1 = 0;
  void *local_0;
  if (!local_0)
  {
  }
  local_0 = func_80100368();
  if (((*((s32 *) (((char *) local_0) + 0x44))) != 0) && ((((u32) (*((s32 *) (((char *) param_0) + 0x6C)))) >> 21) != 0))
  {
    local_1 |= func_80107320(param_0);
  }
  return local_1;
}

void func_80106EE0(u8 *param_0)
{
  register u32 v0;
  register u32 t6;
  u8 *new_var;
  register u32 t7;
  int t8;
  u16 t9;
  u8 *new_var2;
  v0 = *((u32 *) (param_0 + 0x94));
  t6 = v0 << 2;
  v0 = t6 >> 0x16;
  t7 = v0;
  if (t7 != 0)
  {
    new_var = (0, param_0 + 0x94);
    freelist_erase(((u8 *) D_80136F00), t7 ^ 0, param_0);
    new_var2 = new_var;
    t8 = (*((u16 *) new_var2)) & 0xFFFF;
    t9 = t8 & 0xC00F;
    *((u16 *) (param_0 + 0x94)) = t8 & 0xC00F;
  }
}

s32 func_80106F30(param_0) u8 * param_0;
{
  u32 temp_v0;
  s32 *new_var;
  char *new_var2;
  s32 val;
  new_var = (s32 *) ((new_var2 = (char *) param_0) + 0x94);
  temp_v0 = *new_var;
  val = temp_v0;
  temp_v0 = val;
  temp_v0 = (temp_v0 * 4) >> 22;
  if (temp_v0 == 0)
  {
    return 0;
  }
  return freelist_at(((int) D_80136F00), temp_v0 ^ 0);
}

void func_80106F70(s32 param_0) {
    s32 local_0;
    s32 local_4[3];
    local_0 = func_80106F30(param_0);
    switch (*(s16*)((u8*)local_0 + 10)) {
        case 1:
            if (func_80107858(param_0, local_0) == 0) return;
            func_80107070(param_0, 4);
            return;
        case 2:
            if (_subaddiefade_entrypoint_0(param_0) != 0) return;
            func_80107070(param_0, 3);
            return;
        case 3:
            if (func_801078AC(param_0, local_0) == 0) return;
            func_800EE88C(&local_4, local_0 + 4);
            if (func_8010CAC0(&local_4, 0xc8) != 0) return;
            func_80107070(param_0, 4);
            return;
        case 4:
            if (func_80107784(param_0, local_0) == 0) return;
            func_80107070(param_0, 0);
            return;
        default:
            return;
    }
}

int func_80107070(param_0, param_1) s32 param_0; unsigned int param_1;
{
    u8 *local_0 = func_80106F30(param_0);
    if (!local_0)
    {
        return 0;
    }
    if (*((s16 *) (local_0 + 0xA)) == param_1)
    {
        return 1;
    }
    switch (param_1)
    {
        case 0:
            func_80103110(param_0, 1);
            break;
        case 1:
            _subaddieaudioquick_entrypoint_2(param_0, param_0 + 4, D_801244F0);
            if (!func_801073F8(param_0, 1, 1))
            {
                func_80103110(param_0, 0);
            }
            func_80107750(param_0, local_0);
            break;
        case 2:
            if (!func_801073F8(param_0, 2, 1))
            {
                func_80103110(param_0, 0);
            }
            func_80107750(param_0, local_0);
            break;
        case 3:
            if (!func_801073F8(param_0, 3, 1))
            {
                func_80103110(param_0, 0);
            }
            func_80107448(param_0, local_0);
            break;
        case 4:
            if (!func_801073F8(param_0, 4, 1))
            {
                func_80103110(param_0, 0);
            }
            func_8010754C(param_0, local_0);
            func_801075E4(param_0, local_0);
            break;
    }
    func_801073AC(param_0, param_1);
    *((s16 *) (local_0 + 0xA)) = param_1;
    return 1;
}

void func_80107200(u8 *param_0)
{
  u8 *local_0;
  u32 local_1;
  s16 *new_var2;
  long new_var;
  local_0 = func_80106F30();
  if (local_0 != 0)
  {
    new_var2 = (s16 *) (((s8 *) local_0) + 0x12);
    func_800EE940(local_0 + 4, param_0 + 4, param_0);
    if (1)
    {
    }
    if (1)
    {
    }
    if (1)
    {
    }
    new_var = 0x70;
    local_1 = *((u32 *) (((s8 *) local_0) + 0xC));
    *((u32 *) (((s8 *) local_0) + 0xC)) = (u32) ((((u32) (((((u32) ((*((u32 *) (((s8 *) param_0) + new_var))) << 0x16)) >> 0x1A) ^ (local_1 >> 8)) << 0x14)) >> 0xC) ^ local_1);
    *((u16 *) (((s8 *) local_0) + 0xC)) = (s16) (((*((u16 *) (((s8 *) local_0) + 0xC))) & 0xF) | (((((u32) (*((u32 *) (((s8 *) param_0) + new_var)))) >> 0x19) * 0x10) & 0xFFFF));
    *new_var2 = (s16) ((s32) (*((f32 *) (((s8 *) param_0) + 0x48))));
    *((s16 *) (((s8 *) local_0) + 0xA)) = 0;
    *((f32 *) (((s8 *) local_0) + (new_var * 0))) = 0.0f;
  }
}

int func_801072A8()
{
  s32 *local_1 = func_80106F30();
  if (local_1 == 0)
  {
    return 0;
  }
  return ((s16 *)local_1)[5] != 0;
}

s32 func_801072E4(void)
{
    u8 *ptr = func_80106F30();
    if (ptr == NULL)
    {
        return 0;
    }
    return (*(s16 *)((u8 *)ptr + 0xA)) == 4;
}

s32 func_80107320(param_0) local_2 * param_0;
{
  s32 local_1 = 0;
  s32 local_0;
  local_0 = freelist_next(((int *) &D_80136F00), &local_1);
  bzero(local_0, 0x18);
  param_0->local_1 = local_1;
  func_80107200(param_0);
  return local_0;
}

s32 func_80107388() {
    return (*(s32 *)((s8 *)(func_80100368()) + (0x44)));
}

int func_801073AC(param_0, param_1) s32 param_0; s32 param_1;
{
  s16 *local_0;
  local_0 = func_80107388(param_0) + (param_1 << 2);
  func_80102424(param_0, *local_0);
  func_8010108C(param_0, 0x8F, param_1);
}

s32 func_801073F8(param_0, param_1, param_2) s32 param_0; s32 param_1; u32 param_2; {
    s16 *local_0 = func_80107388(param_0);
    return (*(s16 *)((u8 *)local_0 + param_1 * 4 + 2) & param_2) ? 1 : 0;
}

void func_80107448(param_0, param_1) local_type_80107448 * param_0; f32 * param_1; {
    s32 local_0;
    if (!func_801073F8(param_0, 3, 4)) {
        param_0->local_18 = 0;
        param_0->local_8 = param_0->local_18;
        param_0->local_24 = 0;
    }
    param_0->local_16 = 0;
    param_0->local_6 = 0;
    param_0->local_21 = 0;
    param_0->local_3 = 0;
    param_0->local_4 = 0;
    param_0->local_13 = 0;
    func_8010A570(param_0);
    func_8010A624(param_0);
    func_80104580(param_0);
    func_8010754C(param_0, param_1);
    local_0 = 0;
    do { ++local_0; param_0->local_1[local_0 - 1] = 99; } while (local_0 != 3);
    *param_1 = func_80107A80();
}

void func_8010754C(param_0, param_1) LocalActor_8010754C * param_0; LocalProp * param_1;
{
    func_800EE88C(param_0->position, (u8 *)param_1 + 4);
    param_0->variant = param_1->variant;
    param_0->kind = param_1->kind;
    param_0->rotation = param_1->rotation;
    func_80103014(param_0);
}

void func_801075E4(param_0, param_1) LocalActor_801075E4 * param_0; LocalState * param_1;
{
    LocalDesc *local_0 = func_80100368(param_0);
    func_8010754C(param_0, param_1);
    if (!func_801073F8(param_0, 3, 4)) {
        _subaddiefade_entrypoint_2(param_0);
        param_0->flag2 = 1;
        if (local_0->value != 0.0f) param_0->flag4 = 1;
        else param_0->flag4 = 0;
        param_1->value = 0;
    } else param_1->value = 1.8f;
    param_0->flag0 = func_80102FA0(local_0, 0x80000004);
    param_0->flag1 = func_80102FA0(local_0, 0x80000008);
    param_0->flags |= 0x80000;
    param_0->flag3 = func_80102FA0(local_0, 0x80001000);
    param_1->value14 = 0;
    if (!func_801073F8(param_0, 4, 2)) {
        _subaddieaudioquick_entrypoint_2(param_0, param_0->position, D_801244FC);
    }
}

int func_80107750(param_0, param_1) s32 param_0; s32 param_1;
{
  _subaddiefade_entrypoint_5(param_0);
  func_8010A570(param_0);
  func_8010A624(param_0);
}

s32 func_80107784(param_0, param_1) u8 * param_0; u8 * param_1;
{
    if (func_801073F8(param_0, *(s16 *)((u8 *)param_1 + 0xA), 2) == 0) {
        func_801078DC(param_0, param_1 + 0x14);
    }
    if ((_subaddiefade_entrypoint_0(param_0) == 0xFF) && (func_800D90A4(param_1) != 0)) {
        ((local_type_80107784 *)(param_0 + 0x64))->local_1 = func_80102F74(param_0, 0x80000001);
        if (func_80102F74(param_0, 0x80000002) == 0) {
            func_8010A590(param_0);
        }
        if (func_80102F74(param_0, 0x800) != 0) {
            func_8010A63C(param_0);
        }
        return 1;
    }
    return 0;
}

s32 func_80107858(param_0, param_1) s32 param_0; s32 * param_1;
{
  if (!func_801073F8(param_0, (s32)((s16 *)param_1)[5], 2))
  {
    func_801078DC(param_0, &param_1[5]);
  }
  if (_subaddiefade_entrypoint_0(param_0) == 0) {
    return 1;
  }
  return 0;
}

int func_801078AC(param_0, param_1) s32 param_0; s32 param_1;
{
  if (func_800D90A4(param_1 | 0))
  {
    return 1;
  }
  return 0;
}

s32 func_801078DC(param_0, param_1) void * param_0; s16 * param_1;
{
    f32 local_0[20][3];
    f32 local_1[3];
    s32 local_2;
    s32 local_3;
    s32 local_4;
    s32 local_5;
    f32 local_6[3];
    f32 local_7[3];
    local_5 = *param_1;
    local_2 = _subaddievolume_entrypoint_0(param_0, local_0, 3, 20, &local_5);
    *param_1 = local_5;
    if (local_2 > 0) {
        func_80103F38(param_0, local_1);
        local_4 = func_800B5BE4(0x11);
        func_800BABB8(local_4, 0, 0, 1.0f, D_80124508);
    }
    for (local_3 = 0; local_3 < local_2; local_3++) {
        func_800EFB24(local_6, local_0[local_3], local_1);
        func_800EF368(local_6, 40.0f);
        func_800EF04C(local_0[local_3], local_6);
        func_800EFB24(local_6, local_1, local_0[local_3]);
        func_800EF334(local_6, -1.0f);
        func_800EE780(local_7, local_0[local_3], local_6);
        func_800BABB8(local_4, local_0[local_3], local_7, 1.0f, D_80124538);
    }
    return local_2 >= 0;
}

float func_80107A80(void)
{
    switch (D_8012762C - 0xF)
    {
        case 4: return 40.0f;
        case 1: return 30.0f;
        case 0: return 28.0f;
        case 3: return 26.0f;
        case 5: return 24.0f;
        case 6: return 22.0f;
        case 7: return 20.0f;
        case 8: return 18.0f;
        case 9: return 16.5f;
        case 10: return 14.0f;
        case 11: return 30.0f;
        default: return 30.0f;
    }
}

int func_80107B70(s32 param_0, s32 param_1)
{
  s32 local_0;
  s32 local_1;
  local_0 = func_80106F30(param_0);
  if (local_0 == 0)
  {
    return 0;
  }
  else
  {
    local_1 = local_0 | 0;
    func_800EE88C(param_1, local_1 + 4);
    return 1;
  }
}

void func_80107BB0(void)
{
  s32 new_var2;
  int new_var;
  s32 new_var5;
  s32 sp20;
  s32 new_var3;
  s32 new_var4;
  new_var = 0;
  if (_gccubesearch_entrypoint_9(0x4F0, &sp20, 4) > 0)
  {
    sp20 = sp20;
    new_var4 = (new_var, sp20);
    new_var5 = (new_var3 = new_var4);
    new_var2 = new_var5;
    D_80136F10 = _gspropmarker_entrypoint_3(new_var2);
  }
  else
  {
    D_80136F10 = 1.0;
  }
}

float func_80107C00()
{
  return D_80136F10;
}
