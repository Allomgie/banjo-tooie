// Most likely Cheato, the spell book NPC: plays his theme near the player, talks, trades
// 5 Cheato Pages per cheat and opens a menu listing the cheats already given.
#include "common.h"
#include "gc/newoption.h"

extern int D_80800E98_chcheato[];
extern s32 D_80800E50_chcheato[];
extern int func_800EB854(void);
extern void func_80101870(Actor *, s32);
extern s32 D_80800EE0_chcheato[];
extern s16 D_80800EE6_chcheato;
extern s16 D_80800EF4_chcheato[];
typedef struct {
    f32 time[2];
} CheatoSoundTimes;
typedef struct {
    s16 id[2];
} CheatoSoundIds;
extern CheatoSoundTimes D_80800EFC_chcheato;
extern CheatoSoundIds D_80800F04_chcheato;
extern s16 D_80800F08_chcheato[];
extern s32 func_80101E14(Actor *, f32);
extern void func_800D3EF4();
extern s32 _gcnewoption_entrypoint_17(s32, u32);
typedef struct {
    s16 rgb[3];
} CheatoOptionDescriptor;
extern CheatoOptionDescriptor D_80800F20_chcheato;
extern CheatoOptionDescriptor D_80800F28_chcheato;
extern u8 _gcnewoption_entrypoint_35[];
extern u8 _gcnewoption_entrypoint_16[];
extern void _capod_entrypoint_3(int param_0, Actor *param_1);
extern void _sudeflect_entrypoint_0(f32 *, f32, f32, s32);
extern f32 func_8010CD28(Actor *);
extern void func_80102B2C(Actor *, f32);
s32 func_80800824_chcheato();
int func_80800AB4_chcheato();
s32 func_80800BB8_chcheato();
int func_80800C0C_chcheato();
int func_80800C64_chcheato();
void func_80800D08_chcheato();
void func_80800434_chcheato();

int *chcheato_entrypoint_0()
{
    return &D_80800E98_chcheato;
}

s32 func_8080000C_chcheato(Actor *this)
{
    _subaddieitem_entrypoint_0(func_80100094(this, 1), 0x4E3, -1, 3);
    _subaddieitem_entrypoint_1(func_80100094(this, 1), 0x5);
    func_8010A828(this, 0x9);
}

void func_80800CC0_chcheato();

void func_80800B00_chcheato();

void func_8080078C_chcheato();

void func_808006B8_chcheato();

void func_808003C4_chcheato();

void func_80800068_chcheato(Actor *actor)
{
    f32 item_pos[3];
    _sudeflect_entrypoint_0(actor->position, 150.0f, 150.0f, 0xA);
    func_808006B8_chcheato(actor);
    func_8080078C_chcheato(actor);
    func_800D1824(0x4A);
    switch (actor->unk70_10) {
        case 1:
            if (!actor->unk64_19 && func_8010D23C()) {
                actor->unk54 = func_8010CD28(actor);
                func_80102B2C(actor, 4.0f);
                func_808003C4_chcheato(actor);
            }
            break;
        case 3:
            func_80103DFC(actor, item_pos);
            if (_subaddieitem_entrypoint_3(actor, item_pos, func_80100094(actor, 1))) {
                func_80102424(actor, 2);
                _subaddiedialog_entrypoint_11(actor->unk0, 0x115D, 0xE, actor->position, 0x37);
            }
            break;
        case 4:
            if (!func_800C0638()) {
                func_80800D08_chcheato(actor, 2, 1);
                func_80800B00_chcheato(actor);
            }
            break;
        case 5:
            _gcnewoption_entrypoint_0(func_80100094(actor, 0));
            break;
        case 6:
            _gcnewoption_entrypoint_6(actor, 0);
            func_80090708(0);
            func_80102424(actor, 1);
            func_80800CC0_chcheato(actor);
    }
}

s32 func_80800204_chcheato(Actor *actor, s32 msg, s32 arg)
{
    switch (msg) {
        case 0x2E:
            func_80800434_chcheato(actor, *(s16 *) &arg, ((s16 *) &arg)[1]);
            break;
        case 0x49:
            if (arg == 1) {
                actor->unk64_19 = 1;
                _subaddiedialog_entrypoint_11(actor->unk0, 0x1143, 4, actor->position, 0x37);
                _capod_entrypoint_13(actor->unk0, 0, 1, 0x830);
            }
            break;
        case 0x20:
            func_80800AB4_chcheato(actor, func_80101080(), *(s16 *) &arg,
                                   ((s16 *) &arg)[1]);
            break;
        case 0x52:
            _gcdialogcamera_entrypoint_3(&D_80800E50_chcheato, *(s32 *) &actor->scale);
            break;
        case 0x95:
            actor->unk64_20 = 0;
            break;
        case 0x57:
            return func_80800C64_chcheato(actor, arg & 0xFFFF,
                                          (u32) (arg & 0xFFFF0000) >> 16);
        default:
            return 0;
    }
    return 1;
}

void func_8080035C_chcheato(Actor *actor, s32 param_1)
{
    if (func_800EB854() == 3) {
        if ((((*(u16 *) ((u8 *) actor + 0x72) & 0xFFFFFFFFu) & 0xFFFFFFFFu) >> 10) == 5) {
            _gcnewoption_entrypoint_1(func_80100094(actor, 0), param_1);
        }
    } else {
        func_80101870(actor, param_1);
    }
}

void func_808003C4_chcheato(s32 actor)
{
    s32 dialog_arg;
    s32 result;

    dialog_arg = 0xE;
    D_80800EE6_chcheato = func_80800824_chcheato(&dialog_arg);
    D_80800EF4_chcheato[0] = (s16) dialog_arg;
    result = _subaddiedialog_entrypoint_7(actor, actor + 4, &D_80800EE0_chcheato);
    if ((result != 0) && (result != 0x1208)) {
        func_80800D08_chcheato(actor, 3, 0);
    }
}

s32 func_80800888_chcheato();

void func_80800434_chcheato(actor, dialog_id, param_2) s32 *actor;
s32 dialog_id;
s32 param_2;
{
    s32 dialog_arg;

    switch (dialog_id) {
        case 0x1144:
            _subaddieitem_entrypoint_2(func_80100094(actor, 1));
            func_80102424(actor, 3);
            return;
        case 0x115D:
            _subaddiedialog_entrypoint_11(*actor, func_80800888_chcheato(), 0xE, actor + 1,
                                          0x37);
            return;
        case 0x1142:
            if (func_800D1A04(0x4A) != 0) {
                dialog_arg = 0xE;
                _subaddiedialog_entrypoint_11(*actor, func_80800824_chcheato(&dialog_arg), dialog_arg,
                                              actor + 1, 0x37);
                return;
            }
            func_800C01A8(0x64, 0);
            func_800C0850();
            func_80102424(actor, 1);
            func_80800CC0_chcheato(actor);
            return;
        case 0x1145:
            if (func_80800C0C_chcheato() != 0) {
                func_80102424(actor, 4);
                return;
            }
            func_80102424(actor, 1);
            func_80800CC0_chcheato(actor);
            return;
        case 0x1147:
            func_80102424(actor, 4);
            return;
        case 0x1148:
            func_800DA544(0x69);
            if (func_80800C0C_chcheato() != 0) {
                func_80102424(actor, 4);
                return;
            }
            func_80102424(actor, 1);
            func_80800CC0_chcheato(actor);
            return;
        case 0x114B:;
        case 0x114C:
        case 0x114D:;
        case 0x114E:
        case 0x114F:
            if ((func_800D1A04(0x4A) >= 5) && (func_80800BB8_chcheato() != -1)) {
                _subaddieitem_entrypoint_2(func_80100094(actor, 1));
                func_80102424(actor, 3);
                return;
            }
            if (func_800DA298(0x69) == 0) {
                _subaddiedialog_entrypoint_11(*actor, 0x1148, 0xE, actor + 1, 0x37);
                return;
            }
            _subaddiedialog_entrypoint_11(*actor, 0x115E, 0xE, actor + 1, 0x37);
            return;
        case 0x1143:
            _capod_entrypoint_14();
            _glcutDll_entrypoint_17();
            return;
        case 0x115E:
            func_80102424(actor, 4);
            return;
        default:
            func_80102424(actor, 1);
            func_80800CC0_chcheato(actor);
    }
}

// Plays sounds at fixed animation times.
void func_808006B8_chcheato(Actor *actor)
{
    CheatoSoundTimes sound_times;
    CheatoSoundIds sound_ids;
    s32 i;

    sound_times = D_80800EFC_chcheato;
    sound_ids = D_80800F04_chcheato;
    for (i = 0; i < 2; i++) {
        if (func_80101E14(actor, sound_times.time[i])) {
            func_800C4B7C(sound_ids.id[i]);
            _subaddieaudioquick_entrypoint_2(actor, actor->position, D_80800F08_chcheato);
        }
    }
}

// Fades Cheato music in/out when the player is within range.
void func_8080078C_chcheato(Actor *actor)
{
    s32 player_near;

    player_near = func_8010CAC0((u8 *) actor + 4, 0x2EE);
    if (!actor->unk64_20) {
        if (player_near != 0) {
            func_800FC63C(0x44, 0);
            func_800FCAE0(0x44, -1, 0x1F4);
            actor->unk64_20 = 1;
        }

    } else if (player_near == 0) {
        func_800FCAE0(0x44, 0, 0x1F4);
        func_800FCA90(0x44);
        actor->unk64_20 = 0;
    }
}

s32 func_80800824_chcheato(flags)
u32 *flags;
{
    s32 pages;

    pages = func_800D1A04(0x4A);
    if (func_80800BB8_chcheato() == -1) {
        return 0x1147;
    }
    if (pages < 5) {
        *flags |= 1;
        return 0x1145;
    }
    return 0x1144;
}

s32 func_80800888_chcheato(void)
{
    s32 cheat_id = func_80800BB8_chcheato();
    func_800D3EF4(cheat_id);
    return cheat_id + 0x114A;
}

void func_808008B8_chcheato(OptionState *options, s32 index)
{
    s32 pad0;
    CheatoOptionDescriptor color_a;
    CheatoOptionDescriptor color_b;

    if (_gcnewoption_entrypoint_17((s32) options, index)) {
        color_a = D_80800F20_chcheato;
        _gcnewoption_entrypoint_13(options, index, &color_a);
        _gcnewoption_entrypoint_12(options, index, (s16) (index * 2 + 3));
    } else if (_gcnewoption_entrypoint_19(options, index)) {
        color_b = D_80800F28_chcheato;
        _gcnewoption_entrypoint_13(options, index, &color_b);
        _gcnewoption_entrypoint_12(options, index, (s16) (index * 2 + 4));
    }
}

void func_8080098C_chcheato(param_0, options) Actor *param_0;
OptionState *options;
{
    _gcnewoption_entrypoint_14(options, 0, 1, 2, 4.0f);
    _gcnewoption_entrypoint_40(options, 0x41, 0x22, 0x20, 0.8f, 1.0f);
    _gcnewoption_entrypoint_32(options, 0x37);
}

void func_80800A04_chcheato(Actor *options)
{
    s32 i;
    s32 count;
    s32 cheat_id;
    // Matching: empty block steers IDO register allocation.
    if (1) {
    }

    count = func_80800C0C_chcheato(options);
    for (i = 0; i < count; i++) {
        cheat_id = i + 1;
        if (func_800D3E14(cheat_id))
            _gcnewoption_entrypoint_21(options, i);
        else
            _gcnewoption_entrypoint_23(options, i);
        func_808008B8_chcheato(options, i);
        _gcnewoption_entrypoint_31(options, i, (s16) func_800D3FC0(cheat_id));
    }
}

int func_80800AB4_chcheato(param_0, param_1, param_2, param_3)
s32 param_0;
s32 param_1;
s32 param_2;
s32 param_3;
{
    switch (param_3) {
        case 0:
            func_80800A04_chcheato(param_1 | 0);
            break;

        case 2:
            func_80102424(param_0, 6);
    }
}

void func_80800B00_chcheato(Actor *actor)
{
    s32 menu;
    s32 unk_0;
    s32 count;

    count = func_80800C0C_chcheato();
    _gcnewoption_entrypoint_4(actor, 0, &_gcnewoption_entrypoint_16, &_gcnewoption_entrypoint_35,
                              0x1849);
    menu = func_80100094(actor, 0);
    _gcnewoption_entrypoint_8(menu, func_800F1418(5, count));
    _gcnewoption_entrypoint_9(menu, count);
    _gcnewoption_entrypoint_10(menu, 1);
    func_8080098C_chcheato(actor, menu);
    _gcnewoption_entrypoint_11(menu);
    func_80102424(actor, 5);
    func_80090708(2);
}

// Returns the first cheat (1..5) not yet given, or -1.
s32 func_80800BB8_chcheato(void)
{
    s32 i;
    s32 out;
    for (i = 1; i < 6; i++) {
        if (func_800D3DD0(i) == 0) {
            out = i;
            return out;
        }
    }
    out = -1;
    return out;
}

// Returns how many cheats have been given.
int func_80800C0C_chcheato()
{
    s32 i;
    s32 count = 0;
    for (i = 1; i < 6; i++) {
        if (func_800D3DD0(i | 0)) {
            count++;
        }
    }

    return count;
}

int func_80800C64_chcheato(actor, param_1, param_2)
Actor *actor;
s32 param_1;
s32 param_2;
{
    if (_gcdialogcamera_entrypoint_0(param_1 | 0, param_2 | 0)) {
        if ((*(s32 *) ((char *) actor + 0x6C) & 0x1FF) != 2) {
            func_80800D08_chcheato(actor, 2, 1);
        }

        return 2;
    }
    return 1;
}

void func_80800CC0_chcheato(Actor *actor)
{
    if (((*(u32 *) ((char *) actor + 0x6C)) & 0x1FF) != 0) {
        _capod_entrypoint_3(0, actor);
        *(u16 *) ((char *) actor + 0x6E) &= 0xFE00;
    }
}

void func_80800D08_chcheato(actor, param_1, param_2) u8 *actor;
s32 param_1;
s32 param_2;
{
    s32 state;

    state = (*(s32 *) ((s8 *) (actor) + (0x6C))) & 0x1FF;
    switch (state) {
        case 0:
            _capod_entrypoint_2((*(s32 *) ((s8 *) (actor) + (0))), 0x19, 0);

        case 1:
            _capod_entrypoint_8(1);
            (*(u16 *) ((s8 *) (actor) + (0x6E))) =
                (u16) (((*(u16 *) ((s8 *) (actor) + (0x6E))) & 0xFE00) | 2);
            _gcdialogcamera_entrypoint_3(&D_80800E50_chcheato,
                                         (*(s32 *) ((s8 *) (actor) + (0x38))));
            _gcdialogcamera_entrypoint_4(actor + 4);
            _gcdialogcamera_entrypoint_5(actor + 0x44);
            _gcdialogcamera_entrypoint_8();

        case 2:
            _capod_entrypoint_7(param_1, param_2);
    }
}

extern void func_80105834();
extern void func_80107C2C();
s32 D_80800E50_chcheato[4] = {0x43A00000, 0x437A0000, 0x435C0000, 0x42F00000};
u32 D_80800E60_chcheato[14] = {0x0,        0x0,        0x3F4CCCCD, 0x2200000,  0x3F4CCCCD,
                               0x2200000,  0x3F4CCCCD, 0x2200000,  0x3F4CCCCD, 0x2200000,
                               0x3F4CCCCD, 0x2200000,  0x3F4CCCCD, 0x2200000};
int D_80800E98_chcheato[18] = {0x1860135,
                               0x7870001,
                               (u32) &D_80800E60_chcheato,
                               (u32) func_80800068_chcheato,
                               (u32) func_80105834,
                               (u32) func_8080035C_chcheato,
                               0x0,
                               0x40000000,
                               0x0,
                               0x100,
                               0x0,
                               0x0,
                               0x14,
                               (u32) func_8080000C_chcheato,
                               (u32) func_80107C2C,
                               -0x7FFFFB7E,
                               (u32) func_80800204_chcheato,
                               0x0};
s32 D_80800EE0_chcheato[5] = {0x68015E, 0x11420000, 0x201, 0x12080000, 0x370000};
s16 D_80800EF4_chcheato[4] = {0xE, 0x800, 0x200, 0x0};
CheatoSoundTimes D_80800EFC_chcheato = {0.25f, 0.95f};
CheatoSoundIds D_80800F04_chcheato = {0x4C5, 0x4C6};
s16 D_80800F08_chcheato[12] = {0x21, 0xD,  0xF3,  0x10C, 0x16, 0x36B0,
                               0x1,  0xC8, 0x5DC, 0x11,  0x0,  0x0};
CheatoOptionDescriptor D_80800F20_chcheato = {0xFF, 0xFF, 0xFF};
CheatoOptionDescriptor D_80800F28_chcheato = {0xFF, 0xFF, 0x0};
