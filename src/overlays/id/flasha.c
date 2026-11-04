#include "common.h"

typedef struct {
    s16 level;
    s16 peak;
    s32 flash_count;
    s32 burst_size;
    s32 state;
    f32 timer;
    f32 duration;
} FlashCycleState;
extern f32 func_800DC264(f32, f32);
extern f32 func_800D8FF8(void);
extern s32 func_800F1574(f32 *, f32);
extern void _idflasha_entrypoint_0(void);

// Kernel: writes the flash level into the alpha byte of each vertex.
void idflasha_entrypoint_0(s32 param_0, u32 src, u8 *dst, s32 count, s16 *level_ptr)
{
    u32 end;
    s32 alpha;

    alpha = *level_ptr;
    end = src + count * 0x10;
    while (src < end) {
        src += 0x10;
        dst += 0x10;
        dst[-1] = alpha;
    }
}

// State 1 starts a flash with a random peak; state 0 schedules the next flash or burst.
void func_80800038_idflasha(flash, new_state) FlashCycleState *flash;
s32 new_state;
{
    f32 time;

    if (new_state == 1) {
        flash->level = 0;
        flash->peak = func_800DC214(200, 255);
        flash->flash_count++;
        time = func_800DC264(0.08f, 0.12f);
        flash->timer = time;
        flash->duration = time;
    }
    if (new_state == 0) {
        flash->level = 0;
        if (flash->flash_count > 0 && flash->flash_count < flash->burst_size) {
            flash->timer = func_800DC264(0.1f, 0.2f);
        } else {
            flash->flash_count = 0;
            flash->burst_size = func_800DC214(1, 4);
            flash->timer = func_800DC264(4.0f, 6.0f);
        }
    }
    flash->state = new_state;
}

// Returns the current flash level.
s32 idflasha_entrypoint_1(s16 *state)
{
    s16 level;
    level = *state;
    return level;
}

void idflasha_entrypoint_2(s32 arg0)
{
}

void idflasha_entrypoint_3(void *state, s32 param_1, s32 param_2, s32 param_3)
{
    int idx;
    void *self;
    *(u16 *) ((char *) state + 0x0) = 0;

    ((s32 *) state)[1] = 0;
    // Matching: idx is used both as value and as index.
    idx = 2;
    ((s32 *) state)[idx] = idx;
    ((s32 *) state)[3] = 0;
    self = state;
    func_80800038_idflasha(self, 0);
}

// Counts down the idle/flash timers, fades the level in and out, then runs the kernel.
void idflasha_entrypoint_4(u8 *state, s32 param_1, s32 param_2)
{
    f32 dt;

    f32 duration;

    dt = func_800D8FF8();
    if (*(s32 *) (state + 0xC) == 0 && func_800F1574((f32 *) (state + 0x10), dt)) {
        func_80800038_idflasha(state, 1);
    }
    if (*(s32 *) (state + 0xC) == 1) {
        if (*(f32 *) (state + 0x10) <= 0.04f) {
            *(s16 *) state =
                (s32) ((f32) *(s16 *) (state + 2) * (*(f32 *) (state + 0x10) / 0.04f));
        } else {
            duration = *(f32 *) (state + 0x14);
            if (*(f32 *) (state + 0x10) < duration - 0.04f) {
                *(s16 *) state = *(s16 *) (state + 2);
            } else {
                *(s16 *) state = (s32) ((f32) *(s16 *) (state + 2) *
                                          ((duration - *(f32 *) (state + 0x10)) / 0.04f));
            }
        }
        if (func_800F1574((f32 *) (state + 0x10), dt)) {
            func_80800038_idflasha(state, 0);
        }
    }
    _glid_entrypoint_0(param_1, param_2, _idflasha_entrypoint_0, state);
}
