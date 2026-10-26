#include "common.h"

typedef struct { s16 local_0; s16 pad_0; s32 pad_1 : 17; s32 local_1 : 15; void *local_2; } InfoBarSound;
extern InfoBarSound D_808008B0_scinfobar[];
extern s32 func_800E8B74(s32);
extern void func_800E8D28(s32, f32);
extern void func_800E8C08(u8);
typedef struct ScInfobarCallback { s32 (*local_0)(void); u32 pad_0[2]; } ScInfobarCallback;
extern ScInfobarCallback D_80800D58_scinfobar[];
typedef struct { u8 percent; u8 mode; u8 state; u8 active; s16 id; s16 index; u8 pad_0[2]; u8 flag; u8 pad_1[9]; f32 time; u8 pad_2[8]; s32 first; s32 second; s32 third; u8 pad_3[8]; } InfoBar;
extern void *heap_alloc(s32);
extern void heap_free(void *);
typedef struct { u8 local_0; u8 pad_0[9]; u8 local_1; u8 pad_1[9]; f32 local_2; f32 local_3; } InfobarTransition;
extern f32 func_800D8FF8(void);
extern int D_80800D5C_scinfobar[];
typedef struct { u8 pad0[8]; s16 unk8; u16 padA; f32 unkC; f32 unk10; f32 pad14; f32 unk18; } InfoBarRateRecord;
extern u8 unkC[];
typedef struct { s16 local_0; s8 local_1; s8 local_2; s16 local_3; u16 local_4; s32 local_5; } InfoBarDialog;
extern void _fxdialog_entrypoint_2(f32);
extern void _fxdialog_entrypoint_4(s32, s32, s32, f32, f32, s32, s32);
typedef struct { u8 local_0; u8 local_1; u8 pad_0[6]; s16 local_2; u8 pad_1[2]; f32 local_3; u8 pad_2[4]; f32 local_4; } InfoBarDrawState;
extern void _fxdialog_entrypoint_3(void *, f32, s32, s32);
typedef struct { s32 (*local_0)(s32, u8 *, s32, s32); s32 local_1, local_2; } InfobarDrawCallbacks;
extern InfobarDrawCallbacks D_80800D54_scinfobar[];
int scinfobar_entrypoint_3();
void scinfobar_entrypoint_8();
void scinfobar_entrypoint_9();
void scinfobar_entrypoint_10();

void func_80800000_scinfobar(u8 *param_0, s32 param_1)
{
    f32 local_1;

    if (D_808008B0_scinfobar[param_1].local_1 != 0) {
        local_1 = D_808008B0_scinfobar[param_1].local_1 / 256.0f;
        param_0[0x32] = func_800E8B74(D_808008B0_scinfobar[param_1].local_0);
        if (D_808008B0_scinfobar[param_1].local_2 != NULL) {
            func_800E8D5C(param_0[0x32], D_808008B0_scinfobar[param_1].local_2, 0);
        }
        func_800E8D28(param_0[0x32], local_1);
    } else {
        param_0[0x32] = 0;
    }
}

void func_808000B0_scinfobar(void *param_0)
{
  s16 local_0;
  *((s16 *) (((s8 *) param_0) + 0x30)) = 0;
  *((s16 *) (((s8 *) param_0) + 0x2E)) = (local_0 = *((s16 *) (((s8 *) param_0) + 0x30)));
  *((s16 *) (((s8 *) param_0) + 0x2C)) = local_0;
}

void func_808000C4_scinfobar(u8 *param_0)
{
    *(s16 *)(param_0 + 4) = *(s16 *)(param_0 + 6);
    *(s16 *)(param_0 + 6) = -1;
    param_0[2] = 0;
    if (param_0[0x32]) {
        func_800E8C08(param_0[0x32]);
    }
    func_80800000_scinfobar(param_0, *(s16 *)(param_0 + 4));
    scinfobar_entrypoint_8(param_0, *(s16 *)(param_0 + 0x2C));
    scinfobar_entrypoint_9(param_0, *(s16 *)(param_0 + 0x2E));
    scinfobar_entrypoint_3(param_0, *(s16 *)(param_0 + 0x30));
    func_808000B0_scinfobar(param_0);
}

void func_80800144_scinfobar(u8 *param_0, s32 param_1)
{
    s32 local_0;

    if (param_1 == param_0[0]) {
        return;
    }
    if (param_0[2] != 0 && param_0[0] == param_0[2]) {
        func_808000C4_scinfobar(param_0);
    }
    param_0[0] = param_1;
    switch (param_1) {
        case 0x65:
            local_0 = param_0[2] ? *(s16 *)(param_0 + 0x30) : *(s32 *)(param_0 + 0x1C);
            if (D_80800D58_scinfobar[local_0].local_0 != NULL) {
                scinfobar_entrypoint_10(param_0, D_80800D58_scinfobar[local_0].local_0());
            }
            break;
        case 0x66:
            *(f32 *)(param_0 + 0x14) = 1.0f;
            break;
        case 0x67:
            break;
        case 0x64:
            *(f32 *)(param_0 + 0x14) = 0.0f;
            break;
    }
}

InfoBar *scinfobar_entrypoint_0(s32 param_0, s32 param_1, s32 param_2)
{
    InfoBar *local_0;
    local_0 = heap_alloc(sizeof(InfoBar));
    local_0->percent = 100;
    local_0->state = 0;
    local_0->id = param_0;
    local_0->index = -1;
    local_0->mode = param_1;
    local_0->active = 0;
    local_0->flag = 0;
    local_0->time = 0.0f;
    scinfobar_entrypoint_3((u8 *)local_0, param_2);
    scinfobar_entrypoint_10(local_0, 0xD8);
    local_0->second = 0;
    local_0->third = 0;
    local_0->first = 0;
    func_808000B0_scinfobar(local_0);
    func_80800000_scinfobar(local_0, param_0);
    return local_0;
}

void scinfobar_entrypoint_1(u8 *param_0) {
    u8 local_0 = param_0[0x32];
    if (local_0 != 0) {
        func_800E8C08(local_0);
    }
    heap_free(param_0);
}

void scinfobar_entrypoint_2(InfobarTransition *param_0)
{
    f32 local_0;
    local_0 = func_800D8FF8();
    switch (param_0->local_0) {
        case 0x64:
        case 0x66:
            break;
        case 0x65:
            param_0->local_2 += local_0 * param_0->local_3;
            if (param_0->local_2 > 1.0f) func_80800144_scinfobar(param_0, 0x66);
            break;
        case 0x67:
            param_0->local_2 -= local_0 * param_0->local_3;
            if (param_0->local_2 < 0.0f) func_80800144_scinfobar(param_0, 0x64);
            break;
    }
    param_0->local_1 = 0;
}

int scinfobar_entrypoint_3(param_0, param_1) u8 *param_0; s32 param_1;
{
  if (param_0[2])
  {
    *(s16*)((char*)param_0 + 0x30) = param_1;
  }
  else
  {
    *(s32*)((char*)param_0 + 0x1C) = param_1;
    *(f32*)((char*)param_0 + 0xC) = *(f32*)((char*)D_80800D5C_scinfobar + (param_1 * 3) * 4);
  }
}

void scinfobar_entrypoint_4(s32 param_0, s32 param_1)
{
  s32 local_0 = param_0;
  s32 local_1 = param_1;
  *(s32 *)(local_0 + 0x28) = local_1;
}

void scinfobar_entrypoint_5(void *arg, s32 v)
{
    ((s8 *)arg)[10] = v;
}

void scinfobar_entrypoint_6(u8 *param_0, s32 param_1)
{
    if (param_1 != 0) {
        if (*param_0 != 0x66) {
            func_80800144_scinfobar(param_0, 0x65);
        }
    } else if (*param_0 != 0x64) {
        func_80800144_scinfobar(param_0, 0x67);
    }
}

s32 scinfobar_entrypoint_7(u8 *param_0, int param_1)
{
  u8 temp_v0;
  s8 *new_var;
  if ((*((u8 *) (((s8 *) param_0) + 2))) != 0)
  {
    return 0;
  }
  if ((param_1 == (*((s16 *) (((s8 *) param_0) + 4)))) || (param_1 == (*((s16 *) (((s8 *) param_0) + 6)))))
  {
    return 1;
  }
  temp_v0 = *((u8 *) (((s8 *) param_0) + 0));
  new_var = ((s8 *) param_0) + 6;
  *((s16 *) new_var) = param_1;
  if ((temp_v0 == 0x66) || (temp_v0 == 0x65))
  {
    *((u8 *) (((s8 *) param_0) + 2)) = 0x67U;
  }
  else
  {
    *((u8 *) (((s8 *) param_0) + 2)) = 0x65U;
  }
  return 1;
}

void scinfobar_entrypoint_8(param_0, param_1) u8 *param_0; s32 param_1; {
    if (param_0[2]) {
        *(s16 *)(param_0 + 0x2c) = param_1;
        return;
    }
    *(s32 *)(param_0 + 0x20) = param_1;
}

void scinfobar_entrypoint_9(param_0, param_1) u8 *param_0; s32 param_1; {
    if (param_0[2]) {
        *(s16 *)(param_0 + 0x2E) = param_1;
        return;
    }
    *(s32 *)(param_0 + 0x24) = param_1;
}

void scinfobar_entrypoint_10(param_0, param_1) InfoBarRateRecord *param_0; s32 param_1;
{
    f32 local_0;

    param_0->unk10 = (f32)param_1 / (24.0f * param_0->unkC);
    param_0->unk8 = param_1;
    param_0->unk18 = 250.0f / (f32)param_1;
}

s32 scinfobar_entrypoint_11(u8 *param_0)
{
  return (s32) (((f32) (*((s16 *) (((char *) param_0) + 0x8)))) * (*((f32 *) (((char *) param_0) + 0x14))));
}

int scinfobar_entrypoint_12(param_0) s16 param_0[5];
{
  return param_0[4];
}

f32 scinfobar_entrypoint_13(void *arg)
{
    return ((f32 *)arg)[5];
}

int scinfobar_entrypoint_14(void *param_0)
{
    return ((int *)param_0)[0x28 / 4];
}

scinfobar_entrypoint_15(u8 *param_0) {
    return param_0[1];
}

int scinfobar_entrypoint_16(param_0) s16 param_0[5];
{
  return param_0[2];
}

scinfobar_entrypoint_17(u8 *param_0) {
    return param_0[10];
}

f32 scinfobar_entrypoint_18(Actor *param_0)
{
  return (*(f32 *)((char *)(param_0) + 0xC));
}

int scinfobar_entrypoint_19(void *param_0)
{
  return (*(s32 *)((char *)(param_0) + 0x20));
}

int scinfobar_entrypoint_20(void *param_0)
{
  return (*(s32 *)((char *)(param_0) + 0x24));
}

int scinfobar_entrypoint_21(u8 *param_0) {
    return param_0[0] == 'd';
}

s32 scinfobar_entrypoint_22(u8 *param_0)
{
  u8 v0;
  return (*param_0) == 0x66;
}

s32 scinfobar_entrypoint_23(u8 *self)
{
  u8 local_0 = *self;
  s32 local_1 = (((((local_0 & 0xFFFFFFFF) & 0xFFFFFFFF) & 0xFFFFFFFF) & 0xFFFFFFFF) & (0xFFFFFFFF & 0xFF)) == 0x65;
  s32 new_var;
  new_var = local_1;
  return new_var;
}

void func_80800608_scinfobar(s32 param_0, s32 param_1, s32 param_2, s32 param_3, s32 param_4, s32 param_5)
{
    InfoBarDialog *local_0;
    s32 local_1;

    if (param_1 >= 0 && param_1 < 100 && param_1 != 0) {
        local_0 = &((InfoBarDialog *)D_808008B0_scinfobar)[param_1];
        if (local_0->local_3 != 0) {
            _fxdialog_entrypoint_2(local_0->local_3 * (1.0f / 256.0f));
        }
        local_1 = param_5 ? func_800E8C58((u8)param_5) : 0;
        _fxdialog_entrypoint_4(param_0, local_0->local_0, local_1, (f32)local_0->local_1, (f32)local_0->local_2, param_4, (u32)local_0->local_4 >> 15);
    }
}

void func_808006EC_scinfobar(void *param_0, InfoBarDrawState *param_1, s32 param_2, s32 param_3)
{
    _fxdialog_entrypoint_0();
    _fxdialog_entrypoint_1(param_2, param_3);
    _fxdialog_entrypoint_2(param_1->local_3);
    _fxdialog_entrypoint_3(param_0,
        param_1->local_4 * param_1->local_2, param_1->local_1, 0xFF);
}

void scinfobar_entrypoint_24(s32 param_0, u8 *param_1, s32 param_2, s32 param_3)
{
    s32 local_0;
    s32 (*local_1)(s32, u8 *, s32, s32);
    func_808006EC_scinfobar(param_0, param_1, param_2, param_3);
    if (param_1[0] != 100) {
        local_1 = D_80800D54_scinfobar[*(s32 *)(param_1 + 0x1C)].local_0;
        if (local_1) local_1(param_0, param_1, param_2, param_3);
    }
    if (param_1[2] && param_1[0] == param_1[2]) {
        local_0 = *(f32 *)(param_1 + 0x14) * 255.0f;
        if (param_1[2] == 101) local_0 = 255 - local_0;
        func_80800608_scinfobar(param_0, *(s16 *)(param_1 + 4), param_2, param_3, local_0, param_1[0x32]);
        func_80800608_scinfobar(param_0, *(s16 *)(param_1 + 6), param_2, param_3, 255 - local_0, 0);
        return;
    }
    func_80800608_scinfobar(param_0, *(s16 *)(param_1 + 4), param_2, param_3, 255, param_1[0x32]);
}
