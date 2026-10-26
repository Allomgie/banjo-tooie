#include "common.h"

extern int D_80801A5C_chnicecavemen;
extern int D_80801AA4_chnicecavemen;
extern void *D_80801AEC_chnicecavemen;
extern s32 D_80801B34_chnicecavemen[];
extern u8 D_808018D8_chnicecavemen[];
extern void *func_80100094(Actor *, u32);
extern void _suexpression_entrypoint_12(s32, f32, f32);
extern void _subaddiepalette_entrypoint_4();
extern void func_800F7F98(void *, s32);
extern void *func_800F54E4(void);
extern s32 func_800DA298();
extern void _subaddiedialog_entrypoint_11(s32, s32, s32, s32, s32);
extern void _gcdialogcamera_entrypoint_3(u8 *, f32);
extern s32 _suexpression_entrypoint_7(Actor *, s32, s32);
extern void _suexpression_entrypoint_17(s32, s32);
typedef struct { u8 pad_0[0x14]; u16 local_0; u8 pad_1[2]; s16 local_1; u8 pad_2[2]; f32 local_2; f32 local_3; } NiceCavemanPalette1828;
extern f32 func_800F12D4(f32, f32, f32, f32, f32);
extern void _subaddiepalette_entrypoint_3();
extern void func_800DF6BC();
extern void func_800DF744();
extern void func_801015D0();
extern u8 D_80801810_chnicecavemen[];
extern u8 D_80801848_chnicecavemen[];
extern u8 D_80801880_chnicecavemen[];
extern u8 D_808018B8_chnicecavemen[];
extern s32 _subaddiedialog_entrypoint_9(Actor *, s32, s32, s32);
extern u8 D_808018E8_chnicecavemen[];
extern void func_800F8300(s32, s32, f32 *);
extern s32 func_800DC298(f32);
extern s32 _subaddiedialog_entrypoint_8(Actor *, f32 *, void *, s32, s32);
extern u8 unk18[];
typedef union { u8 *local_0; s32 local_1; } CaveEvent60;
extern int _chfirefx_entrypoint_5(Actor *, s32, void *);
extern u8 D_80801B7C_chnicecavemen[];
extern void func_800F4F34(s32, f32 *, f32, f32);
typedef struct { s32 v[7]; } CavemenSnd;
typedef struct { u8 pad0[0x70]; u32 pad70_1:31; u32 unk70_0:1; } CavemenBits;
extern u8 D_80801BC0_chnicecavemen[];
extern f32 D_80801CA0_chnicecavemen[];
extern f32 D_80801CB8_chnicecavemen[];
extern f32 D_80801CD0_chnicecavemen[];
extern u8 D_80801BEC_chnicecavemen[];
extern CavemenSnd D_80801B8C_chnicecavemen;
extern f32 D_80801C60_chnicecavemen[];
extern u8 D_80801D1C_chnicecavemen[];
extern u8 D_80801CEC_chnicecavemen[];
extern u8 D_80801CF4_chnicecavemen[];
extern u8 D_80801D08_chnicecavemen[];
extern f32 D_80801D28_chnicecavemen[];
extern f32 D_80801D38_chnicecavemen[];
extern f32 D_80801D48_chnicecavemen[];
extern f32 D_80801D5C_chnicecavemen[];
extern f32 D_80801D70_chnicecavemen[];
extern f32 D_80801C8C_chnicecavemen[];
extern f32 D_80801DA8_chnicecavemen[];
extern f32 D_80801C78_chnicecavemen[];
extern f32 D_80801D94_chnicecavemen[];
extern u8 D_80801C1C_chnicecavemen[];
extern f32 D_80801DB8_chnicecavemen[];
extern f32 D_80801BA8_chnicecavemen[];
extern s32 func_801022E4(Actor *);
extern f32 func_80101F24(Actor *);
extern s32 func_80101E14(Actor *, f32);
extern s32 _subaddieskeleton_entrypoint_2(Unk80132ED0 *, s32, f32 *);
extern void func_800EE7F8(f32 *, f32 *);
extern void func_800EF1B8(f32 *, f32, f32);
extern void func_800BABB8(s32, f32 *, f32 *, f32, u8 *);
extern void _subaddieaudioquick_entrypoint_2(Actor *, f32 *, f32 *);
extern s32 _subaddieaudioquick_entrypoint_4(Actor *, f32 *, f32 *, void *);
extern void func_800BBCB8(f32 *, f32 *, f32, s32, u8 *);
extern s32 func_80101E4C();
extern void func_8010D930();
extern s32 _subaddieaudioquick_entrypoint_3(Actor *, f32 *, f32 *, f32);
extern s32 func_800DC128(s32, s32);
extern void _subaddieaudioloop_entrypoint_4(Actor *, f32 *, s32, f32 *);
void func_80800624_chnicecavemen();
void func_8080077C_chnicecavemen();
int func_80800AB8_chnicecavemen();
int func_80800BF8_chnicecavemen();
int func_80800C6C_chnicecavemen();
void func_80801200_chnicecavemen();
s32 func_8080126C_chnicecavemen();
int func_808013D0_chnicecavemen();
int func_80801428_chnicecavemen();
int func_80801464_chnicecavemen();
int func_80801508_chnicecavemen();
int func_80801580_chnicecavemen();
void func_80800CC8_chnicecavemen();

int *chnicecavemen_entrypoint_0()
{
    return &D_80801A5C_chnicecavemen;
}

int chnicecavemen_entrypoint_1()
{
  return &D_80801AA4_chnicecavemen;
}

int chnicecavemen_entrypoint_2()
{
  return &D_80801AEC_chnicecavemen;
}

int chnicecavemen_entrypoint_3()
{
  return (int)D_80801B34_chnicecavemen;
}

void func_80800030_chnicecavemen(u8 *param_0) {
    s32 local_0;
    u32 local_1;

    local_1 = (u32)((u16) (*(u16 *)((s8 *)(param_0) + (0x76)))) >> 7;
    (*(s32 *)((s8 *)(param_0) + (0x30))) = 0;
    switch (local_1) {                              
    case 0x32:
        (*(s32 *)((s8 *)(param_0) + (0x28))) = 0x324;
        (*(s32 *)((s8 *)(param_0) + (0x2C))) = 0x16C;
        break;
    case 0x33:
        (*(s32 *)((s8 *)(param_0) + (0x28))) = 0x325;
        (*(s32 *)((s8 *)(param_0) + (0x2C))) = 0x16D;
        break;
    case 0x34:
        (*(s32 *)((s8 *)(param_0) + (0x28))) = 0x326;
        (*(s32 *)((s8 *)(param_0) + (0x2C))) = 0x16E;
        break;
    }
    if (_glcutDll_entrypoint_20() != 0) {
        local_0 = 0xD;
    } else if (func_800DA298((*(s32 *)((s8 *)(param_0) + (0x28)))) != 0) {
        if (func_800DA298((*(s32 *)((s8 *)(param_0) + (0x2C)))) != 0) {
            local_0 = 0xC;
        } else {
            local_0 = 0xA;
        }
    } else {
        if (func_800DA298((*(s32 *)((s8 *)(param_0) + (0x2C)))) != 0) {
            local_0 = 9;
        } else {
            local_0 = 1;
        }
    }
    func_80102424(param_0, local_0);
    func_80801200_chnicecavemen(param_0);
}

s32 func_8080134C_chnicecavemen();

void func_80800128_chnicecavemen(Actor *param_0)
{
    u8 *local_0;
    local_0 = func_80100094(param_0, 0);
    func_800F4F34(func_800F54E4(), param_0->position, 60.0f, 50.0f);
    _suexpression_entrypoint_10(func_80100094(param_0, 1), param_0->unk0, 0);
    switch (param_0->unk70_10) {
    case 1:
        if (func_800DA298(param_0->actorData[4])) {
            func_800F7B9C(func_800F54E4(), 0x93);
            func_80800AB8_chnicecavemen(param_0, 8);
        } else {
            func_8080134C_chnicecavemen(param_0, D_80801B7C_chnicecavemen, (s32)D_80801810_chnicecavemen, 7, 2);
        }
        break;
    case 5:
    case 6:
        func_80801178_chnicecavemen(param_0);
        if (*(f32 *)(local_0 + 0x10) > 0.75f) {
            func_80800AB8_chnicecavemen(param_0, 7);
        }
        break;
    case 7:
        func_80801178_chnicecavemen(param_0);
        if (func_80101DDC(param_0)) {
            if (*(s32 *)(local_0 + 0x824)) {
                if (*(s32 *)(local_0 + 0x824)) {
                    func_800F82D4(func_800F54E4(), 0);
                    *(s32 *)(local_0 + 0x824) = 0;
                }
                _subaddiedialog_entrypoint_11(param_0->unk0, 0x17D7, 14, param_0->position, 0xA2);
                func_80800AB8_chnicecavemen(param_0, func_800DA298(param_0->actorData[4]) ? 4 : 2);
            }
        }
        break;
    case 9:
        if (func_800DA298(param_0->actorData[4])) {
            func_80800AB8_chnicecavemen(param_0, 8);
        } else {
            func_8080134C_chnicecavemen(param_0, D_80801B7C_chnicecavemen, (s32)D_80801848_chnicecavemen, 7, 2);
        }
        break;
    case 10:
        func_8080134C_chnicecavemen(param_0, D_80801B7C_chnicecavemen, (s32)D_80801880_chnicecavemen, 7, 3);
        break;
    case 11:
        if (func_80101DDC(param_0)) {
            func_80800AB8_chnicecavemen(param_0, 12);
        }
        break;
    case 12:
        func_8080134C_chnicecavemen(param_0, D_80801B7C_chnicecavemen, (s32)D_808018B8_chnicecavemen, 4, 4);
        break;
    }
    func_80800CC8_chnicecavemen(param_0);
    _subaddiepalette_entrypoint_1(param_0, local_0 + 0x14);
}

void func_808003B8_chnicecavemen(Actor* arg0) 
{
    _suexpression_entrypoint_8(arg0, 1);
}
int func_808003D8_chnicecavemen(Actor *param_0, s32 param_1, s32 param_2)
{
    s32 local_2;
    s32 local_0;
    s32 local_1;
    f32 local_3;
    switch (param_1) {
    case 0x2E:
        func_8080077C_chnicecavemen(param_0, ((s16 *)&param_2)[0], ((s16 *)&param_2)[1]);
        break;
    case 0x29:
        _subaddiepalette_entrypoint_4(param_0, (u8 *)func_80100094(param_0, 0) + 0x14);
        break;
    case 0xB:
        switch (param_2) {
        case 9:
        case 12:
        case 16:
            func_800F7F98(func_800F54E4(), 0);
            if (!func_80800C6C_chnicecavemen(param_0)) {
                if (func_800DA298(param_0->actorData[5])) local_0 = 0x17D9;
                else local_0 = 0x17D4;
                func_80801464_chnicecavemen(param_0, 3, 1);
                _subaddiedialog_entrypoint_11(param_0->unk0, local_0, 0xE, param_0->position, 0xA2);
            }
            return 4;
        case 1:
            if (func_800F64A4(func_800F54E4(), 0x400)) local_1 = 0x1811;
            else local_1 = 0x17FD;
            func_80801464_chnicecavemen(param_0, 3, 1);
            _subaddiedialog_entrypoint_11(param_0->unk0, local_1, 0xE, param_0->position, 0xA2);
            return 4;
        default:
            return 3;
        }
    case 0x1F:
        func_80800624_chnicecavemen(param_0, *(s32 *)&param_2);
        break;
    case 0x52:
        _gcdialogcamera_entrypoint_3(D_808018D8_chnicecavemen, param_0->scale);
        break;
    case 0x57:
        return func_808013D0_chnicecavemen(param_0, param_2 & 0xFFFF, (u32)(param_2 & 0xFFFF0000) >> 16);
    case 0x95:
        local_2 = _suexpression_entrypoint_7(param_0, 1, 0xA2);
        _suexpression_entrypoint_12(local_2, 6e+01f, 15.0f);
        _suexpression_entrypoint_17(local_2, 800);
        break;
    default:
        return 0;
    }
    return 1;
}

void func_80800624_chnicecavemen(param_0, param_1) Actor *param_0; s32 param_1;
{
    s32 local_2;
    s32 local_3;
    NiceCavemanPalette1828 *local_0;
    s32 local_1;
    s32 local_4;

    local_0 = (NiceCavemanPalette1828 *)func_80100094(param_0, 0);
    local_1 = func_801022E4(param_0);
    func_801015D0(param_0);
    local_2 = param_0->unk6C_9 == 0x42C ? 1 : 0;
    switch (local_1) {
    case 0x2D5:
    case 0x2D6:
        local_3 = 1;
        break;
    default:
        local_3 = 0;
        break;
    }
    func_800DF744(3, local_2, local_3);
    func_800DF744(4, local_2);
    func_800DF744(5, local_3);
    func_800DF744(7, param_0->unk74_7 - 0x31);
    func_800DF744(8, param_0->unk74_7 - 0x31);
    if (local_0->local_1 == 1) {
        local_4 = (s32)func_800F12D4(local_0->local_2, 0.0f, local_0->local_3, 0.0f, 255.0f);
    } else {
        local_4 = local_0->local_0 == 0x7E7 ? 0 : 255;
    }
    func_800DF6BC(local_4, 255);
    _subaddiepalette_entrypoint_3(param_0, &local_0->local_0, param_1);
}

void func_8080077C_chnicecavemen(param_0, param_1, param_2) Actor *param_0; s32 param_1; s32 param_2;
{
    void *local_0;
    s32 local_1;
    s32 local_2;
    s32 local_3;
    s32 local_4;
    s32 local_5;

    switch (param_1) {
    case 0x17D5:
    case 0x1803:
        if (param_2 > 0) {
            local_0 = func_80100094(param_0, 0);
            func_800FC660(0xE);
            func_80800AB8_chnicecavemen(param_0, func_800DA298(param_0->actorData[4]) ? 6 : 5);
            _subaddieitem_entrypoint_0(local_0, param_0->actorData[6], -1, 1);
            _subaddieitem_entrypoint_2(local_0);
        } else {
            _subaddiedialog_entrypoint_11(param_0->unk0, 0x17D6, 15, param_0->position, 0xA2);
        }
        break;
    case 0x17D7:
        if (!func_80800BF8_chnicecavemen(param_0)) {
            func_80801428_chnicecavemen(param_0);
        }
        func_80800AB8_chnicecavemen(param_0, func_800DA298(param_0->actorData[4]) ? 12 : 9);
        break;
    case 0x17D8:
        func_80801508_chnicecavemen(param_0, 1, 0x30);
        func_800D1000(0x2D, 1, NULL, 1, NULL);
        break;
    case 0x17FD:
    case 0x1811:
        func_80801428_chnicecavemen(param_0);
        func_80800AB8_chnicecavemen(param_0, 12);
        break;
    default:
        local_1 = _subaddiedialog_entrypoint_9(param_0, param_1, (s32)D_80801810_chnicecavemen, 7);
        local_2 = _subaddiedialog_entrypoint_9(param_0, param_1, (s32)D_80801848_chnicecavemen, 7);
        local_3 = _subaddiedialog_entrypoint_9(param_0, param_1, (s32)D_80801880_chnicecavemen, 7);
        local_4 = _subaddiedialog_entrypoint_9(param_0, param_1, (s32)D_808018B8_chnicecavemen, 4);
        if (_subaddiedialog_entrypoint_10(local_1) || _subaddiedialog_entrypoint_10(local_3)) {
            if (func_80801580_chnicecavemen(param_0)) {
                _subaddiedialog_entrypoint_11(param_0->unk0, func_8080126C_chnicecavemen(param_0), 0x4E,
                                            param_0->position, 0xA2);
            } else {
                func_800C01A8(100, 0);
                func_800C0850();
                func_80801428_chnicecavemen(param_0);
                func_80800AB8_chnicecavemen(param_0, func_800DA298(param_0->actorData[4]) ? 10 : 1);
            }
        } else if (_subaddiedialog_entrypoint_10(local_2)) {
            func_80801428_chnicecavemen(param_0);
            func_80800AB8_chnicecavemen(param_0, 9);
        } else if (_subaddiedialog_entrypoint_10(local_4)) {
            if (!func_80800BF8_chnicecavemen(param_0)) {
                func_80801428_chnicecavemen(param_0);
            }
            func_80800AB8_chnicecavemen(param_0, 12);
        } else {
            if (func_800DA298(param_0->actorData[4])) {
                if (func_800DA298(param_0->actorData[5])) {
                    local_5 = 12;
                } else {
                    local_5 = 10;
                }
            } else if (func_800DA298(param_0->actorData[5])) {
                local_5 = 9;
            } else {
                local_5 = 1;
            }
            func_80801428_chnicecavemen(param_0);
            func_80800AB8_chnicecavemen(param_0, local_5);
        }
        break;
    }
}

int func_80800AB8_chnicecavemen(param_0, param_1) Actor *param_0; s32 param_1;
{
  s32 local_0;
  s32 local_1;
  u32 local_2;
  local_0 = func_80100094(param_0, 0);
  switch (param_1)
    {
    case 7:
        break;
    case 11:
        if (func_801021BC(param_0, 0xB) != 0)
        {
            break;
        }
        param_1 = 0xC;
        /* fallthrough */
    case 12:
        func_80800C6C_chnicecavemen(param_0);
        break;
    case 8:
        local_1 = 0;
        local_2 = (u32)(*(u16 *)((char *)param_0 + 0x76)) >> 7;
        switch (local_2)
        {
        case 0x32:
            local_1 = 0x10;
            break;
        case 0x33:
            local_1 = 0xC;
            break;
        case 0x34:
            local_1 = 9;
            break;
        }
        func_80801508_chnicecavemen(param_0, local_1, 0x28, param_1);
        func_800F7F98(func_800F54E4(), 1);
        if (_subaddiepalette_entrypoint_2(param_0, local_0 + 0x14, 0x7E7, 0x40400000) != 0)
        {
            func_800BBCB8((f32 *)((char *)param_0 + 0x4), 0, 1.0f, 1, &D_808018E8_chnicecavemen);
        }
        break;
    }
  func_80102424(param_0, param_1);
}

int func_80800BF8_chnicecavemen(param_0) s32 param_0;
{
    int local_0;
    s32 local_1;

    if (!func_800D0A9C(0x2D, 1)) {
        local_0 = func_800DA980(0x16C, 3) == 3;
        local_1 = func_800DA980(0x324, 3) == 3;
        return local_0 && local_1;
    }
    return 0;
}

int func_80800C6C_chnicecavemen(param_0) s32 param_0[4];
{
  if (func_80800BF8_chnicecavemen())
  {
    func_80102424(param_0, 4);
    _subaddiedialog_entrypoint_11(param_0[0], 0x17D8, 0xE, &param_0[1], 0xA2);
    return 1;
  }
  return 0;
}

void func_80800CC8_chnicecavemen(param_0) Actor *param_0;
{
    s32 local_0;
    f32 local_1;
    s32 local_2;
    f32 local_3[3];
    f32 local_4[3];
    f32 local_5[3];
    CavemenSnd local_6;
    s32 local_7;
    s32 local_8;
    f32 local_9[3];
    f32 local_10[3];

    local_0 = func_801022E4(param_0);
    local_1 = func_80101F24(param_0);
    local_2 = 0;
    switch (local_0) {
    case 0x2CD:
        if (func_80101E14(param_0, 0.7f)) {
            if (_subaddieskeleton_entrypoint_2(param_0->unk0, 4, local_3)) {
                func_800EE7F8(local_4, local_3);
                func_800EF1B8(local_4, param_0->rotation[1], -50.0f);
                local_4[1] += 30.0f;
                func_800BABB8(0, local_3, local_4, 1.0f, D_80801BC0_chnicecavemen);
            }
            _subaddieaudioquick_entrypoint_2(param_0, param_0->position, D_80801CA0_chnicecavemen);
        }
        local_2 = 1;
        break;
    case 0x2CF:
        if (_subaddieaudioquick_entrypoint_4(param_0, param_0->position, D_80801CB8_chnicecavemen, D_80801CD0_chnicecavemen) && func_800DC298(0.4f) && _subaddieskeleton_entrypoint_2(param_0->unk0, 5, local_5)) {
            func_800BBCB8(local_5, param_0->position, 1.0f, 3, D_80801BEC_chnicecavemen);
        }
        local_2 = 0.4f < local_1;
        break;
    case 0x2CE:
        local_6 = D_80801B8C_chnicecavemen;
        _subaddieaudioquick_entrypoint_4(param_0, param_0->position, D_80801C60_chnicecavemen, &local_6);
        local_2 = local_1 < 0.6f;
        break;
    case 0x2D0:
    case 0x2D1:
    case 0x2D2:
        if (func_80101E4C(param_0, D_80801D1C_chnicecavemen)) {
            func_8010D930(4, ((CavemenBits *)param_0)->unk70_0, param_0->position, D_80801CEC_chnicecavemen);
        }
        if (func_80101E14(param_0, 0.83f)) {
            func_8010D930(4, ((CavemenBits *)param_0)->unk70_0, param_0->position, D_80801CF4_chnicecavemen);
        }
        if (func_80101E14(param_0, 0.08f)) {
            func_8010D930(4, ((CavemenBits *)param_0)->unk70_0, param_0->position, D_80801D08_chnicecavemen);
        }
        break;
    case 0x2D6:
        _subaddieaudioquick_entrypoint_3(param_0, param_0->position, D_80801D28_chnicecavemen, 0.05f);
        _subaddieaudioquick_entrypoint_3(param_0, param_0->position, D_80801D38_chnicecavemen, 0.16f);
        break;
    case 0x2D4:
        _subaddieaudioquick_entrypoint_4(param_0, param_0->position, D_80801D48_chnicecavemen, D_80801D5C_chnicecavemen);
        break;
    case 0x2D3:
        _subaddieaudioquick_entrypoint_4(param_0, param_0->position, D_80801C60_chnicecavemen, D_80801D70_chnicecavemen);
        break;
    case 0x2E2:
        local_7 = 0;
        _subaddieaudioquick_entrypoint_4(param_0, param_0->position, D_80801C8C_chnicecavemen, D_80801DA8_chnicecavemen);
        if (_subaddieaudioquick_entrypoint_3(param_0, param_0->position, D_80801C78_chnicecavemen, 0.3f)) {
            local_7 = 1;
            local_8 = 4;
        }
        if (_subaddieaudioquick_entrypoint_3(param_0, param_0->position, D_80801D94_chnicecavemen, 0.84f)) {
            local_7 = 1;
            local_8 = 6;
        }
        if (local_7 && _subaddieskeleton_entrypoint_2(param_0->unk0, local_8, local_9)) {
            func_800EE7F8(local_10, local_9);
            func_800EF1B8(local_10, param_0->rotation[1] - 30.0f, -20.0f);
            local_10[1] -= 30.0f;
            func_800BBCB8(local_9, local_10, 1.0f, func_800DC128(4, 8), D_80801C1C_chnicecavemen);
        }
        break;
    case 0x2E1:
        _subaddieaudioquick_entrypoint_4(param_0, param_0->position, D_80801C8C_chnicecavemen, D_80801DB8_chnicecavemen);
        _subaddieaudioquick_entrypoint_3(param_0, param_0->position, D_80801C78_chnicecavemen, 0.3f);
        break;
    }
    _subaddieaudioloop_entrypoint_4(param_0, param_0->position, local_2, D_80801BA8_chnicecavemen);
}

int func_80801178_chnicecavemen(Actor *param_0)
{
    u8 *local_0;
    f32 local_1[3];
    local_0 = func_80100094(param_0, 0);
    _subaddieskeleton_entrypoint_3(param_0->unk0, 4, local_1);
    if (_subaddieitem_entrypoint_3(param_0, local_1, local_0)) {
        *(s32 *)(local_0 + 0x824) = 1;
        func_800F8300(func_800F54E4(), 2, param_0->position);
        func_800DA544(param_0->actorData[5]);
        return 1;
    }
    return 0;
}

void func_80801200_chnicecavemen(param_0) u8 *param_0; {
    s32 sp1C;
    s32 var_v0;

    sp1C = func_80100094(param_0, 0);
    if ((func_800DA298((*(s32 *)((char *)(param_0) + 0x28))) != 0) || (_glcutDll_entrypoint_20() != 0)) {
        var_v0 = 0x7E7;
    } else {
        var_v0 = 0x7E6;
    }
    _subaddiepalette_entrypoint_0(param_0, sp1C + 0x14, var_v0 & 0xFFFF);
}

s32 func_8080126C_chnicecavemen(param_0) Actor *param_0;
{
    s32 local_0;

    local_0 = func_800F54E4();
    if (param_0->actorData[6] == 0) {
        if (func_800DC298(0.5f)) {
            if (func_800F640C(local_0, 0x3CA) > 0) param_0->actorData[6] = 0x3CA;
            else param_0->actorData[6] = 0x3CB;
        } else {
            if (func_800F640C(local_0, 0x3CB) > 0) param_0->actorData[6] = 0x3CB;
            else param_0->actorData[6] = 0x3CA;
        }
    } else if (!func_800F640C(local_0, param_0->actorData[6])) {
        param_0->actorData[6] = param_0->actorData[6] == 0x3CA ? 0x3CB : 0x3CA;
    }
    return param_0->actorData[6] == 0x3CA ? 0x17D5 : 0x1803;
}

s32 func_8080134C_chnicecavemen(Actor *param_0, u8 *param_1, s32 param_2, s32 param_3, s32 param_4)
{
    s32 local_0;

    param_1[0xE] = param_4;
    local_0 = _subaddiedialog_entrypoint_8(param_0, param_0->position, param_1, param_2, param_3);
    if (!local_0) {
        return 0;
    }
    if (_subaddiedialog_entrypoint_9(param_0, local_0, param_2, param_3) != 3) {
        func_80801464_chnicecavemen(param_0, 2, 0);
    }
    return 1;
}

int func_808013D0_chnicecavemen(param_0, param_1, param_2) s32 param_0[3]; s32 param_1; s32 param_2;
{
  if (_gcdialogcamera_entrypoint_0(param_1 | 0, param_2 | 0))
  {
    if (param_0[6] != 2)
    {
      func_80801464_chnicecavemen(param_0, 2, 1);
    }
    return 2;
  }
  return 1;
}

int func_80801428_chnicecavemen(param_0) Actor *param_0;
{
  if ((*(s32 *)((char *)(param_0) + 0x18)) != 0)
  {
    _capod_entrypoint_3(0, param_0);
    (*(s32 *)((char *)(param_0) + 0x18)) = 0;
  }
}

int func_80801464_chnicecavemen(param_0, param_1, param_2) Actor *param_0; s32 param_1; s32 param_2;
{
  s32 local_0 = *(s32 *)((char *)param_0 + 0x18);
  switch (local_0) {
    case 0:
        _capod_entrypoint_2(*(s32 *)((char *)param_0 + 0), 0x13, 0);
        /* fallthrough */
    case 1:
        _capod_entrypoint_8(1);
        *(s32 *)((char *)param_0 + 0x18) = 2;
        _gcdialogcamera_entrypoint_3(&D_808018D8_chnicecavemen, *(f32 *)((char *)param_0 + 0x38));
        _gcdialogcamera_entrypoint_4((u8 *)param_0 + 4);
        _gcdialogcamera_entrypoint_5((u8 *)param_0 + 0x44);
        _gcdialogcamera_entrypoint_8();
        /* fallthrough */
    case 2:
        _capod_entrypoint_7(param_1, param_2);
        return;
  }
}

int func_80801508_chnicecavemen(param_0, param_1, param_2) s32 param_0; s32 param_1; s32 param_2;
{
  switch ((*(s32 *)((char *)(param_0) + 0x18)))
  {
    case 0 :
      _capod_entrypoint_2((*(s32 *)((char *)(param_0) + 0x0)), 0x13, param_2, param_0);
      
    case 2 :
      (*(s32 *)((char *)(param_0) + 0x18)) = 1;
      
    case 1 :
      _capod_entrypoint_6((*(s32 *)((char *)(param_0) + 0x0)), param_1, param_2, param_0);
      return;
  }
}

int func_80801580_chnicecavemen(param_0) Actor *param_0;
{
    s32 local_0;

    local_0 = func_800F54E4();
    if (!func_800F64A4(local_0, 0x201)) {
        return 0;
    }
    if (!func_8010CB84(param_0->position, 300)) {
        return 0;
    }
    return func_800F640C(local_0, 0x3CA) > 0 || func_800F640C(local_0, 0x3CB) > 0;
}

void func_80801604_chnicecavemen(u8 *param_0) {
    u32 local_0;

    local_0 = (u32)((u16) (*(u16 *)((s8 *)(param_0) + (0x76)))) >> 7;
    switch (local_0) {                              
    case 0x32: ;
    case 0x33:
        _chfirefx_entrypoint_2(param_0, 0x3F99999A, 0x42480000, 0xF, 0xD);
        (*(s32 *)((s8 *)(param_0) + (0x28))) = (s32) (((u32)((u16) (*(u16 *)((s8 *)(param_0) + (0x76)))) >> 7) + 0x2F2);
        break;
    case 0x34:
        _chfirefx_entrypoint_2(param_0, 0x3FC00000, 0x42C80000, 0x14, 5);
        (*(s32 *)((s8 *)(param_0) + (0x28))) = 0x326;
        func_80102FDC(param_0, 0x3F800000);
        break;
    }
    if ((func_800DA298((*(s32 *)((s8 *)(param_0) + (0x28)))) != 0) || (_glcutDll_entrypoint_20() != 0)) {
        func_8010A570(param_0);
        func_80101FDC(param_0, 2);
    }
}

int func_808016E8_chnicecavemen(Actor *param_0, s32 param_1, CaveEvent60 param_2)
{
    if (param_1 == 0x40) {
        if (*(u16 *)(param_2.local_0 + 0x18) & 1) {
            func_8010114C(param_2.local_0, 0x92, 0);
        }
        if (param_2.local_0) {
        }
        func_8010A570(param_0);
        func_80101FDC(param_0, 2);
        func_800DA544(*(s32 *)((u8 *)param_0 + 0x28));
        func_800FC6B0(0xE);
        return 1;
    }
    return _chfirefx_entrypoint_5(param_0, param_1, param_2.local_0);
}
