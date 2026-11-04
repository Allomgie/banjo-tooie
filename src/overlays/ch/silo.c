// Jamjars' warp silos on the Isle o' Hags (7 of them): opened by an egg hit or approach; stepping
// in shows a menu of the other opened silos and warps the player to the chosen one.
#include "common.h"
#include <types.h>

extern u32 D_808012EC_chsilo[][2];
extern void rom_read_word(u32, u32 *);
typedef struct SiloS {
    s32 f0;
    u8 pad[0x70];
    u32 pad74 : 1;
    u32 flag : 1;
    u32 rest : 30;
} SiloS;
extern s32 _subaddiedialog_entrypoint_11(s32, s32, s32, void *, s32);
extern void *func_800F54E4(void);
extern s32 func_800DA9E4(GameFlag, s32);
extern void func_800EF1B8(f32 *, f32, f32);
typedef struct {
    u8 pad0[0x24];
    f32 unk24;
    u8 pad28[0x44];
    u32 unk6C;
    u8 pad70[2];
    u16 unk72;
} ChSiloStruct;
extern s32 func_80090178(s32);
extern s32 func_8010CAC0(void *, s32);
extern f32 func_800D8FF8(void);
extern int D_80801384_chsilo[];
extern f32 D_808012C0_chsilo[];
extern void _subaddieDll_entrypoint_4(Actor *, s32);
extern void func_800DA544(s32);
extern void _gcnewoption_entrypoint_6(Actor *, s32);
extern void func_80090708(s32);
extern void func_8010A828(Actor *, s32);
extern void _plcamera_entrypoint_3(s32, s32);
extern void func_80102424(Actor *, s32);
extern void _subaddieaudioquick_entrypoint_2(Actor *, f32 *, f32 *);
extern void func_800F82D4(s32, s32);
extern void func_8008FE68(f32 *);
extern void _gcnewoption_entrypoint_35();
extern void _gcnewoption_entrypoint_4(Actor *, s32, void *, s32, s32);
extern void *func_80100094(Actor *, s32);
extern void _gcnewoption_entrypoint_8(void *, s32);
extern void _gcnewoption_entrypoint_9(void *, s32);
extern void _gcnewoption_entrypoint_10(void *, s32);
extern void _gcnewoption_entrypoint_14(void *, s32, s32, s32, f32);
extern void _gcnewoption_entrypoint_40(void *, s32, s32, s32, f32, f32);
extern void _gcnewoption_entrypoint_42(void *, f32);
extern void _gcnewoption_entrypoint_11(void *);
extern void func_800C964C(s32);
extern void func_800EE7F8(f32 *, f32 *);
extern void func_800907C0(f32 *);
typedef struct {
    s16 unk0;
    s16 pad2;
    s32 unk4;
} SiloGoto;
extern f32 D_808012E0_chsilo[];
extern f32 D_808012D0_chsilo[];
extern SiloGoto D_808012E8_chsilo[];
extern void func_8008FB58(f32 *, f32, f32);
extern s32 func_80101DDC(Actor *);
extern s32 func_8010CB0C(f32 *, s32, s32, s32);
extern s32 func_8008FA2C(s32, s32);
extern void _subaddieaudioloop_entrypoint_4(Actor *, f32 *, s32, f32 *);
extern void _gcnewoption_entrypoint_0(void *);
extern void func_800A7AD4(s32, s32);
extern void _gcgoto_entrypoint_1(s32, s32);
extern s32 func_80101E14(Actor *, f32);
extern void func_800904C8(s32);

// Returns the destination map id for a silo, read from ROM halfwords.
s32 func_80800000_chsilo(s32 silo_index)
{
    u32 value;
    u32 rom_word;
    u32 addr;
    u32 addr2;
    u32 half;

    value = D_808012EC_chsilo[silo_index][0];
    addr = (value & 0xFFFF) + 0xB0000000;
    addr2 = (value & 0xFFFF0000) >> 16;
    value = 0;
    if (addr & 2) {
        rom_read_word((addr >> 2) << 2, &rom_word);
        half = (rom_word & 0xFFFF0000) >> 16;
        value += half;
    } else {
        rom_read_word(addr, &rom_word);
        half = rom_word & 0xFFFF;
        value += half;
    }
    if (addr2) {
        addr2 += 0xB0000000;
        if (addr2 & 2) {
            addr2 = (addr2 >> 2) << 2;
            rom_read_word(addr2, &rom_word);
            value += (rom_word & 0xFFFF0000) >> 16;
        } else {
            rom_read_word(addr2, &rom_word);
            value += rom_word & 0xFFFF;
        }
    }
    return value + 0xA0;
}

void func_80800104_chsilo(SiloS *silo, s32 text_id, s32 flags)
{
    if (!silo->flag) {
        flags |= 6;
        _subaddiedialog_entrypoint_11(silo->f0, text_id, flags, (u8 *) silo + 4, 0x6F);
        silo->flag = 1;
    }
}

// True if the silo is opened and is not the current one.
s32 func_8080015C_chsilo(u8 *actor, s32 silo_index)
{
    if (silo_index == (*(s32 *) ((s8 *) actor + 0x6C) & 0x1FF)) {
        return 0;
    }
    if (func_800DA298(silo_index + 0x32C) == 0) {
        return 0;
    }
    return 1;
}

// Counts the opened silos other than the current one.
s32 func_808001A8_chsilo(s32 actor)
{
    s32 i;
    s32 count;
    count = (count = 0); // Matching: odd double assignment needed for the match.
    for (i = 1, count; i < 8; i++) {
        if (func_8080015C_chsilo(actor, i)) {
            count++;
        }
    }

    return count;
}

int func_80800210_chsilo(s32 actor, s32 menu)
{
    _gcnewoption_entrypoint_32(menu | 0, 0x6F);
}

void func_80800238_chsilo(s32 actor, s32 menu)
{
    s32 silo_index;
    s32 option_index;
    option_index = 0;
    silo_index = 1;
    do {
        if (func_8080015C_chsilo(actor, silo_index) != 0) {
            _gcnewoption_entrypoint_12(menu, option_index, (s16) (silo_index + 9));
            _gcnewoption_entrypoint_31(menu, option_index,
                                       *(s16 *) ((char *) &D_808012EC_chsilo + (silo_index * 8) - 2));
            option_index += 1;
        }
        silo_index += 1;
    } while (silo_index != 8);
}

void func_808002E8_chsilo(void *actor, s32 choice)
{
    s32 silo_index;
    s32 option_index;
    option_index = 0;
    silo_index = 1;
    while (1) {
        if (func_8080015C_chsilo(actor, silo_index) != 0) {
            if (!silo_index && 1) { // Matching: empty block needed for the match.
            }
            if (option_index == choice) {
                ((f32 *) actor)[0x16] = (f32) silo_index;
                return;
            }
            option_index += 1;
        }
        silo_index += 1;
        if (silo_index == 8) {
            return;
        }
    }
}

s32 func_80800378_chsilo(s32 actor)
{
    func_800903D0(actor + 0x18);
}

void func_80800398_chsilo(Actor *actor, s32 enable)
{
    if (enable) {
        if (!actor->unk74_29) {
            func_800F4CEC(func_800F54E4(), 0x33);
            actor->unk74_29 = 1;
        }
    } else {
        if (actor->unk74_29) {
            func_800F4CC0(func_800F54E4());
            actor->unk74_29 = 0;
        }
    }
}

int func_80800420_chsilo(Actor *actor, s32 enable)
{
    if (enable) {
        if (!actor->unk64_19) {
            if (func_800F7B9C(func_800F54E4(), 0x8B) != 2) {
                return 0;
            }
            actor->unk64_19 = 1;
        }
    } else if (actor->unk64_19) {
        func_800F7B9C(func_800F54E4(), 0x90);
        actor->unk64_19 = 0;
    }
    return 1;
}

// Enters a new state: runs exit code for the old state, then entry code for the new one.
s32 func_808004C0_chsilo(actor, state)
Actor *actor;
s32 state;
{
    s32 player;
    s32 open_count;
    void *menu;

    switch (actor->unk70_10) {
        case 1:
            _subaddieDll_entrypoint_4(actor, 1);
            break;
        case 2:
            func_800DA544(actor->unk6C_0 + 0x32C);
            actor->unk64_20 = 1;
            ((f32 *) actor->actorData)[3] = 5.0f;
            break;
        case 6:
            ((f32 *) actor->actorData)[3] = 0.5f;
            break;
        case 5:
            _gcnewoption_entrypoint_6(actor, 0);
            func_80090708(0);
            func_8010A828(actor, 2);
            break;
        case 8:
            func_80800420_chsilo(actor, 0);
            break;
        case 11:
            _plcamera_entrypoint_3(func_800F54E4(), 1);
    }
    func_80102424(actor, state);
    switch (actor->unk70_10) {
        case 1:
            _subaddieDll_entrypoint_4(actor, 0);
            break;
        case 2:
            _subaddieaudioquick_entrypoint_2(actor, actor->position, D_808012C0_chsilo);
            break;
        case 6:
            _subaddieaudioquick_entrypoint_2(actor, actor->position, D_808012C0_chsilo);
            break;
        case 4:
            player = func_800F54E4();
            func_800F82D4(player, 1);
            _plcamera_entrypoint_3(player, 0);
            func_80800398_chsilo(actor, 1);
            func_8008FE68((f32 *) &actor->actorData[4]);
            break;
        case 5:
            open_count = func_808001A8_chsilo(actor);
            _gcnewoption_entrypoint_4(actor, 0, _gcnewoption_entrypoint_35, 0, 0x184F);
            menu = func_80100094(actor, 0);
            _gcnewoption_entrypoint_8(menu, (open_count > 5) ? 5 : open_count);
            _gcnewoption_entrypoint_9(menu, open_count);
            _gcnewoption_entrypoint_10(menu, 0);
            func_80800210_chsilo(actor, menu);
            _gcnewoption_entrypoint_14(menu, 0, 1, 3, 4.0f);
            _gcnewoption_entrypoint_40(menu, 0x41, 0x22, 0x20, 0.8f, 1.0f);
            _gcnewoption_entrypoint_42(menu, 0.1f);
            _gcnewoption_entrypoint_11(menu);
            func_8010A828(actor, 10);
            break;
        case 10:
            func_80090708(2);
            _subaddieaudioquick_entrypoint_2(actor, actor->position, D_808012C0_chsilo);
            break;
        case 8:
            func_800C964C(0x10);
            func_80800420_chsilo(actor, 1);
            func_80800398_chsilo(actor, 1);
            func_800EE7F8((f32 *) &actor->actorData[4], actor->position);
            ((f32 *) actor->actorData)[5] -= 150.0f;
            func_800907C0((f32 *) &actor->actorData[4]);
            _subaddieaudioquick_entrypoint_2(actor, actor->position, D_808012C0_chsilo);
            break;
        case 11:
            func_80800398_chsilo(actor, 1);
            func_80800420_chsilo(actor, 1);
            func_800EE7F8((f32 *) &actor->actorData[4], actor->position);
            ((f32 *) actor->actorData)[5] -= 150.0f;
            func_800907C0((f32 *) &actor->actorData[4]);
            break;
        case 9:
            func_80800398_chsilo(actor, 0);
            ((f32 *) actor->actorData)[5] = actor->position[1] - 25.0f;
            func_800907C0((f32 *) &actor->actorData[4]);
            func_80800378_chsilo(actor);
    }
    return 1;
}

void func_8080087C_chsilo(Actor *actor)
{
    s32 cube;

    cube = _gccubesearch_entrypoint_1(0x309, actor->position);
    actor->unk6C_0 = actor->unk74_7 - 0x32;
    actor->scale = 1.0f;
    if (cube == 0) {
        func_800EE7F8(actor->actorData, actor->position);
        func_800EF1B8((f32 *) actor->actorData, *(f32 *) ((u8 *) actor + 0x48) - 90.0f, 200.0f);
    } else
        _gspropctrl_entrypoint_11(cube, actor->actorData);
    func_8010A828(actor, 2);
    if (func_800DA298(actor->unk6C_0 + 0x32C)) {
        actor->unk64_20 = 1;
        if (func_800DA9E4(0x6BF, 0)) {
            if (func_8010CB0C(actor->position, (s32) (actor->scale * 55.0f),
                              (s32) (actor->scale * 500.0f), (s32) (actor->scale * -50.0f))) {
                func_808004C0_chsilo(actor, 8);
                return;
            }
        }
        func_808004C0_chsilo(actor, 1);
        return;
    }
    func_808004C0_chsilo(actor, 1);
}

s32 func_808009E8_chsilo(s32 actor)
{
    if (func_80100094(actor, 0) != 0) {
        _gcnewoption_entrypoint_6(actor, 0);
    }
    if (((u32) *(u16 *) (actor + 0x72) >> 0xA) == 0xA) {
        func_80800398_chsilo(actor, 0);
    }
}

void func_80800A40_chsilo(volatile ChSiloStruct *actor)
{
    s32 unk_0;
    unk_0 = func_80090178(1);
    if ((func_8010CAC0((char *) actor + 4, 0x1F4) != 0) && (unk_0 != 0) &&
        (*(f32 *) ((char *) actor + 36) <= 0.0f)) {
        switch ((u32) actor->unk72 >> 10) {
            case 2:
            case 3:
            case 7:
                break;
            default:
                if (func_800DA9E4(0x334, 1) == 0) {
                    func_80800104_chsilo((struct SiloS *) actor, 0xDA6, 8);
                }
                if (*(s32 *) ((char *) actor + 108) & 0x1FF) {
                    func_808004C0_chsilo(actor, 2);
                }
        }
    } else if ((*(f32 *) ((char *) actor + 36) <= 0.0f) || (unk_0 == 0)) {
        switch ((u32) actor->unk72 >> 10) {
            case 1:
            case 6:
                break;
            default:
                func_808004C0_chsilo(actor, 6);
        }
    } else {
        *(f32 *) ((char *) actor + 36) = *(f32 *) ((char *) actor + 36) - func_800D8FF8();
    }
}

// Per-frame update, driven by the state machine below.
void func_80800B80_chsilo(Actor *actor)
{
    f32 delta;

    delta = func_800D8FF8();
    if (actor->unk6C_0 == 0) {
        return;
    }
    switch (actor->unk70_10) {
        case 1:
            func_8008FB58(actor->position, actor->scale * 30.0f, actor->scale * 60.0f);
            func_80800A40_chsilo(actor);
            break;
        case 2:
            func_8008FB58(actor->position, actor->scale * 30.0f, actor->scale * 60.0f);
            if (func_80101DDC(actor)) {
                func_808004C0_chsilo(actor, 3);
            }
            break;
        case 3:
            if (func_8010CB0C(actor->position, actor->scale * 55.0f, actor->scale * 45.0f,
                              actor->scale * -50.0f) &&
                func_8008FA2C(1, 0)) {
                if (func_808001A8_chsilo(actor) > 0) {
                    if (func_80800420_chsilo(actor, 1)) {
                        func_808004C0_chsilo(actor, 4);
                    }
                } else {
                    func_80800104_chsilo(actor, 0xDA8, 0);
                    func_80800378_chsilo(actor);
                    func_808004C0_chsilo(actor, 7);
                }
            } else {
                func_80800A40_chsilo(actor);
            }
            break;
        case 4:
            ((f32 *) actor->actorData)[4] +=
                (actor->position[0] - ((f32 *) actor->actorData)[4]) * 0.2f;
            ((f32 *) actor->actorData)[6] +=
                (actor->position[2] - ((f32 *) actor->actorData)[6]) * 0.2f;
            if (((f32 *) actor->actorData)[5] < actor->position[1] - 150.0f) {
                _subaddieaudioquick_entrypoint_2(actor, actor->position, D_808012E0_chsilo);
                func_808004C0_chsilo(actor, 5);
            } else {
                ((f32 *) actor->actorData)[5] -= 300.0f * delta;
                func_800907C0((f32 *) &actor->actorData[4]);
                _subaddieaudioloop_entrypoint_4(actor, actor->position, 1, D_808012D0_chsilo);
            }
            break;
        case 5:
            _gcnewoption_entrypoint_0(func_80100094(actor, 0));
            break;
        case 11:
            if (actor->position[1] < ((f32 *) actor->actorData)[5]) {
                func_80800398_chsilo(actor, 0);
                func_80800420_chsilo(actor, 0);
                _subaddieaudioquick_entrypoint_2(actor, actor->position, D_808012E0_chsilo);
                func_80800378_chsilo(actor);
                func_808004C0_chsilo(actor, 7);
            } else {
                ((f32 *) actor->actorData)[5] += 300.0f * delta;
                func_800907C0((f32 *) &actor->actorData[4]);
                _subaddieaudioloop_entrypoint_4(actor, actor->position, 1, D_808012D0_chsilo);
            }
            break;
        case 10:
            if (func_80101DDC(actor)) {
                func_800DA544(0x6BF);
                func_800A7AD4(1, 0x11);
                _gcgoto_entrypoint_1(func_80800000_chsilo((s32) actor->unk58 - 1),
                                     D_808012E8_chsilo[(s32) actor->unk58].unk0);
            }
            break;
        case 6:
            func_8008FB58(actor->position, actor->scale * 30.0f, actor->scale * 60.0f);
            func_80800A40_chsilo(actor);
            if (func_80101DDC(actor)) {
                func_808004C0_chsilo(actor, 1);
            }
            break;
        case 8:
            if (func_80101E14(actor, 0.4f)) {
                func_808004C0_chsilo(actor, 9);
            }
            break;
        case 9:
            if (!func_8010CAC0(actor->position, actor->scale * 150.0f)) {
                func_808004C0_chsilo(actor, 3);
            }
            break;
        case 7:
            if (!func_8010CB0C(actor->position, actor->scale * 55.0f, actor->scale * 500.0f,
                               actor->scale * -50.0f)) {
                func_808004C0_chsilo(actor, 3);
            }
    }
    if (func_80090178(0x10000) && func_8010CAC0(actor->position, actor->scale * 60.0f)) {
        func_800904C8(0x1F);
    }
}

// Actor message handler.
s32 func_80801080_chsilo(Actor *actor, s32 message, s32 data)
{
    s32 unk_0;
    switch (message) {
        case 0x40:
            if (actor->unk6C_0)
                func_808004C0_chsilo(actor, 2);
            break;
        case 0x1F:
            func_801015D0(actor);
            if (actor->unk64_20)
                func_800DF744(3, 2);
            else
                func_800DF744(3, 1);
            return 1;
        case 0x95:
            func_8080087C_chsilo(actor);
            return 1;
        case 0x20:
            unk_0 = func_80101080();
            switch (((s16 *) &data)[1]) {
                case 3:
                    func_808002E8_chsilo(actor, *(s16 *) &data);
                    func_808004C0_chsilo(actor, 10);
                    return 1;
                case 0:
                    func_80800238_chsilo(actor, unk_0);
                    return 1;
                case 2:
                    func_808004C0_chsilo(actor, 11);
            }
            break;
        case 0x2E:
            *((u8 *) actor + 0x74) &= ~0x40;
            break;
        default:
            return 0;
    }
    return 1;
}

void func_808011C8_chsilo(s32 actor, s32 unk_1)
{
    s32 menu;

    if (func_800EB854() == 3) {
        menu = func_80100094(actor, 0);
        if (menu != 0) {
            _gcnewoption_entrypoint_1(menu, unk_1);
        }
    } else {
        func_801018A4(actor, unk_1);
    }
}

int chsilo_entrypoint_0()
{
    return (int) &D_80801384_chsilo;
}

// TU-NOTE: the overlay .data is defined here in C; its tables point to functions of this file, and IDO schedules them differently otherwise.
extern void func_80105834();
extern void func_80108ED0();
extern void func_80107C2C();
f32 D_808012C0_chsilo[4] = {1.746707e-39f, 9.18641e-40f, 2.059617e-39f, 0.0f};
f32 D_808012D0_chsilo[4] = {1.746927e-39f, 1.286037e-39f, 2.571401e-38f, 0.0f};
f32 D_808012E0_chsilo[2] = {1.746588e-39f, 2.048407e-39f};
SiloGoto D_808012E8_chsilo[7] = {0x0, 0x0,  0x61A0CC0, 0x4, 0xAE, 0x5400B74, 0x6, 0x97, 0x5400290,
                                 0x5, 0x9B, 0x6E40A68, 0x5, 0x40, 0x5400C68, 0x7, 0x10, 0x5400CC8,
                                 0x4, 0x65, 0x5400004};
static u32 D_808012E8_chsilo_rest[1] = {0x40022};
u32 D_80801324_chsilo[24] = {0x0,        0x0,       0x0,        0x4AA0044, 0x3FD9999A, 0x4AA000A,
                             0x3FD9999A, 0x4AA0084, 0x3FD9999A, 0x4AA0084, 0x3FD9999A, 0x4AA0084,
                             0x3FCCCCCD, 0x4AA0012, 0x3FD9999A, 0x4AA0084, 0x3FD9999A, 0x4AA000A,
                             0x3FD9999A, 0x4AA000A, 0x3FCCCCCD, 0x4AA0012, 0x3FD9999A, 0x4AA0084};
int D_80801384_chsilo[19] = {0xB9019D,
                             0x9170001,
                             (u32) &D_80801324_chsilo,
                             (u32) func_80800B80_chsilo,
                             (u32) func_80105834,
                             (u32) func_808011C8_chsilo,
                             0x5DC0000,
                             0x0,
                             0x0,
                             0xA0864,
                             (u32) func_808009E8_chsilo,
                             (u32) func_80108ED0,
                             0x0,
                             0x0,
                             (u32) func_80107C2C,
                             -0x7FFFDFFE,
                             (u32) func_80801080_chsilo,
                             0x0,
                             0x0};
