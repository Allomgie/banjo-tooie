#include "common.h"
#include "playerstate.h"

extern void func_8009EA08(f32);
extern void func_800C2FDC();
typedef struct { f32 local_0[3]; u8 local_1; u8 pad_0[3]; f32 local_2; f32 local_3; f32 local_4; u8 local_5; } KazTorpedoState;
typedef struct { u8 pad_0[0xB0]; KazTorpedoState *local_0; } KazTorpedoPlayer;
extern f32 func_8009EA88(PlayerState *);
extern u8 D_80800420_bakaztorpedo[];
typedef struct { f32 local_0; f32 local_1; f32 local_2; u8 local_3; u8 pad_0[3]; f32 local_4; f32 local_5; f32 local_6; u8 local_7; } KazTorpedoUpdateState;
typedef struct { u8 pad_0[0xB0]; KazTorpedoUpdateState *local_0; u8 pad_1[0xD0]; s32 local_1; } KazTorpedoUpdatePlayer;
extern f32 func_800D8FF8(void);
extern f32 func_800F10B4(f32, f32, f32, f32, f32);
extern f32 func_800136E4(f32);
extern f32 func_800F15F8(f32, f32, f32);
extern void func_800F1574(f32 *, f32);
extern void *func_80092AD8(void *);
extern void func_800E0AF0(void *, f32);
extern void func_800E0AFC(void *, s32, f32, f32, f32, f32);
extern void func_800C31DC(s32, f32);

s32 bakaztorpedo_entrypoint_0() 
{
    return 0x20;
}

f32 bakaztorpedo_entrypoint_1(s32 param_0) {
    return *(f32 *)(*(s32 *)(param_0 + 0xB0) + 0x10);
}

void bakaztorpedo_entrypoint_2(u8 *param_0) {
    func_8009EA08(*(f32 *)(*(u8 **)(param_0 + 0xB0) + 0x10));
    func_800C2FDC(*(*(u8 **)(param_0 + 0xB0) + 0x1C));
}

void bakaztorpedo_entrypoint_3(void *param_0)
{
  *(f32 *)(*(s32 *)((char *)param_0 + 0xB0) + 0x10) = 20.0f;
}

void bakaztorpedo_entrypoint_4(PlayerState *param_0)
{
    ((KazTorpedoPlayer *)param_0)->local_0->local_0[0] =
        ((KazTorpedoPlayer *)param_0)->local_0->local_0[1] =
        ((KazTorpedoPlayer *)param_0)->local_0->local_0[2] = 0.0f;
    ((KazTorpedoPlayer *)param_0)->local_0->local_2 = func_8009EA88(param_0);
    ((KazTorpedoPlayer *)param_0)->local_0->local_1 = 1;
    ((KazTorpedoPlayer *)param_0)->local_0->local_3 =
        ((KazTorpedoPlayer *)param_0)->local_0->local_4 = 0.0f;
    ((KazTorpedoPlayer *)param_0)->local_0->local_5 = func_8009D454(param_0, 0, D_80800420_bakaztorpedo);
}

void bakaztorpedo_entrypoint_5(u8 *param_0, f32 param_1, f32 param_2) {
    (*(f32 *)((s8 *)((*(u8 **)((s8 *)(param_0) + (0xB0)))) + (4))) = param_1;
    (*(f32 *)((s8 *)((*(u8 **)((s8 *)(param_0) + (0xB0)))) + (8))) = param_2;
}

void bakaztorpedo_entrypoint_6(void *arg, s32 v)
{
    ((s8 *)(*(void **)((char *)arg + 0xB0)))[12] = v;
}

int bakaztorpedo_entrypoint_7(s32 param_0, f32 param_1)
{
  int new_var2;
  int new_var;
  new_var = param_0 + new_var2;
  new_var2 = 0x50;
  new_var2 = 0xB0;
  *((f32 *) ((*((s32 *) (new_var = param_0 + new_var2))) + (0x18 & 0xFFFFFFFF))) = param_1;
}

void bakaztorpedo_entrypoint_8(KazTorpedoUpdatePlayer *param_0)
{
    f32 local_0;
    f32 local_1;
    f32 local_2;
    void *local_3;
    s32 local_4;
    s32 local_5;
    s32 local_6;
    s32 cnd;
    s32 local_7;
    f32 local_9;
    Vec3f local_10;

    local_1 = func_800D8FF8();
    switch (param_0->local_0->local_3) {
    case 2:
        local_0 = 1.0f;
        break;
    case 3:
        local_0 = 1.0f;
        break;
    case 4:
        local_0 = 3.0f;
        break;
    default:
        local_0 = 0.0f;
        break;
    }
    local_2 = param_0->local_0->local_4;
    local_5 = func_8008E124(param_0);
    local_6 = func_800C954C();
    local_4 = func_800F8004(param_0->local_1);
    cnd = !local_5 && !local_6 && !local_4;
    if (cnd) {
        func_800F1574(&param_0->local_0->local_4, local_1 * local_0);
    }
    if (local_2 > 0.1f && param_0->local_0->local_4 <= 0.1f) {
        func_800FC660(0x19);
    }
    local_7 = param_0->local_0->local_4 > 0.0f ?
        (s32)func_800F10B4(param_0->local_0->local_4, 0, 20.0f, 1.0f, 20.99f) : 0;
    func_800D2498(0xCB, local_7, 0);
    param_0->local_0->local_5 = func_800136E4(param_0->local_0->local_5 + param_0->local_0->local_6 * local_1);
    local_3 = func_80092AD8(param_0);
    func_800E0AF0(local_3, 1.0f);
    func_800E0AFC(local_3, 0x5D, 1.0f, 0, 0, param_0->local_0->local_5);
    if (player_inWater(param_0)) {
        func_8009C128(param_0, local_10.f);
        local_9 = func_800F10B4(param_0->local_0->local_6, 300.0f, 1200.0f, 0.7f, 1.5f);
        func_800C35E8(param_0->local_0->local_7, local_10.f);
        func_800C31DC(param_0->local_0->local_7, local_9);
        func_800C3BDC(param_0->local_0->local_7);
    }
    param_0->local_0->local_0 = func_800F15F8(param_0->local_0->local_0,
        param_0->local_0->local_1, local_1 * 100.0f);
    func_800E0AFC(local_3, 0x6C, 1.0f, param_0->local_0->local_0, 0, 0);
    func_800E0AFC(local_3, 0x6C, 1.0f, 0, param_0->local_0->local_2, 0);
}
