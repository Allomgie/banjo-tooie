#include "common.h"

extern void *func_80100094(Actor *, u32);
extern void func_800EE7F8();
extern void func_800EF04C();
extern void func_8010D254();
typedef struct { f32 local_0; f32 local_1; u8 pad_0[8]; f32 local_2[3]; u8 pad_1[0xC]; f32 local_3; } MumboEffectBlend;
extern void func_800EEB9C(f32 *, f32, f32);
extern void func_800EF334(f32 *, f32);
typedef struct { u8 pad0[0x10]; f32 unk10; f32 unk14; u8 pad18[0x10]; f32 unk28[3]; f32 unk34; f32 unk38; u8 pad3C[0xC]; u8 unk48[0xC]; s32 unk54; u8 pad58[8]; u32 unk60_25 : 7; u32 pad60 : 17; u8 pad63; } MumboFx;
extern f32 func_800F10B4(f32, f32, f32, f32, f32);
extern void *func_800F54E4(void);
extern void func_800F5A00(void *, f32 *);
extern f32 func_800EEB40(f32 *, f32 *);
extern void func_800B99CC(s32, s32, u8 *);
extern Vec3f D_808014DC_sumumbofx;
extern void func_800F3214(f32 *, f32 *, f32 *, f32);
extern void func_800C8E84(s32, f32 *);
extern f32 func_800DC178(f32, f32);
typedef struct { f32 angle; f32 offset; f32 radius; f32 speed; u8 pad_0[0x10]; f32 phase; f32 period; f32 pad_1; } MumboSpark29;
typedef struct { u8 pad_0[0x58]; s16 count; u8 pad_1[0xA]; MumboSpark29 sparks[1]; } MumboParticles29;
extern f32 func_800D8FF8(void);
extern f32 func_80013970(f32);
typedef struct { f32 local_0; f32 local_1; f32 local_2; f32 local_3; f32 local_4[3]; f32 local_5; f32 local_6; f32 local_7; f32 local_8; } MumboParticle48;
extern void func_800EF5A0(f32 *, f32 *, f32, f32, f32);
extern void func_800EF4E4(f32 *, f32, f32, f32, f32, f32);
typedef struct { u32 local_0 : 7; u32 pad_0 : 25; } Broad51MumboFXFlags;
extern u8 D_808014D0_sumumbofx[];
extern void func_800EFA4C(f32 *, f32, f32, f32);
typedef struct { u8 local_0[0x60]; u32 local_1:7; u32 local_2:1; u32 local_3:24; } Mass47MumboFX;
int sumumbofx_entrypoint_13();
void sumumbofx_entrypoint_20(void *param_0, f32 param_1);

void sumumbofx_entrypoint_0(Actor *param_0, u32 param_1, s32 param_2, s16 param_3)
{
    u8 *local_0;
    func_80100074(param_0, param_1, param_2 * 44 + 0x64);
    local_0 = func_80100094(param_0, param_1);
    *(s32 *)local_0 = param_3;
    *(s16 *)(local_0 + 0x58) = param_2;
    func_800EE7F8((f32 *)(local_0 + 0x1C), param_0->position);
    local_0[0x63] = 0;
}

void sumumbofx_entrypoint_1(Actor *param_0, u32 param_1)
{
    u8 *local_0;
    local_0 = func_80100094(param_0, param_1);
    if (*(s16 *)(local_0 + 0x5E)) {
        sumumbofx_entrypoint_13(local_0);
    }
    switch (local_0[0x62]) {
    case 1:
        break;
    case 2:
        func_800FCAE0(0x1C, 0, 0x4E20);
        func_800FCA90(0x1C);
        break;
    }
    func_80100074(param_0, param_1, 0);
}

void sumumbofx_entrypoint_2(u8 *param_0)
{
    s32 local_0;
    u8 *local_1;

    *(s16 *)(param_0 + 0x5A) = 0;
    *(s16 *)(param_0 + 0x5C) = 0;
    param_0[0x60] &= ~0xFE;
    *(s16 *)(param_0 + 0x5E) = 0;
    param_0[0x61] = 0;
    param_0[0x62] = 2;
    *(s32 *)(param_0 + 0x54) = -1;
    *(f32 *)(param_0 + 0x10) = 0.0f;
    *(f32 *)(param_0 + 0x14) = 0.0f;
    *(f32 *)(param_0 + 0x18) = 0.0f;
    *(f32 *)(param_0 + 4) = 0.0f;
    *(f32 *)(param_0 + 12) = 1.0f;
    for (local_0 = 0, local_1 = param_0 + 0x64; local_0 < *(s16 *)(param_0 + 0x58); local_0++, local_1 += 0x2C) {
        *(f32 *)(local_1 + 0x1C) = 0.0f;
        *(f32 *)(local_1 + 0x24) = func_800DC178(0.4f, 0.8f);
        *(f32 *)(local_1 + 0x20) = func_800DC178(0, *(f32 *)(local_1 + 0x24));
        *(f32 *)local_1 = func_800DC178(0.0f, 359.0f);
        *(f32 *)(local_1 + 4) = 0.0f;
        *(f32 *)(local_1 + 12) = func_800DC178(8.0f, 16.0f);
        *(f32 *)(local_1 + 8) = func_800DC178(8.0f, 16.0f);
    }
}

void sumumbofx_entrypoint_3(MumboParticles29 *param_0, f32 param_1)
{
    s32 local_0;
    MumboSpark29 *local_1 = param_0->sparks;
    for (local_0 = 0; local_0 < param_0->count; local_0++, local_1++) {
        local_1->period = func_800DC178(0.4f, 0.8f);
        local_1->phase = func_800DC178(0, local_1->period);
        local_1->angle = func_800DC178(0.0f, 359.0f);
        local_1->offset = func_800DC178(0.0f, param_1);
        local_1->speed = func_800DC178(8.0f, 16.0f);
        local_1->radius = func_800DC178(8.0f, 16.0f);
    }
}

void sumumbofx_entrypoint_4(u8 *param_0)
{
  s32 local_0;
  f32 *new_var;
  u8 *local_1;
  local_1 = param_0 + 0x64;
  local_0 = 0;
  *((f32 *) (((s8 *) param_0) + 8)) = 0.0f;
  if ((*((s16 *) (((s8 *) param_0) + 0x58))) > 0)
  {
    do
    {
      *((f32 *) (((s8 *) local_1) + 0x28)) = 1.0f;
      local_0 += 1;
      local_1 += 0x2C;
      *((f32 *) (((s8 *) param_0) + 8)) = (f32) ((*((f32 *) (((s8 *) param_0) + 8))) + 1.0f);
    }
    while (local_0 < (*((s16 *) (((s8 *) param_0) + 0x58))));
  }
  new_var = (f32 *) (((s8 *) param_0) + 4);
  if ((*new_var) != 1.0f)
  {
    *((f32 *) (((s8 *) param_0) + 4)) = 1.0f;
    *((u8 *) (((s8 *) param_0) + 0x60)) = (u8) (((*((u8 *) (((s8 *) param_0) + 0x60))) & 0xFF) | 1);
  }
}

void func_808003E4_sumumbofx(MumboEffectBlend *param_0, f32 param_1, f32 param_2)
{
    f32 local_0[3];
    f32 local_1[3];

    func_8010D254(local_1);
    func_800EEB9C(local_0, param_0->local_0, param_2);
    local_0[1] = param_0->local_1 * 0.75f;
    if (param_1 < local_0[1]) {
        do { local_0[1] -= param_1; } while (param_1 < local_0[1]);
    }
    func_800EF04C(local_0, local_1);
    func_800EF334(local_0, 1.0f - param_0->local_3);
    func_800EF334(param_0->local_2, param_0->local_3);
    func_800EF04C(param_0->local_2, local_0);
}

s32 sumumbofx_entrypoint_5(u8 *param_0, f32 param_1)
{
    s32 local_1;
    s32 local_0 = 0;
    u8 *local_2;
    f32 local_3;
    f32 local_4;
    f32 local_5;
    local_2 = param_0 + 0x64;
    *(f32 *)(param_0 + 8) = 0.0f;
    for (local_1 = 0; local_1 < *(s16 *)(param_0 + 0x58); local_1++, local_2 += 0x2C) {
        if (*(s16 *)(param_0 + 0x5A) >= local_1) {
            local_3 = *(f32 *)(local_2 + 0x28);
            if (local_3 < 0.98f) {
                local_4 = (1.0f - local_3) * 0.075f;
                local_5 = local_4 < 0.02f ? 0.02f : local_4;
                *(f32 *)(local_2 + 0x28) = local_3 + local_5;
            } else {
                *(f32 *)(local_2 + 0x28) = 1.0f;
                local_0++;
            }
        }
        *(f32 *)(param_0 + 8) += *(f32 *)(local_2 + 0x28);
    }
    *(s16 *)(param_0 + 0x5A) = func_800F10B4(*(f32 *)(param_0 + 0x18), 0.0f, param_1, 0.0f, (f32)*(s16 *)(param_0 + 0x58));
    *(f32 *)(param_0 + 0x18) += func_800D8FF8();
    if (local_0 < *(s16 *)(param_0 + 0x58)) return 0;
    return 1;
}

void func_8080060C_sumumbofx(void *param_0, void *param_1, f32 param_2)
{
    f32 local_0;
    local_0 = *(f32 *)((u8 *)param_1 + 0x28) * *(f32 *)((u8 *)param_0 + 0xC) + (1.0f - *(f32 *)((u8 *)param_1 + 0x28)) * 0.25f;
    *(f32 *)((u8 *)param_1 + 0x20) += func_800D8FF8();
    if (*(f32 *)((u8 *)param_1 + 0x20) >= *(f32 *)((u8 *)param_1 + 0x24)) *(f32 *)((u8 *)param_1 + 0x20) -= *(f32 *)((u8 *)param_1 + 0x24);
    switch (*(u32 *)((u8 *)param_0 + 0x60) >> 25) {
    case 2: param_2 = 1.0f - param_2;
    case 1:
        *(f32 *)((u8 *)param_1 + 0x1C) = (func_80013970(func_800F10B4(*(f32 *)((u8 *)param_1 + 0x20), 0.0f, *(f32 *)((u8 *)param_1 + 0x24), 0.0f, 180.0f)) * 0.7f + 0.3f) * (param_2 * local_0);
        break;
    case 0:
        *(f32 *)((u8 *)param_1 + 0x28) += 0.02f;
        if (*(f32 *)((u8 *)param_1 + 0x28) > 1.0f) *(f32 *)((u8 *)param_1 + 0x28) = 1.0f;
    case 3:
        *(f32 *)((u8 *)param_1 + 0x1C) = (func_80013970(func_800F10B4(*(f32 *)((u8 *)param_1 + 0x20), 0.0f, *(f32 *)((u8 *)param_1 + 0x24), 0.0f, 180.0f)) * 0.7f + 0.3f) * local_0;
        break;
    }
}

f32 sumumbofx_entrypoint_26();

void sumumbofx_entrypoint_6(u8 *param_0, f32 param_1, f32 param_2, s32 param_3, s32 param_4,
    f32 *param_5, f32 *param_6, f32 *param_7)
{
    f32 local_0;
    MumboParticle48 *local_1;
    f32 *local_2;
    s32 local_3;
    u32 local_4;
    s32 k = 1; /* comparison value as a local: the loop-invariant constant register is the left operand of beql */

    local_0 = sumumbofx_entrypoint_26();
    local_1 = (MumboParticle48 *)(param_0 + 0x64) + param_3;
    for (local_3 = param_3; local_3 < param_4; local_3++, local_1++) {
        func_8080060C_sumumbofx(param_0, local_1, local_0);
        local_2 = local_1->local_4;
        local_1->local_1 += local_1->local_2;
        if (param_1 < local_1->local_1) {
            local_1->local_1 = 0.0f;
            local_4 = *(u32 *)(param_0 + 0x60) >> 25;
            if (k != local_4 && local_4 != 2) {
                local_1->local_5 = 0.25f;
            }
        }
        local_1->local_0 += local_1->local_3;
        if (local_1->local_0 > 359.0f) {
            local_1->local_0 = 0.0f;
        }
        func_800EEB9C(local_2, local_1->local_0, param_2);
        local_1->local_4[1] = local_1->local_1;
        func_800EF04C(local_2, param_5);
        if (param_7 != NULL) {
            func_800EF5A0(local_2, param_7, local_1->local_4[0], local_1->local_4[1], local_1->local_4[2]);
        }
        if (param_6 != NULL) {
            func_800EF04C(local_2, param_6);
        }
        if (local_1->local_8 < 1.0f) {
            func_808003E4_sumumbofx(local_1, 125.0f, 40.0f);
        }
    }
    if (param_6 != NULL) {
        func_800EE7F8((f32 *)(param_0 + 0x1C), param_6);
    }
}

void sumumbofx_entrypoint_7(u8 *param_0, f32 param_1, s32 param_2, s32 param_3, s32 param_4, f32 *param_5, s32 param_6)
{
    f32 local_0;
    s32 local_1;
    u32 local_2;
    u8 *local_3;
    f32 *local_4;

    local_0 = sumumbofx_entrypoint_26((f32 *)param_0);
    local_3 = param_0;
    local_3 += param_2 * 0x2C + 0x64;
    for (local_1 = param_2; local_1 < param_3; local_1++) {
        func_8080060C_sumumbofx(param_0, local_3, local_0);
        local_4 = (f32 *)(local_3 + 0x10);
        *(f32 *)(local_3 + 4) += *(f32 *)(local_3 + 8) * 0.15f;
        if (*(f32 *)(local_3 + 4) > 359.0f) {
            while (*(f32 *)(local_3 + 4) > 359.0f) {
                *(f32 *)(local_3 + 4) -= 360.0f;
            }
            if (((Broad51MumboFXFlags *)(param_0 + 0x60))->local_0 != 1 &&
                ((Broad51MumboFXFlags *)(param_0 + 0x60))->local_0 != 2) {
                *(f32 *)(local_3 + 0x1C) = 0.25f;
            }
        }
        *(f32 *)local_3 += *(f32 *)(local_3 + 0xC) * 0.3f;
        if (*(f32 *)local_3 > 359.0f) {
            *(f32 *)local_3 = 0.0f;
        }
        func_800EF4E4(local_4, *(f32 *)(local_3 + 4), *(f32 *)local_3, 0.0f, 0.0f, param_1);
        func_800EF04C(local_4, param_4);
        if (param_6) {
            func_800EF5A0(local_4, param_6, *(f32 *)(local_3 + 0x10), *(f32 *)(local_3 + 0x14), *(f32 *)(local_3 + 0x18));
        }
        if (param_5) {
            func_800EF04C(local_4, param_5);
        }
        if (*(f32 *)(local_3 + 0x28) < 1.0f) {
            func_808003E4_sumumbofx(local_3, 125.0f, 40.0f);
        }
        local_3 += 0x2C;
    }
    if (param_5) {
        func_800EE7F8((f32 *)(param_0 + 0x1C), param_5);
    }
}

void sumumbofx_entrypoint_8(u8 *param_0, void *param_1)
{
    Vec3f local_0 = *(Vec3f *)D_808014D0_sumumbofx;
    f32 local_1[3];
    u8 *local_2;
    void *local_3;
    s32 local_4;
    f32 local_5;
    param_0[0x61] = 1;
    local_3 = (void *)func_800D674C(*(s32 *)param_0);
    func_800E2588(2);
    func_800E2594(param_1, local_3);
    func_800E24D8(1);
    local_2 = param_0 + 0x64;
    for (local_4 = 0; local_4 < *(s16 *)(param_0 + 0x58); local_4++, local_2 += 0x2C) {
        local_5 = *(f32 *)(local_2 + 0x1C);
        if (local_5 > 0.005f) {
            func_800EFA4C(local_1, local_5, local_5, local_5);
            func_800E2720(param_1, 0, 0, local_2 + 0x10, local_1, (s32)(*(f32 *)(param_0 + 4) * 127.0f + 128.0f));
        }
    }
    func_800E2A14(param_1);
}

void sumumbofx_entrypoint_9(MumboFx *param_0, s32 param_1)
{
    f32 local_0;
    f32 local_1[3];
    f32 local_2;

    if (param_0->unk54 == -1) {
        return;
    }
    switch (param_0->unk60_25) {
    case 1:
        local_0 = func_800F10B4(param_0->unk10, param_0->unk14, 0.0f, 0.0f, 1.0f);
        break;
    case 0:
    case 3:
        local_0 = 1.0f;
        break;
    case 2:
        local_0 = func_800F10B4(param_0->unk10, param_0->unk14, 0.0f, 1.0f, 0.0f);
        break;
    }
    if (param_0->pad63) {
        func_800F5A00(func_800F54E4(), local_1);
        local_2 = func_800EEB40(param_0->unk28, local_1);
        if (!(local_2 < param_0->unk34)) {
            if (param_0->unk38 < local_2) {
                local_0 = 0.0f;
            } else {
                local_0 *= func_800F10B4(local_2, param_0->unk34, param_0->unk38, 1.0f, 0.0f);
            }
        } else {
        }
    } else {
    }
    func_800B99CC(param_1, param_0->unk54 * local_0, param_0->unk48);
}

s32 sumumbofx_entrypoint_10(u8 *param_0)
{
  u8 *new_var;
  new_var = (u8 *) param_0;
  return (s32) (255.0f - ((((*((f32 *) (new_var + 8))) / ((f32) (*((s16 *) (((u8 *) param_0) + 0x58))))) * (*((f32 *) (((u8 *) param_0) + 4)))) * 255.0f));
}

int sumumbofx_entrypoint_11(param_0) s32 param_0;
{
  s16 local_0;
  local_0 = *(s16*)((char*)param_0 + 0x5e);
  func_800C8CB8(local_0);
}

void func_80800F8C_sumumbofx(u8 *param_0)
{
    f32 local_0[3];
    Vec3f local_1 = D_808014DC_sumumbofx;

    func_800F3214(local_0, local_1.f, (f32 *)(param_0 + 0x3C), *(f32 *)(param_0 + 4));
    func_800C8E84(*(s16 *)(param_0 + 0x5E), local_0);
}

void sumumbofx_entrypoint_12(s32 param_0, s32 param_1, s32 param_2, s32 param_3)
{
  s32 *s0 = (s32 *) param_0;
  func_800EE830(param_0 + 0x3C, param_3);
  *(s16*)((char*)s0 + 0x5E) = func_800C8A98();
  func_80800F8C_sumumbofx(s0);
  sumumbofx_entrypoint_11(s0, param_1);
  func_800C8D4C(*(s16*)((char*)s0 + 0x5E), param_2);
}

int sumumbofx_entrypoint_13(param_0) s32 param_0;
{
  s16 local_0;
  local_0 = *(s16*)((char*)param_0 + 0x5e);
  func_800C8B84(local_0);
}

void sumumbofx_entrypoint_14(u8 *param_0)
{
    f32 pad[2];
    f32 local_0[4];
    f32 local_1;
    f32 local_2;

    switch (((Mass47MumboFX *)param_0)->local_1) {
    case 2:
        local_1 = sumumbofx_entrypoint_26((f32 *)param_0);
        local_1 = 1.0f - local_1;
        ((Mass47MumboFX *)param_0)->local_2 = local_1 != *(f32 *)(param_0 + 4);
        *(f32 *)(param_0 + 4) = local_1;
        break;
    case 1:
        local_1 = sumumbofx_entrypoint_26((f32 *)param_0);
        ((Mass47MumboFX *)param_0)->local_2 = local_1 != *(f32 *)(param_0 + 4);
        *(f32 *)(param_0 + 4) = local_1;
        break;
    }
    if (param_0[0x61] && *(f32 *)(param_0 + 4) > 0.1f && param_0[0x62] == 2) {
        if (param_0[0x63]) {
            func_800F5A00(func_800F54E4(), local_0);
            local_1 = func_800EEB40((f32 *)(param_0 + 0x28), local_0);
            if (local_1 < *(f32 *)(param_0 + 0x34)) {
                local_2 = 1.0f;
            } else if (*(f32 *)(param_0 + 0x38) < local_1) {
                local_2 = 0.0f;
            } else {
                local_2 = func_800F10B4(local_1, *(f32 *)(param_0 + 0x34),
                    *(f32 *)(param_0 + 0x38), 1.0f, 0.0f);
            }
        } else {
            local_2 = 1.0f;
        }
        func_800FCAE0(0x1C, (s32)(*(f32 *)(param_0 + 4) * 20000.0f * local_2), 500);
    }
    param_0[0x61] = 0;
    func_800D9078(param_0 + 0x10);
    if (((Mass47MumboFX *)param_0)->local_2) {
        ((Mass47MumboFX *)param_0)->local_2 = 0;
        if (*(s16 *)(param_0 + 0x5E)) {
            func_80800F8C_sumumbofx(param_0);
        }
    }
}

void sumumbofx_entrypoint_15(u8 *param_0, f32 param_1) {
    param_0[0x60] = (param_0[0x60] & 0xFF01) | 2;
    sumumbofx_entrypoint_20(param_0, param_1);
}

void sumumbofx_entrypoint_16(u8 *param_0, f32 param_1) {
    param_0[0x60] = (param_0[0x60] & 0xFF01) | 4;
    sumumbofx_entrypoint_20(param_0, param_1);
}

void sumumbofx_entrypoint_17(u8 *param_0, f32 param_1) {
    param_0[0x60] &= 0xFF01;
    sumumbofx_entrypoint_20(param_0, param_1);
}

void sumumbofx_entrypoint_18(u8 *param_0, f32 param_1) {
    param_0[0x60] = (param_0[0x60] & 0xFF01) | 6;
    sumumbofx_entrypoint_20(param_0, param_1);
}

void sumumbofx_entrypoint_19(u8 *param_0, unsigned int param_1)
{
  *((s8 *) (((s8 *) param_0) + 0x62)) = param_1;
}

void sumumbofx_entrypoint_20(void *param_0, f32 param_1)
{
    *(f32 *)((char *)param_0 + 0x10) = param_1;
    *(f32 *)((char *)param_0 + 0x14) = param_1;
}

f32 sumumbofx_entrypoint_21(arg) void *arg;
{
    return ((f32 *)arg)[4];
}

f32 sumumbofx_entrypoint_22(f32 param_0[3])
{
  return param_0[1];
}

void sumumbofx_entrypoint_23(f32 param_0[3], f32 param_1)
{
  param_0[1] = param_1;
}

void sumumbofx_entrypoint_24(void *param_0, float param_1)
{
    *(float *)((char *)param_0 + 12) = param_1;
}

void sumumbofx_entrypoint_25(u8 *param_0, s32 param_1, s32 param_2) {
    *(s32 *)(param_0 + 0x54) = param_1;
    func_800EE830(param_0 + 0x48, param_2);
}

f32 sumumbofx_entrypoint_26(param_0) f32 param_0[4];
{
    return 1.0f - param_0[4] / param_0[5];
}

s32 sumumbofx_entrypoint_27(void)
{
    return sumumbofx_entrypoint_21() <= 0.0f;
}

int sumumbofx_entrypoint_28(s32 param_0, s32 param_1, f32 param_2, f32 param_3)
{
  u8 *local_0;
  local_0 = &(*(s32 *)((char *)(param_0) + 0x63));
  *local_0 = 1;
  func_800EE7F8(&(*(s32 *)((char *)(param_0) + 0x28)), param_1, param_0);
  (*(f32 *)((char *)(param_0) + 0x34)) = param_2 * param_2;
  (*(f32 *)((char *)(param_0) + 0x38)) = param_3 * param_3;
}
