#include "common.h"

extern s32 D_8011A480;
extern s32 D_8011A498;
extern s32 D_80127770;
typedef struct { s16 f0; s8 f2; s8 f3; s16 a[4]; s16 b[4]; } Struct_80127780;
Struct_80127780 D_80127780;
extern char D_80127783;
extern s16 D_80127784[];
extern s16 D_8012778C[];
extern u8 D_80127782;

void func_800A9EC0(s32 param_0)
{
  s32 *local_0;
  s32 new_var;
 new_var = param_0; D_80127770 = 0x3E800;
  ;
 do { local_0 = (s8 *) (&D_8011A480); loop_1: if (new_var == (*((s16 *) (local_0 + 0)))) { new_var = 9; new_var = (*((s16 *) (((s8 *) local_0) + 2))) << new_var; D_80127770 = new_var << 1; return; } } while (0);
  local_0 += 1;
  if (local_0 == (&D_8011A498))
  {
    return;
  }
  goto loop_1;
}

func_800A9F14(param_0){
    if(param_0 == 2)
        return 3;
    return 0x12;
}

int func_800A9F30()
{
  s32 local_0;
  func_8001BDAC(&local_0, 1);
  return D_80127770 < local_0;
}

int func_800A9F60(param_0) s32 param_0;
{
  func_800DA3B8(param_0 + 0xD1B);
}

int func_800A9F80(param_0) s32 param_0;
{
  func_800DA298(param_0 + 0xD1B);
}

s32 func_800A9FA0(param_0) s32 param_0; {
    s32 local_0 = 0;
    s32 local_1;
    for (local_1 = 0x40; local_1 != 0x4E; local_1++) {
        if (func_800A9F80(local_1) && local_0++ == param_0) break;
    }
    return local_1;
}

void func_800AA00C(void) {
    s32 i;
    D_80127780.f0 = -1;
    D_80127780.f3 = 0;
    D_80127780.f2 = 0;
    for (i = 0; i < 4; i++) {
        D_80127780.a[i] = D_80127780.b[i] = 0;
    }
}

void func_800AA054(s32 arg0)
{
    func_800A9F60(arg0,1);
}

int func_800AA074()
{
  s32 local_0;
  for (local_0 = 0x40; local_0 < 0x4E; local_0++)
  {
    func_800A9F60(local_0 | 0, 0);
  }

}

u8 func_800AA0B8()
{
  return D_80127783;
}

int func_800AA0C4()
{
  return (*((s16 *) &D_80127780));
}

s32 func_800AA0D0(void) {
    s32 i;
    s32 local_0;

    local_0 = 0;
    for(i = 0x40; i < 0x4E; i++){
        local_0 += func_800A9F80(i);
    }
    return local_0;
}

s32 func_800AA120(void){
    func_800A9FA0((*((s16 *) &D_80127780)) + 1);
}

int func_800AA148()
{
  func_800A9FA0((*((s16 *) &D_80127780)));
}

int func_800AA16C(s32 param_0)
{
  return D_80127784[param_0];
}

int func_800AA180(s32 param_0)
{
  return D_8012778C[param_0];
}

s32 func_800AA194(void)
{
  return (*((u8 *) &D_80127782));
}

void func_800AA1A0(void) {
    s32 i;
    D_80127780.f3 = 1;
    D_80127780.f0++;
    D_80127780.f2 = 0;
    for (i = 0; i < 4; i++) {
        D_80127780.b[i] = 0;
    }
    _gcfrontend_entrypoint_7(func_800AA148(), 1);
}

int func_800AA200(unsigned int param_0)
{
  unsigned int new_var;
  D_80127782 = param_0;
  new_var = param_0;
  D_80127782 = new_var;
}

int func_800AA20C(s32 param_0, int param_1)
{
  D_8012778C[param_0] = param_1;
}

int func_800AA220(s32 param_0, s32 param_1)
{
  ((s16 *) &D_80127780)[param_0 + 2] += param_1;
  return;
}

int func_800AA240()
{
  s32 local_0;
  local_0 = func_800AA0C4();
  return local_0 >= func_800AA0D0() - 1;
}

int func_800AA274()
{
  func_800A9F80();
}
