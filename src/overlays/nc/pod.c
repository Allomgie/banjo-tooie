#include "common.h"

extern void _glcutDll_entrypoint_6(int a, int b);
extern int func_800EA05C(void);
typedef struct { s16 local_0[3]; u8 pad_0[2]; s32 local_1; s32 local_2; s32 local_3; s32 local_4; f32 local_5[3]; f32 local_6[3]; f32 local_7; f32 local_8; s32 local_9; s16 local_10; u8 local_11[6]; f32 local_12; f32 local_13; } PodInitialState;
extern f32 func_800C517C(s32);
extern f32 func_800C5190(s32);
typedef struct PodRangeFlags { u32 pad_0 : 12; u32 local_0 : 1; u32 pad_1 : 19; } PodRangeFlags;
extern void func_800C5148(s32, f32);
extern void func_800C51A4(s32, f32);
struct NCPod { u16 unk3A; };
extern u8 unk38[];
typedef struct { u8 pad_0[2]; s16 local_0; u8 pad_1[0x38]; s16 local_1; } PodEventState;
typedef struct PodDispatchState { u8 pad_0[8]; u8 *local_0; s32 local_1; } PodDispatchState;
extern void func_80101074(s32);
extern int func_800A940C(s32);
extern s32 func_800C52F4(s32, s32);
extern s32 func_800C53EC(s32, s32);
typedef struct { u8 pad[0x3E]; u32 unk3E : 8; u32 pad2 : 24; } PodFlags;
extern void *func_80110024();
extern void func_80015178();
extern void func_8010F9C0();
s32 ncpod_entrypoint_2();
void ncpod_entrypoint_12();
void ncpod_entrypoint_15();
int ncpod_entrypoint_17();
void ncpod_entrypoint_19();

void func_80800000_ncpod(arg0) u8 *arg0; {
    if (arg0[0x42] == 0) {
        arg0[0x42] = 1;
        func_800F82D4(*(s32 *)(arg0 + 0x38), 2);
  }
}

void func_80800038_ncpod(s32 param_0)
{
    if (*(u8 *)((u8 *)param_0 + 0x42) != 0)
    {
        *(u8 *)((u8 *)param_0 + 0x42) = 0;
        func_800F82D4(*(s32 *)((u8 *)param_0 + 0x38), 0);
    }
}

void func_8080006C_ncpod(void *param_0)
{
    if (!(*(int *)((char *)param_0 + 0x10) & 0x800))
    {
        *(unsigned char *)((char *)param_0 + 0x43) = 1;
        _glcutDll_entrypoint_6(func_800EA05C() | 0, 0x79);
    }
}

int func_808000AC_ncpod(u8 *param_0)
{
  if (param_0[0x43])
  {
    _glcutDll_entrypoint_17(param_0);
    param_0[0x43] = 0;
  }
}

s16 ncpod_entrypoint_0(s32 param_0)
{
    s16 local_0;
    PodInitialState *local_1;
    s32 local_2;
    local_0 = func_8001B668(0, 0x4C);
    local_1 = ncpod_entrypoint_2(local_0);
    local_2 = func_800A940C(param_0);
    local_1->local_0[0] = 0;
    local_1->local_0[1] = 0;
    local_1->local_0[2] = 0;
    local_1->local_1 = 0;
    local_1->local_2 = -1;
    func_800EFD24(local_1->local_5);
    func_800EFD24(local_1->local_6);
    local_1->local_8 = 1.0f;
    local_1->local_7 = 40.0f;
    local_1->local_4 = func_80015184();
    local_1->local_11[0] = 0;
    local_1->local_11[4] = 0;
    local_1->local_11[2] = 0;
    local_1->local_11[5] = 0;
    local_1->local_10 = 0;
    local_1->local_9 = param_0;
    local_1->local_3 = 0;
    local_1->local_11[3] = 0;
    local_1->local_12 = func_800C517C(local_2);
    local_1->local_13 = func_800C5190(local_2);
    return local_0;
}

void ncpod_entrypoint_1(param_0) s16 param_0;
{
    u8 *local_0;
    s32 local_1;

    local_0 = (u8 *)ncpod_entrypoint_2(param_0);
    local_1 = func_800A940C(*(s32 *)(local_0 + 0x38));
    ncpod_entrypoint_12(local_0, 0);
    if (local_0[0x3E]) {
        ncpod_entrypoint_15(local_0, 0, (*(u32 *)(local_0 + 0x10) & 0x4000) ? 0 : 1);
    }
    if (!(*(u32 *)(local_0 + 0x10) & 0x8000)) {
        func_800C5148(local_1, (*(u32 *)(local_0 + 0x10) & 0x80000) ? 40.0f : *(f32 *)(local_0 + 0x44));
        func_800C51A4(local_1, (*(u32 *)(local_0 + 0x10) & 0x80000) ? 1.0f : *(f32 *)(local_0 + 0x48));
    }
    func_80015178(*(s32 *)(local_0 + 0x14));
    func_808000AC_ncpod(local_0);
    func_8001B754(param_0);
}

s32 ncpod_entrypoint_2(param_0) s16 param_0;{
    s32 temp = param_0;
    func_8001B798(temp);
}

void ncpod_entrypoint_3(param_0, param_1)
struct NCPod *param_0;
int param_1;
{
  *((u16 *) (((char *) param_0) + 60)) = param_1;
 param_1++; param_1--;
}

int ncpod_entrypoint_4(Actor *param_0) {
    return (*(s32 *)((char *)(param_0) + 0x38));
}

int func_808002E8_ncpod(param_0, param_1) u16 *param_0; u32 param_1;
{
    s32 ret;
    if (param_1 == -1) {
        ret = 0;
    } else {
        ret = (param_1 == ((u32)*(u16 *)(param_0 + 9) >> 1));
    }
    return ret;
}

s32 func_80800314_ncpod(s32 param_0, PodEventState *param_1, s32 param_2, s32 param_3, s32 param_4)
{
    s32 local_0;

    switch (param_1->local_1) {
    case 0:
        break;
    case 1:
        local_0 = _ncpoducam_entrypoint_5(_ncpoducam_entrypoint_1(param_1->local_0));
        if (param_2 == 11) {
            if (local_0 & 0x100) _glcutDll_entrypoint_17();
            if (!(local_0 & 0x20)) return ncpod_entrypoint_17(param_0, 0);
            return 3;
        }
        break;
    case 6:
        return _gcdialogcamera_entrypoint_1(param_2, param_3, param_4);
    case 11:
        break;
    default:
        break;
    }
    return -1;
}

s32 ncpod_entrypoint_5(s32 param_0, PodDispatchState *param_1, s32 param_2, s32 param_3, s32 param_4)
{
    s32 local_0;

    if (func_808002E8_ncpod(param_1->local_0, param_1->local_1)) {
        if (*(u16 *)(param_1->local_0 + 0x18) & 1) {
            func_80101074(param_4);
            local_0 = func_8010114C(param_1->local_0, param_2, param_3);
            switch (local_0) {
                case 4:
                    return 4;
                case 5:
                    return local_0;
            }
            local_0 = func_80800314_ncpod(param_0, param_1, param_2, param_3, param_4);
            if (local_0 == 4) {
                return 4;
            }
            return local_0;
        }
    } else {
        return func_80800314_ncpod(param_0, param_1, param_2, param_3, param_4);
    }
    return -1;
}

s32 ncpod_entrypoint_6(s32 param_0, u8 *param_1, s32 param_2, s32 param_3, s32 param_4) {
    if ((func_808002E8_ncpod((*(u8 **)((s8 *)(param_1) + (8))), (*(s32 *)((s8 *)(param_1) + (0xC)))) != 0) && ((*(u16 *)((s8 *)((*(u8 **)((s8 *)(param_1) + (8)))) + (0x18))) & 1)) {
        func_80101074(param_4);
        return func_8010114C((*(u8 **)((s8 *)(param_1) + (8))), param_2, param_3);
    }
    return -1;
}

void ncpod_entrypoint_7(u8 *param_0, u8 *param_1)
{
  *((u8 **) (((u8 *) param_0) + 8)) = param_1;
  *((u32 *) (((u8 *) param_0) + 0xC)) = (u32) (((((((((((u16) (*((u16 *) (((u8 *) param_1) + 0x12)))) & 0xFFFFFFFF) & 0xFFFFFFFF) & 0xFFFFFFFF) & 0xFFFFFFFF) & 0xFFFFFFFF) & 0xFFFFFFFF) & 0xFFFFFFFF) & 0xFFFFFFFF) >> 1);
}

void ncpod_entrypoint_8(s32 param_0, s32 param_1, s32 param_2)
{
    func_800EE7F8(param_0 + 0x18, param_1);
    func_800EE7F8(param_0 + 0x24, param_2);
    *(s8 *)(param_0 + 0x40) = 1;
}

void ncpod_entrypoint_9(void *param_0, f32 param_1)
{
  *(f32 *)((char *)param_0 + 0x30) = param_1;
}

f32 ncpod_entrypoint_10(void *arg)
{
    return ((f32 *)arg)[12];
}

int ncpod_entrypoint_11(f32 *param_0, f32 param_1)
{
  param_0[13] = param_1;
}

void ncpod_entrypoint_12(param_0, param_1) u8 *param_0; s32 param_1;
{
  s32 temp_v0_2;
  u8 temp_v0;
  s32 *new_var;
  temp_v0 = *((u8 *) (((s8 *) param_0) + 0x41));
  switch (temp_v0)
  {
    case 1:
      _ncpoddialog_entrypoint_3(*((s16 *) (((s8 *) param_0) + 0)));
      *((s16 *) (((s8 *) param_0) + 0)) = 0;
      break;

    case 2:
      _ncpoducam_entrypoint_6(*((s16 *) (((s8 *) param_0) + 2)));
      *((s16 *) (((s8 *) param_0) + 2)) = 0;
      break;

    case 3:
      _ncpodfixpos_entrypoint_1(*((s16 *) (((s8 *) param_0) + 4)));
      *((s16 *) (((s8 *) param_0) + 4)) = 0;
      break;

  }

  temp_v0_2 = 0xFF;
  temp_v0_2 = param_1 & temp_v0_2;
  new_var = &param_1;
  *((u8 *) (((s8 *) param_0) + 0x41)) = (u8) (*new_var);
  switch (temp_v0_2)
  {
    case 1:
      *((s16 *) (((s8 *) param_0) + 0)) = _ncpoddialog_entrypoint_2();
      return;

    case 2:
      *((s16 *) (((s8 *) param_0) + 2)) = _ncpoducam_entrypoint_0();
      return;

    case 3:
      *((s16 *) (((s8 *) param_0) + 4)) = _ncpodfixpos_entrypoint_0();
      return;

  }

}

int ncpod_entrypoint_13(u8 *param_0) {
    return param_0[0x41];
}

void ncpod_entrypoint_14(param_0, param_1) s16 param_0; s32 param_1;
{
    u8 *local_0;
    s32 local_1;
    s32 local_2;

    local_0 = (u8 *)ncpod_entrypoint_2(param_0);
    local_1 = 2;
    switch (local_0[0x41]) {
        case 0: break;
        case 1: local_1 = _ncpoddialog_entrypoint_1(*(s16 *)local_0, param_1); break;
        case 2: local_1 = _ncpoducam_entrypoint_7(*(s16 *)(local_0 + 2), param_1); break;
        case 3: local_1 = _ncpodfixpos_entrypoint_6(*(s16 *)(local_0 + 4), param_1); break;
    }
    if (local_1 != 4 && local_0[0x40]) {
        local_2 = func_800A940C(*(s32 *)(local_0 + 0x38));
        func_8010FE14(param_1, local_0 + 0x18, local_0 + 0x24);
        func_800C5148(local_2, *(f32 *)(local_0 + 0x30));
        if (*(f32 *)(local_0 + 0x30) == 40.0f && *(f32 *)(local_0 + 0x34) != 1.0f) {
            func_800C51A4(local_2, *(f32 *)(local_0 + 0x34));
        } else {
            func_800C51A4(local_2, 1.0f);
        }
    }
}

void func_808007D8_ncpod(param_0, param_1) u8 *param_0; s32 param_1; {
    s32 local_0;
    s32 local_1;
    s32 local_2;

    if (param_1 & 0x10) {
        func_80800000_ncpod();
    } else {
        func_80800038_ncpod(param_0);
    }
    if (param_1 & 0x60000) {
        if (param_1 & 0x40000) {
            local_0 = 4;
        } else if (param_1 & 0x20000) {
            local_0 = 3;
        } else {
            local_0 = *(s32 *)((char *)param_0 + 0x14);
        }
        func_80015178(local_0, param_1);
    }
    if (param_1 & 4) {
        if (param_1 & 0x4000) {
            local_1 = 0;
        } else {
            local_1 = 1;
        }
        ncpod_entrypoint_15(param_0, 0, local_1);
        return;
    }
    if (param_1 & 0x2000) {
        local_2 = 0;
    } else {
        local_2 = 1;
    }
    ncpod_entrypoint_15(param_0, 1, local_2);
}

void ncpod_entrypoint_15(param_0, param_1, param_2) u8 *param_0; s32 param_1; s32 param_2;
{
    s32 local_0;

    if (param_1 != ((PodFlags *)param_0)->unk3E) {
        if (param_1) {
            local_0 = func_800A940C(*(s32 *)(param_0 + 0x38));
            func_800C52F4(local_0, param_2 ? 2 : 0);
        } else {
            local_0 = func_800A940C(*(s32 *)(param_0 + 0x38));
            func_800C53EC(local_0, param_2 ? 2 : 0);
        }
        ((PodFlags *)param_0)->unk3E = param_1;
    }
}

int ncpod_entrypoint_16(s32 param_0, s32 param_1, s32 param_2, s32 param_3)
{
  s32 local_0;
  if (func_8010FAE4(param_0) == 8)
  {
    return 0;
  }
  func_8010F9C0(param_0, 8);
  local_0 = func_80110024(param_0);
  ncpod_entrypoint_3(local_0, param_2);
  if (param_1 != 0)
  {
    ncpod_entrypoint_7(local_0, param_1);
  }
  ncpod_entrypoint_19(local_0, param_3);
  func_8080006C_ncpod(local_0);
  return 1;
}

int ncpod_entrypoint_17(param_0, param_1) s32 param_0; s32 param_1;
{
    u8 *local_0;
    s32 local_1;
    s32 local_2;
    local_0 = func_80110024();
    local_1 = func_800A940C(*(s32 *)(local_0 + 0x38));
    ncpod_entrypoint_12(local_0, 0);
    if (!param_1 && !(*(u32 *)(local_0 + 0x10) & 0x8000)) {
        ncpod_entrypoint_15(local_0, 0, (*(u32 *)(local_0 + 0x10) & 0x4000) ? 0 : 1);
        func_800C5148(local_1, (*(u32 *)(local_0 + 0x10) & 0x80000) ? 40.0f : *(f32 *)(local_0 + 0x44));
        func_800C51A4(local_1, (*(u32 *)(local_0 + 0x10) & 0x80000) ? 1.0f : *(f32 *)(local_0 + 0x48));
    }
    if (*(u32 *)(local_0 + 0x10) & 0x10) { func_80800038_ncpod(local_0); }
    func_808000AC_ncpod(local_0);
    if (param_1) { *(u32 *)(local_0 + 0x10) |= 0x8000; }
    func_80015178(*(s32 *)(local_0 + 0x14));
    if (*(u32 *)(local_0 + 0x10) & 0x200) { local_2 = 0x200; }
    else if (*(u32 *)(local_0 + 0x10) & 0x10000) { local_2 = 0x10000; }
    else { local_2 = 0; }
    func_8010F9C0(param_0, 2);
    if (local_2 == 0x200) { func_801108A0(func_80110014(param_0)); }
    else if (local_2 == 0x10000) { func_80110928(func_80110014(param_0)); }
    if (!param_1) { func_8010FD88(param_0); }
    return 4;
}

s16 ncpod_entrypoint_18(void) {
    u8 *temp_v0;

    temp_v0 = func_80110024();
    if (temp_v0 == NULL) {
        return -1;
    }
    return (*(s16 *)((s8 *)temp_v0 + 0x3C));
}

void ncpod_entrypoint_19(param_0, param_1) void *param_0; s32 param_1;
{
    func_808007D8_ncpod();
    *(s32 *)((char *)param_0 + 0x10) = param_1;
}

s32 ncpod_entrypoint_20(s32 param_0, s32 param_1, s32 param_2, s32 param_3)
{
  s32 local_0;
  s32 local_1;
  local_0 = func_80110024();
  ncpod_entrypoint_12(local_0, 2);
  local_1 = _ncpoducam_entrypoint_1(*(s16 *)(local_0 + 2));
  _ncpoducam_entrypoint_4(local_1, param_3);
  ncpod_entrypoint_19(local_0, param_3);
  if (param_1 != 0)
  {
    _ncpoducam_entrypoint_3(local_1, param_1);
  }
  _ncpoducam_entrypoint_2(local_1, param_0, param_2);
  func_8010FD88(param_0);
  return 4;
}

void ncpod_entrypoint_21(s32 param_0, s32 param_1, s32 param_2)
{
  _ncpoddialog_entrypoint_9(_ncpoddialog_entrypoint_0(*(s16 *)func_80110024()), param_0, param_1, param_2);
}

int ncpod_entrypoint_22(s16 *param_0, s32 param_1, s32 param_2)
{
  _ncpoddialog_entrypoint_4(_ncpoddialog_entrypoint_0(*param_0) | 0, param_1, param_2);
}

int ncpod_entrypoint_23(s16 *param_0, s32 param_1, s32 param_2)
{
  s32 local_0;
  local_0 = _ncpoddialog_entrypoint_0(*param_0);
  _ncpoddialog_entrypoint_5(local_0 | 0, param_1, param_2);
}

int ncpod_entrypoint_24(s16 *param_0, s32 param_1, s32 param_2)
{
  u32 local_0;
  local_0 = _ncpoddialog_entrypoint_0(*param_0);
  _ncpoddialog_entrypoint_6(local_0 | 0, param_1, param_2);
}

int ncpod_entrypoint_25(s16 *param_0, s32 param_1)
{
  _ncpoddialog_entrypoint_7(_ncpoddialog_entrypoint_0(*param_0) | 0, param_1);
}

s32 ncpod_entrypoint_26(s32 param_0, s32 param_1, s32 param_2, s32 param_3, s32 param_4)
{
    s32 local_0;
    s32 local_1;

    if (!ncpod_entrypoint_16(param_0, 0, 1, param_4)) return 0;
    local_0 = func_80110024(param_0);
    ncpod_entrypoint_12(local_0, 2);
    if (param_2) ncpod_entrypoint_7(local_0, param_2);
    else if (param_1) ncpod_entrypoint_7(local_0, param_1);
    local_1 = _ncpoducam_entrypoint_1(*(s16 *)(local_0 + 2));
    if (param_1) _ncpoducam_entrypoint_3(local_1, param_1);
    _ncpoducam_entrypoint_4(local_1, param_4);
    _ncpoducam_entrypoint_2(local_1, param_0, param_3);
    func_8010FD88(param_0);
    return 1;
}

int ncpod_entrypoint_27(s32 param_0, s32 param_1)
{
  s32 local_0;
  s32 local_1;
  local_0 = func_80110024(param_0);
  local_1 = ncpod_entrypoint_17(param_0, param_1);
  func_8010F9C0(param_0, 2);
  return local_1;
}

int ncpod_entrypoint_28(s32 param_0, s32 param_1)
{
    u32 local_0;
    local_0 = func_80110024(param_0);
    _ncpoducam_entrypoint_8(_ncpoducam_entrypoint_1(*(s16 *)((char *)local_0 + 2)), param_1);
}

int ncpod_entrypoint_29(s32 param_0, s32 param_1)
{
    u32 local_0;
    local_0 = func_80110024(param_0);
    _ncpoducam_entrypoint_9(_ncpoducam_entrypoint_1(*(s16 *)((char *)local_0 + 2)), param_1);
}

int ncpod_entrypoint_30()
{
  _ncpoducam_entrypoint_10(_ncpoducam_entrypoint_1(((s16 *)func_80110024())[1]));
}

int ncpod_entrypoint_31(s32 param_0, s32 param_1)
{
    u32 local_0;
    local_0 = func_80110024(param_0);
    _ncpoducam_entrypoint_11(_ncpoducam_entrypoint_1(*(s16 *)((char *)local_0 + 2)), param_1);
}

s32 ncpod_entrypoint_32(s32 param_0, s32 param_1, s32 param_2, s32 param_3) {
    s32 sp1C;
    s32 sp18;

    sp1C = func_80110024();
    ncpod_entrypoint_12(sp1C, 3);
    sp18 = _ncpodfixpos_entrypoint_2(*(s16 *)(sp1C + 4));
    _ncpodfixpos_entrypoint_5(sp18, param_3);
    if (param_1 != 0) {
        _ncpodfixpos_entrypoint_4(sp18, param_1);
    }
    _ncpodfixpos_entrypoint_3(sp18, param_0, param_2);
    return 4;
}

s32 ncpod_entrypoint_33(s32 param_0, s32 param_1, s32 param_2, s32 param_3, s32 param_4)
{
    s32 local_0;
    s32 local_1;

    if (!ncpod_entrypoint_16(param_0, 0, 0xB, param_4)) return 0;
    local_0 = func_80110024(param_0);
    ncpod_entrypoint_12(local_0, 3);
    if (param_2) ncpod_entrypoint_7(local_0, param_2);
    else if (param_1) ncpod_entrypoint_7(local_0, param_1);
    local_1 = _ncpodfixpos_entrypoint_2(*(s16 *)(local_0 + 4));
    _ncpodfixpos_entrypoint_5(local_1, param_4);
    if (param_1) _ncpodfixpos_entrypoint_4(local_1, param_1);
    _ncpodfixpos_entrypoint_3(local_1, param_0, param_3);
    func_8010FD88(param_0);
    return 1;
}
