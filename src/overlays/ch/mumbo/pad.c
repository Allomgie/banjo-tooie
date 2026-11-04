#include "common.h"

extern u8 D_808010C8_chmumbopad[];
extern s16 D_808010EC_chmumbopad[];
typedef union {
    s32 word;
    s16 half;
} MumboPadPayload31;
typedef struct {
    u8 pad_0[0x28];
    u32 pad_28 : 18;
    u32 unk_2A_5 : 1;
    u32 pad_2A : 13;
} MumboMarkerFlags31;
extern int D_80801110_chmumbopad[];
extern s16 D_80801060_chmumbopad[];
extern u16 D_80801084_chmumbopad[][2];
extern f32 func_80103EAC(Actor *);
typedef struct {
    u8 pad_0[0x2A];
    u8 pad_2A_6 : 2;
    u8 unk_2A_5 : 1;
    u8 pad_2A_0 : 5;
} MumboPadInfo;
extern void func_80015E80(s32, s32 *);
int func_80800674_chmumbopad();
void func_808008CC_chmumbopad();
extern void func_80101870(), func_80105834(), func_80107C2C(), func_80108ED0(),
    func_8080044C_chmumbopad();

// Maps a pad index to the spell target id used by the spell overlays.
int chmumbopad_entrypoint_0(s32 pad_index)
{
    return (s16) D_80801084_chmumbopad[pad_index][1];
}

s32 func_80800014_chmumbopad(s32 actor, s32 actor_data, s32 search_id)
{
    s32 cube;

    // Matching: the `| 0` operands are needed for the match.
    cube = _gccubesearch_entrypoint_1(search_id | 0);
    _gspropctrl_entrypoint_11(cube | 0, actor_data);
}

// True if this pad's own flag from the flag table is set.
int func_80800048_chmumbopad(Actor *actor)
{
    s16 flag;
    unsigned int flag_arg;
    flag =*(s16 *) (D_808010C8_chmumbopad + ((*(s32 *) ((char *) actor + 0x6C) & 0x1FF) * 2));
    if (flag != -1) {
        // Matching: the copy and the second argument are needed for the match.
        flag_arg = flag;
        return func_800DA298(flag_arg, flag);
    }
    return 0;
}

// True when this pad's job is done and it should hide.
int func_80800098_chmumbopad(Actor *actor)
{
    s32 flag;

    switch (actor->unk6C_0) {
        case 12:
            return func_800DA298(0x358) != 0 && func_800DA298(0x359) != 0;
        case 13:
            return func_800DA564(0x1CA, 2) != 0;
        default:
            flag = D_808010EC_chmumbopad[actor->unk6C_0];
            if (flag != -1)
                return func_800DA298(flag);
            return 0;
    }
}

// Spawn: derives the pad index from the map id (and marker variant) and sets up the pad.
void func_80800140_chmumbopad(Actor *actor)
{
    s32 map_id;

    map_id = func_800EA05C();
    switch (map_id) {
        case 0xD7:
            actor->unk6C_0 = 0;
            break;
        case 0xC7:
            actor->unk6C_0 = 1;
            break;
        case 0xB8:
            actor->unk6C_0 = 2;
            break;
        case 0xE6:
            actor->unk6C_0 = 3;
            break;
        case 0xD6:
            if (actor->pad6C_21 == 0xB4) {
                actor->unk6C_0 = 5;
            } else {
                actor->unk6C_0 = 4;
            }
            break;
        case 0x1A7:
            actor->unk6C_0 = 6;
            break;
        case 0x118:
            actor->unk6C_0 = 7;
            break;
        case 0x112:
            if (actor->pad6C_21 == 0x5D) {
                actor->unk6C_0 = 8;
            } else {
                actor->unk6C_0 = 9;
            }
            break;
        case 0x107:
            actor->unk6C_0 = 10;
            break;
        case 0x10B:
            actor->unk6C_0 = 11;
            break;
        case 0x136:
            actor->unk6C_0 = 12;
            break;
        case 0x128:
            if (actor->pad6C_21 == 0x144) {
                actor->unk6C_0 = 13;
            } else if (func_800DA298(0x376)) {
                actor->unk6C_0 = 15;
            } else {
                actor->unk6C_0 = 14;
            }
            break;
        case 0x155:
            actor->unk6C_0 = 16;
            break;
    }
    func_80103140(actor, D_80801084_chmumbopad[actor->unk6C_0][0], actor->unk0->unk16);
    func_8010A654(actor, func_800DA298(0x64D));
    if (func_80800098_chmumbopad(actor)) {
        if (func_8010CB84(actor->position, (s32) func_80103EAC(actor))) {
            func_80101FDC(actor, 2);
        } else {
            func_800FFAB0(actor);
            return;
        }
    }
    func_80800014_chmumbopad(actor, actor->actorData, D_80801060_chmumbopad[actor->unk6C_0]);
    if (func_800F5410(func_800F54E4()) != 13) {
        _subaddiefade_entrypoint_1(actor, 0x87);
    }
}

void func_8080044C_chmumbopad(actor) Actor *actor;
{
    switch (actor->unk70_10) {
        case 1:
            if (!actor->unk74_29) {
                func_80103110(actor, 0);
                if (func_80800098_chmumbopad(actor)) {
                    _subaddiefade_entrypoint_3(actor);
                    func_80101FDC(actor, 3);
                }
            }
            actor->unk74_29 = 0;
            break;
        case 2:
            if (!actor->unk74_29) {
                _subaddiefade_entrypoint_3(actor);
                func_80101FDC(actor, 3);
            }
            actor->unk74_29 = 0;
    }
}

s32 func_80800514_chmumbopad(Actor *actor, s32 msg, MumboPadPayload31 payload)
{
    switch (msg) {
        default:
            return 0;
        case 0x91:
            if (!actor->unk64_19 && !actor->unk74_29 &&
                !((MumboMarkerFlags31 *) actor->unk0)->unk_2A_5) {
                func_808008CC_chmumbopad(actor, payload.word);
            }
            func_80103110(actor, 1);
            return 1;
        case 0x32:
            func_80800674_chmumbopad(actor, payload.word);
            return 1;
        case 0xBB:
            if (payload.word == actor->unk6C_0) {
                ((MumboMarkerFlags31 *) actor->unk0)->unk_2A_5 = 0;
            }
            break;
        case 0x2E:
            if (payload.half == 0x11DE) {
                _chintrotext_entrypoint_1(0x18BD, actor->unk6C_0, 0, 1);
                actor->unk64_19 = 0;
            }
            return 0;
    }
    return 1;
}

int func_8080063C_chmumbopad(s32 actor, s32 player)
{
    func_800F7874(player, *(s32 *) actor, actor + 4, actor);
    func_800F5FA8(player);
}

// Spell cast: sends the cast message to this pad's target actor.
int func_80800674_chmumbopad(actor, player)
Actor *actor;
s32 player;
{
    func_800F7CF4(player, 0x43, actor->actorData);
    func_800C067C(0x11DD);
    if (!func_80800048_chmumbopad(actor)) {
        _subaddiedialog_entrypoint_11(actor->unk0, 0x11DE, 6, actor->position, 0);
        actor->unk64_19 = 1;
    }
    actor->unk64_20 = 1;
    actor->unk74_30 = 0;
    func_800C067C(0x11DD);
    switch (*(u32 *) ((u8 *) actor + 0x6C) & 0x1FF) {
        case 0:
        case 1:
            break;
        case 2:
            actor->unk64_20 = 0;
            break;
        case 3:
            func_80101180(0x337, 10, 0);
            break;
        case 4:
            func_80101180(0x39D, 10, 0);
            break;
        case 5:
            func_80101180(0x39C, 10, 0);
            break;
        case 6:
            func_80101180(0x297, 75, 0);
            break;
        case 7:
            func_80101180(0x292, 75, 0);
            break;
        case 8:
            func_80101180(0x28E, 75, 8);
            break;
        case 9:
            func_80101180(0x28D, 75, 9);
            actor->unk64_20 = 0;
            break;
        case 11:
            func_80101180(0x3EE, 75, 0);
            actor->unk64_20 = 0;
            break;
        case 10:
            func_80101180(0x3F5, 75, 0);
            actor->unk64_20 = 0;
            break;
        case 12:
            func_80101180(0x40E, 75, 12);
            actor->unk64_20 = 0;
            break;
        case 13:
            func_80101180(0x346, 75, 0);
            break;
        case 14:
            func_80101180(0x45A, 75, 0);
            break;
        case 15:
            func_80101180(0x457, 75, 0);
            break;
        case 16:
            func_80101180(0x4D8, 75, 0);
            break;
    }
    ((MumboPadInfo *) actor->unk0)->unk_2A_5 = !actor->unk64_20;
}

// Mumbo stands on the pad: shows the tutorial text and, on the cast button, checks the
// per-pad preconditions before casting.
void func_808008CC_chmumbopad(actor, player) Actor *actor;
s32 player;
{
    s32 input[6];

    if (func_800F54E4() == player) {
        if (func_800F5410(player) == 0xD) {
            func_80015E80(0, input);
            actor->unk74_29 = 1;
            if (!func_800DA298(0x9B)) {
                func_800DA544(0x9B);
                _subaddiedialog_entrypoint_11(actor->unk0, 0x11DD, 6, actor->position, 0);
            }
            if (input[1] == 1 && !actor->unk64_20 && !func_800DA298(0x9DE)) {
                switch (actor->unk6C_0) {
                    case 0:
                        if (!func_800DA298(0x95)) {
                            func_8080063C_chmumbopad(actor, player);
                        }
                        break;
                    case 1:
                        if (!func_800DA564(0x4FC, 4)) {
                            func_8080063C_chmumbopad(actor, player);
                        }
                        break;
                    case 2:
                        func_8080063C_chmumbopad(actor, player);
                        return;
                    case 3:
                        func_8080063C_chmumbopad(actor, player);
                        return;
                    case 4:
                        func_8080063C_chmumbopad(actor, player);
                        return;
                    case 5:
                        func_8080063C_chmumbopad(actor, player);
                        return;
                    case 6:
                        if (!func_800DA298(0xE9)) {
                            func_8080063C_chmumbopad(actor, player);
                        }
                        break;
                    case 7:
                        if (!func_800DA298(0x15F)) {
                            func_8080063C_chmumbopad(actor, player);
                        }
                        break;
                    case 8:
                        if (!func_800DA298(0x160)) {
                            func_8080063C_chmumbopad(actor, player);
                        }
                        break;
                    case 9:
                        func_8080063C_chmumbopad(actor, player);
                        return;
                    case 11:
                        if (!func_800DA298(0xA05) && !func_800DA298(0x329)) {
                            if (!func_800DA298(0xA06)) {
                                func_8080063C_chmumbopad(actor, player);
                                return;
                            }
                            if (!actor->unk74_30) {
                                actor->unk74_30 = 1;
                                _subaddiedialog_entrypoint_11(actor->unk0, 0x11E9, 0xE,
                                                              actor->position, 0x10);
                            }
                        }
                        break;
                    case 10:
                        if (!func_800DA298(0xA06)) {
                            if (!func_800DA298(0xA05)) {
                                func_8080063C_chmumbopad(actor, player);
                                return;
                            }
                            if (!actor->unk74_30) {
                                actor->unk74_30 = 1;
                                _subaddiedialog_entrypoint_11(actor->unk0, 0x11E9, 0xE,
                                                              actor->position, 0x10);
                            }
                        }
                        break;
                    case 12:
                        if (!func_800DA298(0x1E1) || !func_800DA298(0x358) ||
                            !func_800DA298(0x359) || !func_800DA298(0x35A)) {
                            func_8080063C_chmumbopad(actor, player);
                        }
                        break;
                    case 13:
                        if (!func_800DA564(0x1CA, 2)) {
                            func_8080063C_chmumbopad(actor, player);
                        }
                        break;
                    case 14:
                        if (func_800DA298(0x375) && !func_800DA298(0x376)) {
                            func_8080063C_chmumbopad(actor, player);
                            return;
                        }
                        if (!actor->unk74_30) {
                            actor->unk74_30 = 1;
                            _subaddiedialog_entrypoint_11(actor->unk0, 0x11EC, 0xE,
                                                          actor->position, 0x10);
                        }
                        break;
                    case 15:
                        if (!func_800DA298(0x373) && func_800DA298(0x6B4)) {
                            func_8080063C_chmumbopad(actor, player);
                            return;
                        }
                        if (!actor->unk74_30) {
                            actor->unk74_30 = 1;
                            _subaddiedialog_entrypoint_11(actor->unk0, 0x11EC, 0xE,
                                                          actor->position, 0x10);
                        }
                        break;
                    case 16:
                        if (func_800DA298(0x4F3) && !func_800DA298(0x15E)) {
                            if (!func_800C0638()) {
                                if (func_800DA298(0x189)) {
                                    func_8080063C_chmumbopad(actor, player);
                                    return;
                                }
                                if (func_800DA298(0x6DB)) {
                                    _subaddiedialog_entrypoint_11(actor->unk0, 0x150E, 0xE,
                                                                  actor->position, 0x10);
                                    return;
                                }
                                _subaddiedialog_entrypoint_11(actor->unk0, 0x150F, 0xE,
                                                              actor->position, 0x10);
                                func_800DA544(0x6DB);
                            }
                        } else if (!func_800C0638()) {
                            if (func_800DA298(0x6DC)) {
                                _subaddiedialog_entrypoint_11(actor->unk0, 0x150D, 0xE,
                                                              actor->position, 0x10);
                                return;
                            }
                            _subaddiedialog_entrypoint_11(actor->unk0, 0x150C, 0xE,
                                                          actor->position, 0x10);
                            func_800DA544(0x6DC);
                        }
                }
            }
        } else if (!func_800DA298(0x9A)) {
            func_800DA544(0x9A);
            _subaddiedialog_entrypoint_11(actor->unk0, 0x11DC, 6, actor->position, 0);
        }
    }
}

int chmumbopad_entrypoint_1()
{
    return (int) &D_80801110_chmumbopad;
}

// TU-NOTE: the .data of this overlay is defined here in C. Tables holding function pointers must be
// in the same unit, otherwise IDO's assembler schedules those functions differently.
// D_80801110_chmumbopad is declared as int[] above.
s16 D_80801060_chmumbopad[18] ={0x2A5, 0x17E, 0x163, 0x154, 0x154, 0x154, 0x297, 0x292, 0x28E,
                                 0x28D, 0x3F5, 0x3EE, 0x40E, 0x346, 0x45A, 0x457, 0x4D8, 0x0};
u16 D_80801084_chmumbopad[17][2] = {0x7D8, 0x9D5, 0x7D8, 0x9D5, 0x7E0, 0x9DF, 0x7D9, 0x9E0, 0x7D9,
                                    0x9E0, 0x7D9, 0x9E0, 0x7DB, 0x9E2, 0x7DC, 0x9E5, 0x7DC, 0x9E5,
                                    0x7DC, 0x9E5, 0x7DE, 0x9E3, 0x7DE, 0x9E3, 0x7DD, 0x9E4, 0x7DA,
                                    0x9E9, 0x7DA, 0x9E9, 0x7DA, 0x9E9, 0x7DF, 0x9DE};
u8 D_808010C8_chmumbopad[36] = {0xFF, 0xFF, 0xFF, 0xFF, 0x5,  0x7C, 0xFF, 0xFF, 0xFF,
                                0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
                                0x5,  0x7D, 0x5,  0x7E, 0x5,  0x7F, 0x5,  0x80, 0xFF,
                                0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x0,  0x0};
s16 D_808010EC_chmumbopad[18] = {0x95, 0x4FC, -0x1,  0xEA, 0xEC, 0xEB, 0xE9,  0x15F, 0x160,
                                 -0x1, 0x1B8, 0x329, -0x1, -0x1, -0x1, 0x373, 0x15E, 0x0};
int D_80801110_chmumbopad[20] = {0x21002B0,
                                 -0xFFFF,
                                 0x0,
                                 (u32) func_8080044C_chmumbopad,
                                 (u32) func_80105834,
                                 (u32) func_80101870,
                                 0x0,
                                 0x0,
                                 0x0,
                                 0x181C,
                                 0x0,
                                 (u32) func_80108ED0,
                                 0x0,
                                 (u32) func_80800140_chmumbopad,
                                 (u32) func_80107C2C,
                                 -0x7FFFD3FE,
                                 (u32) func_80800514_chmumbopad,
                                 0x0,
                                 0x0,
                                 0x0};
