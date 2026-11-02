#include "ch/biggafoot.h"

extern int D_80801094_chbiggafoot;
extern int D_808010DC_chbiggafoot;
extern s32 D_80801198_chbiggafoot;
extern void *func_800F54E4(void);
extern f32 func_800F5BF0(void *, f32 *);
extern s32 func_800F0008(f32 *, f32, f32 *, f32);
extern s32 func_800F6438(void *);
extern void func_800F5A00(void *, f32 *);
extern f32 func_80102D78(Actor *, u32 *);
extern void func_80102BF8(Actor *, f32, f32, f32);
extern u8 D_80801218_chbiggafoot[];
extern u8 D_808011E4_chbiggafoot[];
extern u8 D_808011D4_chbiggafoot[];
extern u8 D_80801208_chbiggafoot[];
extern u8 D_808011B4_chbiggafoot[];
extern u8 D_808011F4_chbiggafoot[];
extern u8 D_808011C4_chbiggafoot[];
extern u8 D_80801200_chbiggafoot[];
extern s16 D_80801030_chbiggafoot;
typedef struct { u8 pad[0x6C]; u32 pad6C:23; u32 f:9; } BiggaS;
extern u8 D_80801224_chbiggafoot;
extern u8 D_80801038_chbiggafoot[];
extern u8 func_800C4350(u8, s32, void *);
extern void func_800C32C4(u8, u8);
extern void func_800C3BDC(u8);
extern u8 D_80801238_chbiggafoot[];
extern f32 func_800F10B4(f32, f32, f32, f32, f32);
extern void func_800EFE50(f32 *, f32 *, f32 *, f32);
extern void func_800BBCB8(void *param_0, s32 param_1, s32 param_2, s32 param_3, void *param_4);
extern s32 D_80801244_chbiggafoot;
extern void func_80102FDC(Actor *, f32);
typedef struct { u8 pad_0[0x72]; u16 st : 6; u16 rest : 10; } BiggaState;
extern u8 D_80801124_chbiggafoot[];
extern u8 D_8080113C_chbiggafoot[];
extern u8 D_80801148_chbiggafoot[];
extern f32 func_80101F24(Actor *);
extern s32 func_80101E14(Actor *, f32);
extern void func_80102B2C(Actor *, f32);
extern f32 func_800F3780(f32, u8 *, s32);
extern f32 func_800D8FF8(void);
extern f32 func_80013970(f32);
extern f32 func_800F15F8(f32, f32, f32);
extern s32 _sudeflect_entrypoint_0(f32 *, f32, f32, s32);
extern void _sudeflect_entrypoint_4(s32, f32 *);
extern void _sudeflect_entrypoint_3(f32 *, f32 *, u8 *, u8 *, s32);
extern void func_800EF1B8(f32 *, f32, f32);
extern void func_800EFA4C(f32 *, f32, s32, f32);
typedef struct { u8 pad0[0x70]; u32 pad70_1:31; u32 unk70_0:1; } BiggaBits;
extern f32 D_80801154_chbiggafoot[];
extern u8 D_8080115C_chbiggafoot[];
extern u8 D_80801170_chbiggafoot[];
extern u8 D_80801188_chbiggafoot[];
extern void func_800FFAB0(Actor *);
extern void _capod_entrypoint_3(s32);
extern Actor *func_80106790(Unk80132ED0 *);
extern s32 _capod_entrypoint_17(f32);
extern void func_8010D930();
extern void func_8010A570(Actor *);
extern void _subaddiedialog_entrypoint_11(Unk80132ED0 *, s32, s32, f32 *, s32);
extern f32 func_800F0D50(f32, f32, f32);
extern s32 func_800B2768(s32);
extern s32 func_80103CB8(Actor *, s32);
extern s32 func_800B2840(s32);
extern void _dbmorph_entrypoint_3(s32, s32, s32, s32, f32 *);
extern void func_801015D0(Actor *);
extern void _gcdialogcamera_entrypoint_3(u8 *, f32);
extern void func_800F7F98(s32, s32);
extern void func_800EE7F8(f32 *, f32 *);
extern f32 func_800F1DF4(f32 *, f32 *);
extern Actor *func_80108528(s32, f32 *, s32, Actor **);
extern f32 func_800EEAD4(f32 *, f32 *);
extern void _capod_entrypoint_2(Unk80132ED0 *, s32, s32);
extern void _capod_entrypoint_6(Unk80132ED0 *, s32, s32);
extern void func_80102424(Actor *, s32);
void func_80800CDC_chbiggafoot();
void func_80800E98_chbiggafoot();

int *chbiggafoot_entrypoint_0()
{
    return &D_80801094_chbiggafoot;
}

int *chbiggafoot_entrypoint_1()
{
    return &D_808010DC_chbiggafoot;
}

void func_80800018_chbiggafoot(Actor *param_0)
{
    struct { f32 local_0[3]; s32 local_1; f32 local_2; f32 local_3; } local_0;

    func_80102FDC(param_0, param_0->scale * 1.6f);
    *(f32 *)((u8 *)param_0 + 0x2C) = 0.0f;
    *(f32 *)((u8 *)param_0 + 0x28) = 0.0f;
    *(f32 *)((u8 *)param_0 + 0x30) = 0.0f;
    param_0->unk50 = param_0->rotation[1];
    if (func_800A9C98()) {
        func_800DA544(0x1C7);
        func_800DA524(0x1CC);
    }
    if (_glcutDll_entrypoint_20()) {
        func_80102424(param_0, 10);
    } else {
        if (func_800DA298(0x1CC)) {
            func_800FFAB0(param_0);
            return;
        }
        _subaddiemarker_entrypoint_1(param_0, 0x320, 0x32, local_0.local_0, 1);
        func_800EE7F8((f32 *)((u8 *)param_0 + 0x18), local_0.local_0);
    }
    *(f32 *)((u8 *)param_0 + 0x34) = 3.0f;
}

void func_80800C04_chbiggafoot();

void func_80800BA4_chbiggafoot();

void func_80800A9C_chbiggafoot();

s32 func_808009EC_chbiggafoot();

void func_80800980_chbiggafoot();

s32 func_808008FC_chbiggafoot();

void func_808008D4_chbiggafoot();

void func_80800100_chbiggafoot(Actor *param_0)
{
    f32 local_0[3];
    f32 local_1[3];
    f32 *local_2;

    func_800D9078(&param_0->unk58);
    switch (((BiggaState *)param_0)->st) {
    case 1:
        func_80800980_chbiggafoot(param_0);
        if (func_808009EC_chbiggafoot(param_0)) {
            func_800F7F98(func_800F54E4(), 1);
            func_80102424(param_0, 4);
            func_80108B04(param_0, 0);
            _subaddieDll_entrypoint_4(param_0, 1);
        } else if (func_808008FC_chbiggafoot(param_0)) {
            param_0->unk64_20 = 0;
            func_80102424(param_0, 3);
        } else {
            func_808008D4_chbiggafoot(param_0);
        }
        break;
    case 2:
        func_80800980_chbiggafoot(param_0);
        break;
    case 3:
        if (!param_0->unk64_20 && func_80101F24(param_0) > 0.35f) {
            func_8010A590(param_0);
        }
        func_80800980_chbiggafoot(param_0);
        if (func_80101DDC(param_0)) {
            func_8010A570(param_0);
            func_80101FDC(param_0, 1);
        }
        break;
    case 4:
        param_0->unk54 = param_0->unk50;
        func_80102BF8(param_0, 0.15f, 5.0f, 120.0f);
        break;
    case 5:
        if (func_80101E14(param_0, 0.9f)) {
            func_80800BA4_chbiggafoot(param_0);
        }
        break;
    case 6:
        if (func_80101DDC(param_0)) {
            func_80102424(param_0, 7);
        }
        func_80800C04_chbiggafoot(param_0);
        break;
    case 7:
        func_80800C04_chbiggafoot(param_0);
        break;
    case 9:
        param_0->unk54 = func_80102D78(param_0, param_0->actorData);
        *(f32 *)&param_0->actorData[3] = func_800F3780(func_80101F24(param_0), D_80801124_chbiggafoot, 3) * 400.0f;
        func_80102B2C(param_0, func_800D8FF8() * 100.0f);
        func_8010B990(param_0, 0x1005);
        break;
    }
    if (((BiggaState *)param_0)->st >= 5 && ((BiggaState *)param_0)->st < 10) {
        *(f32 *)&param_0->actorData[6] += func_800D8FF8() * 400.0f;
        *(f32 *)&param_0->actorData[5] = func_800F10B4(func_80013970(*(f32 *)&param_0->actorData[6]), -1.0f, 1.0f, -0.2f, 0.0f);
        *(f32 *)&param_0->actorData[4] = func_800F15F8(*(f32 *)&param_0->actorData[4], 1.0f, func_800D8FF8());
    }
    local_2 = param_0->position;
    func_800EE7F8(local_0, local_2);
    if (_sudeflect_entrypoint_0(local_2, 140.0f, 160.0f, 10) & 2) {
        _sudeflect_entrypoint_4(9, local_2);
    }
    func_800EF1B8(local_0, *(f32 *)&param_0->unk50, -250.0f);
    func_800EFA4C(local_1, 0.0f, *(s32 *)&param_0->unk50, 0.0f);
    _sudeflect_entrypoint_3(local_0, local_1, D_8080113C_chbiggafoot, D_80801148_chbiggafoot, 2);
    func_80800A9C_chbiggafoot(param_0);
}

void func_808004B0_chbiggafoot(s32 arg0)
{
    func_800DA524(FLAG2_6CD_UNK);
}

void func_80800840_chbiggafoot();

s32 func_808004D4_chbiggafoot(Actor *param_0, s32 param_1, s32 param_2)
{
    f32 local_6;
    Actor *local_0;
    f32 local_1[2];
    f32 *local_3;
    f32 local_2[3];
    Actor *local_4;
    s32 local_5;

    switch (param_1) {
    case 0x2E:
        func_80800840_chbiggafoot(param_0, ((s16 *)&param_2)[0], ((s16 *)&param_2)[1]);
        break;
    case 0x0B:
        if (param_2 == 0x50) {
            func_800DA544(0x1CC);
            func_800FFAB0(param_0);
            _capod_entrypoint_3(0);
            return 4;
        }
        return 3;
    case 0x0E:
        if (param_2 == 0x5A) {
            local_0 = func_80106790(param_0->unk3C);
            local_3 = D_80801154_chbiggafoot;
            do {
                if (_capod_entrypoint_17(*local_3)) {
                    func_8010D930(4, ((BiggaBits *)local_0)->unk70_0, local_0->position, D_8080115C_chbiggafoot);
                    return 3;
                }
                local_3++;
            } while (local_3 != (f32 *)D_8080115C_chbiggafoot);
        }
        return 3;
    case 0x3F:
        func_8010A570(param_0);
        param_0->unk64_20 = 1;
        func_8010D930(1, ((BiggaBits *)param_0)->unk70_0, param_0->position, D_80801170_chbiggafoot);
        if (!param_0->unk64_19) {
            param_0->unk64_19 = 1;
            _subaddiedialog_entrypoint_11(param_0->unk0, 0x12B1, 0xE, param_0->position, 0xA8);
        }
        break;
    case 0x1F:
        local_5 = *(s32 *)&param_2;
        local_6 = func_800F0D50(((f32 *)param_0->actorData)[4] + ((f32 *)param_0->actorData)[5], 0, 1.0f);
        local_1[1] = local_6;
        local_1[0] = local_6;
        _dbmorph_entrypoint_3(func_800B2768(local_5), func_80103CB8(param_0, local_5), func_800B2840(local_5), 1, local_1);
        func_801015D0(param_0);
        break;
    case 0x52:
        _gcdialogcamera_entrypoint_3(D_80801188_chbiggafoot, param_0->scale);
        break;
    case 0x3D:
        func_800F7F98(func_800F54E4(), 0);
        func_800EE7F8(local_2, param_0->position);
        func_800EF1B8(local_2, param_0->unk50 - 40.0f, 100.0f);
        local_2[1] += 60.0f;
        local_4 = func_80108528(0x44E, (f32 *)param_0->actorData, func_800F1DF4((f32 *)param_0->actorData, local_2), &param_0);
        local_4->unk3C = (Unk80132ED0 *)param_0->unk0;
        param_0->unk3C = (Unk80132ED0 *)local_4->unk0;
        func_800EE7F8((f32 *)local_4->actorData, local_2);
        func_800EE7F8((f32 *)&local_4->actorData[4], (f32 *)param_0->actorData);
        local_4->unk58 = ((f32 *)local_4->actorData)[3] = func_800EEAD4((f32 *)param_0->actorData, local_2) / 1600.0f;
        _capod_entrypoint_2(param_0->unk0, 0x23, 0);
        _capod_entrypoint_6(local_4->unk0, 0x5A, 0x30);
        break;
    case 0x0A:
        func_80102424(param_0, 5);
        break;
    default:
        return 0;
    }
    return 1;
}

void func_80800840_chbiggafoot(Actor *param_0, s32 param_1, s32 param_2) {
    u8 *sp20;

    (*(f32 *)((u8 *)param_0 + 0x58)) = 1.5f;
    if (param_1 != 0x12B1) {
        if (param_1 == 0x12B2) {
            sp20 = (u8 *)param_0 + 0x18;
            func_800EE7F8(sp20, (u8 *)param_0 + 4);
            func_800EF1B8(sp20, *(f32 *)((u8 *)param_0 + 0x50), 1e+03f);
            func_80102424(param_0, 9);
            _capod_entrypoint_6(*(s32 *)param_0, 0x50, 0x2010);
            return;
        }
        func_80102424(param_0, 1);
    }
}

void func_808008D4_chbiggafoot(s32 param_0[3])
{
  _subaddiedialog_entrypoint_7(param_0, &param_0[1], &D_80801198_chbiggafoot);
}

s32 func_808008FC_chbiggafoot(Actor *param_0)
{
    f32 local_0[3];
    f32 local_2;
    void *local_1;

    if (param_0->unk58 > 0.0f) {
        return 0;
    }
    local_1 = func_800F54E4();
    if (!func_800F6478(local_1)) {
        return 0;
    }
    local_2 = func_800F5BF0(local_1, local_0);
    return func_800F0008(local_0, local_2, param_0->position, 180.0f);
}

void func_80800980_chbiggafoot(Actor *param_0)
{
    f32 local_0[3];
    if (func_800F6438(func_800F54E4())) {
        func_800F5A00(func_800F54E4(), local_0);
        param_0->unk54 = func_80102D78(param_0, local_0);
        func_80102BF8(param_0, 0.15f, 5.0f, 120.0f);
    }
}

s32 func_808009EC_chbiggafoot(Actor *param_0)
{
    s32 local_0;

    local_0 = func_8010C9B0(param_0->position, 0x320);
    func_800DA3B8(0x6CD, local_0);
    if (!local_0) {
        ((f32 *)param_0->actorData)[7] = 3.0f;
        return 0;
    }
    if (!func_800F6478(func_800F54E4())) return 0;
    if (func_800DA298(0x9FB) && func_800DA298(0x1C7)) {
        return func_800D9078(&param_0->actorData[7]);
    }
    return 0;
}

void func_80800A9C_chbiggafoot(s32 param_0)
{
    s32 *s1 = (s32 *)param_0;
    s32 *s0;
    int ret;

    ret = func_801022E4();
    switch (ret) {
    case 0x389:
        s0 = s1 + 1;
        _subaddieaudioquick_entrypoint_3(param_0, s0, &D_808011B4_chbiggafoot, 0x3F400000);
        _subaddieaudioquick_entrypoint_4(param_0, s0, &D_808011D4_chbiggafoot, &D_808011F4_chbiggafoot);
        _subaddieaudioquick_entrypoint_4(param_0, s0, &D_808011C4_chbiggafoot, &D_808011E4_chbiggafoot);
        return;
    case 0x38B:
        s0 = s1 + 1;
        _subaddieaudioquick_entrypoint_3(param_0, s0, &D_80801200_chbiggafoot, 0x3DF5C28F);
        _subaddieaudioquick_entrypoint_3(param_0, s0, &D_80801208_chbiggafoot, 0x3F1EB852);
        return;
    case 0x38A:
        _subaddieaudioquick_entrypoint_3(param_0, param_0 + 4, &D_80801218_chbiggafoot, 0x3EB33333);
        return;
    }
}

void func_80800BA4_chbiggafoot(Actor *param_0)
{
    func_80102424(param_0, 6);
    param_0->unk6C_0 = 0;
    param_0->unk3C = NULL;
    *(f32 *)&param_0->actorData[3] = 1.0f;
    _capod_entrypoint_20(param_0->unk0, D_80801030_chbiggafoot, 0x10);
    func_80800CDC_chbiggafoot(param_0);
}

void func_80800C04_chbiggafoot(Actor *param_0)
{
    if (func_800D9078((f32 *)&param_0->actorData[3])) {
        param_0->unk6C_0++;
        if (param_0->unk6C_0 == 4) {
            _capod_entrypoint_20(param_0->unk0, 0x7F, 0x10);
            _subaddiedialog_entrypoint_11(param_0->unk0, 0x12B2, 6, param_0->position, 0xA8);
            func_80102424(param_0, 8);
        } else {
            _capod_entrypoint_20(param_0->unk0, ((s16 *)&D_80801030_chbiggafoot)[param_0->unk6C_0], 0x10);
            func_80800CDC_chbiggafoot(param_0);
            *(f32 *)&param_0->actorData[3] = 1.0f;
        }
    }
}

void func_80800CDC_chbiggafoot(BiggaS *param_0) {
    u8 local_0 = func_800C4350(0, 0, &D_80801224_chbiggafoot);
    func_800C32C4(local_0, D_80801038_chbiggafoot[param_0->f]);
    func_800C3BDC(local_0);
}

int func_80800D38_chbiggafoot(int param_0)
{
  int new_var;
  func_80102FDC(param_0, 1.4f);
  new_var = 0;
}

void func_80800D5C_chbiggafoot(Actor *param_0)
{
    s32 local_0;
    f32 local_3;
    f32 local_1[3];

    local_0 = func_800D9078(&param_0->unk58);
    local_3 = func_800F10B4(param_0->unk58, 0.0f, *(f32 *)((u8 *)param_0 + 0x24), 1.0f, 0.0f);
    func_800EFE50(param_0->position, (f32 *)((u8 *)param_0 + 0x28), (f32 *)param_0->actorData, local_3);
    func_80800E98_chbiggafoot(param_0);
    if (param_0->unk70_10 == 1 && local_0) {
        func_800EE7F8(local_1, param_0->position);
        _chexploder_entrypoint_3(param_0, local_1, 0xB);
        _subaddieaudioquick_entrypoint_2(param_0, param_0->position, D_80801238_chbiggafoot);
        func_80101FDC(param_0, 2);
        func_8010114C(param_0->unk3C, 0xA, 0);
    }
}

s32 func_80800E2C_chbiggafoot(s32 param_0, s32 param_1, s32 param_2) {
    s32 local_0;
    s32 local_1;

    if (param_1 == 0x90) {
        local_1 = func_80106790(func_80101080());
        local_0 = local_1;
        _chexploder_entrypoint_9(local_1, 1, 2);
        _chexploder_entrypoint_6(local_0, 0x43C80000, 0x43FA0000);
    } else {
        return 0;
    }
    return 1;
}

void func_80800E98_chbiggafoot(param_0) Actor *param_0;
{
  s32 *local_1;
  s32 *new_var;
  local_1 = &local_1[0x38];
  local_1 = (s32 *) (((u8 *) param_0) + 0x38);
  new_var = local_1;
  func_800BBCB8(((s32) param_0) + 4, 0, *new_var, 1, &D_80801244_chbiggafoot);
  local_1 = &local_1[0x38];
}
