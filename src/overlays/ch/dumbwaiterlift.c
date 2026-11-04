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
    s16 map;
    u8 pad_2[6];
} LiftMapRecord;
extern void func_800EFA4C(f32 *, f32, f32, f32);
typedef struct {
    s16 map;
    s16 entrance;
    s16 flag;
    s16 unk_6;
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

int func_8080000C_chdumbwaiterlift(actor_addr)
s32 actor_addr;
{
    s32 actor;
    actor = actor_addr | 0; // Matching: `| 0` is needed for the match.
    func_800EE7F8(actor + 0x28, actor + 4);
    func_8010A828(actor, 2);
}

void func_80800044_chdumbwaiterlift(Actor *actor)
{
    s32 is_moving;
    s32 arrive_done;
    DumbwaiterDestination48 *dest;
    s32 depart_done;
    is_moving = actor->unk70_10 == 2 || actor->unk70_10 == 6;
    if (is_moving || (!is_moving && actor->unk5F)) {
        _subaddieaudioloop_entrypoint_4(actor, actor->position, is_moving,
                                        D_80800C30_chdumbwaiterlift);
    }
    switch (actor->unk70_10) {
        case 1:
            func_80800770_chdumbwaiterlift(actor);
            return;
        case 2:
            arrive_done = func_800D9078(&actor->unk58);
            func_800EFE50(actor->position, (f32 *) &actor->actorData[4],
                          (f32 *) &actor->actorData[0],
                          func_800F10B4(actor->unk58, 0.0f, 3.0f, 1.0f, 0.0f));
            if (arrive_done) {
                _subaddieaudioquick_entrypoint_2(actor, actor->position,
                                                 D_80800C40_chdumbwaiterlift);
                func_80101FDC(actor, 1);
                _subaddieDll_entrypoint_4(actor, 0);
                _capod_entrypoint_22();
            }
            break;
        case 3:
            func_80800804_chdumbwaiterlift(actor);
            return;
        case 4:
            _gcnewoption_entrypoint_0(func_80100094(actor, 0));
            return;
        case 5:
            _gcnewoption_entrypoint_6(actor, 0);
            func_80101FDC(actor, 1);
            func_8010A828(actor, 2);
            return;
        case 6:
            depart_done = func_800D9078(&actor->unk58);
            func_800EFE50(actor->position, (f32 *) &actor->actorData[4],
                          (f32 *) &actor->actorData[0],
                          func_800F10B4(actor->unk58, 0.0f, 3.0f, 1.0f, 0.0f));
            if (depart_done) {
                func_800DA544(
                    D_80800BC0_chdumbwaiterlift[func_808008B4_chdumbwaiterlift()].flag);
                _subaddieDll_entrypoint_4(actor, 0);
                dest = &D_80800BC0_chdumbwaiterlift[actor->unk6C_0];
                _gcgoto_entrypoint_1(dest->map, dest->entrance);
            }
    }
}

s32 func_80800268_chdumbwaiterlift(actor)
s32 actor;
{
    if (((u32) *(u16 *) (actor + 0x72) >> 0xA) == 6) {
        func_800C53EC(0, 0);
    }
    if (func_80100094(actor, 0) != 0) {
        _gcnewoption_entrypoint_6(actor, 0);
    }
}

s32 func_808002C0_chdumbwaiterlift(Actor *actor, s32 msg, DumbwaiterEvent args)
{
    switch (msg) {
        case 0x2E:
            func_80800B40_chdumbwaiterlift(actor);
            func_80101FDC(actor, 1);
            break;
        case 0x95:
            func_808003C4_chdumbwaiterlift(actor);
            break;
        case 0x20:
            func_80800608_chdumbwaiterlift(actor, func_80101080(), args.first, args.second);
            break;
        default:
            return 0;
    }
    return 1;
}

void func_8080035C_chdumbwaiterlift(actor, arg) u8 *actor;
s32 arg;
{
    if (func_800EB854() == 3) {
        if (((unsigned int) (u16) *(u16 *) ((s8 *) actor + 0x72) >> 0xA) == 4) {
            _gcnewoption_entrypoint_1(func_80100094(actor, 0), arg);
        }
    } else {
        func_80101870(actor, arg);
    }
}

void func_808003C4_chdumbwaiterlift(actor) Actor *actor;
{
    s32 player;
    s32 entrance;
    s32 cur_floor;
    s32 dest_floor;
    f32 offset_y;

    player = func_800F54E4();
    entrance = func_800EA090();
    cur_floor = func_808008B4_chdumbwaiterlift();
    if (entrance == D_80800BC2_chdumbwaiterlift[cur_floor][0]) {
        dest_floor = func_8080094C_chdumbwaiterlift();
        func_800EE7F8((f32 *) actor->actorData, actor->position);
        if (dest_floor < cur_floor)
            offset_y = -150.0f;
        else
            offset_y = 150.0f;
        actor->position[1] += offset_y;
        func_800EE7F8((f32 *) ((u8 *) actor + 0x28), actor->position);
        actor->unk58 = 3.0f;
        func_80101FDC(actor, 2);
        _subaddieDll_entrypoint_4(actor, 1);
        func_800F608C(player, 1);
        func_800F8294(player, actor->position);
        func_800F832C(player, actor->rotation);
        _capod_entrypoint_21(actor->unk0, 0, D_80800BC6_chdumbwaiterlift[cur_floor][0], 0x2010);
    }
}

void func_808004E8_chdumbwaiterlift(actor, options) Actor *actor;
OptionState *options;
{
    _gcnewoption_entrypoint_14(options, 0, 1, 4, 4.0f);
    _gcnewoption_entrypoint_40(options, 0x41, 0x22, 0x20, 0.8f, 1.0f);
    _gcnewoption_entrypoint_32(options, 0xA3);
}

void func_80800560_chdumbwaiterlift(s32 menu)
{
    s32 slot;
    s32 item = 0;
    u8 *row = (u8 *) D_80800BC0_chdumbwaiterlift;
    s32 floor = 0;
    do {
        if (func_800EA05C() != *(s16 *) (row + 0)) {
            slot = item;
            _gcnewoption_entrypoint_12(menu, slot, (s16) (floor + 0xA));
            _gcnewoption_entrypoint_21(menu, item);
            _gcnewoption_entrypoint_31(menu, (long) item, *(u8 *) (row + 7));
            item += 1;
        }
        floor += 1;
        row += 8;
    } while (floor != 5);
    // Matching: empty block steers IDO's register allocation.
    if (floor) {
    }
}

void func_80800608_chdumbwaiterlift(actor, menu, selection, event) Actor *actor;
s32 menu;
s32 selection;
s32 event;
{
    s32 dest_floor;
    s32 cur_floor;
    f32 offset_y;

    switch (event) {
        case 0:
            func_80800560_chdumbwaiterlift(menu);
            break;
        case 2:
            func_80800B40_chdumbwaiterlift(actor);
            func_80101FDC(actor, 5);
            break;
        case 3:
            dest_floor = func_808009B8_chdumbwaiterlift(selection);
            cur_floor = func_808008B4_chdumbwaiterlift();
            actor->unk6C_0 = dest_floor;
            func_800EE7F8((u8 *) actor + 0x28, actor->position);
            func_800EE7F8(actor->actorData, actor->position);
            offset_y = dest_floor < cur_floor ? -150.0f : 150.0f;
            *(f32 *) &actor->actorData[1] += offset_y;
            actor->unk58 = 3.0f;
            func_80101FDC(actor, 6);
            func_800F8418(func_800F54E4(), actor->position);
            func_800F8444(func_800F54E4(), (u8 *) actor + 0x44);
            func_80800B40_chdumbwaiterlift(actor);
            _capod_entrypoint_21(actor->unk0, 0,
                                 ((u8 *) D_80800BC6_chdumbwaiterlift)[cur_floor * 8], 0x2010);
            _subaddieDll_entrypoint_4(actor, 1);
    }
}

// Only the washing machine may use the lift; otherwise Mr. Tannoy refuses.
void func_80800770_chdumbwaiterlift(Actor *actor)
{
    if (_subaddiedialog_entrypoint_4(actor->position, 0x50, 0)) {
        if (!func_80090178(0x40)) {
            _chmrtannoy_entrypoint_0();
            func_80800A8C_chdumbwaiterlift(actor);
            _subaddiedialog_entrypoint_11(actor->unk0, 0x133F, 0xF, NULL, 0xA3);
            func_80101FDC(actor, 7);
        } else
            func_80101FDC(actor, 3);
    }
}

void func_80800804_chdumbwaiterlift(Actor *actor)
{
    void *menu;

    _gcnewoption_entrypoint_4(actor, 0, _gcnewoption_entrypoint_16, _gcnewoption_entrypoint_35,
                              0x184E);
    menu = func_80100094(actor, 0);
    _gcnewoption_entrypoint_8(menu, 4);
    _gcnewoption_entrypoint_9(menu, 4);
    _gcnewoption_entrypoint_10(menu, 0);
    func_808004E8_chdumbwaiterlift(actor, menu);
    _gcnewoption_entrypoint_11(menu);
    func_80101FDC(actor, 4);
    func_80800A8C_chdumbwaiterlift(actor);
    func_8010A828(actor, 0xA);
}

// Index of the floor matching the current map, or -1.
s32 func_808008B4_chdumbwaiterlift(void)
{
    s32 map;
    s32 i;
    map = func_800EA05C();
    for (i = 0; i < 5; i++) {
        if (map == ((LiftMapRecord *) D_80800BC0_chdumbwaiterlift)[i].map)
            return i;
    }
    return -1;
}

// Finds the floor whose flag is set (destination) and clears it; -1 if none.
s32 func_8080094C_chdumbwaiterlift(void)
{
    s8 *row;
    s32 i;

    row = (s8 *) D_80800BC0_chdumbwaiterlift;
    i = 0;
loop_1:
    if (func_800DA298(*(s16 *) ((s8 *) row + 4)) != 0) {
        func_800DA524(*(s16 *) ((s8 *) row + 4));
        return i;
    }
    i += 1;
    row += 8;
    if (i == 5) {
        return -1;
    }
    goto loop_1;
}

s32 func_808009B8_chdumbwaiterlift(selection)
s32 selection;
{
    s32 map;
    s32 i;
    s32 count;

    map = func_800EA05C();
    count = 0;
    for (i = 0; i < 5; i++) {
        if (map != D_80800BC0_chdumbwaiterlift[i].map) {
            if (selection == count)
                return i;
            count++;
        }
    }
    return -1;
}

int func_80800A8C_chdumbwaiterlift(actor)
Actor *actor;
{
    f32 rotation[3];

    if (!actor->unk64_20) {
        func_800EFA4C(rotation, 0.0f, actor->rotation[1], 0.0f);
        func_800F8444(func_800F54E4(), rotation);
        _capod_entrypoint_2(actor->unk0, 0x1B, 0x10);
        _capod_entrypoint_8(1);
        _gcdialogcamera_entrypoint_8();
        _capod_entrypoint_11(1, rotation);
        _capod_entrypoint_7(5, 0);
        _subaddieDll_entrypoint_4(actor, 1);
        actor->unk64_20 = 1;
    }
}

void func_80800B40_chdumbwaiterlift(actor) Actor *actor;
{
    if (actor->unk64_20) {
        _capod_entrypoint_3(0);
        _subaddieDll_entrypoint_4(actor, 0);
        actor->unk64_20 = 0;
    }
}

// Floor table rows: {map, entrance, flag, unk_6}.
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
