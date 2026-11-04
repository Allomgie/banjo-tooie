// Most likely the Hillbilly baddie on the shared su/coaster walker framework. It hides and pops
// up (models 0x789/0x78A), chases the player along a route and has the usual hit/death/stun states.
#include "common.h"

extern int D_80800C60_chhillbilly[];
typedef struct {
    u8 pad[0x28];
    u32 pad28 : 18;
    u32 flag : 1;
    u32 rest : 13;
} HillSub;
extern void func_800DF744(s32, s32, HillSub **);
extern void _sucoaster_entrypoint_20(HillSub **, s32);
extern void func_800EE7F8(void *, void *);
extern s32 D_80800CB4_chhillbilly[];
typedef struct {
    u8 pad_0[0x64];
    u32 : 2;
    u32 joy_control : 1;
    u32 : 29;
} HillbillyFlags1262;
extern s32 _subaddiejoy_entrypoint_6(Actor *, s32);
extern int _sucoaster_entrypoint_13(Actor *);
typedef struct {
    u8 pad_0[0x64];
    u32 pad_64_30 : 2;
    u32 joy_control : 1;
    u32 pad_64_0 : 29;
} PlantActorFlags;
extern s32 _subaddieDll_entrypoint_3(Actor *);
extern void _sucoaster_entrypoint_6();
extern void _sucoaster_entrypoint_10(Actor *, s32);
typedef struct {
    u8 pad0[0x64];
    u32 pad64 : 2;
    u32 joy_control : 1;
    u32 pad64_0 : 29;
    u8 pad68[0x10];
    u32 pad78 : 29;
    u32 disabled : 1;
    u32 pad78_0 : 2;
} HillbillyActor;
typedef struct {
    u8 pad0[0x2A];
    u8 unk2A;
} HillbillyModel;
extern u8 D_80800B54_chhillbilly[];
extern s32 _sucoaster_entrypoint_21(Actor *, s32, s32);
extern void func_80101074();
extern s32 _sucoaster_entrypoint_3(u8 *);
extern void func_800EE88C(f32 *, f32 *);
extern void func_800BBCB8(void *, s32, s32, s32, void *);
extern s32 D_80800CF0_chhillbilly[];
extern void func_80103140();
extern void func_801032B0();
extern void func_8010A3E8(Actor *, f32);
extern void _subaddieskeleton_entrypoint_3(Unk80132ED0 *, s32, f32 *);
extern f32 func_8010CD28(Actor *);
extern void func_80102BF8(Actor *, f32, f32, f32);
extern f32 func_80102D78(Actor *, f32 *);
extern void _subaddieaudioquick_entrypoint_3(Actor *, f32 *, void *, f32);
extern void _sucoaster_entrypoint_7(Actor *, s32, f32);
extern u8 D_80800CA8_chhillbilly[];
typedef struct {
    u8 pad_0[0x64];
    u32 pad_1 : 2;
    u32 joy_control : 1;
    u32 pad_2 : 29;
    u8 pad_3[0x10];
    u32 pad_4 : 29;
    u32 disabled : 1;
    u32 pad_5 : 2;
} HillbillyFlags62;
extern f32 func_800EFC7C();
extern s32 func_800D9058(f32);
extern void func_8010297C(Actor *, f32, f32, f32);
typedef struct {
    u32 pad64_30 : 2;
    u32 joy_control : 1;
    u32 pad64_0 : 29;
} ActorFlags64;
void func_808009D8_chhillbilly();
s32 func_808002F0_chhillbilly();
s32 func_808006B4_chhillbilly();

int *chhillbilly_entrypoint_0()
{
    return &D_80800C60_chhillbilly;
}

s32 func_8080000C_chhillbilly(s32 actor)
{
    s32 data;

    if (_sucoaster_entrypoint_0(actor, 0xC)) {
        data = _sucoaster_entrypoint_3(actor);
        func_800EE940(data + 6, actor + 4);
        func_800EE940(data, actor + 4);
    }
}

void func_80800944_chhillbilly();

s32 func_8080042C_chhillbilly();

// Update: hide, pop-up and chase states.
void func_80800064_chhillbilly(Actor *actor)
{
    f32 bone_pos[3];
    f32 target[3];

    _sucoaster_entrypoint_2(actor);
    if (((HillbillyFlags62 *) actor)->disabled)
        return;
    _subaddieskeleton_entrypoint_3(actor->unk0, 4, bone_pos);
    func_800EE940(_sucoaster_entrypoint_3(actor), bone_pos);
    switch (actor->unk70_10) {
        case 2:
        case 3:
        case 8:
            if (func_8080042C_chhillbilly(actor)) {
                _sucoaster_entrypoint_10(actor, 0x14);
                ((f32 *) actor->actorData)[3] = 0.0f;
            }
            break;
        case 19:
            func_80800944_chhillbilly(actor);
            actor->unk54 = func_8010CD28(actor);
            func_80102BF8(actor, 0.2f, 60.0f, 300.0f);
            _subaddieaudioquick_entrypoint_3(actor, actor->position, D_80800CA8_chhillbilly,
                                             0.2f);
            if (func_80101DDC(actor)) {
                _sucoaster_entrypoint_10(actor, (((u8 *) actor)[0x74] & 1)              ? 0x12
                                                  : ((HillbillyFlags62 *) actor)->joy_control ? 2
                                                                                            : 8);
            }
            break;
        case 20:
            _sucoaster_entrypoint_19(actor);
            if (func_80101DDC(actor)) {
                func_808009D8_chhillbilly(actor, 0x78A, 0);
                _sucoaster_entrypoint_10(actor, 0x16);
            }
            break;
        case 21:
            _sucoaster_entrypoint_19(actor);
            if (!_sucoaster_entrypoint_13(actor)) {
                if (func_808002F0_chhillbilly(actor)) {
                    _sucoaster_entrypoint_10(actor, 0x14);
                    ((f32 *) actor->actorData)[3] = 0.0f;
                    break;
                }
                if (_subaddierouteDll_entrypoint_4(actor)) {
                    func_800EE88C(target, (f32 *) ((u8 *) _sucoaster_entrypoint_3(actor) + 6));
                    actor->unk54 = func_80102D78(actor, target);
                }
            }
            _sucoaster_entrypoint_7(actor, 0x5802, 30.0f);
            break;
        case 22:
            if (func_808003C8_chhillbilly(actor)) {
                func_808009D8_chhillbilly(actor, 0x789, 0);
                _sucoaster_entrypoint_10(actor, 0x13);
            }
    }
}

void func_80800298_chhillbilly(HillSub **actor, s32 param_1)
{
    func_800DF744(3, (*actor)->flag ? 0 : 1, actor);
    _sucoaster_entrypoint_20(actor, param_1);
}

s32 func_808002F0_chhillbilly(actor)
u8 *actor;
{
    f32 target[3];
    func_800EE88C(target, _sucoaster_entrypoint_3(actor) + 6);
    return func_800EFC7C(actor + 4, target) < 10000.0f;
}

void func_80800348_chhillbilly(void *actor)
{
    f32 pos[3];

if (((unsigned int) *(u16 *) ((char *) actor + 0x72) >> 10) == 0x16) {
    func_800EE7F8(pos, (void *) ((char *) actor + 0x4));
}

else
{
    func_800EE88C(pos, _sucoaster_entrypoint_3(actor));
}
func_800BBCB8(pos, 0, *((s32 *) (((char *) actor) + 0x38)), 1, &D_80800CB4_chhillbilly);

}

int func_808003C8_chhillbilly(Actor *actor)
{
    if (((HillbillyFlags1262 *) actor)->joy_control) {
        return _subaddiejoy_entrypoint_6(actor, 0) == 1;
    }

if (*((u8 *) actor + 0x74) & 1) {
    return 1;
}

return _sucoaster_entrypoint_13(actor) == 1;

}

s32 func_8080042C_chhillbilly(Actor *actor)
{
    if (((PlantActorFlags *) actor)->joy_control) {
        return _subaddiejoy_entrypoint_6(actor, 0) == 1;
    }

return 0;
}

void func_8080046C_chhillbilly(u8 *actor)
{
    u32 state;
    state = (u16) (*((u16 *) (((s8 *) actor) + 0x72)));
    state = state >> 10;

switch (state) {
    case 21:
        _sucoaster_entrypoint_10(actor, 3);
        return;

    case 22:
        func_808009D8_chhillbilly(actor, 0x789, 0);
        _sucoaster_entrypoint_10(actor, 0x13);
}

}

void func_808004D0_chhillbilly(Actor *actor)
{
    s32 next_state;
    u32 state;

    state = actor->unk70_10;

if (state == 2 || state == 3 || state == 8) {
    if (_subaddieDll_entrypoint_3(actor)) {
        next_state = 21;
    } else {
        next_state = 14;
    }
    _sucoaster_entrypoint_6(actor, 0x43480000, next_state);
    _sucoaster_entrypoint_10(actor, next_state);
}

}

// Message handler.
s32 func_80800540_chhillbilly(Actor *actor, s32 msg, s32 msg_data)
{
    s32 result;
    s32 unk_0;

switch (msg) {
    case 1:
    case 2:
        result = _sucoaster_entrypoint_21(actor, msg, msg_data);
        if (!((HillbillyActor *) actor)->disabled) {
            if (((HillbillyActor *) actor)->joy_control) {
                func_8080046C_chhillbilly(actor);
            } else {
                func_808004D0_chhillbilly(actor);
            }
            return 1;
        }
        break;
    case 0x42:
        result = func_808006B4_chhillbilly(actor, ((s16 *) &msg_data)[0], ((u8 *) &msg_data)[2]);
        break;
    case 0x8F:
        unk_0 = msg_data;
        if (unk_0 == 0 || unk_0 == 4) {
            func_808009D8_chhillbilly(actor, 0x78A, 0);
            ((HillbillyModel *) actor->unk0)->unk2A &= ~0x20;
        }
        result = 1;
        break;
    case 0x95:
        func_808009D8_chhillbilly(
            actor, (actor->unk70_10 == 0x16 || actor->unk70_10 == 0x10) ? 0x78A : 0x789, 1);
        result = _sucoaster_entrypoint_21(actor, msg, msg_data);
        break;
    case 0x38:
        func_80101074(D_80800B54_chhillbilly);
        return 7;
    default:
        result = _sucoaster_entrypoint_21(actor, msg, msg_data);
}

return result;

}

void func_80800894_chhillbilly();

s32 func_808006B4_chhillbilly(actor, param_1, param_2)
Actor *actor;
s32 param_1;
u32 param_2;
{
    switch (param_2) {
        case 0:
            if (actor->unk70_10 == 0x16)
                return 0;
            switch (param_1) {
                case 2:
                case 3:
                    func_80800894_chhillbilly(actor, actor->unk0->unk14 == 0x78A ? 0x16 : 0x15);
                    return 0;
                case 4:
                    func_80800894_chhillbilly(actor, 0x15);
                    return 0;
                case 5:
                case 8:
                case 9:
                case 18:
                    return 1;
                case 7:
                    _sucoaster_entrypoint_10(actor, 8);
            }
            break;
        case 2:
        case 7:
            func_80800894_chhillbilly(actor, 0x15);
            return 0;
        case 3:
            actor->unk6C_0 = func_800D9058(2.0f);
            func_8010297C(actor, actor->unk54, 70.0f, 120.0f);
            if (actor->unk70_10 == 8)
                func_80800894_chhillbilly(actor, 0x15);
            return 0;
        case 4:
            if (actor->unk0->unk14 == 0x789)
                return 1;
            break;
        case 1:
        case 6:
            return 1;
        case 5:
            func_80800894_chhillbilly(actor, 0xC);
            return 0;
        case 8:
            if (param_1 == 0x11) {
                func_808009D8_chhillbilly(actor, 0x78A, 0);
                func_801020DC(actor, 0);
            }
            ((u8 *) actor->unk0)[0x2A] &= ~0x20;
            return 1;
        case 9:
            if (((ActorFlags64 *) ((u8 *) actor + 0x64))->joy_control) {
                _sucoaster_entrypoint_10(actor, 2);
                return 0;
            }
            return 1;
    }

return 0;
}

void func_80800894_chhillbilly(u8 **actor, s32 state)
{
    char is_null;
    u8 **actor_copy;
    u8 *model;

switch (state) {
    case 0xC:
        func_80800348_chhillbilly(actor);
        // Matching: the extra copy of actor is needed for the match.
        actor_copy = actor;
        func_808009D8_chhillbilly(actor, 0x789, 0);
        func_8010A570(actor);
        _sucoaster_entrypoint_10(actor_copy, 0xC);
        // Matching: the is_null temporary and its empty test are needed for the match.
        is_null = !actor;
        model = *actor;
        if ((is_null && 1) && is_null) {
        }
        *(u8 *) ((s8 *) model + 0x2A) = *(u8 *) ((s8 *) model + 0x2A) | 0x20;
        return;

    case 0x15:
        _sucoaster_entrypoint_10(actor, 0x15);
        _sucoaster_entrypoint_6(actor, 0x43480000);
        return;

    case 0x16:
        _sucoaster_entrypoint_10(actor, 0x16);
}

}

void func_80800944_chhillbilly(Actor *actor)
{
    f32 unk_0[3];
    f32 pos[3];

if (actor->unk7C_12 && !func_8001210C(1)) {
    func_800EE88C(pos, _sucoaster_entrypoint_3(actor));
    func_800EE7F8(unk_0, pos);
    unk_0[1] -= 20.0f;
    func_800BBCB8(pos, unk_0, 0x3F800000, 3, D_80800CF0_chhillbilly);
}

}

// Swaps the model (0x789/0x78A) and sets the animation speed (0.75 / 1.0).
void func_808009D8_chhillbilly(actor, model_id, param_2) Actor *actor;
s32 model_id;
s32 param_2;
{
    if (param_2)
        func_801032B0(actor, (u16) model_id, actor->unk0->unk16);
    else
        func_80103140(actor, (u16) model_id, actor->unk0->unk16);

switch (model_id) {
    case 0x789:
        func_8010A3E8(actor, 0.75f);
        break;
    case 0x78A:
        func_8010A3E8(actor, 1.0f);
}

}

// TU-NOTE: the overlay .data is defined here in C (values from the ROM). Its tables point to
// functions of this file, and IDO's assembler schedules some of them differently otherwise.
// Externs are declared to match the object: D_80800C60_chhillbilly is int[],
// D_80800CB4_chhillbilly is s32[].
extern void func_80105834();
extern void _sucoaster_entrypoint_1();
extern void _sucoasterhit_entrypoint_0();
extern void func_80107C2C();
u32 D_80800B40_chhillbilly[5] = {0x160001, 0xE0001, 0xD0001, 0x100001, 0x160001};
u8 D_80800B54_chhillbilly[84] = {0x0, 0x0, 0x0, 0x2A, 0x3F, 0xA0, 0x0,  0x0,  0x0, 0x2B, 0x0, 0x0,
                                 0x0, 0x0, 0x0, 0x1E, 0x3F, 0xA6, 0x66, 0x66, 0x2, 0x1C, 0x0, 0x0,
                                 0x0, 0x0, 0x0, 0x10, 0x3F, 0xA6, 0x66, 0x66, 0x2, 0xE,  0x0, 0x0,
                                 0x0, 0x0, 0x0, 0x1C, 0x3F, 0xA6, 0x66, 0x66, 0x1, 0xE,  0x0, 0x0,
                                 0x0, 0x0, 0x0, 0x14, 0x3F, 0x99, 0x99, 0x9A, 0x2, 0x18, 0x0, 0x0,
                                 0x0, 0x0, 0x0, 0x6,  0x3F, 0x99, 0x99, 0x9A, 0x2, 0xA,  0x0, 0x0,
                                 0x0, 0x0, 0x0, 0x1,  0x3F, 0xC0, 0x0,  0x0,  0x1, 0x12, 0x0, 0x0};
u32 D_80800BA8_chhillbilly[46] = {
    0x0,        0x0,       0x3F19999A, 0x21D0001, 0x3F19999A, 0x21D0001, 0x3FC00000, 0x21A0001,
    0x3F800000, 0x21A0001, 0x3FC00000, 0x21A0001, 0x3FC00000, 0x21A0001, 0x0,        0x0,
    0x3FC00000, 0x21A0001, 0x3F99999A, 0x3E10002, 0x3FC00000, 0x21A0001, 0x3F000000, 0x3E20002,
    0x3FB33333, 0x21B0002, 0x3FB33333, 0x21B0084, 0x3F19999A, 0x21D0001, 0x3FC00000, 0x21A0020,
    0x0,        0x0,       0x3F8CCCCD, 0x21C0001, 0x3FC00000, 0x21A0001, 0x3F666666, 0x2180002,
    0x3F8CCCCD, 0x2190002, 0x3F4CCCCD, 0x21A0001, 0x3F8CCCCD, 0x21C0001};
int D_80800C60_chhillbilly[18] = {0x1A10150,
                                  0x78A0016,
                                  (u32) &D_80800BA8_chhillbilly,
                                  (u32) func_80800064_chhillbilly,
                                  (u32) func_80105834,
                                  (u32) func_80800298_chhillbilly,
                                  0xBB80000,
                                  0x3F800000,
                                  0x0,
                                  0x43050361,
                                  (u32) _sucoaster_entrypoint_1,
                                  (u32) _sucoasterhit_entrypoint_0,
                                  0x0,
                                  (u32) func_8080000C_chhillbilly,
                                  (u32) func_80107C2C,
                                  -0x7BCDABE3,
                                  (u32) func_80800540_chhillbilly,
                                  (u32) &D_80800B40_chhillbilly};
u8 D_80800CA8_chhillbilly[12] = {0x0, 0x13, 0x4, 0xCF, 0x0, 0xD, 0x0, 0xF3, 0x1, 0xC, 0x0, 0x0};
s32 D_80800CB4_chhillbilly[15] = {0x1D078A, 0x270064, 0xC800C8,  0x190001B, -0x31F02BC,
                                  0x150000, 0x66002B, 0x3000400, 0x2CFF6A,  0x12CFF6A,
                                  0x960190, 0x960007, 0x30004,   0x800016,  0x1820000};
s32 D_80800CF0_chhillbilly[16] = {0x1D06A4, 0x161182, 0x1BFDA8, -0x257FFD9, -0x2570258, 0x2580258,
                                  0x2D0096, 0xC80022, 0xC0019,  0x0,        0x2B0099,   0xCC0015,
                                  0xB3,     0xB0032,  0x3CFFF6, -0x140000};
