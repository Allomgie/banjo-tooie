#include "common.h"

extern s32 func_800D90A4(f32 *);
extern void _capod_entrypoint_2(Unk80132ED0 *, s32, s32);
extern u32 D_80802674_chaliendad[];
extern int D_808026BC_chaliendad[];
extern int D_80802704_chaliendad[];
extern void *func_80100094(Actor *, u32);
extern void func_800EE940();
extern void func_800EE7F8(f32 *, f32 *);
extern void func_800EF214(f32 *, f32, f32, f32);
extern void func_80102424(Actor *, s32);
extern s32 D_808025C0_chaliendad[];
extern f32 D_808025D8_chaliendad[3];
extern u32 D_8080281C_chaliendad[];
extern int _gcdialogcamera_entrypoint_0(int, int);
extern s32 D_80802824_chaliendad[];
extern u8 D_808025E4_chaliendad[];
extern void _capod_entrypoint_6(Unk80132ED0 *, s32, s32);
extern void func_80105A9C(Actor *, f32);
extern f32 func_800D8FF8(void);
extern f32 func_800F12D4(f32, f32, f32, f32, f32);
extern void func_800EFE50(f32 *, f32 *, f32 *, f32);
extern void func_800EFA4C(f32 *, f32, f32, f32);
extern void func_800DE448(f32 *, f32 *, f32, s32, s32);
extern void func_801015D0(Actor *);
extern f32 func_800F15F8(f32, f32, f32);
typedef struct {
    u8 pad[0x72];
    u16 f72 : 6;
    u16 rest72 : 10;
} AlienState;
extern u8 D_80802834_chaliendad[];
extern void func_80103DFC(AlienState *, f32 *);
extern void _subaddieaudioloop_entrypoint_4();
extern void func_80018820(s32, f32, f32);
extern s32 func_80102320(Actor *, f32, f32);
extern s32 func_80101E14(Actor *, f32);
extern s32 _subaddieaudioquick_entrypoint_3(Actor *, f32 *, void *, f32);
extern void _subaddieaudioquick_entrypoint_2(Actor *, f32 *, void *);
extern void func_800EF1B8(f32 *, f32, f32);
extern s32 func_800BBCB8(f32 *, s32, f32, s32, s32 *);
extern s32 _sudeflect_entrypoint_0(f32 *, f32, f32, s32);
extern void _chbadshad_entrypoint_2(Actor *, s32, f32, s32);
typedef struct {
    u8 pad0[0x34];
    s32 unk34;
} AlienData;
typedef union {
    s32 i;
    struct {
        s16 a;
        s16 b;
    } h;
} AlienArg;
extern s32 _chlifeforcespell_entrypoint_1(Actor **, f32 *, s32, f32, s32);
extern Actor *func_80108528(s32, f32 *, s32, Actor **);
extern s32 _subaddieskeleton_entrypoint_2(Unk80132ED0 *, s32, f32 *);
extern void func_80108B04(Actor *, s32);
extern void func_800EE88C(f32 *, AlienData *);
extern s32 _glcutDll_entrypoint_19(s32);
extern void _glcutDll_entrypoint_17(void);
extern void func_800DA544(s32);
extern void func_800E39A8(f32 *, f32 *);
extern void _gcdialogcamera_entrypoint_3();
extern void _subaddiedialog_entrypoint_11(Unk80132ED0 *, s32, s32, f32 *, s32);
extern void func_800FFAB0(Actor *);
typedef struct {
    u8 pad_0[0x78];
    u32 pad_1 : 18;
    u32 local_0 : 2;
    u32 local_1 : 3;
    u32 pad_2 : 9;
} AlienDadBlink1506;
typedef struct {
    u8 pad_0[0x18];
    s16 local_0;
    f32 local_1;
    f32 local_2;
    f32 local_3;
} AlienDadExpressionData;
extern f32 func_800DC0C0(void);
typedef struct {
    u8 pad_0[0x1C];
    f32 local_0;
    f32 local_1;
    f32 local_2;
} AlienBlinkData271;
typedef struct {
    u8 pad_0[0x78];
    u32 pad_1 : 18;
    u32 local_0 : 2;
    u32 local_1 : 3;
    u32 pad_2 : 9;
} AlienBlink271;
extern f32 func_800F10B4(f32, f32, f32, f32, f32);
extern f32 func_800138D0(f32);
extern void func_80102FDC(Actor *, f32);
void func_80801C9C_chaliendad();
void func_80801D40_chaliendad();
int func_80801DD0_chaliendad();
void func_80802218_chaliendad();
void func_80802284_chaliendad();
void func_80801324_chaliendad();
void func_8080142C_chaliendad();
void func_8080152C_chaliendad();
void func_80801868_chaliendad();
extern void func_80105834(), func_80107C2C(), func_80800024_chaliendad(),
    func_808000AC_chaliendad(), func_80800918_chaliendad();

// Alien Dad (NPC 0x45A), the UFO (0x45B) and a small glow effect (0x467).
u8 *chaliendad_entrypoint_0(void)
{
    return D_80802674_chaliendad;
}

int chaliendad_entrypoint_1()
{
    return (int) &D_808026BC_chaliendad;
}

int chaliendad_entrypoint_2()
{
    return (int) &D_80802704_chaliendad;
}

void func_80800024_chaliendad(actor) Actor *actor;
{
    u8 *state;
    state = func_80100094(actor, 0);
    func_800EE940((s16 *) state, actor->position);
    func_800EE7F8((f32 *) &actor->actorData[4], actor->position);
    *(s16 *) (state + 6) = actor->rotation[1];
    func_80801324_chaliendad(actor, 0);
    if (func_80801DD0_chaliendad() == 3)
        func_800FFAB0(actor);
}

void func_808022CC_chaliendad();

void func_808012AC_chaliendad();

void func_808000AC_chaliendad(actor) Actor *actor;
{
    extern u8 D_8080274C_chaliendad[];
    extern u8 D_80802764_chaliendad[];
    extern u8 D_80802774_chaliendad[];
    extern u8 D_80802784_chaliendad[];
    extern u8 D_80802794_chaliendad[];
    extern u8 D_808027A4_chaliendad[];
    extern u8 D_808027B4_chaliendad[];
    extern u8 D_808027C0_chaliendad[];
    extern u8 D_808027CC_chaliendad[];
    extern u8 D_808027D4_chaliendad[];
    extern u8 D_808027FC_chaliendad[];
    extern u8 D_80802808_chaliendad[];
    extern u8 D_80802814_chaliendad[];

    char *state;
    char *expression;
    Actor *ufo;
    f32 pos[3];
    s32 unk_4;
    s32 saved_count;
    s32 i;
    s32 timer_done;
    char *ufo_data;
    f32 joint_pos[3];
    f32 delta;

    state = (char *) func_80100094(actor, 0);
    expression = (char *) func_80100094(actor, 1);

    if (expression != 0) {
        if (func_801022E4(actor) != 0x367) {
            _suexpression_entrypoint_18(expression, 1);
        }

        _suexpression_entrypoint_10(expression, *(s32 *) ((char *) actor + 0x0), 0);
    }

    switch (actor->unk70_10) {
        case 2:
            func_800EE7F8((char *) actor + 0x28, (char *) actor + 4);

            if (_subaddieaudioquick_entrypoint_3(actor, (char *) actor + 4,
                                                 D_80802764_chaliendad, 0.55f)) {
                func_80018820(0, 0.7f, 0.3f);
            }

            if (_subaddieaudioquick_entrypoint_3(actor, (char *) actor + 4,
                                                 D_80802774_chaliendad, 0.71f)) {
                func_80018820(0, 1.0f, 0.3f);
            }

            _subaddieaudioquick_entrypoint_3(actor, (char *) actor + 4, D_80802784_chaliendad,
                                             0.92f);

            _subaddieaudioquick_entrypoint_3(actor, (char *) actor + 4, D_80802794_chaliendad,
                                             0.56f);

            _subaddieaudioquick_entrypoint_3(actor, (char *) actor + 4, D_808027A4_chaliendad,
                                             0.75f);

            unk_4 = func_80102320(actor, 0.25f, 0.9f);

            *(u8 *) (state + 0x39) = _subaddieaudioloop_entrypoint_7(
                *(u8 *) (state + 0x39), (char *) actor + 4, unk_4, D_808027B4_chaliendad,
                *(s32 *) ((char *) actor + 0x70) & 1);

            if (func_80101DDC(actor)) {
                func_800EE88C((char *) actor + 4, state);

                *(f32 *) ((char *) actor + 0x8) += 6500.0f;
                *(f32 *) ((char *) actor + 0x48) = (f32) *(s16 *) (state + 6);

                func_80102424(actor, 3);

                _subaddiedialog_entrypoint_11(*(s32 *) ((char *) actor + 0), 0x1288, 0x44,
                                              (char *) actor + 4, 0x62);

                func_80801D40_chaliendad(actor, 7, 0x31, 0);

                *(f32 *) ((char *) actor + 0x24) = 800.0f;

                ufo = (Actor *) _subaddiefind_entrypoint_2(0x45B, 0);

                func_80102424(ufo, 4);
                ufo->unk64_16 = 1;
            }
            break;

        case 3:
            _subaddieaudioquick_entrypoint_3(actor, (char *) actor + 4, D_8080274C_chaliendad,
                                             0.4f);

            *(f32 *) ((char *) actor + 0x24) += func_800D8FF8() * 600.0f;

            *(f32 *) ((char *) actor + 0x8) -=
                func_800D8FF8() * *(f32 *) ((char *) actor + 0x24);
            break;

        case 4:
            _subaddieaudioquick_entrypoint_3(actor, (char *) actor + 4, D_8080274C_chaliendad,
                                             0.4f);

            *(f32 *) ((char *) actor + 0x24) += func_800D8FF8() * 400.0f;

            *(f32 *) ((char *) actor + 0x8) -=
                func_800D8FF8() * *(f32 *) ((char *) actor + 0x24);
            break;

        case 5:
            if (_subaddieaudioquick_entrypoint_3(actor, (char *) actor + 4,
                                                 D_808027C0_chaliendad, 0.155f)) {
                _subaddieaudioquick_entrypoint_2(actor, (char *) actor + 4,
                                                 D_808027CC_chaliendad);

                func_80018820(0, 2.0f, 0.3f);

                func_800EE7F8(pos, (char *) actor + 4);

                func_800EF1B8(pos, *(f32 *) ((char *) actor + 0x48), -100.0f);

                func_800BBCB8(pos, 0, 1.2f, 1, D_808027D4_chaliendad);

                _subaddiedialog_entrypoint_11(*(s32 *) ((char *) actor + 0), 0x1289, 0x44,
                                              (char *) actor + 4, 0x62);
            }

            if (func_80101E14(actor, 0.9f)) {
                func_80801324_chaliendad(actor, 1);
            }

            if (func_80101DDC(actor)) {
                func_80102424(actor, 6);
                _subaddieDll_entrypoint_4(actor, 0);
            }
            break;

        case 7:
            if (func_800D9078((char *) actor + 0x58)) {
                func_80102424(actor, 8);
            }
            break;

        case 8:
            if (func_80101E14(actor, 0.1f)) {
                func_80801324_chaliendad(actor, 3);
            }

            if (func_80101DDC(actor)) {
                func_800DA544(0x376);

                func_80801C9C_chaliendad(actor, 3, 1);

                _subaddiedialog_entrypoint_11(*(s32 *) ((char *) actor + 0), 0x1287, 0xE,
                                              (char *) actor + 4, 0x62);

                func_80102424(actor, 0xA);
            }
            break;

        case 11:
            if (func_80101E14(actor, 0.2f)) {
                func_80108B04(actor, 3);
            }

            if (func_80101DDC(actor) && func_800D9078((char *) actor + 0x58)) {
                func_80801C60_chaliendad(actor);

                func_8010114C(*(s32 *) (state + 0x28), 0x4A, 0);

                func_80102424(actor, 9);
            }
            break;

        case 9:
            func_80801B9C_chaliendad(actor);
            break;

        case 12:
            saved_count = 0;
            i = 0;

            while (i < 3) {
                if (func_800D9078(state + 0xC + i * 4)) {
                    func_8010114C(*(s32 *) (state + 0x28 + i * 4), 0x4E, 0);

                    *(u8 *) (state + 8 + i) = 1;
                    *(u8 *) (state + 0xB) = 1;
                }

                if (*(u8 *) (state + 8 + i)) {
                    saved_count++;
                }

                i++;
            }

            if (saved_count == 3) {
                func_80801D40_chaliendad(actor, 0x41, 0x30, 0);

                func_80102424(actor, 0xD);
                func_80108B04(actor, 2);
                *(f32 *) ((char *) actor + 0x58) = 2.0f;
            }
            break;

        case 13:
            if (func_80101DDC(actor) && func_800D9078((char *) actor + 0x58)) {
                _subaddieaudioquick_entrypoint_2(actor, (char *) actor + 4,
                                                 D_808027FC_chaliendad);

                func_80102424(actor, 0xE);

                *(f32 *) ((char *) actor + 0x58) = 4.0f;
                *(f32 *) ((char *) actor + 0x24) = 50.0f;
                *(f32 *) ((char *) actor + 0x18) = 0.5f;
            }
            break;

        case 14:
            timer_done = func_800D9078((char *) actor + 0x58);

            *(f32 *) ((char *) actor + 0x24) += func_800D8FF8() * 100.0f;

            delta = *(f32 *) ((char *) actor + 0x24) * func_800D8FF8();
            *(f32 *) ((char *) actor + 0x8) += delta;

            if (func_800D9078((char *) actor + 0x18)) {
                _subaddieaudioquick_entrypoint_2(actor, (char *) actor + 4,
                                                 D_80802808_chaliendad);
            }

            if (timer_done) {
                ufo_data = (char *) _subaddiefind_entrypoint_2(0x45B, 0);

                func_8010114C(*(s32 *) ((char *) actor + 0x3C), 0x4F, 0);

                *(s32 *) ((char *) actor + 0x3C) = 0;

                func_800D1000(0x45, 1, (char *) actor + 4, 0, 0);

                func_80801D40_chaliendad(actor, 0x47, 0x31, *(s32 *) ufo_data);

                func_808022CC_chaliendad(ufo_data);

                *(u8 *) ((char *) actor + 0x65) &= ~1;
                func_80102424(actor, 0xF);
            }
    }

    *(u8 *) (state + 0x38) = _subaddieaudioloop_entrypoint_7(
        *(u8 *) (state + 0x38), (char *) actor + 4, *(u8 *) (state + 0xB),
        D_80802814_chaliendad, *(s32 *) ((char *) actor + 0x70) & 1);

    if (_subaddieskeleton_entrypoint_0(actor, 0x2C, joint_pos)) {
        _sudeflect_entrypoint_0(joint_pos, 0, 125.0f, 2);
    }

    if (_subaddieskeleton_entrypoint_0(actor, 1, joint_pos)) {
        _sudeflect_entrypoint_0(joint_pos, 0, 125.0f, 2);
    }

    func_808012AC_chaliendad(actor);

    if (actor->unk7C_12) {
        _chbadshad_entrypoint_2(actor, 3, actor->scale + actor->scale, 0);
    }
}

void func_80801E80_chaliendad();

s32 func_808008C8_chaliendad(actor) Actor *actor;
{
    u8 *state;

    state = func_80100094(actor, 0);
    state[0x38] = _subaddieaudioloop_entrypoint_3(state[0x38]);
    state[0x39] = _subaddieaudioloop_entrypoint_3(state[0x39]);
    func_80801E80_chaliendad(actor);
}

void func_80800918_chaliendad(actor, param_1) Actor *actor;
void *param_1;
{
    u8 *state;
    f32 angles[3];
    f32 spell_pos[3];
    f32 saved_pos[3];

    state = func_80100094(actor, 0);
    if (actor->unk70_10 == 2) {
        func_800E39A8(actor->position, angles);
        func_800EF214(actor->position, angles[0], angles[1], -1000.0f);
        actor->rotation[1] = angles[1];
        actor->rotation[0] = angles[0] + 15.0f;
        func_800DF744(3, 1);
    } else {
        func_800DF744(3, 0);
    }
    func_800DF744(1, ((*(u32 *) ((u8 *) actor + 0x78) << 20) >> 29) + 1);
    func_800DF744(2, ((*(u32 *) ((u8 *) actor + 0x78) << 20) >> 29) + 1);
    if (*(s32 *) (state + 0x34)) {
        _subaddiefade_entrypoint_9(actor, saved_pos);
        _chlifeforcespell_entrypoint_2(actor, *(s32 *) (state + 0x34), spell_pos);
        _subaddiefade_entrypoint_11(actor, spell_pos);
        func_80101870(actor, param_1);
        _subaddiefade_entrypoint_11(actor, saved_pos);
    } else {
        func_80101870(actor, param_1);
    }
}

s32 func_80801E28_chaliendad();

void func_80801220_chaliendad();

void func_80801110_chaliendad();

void func_80800F28_chaliendad();

s32 func_80800A54_chaliendad(Actor *actor, s32 msg, AlienArg arg)
{
    AlienData *state;
    f32 spell_pos[3];
    f32 ufo_pos[3];
    AlienArg *unpacked_a;
    f32 joint_pos[3];
    AlienArg *unpacked_b;
    Actor *spawned;
    f32 angles[2];

    state = func_80100094(actor, 0);
    switch (msg) {
        case 0x95:
            func_80800F28_chaliendad(actor);
            return 1;
        case 0x2E:
            unpacked_a = &arg;
            func_80801110_chaliendad(actor, unpacked_a->h.a, unpacked_a->h.b);
            return 1;
        case 0x2F:
            unpacked_b = &arg;
            func_80801220_chaliendad(actor, unpacked_b->h.a, unpacked_b->h.b);
            return 1;
        case 0x3D:
            switch (arg.i) {
                case 0:
                    func_800EE7F8(spell_pos, actor->position);
                    spell_pos[1] += 60.0f;
                    state->unk34 =
                        _chlifeforcespell_entrypoint_1(&actor, spell_pos, 150, 3.2f, 0x12);
                    break;
                case 1:
                    func_800EE7F8(ufo_pos, actor->position);
                    ufo_pos[1] += 2000.0f;
                    func_80108528(0x45B, ufo_pos, 0, &actor);
                    return 1;
                case 2:
                    actor->unk3C = func_80108528(0x466, actor->position, 0, &actor)->unk0;
                    break;
                case 3:
                    if (_subaddieskeleton_entrypoint_2(actor->unk0, 4, joint_pos)) {
                        spawned = func_80108528(0x467, joint_pos, 0, &actor);
                        spawned->unk3C = actor->unk0;
                    }
            }
            break;
        case 0x4B:
            func_80108B04(actor, 0);
            func_80801D40_chaliendad(actor, 0x15, 0x30, 0);
            func_80102424(actor, 7);
            actor->unk58 = 6.0f;
            break;
        case 0x4C:
            state->unk34 = 0;
            break;
        case 0xB:
            switch (arg.i) {
                case 7:
                    func_800EE88C(actor->position, state);
                    actor->position[1] += 6500.0f;
                    func_80102424(actor, 4);
                    func_80801D40_chaliendad(actor, 0x2D, 0x31, 0);
                    ((f32 *) actor->actorData)[3] = 800.0f;
                    return 4;
                case 0x2D:
                    func_800EE88C(actor->position, state);
                    func_80801D40_chaliendad(actor, 0x27, 0x30, 0);
                    func_80102424(actor, 5);
                    return 4;
                case 0x27:
                    func_80801C60_chaliendad(actor);
                    if (_glcutDll_entrypoint_19(0x4A)) {
                        _glcutDll_entrypoint_17();
                    }
                    func_800DA544(0x375);
                    return 4;
            }
            return 3;
        case 0xE:
            if (actor->unk70_10 == 2) {
                func_800E39A8(actor->position, angles);
                func_800EF214(actor->position, angles[0], angles[1], -1000.0f);
                actor->rotation[1] = angles[1];
                actor->rotation[0] = angles[0] + 15.0f;
            }
            return 3;
        case 0x52:
            _gcdialogcamera_entrypoint_3(D_808025E4_chaliendad, *(s32 *) &actor->scale);
            return 1;
        case 0x57:
            return func_80801254_chaliendad(actor, arg.i & 0xFFFF,
                                            (arg.i & 0xFFFF0000) >> 16);
        case 0x31:
            if (arg.i == 0x45B) {
                func_80801D40_chaliendad(actor, 0x1A, 0x30, 0);
                _subaddiedialog_entrypoint_11(actor->unk0, 0x12AA, 7, actor->position, 0x62);
                func_80102424(actor, 10);
                return 1;
            }
            if (func_80801DD0_chaliendad() == 3) {
                func_80108B04(actor, 1);
                func_80801D40_chaliendad(actor, 0x45, 0x2030, 0);
            }
            break;
        case 0x29:
            func_80801E28_chaliendad(actor);
            return 1;
        case 0x2A:
            func_80801E80_chaliendad(actor);
            return 1;
        case 0x2C:
            func_80801C60_chaliendad(actor);
            func_800FFAB0(actor);
            return 1;
        case 0xB8:
            return 0x12A9 - func_80801DD0_chaliendad();
        default:
            return 0;
    }
    return 1;
}

void func_80800F28_chaliendad(Actor *actor)
{
    u8 *state;
    Actor *ufo;
    s32 pad[2];
    s32 cutscene_active;
    s32 unk_3;
    s32 dialog_flags;
    s32 unk_5;
    Actor *kid;
    s32 unk_8;
    u8 *kid_slot;

    state = func_80100094(actor, 0);
    ufo = _subaddiefind_entrypoint_2(0x45B, 0);
    actor->unk64_20 = 0;
    if (!func_800DA298(0x375)) {
        cutscene_active = _glcutDll_entrypoint_19(0x4A);
        unk_3 = 0;
        dialog_flags = 0x30;
        if (!cutscene_active && !func_800DB9B0()) {
            if (func_800DA298(0xB6)) {
                unk_5 = func_800EA090();
                unk_8 = unk_5 != 10;
                if (unk_8) {
                    unk_8 = unk_5 != 6;
                }
                if (unk_8) {
                    unk_3 = 1;
                }
            }
        } else {
            dialog_flags = 0x2830;
        }
        if (cutscene_active || unk_3) {
            actor->unk64_20 = 1;
            func_80102424(actor, 1);
            func_80101FDC(ufo, 2);
            *(u8 *) ((u8 *) actor + 0x65) &= ~1;
            _subaddiedialog_entrypoint_11(actor->unk0, 0x12A0, 0x44, actor->position, 0x62);
            func_80801D40_chaliendad(actor, 0x2A, dialog_flags, ufo->unk0);
        }
    }
    unk_3 = 0;
    kid_slot = state;
    do {
        kid = _subaddiefind_entrypoint_2(unk_3 + 0x456, 0);
        *(Unk80132ED0 **) (kid_slot + 0x28) = kid ? kid->unk0 : NULL;
        unk_3++;
        kid_slot += 4;
    } while (unk_3 != 3);
    if (!actor->unk64_20) {
        func_800FFAB0(ufo);
        if (!func_800DA298(0x375)) {
            func_800FFAB0(actor);
            return;
        }
        if (!func_800DA298(0x376)) {
            func_80801324_chaliendad(actor, 2);
            func_80102424(actor, 6);
        }
    }
}

void func_80801110_chaliendad(Actor *actor, s32 dialog_id, s32 param_2)
{
    f32 *data;
    s32 i;

    data = (f32 *) func_80100094(actor, 0);
    switch (dialog_id) {
        case 0x1287:
            func_80102424(actor, 0xB);
            _subaddiedialog_entrypoint_11(actor->unk0, 0x12B4, 0x144, actor->position, 0x62);
            func_80801D40_chaliendad(actor, 0x37, 0x30, NULL);
            actor->unk58 = 1.5f;
            break;
        case 0x12AA:
            func_80801D40_chaliendad(actor, 0x49, 0x30, NULL);
            func_80102424(actor, 0xC);
            for (i = 0; i < 3; i++) {
                data[i + 3] = D_808025D8_chaliendad[i];
            }
            break;
        default:
            if (_subaddiedialog_entrypoint_9(actor, dialog_id, &D_808025C0_chaliendad, 3)) {
                func_80102424(actor, 9);
            }
    }
}

void func_80801220_chaliendad(s32 actor, s32 dialog_id, s32 param_2)
{
    if (dialog_id == 0x12A0) {
        _subaddieaudioquick_entrypoint_2(actor, actor + 4, &D_8080281C_chaliendad);
    }
}

int func_80801254_chaliendad(Actor *actor, s32 param_1, s32 param_2)
{
    if (_gcdialogcamera_entrypoint_0(param_1 | 0, param_2 | 0)) {
        if (*(s32 *) ((char *) actor + 0x1C) != 2) {
            func_80801C9C_chaliendad((u8 *) actor, 2, 1);
        }
        return 2;
    }
    return 1;
}

void func_808012AC_chaliendad(Actor *actor)
{
    u8 *state;

    state = (u8 *) func_80100094(actor, 0);
    switch (*(s16 *) (state + 0x18)) {
        case 0:
            func_8080142C_chaliendad(actor);
            break;
        case 1:
            func_8080152C_chaliendad(actor);
            break;
        case 3:
            func_80801868_chaliendad(actor);
    }
}

void func_80801324_chaliendad(actor, expression) Actor *actor;
s32 expression;
{
    AlienDadExpressionData *data;

    data = (AlienDadExpressionData *) func_80100094(actor, 0);
    data->local_0 = expression;
    switch (expression) {
        case 0:
            ((AlienDadBlink1506 *) actor)->local_0 = 0;
            ((AlienDadBlink1506 *) actor)->local_1 = 0;
            break;
        case 1:
            ((AlienDadBlink1506 *) actor)->local_0 = 0;
            ((AlienDadBlink1506 *) actor)->local_1 = 0;
            data->local_2 = data->local_3 = 0.8f;
            data->local_1 = 6.0f;
            break;
        case 2:
            ((AlienDadBlink1506 *) actor)->local_1 = 3;
            data->local_2 = data->local_3 = 0.4f;
            break;
        case 3:
            ((AlienDadBlink1506 *) actor)->local_0 = 2;
            ((AlienDadBlink1506 *) actor)->local_1 = 3;
            data->local_2 = data->local_3 = 0.3f;
            data->local_1 = 5.0f;
    }
}

void func_8080142C_chaliendad(actor) Actor *actor;
{
    AlienDadBlink1506 *blink = (AlienDadBlink1506 *) actor;

    switch (blink->local_0) {
        case 0:
            if (func_800DC0C0() < 0.03f)
                blink->local_0 = 1;
            break;
        case 1:
            if (blink->local_1 == 3)
                blink->local_0 = 3;
            else
                blink->local_1++;
            break;
        case 3:
            blink->local_1--;
            if (!blink->local_1)
                blink->local_0 = 0;
    }
}

void func_8080152C_chaliendad(actor) Actor *actor;
{
    AlienBlinkData271 *data;
    f32 progress;
    f32 phase_t;
    s32 done;

    data = func_80100094(actor, 0);
    func_800D90A4(&data->local_0);
    done = func_800D90A4(&data->local_1);
    progress = func_800F10B4(data->local_0, 0.0f, 6.0f, 1.0f, 0.0f);
    phase_t = func_800F10B4(data->local_1, 0.0f, data->local_2, 1.0f, 0.0f);
    switch (((AlienBlink271 *) actor)->local_0) {
        case 0:
            if (func_800D90A4(&data->local_1)) {
                f32 target;
                ((AlienBlink271 *) actor)->local_0 = 1;
                target = func_800F10B4(progress, 0.0f, 1.0f, 0.1f, 0.8f);
                data->local_2 = target;
                data->local_1 = target;
            }
            break;
        case 1:
            if (((AlienBlink271 *) actor)->local_1 == 3) {
                if (func_800D90A4(&data->local_1)) {
                    f32 target;
                    ((AlienBlink271 *) actor)->local_0 = 2;
                    target = func_800F10B4(progress, 0.0f, 1.0f, 0.0f, 0.8f);
                    data->local_2 = target;
                    data->local_1 = target;
                }
            } else {
                ((AlienBlink271 *) actor)->local_1++;
            }
            break;
        case 2:
            if (func_800D90A4(&data->local_1)) {
                f32 target;
                ((AlienBlink271 *) actor)->local_0 = 3;
                target = func_800F10B4(progress, 0.0f, 1.0f, 0.1f, 0.8f);
                data->local_2 = target;
                data->local_1 = target;
            }
            break;
        case 3: {
            s32 frame;

            frame = (s32) func_800F10B4(progress, 0.0f, 1.0f, 0.f, 2.0f);
            ((AlienBlink271 *) actor)->local_1 =
                (u32) func_800F10B4(phase_t, 0.0f, 1.0f, (f32) frame, 3.0f);
            if (done) {
                f32 target;
                ((AlienBlink271 *) actor)->local_1 = frame;
                ((AlienBlink271 *) actor)->local_0 = 0;
                target = func_800F10B4(progress, 0.0f, 1.0f, 0.8f, 0.01f);
                data->local_2 = target;
                data->local_1 = target;
                if (progress == 1.0f) {
                    func_80801324_chaliendad(actor, 2);
                }
            }
            break;
        }
    }
}

void func_80801868_chaliendad(actor) Actor *actor;
{
    AlienBlinkData271 *data;
    f32 progress;
    f32 phase_t;
    s32 done;

    data = func_80100094(actor, 0);
    func_800D90A4(&data->local_0);
    done = func_800D90A4(&data->local_1);
    progress = func_800F10B4(data->local_0, 0, 6.0f, 1.0f, 0);
    phase_t = func_800F10B4(data->local_1, 0, data->local_2, 1.0f, 0);
    switch (((AlienBlink271 *) actor)->local_0) {
        case 0:
            if (func_800D90A4(&data->local_1)) {
                f32 target;
                ((AlienBlink271 *) actor)->local_0 = 1;
                target = func_800F10B4(progress, 0, 1.0f, 0.8f, 0.1f);
                data->local_2 = target;
                data->local_1 = target;
            }
            break;
        case 1:
            if (((AlienBlink271 *) actor)->local_1 == 3) {
                if (func_800D90A4(&data->local_1)) {
                    f32 target;
                    ((AlienBlink271 *) actor)->local_0 = 2;
                    target = func_800F10B4(progress, 0, 1.0f, 0.8f, 0);
                    data->local_2 = target;
                    data->local_1 = target;
                }
            } else {
                ((AlienBlink271 *) actor)->local_1++;
            }
            break;
        case 2:
            if (func_800D90A4(&data->local_1)) {
                f32 target;
                ((AlienBlink271 *) actor)->local_0 = 3;
                target = func_800F10B4(progress, 0, 1.0f, 0.8f, 0.1f);
                data->local_2 = target;
                data->local_1 = target;
            }
            break;
        case 3: {
            s32 frame;

            frame = func_800F10B4(progress, 0, 1.0f, 2.0f, 0.f);
            ((AlienBlink271 *) actor)->local_1 =
                (u32) func_800F10B4(phase_t, 0, 1.0f, (f32) frame, 3.0f);
            if (done) {
                f32 target;
                ((AlienBlink271 *) actor)->local_1 = frame;
                ((AlienBlink271 *) actor)->local_0 = 0;
                target = func_800F10B4(progress, 0, 1.0f, 0.01f, 0.08f);
                data->local_2 = target;
                data->local_1 = target;
                if (progress == 1.0f) {
                    func_80801324_chaliendad(actor, 0);
                }
            }
            break;
        }
    }
}

int func_80801B9C_chaliendad(s32 actor)
{
    s32 option_count;
    option_count = 3;
    _subaddiedialog_entrypoint_8(actor, actor + 4, &D_80802824_chaliendad,
                                 &D_808025C0_chaliendad, option_count);
}

void func_80801BD4_chaliendad(void *actor)
{
    u8 *raw;
    // Matching: the repeated masks are needed for the match.
    raw = (u8 *) actor;
    raw[0x65] =
        (((((((((((raw[0x65] & 0xFFFFu) & 0xFFFFu) & 0xFFFFu) & 0xFFFFu) & 0xFFFFu) & 0xFFFFu) &
             0xFFFFu) &
            0xFFFFu) &
           0xFFFFu) &
          0xFFFFu) &
         0xFFFFu) |
        1;
    _subaddieDll_entrypoint_4(actor, 1);
    func_80102424(actor, 2);
    _subaddiedialog_entrypoint_11(*(void ***) actor, 0x12B3, 0x44, (void *) ((u8 *) actor + 4),
                                  0x62);
    func_80801D40_chaliendad(actor, 0x22, 0x30, 0);
    raw = _subaddiefind_entrypoint_2(0x45B, 0);
    raw[0x65] = raw[0x65] & 0xFFFE;
}

int func_80801C60_chaliendad(Actor *actor)
{
    if (*(s32 *) ((char *) actor + 0x1C) != 0) {
        _capod_entrypoint_3(0, actor);
        *(s32 *) ((char *) actor + 0x1C) = 0;
    }
}

void func_80801C9C_chaliendad(actor, param_1, param_2) u8 *actor;
s32 param_1;
s32 param_2;
{
    s32 state;

    state = *(s32 *) ((u8 *) actor + 0x1C);
    switch (state) {
        case 0:
            _capod_entrypoint_2(*(s32 *) actor, 0xD, 0);

        case 1:
            _capod_entrypoint_8(1);
            *(s32 *) ((u8 *) actor + 0x1C) = 2;
            _gcdialogcamera_entrypoint_3(&D_808025E4_chaliendad, *(s32 *) ((u8 *) actor + 0x38));
            _gcdialogcamera_entrypoint_4(actor + 4);
            _gcdialogcamera_entrypoint_5(actor + 0x44);
            _gcdialogcamera_entrypoint_8();

        case 2:
            _capod_entrypoint_7(param_1, param_2);
    }
}

void func_80801D40_chaliendad(actor, param_1, param_2, speaker) Actor *actor;
s32 param_1;
s32 param_2;
Unk80132ED0 *speaker;
{
    if (speaker == NULL) {
        speaker = actor->unk0;
    }
    switch (actor->actorData[1]) {
        case 0:
            _capod_entrypoint_2(actor->unk0, 13, param_2);
        case 2:
            actor->actorData[1] = 1;
        case 1:
            _capod_entrypoint_6(speaker, param_1, param_2);
    }
}

// Counts the saved kids (flags 0x372..0x374).
int func_80801DD0_chaliendad()
{
    s32 i;
    s32 count = 0;
    s32 unk_2 = 0;
    for (i = 0; i < 3; i++) {
        if (func_800DA298(i + 0x372)) {
            count++;
        }
    }

    return count | unk_2;
}

s32 func_80801E28_chaliendad(s32 actor)
{
    s32 expression;

    if (!func_80100094(actor, 1)) {
        expression = _suexpression_entrypoint_7(actor, 1, 0x62);
        _suexpression_entrypoint_12(expression, 0x42700000, 0x41700000);
        _suexpression_entrypoint_17(expression, 0x3E8);
    }
}

void func_80801E80_chaliendad(Actor *actor)
{
    if (func_80100094(actor, 1) != 0) {
        _suexpression_entrypoint_8(actor, 1);
    }
}

void func_80801EB4_chaliendad(Actor *actor)
{
    f32 *data;

    data = func_80100094(actor, 0);
    data[2] = actor->rotation[1];
    if (func_80105494(actor)) {
        data[0] = 100.0f;
        data[1] = 100.0f;
        func_80105A9C(actor, 1200.0f);
        if (func_80801DD0_chaliendad() == 3) {
            func_800FFAB0(actor);
        }
    } else {
        data[1] = 100.0f;
        data[0] = 10.0f;
        func_800EE7F8((f32 *) ((u8 *) actor + 0x28), actor->position);
        func_800EE7F8((f32 *) ((u8 *) actor + 0x18), actor->position);
        *(f32 *) ((u8 *) actor + 0x1C) = 1000.0f;
        func_80101FDC(actor, 5);
        actor->unk58 = 6.0f;
    }
}

void func_80801F98_chaliendad(u8 *actor)
{
    u32 state;
    func_80802218_chaliendad((Actor *) actor);
    do {
        state = (u16) *(u16 *) ((s8 *) actor + 0x72);
        state = state >> 0xA;
        switch (state) {
            case 3:
                break;
            case 2:
                func_80105834(actor);
                if (func_80105998(actor, 0x3F4CCCCD) != 0) {
                    func_80102424(actor, 3);
                    func_80801BD4_chaliendad(_subaddiefind_entrypoint_2(0x45A, 0));
                }
                break;
            case 4:
                func_80105834(actor);
                if (func_80105A5C(actor) != 0) {
                    func_800FFAB0(actor);
                }
                break;
        }
    } while (0);
    func_80802284_chaliendad(actor);
}

void func_80802058_chaliendad(Actor *actor)
{
    s32 timer_done;
    f32 blend;
    s32 takeoff_done;

    func_80802218_chaliendad(actor);
    switch (actor->unk70_10) {
        case 6:
            break;
        case 5:
            timer_done = func_800D9078(&actor->unk58);
            blend = func_800F12D4(actor->unk58, 0.0f, 6.0f, 1.0f, 0.0f);
            func_800EFE50(actor->position, (f32 *) &actor->actorData[4],
                          (f32 *) actor->actorData, blend);
            if (timer_done) {
                func_80101180(0x45A, 0x31, actor->unk6C_9);
                func_80102424(actor, 6);
            }
            break;
        case 7:
            takeoff_done = func_800D9078(&actor->unk58);
            *(f32 *) &actor->actorData[3] += func_800D8FF8() * 300.0f;
            actor->position[1] += *(f32 *) &actor->actorData[3] * func_800D8FF8();
            if (takeoff_done) {
                func_80101180(0x45A, 0x2C, 0);
                func_800FFAB0(actor);
            }
    }
    func_80802284_chaliendad(actor);
}

void func_80802188_chaliendad(Actor *actor, s32 param_1)
{
    f32 rot[3];
    f32 *data;
    data = func_80100094(actor, 0);
    func_80101970(actor);
    func_800EFA4C(rot, actor->rotation[0], data[2], actor->rotation[2]);
    func_800DF47C(func_801015D0, actor);
    func_800DE448(actor->position, rot, actor->scale, func_801018D8(actor),
                  func_8010347C(actor->unk0));
}

void func_80802218_chaliendad(actor) Actor *actor;
{
    f32 *data;
    f32 dt;
    data = (f32 *) func_80100094(actor, 0);
    dt = func_800D8FF8();
    data[1] = func_800F15F8(data[1], data[0], dt * 15.0f);
    data[2] += data[1] * dt;
}

void func_80802284_chaliendad(alien) AlienState *alien;
{
    f32 pos[3];
    func_80103DFC(alien, pos);
    _subaddieaudioloop_entrypoint_4(alien, pos, alien->f72 != 1, D_80802834_chaliendad);
}

void func_808022CC_chaliendad(Actor *actor)
{
    f32 *glow;

    glow = (f32 *) func_80100094(actor, 0);
    func_80102424(actor, 7);
    *(f32 *) &actor->actorData[3] = 100.0f;
    actor->unk58 = 5.0f;
    glow[0] = 100.0f;
    glow[1] = 10.0f;
}

void func_80802330_chaliendad(void *actor)
{
    *(float *) ((char *) actor + 0x58) = 0.85f;
}

void func_80802340_chaliendad(Actor *actor)
{
    s32 timer_done;

    _subaddieskeleton_entrypoint_2(actor->unk3C, 4, actor->position);

switch (actor->unk70_10) {
    case 1:
        timer_done = func_800D9078(&actor->unk58);
        func_80102FDC(actor, func_800F12D4(actor->unk58, 0.0f, 0.85f, 0.2f, 0.08f));
        if (timer_done) {
            func_80102424(actor, 2);
            actor->unk58 = 2.5f;
        }
        break;
    case 2:
        *(f32 *) ((u8 *) actor + 0x24) += func_800D8FF8() * 800.0f;
        func_80102FDC(actor,
                      func_800138D0(*(f32 *) ((u8 *) actor + 0x24)) * 0.080000006f + 0.2f);
        if (func_800D9078(&actor->unk58)) {
            func_80102424(actor, 3);
            _subaddiefade_entrypoint_3(actor);
        }
    case 3:
        break;
}

}

extern int func_80101870();
extern void func_80108ED0();
s32 D_808025C0_chaliendad[6] = {0x601, -0xFE00, 0x1000, 0x12D50200, -0x12001, 0x120F0300};
f32 D_808025D8_chaliendad[3] = {1.5f, 3.0f, 4.5f};
u8 D_808025E4_chaliendad[16] = {0x43, 0x87, 0x0, 0x0, 0x43, 0x48, 0x0, 0x0,
                                0x43, 0x34, 0x0, 0x0, 0x42, 0xA0, 0x0, 0x0};
u8 D_808025F4_chaliendad[128] = {
    0x0,  0x0,  0x0,  0x0,  0x0, 0x0,  0x0, 0x0,  0x0,  0x0,  0x0,  0x0,  0x0, 0x0,  0x0, 0x0,
    0x41, 0x50, 0x0,  0x0,  0x3, 0x63, 0x0, 0x2,  0x3F, 0x14, 0x7A, 0xE1, 0x3, 0x64, 0x0, 0x1,
    0x3F, 0x14, 0x7A, 0xE1, 0x3, 0x64, 0x0, 0x1,  0x40, 0xBE, 0x66, 0x66, 0x3, 0x65, 0x2, 0x2,
    0x40, 0xBE, 0x66, 0x66, 0x3, 0x65, 0x0, 0x84, 0x40, 0xBE, 0x66, 0x66, 0x3, 0x65, 0x0, 0x84,
    0x40, 0xD0, 0x0,  0x0,  0x3, 0x66, 0x0, 0x42, 0x40, 0x12, 0x8F, 0x5C, 0x3, 0x67, 0x0, 0x1,
    0x40, 0x12, 0x8F, 0x5C, 0x3, 0x67, 0x0, 0x1,  0x40, 0x0,  0x0,  0x0,  0x3, 0x68, 0x0, 0x2,
    0x40, 0x12, 0x8F, 0x5C, 0x3, 0x67, 0x0, 0x1,  0x40, 0x56, 0x66, 0x66, 0x3, 0x28, 0x0, 0x2,
    0x40, 0x56, 0x66, 0x66, 0x3, 0x28, 0x0, 0x84, 0x0,  0x0,  0x0,  0x0,  0x0, 0x0,  0x0, 0x0};
u32 D_80802674_chaliendad[18] = {0x158045A,
                                 0x8070009,
                                 (u32) &D_808025F4_chaliendad,
                                 (u32) func_808000AC_chaliendad,
                                 (u32) func_80105834,
                                 (u32) func_80800918_chaliendad,
                                 0xBB80000,
                                 0x0,
                                 0x0,
                                 0x40060,
                                 (u32) func_808008C8_chaliendad,
                                 0x0,
                                 0x3C0000,
                                 (u32) func_80800024_chaliendad,
                                 (u32) func_80107C2C,
                                 0x84400412,
                                 (u32) func_80800A54_chaliendad,
                                 0x0};
int D_808026BC_chaliendad[18] = {0x1580467,
                                 0x7FB0001,
                                 0x0,
                                 (u32) func_80802340_chaliendad,
                                 (u32) func_80105834,
                                 (u32) func_80101870,
                                 0x0,
                                 0x0,
                                 0x0,
                                 0x21004,
                                 0x0,
                                 0x0,
                                 0x0,
                                 (u32) func_80802330_chaliendad,
                                 (u32) func_80107C2C,
                                 -0x7FFFFBFE,
                                 0x0,
                                 0x0};
int D_80802704_chaliendad[18] = {0x158045B,
                                 0x6FC0001,
                                 0x0,
                                 (u32) func_80802058_chaliendad,
                                 (u32) func_80801F98_chaliendad,
                                 (u32) func_80802188_chaliendad,
                                 0x0,
                                 0x0,
                                 0x0,
                                 0x1400,
                                 0x0,
                                 (u32) func_80108ED0,
                                 0xC0000,
                                 (u32) func_80801EB4_chaliendad,
                                 (u32) func_80107C2C,
                                 -0x7FFFFBFE,
                                 0x0,
                                 0x0};
u8 D_8080274C_chaliendad[24] = {0x0, 0x13, 0x3,  0xFF, 0x0, 0xD,  0x0,  0xD9, 0x0, 0xF3, 0x0, 0x1,
                                0x3, 0x20, 0x13, 0x88, 0x0, 0x16, 0x1F, 0x40, 0x0, 0x0,  0x0, 0x0};
u8 D_80802764_chaliendad[16] = {0x0, 0x13, 0x4, 0xB5, 0x0,  0xA,  0x0, 0xD9,
                                0x0, 0x2,  0x0, 0x16, 0x61, 0xA8, 0x0, 0x0};
u8 D_80802774_chaliendad[16] = {0x0, 0x13, 0x4, 0xCE, 0x0, 0xA, 0x1, 0x70,
                                0x0, 0x2,  0x0, 0x18, 0x0, 0x0, 0x0, 0x0};
u8 D_80802784_chaliendad[16] = {0x0, 0x13, 0x4, 0x46, 0x0, 0xA, 0x1, 0x99,
                                0x0, 0x2,  0x0, 0x18, 0x0, 0x0, 0x0, 0x0};
u8 D_80802794_chaliendad[16] = {0x0, 0x13, 0x5, 0xCC, 0x0, 0xA, 0x1, 0x33,
                                0x0, 0x2,  0x0, 0x18, 0x0, 0x0, 0x0, 0x0};
u8 D_808027A4_chaliendad[16] = {0x0, 0x13, 0x5, 0xCD, 0x0, 0xA, 0x1, 0x33,
                                0x0, 0x2,  0x0, 0x18, 0x0, 0x0, 0x0, 0x0};
u8 D_808027B4_chaliendad[12] = {0x0, 0x13, 0x5, 0xF0, 0x0, 0x2, 0x0, 0x16, 0x75, 0x30, 0x0, 0x0};
u8 D_808027C0_chaliendad[12] = {0x0, 0x13, 0x4, 0x1F, 0x0, 0x2, 0x0, 0x18, 0x0, 0x0, 0x0, 0x0};
u8 D_808027CC_chaliendad[8] = {0x0, 0x13, 0x4, 0x15, 0x0, 0x2, 0x0, 0x0};
u8 D_808027D4_chaliendad[40] = {0x0, 0x1D, 0x8, 0x21, 0x0, 0x16, 0x2, 0x0,  0x0, 0x2B,
                                0xA, 0x0,  0xA, 0x0,  0x0, 0x22, 0x0, 0xCC, 0x0, 0xCC,
                                0x3, 0x80, 0x3, 0x80, 0x0, 0x15, 0x0, 0x0,  0x0, 0xC0,
                                0x0, 0x1E, 0x0, 0x4,  0x0, 0x4,  0x0, 0x0,  0x0, 0x0};
u8 D_808027FC_chaliendad[12] = {0x0, 0x13, 0x5, 0xF1, 0x0, 0xD, 0x0, 0xF3, 0x1, 0xC, 0x0, 0x0};
u8 D_80802808_chaliendad[12] = {0x0, 0x13, 0x5, 0xF1, 0x0, 0xD, 0x0, 0xF3, 0x1, 0xC, 0x0, 0x0};
u8 D_80802814_chaliendad[8] = {0x0, 0x13, 0x5, 0xEF, 0x0, 0x2, 0x0, 0x0};
u32 D_8080281C_chaliendad[2] = {0x13051C, 0x20000};
s32 D_80802824_chaliendad[4] = {0x0, 0x1C20062, 0xC, 0x63C0A00};
u8 D_80802834_chaliendad[28] = {0x0, 0x13, 0x4, 0xDF, 0x0,  0x16, 0x2E, 0xE0, 0x0, 0x2,
                                0x0, 0x1,  0x7, 0xD0, 0x1F, 0x40, 0x0,  0x0,  0x0, 0x0,
                                0x0, 0x0,  0x0, 0x0,  0x0,  0x0,  0x0,  0x0};
