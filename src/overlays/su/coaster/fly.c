#include "su/coasterfly.h"

// OD(n): float n of the actor data; the macro hardcodes the name param_0.
#define OD(n) (((f32 *) param_0->actorData)[n])
extern int D_80802280_sucoasterfly[];
typedef struct {
    u8 pad_0[0xC];
    f32 local_0;
    u8 pad_1;
    u8 local_1 : 4;
    u8 pad_2 : 4;
    u8 pad_3[6];
    s16 local_2;
} CoasterFlightRoute;
extern void *func_80100074(Actor *, u32, u32);
typedef struct {
    u32 pad74_4 : 28;
    u32 unk74_0 : 4;
} ActorFlags74;
typedef struct {
    u8 pad0[0x11];
    u8 unk11_4 : 4;
    u8 unk11_0 : 4;
} CoasterFlyLocal;
extern s32 _subaddieDll_entrypoint_3(Actor *);
extern s32 func_80107070(Actor *, s32);
extern void _subaddiefade_entrypoint_3(Actor *);
extern void _subaddieDll_entrypoint_4(Actor *, s32);
extern void *func_80100094(Actor *, u32);
extern void _suexpression_entrypoint_13(void *, f32 *, f32 *);
extern void func_80101010(f32 *);
extern void _subaddierouteDll_entrypoint_1(Actor *);
extern s32 _sucoasterflydata_entrypoint_2(s32, s32 *);
extern void func_80101074(s32);
typedef struct {
    u8 pad[0x72];
    u16 f72 : 6;
    u16 rest : 10;
} FlyActor;
typedef struct {
    u8 pad[0x24];
    u32 f24 : 10;
    u32 r24 : 22;
} FlyObj;
extern u8 *func_80106790(s32);
extern f32 func_800D8FF8(void);
extern f32 func_800EEF94(f32 *);
extern f32 func_800EEFD4(f32 *);
extern void func_800EF334(f32 *, f32);
extern void func_800EF368(f32 *, f32);
extern s32 _glhittableDll_entrypoint_10(u8 *);
extern s32 _glhittableDll_entrypoint_9(u8 *);
extern s32 _glhittableDll_entrypoint_6(u8 *);
extern s32 _glhittableDll_entrypoint_8(u8 *);
extern s32 func_800F70EC(s32);
extern s32 func_800F6C1C(s32);
extern s32 func_800F0E28(s32, s32, u8 *, u8 *);
extern void func_80109600(u8 *, u8 *, u8 *, s32);
extern void _chflamer_entrypoint_1(u8 *, u8 *, u8 *);
extern void func_800EC370(u8 *, s32 *, u8 *);
extern void _chfreezy_entrypoint_1(u8 *, s32 *);
extern s32 func_8010A430(u8 *);
extern s32 func_800F54E4(void);
extern f32 func_800F5F24(s32);
extern void func_800EB860(void *, u8 *);
extern f32 func_800EC708(s32);
extern void _chbaddiesetup_entrypoint_5(void *, s32, s32, s32, s32, s32);
extern void func_800EB874(void);
extern void func_8010D930(s32, s32, u8 *, u8 *);
extern void _subaddiejoy_entrypoint_10(u8 *, f32, f32);
extern u8 D_80802294_sucoasterfly[];
extern u8 func_80108EF4[];
extern u8 _chbaddiesetup_entrypoint_10[];
extern void func_800EEB9C(f32 *, f32, f32);
extern f32 func_800F0D50(f32, f32, f32);
extern void func_80102924(Actor *, f32);
typedef struct {
    u8 pad_0[0x64];
    u32 pad_1 : 2;
    u32 local_0 : 1;
    u32 pad_2 : 29;
} CoasterFlyMovementFlags;
typedef struct {
    u8 pad_0[0x64];
    u32 pad_1 : 1;
    u32 local_0 : 1;
    u32 local_1 : 1;
    u32 pad_2 : 29;
    u8 pad_3[16];
    u32 pad_4 : 28;
    u32 local_2 : 1;
    u32 pad_5 : 3;
} CoasterFlyEligibility;
typedef struct {
    u8 pad_0[0x10];
    u32 pad_1 : 12;
    u32 local_0 : 1;
    u32 pad_2 : 19;
} CodexCoasterFlyFlags;
typedef struct {
    u32 pad_0 : 2;
    u32 local_0 : 1;
    u32 pad_1 : 29;
} CodexCoasterActorFlags;
extern s32 func_80101E14(Actor *, f32);
extern f32 func_8010CD28(Actor *);
extern s32 func_800F20BC(f32, f32, f32);
typedef struct {
    u8 pad_0[0x18];
    s16 local_0;
} FlightClearance1570;
extern void func_8008FE94(s32, f32 *);
extern int func_80104544(Actor *);
extern f32 func_8010473C(Actor *, s32);
extern void func_800EE7F8(f32 *, f32 *);
extern int func_800CC338(f32 *, s32, s32);
typedef struct {
    u8 pad_0[0x64];
    u32 pad_1 : 2;
    u32 local_0 : 1;
    u32 pad_2 : 29;
    u8 pad_3[0x10];
    u32 pad_4 : 29;
    u32 local_1 : 1;
    u32 pad_5 : 2;
} CoasterFlyUpdateFlags;
typedef struct {
    u8 pad_0[0x10];
    u32 pad_1 : 12;
    u32 local_0 : 1;
    u32 pad_2 : 19;
} CoasterFlyUpdateLocalFlags;
extern f32 func_80107C00(void);
extern void func_800D9078(f32 *);
extern f32 _subaddiejoy_entrypoint_9(Actor *, f32 *, s32);
extern f32 _subaddiejoy_entrypoint_3(Actor *);
extern s32 func_800DC298(f32);
extern void func_80102D98(Actor *, s32, s32, f32, f32, f32);
extern void func_80102BF8(Actor *, f32, f32, f32);
extern s32 func_80102CF4(Actor *, f32);
extern s32 _subaddierouteDll_entrypoint_4(Actor *);
extern s32 _subaddierouteDll_entrypoint_7(Actor *, void *, f32, f32, f32, s32);
extern void _subaddierouteDll_entrypoint_5(Actor *, void *, u8, f32, f32, f32);
extern f32 func_800F5BF0(s32, f32 *);
extern s32 func_800F0008(f32 *, f32, f32 *, f32);
extern f32 func_800F1DCC(f32, f32);
extern f32 func_80102D78(Actor *, f32 *);
extern void func_800EFB24(f32 *, f32 *, f32 *);
extern f32 func_800EEFFC(f32 *);
extern void func_800EFCD8(f32 *, f32, f32);
extern s32 func_8010B990(Actor *, s32);
extern void func_800EE88C(f32 *, s16 *);
extern f32 func_800EEB40(f32 *, f32 *);
extern f32 func_800F10B4(f32, f32, f32, f32, f32);
extern f32 func_800F1FF0(f32, f32, f32, f32, f32);
typedef struct {
    u8 pad0[0xC];
    f32 unkC;
    u8 pad10;
    u8 unk11_4 : 4;
    u8 unk11_3 : 1;
    u8 pad11 : 3;
    s16 unk12[3];
} FlyData;
typedef struct {
    u8 pad0[0x24];
    s16 unk24;
    s16 unk26;
} FlyInfo;
typedef struct {
    u8 pad0[0x14];
    u32 pad14_20 : 12;
    u32 unk14_19 : 1;
    u32 pad14_0 : 19;
    u8 pad18[0x64 - 0x18];
    u32 unk64_31 : 1;
    u32 unk64_30 : 1;
    u32 pad64_26 : 4;
    u32 unk64_25 : 1;
    u32 unk64_24 : 1;
    u32 pad64_0 : 24;
    u8 pad68[8];
    u32 unk70_25 : 7;
    u32 pad70_10 : 15;
    u32 unk70_4 : 6;
    u32 pad70_0 : 4;
    u32 pad74_4 : 28;
    u32 unk74_0 : 4;
} FlyBits;
extern u8 D_808022AC_sucoasterfly[];
extern FlyInfo *_sucoasterflydata_entrypoint_1(s32);
extern void func_80102424(Actor *, s32);
extern s32 _sucoasterflydata_entrypoint_3(s32);
extern s32 _sucoasterflydata_entrypoint_4(s32);
extern s32 _sucoasterflydata_entrypoint_5(s32);
extern s32 func_800DC128(s32, s32);
extern void func_800EE940();
extern void func_8010A570(Actor *);
extern void _subaddieaudioquick_entrypoint_2();
typedef struct {
    u8 pad_0[0xC];
    f32 local_0;
} CoasterFlySpeed1482;
extern f32 func_800F0E00(f32, f32);
extern f32 func_800F15F8(f32, f32, f32);
typedef struct CoasterFlyJoyFlag {
    u8 pad_0[0x64];
    u32 pad_1 : 2;
    u32 local_0 : 1;
    u32 pad_2 : 29;
} CoasterFlyJoyFlag;
extern u8 D_808022BC_sucoasterfly[];
extern f32 func_800DC178(f32, f32);
extern void func_800C4B64(f32);
f32 func_80801E5C_sucoasterfly();
s32 func_80801FE4_sucoasterfly(u8 *param_0, f32 *param_1, f32 param_2, f32 param_3);
void func_80802080_sucoasterfly();
extern void func_808014AC_sucoasterfly(Actor *, s32);
extern void func_8080181C_sucoasterfly(Actor *);
void func_80801CD0_sucoasterfly();

int sucoasterfly_entrypoint_0()
{
    return (int) &D_80802280_sucoasterfly;
}

// Init: sets up the local data and route following.
s32 sucoasterfly_entrypoint_1(Actor *actor, s32 extra_size)
{
    CoasterFlightRoute *fly;
    f32 floor_y;

    fly = func_80100074(actor, 0, extra_size + 0x1C);
    fly->local_1 = _sucoasterflydata_entrypoint_0(actor);
    _subaddierouteDll_entrypoint_3(actor, fly, actor->position);
    fly->local_0 = 0.0f;
    floor_y = actor->position[1] - 400.0f;
    func_80801FE4_sucoasterfly(actor, &floor_y, 50.0f, -1500.0f);
    fly->local_2 = (s32) (actor->position[1] - floor_y);
    return 1;
}

void sucoasterfly_entrypoint_2(Actor *actor)
{
    func_80802128_sucoasterfly(actor);
}

extern s32 func_8080215C_sucoasterfly(s32);

extern void func_80801C44_sucoasterfly(Actor *, s32);

extern s32 func_80801B90_sucoasterfly(Actor *);

extern s32 func_80801AB0_sucoasterfly(Actor *);

extern s32 func_80801A80_sucoasterfly(s32);

extern void func_808019A0_sucoasterfly(Actor *);

// Update: runs the current state, then smooths the bank toward the turn rate.
void sucoasterfly_entrypoint_3(Actor *actor)
{
    char *fly;
    f32 prev_heading;
    f32 dt;
    f32 heading_delta;
    void *expression;

    fly = (char *) func_80100094(actor, 0);
    dt = func_800D8FF8();

    if (((CoasterFlyUpdateFlags *) actor)->local_1) {
        return;
    }

    func_800D9078((char *) actor + 0x58);

    prev_heading = *(f32 *) ((char *) actor + 0x48);

    if (func_80100094(actor, 1) != 0) {
        expression = func_80100094(actor, 1);
        _suexpression_entrypoint_10(expression, *(s32 *) actor, 0);
    }

    switch (actor->unk70_10) {
        case 1: {
            f32 stick;

            func_80801C44_sucoasterfly(actor, 0);

            if (((CoasterFlyUpdateFlags *) actor)->local_0) {
                stick = _subaddiejoy_entrypoint_9(actor, (char *) actor + 0x54, 3);

                if (0.2f < stick) {
                    func_808014AC_sucoasterfly(actor, 3);
                }

                func_80801DD0_sucoasterfly(actor);
            } else {
                if (!func_80801AB0_sucoasterfly(actor) &&
                    *(f32 *) ((char *) actor + 0x58) <= 0.0f && func_800DC298(0.02f)) {
                    func_808014AC_sucoasterfly(actor, 3);
                }

                func_80102D98(actor, 0x3F, 0, 0.3f, 20.0f, 40.0f);
            }

            func_80102BF8(actor, 0.1f, 4.0f, 150.0f);
            func_808019A0_sucoasterfly(actor);
            break;
        }

        case 2:
            func_80801C44_sucoasterfly(actor, 0);
            func_80102BF8(actor, 0.1f, 4.0f, 150.0f);

            if (func_80102CF4(actor, 6.0f)) {
                func_808014AC_sucoasterfly(actor, 3);
            }
            break;

        case 3: {
            f32 value;

            func_80801C44_sucoasterfly(actor, 0);

            if (((CoasterFlyUpdateFlags *) actor)->local_0) {
                value = _subaddiejoy_entrypoint_9(actor, (char *) actor + 0x54, 3);

                func_80102BF8(actor, 0.1f, 4.0f, 150.0f);

                if (value == 0.0f) {
                    func_808014AC_sucoasterfly(actor, 1);
                }

                func_80801DD0_sucoasterfly(actor);
            } else {
                if (_subaddierouteDll_entrypoint_4(actor)) {
                    value = func_80107C00();

                    _subaddierouteDll_entrypoint_7(
                        actor, fly, *(f32 *) ((char *) actor + 0x48),
                        *(f32 *) ((char *) actor + 0x54), value * 300.0f, 0x4802);

                    *(u8 *) (fly + 0x10) = *(u16 *) (fly + 6);
                }

                if (!func_80801AB0_sucoasterfly(actor) &&
                    *(f32 *) ((char *) actor + 0x58) <= 0.0f && func_800DC298(0.02f)) {
                    func_808014AC_sucoasterfly(actor, 1);
                }

                _subaddierouteDll_entrypoint_5(actor, fly, *(u8 *) (fly + 0x10), 0.1f,
                                               4.0f, 150.0f);
            }

            func_808019A0_sucoasterfly(actor);
            break;
        }

        case 4: {
            f32 rand;

            func_80801C44_sucoasterfly(actor, 0);

            if (_subaddierouteDll_entrypoint_4(actor)) {
                *(f32 *) ((char *) actor + 0x54) = func_8010CD28(actor);

                rand = func_80107C00();

                _subaddierouteDll_entrypoint_7(actor, fly, *(f32 *) ((char *) actor + 0x48),
                                               *(f32 *) ((char *) actor + 0x54), rand * 300.0f,
                                               0x4802);

                *(u8 *) (fly + 0x10) = *(u16 *) (fly + 6);
            }

            _subaddierouteDll_entrypoint_5(actor, fly, *(u8 *) (fly + 0x10), 0.1f, 4.0f,
                                           180.0f);

            func_808019A0_sucoasterfly(actor);

            if (((CoasterFlyUpdateFlags *) actor)->local_0) {
                func_808014AC_sucoasterfly(actor, 1);
                break;
            }

            if (func_80801B90_sucoasterfly(actor)) {
                break;
            }

            if (!func_80102CF4(actor, 20.0f)) {
                break;
            }

            if (func_801021BC(actor, 5)) {
                func_808014AC_sucoasterfly(actor, 5);
            } else {
                func_808014AC_sucoasterfly(actor, 6);
            }
            break;
        }

        case 5: {
            f32 rand;

            func_80801C44_sucoasterfly(actor, 1);

            if (_subaddierouteDll_entrypoint_4(actor)) {
                *(f32 *) ((char *) actor + 0x54) = func_8010CD28(actor);

                rand = func_80107C00();

                _subaddierouteDll_entrypoint_7(actor, fly, *(f32 *) ((char *) actor + 0x48),
                                               *(f32 *) ((char *) actor + 0x54), rand * 300.0f,
                                               0x4802);

                *(u8 *) (fly + 0x10) = *(u16 *) (fly + 6);
            }

            _subaddierouteDll_entrypoint_5(actor, fly, *(u8 *) (fly + 0x10), 0.1f, 4.0f,
                                           180.0f);

            func_808019A0_sucoasterfly(actor);

            if (func_80801B90_sucoasterfly(actor)) {
                break;
            }

            if (func_80101DDC(actor)) {
                func_808014AC_sucoasterfly(actor, 6);
            }
            break;
        }

        case 6: {
            f32 anchor_pos[3];
            f32 value;
            f32 heading_diff;
            f32 delta[3];
            s32 tmp;
            s32 move_flags;

            tmp = func_800F54E4();
            value = func_800F5BF0(tmp, anchor_pos);

            func_80801C44_sucoasterfly(actor, 0);

            if (!func_800F0008((f32 *) actor->position, 300.0f, anchor_pos, value)) {
                func_80801A80_sucoasterfly(actor);
            }

            if (((CoasterFlyUpdateFlags *) actor)->local_0) {
                value = _subaddiejoy_entrypoint_3(actor);

                if (0.0f < value) {
                    heading_diff = func_800F1DCC(*(f32 *) ((char *) actor + 0x54),
                                            *(f32 *) ((char *) actor + 0x48));

                    if (heading_diff < -30.0f) {
                        *(f32 *) ((char *) actor + 0x54) =
                            *(f32 *) ((char *) actor + 0x48) - 30.0f;
                    } else if (30.0f < heading_diff) {
                        *(f32 *) ((char *) actor + 0x54) =
                            *(f32 *) ((char *) actor + 0x48) + 30.0f;
                    }
                }
            } else {
                *(f32 *) ((char *) actor + 0x54) =
                    func_80102D78(actor, (char *) actor + 0x18);
            }

            func_80102BF8(actor, 0.1f, 4.0f, 180.0f);

            if (func_80801B90_sucoasterfly(actor)) {
                break;
            }

            move_flags = ((CoasterFlyUpdateFlags *) actor)->local_0 ? 0x00604027 : 0x00600307;

            func_8080181C_sucoasterfly(actor);

            func_800EFB24(delta, (f32 *) actor->actorData, (char *) actor + 4);

            func_800EF368(delta, *(f32 *) ((char *) actor + 0x24));

            value = func_800EEFFC(delta);

            func_800EFCD8((char *) actor + 0x28, *(f32 *) ((char *) actor + 0x48), value);

            *(f32 *) ((char *) actor + 0x2C) = delta[1];

            tmp = func_8010B990(actor, move_flags);

            if (tmp & 0x24) {
                func_808014AC_sucoasterfly(actor, 8);
                break;
            }

            value = func_80102D78(actor, (f32 *) actor->actorData);

            if (func_800F20BC(*(f32 *) ((char *) actor + 0x48), value, 100.0f)) {
                break;
            }

            func_808014AC_sucoasterfly(actor, 7);
            break;
        }

        case 7: {
            s32 hit_flags;
            s32 move_flags;

            if (((CoasterFlyUpdateFlags *) actor)->local_0) {
                move_flags = 0x00604027;
            } else {
                move_flags = 0x00600307;
            }

            func_80801C44_sucoasterfly(actor, 0);
            func_80102BF8(actor, 0.1f, 4.0f, 150.0f);
            func_8080181C_sucoasterfly(actor);

            if (30.0f < *(f32 *) ((char *) actor + 0x24)) {
                func_800EF368((char *) actor + 0x28, *(f32 *) ((char *) actor + 0x24));

                hit_flags = func_8010B990(actor, move_flags);

                if ((hit_flags & 0x24) != 0 || *(f32 *) ((char *) actor + 0x24) == 0.0f) {
                    func_808014AC_sucoasterfly(actor, 8);
                }
            } else {
                if (*(u8 *) ((char *) actor + 0x64) & 1) {
                    func_808014AC_sucoasterfly(actor, 3);
                } else {
                    func_808014AC_sucoasterfly(actor, 8);
                }
            }
            break;
        }

        // Return to the home point.
        case 8: {
            f32 home_pos[3];
            f32 arrive_dist;
            f32 rand;
            f32 home_target[3];

            arrive_dist = func_800D8FF8();
            arrive_dist *= 10.0f * *(f32 *) (fly + 0xC);

            func_80801C44_sucoasterfly(actor, 0);

            if (_subaddierouteDll_entrypoint_4(actor)) {
                func_800EE88C(home_target, fly + 0x12);

                *(f32 *) ((char *) actor + 0x54) = func_80102D78(actor, home_target);

                rand = func_80107C00();

                _subaddierouteDll_entrypoint_7(actor, fly, *(f32 *) ((char *) actor + 0x48),
                                               *(f32 *) ((char *) actor + 0x54), rand * 300.0f,
                                               0x4802);

                *(u8 *) (fly + 0x10) = *(u16 *) (fly + 6);
            }

            _subaddierouteDll_entrypoint_5(actor, fly, *(u8 *) (fly + 0x10), 0.1f, 4.0f,
                                           150.0f);

            func_808019A0_sucoasterfly(actor);

            func_800EE88C(home_pos, fly + 0x12);

            if (func_80102CF4(actor, 6.0f) ||
                func_800EEB40((f32 *) actor->position, home_pos) < arrive_dist * arrive_dist) {
                func_808014AC_sucoasterfly(actor, 9);
            }
            break;
        }

        case 9: {
            f32 home_pos[3];
            f32 arrive_dist;

            arrive_dist = func_800D8FF8();
            arrive_dist *= 10.0f * *(f32 *) (fly + 0xC);

            func_80801C44_sucoasterfly(actor, 0);
            func_80102BF8(actor, 0.1f, 4.0f, 150.0f);

            func_800EE88C(home_pos, fly + 0x12);

            if (func_800EEB40(actor->position, home_pos) < arrive_dist * arrive_dist) {
                actor->unk64_24 = 1;
                func_808014AC_sucoasterfly(actor, 3);
            } else {
                func_8080181C_sucoasterfly(actor);

                func_800EFB24((char *) actor + 0x28, home_pos, actor->position);

                func_800EF368((char *) actor + 0x28, *(f32 *) ((char *) actor + 0x24));

                func_8010B990(actor, 0x4027);
            }
            break;
        }

        case 10:
            func_8080215C_sucoasterfly(actor);
            func_80801C44_sucoasterfly(actor, 2);

            if (func_80101DDC(actor)) {
                if (((CoasterFlyUpdateLocalFlags *) fly)->local_0) {
                    func_808014AC_sucoasterfly(actor, 8);
                } else {
                    func_808014AC_sucoasterfly(actor, 3);
                }

                func_80101D7C(actor);
            }
            break;

        // Knocked down: falls with gravity until it hits the ground.
        case 11: {
            f32 step;
            s32 hit_flags;

            step = func_800D8FF8();

            func_8080215C_sucoasterfly(actor);

            *(f32 *) ((char *) actor + 0x34) += step * -9800.0f;

            *(f32 *) ((char *) actor + 0x2C) += step * *(f32 *) ((char *) actor + 0x34);

            if (*(f32 *) ((char *) actor + 0x2C) < -1500.0f) {
                *(f32 *) ((char *) actor + 0x2C) = -1500.0f;
            }

            hit_flags = func_8010B990(actor, 0x00204007);

            if (hit_flags & 0x28) {
                func_808014AC_sucoasterfly(actor, 12);
            }
            break;
        }

        // Dying: after the animation, fade out.
        case 12:
            func_8080215C_sucoasterfly(actor);
            func_80801C44_sucoasterfly(actor, 3);

            if (func_80101DDC(actor)) {
                _subaddieDll_entrypoint_4(actor, 0);

                if (!func_80107070(actor, 2)) {
                    func_808014AC_sucoasterfly(actor, 13);
                    _subaddiefade_entrypoint_3(actor);
                }
            }
            break;

        case 13:
        case 14:
        case 15:
        case 16:
            func_8080215C_sucoasterfly(actor);
    }

    heading_delta = func_800F1DCC(prev_heading, *(f32 *) ((char *) actor + 0x48));

    {
        f32 inv_dt;
        f32 target_bank;
        inv_dt = 1.0f / dt;
        target_bank = func_800F10B4(heading_delta * inv_dt, -60.0f, 60.0f, -12.0f, 12.0f);

        *(f32 *) ((char *) actor + 0x4C) = func_800F1FF0(
            *(f32 *) ((char *) actor + 0x4C), target_bank, 0.1f, 4.0f * dt, 120.0f * dt);
    }

    if (!func_801072A8(actor) || func_801072E4(actor)) {
        func_8010D690(actor);
    }
}

// Message handler.
s32 sucoasterfly_entrypoint_4(Actor *actor, s32 msg, s32 arg)
{
    f32 v[3];
    s32 ret;

    switch (msg) {
        case 1:
            func_808014AC_sucoasterfly(actor, 1);
            break;
        case 2:
            if (actor->unk70_10 == 0xB) {
                break;
            }
            if (!_subaddieDll_entrypoint_3(actor) && !func_80107070(actor, 1)) {
                _subaddiefade_entrypoint_3(actor);
                func_808014AC_sucoasterfly(actor, 0xF);
                actor->unk64_24 = 0;
            }
            break;
        case 0x8F:
            if (arg == 0) {
                actor->unk64_25 = 1;
                ((ActorFlags74 *) ((u8 *) actor + 0x74))->unk74_0 = 1;
                func_808014AC_sucoasterfly(actor, 3);
            }
            break;
        case 0x29:
            func_80802080_sucoasterfly(actor);
            break;
        case 0x2A:
            func_80802128_sucoasterfly(actor);
            break;
        case 0x4D:
            _subaddieDll_entrypoint_4(actor, 0);
            if (!func_80107070(actor, 3)) {
                return 0;
            }
            break;
        case 0x94:
            if (!func_80100094(actor, 1)) {
                return 0;
            }
            v[2] = 0.0f;
            _suexpression_entrypoint_13(func_80100094(actor, 1), &v[1], &v[0]);
            func_80101010(v);
            break;
        case 0x95:
            _subaddierouteDll_entrypoint_1(actor);
            break;
        case 0x38:
            func_80101074(_sucoasterflydata_entrypoint_2(
                ((CoasterFlyLocal *) func_80100094(actor, 0))->unk11_4, &ret));
            return ret;
        default:
            return 0;
    }
    return 1;
}

// Hit handlers 800EF0/800F44/800FA8 are called from func_80801108 by hit type 0/1/2.
void func_80800EF0_sucoasterfly(s32 handle, FlyObj *hitter)
{
    FlyActor *actor = func_80106790(handle);
    if (hitter->f24 == 0 && actor->f72 == 6) {
        func_808014AC_sucoasterfly(actor, 7);
    }
}

void func_80800F44_sucoasterfly(Actor *handle, u32 hitter)
{
    void *actor;
    // Matching: the redundant mask chain and its temporaries are needed for the match.
    unsigned int mask_ffff;
    int mask_ff;
    actor = func_80106790(handle);
    mask_ff = 0xFF;
    mask_ffff = 0xFFFFu;
    if (((u32) ((u16 *) actor)[57] >> 10) != 0xA) {
        short flags = ((((((((((((((u32 *) actor)[30] & mask_ffff) & 0xFFFFu) & 0xFF) & mask_ff) &
                            mask_ff) &
                           mask_ff) &
                          mask_ff) &
                         mask_ff) &
                        mask_ff) &
                       0xFF) &
                      (0xFFFFFFFFFFFFFFFF & 0xFFFFFFFFu)) &
                     0xFF) &
                    0xFFFFu;
        if ((flags << 29) >= 0) {
            if (func_801021BC(actor, 0xA)) {
                func_808014AC_sucoasterfly(actor, 0xA);
            }
        }
    }
}

// Knock-down: sets the knock-back velocity from the hit, then enters state 11.
void func_80800FA8_sucoasterfly(Unk80132ED0 *handle, Unk80132ED0 *hitter)
{
    Actor *actor = func_80106790(handle);
    f32 velocity[3];
    f32 inv_dt;
    f32 source_pos[3];

    if (_sueggmisc_entrypoint_0(hitter)) {
        _suegg_entrypoint_19(func_80106790(hitter), velocity);
        inv_dt = 1.0f / func_800D8FF8();
        func_800EF334(velocity, inv_dt);
        if (func_800EEF94(velocity) > 400.0f)
            func_800EF368(velocity, 400.0f);
    } else if (!(*(u32 *) ((u8 *) hitter + 0x24) >> 22)) {
        func_800F5D70((u32) *(u16 *) ((u8 *) hitter + 0x1A) >> 5, velocity);
        if (func_800EEFD4(velocity) < 100.0f) {
            func_800F5A00((u32) *(u16 *) ((u8 *) hitter + 0x1A) >> 5, source_pos);
            func_800EFB24(velocity, actor->position, source_pos);
            func_800EF368(velocity, 200.0f);
            velocity[1] += 150.0f;
        }
    } else {
        func_800EFD24(velocity);
    }
    func_808014AC_sucoasterfly(actor, 11);
    func_800EF04C((f32 *) &actor->actorData[4], velocity);
}

void func_80801108_sucoasterfly(s32 handle, u8 *hitter, u8 *hit)
{
    u8 *actor;
    s32 unk_0;
    s32 damage;
    s32 type;
    s32 killed;
    // Matching: unused locals, needed for the match.
    s32 unused48;
    s32 unused44;
    s32 tmp;
    s32 freeze_data[2];
    f32 unk_1;
    f32 spawn_y;

    actor = func_80106790(handle);
    unk_0 = _glhittableDll_entrypoint_10(hit);
    damage = _glhittableDll_entrypoint_9(hit);
    type = _glhittableDll_entrypoint_6(hit);
    tmp = !(*(u32 *) (hitter + 0x24) >> 22);
    if (tmp) {
        tmp = (u32) *(u16 *) (hitter + 0x1A) >> 5;
        if (!func_800F70EC(tmp) || !func_800F6C1C(tmp)) {
            if (_glhittableDll_entrypoint_8(hit)) {
                return;
            }
        }
    }
    if (type == 0) {
        if (damage == 0 && (*(u32 *) (hitter + 0x24) >> 22) != 0) {
            return;
        }
        if (damage <= 0) {
            damage = 1;
        }
    }
    (actor + type)[0x5C] =
        func_800F0E28(0, (actor + type)[0x5C] - 100 / damage, actor + type, hitter);
    killed = type == 2 && !(actor + type)[0x5C];
    if (damage != 0) {
        switch (type) {
            case 2:
                func_80109600(actor, hitter, (actor + type), type);
                if ((*(u32 *) (hitter + 0x24) >> 22) == 0x26D) {
                    // Matching: ^ 0 makes the argument a fresh value for uopt.
                _chflamer_entrypoint_1(actor, (u8 *) ((s32) hitter ^ 0),
                                           (actor + type));
                }
                break;
            case 1:
                func_80109600(actor, hitter, (actor + type), type);
                if ((*(u32 *) (hitter + 0x24) >> 22) == 0x26E) {
                    // Matching: ^ 0 makes the argument a fresh value for uopt.
                    func_800EC370((u8 *) ((s32) hitter ^ 0), freeze_data, (actor + type));
                    _chfreezy_entrypoint_1(actor, freeze_data);
                }
                break;
        }
    }
    if ((actor + type)[0x5C] == 0 || type != 0) {
        if ((actor + type)[0x5C] != 0) {
            type--;
        }
        if (type != 2) {
            (actor + type)[0x5C] = 99;
        }
        if (type == 2 && unk_0 && func_8010A430(actor)) {
            unk_1 = func_800F5F24(func_800F54E4());
            func_800EB860(func_80108EF4, actor);
            spawn_y = *(f32 *) (actor + 0x8) + func_800EC708(handle);
            _chbaddiesetup_entrypoint_5(_chbaddiesetup_entrypoint_10, unk_0 + 2,
                                        *(s32 *) (actor + 0x4), *(s32 *) &spawn_y,
                                        *(s32 *) (actor + 0xC), *(s32 *) &unk_1);
            func_800EB874();
        }
        switch (type) {
            case 0:
                func_80800EF0_sucoasterfly(*(s32 *) actor, hitter);
                break;
            case 1:
                func_80800F44_sucoasterfly(*(s32 *) actor, hitter);
                break;
            case 2:
                func_80800FA8_sucoasterfly(*(s32 *) actor, hitter);
        }
    }
    if (killed) {
        func_8010D930(1, *(s32 *) (actor + 0x70) & 1, actor + 4, D_80802294_sucoasterfly);
        _subaddiejoy_entrypoint_10(actor, 1.0f, 0.25f);
    }
}

// Enters a state: per-state setup.
void func_808014AC_sucoasterfly(param_0, state) Actor *param_0;
s32 state;
{
    FlyData *fly;
    FlyInfo *info;
    s32 prev_state;
    f32 home_pos[3];

    fly = func_80100094(param_0, 0);
    info = _sucoasterflydata_entrypoint_1(fly->unk11_4);
    prev_state = param_0->unk70_10;
    func_80102424(param_0, state);
    switch (state) {
        case 1:
            param_0->unk58 = info->unk24;
            fly->unkC = 0.0f;
            break;
        case 2:
            OD(3) = fly->unkC = 0.0f;
            break;
        case 3:
            param_0->unk58 = info->unk26;
            fly->unkC =
                func_80107C00() * func_800DC128(_sucoasterflydata_entrypoint_3(fly->unk11_4),
                                                _sucoasterflydata_entrypoint_4(fly->unk11_4));
            break;
        case 4:
            param_0->unk54 = func_8010CD28(param_0);
            fly->unkC = func_80107C00() * _sucoasterflydata_entrypoint_3(fly->unk11_4);
            OD(3) = 0.0f;
            break;
        case 5:
            func_800EE940(fly->unk12, param_0->position);
            break;
        case 6:
            if (prev_state != 5) {
                func_800EE940(fly->unk12, param_0->position);
            }
            func_80801A80_sucoasterfly(param_0);
            param_0->unk54 = func_80102D78(param_0, &OD(0));
            fly->unk11_3 = 1;
            OD(3) = fly->unkC =
                func_80107C00() * _sucoasterflydata_entrypoint_5(fly->unk11_4);
            break;
        case 7:
            fly->unkC = 0.0f;
            break;
        case 8:
            func_800EE88C(home_pos, fly->unk12);
            param_0->unk54 = func_80102D78(param_0, home_pos);
            fly->unk11_3 = 0;
            fly->unkC = func_80107C00() * _sucoasterflydata_entrypoint_3(fly->unk11_4);
            OD(3) = 0.0f;
            break;
        case 9:
            fly->unkC =
                (func_80107C00() * 1.2f) * _sucoasterflydata_entrypoint_4(fly->unk11_4);
            break;
        case 11:
            OD(7) = 0.0f;
            _subaddieDll_entrypoint_4(param_0, 1);
            ((FlyBits *) param_0)->unk64_25 = 0;
            ((FlyBits *) param_0)->unk64_24 = 0;
            ((FlyBits *) param_0)->unk70_4 = 0;
            ((FlyBits *) param_0)->unk70_25 = ((FlyBits *) param_0)->unk70_4;
            ((FlyBits *) param_0)->unk64_30 = 0;
            ((FlyBits *) param_0)->unk64_31 = ((FlyBits *) param_0)->unk64_30;
            param_0->unk14 &= ~0x80000;
            ((FlyBits *) param_0)->unk74_0 = 2;
            func_8010A570(param_0);
            func_80801CD0_sucoasterfly(param_0, 2);
            break;
        case 12:
            _subaddieaudioquick_entrypoint_2(param_0, param_0->position, D_808022AC_sucoasterfly);
    }
}

// Ramps the actor-data speed toward the base speed.
void func_8080181C_sucoasterfly(actor) Actor *actor;
{
    CoasterFlySpeed1482 *fly;
    f32 rate;

    fly = func_80100094(actor, 0);
    rate = (fly->local_0 < ((f32 *) actor->actorData)[3]
                   ? func_800F0E00(((f32 *) actor->actorData)[3], 10.0f)
                   : fly->local_0) *
              0.1f;
    ((f32 *) actor->actorData)[3] =
        func_800F15F8(((f32 *) actor->actorData)[3], fly->local_0, func_80107C00() * rate);
}

// Same ramp, scaled by the stick input when joystick-driven.
void func_808018BC_sucoasterfly(actor) Actor *actor;
{
    u8 *fly;
    f32 rate;
    f32 stick;

    fly = (u8 *) func_80100094(actor, 0);
    if (((CoasterFlyJoyFlag *) actor)->local_0)
        stick = _subaddiejoy_entrypoint_9(actor, 0, 0);
    else
        stick = 1.0f;
    rate = (*(f32 *) (fly + 0xC) < *(f32 *) ((u8 *) actor + 0x24)
                   ? func_800F0E00(*(f32 *) ((u8 *) actor + 0x24), 10.0f)
                   : *(f32 *) (fly + 0xC)) *
              0.1f;
    *(f32 *) ((u8 *) actor + 0x24) =
        func_800F15F8(*(f32 *) ((u8 *) actor + 0x24), *(f32 *) (fly + 0xC) * stick,
                      func_80107C00() * rate);
}

// Applies speed and target height; on a collision (not joystick-driven) turns around into state 2.
void func_808019A0_sucoasterfly(Actor *actor)
{
    f32 target_y;
    s32 move_flags;

    target_y = func_80801E5C_sucoasterfly(actor);
    move_flags = ((CoasterFlyMovementFlags *) actor)->local_0 ? 0x404027 : 0x504327;
    func_808018BC_sucoasterfly(actor);
    func_800EEB9C((f32 *) &actor->actorData[4], actor->rotation[1],
                  ((f32 *) actor->actorData)[3]);
    ((f32 *) actor->actorData)[5] =
        func_800F0D50(target_y - actor->position[1], -300.0f, 300.0f);
    if ((func_8010B990(actor, move_flags) & 0x24) &&
        !((CoasterFlyMovementFlags *) actor)->local_0) {
        func_80102924(actor, actor->rotation[1] + 180.0f);
        func_808014AC_sucoasterfly(actor, 2);
    }
}

s32 func_80801A80_sucoasterfly(s32 actor)
{
    func_800F5BF0(func_800F54E4(), actor + 0x18);
}

// Returns 1 and enters state 4 once the player is noticed.
s32 func_80801AB0_sucoasterfly(Actor *actor)
{
    if (!((CoasterFlyEligibility *) actor)->local_0)
        return 0;
    if (((CoasterFlyEligibility *) actor)->local_1)
        return 1;
    if (func_801072A8(actor) || ((CoasterFlyEligibility *) actor)->local_2)
        return 0;
    if (!_subaddierouteDll_entrypoint_4(actor))
        return 0;
    if (!func_8010C9B0(actor->position, 0x578))
        return 0;
    if (!func_8010C500(actor))
        return 0;
    if (!_suchase_entrypoint_1(actor))
        return 0;
    func_808014AC_sucoasterfly(actor, 4);
    return 1;
}

// Returns 1 and leaves the chase (state 7 or 1) when the player is lost.
s32 func_80801B90_sucoasterfly(Actor *actor)
{
    s32 lost;
    CodexCoasterFlyFlags *fly;

    lost = 0;
    if (((CodexCoasterActorFlags *) ((u8 *) actor + 0x64))->local_0) {
        return 0;
    }
    if (!func_8010C500(actor)) {
        lost = 1;
    }
    if (!lost) {
        if (!_suchase_entrypoint_1(actor)) {
            lost++;
        }
    }
    if (lost) {
        fly = func_80100094(actor, 0);
        func_808014AC_sucoasterfly(actor, fly->local_0 ? 7 : 1);
    }
    return lost;
}

void func_80801C44_sucoasterfly(Actor *actor, s32 slot)
{
    s32 info;
    s32 offset;

    info = _sucoasterflydata_entrypoint_1(
        (u32) *(u8 *) ((u8 *) func_80100094(actor, 0) + 0x11) >> 4);
    offset = slot * 8;
    if (*(s16 *) (info + offset + 4) != 0 &&
        func_80101E14(actor, *(s16 *) (info + offset + 0xA) * 0.00390625f)) {
        func_80801CD0_sucoasterfly(actor, slot);
    }
}

void func_80801CD0_sucoasterfly(actor, slot) Actor *actor;
s32 slot;
{
    f32 pitch;
    u8 *info;
    s32 unused;
    f32 ref_pos[3];

    info = func_80100094(actor, 0);
    info = (u8 *) _sucoasterflydata_entrypoint_1((u32) info[0x11] >> 4);
    if (*(s16 *) ((info + 4) + slot * 8)) {
        func_8010D640(ref_pos);
        if (func_800EEB40(ref_pos, actor->position) >= 9000000.0f) {
            return;
        }
        pitch = func_800DC178(-0.05f, 0.05f);
        pitch += *(s16 *) ((info + 8) + slot * 8) * 0.00390625f;
        func_800C4B64(pitch);
        func_800C4B7C(*(s16 *) ((info + 4) + slot * 8));
        func_800C4B70(*(s16 *) ((info + 6) + slot * 8));
        _subaddieaudioquick_entrypoint_2(actor, actor->position, D_808022BC_sucoasterfly);
    }
}

int func_80801DD0_sucoasterfly(Actor *actor)
{
    if (func_800F20BC(actor->rotation[1], func_8010CD28(actor), 20.0f)) {
        if (_subaddiejoy_entrypoint_6(actor, 1) == 1) {
            if (func_801021BC(actor, 5))
                func_808014AC_sucoasterfly(actor, 5);
            else
                func_808014AC_sucoasterfly(actor, 6);
            return 1;
        }
    }
    return 0;
}

// Returns the target flight height (floor-relative); falls back to the current y.
f32 func_80801E5C_sucoasterfly(actor)
Actor *actor;
{
    FlightClearance1570 *clearance;
    f32 probe_pos[3];
    f32 target_y;
    f32 floor_y;

    clearance = func_80100094(actor, 0);
    if (((CoasterFlyMovementFlags *) actor)->local_0) {
        func_8008FE94(5, probe_pos);
        return probe_pos[1] + 100.0f;
    }
    if (func_80104544(actor)) {
        target_y = func_8010473C(actor, 0) + clearance->local_0;
        func_800EE7F8(probe_pos, actor->position);
        probe_pos[1] = target_y;
        if (func_800CC338(probe_pos, (*(u32 *) ((u8 *) actor + 0x70) >> 25) - 1,
                          ((*(u32 *) ((u8 *) actor + 0x70) << 22) >> 26) - 1) != -1)
            return target_y;
    } else {
        if (func_80801FE4_sucoasterfly(actor, &floor_y, 50.0f, -(clearance->local_0 + 400.0f))) {
            func_800EE7F8(probe_pos, actor->position);
            probe_pos[1] = clearance->local_0 + floor_y;
            if (func_800CC338(probe_pos, (*(u32 *) ((u8 *) actor + 0x70) >> 25) - 1,
                              ((*(u32 *) ((u8 *) actor + 0x70) << 22) >> 26) - 1) != -1)
                return clearance->local_0 + floor_y;
        }
    }
    return actor->position[1];
}

// Floor raycast below the actor; returns 1 on a hit.
s32 func_80801FE4_sucoasterfly(u8 *actor, f32 *floor_y, f32 start_dy, f32 end_dy)
{
    f32 ray_start[3];
    f32 ray_end[3];
    f32 hit_pos[3];

    func_800EE7F8(ray_start, actor + 4);
    func_800EE7F8(ray_end, actor + 4);
    ray_start[1] += start_dy;
    ray_end[1] += end_dy;
    if (func_800BEF00(ray_start, ray_end, hit_pos, *(s32 **) ((char *) actor + 0x14)) != 0) {
        *floor_y = ray_end[1];
        return 1;
    }
    return 0;
}

// Creates the face expression when there is none yet.
void func_80802080_sucoasterfly(actor) s32 actor;
{
    u8 *fly;
    u8 *info;

    fly = func_80100094(actor, 0);
    info = _sucoasterflydata_entrypoint_1((u32) (*(u8 *) ((s8 *) (fly) + 0x11)) >> 4);

if ((func_80100094(actor, 1) == NULL) &&
    (_suexpression_entrypoint_1(*(u8 *) ((s8 *) info + 3)) != 0)) {
    _suexpression_entrypoint_7(actor, 1, *(s16 *) ((s8 *) info + 2));
    _suexpression_entrypoint_12(func_80100094(actor, 1), 0x42480000, 0x42200000);
    _suexpression_entrypoint_17(func_80100094(actor, 1), 0x7D0);
}

}

void func_80802128_sucoasterfly(Actor *actor)
{
    if (func_80100094(actor, 1) != 0) {
        _suexpression_entrypoint_8(actor, 1);
    }

}
s32 func_8080215C_sucoasterfly(s32 actor)
{
    s32 expression;

if (func_80100094(actor, 1)) {
    expression = func_80100094(actor, 1);
    // Matching: | 0 is needed for the match.
    _suexpression_entrypoint_18(expression | 0, 1);
}

}

// Local-data getter: the caller's extra data after the 0x1C flyer bytes.
s32 sucoasterfly_entrypoint_5(s32 actor)
{
    return (s32) ((u8 *) func_80100094(actor, 0) + 0x1C);
}

void sucoasterfly_entrypoint_6()
{
    func_80101870();
}

// TU-NOTE: the .data of this overlay is defined here in C (values from the ROM). The tables point to
// functions of this file; IDO's assembler schedules some of them differently unless the tables are
// defined in the same unit. D_80802280_sucoasterfly is declared int[] to match the object.
int D_80802280_sucoasterfly[5] = {0x0, (u32) func_80800F44_sucoasterfly,
                                  (u32) func_80800FA8_sucoasterfly,
                                  (u32) func_80801108_sucoasterfly, 0x0};
u8 D_80802294_sucoasterfly[24] = {0x0, 0x13, 0x4,  0x17, 0x0,  0xD,  0x1, 0xC,
                                  0x1, 0x26, 0x0,  0x16, 0x65, 0x90, 0x0, 0x1,
                                  0x3, 0x20, 0x13, 0x88, 0x0,  0x0,  0x0, 0x0};
u8 D_808022AC_sucoasterfly[16] = {0x0, 0x13, 0x4, 0x1F, 0x0,  0xD,  0x0, 0xC0,
                                  0x0, 0xD9, 0x0, 0x16, 0x6D, 0x60, 0x0, 0x0};
u8 D_808022BC_sucoasterfly[20] = {0x0, 0x21, 0x0, 0x1D, 0x0, 0x1E, 0x0, 0x1, 0x5, 0xDC,
                                  0xB, 0xB8, 0x0, 0x0,  0x0, 0x0,  0x0, 0x0, 0x0, 0x0};
