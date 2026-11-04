#include "common.h"

extern int D_80800DB0_chswitch[];
extern void *D_80800DC4_chswitch;
extern void *D_80800DD8_chswitch;
extern Actor *func_80106790();
extern void func_80103110(Actor *, s32);
extern void _gcaudiolist_entrypoint_0(s32);
typedef struct {
    u8 pad_0[0x50];
    void *unk_50;
} SwitchPlayerOwner;
extern void *func_800F5410(s32);
extern s32 func_80101E14(Actor *, f32);
extern void func_80101EE4(Actor *, f32);
extern f32 func_800D8FF8(void);
extern void func_800F7F98(s32, s32);
extern Unk80132ED0 *func_800F55D0(s32);
int func_8080093C_chswitch();

int chswitch_entrypoint_0()
{
    return (int) &D_80800DB0_chswitch;
}

int chswitch_entrypoint_1()
{
    return &D_80800DC4_chswitch;
}

void *chswitch_entrypoint_2(void)
{
    return &D_80800DD8_chswitch;
}

// Toggle on player contact; ignored while the cooldown runs.
void func_80800024_chswitch(Unk80132ED0 *handle, s32 unk_0)
{
    Actor *actor;

    actor = func_80106790(handle);
    if (!(actor->unk58 > 0.0f) && func_8008FCC8(handle) == 2) {
        actor->unk64_20 = (s32) actor->unk64_20 ^ 1;
        actor->unk58 = 2.0f;
        func_80103110(actor, 1);
    }
}

// Toggle (any hit); ignored while the cooldown runs.
void func_808000B8_chswitch(Unk80132ED0 *handle, s32 unk_0)
{
    Actor *actor;

    actor = func_80106790(handle);
    if (!(actor->unk58 > 0.0f)) {
        actor->unk64_20 = (s32) actor->unk64_20 ^ 1;
        actor->unk58 = 2.0f;
        func_80103110(actor, 1);
    }
}

// Switch pressed: remember the touching player and lock it.
void func_8080012C_chswitch(Unk80132ED0 *handle, u8 *contact)
{
    Actor *actor;
    actor = func_80106790(handle);
    if (func_8008FCC8(handle) == 1 && (int) actor->unk70_10 == 1) {
        _gcaudiolist_entrypoint_0(0);
        func_80102424(actor, 2);
        actor->actorData[4] = (u32) *(u16 *) (contact + 0x1A) >> 5;
        func_800F7F98(actor->actorData[4], 1);
    }
}

int chswitch_entrypoint_3(void *actor, s32 flag)
{
    s32 is_set;
    // Matching: the "| 0" and the empty "if" are needed for the match.
    is_set = func_800DA298(flag | 0);
    *(s32 *) ((char *) actor + 0x34) = flag;
    func_80103110(actor, 0);
    if (!actor) {
    }
    *(float *) ((char *) actor + 0x54) = 0.75f;
    {
        func_80102E08();
        return is_set;
    }
}

// Sets the game flag and sends message 7 to the linked actor.
void chswitch_entrypoint_4(Actor *actor)
{
    if (actor->unk70_10 == 2 && func_80101DDC() && !actor->unk64_20 &&
        func_800D9078(&actor->unk54)) {
        actor->unk64_20 = 1;
        func_80102424(actor, 3);
        func_80103110(actor, 0);
        func_800F7F98(actor->actorData[4], 0);
        func_800DA544(actor->actorData[7]);
        func_8010108C(actor, 7, 0);
    }
}

void func_808002B4_chswitch(s32 handle, u8 *contact)
{
    u16 raw_player;
    u8 *actor;
    u8 *actor_copy;
    u32 player;
    char *owner_slot;
    char *contact_field;
    // Matching: the extra temporaries and the "^ 0" are needed for the match.
    actor = func_80106790();
    if (func_8008FCF4(handle) == 1) {
        contact_field = (char *) contact + 0x1A;
        _gcaudiolist_entrypoint_0(0);
        owner_slot = (char *) actor + 0x28;
        func_80102424(actor, 2);
        actor_copy = actor;
        func_8010A570(actor_copy);
        func_80103110(actor, 1);
        *(u32 *) owner_slot = (player = (u32) (raw_player = *(u16 *) contact_field ^ 0) >> 5);
        func_800F7F98(player, 1);
    }
}

s32 chswitch_entrypoint_5(Actor *actor, s32 msg, s32 arg)
{
    switch (msg) {
        case 0x29:
            return func_8080093C_chswitch(actor);
        case 0x91:
            if (actor->unk70_10 == 1) {
                _gcaudiolist_entrypoint_0(0);
                func_80102424(actor, 2);
                func_8010A570(actor);
                func_80103110(actor, 1);
                actor->actorData[4] = arg;
                func_800F7F98(arg, 1);
                return 1;
            }
            return 0;
        case 0x95:
            if (func_800DA298(actor->actorData[7])) {
                func_80102424(actor, 3);
                actor->unk64_20 = 1;
                func_8010A570(actor);
            } else {
                func_80102424(actor, 1);
            }
            break;
        default:
            return 0;
    }
    return 1;
}

void chswitch_entrypoint_6(Actor *actor)
{
    s32 player;
    switch (actor->unk70_10) {
        case 1:
            break;
        case 2:
            if (func_80101DDC(actor))
                func_80102424(actor, 3);
            break;
        case 3:
            player = _plsu_entrypoint_1(*(s32 *) &actor->unk50);
            if (!actor->unk64_20 && (player + 1)) {
                if (func_800D9078(&actor->unk54)) {
                    func_800F7F98(player, 0);
                    func_800DA544(actor->actorData[7]);
                    actor->unk64_20 = 1;
                    if (actor->actorData[6])
                        func_80103110(actor, 0);
                    func_8010108C(actor, 7, 0);
                }
            } else if (!actor->unk6C_0 || !(player + 1)) {
                if (func_800D90A4(&actor->unk58)) {
                    _gcaudiolist_entrypoint_0(0);
                    func_80102424(actor, 4);
                    actor->unk64_20 = 0;
                    actor->unk54 = 0.375f;
                }
            } else
                actor->unk58 = 0.15f;
            break;
        case 4:
            if (func_80101DDC(actor)) {
                func_80103110(actor, 0);
                func_80102424(actor, 1);
                func_800DA524(actor->actorData[7]);
                *(s32 *) &actor->unk50 = 0;
                func_8010108C(actor, 8, 0);
            }
    }
    actor->unk6C_0 = 0;
}

s32 chswitch_entrypoint_7(s32 actor, s32 flag)
{
    s32 is_set;

    is_set = func_800DA298(flag);
    *(s32 *) ((char *) actor + 0x34) = flag;
    if (is_set != 0) {
        *(f32 *) ((char *) actor + 0x54) = 0.0f;
        func_80102424(actor, 3);
    } else {
        *(f32 *) ((char *) actor + 0x54) = 0.375f;
        func_80102424(actor, 1);
    }
    *(s32 *) ((char *) actor + 0x2C) = -1;
    *(s32 *) ((char *) actor + 0x50) = 0;
    *(s32 *) ((char *) actor + 0x30) = 0;
    func_80102E08(actor);
    return is_set;
}

void chswitch_entrypoint_8(u8 *actor, s32 value)
{
    *(s32 *) ((u8 *) actor + 0x2C) = value;
}

void chswitch_entrypoint_9(void *actor)
{
    int slot;
    s32 *words;
    void *base;
    void *actor_copy;
    // Matching: the if (1) block, the bare "0;", the copies and the "^ 0" are needed for the match.
    actor_copy = actor;
    if (1) {
        base = actor_copy;
        0;
        words = (s32 *) base;
        slot = 0xC;
        ((s32 *) base)[slot] = 1;
        ((s32 *) base)[slot] = words[slot] ^ 0;
    }
}

void func_80800694_chswitch(Actor *actor)
{
    f32 player_pos[3];
    s32 player;
    s32 unk_0;

    if (func_800DA298(actor->actorData[7])) {
        player = _plsu_entrypoint_0(player_pos, actor->position);
        func_80103110(actor, actor->actorData[6] == 0);
        if (!actor->unk6C_0) {
            func_80102424(actor, 3);
            if (actor->actorData[6] == 0 && player != -1) {
                actor->unk64_20 = 1;
                ((SwitchPlayerOwner *) actor)->unk_50 = func_800F5410(player);
                actor->unk6C_0 = 1;
            }
        } else {
            ((SwitchPlayerOwner *) actor)->unk_50 = func_800F5410(player);
        }
    }
}

s32 chswitch_entrypoint_10(Actor *actor, s32 msg, s32 arg)
{
    f32 unk_0[4];
    s32 other_on_pad;
    s32 unk_1;
    s32 i;

    switch (msg) {
        case 0x29:
            return func_8080093C_chswitch(actor);
        case 0x32:
            *(s32 *) &actor->unk50 = func_800F5410(arg);
            actor->unk58 = 0.15f;
            _gcaudiolist_entrypoint_0(0);
            actor->unk54 = 0.375f;
            func_80102424(actor, 2);
            func_80103110(actor, 1);
            func_800F7F98(arg, 1);
            break;
        case 0x91:
            unk_1 = func_800F55FC(arg) & 0x08000000;
            actor->unk6C_0 = func_800DA298(0x9D4);
            *(s32 *) &actor->unk50 = func_800F5410(arg);
            if (!unk_1 && actor->unk70_10 == 1 &&
                func_800F64A4(arg, actor->actorData[5]) && func_800DA298(0x9D4)) {
                if (func_800F54E4() == arg) {
                    other_on_pad = 0;
                    for (i = 0; i != 8; i++) {
                        if (func_800F6438(i) && i != arg &&
                            func_800F6C5C(i) && func_800F55D0(i) == actor->unk0) {
                            other_on_pad = 1;
                            break;
                        }
                    }
                    if (!other_on_pad) {
                        func_800F7874(arg, actor->unk0, actor->position);
                    }
                }
            }
            return 1;
        case 0x95:
            func_80800694_chswitch(actor);
            return 1;
        default:
            return 0;
    }
    return 1;
}

int func_8080093C_chswitch(actor)
Actor *actor;
{
    s32 unk_0;
    if (func_800CB854(&unk_0) == 1) {
        func_80100120(actor);
        if (!actor->unk64_17 && func_800DA298(actor->actorData[7])) {
            func_80102424(actor, 3);
            func_80102204(actor);
            actor->unk64_20 = 1;
            actor->unk6C_0 = 1;
        }
    }
    return 1;
}

void chswitch_entrypoint_11(u8 *actor)
{
    u32 state;

    state = (u32) (u16) *(u16 *) ((s8 *) actor + 0x72) >> 0xA;
    switch (state) {
        case 2:
            if (func_80101DDC(actor) != 0) {
                func_800DA544(*(s32 *) ((s8 *) actor + 0x34));
                func_80102424(actor, 3);
                func_800F7F98(*(s32 *) ((s8 *) actor + 0x28), 0);
                func_8010108C(actor, 7, 0);
            }
        case 1:
            return;
        case 3:
            if (func_800DA298(*(s32 *) ((s8 *) actor + 0x2C)) != 0) {
                func_800DA524(*(s32 *) ((s8 *) actor + 0x2C));
                _gcaudiolist_entrypoint_0(0);
                func_80102424(actor, 4);
            }
            break;
        case 4:
            if (func_80101DDC(actor) != 0) {
                func_800DA524(*(s32 *) ((s8 *) actor + 0x34));
                func_80102424(actor, 1);
                func_8010108C(actor, 8, 0);
            }
    }
}

void chswitch_entrypoint_12(Actor *actor, s32 flag, s32 reset_flag)
{
    s32 is_set;
    is_set = func_800DA298(flag);
    *(s32 *) ((u8 *) actor + 0x34) = flag;
    *(s32 *) ((u8 *) actor + 0x2C) = reset_flag;
    if (reset_flag != -1) {
        func_800DA524(reset_flag);
    }
    func_80102424(actor, is_set ? 3 : 1);
    func_80102E08(actor);
}

// Timed switch: resets itself when the timer runs out.
void chswitch_entrypoint_13(Actor *actor)
{
    f32 delta_time = func_800D8FF8();
    switch (actor->unk70_10) {
        case 1:
            if (actor->unk64_20) {
                _gcaudiolist_entrypoint_0(0);
                func_80102424(actor, 2);
            }
            if (actor->unk58 <= 0.0f) {
                func_80103110(actor, 0);
                return;
            }
            actor->unk58 -= delta_time;
            break;
        case 2:
            if (func_80101E14(actor, 0.5f)) {
                func_80102424(actor, 3);
                func_80101EE4(actor, 0.5f);
                if (!func_800F6CC8(func_800F54E4())) {
                    func_800DA544(actor->actorData[7]);
                    func_8010108C(actor, 7, 0);
                }
            }
            break;
        case 3:
            if (!actor->unk64_20) {
                _gcaudiolist_entrypoint_0(0);
                func_80102424(actor, 4);
            }
            if (actor->unk58 <= 0.0f) {
                func_80103110(actor, 0);
                return;
            }
            actor->unk58 -= delta_time;
            break;
        case 4:
            if (func_80101DDC(actor)) {
                func_800DA524(actor->actorData[7]);
                func_80102424(actor, 1);
                func_8010108C(actor, 8, 0);
            }
    }
}

s32 chswitch_entrypoint_14(Actor *actor, s32 flag)
{
    s32 is_set;
    is_set = func_800DA298(flag);
    actor->actorData[7] = flag;
    if (is_set) {
        func_80102424(actor, 3);
        func_80101EE4(actor, 0.5f);
    } else
        func_80102424(actor, 1);
    actor->unk64_20 = is_set;
    func_80103110(actor, 0);
    return is_set;
}

extern void func_80108F08();
// TU-NOTE: the overlay .data is defined here in C. The tables hold pointers to functions of this
// file, and IDO's assembler schedules some of them differently unless they are in the same unit.
// Values are taken from the ROM; D_80800DB0_chswitch is declared as int[] (same address).
int D_80800DB0_chswitch[5] = {(u32) func_80800024_chswitch, 0x0, (u32) func_808000B8_chswitch,
                              (u32) func_80108F08, 0x0};
void *D_80800DC4_chswitch = (void *) func_808002B4_chswitch;
static u32 D_80800DC4_chswitch_rest[4] = {0x0, 0x0, 0x0, 0x0};
void *D_80800DD8_chswitch = (void *) func_8080012C_chswitch;
static u32 D_80800DD8_chswitch_rest[5] = {0x0, 0x0, 0x0, 0x0, 0x0};
