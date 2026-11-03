#include "core2/1E6E870.h"
#include "types.h"

#define STATE(p) (*(LocalEntry **) ((u8 *) (p) + 0x78))
f32 func_800A0C2C(void *param_0);
f32 func_800A0C38(void *param_0);
extern void func_800A0D74(s32, f32);
extern void func_800A0D84(s32, f32);
typedef struct {
    f32 duration;
    u8 state;
    u8 pad_5[3];
} Struct8009518CElement;
typedef struct {
    u8 pad_0[0x78];
    Struct8009518CElement *channels;
} Struct8009518C;
typedef struct {
    f32 duration;
    u8 state;
    u8 pad[3];
} LocalEntry;
extern f32 func_800D8FF8(void);

s32 func_80094F80(void)
{
    return 0x20;
}

// Returns the current eyelid value of a channel (only 0 and 1 are wired up).
f32 func_80094F88(void *player, s32 channel)
{
    switch (channel) {
        case 0:
            return func_800A0C2C(player);
        case 1:
            return func_800A0C38(player);
        case 2:
            return 0.0f;
        case 3:
            return 0.0f;
        default:
            return 0.0f;
    }
}

// Writes the eyelid value of a channel (only 0 and 1 are wired up).
void func_80095004(s32 player, s32 channel, f32 value)
{
    switch (channel) {
        case 0:
            func_800A0D74(player, value);
            break;

        case 1:
            func_800A0D84(player, value);

        case 2:
        case 3:
            break;
    }
}

// Resets all four channels to fully open (1.0), idle.
void func_80095068(u8 *player)
{
    s32 i;

    for (i = 0; i != 4; i++) {
        *(f32 *) (*(u8 **) (player + 0x78) + i * 8) = 1.0f;
        *(u8 *) (*(u8 **) (player + 0x78) + i * 8 + 4) = 0;
        func_80095004(player, i, 0.0f);
    }
}

// Starts a channel in state 1 (close) with the given duration.
void func_800950FC(u8 *player, s32 channel, f32 duration)
{
    s32 offset;

    offset = channel * 8;
    *(u8 *) ((u8 *) *(s32 *) ((u8 *) player + 0x78) + offset + 4) = 1;
    *(f32 *) ((u8 *) *(s32 *) ((u8 *) player + 0x78) + offset) = duration;
}

// Starts a channel in state 5 (close and stay) with the given duration.
void func_80095124(u8 *player, s32 channel, f32 duration)
{
    s32 offset;

    offset = channel * 8;
    *(s8 *) ((s8 *) (*(s32 *) ((s8 *) player + 0x78) + offset) + 4) = 5;
    *(f32 *) (s8 *) (*(s32 *) ((s8 *) player + 0x78) + offset) = duration;
}

void func_8009514C(PlayerState *player)
{
    func_80095124(player, 0, 0.09f);
    func_80095124(player, 1, 0.09f);
}

// Starts a channel in state 4 (open) with the given duration.
int func_8009518C(void *player, s32 channel, f32 duration)
{
    ((Struct8009518C *) player)->channels[channel].state = 4;
    ((Struct8009518C *) player)->channels[channel].duration = duration;
}

void func_800951B4(PlayerState *player)
{
    func_8009518C(player, 0, 0.034f);
    func_8009518C(player, 1, 0.034f);
}

// Per-frame update of the four blink channels.
void func_800951F4(void *player)
{
    s32 i;
    s32 offset;
    f32 delta_time;
    f32 value;
    LocalEntry *entry;
    delta_time = func_800D8FF8();
    i = 0;
    offset = 0;
    do {
        value = func_80094F88(player, i);
        entry = (LocalEntry *) ((u8 *) STATE(player) + offset);
        switch (entry->state) {
            case 1:
                value += delta_time / entry->duration;
                if (value > 1.0f) {
                    value = 1.0f;
                    entry->state = 2;
                }
                func_80095004(player, i, value);
                break;
            case 2:
                entry->state = 3;
                break;
            case 3:
            case 4:
                value -= delta_time / entry->duration;
                if (value < 0.0f) {
                    value = 0.0f;
                    entry->state = 0;
                }
                func_80095004(player, i, value);
                break;
            case 5:
                value += delta_time / entry->duration;
                if (value > 1.0f) {
                    value = 1.0f;
                    entry->state = 0;
                }
                func_80095004(player, i, value);
            case 0:
                break;
        }
        i++;
        offset += 8;
    } while (i != 4);
}
