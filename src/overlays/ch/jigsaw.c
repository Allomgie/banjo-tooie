#include "common.h"

extern s32 func_8010A6B0(Actor *, s32);
extern void func_80108B04(Actor *, s32);
extern f32 func_800D8FF8(void);
extern void func_800EFA4C(f32 *, f32, f32, f32);
extern void func_801015D0(Actor *);
extern void *func_800DE448(f32 *, f32 *, f32, f32 *, s32);
extern int D_80800770_chjigsaw[];
extern int D_808007B8_chjigsaw[];
extern f32 func_800DC0C0(void);
extern f32 func_800DC178(f32, f32);
extern void func_800EE7F8(f32[3], f32[3]);
extern void func_800EF214(f32[3], f32, f32, f32);
extern void func_800BABB8(s32, f32[3], f32[3], f32, void *);
extern void *_fxgenlist_entrypoint_1(void);

typedef struct {
    u32 pad_0 : 28;
    u32 unk_78 : 1;
    u32 pad_1 : 3;
} CodexJigsawFlags65;

// Message 0x3E handler: calls suautobaddies unless flag 0x665 is set.
void func_80800000_chjigsaw(Actor *actor, void *msg)
{
    if (func_8010A6B0(actor, (u32) *(u16 *) ((u8 *) msg + 0x1A) >> 5)) {
        if (!func_800DA298(0x665)) {
            func_80108B04(actor, 0);
            func_800D0BD4((s32) actor->unk50, 1);
            _suautobaddies_entrypoint_3();
        }
    }
}

void func_80800070_chjigsaw(u8 *actor)
{
    if (func_800D0B68((s32) *(f32 *) ((s8 *) actor + 0x50), 1) != 0) {
        func_800FFAB0(actor);
        return;
    }
    func_800D05E4((s32) *(f32 *) ((s8 *) actor + 0x50), 1, *(s32 *) ((s8 *) actor + 0));
    if (*(f32 *) ((s8 *) actor + 0x58) != 0.0f) {
        func_800FC6B0(0x18);
    }
    func_800D0778((s32) *(f32 *) ((s8 *) actor + 0x50), 1, actor + 4);
}

// Spin at 230 deg/s, wrapping at 360.
void func_8080011C_chjigsaw(u8 *actor)
{
    *(f32 *) (actor + 0x54) += func_800D8FF8() * 230.0f;
    if (*(f32 *) (actor + 0x54) >= 360.0f) {
        *(f32 *) (actor + 0x54) -= 360.0f;
    }
}

// Cleanup: collectible registry entry and light.
int func_8080017C_chjigsaw(Actor *actor)
{
    s32 registry_index;
    s32 flags;
    unsigned short light_id;
    registry_index = *(f32 *) ((char *) actor + 0x50);
    func_800D05E4(registry_index, 1, 0);
    flags = *(s32 *) ((char *) actor + 0x6C);
    light_id = flags & 0x1FF;
    if (light_id) {
        // Matching: "| 0" is needed for the match.
        func_800C8B84(light_id | 0);
    }
}

void func_808001D0_chjigsaw(s32 actor)
{
    func_80105834();
    func_8080011C_chjigsaw(actor);
}

// Update: drop to the floor, twinkle, spawn particles, move the light.
void func_808001F8_chjigsaw(Actor *actor)
{
    s32 i;
    f32 delta_time;
    f32 probe_top[3];
    f32 probe_bottom[3];
    f32 floor_hit[3];
    f32 twinkle_pos[3];
    f32 angle;
    f32 light_pos[3];
    s32 emitter;

    delta_time = func_800D8FF8();
    if (((CodexJigsawFlags65 *) ((u8 *) actor + 0x78))->unk_78) {
        func_800D0778((s32) actor->unk50, 1, actor->position);
    } else if (actor->unk64_19) {
        func_800EE7F8(probe_top, actor->position);
        probe_top[1] += 100.0f;
        func_800EE7F8(probe_bottom, actor->position);
        probe_bottom[1] -= 100.0f;
        if (func_800BEF00(probe_top, probe_bottom, floor_hit, actor->unk14)) {
            actor->position[1] = probe_bottom[1];
        } else {
            actor->position[1] += ((f32 *) actor->actorData)[7] * delta_time;
        }
    }
    if (actor->unk7C_12) {
        for (i = 0; i != 4; i++) {
            if (func_800DC0C0() < 0.015f) {
                func_80103DFC(actor, twinkle_pos);
                angle = func_800DC178(0.0f, 360.0f);
                func_800EF214(twinkle_pos, angle, func_800DC178(0.0f, 360.0f), 40.0f);
                _fxtwinkle_entrypoint_0(twinkle_pos);
            }
        }
        if (actor->unk58 > 0.0f) {
            if (func_800DC0C0() < 2.0f * (actor->unk58 / 3.0f)) {
                emitter = func_800B5BE4(0x10);
                func_800BABB8(emitter, actor->position, actor->position, 1.0f,
                              _fxgenlist_entrypoint_1());
                func_800BA22C(emitter, 1);
            }
            actor->unk58 -= delta_time;
        }
    }
    if (actor->unk70_10 == 1) {
        // Matching: empty block steers IDO's register allocation.
        if (1) {
        }
        if (((CodexJigsawFlags65 *) ((u8 *) actor + 0x78))->unk_78 && actor->unk6C_0) {
            func_800EE7F8(light_pos, actor->position);
            light_pos[1] += 100.0f;
            func_800C8CB8(actor->unk6C_0, light_pos);
        }
        func_8080011C_chjigsaw(actor);
    }
}

void func_808004A0_chjigsaw(Actor *actor, void *unk_1)
{
    f32 rotation[3];
    func_800EFA4C(rotation, 0.0f, actor->unk54, 0.0f);
    func_80101970(actor);
    func_800DF47C(func_801015D0, actor);
    func_800DE448(actor->position, rotation, actor->scale, NULL, func_8010347C(actor->unk0));
}

s32 func_80800518_chjigsaw(Actor *actor, s32 msg_id, s32 data)
{
    f32 light_pos[3];

    switch (msg_id) {
        case 0x3E:
            func_80800000_chjigsaw(actor, *(s32 *) &data);
            break;
        case 0x12:
            actor->unk64_19 = data;
            break;
        case 0x13:
            actor->unk50 = data;
            break;
        case 0x14:
            if (data) {
                actor->unk58 = 3.0f;
            } else {
                actor->unk58 = 0.0f;
            }
            break;
        case 0x3D:
            _chjigsawcollect_entrypoint_1(&actor, (s32) actor->unk50,
                                          (*(u32 *) ((u8 *) actor + 0x70) & 1));
            func_800FFAB0(actor);
            break;
        case 0x55:
            actor->unk6C_0 = func_800C8A98();
            func_800CF9E4((s32) actor->unk50, 1, actor->unk6C_0);
            func_800EE7F8(light_pos, actor->position);
            light_pos[1] += 100.0f;
            func_800C8CB8(actor->unk6C_0, light_pos);
            break;
        default:
            return 0;
    }
    return 1;
}

int chjigsaw_entrypoint_0()
{
    return (int) &D_80800770_chjigsaw;
}

// Second actor: shows text 0xD0A once and unlocks replay entry 0x85, except in replay mode.
int func_808006CC_chjigsaw(s32 actor)
{
    if (func_800D395C()) {
        func_800FFAB0(actor);
    } else {
        if (_subaddiedialog_entrypoint_16()) {
            if (_subaddiedialog_entrypoint_11(0, 0xD0A, 0, actor + 4, 0x6F) != 0) {
                _gcfrontend_entrypoint_9(0x85);
                func_800FFAB0(actor);
            }
        }
    }
}

int chjigsaw_entrypoint_1()
{
    return (int) &D_808007B8_chjigsaw;
}

// TU-NOTE: this overlay's .data is defined here in C. Its tables point to functions of this file,
// and IDO's assembler schedules some of them differently unless they share the unit.
// D_80800770_chjigsaw and D_808007B8_chjigsaw are declared as int[].
extern void func_80108ED0();
extern void func_80107C2C();
extern void func_8010A730();
int D_80800770_chjigsaw[18] = {0x52021F,
                               0x6100001,
                               0x0,
                               (u32) func_808001F8_chjigsaw,
                               (u32) func_808001D0_chjigsaw,
                               (u32) func_808004A0_chjigsaw,
                               0xDAC0000,
                               0x3F666666,
                               0x0,
                               0x200004,
                               (u32) func_8080017C_chjigsaw,
                               (u32) func_80108ED0,
                               0x0,
                               (u32) func_80800070_chjigsaw,
                               (u32) func_80107C2C,
                               -0x77FF8FFC,
                               (u32) func_80800518_chjigsaw,
                               0x0};
int D_808007B8_chjigsaw[18] = {0x1580524,
                               0x1,
                               0x0,
                               (u32) func_808006CC_chjigsaw,
                               0x0,
                               (u32) func_8010A730,
                               0x0,
                               0x3F666666,
                               0x0,
                               0x4,
                               0x0,
                               0x0,
                               0x0,
                               0x0,
                               (u32) func_80107C2C,
                               0x0,
                               0x0,
                               0x0};
