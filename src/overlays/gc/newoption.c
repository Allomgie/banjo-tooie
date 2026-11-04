// Generic option/choice menu built from zoomboxes: title box, up to 5 visible items over a list
// of up to 30, wrap-around selection, open/close animations and callbacks. Used by many menus.
#include "gc/newoption.h"

extern s16 _gczoombox_entrypoint_29();
extern void _gczoombox_entrypoint_28();
typedef struct {
    s16 local_0;
    s16 local_1;
    u8 pad_0[0x10];
    f32 local_2;
    u8 pad_1[8];
    s32 local_3;
    u8 pad_2[0x10];
    s16 local_4;
    u8 pad_3[6];
    s32 local_5[5];
    u8 pad_4[0x30];
    f32 local_6[5];
    u8 pad_5[0x1C2];
    s16 local_7;
} NewOptionDrawState;
extern void func_80100074();
extern s32 func_80100094();
typedef struct {
    s16 local_0;
    u8 pad_0[0xA];
    s16 local_1;
    u8 pad_1[0xA];
    f32 local_2;
    u32 pad_2 : 3;
    u32 local_3 : 1;
    u32 local_4 : 1;
    u32 pad_3 : 3;
    u32 local_5 : 1;
    u32 local_6 : 1;
    u32 local_7 : 1;
    u32 local_8 : 1;
    u32 local_9 : 1;
    u32 local_10 : 1;
    u32 local_11 : 1;
    u32 pad_4 : 17;
    u8 pad_5[0x90];
    s16 local_12[30];
    s16 local_13[30];
    s16 local_14[30][3];
    s16 local_15[30];
    u8 local_16[30];
    s16 local_17;
    s16 local_18;
    u8 pad_6[2];
    s32 local_19;
    s16 local_20;
    u8 pad_7[2];
    s32 local_21;
    s32 local_22;
    s32 local_23;
    u8 local_24;
} NewOptionInitState;
typedef struct OptionBoxes {
    s16 pad_0;
    s16 count;
    u8 pad_1[0x1C];
    void *title;
    u8 title_state;
    u8 pad_2[0x17];
    void *items[22];
    s8 states[22];
} OptionBoxes;
extern void _gczoomboxdata_entrypoint_0(s32);
typedef struct {
    s16 local_0;
    s16 local_1;
    s16 local_2;
    s16 local_3;
    s16 local_4;
    s16 local_5;
} OptionScrollState;
typedef struct {
    u8 local_0 : 1;
    u8 pad_0 : 7;
} CodexOptionVisibility;
extern u16 _gczoomboxdata_entrypoint_5(s32);
extern s32 _gczoombox_entrypoint_32(void *);
extern void *_gldbstring_entrypoint_1(void *, s16);
extern s32 _gczoombox_entrypoint_8(void *, void *);
typedef struct {
    u8 unused[0x1D];
    u8 reserved : 5;
    u8 changed : 1;
    u8 low : 2;
} OptionChangeFlags;
typedef struct {
    s16 local_0[7];
    u8 pad_0[0xE];
    u32 pad_1 : 9;
    u32 local_1 : 1;
    u32 pad_2 : 2;
    u32 local_2 : 1;
    u32 pad_3 : 19;
    void *local_3;
    u8 local_4;
    u8 pad_4[0x17];
    void *local_5[5];
    u8 pad_5[0x1C8];
    u8 local_6[30];
} NewOptionUpdateState;
extern void _gczoombox_entrypoint_4(void *);
typedef struct {
    s16 local_0[4];
    u8 pad_0[0x34];
    void *local_1[5];
    u8 pad_1[0x44];
    s8 local_2[5];
} NewOptionBoxes;
typedef struct NewOptionContentState {
    u8 pad_0[0xC];
    s16 local_0;
    u8 pad_1[0x2E];
    void *local_1[5];
    s16 local_2[5];
    s16 local_3[5][3];
    u8 local_4[5];
    u8 pad_2[0x6F];
    s16 local_5[30];
    s16 local_6[30][3];
    s16 local_7[30];
    u8 local_8[30];
    u8 pad_3[6];
    void *local_9;
} NewOptionContentState;
typedef struct {
    u8 pad_0[0x1D];
    u8 pad_4 : 5;
    u8 local_0 : 1;
    u8 pad_5 : 2;
    u8 pad_1[2];
    void *local_1;
    u8 pad_2[2];
    s16 local_2;
    s16 local_3;
    s16 local_4;
    f32 local_5;
    f32 local_6;
    u8 pad_3[0x208];
    void *local_7;
} NewOptionScroll27;
extern f32 func_800D8FF8(void);
extern void _gczoombox_entrypoint_41(void *, f32);
typedef struct NewOptionMainState {
    s16 local_s;
    s16 count;
    s16 pad_a;
    s16 idx;
    s16 pad_b[4];
    f32 local_1;
    u8 pad_1[8];
    u32 local_2 : 1;
    u32 local_3 : 1;
    u32 local_4 : 1;
    u32 pad_2 : 1;
    u32 local_5 : 1;
    u32 local_6 : 3;
    u32 pad_3 : 24;
    void *local_7;
    u8 local_8;
    u8 pad_4[0x17];
    void *local_9[5];
    u8 pad_5[0x60];
    s16 local_10[30];
    u8 pad_6[0x158];
    void (*local_11)(s32, void *, s32, s32);
    void (*local_12)(void);
    s32 local_13;
    s8 local_14;
} NewOptionMainState;
extern void func_80015E80(s32, s32 *);
extern void func_80016068(s32, f32 *);
extern f32 mlAbsF(f32);
extern void *_gczoombox_entrypoint_5(s32, s32, s32, s32, s32);
extern void _gczoombox_entrypoint_42(void *, f32);
extern void _gczoombox_entrypoint_20(void *, f32, s32, s32, f32, s32, s32);
typedef struct {
    u8 pad_0[0x1C];
    u32 pad_1 : 3;
    u32 local_0 : 1;
    u32 pad_2 : 6;
    u32 local_1 : 1;
    u32 local_2 : 1;
    u32 pad_3 : 2;
    u32 local_3 : 1;
    u32 pad_4 : 17;
} OptionFlags211;
extern void _gczoombox_entrypoint_26(void *, s32, f32, f32, s32);
typedef struct {
    s16 state;
    s16 count;
    u8 pad_0[0x10];
    f32 spacing;
    u8 pad_1[4];
    u32 flags;
    void *title;
    u8 title_state;
    u8 pad_2;
    s16 title_text;
    u8 pad_3[0x14];
    void *items[5];
    s16 selected_text[5];
    s16 colors[5][3];
    u8 item_states[5];
    u8 pad_4[3];
    f32 item_y[5];
    u8 item_changed[5];
    u8 pad_5[0x143];
    s16 texts[5];
    u8 pad_6[0x50];
    s16 title_font;
    s16 wrap;
    u8 pad_7[2];
    void *strings;
    u8 pad_8[0x14];
    s16 font;
    s16 y;
    f32 speed;
    f32 duration;
} OptionCreate211;
typedef struct {
    u8 pad_0[0x1D];
    u8 pad_1 : 5;
    u8 local_0 : 1;
    u8 pad_2 : 2;
} OptionTitleFlags211;
typedef struct {
    u8 pad_0[0x1D];
    u8 pad_1 : 2;
    u8 local_0 : 1;
    u8 pad_2 : 5;
} OptionClosingFlag;
typedef struct {
    u8 pad_0[0x1C];
    u32 local_0 : 1;
    u32 pad_1 : 31;
} NewOptionMovingFlag1081;
typedef struct {
    s16 local_0;
    s16 local_1;
    u8 pad_0[0x1C];
    void *local_2;
    u8 local_3;
    u8 pad_1[0x17];
    void *local_4[5];
    u8 pad_2[0x44];
    s8 local_5[5];
} NewOptionTransitionState;
typedef struct {
    s16 pad_0;
    s16 count;
    s16 pad_1;
    s16 selected;
    u8 pad_2[0x34];
    void *boxes[5];
    s16 indices[34];
    s8 states[1];
} OptionBoxes29;
typedef struct {
    u8 pad_0[0x1C];
    u32 pad_1 : 10;
    u32 local_1 : 1;
    u32 local_2 : 1;
    u32 pad_2 : 1;
    u32 local_0 : 1;
    u32 pad_3 : 18;
    void *title;
    u8 pad_4[2];
    s16 title_text;
    u8 pad_5[0x214];
    void *strings;
} OptionTitleControl;
void gcnewoption_entrypoint_5();
void func_8080103C_gcnewoption();
void func_808027DC_gcnewoption();
void func_80800D28_gcnewoption();
void func_80801B5C_gcnewoption();
s32 func_808020C4_gcnewoption();
s32 func_808022E0_gcnewoption();
s32 func_8080241C_gcnewoption();
s32 func_80802674_gcnewoption();

s32 func_80801114_gcnewoption(s16 *param_0);
int func_80801190_gcnewoption(OptionState *param_0);
union U;
void gcnewoption_entrypoint_31();
void func_808019D0_gcnewoption(NewOptionUpdateState *param_0);
s32 func_80801E68_gcnewoption(u8 *param_0);
int func_80802534_gcnewoption(NewOptionBoxes *param_0);
void func_80802998_gcnewoption(NewOptionScroll27 *param_0);
void func_80802A9C_gcnewoption(void *param_0);
void func_80802B24_gcnewoption(u8 *param_0, s32 param_1);
void gcnewoption_entrypoint_40(u8 *param_0, s32 param_1, s32 param_2, s32 param_3, f32 param_4,
                               f32 param_5);
void gcnewoption_entrypoint_42(OptionState *param_0, f32 param_1);

// Returns the box index `delta` entries after the first box, wrapped around the item count.
s32 func_80800000_gcnewoption(u8 *menu, s32 delta)
{
    s16 count;
    s32 index;
    count = *(s16 *) ((s8 *) menu + 2);
    index = *(s16 *) ((s8 *) menu + 0xA) + delta;
    if (index >= count) {
        index = index - count;
    } else if (index < 0) {
        // Matching: the mask is needed for the match.
        index = (index & 0xFFFFFFFF) + count;
    }
    return index;
}

// Returns the visible slot of an item, or -1 when it is not visible.
func_80800038_gcnewoption(s16 *menu, s32 item)
{
    s32 slot;
    slot = item - menu[4];
    if (slot >= menu[1]) {
        return -1;
    }
    if (slot < 0) {
        return -1;
    }
    return slot;
}

// Returns the item index shown in a visible slot.
s32 func_80800070_gcnewoption(s32 *menu, s32 slot)
{
    return *(s16 volatile *) (menu + 2) + slot;
}

// Per-frame update; steps the menu state machine.
void gcnewoption_entrypoint_0(NewOptionMainState *menu)
{
    u8 prev_title_state;
    s32 i;
    s32 box;
    s32 buttons[6]; // func_80015E80 fills 6 words
    f32 stick[2];
    s32 pad_c[2]; // frame padding (unused locals)

    menu->local_2 = 0;
    if (menu->local_7 != NULL) {
        prev_title_state = menu->local_8;
    }
    switch (menu->local_s) {
        case 0:
            break;
        case 1:
            func_80800D28_gcnewoption(menu);
            menu->local_11(menu->local_13, menu, menu->idx, 0);
            menu->local_s = 2;
            break;
        case 2:
            menu->local_s = 3;
            break;
        case 3:
            if (func_80801E68_gcnewoption(menu)) {
                if ((s32) menu->local_6 == 3) {
                    menu->local_s = 4;
                } else {
                    menu->local_s = 5;
                    menu->local_11(menu->local_13, menu, menu->idx, 8);
                    menu->local_11(menu->local_13, menu, menu->idx, 10);
                }
            }
            func_808019D0_gcnewoption(menu);
            break;
        case 4:
            for (i = 0; i < menu->count; i++) {
                box = func_80800000_gcnewoption(menu, i);
                func_808027DC_gcnewoption(menu, i);
                _gczoombox_entrypoint_4(menu->local_9[box]);
            }
            func_80801B5C_gcnewoption(menu);
            if (menu->local_7 != NULL) {
                _gczoombox_entrypoint_4(menu->local_7);
            }
            func_80802998_gcnewoption(menu);
            break;
        case 5:
            func_808019D0_gcnewoption(menu);
            func_80802998_gcnewoption(menu);
            if (menu->local_1 <= 0.0f && menu->local_14 >= 0) {
                // Matching: `^ 0` on the controller index is needed for the match.
                func_80015E80(menu->local_14 ^ 0, buttons);
                if (buttons[1] == 1) {
                    if (menu->local_6 == 2) {
                        if (menu->local_11 != NULL) {
                            menu->local_11(menu->local_13, menu, menu->idx, 5);
                        }
                    } else {
                        menu->local_4 = 1;
                        func_80802A9C_gcnewoption(menu);
                        menu->local_s = 6;
                    }
                } else if (buttons[0] == 1) {
                    switch ((s32) menu->local_6) {
                        case 0:
                            if (menu->local_10[menu->idx] == -1) {
                                if (menu->local_11 != NULL) {
                                    menu->local_11(menu->local_13, menu, menu->idx, 3);
                                    return;
                                }
                            } else {
                                func_80802A9C_gcnewoption(menu);
                                menu->local_s = 6;
                            }
                            break;
                        case 1:
                            if (menu->local_11 != NULL) {
                                menu->local_11(menu->local_13, menu, menu->idx, 1);
                            }
                            break;
                        case 2:
                            if (menu->local_11 != NULL) {
                                menu->local_11(menu->local_13, menu, menu->idx, 4);
                            }
                    }
                    menu->local_1 = 0.6f;
                }
                if (menu->local_s != 5) {
                    break;
                }
                // Matching: same `^ 0` trick as above.
                if (!menu->local_2 && !menu->local_5 && (menu->local_14 ^ 0) >= 0) {
                    func_80016068(menu->local_14 ^ 0, stick);
                    if (0.8f < stick[1]) {
                        if (func_80801114_gcnewoption(menu)) {
                            menu->local_1 = 0.2f;
                        }
                    } else if (stick[1] < -0.8f) {
                        if (func_80801190_gcnewoption(menu)) {
                            menu->local_1 = 0.2f;
                        }
                    }
                }
                if (menu->local_6 == 2 && menu->local_5) {
                    func_80016068(menu->local_14, stick);
                    if (menu->local_3) {
                        if (mlAbsF(stick[0]) < 0.8f) {
                            menu->local_3 = 0;
                        }
                    } else if (0.8f < stick[0]) {
                        if (menu->local_11 != NULL) {
                            menu->local_11(menu->local_13, menu, menu->idx, 7);
                        }
                        menu->local_3 = 1;
                    } else if (stick[0] < -0.8f) {
                        if (menu->local_11 != NULL) {
                            menu->local_11(menu->local_13, menu, menu->idx, 6);
                        }
                        menu->local_3 = 1;
                    }
                }
            } else if (0.0f < menu->local_1) {
                menu->local_1 -= func_800D8FF8();
            }
            break;
        case 6:
            func_808019D0_gcnewoption(menu);
            if (func_808020C4_gcnewoption(menu)) {
                menu->local_s = 11;
            }
            break;
        case 7:
            func_808019D0_gcnewoption(menu);
            if (func_808022E0_gcnewoption(menu)) {
                func_80802A9C_gcnewoption(menu);
                menu->local_s = 8;
            }
            break;
        case 8:
            func_808019D0_gcnewoption(menu);
            if (func_80802674_gcnewoption(menu)) {
                menu->local_s = 11;
            }
            break;
        case 11:
            func_8080103C_gcnewoption(menu);
            menu->local_s = 12;
            break;
        case 12:
            menu->local_s = 13;
            if (menu->local_11 != NULL) {
                if (menu->local_4) {
                    menu->local_11(menu->local_13, menu, menu->idx, 2);
                    return;
                }
                menu->local_11(menu->local_13, menu, menu->idx, 3);
                return;
            }
            break;
        case 13:
            break;
        case 9:
            func_808019D0_gcnewoption(menu);
            if (func_8080241C_gcnewoption(menu)) {
                menu->local_s = 5;
                if (menu->local_11 != NULL) {
                    menu->local_11(menu->local_13, menu, menu->idx, 10);
                }
            }
            break;
        case 10:
            func_808019D0_gcnewoption(menu);
            if (func_80802534_gcnewoption(menu)) {
                menu->local_s = 5;
                func_80802B24_gcnewoption(menu, 0);
                if (menu->local_11 != NULL) {
                    menu->local_11(menu->local_13, menu, menu->idx, 10);
                }
            }
            break;
        default:
            break;
    }
    if (menu->local_7 != NULL &&
        (menu->local_s == 3 || menu->local_s == 5 || menu->local_s == 10)) {
        if (prev_title_state != 3 && menu->local_8 == 3) {
            menu->local_11(menu->local_13, menu, menu->idx, 9);
        }
    }
}

// Draws the menu; items scrolling past an end are drawn again on the other side.
void gcnewoption_entrypoint_1(NewOptionDrawState *menu, void *gfx)
{
    f32 item_y;
    s32 saved_alpha;
    s32 saved_alpha2;
    s16 state;
    s32 title;
    s32 box;
    s32 slot;

    state = menu->local_0;
    if (state >= 2 && state < 0xC) {
        for (slot = 0; slot < menu->local_1; slot++) {
            box = func_80800000_gcnewoption(menu, slot);
            _gczoombox_entrypoint_2(menu->local_5[slot], gfx);
            if (menu->local_6[box] < menu->local_2) {
                item_y = menu->local_6[box];
                saved_alpha = _gczoombox_entrypoint_29(menu->local_5[box]);
                _gczoombox_entrypoint_28(menu->local_5[box], menu->local_4);
                _gczoombox_entrypoint_38(menu->local_5[box],
                                         (s32) (menu->local_6[box] +
                                                menu->local_2 * menu->local_1 +
                                                menu->local_7));
                _gczoombox_entrypoint_2(menu->local_5[box], gfx);
                _gczoombox_entrypoint_38(menu->local_5[box],
                                         (s32) (menu->local_7 + item_y));
                _gczoombox_entrypoint_28(menu->local_5[box], (s16) saved_alpha);
            }
            if (menu->local_2 * menu->local_1 < menu->local_6[box]) {
                item_y = menu->local_6[box];
                saved_alpha2 = _gczoombox_entrypoint_29(menu->local_5[box]);
                _gczoombox_entrypoint_28(menu->local_5[box], menu->local_4);
                _gczoombox_entrypoint_38(menu->local_5[box],
                                         (s32) (menu->local_6[box] -
                                                menu->local_2 * menu->local_1 +
                                                menu->local_7));
                _gczoombox_entrypoint_2(menu->local_5[box], gfx);
                _gczoombox_entrypoint_38(menu->local_5[box],
                                         (s32) (menu->local_7 + item_y));
                _gczoombox_entrypoint_28(menu->local_5[box], (s16) saved_alpha2);
            }
        }
        title = menu->local_3;
        if (title != 0) {
            _gczoombox_entrypoint_2(title, gfx);
        }
    }
}

// Returns the state size in bytes.
int gcnewoption_entrypoint_2(void)
{
    return 0x260;
}

int gcnewoption_entrypoint_3(Actor *actor)
{
    s32 offset = 3;
    u8 *ptr = *(s32 *) ((char *) actor + 0x23C) + 3;
    if (*(u8 *) ((char *) *(s32 *) ((char *) actor + 0x23C) + 3) != 0x8D) {
        do {
            // Matching: the comma expression `(0, 2)` is needed for the match.
            offset = (offset + *(u8 *) ((char *) ptr + 1)) + (0, 2);
            ptr = *(s32 *) ((char *) actor + 0x23C) + offset;
        } while (*ptr != 0x8D);
    }
    return *(u8 *) ((char *) (*(s32 *) ((char *) actor + 0x23C) + offset) + 2) - 0x31;
}

// Allocates the state in actor local storage and initialises it.
void gcnewoption_entrypoint_4(owner, storage_slot, unk_2, callback, strings_id) s32 owner[3];
s16 storage_slot;
s32 unk_2;
s32 callback;
s32 strings_id;
{
    func_80100074(owner, storage_slot, 0x260);
    gcnewoption_entrypoint_5(func_80100094(owner, storage_slot), unk_2, callback, strings_id,
                             owner[0]);
}

// Sets the state to its defaults: 30 empty entries (white, font 0xC) and the title string.
void gcnewoption_entrypoint_5(menu, unk_1, callback, strings_id, callback_arg) u8 *menu;
s32 unk_1;
s32 callback;
s32 strings_id;
s32 callback_arg;
{
    s32 i;
    NewOptionInitState *opt = (NewOptionInitState *) menu;

    opt->local_0 = 0;
    opt->local_19 = _gldbstring_entrypoint_0(opt->local_19, strings_id);
    opt->local_20 = strings_id;
    opt->local_21 = unk_1;
    opt->local_22 = callback;
    opt->local_23 = callback_arg;
    opt->local_3 = 0;
    opt->local_4 = 0;
    opt->local_8 = 0;
    opt->local_6 = 0;
    opt->local_5 = 0;
    opt->local_7 = 0;
    opt->local_9 = 0;
    opt->local_18 = 0;
    opt->local_10 = 0;
    opt->local_17 = 0xD;
    opt->local_1 = _gldialog_entrypoint_0();
    opt->local_11 = 0;
    gcnewoption_entrypoint_40(menu, 0x2C, 0x1C, 0x32, 1.0f, 1.0f);
    opt->local_24 = 0;
    opt->local_2 = 0.0f;
    for (i = 0; i < 30; i++) {
        opt->local_12[i] = 0;
        opt->local_13[i] = -1;
        opt->local_14[i][0] = 0xFF;
        opt->local_14[i][1] = 0xFF;
        opt->local_14[i][2] = 0xFF;
        opt->local_15[i] = 0xC;
        opt->local_16[i] = 0;
    }
}

// Destroys the menu and frees its local storage.
void gcnewoption_entrypoint_6(owner, storage_slot) s32 owner;
s16 storage_slot;
{
    gcnewoption_entrypoint_7(func_80100094(owner, storage_slot));
    func_80100074(owner, storage_slot, 0);

}

// Destroys the boxes and releases the string table.
void gcnewoption_entrypoint_7(menu) OptionState *menu;
{
    if (*(s16 *) menu != 0xD || *(u32 *) (menu->data + 0x20)) {
        func_8080103C_gcnewoption(menu);
    }

_gldbstring_entrypoint_2(*(s16 *) (menu->data + 0x240));
}

void gcnewoption_entrypoint_8(s16 *menu, unsigned int count)
{
    menu[1] = count;
}

int gcnewoption_entrypoint_9(Actor *menu, long value)
{
    *((u16 *) (((char *) menu) + 0x4)) = value;
}

void gcnewoption_entrypoint_10(u8 *menu, u32 mode)
{
    unsigned char mode_byte; // Matching: extra temporary needed for the match.
    menu[0x1c] = (u8) ((menu[0x1c] & 0xfff8) | ((mode_byte = (unsigned char) mode) & 7));
}

// Starts the menu (state 1).
s32 gcnewoption_entrypoint_11(s16 *menu)
{
    s32 new_state;
    new_state = 1;
    *menu = new_state;
}

// Creates the item zoomboxes and the title zoombox.
void func_80800D28_gcnewoption(menu) OptionCreate211 *menu;
{
    s32 i;

    for (i = 0; i < menu->count; i++) {
        menu->items[i] = _gczoombox_entrypoint_5(
            (i + 1) * menu->spacing + menu->y, menu->texts[i], 2,
            ((OptionFlags211 *) menu)->local_3, 0);
        _gczoombox_entrypoint_41(menu->items[i], 45.0f);
        _gczoombox_entrypoint_42(menu->items[i], 0.3f);
        _gczoombox_entrypoint_26(menu->items[i], menu->font, menu->speed,
                                 menu->duration, 0);
        _gczoombox_entrypoint_44(menu->items[i], (u32) ((u8 *) menu)[0x1D] >> 7);
        _gczoombox_entrypoint_23(menu->items[i], menu->wrap == 0);

if (((OptionFlags211 *) menu)->local_1) {
    _gczoombox_entrypoint_20(menu->items[i], 100.0f, 0, 2, 0.1f, 0, 0);
}

if ((((u8 *) menu)[0x1C] & 7) == 3) {
    _gczoombox_entrypoint_41(menu->items[i], 1000.0f);
    _gczoombox_entrypoint_21(menu->items[i], 0);
}

menu->item_y[i] = (i + 1) * menu->spacing;
menu->colors[i][0] = menu->colors[i][1] = menu->colors[i][2] = 255;
menu->selected_text[i] = -1;
menu->item_states[i] = menu->texts[i];
}
if ((((u8 *) menu)[0x1C] & 7) == 3) {
    *(s16 *) ((u8 *) menu + 6) = -1;
} else {
    *(s16 *) ((u8 *) menu + 6) = 0;
}
*(s16 *) ((u8 *) menu + 8) = 0;
((u8 *) menu)[0x1C] &= ~0x20;
if (((OptionFlags211 *) menu)->local_0) {
    menu->title = NULL;
} else {
    menu->title = _gczoombox_entrypoint_5(0x1C, menu->title_font, 0, 0, 0);

if (!((OptionFlags211 *) menu)->local_2) {
    ((OptionTitleFlags211 *) menu)->local_0 = 1;
    _gczoombox_entrypoint_8(menu->title,
                            _gldbstring_entrypoint_1(menu->strings, menu->title_text));
}

_gczoombox_entrypoint_23(menu->title, menu->wrap == 0);

if (((OptionFlags211 *) menu)->local_1) {
    _gczoombox_entrypoint_20(menu->title, 30.0f, 0, 2, 0.1f, 0, 0);
}

}
func_80802A9C_gcnewoption(menu);
}

// Destroys the item and title zoomboxes.
void func_8080103C_gcnewoption(menu) OptionBoxes *menu;
{
    s32 i;
    for (i = 0; i < menu->count; i++) {
        if (menu->items[i]) {
            _gczoombox_entrypoint_0(menu->items[i]);
            menu->items[i] = NULL;
            menu->states[i] = -1;
        }

}
if (menu->title) {
    _gczoombox_entrypoint_0(menu->title);
    menu->title = NULL;
    menu->title_state = 0xFF;
}
}

// Plays the portrait voice of an item.
void func_808010E0_gcnewoption(s16 *menu, s32 item)
{
    if (menu[0x11C] == 0) {
        _gczoomboxdata_entrypoint_0(menu[item + 0xEE]);
    }
}

// Moves the selection up with wrap-around; returns 1 if it moved.
s32 func_80801114_gcnewoption(s16 *menu)
{
    if (menu[3] <= 0) {
        return 0;
    }
    menu[3]--;
    if (func_80800038_gcnewoption(menu, menu[3]) == -1) {
        menu[4]--;
        menu[5]--;

if (menu[5] < 0) {
    menu[5] = menu[1] - 1;
}

}
return 1;
}

// Moves the selection down with wrap-around; returns 1 if it moved.
int func_80801190_gcnewoption(OptionState *menu)
{
    OptionScrollState *scroll = (OptionScrollState *) menu;
    if (scroll->local_3 >= scroll->local_2 - 1)
        return 0;
    scroll->local_3++;
    if (func_80800038_gcnewoption(menu, scroll->local_3) == -1) {
        scroll->local_4++;
        scroll->local_5++;
        if (scroll->local_5 >= scroll->local_1)
            scroll->local_5 = 0;
    }
    return 1;
}

void gcnewoption_entrypoint_12(OptionState *menu, u32 item, s16 value)
{
    if (*(s16 *) (menu->data + 0xEC + item * 2) != value) {
        *(s16 *) (menu->data + 0xEC + item * 2) = value;
    }
}

void gcnewoption_entrypoint_13(s32 menu, s32 item, s16 *color)
{
    if (((color[0] != ((s16 *) (((char *) ((long) menu)) + (item * 6)))[0x94]) ||
         (color[1] != ((s16 *) (((char *) ((long) menu)) + (item * 6)))[0x95])) ||
        (color[2] != ((s16 *) (((char *) ((long) menu)) + (item * 6)))[0x96])) {
        ((s16 *) (((char *) ((long) menu)) + (item * 6)))[0x94] = color[0];
        ((s16 *) (((char *) ((long) menu)) + (item * 6)))[0x95] = color[1];
        ((s16 *) (((char *) ((long) menu)) + (item * 6)))[0x96] = color[2];
    }
}

void gcnewoption_entrypoint_14(u8 *menu, s16 unk_1, s16 unk_2, s16 unk_3, f32 unk_4)
{
    *(s16 *) (menu + 0x26) = unk_1;
    *(s16 *) (menu + 0x28) = unk_2;
    *(s16 *) (menu + 0x2A) = unk_3;
    *(f32 *) (menu + 0x2C) = unk_4;
    *(f32 *) (menu + 0x30) = unk_4;
}

// Plays the sound for a toggle value (0, 1 or -1).
int func_808012C8_gcnewoption(s32 value)
{
    s32 sfx_id;
    sfx_id = 0;
    switch (value) {
        case 0:
            sfx_id = 0x96;
            break;

        case 1:
            sfx_id = 0x97;
            break;

        case -1:
            sfx_id = 0xf;
    }

    if (sfx_id != 0) {
        // Matching: the mask and the extra argument are needed for the match.
        func_800FC6B0(sfx_id & 0xFFFFFFFF, sfx_id);
    }
}

// Default menu callback: event 1 toggles the item's value.
void gcnewoption_entrypoint_15(s32 unk_0, u8 *menu, s32 item, s32 event)
{
    // Matching: the extra temporaries are needed for the match.
    int item_offset;
    int arg_offset;
    u8 *entry;
    arg_offset = 0x24C;
    item_offset = item * 2;
    if (event == 1) {
        entry = menu + item_offset;

switch (*(s16 *) ((s8 *) entry + 0xB0)) {
    case 0:
        *(s16 *) ((s8 *) entry + 0xB0) = 1;
        (*(s32(**)(s32))((s8 *) menu + 0x248))(*(s32 *) ((s8 *) menu + arg_offset));
        break;

    case 1:
        *(s16 *) ((s8 *) entry + 0xB0) = 0;
        (*(s32(**)(s32))((s8 *) menu + 0x248))(*(s32 *) ((s8 *) menu + arg_offset));
        break;

    case -1:
        (*(s32(**)(s32))((s8 *) menu + 0x248))(*(s32 *) ((s8 *) menu + 0x24C));
}

func_808012C8_gcnewoption(*((s16 *) (((s8 *) entry) + 0xB0)));
return;
}
(*((s32(**)(s32))(((s8 *) menu) + 0x248)))(*((s32 *) (((s8 *) menu) + arg_offset)));
}

void gcnewoption_entrypoint_16(s32 unk_0, u8 *menu, s32 item, s32 event)
{
    if (event != 1) {
        (*(s32(**)(s32, u8 *, s32))(menu + 0x248))(*(s32 *) (menu + 0x24C), menu, item);
    }
}

s32 gcnewoption_entrypoint_17(s32 menu, unsigned int item)
{
    return (*((s16 *) (((s8 *) (menu + (item * 2))) + 0xB0))) == 0;
}

int gcnewoption_entrypoint_18(s16 *menu, int item)
{
    return menu[item + 0x58] == 1;
}

int gcnewoption_entrypoint_19(s16 *menu, int item)
{
    return !(menu[item + 0x58] + 1);
}

int gcnewoption_entrypoint_20(s16 *menu, int item)
{
    return menu[item + 0x58];
}

void gcnewoption_entrypoint_21(s16 *menu, int item)
{
    menu[item + 0x58] = 0;
}

void gcnewoption_entrypoint_22(union U *menu, int item)
{
    *(s16 *) ((char *) menu + (item * 2) + 0xB0) = 1;
}

void gcnewoption_entrypoint_23(s16 *menu, int item)
{
    *(s16 *) ((s8 *) (&menu[item]) + 176) = -1;
}

void gcnewoption_entrypoint_24(s16 *menu, s32 item, s32 value)
{
    menu[item + 0x58] = value;
}

int gcnewoption_entrypoint_25(u8 *menu, s32 flag)
{
    if (!(flag == 0)) {
        menu[0x1D] &= ~0x40;
    } else {
        menu[0x1D] = (menu[0x1D] & 0xFFFF) | 0x40;
    }
}

void gcnewoption_entrypoint_26(u8 *menu, s32 flag)
{
    s32 i;
    s32 box;

    if (flag) {
        ((CodexOptionVisibility *) (menu + 0x1D))->local_0 = 0;
    } else {
        ((CodexOptionVisibility *) (menu + 0x1D))->local_0 = 1;
    }
    for (i = 0; i < *(s16 *) (menu + 2); i++) {
        box = func_80800000_gcnewoption(menu, i);

if (((void **) (menu + 0x3C))[box]) {
    _gczoombox_entrypoint_44(((void **) (menu + 0x3C))[box], flag ? 0 : 1);
}

}
}

void gcnewoption_entrypoint_27(u8 *menu, s32 item, s32 value)
{
    s32 box;
    s32 slot;

    (menu + item)[0x218] = value;
    slot = func_80800038_gcnewoption(menu, item);
    func_80800000_gcnewoption(menu, slot);
    if (slot != -1) {
        box = func_80800000_gcnewoption(menu, slot);

if (((s32 *) menu)[box + 15] != 0) {
    _gczoombox_entrypoint_40(((s32 *) menu)[box + 15], value);
}

}
}

// Starts the closing animation of the title and all item boxes.
void gcnewoption_entrypoint_28(OptionState *menu)
{
    s32 i;
    gcnewoption_entrypoint_42(menu, 0.1f);
    ((OptionClosingFlag *) menu)->local_0 = 1;
    if (*(void **) ((u8 *) menu + 0x20))
        _gczoombox_entrypoint_20(*(void **) ((u8 *) menu + 0x20), 30.0f, 0, 2, 0.1f, 0, 0);
    for (i = 0; i < *(s16 *) ((u8 *) menu + 2); i++) {
        if (((void **) ((u8 *) menu + 0x3C))[i])
            _gczoombox_entrypoint_20(((void **) ((u8 *) menu + 0x3C))[i], 100.0f, 0, 2,
                                     0.1f, 0, 0);
    }
}

void gcnewoption_entrypoint_29(u8 *menu, u32 flag)
{
    // Matching: the extra temporaries are needed for the match.
    int flags_offset;
    char shifted;
    menu[flags_offset = 0x1d] = (u8) ((menu[flags_offset] & 0xfff7) | ((shifted = flag * 8) & 8));
    {
    }
}

void gcnewoption_entrypoint_30(u8 *menu, s16 *exclude)
{
    s16 chosen[30];
    s32 i;
    s32 candidate;
    u16 key;
    s32 unique;
    s32 j;

    for (i = 0; i < *(s16 *) (menu + 4); i++) {
        unique = 0;
        do {
            candidate = func_800DC128(12, 210);
            if (_gczoomboxdata_entrypoint_6(candidate)) {
                key = _gczoomboxdata_entrypoint_5(candidate);
                if (_gczoomboxdata_entrypoint_5(*(s16 *) (menu + 0x236)) != key) {
                    unique = 1;
                    if (exclude) {
                        for (j = 0; exclude[j] != -1; j++) {
                            if (_gczoomboxdata_entrypoint_5(exclude[j]) == key) {
                                unique = 0;
                                break;
                            }
                        }
                    }
                    if (unique) {
                        for (j = i - 1; j >= 0; j--) {
                            if (_gczoomboxdata_entrypoint_5(chosen[j]) == key) {
                                unique = 0;
                                break;
                            }
                        }
                    }
                }
            }
        } while (!unique);
        gcnewoption_entrypoint_31(menu, i, (s16) candidate);
        chosen[i] = candidate;
    }
}

void gcnewoption_entrypoint_31(menu, item, text_id) s32 menu;
s32 item;
s16 text_id;
{
    (*(s16 *) ((s8 *) ((menu + (item * 2))) + (0x1DC))) = text_id;
}

int gcnewoption_entrypoint_32(Actor *menu, s16 title_font)
{
    s16 font;
    font = title_font;
    *(s16 *) ((char *) menu + 0x236) = font;
    _gczoombox_entrypoint_37(*(s32 *) ((char *) menu + 0x20), font);
}

int gcnewoption_entrypoint_33(void *menu)
{
    s32 i;
    void *box;
    void *cursor;
    *(s16 *) ((char *) (menu) + 0x238) = 1;
    if ((*(s32 *) ((char *) (menu) + 0x20)) != 0) {
        _gczoombox_entrypoint_23((*(s32 *) ((char *) (menu) + 0x20)), 0);
    }
    i = 0;
    cursor = menu;
    while (i < (*(s16 *) ((char *) (menu) + 0x2))) {
        box = *(void **) ((char *) (cursor) + 0x3C);
        _gczoombox_entrypoint_23(box, 0);
        i++;
        cursor = (void *) ((char *) (cursor) + 0x4);
    }
}

// Replaces the title text.
void gcnewoption_entrypoint_34(OptionState *menu, u32 text_id)
{
    if (*(void **) ((u8 *) menu + 0x20) != NULL) {
        _gczoombox_entrypoint_32(*(void **) ((u8 *) menu + 0x20));
        _gczoombox_entrypoint_8(
            *(void **) ((u8 *) menu + 0x20),
            _gldbstring_entrypoint_1(*(void **) ((u8 *) menu + 0x23C), (s16) text_id));
        ((OptionChangeFlags *) menu)->changed = 1;
        *(f32 *) ((u8 *) menu + 0x30) = *(f32 *) ((u8 *) menu + 0x2C);
    }
}

// Updates and draws the item boxes and the title box.
void func_808019D0_gcnewoption(NewOptionUpdateState *menu)
{
    s32 selected_slot;
    s32 slot;
    s32 box;
    s32 item;
    void *title;
    s32 title_state;
    if (!menu->local_1) {
        selected_slot = func_80800038_gcnewoption(menu, menu->local_0[3]);
        for (slot = 0; slot < menu->local_0[1]; slot++) {
            box = func_80800000_gcnewoption(menu, slot);
            item = func_80800070_gcnewoption(menu, slot);
            func_808027DC_gcnewoption(menu, slot);

if (menu->local_2) {
    _gczoombox_entrypoint_40(menu->local_5[box], selected_slot == slot ? 1 : 0);
} else {

_gczoombox_entrypoint_40(menu->local_5[box], menu->local_6[item]);
}
if (selected_slot == slot && !_gczoombox_entrypoint_22(menu->local_5[box])) {
    func_808010E0_gcnewoption(menu, item);
}
_gczoombox_entrypoint_21(menu->local_5[box], selected_slot == slot);
_gczoombox_entrypoint_4(menu->local_5[box]);
}
func_80801B5C_gcnewoption(menu);
}
if (menu->local_3 != 0) {
    title = menu->local_3;
    title_state = _gczoombox_entrypoint_3(menu->local_3);
    _gczoombox_entrypoint_4(title);
    if (menu->local_0[0] == 3 || menu->local_0[0] == 4 || menu->local_0[0] == 5) {
        menu->local_4 = title_state;
    }
}
menu->local_0[6] = _gldialog_entrypoint_0();
}

// Slides each item box toward its slot position and fades boxes that wrap around.
void func_80801B5C_gcnewoption(menu) u8 *menu;
{
    s32 i;
    s32 box;
    f32 target_y;
    f32 diff;
    f32 limit;
    s16 alpha_in;
    s16 alpha_out;

    for (i = 0; i < *(s16 *) (menu + 2); i++) {
        box = func_80800000_gcnewoption(menu, i);
        target_y = i + 1;
        target_y *= *(f32 *) (menu + 0x14);
        limit = *(f32 *) (menu + 0x14) * 1.9f;
        diff = target_y - ((f32 *) (menu + 0x80))[box];
        if (limit < diff) {
            ((f32 *) (menu + 0x80))[box] =
                *(f32 *) (menu + 0x14) * (*(s16 *) (menu + 2) + 1);
            _gczoombox_entrypoint_28(((s32 *) (menu + 0x3C))[box], 0);
            *(s16 *) (menu + 0x34) = 255;
        } else if (diff < -limit) {
            ((f32 *) (menu + 0x80))[box] = 0.0f;
            _gczoombox_entrypoint_28(((s32 *) (menu + 0x3C))[box], 0);
            *(s16 *) (menu + 0x34) = 255;
        }
        if (*(s16 *) (menu + 0x34) >= 20.0f) {
            *(s16 *) (menu + 0x34) -= 20.0f;
        }
        if (*(f32 *) (menu + 0x14) * 0.66f < ((f32 *) (menu + 0x80))[box] &&
            ((f32 *) (menu + 0x80))[box] <
                ((f32) *(s16 *) (menu + 2) + 0.66f) * *(f32 *) (menu + 0x14)) {
            alpha_in = _gczoombox_entrypoint_29(((s32 *) (menu + 0x3C))[box]);
            if (alpha_in < 236) {
                _gczoombox_entrypoint_28(((s32 *) (menu + 0x3C))[box], (s16) (alpha_in + 20));
            }
        } else {
            alpha_out = _gczoombox_entrypoint_29(((s32 *) (menu + 0x3C))[box]);
            if (alpha_out >= 20) {
                _gczoombox_entrypoint_28(((s32 *) (menu + 0x3C))[box], (s16) (alpha_out - 20));
            }
        }
        if (target_y != ((f32 *) (menu + 0x80))[box]) {
            if (target_y < ((f32 *) (menu + 0x80))[box]) {
                ((f32 *) (menu + 0x80))[box] -= 4.0f;

if (((f32 *) (menu + 0x80))[box] <= target_y) {
    ((f32 *) (menu + 0x80))[box] = target_y;
} else {

((NewOptionMovingFlag1081 *) menu)->local_0 = 1;
}
}
else if (((f32 *) (menu + 0x80))[box] < target_y)
{
    ((f32 *) (menu + 0x80))[box] += 4.0f;
    if (target_y <= ((f32 *) (menu + 0x80))[box]) {
        ((f32 *) (menu + 0x80))[box] = target_y;
    } else {
        ((NewOptionMovingFlag1081 *) menu)->local_0 = 1;

}
}
_gczoombox_entrypoint_38(((s32 *) (menu + 0x3C))[box],
                         (s32) (*(s16 *) (menu + 0x256) + ((f32 *) (menu + 0x80))[box]));
}
}
}

// Runs the open animation of the boxes; returns 1 once all of them are open.
s32 func_80801E68_gcnewoption(u8 *menu)
{
    s32 i;
    s32 all_ready;
    s32 box_state;
    s32 title_state;
    u8 *box_cursor;
    u8 *state_cursor;

    all_ready = 1;
    box_cursor = menu;
    i = 0;
    if (*(s16 *) ((s8 *) menu + 2) > 0) {
        state_cursor = menu;
        do {
            box_state = _gczoombox_entrypoint_3(*(s32 *) ((s8 *) box_cursor + 0x3C));
            switch (box_state) {
                case 0:
                    if (i == 0) {
                        if ((*(s32 *) ((s8 *) menu + 0x20) == 0) ||
                            (_gczoombox_entrypoint_3(*(s32 *) ((s8 *) menu + 0x20)) == 1) ||
                            (_gczoombox_entrypoint_3(*(s32 *) ((s8 *) menu + 0x20)) == 2) ||
                            (_gczoombox_entrypoint_3(*(s32 *) ((s8 *) menu + 0x20)) == 3) ||
                            (func_800D9078(menu + 0x38) != 0)) {
                            _gczoombox_entrypoint_9(*(s32 *) ((s8 *) box_cursor + 0x3C));
                            if (*(f32 *) ((s8 *) box_cursor + 0x9C) == 0.0f) {
                                *(f32 *) ((s8 *) box_cursor + 0x9C) =
                                    (f32) *(f32 *) ((s8 *) menu + 0x18);
                            }
                        }

}
else if ((_gczoombox_entrypoint_3((*(s32 *) ((s8 *) (box_cursor) + (0x38)))) == 1) ||
         (_gczoombox_entrypoint_3((*(s32 *) ((s8 *) (box_cursor) + (0x38)))) == 2) ||
         (_gczoombox_entrypoint_3((*(s32 *) ((s8 *) (box_cursor) + (0x38)))) == 3) ||
         (func_800D9078(box_cursor + 0x98) != 0))
{
    _gczoombox_entrypoint_9((*(s32 *) ((s8 *) (box_cursor) + (0x3C))));

if (*(f32 *) ((s8 *) box_cursor + 0x9C) == 0.0f) {
    *(f32 *) ((s8 *) box_cursor + 0x9C) = (f32) *(f32 *) ((s8 *) menu + 0x18);
}

}
break;
case 1:
    _gczoombox_entrypoint_11((*(s32 *) ((s8 *) (box_cursor) + (0x3C))));
    (*(s8 *) ((s8 *) (state_cursor) + (0x94))) = box_state;
    break;
case 2:;
case 3:
    (*(s8 *) ((s8 *) (state_cursor) + (0x94))) = box_state;
    }
    if ((*(s8 *) ((s8 *) (state_cursor) + (0x94))) <= 0) {
        all_ready = 0;
    }
    i += 1;
    box_cursor += 4;
    state_cursor += 1;
    }
    while (i < (*(s16 *) ((s8 *) (menu) + (2))))
        ;
    }
    if ((*(s32 *) ((s8 *) (menu) + (0x20))) != 0) {
        title_state = _gczoombox_entrypoint_3((*(s32 *) ((s8 *) (menu) + (0x20))));
        switch (title_state) {
            case 2:;
            case 3:
                break;
            case 0:
                all_ready = 0;
                if (title_state != (*(u8 *) ((s8 *) (menu) + (0x24)))) {
                    _gczoombox_entrypoint_9((*(s32 *) ((s8 *) (menu) + (0x20))));
                    _gczoombox_entrypoint_11((*(s32 *) ((s8 *) (menu) + (0x20))));
                    if ((*(f32 *) ((s8 *) (menu) + (0x38))) == 0.0f) {
                        (*(f32 *) ((s8 *) (menu) + (0x38))) =
                            (f32) (*(f32 *) ((s8 *) (menu) + (0x18)));
                    }
                }
        }
        (*(u8 *) ((s8 *) (menu) + (0x24))) = (u8) title_state;
    }
    return all_ready;
    }

    s32 func_808020C4_gcnewoption(menu)
    NewOptionTransitionState *menu;
    {
        s32 i;
        s32 box_state;
        s32 all_settled = 1;
        s32 any_active = 0;
        s32 title_probe;
        s32 state;
        s32 title_state;

        for (i = 0; i < menu->local_1; i++) {
            box_state = _gczoombox_entrypoint_3(menu->local_4[i]);
            if (box_state == 0 || box_state == 2 || box_state == 3) {
                any_active = 1;
            }
        }
        if (menu->local_2) {
            title_probe = _gczoombox_entrypoint_3(menu->local_2);
            switch (title_probe) {
                case 0:
                case 2:
                case 3:
                    any_active = 1;
            }
        }
        for (i = 0; i < menu->local_1; i++) {
            state = _gczoombox_entrypoint_3(menu->local_4[i]);
            switch (state) {
                case 0:
                case 2:
                case 3:
                    all_settled = 0;
                    if (state != menu->local_5[i]) {
                        _gczoombox_entrypoint_33(menu->local_4[i]);
                    }
                    menu->local_5[i] = state;
                    break;
                case 4:
                    all_settled = 0;
                    if (!any_active) {
                        if (state != menu->local_5[i]) {
                            _gczoombox_entrypoint_10(menu->local_4[i]);
                        }
                        menu->local_5[i] = state;
                    }
                    break;
                case 5:
                    menu->local_5[i] = state;
                    break;
                default:
                    menu->local_5[i] = state;
            }
        }
        if (menu->local_2) {
            title_state = _gczoombox_entrypoint_3(menu->local_2);
            switch (title_state) {
                case 6:
                    break;
                case 0:
                case 2:
                case 3:
                    all_settled = 0;
                    if (title_state != menu->local_3) {
                        _gczoombox_entrypoint_33(menu->local_2);
                    }
                    break;
                case 4:
                    all_settled = 0;
                    if (title_state != menu->local_3) {
                        _gczoombox_entrypoint_10(menu->local_2);
                    }
            }
            menu->local_3 = title_state;
        }
        return all_settled;
    }

    s32 func_808022E0_gcnewoption(menu)
    u8 *menu;
    {
        s32 i;
        s32 slot;
        s32 state;
        s32 settled = 1;
        s32 *box_words;
        u8 *state_bytes;

        for (i = 0; i < *(s16 *) (menu + 2); i++) {
            if (func_80800070_gcnewoption(menu, i) != *(s16 *) (menu + 6)) {
                slot = func_80800000_gcnewoption(menu, i);
                state = _gczoombox_entrypoint_3(*(s32 *) (menu + 0x3C + slot * 4));
                switch (state) {
                    case 0:
                    case 2:
                    case 3:
                        state_bytes = menu + slot;
                        settled = 0;
                        box_words = (s32 *) menu + slot;
                        if (state != *(s8 *) (state_bytes + 0x94)) {
                            _gczoombox_entrypoint_12(box_words[0xF]);
                            _gczoombox_entrypoint_10(box_words[0xF]);
                        }
                        break;
                    case 4:
                        state_bytes = menu + slot;
                        if (state != *(s8 *) (state_bytes + 0x94)) {
                            _gczoombox_entrypoint_10(*(s32 *) (menu + 0x3C + slot * 4));
                        }
                        break;
                    case 5:
                        state_bytes = menu + slot;
                        break;
                    default:
                        state_bytes = menu + slot;
                }
                state_bytes[0x94] = state;
            }
        }
        return settled;
    }

    s32 func_8080241C_gcnewoption(menu)
    OptionBoxes29 *menu;
    {
        s32 i;
        s32 slot;
        s32 state;
        s32 settled = 1;
        for (i = 0; i < menu->count; i++) {
            if (func_80800070_gcnewoption(menu, i) != menu->selected) {
                slot = func_80800000_gcnewoption(menu, i);
                state = _gczoombox_entrypoint_3(menu->boxes[slot]);
                switch (state) {
                    case 0:
                    case 2:
                    case 3:
                        settled = 0;
                        if (state != menu->states[slot]) {
                            _gczoombox_entrypoint_33(menu->boxes[slot]);
                            menu->indices[slot] = -1;
                        }
                        break;
                    case 4:
                    case 5:
                        break;
                    default:
                        break;
                }
                menu->states[slot] = state;
            }
        }
        return settled;
    }

    int func_80802534_gcnewoption(NewOptionBoxes *menu)
    {
        s32 i;
        s32 slot;
        s32 state;
        s32 settled = 1;
        for (i = 0; i < menu->local_0[1]; i++) {
            if (func_80800070_gcnewoption(menu, i) != menu->local_0[3]) {
                slot = func_80800000_gcnewoption(menu, i);
                state = _gczoombox_entrypoint_3(menu->local_1[slot]);
                switch (state) {
                    case 0:
                        settled = 0;
                        if (state != menu->local_2[slot]) {
                            _gczoombox_entrypoint_9(menu->local_1[slot]);
                            _gczoombox_entrypoint_11(menu->local_1[slot]);
                        }
                        break;
                    case 4:
                        settled = 0;
                        if (state != menu->local_2[slot])
                            _gczoombox_entrypoint_11(menu->local_1[slot]);
                        break;
                    case 2:
                        break;
                }
                menu->local_2[slot] = state;
            }
        }
        return settled;
    }

    s32 func_80802674_gcnewoption(menu)
    u8 *menu;
    {
        s32 settled;
        s32 slot;
        s32 state;

        settled = 1;
        slot = func_80800000_gcnewoption(
            menu, func_80800038_gcnewoption(menu, *(s16 *) (menu + 6)));
        state = _gczoombox_entrypoint_3(((s32 *) (menu + 0x3C))[slot]);
        switch (state) {
            case 0:
            case 3:
                if (state != *(s8 *) (menu + slot + 0x94)) {
                    _gczoombox_entrypoint_34(((s32 *) (menu + 0x3C))[slot]);
                }
                settled = 0;
                break;
            case 4:
                if (state != *(s8 *) (menu + slot + 0x94)) {
                    _gczoombox_entrypoint_10(((s32 *) (menu + 0x3C))[slot]);
                }
                settled = 0;
                break;
            case 5:
            case 6:
                break;
            default:
                break;
        }
        *(s8 *) (menu + slot + 0x94) = state;
        if (*(s32 *) (menu + 0x20)) {
            state = _gczoombox_entrypoint_3(*(s32 *) (menu + 0x20));
            switch (state) {
                case 0:
                case 2:
                case 3:
                case 6:
                    settled = 0;
                    if (state != menu[0x24]) {
                        _gczoombox_entrypoint_34(*(s32 *) (menu + 0x20));
                    }
                    break;
                case 4:
                    settled = 0;
                    if (state != menu[0x24]) {
                        _gczoombox_entrypoint_10(*(s32 *) (menu + 0x20));
                    }
            }
            menu[0x24] = state;
        }
        return settled;
    }

    // Refreshes a visible item box when its entry's text, colour or font changed.
    void func_808027DC_gcnewoption(menu, index) NewOptionContentState *menu;
    s32 index;
    {
        s32 entry;
        s32 slot;
        s32 text_id;
        s32 unk_0;
        entry = func_80800070_gcnewoption(menu, index);
        slot = func_80800000_gcnewoption(menu, index);
        text_id = menu->local_5[entry];
        unk_0 = _gldialog_entrypoint_0();
        if (text_id != menu->local_2[func_80800000_gcnewoption(menu, index)] ||
            menu->local_3[slot][0] != menu->local_6[entry][0] ||
            menu->local_3[slot][1] != menu->local_6[entry][1] ||
            menu->local_3[slot][2] != menu->local_6[entry][2] ||
            menu->local_4[slot] != menu->local_7[entry] || unk_0 != menu->local_0) {
            _gczoombox_entrypoint_32(menu->local_1[slot]);
            _gczoombox_entrypoint_27(menu->local_1[slot], menu->local_6[entry]);
            _gczoombox_entrypoint_8(menu->local_1[slot],
                                    _gldbstring_entrypoint_1(menu->local_9, (s16) text_id));
            _gczoombox_entrypoint_40(menu->local_1[slot], menu->local_8[entry]);
            _gczoombox_entrypoint_36(menu->local_1[slot], menu->local_7[entry]);
            menu->local_2[slot] = text_id;
            menu->local_3[slot][0] = menu->local_6[entry][0];
            menu->local_3[slot][1] = menu->local_6[entry][1];
            menu->local_3[slot][2] = menu->local_6[entry][2];
            menu->local_4[slot] = menu->local_7[entry];
        }
    }

    void func_80802998_gcnewoption(NewOptionScroll27 *menu)
    {
        s16 next_index;

        if (menu->local_1 && (menu->local_3 || menu->local_4)) {
            if (menu->local_6 <= 0.0f) {
                next_index = menu->local_2 + 1;
                if (menu->local_4 < next_index) {
                    next_index = menu->local_3 - 1;
                }
                _gczoombox_entrypoint_32(menu->local_1);
                _gczoombox_entrypoint_8(menu->local_1,
                                        _gldbstring_entrypoint_1(menu->local_7, next_index));
                menu->local_0 = 1;
                menu->local_2 = next_index;
                menu->local_6 = menu->local_5;
            } else if (_gczoombox_entrypoint_3(menu->local_1) == 3) {
                menu->local_6 -= func_800D8FF8();
            }
        }
    }

    // Resets the cached box states.
    void func_80802A9C_gcnewoption(void *menu)
    {
        s32 i;
        s8 *states = menu;
        for (i = 0; i < *(s16 *) ((char *) menu + 0x2); i++) {
            states[0x94 + i] = -1;
        }
        *(u8 *) ((char *) menu + 0x24) = 0xFF;
    }

    void gcnewoption_entrypoint_35(s32 param_0, s32 param_1, s32 param_2, s32 param_3)
    {
        union {
            struct {
                s16 local_0;
                s16 local_1;
            } local_0;
            s32 local_1;
        } packed;

        packed.local_0.local_0 = param_2;
        packed.local_0.local_1 = param_3;
        func_80101074(param_1);
        func_8010114C(param_0, 0x20, packed.local_1);
    }

    void gcnewoption_entrypoint_36(s32 menu)
    {
        u8 *flags;
        flags = (u8 *) (menu + 0x1C);
        *flags = ((*flags) & 0xFF) | 0x10;
    }

    void func_80802B24_gcnewoption(u8 *menu, s32 on)
    {
        // Matching: the extra copy and the empty block are needed for the match.
        int flag;
        flag = on;
        if (flag) {
            if (((!(flag & 0xFF)) && (!flag)) && (!flag)) {
            }
            menu[28] |= (long) 0x8;
        } else {
            menu[28] &= 0xFFF7;
        }
    }

    u32 gcnewoption_entrypoint_37(OptionState *menu, u32 on)
    {
        // Matching: the extra copies and the empty block are needed for the match.
        s16 *state_ptr;
        int is_null;
        OptionState *menu_copy;
        u8 *flags_clr;
        u8 *flags_set;
        menu_copy = menu;
        if (((*((s16 *) (((char *) menu_copy) + 0x0))) == 5) ||
            ((*((s16 *) (((char *) menu_copy) + 0x0))) == 4)) {
            is_null = !menu_copy;
            if ((((!menu_copy) & 0xFFFF) && is_null) && (!menu_copy)) {
            }
            state_ptr = (s16 *) (((char *) menu_copy) + 0x0);
            if (on != 0) {
                flags_set = (u8 *) (((char *) menu) + 0x1C);
                *flags_set |= 0x20;
            } else {
                *(flags_clr = (u8 *) (((char *) menu_copy) + 0x1C)) &= ~0x20;
            }
            func_80802A9C_gcnewoption(menu);
            *state_ptr = 6;
            return 1;
        }
        return 0;
    }

    s32 gcnewoption_entrypoint_38(u8 *menu, s32 param_1)
    {
        s32 slot;
        s16 state;
        int offset;
        state = *((s16 *) ((s8 *) menu));
        if ((state == 5) || (state == 0xA)) {
            slot = func_80800000_gcnewoption(
                menu, func_80800038_gcnewoption(menu, *((s16 *) (((s8 *) menu) + 6))));
            func_80802A9C_gcnewoption(menu);
            *((s16 *) ((s8 *) menu)) = 9;
            func_80802B24_gcnewoption(menu, 1);
            if (param_1 != 0) {
                // Matching: extra temporary for the offset.
                offset = slot * 4;
                _gczoombox_entrypoint_41(*((s32 *) (((s8 *) (menu + offset)) + 0x3C)), 1000.0f);
            }
            return 1;
        }
        return 0;
    }

    s32 gcnewoption_entrypoint_39(OptionState *menu)
    {
        s32 slot;
        if (((s16 *) menu)[0] == 5 || ((s16 *) menu)[0] == 9) {
            slot = func_80800000_gcnewoption(
                menu, func_80800038_gcnewoption(menu, ((s16 *) menu)[3]));
            func_80802A9C_gcnewoption(menu);
            ((s16 *) menu)[0] = 10;
            _gczoombox_entrypoint_41(*(void **) ((u8 *) menu + 0x3C + slot * 4), 45.0f);
            return 1;
        }
        return 0;
    }

    void gcnewoption_entrypoint_40(u8 *menu, s32 param_1, s32 param_2, s32 param_3, f32 param_4,
                                   f32 param_5)
    {
        *(s16 *) (menu + 0x254) = param_1;
        *(s16 *) (menu + 0x256) = param_2;
        *(f32 *) (menu + 0x14) = param_3;
        *(f32 *) (menu + 0x258) = param_4;
        *(f32 *) (menu + 0x25C) = param_5;
    }

    // HEADER-CHANGE: include/gc/newoption.h declares gcnewoption_entrypoint_41 (and _gcnewoption_entrypoint_41)
    // with an s32 second parameter (was u8); the target does not mask it on entry.
    // Selects entry `index` and centres it in the visible window.
    void gcnewoption_entrypoint_41(OptionState *menu, s32 index)
    {
        OptionScrollState *scroll = (OptionScrollState *) menu;
        scroll->local_3 = index;
        scroll->local_5 = 0;
        scroll->local_4 = index - (scroll->local_1 - 1) / 2;
        if (scroll->local_4 < 0)
            scroll->local_4 = 0;
        if (scroll->local_4 > scroll->local_2 - scroll->local_1) {
            scroll->local_4 = scroll->local_2 - scroll->local_1;
        }
        func_808010E0_gcnewoption(menu, index);
    }

    void gcnewoption_entrypoint_42(OptionState *menu, f32 value)
    {
        // Matching: extra temporary for the index.
        int field_index;
        field_index = 6;
        ((f32 *) menu)[field_index] = value;
    }

    s32 gcnewoption_entrypoint_43(void *menu, s32 param_1, s32 param_2)
    {
        s32 slot;

        slot = func_80800038_gcnewoption(menu, param_1);
        if (slot != -1) {
            slot = func_80800000_gcnewoption(menu, slot);
            _gczoombox_entrypoint_21(*(void **) ((u8 *) menu + 0x3C + slot * 4), param_2);
            return 1;
        }
        return 0;
    }

    void gcnewoption_entrypoint_44(OptionTitleControl *menu, s32 param_1)
    {
        menu->local_2 = param_1;
        if (param_1) {
            _gczoombox_entrypoint_20(menu->title, 0.0f, 0, 2, 0.1f, 0, 0);
        } else {
            if (!menu->local_0) {
                _gczoombox_entrypoint_32(menu->title);
                _gczoombox_entrypoint_8(menu->title, _gldbstring_entrypoint_1(
                                                            menu->strings, menu->title_text));
                menu->local_0 = 1;
            }
            if (menu->local_1) {
                _gczoombox_entrypoint_20(menu->title, 30.0f, 0, 2, 0.1f, 0, 0);
            } else {
                _gczoombox_entrypoint_20(menu->title, 15.0f, 0, 2, 0.1f, 0, 0);
            }
        }
    }

    // Returns the selected index.
    s16 gcnewoption_entrypoint_45(u8 *menu)
    {
        return *(s16 *) (menu + 6);
    }

    void gcnewoption_entrypoint_46(void *menu, int param_1)
    {
        ((u8 *) menu)[0x250] = param_1;
    }

    s32 gcnewoption_entrypoint_47(s32 menu)
    {
        return *(u8 *) (menu + 0x24) == 3;
    }

    // True while the menu is in state 3 to 10.
    int gcnewoption_entrypoint_48(s16 *menu)
    {
        s16 state = *menu;
        return state >= 3 && state < 11;
    }

    void gcnewoption_entrypoint_49(u8 *menu, u32 param_1)
    {
        // Matching: extra temporary and redundant masks are needed for the match.
        int flags;
        flags = menu[0x1D] & 0xFFFF;
        menu[0x1D] = (u8) (((param_1 << 1) & 2) | ((flags & 0xFFFF) & 0xFFFD));
    }
