#include "common.h"
#include "playerstate.h"
#include "core2/1E93440.h"

extern f32 func_8009BB18(PlayerState *);
extern void _batimer_set(PlayerState *, s32, f32);
extern s32 func_80096544(void);
extern f32 func_800964DC(void *);
extern f32 func_8009C150(void *);
extern f32 func_8009BB5C(void *);
extern s32 _fxdlsmoke_entrypoint_0(f32 *);
extern void func_800BA7C4(s32, f32, f32);
extern void func_800BA7FC(s32, f32, f32);
extern void func_800BA8F8(s32, f32, f32);
extern void func_800BA5BC(s32, f32, f32);
typedef struct { s32 local_0; u8 pad_0[5]; u8 local_1; } DustState;
typedef struct { u8 pad_0[0x5C]; DustState *local_0; } DustPlayer;
extern void func_8009C128(PlayerState *, f32 *);
extern void func_800EFCD8(f32 *, f32, f32);
extern void func_800EFA4C(f32 *, f32, f32, f32);
extern void func_800BA930(s32, s32, s32, s32, s32, s32, s32);
extern f32 yaw_get(PlayerState *);
extern f32 func_800DC178(f32, f32);
extern f32 func_800DC0C0(void);
extern f32 func_800136E4(f32);
extern void func_800EF334(f32 *, f32);
extern int func_800EF04C(f32 *, f32 *);
void badust_entrypoint_12();
void badust_entrypoint_4(PlayerState *param_0, f32 param_1, f32 param_2);
void badust_entrypoint_5(PlayerState *param_0, f32 param_1, f32 param_2);

s32 badust_entrypoint_0() 
{
    return 0xC;
}

void func_80800008_badust(arg0) s32 arg0; 
{
}
void func_80800010_badust(param_0) PlayerState *param_0;
{
    if (_batimer_decrement(param_0, 8)) {
        func_800A2EEC(param_0, 0);
        _batimer_set(param_0, 8, 0.12f);
    }
    ((u8 *)*(u8 **)((u8 *)param_0 + 0x5C))[9] = (((u8 *)*(u8 **)((u8 *)param_0 + 0x5C))[9] + 1) % 2;
    switch (((u8 *)*(u8 **)((u8 *)param_0 + 0x5C))[9]) {
    case 0:
        badust_entrypoint_4(param_0, func_8009BB18(param_0) + 180.0f - 70.0f, 20.0f);
        return;
    case 1:
        badust_entrypoint_4(param_0, func_8009BB18(param_0) + 180.0f - 10.0f, 20.0f);
        return;
    case 2:
        badust_entrypoint_4(param_0, func_8009BB18(param_0) + 180.0f + 50.0f, 20.0f);
        return;
    }
}

void badust_entrypoint_1(void *param_0)
{
  f32 sp24;
  u8 *temp_v0;
  if ((func_80096544() == 0) || ((sp24 = func_800964DC(param_0), !(func_8009C150(param_0) < sp24))))
  {
    temp_v0 = *((u8 **) (((u8 *) param_0) + 0x5C));
    if ((*((s32 *) (((u8 *) temp_v0) + 4))) != 0)
    {
      *((s32 *) (((u8 *) temp_v0) + 4)) = 0;
    }
    else
    {
      *((s32 *) (((u8 *) temp_v0) + 4)) = 1;
    }
    if (func_8009BB5C(param_0) > 100.0f)
    {
      if ((*((s32 *) (((u8 *) (*((u8 **) (((u8 *) param_0) + 0x5C)))) + 4))) != 0)
      {
        badust_entrypoint_4(param_0, func_8009BB18(param_0) - 20.0f, 20.0f);
        return;
      }
      badust_entrypoint_4(param_0, func_8009BB18(param_0) + 20.0f, 20.0f);
    }
  }
}

void badust_entrypoint_2(PlayerState *param_0, f32 *param_1, f32 *param_2, f32 param_3, f32 param_4, f32 param_5)
{
    s32 local_0;
    s16 local_1;
    s16 local_2;
    s16 local_3;
    local_0 = _fxdlsmoke_entrypoint_0(param_1);
    local_1 = (s16)param_2[0];
    local_2 = (s16)param_2[1];
    local_3 = (s16)param_2[2];
    func_800BA930(local_0, local_1, local_2, local_3, local_1, local_2, local_3);
    func_800BA450(local_0, 0, 0, 0, 0, 0, 0);
    func_800BA7C4(local_0, param_3, param_3);
    func_800BA7FC(local_0, param_4, param_4);
    func_800BA8F8(local_0, param_5, param_5);
    func_800BA5BC(local_0, 19.0f / param_5, 19.0f / param_5);
    func_800BA22C(local_0, 1);
}

void badust_entrypoint_3(PlayerState *param_0, f32 param_1, f32 param_2)
{
    f32 local_1[3];
    f32 local_0[3];

    param_2 *= 0.51f;
    func_8009C128(param_0, local_0);
    local_0[1] += 12.0f;
    func_800EFCD8(local_1, param_1, param_2);
    local_1[1] = 50.0f;
    badust_entrypoint_2(param_0, local_0, local_1, 0.1f, 0.8f, 1.0f);
}

void badust_entrypoint_4(PlayerState *param_0, f32 param_1, f32 param_2)
{
    f32 local_0[3];
    f32 local_1[3];
    f32 local_2[3];
    s32 local_3;

    func_800EFA4C(local_2, 0.0f, 40.0f, 0.0f);
    func_8009C128(param_0, local_1);
    func_800EFCD8(local_0, param_1, param_2);
    local_0[1] = 15.0f;
    func_800EF04C(local_1, local_0);
    local_3 = _fxdlsmoke_entrypoint_0(local_1);
    func_800BA930(local_3, (s16)local_2[0], (s16)local_2[1], (s16)local_2[2],
        (s16)local_2[0], (s16)local_2[1], (s16)local_2[2]);
    func_800BA450(local_3, 0, 0, 0, 0, 0, 0);
    func_800BA7C4(local_3, 0.2f, 0.2f);
    func_800BA7FC(local_3, 0.7f, 0.75f);
    func_800BA8F8(local_3, 0.6f, 0.7f);
    func_800BA5BC(local_3, 19.0f, 19.0f);
    func_800BA22C(local_3, 1);
}

void badust_entrypoint_5(PlayerState *param_0, f32 param_1, f32 param_2)
{
    f32 local_1[3];
    f32 local_0[3];

    param_2 *= 0.51f;
    func_8009C128(param_0, local_0);
    local_0[1] += 2.0f;
    func_800EFCD8(local_1, param_1, param_2);
    local_1[1] = 50.0f;
    badust_entrypoint_2(param_0, local_0, local_1, 0.1f, 0.8f, 1.0f);
}

void badust_entrypoint_6(PlayerState *param_0, f32 param_1, f32 param_2, f32 param_3, f32 param_4)
{
    f32 local_0[3];
    f32 local_1[3];
    param_3 *= 0.51f;
    func_8009C128(param_0, local_1);
    local_1[1] += 12.0f + param_1;
    func_800EFCD8(local_0, param_2, param_3);
    local_0[1] = param_4;
    badust_entrypoint_2(param_0, local_1, local_0, 0.1f, 0.8f, 0.7f);
}

void badust_entrypoint_7(PlayerState *param_0)
{
    f32 local_2[3];
    f32 local_0[3];
    f32 local_1[3];
    f32 local_3;
    func_8009C128(param_0, local_0);
    local_0[1] += 20.0f;
    ((u8 *)(*(void **)((u8 *)param_0 + 0x5C)))[8]++;
    if (((u8 *)(*(void **)((u8 *)param_0 + 0x5C)))[8] > 2) ((u8 *)(*(void **)((u8 *)param_0 + 0x5C)))[8] = 0;
    if (((u8 *)(*(void **)((u8 *)param_0 + 0x5C)))[8]) {
        local_3 = func_800136E4(yaw_get(param_0) + func_800DC178(70.0f, 90.0f));
        func_800EFCD8(local_1, local_3, func_800DC0C0() * 15.0f + 20.0f);
        local_1[1] = 0.0f;
    }
    switch (((u8 *)(*(void **)((u8 *)param_0 + 0x5C)))[8]) {
    case 0: break;
    case 1: func_800EF334(local_1, -1.0f); func_800EF04C(local_0, local_1); break;
    case 2: func_800EF04C(local_0, local_1); break;
    }
    func_800EFCD8(local_2, yaw_get(param_0), 40.0f);
    local_2[1] = func_800DC178(50.0f, 90.0f);
    badust_entrypoint_2(param_0, local_0, local_2, func_800DC178(0.4f, 0.5f),
        func_800DC178(0.7f, 0.9f), func_800DC178(0.8f, 1.3f));
}

void badust_entrypoint_8(s32 param_0) {
    f32 local_0;

    for (local_0 = 0.0f; local_0 < 360.0f; local_0 += 45.0f) {
        badust_entrypoint_5(param_0, local_0, 230.0f);
    }
}

void badust_entrypoint_9(PlayerState *param_0)
{
    switch (*(s32 *)(*(u8 **)((u8 *)param_0 + 0x5C) + 4)) {
        case 0:
            badust_entrypoint_4(param_0, func_8009BB18(param_0) - 20.0f, 40.0f);
            break;
        case 1:
            badust_entrypoint_4(param_0, func_8009BB18(param_0) + 20.0f, 40.0f);
            break;
        case 2:
            badust_entrypoint_4(param_0, func_8009BB18(param_0), 30.0f);
            break;
    }
    (*(s32 *)(*(u8 **)((u8 *)param_0 + 0x5C) + 4))++;
    if (*(s32 *)(*(u8 **)((u8 *)param_0 + 0x5C) + 4) >= 3) {
        *(s32 *)(*(u8 **)((u8 *)param_0 + 0x5C) + 4) = 0;
    }
}

void badust_entrypoint_10(PlayerState *param_0, f32 param_1)
{
    f32 local_0;
    for (local_0 = 0.0f; local_0 < 359.0f; local_0 += 60.0f)
        badust_entrypoint_6(param_0, param_1, local_0, 730.0f, 100.0f);
    for (local_0 = 0.0f; local_0 < 359.0f; local_0 += 60.0f)
        badust_entrypoint_6(param_0, param_1, func_800136E4(local_0 + 30.0f), 430.0f, 40.0f);
}

void badust_entrypoint_11(u8 *param_0) {
    (*(s32 *)((s8 *)((*(u8 **)((s8 *)(param_0) + (0x5C)))) + (4))) = 0;
    (*(s8 *)((s8 *)((*(u8 **)((s8 *)(param_0) + (0x5C)))) + (8))) = 0;
    (*(s32 *)((s8 *)((*(u8 **)((s8 *)(param_0) + (0x5C)))) + (0))) = 0;
    badust_entrypoint_12(param_0, 1);
}

void badust_entrypoint_12(param_0, param_1) PlayerState *param_0; s32 param_1;
{
    ((DustPlayer *)param_0)->local_0->local_0 = param_1;
    switch (param_1) {
    case 2:
        func_8009ADF0(param_0, 3, 1);
        ((DustPlayer *)param_0)->local_0->local_1 = 0;
        _batimer_set(param_0, 8, 0.01f);
        break;
    case 3:
        func_8009ADF0(param_0, 3, 1);
        break;
    case 1:
        func_8009ADF0(param_0, 3, 0);
        break;
    }
}

void badust_entrypoint_13(u8 *param_0) {
    s32 local_0;

    local_0 = *(*(s32 **)((s8 *)(param_0) + (0x5C)));
    switch (local_0) {                              
    case 2:
        func_80800010_badust();
        return;
    case 3:
        func_80800008_badust();
        return;
    }
}
