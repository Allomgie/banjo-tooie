#include "core2/1EA9160.h"
extern s32 func_80106790(s32);
void func_800DA544(s32);

extern s16 D_8011AE64[];
extern s16 D_8011AE6C[];
extern s16 D_8011AE74[];
extern s16 D_8011AE76;
extern struct { s16 unk0; s16 unk2; } D_8011AE84[32];
typedef struct { u8 field_0, field_1, field_2; } LocalRecord;
extern void func_800DC324(s32);
void _subaddieDll_entrypoint_4(Actor *, s32);
extern u8 D_8011AB40[];
extern u8 D_8011ABC8[];
extern u8 D_8011AC7C[];
extern u8 D_8011ACB0[];
extern u8 D_8011ACD4[];
extern u8 D_8011AD08[];
typedef struct { u8 field0,pad[2]; } LocalThree;
typedef struct { u8 field0,field1; } LocalTwo;
extern LocalThree D_8011AB3D[];
extern LocalTwo D_8011ABC6[];
extern LocalTwo D_8011AC7A[];
extern LocalTwo D_8011ACAE[];
extern LocalTwo D_8011ACD2[];
extern s32 _chnests_entrypoint_13(s32);
extern s32 func_800EA05C(void);
extern u8 D_8012B190[];
struct D_8012B18C_struct { int a; int b; int c; int d; int e; };
extern struct D_8012B18C_struct D_8012B18C[];
extern void func_800EE7F8(f32 [3], f32 [3]);
extern f32 D_8012B180[3];
extern u8 D_8011AB3F[];
extern u8 D_8011ABC7[];
extern u8 D_8011ACD3[];
extern u8 D_8011AC7B[];
extern u8 D_8011ACAF[];
extern u8 D_8011AE3B[];
extern u8 D_8011AE5B[];
extern s32 D_8011AF28[];
extern s32 D_8011AF04[];
extern s32 func_800D395C(void);
extern s32 func_800DA298(u32);
extern s32 _glcutDll_entrypoint_20(void);
extern void func_800DA524(s32);
extern void func_800FC660(u32);
extern u8 D_8011AB3E[];
s32 func_800D0820();
s32 func_800D0894();
s32 func_800D0A80();
s32 func_800D0B68();

extern s32 D_8011AE60;

void func_800CF870(s32 param_0)
{
  D_8011AE60 = param_0;
}

s32 func_800CF87C()
{
    return D_8011AE60;
}

s32 func_800CF888(s32 param_0, s32 param_1)
{
  s16 *var_v1;
 do { var_v1 = D_8011AE64; loop_1: if ((param_0 == var_v1[0]) && (param_1 == var_v1[1])) { return 1; } var_v1 += (0, 2); if (var_v1 == D_8011AE6C) { return var_v1[0] * 0; } } while (0);
  goto loop_1;
}

s32 func_800CF8D0(s32 param_0, s32 param_1)
{
  s16 *var_v1;
 do { var_v1 = D_8011AE6C; loop_1: if ((param_0 == var_v1[0]) && (param_1 == var_v1[1])) { return 1; } var_v1 += (0, 2); if (var_v1 == D_8011AE74) { return var_v1[0] * 0; } } while (0);
  goto loop_1;
}

s32 func_800CF918(param_0, param_1) s32 param_0; s32 param_1;
{
  s32 local_0;
  struct 
  {
    s16 unk0;
    s16 unk2;
  } *var_v0;
  local_0 = 1;
  if ((param_0 == (*((s16 *) D_8011AE74))) && (param_1 == D_8011AE76))
  {
    return 0;
  }
  local_0 = 1;
  var_v0 = &D_8011AE84;
  loop_4:
  if ((param_0 == var_v0->unk0) && (param_1 == var_v0->unk2))
  {
    return local_0;
  }

  if ((param_0 == var_v0[4].unk0) && (param_1 == var_v0[4].unk2))
  {
    return local_0 + 1;
  }
  if ((param_0 == var_v0[8].unk0) && (param_1 == var_v0[8].unk2))
  {
    return local_0 + 2;
  }
  if ((param_0 == var_v0[12].unk0) && (param_1 == var_v0[12].unk2))
  {
    return local_0 + 3;
  }
  local_0 += 4;
  var_v0 += 0x10;
  if (local_0 == 9)
  {
    return -1;
  }
  goto loop_4;
}

void func_800CF9E4(s32 param_0, s32 param_1, s32 param_2) {
    u8 *local_3;
    s32 local_0[3];
    s32 local_1;
    local_1 = func_800CF918(param_0, param_1);
    for (param_0 = 0; param_0 < 3; param_0++) local_0[param_0] = ((u8 *) D_8011AE74)[local_1 * 16 + 12 + param_0];
    local_3 = ((u8 *) D_8011AE74) + local_1 * 16;
    func_800C8D4C(param_2, local_3 + 4);
    func_800C8E84(param_2, local_0);
    func_800C8F64(param_2, local_3[15]);
}

void func_800CFA70()
{
    func_800CF918();
}

s32 func_800CFA90(void)
{
    s32 local_0[9];
    s32 local_1;
    s32 local_2;
    s32 local_3;

    if (func_800DA9E4(0x6A0, 1)) {
        return 0;
    }
    if (!func_800DA298(0x379)) {
        local_1 = func_800DC128(0, 0x21);
        func_800DA7A8(0x37A, local_1, 5);
        func_800DA544(0x379);
    } else {
        local_1 = func_800DA564(0x37A, 5);
    }
    func_800DC330();
    func_800DC324(local_1);
    for (local_3 = 0; local_3 < 9; local_3++) {
        local_0[local_3] = 0;
    }
    for (local_3 = 0; local_3 < 45; local_3++) {
        local_2 = func_800DC128(0, 9);
        while (local_2 < local_0[local_2]) {
            local_2 = func_800DC128(0, 9);
        }
        local_0[local_2]++;
        ((LocalRecord *) D_8011AB40)[local_3].field_1 = local_2;
    }
    func_800DC354();
    return 1;
}

void func_800CFBC8(Actor *param_0, u32 param_1, s32 param_2, s32 param_3)
{
    func_8010108C(param_0, 0x13, param_1);
    if (func_800CF888(param_1, param_2))
    {
        _subaddieDll_entrypoint_4(param_0, 1);
    }
    if (func_800CF8D0(param_1, param_2))
    {
        func_8010108C(param_0, 0x12, 1);
    }
    if (func_800CF918(param_1, param_2) != -1)
    {
        func_8010108C(param_0, 0x55, 1);
    }
}

s32 func_800CFC5C(s32 param_0){
    param_0 -= D_8011AE60;
    if(-1 < param_0 && param_0 < 0xA){
        return param_0;
    }
    return -1;
}

u32 func_800CFC8C(s32 param_0, s32 param_1)
{
  s32 var_a0;
  s32 temp_s0;
  s32 var_s1;
  s32 var_s2;
  u8 temp_t;
  u8 *var_s0;
  var_s2 = 0;
  switch (param_0)
  {
    case 0:
      var_s1 = func_800D0820(param_0);
      if (func_800D0894(param_0) >= var_s1)
    {
      var_s0 = D_8011AB40 + (var_s1 * 3);
      do
      {
        temp_t = *((u8 *) (((s8 *) var_s0) + (-3)));
        var_s1 += 1;
        var_s0 += 3;
        if (param_1 == (temp_t & 0xFF))
        {
          var_s2 += 1;
        }
      }
      while (func_800D0894(param_0) >= var_s1);
    }
      return var_s2;

    case 1:
      var_s1 = func_800D0820(param_0);
      if (func_800D0894(param_0) >= var_s1)
    {
      var_s0 = D_8011ABC8 + (var_s1 * 2);
      do
      {
        if (param_1 == var_s0[-2])
        {
          var_s2 += 1;
        }
        var_s1 += 1;
        var_s0 += 2;
         
      }
      while (func_800D0894(param_0) >= var_s1);
    }
      return var_s2;

    case 2:
      var_s1 = func_800D0820(param_0);
      if (func_800D0894(param_0) >= var_s1)
    {
      var_s0 = D_8011AC7C + (var_s1 * 2);
      do
      {


        if (param_1 == var_s0[-2])
        {
          var_s2 += 1;
        }
        var_s1 += 1;
        var_s0 += 2;
        
      }
      while (func_800D0894(param_0) >= var_s1);
    }
      return var_s2;

    case 3:
      var_s1 = func_800D0820(param_0);
      if (func_800D0894(param_0) >= var_s1)
    {
      var_s0 = D_8011ACB0 + (var_s1 * 2);
      do
      {
        if (param_1 == var_s0[-2])
        {
          var_s2 += 1;
        }
        var_s1 += 1;
        var_s0 += 2;
      }
      while (func_800D0894(param_0) >= var_s1);
    }
      return var_s2;

    case 4:
      var_s1 = func_800D0820(param_0);
      if (func_800D0894(param_0) >= var_s1)
    {
      var_s0 = D_8011ACD4 + (var_s1 * 2);
      do
      {
        if (param_1 == var_s0[-2])
        {
          var_s2 += 1;
        }
        var_s1 += 1;
        var_s0 += 2;
      }
      while (func_800D0894(param_0) >= var_s1);
    }
      return var_s2;

    case 5:
      temp_s0 = func_800D0894(param_0);
      return (temp_s0 - func_800D0820(param_0)) + 1;

    case 6:
      var_s1 = func_800D0820(param_0);
      if (func_800D0894(param_0) >= var_s1)
    {
      var_s0 = D_8011AD08 + (var_s1 * 2);
      do
      {
        if (param_1 == (*((u8 *) (((s8 *) var_s0) + (-2)))))
        {
          if ((*((u8 *) (((s8 *) var_s0) + (-1)))) != 0)
          {
            var_a0 = 0x1DA;
          }
          else
          {
            var_a0 = 0x1D9;
          }
          var_s2 += _chnests_entrypoint_13(var_a0);
        }
        var_s1 += 1;
        var_s0 += 2;
      }
      while (func_800D0894(param_0) >= var_s1);
    }
      return var_s2;

    case 7:
      temp_s0 = func_800D0894(param_0);
      return (temp_s0 - func_800D0820(param_0)) + 1;

    case 8:
      temp_s0 = func_800D0894(param_0);
      return (temp_s0 - func_800D0820(param_0)) + 1;

    default:
      return -1;

  }

}

s32 func_800CFFBC(param_0, param_1)
s32 param_0;
s32 param_1;
{
    s32 local_0;
    if (param_0 >= func_800D0820(param_1 | 0))
    {
        local_0 = func_800D0894(param_1);
        if (!(local_0 < param_0)) {
            return 1;
        }
    }
    return 0;
}

s32 func_800D0018(s32 param_0,s32 param_1)
{
    /* HEADER DEPENDENCY: also push core2/1EA9160.h; the category argument is s32, not s16. */
    s32 local_0;
    s32 local_1=0;
    switch(param_0) {
    case 0:
        for (local_0=func_800D0820(param_0);local_0<=func_800D0894(param_0);local_0++) {
            if (func_800D0B68(local_0,param_0) && param_1==D_8011AB3D[local_0].field0) local_1++;
        }
        return local_1;
    case 1:
        for (local_0=func_800D0820(param_0);local_0<=func_800D0894(param_0);local_0++) {
            if (func_800D0B68(local_0,param_0) && param_1==D_8011ABC6[local_0].field0) local_1++;
        }
        return local_1;
    case 2:
        for (local_0=func_800D0820(param_0);local_0<=func_800D0894(param_0);local_0++) {
            if (func_800D0B68(local_0,param_0) && param_1==D_8011AC7A[local_0].field0) local_1++;
        }
        return local_1;
    case 3:
        for (local_0=func_800D0820(param_0);local_0<=func_800D0894(param_0);local_0++) {
            if (func_800D0B68(local_0,param_0) && param_1==D_8011ACAE[local_0].field0) local_1++;
        }
        return local_1;
    case 4:
        for (local_0=func_800D0820(param_0);local_0<=func_800D0894(param_0);local_0++) {
            if (func_800D0B68(local_0,param_0) && param_1==D_8011ACD2[local_0].field0) local_1++;
        }
        return local_1;
    case 6:
        for (local_0=func_800D0820(param_0);local_0<=func_800D0894(param_0);local_0++) {
            if (func_800D0B68(local_0,param_0) && param_1==((LocalTwo *) D_8011AD08)[local_0-1].field0)
                local_1+=_chnests_entrypoint_13(((LocalTwo *) D_8011AD08)[local_0-1].field1 ? 0x1DA : 0x1D9);
        }
        return local_1;
    default:
        for (local_0=func_800D0820(param_0);local_0<=func_800D0894(param_0);local_0++) {
            if (func_800D0B68(local_0,param_0)) local_1++;
        }
        return local_1;
    }
    return local_1;
}

s32 func_800D035C(s32 param_0)
{
    s32 local_0;
    s32 local_1 = 0;
    if (param_0 == 6) {
        for (local_0 = func_800D0820(param_0); local_0 <= func_800D0894(param_0); local_0++) {
            if (func_800D0B68(local_0, param_0)) {
                local_1 += _chnests_entrypoint_13(D_8011AD08[local_0 * 2 - 1] ? 0x1DA : 0x1D9);
            }
        }
    } else {
        for (local_0 = func_800D0820(param_0); local_0 <= func_800D0894(param_0); local_0++) {
            if (func_800D0B68(local_0, param_0)) local_1++;
        }
    }
    return local_1;
}

int func_800D046C(s32 param_0, s32 param_1, s32 param_2)
{
  s32 local_0;
  local_0 = func_800D0A80(param_1 | 0, param_2 | 0);
  func_800DAC78(param_0, local_0 | 0);
}

int func_800D04A0(s32 param_0, s32 param_1)
{
  s32 s0;
  s32 s1;
  s32 s2;
  s32 s3;
  s32 s4;
  s32 ra;

  s4 = param_0;
  s1 = param_1;
  s2 = 0;
  s0 = func_800D0820(s1 | s1);
  s3 = func_800D0894(s1 | s1);
  if (s3 >= s0) {
    do {
      if (func_800D046C(s4, s0, s1) == 1) {
        s2++;
      }
      s0++;
      s3 = func_800D0894(s1 | s1);
    } while (s3 >= s0);
  }

  return s2;
}

void func_800D053C(u32 param_0, u32 param_1)
{
  s32 local_0;
  if (param_1 == 1)
  {
    local_0 = func_800CFC5C(param_0);
    if (local_0 != -1)
    {
      *(u16 *)&D_8012B190[local_0 * 20] = (u16)(short)func_800EA05C();
    }
  }
}

void func_800D0594(s32 param_0, s32 param_1, short param_2)
{
  s32 idx;
  if (param_1 == 1)
  {
 idx = func_800CFC5C(param_0); if (idx != (-1)) {
      *((s16 *) (((char *) (&D_8012B190)) + (idx * 20))) = param_2;
    }
  }
}

void func_800D05E4(s32 param_0, long param_1, s32 param_2) {
    if (param_1 == 1) {
        s32 var = func_800CFC5C(param_0);
        if (var != -1) {
            D_8012B18C[var].a = param_2;
        }
    }
}

s32 func_800D0634(u32 param_0, u32 param_1)
{
  int new_var2;
  int new_var;
  s32 local_0;
  if (param_1 == 1)
  {
    local_0 = func_800CFC5C(param_0);
    if (local_0 != (-1))
    {
      new_var = (((((((local_0 * 5) & 0xFFFFFFFFFFFFFFFF) & 0xFFFFFFFFFFFFFFFF) & 0xFFFFFFFFFFFFFFFF) & 0xFFFFFFFFFFFFFFFF) & 0xFFFFFFFFFFFFFFFF) & 0xFFFFFFFFFFFFFFFF) & 0xFFFFFFFFFFFFFFFF;
      new_var2 = new_var & 0xFFFFFFFFFFFFFFFF;
      return ((s32 *) D_8012B18C)[((new_var2 & 0xFFFFFFFFFFFFFFFF) & ((short) 0xFFFFFFFFFFFFFFFF)) & 0xFFFFFFFFFFFFFFFF];
    }
  }
  return 0;
}

s32 func_800D0684(s32 param_0, s32 param_1)
{
  s32 local_0;
  if (param_1 == 1)
  {
    local_0 = func_800CFC5C(param_0);
    if (local_0 != (-1))
    {
      return *(s16 *)((char *)((s16 *) D_8012B190) + local_0 * 20);
    }
  }
  return 0;
}

s32 func_800D06D4(s32 param_0, s32 param_1)
{
    switch (param_1)
    {
        case 1:
            return ((u8 *) D_8011ABC6)[param_0 * 2];

        case 0:
            return ((u8 *) D_8011AB3D)[param_0 * 3];

        case 4:
            return ((u8 *) D_8011ACD2)[param_0 * 2];

        case 3:
            return ((u8 *) D_8011ACAE)[param_0 * 2];

        case 2:
            return ((u8 *) D_8011AC7A)[param_0 * 2];

        case 5:
            return 0x10;

        case 6:
            return -1;

        default:
            return -1;
    }
}

void func_800D0778(s32 param_0, s32 param_1, s32 *param_2)
{
    s32 tmp;

    if (param_1 == 1)
    {
        tmp = func_800CFC5C(param_0);
        if (tmp != -1)
        {
            func_800EE7F8((f32*)((u8*)&D_8012B180 + tmp * 0x14), param_2);
        }
    }

}

void func_800D07CC(s32 param_0, s32 param_1, s32 *param_2)
{
    s32 tmp;

    if (param_1 == 1)
    {
        tmp = func_800CFC5C(param_0);
        if (tmp != -1)
        {
            func_800EE7F8(param_2, ((u8 *) D_8012B180) + tmp * 0x14);
        }
    }
}

s32 func_800D0820(param_0) s32 param_0;
{
  switch (param_0)
  {
    case 0 :
      return 1;

    case 1 :
      return 1;

    case 2 :
      return 1;

    case 3 :
      return 1;

    case 4 :
      return 1;

    case 5 :
      return 1;

    case 6 :
      return 1;

    case 7 :
      return 1;

    case 8 :
      return 1;

    default :
      return -1;

  }

}

s32 func_800D0894(param_0) s32 param_0;{
    switch(param_0){
        case 0: return 0x2D;
        case 1: return 0x5A;
        case 2: return 0x19;
        case 3: return 0x11;
        case 4: return 0x19;
        case 5: return 0x19;
        case 6: return 0x99;
        case 7: return 0x1E;
        case 8: return 0x4;
    }
    return -1;
}

s32 func_800D0908(param_0, param_1) s32 param_0; s32 param_1;
{
  s32 local_0;
  s32 local_1;
  s32 local_2;
  s32 local_3;
  s32 local_4;
  local_3 = param_0 * 3;
  local_0 = param_0 << 1;
  local_1 = param_0 << 1;
  local_2 = param_0 << 1;
  local_4 = param_0 << 1;
  switch (param_1)
  {
    case 0:
      if (D_8011AB3F[local_3])
    {
      return D_8011AF28[param_1] + D_8011AB3F[local_3] - 1;
    }
      break;

    case 1:
      if (D_8011ABC7[local_0])
    {
      return D_8011AF28[param_1] + D_8011ABC7[local_0] - 1;
    }
      break;

    case 4:
      if (D_8011ACD3[local_1])
    {
      return D_8011AF28[param_1] + D_8011ACD3[local_1] - 1;
    }
      break;

    case 2:
      if (D_8011AC7B[local_2])
    {
      return D_8011AF28[param_1] + D_8011AC7B[local_2] - 1;
    }
      break;

    case 3:
      if (D_8011ACAF[local_4])
    {
      return D_8011AF28[param_1] + D_8011ACAF[local_4] - 1;
    }
      break;

    case 7:
      if (D_8011AE3B[param_0])
    {
      return D_8011AF28[param_1] + D_8011AE3B[param_0] - 1;
    }
      break;

    case 8:
      if (D_8011AE5B[param_0])
    {
      return D_8011AF28[param_1] + D_8011AE5B[param_0] - 1;
    }
      break;

    case 5:

    case 6:
      break;

  }

  return 0;
}

s32 func_800D0A80(param_0, param_1) s32 param_0; s32 param_1;
{
  return D_8011AF04[param_1] + param_0 - 1;
}

s32 func_800D0A9C(u32 param_0, u32 param_1)
{
  s32 local_0;
  local_0 = func_800D0908(param_0, param_1);
  if (local_0 == 0) return 1;
  return (func_800DA298(local_0) || _glcutDll_entrypoint_20() || func_800D395C()) ? 1 : 0;
}

int func_800D0B08()
{
  s32 local_0;
  extern s32 func_800D0908();
  local_0 = func_800D0908();
  if (local_0 != 0)
  {
    func_800DA544(local_0);
  }
}

void func_800D0B38(s32 param_0, s32 param_1) {
  s32 local_0 = func_800D0908(param_0, param_1);
  if (local_0 != 0)
  {
    func_800DA524(local_0);
  }
}

s32 func_800D0B68(param_0, param_1) u32 param_0; u32 param_1;
{
  s32 local_0;
  local_0 = func_800D0A80(param_0, param_1);
  if (local_0 == 0) return -1;
  return (func_800DA298(local_0) || _glcutDll_entrypoint_20() || func_800D395C()) ? 1 : 0;
}

void func_800D0BD4(s32 param_0, u32 param_1)
{
    s32 local_0;
    local_0 = func_800D0A80(param_0, param_1);
    if (local_0 != 0)
    {
        func_800DA544(local_0);
        if (param_1 != 0)
        {
            if (param_1 != 1)
            {
                if (param_1 == 6)
                {
                    func_800D24E8(0xD0, func_800D035C(6), 0);
                }
            }
            else
            {
                func_800D24E8(0xD6, func_800D035C(1), 0);
                goto block_6;
            }
        }
        else
        {
block_6:
            func_80101238(0xB7, (param_0 << 0x10) | (param_1 & 0xFFFF));
        }
    }
}

void func_800D0C78(u32 param_0, u32 param_1, u32 param_2)
{
  if (param_1 == 1)
  {
    func_800D0B08();
    func_800D0BD4(param_0, param_1);
    if (!param_2)
    {
      func_800FC660(5);
    }
  }
}

int func_800D0CC8(s32 param_0)
{
  return D_8011AB3E[param_0 * 3];
}

int func_800D0CE0(s32 param_0, s32 param_1, u32 param_2, s32 *param_3) {
    *param_3 = 0;
    switch (param_2) {
        case 0:
            _chbounce_entrypoint_7(0x1C, param_1, param_0);
            break;
        case 1:
            _chbounce_entrypoint_7(0x1D, param_1, param_0);
            break;
        case 4:
            _chbounce_entrypoint_7(0x1E, param_1, param_0);
            break;
        case 3:
            *param_3 = 1;
        case 2:
            func_80108474(param_0, param_1, 0);
            break;
        case 5:
            _chbounce_entrypoint_7(0x1F, param_1, param_0);
            break;
        case 6:
            _chbounce_entrypoint_7(0x20, param_1, param_0);
            break;
        default:
            return 0;
    }
}

s32 func_800D0DAC(s32 param_0, s32 *param_1, u32 param_2, u8 *param_3) {
    u16 local_2;
    s32 local_3;
    s32 *local_0;
    s32 local_1;

    local_2 = param_0;
    local_3 = (param_0 >> 16) & 0xFFFF;
    switch (local_2) {
    case 1:
        local_0 = func_800D0CE0(0x21F, param_1, param_2, &local_1);
        if (local_1 == 0) {
            func_8010108C(local_0, 0x14, 1);
        }
        func_800D05E4(local_3, local_2, *local_0);
        break;
    case 0:
        local_0 = func_800D0CE0(0x1F4, param_1, param_2, &local_1);
        if (local_1 == 0) {
            func_8010108C(local_0, 0x14, 1);
        }
        break;
    case 4:
        local_0 = func_800D0CE0(0x136, param_1, param_2, &local_1);
        if (local_1 == 0) {
            func_8010108C(local_0, 0x14, 1);
        }
        break;
    case 2:
        local_0 = func_800D0CE0(0x220, param_1, param_2, &local_1);
        break;
    case 3:
        local_0 = func_800D0CE0(0x21B, param_1, param_2, &local_1);
        break;
    case 7:
        local_0 = func_800D0CE0(0x4E5, param_1, param_2, &local_1);
        break;
    case 8:
        local_0 = func_800D0CE0(0x3C6, param_1, param_2, &local_1);
        break;
    default:
        break;
    }
    func_800CFBC8(local_0, local_3, local_2, 0);
    if (param_3 != NULL && (*(u16 *)(param_3 + 0x18) & 1)) {
        func_80101074(*local_0);
        func_8010114C(param_3, 0xD, param_0);
    }
    return *local_0;
}

void func_800D0F9C(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5)
{
    f32 temp;
    f32 sp18[3];
    sp18[0] = (f32)arg1;
    sp18[1] = (f32)arg2;
    sp18[2] = (f32)arg3;
    func_800D0DAC(arg0, sp18, arg4, arg5);
}

void func_800D1000(u32 arg0, u32 arg1, f32* arg2, u32 arg3, Unk80132ED0* arg4)
{
    s32 sp44[3];
    s32 temp;
    f32 sp34[3];
    if ((func_800D0A9C(arg0, arg1) == 0) && (func_800D0B68(arg0, arg1) == 0))
    {
        func_800D0B08(arg0, arg1);
        func_800D053C(arg0, arg1);
        if (arg2 != NULL)
        {
            func_800EE904(sp44, arg2);
        }
        else
        {
            func_800D07CC(arg0, arg1, sp34);
            func_800EE904(sp44, sp34);
        }
        _chbaddiesetup_entrypoint_6(&func_800D0F9C, (arg0 << 0x10) | (arg1 & 0xFFFF), sp44[0], sp44[1], sp44[2], arg3, arg4);
    }
}

s32 func_800D10D4(s32 param_0, s32 param_1, s32 *param_2, s32 param_3, s32 param_4) {
    s32 sp20[4];

    if (func_800D0A9C(param_0, param_1) != 0) {
        return 0;
    }
    if (func_800D0B68(param_0, param_1) != 0) {
        return 0;
    }
    func_800D0B08(param_0, param_1);
    func_800D053C(param_0, param_1);
    if (param_2 != NULL) {
        return func_800D0DAC((param_0 << 0x10) | (param_1 & 0xFFFF), param_2, param_3, param_4);
    }
    func_800D07CC(param_0, param_1, sp20);
    return func_800D0DAC((param_0 << 0x10) | (param_1 & 0xFFFF), sp20, param_3, param_4);
}

void func_800D119C(s32 param_0, s32 param_1)
{
    if (func_800D0B68(param_0, param_1) == 0 && func_800D0A9C(param_0, param_1) != 0)
    {
        if (param_1 == 1)
        {
            func_800FFA88(func_800D0634(param_0, 1));
            func_800D05E4(param_0, 1, 0);
        }
        func_800D0B38(param_0, param_1);
    }
}

void func_800D1218(s32 param_0, s32 param_1, s32 param_2)
{
  s32 local_0;
  local_0 = func_800D0634(param_0, param_1);
  if (local_0 != 0)
  {
    local_0 = func_80106790(local_0);
    func_800EE7F8(param_2, local_0 + 4);
  }
}

void func_800D1254(s32 param_0, s32 param_1, s32 param_2)
{
  s32 local_0;
  s32 local_1;
  local_0 = func_800D0634(param_0, param_1);
  if (local_0 != 0)
  {
    local_1 = func_80106790(local_0);
    func_800EE7F8(local_1 + 4, param_2);
    func_80103014(local_1);
  }
}

s32 func_800D129C(u32 param_0)
{
  s32 local_1;
  s32 local_2;
  s32 local_3;
  local_2 = 0;
  local_1 = func_800D0820(0);
  local_3 = local_1;
  while (local_3 <= func_800D0894(0))
  {
    if (D_8011AB40[local_3 * 3 - 2] == param_0)
    {
      local_2++;
    }
    local_3++;
  }
  return local_2;
}

u32 func_800D1338(u32 param_0)
{
  s32 local_0;
  s32 local_1;
  local_1 = 0;
  local_0 = func_800D0820(0);
  while (func_800D0894(0) >= local_0)
  {
    if (param_0 == D_8011AB40[local_0 * 3 - 2])
    {
      if (func_800D0B68(local_0, 0) != 0)
      {
        local_1++;
      }
    }
    local_0++;
  }
  return local_1;
}

s32 func_800D13E8(s32 param_0, s32 param_1)
{
  s32 local_0;
  if (param_0 == 6)
  {
    local_0 = func_800D0820(param_0);
    while (func_800D0894(param_0) >= local_0)
    {
      if (((u8 *) D_8011AD08)[(local_0 * 2) - 2] == param_1)
      {
        local_0--;
        return local_0;
      }
      local_0++;
    }
  }
  return 0;
}
