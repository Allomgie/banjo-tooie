#include "common.h"
#include "overlays/ba/playerstate.h"

extern s32 D_80800690_baeggcursor[];
extern void func_800E253C(f32);
extern void func_800E257C(s32);
typedef struct { f32 local_0; f32 local_1; } EggCursorCurvePoint;
typedef struct { u8 pad_0[9]; u8 local_0; u8 pad_1[2]; f32 local_1; u8 local_2; u8 pad_2[3]; s32 local_3; f32 local_4; } EggCursorUpdateState;
int baeggcursor_entrypoint_7();

int func_80800000_baeggcursor(s32 param_0)
{
  return D_80800690_baeggcursor[param_0];
}

s32 baeggcursor_entrypoint_0() 
{
    return 0x1C;
}

void baeggcursor_entrypoint_1(PlayerState *param_0)
{
    s32 local_0[2];
    s32 local_1;
    s32 local_2;

    local_1 = func_800A89F8(param_0);
    if (func_800A4C68(param_0) == local_1 && (*(u8 **)((u8 *)param_0 + 0x68))[8] != 0 && (*(u8 **)((u8 *)param_0 + 0x68))[0xA] != 0 && !func_800A9C98()) {
        func_800E253C(*(f32 *)(*(u8 **)((u8 *)param_0 + 0x68) + 0x18));
        func_800E257C(*(s32 *)(*(u8 **)((u8 *)param_0 + 0x68) + 0x14));
        func_800E2434(1);
        func_800E24CC(1);
        local_0[0] = *(f32 *)(*(u8 **)((u8 *)param_0 + 0x68)) * 4.0f;
        local_0[1] = *(f32 *)(*(u8 **)((u8 *)param_0 + 0x68) + 4) * 4.0f;
        local_2 = func_800A7180();
        func_800E30E0(local_2, func_800D674C(0x64E), 0, local_0);
    }
}

s32 baeggcursor_entrypoint_2(s32 param_0)
{
  if (!param_0)
  {
  }
  return ((u8 *) (*((u8 **) (param_0 + 104))))[9];
}

void baeggcursor_entrypoint_3(u8 *param_0, f32 *param_1, f32 *param_2) {
    *param_1 = (*(f32 *)((s8 *)((*(u8 **)((s8 *)(param_0) + (0x68)))) + (0)));
    *param_2 = (*(f32 *)((s8 *)((*(u8 **)((s8 *)(param_0) + (0x68)))) + (4)));
}

void baeggcursor_entrypoint_4(s32 arg0)
{
    baeggcursor_entrypoint_7(arg0,0);
}

void baeggcursor_entrypoint_5(void *param_0)
{
  *(s8 *)(*(s32 *)((char *)param_0 + 0x68) + 0x9) = 0;
  baeggcursor_entrypoint_7(param_0, 1);
}

void baeggcursor_entrypoint_6(Actor *param_0, int param_1) {
    *(*(s8 **)((u8 *)param_0 + 0x68) + 0xA) = param_1;
}































void baeggcursor_entrypoint_10(s32 param_0, f32 param_1, f32 param_2);

int baeggcursor_entrypoint_7(param_0, param_1) u8 *param_0; s32 param_1;
{

    switch ((*(u8 **)(param_0 + 0x68))[9]) {
        case 0:
            (*(u8 **)(param_0 + 0x68))[8] = 0;
            (*(u8 **)(param_0 + 0x68))[0xA] = 1;
            break;
        case 1:
            (*(u8 **)(param_0 + 0x68))[8] = 1;
            *(s32 *)(*(u8 **)(param_0 + 0x68) + 0x14) = 0x78;
            break;
        case 3: *(s32 *)((*(u8 **)(param_0 + 0x68)) + 0x14) = 0x78; break;
    }
    (*(u8 **)(param_0 + 0x68))[9] = param_1;
    switch (param_1) {
        case 0:
        case 1:
            func_8009ADF0(param_0, 8, 0);
            if ((*(u8 **)(param_0 + 0x68))[8]) { (*(u8 **)(param_0 + 0x68))[8] = 0; }
            break;
        case 2:
            func_8009ADF0(param_0, 8, 1);
            *(f32 *)(*(u8 **)(param_0 + 0x68) + 0x18) = 1.0f;
            *(s32 *)(*(u8 **)(param_0 + 0x68) + 0x14) = 0x78;
            break;
        case 3:
            func_8009ADF0(param_0, 8, 1);
            *(f32 *)(*(u8 **)(param_0 + 0x68) + 0xC) = 0.3f;
            baeggcursor_entrypoint_10(param_0, 152.0f, 114.0f);
            *(f32 *)(*(u8 **)(param_0 + 0x68) + 0x18) = 16.0f;
            *(s32 *)(*(u8 **)(param_0 + 0x68) + 0x14) = 0;
            break;
        case 4:
            func_8009ADF0(param_0, 8, 1);
            *(f32 *)(*(u8 **)(param_0 + 0x68) + 0xC) = 0.2f;
            break;
        case 5:
            func_8009ADF0(param_0, 8, 1);
            *(f32 *)(*(u8 **)(param_0 + 0x68) + 0xC) = 0.0f;
            (*(u8 **)(param_0 + 0x68))[0x10] = 0;
            break;
    }
}

void baeggcursor_entrypoint_8(u8 *param_0) {
    u8 local_0;

    local_0 = (*(u8 *)((s8 *)((*(u8 **)((s8 *)(param_0) + (0x68)))) + (9)));
    if ((local_0 != 0) && (local_0 != 1) && (local_0 != 4)) {
        baeggcursor_entrypoint_7(param_0, 5);
    }
}

s32 baeggcursor_entrypoint_9(u8 *param_0) {
    u8 local_0;

    local_0 = (*(u8 *)((s8 *)((*(u8 **)((s8 *)(param_0) + (0x68)))) + (9)));
    if ((local_0 != 0) && (local_0 != 1) && (local_0 != 4)) {
        return 1;
    }
    return 0;
}

void baeggcursor_entrypoint_10(s32 param_0, f32 param_1, f32 param_2) {
    *(f32 *)(*(s32 *)(param_0 + 0x68) + 0x0) = param_1;
    *(f32 *)(*(s32 *)(param_0 + 0x68) + 0x4) = param_2;
}

void baeggcursor_entrypoint_11(u8 *param_0)
{
    extern f32 func_800F10B4(f32, f32, f32, f32, f32);
    extern u8 func_800D9078(f32 *);
    f32 local_3;
    f32 local_4;
    s32 local_2;
    EggCursorCurvePoint *local_1;
    EggCursorUpdateState *local_0;
    local_0 = *(EggCursorUpdateState **)(param_0 + 0x68);
    if (1) {}
    if (1) {}
    switch (local_0->local_0) {
    case 3:
        if (local_0->local_1 < 0.1f) {
            local_3 = func_800F10B4(local_0->local_1, 0.0f, 0.1f, 1.0f, 0.8f);
        } else {
            local_3 = func_800F10B4(local_0->local_1, 0.1f, 0.3f, 0.8f, 16.0f);
        }
        (*(EggCursorUpdateState **)(param_0 + 0x68))->local_4 = local_3;
        (*(EggCursorUpdateState **)(param_0 + 0x68))->local_3 = func_800F10B4(
            (*(EggCursorUpdateState **)(param_0 + 0x68))->local_1, 0.0f, 0.3f, 120.0f, 0.0f);
        if (func_800D9078(&(*(EggCursorUpdateState **)(param_0 + 0x68))->local_1)) {
            baeggcursor_entrypoint_7(param_0, 2);
        }
        break;
    case 4:
        (*(EggCursorUpdateState **)(param_0 + 0x68))->local_4 = func_800F10B4(local_0->local_1, 0.0f, 0.2f, 16.0f, 1.0f);
        (*(EggCursorUpdateState **)(param_0 + 0x68))->local_3 = func_800F10B4(
            (*(EggCursorUpdateState **)(param_0 + 0x68))->local_1, 0.0f, 0.2f, 0, 120.0f);
        if (func_800D9078(&(*(EggCursorUpdateState **)(param_0 + 0x68))->local_1)) {
            baeggcursor_entrypoint_7(param_0, 1);
        }
        break;
    case 5:
        local_4 = local_0->local_1;
        local_1 = func_80800000_baeggcursor(local_0->local_2);
        for (local_2 = 0; local_1[local_2].local_0 <= local_4; local_2++) {
            if (local_1[local_2].local_1 == 0) {
                baeggcursor_entrypoint_7(param_0, 2);
                break;
            }
        }
        (*(EggCursorUpdateState **)(param_0 + 0x68))->local_4 = func_800F10B4(local_4,
            local_1[local_2 - 1].local_0, local_1[local_2].local_0,
            local_1[local_2 - 1].local_1, local_1[local_2].local_1);
        func_800D91B8(&(*(EggCursorUpdateState **)(param_0 + 0x68))->local_1);
        break;
    }
}
