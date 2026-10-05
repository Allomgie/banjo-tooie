#include "common.h"

extern f32 func_80015D14(s32);
extern s32 func_800A89A0();
extern f32 func_800A8AD4(s32);
extern s32 func_800A8984();
extern void func_800CA7E4(s32, f32 *);
extern void func_800EFB24(f32 *, f32 *, f32 *);
extern void *func_800CA7AC(s32);
extern void func_800F23D0(void *, f32 *, f32 *);
extern void func_800A8A04(s32, s32 *, s32 *, s32 *, s32 *);
extern f32 func_800CA79C(s32);
extern f32 func_800CA6FC(s32);
extern f32 func_800F214C(f32, f32);
extern void func_800EFD24(f32 *);
extern f32 func_800CA7B4(s32);
extern void *func_800CA7A4(s32);
extern void func_800EF04C(f32 *, f32 *);
extern f32 func_800139F8(f32);
extern f32 func_80013B7C(f32, f32);
extern void func_800A8A88(s32, f32);
extern float D_8012AA04[10];
typedef struct { s32 value, duration, target; u8 state; u8 pad[3]; } LocalView;
extern void func_800A8A44(s32, s32 *, s32 *, s32 *, s32 *);
typedef struct { s32 local_0, local_1, local_2; u8 local_3; u8 pad[3]; } EntryC54F0;
typedef struct { EntryC54F0 e[5]; f32 unk50[5]; s32 unk64[5]; f32 f78; f32 f7C; } State_8012A9A0;
State_8012A9A0 D_8012A9A0;
extern void func_80015CE8(s32, s32);
extern void func_800CA6F0(s32, s32);
extern void func_800CA558(s32, f32);
extern void func_800CA510(s32, f32);
extern void func_800CAF34(s32);
typedef struct { s32 current, unused, maximum; u8 mode, pad[3]; } LocalEntry;
extern u8 D_8011A880[];
void func_800C54CC(s32 param_0, f32 param_1, f32 param_2);

void func_800C4B90(s32 param_0, f32 param_1, f32 param_2)
{
  s32 sp18;
  f32 sp20;
  s32 sp1C;
  s32 temp_v0;
  f32 temp_f8;
  sp1C = func_800A8984();
  temp_v0 = func_800A89A0(param_0);
  if ((temp_v0 != 0) && (sp1C != 0))
  {
    sp18 = temp_v0;
    sp20 = func_800A8AD4(param_0);
    temp_f8 = func_80015D14(sp18);
    temp_f8 = param_2 * temp_f8;
    *((f32 *) (((s8 *) (((f32 *) &D_8012A9A0))) + 0x7C)) += (param_1 * sp20) / 40.0f;
    *((f32 *) (((s8 *) (((f32 *) &D_8012A9A0))) + 0x78)) += temp_f8 / 1.3333334f;
  }
}

s32 func_800C4C34(s32 param_0, f32 *param_1, f32 *param_2, s32 *param_3) {
    f32 local_0[3];
    f32 local_1[3];
    f32 local_2;
    f32 local_3;
    f32 local_4;
    s32 local_5, local_6, local_7, local_8;
    s32 local_9;
    local_9 = func_800A8984(param_0);
    func_800CA7E4(local_9, local_1);
    func_800EFB24(local_0, param_1, local_1);
    func_800F23D0(func_800CA7AC(local_9), local_0, local_0);
    *param_3 = local_0[2] < (-1e-05f);
    if (!*param_3) {
        param_2[0] = param_2[1] = 0.0f;
        return 0;
    }
    func_800A8A04(param_0, &local_5, &local_6, &local_7, &local_8);
    local_2 = func_800CA79C(local_9) * local_8 * 0.5f;
    local_3 = 1.0f / local_0[2];
    local_4 = (f32)local_7 / local_8 / func_800CA6FC(local_9);
    param_2[0] = local_7 * 0.5f - local_0[0] * local_2 * local_3 * local_4;
    param_2[1] = local_0[1] * local_2 * local_3 + local_8 * 0.5f;
    if (param_2[0] < 0 || local_7 < param_2[0] || param_2[1] < 0 || local_8 < param_2[1]) return 0;
    param_2[0] += local_5;
    param_2[1] += local_6;
    return 1;
}

void func_800C4E58(s32 param_0, f32 *param_1, f32 *param_2) {
    f32 local_0[3];
    f32 local_1;
    f32 local_2;
    f32 local_3;
    s32 local_4;
    s32 local_5;
    s32 local_6;
    s32 local_7;
    s32 local_8;
    local_8 = func_800A8984(param_0);
    func_800A8A04(param_0, &local_4, &local_5, &local_6, &local_7);
    local_2 = func_800CA79C(local_8) * local_7 * 0.5f;
    if (func_800F214C(local_2, 1e-05f) == 0.0f) {
        func_800EFD24(param_2);
        return;
    }
    local_1 = 1.0f / local_2;
    local_3 = (f32)local_6 / local_7 / func_800CA6FC(local_8);
    param_2[2] = -func_800CA7B4(local_8) - param_1[2];
    param_2[1] = (param_1[1] - local_7 * 0.5f) * param_2[2] * local_1;
    param_2[0] = -(param_1[0] - local_6 * 0.5f) * param_2[2] * local_1 / local_3;
    func_800F23D0(func_800CA7A4(local_8), param_2, param_2);
    func_800CA7E4(local_8, local_0);
    func_800EF04C(param_2, local_0);
}

void func_800C5008(s32 param_0, f32 *param_1, f32 *param_2) {
    s32 local_0;
    s32 local_1;
    s32 local_2;
    s32 local_3;
    func_800A8A04(param_0, &local_0, &local_1, &local_2, &local_3);
    param_2[0] = param_1[0] * ((f32)local_2 / 304.0f);
    param_2[1] = param_1[1] * ((f32)local_3 / 228.0f);
}

void func_800C5094(s32 param_0, f32 param_1) {
    f32 sp34;
    f32 sp30;
    f32 sp2C;
    s32 sp28;
    s32 sp24;

    func_800A8A44(param_0, &sp34, &sp30, &sp2C, &sp28);
    func_800A8A04(param_0, &sp34, &sp30, &sp2C, &sp24);
    if (sp28 != sp24) {
        param_1 = 2.0f * func_80013B7C((f32) sp24, (f32) sp28 / func_800139F8(param_1 * 0.5f));
    }
    func_800A8A88(param_0, param_1);
}

void func_800C5148(s32 param_0, f32 param_1)
{
  f32 new_var;
  new_var--;
  new_var = param_1;
  D_8012A9A0.unk50[param_0] = param_1;
  func_800C5094(param_0, new_var);
}

float func_800C517C(s32 param_0){
    return D_8012A9A0.unk50[param_0];
}

float func_800C5190(s32 param_0){
    return D_8012AA04[param_0];
}

void func_800C51A4(s32 param_0, f32 param_1)
{
  f32 local_0 = param_1;
  f32 f1;
  f32 f2;
  D_8012AA04[param_0] = local_0;
  if (local_0 != 1.0f)
  {
    f1 = func_800C517C(param_0);
    f2 = func_80013B7C(func_800139F8(f1 * 0.5f), param_1);
    func_800C5094(param_0, f2 + f2);
  }
  else
  {
    f1 = func_800C517C(param_0);
    func_800C5094(param_0, f1);
  }
}

void func_800C524C(s32 param_0, s32 param_1)
{
  s32 sp44;
  s32 sp40;
  s32 sp3C;
  s32 sp38;
  s8 _sfpad[8];
  s32 sp2C;
  s32 sp28;
  sp2C = func_800A89A0(param_0);
  sp28 = func_800A8984(param_0);
  func_800A8A44(param_0, &sp44, &sp40, &sp3C, &sp38);
 do { } while (0);
  func_80015B34(sp2C, sp44, sp40 + param_1, sp3C, sp38 - (param_1 * 2));
  func_80015CE8(sp2C, sp28);
  func_800C5148(param_0, D_8012A9A0.unk50[param_0]);
}

s32 func_800C52F4(s32 param_0, s32 param_1)
{
    s32 local_4;
    s32 local_0;
    s32 local_1;
    s32 local_2;
    s32 local_3;
    LocalView *local_5;
    local_5 = &((LocalView *) &D_8012A9A0)[param_0];
    if (local_5->state == 1 || local_5->state == 2) return 0;
    local_5->state = 1;
    local_5->value = 0;
    local_5->duration = param_1;
    func_800A8A44(param_0, &local_0, &local_1, &local_2, &local_3);
    local_4 = local_2 * 0.5625f;
    if (local_4 & 1) local_4++;
    local_5->target = (local_3 - local_4) / 2;
    if (!param_1) {
        local_5->value = local_5->target;
        local_5->state = 2;
        func_800C524C(param_0, local_5->target);
    }
    return 1;
}

s32 func_800C53EC(s32 param_0, s32 param_1)
{
  u8 *temp_v0;
  temp_v0 = (param_0 * 0x10) + (u8 *) ((s32 *) &D_8012A9A0);
  if ((*((u8 *) (((s8 *) temp_v0) + 0xC)) == 0) || (3 == *((u8 *) (((s8 *) temp_v0) + 0xC))))
  {
    return 0;
  }
  *((u8 *) (((s8 *) temp_v0) + 0xC)) = 3U;
  *((s32 *) (((s8 *) temp_v0) + 4)) = param_1;
  func_800C524C(param_0, 0);
  if (param_1 == 0)
  {
    *((s32 *) (((s8 *) temp_v0) + 0)) = 0;
  }
  return 1;
}

void func_800C5464(void) {
    float var_f20;
    float var_f22;
    s32 var_s0;
    s32 var_s1;

    var_f20 = 40.0f;
    var_f22 = 1.0f;
    var_s0 = 0;
    var_s1 = 5;

    do {
        func_800C54CC(var_s0, var_f20, var_f22);
        var_s0 += 1;
    } while (var_s0 != var_s1);
}

void func_800C54CC(s32 param_0, f32 param_1, f32 param_2)
{
  float *local_0 = &((f32 *) &D_8012A9A0)[param_0];
  local_0[20] = param_1;
  local_0[25] = param_2;
}

void func_800C54F0(s32 param_0) {
    f32 local_0;
    s32 local_1;
    s32 local_2;
    EntryC54F0 *local_3;
    f32 local_4, local_5, local_6;
    local_1 = func_800A89A0();
    local_2 = func_800A8984(param_0);
    local_3 = &D_8012A9A0.e[param_0];
    switch (local_3->local_3) {
    case 1:
        local_3->local_0 += local_3->local_1;
        if (local_3->local_0 >= local_3->local_2) {
            local_3->local_0 = local_3->local_2;
            local_3->local_3 = 2;
            func_800C524C(param_0, local_3->local_0);
        }
        break;
    case 3:
        local_3->local_0 -= local_3->local_1;
        if (local_3->local_0 < 0) { local_3->local_0 = 0; local_3->local_3 = 0; }
        break;
    }
    if (local_1 && local_2) {
        func_80015CE8(local_1, local_2);
        func_800CA6F0(local_2, ((s32 *) D_8012AA04)[param_0]);
        local_4 = func_800A8AD4(param_0);
        local_0 = func_800CA6FC(local_2);
        local_6 = local_4 + D_8012A9A0.f7C;
        local_5 = local_0 * local_4 + D_8012A9A0.f78;
        func_800CA558(local_2, local_6);
        func_800CA510(local_2, local_5 / local_6);
        func_800CAF34(local_2);
    }
    D_8012A9A0.f7C = 0.0f;
    D_8012A9A0.f78 = D_8012A9A0.f7C;
}

void func_800C5668(s32 param_0, void *param_1)
{
    f32 local_5;
    LocalEntry *local_6;
    s32 local_0, local_1, local_2, local_3;
    s32 local_4;
    s32 local_7;
    local_6 = &((LocalEntry *) &D_8012A9A0)[param_0];
    if (local_6->mode == 3 || local_6->mode == 1) {
        func_800A8A04(param_0, &local_0, &local_1, &local_2, &local_3);
        local_4 = local_6->current;
        local_5 = (f32)local_6->current / local_6->maximum;
        local_7 = local_5 * 255.0f;
        func_800B9A24(param_1, local_7, D_8011A880, local_0, local_1, local_2, local_4);
        func_800B9A24(param_1, local_7, D_8011A880, local_0, local_1+local_3-local_4, local_2, local_4);
    }
}
