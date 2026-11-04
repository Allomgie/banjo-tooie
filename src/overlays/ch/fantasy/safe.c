// The Superstash safe in Cloud Cuckooland: its dial follows how many of the four numbered
// switches were hit; a full code turns the handle and swings the door open (FLAG_38D).
#include "common.h"

extern f32 D_80800998_chfantasysafe[];
extern void func_800EFA4C(f32 *, f32, f32, f32);
extern s32 func_800DB9B0(void);
extern void func_80101FDC(Actor *, s32);
extern s32 func_800DA298(s32);
extern void _capod_entrypoint_13(Unk80132ED0 *, s32, s32, s32);
extern void func_801015D0(Actor *);
extern s32 _glcutDll_entrypoint_20(void);
extern void func_800DF744(s32, s32);
extern int D_80800AA0_chfantasysafe[];
extern int D_80800AE8_chfantasysafe[];
typedef struct {
    f32 time;
    f32 blend;
    u8 switch_mask;
} SafeKey;
extern u8 D_808009AC_chfantasysafe[];
extern u8 D_808009D4_chfantasysafe[];
extern u8 D_808009DC_chfantasysafe[];
extern u8 D_808009F4_chfantasysafe[];
extern u8 D_808009FC_chfantasysafe[];
extern SafeKey D_80800A08_chfantasysafe[];
extern u8 D_80800A98_chfantasysafe[];
extern void _subaddiedialog_entrypoint_8();
extern s32 func_800D90A4(f32 *);
extern void _subaddiedialog_entrypoint_11(Unk80132ED0 *, s32, s32, f32 *, s32);
extern void _subaddieaudioloop_entrypoint_2(Actor *);
extern void func_800FC6B0(s32);
extern void _subaddieaudioloop_entrypoint_4();
extern f32 func_800F10B4(f32, f32, f32, f32, f32);
extern void _subaddieaudioquick_entrypoint_2();
extern void func_80103110(Actor *, s32);
extern void func_800D91B8(f32 *);
extern void func_800C3F48(s32);
extern f32 func_800F12D4(f32, f32, f32, f32, f32);
extern f32 func_800F1214(f32, f32, f32);
extern s32 func_8010262C(Unk80132ED0 *, s32);
extern void func_800E0AFC(s32, s32, f32, f32, f32, f32);
extern void func_801018A4(), func_80105834(), func_80107C2C(), func_80108ED0(),
    func_80800000_chfantasysafe(), func_808001A0_chfantasysafe();

// Superstash safe init: dial angle comes from how many of the four switches were hit.
void func_80800000_chfantasysafe(actor) Actor *actor;
{
    s32 pad[2];
    s32 hit_4;
    s32 hit_1;
    s32 hit_9;
    s32 hit_8;

    func_800EFA4C(actor->position, 4539.4f, -748.6f, 2277.6f);
    if (_glcutDll_entrypoint_20()) {
        actor->actorData[4] = 0;
        actor->unk79_4 = 0;
        actor->unk58 = actor->unk54 = actor->unk50 = ((f32 *) actor->actorData)[3] =
            ((f32 *) actor->actorData)[7] = 0.0f;
        actor->rotation[1] = 228.0f;
        func_80101FDC(actor, 6);
        return;
    }
    if (func_800DA298(0x38D)) {
        actor->rotation[1] = 360.0f;
        actor->unk50 = 0.0f;
        actor->unk54 = 110.0f;
        func_80101FDC(actor, 5);
        return;
    }
    hit_8 = func_800DA298(0x38B) ? 1 : 0;
    hit_9 = func_800DA298(0x38A) ? 1 : 0;
    hit_1 = func_800DA298(0x389) ? 1 : 0;
    hit_4 = func_800DA298(0x38C) ? 1 : 0;
    actor->unk50 = ((f32 *) actor->actorData)[3] = ((f32 *) actor->actorData)[7] =
        D_80800998_chfantasysafe[hit_4 + hit_1 + hit_9 + hit_8];
    actor->unk54 = 0.0f;
    actor->rotation[1] = 228.0f;
}

// Per-frame update: states 2-4 turn the dial and then the handle, 5 is open, 6 is the cutscene.
void func_808001A0_chfantasysafe(actor) Actor *actor;
{
    s32 model;
    s32 unk_1;
    f32 blend;
    SafeKey *unk_3; // Matching: unused, the target's frame has this slot.
    s32 hit_1;
    s32 hit_9;
    s32 hit_8;
    s32 hit_4;
    f32 next_time;

    switch (actor->unk70_10) {
        case 1:
            _subaddiedialog_entrypoint_8(actor, actor->position, D_808009DC_chfantasysafe,
                                         D_808009AC_chfantasysafe, 5);
            break;
        case 2:
            if (func_800D90A4(&actor->unk58)) {
                hit_8 = func_800DA298(0x38B) ? 1 : 0;
                hit_9 = func_800DA298(0x38A) ? 1 : 0;
                hit_1 = func_800DA298(0x389) ? 1 : 0;
                hit_4 = func_800DA298(0x38C) ? 1 : 0;
                if (hit_4 + hit_1 + hit_9 + hit_8 >= 3) {
                    actor->unk58 = 1.0f;
                    func_80101FDC(actor, 3);
                    unk_1 = 0x10;
                    _subaddiedialog_entrypoint_11(actor->unk0, 0x13DD, 0, actor->position, 0);
                } else {
                    func_80101FDC(actor, 1);
                    unk_1 = 0xE;
                }
                func_800DA544(actor->unk6C_0 + 0x389);
                _subaddieaudioloop_entrypoint_2(actor);
                func_800FC6B0(unk_1);
                actor->unk50 = ((f32 *) actor->actorData)[7] = ((f32 *) actor->actorData)[3];
            } else {
                _subaddieaudioloop_entrypoint_4(actor, actor->position, 1,
                                                D_808009F4_chfantasysafe);
                actor->unk50 =
                    func_800F10B4(actor->unk58, 2.0f, 0, ((f32 *) actor->actorData)[7],
                                  ((f32 *) actor->actorData)[3]);
            }
            break;
        case 3:
            actor->unk54 = func_800F10B4(actor->unk58, 1.0f, 0, 0, 110.0f);
            if (func_800D90A4(&actor->unk58)) {
                actor->unk54 = 110.0f;
                actor->unk58 = 3.0f;
                func_80101FDC(actor, 4);
                _subaddieaudioquick_entrypoint_2(actor, actor->position,
                                                 D_808009D4_chfantasysafe);
            }
            break;
        case 4:
            if (func_800D90A4(&actor->unk58)) {
                func_80101FDC(actor, 5);
                func_800DA544(0x38D);
                _subaddieaudioloop_entrypoint_2(actor);
                _subaddieaudioquick_entrypoint_2(actor, actor->position,
                                                 D_808009D4_chfantasysafe);
            } else {
                _subaddieaudioloop_entrypoint_4(actor, actor->position, 1,
                                                D_808009FC_chfantasysafe);
            }
            actor->rotation[1] = func_800F10B4(actor->unk58, 3.0f, 0, 228.0f, 360.0f);
            break;
        case 5:
            func_80103110(actor, 0);
            break;
        case 6:
            func_800D91B8(&actor->unk58);
            next_time = D_80800A08_chfantasysafe[actor->actorData[4] + 1].time;
            if (next_time < actor->unk58) {
                actor->actorData[4]++;
                if (D_80800A08_chfantasysafe[actor->actorData[4]].blend == 0.0f) {
                    func_800C3F48(0x66538CA0);
                    func_800C3F48(0x4CB38CA1);
                } else {
                    func_800C3F48(0x66538CA1);
                }
                actor->unk79_4 = D_80800A08_chfantasysafe[actor->actorData[4]].switch_mask;
            }
            blend =
                func_800F12D4(actor->unk58, D_80800A08_chfantasysafe[actor->actorData[4]].time,
                              D_80800A08_chfantasysafe[actor->actorData[4] + 1].time,
                              D_80800A08_chfantasysafe[actor->actorData[4]].blend,
                              D_80800A08_chfantasysafe[actor->actorData[4] + 1].blend);
            actor->rotation[1] = func_800F1214(blend, 228.0f, 360.0f);
            actor->unk54 = func_800F1214(blend, 0.0f, 110.0f);
            actor->unk50 = func_800F1214(blend, 0.0f, 360.0f);
            _subaddieaudioloop_entrypoint_4(actor, actor->position, 1,
                                            D_80800A98_chfantasysafe);
    }
    model = func_8010262C(actor->unk0, 2);
    if (model) {
        func_800E0AFC(model, 0x2A, 1.0f, 0, 0.0f, actor->unk54);
        func_800E0AFC(model, 0x2B, 1.0f, 0, 0.0f, actor->unk50);
    }
}

// Messages: 0x49 = a numbered switch was hit, 0x1F = show the indicator sub-models.
s32 func_80800630_chfantasysafe(actor, msg, arg)
Actor *actor;
s32 msg;
s32 arg;
{
    s32 index;
    s32 flags[1];
    f32 *angles;
    s32 unk_4;
    s32 hit_1;
    s32 hit_9;
    s32 hit_8;
    switch (msg) {
        case 0x49:
            index = arg - 0x51;
            if (func_800DB9B0()) {
                msg = 0x100;
            } else {
                msg = 0;
            }
            flags[0] = msg | 0x810;
            if (index < 4 && index >= 0) {
                actor->unk58 = 2.0f;
                func_80101FDC(actor, 2);
                actor->unk6C_0 = index;
                angles = &D_80800998_chfantasysafe[index];
                ((f32 *) actor->actorData)[7] = actor->unk50 = angles[0];
                ((f32 *) actor->actorData)[3] = angles[1];
                hit_8 = func_800DA298(0x38B) ? 1 : 0;
                hit_9 = func_800DA298(0x38A) ? 1 : 0;
                hit_1 = func_800DA298(0x389) ? 1 : 0;
                msg = func_800DA298(0x38C) ? 1 : 0;
                if (msg + hit_1 + hit_9 + hit_8 >= 3) {
                    _capod_entrypoint_13(actor->unk0, 0, 0, flags[0]);
                    return 1;
                }
                _capod_entrypoint_13(actor->unk0, 0, 2, flags[0]);
                return 1;
            }
            return 0;
        case 0x1F:
            func_801015D0(actor);
            if (_glcutDll_entrypoint_20()) {
                func_800DF744(1, (actor->unk79_4 & 1) ? 1 : 0);
                func_800DF744(2, (actor->unk79_4 & 2) ? 1 : 0);
                func_800DF744(3, (actor->unk79_4 & 4) ? 1 : 0);
                func_800DF744(4, (actor->unk79_4 & 8) ? 1 : 0);
            } else {
                func_800DF744(1, func_800DA298(0x389) ? 1 : 0);
                func_800DF744(2, func_800DA298(0x38A) ? 1 : 0);
                func_800DF744(3, func_800DA298(0x38B) ? 1 : 0);
                func_800DF744(4, func_800DA298(0x38C) ? 1 : 0);
            }
            return 1;
        default:
            return 0;
    }
}

int chfantasysafe_entrypoint_0()
{
    return (int) &D_80800AA0_chfantasysafe;
}

int chfantasysafe_entrypoint_1()
{
    return (int) &D_80800AE8_chfantasysafe;
}

// TU-NOTE: the overlay .data is defined here in C (from the ROM); its tables point to functions of
// this file, and IDO's assembler schedules them differently otherwise.
// D_80800AA0_chfantasysafe and D_80800AE8_chfantasysafe are int[].
extern void func_8010C964();
extern void func_80101870();
u8 D_80800960_chfantasysafe[56] = {
    0x0, 0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x3F, 0x80, 0x0,  0x0,  0x0,  0x4A,
    0x0, 0x44, 0x3F, 0x80, 0x0,  0x0,  0x0,  0x4A, 0x0,  0x44, 0x3F, 0x80, 0x0,  0x0,
    0x0, 0x4A, 0x0,  0x44, 0x3F, 0x80, 0x0,  0x0,  0x0,  0x4A, 0x0,  0x44, 0x3F, 0x80,
    0x0, 0x0,  0x0,  0x4A, 0x0,  0x44, 0x3F, 0x80, 0x0,  0x0,  0x0,  0x4A, 0x0,  0x44};
f32 D_80800998_chfantasysafe[5] = {135.0f, 7.2e+02f, 3.2e+02f, 6.4e+02f, 1.2e+02f};
u8 D_808009AC_chfantasysafe[40] = {0x0,  0x0,  0x0,  0x1,  0x13, 0xDB, 0x1,  0x0, 0x0,  0x0,
                                   0x6,  0x1,  0x13, 0xDC, 0x2,  0x0,  0x0,  0x0, 0x2,  0x0,
                                   0x14, 0x57, 0x1,  0x0,  0x0,  0x0,  0x4,  0x0, 0x14, 0x58,
                                   0x1,  0x0,  0xFF, 0xFE, 0xDF, 0xFF, 0x12, 0xB, 0x3,  0x0};
u8 D_808009D4_chfantasysafe[8] = {0x0, 0x13, 0x4, 0xC7, 0x0, 0x0, 0x0, 0x0};
u8 D_808009DC_chfantasysafe[24] = {0x3, 0x88, 0x0, 0x0, 0x3, 0xE8, 0x0, 0x69, 0x0, 0x0, 0x0, 0xF,
                                   0x0, 0x0,  0x1, 0x0, 0x0, 0x13, 0x5, 0x21, 0x0, 0x0, 0x0, 0x0};
u8 D_808009F4_chfantasysafe[8] = {0x0, 0x13, 0x5, 0x7, 0x0, 0x0, 0x0, 0x0};
u8 D_808009FC_chfantasysafe[12] = {0x0, 0x13, 0x4, 0xA1, 0x0, 0xA, 0x0, 0x99, 0x0, 0x0, 0x0, 0x0};
SafeKey D_80800A08_chfantasysafe[12] = {0.0f,  0.0f,  0x0, 2.0f, 1.0f,  0x1, 2.5f,   0.0f, 0x0,
                                        3.0f,  0.25f, 0x2, 3.5f, 0.0f,  0x0, 4.0f,   0.5f, 0x4,
                                        4.5f,  0.0f,  0x0, 5.0f, 0.75f, 0x8, 5.5f,   0.0f, 0x0,
                                        6.25f, 1.0f,  0x0, 7.0f, 0.0f,  0xF, 1e+02f, 0.0f, 0xF};
u8 D_80800A98_chfantasysafe[8] = {0x0, 0x13, 0x5, 0x7, 0x0, 0x0, 0x0, 0x0};
int D_80800AA0_chfantasysafe[18] = {0xAC0417,
                                    0x8DA0001,
                                    (u32) &D_80800960_chfantasysafe,
                                    (u32) func_808001A0_chfantasysafe,
                                    (u32) func_80105834,
                                    (u32) func_801018A4,
                                    0x0,
                                    0x0,
                                    0x0,
                                    0x800C20,
                                    0x0,
                                    (u32) func_80108ED0,
                                    0x0,
                                    (u32) func_80800000_chfantasysafe,
                                    (u32) func_80107C2C,
                                    -0x7FFFDBFE,
                                    (u32) func_80800630_chfantasysafe,
                                    0x0};
int D_80800AE8_chfantasysafe[18] = {0x158050D,
                                    0x9300001,
                                    0x0,
                                    (u32) func_8010C964,
                                    (u32) func_80105834,
                                    (u32) func_80101870,
                                    0x12C0000,
                                    0x0,
                                    0x0,
                                    0x100,
                                    0x0,
                                    (u32) func_80108ED0,
                                    0x0,
                                    0x0,
                                    (u32) func_80107C2C,
                                    -0x7FFFDBFE,
                                    0x0,
                                    0x0};
