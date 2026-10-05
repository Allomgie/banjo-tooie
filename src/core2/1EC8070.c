#include "core2/1EC8070.h"

extern f32 func_800137F4(f32);
extern f32 func_80013788(void);
extern void func_800EFD24(f32 [3]);
extern f32 func_800138D0(f32);
extern f32 mlAbsF(f32);
extern f32 func_800137AC(f32);
extern f32 func_800137C4(void);
extern f32 func_800136E4(f32);
extern void func_800EE7F8(f32 param_0[3], f32 param_1[3]);
extern f32 sqrtf(f32 x);
extern f32 D_80125EA0;
extern f32 func_800EEAA4(f32 *, f32 *);
extern void func_800EF3DC(f32 *, f32 *);
void func_800EF214(f32 param_0[3], f32 param_1, f32 param_2, f32 param_3);
int func_800EFA20(f32 *param_0, f32 param_1[3], f32 param_2);

// TODO rename operations based on whether they output to a new vector or output to an input vector.
// add vs sum/subtract vs difference? What to do for scalar multiplication? apply_scale vs scale?

// ml_vec3f_sum
void func_800EE780(f32 dst[3], f32 a[3], f32 b[3]) {
    dst[0] = a[0] + b[0];
    dst[1] = a[1] + b[1];
    dst[2] = a[2] + b[2];
}

// ml_vec3f_scaled_sum
void func_800EE7B4(f32 dst[3], f32 a[3], f32 b[3], f32 scale) {
    dst[0] = a[0] + b[0] * scale;
    dst[1] = a[1] + b[1] * scale;
    dst[2] = a[2] + b[2] * scale;
}

// ml_vec3f_copy
void func_800EE7F8(f32 dst[3], f32 src[3]) {
    dst[0] = src[0];
    dst[1] = src[1];
    dst[2] = src[2];
}

// ml_vec3s_copy
void func_800EE814(s16 dst[3], s16 src[3]) {
    dst[0] = src[0];
    dst[1] = src[1];
    dst[2] = src[2];
}

// ml_vec3i_copy
void func_800EE830(s32 dst[3], s32 src[3]) {
    dst[0] = src[0];
    dst[1] = src[1];
    dst[2] = src[2];
}

// ml_vec3i_to_vec3f
void func_800EE84C(f32 dst[3], s32 src[3]) {
    dst[0] = src[0];
    dst[1] = src[1];
    dst[2] = src[2];
}

// ml_vec3s_to_vec3f
void func_800EE88C(f32 dst[3], s16 src[3]) {
    dst[0] = src[0];
    dst[1] = src[1];
    dst[2] = src[2];
}

// ml_vec3s_to_vec3i
void func_800EE8CC(s32 dst[3], s16 src[3]) {
    dst[0] = src[0];
    dst[1] = src[1];
    dst[2] = src[2];
}

// ml_vec2f_to_vec3f
void func_800EE8E8(f32 dst[3], f32 src[2]) {
    dst[0] = src[0];
    dst[1] = 0;
    dst[2] = src[1];
}

// ml_vec3f_to_vec3i
void func_800EE904(s32 dst[3], f32 src[3]) {
    dst[0] = src[0];
    dst[1] = src[1];
    dst[2] = src[2];
}

// ml_vec3f_to_vec3s
void func_800EE940(s16 dst[3], f32 src[3]) {
    dst[0] = src[0];
    dst[1] = src[1];
    dst[2] = src[2];
}

// ml_vec3f_cross_product
void func_800EE97C(f32 dst[3], f32 a[3], f32 b[3]) {
    dst[0] = a[1] * b[2] - a[2] * b[1];
    dst[1] = a[2] * b[0] - a[0] * b[2];
    dst[2] = a[0] * b[1] - a[1] * b[0];
}

// ml_vec3i_cross_product
void func_800EE9EC(f32 dst[3], s32 a[3], s32 b[3]) {
    dst[0] = a[1] * b[2] - a[2] * b[1];
    dst[1] = a[2] * b[0] - a[0] * b[2];
    dst[2] = a[0] * b[1] - a[1] * b[0];
}

// ml_vec3f_dot_product
f32 func_800EEAA4(f32 a[3], f32 b[3]) {
    return a[0] * b[0] + a[1] * b[1] + a[2] * b[2];
}

// ml_vec3f_distance
f32 func_800EEAD4(f32 a[3], f32 b[3]) {
    f32 delta[3];
    delta[0] = a[0] - b[0];
    delta[1] = a[1] - b[1];
    delta[2] = a[2] - b[2];
    return sqrtf(SQ(delta[0]) + SQ(delta[1]) + SQ(delta[2]));
}

// ml_vec3f_distance_sq
f32 func_800EEB40(f32 a[3], f32 b[3]) {
    f32 delta[3];
    delta[0] = a[0] - b[0];
    delta[1] = a[1] - b[1];
    delta[2] = a[2] - b[2];
    return SQ(delta[0]) + SQ(delta[1]) + SQ(delta[2]);
}

void func_800EEB9C(f32 arg0[3], f32 arg1, f32 arg2) {
    arg0[0] = func_800137F4(arg1) * arg2;
    arg0[1] = 0.0f;
    arg0[2] = func_80013788() * arg2;
}

void func_800EEBF0(f32 *param_0, f32 *param_1, f32 param_2)
{
  func_800EFD24(param_0);
  func_800EF214(param_0, param_1[0], param_1[1], param_2);
}

void func_800EEC30(f32 param_0[3], f32 param_1, f32 param_2, f32 param_3)
{
  func_800EFD24(param_0);
  func_800EF214(param_0, param_1, param_2, param_3);
}

void func_800EEC70(u8 *param_0, f32 param_1, f32 param_2, f32 param_3) {
    f32 sp1C;
    sp1C = func_800138D0(param_1) * param_3;
    (*(f32 *)((s8 *)param_0 + 4)) = 0.0f;
    (*(f32 *)((s8 *)param_0 + 0)) = func_800137F4(param_2) * sp1C;
    (*(f32 *)((s8 *)param_0 + 8)) = func_80013788() * sp1C;
}

int func_800EECE0(f32 param_0[3], f32 param_1[3])
{
  return (param_0[0] == param_1[0]) && (param_0[1] == param_1[1]) && (param_0[2] == param_1[2]);
}

int func_800EED58(s32 *param_0, s32 *param_1)
{
  int new_var;
  int new_var2;
  new_var = param_0[0] == param_1[0];
  if (new_var)
  {
    new_var2 = param_0[1] == param_1[1];
    if (new_var2)
    {
      return param_0[2] == param_1[2];
    }
  }
}

int func_800EEDA0(s16 *param_0, s16 *param_1)
{
  int new_var;
  int new_var2;
  new_var2 = param_0[0] == param_1[0];
  if (new_var2)
  {
    new_var = param_0[1] == param_1[1];
    if (new_var)
    {
      return param_0[2] == param_1[2];
 } }
}

int func_800EEDE8(f32 *param_0, f32 *param_1, f32 param_2) {
    return mlAbsF(param_0[0] - param_1[0]) < param_2
        && mlAbsF(param_0[1] - param_1[1]) < param_2
        && mlAbsF(param_0[2] - param_1[2]) < param_2;
}

int func_800EEEA8(f32 *param_0) { return !((param_0[0] != 0.0f) || (param_0[1] != 0.0f) || (param_0[2] != 0.0f)); }

s32 func_800EEF24(f32 param_0[3])
{
  unsigned char local_0;
  local_0 = 0;
  if (param_0[0] != 0.0f)
  {
    local_0 = 1;
  }
  if (local_0 == 0)
  {
    local_0 = 0;
    if (param_0[1] != 0.0f)
    {
      local_0 = 1;
    }
    if (local_0 == 0)
    {
      local_0 = 0;
      if (param_0[2] != 0.0f)
      {
        local_0 = 1;
      }
    }
  }
  if (param_0)
  {
  }
  return local_0;
}

f32 func_800EEF94(f32 param_0[3])
{
  f32 local_0;
  f32 new_var;
  f32 new_var3;
  f32 new_var2;
  new_var = param_0[2];
  new_var2 = param_0[0];
  local_0 = new_var2 * new_var2;
  new_var3 = param_0[1];
  local_0 += new_var3 * new_var3;
  local_0 = local_0 + (new_var * new_var);
  return sqrtf(local_0);
}

f32 func_800EEFD4(f32 param_0[3]) {
    return param_0[0] * param_0[0] + param_0[1] * param_0[1] + param_0[2] * param_0[2];
}

int func_800EEFFC(f32 param_0[3])
{
  f32 new_var6;
  float new_var;
  f32 new_var4;
  f32 new_var3;
  f32 local_0;
  int new_var5;
  f32 new_var2;
  new_var6 = param_0[2];
  local_0 = (new_var4 = new_var6);
  new_var = local_0 * new_var4;
  new_var2 = param_0[0];
  local_0++;
  local_0--;
  new_var4 = new_var;
  if (1)
  {
    new_var3 = new_var2;
    new_var5 = !new_var4;
    local_0 = new_var3;
    local_0 = local_0 * new_var2;
    new_var2 = new_var2;
    {
    }
    local_0 = local_0 + (new_var4 * 1.0f);
  }
  new_var = local_0;
  if (new_var)
  {
  }
  sqrtf(local_0);
}

f32 func_800EF030(f32 *param_0) {
    f32 local_0;
    f32 local_1;

    local_0 = param_0[2];
    local_1 = param_0[0];
    return (local_0 * local_0) + (local_1 * local_1);
}

void func_800EF04C(f32 *param_0, f32 *param_1){
    param_0[0] += param_1[0];
    param_0[1] += param_1[1];
    param_0[2] += param_1[2];
}

func_800EF080(s16 *param_0, s16 *param_1){
    param_0[0] += param_1[0];
    param_0[1] += param_1[1];
    param_0[2] += param_1[2];
}

func_800EF0B4(s16 *param_0, f32 param_1[3]) {
    param_0[0] += param_1[0];
    param_0[1] += param_1[1];
    param_0[2] += param_1[2];
}

func_800EF11C(f32 param_0[3], s16 param_1[3]){
    param_0[0] += param_1[0];
    param_0[1] += param_1[1];
    param_0[2] += param_1[2];
}

func_800EF174(f32 param_0[3], f32 param_1[3], f32 param_2){
    param_0[0] += param_1[0]*param_2;
    param_0[1] += param_1[1]*param_2;
    param_0[2] += param_1[2]*param_2;
}

void func_800EF1B8(f32 *param_0, f32 param_1, f32 param_2) {
    param_0[0] += param_2 * func_800137F4(param_1);
    param_0[2] += param_2 * func_80013788();
}

void func_800EF214(f32 param_0[3], f32 param_1, f32 param_2, f32 param_3) {
    f32 local_0;
    local_0 = func_800137AC(param_1) * param_3;
    param_0[1] += param_3 * func_800137C4();
    param_0[0] += local_0 * func_800137F4(param_2);
    param_0[2] += local_0 * func_80013788();
}

void func_800EF2A0(f32 param_0[3])
{
  f32 local_0;
  if ((local_0 = param_0[0] * param_0[0] + param_0[1] * param_0[1] + param_0[2] * param_0[2]) != 0.0f)
  {
    local_0 = sqrtf(local_0);
    param_0[0] *= 1.0f / local_0;
    param_0[1] *= 1.0f / local_0;
    param_0[2] *= 1.0f / local_0;
  }
}

// ml_vec3f_apply_scale
void func_800EF334(f32 vec[3], f32 scale) {
    vec[0] *= scale;
    vec[1] *= scale;
    vec[2] *= scale;
}

// ml_vec3f_set_length
void func_800EF368(f32 vec[3], f32 target_length) {
    f32 length_sq;

    length_sq = SQ(vec[0]) + SQ(vec[1]) + SQ(vec[2]);
    if (length_sq != 0.0f) {
        func_800EF334(vec, target_length / sqrtf(length_sq));
    }
}

// ml_vec3f_subtract
void func_800EF3DC(f32 dst[3], f32 src[3]) {
    dst[0] -= src[0];
    dst[1] -= src[1];
    dst[2] -= src[2];
}

void func_800EF410(s32 param_0, f32 param_1[3])
{
  f32 sum = ((param_1[0] * param_1[0]) + (param_1[1] * param_1[1])) + (param_1[2] * param_1[2]);
  if (sum != 0.0f) {
    func_800EFA20(param_0, param_1, 1.0f / sqrtf(sum));
  } else {
    func_800EE7F8(param_0, param_1);
  }
}

void func_800EF49C(f32 *param_0) {
    param_0[0] = func_800136E4(param_0[0]);
    param_0[1] = func_800136E4(param_0[1]);
    param_0[2] = func_800136E4(param_0[2]);
}

void func_800EF4E4(f32 *param_0, f32 param_1, f32 param_2, f32 param_3, f32 param_4, f32 param_5) {
    f32 local_0;
    f32 local_1;
    f32 local_2;
    local_0 = func_800137F4(param_1);
    local_1 = func_80013788();
    local_2 = param_4 * local_0 + param_5 * local_1;
    param_0[1] = param_4 * local_1 - param_5 * local_0;
    local_0 = func_800137F4(param_2);
    local_1 = func_80013788();
    param_0[0] = local_2 * local_0 + param_3 * local_1;
    param_0[2] = local_2 * local_1 - param_3 * local_0;
}

void func_800EF5A0(f32 *param_0, f32 *param_1, f32 param_2, f32 param_3, f32 param_4)
{
    f32 local_0;
    f32 local_1;
    f32 local_2;
    local_0 = func_800137F4(param_1[0]);
    local_1 = func_80013788();
    local_2 = param_3 * local_0 + param_4 * local_1;
    param_0[1] = param_3 * local_1 - param_4 * local_0;
    local_0 = func_800137F4(param_1[1]);
    local_1 = func_80013788();
    param_0[0] = local_2 * local_0 + param_2 * local_1;
    param_0[2] = local_2 * local_1 - param_2 * local_0;
    local_0 = func_800137F4(param_1[2]);
    local_1 = func_80013788();
    local_2 = param_0[0] * local_1 - param_0[1] * local_0;
    param_0[1] = param_0[0] * local_0 + param_0[1] * local_1;
    param_0[0] = local_2;
}

void func_800EF6A8(f32 *param_0, f32 *param_1, f32 param_2, f32 param_3, f32 param_4) {
    f32 local_0;
    f32 local_1;
    f32 local_2;
    f32 local_3;
    local_0 = func_800137F4(param_1[2]);
    local_1 = func_80013788();
    param_0[1] = param_2 * local_0 + param_3 * local_1;
    param_0[0] = param_2 * local_1 - param_3 * local_0;
    local_0 = func_800137F4(param_1[0]);
    local_1 = func_80013788();
    local_2 = param_0[1] * local_0 + param_4 * local_1;
    param_0[1] = param_0[1] * local_1 - param_4 * local_0;
    local_0 = func_800137F4(param_1[1]);
    local_1 = func_80013788();
    local_3 = param_0[0];
    param_0[2] = local_2 * local_1 - local_3 * local_0;
    param_0[0] = local_3 * local_1 + local_2 * local_0;
}

void func_800EF7B0(f32 *param_0, f32 *param_1, f32 param_2, f32 param_3, f32 param_4)
{
    f32 local_0;
    f32 local_1;
    f32 local_2;
    local_0 = func_800137AC(param_1[1]);
    local_1 = func_800137C4();
    local_2 = param_4 * local_1 + param_2 * local_0;
    param_0[1] = param_3;
    param_0[2] = param_4 * local_0 - param_2 * local_1;
    param_0[0] = local_2;
    local_0 = func_800137AC(param_1[0]);
    local_1 = func_800137C4();
    local_2 = param_0[1] * local_0 - param_0[2] * local_1;
    param_0[2] = param_0[1] * local_1 + param_0[2] * local_0;
    param_0[1] = local_2;
    local_0 = func_800137AC(param_1[2]);
    local_1 = func_800137C4();
    local_2 = param_0[0] * local_0 - param_0[1] * local_1;
    param_0[1] = param_0[0] * local_1 + param_0[1] * local_0;
    param_0[0] = local_2;
}

void func_800EF8BC(f32 *param_0, f32 *param_1, f32 param_2) {
    f32 local_0;
    f32 local_1;
    f32 local_2;
    local_0 = func_800137AC(param_2);
    local_1 = func_800137C4();
    param_0[0] = param_1[0];
    local_2 = param_1[1] * local_0 - param_1[2] * local_1;
    param_0[2] = param_1[1] * local_1 + param_1[2] * local_0;
    param_0[1] = local_2;

}

void func_800EF934(f32 param_0[3], f32 param_1[3], f32 param_2)
{
    f32 s;
    f32 c;
    f32 x;
    s = func_800137AC(param_2);
    c = func_800137C4();
    x = param_1[2] * c + param_1[0] * s;
    param_0[1] = param_1[1];
    param_0[2] = param_1[2] * s - param_1[0] * c;
    param_0[0] = x;
}

void func_800EF9A8(f32 *param_0, f32 *param_1, f32 param_2) {
    f32 local_0;
    f32 local_1;
    f32 local_2;
    local_0 = func_800137AC(param_2);
    local_1 = func_800137C4();
    local_2 = param_1[0] * local_0 - param_1[1] * local_1;
    param_0[1] = param_1[0] * local_1 + param_1[1] * local_0;
    param_0[2] = param_1[2];
    param_0[0] = local_2;
}

func_800EFA20(f32 *param_0, f32 param_1[3], f32 param_2){
    param_0[0] = param_1[0]*param_2;
    param_0[1] = param_1[1]*param_2;
    param_0[2] = param_1[2]*param_2;
}

void func_800EFA4C(f32 dst[3], f32 param_1, f32 param_2, f32 param_3){
    dst[0] = param_1;
    dst[1] = param_2;
    dst[2] = param_3;
}

func_800EFA6C(param_0, param_1, param_2, param_3) s32 param_0; s16 param_1; s16 param_2; s16 param_3; {
    s16 *local_0 = param_0;

    local_0[0] = param_1;
    local_0[1] = param_2;
    local_0[2] = param_3;
}

s32 func_800EFA88(void *param_0, s32 param_1, s32 param_2, s32 param_3){
    *(s32*)((s32)param_0 + 0) = param_1;
    *(s32*)((s32)param_0 + 4) = param_2;
    *(s32*)((s32)param_0 + 8) = param_3;
}

void func_800EFA98(f32 param_0[3], f32 param_1[3], f32 param_2)
{
  f32 mag;
  f32 denom;
  denom = ((param_1[0] * param_1[0]) + (param_1[1] * param_1[1])) + (param_1[2] * param_1[2]);
  mag = denom;
  if (mag != 0.0f)
  {
    f32 tmp;
    tmp = param_2 / sqrtf(denom);
    func_800EFA20(param_0, param_1, tmp);
  }
  else
  {
    denom = param_1[2];
    func_800EE7F8(param_0, param_1);
  }
}

func_800EFB24(f32 param_0[3], f32 param_1[3], f32 param_2[3]){
    param_0[0] = param_1[0]-param_2[0];
    param_0[1] = param_1[1]-param_2[1];
    param_0[2] = param_1[2]-param_2[2];
}

func_800EFB58(s32 *param_0, s32 *param_1, s32 *param_2){
    param_0[0] = param_1[0]-param_2[0];
    param_0[1] = param_1[1]-param_2[1];
    param_0[2] = param_1[2]-param_2[2];
}

f32 func_800EFB8C(f32 param_0[3], f32 param_1[3])
{
  f32 local_0;
  f32 local_1;
  int new_var;
  f32 local_2;
  float new_var2;
  f32 local_3;
  local_0 = param_0[0] - param_1[0];
  local_1 = param_0[2] - param_1[2];
  {
  }
  new_var2 = 0.0f;
  new_var = local_0 == new_var2;
  if ((new_var ^ 0) && (local_1 == new_var2))
  {
  }
  else
  {
    local_2 = (local_0 * local_0) + (local_1 * local_1);
    local_3 = sqrtf(local_2);
    return local_3;
  }
  return 0.0f;
}

f32 func_800EFBFC(f32 param_0[3], f32 param_1[3])
{
  f32 local_0;
  f32 local_1;
  f32 local_2;
  local_0 = mlAbsF(param_1[0] - param_0[0]);
  local_1 = mlAbsF(param_1[2] - param_0[2]);
  local_2 = (local_0 < local_1) ? local_0 : local_1;
  return local_0 + local_1 - local_2 * D_80125EA0;
}

f32 func_800EFC7C(f32 param_0[3], f32 param_1[3])
{
  f32 local_0;
  f32 local_1;
  f32 local_2;
  local_0 = param_0[0] - param_1[0];
  local_1 = param_0[2] - param_1[2];
  if ((local_0 != 0.0f) || (local_1 != 0.0f))
  {
    local_2 = (local_0 * local_0) + (local_1 * local_1);
    return local_2;
  }
  return 0;
}

void func_800EFCD8(f32 *param_0, f32 param_1, f32 param_2)
{
  f32 t0 = func_800137F4(param_1);
  f32 t1 = t0 * param_2;
  param_0[0] = t1;
  param_0[2] = func_80013788() * param_2;
}

// ml_vec3f_clear
void func_800EFD24(f32 vec[3]) {
    vec[0] = vec[1] = vec[2] = 0;
}

// ml_vec3i_clear
void func_800EFD3C(s32 vec[3]) {
    vec[0] = vec[1] = vec[2] = 0;
}

// ml_vec3s_clear
void func_800EFD4C(s16 vec[3]) {
    vec[0] = vec[1] = vec[2] = 0;
}

void func_800EFD60(f32 *param_0, f32 *param_1, f32 param_2) {
    f32 local_0;
    f32 local_1;
    f32 local_2;
    f32 local_3;
    local_0 = mlAbsF(func_800137AC(param_2));
    local_1 = mlAbsF(func_800137C4());
    local_2 = param_1[0];
    local_3 = param_1[2];
    param_0[0] = local_2 * local_0 + local_3 * local_1;
    param_0[1] = param_1[1];
    param_0[2] = local_3 * local_0 + local_2 * local_1;
}

void func_800EFDE8(f32 *param_0, f32 *param_1, f32 *param_2) {
    f32 sp1C[3];
    f32 t;
    func_800EFA20(sp1C, param_1, -1.0f);
    t = func_800EEAA4(sp1C, param_2);
    func_800EFA20(param_0, param_2, t + t);
    func_800EF3DC(param_0, sp1C);
}
