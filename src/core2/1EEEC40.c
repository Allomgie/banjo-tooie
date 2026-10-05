#include "core2/1EEEC40.h"

typedef struct { u8 pad0[0xC]; f32 unkC; f32 unk10; } T_115358;
typedef struct { u8 pad0[0x14]; T_115358 *unk14; } S_115358;
typedef struct { u8 pad0[0xC]; f32 unkC; f32 unk10; f32 unk14; f32 unk18; } S801154A4;
extern void func_801107F0();
extern void func_800EFB24(f32 *, f32 *, f32 *);
extern f32 func_800EEF94(f32 *);
f32 func_800EEB40(void*, s32);
void func_80115428(s32 *param_0, f32 param_1, f32 param_2);

s32 func_80115350() 
{
    return 0x1C;
}

f32 func_80115358(S_115358 *param_0, f32 param_1) {
    T_115358 *t = param_0->unk14;
    if (param_1 < t->unkC) {
        param_1 = t->unkC;
    } else if (t->unk10 < param_1) {
        param_1 = t->unk10;
    }
    return param_1;
}

void func_8011539C(void *param_0, f32 param_1, f32 param_2, f32 param_3)
{
  f32 *new_var;
  f32 sp20;
  f32 temp_f2;
  void *sp28;
  (*((f32 **) (((char *) param_0) + 0x14)))[0] = param_1;
  (*((f32 **) (((char *) param_0) + 0x14)))[1] = param_2;
  (*((f32 **) (((char *) param_0) + 0x14)))[2] = param_3;
  new_var = &param_3;
  sp28 = param_0;
  temp_f2 = param_3 * (*new_var);
  sp20 = sqrtf((param_1 * param_1) + temp_f2);
  func_80115428(param_0, sp20, sqrtf((param_2 * param_2) + temp_f2));
}

void func_80115428(s32 *param_0, f32 param_1, f32 param_2) {
    *(f32 *)((u8 **)param_0[5] + 5) = param_1;
    *(f32 *)((u8 **)param_0[5] + 6) = param_2;
}

void func_80115444(u8 *param_0, f32 *param_1, f32 *param_2) {
    *param_1 = (*(f32 *)((s8 *)((*(u8 **)((s8 *)(param_0) + (0x14)))) + (0xC)));
    *param_2 = (*(f32 *)((s8 *)((*(u8 **)((s8 *)(param_0) + (0x14)))) + (0x10)));
}

f32 func_80115460(void *arg)
{
    return ((f32 *)(*(void **)((char *)arg + 0x14)))[2];
}

f32 func_8011546C(void *arg)
{
    return ((f32 *)(*(void **)((char *)arg + 0x14)))[0];
}

f32 func_80115478(void *param_0)
{

  return ((f32 *) (*((void **) (((char *) param_0) + 0x14))))[1];
}

void func_80115484(PlayerState* arg0, f32* arg1)
{
    func_80112524(arg0,arg1);
}

void func_801154A4(u8 *param_0) {
    f32 b[3];
    f32 a[3];
    f32 c[3];
    f32 d;

    if ((*(S801154A4 **)(param_0 + 0x14))->unkC < (*(S801154A4 **)(param_0 + 0x14))->unk14) {
        func_80115484(param_0, a);
        func_801107F0(param_0, b);
        func_800EFB24(c, b, a);
        d = func_800EEF94(c);
        if ((*(S801154A4 **)(param_0 + 0x14))->unk14 < d) {
            (*(S801154A4 **)(param_0 + 0x14))->unkC = (*(S801154A4 **)(param_0 + 0x14))->unk14;
        } else if ((*(S801154A4 **)(param_0 + 0x14))->unkC < d) {
            (*(S801154A4 **)(param_0 + 0x14))->unkC = d;
        }
    } else {
        (*(S801154A4 **)(param_0 + 0x14))->unkC = (*(S801154A4 **)(param_0 + 0x14))->unk14;
    }
    (*(S801154A4 **)(param_0 + 0x14))->unk10 = (*(S801154A4 **)(param_0 + 0x14))->unk18;
}

void func_80115564(u8 *param_0)
{
  u8 **local_0;
  u8 *new_var;
  u8 **local_1;
 do { local_0 = *((u8 ***) (((u8 *) param_0) + 0x14)); new_var = (u8 *) local_0; *((f32 *) (new_var + 0xC)) = *((f32 *) (new_var + 0x14)); } while (0);
  local_1 = *((u8 ***) (((u8 *) param_0) + 0x14));
  *((f32 *) (((u8 *) local_1) + 0x10)) = *((f32 *) (((u8 *) local_1) + 0x18));
}

s32 func_80115580(u8 *param_0, s32 param_1) {
    f32 func_ret;
    f32 temp_f2;
    s32 sp1C;

    func_801107F0(param_0, &sp1C);
    func_ret = func_800EEB40(&sp1C, param_1);
    temp_f2 = (*(f32 *)((u8 *)*(u8 **)(param_0 + 0x14) + 0x10)) * 1.5f;
    return (temp_f2 * temp_f2) < func_ret;
}

f32 func_801155E8(void *param_0)
{
  u32 *t6 = *((u32 **) (((u8 *) param_0) + 0x14));
  f32 val = *((f32 *) (((u8 *) (*((u32 **) (((u8 *) param_0) + 0x14)))) + 0x10));
  return (*((f32 *) (((u8 *) t6) + 0x10))) * 1.5f;
}
