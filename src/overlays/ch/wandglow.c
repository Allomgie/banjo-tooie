#include "common.h"

extern void func_800EFA4C(f32 *, f32, f32, f32);
extern f32 func_800F10B4(f32, f32, f32, f32, f32);
extern void func_800DE448(f32 *, f32 *, f32, s32, s32);
extern void func_800F5A2C(Unk80132ED0 *, s32, f32 *);
extern s32 func_800D9078();
extern Actor *func_80108474(s32, f32 *, s32);
extern s32 D_80800410_chwandglow[];
typedef struct WandGlowStateBits { u8 local_0 : 6; u8 pad_0 : 2; } WandGlowStateBits;
void func_8080011C_chwandglow();

void func_80800000_chwandglow(Actor *param_0, s32 param_1)
{
    f32 local_0[3];
    f32 local_1[3];
    f32 local_2[3];

    func_800F5A00(param_0->unk6C_0, local_0);
    func_800F5A2C((Unk80132ED0 *)param_0->unk6C_0, 6, local_2);
    if (!func_800EECE0(local_0, local_2)) {
        func_800EE7F8(param_0->position, local_2);
    }
    func_800EFA4C(local_1, 0.0f, 0.0f, 0.0f);
    func_800DF410((s32)func_800F10B4(*(f32 *)((u8 *)param_0 + 0x2C), 0.0f, 1.0f, 0.0f, 255.0f));
    func_800DF830(2);
    func_800DE448(param_0->position, local_1, param_0->scale, 0, func_801039E4(param_0->unk0));
}

void func_808000E8_chwandglow(s32 *arg0)
{
  s32 (*func)(s32, s32, s32 *);
  s32 var1;
  s32 (*new_var)(s32, s32, s32 *);
  s32 var2;
  var1 = *arg0;
  var2 = *(arg0 + 0x1B);
  func = *((s32 (**)(s32, s32, s32 *)) (arg0 + 0xC));
  var2 &= 0x1FF;
  new_var = *((s32 (**)(s32, s32, s32 *)) (arg0 + 0xC));
  func = new_var;
  func(var1, var2, arg0);
}

void func_8080011C_chwandglow(param_0, param_1) Actor *param_0; s32 param_1;
{
    switch (param_1) {
        case 2:
            ((f32 *)param_0->actorData)[4] = 0.4f;
            ((f32 *)param_0->actorData)[5] = 0.0f;
            break;
        case 3:
            ((f32 *)param_0->actorData)[5] = 1.0f;
            param_0->scale = 1.0f;
            break;
        case 4:
            param_0->scale = 1.0f;
            ((f32 *)param_0->actorData)[4] = func_800F10B4(((f32 *)param_0->actorData)[5], 0.0f, 1.0f, 0.0f, 0.3f);
            if (((f32 *)param_0->actorData)[4] == 0.0f) ((f32 *)param_0->actorData)[4] += 0.01f;
            break;
        case 5:
            ((f32 *)param_0->actorData)[5] = 0.0f;
            break;
    }
    ((WandGlowStateBits *)((u8 *)param_0 + 0x72))->local_0 = param_1;
}

void func_80800218_chwandglow(Actor *param_0)
{
    switch (param_0->unk70_10) {
    case 2:
        *(f32 *)((u8 *)param_0 + 0x2C) = func_800F10B4(*(f32 *)((u8 *)param_0 + 0x28), 0.0f, 0.4f, 1, 0.0f);
        if (func_800D9078((f32 *)((u8 *)param_0 + 0x28))) func_8080011C_chwandglow(param_0, 3);
        break;
    case 3:
        if (param_0->scale == 1.0f) param_0->scale = 0.75f;
        else param_0->scale = 1.0f;
        break;
    case 4:
        *(f32 *)((u8 *)param_0 + 0x2C) = func_800F10B4(*(f32 *)((u8 *)param_0 + 0x28), 0.0f, 0.3f, 0.0f, 1);
        if (func_800D9078((f32 *)((u8 *)param_0 + 0x28))) func_8080011C_chwandglow(param_0, 5);
        break;
    case 5:
        func_800FFA88(param_0->unk0);
        break;
    }
}

Unk80132ED0 *chwandglow_entrypoint_0(Unk80132ED0 *param_0, void *param_1)
{
    Actor *local_1;
    f32 local_0[3];
    func_800F5A2C(param_0, 6, local_0);
    local_1 = func_80108474(0x164, local_0, 0);
    local_1->unk6C_0 = (u32)param_0;
    local_1->actorData[6] = (u32)param_1;
    func_8080011C_chwandglow(local_1, 2);
    return local_1->unk0;
}

void chwandglow_entrypoint_1()
{
    func_800FFA88();
}

s32 chwandglow_entrypoint_2(void) {
    func_8080011C_chwandglow(func_80106790(), 4);
}

int chwandglow_entrypoint_3()
{
    return (int)D_80800410_chwandglow;
}
