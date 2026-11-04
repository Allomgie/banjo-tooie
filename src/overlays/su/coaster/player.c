#include "common.h"

typedef struct {
    u8 pad_0[0xE];
    s16 unk_E;
} CoasterPlayerTarget;
extern void *func_80100094(Actor *, u32);
extern f32 func_80107C00(void);
extern f32 func_800F15F8(f32, f32, f32);
extern f32 func_800F2094(f32, f32);
extern void func_80102BF8(Actor *, f32, f32, f32);
extern f32 _subaddiejoy_entrypoint_9(Actor *, f32 *, s32);
extern void _sucoaster_entrypoint_6(Actor *, f32);
typedef struct {
    u8 pad_0[0xC];
    s16 unk_C;
    s16 unk_E;
    u8 pad_1[8];
    u32 kind : 4;
    u32 pad_2 : 6;
    u32 unk_18 : 1;
    u32 pad_3 : 21;
} CoasterPlayerState441;
typedef struct {
    u8 pad_0[0x64];
    u32 pad_1 : 3;
    u32 controller : 2;
    u32 pad_2 : 27;
} CoasterController441;

s32 sucoasterplayer_entrypoint_2(Actor *actor, f32 rate);

extern void _sucoaster_entrypoint_11(Actor *, f32);
extern void _subaddiefade_entrypoint_3();
extern s32 func_800DC298(f32);

// Per-state update while a controller drives the baddie.
void sucoasterplayer_entrypoint_0(Actor *actor)
{
    CoasterPlayerState441 *state;

    state = func_80100094(actor, 0);
    switch (actor->unk70_10) {
        case 2:
            if (!func_8080076C_sucoasterplayer(actor, state)) {
                if (sucoasterplayer_entrypoint_3(actor)) {
                    if ((f32) _sucoasterdata_entrypoint_2(state->kind) *
                            ((f32) state->unk_C * 0.00390625f) <=
                        (f32) state->unk_E) {
                        _sucoaster_entrypoint_9(actor, 3, 6);
                    }
                } else if (func_801021BC(actor, 7) &&
                           func_80016B54(((CoasterController441 *) actor)->controller, 1) == 1) {
                    _sucoaster_entrypoint_9(actor, 7, 6);
                }
            }
            sucoasterplayer_entrypoint_2(actor, 30.0f);
            return;
        case 3:
            _sucoaster_entrypoint_11(actor, (f32) _sucoasterdata_entrypoint_2(state->kind));
            if (!func_8080076C_sucoasterplayer(actor, state)) {
                if (sucoasterplayer_entrypoint_3(actor)) {
                    if ((f32) _sucoasterdata_entrypoint_3(state->kind) *
                            ((f32) state->unk_C * 0.00390625f) <
                        (f32) state->unk_E) {
                        _sucoaster_entrypoint_9(actor, 8, 6);
                    }
                    if ((f32) state->unk_E <
                        (f32) _sucoasterdata_entrypoint_2(state->kind) *
                            ((f32) state->unk_C * 0.00390625f)) {
                        _sucoaster_entrypoint_9(actor, 2, 6);
                    }
                } else {
                    _sucoaster_entrypoint_9(actor, 2, 6);
                }
            }
            sucoasterplayer_entrypoint_2(actor, 30.0f);
            return;
        case 8:
            _sucoaster_entrypoint_11(actor, (f32) _sucoasterdata_entrypoint_3(state->kind));
            if (!func_8080076C_sucoasterplayer(actor, state)) {
                if (sucoasterplayer_entrypoint_3(actor)) {
                    if ((f32) state->unk_E <=
                        (f32) _sucoasterdata_entrypoint_3(state->kind) *
                            ((f32) state->unk_C * 0.00390625f)) {
                        _sucoaster_entrypoint_9(actor, 3, 6);
                    }
                } else {
                    _sucoaster_entrypoint_9(actor, 3, 6);
                }
            }
            sucoasterplayer_entrypoint_2(actor, 30.0f);
            return;
        case 9:
            _sucoaster_entrypoint_19(actor);
            _subaddiejoy_entrypoint_9(actor, &actor->unk54, 1);
            func_80102BF8(actor, 0.3f, 1.0f, 1000.0f);
            sucoasterplayer_entrypoint_2(actor, 30.0f);
            _sucoaster_entrypoint_16(actor, 1);
            _sucoaster_entrypoint_16(actor, 6);
            if (!state->unk_18 && _sucoaster_entrypoint_16(actor, 5)) {
                _sucoasterhit_entrypoint_2(actor);
            }
            if (func_80101DDC(actor)) {
                _sucoaster_entrypoint_9(actor, 3, 6);
            }
            return;
        case 11:
            _sucoaster_entrypoint_16(actor, 2);
            if (func_80101DDC(actor)) {
                _sucoaster_entrypoint_9(actor, 3, 6);
            }
            break;
        case 12:
        case 13:
        case 18:
            actor->unk64_24 = 0;
            return;
        case 15:
            _sucoasterhit_entrypoint_1(actor);
            return;
        case 7:
            _sucoaster_entrypoint_19(actor);
            sucoasterplayer_entrypoint_3(actor);
            _sucoaster_entrypoint_16(actor, 0);
            func_80102BF8(actor, 0.3f, 1.0f, 1000.0f);
            if (func_80101DDC(actor)) {
                _sucoaster_entrypoint_9(actor, 2, 6);
            }
    }
}

void sucoasterplayer_entrypoint_1(Actor *actor)
{
    u32 flags;

    if (!((*(u32 *) ((u8 *) actor + 0x64) << 2) >> 31)) {
        if (actor->unk70_10 == 12)
            return;
        flags = *(u32 *) ((u8 *) actor + 0x70);
        if (!(flags >> 25) || !((flags << 22) >> 26))
            return;
        if (_subaddieDll_entrypoint_3()) {
            if (actor->unk70_10 == 2)
                _sucoaster_entrypoint_9(actor, func_800DC298(0.5f) ? 2 : 3, 7);
        } else if (!func_80107070(actor, 1)) {
            _subaddiefade_entrypoint_3(actor);
            _sucoaster_entrypoint_10(actor, 14);
        }
        *(u32 *) ((u8 *) actor + 0x14) |= 0x80000;
    } else {
        *(u32 *) ((u8 *) actor + 0x14) &= ~0x80000;
        switch (actor->unk70_10) {
            case 5:
            case 6:
            case 7:
            case 10:
                _sucoaster_entrypoint_9(actor, 2, 6);
                break;
            case 4:
                _sucoaster_entrypoint_9(actor, 3, 6);
        }
    }
    actor->unk54 = *(f32 *) ((u8 *) actor + 0x48);
}

s32 sucoasterplayer_entrypoint_2(Actor *actor, f32 rate)
{
    CoasterPlayerTarget *data;
    f32 unk_1;

    data = func_80100094(actor, 0);
    *(f32 *) &actor->actorData[3] =
        func_800F15F8(*(f32 *) &actor->actorData[3], data->unk_E, func_80107C00() * rate);
    _sucoaster_entrypoint_18(actor);
    unk_1 = func_800F2094(actor->unk54, actor->rotation[1]);
    func_80102BF8(actor, 0.3f, 1.0f, 1000.0f);
    if (unk_1 >= 100.0f)
        return 1;
    func_8010B990(actor, 0x205025);
    return 1;
}

int sucoasterplayer_entrypoint_3(Actor *actor)
{
    u32 *state;
    f32 stick;
    state = func_80100094(actor, 0);
    stick = _subaddiejoy_entrypoint_9(actor, &actor->unk54, 1);
    _sucoaster_entrypoint_6(actor, _sucoasterdata_entrypoint_4(state[6] >> 28) * stick);
    return stick != 0.0f;
}

int func_8080076C_sucoasterplayer(Actor *actor, void *state)
{
    void *params = _sucoasterdata_entrypoint_1((u32) *(s32 *) ((char *) state + 0x18) >> 28);
    if (*(u16 *) ((char *) params + 0x4A) != 0) {
        if (func_80016B30((u32) *(s32 *) ((char *) actor + 0x64) * 8 >> 30, 1) == 1) {
            return _sucoaster_entrypoint_9(actor, 9, 6);
        }
    }
    return 0;
}
