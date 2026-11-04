// Cloud Cuckooland Canary Mary race: the player's clockwork-mouse racer and Canary Mary (dialog,
// rubber-band AI, race state machine, jiggy). Also drives the race camera via ca/pod.
#include "overlays/ch/clockworkmouse.h"

#define CLOCKWORK_DATA(arg0) ((ClockworkActorData *) (arg0->actorData))

// size of 4 might be incorrect
extern Unk80803CD8 *D_80803CD8_chclockworkmouse[4];
extern s32 D_80803CE8_chclockworkmouse[4];
extern Unk80803E08 *D_80803E08_chclockworkmouse[4];
extern s32 D_80803E18_chclockworkmouse[4];
extern s32 D_80803E28_chclockworkmouse[4];
extern ActorData *D_80803E48_chclockworkmouse;
extern ActorData *D_80803EF0_chclockworkmouse;

extern f32 D_80803E3C_chclockworkmouse[3]; // all 0s

extern void *D_80803950_chclockworkmouse; // unknown data
extern void *D_80803964_chclockworkmouse; // unknown data
extern void *D_80803978_chclockworkmouse; // unknown data
extern void *D_80803E90_chclockworkmouse; // unknown data
extern void *D_80803E9C_chclockworkmouse; // unknown data
extern void *D_80803EB0_chclockworkmouse; // unknown data
extern void *D_80803EBC_chclockworkmouse; // unknown data
extern void *D_80803ED0_chclockworkmouse; // unknown data
extern void *D_80803EE0_chclockworkmouse; // unknown data

s32 func_80800000_chclockworkmouse(void)
{
    return func_800DA564(FLAG3_A37_CANARY_MARY_RACE_STATE_1, 3);
}

void func_80800024_chclockworkmouse(s32 arg0)
{
    func_800DA7A8(FLAG3_9DA_UNK, arg0, 2);
    func_800FDC28(0);
    switch (arg0) {
        case 1:
            func_800FC660(0x17);
            return;
        case 2:
            func_800FC660(0x16);
    }
}

s32 func_80800090_chclockworkmouse(void)
{
    return func_800DA564(FLAG3_9DA_UNK, 2);
}

void func_808000B4_chclockworkmouse(Actor *actor)
{
    switch (((Unk80100094 *) func_80100094(actor, 0))->unkC.bytes[3]) {
        case 1:
            _gcgoto_entrypoint_1(0x161, 1);
            return;
        case 0:
        case 2:
            _gcgoto_entrypoint_1(0x136, 0x1F);
    }
}

u8 func_8080011C_chclockworkmouse(Actor *actor)
{
    Unk80100094 *state;

    state = (Unk80100094 *) func_80100094(actor, 0);
    state->unkC.bytes[3] = func_800DA564(FLAG3_A37_CANARY_MARY_RACE_STATE_1, 3);
    return state->unkC.bytes[3];
}

void func_80800158_chclockworkmouse(Actor *actor, s32 arg1)
{
    Unk80100094 *state;

    state = (Unk80100094 *) func_80100094(actor, 0);
    func_800DA7A8(FLAG3_A37_CANARY_MARY_RACE_STATE_1, arg1, 3);
    state->unkC.bytes[3] = arg1;
}

void func_8080019C_chclockworkmouse(Actor *actor)
{
    switch (((Unk80100094 *) func_80100094(actor, 0))->unkC.bytes[3]) {
        case 0:
            func_80800158_chclockworkmouse(actor, 1);
            func_808000B4_chclockworkmouse(actor);
            return;
        case 1:
            func_80800158_chclockworkmouse(actor, 2);
            _gcintrotext_entrypoint_0();
            func_808000B4_chclockworkmouse(actor);
            return;
        case 2:
            func_80800158_chclockworkmouse(actor, 0);
            func_80800024_chclockworkmouse(0);
    }
}

void func_80800240_chclockworkmouse(Actor *actor, s32 arg1)
{
    Vec3f *sp6C[1];
    f32 *sp68[1];
    s16 *var_s3;
    s16 *var_s4;
    SplineMemory *spline_memory;
    s32 i;
    s32 index;
    s32 pad;
    Unk80100094 *state;

    index = arg1 - 1;
    state = (Unk80100094 *) func_80100094(actor, 0);
    spline_memory = (SplineMemory *) func_80100074(
        actor, 1, _susplinet_entrypoint_18(D_80803CE8_chclockworkmouse[index], 1, 1));
    _susplinet_entrypoint_19(spline_memory, D_80803CE8_chclockworkmouse[index], 1, 1);
    for (i = 0; i < 1; i++) {
        sp6C[i] = _susplinet_entrypoint_14(spline_memory, i);
    }
    for (i = 0; i < 1; i++) {
        sp68[i] = _susplinet_entrypoint_15(spline_memory, i);
    }
    var_s3 = _susplinet_entrypoint_12(spline_memory);
    var_s4 = _susplinet_entrypoint_13(spline_memory);
    for (i = 0; i < D_80803CE8_chclockworkmouse[index];) {
        func_800EE7F8(sp6C[0]->f, D_80803CD8_chclockworkmouse[index][i].unk0);
        var_s3[0] = D_80803CD8_chclockworkmouse[index][i].unk10;
        var_s4[0] = -1;
        sp68[0][0] = D_80803CD8_chclockworkmouse[index][i].unkC;
        _susplinet_entrypoint_0(spline_memory, i, 2,
                                D_80803CD8_chclockworkmouse[index][i].unk12 & 1 ? 1 : 0);
        _susplinet_entrypoint_0(spline_memory, i, 4,
                                D_80803CD8_chclockworkmouse[index][i].unk12 & 2 ? 1 : 0);
        i++;
        var_s3++;
        var_s4++;
        sp68[0]++;
        sp6C[0]++;
    }
    for (i = 0; i < 1; i++) {
        sp6C[i] = _susplinet_entrypoint_14(spline_memory, i);
    }
    for (i = 0; i < 1; i++) {
        sp68[i] = _susplinet_entrypoint_15(spline_memory, i);
    }
    func_800F0EF0(D_80803CE8_chclockworkmouse[index], sp6C[0]->f);
    state->unkFB = arg1;
    state->unkFC = 0;
}

void func_808004B0_chclockworkmouse(Actor *actor)
{
    SplineMemory *spline_memory;
    Unk80100094 *state;
    f32 dt;
    Actor *target;
    f32 spline_pos[3];
    f32 focus[3];
    f32 cam_rot[3];
    f32 eye[3];
    f32 step;

    spline_memory = (SplineMemory *) func_80100094(actor, 1);
    state = (Unk80100094 *) func_80100094(actor, 0);
    dt = func_800D8FF8();
    target = NULL;
    if (state->unkFA == 3) {
        switch (state->unkFB) {
            case 1:
            case 3:
                target = actor;
                break;
            case 2:
            case 4:
                target = func_80106790(actor->unk3C);
        }
        _susplinet_entrypoint_11(spline_memory, _susplinet_entrypoint_9(spline_memory));
        _susplinet_entrypoint_10(spline_memory, func_80105AE8(target) * 1000.0f);
        _susplinet_entrypoint_17(spline_memory);
        _susplinet_entrypoint_7(spline_memory, 0, spline_pos);
        func_800EF5A0(focus, spline_pos, 0.0f, 0.0f, -_susplinet_entrypoint_8(spline_memory, 0));
        if (_susplinet_entrypoint_6(spline_memory) != 0) {
            state->unkFC = 0;
        }
        if (state->unkFC != 0) {
            step = 3.0f * dt;
            state->unk10C += func_800F1DCC(target->rotation[0], state->unk10C) * step;
            state->unk110 += func_800F1DCC(target->rotation[1], state->unk110) * step;
        } else {
            state->unk10C = target->rotation[0];
            state->unk110 = target->rotation[1];
            state->unkFC = 1;
        }
        func_800EF4E4(focus, state->unk10C, state->unk110, focus[0], focus[1], focus[2]);
        func_800EF4E4(eye, state->unk10C, state->unk110, 0, 75.0f, 150.0f);
        func_800EF04C(focus, target->position);
        func_800EF04C(eye, target->position);
        func_800A516C(cam_rot, eye, focus);
        _capod_entrypoint_1(focus, cam_rot);
    }
}

void func_80800700_chclockworkmouse(Unk80132ED0 **arg0, s32 arg1)
{
    _capod_entrypoint_2(*arg0, 0x1C, arg1 | 0x800);
}

void func_80800734_chclockworkmouse(Actor *actor)
{
    if (((Unk80100094 *) func_80100094(actor, 0))->unkFA == 3) {
        func_80100074(actor, 1, 0);
    }
}

void func_80800774_chclockworkmouse(Actor *actor)
{
    func_8008FB58(actor->position, 0.0f, 70.0f);
}

void func_8080079C_chclockworkmouse(Actor *actor, Actor *arg1, s32 arg2, s32 arg3)
{
    Unk80100094 *state;

    state = (Unk80100094 *) func_80100094(actor, 0);
    func_80800734_chclockworkmouse(actor);
    if (arg1 == NULL) {
        arg1 = actor;
    }
    switch (state->unkFA) {
        case 0:
            func_80800700_chclockworkmouse(&actor->unk0, 0);
        case 1:
        case 3:
        case 4:
            _capod_entrypoint_8(1);
            state->unkFA = 2;
            _gcdialogcamera_entrypoint_6(arg1->unk0);
            _gcdialogcamera_entrypoint_8();
        case 2:
            _capod_entrypoint_7(arg2, arg3);
    }
}

void func_80800850_chclockworkmouse(Actor *actor, s32 arg1, s32 arg2, Unk80132ED0 *arg3)
{
    Unk80100094 *state;

    state = (Unk80100094 *) func_80100094(actor, 0);
    func_80800734_chclockworkmouse(actor);
    switch (state->unkFA) {
        case 0:
            func_80800700_chclockworkmouse(&actor->unk0, arg2);
        case 2:
        case 3:
        case 4:
            state->unkFA = 1;
        case 1:
            _capod_entrypoint_6(arg3, arg1, arg2);
    }
}

void func_808008DC_chclockworkmouse(Actor *actor, s32 arg1, s32 arg2, Unk80132ED0 *arg3)
{
    Unk80100094 *state;

    state = (Unk80100094 *) func_80100094(actor, 0);
    func_80800734_chclockworkmouse(actor);
    switch (state->unkFA) {
        case 0:
            func_80800700_chclockworkmouse(&actor->unk0, arg2);
        case 1:
        case 2:
        case 3:
            state->unkFA = 4;
        case 4:
            _capod_entrypoint_20(arg3, arg1, arg2);
    }
}

void func_80800968_chclockworkmouse(Actor *actor, s32 arg1, s32 arg2)
{
    Unk80100094 *state;

    state = (Unk80100094 *) func_80100094(actor, 0);
    func_80800734_chclockworkmouse(actor);
    switch (state->unkFA) {
        case 0:
            func_80800700_chclockworkmouse(&actor->unk0, arg2);
        case 1:
        case 2:
        case 4:
            state->unkFA = 3;
        case 3:
            _capod_entrypoint_8(0);
            func_80800240_chclockworkmouse(actor, arg1);
    }
}

void func_808009F4_chclockworkmouse(Actor *actor)
{
    Unk80100094 *state;

    state = (Unk80100094 *) func_80100094(actor, 0);
    func_80800734_chclockworkmouse(actor);
    if (state->unkFA != 0) {
        _capod_entrypoint_3(0);
        state->unkFA = 0;
    }
}

void func_80800A44_chclockworkmouse(Actor *actor)
{
    Unk80100094 *state;
    s32 path_idx;
    s32 j;
    s32 i;

    state = (Unk80100094 *) func_80100094(actor, 0);
    path_idx = state->unkFB - 1;
    if (D_80803E08_chclockworkmouse[path_idx] == NULL) {
        return;
    }

    if (!actor->unk7C_0) {
        return;
    }

    for (i = 0, j = 0; i < D_80803E18_chclockworkmouse[path_idx];
         i++, j++) {
        if (func_80105998(actor, D_80803E08_chclockworkmouse[path_idx][j].unk0) != 0) {
            switch (D_80803E08_chclockworkmouse[path_idx][j].unkC) {
                case 1:
                    if (state->unkFE != 0) {
                        func_80800968_chclockworkmouse(actor, state->unkFB, 4);
                    }
                    break;
                case 2:
                    if (state->unkFE != 0) {
                        func_808008DC_chclockworkmouse(
                            actor, D_80803E08_chclockworkmouse[path_idx][j].unkE, 5,
                            actor->unk0);
                    }
                    break;
                case 3:
                    if (state->unkFE != 0) {
                        state->unk104 = D_80803E08_chclockworkmouse[path_idx][j].unk4;
                        state->unk108 = D_80803E08_chclockworkmouse[path_idx][j].unk8;
                        func_80800850_chclockworkmouse(
                            actor, D_80803E08_chclockworkmouse[path_idx][j].unkE, 4,
                            actor->unk0);
                    }
                    break;
            }
            state->unkFF = D_80803E08_chclockworkmouse[path_idx][j].unkC;
        }
    }
}

void func_80800C14_chclockworkmouse(Actor *actor)
{
    f32 pos[3];

    func_800904C8(0x28);
    func_800EEB9C(pos, actor->rotation[1], 120.0f);
    func_800EF04C(pos, actor->position);
    func_800903D0(pos);
}

void func_80800C64_chclockworkmouse(Actor *actor)
{
    Unk80100094 *state;

    state = (Unk80100094 *) func_80100094(actor, 0);
    if ((func_8009EA64() == 0x171) && (state->unk100 != 0)) {
        state->unk100 = 0;
        func_80800C14_chclockworkmouse(actor);
        CLOCKWORK_DATA(actor)->unkC = 0.0f;
    }
}

void func_80800CC0_chclockworkmouse(Actor *actor)
{
    if (actor->unk70_10 == 0 || actor->unk70_10 == 1 || actor->unk70_10 == 2) {
        _subaddieDll_entrypoint_4(actor, 0);
        return;
    }
    _subaddieDll_entrypoint_4(actor, 1);
}

void func_80800D14_chclockworkmouse(Actor *actor, s32 arg1)
{
    Unk80100094 *state;
    s32 i;

    state = (Unk80100094 *) func_80100094(actor, 0);
    switch (actor->unk70_10) {
        case 11:
            break;
        case 4:
            func_800F4CC0(func_800F54E4());
            break;
        case 23:
            func_80103140(actor, 0x8A0, ((u16 *) actor->unk0)[0xB]);
    }
    func_80102424(actor, arg1);
    switch (actor->unk70_10) {
        case 3:
            func_800903D0(actor->position);
            break;
        case 4:
            func_800904F4(0x27, actor->unk0);
            state->unk100 = 1;
            func_800F4CEC(func_800F54E4(), 0x3B);
            break;
        case 5:
            func_800904F4(0x27, actor->unk0);
            state->unk100 = 1;
            break;
        case 6:
            state->unkDC = 0.15f;
            for (i = 0; i < 10; i++) {
                state->unkF0[i] = 1;
            }
            break;
        case 7:
            func_80800C64_chclockworkmouse(actor);
            // fallthrough

        case 15:
            break;
    }
    func_80800CC0_chclockworkmouse(actor);
}

void func_80800E8C_chclockworkmouse(Actor *actor, s32 arg1)
{
    Actor *other;

    other = func_80106790(actor->unk3C);
    func_80800D14_chclockworkmouse(actor, arg1);
    func_808022E4_chclockworkmouse(other, arg1);
}

void func_80800ED0_chclockworkmouse(Actor *actor)
{
    if (func_8009EA64() == 0x171) {
        func_800907C0(actor->position);
        func_800906DC(actor->rotation);
    }
}

f32 func_80800F10_chclockworkmouse(f32 *arg0, f32 arg1)
{
    f32 dt;
    s32 pressed;

    dt = func_800D8FF8();
    pressed = func_80016B30(0, 0);
    if (*arg0 < 0.0f) {
        if (pressed != 0) {
            arg1 += func_800F10B4(*arg0, -1.0f, -0.01f, 0.0f, 3.0f);
            *arg0 = 0.01f;
            return arg1;
        }
        *arg0 -= dt;
        arg1 *= 0.98f;
    } else {
        if (pressed == 0) {
            arg1 += func_800F10B4(*arg0, 1.0f, 0.01f, 0.0f, 3.0f);
            *arg0 = -0.01f;
            return arg1;
        }
        *arg0 += dt;
        arg1 *= 0.98f;
    }

    if (arg1 > 200.0f) {
        arg1 = 200.0f;
    }

    return arg1;
}

void func_80801044_chclockworkmouse(Actor *actor)
{
    f32 temp_f12;

    if (CLOCKWORK_DATA(actor)->unkC > 10.0f) {
        temp_f12 =
            func_800F10B4(1.0f - (CLOCKWORK_DATA(actor)->unkC / 200.0f), 0.0f, 1, 0.5f, 3.0f);
        if (actor->unk5F == 0) {
            actor->unk5F =
                func_800C4350(actor->unk5F, actor->position, (s32 *) D_80803E28_chclockworkmouse);
            return;
        }
        func_800C31DC(actor->unk5F, func_800F10B4(temp_f12, 0.5f, 3.0f, 1.2f, 0.8f));
        func_800C4350(actor->unk5F, actor->position, NULL);
    }
}

void func_8080111C_chclockworkmouse(Actor *actor)
{
    Unk80100094 *state;
    f32 blend;

    blend = 0.1f;
    state = (Unk80100094 *) func_80100094(actor, 0);
    func_80105A9C(actor, CLOCKWORK_DATA(actor)->unkC * 10.0f);
    func_80105834(actor);
    state->unkD8 =
        (((func_800F1DCC(actor->rotation[1], state->unkD4) * 10.0f) - state->unkD8) * 0.02f);
    actor->rotation[2] =
        func_800F10B4(CLOCKWORK_DATA(actor)->unkC, 0.0f, 500.0f, 0.0f, state->unkD8);
    state->unkD4 = actor->rotation[1];
    if (state->unkFD == 0) {
        blend = 1.0f;
        state->unkFD = 1;
    }
    actor->rotation[0] += func_800F1DCC(actor->unk50, actor->rotation[0]) * blend;
    actor->rotation[1] += func_800F1DCC(actor->unk54, actor->rotation[1]) * blend;
    func_80801044_chclockworkmouse(actor);
}

void func_80801240_chclockworkmouse(Actor *actor)
{
    Unk80100094 *state;
    f32 temp_f0;
    f32 progress;
    f32 dt;
    Unk800C7A68 *temp_s5;
    s32 i;

    progress = func_80105AE8(actor);
    state = (Unk80100094 *) func_80100094(actor, 0);
    temp_s5 = (Unk800C7A68 *) func_800D7520(state->unk0.shorts.unk0);
    dt = func_800D8FF8();
    for (i = 0; i < 10; i++) {
        if (state->unkF0[i] == 1) {
            temp_f0 = func_800C7B7C(temp_s5, state->unkEC, 250.0f, 1.0f);
            state->unkEC = temp_f0;
            state->unk84[i] = temp_f0;
            func_800C7A68(temp_s5, state->unkEC, (s32) &state->unkC.vecs[i]);
            state->unkF0[i] = 2U;
            state->unkAC[i] = state->unkDC;
            state->unkDC += 0.0075000003f;
            if (state->unkDC > 0.3f) {
                state->unkDC = 0.15f;
            }
            state->unkE0[i] = 0;
        }
    }
    for (i = 0; i < 10; i++) {
        if (state->unkF0[i] == 2) {
            temp_f0 = 1.5f * dt;
            if (state->unkE0[i] != 0) {
                state->unkAC[i] -= temp_f0;
                if (state->unkAC[i] <= 0.15f) {
                    state->unkE0[i] = 0U;
                }
            } else {
                state->unkAC[i] += temp_f0;
                if (state->unkAC[i] >= 0.3f) {
                    state->unkE0[i] = 1U;
                }
            }
            if (state->unk84[i] <= progress) {
                if (progress >= 1.0f) {
                    state->unkF0[i] = 0U;
                } else {
                    state->unkF0[i] = 1U;
                }
            }
        }
    }
}

void func_80801508_chclockworkmouse(Actor *actor)
{
    CLOCKWORK_DATA(actor)->unkC *= 0.95f;
    actor->rotation[0] += func_800F1DCC(0.0f, actor->rotation[0]) * 0.05f;
    actor->rotation[2] += func_800F1DCC(0.0f, actor->rotation[2]) * 0.05f;
}

void func_80801588_chclockworkmouse(Actor *actor)
{
    Actor *other;
    f32 dt;
    Unk80100094 *state;

    if (actor->unk3C == 0) {
        func_80800774_chclockworkmouse(actor);
        return;
    }
    dt = func_800D8FF8();
    other = func_80106790(actor->unk3C);
    state = (Unk80100094 *) func_80100094(actor, 0);
    state->unk8 += 5.0f * CLOCKWORK_DATA(actor)->unkC * dt;
    switch (actor->unk70_10) {
        case 2:
        case 17:
            func_80800774_chclockworkmouse(actor);
            if ((func_80090178(ALLOW_BK) != 0) && (func_8010C9B0(actor->position, 0x96) != 0)) {
                func_80800E8C_chclockworkmouse(actor, 3);
            }
            break;
        case 3:
            if (func_8010CB0C(actor->position, 0x32, 0x32, 0) != 0) {
                func_800DA544(FLAG_42B_UNK);
                func_80800E8C_chclockworkmouse(actor, 4);
            }
            break;
        case 4: {
            f32 rot[3] = D_80803E3C_chclockworkmouse;
            f32 diff;
            func_800907C0(actor->position);
            rot[1] = func_80090010();
            diff = func_800F1DCC(actor->rotation[1], rot[1]);
            if ((diff < -35.0f) || (diff > 35.0f)) {
                rot[1] += diff * dt * 5.0f;
                func_800906DC(rot);
            } else {
                func_8080019C_chclockworkmouse(other);
            }
        } break;
        case 5:
            func_80800ED0_chclockworkmouse(actor);
            break;
        case 6:
            CLOCKWORK_DATA(actor)->unkC =
                func_80800F10_chclockworkmouse(&state->unk4, CLOCKWORK_DATA(actor)->unkC);
            func_8080111C_chclockworkmouse(actor);
            func_80800ED0_chclockworkmouse(actor);
            func_80801240_chclockworkmouse(actor);
            if (func_80105A5C(actor) != 0) {
                func_80800E8C_chclockworkmouse(actor, 7);
            }
            break;
        case 9:
        case 10:
        case 11:
            CLOCKWORK_DATA(actor)->unkC =
                func_80800F10_chclockworkmouse(&state->unk4, CLOCKWORK_DATA(actor)->unkC);
            func_8080111C_chclockworkmouse(actor);
            func_80800ED0_chclockworkmouse(actor);
            func_80801240_chclockworkmouse(actor);
            break;
        case 7:
        case 8:
        case 12:
        case 13:
            func_80801508_chclockworkmouse(actor);
            break;
        case 14:
        case 15:
            func_80800774_chclockworkmouse(actor);
            func_80801508_chclockworkmouse(actor);
    }
    if ((state->unkFB == 1) || (state->unkFB == 3)) {
        func_80800A44_chclockworkmouse(actor);
        func_808004B0_chclockworkmouse(actor);
    }
}

void func_80801848_chclockworkmouse(s32 actor)
{
}

void func_80801850_chclockworkmouse(Actor *actor)
{
    Actor *spawned;
    s32 pad;
    f32 sp1C[3];

    _gspropctrl_entrypoint_11(_gccubesearch_entrypoint_1(0x226, actor->position), sp1C);
    spawned = func_80108528(0x383, sp1C, 0, &actor);
    actor->unk3C = spawned->unk0;
    spawned->unk3C = actor->unk0;
    func_80100120(spawned);
}

void func_808018BC_chclockworkmouse(Actor *actor)
{
    Unk80100094 *state;
    Prop *prop;

    state = (Unk80100094 *) func_80100094(actor, 0);
    actor->unk64_19 = func_800D0A9C(0x4A, 1);
    state->unkFA = 0;
    state->unk4 = 0.0f;
    if ((func_800D0A9C(4, 4) == 0) || (func_800D0A9C(0x16, 4) != 0)) {
        func_80103140(actor, 0x8A1, ((u16 **) actor)[0][0xB]);
        return;
    }
    switch (func_80800000_chclockworkmouse()) {
        case 0:
            if (func_800DA298(FLAG_504_PROGRESS_CANARY_MARY_IN_CCL) == 0) {
                func_80103140(actor, 0x8A1, ((u16 **) actor)[0][0xB]);
            }
            break;
        case 1:
            if (actor->unk64_19) {
                state->unk0.shorts.unk0 = _glsplinefind_entrypoint_0(0x314, actor->position);
            } else {
                state->unk0.shorts.unk0 = _glsplinefind_entrypoint_0(0x313, actor->position);
            }
            func_801058C4(actor, (s16) state->unk0.shorts.unk0, CLOCKWORK_DATA(actor)->unkC, 0);
            func_8080111C_chclockworkmouse(actor);
            break;
        case 2:
            if (actor->unk64_19) {
                prop = _gccubesearch_entrypoint_0(0x201, actor);
            } else {
                prop = _gccubesearch_entrypoint_0(0x1F6, actor);
            }
            func_800EE88C(&state->unk114, prop->position);
            if (actor->unk64_19 && (func_80800090_chclockworkmouse() == 2)) {
                func_80103140(actor, 0x8A1, ((u16 **) actor)[0][0xB]);
            }
    }
    func_80108B04(actor, 0);
}

void func_80801A94_chclockworkmouse(Actor *actor)
{
    Unk80100094 *state;
    s32 sp38;
    f32 sp2C[3];
    f32 sp1C[4];

    state = (Unk80100094 *) func_80100094(actor, 0);
    sp38 = func_801040D0();
    func_801015D0(actor);
    func_800DF41C(sp38);
    func_800EFA4C(sp2C, -70.0f, 0.0f, 0.0f);
    func_800D93A0(sp1C, sp2C);
    func_800DFF2C(sp38, 0x5C, sp1C);
    func_800EFA4C(sp2C, 0.0f, state->unk8, 0.0f);
    func_800D93A0(sp1C, sp2C);
    func_800DFF2C(sp38, 0x5D, sp1C);
}

void func_80801B44_chclockworkmouse(Actor *actor, s32 arg1, s32 arg2)
{
    arg2 |= 4;
    _subaddiedialog_entrypoint_11(actor->unk0, arg1, arg2, actor->position, 0x36);
    actor->unk74_30 = 1;
}

void func_80801B90_chclockworkmouse(Actor *actor, s32 arg1)
{
    f32 pos[3];

    func_800EE7F8(pos, actor->position);
    pos[1] += 75.0f;
    if ((arg1 == 0x47) || (arg1 == 0x4B)) {
        _capod_entrypoint_19(pos);
    }
}

s32 func_80801BF0_chclockworkmouse(Actor *actor, s32 arg1, s32 arg2)
{
    Actor *other;
    s32 text_id;

    switch (arg1) {
        case 0x1F:
            func_80801A94_chclockworkmouse(actor);
            break;
        case 0xE:
            func_80801B90_chclockworkmouse(func_80106790(actor->unk3C), arg2);
            return 3;
        case 0xB:
            other = func_80106790(actor->unk3C);
            text_id = 0;
            switch (arg2) {
                case 23:
                    text_id = 0x142B;
                    break;
                case 25:
                    text_id = 0x142F;
            }
            if (text_id != 0) {
                func_8080079C_chclockworkmouse(actor, other, 2, 1);
                func_80801B44_chclockworkmouse(other, text_id, 0xB);
            }
            return 4;
        case 0x3D:
            func_80801850_chclockworkmouse(actor);
            break;
        default:
            return 0;
    }
    return 1;
}

void func_80801CFC_chclockworkmouse(Actor *actor, s32 arg1)
{
    Unk80100094 *state;
    f32 scale[3];
    ImageStruct *image;
    s32 i;

    func_801018A4();
    if (actor->unk7C_12) {
        image = func_800D674C(0x9E2);
        state = (Unk80100094 *) func_80100094(actor, 0);
        func_800E2588(2);
        func_800E2594(arg1, image);
        for (i = 0; i < 10; i++) {
            if (state->unkF0[i] == 2) {
                func_800EFA4C(scale, state->unkAC[i], state->unkAC[i],
                              state->unkAC[i]);
                func_800E2720(arg1, 0, 0, &state->unkC.vecs[i], scale, 0xFF);
            }
        }
        func_800E2A14(arg1);
    }
}

ActorData **chclockworkmouse_entrypoint_0(void)
{
    return &D_80803E48_chclockworkmouse;
}

void func_80801E2C_chclockworkmouse(Actor *actor)
{
    Unk80100094 *state;
    s32 pad;

    state = (Unk80100094 *) func_80100094(actor, 0);
    state->unk0.f = (f32) (state->unk0.f - func_800D8FF8());
    switch (func_801022E4(actor)) {
        case 0x7D:
            _subaddieaudioquick_entrypoint_3(actor, actor->position,
                                             (u32 *) &D_80803964_chclockworkmouse, 0.1f);
            if ((state->unk0.f <= 0.0f) && (func_800DC298(0.03f) != 0) && (func_800C0638() == 0)) {
                _subaddieaudioquick_entrypoint_2(actor, actor->position,
                                                 &D_80803950_chclockworkmouse);
                state->unk0.f = 1.5f;
            }
            return;
        case 0x89:
            _subaddieaudioquick_entrypoint_4(actor, actor->position,
                                             (u32 *) &D_80803964_chclockworkmouse,
                                             (u32 *) &D_80803E90_chclockworkmouse);
            return;
        case 0x8A:
            _subaddieaudioquick_entrypoint_4(actor, actor->position,
                                             (u32 *) &D_80803964_chclockworkmouse,
                                             (u32 *) &D_80803E9C_chclockworkmouse);
            return;
        case 0x85:
            _subaddieaudioquick_entrypoint_4(actor, actor->position,
                                             (u32 *) &D_80803978_chclockworkmouse,
                                             (u32 *) &D_80803EB0_chclockworkmouse);
            return;
        case 0x80:
            _subaddieaudioquick_entrypoint_4(actor, actor->position,
                                             (u32 *) &D_80803964_chclockworkmouse,
                                             (u32 *) &D_80803EBC_chclockworkmouse);
            _subaddieaudioquick_entrypoint_3(actor, actor->position,
                                             (u32 *) &D_80803978_chclockworkmouse, 0.9f);
    }
}

void func_80801FC8_chclockworkmouse(Actor *actor)
{
    s32 pad[2];
    f32 sp2C;
    Unk80100094 *state;

    state = (Unk80100094 *) func_80100094(actor, 0);
    actor->unk64_19 = func_800D0A9C(0x4A, 1);
    switch (func_8080011C_chclockworkmouse(actor)) {
        case 0:
            break;
        case 1:
            if (actor->unk64_19) {
                state->unkC.shorts[0] = _glsplinefind_entrypoint_0(0x385, &sp2C);
            } else {
                state->unkC.shorts[0] = _glsplinefind_entrypoint_0(0x384, &sp2C);
            }
            func_80800024_chclockworkmouse(0);
            func_808026E0_chclockworkmouse(actor, 5);
            break;
        case 2:
            func_808026E0_chclockworkmouse(actor, 0xF);
            if (actor->unk64_19) {
                state->unkC.shorts[0] = _glsplinefind_entrypoint_0(0x389, &sp2C);
            }
            func_8080019C_chclockworkmouse(actor);
    }
    if ((func_800D0A9C(4, 4) != 0) && (func_800DA298(FLAG_504_PROGRESS_CANARY_MARY_IN_CCL) == 0)) {
        state->unkC.shorts[0] = _glsplinefind_entrypoint_0(0x388, actor->position);
        func_801058C4(actor, (s16) state->unkC.shorts[0], CLOCKWORK_DATA(actor)->unkC, 0);
        if (_glcutDll_entrypoint_19(0x55) != 0) {
            func_808026E0_chclockworkmouse(actor, 0x14);
        } else {
            func_808026E0_chclockworkmouse(actor, 0x13);
        }
    }
    _suexpression_entrypoint_7(actor, 1, 0x36);
    _suexpression_entrypoint_12(func_80100094(actor, 1), 45.0f, 15.0f);
}

void func_80802170_chclockworkmouse(Actor *actor)
{
    if (actor->unk70_10 == 0x10) {
        func_800904C8(0x28);
    }
    if (func_80100094(actor, 1) != NULL) {
        _suexpression_entrypoint_8(actor, 1);
    }
}

void func_808021C4_chclockworkmouse(Actor *actor)
{
    Unk80100094 *state;
    f32 blend;
    f32 roll;

    blend = 0.1f;
    state = (Unk80100094 *) func_80100094(actor, 0);
    func_80105A9C(actor, CLOCKWORK_DATA(actor)->unkC * 10.0f);
    func_80105834(actor);
    roll = (CLOCKWORK_DATA(actor)->unkC * func_800F1DCC(actor->rotation[1], state->unk4) * 0.5f);
    state->unk8 = (roll - state->unk8) * 0.02f;
    actor->rotation[2] = state->unk8;
    state->unk4 = actor->rotation[1];
    if (state->unkC.bytes[2] == 0) {
        blend = 1.0f;
        state->unkC.bytes[2] = 1;
    }
    actor->rotation[0] += func_800F1DCC(actor->unk50 * 0.1f, actor->rotation[0]) * blend;
    actor->rotation[1] += func_800F1DCC(actor->unk54, actor->rotation[1]) * blend;
}

void func_808022E4_chclockworkmouse(Actor *actor, s32 arg1)
{
    Actor *mary;
    Unk80100094 *mary_data;
    s32 text_id;
    s32 result_text_id;
    s32 race_result;

    mary = func_80106790(actor->unk3C);
    mary_data = (Unk80100094 *) func_80100094(actor, 0);
    switch (actor->unk70_10) {
        case 19:
            actor->unk64_16 = 1;
            break;
        case 23:
            func_808009F4_chclockworkmouse(mary);
            break;
        case 15:
            func_80090708(0);
    }
    func_80102424(actor, arg1);
    switch (actor->unk70_10) {
        case 19:
            actor->unk64_16 = 0;
            break;
        case 20:
            func_800DA544(FLAG_504_PROGRESS_CANARY_MARY_IN_CCL);
            CLOCKWORK_DATA(actor)->unkC = 40.0f;
            func_80800850_chclockworkmouse(mary, 0x47, 0x20B0, actor->unk0);
            break;
        case 23:
            actor->unk58 = 1.0f;
            break;
        case 5:
            func_808008DC_chclockworkmouse(mary, 4, 5, mary->unk0);
            func_80801B44_chclockworkmouse(actor, 0xCEC, 3);
            func_801058C4(actor, mary_data->unkC.shorts[0], CLOCKWORK_DATA(actor)->unkC, 0);
            break;
        case 6:
            func_800FDC28(0x13);
            if (actor->unk64_19) {
                CLOCKWORK_DATA(actor)->unkC = 55.0f;
            } else {
                CLOCKWORK_DATA(actor)->unkC = 35.0f;
            }
            break;
        case 7:
            func_80800024_chclockworkmouse(2);
            func_80090658(1);
            break;
        case 8:
            if (func_80105AE8(actor) < 0.93f) {
                func_80800968_chclockworkmouse(mary, actor->unk64_19 ? 4 : 2, 4);
            } else {
                func_808008DC_chclockworkmouse(mary, 5, 5, actor->unk0);
            }
            break;
        case 9:
            func_80800024_chclockworkmouse(1);
            break;
        case 10:
            if (func_80105AE8(mary) < 0.93f) {
                func_80800968_chclockworkmouse(mary, actor->unk64_19 ? 3 : 1, 4);
            } else {
                func_808008DC_chclockworkmouse(mary, 5, 5, mary->unk0);
            }
            break;
        case 14:
            actor->unk58 = 0.5f;
            break;
        case 16:
            if (func_800D0A9C(0x4A, 1) != 0) {
                text_id = 0x142D;
            } else {
                text_id = 0x1429;
            }
            func_8080079C_chclockworkmouse(mary, actor, 3, 1);
            func_80801B44_chclockworkmouse(actor, text_id, 3);
            func_800FDC28(0);
            func_800FC660(0x17);
            break;
        case 15:
            result_text_id = 0;
            func_80090658(0);
            func_80090734(1, actor->position);
            func_8080079C_chclockworkmouse(mary, actor, 2, 1);
            race_result = func_80800090_chclockworkmouse();
            switch (race_result) {
                case 1:
                    if (func_800D0A9C(0x4A, 1) != 0) {
                        result_text_id = 0x142C;
                    } else {
                        result_text_id = 0x1428;
                    }
                    break;
                case 2:
                    if (func_800D0A9C(0x4A, 1) != 0) {
                        result_text_id = 0x142E;
                    } else {
                        result_text_id = 0x142A;
                    }
            }
            func_80801B44_chclockworkmouse(actor, result_text_id, 0xB);
            break;
        case 18:
            CLOCKWORK_DATA(actor)->unkC = 40.0f;
            func_801058C4(actor, (s16) mary_data->unkC.shorts[0], 40.0f, 0);
            func_808021C4_chclockworkmouse(actor);
            func_80800850_chclockworkmouse(mary, 0x4B, 0x20B0, actor->unk0);
    }
    func_80800CC0_chclockworkmouse(actor);
}

void func_808026E0_chclockworkmouse(Actor *actor, s32 arg1)
{
    Actor *mary;

    mary = func_80106790(actor->unk3C);
    func_808022E4_chclockworkmouse(actor, arg1);
    func_80800D14_chclockworkmouse(mary, arg1);
}

// Rubber band: adjusts Canary Mary's speed to the path progress of the player.
void func_80802724_chclockworkmouse(Actor *actor, Actor *mary)
{
    f32 mary_progress;
    f32 progress;
    f32 dt;
    f32 threshold;
    u32 rematch;

    if (mary->unk7C_0) {
        mary_progress = func_80105AE8(mary);
    } else {
        mary_progress = 1.0f;
    }
    progress = func_80105AE8(actor);
    dt = func_800D8FF8();
    rematch = actor->unk64_19;
    if (mary_progress <= (progress - 0.099990845f)) {
        func_808026E0_chclockworkmouse(actor, 0x10);
        return;
    }
    if (rematch != 0) {
        threshold = 0.004989624f;
    } else {
        threshold = 0.009994507f;
    }
    if (mary_progress <= (progress - threshold)) {
        if (rematch != 0) {
            progress = 185.0f;
        } else {
            progress = 165.0f;
        }
        if (rematch != 0) {
            threshold = 15.0f;
        } else {
            threshold = 25.0f;
        }
        if ((progress - threshold) < CLOCKWORK_DATA(actor)->unkC) {
            if (rematch != 0) {
                threshold = 65.0f;
            } else {
                threshold = 45.0f;
            }
            CLOCKWORK_DATA(actor)->unkC -= (threshold * dt);
        }
        return;
    }

    if (rematch != 0) {
        threshold = 0.004989624f;
    } else {
        threshold = 0.019989014f;
    }
    if ((threshold + progress) <= mary_progress) {
        if (rematch != 0) {
            progress = 185.0f;
        } else {
            progress = 165.0f;
        }
        if (CLOCKWORK_DATA(actor)->unkC < (15.0f + progress)) {
            if (rematch != 0) {
                threshold = 65.0f;
            } else {
                threshold = 45.0f;
            }
            CLOCKWORK_DATA(actor)->unkC += (threshold * dt);
        }
    } else {
        if (rematch != 0) {
            threshold = 185.0f;
        } else {
            threshold = 165.0f;
        }
        if (CLOCKWORK_DATA(actor)->unkC < threshold) {
            if (rematch != 0) {
                threshold = 65.0f;
            } else {
                threshold = 45.0f;
            }
            CLOCKWORK_DATA(actor)->unkC += (threshold * dt);
        }
    }
}

s32 func_8080297C_chclockworkmouse(Actor *actor)
{
    s32 pad;
    f32 ray_start[3];
    f32 ray_end[3];
    f32 ray_hit[3];
    f32 dt;

    dt = func_800D8FF8();
    func_800EE7F8(ray_start, actor->position);
    ray_start[1] += 50.0f;
    func_800EE7F8(ray_end, actor->position);
    ray_end[1] -= 50.0f;
    if (func_800BEF00(ray_start, ray_end, ray_hit, 0x20020) == 0 || ray_end[1] < actor->position[1]) {
        actor->position[1] -= 250.0f * dt;
        return 0;
    }
    return 1;
}

void func_80802A48_chclockworkmouse(Actor *actor)
{
    f32 angle_diff;
    f32 anim_progress;

    actor->unk54 = func_8010CD28(actor);
    angle_diff = func_800F1DCC(actor->rotation[1], actor->unk54);
    if ((angle_diff < -10.0f) || (angle_diff > 10.0f)) {
        anim_progress = func_80101F24(actor);
        switch (func_801022E4(actor)) {
            case 0x80:
                if ((anim_progress > 0.75f) && (anim_progress < 0.88f)) {
                    func_80102B2C(actor, 6.0f);
                }
                break;
            case 0x85:
                if (((anim_progress > 0.76f) && (anim_progress < 0.99f)) || ((anim_progress > 0.25f) && (anim_progress < 0.51f))) {
                    actor->rotation[1] += angle_diff > 0.0f ? -6.0f : 6.0f;
                }
        }
    }
}

void func_80802BCC_chclockworkmouse(Actor *actor)
{
    _sudeflect_entrypoint_1(actor->position, 180.0f, 0.0f, 65.0f, 0x1E);
}

void func_80802C04_chclockworkmouse(Actor *actor, Actor *actor2)
{
    Unk80100094 *mary_data;

    mary_data = (Unk80100094 *) func_80100094(actor2, 0);
    if (func_80105998(actor2, 0.94f) != 0) {
        mary_data->unkFE = 0;
        func_808008DC_chclockworkmouse(actor2, 5, 5, actor2->unk0);
    }
}

void func_80802C64_chclockworkmouse(Actor *actor, Actor *actor2)
{
    Unk80100094 *mary_data;

    mary_data = (Unk80100094 *) func_80100094(actor2, 0);
    if (func_80105998(actor, 0.94f) != 0) {
        mary_data->unkFE = 0;
        func_808008DC_chclockworkmouse(actor2, 5, 5, actor->unk0);
    }
}

void func_80802CC8_chclockworkmouse(Actor *actor)
{
    Actor *mary;
    Unk80100094 *mary_data;
    f32 dt;

    mary = func_80106790(actor->unk3C);
    mary_data = (Unk80100094 *) func_80100094(mary, 0);
    dt = func_800D8FF8();
    _suexpression_entrypoint_10(func_80100094(actor, 1), actor->unk0, 0);
    switch (actor->unk70_10) {
        case 20:
            func_808021C4_chclockworkmouse(actor);
            if (func_80105A5C(actor) != 0) {
                func_80105634(actor);
                func_808026E0_chclockworkmouse(actor, 0x15);
            }
            break;
        case 21:
            if ((func_8080297C_chclockworkmouse(actor) != 0) && (func_80101E14(actor, 0.999f) != 0)) {
                func_808026E0_chclockworkmouse(actor, 0x16);
            }
            break;
        case 22:
            if (func_80101DDC(actor) != 0) {
                func_808026E0_chclockworkmouse(actor, 0x17);
            }
            break;
        case 23:
            if (actor->unk58 > 0.0f) {
                actor->unk58 -= dt;
            } else if (_glcutDll_entrypoint_19(0x55) != 0) {
                _glcutDll_entrypoint_17();
            } else {
                func_808026E0_chclockworkmouse(actor, 0x11);
            }
            break;
        case 17:
            func_80802BCC_chclockworkmouse(actor);
            func_80802A48_chclockworkmouse(actor);
            if (func_800DA298(FLAG_42B_UNK) != 0) {
                func_808026E0_chclockworkmouse(actor, 2);
            } else if (!actor->unk74_30 && (func_80090178(ALLOW_BK) != 0) &&
                       (_subaddiedialog_entrypoint_3(actor->position, actor->rotation[1], 0xC8, 0x46,
                                                     6) != 0)) {
                func_800DA544(FLAG_42B_UNK);
                func_8080079C_chclockworkmouse(mary, actor, 2, 0);
                func_80801B44_chclockworkmouse(actor, 0x1426, 0xB);
            }
            break;
        case 2:
            func_80802BCC_chclockworkmouse(actor);
            func_80802A48_chclockworkmouse(actor);
            if (!actor->unk74_30 && (func_80090178(ALLOW_BK) != 0) &&
                (_subaddiedialog_entrypoint_6(actor->position, actor->rotation[1], 0xC8, 0x46, 6) !=
                 0)) {
                func_80801B44_chclockworkmouse(actor, actor->unk64_19 ? 0x1436 : 0x1427, 0xB);
            }
            break;
        case 5:
            func_80802A48_chclockworkmouse(actor);
            func_80802BCC_chclockworkmouse(actor);
            func_808021C4_chclockworkmouse(actor);
            break;
        case 6:
            func_80802724_chclockworkmouse(actor, mary);
            func_808021C4_chclockworkmouse(actor);
            if (func_80105998(mary, 0.05f) != 0) {
                mary_data->unkFE = 1;
                func_80800968_chclockworkmouse(mary, mary->unk64_19 ? 3 : 1, 4);
            }
            func_80802C04_chclockworkmouse(actor, mary);
            if (func_80105A5C(actor) != 0) {
                func_808026E0_chclockworkmouse(actor, 9);
            }
            break;
        case 7:
            func_80802724_chclockworkmouse(actor, mary);
            func_808021C4_chclockworkmouse(actor);
            func_80802C64_chclockworkmouse(actor, mary);
            if (func_80090248() != 0) {
                func_808026E0_chclockworkmouse(actor, 8);
            }
            if (func_80105A5C(actor) != 0) {
                func_808026E0_chclockworkmouse(actor, 0xC);
            }
            break;
        case 8:
            func_80802724_chclockworkmouse(actor, mary);
            func_808021C4_chclockworkmouse(actor);
            func_80802C64_chclockworkmouse(actor, mary);
            if (func_80105A5C(actor) != 0) {
                func_808026E0_chclockworkmouse(actor, 0xC);
            }
            break;
        case 9:
            func_80802C04_chclockworkmouse(actor, mary);
            if (func_80105A5C(mary) != 0) {
                func_80800C64_chclockworkmouse(mary);
            }
            if ((func_8080297C_chclockworkmouse(actor) != 0) && (func_80101E14(actor, 0.999f) != 0)) {
                func_808026E0_chclockworkmouse(actor, 0xA);
            }
            break;
        case 10:
            func_80802C04_chclockworkmouse(actor, mary);
            func_80802BCC_chclockworkmouse(actor);
            if (func_80105A5C(mary) != 0) {
                func_80800C64_chclockworkmouse(mary);
            }
            if (func_80101DDC(actor) != 0) {
                func_808026E0_chclockworkmouse(actor, 0xB);
            }
            break;
        case 11:
            func_80802C04_chclockworkmouse(actor, mary);
            func_80802BCC_chclockworkmouse(actor);
            func_80802A48_chclockworkmouse(actor);
            if (func_80105A5C(mary) != 0) {
                func_80800C64_chclockworkmouse(mary);
                func_808026E0_chclockworkmouse(actor, 0xE);
            }
            break;
        case 12:
            if ((func_8080297C_chclockworkmouse(actor) != 0) && (func_80101E14(actor, 0.999f) != 0)) {
                func_808026E0_chclockworkmouse(actor, 0xD);
            }
            break;
        case 13:
            func_80802BCC_chclockworkmouse(actor);
            if (func_80101DDC(actor) != 0) {
                func_808026E0_chclockworkmouse(actor, 0xE);
            }
            break;
        case 14:
            if (actor->unk58 > 0.0f) {
                actor->unk58 -= dt;
            } else {
                func_8080019C_chclockworkmouse(actor);
            }
            break;
        case 15:
            func_80802A48_chclockworkmouse(actor);
            func_80802BCC_chclockworkmouse(actor);
            break;
        case 18:
            if (CLOCKWORK_DATA(actor)->unkC < 150.0f) {
                CLOCKWORK_DATA(actor)->unkC += 50.0f * dt;
            }
            func_808021C4_chclockworkmouse(actor);
            if (func_80105A5C(actor) != 0) {
                func_80105634(actor);
                func_808009F4_chclockworkmouse(mary);
                mary->unk3C = 0;
                func_800FFAB0(actor);
            }
    }
    func_80801E2C_chclockworkmouse(actor);
    switch (mary_data->unkFB) {
        case 2:
        case 4:
            func_80800A44_chclockworkmouse(mary);
            func_808004B0_chclockworkmouse(mary);
    }
}

s32 func_808032F8_chclockworkmouse(Actor *actor, s32 arg1, s32 arg2)
{
    s16 *arg2_lo;
    s32 pad;
    Actor *mary;
    Actor *mary2;
    Unk80100094 *mary_data;

    arg2_lo = (s16 *) &arg2;
    switch (arg1) {
        case 14:
            func_80801B90_chclockworkmouse(actor, arg2);
            return 3;
        case 47:
            mary_data = (Unk80100094 *) func_80100094(func_80106790(actor->unk3C), 0);
            switch (*arg2_lo) {
                case 0x142A:
                    func_800D1000(0x4A, 1, &mary_data->unk114, 1, actor->unk0);
                    break;
                case 0x142E:
                    func_800D1000(0x16, 4, &mary_data->unk114, 1, actor->unk0);
            }
            break;
        case 13:
            mary = func_80106790(actor->unk3C);
            switch (*(s32 *) arg2_lo & 0xFFFF) {
                case 1:
                    func_80800850_chclockworkmouse(mary, 0x17, 0x2000, func_80101080());
                    break;
                case 4:
                    func_80800850_chclockworkmouse(mary, 0x19, 0x2000, func_80101080());
            }
            break;
        case 46:
            mary2 = func_80106790(actor->unk3C);
            switch (*arg2_lo) {
                case 0x1426:
                    func_808009F4_chclockworkmouse(mary2);
                    func_808026E0_chclockworkmouse(actor, 2);
                    break;
                case 0xCEC:
                    func_808026E0_chclockworkmouse(actor, 6);
                    break;
                case 0x1429:
                case 0x142D:
                    func_80800158_chclockworkmouse(actor, 0);
                    func_808000B4_chclockworkmouse(actor);
                    func_800904C8(0x28);
                    break;
                case 0x1428:
                    func_808009F4_chclockworkmouse(mary2);
                    func_808026E0_chclockworkmouse(actor, 2);
                    break;
                case 0x142C:
                    func_808009F4_chclockworkmouse(mary2);
                    func_808026E0_chclockworkmouse(actor, 2);
                    break;
                case 0x142B:
                    func_808009F4_chclockworkmouse(mary2);
                    func_808026E0_chclockworkmouse(actor, 2);
                    actor->unk64_19 = 1;
                    mary2->unk64_19 = 1;
                    break;
                case 0x142F:
                    func_808009F4_chclockworkmouse(mary2);
                    func_808026E0_chclockworkmouse(actor, 0x12);
            }
            actor->unk74_30 = 0;
            break;
        case 0x52:

            if (func_801022E4(actor) == 0x7D) {
                _gcdialogcamera_entrypoint_3((u32 *) &D_80803ED0_chclockworkmouse, actor->scale);
            } else {
                _gcdialogcamera_entrypoint_3((u32 *) &D_80803EE0_chclockworkmouse, actor->scale);
            }
            return 1;
        case 11:
            if ((arg2 == 0x1F) && (actor->unk70_10 == 0x13)) {
                _capod_entrypoint_14();
                func_808026E0_chclockworkmouse(actor, 0x14);
                return 4;
            }
            return 3;
        case 31:
            func_801015D0(actor);
            func_800DF744(3, 0);
            break;
        default:
            return 0;
    }
    return 1;
}

void func_8080364C_chclockworkmouse(void)
{
    func_801018A4();
}

ActorData **chclockworkmouse_entrypoint_1(void)
{
    return &D_80803EF0_chclockworkmouse;
}

extern void func_80107C2C();
void *D_80803950_chclockworkmouse = (void *) 0x00130660;
static u32 D_80803950_chclockworkmouse_rest[4] = {0xD00E6, 0x1190019, 0x3E804650, 0x0};
void *D_80803964_chclockworkmouse = (void *) 0x001303FF;
static u32 D_80803964_chclockworkmouse_rest[4] = {0xD00CC, 0xE60019, 0x3E804650, 0x0};
void *D_80803978_chclockworkmouse = (void *) 0x00130404;
static u32 D_80803978_chclockworkmouse_rest[2] = {0x164E20, 0x0};
u32 D_80803984_chclockworkmouse[48] = {
    0x0,        0x0,      0x40C00000, 0x800001, 0x40C00000, 0x800001, 0x40C00000, 0x800001,
    0x40C00000, 0x800001, 0x3ECCCCCD, 0x7D0001, 0x3ECCCCCD, 0x7D0001, 0x3ECCCCCD, 0x7D0001,
    0x3ECCCCCD, 0x7D0001, 0x3F800000, 0x890001, 0x40000000, 0x8A0042, 0x3F800000, 0x850001,
    0x3F800000, 0x890001, 0x40000000, 0x8A0042, 0x3F800000, 0x850001, 0x3F800000, 0x850001,
    0x3ECCCCCD, 0x7D0001, 0x40C00000, 0x800001, 0x3ECCCCCD, 0x7D0001, 0x3ECCCCCD, 0x7D0001,
    0x3ECCCCCD, 0x7D0001, 0x3F800000, 0x890001, 0x40000000, 0x8A0042, 0x40C00000, 0x800001};
u32 D_80803A44_chclockworkmouse[45] = {
    0x41700000, 0xC1C80000, 0x0,        0x442F0000, 0x0,        0x41700000, 0xC1C80000, 0x0,
    0x442F0000, 0x14A0000,  0x41700000, 0xC1C80000, 0x0,        0x442F0000, 0x17C0000,  0x41700000,
    0xC1C80000, 0x0,        0x442F0000, 0x1B80000,  0x41700000, 0xC1C80000, 0x0,        0x442F0000,
    0x23A0000,  0x41700000, 0xC1C80000, 0x0,        0x442F0000, 0x26C0000,  0x41700000, 0x41C80000,
    0x0,        0x442F0000, 0x2BC0000,  0x41700000, 0x41C80000, 0x0,        0x442F0000, 0x3840000,
    0x41700000, 0x41C80000, 0x0,        0x442F0000, 0x3E80000};
u32 D_80803AF8_chclockworkmouse[40] = {
    0x41700000, 0x434D0000, 0x0,        0x442F0000, 0x0,        0x41700000, 0x434D0000, 0x0,
    0x442F0000, 0x14A0000,  0x41700000, 0x434D0000, 0x0,        0x442F0000, 0x17C0000,  0x41700000,
    0x434D0000, 0x0,        0x442F0000, 0x1B80000,  0x41700000, 0x434D0000, 0x0,        0x442F0000,
    0x2940000,  0x41700000, 0x434D0000, 0x0,        0x442F0000, 0x3520000,  0x41700000, 0x434D0000,
    0x0,        0x442F0000, 0x3840000,  0x41700000, 0x434D0000, 0x0,        0x442F0000, 0x3E80000};
u32 D_80803B98_chclockworkmouse[40] = {
    0x41700000, 0xC1C80000, 0x0,        0x442F0000, 0x0,        0x41700000, 0xC1C80000, 0x0,
    0x442F0000, 0x14A0000,  0x41700000, 0xC1C80000, 0x0,        0x442F0000, 0x17C0000,  0x41700000,
    0xC1C80000, 0x0,        0x442F0000, 0x1B80000,  0x41700000, 0xC1C80000, 0x0,        0x442F0000,
    0x2940000,  0x41700000, 0xC1C80000, 0x0,        0x442F0000, 0x3520000,  0x41700000, 0xC1C80000,
    0x0,        0x442F0000, 0x3840000,  0x41700000, 0xC1C80000, 0x0,        0x442F0000, 0x3E80000};
u32 D_80803C38_chclockworkmouse[40] = {
    0x41700000, 0xC1C80000, 0x0,        0x442F0000, 0x0,        0x41700000, 0xC1C80000, 0x0,
    0x442F0000, 0x14A0000,  0x41700000, 0xC1C80000, 0x0,        0x442F0000, 0x17C0000,  0x41700000,
    0xC1C80000, 0x0,        0x442F0000, 0x1B80000,  0x41700000, 0xC1C80000, 0x0,        0x442F0000,
    0x2940000,  0x41700000, 0xC1C80000, 0x0,        0x442F0000, 0x3520000,  0x41700000, 0xC1C80000,
    0x0,        0x442F0000, 0x3840000,  0x41700000, 0xC1C80000, 0x0,        0x442F0000, 0x3E80000};
Unk80803CD8 *D_80803CD8_chclockworkmouse[4] = {
    (void *) &D_80803A44_chclockworkmouse, (void *) &D_80803AF8_chclockworkmouse,
    (void *) &D_80803B98_chclockworkmouse, (void *) &D_80803C38_chclockworkmouse};
s32 D_80803CE8_chclockworkmouse[4] = {0x9, 0x8, 0x8, 0x8};
u32 D_80803CF8_chclockworkmouse[28] = {0x3ED70A3D, 0x0, 0x0, 0x2000C, 0x3F0147AE, 0x0, 0x0, 0x20007,
                                       0x3F147AE1, 0x0, 0x0, 0x10000, 0x3F266666, 0x0, 0x0, 0x2000B,
                                       0x3F35C28F, 0x0, 0x0, 0x10000, 0x3F47AE14, 0x0, 0x0, 0x2000E,
                                       0x3F570A3D, 0x0, 0x0, 0x10000};
u32 D_80803D68_chclockworkmouse[40] = {
    0x3E19999A, 0x0, 0x0, 0x2000F, 0x3E4CCCCD, 0x0, 0x0, 0x10000, 0x3E8F5C29, 0x0, 0x0, 0x20008,
    0x3EB33333, 0x0, 0x0, 0x10000, 0x3EC7AE14, 0x0, 0x0, 0x20009, 0x3ED70A3D, 0x0, 0x0, 0x10000,
    0x3EFAE148, 0x0, 0x0, 0x2000A, 0x3F051EB8, 0x0, 0x0, 0x10000, 0x3F5851EC, 0x0, 0x0, 0x20010,
    0x3F63D70A, 0x0, 0x0, 0x10000};
Unk80803E08 *D_80803E08_chclockworkmouse[4] = {(void *) &D_80803CF8_chclockworkmouse, 0,
                                               (void *) &D_80803D68_chclockworkmouse, 0};
s32 D_80803E18_chclockworkmouse[4] = {0x7, 0x0, 0xA, 0x0};
s32 D_80803E28_chclockworkmouse[4] = {0x2060013, 0x67E0016, 0x46500001, 0x1F409C4};
static u32 D_80803E28_chclockworkmouse_rest[1] = {0x0};
f32 D_80803E3C_chclockworkmouse[3] = {0.0f, 0.0f, 0.0f};
ActorData *D_80803E48_chclockworkmouse = (void *) 0x01580171;
static u32 D_80803E48_chclockworkmouse_rest[17] = {0x8A00011,
                                                   0x0,
                                                   (u32) func_80801588_chclockworkmouse,
                                                   (u32) func_80801588_chclockworkmouse,
                                                   (u32) func_80801CFC_chclockworkmouse,
                                                   0x5DC0000,
                                                   0x0,
                                                   0x0,
                                                   0x80024,
                                                   (u32) func_80801848_chclockworkmouse,
                                                   0x0,
                                                   0x1200000,
                                                   (u32) func_808018BC_chclockworkmouse,
                                                   (u32) func_80107C2C,
                                                   0x80000002,
                                                   (u32) func_80801BF0_chclockworkmouse,
                                                   0x0};
void *D_80803E90_chclockworkmouse = (void *) 0x3E0F5C29;
static u32 D_80803E90_chclockworkmouse_rest[2] = {0x3F266666, 0xBF800000};
void *D_80803E9C_chclockworkmouse = (void *) 0x3D8F5C29;
static u32 D_80803E9C_chclockworkmouse_rest[4] = {0x3E99999A, 0x3F0F5C29, 0x3F51EB85, 0xBF800000};
void *D_80803EB0_chclockworkmouse = 0;
static u32 D_80803EB0_chclockworkmouse_rest[2] = {0x3F000000, 0xBF800000};
void *D_80803EBC_chclockworkmouse = (void *) 0x3F266666;
static u32 D_80803EBC_chclockworkmouse_rest[4] = {0x3F400000, 0x3F4CCCCD, 0x3F59999A, 0xBF800000};
void *D_80803ED0_chclockworkmouse = (void *) 0x430C0000;
static u32 D_80803ED0_chclockworkmouse_rest[3] = {0x43590000, 0x43590000, 0x0};
void *D_80803EE0_chclockworkmouse = (void *) 0x43590000;
static u32 D_80803EE0_chclockworkmouse_rest[3] = {0x43590000, 0x43590000, 0x42D90000};
ActorData *D_80803EF0_chclockworkmouse = (void *) 0x01580383;
static u32 D_80803EF0_chclockworkmouse_rest[19] = {0x67B0011,
                                                   (u32) &D_80803984_chclockworkmouse,
                                                   (u32) func_80802CC8_chclockworkmouse,
                                                   (u32) func_80802CC8_chclockworkmouse,
                                                   (u32) func_8080364C_chclockworkmouse,
                                                   0x9C42710,
                                                   0x0,
                                                   0x0,
                                                   0x880564,
                                                   (u32) func_80802170_chclockworkmouse,
                                                   0x0,
                                                   0x100000,
                                                   (u32) func_80801FC8_chclockworkmouse,
                                                   (u32) func_80107C2C,
                                                   0x84000002,
                                                   (u32) func_808032F8_chclockworkmouse,
                                                   0x0,
                                                   0x0,
                                                   0x0};
