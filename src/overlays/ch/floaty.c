#include "common.h"

extern int D_80800E00_chfloaty;
extern void _chbaddiesetup_entrypoint_6(void *, void *, s32, s32, s32, s32, s32);
extern void _subaddietaxi_entrypoint_16(void);
extern s32 *_chfloaty_entrypoint_0(void);
extern Actor *func_80108528(s32, f32 *, s32, Actor **);
extern void func_801015D0(Actor *);
extern s32 D_80800EA8_chfloaty;
typedef struct { u8 pad[0x64]; u32 pad64:12; u32 flag:1; u32 rest:19; } FloatyS;
extern void func_800FCAE0(s32, s32, s32);
extern void func_800FCA90(s32);
extern int D_80800EF0_chfloaty;
extern s32 _plsu_entrypoint_3(Unk80132ED0 *);
extern void func_800F7BC8(s32, s32, Unk80132ED0 *);
extern s32 func_80101E14(Actor *, f32);
extern void func_80108B04(Actor *, s32);
extern void func_800C4140(s32, f32 *, s32);
extern s32 func_80101DDC(Actor *);
extern void func_800FFA88(Unk80132ED0 *);
extern s32 func_800D90A4(f32 *);
extern s32 func_800DA298(s32);
extern void func_800DA544(s32);
extern void _subaddiedialog_entrypoint_11(Unk80132ED0 *, s32, s32, f32 *, s32);
extern f32 func_800F10B4(f32, f32, f32, f32, f32);
extern f32 func_80013970(f32);
extern f32 mlAbsF(f32);
extern s32 func_8010262C(Unk80132ED0 *, s32);
extern void func_800E0B8C(s32, s32, f32, f32, f32, f32);
extern void func_8010C964(Actor *);
extern s32 func_800F54E4(void);
extern s32 func_800F64A4(s32, s32);
extern s32 _subaddiedialog_entrypoint_4(f32 *, s32, s32);
extern f32 func_8010CD28(Actor *);
extern void func_80102BAC(Actor *, f32, f32, f32);
extern void _subaddieDll_entrypoint_4(Actor *, s32);
extern void _subaddietaxi_entrypoint_5(Actor *, s32);
extern f32 func_800F12D4(f32, f32, f32, f32, f32);
extern void func_800EFE50(f32 *, f32 *, f32 *, f32);
extern s32 D_80800E84_chfloaty;
extern f32 func_800C6920(f32 *, f32, f32, s32);
extern void func_800F7C0C(s32, s32, f32);
extern void func_800EEB9C(f32 *, f32, f32);
void func_808006AC_chfloaty();
void func_80800CA0_chfloaty();

int *chfloaty_entrypoint_0()
{
    return &D_80800E00_chfloaty;
}

s32 func_8080000C_chfloaty(s32 param_0, s32 param_1, s32 param_2){
    return 1;
}

void func_80800020_chfloaty(s32 param_0[3], s32 param_1[3], s32 param_2, s32 param_3)
{
  _chbaddiesetup_entrypoint_6(&_subaddietaxi_entrypoint_16, param_0, param_1[0], param_1[1], param_1[2], param_2, param_3);
  if (param_0)
  {
  }
}

void func_8080007C_chfloaty(Actor *param_0, f32 param_1[3]) {
    s32 local_0;
    s32 local_1;

    func_80102FDC(param_0, 0x3F800000);
    local_0 = func_800CB3E0(param_1);
    switch (local_0) {
    case 1:
        if (func_800DA298(((u32)(*(u16 *)((char *)param_0 + 0x76)) >> 7) + 0x320) != 0) {
            local_1 = 4;
        }
        else {
            local_1 = 1;
        }
        func_808006AC_chfloaty(param_0, local_1);
        return;
    case 3:
    case 4:
    case 6:
        func_808006AC_chfloaty(param_0, 6);
        return;
    }
}

void func_80800BD8_chfloaty();

void func_80800118_chfloaty(Actor *param_0)
{
    s32 local_5;
    f32 local_0;
    f32 local_1;
    f32 local_2;
    s32 local_3;
    f32 local_4;

    switch (param_0->unk70_10) {
    case 1:
        if ((local_5 = _plsu_entrypoint_3(param_0->unk0)) != -1) {
            func_800F7BC8(local_5, 0x53, param_0->unk0);
        }
        break;
    case 2:
        if (func_80101E14(param_0, 0.47f)) {
            func_80108B04(param_0, 0);
            func_800C4140(0x7FFB5D61, param_0->position, 0x4B000FA);
        }
        if (func_80101DDC(param_0)) {
            func_800FFA88(param_0->unk0);
        }
        break;
    case 3:
        if (func_800D90A4(&param_0->unk50)) {
            if (!func_800DA298(0x340)) {
                func_800DA544(0x340);
                _subaddiedialog_entrypoint_11(param_0->unk0, 0x1431, 0xE, param_0->position, 0x6F);
            }
            func_808006AC_chfloaty(param_0, 4);
        } else {
            local_0 = func_800F10B4(param_0->unk50, 1.5f, 0.0f, 0.01f, 1.0f);
            local_1 = func_800F10B4(param_0->unk50, 1.5f, 0.75f, 0.0f, 1.0f);
            local_2 = func_800F10B4(param_0->unk50, 0.75f, 0.0f, 0.0f, 1.0f);
            local_0 = mlAbsF(func_80013970(local_0 * 720.0f) * 0.25f) + local_0;
            local_1 = mlAbsF(func_80013970(local_1 * 180.0f) * 2.0f) + local_1;
            local_2 = mlAbsF(func_80013970(local_2 * 180.0f) * 2.0f) + local_2;
            if ((local_3 = func_8010262C(param_0->unk0, 8))) {
                func_800E0B8C(local_3, 0x2A, -1.0f, local_1, local_1, local_1);
                func_800E0B8C(local_3, 0x2D, -1.0f, local_2, local_2, local_2);
                func_800E0B8C(local_3, 0x30, -1.0f, local_1, local_1, local_1);
                func_800E0B8C(local_3, 0x33, -1.0f, local_2, local_2, local_2);
                func_800E0B8C(local_3, 0x39, -1.0f, local_1, local_1, local_1);
                func_800E0B8C(local_3, 0x3C, -1.0f, local_2, local_2, local_2);
                func_800E0B8C(local_3, 0x3F, -1.0f, local_1, local_1, local_1);
                func_800E0B8C(local_3, 0x36, -1.0f, local_2, local_2, local_2);
            }
            param_0->scale = local_0;
        }
        func_80800BD8_chfloaty(param_0, 1);
        func_8010C964(param_0);
        break;
    case 4:
        if (func_800F64A4(func_800F54E4(), 10)) {
            if (!func_800DA298(0x6DD) && _subaddiedialog_entrypoint_4(param_0->position, 500, 0)) {
                func_800DA544(0x6DD);
                _subaddiedialog_entrypoint_11(param_0->unk0, 0x1432, 0xE, param_0->position, 0x6F);
            }
        } else {
            if (!func_800DA298(0x6DE) && _subaddiedialog_entrypoint_4(param_0->position, 500, 0)) {
                func_800DA544(0x6DE);
                _subaddiedialog_entrypoint_11(param_0->unk0, 0x1433, 0xE, param_0->position, 0x6F);
            }
        }
        param_0->unk54 = func_8010CD28(param_0);
        func_80102BAC(param_0, 0.1f, 0.5, 8.0f);
        func_8010C964(param_0);
        func_80800BD8_chfloaty(param_0, 1);
        break;
    case 6:
        if (func_800D90A4((f32 *)&param_0->actorData[3])) {
            _subaddieDll_entrypoint_4(param_0, 0);
            _subaddietaxi_entrypoint_5(param_0, param_0->unk74_7 - 0x25);
            func_808006AC_chfloaty(param_0, 4);
        } else if (7.0f <= *(f32 *)&param_0->actorData[3]) {
            local_4 = func_800F12D4(*(f32 *)&param_0->actorData[3], 8.0f, 7.0f, 0.0f, 1.0f);
            param_0->scale = local_4 / 2.0f + 0.5f;
            func_800EFE50(param_0->position, (f32 *)&param_0->actorData[4], (f32 *)param_0->actorData, local_4);
            param_0->position[1] += func_80013970(local_4 * 180.0f) * 100.0f;
        }
        if (*(f32 *)&param_0->actorData[3] < 1.0f) {
            ((u8 *)param_0)[0x9B] = (s32)func_800F12D4(*(f32 *)&param_0->actorData[3], 1.0f, 0.0f, 255.0f, 0.0f);
        }
        func_8010C964(param_0);
        func_80800BD8_chfloaty(param_0, 1);
        break;
    }
}

f32 func_80800B68_chfloaty();

void func_808006AC_chfloaty(param_0, param_1) Actor *param_0; int param_1;
{
    switch (param_1) {
    case 1:
        func_8010A63C(param_0);
        func_80103140(param_0, 0x923, *(u16 *)((u8 *)param_0->unk0 + 0x16));
        func_80102FDC(param_0, 0x3F800000);
        func_8010A63C(param_0);
        break;
    case 2:
        func_800DA544(param_0->unk74_7 + 0x320);
        func_8010A624(param_0);
        func_8010A570(param_0);
        func_800F77E8(func_800F54E4(), (u8 *)&D_80800E84_chfloaty + param_0->unk74_7 * 12 - 600);
        break;
    case 3:
        func_80104580(param_0);
        param_0->unk50 = 1.5f;
        func_80103140(param_0, 0x924, *(u16 *)((u8 *)param_0->unk0 + 0x16));
        param_0->rotation[1] = func_8010CD28(param_0);
        func_80800BD8_chfloaty(param_0, 10);
        param_0->position[1] = func_800C6920(param_0->position, 1000.0f, -1000.0f, 0) + 100.0f;
        break;
    case 4:
        func_80104580(param_0);
        func_8010A624(param_0);
        func_80103140(param_0, 0x924, *(u16 *)((u8 *)param_0->unk0 + 0x16));
        func_80102FDC(param_0, 0x3F800000);
        param_0->position[1] = func_800C6920(param_0->position, 1000.0f, -1000.0f, 0) + 100.0f;
        break;
    case 5:
        func_800F7C0C(func_800F54E4(), 0x6E, func_80800B68_chfloaty((u8 *)param_0));
        break;
    case 6:
        func_800CB698(param_0->unk74_7 - 0x25, 5);
        func_800EEB9C((f32 *)&param_0->actorData[0], param_0->rotation[1], 300.0f);
        func_800EF04C((f32 *)&param_0->actorData[0], param_0->position);
        *(f32 *)&param_0->actorData[1] = func_800C6920((f32 *)&param_0->actorData[0], 1000.0f, -1000.0f, 0) + 100.0f;
        func_800EE7F8((f32 *)&param_0->actorData[4], param_0->position);
        *(f32 *)&param_0->actorData[3] = 8.0f;
        _subaddieDll_entrypoint_4(param_0, 1);
        break;
    }
    func_80102424(param_0, param_1);
}

s32 func_8080090C_chfloaty(Actor *param_0, s32 param_1, s32 param_2)
{
    Actor *local_0;
    switch (param_1) {
    case 0x18:
        if (param_0->unk70_10 != 2) func_808006AC_chfloaty(param_0, 2);
        return 1;
    case 0x44:
        func_8080007C_chfloaty(param_0, param_2);
        return 1;
    case 0x3E:
        if (func_800DA298(param_0->unk74_7 + 0x320) && _subaddietaxi_entrypoint_2(param_0, param_0->unk74_7 - 0x25)) func_808006AC_chfloaty(param_0, 5);
        return 1;
    case 0x1F:
        func_801015D0(param_0);
        switch (param_0->unk70_10) {
        case 1: func_800DF744(3, 1); break;
        case 2: func_800DF744(3, 2); break;
        }
        return 1;
    case 0x3D:
        local_0 = func_80108528(0x486, param_0->position, (s32)param_0->rotation[1], &param_0);
        func_808006AC_chfloaty(local_0, 3);
        local_0->unk74_7 = param_0->unk74_7;
        return 1;
    case 0x95:
        if (_subaddietaxi_entrypoint_13(param_0, param_0->unk74_7 - 0x25, _chfloaty_entrypoint_0, 1)) {
            func_80102FDC(param_0, 0x3F800000);
            if (!func_800DA298(param_0->unk74_7 + 0x320)) func_808006AC_chfloaty(param_0, 1);
            else func_808006AC_chfloaty(param_0, 4);
        } else if (param_0->unk7A_5) {
            func_800FFA88(param_0->unk0);
            return 1;
        }
        if (*(u16 *)((u8 *)param_0->unk0 + 0x14) == 0x924) {
            func_8010A3E8(param_0, 0x3F000000);
            *(s16 *)((u8 *)param_0->unk0 + 0x20) = -80;
        }
        return 1;
    default: return 0;
    }
}

f32 func_80800B68_chfloaty(u8 *param_0) {
    s32 local_0;

    local_0 = ((u32)((u16) (*(u16 *)((s8 *)(param_0) + (0x76)))) >> 7) - 0x32;
    switch (local_0) {                              
    case 0:
        return 15.0f;
    case 1:
        return 15.0f;
    case 2:
        return 15.0f;
    default:
        return 1000.0f;
    }
}

void func_80800BD8_chfloaty(s32 param_0, s32 param_1) {
    s32 local_0;
    s32 local_1;
    s32 local_2;

    if (func_8001210C(1) != 0) {
        local_2 = func_800B5BE4(0x1C);
        local_1 = param_0 + 4;
        local_0 = local_2;
        func_800BABB8(local_2, local_1, local_1, 0x3F800000, &D_80800EA8_chfloaty);
        func_800BA22C(local_0, param_1);
    }
    func_80800CA0_chfloaty(param_0);
}

void func_80800C4C_chfloaty(FloatyS *param_0) {
    if (param_0->flag) {
        func_800FCAE0(0x1C, 0, 0x7D0);
        func_800FCA90(0x1C);
        param_0->flag = 0;
    }
}

void func_80800CA0_chfloaty(param_0) Actor *param_0;
{
    f32 local_0;
    local_0 = func_8010C710(param_0);
    if (local_0 > 250000.0f) {
        if (param_0->unk64_19) {
            func_800FCAE0(0x1C, 0, 2000);
            func_800FCA90(0x1C);
            param_0->unk64_19 = 0;
        }
    } else {
        if (param_0->unk64_19) {
            func_800FCAE0(0x1C, (s32)func_800F10B4(local_0, 0.0f, 250000.0f, 22000.0f, 0), 2000);
        } else if (!param_0->unk64_19) {
            func_800FC618(0x1C, (s32)func_800F10B4(local_0, 0.0f, 250000.0f, 22000.0f, 0.0f));
            param_0->unk64_19 = 1;
        }
    }
}

int chfloaty_entrypoint_1()
{
    return (int)&D_80800EF0_chfloaty;
}
