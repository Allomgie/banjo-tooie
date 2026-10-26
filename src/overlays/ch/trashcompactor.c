#include "common.h"

extern int D_80800918_chtrashcompactor;
extern int D_80800960_chtrashcompactor;
extern int D_808009A8_chtrashcompactor;
extern void func_800EE7F8(f32 *, f32 *);
extern void func_800C87DC(f32 *);
extern void func_80101180(s32, s32, s32);
extern Actor *func_801084B0(s32, Actor **);
extern s32 _capod_entrypoint_14(void);
extern s32 _chdoormake_entrypoint_3(Actor *, f32, f32, f32, s32, s32);
extern u8 D_808009F0_chtrashcompactor[];
extern u8 D_808009FC_chtrashcompactor[];
extern u8 D_80800A0C_chtrashcompactor[];
extern f32 _subaddieaudioloop_entrypoint_8(Actor *, void *, s32, f32);
extern void _subaddieaudioquick_entrypoint_2(Actor *, f32 *, void *);
extern void _capod_entrypoint_13(Unk80132ED0 *, s32, s32, s32);
extern void _subaddiedialog_entrypoint_11(Unk80132ED0 *, s32, s32, f32 *, s32);
extern s32 func_800D9078(f32 *);
extern f32 func_800F12D4(f32, f32, f32, f32, f32);
extern f32 func_800F10B4(f32, f32, f32, f32, f32);
extern void func_800EFE50(f32 *, f32 *, f32 *, f32);
extern void func_800E15CC(s32, f32, f32);
extern void func_800187B4(s32, f32, f32, f32);
extern Actor *func_80106790(Unk80132ED0 *);
extern void func_800EF04C(f32 *, f32 *);
extern void func_80104004(Actor *, f32 *, f32 *);

int chtrashcompactor_entrypoint_0(void)
{
    extern int D_808008D0_chtrashcompactor;
    return (int)&D_808008D0_chtrashcompactor;
}

int chtrashcompactor_entrypoint_1()
{
  return (int)&D_80800918_chtrashcompactor;
}

int *chtrashcompactor_entrypoint_2()
{
    return &D_80800960_chtrashcompactor;
}

int *chtrashcompactor_entrypoint_3()
{
    return &D_808009A8_chtrashcompactor;
}

void func_80800030_chtrashcompactor(u8 *param_0) {
    f32 local_0[3];

    func_800EE7F8(param_0 + 0x18, param_0 + 4);
    func_800EE7F8(param_0 + 0x28, param_0 + 4);
    (*(f32 *)((s8 *)(param_0) + (0x2C))) = 0.0f;
    if (((u32)((u16) (*(u16 *)((s8 *)(param_0) + (0x76)))) >> 7) == 0x32) {
        (*(s32 *)((s8 *)(param_0) + (0x50))) = 0x08000000;
    } else {
        (*(s32 *)((s8 *)(param_0) + (0x50))) = 0x10000000;
    }
    (*(f32 *)((s8 *)(param_0) + (0x34))) = 800.0f;
    func_800C87DC(local_0);
    _subaddiefade_entrypoint_11(param_0, local_0);
}

void func_808000BC_chtrashcompactor(Actor *param_0)
{
    s32 local_0;
    s32 local_1;
    s32 local_2;
    f32 local_3[3];

    local_0 = func_800F54E4();
    local_1 = func_800F64A4(local_0, 0x10000);
    local_2 = 0;
    if (!local_1 && !func_800DA298(0x1A0)) {
        if (func_800F6438(local_0) && func_800F6478(local_0) && param_0->unk74_7 == 0x33) {
            func_800F5A00(local_0, local_3);
            if (local_3[0] > -2500.0f && local_3[2] > -800.0f) {
                param_0->unk64_19 = 1;
                _capod_entrypoint_13(param_0->unk0, 0, 8, 0x10);
                func_80101180(0x3A7, 10, 1);
                _chmrtannoy_entrypoint_0();
                _subaddiedialog_entrypoint_11(param_0->unk0, 0x1334, 0x44, param_0->position, 0xA3);
                func_800DA544(0x1A0);
                func_80101FDC(param_0, 2);
                param_0->unk58 = 8.0f;
            }
        }
        local_1 = 1;
    }

    param_0->unk54 = _subaddieaudioloop_entrypoint_8(param_0, D_808009F0_chtrashcompactor, param_0->unk70_10 != 1, param_0->unk54);
    switch (param_0->unk70_10) {
    case 1:
        local_2 = 1;
        if (!local_1 && func_80090248() && (func_8008FDC4() & *(s32 *)&param_0->unk50) && func_80090150()) {
            func_80090708(2);
            param_0->unk64_19 = 1;
            _capod_entrypoint_13(param_0->unk0, 0, param_0->unk74_7 == 0x32 ? 2 : 4, 0x20);
            func_80101FDC(param_0, 3);
            param_0->unk58 = 0.45f;
        }
        break;
    case 2:
        if (func_800D9078(&param_0->unk58)) {
            param_0->unk64_20 = 1;
            func_80101FDC(param_0, 3);
            param_0->unk58 = 0.45f;
        }
        break;
    case 3:
    {
        s32 local_4;
        f32 local_5;
        local_4 = func_800D9078(&param_0->unk58);
        local_5 = func_800F12D4(param_0->unk58, 0.0f, 0.45f, 1.0f, 0.0f);
        func_800EFE50(param_0->position, (f32 *)&param_0->actorData[0], (f32 *)&param_0->actorData[4], local_5);
        if (local_4) {
            _subaddieaudioquick_entrypoint_2(param_0, param_0->position, D_808009FC_chtrashcompactor);
            _subaddieaudioquick_entrypoint_2(param_0, param_0->position, D_80800A0C_chtrashcompactor);
            func_800E15CC(2, 80.0f, 0.85f);
            func_800187B4(0, 2.0f, 1.0f, 1.0f);
            func_80101FDC(param_0, 4);
            if (!param_0->unk64_20) {
                func_800904C8(0x9A);
            }
            param_0->unk58 = 0.85f;
        }
        break;
    }
    case 4:
    {
        s32 local_6;
        f32 local_7;
        local_6 = func_800D9078(&param_0->unk58);
        local_7 = func_800F10B4(param_0->unk58, 0.0f, 0.85f, 400.0f, 800.0f);
        *(f32 *)&param_0->actorData[7] = local_7;
        if (local_6) {
            func_80101FDC(param_0, 5);
            param_0->unk58 = 0.8f;
        }
        break;
    }
    case 5:
        if (func_800D9078(&param_0->unk58)) {
            func_80101FDC(param_0, 6);
            param_0->unk58 = 0.15f;
        }
        break;
    case 6:
    {
        s32 local_8;
        local_8 = func_800D9078(&param_0->unk58);
        *(f32 *)&param_0->actorData[7] = func_800F10B4(param_0->unk58, 0.0f, 0.15f, 800.0f, 400.0f);
        if (local_8) {
            if (!param_0->unk64_20) {
                func_80090708(0);
                func_800904C8(0x5A);
                func_80090658(1);
            }
            func_80101FDC(param_0, 7);
            param_0->unk58 = 1.0f;
        }
        break;
    }
    case 7:
    {
        s32 local_9;
        f32 local_10;
        local_9 = func_800D9078(&param_0->unk58);
        local_10 = func_800F12D4(param_0->unk58, 0.0f, 0.45f, 0.0f, 1.0f);
        func_800EFE50(param_0->position, (f32 *)&param_0->actorData[0], (f32 *)&param_0->actorData[4], local_10);
        if (local_9) {
            if (!param_0->unk64_20) {
                func_80090658(0);
                if (param_0->unk64_19) {
                    _capod_entrypoint_14();
                    param_0->unk64_19 = 0;
                }
            }
            param_0->unk64_20 = 0;
            func_80101FDC(param_0, 8);
            param_0->unk58 = 3.5f;
        }
        break;
    }
    case 8:
        local_2 = 1;
        if (func_800D9078(&param_0->unk58)) {
            func_80101FDC(param_0, 1);
        }
        break;
    }

    if (param_0->unk3C) {
        Actor *local_11;
        local_11 = func_80106790(param_0->unk3C);
        func_800EE7F8(local_11->position, param_0->position);
        local_11->position[1] += *(f32 *)&param_0->actorData[7];
    }
    if (local_2) {
        f32 local_12[3];
        f32 local_13[3];
        func_80104004(param_0, local_12, local_13);
        func_800EF04C(local_12, param_0->position);
        func_800EF04C(local_13, param_0->position);
        _sudeflect_entrypoint_2(local_12, local_13, 10);
    }
}

s32 func_80800684_chtrashcompactor(Actor *param_0, s32 param_1, s32 param_2)
{
    Actor *local_0;
    switch (param_1) {
    case 0x3D:
        local_0 = func_801084B0(0x3B5, &param_0);
        if (local_0) {
            func_80108944(local_0, param_0);
            local_0->position[1] += *(f32 *)((u8 *)param_0 + 0x34);
            param_0->unk3C = local_0->unk0;
        }
        break;
    case 0x95:
        param_0->unk3C = 0;
        func_80108B04(param_0, 0);
        if (!func_800DA298(0x1A0)) func_80101180(0x3A7, 10, 0);
        break;
    case 0xB:
        if (param_2 == 8) param_0->unk64_19 = 0;
        return 3;
    case 0x9F:
        if (param_0->unk64_19) {
            _capod_entrypoint_14();
            param_0->unk64_19 = 0;
        }
        break;
    default: return 0;
    }
    return 1;
}

s32 func_808007A4_chtrashcompactor(s32 param_0){
    _chswitch_entrypoint_7(param_0, 0x9F5);
    _chswitch_entrypoint_8(param_0, 0x200);
    _chswitch_entrypoint_9(param_0);
}

s32 func_808007DC_chtrashcompactor(void *this, s32 next_state){
    if(next_state == 7){
        func_80101180(0x3B7, 7, 0);
    }
    else{
        _chswitch_entrypoint_10(this, next_state);
    }
}

void func_8080081C_chtrashcompactor(Actor *param_0)
{
    f32 local_0[3];
    if (_chdoormake_entrypoint_3(param_0, 0.0f, 90.0f, 200.0f, 1, 0x9F5)) {
        _chdoormake_entrypoint_9(param_0, 0, 0, 0x10);
        _chdoormake_entrypoint_8(param_0, 0xC);
    }
    func_800C87DC(local_0);
    _subaddiefade_entrypoint_11(param_0, local_0);
}
