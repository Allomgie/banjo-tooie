#include "common.h"

extern int D_808018C0_chfishshootgame[];
extern u8 D_808018B0_chfishshootgame[];
extern void *func_80100094(Actor *, u32);
extern f32 func_800BED50(f32 *);
extern f32 _dbskeleton_entrypoint_1(s32);
extern u8 D_80801910_chfishshootgame[];
extern u8 D_80801934_chfishshootgame[];
extern u8 D_80801908_chfishshootgame[];
extern void func_800BBCB8(f32 *, s32, f32, s32, u8 *);
extern void func_800BABB8(s32, u8 *, s32, f32, void *);
extern void _fxsplash_entrypoint_0();
extern int D_80801978_chfishshootgame[];
extern void func_800C4B64(f32);
extern void func_800EE7F8(f32 *param_0, s32 param_1);
extern s32 func_800DA298(s32);
extern void _subaddiedialog_entrypoint_7(s32, s32, void *);
extern void func_800DFC20(s32 *, s32, f32 *);
extern Actor *func_80108528(s32, f32 *, s32, Actor **);
extern f32 func_800DC178(f32, f32);
extern u8 D_808019A8_chfishshootgame[];
typedef struct {
    u32 pad_0;
    f32 local_0;
    u8 pad_1[8];
    f32 local_1;
    u32 pad_2;
    f32 local_2;
    f32 local_3;
} FishShootBounce;
extern f32 func_800D8FF8(void);
extern Actor *func_80106790();
extern void _gcdialogcamera_entrypoint_3(void *, s32);
extern int D_80801A00_chfishshootgame[];
extern s32 _fxairbub_entrypoint_1(u8 *, f32, s32, f32);
extern void _subaddieaudioquick_entrypoint_2(u8 *, u8 *, void *);
extern void _subaddiefade_entrypoint_3(u8 *);
extern void func_80102424(u8 *, s32);
extern void func_8010A570(u8 *);
extern u8 D_80801A48_chfishshootgame[];
extern u8 D_80801A64_chfishshootgame[];
extern u8 D_80801A6C_chfishshootgame[];
extern u8 D_80801A74_chfishshootgame[];
extern f32 func_800EEAD4(f32 *, f32 *);
extern s32 func_80101E14(Actor *, f32);
extern int D_80801A7C_chfishshootgame[];
extern void func_800CE8D8(s32, f32, s32);
typedef struct {
    u8 pad_0[0x72];
    u16 st : 6;
    u16 rest : 10;
} FishShootState;
typedef struct {
    u8 pad_0[0x30];
    u8 flag30;
    u8 pad31;
    s16 s32;
    s16 s34;
} FishShootRec;
extern u8 D_808019C8_chfishshootgame[];
extern u8 D_808019B8_chfishshootgame[];
extern f32 func_800CEA60(s32);
extern f32 func_80101F24(Actor *);
extern void func_800EFA4C(f32 *, f32, f32, f32);
extern void func_8010C788(f32 *, f32, f32, f32);
extern void func_8008FB10(f32 *, f32, f32, f32);

typedef struct {
    u16 h[10];
    u16 f;
    u16 rest[3];
} FishShootLevel;
int chfishshootgame_entrypoint_0()
{
    return (int) &D_808018C0_chfishshootgame;
}

void func_8080000C_chfishshootgame(Actor *param_0)
{
    u8 *local_1;
    s32 local_2;
    s32 local_0[20];

    local_1 = func_80100094(param_0, 0);
    _susubgame_entrypoint_11(0);
    if (func_800D0A9C(0x21, 1) && !_glcutDll_entrypoint_20()) {
        func_800FFAB0(param_0);
        return;
    }
    func_800EE7F8(local_1, param_0->position);
    *(s16 *) (local_1 + 0x34) = _gccubesearch_entrypoint_9(0x1C0, local_0, 20);
    *(s16 *) (local_1 + 0x32) = -1;
    for (local_2 = 0; local_2 < *(s16 *) (local_1 + 0x34); local_2++) {
        _gspropctrl_entrypoint_10(local_0[local_2], local_1 + 0x36 + local_2 * 6);
    }
    local_0[0] = _gccubesearch_entrypoint_0(0x1C1, param_0);
    _gspropctrl_entrypoint_11(local_0[0], local_1 + 0xC);
    *(f32 *) (local_1 + 0x20) = func_800BED50(param_0->position);
    *(f32 *) (local_1 + 0x28) =
        _dbskeleton_entrypoint_1(func_800B27E0(func_801039E4(param_0->unk0)));
    *(f32 *) (local_1 + 0x2C) = 32000.0f;
    func_80108B04(param_0, 1);
    _susubgame_entrypoint_0(param_0, local_1 + 0xB0, 0);
    _susubgame_entrypoint_12(local_1 + 0xB0, D_808018B0_chfishshootgame);
}

void func_80800178_chfishshootgame(Actor *param_0)
{
    u8 *local_0;
    local_0 = func_80100094(param_0, 0);
    _susubgame_entrypoint_11(0);
    if (func_800FCCD4(0x53)) {
        func_800FCAE0(0x53, 0, 0xFA0);
        func_800FCA90(0x53);
    }
    if (_susubgame_entrypoint_2(param_0, local_0 + 0xB0)) {
        _susubgame_entrypoint_4(param_0, local_0 + 0xB0);
    }
}

void func_808001F0_chfishshootgame(Actor *param_0)
{
    u8 *local_0;
    f32 local_1[3];
    f32 local_2[3];
    s32 local_3;

    local_0 = func_80100094(param_0, 0);
    func_800EE7F8(local_1, param_0->position);
    local_1[1] = *(f32 *) (local_0 + 0x20);
    func_800BBCB8(local_1, 0, 1.0f, 1, D_80801910_chfishshootgame);
    local_3 = func_800B5BE4(1);
    func_800BA4D0(local_3, (s16) local_1[1]);
    func_800BA544(local_3, _fxsplash_entrypoint_0);
    func_800EE7F8(local_2, local_1);
    local_2[1] -= 200.0f;
    func_800BABB8(local_3, local_1, local_2, 1.0f, D_80801934_chfishshootgame);
    _subaddieaudioquick_entrypoint_2(param_0, param_0->position, D_80801908_chfishshootgame);
}

void func_808002E8_chfishshootgame(s32 param_0, f32 param_1)
{
    func_800C4B64(param_1);
    _subaddieaudioquick_entrypoint_2(param_0, param_0 + 4, &D_80801978_chfishshootgame);
}

void func_80800320_chfishshootgame(Actor *param_0)
{
    u8 *local_0;
    f32 local_1[3];
    local_0 = func_80100094(param_0, 0);
    func_800EE7F8(local_1, (u32 *) param_0 + 1);
    local_1[1] -= 100.0f;
    func_800D1000(0x21, 1, (u32 *) param_0 + 1, 4, param_0->unk0);
    _susubgame_entrypoint_6(param_0, local_0 + 0xB0, 0, 0x2090, 0);
}

void func_80800A90_chfishshootgame();

void func_808003B0_chfishshootgame(param_0, param_1) Actor *param_0;
s32 param_1;
{
    extern u8 D_80801984_chfishshootgame[];

    char *local_0;
    s32 local_1;
    s32 local_2;
    f32 local_3[4];
    s32 current_state;
    void *temp;

    local_0 = (char *) func_80100094(param_0, 0);
    local_1 = 0;
    local_2 = 0;
    current_state = (u32) *(u16 *) ((char *) param_0 + 0x72) >> 10;

    if (param_1 == current_state) {
        return;
    }

    switch (param_1) {
        case 13:
            _susubgame_entrypoint_4(param_0, local_0 + 0xB0);

            func_808002E8_chfishshootgame(param_0, 0.8f);

            func_800FFAB0(param_0);

            func_800FFA88(*(void **) ((char *) param_0 + 0x3C));
            return;

        case 2:
            if (current_state != 1) {
                _susubgame_entrypoint_5(param_0, local_0 + 0xB0, 3, 1, 0);
                local_1 = 0xFEF;
            }
            break;

        case 10:
            *(f32 *) (local_0 + 0x18) = 0.0f;
            *(f32 *) (local_0 + 0x1C) = 0.05f;
            *(u8 *) (local_0 + 0x30) = 0;

            func_800DA3B8(0, 0);
            break;

        case 12:
            if (current_state == 4) {
                func_800FC6B0(0x16);
                func_800FCAE0(0x53, 0, 0xFA0);
                func_800FCA90(0x53);
                func_800DA3B8(0, 1);

                local_1 = 0x1024;

                _susubgame_entrypoint_5(param_0, local_0 + 0xB0, 3, 1, 0);

                func_80800A90_chfishshootgame(param_0, local_3);

                local_3[1] -= 60.0f;
                _gcdialogcamera_entrypoint_4(local_3);
            } else {
                local_1 = 0x1023;

                func_808002E8_chfishshootgame(param_0, 1.2f);

                _susubgame_entrypoint_5(param_0, local_0 + 0xB0, 5, 1, 0);
            }
            break;

        case 11:
            _susubgame_entrypoint_6(param_0, local_0 + 0xB0, 0xB, 0x2090, 0);

            func_800DA3B8(0, 1);
            break;

        case 4:
            _susubgame_entrypoint_4(param_0, local_0 + 0xB0);

            *(f32 *) ((char *) param_0 + 0x58) = 0.0f;

            func_800CE8D8(0, 60.0f, 0x3C);

            func_800CE88C(0, 1);
            func_800FC6B0(0x53);
            break;

        case 5:
            func_800CE88C(0, 0);

            _subaddieaudioquick_entrypoint_2(param_0, (char *) param_0 + 4,
                                             D_80801984_chfishshootgame);

            *(u8 *) (local_0 + 0x30) = 1;
            local_2 = 1;
            break;

        case 7:
            local_2 = 1;
            func_808001F0_chfishshootgame(param_0);
            break;

        case 3:
            func_808002E8_chfishshootgame(param_0, 1.0f);
            break;

        case 6:
            *(f32 *) (local_0 + 0x1C) = 0.1f;

            if (*(f32 *) (local_0 + 0x18) < 0.5f) {
                *(f32 *) (local_0 + 0x18) = 1.0f - *(f32 *) (local_0 + 0x18);
            }
            break;

        case 8:
            local_1 = 0xFEE;

            _susubgame_entrypoint_5(param_0, local_0 + 0xB0, 3, 1, 0);
            break;

        case 9:
            *(f32 *) (local_0 + 0x18) = 0.5f;
            *(f32 *) (local_0 + 0x10) = *(f32 *) (local_0 + 4);
            *(f32 *) (local_0 + 4) += 900.0f;
            *(f32 *) (local_0 + 0x1C) = 0.1f;

            _susubgame_entrypoint_6(param_0, local_0 + 0xB0, 4, 0x2090, 0);
    }

    func_80102424(param_0, param_1);

    temp = (void *) func_80106790(*(void **) ((char *) param_0 + 0x3C));

    func_80102424(temp, param_1);

    if (local_1 != 0) {
        if (func_80090270() == 0) {
            _subaddiedialog_entrypoint_11(*(s32 *) ((char *) param_0 + 0x0), local_1, 0xA,
                                          (char *) param_0 + 4, 0x63);
        }
    }

    if (local_2 != 0) {
        func_800DA544(0);
    }
}

void func_8080076C_chfishshootgame(param_0, param_1, param_2) s32 *param_0;
s32 param_1;
s32 param_2;
{
    s32 local_c[1];
    struct {
        s32 b;
    } s;
    s32 local_a[1];
    s32 rec;
    s32 x;
    s32 q[1];

    local_a[0] = 0xE;
    local_c[0] = 0;
    s.b = 0;
    rec = func_80100094(param_0, 0);
    switch (param_1) {
        case 0xFEC:
            s.b = 0x105E;
            local_a[0] = 0x4E;
            x = local_c[0];
            break;
        case 0x105E:
            func_800DA544(0x449);
        case 0xFED:
            s.b = (param_2 == 1) ? 0x1025 : 0x1026;
            x = local_c[0];
            break;
        case 0xFEE:
            func_80800320_chfishshootgame(param_0);
            x = local_c[0];
            break;
        case 0xFEF:
            _susubgame_entrypoint_5(param_0, rec + 0xB0, 5, 1, 0);
            s.b = 0x105F;
            local_a[0] = 0x4E;
            x = local_c[0];
            break;
        case 0x105F:
            if (param_2 == 1) {
                s.b = 0x1025;
            } else {
                s.b = 0x1026;
            }
            local_a[0] = 0xE;
            x = local_c[0];
            break;
        case 0xFF0:
            local_c[0] = 9;
            x = 9;
            break;
        case 0x1023:
            local_c[0] = 4;
            x = 4;
            break;
        case 0x1024:
            local_c[0] = 0xB;
            x = 0xB;
            break;
        case 0x1025:
            if (_susubgame_entrypoint_2(param_0, q[0] = rec + 0xB0) != 0) {
                x = q[0];
                _susubgame_entrypoint_4(param_0, x);
            }
            local_c[0] = 3;
            x = 3;
            break;
        case 0x1026:
            if (_susubgame_entrypoint_2(param_0, q[0] = rec + 0xB0) != 0) {
                x = q[0];
                _susubgame_entrypoint_4(param_0, x);
            }
        case 0x1060:
            x = 1;
            break;
        default:
            x = local_c[0];
    }
    if (x != 0) {
        func_808003B0_chfishshootgame(param_0, x);
    }
    if (s.b != 0) {
        _subaddiedialog_entrypoint_11(*param_0, s.b, local_a[0], param_0 + 1, 0x63);
    }
}

void func_80800D48_chfishshootgame();
int func_80801110_chfishshootgame();
extern void func_80102EC0();
extern void func_80101870();
extern void func_80107C2C();
extern void func_80108ED0();

u32 D_80801840_chfishshootgame[28] = {
    0x0,        0x0,        0x41400000, 0x1700000,  0x41400000, 0x1700000,  0x40955810,
    0x16F0002,  0x40AEB852, 0x16E0000,  0x3F99999A, 0x16D0002,  0x40AEB852, 0x16E0000,
    0x3FA66666, 0x16B0002,  0x40800000, 0x16C0000,  0x40800000, 0x16C0000,  0x40AEB852,
    0x16E0000,  0x40AEB852, 0x16E0000,  0x40AEB852, 0x16E0000,  0x0,        0x0};
u8 D_808018B0_chfishshootgame[16] = {0x43, 0x3E, 0x0, 0x0, 0x43, 0x20, 0x0, 0x0,
                                     0x43, 0x20, 0x0, 0x0, 0x42, 0xC8, 0x0, 0x0};
int D_808018C0_chfishshootgame[18] = {0x15801BE,
                                      0x6D10001,
                                      (u32) &D_80801840_chfishshootgame,
                                      (u32) func_80800D48_chfishshootgame,
                                      (u32) func_80102EC0,
                                      (u32) func_80101870,
                                      0x13880000,
                                      0x40000000,
                                      0x0,
                                      0x100,
                                      (u32) func_80800178_chfishshootgame,
                                      0x0,
                                      0xC80000,
                                      0x0,
                                      (u32) func_80107C2C,
                                      -0x7FFFFBFE,
                                      (u32) func_80801110_chfishshootgame,
                                      0x0};
u8 D_80801908_chfishshootgame[8] = {0x0, 0x13, 0x5, 0x5B, 0x0, 0x1B, 0x0, 0x0};
u8 D_80801910_chfishshootgame[36] = {
    0x0, 0x1D, 0x9, 0xDB, 0x0, 0x16, 0x10, 0x1,  0x0, 0x2A, 0x0, 0x0, 0x0, 0x0, 0x2, 0x0, 0x2, 0x80,
    0x0, 0x15, 0x0, 0x0,  0x0, 0x80, 0x0,  0x22, 0x2, 0x0,  0x2, 0x0, 0x6, 0x0, 0x6, 0x0, 0x0, 0x0};
u8 D_80801934_chfishshootgame[68] = {
    0x0,  0x1D, 0x9,  0xDA, 0x0, 0x20, 0xFF, 0xFF, 0xFE, 0xB4, 0x0, 0x1B, 0xFA, 0xEC,
    0xFA, 0xEC, 0x0,  0x7,  0x0, 0x1,  0x0,  0x15, 0x0,  0x0,  0x0, 0xCC, 0x0,  0x22,
    0x0,  0x5,  0x0,  0xA,  0x0, 0x2,  0x0,  0x2,  0x0,  0x2B, 0x2, 0x0,  0x2,  0x0,
    0x0,  0x16, 0x10, 0x0,  0x0, 0x2D, 0x1,  0x90, 0x2,  0xBC, 0x0, 0xB,  0x0,  0x64,
    0x0,  0x78, 0x0,  0x0,  0x0, 0x0,  0x1E, 0x1A, 0x0,  0x0,  0x0, 0x0};
int D_80801978_chfishshootgame[3] = {0x13055A, 0x1D001B, 0x0};
u8 D_80801984_chfishshootgame[8] = {0x0, 0x13, 0x5, 0x5E, 0x0, 0x1B, 0x0, 0x0};

void func_808009C0_chfishshootgame(s32 param_0)
{
    static FishShootLevel D_8080198C_chfishshootgame = {
        0x449, 0x258, 0xFEC, 0xFED, 0x0, 0x1, 0x1060, 0x0, 0x63, 0x2, 0xA, 0xE28, 0x200, 0x0};
    if (func_800DA298(0x449) != 0) {
        D_8080198C_chfishshootgame.f = D_8080198C_chfishshootgame.f | 0x42;
    } else {
        D_8080198C_chfishshootgame.f = D_8080198C_chfishshootgame.f & 0xFFBF;
    }
    _subaddiedialog_entrypoint_7(param_0, param_0 + 4, &D_8080198C_chfishshootgame);
}

void func_80800A28_chfishshootgame(Actor *param_0)
{
    s32 pad0;
    s32 local_0;
    u8 *local_1;
    f32 local_2[3];

    local_0 = func_8008C27C(func_8008AEDC(func_80104248()));
    local_1 = func_80100094(param_0, 0);
    func_800DFC20((s32 *) local_0, 0x5D, local_2);
    *(f32 *) (local_1 + 0x24) = *(f32 *) (local_1 + 0x28) * local_2[1];
}

void func_80800A90_chfishshootgame(s32 param_0, f32 *param_1)
{
    Actor *local_0;
    local_0 = func_80100094(param_0, 0);
    func_800EE7F8(param_1, param_0 + 4);
    param_1[1] += *(f32 *) ((char *) local_0 + 0x24) + 60.0f;
}

void func_80800AF0_chfishshootgame(void *param_0)
{
    s32 *temp;
    temp = func_80108528(0x1D0, (char *) param_0 + 4, 0, &param_0);
    *(s32 *) ((char *) param_0 + 0x3C) = *temp;
}

void func_80800B30_chfishshootgame(Actor *param_0)
{
    f32 local_0[3];
    Actor *local_1;
    u8 *local_2;

    local_2 = func_80100094(param_0, 0);
    func_800EE88C(local_0, ((s16(*)[3])(local_2 + 0x36))[*(s16 *) (local_2 + 0x32)]);
    local_0[1] = param_0->position[1] + func_800DC178(-200.0f, 0.0f);
    if (local_0[1] < *(f32 *) (local_2 + 0x10)) {
        local_0[1] = *(f32 *) (local_2 + 0x10);
    } else if (*(f32 *) (local_2 + 4) < local_0[1]) {
        local_0[1] = *(f32 *) (local_2 + 4);
    }
    local_1 = func_80108528(0x1BF, local_0, 0, &param_0);
    local_1->unk3C = param_0->unk0;
    local_1->unk58 = *(f32 *) (local_2 + 0x18) * 100.0f + 100.0f;
    local_1->unk50 = *(f32 *) (local_2 + 0x20);
}

int func_80800C24_chfishshootgame(Actor *param_0)
{
    u8(*new_var)[];
    u8 local_0;
    unsigned int local_1;
    local_1 = *(u8 *) ((char *) param_0 + 0x5F);
    if (local_1 == 0) {
        new_var = &D_808019A8_chfishshootgame;
        local_0 = func_800C4350(0, 0, new_var, local_1);
        *(u8 *) ((char *) param_0 + 0x5F) = local_0;
        local_1 = *(u8 *) ((char *) param_0 + 0x5F);
    }
    func_800C4350(local_1 & 0xFF, 0, 0, local_1);
}

void func_80800C78_chfishshootgame(Actor *param_0, s32 param_1, f32 param_2)
{
    FishShootBounce *local_0;
    f32 local_1;
    f32 local_2;
    f32 local_3;

    local_0 = func_80100094(param_0, 0);
    local_0->local_2 += local_0->local_3 * func_800D8FF8();
    local_1 = local_0->local_2;
    if (param_2 < local_1) {
        local_0->local_2 = param_2;
        func_808003B0_chfishshootgame(param_0, param_1);
        local_1 = local_0->local_2;
    }
    if (local_1 > 0.5f)
        local_2 = 1.0f - local_1;
    else
        local_2 = local_1;
    local_3 = local_0->local_0;
    param_0->position[1] = (local_0->local_1 - local_3) * (2.0f * local_2) + local_3;
    func_80800C24_chfishshootgame(param_0);
}

void func_80800D48_chfishshootgame(Actor *param_0)
{
    f32 local_6;
    f32 local_0;
    f32 local_1[3];
    f32 local_2[3];
    FishShootRec *local_3;
    s32 local_4;

    local_3 = func_80100094(param_0, 0);
    local_0 = func_800D8FF8();
    func_80800A28_chfishshootgame(param_0);
    func_80800A90_chfishshootgame(param_0, local_1);
    local_1[1] -= 60.0f;
    func_800EFA4C(local_2, local_1[0] - 1.0f, local_1[1], local_1[2] - 17.0f);
    func_8010C788(local_2, 340.0f, 0.0f, 160.0f);
    local_1[1] += 340.0f;
    func_8008FB10(local_1, 2500.0f, 0.0f, 10.0f);
    switch (((FishShootState *) param_0)->st) {
        case 1:
            func_808009C0_chfishshootgame(param_0);
            break;
        case 4:
            if (func_800CEAD0(0)) {
                func_808003B0_chfishshootgame(param_0, 0xC);
                break;
            }
            param_0->unk58 = param_0->unk58 - local_0;
            if (param_0->unk58 < 0.0f) {
                do {
                    local_4 = func_800DC128(0, local_3->s34);
                } while (local_4 == local_3->s32);
                local_3->s32 = local_4;
                func_80108B04(param_0, 0);
                local_6 = func_800CEA60(0);
                param_0->unk58 = (1.0f - local_6 / 60.0f) * -1.5f + 4.0f;
            }
            break;
        case 5:
            if (func_80101E14(param_0, 0.999f)) {
                func_800FC6B0(0x17);
                func_800FCAE0(0x53, 0, 0xFA0);
                func_800FCA90(0x53);
                func_808003B0_chfishshootgame(param_0, 6);
            }
            break;
        case 6:
        case 11:
            func_80800C78_chfishshootgame(param_0, 7, 1.0f);
            break;
        case 9:
            func_80800C78_chfishshootgame(param_0, 0xD, 1.0f);
        case 8:
            _subaddieaudioquick_entrypoint_4(param_0, param_0->position, D_808019C8_chfishshootgame,
                                             D_808019B8_chfishshootgame);
            break;
        case 3:
            if (func_80101E14(param_0, 0.02f)) {
                func_808001F0_chfishshootgame(param_0);
            }
            if (func_80101E14(param_0, 0.8f)) {
                func_808002E8_chfishshootgame(param_0, 1.1f);
            }
            if (func_80101F24(param_0) > 0.2f && func_80101F24(param_0) < 0.8f) {
                func_80800C24_chfishshootgame(param_0);
            }
            if (func_80101E14(param_0, 0.999f)) {
                func_808003B0_chfishshootgame(param_0, 0xA);
            }
            break;
        case 10:
            func_80800C78_chfishshootgame(param_0, 0xC, 0.5f);
            break;
        case 7:
            if (func_80101F24(param_0) < 0.8f) {
                func_80800C24_chfishshootgame(param_0);
            }
            if (func_80101E14(param_0, 0.9f)) {
                func_808002E8_chfishshootgame(param_0, 1.0f);
            }
            if (func_80101E14(param_0, 0.999f)) {
                func_808003B0_chfishshootgame(param_0, local_3->flag30 ? 2 : 8);
            }
    }
    if (param_0->unk3C) {
        func_800EE7F8(func_80106790(param_0->unk3C)->position, param_0->position);
    }
}

int func_80801110_chfishshootgame(Actor *param_0, s32 param_1, s32 param_2)
{
    u8 *local_0;
    f32 local_1[3];
    f32 *local_2;
    s32 local_3;
    local_0 = func_80100094(*(Actor **) &param_0, 0);
    switch (param_1) {
        case 0x95:
            func_8080000C_chfishshootgame(param_0);
            if (_glcutDll_entrypoint_20())
                func_80102424(param_0, 8);
            break;
        case 0x3D:
            if (param_2) {
                if (param_2 == 1)
                    func_80800AF0_chfishshootgame(param_0);
            } else
                func_80800B30_chfishshootgame(param_0);
            break;
        case 0x2E:
            func_8080076C_chfishshootgame(param_0, ((s16 *) &param_2)[0], ((s16 *) &param_2)[1]);
            break;
        case 0xE:
            if (param_2 == 0) {
                local_2 = func_80100094(param_0, 0);
                local_3 = func_800D0634(0x21, 1);
                if (local_3) {
                    func_800EE7F8(local_1, func_80106790(local_3)->position);
                    if (local_1[1] < local_2[11])
                        local_2[11] = local_1[1];
                    local_1[1] = local_2[11];
                } else
                    func_800EE7F8(local_1, param_0->position);
                _capod_entrypoint_19(local_1);
                return 3;
            }
            func_80800A90_chfishshootgame(param_0, local_1);
            _capod_entrypoint_19(local_1);
            return 3;
        case 0xB:
            if (!param_2) {
                _susubgame_entrypoint_5(param_0, local_0 + 0xB0, 3, 1, 0);
                _subaddiedialog_entrypoint_11(param_0->unk0, 0xFF0, 0xE, param_0->position, 0x63);
                return 4;
            }
            return 3;
        case 0x52:
            _gcdialogcamera_entrypoint_3(D_808018B0_chfishshootgame, *(s32 *) &param_0->scale);
            break;
        case 0x57:
            return _susubgame_entrypoint_3(param_0, local_0 + 0xB0, param_2 & 0xFFFF,
                                           (u32) (param_2 & 0xFFFF0000) >> 16);
        default:
            return 0;
    }
    return 1;
}

int chfishshootgame_entrypoint_1()
{
    return (int) &D_80801A00_chfishshootgame;
}

int func_80801358_chfishshootgame(Actor *param_0)
{
    f32 local_0[2];
    func_80800A90_chfishshootgame(func_80106790(*(s32 *) ((char *) param_0 + 0x3C)),
                                  (f32 *) ((char *) param_0 + 0x18));
    func_800F18FC((f32 *) ((char *) param_0 + 0x4), (f32 *) ((char *) param_0 + 0x18), local_0);
    *(f32 *) ((char *) param_0 + 0x48) = local_0[1];
    *(f32 *) ((char *) param_0 + 0x44) = -local_0[0];
}

void func_808013B8_chfishshootgame(Actor *param_0)
{
    *(f32 *) ((u8 *) param_0 + 0x24) = param_0->unk58 * func_800D8FF8();
    func_8010B990(param_0, 0x100008);
    if (param_0->unk50 < param_0->position[1] + 40.0f) {
        param_0->position[1] = param_0->unk50 - 40.0f;
    }
}

void func_80801424_chfishshootgame(u8 *param_0, s32 param_1)
{
    s32 flag;
    u8 *s0;
    if (1)

        flag = 0;
    if (param_1 == ((Actor *) param_0)->unk70_10) {
        return;
    }
    switch (param_1) {
        case 1:
            s0 = param_0 + 4;
            func_800BABB8(_fxairbub_entrypoint_1(s0, 40.0f, *(s32 *) (param_0 + 0x50), 4.0f), s0, 0,
                          1.0f, D_80801A48_chfishshootgame);
            _subaddieaudioquick_entrypoint_2(param_0, s0, D_80801A64_chfishshootgame);
        case 3:
            break;
        case 4:
            s0 = param_0 + 4;
            func_800BABB8(_fxairbub_entrypoint_1(s0, 30.0f, *(s32 *) (param_0 + 0x50), 4.0f), s0, 0,
                          1.0f, D_80801A48_chfishshootgame);
            _subaddieaudioquick_entrypoint_2(param_0, s0, D_80801A6C_chfishshootgame);
            flag = 1;
            break;
        case 5:
            flag = 1;
            _subaddiefade_entrypoint_3(param_0);
    }
    func_80102424(param_0, param_1);
    if (flag != 0) {
        func_8010A570(param_0);
    }
}

void func_80801568_chfishshootgame(Actor *param_0)
{
    param_0->scale = 0.3f;
    if (param_0->unk58 < 100.0f) {
        param_0->unk58 = func_800DC178(100.0f, 200.0f);
    }
    func_80801358_chfishshootgame(param_0);
    *((u8 *) param_0 + 0x72) &= 0xFF03;
    func_80801424_chfishshootgame(param_0, 1);
}

void func_808015DC_chfishshootgame(Actor *param_0)
{
    f32 local_0;
    switch (param_0->unk70_10) {
        case 1:
            func_80101FDC(param_0, 2);
            return;
        case 2:
            func_80801358_chfishshootgame(param_0);
            func_808013B8_chfishshootgame(param_0);
            if (func_800DA298(0)) {
                func_80801424_chfishshootgame(param_0, 5);
                return;
            }
            if (func_800EEAD4(param_0->position, (f32 *) param_0->actorData) < 100.0f) {
                func_80801424_chfishshootgame(param_0, 3);
            }
            return;
        case 4:
            local_0 = param_0->rotation[0];
            if (param_0->rotation[0] != 0.0f) {
                param_0->rotation[0] = local_0 * 0.75f;
            }
            if (func_80101E14(param_0, 0.999f)) {
                _subaddiefade_entrypoint_3(param_0);
            }
            break;
        case 3:
            if (func_80101E14(param_0, 0.54f)) {
                func_808003B0_chfishshootgame(func_80106790(param_0->unk3C), 5);
                _subaddieaudioquick_entrypoint_2(param_0, param_0->position,
                                                 D_80801A74_chfishshootgame);
                func_8010A570(param_0);
            }
            if (func_80101E14(param_0, 0.999f)) {
                _subaddiefade_entrypoint_3(param_0);
            }
    }
}

s32 func_80801768_chfishshootgame(Actor *this, s32 param_1, s32 param_2)
{
    if (param_1 == 0x40) {
        func_80801424_chfishshootgame(this, 4);
        return 1;
    } else {
        return 0;
    }
}

int *chfishshootgame_entrypoint_2()
{
    return &D_80801A7C_chfishshootgame;
}

u8 D_808019A8_chfishshootgame[16] = {0x2,  0x6,  0x0, 0x13, 0x5, 0x16, 0x0, 0x16,
                                     0x4E, 0x20, 0x0, 0x1B, 0x0, 0x0,  0x0, 0x0};
u8 D_808019B8_chfishshootgame[16] = {0x3E, 0x23, 0xD7, 0xA,  0x3E, 0x8F, 0x5C, 0x29,
                                     0x3E, 0xCC, 0xCC, 0xCD, 0xBF, 0x80, 0x0,  0x0};
u8 D_808019C8_chfishshootgame[8] = {0x0, 0x13, 0x5, 0x5F, 0x0, 0x0, 0x0, 0x0};
u32 D_808019D0_chfishshootgame[12] = {0x0,        0x0,       0x3F800000, 0x1C20000,
                                      0x3F1C28F6, 0x1C20000, 0x3F1C28F6, 0x1C30002,
                                      0x400A3D71, 0x1C40002, 0x3F800000, 0x1C20000};
int D_80801A00_chfishshootgame[18] = {0x1C801BF,
                                      0x6DE0001,
                                      (u32) &D_808019D0_chfishshootgame,
                                      (u32) func_808015DC_chfishshootgame,
                                      (u32) func_80102EC0,
                                      (u32) func_80101870,
                                      0x13880000,
                                      0x40400000,
                                      0x0,
                                      0x10C,
                                      0x0,
                                      (u32) func_80108ED0,
                                      0x0,
                                      (u32) func_80801568_chfishshootgame,
                                      (u32) func_80107C2C,
                                      -0x7FE00000,
                                      (u32) func_80801768_chfishshootgame,
                                      0x0};
u8 D_80801A48_chfishshootgame[28] = {0x0, 0x2C, 0xFF, 0xD8, 0xFF, 0xD8, 0xFF, 0xD8, 0x0, 0x28,
                                     0x0, 0x28, 0x0,  0x28, 0x0,  0x22, 0x0,  0xC,  0x0, 0x17,
                                     0x0, 0xC,  0x0,  0x17, 0x14, 0x1A, 0x0,  0x0};
u8 D_80801A64_chfishshootgame[8] = {0x0, 0x13, 0x5, 0x5D, 0x0, 0x1B, 0x0, 0x0};
u8 D_80801A6C_chfishshootgame[8] = {0x0, 0x13, 0x5, 0x5C, 0x0, 0x1B, 0x0, 0x0};
u8 D_80801A74_chfishshootgame[8] = {0x0, 0x13, 0x4, 0x9C, 0x0, 0x1B, 0x0, 0x0};
int D_80801A7C_chfishshootgame[21] = {0x15801D0,
                                      0x6F30001,
                                      (u32) &D_80801840_chfishshootgame,
                                      (u32) func_80102EC0,
                                      (u32) func_80102EC0,
                                      (u32) func_80101870,
                                      0x13880000,
                                      0x0,
                                      0x0,
                                      0x404,
                                      0x0,
                                      0x0,
                                      0x0,
                                      0x0,
                                      (u32) func_80107C2C,
                                      -0x7FFFFFFE,
                                      0x0,
                                      0x0,
                                      0x0,
                                      0x0,
                                      0x0};
