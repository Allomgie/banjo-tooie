// Most likely Taxi Pack passenger logic: pickup tests, flights into and out of the backpack,
// restoring passengers after a map change, falling to the floor, and the drop-off.
#include "common.h"

extern void func_8010D254(f32 *);
extern f32 func_800F1DF4(f32 *, f32 *);
extern f32 func_80090010(void);
extern f32 func_800F1DCC(f32, f32);
extern f32 mlAbsF(f32);
extern f32 func_800CB45C(s32, f32 *, s32 *, s32 *);
extern void func_800EE7F8(f32 *, f32 *);
extern u8 D_80800D5C_subaddietaxi[];
extern void func_800DFF64();
extern void func_800EFA4C(f32 *, f32, f32, f32);
typedef union {
    f32 as_f32;
    s32 as_s32;
} TaxiCallbackFloatWord1001;
extern void _subaddiefade_entrypoint_1();
extern Actor *func_80106790(Unk80132ED0 *);
extern void *func_80104248(Actor *);
extern void func_8008AEE4();
extern void func_8008AF04(void *, s32);
extern void _subaddietaxi_entrypoint_6(Actor *, f32);
typedef struct {
    u8 pad_0[0x48];
    s32 unk_48;
    u8 pad_4C[0x18];
    u32 pad_64 : 14;
    u32 flag : 1;
    u32 unk_64_15 : 17;
} TaxiS;
extern s32 func_800EA05C(void);
extern void func_800CB6B4();
extern void _subaddieaudioquick_entrypoint_2(s32, s32, void *);
extern void func_800BBCB8(s32, s32, f32, s32, void *);
extern s32 D_80800D50_subaddietaxi[];
extern s32 D_80800D74_subaddietaxi[];
typedef struct {
    s32 unk_0;
    s32 passenger_id;
    f32 unk_8;
    f32 pos[3];
} TaxiSpawn62;
extern Actor *func_80108474(s32, f32 *, s32);
extern void func_8010108C(Actor *, s32, s32);
extern s16 D_80800DB4_subaddietaxi[];
extern void *func_8010410C();
extern f32 func_800F10B4(f32, f32, f32, f32, f32);
extern f32 func_800F1214(f32, f32, f32);
extern void func_800EFE50(f32 *, f32 *, f32 *, f32);
extern f32 func_8001395C(f32);
extern f32 func_800CB3FC(s32, f32 *, s32 *);
extern void func_800CB534(s32, f32 *, f32);
extern f32 func_800F2094(f32, f32);
extern int func_800F1884(f32[3], f32 *);
extern int func_800C696C(f32[3], f32, f32, u32, f32 *);
extern int func_800E1610(s32, f32, f32, f32[3]);
extern u8 D_80800D68_subaddietaxi[];
s32 func_80800CF0_subaddietaxi();

// Init flight data: start[3], target[3], saved scale, timer. Actor shrinks to 0.05.
void subaddietaxi_entrypoint_0(u8 *actor, s32 unk_1, u8 *target, s32 unk_3)
{
    u8 *flight;

    flight = func_8010410C();
    if (unk_3 >= 0) {
        func_80102424(actor, unk_3);
    }
    func_800EE7F8(flight, actor + 4);
    func_800EE7F8(flight + 0xC, target);
    *(f32 *) ((char *) flight + 0x18) = *(f32 *) ((char *) actor + 0x38);
    *(f32 *) ((char *) actor + 0x38) = 0.05f;
    *(f32 *) ((char *) flight + 0x1C) = 0.5f;
}

void func_80800C00_subaddietaxi();

// Per-frame flight along an arc with scale change and sparkles; returns 1 when done.
s32 subaddietaxi_entrypoint_1(Actor *actor, s32 slot)
{
    f32 *flight;
    s32 events;
    f32 t;
    flight = func_8010410C(actor);
    events = func_800CB518(slot);
    func_800CB698(slot, 6);
    if (flight[7] == 0.0f) {
        return 1;
    }
    if (events & 1) {
        _fxsparkle_entrypoint_1(actor->position, 0xB);
    }
    func_800D9078(flight + 7);
    t = func_800F10B4(flight[7], 0.0f, 0.5f, 0, 1.0f);
    actor->scale = func_800F1214(t, flight[6], 0.05f);
    func_800EFE50(actor->position, flight + 3, flight, t);
    actor->position[1] += func_8001395C(t * 3.1415927f) * 200.0f;
    func_80104580(actor);
    if (flight[7] == 0.0f) {
        flight[6] = flight[7];
        func_800EFD24(flight);
        func_800EFD24(flight + 3);
        if (events & 4) {
            func_800E1610(0, 20.0f, 0.9f, actor->position);
        }
        if (events & 2) {
            func_80800C00_subaddietaxi(actor);
        }
        return 1;
    }
    return 0;
}

// Whether the player faces the actor within a window of max_angle degrees.
s32 func_80800220_subaddietaxi(Actor *actor, f32 max_angle)
{
    f32 player_pos[3];
    f32 facing;
    f32 angle_to_actor;

    func_8010D254(player_pos);
    angle_to_actor = func_800F1DF4(player_pos, actor->position);
    facing = func_80090010();
    return mlAbsF(func_800F1DCC(facing, angle_to_actor)) < max_angle;
}

// Pickup test: slot state 1 or 5, player faces actor, actor visible, taxi state 0x13.
int subaddietaxi_entrypoint_2(s32 *actor, s32 slot)
{
    s32 state;
    state = func_800CB3E0(slot);
    if ((state != 1) && (state != 5)) {
        return 0;
    }
    if (func_80800220_subaddietaxi(actor, 9e+01f) == 0) {
        return 0;
    }
    if (_subaddiefade_entrypoint_0(actor) < 0x78) {
        return 0;
    }
    return func_8008FCC8(*actor) == 0x13 && func_800905C4(*actor, slot) != 0;
}

void subaddietaxi_entrypoint_3(void)
{
}

// Map start: re-place stored passengers in the registry whose stored map is the current map.
void subaddietaxi_entrypoint_4(void)
{
    f32 pos[3];
    f32 rotation;
    s32 map;
    s32 slot;
    s32 stored_map;

    map = func_800EA05C();
    for (slot = 1; slot != 16; slot++) {
        switch (func_800CB3E0(slot)) {
            case 0:
            case 2:
            case 3:
            case 4:
                break;
            case 1:
                rotation = func_800CB3FC(slot, pos, &stored_map);
                if (stored_map == map) {
                    func_800CB534(slot, pos, rotation);
                }
                break;
            case 5:
                func_800CB70C(slot);
                func_800CB698(slot, 1);
                rotation = func_800CB3FC(slot, pos, &stored_map);
                if (stored_map == map) {
                    func_800CB534(slot, pos, rotation);
                }
                break;
            case 6:
                rotation = func_800CB3FC(slot, pos, &stored_map);
                if (stored_map == map) {
                    func_800CB534(slot, pos, rotation);
                }
            default:
                break;
        }
    }
}

// Restore a passenger at its stored position if it is on the current map; returns 1 if placed.
s32 subaddietaxi_entrypoint_5(Actor *actor, s32 slot)
{
    s32 stored_map;
    s32 unk_1;
    f32 pos[3];
    f32 rotation;
    s32 placed;

    placed = 0;
    rotation = func_800CB45C(slot, pos, &stored_map, &unk_1);
    if (func_800EA05C() == stored_map) {
        actor->rotation[1] = rotation;
        func_800EE7F8(actor->position, pos);
        actor->unk74_7 = unk_1;
        placed = 1;
        _subaddiefade_entrypoint_2(actor);
        _subaddieaudioquick_entrypoint_2(actor, actor->position, D_80800D5C_subaddietaxi);
    } else
        func_800FFAB0(actor);
    func_800CB698(slot, 1);
    func_800CB70C(slot);
    return placed;
}

void subaddietaxi_entrypoint_6(Actor *actor, TaxiCallbackFloatWord1001 scale)
{
    f32 vec[3];
    // Matching: empty block needed for the match.
    if (1) {
    }
    func_800EFA4C(vec, scale.as_f32, scale.as_f32, scale.as_f32);
    func_800DFF64(actor, 0x12, vec);
}

void subaddietaxi_entrypoint_7(Unk80132ED0 *ref)
{
    Actor *actor;
    f32 *flight;
    void *anctrl;
    TaxiCallbackFloatWord1001 scale;
    actor = func_80106790(ref);
    flight = func_8010410C();
    anctrl = func_80104248(actor);
    func_800EE7F8(flight, actor->position);
    flight[6] = actor->scale;
    func_8008AEE4(anctrl, _subaddietaxi_entrypoint_6);
    scale.as_f32 = 1.0f;
    func_8008AF04(anctrl, scale.as_s32);
    _subaddiefade_entrypoint_1((u8 *) actor, 0xFF);
}

void subaddietaxi_entrypoint_8(Unk80132ED0 *ref, f32 *target, f32 t, f32 progress,
                               s32 slot)
{
    Actor *actor;
    f32 *flight;
    s32 pad;
    TaxiCallbackFloatWord1001 scale;

    actor = func_80106790(ref);
    flight = func_8010410C();
    if (func_800CB518(slot) & 1) {
        _fxsparkle_entrypoint_1(actor->position, 11);
    }
    func_800EFE50(actor->position, target, flight, t);
    actor->scale = func_800F10B4(progress, 0.0f, 1.0f, 0.01f, flight[6]);
    if (0.45f < progress) {
        scale.as_f32 = 1 / progress;
    } else {
        scale.as_f32 = func_800F10B4(progress, 0.0f, 0.45f, 0.01f, 1.0f / progress);
    }
    func_8008AF04(func_80104248(actor), scale.as_s32);
}

// Store the passenger's position in its registry slot unless flagged.
void subaddietaxi_entrypoint_9(TaxiS *actor, s32 slot)
{
    if (!actor->flag) {
        func_800CB6B4(slot, (u8 *) actor + 4, actor->unk_48, func_800EA05C());
    }
}

int subaddietaxi_entrypoint_10(s32 actor, s32 unk_1, s32 unk_2)
{
    Actor *data;
    data = func_8010410C();
    if (unk_2 >= 0) {
        // Matching: `| 0` needed for the match.
        func_80102424(actor | 0, unk_2);
    }
    *(f32 *) ((char *) actor + 0x34) = -6800.0f;
    func_800EEB9C((f32 *) ((char *) actor + 0x28), *(s32 *) ((char *) actor + 0x48),
                  0x43960000);
    *(f32 *) ((char *) actor + 0x2C) = 1800.0f;
    *(f32 *) ((char *) actor + 0x18) = 8.0f;
    *(f32 *) ((char *) actor + 0x1C) = *(f32 *) ((char *) actor + 0x38);
    *(f32 *) ((char *) actor + 0x38) = 0.05f;
    _subaddieDll_entrypoint_4(actor, 1);
    *(u16 *) ((char *) data + 0x20) = 0;
}

// Drop-off flight: passenger falls out of the backpack and lands on the floor.
s32 subaddietaxi_entrypoint_11(Actor *actor, s32 slot)
{
    s32 data;
    s32 alpha;
    s32 events;
    s32 hit;
    s32 landed;
    f32 hit_dir[3];
    f32 hit_angle;
    f32 *pos;
    f32 floor_y;

    data = func_8010410C();
    func_800CB698(slot, 5);
    func_800D9078(actor->actorData);
    if (((f32 *) actor->actorData)[7] != 0.0f) {
        events = func_800CB518(slot);
        if (events & 1) {
            _fxsparkle_entrypoint_1(actor->position, 0xB);
        }
        hit = func_8010B990(actor, 0x204024);
        if (hit & 0x28) {
            landed = hit & 8;
            if (hit & 0x20) {
                func_8010AA54(hit_dir);
                if (func_800F1884(hit_dir, &hit_angle)) {
                    if (func_800F2094(hit_angle, 90.0f) < 45.0f) {
                        landed = (hit & 8) + 1;
                    }
                } else if (hit_dir[1] > 0.0f) {
                    landed = (hit & 8) + 1;
                }
            }
            if (landed) {
                pos = actor->position;
                func_800EFD24(&actor->actorData[4]);
                ((f32 *) actor->actorData)[7] = 0.0f;
                if (func_800C696C(pos, 50.0f, -50.0f, actor->unk14, &floor_y) &&
                    actor->position[1] < floor_y) {
                    actor->position[1] = floor_y;
                }
                if (events & 4) {
                    func_800E1610(0, 20.0f, 0.9f, pos);
                }
                if (events & 2) {
                    func_80800C00_subaddietaxi(actor);
                }
            }
        }
    }
    alpha = _subaddiefade_entrypoint_0(actor);
    _subaddiefade_entrypoint_1(
        actor, (s32) func_800F10B4(((f32 *) actor->actorData)[0], 0, 1.0f, 0.0f, 255.0f));
    actor->scale = func_800F10B4(((f32 *) actor->actorData)[0], 7.7f, 8.0f,
                                 ((f32 *) actor->actorData)[1], 0.05f);
    if (alpha == 255 && _subaddiefade_entrypoint_0(actor) != 255) {
        _subaddieaudioquick_entrypoint_2(actor, actor->position, D_80800D68_subaddietaxi);
    }
    if (_subaddiefade_entrypoint_0(actor) != 255) {
        func_801078DC(actor, data + 0x20);
    }
    if (((f32 *) actor->actorData)[0] == 0.0f || actor->position[1] < -30000.0f) {
        _subaddieDll_entrypoint_4(actor, 0);
        return 1;
    }
    return 0;
}

int subaddietaxi_entrypoint_12(struct Actor *actor, s32 unk_1)
{
    return *(f32 *) ((char *) actor + 0x34) == 0.0f;
}

// Claim a registry slot for the passenger and store its map and position.
int subaddietaxi_entrypoint_13(s32 *actor, s32 slot, s32 unk_2, s32 unk_3)
{
    s32 claimed;
    s32 map;
    s32 stored;
    // Matching: the `| 0` operands are needed for the match.
    claimed = func_800CB4D0(slot | 0, unk_2 | 0, unk_3 | 0);
    if (claimed != 0) {
        map = func_800EA05C();
        stored = func_800CB764(slot, actor + 1, *(s32 *) ((char *) actor + 0x48), map,
                               (u32) (u16) *(s32 *) ((char *) actor + 0x74) >> 7);
        func_800CB70C(slot);
    }
    *(s32 *) ((char *) actor + 0x14) = 0x420021;
    return claimed;
}

void subaddietaxi_entrypoint_14(s32 actor, s32 unk_1)
{
    *(s16 *) ((s8 *) func_8010410C() + 0x20) = 0;
    _subaddieDll_entrypoint_4(actor, 1);
}

s32 subaddietaxi_entrypoint_15(s32 actor, s32 unk_1)
{
    unsigned long alpha;
    func_801078DC(actor, (s32) func_8010410C() + 0x20);
    alpha = _subaddiefade_entrypoint_0(actor);
    if (alpha == 0xFF) {
        _subaddieDll_entrypoint_4(actor, 0);
        return 1;
    }
    return 0;
}

void func_80800C00_subaddietaxi(s32 actor)
{
    func_800BBCB8(actor + 4, actor + 4, 1.0f, 6, &D_80800D74_subaddietaxi);
    _subaddieaudioquick_entrypoint_2(actor, actor + 4, &D_80800D50_subaddietaxi);
}

// Spawn a passenger actor; args are packed as words and reinterpreted as f32 where needed.
void subaddietaxi_entrypoint_16(s32 passenger_id, s32 pos_x, s32 pos_y, s32 pos_z, s32 unk_4,
                                s32 unk_5)
{
    Actor *actor;
    TaxiSpawn62 spawn;

    spawn.passenger_id = *(s32 *) &passenger_id;
    spawn.pos[0] = *(f32 *) &pos_x;
    spawn.pos[1] = *(f32 *) &pos_y;
    spawn.pos[2] = *(f32 *) &pos_z;
    spawn.unk_8 = *(f32 *) &unk_4;
    spawn.unk_0 = unk_5;
    actor = func_80108474(func_80800CF0_subaddietaxi(spawn.passenger_id), spawn.pos,
                          (s32) spawn.unk_8);
    actor->unk74_7 = spawn.unk_0;
    func_8010108C(actor, 0x44, spawn.passenger_id);
}

s32 func_80800CF0_subaddietaxi(index)
s32 index;
{
    return D_80800DB4_subaddietaxi[index];
}

// TU-NOTE: the overlay .data is defined here in C (values from the ROM). The externs of
// D_80800D50_subaddietaxi and D_80800D74_subaddietaxi are declared as s32[] to match the object.
s32 D_80800D50_subaddietaxi[3] = {0x130417, 0x164650, 0x0};
u8 D_80800D5C_subaddietaxi[12] = {0x0, 0x13, 0x4, 0xED, 0x0, 0x1, 0x3, 0xE8, 0x13, 0x88, 0x0, 0x0};
u8 D_80800D68_subaddietaxi[12] = {0x0, 0x13, 0x4, 0xEE, 0x0, 0x1, 0x3, 0xE8, 0x13, 0x88, 0x0, 0x0};
s32 D_80800D74_subaddietaxi[16] = {0x1D09DD,    0x2B00CC, 0x1000022, 0x800099, 0xCC0100, 0x150000,
                                   0x260019,    0x7,      0x2D0096,  0xC8001E, 0x1E001E, 0x208080,
                                   -0x7F3FFFF5, 0x140032, 0x50000,   0x0};
s16 D_80800DB4_subaddietaxi[22] = {-0x1,  0x142, 0x291, 0x28C, 0x28C, 0x28C, 0x28C, 0x3D6,
                                   0x3D6, 0x3D6, 0x3D6, 0x346, 0x291, 0x486, 0x486, 0x486,
                                   0x0,   0x0,   0x0,   0x0,   0x0,   0x0};
