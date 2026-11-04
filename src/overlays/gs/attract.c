// Attract-mode demo sequencer: demo playlists (map/exit plus demo index), started through the
// special-sequence mode, with a timer firing ch/attract events at 0.5/1/6 s. A button press ends it.
#include "common.h"

typedef struct {
    s16 id;
    s8 type;
    u8 flags;
    u8 count;
    u8 pad_1;
} AttractEntry_gsattract_entrypoint_1;
typedef struct {
    s16 id;
    u8 count;
    u8 pad_0;
    AttractEntry_gsattract_entrypoint_1 *entries;
    u8 flags;
    u8 pad_1[3];
} AttractMode_gsattract_entrypoint_1;
typedef struct {
    u8 mode;
    u8 entry;
    u8 pad_2[2];
    f32 timer;
} AttractState_gsattract_entrypoint_1;
typedef struct {
    s32 pad_0;
    AttractState_gsattract_entrypoint_1 state;
} AttractGlobal;
extern AttractMode_gsattract_entrypoint_1 D_80800490_gsattract[];
extern s32 func_800C95D4(void);
extern f32 func_800D9004(void);
extern s32 func_800167F4(void);
extern void _chattract_entrypoint_1(s32);
extern s32 func_80015FA0(s32);
extern void func_800A9C50(void);
extern u8 D_80135470[];
extern u8 D_80800493_gsattract[];
typedef struct {
    s16 id;
    s8 type;
    u8 pad_0;
    u8 count;
    u8 pad_1;
} AttractEntry_808002A4_gsattract;
typedef struct {
    s16 id;
    u8 count;
    u8 pad_0;
    AttractEntry_808002A4_gsattract *entries;
    s32 pad_1;
} AttractMode_808002A4_gsattract;
typedef struct {
    u8 mode;
    u8 entry;
} AttractState_808002A4_gsattract;
typedef struct {
    s16 id;
    s8 type;
    u8 pad_0;
    u8 count;
    u8 pad_1;
} AttractEntry_gsattract_entrypoint_5;
typedef struct {
    s16 id;
    u8 count;
    u8 pad_0;
    AttractEntry_gsattract_entrypoint_5 *entries;
    s32 pad_1;
} AttractMode_gsattract_entrypoint_5;
extern AttractGlobal D_8013546C;
extern s16 widescreen_enabled;
extern void func_800FE4E4(void);
extern void func_800A9B84(void);
void func_808002A4_gsattract();

void gsattract_entrypoint_0()
{
    *(f32 *) ((u8 *) (u8 *) &D_8013546C + 0x8) = 0.0f;
}

// Advances the demo timer and fires attract overlay events at 6.0 s, 0.5 s and 1.0 s;
// a button press ends the demo.
void gsattract_entrypoint_1(void)
{
    f32 prev;

    prev = (*(AttractState_gsattract_entrypoint_1 *) D_80135470).timer;
    if (func_800C95D4()) {
        (*(AttractState_gsattract_entrypoint_1 *) D_80135470).timer += func_800D9004();
    }
    if ((D_80800490_gsattract[(*(AttractState_gsattract_entrypoint_1 *) D_80135470).mode].flags &
         1) &&
        6.0f <= (*(AttractState_gsattract_entrypoint_1 *) D_80135470).timer && prev < 6.0f) {
        _chattract_entrypoint_1(func_800167F4() ? 3 : 1);
    }
    if ((D_80800490_gsattract[(*(AttractState_gsattract_entrypoint_1 *) D_80135470).mode].flags &
         2) &&
        0.5f <= (*(AttractState_gsattract_entrypoint_1 *) D_80135470).timer && prev < 0.5f) {
        _chattract_entrypoint_1(2);
    }
    if ((D_80800490_gsattract[(*(AttractState_gsattract_entrypoint_1 *) D_80135470).mode]
             .entries[(*(AttractState_gsattract_entrypoint_1 *) D_80135470).entry]
             .flags &
         1) &&
        1.0f <= (*(AttractState_gsattract_entrypoint_1 *) D_80135470).timer && prev < 1.0f) {
        _chattract_entrypoint_1(0);
    }
    if (func_800C95D4() && func_80015FA0(0)) {
        func_800A9C50();
    }
}

void gsattract_entrypoint_2(s32 arg0)
{
}

// Starts the next demo of the playlist, wrapping around at the end.
void gsattract_entrypoint_3(void)
{
    s32 next_entry;

    if (func_800A8264() == 0) {
        next_entry = D_80135470[1] + 1;
        if (next_entry >= D_80800493_gsattract[D_80135470[0] * 12]) {
            next_entry = 0;
        }
        func_808002A4_gsattract(next_entry);
    }
}

void gsattract_entrypoint_4(void)
{
    s32 mode = 2;
    ((u8 *) &D_8013546C)[4] = mode;
}

// Selects a playlist and restarts it at the first entry.
void func_80800274_gsattract(s32 mode)
{
    D_80135470[0] = mode;
    D_80135470[1] = D_80800493_gsattract[(u8) mode * 12];
}

// Starts the demo entry of the current playlist.
void func_808002A4_gsattract(entry_index) s32 entry_index;
{
    AttractEntry_808002A4_gsattract *entry;
    AttractState_808002A4_gsattract *state;
    state = (AttractState_808002A4_gsattract *) D_80135470;
    state->entry = entry_index;
    entry =
        &((AttractMode_808002A4_gsattract *) D_80800490_gsattract)[state->mode].entries[entry_index];
    // Negative type: plain warp instead of a demo.
    if (entry->type < 0) {
        func_800A791C(entry->id, 1, 1);
    } else {
        func_800D3A14(entry->count);
        func_800A9BA0(2, entry->id, entry->type);
    }
}

void gsattract_entrypoint_5(s32 mode)
{
    AttractMode_gsattract_entrypoint_5 *playlist;
    if (!func_800A8264()) {
        // Widescreen always uses playlist 1.
        if (widescreen_enabled)
            mode = 1;
        if (mode != D_8013546C.state.mode)
            func_80800274_gsattract(mode);
        func_800FE4E4();
        func_800A9B84();
        playlist =
            &((AttractMode_gsattract_entrypoint_5 *) D_80800490_gsattract)[D_8013546C.state.mode];
        func_800A9B8C(playlist->id, playlist->count);
        gsattract_entrypoint_3();
    }
}

// TU-NOTE: the .data of this overlay is defined here in C; values are taken from the ROM.
// D_80800493_gsattract = D_80800490_gsattract + 0x3 and D_80800494_gsattract = D_80800490_gsattract + 0x4
// are linker symbols.
u32 D_808003D0_gsattract[24] = {0x14F0801, 0x1000116, 0x7000100, 0x13A0800, 0xD00018B, 0xFF000000,
                                0xEB0501,  0x1000128, 0x8000100, 0xB90700,  0xD00018B, 0xFF000000,
                                0x11A0801, 0x1000108, 0x8000700, 0xE60800,  0xD00018B, 0xFF000000,
                                0xF40701,  0xB000114, 0x6001200, 0x1A70800, 0xD00018B, 0xFF000000};
u32 D_80800430_gsattract[24] = {0x14F0701, 0x1000116, 0x5000100, 0x13A0700, 0xD00018B, 0xFF000000,
                                0xEB0601,  0x1000128, 0x7000100, 0xB90600,  0xD00018B, 0xFF000000,
                                0x11A0401, 0x1000108, 0x7000700, 0xE60700,  0xD00018B, 0xFF000000,
                                0xF40501,  0xB000114, 0x3001200, 0x1A70600, 0xD00018B, 0xFF000000};
AttractMode_gsattract_entrypoint_1 D_80800490_gsattract[2] = {
    0x158, 0x1, 0x10, (void *) &D_808003D0_gsattract, 0x1, 0x0, 0x0, 0x0,
    0x158, 0x1, 0x10, (void *) &D_80800430_gsattract, 0x1, 0x0, 0x0, 0x0};
