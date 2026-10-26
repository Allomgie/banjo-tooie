#include "common.h"

extern int D_80800C30_chklungophial;
extern int D_80800C78_chklungophial;
typedef struct { f32 local_0[9]; } PhialRecord1826;
typedef struct { s32 local_0; PhialRecord1826 local_1[1]; } PhialList1826;
extern f32 func_800D8FF8(void);
extern void *func_80100094(Actor *, u32);
extern void func_800E2588();
extern void func_800E2594();
extern void func_800E2A14();
extern void func_800EFA4C(f32 *, f32, f32, f32);
extern void func_800E2530(f32);
extern u32 func_800F54E4(void);
extern void func_8010D12C(u32, f32 *, f32, s32);
extern s32 func_800DC298(f32);
extern void func_800C8E54(s32, f32, f32);
extern f32 func_800DC178(f32, f32);
extern Actor *_subaddiefind_entrypoint_2(s32, s32);
extern Actor *func_80108A30(s32, f32 *, f32, s32);
extern u8 D_80800CC0_chklungophial[];
extern u8 D_80800CCC_chklungophial[];
extern f32 func_800136E4(f32);
extern u8 D_80800CDC_chklungophial[];
extern u8 D_80800D18_chklungophial[];
extern u8 D_80800D28_chklungophial[];
extern u8 D_80800D50_chklungophial[];
extern u8 D_80800D6C_chklungophial[];
extern u8 D_80800D90_chklungophial[];
extern u8 D_80800DCC_chklungophial[];
extern void func_80103DFC(Actor *, f32 *);
extern f32 func_800F1DF4(f32 *, f32 *);
extern void func_800EF1B8(f32 *, f32, f32);
extern void func_800BBCB8(f32 *, f32 *, f32, s32, void *);
extern s32 func_800BABB8(s32, f32 *, f32 *, f32, void *);
extern void func_800EEB9C(f32 *, f32, f32);
extern void func_800EF04C(f32 *, f32 *);
extern s32 _chlightfader_entrypoint_1(s32, f32, s32);
extern f32 mlAbsF(f32);
extern void func_800EF174(f32 *, f32 *, f32);
typedef struct { s32 local_0; f32 local_1[50][9]; } PhialParticles26;
void func_808003C8_chklungophial();
s32 func_808006B4_chklungophial();
s32 func_80800AEC_chklungophial(Actor *param_0, f32 *param_1, f32 param_2);

int chklungophial_entrypoint_0()
{
    return (int)&D_80800C30_chklungophial;
}

int chklungophial_entrypoint_1()
{
  return (int)&D_80800C78_chklungophial;
}

void func_80800018_chklungophial(Actor *param_0)
{
    s32 local_4;
    f32 local_0[3];
    u8 *local_1;
    f32 local_2[3];

    local_1 = func_80100094(param_0, 0);
    func_8010D12C(func_800F54E4(), local_0, param_0->unk58, 5);
    for (local_4 = 0; local_4 < 3; local_4++) {
        ((f32 *)((u8 *)param_0 + 0x28))[local_4] = (local_0[local_4] - param_0->position[local_4]) / ((f32 *)param_0->actorData)[3];
    }
    ((f32 *)param_0->actorData)[5] += 400.0f * ((f32 *)param_0->actorData)[3];
    param_0->unk50 = (func_800DC298(0.5f) ? -1.0f : 1.0f) * func_800DC178(250.0f, 350.0f);
    param_0->unk54 = (func_800DC298(0.5f) ? -1.0f : 1.0f) * func_800DC178(150.0f, 250.0f);
    func_800EE7F8((f32 *)local_1, param_0->position);
    *(f32 *)(local_1 + 0x10) = 0.15f;
    *(s32 *)(local_1 + 0xC) = func_800C8A98();
    func_800C8E84(*(s32 *)(local_1 + 0xC), D_80800CC0_chklungophial);
    func_800C8E54(*(s32 *)(local_1 + 0xC), 250.0f, 600.0f);
    func_800C8CB8(*(s32 *)(local_1 + 0xC), param_0->position);
    if (!_subaddiefind_entrypoint_2(0x423, 0)) {
        func_800EFD24(local_2);
        func_80108A30(0x423, local_2, 0.0f, 0x32);
    }
}

void func_80800204_chklungophial(Actor *param_0)
{
    u8 *local_0;
    f32 local_1;
    Actor *local_2;
    f32 local_3[3];
    local_0 = func_80100094(param_0, 0);
    if (func_800D9078(local_0 + 0x10)) _subaddieaudioquick_entrypoint_2(param_0, param_0->position, D_80800CCC_chklungophial);
    if (param_0->unk70_10 == 1) {
        local_1 = func_800D8FF8();
        local_2 = (Actor *)_subaddiefind_entrypoint_2(0x423, 0);
        param_0->rotation[1] = func_800136E4(local_1 * *(f32 *)((u8 *)param_0 + 0x50) + param_0->rotation[1]);
        param_0->rotation[0] = func_800136E4(local_1 * *(f32 *)((u8 *)param_0 + 0x54) + param_0->rotation[0]);
        *(f32 *)((u8 *)param_0 + 0x2C) -= 800.0f * local_1;
        if (func_8010B990(param_0, 0x400007) & 0x20) func_808003C8_chklungophial(param_0, 1);
        if (func_800DC298(0.6f) && local_2) {
            _subaddieskeleton_entrypoint_3(param_0->unk0, 4, local_3);
            func_80800AEC_chklungophial(local_2, local_3, 0.0f);
        }
    }
    if (!func_800BFA1C(param_0->position)) {
        func_800FFAB0(param_0);
        if (*(s32 *)(local_0 + 12)) {
            func_800C8B84(*(s32 *)(local_0 + 12));
            *(s32 *)(local_0 + 12) = 0;
        }
    }
    if (*(s32 *)(local_0 + 12)) func_800C8CB8(*(s32 *)(local_0 + 12), param_0->position);
}

int func_8080038C_chklungophial(s32 param_0, s32 param_1, s32 param_2)
{
  if (param_1 == 0x40)
  {
    func_808003C8_chklungophial(param_0, 0);
  }
  else
  {
    return 0;
  }
  return 1;
}

void func_808003C8_chklungophial(param_0, param_1) Actor *param_0; s32 param_1;
{
    Vec3f local_0;
    Vec3f local_1;
    Actor *local_2;
    s32 *local_3;
    Vec3f local_4;
    s32 local_9;
    s32 local_5;
    f32 local_6;
    f32 local_7;
    Vec3f local_8;
    f32 local_10;
    f32 local_11;

    local_3 = func_80100094(param_0, 0);
    func_80103DFC(param_0, local_0.f);
    func_800EE7F8(local_1.f, local_0.f);
    func_800EF1B8(local_1.f, func_800F1DF4(param_0->position, (f32 *)local_3), param_0->scale * 60.0f);
    local_1.pos.y -= param_0->scale * 40.0f;
    func_800BBCB8(local_0.f, local_1.f, param_0->scale, 10, D_80800CDC_chklungophial);
    _subaddieaudioquick_entrypoint_2(param_0, local_0.f, D_80800D18_chklungophial);
    _subaddieaudioquick_entrypoint_2(param_0, local_0.f, D_80800D50_chklungophial);
    if (param_1 == 1) {
        local_2 = _subaddiefind_entrypoint_2(0x423, 0);
        if (func_808006B4_chklungophial(param_0, local_0.f, local_4.f)) {
            local_9 = func_800BABB8(0, local_0.f, NULL, param_0->scale * 0.25f, D_80800D6C_chklungophial);
            func_800BA77C(local_9, (s16)local_4.pos.x, (s16)local_4.pos.y, (s16)local_4.pos.z);
            func_800BA22C(local_9, 1);
        }
        func_800BABB8(0, local_0.f, NULL, param_0->scale, D_80800D90_chklungophial);
        _subaddieaudioquick_entrypoint_2(param_0, local_0.f, D_80800DCC_chklungophial);
        if (local_2 != NULL) {
            local_6 = 0.35f;
            for (local_5 = 0; local_5 < 6; local_5++) {
                local_7 = func_800DC178(0.0f, 359.0f);
                local_10 = func_800DC178(5.0f, 80.0f);
                func_800EEB9C(local_8.f, local_7, local_10);
                func_800EF04C(local_8.f, local_0.f);
                func_80800AEC_chklungophial(local_2, local_8.f, local_6);
                local_11 = func_800DC178(0.1f, 0.2f);
                local_6 += local_11;
            }
        }
    } else {
        func_800BBCB8(local_0.f, local_0.f, 1.0f, 2, D_80800D28_chklungophial);
    }
    if (local_3[3] != 0) {
        local_3[3] = _chlightfader_entrypoint_1(local_3[3], 1.5f, 2);
    }
    func_800FFAB0(param_0);
    func_8010A570(param_0);
}

s32 func_808006B4_chklungophial(param_0, param_1, param_2) Actor *param_0; f32 *param_1; f32 *param_2;
{
    f32 local_0[3];
    f32 local_1[3];
    f32 local_2[3];
    f32 local_5;
    f32 *local_3;
    local_3 = param_0->position;
    func_800EE7F8(local_0, local_3);
    local_5 = func_800D8FF8() * -6.0f;
    func_800EF174(local_0, ((f32 *)((u8 *)param_0 + 0x28)), local_5);
    func_800EE7F8(local_1, local_3);
    local_5 = func_800D8FF8() * 3.0f;
    func_800EF174(local_1, ((f32 *)((u8 *)param_0 + 0x28)), local_5);
    if (func_800C6A7C(local_0, local_1, local_2, *(s32 *)((u8 *)param_0 + 0x14))) {
        if (func_800F1988(local_2, param_2, param_2 + 1)) {
            param_2[2] = 0.0f;
            func_800EE7F8(param_1, local_1);
            return 1;
        }
        if (mlAbsF(local_2[0]) < 0.0001f && mlAbsF(local_2[2]) < 0.0001f &&
            mlAbsF(local_2[1]) > 0.9999f) {
            func_800EFD24(param_2);
            func_800EE7F8(param_1, local_1);
            return 1;
        }
    }
    return 0;
}

void func_80800820_chklungophial(s32 arg0) 
{
}
void func_80800828_chklungophial(Actor *param_0)
{
    s32 sv_state;
    f32 local_0 = func_800D8FF8();
    PhialList1826 *local_1 = (PhialList1826 *)func_80100094(param_0, 0);
    PhialRecord1826 *local_2 = local_1->local_1;
    s32 local_3 = 0;

    while (local_3 < local_1->local_0) {
        if (func_800D90A4(&local_2->local_0[5])) {
            if (func_800D90A4(&local_2->local_0[3])) local_2->local_0[4] += local_0 * 15.0f;
            if (local_2->local_0[4] > 11.0f) {
                rare_memcpy(local_2, &local_1->local_1[local_1->local_0 - 1], 0x24);
                (local_1->local_0)--;
                continue;
            }
            local_2->local_0[1] += local_0 * local_2->local_0[7];
        }
        local_2++;
        local_3++;
    }
    if (param_0->unk70_10 == 2) {
        sv_state = local_1->local_0;
        switch (sv_state) {
        case 0:
            func_800FFAB0(param_0);
            break;
        }
    }
}

s32 func_80800980_chklungophial(Actor *this, s32 param_1, s32 param_2)
{
  Actor *new_var;
  if (param_1 == 0x4f)
  {
    new_var = this;
    func_80101FDC(new_var, 2);
  }
  else
  {
    return 0;
  }
  return 1;
}

void func_808009BC_chklungophial(Actor *param_0, s32 param_1)
{
    s32 *local_0;
    s32 local_2;
    u8 *local_3;
    s32 local_4;
    f32 local_1[3];
    s32 local_5;

    local_0 = func_80100094(param_0, 0);
    local_3 = (u8 *)local_0 + 4;
    param_0->unk7C_12 = 1;
    if (*local_0) {
        local_4 = func_800D674C(0x9CF);
        func_800E2588(1);
        func_800E2594(param_1, local_4);
        func_800E24D8(1);
        for (local_2 = 0; local_2 < *local_0; local_2++, local_3 += 0x24) {
            if (*(f32 *)(local_3 + 0x14) == 0.0f) {
                func_800EFA4C(local_1, *(f32 *)(local_3 + 0x18),
                    *(f32 *)(local_3 + 0x18), *(f32 *)(local_3 + 0x18));
                func_800E2530(*(f32 *)(local_3 + 0x20));
                func_800E2720(param_1, (s32)*(f32 *)(local_3 + 0x10), 0, local_3, local_1, 255);
            }
        }
        func_800E2A14(param_1);
    }
}

s32 func_80800AEC_chklungophial(Actor *param_0, f32 *param_1, f32 param_2)
{
    f32 *local_0;
    PhialParticles26 *local_1;

    local_1 = func_80100094(param_0, 0);
    if (local_1->local_0 == 50) {
        return 0;
    }
    local_0 = local_1->local_1[local_1->local_0];
    bzero(local_0, 0x24);
    func_800EE7F8(local_0, param_1);
    local_0[3] = func_800DC178(0.55f, 1.25f);
    local_0[4] = 0.0f;
    local_0[5] = param_2;
    local_0[6] = func_800DC178(0.85f, 1.15f);
    local_0[7] = func_800DC178(40.0f, 80.0f);
    local_0[8] = func_800DC178(0.0f, 359.0f);
    local_1->local_0++;
    return 1;
}
