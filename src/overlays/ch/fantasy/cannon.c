#include "common.h"

extern s32 D_80800CF8_chfantasycannon[];
extern s32 func_800B5BE4(s32);
extern void func_800F5A00(u32, f32 *);
extern s32 func_800BABB8(s32, f32 *, f32 *, f32, s32 *);
extern f32 func_800F1DF4(f32 *, f32 *);
extern void func_800EF1B8(f32 *, f32, f32);
extern void *func_80100094(Actor *, s32);
extern f32 func_800EEB40(f32 *, f32 *);
extern void func_800EFE50(f32 *, f32 *, f32 *, f32);
extern f32 func_800DC0C0(void);
extern void func_800EEC30(f32 *, f32, f32, f32);
extern void func_800EF334(f32 *, f32);
extern int D_80800D30_chfantasycannon;
extern void *D_80800D78_chfantasycannon;
extern s32 _sudeflect_entrypoint_0(f32 *, f32, f32, s32);
extern s32 func_80101E14(Actor *, f32);
extern f32 func_80101F24(Actor *);
extern f32 func_800F10B4(f32, f32, f32, f32, f32);
extern f32 func_80013970(f32);
extern void func_800EFA4C(f32 *, f32, f32, f32);
extern s32 func_800F78EC(s32, f32 *, f32, f32);
extern f32 sqrtf(f32);
int func_808009B8_chfantasycannon();
void func_80800544_chfantasycannon();

int func_80800000_chfantasycannon(Actor *param_0)
{
  func_800DA298(((u32)*(u16 *)((char *)param_0 + 0x76) >> 7) + 0x55D);
}

int func_80800028_chfantasycannon(Actor *param_0)
{
  func_800DA544(((u32)*(u16 *)((char *)param_0 + 0x76) >> 7) + 0x55D);
}

int func_80800050_chfantasycannon()
{
  s32 local_0;
  if (!func_8010C500())
  {
    return 0;
  }
  local_0 = func_800F54E4();
  if (func_800F64DC(local_0 | 0) == 0)
  {
    return 0;
  }
  return 1;
}

void func_808000A4_chfantasycannon(void)
{
    f32 local_1[3];
    s32 local_0;

    local_0 = func_800B5BE4(0x1A);
    func_800F5A00(func_800F54E4(), local_1);
    local_1[1] += 60.0f;
    func_800BABB8(local_0, local_1, NULL, 1.0f, D_80800CF8_chfantasycannon);
}

void func_8080010C_chfantasycannon(Actor *param_0)
{
    void *local_0[20];
    s32 local_1 = 0;
    s32 local_2;
    s32 local_3;
    local_2 = _gccubesearch_entrypoint_9(0x47E, local_0, 20);
    if (!_subaddieDll_entrypoint_1(param_0)) {
        func_800FFA88(param_0->unk0);
        return;
    }
    for (local_3 = 0; local_3 < local_2; local_3++) {
        if (_gspropctrl_entrypoint_8(local_0[local_3]) == param_0->unk74_7) {
            _gspropctrl_entrypoint_11(local_0[local_3], (f32 *)param_0->actorData);
            func_800EF1B8((f32 *)param_0->actorData, func_800F1DF4((f32 *)param_0->actorData, param_0->position), -70.0f);
            *(f32 *)((u8 *)param_0 + 0x1C) += 60.0f;
            local_1 = 1;
            break;
        }
    }
    if (!local_1) {
        func_800FFA88(param_0->unk0);
        return;
    }
    func_808009B8_chfantasycannon(param_0);
    param_0->unk64_19 = 0;
}

void func_808008B0_chfantasycannon();

void func_80800228_chfantasycannon(Actor *param_0)
{
  s32 pad0;
    f32 local_0[3];
    f32 local_1;

    switch (param_0->unk70_10) {
        case 1:
            if (func_80800050_chfantasycannon(param_0)) {
                func_80800544_chfantasycannon(param_0, 3);
                return;
            }
            _sudeflect_entrypoint_0(param_0->position, param_0->scale * 226.0f * 0.75f,
                param_0->scale * 226.0f * 0.75f, 14);
            return;
        case 2:
            if (func_800D90A4(&param_0->unk54)) {
                func_80800544_chfantasycannon(param_0, 3);
                return;
            }
        default:
            return;
        case 3:
            if (func_80101E14(param_0, 0.47f)) {
                func_800C3F48(0x7FFB5E0D);
                func_80800544_chfantasycannon(param_0, 4);
            }
            if (func_80101E14(param_0, 0.16f)) {
                func_800F4CEC(func_800F54E4(), 0x2E);
                param_0->unk64_20 = 0;
            }
            if (func_80101E14(param_0, 0.01f)) {
                func_800C3F48(0x665B5E0C);
            }
            if (func_80101F24(param_0) <= 0.3f) {
                local_1 = func_800F10B4(func_80101F24(param_0), 0.0f, 0.16f, 0.0f, 1.0f);
                func_800EFE50(local_0, (f32 *)&param_0->actorData[4], param_0->position, local_1);
                local_0[1] += func_80013970(local_1 * 180.0f) * 300.0f;
                func_800F8294(func_800F54E4(), local_0);
                return;
            }
            break;
        case 4:
            if (func_80101DDC(param_0)) {
                func_80800544_chfantasycannon(param_0, 5);
            } else if (func_80101F24(param_0) >= 0.5f) {
                func_808000A4_chfantasycannon();
                if (!param_0->unk64_20 && func_80101E14(param_0, 0.5f)) {
                    param_0->unk64_20 = 1;
                    func_800F4CC0(func_800F54E4());
                }
            }
            func_800F7B9C(func_800F54E4(), 140);
            func_808008B0_chfantasycannon(param_0);
            return;
        case 5:
            func_808000A4_chfantasycannon();
            if (func_800F6C5C(func_800F54E4())) {
                func_80800544_chfantasycannon(param_0, 6);
            }
            func_800F7B9C(func_800F54E4(), 140);
            func_808008B0_chfantasycannon(param_0);
            return;
        case 6:
            if (func_800D90A4(&param_0->unk54)) {
                func_80800544_chfantasycannon(param_0, 1);
                return;
            }
            func_808008B0_chfantasycannon(param_0);
            break;
    }
}

void func_80800544_chfantasycannon(param_0, param_1) Actor *param_0; s32 param_1;
{
    f32 *local_0;
    f32 local_1[3];
    f32 local_2[3];
    s32 local_8;
    f32 local_3;
    f32 local_4;
    s32 local_10;
    f32 local_5[3];
    f32 local_6[3];
    f32 local_7[3];
    f32 local_9;

    local_0 = func_80100094(param_0, 0);
    switch (param_1) {
    case 1:
        _subaddieDll_entrypoint_4(param_0, 0);
        func_800F7F98(func_800F54E4(), 0);
        if (param_0->unk64_19) {
            param_0->unk64_19 = 0;
            _capod_entrypoint_3(0);
        }
        break;
    case 2:
        param_0->unk54 = 1.0f;
        break;
    case 3:
        if (func_800DA298(0x1E1)) {
            local_8 = (Actor *)_subaddiefind_entrypoint_2(0x40E, 0);
            if (local_8) func_8010A624(local_8);
        }
        _subaddieDll_entrypoint_4(param_0, 1);
        func_8010FFB0(func_800F5EF8(func_800F54E4()), local_2, local_1);
        _capod_entrypoint_2(param_0->unk0, 45, 0x10804);
        _capod_entrypoint_8(0);
        _capod_entrypoint_1(local_2, local_1);
        if (func_80800000_chfantasycannon(param_0)) {
            func_800EE7F8(local_0, local_2);
            func_800EE7F8(local_0 + 3, local_1);
        }
        func_800F7F98(func_800F54E4(), 1);
        param_0->unk64_19 = 1;
        func_800F5A00(func_800F54E4(), (f32 *)&param_0->actorData[4]);
        *(s32 *)&param_0->unk50 = func_80015184();
        func_80015178(4);
        break;
    case 4:
        if (func_80800000_chfantasycannon(param_0)) {
            local_0 = (f32 *)param_0->actorData;
            func_800EEC30(local_6, 45.0f, func_800F1DF4(local_0, param_0->position), 1250.0f);
            func_800EFA4C(local_5, ((f32 *)param_0->actorData)[0] + local_6[0],
                         ((f32 *)param_0->actorData)[1] + local_6[1],
                         ((f32 *)param_0->actorData)[2] + local_6[2]);
            func_800F8294(func_800F54E4(), local_5);
            local_4 = -1250.0f;
            local_3 = 50.0f;
        } else {
            local_4 = -800.0f;
            func_800EFA4C(local_7, param_0->position[0], param_0->position[1] + 350.0f, param_0->position[2]);
            func_800F8294(func_800F54E4(), local_7);
            local_9 = 1700.0f;
            local_3 = local_9 * local_9 - (((f32 *)param_0->actorData)[1] - local_7[1]) * (local_4 + local_4);
            if (local_3 > 0.0f) {
                local_0 = (f32 *)param_0->actorData;
                local_3 = sqrtf(local_3);
            } else {
                local_3 = local_9;
                local_0 = (f32 *)param_0->actorData;
            }
        }
        func_800F78EC(func_800F54E4(), local_0, local_3, local_4);
        break;
    case 6:
        param_0->unk54 = 0.25f;
        func_80015178(*(s32 *)&param_0->unk50);
        func_80800028_chfantasycannon(param_0);
        if (func_800DA298(0x1E1)) {
            local_10 = (Actor *)_subaddiefind_entrypoint_2(0x40E, 0);
            if (local_10) func_8010A63C(local_10);
        }
        break;
    }
    func_80102424(param_0, param_1);
}

void func_808008B0_chfantasycannon(Actor *param_0)
{
    f32 local_0[3];
    f32 local_1[3];
    f32 local_2[3];
    f32 *local_3;

    local_3 = func_80100094(param_0, 0);
    if (func_80800000_chfantasycannon(param_0)) {
        if ((s32)param_0->unk70_10 < 4) {
            _capod_entrypoint_1(local_3, local_3 + 3);
        } else {
            func_800A516C(local_0, param_0->actorData, local_3 + 6);
            _capod_entrypoint_1(local_3 + 6, local_0);
        }
    } else {
        func_800F5A00(func_800F54E4(), local_2);
        func_800EFE50(local_1, local_3 + 6, local_3,
                     func_800EEB40(local_2, (f32 *)param_0->actorData) / func_800EEB40(param_0->position, (f32 *)param_0->actorData));
        func_800A516C(local_0, local_2, local_1);
        _capod_entrypoint_1(local_1, local_0);
    }
}

int func_808009B8_chfantasycannon(param_0) Actor *param_0;
{
    f32 *local_5;
    f32 local_0[3];
    f32 local_1[3];
    f32 local_6;
    u8 *local_2;
    s32 local_7;
    s32 local_8;
    local_2 = (u8 *)func_80100094(param_0, 0);
    local_6 = func_800F1DF4(param_0->position, (f32 *)param_0->actorData) - 180.0f;
    local_7 = 5;
    local_8 = 60;
    local_5 = (f32 *)(local_2 + 0x18);
    do {
        func_800EEC30(local_0, func_800DC0C0() * 10.0f + 25.0f, local_8 + local_6, 2000.0f);
        func_800EE780(local_5, (f32 *)param_0->actorData, local_0);
        if (!func_800BEF00(param_0->position, local_5, local_1, 0)) break;
        func_800EEC30(local_0, func_800DC0C0() * 10.0f + 25.0f, local_7 * -12 + local_6, 2000.0f);
        func_800EE780(local_5, (f32 *)param_0->actorData, local_0);
        if (!func_800BEF00(param_0->position, local_5, local_1, 0)) break;
        local_7++;
        local_8 += 12;
    } while (local_7 >= 0);
    func_800EE780(local_2, local_5, param_0->position);
    func_800EF334((f32 *)local_2, 0.5f);
}

int chfantasycannon_entrypoint_0()
{
    return (int)&D_80800D30_chfantasycannon;
}

void func_80800B84_chfantasycannon()
{
    func_80101870();
}

void func_80800BA4_chfantasycannon(u8 *param_0) {
    *(f32 *)(param_0 + 0x48) = 0.0f;
    if ((u32)(((u16 *)(param_0 + 0x76))[0]) >> 7 == 0x38) {
        func_800FFAB0();
    }
}

void func_80800BDC_chfantasycannon(Actor *param_0)
{
    s32 local_0;
    local_0 = _plsu_entrypoint_3(param_0->unk0);
    if (!local_0 && func_800D90A4(&param_0->unk58) && !param_0->unk64_20) {
        func_800C3F48(0x731C5699);
        param_0->unk58 = 0.5f;
    }
    param_0->unk64_20 = !local_0;
}

int chfantasycannon_entrypoint_1()
{
  return &D_80800D78_chfantasycannon;
}
