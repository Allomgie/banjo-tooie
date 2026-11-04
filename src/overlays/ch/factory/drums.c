#include "common.h"

extern s32 _subaddiefind_entrypoint_4(s32, Actor **, s32);
extern s32 func_800CC338(f32 *, s32, s32);
extern void func_800EE7F8(f32 *, f32 *);
typedef struct FactoryDrumFlags {
    u32 pad_0 : 2;
    u32 stick_driven : 1;
    u32 pad_1 : 29;
} FactoryDrumFlags;
extern f32 func_800DC178(f32, f32);
extern u8 D_808011CC_chfactorydrums[];
extern void func_800BBCB8(s32, s32, f32, s32, void *);
extern s32 D_80801208_chfactorydrums[];
extern void func_80101CDC(Actor *, f32);
extern int D_8080125C_chfactorydrums[];
typedef struct {
    u8 pad_0[0x64];
    u32 pad_1 : 2;
    u32 stick_driven : 1;
    u32 pad_2 : 29;
    u8 pad_3[0x10];
    u32 pad_4 : 29;
    u32 unk_78 : 1;
    u32 pad_5 : 2;
} FactoryDrumStateFlags;
extern void func_8010C93C(s32, s32, f32);
extern void func_800C4140(s32, f32 *, s32);
extern f32 _subaddiejoy_entrypoint_3(Actor *);
extern f32 func_800D8FF8(void);
extern f32 func_800F1198(f32, f32, f32, f32, f32);
extern f32 func_800F15F8(f32, f32, f32);
extern f32 func_800F10B4(f32, f32, f32, f32, f32);
extern f32 func_800F1214(f32, f32, f32);
extern f32 func_800F3780(f32, f32 *, s32);
extern f32 func_80101F24(Actor *);
extern f32 func_8010CD50(Actor *, s32);
extern void *func_80100094(Actor *, u32);
extern s32 _subaddieaudioquick_entrypoint_3(Actor *, f32 *, void *, f32);
extern void _subaddieaudioloop_entrypoint_0(Actor *, f32);
extern void func_80102BAC(Actor *, f32, f32, f32);
extern void _subaddierouteDll_entrypoint_7(Actor *, void *, f32, f32, f32, s32);
extern void _subaddierouteDll_entrypoint_5(Actor *, void *, s32, f32, f32, f32);
extern void func_8010C3A8(Actor *, u32, f32);
extern void func_801026CC(Actor *, Vec3f, f32);
extern s32 func_80101E14(Actor *, f32);
extern u8 D_80801250_chfactorydrums[];
extern u8 D_80801044_chfactorydrums[];
extern Actor *func_80108528(s32, f32 *, s32, Actor **);
extern f32 func_80103EF4(Actor *);
extern void func_80101870(), func_80105834(), func_80107C2C(), func_80108ED0();

// TU-NOTE: the .data of this overlay is defined in C at the end of the file. Its tables point to
// functions of this file; IDO's assembler schedules some of them differently unless the tables are
// in the same unit. The extern declarations of D_80801208 (s32[]) and D_8080125C (int[]) match the object.

// Returns nonzero while the zone has fewer active drums than the cap allows.
s32 func_80800000_chfactorydrums(Actor *drum)
{
    s32 count;
    Actor *actors[9];
    s32 found;
    s32 i;

    count = 0;
    found = _subaddiefind_entrypoint_4(0x3FF, actors, 10);
    for (i = 0; i < found; i++) {
        if (func_800CC338(actors[i]->position, (*(u32 *) ((u8 *) drum + 0x70) >> 25) - 1,
                          ((*(u32 *) ((u8 *) drum + 0x70) << 22) >> 26) - 1)) {
            count++;
        }
    }
    found = _subaddiefind_entrypoint_4(0x3F0, actors, 10);
    for (i = 0; i < found; i++) {
        if (actors[i]->unk70_10 == 5 &&
            func_800CC338(actors[i]->position, (*(u32 *) ((u8 *) drum + 0x70) >> 25) - 1,
                          ((*(u32 *) ((u8 *) drum + 0x70) << 22) >> 26) - 1)) {
            count++;
        }
    }
    return count < (s32) drum->unk74_7 - 0x32;
}

// Returns 1 if no other active drum is on the same side of the player (dot product test).
s32 func_80800130_chfactorydrums(Actor *drum)
{
    Actor *drums[10];
    s32 found;
    s32 i;
    s32 result;
    f32 player_pos[3];
    f32 drum_vec[3];
    f32 other_vec[3];
    result = 1;
    found = _subaddiefind_entrypoint_4(0x3F0, drums, 10);
    for (i = 0; i < found; i++) {
        if ((drums[i]->unk70_10 == 3 || drums[i]->unk70_10 == 5) &&
            drum != drums[i]) {
            func_800F5A00(func_800F54E4(), player_pos);
            func_800EE7F8(other_vec, drums[i]->position);
            func_800EE7F8(drum_vec, drum->position);
            func_800EF3DC(other_vec, player_pos);
            func_800EF3DC(drum_vec, player_pos);
            func_800EF2A0(other_vec);
            func_800EF2A0(drum_vec);
            result &= ((other_vec[0] * drum_vec[0] + other_vec[1] * drum_vec[1]) +
                        other_vec[2] * drum_vec[2]) <= 0.0f;
            if (result == 0)
                return 0;
        }
    }
    return result;
}

// Wake-up check: after a random 3-5 s timer, switch to state 5 if the zone cap allows it.
void func_808002B8_chfactorydrums(Actor *drum)
{
    if (((FactoryDrumFlags *) ((u8 *) drum + 0x64))->stick_driven) {
        if (func_8001210C(7) && drum->unk74_7 != 0x32) {
            if (func_80800000_chfactorydrums(drum) && _subaddiejoy_entrypoint_6(drum, 1)) {
                func_80102424(drum, 5);
            }
        }
    } else if (func_800D90A4(&drum->unk58) && func_8001210C(7)) {
        if (drum->unk74_7 != 0x32 && func_80800000_chfactorydrums(drum)) {
            func_80102424(drum, 5);
        }
        drum->unk58 = func_800DC178(3.0f, 5.0f);
    }
}

int func_808003A8_chfactorydrums(actor)
s32 actor;
{
    s32 route;
    route = func_80100094(actor, 0);
    // Matching: `| 0` is needed for the match.
    _subaddierouteDll_entrypoint_3(actor, route | 0, actor + 4);
}

void func_80800CD0_chfactorydrums();

extern s32 func_800BABB8(s32, f32 *, f32 *, f32, void *);

void func_808003DC_chfactorydrums(Actor *drum)
{
    extern Vec3f D_8080108C_chfactorydrums;
    extern u8 D_80801080_chfactorydrums[];
    extern u8 D_80801098_chfactorydrums[];
    extern f32 D_808010B0_chfactorydrums[];
    extern Vec3f D_808010E0_chfactorydrums;
    extern u8 D_808010EC_chfactorydrums[];
    extern u8 D_80801134_chfactorydrums[];
    extern u8 D_8080117C_chfactorydrums[];
    extern u8 D_808011B8_chfactorydrums[];
    extern void _chfactorydrums_entrypoint_0(void);
    extern void _chfactorydrums_entrypoint_1(void);

    Vec3f dir;
    f32 value;
    char *ptr;
    s32 fx_0;
    s32 fx_1;
    s32 fx_2;
    f32 unk_0;
    s32 moving;

    if (drum->unk70_10 != 7) {
        func_8010C93C(drum, drum->position, 0.5f);
    }

    if (((FactoryDrumStateFlags *) drum)->unk_78) {
        return;
    }

    switch (drum->unk70_10) {
        case 1:
            if (((FactoryDrumStateFlags *) drum)->stick_driven) {
                value = _subaddiejoy_entrypoint_3(drum);

                if (value >= 0.1f) {
                    func_80800CD0_chfactorydrums(drum, 2);
                }

                func_808002B8_chfactorydrums(drum);
                return;
            }

            if (func_800D90A4((char *) drum + 0x58) && func_8010C500(drum) &&
                func_80800130_chfactorydrums(drum)) {
                func_80800CD0_chfactorydrums(drum, 2);
            }
            break;

        case 2:
            _subaddieaudioquick_entrypoint_3(drum, (char *) drum + 4,
                                             D_80801098_chfactorydrums, 0.5f);

            if (func_80101DDC(drum)) {
                func_80800CD0_chfactorydrums(drum, 3);

                *(f32 *) ((char *) drum + 0x58) = func_800DC178(3.0f, 5.0f);
            }

            if (((FactoryDrumStateFlags *) drum)->stick_driven) {
                _subaddiejoy_entrypoint_3(drum);

                func_80102BAC(drum, 1.5f, 1.0f, 20.0f);
            }
            break;

        case 3:
            dir = D_8080108C_chfactorydrums;

            if (func_80101E4C(drum, &dir)) {
                func_800C4140(((u16) (u32) (func_800DC178(1.0f, 1.1f) * 1023.0f) << 21) + 0xFA45A,
                              (char *) drum + 4, 0x4B000FA);
            }

            if (((FactoryDrumStateFlags *) drum)->stick_driven) {
                value = _subaddiejoy_entrypoint_3(drum);

                func_80102BAC(drum, 1.5f, 1.0f, 20.0f);

                // Possessed: the stick drives the speed.
                *(f32 *) ((char *) drum + 0x24) = value * 600.0f;

                func_8010BA80(drum, 0x201015, 0x20);

                unk_0 = func_800F1198(*(f32 *) ((char *) drum + 0x24), 500.0f, 600.0f,
                                        0.467000008f, 0.350250006f);

                func_80101CDC(drum, unk_0);
                func_808002B8_chfactorydrums(drum);
                return;
            }

            ptr = (char *) func_80100094(drum, 0);

            if (_subaddierouteDll_entrypoint_4(drum)) {
                if (func_8010C500(drum) && func_80800130_chfactorydrums(drum)) {
                    *(f32 *) ((char *) drum + 0x54) = func_8010CD50(drum, func_800F54E4());
                } else {
                    func_80800CD0_chfactorydrums(drum, 4);
                }

                _subaddierouteDll_entrypoint_7(drum, ptr, *(f32 *) ((char *) drum + 0x48),
                                               *(f32 *) ((char *) drum + 0x54), 200.0f, 0x4802);

                drum->unk6C_0 = *(u16 *) (ptr + 6);
            }

            *(f32 *) ((char *) drum + 0x24) =
                func_800F15F8(*(f32 *) ((char *) drum + 0x24),
                              *(f32 *) ((char *) drum + 0x50), func_800D8FF8() * 500.0f);

            _subaddierouteDll_entrypoint_5(drum, ptr, drum->unk6C_0, 0.3f, 1.0f, 200.0f);

            unk_0 = func_800F3780(func_80101F24(drum), D_808010B0_chfactorydrums, 6);

            func_8010C3A8(drum, 0x305425, unk_0);

            func_801026CC(drum, D_808010E0_chfactorydrums, *(f32 *) ((char *) drum + 0x24));

            func_808002B8_chfactorydrums(drum);
            break;

        case 4:
            _subaddieaudioquick_entrypoint_3(drum, (char *) drum + 4,
                                             D_80801098_chfactorydrums, 0.5f);

            if (func_80101DDC(drum)) {
                if (((FactoryDrumStateFlags *) drum)->unk_78) {
                    return;
                }

                *(f32 *) ((char *) drum + 0x58) = 1.5f;
                func_80800CD0_chfactorydrums(drum, 1);
            }
            break;

        case 5:
            moving = func_80101F24(drum) > 0.3f && func_80101F24(drum) < 1.0f;
            _subaddieaudioloop_entrypoint_4(drum, (char *) drum + 4, moving,
                                            D_80801080_chfactorydrums);

            value = func_80101F24(drum);

            value = func_800F10B4(value, 0.3f, 1.0f, 0.0f, 1.0f);

            value = func_800F1214(value, 1.2f, 0.9f);

            _subaddieaudioloop_entrypoint_0(drum, value);

            if (func_80101E14(drum, 0.5f)) {
                func_80108B04(drum, 0);
                return;
            }

            if (func_80101DDC(drum)) {
                _subaddieaudioloop_entrypoint_2(drum);

                if (((FactoryDrumStateFlags *) drum)->stick_driven) {
                    func_80800CD0_chfactorydrums(drum, 3);
                    return;
                }

                if (func_8010C500(drum)) {
                    func_80800CD0_chfactorydrums(drum, 3);
                } else {
                    func_80800CD0_chfactorydrums(drum, 4);
                }
            }
            break;

        case 6:
            ptr = (char *) drum + 4;

            fx_0 = func_800B53A4(2);
            fx_1 = func_800B53A4(2);
            fx_2 = func_800B53A4(6);

            func_800BABB8(fx_0, ptr, ptr, 1.0f, D_8080117C_chfactorydrums);

            func_800BA670(fx_0, 0x88C);
            func_800BA4D0(fx_0, (s16) (*(f32 *) ((char *) drum + 8) + 35.0f));
            func_800BA22C(fx_0, 2);

            func_800BABB8(fx_1, ptr, ptr, 1.0f, D_8080117C_chfactorydrums);

            func_800BA670(fx_1, 0x88D);
            func_800BA4D0(fx_1, (s16) (*(f32 *) ((char *) drum + 8) + 35.0f));
            func_800BA22C(fx_1, 2);

            func_800BABB8(fx_2, ptr, ptr, 1.0f, D_8080117C_chfactorydrums);

            func_800BA670(fx_2, 0x88B);

            func_800BA544(fx_2, drum->unk74_7 != 0x32 ? _chfactorydrums_entrypoint_0
                                                            : _chfactorydrums_entrypoint_1);

            func_800BA4D0(fx_2, (s16) (*(f32 *) ((char *) drum + 8) + 35.0f));
            func_800BA22C(fx_2, 6);

            _subaddieaudioquick_entrypoint_2(drum, ptr, D_808011B8_chfactorydrums);

            if (drum->unk74_7 != 0x32) {
                if (func_80800000_chfactorydrums(drum)) {
                    func_80108B04(drum, 0);
                }

                func_800BBCB8(ptr, 0, drum->scale, 3, D_80801134_chfactorydrums);
            } else {
                func_800BBCB8(ptr, 0, drum->scale, 3, D_808010EC_chfactorydrums);
            }

            func_80800CD0_chfactorydrums(drum, 7);

        case 9:
            break;
    }
}

void chfactorydrums_entrypoint_0(s32 param_0, s32 param_1)
{
    func_800BBCB8(param_1, 0, 1.0f, 1, D_808011CC_chfactorydrums);
}

void chfactorydrums_entrypoint_1(s32 param_0, s32 param_1)
{
    func_800BBCB8(param_1, 0, 1.0f, 1, &D_80801208_chfactorydrums);
}

// Per-state setup, then switches the actor to the new state.
void func_80800CD0_chfactorydrums(Actor *drum, s32 state)
{
    switch (state) {
        case 1:
            func_8010A590(drum);
            drum->unk64_16 = 1;
            drum->unk58 = func_800DC178(0.5f, 2.0f);
            *(f32 *) &drum->actorData[3] = 0.0f;
            break;
        case 3:
            func_80101CDC(drum, 0.467f);
            *(f32 *) &drum->actorData[3] = 0.0f;
            drum->unk50 = 500.0f;
            break;
        case 7:
            func_80107070(drum, 3);
    }
    func_80102424(drum, state);
}

s32 func_80800D90_chfactorydrums(drum, msg, msg_arg)
Actor *drum;
s32 msg;
s32 msg_arg;
{
    Actor *spawned;

    switch (msg) {
        case 0x3E:
        case 0x3F:
            // Hit.
            if (!((FactoryDrumStateFlags *) drum)->stick_driven &&
                !((FactoryDrumStateFlags *) drum)->unk_78) {
                func_80800CD0_chfactorydrums(drum, 4);
            }
            if (drum->unk70_10 != 4) {
                func_800C4140(0x7FEFA417, drum->position, 0x04B000FA);
            }
            return 1;
        case 0x40:
            // Break apart.
            func_80800CD0_chfactorydrums(drum, 6);
            return 1;
        case 1:
            // Possess.
            func_80800CD0_chfactorydrums(drum, 2);
            return 1;
        case 2:
            // Release.
            func_80800CD0_chfactorydrums(drum, 8);
            return 1;
        case 0x3D:
            // Deferred message from the attack animation: spawn actor 0x3FF.
            spawned = func_80108528(0x3FF, drum->position, 0, &drum);
            spawned->position[1] += func_80103EF4(drum);
            return 1;
        case 0x38:
            func_80101074(D_80801044_chfactorydrums);
            return 5;
        case 0x95:
            _subaddierouteDll_entrypoint_1(drum);
            if (drum->unk74_7 == 0x32) {
                func_80103140(drum, 0x7D0, *(u16 *) ((u8 *) drum->unk0 + 0x16));
            }
            func_80800CD0_chfactorydrums(drum, 1);
            return 1;
        case 0x97:
            // Attach point.
            func_80101010(D_80801250_chfactorydrums);
            return 1;
        default:
            return 0;
    }
}

int chfactorydrums_entrypoint_2(void)
{
    return (int) &D_8080125C_chfactorydrums;
}

u8 D_80800FE0_chfactorydrums[20] = {0x0, 0x1, 0x0, 0x0, 0x0, 0x8, 0x0, 0x0, 0x0, 0x8,
                                    0x0, 0x0, 0x0, 0x7, 0x0, 0x0, 0x0, 0x9, 0x0, 0x0};
u8 D_80800FF4_chfactorydrums[80] = {
    0x0,  0x0,  0x0,  0x0,  0x0, 0x0,  0x0, 0x0,  0x3E, 0xEF, 0x1A, 0xA0, 0x2, 0xAC, 0x0, 0x44,
    0x3E, 0xEF, 0x1A, 0xA0, 0x2, 0xAC, 0x0, 0x42, 0x3E, 0x92, 0xF1, 0xAA, 0x2, 0xA7, 0x0, 0x1,
    0x3E, 0xEF, 0x1A, 0xA0, 0x2, 0xAC, 0x0, 0x92, 0x3F, 0x28, 0xF5, 0xC3, 0x2, 0xAB, 0x0, 0x42,
    0x3F, 0x28, 0xF5, 0xC3, 0x2, 0xAB, 0x0, 0x42, 0x3F, 0x28, 0xF5, 0xC3, 0x2, 0xAB, 0x0, 0x62,
    0x3E, 0xEF, 0x1A, 0xA0, 0x2, 0xAC, 0x0, 0x44, 0x3E, 0xEF, 0x1A, 0xA0, 0x2, 0xAC, 0x0, 0x44};
u8 D_80801044_chfactorydrums[60] = {
    0x0, 0x0,  0x0,  0x3,  0x40, 0x19, 0x99, 0x9A, 0x1,  0x1,  0x0,  0x0,  0x0,  0x0,  0x0,
    0x1, 0x40, 0x19, 0x99, 0x9A, 0x1,  0x12, 0x0,  0x0,  0x0,  0x0,  0x0,  0xA,  0x3F, 0xC0,
    0x0, 0x0,  0x2,  0x3,  0x0,  0x0,  0x0,  0x0,  0x0,  0x18, 0x3F, 0xC0, 0x0,  0x0,  0x2,
    0x3, 0x0,  0x0,  0x0,  0x0,  0x0,  0x2A, 0x3F, 0x99, 0x99, 0x9A, 0x2,  0x6C, 0x0,  0x0};
u8 D_80801080_chfactorydrums[12] = {0x0,  0x13, 0x4, 0xDC, 0x0, 0x16,
                                    0x36, 0xB0, 0x0, 0x0,  0x0, 0x0};
Vec3f D_8080108C_chfactorydrums = {0.0f, 0.5f, -1.0f};
u8 D_80801098_chfactorydrums[24] = {0x0, 0x13, 0x4,  0xD5, 0x0, 0x16, 0x3E, 0x80,
                                    0x0, 0xD,  0x0,  0xCC, 0x0, 0xE6, 0x0,  0x1,
                                    0x0, 0xC8, 0x17, 0x70, 0x0, 0x0,  0x0,  0x0};
f32 D_808010B0_chfactorydrums[12] = {0.0f, 0.2f, 0.15f, 1.0f, 0.35f, 0.8f,
                                     0.5f, 0.2f, 0.65f, 1.0f, 0.85f, 0.8f};
Vec3f D_808010E0_chfactorydrums = {1.1f, -0.0014f, 0.35f};
u8 D_808010EC_chfactorydrums[72] = {
    0x0,  0x1D, 0x9,  0xC9, 0x0,  0x16, 0x10, 0x0,  0x0,  0x2B, 0x1,  0x80, 0x3,  0x0,  0x0,
    0x22, 0x0,  0x80, 0x1,  0x0,  0x5,  0x0,  0xA,  0x0,  0x0,  0x15, 0x0,  0x33, 0x0,  0x4C,
    0x0,  0x19, 0x0,  0x0,  0x0,  0x7,  0x0,  0x2C, 0xFF, 0xD8, 0x0,  0x32, 0xFF, 0xD8, 0x0,
    0x28, 0x0,  0x96, 0x0,  0x28, 0x0,  0x20, 0xFF, 0xFF, 0xFF, 0x50, 0x0,  0xA,  0xFF, 0xD8,
    0x0,  0x0,  0xFF, 0xD8, 0x0,  0x28, 0x0,  0xC8, 0x0,  0x28, 0x0,  0x0};
u8 D_80801134_chfactorydrums[72] = {
    0x0,  0x1D, 0x9,  0xD0, 0x0,  0x16, 0x10, 0x0,  0x0,  0x2B, 0x1,  0x80, 0x3,  0x0,  0x0,
    0x22, 0x0,  0x80, 0x1,  0x0,  0x5,  0x0,  0xA,  0x0,  0x0,  0x15, 0x0,  0x33, 0x0,  0x4C,
    0x0,  0x19, 0x0,  0x0,  0x0,  0x7,  0x0,  0x2C, 0xFF, 0xD8, 0x0,  0x32, 0xFF, 0xD8, 0x0,
    0x28, 0x0,  0x96, 0x0,  0x28, 0x0,  0x20, 0x0,  0xF0, 0x3,  0x50, 0x0,  0xA,  0xFF, 0xD8,
    0x0,  0x0,  0xFF, 0xD8, 0x0,  0x28, 0x0,  0xC8, 0x0,  0x28, 0x0,  0x0};
u8 D_8080117C_chfactorydrums[60] = {
    0x0,  0x14, 0x0,  0x16, 0x14, 0x6,  0x0,  0x2B, 0x2,  0x0,  0x3,  0x0,  0x0, 0x2D, 0x2,
    0x58, 0x3,  0x20, 0x0,  0x1B, 0xF4, 0x48, 0xF6, 0x3C, 0x0,  0x23, 0x1,  0x0, 0x0,  0x31,
    0xFF, 0xEC, 0xFF, 0xFB, 0x0,  0xB,  0x0,  0x19, 0x0,  0x19, 0x0,  0x32, 0x0, 0x0,  0x0,
    0x15, 0x0,  0x0,  0x0,  0xB3, 0x0,  0x4,  0x0,  0x8C, 0x0,  0x7,  0x0,  0x4, 0x0,  0x0};
u8 D_808011B8_chfactorydrums[20] = {0x0, 0x13, 0x4,  0xC8, 0x0, 0x16, 0x5D, 0xC0, 0x0, 0x1,
                                    0x0, 0xC8, 0x17, 0x70, 0x0, 0xA,  0x1,  0x4C, 0x0, 0x0};
u8 D_808011CC_chfactorydrums[60] = {
    0x0,  0x1D, 0x9,  0xD0, 0x0,  0x16, 0x10, 0x0,  0x0,  0x2B, 0x1,  0x80, 0x2,  0x0,  0x0,
    0x22, 0x0,  0x80, 0x1,  0x0,  0x5,  0x0,  0xA,  0x0,  0x0,  0x15, 0x0,  0x0,  0x0,  0x4C,
    0x0,  0x19, 0x0,  0x0,  0x0,  0x7,  0x0,  0x2C, 0xFF, 0xD8, 0x0,  0x32, 0xFF, 0xD8, 0x0,
    0x28, 0x0,  0x96, 0x0,  0x28, 0x0,  0x20, 0x0,  0xF0, 0x3,  0x50, 0x0,  0x0,  0x0,  0x0};
s32 D_80801208_chfactorydrums[18] = {0x1D09C9, 0x161000, 0x2B0180, 0x3000022, 0x800100, 0x5000A00,
                                     0x150033, 0x4C0019, 0x7,      0x2CFFD8,  0x32FFD8, 0x280096,
                                     0x280020, -0xB0,    0xAFFD8,  0xFFD8,    0x2800C8, 0x280000};
u8 D_80801250_chfactorydrums[12] = {0x0, 0x0, 0x0, 0x0, 0x43, 0x7A, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0};
int D_8080125C_chfactorydrums[21] = {0x11503F0,
                                     0x7CF0001,
                                     (u32) &D_80800FF4_chfactorydrums,
                                     (u32) func_808003DC_chfactorydrums,
                                     (u32) func_80105834,
                                     (u32) func_80101870,
                                     0xBB80000,
                                     0x3FC00000,
                                     0x0,
                                     0x43850221,
                                     0x0,
                                     (u32) func_80108ED0,
                                     0xC0000,
                                     (u32) func_808003A8_chfactorydrums,
                                     (u32) func_80107C2C,
                                     -0x7FFDABE3,
                                     (u32) func_80800D90_chfactorydrums,
                                     (u32) &D_80800FE0_chfactorydrums,
                                     0x0,
                                     0x0,
                                     0x0};
