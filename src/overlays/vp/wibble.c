#include "common.h"

#define CODEX_WIBBLE_RECORD
typedef struct { u8 pad0[0xE]; s16 unkE; } WibbleRecord;
extern WibbleRecord D_80800700_vpwibble[];
typedef struct { u8 pad_0[0x24]; f32 local_0; u8 pad_1[4]; f32 local_1; u8 pad_2[4]; s32 local_2; } WibbleState;
typedef struct { u8 pad_0[3]; u8 local_0; u8 pad_1[16]; } WibbleVertex;
typedef struct { u8 pad_0[0x1C]; s32 local_0; } WibbleModel;
extern f32 func_800D8FF8(void);
extern f32 func_800EEF94(f32 *);
extern f32 func_800136D0(f32);
extern f32 func_800137D4(f32);
extern f32 func_80013788(f32);
void func_808000B0_vpwibble();
f32 func_808003F0_vpwibble();

WibbleRecord *func_80800000_vpwibble(s32 param_0)
{
    s32 local_0;

    param_0 -= param_0 % 100;
    for (local_0 = 0; local_0 < 6; local_0++) {
        if (param_0 == D_80800700_vpwibble[local_0].unkE) {
            return &D_80800700_vpwibble[local_0];
        }
    }
    return D_80800700_vpwibble;
}

void func_808000B0_vpwibble(param_0, param_1) u8 *param_0; s32 param_1;
{
    u8 *local_0;
    f32 local_1;
    f32 local_2;
    f32 local_3;
    local_0 = (u8 *)func_80800000_vpwibble(param_1);
    param_1 %= 100;
    *(f32 *)(param_0 + 0x1C) = local_0[13] << 6;
    if (local_0[13]) param_0[0x33] = 1;
    else param_0[0x33] = 0;
    local_2 = *(f32 *)(param_0 + 0x10);
    local_3 = *(f32 *)(param_0 + 4);
    *(s16 *)(param_0 + 0x18) = (s32)((local_2 + local_3) / 2);
    local_1 = *(f32 *)(local_0 + 4);
    if (local_1 < 0.0f) {
        *(s16 *)(param_0 + 0x1A) = (s32)-local_1;
        param_0[0x31] = 2;
    } else if (local_1 > 0.0f) {
        param_0[0x31] = 0;
        *(s16 *)(param_0 + 0x1A) = (s32)local_1;
    } else {
        param_0[0x31] = 1;
        *(s16 *)(param_0 + 0x1A) = (s32)((local_2 - local_3) * 0.5f);
    }
    *(f32 *)(param_0 + 0x20) = (f32)(u32)local_0[12] / *(s16 *)(param_0 + 0x1A);
    param_0[0x30] = 255 - local_0[12];
    if (local_0[12]) param_0[0x32] = 1;
    else param_0[0x32] = 0;
    *(f32 *)(param_0 + 0x24) = 0.0f;
    *(f32 *)(param_0 + 0x28) = 6.2831855f / *(f32 *)local_0;
    local_1 = *(f32 *)(local_0 + 8);
    if (local_1 < 0.0f) *(f32 *)(param_0 + 0x2C) = -local_1;
    else *(f32 *)(param_0 + 0x2C) = param_1 * local_1;
}

u8 *vpwibble_entrypoint_0(u8 *param_0, u8 *param_1)
{
  u32 temp_a0;
  u32 temp_a1;
  u8 *local_1;
  u8 *temp_v0;
  temp_v0 = heap_alloc(((*((s32 *) (((char *) param_0) + 0x14))) * 2) + 0x38);
  temp_a0 = ((u32) param_1) + 0x14;
 do { local_1 = (u8 *) temp_a0; temp_a1 = (((*((s32 *) (((char *) param_0) + 0x14))) * 4) + ((u32) param_1)) + 0x14; *((s32 *) (((char *) temp_v0) + 0x34)) = 0; if (((!temp_v0) && (!temp_v0)) && (!temp_v0)) { } if (temp_a0 < temp_a1) { do { if ((*((u16 *) (((char *) local_1) + 2))) != 0) { *((s16 *) (((char *) (temp_v0 + ((*((s32 *) (((char *) temp_v0) + 0x34))) * 2))) + 0x38)) = (s16) (((s32) (local_1 - ((u8 *) temp_a0))) >> 2); *((s32 *) (((char *) temp_v0) + 0x34)) = (s32) ((*((s32 *) (((char *) temp_v0) + 0x34))) + 1); } local_1 = local_1 + 4; } while (local_1 < ((u8 *) temp_a1)); } func_800EE88C(temp_v0, param_1 + 8); } while (0);
  func_800EE88C(temp_v0 + 0xC, param_1 + 14);
  func_808000B0_vpwibble(temp_v0, *((s32 *) param_1));
  return temp_v0;
}

void vpwibble_entrypoint_1(void* arg0) 
{
    heap_free(arg0);
}
void vpwibble_entrypoint_2(WibbleState *param_0, WibbleModel *param_1)
{
    WibbleVertex *local_0;
    s32 local_1;
    s16 *local_2;
    param_0->local_0 += func_800D8FF8() * param_0->local_1;
    local_0 = (WibbleVertex *)((u8 *)param_1 + param_1->local_0);
    local_2 = (s16 *)(param_0 + 1);
    for (local_1 = 0; local_1 < param_0->local_2;) {
        local_0[local_2[local_1++]].local_0 = 1;
    }
}

f32 func_808003F0_vpwibble(param_0, param_1, param_2) u8 *param_0; s16 *param_1; f32 *param_2;
{
    f32 local_0;
    f32 local_1;
    f32 local_3;
    f32 local_2[3];
    f32 local_4;

    local_2[0] = param_1[0];
    local_2[1] = param_1[1];
    local_2[2] = param_1[2];
    local_0 = func_800EEF94(local_2);
    local_1 = *(s16 *)(param_0 + 0x1A) *
        func_800137D4(func_800136D0((local_0 - *(f32 *)(param_0 + 0x24)) * *(f32 *)(param_0 + 0x28)));
    if (param_0[0x33]) {
        local_3 = *(f32 *)(param_0 + 0x28) * (*(s16 *)(param_0 + 0x1A) * func_80013788(local_1));
        if (local_0 > 0.0001f) {
            local_4 = local_3 / local_0;
            param_2[0] = local_2[0] * local_4;
            param_2[1] = local_2[2] * local_4;
        } else {
            param_2[0] = local_2[0] * local_3;
            param_2[1] = local_2[2] * local_3;
        }
    }
    return local_1;
}

void vpwibble_entrypoint_3(u8 *param_0, s32 param_1, u8 *param_2, s32 param_3)
{
    f32 local_1;
    s32 local_2;
    f32 local_0[2];
    u8 *local_3;
    local_3 = param_2 + param_3 * 16;
    for (; param_2 < local_3; param_2 += 16) {
        local_1 = func_808003F0_vpwibble(param_0, param_2, local_0);
        if (param_0[0x31] == 1) *(s16 *)(param_2 + 2) = (s32)(*(s16 *)(param_0 + 0x18) + local_1);
        else if (param_0[0x31] == 2) *(s16 *)(param_2 + 2) = (s32)(*(s16 *)(param_2 + 2) + local_1);
        if (param_0[0x32]) {
            local_2 = (s32)(local_1 * *(f32 *)(param_0 + 0x20) + (f32)(u32)param_0[0x30]);
            param_2[12] = (param_2[12] * local_2) >> 8;
            param_2[13] = (param_2[13] * local_2) >> 8;
            param_2[14] = (param_2[14] * local_2) >> 8;
        }
        if (param_0[0x33]) {
            *(s16 *)(param_2 + 8) = (s32)(*(s16 *)(param_2 + 8) + *(f32 *)(param_0 + 0x1C) * local_0[0]);
            *(s16 *)(param_2 + 10) = (s32)(*(s16 *)(param_2 + 10) + *(f32 *)(param_0 + 0x1C) * local_0[1]);
        }
    }
}
