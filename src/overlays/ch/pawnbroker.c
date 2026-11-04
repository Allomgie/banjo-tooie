#include "common.h"

extern void *D_80800FD0_chpawnbroker;
extern int D_80801018_chpawnbroker[];
extern int D_80801060_chpawnbroker[];
extern void *func_80100094(Actor *, u32);
extern void *_gccubesearch_entrypoint_0(s32, Actor *);
extern f32 func_800EEAD4(f32 *, f32 *);
extern void func_8010A3E8(Actor *, f32);
typedef union {
    s32 word;
    s16 half[2];
} PawnbrokerMessage32;
extern s32 D_80800F60_chpawnbroker[];
extern void _gcdialogcamera_entrypoint_3(void *, f32);
extern void _suexpression_entrypoint_12(s32, f32, f32);
extern s32 D_808010C4_chpawnbroker[];
extern s32 D_808010D8_chpawnbroker[];
extern s32 D_808010F0_chpawnbroker[];
extern s32 D_808010CC_chpawnbroker[];
extern s32 D_808010E4_chpawnbroker[];
extern void _subaddieaudioquick_entrypoint_4(Actor *, f32[3], void *, void *);
extern void _subaddieaudioquick_entrypoint_3(Actor *, f32[3], void *, f32);
extern Actor *func_80106790(Unk80132ED0 *);
extern s32 func_800BBCB8(f32 *, f32 *, f32, s32, s32 *);
extern s32 D_80801100_chpawnbroker[];
extern u8 D_80801134_chpawnbroker[];
extern s32 D_80801144_chpawnbroker[];
extern s32 D_80801154_chpawnbroker[];
extern s32 D_8080114C_chpawnbroker[];
extern f32 D_808010B8_chpawnbroker[];
extern s16 D_808010A8_chpawnbroker[];
extern u8 D_80800ED0_chpawnbroker[];
extern u8 D_80800F08_chpawnbroker[];
extern u8 D_80800F40_chpawnbroker[];
extern void _sudeflect_entrypoint_1(f32 *, f32, f32, f32, s32);
extern s32 func_80102320(Actor *, f32, f32);
void func_808006FC_chpawnbroker();
void func_8080083C_chpawnbroker();
int func_80800A50_chpawnbroker();
int func_80800AA8_chpawnbroker();
void func_80800AE4_chpawnbroker();
int func_80800B88_chpawnbroker();
int func_80800C00_chpawnbroker();
void func_80800CB4_chpawnbroker();
void func_80800E3C_chpawnbroker();
extern void func_80101870(), func_80105834(), func_80107C2C(), func_80800024_chpawnbroker(),
    func_80800514_chpawnbroker();

int chpawnbroker_entrypoint_0()
{
    return &D_80800FD0_chpawnbroker;
}

int *chpawnbroker_entrypoint_1()
{
    return &D_80801018_chpawnbroker;
}

int *chpawnbroker_entrypoint_2()
{
    return &D_80801060_chpawnbroker;
}

s32 func_808007BC_chpawnbroker();

void func_80800694_chpawnbroker();

void func_80800024_chpawnbroker(actor) Actor *actor;
{
    u32 *unk_0;
    s32 pad;
    f32 *position;
    f32 *unk_1;

    unk_0 = func_80100094(actor, 1);
    func_800D1824(0x4E);
    _sudeflect_entrypoint_1(D_808010B8_chpawnbroker, 60.0f, 0.0f, 60.0f, 2);
    position = actor->position;
    _sudeflect_entrypoint_1(position, 250.0f, 0.0f, 100.0f, 10);
    _suexpression_entrypoint_10(unk_0, actor->unk0, 0);
    if (func_801022E4(actor) != 0x115 || !func_80102320(actor, 0.55f, 0.99f)) {
        _suexpression_entrypoint_18(unk_0, 1);
    }
    switch (actor->unk70_10) {
        case 2:
            func_80800694_chpawnbroker(actor);
            if (func_808007BC_chpawnbroker(actor, D_808010A8_chpawnbroker,
                                           (s32) D_80800ED0_chpawnbroker, 7, 0x6A5)) {
                func_80800AE4_chpawnbroker(actor, 3, 0);
            }
            return;
        case 6:
            func_80800694_chpawnbroker(actor);
            if (func_808007BC_chpawnbroker(actor, D_808010A8_chpawnbroker,
                                           (s32) D_80800F08_chpawnbroker, 7, 0x6A6)) {
                func_80800AE4_chpawnbroker(actor, 3, 0);
            }
            break;
        case 5:
            func_80800694_chpawnbroker(actor);
            if (func_808007BC_chpawnbroker(actor, D_808010A8_chpawnbroker,
                                           (s32) D_80800F40_chpawnbroker, 4, 0)) {
                func_80800AE4_chpawnbroker(actor, 5, 1);
            }
            break;
        case 8:
            func_80800694_chpawnbroker(actor);
            if (func_808007BC_chpawnbroker(actor, D_808010A8_chpawnbroker,
                                           (s32) D_80800F40_chpawnbroker, 4, 0)) {
                func_80800AE4_chpawnbroker(actor, 5, 1);
            }
            break;
        case 4:
            func_80800664_chpawnbroker(actor);
            if (func_80101DDC(actor)) {
                func_80102424(actor, 5);
                func_80101180(0x353, 5, 0);
                func_800DA544(0xB4);
            }
            break;
        case 3:
            func_80800694_chpawnbroker(actor);
            func_80103DFC(actor, &unk_1);
            if (_subaddieitem_entrypoint_3(actor, &unk_1, func_80100094(actor, 0))) {
                _subaddiedialog_entrypoint_11(actor->unk0, 0xFE8, 14, position, 0x53);
                func_80102424(actor, 1);
            }
            break;
        case 7:
            func_80800664_chpawnbroker(actor);
            if (func_80101DDC(actor)) {
                func_80102424(actor, 8);
                func_80101180(0x353, 5, 0);
                func_800DA544(0xB5);
            }
            break;
        default:
            func_80800694_chpawnbroker(actor);
    }
}

void func_80800320_chpawnbroker(Actor *actor)
{
    s32 state;
    f32 unk_1[4];
    s32 unk_2;

    func_800EE88C((f32 *) actor->actorData, _gccubesearch_entrypoint_0(0x154, actor));
    if (func_800D0B68(0x27, 1) && func_800D0B68(10, 4)) {
        state = 8;
    } else if (func_800D0B68(0x27, 1)) {
        unk_2 = 1;
        if (_plsu_entrypoint_0(unk_1, (f32 *) actor->actorData) != -1 &&
            func_800EEAD4(unk_1, (f32 *) actor->actorData) < 250.0f) {
            unk_2 = 0;
        }
        if (func_800DA298(0xB5)) {
            if (!func_800D0A9C(10, 4)) {
                func_800D1000(10, 4, (f32 *) actor->actorData, 3, 0);
            }
            state = 8;
        } else if (unk_2) {
            if (!func_800D0A9C(10, 4)) {
                func_800D1000(10, 4, (f32 *) actor->actorData, 3, 0);
            }
            state = 6;
        } else {
            state = 5;
        }
    } else if (func_800DA298(0xB4)) {
        state = 5;
    } else {
        state = 2;
    }
    if (state != 5 && state != 8) {
        func_80108B04(actor, 0x353);
    }
    _subaddieitem_entrypoint_0(func_80100094(actor, 0), 0x4E4, -1, 3);
    _subaddieitem_entrypoint_1(func_80100094(actor, 0), func_800DA298(0xB4) ? 5 : 20);
    func_80101FDC(actor, state);
    func_8010A3E8(actor, 0.8f);
}

void func_80800514_chpawnbroker(Actor *actor)
{
    _suexpression_entrypoint_8(actor, 1);
}

s32 func_80800534_chpawnbroker(Actor *actor, u32 message, PawnbrokerMessage32 data)
{
    s32 unk_0;

    switch (message) {
        case 0x2E:
            func_8080083C_chpawnbroker(actor, data.half[0], data.half[1]);
            break;
        case 0x3D:
            func_808006FC_chpawnbroker(actor, data.word);
            break;
        case 0x52:
            _gcdialogcamera_entrypoint_3(D_80800F60_chpawnbroker, actor->scale);
            break;
        case 0x57:
            return func_80800A50_chpawnbroker(actor, data.word & 0xFFFF,
                                              (u32) (data.word & 0xFFFF0000) >> 16);
        case 0xB:
            func_80800AA8_chpawnbroker(actor);
            return 4;
        case 0x95:
            unk_0 = _suexpression_entrypoint_7(actor, 1, 0x53);
            _suexpression_entrypoint_12(unk_0, 70.0f, 30.0f);
            _suexpression_entrypoint_17(unk_0, 1000);
            func_80108B04(actor, 0x354);
            break;
        default:
            return 0;
    }
    return 1;
}

int func_80800664_chpawnbroker(s32 actor)
{
    s32 position;
    position = actor + 4;
    _subaddieaudioquick_entrypoint_3(actor, position, &D_808010C4_chpawnbroker, 0.52f);
}

void func_80800694_chpawnbroker(Actor *actor)
{
    _subaddieaudioquick_entrypoint_4(actor, actor->position, &D_808010D8_chpawnbroker,
                                     &D_808010F0_chpawnbroker);
    _subaddieaudioquick_entrypoint_3(actor, actor->position, &D_808010CC_chpawnbroker, 0.0f);
    _subaddieaudioquick_entrypoint_3(actor, actor->position, &D_808010E4_chpawnbroker, 0.0f);
}

void func_808006FC_chpawnbroker(actor, actor_id) u8 *actor;
s32 actor_id;
{
    s32 *unk_0;

switch (actor_id) {
    case 0x136:
        func_80108528(actor_id, actor + 0x18, 0xA, &actor);
        return;
    case 0x353:
        func_80108528(actor_id, actor + 0x18, 0, &actor);
        return;
    case 0x354:
        unk_0 = func_801084B0(actor_id, &actor);
        func_80102FDC(unk_0, *(s32 *) ((s8 *) actor + 0x38));
        func_80108944(unk_0, actor);
        *(s32 *) ((s8 *) actor + 0x3C) = (s32) *unk_0;
}

}

s32 func_808007BC_chpawnbroker(Actor *actor, s16 *dialog_state, s32 script, s32 unk_3, s32 dialog_id)
{
    s32 unk_0;
    *dialog_state = dialog_id;
    unk_0 = _subaddiedialog_entrypoint_8(actor, actor->position, dialog_state, script, unk_3);

if (!unk_0) {
    return 0;
}

if (_subaddiedialog_entrypoint_9(actor, unk_0, script, unk_3) != 3) {
    return 1;
}

return 0;
}

void func_8080083C_chpawnbroker(actor, dialog_id, choice) Actor *actor;
s32 dialog_id;
s32 choice;
{
    s32 cheato_dialog;
    s32 jiggy_dialog;
    s32 state;

switch (dialog_id) {
    case 0xFE4:
    case 0xFE6:
    case 0x105B:
        _subaddiedialog_entrypoint_11(actor->unk0, 0xFEA, 0x4E, actor->position, 0x53);
        break;
    case 0xFEA:
        if (func_800DA298(0xB4)) {
            cheato_dialog = func_80800C00_chpawnbroker(5, choice);
            _subaddiedialog_entrypoint_11(actor->unk0, cheato_dialog, 0xE, actor->position, 0x53);
            if (cheato_dialog == 0x1040) {
                actor->unk64_20 = 0;
            }
        } else {
            jiggy_dialog = func_80800C00_chpawnbroker(20, choice);
            _subaddiedialog_entrypoint_11(actor->unk0, jiggy_dialog, 0xE, actor->position, 0x53);
            if (jiggy_dialog == 0x1040) {
                actor->unk64_20 = 1;
            }
        }
        break;
    case 0x1040:
        _subaddieitem_entrypoint_2(func_80100094(actor, 0));
        func_80102424(actor, 3);
        break;
    case 0xFE8:
        func_80102424(actor, actor->unk64_20 ? 4 : 7);
        func_80102424(func_80106790(actor->unk3C), 2);
        func_80800B88_chpawnbroker(actor, 3, 0x30);
        break;
    default:
        if (func_800DA298(0xB5)) {
            state = 8;
        } else if (func_800DA298(0xB4)) {
            if (func_800D0B68(0x27, 1) && func_800D0A9C(10, 4)) {
                state = 6;
            } else {
                state = 5;
            }
        } else {
            state = 2;
        }
        func_80800AA8_chpawnbroker(actor, state);
        func_80102424(actor, state);
}

}

int func_80800A50_chpawnbroker(actor, param_1, param_2)
Actor *actor;
s32 param_1;
s32 param_2;
{
    // Matching: the `| 0` operations are needed for the match.
    if (_gcdialogcamera_entrypoint_0(param_1 | 0, param_2 | 0)) {
        if (*(s32 *) ((char *) actor + 0x28) != 2) {
            func_80800AE4_chpawnbroker(actor, 2, 1);
        }
        return 2;
    }

return 1;
}

int func_80800AA8_chpawnbroker(actor)
Actor *actor;
{
    s32 *dialog_state = (s32 *) ((char *) actor + 0x28);

if (*dialog_state) {
    _capod_entrypoint_3(0, actor);
    *dialog_state = 0;
}

}

void func_80800AE4_chpawnbroker(actor, param_1, param_2) u8 *actor;
s32 param_1;
s32 param_2;
{
    s32 dialog_state;

    dialog_state = (*(s32 *) ((s8 *) actor + 0x28));

switch (dialog_state) {
    case 0:
        _capod_entrypoint_2(*(s32 *) ((s8 *) actor + 0), 0x11, 0);
    case 1:
        _capod_entrypoint_8(1);
        *(s32 *) ((s8 *) actor + 0x28) = 2;
        _gcdialogcamera_entrypoint_3((int *) D_80800F60_chpawnbroker,
                                     *(f32 *) ((s8 *) actor + 0x38));
        _gcdialogcamera_entrypoint_4(actor + 4);
        _gcdialogcamera_entrypoint_5(actor + 0x44);
        _gcdialogcamera_entrypoint_8();
    case 2:
        _capod_entrypoint_7(param_1, param_2);
}

}

int func_80800B88_chpawnbroker(actor, param_1, param_2)
s32 actor[2];
s32 param_1;
s32 param_2;
{
    switch (actor[10]) {
        case 0:
            _capod_entrypoint_2(actor[0], 0x11, param_2, actor);

        case 2:
            actor[10] = 1;

        case 1:
            _capod_entrypoint_6(actor[0], param_1, param_2, actor);
    }

}

// Returns the dialog id for buying at `price` doubloons.
int func_80800C00_chpawnbroker(price, choice)
s32 price;
s32 choice;
{
    if (choice > 0) {
        if (func_800D1A04(0x4E) >= price) {
            if (func_800F64A4(func_800F54E4(), 0x201)) {
                return 0x1040;
            }
            {
                return 0x1225;
            }
        }
        return 0xFE9;
    }

return 0xFE7;
}

void func_80800C70_chpawnbroker(void *actor)
{
    u32 state;

    state = (u32) ((u16) *((u16 *) actor + 0x39)) >> 0xA;

switch (state) {
    case 1:
        func_80800CB4_chpawnbroker();
    case 2:
        return;
}

}

void func_80800CB4_chpawnbroker(actor) u8 *actor;
{
    s32 *item;
    s32 *item_src;

    (*(f32 *) ((s8 *) (actor) + (8))) = (f32) ((*(f32 *) ((s8 *) (actor) + (8))) - 40.0f);

if (func_800D0B68(0x27, 1) == 0) {
    item_src = func_80106790(func_800D0634(0x27, 1));
    goto block_4;
}

if (func_800D0B68(0xA, 4) == 0) {
    item_src = _subaddiefind_entrypoint_0(actor + 4, 0x136, -1, 0);
block_4:
    item = item_src;
}

(*(s32 *) ((s8 *) (actor) + (0x3C))) = (s32) *item;
func_8010A570(item);
func_80102424(actor, 2);

}

int func_80800D5C_chpawnbroker(Actor *actor, s32 message, s32 unk_2)
{
    if (message == 5) {
        func_800BBCB8(actor->position, actor->position, actor->scale, 40,
                      D_80801100_chpawnbroker);
        _subaddieaudioquick_entrypoint_2(actor, actor->position, D_80801134_chpawnbroker);
        func_8010A590(func_80106790(actor->unk3C));
        func_800FFAB0(actor);
        return 1;
    }

return 0;
}

void func_80800DE8_chpawnbroker(u8 *actor)
{
    int target_state;

// Matching: empty block steers IDO's register allocation.
if (actor && actor) {
}

target_state = 2;

if (((((((((((u16) *(u16 *) (actor + 0x72) & 0xFFFFFFFFu) & 0xFFFFFFFFu) & 0xFFFFFFFFu) &
          0xFFFFFFFFu) &
         0xFFFFFFFFu) &
        0xFFFFFFFFu) &
       0xFFFFFFFFu) &
      0xFFFFFFFFu) >>
     0xA) == target_state) {
    func_80800E3C_chpawnbroker();
    if (func_80101DDC(actor) != 0) {
        func_80102424(actor, 1);
    }
}

}

void func_80800E34_chpawnbroker(s32 actor)
{
}
void func_80800E3C_chpawnbroker(actor) Actor *actor;
{
    _subaddieaudioquick_entrypoint_4(actor, actor->position, &D_80801144_chpawnbroker,
                                     &D_80801154_chpawnbroker);
    _subaddieaudioquick_entrypoint_3(actor, actor->position, &D_8080114C_chpawnbroker, 0.5f);
    _subaddieaudioquick_entrypoint_3(actor, actor->position, &D_8080114C_chpawnbroker, 0.87f);
}

u8 D_80800ED0_chpawnbroker[56] = {
    0x0, 0x0,  0x0, 0x1,  0xF, 0xE3, 0x1,  0x0,  0x0,  0x0,  0x0,  0x1, 0xF, 0xE4,
    0x2, 0x0,  0x0, 0x0,  0x2, 0x0,  0x10, 0x57, 0x1,  0x0,  0x0,  0x0, 0x2, 0x0,
    0xF, 0xE4, 0x2, 0x0,  0x0, 0x0,  0x4,  0x0,  0x10, 0x58, 0x1,  0x0, 0x0, 0x0,
    0x4, 0x0,  0xF, 0xE4, 0x2, 0x0,  0xFF, 0xFE, 0xDF, 0xFF, 0x12, 0xB, 0x3, 0x0};
u8 D_80800F08_chpawnbroker[56] = {
    0x0,  0x0,  0x0, 0x1,  0xF, 0xE5, 0x1,  0x0,  0x0,  0x0,  0x0,  0x1, 0xF, 0xE6,
    0x2,  0x0,  0x0, 0x0,  0x2, 0x0,  0x10, 0x59, 0x1,  0x0,  0x0,  0x0, 0x2, 0x0,
    0x10, 0x5B, 0x2, 0x0,  0x0, 0x0,  0x4,  0x0,  0x10, 0x5A, 0x1,  0x0, 0x0, 0x0,
    0x4,  0x0,  0xF, 0xE6, 0x2, 0x0,  0xFF, 0xFE, 0xDF, 0xFF, 0x12, 0xB, 0x3, 0x0};
u8 D_80800F40_chpawnbroker[32] = {0x0, 0x0,  0x0,  0x1,  0xF,  0xEB, 0x2,  0x0, 0x0, 0x0,  0x2,
                                  0x0, 0x10, 0x5C, 0x2,  0x0,  0x0,  0x0,  0x4, 0x0, 0x10, 0x5D,
                                  0x2, 0x0,  0xFF, 0xFE, 0xDF, 0xFF, 0x12, 0xB, 0x3, 0x0};
s32 D_80800F60_chpawnbroker[4] = {0x437A0000, 0x43160000, 0x43160000, 0x43160000};
u8 D_80800F70_chpawnbroker[72] = {
    0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x40, 0xFB, 0x33, 0x33, 0x1,  0x15, 0x0,
    0x1,  0x40, 0xFB, 0x33, 0x33, 0x1,  0x15, 0x0,  0x1,  0x40, 0xFB, 0x33, 0x33, 0x1,  0x15,
    0x0,  0x1,  0x41, 0xD,  0x47, 0xAE, 0x1,  0x17, 0x0,  0x2,  0x40, 0xFB, 0x33, 0x33, 0x1,
    0x15, 0x0,  0x1,  0x40, 0xFB, 0x33, 0x33, 0x1,  0x15, 0x0,  0x1,  0x41, 0xD,  0x47, 0xAE,
    0x1,  0x17, 0x0,  0x2,  0x40, 0xFB, 0x33, 0x33, 0x1,  0x15, 0x0,  0x1};
u32 D_80800FB8_chpawnbroker[6] = {0x0, 0x0, 0x410D47AE, 0x1180044, 0x410D47AE, 0x1180002};
void *D_80800FD0_chpawnbroker = (void *) 0x02B40352;
static u32 D_80800FD0_chpawnbroker_rest[17] = {0x6C30002,
                                               (u32) &D_80800F70_chpawnbroker,
                                               (u32) func_80800024_chpawnbroker,
                                               (u32) func_80105834,
                                               (u32) func_80101870,
                                               0x0,
                                               0x3FB33333,
                                               0x0,
                                               0x120,
                                               (u32) func_80800514_chpawnbroker,
                                               0x0,
                                               0x140000,
                                               (u32) func_80800320_chpawnbroker,
                                               (u32) func_80107C2C,
                                               0x82002482,
                                               (u32) func_80800534_chpawnbroker,
                                               0x0};
int D_80801018_chpawnbroker[18] = {0x2B50353,
                                   0x7570001,
                                   0x0,
                                   (u32) func_80800C70_chpawnbroker,
                                   (u32) func_80105834,
                                   (u32) func_80101870,
                                   0x0,
                                   0x0,
                                   0x0,
                                   0x20804,
                                   0x0,
                                   0x0,
                                   0x0,
                                   (u32) func_80800CB4_chpawnbroker,
                                   (u32) func_80107C2C,
                                   -0x7FFFDB7E,
                                   (u32) func_80800D5C_chpawnbroker,
                                   0x0};
int D_80801060_chpawnbroker[18] = {0x2B60354,
                                   0x6C40001,
                                   (u32) &D_80800FB8_chpawnbroker,
                                   (u32) func_80800DE8_chpawnbroker,
                                   (u32) func_80105834,
                                   (u32) func_80101870,
                                   0x0,
                                   0x0,
                                   0x0,
                                   0x804,
                                   0x0,
                                   0x0,
                                   0x0,
                                   (u32) func_80800E34_chpawnbroker,
                                   (u32) func_80107C2C,
                                   -0x7FFFDFFE,
                                   0x0,
                                   0x0};
s16 D_808010A8_chpawnbroker[8] = {0x0, 0x0, 0x1E0, 0x53, 0x0, 0xC, 0x2632, 0x100};
f32 D_808010B8_chpawnbroker[3] = {461.0f, 95.0f, -1e+02f};
s32 D_808010C4_chpawnbroker[2] = {0x130532, 0x0};
s32 D_808010CC_chpawnbroker[3] = {0x130533, 0xD0140, 0x1590000};
s32 D_808010D8_chpawnbroker[3] = {0x130564, 0xD00F3, 0x10C0000};
s32 D_808010E4_chpawnbroker[3] = {0x130565, 0xD00F3, 0x10C0000};
s32 D_808010F0_chpawnbroker[4] = {0x3E3851EC, 0x3E8F5C29, 0x3EB851EC, -0x40800000};
s32 D_80801100_chpawnbroker[13] = {0x1D0758,   0x14002B, 0xCC0133,  0x2D01F4, 0x258001B,
                                   -0x3E70320, 0x220133, 0x1660099, 0xCC001E, 0x1E0028,
                                   0xE0032,    0x3C0005, 0x0};
u8 D_80801134_chpawnbroker[16] = {0x0, 0x13, 0x4, 0x8D, 0x0, 0x18, 0x0, 0x1,
                                  0x4, 0xE2, 0x9, 0xC4, 0x0, 0x0,  0x0, 0x0};
s32 D_80801144_chpawnbroker[2] = {0x130520, 0x0};
s32 D_8080114C_chpawnbroker[2] = {0x130521, 0x0};
s32 D_80801154_chpawnbroker[3] = {0x3E6B851F, 0x3EA3D70A, -0x40800000};
