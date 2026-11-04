// Probably the Witchyworld cable car: a switch-powered car moving between two endpoints with
// a sway, ridden by the player as a sub-game vehicle.
#include "common.h"
#include "core2/1EB5980.h"
#include "core2/1ED8C80.h"
#include "su/baddieaudioquick.h"

extern void *D_80800EB0_chcablecar;
extern void *D_80800EF8_chcablecar;
typedef struct {
    s16 local_0;
    s16 local_1;
} CableCarEvent;
typedef struct {
    u8 pad_0[0x2A];
    u8 pad_1 : 3;
    u8 local_0 : 1;
    u8 pad_2 : 4;
} CableCarMarker;
extern void _mlwave_entrypoint_1(void *);
extern f32 _mlwave_entrypoint_5(void *, f32, f32);
extern u8 D_80800F68_chcablecar[];
extern void _subaddieaudioloop_entrypoint_4(Actor *, f32 *, s32, void *);
typedef struct {
    s16 local_0[3];
    s16 local_1[3];
    f32 local_2;
} CableCarPath;
extern void func_800EFE50(f32 *, f32 *, f32 *, f32);
typedef struct {
    u8 pad[0x2A];
    u8 b7 : 1;
    u8 b6 : 1;
    u8 b5 : 1;
    u8 rest : 5;
} CcarS;
extern void func_80015178(s32);
typedef struct {
    u8 pad_0[0x28];
    u32 pad_1 : 18;
    u32 local_0 : 1;
    u32 pad_2 : 13;
} CableCarMarkerFlags;
typedef struct {
    u8 pad0[0x28];
    u32 pad28_13 : 19;
    u32 unk28_12 : 1;
    u32 pad28_0 : 12;
} CableCarInfo;
extern s32 func_800F4F34(s32, f32 *, f32, f32);
extern void _subaddieDll_entrypoint_4(void *, s32);
extern f32 func_800D8FF8(void);
extern f32 func_800EEB40(f32 *, f32 *);
extern void func_808005E0_chcablecar(Actor *);
typedef struct {
    u8 pad_0[0x28];
    u32 pad_1 : 19;
    u32 local_0 : 1;
    u32 pad_2 : 12;
} Mass63CableMarker;
extern void _mlwave_entrypoint_0(void *, f32, f32);
typedef struct {
    u8 pad[0xC];
    f32 progress;
} CableCarProgress;
extern f32 func_800F10B4(f32, f32, f32, f32, f32);
typedef struct Mass45CableFlags {
    u32 local_0 : 12;
    u32 local_1 : 1;
    u32 local_2 : 19;
} Mass45CableFlags;
extern void func_800EFA4C(f32 *, f32, f32, f32);
extern void func_800EF04C(f32 *, f32 *);
void func_80800DC8_chcablecar();
void func_808004EC_chcablecar();
void func_80800914_chcablecar();

extern f32 D_80800F40_chcablecar[3];
extern s16 D_80800F4C_chcablecar[];
extern s16 D_80800F58_chcablecar[];

typedef struct {
    u8 pad0[0xC];
    f32 unkC;
    u8 unk10;
} cablecarMemory;

int chcablecar_entrypoint_0()
{
    return &D_80800EB0_chcablecar;
}

int chcablecar_entrypoint_1()
{
    return &D_80800EF8_chcablecar;
}

void func_80800D14_chcablecar();

s32 func_80800BD0_chcablecar();

void func_80800AF4_chcablecar();

void func_808007C8_chcablecar();

s32 func_8080070C_chcablecar(Actor *param_0, f32 param_1);

void func_8080069C_chcablecar();

void func_80800598_chcablecar();

void func_80800018_chcablecar(Actor *actor)
{
    u8 *car;
    f32 frame_time;
    s32 riding;
    f32 player_pos[3];
    f32 car_pos[3];
    car = func_80100094(actor, 0);
    frame_time = func_800D8FF8();
    riding = 0;
    func_80800598_chcablecar(actor);
    func_8080069C_chcablecar(actor);
    switch (actor->unk70_10) {
        case 1:
            if (func_800DA298(0xD4) != 0) {
                func_808007C8_chcablecar(actor, 1, 4);
            }
            func_808005E0_chcablecar(actor);
            break;

        case 2:
            if (func_80800BD0_chcablecar(actor) != 0) {
                func_808007C8_chcablecar(actor, 2, 5);
            }
            func_808005E0_chcablecar(actor);
            break;

        case 3:
            if (!((Mass63CableMarker *) actor->unk0)->local_0) {
                func_8010D254(player_pos);
                func_800EE7F8(car_pos, actor->position);
                car_pos[1] -= 400.0f;
                if (func_800EEB40(car_pos, player_pos) > 3062500.0f) {
                    func_800DA524(0x67E);
                    func_80101FDC(actor, 6);
                }
            } else if (func_80800BD0_chcablecar(actor) != 0) {
                func_808007C8_chcablecar(actor, 4, 4);
            }
            func_808005E0_chcablecar(actor);
            break;

        case 4:
            riding = 1;
            if (func_8080070C_chcablecar(actor, *(f32 *) ((s8 *) car + 0xC) -
                                                      (frame_time * 0.045f)) != 0) {
                _susubgame_entrypoint_4(actor, car + 0x2C);
                func_800DA524(0x67E);
                func_80800AF4_chcablecar(actor, 2);
            }
            break;

        case 5:
            riding = 1;
            if (func_8080070C_chcablecar(actor, *(f32 *) (car + 0xC) + (frame_time * 0.045f)) !=
                0) {
                _susubgame_entrypoint_4(actor, car + 0x2C);
                func_800DA544(0x67E);
                func_80800AF4_chcablecar(actor, 3);
                _subaddieDll_entrypoint_4(actor, 1);
            }
            break;

        case 6:
            riding = 1;
            if (func_8080070C_chcablecar(actor, *(f32 *) ((s8 *) car + 0xC) -
                                                      (frame_time * 0.045f)) != 0) {
                _subaddieDll_entrypoint_4(actor, 0);
                func_80101FDC(actor, 2);
            }
            break;

        case 7:
            func_808005E0_chcablecar(actor);
    }

    func_80800D14_chcablecar(actor, riding);
    func_80800914_chcablecar(actor);
    ((u8 *) actor->unk0)[0x2A] &= ~0x10;
}

void func_808002E0_chcablecar(Actor *actor)
{
    u8 *car;
    s32 at_top;
    s32 powered;

    car = func_80100094(actor, 0);
    _susubgame_entrypoint_0(actor, car + 0x2C, 0);
    if (func_800EA05C() == 0x124) {
        func_8010A624(actor);
        ((u8 *) actor)[0x7E] &= ~0x40;
    }
    func_800EE940(car, actor->position);
    func_800EFA6C(car + 6, -8300, 2675, 0);
    *(s32 *) ((u8 *) actor + 0x28) = 0;
    at_top = func_800DA298(0x67E);
    powered = func_800DA298(0xD4);
    if (!at_top && powered) {
        *(f32 *) (car + 0xC) = 0.0f;
        func_8080070C_chcablecar(actor, 0.0f);
        func_80101FDC(actor, 2);
    } else if (at_top) {
        *(f32 *) (car + 0xC) = 1.0f;
        func_8080070C_chcablecar(actor, 1.0f);
        func_80101FDC(actor, 3);
        _subaddieDll_entrypoint_4(actor, 1);
    } else {
        *(f32 *) (car + 0xC) = 0.1f;
        func_8080070C_chcablecar(actor, 0.1f);
    }
    _mlwave_entrypoint_0(car + 0x10, 100.0f, 15.0f);
}

s32 func_80800B74_chcablecar();

s32 func_80800424_chcablecar(Actor *actor, s32 msg, CableCarEvent event)
{
    switch (msg) {
        case 0x3D:
            func_80800DC8_chcablecar(actor);
            break;
        case 0x2E:
            func_80800B74_chcablecar(actor, event.local_0, event.local_1);
            break;
        case 0x1F:
            func_808004EC_chcablecar(actor);
            break;
        case 0x95:
            if (func_800EA05C() == 0xD6)
                func_80108B04(actor, 0);
            break;
        case 0x91:
            ((CableCarMarker *) actor->unk0)->local_0 = 1;
            break;
        default:
            return 0;
    }
    return 1;
}

void func_808004EC_chcablecar(actor) Actor *actor;
{
    CableCarProgress *local_0;
    s32 local_1;

    local_0 = func_80100094(actor, 0);
    if (local_0->progress < 0.4f) {
        local_1 = 0;
    } else if (local_0->progress > 0.6f) {
        local_1 = 255;
    } else {
        local_1 = (s32) func_800F10B4(local_0->progress, 0.4f, 0.6f, 0.0f, 255.0f);
    }
    func_801015D0(actor);
    func_800DF6BC(local_1, 255);
}

void func_80800598_chcablecar(Actor *actor)
{
    u8 *car = (u8 *) func_80100094(actor, 0);
    u8 *wave = car + 0x10;
    _mlwave_entrypoint_1(wave);
    *(f32 *) ((u8 *) actor + 0x44) = _mlwave_entrypoint_5(wave, -5.0f, 5.0f);
}

void func_808005E0_chcablecar(Actor *actor)
{
    void *wave;
    cablecarMemory *car;

    car = func_80100094(actor, 0);
    wave = &car->unk10;
    if (car->unkC < 0.5f) {
        if ((_mlwave_entrypoint_9(wave, D_80800F40_chcablecar) != 0) &&
            (func_800DC298(0.8f) != 0)) {
            _subaddieaudioquick_entrypoint_2(actor, actor->position, D_80800F4C_chcablecar);
        }
    } else if ((_mlwave_entrypoint_9(wave, D_80800F40_chcablecar) != 0) &&
               (func_800DC298(0.8f) != 0)) {
        _subaddieaudioquick_entrypoint_2(actor, actor->position, D_80800F58_chcablecar);
    }
}

void func_8080069C_chcablecar(Actor *actor)
{
    s32 moving;

    switch (actor->unk70_10) {
        case 4:
        case 5:
        case 6:
            moving = 1;
            break;
        default:
            moving = 0;
            break;
    }
    if (moving || (!moving && actor->unk5F)) {
        _subaddieaudioloop_entrypoint_4(actor, actor->position, moving, D_80800F68_chcablecar);
    }
}

s32 func_8080070C_chcablecar(Actor *actor, f32 progress)
{
    CableCarPath *path;
    s32 clamped;
    f32 end[3];
    f32 start[3];
    path = func_80100094(actor, 0);
    clamped = 0;
    if (progress < 0.0f) {
        progress = 0.0f;
        clamped = 1;
    } else if (progress > 1.0f) {
        progress = 1.0f;
        clamped = 1;
    }
    func_800EE88C(end, path->local_1);
    func_800EE88C(start, path->local_0);
    func_800EFE50(actor->position, start, end, progress);
    path->local_2 = progress;
    return clamped;
}

void func_808007C8_chcablecar(Actor *actor, s32 mode, s32 next_state)
{
    u8 *car;
    s32 subgame_id;

    car = func_80100094(actor, 0);
    _subaddieDll_entrypoint_4(actor, 1);
    func_801039E4(actor->unk0);
    func_80103D48(actor);
    if (*(s32 *) &mode == 2 && func_800DA9E4(0xBF, 1)) {
        mode = 3;
    }
    switch (mode) {
        case 3:
            _susubgame_entrypoint_8(actor, car + 0x2C, 0x2F, 0x10010, 0);
            break;
        case 4:
            _susubgame_entrypoint_8(actor, car + 0x2C, 0x2E, 0x10010, 0);
            break;
        default:
            subgame_id = (mode == 1) ? 0x1D : 0x21;
            func_80015178(3);
            ((CcarS *) actor->unk0)->b5 = 1;
            _susubgame_entrypoint_6(actor, car + 0x2C, subgame_id, 0x10070, 0);
    }
    *(s32 *) ((u8 *) actor + 0x28) = mode;
    func_80101FDC(actor, next_state);
}

void func_80800914_chcablecar(actor) Actor *actor;
{
    u8 *car;
    s32 subgame_id;
    f32 local_2[3];
    f32 local_3[3];
    f32 local_4[3];
    f32 local_5[3];

    car = func_80100094(actor, 0);
    subgame_id = func_800F54E4();
    switch (actor->actorData[4]) {
        case 3:
            if (*(f32 *) (car + 0xC) > 0.15f &&
                !((Mass45CableFlags *) ((u8 *) actor + 0x64))->local_1) {
                func_8080070C_chcablecar(actor, 0.85f);
                actor->unk64_19 = 1;
                _susubgame_entrypoint_8(actor, car + 0x2C, 0x2E, 0x12010, 0);
                func_800EFA4C(local_2, -80.0f, -425.0f, 0.0f);
                func_800EF04C(local_2, actor->position);
                func_800F8294(subgame_id, local_2);
                func_800EFA4C(local_3, 0.0f, 270.0f, 0.0f);
                func_800F8444(subgame_id, local_3);
            }
            break;
        case 4:
            if (*(f32 *) (car + 0xC) < 0.85f &&
                !((Mass45CableFlags *) ((u8 *) actor + 0x64))->local_1) {
                func_8080070C_chcablecar(actor, 0.15f);
                actor->unk64_19 = 1;
                _susubgame_entrypoint_8(actor, car + 0x2C, 0x2F, 0x12010, 0);
                func_800EFA4C(local_4, 60.0f, -425.0f, 0.0f);
                func_800EF04C(local_4, actor->position);
                func_800F8294(subgame_id, local_4);
                func_800EFA4C(local_5, 0.0f, 90.0f, 0.0f);
                func_800F8444(subgame_id, local_5);
            }
    }
}

void func_80800AF4_chcablecar(Actor *actor, void *state)
{
    _subaddieDll_entrypoint_4(actor, 0);
    func_80103D70(actor);
    func_80101FDC(actor, state);
    if (((CableCarMarkerFlags *) actor->unk0)->local_0) {
        func_80015178(2);
        ((CableCarMarkerFlags *) actor->unk0)->local_0 = 0;
    }
    actor->actorData[4] = 0;
    actor->unk64_19 = 0;
}

s32 func_80800B74_chcablecar(Actor *this, enum asset_e text_id, s32 param_2)
{
    if (!func_800DA298(0x67E)) {
        func_80101FDC(this, 2);
    } else {
        func_80101FDC(this, 3);
        _subaddieDll_entrypoint_4(this, 1);
    }
}

s32 func_80800BD0_chcablecar(Actor *actor)
{
    s32 player;

    player = func_800F54E4();
    if (!func_800F6438(player) || !((CableCarInfo *) actor->unk0)->unk28_12 ||
        !func_800F6C5C(player))
        return 0;
    if (!func_800DA298(0x67F)) {
        _subaddiedialog_entrypoint_11(actor->unk0, 0x10BA, 0xE, 0, 0x22);
        func_80101FDC(actor, 7);
        func_800DA544(0x67F);
        return 0;
    }
    if (func_80016B30(0, 1) != 1)
        return 0;
    if (func_800F6B40(player))
        return 0;
    if (!func_800F4BB8(player, -1, 0))
        return 0;
    if (func_800F5410(player) != 1) {
        _subaddiedialog_entrypoint_11(actor->unk0, 0x10B9, 0xF, 0, 0x22);
        func_80101FDC(actor, 7);
        return 0;
    }
    return 1;
}

void func_80800D14_chcablecar(Actor *actor, s32 riding)
{
    Actor *passenger;
    s32 player;

    if (actor->unk3C) {
        player = func_800F54E4();
        passenger = func_80106790(actor->unk3C);
        passenger->rotation[0] = actor->rotation[0];
        func_800EE7F8(passenger->position, actor->position);
        func_80103014(passenger);
        _subaddieDll_entrypoint_4(passenger, *(u16 *) ((u8 *) actor + 0x7C));
        if (func_800F6C88(player) && func_800F4F34(player, passenger->position, 0.0f, 80.0f) &&
            riding) {
            func_800F76B0(player, 0xA, passenger->unk0);
        }
    }
}

void func_80800DC8_chcablecar(actor) Actor *actor;
{
    u8 *player;

    player = func_801084B0(0x33F, &actor);
    func_80102FDC(player, *(s32 *) ((u8 *) actor + 0x38));
    _subaddieDll_entrypoint_4(player, *(u16 *) ((u8 *) actor + 0x7C));
    *(f32 *) (player + 0x44) = *(f32 *) ((u8 *) actor + 0x44);
    *(s32 *) ((u8 *) actor + 0x3C) = *(s32 *) (player + 0);
}

s32 func_80800E30_chcablecar(Actor *this)
{
    _chswitch_entrypoint_7(this, 0xD4);
    _chswitch_entrypoint_9(this);
}

// TU-NOTE: the overlay .data is defined in this file. Its tables point to functions here, and
// IDO's assembler schedules some of them differently unless the tables are in the same unit.
extern void func_80105834();
extern void func_801018A4();
extern void func_80107C2C();
extern u8 D_8011A248[];
extern void _chswitch_entrypoint_6();
extern void func_80101870();
extern void _chswitch_entrypoint_10();
void *D_80800EB0_chcablecar = (void *) 0x02A5033E;
static u32 D_80800EB0_chcablecar_rest[17] = {0x77D0001,
                                             0x0,
                                             (u32) func_80800018_chcablecar,
                                             (u32) func_80105834,
                                             (u32) func_801018A4,
                                             0x9C40000,
                                             0x0,
                                             0x0,
                                             0x4C00,
                                             0x0,
                                             0x0,
                                             0x440000,
                                             (u32) func_808002E0_chcablecar,
                                             (u32) func_80107C2C,
                                             0x80004402,
                                             (u32) func_80800424_chcablecar,
                                             0x0};
void *D_80800EF8_chcablecar = (void *) 0x0343033F;
static u32 D_80800EF8_chcablecar_rest[17] = {0x77F0001,
                                             (u32) &D_8011A248,
                                             (u32) _chswitch_entrypoint_6,
                                             (u32) func_80105834,
                                             (u32) func_80101870,
                                             0x0,
                                             0x0,
                                             0x0,
                                             0x480C,
                                             0x0,
                                             0x0,
                                             0x0,
                                             (u32) func_80800E30_chcablecar,
                                             (u32) func_80107C2C,
                                             0x80002802,
                                             (u32) _chswitch_entrypoint_10,
                                             0x0};
f32 D_80800F40_chcablecar[3] = {0.35f, 0.85f, -1.0f};
s16 D_80800F4C_chcablecar[6] = {0x13, 0x51B, 0xD, 0xD9, 0x126, 0x0};
s16 D_80800F58_chcablecar[8] = {0x13, 0x4A1, 0x16, 0x4650, 0xD, 0xE6, 0x100, 0x0};
u8 D_80800F68_chcablecar[24] = {0x0,  0x13, 0x4, 0xBF, 0x0, 0xA, 0x0, 0xE6, 0x0, 0x1, 0x3, 0xE8,
                                0x11, 0x94, 0x0, 0x0,  0x0, 0x0, 0x0, 0x0,  0x0, 0x0, 0x0, 0x0};
