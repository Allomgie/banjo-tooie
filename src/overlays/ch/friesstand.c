#include "ch/friesstand.h"

extern void func_80102424(Actor *, s32);
extern void func_800EE7F8(f32 *, f32 *);
extern void func_80090734(s32, f32 *);
extern void *func_80100094(Actor *, u32);
extern int D_80800EC8_chfriesstand[];
extern int D_80800F10_chfriesstand[];
extern s32 D_80800FA0_chfriesstand[];
extern int D_80801000_chfriesstand[];
extern int D_8080100C_chfriesstand[];
extern int D_8080102C_chfriesstand[];
extern int D_80801038_chfriesstand[];
extern int D_80801044_chfriesstand[];
extern int D_80801050_chfriesstand[];
extern int D_8080101C_chfriesstand[];
extern int D_8080105C_chfriesstand[];
extern s32 D_80801088_chfriesstand[];
extern u8 D_80800E50_chfriesstand[];
extern s32 _subaddiedialog_entrypoint_8();
extern Actor *func_80106790(Unk80132ED0 *);
extern s32 _subaddiedialog_entrypoint_9(Actor *, s32, void *, s32);
extern void _capod_entrypoint_14(void);
extern void func_8010D254(f32 *);
extern void func_800EF1B8(f32 *, f32, f32);
extern f32 func_800EEAD4(f32 *, f32 *);
extern void func_8010D5DC(void);
extern void func_8008F904(void *, Unk80132ED0 *);
extern void func_8008F990(f32 *, f32);
extern Actor *func_801084B0(s32, Actor **);
extern void func_80102FDC(Actor *, f32);
extern void _subaddiefade_entrypoint_9(Actor *, f32 *);
extern void _subaddiefade_entrypoint_11(Actor *, f32 *);
extern void func_80101FDC();
extern s32 _chdoormake_entrypoint_3(Actor *, f32, f32, f32, s32, s32);
extern void _chdoormake_entrypoint_5(Actor *, f32);
extern void func_80101180(s32, s32, s32);
extern s32 _chswitch_entrypoint_10(Actor *, s32);
extern s32 D_80800FE8_chfriesstand[];
extern s32 func_80102320(Actor *, f32, f32);
extern s32 func_80101E14(Actor *, f32);
extern s32 func_800F4EC8(s32, f32 *, f32, f32, f32);
extern s32 _subaddieaudioquick_entrypoint_3(Actor *, f32 *, void *, f32);
typedef union {
    u32 raw;
    s16 halves[2];
} StandEvent_chfriesstand;
extern u32 D_80800FF0_chfriesstand[];
extern void func_80101EE4(Actor *, f32);
extern void _gcdialogcamera_entrypoint_3(u32 *, f32);
extern u8 D_8080106C_chfriesstand[];
extern void func_800BABB8(s32, f32 *, s32, f32, void *);
extern void func_800BA994();
void func_808006D4_chfriesstand();

int chfriesstand_entrypoint_0()
{
    return (int) D_80800EC8_chfriesstand;
}

int chfriesstand_entrypoint_1()
{
    return (int) D_80800F10_chfriesstand;
}

int chfriesstand_entrypoint_2()
{
    extern int D_80800F58_chfriesstand[];
    return (int) D_80800F58_chfriesstand;
}

int chfriesstand_entrypoint_3()
{
    return D_80800FA0_chfriesstand;
}

void func_80800030_chfriesstand(Actor *actor)
{
    s32 found;
    Actor *actor_alias;
    // Matching: extra alias of the parameter is needed for the match.
    actor_alias = actor;
    if (_glcutDll_entrypoint_20() != 0) {
        func_80102424(actor_alias, 5);
    } else {
        *(u8 *) ((u8 *) actor_alias + 0x65) = (u8) ((*(u8 *) ((u8 *) actor_alias + 0x65) & 0xFFFE) |
                                                ((func_800DA298(0xA0) & 0xFFFFu) & 1));
    }
    func_80103110(actor_alias, *(u16 *) ((u8 *) actor + 0x64) & 1);
    found = _subaddiefind_entrypoint_2(0x331, 0);
    if (found != 0) {
        func_800EE7F8((u8 *) actor + 0x18, found + 4);
        *(f32 *) ((u8 *) actor + 0x1C) = (f32) *(f32 *) ((u8 *) actor + 8);
    }
}

void func_808009A4_chfriesstand();

void func_808005F0_chfriesstand();

void func_808000C4_chfriesstand(Actor *actor)
{
    s32 dialog_id;

    if (func_80100094(actor, 1)) {
        _suexpression_entrypoint_10(func_80100094(actor, 1), actor->unk0, 0);
        if (func_801022E4(actor) != 0xD0 || !func_80102320(actor, 0.45f, 0.85f)) {
            _suexpression_entrypoint_18(func_80100094(actor, 1), 1);
        }
    }
    func_800F4EC8(func_800F54E4(), (f32 *) actor->actorData, 300.0f, -10.0f, 200.0f);
    switch (actor->unk70_10) {
        case 1:
            func_808005F0_chfriesstand(actor);
            if (func_80101E14(actor, 0.999f)) {
                if (actor->unk6C_0 < 2U)
                    actor->unk6C_0++;
                else
                    func_80102424(actor, 2);
            }
            func_808009A4_chfriesstand(actor);
            return;
        case 2:
            func_80800620_chfriesstand(actor);
            func_808006D4_chfriesstand(actor);
            if (func_80101DDC(actor)) {
                actor->unk6C_0 = 0;
                func_80102424(actor, 1);
            }
            func_808009A4_chfriesstand(actor);
            return;
        case 3:
            func_808005F0_chfriesstand(actor);
            return;
        case 4:
            _subaddieaudioquick_entrypoint_3(actor, actor->position, D_80800FE8_chfriesstand,
                                             0.7f);
            if (func_80101E14(actor, 0.837f)) {
                if (actor->unk3C) {
                    func_800FC660(0xE);
                    func_800D175C(0x4C, 5 - func_800D1A04(0x4C));
                    func_800FFA88(actor->unk3C);
                    actor->unk3C = 0;
                }
                if (func_800F64A4(func_800F54E4(), 0x200))
                    dialog_id = 0x110B;
                else
                    dialog_id = 0x10FD;
                _subaddiedialog_entrypoint_11(actor->unk0, dialog_id, 6, actor->position, 0x51);
            }
            if (func_80101DDC(actor)) {
                actor->unk6C_0 = 0;
                func_80102424(actor, 1);
            }
            return;
        case 5:
            func_808005F0_chfriesstand(actor);
            if (func_80101DDC(actor))
                func_80102424(actor, 6);
            break;
        case 6:
            func_80800620_chfriesstand(actor);
            func_808006D4_chfriesstand(actor);
            if (func_80101DDC(actor))
                func_80102424(actor, 5);
    }
}

void func_80800398_chfriesstand(Actor *actor)
{
    func_80800970_chfriesstand(actor);
}

void func_80800BB0_chfriesstand();

void func_80800AEC_chfriesstand();

void func_808009F0_chfriesstand();

s32 func_80800904_chfriesstand();

s32 func_808003B8_chfriesstand(Actor *actor, s32 msg, StandEvent_chfriesstand event)
{
    Actor *tray;
    u32 query;
    switch (msg) {
        default:
            return 0;
        case 0x2E:
            func_808009F0_chfriesstand(actor, event.halves[0], event.halves[1]);
            return 1;
        case 0x2F:
            func_80800AEC_chfriesstand(actor, event.halves[0], event.halves[1]);
            return 1;
        case 0x32:
            func_80090734(2, actor->position);
            return 1;
        case 0x3D:
            func_80800BB0_chfriesstand(actor);
            return 1;
        case 0x52:
            _gcdialogcamera_entrypoint_3(D_80800FF0_chfriesstand, actor->scale);
            return 1;
        case 0xA:
            actor->unk64_16 = 1;
            func_80102424(actor, 3);
            func_80101EE4(actor, 0.0f);
            func_80103110(actor, 1);
            if (actor->unk3C) {
                tray = func_80106790(actor->unk3C);
                tray->unk64_16 = actor->unk64_16;
            }
            _capod_entrypoint_13(actor->unk0, 0, 0x16, 0x30);
            _subaddiedialog_entrypoint_11(actor->unk0, 0x10E0, 4, actor->position, 0x51);
            return 1;
        case 0x29:
            func_80800904_chfriesstand(actor);
            return 1;
        case 0x2A:
            func_80800970_chfriesstand(actor);
            return 1;
        case 0x95:
            if (!func_800D1A04(0x4C))
                func_80108B04(actor, 0);
            break;
        case 0xB8:
            query = event.raw & 0xFFFF;
            switch (query) {
                default:
                    return 0;
                case 1:
                    return actor->unk3C ? 0x10AE : 0x10AF;
                case 2:
                    return actor->unk3C ? 0x1109 : 0x110A;
            }
    }
    return 1;
}

void func_808005F0_chfriesstand(s32 actor)
{
    _subaddieaudioquick_entrypoint_4(actor, actor + 4, D_80801000_chfriesstand,
                                     D_8080100C_chfriesstand);
}

int func_80800620_chfriesstand(s32 actor)
{
    s32 self;
    // Matching: `| 0` is needed for the match.
    self = actor | 0;
    _subaddieaudioquick_entrypoint_3(self, self + 4, D_8080102C_chfriesstand, 0.0799999982f);
    _subaddieaudioquick_entrypoint_3(self, self + 4, D_80801038_chfriesstand, 0.230000004f);
    _subaddieaudioquick_entrypoint_3(self, self + 4, D_80801044_chfriesstand, 0.340000004f);
    _subaddieaudioquick_entrypoint_3(self, self + 4, D_80801050_chfriesstand, 0.419999987f);
    _subaddieaudioquick_entrypoint_4(self, self + 4, D_8080101C_chfriesstand,
                                     D_8080105C_chfriesstand);
}

// Matching: the line breaks in this function are needed for the match.
// Spawns the cooking steam particles.
void func_808006D4_chfriesstand(actor) Actor *actor;
{
    f32 pos[3];
    s32 particle;
    f32 angle;
    f32 base_scale;
    if (func_80101E14(actor, 0.345f)) {
        if (!_subaddieskeleton_entrypoint_3(actor->unk0, 4, pos)) return;
        func_800EF1B8(pos, actor->rotation[1], 20.0f); particle = func_800B53A4(12); func_800BABB8(particle, pos, 0, actor->scale, D_8080106C_chfriesstand);
        func_800BA610(particle, -100, -100);
        angle = actor->rotation[1]; base_scale = actor->scale; func_800BA994(particle, 15, (s16)(s32)(angle - 50.0f), (s16)(s32)(base_scale * 300.0f), 20, (s32)(angle + 50.0f), (s32)(base_scale * 450.0f));
        func_800BA22C(particle, 12);
    }
    if (func_80101E14(actor, 0.43f) && _subaddieskeleton_entrypoint_3(actor->unk0, 4, pos)) {
        particle = func_800B53A4(5); func_800BABB8(particle, pos, 0, actor->scale * 1.2f, D_8080106C_chfriesstand);
        func_800BA610(particle, -800, -1000);
        angle = actor->rotation[1] + 90.0f; base_scale = actor->scale; func_800BA994(particle, -25, (s16)(s32)(angle - 10.0f), (s16)(s32)(base_scale * 200.0f), -15, (s32)(angle + 10.0f), (s32)(base_scale * 400.0f));
        func_800BA22C(particle, 5);
    }
}

s32 func_80800904_chfriesstand(Actor *actor)
{
    if (!func_80100094(actor, 1)) {
        _suexpression_entrypoint_7(actor, 1, 0x51);
        _suexpression_entrypoint_12(func_80100094(actor, 1), 0x42480000, 0x41A00000);
        _suexpression_entrypoint_17(func_80100094(actor, 1), 0x3E8);
    }
}

void func_80800970_chfriesstand(Actor *actor)
{
    if (func_80100094(actor, 1) != 0) {
        _suexpression_entrypoint_8(actor, 1);
    }
}

void func_808009A4_chfriesstand(u8 *actor)
{
    if (_subaddiedialog_entrypoint_8(actor, actor + 4, D_80801088_chfriesstand,
                                     &D_80800E50_chfriesstand, 5)) {
        func_80090734(1, (f32 *) (actor + 4));
    }
}

void func_808009F0_chfriesstand(Actor *actor, s32 dialog_id, s32 unk_2)
{
    switch (dialog_id) {
        case 0x10E0:
            _capod_entrypoint_14();
            actor->unk6C_0 = 0;
            func_80102424(actor, 1);
            break;
        case 0x10FD:
        case 0x110B:
            func_8008FC9C(0);
            func_80102424(actor, 1);
            break;
        default:
            if (actor->unk3C &&
                _subaddiedialog_entrypoint_9(actor, dialog_id, D_80800E50_chfriesstand, 5) == 2) {
                func_80102424(actor, 4);
                func_80102424(func_80106790(actor->unk3C), 2);
            } else {
                actor->unk6C_0 = 0;
                func_80102424(actor, 1);
                func_80090708(0);
            }
    }
}

void func_80800AEC_chfriesstand(Actor *actor, s32 dialog_id, s32 unk_2)
{
    f32 front_pos[3];
    f32 unk_1[3];
    s32 result;
    f32 dist;

    if (actor->unk3C) {
        result = _subaddiedialog_entrypoint_9(actor, dialog_id, D_80800E50_chfriesstand, 5);
        if (result != 2) {
            return;
        }
        func_8010D254(unk_1);
        func_800EE7F8(front_pos, actor->position);
        func_800EF1B8(front_pos, actor->rotation[1], 255.0f);
        dist = func_800EEAD4(unk_1, front_pos);
        if (dist > 50.0f) {
            func_80090708(0);
            func_8008F8B0();
            func_8008F904(func_8010D5DC, actor->unk0);
            func_8008F990(front_pos, 170.0f);
        }
    }
}

// Spawns the fries tray (actor 0x32E) and hands it to the vendor.
void func_80800BB0_chfriesstand(Actor *actor)
{
    Actor *tray;
    f32 unk_0[3];

    tray = func_801084B0(0x32E, &actor);
    func_80102FDC(tray, actor->scale);
    _subaddiefade_entrypoint_9(actor, unk_0);
    _subaddiefade_entrypoint_11(tray, unk_0);
    actor->unk3C = tray->unk0;
    tray->unk64_16 = actor->unk64_16;
}

void func_80800C34_chfriesstand(s32 arg0)
{
}

void func_80800C3C_chfriesstand(Actor *actor)
{
    int switch_flag;

    if (func_800EA05C() == 0x124) {
        func_8010A624(actor);
    }
    actor->position[1] -= 225.0f;
    if (_glcutDll_entrypoint_20()) {
        switch_flag = -1;
        func_80101FDC(actor, 4);
    } else {
        switch_flag = 0xA0;
    }
    if (_chdoormake_entrypoint_3(actor, 0.0f, 90.0f, 225.0f, 0x20, switch_flag)) {
        _chdoormake_entrypoint_5(actor, 2.0f);
        _chdoormake_entrypoint_8(actor, 3);
    }
}

void func_80800CF0_chfriesstand(s32 switch_actor)
{
    _chswitch_entrypoint_7(switch_actor, FLAG_0A0_UNK);
    _chswitch_entrypoint_9(switch_actor);
}

s32 func_80800D1C_chfriesstand(Actor *actor, s32 msg)
{
    if (msg == 7) {
        func_80101180(0x331, 7, 0);
        func_80101180(0x32D, 10, 0);
    } else {
        return _chswitch_entrypoint_10(actor, msg);
    }
    return 1;
}

// TU-NOTE: the .data of this overlay is defined here in C. Its tables hold pointers to
// functions of this file; IDO assembler schedules some of them differently unless the
// tables are in the same unit. Values are taken from the ROM.
extern void func_80105834();
extern void func_80101870();
extern void func_80107C2C();
extern u8 boot_thread_stack[];
extern void func_80102EC0();
extern void _chdoor_entrypoint_0();
extern void _chdoor_entrypoint_1();
extern u8 D_8011A270[];
extern void _chswitch_entrypoint_6();
u8 D_80800E50_chfriesstand[40] = {0x0,  0x0, 0x0,  0x1,  0x10, 0xAD, 0x1,  0x0,  0x0,  0x0,
                                  0x0,  0x1, 0xFF, 0xFF, 0x2,  0x0,  0x0,  0x0,  0x2,  0x0,
                                  0x11, 0x8, 0x1,  0x0,  0x0,  0x0,  0x2,  0x0,  0xFF, 0xFE,
                                  0x2,  0x0, 0xFF, 0xFE, 0xDF, 0xFF, 0x12, 0x10, 0x3,  0x0};
u32 D_80800E78_chfriesstand[14] = {0x0,        0x0,        0x41200000, 0xD00001,   0x41200000,
                                   0xD10002,   0x41200000, 0xD00001,   0x40100000, 0xDA0002,
                                   0x41200000, 0xD00002,   0x41200000, 0xD10002};
u32 D_80800EB0_chfriesstand[6] = {0x0, 0x0, 0x40100000, 0xDB0044, 0x40100000, 0xDB0002};
int D_80800EC8_chfriesstand[18] = {0x1B9032D,
                                   0x6AD0001,
                                   (u32) &D_80800E78_chfriesstand,
                                   (u32) func_808000C4_chfriesstand,
                                   (u32) func_80105834,
                                   (u32) func_80101870,
                                   0x7D00000,
                                   0x0,
                                   0x0,
                                   0x40000160,
                                   (u32) func_80800398_chfriesstand,
                                   0x0,
                                   0x0,
                                   (u32) func_80800030_chfriesstand,
                                   (u32) func_80107C2C,
                                   (u32) ((u8 *) boot_thread_stack + 0x1F32),
                                   (u32) func_808003B8_chfriesstand,
                                   0x0};
int D_80800F10_chfriesstand[18] = {0x1BA032E,
                                   0x6B00001,
                                   (u32) &D_80800EB0_chfriesstand,
                                   (u32) func_80102EC0,
                                   (u32) func_80105834,
                                   (u32) func_80101870,
                                   0x0,
                                   0x0,
                                   0x0,
                                   0x4,
                                   0x0,
                                   0x0,
                                   0x0,
                                   (u32) func_80800C34_chfriesstand,
                                   (u32) func_80107C2C,
                                   -0x7FEFD7EE,
                                   0x0,
                                   0x0};
int D_80800F58_chfriesstand[18] = {0xAC0331,
                                   0x7750001,
                                   0x0,
                                   (u32) _chdoor_entrypoint_0,
                                   (u32) func_80105834,
                                   (u32) func_80101870,
                                   0x0,
                                   0x0,
                                   0x0,
                                   0x40000C00,
                                   0x0,
                                   0x0,
                                   0x0,
                                   (u32) func_80800C3C_chfriesstand,
                                   (u32) func_80107C2C,
                                   -0x7FFFD3FE,
                                   (u32) _chdoor_entrypoint_1,
                                   0x0};
s32 D_80800FA0_chfriesstand[18] = {0x3430332,
                                   0x93D0001,
                                   (u32) &D_8011A270,
                                   (u32) _chswitch_entrypoint_6,
                                   (u32) func_80105834,
                                   (u32) func_80101870,
                                   0x0,
                                   0x0,
                                   0x0,
                                   0x808,
                                   0x0,
                                   0x0,
                                   0x0,
                                   (u32) func_80800CF0_chfriesstand,
                                   (u32) func_80107C2C,
                                   -0x7FFFD3EE,
                                   (u32) func_80800D1C_chfriesstand,
                                   0x0};
s32 D_80800FE8_chfriesstand[2] = {0x1303FF, 0x0};
u32 D_80800FF0_chfriesstand[4] = {0x436B0000, 0x43160000, 0x42C80000, 0x42C80000};
int D_80801000_chfriesstand[3] = {0x130419, 0xD01A6, 0x1C00000};
int D_8080100C_chfriesstand[4] = {0x3E6B851F, 0x3E9EB852, 0x3EB33333, -0x40800000};
int D_8080101C_chfriesstand[4] = {0x130449, 0xD0166, 0x1800016, 0x27100000};
int D_8080102C_chfriesstand[3] = {0x130500, 0xD0140, 0x1590000};
int D_80801038_chfriesstand[3] = {0x130502, 0xD0126, 0x1400000};
int D_80801044_chfriesstand[3] = {0x130503, 0xD0126, 0x1400000};
int D_80801050_chfriesstand[3] = {0x130501, 0xD0126, 0x1400000};
int D_8080105C_chfriesstand[4] = {0x3F4F5C29, 0x3F570A3D, 0x3F5D70A4, -0x40800000};
u8 D_8080106C_chfriesstand[28] = {0x0, 0x1D, 0x9, 0x5C, 0x0, 0x22, 0x0, 0x2, 0x0, 0x5,
                                  0x0, 0x7,  0x0, 0xC,  0x0, 0x15, 0x0, 0x0, 0x0, 0x99,
                                  0x0, 0x2B, 0x0, 0x80, 0x0, 0xCC, 0x0, 0x0};
s32 D_80801088_chfriesstand[6] = {0x9E0000, 0x12C0051, 0x6, 0x7320300, 0x0, 0x0};
