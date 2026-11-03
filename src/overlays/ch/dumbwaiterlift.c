#include "common.h"
#include "gc/newoption.h"

extern int D_80800BE8_chdumbwaiterlift[];
typedef struct {
    s16 first;
    s16 second;
} DumbwaiterEvent;
extern Unk80132ED0 *func_80101080(void);
extern s16 D_80800BC2_chdumbwaiterlift[][4];
extern u8 D_80800BC6_chdumbwaiterlift[][8];
extern int func_800F54E4(void);
extern int func_800EA090(void);
extern void func_800EE7F8(f32 *, f32 *);
extern void _subaddieDll_entrypoint_4(Actor *, s32);
extern void func_800F608C(s32, s32);
extern void func_800F8294(s32, f32 *);
extern void func_800F832C(s32, f32 *);
extern void _capod_entrypoint_21(Unk80132ED0 *, s32, s32, s32);
extern void *func_80100094(Actor *, s32);
extern void _gcnewoption_entrypoint_16(void);
extern void _gcnewoption_entrypoint_35(void);
typedef struct {
    s16 local_0;
    u8 pad_0[6];
} LiftMapRecord;
extern void func_800EFA4C(f32 *, f32, f32, f32);
typedef struct {
    s16 local_0;
    s16 local_1;
    s16 local_2;
    s16 local_3;
} DumbwaiterDestination48;
extern DumbwaiterDestination48 D_80800BC0_chdumbwaiterlift[];
extern u8 D_80800C30_chdumbwaiterlift[];
extern u8 D_80800C40_chdumbwaiterlift[];
extern f32 func_800F10B4(f32, f32, f32, f32, f32);
extern void func_800EFE50(f32 *, f32 *, f32 *, f32);
void func_808003C4_chdumbwaiterlift();
void func_80800608_chdumbwaiterlift();
s32 func_808009B8_chdumbwaiterlift();
int func_80800A8C_chdumbwaiterlift();
void func_80800B40_chdumbwaiterlift();
extern void func_80105834(), func_80107C2C();

void func_80800770_chdumbwaiterlift(Actor *param_0);
void func_80800804_chdumbwaiterlift(Actor *param_0);
s32 func_808008B4_chdumbwaiterlift(void);
s32 func_8080094C_chdumbwaiterlift(void);

int chdumbwaiterlift_entrypoint_0()
{
    return &D_80800BE8_chdumbwaiterlift;
}

int func_8080000C_chdumbwaiterlift(param_0)
s32 param_0;
{
    s32 local_0;
    local_0 = param_0 | 0;
    func_800EE7F8(local_0 + 0x28, local_0 + 4);
    func_8010A828(local_0, 2);
}

void func_80800044_chdumbwaiterlift(Actor *param_0)
{
    s32 local_0;
    s32 local_1;
    DumbwaiterDestination48 *local_2;
    s32 local_3;
    local_0 = param_0->unk70_10 == 2 || param_0->unk70_10 == 6;
    if (local_0 || (!local_0 && param_0->unk5F)) {
        _subaddieaudioloop_entrypoint_4(param_0, param_0->position, local_0,
                                        D_80800C30_chdumbwaiterlift);
    }
    switch (param_0->unk70_10) {
        case 1:
            func_80800770_chdumbwaiterlift(param_0);
            return;
        case 2:
            local_1 = func_800D9078(&param_0->unk58);
            func_800EFE50(param_0->position, (f32 *) &param_0->actorData[4],
                          (f32 *) &param_0->actorData[0],
                          func_800F10B4(param_0->unk58, 0.0f, 3.0f, 1.0f, 0.0f));
            if (local_1) {
                _subaddieaudioquick_entrypoint_2(param_0, param_0->position,
                                                 D_80800C40_chdumbwaiterlift);
                func_80101FDC(param_0, 1);
                _subaddieDll_entrypoint_4(param_0, 0);
                _capod_entrypoint_22();
            }
            break;
        case 3:
            func_80800804_chdumbwaiterlift(param_0);
            return;
        case 4:
            _gcnewoption_entrypoint_0(func_80100094(param_0, 0));
            return;
        case 5:
            _gcnewoption_entrypoint_6(param_0, 0);
            func_80101FDC(param_0, 1);
            func_8010A828(param_0, 2);
            return;
        case 6:
            local_3 = func_800D9078(&param_0->unk58);
            func_800EFE50(param_0->position, (f32 *) &param_0->actorData[4],
                          (f32 *) &param_0->actorData[0],
                          func_800F10B4(param_0->unk58, 0.0f, 3.0f, 1.0f, 0.0f));
            if (local_3) {
                func_800DA544(
                    D_80800BC0_chdumbwaiterlift[func_808008B4_chdumbwaiterlift()].local_2);
                _subaddieDll_entrypoint_4(param_0, 0);
                local_2 = &D_80800BC0_chdumbwaiterlift[param_0->unk6C_0];
                _gcgoto_entrypoint_1(local_2->local_0, local_2->local_1);
            }
    }
}

s32 func_80800268_chdumbwaiterlift(param_0)
s32 param_0;
{
    if (((u32) *(u16 *) (param_0 + 0x72) >> 0xA) == 6) {
        func_800C53EC(0, 0);
    }
    if (func_80100094(param_0, 0) != 0) {
        _gcnewoption_entrypoint_6(param_0, 0);
    }
}

s32 func_808002C0_chdumbwaiterlift(Actor *param_0, s32 param_1, DumbwaiterEvent param_2)
{
    switch (param_1) {
        case 0x2E:
            func_80800B40_chdumbwaiterlift(param_0);
            func_80101FDC(param_0, 1);
            break;
        case 0x95:
            func_808003C4_chdumbwaiterlift(param_0);
            break;
        case 0x20:
            func_80800608_chdumbwaiterlift(param_0, func_80101080(), param_2.first, param_2.second);
            break;
        default:
            return 0;
    }
    return 1;
}

void func_8080035C_chdumbwaiterlift(param_0, param_1) u8 *param_0;
s32 param_1;
{
    if (func_800EB854() == 3) {
        if (((unsigned int) (u16) *(u16 *) ((s8 *) param_0 + 0x72) >> 0xA) == 4) {
            _gcnewoption_entrypoint_1(func_80100094(param_0, 0), param_1);
        }
    } else {
        func_80101870(param_0, param_1);
    }
}

void func_808003C4_chdumbwaiterlift(param_0) Actor *param_0;
{
    s32 local_0;
    s32 local_1;
    s32 local_2;
    s32 local_3;
    f32 local_4;

    local_0 = func_800F54E4();
    local_1 = func_800EA090();
    local_2 = func_808008B4_chdumbwaiterlift();
    if (local_1 == D_80800BC2_chdumbwaiterlift[local_2][0]) {
        local_3 = func_8080094C_chdumbwaiterlift();
        func_800EE7F8((f32 *) param_0->actorData, param_0->position);
        if (local_3 < local_2)
            local_4 = -150.0f;
        else
            local_4 = 150.0f;
        param_0->position[1] += local_4;
        func_800EE7F8((f32 *) ((u8 *) param_0 + 0x28), param_0->position);
        param_0->unk58 = 3.0f;
        func_80101FDC(param_0, 2);
        _subaddieDll_entrypoint_4(param_0, 1);
        func_800F608C(local_0, 1);
        func_800F8294(local_0, param_0->position);
        func_800F832C(local_0, param_0->rotation);
        _capod_entrypoint_21(param_0->unk0, 0, D_80800BC6_chdumbwaiterlift[local_2][0], 0x2010);
    }
}

void func_808004E8_chdumbwaiterlift(param_0, param_1) Actor *param_0;
OptionState *param_1;
{
    _gcnewoption_entrypoint_14(param_1, 0, 1, 4, 4.0f);
    _gcnewoption_entrypoint_40(param_1, 0x41, 0x22, 0x20, 0.8f, 1.0f);
    _gcnewoption_entrypoint_32(param_1, 0xA3);
}

void func_80800560_chdumbwaiterlift(s32 param_0)
{
    s32 new_var;
    s32 local_0 = 0;
    u8 *local_3 = (u8 *) D_80800BC0_chdumbwaiterlift;
    s32 local_1 = 0;
    do {
        if (func_800EA05C() != *(s16 *) (local_3 + 0)) {
            new_var = local_0;
            _gcnewoption_entrypoint_12(param_0, new_var, (s16) (local_1 + 0xA));
            _gcnewoption_entrypoint_21(param_0, local_0);
            _gcnewoption_entrypoint_31(param_0, (long) local_0, *(u8 *) (local_3 + 7));
            local_0 += 1;
        }
        local_1 += 1;
        local_3 += 8;
    } while (local_1 != 5);
    if (local_1) {
    }
}

void func_80800608_chdumbwaiterlift(param_0, param_1, param_2, param_3) Actor *param_0;
s32 param_1;
s32 param_2;
s32 param_3;
{
    s32 local_0;
    s32 local_1;
    f32 local_2;

    switch (param_3) {
        case 0:
            func_80800560_chdumbwaiterlift(param_1);
            break;
        case 2:
            func_80800B40_chdumbwaiterlift(param_0);
            func_80101FDC(param_0, 5);
            break;
        case 3:
            local_0 = func_808009B8_chdumbwaiterlift(param_2);
            local_1 = func_808008B4_chdumbwaiterlift();
            param_0->unk6C_0 = local_0;
            func_800EE7F8((u8 *) param_0 + 0x28, param_0->position);
            func_800EE7F8(param_0->actorData, param_0->position);
            local_2 = local_0 < local_1 ? -150.0f : 150.0f;
            *(f32 *) &param_0->actorData[1] += local_2;
            param_0->unk58 = 3.0f;
            func_80101FDC(param_0, 6);
            func_800F8418(func_800F54E4(), param_0->position);
            func_800F8444(func_800F54E4(), (u8 *) param_0 + 0x44);
            func_80800B40_chdumbwaiterlift(param_0);
            _capod_entrypoint_21(param_0->unk0, 0,
                                 ((u8 *) D_80800BC6_chdumbwaiterlift)[local_1 * 8], 0x2010);
            _subaddieDll_entrypoint_4(param_0, 1);
    }
}

void func_80800770_chdumbwaiterlift(Actor *param_0)
{
    if (_subaddiedialog_entrypoint_4(param_0->position, 0x50, 0)) {
        if (!func_80090178(0x40)) {
            _chmrtannoy_entrypoint_0();
            func_80800A8C_chdumbwaiterlift(param_0);
            _subaddiedialog_entrypoint_11(param_0->unk0, 0x133F, 0xF, NULL, 0xA3);
            func_80101FDC(param_0, 7);
        } else
            func_80101FDC(param_0, 3);
    }
}

void func_80800804_chdumbwaiterlift(Actor *param_0)
{
    void *local_0;

    _gcnewoption_entrypoint_4(param_0, 0, _gcnewoption_entrypoint_16, _gcnewoption_entrypoint_35,
                              0x184E);
    local_0 = func_80100094(param_0, 0);
    _gcnewoption_entrypoint_8(local_0, 4);
    _gcnewoption_entrypoint_9(local_0, 4);
    _gcnewoption_entrypoint_10(local_0, 0);
    func_808004E8_chdumbwaiterlift(param_0, local_0);
    _gcnewoption_entrypoint_11(local_0);
    func_80101FDC(param_0, 4);
    func_80800A8C_chdumbwaiterlift(param_0);
    func_8010A828(param_0, 0xA);
}

s32 func_808008B4_chdumbwaiterlift(void)
{
    s32 local_0;
    s32 local_1;
    local_0 = func_800EA05C();
    for (local_1 = 0; local_1 < 5; local_1++) {
        if (local_0 == ((LiftMapRecord *) D_80800BC0_chdumbwaiterlift)[local_1].local_0)
            return local_1;
    }
    return -1;
}

s32 func_8080094C_chdumbwaiterlift(void)
{
    s8 *var_s0;
    s32 var_s1;

    var_s0 = (s8 *) D_80800BC0_chdumbwaiterlift;
    var_s1 = 0;
loop_1:
    if (func_800DA298(*(s16 *) ((s8 *) var_s0 + 4)) != 0) {
        func_800DA524(*(s16 *) ((s8 *) var_s0 + 4));
        return var_s1;
    }
    var_s1 += 1;
    var_s0 += 8;
    if (var_s1 == 5) {
        return -1;
    }
    goto loop_1;
}

s32 func_808009B8_chdumbwaiterlift(param_0)
s32 param_0;
{
    s32 local_0;
    s32 local_1;
    s32 local_2;

    local_0 = func_800EA05C();
    local_2 = 0;
    for (local_1 = 0; local_1 < 5; local_1++) {
        if (local_0 != D_80800BC0_chdumbwaiterlift[local_1].local_0) {
            if (param_0 == local_2)
                return local_1;
            local_2++;
        }
    }
    return -1;
}

int func_80800A8C_chdumbwaiterlift(param_0)
Actor *param_0;
{
    f32 local_0[3];

    if (!param_0->unk64_20) {
        func_800EFA4C(local_0, 0.0f, param_0->rotation[1], 0.0f);
        func_800F8444(func_800F54E4(), local_0);
        _capod_entrypoint_2(param_0->unk0, 0x1B, 0x10);
        _capod_entrypoint_8(1);
        _gcdialogcamera_entrypoint_8();
        _capod_entrypoint_11(1, local_0);
        _capod_entrypoint_7(5, 0);
        _subaddieDll_entrypoint_4(param_0, 1);
        param_0->unk64_20 = 1;
    }
}

void func_80800B40_chdumbwaiterlift(param_0) Actor *param_0;
{
    if (param_0->unk64_20) {
        _capod_entrypoint_3(0);
        _subaddieDll_entrypoint_4(param_0, 0);
        param_0->unk64_20 = 0;
    }
}

DumbwaiterDestination48 D_80800BC0_chdumbwaiterlift[5] = {
    0x101, 0xF,   0xA09, 0x1C8E, 0x106, 0xF,   0xA0A, 0x540, 0x108, 0x9,
    0xA0B, 0x210, 0x10B, 0x9,    0xA0C, 0x304, 0x10E, 0x9,   0xA0D, 0x10C};
int D_80800BE8_chdumbwaiterlift[18] = {0xA603E0,
                                       0x7AB0001,
                                       0x0,
                                       (u32) func_80800044_chdumbwaiterlift,
                                       (u32) func_80105834,
                                       (u32) func_8080035C_chdumbwaiterlift,
                                       0x1F40000,
                                       0x0,
                                       0x0,
                                       0x20000804,
                                       (u32) func_80800268_chdumbwaiterlift,
                                       0x0,
                                       0x0,
                                       (u32) func_8080000C_chdumbwaiterlift,
                                       (u32) func_80107C2C,
                                       -0x7FF7FBEE,
                                       (u32) func_808002C0_chdumbwaiterlift,
                                       0x0};
u8 D_80800C30_chdumbwaiterlift[16] = {0x0, 0x13, 0x5, 0xB9, 0x0, 0x2,  0x0, 0xE,
                                      0x0, 0xF3, 0x1, 0xC,  0x0, 0x19, 0x0, 0x0};
u8 D_80800C40_chdumbwaiterlift[16] = {0x0, 0x13, 0x4, 0xC7, 0x0, 0x18, 0x0, 0x2,
                                      0x0, 0x0,  0x0, 0x0,  0x0, 0x0,  0x0, 0x0};
