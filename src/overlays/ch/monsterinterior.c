#include "common.h"

extern void *D_80801E80_chmonsterinterior;
extern void *D_80801EC8_chmonsterinterior;
extern int D_80801F10_chmonsterinterior[];
extern s32 D_80801F58_chmonsterinterior[];
extern int D_80801FA0_chmonsterinterior[];
extern void *func_80100094(Actor *, u32);
extern u8 unk6C[];
typedef union { s32 local_0; void *local_1; } MonsterEvent60;
extern s32 func_800D9078();
extern void func_800EE7F8(f32 *, f32 *);
extern void func_80105138(Actor *, f32 *, f32, f32, f32 *);
extern Actor *func_80108528(s32, f32 *, s32, Actor **);
typedef struct { u8 local_0[0x70]; u8 local_1 : 7; u8 local_2 : 1; } MonsterFlags61;
extern u8 D_80801FE8_chmonsterinterior[];
extern u8 D_80801FF0_chmonsterinterior[];
extern u32 func_800FDC28(u32);
extern void func_800FC6B0(u32);
extern void _subaddiemulti_entrypoint_3();
extern void _sumultiscore_entrypoint_3();
extern void _sumultiscore_entrypoint_11(void *, s32, s32, f32);
extern u8 D_80801E58_chmonsterinterior[];
extern u8 D_8080208C_chmonsterinterior[];
extern u8 D_80801E50_chmonsterinterior[];
extern u8 D_8080207C_chmonsterinterior[];
extern u8 D_80802044_chmonsterinterior[];
extern f32 func_800DC178(f32, f32);
extern f32 func_800F12D4(f32, f32, f32, f32, f32);
extern void _susubgame_entrypoint_5();
extern void _subaddiedialog_entrypoint_11(Unk80132ED0 *, s32, s32, f32 *, s32);
extern void func_800F7C0C(s32, s32, f32);
extern void func_800F8300(s32, s32, f32 *);
extern f32 func_800DC0C0(void);
extern s32 func_800D9154(f32 *, f32);
extern s32 _bsfirstp_entrypoint_18;
extern void _subaddiemulti_entrypoint_2();
extern void func_80101FDC();
extern s32 _gcstatusDll_entrypoint_11(void);
extern s32 func_800D3948(void);
extern void func_800F7B9C(s32, s32);
extern void func_800CE8D8(s32, f32, s32);
extern void func_800CE88C(s32, s32);
extern void _sumultiscore_entrypoint_6();
extern u8 D_8080201C_chmonsterinterior[];
extern void func_8010A3E8(Actor *, f32);
extern void func_80102FDC(Actor *, f32);
extern void func_8010D930(s32, s32, f32 *, void *);
extern void _subaddiefade_entrypoint_3();
extern u8 D_80802030_chmonsterinterior[];
extern f32 func_800D8FF8(void);
extern f32 _subaddiejoy_entrypoint_9(Actor *, f32 *, s32);
extern void func_8010C93C(Actor *, f32 *, f32);
extern void func_80102BF8(Actor *, f32, f32, f32);
extern void func_8010C3A8(Actor *, s32, f32);
extern void _subaddierouteDll_entrypoint_7(Actor *, void *, f32, f32, f32, s32);
extern void _subaddierouteDll_entrypoint_6(Actor *, void *, s32, s32, f32, s32, s32);
extern void _subaddierouteDll_entrypoint_5(Actor *, void *, s32, f32, f32, f32);
extern f32 func_800F15F8(f32, f32, f32);
extern f32 func_800F10B4(f32, f32, f32, f32, f32);
typedef struct { u8 pad_0[0x64]; u32 pad_1 : 2; u32 local_0 : 1; u32 pad_2 : 29; } MonsterControlledFlag1121;
void func_80800BC8_chmonsterinterior();
void func_80801114_chmonsterinterior();
s32 func_80801180_chmonsterinterior();
void func_80801930_chmonsterinterior();
void func_8080068C_chmonsterinterior();
void func_8080078C_chmonsterinterior();
extern void func_80101870(), func_80105834(), func_80107C2C(), func_8080003C_chmonsterinterior(), func_808000BC_chmonsterinterior();
extern void func_80105834(), func_80107C2C(), func_80800DA4_chmonsterinterior();

int chmonsterinterior_entrypoint_0()
{
  return &D_80801E80_chmonsterinterior;
}

int chmonsterinterior_entrypoint_1()
{
  return &D_80801EC8_chmonsterinterior;
}

int chmonsterinterior_entrypoint_2()
{
  return &D_80801F10_chmonsterinterior;
}

int chmonsterinterior_entrypoint_3()
{
  return D_80801F58_chmonsterinterior;
}

int chmonsterinterior_entrypoint_4()
{
  return (int)&D_80801FA0_chmonsterinterior;
}

void func_8080003C_chmonsterinterior(param_0) Actor *param_0;
{
    u8 *local_0;
    local_0 = func_80100094(param_0, 0);
    if (!func_800F6438(func_800F54E4())) {
        func_800FFAB0(param_0);
    } else {
        *(s32 *)local_0 = 0;
        _susubgame_entrypoint_0(param_0, local_0 + 0x10, 0);
        _susubgame_entrypoint_11(0);
        param_0->unk6C_0 = 0;
    }
}

s32 func_80800C38_chmonsterinterior();

void func_808000BC_chmonsterinterior(param_0) Actor *param_0;
{
    u8 *local_0;
    void *local_1;
    f32 local_2;
    s32 local_3;

    local_0 = func_80100094(param_0, 0);
    switch (param_0->unk70_10) {
    case 3:
        local_1 = func_800F54E4();
        func_800D2498(0xF7, *(s32 *)local_0, 0);
        if (func_800CEAD0(param_0->unk6C_0)) {
            *(s32 *)(local_0 + 8) = func_80800C38_chmonsterinterior(param_0, local_0 + 0xC);
            func_800F8300(local_1, 2, 0);
            func_800F7C0C(local_1, 0x5F, 0);
            func_80101FDC(param_0, 4);
            return;
        }
        if (func_800D9154(&param_0->unk58, func_800DC178(0.5f, 1.0f))) {
            local_2 = func_800DC0C0();
            if (local_2 < 0.166666f) {
                local_3 = 0;
            } else if (local_2 < 0.5f) {
                local_3 = 1;
            } else {
                local_3 = 2;
            }
            func_80108B04(param_0, local_3);
        }
        break;
    case 1:
        break;
    case 4:
        if (_susubgame_entrypoint_9()) {
            _susubgame_entrypoint_5(param_0, local_0 + 0x10, 5, 1, 0);
            _subaddiedialog_entrypoint_11(param_0->unk0, *(s32 *)(local_0 + 8), *(s32 *)(local_0 + 0xC), NULL, 0xB3);
            func_80101FDC(param_0, 5);
        }
        break;
    case 7:
        if (func_800D0B68(0x2E, 1)) {
            func_800F8300(func_800F54E4(), 2, 0);
            *(s32 *)(local_0 + 8) = 0xCEB;
            *(s32 *)(local_0 + 0xC) = 0x46;
            func_80101FDC(param_0, 4);
        }
        break;
    }
}

void func_80800A44_chmonsterinterior();

s32 func_808009C0_chmonsterinterior();

s32 func_808002D4_chmonsterinterior(u8 *param_0, s32 param_1, s32 param_2)
{
    u8 *local_0;
    s32 local_1;
    s32 local_2;

    local_0 = func_80100094(param_0, 0);
    switch (param_1) {
    case 0x2E:
        func_8080078C_chmonsterinterior(param_0, ((s16 *)&param_2)[0], ((s16 *)&param_2)[1]);
        break;
    case 0x30:
        return func_808009C0_chmonsterinterior(param_0, ((s16 *)&param_2)[0], ((s16 *)&param_2)[1]);
    case 0x3D:
        func_80800A44_chmonsterinterior(param_0, param_2);
        break;
    case 0xB:
        if (param_2 == 6) {
            _susubgame_entrypoint_4(param_0, local_0 + 0x10);
            func_800F7B9C(func_800F54E4(), 0x62);
            func_800F82D4(func_800F54E4(), 0);
            func_80101FDC(param_0, 7);
            return 4;
        }
        return 3;
    case 0x49:
        local_1 = func_800F54E4();
        if (((u32)*(u16 *)(param_0 + 0x72) >> 10) != 1) {
            return 0;
        }
        if (_glcutDll_entrypoint_20() != 0) {
            func_800FFAB0(param_0);
            return 0;
        }
        if (func_800DA9E4(0x370, 1) == 0) {
            func_800F49D4(local_1, &_bsfirstp_entrypoint_18, 0);
            _susubgame_entrypoint_6(param_0, local_0 + 0x10, 0, 0x20, 0);
            _chintrotext_entrypoint_2(1);
        } else {
            func_800F49D4(local_1, 0, 0);
            func_800F7B9C(local_1, 0x8F);
            func_800F7B9C(local_1, 0x63);
            func_800F7C58(local_1, 0x61, 0);
            _susubgame_entrypoint_5(param_0, local_0 + 0x10, 5, 1, 0);
            _subaddiedialog_entrypoint_11(*(s32 *)param_0, 0xCEC, 0x46, 0, 0xB3);
            func_800F82D4(func_800F54E4(), 2);
        }
        func_80101FDC(param_0, 2);
        break;
    case 0x77:
        if (func_800D395C() != 0) {
            local_2 = 0x181A;
        } else {
            local_2 = 0x17F2;
        }
        _subaddiedialog_entrypoint_11(*(s32 *)param_0, local_2, 0x46, 0, 0xB3);
        func_800F82D4(func_800F54E4(), 2);
        break;
    case 0x57:
        return _susubgame_entrypoint_3(param_0, local_0 + 0x10, param_2 & 0xFFFF, (u32)(param_2 & 0xFFFF0000) >> 0x10);
    case 0x59:
        local_2 = param_2;
        switch (local_2) {
        case 0xCEC:
            func_8080068C_chmonsterinterior(param_0, local_2);
            _susubgame_entrypoint_4(param_0, local_0 + 0x10);
            break;
        case 0xCEB:
            _susubgame_entrypoint_4(param_0, local_0 + 0x10);
            break;
        }
        break;
    default:
        return 0;
    }
    return 1;
}

int func_8080060C_chmonsterinterior(param_0) Actor *param_0;
{
  s32 local_0;
  local_0 = func_80100094(param_0, 0);
  if (func_800CEAA8((*(s32 *)((char *)(param_0) + 0x6C)) & 0x1FF))
  {
    func_800CE88C((*(s32 *)((char *)(param_0) + 0x6C)) & 0x1FF, 0);
  }
  if (_susubgame_entrypoint_2(param_0, local_0 + 0x10))
  {
    _susubgame_entrypoint_4(param_0, local_0 + 0x10);
  }
}

void func_8080068C_chmonsterinterior(param_0) u8 *param_0;
{
    s32 i;
    s16 local_0;

    _subaddiemulti_entrypoint_2();
    func_80101FDC(param_0, 3);
    for (i = 0; i < _gcstatusDll_entrypoint_11(); i++) {
        if (func_800D3948() == 0) {
            func_800F7B9C(i, 0x73);
            func_800F7C0C(i, 0x5F, -1.0f);
        } else {
            func_800F7C0C(i, 0x5F, -1.0f);
        }
    }
    local_0 = 60;
    func_800CE8D8(*(s32 *)(param_0 + 0x6C) & 0x1FF, local_0, local_0);
    func_800CE88C(*(s32 *)(param_0 + 0x6C) & 0x1FF, 1);
    *(f32 *)(param_0 + 0x58) = 0.01f;
    func_800FDC28(0xC);
}

void func_8080078C_chmonsterinterior(param_0, param_1, param_2) Actor *param_0; s32 param_1; s32 param_2;
{
    u8 *local_0;
    local_0 = func_80100094(param_0, 0);
    switch (param_1) {
    case 0x17F2:
    case 0x181A:
        if (param_2 > 0) {
            _susubgame_entrypoint_6(param_0, local_0 + 0x10, 3, 0x20, 0);
            _subaddiedialog_entrypoint_11(param_0->unk0, 0x17F3, 0x44, 0, 0xB3);
            func_80108B04(param_0, 0);
        } else _subaddiedialog_entrypoint_11(param_0->unk0, 0xCEC, 7, 0, 0xB3);
        _gcfrontend_entrypoint_9(0x6B);
        break;
    case 0x17F3:
        _susubgame_entrypoint_5(param_0, local_0 + 0x10, 5, 1, 0);
        _subaddiedialog_entrypoint_11(param_0->unk0, 0xCEC, 7, 0, 0xB3);
        break;
    case 0xCEB:
        func_800F82D4(func_800F54E4(), 0);
        func_80101FDC(param_0, 6);
        if (func_800D395C()) {
            if (param_2 > 0) _gcfrontend_entrypoint_11();
            else _gcfrontend_entrypoint_10();
        } else if (param_2 > 0) _gcgoto_entrypoint_1(0x123, 1);
        else func_80108BD4(param_0, 0xCEB);
        break;
    case 0xCEC:
        func_80108BD4(param_0, 0xCEC);
        break;
    case 0x17FA:
        _susubgame_entrypoint_6(param_0, local_0 + 0x10, 6, 0x20, 0);
        func_800D1000(0x2E, 1, 0, 1, 0);
        break;
    case 0x17F7:
    case 0x1807:
    case 0x1808:
    case 0x1809:
        _subaddiedialog_entrypoint_11(param_0->unk0, 0xCEB, 0x46, 0, 0xB3);
        break;
    }
}

s32 func_808009C0_chmonsterinterior(Actor *param_0, s32 param_1, MonsterEvent60 param_2)
{
    s32 *local_0;
    s32 local_1;

    local_1 = param_1;
    local_0 = func_80100094(param_0, 0);
    switch (local_1) {
    case 0x17F7:
        return *local_0;
    case 0x17F3:
        return 0x4B;
    case 0x1808:
    case 0x181A:
        return func_800D211C(0x85);
    }
    return 0;
}

void func_80800A44_chmonsterinterior(Actor *param_0, s32 param_1)
{
    Actor *local_0;
    f32 local_4[3];
    f32 local_3;
    s32 local_5;
    s32 local_1;
    u8 *local_2;
    if (param_1 == 0 || param_1 == 1 || param_1 == 2) {
        local_1 = func_800D3948();
        local_2 = func_80100094(param_0, 0);
        if (_susubgame_entrypoint_2(param_0, local_2 + 0x10)) func_800EE7F8(local_4, param_0->position);
        else func_800CD08C((*(u32 *)((u8 *)param_0 + 0x70) >> 25) - 1, local_4);
        local_4[1] = param_0->position[1];
        func_80105138(param_0, local_4, 200.0f, -200.0f, &local_3);
        local_4[1] = local_3;
        local_5 = func_800DC128(0, 0x167);
        local_0 = func_80108528(param_1 + 0x452, local_4, local_5, &param_0);
        local_0->unk3C = param_0->unk0;
        local_0->unk64_20 = local_1;
        local_0->actorData[5] = param_1;
        local_0->unk6C_0 = param_0->unk6C_0;
        local_0->unk64_19 = _susubgame_entrypoint_2(param_0, local_2 + 0x10);
        ((MonsterFlags61 *)local_0)->local_2 = !local_1;
        func_80800BC8_chmonsterinterior(local_0, param_1);
    }
}

void func_80800BC8_chmonsterinterior(param_0, param_1) u8 **param_0; s32 param_1; {
    if (func_800D3948() != 0) {
        func_801032B0(param_0, *(u16 *)&D_80801FF0_chmonsterinterior[param_1 * 2], *(u16 *)((char *)*param_0 + 0x16));
        return;
    }
    func_801032B0(param_0, *(u16 *)&D_80801FE8_chmonsterinterior[param_1 * 2], *(u16 *)((char *)*param_0 + 0x16));
}

s32 func_80800C38_chmonsterinterior(Actor *param_0, s32 *param_1)
{
    s32 *local_0;
    s32 local_1;
    s32 local_2;
    s32 local_3;
    s32 local_4;
    u32 local_5;
    s32 local_6;
    s32 local_7;
    s32 local_8;

    local_0 = func_80100094(param_0, 0);
    local_1 = local_0[0];
    local_6 = func_800D0A9C(0x2E, 1);
    local_7 = func_800D395C();
    local_8 = func_800D2054(0, 0x85, local_1);
    local_3 = local_8 == 1 && (local_6 || local_7);
    local_4 = local_1 >= 75;
    local_5 = local_4 && !local_6 && !local_7;
    func_800FDC28(0);
    func_800FC6B0((local_5 || local_3) ? 0x16 : 0x17);
    *param_1 = 6;
    if (local_5) {
        local_2 = 0x17FA;
    } else if (local_3) {
        local_2 = 0x17F7;
    } else if (!func_800D395C()) {
        if (local_6) {
            if (local_8 == 0) local_2 = 0x1809;
            else local_2 = 0x1808;
        } else {
            local_2 = 0x1807;
        }
    } else {
        local_2 = 0xCEB;
        *param_1 = 0x46;
    }
    return local_2;
}

void func_80800DA4_chmonsterinterior(param_0) Actor *param_0;
{
    u8 *local_0;

    local_0 = func_80100094(param_0, 0);
    _subaddiemulti_entrypoint_3(10);
    param_0->unk6C_0 = 5;
    _sumultiscore_entrypoint_3(local_0 + 0x28);
    _sumultiscore_entrypoint_4(local_0 + 0x28, 8, 0, 1);
}

void func_808011BC_chmonsterinterior();

void func_80800E0C_chmonsterinterior(Actor *param_0)
{
    u8 *local_0;
    s32 local_2;
    s32 local_4;
    s32 local_1;
    s32 local_6;
    f32 local_5;
    f32 local_3;

    local_0 = func_80100094(param_0, 0);
    _sumultiscore_entrypoint_6(local_0 + 0x28);
    local_1 = param_0->unk70_10;
    switch (local_1) {
    case 1:
        if (!func_800C954C() && !func_800DA298(0x6AD)) {
            _subaddiedialog_entrypoint_11(param_0->unk0, 0xCEC, 7, 0, 0xB3);
            func_80101FDC(param_0, 2);
        }
        break;
    case 3:
        if (func_800CEAD0(param_0->unk6C_0)) {
            func_808011BC_chmonsterinterior(param_0);
        } else {
            local_6 = _subaddiefind_entrypoint_9(0x453);
            local_1 = _subaddiefind_entrypoint_9(0x452);
            if (1) {}
            if (_subaddiefind_entrypoint_9(0x454) + local_1 + local_6 < 5) {
                local_3 = func_800DC178(0.5f, 1.0f);
                if (func_800D9154(&param_0->unk58, local_3 / (f32)_gcstatusDll_entrypoint_11())) {
                    local_5 = func_800DC0C0();
                    if (local_5 < 0.25f) {
                        local_4 = 0;
                    } else if (local_5 < 0.6f) {
                        local_4 = 1;
                    } else {
                        local_4 = 2;
                    }
                    func_80108B04(param_0, local_4);
                }
            }
        }
        break;
    case 4:
        if (_susubgame_entrypoint_9()) {
            _susubgame_entrypoint_5(param_0, local_0 + 0x10, 5, 1, 0);
            _subaddiedialog_entrypoint_11(param_0->unk0,
                *(s32 *)(local_0 + 8), *(s32 *)(local_0 + 0xC), 0, 0xB3);
            func_80101FDC(param_0, 5);
        }
        break;
    }
}

int func_8080101C_chmonsterinterior(param_0, param_1) s32 param_0; s32 param_1;
{
  u8 *local_0;
  local_0 = func_80100094(param_0, 0);
  _sumultiscore_entrypoint_12(local_0 + 0x28, param_1, 1);
}

s32 func_80801050_chmonsterinterior(param_0, param_1, param_2) Actor *param_0; s32 param_1; s32 param_2;
{
    switch (param_1) {
    case 0x2E:
        func_80801114_chmonsterinterior(param_0, ((s16 *)&param_2)[0], ((s16 *)&param_2)[1]);
        break;
    case 0x30:
        return func_80801180_chmonsterinterior(param_0, ((s16 *)&param_2)[0], ((s16 *)&param_2)[1]);
    case 0x3D:
        func_80800A44_chmonsterinterior(param_0, param_2);
        break;
    case 0x95:
        _subaddiemulti_entrypoint_1(0, 0);
        func_800BF544(0, 0, 0);
        func_800BF544(1, 0, 0);
        break;
    default:
        return 0;
    }
    return 1;
}

void func_80801114_chmonsterinterior(param_0, param_1, param_2) s32 param_0; s32 param_1; s32 param_2;
{
    switch (param_1) {
    case 0xCEC:
        func_8080068C_chmonsterinterior(param_0);
        break;
    case 0x17F8:
    case 0x17F9:
        _subaddiemulti_entrypoint_2(param_0);
        func_80101FDC(param_0, 6);
        _gcfrontend_entrypoint_10();
        break;
    }
}

s32 func_80801180_chmonsterinterior(param_0, param_1, param_2) Actor *param_0; s32 param_1; s32 param_2;
{
  s32 new_var;
  new_var = param_1;
  if (new_var == 0x17F8)
  {
    s32 local_0;
    local_0 = func_80100094(param_0, 0);
    ;
    ;
    return (*((s32 *) (((char *) local_0) + 4))) + 1;
  }
  return 0;
}

void func_808011BC_chmonsterinterior(Actor *param_0)
{
    u8 *local_1;
    s32 local_0[8];
    s32 local_2;
    s32 local_3;
    s32 local_4;
    s32 local_8;
    s32 local_5;
    s32 local_7;

    local_1 = func_80100094(param_0, 0);
    local_2 = -1;
    for (local_3 = 0; local_3 < _gcstatusDll_entrypoint_11(); local_3++) {
        local_0[local_3] = _sumultiscore_entrypoint_8(local_1 + 0x28, local_3, 8);
        if (local_2 < local_0[local_3]) {
            local_2 = local_0[local_3];
        }
        func_800AA20C(local_3, local_0[local_3]);
    }
    for (local_3 = 0; local_3 < _gcstatusDll_entrypoint_11(); local_3++) {
        if (local_2 == local_0[local_3]) {
            _sumultiscore_entrypoint_11(local_1 + 0x28, local_3, 8, 3.0f);
        }
    }
    for (local_4 = 1; local_4 < _gcstatusDll_entrypoint_11(); local_4++) {
        for (local_8 = local_4; local_8 > 0 && local_0[local_8 - 1] < local_0[local_8]; local_8--) {
            local_5 = local_0[local_8];
            local_0[local_8] = local_0[local_8 - 1];
            local_0[local_8 - 1] = local_5;
        }
    }
    func_800FC6B0(0x16);
    if (local_0[0] != local_0[1]) {
        for (local_8 = 0; _sumultiscore_entrypoint_8(local_1 + 0x28, local_8, 8) != local_0[0]; local_8++) {
        }
        *(s32 *)(local_1 + 4) = local_8;
        local_7 = 0x17F8;
    } else {
        local_7 = 0x17F9;
    }
    _subaddiemulti_entrypoint_1(0, 0);
    func_80101FDC(param_0, 4);
    *(s32 *)(local_1 + 8) = local_7;
    *(s32 *)(local_1 + 0xC) = 6;
}

f32 func_80801B7C_chmonsterinterior();

f32 func_80801ADC_chmonsterinterior();

void func_808013D0_chmonsterinterior(Actor *param_0)
{
    u8 *local_0;
    s32 local_1;
    local_0 = func_80100094(param_0, 0);
    local_1 = param_0->actorData[5];
    func_8010A3E8(param_0, 0.3f);
    *(s32 *)(local_0 + 0xC) = 0;
    param_0->position[1] -= 250.0f;
    *(f32 *)((u8 *)param_0 + 0x28) = 0.6f;
    *(f32 *)((u8 *)param_0 + 0x30) = func_80801ADC_chmonsterinterior(local_1, (f32 *)(local_0 + 0x28));
    param_0->unk58 = func_80801B7C_chmonsterinterior(local_1);
    func_80102FDC(param_0, func_800DC178(0.6f, 0.8f));
    _subaddieDll_entrypoint_1(param_0);
    _subaddierouteDll_entrypoint_3(param_0, local_0, param_0->position);
    _subaddierouteDll_entrypoint_1(param_0);
    if (param_0->unk64_19) {
        param_0->unk64_24 = 0;
        param_0->unk58 = 5.5f;
    }
    func_8010D930(4, *(u32 *)((u8 *)param_0 + 0x70) & 1, param_0->position, D_8080201C_chmonsterinterior);
}

s32 func_80801C78_chmonsterinterior();

s32 func_80801C1C_chmonsterinterior();

void func_808014E8_chmonsterinterior(Actor *param_0)
{
    u8 *local_0;
    f32 local_1;
    f32 local_2;
    f32 *local_3;

    local_0 = func_80100094(param_0, 0);
    local_1 = func_800D8FF8();
    if (param_0->unk70_10 != 4 && func_800CEAD0(param_0->unk6C_0) && !param_0->unk64_19) {
        func_8010A570(param_0);
        func_80101FDC(param_0, 4);
        _subaddiefade_entrypoint_3(param_0);
    }
    switch (param_0->unk70_10) {
    case 1:
        if (func_80801C1C_chmonsterinterior(param_0)) {
            func_80101FDC(param_0, 2);
        }
        break;
    case 2:
        func_8010C93C(param_0, param_0->position, 1.0f);
        local_3 = &param_0->unk54;
        if (((MonsterControlledFlag1121 *)param_0)->local_0) {
            local_2 = _subaddiejoy_entrypoint_9(param_0, local_3, 3);
            ((f32 *)param_0->actorData)[3] = *(f32 *)(local_0 + 0x28) * 1.4f;
            func_80102BF8(param_0, 0.2f, 8.0f, 600.0f);
            func_8010C3A8(param_0, 0x200025, local_2);
        } else {
            if (_subaddierouteDll_entrypoint_4(param_0)) {
                _subaddierouteDll_entrypoint_7(param_0, local_0, param_0->rotation[1], param_0->unk54, 400.0f, 0x4802);
                *(s32 *)(local_0 + 0xC) = *(u16 *)(local_0 + 6);
            }
            _subaddierouteDll_entrypoint_6(param_0, local_0, *(s32 *)(local_0 + 0xC), 0x3F, 0.4f, 20, 40);
            _subaddierouteDll_entrypoint_5(param_0, local_0, *(s32 *)(local_0 + 0xC), 0.2f, 4.0f, 200.0f);
            ((f32 *)param_0->actorData)[3] = func_800F15F8(((f32 *)param_0->actorData)[3],
                ((f32 *)param_0->actorData)[6], local_1 * 800.0f);
            if (!param_0->unk64_19) {
                func_8010B990(param_0, 0x325);
            }
        }
        if (func_800D9078(&param_0->unk58)) {
            func_80101FDC(param_0, 3);
            ((f32 *)param_0->actorData)[4] = 0.6f;
            param_0->unk64_24 = 0;
        }
        break;
    case 3:
        if (!param_0->unk64_19 && func_800F10B4(((f32 *)param_0->actorData)[4], 0.0f, 0.6f, 1.0f, 0.0f) > 0.3f) {
            func_8010D930(5, *(u32 *)((u8 *)param_0 + 0x70) & 1, param_0->position, D_80802030_chmonsterinterior);
            param_0->unk64_19 = 1;
        }
        if (func_80801C78_chmonsterinterior(param_0)) {
            func_800FFAB0(param_0);
        }
        break;
    case 4:
        break;
    }
}

void func_808017E8_chmonsterinterior(s32 arg0) 
{
}
s32 func_808017F0_chmonsterinterior(Actor *param_0, s32 param_1, MonsterEvent60 param_2)
{
    void *local_0;

    switch (param_1) {
        case 0x40:
            func_80801930_chmonsterinterior(param_0, param_2.local_1);
            break;
        case 0x99:
            func_80101074(param_0->unk64_20 ? 0 : D_80801E58_chmonsterinterior);
            break;
        case 0x1F:
            local_0 = *(void **)&param_2;
            if (param_0->unk64_20) func_8010DD20(param_0, param_0->unk6C_9 - 0x44B, local_0);
            else func_801015D0(param_0);
            break;
        case 0x29:
            if (param_0->unk64_20) func_8010DC50(param_0->unk6C_9 - 0x44B);
            break;
        case 0x2A:
            if (param_0->unk64_20) func_8010DCB4(param_0->unk6C_9 - 0x44B);
            break;
        default:
            return 0;
    }
    return 1;
}

void func_80801930_chmonsterinterior(param_0, param_1) s32 param_0; Actor *param_1; {
    s32 local_6;
    s32 *local_0;
    s32 local_1;
    s32 local_2;
    s32 local_3;
    f32 local_4[3];
    f32 local_5[3];

    local_6 = func_80106790(*(s32 **)((char *)param_0 + 0x3C));
    local_0 = func_80100094(local_6, 0);
    if (func_800D3948() != 0) {
        local_1 = 2;
    } else {
        local_1 = func_800DC128(6, 8);
    }
    local_2 = func_800B53A4(local_1);
    local_3 = _subaddiemulti_entrypoint_5(param_1);
    func_80103DFC(param_0, local_4);
    func_800BABB8(local_2, local_4, local_4, 0x3F800000, D_80802044_chmonsterinterior);
    func_800BA670(local_2, *(s16*)((char*)D_8080208C_chmonsterinterior + (*(s32 *)((char *)param_0 + 0x2C)) * 2));
    func_800BA22C(local_2, local_1);
    if (func_800D3948() != 0) {
        _sumultiscore_entrypoint_7(local_0 + 0xA, local_3, 8, *(s16*)((char*)D_80801E50_chmonsterinterior + (*(s32 *)((char *)param_0 + 0x2C)) * 2));
    } else {
        *local_0 += *(s16*)((char*)D_80801E50_chmonsterinterior + (*(s32 *)((char *)param_0 + 0x2C)) * 2);
    }
    func_8010D930(1, (*(s32 *)((char *)param_0 + 0x70)) & 1, local_4, D_8080207C_chmonsterinterior);
    func_80103DFC(param_0, local_5);
    _chscorepoints_entrypoint_2(*(s16*)((char*)D_80801E50_chmonsterinterior + (*(s32 *)((char *)param_0 + 0x2C)) * 2), local_3, local_5, 1);
    func_800FFAB0(param_0);
    if ((*(u16 *)((char *)param_1 + 0x18)) & 1) {
        func_8010114C(param_1, 0x98, 0);
    }
}

f32 func_80801ADC_chmonsterinterior(s32 param_0, f32 *param_1)
{
    switch (param_0) {
        case 0:
            *param_1 = 600.0f;
            return func_800DC178(500.0f, 600.0f);
        case 1:
            *param_1 = 450.0f;
            return func_800DC178(350.0f, 450.0f);
        case 2:
            *param_1 = 300.0f;
            return func_800DC178(200.0f, 300.0f);
        default:
            return -1.0f;
    }
}

f32 func_80801B7C_chmonsterinterior(s32 param_0)
{
    switch (param_0) {
        case 0:
            return func_800DC178(2.5f, 3.0f);
        case 1:
            return func_800DC178(3.0f, 3.5f);
        case 2:
            return func_800DC178(3.5f, 4.5f);
        default:
            return -1.0f;
    }
}

s32 func_80801C1C_chmonsterinterior(u8 *param_0) {
    s32 local_0 = func_800D9078(param_0 + 0x28);
    *(f32 *)(param_0 + 8) = func_800F12D4(*(f32 *)(param_0 + 0x28), 0.0f, 0.6f, 0.0f, -250.0f);
    return local_0;
}

s32 func_80801C78_chmonsterinterior(u8 *param_0) {
    s32 local_0 = func_800D9078(param_0 + 0x28);
    *(f32 *)(param_0 + 8) = func_800F12D4(*(f32 *)(param_0 + 0x28), 0.0f, 0.6f, -250.0f, 0.0f);
    return local_0;
}

/* TU-NOTE: the .data of this overlay (formerly asm/data/overlays/ch/monsterinterior.data.s) is defined here in C.
 * Its tables hold pointers to functions of this file; IDO's assembler schedules some of these
 * functions differently unless the tables are defined in the same unit. Values are taken from the ROM.
 * extern declarations adjusted to the object (same addresses): D_80801F10_chmonsterinterior -> int[], D_80801FA0_chmonsterinterior -> int[] */
extern void func_801018A4();
extern void func_80108ED0();
u8 D_80801E50_chmonsterinterior[8] = { 0x0, 0x3, 0x0, 0x2, 0x0, 0x1, 0x0, 0x0 };
u8 D_80801E58_chmonsterinterior[40] = { 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x3F, 0x80, 0x0, 0x0, 0x3, 0x61, 0x0, 0x4A, 0x40, 0x80, 0x0, 0x0, 0x3, 0x62, 0x0, 0x9, 0x3F, 0x80, 0x0, 0x0, 0x3, 0x61, 0x0, 0x92, 0x3F, 0x80, 0x0, 0x0, 0x3, 0x61, 0x0, 0x9 };
void *D_80801E80_chmonsterinterior = (void *)0x01580451;
static u32 D_80801E80_chmonsterinterior_rest[17] = { 0x1, 0x0, (u32)func_808000BC_chmonsterinterior, (u32)func_80105834, (u32)func_80101870, 0x0, 0x0, 0x0, 0x1, (u32)func_8080060C_chmonsterinterior, 0x0, 0x5440000, (u32)func_8080003C_chmonsterinterior, (u32)func_80107C2C, 0x80000602, (u32)func_808002D4_chmonsterinterior, 0x0 };
void *D_80801EC8_chmonsterinterior = (void *)0x01580455;
static u32 D_80801EC8_chmonsterinterior_rest[17] = { 0xFFFF0001, 0x0, (u32)func_80800E0C_chmonsterinterior, (u32)func_80105834, (u32)func_8080101C_chmonsterinterior, 0x0, 0x0, 0x0, 0x400401, (u32)func_8080060C_chmonsterinterior, 0x0, 0x5440000, (u32)func_80800DA4_chmonsterinterior, (u32)func_80107C2C, 0x80000402, (u32)func_80801050_chmonsterinterior, 0x0 };
int D_80801F10_chmonsterinterior[18] = { 0x2A60452, -0xFFFF, 0x0, (u32)func_808014E8_chmonsterinterior, (u32)func_80105834, (u32)func_801018A4, 0x0, 0x0, 0x0, 0x124, (u32)func_808017E8_chmonsterinterior, (u32)func_80108ED0, 0x2C0000, (u32)func_808013D0_chmonsterinterior, (u32)func_80107C2C, -0x7FDBEFFF, (u32)func_808017F0_chmonsterinterior, 0x0 };
s32 D_80801F58_chmonsterinterior[18] = { 0x2A60453, -0xFFFF, 0x0, (u32)func_808014E8_chmonsterinterior, (u32)func_80105834, (u32)func_801018A4, 0x0, 0x0, 0x0, 0x124, (u32)func_808017E8_chmonsterinterior, (u32)func_80108ED0, 0x2C0000, (u32)func_808013D0_chmonsterinterior, (u32)func_80107C2C, -0x7FDBEFFF, (u32)func_808017F0_chmonsterinterior, 0x0 };
int D_80801FA0_chmonsterinterior[18] = { 0x2A60454, -0xFFFF, 0x0, (u32)func_808014E8_chmonsterinterior, (u32)func_80105834, (u32)func_801018A4, 0x0, 0x0, 0x0, 0x124, (u32)func_808017E8_chmonsterinterior, (u32)func_80108ED0, 0x2C0000, (u32)func_808013D0_chmonsterinterior, (u32)func_80107C2C, -0x7FDBEFFF, (u32)func_808017F0_chmonsterinterior, 0x0 };
u8 D_80801FE8_chmonsterinterior[8] = { 0x8, 0x6, 0x8, 0x4, 0x8, 0x5, 0x0, 0x0 };
u8 D_80801FF0_chmonsterinterior[44] = { 0x9, 0x9F, 0x9, 0x9E, 0x9, 0x9D, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0xFF, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0xFF, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0xFF, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0 };
u8 D_8080201C_chmonsterinterior[20] = { 0x0, 0x13, 0x4, 0xB2, 0x0, 0xD, 0x0, 0xA6, 0x0, 0xC0, 0x0, 0x1, 0x3, 0x20, 0x8, 0x98, 0x0, 0x0, 0x0, 0x0 };
u8 D_80802030_chmonsterinterior[20] = { 0x0, 0x13, 0x6, 0xF, 0x0, 0xD, 0x0, 0xF3, 0x1, 0xC, 0x0, 0x1, 0x3, 0x20, 0x8, 0x98, 0x0, 0x0, 0x0, 0x0 };
u8 D_80802044_chmonsterinterior[56] = { 0x0, 0x16, 0x12, 0x0, 0x0, 0x15, 0x0, 0x0, 0x0, 0xCC, 0x0, 0x2B, 0x0, 0xB3, 0x0, 0xCC, 0x0, 0x22, 0x0, 0xCC, 0x1, 0x33, 0x0, 0x80, 0x0, 0x99, 0x0, 0x2D, 0x2, 0x58, 0x3, 0x20, 0x0, 0x27, 0xFF, 0x38, 0xFF, 0x38, 0x0, 0xC8, 0x0, 0xC8, 0x0, 0xE, 0x0, 0x19, 0x0, 0x32, 0x0, 0x1B, 0xFC, 0x18, 0xFC, 0xE0, 0x0, 0x0 };
u8 D_8080207C_chmonsterinterior[16] = { 0x0, 0x13, 0x4, 0x1F, 0x0, 0x18, 0x0, 0xD, 0x0, 0xF3, 0x1, 0xC, 0x0, 0x0, 0x0, 0x0 };
u8 D_8080208C_chmonsterinterior[20] = { 0x9, 0x22, 0x9, 0x21, 0x9, 0x20, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0 };
