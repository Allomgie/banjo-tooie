// Probably the blinking-fuse pulse of the Detonator (TNT) state: a timer ramping up and down
// between 0 and a period, plus a normalised 0..1 getter.
#include "common.h"

extern void func_800F10B4(f32, f32, s32, f32, f32);
typedef struct {
    u8 descending;
    u8 pad_0[3];
    f32 period;
    f32 value;
} PlayerPulseState;
typedef struct {
    u8 pad_0[0xE8];
    PlayerPulseState *pulse;
} PlayerPulseOwner;
extern f32 func_800D8FF8(void);
extern f32 func_800F13C4(f32, f32);

s32 bapulse_entrypoint_0()
{
    return 0xC;
}

// Normalised pulse value (0..1).
void bapulse_entrypoint_1(u8 *player)
{
    u8 *state = *(u8 **) (player + 0xE8);
    func_800F10B4(*(f32 *) (state + 8), 0.0f, *(s32 *) (state + 4), 0.0f, 1.0f);
}

void bapulse_entrypoint_2(s32 arg0)
{
}

// Resets the pulse to ramp up from the given value.
void bapulse_entrypoint_3(void *player, float value, float period)
{
    *(s8 *) ((char *) *(void **) ((char *) player + 0xE8) + 0) = 0;
    *(float *) ((char *) *(void **) ((char *) player + 0xE8) + 8) = value;
    *(float *) ((char *) *(void **) ((char *) player + 0xE8) + 4) = period;
}

// Ramps the value between 0 and period, flipping direction at each end.
void bapulse_entrypoint_4(PlayerPulseOwner *player)
{
    f32 dt;
    f32 value;

    dt = func_800D8FF8();
    if (!player->pulse->descending) {
        player->pulse->value += dt;
        value = player->pulse->value;
        if (value >= player->pulse->period) {
            player->pulse->value =
                player->pulse->period - func_800F13C4(value, player->pulse->period);
            player->pulse->descending = 1;
        }
    } else {
        player->pulse->value -= dt;
        value = player->pulse->value;
        if (value < 0.0f) {
            player->pulse->value = func_800F13C4(-value, player->pulse->period);
            player->pulse->descending = 0;
        }
    }
}
