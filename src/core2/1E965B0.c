#include "core2/1E965B0.h"
#include "overlays/ba/playerstate.h"
#include "memory.h"

typedef struct {
    u32 timestamp : 31;
    u32 pressed : 1;
} ButtonState;

typedef struct {
    ButtonState data[BUTTON_COUNT];
} ButtonData;

// Ring of ButtonData snapshots directly after the header. Each entry stores the
// counter value at which a button changed state and whether it is now pressed.
#define GET_BUTTON_DATA(x) ((ButtonData *) &(x)[1])

// Current analog stick values (two axes), stored right after the ring.
#define GET_ANALOG_STICK_VALUES(x) ((f32 *) &GET_BUTTON_DATA(x)[(x)->unk4])

static ButtonData *__get_button_data_ptr(unkfunc_800BCE84 *history, s32 slot)
{
    return &GET_BUTTON_DATA(history)[slot];
}

static f32 *__get_stick_data_ptr(unkfunc_800BCE84 *history)
{
    return GET_ANALOG_STICK_VALUES(history);
}

u8 func_800BCCF4(unkfunc_800BCE84 *history)
{
    return history->controller_index;
}

s32 func_800BCCFC(unkfunc_800BCE84 *history, ButtonId button, s32 frames_ago)
{
    frames_ago = history->unk4 - frames_ago;
    frames_ago += history->unk8[button];
    frames_ago %= history->unk4;

    return __get_button_data_ptr(history, frames_ago)->data[button].pressed;
}

u32 func_800BCD78(unkfunc_800BCE84 *history, ButtonId button, s32 idx)
{
    s32 frames_ago;
    u32 start_time;
    u32 end_time;

    frames_ago = idx;

    // Matching: empty loop needed for the match.
    do {
    } while (0);

    idx = history->unk4 - idx;
    idx += history->unk8[button];
    idx %= history->unk4;

    start_time = __get_button_data_ptr(history, idx)->data[button].timestamp;
    if (frames_ago == 0) {
        end_time = history->counter;
    } else {
        end_time = __get_button_data_ptr(history, (idx + 1) % history->unk4)->data[button].timestamp;
    }

    return end_time - start_time;
}

s32 func_800BCE84(unkfunc_800BCE84 *history, ButtonId button)
{
    return __get_button_data_ptr(history, history->unk8[button])->data[button].pressed;
}

// Time since released
s32 func_800BCEC0(unkfunc_800BCE84 *history, ButtonId button)
{
    ButtonData *snapshot;

    snapshot = __get_button_data_ptr(history, history->unk8[button]);
    if (snapshot->data[button].pressed) {
        return 0;
    }
    return history->counter - snapshot->data[button].timestamp;
}

// Time since pressed
s32 func_800BCF28(unkfunc_800BCE84 *history, ButtonId button)
{
    ButtonData *snapshot;

    snapshot = __get_button_data_ptr(history, history->unk8[button]);
    if (!snapshot->data[button].pressed) {
        return 0;
    }
    return history->counter - snapshot->data[button].timestamp;
}

// Get joystick values
void func_800BCF90(unkfunc_800BCE84 *history, f32 *joystick_values_out)
{
    f32 *joystick_values;

    joystick_values = __get_stick_data_ptr(history);
    joystick_values_out[0] = joystick_values[0];
    joystick_values_out[1] = joystick_values[1];
}

int func_800BCFC4(unkfunc_800BCE84 *history, ButtonId button)
{
    ButtonData *snapshot;

    snapshot = __get_button_data_ptr(history, history->unk8[button]);
    return !snapshot->data[button].pressed && (history->counter - snapshot->data[button].timestamp) == 1;
}

int func_800BD030(unkfunc_800BCE84 *history, ButtonId button)
{
    ButtonData *snapshot;

    snapshot = __get_button_data_ptr(history, history->unk8[button]);
    return snapshot->data[button].pressed && (history->counter - snapshot->data[button].timestamp) == 1;
}

void func_800BD09C(unkfunc_800BCE84 *history)
{
    heap_free(history);
}

unkfunc_800BCE84 *func_800BD0BC(unkfunc_800BCE84 *history)
{
    return (unkfunc_800BCE84 *) defrag(history);
}

unkfunc_800BCE84 *func_800BD0DC(s32 count)
{
    unkfunc_800BCE84 *ret = (unkfunc_800BCE84 *) heap_alloc(
        sizeof(unkfunc_800BCE84) + sizeof(ButtonData) * count + sizeof(f32) *2);
    ret->counter = 0x64;
    ret->controller_index = 0xFF;
    ret->unk5 = 0;
    ret->unk4 = count;
    func_800BD138(ret);
    return ret;
}

void func_800BD138(unkfunc_800BCE84 *history)
{
    s32 i;
    s32 j;
    ButtonData *cur_data;

    for (i = 0; i < BUTTON_COUNT; i++) {
        history->unk8[i] = 0;
        history->unk16[i] = 0;
    }

    // Clear every button data buffer.
    cur_data = GET_BUTTON_DATA(history);
    for (i = 0; i < history->unk4; i++) {
        for (j = 0; j < BUTTON_COUNT; j++) {
            cur_data->data[j].pressed = 0;
            cur_data->data[j].timestamp = 0;
        }
        cur_data++;
    }

    // cur_data now points at the stick values after the ring; clear them.
    ((f32 *) cur_data)[0] = ((f32 *) cur_data)[1] = 0.0f;
}

void func_800BD268(unkfunc_800BCE84 *history, s32 controller)
{
    history->controller_index = controller;
    func_800BD28C(history, 2);
}

void func_800BD28C(unkfunc_800BCE84 *history, s32 mode)
{
    s32 i;
    history->unk5 = mode;
    if (mode == 1) {
        for (i = 0; i < BUTTON_COUNT; i++) {
            history->unk16[i] = 0;
        }
    }
}

// Per-frame update
void func_800BD2D0(unkfunc_800BCE84 *history)
{
    s32 i;
    s32 j;
    s32 controller;
    ButtonData *prev_data;
    s32 was_pressed;
    s32 is_pressed;
    s32 states[BUTTON_COUNT];

    if (history->unk5 == 2) {
        controller = history->controller_index;
        states[BUTTON_START] = func_80015F84(history->controller_index);
        func_80015F28(controller, &states[BUTTON_Z]); // shoulder buttons
        func_80015FFC(controller, &states[BUTTON_D_UP]); // d-pad
        func_80015E80(controller, &states[BUTTON_A]); // face buttons
        for (i = 0; i < BUTTON_COUNT; i++) {
            prev_data = __get_button_data_ptr(history, history->unk8[i]);
            is_pressed = states[i] ? 1 : 0;
            was_pressed = prev_data->data[i].pressed;
            if (is_pressed ^ was_pressed) {
                history->unk8[i]++;
                history->unk8[i] %= history->unk4;
                prev_data = __get_button_data_ptr(history, history->unk8[i]);
                prev_data->data[i].timestamp = history->counter;
                prev_data->data[i].pressed = is_pressed;
            }
        }
        func_80016068(controller, __get_stick_data_ptr(history));
    } else if (history->unk5 == 1) {
        for (j = 0; j < BUTTON_COUNT; j++) {
            if (history->unk16[j] != 0) {
                s32 old_state = __get_button_data_ptr(history, history->unk8[j])->data[j].pressed;
                history->unk16[j]--;
                if (!history->unk16[j]) {
                    history->unk8[j] = history->unk8[j] + 1;
                    history->unk8[j] %= history->unk4;
                    prev_data = __get_button_data_ptr(history, history->unk8[j]);
                    prev_data->data[j].timestamp = history->counter;
                    prev_data->data[j].pressed = old_state ^ 1;
                }
            }
        }
    }
    history->counter++;
}
