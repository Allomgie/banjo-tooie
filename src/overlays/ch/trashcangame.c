// Cloud Cuckooland Trash Can minigame (single and multiplayer): hit the garbage creatures that
// pop up within 60 s; the trash-can host, garbage actor, lid deflector and door live here.
#include "common.h"

#define TRASH_IMPACT(volume)                                                                       \
    func_800C4140((((u32) (func_800DC178(1.05f, 1.15f) * 1023.0f) & 0x7FF) << 21) +                \
                      ((((volume) >> 5) & 0x3FF) << 11) + 0x4C1,                                   \
                  (f32 *) (param_0 + 4), 0x04B000FA)
#define TRASH_RATTLE()                                                                             \
    func_800C4140((((u32) (func_800DC178(0.95f, 1.05f) * 1023.0f) & 0x7FF) << 21) + 0x157C04,      \
                  (f32 *) (param_0 + 4), 0x04B000FA)
extern s32 func_80101E14(void *, f32);
extern s32 func_80101E4C(void *, void *);
extern int func_800C954C(void);
extern int func_800DA298(int);
extern int func_800CC63C(int, int);
extern void _subaddiemulti_entrypoint_6(int, int);
extern int _gcstatusDll_entrypoint_11(void);
extern void func_800D2498(int, int, int);
extern int func_800D90A4(float *);
extern void func_80108B04(void *, int);
extern void func_800D28A0(int);
extern void func_800BA22C(s32, s32);
extern f32 func_800EFC7C(f32 *, f32 *);
extern int _subaddiefind_entrypoint_5(s32, Actor **, s32, f32 *, f32, f32 (*)(f32 *, f32 *));
typedef struct {
    s32 local_0[4];
} TrashParticleColours27;
extern TrashParticleColours27 D_80803164_chtrashcangame;
extern u8 D_80803174_chtrashcangame[];
extern f32 func_800C6920(f32 *, f32, f32, s32);
extern s32 func_800BABB8(s32, f32 *, f32 *, f32, u8 *);
extern f32 func_800DC178(f32, f32);
extern int D_808031B4_chtrashcangame[];
typedef union {
    s32 local_0;
    s16 local_1[2];
} TrashCanEventValue;
extern int D_808031FC_chtrashcangame[];
extern f32 func_800F1DF4(f32 *, f32 *);
extern int D_808033A0_chtrashcangame[];
extern void func_800EFA4C(f32 *, f32, f32, f32);
extern s32 _sudeflect_entrypoint_0(f32 *, f32, f32, s32);
extern int D_808033E8_chtrashcangame[];
extern f32 func_80103EF4(Actor *);
extern void _chdoormake_entrypoint_3(Actor *, f32, f32, f32, s32, s32);
extern void _chdoormake_entrypoint_5(Actor *, f32);
extern int D_80803430_chtrashcangame[];
extern u8 D_80803090_chtrashcangame[];
extern s16 D_80803096_chtrashcangame;
extern f32 func_80103EAC(Actor *);
extern void _sudeflect_entrypoint_1(f32 *, f32, f32, f32, s32);
extern void func_800CE8D8(s32, f32, s32);
extern u8 D_808030AC_chtrashcangame[];
extern s32 _gcdialogcamera_entrypoint_0(s32, s32);
extern void _gcdialogcamera_entrypoint_3(void *, f32);
typedef struct {
    s32 local_0[7];
} TrashTimes7;
typedef struct {
    u16 local_0, local_1;
    f32 local_2;
} TrashAnimation;
extern TrashAnimation D_80802FF4_chtrashcangame[];
extern TrashParticleColours27 D_808030BC_chtrashcangame;
extern TrashParticleColours27 D_808030CC_chtrashcangame;
extern TrashParticleColours27 D_808030DC_chtrashcangame;
extern TrashParticleColours27 D_808030EC_chtrashcangame;
extern TrashParticleColours27 D_808030FC_chtrashcangame;
extern TrashParticleColours27 D_8080310C_chtrashcangame;
extern TrashParticleColours27 D_8080311C_chtrashcangame;
extern TrashTimes7 D_8080312C_chtrashcangame;
extern TrashTimes7 D_80803148_chtrashcangame;
extern void func_800C4140(s32, f32 *, s32);
extern f32 func_800DC0C0(void);
extern Actor *func_80108528(s32, f32 *, s32, Actor **);
extern f32 func_80013970(f32);
extern f32 func_80101F24(Actor *);
extern s32 func_800BBCB8(f32 *, f32 *, f32, s32, u8 *);
extern void func_800BA994(s32, s16, s16, s16, s16, s16, s16);
extern void func_800F4F34(s32, f32 *, f32, f32);
extern Actor *func_80106790(Unk80132ED0 *);
extern u8 D_80803398_chtrashcangame[];
extern u8 D_80803394_chtrashcangame[];
extern u8 D_80803364_chtrashcangame[];
extern u8 D_80803324_chtrashcangame[];
extern u8 D_8080339C_chtrashcangame[];
extern s32 func_800B53A4(s32);
extern void _chscorepoints_entrypoint_2(s32, s32, f32 *, s32);
void func_808017F0_chtrashcangame();
void func_808003D0_chtrashcangame();
void func_80800BA8_chtrashcangame();
void func_8080134C_chtrashcangame();
s32 func_80801558_chtrashcangame();
void func_808019EC_chtrashcangame();
void func_80801EE8_chtrashcangame();

// Clear all player scores.
void func_80800000_chtrashcangame(Actor *actor)
{
    *(s32 *) ((u8 *) actor + 0x18) = 0;
    *(s32 *) ((u8 *) actor + 0x30) = 0;
    *(s32 *) ((u8 *) actor + 0x2C) = 0;
    *(s32 *) ((u8 *) actor + 0x28) = 0;
}

// Score of a player (single-player: slot 0).
s32 func_80800014_chtrashcangame(Actor *actor, s32 player)
{
    if (func_800D3948()) {
        switch (player) {
            case 0:
                return ((s32 *) actor)[10];

            case 1:
                return ((s32 *) actor)[11];

            case 2:
                return ((s32 *) actor)[12];

            case 3:
                return ((s32 *) actor)[6];

            default:
                return 0;
        }
    }
    {
        return ((s32 *) actor)[10];
    }
}

// Set the score of a player.
void func_80800098_chtrashcangame(Actor *actor, s32 player, s32 score)
{
    if (func_800D3948()) {
        if ((s32) actor->unk70_10 == 3) {
            switch (player) {
                case 0:
                    actor->actorData[4] = score;
                    break;
                case 1:
                    actor->actorData[5] = score;
                    break;
                case 2:
                    actor->actorData[6] = score;
                    break;
                case 3:
                    actor->actorData[0] = score;
                    break;
            }
        }
    } else if (actor->unk70_10 == 8) {
        actor->actorData[4] = score;
    }
}

// Add points to a player's score.
void func_80800144_chtrashcangame(Actor *actor, s32 player, s32 points)
{
    s32 score;
    score = func_80800014_chtrashcangame(actor, player);
    func_80800098_chtrashcangame(actor, player, score + points);
}

void func_808018E4_chtrashcangame();

void func_80801740_chtrashcangame();

void func_80800180_chtrashcangame(Actor *actor)
{
    _sudeflect_entrypoint_1(actor->position, func_80103EF4(actor), 0.0f, func_80103EAC(actor),
                            30);
    switch (actor->unk70_10) {
        case 1:
            if (func_800D90A4(&actor->unk58))
                func_808003D0_chtrashcangame(actor, 2);
            break;
        case 3:
            if (func_800D0A9C(0x4E, 1))
                D_80803096_chtrashcangame = 0x13F0;
            if (_subaddiedialog_entrypoint_7(actor, actor->position, D_80803090_chtrashcangame))
                func_80801740_chtrashcangame(actor, 2, 0);
            break;
        case 8:
            if (func_800D90A4(&actor->unk58)) {
                actor->unk58 = 0.299987793f;
                func_80108B04(actor, 0);
            }
            if (_subaddiedialog_entrypoint_4(actor->position, 400, 0)) {
                if (func_800D0A9C(0x4E, 1))
                    _subaddiedialog_entrypoint_11(actor->unk0, func_800DC128(0x1403, 0x1405), 7,
                                                  actor->position, 0x6A);
                else
                    _subaddiedialog_entrypoint_11(actor->unk0, func_800DC128(0x1401, 0x1405), 7,
                                                  actor->position, 0x6A);
            }
            if (func_800CEAD0(0))
                func_80800728_chtrashcangame(actor);
            func_800D2498(0xF8, func_80800014_chtrashcangame(actor, 0), 0);
            break;
        case 9:
        case 11:
            func_8010CEAC(actor);
            func_800D2498(0xF8, func_80800014_chtrashcangame(actor, 0), 0);
            break;
        case 13:
            if (!_subaddiefind_entrypoint_2(0x21F, 0))
                func_808003D0_chtrashcangame(actor, 14);
            break;
        case 14:
            if (func_800D90A4(&actor->unk58))
                func_808003D0_chtrashcangame(actor, 15);
            break;
        case 15:
            func_8010CEAC(actor);
    }
    func_80800BA8_chtrashcangame(actor);
    func_808018E4_chtrashcangame(actor);
}

void func_8080189C_chtrashcangame();

void func_808016B4_chtrashcangame();

void func_808003D0_chtrashcangame(Actor *actor, s32 state)
{
    s32 end_dialog;
    s32 intro_dialog;
    s32 result_dialog;

    switch (state) {
        case 1:
            actor->unk58 = func_800DC178(15.0f, 25.0f);
            break;
        case 2:
            _subaddiedialog_entrypoint_11(actor->unk0, func_800DC128(0x13FE, 0x1401), 4,
                                          actor->position, 0x6A);
            break;
        case 3:
            *(s32 *) &actor->unk50 = 0;
            actor->actorData[7] = 10;
            func_8080189C_chtrashcangame(actor);
            break;
        case 4:
            actor->unk79_4 = func_800DC128(1, 4);
            func_808017F0_chtrashcangame((u8 *) actor, 0x13F1, 0x4E);
            break;
        case 5:
            func_808017F0_chtrashcangame((u8 *) actor, 0x13F2, 0x4E);
            break;
        case 6:
            intro_dialog = func_800D0A9C(0x4E, 1) ? 0x13FD : 0x13F3;
            func_808017F0_chtrashcangame((u8 *) actor, intro_dialog, 0xF);
            break;
        case 7:
            *(s32 *) &actor->unk50 = 0;
            if (func_800D395C()) {
                end_dialog = 0x1444;
                func_800946C4(func_800F53D0(func_800F54E4()), 1);
            } else if (func_800D0A9C(0x4E, 1)) {
                end_dialog = 0x13F5;
            } else {
                end_dialog = 0x13F4;
            }
            func_808017F0_chtrashcangame((u8 *) actor, end_dialog, 0xF);
            func_80800000_chtrashcangame(actor);
            _gcfrontend_entrypoint_9(0x72);
            func_80101180(0x533, 8, 0);
            break;
        case 8:
            func_8080189C_chtrashcangame(actor);
            func_800CE8D8(0, 60.0f, 60);
            func_800CE88C(0, 1);
            actor->unk58 = 0.29998779296875f;
            func_80800098_chtrashcangame(actor, 0, 0);
            *(s32 *) &actor->unk50 = 0;
            func_800FDC28(12);
            break;
        case 9:
            func_800FC6B0(0x17);
            break;
        case 10:
            result_dialog = func_800D0A9C(0x4E, 1) ? 0x13FC : 0x13FB;
            func_808017F0_chtrashcangame((u8 *) actor, result_dialog, 0x4E);
            func_800D2054(0, 0x86, func_80800014_chtrashcangame(actor, 0));
            break;
        case 11:
            func_800FC6B0(0x16);
            break;
        case 12:
            func_800D1000(0x4E, 1, actor->position, 6, 0);
            func_808016B4_chtrashcangame(actor, (s32) actor->unk0, 6, 0x10);
            break;
        case 13:
            func_8080189C_chtrashcangame(actor);
            break;
        case 14:
            actor->unk58 = 0.5f;
            break;
        case 15:
            func_808017F0_chtrashcangame((u8 *) actor, 0x13FC, 0x4E);
            func_800D2054(0, 0x86, func_80800014_chtrashcangame(actor, 0));
            break;
        case 16:
            *(s32 *) &actor->unk50 = 0;
            actor->actorData[7] = 10;
            func_8080189C_chtrashcangame(actor);
            func_808017F0_chtrashcangame((u8 *) actor, 0x1443, 0x4E);
            break;
        case 17:
            func_808017F0_chtrashcangame((u8 *) actor, 0x1451, 0xF);
    }
    func_80102424(actor, state);
}

// Evaluate the final score and pick the end dialog.
int func_80800728_chtrashcangame(s32 actor)
{
    s32 score;
    func_800FDC28(0);
    func_80101180(0x533, 7, 0);
    if (func_800D395C() != 0) {
        score = func_80800014_chtrashcangame(actor, 0);
        if (score == func_800D211C(0x86)) {
            func_800FC660(0x17);
            func_808017F0_chtrashcangame(actor, 0x1446, 0xF);
        } else {
            score = func_80800014_chtrashcangame(actor, 0);
            if (score < func_800D211C(0x86)) {
                func_800FC660(0x17);
                func_808017F0_chtrashcangame(actor, 0x1445, 0xF);
            } else {
                func_800FC660(0x16);
                func_808017F0_chtrashcangame(actor, 0x1447, 0xF);
            }
        }
        func_808003D0_chtrashcangame(actor, 0x12);
        return;
    }
    if (func_800D0A9C(0x4E, 1) != 0) {
        score = func_80800014_chtrashcangame(actor, 0);
        if (score == func_800D211C(0x86)) {
            func_808017F0_chtrashcangame(actor, 0x13F9, 0xF);
            func_808003D0_chtrashcangame(actor, 9);
            return;
        }
        score = func_80800014_chtrashcangame(actor, 0);
        if (score < func_800D211C(0x86)) {
            func_808017F0_chtrashcangame(actor, 0x13F8, 0xF);
            func_808003D0_chtrashcangame(actor, 9);
            return;
        }
        func_808017F0_chtrashcangame(actor, 0x13FA, 0xF);
        func_808003D0_chtrashcangame(actor, 0xB);
        return;
    }
    if (func_80800014_chtrashcangame(actor, 0) < 0x32) {
        func_808017F0_chtrashcangame(actor, 0x13F6, 0xF);
        func_808003D0_chtrashcangame(actor, 9);
        return;
    }
    func_808017F0_chtrashcangame(actor, 0x13F7, 0xF);
    func_808003D0_chtrashcangame(actor, 0xB);
}

s32 func_8080093C_chtrashcangame(Actor *actor, s32 event, s32 value)
{
    s32 lo;
    u32 hi;

    switch (event) {
        case 0x2E:
            func_8080134C_chtrashcangame(actor, ((s16 *) &value)[0], ((s16 *) &value)[1]);
            return 1;
        case 0x2F:
            func_80108B04(actor, ((s16 *) &value)[1]);
            return 1;
        case 0x30:
            return func_80801558_chtrashcangame(actor, ((s16 *) &value)[0],
                                                ((s16 *) &value)[1]);
        case 0x3D:
            func_808019EC_chtrashcangame(actor, value);
            return 1;
        case 0xB:
            if (value == 6) {
                func_808003D0_chtrashcangame(actor, 13);
            }
            return 4;
        case 0x52:
            _gcdialogcamera_entrypoint_4(actor->position);
            _gcdialogcamera_entrypoint_3(D_808030AC_chtrashcangame, actor->scale);
            return 3;
        case 0x57:
            lo = value & 0xFFFF;
            hi = (u32) (value & 0xFFFF0000) >> 16;
            if (_gcdialogcamera_entrypoint_0(lo, hi)) {
                func_80801740_chtrashcangame(actor, lo, hi);
                return 2;
            }
            return 1;
        case 0x95:
            actor->unk74_7 = 0;
            *(f32 *) &actor->actorData[3] = 0.0f;
            if (_glcutDll_entrypoint_20()) {
                func_808003D0_chtrashcangame(actor, 19);
            } else if (func_800D395C()) {
                func_808003D0_chtrashcangame(actor, 16);
            } else if (!func_800F64A4(func_800F54E4(), 0x400)) {
                func_808003D0_chtrashcangame(actor, 1);
            } else {
                func_808003D0_chtrashcangame(actor, 3);
            }
            func_800BF744(1, 1);
            return 1;
        default:
            return 0;
    }
}

// Count garbage creatures near pos.
s32 func_80800B64_chtrashcangame(f32 *pos)
{
    Actor *found[50];
    f32 radius;
    s32 count;

    radius = 300.0f;
    count = _subaddiefind_entrypoint_5(0x476, found, 50, pos, radius, func_800EFC7C);
}

void func_80800BA8_chtrashcangame(param_0) u8 *param_0;
{
    // Pick impact and rattle sounds from the animation frame.
    switch (D_80802FF4_chtrashcangame[(u32) *(u16 *) (param_0 + 0x72) >> 10].local_0) {
        // One explicit strong impact, then table-driven softer hits.
        case 0x369: {
            TrashParticleColours27 unk_0 = D_808030BC_chtrashcangame;
            TrashParticleColours27 unk_1 = D_808030CC_chtrashcangame;
            TrashParticleColours27 unk_2 = D_808030DC_chtrashcangame;
            s32 impact = 0;
            if (func_80101E14(param_0, 0.157f))
                impact = 22000;
            else if (func_80101E4C(param_0, &unk_0))
                impact = 10000;
            else if (func_80101E4C(param_0, &unk_1))
                impact = 5000;
            if (func_80101E4C(param_0, &unk_2))
                TRASH_RATTLE();
            if (impact)
                TRASH_IMPACT(impact);
            break;
        }
        // Explicit normalized animation times; no rattle branch.
        case 0x36A: {
            TrashParticleColours27 unk_3 = D_808030EC_chtrashcangame;
            TrashParticleColours27 unk_4 = D_808030FC_chtrashcangame;
            TrashParticleColours27 unk_5 = D_8080310C_chtrashcangame;
            s32 impact = 0;
            if (func_80101E14(param_0, 0.126f))
                impact = 22000;
            else if (func_80101E14(param_0, 0.156f) || func_80101E14(param_0, 0.888f))
                impact = 10000;
            else if (func_80101E14(param_0, 0.918f))
                impact = 5000;
            if (impact)
                TRASH_IMPACT(impact);
            break;
        }
        // Table-driven strong/medium hits and independent rattles.
        case 0x36B: {
            TrashParticleColours27 unk_6 = D_8080311C_chtrashcangame;
            TrashTimes7 unk_7 = D_8080312C_chtrashcangame;
            TrashTimes7 unk_8 = D_80803148_chtrashcangame;
            s32 impact = 0;
            if (func_80101E4C(param_0, &unk_6))
                impact = 22000;
            else if (func_80101E4C(param_0, &unk_7))
                impact = 10000;
            else if (func_80101E14(param_0, 0.44f) || func_80101E14(param_0, 0.994f))
                impact = 5000;
            if (func_80101E4C(param_0, &unk_8))
                TRASH_RATTLE();
            if (impact)
                TRASH_IMPACT(impact);
        }
    }
}

void func_8080134C_chtrashcangame(actor, dialog_id, answer) Actor *actor;
s32 dialog_id;
s32 answer;
{
    switch (dialog_id) {
        case 0x13EE:
            if (answer) {
                func_808003D0_chtrashcangame(actor, 4);
                return;
            }
            func_808003D0_chtrashcangame(actor, 5);
            return;
        case 0x13EF:
        case 0x13F0:
        case 0x13F1:
        case 0x13F2:
            if (answer) {
                func_808003D0_chtrashcangame(actor, 7);
                return;
            }
            func_808003D0_chtrashcangame(actor, 6);
            return;
        case 0x13F3:
            func_808003D0_chtrashcangame(actor, 3);
            return;
        case 0x13F4:
        case 0x13F5:
        case 0x1444:
            func_808003D0_chtrashcangame(actor, 8);
            return;
        case 0x13F6:
        case 0x13F8:
        case 0x13F9:
            func_808003D0_chtrashcangame(actor, 10);
            return;
        case 0x13FA:
            func_808003D0_chtrashcangame(actor, 15);
            return;
        case 0x13F7:
            func_808003D0_chtrashcangame(actor, 12);
            return;
        case 0x13FD:
            func_808003D0_chtrashcangame(actor, 3);
            return;
        case 0x13FC:
            if (answer) {
                func_808003D0_chtrashcangame(actor, 7);
                return;
            }
            func_808003D0_chtrashcangame(actor, 6);
            return;
        case 0x13FB:
            if (answer) {
                func_808003D0_chtrashcangame(actor, 7);
                return;
            }
            func_808003D0_chtrashcangame(actor, 6);
            return;
        case 0x13FE:
        case 0x13FF:
        case 0x1400:
            func_808003D0_chtrashcangame(actor, 1);
            return;
        case 0x1443:
            if (answer) {
                func_808003D0_chtrashcangame(actor, 17);
                return;
            }
            func_808003D0_chtrashcangame(actor, 7);
            return;
        case 0x1451:
            func_808003D0_chtrashcangame(actor, 7);
            return;
        case 0x1445:
        case 0x1446:
        case 0x1447:
            func_808017F0_chtrashcangame(actor, 0x1448, 0x4E);
            func_800D2054(0, 0x86, func_80800014_chtrashcangame(actor, 0));
            return;
        case 0x1448:
            if (answer) {
                func_808003D0_chtrashcangame(actor, 7);
                return;
            }
            func_800C0850();
            _gcfrontend_entrypoint_10();
    }
}

s32 func_80801558_chtrashcangame(actor, dialog_id, answer)
s32 actor;
s32 dialog_id;
s32 answer;
{

switch (dialog_id) {
    case 0x13EF:;
    case 0x13F1:
    case 0x13F2:
        return 0x32;
    case 0x13F0:
        return func_800D211C(0x86);
    case 0x13F4:
        if (answer != 0) {
            return 0x32;
        }
        return 0x3C;
    case 0x13F5:
        if (answer != 0) {
            return func_800D211C(0x86);
        }
        return 0x3C;
    case 0x13F8:
        if (answer != 0) {
            return func_800D211C(0x86);
        }
        return func_80800014_chtrashcangame(actor, 0);
    case 0x13FA:
        return func_80800014_chtrashcangame(actor, 0);
    case 0x13F6:;
    case 0x13F7:
    case 0x13F9:
        return func_80800014_chtrashcangame(actor, 0);
    case 0x1443:
        return 0x3C;
    case 0x1444:
        if (answer != 0) {
            return func_800D211C(0x86);
        }
        return 0x3C;
    case 0x1445:;
    case 0x1446:
    case 0x1447:
        if (answer != 0) {
            return func_800D211C(0x86);
        }
        return func_80800014_chtrashcangame(actor, 0);
    case 0x1451:
        return 0x3C;
    default:
        return 0;
}

}

void func_808016B4_chtrashcangame(Actor *actor, s32 param_1, s32 param_2, s32 param_3)
{
    switch (actor->unk74_7) {
        case 0:
            _capod_entrypoint_2(actor->unk0, 0x2A, 0x10);
        case 1:
            actor->unk74_7 = 2;
        case 2:
            _capod_entrypoint_6(param_1, param_2, param_3);
    }

}

void func_80801740_chtrashcangame(u8 *actor, s32 param_1, s32 param_2)
{
    u32 state;
    state = (u16) (*((u16 *) (((char *) actor) + 0x76)));
    state = state >> 7;

switch (state) {
    case 0:
        _capod_entrypoint_2(*(s32 *) ((char *) actor + 0x0), 0x2A, 0x10, actor);

    case 2:
        _capod_entrypoint_8(1);
        *(u16 *) ((char *) actor + 0x76) =
            (u16) ((*(u16 *) ((char *) actor + 0x76) & 0x7F) | 0x80);
        param_1 = 2;
        param_2 = 1;
        _gcdialogcamera_entrypoint_6(*(s32 *) ((char *) actor + 0x0));
        _gcdialogcamera_entrypoint_8();

    case 1:
        _capod_entrypoint_7(param_1, param_2);
}

}

void func_808017F0_chtrashcangame(actor, dialog_id, param_2) u8 *actor;
s32 dialog_id;
s32 param_2;
{
    u32 state;

    state = (u32) ((u16) (*(u16 *) ((s8 *) (actor) + (0x76)))) >> 7;

switch (state) {
    case 0:
        _capod_entrypoint_2(*(s32 *) ((s8 *) actor + 0), 0x2A, 0x10);

    case 2:
        _capod_entrypoint_8(1);
        *(u16 *) ((s8 *) actor + 0x76) = (u16) ((*(u16 *) ((s8 *) actor + 0x76) & 0x7F) | 0x80);
        _gcdialogcamera_entrypoint_6(*(s32 *) ((s8 *) actor + 0));
        _gcdialogcamera_entrypoint_8();
        _capod_entrypoint_7(2, 1);
}

_subaddiedialog_entrypoint_11((*(s32 *) ((s8 *) (actor) + (0))), dialog_id, param_2, actor + 4,
                              0x6A);
}

void func_8080189C_chtrashcangame(Actor *actor)
{
    u16 state_bits;
    unsigned int offset;
    // Matching: "^ 0" and the offset variable are needed for the match.
    state_bits = (*((u16 *) (((char *) actor) + 0x76))) ^ 0;
    offset = 0x76;
    {
        if ((((u32) state_bits) >> 7) != 0) {
            _capod_entrypoint_3(0, actor);
            *((u16 *) (((char *) actor) + offset)) =
                (*((u16 *) (((char *) actor) + 0x76))) & 0x7F;
        }
    }
}

void func_808018E4_chtrashcangame(Actor *actor)
{
    f32 pos[3];
    s32 particle;
    TrashParticleColours27 colours;

if (actor->unk70_10 != 8 && func_800D90A4(&actor->actorData[3])) {
    colours = D_80803164_chtrashcangame;
    func_800CD08C((*(u32 *) ((u8 *) actor + 0x70) >> 25) - 1, pos);
    pos[1] = func_800C6920(pos, 1000.0f, -1000.0f, 0);
    particle = func_800BABB8(0, pos, pos, 1.0f, D_80803174_chtrashcangame);
    func_800BAB80(particle, &colours.local_0[func_800DC128(0, 4)]);
    func_800BA22C(particle, 1);
    ((f32 *) actor->actorData)[3] = func_800DC178(1.0f, 2.0f);
}

}

// Spawn a garbage creature (mode 0 = random spot, 1-3 = fixed spots).
void func_808019EC_chtrashcangame(actor, mode) Actor *actor;
s32 mode;
{
    Vec3f pos;
    Actor *garbage;
    s32 model_id;
    s32 spawn_slot = -1;
    f32 roll;

if (*(s32 *) &actor->unk50 < (s32) actor->actorData[7]) {
    (*(s32 *) &actor->unk50)++;
    switch (mode) {
        case 0:
            roll = func_800DC0C0();
            func_800CD08C((*(u32 *) ((u8 *) actor + 0x70) >> 25) - 1, pos.f);
            while (func_80800B64_chtrashcangame(pos.f)) {
                func_800CD08C((*(u32 *) ((u8 *) actor + 0x70) >> 25) - 1, pos.f);
            }
            if (roll < 0.5f) {
                model_id = func_800D3948() ? 0x99D : 0x805;
            } else if (roll < 0.799987793f) {
                model_id = func_800D3948() ? 0x99E : 0x804;
            } else {
                model_id = func_800D3948() ? 0x99F : 0x806;
            }
            break;
        case 1:
            model_id = 0x805;
            func_800EFA4C(pos.f, -716.0f, 0.0f, -1173.0f);
            spawn_slot = 0;
            break;
        case 2:
            model_id = 0x804;
            func_800EFA4C(pos.f, 1203.0f, 0.0f, -810.0f);
            spawn_slot = 2;
            break;
        case 3:
            model_id = 0x806;
            func_800EFA4C(pos.f, 1050.0f, 0.0f, 500.0f);
            spawn_slot = 4;
    }
    garbage = func_80108528(0x476, pos.f, 0, &actor);
    garbage->scale = 0.5f;
    func_80103140(garbage, (u16) model_id, garbage->unk0->unk16);
    func_80102424(garbage, garbage->unk70_10);
    garbage->unk3C = actor->unk0;
    if (spawn_slot != -1) {
        func_808016B4_chtrashcangame(actor, actor->unk0, spawn_slot, 0x10);
    }
    if (mode != 0) {
        garbage->unk64_20 = mode == actor->unk79_4;
    } else {
        garbage->unk64_20 = func_800DC0C0() < 0.3f;
    }
}

}

int chtrashcangame_entrypoint_0()
{
    return (int) &D_808031B4_chtrashcangame;
}

void func_80801CF0_chtrashcangame(s32 param_0)
{
    s32 i;

_subaddiemulti_entrypoint_3(1);
{
    for (i = 0; i < _gcstatusDll_entrypoint_11(); i++) {
        // Matching: "| 0" is needed for the match.
        func_800946C4(func_800F53D0(i | 0), 1);
    }
}

}

void func_80801D54_chtrashcangame(u8 *actor)
{
    s32 i;
    s32 j;
    u32 state;
    u32 flags;
    u8 *unk_0;
    state = (u16) (*((u16 *) (((char *) actor) + 0x72)));
    state = state >> 0xA;

switch (state) {
    case 1:
        if ((func_800C954C() == 0) && (func_800DA298(0x6AD) == 0)) {
            func_80801EE8_chtrashcangame(actor, 2);
        }

    case 2:
        return;

    case 3:
        flags = *(u32 *) ((char *) actor + 0x70);
        unk_0 = func_800CC63C((flags >> 0x19) - 1, ((u32) (flags << 0x16) >> 0x1A) - 1);
        _subaddiemulti_entrypoint_6(unk_0, *(s32 *) ((char *) unk_0 + 0x10));
        i = 0;
        if (_gcstatusDll_entrypoint_11() > 0) {
            do {
                func_800D2498(i + 0xC3, func_80800014_chtrashcangame(actor, i), 0);
                i++;
            } while (i < _gcstatusDll_entrypoint_11());
        }
        if (func_800D90A4(actor + 0x58) != 0) {
            *(float *) ((char *) actor + 0x58) = 0.2999878f;
            func_80108B04(actor, 0);
        }
        if (func_800CEAD0(0) != 0) {
            func_80801EE8_chtrashcangame(actor, 4);
        }
        break;

    case 4:
        j = 0;
        if (_gcstatusDll_entrypoint_11() > 0) {
            do {
                if (j == *(s32 *) ((char *) actor + 0x20)) {
                    func_800D28A0(j + 0xC3);
                }
                func_800D2498(j + 0xC3, func_80800014_chtrashcangame(actor, j), 0);
                j++;
            } while (j < _gcstatusDll_entrypoint_11());
        }
}

}

// State changes of the multiplayer host.
void func_80801EE8_chtrashcangame(actor, state) Actor *actor;
s32 state;
{
    s32 i;
    s32 score;
    s32 is_tie;

switch (state) {
    case 2:
        _subaddiedialog_entrypoint_11(actor->unk0, 0x13ED, 0xF, 0, 0x6A);
        func_80800000_chtrashcangame(actor);
        break;
    case 3:
        actor->unk58 = 0.299987793f;
        *(s32 *) &actor->unk50 = 0;
        actor->actorData[7] = 10;
        for (i = 0; i < _gcstatusDll_entrypoint_11(); i++) {
            func_80800098_chtrashcangame(actor, i, 0);
            func_800D2748(i + 0xC3, i + 0x5F);
        }
        func_800CE8D8(0, 60.0f, 60);
        func_800CE88C(0, 1);
        _subaddiemulti_entrypoint_2();
        func_800FDC28(12);
        break;
    case 4:
        is_tie = 0;
        actor->actorData[1] = func_80800014_chtrashcangame(actor, 0);
        actor->actorData[2] = 0;
        func_800AA20C(0, actor->actorData[1]);
        func_800FC660(0x10);
        for (i = 1; i < _gcstatusDll_entrypoint_11(); i++) {
            score = func_80800014_chtrashcangame(actor, i);
            if ((s32) actor->actorData[1] < score) {
                actor->actorData[1] = score;
                actor->actorData[2] = i;
            } else if (score == actor->actorData[1]) {
                is_tie = 1;
            }
            func_800AA20C(i, score);
        }
        if (is_tie) {
            _subaddiedialog_entrypoint_11(actor->unk0, 0x13DF, 7, 0, 0x6A);
        } else {
            _subaddiedialog_entrypoint_11(actor->unk0, 0x13DE, 7, 0, 0x6A);
        }
        _subaddiemulti_entrypoint_0(1);
}

func_80101FDC(actor, state);

}

s32 func_808020D8_chtrashcangame(Actor *actor, s32 event, TrashCanEventValue value)
{
    switch (event) {
        case 0x2E:
            switch (value.local_1[0]) {
                case 0x13ED:
                    func_80801EE8_chtrashcangame(actor, 3);
                    return 1;
                case 0x13DE:
                case 0x13DF:
                    _gcfrontend_entrypoint_10(actor);
                    return 1;
                default:
                    return 1;
            }
        case 0x30:
            if (value.local_1[1])
                return actor->actorData[1];
            return actor->actorData[2] + 1;
        case 0x95:
            _subaddiemulti_entrypoint_0(0);
            _subaddiemulti_entrypoint_4(0);
            return 1;
        case 0x3D:
            func_808019EC_chtrashcangame(actor, value.local_0);
            return 1;
        default:
            return 0;
    }

}

int chtrashcangame_entrypoint_1()
{
    return (int) &D_808031FC_chtrashcangame;
}

void func_808021BC_chtrashcangame(Actor *actor)
{
    f32 player_pos[3];

    actor->position[1] = func_800C6920(actor->position, 1000.0f, -1000.0f, 0);
    func_800EE7F8((f32 *) actor->actorData, actor->position);
    func_80102424(actor, 1);
    actor->unk58 = 0.0f;
    func_800F5A00(func_800F54E4(), player_pos);
    actor->rotation[1] = func_800F1DF4(actor->position, player_pos);
}

void func_8080223C_chtrashcangame(Actor *actor)
{
    extern u8 D_8080326C_chtrashcangame[];
    extern u8 D_808032C0_chtrashcangame[];
    extern u8 D_80803300_chtrashcangame[];
    s32 effect;

switch (actor->unk70_10) {
    case 1:
        if (func_80101E14(actor, 0.01f)) {
            if (func_8010C754(actor) < 1500 || func_800DB9B0()) {
                if (!func_800D3948()) {
                    func_800BBCB8(actor->position, actor->position, 1.0f, 5,
                                  D_8080326C_chtrashcangame);
                }
                func_800C4140((((u32) (func_800DC178(0.45f, 0.65f) * 1023.0f) & 0x7FF) << 21) +
                                  0x1FFCB7,
                              actor->position, 0x05DC0190);
            }
        }
        actor->position[1] = *(f32 *) &actor->actorData[1] +
                               (func_80013970(func_80101F24(actor) * 135.0f) - 0.707f) *
                                   (func_80103EF4(actor) * 1.25f);
        actor->scale = func_80101F24(actor) * 0.8f + 0.2f;
        if (func_80101DDC(actor)) {
            if (actor->unk64_20) {
                func_80102424(actor, 3);
            } else {
                actor->unk58 = func_800DC178(2.0f, 3.0f);
                func_80102424(actor, 2);
            }
        }
        break;
    case 3:
        if (func_80101E14(actor, 0.1f)) {
            if (func_8010C754(actor) < 1500) {
                func_800C4140((((u32) (func_800DC178(0.75f, 0.85f) * 1023.0f) & 0x7FF) << 21) +
                                  0x157C9D,
                              actor->position, 0x05DC0190);
            }
        }
        if (!func_800D3948() && func_80101E4C(actor, D_80803300_chtrashcangame)) {
            effect = func_800BABB8(0, actor->position, actor->position, 1.0f,
                                    D_808032C0_chtrashcangame);
            if (func_800DC0C0() < 0.5f) {
                func_800BA994(effect, -20, (s16) actor->rotation[1] - 75, 300, -45,
                              (s16) actor->rotation[1] - 75, 500);
            } else {
                func_800BA994(effect, -20, (s16) actor->rotation[1] + 75, 300, -45,
                              (s16) actor->rotation[1] + 75, 500);
            }
            func_800BA22C(effect, 1);
        }
        if (func_80101DDC(actor)) {
            func_80102424(actor, 4);
        }
        break;
    case 2:
        if (func_800D90A4(&actor->unk58)) {
            func_80102424(actor, 4);
        }
        break;
    case 4:
        if (func_80101E14(actor, 0.05f)) {
            if (func_8010C754(actor) < 1500) {
                if (!func_800D3948()) {
                    func_800BBCB8(actor->position, actor->position, 1.0f, 5,
                                  D_8080326C_chtrashcangame);
                }
                func_800C4140((((u32) (func_800DC178(0.45f, 0.65f) * 1023.0f) & 0x7FF) << 21) +
                                  0x1FFC01,
                              actor->position, 0x05DC0190);
            }
        }
        if (func_80101DDC(actor)) {
            (*(s32 *) &func_80106790(actor->unk3C)->unk50)--;
            func_800FFA88(actor->unk0);
        }
        actor->position[1] = *(f32 *) &actor->actorData[1] +
                               (func_80013970(func_80101F24(actor) * 135.0f) - 0.707f) *
                                   (func_80103EF4(actor) * 1.25f);
        actor->scale = func_80101F24(actor) * 0.8f + 0.2f;
}

if (actor->scale > 0.5f) {
    actor->scale = 0.5f;
}

func_800F4F34(func_800F54E4(), actor->position, func_80103EAC(actor) * 2.0f,
              func_80103EAC(actor) * 0.4f);
}

// Hit by the player: award points, spawn effects, free the slot.
s32 func_8080292C_chtrashcangame(Actor *actor, s32 event, s32 param_2)
{
    s32 unk_0;
    s32 unk_1;
    Actor *host;
    s32 points;
    s32 player;

if (event == 0x40) {
    unk_0 = func_800B53A4(func_800D3948() ? 2 : 6);
    host = func_80106790(actor->unk3C);
    player = 0;
    func_800BABB8(unk_0, actor->position, actor->position, 1.0f, D_80803324_chtrashcangame);
    if (!func_800D3948()) {
        unk_1 =
            func_800BABB8(0, actor->position, actor->position, 1.0f, D_80803364_chtrashcangame);
    } else {
        player = _subaddiemulti_entrypoint_5(param_2);
    }
    switch (actor->unk0->unk14) {
        case 0x805:
        case 0x99D:
            if (!func_800D3948()) {
                func_800BAB80(unk_1, D_80803394_chtrashcangame);
            }
            func_800BA670(unk_0, 0x920);
            points = 1;
            break;
        case 0x804:
        case 0x99E:
            if (!func_800D3948()) {
                func_800BAB80(unk_1, D_80803398_chtrashcangame);
            }
            func_800BA670(unk_0, 0x921);
            points = 2;
            break;
        case 0x806:
        case 0x99F:
            if (!func_800D3948()) {
                func_800BAB80(unk_1, D_8080339C_chtrashcangame);
            }
            func_800BA670(unk_0, 0x922);
            points = 3;
    }
    func_80800144_chtrashcangame(func_80106790(actor->unk3C), player, points);
    func_800BA22C(unk_0, func_800D3948() ? 2 : 6);
    if (!func_800D3948()) {
        func_800BA22C(unk_1, 6);
    }
    *(s32 *) &host->unk50 -= 1;
    _chscorepoints_entrypoint_2(points, player, actor->position, 1);
    func_800FFA88(actor->unk0);
    func_800C4140((((u32) (func_800DC178(0.45f, 0.65f) * 1023.0f) & 0x7FF) << 21) + 0x1FFC1F,
                  actor->position, 0x05DC0190);
    return 1;
}

return 0;
}

int chtrashcangame_entrypoint_2()
{
    return (int) &D_808033A0_chtrashcangame;
}

void func_80802C40_chtrashcangame(f32 *actor_pos)
{
    f32 deflect_pos[3];
    s32 unk_0;

    unk_0 = func_800F54E4();

if (func_800F64A4(unk_0, 0x400)) {
    func_800EFA4C(deflect_pos, actor_pos[1], 1300.0f, actor_pos[3]);
    deflect_pos[1] += 150.0f;
    _sudeflect_entrypoint_0(deflect_pos, 0.0f, 200.0f, 2);
}

}

int *chtrashcangame_entrypoint_3()
{
    return &D_808033E8_chtrashcangame;
}

void func_80802CC0_chtrashcangame(Actor *actor)
{
    _chdoormake_entrypoint_3(actor, actor->rotation[1], 90.0f, func_80103EF4(actor), 0x802,
                             0);
    _chdoormake_entrypoint_8(actor, 2);
    _chdoormake_entrypoint_5(actor, 2.0f);
}

int chtrashcangame_entrypoint_4()
{
    return &D_80803430_chtrashcangame;
}

extern void func_80105834();
extern void func_80101870();
extern void func_80108ED0();
extern void func_80107C2C();
extern void _chdoor_entrypoint_0();
extern void _chdoor_entrypoint_1();
u32 D_80802FF0_chtrashcangame[1] = {0x0};
TrashAnimation D_80802FF4_chtrashcangame[19] = {
    0x0,   0x0, 7.21f, 0x369, 0x1, 7.21f, 0x369, 0x1, 7.21f, 0x369, 0x1, 7.21f, 0x369, 0x1, 7.21f,
    0x369, 0x1, 7.21f, 0x369, 0x1, 7.21f, 0x369, 0x1, 7.21f, 0x369, 0x1, 6.67f, 0x36A, 0x1, 6.67f,
    0x36A, 0x1, 4.95f, 0x36B, 0x1, 4.95f, 0x36B, 0x1, 4.95f, 0x36B, 0x1, 4.95f, 0x36B, 0x1, 4.95f,
    0x36B, 0x1, 4.95f, 0x369, 0x1, 4.95f, 0x369, 0x1, 4.95f, 0x36B, 0x1, 4.95f};
static u32 D_80802FF4_chtrashcangame_rest[1] = {0x36B0001};
u8 D_80803090_chtrashcangame[28] = {0x3, 0x8E, 0x1,  0x5E, 0x13, 0xEE, 0x13, 0xEF, 0x0, 0x0,
                                    0x4, 0x0,  0x12, 0x8,  0x0,  0x0,  0x0,  0x6A, 0x0, 0x0,
                                    0x0, 0x4E, 0x26, 0x3C, 0x3,  0x0,  0x0,  0x0};
u8 D_808030AC_chtrashcangame[16] = {0x43, 0x96, 0x0, 0x0, 0x42, 0xC8, 0x0, 0x0,
                                    0x42, 0xC8, 0x0, 0x0, 0x43, 0x48, 0x0, 0x0};
TrashParticleColours27 D_808030BC_chtrashcangame = {0x3E439581, 0x3F43D70A, 0x3F5851EC,
                                                    -0x40800000};
TrashParticleColours27 D_808030CC_chtrashcangame = {0x3E6147AE, 0x3F4D0E56, 0x3F62D0E5,
                                                    -0x40800000};
TrashParticleColours27 D_808030DC_chtrashcangame = {0x3E000000, 0x3F41CAC1, 0x3F574BC7,
                                                    -0x40800000};
TrashParticleColours27 D_808030EC_chtrashcangame = {0x3E439581, 0x3F43D70A, 0x3F5851EC,
                                                    -0x40800000};
TrashParticleColours27 D_808030FC_chtrashcangame = {0x3E6147AE, 0x3F4D0E56, 0x3F62D0E5,
                                                    -0x40800000};
TrashParticleColours27 D_8080310C_chtrashcangame = {0x3E000000, 0x3F41CAC1, 0x3F574BC7,
                                                    -0x40800000};
TrashParticleColours27 D_8080311C_chtrashcangame = {0x3E147AE1, 0x3E6A7EFA, 0x3EA45A1D,
                                                    -0x40800000};
TrashTimes7 D_8080312C_chtrashcangame = {0x3E3A5E35, 0x3E87AE14, 0x3EB7CED9, 0x3ECF5C29,
                                         0x3F20C49C, 0x3F36872B, -0x40800000};
TrashTimes7 D_80803148_chtrashcangame = {0x3E0624DD, 0x3E5D2F1B, 0x3E9D2F1B, 0x3EC7AE14,
                                         0x3F2E5604, 0x3F445A1D, -0x40800000};
TrashParticleColours27 D_80803164_chtrashcangame = {-0x699BB97E, -0x6969B97E, 0x64964682,
                                                    0x64644682};
u8 D_80803174_chtrashcangame[64] = {
    0x1, 0x10, 0x0, 0x1D, 0x9, 0xDC, 0x0, 0x18, 0x0, 0x0,  0x0, 0x2,  0xC, 0x0,  0xF, 0x0,
    0x0, 0x1B, 0x0, 0x64, 0x0, 0xC8, 0x0, 0x16, 0x6, 0x0,  0x0, 0x2C, 0x0, 0x0,  0x0, 0x32,
    0x0, 0x0,  0x0, 0x0,  0x0, 0x64, 0x0, 0x0,  0x0, 0x22, 0x0, 0x33, 0x0, 0x33, 0x4, 0x0,
    0x5, 0x0,  0x0, 0x15, 0x0, 0x66, 0x0, 0x80, 0x0, 0x2B, 0x3, 0x0,  0x4, 0x0,  0x0, 0x0};
int D_808031B4_chtrashcangame[18] = {0x1580475,
                                     0x8080003,
                                     (u32) &D_80802FF0_chtrashcangame,
                                     (u32) func_80800180_chtrashcangame,
                                     (u32) func_80105834,
                                     (u32) func_80101870,
                                     0x0,
                                     0x3F800000,
                                     0x0,
                                     0x109,
                                     0x0,
                                     (u32) func_80108ED0,
                                     0x0,
                                     0x0,
                                     (u32) func_80107C2C,
                                     -0x7FFFDBFE,
                                     (u32) func_8080093C_chtrashcangame,
                                     0x0};
int D_808031FC_chtrashcangame[18] = {0x158051C,
                                     0x1,
                                     0x0,
                                     (u32) func_80801D54_chtrashcangame,
                                     (u32) func_80105834,
                                     (u32) func_80101870,
                                     0x0,
                                     0x0,
                                     0x0,
                                     0x1,
                                     0x0,
                                     (u32) func_80108ED0,
                                     0x0,
                                     (u32) func_80801CF0_chtrashcangame,
                                     (u32) func_80107C2C,
                                     -0x7FFFD9FE,
                                     (u32) func_808020D8_chtrashcangame,
                                     0x0};
u32 D_80803244_chtrashcangame[10] = {0x0,       0x0,        0x3F000000, 0x361004A,  0x3F800000,
                                     0x3610009, 0x40400000, 0x362004A,  0x3F000000, 0x3610092};
u8 D_8080326C_chtrashcangame[84] = {
    0x0,  0x1D, 0x9,  0xC8, 0x0,  0x19, 0x0, 0x0,  0x0, 0x3,  0x0, 0x1B, 0xFE, 0x70,
    0xFE, 0xD4, 0x0,  0x2D, 0x0,  0xC8, 0x1, 0x90, 0x0, 0xE,  0x0, 0x0,  0x0,  0x32,
    0x0,  0x16, 0x14, 0x0,  0x0,  0x27, 0x0, 0x0,  0x0, 0x96, 0x0, 0x0,  0x1,  0xC2,
    0x0,  0x23, 0x0,  0x26, 0x0,  0x15, 0x0, 0xC,  0x0, 0xD9, 0x0, 0x2B, 0x1,  0x0,
    0x2,  0x0,  0x0,  0x31, 0xFF, 0xF6, 0x0, 0x0,  0x0, 0x2F, 0x1, 0x0,  0x1,  0x0,
    0x0,  0x0,  0x0,  0x33, 0x0,  0x4C, 0x0, 0x0,  0x0, 0x66, 0x0, 0x0,  0x0,  0x0};
u8 D_808032C0_chtrashcangame[64] = {
    0x1, 0x10, 0x0, 0x1D, 0x9,  0xDA, 0x0, 0x1B, 0xFC, 0xE0, 0xFD, 0xA8, 0x0, 0xE,  0x0, 0x0,
    0x0, 0x3C, 0x0, 0x23, 0x0,  0x19, 0x0, 0x15, 0x0,  0xC,  0x0,  0xE6, 0x0, 0x1E, 0x0, 0x32,
    0x0, 0x32, 0x0, 0x16, 0x10, 0x0,  0x0, 0x2B, 0x0,  0x80, 0x1,  0x0,  0x0, 0x2F, 0x0, 0x19,
    0x0, 0x33, 0x0, 0x0,  0x0,  0x0,  0x0, 0x0,  0x0,  0x0,  0x0,  0x82, 0x0, 0x0,  0x0, 0x0};
u8 D_80803300_chtrashcangame[36] = {0x3C, 0xCC, 0xCC, 0xCD, 0x3D, 0x4C, 0xCC, 0xCD, 0x3D,
                                    0x99, 0x99, 0x9A, 0x3D, 0xCC, 0xCC, 0xCD, 0x3E, 0x19,
                                    0x99, 0x9A, 0x3E, 0x4C, 0xCC, 0xCD, 0x3E, 0x80, 0x0,
                                    0x0,  0x3E, 0x99, 0x99, 0x9A, 0xBF, 0x80, 0x0,  0x0};
u8 D_80803324_chtrashcangame[64] = {
    0x0, 0x1D, 0x9,  0x20, 0x0, 0x1B, 0xFC, 0x7C, 0xFD, 0xA8, 0x0, 0x2D, 0x1, 0xF4, 0x2, 0xBC,
    0x0, 0xE,  0x0,  0x0,  0x0, 0x14, 0x0,  0x27, 0x0,  0x0,  0x0, 0x0,  0x1, 0xF4, 0x1, 0xF4,
    0x0, 0x16, 0x14, 0x2,  0x0, 0x23, 0x0,  0x59, 0x0,  0x2B, 0x1, 0x80, 0x2, 0x0,  0x0, 0x4,
    0x0, 0x66, 0x0,  0x7,  0x0, 0x3,  0x0,  0x31, 0xFF, 0xEC, 0x0, 0x14, 0x0, 0x0,  0x0, 0x0};
u8 D_80803364_chtrashcangame[48] = {
    0x6, 0x10, 0x0, 0x1D, 0x9, 0xDA, 0x0, 0x1B, 0xFC, 0x18, 0xFC, 0x7C, 0x0, 0x2D, 0x1, 0xF4,
    0x2, 0x58, 0x0, 0xE,  0x0, 0x0,  0x0, 0x14, 0x0,  0x16, 0x10, 0x0,  0x0, 0x23, 0x0, 0x19,
    0x0, 0x2B, 0x1, 0x80, 0x2, 0x0,  0x0, 0x31, 0xFF, 0xCE, 0x0,  0x32, 0x0, 0x0,  0x0, 0x0};
u8 D_80803394_chtrashcangame[4] = {0xB4, 0x64, 0x64, 0xFF};
u8 D_80803398_chtrashcangame[4] = {0x64, 0xB4, 0x64, 0xFF};
u8 D_8080339C_chtrashcangame[4] = {0x64, 0x64, 0xB4, 0xFF};
int D_808033A0_chtrashcangame[18] = {0x1220476,
                                     0x8060001,
                                     (u32) &D_80803244_chtrashcangame,
                                     (u32) func_8080223C_chtrashcangame,
                                     (u32) func_80105834,
                                     (u32) func_80101870,
                                     0x0,
                                     0x0,
                                     0x0,
                                     0xD,
                                     0x0,
                                     (u32) func_80108ED0,
                                     0x0,
                                     (u32) func_808021BC_chtrashcangame,
                                     (u32) func_80107C2C,
                                     -0x7FDFF000,
                                     (u32) func_8080292C_chtrashcangame,
                                     0x0};
int D_808033E8_chtrashcangame[18] = {0x158050E,
                                     0x8D20001,
                                     0x0,
                                     (u32) func_80802C40_chtrashcangame,
                                     (u32) func_80105834,
                                     (u32) func_80101870,
                                     0x0,
                                     0x0,
                                     0x0,
                                     0x20C00,
                                     0x0,
                                     (u32) func_80108ED0,
                                     0x0,
                                     0x0,
                                     (u32) func_80107C2C,
                                     -0x7FFFDC00,
                                     0x0,
                                     0x0};
int D_80803430_chtrashcangame[20] = {0xAC0533,
                                     0x8CC0004,
                                     0x0,
                                     (u32) _chdoor_entrypoint_0,
                                     (u32) func_80105834,
                                     (u32) func_80101870,
                                     0x0,
                                     0x0,
                                     0x0,
                                     0x800,
                                     0x0,
                                     0x0,
                                     0x0,
                                     (u32) func_80802CC0_chtrashcangame,
                                     (u32) func_80107C2C,
                                     -0x7FFFDBFE,
                                     (u32) _chdoor_entrypoint_1,
                                     0x0,
                                     0x0,
                                     0x0};
