#include "common.h"

#define DATA ((f32 *) this->actorData)
extern int D_80800A9C_ch2dbaddy[];
typedef struct {
    u8 pad_0[0x64];
    u32 pad_1 : 2;
    u32 unk_64 : 1;
    u32 pad_2 : 29;
} BaddyHitFlags1766;
typedef struct {
    s16 index;
    u8 count;
    u8 pad_0;
} BaddyMessage29;
typedef struct {
    u8 pad_0[0x78];
    u32 pad_1 : 29;
    u32 locked : 1;
    u32 pad_2 : 2;
} BaddyFlags29;
extern u8 D_80800A3C_ch2dbaddy[];
extern void *_sucoaster_entrypoint_3();
typedef struct {
    u8 pad[0x64];
    u32 pad64 : 2;
    u32 flag : 1;
    u32 rest : 29;
} JoyState;
extern s32 _subaddiejoy_entrypoint_6(JoyState *, s32);
extern s32 _sucoaster_entrypoint_13(JoyState *);
typedef struct {
    u8 pad_0[0x64];
    u32 pad_64_30 : 2;
    u32 flag_64_29 : 1;
    u32 pad_64_0 : 29;
} PlantActorFlags;
typedef struct {
    u8 pad_0[0x64];
    u32 pad_1 : 2;
    u32 flag_29 : 1;
    u32 pad_2 : 29;
} BaddyFlags30;
extern void _sucoaster_entrypoint_6();
extern u8 D_80800AE4_ch2dbaddy[];
extern s32 D_80800AF4_ch2dbaddy[];
extern s16 D_80800B00_ch2dbaddy[];
extern void func_8010A3E8(Actor *, f32);
extern void func_80102FDC(Actor *, f32);
extern void func_800EE940(void *, f32 *);
typedef struct {
    u32 pad78_3 : 29;
    u32 unk78_2 : 1;
    u32 pad78_0 : 2;
} ActorFlags78;
typedef struct {
    u32 pad64_30 : 2;
    u32 unk64_29 : 1;
    u32 pad64_0 : 29;
} ActorFlags64;
extern void _sucoaster_entrypoint_2(Actor *);
extern void _sucoaster_entrypoint_10(Actor *, s32);
extern void _sucoaster_entrypoint_19(Actor *);
extern f32 func_8010CD28(Actor *);
extern void func_80102BF8(Actor *, f32, f32, f32);
extern void func_8010A5B0(Actor *, s32);
extern s32 func_80101DDC(Actor *);
extern f32 func_80101F24(Actor *);
extern void func_8010A570(Actor *);
extern s32 _subaddierouteDll_entrypoint_4(Actor *);
extern void func_800EE88C(f32 *, void *);
extern f32 func_80102D78(Actor *, f32 *);
extern void _sucoaster_entrypoint_7(Actor *, s32, f32);
extern f32 func_800EFC7C();
typedef struct {
    u8 pad0[0x64];
    u32 b31 : 1;
    u32 b30 : 1;
    u32 b29 : 1;
    u32 rest : 29;
} Baddy2DFlags;
extern s32 func_800D9058(f32);
extern void func_8010297C(Actor *, f32, f32, f32);
void func_808004A8_ch2dbaddy();
void func_808004F4_ch2dbaddy();
void func_80800700_ch2dbaddy();
void func_80800850_ch2dbaddy();
s32 func_808003C4_ch2dbaddy();
int func_80800564_ch2dbaddy();

int ch2dbaddy_entrypoint_0()
{
    return (int) &D_80800A9C_ch2dbaddy;
}

void func_8080000C_ch2dbaddy(Actor *actor)
{
    void *baddie_data;
    if (_sucoaster_entrypoint_0(actor, 10)) {
        func_8010A3E8(actor, 0.55f);
        func_80102FDC(actor, actor->scale * 0.6f);
        baddie_data = _sucoaster_entrypoint_3(actor);
        func_80800850_ch2dbaddy(actor);
        func_800EE940(baddie_data, actor->position);
        actor->unk64_16 = 0;
        func_8010A570(actor);
    }
}

s32 func_80800468_ch2dbaddy();

void func_808000A0_ch2dbaddy(Actor *this)
{
    f32 route_pos[3];

    _sucoaster_entrypoint_2(this);
    if (((ActorFlags78 *) &this->unk78)->unk78_2) {
        return;
    }
    // States 0x13-0x16 are the notice/chase states.
    switch (this->unk70_10) {
        case 2:
        case 3:
        case 8:
            if (func_80800468_ch2dbaddy(this)) {
                _sucoaster_entrypoint_10(this, 0x16);
                DATA[3] = 0.0f;
            }
            break;
        case 0x13:
            _sucoaster_entrypoint_19(this);
            if (func_8080041C_ch2dbaddy(this)) {
                func_80800700_ch2dbaddy(this, 0x14);
            }
            break;
        case 0x14:
            func_80800820_ch2dbaddy(this);
            this->unk54 = func_8010CD28(this);
            func_80102BF8(this, 0.2f, 60.0f, 300.0f);
            func_8010A5B0(this, this->unk64_20);
            this->unk64_20 = 1;
            if (func_80101DDC(this)) {
                _sucoaster_entrypoint_10(this,
                                         ((ActorFlags64 *) ((u8 *) this + 0x64))->unk64_29 ? 2 : 8);
            }
            break;
        case 0x16:
            _sucoaster_entrypoint_19(this);
            if (0.6f < func_80101F24(this)) {
                func_8010A570(this);
            }
            if (func_80101DDC(this)) {
                func_80800700_ch2dbaddy(this, 0x13);
            }
            break;
        case 0x15:
            _sucoaster_entrypoint_19(this);
            if (!_sucoaster_entrypoint_13(this)) {
                if (func_808003C4_ch2dbaddy(this)) {
                    _sucoaster_entrypoint_10(this, 0x16);
                    DATA[3] = 0.0f;
                    break;
                }
                if (_subaddierouteDll_entrypoint_4(this)) {
                    func_800EE88C(route_pos, _sucoaster_entrypoint_3(this));
                    this->unk54 = func_80102D78(this, route_pos);
                }
            }
            _sucoaster_entrypoint_7(this, 0x5802, 30.0f);
    }
}

s32 func_808002A8_ch2dbaddy(Actor *actor, s32 message, s32 message_data)
{
    s32 result;
    switch (message) {
        case 1:
        case 2:
            result = _sucoaster_entrypoint_21(actor, message, message_data);
            if (!((BaddyFlags29 *) actor)->locked) {
                if (((BaddyHitFlags1766 *) actor)->unk_64)
                    func_808004A8_ch2dbaddy(actor);
                else
                    func_808004F4_ch2dbaddy(actor);
                return 1;
            }
            break;
        case 0x42: // egg/attack table message
            result = func_80800564_ch2dbaddy(actor, ((BaddyMessage29 *) &message_data)->index,
                                              ((BaddyMessage29 *) &message_data)->count);
            break;
        case 0x95:
            func_801032B0(actor, *(u16 *) ((u8 *) _sucoaster_entrypoint_3(actor) + 6), 0);
            result = _sucoaster_entrypoint_21(actor, message, message_data);
            break;
        case 0x38:
            func_80101074(D_80800A3C_ch2dbaddy);
            return 8;
        default:
            result = _sucoaster_entrypoint_21(actor, message, message_data);
    }
    return result;
}

s32 func_808003C4_ch2dbaddy(actor)
u8 *actor;
{
    f32 route_pos[3];
    func_800EE88C(route_pos, _sucoaster_entrypoint_3(actor));
    return func_800EFC7C(actor + 4, route_pos) < 10000.0f;

}

int func_8080041C_ch2dbaddy(JoyState *actor)
{
    if (actor->flag) {
        return _subaddiejoy_entrypoint_6(actor, 0) == 1;
    }

return _sucoaster_entrypoint_13(actor) == 1;

}

s32 func_80800468_ch2dbaddy(Actor *actor)
{
    if (((PlantActorFlags *) actor)->flag_64_29) {
        return _subaddiejoy_entrypoint_6(actor, 0) == 1;
    }

return 0;
}

void func_808004A8_ch2dbaddy(actor) u8 *actor;
{
    u32 state;

    state = (u32) (*(u16 *) ((char *) actor + 0x72)) >> 0xA;

if (state != 0x13) {
    if (state == 0x15) {
        _sucoaster_entrypoint_10(actor, 3);
    }
} else {

func_80800700_ch2dbaddy(actor, 0x14);

}
}

void func_808004F4_ch2dbaddy(actor) u8 *actor;
{
    s32 next_state;
    u32 state;

    state = (u32) *(u16 *) ((s8 *) actor + 0x72) >> 0xA;
    if (state == 2 || state == 3 || state == 8) {
        if (_subaddieDll_entrypoint_3(actor) != 0) {
            next_state = 0x15;
        } else {

next_state = 0xE;
}
_sucoaster_entrypoint_6(actor, 0x43480000, next_state);
_sucoaster_entrypoint_10(actor, next_state);
}
}

int func_80800564_ch2dbaddy(actor, index, count)
Actor *actor;
s32 index;
u32 count;
{
    switch (count) {
        case 0:
            if (actor->unk70_10 == 0x13) {
                return 0;
            }

switch (index) {
    case 2:
    case 3:
        func_80800700_ch2dbaddy(actor, 0x15);
        return 0;
    case 4:
        func_80800700_ch2dbaddy(actor, 0x15);
        return 0;
    case 5:
    case 8:
    case 9:
    case 18:
        return 1;
    case 7:
        _sucoaster_entrypoint_10(actor, 8);
        return 0;
}

break;
case 2:
case 7:
    func_80800700_ch2dbaddy(actor, 0x15);
    return 0;
case 3:
    actor->unk6C_0 = func_800D9058(2.0f);
    func_8010297C(actor, actor->unk54, 70.0f, 120.0f);

if (actor->unk70_10 == 8) {
    func_80800700_ch2dbaddy(actor, 0x15);
}

return 0;

case 4:
    if (actor->unk70_10 != 0x13) {
        return 1;
    }

break;
case 1:
case 6:
    return 1;
case 5:
    func_80800700_ch2dbaddy(actor, 0xC);
    return 0;

case 8:
    if (index == 0x11) {
        func_801020DC(actor, 0);
    }

return 1;

case 9:
    if (((Baddy2DFlags *) actor)->b29) {
        _sucoaster_entrypoint_10(actor, 2);
        return 0;
    }

return 1;
}
return 0;
}

void func_80800700_ch2dbaddy(actor, state) Actor *actor;
s32 state;
{
    u8 *baddie_data;
    baddie_data = _sucoaster_entrypoint_3(actor);
    switch (state) {
        case 0xC:
            func_8010A570(actor);
            _sucoaster_entrypoint_10(actor, state);
            break;
        case 0x15:
            _sucoaster_entrypoint_10(actor, state);
            _sucoaster_entrypoint_6(actor, 0x43480000);
            break;
        case 0x13:
            _sucoaster_entrypoint_10(actor, state);
            func_8010A570(actor);

if (!((BaddyFlags30 *) actor)->flag_29) {
    func_80800850_ch2dbaddy(actor);
    func_801032B0(actor, *(u16 *) (baddie_data + 6), 0);
}

actor->unk64_16 = 0;
break;
case 0x14:
    _sucoaster_entrypoint_10(actor, state);
    actor->unk64_16 = 1;
    actor->unk64_20 = 0;
    func_8010A570(actor);
    _subaddieaudioquick_entrypoint_2(actor, actor->position, D_80800AE4_ch2dbaddy);
    }
    }

    int func_80800820_ch2dbaddy(s32 actor)
    {
        s32 pos;
        pos = actor + 4;
        _subaddieaudioquick_entrypoint_3(actor, pos, &D_80800AF4_ch2dbaddy, 0x3DCCCCCD);
    }

    // Picks a random sound id from a 3-entry table.
    void func_80800850_ch2dbaddy(void)
    {
        void *baddie_data = _sucoaster_entrypoint_3();
        *((u16 *) ((char *) baddie_data + 6)) = D_80800B00_ch2dbaddy[func_800DC128(0, 3)];
    }

    // TU-NOTE: the overlay .data is defined here in C; its tables point to functions of this file,
    // and IDO's assembler schedules them differently unless defined in the same unit.
    extern void func_80105834();
    extern void _sucoaster_entrypoint_20();
    extern void _sucoaster_entrypoint_1();
    extern void _sucoasterhit_entrypoint_0();
    extern void func_80107C2C();
    u32 D_80800970_ch2dbaddy[5] = {0x130001, 0xE0001, 0xD0001, 0x100001, 0x130003};
    u32 D_80800984_ch2dbaddy[46] = {
        0x0,        0x0,       0x40A66666, 0x3800001, 0x40A66666, 0x3800001, 0x3F800000, 0x37C0001,
        0x3F800000, 0x37C0001, 0x3F800000, 0x37C0001, 0x3F800000, 0x37C0001, 0x0,        0x0,
        0x3F800000, 0x37C0001, 0x3F35C28F, 0x37D0002, 0x3F800000, 0x37C0001, 0x3F000000, 0x37F0002,
        0x3FB33333, 0x1EA0002, 0x3FB33333, 0x1EA0084, 0x40A66666, 0x3800001, 0x3F800000, 0x37C0020,
        0x0,        0x0,       0x3FA00000, 0x37B0044, 0x3F800000, 0x37C0001, 0x3FA00000, 0x37B0044,
        0x3FA00000, 0x37B0002, 0x3F800000, 0x37C0001, 0x3F8F5C29, 0x37E0002};
    u8 D_80800A3C_ch2dbaddy[96] = {
        0x0,  0x0,  0x0,  0x12, 0x40, 0x66, 0x66, 0x66, 0x0,  0x13, 0x0,  0x0,  0x0,  0x0,
        0x0,  0x1C, 0x3F, 0xE6, 0x66, 0x66, 0x0,  0x1E, 0x0,  0x0,  0x0,  0x0,  0x0,  0xE,
        0x3F, 0xE6, 0x66, 0x66, 0x0,  0x10, 0x0,  0x0,  0x0,  0x0,  0x0,  0x2B, 0x40, 0xC,
        0xCC, 0xCD, 0x0,  0x1E, 0x0,  0x0,  0x0,  0x0,  0x0,  0x2A, 0x40, 0xC,  0xCC, 0xCD,
        0x0,  0x10, 0x0,  0x0,  0x0,  0x0,  0x0,  0x1A, 0x40, 0xC,  0xCC, 0xCD, 0x2,  0x18,
        0x0,  0x0,  0x0,  0x0,  0x0,  0xC,  0x40, 0xC,  0xCC, 0xCD, 0x2,  0xA,  0x0,  0x0,
        0x0,  0x0,  0x0,  0x46, 0x40, 0x73, 0x33, 0x33, 0x2,  0x44, 0x0,  0x0};
    int D_80800A9C_ch2dbaddy[18] = {0x2F70464,
                                    0x13,
                                    (u32) &D_80800984_ch2dbaddy,
                                    (u32) func_808000A0_ch2dbaddy,
                                    (u32) func_80105834,
                                    (u32) _sucoaster_entrypoint_20,
                                    0xBB80000,
                                    0x0,
                                    0x0,
                                    0x43070329,
                                    (u32) _sucoaster_entrypoint_1,
                                    (u32) _sucoasterhit_entrypoint_0,
                                    0x0,
                                    (u32) func_8080000C_ch2dbaddy,
                                    (u32) func_80107C2C,
                                    -0x7BCDABE3,
                                    (u32) func_808002A8_ch2dbaddy,
                                    (u32) &D_80800970_ch2dbaddy};
    u8 D_80800AE4_ch2dbaddy[16] = {0x0, 0x13, 0x5, 0x20, 0x0, 0xD, 0x0, 0xF3,
                                   0x1, 0xC,  0x0, 0x18, 0x0, 0x0, 0x0, 0x0};
    s32 D_80800AF4_ch2dbaddy[3] = {0x1305EC, 0xD00F3, 0x10C0000};
    s16 D_80800B00_ch2dbaddy[8] = {0x818, 0x819, 0x81A, 0x0, 0x0, 0x0, 0x0, 0x0};
