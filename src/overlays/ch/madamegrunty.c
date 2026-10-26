#include "common.h"

#define CODEX_MADAME_REWARD_DEFINED
extern int D_80800B50_chmadamegrunty;
extern int D_80800B98_chmadamegrunty;
typedef union { s32 local_0; s16 local_1[2]; } MadameMessage1417;
extern void func_800EEB9C(f32 *, f32, f32);
extern void func_800F4AC0(s32, f32 *, f32);
extern s32 func_800DC298(f32);
extern void func_8010D5DC();
extern void _capod_entrypoint_14(void);
extern void func_800F7C0C(s32, s32, f32);
typedef struct { s16 reward; s16 flag; s16 count; s16 pad_0; f32 weight; } MadameReward;
extern MadameReward D_80800AF0_chmadamegrunty[8];
extern f32 func_800DC178(f32, f32);
extern s32 func_800C6E38(s32);
typedef struct { s32 unk0; f32 unk4; f32 unk8; } MadameEntry;
extern MadameEntry D_80800BE0_chmadamegrunty[9];
extern s32 func_800D9078();
extern f32 func_800F10B4(f32, f32, f32, f32, f32);
extern s32 _chdoormake_entrypoint_3(Actor *, f32, f32, f32, s32, s32);
extern void _chdoormake_entrypoint_5(Actor *, f32);
extern void _chdoormake_entrypoint_7(Actor *, f32);
extern void func_800EF1B8(f32 *, f32, f32);
extern u8 D_80800C4C_chmadamegrunty[];
extern void func_800C31DC(u8, f32);
extern void func_800C301C(u8, s32);
extern void func_800C3BDC();
void func_80800460_chmadamegrunty();
void func_80800784_chmadamegrunty();
void func_8080082C_chmadamegrunty();
void func_80800670_chmadamegrunty();
void func_808009AC_chmadamegrunty(Actor *param_0, s32 param_1, f32 param_2);

int chmadamegrunty_entrypoint_0()
{
  return (int)&D_80800B50_chmadamegrunty;
}

int chmadamegrunty_entrypoint_1()
{
    return (int)&D_80800B98_chmadamegrunty;
}

int func_80800018_chmadamegrunty(Actor *param_0)
{
  if (func_800DA298(0xA02))
  {
    func_80101FDC(param_0, 7);
    param_0->unk58 = 20.0f;
  }
}

s32 func_808008D4_chmadamegrunty();

void func_808003B0_chmadamegrunty();

void func_80800200_chmadamegrunty();

void func_8080005C_chmadamegrunty(Actor *param_0)
{

    switch (param_0->unk70_10) {
        case 1:
            func_80800200_chmadamegrunty(param_0);
            break;
        case 2:
        case 3:
        case 4:
            break;
        case 5:
            if (!func_808008D4_chmadamegrunty(param_0)) {
                func_800F4924(func_800F54E4(), -1);
                func_808003B0_chmadamegrunty(param_0);
            }
            break;
        case 6:
            if (func_800D9078(&param_0->unk58)) {
                func_8080082C_chmadamegrunty(param_0, param_0->unk64_20 ? 7 : 1);
                param_0->unk64_20 = 0;
            }
            break;
        case 7:
            if (func_800D90A4(&param_0->unk58) && _subaddiedialog_entrypoint_16() &&
                _subaddiedialog_entrypoint_11(param_0->unk0, 0x10CB, 0, 0, 0x43)) {
                func_8080082C_chmadamegrunty(param_0, 1);
                func_80101180(0x3D4, 7, 0);
                _subaddieDll_entrypoint_4(param_0, 0);
            }
            break;
    }
}

int func_80800198_chmadamegrunty(Actor *param_0, s32 param_1, MadameMessage1417 param_2)
{
    switch (param_1) {
        case 0x2E:
            func_80800784_chmadamegrunty(param_0, param_2.local_1[0], param_2.local_1[1]);
            break;
        case 0x32:
            func_80800460_chmadamegrunty(param_0);
            break;
        default:
            return 0;
    }
    return 1;
}

void func_80800200_chmadamegrunty(s32 *param_0) {
    s32 temp_v0;

    temp_v0 = func_800F54E4();
    if ((func_800F6438(temp_v0) != 0) && (func_800F6478(temp_v0) != 0) && (func_8010C500(param_0) != 0) && (func_800F64A4(temp_v0, 0x10000) == 0)) {
        func_800F497C(temp_v0);
        func_800F49D4(temp_v0, &func_8010D5DC, *param_0);
        func_800F4AC0(temp_v0, param_0 + 1, 1.7e+02f);
        func_8080082C_chmadamegrunty(param_0, 2);
        _capod_entrypoint_13(*param_0, 0, 0xAE, 0x20);
    }
}

void func_808002BC_chmadamegrunty(param_0) Actor *param_0;
{
    f32 local_0[3];

    func_800EEB9C(local_0, param_0->rotation[1], 400.0f);
    func_800EF04C(local_0, param_0->position);
    func_800F82D4(func_800F54E4(), 0);
    func_800F497C(func_800F54E4());
    func_800F49D4(func_800F54E4(), func_8010D5DC, param_0->unk0);
    func_800F4AC0(func_800F54E4(), local_0, 170.0f);
    func_8080082C_chmadamegrunty(param_0, 4);
    param_0->unk64_20 = func_800DC298(0.25f);
    if (param_0->unk64_20) {
        func_80101180(0x3D4, 8, 0);
    }
    _capod_entrypoint_14();
}

void func_808003B0_chmadamegrunty(Actor *param_0)
{
    func_800F82D4(func_800F54E4(), 0);
    func_800F7C0C(func_800F54E4(), 0x44, param_0->rotation[1]);
    func_8080082C_chmadamegrunty(param_0, 6);
    param_0->unk58 = 1.5f;
    param_0->unk64_20 = func_800DC298(0.25f);
    if (param_0->unk64_20) func_80101180(0x3D4, 8, 0);
    _capod_entrypoint_14();
}

void func_80800460_chmadamegrunty(param_0) Actor *param_0;
{
    switch (param_0->unk70_10) {
        case 2:
            if (!func_800F64A4(func_800F54E4(), 0x201)) {
                _subaddiedialog_entrypoint_11(param_0->unk0, 0x10A0, 15, 0, 0x43);
                func_8080082C_chmadamegrunty(param_0, 3);
            } else {
                _subaddiedialog_entrypoint_11(param_0->unk0, 0x109F, 15, 0, 0x43);
                func_8080082C_chmadamegrunty(param_0, 3);
            }
            func_800F82D4(func_800F54E4(), 2);
            break;
        case 4:
            func_8080082C_chmadamegrunty(param_0, param_0->unk64_20 ? 7 : 1);
            param_0->unk64_20 = 0;
            break;
    }
}

s32 func_80800564_chmadamegrunty(param_0) Actor *param_0;
{
    f32 local_0;
    f32 local_1;
    s32 i;

    local_0 = 0.0f;
    local_1 = 0.0f;
    for (i = 0; i < 8; i++) {
        if (D_80800AF0_chmadamegrunty[i].flag == -1 || func_800C6E38(D_80800AF0_chmadamegrunty[i].flag)) {
            local_0 += D_80800AF0_chmadamegrunty[i].weight;
        }
    }
    local_0 = func_800DC178(0.0f, local_0);
    for (i = 0; i < 8; i++) {
        if (D_80800AF0_chmadamegrunty[i].flag == -1 || func_800C6E38(D_80800AF0_chmadamegrunty[i].flag)) {
            local_1 += D_80800AF0_chmadamegrunty[i].weight;
            if (local_0 <= local_1) {
                *(s32 *)&param_0->unk50 = i;
                return i + 0x10A1;
            }
        }
    }
    return 0;
}

void func_80800670_chmadamegrunty(param_0) Actor *param_0;
{
    f32 local_0[3];
    s32 local_1;
    local_1 = *(s32 *)&param_0->unk50;
    func_800EE7F8(local_0, param_0->position);
    func_800EF1B8(local_0, param_0->rotation[1], 400.0f);
    switch (local_1) {
    case 0:
        func_800D3EF4(6);
        func_800FC660(0xE);
        _subaddiedialog_entrypoint_11(param_0->unk0, 0x10A9, 0xE, 0, 0x43);
        break;
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
        func_800D175C(((MadameReward *) D_80800AF0_chmadamegrunty)[local_1].reward, ((MadameReward *) D_80800AF0_chmadamegrunty)[local_1].count);
        func_808002BC_chmadamegrunty(param_0);
        break;
    case 6:
        func_800F4924(func_800F54E4(), 1);
        func_808002BC_chmadamegrunty(param_0);
        break;
    case 7:
        func_80101FDC(param_0, 5);
        param_0->unk58 = 4.0f;
        break;
    }
}

void func_80800784_chmadamegrunty(arg0, arg1, arg2) s32 *arg0; s32 arg1; s32 arg2;
{
  switch (arg1)
  {
    case 0x109F:
      _subaddiedialog_entrypoint_11(*arg0, func_80800564_chmadamegrunty(), 0xE, 0, 0x43);
      return;

    case 0x10A9:
      func_808002BC_chmadamegrunty();
      return;

    case 0x10A0:
      func_808002BC_chmadamegrunty();
      return;

    default:
      if ((!arg0) && (!arg0))
    {
    }
      func_80800670_chmadamegrunty();

    case 0x10CA:

    case 0x10CB:
      return;

  }

}

void func_8080082C_chmadamegrunty(param_0, param_1) u8 *param_0; s32 param_1; {
    func_80101FDC();
    if (param_1 == 7) {
        _subaddieDll_entrypoint_4(param_0, 1);
        (*(f32 *)((s8 *)(param_0) + (0x58))) = 60.0f;
        _subaddiedialog_entrypoint_11((*(s32 *)((s8 *)(param_0) + (0))), 0x10CA, 4, 0, 0x43);
    }
}

int func_80800898_chmadamegrunty(f32 param_0, f32 param_1, f32 param_2)
{
  s32 local_0;
  local_0 = 0;
  if (param_0 <= param_2 && param_2 < param_1)
  {
    return 1;
  }
  return local_0;
}

s32 func_808008D4_chmadamegrunty(Actor *param_0)
{
    f32 local_0;
    s32 local_1;
    s32 i;

    local_0 = *(f32 *)((u8 *)param_0 + 0x58);
    local_1 = func_800D9078((f32 *)((u8 *)param_0 + 0x58));
    for (i = 0; i < 9; i++) {
        if (func_80800898_chmadamegrunty(*(f32 *)((u8 *)param_0 + 0x58), local_0, func_800F10B4(D_80800BE0_chmadamegrunty[i].unk4, 0.0f, 1.0f, 4.0f, 0.0f))) {
            func_808009AC_chmadamegrunty(param_0, D_80800BE0_chmadamegrunty[i].unk0, D_80800BE0_chmadamegrunty[i].unk8);
        }
    }
    return local_1 == 0;
}

void func_808009AC_chmadamegrunty(Actor *param_0, s32 param_1, f32 param_2)
{
    u8 local_0;

    local_0 = _subaddieaudioquick_entrypoint_1(param_0, param_0->position);
    func_800C4350(local_0, param_0->position, D_80800C4C_chmadamegrunty);
    func_800C301C(local_0, param_1);
    func_800C31DC(local_0, func_800DC178(-0.05f, 0.05f) + param_2);
    func_800C3BDC(local_0);
}

void func_80800A30_chmadamegrunty(Actor *param_0)
{
    if (_chdoormake_entrypoint_3(param_0, 0.0f, 90.0f, 200.0f * param_0->scale, 0x2812, 0xA02)) {
        _chdoormake_entrypoint_5(param_0, 1.0f);
        _chdoormake_entrypoint_7(param_0, 1.0f);
    }
}
