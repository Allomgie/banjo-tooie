#include "common.h"
#include <vector.h>

extern s32 D_80136EC0;
typedef struct { u8 pad[0x7c]; u32 unused:20, index:12; } LocalActor_80105494;
typedef struct { u32 pad0:21; s32 local_0:10; u32 pad1:1; u8 pad2[8]; f32 local_1, local_2, local_3; u8 local_4:1; u8 local_5:1; u8 pad3:6; u8 pad4[14]; u8 pad5:2; u8 local_6:1; u8 pad6:5; u8 local_7:3; u8 pad7:5; } Motion105;
extern s32 func_800D7DE8();
extern void *func_800D7520(s32);
extern void func_800C810C(void *, f32, f32 *, f32 *);
typedef struct { u8 pad[0x7C]; u32 pad0:20; u32 local_0:12; } Actor105;
extern Motion105 *freelist_next(void *, s32 *);
extern s32 func_800E6A00(void);
extern void rare_memset(void *, s32, s32);
extern void freelist_erase(void *param_0, s32 param_1);
typedef struct { u8 pad_0[0x7C]; u32 local_0 : 20; u32 local_1 : 12; } Struct80105634;
typedef struct { s32 a : 21; s32 f : 10; s32 b : 1; u8 pad4[8]; f32 unkC; f32 unk10; } S_1056EC;
extern void func_800D86F0(s32, f32, void *);
typedef struct { s32 local_0:21; s32 local_1:10; u32 local_2:1; u8 local_3[8]; f32 local_4; f32 local_5; f32 local_6; u8 local_7[0x10]; u32 local_8:3; u32 local_9:29; } local_type;
typedef struct {u8 local_0[0x74]; u32 local_1:27; u32 local_2:1; u32 local_3:4;} local_actor;
extern void func_800D8648(s32, f32 *);
typedef struct { u8 pad0[0x27]; u8 f0 : 2; u8 bit : 1; u8 f2 : 5; } S_105BE0;
extern s32 D_80136ED0;
extern void *freelist_at(void *, s32);
extern void vector_free();
extern void _glidmake_entrypoint_4(int a);
typedef struct { u8 pad[0x14]; u16 id; } LocalMarker;
typedef struct { LocalMarker *marker; u8 pad4[0x6C]; u32 unused0:7, has_secondary:1, unused1:20, reset:1, unused2:3; u32 unused3:9, blocked:1, unused4:22; u8 pad78[4]; u32 unused5:19, update:1, unused6:12; } LocalActor_801061D8;
typedef struct { void *handle; Vector *entries; } LocalState;
typedef struct { s32 key; s16 type, argument; u8 data[0xA0]; } LocalEntry;
typedef struct { void *unused0; void (*update)(void *, s32, s16); void *unused1[2]; } LocalCallbacks;
extern LocalCallbacks D_80124440[];
extern Vector *D_80136ED4;
extern void *func_80103AA0(LocalMarker *);
extern void *func_80103CDC(LocalActor_801061D8 *, void *);
extern void *func_80103D00(LocalActor_801061D8 *, void *);
extern void func_8010381C(LocalActor_801061D8 *);
extern void _glid_entrypoint_5(void *, void *);
extern void _glid_entrypoint_6(void *, void *);
int func_80105A5C();
void func_801060E4();
void *func_80106320();
int func_801063C0();
void func_801063EC();
extern s32 D_80136ED8;

int func_80105410()
{
  D_80136EC0 = freelist_new(0x48, 8);
}

s32 func_80105438(void){
    freelist_free(D_80136EC0);
}

int func_8010545C()
{
  if (D_80136EC0 != 0)
  {
    D_80136EC0 = freelist_defrag(D_80136EC0);
  }
}

void *func_80105494(param_0) LocalActor_80105494 * param_0; {
    if (param_0->index == 0) return 0;
    return freelist_at(((void *) D_80136EC0), param_0->index);
}

s32 func_801054D4(param_0) s32 param_0;
{
  typedef struct {
    u32 pad_0[9];
    u32 pad_24_6 : 26;
    u32 local_5 : 1;
    u32 pad_24_0 : 5;
  } Struct801054D4;
  u8 *local_0;
  s32 local_1;
  local_0 = func_80105494();
  local_1 = func_800D8588(param_0, func_800D7DE8(param_0), 0x19, 0x19);
  if ((((u32) (*((u32 *) (((s8 *) local_0) + 0x18)))) >> 0x1F) != 0)
  {
    func_8010B990(param_0, 0x6000);
  }
  if ((((Struct801054D4 *)local_0)->local_5 != 0) && (func_80105A5C(param_0) != 0))
  {
    func_800FFAB0(param_0);
  }
  return local_1;
}

Motion105 *func_8010556C(Actor105 *param_0) {
    s32 local_0 = 0;
    Motion105 *local_1;
    local_1 = freelist_next(((u8 *) &D_80136EC0), &local_0);
    param_0->local_0 = local_0;
    rare_memset(local_1, 0, 0x48);
    local_1->local_0 = -1;
    local_1->local_7 = 7;
    local_1->local_4 = 0;
    local_1->local_3 = 100.0f;
    local_1->local_5 = func_800E6A00();
    local_1->local_6 = 0;
    return local_1;
}

void func_80105634(void *param_0)
{
  u32 local_0;
  local_0 = ((Struct80105634 *) param_0)->local_1;
  if (local_0 != 0)
  {
    freelist_erase(((void *) D_80136EC0), local_0 & 0xFFFFFFFFu);
    *((u16 *) (((u8 *) param_0) + (local_0 = 0x7E))) &= 0xF000;
    *(((u8 *) param_0) + 0x77) &= ~0x10;
  }
}

s32 func_8010568C(s32 param_0, s32 param_1) {
    s32 *local_0;

    local_0 = func_80105494();
    if ((local_0 == NULL) || (((s32) (*local_0 << 0x15) >> 0x16) == -1)) {
        if (param_1 != 0) {
            func_800FFAB0(param_0);
        }
        return 0;
    }
    return 1;
}

void func_801056EC(void *param_0, f32 param_1) {
    S_1056EC *p = func_80105494();
    p->unk10 = p->unkC;
    p->unkC = param_1;
    func_800D86F0(p->f, param_1, (u8 *)param_0 + 4);
}

void func_8010573C(u8 *param_0, f32 param_1) {
    f32 local_0[3];
    f32 local_1[3];
    Motion105 *local_2;
    s32 local_3;
    local_2 = func_80105494(param_0);
    local_3 = func_800D7DE8(param_0);
    local_2->local_2 = local_2->local_1;
    local_2->local_1 = param_1;
    func_800D86F0(local_2->local_0, param_1, (f32 *)(param_0 + 4));
    func_800C810C(func_800D7520(local_2->local_0), local_2->local_1, local_0, local_1);
    if (local_3 & 0x100) {
        if (local_1[1] >= 180.0f) *(f32 *)(param_0 + 0x54) = local_1[1] - 180.0f;
        else *(f32 *)(param_0 + 0x54) = local_1[1] + 180.0f;
    }
    if (local_3 & 0x200) *(f32 *)(param_0 + 0x50) = 360.0f - local_1[0];
    *(f32 *)(param_0 + 0x48) = *(f32 *)(param_0 + 0x54);
    *(f32 *)(param_0 + 0x44) = *(f32 *)(param_0 + 0x50);
}

void func_80105834()
{
    func_801054D4();
}

int func_80105854(s32 param_0)
{
  func_801054D4(param_0);
  if (func_80105A5C(param_0))
  {
    func_800FFAB0(param_0);
  }
}

void func_8010588C(u8 **param_0)
{
  int new_var3;
  u8 **new_var;
  u8 ***new_var4;
  u8 **new_var2;
  func_8010A570();
  new_var4 = &param_0;
  new_var3 = 0x2A;
  new_var = *new_var4;
  new_var2 = new_var;
  param_0[0][new_var3] |= 4;
  func_801054D4(new_var2);
}

void func_801058C4(Actor *param_0, s32 param_1, f32 param_2, s32 param_3) {
    local_type *local_0;
    local_0 = func_80105494(param_0);
    if (!local_0) local_0 = func_8010556C(param_0);
    if (param_1 != -1) local_0->local_1 = param_1;
    if (param_3) func_800D8648(local_0->local_1, (f32 *)((u8 *)param_0 + 4));
    local_0->local_4 = 0.0f;
    local_0->local_5 = 0.0f;
    local_0->local_6 = param_2;
    ((local_actor *)param_0)->local_2 = 1;
    local_0->local_2 = 1;
    local_0->local_8 = 0;
}

s32 func_80105998(f32 *param_0, f32 param_1)
{
  f32 *local_0 = func_80105494(param_0);
  f32 local_2 = *((f32 *) (((char *) local_0) + 0xC));
  f32 local_1 = *((f32 *) (((char *) local_0) + 0x10));
  s32 result = 0;
  if (local_1 == local_2)
  {
    return 0;
  }
  if (local_1 < local_2)
  {
    result = (local_1 <= param_1) && (param_1 < local_2);
  }
  else
  {
    result = ((local_1 <= param_1) || (param_1 < local_2)) & 0xFFFFFFFFu;
  }
  return result;
}

int func_80105A5C(param_0) int param_0;
{
    f32* local_0 = func_80105494(param_0);
    return local_0[3] == 1.0f;
}

void func_80105A9C(s32 param_0, f32 param_1)
{
  Actor *local_0 = func_80105494(param_0);
  *(f32 *)((char *)local_0 + 0x14) = param_1;
}

float func_80105AC4(void)
{
    return *(float *)((char *)func_80105494() + 0x14);
}

f32 func_80105AE8(void)
{
    return *(f32 *)((char *)func_80105494() + 0xC);
}

f32 func_80105B0C(u8 *param_0, f32 *param_1) {
    f32 local_0[3];
    f32 local_1[3];
    Motion105 *local_2;
    s32 local_3;
    local_2 = func_80105494(param_0);
    local_3 = func_800D7DE8(param_0);
    func_800C810C(func_800D7520(local_2->local_0), local_2->local_1, local_0, local_1);
    if (local_3 & 0x100) {
        return local_1[1] >= 180.0f ? local_1[1] - 180.0f : local_1[1] + 180.0f;
    }
    return local_1[1];
}

void func_80105BAC(void)
{
  u8 *local_0;
  local_0 = func_80105494();
  if (local_0 != 0)
  {
    local_0[0x18] = (local_0[0x18] & 0xFFFF) | 0x80;
  }
}

void func_80105BE0(void *param_0, s32 param_1) {
    S_105BE0 *p = func_80105494(param_0);
    if (p != 0) { p->bit = param_1; }
}

void func_80105C20()
{
  D_80136ED0 = freelist_new(8, 0);
}

s32 func_80105C48(void){
    s32 i;
    s32 max = freelist_capacity(D_80136ED0);
    for(i = 1; i < max; i++){
        if(freelist_is_element_alive(D_80136ED0, i)){
            func_801060E4((s16)i);
        }
    }
    freelist_free(D_80136ED0);
    D_80136ED0 = 0;
}

typedef struct {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    void (*fnC)(s32);
} Entry_80124440;

void func_80105CD0(void)
{
  void (*temp_v0_5)(s32);
  int var_s3;
  s32 temp_v0;
  s32 temp_v0_3;
  u32 temp_s1;
  u32 temp_v0_4;
  u32 var_s0;
  u8 *temp_v0_2;
  if (D_80136ED0 != 0)
  {
    temp_v0 = freelist_capacity(D_80136ED0);
    var_s3 = 1;
    if (temp_v0 >= 2)
    {
      do
      {
        if (freelist_is_element_alive(D_80136ED0, var_s3) != 0)
        {
          temp_v0_2 = freelist_at(D_80136ED0, var_s3);
          func_801063EC((short) var_s3, defrag(*((void **) (((char *) temp_v0_2) + 0))));
          temp_v0_3 = vector_defrag(*((void **) (((char *) temp_v0_2) + 4)));
          *((void **) (((char *) temp_v0_2) + 4)) = temp_v0_3;
          temp_s1 = vector_end(temp_v0_3);
          temp_v0_4 = vector_begin(*((void **) (((char *) temp_v0_2) + 4)));
          var_s0 = temp_v0_4;
          if (temp_v0_4 < temp_s1)
          {
            do
            {
              temp_v0_5 = ((Entry_80124440 *) D_80124440)[*((s16 *) (((char *) var_s0) + 4))].fnC;
              if (temp_v0_5 != 0)
              {
                temp_v0_5(var_s0 + 8);
              }
              var_s0 += 0xA8;
            }
            while (var_s0 < temp_s1);
          }
        }
        var_s3 += 1;
      }
      while (var_s3 < temp_v0);
    }
    D_80136ED0 = freelist_defrag(D_80136ED0);
    *(&D_80136ED0 + 1) = 0;
  }
}

void func_80105DFC(u8 *param_0) {
    s16 *local_0;
    s16 *local_3;
    s16 local_4;
    s32 local_1;
    s32 local_6;
    u8 *local_7;

    local_1 = 0;
    if ((*(s16 *)((s8 *)(param_0) + (0x90))) == 0) {
        local_7 = freelist_next(&D_80136ED0, &local_1);
        (*(s16 *)((s8 *)(param_0) + (0x90))) = (s16) local_1;
        (*(s32 *)((s8 *)(local_7) + (0))) = _glidmake_entrypoint_5((*(u16 *)((s8 *)((*(u8 **)((s8 *)(param_0) + (0)))) + (0x14))), 0);
        if ((*(s32 *)((s8 *)(local_7) + (0))) == 0) {
            freelist_erase(D_80136ED0, local_1);
            (*(s16 *)((s8 *)(param_0) + (0x90))) = 0;
            return;
        }
        (*(s32 *)((s8 *)(local_7) + (4))) = vector_new(0xA8, 0);
        local_0 = _glidmake_entrypoint_1((*(s32 *)((s8 *)(local_7) + (0))));
        local_3 = local_0 + 1;
        local_6 = 0;
        if (*local_0 > 0) {
            do {
                local_4 = (*(s16 *)((s8 *)(local_3) + (0)));
                if ((local_4 >= 0x65) && (local_4 < 0xC8)) {
                    func_80106320(param_0, local_4, 1, local_4 - 0x64, 0);
                } else if ((local_4 >= 0xC8) && (local_4 < 0x12C)) {
                    func_80106320(param_0, local_4, 0, local_4 - 0xC8, 0);
                } else if ((local_4 >= 0x12C) && (local_4 < 0x190)) {
                    func_80106320(param_0, local_4, 3, local_4 - 0x12C, 0);
                } else if ((local_4 >= 0x190) && (local_4 < 0x1F4)) {
                    func_80106320(param_0, local_4, 2, local_4 - 0x190, 0);
                } else if ((local_4 >= 0x1F4) && (local_4 < 0x258)) {
                    func_80106320(param_0, local_4, 4, local_4 - 0x1F4, 0);
                } else if ((local_4 >= 0x258) && (local_4 < 0x2BC)) {
                    func_80106320(param_0, local_4, 2, local_4 - 0x258, 0);
                } else if ((local_4 >= 0x2BC) && (local_4 < 0x320)) {
                    func_80106320(param_0, local_4, 5, local_4 - 0x2BC, 0);
                } else if ((local_4 >= 0x320) && (local_4 < 0x384)) {
                    func_80106320(param_0, local_4, 6, local_4 - 0x320, 0);
                } else if ((local_4 >= 0x384) && (local_4 < 0x3E8)) {
                    func_80106320(param_0, local_4, 7, local_4 - 0x384, 0);
                } else if ((local_4 >= 0x4B0) && (local_4 < 0x6A4)) {
                    func_80106320(param_0, local_4, 8, local_4 - 0x4B0, 0);
                } else if ((local_4 >= 0x6A4) && (local_4 < 0x708)) {
                    func_80106320(param_0, local_4, 0xA, local_4 - 0x6A4, 0);
                } else if ((local_4 >= 0x76C) && (local_4 < 0x7D0)) {
                    func_80106320(param_0, local_4, 9, local_4 - 0x76C, 0);
                }
                local_6 += 1;
                local_3 = (&local_3[(*(s16 *)((s8 *)(local_3) + (2)))]) + ((0, 2));
            } while (local_6 < *local_0);
        }
    }
}

void func_801060E4(param_0) s16 param_0;
{
    s32 *sp1C;
    s32 *temp_v0;

    temp_v0 = freelist_at(((void *) D_80136ED0), param_0);
    sp1C = temp_v0;
    vector_free((*(s32 *)((s8 *)(temp_v0) + (4))));
    _glidmake_entrypoint_4(*sp1C);
    freelist_erase(((void *) D_80136ED0), param_0);
}

void func_80106138(u8 *param_0)
{
  u32 local_0;
  u32 local_1;
  u32 local_2;
  int new_var;
  u8 *local_3;
  local_3 = func_801063C0();
  local_0 = vector_end(*((s32 *) (((s8 *) local_3) + 4)));
  local_1 = vector_begin(*((s32 *) (((s8 *) local_3) + 4)));
  local_2 = local_1;
  if (local_1 < local_0)
  {
    do
    {
      new_var = (*((s16 *) (((s8 *) local_2) + 4))) * 4;
      (*((s32 (**)(s32)) (((s8 *) ((((s32 *) D_80124440)) + new_var)) + 8)))(local_2 + 8);
      local_2 += 0xA8;
    }
    while (local_2 < local_0);
  }
  func_801060E4(*((s16 *) (((s8 *) param_0) + 0x90)));
  *((s16 *) (((s8 *) param_0) + 0x90)) = 0;
}

void func_801061D8(LocalActor_801061D8 *param_0)
{
    LocalState *local_0;
    void *local_1;
    LocalEntry *local_2;
    LocalEntry *local_3;
    local_0 = func_801063C0(param_0);
    local_1 = func_80103AA0(param_0->marker);
    if (local_1) {
        func_800D62E4(param_0->marker->id);
        _glid_entrypoint_5(local_0->handle, func_80103CDC(param_0, local_1));
        if (param_0->has_secondary) _glid_entrypoint_6(local_0->handle, func_80103D00(param_0, local_1));
        if (param_0->update && !param_0->blocked) {
            local_3 = vector_end(local_0->entries);
            D_80136ED4 = local_0->entries;
            for (local_2 = vector_begin(local_0->entries); local_2 < local_3; local_2++) {
                D_80124440[local_2->type].update(local_2->data, local_2->key, local_2->argument);
            }
        }
    } else if (param_0->reset) func_8010381C(param_0);
}

s32 func_80106314()
{
    return D_80136ED8;
}

void *func_80106320(param_0, param_1, param_2, param_3) s32 * param_0; s32 param_1; s32 param_2; s32 param_3;
{
  s32 *local_24;
  void *local_0;

  local_24 = func_801063C0();
  local_0 = vector_push_back((char *)local_24 + 4);
  *(s16 *)((char *)local_0 + 4) = (s16)param_2;
  *(s32 *)((char *)local_0 + 0) = (s32)*local_24;
  *(s16 *)((char *)local_0 + 6) = (s16)param_1;
  D_80136ED8 = *param_0;
  (*(void (**)(s32, s32, s32, s16, s32))((char *)((s32 *) D_80124440) + *(s16 *)((char *)local_0 + 4) * 16))((s32)((char *)local_0 + 8), param_3, *(volatile s32 *)((char *)local_0 + 0), *(s16 *)((char *)local_0 + 6), 4);
  return local_0;
}

int func_801063C0(param_0) void * param_0;
{
    freelist_at(((void *) D_80136ED0), *(s16 *)((u8 *)param_0 + 0x90));
}

typedef struct { s32 unk0; Vector *vec; } Entry_801063EC;

void func_801063EC(param_0, param_1) s16 param_0; s32 param_1; {
    Entry_801063EC *e;
    s32 *p;
    s32 *end;

    e = freelist_at(D_80136ED0, param_0);
    if (param_1 != e->unk0) {
        end = vector_end(e->vec);
        for (p = vector_begin(e->vec); p < end; p = (s32 *)((u8 *)p + 0xA8)) {
            *p = param_1;
        }
        e->unk0 = param_1;
    }
}

int func_8010647C(s32 param_0)
{
  s16 local_0;
  local_0 = *(s16*)((char*)param_0 + 0x90);
  func_801063EC(local_0);
}

u8 *func_8010649C(s32 param_0, s32 param_1) {
    s32 local_5 = param_1;
    u32 local_0;
    u8 *local_1;
    u32 local_2;
    u32 local_3;
    u8 *local_4;

    local_4 = func_801063C0(param_0);
    local_1 = local_4;
    local_0 = vector_end((*(s32 *)((s8 *)(local_4) + (4))));
    local_2 = vector_begin((*(s32 *)((s8 *)(local_1) + (4))));
    local_3 = local_2;
    if (local_2 < local_0) {
loop_2:
        if (((*(s16 *)((s8 *)(local_3) + (4))) == 2) && (local_5 == (*(s16 *)((s8 *)(local_3) + (6))))) {
            return local_3 + 8;
        }
        local_3 += 0xA8;
        if (local_3 >= local_0) {
            goto block_6;
        }
        goto loop_2;
    }
block_6:
    return NULL;
}

s32 func_80106520(s32 param_0)
{
  s32 local_1;
  s32 local_2;
  s32 *local_3;
  local_2 = vector_end((s32 *)((u8 *) D_80136ED4));
  local_1 = vector_begin((s32 *)((u8 *) D_80136ED4));
  if ((u32)local_1 < (u32)local_2)
  {
    local_3 = (s32 *) local_1;
    while (1)
    {
      if (*((s16 *) ((char *) local_3 + 4)) == 7 &&
          *((s16 *) ((char *) local_3 + 6)) == param_0)
      {
        return (s32) ((char *) local_3 + 8);
      }
      local_3 = (s32 *) ((char *) local_3 + 0xA8);
      if ((u32)local_3 >= (u32)local_2)
      {
        break;
      }
    }
  }
  return 0;
}

s32 func_801065A4(s32 param_0)
{
  s16 local_0;
 ; if ((*((s16 *) (param_0 + 0x90))) != 0) { s32 *local_1;
    local_1 = func_801063C0(param_0);
    return *local_1;
  }
  return 0;
}
