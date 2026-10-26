#include "common.h"

extern int D_8080092C_chstarspinnerctrl;
extern int D_80800974_chstarspinnerctrl;
extern s32 D_80800900_chstarspinnerctrl[];
extern s32 D_8080090C_chstarspinnerctrl[3];
extern s32 D_80800918_chstarspinnerctrl[];
extern void *func_80100094(Actor *, u32);
extern f32 func_800F10B4(f32, f32, f32, f32, f32);
extern s32 func_800F3214(s32 *, s32 *, s32 *, f32);
extern s32 _chpowerhut_entrypoint_4(Actor *, f32, void *);
extern u8 _chstarspinnerctrl_entrypoint_2[];
extern Actor *func_80106790();
extern void func_800F2FD0(u8 *, u8 *, f32);
extern void func_800EE7F8(f32 *, f32 *);
extern void func_800EF1B8(f32 *, f32, f32);
extern s32 func_800BBCB8(f32 *, f32 *, f32, s32, s32 *);
extern s32 D_808009BC_chstarspinnerctrl[];
extern void func_801015D0(void);
extern int D_80800A50_chstarspinnerctrl;
extern int D_80800A00_chstarspinnerctrl;
extern int D_80800A98_chstarspinnerctrl;
extern int D_80800AA8_chstarspinnerctrl;
extern int D_808008E0_chstarspinnerctrl;
typedef struct { u8 pad_0[0x14]; f32 local_0; } StarSpinnerColor1506;
extern void func_800F2E60(s32 *, s32 *);
extern Actor *_subaddiefind_entrypoint_2(s32, s32 *);
extern Actor *_subaddiefind_entrypoint_3(s32, s32 *);
extern void _subaddiefade_entrypoint_11(Actor *, s32 *);
extern s32 D_808008E8_chstarspinnerctrl;
extern s32 D_808008F4_chstarspinnerctrl;
void func_808002B4_chstarspinnerctrl();
void func_80800554_chstarspinnerctrl();
void func_8080069C_chstarspinnerctrl();

int chstarspinnerctrl_entrypoint_0()
{
    return (int)&D_8080092C_chstarspinnerctrl;
}

int chstarspinnerctrl_entrypoint_1()
{
    return (int)&D_80800974_chstarspinnerctrl;
}

void func_80800018_chstarspinnerctrl(s32 param_0) {
    _chpowerhut_entrypoint_0(param_0, ((s32 *) D_80800918_chstarspinnerctrl));
}

void func_8080003C_chstarspinnerctrl(Actor *param_0)
{
    s32 local_0[3];

    _chpowerhut_entrypoint_1(param_0, D_80800918_chstarspinnerctrl);
    switch (param_0->unk70_10) {
        case 1:
            break;
        case 3:
            if (*(s16 *)((u8 *)func_80100094(param_0, 0) + 0xC) == 2) {
                func_800BF744(2, 0);
                func_800BF744(1, 1);
            }
            if (*(s16 *)((u8 *)func_80100094(param_0, 0) + 0xC) == 3) {
                *(f32 *)((u8 *)func_80100094(param_0, 0) + 0x18) = func_800F10B4(*(f32 *)((u8 *)func_80100094(param_0, 0) + 0x14), 0.0f, 1.0f, 0.3f, 1.0f);
                func_800F3214(local_0, D_80800900_chstarspinnerctrl, D_8080090C_chstarspinnerctrl, *(f32 *)((u8 *)func_80100094(param_0, 0) + 0x18));
                func_800C8F08(local_0, 0);
                func_808002B4_chstarspinnerctrl(param_0);
            }
            if (_chpowerhut_entrypoint_4(param_0, 10.75f, D_80800918_chstarspinnerctrl)) func_800DA544(0);
            break;
    }
    func_8080069C_chstarspinnerctrl(param_0);
}

s32 func_80800184_chstarspinnerctrl(Actor *param_0, s32 param_1, s32 param_2)
{
    s32 local_0;

    if (param_1 == 0x95) {
        local_0 = func_800DA298(0xEA) != 0 || _glcutDll_entrypoint_20() != 0;
        func_800BF744(2, !local_0);
        func_800BF744(1, local_0);
        *(f32 *)((u8 *)func_80100094(param_0, 0) + 0x18) =
            func_800F10B4(*(f32 *)((u8 *)func_80100094(param_0, 0) + 0x14),
                0.0f, 1.0f, 0.3f, 1.0f);
        if (!local_0) {
            func_808002B4_chstarspinnerctrl(param_0);
            func_800C8F08(D_80800900_chstarspinnerctrl, 0);
        } else {
            func_800DA544(0);
        }
        _chpowerhut_entrypoint_3(param_0, param_1, param_2, D_80800918_chstarspinnerctrl);
        func_80103110(param_0, 1);
        return 1;
    }
    return _chpowerhut_entrypoint_3(param_0, param_1, param_2, D_80800918_chstarspinnerctrl);
}

void func_808002B4_chstarspinnerctrl(param_0) s32 *param_0; {
    _glid_entrypoint_0(func_800BEA88(0), 1, &_chstarspinnerctrl_entrypoint_2, *param_0);
}

void chstarspinnerctrl_entrypoint_2(void *param_0, Vtx *param_1, Vtx *param_2, s32 param_3, Unk80132ED0 *param_4)
{
    f32 local_0;
    local_0 = *(f32 *)((u8 *)func_80100094(func_80106790(param_4), 0) + 0x18);
    while (param_3 > 0) {
        func_800F2FD0(param_2->v.cn, param_1->v.cn, local_0);
        param_3--;
        param_1++;
        param_2++;
    }
}

void func_80800374_chstarspinnerctrl(u8 *param_0)
{
  if (func_800DA298(0x679) != 0)
  {
    func_8010A570(param_0);
    param_0[0x65] = 0x10 | (param_0[0x65] & 0xFF);
  }
}

void func_808003B8_chstarspinnerctrl(Actor *param_0)
{
    f32 local_0[3];
    if (param_0->unk64_20 && !func_8001210C(3)) {
        func_800EE7F8(local_0, param_0->position);
        func_800EF1B8(local_0, param_0->rotation[1], 40.0f);
        local_0[1] += 30.0f;
        func_800BBCB8(local_0, local_0, 0.8f, 1, D_808009BC_chstarspinnerctrl);
    }
}

void func_8080044C_chstarspinnerctrl(Actor *param_0, void *param_1)
{
    func_800DF744(1, param_0->unk64_20 ? 0 : 1);
    func_800DF744(2, param_0->unk64_20 ? 1 : 0);
    func_80101808(param_0, func_801015D0);
}

int func_808004CC_chstarspinnerctrl(Actor *param_0, s32 param_1, s32 param_2)
{
    switch (param_1) {
    case 0x40:
        func_8010A570(param_0);
        param_0->unk64_20 = 1;
        func_800DA544(0x679);
        func_80800554_chstarspinnerctrl(param_0);
        func_800FC660(14);
        _subaddiedialog_entrypoint_11(param_0->unk0, 0x10F4, 4, param_0->position, 0x22);
        break;
    default:
        return 0;
    }
    return 1;
}

void func_80800554_chstarspinnerctrl(param_0) s32 param_0;
{
  s32 local_0 = param_0 + 4;
  func_800BBCB8(param_0 + 4, 0, 1.0f, 8, &D_80800A50_chstarspinnerctrl);
  func_800BBCB8(param_0 + 4, 0, 1.0f, 0xC, &D_80800A00_chstarspinnerctrl);
  func_800C4AF0(param_0 + 4, &D_80800A98_chstarspinnerctrl);
  func_800C4AF0(param_0 + 4, &D_80800AA8_chstarspinnerctrl);
  func_800E1610(0, 0x41200000, 0x3F666666, param_0 + 4);
  func_80018820(0, 0x40000000, 0x3E800000);
}

int chstarspinnerctrl_entrypoint_3(s32 param_0, s32 param_1)
{
  s32 local_0;
  if ((!func_800DA298(0xEA)) && (!_glcutDll_entrypoint_20()))
  {
    return 0;
  }
  local_0 = func_800C8A98();
  func_800C8D4C(local_0, &D_808008E0_chstarspinnerctrl);
  func_800C8E84(local_0, &D_808008F4_chstarspinnerctrl);
  func_800C8CB8(local_0, param_1);
  func_800C8F64(local_0, 9);
  return local_0;
}

void func_8080069C_chstarspinnerctrl(param_0) Actor *param_0;
{
    Actor *local_2;
    s32 local_0;
    s32 local_1[3];
    f32 local_3;

    switch (param_0->unk70_10) {
    case 1:
    case 2:
        func_800F2E60(local_1, &D_808008E8_chstarspinnerctrl);
        break;
    case 3:
        local_3 = ((StarSpinnerColor1506 *)func_80100094(param_0, 0))->local_0;
        func_800F3214(local_1, &D_808008E8_chstarspinnerctrl, &D_808008F4_chstarspinnerctrl, local_3);
        break;
    case 4:
    case 5:
        func_800F2E60(local_1, &D_808008F4_chstarspinnerctrl);
        break;
    }
    local_2 = _subaddiefind_entrypoint_2(0x336, &local_0);
    while (local_2) {
        _subaddiefade_entrypoint_11(local_2, local_1);
        local_2 = _subaddiefind_entrypoint_3(0x336, &local_0);
    }
}

s32 chstarspinnerctrl_entrypoint_4(Actor *param_0, s32 param_1, s32 param_2)
{
    Actor *local_0;
    s32 local_1;

    local_1 = func_800DA298(0xEA) || _glcutDll_entrypoint_20();
    if (!param_0->unk3C) {
        return 0;
    }
    local_0 = func_80106790(param_0->unk3C);
    if (local_1 && !param_2) {
        param_2 = chstarspinnerctrl_entrypoint_3(param_0, param_1);
        if (param_2) {
            func_800C8E84(param_2, &D_808008E8_chstarspinnerctrl);
        }
    }
    if (!param_2) {
        return 0;
    }
    func_800C8CB8(param_2, param_1);
    switch (local_0->unk70_10) {
        case 1:
        case 2:
            func_800C8B84(param_2);
            param_2 = 0;
            break;
        case 3:
            func_800C8E84(param_2, &D_808008F4_chstarspinnerctrl);
            break;
        case 4:
        case 5:
            func_800C8E84(param_2, &D_808008F4_chstarspinnerctrl);
            break;
    }
    return param_2;
}
