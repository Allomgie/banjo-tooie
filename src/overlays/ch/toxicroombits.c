#include "common.h"

typedef struct { f32 local_0[3]; } Mass43ToxicVector_80800000_chtoxicroombits;
extern s32 D_80800F00_chtoxicroombits;
extern s32 D_80800F0C_chtoxicroombits;
extern s32 D_80800F54_chtoxicroombits;
extern s32 D_80800FA0_chtoxicroombits;
extern void func_800BBCB8(f32 *, f32 *, f32, s32, void *);
extern Actor *func_80108474(s32, f32 *, s32);
extern int D_80800FB0_chtoxicroombits;
extern int D_80801004_chtoxicroombits[];
extern u8 D_80801005_chtoxicroombits[];
extern void func_800DA7A8();
extern void func_800EFA4C(f32 *, f32, f32, f32);
extern void _chmrtannoy_entrypoint_0();
extern Actor *func_80106790(Unk80132ED0 *);
extern f32 func_800F10B4(f32, f32, f32, f32, f32);
extern f32 D_80801028_chtoxicroombits[];
extern int D_80801034_chtoxicroombits;
extern void func_800E2588();
extern void func_800E2AA4();
extern f32 func_800138D0(f32);
extern f32 mlAbsF(f32);
extern s32 _subaddiefind_entrypoint_4(s32, Actor **, s32);
extern f32 func_800D91B8(f32 *);
extern f32 func_800D8FF8(void);
extern f32 func_80103EF4(Actor *);
extern f32 func_80103EAC(Actor *);
extern void _subaddieaudioloop_entrypoint_0(Actor *, f32);
extern void _sudeflect_entrypoint_1(f32 *, f32, f32, f32, s32);
typedef struct Mass43ToxicVector_80800A2C_chtoxicroombits { f32 local_0[3]; } Mass43ToxicVector_80800A2C_chtoxicroombits;
extern Mass43ToxicVector_80800A2C_chtoxicroombits D_80801010_chtoxicroombits;
extern Mass43ToxicVector_80800A2C_chtoxicroombits D_8080101C_chtoxicroombits;
extern void func_800DE498(void *, f32 *, f32 *, f32, s32, void *);
s32 func_808004C8_chtoxicroombits();
int func_808004F0_chtoxicroombits();
void func_80800960_chtoxicroombits();

s32 func_80800000_chtoxicroombits(Actor *param_0, s32 param_1, s32 param_2)
{
    Mass43ToxicVector_80800000_chtoxicroombits local_0;
    f32 *local_1;

    switch (param_1) {
    case 0x40:
        local_1 = param_0->position;
        _subaddieaudioquick_entrypoint_2(param_0, local_1, &D_80800FA0_chtoxicroombits);
        if (*(u16 *)((u8 *)param_0->unk0 + 0x14) == 0x884) {
            func_800BBCB8(local_1, NULL, 1.0f, 5, &D_80800F54_chtoxicroombits);
            if (!func_800DA298(0x1BD)) {
                func_800DA544(0x1BD);
                func_80108B04(param_0, 0);
                func_80101180(0x3A7, 10, 1);
                func_80101180(0x3EB, 0x34, 0);
            }
        } else {
            func_800BBCB8(local_1, NULL, 1.0f, 5, &D_80800F0C_chtoxicroombits);
            if (!func_800D0A9C(0x38, 1)) {
                func_808004C8_chtoxicroombits(func_808004F0_chtoxicroombits() - 1);
                if (!func_808004F0_chtoxicroombits()) {
                    func_800FC6B0(0x10);
                    func_800D1000(0x38, 1, local_1, 5, 0);
                    func_80101180(0x3EB, 0x34, 1);
                } else {
                    func_800FC6B0(0xE);
                }
            }
        }
        _chskeletonexplode_entrypoint_7(param_0, local_1);
        return 1;
    case 0xF:
        func_800FFA88(param_0->unk0);
        return 1;
    case 0x3D:
        local_0 = *(Mass43ToxicVector_80800000_chtoxicroombits *)&D_80800F00_chtoxicroombits;
        *(f32 *)&func_80108474(0x178, local_0.local_0, 0)->actorData[7] = 8.0f;
        return 1;
    }
    return 0;
}

void func_808001D4_chtoxicroombits(Actor *param_0, s32 param_1)
{
    f32 local_0;
    f32 local_1[3];
    f32 local_2[3];
    f32 local_3;

    local_0 = func_800F10B4(param_0->position[2], 2000.0f, -2000.0f, 0.0f, 1.0f);
    param_0->position[1] = func_800138D0(local_0 * 360.0f * 18.0f) * 3.0f + 395.0f;
    *(f32 *)((u8 *)param_0 + 0x44) = func_800138D0(local_0 * 360.0f * 18.0f);
    func_80101870(param_0, param_1);
    if (param_0->unk7C_12 && *(u16 *)((u8 *)param_0->unk0 + 0x14) == 0x885) {
        func_800E3980(local_2);
        if (local_2[0] < -400.0f) {
            _subaddieskeleton_entrypoint_2(param_0->unk0, 5, local_1);
        } else {
            _subaddieskeleton_entrypoint_2(param_0->unk0, 4, local_1);
        }
        if (local_1[2] < 650.0f && local_1[2] > 550.0f) {
            local_3 = mlAbsF(local_1[2] - 600.0f) / 50.0f;
        } else if (local_1[2] < -550.0f && local_1[2] > -650.0f) {
            local_3 = mlAbsF(local_1[2] + 600.0f) / 100.0f;
        } else {
            return;
        }
        func_800EFA4C(local_2, 1.0f - local_3, 1.0f - local_3, 1.0f);
        func_800E2588(1);
        func_800E2AA4(param_1, func_800D674C(0x9DE), 0, 0, local_1, local_2);
    }
}

int chtoxicroombits_entrypoint_0()
{
  return (int)&D_80800FB0_chtoxicroombits;
}

int func_80800410_chtoxicroombits()
{
  s32 v = func_808004F0_chtoxicroombits() ? func_808004F0_chtoxicroombits() : 6;
  return *(u8 *)((char *)D_80801004_chtoxicroombits + -(v << 1));
}

f32 func_80800458_chtoxicroombits(void)
{
    s32 local_0;
    local_0 = func_808004F0_chtoxicroombits() ?
        func_808004F0_chtoxicroombits() : 6;
    return (f32)(u32)D_80801005_chtoxicroombits[-(local_0 * 2)] / 10.0f;
}

s32 func_808004C8_chtoxicroombits(param_0) s32 param_0;{
    func_800DA7A8(0x6DF, param_0, 3);
}

int func_808004F0_chtoxicroombits()
{
  if (!func_800D0A9C(0x38, 1))
  {
    if (_glcutDll_entrypoint_19(0x41) == 0)
    {
      return func_800DA564(0x6DF, 3);
    }
  }
  return 6;
}

void func_80800540_chtoxicroombits(Actor *param_0)
{
    s32 local_0;
    f32 local_1 = 16.0f;

    if (!func_800DA298(0x6E2)) {
        func_808004C8_chtoxicroombits(6);
        func_800DA544(0x6E2);
    }
    *(f32 *)((u8 *)param_0 + 0x34) = func_80800458_chtoxicroombits();
    param_0->unk79_4 = func_80800410_chtoxicroombits();
    if (func_800DB9B0()) {
        param_0->unk6C_0 = 0;
    } else {
        param_0->unk6C_0 = 8;
    }
    local_0 = 16;
    param_0->unk58 = *(f32 *)((u8 *)param_0 + 0x34) / local_1;
    *(f32 *)((u8 *)param_0 + 0x18) = 0.0f;
    for (; local_0 != 0; local_0--) {
        if (--param_0->unk79_4 == 0) {
            func_80800960_chtoxicroombits(param_0, local_0);
        }
    }
}

s32 func_80800BE4_chtoxicroombits();

void func_80800630_chtoxicroombits(Actor *param_0)
{
    Actor *local_0[20];
    f32 local_1;
    Vec3f local_2;
    s32 local_3;
    s32 local_5;
    s32 local_4;
    f32 local_6;

    local_4 = _subaddiefind_entrypoint_4(0x3EA, local_0, 20);
    if (*(f32 *)&param_0->actorData[7] + 0.05f < func_80800458_chtoxicroombits()) {
        *(f32 *)&param_0->actorData[7] += 0.05f;
    } else if (func_80800458_chtoxicroombits() < *(f32 *)&param_0->actorData[7] - 0.05f) {
        *(f32 *)&param_0->actorData[7] -= 0.05f;
    } else {
        *(f32 *)&param_0->actorData[7] = func_80800458_chtoxicroombits();
    }
    _subaddieaudioloop_entrypoint_0(param_0,
        func_800F10B4(func_808004F0_chtoxicroombits(), 6.0f, 1.0f, 0.45f, 0.7f));
    func_800E3980(local_2.f);
    if (local_2.pos.x > -200.0f && !func_800DA298(0xA04) && func_800DA298(0x1BD)) {
        _subaddieaudioloop_entrypoint_1(param_0, 0x1F40);
    } else {
        _subaddieaudioloop_entrypoint_1(param_0, 0x55F0);
    }
    _subaddieaudioloop_entrypoint_4(param_0, param_0->position, 1, ((u8 *) D_80801004_chtoxicroombits));
    if (*(f32 *)&param_0->actorData[7] / 16 <= func_800D91B8(&param_0->unk58)) {
        param_0->unk58 -= *(f32 *)&param_0->actorData[7] / 16;
        if (--param_0->unk79_4 == 0) {
            func_80800960_chtoxicroombits(param_0, 0);
        }
    }
    local_3 = func_80800BE4_chtoxicroombits(param_0);
    local_1 = (func_800D8FF8() / (*(f32 *)&param_0->actorData[7] / 16)) * 250.0f;
    for (local_5 = 0; local_5 < local_4; local_5++) {
        local_0[local_5]->position[2] -= local_1;
        if (local_0[local_5]->position[2] < -2000.0f) {
            func_800FFAB0(local_0[local_5]);
        } else if (local_3) {
            local_6 = func_80103EF4(local_0[local_5]);
            _sudeflect_entrypoint_1(local_0[local_5]->position, local_6, 0.0f, func_80103EAC(local_0[local_5]), 30);
        }
    }
    if (*(f32 *)&param_0->actorData[0] != 0.0f && func_800D90A4((f32 *)&param_0->actorData[0])) {
        if (param_0->unk64_19) {
            _capod_entrypoint_13(param_0->unk0, 0, 5, 0x90);
            *(f32 *)&param_0->actorData[1] = func_80106790(func_800D0634(0x38, 1))->position[1];
        } else if (!func_800DA298(0x1BE)) {
            func_800DA544(0x1BE);
            _capod_entrypoint_13(param_0->unk0, 0, 3, 0x10);
        }
    }
}

void func_80800960_chtoxicroombits(param_0, param_1) Actor *param_0; s32 param_1;
{
    if (_glcutDll_entrypoint_19(0x41)) {
        if ((1 << param_0->unk6C_0) & 0x410) param_1 += 100;
        param_0->unk6C_0++;
    } else {
        if (--param_0->unk6C_0 == 0) {
            param_1 += 100;
            param_0->unk6C_0 = 8;
        }
    }
    func_80108B04(param_0, param_1);
    param_0->unk79_4 = func_80800410_chtoxicroombits();
}

void func_80800A2C_chtoxicroombits(Actor *param_0, void *param_1)
{
    Mass43ToxicVector_80800A2C_chtoxicroombits local_0 = D_80801010_chtoxicroombits;
    f32 local_2;
    s32 local_3;
    Mass43ToxicVector_80800A2C_chtoxicroombits local_1;
    local_0.local_0[2] += func_800F10B4(param_0->unk58, 0.0f, ((f32 *)param_0->actorData)[7] / 16, 250.0f, 0.0f);
    for (local_3 = 0; local_3 < 16; local_3++) {
        local_2 = func_800F10B4(local_0.local_0[2], -2000.0f, 2000.0f, 0.0f, 1.0f);
        local_1 = D_8080101C_chtoxicroombits;
        local_0.local_0[1] = func_800138D0((local_2 * 360.0f) * 18.0f) * 3.0f + 395.0f;
        local_1.local_0[0] = func_800138D0((local_2 * 360.0f) * 18.0f);
        func_800DF830(1);
        func_800DE498(param_1, local_0.local_0, local_1.local_0, 1.0f, 0, func_800D674C(0x882));
        local_0.local_0[2] += 250.0f;
    }
}

s32 func_80800BE4_chtoxicroombits(Actor *param_0)
{
    f32 local_0[3];

    func_800F5A00(func_800F54E4(), local_0);
    if (-600.0f <= local_0[0] && local_0[0] <= -200.0f) {
        if (func_800F6C5C(func_800F54E4())) {
            func_800EFA4C(local_0, 0.0f, 0.0f, -(4000.0f / *(f32 *)&param_0->actorData[7]));
            func_800F48BC(func_800F54E4(), local_0);
        }
        return 1;
    }
    return 0;
}

s32 func_80800CB0_chtoxicroombits(Actor *param_0, s32 param_1, s32 param_2)
{
    f32 local_0[3];
    Actor *local_1;

    switch (param_1) {
    case 0x34:
        if (param_2 != 0) {
            param_0->unk64_19 = 1;
            (*(f32 *)&param_0->actorData[0]) = 0.25f;
        } else {
            if (func_800DA298(0x6AB) == 0) {
                _chmrtannoy_entrypoint_0();
                _subaddiedialog_entrypoint_11(param_0->unk0, 0x133E, 7, param_0->position, 0xA3);
                func_800DA544(0x6AB);
            } else {
                func_800CF2D4(4);
            }
            (*(f32 *)&param_0->actorData[0]) = 1.5f;
            param_0->unk64_19 = 0;
        }
        return 1;
    case 0xE:
        if (param_2 == 5) {
            func_800EE7F8(local_0, func_80106790(func_800D0634(0x38, 1))->position);
            if ((*(f32 *)&param_0->actorData[1]) < local_0[1]) {
                local_0[1] = (*(f32 *)&param_0->actorData[1]);
            } else {
                (*(f32 *)&param_0->actorData[1]) = local_0[1];
            }
            _capod_entrypoint_19(local_0);
        }
        return 3;
    case 0x2E:
        if (((s16 *)&param_2)[0] == 0x133E) {
            func_800CF2D4(4);
        }
        return 1;
    case 0x3D:
        local_1 = func_80108474(0x3EA, D_80801028_chtoxicroombits, 0xB4);
        func_80109F08(local_1, 0x40);
        if (param_2 >= 100) {
            func_80103140(local_1, 0x885, local_1->unk0->unk16);
            param_2 -= 100;
        } else {
            func_80103140(local_1, 0x884, local_1->unk0->unk16);
        }
        local_1->position[2] -= func_800F10B4((f32)param_2, 0.0f, 16.0f, 0.0f, 4000.0f);
        return 1;
    default:
        return 0;
    }
}

int chtoxicroombits_entrypoint_1()
{
    return (int)&D_80801034_chtoxicroombits;
}
