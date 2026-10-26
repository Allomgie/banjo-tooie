#include "common.h"

typedef union { s32 local_0; s16 local_1[2]; } ChuffyControlEvent;
extern void _gcnewoption_entrypoint_0(void *);
extern void func_8010A828();
typedef struct { s16 local_0; s16 local_1; s16 local_2; s16 pad_0[2]; } ChuffyStationRecord;
extern ChuffyStationRecord D_80800B20_chchuffycont[];
extern ChuffyStationRecord D_80800B66_chchuffycont[];
typedef struct { s16 unused0; s16 destination; s16 unused4; s16 prerequisite; s16 unused8; } ChuffyTravelRecord;
typedef struct { s16 map; s16 flag; u8 pad4[6]; } ChuffyStop;
extern u8 D_8012762C;
extern s32 func_800EA05C(void);
extern s32 func_800DA298(s32);
extern void func_800A7A5C(void);
extern s32 _gcsectionDll_entrypoint_4(s32);
extern void func_800A8230(void);
extern void func_800DA3B8(s32, s32);
typedef struct { s16 local_0; s16 local_1; s16 local_2[3]; } TrainStop62;
extern int D_80800B78_chchuffycont;
extern int D_80800B68_chchuffycont;
extern int D_80800B84_chchuffycont;
typedef struct { s16 a; s16 b; s16 pad[3]; } ChuffEnt;
s32 func_8080046C_chchuffycont();

extern void *func_80100094(Actor *, u32);
extern void _gcnewoption_entrypoint_35();
extern void _gcnewoption_entrypoint_14(void *, s32, s32, s32, f32);
extern void _gcnewoption_entrypoint_40(void *, s32, s32, s32, f32, f32);
extern void _gcnewoption_entrypoint_42(void *, f32);
extern void _gcnewoption_entrypoint_10();
extern void _gcnewoption_entrypoint_11();
extern void _gcnewoption_entrypoint_4();
extern void _gcnewoption_entrypoint_8();
extern void _gcnewoption_entrypoint_9();
extern void _subaddiedialog_entrypoint_11();
extern void func_80090708();
extern void func_80102424();
void func_80800440_chchuffycont();
void func_80800494_chchuffycont();
void func_80800620_chchuffycont();
int func_808006A4_chchuffycont();
s32 func_8080070C_chchuffycont();
void func_80800768_chchuffycont();
void func_80800A7C_chchuffycont();
void func_80800000_chchuffycont();
extern void func_80105834(), func_80107C2C(), func_80800440_chchuffycont(), func_80800768_chchuffycont();

void func_80800000_chchuffycont(param_0, param_1) Actor *param_0; s32 param_1;
{
    s32 local_0;
    void *local_1;
    s32 local_2;

    if (param_0->unk70_10 == 5) {
        _gcnewoption_entrypoint_6(param_0, 1);
        func_80090708(0);
        func_8010A828(param_0, 2);
    }
    func_80102424(param_0, param_1);
    switch (param_0->unk70_10) {
    case 2:
        _subaddiedialog_entrypoint_11(param_0->unk0, 0xF96, 0xE, &param_0->position, 0x42);
        break;
    case 3:
        _subaddiedialog_entrypoint_11(param_0->unk0, 0xD80, 0xE, &param_0->position, 0x42);
        break;
    case 6:
        _subaddiedialog_entrypoint_11(param_0->unk0, 0x12C5, 0xE, &param_0->position, 0x42);
        break;
    case 5:
        local_0 = func_8080070C_chchuffycont(param_0);
        _gcnewoption_entrypoint_4(param_0, 1, _gcnewoption_entrypoint_35, 0, 0x184B);
        local_1 = func_80100094(param_0, 1);
        func_80090708(2);
        _gcnewoption_entrypoint_8(local_1, local_0 >= 6 ? 5 : local_0);
        _gcnewoption_entrypoint_9(local_1, local_0);
        _gcnewoption_entrypoint_10(local_1, 0);
        func_8080046C_chchuffycont(param_0, local_1);
        _gcnewoption_entrypoint_14(local_1, 0, 1, 3, 4.0f);
        _gcnewoption_entrypoint_40(local_1, 0x41, 0x22, 0x20, 0.8f, 1.0f);
        _gcnewoption_entrypoint_42(local_1, 0.1f);
        _gcnewoption_entrypoint_11(local_1);
        func_8010A828(param_0, 10);
        break;
    }
}

s32 func_808001F8_chchuffycont(Actor *param_0, s32 param_1, ChuffyControlEvent param_2)
{
    s32 local_0;

    switch (param_1) {
    case 0x91:
        param_0->unk64_19 = 1;
        break;
    case 0x20:
        local_0 = func_80101080();
        switch (param_2.local_1[1]) {
        case 3:
            func_80800620_chchuffycont(param_0, param_2.local_1[0]);
            func_80800000_chchuffycont(param_0, 1);
            break;
        case 0:
            func_80800494_chchuffycont(param_0, local_0);
            break;
        case 2:
            func_80800000_chchuffycont(param_0, 1);
            break;
        }
        break;
    case 0x2E:
        func_80800000_chchuffycont(param_0, 1);
        break;
    default:
        return 0;
    }
    return 1;
}

void func_808002C4_chchuffycont(Actor *param_0)
{
    func_80800A7C_chchuffycont(param_0);
    switch (param_0->unk70_10) {
    case 1:
        if (!func_800DA298(0x66D) && !func_800DA298(0x86) && func_8010CAC0(param_0->position, 250)) {
            _subaddiedialog_entrypoint_11(param_0->unk0, 0xFAC, 0xE, 0, 0x42);
            func_800DA544(0x66D);
        }
        if (param_0->unk64_19 && _subaddiedialog_entrypoint_4(param_0->position, 100, 0)) {
            if (!func_800DA298(0x86)) {
                param_0->unk74_30 = 0;
                func_80800000_chchuffycont(param_0, 2);
            } else if (func_8080070C_chchuffycont(param_0) <= 0) {
                param_0->unk74_30 = 0;
                func_80800000_chchuffycont(param_0, 3);
                if (param_0) {}
                break;
            } else func_80800000_chchuffycont(param_0, 5);
        }
        break;
    case 5: _gcnewoption_entrypoint_0(func_80100094(param_0, 1)); break;
    }
    if (param_0->unk64_19) param_0->unk64_19 = 0;
}

void func_80800440_chchuffycont(param_0) u8 *param_0; {
    *(f32 *)(param_0 + 0x38) = 0.5f;
    func_8010A828(param_0, 2);
}

s32 func_8080046C_chchuffycont(s32 param_0, s32 param_1){
    _gcnewoption_entrypoint_32(param_1, 0x42);
}

void func_80800494_chchuffycont(param_0, param_1) s32 param_0; s32 param_1;
{
  s32 local_0;
  s32 local_1;

  local_1 = 0;
  local_0 = 0;
  do {
    if (func_808006A4_chchuffycont(local_0) != 0) {
      _gcnewoption_entrypoint_12(param_1, local_1, (s16) (local_0 + 0xA));
      _gcnewoption_entrypoint_31(param_1, local_1, *(s16 *)((char *)((s32 *) D_80800B20_chchuffycont) + (local_0 * 0xA) + 8));
      local_1 += 1;
    }
    local_0 += 1;
  } while (local_0 != 7);
}

void func_80800540_chchuffycont(Actor *param_0, s32 param_1)
{
    ChuffyStationRecord *local_0;
    s32 local_1;

    local_0 = &D_80800B20_chchuffycont[param_1];
    if (local_0->local_0 == 0x12A && !func_800DA298(0x171)) {
        func_80800000_chchuffycont(param_0, 6);
        return;
    }
    func_800DA544(local_0->local_2);
    for (local_1 = 0; local_1 < 7; local_1++) {
        if (func_800DA298(D_80800B20_chchuffycont[local_1].local_1)) break;
    }
    local_0 = &D_80800B20_chchuffycont[local_1];
    if (local_0->local_0 == 0xEC) func_800DA544(0x6E7);
    _glcutDll_entrypoint_0();
    _glcutDll_entrypoint_7(local_0->local_0);
    _glcutDll_entrypoint_10(0xD0);
    _glcutDll_entrypoint_22(0x6F);
    _glcutDll_entrypoint_16();
}

void func_80800620_chchuffycont(param_0, param_1) s32 param_0; s32 param_1;
{
  s32 var_s0;
  s32 var_s1;
  var_s1 = 0;
  var_s0 = 0;
 if (1) { } if (1) { } if (1) { } if (1) { } if (1) { } if (1) { }
  loop_1:
  if (func_808006A4_chchuffycont(var_s0) != 0)
  {
    if (var_s1 == param_1)
    {
      func_80800540_chchuffycont(param_0, var_s0);
      return;
    }
    var_s1 += 1;
    goto block_5;
  }

  block_5:
  var_s0 += 1;

  if (var_s0 == 7)
  {
    return;
  }
  goto loop_1;
}

int func_808006A4_chchuffycont(param_0) s32 param_0;
{
    return (((ChuffyTravelRecord *) D_80800B20_chchuffycont)[param_0].prerequisite == -1 ||
        func_800DA298(((ChuffyTravelRecord *) D_80800B20_chchuffycont)[param_0].prerequisite)) &&
        !func_800DA298(((ChuffyTravelRecord *) D_80800B20_chchuffycont)[param_0].destination);
}

s32 func_8080070C_chchuffycont(param_0) void *param_0;
{
  s32 local_0;
  s32 local_1;
  local_1 = (local_1 = 0);
  for (local_0 = 0, local_1; local_0 < 7; local_0++)
  {
    if (func_808006A4_chchuffycont(local_0))
    {
      local_1++;
    }
  }

  return local_1;
}

void func_80800768_chchuffycont(param_0, param_1) s32 param_0; s32 param_1;
{
    if (func_800EB854() == 3) {
        s32 local_0 = func_80100094(param_0, 1);
        if (local_0 != 0) {
            _gcnewoption_entrypoint_1(local_0, param_1);
        }
    }
    else {
        func_80101870(param_0, param_1);
    }
}

s32 chchuffycont_entrypoint_0(s32 *param_0, s32 *param_1)
{
    s32 i;
    s32 j;
    s32 local_0;
    s32 local_1;

    if (func_800EA05C() == 0xD0) {
        for (i = 0; i < 7; i++) {
            if (func_800DA298(((ChuffyStop *) D_80800B20_chchuffycont)[i].flag)) {
                break;
            }
        }
        *param_0 = ((ChuffyStop *) D_80800B20_chchuffycont)[i].map;
        *param_1 = 2;
        if (func_800DA298(0x66B)) {
            func_800A7A5C();
        } else {
            local_0 = _gcsectionDll_entrypoint_4(*param_0);
            if (_gcsectionDll_entrypoint_4(0xD0) != local_0) {
                func_800A8230();
            }
        }
        func_800DA3B8(0x66B, 0);
        return 1;
    }
    local_1 = func_800EA05C();
    for (j = 0; j < 7; j++) {
        if (local_1 == ((ChuffyStop *) D_80800B20_chchuffycont)[j].map) {
            break;
        }
    }
    if (func_800DA298(((ChuffyStop *) D_80800B20_chchuffycont)[j].flag)) {
        *param_0 = 0xD0;
        *param_1 = 1;
        if (_gcsectionDll_entrypoint_4(0xD0) != D_8012762C) {
            func_800A8230();
        }
        return 1;
    }
    return 0;
}

s32 chchuffycont_entrypoint_1(s32 *param_0, s32 *param_1)
{
    s32 local_0;
    s32 local_1;
    TrainStop62 *local_2;
    TrainStop62 *local_4;
    u8 *local_5;
    u8 *local_6;
    s32 local_3;

    local_0 = func_800EA05C();
    local_1 = 0;
    if (local_0 == 0x121) {
        if (!func_800DA298(0x95)) {
            *param_0 = 0xD7;
            *param_1 = 3;
        } else {
            local_2 = ((TrainStop62 *) D_80800B20_chchuffycont); local_5 = ((u8 *) D_80800B66_chchuffycont);
            do {
                if (func_800DA298(local_2->local_1)) break;
                local_2++;
            } while ((u8 *)local_2 != local_5);
            *param_0 = local_2->local_0;
            *param_1 = 3;
        }
        local_3 = _gcsectionDll_entrypoint_4(*param_0);
        if (_gcsectionDll_entrypoint_4(0x121) != local_3) func_800A8230();
        local_1 = 1;
    } else {
        local_4 = ((TrainStop62 *) D_80800B20_chchuffycont); local_6 = ((u8 *) D_80800B66_chchuffycont);
        do {
            if (local_4->local_0 == local_0) break;
            local_4++;
        } while ((u8 *)local_4 != local_6);
        if (func_800DA298(local_4->local_1) || (local_0 == 0xD7 && !func_800DA298(0x95))) {
            *param_0 = 0x121;
            *param_1 = 1;
            local_1 = 1;
            if (_gcsectionDll_entrypoint_4(0x121) != D_8012762C) func_800A8230();
        }
    }
    return local_1;
}

void func_80800A7C_chchuffycont(param_0) int param_0;
{
  int *new_var3;
  int *new_var2;
  int new_var;
  new_var2 = (new_var3 = &D_80800B68_chchuffycont);
  _subaddieaudioloop_entrypoint_4(param_0, &D_80800B78_chchuffycont, 1, new_var2);
  new_var = 0;
}

int chchuffycont_entrypoint_2()
{
  return (int)&D_80800B84_chchuffycont;
}

void chchuffycont_entrypoint_3(void) {
    s32 i;
    for (i = 0; i < 7; i++) {
        if (func_800DA298(((ChuffEnt *) D_80800B20_chchuffycont)[i].b)) {
            break;
        }
    }
    _gcsectionDll_entrypoint_4(((ChuffEnt *) D_80800B20_chchuffycont)[i].a);
}
