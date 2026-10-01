#include "core2/1ECD170.h"

extern f32 bastick_distance(s32);
extern f32 func_8009BFCC(s32);
extern f32 yaw_get(s32);
extern f32 baroll_get(s32);
extern f32 func_800964DC(s32);
extern f32 func_80096364(s32);
extern s32 func_8009E674();
extern s32 func_8008E124();
extern s32 func_8008E974();
extern s32 func_800F8004();
extern s32 func_8008DAA8();
extern s32 func_800F54E4(void);
extern s32 func_800F5410(s32);
extern s32 func_800F6D24(s32);
typedef struct { s32 local_0; s32 (*local_1)(void); } SizeF;
extern SizeF D_801235D0[];
extern void func_8009C128();
extern void func_800EFB24();
extern void func_8009C1F8();
extern void func_80099544(void *);
extern void *defrag(void *);
s32 func_800F3ED0();
s32 func_800F40EC();
void func_800F44DC();

void func_800F3880(s32 arg0)
{
    func_80098E64();
    heap_free(arg0);
}
int func_800F38A8(s32 param_0, s32 param_1)
{
    return (((param_1 & 4) != 0) && func_800F40EC(param_0) == 2) ||
           (((param_1 & 2) != 0) && func_800F40EC(param_0) == 1) ||
           (((param_1 & 1) != 0) && func_800F3ED0(param_0) == 10);
}

s32 func_800F3930(param_0, param_1, param_2) u8 * param_0; s32 param_1; s32 param_2; {
    s32 sp24;

    sp24 = func_800F38A8(param_0, param_2);
    if (func_800F9184() != 0) {
        return 0;
    }
    if (func_800F6774((*(s32 *)((s8 *)(param_0) + (0x184)))) == 0) {
        return 0;
    }
    if (func_800F6CC8((*(s32 *)((s8 *)(param_0) + (0x184)))) != 0) {
        return 0;
    }
    if (func_8008EF3C(param_0, 0) == 0x13) {
        return 0;
    }
    if ((player_isStable(param_0) == 0) && (sp24 == 0)) {
        return 0;
    }
    if (func_800F64A4((*(s32 *)((s8 *)(param_0) + (0x184))), 0x12000) != 0) {
        return 0;
    }
    if (func_800F64A4((*(s32 *)((s8 *)(param_0) + (0x184))), param_1) == 0) {
        return 0;
    }
    if (baflag_isTrue(param_0, 0x3F) != 0) {
        return 0;
    }
    if (func_8009CA70(param_0, bs_getCurrentState(param_0), 0x20) != 0) {
        return 0;
    }
    if (func_800A9C98() != 0) {
        return 0;
    }
    return 1;
}

int func_800F3A78(s32 param_0, s32 param_1, f32 param_2[3])
{
  s32 local_1;
  if (func_800F3930(param_0, param_1) == 0)
    {
        return 0;
    }
  if (func_8009E674(param_0, 0x8000) != 0)
    {
        return 0;
    }
  local_1 = func_800F38A8(param_0, param_2);
  if (bastick_distance(param_0) != 0.0f)
    {
        if (local_1 == 0)
        {
            return 0;
        }
    }
  if (func_800F5FA8(*(s32 **)(param_0 + 0x184)) == 0)
    {
        return 0;
    }
  if (func_800A9C98() != 0)
    {
        return 0;
    }
  return 1;
}

f32 func_800F3B3C(s32 param_0, s32 param_1, s32 param_2)
{
    s32 local_1C;

    func_8009E154(param_0, param_2, param_1);
    func_8008E9B8(param_0, &local_1C);
    return (f32) ((s32 *) local_1C)[param_2];
}

void func_800F3B90(s32 param_0, s32 param_1)
{
  func_800F3B3C(param_0, param_1, 0);
}

void func_800F3BB0()
{
    func_8009C128();
}

void func_800F3BD0(s32 param_0,s32 param_1,f32 *param_2)
{
    switch(param_1) {
    case 1: func_80092D44(param_0,param_2); break;
    case 2: func_80092E5C(param_0,param_2); break;
    case 3: func_80092C00(param_0,param_2); break;
    case 4: func_80092C24(param_0,param_2); break;
    case 6: func_80092C48(param_0,param_2); break;
    case 5:
        func_8009C128(param_0,param_2);
        switch(func_800A3274(param_0)) {
        case 2: param_2[1]+=85.0f; break;
        case 15: param_2[1]+=90.0f; break;
        case 6: param_2[1]+=85.0f; break;
        case 7: param_2[1]+=130.0f; break;
        case 14: param_2[1]+=575.0f; break;
        case 16: param_2[1]+=130.0f; break;
        case 12: param_2[1]+=45.0f; break;
        case 17: param_2[1]+=40.0f; break;
        case 18: param_2[1]+=130.0f; break;
        case 19: param_2[1]+=400.0f; break;
        case 11: param_2[1]+=55.0f; break;
        case 1:
            if (func_800F40EC(param_0)==2 || func_800F6720(*(s32 *)((u8 *)param_0+0x184))) param_2[1]+=70.0f;
            else param_2[1]+=100.0f;
            break;
        default: param_2[1]+=100.0f; break;
        }
        break;
    case 7: func_80092DC0(param_0,param_2); break;
    case 8: func_8009C188(param_0,param_2); break;
    case 9: func_80092D9C(param_0,param_2); break;
    case 0:
    default: func_800F3BB0(param_0,param_2); break;
    }
}

void func_800F3E84(s32 param_0, f32 *param_1)
{
  param_1[0] = func_8009BFCC(param_0);
  param_1[1] = yaw_get(param_0);
  param_1[2] = baroll_get(param_0);
}

s32 func_800F3ED0(param_0) s32 param_0; {
    s32 local_0;
    s32 local_1;

    local_0 = bs_getCurrentState(param_0);
    if (baflag_isTrue(param_0, 0x1B) != 0) {
        return 0xD;
    }
    if (baflag_isTrue(param_0, 0x17) != 0) {
        return 4;
    }
    if (func_8009CBDC(param_0, local_0) == 9) {
        return 0xA;
    }
    if (func_8009CBDC(param_0, local_0) == 0x12) {
        return 0xC;
    }
    if (func_8009CBDC(param_0, local_0) == 0x13) {
        return 0xE;
    }
    if (func_8009CBDC(param_0, local_0) == 8) {
        return 9;
    }
    if (func_8009CBDC(param_0, local_0) == 0xA) {
        return 5;
    }
    if (baflag_isTrue(param_0, 9) != 0) {
        return 1;
    }
    if (func_8009E674(param_0, 0x80) != 0) {
        local_1 = _bashoes_entrypoint_1(param_0);
        switch (local_1) {                          
        case 3:                                     
            return 6;
        case 4:                                     
            return 0x10;
        case 5:                                     
            return 0xF;
        }
    }
    {
        switch (local_0) {                             
        case 0xE: ;                                   
        case 0x34:                                  
        case 0x3C: ;                                  
        case 0x3F:                                  
        case 0x41: ;                                  
        case 0x44:                                  
        case 0x120:                                 
            return 1;
        case 0x1A: ;                                  
        case 0x1B:                                  
        case 0x1C: ;                                  
        case 0x1D:                                  
        case 0x1E: ;                                  
        case 0xA4:                                  
        case 0xA5:                                  
            return 3;
        case 0x8: ;                                   
        case 0x15:                                  
        case 0x16: ;                                  
        case 0x17:                                  
        case 0x45:                                  
            if (bastatetimer_isActive(param_0, 3) != 0) {
                return 6;
            }
            return 8;
        case 0xB:                                   
            return 2;
        default:                                    
            if (func_8008EF3C(param_0, 0) != 0) {
                return 0xB;
            }
            return 0;
        }
    }
}

s32 func_800F40EC(param_0) s32 param_0;
{
  s32 state;
  f32 val1;
  f32 val2;
  state = bs_getCurrentState();
  if (func_800A3274(param_0) != 0xC)
  {
    goto block_5;
  }
  if (func_80096544(param_0) == 0)
  {
    return 0;
  }
  val1 = func_800964DC(param_0);
  val2 = func_80096364(param_0);
  if ((val1 - val2) < 50.0f)
  {
    return 0;
  }
  goto block_5;
  block_5:
  if ((func_8009CA70(param_0, state, 1) != 0) || (func_8009CA70(param_0, state, 0x40000) != 0))
  {
    return 1;
  }

  if (state == 5)
  {
    if (_bsjump_entrypoint_16(param_0) != 0)
    {
      return 1;
    }
    return 0;
  }
  if (func_8009CA70(param_0, state, 2) != 0)
  {
    return 2;
  }
  return 0;
}

int func_800F4200(s32 param_0, s32 param_1)
{
  f32 local_0[3];
  f32 local_1[3];
  func_8009C128(param_0, local_0);
  func_8009C1CC(param_0, local_1);
  func_800EE780(param_1, local_0, local_1);
}

s32 func_800F4244(Actor *param_0)
{
    return (*(s32 *)((s8 *)(param_0) + (0x17C)));
}

s32 func_800F424C(u8 *param_0) {
    s32 temp_v0;
    s32 sp24;
    s32 sp1C;
    s8 _sfpad[8];
    s32 temp_v0_2;
    if ((*(s32 *)((s8 *)(param_0) + (0x17C))) == 0) {
        return 0;
    }
    if (func_8009E674(param_0, 4) != 0) {
        return 0;
    }
    if (func_8009E674(param_0, 0x2000) != 0) {
        return 0;
    }
    if (func_8008E124(param_0) != 0) {
        return 0;
    }
    if (func_8008E974(param_0) == 0) {
        return 0;
    }
    if (func_800F8004((*(s32 *)((s8 *)(param_0) + (0x184)))) != 0) {
        return 0;
    }
    if (func_8008DAA8(param_0) == 0) {
        temp_v0 = func_800F54E4();
        if (temp_v0 != -1) {
            sp24 = temp_v0;
            sp1C = func_800F5410(temp_v0) == 0x11;
            temp_v0_2 = func_800F6D24(sp24);
            if ((sp1C != 0) && (temp_v0_2 != 0)) {
                return 0;
            }
        }
    }
    return 1;
}

s32 func_800F4354(s32 param_0)
{
    if (D_801235D0[param_0].local_0 >= 0) return D_801235D0[param_0].local_0;
    D_801235D0[param_0].local_0 = D_801235D0[param_0].local_1();
    return D_801235D0[param_0].local_0;
}

u8 *func_800F43A8(s32 param_0) {
    s32 local_1;
    u8 *local_0;
    unsigned int local_2;
    s32 local_3;
    s32 local_4;

    local_1 = 0x19C;
    local_0 = heap_alloc(0x19C);
    for (local_2 = 0; local_2 < 0x56; local_2++) {
        local_3 = func_800F4354((s32)local_2);
        local_4 = local_3 % 4;
        if (local_4 != 0) {
            local_4 = 4 - local_4;
        } else {
            local_4 = 0;
        }
        local_1 = local_1 + local_3 + local_4;
        local_0 = heap_realloc(local_0, local_1);
    }
    bzero(local_0, local_1);
    local_1 = 0x19C;
    for (local_2 = 0; local_2 < 0x56; local_2++) {
        *(u8 **)(local_0 + (local_2 << 2)) = local_0 + local_1;
        local_3 = func_800F4354((s32)local_2);
        local_4 = local_3 % 4;
        if (local_4 != 0) {
            local_4 = 4 - local_4;
        } else {
            local_4 = 0;
        }
        local_1 = local_1 + local_3 + local_4;
    }
    ((s32 *)local_0)[0x60] = 0;
    ((s32 *)local_0)[0x61] = param_0;
    func_80098C48(local_0);
    func_800F44DC(local_0, 1);
    return local_0;
}

void func_800F44DC(param_0, param_1) s32 param_0; s32 param_1; {
  s32 local_0;
  s32 local_1;
  *(s32 *)(param_0 + 0x17c) = param_1;
  local_1 = func_800A4C88(param_0);
  if (param_1 != 0) {
    local_0 = 2;
  } else {
    local_0 = 1;
  }
  func_8010F9C0(local_1, local_0);
}

void func_800F4524(s32 param_0, s32 param_1)
{
  s32 *local_0;
  local_0 = (s32 *) (param_0 + 0x17C);
  local_0++;
  *local_0 = param_1;
  local_0--;
}

int func_800F452C(s32 param_0)
{
  s32 local_0;
  local_0 = param_0 | 0;
  func_8009C0BC(local_0);
  func_80095C94(local_0);
  func_800A10A0(local_0);
  func_800A4030(local_0);
  func_800A4B08(local_0);
  func_800A380C(local_0);
}

int func_800F457C(s32 param_0, s32 param_1)
{
  if (!param_1)
  {
    func_8009CCA4(param_0);
  }
  else
  {
    func_8009CCFC(param_0);
  }
}

s32 func_800F45B0(Actor *this, Gfx **dl, Mtx **m){
    func_8009CCFC(this, dl, m);
    func_8009CD70(this, m);
}

void func_800F45E0(s32 param_0, s32 *param_1)
{
  func_8009BF5C(param_0, param_1[0]);
  yaw_setIdeal(param_0, param_1[1]);
  baroll_setIdeal(param_0, param_1[2]);
  func_8009BFBC(param_0);
  yaw_applyIdeal(param_0);
  baroll_applyIdeal(param_0);
}

s32 func_800F4648(s32 param_0, s32 param_1) {
    f32 local_0[3];
    f32 local_1[3];

    func_8009C128(param_0, local_0);
    func_800EFB24(local_1, param_1, local_0);
    func_8009C1F8(param_0, local_1);
}

s32 func_800F468C(Actor *this)
{
  if (*(s32*)((char*)this + 0x17C) != 0 && *(s32*)((char*)this + 0x180) == 0 && func_800EA09C() == 2)
    {
        func_800991B0(this);
    }
}

u8 *func_800F46D8(u8 *param_0) {
    u8 local_3[8];
    u8 *local_0;
    s32 local_1;
    int local_2;
    func_80099544(param_0);
    local_0 = param_0;
    param_0 = defrag(param_0);
    if (local_0 == param_0) return param_0;
    local_1 = param_0 - local_0;
    for (local_2 = 0; local_2 < 0x56; local_2++) {
        *(u8 **)((u32)param_0 + (local_2 << 2)) += local_1;
    }
    return param_0;
}
