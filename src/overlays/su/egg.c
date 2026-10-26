#include "common.h"

extern char D_80800E40_suegg;
typedef struct EggSpriteClock { f32 local_0; f32 local_1; s32 local_2; } EggSpriteClock;
typedef struct EggSpriteFlags { u8 pad_0[0xA]; u8 local_0 : 5; u8 pad_1 : 3; } EggSpriteFlags;
extern void *func_80100094(Actor *, u32);
extern f32 func_800D8FF8(void);
extern f32 func_800F13C4(f32, f32);
typedef struct { u8 pad_0[0x38]; u32 pad_1:10; u32 local_0:1; u32 pad_2:21; void *local_1; } EggLightState;
extern void * _chlightfader_entrypoint_1(void *, f32, s32);
typedef struct { u8 pad_0[0x38]; u32 pad_1 : 8; u32 local_1 : 1; u32 local_0 : 1; u32 pad_2 : 22; } CodexEggFlags;
extern u8 D_80800E54_suegg[];
extern void _fxegg_entrypoint_0(s32, f32 *, f32);
typedef struct { u8 pad[0x2A]; u8 pad2A:5; u8 flag:1; u8 rest:2; } EggSub;
extern f32 func_800EEB40(f32 *, f32 *);
extern int func_800F0734(f32 *, f32 *, f32 *, f32, f32, f32 *, f32 *);
extern void func_800CB840();
extern void func_800F7BC8();
extern Actor *func_80106790();
extern Unk80132ED0 *func_800CD820(Unk80132ED0 *, f32 *, f32 *, f32);
typedef struct { u8 pad_0[0x38]; u32 pad_1 : 8; u32 local_0 : 1; u32 pad_2 : 23; } EggHitFlags1081;
extern u8 unk39[];
typedef struct { u8 pad_0[0x30]; f32 local_0; u8 pad_1[6]; s16 local_1; } EggTimeState;
extern void *func_800A940C(s32);
extern f32 func_800C5190(void *);
typedef struct { u8 pad_0[0x14]; u8 homing[0x1C]; f32 timer; u8 pad_1[4]; u8 mode; } EggHomingState;
extern void _sumissilehome_entrypoint_5(Actor *, void *, f32, f32);
typedef struct { u8 pad_0[0x38]; u16 pad_1 : 8; u16 local_0 : 1; u16 local_1 : 1; u16 local_2 : 1; u16 pad_2 : 5; } EggEventFlags;
typedef struct { u8 pad_0[0x3C]; void *local_0; f32 local_1[3]; } EggSoundPosition61;
extern int func_800E3E8C(f32 *, f32);
extern s32 D_80800E64_suegg[];
extern void func_8010D254(f32 *);
extern void func_800EFB24(f32 *, f32 *, f32 *);
s32 suegg_entrypoint_18();
void suegg_entrypoint_22();
s32 func_80800DC0_suegg();

void *suegg_entrypoint_0()
{
  return &D_80800E40_suegg;
}

void func_8080000C_suegg(s32 *param_0) {
    u8 *sp1C;
    u8 *temp_v0;

    temp_v0 = func_80100094(param_0, 0);
    sp1C = temp_v0;
    (*(f32 *)((s8 *)(temp_v0) + (4))) = 0.0f;
    (*(s32 *)((s8 *)(sp1C) + (8))) = func_800AF5A0(func_800EC3E8(*param_0));
    (*(f32 *)((s8 *)(sp1C) + (0))) = 1.0f;
}

void func_80800064_suegg(Actor *param_0)
{
    EggSpriteClock *local_0;
    f32 local_1;

    local_0 = func_80100094(param_0, 0);
    local_1 = func_800D8FF8() * local_0->local_0;
    local_1 += local_0->local_1;
    local_0->local_1 = func_800F13C4(local_1, (f32)local_0->local_2);
    ((EggSpriteFlags *)param_0->unk0->unk0)->local_0 = (s32)local_0->local_1 % local_0->local_2;
}

void suegg_entrypoint_1(s32 param_0, f32 param_1)
{
  *(f32 *)func_80100094(param_0, 0) = param_1;
}

void suegg_entrypoint_15();

void suegg_entrypoint_2(Actor *param_0)
{
    EggLightState *local_0;
    local_0 = func_80100094(param_0, 0);
    if (local_0->local_1) {
        if (local_0->local_0) {
            func_800C8B84(local_0->local_1);
        } else {
            func_800C8CB8(local_0->local_1, param_0->position);
            local_0->local_1 = _chlightfader_entrypoint_1(local_0->local_1, 1.0f, 2);
        }
        local_0->local_1 = NULL;
    }
    suegg_entrypoint_15((s32)param_0);
}

void suegg_entrypoint_4();

void suegg_entrypoint_3(s32 arg0)
{
    suegg_entrypoint_4(arg0,1);
}

void suegg_entrypoint_4(Actor *param_0, s32 param_1)
{
    CodexEggFlags *local_0;

    local_0 = func_80100094(param_0, 0);
    if (!param_0->unk64_17) {
        if (!local_0->local_0) {
            local_0->local_1 = 0;
            func_8010D930(0, *(u32 *)((u8 *)param_0 + 0x70) & 1, param_0->position, D_80800E54_suegg);
            if (param_1) {
                _fxegg_entrypoint_0(_gcegg_entrypoint_1(param_0->unk6C_9), param_0->position, param_0->scale);
            }
        }
        func_800FFAB0(param_0);
    }
}

void suegg_entrypoint_5(Actor *param_0) {
    if (!func_80800DC0_suegg(param_0, *(s16 *)((u8 *)func_80100094(param_0, 0) + 0x3A))) {
        (*(EggSub **)param_0)->flag = 1;
    }
}

s16 suegg_entrypoint_6(u8 *param_0, s32 param_1, s32 *param_2) {
    s32 sp1C;
    u8 *sp18;
    s32 temp_v0;

    temp_v0 = func_80106790();
    sp1C = temp_v0;
    sp18 = func_80100094(temp_v0, 0);
    func_800EFB24(param_1, sp1C + 4, sp1C + 0x18);
    *param_2 = _gcegg_entrypoint_0((u32) (*(u32 *)((s8 *)(param_0) + (0x24))) >> 0x16);
    return (*(s16 *)((s8 *)(sp18) + (0x3A)));
}

s16 suegg_entrypoint_7(void) {
    return (*(s16 *)((s8 *)(func_80100094(func_80106790(), 0)) + (0x3A)));
}

s32 func_80800390_suegg(Actor *param_0)
{
    u8 *local_0;
    f32 local_8;
    f32 local_9;
    s32 local_10;
    f32 local_1[3];
    f32 local_2[3];
    f32 local_4[3];
    f32 local_5[2];
    s32 local_11;
    f32 local_3[3];
    f32 local_7;
    f32 local_6;
    s32 local_12;

    local_0 = func_80100094(param_0, 0);
    local_12 = -1;
    if (func_800EA068(0x4000)) {
        suegg_entrypoint_18(param_0, local_1);
        func_800EE7F8(local_2, param_0->position);
        local_9 = 0.0f;
        local_10 = func_800EA068(8);
        for (local_11 = 0; local_11 < func_800F5898(); local_11++) {
            if (func_800F6438(local_11) && local_11 != *(s16 *)(local_0 + 0x3A)) {
                func_800F5A00(local_11, local_3);
                local_8 = func_800EEB40(local_3, local_1);
                if (local_12 < 0 || local_8 < local_9) {
                    if (local_10) {
                        param_0 = func_800F53D0(local_11);
                        _bsfirstp_entrypoint_7(param_0, &local_7, &local_6);
                    } else {
                        func_800F551C(local_11, &local_7, local_5, &local_6);
                    }
                    if (func_800F0734(local_1, local_2, local_3, local_7, local_6, local_4, local_4)) {
                        local_12 = local_11;
                        local_9 = local_8;
                    }
                }
            }
        }
    }
    return local_12;
}

void suegg_entrypoint_8(s32 arg0)
{
    suegg_entrypoint_9(arg0,1);
}

int suegg_entrypoint_9(Actor *param_0, s32 param_1)
{
    u8 *local_0;
    Unk80132ED0 *local_1;
    Unk80132ED0 *local_2;
    f32 local_3[3];
    s32 local_4;
    Actor *local_7;
    f32 local_5;
    f32 local_6[3];

    local_0 = func_80100094(param_0, 0);
    local_2 = param_0->unk0;
    local_4 = func_80800390_suegg(param_0);
    func_800CB840(3, param_0);
    *(s16 *)((u8 *)local_2 + 0x20) = 0;
    suegg_entrypoint_18(param_0, local_3);
    func_8010A590(param_0);
    local_1 = func_800CD820(local_2, local_3, param_0->position, 38.0f);
    if (local_1 && local_4 >= 0) {
        local_7 = func_80106790(local_1);
        local_5 = func_800EEB40(local_3, local_7->position);
        func_800F5A00(local_4, local_6);
        if (func_800EEB40(local_3, local_6) < local_5) local_1 = NULL;
        else local_4 = -1;
    }
    if (local_1) {
        if (param_1) _glhittableDll_entrypoint_1(local_2, local_1);
        else ((EggHitFlags1081 *)local_0)->local_0 = 1;
    }
    if (local_4 >= 0) {
        func_800F7BC8(local_4, 0x47, local_2);
        ((EggHitFlags1081 *)local_0)->local_0 = 1;
    }
    func_800CB870();
    func_8010A570(param_0);
    return ((EggHitFlags1081 *)local_0)->local_0;
}

int suegg_entrypoint_10(s32 param_0, s32 param_1, s32 param_2)
{
  s32 *new_var;
  new_var = &param_2;
  if (_glhittableDll_entrypoint_6((*new_var) | 0) && _glhittableDll_entrypoint_9(param_2))
  {
    Actor *local_0 = func_80106790(param_0);
    local_0 = func_80100094(local_0, 0);
    if (((!param_2) && (!param_2)) && (!param_2))
    {
    }
    *((u8 *) (((char *) local_0) + 0x39)) |= 0x80;
  }
}

u8 *suegg_entrypoint_11(s32 param_0, s32 param_1, s32 param_2)
{
    u8 *local_4;
    u8 *local_2;
    u8 *local_0;

    local_4 = func_80108474(param_0, param_1, 0);
    local_2 = func_80100094(local_4, 0);
    if (1) {}
    if (1) {}
    func_8080000C_suegg(local_4);
    *(s16 *)(local_2 + 0x3A) = param_2;
    *(s32 *)(local_2 + 0x34) = 0;
    local_2[0x38] = 1;
    *(f32 *)(local_2 + 0x28) = 0.0f;
    *(f32 *)(local_2 + 0x30) = 0.0f;
    if (func_800D3E40(0xC) && !func_800DA298(0xA31)) {
        local_0 = local_2 + 0x14;
        _sumissilehome_entrypoint_0(local_4, local_0);
        _sumissilehome_entrypoint_3(local_4, local_0, *(s16 *)(local_2 + 0x3A));
        _sumissilehome_entrypoint_1(local_4, local_0, -1);
        _sumissilehome_entrypoint_2(local_4, local_0, 0x45BB8000);
        local_2[0x38] = 2;
    }
    _sueggmove_entrypoint_4(local_4);
    func_8010A570(local_4);
    if (func_800F693C(param_2)) {
        local_4[0x75] &= ~0x10;
    } else if (func_800F690C(param_2)) {
        local_4[0x75] &= ~0x10;
    }
    return local_4;
}

int suegg_entrypoint_12(Actor *param_0)
{
    u8 *local_0;
    f32 local_1[3];
    f32 local_2[3];

    local_0 = func_80100094(param_0, 0);
    if (func_800D3948()) {
        return 0;
    }
    if (*(f32 *)(local_0 + 0x30) < 0.6f) {
        return 0;
    }
    func_8010D254(local_1);
    func_800EFB24(local_2, local_1, param_0->position);
    return local_1[1] < param_0->position[1] &&
           param_0->position[1] < local_1[1] + 100.0f &&
           local_2[0] * local_2[0] + local_2[2] * local_2[2] < 4900.0f;
}

int suegg_entrypoint_13(Actor *param_0)
{
    f32 *local_0;
    local_0 = func_80100094(param_0, 0);
    return local_0[12] > 2.8f && (_sueggmove_entrypoint_3(param_0) || local_0[12] > 3.5f);
}

int suegg_entrypoint_14(Actor *param_0)
{
    EggTimeState *local_0;
    f32 local_1;
    local_0 = func_80100094(param_0, 0);
    local_1 = func_800C5190(func_800A940C(local_0->local_1));
    if (local_1 > 2.0f) local_1 = 2.0f;
    return local_0->local_0 > local_1 + local_1 || !func_800DA298(0x662);
}

void suegg_entrypoint_15(s32 arg0) 
{
}
void suegg_entrypoint_16(Actor *param_0)
{
    EggHomingState *local_0;
    local_0 = func_80100094(param_0, 0);
    if (local_0->mode != 1) {
        if (local_0->mode == 2) {
            local_0->mode = 3;
            _sumissilehome_entrypoint_5(param_0, local_0->homing, 4500.0f, 1400.0f);
        }
        _sumissilehome_entrypoint_6(param_0, local_0->homing);
    }
    _sueggmove_entrypoint_9(param_0);
    func_80800064_suegg(param_0);
    suegg_entrypoint_22(param_0);
    local_0->timer += func_800D8FF8();
}

s32 suegg_entrypoint_17(Actor *param_0, s32 param_1, s32 param_2)
{
    EggEventFlags *local_0;

    local_0 = func_80100094(param_0, 0);
    switch (param_1) {
        case 5:
            local_0->local_0 = 1;
            func_8010A570(param_0);
            return 1;
        case 0x2C:
            local_0->local_1 = 1;
            func_8010A570(param_0);
            func_800FFAB0(param_0);
            return 1;
        case 0x92:
            local_0->local_2 = 1;
            break;
        case 0x98:
            local_0->local_1 = 1;
            break;
        case 0x9F:
            func_80800DC0_suegg(param_0, param_2);
            return 1;
        default:
            return 0;
    }
    return 1;
}

s32 suegg_entrypoint_18(param_0, param_1) s32 param_0; s32 param_1; {
    s32 local_0;

    local_0 = param_0;
    func_800EFB24(param_1, param_0 + 4, param_0 + 0x18);
}

s32 suegg_entrypoint_19(s32 param_0, s32 param_1)
{
  u32 local_0 = param_1;
  u32 local_1 = param_0;
  func_800EE7F8(param_1, local_1 + 0x18);
}

s32 suegg_entrypoint_20(s32 param_0, s32 param_1)
{
  s32 local_0 = param_1;
  s32 local_1 = param_0;
  func_800EE7F8(param_1, local_1 + 0x28);
}

void suegg_entrypoint_21(s32 param_0, s32 param_1) {
    s32 *local_0;
    s32 local_1;
    s32 local_2;
    s32 local_3;

    local_0 = func_80100094(param_0, 0);
    if (func_800BF8E4() > 0) {
        local_3 = func_800C8A98();
        *(s32 *)((char *)local_0 + 0x3C) = local_3;
        local_2 = param_0 + 4;
        local_1 = local_2;
        func_800C8CB8(local_3, local_2);
        func_800C8E84(*(s32 *)((char *)local_0 + 0x3C), param_1);
        func_800C8E54(*(s32 *)((char *)local_0 + 0x3C), 0x42A00000, 0x43E10000);
        func_800EE7F8((s32 *)((char *)local_0 + 0x40), local_1);
    }
}

void suegg_entrypoint_22(param_0) Actor *param_0;
{
    EggSoundPosition61 *local_0;

    local_0 = func_80100094(param_0, 0);
    if (local_0->local_0 != NULL) {
        if (func_800E3E8C(param_0->position, 450.0f)
            || func_800E3E8C(local_0->local_1, 450.0f)) {
            func_800C8CB8(local_0->local_0, param_0->position);
            func_800EE7F8(local_0->local_1, param_0->position);
        }
    }
}

void suegg_entrypoint_23(s32 param_0)
{
  func_8010D930(8, 0, param_0 + 4, &D_80800E64_suegg);
}

s32 func_80800DC0_suegg(this, param_1) Actor *this; s32 param_1;
{
  u8 *local_0;
  if ((func_800D3948() == 0) && (func_800F6CC8(param_1) != (0 * 0)))
  {
    local_0 = func_80100094(this, 0);
    *((u8 *) (((char *) local_0) + 0x39)) = (u8) (((*((u8 *) (((char *) local_0) + 0x39))) & 0xFF) | 0x40);
    suegg_entrypoint_3(this);
    return 1;
  }
  return 0;
}
