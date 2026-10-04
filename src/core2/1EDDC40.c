#include "common.h"

extern s32 D_80136E80;
extern s32 D_80136EB0;
extern u8 D_80136E88[];
extern s32 D_80136EAC;
extern s32 D_80136E8B;
typedef struct { u8 local_0[3]; u8 local_1; s16 local_2[3][3]; u16 local_3; u8 local_4[3][4]; s32 local_5; u8 local_6; } local_type;
extern local_type *freelist_next(void *, s32 *);
extern void func_800EFD4C();
extern f32 func_800F0E00(f32, f32);
typedef struct { u8 pad[0x70]; u32 pad0:29; u32 local_0:1; u32 pad1:2; u32 pad2:26; u32 local_1:1; u32 pad3:5; u32 pad4:30; u32 local_2:1; u32 pad5:1; } Flags104780;
extern void func_800AAD28(f32 *);
extern void func_800EE940();
typedef struct { u8 pad_0[4]; s16 field_4[3][3]; u8 pad_16[2]; u8 field_18[3][4]; u32 field_24; } LocalRecord;
extern void func_800EFA88(s32 *, s32, s32, s32);
extern void func_800EE830(s32 *, s32 *);
extern void func_800EE7F8(f32 *, f32 *);
extern void func_800EE88C();
extern s32 func_800F36D4(s32 *, s32 *);
extern void func_800EFB24(f32 *, f32 *, f32 *);
extern void func_800EE97C(f32 *, f32 *, f32 *);
extern f32 func_800EEAA4(f32 *, f32 *);
extern f32 func_800EEF94(f32 *);
extern u8 *func_800BEF00(f32 *, f32 *, f32 *, s32);
extern s32 func_800F1B78(f32 *, f32 *, f32, f32);
extern void func_800EF1B8(f32 *, f32, f32);
extern void func_800C696C(s32, f32, f32, s32, s32);
extern void func_800EFA4C(s32, float, float, float);
typedef struct { s32 pad; f32 local_0[3]; u8 pad2[0x60]; u32 pad3:31; u32 local_1:1; } Actor105230;
extern f32 D_80124420[];
extern f32 D_8012442C[];
extern s32 func_800D3948(void);
extern void func_8010D640(f32 *);
extern f32 func_800EEB40(f32 *, f32 *);
extern s32 func_80101E14(Actor105230 *, f32);
extern s32 _fxstep_entrypoint_15(s32, s32, s32 *, s32 *, f32 *);
extern void func_800C4B64(f32);
extern void func_800C4B70(s32);
extern void func_800C4B7C(s32);
extern void func_8010D930(s32, s32, f32 *, f32 *);
void func_8010486C();
void func_801048E4();
void func_80104958();
void func_801049B4();
void func_80104D80();
int func_80104E24();
int func_80105390(s32 param_0[3], s32 param_1[3]);
int func_801053D4();

void func_80104350()
{
  D_80136E80 = freelist_new(0x2C, 8);
}

s32 func_80104378(void){
    freelist_free(D_80136E80);
    D_80136E80 = 0;
}

void func_801043A0()
{
  if (D_80136E80 != 0)
  {
    D_80136E80 = freelist_defrag(D_80136E80);
  }
}

s32 func_801043D8(param_0) u8 * param_0;
{
    s16 local_0;

    local_0 = *(s16 *)(param_0 + 0x8E);
    if (local_0 == 0) {
        return 0;
    }
    return freelist_at(((int) D_80136E80), local_0);
}

int func_80104410(param_0) Actor * param_0;
{
  s16 local_0 = *(s16 *)((char *)param_0 + 0x8E);
  if (local_0 == 0)
  {
    *(u8 *)&D_80136E8B = 0;
    D_80136EAC = 0;
    *(u8 *)&D_80136EB0 = 0;
    return (int)&D_80136E88;
  }
  return freelist_at(((u8 *) D_80136E80), local_0);
}

void func_80104460(u8 *param_0) {
    s32 local_0 = 0;
    local_type *local_1;
    s32 local_2;
    s32 local_3;

    local_1 = freelist_next(((u8 *) &D_80136E80), &local_0);
    *(u16 *)(param_0 + 0x8E) = local_0;
    local_1->local_1 = 0;
    local_1->local_5 = 0;
    local_1->local_6 = 0;
    for (local_2 = 0; local_2 < 3; local_2++) {
        func_800EFD4C(local_1->local_2[local_2]);
        for (local_3 = 0; local_3 < 4; local_3++) {
            local_1->local_4[local_2][local_3] = 0xFF;
        }
    }
}

void func_80104504(u8 *param_0) {
    s16 local_0;

    local_0 = (*(s16 *)((s8 *)(param_0) + (0x8E)));
    if (local_0 != 0) {
        freelist_erase(D_80136E80, local_0, param_0);
        (*(s16 *)((s8 *)(param_0) + (0x8E))) = 0;
    }
}

int func_80104544()
{
  s32 tmp;
  tmp = func_801043D8();
  return tmp && ((u8 *)tmp)[3] != 0;
}

void func_80104580()
{
  s32 local_0;
  local_0 = func_801043D8();
  if (local_0 != 0)
  {
    *(u8 *)(local_0 + 3) = 0;
  }
}

void func_801045AC(s32 param_0, s32 param_1, u8 *param_2, s32 param_3) {
  s32 _pad;

    f32 local_0[3];
    f32 local_1[3];
    u8 *local_2;

    local_2 = func_80104410();
    func_80104958(local_2);
    func_800AAAE0(local_2 + 0x18);
    func_8010486C(local_2, param_1);
    (*(s16 *)((s8 *)(local_2) + (0x16))) = (s16) (s32) (*(f32 *)((s8 *)(param_2) + (4)));
    (*(s8 *)((s8 *)(local_2) + (3))) = 1;
    (*(s32 *)((s8 *)(local_2) + (0x24))) = param_3;
    if ((*(u8 *)((s8 *)(local_2) + (0x28))) == 0) {
        func_801049B4(local_2, param_2, local_0);
        func_80104D80(local_0, 0x28);
        func_80104E24(local_0, local_1);
        _subaddiefade_entrypoint_11(param_0, local_1);
        (*(u8 *)((s8 *)(local_2) + (0x28))) = 1U;
    }
}

s32 func_80104668(s32 param_0, u8 *param_1, u8 *param_2, u8 *param_3, f32 *param_4) {
    u8 *sp24;
    f32 sp18[3];

    if (func_80104544() == 0) {
        return 0;
    }
    sp24 = func_801043D8(param_0);
    if ((*(s32 *)((s8 *)(sp24) + (0x24))) & 0x8000) {
        return 0;
    }
    func_800EE7F8(param_2, param_1);
    (*(f32 *)((s8 *)(param_2) + (4))) = (f32) (*(s16 *)((s8 *)(sp24) + (0x16)));
    *param_4 = func_800F0E00(0.0f, (*(f32 *)((s8 *)(param_1) + (4))) - (*(f32 *)((s8 *)(param_2) + (4))));
    func_801048E4(sp24, sp18);
    func_800F1988(sp18, param_3, param_3 + 4);
    (*(f32 *)((s8 *)(param_3) + (8))) = 0.0f;
    return 1;
}

f32 func_8010473C(s32 param_0, s32 param_1)
{
    s16 *local_1;

    local_1 = func_801043D8(param_0);
    if (param_1 != 0)
    {
        func_801048E4(local_1, param_1);
    }
    return (f32) local_1[0x16 / sizeof(s16)];
}

void func_80104780(u8 *param_0) {
    u8 *local_0;
    s32 local_1[3];
    s32 local_2[3];
    s32 local_3;
    local_0 = func_801043D8();
    if (((Flags104780 *)param_0)->local_2 && !((Flags104780 *)param_0)->local_1 && local_0[3]) {
        func_801049B4(local_0, (f32 *)(param_0 + 4), local_1);
        func_80104D80(local_1, 40);
        func_80104E24(local_1, local_2);
        if (((Flags104780 *)param_0)->local_0 && !(*(u32 *)(local_0 + 0x24) & 0x04200000)) {
            func_80105390(local_2, local_2);
        }
        for (local_3 = 0; local_3 < 3; local_3++) {
            param_0[0x98 + local_3] = (param_0[0x98 + local_3] * 3 + local_2[local_3]) >> 2;
        }
    }
}

void func_8010486C(param_0, param_1) u8 * param_0; f32 * param_1;
{
    s32 i;
    for (i = 0; i < 3; i++)
    {
        param_0[i] = (s8)(param_1[i] * 127.0f);
    }
}

void func_801048E4(param_0, param_1) s8 * param_0; f32 * param_1;
{
    s32 local_0;
    f32 local_1 = 0.007874015f;
    for (local_0 = 0; local_0 < 3; local_0++)
    {
        param_1[local_0] = (f32)param_0[local_0] * local_1;
    }
}

void func_80104958(param_0) void * param_0; {
    f32 sp34[3][3];
    s16 *p;
    s32 i;
    func_800AAD28(&sp34[0][0]);
    p = (s16 *)((u8 *)param_0 + 4);
    for (i = 0; i < 3; i++) {
        func_800EE940(p, sp34[i]);
        p += 3;
    }
}

void func_801049B4(param_0, param_1, param_2) LocalRecord * param_0; f32 * param_1; s32 * param_2;
{
    f32 local_0[3];
    f32 local_1[3];
    f32 local_2[3];
    f32 local_3;
    s32 local_17;
    f32 local_5;
    s32 local_18;
    f32 local_7[3];
    f32 local_8[3];
    f32 local_9[3];
    s32 local_10[3][3];
    f32 local_11;
    f32 local_12[3][3];
    f32 local_13[3];
    f32 local_14[3];
    f32 local_15[3];
    f32 local_16[3];
    s32 local_19;
    if ((param_0->field_24 & 0x200000)) {
        func_800EFA88(param_2, 255, 255, 255);
        return;
    }
    func_800EE7F8(local_0, param_1);
    for (local_17 = 0; local_17 < 3; local_17++) {
        func_800EE88C(local_12[local_17], param_0->field_4[local_17]);
        for (local_18 = 0; local_18 < 3; local_18++) {
            local_10[local_17][local_18] = param_0->field_18[local_17][local_18];
        }
    }
    if (func_800F36D4(local_10[0], local_10[1]) && func_800F36D4(local_10[0], local_10[2])) {
        func_800EE830(param_2, local_10[0]);
        return;
    }
    func_800EFB24(local_1, local_0, local_12[0]);
    func_800EFB24(local_8, local_12[0], local_12[1]);
    func_800EFB24(local_14, local_12[1], local_12[0]);
    func_800EFB24(local_15, local_12[2], local_12[0]);
    func_800EFB24(local_16, local_12[2], local_12[1]);
    func_800EE97C(local_13, local_14, local_15);
    func_800EE97C(local_7, local_16, local_13);
    local_3 = func_800EEAA4(local_1, local_7);
    if (local_3 == 0.0f) local_3 = 0.1f;
    local_5 = -func_800EEAA4(local_8, local_7) / local_3;
    func_800EFA4C(local_9, local_12[0][0] + local_1[0] * local_5, 0, local_12[0][2] + local_1[2] * local_5);
    func_800EFB24(local_2, local_9, local_12[1]);
    local_5 = func_800EEF94(local_2);
    local_11 = local_5 / (func_800EEF94(local_7) + 0.01f);
    for (local_17 = 0; local_17 < 3; local_17++) param_2[local_17] = local_10[1][local_17] + (local_10[2][local_17] - local_10[1][local_17]) * local_11;
    func_800EFB24(local_2, local_9, local_12[0]);
    local_5 = func_800EEF94(local_1);
    local_11 = 1.0f - local_5 / (func_800EEF94(local_2) + 0.01f);
    for (local_17 = 0; local_17 != 3; local_17++) param_2[local_17] = param_2[local_17] + (local_10[0][local_17] - param_2[local_17]) * local_11;
    if (param_0->field_24 & 0x4000000) func_80105390(param_2, param_2);
}

void func_80104D80(param_0, param_1) s32 * param_0; s32 param_1;
{
    f32 local_0 = 1.0f - param_1 * 0.00390625f;
    s32 local_1;
    for (local_1 = 0; local_1 < 3; local_1++) {
        param_0[local_1] = param_0[local_1] * local_0 + param_1;
    }
}

int func_80104E24(param_0, param_1) s32 * param_0; s32 * param_1;
{
  s32 new_var;
  s32 i;
  s32 val;
  val = 0;
  for (i = val; i < 0xC; i = i - -4)
  {
    new_var = (val = *((s32 *) (((u8 *) param_0) + i)));
    if ((!i) && (!i))
    {
    }
    if (new_var < 0)
    {
      *((s32 *) (((u8 *) param_1) + i)) = 0;
    }
    else
      if (0x100 <= val)
    {
      *((s32 *) (((u8 *) param_1) + i)) = 0xFF;
    }
    else
    {
 do { } while (0);
      *((s32 *) (((u8 *) param_1) + i)) = val;
    }
  }

}

s32 func_80104E78(u8 *param_0) {
    f32 local_0[3];
    f32 local_1[3];
    f32 local_2[3];
    u8 *local_3;
    func_800EE7F8(local_0, (f32 *)(param_0 + 4));
    func_800EE7F8(local_1, (f32 *)(param_0 + 4));
    local_0[1] -= 300.0f;
    local_1[1] += 100.0f;
    local_3 = func_800BEF00(local_1, local_0, local_2, *(s32 *)(param_0 + 0x14));
    if (local_3) {
        func_801045AC(param_0, local_2, local_0, *(s32 *)(local_3 + 8));
        return 1;
    }
    _subaddiefade_entrypoint_12(param_0, 255, 255, 255);
    return 0;
}

void func_80104F2C(u8 *param_0, s32 param_1, s32 param_2) {
    f32 local_0[3];
    f32 local_1[3];
    f32 local_2[3];
    u8 *local_3;
    f32 local_4[3];
    if (param_1 || param_2) {
        func_800EE7F8(local_0, (f32 *)(param_0 + 4));
        func_800EE7F8(local_1, (f32 *)(param_0 + 4));
        local_0[1] -= 300.0f;
        local_1[1] += 100.0f;
        local_3 = func_800BEF00(local_1, local_0, local_2, *(s32 *)(param_0 + 0x14));
        if (local_3) {
            if (param_1) func_801045AC(param_0, local_2, local_0, *(s32 *)(local_3 + 8));
            if (param_2) {
                *(f32 *)(param_0 + 8) = local_0[1];
                if (func_800F1B78(local_4, local_2, *(f32 *)(param_0 + 0x48), 1.0f)) {
                    *(f32 *)(param_0 + 0x44) = local_4[0];
                    *(f32 *)(param_0 + 0x4C) = local_4[2];
                }
            }
        }
    }
}

s32 func_80105010(u8 *param_0) {
    u8 *local_6;
    f32 local_0[3];
    f32 local_1[3];
    f32 local_2[3];
    u8 *local_3;
    s32 local_4[3];
    s32 local_5[3];
    local_6 = func_80104410();
    func_800EE7F8(local_0, (f32 *)(param_0 + 4));
    func_800EE7F8(local_1, (f32 *)(param_0 + 4));
    func_800EF1B8(local_0, *(f32 *)(param_0 + 0x48), 80.0f);
    func_800EF1B8(local_1, *(f32 *)(param_0 + 0x48), -80.0f);
    local_3 = func_800BEF00(local_0, local_1, local_2, *(s32 *)(param_0 + 0x14));
    if (local_3) {
        func_80104958(local_6);
        func_800AAAE0(local_6 + 0x18);
        func_8010486C(local_6, local_2);
        *(s16 *)(local_6 + 0x16) = local_1[1];
        local_6[3] = 1;
        *(s32 *)(local_6 + 0x24) = *(s32 *)(local_3 + 8);
        func_801049B4(local_6, local_1, local_4);
        func_80104D80(local_4, 40);
        func_80104E24(local_4, local_5);
        _subaddiefade_entrypoint_11(param_0, local_5);
        local_6[0x28] = 1;
        return 1;
    }
    _subaddiefade_entrypoint_12(param_0, 255, 255, 255);
    return 0;
}

void func_80105138(s32 param_0, s32 param_1, f32 param_2, f32 param_3, s32 param_4)
{
  s32 local_0;
  if (param_1 != 0)
  {
    local_0 = param_1 | 0;
  }
  else
  {
    local_0 = param_0 + 4;
  }
  func_800C696C(local_0, param_2, param_3, *(s32 *)(param_0 + 0x14), param_4);
}

s32 func_8010518C(param_0) ALLink * param_0; {
    if (!func_80104544(param_0)) {
        return 0;
    }
    return *(s32 *)((char *)func_801043D8(param_0) + 0x24);
}

int func_801051C8(s32 param_0, s32 param_1) {
    if (!func_80104544()) {
        func_800EFA4C(param_1, 0.0f, 1.0f, 0.0f);
        return 0;
    }
    func_801048E4(func_801043D8(param_0), param_1);
    return 1;
}

s32 func_80105230(Actor105230 *param_0, f32 *param_1) {
    s32 local_0;
    f32 local_1[3];
    s32 local_2;
    s32 local_3, local_4;
    f32 local_5;
    f32 *local_6;
    f32 *local_7[1];
    local_2 = 0;
    if (func_800D3948()) return 0;
    func_8010D640(local_1);
    local_7[0] = param_0->local_0;
    if (2.25e+06f <= func_800EEB40(local_1, local_7[0])) return 0;
    local_6 = param_1 ? param_1 : D_80124420;
    for (; *local_6 != -1.0f; local_6++, local_2++) {
        if (func_80101E14(param_0, *local_6)) {
            if (_fxstep_entrypoint_15(func_801053D4(param_0), local_2 & 1, &local_3, &local_4, &local_5)) {
                func_800C4B64(local_5);
                func_800C4B70(local_4);
                func_800C4B7C(local_3);
                func_8010D930(2, param_0->local_1, local_7[0], D_8012442C);
            }
            return 1;
        }
    }
    return 0;
}

int func_80105390(s32 param_0[3], s32 param_1[3])
{
  f32 local_0;
  local_0 = ((param_1[0] + param_1[1]) + param_1[2]) / 3.0f;
  param_0[2] = (param_0[1] = (param_0[0] = ((param_1[0] + param_1[1]) + param_1[2]) / 3.0f));
}

int func_801053D4()
{
  s32 local_0;
  s32 local_1;
  local_0 = func_8010518C();
  local_1 = func_800C84B0(local_0 | 0);
  if (local_1 == 0)
  {
    local_1 = 1;
  }
  return local_1;
}
