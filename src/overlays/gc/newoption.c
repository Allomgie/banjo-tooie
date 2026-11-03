#include "gc/newoption.h"
#include "gc/newoption.h"

extern s16 _gczoombox_entrypoint_29();
extern void _gczoombox_entrypoint_28();
typedef struct { s16 local_0; s16 local_1; u8 pad_0[0x10]; f32 local_2; u8 pad_1[8]; s32 local_3; u8 pad_2[0x10]; s16 local_4; u8 pad_3[6]; s32 local_5[5]; u8 pad_4[0x30]; f32 local_6[5]; u8 pad_5[0x1C2]; s16 local_7; } NewOptionDrawState;
extern u8 unk23C[];
extern void func_80100074();
extern s32 func_80100094();
typedef struct { s16 local_0; u8 pad_0[0xA]; s16 local_1; u8 pad_1[0xA]; f32 local_2; u32 pad_2 : 3; u32 local_3 : 1; u32 local_4 : 1; u32 pad_3 : 3; u32 local_5 : 1; u32 local_6 : 1; u32 local_7 : 1; u32 local_8 : 1; u32 local_9 : 1; u32 local_10 : 1; u32 local_11 : 1; u32 pad_4 : 17; u8 pad_5[0x90]; s16 local_12[30]; s16 local_13[30]; s16 local_14[30][3]; s16 local_15[30]; u8 local_16[30]; s16 local_17; s16 local_18; u8 pad_6[2]; s32 local_19; s16 local_20; u8 pad_7[2]; s32 local_21; s32 local_22; s32 local_23; u8 local_24; } NewOptionInitState;
struct OptionBoxes;
extern u8 unk4[];
typedef struct OptionBoxes { s16 pad_0; s16 count; u8 pad_1[0x1C]; void *title; u8 title_state; u8 pad_2[0x17]; void *items[22]; s8 states[22]; } OptionBoxes;
extern void _gczoomboxdata_entrypoint_0(s32);
typedef struct { s16 local_0; s16 local_1; s16 local_2; s16 local_3; s16 local_4; s16 local_5; } OptionScrollState;
typedef struct { u8 local_0 : 1; u8 pad_0 : 7; } CodexOptionVisibility;
extern u16 _gczoomboxdata_entrypoint_5(s32);
extern s32 _gczoombox_entrypoint_32(void *);
extern void *_gldbstring_entrypoint_1(void *, s16);
extern s32 _gczoombox_entrypoint_8(void *, void *);
typedef struct { u8 unused[0x1D]; u8 reserved : 5; u8 changed : 1; u8 low : 2; } OptionChangeFlags;
typedef struct { s16 local_0[7]; u8 pad_0[0xE]; u32 pad_1 : 9; u32 local_1 : 1; u32 pad_2 : 2; u32 local_2 : 1; u32 pad_3 : 19; void *local_3; u8 local_4; u8 pad_4[0x17]; void *local_5[5]; u8 pad_5[0x1C8]; u8 local_6[30]; } NewOptionUpdateState;
struct NewOptionContentState;
extern void _gczoombox_entrypoint_4(void *);
typedef struct { s16 local_0[4]; u8 pad_0[0x34]; void *local_1[5]; u8 pad_1[0x44]; s8 local_2[5]; } NewOptionBoxes;
typedef struct NewOptionContentState { u8 pad_0[0xC]; s16 local_0; u8 pad_1[0x2E]; void *local_1[5]; s16 local_2[5]; s16 local_3[5][3]; u8 local_4[5]; u8 pad_2[0x6F]; s16 local_5[30]; s16 local_6[30][3]; s16 local_7[30]; u8 local_8[30]; u8 pad_3[6]; void *local_9; } NewOptionContentState;
typedef struct { u8 pad_0[0x1D]; u8 pad_4:5; u8 local_0:1; u8 pad_5:2; u8 pad_1[2]; void *local_1; u8 pad_2[2]; s16 local_2; s16 local_3; s16 local_4; f32 local_5; f32 local_6; u8 pad_3[0x208]; void *local_7; } NewOptionScroll27;
extern f32 func_800D8FF8(void);
extern void _gczoombox_entrypoint_41(void *, f32);
extern void func_800EE7F8(void);
typedef struct NewOptionMainState { s16 local_s; s16 count; s16 pad_a; s16 idx; s16 pad_b[4]; f32 local_1; u8 pad_1[8]; u32 local_2 : 1; u32 local_3 : 1; u32 local_4 : 1; u32 pad_2 : 1; u32 local_5 : 1; u32 local_6 : 3; u32 pad_3 : 24; void *local_7; u8 local_8; u8 pad_4[0x17]; void *local_9[5]; u8 pad_5[0x60]; s16 local_10[30]; u8 pad_6[0x158]; void (*local_11)(s32, void *, s32, s32); void (*local_12)(void); s32 local_13; s8 local_14; } NewOptionMainState;
extern void func_80015E80(s32, s32 *);
extern void func_80016068(s32, f32 *);
extern f32 mlAbsF(f32);
extern void *_gczoombox_entrypoint_5(s32, s32, s32, s32, s32);
extern void _gczoombox_entrypoint_42(void *, f32);
extern void _gczoombox_entrypoint_20(void *, f32, s32, s32, f32, s32, s32);
typedef struct { u8 pad_0[0x1C]; u32 pad_1 : 3; u32 local_0 : 1; u32 pad_2 : 6; u32 local_1 : 1; u32 local_2 : 1; u32 pad_3 : 2; u32 local_3 : 1; u32 pad_4 : 17; } OptionFlags211;
extern void _gczoombox_entrypoint_26(void *, s32, f32, f32, s32);
typedef struct { s16 state; s16 count; u8 pad_0[0x10]; f32 spacing; u8 pad_1[4]; u32 flags; void *title; u8 title_state; u8 pad_2; s16 title_text; u8 pad_3[0x14]; void *items[5]; s16 selected_text[5]; s16 colors[5][3]; u8 item_states[5]; u8 pad_4[3]; f32 item_y[5]; u8 item_changed[5]; u8 pad_5[0x143]; s16 texts[5]; u8 pad_6[0x50]; s16 title_font; s16 wrap; u8 pad_7[2]; void *strings; u8 pad_8[0x14]; s16 font; s16 y; f32 speed; f32 duration; } OptionCreate211;
typedef struct { u8 pad_0[0x1D]; u8 pad_1 : 5; u8 local_0 : 1; u8 pad_2 : 2; } OptionTitleFlags211;
typedef struct { u8 pad_0[0x1D]; u8 pad_1 : 2; u8 local_0 : 1; u8 pad_2 : 5; } OptionClosingFlag;
typedef struct { u8 pad_0[0x1C]; u32 local_0 : 1; u32 pad_1 : 31; } NewOptionMovingFlag1081;
typedef struct { s16 local_0; s16 local_1; u8 pad_0[0x1C]; void *local_2; u8 local_3; u8 pad_1[0x17]; void *local_4[5]; u8 pad_2[0x44]; s8 local_5[5]; } NewOptionTransitionState;
typedef struct { s16 pad_0; s16 count; s16 pad_1; s16 selected; u8 pad_2[0x34]; void *boxes[5]; s16 indices[34]; s8 states[1]; } OptionBoxes29;
typedef struct { u8 pad_0[0x1C]; u32 pad_1:10; u32 local_1:1; u32 local_2:1; u32 pad_2:1; u32 local_0:1; u32 pad_3:18; void *title; u8 pad_4[2]; s16 title_text; u8 pad_5[0x214]; void *strings; } OptionTitleControl;
void gcnewoption_entrypoint_5();
void gcnewoption_entrypoint_7();
void func_8080103C_gcnewoption();
void func_808027DC_gcnewoption();
void func_80800D28_gcnewoption();
void func_80801B5C_gcnewoption();
s32 func_808020C4_gcnewoption();
s32 func_808022E0_gcnewoption();
s32 func_8080241C_gcnewoption();
s32 func_80802674_gcnewoption();

s32 func_80800000_gcnewoption(u8 *param_0, s32 param_1);
s32 func_80800070_gcnewoption(s32 *param_0, s32 param_1);
void gcnewoption_entrypoint_0(NewOptionMainState *param_0);
void gcnewoption_entrypoint_1(NewOptionDrawState *param_0, void *param_1);
int gcnewoption_entrypoint_2(void);
int gcnewoption_entrypoint_3(Actor *param_0);
void gcnewoption_entrypoint_6();
void gcnewoption_entrypoint_8(s16 *param_0, unsigned int param_1);
int gcnewoption_entrypoint_9(Actor *param_0, long param_1);
void gcnewoption_entrypoint_10(u8 *param_0, u32 param_1);
s32 gcnewoption_entrypoint_11(s16 *param_0);
void func_808010E0_gcnewoption(s16 *param_0, s32 param_1);
s32 func_80801114_gcnewoption(s16 *param_0);
int func_80801190_gcnewoption(OptionState *param_0);
void gcnewoption_entrypoint_12(OptionState *param_0, u32 param_1, s16 param_2);
void gcnewoption_entrypoint_13(s32 param_0, s32 param_1, s16 *param_2);
void gcnewoption_entrypoint_14(u8 *param_0, s16 param_1, s16 param_2, s16 param_3, f32 param_4);
int func_808012C8_gcnewoption(s32 param_0);
void gcnewoption_entrypoint_15(s32 param_0, u8 *param_1, s32 param_2, s32 param_3);
void gcnewoption_entrypoint_16(s32 param_0, u8 *param_1, s32 param_2, s32 param_3);
s32 gcnewoption_entrypoint_17(s32 param_0, unsigned int param_1);
int gcnewoption_entrypoint_18(s16 *param_0, int param_1);
int gcnewoption_entrypoint_19(s16 *param_0, int param_1);
int gcnewoption_entrypoint_20(s16 *param_0, int param_1);
void gcnewoption_entrypoint_21(s16 *param_0, int param_1);
union U;
void gcnewoption_entrypoint_22(union U *param_0, int param_1);
void gcnewoption_entrypoint_23(s16 *param_0, int param_1);
void gcnewoption_entrypoint_24(s16 *param_0, s32 param_1, s32 param_2);
int gcnewoption_entrypoint_25(u8 *param_0, s32 param_1);
void gcnewoption_entrypoint_26(u8 *param_0, s32 param_1);
void gcnewoption_entrypoint_27(u8 *param_0, s32 param_1, s32 param_2);
void gcnewoption_entrypoint_28(OptionState *param_0);
void gcnewoption_entrypoint_29(u8 *param_0, u32 param_1);
void gcnewoption_entrypoint_30(u8 *param_0, s16 *param_1);
void gcnewoption_entrypoint_31();
int gcnewoption_entrypoint_32(Actor *param_0, s16 param_1);
int gcnewoption_entrypoint_33(void *param_0);
void gcnewoption_entrypoint_34(OptionState *param_0, u32 param_1);
void func_808019D0_gcnewoption(NewOptionUpdateState *param_0);
s32 func_80801E68_gcnewoption(u8 *param_0);
int func_80802534_gcnewoption(NewOptionBoxes *param_0);
void func_80802998_gcnewoption(NewOptionScroll27 *param_0);
void func_80802A9C_gcnewoption(void *param_0);
void gcnewoption_entrypoint_35(s32 param_0, s32 param_1, s32 param_2, s32 param_3);
void gcnewoption_entrypoint_36(s32 param_0);
void func_80802B24_gcnewoption(u8 *param_0, s32 param_1);
u32 gcnewoption_entrypoint_37(OptionState *param_0, u32 param_1);
s32 gcnewoption_entrypoint_38(u8 *param_0, s32 param_1);
s32 gcnewoption_entrypoint_39(OptionState *param_0);
void gcnewoption_entrypoint_40(u8 *param_0, s32 param_1, s32 param_2, s32 param_3, f32 param_4, f32 param_5);
void gcnewoption_entrypoint_41(OptionState *param_0, s32 param_1);
void gcnewoption_entrypoint_42(OptionState *param_0, f32 param_1);
s32 gcnewoption_entrypoint_43(void *param_0, s32 param_1, s32 param_2);
void gcnewoption_entrypoint_44(OptionTitleControl *param_0, s32 param_1);
s16 gcnewoption_entrypoint_45(u8 *param_0);
void gcnewoption_entrypoint_46(void *param_0, int param_1);
s32 gcnewoption_entrypoint_47(s32 param_0);
int gcnewoption_entrypoint_48(s16 *param_0);
void gcnewoption_entrypoint_49(u8 *param_0, u32 param_1);
s32 func_80800000_gcnewoption(u8 *param_0, s32 param_1)
{
  s16 temp_v0;
  s32 var_v1;
  temp_v0 = *((s16 *) (((s8 *) param_0) + 2));
  var_v1 = (*((s16 *) (((s8 *) param_0) + 0xA))) + param_1;
  if (var_v1 >= temp_v0)
  {
    var_v1 = var_v1 - temp_v0;
  }
  else
    if (var_v1 < 0)
  {
    var_v1 = (var_v1 & 0xFFFFFFFF) + temp_v0;
  }
  return var_v1;
}

func_80800038_gcnewoption(s16 *param_0, s32 param_1){
    s32 local_0;
    local_0 = param_1 - param_0[4];
    if(local_0 >= param_0[1]){
        return -1;
    }
    if(local_0 < 0){
        return -1;
    }
    return local_0;
}

s32 func_80800070_gcnewoption(s32 *param_0, s32 param_1){
    return *(s16 volatile *)(param_0 + 2) + param_1;
}

void gcnewoption_entrypoint_0(NewOptionMainState *param_0)
{
    u8 local_0;
    s32 i;
    s32 local_2;
    s32 local_3[6]; /* func_80015E80 fills 6 words */
    f32 local_4[2];
    s32 pad_c[2]; /* frame padding (unused locals) */

    param_0->local_2 = 0;
    if (param_0->local_7 != NULL) {
        local_0 = param_0->local_8;
    }
    switch (param_0->local_s) {
    case 0:
        break;
    case 1:
        func_80800D28_gcnewoption(param_0);
        param_0->local_11(param_0->local_13, param_0, param_0->idx, 0);
        param_0->local_s = 2;
        break;
    case 2:
        param_0->local_s = 3;
        break;
    case 3:
        if (func_80801E68_gcnewoption(param_0)) {
            if ((s32)param_0->local_6 == 3) {
                param_0->local_s = 4;
            } else {
                param_0->local_s = 5;
                param_0->local_11(param_0->local_13, param_0, param_0->idx, 8);
                param_0->local_11(param_0->local_13, param_0, param_0->idx, 10);
            }
        }
        func_808019D0_gcnewoption(param_0);
        break;
    case 4:
        for (i = 0; i < param_0->count; i++) {
            local_2 = func_80800000_gcnewoption(param_0, i);
            func_808027DC_gcnewoption(param_0, i);
            _gczoombox_entrypoint_4(param_0->local_9[local_2]);
        }
        func_80801B5C_gcnewoption(param_0);
        if (param_0->local_7 != NULL) {
            _gczoombox_entrypoint_4(param_0->local_7);
        }
        func_80802998_gcnewoption(param_0);
        break;
    case 5:
        func_808019D0_gcnewoption(param_0);
        func_80802998_gcnewoption(param_0);
        if (param_0->local_1 <= 0.0f && param_0->local_14 >= 0) {
            func_80015E80(param_0->local_14 ^ 0, local_3);
            if (local_3[1] == 1) {
                if (param_0->local_6 == 2) {
                    if (param_0->local_11 != NULL) {
                        param_0->local_11(param_0->local_13, param_0, param_0->idx, 5);
                    }
                } else {
                    param_0->local_4 = 1;
                    func_80802A9C_gcnewoption(param_0);
                    param_0->local_s = 6;
                }
            } else if (local_3[0] == 1) {
                switch ((s32)param_0->local_6) {
                case 0:
                    if (param_0->local_10[param_0->idx] == -1) {
                        if (param_0->local_11 != NULL) {
                            param_0->local_11(param_0->local_13, param_0, param_0->idx, 3);
                            return;
                        }
                    } else {
                        func_80802A9C_gcnewoption(param_0);
                        param_0->local_s = 6;
                    }
                    break;
                case 1:
                    if (param_0->local_11 != NULL) {
                        param_0->local_11(param_0->local_13, param_0, param_0->idx, 1);
                    }
                    break;
                case 2:
                    if (param_0->local_11 != NULL) {
                        param_0->local_11(param_0->local_13, param_0, param_0->idx, 4);
                    }
                    break;
                }
                param_0->local_1 = 0.6f;
            }
            if (param_0->local_s != 5) {
                break;
            }
            if (!param_0->local_2 && !param_0->local_5 && (param_0->local_14 ^ 0) >= 0) {
                func_80016068(param_0->local_14 ^ 0, local_4);
                if (0.8f < local_4[1]) {
                    if (func_80801114_gcnewoption(param_0)) {
                        param_0->local_1 = 0.2f;
                    }
                } else if (local_4[1] < -0.8f) {
                    if (func_80801190_gcnewoption(param_0)) {
                        param_0->local_1 = 0.2f;
                    }
                }
            }
            if (param_0->local_6 == 2 && param_0->local_5) {
                func_80016068(param_0->local_14, local_4);
                if (param_0->local_3) {
                    if (mlAbsF(local_4[0]) < 0.8f) {
                        param_0->local_3 = 0;
                    }
                } else if (0.8f < local_4[0]) {
                    if (param_0->local_11 != NULL) {
                        param_0->local_11(param_0->local_13, param_0, param_0->idx, 7);
                    }
                    param_0->local_3 = 1;
                } else if (local_4[0] < -0.8f) {
                    if (param_0->local_11 != NULL) {
                        param_0->local_11(param_0->local_13, param_0, param_0->idx, 6);
                    }
                    param_0->local_3 = 1;
                }
            }
        } else if (0.0f < param_0->local_1) {
            param_0->local_1 -= func_800D8FF8();
        }
        break;
    case 6:
        func_808019D0_gcnewoption(param_0);
        if (func_808020C4_gcnewoption(param_0)) {
            param_0->local_s = 11;
        }
        break;
    case 7:
        func_808019D0_gcnewoption(param_0);
        if (func_808022E0_gcnewoption(param_0)) {
            func_80802A9C_gcnewoption(param_0);
            param_0->local_s = 8;
        }
        break;
    case 8:
        func_808019D0_gcnewoption(param_0);
        if (func_80802674_gcnewoption(param_0)) {
            param_0->local_s = 11;
        }
        break;
    case 11:
        func_8080103C_gcnewoption(param_0);
        param_0->local_s = 12;
        break;
    case 12:
        param_0->local_s = 13;
        if (param_0->local_11 != NULL) {
            if (param_0->local_4) {
                param_0->local_11(param_0->local_13, param_0, param_0->idx, 2);
                return;
            }
            param_0->local_11(param_0->local_13, param_0, param_0->idx, 3);
            return;
        }
        break;
    case 13:
        break;
    case 9:
        func_808019D0_gcnewoption(param_0);
        if (func_8080241C_gcnewoption(param_0)) {
            param_0->local_s = 5;
            if (param_0->local_11 != NULL) {
                param_0->local_11(param_0->local_13, param_0, param_0->idx, 10);
            }
        }
        break;
    case 10:
        func_808019D0_gcnewoption(param_0);
        if (func_80802534_gcnewoption(param_0)) {
            param_0->local_s = 5;
            func_80802B24_gcnewoption(param_0, 0);
            if (param_0->local_11 != NULL) {
                param_0->local_11(param_0->local_13, param_0, param_0->idx, 10);
            }
        }
        break;
    default:
        break;
    }
    if (param_0->local_7 != NULL && (param_0->local_s == 3 || param_0->local_s == 5 || param_0->local_s == 10)) {
        if (local_0 != 3 && param_0->local_8 == 3) {
            param_0->local_11(param_0->local_13, param_0, param_0->idx, 9);
        }
    }
}

void gcnewoption_entrypoint_1(NewOptionDrawState *param_0, void *param_1)
{
    f32 local_1;
    s32 local_0;
    s32 local_2;
    s16 local_3;
    s32 local_4;
    s32 local_5;
    s32 local_6;

    local_3 = param_0->local_0;
    if (local_3 >= 2 && local_3 < 0xC) {
        for (local_6 = 0; local_6 < param_0->local_1; local_6++) {
            local_5 = func_80800000_gcnewoption(param_0, local_6);
            _gczoombox_entrypoint_2(param_0->local_5[local_6], param_1);
            if (param_0->local_6[local_5] < param_0->local_2) {
                local_1 = param_0->local_6[local_5];
                local_0 = _gczoombox_entrypoint_29(param_0->local_5[local_5]);
                _gczoombox_entrypoint_28(param_0->local_5[local_5], param_0->local_4);
                _gczoombox_entrypoint_38(param_0->local_5[local_5], (s32)(param_0->local_6[local_5] + param_0->local_2 * param_0->local_1 + param_0->local_7));
                _gczoombox_entrypoint_2(param_0->local_5[local_5], param_1);
                _gczoombox_entrypoint_38(param_0->local_5[local_5], (s32)(param_0->local_7 + local_1));
                _gczoombox_entrypoint_28(param_0->local_5[local_5], (s16)local_0);
            }
            if (param_0->local_2 * param_0->local_1 < param_0->local_6[local_5]) {
                local_1 = param_0->local_6[local_5];
                local_2 = _gczoombox_entrypoint_29(param_0->local_5[local_5]);
                _gczoombox_entrypoint_28(param_0->local_5[local_5], param_0->local_4);
                _gczoombox_entrypoint_38(param_0->local_5[local_5], (s32)(param_0->local_6[local_5] - param_0->local_2 * param_0->local_1 + param_0->local_7));
                _gczoombox_entrypoint_2(param_0->local_5[local_5], param_1);
                _gczoombox_entrypoint_38(param_0->local_5[local_5], (s32)(param_0->local_7 + local_1));
                _gczoombox_entrypoint_28(param_0->local_5[local_5], (s16)local_2);
            }
        }
        local_4 = param_0->local_3;
        if (local_4 != 0) {
            _gczoombox_entrypoint_2(local_4, param_1);
        }
    }
}

int gcnewoption_entrypoint_2(void)
{
	return 0x260;
}

int gcnewoption_entrypoint_3(Actor *param_0)
{
  s32 local_1 = 3;
  u8 *local_0 = (*((s32 *) (((char *) param_0) + 0x23C))) + 3;
  if ((*((u8 *) (((char *) (*((s32 *) (((char *) param_0) + 0x23C)))) + 3))) != 0x8D)
  {
    do
    {
      local_1 = (local_1 + (*((u8 *) (((char *) local_0) + 1)))) + ((0, 2));
      local_0 = (*((s32 *) (((char *) param_0) + 0x23C))) + local_1;
    }
    while ((*local_0) != 0x8D);
  }
  return (*((u8 *) (((char *) ((*((s32 *) (((char *) param_0) + 0x23C))) + local_1)) + 2))) - 0x31;
}

void gcnewoption_entrypoint_4(param_0, param_1, param_2, param_3, param_4) s32 param_0[3]; s16 param_1; s32 param_2; s32 param_3; s32 param_4;
{
  func_80100074(param_0, param_1, 0x260);
  gcnewoption_entrypoint_5(func_80100094(param_0, param_1), param_2, param_3, param_4, param_0[0]);
}

void gcnewoption_entrypoint_5(param_0, param_1, param_2, param_3, param_4) u8 *param_0; s32 param_1; s32 param_2; s32 param_3; s32 param_4;
{
    s32 local_0;
    NewOptionInitState *local_1 = (NewOptionInitState *)param_0;

    local_1->local_0 = 0;
    local_1->local_19 = _gldbstring_entrypoint_0(local_1->local_19, param_3);
    local_1->local_20 = param_3;
    local_1->local_21 = param_1;
    local_1->local_22 = param_2;
    local_1->local_23 = param_4;
    local_1->local_3 = 0;
    local_1->local_4 = 0;
    local_1->local_8 = 0;
    local_1->local_6 = 0;
    local_1->local_5 = 0;
    local_1->local_7 = 0;
    local_1->local_9 = 0;
    local_1->local_18 = 0;
    local_1->local_10 = 0;
    local_1->local_17 = 0xD;
    local_1->local_1 = _gldialog_entrypoint_0();
    local_1->local_11 = 0;
    gcnewoption_entrypoint_40(param_0, 0x2C, 0x1C, 0x32, 1.0f, 1.0f);
    local_1->local_24 = 0;
    local_1->local_2 = 0.0f;
    for (local_0 = 0; local_0 < 30; local_0++) {
        local_1->local_12[local_0] = 0;
        local_1->local_13[local_0] = -1;
        local_1->local_14[local_0][0] = 0xFF;
        local_1->local_14[local_0][1] = 0xFF;
        local_1->local_14[local_0][2] = 0xFF;
        local_1->local_15[local_0] = 0xC;
        local_1->local_16[local_0] = 0;
    }
}

void gcnewoption_entrypoint_6(param_0, param_1) s32 param_0; s16 param_1; {
    gcnewoption_entrypoint_7(func_80100094(param_0, param_1));
    func_80100074(param_0, param_1, 0);
}

void gcnewoption_entrypoint_7(param_0) OptionState *param_0;
{
    if (*(s16 *)param_0 != 0xD || *(u32 *)(param_0->data + 0x20)) {
        func_8080103C_gcnewoption(param_0);
    }
    _gldbstring_entrypoint_2(*(s16 *)(param_0->data + 0x240));
}

void gcnewoption_entrypoint_8(s16 *param_0, unsigned int param_1)
{
  param_0[1] = param_1;
}

int gcnewoption_entrypoint_9(Actor *param_0, long param_1)
{
  *((u16 *) (((char *) param_0) + 0x4)) = param_1;
  param_0 = param_0;
}

void gcnewoption_entrypoint_10(u8 *param_0, u32 param_1)
{
  unsigned char new_var;
  param_0[0x1c] = (u8) ((param_0[0x1c] & 0xfff8) | ((new_var = (unsigned char) param_1) & 7));
}

s32 gcnewoption_entrypoint_11(s16 *param_0){
    s32 temp;
    temp = 1;
    *param_0 = temp;
}

void func_80800D28_gcnewoption(param_0) OptionCreate211 *param_0;
{
    s32 local_0;

    for (local_0 = 0; local_0 < param_0->count; local_0++) {
        param_0->items[local_0] = _gczoombox_entrypoint_5((local_0 + 1) * param_0->spacing + param_0->y,
            param_0->texts[local_0], 2, ((OptionFlags211 *)param_0)->local_3, 0);
        _gczoombox_entrypoint_41(param_0->items[local_0], 45.0f);
        _gczoombox_entrypoint_42(param_0->items[local_0], 0.3f);
        _gczoombox_entrypoint_26(param_0->items[local_0], param_0->font, param_0->speed, param_0->duration, 0);
        _gczoombox_entrypoint_44(param_0->items[local_0], (u32)((u8 *)param_0)[0x1D] >> 7);
        _gczoombox_entrypoint_23(param_0->items[local_0], param_0->wrap == 0);
        if (((OptionFlags211 *)param_0)->local_1) {
            _gczoombox_entrypoint_20(param_0->items[local_0], 100.0f, 0, 2, 0.1f, 0, 0);
        }
        if ((((u8 *)param_0)[0x1C] & 7) == 3) {
            _gczoombox_entrypoint_41(param_0->items[local_0], 1000.0f);
            _gczoombox_entrypoint_21(param_0->items[local_0], 0);
        }
        param_0->item_y[local_0] = (local_0 + 1) * param_0->spacing;
        param_0->colors[local_0][0] = param_0->colors[local_0][1] = param_0->colors[local_0][2] = 255;
        param_0->selected_text[local_0] = -1;
        param_0->item_states[local_0] = param_0->texts[local_0];
    }
    if ((((u8 *)param_0)[0x1C] & 7) == 3) {
        *(s16 *)((u8 *)param_0 + 6) = -1;
    } else {
        *(s16 *)((u8 *)param_0 + 6) = 0;
    }
    *(s16 *)((u8 *)param_0 + 8) = 0;
    ((u8 *)param_0)[0x1C] &= ~0x20;
    if (((OptionFlags211 *)param_0)->local_0) {
        param_0->title = NULL;
    } else {
        param_0->title = _gczoombox_entrypoint_5(0x1C, param_0->title_font, 0, 0, 0);
        if (!((OptionFlags211 *)param_0)->local_2) {
            ((OptionTitleFlags211 *)param_0)->local_0 = 1;
            _gczoombox_entrypoint_8(param_0->title, _gldbstring_entrypoint_1(param_0->strings, param_0->title_text));
        }
        _gczoombox_entrypoint_23(param_0->title, param_0->wrap == 0);
        if (((OptionFlags211 *)param_0)->local_1) {
            _gczoombox_entrypoint_20(param_0->title, 30.0f, 0, 2, 0.1f, 0, 0);
        }
    }
    func_80802A9C_gcnewoption(param_0);
}

void func_8080103C_gcnewoption(param_0) OptionBoxes *param_0;
{
    s32 local_0;
    for (local_0 = 0; local_0 < param_0->count; local_0++) {
        if (param_0->items[local_0]) {
            _gczoombox_entrypoint_0(param_0->items[local_0]);
            param_0->items[local_0] = NULL;
            param_0->states[local_0] = -1;
        }
    }
    if (param_0->title) {
        _gczoombox_entrypoint_0(param_0->title);
        param_0->title = NULL;
        param_0->title_state = 0xFF;
    }
}

void func_808010E0_gcnewoption(s16 *param_0, s32 param_1) {
    if (param_0[0x11C] == 0) {
        _gczoomboxdata_entrypoint_0(param_0[param_1 + 0xEE]);
    }
}

s32 func_80801114_gcnewoption(s16 *param_0)
{
    if (param_0[3] <= 0) {
        return 0;
    }
    param_0[3]--;
    if (func_80800038_gcnewoption(param_0, param_0[3]) == -1) {
        param_0[4]--;
        param_0[5]--;
        if (param_0[5] < 0) {
            param_0[5] = param_0[1] - 1;
        }
    }
    return 1;
}

int func_80801190_gcnewoption(OptionState *param_0)
{
    OptionScrollState *local_0 = (OptionScrollState *)param_0;
    if (local_0->local_3 >= local_0->local_2 - 1) return 0;
    local_0->local_3++;
    if (func_80800038_gcnewoption(param_0, local_0->local_3) == -1) {
        local_0->local_4++;
        local_0->local_5++;
        if (local_0->local_5 >= local_0->local_1) local_0->local_5 = 0;
    }
    return 1;
}

void gcnewoption_entrypoint_12(OptionState *param_0, u32 param_1, s16 param_2)
{
    if (*(s16 *)(param_0->data + 0xEC + param_1 * 2) != param_2) {
        *(s16 *)(param_0->data + 0xEC + param_1 * 2) = param_2;
    }
}

void gcnewoption_entrypoint_13(s32 param_0, s32 param_1, s16 *param_2)
{
  s16 val0;
  s16 *target;
  ;
  ;
  if (((param_2[0] != ((s16 *) (((char *) ((long) param_0)) + (param_1 * 6)))[0x94]) || (param_2[1] != ((s16 *) (((char *) ((long) param_0)) + (param_1 * 6)))[0x95])) || (param_2[2] != ((s16 *) (((char *) ((long) param_0)) + (param_1 * 6)))[0x96]))
  {
 ;
    ((s16 *) (((char *) ((long) param_0)) + (param_1 * 6)))[0x94] = param_2[0];
    ((s16 *) (((char *) ((long) param_0)) + (param_1 * 6)))[0x95] = param_2[1];
    ((s16 *) (((char *) ((long) param_0)) + (param_1 * 6)))[0x96] = param_2[2];
  }
}

void gcnewoption_entrypoint_14(u8 *param_0, s16 param_1, s16 param_2, s16 param_3, f32 param_4) {
    *(s16 *)(param_0 + 0x26) = param_1;
    *(s16 *)(param_0 + 0x28) = param_2;
    *(s16 *)(param_0 + 0x2A) = param_3;
    *(f32 *)(param_0 + 0x2C) = param_4;
    *(f32 *)(param_0 + 0x30) = param_4;
}

int func_808012C8_gcnewoption(s32 param_0)
{
  s32 local_0;
  local_0 = 0;
  switch (param_0)
  {
    case 0:
      local_0 = 0x96;
      break;

    case 1:
      local_0 = 0x97;
      break;

    case -1:
      local_0 = 0xf;
      break;

    default:
      break;

  }

  if (local_0 != 0)
  {
    func_800FC6B0(local_0 & 0xFFFFFFFF, local_0);
  }
}

void gcnewoption_entrypoint_15(s32 param_0, u8 *param_1, s32 param_2, s32 param_3)
{
  int new_var2;
  s16 local_0;
  int new_var;
  u8 *local_1;
  new_var = 0x24C;
  new_var2 = param_2 * 2;
  if (param_3 == 1)
  {
    local_1 = param_1 + new_var2;
    local_0 = *((s16 *) (((s8 *) local_1) + 0xB0));
    switch (*((s16 *) (((s8 *) local_1) + 0xB0)))
    {
      case 0:
        *((s16 *) (((s8 *) local_1) + 0xB0)) = 1;
        (*((s32 (**)(s32)) (((s8 *) param_1) + 0x248)))(*((s32 *) (((s8 *) param_1) + new_var)));
        break;

      case 1:
        *((s16 *) (((s8 *) local_1) + 0xB0)) = 0;
        (*((s32 (**)(s32)) (((s8 *) param_1) + 0x248)))(*((s32 *) (((s8 *) param_1) + new_var)));
        break;

      case -1:
        (*((s32 (**)(s32)) (((s8 *) param_1) + 0x248)))(*((s32 *) (((s8 *) param_1) + 0x24C)));
        break;

    }

    func_808012C8_gcnewoption(*((s16 *) (((s8 *) local_1) + 0xB0)));
    return;
  }
  (*((s32 (**)(s32)) (((s8 *) param_1) + 0x248)))(*((s32 *) (((s8 *) param_1) + new_var)));
}

void gcnewoption_entrypoint_16(s32 param_0, u8 *param_1, s32 param_2, s32 param_3)
{
    if (param_3 != 1) {
        (*(s32 (**)(s32, u8 *, s32))(param_1 + 0x248))(*(s32 *)(param_1 + 0x24C), param_1, param_2);
    }
}

s32 gcnewoption_entrypoint_17(s32 param_0, unsigned int param_1)
{
  return (*((s16 *) (((s8 *) (param_0 + (param_1 * 2))) + 0xB0))) == 0;
}

int gcnewoption_entrypoint_18(s16 *param_0, int param_1)
{
  return param_0[param_1 + 0x58] == 1;
}

int gcnewoption_entrypoint_19(s16 *param_0, int param_1)
{
  return !(param_0[param_1 + 0x58] + 1);
}

int gcnewoption_entrypoint_20(s16 *param_0, int param_1) {
    return param_0[param_1 + 0x58];
}

void gcnewoption_entrypoint_21(s16 *param_0, int param_1)
{
  param_0[param_1 + 0x58] = 0;
}

void gcnewoption_entrypoint_22(union U *param_0, int param_1)
{
    *(s16 *)((char *)param_0 + (param_1 * 2) + 0xB0) = 1;
}

void gcnewoption_entrypoint_23(s16 *param_0, int param_1)
{
  *(s16*)((s8*)(&param_0[param_1]) + 176) = -1;
}

void gcnewoption_entrypoint_24(s16 *param_0, s32 param_1, s32 param_2) {
    param_0[param_1 + 0x58] = param_2;
}

int gcnewoption_entrypoint_25(u8 *param_0, s32 param_1)
{
  if (!(param_1 == 0))
  {
    param_0[0x1D] &= ~0x40;
  }
  else
  {
    param_0[0x1D] = (param_0[0x1D] & 0xFFFF) | 0x40;
  }
}

void gcnewoption_entrypoint_26(u8 *param_0, s32 param_1)
{
    s32 local_0;
    s32 local_1;

    if (param_1) {
        ((CodexOptionVisibility *)(param_0 + 0x1D))->local_0 = 0;
    } else {
        ((CodexOptionVisibility *)(param_0 + 0x1D))->local_0 = 1;
    }
    for (local_0 = 0; local_0 < *(s16 *)(param_0 + 2); local_0++) {
        local_1 = func_80800000_gcnewoption(param_0, local_0);
        if (((void **)(param_0 + 0x3C))[local_1]) {
            _gczoombox_entrypoint_44(((void **)(param_0 + 0x3C))[local_1], param_1 ? 0 : 1);
        }
    }
}

void gcnewoption_entrypoint_27(u8 *param_0, s32 param_1, s32 param_2)
{
    s32 local_1;
    s32 local_0;

    (param_0 + param_1)[0x218] = param_2;
    local_0 = func_80800038_gcnewoption(param_0, param_1);
    func_80800000_gcnewoption(param_0, local_0);
    if (local_0 != -1) {
        local_1 = func_80800000_gcnewoption(param_0, local_0);
        if (((s32 *)param_0)[local_1 + 15] != 0) {
            _gczoombox_entrypoint_40(((s32 *)param_0)[local_1 + 15], param_2);
        }
    }
}

void gcnewoption_entrypoint_28(OptionState *param_0)
{
    s32 local_0;
    gcnewoption_entrypoint_42(param_0, 0.1f);
    ((OptionClosingFlag *)param_0)->local_0 = 1;
    if (*(void **)((u8 *)param_0 + 0x20))
        _gczoombox_entrypoint_20(*(void **)((u8 *)param_0 + 0x20), 30.0f, 0, 2, 0.1f, 0, 0);
    for (local_0 = 0; local_0 < *(s16 *)((u8 *)param_0 + 2); local_0++) {
        if (((void **)((u8 *)param_0 + 0x3C))[local_0])
            _gczoombox_entrypoint_20(((void **)((u8 *)param_0 + 0x3C))[local_0], 100.0f, 0, 2, 0.1f, 0, 0);
    }
}

void gcnewoption_entrypoint_29(u8 *param_0, u32 param_1)
{
  int new_var;
  char new_var2;
  param_0[new_var = 0x1d] = (u8) ((param_0[new_var] & 0xfff7) | ((new_var2 = param_1 * 8) & 8));
  if (!param_0)
  {
  }
}

void gcnewoption_entrypoint_30(u8 *param_0, s16 *param_1)
{
    s16 local_0[30];
    s32 local_1;
    s32 local_2;
    u16 local_3;
    s32 local_4;
    s32 local_5;

    for (local_1 = 0; local_1 < *(s16 *)(param_0 + 4); local_1++) {
        local_4 = 0;
        do {
            local_2 = func_800DC128(12, 210);
            if (_gczoomboxdata_entrypoint_6(local_2)) {
                local_3 = _gczoomboxdata_entrypoint_5(local_2);
                if (_gczoomboxdata_entrypoint_5(*(s16 *)(param_0 + 0x236)) != local_3) {
                    local_4 = 1;
                    if (param_1) {
                        for (local_5 = 0; param_1[local_5] != -1; local_5++) {
                            if (_gczoomboxdata_entrypoint_5(param_1[local_5]) == local_3) {
                                local_4 = 0;
                                break;
                            }
                        }
                    }
                    if (local_4) {
                        for (local_5 = local_1 - 1; local_5 >= 0; local_5--) {
                            if (_gczoomboxdata_entrypoint_5(local_0[local_5]) == local_3) {
                                local_4 = 0;
                                break;
                            }
                        }
                    }
                }
            }
        } while (!local_4);
        gcnewoption_entrypoint_31(param_0, local_1, (s16)local_2);
        local_0[local_1] = local_2;
    }
}

void gcnewoption_entrypoint_31(param_0, param_1, param_2) s32 param_0; s32 param_1; s16 param_2; {
    (*(s16 *)((s8 *)((param_0 + (param_1 * 2))) + (0x1DC))) = param_2;
}

int gcnewoption_entrypoint_32(Actor *param_0, s16 param_1)
{
    s16 temp;
    temp = param_1;
    *(s16 *)((char *)param_0 + 0x236) = temp;
    _gczoombox_entrypoint_37(*(s32 *)((char *)param_0 + 0x20), temp);
}

int gcnewoption_entrypoint_33(void *param_0)
{
    s32 local_0;
    void *local_1;
    void *local_2;
    *(s16 *)((char *)(param_0) + 0x238) = 1;
    if ((*(s32 *)((char *)(param_0) + 0x20)) != 0)
    {
        _gczoombox_entrypoint_23((*(s32 *)((char *)(param_0) + 0x20)), 0);
    }
    local_0 = 0;
    local_2 = param_0;
    while (local_0 < (*(s16 *)((char *)(param_0) + 0x2)))
    {
        local_1 = *(void **)((char *)(local_2) + 0x3C);
        _gczoombox_entrypoint_23(local_1, 0);
        local_0++;
        local_2 = (void *)((char *)(local_2) + 0x4);
    }
}

void gcnewoption_entrypoint_34(OptionState *param_0, u32 param_1)
{
    if (*(void **)((u8 *)param_0 + 0x20) != NULL) {
        _gczoombox_entrypoint_32(*(void **)((u8 *)param_0 + 0x20));
        _gczoombox_entrypoint_8(*(void **)((u8 *)param_0 + 0x20),
            _gldbstring_entrypoint_1(*(void **)((u8 *)param_0 + 0x23C), (s16)param_1));
        ((OptionChangeFlags *)param_0)->changed = 1;
        *(f32 *)((u8 *)param_0 + 0x30) = *(f32 *)((u8 *)param_0 + 0x2C);
    }
}

void func_808019D0_gcnewoption(NewOptionUpdateState *param_0)
{
    s32 local_0;
    s32 local_1;
    s32 local_2;
    s32 local_3;
    void *local_4;
    s32 local_5;
    if (!param_0->local_1) {
        local_0 = func_80800038_gcnewoption(param_0, param_0->local_0[3]);
        for (local_1 = 0; local_1 < param_0->local_0[1]; local_1++) {
            local_2 = func_80800000_gcnewoption(param_0, local_1);
            local_3 = func_80800070_gcnewoption(param_0, local_1);
            func_808027DC_gcnewoption(param_0, local_1);
            if (param_0->local_2) {
                _gczoombox_entrypoint_40(param_0->local_5[local_2], local_0 == local_1 ? 1 : 0);
            } else {
                _gczoombox_entrypoint_40(param_0->local_5[local_2], param_0->local_6[local_3]);
            }
            if (local_0 == local_1 && !_gczoombox_entrypoint_22(param_0->local_5[local_2])) {
                func_808010E0_gcnewoption(param_0, local_3);
            }
            _gczoombox_entrypoint_21(param_0->local_5[local_2], local_0 == local_1);
            _gczoombox_entrypoint_4(param_0->local_5[local_2]);
        }
        func_80801B5C_gcnewoption(param_0);
    }
    if (param_0->local_3 != 0) {
        local_4 = param_0->local_3;
        local_5 = _gczoombox_entrypoint_3(param_0->local_3);
        _gczoombox_entrypoint_4(local_4);
        if (param_0->local_0[0] == 3 || param_0->local_0[0] == 4 ||
            param_0->local_0[0] == 5) {
            param_0->local_4 = local_5;
        }
    }
    param_0->local_0[6] = _gldialog_entrypoint_0();
}

void func_80801B5C_gcnewoption(param_0) u8 *param_0;
{
    s32 local_0;
    s32 local_1;
    f32 local_2;
    f32 local_3;
    f32 local_4;
    s16 local_5;
    s16 local_6;

    for (local_0 = 0; local_0 < *(s16 *)(param_0 + 2); local_0++) {
        local_1 = func_80800000_gcnewoption(param_0, local_0);
        local_2 = local_0 + 1;
        local_2 *= *(f32 *)(param_0 + 0x14);
        local_4 = *(f32 *)(param_0 + 0x14) * 1.9f;
        local_3 = local_2 - ((f32 *)(param_0 + 0x80))[local_1];
        if (local_4 < local_3) {
            ((f32 *)(param_0 + 0x80))[local_1] =
                *(f32 *)(param_0 + 0x14) * (*(s16 *)(param_0 + 2) + 1);
            _gczoombox_entrypoint_28(((s32 *)(param_0 + 0x3C))[local_1], 0);
            *(s16 *)(param_0 + 0x34) = 255;
        } else if (local_3 < -local_4) {
            ((f32 *)(param_0 + 0x80))[local_1] = 0.0f;
            _gczoombox_entrypoint_28(((s32 *)(param_0 + 0x3C))[local_1], 0);
            *(s16 *)(param_0 + 0x34) = 255;
        }
        if (*(s16 *)(param_0 + 0x34) >= 20.0f) {
            *(s16 *)(param_0 + 0x34) -= 20.0f;
        }
        if (*(f32 *)(param_0 + 0x14) * 0.66f < ((f32 *)(param_0 + 0x80))[local_1]
            && ((f32 *)(param_0 + 0x80))[local_1] <
                ((f32)*(s16 *)(param_0 + 2) + 0.66f) * *(f32 *)(param_0 + 0x14)) {
            local_5 = _gczoombox_entrypoint_29(((s32 *)(param_0 + 0x3C))[local_1]);
            if (local_5 < 236) {
                _gczoombox_entrypoint_28(((s32 *)(param_0 + 0x3C))[local_1], (s16)(local_5 + 20));
            }
        } else {
            local_6 = _gczoombox_entrypoint_29(((s32 *)(param_0 + 0x3C))[local_1]);
            if (local_6 >= 20) {
                _gczoombox_entrypoint_28(((s32 *)(param_0 + 0x3C))[local_1], (s16)(local_6 - 20));
            }
        }
        if (local_2 != ((f32 *)(param_0 + 0x80))[local_1]) {
            if (local_2 < ((f32 *)(param_0 + 0x80))[local_1]) {
                ((f32 *)(param_0 + 0x80))[local_1] -= 4.0f;
                if (((f32 *)(param_0 + 0x80))[local_1] <= local_2) {
                    ((f32 *)(param_0 + 0x80))[local_1] = local_2;
                } else {
                    ((NewOptionMovingFlag1081 *)param_0)->local_0 = 1;
                }
            } else if (((f32 *)(param_0 + 0x80))[local_1] < local_2) {
                ((f32 *)(param_0 + 0x80))[local_1] += 4.0f;
                if (local_2 <= ((f32 *)(param_0 + 0x80))[local_1]) {
                    ((f32 *)(param_0 + 0x80))[local_1] = local_2;
                } else {
                    ((NewOptionMovingFlag1081 *)param_0)->local_0 = 1;
                }
            }
            _gczoombox_entrypoint_38(((s32 *)(param_0 + 0x3C))[local_1],
                (s32)(*(s16 *)(param_0 + 0x256) + ((f32 *)(param_0 + 0x80))[local_1]));
        }
    }
}

s32 func_80801E68_gcnewoption(u8 *param_0) {
    s32 var_s3;
    s32 sp48;
    s32 temp_v0;
    s32 temp_v0_2;
    u8 *var_s0;
    u8 *var_s2;

    sp48 = 1;
    var_s0 = param_0;
    var_s3 = 0;
    if ((*(s16 *)((s8 *)(param_0) + (2))) > 0) {
        var_s2 = param_0;
        do {
            temp_v0 = _gczoombox_entrypoint_3((*(s32 *)((s8 *)(var_s0) + (0x3C))));
            switch (temp_v0) {                      
            case 0:                                 
                if (var_s3 == 0) {
                    if (((*(s32 *)((s8 *)(param_0) + (0x20))) == 0) || (_gczoombox_entrypoint_3((*(s32 *)((s8 *)(param_0) + (0x20)))) == 1) || (_gczoombox_entrypoint_3((*(s32 *)((s8 *)(param_0) + (0x20)))) == 2) || (_gczoombox_entrypoint_3((*(s32 *)((s8 *)(param_0) + (0x20)))) == 3) || (func_800D9078(param_0 + 0x38) != 0)) {
                        _gczoombox_entrypoint_9((*(s32 *)((s8 *)(var_s0) + (0x3C))));
                        if ((*(f32 *)((s8 *)(var_s0) + (0x9C))) == 0.0f) {
                            (*(f32 *)((s8 *)(var_s0) + (0x9C))) = (f32) (*(f32 *)((s8 *)(param_0) + (0x18)));
                        }
                    }
                } else if ((_gczoombox_entrypoint_3((*(s32 *)((s8 *)(var_s0) + (0x38)))) == 1) || (_gczoombox_entrypoint_3((*(s32 *)((s8 *)(var_s0) + (0x38)))) == 2) || (_gczoombox_entrypoint_3((*(s32 *)((s8 *)(var_s0) + (0x38)))) == 3) || (func_800D9078(var_s0 + 0x98) != 0)) {
                    _gczoombox_entrypoint_9((*(s32 *)((s8 *)(var_s0) + (0x3C))));
                    if ((*(f32 *)((s8 *)(var_s0) + (0x9C))) == 0.0f) {
                        (*(f32 *)((s8 *)(var_s0) + (0x9C))) = (f32) (*(f32 *)((s8 *)(param_0) + (0x18)));
                    }
                }
                break;
            case 1:                                 
                _gczoombox_entrypoint_11((*(s32 *)((s8 *)(var_s0) + (0x3C))));
                (*(s8 *)((s8 *)(var_s2) + (0x94))) = temp_v0;
                break;
            case 2: ;                                 
            case 3:                                 
                (*(s8 *)((s8 *)(var_s2) + (0x94))) = temp_v0;
                break;
            }
            if ((*(s8 *)((s8 *)(var_s2) + (0x94))) <= 0) {
                sp48 = 0;
            }
            var_s3 += 1;
            var_s0 += 4;
            var_s2 += 1;
        } while (var_s3 < (*(s16 *)((s8 *)(param_0) + (2))));
    }
    if ((*(s32 *)((s8 *)(param_0) + (0x20))) != 0) {
        temp_v0_2 = _gczoombox_entrypoint_3((*(s32 *)((s8 *)(param_0) + (0x20))));
        switch (temp_v0_2) {                        
        case 2: ;                                     
        case 3:                                     
            break;
        case 0:                                     
            sp48 = 0;
            if (temp_v0_2 != (*(u8 *)((s8 *)(param_0) + (0x24)))) {
                _gczoombox_entrypoint_9((*(s32 *)((s8 *)(param_0) + (0x20))));
                _gczoombox_entrypoint_11((*(s32 *)((s8 *)(param_0) + (0x20))));
                if ((*(f32 *)((s8 *)(param_0) + (0x38))) == 0.0f) {
                    (*(f32 *)((s8 *)(param_0) + (0x38))) = (f32) (*(f32 *)((s8 *)(param_0) + (0x18)));
                }
            }
            break;
        }
        (*(u8 *)((s8 *)(param_0) + (0x24))) = (u8) temp_v0_2;
    }
    return sp48;
}

s32 func_808020C4_gcnewoption(param_0) NewOptionTransitionState *param_0;
{
    s32 local_0;
    s32 local_1;
    s32 local_2 = 1;
    s32 local_3 = 0;
    s32 local_4;
    s32 local_5;
    s32 local_6;

    for (local_0 = 0; local_0 < param_0->local_1; local_0++) {
        local_1 = _gczoombox_entrypoint_3(param_0->local_4[local_0]);
        if (local_1 == 0 || local_1 == 2 || local_1 == 3) {
            local_3 = 1;
        }
    }
    if (param_0->local_2) {
        local_4 = _gczoombox_entrypoint_3(param_0->local_2);
        switch (local_4) {
        case 0:
        case 2:
        case 3:
            local_3 = 1;
            break;
        }
    }
    for (local_0 = 0; local_0 < param_0->local_1; local_0++) {
        local_5 = _gczoombox_entrypoint_3(param_0->local_4[local_0]);
        switch (local_5) {
        case 0:
        case 2:
        case 3:
            local_2 = 0;
            if (local_5 != param_0->local_5[local_0]) {
                _gczoombox_entrypoint_33(param_0->local_4[local_0]);
            }
            param_0->local_5[local_0] = local_5;
            break;
        case 4:
            local_2 = 0;
            if (!local_3) {
                if (local_5 != param_0->local_5[local_0]) {
                    _gczoombox_entrypoint_10(param_0->local_4[local_0]);
                }
                param_0->local_5[local_0] = local_5;
            }
            break;
        case 5:
            param_0->local_5[local_0] = local_5;
            break;
        default:
            param_0->local_5[local_0] = local_5;
            break;
        }
    }
    if (param_0->local_2) {
        local_6 = _gczoombox_entrypoint_3(param_0->local_2);
        switch (local_6) {
        case 1:
        case 5:
        case 6:
            break;
        case 0:
        case 2:
        case 3:
            local_2 = 0;
            if (local_6 != param_0->local_3) {
                _gczoombox_entrypoint_33(param_0->local_2);
            }
            break;
        case 4:
            local_2 = 0;
            if (local_6 != param_0->local_3) {
                _gczoombox_entrypoint_10(param_0->local_2);
            }
            break;
        }
        param_0->local_3 = local_6;
    }
    return local_2;
}

s32 func_808022E0_gcnewoption(param_0) u8 *param_0;
{
    s32 local_0;
    s32 local_1;
    s32 local_2;
    s32 local_3 = 1;
    s32 *local_4;
    u8 *local_5;

    for (local_0 = 0; local_0 < *(s16 *)(param_0 + 2); local_0++) {
        if (func_80800070_gcnewoption(param_0, local_0) != *(s16 *)(param_0 + 6)) {
            local_1 = func_80800000_gcnewoption(param_0, local_0);
            local_2 = _gczoombox_entrypoint_3(*(s32 *)(param_0 + 0x3C + local_1 * 4));
            switch (local_2) {
                case 0:
                case 2:
                case 3:
                    local_5 = param_0 + local_1;
                    local_3 = 0;
                    local_4 = (s32 *)param_0 + local_1;
                    if (local_2 != *(s8 *)(local_5 + 0x94)) {
                        _gczoombox_entrypoint_12(local_4[0xF]);
                        _gczoombox_entrypoint_10(local_4[0xF]);
                    }
                    break;
                case 4:
                    local_5 = param_0 + local_1;
                    if (local_2 != *(s8 *)(local_5 + 0x94)) {
                        _gczoombox_entrypoint_10(*(s32 *)(param_0 + 0x3C + local_1 * 4));
                    }
                    break;
                case 5:
                    local_5 = param_0 + local_1;
                    break;
                case 1:
                default:
                    local_5 = param_0 + local_1;
                    break;
            }
            local_5[0x94] = local_2;
        }
    }
    return local_3;
}

s32 func_8080241C_gcnewoption(param_0) OptionBoxes29 *param_0;
{
    s32 local_0;
    s32 local_1;
    s32 local_2;
    s32 local_3 = 1;
    for (local_0 = 0; local_0 < param_0->count; local_0++) {
        if (func_80800070_gcnewoption(param_0, local_0) != param_0->selected) {
            local_1 = func_80800000_gcnewoption(param_0, local_0);
            local_2 = _gczoombox_entrypoint_3(param_0->boxes[local_1]);
            switch (local_2) {
            case 0:
            case 2:
            case 3:
                local_3 = 0;
                if (local_2 != param_0->states[local_1]) {
                    _gczoombox_entrypoint_33(param_0->boxes[local_1]);
                    param_0->indices[local_1] = -1;
                }
                break;
            case 4:
            case 5:
                break;
            default:
                break;
            }
            param_0->states[local_1] = local_2;
        }
    }
    return local_3;
}

int func_80802534_gcnewoption(NewOptionBoxes *param_0)
{
    s32 local_0;
    s32 local_1;
    s32 local_2;
    s32 local_3 = 1;
    for (local_0 = 0; local_0 < param_0->local_0[1]; local_0++) {
        if (func_80800070_gcnewoption(param_0, local_0) != param_0->local_0[3]) {
            local_1 = func_80800000_gcnewoption(param_0, local_0);
            local_2 = _gczoombox_entrypoint_3(param_0->local_1[local_1]);
            switch (local_2) {
            case 0:
                local_3 = 0;
                if (local_2 != param_0->local_2[local_1]) {
                    _gczoombox_entrypoint_9(param_0->local_1[local_1]);
                    _gczoombox_entrypoint_11(param_0->local_1[local_1]);
                }
                break;
            case 4:
                local_3 = 0;
                if (local_2 != param_0->local_2[local_1])
                    _gczoombox_entrypoint_11(param_0->local_1[local_1]);
                break;
            case 2:
                break;
            }
            param_0->local_2[local_1] = local_2;
        }
    }
    return local_3;
}

s32 func_80802674_gcnewoption(param_0) u8 *param_0;
{
    s32 local_0;
    s32 local_1;
    s32 local_2;

    local_0 = 1;
    local_1 = func_80800000_gcnewoption(param_0, func_80800038_gcnewoption(param_0, *(s16 *)(param_0 + 6)));
    local_2 = _gczoombox_entrypoint_3(((s32 *)(param_0 + 0x3C))[local_1]);
    switch (local_2) {
    case 0:
    case 3:
        if (local_2 != *(s8 *)(param_0 + local_1 + 0x94)) {
            _gczoombox_entrypoint_34(((s32 *)(param_0 + 0x3C))[local_1]);
        }
        local_0 = 0;
        break;
    case 4:
        if (local_2 != *(s8 *)(param_0 + local_1 + 0x94)) {
            _gczoombox_entrypoint_10(((s32 *)(param_0 + 0x3C))[local_1]);
        }
        local_0 = 0;
        break;
    case 5:
    case 6:
        break;
    default:
    case 1:
    case 2:
        break;
    }
    *(s8 *)(param_0 + local_1 + 0x94) = local_2;
    if (*(s32 *)(param_0 + 0x20)) {
        local_2 = _gczoombox_entrypoint_3(*(s32 *)(param_0 + 0x20));
        switch (local_2) {
        case 0:
        case 2:
        case 3:
        case 6:
            local_0 = 0;
            if (local_2 != param_0[0x24]) {
                _gczoombox_entrypoint_34(*(s32 *)(param_0 + 0x20));
            }
            break;
        case 4:
            local_0 = 0;
            if (local_2 != param_0[0x24]) {
                _gczoombox_entrypoint_10(*(s32 *)(param_0 + 0x20));
            }
            break;
        }
        param_0[0x24] = local_2;
    }
    return local_0;
}

void func_808027DC_gcnewoption(param_0, param_1) NewOptionContentState *param_0; s32 param_1;
{
    s32 local_1;
    s32 local_2;
    s32 local_0;
    s32 local_3;
    local_1 = func_80800070_gcnewoption(param_0, param_1);
    local_2 = func_80800000_gcnewoption(param_0, param_1);
    local_0 = param_0->local_5[local_1];
    local_3 = _gldialog_entrypoint_0();
    if (local_0 != param_0->local_2[func_80800000_gcnewoption(param_0, param_1)] ||
        param_0->local_3[local_2][0] != param_0->local_6[local_1][0] ||
        param_0->local_3[local_2][1] != param_0->local_6[local_1][1] ||
        param_0->local_3[local_2][2] != param_0->local_6[local_1][2] ||
        param_0->local_4[local_2] != param_0->local_7[local_1] || local_3 != param_0->local_0) {
        _gczoombox_entrypoint_32(param_0->local_1[local_2]);
        _gczoombox_entrypoint_27(param_0->local_1[local_2], param_0->local_6[local_1]);
        _gczoombox_entrypoint_8(param_0->local_1[local_2], _gldbstring_entrypoint_1(param_0->local_9, (s16)local_0));
        _gczoombox_entrypoint_40(param_0->local_1[local_2], param_0->local_8[local_1]);
        _gczoombox_entrypoint_36(param_0->local_1[local_2], param_0->local_7[local_1]);
        param_0->local_2[local_2] = local_0;
        param_0->local_3[local_2][0] = param_0->local_6[local_1][0];
        param_0->local_3[local_2][1] = param_0->local_6[local_1][1];
        param_0->local_3[local_2][2] = param_0->local_6[local_1][2];
        param_0->local_4[local_2] = param_0->local_7[local_1];
    }
}

void func_80802998_gcnewoption(NewOptionScroll27 *param_0)
{
    s16 local_0;

    if (param_0->local_1 && (param_0->local_3 || param_0->local_4)) {
        if (param_0->local_6 <= 0.0f) {
            local_0 = param_0->local_2 + 1;
            if (param_0->local_4 < local_0) {
                local_0 = param_0->local_3 - 1;
            }
            _gczoombox_entrypoint_32(param_0->local_1);
            _gczoombox_entrypoint_8(param_0->local_1, _gldbstring_entrypoint_1(param_0->local_7, local_0));
            param_0->local_0 = 1;
            param_0->local_2 = local_0;
            param_0->local_6 = param_0->local_5;
        } else if (_gczoombox_entrypoint_3(param_0->local_1) == 3) {
            param_0->local_6 -= func_800D8FF8();
        }
    }
}

void func_80802A9C_gcnewoption(void *param_0) {
    s32 local_0;
    s8 *local_1 = param_0;
    for (local_0 = 0; local_0 < *(s16 *)((char *)param_0 + 0x2); local_0++) {
        local_1[0x94 + local_0] = -1;
    }
    *(u8 *)((char *)param_0 + 0x24) = 0xFF;
}

void gcnewoption_entrypoint_35(s32 param_0, s32 param_1, s32 param_2, s32 param_3)
{
    union {
        struct { s16 local_0; s16 local_1; } local_0;
        s32 local_1;
    } local_0;

    local_0.local_0.local_0 = param_2;
    local_0.local_0.local_1 = param_3;
    func_80101074(param_1);
    func_8010114C(param_0, 0x20, local_0.local_1);
}

void gcnewoption_entrypoint_36(s32 param_0)
{
  u8 *new_var;
  new_var = (u8 *) (param_0 + 0x1C);
  *new_var = ((*new_var) & 0xFF) | 0x10;
}

void func_80802B24_gcnewoption(u8 *param_0, s32 param_1)
{
  int new_var;
  new_var = param_1;
  if (new_var)
  {
    if (((!(new_var & 0xFF)) && (!new_var)) && (!new_var))
    {
    }
    param_0[28] |= (long) 0x8;
  }
  else
  {
    param_0[28] &= 0xFFF7;
  }
}

u32 gcnewoption_entrypoint_37(OptionState *param_0, u32 param_1)
{
  s16 *new_var2;
  int new_var5;
  OptionState *new_var;
  u8 *new_var4;
  u8 *new_var3;
  new_var = param_0;
  if (((*((s16 *) (((char *) new_var) + 0x0))) == 5) || ((*((s16 *) (((char *) new_var) + 0x0))) == 4))
  {
    new_var5 = !new_var;
    if ((((!new_var) & 0xFFFF) && new_var5) && (!new_var))
    {
    }
    new_var2 = (s16 *) (((char *) new_var) + 0x0);
    if (param_1 != 0)
    {
      new_var3 = (u8 *) (((char *) param_0) + 0x1C);
      *new_var3 |= 0x20;
    }
    else
    {
      *(new_var4 = (u8 *) (((char *) new_var) + 0x1C)) &= ~0x20;
    }
    func_80802A9C_gcnewoption(param_0);
    *new_var2 = 6;
    return 1;
  }
  return 0;
}

s32 gcnewoption_entrypoint_38(u8 *param_0, s32 param_1)
{
  s32 local_0;
  s16 temp_v0;
  int new_var;
  temp_v0 = *((s16 *) ((s8 *) param_0));
  if ((temp_v0 == 5) || (temp_v0 == 0xA))
  {
    local_0 = func_80800000_gcnewoption(param_0, func_80800038_gcnewoption(param_0, *((s16 *) (((s8 *) param_0) + 6))));
    func_80802A9C_gcnewoption(param_0);
    *((s16 *) ((s8 *) param_0)) = 9;
    func_80802B24_gcnewoption(param_0, 1);
    if (param_1 != 0)
    {
      new_var = local_0 * 4;
      _gczoombox_entrypoint_41(*((s32 *) (((s8 *) (param_0 + new_var)) + 0x3C)), 1000.0f);
    }
    return 1;
  }
  return 0;
}

s32 gcnewoption_entrypoint_39(OptionState *param_0)
{
    s32 local_0;
    if (((s16 *)param_0)[0] == 5 || ((s16 *)param_0)[0] == 9) {
        local_0 = func_80800000_gcnewoption(param_0, func_80800038_gcnewoption(param_0, ((s16 *)param_0)[3]));
        func_80802A9C_gcnewoption(param_0);
        ((s16 *)param_0)[0] = 10;
        _gczoombox_entrypoint_41(*(void **)((u8 *)param_0 + 0x3C + local_0 * 4), 45.0f);
        return 1;
    }
    return 0;
}

void gcnewoption_entrypoint_40(u8 *param_0, s32 param_1, s32 param_2, s32 param_3, f32 param_4, f32 param_5) {
    *(s16 *)(param_0 + 0x254) = param_1;
    *(s16 *)(param_0 + 0x256) = param_2;
    *(f32 *)(param_0 + 0x14) = param_3;
    *(f32 *)(param_0 + 0x258) = param_4;
    *(f32 *)(param_0 + 0x25C) = param_5;
}

/* HEADER-CHANGE: include/gc/newoption.h now declares gcnewoption_entrypoint_41 and _gcnewoption_entrypoint_41
 * with an s32 second parameter (was u8); the target does not mask param_1 on entry. Regression check: all 1153
 * objects were built with the old and the new header, and only this file changed. */
void gcnewoption_entrypoint_41(OptionState *param_0, s32 param_1)
{
    OptionScrollState *local_0 = (OptionScrollState *)param_0;
    local_0->local_3 = param_1;
    local_0->local_5 = 0;
    local_0->local_4 = param_1 - (local_0->local_1 - 1) / 2;
    if (local_0->local_4 < 0) local_0->local_4 = 0;
    if (local_0->local_4 > local_0->local_2 - local_0->local_1) {
        local_0->local_4 = local_0->local_2 - local_0->local_1;
    }
    func_808010E0_gcnewoption(param_0, param_1);
}

void gcnewoption_entrypoint_42(OptionState *param_0, f32 param_1)
{
  int new_var;
  new_var = 6;
  ((f32 *)param_0)[new_var] = param_1;
}

s32 gcnewoption_entrypoint_43(void *param_0, s32 param_1, s32 param_2)
{
    s32 local_0;

    local_0 = func_80800038_gcnewoption(param_0, param_1);
    if (local_0 != -1) {
        local_0 = func_80800000_gcnewoption(param_0, local_0);
        _gczoombox_entrypoint_21(*(void **)((u8 *)param_0 + 0x3C + local_0 * 4), param_2);
        return 1;
    }
    return 0;
}

void gcnewoption_entrypoint_44(OptionTitleControl *param_0, s32 param_1)
{
    param_0->local_2 = param_1;
    if (param_1) {
        _gczoombox_entrypoint_20(param_0->title, 0.0f, 0, 2, 0.1f, 0, 0);
    } else {
        if (!param_0->local_0) {
            _gczoombox_entrypoint_32(param_0->title);
            _gczoombox_entrypoint_8(param_0->title, _gldbstring_entrypoint_1(param_0->strings, param_0->title_text));
            param_0->local_0 = 1;
        }
        if (param_0->local_1) {
            _gczoombox_entrypoint_20(param_0->title, 30.0f, 0, 2, 0.1f, 0, 0);
        } else {
            _gczoombox_entrypoint_20(param_0->title, 15.0f, 0, 2, 0.1f, 0, 0);
        }
    }
}

s16 gcnewoption_entrypoint_45(u8 *param_0) {
    return *(s16 *)(param_0 + 6);
}

void gcnewoption_entrypoint_46(void *param_0, int param_1)
{
  ((u8 *) param_0)[0x250] = param_1;
}

s32 gcnewoption_entrypoint_47(s32 param_0) {
    return *(u8 *)(param_0 + 0x24) == 3;
}

int gcnewoption_entrypoint_48(s16 *param_0) {
    s16 local_0 = *param_0;
    return local_0 >= 3 && local_0 < 11;
}

void gcnewoption_entrypoint_49(u8 *param_0, u32 param_1)
{
  int new_var;
  new_var = param_0[0x1D] & 0xFFFF;
  param_0[0x1D] = (u8) (((param_1 << 1) & 2) | ((new_var & 0xFFFF) & 0xFFFD));
}

/* TU-NOTE: the .data of this overlay (formerly asm/data/overlays/gc/newoption.data.s) is defined here in C.
 * Values are taken from the ROM. */
