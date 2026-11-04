// The star platforms of the Witchyworld Star Spinner: when powered they rise and spin while touched
// and sink back otherwise; the egg target slows them down. Each star gets a controller light.

#include "common.h"

extern int D_808006B0_chstarspinnerstar[];
extern Actor *_subaddiefind_entrypoint_0(f32 *, s32, s32, s32);
extern s32 _chstarspinnerctrl_entrypoint_3(Actor *, f32 *);
extern void func_800EE7F8(f32 *, f32 *);
typedef union {
    s32 word;
    Unk80132ED0 *marker;
} StarSpinnerEventPayload;
typedef struct {
    f32 f0, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11, f12, f13, f14, f15;
} ADF_;
extern u8 D_808006F8_chstarspinnerstar[];
extern f32 func_800D8FF8(void);
extern f32 func_800136E4(f32);
extern f32 func_800F10B4(f32, f32, f32, f32, f32);
extern void func_800C4B64(f32);
extern void _subaddieaudioloop_entrypoint_0(Actor *, f32);
extern void func_80101FDC();
extern f32 mlAbsF(f32);
void func_808005F8_chstarspinnerstar();
f32 *func_80800660_chstarspinnerstar();
int func_80800454_chstarspinnerstar(Actor *param_0, f32 param_1);
extern void func_801018A4(), func_80105834(), func_80107C2C(), func_80800320_chstarspinnerstar();

int chstarspinnerstar_entrypoint_0()
{
    return (int) &D_808006B0_chstarspinnerstar;
}

// Per-frame update: rise/spin when touched while powered, sink back otherwise.
void func_8080000C_chstarspinnerstar(Actor *actor)
{
    f32 dt;
    s32 powered;
    s32 active;
    f32 pitch;

    dt = func_800D8FF8();
    powered = func_800DA298(0xEA) || _glcutDll_entrypoint_20();
    actor->actorData[6] = _chstarspinnerctrl_entrypoint_4(
        actor, func_80800660_chstarspinnerstar(actor), actor->actorData[6]);
    switch (actor->unk70_10) {
        case 1:
            if (powered && actor->unk64_20) {
                func_80101FDC(actor, 2);
                actor->unk58 = 1.5f;
            }
            break;
        case 2:
            ((ADF_ *) actor->actorData)->f7 =
                (func_800DA298(0x679) ? 30 : 80) * ((ADF_ *) actor->actorData)->f4;
            actor->rotation[1] =
                func_800136E4(actor->rotation[1] + dt * ((ADF_ *) actor->actorData)->f7);
            func_80800454_chstarspinnerstar(actor, dt);
            if (!actor->unk64_20 || !powered) {
                actor->unk58 -= dt;
                if (actor->unk58 < 0.0f || !powered) {
                    if (((ADF_ *) actor->actorData)->f5 > 0) {
                        ((ADF_ *) actor->actorData)->f5 = -((ADF_ *) actor->actorData)->f5;
                    }
                    func_80101FDC(actor, 3);
                }
            } else {
                actor->unk58 = 1.5f;
            }
            break;
        case 3:
            ((ADF_ *) actor->actorData)->f7 =
                (func_800DA298(0x679) ? 30 : 80) * ((ADF_ *) actor->actorData)->f4;
            actor->rotation[1] =
                func_800136E4(actor->rotation[1] + dt * ((ADF_ *) actor->actorData)->f7);
            if (func_80800454_chstarspinnerstar(actor, dt)) {
                actor->position[1] = ((ADF_ *) actor->actorData)->f1;
                func_80101FDC(actor, 1);
            }
            if (actor->unk64_20 && powered) {
                func_80101FDC(actor, 2);
                actor->unk58 = 1.5f;
            }
            break;
    }
    actor->unk64_20 = 0;
    active = powered && (s32) actor->unk70_10 >= 2;
    if (active || (!active && actor->unk5F)) {
        pitch = func_800F10B4(actor->position[1] - ((ADF_ *) actor->actorData)->f1, 0,
                                1900.0f, 0.8f, 1.2f);
        func_800C4B64(pitch);
        _subaddieaudioloop_entrypoint_4(actor, actor->position, active,
                                        D_808006F8_chstarspinnerstar);
        _subaddieaudioloop_entrypoint_0(actor, pitch);
    }
}

void func_80800320_chstarspinnerstar(actor) Actor *actor;
{
    actor->unk3C = _subaddiefind_entrypoint_0(actor->position, 0x337, -1, 0)->unk0;
    actor->actorData[6] =
        _chstarspinnerctrl_entrypoint_3(actor, func_80800660_chstarspinnerstar(actor));
    actor->unk54 = actor->rotation[1];
    func_800EE7F8((f32 *) actor->actorData, actor->position);
    if (actor->rotation[1] == 1.0f) {
        *(f32 *) ((u8 *) actor + 0x28) = -1.0f;
    } else {
        *(f32 *) ((u8 *) actor + 0x28) = 1.0;
    }
    actor->rotation[1] = 0.0f;
    *(f32 *) ((u8 *) actor + 0x2C) = 1.0;
    if (func_800EA05C() != 0xE6) {
        func_8010A624(actor);
    }
}

s32 func_808003F8_chstarspinnerstar(Actor *actor, s32 event, StarSpinnerEventPayload payload)
{
    switch (event) {
        case 0x91:
            actor->unk64_20 = 1;
            break;
        case 0x1F:
            func_808005F8_chstarspinnerstar(actor, payload.word);
            break;
        default:
            return 0;
    }
    return 1;
}

// Move vertically toward start or start+1900; returns 1 on reaching the end.
int func_80800454_chstarspinnerstar(Actor *actor, f32 dt)
{
    s32 slow;
    f32 step;
    f32 dist;
    f32 max_step;
    step =
        ((((f32 *) actor->actorData)[5] < 0.0f ? ((f32 *) actor->actorData)[1]
                                                 : ((f32 *) actor->actorData)[1] + 1900.0f) -
         actor->position[1]) *
        0.05f;
    dist = mlAbsF(step);
    slow = func_800DA298(0x679);
    max_step = ((f32 *) actor->actorData)[5] * (slow ? 400 : 1000) * dt;
    if (dist < 4.0f) {
        step = step < 0.0f ? -4.0f : 4.0f;
    } else if (dist > mlAbsF(max_step)) {
        step = max_step;
    }
    actor->position[1] += step;
    if (((f32 *) actor->actorData)[5] < 0.0f) {
        if (actor->position[1] < ((f32 *) actor->actorData)[1]) {
            ((f32 *) actor->actorData)[5] = -((f32 *) actor->actorData)[5];
            return 1;
        }
    } else if (((f32 *) actor->actorData)[1] + 1900.0f < actor->position[1]) {
        ((f32 *) actor->actorData)[5] = -((f32 *) actor->actorData)[5];
        return 1;
    }
    return 0;
}

void func_808005F8_chstarspinnerstar(param_0, param_1) u8 **param_0;
s32 param_1;
{
    u8 sp1F;
    int temp_v0;
    func_801015D0();
    temp_v0 = func_800D731C(*(u16 *) ((s8 *) *param_0 + 0x14));
    sp1F = temp_v0;
    if (((temp_v0 != 0) && (func_800DA298(0xEA) == 0)) && (_glcutDll_entrypoint_20() == 0)) {
        func_800DBE60(sp1F, 0, 0);
    }
}

u8 B_80800710_chstarspinnerstar[16];

f32 *func_80800660_chstarspinnerstar(actor_addr)
s32 actor_addr;
{
    func_800EE7F8(B_80800710_chstarspinnerstar, (f32 *) (actor_addr + 4));
    ((f32 *) B_80800710_chstarspinnerstar)[1] = ((f32 *) B_80800710_chstarspinnerstar)[1];
    return (f32 *) B_80800710_chstarspinnerstar;
}

int D_808006B0_chstarspinnerstar[18] = {0x1BF0336,
                                        0x7790001,
                                        0x0,
                                        (u32) func_8080000C_chstarspinnerstar,
                                        (u32) func_80105834,
                                        (u32) func_801018A4,
                                        0x0,
                                        0x0,
                                        0x0,
                                        0x4C00,
                                        0x0,
                                        0x0,
                                        0x0,
                                        (u32) func_80800320_chstarspinnerstar,
                                        (u32) func_80107C2C,
                                        -0x7FFFFBEE,
                                        (u32) func_808003F8_chstarspinnerstar,
                                        0x0};
u8 D_808006F8_chstarspinnerstar[24] = {0x0, 0x13, 0x4,  0xE0, 0x0, 0xA, 0x0, 0xCC,
                                       0x0, 0x16, 0x1B, 0x58, 0x0, 0x0, 0x0, 0x0,
                                       0x0, 0x0,  0x0,  0x0,  0x0, 0x0, 0x0, 0x0};
