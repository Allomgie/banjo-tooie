/*
 * 1EEC090 -- split into three translation units (1EEC090, 1EEC780 and
 * 1EED8E0).
 *
 * The yaml treated 0x1EEC090..0x1EEE680 as one file, but the ROM's .rodata
 * shows three objects. The constants of func_80112D90 end at 0x1EFFE9C and
 * are padded to 0x1EFFEA0; the constants of func_80113978 end at 0x1EFFEC4
 * and are padded to 0x1EFFED0. IDO aligns every object's .rodata to 16 bytes
 * and never pads inside an object, so both gaps are object boundaries. The
 * text shows none because these objects happen to end on 16-byte boundaries.
 *
 * The second object starts at func_80112E90 (ROM 0x1EEC780): this unit's
 * accessors of the structure at param->0x60 run up to func_80112E84, and
 * func_80112E90 (return 0x80) opens the next unit much as func_800967C0
 * (return 0x28) opens 1E700B0. The third object starts at func_80113FF0
 * (ROM 0x1EED8E0); see 1EED8E0.c.
 */

#include "core2/1EEC090.h"
#include <types.h>

extern f32 func_800F1DCC(f32, f32);
extern f32 func_800FF060(f32, f32 *, f32, f32, f32, f32);
extern f32 func_800D8FF8(void);
extern f32 mlAbsF(f32);
extern f32 func_800F1344(f32, f32, f32, u32, f32);
extern f32 func_800136E4(f32);
typedef struct { u8 pad[12]; s16 local_0, local_1; f32 local_2, local_3, local_4, local_5, local_6; } State112A84;
typedef struct { u8 pad[0x60]; State112A84 *local_0; } Actor112A84;
extern void func_801107F0(Actor112A84 *, f32 *);
extern void func_800EFB24(f32 *, f32 *, f32 *);
extern void func_800F1A88(f32 *, f32 *);
extern void func_801160DC(Actor112A84 *, f32);
typedef struct { f32 field0,field4; s32 field8; } LocalAngle;
typedef struct { u8 pad0[0x60]; LocalAngle *field60; } LocalActor;
extern f32 func_800F1738(f32,f32,f32);
typedef struct { u8 pad[0xC]; s16 local_0, local_1; f32 local_2, local_3, local_4, local_5, local_6; } Motion112D90;
typedef struct { u8 pad[0x60]; Motion112D90 *local_0; } Actor112D90;
typedef struct { f32 *local_0; s32 local_1; } Table112E98;
typedef struct { u8 pad00[0x10]; s32 mode; } LocalSearch;
typedef struct { u8 pad00[0x28]; LocalSearch *search; } LocalOwner;
typedef struct { s32 pad[2]; s32 local_0; } Hit113688;
typedef struct { u8 pad0[0x14]; u8 disabled; u8 pad15[3]; s32 value18,value1C,value20,value24; u8 pad28[0x14]; s32 count3C,count40,count44,count48; f32 point4C[3],point58[3],point64[3],point70[3]; s32 direction7C; } LocalControls;
typedef struct { u8 pad0[0x28]; LocalControls *controls; } LocalState;
typedef struct { u8 pad0[0xC]; s16 local_0; u8 padE[0xA]; s32 local_1[4]; u8 pad28[0xC]; u8 local_2[4]; s8 local_3[4]; s32 local_4[4]; f32 local_5[4][3]; } State113D30;
typedef struct { u8 pad0[0x28]; State113D30 *local_0; } Owner113D30;
typedef struct { s32 pad; f32 local_0; u8 local_1; u8 pad_1[3]; } Entry113FF0;
typedef struct { u8 pad[0x48]; Entry113FF0 local_0[7]; } State113FF0;
typedef struct { u32 local_0; f32 local_1; u8 local_2; u8 pad[3]; } Hit114184;
typedef struct { s16 local_0; u8 local_1, local_2; u8 pad[0x10]; f32 local_3[3]; u8 pad2[0x18]; u32 local_4; f32 local_5[3]; Hit114184 local_6[7]; } State114184;
typedef struct { u8 pad[8]; u32 local_0; } Surface114184;
typedef struct { u8 pad[0x14]; u16 local_0; u8 pad2[2]; u16 local_1; } Marker11458C;
typedef struct { Marker11458C *local_0; s32 pad; u32 pad2:27; u32 local_1:1; u32 local_2:1; u32 pad3:2; u32 local_3:1; } Entry11458C;
typedef struct { u8 pad[0x64]; u32 pad2:14; u32 local_0:1; u32 pad3:17; u8 pad4[0x2C]; u32 pad5:17; u32 local_1:1; u32 pad6:14; } Actor11458C;
typedef struct { u8 pad[2]; u8 local_0; u8 pad2[9]; f32 local_1; u8 pad3[0x3C]; f32 local_2[1][3]; } Bounds114774;
typedef struct { u8 pad[3]; u8 local_0; u8 local_1; u8 pad5[3]; f32 local_2, local_3, local_4; } State149;
typedef struct {s32 local_0; f32 local_1; u8 local_2; u8 local_3[3];} local_record;
typedef struct {s16 local_0; u8 local_1, local_2, local_3; u8 local_4[3]; f32 local_5; u8 local_6[60]; local_record local_7[7];} local_type;
void func_80112D08(u8 *param_0, s32 param_1, f32 param_2, f32 param_3);

s32 func_801127A0() 
{
    return 0x24;
}

void func_801127A8(PlayerState* arg0, f32* arg1)
{
    func_80112550(arg0, arg1);
}

void func_801127C8(f32 param_0, f32 *param_1, f32 *param_2, f32 param_3, f32 param_4) {
    f32 local_0;
    f32 local_1;
    f32 local_2;
    local_0 = func_800F1DCC(param_0, *param_1);
    local_1 = mlAbsF(local_0);
    if (0.1f < local_1) {
        local_2 = func_800FF060(local_0, param_2, 1000.0f, -560.0f, 75.0f, func_800D8FF8());
        if (local_1 < mlAbsF(local_2) && *param_2 * local_0 > 0.0f) {
            local_2 = local_0;
            *param_2 = 0.0f;
        }
        *param_1 = func_800136E4(*param_1 + local_2);
    } else {
        *param_2 = 0.0f;
        *param_1 = param_0;
    }
}

void func_801128D4(f32 param_0, f32 *param_1, f32 *param_2, f32 param_3, f32 param_4, f32 param_5)
{
  f32 *new_var;
  f32 sp38;
  f32 *new_var2;
  f32 sp30;
  f32 sp2C;
  f32 sp28;
  f32 var_f0;
  if (param_0 == (*param_1))
  {
    *param_2 = 0.0f;
    return;
  }
  sp30 = func_800D8FF8();
  sp38 = func_800F1DCC(param_0, *param_1);
  if (mlAbsF(sp38) < param_5)
  {
    *param_2 = func_800F1344(sp38, 0.0f, param_5, 0x41200000, param_4);
  }
  else
  {
    var_f0 = param_3 * sp30;
    if (sp38 < 0.0f)
    {
      var_f0 = -var_f0;
    }
    *param_2 += var_f0;
    if ((*param_2) < 0.0f)
    {
      if ((*param_2) < (-param_4))
      {
        *param_2 = -param_4;
      }
    }
    else
      if (param_4 < (*param_2))
    {
      *param_2 = param_4;
    }
  }
  sp2C = (*param_2) * sp30;
  sp28 = mlAbsF(sp2C);
  if ((mlAbsF(sp38) < sp28) && ((sp2C * sp38) > 0.0f))
  {
    *param_2 = 0.0f;
    new_var2 = &(*(new_var = &param_0));
    sp2C = 0.0f;
    *param_1 = *new_var2;
  }
  *param_1 = func_800136E4((*param_1) + sp2C);
}

void func_80112A84(Actor112A84 *param_0) {
    s32 local_0;
    f32 local_1;
    f32 local_2;
    f32 local_3[3];
    f32 local_4[3];
    f32 local_5[3];
    f32 local_6[2];
    s32 local_7;
    if (param_0->local_0->local_0) {
        local_0 = 5;
        param_0->local_0->local_5 += func_800D8FF8();
        func_801127A8(param_0, local_3);
        func_801107F0(param_0, local_5);
        func_800EFB24(local_4, local_5, local_3);
        func_800F1A88(local_4, local_6);
        if (param_0->local_0->local_5 > param_0->local_0->local_6) local_6[1] = param_0->local_0->local_2;
        local_7 = mlAbsF(param_0->local_0->local_2 - local_6[1]) < 1.0f;
        local_1 = param_0->local_0->local_3;
        local_2 = param_0->local_0->local_2;
        if (param_0->local_0->local_0 == 1) {
            func_801127C8(param_0->local_0->local_2, &param_0->local_0->local_3, &param_0->local_0->local_4, 50.0f, 3.0f);
            func_801160DC(param_0, 0.0f);
        } else {
            func_801128D4(param_0->local_0->local_2, &param_0->local_0->local_3, &param_0->local_0->local_4, 800.0f, 160.0f, 100.0f);
            func_801160DC(param_0, 0.0f);
        }
        if (local_7) {
            param_0->local_0->local_0 = 0;
            param_0->local_0->local_1 = 0;
        }
    } else {
        local_0 = 0;
        local_2 = 0.0f;
        local_1 = 0.0f;
    }
    func_80112D08(param_0, local_0, local_1, local_2);
}

f32 func_80112C3C(LocalActor *param_0,f32 param_1)
{
    switch (param_0->field60->field8) {
    case 1: case 2: case 5:
        param_1=func_800F1738(param_1,param_0->field60->field0,param_0->field60->field4);
        break;
    case 3:
        if (func_800F1DCC(param_1,param_0->field60->field0)<0.0f) param_1=param_0->field60->field0;
        break;
    case 4:
        if (func_800F1DCC(param_1,param_0->field60->field0)>0.0f) param_1=param_0->field60->field0;
        break;
    }
    return param_1;
}

void func_80112D08(u8 *param_0, s32 param_1, f32 param_2, f32 param_3) {
    (*(s32 *)((s8 *)((*(u8 **)((s8 *)(param_0) + (0x60)))) + (8))) = param_1;
    (*(f32 *)((s8 *)((*(u8 **)((s8 *)(param_0) + (0x60)))) + (0))) = param_2;
    (*(f32 *)((s8 *)((*(u8 **)((s8 *)(param_0) + (0x60)))) + (4))) = param_3;
}

void func_80112D2C(s32 param_0)
{
    f32 local_0[3];
    f32 local_2[3];
    f32 local_1[3];

    func_801107F0(param_0, local_0);
    func_801127A8(param_0, local_1);
    func_800EFB24(local_2, local_0, local_1);
    func_800F1EA4(local_2, *(u8 **)(param_0 + 0x60) + 0x14);
    *(f32 *)((char *)(*(u8 **)(param_0 + 0x60)) + 0x18) = 0.0f;
}

void func_80112D90(Actor112D90 *param_0, f32 param_1, f32 param_2, s32 param_3, s32 param_4) {
    if (param_4 >= param_0->local_0->local_1) {
        if (param_3 != param_0->local_0->local_0) func_80112D2C(param_0);
        param_0->local_0->local_2 = param_1;
        param_0->local_0->local_5 = 0.0f;
        param_0->local_0->local_6 = mlAbsF(func_800F1DCC(param_0->local_0->local_2, param_0->local_0->local_3)) * 1.2f / param_2;
        param_0->local_0->local_0 = param_3;
        param_0->local_0->local_1 = param_4;
    }
}

void func_80112E50(u8 *param_0, f32 param_1, s32 param_2) {
    u8 *local_0;

    local_0 = (*(u8 **)((s8 *)(param_0) + (0x60)));
    if (((*(s16 *)((s8 *)(local_0) + (0xC))) != 0) && (param_2 == (*(s16 *)((s8 *)(local_0) + (0xE))))) {
        (*(f32 *)((s8 *)(local_0) + (0x10))) = (f32) ((*(f32 *)((s8 *)(local_0) + (0x14))) + param_1);
    }
}

short func_80112E84(s16 *param_0) {
    return ((s16 *)*((int *)param_0 + 0x18))[6];
}
