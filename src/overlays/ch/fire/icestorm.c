#include "ch/fireicestorm.h"

extern int D_80800EA8_chfireicestorm;
extern char D_80800EF0_chfireicestorm;
extern void func_800EE7F8(f32 *, f32 *);
extern f32 func_800DC178(f32, f32);
typedef struct { u32 pad : 11; u32 flag : 1; u32 pad2 : 20; } IceStormBits;
extern void func_800EF368(f32 *, f32);
extern void func_800EFA4C(f32 *, f32, f32, f32);
typedef struct { s32 f0; u8 pad[0x60]; u32 pad64:11; u32 flag:1; u32 rest:20; } StormState;
extern void _subaddiedialog_entrypoint_11(s32, s32, s32, s32, s32);
extern s32 D_80800F38_chfireicestorm;
extern f32 func_800D8FF8(void);
extern void func_800EFA20(f32 *, f32 *, f32);
typedef struct { u8 pad0[0x1A]; u16 unk1A_5 : 11; u16 pad1A : 5; u8 pad1C[8]; u32 unk24_22 : 10; u32 pad24 : 22; } StormHit;
extern f32 D_80800F4C_chfireicestorm[];
extern u8 D_80800F54_chfireicestorm[];
extern Unk80132ED0 *func_80101080(void);
extern Actor *func_80106790(Unk80132ED0 *);
extern void _chexploder_entrypoint_9(Actor *, s32, s32);
extern void _subaddiefade_entrypoint_3(Actor *);
extern s32 func_800F6438(s32);
extern s32 func_800F6478(s32);
extern void func_800F7B9C(s32, s32);
extern s32 _capod_entrypoint_17(f32);
extern void func_8010D930(s32, s32, f32 *, void *);
extern void func_800FFAB0(Actor *);
typedef struct { u8 pad0[4]; f32 position[3]; u8 pad10[0x64 - 0x10]; u32 unk64_21 : 11; u32 unk64_20 : 1; u32 unk64_19 : 1; u32 unk64_0 : 19; u8 pad68[0x70 - 0x68]; s32 unk70; } IceStorm;
extern s32 D_80800F68_chfireicestorm;
extern s32 D_80800F7C_chfireicestorm;
extern void _chexploder_entrypoint_3(IceStorm *, f32 *, s32);
extern void func_800E1610(s32, f32, f32, f32 *);
extern void func_80018820(s32, f32, f32);
extern void func_80101FDC(IceStorm *, s32);
extern u8 D_80800F94_chfireicestorm[];
extern void func_800BBCB8(s32, s32, s32, s32, void *);
extern s32 D_80800FCC_chfireicestorm;
extern s32 D_80800FFC_chfireicestorm;
extern void func_80103140(Actor *, u16, u16);
typedef struct Mass45StormFlags { u32 local_0 : 11; u32 local_1 : 1; u32 local_2 : 20; } Mass45StormFlags;
extern Actor *func_80108528(s32, f32 *, s32, Actor **);
extern void func_80102FDC(Actor *, f32);
extern void func_800EFB24(f32 *, f32 *, f32 *);
extern u8 D_80800E94_chfireicestorm[];
extern u8 D_80800E80_chfireicestorm[];
void func_8080048C_chfireicestorm();
void func_80800558_chfireicestorm();
Actor *func_808007EC_chfireicestorm();
int func_80800940_chfireicestorm();
int func_80800980_chfireicestorm();
int func_808009C8_chfireicestorm();
void func_80800D0C_chfireicestorm();
void func_80800DC8_chfireicestorm();
void func_80800E08_chfireicestorm();
Actor *func_80800608_chfireicestorm();

int chfireicestorm_entrypoint_0(void)
{
    return (int)&D_80800EA8_chfireicestorm;
}

int chfireicestorm_entrypoint_1()
{
  return (int)&D_80800EF0_chfireicestorm;
}

void func_80800018_chfireicestorm(Actor *param_0)
{
    s32 pad[2];
    u32 local_3;
    f32 local_0[3];
    s32 local_1;
    s32 local_2;

    func_800DA524(0x9FB);
    if (param_0->unk74_7 != 0x32) {
        param_0->unk64_20 = 1;
    } else {
        param_0->unk64_20 = 0;
    }
    local_3 = param_0->unk64_20;
    local_1 = local_3 ? 0x1D5 : 0x1D6;
    local_2 = local_3 ? 0x43E : 0x43F;
    if (func_800A9C98()) {
        func_800DA524(local_1);
        func_800DA544(local_2);
    }
    if (func_800DA298(local_1)) {
        func_800FFAB0(param_0);
        return;
    }
    if (func_800A9C98()) {
        param_0->unk58 = 5.0f;
    } else {
        param_0->unk58 = 30.0f;
    }
    if (func_800DA298(local_2)) {
        func_80800558_chfireicestorm(param_0, 3);
    }
    param_0->unk64_19 = func_800DA298(0x49) != 0 || param_0->unk64_20 != 0;
    if (!param_0->unk64_19) {
        _subaddiemarker_entrypoint_1(param_0, 0x320, 0x32, local_0, 1);
        func_800EE7F8((f32 *)&param_0->actorData[0], local_0);
        _subaddiemarker_entrypoint_1(param_0, 0x320, 0x33, local_0, 1);
        func_800EE7F8((f32 *)&param_0->actorData[4], local_0);
    }
}

void func_808001CC_chfireicestorm(Actor *param_0)
{
    s32 local_0;
    s32 local_1;
    local_0 = func_800F54E4();
    if (func_800F6478(local_0) && !((s32)((u32)func_800F55FC(local_0) << 2) < 0)) {
        switch (param_0->unk70_10) {
            case 1:
                if (func_800D90A4(&param_0->unk58) && _subaddiedialog_entrypoint_16()) {
                    if (((IceStormBits *)((u8 *)param_0 + 0x64))->flag) { local_1 = 0x12D0; } else { local_1 = 0x12CF; }
                    if (func_80800980_chfireicestorm(param_0, local_1, 4)) {
                        func_80800940_chfireicestorm(param_0);
                        func_80800558_chfireicestorm(param_0, 2);
                    }
                }
                break;
            case 3:
                if (func_800D9078(&param_0->unk58)) {
                    func_80800940_chfireicestorm(param_0);
                    func_80800558_chfireicestorm(param_0, 4);
                }
                break;
            case 4:
                if (!func_800DA298(0x6CD) && !func_800A9C98()) {
                    if (func_800D9078(&param_0->unk58)) {
                        func_80800558_chfireicestorm(param_0, 3);
                        return;
                    }
                    if (func_800D9078((f32 *)((u8 *)param_0 + 0x24)) && !func_808009C8_chfireicestorm(param_0)) {
                        func_80108B04(param_0, 0);
                        *(f32 *)((u8 *)param_0 + 0x24) = func_800DC178(3.0f, 4.0f);
                    }
                }
                break;
        }
    }
}

void func_80800360_chfireicestorm(s32 arg0)
{
    func_800DA524(FLAG3_9FB_UNK);
}

s32 func_80800384_chfireicestorm(Actor *param_0, s32 param_1, s32 param_2)
{
    switch (param_1) {
    case 0x2E:
        switch (*(s16 *)&param_2) {
        case 0x12CF: func_800DA544(0x43F); break;
        case 0x12D0: func_800DA544(0x43E); break;
        }
        func_80800558_chfireicestorm(param_0, 4);
        return 1;
    case 0x3D:
        switch (param_2) {
        case 0:
            if (!func_800DA298(0x6CD)) {
                func_80800608_chfireicestorm(param_0);
            }
            break;
        case 1: func_808007EC_chfireicestorm(param_0); break;
        }
        break;
    case 0x95:
        func_8080048C_chfireicestorm(param_0);
        break;
    default:
        return 0;
    }
    return 1;
}

void func_8080048C_chfireicestorm(param_0) Actor *param_0;
{
    s32 local_0;
    s32 local_1;
    s32 local_2;
    void *local_3;
    void *local_4;

    local_0 = 0;
    local_1 = 0;
    local_2 = func_800EA090();
    if (param_0->unk64_20) {
        if (local_2 == 6) local_0 = 1;
        if (local_2 == 10) {
            local_0 = 1;
            local_1 = 1;
        }
    }
    if (local_1) {
        local_3 = func_800BEA88(0);
        local_4 = func_800BEA88(1);
        if (local_3) _idworldmake_entrypoint_1(local_3, 0x596, 1, 1);
        if (local_4) _idworldmake_entrypoint_1(local_4, 0x65E, 2, 1);
    }
    if (local_0) func_800FFAB0(param_0);
}

void func_80800558_chfireicestorm(param_0, param_1) Actor *param_0; s32 param_1;
{
    s32 local_0 = 0;

    func_80101FDC(param_0, param_1);
    switch (param_1) {
    case 3:
        if (func_800A9C98()) param_0->unk58 = 5.0f;
        else param_0->unk58 = 30.0f;
        break;
    case 4:
        local_0 = 1;
        param_0->unk58 = 15.0f;
        ((f32 *)param_0->actorData)[3] = func_800DC178(3.0f, 4.0f);
        break;
    }
    func_800DA3B8(0x9FB, local_0);
}

Actor *func_80800608_chfireicestorm(param_0) Actor *param_0;
{
    Actor *local_3;
    f32 local_0[3];
    f32 local_1[3];

    func_800F5BF0(func_800F54E4(), local_0);
    func_800EE7F8(local_1, local_0);
    local_1[0] += func_800DC178(-100.0f, 100.0f);
    local_1[1] += 2500.0f;
    local_1[2] += func_800DC178(-100.0f, 100.0f);
    local_3 = func_80108528(0x4FD, local_1, 0, &param_0);
    local_3->unk64_20 = ((Mass45StormFlags *)((u8 *)param_0 + 0x64))->local_1;
    func_80102FDC(local_3, func_800DC178(0.95f, 1.25f));
    func_800EFB24((f32 *)&local_3->actorData[4], local_0, local_1);
    func_800EF368((f32 *)&local_3->actorData[4], func_800DC178(2750.0f, 3250.0f));
    func_800EFA4C((f32 *)local_3->actorData, func_800DC178(50.0f, 100.0f), 0.0f, func_800DC178(5.0f, 10.0f));
    func_80103140(local_3,
        ((Mass45StormFlags *)((u8 *)param_0 + 0x64))->local_1 ? 0x814 : 0x815,
        *(u16 *)((u8 *)local_3->unk0 + 0x16));
    func_8010D930(4, *(u32 *)((u8 *)local_3 + 0x70) & 1, local_1,
        ((Mass45StormFlags *)((u8 *)local_3 + 0x64))->local_1 ?
        D_80800E94_chfireicestorm : D_80800E80_chfireicestorm);
    return param_0;
}

Actor *func_808007EC_chfireicestorm(param_0) Actor *param_0;
{
    Actor *local_2;
    f32 *local_3;
    f32 local_1[2];
    f32 local_0[3];

    func_800EE7F8(local_0, param_0->actorData);
    func_800EE7F8(local_1, &param_0->actorData[4]);
    local_2 = (Actor *)func_80108528(0x4FD, local_0, 0, &param_0);
    *(void **)((u8 *)local_2 + 0x3C) = param_0->unk0;
    local_2->unk64_20 = 0;
    local_2->unk64_19 = 1;
    func_80102FDC(local_2, 2.0f);
    func_8010A570(local_2);
    _subaddieDll_entrypoint_0(local_2);
    local_3 = (f32 *)&local_2->actorData[4];
    func_800EFB24(local_3, local_1, local_0);
    func_800EF368(local_3, 2000.0f);
    func_800EFA4C((f32 *)local_2->actorData, func_800DC178(50.0f, 100.0f), 0.0f, func_800DC178(5.0f, 10.0f));
    func_80103140(local_2, 0x815, *(u16 *)((u8 *)local_2->unk0 + 0x16));
    if (!local_2->unk64_19) func_8010D930(4, *(u32 *)((u8 *)local_2 + 0x70) & 1, local_0, ((s32 *) D_80800E80_chfireicestorm));
    _capod_entrypoint_13(local_2->unk0, 0, 0x27, 0x10);
    return param_0;
}

int func_80800940_chfireicestorm(param_0) s32 param_0;
{
  func_800C3FF0(0x605, 0x3F4CCCCD, 0x7FFF);
  func_800C3FF0(0x604, 0x3F800000, 0x7FFF);
}

int func_80800980_chfireicestorm(param_0, param_1, param_2) StormState *param_0; s32 param_1; s32 param_2; {
    s32 local_0;
    if (param_0->flag) {
        local_0 = 0x75;
    } else {
        local_0 = 0x76;
    }
    _subaddiedialog_entrypoint_11(param_0->f0, param_1, param_2, 0, local_0);
}

int func_808009C8_chfireicestorm(param_0) Actor *param_0;
{
    if (param_0->unk64_19) return 0;
    if (func_800DA298(0xA24)) {
        func_80101FDC(param_0, 5);
        func_80108B04(param_0, 1);
        param_0->unk64_19 = 1;
        return 1;
    }
    return 0;
}

void func_80800A40_chfireicestorm(void *param_0) {
    struct { char pad[0x58]; float unk58; } *tmp = param_0;
    tmp->unk58 = 8.0f;
}

void func_80800A50_chfireicestorm(Actor *param_0)
{
    s32 local_0;
    f32 local_1[3];
    f32 local_2[3];
    f32 local_3[3];
    f32 local_4[3];
    f32 local_5;

    if (param_0->unk70_10 == 1) {
        local_5 = func_800D8FF8();
        func_800EFA20(local_1, (f32 *)&param_0->actorData[4], local_5);
        func_800EE780(local_2, param_0->position, local_1);
        local_0 = func_800C6A7C(param_0->position, local_2, local_4, 0x20020);
        func_800EE7F8(param_0->position, local_2);
        if (param_0->unk64_19) _subaddieaudioloop_entrypoint_5(param_0, param_0->position, 1, 1500, &D_80800F38_chfireicestorm);
        if (local_0) {
            if (param_0->unk64_19) func_80101180(0x4A4, 0x40, 0);
            func_80800D0C_chfireicestorm(param_0);
        } else if (func_800D9078(&param_0->unk58)) {
            _subaddiefade_entrypoint_3(param_0);
        }
        func_800EFA20(local_3, (f32 *)param_0->actorData, local_5);
        func_800EF04C(param_0->rotation, local_3);
        if (param_0->unk64_20) func_80800E08_chfireicestorm(param_0);
        else func_80800DC8_chfireicestorm(param_0);
    }
}

s32 func_80800BA4_chfireicestorm(Actor *param_0, s32 param_1, StormHit *param_2)
{
    Actor *local_0;
    s32 local_1;
    s32 i;
    StormHit *local_3;
    StormHit **local_2;

    local_2 = &param_2;
    switch (param_1) {
    case 0x90:
        local_0 = func_80106790(func_80101080());
        _chexploder_entrypoint_9(local_0, 1, 2);
        _subaddiefade_entrypoint_3(local_0);
        return 1;
    case 0x3E:
        local_3 = param_2;
        func_80800D0C_chfireicestorm(param_0);
        if (local_3->unk24_22 == 0) {
            local_1 = local_3->unk1A_5;
            if (func_800F6438(local_1) && func_800F6478(local_1)) {
                func_800F7B9C(local_1, 0x51);
            }
        }
        break;
    case 0xE:
        for (i = 0; i < 2; i++) {
            if (_capod_entrypoint_17(D_80800F4C_chfireicestorm[i])) {
                func_8010D930(4, *(u32 *)((u8 *)param_0 + 0x70) & 1, param_0->position, D_80800F54_chfireicestorm);
                return 3;
            }
        }
        return 3;
    case 0xB:
        func_80800558_chfireicestorm(func_80106790(param_0->unk3C), 4);
        func_800FFAB0(param_0);
        return 3;
    default:
        return 0;
    }
    return 1;
}

void func_80800D0C_chfireicestorm(param_0) IceStorm *param_0;
{
    s32 local_0;

    local_0 = 20;
    if (!param_0->unk64_19) {
        local_0 = 28;
    }
    _chexploder_entrypoint_3(param_0, param_0->position, local_0);
    func_800E1610(2, 150.0f, 0.85f, param_0->position);
    func_80018820(0, 2.0f, 0.3f);
    func_8010D930(4, param_0->unk70 & 1, param_0->position, param_0->unk64_20 ? &D_80800F68_chfireicestorm : &D_80800F7C_chfireicestorm);
    func_80101FDC(param_0, 2);
}

void func_80800DC8_chfireicestorm(param_0) u8 *param_0;
{
  func_800BBCB8(param_0 + 4, 0, (*(s32 *)((char *)(param_0) + 0x38)), 1, &D_80800F94_chfireicestorm);
}

void func_80800E08_chfireicestorm(param_0) Actor *param_0;
{
    func_800BBCB8((s32)param_0 + 4, 0, *(s32 *)((char *)param_0 + 0x38), 1, &D_80800FCC_chfireicestorm);
    func_800BBCB8((s32)param_0 + 4, 0, *(s32 *)((char *)param_0 + 0x38), 2, &D_80800FFC_chfireicestorm);
}
