#include "common.h"

typedef struct {s32 local_0, local_1; u8 local_2[72]; f32 local_3[][4][4];} local_type;
extern void *heap_realloc(void *, s32);
extern void func_80019CD4(void);
extern void mlMtxGet(f32 (*)[4]);
typedef struct { u8 pad[0x40]; } E40;
typedef struct { s32 count; u8 pad4[0x4C]; E40 e[1]; } ObjA;
typedef struct { u8 pad[0xC]; s16 id; u8 padE[2]; } EntB;
typedef struct { u8 pad0[4]; s16 count; u8 pad6[2]; EntB e[1]; } ObjB;
typedef struct { s32 count; u8 pad4[0x4C]; E40 e[1]; } A800ADEC4;
extern void func_800F293C(E40 *, s32);
struct UnkStruct { s32 unk0; };
typedef f32 MatrixAE40C[4][4];
typedef struct { s32 local_0; s32 local_1; u8 pad[0x48]; MatrixAE40C local_2[1]; } BufferAE40C;
typedef struct { u8 pad[12]; s16 local_0; s16 local_1; } BoneAE40C;
typedef struct { s16 pad[2]; s16 local_0; s16 pad_1; BoneAE40C local_1[1]; } StateAE40C;
extern BufferAE40C *func_8001B710(s16, s32);
extern void func_800DFB7C(s32, s32, f32 *, f32 *, f32 *);
extern void mlMtxSet(f32 [4][4]);
extern s32 func_800D9C4C(f32 *);
extern void func_800D9CE8(f32 *, f32 [3][3]);
extern void func_80019BB8(f32 [3][3]);
extern void mlMtxScale_xyz(f32, f32, f32);
struct UnkStruct* func_800AE080(s16);

void func_800ADCD0(local_type **param_0, s16 *param_1) {
    local_type *local_0;
    f32 (*local_1)[4][4];
    f32 (*local_2)[4][4];
    local_0 = *param_0;
    if (local_0->local_1 < param_1[2]) {
        local_0 = heap_realloc(local_0, param_1[2] * 64 + 0x50);
        local_0->local_1 = param_1[2];
        *param_0 = local_0;
    }
    local_0->local_0 = param_1[2];
    local_2 = local_0->local_0 + local_0->local_3;
    func_80019CD4();
    for (local_1 = local_0->local_3; local_1 < local_2; local_1++) mlMtxGet(*local_1);
}

void func_800ADD80(s16 param_0, s16 *param_1) {
    local_type *local_0;
    f32 (*local_1)[4][4];
    f32 (*local_2)[4][4];
    local_0 = func_800AE080(param_0);
    if (local_0->local_1 < param_1[2]) {
        local_0 = func_8001B710(param_0, param_1[2] * 64 + 0x50);
        local_0->local_1 = param_1[2];
    }
    local_0->local_0 = param_1[2];
    local_2 = local_0->local_0 + local_0->local_3;
    func_80019CD4();
    for (local_1 = local_0->local_3; local_1 < local_2; local_1++) mlMtxGet(*local_1);
}

int func_800ADE2C(s32 param_0, s32 param_1)
{
  long new_var2;
  s32 new_var;
  if (param_1 == (-1))
  {
    return param_0 + 0x10;
  }
  else
  {
    new_var = param_1;
    new_var2 = new_var * 0x40;
    return (param_0 + new_var2) + 0x50;
  }
}

int func_800ADE50(ObjA *param_0, ObjB *param_1, s32 param_2) {
    EntB *q;
    E40 *p;
    q = param_1->e;
    if (param_1->count != param_0->count) {
        return 0;
    }
    for (p = param_0->e; p < param_0->count + param_0->e; p++, q++) {
        if (param_2 == q->id) {
            return (int)p;
        }
    }
    return 0;
}

void func_800ADEC4(A800ADEC4 *param_0, u8 *param_1, s32 param_2, s32 param_3) {
    E40 *e;
    E40 *end;
    u8 *q;
    q = param_1 + 8;
    if (param_0->count == *(s16 *)(param_1 + 4)) {
        e = param_0->e;
        end = (E40 *)(param_0->count * 0x40 + (u8 *)param_0 + 0x50);
        for (; e < end; e++, q += 0x10) {
            if (param_2 == *(s16 *)(q + 0xC)) {
                func_800F293C(e, param_3);
            }
        }
    }
}

int func_800ADF5C(Actor *param_0)
{
  s32 local_0 = *((s32 *) (((char *) param_0) + 0x8));
  s32 local_1;
  if (local_0 != 0)
  {
    local_1 = (s32) param_0;
    func_800E0A50((Actor *) ((((local_0 & 0xFFFFFFFFFFFFFFFF) & 0xFFFFFFFFFFFFFFFF) & 0xFFFFFFFFFFFFFFFF) & 0xFFFFFFFFFFFFFFFF), (Actor *) local_0, (Actor *) local_1);
  }
  heap_free((void *) param_0);
}

u8 *func_800ADF98(void) {
    u8 *temp_v0;

    temp_v0 = heap_alloc(0x50);
    (*(s32 *)((s8 *)(temp_v0) + (0))) = 0;
    (*(s32 *)((s8 *)(temp_v0) + (4))) = 0;
    (*(s32 *)((s8 *)(temp_v0) + (8))) = 0;
    (*(s16 *)((s8 *)(temp_v0) + (0xC))) = 0;
    func_80019CD4();
    mlMtxGet(temp_v0 + 0x10);
    return temp_v0;
}

int func_800ADFE0(param_0) s16 param_0;
{
  s16 *local_0;
  local_0 = func_800AE080(param_0);
  if (local_0[6] != 0)
  {
    func_800E0A70(local_0[6]);
  }
  func_8001B754(param_0);
}

s16 func_800AE020(void) {
    s16 local_0;
    Mtx *local_1;

    local_0 = func_8001B668(0, 0x50);
    local_1 = func_800AE080(local_0);
    local_1->m[0][0] = 0;
    *(s32*)((char*)local_1 + 4) = 0;
    *(s32*)((char*)local_1 + 8) = 0;
    *(s16*)((char*)local_1 + 0xC) = 0;
    func_80019CD4();
    mlMtxGet((char*)local_1 + 0x10);
    return local_0;
}

struct UnkStruct* func_800AE080(s16 param_0)
{
  if (param_0 == 0)
  {
    return 0;
  }
  else
  {
    return func_8001B798(param_0);
  }
}

func_800AE0B8(param_0) s32 * param_0;{
    if(param_0 != NULL){
        return param_0[0];
    }else{
        return 1;
    }
}

func_800AE0D0(s32 *param_0){
    if(param_0 != NULL){
        return param_0[0];
    }else{
        return 0;
    }
}

int func_800AE0E8(param_0) s16 param_0;
{
  if (param_0 != 0)
  {
    return func_800AE080(param_0)->unk0;
  }
  return 1;
}

int func_800AE124(param_0) s16 param_0;
{
  if (param_0 != 0)
  {
    return func_800AE080(param_0)->unk0;
  }
  return 0;
}

void func_800AE160(u8 **param_0, u8 *param_1, s32 param_2) {
    s16 var_v1;
    u8 *temp_v0;
    u8 *var_s0;

    var_s0 = *param_0;
    var_v1 = (*(s16 *)((s8 *)(param_1) + 4));
    if ((*(s32 *)((s8 *)(var_s0) + 4)) < var_v1) {
        temp_v0 = heap_realloc(var_s0, (var_v1 << 6) + 0x50);
        var_s0 = temp_v0;
        (*(s32 *)((s8 *)(temp_v0) + 4)) = (s32) (*(s16 *)((s8 *)(param_1) + 4));
        *param_0 = temp_v0;
        var_v1 = (*(s16 *)((s8 *)(param_1) + 4));
    }
    (*(s32 *)((s8 *)(var_s0) + 0)) = (s32) var_v1;
    func_800AE820(param_2, param_1, var_s0 + 0x50, (*(s32 *)((s8 *)(var_s0) + 8)));
}

void func_800AE1E8(s16 param_0, u8 *param_1, s32 param_2)
{
  u8 *local_4;
  int new_var2;
  s16 local_1;
  u8 *local_5;
  int new_var3;
  s8 *new_var;
  local_5 = func_800AE080(param_0);
  local_4 = local_5;
  local_1 = *((s16 *) (((s8 *) param_1) + 4));
  new_var3 = (local_1 << 6) + 0x50;
  if ((*((s32 *) (((s8 *) local_5) + 4))) < local_1)
  {
    new_var = ((s8 *) param_1) + 4;
    new_var2 = new_var3;
    local_5 = func_8001B710(param_0, new_var2);
    local_4 = local_5;
    *((s32 *) (((s8 *) local_5) + 4)) = (s32) (*((s16 *) new_var));
    local_1 = *((s16 *) (((s8 *) param_1) + 4));
  }
  *((s32 *) (((s8 *) local_5) + 0)) = (s32) local_1;
  func_800AE820(param_2, param_1, local_4 + 0x50, ((*((s16 *) (((s8 *) local_5) + 0xC))) != 0) ? (func_800E0A28(*((s16 *) (((s8 *) local_4) + 0xC)))) : (0));
}

void func_800AE290(param_0, param_1, param_2) s16 param_0; StateAE40C *param_1; s32 param_2; {
    BufferAE40C *local_4;
    MatrixAE40C *local_11;
    f32 local_0[3][3];
    f32 local_1[4];
    f32 local_2[3];
    f32 local_3[3];
    MatrixAE40C *local_5;
    MatrixAE40C *local_6;
    BoneAE40C *local_7;
    local_4 = func_800AE080(param_0);
    if (local_4->local_1 < param_1->local_0) {
        local_4 = func_8001B710(param_0, param_1->local_0 * 64 + 0x50);
        local_4->local_1 = param_1->local_0;
        }
    local_4->local_0 = param_1->local_0;
    local_6 = local_4->local_0 + local_4->local_2;
    local_5 = local_4->local_2;
    for (local_7 = param_1->local_1; local_5 < local_6; local_5++, local_7++) {
        func_800DFB7C(param_2, local_7->local_0, local_1, local_2, local_3);
        local_11 = local_4->local_2;
        if (local_7->local_1 == -1) func_80019CD4();
        else if (local_7->local_1 + 1 != local_5 - local_11) mlMtxSet(*(MatrixAE40C *)((local_7->local_1 << 6) + (u8 *)local_11));
        if (!func_800D9C4C(local_1)) {
            func_800D9CE8(local_1, local_0);
            func_80019BB8(local_0);
        }
        mlMtxGet(*local_5);
    }
}

void func_800AE40C(param_0, param_1, param_2) s16 param_0; StateAE40C *param_1; s32 param_2; {
    BufferAE40C *local_4;
    MatrixAE40C *local_11;
    f32 local_0[3][3];
    f32 local_1[4];
    f32 local_2[3];
    f32 local_3[3];
    MatrixAE40C *local_5;
    MatrixAE40C *local_6;
    BoneAE40C *local_7;
    local_4 = func_800AE080(param_0);
    if (local_4->local_1 < param_1->local_0) {
        local_4 = func_8001B710(param_0, param_1->local_0 * 64 + 0x50);
        local_4->local_1 = param_1->local_0;
        }
    local_4->local_0 = param_1->local_0;
    local_6 = local_4->local_0 + local_4->local_2;
    local_5 = local_4->local_2;
    for (local_7 = param_1->local_1; local_5 < local_6; local_5++, local_7++) {
        func_800DFB7C(param_2, local_7->local_0, local_1, local_2, local_3);
        local_11 = local_4->local_2;
        if (local_7->local_1 == -1) func_80019CD4();
        else if (local_7->local_1 + 1 != local_5 - local_11) mlMtxSet(*(MatrixAE40C *)((local_7->local_1 << 6) + (u8 *)local_11));
        if (!func_800D9C4C(local_1)) {
            func_800D9CE8(local_1, local_0);
            func_80019BB8(local_0);
        }
        mlMtxScale_xyz(local_2[0], local_2[1], local_2[2]);
        mlMtxGet(*local_5);
    }
}

void func_800AE598(s32 *param_0, s32 *param_1) {
    s32 local_0;
    s32 local_1;
    s32 local_2;
    s32 local_3;
    s32 local_4;
    s32 local_5;
    s32 local_24;
    s32 local_28;
    local_24 = (s32) (param_0 + 4);
    local_28 = *param_1;
    func_80116684((s32 *) local_24, local_28, *param_0 + 1, param_0);
    *param_1 += (*param_0 + 1) << 6;
    local_0 = *param_1;
    local_1 = *param_0;
    local_2 = *(s32 *) local_0;
    local_3 = *(s32 *) local_1;
    local_4 = local_2 + 1;
    local_5 = local_4 << 6;
}

void func_800AE5F0(void *param_0)
{
  void *local_0;
  local_0 = *(void **)((char *)param_0 + 8);
  if (local_0 != 0)
  {
    *(void **)((char *)param_0 + 8) = func_800E0A98(local_0, param_0);
  }
  defrag(param_0);
}

s32 func_800AE630(s32 *param_0, u8 *param_1, s32 param_2, s32 param_3)
{
  s32 temp_t8;
  u8 *var_s0;
  u8 *var_a0;
  u8 *temp_v0;
  s32 temp_t1;

  temp_t8 = (s32)param_0;
  var_s0 = param_1 + 8;
  if (param_0[0] != (*((s16 *) (param_1 + 4)))) {
    return 0;
  }
  var_a0 = ((u8 *) temp_t8) + 0x50;
  temp_v0 = (u8 *) ((param_0[0] << 6) + temp_t8 + 0x50);

  if (((u32) var_a0) < ((u32) temp_v0))
  {
    loop_3:
    var_a0 += 0;
    if (param_2 == (*((s16 *) (var_s0 + 12))))
    {
      func_800F23D0((u32) var_a0, param_3, var_s0);
      return 1;
    }
    var_a0 += 0x40;
    var_s0 += 0x10;
    temp_t1 = 1;
    if (((u32) var_a0) >= ((u32) temp_v0))
    {
      if (temp_t1)
      {
        goto block_6;
      }
    }
    goto loop_3;
  }
  block_6:
  return 0;
}

s32 func_800AE6BC(u8 *param_0)
{
  s16 temp_a1;
  s16 new_var;
  ;
  if ((*((s16 *) (((s8 *) param_0) + 0xC))) != 0)
  {
    new_var = *((s16 *) (((s8 *) param_0) + 0xC));
    return func_800E0A28(new_var, *((s16 *) (((s8 *) param_0) + 0xC)));
  }
  return *((s32 *) (((s8 *) param_0) + 0x8));
}

void func_800AE6FC(param_0, param_1) s32 param_0; s16 param_1; {
    *(s16 *)(param_0 + 0xc) = param_1;
}

s32 func_800AE708(s32 param_0, u8 *param_1, s32 *param_2, u8 *param_3) {
    s32 local_0;
    s32 local_1;
    u8 *local_2;
    u8 *local_3;

    if (func_800AE0B8() == 0) {
        return 0;
    }
    if ((*(s16 *)((s8 *)(param_1) + (4))) < (*(s16 *)((s8 *)(param_3) + (4)))) {
        return 0;
    }
    if ((*(f32 *)((s8 *)(param_3) + (0))) != (*(f32 *)((s8 *)(param_1) + (0)))) {
        return 0;
    }
    func_800ADCD0(param_2, param_3);
    local_3 = param_3 + 8;
    local_2 = ((*(s16 *)((s8 *)(param_3) + (4))) * 0x10) + param_3 + 8;
    local_1 = *param_2 + 0x50;
    if ((u32) local_3 < (u32) local_2) {
loop_7:
        local_0 = func_800ADE50(param_0, param_1, (*(s16 *)((s8 *)(local_3) + (0xC))));
        if (local_0 == 0) {
            return 0;
        }
        func_800F293C(local_1, local_0);
        local_3 += 0x10;
        local_1 += 0x40;
        if ((u32) local_3 >= (u32) local_2) {
            goto block_10;
        }
        goto loop_7;
    }
block_10:
    return 1;
}
