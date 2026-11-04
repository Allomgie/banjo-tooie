#include "su/mole.h"

#define MOLE_DATA(arg0) ((MoleActorData *) (arg0->actorData))

extern u32 D_80802510_sumole[];
extern u32 D_80802520_sumole[];
extern s32 D_80802530_sumole[];
extern s32 D_8080254C_sumole[];
extern s32 D_8080255C_sumole[];
extern s32 D_8080256C_sumole[27];
extern s32 D_808025B4_sumole[];

extern s32 _sumole_entrypoint_21;
s32 sumole_entrypoint_17(Actor *arg0, s16 arg1, s32 arg2, s32 arg3);
Unk80132ED0 *func_80802178_sumole(Actor *arg0);

s32 func_80800000_sumole(Actor *actor, MoveData *moves)
{
    return moves[(s32) actor->unk54].price;
}

void sumole_entrypoint_0(Actor *actor, s32 arg1)
{
    Prop *prop;

    prop = _gccubesearch_entrypoint_1(0x387U, actor->position);
    if (prop == NULL) {
        func_800EE7F8(MOLE_DATA(actor)->unk0, actor->position);
        func_800EF1B8(MOLE_DATA(actor)->unk0, actor->rotation[1] - 90.0f, 200.0f);
    } else {
        _gspropctrl_entrypoint_11(prop, MOLE_DATA(actor)->unk0);
    }
    if ((actor->unk3C == NULL) && !actor->unk64_20) {
        _chbaddiesetup_entrypoint_2(&_sumole_entrypoint_21, actor->unk0, arg1);
        actor->unk64_20 = 1;
    }
    _subaddieDll_entrypoint_4(actor, 1U);
}

s32 sumole_entrypoint_1(Actor *actor, s32 next_state, u32 price, s32 ability)
{
    // Only these characters can talk to Jamjars at all
    if (func_80090178(ALLOW_BK | ALLOW_BANJO | ALLOW_KAZOOIE | ALLOW_MUMBO | ALLOW_FIRSTPERSON) ==
        0) {
        return 0;
    }
    if ((price != 0) && (func_8010CAC0(actor->position, 0x177U) != 0) &&
        ((ability == -1) || (func_800C6E38(ability) == 0))) {
        func_800D2498(0xD0U, func_800D035C(6), 0U);
        func_800D2498(0xEAU, price, 0U);
    }
    if (_subaddiedialog_entrypoint_4(actor->position, 0xFA, 0) != 0) {
        if (next_state != -1) {
            actor->unk70_10 = next_state;
        }
        actor->unk6C_0 = 0;
        return 1;
    }
    return 0;
}

void func_808001E0_sumole(Actor *actor, s32 preset)
{
    f32 cam_pos[3];

    func_800EE7F8(cam_pos, actor->position);
    func_800EF1B8(cam_pos, actor->rotation[1] + 15.0f, 150.0f);
    switch (preset) {
        case 1:
            _gcdialogcamera_entrypoint_3(D_80802510_sumole, actor->scale);
            break;
        case 2:
        case 3:
            _gcdialogcamera_entrypoint_3(D_80802520_sumole, actor->scale);
            break;
        case 0:
            _gcdialogcamera_entrypoint_3((u32 *) D_80802530_sumole, actor->scale);
    }
    _capod_entrypoint_10(0U, actor->position);
    _capod_entrypoint_11(0U, actor->rotation);
    _capod_entrypoint_12(1);
    _gcdialogcamera_entrypoint_8();
    _capod_entrypoint_10(1U, cam_pos);
}

void func_808002E0_sumole(Actor *actor, s32 arg1, s32 arg2, s32 preset)
{
    switch (actor->unk7A_11) {
        case 0:
            _capod_entrypoint_2(actor->unk0, 4U, 0x800);
        case 1:
            _capod_entrypoint_8(1);
            actor->unk7A_11 = 2;
        case 2:
            func_808001E0_sumole(actor, preset);
            _capod_entrypoint_7(arg1, arg2);
    }
}

void func_8080037C_sumole(Actor *actor, s32 arg1, s32 arg2, s32 arg3)
{
    switch (actor->unk7A_11) {
        case 0:
            _capod_entrypoint_2(actor->unk0, 4, 0x800);
        case 2:
            actor->unk7A_11 = 1;
        case 1:
            _capod_entrypoint_6(arg3, arg1, arg2);
    }
}

void func_80800408_sumole(Actor *actor)
{
    if (actor->unk7A_11 != 0) {
        _capod_entrypoint_3(0U);
        actor->unk7A_11 = 0;
    }
}

void sumole_entrypoint_13();

void sumole_entrypoint_9();

// Leaves the current state and enters new_state, running exit and entry actions.
void sumole_entrypoint_2(Actor *actor, s32 new_state)
{
    for (;;) {
        switch (actor->unk70_10) {
            case 1:
                if (new_state != 12)
                    func_800C78CC(1);
                break;
            case 7:
            case 22:
                func_800DA544(0x9F1);
                func_808002E0_sumole(actor, 2, 1, 2);
                break;
            case 3:
                func_808002E0_sumole(actor, 2, 0, 2);
                break;
            case 8:
                sumole_entrypoint_19(actor, 3);
        }
        actor->unk70_10 = new_state;
        switch (actor->unk70_10) {
            case 13:
                _chmolehill_entrypoint_1(func_80106790(actor->unk3C), 7);
                break;
            case 3:
                func_808002E0_sumole(actor, 2, 1, 3);
                sumole_entrypoint_7(actor);
                sumole_entrypoint_19(actor, 3);
                break;
            case 14:
                func_808002E0_sumole(actor, 2, 1, 0);
                sumole_entrypoint_9(actor);
                sumole_entrypoint_19(actor, 3);
                break;
            case 7:
                if ((s32) actor->unk58 == 0)
                    return;
                break;
            case 11:
                func_808002E0_sumole(actor, 2, 1, 1);
                sumole_entrypoint_13(actor);
                break;
            case 17:
                // Matching: no-op reassignments raise actor's register priority above new_state.
                actor = (Actor *) ((s32) actor * 1);
                actor = (Actor *) ((s32) actor * 1);
                actor = (Actor *) ((s32) actor * 1);
                actor = (Actor *) ((s32) actor * 1);
                actor = (Actor *) ((s32) actor * 1);
                actor = (Actor *) ((s32) actor * 1);
                new_state = func_8008FC28();
                if (func_8008FC00() < new_state) {
                    if (!func_800DA9E4(0x422, 1))
                        return;
                    new_state = 20;
                    continue;
                }
                if (_chmolehill_entrypoint_3(func_80106790(actor->unk3C))) {
                    new_state = 9;
                } else {
                    new_state = 18;
                    func_800C0850();
                }
                continue;
            case 20:
                new_state = func_8008FC00();
                if (new_state >= func_8008FC28()) {
                    if (_chmolehill_entrypoint_3(func_80106790(actor->unk3C))) {
                        new_state = 9;
                    } else {
                        new_state = 18;
                        func_800C0850();
                    }
                    continue;
                }
                ((f32 *) actor->actorData)[6] = 0.2f;
                break;
            case 1:
                func_800C78CC(0);
                func_800DA524(0x9F1);
                func_80800408_sumole(actor);
                sumole_entrypoint_19(actor, 0);
                actor->unk54 = (s32) actor->unk74_7;
        }
        return;
    }
}

typedef union {
    s32 i;
    struct {
        s16 s_0;
        s16 s_1;
    };
} Arg2;

s32 sumole_entrypoint_3(Actor *actor, s32 event, Arg2 event_data, MoveData *moves)
{
    s32 dialog_id;
    Actor *spawned;
    Actor *hill;
    s32 i;

    switch (event) {
        case 0x95:
            if (_glcutDll_entrypoint_20() != 0) {
                sumole_entrypoint_2(actor, 0xC);
            }
            break;
        case 0x21:
            func_80101074(moves);
            break;
        case 0x3D:
            switch (event_data.i) {
                case 4:
                case 5:
                case 6:
                    spawned =
                        func_80108528(0xB7, MOLE_DATA(actor)->unk0, (s32) actor->rotation[1], &actor);
                    spawned->unk6C_0 = event_data.i - 4;
                    func_8080037C_sumole(actor, D_80802530_sumole[event_data.i], 0x6000, 0);
                    break;
                case 0:
                case 1:
                case 2:
                case 3:
                    func_8080037C_sumole(actor, D_8080254C_sumole[event_data.i], 0x6000, 0);
                    _chappearfx_entrypoint_2(_chbounce_entrypoint_7(0x1D, MOLE_DATA(actor)->unk0,
                                                                    D_8080255C_sumole[event_data.i]),
                                             0x2A, 0, 1.0f);
            }
            break;
        case 0x2E:
            dialog_id = event_data.s_0;
            if (dialog_id == 0xD6C) {
                sumole_entrypoint_16(actor, 0xD6C);
                if (event_data.s_1 == 1) {
                    sumole_entrypoint_2(actor, 7);
                } else {
                    sumole_entrypoint_2(actor, 6);
                }
            } else {
                sumole_entrypoint_16(actor, dialog_id);
            }
            break;
        case 0x2F:
            hill = func_80106790(actor->unk3C);
            switch (event_data.s_1) {
                case 1:
                    if (_chmolehill_entrypoint_3(hill) != 0) {
                        _chmolehill_entrypoint_1(hill, 5);
                    }
                    break;
                case 2:
                    if (_chmolehill_entrypoint_3(hill) != 0) {
                        _chmolehill_entrypoint_1(hill, 6);
                    }
                    break;
                case 4:
                    if (moves[(s32) actor->unk54].unkE > 0) {
                        _chintrotext_entrypoint_1(0x18BB, moves[(s32) actor->unk54].unkE - 1, 0, 1);
                    }
                    break;
                case 5:
                    for (i = 0; i < 27; i += 3) {
                        if (D_8080256C_sumole[i + 0] ==
                            moves[(s32) actor->unk54].MoveTutorialDialog) {
                            func_80108B04(actor, D_8080256C_sumole[i + 1]);
                        }
                    }
            }
            break;
        case 0xAC:
            if (moves[(s32) actor->unk54].TitleToShow != 0) {
                return _ncpoddialog_entrypoint_8(func_80101080(),
                                                 moves[(s32) actor->unk54].TitleToShow);
            }
            return 3;
        case 0xB:
            switch (event_data.i) {
                case 30:
                case 37:
                case 0x42:
                    func_808002E0_sumole(actor, 2, 1, 2);
                    return 4;
                case 7:
                case 13:
                case 15:
                case 33:
                    func_808002E0_sumole(actor, 2, 1, 2);
                    if (func_800C6E38(0x18) != 0) {
                        sumole_entrypoint_2(actor, 0x11);
                        return 4;
                    }
                    actor->unk54 = 4.0f;
                    sumole_entrypoint_2(actor, 7);
                default:
                    return 4;
            }
        case 0x30:
            return func_80800000_sumole(actor, moves);
        default:
            return 0;
    }
    return 1;
}

void sumole_entrypoint_4(Actor *actor, MoveData *moves)
{
    Actor *hill;
    f32 pitch;
    s32 pad;
    s32 pad2;
    s32 unk_0;

    if (actor->unk3C != NULL) {
        if (!actor->unk7A_8) {
            _subaddieDll_entrypoint_4(actor, 0U);
            actor->unk7A_8 = 1;
        }
        if (moves[(s32) actor->unk54].AbilityToLearn != -1) {
            unk_0 = moves[(s32) actor->unk54].AbilityToLearn == 0x18;
            if (unk_0 == 0) {
                unk_0 = func_800C6E38(moves[(s32) actor->unk54].AbilityToLearn) != 0;
            }
            if (unk_0 != actor->unk74_29) {
                hill = func_80106790(actor->unk3C);
                hill->unk74_29 = unk_0;
                actor->unk74_29 = unk_0;
            }
        }
        switch (actor->unk70_10) {
            case 1:
                if (sumole_entrypoint_1(actor, -1, func_80800000_sumole(actor, moves),
                                        (s32) moves[(s32) actor->unk54].AbilityToLearn) != 0) {
                    if (sumole_entrypoint_5(actor, moves[(s32) actor->unk54].charactersAllowed, -1,
                                            -1) != 0) {
                        if (func_800DA298(FLAG_40C_FTT_JAMJARS) == 0) {
                            sumole_entrypoint_2(actor, 3);
                            return;
                        }
                        if ((moves[(s32) actor->unk54].AbilityToLearn != -1) &&
                            (func_800C6E38((s32) moves[(s32) actor->unk54].AbilityToLearn) == 0)) {
                            unk_0 = func_80800000_sumole(actor, moves);
                            if (unk_0 > func_800D035C(6)) {
                                sumole_entrypoint_2(actor, 0xE);
                                actor->unk6C_0 = 0xF;
                                return;
                            }
                            sumole_entrypoint_7(actor);
                            sumole_entrypoint_2(actor, 3);
                            return;
                        }
                        sumole_entrypoint_2(actor, 0xE);
                        actor->unk6C_0 = 0xA;
                        return;
                    }
                    sumole_entrypoint_2(actor, 0xE);
                    if (func_80090178(ALLOW_BK | ALLOW_KAZOOIE | ALLOW_BANJO) != 0) {
                        if ((moves[(s32) actor->unk54].AbilityToLearn != -1) &&
                            (func_800C6E38(moves[(s32) actor->unk54].AbilityToLearn) == 0)) {
                            actor->unk6C_0 = 2;
                            return;
                        }
                        actor->unk6C_0 = 0xA;
                        return;
                    }
                    actor->unk6C_0 = 2;
                }
                break;
            case 2:
                sumole_entrypoint_15(actor, (s32) moves[(s32) actor->unk54].charactersAllowed, -1);
                return;
            case 4:
                sumole_entrypoint_17(actor, (s16) moves[(s32) actor->unk54].CannotAffordDialog, -1, 0);
                return;
            case 7:
                sumole_entrypoint_17(actor, (s16) moves[(s32) actor->unk54].MoveTutorialDialog, -1, 1);
                return;
            case 8:
                if (actor->unk79_4 != 4) {
                    sumole_entrypoint_19(actor, 4);
                }
                sumole_entrypoint_18(actor, 250.0f);
                if (sumole_entrypoint_20(actor, (s32) (s8) moves[(s32) actor->unk54].unk11, -1) != 0) {
                    sumole_entrypoint_2(actor, 0x11);
                }
                break;
            case 10:
                sumole_entrypoint_17(actor, (s16) moves[(s32) actor->unk54].AlreadyLearnedDialog, -1,
                                     0);
                return;
            case 11:
                if (sumole_entrypoint_14(actor) != 0) {
                    sumole_entrypoint_2(actor, 1);
                }
                break;
            case 3:
                if (sumole_entrypoint_8(actor, -1) != 0) {
                    if (func_800DA9E4(FLAG_40C_FTT_JAMJARS, 1) == 0) {
                        sumole_entrypoint_2(actor, 0x10);
                        return;
                    }
                    if (func_800DA9E4(FLAG_424_FTT_JAMJARS_FIRST_LESSON_INTRO, 1) == 0) {
                        sumole_entrypoint_2(actor, 0x13);
                        return;
                    }
                    sumole_entrypoint_2(actor, 7);
                }
                break;
            case 16:
                sumole_entrypoint_17(actor, 0xDB6, -1, 0);
                return;
            case 19:
                sumole_entrypoint_17(actor, 0xDBE, -1, 0);
                return;
            case 5:
                sumole_entrypoint_17(actor, 0xD6C, -1, 0);
                return;
            case 6:
                sumole_entrypoint_17(actor, 0xD6D, -1, 0);
                return;
            case 14:
                if (sumole_entrypoint_10(actor, -1) != 0) {
                    sumole_entrypoint_2(actor, actor->unk6C_0);
                }
                break;
            case 15:
                sumole_entrypoint_17(actor, moves[(s32) actor->unk54].CannotAffordDialog, -1, 0);
                return;
            case 9:
                sumole_entrypoint_17(actor, 0xD6E, -1, 0);
                return;
            case 18:
                sumole_entrypoint_11(actor);
                sumole_entrypoint_2(actor, 0x15);
                return;
            case 21:
                if (sumole_entrypoint_12(actor) != 0) {
                    sumole_entrypoint_2(actor, 1);
                }
                break;
            case 17:
                func_8008FBE0(1U);
                sumole_entrypoint_17(actor, 0xDB7, -1, 0);
                return;
            case 20:
                unk_0 = func_8008FC00();
                if (unk_0 >= func_8008FC28()) {
                    if (_chmolehill_entrypoint_3(func_80106790(actor->unk3C)) != 0) {
                        sumole_entrypoint_2(actor, 9);
                        return;
                    }
                    sumole_entrypoint_2(actor, 0x12);
                    return;
                }
                MOLE_DATA(actor)->unk18 -= func_800D8FF8();
                if (MOLE_DATA(actor)->unk18 <= 0.0f) {
                    pitch = func_800F10B4((f32) (func_8008FC00() + 1), 1.0f, 10.0f, 0.8f, 1.5f);
                    MOLE_DATA(actor)->unk18 = 0.2f;
                    func_800C3FC0(0x66C, pitch, 0x3E80);
                    func_8008FC50();
                }
                break;
            case 12:
                sumole_entrypoint_2(actor, 0xD);
            case 22:
                break;
        }
    }
}

s32 sumole_entrypoint_5(Actor *actor, s32 allowed, AllowedTransformation ok_state, s32 denied_state)
{
    if (ok_state != -1) {
        if (allowed == -1U) {
            actor->unk70_10 = ok_state;
        } else if (func_80090178(allowed) != 0) {
            actor->unk70_10 = ok_state;
        } else {
            actor->unk70_10 = denied_state;
        }
        return 0;
    }
    {
        if (allowed == -1U) {
            return 1;
        }
        if (func_80090178(allowed) != 0) {
            return 1;
        }
    }
    return 0;
}

s32 sumole_entrypoint_6(Actor *actor, s32 next_state, f32 arg2)
{
    f32 player_pos[3];
    func_8010D254(player_pos);
    if (_subaddiedialog_entrypoint_0(actor, (s32) arg2, 0) != 0) {
        if (next_state != -1) {
            actor->unk70_10 = next_state;
        }
        return 1;
    }
    return 0;
}

void sumole_entrypoint_7(Actor *actor)
{
    _chmolehill_entrypoint_1(func_80106790(actor->unk3C), 1);
}

s32 sumole_entrypoint_8(Actor *actor, s32 next_state)
{
    Actor *hill;

    hill = func_80106790(actor->unk3C);
    if ((func_800C064C() == -1) && (hill->unk64_19 == 1) && (hill->unk3C != NULL)) {
        if (next_state != -1) {
            actor->unk70_10 = next_state;
        }
        return 1;
    }
    return 0;
}

void sumole_entrypoint_9(Actor *actor)
{
    _chmolehill_entrypoint_1(func_80106790(actor->unk3C), 3);
}

s32 sumole_entrypoint_10(Actor *actor, s32 next_state)
{
    Actor *hill;

    hill = func_80106790(actor->unk3C);
    if ((func_800C064C() == -1) && (hill->unk64_19 == 1) && (hill->unk3C != NULL)) {
        if (next_state != -1) {
            actor->unk70_10 = next_state;
        }
        return 1;
    }
    return 0;
}

void sumole_entrypoint_11(Actor *actor)
{
    _chmolehill_entrypoint_1(func_80106790(actor->unk3C), 4);
}

s32 sumole_entrypoint_12(Actor *actor)
{
    if (func_80106790(actor->unk3C)->unk70_10 == 1) {
        return 1;
    }
    return 0;
}

void sumole_entrypoint_13(Actor *actor)
{
    _chmolehill_entrypoint_1(func_80106790(actor->unk3C), 2);
}

s32 sumole_entrypoint_14(Actor *actor)
{
    if (func_80106790(actor->unk3C)->unk70_10 == 1) {
        return 1;
    }
    return 0;
}

s32 sumole_entrypoint_15(Actor *actor, s32 characters, s32 next_state)
{
    s16 message;

    message = func_800DC128(0xD7B, 0xD7D);
    switch (characters) {
        case ALLOW_BANJO: // Banjo moves
            if (func_8010D278() == TRANSFORM_B_KAZOOIE) {
                // Random refusal message from Kazooie
                message = func_800DC128(0xD71, 0xD73);
            } else {
                if (func_8010D278() == TRANSFORM_1_BK) {
                    // Random message telling the player to get rid of Kazooie
                    message = func_800DC128(0xD6F, 0xD71);
                }
            }
            break;
        case ALLOW_KAZOOIE: // Kazooie moves
            if (func_8010D278() == TRANSFORM_A_BANJO) {
                // Random refusal message from Banjo
                message = func_800DC128(0xD73, 0xD75);
            } else {
                if (func_8010D278() == TRANSFORM_1_BK) {
                    // Random message telling the player to get rid of Banjo
                    message = func_800DC128(0xD75, 0xD77);
                }
            }
            break;
        case ALLOW_BK: // Banjo-Kazooie moves
            if (func_8010D278() == TRANSFORM_B_KAZOOIE) {
                // Random refusal message from Kazooie
                message = func_800DC128(0xD79, 0xD7B);
            } else {
                if (func_8010D278() == TRANSFORM_A_BANJO) {
                    // Random refusal message from Banjo
                    message = func_800DC128(0xD77, 0xD79);
                }
            }
    }
    return sumole_entrypoint_17(actor, message, next_state, 0);
}

void sumole_entrypoint_16(Actor *actor, s32 dialog_id)
{
    MoveData *moves;
    s32 i;

    func_8010114C((s32) actor->unk0, 0x21, 0);
    moves = (MoveData *) func_80101080();
    actor->unk58 = 0.0f;
    switch (actor->unk70_10) {
        case 16:
            if (moves[(s32) actor->unk54].AbilityToLearn != -1) {
                if (func_800C6E38(moves[(s32) actor->unk54].AbilityToLearn) == 0) {
                    if (func_80800000_sumole(actor, moves) > func_800D035C(6)) {
                        sumole_entrypoint_2(actor, 0xF);
                        return;
                    }
                    if (func_800DA9E4(FLAG_424_FTT_JAMJARS_FIRST_LESSON_INTRO, 1) == 0) {
                        sumole_entrypoint_2(actor, 0x13);
                        return;
                    }
                    sumole_entrypoint_2(actor, 7);
                    return;
                }
            }
            sumole_entrypoint_2(actor, 0xA);
            return;
        case 2:
            if (func_80090178(ALLOW_BK | ALLOW_KAZOOIE | ALLOW_BANJO) != 0) {
                sumole_entrypoint_2(actor, 0x11);
                return;
            }
            sumole_entrypoint_11(actor);
            sumole_entrypoint_2(actor, 0x15);
            return;
        case 15:
            sumole_entrypoint_2(actor, 0x11);
            return;
        case 4:
            sumole_entrypoint_2(actor, 5);
            return;
        case 6:
            sumole_entrypoint_2(actor, 0x11);
            return;
        case 19:
            if (func_80800000_sumole(actor, moves) > func_800D035C(6)) {
                sumole_entrypoint_2(actor, 0xF);
                return;
            }
            sumole_entrypoint_2(actor, 7);
            return;
        case 10:
            if (_chmolehill_entrypoint_3(func_80106790(actor->unk3C)) == 0) {
                func_800C0850();
            }
            sumole_entrypoint_2(actor, 0x11);
            return;
        case 17:
            if (_chmolehill_entrypoint_3(func_80106790(actor->unk3C)) == 0) {
                func_800C0850();
            }
            sumole_entrypoint_2(actor, 0x14);
            return;
        case 9:
            sumole_entrypoint_2(actor, 0xB);
            return;
        case 7:
            func_800FC6B0(0x10U);
            if (moves[(s32) actor->unk54].AbilityToLearn != -1) {
                func_800C7074((s32) moves[(s32) actor->unk54].AbilityToLearn,
                              func_800DA298(FLAG2_660_UNK));
            }
            for (i = 0; i < 8; i++) {
                if (D_808025B4_sumole[i * 2 + 0] ==
                    (s16) moves[(s32) actor->unk54].MoveTutorialDialog) {
                    func_80108B04(actor, D_808025B4_sumole[i * 2 + 1]);
                    sumole_entrypoint_2(actor, 0x16);
                    break;
                }
            }
            if (i >= 8U) {
                sumole_entrypoint_2(actor, 0x11);
            }
    }
}

s32 sumole_entrypoint_17(Actor *actor, s16 message, s32 next_state, s32 arg3)
{
    Unk80132ED0 *target_copy;
    Unk80132ED0 *target;

    target = func_80802178_sumole(actor);
    // Matching: extra copy of the pointer needed for the match.
    target_copy = target;
    switch ((s32) actor->unk58) {
        case 0:
            if (target != NULL) {
                func_800C05B8(message, 7, actor->position, target_copy, 0, 0, 0);
            } else {
                func_800C05B8(message, 7, actor->position, NULL, 0, 0,
                              func_800DA298(FLAG_578_PROGRESS_BOTTLES_ENERGY_RESTORED) != 0 ? 0xF
                                                                                            : 0x84);
            }
            actor->unk58 = 1.0f;
            break;
        case 1:
            if (func_800C064C() == message) {
                actor->unk58 = 2.0f;
            }
            break;
        case 2:
            if (func_800C064C() == -1) {
                actor->unk58 = 0.0f;
                if (next_state != -1) {
                    actor->unk70_10 = next_state;
                }
                return 1;
            }
    }
    return 0;
}

// Pulls the player back toward Jamjars when farther away than max_dist.
void sumole_entrypoint_18(Actor *actor, f32 max_dist)
{
    f32 delta[3];
    f32 dist;

    if ((actor->unk6C_0 == 2) || (actor->unk6C_0 == 4)) {
        func_8010D254(delta);
        func_800EF3DC(delta, actor->position);
        dist = func_800EEF94(delta);
        if (dist != 0.0f) {
            dist = max_dist / dist;
            if (dist < 1.0f) {
                func_800EF334(delta, dist);
                func_800EF04C(delta, actor->position);
                func_800907C0(delta);
            }
        }
    }
}

void sumole_entrypoint_19(Actor *actor, s32 new_mode)
{
    if (new_mode != actor->unk79_4) {
        switch (actor->unk79_4) {
            case 0:
                switch (new_mode) {
                    case 1:
                        func_80090708(0);
                        actor->unk79_4 = new_mode;
                        return;
                    case 2:
                        func_8010D254(actor->position);
                        actor->unk79_4 = new_mode;
                        return;
                    case 3:
                        func_80090734(1, actor->position);
                        actor->unk79_4 = new_mode;
                        return;
                    case 4:
                        actor->unk79_4 = new_mode;
                }
                break;
            case 1:
                switch (new_mode) {
                    case 0:
                        func_80090708(0);
                        actor->unk79_4 = new_mode;
                        break;
                    case 2:
                        func_8010D254(actor->position);
                        func_80090708(0);
                        actor->unk79_4 = new_mode;
                        return;
                    case 3:
                        func_80090708(0);
                        func_80090734(1, actor->position);
                        actor->unk79_4 = new_mode;
                        return;
                    case 4:
                        func_80090708(0);
                        actor->unk79_4 = new_mode;
                }
                break;
            case 2:
                switch (new_mode) {
                    case 0:
                        actor->unk79_4 = new_mode;
                        return;
                    case 1:
                        func_80090708(1);
                        actor->unk79_4 = new_mode;
                        break;
                    case 3:
                        func_80090734(1, actor->position);
                        actor->unk79_4 = new_mode;
                        return;
                    case 4:
                        actor->unk79_4 = new_mode;
                }
                break;
            case 3:
                switch (new_mode) {
                    case 0:
                        func_80090708(0);
                        actor->unk79_4 = new_mode;
                        return;
                    case 1:
                        func_80090708(0);
                        func_80090708(1);
                        return;
                    case 2:
                        func_8010D254(actor->position);
                        func_80090708(0);
                        actor->unk79_4 = new_mode;
                        return;
                    case 4:
                        func_80090708(0);
                        actor->unk79_4 = new_mode;
                }
                break;
            case 4:
                switch (new_mode) {
                    case 0:
                        actor->unk79_4 = new_mode;
                        return;
                    case 1:
                        func_80090708(1);
                        actor->unk79_4 = new_mode;
                        return;
                    case 2:
                        actor->unk79_4 = new_mode;
                        return;
                    case 3:
                        func_80090734(1, actor->position);
                        actor->unk79_4 = new_mode;
                }
        }
    }
}

s32 sumole_entrypoint_20(Actor *actor, s32 arg1, s32 next_state)
{
    if (func_800C6E18(arg1) != 0) {
        if (next_state != -1) {
            actor->unk70_10 = next_state;
        }
        return 1;
    }
    return 0;
}

Unk80132ED0 *func_80802178_sumole(Actor *actor)
{
    Actor *found;

    found = _subaddiefind_entrypoint_0(actor->position, 0x18F, -1, 0);
    if (found != NULL) {
        return found->unk0;
    }
    return 0;
}

void sumole_entrypoint_21(Unk80132ED0 *mole_id, s32 arg1)
{
    Actor *mole;
    Actor *hill_copy;
    Actor *hill;
    // Matching: empty block with the parameter's address needed for the match.
    if (&mole_id) {
    }

    mole = func_80106790(mole_id);
    hill = func_801084B0(0x247, &mole);
    hill_copy = hill;
    mole->unk3C = hill->unk0;
    _chmolehill_entrypoint_4(hill, mole->unk0);
    func_80108944(hill_copy, mole);
    if (arg1 != 0) {
        func_80103140(hill_copy, 0x629U, mole->unk0->unk16);
    }
}

// TU-NOTE: the overlay's .data is defined here in C (values from the ROM).
// D_808025B4_sumole is a linker symbol inside D_8080256C_sumole (+0x48).
// D_80802510_sumole and D_80802520_sumole are declared u32[] (uses written as NAME[0]).
u32 D_80802510_sumole[4] = {0x43480000, 0x43480000, 0x43480000, 0x0};
u32 D_80802520_sumole[4] = {0x42F00000, 0x42B40000, 0x42C80000, 0x42A00000};
s32 D_80802530_sumole[7] = {0x42A00000, 0x42B40000, 0x42C80000, 0x0, 0x42, 0x1E, 0x25};
s32 D_8080254C_sumole[4] = {0xD, 0x21, 0x7, 0xF};
s32 D_8080255C_sumole[4] = {0x1C9, 0x1CA, 0x1CB, 0x1CC};
s32 D_8080256C_sumole[27] = {0xD8D, 0x4, 0x42,  0xD8E, 0x4,   0x42, 0xD9C, 0x5, 0x1E,
                             0xD9D, 0x5, 0x1E,  0xD68, 0x6,   0x25, 0xD67, 0x6, 0x25,
                             0xDAB, 0x0, 0xDB1, 0x1,   0xDAD, 0x2,  0xDAF, 0x3, 0x0};
u32 D_808025D8_sumole[2] = {0x0, 0x0};
