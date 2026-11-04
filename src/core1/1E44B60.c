// Synth voice filter stage: resample pull plus per-voice low-pass and pole filters, param handler.
#include "common.h"

typedef struct {
    u32 w0;
    u32 w1;
} TTAcmd;
typedef struct {
    u8 pad0[0x8C];
    u8 delay; // 0x8C: reverb/filter delay amount
    u8 pad8D[5];
    s16 filter_gain;
    u8 pad94[0x24];
    u32 dirty;
    void *pole_state;
} TTRvb;
typedef struct {
    s16 unk_0;
} TTRParam;
extern TTAcmd *func_8002D450(TTRvb *, TTRParam *, TTAcmd *);
extern void func_80028C04(void *, f32);
typedef struct {
    u8 pad0[0x8C];
    u8 delay; // 0x8C: reverb/filter delay amount
    u8 pad8D[3];
    s16 filter_cutoff;
    s16 filter_gain;
    u8 pad94[0x24];
    s32 dirty;
} TTVoiceE;
extern void func_8002CC9C(TTVoiceE *, s32, s32);

// Resample pull, then per-voice low-pass/delay and pole filter commands.
TTAcmd *func_8002D030(TTRvb *state, TTRParam *param, s32 arg2, TTAcmd *list)
{
    TTAcmd *cmd = list;
    f32 pitch;
    TTAcmd *lowpass;
    TTAcmd *coef;
    TTAcmd *polef;

    cmd = func_8002D450(state, param, list);

    if (state->delay != 0 && state->delay < 0x40) {
        if (state->delay >= 6)
            pitch = 26755.0f / sqrtf((f32) state->delay + 1.0f);
        else
            pitch = 65536.0f / ((f32) state->delay + 1.0f);

        if (pitch < 7723.0f)
            pitch = 7723.0f;

        lowpass = cmd++;
        lowpass->w0 = param->unk_0 & 0xFFFF;
        lowpass->w1 = (((u32) pitch & 0xFFFF) << 16) | ((state->delay + 1) & 0xFFFF);
    }

    if (state->filter_gain > 0) {
        // Recompute the filter coefficients at 22050 Hz when dirty.
        if (state->dirty != 0)
            func_80028C04(&((u8 *) state)[0x90], 22050.0f);

        coef = cmd++;
        coef->w0 = 0x0B000020;
        coef->w1 = osVirtualToPhysical(&((u8 *) state)[0x98]);

        if (state->dirty == 2)
            state->dirty = 0;

        polef = cmd++;
        polef->w0 = (param->unk_0 & 0xFFFF) | (((state->dirty & 0xFF) << 16) | 0x0E000000);
        polef->w1 = (osVirtualToPhysical(state->pole_state) & 0xFFFFFF) & 0xFFFFFF;
        state->dirty = 0;
    }

    return cmd;
}

// Param handler: types 4 (reset), 0x11 (delay), 0x12 (filter gain), 0x13 (filter cutoff);
// others go to the ADPCM loader.
s32 func_8002D328(TTVoiceE *voice, s32 type, s32 val)
{
    f32 *as_float = (f32 *) &val;

    switch (type) {
        case 4:
            voice->filter_gain = 0;
            func_8002CC9C(voice, 4, val);
            break;
        case 0x12:
            voice->filter_gain = val;
            voice->dirty |= 2;
            break;
        case 0x13:
            voice->filter_cutoff = (s32) *as_float;
            voice->dirty |= 2;
            break;
        case 0x11:
            voice->delay = val;
            break;
        default:
            func_8002CC9C(voice, type, val);
            break;
    }

    return 0;
}
