#include "ch/boggy/girl.h"

extern int D_80800CF0_chboggygirl[];
extern void *func_80100094(Actor *, u32);
typedef struct { u8 pad_0[0x14]; u32 pad_1 : 17; u32 local_0 : 1; u32 pad_2 : 14; } BoggyGirlFlags;
typedef struct { u8 pad[0x74]; u8 b7 : 1; u8 b6 : 1; u8 b5 : 1; u8 b4 : 1; u8 b3 : 1; u8 b2 : 1; u8 b1 : 1; u8 b0 : 1; } BitS116;
extern f32 func_800DC178(f32, f32);
extern f32 func_801028C4(void *, f32 *, f32, f32, f32);
extern f32 func_80102D78(void *, f32 *);
extern void func_80102BF8(void *, f32, f32, f32);
extern s32 func_80102CF4(void *, f32);
extern void func_80102424(void *, s32);
extern s32 func_800D9154(f32 *, f32);
extern void _subaddierouteDll_entrypoint_6(void *, void *, s32, s32, f32, s32, s32);
extern void _subaddierouteDll_entrypoint_7(void *, void *, f32, f32, f32, s32);
extern s32 _subaddierouteDll_entrypoint_4(void *);
extern s32 func_8010B990(void *, s32);
extern void func_801058C4(void *, s32, f32, s32);
extern s32 func_800F0064(void *, f32, f32 *);
extern void _sudeflect_entrypoint_0();
extern u8 D_80800D58_chboggygirl[];
extern u8 D_80800D48_chboggygirl[];
extern void _gcdialogcamera_entrypoint_3(void *, f32);
extern void func_800C9C70(f32, s32, f32, s32, f32 *, f32, f32);
extern u8 D_80800C50_chboggygirl[];
extern void func_80102924(Actor *, f32);
void func_8080093C_chboggygirl();
s32 func_80800508_chboggygirl();
void func_80800708_chboggygirl();
extern void func_80101870(), func_80107C2C(), func_8080000C_chboggygirl(), func_8080091C_chboggygirl(), func_8080097C_chboggygirl();
extern u8 D_80800C68_chboggygirl[];

int *chboggygirl_entrypoint_0()
{
    return &D_80800CF0_chboggygirl;
}

void func_8080000C_chboggygirl(param_0) Actor *param_0;
{
    u8 *local_0;
    local_0 = func_80100094(param_0, 0);
    if (!_chboggykids_entrypoint_0(param_0)) {
        func_800FFAB0(param_0);
    } else {
        *(f32 *)&param_0->actorData[3] = 240.0f;
        _subaddieDll_entrypoint_1(param_0);
        _subaddierouteDll_entrypoint_3(param_0, local_0 + 8, param_0->position);
        _subaddieitem_entrypoint_0(local_0 + 0x18, 0x3CB, 0x190, 1);
        *(s16 *)(local_0 + 0x14) = 0;
        func_8080093C_chboggygirl(param_0);
    }
}

void func_808000A8_chboggygirl(Actor *param_0)
{
    extern u16 D_80800D38_chboggygirl[];
    extern u8 D_80800C50_chboggygirl[];

    char *local_0;
    s32 local_3;
    f32 local_2[3];
    f32 local_4[3];
    char *local_1;
    char *local_5;

    local_0 = (char *)func_80100094(param_0, 0);

    if (func_800DA298(0xB9)) {
        if (func_80800B5C_chboggygirl(0x3CB)) {
            if (!func_8010CAC0((char *)param_0 + 4, 0x320)) {
                ((BitS116 *)(param_0))->b6 = 0;
            }
        }
    }

    local_3 = func_800D90A4((char *)param_0 + 0x58);

    local_1 = (char *)func_80100094(param_0, 1);
    if (local_1 != 0) {
        local_5 = (char *)func_80100094(param_0, 1);
        _suexpression_entrypoint_10(
            local_5,
            *(s32 *)((char *)param_0 + 0),
            0
        );
    }


    switch (((u32) (*(u16 *)((char *)param_0 + 0x72)) >> 10)) {
        case 1:
            if (!_subaddiedialog_entrypoint_8(
                    param_0,
                    (char *)param_0 + 4,
                    D_80800D38_chboggygirl,
                    D_80800C50_chboggygirl,
                    3) &&
                local_3) {
                func_80102924(
                    param_0,
                    *(f32 *)((char *)param_0 + 0x48) +
                        func_800DC178(90.0f, 270.0f)
                );

                func_80102424(param_0, 3);
                *(s16 *)(local_0 + 0x14) = 0;
            }
            break;

        case 4:
            func_8010CE70(param_0, 10, -1);
            break;

        case 3:
            func_80102BF8(
                param_0,
                0.2f,
                60.0f,
                180.0f
            );

            if (func_80102CF4(param_0, 15.0f)) {
                *(f32 *)((char *)param_0 + 0x58) =
                    func_800DC178(8.0f, 12.0f);

                func_80102424(param_0, 2);
            }

            _subaddiedialog_entrypoint_8(
                param_0,
                (char *)param_0 + 4,
                D_80800D38_chboggygirl,
                D_80800C50_chboggygirl,
                3
            );
            break;

        case 2:
            func_80105230(param_0, 0);

            if (!_subaddiedialog_entrypoint_8(
                    param_0,
                    (char *)param_0 + 4,
                    D_80800D38_chboggygirl,
                    D_80800C50_chboggygirl,
                    3)) {
                _subaddierouteDll_entrypoint_6(
                    param_0,
                    local_0 + 8,
                    *(s16 *)(local_0 + 0x14),
                    7,
                    0.7f,
                    8,
                    12
                );

                if (_subaddierouteDll_entrypoint_4(param_0)) {
                    _subaddierouteDll_entrypoint_7(
                        param_0,
                        local_0 + 8,
                        *(f32 *)((char *)param_0 + 0x48),
                        *(f32 *)((char *)param_0 + 0x54),
                        200.0f,
                        0x4000
                    );

                    *(u16 *)(local_0 + 0x14) =
                        *(u16 *)(local_0 + 0x0E);
                }

                func_80102BF8(
                    param_0,
                    0.2f,
                    30.0f,
                    180.0f
                );

                if (func_8010B990(param_0, 0x1305) & 4) {
                    func_80102924(
                        param_0,
                        *(f32 *)((char *)param_0 + 0x48) +
                            180.0f
                    );

                    func_80102424(param_0, 3);
                    *(s16 *)(local_0 + 0x14) = 0;
                } else if (local_3) {
                    func_80102424(param_0, 1);
                    *(f32 *)((char *)param_0 + 0x58) =
                        func_800DC178(4.0f, 6.0f);
                }
            }
            break;

        case 5:
            {
            func_800EE88C(local_2, local_0);

            if (func_801028C4(
                    param_0,
                    local_2,
                    0.2f,
                    30.0f,
                    180.0f) < 40.0f) {
                func_80102424(param_0, 6);
            }
            }
            break;

        case 6:
            {
            func_800EE88C(local_4, local_0);

            *(f32 *)((char *)param_0 + 0x54) =
                func_80102D78(param_0, local_4);

            func_80102BF8(
                param_0,
                0.2f,
                30.0f,
                180.0f
            );

            func_8010B990(param_0, 0x1005);

            if (func_800F0064(
                    (char *)param_0 + 4,
                    100.0f,
                    local_4)) {
                func_801058C4(
                    param_0,
                    *(s16 *)(local_0 + 6),
                    *(f32 *)((char *)param_0 + 0x24),
                    1
                );

                func_80105BAC(param_0);
                func_80102424(param_0, 7);
            }
            }
            break;

        case 15:
            if (_subaddieitem_entrypoint_3(
                    param_0,
                    0,
                    local_0 + 0x18)) {
                _subaddiedialog_entrypoint_11(
                    *(s32 *)((char *)param_0 + 0),
                    0x1090,
                    0xE,
                    (char *)param_0 + 4,
                    0x3B
                );

                func_80102424(param_0, 4);
            }
            break;
    }

    _sudeflect_entrypoint_0((char *)param_0 + 4, 0x42C80000, 0x42480000, 10);
}

s32 func_80800ABC_chboggygirl();

s32 func_80800508_chboggygirl(param_0, param_1, param_2) Actor *param_0; s32 param_1; s32 param_2;
{
    f32 *local_0;
    s32 local_1;

    switch (param_1) {
    case 0x2E:
        func_80800708_chboggygirl(param_0, ((s16 *)&param_2)[0], ((s16 *)&param_2)[1]);
        break;
    case 0x95:
        _subaddierouteDll_entrypoint_1(param_0);
        param_0->unk74_30 = func_800DA298(0xB9);
        break;
    case 0x29:
        func_80800ABC_chboggygirl(param_0);
        break;
    case 0x52:
        _gcdialogcamera_entrypoint_3(D_80800D48_chboggygirl, param_0->scale);
        break;
    case 0xB8:
        switch (param_2 & 0xFFFF) {
        case 1:
            if (func_800DA298(0xB9)) {
                local_1 = func_80800B5C_chboggygirl(0x3CB) ? 0x108E : 0x108C;
                return local_1;
            }
            return 0x108C;
        case 2:
            local_1 = func_80800B5C_chboggygirl(0x3CB) ? 0x108E : 0x108C;
            return local_1;
        }
        break;
    case 0x2D:
        local_0 = param_0->position;
        _subaddieaudioquick_entrypoint_2(param_0, local_0, D_80800D58_chboggygirl);
        func_800C9C70(1.0f, 0x525, 1.05f, 22000, local_0, 200.0f, 3000.0f);
        break;
    case 0x30:
        return 3 - func_800DA980(0x8C, 3);
    case 0x2A:
        func_80800B28_chboggygirl(param_0);
        break;
    default:
        return 0;
    }
    return 1;
}

void func_80800A4C_chboggygirl();

void func_80800708_chboggygirl(param_0, param_1, param_2) Actor *param_0; s32 param_1; s32 param_2;
{
    u8 *local_0;
    local_0 = func_80100094(param_0, 0);
    switch (param_1) {
    case 0x1090:
        func_80102424(param_0, 5);
        _subaddieDll_entrypoint_4(param_0, 1);
        func_800DA544(0x8D);
        func_80800A4C_chboggygirl(param_0);
        func_80101180(0x13F, 0x23, 0);
        break;
    case 0x108F:
        func_80102924(param_0, param_0->rotation[1] + 180.0f);
        func_80102424(param_0, 3);
        *(s16 *)(local_0 + 0x14) = 0;
        break;
    case 0x108E:
        _subaddiedialog_entrypoint_11(param_0->unk0, 0x108B, 0x4E, param_0->position, 0x3C);
        break;
    case 0x108B:
        if (param_2 > 0) {
            func_80102424(param_0, 0xF);
            _subaddieitem_entrypoint_2(local_0 + 0x18);
        } else {
            _subaddiedialog_entrypoint_11(param_0->unk0, 0x108F, 0xE, param_0->position, 0x3C);
        }
        break;
    case 0x1098:
    case 0x1099:
        local_0[0x16] &= ~0x40;
        break;
    default:
        switch (_subaddiedialog_entrypoint_9(param_0, param_1, D_80800C50_chboggygirl, 3)) {
        case 1:
            func_800DA544(0xB9);
            if (func_80800B5C_chboggygirl(0x3CB)) {
                _subaddiedialog_entrypoint_11(param_0->unk0, 0x108E, 0xE, param_0->position, 0x3C);
                return;
            }
            func_800C01A8(100, 0);
            func_800C0850();
        case 2:
            func_80102924(param_0, param_0->rotation[1] + 180.0f);
            func_80102424(param_0, 3);
            *(s16 *)(local_0 + 0x14) = 0;
            break;
        default:
            func_80102424(param_0, 1);
            break;
        }
        break;
    }
}

void func_8080091C_chboggygirl(Actor* arg0)
{
    func_80800B28_chboggygirl(arg0);
}

void func_8080093C_chboggygirl(param_0) s32 param_0; {
    u8 *sp24;
    s8 _sfpad[8];
    s32 sp18;

    sp24 = func_80100094(param_0, 0);
    (*(s16 *)((s8 *)(sp24) + (6))) = _glsplinefind_entrypoint_0(0x3A1, &sp18);
    func_800EE940(sp24, &sp18);
}

void func_8080097C_chboggygirl(param_0) Actor *param_0;
{
    BoggyGirlFlags *local_0;

    local_0 = func_80100094(param_0, 0);
    if (param_0->unk70_10 == 0x10) {
        if (!local_0->local_0) func_800FFAB0(param_0);
    } else {
        func_80105834(param_0);
        _sudeflect_entrypoint_0(param_0->position, 0x42C80000, 0x42480000, 10);
        func_80105230(param_0, 0);
        if (func_80105A5C(param_0)) {
            if (local_0->local_0) {
                func_80102424(param_0, 0x10);
                param_0->unk64_16 = 0;
            } else {
                func_800FFAB0(param_0);
            }
        }
    }
}

void func_80800A4C_chboggygirl(Actor *param_0)
{
  Actor *new_var;
  s32 var_a1;
  u8 *temp_v0;
  new_var = param_0;
  if (func_800DA980(0x8C, 3) == 3)
  {
    var_a1 = 0x1099;
  }
  else
  {
    var_a1 = 0x1098;
  }
  _subaddiedialog_entrypoint_11(*((s32 *) (((char *) new_var) + 0x0)), var_a1, 0xF, (u32 *)new_var + 1, 0x3c);
  temp_v0 = func_80100094(new_var, 0);
  *((u8 *) (((char *) temp_v0) + 0x16)) = ((*((u8 *) (((char *) temp_v0) + 0x16))) & 0xFF) | 0x40;
}

s32 func_80800ABC_chboggygirl(Actor *this){
    if(!func_80100094(this, 1)){
        _suexpression_entrypoint_7(this, 1, 0x3C);
        _suexpression_entrypoint_12(func_80100094(this, 1), 0x42700000, 0x41A00000);
        _suexpression_entrypoint_17(func_80100094(this, 1), 0x3E8);
    }
}

void func_80800B28_chboggygirl(Actor* arg0) 
{
    if (func_80100094(arg0,1) != 0)
    {
        _suexpression_entrypoint_8(arg0, 1);
    }
}
int func_80800B5C_chboggygirl(s32 param_0)
{
  s32 local_0;
  local_0 = func_800F54E4();
  if (!func_800F64A4(local_0 | 0, 0x201))
  {
    return 0;
  }
  else
  {
    return func_800F640C(local_0, param_0) > 0;
  }
}

/* TU-NOTE: the .data of this overlay (formerly asm/data/overlays/ch/boggy/girl.data.s) is defined here in C --
 * tables holding function pointers must be in the same unit, otherwise IDO's assembler schedules those functions differently.
 * extern views adjusted to the object (address-neutral): D_80800CF0_chboggygirl -> int[] */
u8 D_80800C50_chboggygirl[24] = { 0x0, 0x0, 0x6, 0x1, 0xFF, 0xFF, 0x1, 0x0, 0x0, 0x0, 0x6, 0x1, 0xFF, 0xFE, 0x2, 0x0, 0xFF, 0xFE, 0xDF, 0xFF, 0x12, 0x22, 0x3, 0x0 };
u8 D_80800C68_chboggygirl[136] = { 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x40, 0x13, 0x33, 0x33, 0x2, 0x44, 0x0, 0x1, 0x3F, 0x19, 0x99, 0x9A, 0x2, 0x45, 0x0, 0x1, 0x3F, 0x19, 0x99, 0x9A, 0x2, 0x45, 0x0, 0x1, 0x40, 0x13, 0x33, 0x33, 0x2, 0x44, 0x0, 0x1, 0x3F, 0x19, 0x99, 0x9A, 0x2, 0x45, 0x0, 0x1, 0x3F, 0x19, 0x99, 0x9A, 0x2, 0x45, 0x0, 0x1, 0x3F, 0x19, 0x99, 0x9A, 0x2, 0x45, 0x0, 0x1, 0x40, 0x13, 0x33, 0x33, 0x2, 0x44, 0x0, 0x1, 0x40, 0x13, 0x33, 0x33, 0x2, 0x44, 0x0, 0x1, 0x40, 0x13, 0x33, 0x33, 0x2, 0x44, 0x0, 0x1, 0x40, 0x13, 0x33, 0x33, 0x2, 0x44, 0x0, 0x1, 0x40, 0x13, 0x33, 0x33, 0x2, 0x44, 0x0, 0x1, 0x40, 0x13, 0x33, 0x33, 0x2, 0x44, 0x0, 0x1, 0x3F, 0x4C, 0xCC, 0xCD, 0x0, 0xB7, 0x0, 0x2, 0x40, 0x13, 0x33, 0x33, 0x2, 0x44, 0x0, 0x1, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0 };
int D_80800CF0_chboggygirl[18] = { 0x1930141, 0x75A0002, (u32)&D_80800C68_chboggygirl, (u32)func_808000A8_chboggygirl, (u32)func_8080097C_chboggygirl, (u32)func_80101870, 0x9C40000, 0x3F800000, 0x8D0000, 0x40040128, (u32)func_8080091C_chboggygirl, 0x0, 0x300000, (u32)func_8080000C_chboggygirl, (u32)func_80107C2C, -0x7FEFAFEA, (u32)func_80800508_chboggygirl, 0x0 };
u16 D_80800D38_chboggygirl[8] = { 0x0, 0x0, 0x190, 0x3C, 0x0, 0xE, 0x4000, 0x400 };
u8 D_80800D48_chboggygirl[16] = { 0x43, 0x20, 0x0, 0x0, 0x43, 0xC, 0x0, 0x0, 0x43, 0xC, 0x0, 0x0, 0x42, 0x8C, 0x0, 0x0 };
u8 D_80800D58_chboggygirl[24] = { 0x0, 0x13, 0x4, 0xA4, 0x0, 0xA, 0x1, 0x40, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0 };
