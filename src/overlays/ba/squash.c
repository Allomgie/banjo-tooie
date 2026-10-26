#include "common.h"

typedef struct { u8 local_0; u8 local_1; u8 pad_0[2]; f32 local_2; f32 local_3; } SquashState1559;
extern void func_8009ADF0(void *, s32, s32);
typedef struct { u8 index; u8 pad_0[3]; f32 time; f32 scale; } SquashState30;
extern u8 D_808006B0_basquash[];
extern u8 D_808006C4_basquash[];
extern s32 func_8009D454();
extern f32 func_800F13C4(f32, f32);
extern f32 func_800F0F9C(f32, f32);
extern f32 func_80013970(f32);
extern f32 func_800F10B4(f32, f32, f32, f32, f32);
extern void func_800E0AF0(s32, f32);
extern void func_800E0B8C(s32, s32, f32, f32, f32, f32);
extern f32 func_800F1198(f32, f32, f32, f32, f32);
extern f32 func_800F0E00(f32, f32);
void func_80800008_basquash();
void func_80800140_basquash();
void func_80800260_basquash();

s32 basquash_entrypoint_0() 
{
    return 0xC;
}

void func_80800008_basquash(param_0, param_1) u8 *param_0; s32 param_1;
{
    switch (param_1) {
        case 1:
            ((SquashState1559 *)*(void **)(param_0 + 0x11C))->local_2 = 0.0;
            ((SquashState1559 *)*(void **)(param_0 + 0x11C))->local_3 = 0.0f;
            func_8009ADF0(param_0, 10, 0);
            break;
        case 2:
            ((SquashState1559 *)*(void **)(param_0 + 0x11C))->local_0 = 0;
            ((SquashState1559 *)*(void **)(param_0 + 0x11C))->local_2 = 5.0f;
            ((SquashState1559 *)*(void **)(param_0 + 0x11C))->local_3 = 1.0f;
            func_8009ADF0(param_0, 10, 1);
            break;
        case 3:
            ((SquashState1559 *)*(void **)(param_0 + 0x11C))->local_2 = 1.7f;
            break;
    }
    ((SquashState1559 *)*(void **)(param_0 + 0x11C))->local_1 = param_1;
}

void basquash_entrypoint_1(s32 arg0) 
{
}
void basquash_entrypoint_2(u8 *param_0) {
    (*(s8 *)((s8 *)((*(u8 **)((s8 *)(param_0) + (0x11C)))) + (2))) = 0;
    (*(s8 *)((s8 *)((*(u8 **)((s8 *)(param_0) + (0x11C)))) + (1))) = 0;
    func_80800008_basquash(param_0, 1);
}

void basquash_entrypoint_3(u8 *param_0, s32 param_1) {
    (*(u8 **)(param_0 + 0x11C))[2] = param_1;
    func_80800008_basquash(param_0, 2);
}

void func_80800140_basquash(param_0) u8 *param_0;
{
    s32 pad[2];
    f32 local_0;
    f32 local_1;
    s32 local_2;
    SquashState30 *local_3;
    f32 local_4;
    f32 local_5;
    local_3 = *(SquashState30 **)(param_0 + 0x11C);
    local_2 = (s32)(local_3->time / 0.5666666627f);
    if (local_2 != local_3->index) {
        func_8009D454(param_0,
            (u8)func_8009D454(param_0, 0, D_808006B0_basquash),
            D_808006C4_basquash + local_2 * 12);
        local_3 = *(SquashState30 **)(param_0 + 0x11C);
    }
    local_3->index = local_2;
    local_0 = func_800F13C4((*(SquashState30 **)(param_0 + 0x11C))->time, 0.5666666627f);
    local_5 = func_800F0F9C(local_0, 0.15f);
    local_1 = func_80013970(local_5 * 360.0f);
    local_4 = func_800F10B4(local_0, 0.0f, 0.5666666627f, 0.0f, 0.6f);
    (*(SquashState30 **)(param_0 + 0x11C))->scale = local_1 * local_4 + (f32)local_2 / 3.0f;
}

void func_80800260_basquash(param_0) u8 *param_0;
{
    f32 local_0;
    f32 local_1;
    s32 local_2;
    s32 local_3;
    s32 local_4;
    s32 local_5;

    local_3 = local_4 = local_5 = 0;
    local_2 = func_80092AD8(param_0);
    func_800E0AF0(local_2, 1.0);
    local_0 = func_800F0E00(func_800F1198((*(f32 **)(param_0 + 0x11C))[2],
        0.0f, 1.0f, 1.0, 0.08f), 0.08f);
    local_1 = 1 / local_0;
    switch (func_80092B80(param_0)) {
    case 0x607:
    case 0x608:
    case 0x61F:
        local_3 = 1;
        break;
    case 0x61C:
    case 0x83A:
        local_4 = 1;
        break;
    case 0x60C:
        local_5 = 1;
        break;
    }
    switch ((*(u8 **)(param_0 + 0x11C))[2]) {
    case 1:
        if (local_5) {
            func_800E0B8C(local_2, 0x43, 1.0f, 1.0f, local_0, 1.0f);
        } else if (local_4) {
            func_800E0B8C(local_2, 0x6B, 1.0f, 1.0f, local_0, 1.0f);
        } else if (local_3) {
            func_800E0B8C(local_2, 1, 1.0f, 1.0f, local_0, 1.0f);
            func_800E0B8C(local_2, 0x1C, 1.0f, 1.0f, local_1, 1.0f);
            func_800E0B8C(local_2, 0xE, 1.0f, 1.0f, local_1, 1.0f);
        } else {
            func_800E0B8C(local_2, 1, 1.0f, 1.0f, local_0, 1.0f);
            func_800E0B8C(local_2, 0x1C, 1.0f, 1.0f, local_1, 1.0f);
            func_800E0B8C(local_2, 0xE, 1.0f, 1.0f, local_1, 1.0f);
        }
        break;
    case 2:
        func_800E0B8C(local_2, 3, 1.0f, local_0, 1.0f, 1.0f);
        if (local_3 || local_4) {
            func_800E0B8C(local_2, 0xA, 1.0f, local_1, local_0, 1.0f);
            func_800E0B8C(local_2, 0x18, 1.0f, local_1, local_0, 1.0f);
            func_800E0B8C(local_2, 0xE, 1.0f, local_1, local_0, 1.0f);
            func_800E0B8C(local_2, 0x1C, 1.0f, local_1, local_0, 1.0f);
        }
        break;
    }
}

void basquash_entrypoint_4(u8 *param_0) {
    u8 local_0;

    func_800D9078((*(u8 **)((s8 *)(param_0) + (0x11C))) + 4);
    local_0 = (*(u8 *)((s8 *)((*(u8 **)((s8 *)(param_0) + (0x11C)))) + (1)));
    switch (local_0) {                              
    case 2:
        func_80800260_basquash(param_0);
        if ((*(f32 *)((s8 *)((*(u8 **)((s8 *)(param_0) + (0x11C)))) + (4))) == 0.0f) {
            func_80800008_basquash(param_0, 3);
            return;
        }
    case 1:
        return;
    case 3:
        func_80800140_basquash(param_0);
        func_80800260_basquash(param_0);
        if ((*(f32 *)((s8 *)((*(u8 **)((s8 *)(param_0) + (0x11C)))) + (4))) == 0.0f) {
            func_80800008_basquash(param_0, 1);
        }
        break;
    }
}
