#include "core2/1EAF950.h"

typedef struct { s32 pad[2]; u32 local_0:14; u32 pad2:18; } EntryD6060;
extern s16 D_8012BE62;
void aligned4_memmove(void *dst, void *src, int length);
typedef struct { u32 unk0_0 : 27; u32 unk0_27 : 4; u32 unk0_31 : 1; s32 unk4; u32 unk8_0 : 14; u32 unk8_14 : 1; u16 unk8_15 : 1; u16 unkA_0 : 4; u16 unkA_4 : 12; } S8012B800;
extern s16 D_8012BE64;
extern u8 unkA[];
typedef struct { u32 age:27, kind:4, pinned:1; void *data; union { struct { u32 unused:14, blocked:1, rest:17; } bits; struct { u16 flags; u8 unused, id; } fields; } extra; } LocalAsset;
extern s32 func_8001211C(void);
extern s32 func_800D56C4(void *);
extern void func_800D5E54(void *);
typedef struct { u32 age:27, type:4, busy:1; void *asset; u32 unused0:14, locked:1, active:1, unused1:16; } LocalEntry_800D6550;
extern void *func_800D5804(void *,s32);
typedef struct { u32 local_0 : 27; u32 local_1 : 4; u32 local_2 : 1; s32 local_3; u16 local_4 : 14; u16 local_5 : 2; u16 local_6; } local_type_800D66AC;
s16 D_8011B910 = -1;
typedef struct { u32 age:27,type:4,busy:1; ImageStruct *asset; u32 id:14,locked:1,active:1,refs:4,unused:4,slot:8; } LocalEntry_800D674C;
typedef struct { u8 pad[0x2C]; s32 off; } Img2C;
extern ImageStruct *func_800D5B34(s32);
typedef struct { u32 local_0:27; u32 local_1:4; u32 local_2:1; s32 local_3; u32 local_4:14; u32 local_5:1; u32 local_6:1; u32 local_7:16; } EntryD725C;
typedef struct { u8 local_0[10]; u16 local_1:4; u16 local_2:12; } local_type_800D6CEC;
extern s16 D_8012BE60;
typedef struct { u32 age:27, type:4, busy:1; void *asset; u32 unused0:16, references:4, unused1:12; } LocalEntry_800D6E54;
typedef struct { u8 pad0[0xA]; u16 fld : 4; u16 rest : 12; } E_D7050;
typedef union { u8 raw[1]; EntryD6060 EntryD6060[1]; ImageStruct ImageStruct[1]; S8012B800 S8012B800[1]; local_type_800D66AC local_type_800D66AC[1]; LocalEntry_800D674C LocalEntry_800D674C[1]; EntryD725C EntryD725C[1]; local_type_800D6CEC local_type_800D6CEC[1]; LocalEntry_800D6E54 LocalEntry_800D6E54[1]; E_D7050 E_D7050[1]; } Union_D_8012B800;
extern Union_D_8012B800 D_8012B800;
extern u32 D_8012B80A[];
extern s32 D_8012BFFC;
typedef struct { f32 local_0; u8 pad[16]; } EntryD75DC;
typedef struct { s32 local_0; EntryD75DC local_1[1]; } BlockD75DC;
extern s16 D_8012BFF6;
extern void *func_8001B798();
extern f32 func_800C7AE4(void *, s32, f32);
typedef struct { u8 pad0[0x24]; u32 unused0:16, flag0:1, flag1:1, flag2:1, unused1:4, field0:3, unused2:6; u32 unused3:26, field1:6; } LocalState_800D7754;
typedef struct { u32 pad0:21; s32 path:10; u32 flag0:1; u8 pad4[8]; f32 position; u8 pad10[4]; f32 speed; u8 pad18[0xC]; u32 pad24a:18,player:1,pad24b:4,focus:3,pad24c:6; u32 pad28:26,follow:6; u8 pad2C[4]; f32 startSpeed,endSpeed,start,end; u32 yawEnd:9,yawStart:9,pitchStart:9,pad40:5; u32 globalTime:1,mode:2,pitchEnd:9,pad44:20; } LocalSpline_800D7948;
typedef struct { u8 pad0[4]; s16 position[3]; } LocalMarker;
typedef union { struct { u32 pad0:1,direct:1,pad1:30; } flags; struct { u16 pad0; s16 position[3]; LocalMarker **marker; } data; } LocalFocus;
extern LocalFocus *D_8012C014;
extern s32 D_8012BF70[];
extern f32 D_8012C000;
extern LocalSpline_800D7948 *func_80105494();
extern void func_800C810C(void *,f32,f32 *,f32 *);
extern void func_8008FE68(f32 *);
extern u8 *func_80106790(s32);
extern f32 func_800F1DCC(f32,f32);
extern f32 func_800136E4(f32);
typedef struct { u8 local_0[0x24]; u32 local_1:16; u32 local_2:1; u32 local_3:1; u32 local_4:14; } FlagsD7DE8;
typedef struct { u8 pad0[0x10]; u32 flags; } LocalNode;
typedef struct { s32 count; LocalNode nodes[1]; } LocalList;
typedef struct { u8 pad0[0xC]; f32 position; u8 pad10[0x28]; f32 start, end; } LocalState_800D7E38;
extern s32 D_8011B920;
typedef struct { u32 pad0:21; s32 path:10; u32 initialized:1; u8 pad4[8]; f32 position,previous,speed; u32 pad18a:1,introSync:1,pad18b:30; u8 pad1C[4]; f32 wait; u32 pad24a:19,waitMode:4,pad24b:9; u32 pad28a:6,event:8,pad28b:2,sequence:9,resetSequence:1,pad28c:6; f32 cap; } LocalSpline_800D8070;
extern u8 D_8012BE6F[];
extern f32 func_800C8070(void *,f32,f32,s32 *);
extern f32 func_800C7E28(void *);
extern void func_800C7A68(void *,f32,f32 *);
extern f32 _glintrosyncDll_entrypoint_5(void);
extern f32 func_800D8FF8(void);
extern s32 _seqdefine_entrypoint_0(s32);
extern s32 func_800DA298(s32);
extern s32 _capod_entrypoint_16(f32);
extern void func_800DA524(s32);
typedef struct { u8 pad0[0x188]; s32 unk188; u8 pad18C[0x10]; s32 unk19C; u8 pad1A0[4]; s32 unk1A4; } S8012BE70;
extern s32 defrag(s32);
extern u8 D_8012BFF4[];

extern u8 D_8012BE70[];

s32 func_800D6060(s32 param_0) {
    s32 local_2;
    s32 local_0, local_1;
    u32 local_3;
    s32 local_4;
    local_0 = D_8012BE62 - 1;
    local_2 = 0;
    local_1 = 0;
    while (local_1 <= local_0) {
        local_2 = (local_0 + local_1) >> 1;
        local_3 = *(u32 *)((u8 *)&D_8012B800.EntryD6060[local_2] + 8);
        if ((s32)(local_3 >> 18) < param_0) {
            local_1 = local_2 + 1;
            if (local_1 < D_8012BE62) {
                if (param_0 < (s32)D_8012B800.EntryD6060[local_1].local_0) { local_2 = local_1; break; }
            } else { local_2 = D_8012BE62; break; }
        } else {
            local_0 = local_2 - 1;
            if (local_0 >= 0) {
                if ((s32)D_8012B800.EntryD6060[local_0].local_0 < param_0) break;
            } else { local_2 = 0; break; }
        }
    }
    if (local_2 < 0) local_2 = 0;
    else if (D_8012BE62 < local_2) local_2 = D_8012BE62;
    if (local_2 < D_8012BE62) {
        local_4 = D_8012BE62 - local_2;
        aligned4_memmove(&D_8012B800.EntryD6060[local_2 + 1], &D_8012B800.EntryD6060[local_2], local_4 * 12);
    }
    return local_2;
}

void func_800D61B4(ImageStruct *param_0)
{
    s16 n2;
    u16 h;
    s32 rest;
    rest = (D_8012BE62 - (param_0 - D_8012B800.ImageStruct)) - 1;
    if (rest > 0)
    {
        aligned4_memmove(param_0, param_0 + 1, rest * 12);
    }
    D_8012BE62 -= 1;
    *((u8 *) ((((u8 *) (&D_8012B800.ImageStruct[D_8012BE62]))) + 3)) &= 0xFFE1;
    h = *((u16 *) ((((u8 *) (&D_8012B800.ImageStruct[D_8012BE62]))) + 8));
    n2 = h;
    n2 = n2 | 0xFFFC;
    *((u16 *) ((((u8 *) (&D_8012B800.ImageStruct[D_8012BE62]))) + 8)) = n2;
}

s32 func_800D6254(param_0) s32 param_0; {
  s32 local_0;
  s32 local_1;
  s32 local_2;
  u32 local_3;
  local_1 = D_8012BE62 - 1;
  local_2 = 0;
  if (local_1 >= 0) {
loop_2:
        local_0 = (s32) (local_1 + local_2) >> 1;
        local_3 = (u32) (*(u32 *)((u8 *)((u32 *) D_8012B800.raw) + local_0 * 0xC + 8)) >> 0x12;
        if ((s32) local_3 < param_0) {
            local_2 = local_0 + 1;
            goto block_7;
        }
        if (param_0 < (s32) local_3) {
            local_1 = local_0 - 1;
            goto block_7;
        }
        return local_0;
block_7:
        if (local_1 >= local_2) {
            goto loop_2;
        }
    }
    return -1;
}

void func_800D62E4(void)
{
    S8012B800 *e;
    if (D_8012BE64 != 0) {
        e = &D_8012B800.S8012B800[func_800D6254()];
        if (e->unk0_27 == 2 && e->unk8_14 && !e->unk8_15) {
            e->unk8_14 = 0;
        }
        D_8012BE64 = 0;
    }
}

int func_800D6378(Actor *param_0)
{
  u32 local_0;
  switch (((*(u32*)param_0) << 27) >> 28) {
    case 1:
      break;
    case 2:
      local_0 = func_800D56C4(*(u32*)((char*)param_0 + 4));
      if (*(u8*)((char*)param_0 + 0xB) != 0) {
        func_800DBB9C(*(u8*)((char*)param_0 + 0xB) & 0xFF);
        *(u8*)((char*)param_0 + 0xB) = 0;
      }
      break;
    case 3: case 4: case 5: case 6: case 7: case 8: case 9:
      local_0 = func_800D56C4(*(u32*)((char*)param_0 + 4));
      break;
  }
  func_800D61B4(param_0);
  return local_0;
}

s32 func_800D6408(LocalAsset *param_0)
{
    s32 local_0;
    switch (param_0->kind) {
    case 6: case 7:
        if ((s32)(param_0->age + 1) < func_8001211C()) local_0 = func_800D56C4(param_0->data);
        else { func_800D5E54(param_0->data); local_0 = -1; }
        break;
    case 2:
        if ((s32)(param_0->age + 1) < func_8001211C()) local_0 = func_800D56C4(param_0->data);
        else if (!param_0->extra.bits.blocked && !(param_0->extra.fields.flags & 1) && !param_0->pinned) local_0 = func_800D56C4(param_0->data);
        else { func_800D5E54(param_0->data); local_0 = -1; }
        if (param_0->extra.fields.id) {
            func_800DBB9C(param_0->extra.fields.id & 0xFF);
            param_0->extra.fields.id = 0;
        }
        break;
    case 3: case 4: case 5: case 8: case 9:
        local_0 = func_800D56C4(param_0->data);
        break;
    case 1: break;
    }
    func_800D61B4(param_0);
    return local_0;
}

s32 func_800D6550(LocalEntry_800D6550 *param_0)
{
    switch (param_0->type) {
    case 1: case 9: return 0;
    case 3: case 4: case 5: case 8:
        if (!func_800D5E94(param_0->asset)) param_0->asset = func_800D5804(param_0->asset, 1);
        return 1;
    case 6: case 7:
        if ((s32)(param_0->age + 1) < func_8001211C()) {
            param_0->asset = func_800D5804(param_0->asset, 1);
            return 1;
        }
        return 0;
    case 2:
        if ((s32)(param_0->age + 1) < func_8001211C()) {
            if (!func_800D5E94(param_0->asset)) param_0->asset = func_800D5804(param_0->asset, 1);
        } else {
            if (!param_0->locked && !param_0->active && !param_0->busy) {
                if (!func_800D5E94(param_0->asset)) param_0->asset = func_800D5804(param_0->asset, 1);
                return 1;
            }
            return 0;
        }
        break;
    }
    return 0;
}

void func_800D66AC(void) {
    s32 local_0;
    for (local_0 = 0; local_0 < 136; local_0++) {
        D_8012B800.local_type_800D66AC[local_0].local_1 = 0;
        D_8012B800.local_type_800D66AC[local_0].local_4 = -1;
        D_8012B800.local_type_800D66AC[local_0].local_3 = 0;
    }
    D_8011B910 = -1;
    D_8012BE62 = 0;
}

ImageStruct *func_800D674C(s32 param_0)
{
    s32 local_0;
    s32 local_1;
    LocalEntry_800D674C *local_2;
    ImageStruct *local_3;
    void *local_4;
    local_0=func_800D6254(param_0);
    if (local_0!=-1) {
        D_8011B910=local_0;
        D_8012BE64=param_0;
        if (D_8012B800.LocalEntry_800D674C[local_0].type==2) {
            if (func_8001211C()==D_8012B800.LocalEntry_800D674C[local_0].age) {
                if (D_8012B800.LocalEntry_800D674C[local_0].locked) D_8012B800.LocalEntry_800D674C[local_0].active=1;
                else D_8012B800.LocalEntry_800D674C[local_0].locked=1;
            } else {
                if (func_8001211C()==D_8012B800.LocalEntry_800D674C[local_0].age+1) D_8012B800.LocalEntry_800D674C[local_0].busy=D_8012B800.LocalEntry_800D674C[local_0].locked || D_8012B800.LocalEntry_800D674C[local_0].active;
                D_8012B800.LocalEntry_800D674C[local_0].locked=1;
                D_8012B800.LocalEntry_800D674C[local_0].active=0;
            }
        }
        D_8012B800.LocalEntry_800D674C[local_0].age=func_8001211C();
        return D_8012B800.LocalEntry_800D674C[local_0].asset;
    }
    if ((u32)D_8012BE62>=135) return 0;
    local_1=func_800D58FC(param_0);
    local_3=func_800D5B34(param_0);
    if (!local_3) { D_8012BE64=0; return 0; }
    local_0=func_800D6060(param_0);
    local_2=&D_8012B800.LocalEntry_800D674C[local_0];
    D_8012BE62++;
    D_8011B910=local_0;
    local_2->age=func_8001211C();
    local_2->asset=local_3;
    local_2->refs=0;
    local_2->unused=0;
    local_2->id=param_0;
    D_8012BE64=param_0;
    switch(local_1) {
    case 0:
        local_2->type=2;
        local_2->locked=1;
        local_2->active=0;
        local_2->slot=0;
        local_4=((Img2C *)local_2->asset)->off ? (void *)((s32)local_2->asset + ((Img2C *)local_2->asset)->off) : 0;
        if (local_4) {
            local_2->slot=func_800DBA84();
            func_800DBBF8(local_2->slot,local_4);
        }
        break;
    case 1: local_2->type=1; break;
    case 3: case 10: local_2->type=4; break;
    case 5: local_2->type=3; break;
    case 6: local_2->type=5; break;
    case 7: local_2->type=6; break;
    case 8: local_2->type=7; break;
    case 2: local_2->type=8; break;
    case 9: local_2->type=9; break;
    }
    return local_3;
}

s32 func_800D6B0C(s32 param_0) {
    s32 local_0;
    local_0 = func_800D6254(param_0);
    if (local_0 != -1) {
        D_8012BE64 = param_0;
        if (D_8012B800.EntryD725C[local_0].local_1 == 2) {
            if (D_8012B800.EntryD725C[local_0].local_0 == func_8001211C()) {
                if (D_8012B800.EntryD725C[local_0].local_5) {
                    D_8012B800.EntryD725C[local_0].local_6 = 1;
                } else {
                    D_8012B800.EntryD725C[local_0].local_5 = 1;
                }
            } else {
                D_8012B800.EntryD725C[local_0].local_5 = 1;
            }
        }
        D_8012B800.EntryD725C[local_0].local_0 = func_8001211C();
        return D_8012B800.EntryD725C[local_0].local_3;
    }
    return 0;
}

int func_800D6C34()
{
  if (func_800D6254() != -1)
  {
    return 1;
  }
  else
  {
    return 0;
  }
}

void func_800D6C64()
{
  s32 i;
  s32 count;
  u32 new_var;
  count = D_8012BE62 - 1;
  for (i = count; i >= 0; i--)
  {
    new_var = ((u32 *) (&D_8012B800.raw[i * 12]))[2];
    new_var = new_var >> 0x12;
    if (((count = new_var) <= 0x1DDC) || (count >= 0x1ED8))
    {
      func_800D6408(&D_8012B800.raw[i * 12]);
    }
  }

}

s32 func_800D6CEC(void) {
    s32 local_0 = func_800D6254();
    if (local_0 != -1) {
        if (D_8012B800.local_type_800D6CEC[local_0].local_1) return 1;
        return func_800D6408(&D_8012B800.local_type_800D6CEC[local_0]);
    }
    return 2;
}

void func_800D6D68(void) {
    s32 var_s1;
    s32 var_s2;

    var_s1 = 0;
    var_s2 = 0;
    while (var_s1 < 0x20 && var_s2 < 8) {
        u8 *addr = (u8 *)&D_8012B800.raw + D_8012BE60 * 0xc;
        if (((*(u32 *)(addr + 8)) >> 18) != 0x3FFF) {
            if (!((*(u8 *)(addr + 0xA)) & 0xF)) {
                func_800D6550(addr);
                var_s2++;
            }
        }
        D_8012BE60++;
        if (D_8012BE60 >= D_8012BE62) {
            D_8012BE60 = 0;
        }
        var_s1++;
    }
}

void func_800D6E54(s32 param_0)
{
    s32 local_0;
    s32 local_1;
    s32 local_2;
    LocalEntry_800D6E54 *local_3;
    f32 local_4;
    static s32 D_8011B914 = 0;
    local_4 = D_8012BE62 * 0.007352941f;
    if (local_4 > 0.85f || !func_800A9F30() || param_0 != 1) {
        local_0 = func_8001211C();
        local_1 = local_0 - func_800A9F14(param_0);
        local_2 = param_0 == 1 ? 8 : D_8012BE62 - 1;
        for (; local_2 >= 0; local_2--) {
            local_3 = &D_8012B800.LocalEntry_800D6E54[D_8011B914];
            if (local_3->type && !local_3->references && ((s32)local_3->age < local_1 || (param_0 == 3 &&
                (local_3->type == 1 || local_3->type == 2 || local_3->type == 6 || local_3->type == 7 || local_3->type == 5 || local_3->type == 8)))) {
                func_800D6378(local_3);
                if (D_8011B914 > 0) D_8011B914--;
            }
            if (D_8011B914 >= D_8012BE62 - 1) D_8011B914 = 0;
            else D_8011B914++;
        }
    }
}

void func_800D7050(s32 param_0, s32 param_1) {
    if (param_1 != 0) { D_8012B800.E_D7050[param_0].fld++; }
    else { D_8012B800.E_D7050[param_0].fld--; }
}

void func_800D70D0(s32 param_0)
{
    func_800D7050(D_8011B910, param_0);
}

int func_800D70F8(s32 param_0, s32 param_1)
{
  s32 local_0;
  local_0 = func_800D6254(param_0);
  if (local_0 != -1)
  {
    func_800D7050(local_0 | 0, param_1);
    return 1;
  }
  return 0;
}

u32 func_800D7138(void) {
    s32 temp_v0;

    temp_v0 = func_800D6254();
    if (temp_v0 != -1) {
        return ((u32)*(u16 *)((u8 *)D_8012B80A + temp_v0 * 12)) >> 12;
    }
    return -1U;
}

void func_800D7184(s32 param_0, s32 param_1)
{
  u8 *ptr;
  unsigned char new_var;
  s32 val;
  if (param_1 != (0xFFF0 * 0))
  {
    ptr = ((u8 *) (((u8 *) D_8012B800.raw))) + (param_0 * 0xC);
    val = ptr[0xA];
    ptr[0xA] = (u8) ((val & 0xFFF0) | (((new_var = val) + 1) & 0xF));
    return;
  }
  ptr = ((u8 *) (((u8 *) D_8012B800.raw))) + (param_0 * 0xC);
  val = ptr[0xA];
  ptr[0xA] = (u8) ((val & (0xFFF0 & 0xFFFFFFFFu)) | (((ptr[0xA] & 0xFFu) - 1) & 0xF));
}

int func_800D71F4(s32 param_0)
{
  s16 local_0;
  s16 new_var;
  local_0 = D_8011B910;
  new_var = local_0;
  func_800D7184(new_var, param_0 | 0);
}

int func_800D721C(s32 param_0, s32 param_1)
{
  s32 local_0;
  local_0 = func_800D6254(param_0);
  if (local_0 != -1)
  {
    func_800D7184(local_0 | 0, param_1);
    return 1;
  }
  return 0;
}

int func_800D725C(s32 param_0) {
    s32 local_0;
    s32 local_1;
    s32 local_3;
    EntryD725C *local_2;
    local_0 = func_800D6254(param_0);
    if (local_0 == -1) {
        return (s32)func_800D674C(param_0);
    } else {
        D_8011B910 = local_0;
        D_8012B800.EntryD725C[local_0].local_0 = func_8001211C();
        local_2 = &D_8012B800.EntryD725C[local_0];
        local_1 = func_800D5950(param_0);
        local_3 = local_2->local_3;
        if (func_800D5EB4(param_0, local_3, local_1)) {
            return local_2->local_3;
        }
        return 0;
    }
}

u8 func_800D731C(void)
{
    s32 idx;

    idx = func_800D6254();
    if (idx != -1 && ((u32)(*((u32 *)((u8 *)D_8012B800.raw + idx * 12)) << 27) >> 28) == 2) {
        return ((u8 *)((u8 *)D_8012B800.raw + idx * 12))[11];
    }
    return 0;
}

void func_800D738C()
{
    func_800D58FC();
}

void func_800D73AC()
{
    func_800D59C0();
}

int func_800D73CC()
{
  s32 local_0;
  s32 local_1;
  local_0 = func_800D6254();
  if (local_0 == -1)
  {
    local_1 = 0 | 0;
  }
  else
  {
    local_1 = 1;
  }
  return local_1 | 0;
}

int func_800D7400()
{
  return (int)((s32 *) D_8012BE70);
}

int func_800D740C()
{
  D_8012BFFC = 0;
}

void func_800D7418()
{
    _glsplineDll_entrypoint_0(&D_8012BE70);
}

void func_800D743C()
{
    _glsplineDll_entrypoint_1(&D_8012BE70);
}

void func_800D7460()
{
    func_800D743C();
    func_800D7418();
}

s32 func_800D7488(param_0, param_1) s16 param_0; s16 param_1;
{
  s32 local_0;
  char *new_var;
  s32 local_1;
  s16 *new_var2;
  s32 local_2;
  local_1 = (*((s32 *) (((char *) D_8012BE70) + 0x188)) += 1);
  new_var2 = (s16 *) (((char *) D_8012BE70) + 0x184);
  local_1 = local_1 * 2;
  local_0 = func_8001B710(*new_var2, local_1);
  local_2 = func_8001B710(*((s16 *) (((char *) D_8012BE70) + 0x186)), (*((s32 *) (((char *) D_8012BE70) + 0x188))) * 2);
  new_var = ((char *) D_8012BE70) + 0x188;
  *((s16 *) ((local_0 + ((*((s32 *) new_var)) * 2)) - 2)) = param_0;
  *((s16 *) ((local_2 + ((*((s32 *) new_var)) * 2)) - 2)) = param_1;
  return (*((s32 *) new_var)) - 1;
 do { } while (0);
}

void *func_800D7520(s32 param_0)
{
    if (param_0 == -1) {
        return 0;
    }
    return func_8001B798(*(s16 *)((u8 *) func_8001B798(*(s16 *)((u8 *) D_8012BFF4)) + (param_0 << 1)));
}

u8 *func_800D7570(s32 param_0)
{
    s32 *local_1;
    u8 *local_2;
    local_1 = func_8001B798(*(s16 *)((s32 *) &D_8012BFF6));
    if (param_0 == -1) {
        return NULL;
    }
    local_2 = func_8001B798(*(s16 *)((char *)local_1 + param_0 * 2));
    if (*(s32 *)local_2 == 0) {
        return NULL;
    }
    return local_2 + 4;
}

s32 func_800D75DC(s32 param_0, f32 param_1) {
    s16 *local_0;
    BlockD75DC *local_1;
    EntryD75DC *local_2;
    s32 local_3;
    local_0 = func_8001B798(D_8012BFF6);
    if (param_0 == -1) return 0;
    local_1 = func_8001B798(local_0[param_0]);
    if (local_1->local_0 == 0) return 0;
    for (local_2 = local_1->local_1, local_3 = 0; local_2 < local_1->local_0 + local_1->local_1 &&
         (local_2->local_0 < param_1 || (param_1 == 1.0f && 1.0f == local_2->local_0)); local_2++) {
        local_3++;
    }
    return local_3;
}

f32 func_800D7708(s32 param_0, s32 param_1, s32 param_2)
{
    void *local_0;
    f32 local_4;
    f32 local_5;
    local_0 = func_800D7520(param_0);
    local_4 = func_800C7AE4(local_0, param_1, 1.0f);
    local_5 = (f32)param_2;
    local_5 = local_5 / 4;
    return local_4 / local_5;
}

void func_800D7754(void *param_0, s32 param_1)
{
    LocalState_800D7754 *local_0 = func_80105494(param_0);
    switch (param_1) {
    case 1:
        local_0->field1 = 0;
        local_0->field0 = 0;
        local_0->flag2 = 1;
        local_0->flag0 = 1;
        local_0->flag1 = 1;
        break;
    case 2:
        local_0->field1 = 0;
        local_0->field0 = 0;
        local_0->flag2 = 0;
        local_0->flag0 = 0;
        break;
    case 3:
        local_0->field1 = 0;
        local_0->field0 = 0;
        local_0->flag2 = 0;
        local_0->flag0 = 1;
        break;
    case 4:
        local_0->field1 = 0;
        local_0->field0 = 0;
        local_0->flag2 = 0;
        local_0->flag1 = 0;
        break;
    case 5:
        local_0->field1 = 0;
        local_0->field0 = 0;
        local_0->flag2 = 0;
        local_0->flag1 = 1;
        break;
    case 6:
        local_0->field1 = 0;
        local_0->field0 = 0;
        local_0->flag2 = 0;
        local_0->flag0 = 0;
        local_0->flag1 = 0;
        break;
    case 7:
        local_0->field1 = 0;
        local_0->field0 = 0;
        local_0->flag2 = 0;
        local_0->flag0 = 1;
        local_0->flag1 = 1;
        break;
    }
}

void func_800D7900(s32 arg0) 
{
}
void func_800D7908(void *param_0, void *param_1)
{
    f32 local_0[3];
    func_800A516C(local_0, param_1, (void *)((char *)param_0 + 4));
    *(f32 *)((char *)param_0 + 84) = local_0[1];
    *(f32 *)((char *)param_0 + 80) = local_0[0];
}

void func_800D7948(u8 *param_0,s32 param_1,s32 param_2,s32 param_3)
{
    LocalSpline_800D7948 *local_0;
    f32 local_1[3];
    f32 local_2[3];
    s32 local_3;
    f32 local_4[3];
    LocalFocus *local_5;
    LocalMarker *local_6;
    f32 local_7[3];
    f32 local_8;
    f32 local_9;
    local_0=func_80105494(param_0);
    if (param_1 & 0x300) {
        func_800C810C(func_800D7520(local_0->path),local_0->position,local_1,local_2);
        if (param_1 & 1) {
            if (param_1 & 0x100) *(f32 *)(param_0+0x54)=local_2[1];
            if (param_1 & 0x200) *(f32 *)(param_0+0x50)=local_2[0];
        } else {
            if (param_1 & 0x100) {
                if (local_2[1]>=180.0f) *(f32 *)(param_0+0x54)=local_2[1]-180.0f;
                else *(f32 *)(param_0+0x54)=local_2[1]+180.0f;
            }
            if (param_1 & 0x200) *(f32 *)(param_0+0x50)=360.0f-local_2[0];
        }
    }
    if (local_0->focus) {
        local_5=(LocalFocus *)((u8 *)D_8012C014+local_0->focus*sizeof(LocalFocus)-sizeof(LocalFocus));
        if (local_5->flags.direct) {
            for (local_3=0;local_3<3;local_3++) local_4[local_3]=local_5->data.position[local_3];
        } else {
            for (local_3=0;local_3<3;local_3++) local_4[local_3]=(*local_5->data.marker)->position[local_3];
        }
        func_800D7908(param_0,local_4);
    } else if (local_0->follow) {
        func_800D7908(param_0,(f32 *)(func_80106790(D_8012BF70[local_0->follow])+4));
    } else if (local_0->player) {
        func_8008FE68(local_7);
        func_800D7908(param_0,local_7);
    } else {
        local_8=local_0->globalTime ? D_8012C000 : local_0->position;
        if (local_0->start<=local_8 && local_8<local_0->end) {
            local_9=(local_8-local_0->start)/(local_0->end-local_0->start);
            if (local_0->mode & 1) {
                if (param_1 & 0x800) *(f32 *)(param_0+0x54)=func_800136E4(func_800F1DCC(local_0->yawEnd,local_0->yawStart)*local_9+local_0->yawStart);
                if (param_1 & 0x1000) *(f32 *)(param_0+0x50)=func_800136E4(func_800F1DCC(local_0->pitchEnd,local_0->pitchStart)*local_9+local_0->pitchStart);
            }
            if (local_0->mode & 2) local_0->speed=(local_0->endSpeed-local_0->startSpeed)*local_9+local_0->startSpeed;
        } else if (local_0->start!=0.0f || local_0->end!=0.0f) {
            local_0->start=0;
            local_0->globalTime=0;
            local_0->end=0;
        }
    }
    func_800D7900(param_0);
    *(f32 *)(param_0+0x48)=*(f32 *)(param_0+0x54);
    *(f32 *)(param_0+0x44)=*(f32 *)(param_0+0x50);
}

s32 func_800D7DE8(u8 *param_0) {
    FlagsD7DE8 *local_0;
    s32 local_1;
    s32 local_2;
    local_0 = (FlagsD7DE8 *)func_80105494(param_0);
    return (local_0->local_2 ? 0x800 : 0x100) + (local_0->local_3 ? 0x1000 : 0x200);
}

s32 func_800D7E38(void *param_0, s32 param_1, s32 param_2, s32 param_3, s32 param_4, s32 param_5)
{
    s32 local_9[2];
    s32 local_8;
    s16 *local_0;
    s32 local_1;
    LocalNode *local_2;
    f32 local_3;
    LocalState_800D7E38 *local_4;
    LocalList *local_5;
    LocalNode *local_6;
    s32 local_7;
    local_0 = func_8001B798(D_8012BFF6);
    local_1 = 0;
    local_4 = func_80105494(param_0);
    local_5 = func_8001B798(local_0[param_1]);
    local_8 = local_5->count;
    if (!local_8) return 0;
    local_2 = (param_2 == -9999 ? local_8 - 1 : param_2) + local_5->nodes;
    local_7 = param_5 * 20;
    local_6 = (param_3 == -9999 ? local_8 + param_4 : param_3) + local_5->nodes;
    while (local_2 != local_6 && local_1 != 1) {
        if ((local_7 >= 20 && !(local_2->flags & 1)) || (local_7 < 0 && (local_2->flags & 1) == 1)) {
            if (D_8011B920 == 1) local_3 = local_4->position;
            local_1 = _glsplinenode_entrypoint_1(((s32 *) D_8012BE70), param_0, local_2, local_5);
            if (local_4->start != 0.0f || local_4->end != 0.0f) {
                if (!(local_4->position >= local_4->start && local_4->position < local_4->end)) {
                    local_4->start = 0.0f;
                    local_4->end = 0.0f;
                }
            }
        }
        local_2 = (LocalNode *)((u8 *)local_2 + local_7);
    }
    if (D_8011B920 == 1 && local_1 == 1) local_4->position = 1e-05f + local_3;
    return local_1;
}

s32 func_800D8070(u8 *param_0,s32 param_1,s32 param_2,s32 param_3)
{
    s32 local_0;
    s32 local_1;
    s32 local_2;
    LocalSpline_800D8070 *local_3;
    f32 local_4;
    void *local_5;
    s16 *local_6;
    s32 local_7;
    s32 local_8;
    local_2=0;
    local_3=func_80105494(param_0);
    local_4=local_3->speed;
    if (local_3->path==-1) return 0;
    local_3->previous=local_3->position;
    local_0=func_800D75DC(local_3->path,local_3->position);
    if (local_3->wait==0.0f && !local_3->waitMode && !local_3->sequence && !local_3->event && local_3->cap==0.0f) {
        local_6=func_8001B798((*((s16 *) D_8012BFF4)));
        local_5=func_8001B798(local_6[local_3->path]);
        local_3->position=func_800C8070(local_5,local_3->position,local_4,&local_2);
        func_800C7A68(local_5,local_3->position,(f32 *)(param_0+4));
    } else {
        if (local_3->wait!=0.0f) {
            local_3->wait-=local_3->introSync ? _glintrosyncDll_entrypoint_5() : func_800D8FF8();
            if (local_3->wait<0.0f) local_3->wait=0.0f;
        }
        if (local_3->sequence && func_800DA298(_seqdefine_entrypoint_0(local_3->sequence-1))) {
            if (local_3->resetSequence) {
                local_3->resetSequence=0;
                func_800DA524(_seqdefine_entrypoint_0(local_3->sequence-1));
            }
            local_3->sequence=0;
        }
        if (local_3->event && !D_8012BE6F[local_3->event]) local_3->event=0;
        if (local_3->cap>0.0f && _capod_entrypoint_16(local_3->cap)) local_3->cap=0.0f;
    }
    local_1=func_800D75DC(local_3->path,local_3->position);
    if (!local_3->initialized) {
        local_3->initialized=1;
        *(f32 *)(param_0+0x48)=*(f32 *)(param_0+0x54);
        *(f32 *)(param_0+0x44)=*(f32 *)(param_0+0x50);
    }
    if (local_0==local_1 && local_2==0) {
        func_800D7948(param_0,param_1,param_2,param_3);
    } else {
        local_7=func_800D7DE8(param_0);
        if (local_4>0.0f) {
            if (!local_2) {
                if (func_800D7E38(param_0,local_3->path,local_0,local_1,0,1)==2) D_8012BFFC=1;
            } else if (!func_800D7E38(param_0,local_3->path,local_0,-9999,0,1)) {
                func_800D7E38(param_0,local_3->path,func_800D75DC(local_3->path,func_800C7E28(func_800D7520(local_3->path))),local_1,0,1);
            }
        } else if (local_4<0.0f) {
            if (!local_2) {
                func_800D7E38(param_0,local_3->path,local_0-1,local_1-1,0,-1);
            } else if (!func_800D7E38(param_0,local_3->path,local_0-1,-1,0,-1)) {
                func_800D7E38(param_0,local_3->path,-9999,local_1-1,0,-1);
            }
        }
        local_8=func_800D7DE8(param_0);
        if (local_7==local_8 || (local_7!=local_8 && local_7!=(param_1 & 0x3F00))) {
            func_800D7948(param_0,param_1,param_2,param_3);
        } else {
            func_800D7948(param_0,(param_1 & ~0x3F00) | (local_8 & 0x3F00),param_2,param_3);
        }
    }
    return 1;
}

s32 func_800D8588(s32 param_0, s32 param_1, s32 param_2, s32 param_3)
{
  s32 local_1;
  u8 *local_0;

  local_1 = 0;
  local_0 = func_80105494();
  do {
    ((s32 *) D_8012BE70)[99] = 0;
    local_1 += func_800D8070(param_0, param_1, param_2, param_3);
  } while (((s32 *) D_8012BE70)[99] != 0);
  if (*local_0)
  {
    _glsplinecs_entrypoint_1(D_8012BE70, param_0);
  }
  return (local_1) ? (1) : (0);
}

int func_800D8648(s32 param_0, s32 param_1)
{
  s32 local_0;
  local_0 = func_800D7520(param_0);
  func_800EE7F8(local_0 + 0x14, param_1);
}

void func_800D8674(void)
{
    s32 i;
    if ((*((S8012BE70 *) D_8012BE70)).unk1A4 != 0) {
        (*((S8012BE70 *) D_8012BE70)).unk1A4 = defrag((*((S8012BE70 *) D_8012BE70)).unk1A4);
    }
    for (i = 0; i < (*((S8012BE70 *) D_8012BE70)).unk188; i++) {
    }
    if ((*((S8012BE70 *) D_8012BE70)).unk19C != 0) {
        (*((S8012BE70 *) D_8012BE70)).unk19C = defrag((*((S8012BE70 *) D_8012BE70)).unk19C);
    }
}

void func_800D86F0(s32 param_0, f32 param_1, s32 param_2)
{
  s32 local_0;
  s32 local_1;
  local_0 = func_8001B798(*(s16 *) D_8012BFF4);
  local_1 = func_8001B798((s16)((s16 *)local_0)[param_0]);
  func_800C7A68(local_1, param_1, param_2);
}

void func_800D8744(void) {
    f32 local_0;

    *(f32 *)&D_8012BE70[0x194] = *(f32 *)&D_8012BE70[0x190];

    if (D_8012BE70[0x1A8] != 0) {
        local_0 = _glintrosyncDll_entrypoint_5();
    } else {
        local_0 = func_800D8FF8();
    }
    D_8012C000 = *(f32 *)&D_8012BE70[0x190] + local_0 * 60.0f;
}

void func_800D87B0()
{
    _glsplineDll_entrypoint_2(&D_8012BE70);
}

int func_800D87D4(s32 *param_0, s32 param_1)
{
  D_8012BF70[param_1] = *param_0;
}

int func_800D87EC(s32 param_0)
{
  return D_8012BF70[param_0];
}

void func_800D8800(void) {
}

int func_800D8808(s32 param_0)
{
  if (param_0 != 0)
  {
    ((s8 *) D_8012C014)[(param_0 - 1) * 12] &= ~0x80;
  }
}
