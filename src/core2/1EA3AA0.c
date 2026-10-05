#include "core2/1EA3AA0.h"
#include <types.h>

extern void func_800EF8BC(void *, void *, f32);
extern void func_800EF934(void *, void *, f32);
extern void func_800EFA4C(f32 *, f32, f32, f32);
typedef struct { u8 pad0[0xE8]; f32 unkE8; u8 padEC[0x24]; f32 unk110; f32 unk114; f32 unk118; f32 unk11C; f32 unk120; f32 unk124; } S_CA2A8;
extern f32 func_800137F4(f32);
extern f32 func_80013788(void);
extern void func_800EF2A0(f32 *);
typedef struct { u8 pad0[0x18]; s32 unk18; s32 unk1C; } S_CA3A4;
extern void func_800EF4E4(f32 *, s32, s32, f32, f32, f32);
extern void func_800EF04C(S_CA3A4 *, f32 *);
typedef struct Actor { char pad[0xE4]; f32 unkE4; f32 unkE8; char pad2[8]; f32 unkF4; } Actor;
extern f32 func_800139F8(float);
typedef struct { char pad[0xEC]; f32 field; } unk_struct;
typedef struct { u8 pad0[0x24]; f32 planes[4][4]; } LocalPlanes;
typedef struct { u8 pad[0x24]; f32 local_0[4][4]; } StateCAB70;
f32 func_800EEAA4();
void func_800136E4(f32);
typedef struct { f32 local_0[3], local_1[3], local_2[3]; f32 local_3[4], local_4[4], local_5[4], local_6[4]; f32 local_7[4][4], local_8[4][4]; u8 pad[0x14]; f32 local_9[3], local_10[3], local_11[3], local_12[3]; f32 local_13[3], local_14[3], local_15[3], local_16[3], local_17[3]; } ViewCAF34;
extern void func_800D93A0(f32 *, f32 *);
extern void func_800D965C(f32 *, f32 (*)[4]);
extern void func_800D9624(f32 *, f32 *);
extern void mlMtxSet(f32 (*)[4]);
extern void func_80019224(f32 *, f32 *);
extern void func_80019480(f32 *, f32, f32, f32);
typedef struct { u8 pad[0xE8]; f32 aspect; f32 near; f32 far; f32 cot; } StateCB124;
extern void func_800F274C(f32 mf[4][4]);
void func_800CA440();
void func_800CA5F8(s32 param_0, f32 param_1, f32 param_2, f32 param_3);
int func_800CA688(s32 param_0[3], f32 param_1, f32 param_2, f32 param_3);
int func_800CA6C0(f32 param_0[3], f32 param_1, f32 param_2);
void func_800CA6F0(f32 *param_0, f32 param_1);
void func_800CAF34();

void func_800CA1B0(u8 *param_0)
{
  s32 local_0;
  u8 *new_var;
  new_var = param_0 + 0xF8;
 if (0) { }
  local_0 = new_var;
  func_800EFA4C(local_0, -1.0f, 0.0f, 0.0f);
  func_800EF934(local_0, local_0, (*((f32 *) (param_0 + 0xE8))) * ((*((f32 *) ((new_var = param_0) + 0xE4))) * 0.5f));
}

void func_800CA218(u8 *param_0, f32 param_1) {
    func_800EFA4C((f32 *)(param_0 + 0x104), 0.0f, 1.0f, 0.0f);
    func_800EF8BC((f32 *)(param_0 + 0x104), (f32 *)(param_0 + 0x104), param_1);
    func_800EFA4C((f32 *)(param_0 + 0xF8), -1.0f, 0.0f, 0.0f);
    func_800EF934((f32 *)(param_0 + 0xF8), (f32 *)(param_0 + 0xF8), ((f32 *)param_0)[0xE8 / 4] * param_1);
}

void func_800CA2A8(S_CA2A8 *param_0, f32 param_1) {
    f32 s;
    f32 c;
    param_0->unk110 = 0.0f;
    s = func_800137F4(param_1);
    param_0->unk120 = s;
    param_0->unk114 = -s;
    c = func_80013788();
    param_0->unk124 = -c;
    param_0->unk118 = -c;
    param_0->unk11C = param_0->unk120 * param_0->unkE8;
    func_800EF2A0(&param_0->unk11C);
}

void func_800CA314(s32 arg0,s32 arg1)
{
    aligned4_memcpy(arg0,arg1,0x168);
}

int func_800CA334()
{
  void *local_0;
  local_0 = heap_alloc(0x168);
  func_800CA440((s32)local_0 | 0);
  return (int)local_0;
}

void func_800CA364(void* arg0) 
{
    heap_free(arg0);
}
void* func_800CA384(void* arg0) 
{
    return defrag(arg0);
}
void func_800CA3A4(S_CA3A4 *param_0, f32 param_1) {
    f32 sp24[3];
    func_800EF4E4(sp24, param_0->unk18, param_0->unk1C, 0.0f, 0.0f, param_1);
    func_800EF04C(param_0, sp24);
}

int func_800CA3F4(s32 param_0, s32 param_1, f32 param_2[3])
{
  f32 local_0[3];
  func_800EFB24(local_0, param_0 | 0, param_1);
  func_800EF368(local_0, param_2);
  func_800EF04C(param_1, local_0);
}

void func_800CA440(param_0) Actor * param_0; {
    f32 local_0;
    func_800CA5F8(param_0, 0.0f, 0.0f, 0.0f);
    func_800CA688(param_0, 0.0f, 0.0f, 0.0f);
    func_800CA6C0(param_0, 1.0f, 10000.0f);
    func_800CA6F0(param_0, 1.0f);
    param_0->unkE4 = 40.0f;
    local_0 = param_0->unkE4 * 0.5f;
    param_0->unkF4 = 1.0f / func_800139F8(local_0);
    param_0->unkE8 = 1.3333334f;
    func_800CA218(param_0, local_0);
    func_800CA2A8(param_0, local_0);
    func_800CAF34(param_0);
}

int func_800CA510(f32 param_0[3], f32 param_1)
{
  *(f32*)((s8*)param_0 + 232) = param_1;
  func_800CA1B0(param_0);
  func_800CA2A8(param_0, param_0[57] * 0.5f);
}

void func_800CA558(void *param_0, f32 param_1) {
    f32 half = param_1 * 0.5f;
    *(f32 *)((u8 *)param_0 + 0xE4) = param_1;
    *(f32 *)((u8 *)param_0 + 0xF4) = 1.0f / func_800139F8(half);
    func_800CA218(param_0, half);
    func_800CA2A8(param_0, half);
}

void func_800CA5B8()
{
    func_800EE7F8();
}

void func_800CA5D8()
{
    func_800EE84C();
}

void func_800CA5F8(s32 param_0, f32 param_1, f32 param_2, f32 param_3)
{
    func_800EFA4C(param_0, param_1, param_2, param_3);
}

func_800CA628(f32 param_0[3], f32 param_1[3], f32 param_2[3]){
    s32 local_0;
    for(local_0 = 0; local_0 < 3; local_0++){
        param_0[local_0] = param_1[local_0];
        param_0[local_0+6] = param_2[local_0];
    }
}

int func_800CA668(s32 param_0)
{
  func_800EE7F8(param_0 + 0x18);
}

int func_800CA688(s32 param_0[3], f32 param_1, f32 param_2, f32 param_3) {
    func_800EFA4C(&param_0[6], param_1, param_2, param_3);
}

int func_800CA6C0(f32 param_0[3], f32 param_1, f32 param_2)
{
  f32 new_var3;
  f32 new_var2;
  unsigned char new_var;
  *(f32*)((s8*)param_0 + 236) = (new_var3 = param_1);
  param_0[60] = (new_var2 = param_2) * 1.0f;
}

int func_800CA6D4(f32 *param_0, f32 *param_1, f32 *param_2)
{
  unsigned char new_var;
  f32 *new_var3;
  int new_var2;
  new_var3 = param_2;
  new_var2 = 2;
  *param_1 = param_0[new_var2 = 59];
  new_var = new_var2;
  *new_var3 = param_0[60];
}

f32 func_800CA6E8(f32 *param_0) {
    return param_0[89];
}

void func_800CA6F0(f32 *param_0, f32 param_1)
{
  param_0[0x59] = param_1;
}

f32 func_800CA6FC(f32 *arg0)
{
    return arg0[58];
}

void func_800CA704(s32 param_0, s32 param_1, s32 param_2) {
    func_800EFB24(param_2, param_1, param_0);
    func_800EEAA4(param_0 + 0xC, param_2);
}

int func_800CA740(s32 param_0, s32 param_1)
{
  func_800EE7F8(param_1 | 0, param_0 + 0xC);
}

int func_800CA768(s32 param_0, s32 param_1)
{
  func_800EEAD4(param_1 | 0, param_0 | 0);
}

f32 func_800CA794(f32 *arg0)
{
    return arg0[57];
}

f32 func_800CA79C(f32 *arg0)
{
    return arg0[61];
}

int func_800CA7A4(s32 param_0)
{
  return param_0 + 100;
}

int func_800CA7AC(s32 param_0)
{
  long local_0;
  local_0 = param_0;
  ;
  return local_0 + 0xA4;
}

f32 func_800CA7B4(unk_struct *param_0) {
    return param_0->field;
}

int func_800CA7BC(f32 param_0[4], f32 *param_1, f32 *param_2, f32 *param_3, f32 *param_4)
{
  int new_var;
  new_var = 60;
  *param_1 = param_0[57];
  *param_2 = param_0[58];
 *param_3 = param_0[59]; *param_4 = param_0[60];
}

int func_800CA7E4(s32 param_0, s32 param_1)
{
  func_800EE7F8(param_1 | 0, param_0 | 0);
}

void func_800CA810(f32 param_0[3], s32 *param_1)
{
    param_1[0] = (s32) ((f32) (s32) (param_0[0] * 500.0f) / 500.0f);
    param_1[1] = (s32) ((f32) (s32) (param_0[1] * 500.0f) / 500.0f);
    param_1[2] = (s32) ((f32) (s32) (param_0[2] * 500.0f) / 500.0f);
}

func_800CA8B4(f32 param_0[3], f32 param_1[3], f32 param_2[3]){
    s32 local_0;
    for(local_0 = 0; local_0 < 3; local_0++){
        param_1[local_0] = param_0[local_0];
        param_2[local_0] = param_0[local_0 + 6];
    }
}

func_800CA8F4(f32 param_0[3], f32 param_1[3], f32 param_2[3]){
    s32 local_0;
    for(local_0 = 0; local_0 < 3; local_0++){
        param_1[local_0] = param_0[local_0];
        param_2[local_0] = param_0[local_0+3];
    }
}

void func_800CA934(u8 *param_0, u8 *param_1) {
    (*(s16 *)((s8 *)(param_1) + (0))) = (s16) (s32) ((f32) (s32) ((*(f32 *)((s8 *)(param_0) + (0))) * 500.0f) / 500.0f);
    (*(s16 *)((s8 *)(param_1) + (2))) = (s16) (s32) ((f32) (s32) ((*(f32 *)((s8 *)(param_0) + (4))) * 500.0f) / 500.0f);
    (*(s16 *)((s8 *)(param_1) + (4))) = (s16) (s32) ((f32) (s32) ((*(f32 *)((s8 *)(param_0) + (8))) * 500.0f) / 500.0f);
}

void func_800CA9D8(f32 * param_0, s32 * param_1)
{
  s32 local_0 = param_1;
  s32 local_1 = param_0;
  func_800EE7F8(param_1, local_1 + 0x18);

}

void func_800CAA00(f32 *param_0, f32 *param_1, f32 *param_2, f32 *param_3)
{
  int new_var;
  *param_1 = param_0[6];
  *param_2 = param_0[7];
  *param_3 = param_0[8];
}

f32 func_800CAA1C(f32 *arg0)
{
    return arg0[7];
}

s32 func_800CAA24(LocalPlanes *param_0,f32 *param_1,f32 *param_2)
{
    s32 local_0;
    f32 local_1,local_2,local_3;
    f32 *local_4;
    for (local_0=0;local_0<4;local_0++) {
        local_4=param_0->planes[local_0];
        local_1=local_4[0]; local_2=local_4[1]; local_3=local_4[2];
        local_1 *= local_1>=0.0f ? param_1[0] : param_2[0];
        local_2 *= local_2>=0.0f ? param_1[1] : param_2[1];
        local_3 *= local_3>=0.0f ? param_1[2] : param_2[2];
        if (local_4[3] + (local_1+local_2+local_3)>=0.0f) return 0;
    }
    return 1;
}

s32 func_800CAB70(StateCAB70 *param_0, s16 *param_1, s16 *param_2) {
    s32 local_0;
    f32 local_1;
    f32 local_2;
    f32 local_3;
    f32 *local_4;
    for (local_0 = 0; local_0 < 4; local_0++) {
        local_4 = param_0->local_0[local_0];
        local_1 = param_0->local_0[local_0][0];
        local_2 = param_0->local_0[local_0][1];
        local_3 = param_0->local_0[local_0][2];
        local_1 *= local_1 >= 0.0f ? param_1[0] : param_2[0];
        local_2 *= local_2 >= 0.0f ? param_1[1] : param_2[1];
        local_3 *= local_3 >= 0.0f ? param_1[2] : param_2[2];
        if (local_4[3] + (local_1 + local_2 + local_3) >= 0.0f) return 0;
    }
    return 1;
}

s32 func_800CACEC(u8 *param_0, u8 *param_1, f32 param_2)
{
    volatile f32 sp44;
    volatile f32 sp40;
    f32 sp3C;
    s32 var_s0;
    u8 *var_s1;

    var_s0 = 0;
    var_s1 = param_0 + 0x24;
    sp3C = (*(f32 *)((s8 *)param_1 + 0)) - (*(f32 *)((s8 *)param_0 + 0));
    sp40 = (*(f32 *)((s8 *)param_1 + 4)) - (*(f32 *)((s8 *)param_0 + 4));
    sp44 = (*(f32 *)((s8 *)param_1 + 8)) - (*(f32 *)((s8 *)param_0 + 8));
loop_1:
    if (param_2 <= func_800EEAA4(&sp3C, var_s1)) {
        return 0;
    }
    var_s0 += 0x10;
    var_s1 += 0x10;
    if (var_s0 == 0x40) {
        return 1;
    }
    goto loop_1;
}

int func_800CAD9C(f32 *param_0, f32 param_1, f32 param_2, f32 param_3) {
    if ((param_0[9] * param_1 + param_0[10] * param_2 + param_0[11] * param_3 + param_0[12] <= 0.0f) &&
        (param_0[13] * param_1 + param_0[14] * param_2 + param_0[15] * param_3 + param_0[16] <= 0.0f) &&
        (param_0[17] * param_1 + param_0[18] * param_2 + param_0[19] * param_3 + param_0[20] <= 0.0f) &&
        (param_0[21] * param_1 + param_0[22] * param_2 + param_0[23] * param_3 + param_0[24] <= 0.0f)) return 1;
    return 0;
}

int func_800CAEA4(f32 param_0[3], f32 param_1, f32 param_2, f32 param_3)
{
  return (((param_0[17] * param_1) + (param_0[18] * param_2)) +
          (param_0[19] * param_3) + param_0[20]) <= 0.0f;
}

f32 func_800CAF00(f32 param_0[3], f32 param_1)
{
  func_800136E4(param_0[7] + param_1 + 90.0f);
}

void func_800CAF34(param_0) ViewCAF34 * param_0; {
    f32 local_0[4];
    f32 local_1[4];
    func_800D93A0(local_0, param_0->local_2);
    func_800D965C(local_0, param_0->local_7);
    func_800D9624(local_1, local_0);
    func_800D965C(local_1, param_0->local_8);
    mlMtxSet(param_0->local_7);
    func_800EFA4C(param_0->local_1, 0.0f, 0.0f, -1.0f);
    func_80019224(param_0->local_1, param_0->local_1);
    func_80019224(param_0->local_3, param_0->local_9);
    func_80019480(param_0->local_4, -param_0->local_9[0], param_0->local_9[1], param_0->local_9[2]);
    func_80019224(param_0->local_5, param_0->local_10);
    func_80019480(param_0->local_6, param_0->local_10[0], -param_0->local_10[1], param_0->local_10[2]);
    param_0->local_3[3] = -func_800EEAA4(param_0->local_0, param_0->local_3);
    param_0->local_4[3] = -func_800EEAA4(param_0->local_0, param_0->local_4);
    param_0->local_5[3] = -func_800EEAA4(param_0->local_0, param_0->local_5);
    param_0->local_6[3] = -func_800EEAA4(param_0->local_0, param_0->local_6);
    func_80019480(param_0->local_13, -param_0->local_12[0], -param_0->local_12[1], param_0->local_12[2]);
    func_80019224(param_0->local_14, param_0->local_12);
    func_80019224(param_0->local_15, param_0->local_11);
    func_80019480(param_0->local_16, -param_0->local_12[0], param_0->local_12[1], param_0->local_12[2]);
    func_80019480(param_0->local_17, param_0->local_12[0], -param_0->local_12[1], param_0->local_12[2]);
}

void func_800CB0E8(s32 param_0, u32 param_1, s32 param_2) {
  func_800EE7F8(param_1, (void*)((char*)param_0 + 0x128 + param_2 * 0xC));
}

u16 func_800CB124(StateCB124 *param_0, f32 mf[4][4])
{
    u16 perspNorm;
    f32 tmp;
    f32 near;
    f32 far;
    s32 i;
    s32 j;
    near = param_0->near;
    far = param_0->far;
    if (near < 1.0f) near = 1.0f;
    if (far < near + 100.0f) far = near + 100.0f;
    tmp = ((2 * near) * far) / (near - far);
    if (((tmp * 0.5f) > 32767) || ((tmp * 0.5f) < (-32767)))
    {
        tmp = ((tmp * 0.5f) > 32767) ? (32767) : (-32767);
        near = ((-(tmp / 0.5f)) * far) / ((2 * far) - (tmp / 0.5f));
    }
    func_800F274C(mf);
    mf[0][0] = param_0->cot / param_0->aspect;
    mf[1][1] = param_0->cot;
    mf[2][2] = (near + far) / (near - far);
    mf[2][3] = -1;
    mf[3][2] = ((near + near) * far) / (near - far);
    mf[3][3] = 0;
    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 4; j++)
        {
            mf[i][j] *= 0.5f;
        }
    }
    if ((near + far) <= 2.0f)
    {
        perspNorm = (u16) 0xFFFF;
    }
    else
    {
        perspNorm = (u16) ((2.0f * 65536.0f) / (near + far));
        if (perspNorm <= 0)
        {
            perspNorm = (u16) 0x0001;
        }
    }
    return perspNorm;
}
