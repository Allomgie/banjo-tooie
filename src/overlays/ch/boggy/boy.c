#include "common.h"
extern u8 D_80800C00_chboggyboy[];

extern int D_80800CB8_chboggyboy[];
typedef struct { u8 pad_0[8]; u8 route[12]; s16 timer; u8 pad_1 : 1; u8 active : 1; u8 pad_2 : 6; } BoggyBoyState;
extern void *func_80100094(Actor *, u32);
typedef union { s32 word; s16 half[2]; } BoggyBoyMessage32;
typedef struct { u8 pad_0[0x14]; s16 local_0; u8 pad_1 : 1; u8 local_1 : 1; u8 local_2 : 1; u8 pad_2 : 5; } BoggyBoyFlags109;
extern void func_80102924(Actor *, f32);
extern void func_80102424(Actor *, s32);
typedef struct { u8 pad_0[0x14]; u32 pad_1 : 16; u32 timed : 1; u32 pad_4 : 1; u32 active : 1; u32 pad_2 : 13; f32 pad_3[2]; f32 timer; } BoggyBoyUpdate;
extern s32 func_800D9154(f32 *, f32);
extern u8 D_80800C18_chboggyboy[];
extern void _sudeflect_entrypoint_0(f32 *, f32, f32, s32);
typedef struct { u8 pad_0[0x14]; u32 pad_1 : 16; u32 local_0 : 1; u32 local_1 : 1; u32 pad_2 : 14; } BoggyBoyDialogFlags;
extern f32 func_800DC178(f32, f32);
extern f32 func_801028C4(void *, f32 *, f32, f32, f32);
extern f32 func_80102D78(void *, f32 *);
extern void func_80102BF8(void *, f32, f32, f32);
extern s32 func_80102CF4(void *, f32);
extern void _subaddierouteDll_entrypoint_6(void *, void *, s32, s32, f32, s32, s32);
extern void _subaddierouteDll_entrypoint_7(void *, void *, f32, f32, f32, s32);
extern s32 _subaddierouteDll_entrypoint_4(void *);
extern s32 func_8010B990(void *, s32);
extern void func_801058C4(void *, s32, f32, s32);
extern s32 func_800F0064(void *, f32, f32 *);
void typedef struct { u8 pad[0x16]; s16 b15 : 1; s16 r : 15; } BoyBits16;
typedef struct { u8 pad[0x14]; u32 hi : 17; u32 b14 : 1; u32 lo : 14; } BoyBits14;
extern s32 D_80800D10_chboggyboy[];
extern s32 D_80800D20_chboggyboy[];
extern void func_800C9C70(f32, s32, f32, s32, f32 *, f32, f32);
typedef union { s32 local_0; struct { s16 local_0; s16 local_1; } local_1; } BoggyBoyMessage36;
int func_8080082C_chboggyboy();
void func_808009F4_chboggyboy();
s32 func_80800AD0_chboggyboy();
s32 func_80800570_chboggyboy(Actor *param_0, s32 param_1, BoggyBoyMessage36 param_2);
extern void func_80101870(), func_80107C2C(), func_80108ED0(), func_8080000C_chboggyboy(), func_8080086C_chboggyboy();
extern u8 D_80800C30_chboggyboy[];

int chboggyboy_entrypoint_0()
{
    return (int)&D_80800CB8_chboggyboy;
}

void func_8080000C_chboggyboy(param_0) Actor *param_0;
{
    BoggyBoyState *local_0;
    local_0 = func_80100094(param_0, 0);
    if (!_chboggykids_entrypoint_0(param_0)) {
        func_800FFAB0(param_0);
        return;
    }
    *(f32 *)&param_0->actorData[3] = 300.0f;
    if (!func_800DA298(0xB8)) func_8010A570(param_0);
    else local_0->active = 1;
    _subaddieDll_entrypoint_1(param_0);
    _subaddierouteDll_entrypoint_3(param_0, local_0->route, param_0->position);
    local_0->timer = 0;
    func_8080082C_chboggyboy(param_0);
}

func_808000B8_chboggyboy(Actor *param_0)
{
    extern u16 D_80800D00_chboggyboy[];
    extern u8 D_80800C00_chboggyboy[];
    extern u8 D_80800C18_chboggyboy[];
    extern u8 D_80800C24_chboggyboy[];

    char *local_0;
    s32 local_3;
    f32 local_2[3];
    f32 local_4[3];
    char *local_1;

    local_0 = (char *)func_80100094(param_0, 0);
    local_3 = func_800D90A4((char *)param_0 + 0x58);

    local_1 = (char *)func_80100094(param_0, 1);
    if (local_1 != 0) {
        local_1 = (char *)func_80100094(param_0, 1);
        _suexpression_entrypoint_10(
            local_1,
            *(s32 *)((char *)param_0 + 0),
            0
        );
    }


    switch (((u32) (*(u16 *)((char *)param_0 + 0x72)) >> 10)) {
        case 1:
            if (!_subaddiedialog_entrypoint_8(
                    param_0,
                    (char *)param_0 + 4,
                    D_80800D00_chboggyboy,
                    D_80800C00_chboggyboy,
                    3) &&
                func_800DA298(D_80800D00_chboggyboy[0]) &&
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
                D_80800D00_chboggyboy,
                D_80800C00_chboggyboy,
                3
            );
            break;

        case 2:
            func_80105230(param_0, 0);

            if (!_subaddiedialog_entrypoint_8(
                    param_0,
                    (char *)param_0 + 4,
                    D_80800D00_chboggyboy,
                    D_80800C00_chboggyboy,
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

        case 14:
            _subaddiefx_entrypoint_0(
                param_0,
                -1,
                local_0 + 0x18
            );

            if (func_80101DDC(param_0)) {
                _subaddiefx_entrypoint_1(
                    param_0,
                    local_0 + 0x18
                );

                func_80102424(param_0, 4);
            }
            break;
    }

    if (((BoyBits14 *)local_0)->b14) {
        if (func_801022E4(param_0) == 0x243) {
            if (func_800D9154(local_0 + 0x20, 3.0f)) {
                _subaddieaudioquick_entrypoint_2(
                    param_0,
                    (char *)param_0 + 4,
                    D_80800C24_chboggyboy
                );
            }
        }
    } else if (((BoyBits16 *)local_0)->b15) {
        if (func_800D9154(local_0 + 0x20, 2.5f)) {
            _subaddieaudioquick_entrypoint_2(
                param_0,
                (char *)param_0 + 4,
                D_80800C18_chboggyboy
            );
        }
    }

    _sudeflect_entrypoint_0(
        (f32 *)((char *)param_0 + 4),
        100.0f,
        50.0f,
        10
    );
}

s32 func_80800A64_chboggyboy();

void func_80800978_chboggyboy();

void func_808006C4_chboggyboy();

s32 func_80800570_chboggyboy(Actor *param_0, s32 param_1, BoggyBoyMessage36 param_2)
{
    f32 *local_0;

    switch (param_1) {
        case 0x2E:
            func_808006C4_chboggyboy(param_0, param_2.local_1.local_0, param_2.local_1.local_1);
            break;
        case 0x40:
            func_80800978_chboggyboy(param_0, param_2.local_0);
            break;
        case 0x95:
            _subaddierouteDll_entrypoint_1(param_0);
            break;
        case 0x29:
            func_80800A64_chboggyboy(param_0);
            break;
        case 0x52:
            _gcdialogcamera_entrypoint_3(&D_80800D10_chboggyboy, *(s32 *)&param_0->scale);
            break;
        case 0x2D:
            local_0 = param_0->position;
            _subaddieaudioquick_entrypoint_2(param_0, local_0, &D_80800D20_chboggyboy);
            func_800C9C70(1.0f, 0x525, 1.05f, 22000, local_0, 200.0f, 3000.0f);
            break;
        case 0x30:
            return 3 - func_800DA980(0x8C, 3);
        case 0x2A:
            func_80800AD0_chboggyboy(param_0);
            break;
        default:
            return 0;
    }
    return 1;
}

void func_808006C4_chboggyboy(Actor *param_0, s32 param_1, BoggyBoyMessage32 param_2)
{
    u8 *local_0;

    local_0 = func_80100094(param_0, 0);
    switch (param_1) {
        case 0x108A:
            func_800DA544(0x8C);
            func_80101180(0x13F, 0x23, 0);
            func_80102424(param_0, 5);
            _subaddieDll_entrypoint_4(param_0, 1);
            func_808009F4_chboggyboy(param_0);
            break;
        case 0x1098:
        case 0x1099:
            ((BoggyBoyFlags109 *)local_0)->local_2 = 0;
            break;
        default:
            switch (_subaddiedialog_entrypoint_9(param_0, param_1, D_80800C00_chboggyboy, 3)) {
                case 1:
                    func_8010A590(param_0);
                    ((BoggyBoyFlags109 *)local_0)->local_1 = 1;
                case 2:
                    func_80102924(param_0, param_0->rotation[1] + 180.0f);
                    func_80102424(param_0, 3);
                    ((BoggyBoyFlags109 *)local_0)->local_0 = 0;
                    break;
                default:
                    func_80102424(param_0, 1);
                    break;
            }
            break;
    }
}

s32 func_808007F4_chboggyboy(param_0) s32 param_0; {
    s32 local_0;

    local_0 = func_80100094(param_0, 0);
    _subaddiefx_entrypoint_1(param_0, local_0 + 0x18);
    func_80800AD0_chboggyboy(param_0);
}

int func_8080082C_chboggyboy(param_0) s32 param_0;
{
  u8 *local_0;
  s8 _sfpad[8];
  s16 local_1[2];
  local_0 = func_80100094(param_0, 0);
  *(s16 *)((char *)local_0 + 6) = _glsplinefind_entrypoint_0(0x3A1, local_1);
  func_800EE940(local_0, local_1);
}

void func_8080086C_chboggyboy(param_0) Actor *param_0;
{
    BoggyBoyUpdate *local_0;
    local_0 = func_80100094(param_0, 0);
    if (local_0->timed) {
        if (func_800D9154(&local_0->timer, 1.6f)) {
            _subaddieaudioquick_entrypoint_2(param_0, param_0->position, D_80800C18_chboggyboy);
        }
    }
    if (param_0->unk70_10 == 0x10) {
        if (!local_0->active) func_800FFAB0(param_0);
    } else {
        func_80105834(param_0);
        _sudeflect_entrypoint_0(param_0->position, 100.0f, 50.0f, 10);
        func_80105230(param_0, 0);
        if (func_80105A5C(param_0)) {
            if (local_0->active) {
                func_80102424(param_0, 0x10);
                param_0->unk64_16 = 0;
            } else {
                func_800FFAB0(param_0);
            }
        }
    }
}

void func_80800978_chboggyboy(Actor *param_0, s32 param_1)
{
    BoggyBoyDialogFlags *local_0;

    local_0 = func_80100094(param_0, 0);
    _subaddiedialog_entrypoint_11(param_0->unk0, 0x108A, 0xE, param_0->position, 0x3B);
    func_80102424(param_0, 0xE);
    func_8010A570(param_0);
    local_0->local_0 = 1;
    local_0->local_1 = 0;
}

void func_808009F4_chboggyboy(param_0) Actor *param_0;
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
  _subaddiedialog_entrypoint_11(*((s32 *) (((char *) new_var) + 0x0)), var_a1, 0xF, (u32 *)new_var + 1, 0x3B);
  temp_v0 = func_80100094(new_var, 0);
  *((u8 *) (((char *) temp_v0) + 0x16)) = ((*((u8 *) (((char *) temp_v0) + 0x16))) & 0xFF) | 0x20;
}

s32 func_80800A64_chboggyboy(Actor *this){
    if(!func_80100094(this, 1)){
        _suexpression_entrypoint_7(this, 1, 0x3B);
        _suexpression_entrypoint_12(func_80100094(this, 1), 0x42700000, 0x41A00000);
        _suexpression_entrypoint_17(func_80100094(this, 1), 0x3E8);
    }
}

s32 func_80800AD0_chboggyboy(this) Actor *this;{
    if(func_80100094(this, 1) != 0){
        _suexpression_entrypoint_8(this, 1);
    }
}

/* TU-NOTE: the .data of this overlay (formerly asm/data/overlays/ch/boggy/boy.data.s) is defined here in C --
 * tables holding function pointers must be in the same unit, otherwise IDO's assembler schedules those functions differently.
 * extern views adjusted to the object (address-neutral): D_80800CB8_chboggyboy -> int[], D_80800D10_chboggyboy -> s32[], D_80800D20_chboggyboy -> s32[] */
u8 D_80800C00_chboggyboy[24] = { 0x0, 0x0, 0x6, 0x1, 0x10, 0x88, 0x1, 0x0, 0x0, 0x0, 0x6, 0x1, 0x10, 0x89, 0x2, 0x0, 0xFF, 0xFE, 0xDF, 0xFF, 0x12, 0x22, 0x3, 0x0 };
u8 D_80800C18_chboggyboy[12] = { 0x0, 0x13, 0x5, 0x24, 0x0, 0xA, 0x0, 0xCC, 0x0, 0x0, 0x0, 0x0 };
u8 D_80800C24_chboggyboy[12] = { 0x0, 0x13, 0x5, 0x25, 0x0, 0xD, 0x0, 0xF3, 0x1, 0xC, 0x0, 0x0 };
u8 D_80800C30_chboggyboy[136] = { 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x40, 0x89, 0x99, 0x9A, 0x2, 0x42, 0x0, 0x1, 0x3F, 0x26, 0x66, 0x66, 0x2, 0x43, 0x0, 0x1, 0x3F, 0x26, 0x66, 0x66, 0x2, 0x43, 0x0, 0x1, 0x40, 0x89, 0x99, 0x9A, 0x2, 0x42, 0x0, 0x1, 0x3F, 0x26, 0x66, 0x66, 0x2, 0x43, 0x0, 0x1, 0x3F, 0x26, 0x66, 0x66, 0x2, 0x43, 0x0, 0x1, 0x3F, 0x26, 0x66, 0x66, 0x2, 0x43, 0x0, 0x1, 0x40, 0x89, 0x99, 0x9A, 0x2, 0x42, 0x0, 0x1, 0x40, 0x89, 0x99, 0x9A, 0x2, 0x42, 0x0, 0x1, 0x40, 0x89, 0x99, 0x9A, 0x2, 0x42, 0x0, 0x1, 0x40, 0x89, 0x99, 0x9A, 0x2, 0x42, 0x0, 0x1, 0x40, 0x89, 0x99, 0x9A, 0x2, 0x42, 0x0, 0x1, 0x40, 0x89, 0x99, 0x9A, 0x2, 0x42, 0x0, 0x1, 0x3F, 0x4C, 0xCC, 0xCD, 0x0, 0xB7, 0x0, 0x2, 0x40, 0x89, 0x99, 0x9A, 0x2, 0x42, 0x0, 0x1, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0 };
int D_80800CB8_chboggyboy[18] = { 0x1920140, 0x7590001, (u32)&D_80800C30_chboggyboy, (u32)func_808000B8_chboggyboy, (u32)func_8080086C_chboggyboy, (u32)func_80101870, 0x9C40000, 0x3F800000, 0x8C0000, 0x40040120, (u32)func_808007F4_chboggyboy, (u32)func_80108ED0, 0x240000, (u32)func_8080000C_chboggyboy, (u32)func_80107C2C, -0x7FEFAFEC, (u32)func_80800570_chboggyboy, 0x0 };
u16 D_80800D00_chboggyboy[8] = { 0xB8, 0x0, 0x190, 0x3B, 0x0, 0xE, 0x0, 0x400 };
s32 D_80800D10_chboggyboy[4] = { 0x43200000, 0x430C0000, 0x430C0000, 0x428C0000 };
s32 D_80800D20_chboggyboy[4] = { 0x1304A4, 0xA0140, 0x0, 0x0 };
