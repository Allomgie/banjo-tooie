#include "su/baddiefade.h"

typedef struct { u8 local_0[0x74]; u32 local_1:27; u32 local_2:1; u32 local_3:4; } FadeFlags49;
extern f32 func_800D8FF8(void);
typedef struct { u8 pad[0x70]; u32 pad70:29; u32 flag:1; u32 rest:2; } FadeS;
extern void func_800F2F20();
extern void func_800F2F3C();
extern void func_800EFA88();
extern void func_800C87DC();
int func_80800450_subaddiefade();

subaddiefade_entrypoint_0(u8 *param_0) {
    return param_0[0x9B];
}

void subaddiefade_entrypoint_1(u8 *param_0, unsigned int param_1)
{
  param_0[0x9B] = param_1;
  param_0[0x79] &= ~3U;
}

void subaddiefade_entrypoint_2(u8 *param_0)
{
  param_0[0x9B] = 0;
  param_0[0x79] = (param_0[0x79] & 0xFFFC) | 1;
}

void subaddiefade_entrypoint_3(u8 *param_0)
{
  param_0[0x79] = (param_0[0x79] & 0xFFFC) | 2;
}

void subaddiefade_entrypoint_4(u8 *param_0)
{
  param_0[0x79] = (param_0[0x79] & 0xFFFC) | 1;
}

void subaddiefade_entrypoint_5(u8 *param_0)
{
  param_0[121] = (param_0[121] & 0xFFFFu) | 3;
}

void subaddiefade_entrypoint_6(u8 *param_0, s32 param_1) {
    s32 local_0 = param_0[0x9B] + param_1;
    param_0[0x9B] = (((local_0 > 0xFF) ? 0xFF : local_0) < 0) ? 0 : ((local_0 > 0xFF) ? 0xFF : local_0);
}

void subaddiefade_entrypoint_7(Actor *param_0)
{

    s32 local_1;
    if (((FadeFlags49 *)param_0)->local_2) {
        *(f32 *)&param_0->actorData[1] += func_800D8FF8();
        if ((*(f32 *)&param_0->actorData[0]) < *(f32 *)&param_0->actorData[1]) *(f32 *)&param_0->actorData[1] = (*(f32 *)&param_0->actorData[0]);
        switch (*(u16 *)((u8 *)param_0 + 0x78) & 3) {
        case 1:
            if ((*(f32 *)&param_0->actorData[0]) != 0.0f) param_0->alpha = (s32)((*(f32 *)&param_0->actorData[1] / (*(f32 *)&param_0->actorData[0])) * 255.0f);
            else param_0->alpha = 255;
            if (param_0->alpha == 255) *((u8 *)param_0 + 0x79) &= ~3;
            break;
        case 2:
            if ((*(f32 *)&param_0->actorData[0]) != 0.0f) param_0->alpha = 255 - (s32)((*(f32 *)&param_0->actorData[1] / (*(f32 *)&param_0->actorData[0])) * 255.0f);
            else param_0->alpha = 0;
            if (param_0->alpha == 0) *((u8 *)param_0 + 0x79) &= ~3;
            break;
        }
    } else {
        switch (*(u16 *)((u8 *)param_0 + 0x78) & 3) {
        case 1:
            local_1 = param_0->alpha + 7;
            if (local_1 >= 256) param_0->alpha = 255;
            else param_0->alpha = local_1;
            if (param_0->alpha == 255) *((u8 *)param_0 + 0x79) &= ~3;
            break;
        case 2:
            local_1 = param_0->alpha - 7;
            if (local_1 < 0) param_0->alpha = 0;
            else param_0->alpha = local_1;
            if (param_0->alpha == 0 && !func_80107070(param_0, 3)) func_800FFAB0(param_0);
            break;
        case 3:
            local_1 = param_0->alpha - 7;
            if (local_1 < 0) param_0->alpha = 0;
            else param_0->alpha = local_1;
            if (param_0->alpha == 0) *((u8 *)param_0 + 0x79) &= ~3;
            break;
        }
    }
}

void subaddiefade_entrypoint_8(u8 *param_0, s32 param_1)
{
    s32 local_0;
    local_0 = func_800F0D90(param_1, 0, 0xFF);
    param_0[0x9B] = (u8)local_0;
}

s32 subaddiefade_entrypoint_9(s32 param_0, s32 param_1)
{
  s32 local_0;
  s32 local_1 = param_1;
  func_800F2EE0(local_1, param_0 + 0x98);
}

void subaddiefade_entrypoint_10(s32 param_0, s32 param_1)
{
  func_800F2EFC(param_1, param_0 + 0x98);
}

void subaddiefade_entrypoint_11(FadeS *param_0, f32 *param_1) {
    f32 local_0[3];
    if (param_0->flag) {
        func_80800450_subaddiefade(local_0);
        func_800F2F20((u8 *)param_0 + 0x98, local_0);
    } else {
        func_800F2F20((u8 *)param_0 + 0x98, param_1);
    }
}

s32 subaddiefade_entrypoint_12(Actor *this){
    f32 local_0[3];

    func_800EFA88(local_0);
    subaddiefade_entrypoint_11(this, &local_0);
}

void subaddiefade_entrypoint_13(FadeS *param_0, f32 *param_1) {
    f32 local_0[3];
    if (param_0->flag) {
        func_80800450_subaddiefade(local_0);
        func_800F2F20((u8 *)param_0 + 0x98, local_0);
    } else {
        func_800F2F3C((u8 *)param_0 + 0x98, param_1);
    }
}

int func_80800450_subaddiefade(param_0, param_1) s32 param_0[3]; s32 param_1[3];
{
  f32 local_0;
  local_0 = ((param_1[0] + param_1[1]) + param_1[2]) / 3.0f;
  param_0[2] = (param_0[1] = (param_0[0] = ((param_1[0] + param_1[1]) + param_1[2]) / 3.0f));
}

s32 subaddiefade_entrypoint_14(Actor *this){
    f32 local_0[3];

    func_800C87DC(local_0);
    subaddiefade_entrypoint_11(this, &local_0);
}
