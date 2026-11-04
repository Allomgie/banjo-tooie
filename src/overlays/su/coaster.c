// Probably the shared brain of generic ground baddies (hillbillies, bigfoot, pirates, ...):
// idle, wander routes, notice, chase, attack, hit, return home, die; with per-kind parameters.
#include "common.h"

extern void *func_80100094(Actor *, u32);
extern s32 _subaddierouteDll_entrypoint_4();
typedef struct {
    u8 pad_0[0xC];
    s16 local_0;
    u8 pad_1[9];
    s8 local_1;
    u8 local_2 : 4;
    u8 pad_2 : 4;
    u8 local_3 : 1;
    u8 local_4 : 1;
    u8 pad_3 : 6;
} CoasterInit1493;
extern void *func_80100074(Actor *, u32, u32);
extern s32 _sucoasterdata_entrypoint_0(Actor *);
extern s32 _subaddiesect_entrypoint_1(Actor *);
extern void _subaddierouteDll_entrypoint_3(Actor *, void *, f32 *);
typedef struct {
    u8 pad_0[0x18];
    u16 pad_1 : 12;
    u16 local_0 : 1;
    u16 pad_2 : 3;
} CoasterStateFlags;
typedef struct {
    u8 pad_0[0xC];
    s16 scale;
    s16 speed;
} CoasterSpeedState1417;
extern f32 func_80107C00(void);
typedef struct CoasterSpeedRecord {
    u8 pad_0[0x3C];
    s32 unk3C;
    u8 pad40[0xC];
    f32 unk4C;
    s16 unk50;
    s16 unk52;
} CoasterSpeedRecord;
typedef struct {
    u8 pad0[6];
    u16 unk6;
} CoasterRoute;
typedef struct {
    u8 pad0[0x16];
    u8 unk16;
    u8 pad17;
    u32 kind : 4;
    u32 pad_26 : 2;
    u32 bit25 : 1;
    u32 pad_24 : 1;
    u32 bit23 : 1;
    u32 pad_20 : 3;
    u32 bit19 : 1;
    u32 pad_0 : 19;
} CoasterRide;
extern s32 func_800F64A4(s32, s32);
extern s32 _subaddierouteDll_entrypoint_7(Actor *, void *, f32, f32, f32, s32);
extern void _subaddierouteDll_entrypoint_5(Actor *, void *, u8, f32, f32, f32);
extern s32 func_8010BA80(Actor *, s32, s32);
extern void func_8010AA54(f32 *);
extern s32 func_800F1EA4(f32 *, f32 *);
extern f32 func_800DC178(f32, f32);
extern f32 func_800136E4(f32);
typedef struct {
    s16 field_a;
    s8 field_b;
} CoasterMessage1482;
extern s32 func_8010108C(Actor *, s32, s32);
typedef struct {
    u8 pad_0[0x19];
    u8 local_0 : 1;
    u8 pad_1 : 7;
} CoasterRouteFlags;
typedef struct {
    u8 pad_0[0x15];
    u8 local_0;
} CoasterRouteState;
typedef struct {
    u8 pad_0[0x70];
    u32 local_0 : 7;
    u32 pad_1 : 15;
    u32 local_1 : 6;
    u32 pad_2 : 4;
} CoasterRouteActor;
extern void func_800F5A00(s32, f32 *);
extern s32 func_800CC338(f32 *, s32, s32);
extern s32 func_800D9058(f32);
extern void _subaddierouteDll_entrypoint_6(Actor *, void *, u8, s32, f32, s32, s32);
typedef struct {
    u8 pad_0[0x18];
    u32 kind : 4;
    u32 pad_1 : 28;
} CoasterEventKind;
extern struct CoasterSpeedRecord *_sucoasterdata_entrypoint_1(s32);
extern s32 func_80101E14(Actor *, f32);
extern int func_801072A8(int);
extern int func_801072E4(int);
extern void func_8010D6E0(int, int, float, float);
extern s32 func_800EFFB4(f32 *, f32, f32 *);
typedef struct {
    u8 pad_0[0x18];
    u32 pad_1 : 9;
    u32 local_0 : 1;
    u32 pad_2 : 22;
} CoasterTrackItem;
typedef struct CoasterPropKind {
    u8 pad_0[0x18];
    u32 local_0 : 4;
    u32 pad_1 : 28;
} CoasterPropKind;
extern void func_80102BF8(Actor *, f32, f32, f32);
typedef struct {
    u8 pad_0[0x78];
    u32 pad_1 : 26;
    u32 local_0 : 1;
    u32 pad_2 : 5;
} CoasterActorFlags;
extern int _sucoasterdata_entrypoint_4(u32);
extern f32 func_80103EAC(Actor *);
extern f32 func_800F0E00(f32, f32);
typedef struct {
    u8 pad0[0x14];
    u32 unk14;
    u8 pad18[0x64 - 0x18];
    u32 unk64_31 : 1;
    u32 unk64_30 : 1;
    u32 unk64_25 : 5;
    u32 unk64_24 : 1;
    u32 unk64_rest : 24;
    u8 pad68[0x70 - 0x68];
    u32 unk70_25 : 7;
    u32 unk70_10 : 15;
    u32 unk70_4 : 6;
    u32 unk70_0 : 4;
    u8 pad74[3];
    u8 unk77_4 : 4;
    u8 unk77_0 : 4;
} SuCoasterBits;
extern void func_8010A570(SuCoasterBits *);
extern f32 func_80102D78(Actor *, f32 *);
extern f32 func_800F1DCC(f32, f32);
extern f32 func_800F57F0(void *, f32 *);
extern f32 func_800D8FF8(void);
extern f32 func_800F15F8(f32, f32, f32);
extern f32 func_800EFC7C(f32 *, f32 *);
extern f32 func_8010CD50();
extern s32 func_800F54E4(void);
extern s32 func_8010D290(s32);
typedef struct {
    u8 pad[0x78];
    u32 pre : 29;
    u32 f2 : 1;
    u32 post : 2;
} SBits78;
typedef struct {
    u8 pad[0x64];
    u32 a : 2;
    u32 f29 : 1;
    u32 rest : 29;
} SBits64;
typedef struct {
    u8 pad_0[0x18];
    u32 local_0 : 4;
    u32 pad_1 : 2;
    u32 local_1 : 1;
    u32 pad_2 : 1;
    u32 local_3 : 1;
    u32 pad_4 : 1;
    u32 local_2 : 1;
    u32 pad_3 : 21;
} CoasterUpdateFlags;
typedef struct {
    u8 pad_0[0x78];
    u32 pad_1 : 28;
    u32 local_0 : 1;
    u32 pad_2 : 3;
} CoasterUpdateActorFlags;
extern s32 func_800DC298(f32);
extern s32 func_80102CF4(Actor *, f32);
extern void func_80102924(Actor *, f32);
extern s32 func_800F20BC(f32, f32, f32);
typedef struct {
    u16 pad : 7;
    u16 f : 9;
} SC6E;
typedef struct {
    u8 f : 1;
    u8 pad : 7;
} SB1;
typedef struct {
    u8 pad : 6;
    u8 f : 1;
    u8 r : 1;
} SB2;
typedef struct {
    u8 pad : 5;
    u8 f : 1;
    u8 r : 2;
} SB4;
typedef struct {
    u8 pad : 2;
    u8 f : 1;
    u8 r : 5;
} SB20;
typedef struct {
    u8 pad : 7;
    u8 f : 1;
} SB01;
typedef struct {
    u32 pad : 6;
    u32 f : 1;
    u32 r : 25;
} SW6;
typedef struct {
    u32 pad : 2;
    u32 f : 1;
    u32 r : 29;
} SW2;
extern f32 func_8010203C(Actor *, s32);
extern void func_80101CDC(Actor *, f32);
extern f32 func_800EEB40(f32 *, f32 *);
extern void func_800C4104(s32, f32, s32, f32 *, f32, f32);
typedef struct {
    u8 pad_0[0x64];
    u8 b64_7 : 1;
    u8 b64_6 : 1;
    u8 pad64 : 5;
    u8 b64_0 : 1;
} Coaster64;
typedef struct {
    u8 pad_0[0x77];
    u8 hi77 : 4;
    u8 lo77 : 4;
} Coaster77;
typedef struct {
    u8 pad_0[0x78];
    u32 pad78 : 29;
    u32 b78_2 : 1;
    u32 pad78b : 2;
} Coaster78;
typedef struct {
    u8 pad_0[0x18];
    u32 pad18 : 10;
    u32 b18_21 : 1;
    u32 pad18b : 21;
} CoasterObj;
typedef struct {
    u8 pad_0[0x6C];
    u32 pad6C : 11;
    u32 f6C_9 : 12;
    u32 f6C_0 : 9;
} Coaster6C;
s32 sucoaster_entrypoint_9();
s32 func_8080202C_sucoaster();
void func_80802130_sucoaster();
f32 func_808021A8_sucoaster();
s32 func_80802384_sucoaster(Actor *param_0, u8 *param_1, f32 param_2);
s32 func_80802594_sucoaster();
s32 func_80802728_sucoaster();
s32 func_80802760_sucoaster();
void func_8080027C_sucoaster();
s32 sucoaster_entrypoint_10();
void sucoaster_entrypoint_11(Actor *param_0, f32 param_1);
int sucoaster_entrypoint_17();
void sucoaster_entrypoint_2(u8 *param_0);

void *D_exp_sucoaster_entrypoint_2[] = {(void *) sucoaster_entrypoint_2};
void *D_exp_sucoaster_entrypoint_11[] = {(void *) sucoaster_entrypoint_11};
void *D_exp_sucoaster_entrypoint_17[] = {(void *) sucoaster_entrypoint_17};

s32 sucoaster_entrypoint_0(Actor *actor, s32 unk_1)
{
    CoasterInit1493 *coaster;

    coaster = func_80100074(actor, 0, unk_1 + 0x1C);
    coaster->local_2 = _sucoasterdata_entrypoint_0(actor);
    coaster->local_1 = _subaddiesect_entrypoint_1(actor);
    _subaddierouteDll_entrypoint_3(actor, coaster, actor->position);
    func_80802130_sucoaster(actor, (struct CoasterPropSize *) coaster, 0x190);
    coaster->local_3 = 1;
    coaster->local_4 = 1;
    coaster->local_0 = (s32) (actor->scale * 256.0f);
    func_80107200(actor);
    return 1;
}

s32 sucoaster_entrypoint_1(s32 actor)
{
    s32 coaster = func_80100094(actor, 0);
    func_80802728_sucoaster(actor, coaster | 0x10000000 & 0xFF);
}

void sucoaster_entrypoint_22();

// Per-frame update.
void sucoaster_entrypoint_2(u8 *actor)
{
    u8 *coaster;
    s32 node;
    u8 count;
    u8 count2;
    u32 action_state;
    coaster = func_80100094(actor, 0);
    // Matching: empty block steers IDO's register allocation.
    if (1) {
    }
    if (*(s8 *) (coaster + 0x17) == -1 ||
        _subaddiesect_entrypoint_0(actor, *(s8 *) (coaster + 0x17), 1) != 0) {
        sucoaster_entrypoint_22(actor);
        if (!((SBits78 *) actor)->f2) {
            func_800D9078(actor + 0x58);
            count = *(u8 *) (coaster + 0x12);
            if (count > 0) {
                *(u8 *) (coaster + 0x12) = count - 1;
            }
            if (*(u8 *) (actor + 0x74) & 1) {
                action_state = (u32) *(u16 *) (actor + 0x72) >> 10;
                if (action_state != 0xB && action_state != 0xC && action_state != 0xD) {
                    count2 = *(u8 *) (coaster + 0x13);
                    if (count2 > 0) {
                        *(u8 *) (coaster + 0x13) = count2 - 1;
                        if (*(u8 *) (coaster + 0x13) == 0) {
                            sucoaster_entrypoint_17(actor, 2);
                            *(u8 *) (coaster + 0x13) = func_800D9058(1.8f);
                        }
                    }
                }
            }
            node = func_80802760_sucoaster(coaster);
            if (node != -1) {
                func_800F5A00(node, actor + 0x18);
            }
            if (((SBits64 *) actor)->f29) {
                _sucoasterplayer_entrypoint_0(actor);
            } else {
                func_8080027C_sucoaster(actor, coaster);
            }
            if (func_80100094(actor, 1) != 0) {
                _suexpression_entrypoint_10(func_80100094(actor, 1), *(s32 *) actor, 0);
            }
        }
    }
}

f32 func_8080264C_sucoaster();

s32 func_80802400_sucoaster();

f32 func_8080230C_sucoaster();

void func_808020B8_sucoaster(Actor *param_0, CoasterPropKind *param_1, f32 param_2);

s32 sucoaster_entrypoint_19();

s32 sucoaster_entrypoint_16();

void sucoaster_entrypoint_15();

s32 sucoaster_entrypoint_14();

s32 sucoaster_entrypoint_13();

void sucoaster_entrypoint_8();

s32 sucoaster_entrypoint_7(Actor *this, s32 arg1, f32 arg2);

// Per-frame state machine, one case per state.
void func_8080027C_sucoaster(actor, coaster) Actor *actor;
void *coaster;
{
    char *kind_data;
    s32 state_id;
    f32 target;
    s32 timer;
    f32 speed;
    f32 turn;
    f32 sign;

    kind_data = (char *) _sucoasterdata_entrypoint_1(*(u32 *) ((char *) coaster + 0x18) >> 28);

    switch (actor->unk70_10) {
        case 1:
            if (func_800DC298(0.5f)) {
                state_id = 2;
            } else {
                state_id = 3;
            }

            if (sucoaster_entrypoint_9(actor, state_id, 0) != 0) {
                break;
            }

            sucoaster_entrypoint_9(actor, 3, 0);
            break;

        case 2:
            sucoaster_entrypoint_19(actor);

            if (*(f32 *) ((char *) actor + 0x58) <= 0.0f && func_800DC298(0.03f)) {
                if (((CoasterUpdateFlags *) coaster)->local_1) {
                    sucoaster_entrypoint_9(actor, 3, 2);
                    ((CoasterUpdateFlags *) coaster)->local_1 = 0;
                } else if (sucoaster_entrypoint_9(actor, 3, 0)) {
                    _subaddierouteDll_entrypoint_6(
                        actor, coaster, *(u8 *) ((char *) coaster + 0x16), 0, 1.0f, 10, 45);
                }
            }

            sucoaster_entrypoint_13(actor);
            sucoaster_entrypoint_8(actor);
            break;

        case 3:
            _subaddierouteDll_entrypoint_6(actor, coaster, *(u8 *) ((char *) coaster + 0x16), 7,
                                           0.6f, 4, 8);

            if ((*(u8 *) ((char *) coaster + 0x16) & 7) == 0 &&
                *(f32 *) ((char *) actor + 0x58) <= 0.0f && func_800DC298(0.01f)) {
                if (func_800DC298(0.3f)) {
                    state_id = 4;
                } else {
                    state_id = 2;
                }
                sucoaster_entrypoint_9(actor, state_id, 0);
            }

            if (sucoaster_entrypoint_7(actor, 0x802, 30.0f)) {
                break;
            }

            sucoaster_entrypoint_13(actor);
            break;

        case 4:
            _subaddierouteDll_entrypoint_6(actor, coaster, *(u8 *) ((char *) coaster + 0x16), 7,
                                           0.6f, 4, 8);

            if (*(f32 *) ((char *) actor + 0x58) <= 0.0f && func_800DC298(0.02f)) {
                sucoaster_entrypoint_9(actor, 3, 0);
            }

            if (sucoaster_entrypoint_7(actor, 0x802, 30.0f)) {
                break;
            }

            sucoaster_entrypoint_13(actor);
            break;

        case 5:
            if (sucoaster_entrypoint_14(actor)) {
                if (sucoaster_entrypoint_9(actor, 2, 0)) {
                    timer = func_800D9058(2.0f);

                    actor->unk6C_0 = timer;
                }
            } else {
                target = func_8080264C_sucoaster(actor, coaster);

                if (!_subaddierouteDll_entrypoint_7(
                        actor, coaster, *(f32 *) ((char *) actor + 0x54), target,
                        (f32) *(s16 *) ((char *) coaster + 0x10), 0x5802)) {
                    if (sucoaster_entrypoint_9(actor, 2, 0)) {
                        timer = func_800D9058(2.0f);

                        actor->unk6C_0 = timer;
                    }
                } else {
                    func_808020B8_sucoaster(actor, coaster, 1.0f);

                    if (func_80102CF4(actor, 15.0f)) {
                        if (*(u8 *) ((char *) coaster + 0x12) != 0) {
                            state_id = 8;
                        } else {
                            state_id = 7;
                        }

                        sucoaster_entrypoint_9(actor, state_id, 0);
                    }
                }
            }

            sucoaster_entrypoint_8(actor);
            break;

        case 6:
            func_80102BF8(actor, *(f32 *) (kind_data + 0x4C), (f32) *(s16 *) (kind_data + 0x50),
                          (f32) *(s16 *) (kind_data + 0x52));

            if (func_80102CF4(actor, 20.0f)) {
                if (*(u8 *) ((char *) actor + 0x74) & 1) {
                    sucoaster_entrypoint_9(actor, 0x12, 0);
                    ((CoasterUpdateFlags *) coaster)->local_1 = 0;
                } else {
                    sucoaster_entrypoint_9(actor, 3, 2);
                    ((CoasterUpdateFlags *) coaster)->local_1 = 0;
                }
            }

            sucoaster_entrypoint_8(actor);
            break;

        case 7:
            sucoaster_entrypoint_16(actor, 0);

            *(f32 *) ((char *) actor + 0x54) = func_8080264C_sucoaster(actor, coaster);

            func_808020B8_sucoaster(actor, coaster, 1.0f);

            if (func_80101DDC(actor)) {
                if (sucoaster_entrypoint_14(actor)) {
                    if (sucoaster_entrypoint_9(actor, 3, 0)) {
                        _subaddierouteDll_entrypoint_6(
                            actor, coaster, *(u8 *) ((char *) coaster + 0x16), 0, 1.0f, 40, 70);

                        timer = func_800D9058(2.0f);

                        actor->unk6C_0 = timer;
                    }
                } else {
                    sucoaster_entrypoint_9(actor, 8, 0);
                }
            }

            sucoaster_entrypoint_8(actor);
            break;

        case 8:
            speed = (f32) _sucoasterdata_entrypoint_3(*(u32 *) ((char *) coaster + 0x18) >> 28);
            sucoaster_entrypoint_11(actor, speed);

            if (sucoaster_entrypoint_14(actor)) {
                sucoaster_entrypoint_15(actor);
            } else {
                if (((CoasterUpdateFlags *) coaster)->local_3 ||
                    _subaddierouteDll_entrypoint_4(actor)) {
                    *(f32 *) ((char *) actor + 0x54) = func_8080264C_sucoaster(actor, coaster);
                }

                if (*(u16 *) (kind_data + 0x4A) != 0 && func_80102CF4(actor, 80.0f) &&
                    func_80802400_sucoaster(actor, coaster)) {
                    sucoaster_entrypoint_9(actor, 9, 0);
                }
            }

            sucoaster_entrypoint_7(actor, 0x5802, 30.0f);
            break;

        case 9:
            if (((CoasterUpdateFlags *) coaster)->local_3 ||
                _subaddierouteDll_entrypoint_4(actor)) {
                *(f32 *) ((char *) actor + 0x54) = func_8080264C_sucoaster(actor, coaster);
            }

            sucoaster_entrypoint_7(actor, 0x5802, 30.0f);

            sucoaster_entrypoint_16(actor, 1);
            sucoaster_entrypoint_16(actor, 6);

            if (!((CoasterUpdateFlags *) coaster)->local_2) {
                if (sucoaster_entrypoint_16(actor, 5)) {
                    _sucoasterhit_entrypoint_2(actor);
                }
            }

            if (func_80101DDC(actor)) {
                if (sucoaster_entrypoint_13(actor)) {
                    break;
                }

                sucoaster_entrypoint_9(actor, 3, 0);
            }
            break;

        case 10:
            speed = (f32) _sucoasterdata_entrypoint_3(*(u32 *) ((char *) coaster + 0x18) >> 28);
            sucoaster_entrypoint_11(actor, speed);

            if (func_80802550_sucoaster(actor, coaster)) {
                sucoaster_entrypoint_15(actor);
            } else if (((CoasterUpdateFlags *) coaster)->local_3 ||
                       _subaddierouteDll_entrypoint_4(actor)) {
                *(f32 *) ((char *) actor + 0x54) = func_8080230C_sucoaster(actor, coaster);
            }

            sucoaster_entrypoint_7(actor, 0x4802, 30.0f);
            break;

        case 11:
            sucoaster_entrypoint_16(actor, 2);

            if (func_80101DDC(actor) && !((CoasterUpdateActorFlags *) actor)->local_0) {
                if (*(u8 *) ((char *) actor + 0x74) & 1) {
                    sucoaster_entrypoint_9(actor, 0x12, 0);
                } else {
                    sucoaster_entrypoint_9(actor, 3, 0);
                }
            }

            sucoaster_entrypoint_8(actor);
            break;

        case 12:
            sucoaster_entrypoint_19(actor);

            if (func_80101DDC(actor) && !((CoasterUpdateActorFlags *) actor)->local_0) {
                if (!func_80107070(actor, 2)) {
                    sucoaster_entrypoint_10(actor, 0xD);
                    _subaddiefade_entrypoint_3(actor);
                }
            }

            sucoaster_entrypoint_16(actor, 3);
            break;

        case 13:
            sucoaster_entrypoint_19(actor);
            break;

        case 14:
            sucoaster_entrypoint_19(actor);
            break;

        case 15:
            _sucoasterhit_entrypoint_1(actor);
            break;

        case 17:
            sucoaster_entrypoint_19(actor);
            break;

        case 18:
            speed = (f32) _sucoasterdata_entrypoint_3(*(u32 *) ((char *) coaster + 0x18) >> 28);
            sucoaster_entrypoint_11(actor, speed);

            state_id = *(u8 *) ((char *) coaster + 0x16);
            if (!state_id & 0x1B) {
                if (!func_8001210C(7)) {
                    if (*(u8 *) ((char *) coaster + 0x18) & 1) {
                        sign = 1.0f;
                    } else {
                        sign = -1.0f;
                    }

                    turn = func_800DC178(30.0f, 40.0f) * sign;
                    func_80102924(actor, actor->unk54 + turn);
                }
            }

            if (!(*(u8 *) ((char *) actor + 0x74) & 1)) {
                sucoaster_entrypoint_9(actor, 3, 0);
            } else {
                sucoaster_entrypoint_7(actor, 0x4000, 30.0f);
            }
    }
}

s32 sucoaster_entrypoint_3(s32 actor)
{
    return (s32) ((u8 *) func_80100094(actor, 0) + 0x1C);
}

void sucoaster_entrypoint_4(s32 actor)
{
    u8 *coaster;

    coaster = func_80100094(actor, 0);
    if (coaster != NULL) {
        coaster[0x19] &= 0xFFBF;
    }
}

void sucoaster_entrypoint_5(Actor *actor)
{
    CoasterStateFlags *coaster;

    coaster = func_80100094(actor, 0);
    if (coaster) {
        coaster->local_0 = 1;
    }
}

void func_80800C68_sucoaster(Actor *actor, u8 *coaster, f32 rate)
{
    if (0.6f * *(s16 *) (coaster + 0xE) < *(f32 *) &actor->actorData[3] &&
        !func_800F20BC(actor->rotation[1], actor->unk54, 60.0f)) {
        *(f32 *) &actor->actorData[3] *= 0.95f;
    } else {
        *(f32 *) &actor->actorData[3] = func_800F15F8(
            *(f32 *) &actor->actorData[3], *(s16 *) (coaster + 0xE), func_80107C00() * rate);
    }
}

void sucoaster_entrypoint_6(Actor *actor, f32 target_speed)
{
    CoasterSpeedState1417 *coaster;

    coaster = func_80100094(actor, 0);
    coaster->speed = (s32) (func_80107C00() * ((f32) coaster->scale * 0.00390625f) * target_speed);
}

void sucoaster_entrypoint_18();

s32 sucoaster_entrypoint_7(Actor *actor, s32 move_flags, f32 rate)
{
    s32 pad;
    CoasterRoute *route;
    CoasterSpeedRecord *kind_data;
    s32 hit_flags;
    CoasterRide *coaster;
    s32 node;
    f32 pos[3];
    f32 angle;

    route = func_80100094(actor, 0);
    coaster = (CoasterRide *) route;
    kind_data = _sucoasterdata_entrypoint_1(coaster->kind);
    if (!coaster->bit19) {
        node = func_80802760_sucoaster(coaster);
        if (node != -1 && func_800F64A4(node, kind_data->unk3C)) {
            move_flags |= 1;
        }
    }
    if (coaster->bit23 || _subaddierouteDll_entrypoint_4(actor)) {
        if (!_subaddierouteDll_entrypoint_7(actor, route, actor->rotation[1], actor->unk54,
                                            func_808021A8_sucoaster(actor, coaster, move_flags), move_flags) &&
            !coaster->bit25 && sucoaster_entrypoint_9(actor, 6, 1)) {
            func_80802384_sucoaster(actor, coaster, actor->rotation[1] + 180.0f);
        }
        coaster->unk16 = route->unk6;
        coaster->bit23 = 0;
    }
    _subaddierouteDll_entrypoint_5(actor, route, coaster->unk16, kind_data->unk4C, kind_data->unk50, kind_data->unk52);
    func_80800C68_sucoaster(actor, coaster, rate);
    sucoaster_entrypoint_18(actor);
    hit_flags = func_8010BA80(actor, 0x305425, 0x20);
    if (hit_flags & 0x20) {
        func_8010AA54(pos);
        if (func_800F1EA4(pos, &angle) && sucoaster_entrypoint_9(actor, 6, 1)) {
            func_80802384_sucoaster(actor, coaster, angle);
        }
    } else if ((hit_flags & 4) && sucoaster_entrypoint_9(actor, 6, 1)) {
        actor->unk54 = func_800136E4(actor->rotation[1] + func_800DC178(140.0f, 2.2e+02f));
    }
    return hit_flags & 0x24;
}

void sucoaster_entrypoint_8(int actor)
{
    int flags;
    // Matching: do/while(0) around the temp is needed for the match.
    do {
        flags = 0x505410;
        func_8010BA80(actor, flags, 0x20);
    } while (0);
}

// Requests a state change; returns 1 if accepted.
s32 sucoaster_entrypoint_9(actor, state_id, arg)
Actor *actor;
s32 state_id;
s32 arg;
{
    s32 unk_0;
    CoasterMessage1482 msg;

    msg.field_b = arg;
    msg.field_a = state_id;
    if (func_8010108C(actor, 0x42, *(s32 *) &msg) > 0) {
        sucoaster_entrypoint_10(actor, state_id);
        return 1;
    }
    return 0;
}

void func_80802260_sucoaster();

// Enters a state and sets up its per-state values.
s32 sucoaster_entrypoint_10(actor, state_id)
u8 *actor;
s32 state_id;
{
    s8 padA[8];
    u8 *coaster;
    s32 range;

    coaster = func_80100094(actor, 0);
    func_80102424(actor, state_id);
    ((SB1 *) (coaster + 0x19))->f = 1;
    switch (state_id) {
        case 2:
            *(f32 *) (actor + 0x58) = 2.0f;
            if (((SW6 *) (coaster + 0x18))->f) {
                *(f32 *) (actor + 0x58) = *(f32 *) (actor + 0x58) * 0.7f;
            }
            sucoaster_entrypoint_6(actor, 0.0f);
            break;
        case 3:
            range = _sucoasterdata_entrypoint_2(*(u32 *) (coaster + 0x18) >> 28);
            sucoaster_entrypoint_6(actor,
                                   func_800DC178((f32) range, (f32) _sucoasterdata_entrypoint_3(
                                                                 *(u32 *) (coaster + 0x18) >> 28)));
            *(f32 *) (actor + 0x58) = 4.0f;
            sucoaster_entrypoint_11(
                actor, (f32) _sucoasterdata_entrypoint_2(*(u32 *) (coaster + 0x18) >> 28));
            break;
        case 4:
            range = _sucoasterdata_entrypoint_3(*(u32 *) (coaster + 0x18) >> 28);
            sucoaster_entrypoint_6(actor,
                                   func_800DC178((f32) range, (f32) _sucoasterdata_entrypoint_4(
                                                                 *(u32 *) (coaster + 0x18) >> 28)));
            *(f32 *) (actor + 0x58) = 4.0f;
            sucoaster_entrypoint_11(
                actor, (f32) _sucoasterdata_entrypoint_3(*(u32 *) (coaster + 0x18) >> 28));
            break;
        case 5:
            sucoaster_entrypoint_6(actor, 0.0f);
            *(f32 *) (actor + 0x54) = func_8080264C_sucoaster(actor, coaster);
            break;
        case 6:
            ((SC6E *) (actor + 0x6E))->f = func_800D9058(2.0f);
            *(f32 *) (actor + 0x24) = 0.0f;
            ((SB2 *) (coaster + 0x18))->f = 1;
            sucoaster_entrypoint_6(actor, 0.0f);
            coaster[0x16] = 0;
            break;
        case 7:
            sucoaster_entrypoint_6(actor, 0.0f);
            break;
        case 8:
            sucoaster_entrypoint_6(
                actor, (f32) _sucoasterdata_entrypoint_4(*(u32 *) (coaster + 0x18) >> 28));
            sucoaster_entrypoint_11(
                actor, (f32) _sucoasterdata_entrypoint_3(*(u32 *) (coaster + 0x18) >> 28));
            if (!((SW2 *) (actor + 0x64))->f) {
                *(f32 *) (actor + 0x54) = func_8080264C_sucoaster(actor, coaster);
            }
            break;
        case 9:
            ((SB20 *) (coaster + 0x19))->f = 0;
            sucoaster_entrypoint_6(actor, 0.0f);
            break;
        case 10:
            sucoaster_entrypoint_6(
                actor, (f32) _sucoasterdata_entrypoint_4(*(u32 *) (coaster + 0x18) >> 28));
            sucoaster_entrypoint_11(
                actor, (f32) _sucoasterdata_entrypoint_3(*(u32 *) (coaster + 0x18) >> 28));
            *(f32 *) (actor + 0x54) = func_8080230C_sucoaster(actor, coaster);
            break;
        case 11:
            *(f32 *) (actor + 0x24) = 0.0f;
            break;
        case 12:
            func_80802260_sucoaster(actor, coaster);
            break;
        case 14:
            func_8010A570(actor);
            sucoaster_entrypoint_6(actor, 0.0f);
            ((SB4 *) (coaster + 0x18))->f = 1;
            ((SB01 *) (actor + 0x64))->f = 0;
            *(f32 *) (actor + 0x24) = 0.0f;
            *(f32 *) (actor + 0x58) = 3.0f;
            _subaddiefade_entrypoint_5(actor);
            break;
        case 15:
            *(f32 *) (actor + 0x24) = 0.0f;
            *(f32 *) (actor + 0x58) = 0.7f;
            coaster[0x14] = 0;
            break;
        case 18:
            ((SB01 *) (coaster + 0x18))->f = func_800DC298(0.5f);
            *(f32 *) (actor + 0x24) = 0.0f;
            sucoaster_entrypoint_6(
                actor, (f32) _sucoasterdata_entrypoint_4(*(u32 *) (coaster + 0x18) >> 28) * 1.2f);
            sucoaster_entrypoint_11(
                actor, (f32) _sucoasterdata_entrypoint_3(*(u32 *) (coaster + 0x18) >> 28));
    }
    return 1;
}

void sucoaster_entrypoint_11(Actor *actor, f32 speed)
{
    s16 *coaster;
    f32 base;
    f32 ratio;

    coaster = (s16 *) func_80100094(actor, 0);
    base = func_8010203C(actor, actor->unk70_10);
    speed *= coaster[6] * 0.00390625f;
    if (coaster[7] != 0.0f) {
        ratio = speed / coaster[7];
        if (ratio < 0.4f) {
            ratio = 0.4f;
        }
        func_80101CDC(actor, base * ratio);
    }
}

s32 sucoaster_entrypoint_12(Actor *actor)
{
    u8 *coaster;
    coaster = func_80100094(actor, 0);
    if (!((CoasterRouteFlags *) coaster)->local_0 &&
        _subaddierouteDll_entrypoint_4(actor, coaster) == 0) {
        return 0;
    }
    return _subaddierouteDll_entrypoint_7(actor, coaster, actor->rotation[1],
                                          actor->rotation[1], *(s16 *) (coaster + 0x10), 0x102);
}

int func_808015F8_sucoaster(Actor *actor, CoasterRouteState *coaster)
{
    f32 pos[3];
    u8 unk_0;
    s32 unk_1;
    s32 node;
    node = func_80802760_sucoaster(coaster);
    unk_0 = coaster->local_0;
    unk_1 = unk_0 ? unk_0 : ((CoasterRouteActor *) actor)->local_1;
    func_800F5A00(node, pos);
    coaster->local_0 =
        func_800CC338(pos, ((CoasterRouteActor *) actor)->local_0 - 1, unk_1 - 1) + 1;
    return coaster->local_0 != 0;
}

s32 sucoaster_entrypoint_13(Actor *actor)
{
    void *coaster = func_80100094(actor, 0);

    if (actor->unk6C_0)
        actor->unk6C_0--;
    if (func_800DB9B0())
        return 0;
    if (func_801072A8(actor))
        return 0;
    if (func_80802760_sucoaster(coaster) == -1)
        return 0;
    if (func_8080202C_sucoaster(actor, coaster)) {
        if (func_80802594_sucoaster(actor, coaster)) {
            sucoaster_entrypoint_9(actor, 10, 0);
            return 2;
        }
        if (actor->unk6C_0)
            return 0;
        if (func_808015F8_sucoaster(actor, coaster) && _suchase_entrypoint_1(actor)) {
            if (actor->unk70_10 != 9 || !sucoaster_entrypoint_9(actor, 8, 0)) {
                sucoaster_entrypoint_9(actor, 5, 0);
            }
            return 1;
        }
    }
    return 0;
}

s32 sucoaster_entrypoint_14(Actor *actor)
{
    u8 *coaster;

    coaster = func_80100094(actor, 0);
    if (func_80802594_sucoaster(actor, coaster)) {
        coaster[0x12] = func_800D9058(func_800DC178(5.0f, 8.0f));
        return 1;
    }
    if (func_8080202C_sucoaster(actor, coaster) && func_808015F8_sucoaster(actor, coaster) &&
        _suchase_entrypoint_1(actor))
        return 0;
    coaster[0x12] = func_800D9058(func_800DC178(5.0f, 8.0f));
    return 1;
}

void sucoaster_entrypoint_15(Actor *actor)
{
    u8 *coaster;
    coaster = func_80100094(actor, 0);
    if (func_80802594_sucoaster(actor, coaster)) {
        sucoaster_entrypoint_9(actor, 10, 0);
    } else if (actor->unk70_10 == 8) {
        sucoaster_entrypoint_9(actor, 4, 0);
        actor->unk58 = func_800DC178(2.0f, 4.0f);
    } else {
        sucoaster_entrypoint_9(actor, 3, 0);
    }
    coaster[0x12] = func_800D9058(func_800DC178(5.0f, 8.0f));
    actor->unk6C_0 = (u16) func_800D9058(2.0f);
    _subaddierouteDll_entrypoint_6(actor, coaster, coaster[0x16], 0, 1.0f, 40, 60);
}

s32 sucoaster_entrypoint_16(Actor *actor, s32 event)
{
    u8 *kind_data;
    s32 offset;
    f32 unk_0;
    kind_data =
        (u8 *) _sucoasterdata_entrypoint_1(((CoasterEventKind *) func_80100094(actor, 0))->kind);
    offset = event * 8;
    if (*(s16 *) (kind_data + offset + 4) == 0)
        return 0;
    unk_0 = *(s16 *) (kind_data + offset + 10) * (1.0f / 256.0f);
    if (func_80101E14(actor, unk_0)) {
        sucoaster_entrypoint_17(actor, event);
        return 1;
    }
    return 0;
}

int sucoaster_entrypoint_17(actor, event)
Actor *actor;
s32 event;
{
    f32 pitch;
    u8 *data;
    s32 unk_0;
    f32 ref_pos[3];

    data = func_80100094(actor, 0);
    data = (u8 *) _sucoasterdata_entrypoint_1(((CoasterEventKind *) data)->kind);
    if (*(s16 *) ((data + 4) + event * 8)) {
        func_8010D640(ref_pos);
        if (func_800EEB40(ref_pos, actor->position) >= 6250000.0f) {
            return 0;
        }
        pitch =
            *(s16 *) ((data + 8) + event * 8) * 0.00390625f + func_800DC178(-0.05f, 0.05f);
        func_800C4104(*(s16 *) ((data + 4) + event * 8), pitch,
                      *(s16 *) ((data + 6) + event * 8), actor->position, 1250.0f, 2500.0f);
        return 1;
    }
    return 0;
}

void sucoaster_entrypoint_18(s32 actor)
{
    func_80105230(actor, 0);
}

s32 sucoaster_entrypoint_19(s32 actor)
{
    if (func_80100094(actor, 1)) {
        _suexpression_entrypoint_18(func_80100094(actor, 1), 1);
    }
}

void sucoaster_entrypoint_20()
{
    func_80101870();
}

void func_80802690_sucoaster();

// Message handler.
s32 sucoaster_entrypoint_21(u8 *actor, s32 msg, s32 arg)
{
    u8 *coaster;
    struct {
        s32 a;
        s32 b;
        f32 c;
        u8 pad[0x18];
    } params;
    s32 flag;
    s32 result;

    switch (msg) {
        case 1:
        case 2:
            if (!((Coaster78 *) actor)->b78_2) {
                _sucoasterplayer_entrypoint_1(actor);
            }
            break;
        case 3:
            ((Coaster64 *) actor)->b64_6 = 0;
            ((Coaster64 *) actor)->b64_0 = 0;
            break;
        case 4:
            ((Coaster64 *) actor)->b64_6 = 1;
            ((Coaster64 *) actor)->b64_0 = 1;
            break;
        case 0x2B:
            coaster = func_80100094(actor, 0);
            flag = arg == 0;
            ((Coaster64 *) actor)->b64_6 = flag;
            ((Coaster64 *) actor)->b64_0 = flag;
            if (arg != 0) {
                coaster[0x13] = func_800D9058(1.8f);
            }
            break;
        case 0x50:
            if (((u32) *(u16 *) (actor + 0x72) >> 10) == 9) {
                msg = (s32) func_80100094(actor, 0);
                if (((CoasterObj *) msg)->b18_21) {
                    return *(s16 *) ((u8 *) _sucoasterdata_entrypoint_1(
                                         (u32) *(u32 *) ((u8 *) msg + 0x18) >> 28) +
                                     0x58) +
                           ((arg >> 16) & 0xFFFF) + 1;
                }
            }
            return 0;
        case 0x4D:
            if (func_80107070(actor, 3) == 0) {
                return 0;
            }
            break;
        case 0x8F:
            switch (arg) {
                case 0:
                    func_8010A590(actor);
                    sucoaster_entrypoint_9(actor, 2, 8);
                case 4:
                    ((Coaster77 *) actor)->lo77 = 1;
                default:
                    goto brk;
            }
        case 0x29:
            func_80802690_sucoaster(actor, func_80100094(actor, 0));
            return 1;
        case 0x2A:
            func_80802728_sucoaster(actor, func_80100094(actor, 0));
            return 1;
        case 0x94:
            if (func_80100094(actor, 1) == 0) {
                return 0;
            }
            params.c = 0.0f;
            _suexpression_entrypoint_13(func_80100094(actor, 1), &params.b, &params);
            func_80101010(&params);
            return 1;
        case 0x95:
            _subaddierouteDll_entrypoint_1(actor);
            return 1;
        case 0x38:
            coaster = func_80100094(actor, 0);
            func_80101074(_sucoasterdata_entrypoint_5((u32) *(u32 *) (coaster + 0x18) >> 28,
                                                      ((Coaster6C *) actor)->f6C_9, &result));
            return result;
        case 0x9A:
            if (((u32) *(u16 *) (actor + 0x72) >> 10) != 0xC) {
                sucoaster_entrypoint_10(actor, 0xC);
                _subaddieDll_entrypoint_4(actor, 1);
            }
        brk:
        case 0x42:
            break;
        default:
            return 0;
    }
    return 1;
}

void sucoaster_entrypoint_22(s32 actor)
{
    u8 *coaster;
    f32 scale;
    f32 unk_0;
    u8 *kind_data;
    float unk_1;
    coaster = func_80100094(actor, 0);
    if ((func_801072A8(actor) == 0) || (func_801072E4(actor) != 0)) {
        kind_data = _sucoasterdata_entrypoint_1((u32) *(u32 *) ((s8 *) coaster + 0x18) >> 0x1C);
        scale = (f32) *(s16 *) ((s8 *) coaster + 0xC) * 0.00390625f;
        unk_1 = (f32) *(s16 *) ((s8 *) kind_data + 0x54) * scale;
        unk_0 = (f32) *(s16 *) ((s8 *) kind_data + 0x56) * scale;
        func_8010D6E0(actor, actor + 4, unk_0, unk_1);
    }
}

s32 func_8080202C_sucoaster(actor, coaster)
Actor *actor;
CoasterTrackItem *coaster;
{
    s32 node;
    f32 pos[3];
    node = func_80802760_sucoaster(coaster);
    if (node == -1)
        return 0;
    if (!func_800F6478(node))
        return 0;
    if (!coaster->local_0)
        return 1;
    func_800F5A00(node, pos);
    return func_800EFFB4(actor->position, 1800.0f, pos);
}

void func_808020B8_sucoaster(Actor *actor, CoasterPropKind *coaster, f32 scale)
{
    CoasterSpeedRecord *kind_data;
    kind_data = _sucoasterdata_entrypoint_1(coaster->local_0);
    func_80102BF8(actor, kind_data->unk4C * scale, kind_data->unk50 * scale,
                  kind_data->unk52 * scale);
}

typedef struct CoasterPropSize {
    u8 pad_0[0x10];
    s16 local_0;
    u8 pad_1[7];
    u8 pad_2 : 3;
    u8 local_1 : 1;
} CoasterPropSize;

void func_80802130_sucoaster(actor, coaster, size) Actor *actor;
CoasterPropSize *coaster;
s16 size;
{
    if (((CoasterActorFlags *) actor)->local_0 && actor->unk74_7 != 0x32) {
        coaster->local_0 = actor->unk74_7;
        coaster->local_1 = 1;
    } else {
        coaster->local_0 = actor->scale * size;
        coaster->local_1 = 0;
    }
}

typedef struct CoasterRadius1548 {
    u8 pad_0[12];
    s16 local_0;
    s16 local_1;
    s16 local_2;
    u8 pad_1[6];
    u32 local_3 : 4;
    u32 pad_2 : 7;
    u32 local_4 : 1;
} CoasterRadius1548;

f32 func_808021A8_sucoaster(actor, coaster, flags)
Actor *actor;
CoasterRadius1548 *coaster;
u32 flags;
{
    f32 unk_0;

    if ((flags & 0x1000) || coaster->local_4)
        return coaster->local_2;
    unk_0 = ((f32) coaster->local_1 / (f32) _sucoasterdata_entrypoint_4(coaster->local_3)) *
              ((f32) coaster->local_0 * 0.00390625f) * (f32) coaster->local_2;
    return func_800F0E00(func_80103EAC(actor) + 50.0f, unk_0);
}

void func_80802260_sucoaster(SuCoasterBits *actor, s32 coaster)
{
    func_8010A570(actor);
    actor->unk64_24 = 0;
    actor->unk70_4 = 0;
    actor->unk70_25 = actor->unk70_4;
    actor->unk64_30 = 0;
    actor->unk64_31 = actor->unk64_30;
    actor->unk14 &= ~0x80000;
    actor->unk77_0 = 2;
}

f32 func_8080230C_sucoaster(Actor *actor, s32 coaster)
{
    s32 unk_0;
    f32 angle;

    angle = func_80102D78(actor, (f32 *) actor->actorData);
    return func_800136E4((func_800F1DCC(actor->rotation[1], angle) > 0.0f ? 110.0f : -110.0f) +
                         angle);
}

s32 func_80802384_sucoaster(Actor *actor, u8 *coaster, f32 angle)
{
    f32 new_angle;
    new_angle = func_800136E4(func_800DC178(-20.0f, 20.0f) + angle);
    if (_subaddierouteDll_entrypoint_7(actor, coaster, new_angle, new_angle,
                                       *(s16 *) (coaster + 0x10), 2) == 0) {
        return 0;
    }
    return 1;
}

s32 func_80802400_sucoaster(Actor *actor, u8 *coaster)
{
    u8 *kind_data;
    f32 range;
    f32 node_pos[3];
    f32 unk_0;
    f32 speed;
    f32 unk_1;
    kind_data = (u8 *) _sucoasterdata_entrypoint_1(*(u32 *) (coaster + 0x18) >> 28);
    unk_0 = func_800F57F0((void *) func_80802760_sucoaster(coaster), node_pos);
    range = (u32) *(u16 *) (kind_data + 0x4A) * (*(s16 *) (coaster + 12) * 0.00390625f);
    speed = *(f32 *) ((u8 *) actor + 0x24);
    unk_1 = func_800D8FF8();
    while (speed > 0.0f) {
        range += unk_1 * speed;
        speed = func_800F15F8(speed, 0.0f, func_80107C00() * 30.0f);
    }
    range += unk_0;
    return func_800EFC7C(actor->position, node_pos) < range * range;
}

int func_80802550_sucoaster(s32 actor, s32 coaster)
{
    if (func_8080202C_sucoaster(actor, coaster)) {
        // Matching: the "| 0" is needed for the match.
        return !func_80802594_sucoaster(actor, coaster) | 0;
    }
    return 1;
}

s32 func_80802594_sucoaster(actor, state)
s32 *actor;
CoasterPropKind *state;
{
    CoasterSpeedRecord *params;
    s32 target;
    s32 unk_2;
    params = _sucoasterdata_entrypoint_1(state->local_0);
    target = func_80802760_sucoaster(state);
    if (target == -1)
        return 0;
    if (func_800F64A4(target, *(s32 *) ((u8 *) params + 0x40)))
        return 1;
    if (func_800F5C94(target) == 3)
        return 1;
    unk_2 = func_800F52B8(target, *actor);
    if (unk_2 == 0xF || unk_2 == 0x19)
        return 1;
    return 0;
}

f32 func_8080264C_sucoaster(u8 *actor, s32 state)
{
    s32 target = func_80802760_sucoaster(state);
    if (target == -1) {
        return *(f32 *) (actor + 0x48);
    }
    return func_8010CD50(actor, target);
}

// Starts the facial expression of the kind if none is active.
void func_80802690_sucoaster(s32 actor, u8 *state)
{
    u8 *params;

    params = _sucoasterdata_entrypoint_1((u32) *(u32 *) ((s8 *) state + 0x18) >> 0x1C);
    if ((func_80100094(actor, 1) == 0) &&
        (_suexpression_entrypoint_1(*(u8 *) ((s8 *) params + 3)) != 0)) {
        _suexpression_entrypoint_7(actor, 1, *(s16 *) ((s8 *) params + 2));
        _suexpression_entrypoint_12(func_80100094(actor, 1), 0x42700000, 0x42200000);
        _suexpression_entrypoint_17(func_80100094(actor, 1), 0x960);
    }
}

s32 func_80802728_sucoaster(actor, unk_1) void *actor;
s32 unk_1;
{

if (func_80100094(actor, 1)) {
    _suexpression_entrypoint_8(actor, 1);
}

}

s32 func_80802760_sucoaster(state) void *state;
{
    u32 state_word;
    int flag_bit;
    // Matching: the all-ones mask and the extra temporary are needed for the match.
    state_word = (*((u32 *) ((u8 *) state + 0x18))) & 0xFFFFFFFFFFFFFFFFu;
    flag_bit = state_word & 0x80000;

if (flag_bit) {
    return func_800F54E4();
}

return func_8010D290(*((s32 *) ((u8 *) _sucoasterdata_entrypoint_1(state_word >> 0x1C) + 0x3C)));
}
