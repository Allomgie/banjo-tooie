#include "common.h"

extern int D_80800A80_chkingjinjobits;
typedef union { s32 local_0; u8 local_1[4]; } KingJinjoEvent;
extern s32 _chkingjinjobits_entrypoint_1;
extern void func_8010D5DC(void);
extern s32 func_800EA364(void);
extern void func_80101FDC(Actor *, s32);
extern void func_800BF744(s32, s32);
extern s32 func_800EA090(void);
extern void func_800F4A58(s32, f32 *, f32);
extern void func_800F49D4(s32, void (*)(void), s32);
extern f32 D_80800AC8_chkingjinjobits[];
extern Actor *func_80106790(Unk80132ED0 *);
extern f32 func_800F12D4(f32, f32, f32, f32, f32);
extern void func_800EE88C(f32 *, Vtx *);
extern f32 func_800EEAD4(f32 *, f32 *);
extern f32 func_800F10B4(f32, f32, f32, f32, f32);
int func_80800744_chkingjinjobits();
void func_80800354_chkingjinjobits();

int chkingjinjobits_entrypoint_0()
{
    return (int)&D_80800A80_chkingjinjobits;
}

void func_8080000C_chkingjinjobits(s32 arg0) 
{
}
void func_80800014_chkingjinjobits(Actor *param_0)
{
  s32 local_0;
  s32 local_1;
  switch (param_0->unk70_10)
  {
    case 2:
      if ((func_8010D23C() != 0) && (func_8010C500(param_0) != 0))
    {
      func_800DA544(0x367);
      _subaddiedialog_entrypoint_11(*((s32 *) (((s8 *) param_0) + 0)), 0x1537, 0x44, 0, 0x97);
      _capod_entrypoint_13(*((s32 *) (((s8 *) param_0) + 0)), 0, 9, 0x10);
      func_80101FDC(param_0, 1);
      return;
    }

    default:
      return;

    case 3:
      if (param_0->unk64_19 && param_0->unk64_20)
    {
      func_800F82D4(func_800F54E4(), 0);
      _capod_entrypoint_14();
      _glcutDll_entrypoint_0();
      _glcutDll_entrypoint_7(0x18E);
      _glcutDll_entrypoint_22(0x68);
      _glcutDll_entrypoint_12(1);
      _glcutDll_entrypoint_16();
      return;
    }
      break;

    case 4:
      if (func_800DA298(0x67A) != 0)
    {
      func_800BF744(3, 1);
      func_800DA544(0x360);
      func_80101FDC(param_0, 5);
      return;
    }
      break;

    case 5:
      local_0 = func_800D9078(&param_0->unk58);
      _glid_entrypoint_0(func_800BEA88(0), 1, &_chkingjinjobits_entrypoint_1, *((s32 *) (((s8 *) param_0) + 0)));
      if (local_0 != 0)
    {
      func_800BF744(3, 0);
      func_800FFAB0(param_0);
      return;
    }
      break;

    case 6:
      if (func_800DA298(0x67B) != 0)
    {
      func_80101FDC(param_0, 7);
      func_800BF744(3, 1);
    }
      _glid_entrypoint_0(func_800BEA88(0), 1, &_chkingjinjobits_entrypoint_1, *((s32 *) (((s8 *) param_0) + 0)));
      return;

    case 7:
      local_1 = func_800D9078(&param_0->unk58);
      _glid_entrypoint_0(func_800BEA88(0), 1, &_chkingjinjobits_entrypoint_1, *((s32 *) (((s8 *) param_0) + 0)));
      if (local_1 != 0)
    {
      func_800BF744(1, 1);
      func_800BF744(2, 0);
      func_800BF744(3, 0);
      func_800DA524(0x360);
      func_800DA544(0x3B);
      func_800DA524(0x1A5);
      func_800FFAB0(param_0);
    }
      break;

  }

}

int func_8080029C_chkingjinjobits(Actor *param_0, s32 param_1, s32 param_2)
{
    switch (param_1) {
    case 0x95:
        func_80800354_chkingjinjobits(param_0);
        break;
    case 0x2E:
        func_80800744_chkingjinjobits(param_0, ((s16 *)&param_2)[0], ((s16 *)&param_2)[1]);
        break;
    case 0x32:
        param_0->unk64_20 = 1;
        func_800F82D4(func_800F54E4(), 1);
        break;
    case 0xB:
        if (func_800EA05C() == 0x14F) {
            func_800FFAB0(param_0);
        }
        return 3;
    default:
        return 0;
    }
    return 1;
}

void func_80800354_chkingjinjobits(param_0) Actor *param_0;
{
    s32 local_0;
    s32 local_1;
    s32 local_2;
    s32 local_3;
    s32 local_4;
    f32 local_5[6];
    s32 local_6;

    local_0 = 0;
    local_1 = func_800DA298(0x360);
    local_2 = func_800DA298(0x3B);
    local_3 = func_800D0B68(0x5A, 1);
    switch (func_800EA05C()) {
    case 0x142:
        if (_glcutDll_entrypoint_19(0x66)) {
            local_4 = 0x900;
            if (func_800EA364() == 0x143) {
                local_4 = 0x2900;
            }
            _capod_entrypoint_13(param_0->unk0, 0, 0x4B, local_4);
            _subaddiedialog_entrypoint_11(param_0->unk0, 0x154D, 0x44, 0, 0xAE);
            local_0 = 1;
        } else if (!func_800DB9B0() && !local_1 && !local_2 && func_800EA090() == 1 && local_3) {
            local_6 = func_800F54E4();
            _subaddiemarker_entrypoint_1(param_0, 0x154, 0x32, local_5, 1);
            func_800F497C(local_6);
            func_800F49A8(local_6, 1);
            func_800F49D4(local_6, func_8010D5DC, param_0->unk0);
            func_800F4A58(local_6, local_5, 200.0f);
            _subaddiedialog_entrypoint_11(param_0->unk0, 0x154C, 0x44, 0, 0xAE);
            func_80101FDC(param_0, 3);
            _capod_entrypoint_13(param_0->unk0, 0, 0x4C, 0x2030);
            local_0 = 1;
        }
        func_800BF744(1, !local_1);
        func_800BF744(2, local_1);
        func_800BF744(3, 0);
        break;
    case 0x145:
    case 0x146:
    case 0x147:
    case 0x148:
    case 0x149:
    case 0x14A:
    case 0x14B:
    case 0x14C:
    case 0x14D:
    case 0x14E:
        if (!local_3 && !func_800DB9B0() && !func_800DA9E4(0x67D, 1)) {
            local_0 = 1;
            _subaddiedialog_entrypoint_11(param_0->unk0, 0x1536, 0xE, 0, 0xAE);
        }
        break;
    case 0x14F:
        local_0 = !func_800DA298(0x367);
        func_80101FDC(param_0, 2);
        _subaddieDll_entrypoint_1(param_0);
        break;
    case 0x190:
        local_0 = 1;
        func_80101FDC(param_0, 4);
        param_0->unk6C_0 = 0;
        param_0->unk58 = 12.0f;
        func_800BF744(1, 0);
        func_800BF744(2, 1);
        func_800BF744(3, 1);
        break;
    case 0x198:
        local_0 = 1;
        func_80101FDC(param_0, 6);
        param_0->unk6C_0 = 1;
        param_0->unk58 = 12.0f;
        func_800BF744(1, 0);
        func_800BF744(2, 1);
        func_800BF744(3, 1);
        break;
    case 0x160:
        if (func_800EA090() == 4) {
            local_0 = 1;
            _capod_entrypoint_2(param_0->unk0, 0x15, 0x2000);
            _capod_entrypoint_8(1);
            _gcdialogcamera_entrypoint_8();
            _capod_entrypoint_7(5, 1);
            _subaddiedialog_entrypoint_11(param_0->unk0, 0x14D7, 0xC, 0, 0x22);
            func_80101FDC(param_0, 8);
        }
        break;
    }
    if (!local_0) {
        func_800FFAB0(param_0);
    }
}

int func_80800744_chkingjinjobits(Actor *param_0, s32 param_1, KingJinjoEvent param_2)
{
    switch (param_1) {
    case 0x1536:
        _glcutDll_entrypoint_6(0x142, 0x66, param_0);
        break;
    case 0x154C:
        param_0->unk64_19 = 1;
        break;
    case 0x14D7:
        _capod_entrypoint_3(0);
        func_800FFAB0(param_0);
        break;
    }
}

void chkingjinjobits_entrypoint_1(s32 arg0, Vtx *src, Vtx *dst, s32 count, Unk80132ED0 *marker)
{
    Actor *a;
    f32 r;
    f32 d;
    f32 v[3];
    s32 pad[2];
    Vtx *end;

    a = func_80106790(marker);
    if (a->unk6C_0) {
        r = func_800F12D4(a->unk58, 0.0f, 12.0f, 10.0f, 3000.0f);
    } else {
        r = func_800F12D4(a->unk58, 0.0f, 12.0f, 3000.0f, 10.0f);
    }
    for (end = src + count; src < end; src++, dst++) {
        func_800EE88C(v, src);
        d = func_800EEAD4(v, D_80800AC8_chkingjinjobits);
        if (d < r) {
            dst->v.cn[3] = 0;
        } else if (r + 200.0f < d) {
            dst->v.cn[3] = 0xFF;
        } else {
            dst->v.cn[3] = func_800F10B4(d - r, 0.0f, 200.0f, 0, 255.0f);
        }
    }
}
