#include "common.h"

extern void *D_80136EE0;
extern s32 vector_defrag();
typedef struct { u8 pad0[0x1A]; u16 unk1A : 11; u16 unk1A_lo : 5; } E_1066C0;
extern void vector_erase_unordered(void *, s32);
extern s32 vector_size();
extern E_1066C0 **vector_at();
typedef struct { u8 pad0[0x18]; u16 unk18; u16 unk1A; } S_1069A4;

void func_801065E0()
{
  D_80136EE0 = vector_new(0x9C, 0x1E);
}

void func_80106608()
{
    vector_free(D_80136EE0);
    D_80136EE0 = 0;
}

void func_80106630()
{
  if (((s32) D_80136EE0) != 0)
  {
    D_80136EE0 = vector_defrag(((s32) D_80136EE0));
  }
}

s32 func_80106668(s32 *param_0) {
    s32 local_1;

    *param_0 = 0;
    local_1 = vector_push_back(((s32 *) &D_80136EE0));
    *param_0 = vector_index_of(((s32) D_80136EE0), local_1);
    bzero(local_1, 0x9C);
    return local_1;
}

void func_801066C0(s32 param_0) {
    vector_erase_unordered(D_80136EE0, param_0);
    if (param_0 < vector_size(D_80136EE0)) {
        (*vector_at(D_80136EE0, param_0))->unk1A = param_0;
    }
}

s32 func_80106730(void){
    if(((s32) D_80136EE0) == 0){
        return 0;
    }else{
        return vector_size(((s32) D_80136EE0));
    }
}

s32 func_80106768(s32 param_0){
    s32 local_0 = param_0;
    vector_at(((s32) D_80136EE0), local_0);
}

void func_80106790(void *param_0)
{
  vector_at(D_80136EE0, (u32)(((u16 *)param_0)[13]) >> 5, param_0);
}

int func_801067C4(int *param_0)
{
  if (((int) D_80136EE0) == 0)
  {
    return 0;
  }
  param_0[0] = vector_size(((int) D_80136EE0)) - 1;
  if (param_0[0] >= 0)
  {
    return vector_at(((int) D_80136EE0), param_0[0]);
  }
  return 0;
}

void *func_8010682C(s32 *param_0) {
    s32 n;
    if (D_80136EE0 == 0) {
        return 0;
    }
    n = vector_size(D_80136EE0);
    if (*param_0 >= n) {
        *param_0 = n;
    }
    if (*param_0 > 0) {
        *param_0 = *param_0 - 1;
        return vector_at(D_80136EE0, *param_0);
    }
    return 0;
}

int func_801068A8(s32 *param_0)
{
  s32 local_0;
  int new_var;
  if (((int) D_80136EE0) == 0)
  {
    return 0;
  }
  local_0 = vector_size(((int) D_80136EE0) ^ 0, ((int) D_80136EE0), param_0);
  if (local_0 > 0)
  {
    new_var = *param_0;
    if ((new_var < 0) || (new_var >= local_0))
    {
      *param_0 = 0;
      new_var = 0;
    }
    return vector_at(((int) D_80136EE0), new_var, param_0);
  }
  return 0;
}

void *func_80106920(s32 *param_0) {
    s32 n;
    if (D_80136EE0 == 0) {
        return 0;
    }
    n = vector_size(D_80136EE0);
    *param_0 = *param_0 - 1;
    if ((*param_0 < 0) || (*param_0 >= n)) {
        *param_0 = n - 1;
    }
    if (*param_0 >= 0) {
        return vector_at(D_80136EE0, *param_0);
    }
    return 0;
}

s32 func_801069A4(S_1069A4 *param_0) {
    s32 rv;
    if (D_80136EE0 == 0) { return 0; }
    if ((param_0 == 0) || ((param_0->unk18 & 1) == 0)) { return 0; }
    rv = (s32)((u32)param_0->unk1A >> 5) < vector_size(D_80136EE0);
    return rv;
}
