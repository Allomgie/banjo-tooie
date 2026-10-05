#include "core2/1EA1DA0.h"
#include <ultra64.h>

/* No <vector.h> here: vector_at is called with extra arguments in this
 * unit, so the original had no prototypes for the vector functions. */
typedef struct {
    s32 element_size;
    void* begin;
    void* end;
    void* mem_end;
    u8 data[];
} Vector;

extern u8 field_C[];
extern u8 field_0[];
extern u8 field_8[];
extern u8 field_4[];
extern u8 D_8011A9B8[];
extern u8 D_8011A938[];
extern u8 D_8011A934[];
extern u8 D_8011A930[];
extern int D_8011A9C0[];
extern void func_800EE830(s32, void*);
extern void* D_8012AB04;
extern s32 D_8012AB10;
extern void func_800EE88C();
extern s32 D_8012AB1C;
extern s32 D_8012AB28;
void* vector_begin(Vector* vec);
void* vector_end(Vector* vec);
extern u8 D_8011A9D8[];
extern u8 D_8011A9E0[];
extern u8 D_8011A9CC[];
extern void *vector_push_back();
extern f32 D_8011A9EC[];
extern f32 D_8011A9F8[];
extern u32 D_8011AA00[];
typedef struct { u8 field0; u8 field1; } ActorMarker;
extern void func_800EE940();
extern void func_800EE814();
typedef struct { void *unk0[5]; u8 unk14; } G_C91C8;
extern G_C91C8 D_8012AB40;
extern void heap_free(void *);
extern void _gctransitionDll_entrypoint_9(void *);
extern u8 D_8012AB54;
extern void func_800A8BD4(int, int, int);
extern void func_800A8CCC(int, int);
extern void _gctransitionDll_entrypoint_0(void *, int);
extern s32 _gctransitionDll_entrypoint_4(s32);
typedef struct { f32 local_0; u8 local_1; u8 local_2[3]; s32 local_3[6]; u8 local_4[0x50]; } local_entry;
extern void func_800C3FF0(s32 a, f32 b);
void func_800C4244(s32, s32, s32, u8 *, f32, f32);
extern s32 func_801069A4();
typedef struct { Vector *local_0; f32 local_1; } Struct_D_8012AB60;
extern Struct_D_8012AB60 D_8012AB60;
extern u8 *vector_at();
typedef struct { u32 unk0; f32 unk4; u32 unk8; f32 unkC[3]; f32 unk18; f32 unk1C; } S_C9C70;
extern void func_800EE7F8(f32 *, f32 *);
typedef struct { u32 unk0; u32 unk4; u32 unk8; f32 unkC[3]; s16 unk18; } S_C9CD0;
extern void func_800EFD24(f32 *);
extern void func_800A54F8(void);
extern s32 func_800A5524;
extern float D_8012AB64;
typedef struct {f32 local_0; u8 local_1[0x6C];} local_type_800CA0A8;
extern f32 func_800D8FF8(void);
extern void *rare_memcpy(void *, const void *, size_t);
void func_800C8CB8(s32 param_0, f32 param_1[3]);
void func_800C8D4C();
void func_800C8E84(s32 param_0, u32 param_1[3]);
void *func_800C91C8();
void func_800C9E20(f32 timerLength, u32 *callback, u32 callbackArg0, u32 callbackArg1);
void func_800C9E64(f32 p0, u32 *p1, u32 p2, u32 p3, s32 p4);
void func_800C9EF8(f32, s32, s32);

extern u8 *D_8012AB00;

int func_800C84B0(s32 param_0)
{
  __OSTranxInfo *local_0;
  long new_var;
  s32 local_1;
  local_1 = param_0;
  local_1 = local_1 & 0x1F00;
  if ((param_0 << 14) < 0)
  {
    return 4;
  }
  if (local_1 == 0)
  {
    return 0;
  }
  new_var = local_1 == (*((s32 *) (&D_8011A930[0])));
  local_0 = (__OSTranxInfo *) (&D_8011A938[0]);
  if (new_var)
  {
    return *((s32 *) (&D_8011A934[0]));
  }
  loop_7:
  if (local_1 == (*((s32 *) (((char *) local_0) + 0x0))))
  {
    return *((s32 *) (((char *) local_0) + 0x4));
  }

  if (local_1 == (*((s32 *) (((char *) local_0) + 0x8))))
  {
    return *((s32 *) (((char *) local_0) + 0xC));
  }
  if (local_1 == (*((s32 *) (((char *) local_0) + 0x10))))
  {
    return *((s32 *) (((char *) local_0) + 0x14));
  }
  if (local_1 == (*((s32 *) (((char *) local_0) + 0x18))))
  {
    return *((s32 *) (((char *) local_0) + 0x1C));
  }
  local_0 = (__OSTranxInfo *) (((char *) local_0) + 0x20);
  if (local_0 == ((__OSTranxInfo *) (&D_8011A9B8[0])))
  {
    return 1;
  }
  goto loop_7;
}

s32 func_800C8560(u8 *param_0, s32 param_1)
{
  u8 *new_var;
  s32 local_0;
  s32 local_1;
  u8 *new_var2;
  new_var = param_0;
  local_0 = (*((u8 *) (((s8 *) ((0, new_var))) + 0x16))) != 0;
  local_1 = local_0;
  if (local_0 != 0)
  {
    ;
    new_var2 = new_var;
    return ((*((u8 *) (((s8 *) param_0) + 0x15))) & param_1) != 0;
    local_0 = (*((u8 *) (((s8 *) ((0, new_var2))) + 0x16))) != 0;
  }
}

func_800C8588(u8 *param_0, u8 param_1) {
    return param_0[0x14];
}

int func_800C8594(u8 *param_0, unsigned int param_1)
{
  return param_0[0x15] & param_1;
}

s32 func_800C85A0(param_0, param_1) s32 (*param_0)(u32, s32); s32 param_1; {
    u32 sp2C;
    u32 temp_v0;
    u32 var_s0;

    sp2C = vector_begin(((void *) D_8012AB00));
    temp_v0 = vector_end(((void *) D_8012AB00));
    var_s0 = sp2C;
    if (var_s0 < temp_v0) {
loop_1:
        if (((*(u8 *)((s8 *)(var_s0) + 0x15)) != 0) && (param_0(var_s0, param_1) != 0) && (((*(u8 *)((s8 *)(var_s0) + 0x17)) != 0) || ((*(u8 *)((s8 *)(var_s0) + 0x18)) != 0))) {
            return ((s32)(var_s0 - sp2C) / 28) + 1;
        }
        var_s0 += 0x1C;
        if (var_s0 >= temp_v0) {
            goto block_7;
        }
        goto loop_1;
    }
block_7:
    return 0;
}

s32 func_800C8678(param_0, param_1, param_2) s32 param_0; s32 (*param_1)(u32, s32); s32 param_2;
{
    s32 *local_1;
    u8 *local_2;
    u8 *local_3;
    s32 local_0;

    local_1 = vector_begin(((u8 *) D_8012AB00));
    local_2 = vector_at(((u8 *) D_8012AB00), param_0 - 1);
    local_3 = vector_end(((u8 *) D_8012AB00));
    local_2 += 0x1C;
    if (local_2 < local_3)
    {
        do
        {
            if ((*(u8 *)((char *)local_2 + 0x15) != 0) && (param_1(local_2, param_2) != 0) && ((*(u8 *)((char *)local_2 + 0x17) != 0) || (*(u8 *)((char *)local_2 + 0x18) != 0)))
            {
                return (((s32)local_2 - (s32)local_1) / 0x1C) + 1;
            }
            local_2 += 0x1C;
        } while (local_2 < local_3);
    }
    return 0;
}

void func_800C8760(s32 param_0)
{
  func_800C85A0(D_8011A9C0[param_0]);
}

int func_800C878C(s32 param_0, s32 param_1)
{
  func_800C8678(param_0, ((s32 *) D_8011A9C0)[param_1]);
}

void func_800C87B8(s32 param_0) {
    func_800EE830(param_0, &D_8012AB04);
}

void func_800C87DC(s32 param_0) {
    func_800EE830(param_0, &D_8012AB10);
}

s32 func_800C8800(s32 param_0, Actor **param_1){
    func_800EE88C(param_1, vector_at(D_8012AB00, param_0 - 1));
}

void func_800C883C(s32 param_0, f32 *param_1)
{
  s16 *local_1 = vector_at(((void *) D_8012AB00), param_0 - 1);
  param_1[0] = local_1[3];
  param_1[1] = local_1[4];
}

void func_800C8898(s32 param_0, f32 *param_1)
{
    s16 *local_0;

    local_0 = (s16 *)vector_at((void *)((void *) D_8012AB00), param_0 - 1);
    param_1[0] = (f32)local_0[3];
    param_1[1] = (f32)local_0[4];
    param_1[2] = *(f32 *)&local_0[8];
}

int func_800C8900(s32 param_0, s32 param_1)
{
  u8 *local_0;
  local_0 = vector_at(((u8 *) D_8012AB00), param_0 - 1);
  if (!local_0[0x17])
  {
    func_800EFA88(param_1, 0, 0, 0);
  }
  else
  {
    func_800F2EE0(param_1, local_0 + 0xA);
  }
}

int func_800C8960(s32 param_0, s32 param_1)
{
  if (param_0 != 0)
  {
    func_800EE830(param_0, &D_8012AB1C);
  }
  if (param_1 != 0)
  {
    func_800EE7F8(param_1, &D_8012AB28);
  }
}

u8 func_800C89A8(s32 param_0)
{
    return (*(u8 *)((char *)(vector_at(((int) D_8012AB00), param_0 - 1, param_0)) + 21));
}

int func_800C89D8(s32 param_0)
{
  u8 *local_0 = vector_at(((u8 *) D_8012AB00), param_0 - 1);
  return *(u8 *)((char *)local_0 + 25);
}

void func_800C8A08(void)
{
  void *new_var;
  void *local_0;
  void *end;
  new_var = vector_begin(((void *) D_8012AB00));
  end = vector_end(((void *) D_8012AB00));
  local_0 = new_var;
  if (local_0 < end)
  {
    do
    {
      if ((*((u8 *) (((char *) local_0) + 0x15))) != 0)
      {
        if ((*((u8 *) (((char *) local_0) + 0x16))) == 2)
        {
          *((u8 *) (((char *) local_0) + 0x15)) = 0;
        }
        else
        {
          *((u8 *) (((char *) local_0) + 0x16)) = 0;
        }
        if ((*((u8 *) (((char *) local_0) + 0x18))) != 0)
        {
          *((u8 *) (((char *) local_0) + 0x18)) = 0;
        }
        *((s8 *) (((char *) local_0) + 0x19)) = 0;
      }
      local_0 = (void *) (((char *) local_0) + 0x1C);
    }
    while (local_0 < end);
  }
}

s32 func_800C8A98(void)
{
  u8 *local_0;
  u8 *local_1;
  u8 *local_2;
  s32 local_3;

  local_0 = (u8 *)vector_begin(((void *) D_8012AB00));
  local_1 = (u8 *)vector_end(((void *) D_8012AB00));
  for (local_2 = local_0; local_2 < local_1; local_2 += 0x1c) {
    if (!local_2[0x15]) break;
  }

  if (local_2 == local_1)
  {
    local_2 = (u8 *)vector_push_back(((void * *) &D_8012AB00));
  }
  local_3 = vector_index_of(((void *) D_8012AB00), (void *)local_2) + 1;
  local_2[0x15] = 0xb;
  local_2[0x16] = local_2[0x17] = 1;
  local_2[0x14] = 0;
  local_2[0x18] = 0;
  local_2[0x19] = 0;
  func_800C8CB8(local_3, D_8011A9CC);
  func_800C8D4C(local_3, D_8011A9D8);
  func_800C8E84(local_3, D_8011A9E0);
  return local_3;
}

void func_800C8B84(s32 param_0)
{
    void *local_0;
    local_0 = vector_at(((void *) D_8012AB00), param_0 - 1);
    func_800C8CB8(param_0, &D_8011A9EC);
    func_800C8D4C(param_0, &D_8011A9F8);
    func_800C8E84(param_0, &D_8011AA00);
    ((u8 *)local_0)[0x16] = 2;
}

s32 func_800C8BF4(void){
    int size;
    size = vector_size(D_8012AB00);
    return size;
}

int func_800C8C18()
{
  u8 *local_1;
  u8 *local_2;
  s32 local_0;
  u8 *local_3;
  u8 *new_var;
  local_1 = vector_end(((u8 *) D_8012AB00));
  local_0 = 0;
  new_var = ((u8 *) D_8012AB00);
  local_3 = new_var;
  local_2 = vector_begin(local_3);
  while (local_2 < local_1)
  {
    if (local_2[21] && local_2[20])
    {
      local_0++;
    }
    local_2 += 28;
  }

  return local_0;
}

int func_800C8C90(s32 param_0)
{
  s32 local_0;
  local_0 = param_0 | 0;
  func_800EE830(((s32 *) &D_8012AB04), local_0);
}

void func_800C8CB8(s32 param_0, f32 param_1[3]) {
    s16 *local_0;
    s16 local_1[3];
    local_0 = vector_at(((void *) D_8012AB00), param_0 - 1);
    func_800EE940(local_1, param_1);
    if (local_0[0] != local_1[0] || local_0[1] != local_1[1] || local_0[2] != local_1[2]) {
        func_800EE814(local_0, local_1);
        ((u8 *)local_0)[0x16] = ((u8 *)local_0)[0x19] = 1;
    }
}

void func_800C8D4C(param_0, param_1) s32 param_0; f32 * param_1; {
    s32 local_3;
    s16 local_0[2];
    s16 local_1;
    u8 *local_2;
    local_2 = vector_at(((Vector *) D_8012AB00), param_0 - 1);
    local_0[0] = param_1[0];
    local_0[1] = param_1[1];
    if (local_0[1] < local_0[0]) local_0[1] = local_0[0];
    if (local_0[1] < local_0[0]) local_0[0] = local_0[1];
    if (local_0[0] == local_0[1]) local_0[1]++;
    if (*(s16 *)(local_2 + 6) != local_0[0] || *(s16 *)(local_2 + 8) != local_0[1]) {
        *(s16 *)(local_2 + 6) = local_0[0];
        *(s16 *)(local_2 + 8) = local_0[1];
        *(f32 *)(local_2 + 0x10) = 1.0f / (local_0[1] - local_0[0]);
        local_2[0x16] = local_2[0x19] = 1;
    }
}

void func_800C8E54(s32 param_0, f32 param_1, f32 param_2)
{
  f32 local_0[2];
  local_0[0] = param_1;
  local_0[1] = param_2;
  func_800C8D4C(param_0, &local_0);
}

void func_800C8E84(s32 param_0, u32 param_1[3]) {
    u8 *local_1;

    local_1 = vector_at((u8 *) D_8012AB00, param_0 - 1, param_1, param_0);
    if ((local_1[0xA] != param_1[0]) || (local_1[0xB] != param_1[1]) || (local_1[0xC] != param_1[2])) {
        local_1[0xA] = (u8) param_1[0];
        local_1[0xB] = (u8) param_1[1];
        local_1[0xC] = (u8) param_1[2];
        local_1[0x16] = 1;
    }
}

int func_800C8F08(s32 param_0, s32 param_1)
{
  if (param_0 != 0)
  {
    func_800EE830(&D_8012AB1C, param_0);
  }
  if (param_1 != 0)
  {
    func_800EE7F8(&D_8012AB28, param_1);
    func_800EF2A0(&D_8012AB28);
  }
}

void func_800C8F64(s32 param_0, s32 param_1) {
    u8 *local_0;

    local_0 = vector_at(D_8012AB00, param_0 - 1, param_0);
    if (param_1 != (*(u8 *)((s8 *)(local_0) + (0x15)))) {
        (*(u8 *)((s8 *)(local_0) + (0x15))) = (u8) param_1;
        (*(s8 *)((s8 *)(local_0) + (0x16))) = 1;
    }
}

void func_800C8FB0(s32 param_0, u32 param_1, u32 param_2, u32 param_3)
{
  u32 local_0[3];
  local_0[0] = param_1;
  local_0[1] = param_2;
  local_0[2] = param_3;
  func_800C8E84(param_0, local_0);
}

int func_800C8FE0(s32 param_0, s32 param_1)
{
  u8 *local_0;
  local_0 = vector_at(((u8 *) D_8012AB00), param_0 - 1);
  if (!local_0[22])
  {
    local_0[22] = local_0[23] != param_1;
  }
  local_0[23] = param_1;
  if (param_1 == 0)
  {
    local_0[24] = 1;
  }
}

u8 func_800C9044(s32 param_0)
{
  return vector_at(((u8 *) D_8012AB00), param_0 - 1)[0x17];
}

void func_800C9074()
{
  if (D_8012AB00 != 0)
  {
    D_8012AB00 = vector_defrag(D_8012AB00);
  }
}

void func_800C90AC()
{
    _gclightsDll_entrypoint_0(&D_8012AB00);
}

void func_800C90D0()
{
    _gclightsDll_entrypoint_1(&D_8012AB00);
}

int func_800C90F4(s32 param_0)
{
  s32 local_0;
  local_0 = param_0 | 0;
  _gclightsDll_entrypoint_2(&D_8012AB00, local_0);
}

int func_800C911C()
{
  return (int)&D_8012AB00;
}

int func_800C9128(s32 param_0)
{
  s32 local_0;
  local_0 = param_0 | 0;
  _gclightsDll_entrypoint_3(&D_8012AB00, local_0);
}

s32 func_800C9150(s32 param_0)
{
    void *local_0;

    local_0 = func_800C91C8(param_0);
    if (local_0 == NULL) {
        local_0 = heap_alloc(0x34);
        bzero(local_0, 0x34);
        D_8012AB40.unk0[D_8012AB40.unk14++] = local_0;
        _gctransitionDll_entrypoint_8(local_0, param_0);
    }
    return (s32) local_0;
}

void *func_800C91C8(param_0) s32 param_0; {
    s32 i;
    for (i = 0; i < D_8012AB40.unk14; i++) {
        if (param_0 == *(s32 *)D_8012AB40.unk0[i]) { return D_8012AB40.unk0[i]; }
    }
    return 0;
}

void func_800C9214(void *param_0) {
    s32 local_0;
    for (local_0 = 0; local_0 < D_8012AB40.unk14; local_0++) {
        if (param_0 == D_8012AB40.unk0[local_0]) {
            heap_free(D_8012AB40.unk0[local_0]);
            D_8012AB40.unk0[local_0] = D_8012AB40.unk0[--D_8012AB40.unk14];
            break;
        }
    }
}

void func_800C929C()
{
	D_8012AB54 = 0;
}

void func_800C92A8(void) {
    s32 i;
    for (i = 0; i < D_8012AB40.unk14; i++) {
        _gctransitionDll_entrypoint_9(D_8012AB40.unk0[i]);
    }
}

void func_800C9310(void)
{
    while (((u8 *) &D_8012AB40)[0x14])
    {
        _gctransitionDll_entrypoint_5(*(u32 *)((u8 *) &D_8012AB40));
    }
}

void func_800C9358(s32 param_0, s32 param_1)
{
  s32 v0;
  s32 local_0;
  void **local_1;
  if (D_8012AB54)
  {
    local_0 = 0;
    if (((s32) D_8012AB54) > (local_0 * 0))
    {
      local_1 = ((void * *) &D_8012AB40);
      do
      {
        v0 = *(*((s32 **) local_1));
        if (v0 != 4)
        {
          func_800A8BD4(param_0, v0, param_1);
          _gctransitionDll_entrypoint_0(*local_1, param_0);
        }
        local_0 += 1;
        local_1 += 1;
      }
      while (local_0 < ((s32) D_8012AB54));
    }
    func_800A8CCC(param_0, param_1);
  }
}

void func_800C940C(s32 param_0,s32 param_1)
{
    s32 local_0;
    s32 local_1;
    if (D_8012AB54) {
        for (local_0=0;local_0<D_8012AB54;local_0++) {
            local_1=*((s32 * *) &D_8012AB40)[local_0];
            if (local_1==4) {
                _gctransitionDll_entrypoint_0(((s32 * *) &D_8012AB40)[local_0],param_0);
                return;
            }
        }
    }
}

void func_800C9484(void)
{
  s32 local_0;
  s32 **local_1;
  s32 *local_2;
  s32 local_3;
  local_0 = 0;
  if (((s32) D_8012AB54) > 0)
  {
    local_1 = ((s32 * *) &D_8012AB40);
    do
    {
      local_2 = *local_1;
      if (local_2 != 0)
      {
        local_3 = *((s32 *) (((char *) local_2) + 0x2C));
        if ((*((s32 *) (((char *) local_2) + 0x2C))) != 0)
        {
          *((s32 *) (((char *) (*local_1)) + 0x2C)) = func_8008AEB4(local_3, *((s32 *) (((char *) local_2) + 0x2C)));
        }
        *local_1 = defrag(*local_1);
      }
      local_0 += 1;
      local_1 += 1;
    }
    while (local_0 < ((s32) D_8012AB54));
  }
}

s32 func_800C9510()
{
  s32 local_0;
  local_0 = func_800C91C8(4);
  if (local_0 != 0)
  {
    return _gctransitionDll_entrypoint_4(local_0 | 0);
  }
  return 0;
}

int func_800C954C()
{
  s32 local_0;
  local_0 = func_800C91C8(4);
  if (local_0 != 0)
  {
    return _gctransitionDll_entrypoint_3(local_0 | 0);
  }
  return 0;
}

float func_800C9588(void)
{
    return 300.0f;
}

int func_800C9598()
{
  s32 local_0;
  local_0 = func_800C91C8(4);
  if (!local_0)
  {
    local_0 = func_800C9150(4);
  }
  _gctransitionDll_entrypoint_1(local_0);
}

int func_800C95D4()
{
  s32 local_0;
  local_0 = func_800C91C8(4);
  if (local_0 != 0)
  {
    return _gctransitionDll_entrypoint_2(local_0 | 0);
  }
  return 1;
}

int func_800C9610()
{
  s32 local_0;
  local_0 = func_800C91C8(4);
  if (!local_0)
  {
    local_0 = func_800C9150(4);
  }
  _gctransitionDll_entrypoint_6(local_0);
}

void func_800C964C(s32 param_0)
{
    s32 local_0;
    local_0 = func_800C91C8(4);
    if (local_0 == 0) {
        local_0 = func_800C9150(4);
    }
    _gctransitionDll_entrypoint_7(local_0, param_0);
}

int func_800C968C(s32 param_0, s32 param_1)
{
  s32 local_0;
  local_0 = func_800C91C8();
  if (!local_0)
  {
    local_0 = func_800C9150(param_0);
  }
  _gctransitionDll_entrypoint_7(local_0, param_1);
}

int func_800C96CC()
{
  u8 *local_0;
  s32 local_1;
  local_0 = func_800C91C8();
  if (local_1 = (local_0 != 0) ^ 0)
  {
    local_1 = 0;
    if (local_0[0xA] == local_0[0x1C])
    {
      return 1;
    }
    else
    {
      return local_1 | 0;
    }
  }
  return 0;
}

int func_800C9714()
{
  s32 local_0;
  local_0 = func_800C91C8();
  if (local_0 != 0)
  {
    return _gctransitionDll_entrypoint_3(local_0 | 0);
  }
  return 1;
}

int func_800C9750(f32 param_0, s32 param_1, s32 param_2, s32 param_3, s32 param_4, s32 param_5, s32 param_6, s32 param_7) {
    local_entry *local_0;
    local_entry *local_1;
    local_entry *local_2;
    if (!D_8012AB60.local_0) D_8012AB60.local_0 = vector_new(sizeof(local_entry), 8);
    local_0 = vector_begin(D_8012AB60.local_0);
    local_1 = vector_end(D_8012AB60.local_0);
    if (local_1 == local_0) D_8012AB60.local_1 = 0.0f;
    else param_0 += D_8012AB60.local_1;
    for (local_2 = local_0; local_2 < local_1; local_2++) { if (param_0 < local_2->local_0) break; }
    local_2 = vector_insert(&D_8012AB60.local_0, local_2 - local_0);
    local_2->local_0 = param_0;
    local_2->local_1 = param_1;
    local_2->local_3[0] = param_2;
    local_2->local_3[1] = param_3;
    local_2->local_3[2] = param_4;
    local_2->local_3[3] = param_5;
    local_2->local_3[4] = param_6;
    local_2->local_3[5] = param_7;
}

void func_800C986C(u8 *param_0) {
  switch (param_0[4]) {
    case 0:
      ((void (*)()) *((u32 *)(param_0 + 8)))();
      break;
    case 1:
      ((void (*)()) *((u32 *)(param_0 + 8)))((u8 *) *((u32 *)(param_0 + 12)));
      break;
    case 2:
      ((void (*)()) *((u32 *)(param_0 + 8)))((u8 *) *((u32 *)(param_0 + 12)), (u8 *) *((u32 *)(param_0 + 16)));
      break;
    case 3:
      ((void (*)()) *((u32 *)(param_0 + 8)))((u8 *) *((u32 *)(param_0 + 12)), (u8 *) *((u32 *)(param_0 + 16)), (u8 *) *((u32 *)(param_0 + 20)));
      break;
    case 4:
      ((void (*)()) *((u32 *)(param_0 + 8)))((u8 *) *((u32 *)(param_0 + 12)), (u8 *) *((u32 *)(param_0 + 16)), (u8 *) *((u32 *)(param_0 + 20)), (u8 *) *((u32 *)(param_0 + 24)));
      break;
    case 5:
      ((void (*)()) *((u32 *)(param_0 + 8)))((u8 *) *((u32 *)(param_0 + 12)), (u8 *) *((u32 *)(param_0 + 16)), (u8 *) *((u32 *)(param_0 + 20)), (u8 *) *((u32 *)(param_0 + 24)), (u8 *) *((u32 *)(param_0 + 28)));
      break;
    case 6:
      ((void (*)()) *((u32 *)(param_0 + 8)))((u8 *)(param_0 + 0x20));
      break;
    default:
      break;
  }
}

void func_800C9974()
{
    func_800FC63C();
}

void func_800C9994()
{
    func_800FCAE0();
}

void func_800C99B4(s32 param_0, s32 param_1)
{
  s32 new_var;
  f32 local_0;
  new_var = param_0;
  local_0 = ((f32) param_1) / 1000.0f;
  func_800C3FF0(new_var ^ 0, local_0);
}

void func_800C99F0(u8 *param_0) {
    func_800C4244(*(s32 *)(param_0), *(s32 *)(param_0 + 4), *(s32 *)(param_0 + 8), param_0 + 0xC, *(float *)(param_0 + 0x18), *(float *)(param_0 + 0x1C));
}

void func_800C9A38(void *param_0)
{
    u16 local_1;
    if (func_800EEEA8((void *) (((u32) param_0) + 12)))
    {
        _subaddiedialog_entrypoint_11(*(u32 *)((char *)param_0 + 0), *(u32 *)((char *)param_0 + 4), *(u32 *)((char *)param_0 + 8), 0, (s32)*(s16 *)((char *)param_0 + 0x18));
        return;
    }
    _subaddiedialog_entrypoint_11(*(u32 *)((char *)param_0 + 0), *(u32 *)((char *)param_0 + 4), *(u32 *)((char *)param_0 + 8), (u32) (((u32) param_0) + 12), (s32)*(s16 *)((char *)param_0 + 0x18));
}

int func_800C9AB0(s32 param_0)
{
  switch (param_0)
  {
    case 1:
      func_80090708(1);
      break;

    case 2:
      func_80090708(3);
      break;

    case 3:
      func_80090708(2);
      break;

    case 0:
      func_80090708(0);
      break;

    case 5:
      func_800A51C0();
  }
}

void func_800C9B30(s32 param_0, s32 param_1, s32 param_2) {
    u8 *sp1C;

    sp1C = *(u8 **)&param_0;
    if ((func_801069A4(sp1C) != 0) && (param_1 == ((u32)*(u16 *)(sp1C + 0x12) >> 1))) {
        func_8010114C((s32)sp1C, 0x22, param_2);
    }
}

s32 func_800C9B84(void){
    if(D_8012AB60.local_0){
        vector_clear(D_8012AB60.local_0);
    }
}

void func_800C9BB4(f32 param_0, s32 param_1, f32 param_2, s32 param_3) {
    func_800C9E64(param_0, (u32 *)func_800C99B4, param_1, (s32)(param_2 * 1000.0f), param_3);
}

void func_800C9C04(f32 param_0, s32 param_1, s32 param_2) {
    func_800C9E20(param_0, &func_800C9974, (u32) param_1, (u32) param_2);
}

void func_800C9C34(f32 param_0, s32 param_1, s32 param_2, s32 param_3) {
    func_800C9E64(param_0, (u32 *)func_800C9994, param_1, param_2, param_3);
}

void func_800C9C70(f32 param_0, u32 param_1, f32 param_2, u32 param_3, f32 *param_4, f32 param_5, f32 param_6) {
    S_C9C70 sp18;
    sp18.unk0 = param_1;
    sp18.unk4 = param_2;
    sp18.unk8 = param_3;
    sp18.unk18 = param_5;
    sp18.unk1C = param_6;
    func_800EE7F8(sp18.unkC, param_4);
    func_800C9EF8(param_0, func_800C99F0, &sp18);
}

void func_800C9CD0(f32 p0, u32 p1, u32 p2, u32 p3, f32 *p4, s16 p5) {
    S_C9CD0 sp1C;
    sp1C.unk0 = p1;
    sp1C.unk4 = p2;
    sp1C.unk8 = p3;
    sp1C.unk18 = p5;
    if (p4 != 0) { func_800EE7F8(sp1C.unkC, p4); }
    else { func_800EFD24(sp1C.unkC); }
    func_800C9EF8(p0, func_800C9A38, &sp1C);
}

void func_800C9DE4(f32, s32, s32);

int func_800C9D38(f32 param_0, s32 param_1)
{
  func_800C9DE4(param_0, func_800C9AB0, param_1 | 0);
}

int func_800C9D60(f32 param_0, s32 param_1)
{
  func_800C9DE4(param_0, &func_800A54F8, param_1 | 0);
}

s32 func_800C9DAC(f32, s32);

void func_800C9D88(f32 param_0) {
    func_800C9DAC(param_0, &func_800A5524);
}

s32 func_800C9DAC(f32 map_id, s32 param_1){
    func_800C9750(map_id, 0, param_1, 0, 0, 0, 0, 0);
}

void func_800C9DE4(f32 param_0, s32 param_1, s32 param_2) {
    func_800C9750(param_0, 1, param_1, param_2, 0, 0, 0, 0);
}

void func_800C9E20(f32 timerLength, u32 *callback, u32 callbackArg0, u32 callbackArg1) {
    func_800C9750(timerLength, 2, callback, callbackArg0, callbackArg1, 0, 0, 0);
}

void func_800C9E64(f32 p0, u32 *p1, u32 p2, u32 p3, s32 p4) {
    func_800C9750(p0, 3, p1, p2, p3, p4, 0, 0);
}

void func_800C9EAC(f32 p0, u32 *p1, u32 p2, u32 p3, s32 p4, s32 p5) {
    func_800C9750(p0, 4, p1, p2, p3, p4, p5, 0);
}

void func_800C9EF8(f32 param_0, s32 param_1, s32 param_2) {
    rare_memcpy(func_800C9750(param_0, 6, param_1, 0, 0, 0, 0, 0) + 0x20, param_2, 0x50);
}

void func_800C9F48(f32 param_0, u8 * param_1, s32 param_2) {
    func_800C9750(param_0, 3, (u32 *)func_800C9B30, *(u32 *)&param_1, (u32)*(u16 *)((u8 *)param_1 + 0x12) >> 1, param_2, 0, 0);
}

int func_800C9F94()
{
    return ((int) D_8012AB60.local_0) == 0 || vector_size(((int) D_8012AB60.local_0)) == 0;
}

int func_800C9FD0()
{
  void *local_1;
  u8 local_0[0x70];
  if (D_8012AB60.local_0 != 0)
  {
    while (vector_size(D_8012AB60.local_0) > 0)
    {
      local_1 = vector_begin(D_8012AB60.local_0);
      rare_memcpy(local_0, local_1, 0x70);
      vector_erase(D_8012AB60.local_0, 0);
      func_800C986C(local_0);
    }

    vector_free(D_8012AB60.local_0);
    D_8012AB60.local_0 = 0;
  }
}

int func_800CA060()
{
  if (D_8012AB60.local_0 != 0)
  {
    vector_free(D_8012AB60.local_0);
    D_8012AB60.local_0 = 0;
  }
}

void func_800CA098()
{
  D_8012AB64 = 0.0f;
}

void func_800CA0A8(void) {
    local_type_800CA0A8 *local_1;
    local_type_800CA0A8 local_0;
    if (func_800C9F94()) return;
    D_8012AB60.local_1 += func_800D8FF8();
    while (vector_size(D_8012AB60.local_0) > 0) {
        local_1 = vector_begin(D_8012AB60.local_0);
        if (D_8012AB60.local_1 < local_1->local_0) break;
        rare_memcpy(&local_0, local_1, sizeof(local_type_800CA0A8));
        vector_erase(D_8012AB60.local_0, 0);
        func_800C986C(&local_0);
    }
    if (vector_size(D_8012AB60.local_0) == 0) {
        vector_free(D_8012AB60.local_0);
        D_8012AB60.local_0 = 0;
    }
}

void func_800CA174()
{
  if (((int) D_8012AB60.local_0) != 0)
  {
    D_8012AB60.local_0 = vector_defrag(((int) D_8012AB60.local_0));
  }
}
