#include "common.h"

#define RF(i) (*(f32 *) &local_1[i])
extern int D_80800EB4_chseaweedbaddy[];
extern int D_80800EFC_chseaweedbaddy[];
extern void _sudeflect_entrypoint_1(u8 *, f32, f32, f32, s32);
typedef union {
    s32 local_0;
    Actor *local_1;
} SeaweedMessage27;
typedef struct {
    s16 a, b;
} S16Pair;
typedef struct {
    u8 pad[0x72];
    u16 f72 : 6;
    u16 rest72 : 10;
    u8 pad74[4];
    u32 pad78 : 29;
    u32 flag : 1;
    u32 rest78 : 2;
} BanditState;
typedef struct {
    u8 pad_0[0x64];
    u32 pad_64_30 : 2;
    u32 flag_64_29 : 1;
    u32 pad_64_0 : 29;
} PlantActorFlags;
extern s32 _subaddierouteDll_entrypoint_4(Actor *);
extern s32 func_8010C9FC(void *, s32, s32, s32);
extern s32 func_8010C668(Actor *, void *, f32, f32);
extern void *_suchase_entrypoint_0(void);
extern s32 func_801072A8(Actor *);
extern s32 D_80800F5C_chseaweedbaddy[];
extern s32 D_80800F90_chseaweedbaddy[];
extern s32 D_80800F9C_chseaweedbaddy[];
typedef struct {
    u8 pad[0x64];
    u32 a : 2;
    u32 f : 1;
    u32 rest : 29;
} WeedC;
typedef struct {
    u8 pad[0x78];
    u32 hi : 29;
    u32 b2 : 1;
    u32 lo : 2;
} WeedB;
typedef struct {
    u8 pad_0[0x72];
    u16 st : 6;
    u16 rest : 10;
} WeedState;
extern u8 D_80800F44_chseaweedbaddy[];
extern u8 D_80800F50_chseaweedbaddy[];
extern f32 func_800D8FF8(void);
extern f32 func_800F15F8(f32, f32, f32);
extern f32 func_800F1FF0(f32, f32, f32, f32, f32);
extern f32 func_800136E4(f32);
extern f32 func_80102D78(Actor *, u32 *);
extern f32 func_800EEB40(f32 *, f32 *);
extern f32 _subaddiejoy_entrypoint_9(Actor *, f32 *, s32);
extern void func_800EEB9C(f32 *, f32, f32);
extern void _subaddierouteDll_entrypoint_7(Actor *, void *, f32, f32, f32, s32);
extern void _subaddieaudioquick_entrypoint_3();
typedef struct {
    f32 local_0[3];
    s32 pad_0;
    s32 local_1;
    u8 local_2[4];
} SeaweedRouteState;
extern s32 func_800DC298(f32);
extern void func_800EE7F8(f32 *, f32 *);
extern void func_80102FDC(Actor *, f32);
extern f32 func_800DC0C0(void);
extern void func_80101EE4(Actor *, f32);
extern f32 func_8010CD28(Actor *);
extern s32 _subaddiefind_entrypoint_5(s32, Actor **, s32, f32 *, f32, f32 (*)(f32 *, f32 *));
extern f32 mlAbsF(f32);
extern s32 func_800DC128(s32, s32);
extern void func_80103014(Actor *);
extern f32 D_80800FAC_chseaweedbaddy[2];
extern f32 D_80800FB4_chseaweedbaddy[];
extern f32 func_80013728(f32);
extern void func_800C4B64(f32);
extern f32 func_800F10B4(f32, f32, f32, f32, f32);
extern void _subaddieaudioquick_entrypoint_2(Actor *, f32 *, f32 *);
void func_808007E4_chseaweedbaddy();
void func_80800BCC_chseaweedbaddy();
void func_80800710_chseaweedbaddy();
void func_808009BC_chseaweedbaddy();
void func_80800CE0_chseaweedbaddy(Actor *param_0, f32 param_1);
extern void func_80105834(), func_80107C2C(), func_80108ED0(), func_80800498_chseaweedbaddy();

int *chseaweedbaddy_entrypoint_0()
{
    return &D_80800EB4_chseaweedbaddy;
}

void *chseaweedbaddy_entrypoint_1()
{
    return &D_80800EFC_chseaweedbaddy;
}

s32 func_80800910_chseaweedbaddy();

s32 func_8080082C_chseaweedbaddy();

void func_80800018_chseaweedbaddy(Actor *param_0)
{
    f32 local_2;
    f32 local_0;
    s32 *local_1;
    f32 speed;
    s32 fill1;
    u32 *local_4;
    f32 local_3;
    local_0 = 0.0f;
    local_1 = func_80100094(param_0, 1);
    if (((WeedB *) param_0)->b2) {
        return;
    }
    local_2 = func_800D8FF8();
    func_800D9078(&param_0->unk58);
    switch (((WeedState *) param_0)->st) {
        case 1:
            if (func_8080082C_chseaweedbaddy(param_0)) {
                func_80800710_chseaweedbaddy(param_0, 2);
            }
            break;
        case 2:
            local_0 = 700.0f;
            _subaddieaudioquick_entrypoint_3(param_0, param_0->position, D_80800F44_chseaweedbaddy,
                                             0x3E4CCCCD);
            if (func_80101DDC(param_0)) {
                func_80800710_chseaweedbaddy(param_0, 3);
            }
            break;
        case 3:
            local_0 = 700.0f;
            func_8010D254(param_0->actorData);
            if (((WeedC *) param_0)->f) {
                speed = _subaddiejoy_entrypoint_9(param_0, &param_0->unk54, 3) * 350.0f;
                RF(3) = param_0->unk54;
                func_800EEB9C((f32 *) &param_0->actorData[4], RF(3), speed);
                func_8010B990(param_0, 0x205027);
            } else {
                if (_subaddierouteDll_entrypoint_4(param_0)) {
                    local_3 = func_80102D78(param_0, param_0->actorData);
                    param_0->unk54 = local_3;
                    _subaddierouteDll_entrypoint_7(param_0, local_4 = &local_1[5], RF(3), local_3,
                                                   100.0f, 0x5000);
                    local_1[4] = ((u16 *) local_4)[3];
                }
                RF(3) = func_800F1FF0(RF(3), param_0->unk54, 0.2f, 2.0f, func_800D8FF8() * 450.0f);
                func_800EEB9C((f32 *) &param_0->actorData[4], RF(3), 350.0f);
                func_8010B990(param_0, 0x5307);
            }
            if (func_80800910_chseaweedbaddy(param_0)) {
                func_80800710_chseaweedbaddy(param_0, 6);
            }
            break;
        case 4:
            if (func_80101DDC(param_0)) {
                func_80800710_chseaweedbaddy(param_0, 5);
            }
            break;
        case 5:
            _subaddieaudioquick_entrypoint_3(param_0, param_0->position, D_80800F50_chseaweedbaddy,
                                             0x3E4CCCCD);
            if (func_80101DDC(param_0)) {
                func_80800710_chseaweedbaddy(param_0, 6);
            }
            break;
        case 6:
            local_0 = 300.0f;
            if (_subaddierouteDll_entrypoint_4(param_0)) {
                local_3 = func_80102D78(param_0, param_0->actorData);
                param_0->unk54 = local_3;
                _subaddierouteDll_entrypoint_7(param_0, local_4 = &local_1[5], RF(3), local_3,
                                               100.0f, 0x5000);
                local_1[4] = ((u16 *) local_4)[3];
            }
            local_4 = param_0->actorData;
            RF(3) = func_800F1FF0(RF(3), param_0->unk54, 0.2f, 2.0f, func_800D8FF8() * 450.0f);
            func_800EEB9C((f32 *) &param_0->actorData[4], RF(3), 350.0f);
            func_8010B990(param_0, 0x5307);
            if (func_800EEB40(param_0->position, local_4) < 6.4e+03f) {
                func_80800710_chseaweedbaddy(param_0, 7);
            } else if (func_8080082C_chseaweedbaddy(param_0)) {
                func_80800710_chseaweedbaddy(param_0, 3);
            }
            break;
        case 7:
            if (func_80101DDC(param_0)) {
                func_80800710_chseaweedbaddy(param_0, 1);
            }
    }
    local_3 = param_0->rotation[1];
    param_0->unk50 = func_800F15F8(param_0->unk50, local_0, local_2 * 800.0f);
    param_0->rotation[1] = func_800136E4(param_0->rotation[1] + param_0->unk50 * local_2);
    func_80800CE0_chseaweedbaddy(param_0, local_3);
}

void func_8080043C_chseaweedbaddy(u8 *param_0)
{
    _sudeflect_entrypoint_1(param_0 + 4, *(f32 *) (param_0 + 0x38) * 120.0f,
                            *(f32 *) (param_0 + 0x38) * 100.0f, 0.0f, 0xA);
}

void func_80800498_chseaweedbaddy(param_0) Actor *param_0;
{
    SeaweedRouteState *local_0;
    if (func_800DC298(0.4f))
        func_808009BC_chseaweedbaddy(param_0);
    _subaddieDll_entrypoint_1(param_0);
    func_80107200(param_0);
    local_0 = func_80100094(param_0, 1);
    _subaddierouteDll_entrypoint_3(param_0, local_0->local_2, param_0->position);
    local_0->local_1 = 0;
    func_800EE7F8(local_0->local_0, param_0->position);
    func_80102FDC(param_0, param_0->scale * 0.7f);
    param_0->unk50 = 0.0f;
    func_80101EE4(param_0, func_800DC0C0());
}

s32 func_80800554_chseaweedbaddy(Actor *param_0, s32 param_1, SeaweedMessage27 param_2)
{
    switch (param_1) {
        case 0x3F:
            func_808007E4_chseaweedbaddy(param_0, param_2.local_1);
            return 1;
        case 0x40:
            _chexploder_entrypoint_3(param_0, param_0->position, 4);
            return 1;
        case 0x90:
            func_80800BCC_chseaweedbaddy(param_0);
            return 1;
        case 0x95:
            _subaddierouteDll_entrypoint_1(param_0);
            return 1;
        case 0x8F:
            if (!param_2.local_0) {
                func_80800710_chseaweedbaddy(param_0, 1);
            }
            break;
        case 2:
            if (!_subaddieDll_entrypoint_3(param_0)) {
                if (!func_80107070(param_0, 1)) {
                    _subaddiefade_entrypoint_3(param_0);
                }
            } else {
                func_80800710_chseaweedbaddy(param_0, 6);
            }
            break;
        default:
            return 0;
    }
    return 1;
}

void func_8080065C_chseaweedbaddy(u8 *param_0)
{
    func_80102FDC(param_0, *(f32 *) (param_0 + 0x38) * 0.7f);
    func_80101EE4(param_0, func_800DC0C0());
}

s32 func_808006A8_chseaweedbaddy(param_0, param_1)
s32 param_0;
s32 param_1;
{
    func_800DF744(1, 0);
    func_800DF744(2, 0);
    func_800DF744(3, 1);
    func_800DF744(4, 0);
    func_800DF744(5, 1);
    func_80101870(param_0, param_1);
}

void func_80800710_chseaweedbaddy(param_0, param_1) Actor *param_0;
s32 param_1;
{
    f32 *local_0;

    local_0 = func_80100094(param_0, 1);

switch (param_1) {
    case 1:
        _subaddieDll_entrypoint_4(param_0, 0);
        break;
    case 2:
        _subaddieDll_entrypoint_4(param_0, 1);
        break;
    case 3:
        func_8010D254(param_0->actorData, local_0);
        local_0[3] = func_8010CD28(param_0);
        break;
    case 6:
        func_800EE7F8(param_0->actorData, local_0);
        param_0->unk58 = 1.4f;
        break;
    case 7:
        param_0->unk58 = 1.4f;
}

func_80102424(param_0, param_1);

}

void func_808007E4_chseaweedbaddy(BanditState *param_0, S16Pair param_1)
{
    if (!param_0->flag && param_0->f72 != 4) {
        func_80800710_chseaweedbaddy(param_0, 4);
    }

}

s32 func_8080082C_chseaweedbaddy(Actor *param_0)
{
    if (param_0->unk58 > 0.0f) {
        return 0;
    }

if (((PlantActorFlags *) param_0)->flag_64_29) {
    return 1;
}

if (func_801072A8(param_0)) {
    return 0;
}

if (!_subaddierouteDll_entrypoint_4(param_0)) {
    return 0;
}

if (!func_8010C9FC(param_0->position, 1000, 500, -50)) {
    return 0;
}

if (!func_8010C668(param_0, param_0->position, 1000.0f, -200.0f)) {
    return 0;
}

return _suchase_entrypoint_0() == param_0->unk0;

}

s32 func_80800910_chseaweedbaddy(Actor *param_0)
{
    if (((PlantActorFlags *) param_0)->flag_64_29) {
        return 0;
    }

if (!_subaddierouteDll_entrypoint_4(param_0)) {
    return 0;
}

if (!func_8010C9FC(param_0->position, 1000, 500, -50)) {
    return 1;
}

if (!func_8010C668(param_0, param_0->position, 1000.0f, -200.0f)) {
    return 1;
}

return _suchase_entrypoint_0() != param_0->unk0;
}

void func_808009BC_chseaweedbaddy(Actor *this)
{
    Actor *list[8];
    Actor *other;
    s32 pad;
    f32 tmp[3];
    s32 i;
    s32 n;
    f32 t;

    n = _subaddiefind_entrypoint_5(0x35D, list, 8, this->position, 3500.0f, func_800EEB40);
    i = 0;

while (i < n) {
    if (800.0f < mlAbsF(list[i]->position[1] - this->position[1])) {
        list[i] = list[--n];
    } else {
        i++;
    }
}

if (n == 0) {
    return;
}

other = list[func_800DC128(0, n)];
func_800EE7F8(tmp, this->position);
func_800EE7F8(this->position, other->position);
func_800EE7F8(other->position, tmp);
t = this->rotation[1];
this->rotation[1] = other->rotation[1];
other->rotation[1] = t;
t = this->unk74_7;
this->unk74_7 = other->unk74_7;
other->unk74_7 = t;
func_80103014(other);
}

void func_80800BCC_chseaweedbaddy(param_0) u8 *param_0;
{
    s32 local_1;
    f32 local_0[3];

    local_1 = func_80106790(func_80101080());
    _chexploder_entrypoint_9(local_1, 1, 0);
    _chexploder_entrypoint_9(local_1, 2, 0);
    _chexploder_entrypoint_9(local_1, 3, 0);
    _chexploder_entrypoint_9(local_1, 4, 1);
    _chexploder_entrypoint_9(local_1, 5, 0);
    _chexploder_entrypoint_10(local_1, &D_80800F9C_chseaweedbaddy);
    _chexploder_entrypoint_6(local_1, 0x43FA0000, 0x44160000);
    _chexploder_entrypoint_14(local_1, 3);
    func_80103DFC(param_0, local_0);
    func_800BBCB8(local_0, local_0, (*(s32 *) ((s8 *) (param_0) + (0x38))), 4,
                  &D_80800F5C_chseaweedbaddy);
    _subaddieaudioquick_entrypoint_2(param_0, param_0 + 4, &D_80800F90_chseaweedbaddy);

if (func_80107070(param_0, 3) == 0) {
    func_800FFAB0(param_0);
}

}

void func_80800CE0_chseaweedbaddy(Actor *param_0, f32 param_1)
{
    s32 i;
    s32 local_0;

    local_0 = 0;
    for (i = 0; i < 2; i++) {

if (func_80013728(param_1) <= D_80800FAC_chseaweedbaddy[i] &&
    D_80800FAC_chseaweedbaddy[i] < func_80013728(*(f32 *) ((u8 *) param_0 + 0x48))) {
    local_0 = 1;
    break;
}

}
if (local_0 && *(f32 *) ((u8 *) param_0 + 0x50) > 100.0f) {
    func_800C4B64(func_800F10B4(*(f32 *) ((u8 *) param_0 + 0x50), 100.0f, 700.0f, 1.0f, 1.15f));
    _subaddieaudioquick_entrypoint_2(param_0, param_0->position, &D_80800FB4_chseaweedbaddy);
}
}

u8 D_80800E40_chseaweedbaddy[20] = {0x0, 0x1, 0x0, 0x0, 0x0, 0x9, 0x0, 0x0, 0x0, 0x9,
                                    0x0, 0x0, 0x0, 0x8, 0x0, 0x0, 0x0, 0xA, 0x0, 0x0};
u8 D_80800E54_chseaweedbaddy[96] = {
    0x0,  0x0,  0x0,  0x0,  0x0, 0x0,  0x0, 0x0, 0x3F, 0x40, 0x0,  0x0,  0x1, 0xD3, 0x0, 0x1,
    0x3F, 0x59, 0x99, 0x9A, 0x1, 0x77, 0x0, 0xA, 0x3F, 0x0,  0x0,  0x0,  0x1, 0x74, 0x0, 0x1,
    0x3F, 0x59, 0x99, 0x9A, 0x1, 0x76, 0x0, 0x2, 0x3F, 0xD7, 0xA,  0x3D, 0x1, 0x75, 0x0, 0x2,
    0x3F, 0x0,  0x0,  0x0,  0x1, 0x74, 0x0, 0x1, 0x3F, 0x59, 0x99, 0x9A, 0x1, 0x77, 0x0, 0x12,
    0x0,  0x0,  0x0,  0x0,  0x0, 0x0,  0x0, 0x0, 0x3F, 0x40, 0x0,  0x0,  0x1, 0xD3, 0x4, 0x1,
    0x3F, 0x40, 0x0,  0x0,  0x1, 0xD3, 0x0, 0x9, 0x3F, 0x40, 0x0,  0x0,  0x1, 0xD3, 0x0, 0x1};
int D_80800EB4_chseaweedbaddy[18] = {0x2EF035C,
                                     0x6CE0001,
                                     (u32) &D_80800E54_chseaweedbaddy,
                                     (u32) func_80800018_chseaweedbaddy,
                                     (u32) func_80105834,
                                     (u32) func_808006A8_chseaweedbaddy,
                                     0xBB80000,
                                     0x3FC00000,
                                     0x0,
                                     0x3050228,
                                     0x0,
                                     (u32) func_80108ED0,
                                     0x20,
                                     (u32) func_80800498_chseaweedbaddy,
                                     (u32) func_80107C2C,
                                     -0x7FDFBBE3,
                                     (u32) func_80800554_chseaweedbaddy,
                                     (u32) &D_80800E40_chseaweedbaddy};
int D_80800EFC_chseaweedbaddy[18] = {0x2F0035D,
                                     0x6CF000B,
                                     (u32) &D_80800E54_chseaweedbaddy,
                                     (u32) func_8080043C_chseaweedbaddy,
                                     (u32) func_80105834,
                                     (u32) func_808006A8_chseaweedbaddy,
                                     0x3200000,
                                     0x3FC00000,
                                     0x0,
                                     0x8,
                                     0x0,
                                     0x0,
                                     0x0,
                                     (u32) func_8080065C_chseaweedbaddy,
                                     (u32) func_80107C2C,
                                     -0x7FFFDBFE,
                                     0x0,
                                     0x0};
u8 D_80800F44_chseaweedbaddy[12] = {0x0, 0x13, 0x4, 0xFF, 0x0, 0xD, 0x1, 0xF3, 0x2, 0x0, 0x0, 0x0};
u8 D_80800F50_chseaweedbaddy[12] = {0x0, 0x13, 0x4, 0x9D, 0x0, 0xD, 0x1, 0x66, 0x1, 0x80, 0x0, 0x0};
s32 D_80800F5C_chseaweedbaddy[13] = {0x1D09DD, 0x2201CC, 0x2000133,  0x1660015, 0x99,
                                     0x190000, 0x7002D,  0x32003C,   0x2B0199,  0x1CC000E,
                                     0x3C0050, 0x2080FF, -0x7F420000};
s32 D_80800F90_chseaweedbaddy[3] = {0x1304FE, 0xD01F3, 0x2000000};
s32 D_80800F9C_chseaweedbaddy[4] = {0x510053, 0x540055, 0x560057, 0x58FFFF};
f32 D_80800FAC_chseaweedbaddy[2] = {-9e+01f, 9e+01f};
f32 D_80800FB4_chseaweedbaddy[3] = {1.746308e-39f, 2.66323e-39f, 0.0f};
