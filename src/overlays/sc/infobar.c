// HUD info-bar object behind each counter slot: slide state machine, value/max/mode setters,
// item cross-fade, icon sprite animation and drawing via the per-style value renderers.
#include "common.h"

// Icon table entry (D_808008B0), indexed by item.
typedef struct {
    s16 sprite_id;
    s16 pad_2;
    s32 pad_4 : 17;
    s32 scale : 15;
    void *unk_8;
} InfoBarSound;
extern InfoBarSound D_808008B0_scinfobar[];
extern s32 func_800E8B74(s32);
extern void func_800E8D28(s32, f32);
extern void func_800E8C08(u8);
typedef struct ScInfobarCallback {
    s32 (*get_frames)(void);
    u32 pad_4[2];
} ScInfobarCallback;
extern ScInfobarCallback D_80800D58_scinfobar[];
// HUD info-bar object, 0x34 bytes. state: 0x64 hidden, 0x65 opening, 0x66 shown, 0x67 closing.
typedef struct {
    u8 state;
    u8 mode;
    u8 pending;
    u8 active;
    s16 item;
    s16 next_item;
    u8 pad_8[2];
    u8 unk_A;
    u8 pad_B[9];
    f32 slide;
    u8 pad_18[8];
    s32 value;
    s32 max_value;
    s32 unk_28;
    u8 pad_2C[8];
} InfoBar;
extern void *heap_alloc(s32);
extern void heap_free(void *);
typedef struct {
    u8 state;
    u8 pad_1[9];
    u8 unk_A;
    u8 pad_B[9];
    f32 slide;
    f32 slide_speed;
} InfobarTransition;
extern f32 func_800D8FF8(void);
extern int D_80800D5C_scinfobar[];
typedef struct {
    u8 pad_0[8];
    s16 frames;
    u16 pad_A;
    f32 unk_C;
    f32 unk_10;
    f32 pad_14;
    f32 slide_speed;
} InfoBarRateRecord;
typedef struct {
    s16 icon;
    s8 unk_2;
    s8 unk_3;
    s16 scale;
    u16 unk_6;
    s32 unk_8;
} InfoBarDialog;
extern void _fxdialog_entrypoint_2(f32);
extern void _fxdialog_entrypoint_4(s32, s32, s32, f32, f32, s32, s32);
typedef struct {
    u8 state;
    u8 mode;
    u8 pad_2[6];
    s16 unk_8;
    u8 pad_A[2];
    f32 unk_C;
    u8 pad_10[4];
    f32 slide;
} InfoBarDrawState;
extern void _fxdialog_entrypoint_3(void *, f32, s32, s32);
// Per-style table (D_80800D54); the words at +4 and +8 are also read through D_80800D58 and D_80800D5C.
typedef struct {
    s32 (*draw)(s32, u8 *, s32, s32);
    s32 unk_4, unk_8;
} InfobarDrawCallbacks;
extern InfobarDrawCallbacks D_80800D54_scinfobar[];
int scinfobar_entrypoint_3();
void scinfobar_entrypoint_8();
void scinfobar_entrypoint_9();
void scinfobar_entrypoint_10();

// Start the icon sprite of an item on the bar (handle stored at +0x32).
void func_80800000_scinfobar(u8 *bar, s32 item)
{
    f32 scale;

    if (D_808008B0_scinfobar[item].scale != 0) {
        scale = D_808008B0_scinfobar[item].scale / 256.0f;
        bar[0x32] = func_800E8B74(D_808008B0_scinfobar[item].sprite_id);
        if (D_808008B0_scinfobar[item].unk_8 != NULL) {
            func_800E8D5C(bar[0x32], D_808008B0_scinfobar[item].unk_8, 0);
        }
        func_800E8D28(bar[0x32], scale);
    } else {
        bar[0x32] = 0;
    }
}

// Clear the deferred value, max and style.
void func_808000B0_scinfobar(void *bar)
{
    s16 zero;
    *(s16 *) ((s8 *) bar + 0x30) = 0;
    // Matching: the chained assignment through a local is needed for the match.
    *(s16 *) ((s8 *) bar + 0x2E) = (zero = *(s16 *) ((s8 *) bar + 0x30));
    *(s16 *) ((s8 *) bar + 0x2C) = zero;
}

// Finish the cross-fade: the next item becomes current and the deferred value, max and style apply.
void func_808000C4_scinfobar(u8 *bar)
{
    *(s16 *) (bar + 4) = *(s16 *) (bar + 6);
    *(s16 *) (bar + 6) = -1;
    bar[2] = 0;
    if (bar[0x32]) {
        func_800E8C08(bar[0x32]);
    }
    func_80800000_scinfobar(bar, *(s16 *) (bar + 4));
    scinfobar_entrypoint_8(bar, *(s16 *) (bar + 0x2C));
    scinfobar_entrypoint_9(bar, *(s16 *) (bar + 0x2E));
    scinfobar_entrypoint_3(bar, *(s16 *) (bar + 0x30));
    func_808000B0_scinfobar(bar);
}

// Enter a slide state (0x64 hidden, 0x65 opening, 0x66 shown, 0x67 closing).
void func_80800144_scinfobar(u8 *bar, s32 state)
{
    s32 style;

    if (state == bar[0]) {
        return;
    }
    if (bar[2] != 0 && bar[0] == bar[2]) {
        func_808000C4_scinfobar(bar);
    }
    bar[0] = state;
    switch (state) {
        case 0x65:
            style = bar[2] ? *(s16 *) (bar + 0x30) : *(s32 *) (bar + 0x1C);
            if (D_80800D58_scinfobar[style].get_frames != NULL) {
                scinfobar_entrypoint_10(bar, D_80800D58_scinfobar[style].get_frames());
            }
            break;
        case 0x66:
            *(f32 *) (bar + 0x14) = 1.0f;
        case 0x67:
            break;
        case 0x64:
            *(f32 *) (bar + 0x14) = 0.0f;
    }
}

// Allocate and initialise a bar for an item; starts hidden.
InfoBar *scinfobar_entrypoint_0(s32 item, s32 mode, s32 style)
{
    InfoBar *bar;
    bar = heap_alloc(sizeof(InfoBar));
    bar->state = 100;
    bar->pending = 0;
    bar->item = item;
    bar->next_item = -1;
    bar->mode = mode;
    bar->active = 0;
    bar->unk_A = 0;
    bar->slide = 0.0f;
    scinfobar_entrypoint_3((u8 *) bar, style);
    scinfobar_entrypoint_10(bar, 0xD8);
    bar->max_value = 0;
    bar->unk_28 = 0;
    bar->value = 0;
    func_808000B0_scinfobar(bar);
    func_80800000_scinfobar(bar, item);
    return bar;
}

void scinfobar_entrypoint_1(u8 *bar)
{
    u8 sprite = bar[0x32];
    if (sprite != 0) {
        func_800E8C08(sprite);
    }
    heap_free(bar);
}

// Advance the slide by delta time; switch to shown or hidden when it reaches the end.
void scinfobar_entrypoint_2(InfobarTransition *bar)
{
    f32 dt;
    dt = func_800D8FF8();
    switch (bar->state) {
        case 0x64:
        case 0x66:
            break;
        case 0x65:
            bar->slide += dt * bar->slide_speed;
            if (bar->slide > 1.0f)
                func_80800144_scinfobar(bar, 0x66);
            break;
        case 0x67:
            bar->slide -= dt * bar->slide_speed;
            if (bar->slide < 0.0f)
                func_80800144_scinfobar(bar, 0x64);
    }
    bar->unk_A = 0;
}

// Set the style (deferred while a cross-fade is pending) and load its slide rate from the table.
int scinfobar_entrypoint_3(bar, style)
u8 *bar;
s32 style;
{
    if (bar[2]) {
        *(s16 *) ((char *) bar + 0x30) = style;
    } else {
        *(s32 *) ((char *) bar + 0x1C) = style;
        *(f32 *) ((char *) bar + 0xC) =
            *(f32 *) ((char *) D_80800D5C_scinfobar + (style * 3) * 4);
    }
}

void scinfobar_entrypoint_4(s32 bar, s32 arg)
{
    // Matching: copying the parameters through locals is needed for the match.
    s32 addr = bar;
    s32 val = arg;
    *(s32 *) (addr + 0x28) = val;
}

void scinfobar_entrypoint_5(void *bar, s32 value)
{
    ((s8 *) bar)[10] = value;
}

// Show or hide the bar.
void scinfobar_entrypoint_6(u8 *bar, s32 show)
{
    if (show != 0) {
        if (*bar != 0x66) {
            func_80800144_scinfobar(bar, 0x65);
        }
    } else if (*bar != 0x64) {
        func_80800144_scinfobar(bar, 0x67);
    }
}

// Request a cross-fade to another item; returns 0 while one is already pending.
s32 scinfobar_entrypoint_7(u8 *bar, int item)
{
    u8 state;
    // Matching: the extra pointer temporary is needed for the match.
    s8 *next_item;
    if (*(u8 *) ((s8 *) bar + 2) != 0) {
        return 0;
    }
    if ((item == *(s16 *) ((s8 *) bar + 4)) || (item == *(s16 *) ((s8 *) bar + 6))) {
        return 1;
    }
    state = *(u8 *) ((s8 *) bar + 0);
    next_item = (s8 *) bar + 6;
    *(s16 *) next_item = item;
    if ((state == 0x66) || (state == 0x65)) {
        *(u8 *) ((s8 *) bar + 2) = 0x67U;
    } else {
        *(u8 *) ((s8 *) bar + 2) = 0x65U;
    }
    return 1;
}

// Set the value (deferred while a cross-fade is pending).
void scinfobar_entrypoint_8(bar, value) u8 *bar;
s32 value;
{

if (bar[2]) {
    *(s16 *) (bar + 0x2c) = value;
    return;
}

*(s32 *) (bar + 0x20) = value;

}

// Set the max value (deferred while a cross-fade is pending).
void scinfobar_entrypoint_9(bar, max_value) u8 *bar;
s32 max_value;
{
    if (bar[2]) {
        *(s16 *) (bar + 0x2E) = max_value;
        return;
    }

*(s32 *) (bar + 0x24) = max_value;
}

void scinfobar_entrypoint_10(bar, frames) InfoBarRateRecord *bar;
s32 frames;
{
    bar->unk_10 = (f32) frames / (24.0f * bar->unk_C);
    bar->frames = frames;
    bar->slide_speed = 250.0f / (f32) frames;
}

s32 scinfobar_entrypoint_11(u8 *bar)
{
    return (s32) (((f32) (*((s16 *) (((char *) bar) + 0x8)))) *
                  (*((f32 *) (((char *) bar) + 0x14))));
}

int scinfobar_entrypoint_12(bar)
s16 bar[5];
{
    return bar[4];
}

f32 scinfobar_entrypoint_13(void *bar)
{
    return ((f32 *) bar)[5];
}

int scinfobar_entrypoint_14(void *bar)
{
    return ((int *) bar)[0x28 / 4];
}

scinfobar_entrypoint_15(u8 *bar)
{
    return bar[1];
}

int scinfobar_entrypoint_16(bar)
s16 bar[5];
{
    return bar[2];
}

scinfobar_entrypoint_17(u8 *bar)
{
    return bar[10];
}

f32 scinfobar_entrypoint_18(Actor *bar)
{
    return (*(f32 *) ((char *) (bar) + 0xC));
}

int scinfobar_entrypoint_19(void *bar)
{
    return (*(s32 *) ((char *) (bar) + 0x20));
}

int scinfobar_entrypoint_20(void *bar)
{
    return (*(s32 *) ((char *) (bar) + 0x24));
}

// Whether the bar is hidden.
int scinfobar_entrypoint_21(u8 *bar)
{
    return bar[0] == 'd';
}

// Whether the bar is fully shown.
s32 scinfobar_entrypoint_22(u8 *bar)
{
    return (*bar) == 0x66;
}

// Whether the bar is opening.
s32 scinfobar_entrypoint_23(u8 *bar)
{
    u8 state = *bar;
    // Matching: the redundant masks and the copy through a local are needed for the match.
    s32 is_opening = (((((state & 0xFFFFFFFF) & 0xFFFFFFFF) & 0xFFFFFFFF) & 0xFFFFFFFF) &
                      (0xFFFFFFFF & 0xFF)) == 0x65;
    s32 result;
    result = is_opening;
    return result;
}

// Draw the icon of an item with the given alpha.
void func_80800608_scinfobar(s32 gfx, s32 item, s32 x, s32 y, s32 alpha,
                             s32 handle)
{
    InfoBarDialog *entry;
    s32 anim;

if (item >= 0 && item < 100 && item != 0) {
    entry = &((InfoBarDialog *) D_808008B0_scinfobar)[item];
    if (entry->scale != 0) {
        _fxdialog_entrypoint_2(entry->scale * (1.0f / 256.0f));
    }
    anim = handle ? func_800E8C58((u8) handle) : 0;
    _fxdialog_entrypoint_4(gfx, entry->icon, anim, (f32) entry->unk_2,
                           (f32) entry->unk_3, alpha, (u32) entry->unk_6 >> 15);
}

}

void func_808006EC_scinfobar(void *gfx, InfoBarDrawState *bar, s32 x, s32 y)
{
    _fxdialog_entrypoint_0();
    _fxdialog_entrypoint_1(x, y);
    _fxdialog_entrypoint_2(bar->unk_C);
    _fxdialog_entrypoint_3(gfx, bar->slide * bar->unk_8, bar->mode, 0xFF);
}

// Draw the bar: frame, per-style value renderer, then the icon (cross-fading when an item switch is pending).
void scinfobar_entrypoint_24(s32 gfx, u8 *bar, s32 x, s32 y)
{
    s32 alpha;
    s32 (*draw)(s32, u8 *, s32, s32);
    func_808006EC_scinfobar(gfx, bar, x, y);

if (bar[0] != 100) {
    draw = D_80800D54_scinfobar[*(s32 *) (bar + 0x1C)].draw;
    if (draw)
        draw(gfx, bar, x, y);
}

if (bar[2] && bar[0] == bar[2]) {
    alpha = *(f32 *) (bar + 0x14) * 255.0f;
    if (bar[2] == 101)
        alpha = 255 - alpha;
    func_80800608_scinfobar(gfx, *(s16 *) (bar + 4), x, y, alpha,
                            bar[0x32]);
    func_80800608_scinfobar(gfx, *(s16 *) (bar + 6), x, y, 255 - alpha, 0);
    return;
}

func_80800608_scinfobar(gfx, *(s16 *) (bar + 4), x, y, 255, bar[0x32]);
}

// TU-NOTE: the .data of this overlay is defined here in C (values from the ROM). Its tables hold
// pointers to functions of this file; IDO's assembler schedules some of them differently unless the
// tables are defined in the same unit. Linker symbols: D_80800D58_scinfobar = D_80800D54_scinfobar
// + 0x4, D_80800D5C_scinfobar = D_80800D54_scinfobar + 0x8.

extern void _sccustom_entrypoint_0();
extern void _sccustom_entrypoint_3();
InfoBarSound D_808008B0_scinfobar[99] = {
    0x0,   0x0, 0x0,   0x0,   0, 0xB50, 0x0, 0x0,   0x0,   0, 0xBE9, 0x0,    0x0,   0x0,   0,
    0xB81, 0x0, 0x0,   0x0,   0, 0xB83, 0x0, 0x0,   0x0,   0, 0xB82, 0x0,    0x0,   0x0,   0,
    0xB84, 0x0, 0x0,   0x0,   0, 0xB85, 0x0, 0x0,   0x0,   0, 0xBE6, 0x0,    0x0,   0x0,   0,
    0xB4A, 0x0, 0x0,   0x100, 0, 0xB4B, 0x0, 0x0,   0x100, 0, 0xBD0, 0x0,    0x0,   0x0,   0,
    0xBEA, 0x0, 0x0,   0x0,   0, 0xC06, 0x0, 0x0,   0x0,   0, 0xB4F, 0x0,    0x0,   0x200, 0,
    0xBAE, 0x0, 0x0,   0x0,   0, 0xB89, 0x0, 0x0,   0x0,   0, 0xBD9, 0x0,    0x0,   0x0,   0,
    0xB99, 0x0, 0x0,   0x0,   0, 0xBD3, 0x0, 0x0,   0x0,   0, 0xBD7, 0x0,    0x0,   0x0,   0,
    0xBD6, 0x0, 0x0,   0x0,   0, 0xBD4, 0x0, 0x0,   0x0,   0, 0xBD5, 0x0,    0x0,   0x0,   0,
    0xBD8, 0x0, 0x0,   0x0,   0, 0xBD2, 0x0, 0x0,   0x0,   0, 0xBD1, 0x0,    0x0,   0x0,   0,
    0xB98, 0x0, 0x0,   0x100, 0, 0xB86, 0x0, 0x0,   0x0,   0, 0xBA2, 0x0,    0x0,   0x0,   0,
    0xBAB, 0x0, 0x0,   0x0,   0, 0xC0D, 0x0, 0x0,   0x0,   0, 0xC0C, 0x0,    0x0,   0x0,   0,
    0xBBF, 0x0, 0x0,   0x0,   0, 0xC0E, 0x0, 0x0,   0x0,   0, 0xBE1, 0x0,    0x0,   0x0,   0,
    0xBC8, 0x0, 0x0,   0x0,   0, 0xBC7, 0x0, 0x0,   0x0,   0, 0xBC9, 0x0,    0x0,   0x0,   0,
    0xBDF, 0x0, 0x0,   0x0,   0, 0xBDE, 0x0, 0x0,   0x0,   0, 0x9C3, 0x0,    0x0,   0x0,   0,
    0xB6D, 0x0, 0x0,   0x0,   0, 0xB6C, 0x0, 0x0,   0x0,   0, 0xB6B, 0x0,    0x0,   0x0,   0,
    0xC04, 0x0, 0x0,   0x0,   0, 0xC02, 0x0, 0x0,   0x0,   0, 0xC03, 0x0,    0x0,   0x0,   0,
    0xC09, 0x0, 0x0,   0x0,   0, 0xC05, 0x0, 0x0,   0x0,   0, 0xBFF, 0x0,    0x0,   0x0,   0,
    0xBA4, 0x0, 0x0,   0x0,   0, 0xBAE, 0x0, 0x0,   0x0,   0, 0xB9E, 0x0,    0x0,   0x0,   0,
    0xC00, 0x0, 0x0,   0x0,   0, 0xC14, 0x0, 0x0,   0x0,   0, 0xB6E, 0x0,    0x0,   0x0,   0,
    0xB4E, 0x0, 0x232, 0x0,   0, 0xB4C, 0x0, 0x232, 0x0,   0, 0xBE7, 0x0,    0x0,   0x0,   0,
    0xBC6, 0x0, 0x0,   0x0,   0, 0xC07, 0x0, 0x0,   0x0,   0, 0xC08, 0x0,    0x0,   0x0,   0,
    0xC0B, 0x0, 0x0,   0x0,   0, 0xBED, 0x0, 0x0,   0x0,   0, 0xBCD, 0x0,    0x101, 0x0,   0,
    0xBDA, 0x0, 0x101, 0x0,   0, 0xBA8, 0x0, 0x101, 0x0,   0, 0xBA7, 0x0,    0x101, 0x0,   0,
    0xBE5, 0x0, 0x0,   0x0,   0, 0xBAA, 0x0, 0x101, 0x0,   0, 0xBA9, 0x0,    0x101, 0x0,   0,
    0xC1A, 0x0, 0x0,   0x0,   0, 0xC1C, 0x0, 0x0,   0x0,   0, 0xC1B, 0x0,    0x0,   0x0,   0,
    0xC16, 0x0, 0x0,   0x0,   0, 0xC15, 0x0, 0x0,   0x0,   0, 0xC13, 0x0,    0x0,   0x0,   0,
    0xC19, 0x0, 0x0,   0x0,   0, 0xC18, 0x0, 0x0,   0x0,   0, 0xC17, 0x0,    0x0,   0x0,   0,
    0xC06, 0x0, 0x0,   0x0,   0, 0xBA3, 0x0, 0x0,   0x0,   0, 0xBA1, -0xA00, 0x0,   0x0,   0,
    0xBE8, 0x0, 0x0,   0x0,   0, 0xC11, 0x0, 0x0,   0x0,   0, 0xBA2, 0x0,    0x1,   0x0,   0,
    0xB89, 0x0, 0x1,   0x0,   0, 0xB8B, 0x0, 0x1,   0x0,   0, 0xBD9, 0x0,    0x1,   0x0,   0,
    0xC00, 0x0, 0x1,   0x0,   0, 0xB50, 0x0, 0xE6,  0x0,   0, 0xB51, 0x0,    0xE6,  0x0,   0,
    0xB52, 0x0, 0xE6,  0x0,   0, 0xB53, 0x0, 0xE6,  0x0,   0, 0xB8B, 0x0,    0x0,   0x0,   0,
    0xB54, 0x0, 0x0,   0x0,   0, 0xB55, 0x0, 0x0,   0x0,   0, 0xB56, 0x0,    0x0,   0x0,   0};
InfobarDrawCallbacks D_80800D54_scinfobar[9] = {(void *) _sccustom_entrypoint_0,
                                                (u32) _sccustom_entrypoint_3,
                                                0x3F266666,
                                                (void *) 0x8008A658,
                                                -0x7FF75990,
                                                0x3F266666,
                                                (void *) 0x8008A928,
                                                -0x7FF756C8,
                                                0x3F266666,
                                                (void *) 0x8008A930,
                                                -0x7FF756C0,
                                                0x3F266666,
                                                (void *) 0x8008A678,
                                                -0x7FF75980,
                                                0x3F666666,
                                                (void *) 0x8008A908,
                                                -0x7FF756E8,
                                                0x3F666666,
                                                (void *) 0x8008A910,
                                                -0x7FF756E0,
                                                0x3F666666,
                                                (void *) 0x80085BA8,
                                                -0x7FF756C8,
                                                0x3F266666,
                                                (void *) 0x8008A650,
                                                -0x7FF75998,
                                                0x3F266666};
