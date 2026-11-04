// Probably a crystal enemy: idles on a route, chases and rams the player when close and
// visible, returns to its route, and shatters into pieces on death.
#include "common.h"

extern int D_80800664_chcrystalbaddie[];
typedef union {
    s32 value;
    Actor *ptr;
} CrystalMessage1410;
extern f32 func_800DC178(f32, f32);
extern void func_80102424();
typedef struct {
    u8 pad[0x64];
    u8 pad64 : 7;
    u8 flag : 1;
} CrystS;
extern void _subaddiejoy_entrypoint_10(CrystS *, f32, f32);
extern void _chexploder_entrypoint_4(CrystS *, s32, s32);
extern int D_808006CC_chcrystalbaddie[];
extern int D_808006BC_chcrystalbaddie[];
extern u8 D_808006AC_chcrystalbaddie[];
extern void *func_80100094(Actor *, u32);
extern u8 func_800D9078(f32 *);
extern void func_8010D254(f32 *);
extern f32 _subaddiejoy_entrypoint_9(Actor *, f32 *, s32);
extern f32 func_80102D78(Actor *, void *);
extern f32 func_800D8FF8(void);
extern f32 func_800F15F8(f32, f32, f32);
extern void func_80102BF8(Actor *, f32, f32, f32);
extern void func_8010C3A8(Actor *, s32, f32);
extern void _subaddierouteDll_entrypoint_7(Actor *, void *, f32, f32, f32, s32);
extern void _subaddierouteDll_entrypoint_5(Actor *, void *, s32, f32, f32, f32);
extern int func_800DC298(f32);
typedef struct {
    u32 pad_0 : 2;
    u32 alerted : 1;
    u32 pad_1 : 29;
} Broad51CrystalFlags;
void func_808004D4_chcrystalbaddie();
void func_8080052C_chcrystalbaddie();

int chcrystalbaddie_entrypoint_0()
{
    return (int) &D_80800664_chcrystalbaddie;
}

void func_8080000C_chcrystalbaddie(u8 *actor)
{
    _subaddierouteDll_entrypoint_3(actor, func_80100094(actor, 0), actor + 4);
    *(f32 *) (actor + 0x2C) = 0.0f;
    *(f32 *) (actor + 0x24) = 0.0f;
}

void func_808004B4_chcrystalbaddie();

void func_808003C4_chcrystalbaddie();

void func_80800054_chcrystalbaddie(Actor *actor)
{
    u8 *route;
    f32 unk_1;
    route = func_80100094(actor, 0);
    // States: 1 idle, 2 wait, 3 route/chase, 4 back to idle.
    func_8010D254((f32 *) actor->actorData);
    func_800D9078(&actor->unk58);
    switch (actor->unk70_10) {
        case 1:
            if (((Broad51CrystalFlags *) ((u8 *) actor + 0x64))->alerted) {
                func_808003C4_chcrystalbaddie(actor, 2);
            } else if (func_80800424_chcrystalbaddie(actor)) {
                func_808003C4_chcrystalbaddie(actor, 2);
            }
            break;
        case 2: {
            extern void _subaddieaudioquick_entrypoint_3(Actor *, f32 *, void *, f32);
            _subaddieaudioquick_entrypoint_3(actor, actor->position, D_808006AC_chcrystalbaddie,
                                             0.0f);
        }
            if (func_80101DDC(actor)) {
                func_808003C4_chcrystalbaddie(actor, 3);
            }
            break;
        case 3:
            if (((Broad51CrystalFlags *) ((u8 *) actor + 0x64))->alerted) {
                unk_1 = _subaddiejoy_entrypoint_9(actor, &actor->unk54, 3);
                *(f32 *) ((u8 *) actor + 0x24) = *(f32 *) ((u8 *) actor + 0x2C);
                func_80102BF8(actor, 0.2f, 8.0f, 500.0f);
                func_8010C3A8(actor, 0x205015, unk_1);
            } else {
                if (_subaddierouteDll_entrypoint_4(actor)) {
                    actor->unk54 = func_80102D78(actor, (f32 *) actor->actorData);
                    _subaddierouteDll_entrypoint_7(actor, route, actor->rotation[1],
                                                   actor->unk54, 200.0f, 0x5800);
                    *(s32 *) (route + 0xC) = *(u16 *) (route + 6);
                }
                _subaddierouteDll_entrypoint_5(actor, route, *(s32 *) (route + 0xC), 0.15f,
                                               8.0f, 200.0f);
                *(f32 *) ((u8 *) actor + 0x24) =
                    func_800F15F8(*(f32 *) ((u8 *) actor + 0x24),
                                  *(f32 *) ((u8 *) actor + 0x2C), func_800D8FF8() * 400.0f);
                func_8010B990(actor, 0x305115);
                // Give up if the player is farther than 1200 units or not visible.
                if (_subaddierouteDll_entrypoint_4(actor) && func_800DC298(0.2f) &&
                    (!func_8010C9B0(actor->position, 1200) || !func_8010C500(actor))) {
                    func_808003C4_chcrystalbaddie(actor, 4);
                }
            }
            func_808004B4_chcrystalbaddie((s32) actor);
            break;
        case 4:
            if (func_80101DDC(actor)) {
                func_808003C4_chcrystalbaddie(actor, 1);
                actor->unk58 = 1.4f;
            }
    }
}

int func_808002E0_chcrystalbaddie(Actor *actor, s32 message, CrystalMessage1410 msg_data)
{
    switch (message) {
        case 0x90: // death: shatter
            func_8080052C_chcrystalbaddie(actor);
            break;
        case 0x40:
            func_808004D4_chcrystalbaddie(actor, msg_data.ptr);
            break;
        case 2:
            if (!_subaddieDll_entrypoint_3(actor)) {
                func_80107070(actor, 1);
            }
            break;
        case 0x95:
            _subaddierouteDll_entrypoint_1(actor);
            break;
        default:
            return 0;
    }
    return 1;
}

void func_80800384_chcrystalbaddie(s32 actor)
{
}

s32 func_8080038C_chcrystalbaddie(s32 actor, s32 unk_1)
{
    func_800DF744(3, 1);
    func_80101870(actor, unk_1);
}

void func_808003C4_chcrystalbaddie(u8 *actor, s32 state)
{
    func_80102424(actor, state);
    switch (state) {
        case 1:
            break;
        case 3:
            *(f32 *) (actor + 0x2C) = func_800DC178(400.0f, 450.0f);
            *(f32 *) (actor + 0x24) = 0.0f;
    }
}

int func_80800424_chcrystalbaddie(f32 actor[3])
{
    // Cooldown still running.
    if (actor[0x16] > 0.0f) {
        return 0;
    }
    if (_subaddierouteDll_entrypoint_4(actor) && func_8010C9B0(&actor[1], 0x4B0) != 0 &&
        _suchase_entrypoint_1(actor) != 0 && func_8010C500(actor) != 0) {
        return 1;
    }
    return 0;
}

void func_808004B4_chcrystalbaddie(s32 actor)
{
    func_80105230(actor, 0);
}

void func_808004D4_chcrystalbaddie(actor, message_data) CrystS *actor;
s32 *message_data;
{
    _subaddiejoy_entrypoint_10(actor, 1.0f, 0.3f);
    _chexploder_entrypoint_4(actor, *message_data + 4, 4);
    actor->flag = 0;
}

void func_8080052C_chcrystalbaddie(actor) s32 actor;
{
    s32 exploder;
    s32 unk_1;
    exploder = func_80106790(func_80101080());
    _chexploder_entrypoint_12(exploder, 0x14);
    _chexploder_entrypoint_14(exploder, 3);
    _chexploder_entrypoint_9(exploder, 2, 0);
    _chexploder_entrypoint_9(exploder, 3, 2);
    _chexploder_entrypoint_15(exploder, 2, 0x3F000000);
    unk_1 = exploder + 0x18;
    func_800BBCB8(unk_1, unk_1, 0x3F800000, 4, &D_808006CC_chcrystalbaddie);
    _subaddieaudioquick_entrypoint_2(actor, actor + 4, &D_808006BC_chcrystalbaddie);

if (func_80107070(actor, 3) == 0) {
    func_800FFAB0(actor);
}

}

// TU-NOTE: the overlay .data is defined here in C; its tables point to functions of this file,
// and IDO's assembler schedules them differently unless defined in the same unit.
extern void func_80105834();
extern void func_80108ED0();
extern void func_80107C2C();
u32 D_80800610_chcrystalbaddie[5] = {0x10000, 0x50000, 0x50000, 0x60000, 0x70000};
u32 D_80800624_chcrystalbaddie[16] = {
    0x0,        0x0,       0x3F19999A, 0x38D0044, 0x3F19999A, 0x38D004A, 0x3F0F5C29, 0x38E0401,
    0x3F19999A, 0x38D0092, 0x0,        0x0,       0x0,        0x0,       0x3F19999A, 0x38D0044};
int D_80800664_chcrystalbaddie[18] = {0x3040426,
                                      0x88F0001,
                                      (u32) &D_80800624_chcrystalbaddie,
                                      (u32) func_80800054_chcrystalbaddie,
                                      (u32) func_80105834,
                                      (u32) func_8080038C_chcrystalbaddie,
                                      0x7D00000,
                                      0x0,
                                      0x0,
                                      0x42840121,
                                      (u32) func_80800384_chcrystalbaddie,
                                      (u32) func_80108ED0,
                                      0x100000,
                                      (u32) func_8080000C_chcrystalbaddie,
                                      (u32) func_80107C2C,
                                      -0x7FCFAFE3,
                                      (u32) func_808002E0_chcrystalbaddie,
                                      (u32) &D_80800610_chcrystalbaddie};
u8 D_808006AC_chcrystalbaddie[16] = {0x0, 0x13, 0x5, 0xE9, 0x0,  0xD,  0x1, 0x8C,
                                     0x1, 0xA6, 0x0, 0x16, 0x36, 0xB0, 0x0, 0x0};
int D_808006BC_chcrystalbaddie[4] = {0x13048D, 0xD00F3, 0x10C0016, 0x6D600000};
int D_808006CC_chcrystalbaddie[13] = {0x1D09DD,  0x2D0064,  0xC8000B,  0x1E0028, -0x13FFB0,
                                      0x220133,  0x1660200, 0x2660015, 0x1900CC, 0x2B0100,
                                      0x1800000, 0x0,       0x0};
