// Humba Wumba's wigwam in Terrydactyland: entering warps to the small or big interior; Mumbo's
// spell grows or shrinks the wigwam.
#include "common.h"

extern void *func_80100094(Actor *, u32);
extern void func_800EE7F8(f32 *, f32 *);
extern void func_800DF500(f32, f32, f32);
extern u8 B_808011E4_chwumbawigwam[];
extern int D_8080116C_chwumbawigwam[];
extern u32 func_800F54E4(void);
extern s32 func_800F64A4(u32, s32);
extern f32 func_80103EAC(Actor *);
extern void func_800EFA4C(f32 *, f32, f32, f32);
extern void func_80103110(Actor *, s32);
extern void func_800F5A00(u32, f32 *);
extern f32 func_80103EF4(Actor *);
extern s32 func_800F00A4(f32 *, f32, f32, f32, f32 *);
extern f32 func_8010CD28(Actor *);
extern void _gcgoto_entrypoint_5(s32, s32, f32);
extern void _sumumbofx_entrypoint_6(void *, f32, f32, s32, s32, f32 *, f32 *, void *);
extern void _sumumbofx_entrypoint_14(void *);
extern s32 _sumumbofx_entrypoint_27(void *);
extern f32 _sumumbofx_entrypoint_21(void *);
extern void _sumumbofx_entrypoint_5(void *, f32);
extern f32 func_800F12D4(f32, f32, f32, f32, f32);
extern f32 func_800F10B4(f32, f32, f32, f32, f32);
extern f32 func_800F0E00(f32, f32);
extern f32 func_800138D0(f32);
extern f32 func_80013970(f32);
extern void _subaddieaudioquick_entrypoint_2(Actor *, f32 *, void *);
extern void func_800BBCB8(f32 *, f32 *, f32, s32, void *);
extern void func_800C4140(s32, f32 *, s32);
typedef struct {
    f32 xyz[3];
} WigwamPosition;
extern void _sumumbofx_entrypoint_24(void *, f32);
extern void _sumumbofx_entrypoint_15(void *, f32);
extern void _sumumbofx_entrypoint_18(void *, f32);
extern void _sumumbofx_entrypoint_17(void *, f32);
extern void _sumumbofx_entrypoint_16(void *, f32);
void func_80800B9C_chwumbawigwam();

// Picks wigwam scale from flag 0x18A and sets the state by player proximity.
void func_80800000_chwumbawigwam(Actor *actor)
{
    s32 pad0;
    f32 height;
    f32 radius_scale;
    f32 unit_scale;
    f32 radius;

    if (func_800EA05C() == 0x112) {
        if (func_800DA298(0x18A) && func_800EA05C() == 0x112)
            actor->scale = 2.8f;
        else
            actor->scale = 1.0f;
        radius = func_80103EAC(actor);
        radius_scale = func_800F64A4(func_800F54E4(), 0x40000) ? 1.0f : 0.6f;
        height = func_800F64A4(func_800F54E4(), 0x40000) ? 40.0f : actor->scale * 280.0f;
        if (func_8010C9FC(actor->position, (s32) (radius_scale * radius), (s32) height, 0)) {
            func_80800B9C_chwumbawigwam(actor, 2);
        } else {
            func_80800B9C_chwumbawigwam(actor, 3);
        }
        unit_scale = 1.0f;
        func_800EFA4C((f32 *) &actor->actorData[4], unit_scale, unit_scale, unit_scale);
    }
}

void func_80800158_chwumbawigwam(Actor *actor)
{
    extern WigwamPosition D_808010E0_chwumbawigwam;
    extern u8 D_808010EC_chwumbawigwam[];
    extern u8 D_80801100_chwumbawigwam[];
    extern u8 D_80801114_chwumbawigwam[];
    extern u8 D_80801158_chwumbawigwam[];

    f32 center_a[3];
    f32 center_b[3];

    switch (actor->unk70_10) {
        case 1:
            func_80103110(actor, 0);
            break;

        case 2:
            func_800F5A00(func_800F54E4(), center_a);

            if (!func_800F00A4(actor->position,
                               func_80103EAC(actor) *
                                   (func_800F64A4(func_800F54E4(), 0x40000) ? 1.0f : 0.6f),
                               func_800F64A4(func_800F54E4(), 0x40000) ? 40.0f
                                                                       : actor->scale * 280.0f,
                               0, center_a)) {
                func_80800B9C_chwumbawigwam(actor, 3);
            }
            break;

        case 3:
            func_800F5A00(func_800F54E4(), center_b);

            if (func_800F00A4(actor->position,
                              func_80103EAC(actor) *
                                  (func_800F64A4(func_800F54E4(), 0x40000) ? 1.0f : 0.6f),
                              func_800F64A4(func_800F54E4(), 0x40000) ? 40.0f
                                                                      : actor->scale * 280.0f,
                              0, center_b)) {
                func_8010A624(actor);

                if (func_800DA298(0x18A) && func_800EA05C() == 0x112) {
                    _gcgoto_entrypoint_5(0x122, 1, func_8010CD28(actor) + 180.0f);
                } else {
                    _gcgoto_entrypoint_5(0x11E, 1, func_8010CD28(actor) + 180.0f);
                }
            }
            break;

        case 4:
            if (func_800DA298(0x9DE)) {
                func_80800B9C_chwumbawigwam(actor, 5);
            }
            break;

        case 5:

            _sumumbofx_entrypoint_6(func_80100094(actor, 1), func_80103EF4(actor),
                                    *(f32 *) ((char *) actor + 0x38) * (f32) (u32) *
                                        (u16 *) ((char *) actor + 0x62),
                                    0, 0x28, (char *) actor + 4, 0, 0);

            _sumumbofx_entrypoint_14(func_80100094(actor, 1));

            if (_sumumbofx_entrypoint_27(func_80100094(actor, 1))) {
                func_80800B9C_chwumbawigwam(actor, 6);
            }
            break;

        case 6:

            _sumumbofx_entrypoint_6(func_80100094(actor, 1), func_80103EF4(actor),
                                    *(f32 *) ((char *) actor + 0x38) * (f32) (u32) *
                                        (u16 *) ((char *) actor + 0x62),
                                    0, 0x28, (char *) actor + 4, 0, 0);

            _sumumbofx_entrypoint_14(func_80100094(actor, 1));

            _sumumbofx_entrypoint_5(func_80100094(actor, 1), 3.0f);

            if (_sumumbofx_entrypoint_27(func_80100094(actor, 1))) {
                if (func_800DA298(0x18A)) {
                    func_80800B9C_chwumbawigwam(actor, 8);
                } else {
                    func_80800B9C_chwumbawigwam(actor, 7);
                }
            }
            break;

        // Grow
        case 7: {
            f32 progress;
            WigwamPosition spawn_pos;
            if (_sumumbofx_entrypoint_21(func_80100094(actor, 1)) > 2.5f) {
                if (!actor->unk64_19) {
                    _subaddieaudioquick_entrypoint_2(actor, (char *) actor + 4,
                                                     D_808010EC_chwumbawigwam);

                    actor->unk64_19 = 1;
                }

                progress = func_800F12D4(_sumumbofx_entrypoint_21(func_80100094(actor, 1)), 4.0f,
                                        2.5f, 1.0f, 2.0f);

                *(f32 *) ((char *) actor + 0x28) = progress;
                *(f32 *) ((char *) actor + 0x2C) = progress;
                *(f32 *) ((char *) actor + 0x30) = progress;
            } else {
                progress = func_800F10B4(_sumumbofx_entrypoint_21(func_80100094(actor, 1)), 2.5f,
                                        0.0f, 1.0f, 0.0f);

                if (!actor->unk64_20) {
                    _subaddieaudioquick_entrypoint_2(actor, (char *) actor + 4,
                                                     D_80801100_chwumbawigwam);

                    actor->unk64_20 = 1;
                }

                *(f32 *) ((char *) actor + 0x28) =
                    (func_800138D0(progress * 3.0f * 360.0f) * progress) + 1.0f;

                *(f32 *) ((char *) actor + 0x2C) =
                    (func_800138D0(progress * 5.0f * 360.0f) * progress) + 1.0f;

                *(f32 *) ((char *) actor + 0x30) = *(f32 *) ((char *) actor + 0x28);

                *(f32 *) ((char *) actor + 0x38) = func_800F12D4(
                    _sumumbofx_entrypoint_21(func_80100094(actor, 1)), 2.5f, 0.0f, 1.0f, 2.8f);
            }

            _sumumbofx_entrypoint_6(func_80100094(actor, 1),
                                    func_80103EF4(actor) * *(f32 *) ((char *) actor + 0x2C),
                                    ((f32) (u32) *(u16 *) ((char *) actor + 0x62) *
                                     *(f32 *) ((char *) actor + 0x38)) *
                                        func_800F0E00(*(f32 *) ((char *) actor + 0x28),
                                                      *(f32 *) ((char *) actor + 0x30)),
                                    0, 0x28, (char *) actor + 4, 0, 0);

            _sumumbofx_entrypoint_14(func_80100094(actor, 1));

            if (_sumumbofx_entrypoint_27(func_80100094(actor, 1))) {
                func_80800B9C_chwumbawigwam(actor, 9);
            }

            if (_sumumbofx_entrypoint_21(func_80100094(actor, 1)) <= 2.0f && !actor->unk74_29) {
                spawn_pos = D_808010E0_chwumbawigwam;

                func_800BBCB8(spawn_pos.xyz, spawn_pos.xyz, 1.0f, 0xF,
                              D_80801114_chwumbawigwam);

                func_800C4140(0x7FFB5BF2, spawn_pos.xyz, 0x1F4003E8);

                actor->unk74_29 = 1;
            }
            break;
        }
        // Shrink
        case 8: {
            f32 progress;
            progress = func_800F10B4(_sumumbofx_entrypoint_21(func_80100094(actor, 1)), 4.0f, 0.0f,
                                    1.0f, 0.0f);

            if (!actor->unk64_20) {
                _subaddieaudioquick_entrypoint_2(actor, (char *) actor + 4,
                                                 D_80801158_chwumbawigwam);

                actor->unk64_20 = 1;
            }

            *(f32 *) ((char *) actor + 0x28) =
                (func_80013970(progress * 6.0f * 360.0f) * (progress * 0.5f)) + 1.0f;

            *(f32 *) ((char *) actor + 0x2C) =
                (func_80013970(progress * 7.0f * 360.0f) * (progress * 0.5f)) + 1.0f;

            *(f32 *) ((char *) actor + 0x30) = *(f32 *) ((char *) actor + 0x28);

            *(f32 *) ((char *) actor + 0x38) = func_800F12D4(
                _sumumbofx_entrypoint_21(func_80100094(actor, 1)), 4.0f, 2.5f, 2.8f, 1.0f);

            _sumumbofx_entrypoint_6(func_80100094(actor, 1),
                                    func_80103EF4(actor) * *(f32 *) ((char *) actor + 0x2C),
                                    ((f32) (u32) *(u16 *) ((char *) actor + 0x62) *
                                     *(f32 *) ((char *) actor + 0x38)) *
                                        func_800F0E00(*(f32 *) ((char *) actor + 0x28),
                                                      *(f32 *) ((char *) actor + 0x30)),
                                    0, 0x28, (char *) actor + 4, 0, 0);

            _sumumbofx_entrypoint_14(func_80100094(actor, 1));

            if (_sumumbofx_entrypoint_27(func_80100094(actor, 1))) {
                func_80800B9C_chwumbawigwam(actor, 9);
            }
            break;
        }
        case 9:

            _sumumbofx_entrypoint_6(func_80100094(actor, 1), func_80103EF4(actor),
                                    *(f32 *) ((char *) actor + 0x38) * (f32) (u32) *
                                        (u16 *) ((char *) actor + 0x62),
                                    0, 0x28, (char *) actor + 4, 0, 0);

            _sumumbofx_entrypoint_14(func_80100094(actor, 1));

            if (_sumumbofx_entrypoint_27(func_80100094(actor, 1))) {
                func_80800B9C_chwumbawigwam(actor, 0xA);
            }
            break;

        case 10:
            func_80800B9C_chwumbawigwam(actor, 3);
    }
}

// State change; states 4-10 run the Mumbo spell that toggles flag 0x18A (wigwam size).
void func_80800B9C_chwumbawigwam(actor, state) Actor *actor;
s32 state;
{
    s32 zero_vec[3];
    s32 unk_0;
    s32 unk_1;
    void *effect;

    switch (state) {
        case 4:
            _subaddieDll_entrypoint_4(actor, 1);
            actor->unk64_20 = 0;
            actor->unk64_19 = 0;
            actor->unk74_29 = 0;
            func_8010A800(actor, 2);
            break;
        case 5:
            zero_vec[0] = 0;
            zero_vec[1] = 0;
            zero_vec[2] = 0;
            _sumumbofx_entrypoint_0(actor, 1, 0x28, (s16) _chmumbopad_entrypoint_0(9));
            _sumumbofx_entrypoint_2(func_80100094(actor, 1));
            _sumumbofx_entrypoint_25(func_80100094(actor, 1), 0x7D, zero_vec);
            effect = func_80100094(actor, 1);
            // Matching: result unused, needed for the match.
            func_800DA298(0x18A);
            _sumumbofx_entrypoint_24(effect, 1.5f);
            _sumumbofx_entrypoint_15(func_80100094(actor, 1), 3.0f);
            func_80101180(0x2B0, 0xBB, 9);
            _capod_entrypoint_13(*(u32 *) actor, 0, 0xE, 0x210);
            func_800DA544(0x57D);
            break;
        case 6:
            _sumumbofx_entrypoint_18(func_80100094(actor, 1), 3.0f);
            break;
        case 7:
            _sumumbofx_entrypoint_17(func_80100094(actor, 1), 4.0f);
            func_800DA544(0x18A);
            break;
        case 8:
            _sumumbofx_entrypoint_17(func_80100094(actor, 1), 4.0f);
            func_800DA524(0x18A);
            break;
        case 9:
            _sumumbofx_entrypoint_16(func_80100094(actor, 1), 3.0f);
            if (func_800DA298(0x18A))
                actor->scale = 2.8f;
            else
                actor->scale = 1.0f;
            *(f32 *) ((u8 *) actor + 0x28) = 1.0f;
            *(f32 *) ((u8 *) actor + 0x2C) = 1.0f;
            *(f32 *) ((u8 *) actor + 0x30) = 1.0f;
            _chglowbo_entrypoint_6();
            break;
        case 10:
            _sumumbofx_entrypoint_1(actor, 1);
            func_8010A800(actor, 0);
            func_800DA544(0x9DF);
            _subaddieDll_entrypoint_4(actor, 0);
    }
    func_80101FDC(actor, state);
}

u8 B_808011C0_chwumbawigwam[48];
u8 B_808011F0_chwumbawigwam[16];

void func_80800E04_chwumbawigwam(Actor *actor, s32 draw_arg)
{
    f32 *unk_0;
    f32 *unk_1;
    s32 i;
    if (func_80100094(actor, 1) != NULL) {
        _sumumbofx_entrypoint_9(func_80100094(actor, 1), draw_arg);
    }
    if (actor->unk70_10 == 7 || actor->unk70_10 == 8) {
        for (i = 4, unk_0 = (f32 *) B_808011F0_chwumbawigwam,
            unk_1 = (f32 *) B_808011E4_chwumbawigwam;
             i != 0; i--, unk_0 -= 3, unk_1 -= 3) {
            func_800EE7F8(unk_0, unk_1);
            if (unk_0[0] != 0.0f && unk_0[1] != 0.0f && unk_0[2] != 0.0f) {
                func_800DF500(unk_0[0], unk_0[1], unk_0[2]);
                _subaddiefade_entrypoint_1(actor, 160 - i * 30);
                *((u8 *) actor + 0x7A) = (*((u8 *) actor + 0x7A) & 0xFF3F) | 0x80;
                func_80101870(actor, draw_arg);
            }
        }
        func_800EE7F8((f32 *) B_808011C0_chwumbawigwam, (f32 *) &actor->actorData[4]);
        if (((f32 *) actor->actorData)[4] != 0.0f && ((f32 *) actor->actorData)[5] != 0.0f &&
            ((f32 *) actor->actorData)[6] != 0.0f) {
            func_800DF500(((f32 *) actor->actorData)[4], ((f32 *) actor->actorData)[5],
                          ((f32 *) actor->actorData)[6]);
        }
        *((u8 *) actor + 0x7A) = (*((u8 *) actor + 0x7A) & 0xFF3F) | 0x40;
    }
    _subaddiefade_entrypoint_1(actor, 255);
    func_80101870(actor, draw_arg);
    if (func_80100094(actor, 1) != NULL) {
        _sumumbofx_entrypoint_8(func_80100094(actor, 1), draw_arg);
    }
}

s32 func_80800FEC_chwumbawigwam(Actor *actor, s32 msg, s32 spell)
{
    switch (msg) {
        // Mumbo spell 9 from the Mumbo pad
        case 0x4B:
            if (spell == 9 && (s32) actor->unk70_10 < 5) {
                func_80800B9C_chwumbawigwam(actor, 4);
                return 1;
            }
            return 0;
        case 0x2E:
            return 1;
        case 0xB:
            func_800DA524(0x9DE);
            return 3;
    }
    return 0;
}

int chwumbawigwam_entrypoint_0()
{
    return (int) &D_8080116C_chwumbawigwam;
}

extern void func_80105834();
extern void func_80107C2C();
WigwamPosition D_808010E0_chwumbawigwam = {0.0f, 4e+03f, 1.85e+03f};
u8 D_808010EC_chwumbawigwam[20] = {0x0,  0x13, 0x4, 0x1D, 0x0, 0xA,  0x0,  0x59, 0x0, 0x16,
                                   0x6D, 0x60, 0x0, 0x1,  0xB, 0xB8, 0x17, 0x70, 0x0, 0x0};
u8 D_80801100_chwumbawigwam[20] = {0x0,  0x13, 0x4, 0x1E, 0x0, 0xA,  0x1,  0x0,  0x0, 0x16,
                                   0x6D, 0x60, 0x0, 0x1,  0xB, 0xB8, 0x17, 0x70, 0x0, 0x0};
u8 D_80801114_chwumbawigwam[68] = {
    0x0, 0x1D, 0x6,  0xA0, 0x0, 0x1B, 0xFD, 0x44, 0xFD, 0xA8, 0x0, 0x2C, 0xFD, 0x44,
    0x0, 0x0,  0xFD, 0x44, 0x2, 0xBC, 0x0,  0x0,  0x2,  0xBC, 0x0, 0xE,  0x0,  0x3C,
    0x0, 0x3C, 0x0,  0x16, 0x4, 0x2,  0x0,  0x27, 0x2,  0xBC, 0x2, 0xBC, 0x3,  0xE8,
    0x3, 0xE8, 0x0,  0x24, 0x0, 0xC0, 0x1,  0x0,  0x0,  0x2B, 0x5, 0x0,  0x6,  0x0,
    0x0, 0x4,  0x0,  0x66, 0x0, 0x7,  0x0,  0x3,  0x0,  0x0,  0x0, 0x0};
u8 D_80801158_chwumbawigwam[20] = {0x0, 0x13, 0x4,  0x1E, 0x0, 0xA,  0x1,  0x0,  0x0, 0x1,
                                   0xB, 0xB8, 0x17, 0x70, 0x0, 0x16, 0x6D, 0x60, 0x0, 0x0};
int D_8080116C_chwumbawigwam[21] = {0x158028D,
                                    0x6F20001,
                                    0x0,
                                    (u32) func_80800158_chwumbawigwam,
                                    (u32) func_80105834,
                                    (u32) func_80800E04_chwumbawigwam,
                                    0x7D00000,
                                    0x0,
                                    0x0,
                                    0xC00,
                                    0x0,
                                    0x0,
                                    0x0,
                                    (u32) func_80800000_chwumbawigwam,
                                    (u32) func_80107C2C,
                                    -0x7FFFFBFE,
                                    (u32) func_80800FEC_chwumbawigwam,
                                    0x0,
                                    0x0,
                                    0x0,
                                    0x0};
