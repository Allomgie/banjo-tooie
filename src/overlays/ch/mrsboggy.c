// Mrs. Boggy in Witchyworld: walks a path, talks, counts her three returned children and then
// gives the Witchyworld Mrs. Boggy jiggy (0x1B).
#include "ch/mrsboggy.h"

extern int D_80800AD8_chmrsboggy[];
extern void func_80105A9C(Actor *, f32);
extern s32 D_80800B30_chmrsboggy[];
extern s32 D_80800A20_chmrsboggy[];
extern s32 _subaddiedialog_entrypoint_8(Actor *, f32[3], void *, void *, s32);
extern s32 _subaddiedialog_entrypoint_9(Actor *, s32, void *, s32);
extern s32 _gcdialogcamera_entrypoint_0(s32, s32);
extern void _capod_entrypoint_3(s32);
extern f32 D_80800A80_chmrsboggy[];
extern void _capod_entrypoint_2();
extern void _gcdialogcamera_entrypoint_3(f32 *, f32);
extern void _gcdialogcamera_entrypoint_4(f32 *);
extern void _gcdialogcamera_entrypoint_5(f32 *);
extern void _capod_entrypoint_6(Unk80132ED0 *, s32, s32);
extern u8 D_80800A58_chmrsboggy[];
extern u8 D_80800B20_chmrsboggy[];
extern void _sudeflect_entrypoint_1(f32 *, f32, f32, f32, s32);
extern void *_suexpression_entrypoint_20();
extern Actor *_subaddiefind_entrypoint_2(s32, void *);
typedef union {
    u32 u;
    s32 s;
} MBArg;
void func_80800790_chmrsboggy();
void func_808007CC_chmrsboggy();
void func_80800878_chmrsboggy();
s32 func_80800990_chmrsboggy();
extern void func_80101870(), func_80102EC0(), func_80107C2C(), func_8080000C_chmrsboggy(),
    func_80800088_chmrsboggy(), func_80800290_chmrsboggy();

int chmrsboggy_entrypoint_0()
{
    return (int) &D_80800AD8_chmrsboggy;
}

void func_8080000C_chmrsboggy(actor) Actor *actor;
{
    if (func_800DA980(0x8C, 3) == 3) {
        if (func_800DA298(0x1CD)) {
            func_800FFAB0(actor);
            return;
        }
        func_800DA524(0x8B);
        func_80102424(actor, 6);
    }
    func_80105A9C(actor, 350.0f);
    func_80105BAC(actor);
}

void func_80800568_chmrsboggy();

// Update.
void func_80800088_chmrsboggy(actor) Actor *actor;
{
    f32 *pos;
    s32 dialog;

    pos = actor->position;
    _sudeflect_entrypoint_1(pos, 200.0f, 0.0f, 100.0f, 10);
    if (_suexpression_entrypoint_20(actor)) {
        _suexpression_entrypoint_10(_suexpression_entrypoint_20(actor), actor->unk0, 0);
    }
    switch (actor->unk70_10) {
        case 1:
            func_80800568_chmrsboggy(actor);
            return;
        case 6:
            dialog = _subaddiedialog_entrypoint_8(actor, pos, D_80800B20_chmrsboggy,
                                                   D_80800A58_chmrsboggy, 5);
            if (dialog &&
                _subaddiedialog_entrypoint_9(actor, dialog, D_80800A58_chmrsboggy, 5) != 3) {
                func_808007CC_chmrsboggy(actor, 3, 0);
            }
            return;
        case 3:
            if (func_80101DDC(actor)) {
                func_80102424(actor, 4);
            }
            break;
        case 5:
            if (func_80101DDC(actor)) {
                func_800F82D4(func_800F54E4(), 0);
                if (func_800DA980(0x8C, 3) == 3) {
                    func_80800910_chmrsboggy(actor, 0x4B, 0x10);
                    _subaddiedialog_entrypoint_11(actor->unk0, 0x109E, 0x4E, pos, 0x3E);
                    func_80102424(actor, 7);
                    return;
                }
                func_80800878_chmrsboggy(actor, 0xE, 0x31,
                                         _subaddiefind_entrypoint_2(0x142, NULL)->unk0);
                func_80102424(actor, 1);
            }
            break;
        case 8:
            func_80105834(actor);
            func_80105230(actor, 0);
            if (func_80105A5C(actor)) {
                func_80800790_chmrsboggy(actor);
                func_800FFAB0(actor);
            }
    }
}

void func_80800290_chmrsboggy(Actor *actor)
{
    func_80800548_chmrsboggy(actor);
}

s32 func_80800738_chmrsboggy();

void func_808005D8_chmrsboggy();

s32 func_808004F4_chmrsboggy();

// Message handler.
int func_808002B0_chmrsboggy(Actor *actor, s32 msg, MBArg arg)
{
    switch (msg) {
        case 0x2E:
            func_808005D8_chmrsboggy(actor, ((s16 *) &arg)[0], ((s16 *) &arg)[1]);
            return 1;
        case 0x30:
            return func_8080070C_chmrsboggy(actor, ((s16 *) &arg)[0], ((s16 *) &arg)[1]);
        case 0x31:
            if (actor->unk70_10 == 2)
                return 0;
            func_800DA544(0x8B);
            func_80102424(actor, 3);
            func_808007CC_chmrsboggy(actor, 3, 1);
            _subaddiedialog_entrypoint_11(actor->unk0, 0x109D, 6, actor->position, 0x3E);
            func_800F82D4(func_800F54E4(), 2);
            return 1;
        case 0x29:
            func_808004F4_chmrsboggy(actor);
            return 1;
        case 0x2A:
            func_80800548_chmrsboggy(actor);
            return 1;
        case 0x52:
            _gcdialogcamera_entrypoint_3(D_80800A80_chmrsboggy, actor->scale);
            return 1;
        case 0x57:
            return func_80800738_chmrsboggy(actor, arg.s & 0xFFFF,
                                            (arg.u & 0xFFFF0000) >> 16);
        case 0x4F:
            func_80800790_chmrsboggy(actor);
            return 1;
        case 0xB8:
            return func_80800990_chmrsboggy() ? 0x109C : 0x109B;
        case 0x95:
            actor->actorData[5] = _glsplinefind_entrypoint_0(0x357, actor->actorData);
            break;
        case 0x23:
            if (func_800DA980(0x8C, 3) == 3) {
                func_800DA524(0x8B);
                func_80102424(actor, 6);
            }
            break;
        default:
            return 0;
    }
    return 1;
}

s32 func_808004F4_chmrsboggy(void *actor)
{
    s32 effect;
    if (_suexpression_entrypoint_20() == 0) {
        effect = _suexpression_entrypoint_7(actor, 1, 0x3E);
        _suexpression_entrypoint_12(effect, 0x42700000, 0x41A00000);
        _suexpression_entrypoint_17(effect, 0x3E8);
    }
}

void func_80800548_chmrsboggy(Actor *actor)
{
    _suexpression_entrypoint_8(actor, 1);
}

void func_80800568_chmrsboggy(Actor *actor)
{
    s32 dialog;

    dialog = _subaddiedialog_entrypoint_8(actor, actor->position, &D_80800B30_chmrsboggy,
                                           &D_80800A20_chmrsboggy, 7);
    if (dialog != 0) {
        if (_subaddiedialog_entrypoint_9(actor, dialog, &D_80800A20_chmrsboggy, 7) != 3) {
            func_808007CC_chmrsboggy(actor, 3, 0);
        }
    }
}

void func_808005D8_chmrsboggy(u8 *actor, s32 dialog_id, s32 unk_2)
{
    s32 result;

    if (dialog_id == 0x109D) {
        func_80102424(_subaddiefind_entrypoint_2(0x142, 0), 0xE);
        func_80102424(actor, 5);
        func_80800878_chmrsboggy(actor, 0x99, 0x30, 0);
        return;
    }
    result = _subaddiedialog_entrypoint_9(actor, dialog_id, (s32 *) D_80800A58_chmrsboggy, 5);
    if ((result != 3) && (result != 0)) {
        func_80102FE8(actor, 0);
        func_80102424(actor, 8);
        _subaddieDll_entrypoint_4(actor, 1);
        func_800D1000(0x1B, 1, actor + 4, 0, 0);
        func_800DA544(0x1CD);
        func_800DA524(0xB8);
        func_800DA524(0xB9);
        func_800DA524(0xBA);
        func_800DA524(0x8B);
        func_80800878_chmrsboggy(actor, 0xE, 0x31, 0);
        return;
    }
    if (*(s32 *) ((s8 *) actor + 0x28) != 0) {
        func_80800790_chmrsboggy(actor);
    }
    func_80102424(actor, 1);
}

int func_8080070C_chmrsboggy(s32 param_0, s32 param_1, s32 param_2)
{
    s32 *arg_ref;
    // Matching: the extra pointer temporary is needed for the match.
    return 3 - func_80800990_chmrsboggy(param_0 ^ 0, *(arg_ref = &param_1));
}

s32 func_80800738_chmrsboggy(s32 actor, s32 unk_1, s32 unk_2)
{
    if (_gcdialogcamera_entrypoint_0(unk_1, unk_2) != 0) {
        if (*(s32 *) (actor + 0x28) != 2) {
            func_808007CC_chmrsboggy(actor, 2, 1);
        }
        return 2;
    }
    return 1;
}

void func_80800790_chmrsboggy(actor) s32 actor;
{

if (*(s32 *) (actor + 0x28) != 0) {
    _capod_entrypoint_3(0);
    *(s32 *) (actor + 0x28) = 0;
}

}

void func_808007CC_chmrsboggy(actor, unk_1, unk_2) Actor *actor;
s32 unk_1;
s32 unk_2;
{
    switch (actor->actorData[4]) {
        case 0:
            _capod_entrypoint_2(actor->unk0, 0x12, 0);
        case 1:
        case 3:
            _capod_entrypoint_8(1);
            actor->actorData[4] = 2;
            _gcdialogcamera_entrypoint_3(D_80800A80_chmrsboggy, actor->scale);
            _gcdialogcamera_entrypoint_4(actor->position);
            _gcdialogcamera_entrypoint_5(actor->rotation);
            _gcdialogcamera_entrypoint_8();
        case 2:
            _capod_entrypoint_7(unk_1, unk_2);
    }

}

void func_80800878_chmrsboggy(actor, unk_1, unk_2, target) Actor *actor;
s32 unk_1;
s32 unk_2;
Unk80132ED0 *target;
{
    if (target == NULL) {
        target = actor->unk0;
    }

switch (actor->actorData[4]) {
    case 0:
        _capod_entrypoint_2(actor->unk0, 18, unk_2);
    case 2:
    case 3:
        actor->actorData[4] = 1;
    case 1:
        _capod_entrypoint_6(target, unk_1, unk_2);
}

}

int func_80800910_chmrsboggy(s32 unk_0[2], s32 unk_1, s32 unk_2)
{
    int index;
    // Matching: index temporary is needed for the match.
    index = 10;

switch (unk_0[index]) {
    case 0:
        _capod_entrypoint_2(unk_0[0], 0x12, unk_2, unk_0);
    case 1:
    case 2:
        unk_0[10] = 1;
    case 3:
        _capod_entrypoint_20(unk_0[0], unk_1, unk_2, unk_0);
}

}

s32 func_80800990_chmrsboggy(void)
{
    func_800DA980(0x8C, 3);
}

s32 D_80800A20_chmrsboggy[14] = {0x1,        0x109A0100, 0x1,      -0xFE00,   0x200,
                                 0x110C0100, 0x200,      -0xFE00,  0x400,     0x110D0100,
                                 0x400,      -0xFE00,    -0x12001, 0x120B0300};
u8 D_80800A58_chmrsboggy[40] = {0x0,  0x0, 0x2,  0x1,  0x10, 0x9E, 0x1,  0x0, 0x0,  0x0,
                                0x2,  0x1, 0x10, 0x9E, 0x2,  0x0,  0x0,  0x0, 0x4,  0x0,
                                0x11, 0xE, 0x1,  0x0,  0x0,  0x0,  0x4,  0x0, 0x11, 0xE,
                                0x2,  0x0, 0xFF, 0xFE, 0xDF, 0xFF, 0x12, 0xB, 0x3,  0x0};
f32 D_80800A80_chmrsboggy[4] = {215.0f, 215.0f, 215.0f, 107.5f};
u8 D_80800A90_chmrsboggy[72] = {
    0x0, 0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x41, 0x20, 0x0,  0x0,  0x0,  0xFF, 0x0,
    0x1, 0x41, 0x20, 0x0,  0x0,  0x0,  0xFF, 0x0,  0x1,  0x3F, 0xA6, 0x66, 0x66, 0x1,  0x2,
    0x0, 0x2,  0x3F, 0xA6, 0x66, 0x66, 0x1,  0x3,  0x0,  0x1,  0x40, 0xA0, 0x0,  0x0,  0x1,
    0x1, 0x0,  0x2,  0x40, 0x6,  0x66, 0x66, 0x3,  0xEE, 0x0,  0x1,  0x40, 0x6,  0x66, 0x66,
    0x3, 0xEE, 0x0,  0x1,  0x3F, 0x4C, 0xCC, 0xCD, 0x1,  0x4,  0x0,  0x1};
int D_80800AD8_chmrsboggy[18] = {0x191013F,
                                 0x6B70001,
                                 (u32) &D_80800A90_chmrsboggy,
                                 (u32) func_80102EC0,
                                 (u32) func_80800088_chmrsboggy,
                                 (u32) func_80101870,
                                 0x5DC0000,
                                 0x3FE00000,
                                 0x0,
                                 0x40040121,
                                 (u32) func_80800290_chmrsboggy,
                                 0x0,
                                 0x0,
                                 (u32) func_8080000C_chmrsboggy,
                                 (u32) func_80107C2C,
                                 -0x7BEF8BEA,
                                 (u32) func_808002B0_chmrsboggy,
                                 0x0};
u8 D_80800B20_chmrsboggy[16] = {0x0, 0x8B, 0x0, 0x0, 0x1, 0x2C, 0x0, 0x3E,
                                0x0, 0x0,  0x0, 0xE, 0x6, 0x3C, 0x7, 0x0};
s32 D_80800B30_chmrsboggy[4] = {0x8B0000, 0x12C003E, 0xE, 0x63C0200};
