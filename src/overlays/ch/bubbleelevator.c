#include "ch/bubbleelevator.h"

#define ELEVATOR_DATA(arg0) ((BubbleElevatorActorData *) (arg0->actorData))

extern f32 func_80013970(f32);
extern f32 func_800138D0(f32);
extern BubbleWarpData D_80800C20_chbubbleelevator[2];
extern u32 D_80800C50_chbubbleelevator[2];
extern u32 D_80800C58_chbubbleelevator[];

// Setup
void func_80800000_chbubbleelevator(Actor *actor)
{
    s32 unk_0;
    Prop *prop;
    s32 unk_1;
    MapId map_id;

    ELEVATOR_DATA(actor)->unkC = actor->position[1];
    prop = _gccubesearch_entrypoint_0(0x299, actor);
    if (prop != 0) {
        _gspropctrl_entrypoint_11(prop, ELEVATOR_DATA(actor)->unk0);
    }
    map_id = func_800EA05C();
    // Selects the warp table entry: 1 in CCL, 0 in the Wasteland
    if (map_id != MAP_136_CCL_CLOUD_CUCKOOLAND) {
        if (map_id == MAP_15A_IOH_WASTELAND) {
            actor->unk79_4 = 0;
        }
    } else {
        actor->unk79_4 = 1;
    }
    // World 7 unlocked
    if (_sujiggy_entrypoint_20(7) != 0) {
        func_800DA544(FLAG_399_PROGRESS_OPENED_WORLD_CCL);
    }
    // World-open cheat
    unk_1 = func_800D3E40(0xB) != 0;
    if (unk_1 != 0) {
        unk_1 = _glcutDll_entrypoint_19(0x81) == 0;
    }
    if ((func_800DA298(FLAG_399_PROGRESS_OPENED_WORLD_CCL) == 0) && (unk_1 == 0)) {
        func_808004DC_chbubbleelevator(actor, 8);
    } else if (func_800DA298(FLAG2_6CA_USING_BUBBLEELEVATOR) != 0) {
        // Flag is set while the player is riding the elevator
        func_808004DC_chbubbleelevator(actor, 1);
    } else {
        func_808004DC_chbubbleelevator(actor, 4);
    }
    actor->unk50 = 0.0f;
    actor->unk54 = 0.0f;
}

// Update
void func_80800124_chbubbleelevator(Actor *actor)
{
    s32 push_player;
    f32 player_pos[3];

    func_808008A8_chbubbleelevator(actor);
    switch (actor->unk70_10) {
        case 1:
            if (func_800D90A4(&actor->unk58) != 0) {
                func_808004DC_chbubbleelevator(actor, 2);
            }
            _subaddieaudioloop_entrypoint_4(actor, actor->position, 1, D_80800C50_chbubbleelevator);
            _subaddieaudioloop_entrypoint_0(
                actor, func_800F12D4(actor->unk58, 0.0f, 5.0f,
                                    D_80800C20_chbubbleelevator[(u32) actor->unk79_4].unk10,
                                    D_80800C20_chbubbleelevator[(u32) actor->unk79_4].unk14));
            func_800F8294(func_800F54E4(), actor->position);
            return;
        case 2:
            func_800F8294(func_800F54E4(), actor->position);
            return;
        case 3:
            if (ELEVATOR_DATA(actor)->unk1C < 1.0f) {
                _sudeflect_entrypoint_0(actor->position, 75.0f, 140.0f, 0x1E);
            }
            if (func_800D90A4(&ELEVATOR_DATA(actor)->unk1C) != 0) {
                func_808004DC_chbubbleelevator(actor, 4);
            }
            return;
        case 4:
            push_player = 0;
            // Player touching the bubble
            if (func_8010C500(actor) != 0) {
                // Only Banjo and Kazooie may enter
                if (func_800F64A4(func_800F54E4(), ALLOW_BK) != 0) {
                    func_808004DC_chbubbleelevator(actor, 5);
                } else {
                    // Warn once
                    if (func_800DA298(FLAG2_6EA_BUBBLE_AS_BK_WARNING) == 0) {
                        func_800DA544(FLAG2_6EA_BUBBLE_AS_BK_WARNING);
                        _subaddiedialog_entrypoint_11(actor->unk0, 0x1229, 3, actor->position, 0x6F);
                    }
                    push_player = 1;
                }
            } else {
                push_player = 1;
            }
            // Repel everyone who cannot enter
            if (push_player != 0) {
                _sudeflect_entrypoint_0(actor->position, 75.0f, 140.0f, 0x1E);
            }
            break;
        case 5:
            // Pull-in animation: wait until the player is near the bubble
            func_800F5A00(func_800F54E4(), player_pos);
            if (func_800EFFB4(actor->position, 50.0f, player_pos) != 0) {
                func_808004DC_chbubbleelevator(actor, 6);
            }
            break;
        case 6:
            if (func_800D91EC(&actor->unk58, 4.75f) != 0) {
                func_808004DC_chbubbleelevator(actor, 7);
            }
            _subaddieaudioloop_entrypoint_4(actor, actor->position, 1, D_80800C50_chbubbleelevator);
            _subaddieaudioloop_entrypoint_0(
                actor, func_800F12D4(actor->unk58, 0.0f, 5.0f,
                                    D_80800C20_chbubbleelevator[(u32) actor->unk79_4].unk10,
                                    D_80800C20_chbubbleelevator[(u32) actor->unk79_4].unk14));
            func_800F8294(func_800F54E4(), actor->position);
            return;
        case 7:
            func_800D91EC(&actor->unk58, 5.0f);
            func_808004DC_chbubbleelevator(actor, 1);
            _subaddieaudioloop_entrypoint_4(actor, actor->position, 1, D_80800C50_chbubbleelevator);
            _subaddieaudioloop_entrypoint_0(
                actor, func_800F12D4(actor->unk58, 0.0f, 5.0f,
                                    D_80800C20_chbubbleelevator[(u32) actor->unk79_4].unk10,
                                    D_80800C20_chbubbleelevator[(u32) actor->unk79_4].unk14));
            func_800F8294(func_800F54E4(), actor->position);
            return;
        case 9:
            if (func_800D90A4(&ELEVATOR_DATA(actor)->unk10) != 0) {
                // Mark the world as unlocked
                func_800DA544(FLAG_399_PROGRESS_OPENED_WORLD_CCL);
                func_808004DC_chbubbleelevator(actor, 4);
            }
            actor->scale = func_800F12D4(ELEVATOR_DATA(actor)->unk10, ELEVATOR_DATA(actor)->unk14,
                                        0.0f, 0.05f, 1.0f);
    }
}

// Enter a new state: set up timers, camera and player.
void func_808004DC_chbubbleelevator(Actor *actor, s32 state)
{
    int zero;
    Actor *actor_copy;
    f32 vec;
    switch (state) {
        case 1:
            actor->unk58 = 5.0f;
            func_808008A8_chbubbleelevator(actor);
            func_800F7B9C(func_800F54E4(), 0x7C);
            func_800F8294(func_800F54E4(), actor->position);
            func_800EFA4C(&vec, 0.0f, func_800F1DF4(actor->position, ELEVATOR_DATA(actor)->unk0),
                          0.0f);
            func_800F832C(func_800F54E4(), &vec);
            func_800F80E4(func_800F54E4(), 0);
            _capod_entrypoint_13(actor->unk0, actor->unk0,
                                 D_80800C20_chbubbleelevator[(u32) actor->unk79_4].unk0, 0x2001);
            actor->unk6C_0 = func_80015184();
            func_80015178(3);
            // Matching: extra temporary for the zero.
            zero = 0;
            ELEVATOR_DATA(actor)->unk1C = zero;
            _subaddieDll_entrypoint_4(actor, 1U);
            func_800FC6B0(0x4A);
            break;

        case 3:
            func_800C3F48(0x665F44B1);
            func_800DA524(FLAG2_6CA_USING_BUBBLEELEVATOR);
            actor->unk58 = 0.0f;
            func_808008A8_chbubbleelevator(actor);
            func_800F78EC(func_800F54E4(), ELEVATOR_DATA(actor)->unk0, 840.0f, -1500.0f);
            ELEVATOR_DATA(actor)->unk1C = 2.0f;
            actor->unk50 = 3.0f;
            _subaddieaudioloop_entrypoint_2(actor);
            func_800FC74C(0x4A);
            func_800F80E4(func_800F54E4(), 1);
            break;

        case 4:
            ELEVATOR_DATA(actor)->unk1C = 0.0f;
            actor->unk58 = 0.0f;
            _subaddieDll_entrypoint_4(actor, 0U);
            if (actor->unk6C_0 != 0) {
                func_80015178(actor->unk6C_0);
            }
            break;

        case 5:
            func_800C3F48(0x7FF194D5);
            func_800F78EC(func_800F54E4(), actor->position, 840.0f, -1500.0f);
            // Matching: pointless copy of the actor.
            actor_copy = actor;
            _subaddieDll_entrypoint_4(actor_copy, 1U);
            break;

        case 6:
            func_800C3F48(0x665F44B1);
            func_800FC6B0(0x4A);
            func_800DA544(FLAG2_6CA_USING_BUBBLEELEVATOR);
            actor->unk58 = 0.0f;
            func_808008A8_chbubbleelevator(actor);
            func_800F7B9C(func_800F54E4(), 0x7C);
            func_800F80E4(func_800F54E4(), 0);
            func_800F8294(func_800F54E4(), actor->position);
            _capod_entrypoint_13(actor->unk0, actor->unk0,
                                 D_80800C20_chbubbleelevator[(u32) actor->unk79_4].unk1, 0x4001);
            actor->unk6C_0 = func_80015184();
            func_80015178(3);
            actor->unk50 = 3.0f;
            break;

        case 7:
            _gcgoto_entrypoint_1(D_80800C20_chbubbleelevator[(u32) actor->unk79_4].mapId,
                                 D_80800C20_chbubbleelevator[(u32) actor->unk79_4].entranceId);
            _subaddieaudioloop_entrypoint_2(actor);
            func_800FC74C(0x4A);
            break;

        case 8:
            func_80103110(actor, 0);
            break;

        case 9:
            func_80103110(actor, 1);
            _subaddieDll_entrypoint_4(actor, 1U);
            actor->scale = 0.05f;
            actor->unk50 = 3.0f;
            ELEVATOR_DATA(actor)->unk10 = ELEVATOR_DATA(actor)->unk14;
            func_800C3F48(0x7FFF468B);
    }
    func_80101FDC(actor, (u32) state);
}

// Raise the bubble along its route.
void func_808008A8_chbubbleelevator(Actor *actor)
{
    actor->position[1] = func_800F12D4(actor->unk58, 0.0f, 5.0f, 0.0f,
                                      D_80800C20_chbubbleelevator[actor->unk79_4].unkC) +
                        ELEVATOR_DATA(actor)->unkC;
}

// Message handler
s32 func_8080090C_chbubbleelevator(Actor *actor, s32 msg, s32 param)
{
    switch (msg) {
        case 7:
            ELEVATOR_DATA(actor)->unk14 = param;
            func_808004DC_chbubbleelevator(actor, 9);
            return 1;
        case 11:
            if (param == D_80800C20_chbubbleelevator[(u32) actor->unk79_4].unk0) {
                func_808004DC_chbubbleelevator(actor, 3);
            }
            if ((func_800EA05C() == MAP_136_CCL_CLOUD_CUCKOOLAND) &&
                (param == D_80800C20_chbubbleelevator[(u32) actor->unk79_4].unk0 &&
                 (func_800DA298(FLAG_504_PROGRESS_CANARY_MARY_IN_CCL) == 0))) {
                return func_80101180(0x383, 0xB, param);
            }
            return 2;
        default:
            return 0;
    }
}

// Draw: wobbling bubble
void func_80800A10_chbubbleelevator(Actor *actor, s32 unk_0)
{
    f32 angle;
    f32 wobble;
    f32 pos[3];
    f32 dir[3];
    f32 scale_xy[2];

    if (actor->unk70_10 != 8) {
        func_800D90A4(&actor->unk50);
        actor->unk54 += (func_800D8FF8() * func_800F10B4(actor->unk50, 0.0f, 3.0f, 1.0f, 3.0f));
        if (actor->unk54 > 1.0f) {
            actor->unk54 = (actor->unk54 - 1.0f);
        }
        angle = actor->unk54 * 360.0f;
        wobble = func_800F10B4(actor->unk50, 0.0f, 3.0f, 0.075f, 0.200000003f);
        func_800EE7F8(pos, actor->position);
        pos[1] += 75.0f;
        func_800E3980(dir);
        func_800F18FC(pos, dir, scale_xy);
        func_800EEBF0(dir, scale_xy, 75.0f);
        func_800EF04C(pos, dir);
        scale_xy[0] = (func_80013970(angle) * wobble) + 1.0f;
        scale_xy[1] = (func_800138D0(angle) * wobble) + 1.0f;
        actor->unk7C_12 = _chbubble_entrypoint_0(unk_0, pos, scale_xy, actor->scale, 4000.0f);
    }
}

u32 *chbubbleelevator_entrypoint_0(void)
{
    return &D_80800C58_chbubbleelevator;
}

// TU-NOTE: the data tables below are defined in this file because they point to its
// functions; IDO schedules those differently otherwise. Values are from the ROM.
// D_80800C21_chbubbleelevator = D_80800C20_chbubbleelevator + 0x1, D_80800C2C_chbubbleelevator = D_80800C20_chbubbleelevator + 0xC (linker symbols).
extern void func_80105834();
extern void func_80108ED0();
extern void func_80107C2C();
BubbleWarpData D_80800C20_chbubbleelevator[2] = {0x0,    0x2,  0x0,   0x0,     0x14, 0x136,
                                                 3e+03f, 0.5f, 1.0f,  0x1F,    0x21, 0x0,
                                                 0x0,    0x5,  0x15A, -3e+03f, 1.5f, 1.0f};
u32 D_80800C50_chbubbleelevator[2] = {0x130486, 0x20000};
u32 D_80800C58_chbubbleelevator[18] = {0x3560412,
                                       0xFFFF0001,
                                       0x0,
                                       (u32) func_80800124_chbubbleelevator,
                                       (u32) func_80105834,
                                       (u32) func_80800A10_chbubbleelevator,
                                       0x3E80000,
                                       0x0,
                                       0x0,
                                       0x20001,
                                       0x0,
                                       (u32) func_80108ED0,
                                       0x0,
                                       (u32) func_80800000_chbubbleelevator,
                                       (u32) func_80107C2C,
                                       0x80000400,
                                       (u32) func_8080090C_chbubbleelevator,
                                       0x0};
