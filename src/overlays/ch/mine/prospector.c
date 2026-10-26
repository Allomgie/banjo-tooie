#include "common.h"
extern void _subaddieaudioquick_entrypoint_3(Actor *, f32[3], void *, f32);

extern int D_8080102C_chmineprospector[];
extern int D_80801074_chmineprospector[];
extern int D_808010BC_chmineprospector[];
typedef struct { u8 pad[8]; f32 f8; u8 padC[0x1C]; u8 f28[4]; f32 f2C; u8 pad30[0x4C]; u32 pad7C:19; u32 flag:1; u32 rest:12; } MineS;
extern void func_80101870(MineS *);
extern s32 func_80104130(void);
extern void func_800DBEFC();
extern s32 D_8080110C_chmineprospector[];
extern s8 D_8080111A_chmineprospector;
extern s32 D_8080111C_chmineprospector[];
extern s32 D_80800FB0_chmineprospector[];
extern u8 D_80800F20_chmineprospector[];
extern u8 D_80800F90_chmineprospector[];
typedef union { s32 local_0; s16 local_1[2]; } ProspectorMessage37;
extern s32 D_80800F58_chmineprospector[];
extern s32 _subaddiedialog_entrypoint_9(s32, s32, s32 *, s32);
extern s32 _subaddiedialog_entrypoint_10(s32);
extern void func_80108B04(s32, s32);
extern void *func_80100094(Actor *, s32);
extern Actor *func_8010856C(s32, f32 *, f32 *);
extern void func_80105A9C(Actor *, f32);
extern s32 D_80800FBC_chmineprospector[];
extern void _capod_entrypoint_2(Unk80132ED0 *, s32, s32);
extern void _capod_entrypoint_8(s32);
extern void _capod_entrypoint_7(s32, s32);
extern void _gcdialogcamera_entrypoint_3(void *, f32);
extern void _gcdialogcamera_entrypoint_4(f32[3]);
extern void _gcdialogcamera_entrypoint_5(f32[3]);
extern void _gcdialogcamera_entrypoint_8(void);
extern void _capod_entrypoint_6(Unk80132ED0 *, s32, s32);
extern int func_8008FB10(f32 *, f32, f32, f32);
extern s32 func_80105998(Actor *, f32);
typedef struct { u32 pad_0:21; s32 local_0:10; u32 pad_1:1; } ProspectorModelReference;
extern void *func_80105494(Actor *);
extern void *func_800D7520(s32);
extern void func_800C7A68(void *, f32, f32 *);
typedef union { s32 word; Unk80132ED0 *marker; } ProspectorEventPayload;
extern void _suexpression_entrypoint_12(void *, f32, f32);
extern s32 D_80801184_chmineprospector[];
extern s32 D_808011AC_chmineprospector[];
extern s32 D_80801194_chmineprospector[];
extern s32 D_808011A0_chmineprospector[];
extern void _subaddieaudioquick_entrypoint_4(Actor *, f32[3], void *, void *);
extern s32 D_80801104_chmineprospector[];
extern s32 func_80102320(Actor *, f32, f32);
extern void _chbadshad_entrypoint_1(Actor *, f32 *, f32);
extern s32 func_800DC298(f32);
extern s32 D_80801128_chmineprospector[];
extern s32 D_80801144_chmineprospector[];
extern s32 D_80801134_chmineprospector[];
extern s32 D_80801168_chmineprospector[];
extern s32 D_80801178_chmineprospector[];
extern void _subaddieaudioquick_entrypoint_2();
void func_80800970_chmineprospector();
void func_808009B0_chmineprospector();
void func_80800A64_chmineprospector();
void func_80800D8C_chmineprospector();
int func_80800398_chmineprospector();
void func_808005F0_chmineprospector();
void func_8080068C_chmineprospector();
void func_80800D34_chmineprospector();
extern void func_80105834(), func_80107C2C(), func_8080029C_chmineprospector(), func_80800340_chmineprospector();
extern u8 D_80800FCC_chmineprospector[];

int chmineprospector_entrypoint_0()
{
    return (int)&D_8080102C_chmineprospector;
}

int chmineprospector_entrypoint_1()
{
    return (int)&D_80801074_chmineprospector;
}

int chmineprospector_entrypoint_2()
{
  return &D_808010BC_chmineprospector;
}

void func_80800638_chmineprospector();

s32 func_80800540_chmineprospector();

void func_80800024_chmineprospector(Actor *param_0)
{
    extern void _subaddieaudioquick_entrypoint_3(Actor *, f32 *, void *, f32);
    f32 local_0[3];

    _suexpression_entrypoint_10(func_80100094(param_0, 1), param_0->unk0, 0);
    func_800EE7F8(local_0, (f32 *)((u8 *)param_0 + 0x28));
    local_0[1] = param_0->position[1];
    func_8008FB10(local_0, 200.0f, -20.0f, (s32)param_0->unk70_10 < 5 ? 120.0f : 80.0f);
    if (param_0->unk7C_12) {
        _chbadshad_entrypoint_1(param_0, local_0, param_0->scale);
    }
    switch (param_0->unk70_10) {
    case 1:
        _suexpression_entrypoint_18(func_80100094(param_0, 1), 1);
        func_808005F0_chmineprospector(param_0);
        if (func_800DA298(0x5C)) {
            func_80800540_chmineprospector(param_0, (s32)&D_80800F58_chmineprospector, 7, 2);
        } else {
            func_80800540_chmineprospector(param_0, (s32)((s32 *) D_80800F20_chmineprospector), 7, 2);
        }
        break;
    case 2:
        if (func_80101DDC(param_0)) {
            func_80102424(param_0, 3);
        }
        break;
    case 3:
        if (!func_80102320(param_0, 0.38f, 0.8f)) {
            _suexpression_entrypoint_18(func_80100094(param_0, 1), 1);
        }
        func_80800638_chmineprospector((s32)param_0);
        break;
    case 4:
        if (func_80101DDC(param_0)) {
            func_80102424(param_0, 1);
        }
        break;
    case 5:
        if (func_80101DDC(param_0)) {
            func_808009B0_chmineprospector(param_0, 3, 1);
            _subaddiedialog_entrypoint_11(param_0->unk0, 0xF90, 0xE, (f32 *)((u8 *)param_0 + 0x28), 0x3F);
            func_80102424(param_0, 7);
        }
        _subaddieaudioquick_entrypoint_3(param_0, param_0->position, &D_80801104_chmineprospector, 0.8f);
        break;
    case 6:
        func_8080068C_chmineprospector(param_0);
        func_80800540_chmineprospector(param_0, (s32)((s32 *) D_80800F90_chmineprospector), 4, 7);
        break;
    case 7:
        func_8080068C_chmineprospector(param_0);
        break;
    case 8:
        func_8080068C_chmineprospector(param_0);
        break;
    }
}

void func_8080029C_chmineprospector(param_0) s32 param_0; {
    f32 sp28[6];
    f32 *sp24;

    sp24 = func_80100094(param_0, 0);
    func_800EE7F8(param_0 + 0x28, param_0 + 4);
    if (_subaddiemarker_entrypoint_0(param_0, 0x152, sp28, 1) != 0) {
        func_800EE7F8(sp24, sp28);
        sp24[3] = sp28[4];
    }
    if (_glcutDll_entrypoint_20() != 0) {
        func_80102424(param_0, 8);
        return;
    }
    if (func_800DA298(0x83) != 0) {
        func_80102424(param_0, 6);
    }
}

void func_80800340_chmineprospector(param_0) MineS *param_0; {
    func_80101870(param_0);
    if (param_0->flag) {
        func_800DBEFC(func_80104130(), 4, param_0->f28);
        param_0->f2C = param_0->f8;
    }
}

s32 func_80800910_chmineprospector();

void func_808008A4_chmineprospector();

void func_8080084C_chmineprospector();

void func_808006EC_chmineprospector();

int func_80800398_chmineprospector(param_0, param_1, param_2) Actor *param_0; s32 param_1; s32 param_2;
{
    u8 *local_0;
    switch (param_1) {
        case 0xB:
            if (param_2 == 8) { func_80800970_chmineprospector(param_0); return 4; }
            return 3;
        case 0x2E:
            func_808006EC_chmineprospector(param_0, ((s16 *)&param_2)[0], ((s16 *)&param_2)[1]);
            break;
        case 0x2F:
            func_8080084C_chmineprospector(param_0, ((s16 *)&param_2)[0], ((s16 *)&param_2)[1]);
            break;
        case 0x31:
            func_800DA544(0x83);
            func_80102424(param_0, 5);
            break;
        case 0x3D: func_808008A4_chmineprospector(param_0); break;
        case 0x52:
            _gcdialogcamera_entrypoint_3(&D_80800FBC_chmineprospector, param_0->scale);
            _gcdialogcamera_entrypoint_4(param_0->actorData + 4);
            break;
        case 0x57:
            return func_80800910_chmineprospector(param_0, param_2 & 0xFFFF, (param_2 & 0xFFFF0000) >> 16);
        case 0x95:
            local_0 = func_80100094(param_0, 0);
            _suexpression_entrypoint_7(param_0, 1, 0x3F);
            _suexpression_entrypoint_12(func_80100094(param_0, 1), 60.0f, 20.0f);
            *(s32 *)(local_0 + 0x10) = 0;
            break;
        default: return 0;
    }
    return 1;
}

s32 func_80800540_chmineprospector(Actor *param_0, s32 param_1, s32 param_2, s32 param_3)
{
    s32 local_0;

    D_8080111A_chmineprospector = param_3;
    local_0 = _subaddiedialog_entrypoint_8(param_0, &param_0->actorData[4],
        &D_8080110C_chmineprospector, param_1, param_2);
    if (!local_0) return 0;
    switch (_subaddiedialog_entrypoint_9(param_0, local_0, param_1, param_2)) {
    case 1:
        func_808009B0_chmineprospector(param_0, 3, 0);
        break;
    case 2:
        func_808009B0_chmineprospector(param_0, 3, 1);
        break;
    }
    return 1;
}

void func_808005F0_chmineprospector(param_0) u8 *param_0; {
    if (func_800DC298(0.2f)) {
        _subaddieaudioquick_entrypoint_3(param_0, param_0 + 0x28, &D_80800FB0_chmineprospector, 0.8f);
    }
}

void func_80800638_chmineprospector(s32 param_0)
{
    _subaddieaudioquick_entrypoint_3(param_0, param_0 + 0x28, &D_8080111C_chmineprospector, 0.03f);
    _subaddieaudioquick_entrypoint_3(param_0, param_0 + 0x28, &D_80800FB0_chmineprospector, 0.65f);
}

void func_8080068C_chmineprospector(param_0) u8 *param_0; {
    _subaddieaudioquick_entrypoint_4(param_0, param_0 + 0x28, &D_80801128_chmineprospector, &D_80801144_chmineprospector);
    if (func_800DC298(0.3f)) {
        _subaddieaudioquick_entrypoint_3(param_0, param_0 + 0x28, &D_80801134_chmineprospector, 0.5f);
    }
}

void func_808006EC_chmineprospector(Actor *param_0, s32 param_1, ProspectorMessage37 param_2)
{
    s32 local_0;
    s32 local_1;
    s32 local_3;
    s32 local_2;

    if (param_1 == 0xF90) {
        func_800D1000(0x10, 1, 0, 1, 0);
        func_80800A64_chmineprospector(param_0, 8, 0x30);
        func_80102424(param_0, 6);
        return;
    }
    local_0 = _subaddiedialog_entrypoint_9(param_0, param_1, D_80800F20_chmineprospector, 7);
    local_1 = _subaddiedialog_entrypoint_9(param_0, param_1, ((u8 *) &D_80800F58_chmineprospector), 7);
    local_3 = _subaddiedialog_entrypoint_9(param_0, param_1, D_80800F90_chmineprospector, 4);
    if (_subaddiedialog_entrypoint_10(local_3)) {
        func_80800970_chmineprospector(param_0);
        func_80102424(param_0, 6);
        return;
    }
    if (local_0 == 1) {
        func_80800970_chmineprospector(param_0);
        func_80102424(param_0, 4);
        _glcutDll_entrypoint_6(0xB9, 12);
        return;
    }
    if (!_subaddiedialog_entrypoint_10(local_1)) {
        local_2 = param_0->unk70_10 == 7 ? 6 : 4;
        func_80800970_chmineprospector(param_0, local_2);
        func_80102424(param_0, local_2);
    }
}

void func_8080084C_chmineprospector(s32 param_0, s32 param_1, s32 param_2)
{
  s32 local_0;
  local_0 = _subaddiedialog_entrypoint_9(param_0, param_1, &D_80800F58_chmineprospector, 7);
  if (_subaddiedialog_entrypoint_10(local_0))
  {
    func_80800A64_chmineprospector(param_0, 1, 0x30);
    func_80108B04(param_0, 0 | 0);
  }
}

void func_808008A4_chmineprospector(Actor *param_0)
{
    Actor *local_0;
    Unk80132ED0 *local_1;
    f32 *local_3;
    f32 local_2[2];

    local_1 = param_0->unk0;
    local_3 = (f32 *)func_80100094(param_0, 0);
    local_2[0] = 0.0f;
    local_2[1] = local_3[3];
    local_0 = func_8010856C(0x152, local_3, local_2);
    func_80108944(local_0, (Actor *)func_80106790(local_1));
    func_80105A9C(local_0, 450.0f);
}

s32 func_80800910_chmineprospector(s32 param_0, s32 param_1, s32 param_2) {
    if (_gcdialogcamera_entrypoint_0(param_1, param_2) != 0) {
        s32* temp = func_80100094(param_0, 0);
        if (*(s32*)((char*)temp + 0x10) != 2) {
            func_808009B0_chmineprospector(param_0, 2, 1);
        }
        return 2;
    }
    return 1;
}

void func_80800970_chmineprospector(param_0) s32 param_0; {
    void *sp1C;

    sp1C = func_80100094(param_0, 0);
    if (*(s32 *)((char *)sp1C + 0x10) != 0) {
        _capod_entrypoint_3(0);
        *(s32 *)((char *)sp1C + 0x10) = 0;
    }
}

void func_808009B0_chmineprospector(param_0, param_1, param_2) Actor *param_0; s32 param_1; s32 param_2;
{
    u8 *local_0;

    local_0 = func_80100094(param_0, 0);
    switch (*(s32 *)(local_0 + 0x10)) {
        case 0:
            _capod_entrypoint_2(param_0->unk0, 15, 0);
        case 1:
            _capod_entrypoint_8(1);
            *(s32 *)(local_0 + 0x10) = 2;
            _gcdialogcamera_entrypoint_3(&D_80800FBC_chmineprospector, param_0->scale);
            _gcdialogcamera_entrypoint_4((f32 *)&param_0->actorData[4]);
            _gcdialogcamera_entrypoint_5(param_0->rotation);
            _gcdialogcamera_entrypoint_8();
        case 2:
            _capod_entrypoint_7(param_1, param_2);
            return;
    }
}

void func_80800A64_chmineprospector(param_0, param_1, param_2) Actor *param_0; s32 param_1; s32 param_2;
{
    u8 *local_0;

    local_0 = func_80100094(param_0, 0);
    switch (*(s32 *)(local_0 + 0x10)) {
        case 0:
            _capod_entrypoint_2(param_0->unk0, 15, param_2);
        case 2:
            *(s32 *)(local_0 + 0x10) = 1;
        case 1:
            _capod_entrypoint_6(param_0->unk0, param_1, param_2);
            return;
    }
}

void func_80800AF0_chmineprospector(Actor *param_0)
{
    _suexpression_entrypoint_10(func_80100094(param_0, 1), param_0->unk0, 0);
    func_8008FB10(param_0->position, 60.0f, 0.0f, 40.0f);
    switch ((u32)param_0->unk70_10) {
        case 1:
            func_80105834(param_0);
            if (func_80105998(param_0, 0.2f)) {
                _subaddiedialog_entrypoint_11(param_0->unk0, 0xF91, 6, param_0->position, 0x32);
            }
            if (func_80105998(param_0, 0.6f)) {
                func_80101180(0x143, 0x31, 0);
            }
            if (func_80105A5C(param_0)) {
                func_80102424(param_0, 2);
            }
            func_80800D34_chmineprospector(param_0);
            break;
        case 2:
            func_80800D8C_chmineprospector(param_0);
            break;
    }
}

void func_80800BF4_chmineprospector(Actor *param_0)
{
    if (!func_800DA298(0x5C) && !_glcutDll_entrypoint_20()) {
        func_800FFAB0(param_0);
        return;
    }
    if (func_800DA298(0x83) || _glcutDll_entrypoint_20()) {
        func_800C7A68(func_800D7520(((ProspectorModelReference *)func_80105494(param_0))->local_0), 0.999f, param_0->position);
        func_80102424(param_0, 2);
    } else if (param_0->unk7A_5) {
        func_800FFAB0(param_0);
        return;
    }
    func_80105A9C(param_0, 450.0f);
}

s32 func_80800CD4_chmineprospector(Actor *param_0, s32 param_1, ProspectorEventPayload param_2)
{
    switch (param_1) {
    case 0x95:
        _suexpression_entrypoint_7(param_0, 1, 0x32);
        _suexpression_entrypoint_12(func_80100094(param_0, 1), 60.0f, 20.0f);
        break;
    default:
        return 0;
    }
    return 1;
}

void func_80800D34_chmineprospector(param_0) u8 *param_0; {
    _subaddieaudioquick_entrypoint_3(param_0, param_0 + 4, &D_80801168_chmineprospector, 0.5f);
    if (func_800DC298(0.1f)) {
        _subaddieaudioquick_entrypoint_2(param_0, param_0 + 4, &D_80801178_chmineprospector);
    }
}

void func_80800D8C_chmineprospector(param_0) Actor *param_0;
{
    _subaddieaudioquick_entrypoint_4(param_0, param_0->position, &D_80801184_chmineprospector, &D_808011AC_chmineprospector);
    _subaddieaudioquick_entrypoint_3(param_0, param_0->position, &D_80801194_chmineprospector, 0.75f);
    _subaddieaudioquick_entrypoint_3(param_0, param_0->position, &D_808011A0_chmineprospector, 0.6f);
}

void func_80800DF8_chmineprospector(s32 arg0) 
{
}
s32 func_80800E00_chmineprospector(this) Actor *this;{
    if(func_80100094(this, 1)){
        _suexpression_entrypoint_8(this, 1);
    }
}

/* TU-NOTE: the .data of this overlay (formerly asm/data/overlays/ch/mine/prospector.data.s) is defined here in C --
 * tables holding function pointers must be in the same unit, otherwise IDO's assembler schedules those functions differently.
 * D_8080111A_chmineprospector is a label inside D_8080110C_chmineprospector, defined in undefined_syms.us.txt.
 * extern views adjusted to the object (address-neutral): D_80800F58_chmineprospector -> s32[], D_80800FB0_chmineprospector -> s32[], D_80800FBC_chmineprospector -> s32[], D_8080102C_chmineprospector -> int[], D_80801074_chmineprospector -> int[], D_808010BC_chmineprospector -> int[], D_80801104_chmineprospector -> s32[], D_8080110C_chmineprospector -> s32[], D_8080111C_chmineprospector -> s32[], D_80801128_chmineprospector -> s32[], D_80801134_chmineprospector -> s32[], D_80801144_chmineprospector -> s32[], D_80801168_chmineprospector -> s32[], D_80801178_chmineprospector -> s32[], D_80801184_chmineprospector -> s32[], D_80801194_chmineprospector -> s32[], D_808011A0_chmineprospector -> s32[], D_808011AC_chmineprospector -> s32[] */
extern void func_80102EC0();
u8 D_80800F20_chmineprospector[56] = { 0x0, 0x0, 0x0, 0x1, 0xF, 0x8B, 0x1, 0x0, 0x0, 0x0, 0x0, 0x1, 0xF, 0x8D, 0x2, 0x0, 0x0, 0x0, 0x2, 0x0, 0xF, 0xB8, 0x1, 0x0, 0x0, 0x0, 0x2, 0x0, 0xF, 0xBA, 0x2, 0x0, 0x0, 0x0, 0x4, 0x0, 0xF, 0xB9, 0x1, 0x0, 0x0, 0x0, 0x4, 0x0, 0xF, 0x8D, 0x2, 0x0, 0xFF, 0xFE, 0xDF, 0xFF, 0x12, 0xB, 0x3, 0x0 };
s32 D_80800F58_chmineprospector[14] = { 0x1, 0xF8C0100, 0x1, 0xF8E0200, 0x200, 0xFBB0100, 0x200, 0xFBD0200, 0x400, 0xFBC0100, 0x400, 0xFBE0200, -0x12001, 0x120B0300 };
u8 D_80800F90_chmineprospector[32] = { 0x0, 0x0, 0x0, 0x1, 0xF, 0x8F, 0x2, 0x0, 0x0, 0x0, 0x2, 0x0, 0xF, 0x8F, 0x2, 0x0, 0x0, 0x0, 0x4, 0x0, 0xF, 0x8F, 0x2, 0x0, 0xFF, 0xFE, 0xDF, 0xFF, 0x12, 0xB, 0x3, 0x0 };
s32 D_80800FB0_chmineprospector[3] = { 0x1304E4, 0xD00C0, 0xCC0000 };
s32 D_80800FBC_chmineprospector[4] = { 0x435C0000, 0x43340000, 0x43340000, 0x43200000 };
u8 D_80800FCC_chmineprospector[72] = { 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x40, 0x0, 0x0, 0x0, 0x2, 0xA5, 0x0, 0x9, 0x40, 0x0, 0x0, 0x0, 0x2, 0xA6, 0x0, 0xA, 0x41, 0x28, 0x0, 0x0, 0x2, 0xA2, 0x0, 0x9, 0x40, 0x0, 0x0, 0x0, 0x2, 0xA6, 0x0, 0x92, 0x40, 0x26, 0x66, 0x66, 0x2, 0xA3, 0x0, 0xA, 0x40, 0x33, 0x33, 0x33, 0x2, 0xA4, 0x0, 0x9, 0x40, 0x33, 0x33, 0x33, 0x2, 0xA4, 0x0, 0x9, 0x40, 0x33, 0x33, 0x33, 0x2, 0xA4, 0x0, 0x9 };
u32 D_80801014_chmineprospector[6] = { 0x0, 0x0, 0x3E99999A, 0x1DA0001, 0x40066666, 0x1DB0001 };
int D_8080102C_chmineprospector[18] = { 0x1950143, 0x7900001, (u32)&D_80800FCC_chmineprospector, (u32)func_80800024_chmineprospector, (u32)func_80105834, (u32)func_80800340_chmineprospector, 0x0, 0x0, 0x0, 0x40000122, (u32)func_80800E00_chmineprospector, 0x0, 0x140000, (u32)func_8080029C_chmineprospector, (u32)func_80107C2C, -0x7DFFFA6E, (u32)func_80800398_chmineprospector, 0x0 };
int D_80801074_chmineprospector[18] = { 0x1A60151, 0x7910001, 0x0, (u32)func_80102EC0, (u32)func_80105834, (u32)func_80101870, 0x0, 0x0, 0x0, 0x40000800, 0x0, 0x0, 0x0, (u32)func_80800DF8_chmineprospector, (u32)func_80107C2C, -0x7FF7F3EE, 0x0, 0x0 };
int D_808010BC_chmineprospector[18] = { 0x1A70152, 0x66D0001, (u32)&D_80801014_chmineprospector, (u32)func_80102EC0, (u32)func_80800AF0_chmineprospector, (u32)func_80101870, 0x0, 0x3F800000, 0x0, 0x40040120, (u32)func_80800E00_chmineprospector, 0x0, 0x0, (u32)func_80800BF4_chmineprospector, (u32)func_80107C2C, -0x7DFFFA6E, (u32)func_80800CD4_chmineprospector, 0x0 };
s32 D_80801104_chmineprospector[2] = { 0x130451, 0x180000 };
s32 D_8080110C_chmineprospector[4] = { 0x820000, 0x12C003F, 0xC, 0x6320200 };
s32 D_8080111C_chmineprospector[3] = { 0x1304E3, 0xD00C0, 0xCC0000 };
s32 D_80801128_chmineprospector[3] = { 0x130419, 0x162328, 0x0 };
s32 D_80801134_chmineprospector[4] = { 0x1304E5, 0x166D60, 0xD00C0, 0xD90000 };
s32 D_80801144_chmineprospector[9] = { 0x3E0F5C29, 0x3EA3D70A, 0x3F000000, 0x3F189375, 0x3F2D9168, 0x3F43126F, 0x3F5AE148, 0x3F770A3D, -0x40800000 };
s32 D_80801168_chmineprospector[4] = { 0x130419, 0x161770, 0xD0173, 0x18C0000 };
s32 D_80801178_chmineprospector[3] = { 0x130419, 0xD0119, 0x1330000 };
s32 D_80801184_chmineprospector[4] = { 0x130419, 0x1636B0, 0xA0119, 0x0 };
s32 D_80801194_chmineprospector[3] = { 0x130451, 0x163A98, 0x0 };
s32 D_808011A0_chmineprospector[3] = { 0x13043A, 0xD01CC, 0x1FD0000 };
s32 D_808011AC_chmineprospector[5] = { 0x3E8A3D71, 0x3F000000, -0x40800000, 0x0, 0x0 };
