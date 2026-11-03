#include "common.h"

typedef struct { u8 unk0; u8 pad1[3]; f32 unk4; f32 unk8[3]; f32 unk14[3]; } RainbowSeg;
extern RainbowSeg *func_80100074(Actor *, s32, s32);
extern void func_800EFD24(f32 *);
extern f32 func_80103EAC(Actor *);
extern void func_800EEC70(f32 *, f32, f32, f32);
extern f32 func_80103EF4(Actor *);
extern void func_800EE780(f32 *, f32 *, f32 *);
extern u8 D_80800FD0_chrainbow[];
extern f32 func_800DC0C0(void);
extern f32 func_800F1214(f32, f32, f32);
extern f32 func_800138D0(f32);
extern void func_800EF04C(f32 *, f32 *);
extern Actor *func_80106790(Unk80132ED0 *);
extern f32 func_800F10B4(f32, f32, f32, f32, f32);
extern s32 _capod_entrypoint_14(void);
extern Actor *_subaddiefind_entrypoint_2(s32, s32);
typedef struct { f32 local_0[3]; } RainbowVector;
extern RainbowVector D_80801004_chrainbow;
extern char D_80801010_chrainbow;
extern void _chrainbow_entrypoint_0();
extern s32 func_800D91EC(f32 *, f32);
typedef struct { u8 pad0[8]; f32 pos[3]; u8 pad14[0xC]; } RbEnt;
extern int func_800EEB9C(f32[3], f32, f32);
extern int func_800EE7F8(f32[3], f32[3]);
void func_80800270_chrainbow();
void func_80800838_chrainbow();

int func_80800000_chrainbow(Actor *param_0)
{
  s32 local_0;
  local_0 = func_800DA298(0x1e1);
  if (local_0 != 0)
  {
    local_0 = 13;
  }
  else
  {
    local_0 = 1;
  }
  func_80800270_chrainbow(param_0, local_0);
}

void func_8080003C_chrainbow(Actor *param_0)
{
    switch (param_0->unk70_10) {
    case 1:
        if (func_801065A4(param_0)) func_80103110(param_0, 0);
        break;
    case 2:
        if (func_800DA298(0x9DE)) func_80800270_chrainbow(param_0, 3);
        break;
    case 3:
        if (func_800D91EC(&param_0->unk58, 5.0f)) func_80800270_chrainbow(param_0, 4);
        break;
    case 4:
        if (func_800D91EC(&param_0->unk58, 6.5f)) func_80800270_chrainbow(param_0, 5);
        *(f32 *)&param_0->actorData[7] = func_800F10B4(param_0->unk58, 5.0f, 6.5f, 0.0f, 1.0f);
        break;
    case 5:
        if (func_800D91EC(&param_0->unk58, 10.5f)) func_80800270_chrainbow(param_0, 6);
        break;
    case 6:
        if (func_800D91EC(&param_0->unk58, 13.5f)) func_80800270_chrainbow(param_0, 7);
        break;
    case 8:
        if (func_800D91EC(&param_0->unk58, 18.5f)) func_80800270_chrainbow(param_0, 9);
        break;
    case 12:
        if (func_800D91EC(&param_0->unk58, 20.5f)) func_80800270_chrainbow(param_0, 13);
        *(f32 *)&param_0->actorData[7] = func_800F10B4(param_0->unk58, 18.5f, 20.5f, 1.0f, 0.0f);
        break;
    case 13:
        if (func_801065A4(param_0) && !param_0->unk64_20) {
            param_0->unk64_20 = 1;
            _glid_entrypoint_0(func_801065A4(param_0), 1, &_chrainbow_entrypoint_0, param_0->unk0);
        }
        break;
    }
    func_80800838_chrainbow(param_0);
    if (func_801065A4(param_0)) {
        _glid_entrypoint_0(func_801065A4(param_0), 1, &_chrainbow_entrypoint_0, param_0->unk0);
    }
}

void func_80800440_chrainbow();

void func_80800270_chrainbow(param_0, param_1) Actor *param_0; s32 param_1;
{
    switch (param_1) {
    case 1:
        func_80103110(param_0, 0);
        param_0->unk64_20 = 0;
        param_0->unk64_16 = 0;
        param_0->unk58 = 0.0f;
        ((f32 *)param_0->actorData)[7] = 0.0f;
        break;
    case 2:
        func_80800440_chrainbow(param_0);
        func_800DA524(0x9DF);
        break;
    case 3:
        func_80101180(0x2B0, 0xBB, 12);
        _capod_entrypoint_13(param_0->unk0, param_0->unk0, 9, 0x810);
        param_0->unk58 = 0.0f;
        break;
    case 4:
        _fxrain_entrypoint_7(func_800B7C54());
        _chglowbo_entrypoint_6();
        func_800DA544(0x580);
        break;
    case 8:
        param_0->unk64_16 = 1;
        ((f32 *)param_0->actorData)[7] = 1.0f;
        _capod_entrypoint_13(param_0->unk0, param_0->unk0, 12, 0x4810);
        _subaddieDll_entrypoint_0(param_0);
        break;
    case 12:
        param_0->unk58 = 18.5f;
        _capod_entrypoint_13(param_0->unk0, param_0->unk0, 90, 0x2810);
        break;
    case 13:
        _fxrain_entrypoint_8(func_800B7C54());
        func_800DA524(0x9DE);
        func_800DA544(0x9DF);
        func_800DA544(0x1E1);
        func_80100074(param_0, 0, 0);
        _subaddieDll_entrypoint_0(param_0);
        func_8010A63C(param_0);
        param_0->unk64_20 = 0;
        ((f32 *)param_0->actorData)[7] = 0.0f;
        param_0->unk58 = 20.5f;
        func_80103110(param_0, 0);
        break;
    }
    func_80101FDC(param_0, param_1);
}

void func_80800440_chrainbow(Actor *param_0)
{
    RainbowSeg *local_0;
    s32 i;
    f32 local_1[3];
    f32 local_2[3];

    local_0 = func_80100074(param_0, 0, 0xC0);
    for (i = 0; i < 6; i++) {
        local_0[i].unk0 = 1;
        func_800EFD24(local_0[i].unk8);
        local_0[i].unk4 = 0.0f;
        func_800EEC70(local_1, param_0->rotation[0], param_0->rotation[1] - 90.0f, func_80103EAC(param_0));
        local_2[0] = param_0->position[0] + local_1[0];
        local_2[1] = param_0->position[1] - func_80103EF4(param_0);
        local_2[2] = param_0->position[2] + local_1[2];
        func_800EEC70(local_1, param_0->rotation[0], param_0->rotation[1] - 180.0f, param_0->scale * 800.0f * ((f32)i / 5.0f));
        func_800EE780(local_0[i].unk14, local_2, local_1);
    }
}

void func_808005E0_chrainbow(f32 *param_0, s32 param_1)
{
  Actor *local_0;
  local_0 = func_800B53A4(1);
  func_800BA3FC((int)local_0, param_1 + 0x9DF);
  func_800BABB8(local_0, param_0, 0, 0x3F800000, &D_80800FD0_chrainbow);
}

void func_8080063C_chrainbow(Actor *param_0, f32 param_1, s32 param_2)
{
    Vec3f local_0;
    Vec3f local_1;
    Vec3f local_2;
    f32 local_3;
    s32 local_6;
    s32 local_7;

    for (local_7 = 0; local_7 < param_2; local_7++) {
        local_3 = func_800F1214(func_800DC0C0(), 1.0f, param_1);
        local_6 = func_800DC128(0, 6);
        func_800EEC70(local_0.f, param_0->rotation[0], param_0->rotation[1] - 90.0f, func_80103EAC(param_0));
        local_1.f[0] = param_0->position[0] + func_800F1214(local_3, -local_0.f[0], local_0.f[0]);
        local_1.f[1] = (param_0->position[1] - func_80103EF4(param_0)) +
            func_800138D0(func_800F1214(local_3, 90.0f, 270.0f)) * -func_80103EF4(param_0);
        local_1.f[2] = param_0->position[2] + func_800F1214(local_3, -local_0.f[2], local_0.f[2]);
        func_800EEC70(local_2.f, param_0->rotation[0], param_0->rotation[1] - 180.0f,
            (param_0->scale * 800.0f) * ((f32)local_6 / 5.0f));
        func_800EF04C(local_2.f, local_1.f);
        func_808005E0_chrainbow(local_2.f, local_6);
    }
}

void func_80800838_chrainbow(param_0) Actor *param_0;
{
    RbEnt *local_0;
    f32 local_8;
    f32 local_1[3];
    f32 local_10;
    f32 local_9[2];
    f32 local_2[3];
    f32 local_3;
    f32 local_4;
    f32 local_5;
    f32 local_6;
    s32 local_7;

    local_10 = 720.0f;
    local_0 = func_80100094(param_0, 0);
    switch (param_0->unk70_10) {
    case 3:
    case 4:
    case 5:
        local_3 = func_800F10B4(param_0->unk58, 0.0f, 10.5f, 0.0f, 1.0f);
        local_4 = local_3 * 1000.0f;
        local_4 = func_800F10B4(param_0->unk58, 0.0f, 5.0f, 0.0f, 200.0f);
        local_6 = func_800F10B4(param_0->unk58, 0.0f, 10.5f, 360.0f, 720.0f);
        local_8 = local_3 * local_6;
        local_3 = 0.0f;
        for (local_7 = 0, local_5 = 2.0f * local_8, local_8 = 0.0f; local_7 != 6; local_7++) {
            func_800EE7F8(local_0[local_7].pos, func_80106790(param_0->unk3C)->position);
            local_6 = (f32)local_7 * 60.0f;
            func_800EEB9C(local_1, local_5 + local_6, 100.0f);
            func_800EF04C(local_0[local_7].pos, local_1);
            local_0[local_7].pos[1] += local_4;
            func_808005E0_chrainbow(local_0[local_7].pos, local_7);
        }
        break;
    case 6:
        local_3 = func_800F10B4(param_0->unk58, 10.5f, 13.5f, 0.0f, 1.0f);
        local_4 = local_3 * 1000.0f + 200.0f;
        local_5 = local_3 * 1000.0f + 100.0f;
        local_8 = local_3 * local_10;
        local_10 = 0.0f;
        local_6 = 2.0f * local_8;
        local_8 = 0.0f;
        for (local_7 = 0; local_7 != 6; local_7++) {
            func_800EE7F8(local_0[local_7].pos, func_80106790(param_0->unk3C)->position);
            local_3 = (f32)local_7 * 60.0f;
            func_800EEB9C(local_2, local_6 + local_3, local_5);
            func_800EF04C(local_0[local_7].pos, local_2);
            local_0[local_7].pos[1] += local_4;
            func_808005E0_chrainbow(local_0[local_7].pos, local_7);
        }
        break;
    case 8:
        func_8080063C_chrainbow(param_0, 0.0f, 4);
        break;
    }
}

void chrainbow_entrypoint_0(s32 param_0, Vtx_tn *param_1, Vtx_tn *param_2,
    s32 param_3, Unk80132ED0 *param_4)
{
    Actor *local_0;
    Vtx_tn *local_1;
    f32 local_2;
    f32 local_3;
    f32 local_4;

    local_0 = func_80106790(param_4);
    local_2 = func_800F10B4(local_0->unk58, 13.5f, 18.0f, -3200.0f, 3200.0f);
    local_3 = func_800F10B4(local_0->unk58, 14.0f, 18.5f, -3200.0f, 3200.0f);
    local_1 = param_2 + param_3;
    for (; param_2 < local_1; param_2++, param_1++) {
        local_4 = param_1->ob[0];
        if (local_4 < local_3) {
            *((u8 *)param_2 + 0xF) = *((u8 *)param_1 + 0xF);
        } else if (local_4 < local_2) {
            *((u8 *)param_2 + 0xF) = (u32)func_800F10B4(local_4, local_3, local_2,
                (f32)(u32)*((u8 *)param_1 + 0xF), 0.0f);
        } else {
            *((u8 *)param_2 + 0xF) = 0;
        }
    }
}

void func_80800CD4_chrainbow(Actor *param_0)
{
    Actor *local_0[3];
    s32 local_1;
    s32 local_2;

    local_2 = _subaddiefind_entrypoint_4(0x480, local_0, 3) - 1;
    local_1 = 0;
    for (; local_2 >= 0; local_2--) {
        if (func_8010114C(local_0[local_2]->unk0, 0x4B, 0)) {
            local_1 = 1;
            break;
        }
    }
    if (local_1) {
        func_80800270_chrainbow(param_0, 0xB);
    } else {
        func_80800270_chrainbow(param_0, 0xC);
    }
}

s32 func_80800D88_chrainbow(Actor *param_0, s32 param_1, s32 param_2)
{
    Actor *local_0;

    switch (param_1) {
        case 11:
            _capod_entrypoint_14();
            if (param_2 == 9) {
                if (func_800DA298(0x1E1)) {
                    func_80800CD4_chrainbow(param_0);
                } else {
                    func_80800270_chrainbow(param_0, 8);
                }
                return 4;
            }
            if (param_2 == 12) {
                func_80800CD4_chrainbow(param_0);
            }
            return 4;
        case 0x4B:
            if (param_2 == 12) {
                func_80800270_chrainbow(param_0, 2);
                _subaddieDll_entrypoint_4(param_0, 1);
                func_80103110(param_0, 1);
                return 1;
            }
            return 0;
        case 0x4C:
            func_80800CD4_chrainbow(param_0);
            return 1;
        case 0x95:
            local_0 = _subaddiefind_entrypoint_2(0x2B0, 0);
            if (local_0) {
                param_0->unk3C = local_0->unk0;
            }
            return 1;
        default:
            return 0;
    }
}

void func_80800EB4_chrainbow(Actor *param_0, s32 param_1)
{
    RainbowVector local_0;
    func_80101870(param_0);
    switch (param_0->unk70_10) {
    case 1:
    case 13:
        break;
    default:
        local_0 = D_80801004_chrainbow;
        func_800B99CC(param_1, (s32)func_800F1214(((f32 *)param_0->actorData)[7], 0.0f, 100.0f), local_0.local_0);
        break;
    }
}

char *chrainbow_entrypoint_1()
{
  return &D_80801010_chrainbow;
}
