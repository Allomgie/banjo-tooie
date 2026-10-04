#include "common.h"

extern u8 D_8012AA20[];
void func_800BF48C();
typedef struct { f32 local_0; f32 local_1; u8 local_2[3]; u8 local_3[3]; u8 local_4[3]; u8 local_5; } StateC57F0;
extern f32 func_800D8FF8(void);
extern f32 func_800F0E00(f32, f32);
extern f32 func_800F10B4(f32, f32, f32, f32, f32);
typedef struct { s32 field_0; s16 field_4[3], field_A; s32 field_C; s16 field_10[3], field_16; s32 field_18; f32 field_1C[3][3]; u8 field_40[3][4]; f32 field_4C[3], field_58[3], field_64[3]; f32 field_70, field_74, field_78; s32 field_7C, field_80; u32 field_84, field_88; s16 field_8C; u8 field_8E, field_8F, field_90, field_91, field_92, field_93, field_94, field_95; u8 pad_96[6]; u8 field_9C; u8 pad_9D[3]; } GroundState;
extern void func_800EE7F8();
extern s32 func_8001210C(s32);
extern void func_800EFD24(f32 *);
extern void func_800EFA4C(f32 *, f32, f32, f32);
extern u8 unk10[];
extern u8 unkC[];
extern u8 unk18[];
typedef struct CollisionC5 CollisionC5;
typedef struct HitC5 HitC5;
extern f32 mlAbsF(f32);
extern void func_800AAAE0();
extern void func_800AAD28();
extern int D_8011A890;
typedef struct { u8 pad0[0x10]; u8 unk10; u8 pad11[0x63]; f32 unk74; u8 pad78[8]; u32 unk80; u8 pad84[0xB]; u8 unk8F; u8 pad90[8]; f32 unk98; u8 unk9C; } S_C5FCC;
typedef struct { u8 pad0[8]; u32 unk8; } T_C5FCC;
extern void func_800FB508();
typedef struct { u8 pad[0x4C]; f32 local_0[3]; s32 pad0; f32 local_1; u8 pad1[0x10]; f32 local_2, local_3, local_4; u8 pad2[8]; u32 local_5, local_6; u8 pad3[0x10]; u8 local_7; } StateC6060;
typedef struct { u8 pad[8]; s32 local_0; } TriangleC6060;
extern s32 func_800DA298(s32);
typedef struct { f32 field_0[3]; f32 field_C; u32 field_10; u16 field_14, field_16; void *field_18; } GroundHit;
extern u8 unk7C[];
void func_800C6420();
extern void func_800C6320(GroundState *), func_800C6420(GroundState *);

void func_800C5770(void) {
}

void func_800C5778(void)
{
  f32 zero = 0.0f;
  u8 *ptr = (u8 *) (((int *) D_8012AA20));
  ptr[0x11] = 0;
  ptr[0x10] = 0xFF;
  *((f32 *) (ptr + 4)) = zero;
  ptr[8] = (ptr[9] = (ptr[0xA] = (ptr[0xB] = (ptr[0xC] = (ptr[0xD] = (ptr[0xE] = (ptr[0xF] = 0xFF)))))));
  *((f32 *) ptr) = *((f32 *) (ptr + 4));
}

void func_800C57C0()
{
    func_800BF48C(D_8012AA20[8], D_8012AA20[9], D_8012AA20[10]);
}

void func_800C57F0(void) {
    s32 local_0;
    if ((*((StateC57F0 *) D_8012AA20)).local_5) {
        (*((StateC57F0 *) D_8012AA20)).local_0 = func_800F0E00(0.0f, (*((StateC57F0 *) D_8012AA20)).local_0 - func_800D8FF8());
        for (local_0 = 0; local_0 < 3; local_0++) {
            (*((StateC57F0 *) D_8012AA20)).local_2[local_0] = (u32)func_800F10B4((*((StateC57F0 *) D_8012AA20)).local_0, (*((StateC57F0 *) D_8012AA20)).local_1, 0.0f, (f32)(u32)(*((StateC57F0 *) D_8012AA20)).local_4[local_0], (f32)(u32)(*((StateC57F0 *) D_8012AA20)).local_3[local_0]);
        }
        func_800C57C0();
        if ((*((StateC57F0 *) D_8012AA20)).local_0 == 0.0f) (*((StateC57F0 *) D_8012AA20)).local_5 = 0;
    }
}

void func_800C5968(int param_0, int param_1, int param_2, f32 param_3) {
    if (param_3 != 0.0f) {
        (*(u8 *)((u8 *)(&D_8012AA20) + 0x11)) = 1;
        (*(f32 *)((u8 *)(&D_8012AA20) + 0)) = param_3;
        (*(f32 *)((u8 *)(&D_8012AA20) + 4)) = param_3;
        (*(u8 *)((u8 *)(&D_8012AA20) + 0xB)) = param_0;
        (*(u8 *)((u8 *)(&D_8012AA20) + 0xC)) = param_1;
        (*(u8 *)((u8 *)(&D_8012AA20) + 0xD)) = param_2;
        (*(u8 *)((u8 *)(&D_8012AA20) + 0xE)) = (u8) (*(u8 *)((u8 *)(&D_8012AA20) + 8));
        (*(u8 *)((u8 *)(&D_8012AA20) + 0xF)) = (u8) (*(u8 *)((u8 *)(&D_8012AA20) + 9));
        (*(u8 *)((u8 *)(&D_8012AA20) + 0x10)) = (u8) (*(u8 *)((u8 *)(&D_8012AA20) + 0xA));
        return;
    }
    (*(u8 *)((u8 *)(&D_8012AA20) + 0x11)) = 0;
    (*(u8 *)((u8 *)(&D_8012AA20) + 8)) = param_0;
    (*(u8 *)((u8 *)(&D_8012AA20) + 9)) = param_1;
    (*(u8 *)((u8 *)(&D_8012AA20) + 0xA)) = param_2;
    func_800C57C0();
}

s32 func_800C59F0(s32 param_0, s32 param_1, s32 param_2)
{
  func_800C5968(param_0, param_1, param_2, 0);
}

func_800C5A10(u8 *param_0, s32 param_1) {
    if (param_1 == 1){
        param_0[0x93] = 5;
    }
    if (param_1 == 4){
        param_0[0x92] = 1;
    }
    param_0[0x94] = param_1;
}

GroundState *func_800C5A38(void) {
    GroundState *local_0;
    s32 local_1, local_2;
    local_0 = heap_alloc(sizeof(GroundState));
    func_800EFD24(local_0->field_4C);
    func_800EFD24(local_0->field_58);
    for (local_1 = 0; local_1 < 3; local_1++) func_800EFD24(local_0->field_1C[local_1]);
    for (local_1 = 0; local_1 < 3; local_1++) {
        for (local_2 = 0; local_2 < 4; local_2++) {
            local_0->field_40[local_1][local_2] = 255;
        }
    }
    for (local_1 = 0; local_1 < 3; local_1++) {
        local_0->field_4[local_1] = 0;
        local_0->field_10[local_1] = 0;
    }
    local_0->field_A = local_0->field_16 = 0;
    local_0->field_18 = 0;
    local_0->field_C = 0;
    func_800EFA4C(local_0->field_64, 0.0f, 1.0f, 0.0f);
    local_0->field_70 = (-1.8e+04f);
    local_0->field_7C = 0;
    local_0->field_8C = 0;
    local_0->field_74 = (-1.9e+04f);
    local_0->field_78 = 100.0f;
    local_0->field_80 = 0;
    local_0->field_8E = local_0->field_90 = 0;
    local_0->field_8F = local_0->field_91 = 0;
    local_0->field_84 = 0;
    local_0->field_0 = 0;
    local_0->field_88 = 0x1F00;
    local_0->field_95 = 0;
    local_0->field_9C = 0;
    local_0->field_94 = 0;
    func_800C5A10(local_0, 1);
    return local_0;
}

void func_800C5B84(s32 arg0)
{
    func_800C5A10(arg0,1);
}

void func_800C5BA4(void* arg0) 
{
    heap_free(arg0);
}
void* func_800C5BC4(void* arg0) 
{
    return defrag(arg0);
}
int func_800C5BE4(s32 param_0, f32 param_1, f32 param_2, s32 param_3, Actor *param_4)
{
  f32 local_0[3];
  f32 local_1[3];
  s32 local_2;
  func_800EE7F8(local_0, param_0);
  local_0[1] += param_1;
  func_800EE7F8(local_1, param_0);
  local_1[1] += param_2;
  if (param_3 == 0x1F00)
  {
    local_2 = func_800BEF00(local_0, local_1, param_4, param_3);
  }
  else
  {
    local_2 = func_800C6A7C(local_0, local_1, param_4, param_3);
  }
  if (local_2 != 0)
  {
    *((s32 *) (((char *) param_4) + 0x10)) = *((s32 *) (((char *) local_2) + 0x8));
    *((u16 *) (((char *) param_4) + 0x14)) = 0;
  }
  else
  {
    *((s32 *) (((char *) param_4) + 0x10)) = 0;
    *((u16 *) (((char *) param_4) + 0x14)) = 0;
  }
  *((f32 *) (((char *) param_4) + 0xC)) = local_1[1];
  *((s32 *) (((char *) param_4) + 0x18)) = func_800C69FC();
  return local_2;
}

CollisionC5 *func_800C5CC0(f32 *param_0, f32 param_1, f32 param_2, u32 param_3, HitC5 *param_4)
{
    CollisionC5 *local_0;
    if (mlAbsF(param_2 - param_1) > 500.0f) {
        if (param_1 < param_2) {
            local_0 = func_800C5BE4(param_0, param_1, param_1 + 500.0f, param_3, param_4);
            if (local_0 == 0) {
                local_0 = func_800C5BE4(param_0, param_1 + 500.0f - 1.0f, param_2, param_3, param_4);
            }
        } else {
            local_0 = func_800C5BE4(param_0, param_1, param_1 - 500.0f, param_3, param_4);
            if (local_0 == 0) {
                local_0 = func_800C5BE4(param_0, param_1 - 500.0f + 1.0f, param_2, param_3, param_4);
            }
        }
    } else {
        local_0 = func_800C5BE4(param_0, param_1, param_2, param_3, param_4);
    }
    return local_0;
}

u8 func_800C5E14(s32 *param_0)
{
  f32 local_0;
  s32 local_4;
  f32 new_var2;
  int new_var;
  local_4 = *((u8 *) (((char *) param_0) + 143));
  if (local_4 == 0)
  {
    return 2;
  }
  new_var = 0;
  if ((local_4 != new_var) && (*((u8 *)param_0 + 142) == 0))
  {
    return 4;
  }
  new_var2 = *((f32 *) (&param_0[29]));
  local_0 = new_var2;
  if (local_0 < (*((f32 *) (&param_0[20]))))
  {
    return 2;
  }
  local_0 = local_0 - (*((f32 *) (&param_0[28])));
  if (local_0 < (-20.0f))
  {
    return 2;
  }
  if (local_0 > 100.0f)
  {
    return 4;
  }
  return 3;
}

void func_800C5EB8(u8 *param_0, f32 param_1, s32 param_2, s32 param_3, s32 param_4, s32 param_5, s32 param_6) {
    if (param_6 != 0) {
        func_800AAD28(param_0 + 0x1C);
        func_800AAAE0(param_0 + 0x40);
        func_800FB508(param_0 + 4, param_6);
    }
    (*(s8 *)((s8 *)(param_0) + (0x8E))) = 1;
    (*(s32 *)((s8 *)(param_0) + (0x7C))) = param_2;
    (*(s16 *)((s8 *)(param_0) + (0x8C))) = (s16) param_3;
    (*(f32 *)((s8 *)(param_0) + (0x70))) = param_1;
    (*(s32 *)((s8 *)(param_0) + (0))) = param_5;
    func_800EE7F8(param_0 + 0x64, param_4);
}

void func_800C5F40(s32 param_0, s32 *param_1, s32 param_2) {
    func_800C5EB8(param_0, ((f32 *)param_1)[3], param_1[4], ((s16 *)param_1)[10], param_1, param_1[6], param_2);
}

void func_800C5F8C(int param_0) {
    func_800C5EB8(param_0, (-1.8e+04f), 0, 0, &D_8011A890, 0, 0);
}

void func_800C5FCC(S_C5FCC *param_0, f32 param_1, T_C5FCC *param_2) {
    if (param_0->unk9C != 0) { param_1 = param_0->unk98; }
    if (param_2 != 0) { func_800FB508(&param_0->unk10, param_2); }
    if (param_2 != 0) { param_0->unk80 = param_2->unk8; }
    param_0->unk8F = 1;
    param_0->unk74 = param_1;
}

int func_800C6038(s32 param_0)
{
  func_800C5FCC(param_0, (-1.9e+04f), 0);
}

void func_800C6060(param_0) StateC6060 * param_0; {
    f32 local_0;
    s32 local_1;
    f32 local_2[6];
    s32 local_3;
    f32 local_4[3];
    TriangleC6060 *local_5;
    s32 local_6 = 0;
    func_800EE7F8(local_4, param_0->local_0);
    local_0 = param_0->local_4;
    if (func_800DA298(0x6B5)) {
        local_5 = func_800C5CC0(local_4, func_800F0E00(param_0->local_1 - param_0->local_0[1], 150.0f) + 10.0f, -5.0f, param_0->local_6, local_2);
        if (local_5 || param_0->local_7) {
            func_800C5FCC(param_0, local_2[3], local_5);
            local_6 = 1;
        }
    }
    local_5 = func_800C5CC0(local_4, local_0, -1300.0f, param_0->local_5, local_2);
    if (!local_5) {
        func_800C5F8C(param_0);
        if (!local_6) func_800C6038(param_0);
        else if (param_0->local_0[1] < param_0->local_3) func_800C5A10(param_0, 3);
    } else if (local_5->local_0 & 0x20020) {
        func_800C5FCC(param_0, local_2[3], local_5);
        if (param_0->local_2 < param_0->local_3 && param_0->local_0[1] < param_0->local_3) func_800C5A10(param_0, 3);
        local_5 = func_800C5CC0(local_4, local_0, -450.0f, param_0->local_5 | 0x20020, local_2);
        if (!local_5) func_800C5F8C(param_0);
        else if (local_2[1] >= 0.0f) func_800C5F40(param_0, local_2, local_5);
    } else if (local_2[1] < 0.0f && !(local_5->local_0 & 0x10000)) {
        local_0 = local_2[3] - local_4[1];
        local_5 = func_800C5CC0(local_4, local_0 - 1.0f, local_0 - 1.3e+03f, param_0->local_5 | 0x20020, local_2);
        if (local_5) func_800C5F40(param_0, local_2, local_5);
        else func_800C5F8C(param_0);
    } else {
        func_800C5F40(param_0, local_2, local_5);
        if (local_6) func_800C5A10(param_0, 3);
        else func_800C6038(param_0);
    }
}

void func_800C6320(GroundState *param_0) {
    f32 local_2[7];
    s32 local_1;
    f32 local_0;
    f32 local_3[3];
    void *local_4;
    func_800EE7F8(local_3, param_0->field_4C);
    local_4 = func_800C5CC0(local_3, param_0->field_78, -1300.0f, param_0->field_84 | 0x20020, local_2);
    if (local_4 && local_2[1] >= 0.0f) func_800C5F40(param_0, local_2, local_4);
    local_0 = param_0->field_74 - local_3[1];
    local_4 = func_800C5CC0(local_3, local_0 + 50.0f, local_0 - 50.0f, param_0->field_88, local_2);
    if (local_4 || param_0->field_9C) func_800C5FCC(param_0, local_2[3], local_4);
    local_1 = func_800C5E14(param_0);
    if (local_1 != 3) func_800C5A10(param_0, local_1);
}

void func_800C6420(param_0) GroundState * param_0; {
    f32 local_2[7];
    s32 local_3;
    s32 local_1;
    s32 local_4;
    f32 local_0;
    f32 local_5[3];
    void *local_6;
    func_800EE7F8(local_5, param_0->field_4C);
    local_3 = (param_0->field_4C[1] - param_0->field_70 > 120.0f) ? 1 : 0;
    local_4 = func_8001210C(1);
    if (!local_3 || local_4) {
        if (local_3) param_0->field_8F = param_0->field_91;
        local_6 = func_800C5CC0(local_5, param_0->field_78, -390.0f, param_0->field_84 | 0x20020, local_2);
        if (local_6) {
            if (local_2[1] >= 0.0f) func_800C5F40(param_0, local_2, local_6);
        } else func_800C5F8C(param_0);
    }
    if (!local_3 || !local_4) {
        if (local_3) param_0->field_8E = param_0->field_90;
        local_0 = param_0->field_74 - local_5[1];
        local_6 = func_800C5CC0(local_5, local_0 + 140.0f, local_0 - 140.0f, param_0->field_88, local_2);
        if (local_6 || param_0->field_9C) {
            func_800C5FCC(param_0, local_2[3], local_6);
            param_0->field_92 = 1;
        } else if (param_0->field_92) {
            param_0->field_92 = 0;
            param_0->field_8F = 1;
        }
    }
    local_1 = func_800C5E14(param_0);
    if (local_1 != 4) func_800C5A10(param_0, local_1);
}

void func_800C65E0(GroundState *param_0) {
    GroundHit local_0;
    void *local_1;
    u8 state;
    u8 next;
    state = param_0->field_94;
    next = state;
    param_0->field_90 = param_0->field_8E;
    param_0->field_91 = param_0->field_8F;
    param_0->field_8E = param_0->field_8F = 0;
    if (state == 1 || param_0->field_93) {
        param_0->field_93--;
        local_1 = func_800C5BE4(param_0->field_4C, -100.0f, 7000.0f, param_0->field_88, &local_0);
        if (local_1) func_800C5FCC(param_0, local_0.field_C, local_1);
        if (local_1) func_800C5A10(param_0, 3);
        else func_800C5A10(param_0, 2);
        next = param_0->field_94;
    }
    switch (next) {
    case 2: func_800C6060(param_0); break;
    case 3: func_800C6320(param_0); break;
    case 4: func_800C6420(param_0); break;
    }
    func_800EE7F8(param_0->field_58, param_0->field_4C);
}

func_800C6704(u8 *param_0) {
    return param_0[0x8E];
}

s32 func_800C670C(s32 *param_0)
{
    if ((-1.9e+04f) == *(f32 *)(param_0 + 0x1D)) {
        return 0;
    }
    return (u8)param_0[0x23];
}

f32 func_800C673C(f32 *arg0)
{
    return arg0[30];
}

int func_800C6744(Actor *param_0) {
    return (*(s32 *)((char *)(param_0) + 0x7C));
}

s16 func_800C674C(s32 param_0) {
    s16 *local_0 = param_0 + 0x8C;
    return *local_0;
}

func_800C6754(u8 *param_0) {
    return param_0[0x95];
}

void func_800C675C(s32 param_0, s32 param_1) {
    func_800EE7F8(param_1, param_0 + 0x64);
}

f32 func_800C6784(u8 *param_0)
{
  f32 local_0;
  f32 local_1;
  f32 local_2;
  if (param_0[0x95] != 0)
  {
    local_2 = 15.0f;
    local_1 = (*((f32 *) (param_0 + 0x74))) - local_2;
    local_0 = *((f32 *) (param_0 + 0x70));
    if ((*((f32 *) (param_0 + 0x70))) < local_1)
    {
      return local_1;
    }
  }
  return *((f32 *) (param_0 + 0x70));
}

int func_800C67C8(s32 *param_0) {
    return param_0[0];
}

func_800C67D0(u8 *param_0) {
    return param_0[0x9C];
}

f32 func_800C67D8(f32 *arg0)
{
    return arg0[29];
}

int func_800C67E0(s32 param_0[12])
{
  return param_0[0x20];
}

func_800C67E8(param_0){
    return param_0 + 0x10;
}

func_800C67F0(param_0){
    return param_0 + 4;
}

int func_800C67F8(u8 *param_0, u8 *param_1)
{
  int new_var;
  s32 local_0;
  int new_var2;
  int new_var3;
 do { } while (0);
  for (local_0 = 0; local_0 < 3; local_0++)
  {
 goto dummy_label_893152; dummy_label_893152: ;
    ;
    new_var3 = (local_0 * 4) + 1;
    param_1[(local_0 * 4) + 0] = param_0[(local_0 * 4) + 64];
    param_1[(local_0 * 4) + 1] = param_0[(local_0 * 4) + 65];
    new_var2 = ((((4 & 0xFF) & 0xFF) & 0xFF) & 0xFF) & 0xFF;
    new_var3 = (local_0 * 4) - 1;
    param_1[(local_0 * 4) + 2] = param_0[(local_0 * 4) + 66];
    param_1[(local_0 * 4) + 3] = param_0[(local_0 * 4) + 67];
  }

}

void func_800C6840(s32 param_0, s32 param_1) {
    s32 var_s0;
    s32 var_s1;
    s32 var_s2;

    var_s0 = 0;
    var_s1 = param_1;
    var_s2 = param_0 + 0x1C;
    do {
        func_800EE7F8(var_s1, var_s2);
        var_s0 += 0xC;
        var_s1 += 0xC;
        var_s2 += 0xC;
    } while (var_s0 != 0x24);
}

int func_800C68A0(f32 *param_0, f32 param_1)
{
  int new_var2;
  int new_var;
  new_var = 5;
 if (new_var = 1) { }
  new_var2 = 30;
  param_0[new_var2] = param_1;
}

int func_800C68AC(s32 param_0)
{
  func_800EE7F8(param_0 + 0x4C);
}

func_800C68CC(s32 param_0, s32 param_1){
    s32 local_0;
    local_0 = param_0;
    local_0 += 0x84;
    *(s32*)local_0 = param_1;
}

int func_800C68D4(u8 *param_0, long param_1)
{
  param_0[0x95] = param_1;
}

void func_800C68DC(void* param_0) {
    ((u8*)param_0)[0x93] = 1;
}

int func_800C68E8(u8 *param_0, unsigned int param_1, f32 param_2)
{
  if (param_0[0x9C] && (!param_1))
  {
    param_0[0x93] = 1;
  }
  if (param_1)
  {
    *((f32 *) (param_0 + 0x98)) = param_2;
  }
  param_0[0x9C] = param_1;
 goto dummy_label_574333; dummy_label_574333: ;
}
