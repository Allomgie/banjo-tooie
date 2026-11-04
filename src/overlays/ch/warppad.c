#include "ch/warppad.h"

#define WARPPAD_DATA(arg0) ((WarppadActorData *) (arg0->actorData))

extern u8 D_8012762C;

extern u32 D_808012FC_chwarppad[];
extern f32 D_8080134C_chwarppad[3];
extern u8 D_80801080_chwarppad[0x20];
extern D_808010A0 D_808010A0_chwarppad[4];
extern D_808010B0 D_808010B0_chwarppad[31];
extern u32 D_80801344_chwarppad[];
extern u32 _gcnewoption_entrypoint_35;

u32 *chwarppad_entrypoint_0(void)
{
    return &D_808012FC_chwarppad;
}

void func_8080000C_chwarppad(Actor *actor, u32 arg1)
{
    OptionState *menu;

    if (func_800EB854() == 3) {
        menu = (OptionState *) func_80100094(actor, 0U);
        if (menu != NULL) {
            _gcnewoption_entrypoint_1(menu, arg1);
        }
    } else {
        func_80101870(actor, arg1);
    }
}

// Is the warp pad at this index available?
s32 func_80800064_chwarppad(Actor *actor, s32 pad_index)
{
    if ((actor->unk74_7 == (pad_index + 0x32))) {
        return 0;
    }
    return func_800DA298((WARPPAD_DATA(actor)->unk14 * 5) + pad_index + 0x3AB);
}

// Number of warp pads unlocked in the level.
s32 func_808000B4_chwarppad(Actor *actor)
{
    s32 i;
    s32 pad_count;

    pad_count = 0;
    for (i = 1; i <= WARPPAD_DATA(actor)->unk4; i++) {
        if (func_80800064_chwarppad(actor, i) != 0) {
            pad_count += 1;
        }
    }
    return pad_count;
}

void func_80800124_chwarppad(Actor *actor, OptionState *menu)
{
    s32 i;
    s32 item_index;

    item_index = 0;
    _gcnewoption_entrypoint_32(menu, 0x6F);

    for (i = 1; i <= WARPPAD_DATA(actor)->unk4; i++) {
        if (func_80800064_chwarppad(actor, i) != 0) {
            _gcnewoption_entrypoint_31(
                menu, item_index, (s16) (&D_808010B0_chwarppad[WARPPAD_DATA(actor)->unk10])[i].unk5);
            item_index += 1;
        }
    }
}

void func_808001F4_chwarppad(Actor *actor, OptionState *menu)
{
    s32 pad_index;
    u32 item_index = 0;

    for (pad_index = 1; WARPPAD_DATA(actor)->unk4 >= pad_index; pad_index++) {
        if (func_80800064_chwarppad(actor, pad_index) != 0) {
            _gcnewoption_entrypoint_12(menu, item_index, (pad_index + 9));
            if (func_80090178(D_808010B0_chwarppad[WARPPAD_DATA(actor)->unk10 + pad_index].unk8) != 0) {
                _gcnewoption_entrypoint_23(menu, item_index);
                _gcnewoption_entrypoint_13(menu, item_index, &D_80801344_chwarppad);
            }
            item_index++;
        }
    }
}

// Maps a menu item index to the pad index, or -1.
s32 func_808002F4_chwarppad(Actor *actor, s32 item_index)
{
    s32 pad_index;
    s32 item_count;

    item_count = 0;
    for (pad_index = 1; WARPPAD_DATA(actor)->unk4 >= pad_index; pad_index++) {
        if (func_80800064_chwarppad(actor, pad_index) != 0) {
            if (item_count == item_index) {
                return pad_index;
            }
            item_count += 1;
        }
    }
    return -1;
}

// Is this warp pad active?
s32 func_80800380_chwarppad(Actor *actor)
{
    return func_800DA298(WARPPAD_DATA(actor)->unk14 * 5 + actor->unk74_7 + 0x379);
}

// Enable the warp pad.
void func_808003B8_chwarppad(Actor *actor)
{
    func_800DA544(WARPPAD_DATA(actor)->unk14 * 5 + actor->unk74_7 + 0x379);
    _subaddiefade_entrypoint_4(actor);
    _chappearfx_entrypoint_1(actor, 2, 3, 0.8f);
}

// State 2: just activated, 3: option menu open, 4: warping.
void func_80800418_chwarppad(Actor *actor, u32 new_state)
{
    s32 pad_count;
    OptionState *menu;
    // Only act when the state changes.
    if (new_state != actor->unk70_10) {
        // Leave the previous state.
        switch (actor->unk70_10) {
            case 2:
                if (func_800DA298(FLAG_3EE_FTT_FIRST_WARP_AVAILABLE) == 0) {
                    // Enable movement.
                    func_80090708(0);
                }
                if (func_808000B4_chwarppad(actor) > 0) {
                    func_800DA544(FLAG_3EE_FTT_FIRST_WARP_AVAILABLE);
                }
                break;
            case 3:
                // Close the option menu.
                _gcnewoption_entrypoint_6((OptionState *) actor, 0U);
                // Enable movement.
                func_80090708(0);
                func_8010A828(actor, 2);
        }
        actor->unk70_10 = new_state;
        // Enter the new state.
        switch (new_state) {
            case 2:
                if (func_800DA298(FLAG_3EE_FTT_FIRST_WARP_AVAILABLE) == 0) {
                    // Disable movement.
                    func_80090708(1);
                    return;
                }
                func_808003B8_chwarppad(actor);
                return;
            case 3:
                // Open the option menu.
                pad_count = func_808000B4_chwarppad(actor);
                _gcnewoption_entrypoint_4(actor, 0, &_gcnewoption_entrypoint_35, 0,
                                          WARPPAD_DATA(actor)->unk14 + 0x185A);
                menu = func_80100094(actor, 0U);
                func_800C78CC(1U);
                // Show at most 4 pads at a time.
                _gcnewoption_entrypoint_8(menu, pad_count >= 5 ? 4 : pad_count);
                _gcnewoption_entrypoint_9(menu, pad_count);
                _gcnewoption_entrypoint_10(menu, 0U);
                func_80800124_chwarppad(actor, menu);
                _gcnewoption_entrypoint_14(menu, 0, 0, 0, 0.0f);
                _gcnewoption_entrypoint_40(menu, 0x41, 0x22, 0x20U, 0.8f, 1.0f);
                _gcnewoption_entrypoint_42(menu, 0.1f);
                _gcnewoption_entrypoint_11(menu);
                func_80090708(2);
                func_80800F34_chwarppad(actor, 5, 1);
                func_8010A828(actor, 0xA);
                return;
            case 4:
                // Warp to the chosen pad.
                func_800DA544(FLAG3_9FE_WARPING_VIA_WARPPAD);
                _gcgoto_entrypoint_1(
                    func_80800E10_chwarppad(
                        D_808010B0_chwarppad[WARPPAD_DATA(actor)->unk18 + WARPPAD_DATA(actor)->unk10]
                            .unk0),
                    D_808010B0_chwarppad[WARPPAD_DATA(actor)->unk18 + WARPPAD_DATA(actor)->unk10]
                        .unk4);
        }
    }
}

s16 func_808006C0_chwarppad(s32 actor)
{
    TransformationId transformation;
    u32 level_index;
    s32 i;

    level_index = D_8012762C;
    transformation = func_8008FD48();
    for (i = 0; D_808010A0_chwarppad[i].unk2 != 0; i++) {
        if ((level_index == D_808010A0_chwarppad[i].unk2) &&
            (transformation == D_808010A0_chwarppad[i].unk3)) {
            return D_808010A0_chwarppad[i].unk0;
        }
    }
    return D_808010A0_chwarppad[i].unk0;
}

void func_80800748_chwarppad(Actor *actor)
{
    s32 unlocked_count;
    s32 player;
    s32 text_id;

    func_800DA524(FLAG3_9FE_WARPING_VIA_WARPPAD);
    switch (actor->unk70_10) {
        case 1:
            // Standing near the warp pad.
            if (func_8010C9FC(actor->position, 0xFA, 0xC8, -0x32) != 0) {
                unlocked_count = func_808000B4_chwarppad(actor);
                player = func_800F54E4();
                if (func_80800380_chwarppad(actor) == 0) {
                    // Activate the warp pad.
                    func_80800418_chwarppad(actor, 2U);
                } else if ((unlocked_count > 0) &&
                           (func_800F64A4(player,
                                          *(s32 *) &(D_80801080_chwarppad -
                                                     0x220)[(WARPPAD_DATA(actor)->unk10 * 0xC) +
                                                            (actor->unk74_7 * 0xC)]) == 0) &&
                           (_subaddiedialog_entrypoint_4(actor->position, 0x64, 4) != 0)) {
                    // Open the option menu.
                    func_80800418_chwarppad(actor, 3U);
                } else if ((func_80016B30(0, 1) == 1) &&
                           (func_800F8004(player) == 0) &&
                           (func_800F4BB8(player, -1, 4) != 0)) {
                    // B pressed near the pad.
                    if (unlocked_count > 0) {
                        if (func_800F64A4(player,
                                          *(s32 *) &(D_80801080_chwarppad -
                                                     0x220)[WARPPAD_DATA(actor)->unk10 * 0xC +
                                                            actor->unk74_7 * 0xC]) != 0) {
                            text_id = func_808006C0_chwarppad((s32) actor);
                        } else {
                            text_id = 0xCF0;
                        }
                    } else {
                        text_id = 0xCEF;
                    }
                    func_80800F34_chwarppad(actor, 5, 1);
                    _subaddiedialog_entrypoint_11(actor->unk0, text_id, 0xF, NULL, 0);
                }
            }
            break;
        case 2:
            if ((func_800DA298(FLAG_3EE_FTT_FIRST_WARP_AVAILABLE) == 0) && !actor->unk74_30) {
                if (_subaddiedialog_entrypoint_11(
                        actor->unk0, func_808000B4_chwarppad(actor) == 0 ? 0xCED : 0xCEE, 0xA,
                        actor->position, 0) != 0) {
                    actor->unk74_30 = 1;
                    func_808003B8_chwarppad(actor);
                    if (func_800F64A4(func_800F54E4(), ALLOW_TREXLARGE | ALLOW_GOLDENGOLIATH) ==
                        0) {
                        func_80800F34_chwarppad(actor, 4, 1);
                    }
                }
            }
            if (_subaddiefade_entrypoint_0(actor) == 0xFF) {
                func_80800418_chwarppad(actor, 1U);
            }
            break;
        case 3:
            _gcnewoption_entrypoint_0(func_80100094(actor, 0U));
    }
    if (actor->unk64_19) {
        actor->unk64_19 = 0;
    }
}

s32 func_80800A1C_chwarppad(Actor *actor, u32 msg, s32 data)
{
    switch (msg) {
        case 0x91:
            actor->unk64_19 = 1;
        case 0x95:
            break;
        case 0x2E:
            func_80800AB8_chwarppad(actor, *(s16 *) &data, *((s16 *) &data + 1));
            break;
        case 0x20:
            func_80800B34_chwarppad(actor, (OptionState *) func_80101080(), *(s16 *) &data,
                                    *((s16 *) &data + 1));
            break;
        default:
            return 0;
    }
    return 1;
}

void func_80800AB8_chwarppad(Actor *actor, s32 arg1, s32 arg2)
{
    func_80801018_chwarppad(actor);
}

u8 func_80800ADC_chwarppad(s32 arg0)
{
    s32 transformation;
    u32 i = 0;
    transformation = func_8008FD48();
    for (i = 0; D_80801080_chwarppad[i] != 0; i += 2) {
        if (transformation == D_80801080_chwarppad[i]) {
            return D_80801080_chwarppad[i + 1];
        }
    }
    return 0;
}

void func_80800B34_chwarppad(Actor *actor, OptionState *menu, s32 item_index, s32 event)
{
    u32 pad_index;
    u32 unk_0;
    switch (event) {
        case 3:
            pad_index = func_808002F4_chwarppad(actor, item_index);
            if (_gcnewoption_entrypoint_19(menu, item_index) != 0) {
                unk_0 = func_80800ADC_chwarppad((s32) actor);
                if (unk_0 != 0) {
                    _gcnewoption_entrypoint_34(menu, unk_0);
                }
            } else {
                WARPPAD_DATA(actor)->unk18 = pad_index;
                func_80800418_chwarppad(actor, 4);
            }

            break;
        case 0:
            func_808001F4_chwarppad(actor, menu);
            break;
        case 2:
            func_800C78CC(0);
            func_80800418_chwarppad(actor, 1);
            func_80801018_chwarppad(actor);
    }
}

void func_80800C00_chwarppad(Actor *actor)
{
    s32 index;
    u32 level_index;
    s32 player;
    f32 pos[3];

    level_index = D_8012762C;
    player = func_800F54E4();
    index = 0;
    // Find the table section of the current level.
    while (D_808010B0_chwarppad[index].unk0 != -2) {
        if (D_808010B0_chwarppad[index].unk0 == -1) {
            if (level_index == D_808010B0_chwarppad[index].unk4) {
                break;
            }
            WARPPAD_DATA(actor)->unk14 += 1;
        }
        index++;
    }
    WARPPAD_DATA(actor)->unk8 = _subaddiesect_entrypoint_1(actor);
    WARPPAD_DATA(actor)->unk10 = index++;
    // Find the end of the section.
    while (D_808010B0_chwarppad[index].unk0 != -2) {
        if (D_808010B0_chwarppad[index].unk0 == -1) {
            break;
        }
        index++;
    }

    WARPPAD_DATA(actor)->unk4 = ((index - WARPPAD_DATA(actor)->unk10) - 1);
    func_80800418_chwarppad(actor, 1U);
    _subaddiefade_entrypoint_8(actor, func_80800380_chwarppad(actor) != 0 ? 0xFF : 0x87);
    if (WARPPAD_DATA(actor)->unk8 != -1U) {
        _subaddiesect_entrypoint_2(actor, WARPPAD_DATA(actor)->unk8, 1);
    }
    func_8010A828(actor, 2);
    // Arriving through this pad: place the player on it.
    if ((func_800DA298(FLAG3_9FE_WARPING_VIA_WARPPAD) != 0) &&
        (func_800EA090() ==
         (D_80801080_chwarppad - 0x224)[WARPPAD_DATA(actor)->unk10 * 0xC + actor->unk74_7 * 0xC])) {
        func_800EE7F8(pos, actor->position);
        pos[1] += 15.0f * actor->scale;
        func_800F608C(player, 1);
        func_800F8294(player, pos);
        func_800F497C(player);
        func_800C78CC(0U);
        func_800DA524(FLAG3_9FE_WARPING_VIA_WARPPAD);
    }
}

// Decodes a map id from ROM words (same as func_8080000C in ch/uffy.c).
s32 func_80800E10_chwarppad(s32 encoded)
{
    u32 word;
    u32 lo_addr;
    u32 hi_addr;

    lo_addr = (encoded & 0xFFFF) + 0xB0000000;
    hi_addr = ((encoded & 0xFFFF0000) >> 0x10);
    if (lo_addr & 2) {
        lo_addr = (lo_addr >> 2) << 2;
        rom_read_word(lo_addr, &word);
        encoded = (word & 0xFFFF0000) >> 0x10;
    } else {
        rom_read_word(lo_addr, &word);
        encoded = word & 0xFFFF;
    }

    if (hi_addr != 0) {
        hi_addr += 0xB0000000;
        if (hi_addr & 2) {
            hi_addr = (hi_addr >> 2) << 2;
            rom_read_word(hi_addr, &word);
            encoded += (word & 0xFFFF0000) >> 0x10;
        } else {
            rom_read_word(hi_addr, &word);
            encoded += word & 0xFFFF;
        }
    }
    return encoded + 0xA0;
}

void func_80800EF8_chwarppad(Actor *actor)
{
    if (func_80100094(actor, 0) != 0) {
        _gcnewoption_entrypoint_6(actor, 0);
    }
    func_80801018_chwarppad(actor);
}

void func_80800F34_chwarppad(Actor *actor, s32 arg1, s32 arg2)
{
    f32 offset[3];
    f32 *facing;

    if (!actor->unk64_20) {
        func_800EFA4C(offset, 0.0f, func_8010CD28(actor), 0.0f);
        _capod_entrypoint_2(actor->unk0, 0x1AU, 0);
        _capod_entrypoint_8(1);
        _capod_entrypoint_9(0, &D_8080134C_chwarppad);
        _capod_entrypoint_10(0, actor->position);

        if (arg1 == 4) {
            facing = offset;
        } else {
            facing = actor->rotation;
        }
        _capod_entrypoint_11(0, facing);
        _gcdialogcamera_entrypoint_8();
        actor->unk64_20 = 1;
        _subaddieDll_entrypoint_4(actor, 1);
    }
    _capod_entrypoint_7(arg1, arg2);
}

void func_80801018_chwarppad(Actor *actor)
{
    if (actor->unk64_20) {
        _capod_entrypoint_3(0);
        actor->unk64_20 = 0;
        _subaddieDll_entrypoint_4(actor, 0U);
    }
}

// TU-NOTE: the .data of this overlay is defined here in C; its tables point to functions of this
// file, and IDO's assembler schedules some of them differently unless they share the unit.
// D_808010B4_chwarppad = D_808010B0_chwarppad + 0x4 (linker symbol). The externs
// D_808012FC_chwarppad and D_80801344_chwarppad are declared as u32[] to match their objects.

extern void func_80102EC0();
extern void func_80108ED0();
extern void func_80107C2C();
u8 D_80801080_chwarppad[32] = {0x1,  0x1E, 0x13, 0x24, 0x12, 0x23, 0x11, 0x22, 0x10, 0x23, 0xF,
                               0x23, 0xE,  0x24, 0xD,  0x21, 0xC,  0x23, 0xB,  0x20, 0xA,  0x1F,
                               0x8,  0x23, 0x7,  0x23, 0x2,  0x23, 0x6,  0x23, 0x0,  0x0};
D_808010A0 D_808010A0_chwarppad[4] = {0xCF2, 0x10, 0xE,  0xD02, 0x16, 0x7,
                                      0xCF2, 0x15, 0x13, 0xCF1, 0x0,  0x0};
D_808010B0 D_808010B0_chwarppad[31] = {
    0xFFFFFFFF, 0x10, 0x0,  0x0, 0x0, 0x0,     0x99C,     0x1E, 0x97, 0x0, 0x0, 0x2000,
    0x99C,      0x1F, 0x10, 0x0, 0x0, 0x2000,  0xAE0,     0x20, 0x32, 0x0, 0x0, 0x2000,
    0x940,      0x21, 0x40, 0x0, 0x0, 0x2000,  0xC56,     0x22, 0x35, 0x0, 0x0, 0x2000,
    0xFFFFFFFF, 0xF,  0x0,  0x0, 0x0, 0x0,     0xAD4,     0x1E, 0x97, 0x0, 0x0, 0x0,
    0xAD4,      0x1F, 0x10, 0x0, 0x0, 0x0,     0x9B6,     0x20, 0x40, 0x0, 0x0, 0x1000,
    0xAD4,      0x21, 0x1,  0x0, 0x0, 0x0,     0xAD4,     0x22, 0x42, 0x0, 0x0, 0x0,
    0xFFFFFFFF, 0x12, 0x0,  0x0, 0x0, 0x0,     0x9500B74, 0x1E, 0x97, 0x0, 0x0, 0x0,
    0x9500B74,  0x1F, 0x52, 0x0, 0x0, 0x0,     0x9500B74, 0x20, 0x41, 0x0, 0x0, 0x0,
    0x9500B74,  0x21, 0x40, 0x0, 0x0, 0x0,     0x91C0CB8, 0x22, 0x10, 0x0, 0x0, 0x0,
    0xFFFFFFFF, 0x14, 0x0,  0x0, 0x0, 0x0,     0x3B6,     0x1E, 0x53, 0x0, 0x0, 0x800,
    0x3B60CC0,  0x1F, 0x63, 0x0, 0x0, 0x1400,  0x3B60CC0, 0x20, 0x64, 0x0, 0x0, 0x1400,
    0x506,      0x21, 0x56, 0x0, 0x0, 0x1400,  0x506,     0x22, 0xB4, 0x0, 0x0, 0x1400,
    0xFFFFFFFF, 0x15, 0x0,  0x0, 0x0, 0x0,     0x3DA0290, 0x1E, 0x97, 0x0, 0x0, 0x40000,
    0x3DA0CC8,  0x1F, 0x58, 0x0, 0x0, 0x40000, 0x3DA0290, 0x20, 0x10, 0x0, 0x0, 0x40000,
    0x3DA0290,  0x21, 0x40, 0x0, 0x0, 0x40000, 0x3DA0290, 0x22, 0x57, 0x0, 0x0, 0x40000,
    0xFFFFFFFF, 0x16, 0x0,  0x0, 0x0, 0x0};
static u32 D_808010B0_chwarppad_rest[54] = {
    0x9780CC0, 0x1E8F0000, 0x40, 0x9140B74, 0x1F400000, 0x40, 0xDAE0CC0,  0x20100000, 0x40,
    0xDAE0B80, 0x21040000, 0x40, 0x978,     0x220D0000, 0x40, 0xFFFFFFFF, 0x17000000, 0x0,
    0x3DA0BAA, 0x1E100000, 0x0,  0x3DA0BAA, 0x1F760000, 0x0,  0xAF6,      0x20A80000, 0x0,
    0xAF6,     0x21400000, 0x0,  0xAF60A68, 0x22A70000, 0x0,  0xFFFFFFFF, 0x18000000, 0x0,
    0x9E609DA, 0x1E970000, 0x0,  0x9E60004, 0x1F690000, 0x0,  0xFFFFFFFF, 0x19000000, 0x0,
    0x5400B98, 0x1EAB0000, 0x0,  0x5400B98, 0x1F220000, 0x0,  0xFFFFFFFE, 0x0,        0x0};
u32 D_808012FC_chwarppad[18] = {0x1C401E5,
                                0x6410001,
                                0x0,
                                (u32) func_80800748_chwarppad,
                                (u32) func_80102EC0,
                                (u32) func_8080000C_chwarppad,
                                0xFA0000,
                                0x0,
                                0x0,
                                0x40000810,
                                (u32) func_80800EF8_chwarppad,
                                (u32) func_80108ED0,
                                0x0,
                                (u32) func_80800C00_chwarppad,
                                (u32) func_80107C2C,
                                0x80002452,
                                (u32) func_80800A1C_chwarppad,
                                0x0};
u32 D_80801344_chwarppad[2] = {0xFF00FF, 0x0};
f32 D_8080134C_chwarppad[3] = {1.5e+02f, 1.5e+02f, 2e+02f};
