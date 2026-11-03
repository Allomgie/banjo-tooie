#include "common.h"

typedef struct { u8 pad[0x48]; f32 f48; u8 pad4C[8]; f32 f54; f32 f58; u8 pad5C[8]; u8 pad64:7; u8 flag:1; } GargS;
extern f32 func_800DC178(f32, f32);
extern void func_80105010(GargS *);
extern int D_80800D7C_chlavagargoyle[];
typedef struct { s32 local_0[3]; } GargoyleLightColor;
extern GargoyleLightColor D_80800E44_chlavagargoyle;
extern f32 func_80103EAC(Actor *);
typedef union { s32 local_0; s16 local_1[2]; } GargoyleMessage37;
extern u8 D_80800E98_chlavagargoyle[];
extern u8 D_80800E50_chlavagargoyle[];
extern u8 _chlavagargoyle_entrypoint_1[];
extern u8 D_80800ED8_chlavagargoyle[];
extern int D_80800F20_chlavagargoyle[];
extern u8 D_80800D2C_chlavagargoyle[];
extern f32 func_80101F24(Actor *);
extern f32 func_800F1DF4(f32 *, f32 *);
extern f32 func_80013728(f32);
extern f32 func_800F0D50(f32, f32, f32);
extern f32 func_800136E4(f32);
extern f32 func_800F1FF0(f32, f32, f32, f32, f32);
extern f32 func_800F10B4(f32, f32, f32, f32, f32);
extern s32 func_80101E14(Actor *, f32);
extern s32 _subaddieaudioloop_entrypoint_0(Actor *, f32);
extern s32 func_800E0AFC(s32, s32, f32, f32, f32, f32);
typedef struct { u8 pad_0[0x64]; u32 pad_1 : 2; u32 local_0 : 1; u32 pad_2 : 29; u8 pad_3[0x10]; u32 pad_4 : 29; u32 local_1 : 1; u32 pad_5 : 2; } Mass63GargoyleFlags;
extern Actor *func_80108528(s32, f32[3], s32, Actor **);
extern f32 func_800EEAD4(f32[3], f32[3]);
extern void func_800EEB9C(f32[3], f32, f32);
extern void func_800EEBF0(f32[3], f32[3], f32);
extern void func_800BBCB8(f32[3], f32[3], f32, s32, void *);
extern int func_8010D12C(s32, f32[3], f32, s32);
extern u8 D_80800D3C_chlavagargoyle[];
extern f32 func_800D8FF8(void);
extern int func_800D91EC(f32 *, f32);
extern f32 func_80013970(f32);
extern int func_800EE7F8(f32 *, f32 *);
extern int func_800EF174(f32 *, f32 *, f32);
extern int func_800EFA4C(f32 *, f32, f32, f32);
extern int func_800BF340(f32 *, f32 *, f32 *, s32, f32);
extern u8 D_80800DD0_chlavagargoyle[];
extern u8 D_80800DC4_chlavagargoyle[];
extern u8 D_80800E08_chlavagargoyle[];
int func_80800B8C_chlavagargoyle();
s32 func_8080064C_chlavagargoyle();

void func_80800000_chlavagargoyle(GargS *param_0) {
    param_0->flag = 1;
    param_0->f58 = func_800DC178(5.0f, 8.0f);
    func_80105010(param_0);
    param_0->f54 = param_0->f48;
}

void func_80800054_chlavagargoyle(Actor *param_0)
{

    s32 local_3;
    f32 local_2;
    f32 local_1[3];
    func_8010C908(param_0, param_0->position);
    if (!((Mass63GargoyleFlags *)param_0)->local_1) {
        switch (param_0->unk70_10) {
        case 1:
            if (((Mass63GargoyleFlags *)param_0)->local_0) {
                if (func_8080064C_chlavagargoyle(param_0) && _subaddiejoy_entrypoint_6(param_0, 1)) {
                    func_80102424(param_0, 2);
                }
            } else if (func_800D90A4(&param_0->unk58) && func_8080064C_chlavagargoyle(param_0)) {
                func_80102424(param_0, 2);
            }
            break;
        case 2:
            local_2 = func_80101F24(param_0);
            if (func_80101DDC(param_0)) {
                if (((Mass63GargoyleFlags *)param_0)->local_0) {
                    param_0->unk58 = 4.0f;
                } else {
                    param_0->unk58 = func_800DC178(5.0f, 8.0f);
                }
                func_80102424(param_0, 1);
                _subaddieaudioloop_entrypoint_2(param_0);
            } else if (local_2 <= 0.35f) {
                _subaddieaudioloop_entrypoint_5(param_0, param_0->position, 1, 2500, D_80800D2C_chlavagargoyle);
                _subaddieaudioloop_entrypoint_0(param_0, func_800F10B4(local_2, 0.0f, 0.35f, 0.8f, 0.9f));
            } else if (local_2 >= 0.65f) {
                _subaddieaudioloop_entrypoint_5(param_0, param_0->position, 1, 2500, D_80800D2C_chlavagargoyle);
                _subaddieaudioloop_entrypoint_0(param_0, func_800F10B4(local_2, 0.65f, 1.0f, 0.9f, 0.8f));
            } else {
                _subaddieaudioloop_entrypoint_2(param_0);
            }
            if (func_80101E14(param_0, 0.18f) && func_8080064C_chlavagargoyle(param_0)) {
                func_80108B04(param_0, 0);
                func_800C4140(0xA63B5DD1, param_0->position, 0xFA000FA);
            }
            break;
        case 3:
            break;
        }
    }
    local_3 = func_8010262C(param_0->unk0, 2);
    if (local_3) {
        func_800F5A00(func_800F54E4(), local_1);
        param_0->unk54 = func_80013728(func_800F1DF4(param_0->position, local_1) - param_0->rotation[1]);
        param_0->unk54 = func_800136E4(func_800F0D50(param_0->unk54, func_80013728(-75.0f), func_80013728(75.0f)));
        param_0->unk50 = func_800F1FF0(param_0->unk50, param_0->unk54, 0.5f, 1.0f, 7.0f);
        func_800E0AFC(local_3, 0x12, -1.0f, 0.0f, param_0->unk50, 0.0f);
    }
}

s32 func_80800394_chlavagargoyle(Actor *param_0, s32 param_1, s32 param_2)
{
    Actor *local_0;
    f32 local_1[2];
    f32 local_2[3];
    f32 *local_6;
    f32 local_3[3];
    f32 local_4[3];
    f32 local_5;

    switch (param_1) {
    case 0x3D:
        local_0 = func_80108528(0x402, param_0->position, 0, &param_0);
        func_800F5A00(func_800F54E4(), local_2);
        local_6 = local_0->position;
        local_0->unk58 = func_800EEAD4(local_6, local_2) / 1100.0f;
        func_8010D12C(func_800F54E4(), local_2, local_0->unk58, 0);
        local_5 = func_800EEAD4(local_6, local_2);
        local_0->unk58 = local_5 / 1100.0f;
        ((f32 *)local_0->actorData)[7] = func_800F10B4(local_5, 300.0f, 3000.0f, 100.0f, 600.0f);
        func_800F18FC(local_6, local_2, local_1);
        func_800EEBF0(&((f32 *)local_0->actorData)[4], local_1, 1100.0f);
        return 1;
    case 0x40:
        func_800EEB9C(local_3, param_0->rotation[1] - 180.0f, 400.0f);
        func_800EF04C(local_3, param_0->position);
        _chskeletonexplode_entrypoint_6(param_0, local_3, 0x902, param_0->unk0->unk16);
        func_80107070(param_0, 2);
        func_80102424(param_0, 3);
        return 1;
    case 1:
        param_0->unk58 = 4.0f;
        func_80102424(param_0, 1);
        return 1;
    case 2:
        func_80102424(param_0, 1);
        return 1;
    case 0x97:
        local_5 = func_80103EAC(param_0);
        func_800EEB9C(local_4, param_0->rotation[1], local_5);
        local_4[1] += 2.0f * local_5;
        func_80101010(local_4);
        return 1;
    case 0xF:
        _chskeletonexplode_entrypoint_4(func_80106790(func_80101080()), 2);
        func_800BBCB8(param_0->position, (f32 *)param_0->actorData, 1.0f, 2, D_80800D3C_chlavagargoyle);
        func_800C4140(0x7FFB5C13, param_0->position, 0x04B000FA);
        func_800C4140(0x7FFB5C17, param_0->position, 0x04B000FA);
        return 1;
    default:
        return 0;
    }
}

s32 func_8080064C_chlavagargoyle(param_0) s32 param_0; {
    f32 temp_f0;

    temp_f0 = (f32) func_8010C710();
    if (func_8010CD88(param_0, 0x42340000, 0x42960000) == 0) {
        return 0;
    }
    if (temp_f0 >= 9000000.0f || temp_f0 < 90000.0f) {
        return 0;
    }
    return func_800F6478(func_800F54E4());
}

int chlavagargoyle_entrypoint_0()
{
    return &D_80800D7C_chlavagargoyle;
}

void func_8080099C_chlavagargoyle();

void func_808006EC_chlavagargoyle(Actor *param_0)
{
    s32 local_0;
    f32 local_1[3];
    f32 local_2[3];

    local_0 = func_8010C754();
    if (func_800D91EC(&((f32 *)param_0->actorData)[3], 3.0f)) {
        func_80800B8C_chlavagargoyle(param_0, (s32)param_0->position, (s32)param_0->position);
        return;
    }
    func_800EE7F8(local_1, param_0->position);
    if (((f32 *)param_0->actorData)[3] <= param_0->unk58) {
        func_800EF174((f32 *)param_0->actorData, &((f32 *)param_0->actorData)[4], func_800D8FF8());
        func_800EFA4C(param_0->position, ((f32 *)param_0->actorData)[0],
            ((f32 *)param_0->actorData)[1] + ((f32 *)param_0->actorData)[7] * func_80013970(func_800F10B4(((f32 *)param_0->actorData)[3], 0.0f, param_0->unk58, 0.0f, 180.0f)),
            ((f32 *)param_0->actorData)[2]);
    } else {
        ((f32 *)param_0->actorData)[5] += -2000.0f * func_800D8FF8();
        func_800EF174(param_0->position, &((f32 *)param_0->actorData)[4], func_800D8FF8());
    }
    func_8080099C_chlavagargoyle(param_0, param_0->position);
    _subaddieaudioloop_entrypoint_4(param_0, param_0->position, local_0 < 1000, D_80800DC4_chlavagargoyle);
    _subaddieaudioloop_entrypoint_0(param_0, func_800F10B4((f32)local_0, 1000.0f, 0.0f, 0.8f, 1.1f));
    if (func_8001210C(1)) {
        func_800BBCB8(param_0->position, NULL, param_0->scale, 1, D_80800DD0_chlavagargoyle);
        func_800BBCB8(param_0->position, NULL, param_0->scale, 1, D_80800E08_chlavagargoyle);
    }
    if (func_800BF340(local_1, param_0->position, local_2, 0x20020, func_80103EAC(param_0))) {
        func_800EFA4C(((f32 *)param_0->actorData), param_0->position[0], param_0->position[1] + 50.0f, param_0->position[2]);
        func_800C8CB8(param_0->unk14, ((f32 *)param_0->actorData));
        func_800EFB24(((f32 *)param_0->actorData), param_0->position, local_1);
        func_800EFDE8(((f32 *)param_0->actorData), ((f32 *)param_0->actorData), local_2);
        func_800EFB24(((f32 *)param_0->actorData), param_0->position, ((f32 *)param_0->actorData));
        func_80800B8C_chlavagargoyle(param_0, (s32)param_0->position, (s32)((f32 *)param_0->actorData));
    }
    param_0->rotation[1] += param_0->unk54 * func_800D8FF8();
    param_0->rotation[0] += param_0->unk50 * func_800D8FF8();
}

void func_8080099C_chlavagargoyle(Actor *param_0, f32 *param_1)
{
    s32 local_1;
    GargoyleLightColor local_0 = D_80800E44_chlavagargoyle;
    local_1 = func_800DC128(0, 10);
    func_800C8CB8(param_0->unk14, param_1);
    local_0.local_0[0] -= local_1;
    local_0.local_0[1] -= local_1;
    func_800C8E84(param_0->unk14, local_0.local_0);
}

s32 func_80800A2C_chlavagargoyle(Actor *param_0, s32 param_1, GargoyleMessage37 param_2)
{
    f32 local_0[2];
    f32 *local_1;

    switch (param_1) {
        case 0x3E:
            local_1 = (f32 *)param_0->actorData;
            func_800F5A00(func_800F54E4(), local_1);
            func_80800B8C_chlavagargoyle(param_0, param_0->position, local_1);
            return 1;
        case 0x40:
            func_80800B8C_chlavagargoyle(param_0, param_0->position, param_0->actorData);
            return 1;
        case 0x95:
            param_0->scale = 0.5f;
            param_0->unk54 = func_800DC178(180.0f, 360.0f);
            param_0->unk50 = func_800DC178(180.0f, 360.0f);
            local_1 = param_0->position;
            func_800EE7F8((f32 *)param_0->actorData, local_1);
            *(f32 *)&param_0->actorData[3] = 0.0f;
            local_0[0] = func_80103EAC(param_0) * 10.0f;
            local_0[1] = func_80103EAC(param_0) * 15.0f;
            param_0->unk14 = func_800C8A98();
            func_800C8F64(param_0->unk14, 3);
            func_800C8D4C(param_0->unk14, local_0);
            func_800C8FE0(param_0->unk14, 1);
            func_800C8CB8(param_0->unk14, local_1);
            return 1;
    }
    return 0;
}

int func_80800B8C_chlavagargoyle(param_0, param_1, param_2) Actor *param_0; s32 param_1; s32 param_2;
{
  s32 local_1;

  local_1 = func_800B53A4(6);
  func_800BA544(local_1, &_chlavagargoyle_entrypoint_1);
  func_800BABB8(local_1, param_1, param_1, *(s32 *)((char *)param_0 + 0x38), D_80800E50_chlavagargoyle);
  func_800BA22C(local_1, 6);
  func_800BBCB8(param_1, param_1, *(f32 *)((char *)param_0 + 0x38), 2, D_80800E98_chlavagargoyle);
  func_800C4140(0x7FFB5C13, (u8 *)((char *)param_0 + 4), 0x04B000FA);
  func_800C4140(0x7FFB5C17, (u8 *)((char *)param_0 + 4), 0x04B000FA);
  _subaddieaudioloop_entrypoint_2(param_0);
  _chlightfader_entrypoint_1(*(s32 *)((char *)param_0 + 0x14), 0x3FC00000, 5);
  func_800FFA88(*(s32 *)((char *)param_0 + 0));
}

void chlavagargoyle_entrypoint_1(s32 param_0, s32 param_1)
{
    func_800BBCB8(param_1, 0, 1.0f, 1, &D_80800ED8_chlavagargoyle);
}

int chlavagargoyle_entrypoint_2()
{
    return (int)&D_80800F20_chlavagargoyle;
}

/* TU-NOTE: the .data of this overlay (formerly asm/data/overlays/ch/lava/gargoyle.data.s) is defined here in C.
 * Its tables hold pointers to functions of this file; IDO's assembler schedules some of these
 * functions differently unless the tables are defined in the same unit. Values are taken from the ROM.
 * extern declarations adjusted to the object (same addresses): D_80800D7C_chlavagargoyle -> int[], D_80800F20_chlavagargoyle -> int[] */
extern void func_80105834();
extern void func_80101870();
extern void func_80108ED0();
extern void func_80107C2C();
u32 D_80800CF0_chlavagargoyle[10] = { 0x0, 0x0, 0x3F800000, 0x4340044, 0x3F800000, 0x434000A, 0x3F800000, 0x4340044, 0x3F800000, 0x4340044 };
u32 D_80800D18_chlavagargoyle[5] = { 0x20000, 0x30000, 0x30003, 0x40000, 0x10000 };
u8 D_80800D2C_chlavagargoyle[16] = { 0x0, 0x13, 0x3, 0xF1, 0x0, 0x16, 0x61, 0xA8, 0x0, 0xA, 0x1, 0x0, 0x0, 0x0, 0x0, 0x0 };
u8 D_80800D3C_chlavagargoyle[64] = { 0x0, 0x1D, 0x9, 0xDD, 0x0, 0x2B, 0x1, 0x0, 0x2, 0x80, 0x0, 0x16, 0x10, 0x0, 0x0, 0x22, 0x1, 0x80, 0x2, 0x0, 0x4, 0x80, 0x6, 0x0, 0x0, 0x15, 0x0, 0x0, 0x0, 0x26, 0x0, 0x19, 0x0, 0x0, 0x0, 0x7, 0x0, 0x2D, 0x0, 0x32, 0x0, 0x64, 0x0, 0x20, 0x87, 0x87, 0x87, 0xA0, 0x0, 0xA, 0xFF, 0x9C, 0x0, 0x19, 0xFF, 0x9C, 0x0, 0x64, 0x0, 0x4B, 0x0, 0x64, 0x0, 0x0 };
int D_80800D7C_chlavagargoyle[18] = { 0x10D0401, 0x9000001, (u32)&D_80800CF0_chlavagargoyle, (u32)func_80800054_chlavagargoyle, (u32)func_80105834, (u32)func_80101870, 0x1F400000, 0x0, 0x0, 0x800220, 0x0, (u32)func_80108ED0, 0x0, (u32)func_80800000_chlavagargoyle, (u32)func_80107C2C, -0x7FDDBBEF, (u32)func_80800394_chlavagargoyle, (u32)&D_80800D18_chlavagargoyle };
u8 D_80800DC4_chlavagargoyle[12] = { 0x0, 0x13, 0x4, 0x83, 0x0, 0xA, 0x1, 0x0, 0x0, 0x0, 0x0, 0x0 };
u8 D_80800DD0_chlavagargoyle[56] = { 0x0, 0x1D, 0x9, 0xCE, 0x0, 0x16, 0x12, 0x0, 0x0, 0x32, 0x0, 0x2, 0x0, 0x15, 0x0, 0x0, 0x0, 0x99, 0x0, 0x22, 0x1, 0x99, 0x2, 0x0, 0x1, 0x33, 0x1, 0x99, 0x0, 0x2B, 0x0, 0xA6, 0x0, 0xA6, 0x0, 0x1B, 0x1, 0x2C, 0x1, 0x2C, 0x0, 0x18, 0x0, 0x0, 0x0, 0x0, 0x19, 0x0, 0x19, 0x0, 0x0, 0x17, 0x0, 0x80, 0x0, 0x0 };
u8 D_80800E08_chlavagargoyle[60] = { 0x0, 0x1D, 0x9, 0xCA, 0x0, 0x16, 0x10, 0x0, 0x0, 0x32, 0x0, 0x2, 0x0, 0x15, 0x0, 0x19, 0x0, 0xF3, 0x0, 0x22, 0x0, 0x80, 0x1, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x2B, 0x1, 0x0, 0x1, 0x0, 0x0, 0x1B, 0x1, 0xF4, 0x1, 0xF4, 0x0, 0x18, 0x0, 0x0, 0x0, 0xB, 0xF, 0x0, 0xF, 0x0, 0x0, 0x1F, 0xA0, 0xA0, 0xA0, 0x0, 0x0, 0x0, 0x0, 0x0 };
GargoyleLightColor D_80800E44_chlavagargoyle = { 0xFF, 0x78, 0x32 };
u8 D_80800E50_chlavagargoyle[72] = { 0x0, 0x1D, 0x8, 0x90, 0x0, 0x7, 0x0, 0x2, 0x0, 0x4, 0x0, 0x80, 0x0, 0x16, 0x15, 0x86, 0x0, 0x2B, 0x2, 0x0, 0x2, 0x80, 0x0, 0x2D, 0x0, 0xFA, 0x1, 0xF4, 0x0, 0x1B, 0xFC, 0x18, 0xFC, 0xE0, 0x0, 0x23, 0x0, 0x73, 0x0, 0x27, 0xFE, 0x70, 0xFE, 0x70, 0x1, 0x90, 0x1, 0x90, 0x0, 0x15, 0x0, 0x0, 0x0, 0xCC, 0x0, 0xE, 0x0, 0x1, 0x0, 0xA, 0x0, 0x31, 0xFF, 0xF6, 0x0, 0x0, 0x0, 0x33, 0x0, 0x1, 0x0, 0x0 };
u8 D_80800E98_chlavagargoyle[64] = { 0x0, 0x1D, 0x9, 0xDD, 0x0, 0x2B, 0x2, 0x0, 0x2, 0x80, 0x0, 0x16, 0x10, 0x0, 0x0, 0x22, 0x0, 0x80, 0x1, 0x0, 0x4, 0x80, 0x6, 0x0, 0x0, 0x15, 0x0, 0x59, 0x0, 0x59, 0x0, 0x19, 0x0, 0x0, 0x0, 0x7, 0x0, 0x2C, 0xFF, 0x9C, 0x0, 0x64, 0xFF, 0x9C, 0x0, 0x64, 0x0, 0xC8, 0x0, 0x64, 0x0, 0x20, 0x91, 0x7D, 0x64, 0xAA, 0x0, 0xE, 0x0, 0x1, 0x0, 0xA, 0x0, 0x0 };
u8 D_80800ED8_chlavagargoyle[72] = { 0x0, 0x1D, 0x9, 0xCE, 0x0, 0x16, 0x12, 0x0, 0x0, 0x32, 0x0, 0x2, 0x0, 0x15, 0x0, 0x4C, 0x0, 0xE6, 0x0, 0x22, 0x0, 0x66, 0x0, 0x66, 0x0, 0x19, 0x0, 0x19, 0x0, 0x2B, 0x0, 0xC0, 0x0, 0xC0, 0x0, 0x1B, 0x1, 0x90, 0x1, 0x90, 0x0, 0x18, 0x0, 0x0, 0x0, 0x0, 0xF, 0x0, 0xF, 0x0, 0x0, 0x17, 0x0, 0x80, 0x0, 0x2C, 0x0, 0x0, 0x0, 0x64, 0x0, 0x0, 0x0, 0x0, 0x0, 0xC8, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0 };
int D_80800F20_chlavagargoyle[20] = { 0x10A0402, 0x8900001, 0x0, (u32)func_808006EC_chlavagargoyle, (u32)func_80105834, (u32)func_80101870, 0x0, 0x0, 0x0, 0x4, 0x0, (u32)func_80108ED0, 0x0, 0x0, (u32)func_80107C2C, 0x0, (u32)func_80800A2C_chlavagargoyle, 0x0, 0x0, 0x0 };
