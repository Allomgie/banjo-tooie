#include "common.h"

extern int D_80801A5C_chnicecavemen[];
extern int D_80801AA4_chnicecavemen[];
extern void *D_80801AEC_chnicecavemen;
extern s32 D_80801B34_chnicecavemen[];
extern u8 D_808018D8_chnicecavemen[];
extern void *func_80100094(Actor *, u32);
extern void _suexpression_entrypoint_12(s32, f32, f32);
extern void _subaddiepalette_entrypoint_4();
extern void func_800F7F98(void *, s32);
extern void *func_800F54E4(void);
extern s32 func_800DA298();
extern void _subaddiedialog_entrypoint_11(s32, s32, s32, s32, s32);
extern void _gcdialogcamera_entrypoint_3(u8 *, f32);
extern s32 _suexpression_entrypoint_7(Actor *, s32, s32);
extern void _suexpression_entrypoint_17(s32, s32);
typedef struct {
    u8 pad_0[0x14];
    u16 local_0;
    u8 pad_1[2];
    s16 local_1;
    u8 pad_2[2];
    f32 local_2;
    f32 local_3;
} NiceCavemanPalette1828;
extern f32 func_800F12D4(f32, f32, f32, f32, f32);
extern void _subaddiepalette_entrypoint_3();
extern void func_800DF6BC();
extern void func_800DF744();
extern void func_801015D0();
extern u8 D_80801810_chnicecavemen[];
extern u8 D_80801848_chnicecavemen[];
extern u8 D_80801880_chnicecavemen[];
extern u8 D_808018B8_chnicecavemen[];
extern s32 _subaddiedialog_entrypoint_9(Actor *, s32, s32, s32);
extern u8 D_808018E8_chnicecavemen[];
extern void func_800F8300(s32, s32, f32 *);
extern s32 func_800DC298(f32);
extern s32 _subaddiedialog_entrypoint_8(Actor *, f32 *, void *, s32, s32);
typedef union {
    u8 *local_0;
    s32 local_1;
} CaveEvent60;
extern int _chfirefx_entrypoint_5(Actor *, s32, void *);
extern u8 D_80801B7C_chnicecavemen[];
extern void func_800F4F34(s32, f32 *, f32, f32);
typedef struct {
    s32 v[7];
} CavemenSnd;
typedef struct {
    u8 pad0[0x70];
    u32 pad70_1 : 31;
    u32 unk70_0 : 1;
} CavemenBits;
extern u8 D_80801BC0_chnicecavemen[];
extern f32 D_80801CA0_chnicecavemen[];
extern f32 D_80801CB8_chnicecavemen[];
extern f32 D_80801CD0_chnicecavemen[];
extern u8 D_80801BEC_chnicecavemen[];
extern CavemenSnd D_80801B8C_chnicecavemen;
extern f32 D_80801C60_chnicecavemen[];
extern u8 D_80801D1C_chnicecavemen[];
extern u8 D_80801CEC_chnicecavemen[];
extern u8 D_80801CF4_chnicecavemen[];
extern u8 D_80801D08_chnicecavemen[];
extern f32 D_80801D28_chnicecavemen[];
extern f32 D_80801D38_chnicecavemen[];
extern f32 D_80801D48_chnicecavemen[];
extern f32 D_80801D5C_chnicecavemen[];
extern f32 D_80801D70_chnicecavemen[];
extern f32 D_80801C8C_chnicecavemen[];
extern f32 D_80801DA8_chnicecavemen[];
extern f32 D_80801C78_chnicecavemen[];
extern f32 D_80801D94_chnicecavemen[];
extern u8 D_80801C1C_chnicecavemen[];
extern f32 D_80801DB8_chnicecavemen[];
extern f32 D_80801BA8_chnicecavemen[];
extern s32 func_801022E4(Actor *);
extern f32 func_80101F24(Actor *);
extern s32 func_80101E14(Actor *, f32);
extern s32 _subaddieskeleton_entrypoint_2(Unk80132ED0 *, s32, f32 *);
extern void func_800EE7F8(f32 *, f32 *);
extern void func_800EF1B8(f32 *, f32, f32);
extern void func_800BABB8(s32, f32 *, f32 *, f32, u8 *);
extern void _subaddieaudioquick_entrypoint_2(Actor *, f32 *, f32 *);
extern s32 _subaddieaudioquick_entrypoint_4(Actor *, f32 *, f32 *, void *);
extern void func_800BBCB8(f32 *, f32 *, f32, s32, u8 *);
extern s32 func_80101E4C();
extern void func_8010D930();
extern s32 _subaddieaudioquick_entrypoint_3(Actor *, f32 *, f32 *, f32);
extern s32 func_800DC128(s32, s32);
extern void _subaddieaudioloop_entrypoint_4(Actor *, f32 *, s32, f32 *);
void func_80800624_chnicecavemen();
void func_8080077C_chnicecavemen();
int func_80800AB8_chnicecavemen();
int func_80800BF8_chnicecavemen();
int func_80800C6C_chnicecavemen();
void func_80801200_chnicecavemen();
s32 func_8080126C_chnicecavemen();
int func_808013D0_chnicecavemen();
int func_80801428_chnicecavemen();
int func_80801464_chnicecavemen();
int func_80801508_chnicecavemen();
int func_80801580_chnicecavemen();
void func_80800CC8_chnicecavemen();

int *chnicecavemen_entrypoint_0()
{
    return D_80801A5C_chnicecavemen;
}

int chnicecavemen_entrypoint_1()
{
    return D_80801AA4_chnicecavemen;
}

int chnicecavemen_entrypoint_2()
{
    return &D_80801AEC_chnicecavemen;
}

int chnicecavemen_entrypoint_3()
{
    return (int) D_80801B34_chnicecavemen;
}

void func_80800030_chnicecavemen(u8 *actor)
{
    s32 state;
    u32 variant;

    variant = (u32) (u16) *(u16 *) ((s8 *) actor + 0x76) >> 7;
    *(s32 *) ((s8 *) actor + 0x30) = 0;
    switch (variant) {
        case 0x32:
            *(s32 *) ((s8 *) actor + 0x28) = 0x324;
            *(s32 *) ((s8 *) actor + 0x2C) = 0x16C;
            break;
        case 0x33:
            *(s32 *) ((s8 *) actor + 0x28) = 0x325;
            *(s32 *) ((s8 *) actor + 0x2C) = 0x16D;
            break;
        case 0x34:
            *(s32 *) ((s8 *) actor + 0x28) = 0x326;
            *(s32 *) ((s8 *) actor + 0x2C) = 0x16E;
    }
    if (_glcutDll_entrypoint_20() != 0) {
        state = 0xD;
    } else if (func_800DA298(*(s32 *) ((s8 *) actor + 0x28)) != 0) {
        if (func_800DA298(*(s32 *) ((s8 *) actor + 0x2C)) != 0) {
            state = 0xC;
        } else {
            state = 0xA;
        }
    } else {
        if (func_800DA298(*(s32 *) ((s8 *) actor + 0x2C)) != 0) {
            state = 9;
        } else {
            state = 1;
        }
    }
    func_80102424(actor, state);
    func_80801200_chnicecavemen(actor);
}

s32 func_8080134C_chnicecavemen();

void func_80800128_chnicecavemen(Actor *actor)
{
    u8 *data;
    data = func_80100094(actor, 0);
    func_800F4F34(func_800F54E4(), actor->position, 60.0f, 50.0f);
    _suexpression_entrypoint_10(func_80100094(actor, 1), actor->unk0, 0);
    switch (actor->unk70_10) {
        case 1:
            if (func_800DA298(actor->actorData[4])) {
                func_800F7B9C(func_800F54E4(), 0x93);
                func_80800AB8_chnicecavemen(actor, 8);
            } else {
                func_8080134C_chnicecavemen(actor, D_80801B7C_chnicecavemen,
                                            (s32) D_80801810_chnicecavemen, 7, 2);
            }
            break;
        case 5:
        case 6:
            func_80801178_chnicecavemen(actor);
            if (*(f32 *) (data + 0x10) > 0.75f) {
                func_80800AB8_chnicecavemen(actor, 7);
            }
            break;
        case 7:
            func_80801178_chnicecavemen(actor);
            if (func_80101DDC(actor)) {
                if (*(s32 *) (data + 0x824)) {
                    if (*(s32 *) (data + 0x824)) {
                        func_800F82D4(func_800F54E4(), 0);
                        *(s32 *) (data + 0x824) = 0;
                    }
                    _subaddiedialog_entrypoint_11(actor->unk0, 0x17D7, 14, actor->position,
                                                  0xA2);
                    func_80800AB8_chnicecavemen(actor,
                                                func_800DA298(actor->actorData[4]) ? 4 : 2);
                }
            }
            break;
        case 9:
            if (func_800DA298(actor->actorData[4])) {
                func_80800AB8_chnicecavemen(actor, 8);
            } else {
                func_8080134C_chnicecavemen(actor, D_80801B7C_chnicecavemen,
                                            (s32) D_80801848_chnicecavemen, 7, 2);
            }
            break;
        case 10:
            func_8080134C_chnicecavemen(actor, D_80801B7C_chnicecavemen,
                                        (s32) D_80801880_chnicecavemen, 7, 3);
            break;
        case 11:
            if (func_80101DDC(actor)) {
                func_80800AB8_chnicecavemen(actor, 12);
            }
            break;
        case 12:
            func_8080134C_chnicecavemen(actor, D_80801B7C_chnicecavemen,
                                        (s32) D_808018B8_chnicecavemen, 4, 4);
    }
    func_80800CC8_chnicecavemen(actor);
    _subaddiepalette_entrypoint_1(actor, data + 0x14);
}

void func_808003B8_chnicecavemen(Actor *arg0)
{
    _suexpression_entrypoint_8(arg0, 1);
}

int func_808003D8_chnicecavemen(Actor *actor, s32 msg, s32 arg)
{
    s32 expr;
    s32 dialog_id;
    s32 item_dialog_id;
    switch (msg) {
        case 0x2E:
            func_8080077C_chnicecavemen(actor, ((s16 *) &arg)[0], ((s16 *) &arg)[1]);
            break;
        case 0x29:
            _subaddiepalette_entrypoint_4(actor, (u8 *) func_80100094(actor, 0) + 0x14);
            break;
        case 0xB:
            switch (arg) {
                case 9:
                case 12:
                case 16:
                    func_800F7F98(func_800F54E4(), 0);
                    if (!func_80800C6C_chnicecavemen(actor)) {
                        if (func_800DA298(actor->actorData[5]))
                            dialog_id = 0x17D9;
                        else
                            dialog_id = 0x17D4;
                        func_80801464_chnicecavemen(actor, 3, 1);
                        _subaddiedialog_entrypoint_11(actor->unk0, dialog_id, 0xE,
                                                      actor->position, 0xA2);
                    }
                    return 4;
                case 1:
                    if (func_800F64A4(func_800F54E4(), 0x400))
                        item_dialog_id = 0x1811;
                    else
                        item_dialog_id = 0x17FD;
                    func_80801464_chnicecavemen(actor, 3, 1);
                    _subaddiedialog_entrypoint_11(actor->unk0, item_dialog_id, 0xE, actor->position,
                                                  0xA2);
                    return 4;
                default:
                    return 3;
            }
        case 0x1F:
            func_80800624_chnicecavemen(actor, *(s32 *) &arg);
            break;
        case 0x52:
            _gcdialogcamera_entrypoint_3(D_808018D8_chnicecavemen, actor->scale);
            break;
        case 0x57:
            return func_808013D0_chnicecavemen(actor, arg & 0xFFFF,
                                               (u32) (arg & 0xFFFF0000) >> 16);
        case 0x95:
            expr = _suexpression_entrypoint_7(actor, 1, 0xA2);
            _suexpression_entrypoint_12(expr, 6e+01f, 15.0f);
            _suexpression_entrypoint_17(expr, 800);
            break;
        default:
            return 0;
    }
    return 1;
}

void func_80800624_chnicecavemen(actor, arg) Actor *actor;
s32 arg;
{
    s32 is_variant_b;
    s32 is_dance;
    NiceCavemanPalette1828 *palette;
    s32 anim_id;
    s32 blend;

    palette = (NiceCavemanPalette1828 *) func_80100094(actor, 0);
    anim_id = func_801022E4(actor);
    func_801015D0(actor);
    is_variant_b = actor->unk6C_9 == 0x42C ? 1 : 0;
    switch (anim_id) {
        case 0x2D5:
        case 0x2D6:
            is_dance = 1;
            break;
        default:
            is_dance = 0;
            break;
    }
    func_800DF744(3, is_variant_b, is_dance);
    func_800DF744(4, is_variant_b);
    func_800DF744(5, is_dance);
    func_800DF744(7, actor->unk74_7 - 0x31);
    func_800DF744(8, actor->unk74_7 - 0x31);
    if (palette->local_1 == 1) {
        blend = (s32) func_800F12D4(palette->local_2, 0.0f, palette->local_3, 0.0f, 255.0f);
    } else {
        blend = palette->local_0 == 0x7E7 ? 0 : 255;
    }
    func_800DF6BC(blend, 255);
    _subaddiepalette_entrypoint_3(actor, &palette->local_0, arg);
}

void func_8080077C_chnicecavemen(actor, dialog_id, choice) Actor *actor;
s32 dialog_id;
s32 choice;
{
    void *data;
    s32 local_1;
    s32 local_2;
    s32 local_3;
    s32 local_4;
    s32 next_state;

    switch (dialog_id) {
        case 0x17D5:
        case 0x1803:
            if (choice > 0) {
                data = func_80100094(actor, 0);
                func_800FC660(0xE);
                func_80800AB8_chnicecavemen(actor, func_800DA298(actor->actorData[4]) ? 6 : 5);
                _subaddieitem_entrypoint_0(data, actor->actorData[6], -1, 1);
                _subaddieitem_entrypoint_2(data);
            } else {
                _subaddiedialog_entrypoint_11(actor->unk0, 0x17D6, 15, actor->position, 0xA2);
            }
            break;
        case 0x17D7:
            if (!func_80800BF8_chnicecavemen(actor)) {
                func_80801428_chnicecavemen(actor);
            }
            func_80800AB8_chnicecavemen(actor, func_800DA298(actor->actorData[4]) ? 12 : 9);
            break;
        case 0x17D8:
            func_80801508_chnicecavemen(actor, 1, 0x30);
            func_800D1000(0x2D, 1, NULL, 1, NULL);
            break;
        case 0x17FD:
        case 0x1811:
            func_80801428_chnicecavemen(actor);
            func_80800AB8_chnicecavemen(actor, 12);
            break;
        default:
            local_1 =
                _subaddiedialog_entrypoint_9(actor, dialog_id, (s32) D_80801810_chnicecavemen, 7);
            local_2 =
                _subaddiedialog_entrypoint_9(actor, dialog_id, (s32) D_80801848_chnicecavemen, 7);
            local_3 =
                _subaddiedialog_entrypoint_9(actor, dialog_id, (s32) D_80801880_chnicecavemen, 7);
            local_4 =
                _subaddiedialog_entrypoint_9(actor, dialog_id, (s32) D_808018B8_chnicecavemen, 4);
            if (_subaddiedialog_entrypoint_10(local_1) || _subaddiedialog_entrypoint_10(local_3)) {
                if (func_80801580_chnicecavemen(actor)) {
                    _subaddiedialog_entrypoint_11(actor->unk0,
                                                  func_8080126C_chnicecavemen(actor), 0x4E,
                                                  actor->position, 0xA2);
                } else {
                    func_800C01A8(100, 0);
                    func_800C0850();
                    func_80801428_chnicecavemen(actor);
                    func_80800AB8_chnicecavemen(actor,
                                                func_800DA298(actor->actorData[4]) ? 10 : 1);
                }
            } else if (_subaddiedialog_entrypoint_10(local_2)) {
                func_80801428_chnicecavemen(actor);
                func_80800AB8_chnicecavemen(actor, 9);
            } else if (_subaddiedialog_entrypoint_10(local_4)) {
                if (!func_80800BF8_chnicecavemen(actor)) {
                    func_80801428_chnicecavemen(actor);
                }
                func_80800AB8_chnicecavemen(actor, 12);
            } else {
                if (func_800DA298(actor->actorData[4])) {
                    if (func_800DA298(actor->actorData[5])) {
                        next_state = 12;
                    } else {
                        next_state = 10;
                    }
                } else if (func_800DA298(actor->actorData[5])) {
                    next_state = 9;
                } else {
                    next_state = 1;
                }
                func_80801428_chnicecavemen(actor);
                func_80800AB8_chnicecavemen(actor, next_state);
            }
    }
}

int func_80800AB8_chnicecavemen(actor, state)
Actor *actor;
s32 state;
{
    s32 data;
    s32 food_flag;
    u32 variant;
    data = func_80100094(actor, 0);
    switch (state) {
        case 7:
            break;
        case 11:
            if (func_801021BC(actor, 0xB) != 0) {
                break;
            }
            state = 0xC;
        // fallthrough
        case 12:
            func_80800C6C_chnicecavemen(actor);
            break;
        case 8:
            food_flag = 0;
            variant = (u32) *(u16 *) ((char *) actor + 0x76) >> 7;
            switch (variant) {
                case 0x32:
                    food_flag = 0x10;
                    break;
                case 0x33:
                    food_flag = 0xC;
                    break;
                case 0x34:
                    food_flag = 9;
            }
            func_80801508_chnicecavemen(actor, food_flag, 0x28, state);
            func_800F7F98(func_800F54E4(), 1);
            if (_subaddiepalette_entrypoint_2(actor, data + 0x14, 0x7E7, 0x40400000) != 0) {
                func_800BBCB8((f32 *) ((char *) actor + 0x4), 0, 1.0f, 1,
                              &D_808018E8_chnicecavemen);
            }
            break;
    }
    func_80102424(actor, state);
}

// True when both 3-bit counters (0x16C, 0x324) are full and the jiggy is not yet given.
int func_80800BF8_chnicecavemen(actor)
s32 actor;
{
    int count_a;
    s32 count_b;

    if (!func_800D0A9C(0x2D, 1)) {
        count_a = func_800DA980(0x16C, 3) == 3;
        count_b = func_800DA980(0x324, 3) == 3;
        return count_a && count_b;
    }
    return 0;
}

int func_80800C6C_chnicecavemen(actor)
s32 actor[4];
{
    if (func_80800BF8_chnicecavemen()) {
        func_80102424(actor, 4);
        _subaddiedialog_entrypoint_11(actor[0], 0x17D8, 0xE, &actor[1], 0xA2);
        return 1;
    }
    return 0;
}

void func_80800CC8_chnicecavemen(actor) Actor *actor;
{
    s32 anim_id;
    f32 anim_progress;
    s32 loop_snd;
    f32 local_3[3];
    f32 local_4[3];
    f32 local_5[3];
    CavemenSnd local_6;
    s32 local_7;
    s32 local_8;
    f32 local_9[3];
    f32 local_10[3];

    anim_id = func_801022E4(actor);
    anim_progress = func_80101F24(actor);
    loop_snd = 0;
    switch (anim_id) {
        case 0x2CD:
            if (func_80101E14(actor, 0.7f)) {
                if (_subaddieskeleton_entrypoint_2(actor->unk0, 4, local_3)) {
                    func_800EE7F8(local_4, local_3);
                    func_800EF1B8(local_4, actor->rotation[1], -50.0f);
                    local_4[1] += 30.0f;
                    func_800BABB8(0, local_3, local_4, 1.0f, D_80801BC0_chnicecavemen);
                }
                _subaddieaudioquick_entrypoint_2(actor, actor->position,
                                                 D_80801CA0_chnicecavemen);
            }
            loop_snd = 1;
            break;
        case 0x2CF:
            if (_subaddieaudioquick_entrypoint_4(actor, actor->position,
                                                 D_80801CB8_chnicecavemen,
                                                 D_80801CD0_chnicecavemen) &&
                func_800DC298(0.4f) && _subaddieskeleton_entrypoint_2(actor->unk0, 5, local_5)) {
                func_800BBCB8(local_5, actor->position, 1.0f, 3, D_80801BEC_chnicecavemen);
            }
            loop_snd = 0.4f < anim_progress;
            break;
        case 0x2CE:
            local_6 = D_80801B8C_chnicecavemen;
            _subaddieaudioquick_entrypoint_4(actor, actor->position, D_80801C60_chnicecavemen,
                                             &local_6);
            loop_snd = anim_progress < 0.6f;
            break;
        case 0x2D0:
        case 0x2D1:
        case 0x2D2:
            if (func_80101E4C(actor, D_80801D1C_chnicecavemen)) {
                func_8010D930(4, ((CavemenBits *) actor)->unk70_0, actor->position,
                              D_80801CEC_chnicecavemen);
            }
            if (func_80101E14(actor, 0.83f)) {
                func_8010D930(4, ((CavemenBits *) actor)->unk70_0, actor->position,
                              D_80801CF4_chnicecavemen);
            }
            if (func_80101E14(actor, 0.08f)) {
                func_8010D930(4, ((CavemenBits *) actor)->unk70_0, actor->position,
                              D_80801D08_chnicecavemen);
            }
            break;
        case 0x2D6:
            _subaddieaudioquick_entrypoint_3(actor, actor->position, D_80801D28_chnicecavemen,
                                             0.05f);
            _subaddieaudioquick_entrypoint_3(actor, actor->position, D_80801D38_chnicecavemen,
                                             0.16f);
            break;
        case 0x2D4:
            _subaddieaudioquick_entrypoint_4(actor, actor->position, D_80801D48_chnicecavemen,
                                             D_80801D5C_chnicecavemen);
            break;
        case 0x2D3:
            _subaddieaudioquick_entrypoint_4(actor, actor->position, D_80801C60_chnicecavemen,
                                             D_80801D70_chnicecavemen);
            break;
        case 0x2E2:
            local_7 = 0;
            _subaddieaudioquick_entrypoint_4(actor, actor->position, D_80801C8C_chnicecavemen,
                                             D_80801DA8_chnicecavemen);
            if (_subaddieaudioquick_entrypoint_3(actor, actor->position,
                                                 D_80801C78_chnicecavemen, 0.3f)) {
                local_7 = 1;
                local_8 = 4;
            }
            if (_subaddieaudioquick_entrypoint_3(actor, actor->position,
                                                 D_80801D94_chnicecavemen, 0.84f)) {
                local_7 = 1;
                local_8 = 6;
            }
            if (local_7 && _subaddieskeleton_entrypoint_2(actor->unk0, local_8, local_9)) {
                func_800EE7F8(local_10, local_9);
                func_800EF1B8(local_10, actor->rotation[1] - 30.0f, -20.0f);
                local_10[1] -= 30.0f;
                func_800BBCB8(local_9, local_10, 1.0f, func_800DC128(4, 8),
                              D_80801C1C_chnicecavemen);
            }
            break;
        case 0x2E1:
            _subaddieaudioquick_entrypoint_4(actor, actor->position, D_80801C8C_chnicecavemen,
                                             D_80801DB8_chnicecavemen);
            _subaddieaudioquick_entrypoint_3(actor, actor->position, D_80801C78_chnicecavemen,
                                             0.3f);
    }
    _subaddieaudioloop_entrypoint_4(actor, actor->position, loop_snd, D_80801BA8_chnicecavemen);
}

int func_80801178_chnicecavemen(Actor *actor)
{
    u8 *data;
    f32 hand_pos[3];
    data = func_80100094(actor, 0);
    _subaddieskeleton_entrypoint_3(actor->unk0, 4, hand_pos);
    if (_subaddieitem_entrypoint_3(actor, hand_pos, data)) {
        *(s32 *) (data + 0x824) = 1;
        func_800F8300(func_800F54E4(), 2, actor->position);
        func_800DA544(actor->actorData[5]);
        return 1;
    }
    return 0;
}

void func_80801200_chnicecavemen(actor) u8 *actor;
{
    s32 data;
    s32 palette_id;

    data = func_80100094(actor, 0);

if ((func_800DA298(*(s32 *) ((char *) actor + 0x28)) != 0) || (_glcutDll_entrypoint_20() != 0)) {
    palette_id = 0x7E7;
} else {

palette_id = 0x7E6;

}
_subaddiepalette_entrypoint_0(actor, data + 0x14, palette_id & 0xFFFF);
}

// Picks which food item (0x3CA or 0x3CB) the caveman asks for; returns the dialog id.
s32 func_8080126C_chnicecavemen(actor)
Actor *actor;
{
    s32 player;

    player = func_800F54E4();
    if (actor->actorData[6] == 0) {
        if (func_800DC298(0.5f)) {
            if (func_800F640C(player, 0x3CA) > 0)
                actor->actorData[6] = 0x3CA;
            else
                actor->actorData[6] = 0x3CB;
        } else {

if (func_800F640C(player, 0x3CB) > 0)
    actor->actorData[6] = 0x3CB;
else
    actor->actorData[6] = 0x3CA;
}
}
else if (!func_800F640C(player, actor->actorData[6]))
{
    actor->actorData[6] = actor->actorData[6] == 0x3CA ? 0x3CB : 0x3CA;
}
return actor->actorData[6] == 0x3CA ? 0x17D5 : 0x1803;
}

s32 func_8080134C_chnicecavemen(Actor *actor, u8 *dialog, s32 lines, s32 line_count, s32 camera_id)
{
    s32 result;

    dialog[0xE] = camera_id;
    result = _subaddiedialog_entrypoint_8(actor, actor->position, dialog, lines, line_count);
    if (!result) {
        return 0;
    }
    if (_subaddiedialog_entrypoint_9(actor, result, lines, line_count) != 3) {
        func_80801464_chnicecavemen(actor, 2, 0);
    }
    return 1;
}

int func_808013D0_chnicecavemen(actor, dialog_a, dialog_b)
s32 actor[3];
s32 dialog_a;
s32 dialog_b;
{
    // Matching: "| 0" needed for the match.
    if (_gcdialogcamera_entrypoint_0(dialog_a | 0, dialog_b | 0)) {
        if (actor[6] != 2) {
            func_80801464_chnicecavemen(actor, 2, 1);
        }
        return 2;
    }
    return 1;
}

int func_80801428_chnicecavemen(actor)
Actor *actor;
{
    if ((*(s32 *) ((char *) (actor) + 0x18)) != 0) {
        _capod_entrypoint_3(0, actor);
        (*(s32 *) ((char *) (actor) + 0x18)) = 0;
    }
}

int func_80801464_chnicecavemen(actor, arg_a, arg_b)
Actor *actor;
s32 arg_a;
s32 arg_b;
{
    s32 cam_state = *(s32 *) ((char *) actor + 0x18);
    switch (cam_state) {
        case 0:
            _capod_entrypoint_2(*(s32 *) ((char *) actor + 0), 0x13, 0);
        // fallthrough
        case 1:
            _capod_entrypoint_8(1);
            *(s32 *) ((char *) actor + 0x18) = 2;
            _gcdialogcamera_entrypoint_3(&D_808018D8_chnicecavemen,
                                         *(f32 *) ((char *) actor + 0x38));
            _gcdialogcamera_entrypoint_4((u8 *) actor + 4);
            _gcdialogcamera_entrypoint_5((u8 *) actor + 0x44);
            _gcdialogcamera_entrypoint_8();
        // fallthrough
        case 2:
            _capod_entrypoint_7(arg_a, arg_b);
    }
}

int func_80801508_chnicecavemen(actor, arg_a, arg_b)
s32 actor;
s32 arg_a;
s32 arg_b;
{
    switch ((*(s32 *) ((char *) (actor) + 0x18))) {
        case 0:
            _capod_entrypoint_2((*(s32 *) ((char *) (actor) + 0x0)), 0x13, arg_b, actor);

        case 2:
            (*(s32 *) ((char *) (actor) + 0x18)) = 1;

        case 1:
            _capod_entrypoint_6((*(s32 *) ((char *) (actor) + 0x0)), arg_a, arg_b, actor);
    }
}

int func_80801580_chnicecavemen(actor)
Actor *actor;
{
    s32 player;

    player = func_800F54E4();
    if (!func_800F64A4(player, 0x201)) {
        return 0;
    }
    if (!func_8010CB84(actor->position, 300)) {
        return 0;
    }
    return func_800F640C(player, 0x3CA) > 0 || func_800F640C(player, 0x3CB) > 0;
}

void func_80801604_chnicecavemen(u8 *actor)
{
    u32 variant;

    variant = (u32) ((u16) (*(u16 *) ((s8 *) (actor) + (0x76)))) >> 7;
    switch (variant) {
        case 0x32:;
        case 0x33:
            _chfirefx_entrypoint_2(actor, 0x3F99999A, 0x42480000, 0xF, 0xD);
            (*(s32 *) ((s8 *) (actor) + (0x28))) =
                (s32) (((u32) ((u16) (*(u16 *) ((s8 *) (actor) + (0x76)))) >> 7) + 0x2F2);
            break;
        case 0x34:
            _chfirefx_entrypoint_2(actor, 0x3FC00000, 0x42C80000, 0x14, 5);
            (*(s32 *) ((s8 *) (actor) + (0x28))) = 0x326;
            func_80102FDC(actor, 0x3F800000);
    }
    if ((func_800DA298((*(s32 *) ((s8 *) (actor) + (0x28)))) != 0) ||
        (_glcutDll_entrypoint_20() != 0)) {
        func_8010A570(actor);
        func_80101FDC(actor, 2);
    }
}

int func_808016E8_chnicecavemen(Actor *actor, s32 event, CaveEvent60 arg)
{
    if (event == 0x40) {
        if (*(u16 *) (arg.local_0 + 0x18) & 1) {
            func_8010114C(arg.local_0, 0x92, 0);
        }
        // Matching: empty block needed for the match.
        if (arg.local_0) {
        }
        func_8010A570(actor);
        func_80101FDC(actor, 2);
        func_800DA544(*(s32 *) ((u8 *) actor + 0x28));
        func_800FC6B0(0xE);
        return 1;
    }
    return _chfirefx_entrypoint_5(actor, event, arg.local_0);
}

// TU-NOTE: the .data of this overlay is defined in this file. The tables hold pointers to
// functions of this file; IDO schedules some of them differently unless the tables are in the
// same unit. D_80801A5C and D_80801AA4 are declared int[] (uses written as NAME[0]).
extern void func_80105834();
extern void func_801018A4();
extern void func_80107C2C();
extern void _chfirefx_entrypoint_3();
extern void _chfirefx_entrypoint_4();
extern void func_80108ED0();
extern u8 boot_thread_stack[];
u8 D_80801810_chnicecavemen[56] = {
    0x0,  0x0,  0x0,  0x1,  0x17, 0xCF, 0x1,  0x0,  0x0,  0x0,  0x0,  0x1, 0x17, 0xD0,
    0x2,  0x0,  0x0,  0x0,  0x2,  0x0,  0x18, 0x10, 0x1,  0x0,  0x0,  0x0, 0x2,  0x0,
    0x17, 0xD0, 0x2,  0x0,  0x0,  0x0,  0x4,  0x0,  0x18, 0xF,  0x1,  0x0, 0x0,  0x0,
    0x4,  0x0,  0x17, 0xD0, 0x2,  0x0,  0xFF, 0xFE, 0xDF, 0xFF, 0x12, 0xB, 0x3,  0x0};
u8 D_80801848_chnicecavemen[56] = {
    0x0,  0x0,  0x0,  0x1,  0x17, 0xD1, 0x1,  0x0,  0x0,  0x0,  0x0,  0x1, 0x17, 0xD2,
    0x2,  0x0,  0x0,  0x0,  0x2,  0x0,  0x17, 0xD1, 0x1,  0x0,  0x0,  0x0, 0x2,  0x0,
    0x17, 0xD2, 0x2,  0x0,  0x0,  0x0,  0x4,  0x0,  0x17, 0xD1, 0x1,  0x0, 0x0,  0x0,
    0x4,  0x0,  0x17, 0xD2, 0x2,  0x0,  0xFF, 0xFE, 0xDF, 0xFF, 0x12, 0xB, 0x3,  0x0};
u8 D_80801880_chnicecavemen[56] = {
    0x0,  0x0,  0x0,  0x1,  0x17, 0xD3, 0x1,  0x0,  0x0,  0x0,  0x0,  0x1, 0x17, 0xD4,
    0x2,  0x0,  0x0,  0x0,  0x2,  0x0,  0x17, 0xD3, 0x1,  0x0,  0x0,  0x0, 0x2,  0x0,
    0x17, 0xD4, 0x2,  0x0,  0x0,  0x0,  0x4,  0x0,  0x17, 0xD3, 0x1,  0x0, 0x0,  0x0,
    0x4,  0x0,  0x17, 0xD4, 0x2,  0x0,  0xFF, 0xFE, 0xDF, 0xFF, 0x12, 0xB, 0x3,  0x0};
u8 D_808018B8_chnicecavemen[32] = {0x0, 0x0,  0x0,  0x1,  0x17, 0xD9, 0x2,  0x0, 0x0, 0x0,  0x2,
                                   0x0, 0x17, 0xD9, 0x2,  0x0,  0x0,  0x0,  0x4, 0x0, 0x17, 0xD9,
                                   0x2, 0x0,  0xFF, 0xFE, 0xDF, 0xFF, 0x12, 0xB, 0x3, 0x0};
u8 D_808018D8_chnicecavemen[16] = {0x43, 0x2,  0x0, 0x0, 0x42, 0xF0, 0x0, 0x0,
                                   0x42, 0xF0, 0x0, 0x0, 0x42, 0x70, 0x0, 0x0};
u8 D_808018E8_chnicecavemen[36] = {0x0, 0x1D, 0x7, 0xE8, 0x0, 0x2B, 0x5, 0x66, 0x5, 0x66, 0x0, 0x22,
                                   0x2, 0x0,  0x2, 0x0,  0x7, 0x80, 0x7, 0x80, 0x0, 0x15, 0x0, 0x0,
                                   0x0, 0xC0, 0x0, 0x1E, 0x0, 0x4,  0x0, 0x4,  0x0, 0x0,  0x0, 0x0};
u32 D_8080190C_chnicecavemen[28] = {
    0x0,        0x0,        0x40D00000, 0x2CD0001,  0x40D00000, 0x2CD0001,  0x40C0A3D7,
    0x2E20001,  0x406EB852, 0x2D60001,  0x40D00000, 0x2CD0001,  0x40C0A3D7, 0x2E20001,
    0x406CCCCD, 0x2D00002,  0x40D00000, 0x2CD0001,  0x40D00000, 0x2CD0001,  0x40C0A3D7,
    0x2E20001,  0x3EDC28F6, 0x2D50002,  0x406EB852, 0x2D60001,  0x406EB852, 0x2D60001};
u32 D_8080197C_chnicecavemen[28] = {
    0x0,        0x0,        0x41073333, 0x2CF0001,  0x41073333, 0x2CF0001,  0x40C4CCCD,
    0x2E10001,  0x407CCCCD, 0x2D40001,  0x41073333, 0x2CF0001,  0x40C4CCCD, 0x2E10001,
    0x406CCCCD, 0x2D20002,  0x41073333, 0x2CF0001,  0x41073333, 0x2CF0001,  0x40C4CCCD,
    0x2E10001,  0x0,        0x1,        0x407CCCCD, 0x2D40001,  0x407CCCCD, 0x2D40001};
u32 D_808019EC_chnicecavemen[28] = {
    0x0,        0x0,        0x40EA8F5C, 0x2CE0001,  0x40EA8F5C, 0x2CE0001,  0x40C0A3D7,
    0x2E20001,  0x40266666, 0x2D30001,  0x40EA8F5C, 0x2CE0001,  0x40C0A3D7, 0x2E20001,
    0x406CCCCD, 0x2D10002,  0x40EA8F5C, 0x2CE0001,  0x40EA8F5C, 0x2CE0001,  0x40C0A3D7,
    0x2E20001,  0x0,        0x1,        0x40266666, 0x2D30001,  0x40266666, 0x2D30001};
int D_80801A5C_chnicecavemen[18] = {0x30F03A6,
                                    0x7E50001,
                                    (u32) &D_8080190C_chnicecavemen,
                                    (u32) func_80800128_chnicecavemen,
                                    (u32) func_80105834,
                                    (u32) func_801018A4,
                                    0x0,
                                    0x3F800000,
                                    0x0,
                                    0x40800164,
                                    (u32) func_808003B8_chnicecavemen,
                                    0x0,
                                    0x8280000,
                                    (u32) func_80800030_chnicecavemen,
                                    (u32) func_80107C2C,
                                    -0x7FFF8BEE,
                                    (u32) func_808003D8_chnicecavemen,
                                    0x0};
int D_80801AA4_chnicecavemen[18] = {0x30F042B,
                                    0x7E50001,
                                    (u32) &D_808019EC_chnicecavemen,
                                    (u32) func_80800128_chnicecavemen,
                                    (u32) func_80105834,
                                    (u32) func_801018A4,
                                    0x0,
                                    0x3F800000,
                                    0x0,
                                    0x40800164,
                                    (u32) func_808003B8_chnicecavemen,
                                    0x0,
                                    0x8280000,
                                    (u32) func_80800030_chnicecavemen,
                                    (u32) func_80107C2C,
                                    -0x7FFF8BEE,
                                    (u32) func_808003D8_chnicecavemen,
                                    0x0};
void *D_80801AEC_chnicecavemen = (void *) 0x030F042C;
static u32 D_80801AEC_chnicecavemen_rest[17] = {0x7E50001,
                                                (u32) &D_8080197C_chnicecavemen,
                                                (u32) func_80800128_chnicecavemen,
                                                (u32) func_80105834,
                                                (u32) func_801018A4,
                                                0x0,
                                                0x3F800000,
                                                0x0,
                                                0x40800164,
                                                (u32) func_808003B8_chnicecavemen,
                                                0x0,
                                                0x8280000,
                                                (u32) func_80800030_chnicecavemen,
                                                (u32) func_80107C2C,
                                                0x80007412,
                                                (u32) func_808003D8_chnicecavemen,
                                                0x0};
s32 D_80801B34_chnicecavemen[18] = {0x31003A8,
                                    0x6FB0001,
                                    0x0,
                                    (u32) _chfirefx_entrypoint_3,
                                    (u32) func_80105834,
                                    (u32) _chfirefx_entrypoint_4,
                                    0xFA00000,
                                    0x0,
                                    0x0,
                                    0x0,
                                    0x0,
                                    (u32) func_80108ED0,
                                    0x0,
                                    (u32) func_80801604_chnicecavemen,
                                    (u32) func_80107C2C,
                                    (u32) ((u8 *) boot_thread_stack + 0x1F20),
                                    (u32) func_808016E8_chnicecavemen,
                                    0x0};
u8 D_80801B7C_chnicecavemen[16] = {0x1, 0x6F, 0x0, 0x0, 0x1, 0x2C, 0x0, 0xA2,
                                   0x0, 0x0,  0x0, 0xC, 0x6, 0x3C, 0x0, 0x0};
CavemenSnd D_80801B8C_chnicecavemen = {0x3F23D70A, 0x3F3851EC, 0x3F47AE14, 0x3F59999A,
                                       0x3F6B851F, 0x3F7D70A4, -0x40800000};
f32 D_80801BA8_chnicecavemen[6] = {1.746525e-39f, 1.286127e-39f, 3.746899e-38f,
                                   2.048407e-39f, 9.2256e-41f,   1.0231503e-34f};
u8 D_80801BC0_chnicecavemen[44] = {0x4,  0x10, 0x0,  0x1D, 0x9,  0xDD, 0x0,  0x22, 0x0,  0x33, 0x0,
                                   0x40, 0x0,  0x4C, 0x0,  0x59, 0x0,  0x15, 0x0,  0x33, 0x0,  0xB3,
                                   0x0,  0x2D, 0x0,  0x1E, 0x0,  0x28, 0x0,  0x2A, 0x0,  0xC,  0x0,
                                   0x33, 0x1,  0x0,  0x1,  0x80, 0x0,  0xF,  0x0,  0x0,  0x0,  0x0};
u8 D_80801BEC_chnicecavemen[48] = {
    0x0, 0x1D, 0x9, 0xDD, 0x0, 0x1F, 0xDE, 0xA7, 0x71, 0x0,  0x0, 0x22, 0x0, 0x33, 0x0, 0x40,
    0x0, 0x4C, 0x0, 0x59, 0x0, 0x15, 0x0,  0x33, 0x0,  0xB3, 0x0, 0x2D, 0x0, 0x14, 0x0, 0x1E,
    0x0, 0x2B, 0x0, 0xCC, 0x1, 0x0,  0x0,  0xE,  0x0,  0x8,  0x0, 0xA,  0x0, 0x0,  0x0, 0x0};
u8 D_80801C1C_chnicecavemen[68] = {
    0x0, 0x1D, 0x6,  0xA4, 0x0,  0x16, 0x11, 0x82, 0x0, 0x1B, 0xFF, 0x38, 0xFE, 0xD4,
    0x0, 0x27, 0xFD, 0xA8, 0xFD, 0xA8, 0x2,  0x58, 0x2, 0x58, 0x0,  0x2D, 0x0,  0x78,
    0x0, 0x8C, 0x0,  0x22, 0x0,  0x7,  0x0,  0xA,  0x0, 0x3,  0x0,  0x5,  0x0,  0x2B,
    0x1, 0x66, 0x1,  0xCC, 0x0,  0x15, 0x0,  0x0,  0x0, 0xB3, 0x0,  0x4,  0x0,  0x66,
    0x0, 0x7,  0x0,  0x2,  0x0,  0xE,  0x0,  0x5,  0x0, 0xA,  0x0,  0x0};
f32 D_80801C60_chnicecavemen[6] = {1.746312e-39f,  2.054012e-39f,  1.194202e-39f,
                                   2.5713942e-38f, 3.1596455e-38f, 0.0f};
f32 D_80801C78_chnicecavemen[5] = {1.746613e-39f, 1.194076e-39f, 1.6438555e-38f, 3.1596455e-38f,
                                   0.0f};
f32 D_80801C8C_chnicecavemen[5] = {1.746528e-39f, 1.1944e-39f, 5.620333e-38f, 3.1596455e-38f, 0.0f};
f32 D_80801CA0_chnicecavemen[6] = {1.746818e-39f, 1.194166e-39f,  2.2316056e-38f,
                                   13312.001f,    3.1596455e-38f, 0.0f};
f32 D_80801CB8_chnicecavemen[6] = {1.746412e-39f,  1.19413e-39f, 1.9928304e-38f,
                                   3.1596455e-38f, 2.0414e-39f,  0.0f};
f32 D_80801CD0_chnicecavemen[7] = {0.01f, 0.07f, 0.12f, 0.19f, 0.25f, 0.31f, -1.0f};
u8 D_80801CEC_chnicecavemen[8] = {0x0, 0x13, 0x5, 0xBB, 0x0, 0x2, 0x0, 0x0};
u8 D_80801CF4_chnicecavemen[20] = {0x0,  0x13, 0x4, 0x34, 0x0, 0xA,  0x0, 0x99, 0x0, 0x16,
                                   0x6D, 0x60, 0x0, 0x1,  0x1, 0x2C, 0x7, 0x8,  0x0, 0x0};
u8 D_80801D08_chnicecavemen[20] = {0x0, 0x13, 0x4, 0x9C, 0x0, 0xD, 0x0, 0xC0, 0x0, 0xD9,
                                   0x0, 0x1,  0x1, 0x2C, 0x7, 0x8, 0x0, 0x0,  0x0, 0x0};
u8 D_80801D1C_chnicecavemen[12] = {0x3E, 0x4C, 0xCC, 0xCD, 0x3F, 0x0,
                                   0x0,  0x0,  0xBF, 0x80, 0x0,  0x0};
f32 D_80801D28_chnicecavemen[4] = {1.746919e-39f, 2.045604e-39f, 9.2256e-41f, 1.0231503e-34f};
f32 D_80801D38_chnicecavemen[4] = {1.74692e-39f, 2.045604e-39f, 9.2256e-41f, 1.0231503e-34f};
f32 D_80801D48_chnicecavemen[5] = {1.746808e-39f, 1.194094e-39f, 1.7632417e-38f, 3.1596455e-38f,
                                   0.0f};
f32 D_80801D5C_chnicecavemen[5] = {0.09f, 0.2f, 0.31f, 0.43f, -1.0f};
f32 D_80801D70_chnicecavemen[9] = {0.09f, 0.23f, 0.35f, 0.48f, 0.6f, 0.73f, 0.85f, 0.97f, -1.0f};
f32 D_80801D94_chnicecavemen[5] = {1.746412e-39f, 1.194076e-39f, 1.6438555e-38f, 3.1596455e-38f,
                                   0.0f};
f32 D_80801DA8_chnicecavemen[4] = {0.06f, 0.15f, 0.24f, -1.0f};
f32 D_80801DB8_chnicecavemen[6] = {0.06f, 0.15f, 0.24f, -1.0f, 0.0f, 0.0f};
