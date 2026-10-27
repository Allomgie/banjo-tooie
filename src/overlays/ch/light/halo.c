#include "common.h"

extern void *D_808006A8_chlighthalo;
extern f32 func_800F10B4(f32, f32, f32, f32, f32);
extern s32 func_800E8918(s32, s32, s32, f32 *);
extern void func_800EFA4C(f32 *, f32, f32, f32);
extern void func_800E2AA4(void *, s32, s32, s32, f32 *, f32 *);
typedef struct Mass46HaloRange { f32 local_0; f32 local_1; } Mass46HaloRange;
extern Mass46HaloRange D_808006A0_chlighthalo;
extern void func_800E8870(s32, f32);
s32 func_80800448_chlighthalo();
extern void func_80105834(), func_80107C2C(), func_80800000_chlighthalo(), func_80800030_chlighthalo(), func_80800630_chlighthalo();

void func_80800000_chlighthalo(param_0) u8 *param_0;
{
  u8 local_0;
  local_0 = *((u8 *) (((char *) param_0) + 0x34));
  if (local_0 != ((*((u8 *) (((char *) param_0) + 0x34))) * 0))
  {
    func_800E8830(local_0 & 0xFF, param_0 + 4);
  }
}

void func_80800030_chlighthalo(param_0) u8 *param_0;
{
  short temp_a1;
  temp_a1 = *((u8 *) (((s8 *) param_0) + 0x34));
  if (temp_a1 != 0)
  {
    func_800E87E0(temp_a1 & 0xFF, temp_a1, param_0);
    *((u8 *) (((s8 *) param_0) + 0x34)) = 0U;
  }
}

void func_80800068_chlighthalo(Actor *param_0, void *param_1)
{
    f32 local_2[2];
    s32 local_0;
    s32 local_1;
    f32 local_3;
    f32 local_4;
    f32 local_5[3];

    local_0 = 0;
    local_1 = func_800E8918(*(u8 *)((u8 *)param_0 + 0x34), func_800A89F8(), 0, local_2);
    switch (local_1) {
    case -1:
        if (param_0->unk64_20) {
            local_3 = 1.0f;
            local_4 = 1.0f;
            if (local_2[0] < param_0->scale * -30.0f || 304.0f + param_0->scale * 30.0f < local_2[0]) {
                local_3 = -1.0f;
            } else if (local_2[0] <= 0.0f && param_0->scale * -30.0f <= local_2[0]) {
                local_3 = func_800F10B4(local_2[0], 0.0f, param_0->scale * -30.0f, 1.0f, 0.0f);
            } else if (304.0f <= local_2[0] && local_2[0] <= 304.0f + param_0->scale * 30.0f) {
                local_3 = func_800F10B4(local_2[0], 304.0f, 304.0f + param_0->scale * 30.0f, 1.0f, 0.0f);
            }
            if (local_2[1] < param_0->scale * -30.0f || 228.0f + param_0->scale * 30.0f < local_2[1]) {
                local_4 = -1.0f;
            } else if (local_2[1] <= 0.0f && param_0->scale * -30.0f <= local_2[1]) {
                local_4 = func_800F10B4(local_2[1], 0.0f, param_0->scale * -30.0f, 1.0f, 0.0f);
            } else if (228.0f <= local_2[1] && local_2[1] <= 228.0f + param_0->scale * 30.0f) {
                local_4 = func_800F10B4(local_2[1], 228.0f, 228.0f + param_0->scale * 30.0f, 1.0f, 0.0f);
            }
            if (local_4 != -1.0f && local_4 != -1.0f) {
                local_0 = (local_3 + local_4) * 0.5f * 255.0f;
                local_1 = 1;
                break;
            }
        }
    case 0:
        local_0 = (u32)param_0->alpha * 0.3f;
        if (local_0 != 0) {
            local_1 = 1;
        }
        break;
    case 1:
        local_0 = 0xFF;
        break;
    }
    param_0->alpha = (param_0->alpha + local_0) >> 1;
    if (local_1 == 1) {
        _subaddiedraw25d_entrypoint_0(param_0);
        func_800EFA4C(local_5, param_0->scale, param_0->scale, param_0->scale);
        func_800E2588(0);
        func_800E24F8(*(u8 *)((u8 *)param_0 + 0x98), *(u8 *)((u8 *)param_0 + 0x99), *(u8 *)((u8 *)param_0 + 0x9A));
        func_800E257C(param_0->alpha);
        func_800E2AA4(param_1, func_800D674C(param_0->unk0->unk14), 0, 0, param_0->position, local_5);
        param_0->unk64_20 = 1;
    } else {
        param_0->unk64_20 = 0;
    }
}

s32 func_80800448_chlighthalo(param_0, param_1, param_2) Actor *param_0; s32 param_1; s32 param_2;
{
    s32 local_0;
    s32 local_1[3];
    Mass46HaloRange local_2;

    if (param_1 == 0x95) {
        switch (param_0->unk74_7) {
        case 50: case 60: local_0 = 0xFFFF2000; break;
        case 51: case 61: local_0 = 0x20FF0000; break;
        case 52: case 62: local_0 = 0xFF202000; break;
        case 53: case 54: case 63: case 64: local_0 = 0x20FFFF00; break;
        case 55: case 65: local_0 = 0xFF802000; break;
        case 56: case 66: local_0 = 0xFF60FF00; break;
        case 57: case 67: local_0 = 0xFFFFFF00; break;
        default: local_0 = 0xFFFFFF00; break;
        }
        local_1[0] = (u32)(local_0 & 0xFF000000) >> 24; local_1[1] = (u32)(local_0 & 0xFF0000) >> 16; local_1[2] = (u32)(local_0 & 0xFF00) >> 8;
        _subaddiefade_entrypoint_11(param_0, local_1);
        if ((s32)param_0->unk74_7 < 60) {
            if (func_800BF8E4() > 0) {
                local_2 = D_808006A0_chlighthalo;
                local_2.local_0 *= param_0->scale;
                local_2.local_1 *= param_0->scale;
                param_0->actorData[3] = func_800C8A98();
                func_800C8FB0(param_0->actorData[3], local_1[0], local_1[1], local_1[2]);
                func_800C8CB8(param_0->actorData[3], param_0->position);
                func_800C8F64(param_0->actorData[3], 5);
                func_800C8D4C(param_0->actorData[3], &local_2);
                func_800C8FE0(param_0->actorData[3], 1);
            }
        }
        *(u8 *)&param_0->actorData[7] = func_800E8714(1);
        func_800E8830(*(u8 *)&param_0->actorData[7], param_0->position);
        param_0->rotation[1] += 50.0f;
        func_800E8870(*(u8 *)&param_0->actorData[7], 50.0f);
        param_0->unk64_20 = 0;
        *((u8 *)param_0 + 0x9B) = 0;
        return 1;
    }
    return 0;
}

void func_80800630_chlighthalo(s32 arg0) 
{
}
int chlighthalo_entrypoint_0()
{
  return &D_808006A8_chlighthalo;
}
