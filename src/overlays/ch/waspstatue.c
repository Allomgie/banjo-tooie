// Most likely the Cloud Cuckooland wasp statue puzzle: hitting it starts a 10 s countdown, enough
// hits in time set flag 0x35A. A second actor is a door that then opens for Bee Banjo.
#include "common.h"

extern void *D_80800740_chwaspstatue;
extern void _chdoormake_entrypoint_3(Actor *, f32, f32, f32, s32, s32);
extern void _chdoormake_entrypoint_5(Actor *, f32);
extern void _chdoormake_entrypoint_6(Actor *, f32);
extern void *D_80800788_chwaspstatue;
extern s32 _chwaspstatue_entrypoint_0;
extern f32 func_800F10B4(f32, f32, f32, f32, f32);
void func_80800134_chwaspstatue();

// Start in the done state if flag 0x35A is set.
int func_80800000_chwaspstatue(Actor *actor)
{
    s32 state;
    state = func_800DA298(0x35A);
    if (state != 0) {
        state = 6;
    } else {
        state = 1;
    }
    func_80800134_chwaspstatue(actor, state);
}

void func_8080003C_chwaspstatue(u8 *actor)
{
// Matching: extra temporaries needed for the match.
    u16 raw_state;
    u32 state;
    state = *(u16 *) (actor + 0x72);
    raw_state = state;
    state = (u16) raw_state;
    state = state >> 0xA;
    switch (state) {
        u8 *timer;
        case 1:

        case 6:
            break;

        case 2:
            timer = actor + 0x58;
            if ((func_800D91EC(timer, 0x40000000) != 0) && (func_800DA298(0x6D8) != 0)) {
                func_80800134_chwaspstatue(actor, 3);
            }
            func_800D2498(0xFF, *(s32 *) (actor + 0x6C) & 0x1FF, 0);
            break;

        case 3:
            func_800D2498(0xFF, *(s32 *) (actor + 0x6C) & 0x1FF, 0);
            break;

        case 4:
            if (func_800D90A4(actor + 0x58) != (long) 0) {
                func_80800134_chwaspstatue(actor, 1);
            }
            break;

        case 5:
            func_80800134_chwaspstatue(actor, 6);
    }

    func_8010C93C(actor, actor + 4, 0x3F400000);
}

// Enter a state: 1 idle, 2 countdown started, 3 waiting for hits, 4 time expired, 5 solved, 6 done.
void func_80800134_chwaspstatue(actor, new_state) u8 *actor;
s32 new_state;
{
    s32 actor_id;
    s32 actor_id2;

switch (new_state) {
    case 1:
        _subaddieDll_entrypoint_4(actor, 0);
        break;
    case 2:
        _subaddieDll_entrypoint_4(actor, 1);
        func_800CE8D8(0, 0x41200000, 0xA);
        func_800CE928(0, &_chwaspstatue_entrypoint_0, *(s32 *) ((s8 *) actor + 0));
        *(u16 *) ((s8 *) actor + 0x6E) =
            (u16) ((*(u16 *) ((s8 *) actor + 0x6E) & 0xFE00) | 0x14);
        *(f32 *) ((s8 *) actor + 0x58) = 0.0f;
        if (func_800DA298(0x6D8) == 0) {
            actor_id = *(s32 *) ((s8 *) actor + 0);
            _capod_entrypoint_13(actor_id, actor_id, 0x15, 0x810);
            _subaddiedialog_entrypoint_11(*(s32 *) ((s8 *) actor + 0), 0x1416, 0xF, actor + 4,
                                          0x6D);
        } else {
            func_800CE88C(0, 1);
        }
        break;
    case 3:
        if (func_800DA298(0x6D8) == 0) {
            func_800CE88C(0, 1);
        }
        *(f32 *) ((s8 *) actor + 0x58) = 2.0f;
        break;
    case 4:
        if (func_800DA298(0x6D9) == 0) {
            func_800DA544(0x6D9);
            _subaddiedialog_entrypoint_11(*(s32 *) ((s8 *) actor + 0), 0x1419, 0xF, actor + 4,
                                          0x6D);
            actor_id2 = *(s32 *) ((s8 *) actor + 0);
            _capod_entrypoint_13(actor_id2, actor_id2, 0x1B, 0x810);
        }
        func_800FC6B0(0x19);
        *(f32 *) ((s8 *) actor + 0x58) = 2.0f;
        break;
    case 5:
        func_800FC6B0(0x10);
        func_800D2498(0xFF, 0, 0);
        _subaddiedialog_entrypoint_11(*(s32 *) ((s8 *) actor + 0), 0x1418, 0xF, actor + 4,
                                      0x6D);
        func_80101180(0x411, 7, 0);
        func_800DA544(0x35A);
        *(f32 *) ((s8 *) actor + 0x58) = 2.0f;
        func_800CE88C(0, 0);
        break;
    case 6:
        _subaddieDll_entrypoint_4(actor, 0);
        *(f32 *) ((s8 *) actor + 0x58) = 2.0f;
}

func_80101FDC(actor, new_state);

}

// Message handler; 0x40 counts statue hits.
int func_80800350_chwaspstatue(Actor *actor, s32 msg, s32 arg)
{
    switch (msg) {
        case 0x3F:
            if (!func_800DA298(0x6DA)) {
                func_800DA544(0x6DA);
                _subaddiedialog_entrypoint_11(actor->unk0, 0x1417, 15, actor->position, 0x6D);
            }
            return 1;
        case 0x40:
            if (actor->unk70_10 == 1) {
                func_80800134_chwaspstatue(actor, 2);
                func_800FC660(14);
            } else if (actor->unk70_10 == 3) {
                actor->unk6C_0--;
                if (!actor->unk6C_0)
                    func_80800134_chwaspstatue(actor, 5);
                func_800FC660(14);
            }
            return 1;
        case 0xB:
            if (arg == 21) {
                func_80800134_chwaspstatue(actor, 3);
                func_800DA544(0x6D8);
            }
            return 3;
        case 0x1F:
            func_801015D0(actor);
            func_800DF6BC((s32) func_800F10B4(actor->unk58, 0.0f, 2.0f, 0, 255.0f), 255);
            return 1;
        case 0x30:
            if (((s16 *) &arg)[0] == 0x1416) {
                if (((s16 *) &arg)[1])
                    return 20;
                return 10;
            }
            return 0;
        default:
            return 0;
    }

}

s32 chwaspstatue_entrypoint_0(s32 param_0, Actor *param_1)
{
    Actor *statue = func_80106790(param_1);
    func_80800134_chwaspstatue(statue, 4);
}

void *chwaspstatue_entrypoint_1()
{
    return &D_80800740_chwaspstatue;
}

// Door that opens once flag 0x35A is set and the player is Bee Banjo.
void func_80800544_chwaspstatue(Actor *actor)
{
    s32 can_open;

    can_open = func_800F64A4(func_800F54E4(), 0x20) != 0;
    if (can_open)
        can_open = func_800DA298(0x35A) != 0;
    func_800DA3B8(0x9FD, can_open);
    _chdoormake_entrypoint_3(actor, actor->rotation[1], actor->rotation[0] + 90.0f,
                             actor->scale * 346.0f, 0x83, 0x9FD);
    _chdoormake_entrypoint_5(actor, 2.0f);
    _chdoormake_entrypoint_6(actor, 0.5f);
    _chdoormake_entrypoint_8(actor, 5);
    _chdoormake_entrypoint_9(actor, 0, 0x1D, 0x810);
    _chdoormake_entrypoint_10(actor, 0, 0x3DF);
}

int chwaspstatue_entrypoint_2()
{
    return &D_80800788_chwaspstatue;
}

extern void func_80105834();
extern void func_801018A4();
extern void func_80108ED0();
extern void func_80107C2C();
extern void _chdoor_entrypoint_0();
extern void func_80101870();
extern void _chdoor_entrypoint_1();
// TU-NOTE: the .data tables below are defined in C so IDO schedules the functions as in the original.
void *D_80800740_chwaspstatue = (void *) 0x0352040F;
static u32 D_80800740_chwaspstatue_rest[17] = {0x8D00001,
                                               0x0,
                                               (u32) func_8080003C_chwaspstatue,
                                               (u32) func_80105834,
                                               (u32) func_801018A4,
                                               0x3E836B0,
                                               0x0,
                                               0x0,
                                               0x400,
                                               0x0,
                                               (u32) func_80108ED0,
                                               0x0,
                                               (u32) func_80800000_chwaspstatue,
                                               (u32) func_80107C2C,
                                               0x80002400,
                                               (u32) func_80800350_chwaspstatue,
                                               0x0};
void *D_80800788_chwaspstatue = (void *) 0x03550411;
static u32 D_80800788_chwaspstatue_rest[17] = {0x8D10001,
                                               0x0,
                                               (u32) _chdoor_entrypoint_0,
                                               (u32) func_80105834,
                                               (u32) func_80101870,
                                               0x0,
                                               0x0,
                                               0x0,
                                               0x800,
                                               0x0,
                                               (u32) func_80108ED0,
                                               0x0,
                                               (u32) func_80800544_chwaspstatue,
                                               (u32) func_80107C2C,
                                               0x80002402,
                                               (u32) _chdoor_entrypoint_1,
                                               0x0};
