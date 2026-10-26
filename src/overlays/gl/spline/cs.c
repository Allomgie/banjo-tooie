#include "common.h"

typedef struct { u8 pad_0[0x40]; u32 local_0 : 9; u32 local_1 : 9; u32 local_2 : 9; u32 pad_1 : 5; u32 pad_2 : 3; u32 local_3 : 9; u32 pad_3 : 20; } SplineCsBits;
extern void *func_80105494(Actor *);
typedef struct { u32 pad_0 : 8; u32 local_0 : 13; u32 pad_1 : 11; u8 pad_2[8]; f32 local_1; u8 pad_3[0x28]; f32 local_2; f32 local_3; u8 pad_4[4]; u8 local_4 : 1; u8 local_5 : 2; u8 pad_5 : 5; } SplineCameraTransition;
typedef struct { s32 pad_0:21; s32 local_0:10; s32 pad_1:1; u8 pad_2[0x10]; f32 local_1; u8 pad_3[0x18]; f32 local_2; f32 local_3; } SplineCameraDuration;
extern void *func_800D7520(s32);
extern f32 func_800C7AE4(void *, f32, f32);
typedef struct { u32 local_0:8; u32 local_1:13; s32 local_2:10; u32 local_3:1; f32 local_4; f32 local_5; f32 local_6; f32 local_7; f32 local_8; f32 local_9; f32 local_10; f32 local_11; u32 local_12:15; u32 pad_0:1; u32 local_13:1; u32 local_14:1; u32 local_15:1; u32 local_16:4; u32 local_17:3; u32 pad_1:6; u32 local_18:3; u32 pad_2:3; u32 local_19:8; u32 pad_3:2; u32 local_20:9; u32 local_21:1; u32 local_22:6; f32 local_23; } SplineScriptState;
typedef struct { s32 local_0:1; s32 local_1:1; u32 pad_0:14; s16 local_2[3]; void *local_3; } SplineScriptSlot;
typedef struct { u8 local_0[0x80]; u8 local_1[0x80]; void *local_2[0x24]; f32 local_3; u8 pad_0[4]; s32 local_4; s32 *local_5; u8 pad_1[4]; SplineScriptSlot *local_6; } SplineScriptContext;
typedef struct { u8 pad_0[0x77]; u8 pad_1:4; u8 local_0:4; u8 pad_2; u8 pad_3:6; u8 local_1:2; } SplineScriptActorFlags;
extern void anctrl_setDuration(s32, f32);
extern void func_8008B10C(s32, f32);
extern void func_8008B1C8(s32, f32);
extern f32 func_800D7708(s32, f32, s32);
extern void func_8010FD38(s32, f32);
extern Actor *func_80106790(void *);
extern Actor *_subaddiefind_entrypoint_12(s32);
extern s16 *_gccubesearch_entrypoint_17(s32, s32);
extern s32 _gspropctrl_entrypoint_10();
extern void _glsplinecs_entrypoint_0();
extern void _glsplinefuncs_entrypoint_1();

s32 glsplinecs_entrypoint_0(s32 param_0, s32 param_1, s32 param_2){
    func_800D035C(1);
}

void func_8080002C_glsplinecs(s32 param_0, u8 *param_1, s32 param_2)
{
    SplineCsBits *local_0;

    local_0 = func_80105494(param_1);
    local_0->local_1 = (u32)*(f32 *)(param_1 + 0x48);
    local_0->local_0 = (param_2 >> 16) & 0x1FF;
    local_0->local_2 = (u32)*(f32 *)(param_1 + 0x44);
    local_0->local_3 = param_2 & 0x1FF;
    *(f32 *)(param_1 + 0x54) = local_0->local_1;
    *(f32 *)(param_1 + 0x50) = local_0->local_2;
}

void func_80800228_glsplinecs(void *param_0, Actor *param_1, s32 param_2, s32 param_3, s32 *param_4)
{
    SplineCameraTransition *local_0;

    local_0 = (SplineCameraTransition *)func_80105494(param_1);
    local_0->local_5 = param_3;
    if (param_4[0] == 0x10006) {
        local_0->local_2 = local_0->local_1;
        local_0->local_3 = (f32)param_2 / 4000000.0f;
        local_0->local_4 = 0;
    }
    else if (param_4[0] == 0x10005) {
        local_0->local_2 = *(f32 *)((u8 *)param_0 + 0x190);
        local_0->local_3 = *(f32 *)((u8 *)param_0 + 0x190) + param_4[local_0->local_0];
        local_0->local_4 = 1;
    }
}

void func_80800310_glsplinecs(s32 param_0, Actor *param_1, s32 param_2, s32 param_3)
{
    SplineCameraDuration *local_0;
    f32 local_1;
    local_0 = func_80105494(param_1);
    local_0->local_2 = local_0->local_1;
    local_1 = func_800C7AE4(func_800D7520(local_0->local_0), param_2 / 4000000.0f, 1.0f);
    local_0->local_3 = local_1 / (param_3 * 0.25f);
}

s32 func_808003A8_glsplinecs(Actor *this)
{
  s32 local_0;
  s32 new_var;
  local_0 = func_80104248(this);
  if (local_0 == 0)
  {
    local_0 = func_801042B8(this);
    anctrl_reset(local_0);
  }
  new_var = local_0;
  return new_var;
}

void glsplinecs_entrypoint_1(SplineScriptContext *param_0, Actor *param_1)
{
    SplineScriptState *local_0;
    s32 *local_1;
    s32 local_2;

    local_0 = func_80105494(param_1);
    local_2 = (s32)func_800D674C(param_0->local_4);
    local_1 = (s32 *)(param_0->local_5[local_0->local_0 - 1] + local_2);
    if (local_0->local_1 == 0) {
        local_0->local_1 = 1;
    }
    if (local_0->local_11 != 0.0f || local_0->local_16 != 0 ||
        local_0->local_20 != 0 || local_0->local_19 != 0 ||
        local_0->local_23 > 0.0f) {
        return;
    }
    if (local_0->local_5 != 0.0f) {
        if (local_1[0] == 0x10005) {
            local_0->local_4 = param_0->local_3 - local_0->local_5;
        }
        local_0->local_5 = 0;
    }
    while (local_1[local_0->local_1 + 1] != 2 &&
           ((local_1[0] == 0x10005 && local_1[local_0->local_1] <= param_0->local_3 - local_0->local_4) ||
            (local_1[0] == 0x10006 && local_1[local_0->local_1] / 4000000.0f <= local_0->local_6)) &&
           local_0->local_11 == 0.0f && local_0->local_16 == 0 &&
           local_0->local_20 == 0 && local_0->local_19 == 0 &&
           !(local_0->local_23 > 0.0f)) {
        switch (local_1[local_0->local_1 + 1] >> 16) {
        case 9:
            func_800D7754(param_1, local_1[local_0->local_1 + 1] & 0xFFFF);
            break;
        case 7:
            if (!local_0->local_15 && !local_0->local_22 && !local_0->local_17 && local_0->local_13) {
                param_1->unk54 = (f32)(local_1[local_0->local_1 + 1] & 0xFFFF);
            }
            break;
        case 8:
            if (!local_0->local_15 && !local_0->local_22 && !local_0->local_17 && local_0->local_14) {
                param_1->unk50 = (f32)(local_1[local_0->local_1 + 1] & 0xFFFF);
            }
            break;
        case 14:
        {
            s32 local_3;
            local_3 = func_808003A8_glsplinecs(param_1);
            local_0->local_10 = local_1[local_0->local_1 + 2] / 4000000.0f;
            local_0->local_12 = _seqdat_entrypoint_0(local_1[local_0->local_1 + 1] & 0xFFFF, 0);
            anctrl_setIndex(local_3, local_0->local_12);
            anctrl_setDuration(local_3, local_0->local_10);
            func_8008B188(local_3, 1);
            anctrl_start(local_3);
            func_8008B10C(local_3, 0.00001f);
            local_0->local_1++;
            break;
        }
        case 15:
        {
            s32 local_4;
            f32 local_40;
            local_4 = func_808003A8_glsplinecs(param_1);
            local_40 = local_1[local_0->local_1 + 2] / 4000000.0f;
            func_8008B1C8(local_4, local_40);
            local_0->local_1++;
            break;
        }
        case 16:
        {
            s32 local_41;
            local_41 = func_808003A8_glsplinecs(param_1);
            anctrl_setPlaybackType(local_41, 1);
            break;
        }
        case 17:
        {
            s32 local_42;
            local_42 = func_808003A8_glsplinecs(param_1);
            anctrl_setPlaybackType(local_42, 2);
            break;
        }
        case 48:
            param_1->unk64_19 = local_1[local_0->local_1 + 1] & 0xFFFF;
            break;
        case 56:
            func_80105BE0(param_1, local_1[local_0->local_1 + 1] & 0xFFFF);
            break;
        case 54:
            param_1->unk7A_11 = local_1[local_0->local_1 + 1] & 0xFFFF;
            break;
        case 55:
            ((SplineScriptActorFlags *)param_1)->local_0 = local_1[local_0->local_1 + 1] & 0xFFFF;
            break;
        case 53:
        {
            f32 local_5;
            local_5 = 0;
            if (local_1[local_0->local_1 + 1] & 0xFFFF) {
                local_5 = 5.0f;
            }
            func_8010FD38(func_8008FFE8(), local_5);
            break;
        }
        case 52:
            func_800DA544(0);
            break;
        case 18:
            local_0->local_8 = func_800D7708(local_0->local_2, local_0->local_6, local_1[local_0->local_1 + 1] & 0xFFFF);
            break;
        case 21:
        {
            s32 local_6;
            f32 local_7;
            f32 local_8[3];
            s32 local_9;
            s32 local_10;
            _glsplinefuncs_entrypoint_0(local_1[local_0->local_1 + 1] & 0xFFFF, &local_6, &local_7, local_8, local_0->local_2, &local_9, &local_10);
            local_0->local_2 = local_6;
            local_0->local_6 = local_7;
            param_1->position[0] = local_8[0];
            param_1->position[1] = local_8[1];
            param_1->position[2] = local_8[2];
            break;
        }
        case 40:
        {
            int local_11;
            int local_12;
            local_11 = ((local_1[local_0->local_1 + 1] & 0xFFFF) & 0x8000) ? (local_1[local_0->local_1 + 1] & 0xFFFF) | 0xFFFF0000 : (local_1[local_0->local_1 + 1] & 0xFFFF);
            local_12 = local_11 >= 0 ? local_11 : -local_11;
            ((SplineScriptActorFlags *)param_1)->local_1 = local_11 < 0 ? 2 : (local_11 > 0 ? 1 : 0);
            if (local_12) {
                ((f32 *)param_1->actorData)[0] = local_12 * 0.25f;
            } else {
                ((f32 *)param_1->actorData)[0] = 0;
            }
            ((f32 *)param_1->actorData)[1] = 0;
            break;
        }
        case 49:
            _subaddiefade_entrypoint_1(param_1, local_1[local_0->local_1 + 1] & 0xFFFF);
            break;
        case 41:
        {
            func_800C04C8(local_1[local_0->local_1 + 1] & 0xFFFF, ((local_1[local_0->local_1 + 2]) >> 24) & 0x3F, (local_1[local_0->local_1 + 2]) & 0xFFFF, ((local_1[local_0->local_1 + 2]) >> 16) & 0xF, _glsplinecs_entrypoint_0);
            local_0->local_1++;
            break;
        }
        case 27:
        {
            func_800DA3B8(_seqdefine_entrypoint_0((local_1[local_0->local_1 + 1] & 0xFFFF) & 0x3FFF), (local_1[local_0->local_1 + 1] & 0xFFFF) & 0x4000 ? 1 : 0);
            break;
        }
        case 34:
        {
            func_800FFA88((local_1[local_0->local_1 + 1] & 0xFFFF) == 0 ? param_1->unk0 : param_0->local_2[(local_1[local_0->local_1 + 1] & 0xFFFF)]);
            break;
        }
        case 35:
        {
            func_800FFA88((local_1[local_0->local_1 + 1] & 0xFFFF) == 0 ? param_1->unk0 : param_0->local_2[(local_1[local_0->local_1 + 1] & 0xFFFF)]);
            func_800A50B0(2);
            break;
        }
        case 36:
            _chbaddiesetup_entrypoint_3(_glsplinefuncs_entrypoint_1, local_1[local_0->local_1 + 1] & 0xFFFF, local_1[local_0->local_1 + 2], local_0->local_2);
            local_0->local_1++;
            break;
        case 19:
            local_0->local_11 = (local_1[local_0->local_1 + 1] & 0xFFFF) * 0.25f;
            if (local_1[0] == 0x10005) {
                local_0->local_5 = param_0->local_3 - local_0->local_4;
            }
            break;
        case 20:
            local_0->local_16 = (local_1[local_0->local_1 + 1] & 0xFFFF) - 0x69;
            if (local_1[0] == 0x10005) {
                local_0->local_5 = param_0->local_3 - local_0->local_4;
            }
            break;
        case 31:
            local_0->local_23 = (f32)(local_1[local_0->local_1 + 1] & 0xFFFF);
            break;
        case 28:
            local_0->local_20 = (local_1[local_0->local_1 + 1] & 0xFFFF) + 1;
            local_0->local_21 = 0;
            if (local_1[0] == 0x10005) {
                local_0->local_5 = param_0->local_3 - local_0->local_4;
            }
            break;
        case 29:
            local_0->local_20 = (local_1[local_0->local_1 + 1] & 0xFFFF) + 1;
            local_0->local_21 = 1;
            if (local_1[0] == 0x10005) {
                local_0->local_5 = param_0->local_3 - local_0->local_4;
            }
            break;
        case 30:
            func_800DA544(0x644);
            break;
        case 42:
        {
            s32 local_17;
            s32 local_18;
            SplineScriptState *local_19;
            Actor *local_36;
            local_18 = ((local_1[local_0->local_1 + 1] & 0xFFFF) >> 12) & 0x3F;
            local_17 = (local_1[local_0->local_1 + 1] & 0xFFFF) & 0xFFF;
            if (local_18 == 0) {
                local_36 = param_1;
            } else {
                local_36 = func_80106790(param_0->local_2[local_18]);
            }
            local_19 = func_80105494(local_36);
            local_19->local_0 = local_17;
            local_19->local_4 = param_0->local_3;
            local_19->local_1 = 0;
            local_19->local_5 = 0;
            break;
        }
        case 37:
            param_0->local_2[local_1[local_0->local_1 + 1] & 0xFFFF] = param_1->unk0;
            break;
        case 43:
        {
            SplineScriptState *local_21;
            Actor *local_37;
            if ((local_1[local_0->local_1 + 1] & 0xFFFF) == 0) {
                local_37 = param_1;
            } else {
                local_37 = func_80106790(param_0->local_2[(local_1[local_0->local_1 + 1] & 0xFFFF)]);
            }
            local_21 = func_80105494(local_37);
            local_21->local_11 = 1700000.0f;
            if (local_1[0] == 0x10005) {
                local_21->local_5 = param_0->local_3 - local_0->local_4;
            }
            break;
        }
        case 44:
        {
            SplineScriptState *local_23;
            Actor *local_38;
            if ((local_1[local_0->local_1 + 1] & 0xFFFF) == 0) {
                local_38 = param_1;
            } else {
                local_38 = func_80106790(param_0->local_2[(local_1[local_0->local_1 + 1] & 0xFFFF)]);
            }
            local_23 = func_80105494(local_38);
            local_23->local_11 = 0;
            break;
        }
        case 10:
        {
            u32 local_24;
            s32 local_25;
            Actor *local_39;
            SplineScriptState *local_26;
            local_25 = ((local_1[local_0->local_1 + 1] & 0xFFFF) >> 6) & 0x3F;
            local_24 = (local_1[local_0->local_1 + 1] & 0xFFFF) & 0x3F;
            if (local_24 == 0) {
                local_39 = param_1;
            } else {
                local_39 = func_80106790(param_0->local_2[local_24]);
            }
            local_26 = func_80105494(local_39);
            local_26->local_22 = local_25;
            local_26->local_17 = 0;
            local_26->local_15 = 0;
            local_26->local_13 = 0;
            local_26->local_14 = 0;
            break;
        }
        case 47:
            func_80090708(local_1[local_0->local_1 + 1] & 0xFFFF ? 0 : 2);
            break;
        case 11:
        {
            s32 local_27;
            Actor *local_28;
            s16 *local_29;
            s32 local_30;
            local_27 = local_1[local_0->local_1 + 1] & 0xFFFF;
            if (local_27 != 0) {
                local_28 = _subaddiefind_entrypoint_12(local_27);
                local_29 = 0;
                if (local_28 == 0) {
                    local_29 = _gccubesearch_entrypoint_17(local_27, 0);
                }
                local_0->local_22 = 0;
                local_0->local_15 = 0;
                local_0->local_13 = 0;
                local_0->local_14 = 0;
                for (local_30 = 0; local_30 < 7; local_30++) {
                    if (!(param_0->local_6 + local_30)->local_0) {
                        SplineScriptSlot *local_31 = param_0->local_6 + local_30;
                        local_0->local_17 = local_30 + 1;
                        if (local_28 != 0) {
                            local_31->local_0 = 1;
                            local_31->local_1 = 0;
                            local_31->local_3 = local_28->unk0;
                        } else if (local_29 != 0) {
                            local_31->local_0 = 1;
                            local_31->local_1 = 1;
                            _gspropctrl_entrypoint_10(local_29, local_31->local_2);
                        }
                        local_30 = 7;
                    }
                }
            } else {
                param_0->local_6[local_0->local_17 - 1].local_0 = 0;
                local_0->local_17 = 0;
            }
            break;
        }
        case 13:
            if (local_1[local_0->local_1 + 1] & 0xFFFF) {
                param_1->unk64_18 = 1;
            } else {
                param_1->unk64_18 = 0;
            }
            break;
        case 32:
        {
            s32 local_32;
            local_32 = param_0->local_0[local_1[local_0->local_1 + 1] & 0xFFFF];
            if (local_32 != 0) {
                param_0->local_0[local_1[local_0->local_1 + 1] & 0xFFFF] = local_32 - 1;
            }
            local_0->local_19 = (local_1[local_0->local_1 + 1] & 0xFFFF) + 1;
            if (local_1[0] == 0x10005) {
                local_0->local_5 = param_0->local_3 - local_0->local_4;
            }
            break;
        }
        case 33:
        {
            param_0->local_0[(local_1[local_0->local_1 + 1] & 0xFFFF)] = param_0->local_1[(local_1[local_0->local_1 + 1] & 0xFFFF)];
            break;
        }
        case 12:
            local_0->local_18 = local_1[local_0->local_1 + 1] & 0xFFFF;
            break;
        case 45:
            func_800C84A4(func_800D7520(local_0->local_2), local_1[local_0->local_1 + 1] & 0xFFFF ? 1 : 0);
            break;
        case 46:
            func_8009086C(local_1[local_0->local_1 + 1] & 0xFFFF);
            break;
        case 38:
            func_80800228_glsplinecs(param_0, param_1, local_1[local_0->local_1 + 3], 1, local_1);
            func_8080002C_glsplinecs(param_0, param_1, local_1[local_0->local_1 + 2]);
            local_0->local_1 += 2;
            break;
        case 39:
            func_80800228_glsplinecs(param_0, param_1, local_1[local_0->local_1 + 3], 2, local_1);
            func_80800310_glsplinecs((s32)param_0, param_1, local_1[local_0->local_1 + 3], local_1[local_0->local_1 + 2]);
            local_0->local_1 += 2;
            break;
        case 51:
            _chintrotext_entrypoint_1(0x18BC, local_1[local_0->local_1 + 1] & 0xFFFF, 2, 2);
            break;
        }
        local_0->local_1 += 2;
    }
    if (local_1[local_0->local_1 + 1] == 2) {
        local_0->local_0 = 0;
        local_0->local_1 = 0;
        local_0->local_4 = 0;
        local_0->local_5 = 0;
    }
}
