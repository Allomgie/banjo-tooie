#include "common.h"

typedef struct ExpressionPositionOffsets { s16 local_0; s16 local_1; } ExpressionPositionOffsets;
extern Actor *func_80106790(Unk80132ED0 *);
typedef struct { s16 local_0; s16 local_1; s16 local_2; s16 local_3; s16 local_4; s16 local_5; s16 local_6; s16 local_7; u8 local_8; u8 local_9; u8 local_10; u8 local_11; } ExpressionState1536;
extern void _suexpressmorph_entrypoint_5();
extern void _suexpressjoint_entrypoint_2();
typedef struct { u8 pad_0[0x95]; u8 pad_1 : 4; u8 slot : 2; u8 pad_2 : 2; } ActorExpressionSlot;
extern void *func_80100074(Actor *, u32, s32);
extern s32 func_8010D23C();
typedef struct { s16 o0; s16 o2; } SXH;
extern f32 func_800EEB40(f32 *, f32 *);
extern u8 unkA[];
extern u8 unk6[];
extern u8 local[];
extern int func_80100094();
extern u8 D_80800D60_suexpression[][6];
extern f32 func_80013728(f32);
extern f32 func_800F0E7C(f32, f32);
extern f32 func_800F1828(s32 *, s32);
extern void func_800F1E6C(s32 *, s32, f32 *);
typedef struct { s16 local_0; s16 pad_0; s16 local_1, local_2, local_3, local_4; u8 pad_1; u8 local_5; u8 pad_2[2]; u8 local_6, local_7; } Expression1864;
extern void *func_8010262C(Unk80132ED0 *, s32);
extern void func_800E0AFC(void *, s32, f32, f32, f32, f32);
u8 *func_80800CF4_suexpression();
void suexpression_entrypoint_15();
void suexpression_entrypoint_16();
void *D_exp_suexpression_entrypoint_15[] = { (void *)suexpression_entrypoint_15 };

f32 suexpression_entrypoint_0(param_0) u8 param_0;
{
  s16 *local_0;
  f32 local_1;
  local_0 = func_80800CF4_suexpression(param_0, param_0);
  if (local_0 == 0)
  {
    return 0.0f;
  }
  ;
  return (f32) (*local_0);
}

int suexpression_entrypoint_1(param_0) u8 param_0;
{
  u8 *local_0;
  local_0 = func_80800CF4_suexpression(param_0 | param_0);
  if (!local_0)
    return 0;
  return local_0[4];
}

void suexpression_entrypoint_2(u8 param_0, Unk80132ED0 *param_1, f32 *param_2)
{
    Actor *local_1;
    ExpressionPositionOffsets *local_0;

    local_0 = func_80800CF4_suexpression(param_0);
    local_1 = func_80106790(param_1);
    if (local_0 == NULL) {
        func_80103DFC(local_1, param_2);
    } else if (local_0->local_1) {
        if (local_1->unk7C_12) {
            func_800DBEFC(param_1->unk4, local_0->local_1, param_2);
        } else {
            param_2[0] = local_1->position[0];
            param_2[1] = local_1->position[1] + local_0->local_0 * local_1->scale;
            param_2[2] = local_1->position[2];
        }
    } else {
        param_2[0] = local_1->position[0];
        param_2[1] = local_1->position[1] + local_0->local_0 * local_1->scale;
        param_2[2] = local_1->position[2];
    }
}

void suexpression_entrypoint_3(s16 param_0, s32 *param_1, s32 *param_2, s32 *param_3)
{
    *param_3 = 0x14;
    *param_1 = _suexpressmorph_entrypoint_0(param_0);
    *param_2 = _suexpressjoint_entrypoint_0(param_0);
    *param_3 = (*param_3 + 3) & 0x7FFFFFFC;
    *param_1 = (*param_1 + 3) & 0x7FFFFFFC;
    *param_2 = (*param_2 + 3) & 0x7FFFFFFC;
}

void suexpression_entrypoint_4(s16 *param_0, s16 param_1) {
    s16 temp_v0;
    s16 temp_v0_2;

    temp_v0 = (*(s16 *)((s8 *)param_0 + 2));
    if (temp_v0 != 0) {
        _suexpressmorph_entrypoint_3((s16 *)((s8 *)param_0 + temp_v0), param_1, param_0);
    }
    temp_v0_2 = (*(s16 *)((s8 *)param_0 + 0));
    if (temp_v0_2 != 0) {
        _suexpressjoint_entrypoint_1((s16 *)((s8 *)param_0 + temp_v0_2), param_1, param_0);
    }
}

void suexpression_entrypoint_5(Actor *this)
{
    s16 offset;

    offset = *(s16*)((char*)this + 0x2);
    if (offset != 0) {
        _suexpressmorph_entrypoint_4((Actor*)((char*)this + offset));
    }
}

void suexpression_entrypoint_6(ExpressionState1536 *param_0, s16 param_1,
    s32 param_2, s32 param_3, s32 param_4)
{
    if (param_3 == 0) param_0->local_1 = 0;
    else param_0->local_1 = param_2;
    if (param_4 == 0) param_0->local_0 = 0;
    else param_0->local_0 = param_2 + param_3;
    if (param_0->local_1 != 0) {
        _suexpressmorph_entrypoint_5((u8 *)param_0 + param_0->local_1, param_1);
    }
    if (param_0->local_0 != 0) {
        _suexpressjoint_entrypoint_2((u8 *)param_0 + param_0->local_0, param_1);
    }
    param_0->local_3 = 0;
    param_0->local_2 = 0;
    param_0->local_5 = 0;
    param_0->local_4 = 0;
    param_0->local_8 = 75;
    param_0->local_9 = 75;
    param_0->local_10 = 1;
    param_0->local_7 = 0;
    param_0->local_11 = 0;
    param_0->local_6 = param_1;
}

void *suexpression_entrypoint_7(Actor *param_0, u32 param_1, s16 param_2)
{
    void *local_0;
    s32 local_1;
    s32 local_2;
    s32 local_3;
    suexpression_entrypoint_3(param_2, &local_1, &local_2, &local_3);
    local_0 = func_80100074(param_0, param_1, local_2 + local_1 + local_3);
    suexpression_entrypoint_6(local_0, param_2, local_3, local_1, local_2);
    ((ActorExpressionSlot *)param_0)->slot = param_1 + 1;
    return local_0;
}

void suexpression_entrypoint_8(u8 *param_0, s32 param_1)
{
    if (func_80100094() != 0) {
        func_80100074(param_0, param_1, 0);
    }
    param_0[0x95] = param_0[0x95] & 0xFFF3;
}

void suexpression_entrypoint_9(void *param_0)
{
    ((u8 *)param_0)[0x12] = 0;
}

void suexpression_entrypoint_10(u8 *param_0, Unk80132ED0 *param_1, f32 *param_2)
{
    f32 local_0[3];
    Actor *local_1;

    if (*(s16 *)(param_0 + 0)) _suexpressjoint_entrypoint_3(param_1, (u8 *)((s32)param_0 + ((SXH *)param_0)->o0), param_0[0x12]);
    if (*(s16 *)(param_0 + 2)) _suexpressmorph_entrypoint_1((u8 *)((s32)param_0 + ((SXH *)param_0)->o2));
    if (*(s16 *)(param_0 + 4) || *(s16 *)(param_0 + 6) ||
        *(s16 *)(param_0 + 8) || *(s16 *)(param_0 + 10)) {
        if (param_2) suexpression_entrypoint_15(param_0, param_1, param_2);
        else if (func_8010D23C() && param_0[0x13] == 0) {
            local_1 = func_80106790(param_1);
            func_8008FE94(5, local_0);
            if (*(s16 *)(param_0 + 0xE) == 0 ||
                func_800EEB40(local_1->position, local_0) <
                (f32)(*(s16 *)(param_0 + 0xE) * *(s16 *)(param_0 + 0xE))) {
                suexpression_entrypoint_15(param_0, param_1, local_0);
            } else suexpression_entrypoint_16(param_0, param_1);
        } else suexpression_entrypoint_16(param_0, param_1);
        if (param_0[0x13] == 1) param_0[0x13] = 0;
    }
    param_0[0x12] = 1;
}

s32 suexpression_entrypoint_11(Actor *this)
{
  s16 local_0;
  local_0 = *(s16 *)((char *)this + 2);
  if (local_0 != 0) {
        _suexpressmorph_entrypoint_2((Actor *)((char *)this + local_0));
    }
}

suexpression_entrypoint_12(Actor *param_0, f32 param_1, f32 param_2) {
    (*(u16 *)((char *)(param_0) + 0x6)) = (u16)(int)param_1;
    (*(u16 *)((char *)(param_0) + 0xA)) = (u16)(int)param_2;
}

int suexpression_entrypoint_13(s16 param_0[3], f32 *param_1, f32 *param_2)
{
 *param_1 = param_0[2]; *param_2 = *(s16*)((s8*)&param_0[0] + 8);
}

void suexpression_entrypoint_14(u8 *param_0, f32 param_1, f32 param_2) {
    (*(s8 *)((s8 *)(param_0) + (0x10))) = (s8) (u32) (100.0f * param_1);
    (*(s8 *)((s8 *)(param_0) + (0x11))) = (s8) (u32) (100.0f * param_2);
}

void suexpression_entrypoint_15(param_0, param_1, param_2) u8 *param_0; u8 *param_1; s32 param_2;
{
    f32 sp54;
    f32 sp50;
    f32 f22;
    f32 f20;
    s32 sp3C[3];
    f32 y;
    f32 f2;

    f22 = (f32)(*(u32 *)(param_1 + 0x28) >> 23);
    f20 = (f32)((u32)*(u16 *)(param_1 + 0x26) >> 7);
    suexpression_entrypoint_2(param_0[0xD], param_1, sp3C);
    func_800F1E6C(sp3C, param_2, &sp54);
    f22 = func_80013728(f22);
    sp54 = func_800F0E7C(sp54, f22);
    f2 = (f32)*(s16 *)(param_0 + 6);
    if (sp54 < f2 + f22 && f22 - f2 < sp54 && *(s16 *)(param_0 + 6) != 0) {
        f2 = (f32)*(s16 *)(param_0 + 4);
        if (f2 + f22 < sp54 && *(s16 *)(param_0 + 4) < *(s16 *)(param_0 + 6)) {
            y = (sp54 - (f2 + f22)) * 0.1f;
            *(s16 *)(param_0 + 4) = (s32)(f2 + y);
            f2 = (f32)*(s16 *)(param_0 + 4);
        }
        if (sp54 < f2 + f22 && -*(s16 *)(param_0 + 6) < *(s16 *)(param_0 + 4)) {
            *(s16 *)(param_0 + 4) = (s32)(f2 - ((f2 + f22) - sp54) * 0.1f);
        }
        sp50 = func_800F1828(sp3C, param_2);
        f20 = func_80013728(f20);
        y = func_800F0E7C(sp50, f20);
        f2 = (f32)*(s16 *)(param_0 + 0xA);
        if (y < f2 + f20 && f20 - f2 < y && *(s16 *)(param_0 + 0xA) != 0) {
            f2 = (f32)*(s16 *)(param_0 + 8);
            if (f2 + f20 < y && *(s16 *)(param_0 + 8) < *(s16 *)(param_0 + 0xA)) {
                sp50 = (y - (f2 + f20)) * 0.1f;
                *(s16 *)(param_0 + 8) = (s32)(f2 + sp50);
                f2 = (f32)*(s16 *)(param_0 + 8);
            }
            if (y < f2 + f20 && -*(s16 *)(param_0 + 0xA) < *(s16 *)(param_0 + 8)) {
                *(s16 *)(param_0 + 8) = (s32)(f2 - ((f2 + f20) - y) * 0.1f);
            }
        }
        if ((f32)*(s16 *)(param_0 + 0xA) * 1.5f + f20 <= y || y <= f20 - (f32)*(s16 *)(param_0 + 0xA) * 1.5f) {
            *(s16 *)(param_0 + 8) = (s32)((f32)*(s16 *)(param_0 + 8) * 0.97f);
        }
    }
    if ((f32)*(s16 *)(param_0 + 6) * 1.5f + f22 <= sp54 || sp54 <= f22 - (f32)*(s16 *)(param_0 + 6) * 1.5f) {
        *(s16 *)(param_0 + 4) = (s32)((f32)*(s16 *)(param_0 + 4) * 0.97f);
        *(s16 *)(param_0 + 8) = (s32)((f32)*(s16 *)(param_0 + 8) * 0.97f);
    }
}

void suexpression_entrypoint_16(param_0, param_1) u8 *param_0; s32 param_1; {
    (*(s16 *)((s8 *)(param_0) + (4))) = (s16) (s32) ((f32) (*(s16 *)((s8 *)(param_0) + (4))) * 0.97f);
    (*(s16 *)((s8 *)(param_0) + (8))) = (s16) (s32) ((f32) (*(s16 *)((s8 *)(param_0) + (8))) * 0.97f);
}

int suexpression_entrypoint_17(Actor *param_0, unsigned int param_1)
{
  *((s16 *) (((char *) param_0) + 0xE)) = param_1;
}

void suexpression_entrypoint_18(u8 *param_0, unsigned int param_1)
{
  param_0[0x13] = param_1;
}

void suexpression_entrypoint_19(Expression1864 *param_0, Actor *param_1)
{
    void *local_0;
    local_0 = func_8010262C(param_1->unk0, suexpression_entrypoint_1(param_0->local_5));
    if (local_0) {
        if (param_0->local_0) _suexpressjoint_entrypoint_4((u8 *)param_0 + param_0->local_0, param_1);
        if (param_0->local_1 || param_0->local_2 || param_0->local_3 || param_0->local_4) {
            func_800E0AFC(local_0, 0x12, 1.0f, (-param_0->local_3 * param_0->local_7) * 0.01f, (param_0->local_1 * param_0->local_6) * 0.01f, 0.0f);
            func_800E0AFC(local_0, 1, 1.0f, (-param_0->local_3 * (100 - param_0->local_7)) * 0.01f, (param_0->local_1 * (100 - param_0->local_6)) * 0.01f, 0.0f);
        }
    }
}

int suexpression_entrypoint_20(int param_0)
{
  unsigned int local_0;
  int local_1;
 do { local_1 = *((int *) (param_0 + 0x94)); local_0 = local_1; local_1 = (local_0 << 12) >> 30; if (local_1 != 0) { return func_80100094((void *) param_0, local_1 - 1); } return 0; } while (0);
}

u8 *func_80800CF4_suexpression(param_0) s32 param_0;
{
  u32 temp_v1;
  temp_v1 = param_0 - 0xC;
  if (temp_v1 >= 0xC6U)
  {
    return 0;
  }
  return D_80800D60_suexpression[temp_v1];
}
