#include "ch/introtext.h"

extern u32 D_808007D0_chintrotext[];
typedef struct {
    s16 count;
    u8 pad_0[0x14];
    s16 starts[9];
    s16 styles[9];
} IntroText30;
extern void _fxkern_entrypoint_3(f32);
typedef struct {
    f32 vals[4];
} local_struct;
extern local_struct D_808007A4_chintrotext[];
extern local_struct D_808007A8_chintrotext[];
extern void _chbaddiesetup_entrypoint_4(void *param_0, s32 param_1, s32 param_2, s32 param_3,
                                        s32 param_4);
extern int func_800A9C98(void);
extern void *_chintrotext_entrypoint_3;
typedef struct {
    u8 pad_0[0x3E];
    u8 style;
    u8 timing_idx;
} IntroTextPlacement;
extern void func_800EFD24(f32 *);
extern Actor *func_80108474(u32, f32 *, s32);
extern void *func_80100094(Actor *, u32);
extern void *func_80100074(Actor *, u32, u32);
extern char *_gldbstring_entrypoint_1();
extern s32 func_800E7188();
extern void func_800E715C();
extern void _gldbstring_entrypoint_2(s32);
typedef struct {
    s16 line_count;
    s16 line_y[30];
    u8 style;
    u8 timing_idx;
} IntroTextState;
typedef struct {
    f32 fade_in, hold, fade_out;
    s32 line_height;
} IntroTextTiming;
extern IntroTextTiming D_808007A0_chintrotext[];
extern void func_80105834(), func_80107C2C(), func_8080000C_chintrotext(),
    func_80800130_chintrotext(), func_808003EC_chintrotext();

int chintrotext_entrypoint_0()
{
    return (int) &D_808007D0_chintrotext;
}

// Splits the string into up to 9 lines at newlines; a hash char marks the small font style.
void func_8080000C_chintrotext(actor) Actor *actor;
{
    IntroText30 *info;
    u8 *text;
    s32 i;
    s32 j;
    text = func_80100094(actor, 0);
    info = func_80100094(actor, 1);
    info->starts[0] = 0;
    info->count = 1;
    info->styles[1] = 0xC26;
    for (i = 0; text[i]; i++) {
        if (text[i] == '#') {
            for (j = i + 1; text[j]; j++)
                text[j - 1] = text[j];
            text[j - 1] = 0;
            info->styles[info->count] = 0xC25;
        }
        if (text[i] == '\n') {
            info->starts[info->count] = i + 1;
            info->styles[info->count + 1] = 0xC26;
            info->count++;
            text[i] = 0;
            if (info->count == 9)
                break;
        }
    }
    func_800DA544(0x6AD);
}

void func_80800130_chintrotext(s32 arg0)
{
    func_800DA524(FLAG2_6AD_CURRENTLY_SHOWING_INTROTEXT);
}

void func_8080051C_chintrotext();

// Intro text state machine: 1 lays out the lines, 3 fades in, 4 holds, 5 fades out.
void func_80800154_chintrotext(Actor *actor)
{
    extern u8 func_800D9078(f32 *);
    extern f32 func_800F12D4(f32, f32, f32, f32, f32);
    IntroTextState *state;
    s32 timer_done;
    s32 line_height;
    IntroTextState *state2;
    s32 style;
    s32 start_y;
    s32 i;
    state = (IntroTextState *) func_80100094(actor, 1);
    timer_done = func_800D9078(&actor->unk58);
    line_height = D_808007A0_chintrotext[state->timing_idx].line_height;
    switch (actor->unk70_10) {
        case 1:
            // Matching: needed for the match.
            state2 = (IntroTextState *) func_80100094(actor, 1);
            style = state2->style;
            switch (style) {
                case 0:
                    start_y = (228 - state2->line_count * line_height) >> 1;
                    start_y += 2.5f * line_height;
                    break;
                case 1:
                    start_y = (114 - state2->line_count * line_height) >> 1;
                    break;
                case 2:
                    start_y = (228 - state2->line_count * line_height) >> 1;
                    break;
                default:;
            }
            for (i = 0; i < state2->line_count; i++) {
                state2->line_y[i] = start_y + i * line_height;
            }
            func_8080051C_chintrotext(actor, 2);
            break;
        case 2:
            func_800DA544(0x6AD);
            if (!func_800C954C()) {
                func_8080051C_chintrotext(actor, 3);
            }
            break;
        case 3:
            func_800DA544(0x6AD);
            _subaddiefade_entrypoint_1(
                actor,
                (s32) func_800F12D4(actor->unk58, 0.0f,
                                    D_808007A0_chintrotext[state->timing_idx].fade_in, 255.0f, 0));
            if (timer_done) {
                func_8080051C_chintrotext(actor, 4);
            }
            break;
        case 4:
            func_800DA544(0x6AD);
            if (timer_done) {
                func_8080051C_chintrotext(actor, 5);
            }
            break;
        case 5:
            _subaddiefade_entrypoint_1(
                actor, (s32) func_800F12D4(actor->unk58, 0,
                                             D_808007A0_chintrotext[state->timing_idx].fade_out, 0.0f,
                                             255.0f));
            if (timer_done) {
                func_800FFAB0(actor);
            }
    }
}

// Draws the lines with the kerned font; small-style lines are scaled to 0.75.
void func_808003EC_chintrotext(actor, gfx) Actor *actor;
s32 gfx;
{
    s16 *state;
    s16 *line;
    s32 i;

    state = func_80100094(actor, 1);
    if ((s32) actor->unk70_10 >= 3 && func_800A819C()) {
        _fxkern_entrypoint_2();
        func_800B8C8C(_subaddiefade_entrypoint_0(actor));
        for (i = 0, line = state; i < *state; i++, line++) {
            func_800B8CE0(line[21]);
            _fxkern_entrypoint_3(line[21] == 0xC25 ? 0.75f : 1.0f);
            _fxkern_entrypoint_1(gfx, line[1],
                                 func_800E71B8((u8 *) func_80100094(actor, 0) + line[11]));
        }
    }
}

// Enters a state and loads its timer.
void func_8080051C_chintrotext(Actor *actor, s32 new_state)
{
    s32 state;

    state = func_80100094(actor, 1);
    func_80101FDC(actor, new_state);
    switch (new_state) {
        case 2:
            _subaddiefade_entrypoint_1(actor, 0, new_state);
            func_800DA544(0x6AD);
            return;
        case 3:
            actor->unk58 =
                ((local_struct *) D_808007A0_chintrotext)[*(u8 *) (state + 0x3F)].vals[0];
            return;
        case 4:
            actor->unk58 = D_808007A4_chintrotext[*(u8 *) (state + 0x3F)].vals[0];
            return;
        case 5:
            func_800DA524(0x6AD);
            actor->unk58 = D_808007A8_chintrotext[*(u8 *) (state + 0x3F)].vals[0];
    }
}

// Spawns the intro text unless a special sequence is active.
int chintrotext_entrypoint_1(s32 param_0, s32 param_1, s32 param_2, s32 param_3)
{
    if (!func_800A9C98()) {
        _chbaddiesetup_entrypoint_4(&_chintrotext_entrypoint_3, param_0, param_1, param_3, param_2);
    }
}

// Spawns the intro text of the current map; returns 1 if one was spawned.
s32 chintrotext_entrypoint_2(s32 param_0)
{
    s32 text_id;
    s32 style;
    s32 result;

    result = _gcintrotext_entrypoint_2(-1, &text_id, &style);
    if ((result != -1) && ((param_0 != 0) || (result > 0))) {
        chintrotext_entrypoint_1(text_id, style, 0, 0);
        return 1;
    }
    return 0;
}

void chintrotext_entrypoint_3(param_0, param_1, param_2, param_3) s32 param_0;
s16 param_1;
s32 param_2;
s32 param_3;
{
    f32 pos[3];
    Actor *actor;
    IntroTextPlacement *placement;
    char *text;

    func_800EFD24(pos);
    actor = func_80108474(0x3B0, pos, 0);
    if (actor) {
        placement = func_80100094(actor, 1);
        text = _gldbstring_entrypoint_1(_gldbstring_entrypoint_0(0, param_0), param_1);
        func_80100074(actor, 0, func_800E7188(text) + 1);
        func_800E715C(func_80100094(actor, 0), text);
        _gldbstring_entrypoint_2(param_0);
        placement->style = param_2;
        placement->timing_idx = param_3;
    }
}

// TU-NOTE: the .data of this overlay is defined here in C. Its tables hold pointers to functions
// of this file; IDO's assembler schedules some of these functions differently unless the tables
// are in the same unit. Values are taken from the ROM. Linker symbols inside an object:
// D_808007A4_chintrotext = D_808007A0_chintrotext + 0x4, D_808007A8_chintrotext = D_808007A0_chintrotext + 0x8.
IntroTextTiming D_808007A0_chintrotext[3] = {0.4f, 2.4f, 0.6f, 0x19, 0.4f, 2.4f,
                                             0.6f, 0x19, 2.5f, 3.5f, 2.5f, 0x14};
u32 D_808007D0_chintrotext[20] = {0x31503B0,
                                  0xFFFF0001,
                                  0x0,
                                  (u32) func_80800154_chintrotext,
                                  (u32) func_80105834,
                                  (u32) func_808003EC_chintrotext,
                                  0x0,
                                  0x0,
                                  0x0,
                                  0x8400404,
                                  (u32) func_80800130_chintrotext,
                                  0x0,
                                  0x40,
                                  (u32) func_8080000C_chintrotext,
                                  (u32) func_80107C2C,
                                  0x80000002,
                                  0x0,
                                  0x0,
                                  0x0,
                                  0x0};
