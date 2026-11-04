// Most likely the Hailfire Peaks Oil Drill puzzle: the drill (bit in Waste Disposal, rig
// elsewhere) and the switch that starts it. A hit stops the drill and releases the Jiggy.
#include "common.h"

extern s32 D_80801404_choildrill[];
extern void _choildrill_entrypoint_0();
extern f32 func_800C6920(f32 *, f32, f32, s32);
extern s32 func_800BABB8(s32, f32 *, f32 *, f32, s32 *);
extern s32 func_800D90A4(f32 *);
extern void func_800EE7F8(f32 *, f32 *);
extern f32 func_800DC0C0(void);
extern u8 D_8080149C_choildrill[];
extern u8 D_80801490_choildrill[];
extern f32 func_800F10B4(f32, f32, f32, f32, f32);
extern f32 func_800DC178(f32, f32);
extern f32 func_80013970(f32);
extern void func_800EEC30(f32 *, f32, f32, f32);
extern void func_800EFE50(f32 *, void *, void *, f32);
extern void func_800DE498(void *, f32 *, f32 *, f32, s32, void *);
typedef struct {
    u8 pad[0x65];
    u8 pad65 : 3;
    u8 flag : 1;
    u8 rest : 4;
} DrillS;
extern void _chswitch_entrypoint_7(DrillS *, s32);
extern void _chswitch_entrypoint_9(DrillS *);
extern int D_808014F0_choildrill[];
extern void func_800EFA4C(f32 *, f32, f32, f32);
typedef struct {
    f32 v[3];
} OilVector;
typedef struct {
    f32 time, speed;
    u8 event;
    u8 pad[3];
    f32 volume;
} OilKey;
typedef struct {
    void *marker;
    f32 position[3];
    u8 pad10[8];
    f32 origin[3];
    f32 soundTimer;
    f32 field28, soundPeriod, field30, speed;
    u8 pad38[16];
    f32 angle, field4C, phase, previousPhase, timer;
    u8 pad5C[22];
    unsigned short state : 6;
    unsigned short stateLow : 10;
    u16 pad74;
    unsigned short key : 9;
    unsigned short keyLow : 7;
    unsigned flags78 : 8;
    unsigned bounces : 4;
    unsigned flags79 : 20;
    unsigned flags7C : 19;
    unsigned sparkle : 1;
    unsigned flags7CLow : 12;
} OilActor;
extern OilVector D_80801300_choildrill;
extern OilKey D_8080130C_choildrill[];
extern f32 func_800D8FF8(void);
extern f32 func_800136E4(f32);
extern s32 func_800D91EC(f32 *, f32);
extern void func_800EF214(f32 *, f32, f32, f32);
extern void func_800E0AFC(void *, s32, f32, f32, f32, f32);
extern void *func_8010262C(void *, s32);
extern s32 func_800BBCB8(f32 *, f32 *, f32, s32, s32 *);
extern u8 D_8080138C_choildrill[];
extern f32 D_808013D0_choildrill[];
extern s32 D_80801398_choildrill[];
extern void func_800C4140();
extern s32 D_80801450_choildrill[];
extern void _subaddieaudioloop_entrypoint_0(Actor *, f32);
void func_808007DC_choildrill(Actor *param_0, f32 param_1, s32 param_2);
int func_808009F8_choildrill();
void func_80800CF0_choildrill(Actor *param_0, u8 param_1, f32 param_2);

// Oil drill actor: init, state machine (spin-up, running, bounces, spin-down), sounds, particles.
// Init: in map 0x111 the drill bit, elsewhere the oil rig.
void func_80800000_choildrill(Actor *actor)
{
    f32 bone_pos[3];
    f32 unk_0[3];

    if (func_800EA05C() == 0x111) {
        if (func_800D0B68(0x42, 1)) {
            func_800FFAB0(actor);
        } else if (func_800D0A9C(0x42, 1)) {
            func_808009F8_choildrill(actor, 8);
        } else {
            func_808009F8_choildrill(actor, 1);
        }
    } else {
        func_808009F8_choildrill(actor, 2);
        if (func_800DA298(0x351)) {
            func_80103110(actor, 0);
        } else {
            _subaddieskeleton_entrypoint_0(actor, 0x2B, bone_pos);
            func_800EFA4C((f32 *) actor->actorData, bone_pos[0], bone_pos[1] - 5000.0f, bone_pos[2]);
            func_800BEF00(bone_pos, (f32 *) actor->actorData, unk_0, 0);
        }
    }
}

void func_8080097C_choildrill();

void func_808008AC_choildrill();

// Matching: the line breaks in this function are needed for the match.
void func_80800104_choildrill(OilActor *drill)
{
    s32 key_reached;
    s32 event_5;
    OilVector bounce_dir;
    s32 event_2;
    f32 rock_a;
    f32 rock_b;
    f32 sparkle_pos[3];
    void *model;
    f32 blend;
    f32 rand_angle;
    s32 i;
    f32 value;
    s32 event_9;

    switch (drill->state) {
        case 1:
        func_800FFAB0(drill);
        break;
        case 4:
        key_reached = func_800D91EC(&drill->timer, D_8080130C_choildrill[drill->key].time);
        drill->speed = func_800F10B4(drill->timer,
        D_8080130C_choildrill[drill->key - 1].time,
        D_8080130C_choildrill[drill->key].time,
        D_8080130C_choildrill[drill->key - 1].speed,
        D_8080130C_choildrill[drill->key].speed) * 180.0f;
        if (drill->timer > 3.0f) {
            func_808007DC_choildrill(drill,
            func_800F10B4(drill->speed, 0.0f, 180.0f, 0.2f, 0.5f), 1);
        }
        if (key_reached) {
            if (D_8080130C_choildrill[drill->key].event) {
                func_80800CF0_choildrill(drill, D_8080130C_choildrill[drill->key].event,
                D_8080130C_choildrill[drill->key].volume);
            }
            drill->key++;
            if (D_8080130C_choildrill[drill->key].time == -1.0f) {
                func_808009F8_choildrill(drill, 5);
            }
        }
        break;
        case 5:
        if (func_800D90A4(&drill->soundTimer)) {
            func_800C3F48(0x8CBB5BE9);
            drill->soundTimer = drill->soundPeriod = func_800DC178(0.4f, 0.5f);
        }
        func_800D90A4(&drill->timer);
        func_808007DC_choildrill(drill, 0.5f, 1);
        break;
        case 6:
        bounce_dir = D_80801300_choildrill;
        if (func_800D90A4(&drill->timer)) {
            drill->bounces--;
            if (drill->bounces == 0) {
                func_800C3F48(0x7FFFFC09);
                func_808009F8_choildrill(drill, 7);
                func_800EE7F8(drill->position, drill->origin);
            } else {
                func_800C3F48(0x7FFFFC0A);
                drill->timer = 0.75f;
            }
            func_808008AC_choildrill(drill->position);
        }
        if (drill->bounces) {
            blend = func_800F10B4(drill->timer, 0.75f, 0.0f, 0.25f, 0.0f);
            func_800EFE50(drill->position, drill->origin, bounce_dir.v,
            func_800F10B4((f32)drill->bounces - 1, 3.0f, 0.0f, 1.0f, 0.0f) + blend);
            value = func_800F10B4(drill->timer, 0.75f, 0.0f, 0.0f, 180.0f);
            drill->position[1] += func_80013970(value) * drill->bounces * 50.0f;
        }
        break;
        case 7:
        func_8080097C_choildrill(drill);
        break;
        case 8:
        func_8080097C_choildrill(drill);
        break;
        case 9:
        drill->speed = func_800F10B4(drill->timer, 4.0f, 0.0f, 180.0f, 0.0f);
        if (func_800D90A4(&drill->timer)) {
            func_808009F8_choildrill(drill, 2);
            func_80103110(drill, 0);
        }
    }
    if (*(u16 *)((u8 *)drill->marker + 0x14) == 0x91F) {
        value = func_800D8FF8();
        drill->phase += drill->speed * value;
        if (drill->phase >= 360.0f) drill->phase -= 360.0f;
        event_9 = (drill->phase > 272.0f && drill->previousPhase < 272.0f) ? 9 : 0;         event_5 = (drill->phase > 92.0f && drill->previousPhase < 92.0f) ? 5 : 0;         event_2 = (drill->phase > 180.0f && drill->phase < 270.0f) ? 2 : 0;         func_80800CF0_choildrill(drill, event_2 | event_5 | event_9,
        func_800F10B4(drill->speed, 0.0f, 180.0f, 0.8f, 1.1f));
        drill->previousPhase = drill->phase;
        model = func_8010262C(drill->marker, 2);
        if (model) {
            value = func_80013970(drill->phase);
            rock_a = func_800136E4(value * 20.0f);
            rock_b = func_800136E4(-rock_a);
            func_800E0AFC(model, 0x2A, -1.0f, rock_a, 0.0f, 0.0f);
            func_800E0AFC(model, 0x2B, -1.0f, rock_b, 0.0f, 0.0f);
        }
    } else {
        if (drill->sparkle) {
            for (i = 0; i != 4; i++) {
                if (func_800DC0C0() < 0.015f) {
                    func_80103DFC(drill, sparkle_pos);
                    rand_angle = func_800DC178(0.0f, 360.0f);
                    func_800EF214(sparkle_pos, rand_angle,
                    func_800DC178(0.0f, 360.0f), 40.0f);
                    _fxtwinkle_entrypoint_2(sparkle_pos, 0x9E2);
                }
            }
        }
        value = func_800D8FF8();
        drill->angle += value * 230.0f;
        drill->angle = func_800136E4(drill->angle);
    }
}

void func_808007DC_choildrill(Actor *actor, f32 unk_1, s32 active)
{
    if (active) {
        _subaddieaudioloop_entrypoint_4(actor, actor->position, 1, D_8080138C_choildrill);
        _subaddieaudioloop_entrypoint_0(actor, unk_1);
        if (func_800DC0C0() < 0.4f)
            func_800BBCB8(D_808013D0_choildrill, 0, 1.0f, 1, D_80801398_choildrill);
    } else
        _subaddieaudioloop_entrypoint_2(actor);
}

int choildrill_entrypoint_0(s32 unk_0, unsigned int pos)
{
    extern f32 D_808013DC_choildrill[];
    func_800BBCB8(pos, 0, 1.0f, 1, &D_808013DC_choildrill);
}

void func_808008AC_choildrill(f32 pos[3])
{
    s32 effect;
    f32 saved_y;

    effect = func_800B53A4(8);
    saved_y = pos[1];
    pos[1] = func_800C6920(pos, 200.0f, -200.0f, 0) + 5.0f;
    func_800BABB8(effect, pos, pos, 1.0f, D_80801404_choildrill);
    func_800BA4D0(effect, (s16) pos[1]);
    func_800BA544(effect, _choildrill_entrypoint_0);
    func_800BA22C(effect, 8);
    choildrill_entrypoint_0(0, (u32) pos);
    pos[1] = saved_y;
}

void func_8080097C_choildrill(Actor *actor)
{
    f32 pos[3];
    f32 delay;
    if (func_800D90A4(&actor->unk58)) {
        func_800EE7F8(pos, actor->position);
        pos[1] = func_800C6920(pos, 200.0f, -200.0f, 0) + 5.0f;
        choildrill_entrypoint_0(0, pos);
        delay = func_800DC0C0();
        actor->unk58 = delay + delay;
    }
}

void func_80800B90_choildrill();

// Enter a drill state.
int func_808009F8_choildrill(actor, state)
Actor *actor;
s32 state;
{
    f32 period;
    switch (state) {
        case 1:
            func_80800B90_choildrill(actor);
            *(u8 *) ((u8 *) actor + 0x65) &= ~1;
            break;
        case 2:
            actor->unk50 = 0.0f;
            actor->unk54 = 0.0f;
            *(f32 *) ((u8 *) actor + 0x34) = 0.0f;
            break;
        case 4:
            actor->unk58 = 0.0f;
            _capod_entrypoint_13(actor->unk0, 0, 0x54, 0x810);
            func_800C3F48(0x7FFFFD1C);
            actor->unk74_7 = 1;
            break;
        case 5:
            func_800FC6B0(0x18);
            *(f32 *) ((u8 *) actor + 0x34) = 180.0f;
            period = func_800DC178(0.4f, 0.5f);
            *(f32 *) ((u8 *) actor + 0x2C) = period;
            *(f32 *) ((u8 *) actor + 0x24) = period;
            actor->unk58 = 5.0f;
            break;
        case 6:
            func_800EE7F8(actor->actorData, actor->position);
            func_80800B90_choildrill(actor);
            actor->unk79_4 = 4;
            actor->unk58 = 0.75f;
            break;
        case 7:
            actor->unk58 = 2.0f * func_800DC0C0();
            break;
        case 8:
            func_80800B90_choildrill(actor);
            actor->unk58 = 2.0f * func_800DC0C0();
            break;
        case 9:
            *(f32 *) ((u8 *) actor + 0x34) = 180.0f;
            actor->unk58 = 4.0f;
            func_808007DC_choildrill(actor, 0.0f, 0);
    }
    func_80102424(actor, state);
}

void func_80800B90_choildrill(u8 **actor)
{
    func_8010A624();
    func_8010A590(actor);
    func_80103140(actor, 0x610, *(u16 *) ((s8 *) *actor + 0x16));
}

// Messages: hit by actor 0x54 stops the drill and releases jiggy 0x42.
s32 func_80800BCC_choildrill(s32 *actor, s32 message, s32 source)
{
    switch (message) {
        case 0xB:
            if (source == 0x54) {
                func_808009F8_choildrill(actor, 9);
                func_800D1000(0x42, 1, actor + 1, 3, 0);
                _glcutDll_entrypoint_6(0x111, 0x85);
            }
            return 3;
        case 0x49:
            if (source == 0x85) {
                func_808009F8_choildrill(actor, 6);
                _capod_entrypoint_13(*actor, 0, 8, 0x900);
                return 1;
            }
            return 0;
        case 0x3D:
            _chjigsawcollect_entrypoint_1(&actor, 0x42, 0);
            func_800FFAB0(actor);
            return 1;
        case 0x3E:
            func_80108B04(actor, 0);
            func_800D0BD4(0x42, 1);
            return 1;
        case 0xA:
            func_808009F8_choildrill(actor, 4);
            return 1;
        default:
            return 0;
    }
}

void func_80800CF0_choildrill(Actor *actor, u8 events, f32 volume)
{
    if (events & 4) {
        func_800C4140(((u16) (u32) (volume * 1023.0f) << 21) + 0x9C608, actor->position,
                      0x12C000FA);
    }
    if (events & 8) {
        func_800C4140(((u16) (u32) (volume * 1023.0f) << 21) + 0x9C609, actor->position,
                      0x12C000FA);
    }
    if ((events & 2) && *(f32 *) &actor->actorData[7] > 135.0f && func_8001210C(1)) {
        func_800BBCB8((f32 *) actor->actorData, (f32 *) actor->actorData, 1.0f, 1,
                      D_80801450_choildrill);
    }
}

void func_80800F08_choildrill(Actor *actor, void *unk_1)
{
    void *model;
    f32 progress;
    f32 pos[3];
    f32 rot[3];
    f32 sparkle_pos[3];
    f32 unk_0;
    f32 unk_2;
    func_80101870();
    if (actor->unk70_10 == 5) {
        model = func_800D674C(0x610);
        progress = func_800F10B4(actor->unk58, 5.0f, 0.0f, 0.0f, 1.0f);
        func_800EFE50(pos, D_80801490_choildrill, D_8080149C_choildrill, progress);
        rot[2] = 0.0f;
        rot[0] = rot[2];
        rot[1] = progress * 360.0f;
        progress = func_800F10B4(((f32 *) actor->actorData)[3], ((f32 *) actor->actorData)[5],
                                0.0f, 0.0f, 1.0f);
        unk_2 = func_800F10B4(((f32 *) actor->actorData)[5], 0.5f, 0.4f, 300.0f, 200.0f);
        pos[1] += func_80013970(180.0f * progress) * unk_2;
        unk_2 = func_800DC178(0.0f, 360.0f);
        unk_0 = func_800DC178(0.0f, 360.0f);
        func_800EEC30(sparkle_pos, unk_2, unk_0, 40.0f);
        func_800EF04C(sparkle_pos, pos);
        _fxtwinkle_entrypoint_0(sparkle_pos);
        func_800DF830(1);
        func_800DE498(unk_1, pos, rot, 1.0f, 0, model);
    }
}

int choildrill_entrypoint_1()
{
    extern int D_808014A8_choildrill[];
    return (int) &D_808014A8_choildrill;
}

// Drill switch (flag 0x351): starts the drill and gives two hint dialogs.
// Switch init, tied to flag 0x351.
void func_808010C0_choildrill(DrillS *switch_actor)
{
    _chswitch_entrypoint_7(switch_actor, 0x351);
    _chswitch_entrypoint_9(switch_actor);
    switch_actor->flag = func_800DA298(0x351);
}

// Switch messages with the two hint dialogs.
s32 func_80801110_choildrill(Actor *actor, s32 message, s32 source)
{
    if (message != 7) {
        if (message == 0x91) {
            if (func_800F6B94(func_800F54E4()) != 0) {
                if (!actor->unk74_29 && (func_800DA298(0x351) == 0)) {
                    _subaddiedialog_entrypoint_11(actor->unk0, 0x12BE, 0xC, (u8 *) actor + 4,
                                                  0x6F);
                    actor->unk74_29 = 1;
                    return _chswitch_entrypoint_10(actor, message, source);
                }
            } else if (!actor->unk74_30 && (func_800DA298(0x351) == 0)) {
                _subaddiedialog_entrypoint_11(actor->unk0, 0x12BD, 4, (u8 *) actor + 4, 0x6F);
                actor->unk74_30 = 1;
            }
            return 0;
        }
    } else {
        func_80101180(0x484, 0xA, 0);
    }
    return _chswitch_entrypoint_10(actor, message, source);
}

int *choildrill_entrypoint_2()
{
    return &D_808014F0_choildrill;
}

extern void func_80105834();
extern void func_80108ED0();
extern void func_80107C2C();
extern void _chswitch_entrypoint_6();
extern int func_80101870();
u32 D_808012B0_choildrill[20] = {0x0,        0x0,        0x0,        0x0,        0x3F800000,
                                 0x4A0000,   0x3F800000, 0x4A0000,   0x3F800000, 0x4A0000,
                                 0x3F800000, 0x4A0000,   0x3F800000, 0x4A0000,   0x3F800000,
                                 0x4A0000,   0x3F800000, 0x4A0000,   0x3F800000, 0x4A0000};
OilVector D_80801300_choildrill = {-6.46e+03f, 0.0f, 1777.0f};
OilKey D_8080130C_choildrill[8] = {
    0.0f,  0.0f, 0x0, 0x0, 0x0, 0x0, 0.0f, 2.0f,  0.0f, 0x1, 0x0, 0x0, 0x0, 0.0f,
    6.0f,  0.0f, 0x5, 0x0, 0x0, 0x0, 1.1f, 6.5f,  0.3f, 0x5, 0x0, 0x0, 0x0, 1.1f,
    7.0f,  0.1f, 0x5, 0x0, 0x0, 0x0, 1.1f, 9.0f,  0.4f, 0x1, 0x0, 0x0, 0x0, 0.0f,
    18.0f, 1.0f, 0x1, 0x0, 0x0, 0x0, 0.0f, -1.0f, 0.0f, 0x0, 0x0, 0x0, 0x0, 0.0f};
u8 D_8080138C_choildrill[12] = {0x0, 0x13, 0x4, 0xB4, 0x0, 0x1, 0x3, 0xE8, 0x27, 0x10, 0x0, 0x0};
s32 D_80801398_choildrill[14] = {0x1D09DC, 0x180000, 0x131400,   0x1E00001B, 0x12C020D,
                                 0xD001E,  0x1F5A5A, 0x5A000016, 0x12000025, 0x5000700,
                                 0x15004F, 0x99002B, 0x2820300,  0x0};
f32 D_808013D0_choildrill[3] = {-5.26e+03f, 3.6e+03f, 4.51e+03f};
f32 D_808013DC_choildrill[10] = {2.666765e-39f,  2.026122e-39f, 3.949644e-39f, 3.7615913e-37f,
                                 5.877741e-39f,  3.122766e-39f, 2.351204e-38f, 6.018553e-36f,
                                 -3.176683e-07f, -3.912045e-34f};
s32 D_80801404_choildrill[19] = {0x1D09D9, 0x1BFC18, -0x383FFD3, 0x12C0190, 0x161000,
                                 0x23001E, 0x15000C, 0xE6002B,   0x4000400, 0x2F0080,
                                 0x800000, 0x330059, 0x99,       0x31FFCE,  -0x9FFF9,
                                 0x1000B,  0x140032, 0x50000,    0x0};
s32 D_80801450_choildrill[16] = {0x1D09F4, 0x1BFE3E, -0x225FFD3, 0x9600FA, 0xD001E,  0x161400,
                                 0x2600FA, 0xFA0000, 0x1900190,  0x22,     0xB30100, 0x4C0080,
                                 0x40099,  0x70002,  0x31FFF6,   -0x1E0000};
u8 D_80801490_choildrill[12] = {0xC5, 0xAC, 0xD0, 0x0,  0x45, 0x3C,
                                0x70, 0x0,  0x45, 0x8F, 0xC0, 0x0};
u8 D_8080149C_choildrill[12] = {0xC5, 0xC2, 0xB0, 0x0,  0x45, 0x3A,
                                0x40, 0x0,  0x45, 0xCB, 0xC0, 0x0};
int D_808014A8_choildrill[18] = {0x1580484,
                                 0x91F0002,
                                 (u32) &D_808012B0_choildrill,
                                 (u32) func_80800104_choildrill,
                                 (u32) func_80105834,
                                 (u32) func_80800F08_choildrill,
                                 0xFA04E20,
                                 0x0,
                                 0x0,
                                 0x800C20,
                                 0x0,
                                 (u32) func_80108ED0,
                                 0x0,
                                 (u32) func_80800000_choildrill,
                                 (u32) func_80107C2C,
                                 -0x7FFFFBFE,
                                 (u32) func_80800BCC_choildrill,
                                 0x0};
int D_808014F0_choildrill[20] = {0x1580485,
                                 0x9320001,
                                 -0x7FEE5DE0,
                                 (u32) _chswitch_entrypoint_6,
                                 (u32) func_80105834,
                                 (u32) func_80101870,
                                 0x0,
                                 0x0,
                                 0x0,
                                 0x808,
                                 0x0,
                                 (u32) func_80108ED0,
                                 0x0,
                                 (u32) func_808010C0_choildrill,
                                 (u32) func_80107C2C,
                                 -0x7FFFD3FE,
                                 (u32) func_80801110_choildrill,
                                 0x0,
                                 0x0,
                                 0x0};
