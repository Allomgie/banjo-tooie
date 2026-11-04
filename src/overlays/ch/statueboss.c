// Targitzan, the Mayahem Temple boss: a spinning five-section totem. 26 states; eggs hit the
// weak spots, sections explode, darts and minions come between phases; at the end a ring of
// 10 darts, the final explosion, the jiggy and the defeated flag.
#include "common.h"

extern void *D_80802748_chstatueboss;
extern void func_800F608C();
extern void func_800FFAB0();
extern void func_80102424();
extern void func_80108B04();
extern void *func_80100094();
extern void func_8010D5DC(void);
extern void func_800F4A58(s32, void *, f32);
extern void _capod_entrypoint_13();
extern void _chintrotext_entrypoint_2();
extern void _subaddiedialog_entrypoint_11();
extern void _subaddiemarker_entrypoint_1();
extern void func_800F497C();
extern void func_800F49A8();
extern void func_800F49D4();
extern void func_800F8294();
extern void func_800FDC28();
extern void func_80109F08();
typedef struct {
    s32 state;
    f32 timer;
    f32 offset;
} StatueResetJoint;
typedef struct {
    u8 states[0x18];
    f32 timers[22];
    f32 parts[5];
    s16 phase;
    u8 pad_0[0x1A];
    StatueResetJoint joints[6];
} StatueResetData;
extern s16 D_808025C0_chstatueboss[][6];
typedef struct {
    u8 states[0x18];
    f32 timers[0x1B];
    s16 phase;
} StatueState1436;
extern s16 D_808027D4_chstatueboss[];
typedef struct {
    u8 pad_0[0x70];
    f32 angles[5];
    s16 start;
} StatueBossAngles;
extern f32 func_800D8FF8(void);
extern f32 func_800136E4(f32);
extern f32 D_80802630_chstatueboss[];
typedef struct {
    u8 pad_0[0x70];
    f32 local_0[5];
    s16 local_1;
} StatueBossRotations;
extern s32 func_800F20BC(f32, f32, f32);
extern f32 func_800F1F38(f32, f32, f32);
extern f32 mlAbsF(f32);
extern u8 D_8080265C_chstatueboss[];
extern void func_800E0AFC(s32, u8, f32, f32, f32, f32);
extern void func_800E0B8C(s32, u8, f32, f32, f32, f32);
extern void func_800E0C20(s32, u8, f32, f32, f32, f32);
extern int func_800D9078(f32 *);
extern u8 D_80802644_chstatueboss[];
extern u8 D_808027E0_chstatueboss[];
extern s16 D_80802624_chstatueboss[];
extern int D_808027E8_chstatueboss[];
extern Actor *func_80106790(s32);
extern void *func_800B2824(s32);
extern s32 func_800B1F8C(void *, f32 *, f32 *, f32, s32, s32, s32, f32, s32, s32);
extern s32 D_80802790_chstatueboss[];
extern s32 _subaddieaudioquick_entrypoint_3(u8 *, u8 *, void *, f32);
extern void func_800E15CC(s32, f32, f32);
extern void func_80018820(s32, f32, f32);
extern s32 D_808027F8_chstatueboss[];
extern u8 D_80802850_chstatueboss[];
extern f32 D_8080264C_chstatueboss[];
extern u8 D_80802668_chstatueboss[];
extern f32 func_8010CD28(Actor *);
extern void func_800EEB9C(f32 *, f32, f32);
extern Actor *func_80108528(s32, f32 *, s32, Actor **);
typedef struct {
    f32 local_0[3];
    f32 pad_0;
    f32 local_1;
    s32 pad_1;
} StatueBossSpawn;
typedef struct {
    u8 pad_0[0x16C];
    StatueBossSpawn local_0[4];
    u8 local_1;
} StatueBossSpawnList;
extern Actor *func_80108474(s32, f32 *, s32);
extern void _chappearfx_entrypoint_2(Actor *, s32, s32, f32);
extern f32 func_800F1DF4(f32 *, f32 *);
extern void func_800EF1B8(f32 *, f32, f32);
extern void _sudeflect_entrypoint_1(f32 *, f32, f32, f32, s32);
extern void _sudeflect_entrypoint_0(f32 *, f32, f32, s32);
extern s32 func_80101E14(Actor *, f32);
extern s32 func_80102320(Actor *, f32, f32);
extern void _chbaddiesetup_entrypoint_5(void (*)(void), s32, s32, s32, s32, s32);
extern void _chexploder_entrypoint_5(Actor *, s32, f32 *, f32, f32, s32);
extern s16 D_808027C0_chstatueboss[];
extern u8 _chstatueboss_entrypoint_1[];
extern u8 D_808027C8_chstatueboss[];
extern void func_800CE8D8(s32, f32, s32);
typedef struct {
    s32 local_0;
    f32 local_1;
    f32 local_2;
} StatueJoint;
typedef struct {
    u8 pad_0[0x84];
    s16 phase;
    u8 pad_1[0xA];
    f32 position[3];
    f32 angle;
    StatueJoint joints[6];
} StatueJointData;
extern s16 D_808025FC_chstatueboss[][4];
extern f32 func_800F10B4(f32, f32, f32, f32, f32);
extern void func_800EE7F8(f32 *, f32 *);
typedef struct {
    f32 values[6];
} StatueAudioTimes;
typedef struct {
    f32 values[5];
} StatueAudioValues;
extern u8 D_80802804_chstatueboss[];
extern u8 D_8080281C_chstatueboss[];
extern u8 D_80802830_chstatueboss[];
extern u8 D_80802844_chstatueboss[];
extern f32 func_800DC178(f32, f32);
extern void func_800C4B64(f32);
extern s32 D_8080285C_chstatueboss[];
extern s32 D_80802894_chstatueboss[];
extern void _chexploder_entrypoint_6(Actor *, f32, f32);
extern void _chexploder_entrypoint_15(Actor *, s32, f32);
extern void func_800BBCB8(f32 *, f32 *, f32, s32, void *);
typedef struct {
    u8 pad_0[0x84];
    s16 index;
    u8 pad_1[0xA];
    f32 position[3];
    f32 angle;
} StatueBossProjectile;
typedef struct {
    f32 local_0[3];
    f32 pad_0;
    f32 local_1;
    f32 pad_1;
} StatueSpawn1772;
typedef struct {
    u8 pad_0[0x10C];
    StatueSpawn1772 local_0[4];
} StatueSpawnData1772;
extern void _chappearfx_entrypoint_1(Actor *, s32, s32, f32);
void func_80800BE0_chstatueboss();
void func_80801640_chstatueboss(s32 param_0, s32 param_1, volatile unsigned int param_2);
void func_80800DA8_chstatueboss();
void func_808010A0_chstatueboss();
void func_80801804_chstatueboss();
void func_80801AF0_chstatueboss();
void func_80801CA0_chstatueboss();
void func_80801ECC_chstatueboss();
void func_80802144_chstatueboss();
extern void func_80105834(), func_80107C2C(), func_80108ED0(), func_8080000C_chstatueboss(),
    func_80800298_chstatueboss();

int chstatueboss_entrypoint_0()
{
    return &D_80802748_chstatueboss;
}

void func_8080000C_chstatueboss(actor) Actor *actor;
{
    u8 *data;
    s32 i;
    s32 unk_0;
    data = func_80100094(actor, 0);
    if (func_800DA298(0x36F) && !_glcutDll_entrypoint_20()) {
        _chintrotext_entrypoint_2(1);
        func_800FFAB0(actor);
        return;
    }
    func_80800BE0_chstatueboss(actor);
    func_80109F08(actor, 0x41);
    *(s16 *) (data + 0x8A) = 0;
    *(s16 *) (data + 0x88) = *(s16 *) (data + 0x8A);
    for (i = 0; i < 4; i++) {
        _subaddiemarker_entrypoint_1(actor, 0x154, i + 0x32,
                                     data + 0x10C + i * 0x18, 1);
    }
    _subaddiemarker_entrypoint_1(actor, 0x320, 0x32, (data + 0xF4), 1);
    _subaddiemarker_entrypoint_1(actor, 0x320, 0x33, data + 0x16C, 4);
    unk_0 = func_800F54E4();
    if (_glcutDll_entrypoint_20()) {
        for (i = 0; i != 4; i++) {
            func_80801640_chstatueboss(actor, i, 1);
        }
        func_80102424(actor, 0x1A);
        return;
    }
    if (!func_800DA298(0x88)) {
        func_800F608C(unk_0, 1);
        func_800F497C(unk_0);
        func_800F49A8(unk_0, 1);
        func_800F49D4(unk_0, func_8010D5DC, actor->unk0);
        func_800F4A58(unk_0, (data + 0xF4), 130.0f);
        data[0x1CD] = 1;
        _capod_entrypoint_13(actor->unk0, 0, 0xC, 0x20);
        _chintrotext_entrypoint_2(1);
        return;
    }
    for (i = 0; i != 4; i++) {
        func_80801640_chstatueboss(actor, i, 1);
    }
    func_800F608C(unk_0, 1);
    func_800F8294(unk_0, (data + 0xF4));
    func_800F497C(unk_0);
    func_80800DA8_chstatueboss(actor, 6);
    _subaddiedialog_entrypoint_11(actor->unk0, 0xF41, 6, actor->position, 0xB2);
    func_80108B04(actor, 3);
    func_80108B04(actor, 4);
    data[0x1CC] = 1;
    data[0x1CD] = 1;
    _capod_entrypoint_13(actor->unk0, 0, 0x12, 0x30);
    func_800FDC28(1);
}

void func_8080232C_chstatueboss();

void func_80801A6C_chstatueboss(u8 *param_0, f32 param_1);

void func_80801448_chstatueboss();

void func_8080124C_chstatueboss();

void func_808011B4_chstatueboss();

// Per-frame state machine.
void func_80800298_chstatueboss(actor) Actor *actor;
{
    extern u8 D_808027AC_chstatueboss[];
    extern void _chbaddiesetup_entrypoint_10(void);

    u8 *data;
    s32 unk_0;
    s32 spin_mode;
    s32 unk_1;
    f32 ground_pos[3];
    f32 bone_pos[3];

    data = (u8 *) func_80100094(actor, 0);
    unk_0 = 0;
    spin_mode = 0;
    unk_1 = 0;

    _sudeflect_entrypoint_1(actor->position, 400.0f, -100.0f, 550.0f, 2);

    if ((s32) actor->unk70_10 >= 7) {
        func_800D2498(0xF3, 0x10 - *(s16 *) (data + 0x8A), 0);
    }

    if (!func_800D0B68(1, 1)) {
        if (_subaddieskeleton_entrypoint_2(actor->unk0, 0xA, ground_pos)) {
            if (ground_pos[1] < actor->position[1]) {
                ground_pos[1] = actor->position[1];
            }

            func_800D1254(1, 1, ground_pos);
        }
    }

    switch (actor->unk70_10) {
        case 1:
            if (!func_800DA298(0x6AD)) {
                if (*(u8 *) (data + 0x1D0) == 0) {
                    *(u8 *) (data + 0x1D0) = 1;

                    _subaddiedialog_entrypoint_11(actor->unk0, 0xF43, 0x44, actor->position,
                                                  0xB2);
                }
            }

            if (*(u8 *) (data + 0x1CF) != 0 && *(u8 *) (data + 0x1CE) != 0) {
                func_800F82D4(func_800F54E4(), 0);
                func_80800DA8_chstatueboss(actor, 2);
            }

            break;

        case 3:
            if (func_80101E14(actor, 0.1f)) {
                func_80801C78_chstatueboss(actor);
            }

            func_80801A6C_chstatueboss(actor, 0.35f);

            if (func_80101DDC(actor)) {
                _subaddiedialog_entrypoint_11(actor->unk0, 0xF33, 6, actor->position, 0xB2);

                func_80800DA8_chstatueboss(actor, 4);
            }
            break;

        case 5:
            if (_subaddieaudioquick_entrypoint_4(actor, actor->position,
                                                 &D_80802790_chstatueboss,
                                                 D_808027AC_chstatueboss)) {
                func_800E15CC(0, 10.0f, 0.8f);
                func_80018820(0, 2.0f, 0.25f);
            }

            unk_1 = func_80102320(actor, 0.6f, 0.99f);

            func_80801AC4_chstatueboss(actor, unk_1);

            if (func_80101DDC(actor)) {
                _subaddiedialog_entrypoint_11(actor->unk0, 0xF34, 6, actor->position, 0xB2);

                func_80800DA8_chstatueboss(actor, 6);
            }
            break;

        case 4:
        case 6:
        case 23:
            func_80801AF0_chstatueboss(actor);
            break;

        case 7:
            if (_subaddieskeleton_entrypoint_0(actor, 0x2D, bone_pos)) {
                func_800EF1B8(bone_pos, func_800F1DF4(bone_pos, actor->position), 120.0f);
                _sudeflect_entrypoint_0(bone_pos, 0.0f, 250.0f, 2);
            }

            if (_subaddieskeleton_entrypoint_0(actor, 0x2C, bone_pos)) {
                func_800EF1B8(bone_pos, func_800F1DF4(bone_pos, actor->position), 120.0f);
                _sudeflect_entrypoint_0(bone_pos, 0.0f, 250.0f, 2);
            }

            spin_mode = 1;
            unk_0 = 1;
            break;

        case 8:
            func_80801A6C_chstatueboss(actor, 0.65f);

            if (func_80101DDC(actor)) {
                func_80800DA8_chstatueboss(actor, 9);
            }
            break;

        case 9:
            func_80801AF0_chstatueboss(actor);
            spin_mode = 2;

            if (_subaddiefind_entrypoint_2(0x112, 0) == 0) {
                func_80801C78_chstatueboss(actor);
                func_80800DA8_chstatueboss(actor, 0xB);
            }
            break;

        case 11:
            spin_mode = 1;
            unk_0 = 1;
            break;

        case 12:
            func_80801A6C_chstatueboss(actor, 0.7f);

            if (func_80101DDC(actor)) {
                func_80800DA8_chstatueboss(actor, 0xD);
            }
            break;

        case 13:
            func_80801AF0_chstatueboss(actor);
            spin_mode = 2;

            if (_subaddiefind_entrypoint_2(0x112, 0) == 0) {
                func_80801C78_chstatueboss(actor);
                func_80800DA8_chstatueboss(actor, 0xF);
            }
            break;

        case 15:
            spin_mode = 1;
            unk_0 = 1;
            break;

        case 16:
            func_80801A6C_chstatueboss(actor, 0.7f);

            if (func_80101DDC(actor)) {
                func_80800DA8_chstatueboss(actor, 0x11);
            }
            break;

        case 17:
            func_80801AF0_chstatueboss(actor);
            spin_mode = 2;

            if (_subaddiefind_entrypoint_2(0x112, 0) == 0) {
                func_80801C78_chstatueboss(actor);
                func_80800DA8_chstatueboss(actor, 0x13);
            }
            break;

        case 19:
            spin_mode = 1;
            unk_0 = 1;
            break;

        case 20:
            func_80801A6C_chstatueboss(actor, 0.85f);

            if (func_80101DDC(actor)) {
                func_80800DA8_chstatueboss(actor, 0x15);
            }
            break;

        case 21:
            func_8080232C_chstatueboss(actor);
            func_80801AF0_chstatueboss(actor);
            spin_mode = 2;

            if (_subaddiefind_entrypoint_2(0x112, 0) == 0) {
                func_80800DA8_chstatueboss(actor, 0x17);
            }
            break;

        case 24:
            func_8080232C_chstatueboss(actor);

            if (func_800CEAD0(0)) {
                func_800E15CC(0, 30.0f, 0.8f);
                func_80018820(0, 3.0f, 0.25f);

                _chbaddiesetup_entrypoint_5(
                    _chbaddiesetup_entrypoint_10, 5, *(s32 *) &actor->position[0],
                    *(s32 *) &actor->position[1], *(s32 *) &actor->position[2],
                    *(s32 *) &actor->rotation[1]);

                _chexploder_entrypoint_5(actor, 0x7CC, actor->position,
                                         *(f32 *) (data + 0x80), actor->scale, 0);

                func_80108B04(actor, 2);
                func_800DA544(0x36F);
                func_800FDC28(0);
            }
            break;

        case 25:
            if (func_800D9078(&actor->unk58)) {
                _gcfrontend_entrypoint_10();
            }
            break;

        case 10:
        case 14:
        case 18:
        case 22:
            spin_mode = 2;
            break;

        case 26:
            func_80801AF0_chstatueboss(actor);
    }

    switch (spin_mode) {
        case 1:
            func_808011B4_chstatueboss(actor);
            break;
        case 2:
            func_8080124C_chstatueboss(actor);
    }

    if (unk_1 == 0) {
        unk_1 = (spin_mode == 1);
    }

    func_80801AC4_chstatueboss(actor, unk_1);
    func_80801804_chstatueboss(actor, unk_0);
    func_80801448_chstatueboss(actor);
}

void func_80802268_chstatueboss();

void func_808020EC_chstatueboss();

void func_80801F74_chstatueboss();

void func_80801518_chstatueboss();

void func_80801320_chstatueboss();

// Message handler.
s32 func_80800934_chstatueboss(Actor *actor, s32 msg, u32 arg)
{
    u8 *data;
    data = func_80100094(actor, 0);
    switch (msg) {
        case 0x2E:
            func_808010A0_chstatueboss(actor, ((s16 *) &arg)[0], ((s16 *) &arg)[1]);
            break;
        case 0x40:
            func_80801518_chstatueboss(actor, *(u32 *) &arg);
            break;
        case 0xB:
            if (arg == 0x10) {
                func_80800DA8_chstatueboss(actor, 3);
                return 4;
            }
            return 3;
        case 0x3D:
            switch (arg) {
                case 0:
                    func_80801ECC_chstatueboss(actor);
                    break;
                case 1:
                    func_80802144_chstatueboss(actor);
                    break;
                case 2:
                    func_80801F74_chstatueboss(actor);
                    break;
                case 3:
                    func_808020EC_chstatueboss(actor);
                    break;
                case 4:
                    func_80802268_chstatueboss(actor);
            }
            break;
        case 0x90:
            func_80801CA0_chstatueboss(actor);
            break;
        case 0x32:
            data[0x1CE] = 1;
            func_800F82D4(func_800F54E4(), 2);
            break;
        case 0x96:
            if (!func_800D395C()) {
                return 0;
            }
            _subaddiedialog_entrypoint_11(actor->unk0, 0xCEB, 0x146, actor->position, 0xB2);
            break;
        case 0x9F:
            func_800FDC28(0);
            func_80800DA8_chstatueboss(actor, D_808027C0_chstatueboss[*(s16 *) (data + 0x84)]);
            break;
        case 0x9C:
            func_80801320_chstatueboss(actor);
            break;
        case 0x95:
            _subaddiecustomhits_entrypoint_0(actor, &_chstatueboss_entrypoint_1);
            break;
        default:
            return 0;
    }
    return 1;
}

int func_80800B74_chstatueboss(actor, arg)
s32 actor;
s32 arg;
{
    u8 *data;
    s32 i;
    data = func_80100094(actor, 0);
    for (i = 1; i < 0x16; i++) {
        func_800DF744(i | 0, data[i]); // Matching: `| 0` is needed for the match.
    }

    func_80101870(actor, arg);
}

// Resets the section states and timers.
void func_80800BE0_chstatueboss(actor) Actor *actor;
{
    StatueResetData *data;
    s32 i;
    s32 section;
    s32 part;

    data = func_80100094(actor, 0);
    for (i = 0; i != 4; i++)
        func_80801640_chstatueboss((s32) actor, i, 0);
    func_80801640_chstatueboss((s32) actor, 4, 1);
    for (section = 0; section < 4; section++) {
        for (i = 0; D_808025C0_chstatueboss[section][i] != -1; i++) {
            part = D_808025C0_chstatueboss[section][i];
            data->states[part] = 2;
        }
    }
    for (i = 0; i < 5; i++)
        data->parts[i] = 0.0f;
    for (i = 0; i < 6; i++) {
        data->joints[i].state = 0;
        data->joints[i].timer = 0.0f;
        data->joints[i].offset = 0.0f;
    }
    for (i = 1; i < 22; i++)
        data->timers[i] = 0.0f;
    data->phase = 0;
}

void func_80800D30_chstatueboss(Actor *actor)
{
    StatueState1436 *data;
    s32 phase;
    s32 i;
    s32 part;
    data = func_80100094(actor, 0);
    phase = data->phase;
    i = 0;
    while (D_808025C0_chstatueboss[phase][i] != -1) {
        part = D_808025C0_chstatueboss[phase][i];
        data->states[part] = 1;
        i++;
    }
}

void func_80801E90_chstatueboss();

void func_80801E24_chstatueboss();

void func_80800DA8_chstatueboss(actor, state) Actor *actor;
s32 state;
{
    s32 i;
    u8 *data;

    data = func_80100094(actor, 0);
    func_80102424(actor, state);
    switch (state) {
        case 2:
            func_80801E24_chstatueboss(actor, 16, 48);
            func_80101180(0x450, 8, 0);
            return;
        case 3:
            func_80801E24_chstatueboss(actor, 0, 48);
            func_80108B04(actor, 3);
            func_800FDC28(1);
            return;
        case 5:
            for (i = 0; i != 4; i++) {
                func_80801640_chstatueboss(actor, i, 1);
            }
            _chintrotext_entrypoint_1(0x18B9, 4, 1, 0);
            func_80801E24_chstatueboss(actor, 6, 48);
            func_80101180(0x449, 7, 0);
            func_80108B04(actor, 4);
            return;
        case 8:
            *(s16 *) (data + 0x88) = 0;
            *(s16 *) (data + 0x84) = 1;
            _chexploder_entrypoint_5(actor, 0x7C8, actor->position, *(f32 *) (data + 0x70),
                                     actor->scale, 0);
            return;
        case 12:
            *(s16 *) (data + 0x88) = 0;
            *(s16 *) (data + 0x84) = 2;
            _chexploder_entrypoint_5(actor, 0x7C9, actor->position, *(f32 *) (data + 0x74),
                                     actor->scale, 0);
            return;
        case 16:
            *(s16 *) (data + 0x88) = 0;
            *(s16 *) (data + 0x84) = 3;
            _chexploder_entrypoint_5(actor, 0x7CA, actor->position, *(f32 *) (data + 0x78),
                                     actor->scale, 0);
            return;
        case 9:
            _subaddiedialog_entrypoint_11(actor->unk0, 0xF35, 6, actor->position, 0xB2);
            func_80801E24_chstatueboss(actor, 10, 48);
        case 13:
        case 17:
        case 21:
            func_80108B04(actor, 1);
            return;
        case 7:
            func_800FDC28(2);
            func_800DA544(0x88);
            _gcfrontend_entrypoint_9(0x23);
            func_80801E90_chstatueboss(actor);
        case 11:
        case 15:
        case 19:
            func_8010A590(actor);
            func_80800D30_chstatueboss(actor);
            return;
        case 20:
            *(s16 *) (data + 0x88) = 0;
            func_8010A570(actor);
            _chexploder_entrypoint_5(actor, 0x7CB, actor->position, *(f32 *) (data + 0x7C),
                                     actor->scale, 0);
            return;
        case 23:
            func_80801E24_chstatueboss(actor, 20, 48);
            _subaddiedialog_entrypoint_11(actor->unk0, 0xF36, 6, actor->position, 0xB2);
            return;
        case 24:
            _subaddieaudioquick_entrypoint_2(actor, actor->position, D_808027C8_chstatueboss);
            func_800CE88C(0, 1);
            func_800CE8D8(0, 3.0f, 3);
            return;
        case 25:
            actor->unk64_16 = 0;
            actor->unk58 = 6.0f;
    }
}

void func_808010A0_chstatueboss(actor, dialog_id, arg) Actor *actor;
s32 dialog_id;
s32 arg;
{
    u8 *data;

    data = func_80100094(actor, 0);
    switch (dialog_id) {
        case 0xF33:
            func_80800DA8_chstatueboss(actor, 5);
            break;
        case 0xF41:
            func_80800DA8_chstatueboss(actor, 7);
            break;
        case 0xF34:
            func_80800DA8_chstatueboss(actor, 7);
            break;
        case 0xF36:
            func_80801E90_chstatueboss(actor);
            func_80800DA8_chstatueboss(actor, 24);
            break;
        case 0xF43:
            data[0x1CF] = 1;
            break;
        case 0xF35:
            func_80801E90_chstatueboss(actor);
            break;
        case 0xCEB:
            if (arg > 0)
                _gcfrontend_entrypoint_11();
            else
                _gcfrontend_entrypoint_10();
    }
}

int func_808011A0_chstatueboss(s32 index)
{
    return D_808027D4_chstatueboss[index];
}

void func_808011B4_chstatueboss(Actor *actor)
{
    StatueBossAngles *data;
    s32 i;
    data = func_80100094(actor, 0);
    for (i = data->start; i < 5; i++) {
        data->angles[i] += func_800D8FF8() * D_80802630_chstatueboss[i];
        data->angles[i] = func_800136E4(data->angles[i]);
    }
}

void func_8080124C_chstatueboss(Actor *actor)
{
    StatueBossRotations *data;
    s32 i;
    f32 delta;

    data = func_80100094(actor, 0);
    for (i = data->local_1; i < 5; i++) {
        if (!func_800F20BC(data->local_0[i], 0.0f, 5.0f)) {
            delta = func_800D8FF8();
            data->local_0[i] =
                func_800F1F38(data->local_0[i], 0.0f,
                              mlAbsF(D_80802630_chstatueboss[i]) * delta);
            data->local_0[i] = func_800136E4(data->local_0[i]);
        }
    }
}

void func_80801320_chstatueboss(Actor *actor)
{
    s32 unk_0;
    u8 *data;
    s32 i;

    unk_0 = func_8010262C(actor->unk0, 12);
    if (unk_0) {
        data = func_80100094(actor, 0);
        for (i = 0; i < 5; i++) {
            func_800E0AFC(unk_0, (u8) func_808011A0_chstatueboss(i), 1.0f, 0.0f,
                          *(f32 *) (data + 0x70 + i * 4), 0.0f);
        }
        func_800E0B8C(unk_0, 0x52, 1.0f, 1.0f, 2.0f, 1.0f);
        for (i = 0; i < 6; i++) {
            func_800E0C20(unk_0, D_8080265C_chstatueboss[i * 2 + 1], 1.0f, 0.0f,
                          *(f32 *) (data + 0xA8 + i * 12), 0.0f);
        }
    }
}

void func_80801448_chstatueboss(Actor *actor)
{
    StatueState1436 *data;
    s32 i;
    s32 part;
    s32 phase;

    data = func_80100094(actor, 0);
    phase = data->phase;
    for (i = 0; D_808025C0_chstatueboss[phase][i] != -1; i++) {
        part = D_808025C0_chstatueboss[phase][i];
        if (data->states[part] == 2 && func_800D9078(&data->timers[part])) {
            data->states[part] = 1;
        }
    }
}

void func_80801518_chstatueboss(Actor *actor, s32 hit_arg)
{
    u8 *data;
    s32 i;
    s32 hit_part;
    s32 phase;
    s32 hits_needed;

    data = func_80100094(actor, 0);
    phase = *(s16 *) (data + 0x84);
    hit_part = *(s16 *) (data + 0x86);
    for (i = 0; D_808025C0_chstatueboss[phase][i] != -1; i++) {
        if (hit_part == D_808025C0_chstatueboss[phase][i]) {
            data[hit_part] = 2;
            *(f32 *) (data + hit_part * 4 + 0x18) = 2.5f;
            func_800FC660(14);
            (*(s16 *) (data + 0x8A))++;
            func_800EC398(hit_arg, data + 0xE8);
            (*(s16 *) (data + 0x88))++;
            if (!func_800DA298(0x681)) {
                hits_needed = *(s16 *) (D_80802644_chstatueboss + phase * 2);
            } else {
                hits_needed = 100;
            }
            if (hits_needed == *(s16 *) (data + 0x88)) {
                func_80800DA8_chstatueboss(actor,
                                           *(s16 *) (D_808027E0_chstatueboss + phase * 2));
            }
            break;
        }
    }
}

void func_80801640_chstatueboss(s32 actor, s32 index, volatile unsigned int value)
{
    s32 addr;
    s16 offset;
    addr = func_80100094(actor, 0);
    offset = D_80802624_chstatueboss[index];
    addr += offset;
    *(u8 *) addr = value;
}

int chstatueboss_entrypoint_1()
{
    return (int) &D_808027E8_chstatueboss;
}

s32 func_80801694_chstatueboss(Actor *actor)
{
    StatueState1436 *data;
    s32 i;
    u32 mask;
    s32 phase;
    s32 part;
    data = func_80100094(actor, 0);
    phase = data->phase;
    mask = 0;
    for (i = 0; D_808025C0_chstatueboss[phase][i] != 0xFFFFFFFF; i++) {
        part = D_808025C0_chstatueboss[phase][i];
        if (data->states[part] == 1)
            mask |= 1U << (part - 1);
    }
    return 0xFFFFFFFF ^ mask;
}

s32 func_80801724_chstatueboss(u8 *obj, s32 param_1, f32 param_2, s32 param_3, s32 param_4)
{
    s32 unk_0;
    u8 *data;
    s32 unk_1;
    Actor *boss;
    void *model;

    boss = func_80106790((s32) obj);
    data = (u8 *) func_80100094(boss, 0);
    unk_1 = func_80103AA0(obj);
    if (!unk_1 || !(unk_0 = func_800AE0E8(*(s16 *) (obj + 16))))
        return 0;
    param_4 = func_80801694_chstatueboss(boss);
    model = func_800B2824(unk_1);
    *(s16 *) (data + 0x86) =
        func_800B1F8C(model, boss->position, boss->rotation, boss->scale, 0,
                      func_800AE080(*(s16 *) (obj + 16)), param_1, param_2, param_3, param_4);
    return *(s16 *) (data + 0x86);
}

void func_80801804_chstatueboss(Actor *actor, s32 check_hit)
{
    StatueJointData *data;
    s32 i;
    s32 phase;
    f32 bone_pos[3];
    f32 unk_0;
    f32 unk_1[3];
    s32 done;
    s32 joint;

    data = func_80100094(actor, 0);
    phase = data->phase;
    if (func_800F6438(func_800F54E4())) {
        unk_0 = func_8010CD28(actor);
        for (i = 0; i < 6; i++) {
            switch (data->joints[i].local_0) {
                case 1:
                    done = func_800D90A4(&data->joints[i].local_1);
                    data->joints[i].local_2 =
                        func_800F10B4(data->joints[i].local_1, 0.0f, 0.6f, -2.0f, 0.0f);
                    if (done) {
                        data->joints[i].local_0 = 2;
                        data->joints[i].local_1 = 1.2f;
                    }
                    break;
                case 2:
                    done = func_800D90A4(&data->joints[i].local_1);
                    data->joints[i].local_2 =
                        func_800F10B4(data->joints[i].local_1, 0.0f, 1.2f, 0.0f, -2.0f);
                    if (done)
                        data->joints[i].local_0 = 0;
            }
        }
        if (check_hit && func_8010D248()) {
            func_8008FE68(unk_1);
            for (i = 0; D_808025FC_chstatueboss[phase][i] != -1; i++) {
                if (1) { // Matching: empty block is needed for the match.
                }
                joint = D_808025FC_chstatueboss[phase][i] - 4;
                func_800D9078(&data->joints[joint].local_1);
                if (!data->joints[joint].local_0 &&
                    _subaddieskeleton_entrypoint_2(
                        actor->unk0, D_808025FC_chstatueboss[phase][i], bone_pos) &&
                    func_800F20BC(func_800F1DF4(actor->position, bone_pos), unk_0, 25.0f)) {
                    func_80108B04(actor, 0);
                    func_800EE7F8(data->position, bone_pos);
                    data->angle = func_800F1DF4(bone_pos, unk_1);
                    data->joints[joint].local_1 = 0.6f;
                    data->joints[joint].local_0 = 1;
                }
            }
        }
    }
}

void func_80801A6C_chstatueboss(u8 *param_0, f32 param_1)
{
    if (_subaddieaudioquick_entrypoint_3(param_0, param_0 + 4, &D_80802790_chstatueboss, param_1)) {
        func_800E15CC(0, 20.0f, 0.8f);
        func_80018820(0, 3.0f, 0.25f);
    }
}

int func_80801AC4_chstatueboss(s32 param_0, s32 param_1)
{
    _subaddieaudioloop_entrypoint_4(param_0, param_0 + 4, param_1 | 0, &D_808027F8_chstatueboss); // Matching: `| 0` is needed for the match.
}

void func_80801AF0_chstatueboss(actor) Actor *actor;
{
    StatueAudioTimes times;
    StatueAudioValues unk_0;
    StatueAudioValues unk_1;
    s32 i;
    times = *(StatueAudioTimes *) D_80802804_chstatueboss;
    unk_0 = *(StatueAudioValues *) D_8080281C_chstatueboss;
    unk_1 = *(StatueAudioValues *) D_80802830_chstatueboss;
    for (i = 0; times.values[i] != -1.0f; i++) {
        if (func_80101E14(actor, times.values[i])) {
            func_800C4B64(unk_0.values[i] + func_800DC178(-0.05f, 0.05f));
            func_800C4B70((s32) unk_1.values[i]);
            _subaddieaudioquick_entrypoint_2(actor, actor->position, D_80802844_chstatueboss);
            return;
        }
    }
}

int func_80801C78_chstatueboss(s32 param_0)
{
    s32 pos;
    pos = param_0 + 4;
    _subaddieaudioquick_entrypoint_2(param_0, pos, &D_80802850_chstatueboss);
}

void func_80801CA0_chstatueboss(actor) Actor *actor;
{
    s32 y_offset;
    u8 *data;
    Actor *explosion;
    y_offset = 0;
    data = func_80100094(actor, 0);
    explosion = func_80106790((Unk80132ED0 *) func_80101080());
    _chexploder_entrypoint_12(explosion, 40);
    _chexploder_entrypoint_6(explosion, 1200.0f, 1600.0f);
    _chexploder_entrypoint_15(explosion, 1, 1.25f);
    switch (actor->unk70_10) {
        case 8:
            y_offset = 80;
            func_80801640_chstatueboss(actor, 0, 0);
            break;
        case 12:
            y_offset = 80;
            func_80801640_chstatueboss(actor, 1, 0);
            break;
        case 16:
            y_offset = 80;
            func_80801640_chstatueboss(actor, 2, 0);
            break;
        case 20:
            y_offset = 80;
            func_80801640_chstatueboss(actor, 3, 0);
            break;
        case 24:
            y_offset = 80;
            func_80801640_chstatueboss(actor, 4, 0);
            break;
    }
    _subaddieaudioquick_entrypoint_2(explosion, explosion->position, &D_80802894_chstatueboss);
    func_800BBCB8(explosion->position, explosion->position, 1.0f, 6, &D_8080285C_chstatueboss);
    explosion = func_80106790(*(Unk80132ED0 **) (data + 0x8C));
    explosion->position[1] -= actor->scale * y_offset;
}

void func_80801E24_chstatueboss(s32 *actor, s32 param_1, s32 flags)
{
    s32 *data_copy;
    s32 *data;

    data = func_80100094(actor, 0);
    data_copy = data;
    if (*(u8 *) ((char *) data + 0x1CD) != 0) {
        flags |= 0x2000;
        _capod_entrypoint_14();
    }
    _capod_entrypoint_13(*actor, 0, param_1, flags);
    *(u8 *) ((char *) data_copy + 0x1CD) = 1;
}

void func_80801E90_chstatueboss(s32 actor)
{
    u8 *data;

    data = func_80100094(actor, 0);
    if (data[0x1CD] != 0) {
        _capod_entrypoint_14();
        data[0x1CD] = 0;
    }
}

// Fires one dart.
void func_80801ECC_chstatueboss(actor) Actor *actor;
{
    StatueBossProjectile *data;
    Actor *dart;
    data = func_80100094(actor, 0);
    dart = func_80108528(0x448, data->position, (s32) data->angle, &actor);
    dart->rotation[1] = data->angle;
    if (!func_800DA298(0x682))
        *(f32 *) &dart->actorData[3] = D_8080264C_chstatueboss[data->index];
    else
        *(f32 *) &dart->actorData[3] = 10000.0f;
    _subaddieaudioquick_entrypoint_2(actor, data->position, D_80802668_chstatueboss);
}

// Fires a ring of 10 darts, then ends the fight.
void func_80801F74_chstatueboss(Actor *actor)
{
    u8 *data;
    f32 angle;
    Actor *dart;
    s32 i;
    f32 pos[3];
    data = func_80100094(actor, 0);
    angle = func_8010CD28(actor);
    for (i = 0; i < 10; i++) {
        func_800EEB9C(pos, angle, 50.0f);
        func_800EF04C(pos, actor->position);
        pos[1] += 100.0f;
        dart = func_80108528(0x448, pos, (s32) angle, &actor);
        dart->rotation[1] = angle;
        *(f32 *) ((u8 *) dart + 0x24) = D_8080264C_chstatueboss[3];
        angle += 36.0f;
    }
    _subaddieaudioquick_entrypoint_2(actor, actor->position, &D_80802668_chstatueboss);
    func_800D1254(1, 1, actor->position);
    if (func_800D395C())
        func_80800DA8_chstatueboss(actor, 0x19);
    else {
        func_80101180(0x450, 7, 0);
        func_800FFAB0(actor);
    }
    func_800FFA88(*(void **) (data + 0x8C));
    *(void **) (data + 0x8C) = NULL;
}

void func_808020EC_chstatueboss(u8 *actor)
{
    u8 *data;
    s32 *piece_alias;
    s32 *piece;

    data = func_80100094(actor, 0);
    piece = func_801084B0(0x44F, &actor);
    piece_alias = piece;
    func_80102FDC(piece, *(s32 *) ((s8 *) actor + 0x38));
    *(s32 *) ((s8 *) data + 0x8C) = (s32) *piece_alias;
}

// Spawns minions (0x112); count depends on the state.
void func_80802144_chstatueboss(actor) Actor *actor;
{
    Actor *minion;
    StatueSpawnData1772 *data;
    s32 i;
    s32 count;

    data = func_80100094(actor, 0);
    count = 1;
    switch (actor->unk70_10) {
        case 13:
            count = 2;
            break;
        case 17:
            count = 3;
            break;
        case 21:
            count = 4;
    }
    for (i = 0; i < count; i++) {
        minion = func_80108528(0x112, data->local_0[i].local_0,
                                (s32) data->local_0[i].local_1, &actor);
        _chappearfx_entrypoint_1(minion, 0x2A, 0, 0.6f);
        func_80100120(minion);
        _sucoaster_entrypoint_4(minion);
        minion->unk74_17 = 0;
    }
}

// Spawns four minions (0x1C8).
void func_80802268_chstatueboss(Actor *actor)
{
    StatueBossSpawnList *data;
    Actor *minion;
    s32 i;

    data = func_80100094(actor, 0);
    for (i = 0; i < 4; i++) {
        minion = func_80108474(0x1C8, data->local_0[i].local_0,
                                (s32) data->local_0[i].local_1);
        minion->unk74_7 = 0x33;
        if (data->local_1 == 0)
            _chappearfx_entrypoint_2(minion, 0x20, 0, 1.0f);
    }
}

void func_8080232C_chstatueboss(Actor *actor)
{
    f32 pos[3];

    if (_subaddieskeleton_entrypoint_0(actor, 0x1E, pos)) {
        func_800EF1B8(pos, func_800F1DF4(actor->position, pos), 8e+01f);
        pos[1] = actor->position[1];
        _sudeflect_entrypoint_1(pos, 300.0f, -50.0f, 250.0f, 2);
    }
    if (_subaddieskeleton_entrypoint_0(actor, 0x10, pos)) {
        func_800EF1B8(pos, func_800F1DF4(actor->position, pos), 80.0f);
        pos[1] = actor->position[1];
        _sudeflect_entrypoint_1(pos, 300.0f, -50.0f, 250.0f, 2);
    }
}

s16 D_808025C0_chstatueboss[5][6] = {0x8,  0x9, 0xA,  0xB,  0xC,  -0x1, 0xD, 0xE, 0xF,  0x10,
                                     -0x1, 0x0, 0x11, 0x12, 0x13, -0x1, 0x0, 0x0, 0x14, 0x15,
                                     -0x1, 0x0, 0x0,  0x0,  0x0,  0x0,  0x0, 0x0, 0x0,  0x0};
s16 D_808025FC_chstatueboss[5][4] = {-0x1, 0x0, 0x0, 0x0, 0x4, -0x1, 0x0, 0x0, 0x5, 0x6,
                                     -0x1, 0x0, 0x7, 0x8, 0x9, -0x1, 0x0, 0x0, 0x0, 0x0};
s16 D_80802624_chstatueboss[6] = {0x3, 0x4, 0x5, 0x6, 0x7, 0x0};
f32 D_80802630_chstatueboss[5] = {3e+01f, -5e+01f, 7e+01f, -9e+01f, 1.1e+02f};
u8 D_80802644_chstatueboss[8] = {0x0, 0x4, 0x0, 0x4, 0x0, 0x4, 0x0, 0x4};
f32 D_8080264C_chstatueboss[4] = {0.0f, 2.4e+03f, 2.8e+03f, 3.2e+03f};
u8 D_8080265C_chstatueboss[12] = {0x0, 0x35, 0x0, 0x41, 0x0, 0x40, 0x0, 0x50, 0x0, 0x51, 0x0, 0x4F};
u8 D_80802668_chstatueboss[8] = {0x0, 0x13, 0x4, 0xAC, 0x0, 0x2, 0x0, 0x0};
u8 D_80802670_chstatueboss[216] = {
    0x0,  0x0,  0x0,  0x0,  0x0, 0x0,  0x0, 0x0,  0x40, 0x20, 0x0,  0x0,  0x3, 0x9,  0x0, 0x44,
    0x40, 0x20, 0x0,  0x0,  0x3, 0x9,  0x0, 0x44, 0x40, 0x20, 0x0,  0x0,  0x3, 0x9,  0x0, 0x2,
    0x40, 0x66, 0x66, 0x66, 0x3, 0xA,  0x0, 0x1,  0x40, 0xA0, 0x0,  0x0,  0x3, 0x3,  0x2, 0x2,
    0x40, 0x66, 0x66, 0x66, 0x3, 0x4,  0x0, 0x1,  0x3F, 0x99, 0x99, 0x9A, 0x3, 0x5,  0x0, 0x44,
    0x3F, 0x99, 0x99, 0x9A, 0x3, 0x5,  0x0, 0x2,  0x40, 0x66, 0x66, 0x66, 0x3, 0x20, 0x0, 0x1,
    0x40, 0x66, 0x66, 0x66, 0x3, 0x4,  0x0, 0x1,  0x3F, 0x8C, 0xCC, 0xCD, 0x3, 0x6,  0x0, 0x44,
    0x3F, 0x8C, 0xCC, 0xCD, 0x3, 0x6,  0x0, 0x2,  0x40, 0x66, 0x66, 0x66, 0x3, 0x21, 0x0, 0x1,
    0x40, 0x66, 0x66, 0x66, 0x3, 0x20, 0x0, 0x1,  0x3F, 0x80, 0x0,  0x0,  0x3, 0x7,  0x0, 0x44,
    0x3F, 0x80, 0x0,  0x0,  0x3, 0x7,  0x0, 0x2,  0x40, 0x66, 0x66, 0x66, 0x3, 0x22, 0x0, 0x1,
    0x40, 0x66, 0x66, 0x66, 0x3, 0x21, 0x0, 0x1,  0x3F, 0x80, 0x0,  0x0,  0x3, 0x8,  0x0, 0x44,
    0x3F, 0x80, 0x0,  0x0,  0x3, 0x8,  0x0, 0x2,  0x40, 0x66, 0x66, 0x66, 0x3, 0xA,  0x0, 0x1,
    0x40, 0x66, 0x66, 0x66, 0x3, 0x22, 0x0, 0x1,  0x40, 0x66, 0x66, 0x66, 0x3, 0xA,  0x0, 0x1,
    0x40, 0x53, 0x33, 0x33, 0x3, 0xB,  0x0, 0x2,  0x0,  0x0,  0x0,  0x0,  0x0, 0x0,  0x0, 0x0,
    0x40, 0x66, 0x66, 0x66, 0x3, 0x4,  0x0, 0x1};
void *D_80802748_chstatueboss = (void *) 0x01BC0447;
static u32 D_80802748_chstatueboss_rest[17] = {0x7F40001,
                                               (u32) &D_80802670_chstatueboss,
                                               (u32) func_80800298_chstatueboss,
                                               (u32) func_80105834,
                                               (u32) func_80800B74_chstatueboss,
                                               0x752F,
                                               0x0,
                                               0x0,
                                               0x560,
                                               0x0,
                                               (u32) func_80108ED0,
                                               0x1D40000,
                                               (u32) func_8080000C_chstatueboss,
                                               (u32) func_80107C2C,
                                               0x80800402,
                                               (u32) func_80800934_chstatueboss,
                                               0x0};
s32 D_80802790_chstatueboss[7] = {0x1304CC, 0xD00F3, 0x10C0002, 0x0, 0x1304F9, 0xA00C0, 0x20000};
u8 D_808027AC_chstatueboss[20] = {0x3D, 0xCC, 0xCC, 0xCD, 0x3E, 0x61, 0x47, 0xAE, 0x3E, 0xB3,
                                  0x33, 0x33, 0x3F, 0x0,  0x0,  0x0,  0xBF, 0x80, 0x0,  0x0};
s16 D_808027C0_chstatueboss[4] = {0xA, 0xE, 0x12, 0x16};
u8 D_808027C8_chstatueboss[12] = {0x0, 0x13, 0x4, 0xF9, 0x0, 0xA, 0x0, 0xD9, 0x0, 0x2, 0x0, 0x0};
s16 D_808027D4_chstatueboss[6] = {0x2A, 0x2E, 0x36, 0x42, 0x52, 0x0};
u8 D_808027E0_chstatueboss[8] = {0x0, 0x8, 0x0, 0xC, 0x0, 0x10, 0x0, 0x14};
int D_808027E8_chstatueboss[4] = {0x0, 0x0, 0x0, (u32) func_80801724_chstatueboss};
s32 D_808027F8_chstatueboss[3] = {0x1304AD, 0x1661A8, 0x20000};
u8 D_80802804_chstatueboss[24] = {0x3E, 0xCC, 0xCC, 0xCD, 0x3F, 0x1C, 0x28, 0xF6,
                                  0x3F, 0x42, 0x8F, 0x5C, 0x3F, 0x5E, 0xB8, 0x52,
                                  0x3F, 0x7D, 0x70, 0xA4, 0xBF, 0x80, 0x0,  0x0};
u8 D_8080281C_chstatueboss[20] = {0x3F, 0x33, 0x33, 0x33, 0x3F, 0x19, 0x99, 0x9A, 0x3F, 0xC,
                                  0xCC, 0xCD, 0x3F, 0x0,  0x0,  0x0,  0x3F, 0x0,  0x0,  0x0};
u8 D_80802830_chstatueboss[20] = {0x46, 0xFA, 0x0,  0x0,  0x46, 0xEA, 0x60, 0x0,  0x46, 0xDA,
                                  0xC0, 0x0,  0x46, 0xCB, 0x20, 0x0,  0x46, 0xC3, 0x50, 0x0};
u8 D_80802844_chstatueboss[12] = {0x0, 0x13, 0x4, 0xBA, 0x0, 0x2, 0x0, 0x1D, 0x0, 0x1E, 0x0, 0x0};
u8 D_80802850_chstatueboss[12] = {0x0, 0x13, 0x4, 0xF9, 0x0, 0xA, 0x0, 0xC0, 0x0, 0x2, 0x0, 0x0};
s32 D_8080285C_chstatueboss[14] = {0x1D09DD,    0x2B0300, 0x4000022, 0x2800380, 0x4800580,
                                   0x150000,    0x990019, 0x7,       0x2D0064,  0x96001F,
                                   -0x21588F00, 0xB0096,  0xC80064,  0xA0000};
s32 D_80802894_chstatueboss[3] = {0x130413, 0x180002, 0x0};
