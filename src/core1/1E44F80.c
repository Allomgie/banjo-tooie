// Synth resampler stage (n_alResamplePull): pitch-shifts the loader output with A_RESAMPLE.
#include "common.h"

typedef struct {
    u32 w0;
    u32 w1;
} TTAcmd2;

typedef struct {
    u8 pad0[0x40];
    void *sample_ptr; // 0x40
    f32 pitch_ratio; // 0x44
    s32 raw_flag; // 0x48
    f32 frac; // 0x4C: fraction accumulator
    s32 start_mode; // 0x50: 0..3
} TTVoiceD;

extern TTAcmd2 *func_8002C5F8(TTVoiceD *, s16 *, s32, TTAcmd2 *);

// Resampler pull: pitch is quantised to 1/32768; unity pitch just moves the samples.
TTAcmd2 *func_8002D450(TTVoiceD *voice, s16 *arg1, TTAcmd2 *list)
{
    TTAcmd2 *cur;
    s16 in_dmem;
    s32 num_samples;
    s32 pitch;
    f32 pos;
    TTAcmd2 *dmemmove;
    TTAcmd2 *resample;

    cur = list;
    in_dmem = 0x170;

    if (voice->raw_flag) {
        cur = func_8002C5F8(voice, &in_dmem, 0xB8, list);
        dmemmove = cur++;
        dmemmove->w0 = (in_dmem & 0xFFFFFF) | 0x0A000000;
        dmemmove->w1 = ((*arg1 & 0xFFFF) << 16) | 0x170;
        // Matching: empty block steers IDO's register allocation.
        if (1) {
        }
    } else {
        // 1.99996 (f64) is the compare limit, 1.99996f the f32 clamp.
        if (voice->pitch_ratio > 1.99996)
            voice->pitch_ratio = 1.99996f;

        voice->pitch_ratio = (f32) (s32) (voice->pitch_ratio * 32768.0f);
        voice->pitch_ratio = voice->pitch_ratio / 32768.0f;

        pos = voice->frac + voice->pitch_ratio * 184.0f;
        num_samples = (s32) pos;
        voice->frac = pos - (f32) num_samples;

        cur = func_8002C5F8(voice, &in_dmem, num_samples, list);

        pitch = (s32) (voice->pitch_ratio * 32768.0f);

        resample = cur++;
        resample->w0 = (osVirtualToPhysical(voice->sample_ptr) & 0xFFFFFF) | 0x05000000;
        resample->w1 = ((voice->start_mode & 3) << 30) | ((pitch & 0xFFFF) << 14) | ((in_dmem & 0xFFF) << 2);
        voice->start_mode = 0;
    }

    return cur;
}

s32 func_8002D694(s32 a, s32 b, s32 c)
{
    func_8002CC9C(a, b, c);
    return 0;
}
