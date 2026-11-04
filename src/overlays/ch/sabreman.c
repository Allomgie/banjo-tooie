// Sabreman, the frozen explorer in Hailfire Peaks: carried by Banjo with the Taxi Pack, revived
// with Mumbo's life-force spell, then gives jiggy 0x3F (progress in the 2-bit flag 0x1CA).
#include "common.h"

extern int D_80801BE0_chsabreman[];
extern int D_80801D78_chsabreman[];
extern s32 D_80801DC0_chsabreman[];
extern s32 func_800DA564(s32, s32);
extern void func_800FFAB0(s32);
extern void *func_80100094(Actor *, s32);
extern void func_80102FDC(Actor *, f32);
extern void func_801017D0(void);
extern s32 _subaddietaxi_entrypoint_16;
extern void *_gccubesearch_entrypoint_15(s32, s32, f32 *);
extern void func_800EE88C(f32 *, void *);
extern void func_800EE814(void *, void *);
extern s32 func_80102BF8(Actor *, f32, f32, f32);
f32 func_80102D78(Actor *param_0, f32 *param_1);
extern void _sudeflect_entrypoint_0(void *, f32, f32, s32);
extern s32 D_80801BE8_chsabreman[];
extern void _capod_entrypoint_2(Unk80132ED0 *, s32, s32);
extern void _capod_entrypoint_8(s32);
extern void _capod_entrypoint_7(s32, s32);
extern void _gcdialogcamera_entrypoint_3(void *, f32);
extern void _gcdialogcamera_entrypoint_4(f32[3]);
extern void _gcdialogcamera_entrypoint_5(f32[3]);
extern void _gcdialogcamera_entrypoint_8(void);
extern void _capod_entrypoint_6(Unk80132ED0 *, s32, s32);
typedef union {
    s32 word;
    void *pointer;
} SabremanEventPayload;
typedef struct {
    u8 pad_0[0x74];
    u32 pad_1 : 11;
    u32 local_0 : 1;
    u32 pad_2 : 20;
} SabremanActorFlags;
extern s32 func_80101E14(Actor *, f32);
extern s32 func_80102CF4(Actor *, f32);
extern f32 func_800DC178(f32, f32);
extern f32 func_800EEB40(f32 *, f32 *);
extern void _subaddiepalette_entrypoint_2(Actor *, void *, s32, f32);
typedef struct {
    u8 pad_0[0x78];
    u32 pad_1 : 26;
    u32 local_0 : 1;
    u32 pad_2 : 5;
} SabremanSpawnFlags;
extern Actor *func_801084B0(s32, Actor **);
extern void *_chlifeforcespell_entrypoint_1(Actor **, f32 *, s32, f32, s32);
extern f32 func_80101F24(Actor *);
extern s32 func_80102320(Actor *, f32, f32);
extern void func_800DF744(s32, s32);
extern Vec3f D_80801E18_chsabreman;
extern Vec3f D_80801E24_chsabreman;
extern u8 D_80801F98_chsabreman[];
extern u8 D_80801F78_chsabreman[];
extern u8 D_80801F88_chsabreman[];
extern u8 D_80801F44_chsabreman[];
extern u8 D_80801F5C_chsabreman[];
extern u8 D_80801F6C_chsabreman[];
extern u8 D_80801F14_chsabreman[];
extern u8 D_80801F08_chsabreman[];
extern u8 D_80801E9C_chsabreman[];
extern u8 D_80801ED4_chsabreman[];
extern u8 D_80801EC4_chsabreman[];
extern u8 D_80801EFC_chsabreman[];
extern u8 D_80801E60_chsabreman[];
extern u8 D_80801E50_chsabreman[];
extern u8 D_80801E30_chsabreman[];
extern u8 D_80801E40_chsabreman[];
extern u8 D_80801E8C_chsabreman[];
extern u8 D_80801F2C_chsabreman[];
extern void _subaddieaudioquick_entrypoint_3(Actor *, f32 *, void *, f32);
extern void func_800EF1B8(f32 *, f32, f32);
extern void func_800BABB8(s32, f32 *, f32 *, f32, void *);
extern void func_800BBCB8(f32 *, s32, f32, s32, void *);
f32 func_8080112C_chsabreman();
void func_80801724_chsabreman();
void func_80800D30_chsabreman();
void func_80801218_chsabreman();

int *chsabreman_entrypoint_0()
{
    return &D_80801BE0_chsabreman;
}

int chsabreman_entrypoint_1()
{
    extern void *D_80801D30_chsabreman;
    return (int) &D_80801D30_chsabreman;
}

int *chsabreman_entrypoint_2()
{
    return &D_80801D78_chsabreman;
}

int chsabreman_entrypoint_3()
{
    return D_80801DC0_chsabreman;
}

void func_808011F8_chsabreman();

// Sets up Sabreman according to his progress flag 0x1CA.
int func_80800030_chsabreman(Actor *actor)
{
    u8 *data;
    data = func_80100094(actor, 0);
    func_80102FDC(actor, 0.45f);
    func_801088A8(actor, 0x10002000, 0, 0);
    _subaddielink_entrypoint_0(data + 0x810);
    if (_glcutDll_entrypoint_20()) {
        _subaddiepalette_entrypoint_0(actor, func_80100094(actor, 0), 0x7F1);
        func_80102424(actor, 0x19);
        actor->position[1] = func_8080112C_chsabreman((u8 *) actor);
        return 1;
    }
    switch (func_800DA564(0x1CA, 2)) {
        case 0:
            func_8010A85C(actor, 2);
            _subaddiepalette_entrypoint_0(actor, func_80100094(actor, 0), 0x7F0);
            func_80108B04(actor, 0);
            func_808011F8_chsabreman(actor, 1);
            func_8010A570(actor);
            *((u8 *) actor + 0x75) &= ~0x10;
            break;
        case 1:
            _subaddiepalette_entrypoint_0(actor, func_80100094(actor, 0), 0x7F0);
            if (func_800CB3E0(0xB) == 1) {
                func_80108B04(actor, 0);
            }
            func_808011F8_chsabreman(actor, 5);
            func_8010A590(actor);
            actor->position[1] = func_8080112C_chsabreman((u8 *) actor);
            break;
        case 2:
            _subaddiepalette_entrypoint_0(actor, func_80100094(actor, 0), 0x7F1);
            func_808011F8_chsabreman(actor, 10);
            func_8010A590(actor);
            actor->position[1] = func_8080112C_chsabreman((u8 *) actor);
            break;
        case 3:
            func_800FFAB0(actor);
            return 0;
    }
    return 1;
}

void func_808017D8_chsabreman();

s32 func_808011AC_chsabreman();

// Per-frame state machine (state in unk70_10).
void func_80800218_chsabreman(Actor *actor)
{
    extern u8 D_80801E16_chsabreman;
    extern u8 D_80801E08_chsabreman[];
    extern u8 D_80801BF8_chsabreman[];
    extern u8 D_80801C20_chsabreman[];

    u8 *data;
    s32 unk_0;
    s32 unk_1;
    s32 text_id;

    data = (u8 *) func_80100094(actor, 0);
    unk_0 = 2;
    unk_1 = 8;

    switch (actor->unk70_10) {
        case 1:
        case 24:
            break;
        case 2:
            if (func_800D9078(&actor->unk58)) {
                func_808011F8_chsabreman(actor, 3);
                func_80101180(0x1FE, 0xA, 0);
                func_8010A85C(actor, 1);
                ((SabremanActorFlags *) actor)->local_0 = 1;
            }
            break;

        case 3:
            if (func_80101DDC(actor)) {
                func_808011F8_chsabreman(actor, 4);
            }
            break;

        case 4:
            if (func_80101DDC(actor)) {
                func_80801724_chsabreman(actor, 3, 1);
                func_8010A590(actor);

                _subaddiedialog_entrypoint_11(actor->unk0, 0x1271, 0xE, actor->position, 0xAA);

                func_808011F8_chsabreman(actor, 6);
                func_800DA7A8(0x1CA, 1, 2);
            }
            break;

        case 5:
            unk_1 = 0;
            D_80801E16_chsabreman = 6;

            _subaddiedialog_entrypoint_8(actor, actor->position, D_80801E08_chsabreman,
                                         D_80801BF8_chsabreman, 5);
            break;

        case 7:
            if (func_80101DDC(actor)) {
                _subaddieDll_entrypoint_4(actor, 0);

                if (*(s32 *) ((u8 *) actor + 0x50) >= 3) {
                    func_800F82D4(func_800F54E4(), 0);
                    if (!func_800F6CC8(func_800F54E4())) {
                        data = (u8 *) func_80100094(actor, 0);

                        _subaddiepalette_entrypoint_2(actor, data, 0x7F1, 3.0f);

                        func_808011F8_chsabreman(actor, 8);
                        func_808017D8_chsabreman(actor, 1, 0x30);
                    } else {
                        func_808011F8_chsabreman(actor, 5);
                    }
                } else {
                    func_808011F8_chsabreman(actor, 5);
                }
            }
            break;

        case 8:
            data = (u8 *) func_80100094(actor, 0);

            if (*(s16 *) (data + 4) == 0) {
                func_808011F8_chsabreman(actor, 9);
                actor->unk64_20 = 0;
            }
            break;

        case 9:
            if (func_80101E14(actor, 0.23f)) {
                func_80101180(0x1FE, 0x48, 3);
                actor->unk64_20 = 1;
            }

            if (func_80101DDC(actor)) {
                if (func_800F64A4(func_800F54E4(), 0x400)) {
                    text_id = 0x12D9;
                } else {
                    text_id = 0x1273;
                }

                func_808011F8_chsabreman(actor, 0xB);
                func_800DA7A8(0x1CA, 2, 2);
                func_80801724_chsabreman(actor, 2, 1);

                _subaddiedialog_entrypoint_11(actor->unk0, text_id, 0xE, actor->position, 0xAA);
            }
            break;

        case 10:
            func_808011AC_chsabreman(actor);
            D_80801E16_chsabreman = 0xB;

            _subaddiedialog_entrypoint_8(actor, actor->position, D_80801E08_chsabreman,
                                         D_80801C20_chsabreman, 4);
            break;

        case 11:
            func_808011AC_chsabreman(actor);
            break;

        case 13:
            unk_0 = 0;
            break;

        case 14:
            unk_0 = 0;
            func_808011AC_chsabreman(actor);

            if (_subaddietaxi_entrypoint_1(actor, 0xB)) {
                func_808011F8_chsabreman(actor, 0x11);

                _subaddiedialog_entrypoint_11(actor->unk0, 0x1275, 0xE, actor->position, 0xAA);

                func_800DA7A8(0x1CA, 3, 2);
            }
            break;

        case 15:
            if (_subaddietaxi_entrypoint_11(actor, 0xB)) {
                if (_subaddietaxi_entrypoint_5(actor, 0xB)) {
                    _subaddietaxi_entrypoint_14(actor, 0xB);
                    func_808011F8_chsabreman(actor, 0x12);
                    func_8010A590(actor);
                }
            }

            unk_0 = _subaddietaxi_entrypoint_12(actor, 0xB);
            break;

        case 16:
            func_808011AC_chsabreman(actor);
            break;

        case 17:
            func_808011AC_chsabreman(actor);
            break;

        case 18:
            if (_subaddietaxi_entrypoint_15(actor, 0xB)) {
                func_808011F8_chsabreman(actor, 0xC);
            }
            break;

        case 19: {
            f32 target[3];
            func_800EE88C(target, data + 0x81A);

            actor->unk54 = func_80102D78(actor, target);

            func_80102BF8(actor, 0.1f, 4.0f, 150.0f);

            if (func_80102CF4(actor, 8.0f)) {
                func_808011F8_chsabreman(actor, 0x14);
                *(f32 *) ((u8 *) actor + 0x24) = 50.0f;
            }
            break;
        }
        case 20: {
            f32 target[3];
            func_800EE88C(target, data + 0x81A);

            actor->unk54 = func_80102D78(actor, target);

            func_80102BF8(actor, 0.1f, 4.0f, 150.0f);

            func_8010B990(actor, 0x1005);

            if (func_800EEB40(actor->position, target) < 2500.0f) {
                func_808011F8_chsabreman(actor, 0x15);
            }
            break;
        }
        case 21:
            actor->unk54 = (f32) *(s16 *) (data + 0x818);

            func_80102BF8(actor, 0.1f, 4.0f, 150.0f);

            if (func_80102CF4(actor, 8.0f)) {
                func_808011F8_chsabreman(actor, 0x16);
            }
            break;

        case 22:
            if (func_80101DDC(actor)) {
                func_808011F8_chsabreman(actor, 0x17);
            }
            break;

        case 23:
            if (!func_800C0638() && func_800D90A4(&actor->unk58) &&
                func_8010CAC0(actor->position, 0x190) && *(f32 *) &actor->unk58 <= 0.0f) {
                _subaddiedialog_entrypoint_11(actor->unk0, func_800DC128(0, 3) + 0x1293, 0,
                                              actor->position, 0xAA);

                func_80102424(actor, 0x18);

                *(f32 *) &actor->unk58 = func_800DC178(8.0f, 12.0f);
            }
    }

    _subaddietaxi_entrypoint_9(actor, 0xB);

    data = (u8 *) func_80100094(actor, 0);
    _subaddiepalette_entrypoint_1(actor, data);

    func_80801218_chsabreman(actor);

    if ((unk_0 | unk_1) != 0) {
        f32 effect_pos[3];
        if (_subaddieskeleton_entrypoint_0(actor, 1, effect_pos)) {
            _sudeflect_entrypoint_0(effect_pos, 0.0f, 90.0f, unk_0 | unk_1);
        }
    }
}

void func_808016E4_chsabreman();

s32 func_8080167C_chsabreman();

void func_80801010_chsabreman();

s32 func_808008C8_chsabreman(Actor *actor, s32 msg, s32 arg)
{
    extern void _chsabreman_entrypoint_0(void);
    u8 *data;
    Actor *companion;

    switch (msg) {
        case 0x3E:
            if (func_800DA564(0x1CA, 2) == 2) {
                if (_subaddietaxi_entrypoint_2(actor, 0xB)) {
                    func_808011F8_chsabreman(actor, 0xD);
                }
            }

            break;

        case 0x40:
            if (func_800DA564(0x1CA, 2) == 1) {
                if (actor->unk70_10 == 5) {
                    func_800FC660(0xE);
                    func_808011F8_chsabreman(actor, 7);
                    _subaddieDll_entrypoint_4(actor, 1);

                    ++*(s32 *) ((u8 *) actor + 0x50);

                    if (*(s32 *) ((u8 *) actor + 0x50) == 3) {
                        func_800F8300(func_800F54E4(), 2, actor->position);
                    }
                }
            }

            break;

        case 0x3D:
            data = (u8 *) func_80100094(actor, 0);

            switch (arg) {
                case 0:
                    companion = func_801084B0(0x1FE, &actor);

                    _subaddielink_entrypoint_1(data + 0x810, companion->unk0);

                    func_80102FDC(companion, actor->scale);

                    companion->unk3C = actor->unk0;
                    break;

                case 1:
                    actor->unk3C = _chlifeforcespell_entrypoint_1(&actor, actor->position,
                                                                    0x64, 4.0f, 0x12);

                    func_808017D8_chsabreman(actor, 0x1B, 0x30);
            }

            break;

        case 0x2E:
            switch (actor->unk70_10) {
                case 6:
                    func_808016E4_chsabreman(actor);
                    func_808011F8_chsabreman(actor, 5);
                    _subaddieDll_entrypoint_4(actor, 0);
                    break;

                case 0x0B:
                    func_808016E4_chsabreman(actor);
                    func_808011F8_chsabreman(actor, 0xA);
                    break;

                case 0x18:
                    func_808011F8_chsabreman(actor, 0x17);
            }

            if (((s16 *) &arg)[0] == 0x1275) {
                func_800C01A8(0x64, 0);

                func_808017D8_chsabreman(actor, 8, 0x2030);

                func_800D1000(0x3F, 1, 0, 1, 0);
            }

            break;

        case 0x0B:
            if (arg == 8) {
                func_808016E4_chsabreman(actor);
                func_808011F8_chsabreman(actor, 0x13);
                return 4;
            }

            return 3;

        case 0x44:
            func_80801010_chsabreman(actor, arg);
            break;

        case 0x4B:
            func_80108B04(actor, 1);
            _subaddieDll_entrypoint_4(actor, 1);
            func_808011F8_chsabreman(actor, 2);
            actor->unk58 = 14.0f;
            break;

        case 0x4C:
            actor->unk3C = 0;
            break;

        case 0x52:
            _gcdialogcamera_entrypoint_3(&D_80801BE8_chsabreman, actor->scale);
            break;

        case 0x1F:
            func_80800D30_chsabreman(actor, arg);
            break;

        case 0x57:
            return func_8080167C_chsabreman(actor, arg & 0xFFFF,
                                            (arg & 0xFFFF0000) >> 16);

        case 0x95:
            *(s32 *) ((char *) actor + 0x50) = 0;

            if (_glcutDll_entrypoint_20() ||
                _subaddietaxi_entrypoint_13(actor, 0xB, _chsabreman_entrypoint_0, 3)) {
                func_80800030_chsabreman(actor);
            } else if (((SabremanSpawnFlags *) actor)->local_0) {
                func_800FFAB0(actor);
            }

            break;

        case 0x29:
            data = (u8 *) func_80100094(actor, 0);
            _subaddiepalette_entrypoint_4(actor, data);
            break;

        default:
            return 0;
    }
    return 1;
}

void func_80800CDC_chsabreman(s32 actor, s32 value)
{
    s32 linked;
    if (func_80101808(actor, &func_801017D0)) {
        linked = _subaddielink_entrypoint_4((u8 *) func_80100094(actor, 0) + 0x810);
        if (linked != 0) {
            func_8010A764(linked, value);
        }
    }
}

void func_80800D30_chsabreman(actor, arg) Actor *actor;
s32 arg;
{
    s32 anim_id;
    f32 spell_pos[3];
    f32 saved_pos[3];
    s32 early;
    s32 window_a;
    s32 window_b;

    anim_id = func_801022E4(actor);
    if (actor->unk3C) {
        _subaddiefade_entrypoint_9(actor, saved_pos);
        _chlifeforcespell_entrypoint_2(actor, actor->unk3C, spell_pos);
        _subaddiefade_entrypoint_11(actor, spell_pos);
        func_801015D0(actor);
        _subaddiefade_entrypoint_11(actor, saved_pos);
    } else {
        func_801015D0(actor);
    }
    switch (anim_id) {
        case 0x2FB:
            if (func_80101F24(actor) < 0.602f)
                early = 1;
            else
                early = 0;
            window_a = func_80102320(actor, 0.602f, 0.819f);
            func_800DF744(5, 1);
            func_800DF744(3, 0);
            func_800DF744(6, early && actor->unk64_20);
            func_800DF744(4, window_a);
            break;
        case 0x2FA:
            window_b = func_80102320(actor, 0.33f, 0.93f);
            func_800DF744(5, !window_b);
            func_800DF744(3, window_b);
            func_800DF744(6, 0);
            func_800DF744(4, 0);
            break;
        default:
            func_800DF744(5, 1);
            func_800DF744(3, 0);
            func_800DF744(6, 0);
            func_800DF744(4, 0);
    }
    _subaddiepalette_entrypoint_3(actor, func_80100094(actor, 0), arg);
}

void func_80800F04_chsabreman(s32 unk_0, u8 *pos, s32 unk_1, s32 unk_2)
{
    if (func_800DA564(0x1CA, 2) != 3) {
        _chbaddiesetup_entrypoint_6(&_subaddietaxi_entrypoint_16, unk_0,
                                    *(s32 *) ((s8 *) pos + 0), *(s32 *) ((s8 *) pos + 4),
                                    *(s32 *) ((s8 *) pos + 8), unk_1, unk_2);
    }
}

s32 func_80800F74_chsabreman(s32 unk_0, s32 pos, s32 target_pos)
{
    s32 node;
    s32 cube;

    if (func_800EA05C() == 0x127) {
        node = _gccubesearch_entrypoint_15(0x154, 0, pos);
        if (node != 0) {
            func_800EE88C(target_pos, node);
            cube = func_800CBC3C(target_pos);
            if (func_800CBC3C(pos) == cube) {
                return 2;
            }
        }
    }
    func_800C05B8(0x1276, 1, 0, 0, 0, 0, 0);
    return 1;
}

void func_80801010_chsabreman(Actor *actor, s32 unk_0)
{
    u8 *data;
    f32 anchor_pos[3];
    u8 *node;
    data = func_80100094(actor, 0);
    if (func_80800030_chsabreman(actor)) {
        switch (func_800CB3E0(unk_0)) {
            case 1:
                break;
            case 3:
                _subaddietaxi_entrypoint_10(actor, unk_0, 15);
                break;
            case 4:
                func_800EE88C(anchor_pos, _gccubesearch_entrypoint_15(0x154, 0, actor->position));
                node = _gccubesearch_entrypoint_15(0x347, 0, actor->position);
                func_800EE814(data + 0x81A, node);
                *(s16 *) (data + 0x818) = *(u32 *) (node + 0xC) >> 23;
                func_8010A570(actor);
                _subaddietaxi_entrypoint_0(actor, unk_0, anchor_pos, 14);
                break;
            case 6:
                func_808011F8_chsabreman(actor, 16);
                func_8010A570(actor);
        }
    }
}

f32 func_8080112C_chsabreman(actor)
u8 *actor;
{
    f32 top[3];
    f32 bottom[3];
    f32 hit[3];

    func_800EE7F8(top, actor + 4);
    func_800EE7F8(bottom, actor + 4);
    top[1] += 100.0f;
    bottom[1] -= 400.0f;
    func_800BEF00(top, bottom, hit, *(s32 **) (actor + 0x14));
    return bottom[1];
}

s32 func_808011AC_chsabreman(Actor *actor)
{
    f32 target[3];

    func_8010D600(target);
    *(f32 *) ((char *) actor + 0x54) = func_80102D78(actor, target);
    return func_80102BF8(actor, 0.1f, 4.0f, 150.0f);
}

void func_808011F8_chsabreman()
{
    func_80102424();
}

void func_80801218_chsabreman(actor) Actor *actor;
{
    Vec3f unk_0;
    f32 bone_pos[3];
    f32 spawn_pos[3];
    f32 bone_pos_b[3];
    Vec3f unk_1;

    switch (func_801022E4(actor)) {
        case 0x2F7:
            unk_0 = D_80801E18_chsabreman;
            _subaddieaudioquick_entrypoint_4(actor, actor->position, D_80801E30_chsabreman,
                                             unk_0.f);
            _subaddieaudioquick_entrypoint_3(actor, actor->position, D_80801E40_chsabreman,
                                             0.2f);
            return;
        case 0x2F9:
            if (func_80101E14(actor, 0.02f)) {
                if (_subaddieskeleton_entrypoint_2(actor->unk0, 5, bone_pos)) {
                    func_800EE7F8(spawn_pos, bone_pos);
                    func_800EF1B8(spawn_pos, actor->rotation[1], -50.0f);
                    spawn_pos[1] += 30.0f;
                    func_800BABB8(0, bone_pos, spawn_pos, 1.0f, D_80801E60_chsabreman);
                }
                _subaddieaudioquick_entrypoint_2(actor, actor->position, D_80801E50_chsabreman);
            }
            _subaddieaudioquick_entrypoint_4(actor, actor->position, D_80801E8C_chsabreman,
                                             D_80801E9C_chsabreman);
            return;
        case 0x2FA:
            _subaddieaudioquick_entrypoint_3(actor, actor->position, D_80801EC4_chsabreman,
                                             0.0f);
            _subaddieaudioquick_entrypoint_3(actor, actor->position, D_80801E30_chsabreman,
                                             0.75f);
            if (func_80101F24(actor) < 0.7f && func_8001210C(1) &&
                _subaddieskeleton_entrypoint_2(actor->unk0, 4, bone_pos_b)) {
                func_800BBCB8(bone_pos_b, 0, 1.0f, 1, D_80801ED4_chsabreman);
            }
            return;
        case 0x2FB:
            _subaddieaudioquick_entrypoint_3(actor, actor->position, D_80801EFC_chsabreman,
                                             0.6f);
            _subaddieaudioquick_entrypoint_3(actor, actor->position, D_80801F08_chsabreman,
                                             0.8f);
            return;
        case 0x2FC:
            _subaddieaudioquick_entrypoint_3(actor, actor->position, D_80801F14_chsabreman,
                                             0.025f);
            _subaddieaudioquick_entrypoint_3(actor, actor->position, D_80801F2C_chsabreman,
                                             0.12f);
            _subaddieaudioquick_entrypoint_4(actor, actor->position, D_80801F44_chsabreman,
                                             D_80801F5C_chsabreman);
            return;
        case 0x2FD:
            unk_1 = D_80801E24_chsabreman;
            _subaddieaudioquick_entrypoint_4(actor, actor->position, D_80801E30_chsabreman,
                                             unk_1.f);
            return;
        case 0x2FE:
            _subaddieaudioquick_entrypoint_3(actor, actor->position, D_80801F6C_chsabreman,
                                             0.8f);
            return;
        case 0x2FF:
            if (!actor->unk5F) {
                actor->unk5F = func_800C4350(0, actor->position, D_80801F78_chsabreman);
            }
            if (actor->unk5F) {
                if (func_80101E14(actor, 0.0f)) {
                    func_800C4350(actor->unk5F, actor->position, D_80801F88_chsabreman);
                }
                if (func_80101E14(actor, 0.65f)) {
                    func_800C4350(actor->unk5F, actor->position, D_80801F98_chsabreman);
                }
            }
    }
}

void func_8080158C_chsabreman(s32 actor)
{
    func_80102FDC((Actor *) actor, 0.45f);
    if (func_800DA564(0x1CA, 2) != 3) {
        func_800FFAB0(actor);
    }
}

void func_808015D4_chsabreman(Actor *actor)
{
    // Matching: padding local for the stack frame.
    s8 _sfpad[8];
    s32 unk_0;

    if (_subaddieskeleton_entrypoint_0(actor, 1, &unk_0) != 0) {
        _sudeflect_entrypoint_0((u8 *) actor + 4, 0.0f, 100.0f, 0xA);
    }
    func_80801218_chsabreman(actor);
}

s32 func_80801620_chsabreman(s32 actor, s32 unk_0)
{
    func_800DF744(5, 1);
    func_800DF744(3, 0);
    func_800DF744(6, 0);
    func_800DF744(4, 0);
    func_80101870(actor, unk_0);
}

s32 func_8080167C_chsabreman(Actor *actor, s32 unk_0, s32 unk_1)
{
    u8 *data;

    if (_gcdialogcamera_entrypoint_0(unk_0, unk_1)) {
        data = func_80100094(actor, 0);
        if (data != NULL && *(s16 *) (data + 0x820) != 2) {
            func_80801724_chsabreman(actor, 2, 1);
        }
        return 2;
    }
    return 1;
}

void func_808016E4_chsabreman(s32 actor)
{
    u8 *data;

    data = func_80100094(actor, 0);
    if (*(s16 *) ((s8 *) data + 0x820) != 0) {
        _capod_entrypoint_3(0);
        *(s16 *) ((s8 *) data + 0x820) = 0;
    }
}

void func_80801724_chsabreman(actor, unk_0, unk_1) Actor *actor;
s32 unk_0;
s32 unk_1;
{
    u8 *data;

    data = func_80100094(actor, 0);
    switch (*(s16 *) (data + 0x820)) {
        case 0:
            _capod_entrypoint_2(actor->unk0, 14, 0);
        case 1:
            _capod_entrypoint_8(1);
            *(s16 *) (data + 0x820) = 2;
            _gcdialogcamera_entrypoint_3(&D_80801BE8_chsabreman, actor->scale);
            _gcdialogcamera_entrypoint_4(actor->position);
            _gcdialogcamera_entrypoint_5(actor->rotation);
            _gcdialogcamera_entrypoint_8();
        case 2:
            _capod_entrypoint_7(unk_0, unk_1);
    }
}

void func_808017D8_chsabreman(Actor *actor, s32 unk_0, s32 unk_1)
{
    u8 *data;

    data = func_80100094(actor, 0);
    switch (*(s16 *) (data + 0x820)) {
        case 0:
            _capod_entrypoint_2(actor->unk0, 14, unk_1);
        case 2:
            *(s16 *) (data + 0x820) = 1;
        case 1:
            _capod_entrypoint_6(actor->unk0, unk_0, unk_1);
    }
}

void func_80801864_chsabreman(u8 *actor)
{
    if (func_800DA564(0x1CA, 2) > 0) {
        func_80102424(actor, 3);
        func_80103110(actor, 0);
    }
    if (func_800DA564(0x1CA, 2) >= 2) {
        actor[0x65] = (actor[0x65] & 0xFF) | 0x10;
    }
    func_8010A800(actor, 2);
}

void func_808018DC_chsabreman(Actor *actor)
{
    switch (actor->unk70_10) {
        case 2:
            if (func_80101DDC(actor)) {
                func_80102424(actor, 3);
                func_80103110(actor, 0);
            }
        case 3:
            break;
    }
}

void func_8080193C_chsabreman(Actor *actor, s32 unk_0)
{
    func_800DF744(3, actor->unk64_20 ? 0 : 1);
    func_800DF744(4, 1);
    func_800DF744(5, 1);
    func_80101870(actor, unk_0);
}

s32 func_808019A4_chsabreman(Actor *actor, s32 msg, SabremanEventPayload payload)
{
    switch (msg) {
        case 0xA:
            func_80102424(actor, 2);
            break;
        case 0x48:
            actor->unk64_20 = 1;
            break;
        default:
            return 0;
    }
    return 1;
}

// TU-NOTE: The overlay .data is defined in this file. Its tables hold pointers to functions
// of this file; IDO's assembler schedules some of them differently unless the tables are in
// the same unit. D_80801E16_chsabreman is a linker symbol at D_80801E08_chsabreman + 0xE.
// The externs D_80801BE0_chsabreman, D_80801BE8_chsabreman and D_80801D78_chsabreman are
// declared as arrays to match their objects.
extern void func_80105834();
extern void func_80108ED0();
extern void func_80107C2C();
int D_80801BE0_chsabreman[2] = {(u32) func_80800F74_chsabreman, (u32) func_80800F04_chsabreman};
s32 D_80801BE8_chsabreman[4] = {0x43820000, 0x43750000, 0x43750000, 0x43340000};
u8 D_80801BF8_chsabreman[40] = {0x0,  0x0,  0x0,  0x1,  0x12, 0x72, 0x2,  0x0, 0x0,  0x0,
                                0x2,  0x0,  0x12, 0x72, 0x2,  0x0,  0x0,  0x0, 0x4,  0x0,
                                0x12, 0x72, 0x2,  0x0,  0x0,  0x0,  0x10, 0x0, 0x12, 0x72,
                                0x2,  0x0,  0xFF, 0xFE, 0xDF, 0xFF, 0x12, 0xB, 0x3,  0x0};
u8 D_80801C20_chsabreman[32] = {0x0, 0x0,  0x4,  0x1,  0x12, 0x74, 0x2,  0x0,  0x0, 0x0,  0x2,
                                0x0, 0x12, 0xDA, 0x2,  0x0,  0x0,  0x0,  0x10, 0x0, 0x12, 0xDB,
                                0x2, 0x0,  0xFF, 0xFE, 0xDF, 0xFF, 0x12, 0xB,  0x3, 0x0};
u32 D_80801C40_chsabreman[52] = {
    0x0,        0x0,       0x40AB851F, 0x2F70020, 0x40AB851F, 0x2F70020, 0x40AB851F, 0x2F70002,
    0x3F828F5C, 0x2F80002, 0x40B4CCCD, 0x2F90001, 0x40B4CCCD, 0x2F90001, 0x3F99999A, 0x2FA0002,
    0x40F9999A, 0x2FC0001, 0x402AE148, 0x2FB0002, 0x40F9999A, 0x2FC0001, 0x40F9999A, 0x2FC0001,
    0x40F9999A, 0x2FC0001, 0x40F9999A, 0x2FC0001, 0x40F9999A, 0x2FC0001, 0x40F9999A, 0x2FC0001,
    0x40F9999A, 0x2FC0001, 0x40F9999A, 0x2FC0001, 0x40F9999A, 0x2FC0001, 0x3FB33333, 0x2FD0001,
    0x3FB33333, 0x2FD0001, 0x3FB33333, 0x2FD0001, 0x3F333333, 0x2FE0002, 0x3FF70A3D, 0x2FF0001,
    0x3FF70A3D, 0x2FF0001, 0x40F9999A, 0x2FC0001};
u32 D_80801D10_chsabreman[8] = {0x0,        0x0,       0x40AB851F, 0x2EC0020,
                                0x40AB851F, 0x2EC0002, 0x40AB851F, 0x2EC0084};
void *D_80801D30_chsabreman = (void *) 0x00B00346;
static u32 D_80801D30_chsabreman_rest[17] = {0x7EF0001,
                                             (u32) &D_80801C40_chsabreman,
                                             (u32) func_80800218_chsabreman,
                                             (u32) func_80105834,
                                             (u32) func_80800CDC_chsabreman,
                                             0xBB80000,
                                             0x40000000,
                                             0x0,
                                             0x840164,
                                             0x0,
                                             (u32) func_80108ED0,
                                             0x8240000,
                                             0x0,
                                             (u32) func_80107C2C,
                                             0x84000010,
                                             (u32) func_808008C8_chsabreman,
                                             0x0};
int D_80801D78_chsabreman[18] = {0xB00347,
                                 0x7EF0017,
                                 (u32) &D_80801C40_chsabreman,
                                 (u32) func_808015D4_chsabreman,
                                 (u32) func_80105834,
                                 (u32) func_80801620_chsabreman,
                                 0xBB80000,
                                 0x0,
                                 0x7F1,
                                 0x840020,
                                 0x0,
                                 0x0,
                                 0x0,
                                 (u32) func_8080158C_chsabreman,
                                 (u32) func_80107C2C,
                                 -0x7BFFDBEE,
                                 0x0,
                                 0x0};
s32 D_80801DC0_chsabreman[18] = {0x15801FE,
                                 0x7ED0001,
                                 (u32) &D_80801D10_chsabreman,
                                 (u32) func_808018DC_chsabreman,
                                 (u32) func_80105834,
                                 (u32) func_8080193C_chsabreman,
                                 0x0,
                                 0x0,
                                 0x0,
                                 0x80C,
                                 0x0,
                                 0x0,
                                 0x0,
                                 (u32) func_80801864_chsabreman,
                                 (u32) func_80107C2C,
                                 -0x7FFFD5FE,
                                 (u32) func_808019A4_chsabreman,
                                 0x0};
u8 D_80801E08_chsabreman[16] = {0x0, 0x0, 0x0, 0x0, 0x1, 0x2C, 0x0, 0xAA,
                                0x0, 0x0, 0x0, 0xE, 0x6, 0x3C, 0x0, 0x0};
Vec3f D_80801E18_chsabreman = {0.24f, 0.28f, -1.0f};
Vec3f D_80801E24_chsabreman = {0.1f, 0.6f, -1.0f};
u8 D_80801E30_chsabreman[16] = {0x0, 0x13, 0x4, 0x4,  0x0,  0xD,  0x0, 0xF3,
                                0x1, 0xC,  0x0, 0x16, 0x27, 0x10, 0x0, 0x0};
u8 D_80801E40_chsabreman[16] = {0x0, 0x13, 0x3, 0xFF, 0x0,  0xD,  0x0, 0xF3,
                                0x1, 0xC,  0x0, 0x16, 0x46, 0x50, 0x0, 0x0};
u8 D_80801E50_chsabreman[16] = {0x0, 0x13, 0x5, 0x6B, 0x0,  0xD,  0x0, 0xD9,
                                0x0, 0xF3, 0x0, 0x16, 0x46, 0x50, 0x0, 0x0};
u8 D_80801E60_chsabreman[44] = {0x4,  0x10, 0x0,  0x1D, 0x9,  0xDD, 0x0,  0x22, 0x0,  0x33, 0x0,
                                0x40, 0x0,  0x4C, 0x0,  0x59, 0x0,  0x15, 0x0,  0x33, 0x0,  0xB3,
                                0x0,  0x2D, 0x0,  0x1E, 0x0,  0x28, 0x0,  0x2A, 0x0,  0xC,  0x0,
                                0x33, 0x1,  0x0,  0x1,  0x80, 0x0,  0xF,  0x0,  0x0,  0x0,  0x0};
u8 D_80801E8C_chsabreman[16] = {0x0, 0x13, 0x5, 0xCA, 0x0, 0xD, 0x0, 0xF3,
                                0x1, 0xC,  0x0, 0x18, 0x0, 0x0, 0x0, 0x0};
u8 D_80801E9C_chsabreman[40] = {0x3E, 0x85, 0x1E, 0xB8, 0x3E, 0x94, 0x7A, 0xE1, 0x3E, 0xA3,
                                0xD7, 0xA,  0x3E, 0xB3, 0x33, 0x33, 0x3F, 0x0,  0x0,  0x0,
                                0x3F, 0x7,  0xAE, 0x14, 0x3F, 0xF,  0x5C, 0x29, 0x3F, 0x17,
                                0xA,  0x3D, 0x3F, 0x1E, 0xB8, 0x52, 0xBF, 0x80, 0x0,  0x0};
u8 D_80801EC4_chsabreman[16] = {0x0, 0x13, 0x5, 0xC5, 0x0, 0x18, 0x0, 0xD,
                                0x0, 0xF3, 0x1, 0xC,  0x0, 0x0,  0x0, 0x0};
u8 D_80801ED4_chsabreman[40] = {0x0, 0x1D, 0x9, 0xDD, 0x0, 0x22, 0x0, 0x4C, 0x0, 0x59,
                                0x0, 0x66, 0x0, 0x73, 0x0, 0x15, 0x0, 0x33, 0x0, 0xB3,
                                0x0, 0x2A, 0x0, 0xC,  0x0, 0x33, 0x1, 0x0,  0x1, 0x80,
                                0x0, 0xE,  0x0, 0x5,  0x0, 0xF,  0x0, 0x0,  0x0, 0x0};
u8 D_80801EFC_chsabreman[12] = {0x0, 0x13, 0x4, 0xA2, 0x0, 0x16, 0x36, 0xB0, 0x0, 0x0, 0x0, 0x0};
u8 D_80801F08_chsabreman[12] = {0x0, 0x13, 0x4, 0x17, 0x0, 0x16, 0x36, 0xB0, 0x0, 0x0, 0x0, 0x0};
u8 D_80801F14_chsabreman[24] = {0x0,  0x13, 0x5, 0xC8, 0x0, 0xD,  0x0, 0xF3, 0x1, 0xC, 0x0, 0x16,
                                0x36, 0xB0, 0x0, 0x1,  0x0, 0x3C, 0x3, 0x84, 0x0, 0x0, 0x0, 0x0};
u8 D_80801F2C_chsabreman[24] = {0x0,  0x13, 0x5, 0xC9, 0x0, 0xD,  0x0, 0xF3, 0x1, 0xC, 0x0, 0x16,
                                0x36, 0xB0, 0x0, 0x1,  0x0, 0x3C, 0x3, 0x84, 0x0, 0x0, 0x0, 0x0};
u8 D_80801F44_chsabreman[24] = {0x0,  0x13, 0x4, 0x49, 0x0, 0xD,  0x0, 0xD9, 0x0, 0xF3, 0x0, 0x16,
                                0x2E, 0xE0, 0x0, 0x1,  0x0, 0x3C, 0x3, 0x84, 0x0, 0x0,  0x0, 0x0};
u8 D_80801F5C_chsabreman[16] = {0x3E, 0x99, 0x99, 0x9A, 0x3E, 0xB8, 0x51, 0xEC,
                                0x3E, 0xD7, 0xA,  0x3D, 0xBF, 0x80, 0x0,  0x0};
u8 D_80801F6C_chsabreman[12] = {0x0, 0x13, 0x4, 0x17, 0x0, 0x16, 0x36, 0xB0, 0x0, 0x0, 0x0, 0x0};
u8 D_80801F78_chsabreman[16] = {0x3, 0x6, 0x0, 0x1,  0x0,  0x3C, 0x3, 0x84,
                                0x0, 0x7, 0x0, 0x16, 0x36, 0xB0, 0x0, 0x0};
u8 D_80801F88_chsabreman[16] = {0x0, 0x13, 0x5, 0xC6, 0x0, 0xD, 0x0, 0xF3,
                                0x1, 0xC,  0x0, 0x11, 0x0, 0x0, 0x0, 0x0};
u8 D_80801F98_chsabreman[24] = {0x0, 0x13, 0x5, 0xC7, 0x0, 0xD, 0x0, 0xF3, 0x1, 0xC, 0x0, 0x11,
                                0x0, 0x0,  0x0, 0x0,  0x0, 0x0, 0x0, 0x0,  0x0, 0x0, 0x0, 0x0};
