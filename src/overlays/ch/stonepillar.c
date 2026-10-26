#include "common.h"
extern void func_800EF1B8(f32 *, f32, f32);

extern int D_808013F0_chstonepillar;
extern int D_80801438_chstonepillar;
extern void *func_80100094(Actor *, u32);
typedef union { s32 local_0; Actor *local_1; } StonePillarMessage1410;
extern u8 func_801015D0[];
extern f32 func_80103EF4(Actor *);
extern Actor *_subaddiefind_entrypoint_2(s32, s32 *);
extern Actor *_subaddiefind_entrypoint_3(s32, s32 *);
extern u8 D_80801480_chstonepillar[];
typedef struct { u8 pad_0[0x2C]; s16 local_0; u8 pad_1; u8 local_1; } StonePillarState;
extern void func_800BBCB8(f32 *, f32 *, f32, s32, s32);
extern s32 D_80801498_chstonepillar;
extern f32 D_808014B8_chstonepillar;
extern f32 func_800136E4(f32);
typedef struct { u8 pad_0[0x2C]; s16 local_0; } PillarActivation;
extern void func_800CE8D8(s32, f32, s32);
extern s32 func_800DA564(s32, s32);
extern f32 func_800D8FF8(void);
extern f32 func_800DC178(f32, f32);
typedef struct { u8 pad[0x5F]; u8 f5F; u8 pad60[0x12]; u16 f72:6; u16 rest:10; } PillarS;
extern u8 D_808014F0_chstonepillar;
extern void _subaddieaudioloop_entrypoint_4(PillarS *, s32, s32, void *);
typedef struct { u8 pad[0xC]; f32 position[3]; u8 pad_18[0x18]; f32 yaw; f32 speed; f32 height; } StonePillarMotion;
extern f32 func_800EFB8C(f32 *, f32 *);
extern f32 func_80102D78(Actor *, f32 *);
extern u8 D_8080148C_chstonepillar[];
extern f32 func_800F1DF4(f32 *, f32 *);
extern void func_80018820(s32, f32, f32);
int func_808005B4_chstonepillar();
void func_808006AC_chstonepillar();
void func_80800704_chstonepillar();
void func_808007C8_chstonepillar();
void func_80800ADC_chstonepillar();
s32 func_80800B58_chstonepillar();
void func_80800BDC_chstonepillar();
void func_80800C10_chstonepillar();
void func_80800C44_chstonepillar();
void func_80800CC8_chstonepillar();
int func_80800DA4_chstonepillar();
int func_80800DD8_chstonepillar();
void func_80800E30_chstonepillar();
void func_80800EE0_chstonepillar();
void func_80800FE0_chstonepillar();
int func_808010CC_chstonepillar();
int func_8080112C_chstonepillar();
s32 func_80801174_chstonepillar();
s32 func_80801238_chstonepillar();
void func_80801374_chstonepillar();
s32 func_80800474_chstonepillar();
s32 func_80800870_chstonepillar();
void func_808011CC_chstonepillar(Actor *param_0, s32 param_1, f32 param_2, f32 param_3);

int chstonepillar_entrypoint_0()
{
  return (int)&D_808013F0_chstonepillar;
}

int chstonepillar_entrypoint_1()
{
    return (int)&D_80801438_chstonepillar;
}

void func_80800018_chstonepillar(Actor *param_0)
{
    u8 *local_0;
    s32 local_1;
    s32 local_2;

    local_0 = func_80100094(param_0, 0);
    local_1 = param_0->unk70_10;
    func_80800FE0_chstonepillar(param_0);
    if (*(s16 *)(local_0 + 0x2C) == 4 || func_800D0B68(8, 1)) {
        if (_glcutDll_entrypoint_19(0xB) && local_1 == 3) {
            func_80800ADC_chstonepillar(param_0, 0);
        }
    } else if (func_800DA298(0x9D7) || func_8080112C_chstonepillar(param_0)) {
        func_80801374_chstonepillar(param_0, 2);
        switch (param_0->unk70_10) {
            case 1:
                if (func_800DA298(0x9D7) && *(s16 *)(local_0 + 0x2C) == 0) {
                    func_80801174_chstonepillar(param_0);
                    func_80800B58_chstonepillar(param_0);
                    *(f32 *)(local_0 + 0x24) = 0.5f;
                    func_800DA524(0x9D7);
                    if (!func_800DA298(0x9D9)) {
                        local_2 = 0x810;
                        if (_glcutDll_entrypoint_19(0xB)) {
                            local_2 = 0x910;
                        }
                        _capod_entrypoint_13(param_0->unk0, 0, 0xC, local_2);
                        func_800DA544(0x9D9);
                    }
                } else if (func_80800474_chstonepillar(param_0)) {
                    func_808011CC_chstonepillar(param_0, 2, 1.0f, 1.0f);
                }
                break;
            case 2:
                if (!func_80801238_chstonepillar(param_0)) {
                    func_80101FDC(param_0, 3);
                }
                break;
            case 3:
                if (!func_80800870_chstonepillar(param_0)) {
                    func_80800ADC_chstonepillar(param_0, 1);
                }
                break;
        }
    }
}

void func_808001FC_chstonepillar(s32 arg0)
{
    _subaddiefade_entrypoint_14();
    func_80800EE0_chstonepillar(arg0);
}
void func_80800224_chstonepillar(u8 *param_0) {
    u8 *sp24;

    sp24 = func_80100094(param_0, 0);
    func_80800FE0_chstonepillar(param_0);
    func_80801374_chstonepillar(param_0, 2);
    if ((((u32) (*(u16 *)((s8 *)(param_0) + (0x72))) >> 0xA) == 2) && (func_80800C10_chstonepillar(param_0 + 4), (func_80801238_chstonepillar(param_0) == 0)) && (func_80101FDC(param_0, 1), (func_800D0B68(8, 1) == 0))) {
        if ((func_800DA298(0x9D8) == 0) && ((*(s16 *)((s8 *)(sp24) + (0x2C))) == 0)) {
            func_800DA544(0x9D8);
        }
        if (func_800DA298(0x9D8) != 0) {
            if ((func_8080112C_chstonepillar(param_0) != 0) && ((*(s16 *)((s8 *)(sp24) + (0x2C))) != 4)) {
                func_80800E30_chstonepillar(param_0);
            }
        } else {
            func_80800DA4_chstonepillar(param_0);
        }
    }
}

s32 func_8080031C_chstonepillar(Actor *param_0, s32 param_1, s32 param_2)
{
    u8 *local_0;

    switch (param_1) {
    case 0x95:
        local_0 = func_80100094(param_0, 0);
        func_80800704_chstonepillar(param_0);
        if (_glcutDll_entrypoint_19(11) && !*(s16 *)(local_0 + 0x2C)) {
            func_808006AC_chstonepillar(param_0);
        }
        break;
    default:
        return 0;
    }
    return 1;
}

int func_80800390_chstonepillar(Actor *param_0, s32 param_1, StonePillarMessage1410 param_2)
{
    switch (param_1) {
        case 0x3F:
            func_80800CC8_chstonepillar(param_0, param_2.local_0);
            break;
        case 0x95:
            func_80800C44_chstonepillar(param_0);
            break;
        default:
            return 0;
    }
    return 1;
}

void func_808003F4_chstonepillar(param_0, param_1) s32 param_0; u8 param_1;
{
  s32 local_0;
  s32 local_1;
  local_0 = 0;
  do
  {
    local_1 = (local_0 = local_0 + 1) ^ 0;
    func_800DF744(local_1, 0);
    local_0 = local_1;
  }
  while (local_1 != 5);
  func_800DF744((*((u8 *) (((char *) func_80100094(param_0, 0)) + 0x2E))) + 1, 1);
  func_80101808(param_0, &func_801015D0);
}

s32 func_80800474_chstonepillar(param_0) Actor *param_0;
{
    StonePillarMotion *local_0;
    f32 local_1;

    local_0 = func_80100094(param_0, 0);
    if (!func_8080112C_chstonepillar(param_0) || !func_800DA298(0x9D5)) {
        return 0;
    }
    local_1 = func_800EFB8C(param_0->position, local_0->position);
    local_0->yaw = func_80102D78(param_0, local_0->position);
    local_0->speed = (0.3f * local_1) / 0.5f;
    local_0->height = 822.00006f;
    return 1;
}

int func_80800520_chstonepillar(Actor *param_0)
{
  Actor *local_0;
  s32 local_4;
  s32 *local_5 = (s32 *) (((char *) param_0) + 0x5A0);
  func_80800EE0_chstonepillar();
  local_0 = func_80100094(param_0, 0);
  local_4 = func_808005B4_chstonepillar(param_0, *((s32 *) (((char *) local_0) + 0x28)), local_0) | 0;
  if ((param_0 && param_0) && param_0)
  {
  }
  local_4 = (*((s32 *) (((char *) local_0) + 0x28))) + 1;
  func_808005B4_chstonepillar(param_0, local_4, ((u8 *) local_0) + 0xC);
  *((f32 *) (((char *) param_0) + 0x8)) -= (*((s32 *) (((char *) local_0) + 0x28))) * 200.0f;
  *((f32 *) (((char *) param_0) + 0x1C)) = *((f32 *) (((char *) param_0) + 0x8));
}

int func_808005B4_chstonepillar(param_0, param_1, param_2) Actor *param_0; s32 param_1; f32 *param_2;
{
    Actor *local_2;
    u8 *local_3;
    s32 local_0;
    f32 local_1;

    local_1 = func_80103EF4(param_0);
    for (local_2 = _subaddiefind_entrypoint_2(0x12E, &local_0); local_2 != NULL; local_2 = _subaddiefind_entrypoint_3(0x12E, &local_0)) {
        local_3 = func_80100094(local_2, 0);
        if (param_1 == *(s16 *)(local_3 + 0x2C)) {
            func_800EE7F8(param_2, (f32 *)(local_3 + 0x18));
            param_2[1] += local_1 - param_1 * 200.0f;
            return;
        }
    }
    local_3 = func_80100094(param_0, 0);
    func_800EE7F8(param_2, (f32 *)(local_3 + 0x18));
    param_2[1] += local_1 - param_1 * 200.0f;
}

void func_808006AC_chstonepillar(arg0) s32 *arg0;
{
  long new_var4;
  u16 *new_var2;
  u8 *new_var3;
  short new_var;
  if (func_800DA298(0x9D5) != 0)
  {
    new_var3 = &D_80801480_chstonepillar[func_800DA564(0x9CD, 3) * 2];
    new_var4 = *arg0;
    new_var2 = (u16 *) new_var3;
    new_var = *new_var2;
    _capod_entrypoint_13(new_var4, 0, new_var, 0x810);
  }
}

void func_80800704_chstonepillar(param_0) Actor *param_0;
{
    StonePillarState *local_0;
    f32 local_1[3];

    local_0 = func_80100094(param_0, 0);
    local_0->local_1 = 0;
    func_808007C8_chstonepillar(param_0);
    func_80101FDC(param_0, 1);
    if (func_800D0B68(8, 1)) {
        local_0->local_0 = -1;
    } else if (!local_0->local_0) {
        func_808005B4_chstonepillar(param_0, func_800DA564(0x9CD, 3), local_1);
        func_800D1254(8, 1, local_1);
        if (func_800DA298(0x9D7)) {
            func_80801174_chstonepillar(param_0);
            func_800DA544(0x9D7);
        }
    }
}

void func_808007C8_chstonepillar(param_0) Actor *param_0;
{
    StonePillarState *local_1;
    StonePillarState *local_2;
    Actor *local_3;
    s32 local_0;

    local_1 = func_80100094(param_0, 0);
    local_3 = _subaddiefind_entrypoint_2(param_0->unk6C_9, &local_0);
    while (local_3) {
        if (local_3 != param_0) {
            local_2 = func_80100094(local_3, 0);
            if (local_1->local_0 + 1 == local_2->local_0) {
                func_800EE7F8((f32 *)((u8 *)local_1 + 0xC), local_2);
            }
        }
        local_3 = _subaddiefind_entrypoint_3(param_0->unk6C_9, &local_0);
    }
}

s32 func_80800870_chstonepillar(param_0) Actor *param_0;
{
    f32 local_2;
    f32 local_0;
    f32 local_1[3];
    u8 *local_4;
    local_0 = func_800D8FF8();
    local_4 = func_80100094(param_0, 0);
    func_800D1218(8, 1, local_1);
    _fxsparkle_entrypoint_1(local_1, 0x12);
    if (!local_4[0x2F]) {
        if (local_1[1] < *(f32 *)(local_4 + 0x10)) {
            local_1[1] = *(f32 *)(local_4 + 0x10);
            *(f32 *)(local_4 + 0x38) *= -0.54f;
            *(f32 *)(local_4 + 0x34) *= 0.08f;
            func_800D1254(8, 1, local_1);
            local_4[0x2F] = 1;
            func_8010D930(3, 0, local_1, D_8080148C_chstonepillar);
            return 1;
        }
        local_2 = *(f32 *)(local_4 + 0x38);
        *(f32 *)(local_4 + 0x38) -= 1200.0f * local_0;
        local_1[1] += *(f32 *)(local_4 + 0x38) * local_0;
        if (local_2 >= 0.0f && *(f32 *)(local_4 + 0x38) < 0.0f) {
            *(f32 *)(local_4 + 0x30) = func_800F1DF4(local_1, (f32 *)(local_4 + 0xC));
        }
        func_800EF1B8(local_1, *(f32 *)(local_4 + 0x30), *(f32 *)(local_4 + 0x34) * local_0);
    } else {
        *(f32 *)(local_4 + 0x38) -= 1200.0f * local_0;
        local_1[1] += *(f32 *)(local_4 + 0x38) * local_0;
        func_800EF1B8(local_1, *(f32 *)(local_4 + 0x30), *(f32 *)(local_4 + 0x34) * local_0);
        if (*(f32 *)(local_4 + 0x38) < 0.0f && local_1[1] < *(f32 *)(local_4 + 0x10)) {
            local_1[1] = *(f32 *)(local_4 + 0x10);
            *(f32 *)(local_4 + 0x38) *= -0.6f;
            func_8010D930(3, 0, local_1, D_8080148C_chstonepillar);
            if (*(f32 *)(local_4 + 0x38) < 2.0f * (1200.0f * local_0)) {
                func_800D1254(8, 1, local_1);
                return 0;
            }
        }
    }
    func_800D1254(8, 1, local_1);
    return 1;
}

void func_80800ADC_chstonepillar(param_0, param_1) s32 param_0; s32 param_1; {
    u8 *local_0;

    local_0 = func_80100094(param_0, 0);
    func_800DA524(0x9D5);
    if (param_1 != 0) {
        func_800DA7A8(0x9CD, (*(s16 *)((s8 *)(local_0) + (0x2C))) + 1, 3);
    }
    func_80101FDC(param_0, 1);
    if (_glcutDll_entrypoint_19(0xB) != 0) {
        _glcutDll_entrypoint_17();
    }
}

s32 func_80800B58_chstonepillar(param_0) Actor *param_0;
{
    f32 local_0[3];
    void *local_1;

    local_1 = func_80100094(param_0, 0);
    func_800D1218(8, 1, local_0);
    func_800BBCB8(local_0, local_0, 1.0f, 0xE, _fxgenlist_entrypoint_0());
    local_0[1] += 40.0f;
    func_80800BDC_chstonepillar(local_0);
    func_800D1254(8, 1, local_1);
    return 0;
}

void func_80800BDC_chstonepillar(param_0) s32 param_0; {
    func_800BBCB8(param_0, 0, 1.0f, 1, &D_80801498_chstonepillar);
}

void func_80800C10_chstonepillar(param_0) s32 param_0; {
    func_800BBCB8(param_0, param_0, 1.0f, 3, &D_808014B8_chstonepillar);
}

void func_80800C44_chstonepillar(param_0) Actor *param_0;
{
    u8 *local_0;

    local_0 = func_80100094(param_0, 0);
    param_0->rotation[1] = func_800136E4((3 - *(s16 *)(local_0 + 0x2C)) * 72.0f);
    if (func_800D0B68(8, 1)) {
        *(s16 *)(local_0 + 0x2C) = -1;
    }
    func_800EE7F8(param_0->position, param_0->actorData);
}

void func_80800CC8_chstonepillar(param_0, param_1) Actor *param_0; s32 param_1;
{
    PillarActivation *local_0;
    local_0 = func_80100094(param_0, 0);
    if (param_0->unk70_10 != 2) {
        if (!local_0->local_0 && !func_800DA298(0x9D6) && !func_800D0B68(8, 1)) {
            func_800CE8D8(0, 45.0f, 45);
            func_800CE88C(0, 1);
            func_800DA544(0x9D6);
        }
        if (func_80800DD8_chstonepillar(param_0)) func_800F7F98(func_800F54E4(), 1);
        func_800C3F48(0x7FF57C16);
        func_808011CC_chstonepillar(param_0, 2, 1.0f, 1.0f);
    }
}

int func_80800DA4_chstonepillar(param_0) s32 param_0;
{
  if (!func_800DA298(0x9D8))
  {
    func_800DA544(0x9D8);
  }
}

int func_80800DD8_chstonepillar(param_0) s32 param_0; {
    u8 *local_0 = func_80100094(param_0, 0);
    return func_800DA564(0x9CD, 3) == *(s16 *)(local_0 + 0x2C) && func_800DA298(*(s16 *)(local_0 + 0x2C) + 0x65C) == 0;
}

void func_80800E30_chstonepillar(param_0) s32 param_0; {
    u8 *local_0;

    local_0 = func_80100094(param_0, 0);
    if (func_80800DD8_chstonepillar(param_0) == 0) {
        func_800DA524(0x9D5);
        func_800DA7A8(0x9CD, *(s16 *)((char *)local_0 + 0x2C) + 1, 3);
        return;
    }
    func_800F7F98(func_800F54E4(), 0);
    if (func_800F6CC8(func_800F54E4()) == 0) {
        func_800DA544(0x9D5);
        func_800DA544(*(s16 *)((char *)local_0 + 0x2C) + 0x65C);
        _glcutDll_entrypoint_6(0xB9, 0xB);
    }
}

void func_80800EE0_chstonepillar(param_0) Actor *param_0;
{
    u8 *local_0;

    local_0 = func_80100094(param_0, 0);
    *(s16 *)(local_0 + 0x2C) = (s32)param_0->rotation[1] - 1;
    *(f32 *)(local_0 + 0x24) = 0.0f;
    local_0[0x2F] = 0;
    *(s32 *)(local_0 + 0x28) = *(s16 *)(local_0 + 0x2C);
    local_0[0x2E] = (s32)param_0->rotation[1] - 1;
    if ((*(u32 *)((u8 *)param_0->unk0 + 0x24) >> 22) == 0x19F) {
        param_0->rotation[1] = func_800136E4(param_0->rotation[1] - *(s16 *)(local_0 + 0x2C) * 18.0f);
    } else {
        param_0->rotation[1] = 0.0f;
    }
    func_800EE7F8((f32 *)param_0->actorData, param_0->position);
    func_800EE7F8((f32 *)(local_0 + 0x18), param_0->position);
    if (func_800D0B68(8, 1)) {
        *(s16 *)(local_0 + 0x2C) = -1;
    }
}

void func_80800FE0_chstonepillar(param_0) u8 **param_0; {
    if ((func_800DA298(0x9D6) != 0) && (func_800DA298(0x9D7) == 0) && (func_8080112C_chstonepillar(param_0) != 0) && ((func_800CEAD0(0) != 0) || (func_800D0B68(8, 1) != 0))) {
        if (func_800CEAA8(0) != 0) {
            func_800CE88C(0, 0);
        }
        func_800DA544(0x9D7);
        if (func_800DA298(0x9D9) != 0) {
            func_80801174_chstonepillar(param_0);
            if (((u32) (*(u32 *)((s8 *)(*param_0) + (0x24))) >> 0x16) != 0x19F) {
                func_800DA524(0x9D7);
            }
        }
        if (func_800D0B68(8, 1) == 0) {
            func_808010CC_chstonepillar(param_0);
            func_800FC660(0x17);
        }
    }
}

int func_808010CC_chstonepillar(param_0) Actor *param_0;
{
  if (!func_800DA298(0x9D9))
  {
    if (func_800EA05C() != 0xB9)
    {
      if (func_800F6CC8(func_800F54E4()) == 0)
      {
        _glcutDll_entrypoint_6(0xB9, 0xB);
      }
    }
  }
}

int func_8080112C_chstonepillar(param_0) s32 param_0;
{
    Actor *local_0;
    local_0 = func_80100094(param_0, 0);
    if (func_800DA564(0x9CD, 3) == (*(s16 *)((char *)(local_0) + 0x2C)))
    {
        return 1;
    }
    return 0;
}

s32 func_80801174_chstonepillar(param_0) s32 param_0;{
    func_800DA7A8(0x9CD, 0, 3);
    func_800DA7A8(0x9CD, 0, 3);
    func_800DA524(0x9D6);
    func_800DA524(0x9D5);
    func_80101FDC(param_0, 1);
}

void func_808011CC_chstonepillar(Actor *param_0, s32 param_1, f32 param_2, f32 param_3)
{
    if (param_1 != param_0->unk70_10) {
        func_80101FDC(param_0, param_1);
        *(f32 *)((u8 *)func_80100094(param_0, 0) + 0x24) = param_2;
        param_0->unk58 = 0.3f;
        func_80018820(0, 3.0f, param_3);
    }
}

s32 func_80801238_chstonepillar(param_0) Actor *param_0;
{
    f32 local_0[3];
    u8 *local_1;

    local_1 = func_80100094(param_0, 0);
    if (func_800D9078(&param_0->unk58) && param_0->unk0->unk24 >> 22 != 0x19F &&
        !func_800D0B68(8, 1) && *(s16 *)(local_1 + 0x2C) != 4 &&
        func_8080112C_chstonepillar(param_0)) {
        func_800FC660(0xE);
    }
    if (*(f32 *)(local_1 + 0x24) > 0.0f) {
        *(f32 *)(local_1 + 0x24) -= func_800D8FF8();
        func_800EE7F8(local_0, param_0->actorData);
        local_0[0] += func_800DC178(-7.5f, 7.5f);
        local_0[2] += func_800DC178(-7.5f, 7.5f);
        func_800EE7F8(param_0->position, local_0);
        return 1;
    }
    func_800EE7F8(param_0->position, param_0->actorData);
    return 0;
}

void func_80801374_chstonepillar(param_0, param_1) PillarS *param_0; s32 param_1; {
    s32 local_0 = param_1 == param_0->f72;
    if (local_0 || (!local_0 && param_0->f5F)) {
        _subaddieaudioloop_entrypoint_4(param_0, 0, local_0, &D_808014F0_chstonepillar);
    }
}
