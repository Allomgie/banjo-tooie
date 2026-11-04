// Core of Rare's modified n_audio envelope mixer: voice parameter queue, volume/pan ramps
// and RSP command generation, plus a helper that posts a raw MIDI event to a sequence player.
#include "common.h"

typedef struct {
    u8 pad_0[0x48];
    u8 evtq;
} TTCSPq;
typedef struct {
    s16 type;
    union {
        struct {
            s32 ticks;
            u8 status;
            u8 chan;
            u8 byte2;
            u8 byte3;
            s32 duration;
        } midi;
    } msg;
} TTEvtA;
extern void func_80026500(void *, TTEvtA *, s32, s32);
typedef struct {
    u32 w0;
    u32 w1;
} TTAcmd;
typedef struct TTItemE_s {
    struct TTItemE_s *next;
    s32 time; // timestamp in samples
    union {
        s16 s;
        u16 u;
    } type; // event type
    s16 unk_A;
    union {
        void *p;
        f32 f;
        s32 i;
        struct {
            s16 hi;
            s16 lo;
        } h;
    } arg;
    union {
        s32 i;
        struct {
            s16 h;
            u8 b12;
            u8 b13;
        } s;
    } arg2;
    u8 unk_14;
    u8 unk_15;
    u8 pad_16[2];
    f32 unk_18;
    s32 unk_1C;
    void *unk_20;
} TTItemE;
typedef struct {
    u8 pad_0[0x44];
    f32 pitch;
    s32 unk_48;
    u8 pad_4C[0xC];
    s16 pan;
    s16 volume;
    s16 vol_l;
    s16 vol_r;
    s16 dry;
    s16 wet;
    u16 rate_frac_l;
    s16 rate_l;
    s16 target_l;
    u16 rate_frac_r;
    s16 rate_r;
    s16 target_r;
    s32 ramp_pos;
    s32 ramp_len;
    s32 vol_dirty;
    TTItemE *events; // update queue head
    s32 events_tail;
    s32 active;
    u8 pad_88[4];
    u8 delay;
    u8 pad_8D[3];
    s16 unk_90;
    s16 unk_92;
    u8 pad_94[0x24];
    s32 unk_B8;
} TTVceE;
typedef struct {
    u8 pad_0[0x88];
    s32 unk_88;
} TTHdlE;
extern s16 D_80041290[];
extern s16 D_8004138E[];
extern u8 D_8007EA30;
extern u8 D_8007EA31;
extern u8 D_8007EA32;
extern s32 func_8002CC9C(TTVceE *, s32, void *);
extern void func_80021884(void *);
extern void func_800217F4(void *);
typedef struct TTQEl_s {
    struct TTQEl_s *next;
} TTQEl;
typedef struct {
    u8 pad_0[0x48];
    s32 unk_48;
    f32 unk_4C;
    s32 unk_50;
    u8 pad_54[6];
    s16 volume;
    u8 pad_5C[0x18];
    s32 ramp_len;
    s32 vol_dirty;
    TTQEl *events; // queue head
    TTQEl *events_tail; // queue tail
    s32 active;
} TTPlayerC;
extern s32 func_8002D328(TTPlayerC *, s32, TTQEl *);
typedef struct {
    u8 pad_0[0x54];
    void *env_state;
    s16 pan;
    s16 volume;
    s16 vol_l;
    s16 vol_r;
    s16 dry;
    s16 wet;
    u16 rate_frac_l;
    s16 rate_l;
    s16 target_l;
    u16 rate_frac_r;
    s16 rate_r;
    s16 target_r;
    u32 ramp_pos;
    s32 ramp_len;
    s32 vol_dirty;
    u8 pad_7C[8];
    s32 active;
} TTVce;
extern TTAcmd *func_8002D030();
typedef struct {
    u8 pad_0[0x8C];
    u8 delay; // delay counter
} TTVceB;
typedef struct {
    u8 pad_0[0x8];
    TTVceB *voice;
    u8 pad_C[0xC];
    s16 chan; // bus channel
} TTHdlB;
typedef struct {
    u8 pad_0[0x8];
    TTHdlB *handle;
} TTNodeB;
typedef struct {
    u8 pad_0[0x14];
    u32 num_nodes;
    u8 pad_18[4];
    TTNodeB **nodes;
    u8 pad_20[0x28];
} TTChSlotB;
typedef struct {
    u8 pad_0[0x34];
    TTChSlotB *chan_slots;
} TTAMgrB;
extern TTAMgrB *D_800411F4;
extern f32 D_80041D90;

s32 func_8002B684(TTPlayerC *voice_in, s32 type, TTQEl *val);
TTAcmd *func_8002B7C8(void *voice_in, s16 *dmem_off, s32 out_pos, s32 samples, TTAcmd *cmd_in);
s16 func_8002BAAC(f32 cur, f32 tgt, s32 steps, u16 *out_frac);
s16 func_8002BCBC();

// Sequence player send-MIDI: queues a MIDI event with a delta.
// Posts a raw MIDI event into a sequence player's event queue.
void func_8002ACE0(TTCSPq *seqp, s32 delta, u8 status, u8 chan, u8 byte2, u8 byte3)
{
    TTEvtA evt;
    s32 ticks;

    evt.type = 2;
    evt.msg.midi.ticks = 0;
    evt.msg.midi.status = status;
    evt.msg.midi.chan = chan;
    evt.msg.midi.byte2 = byte2;
    evt.msg.midi.byte3 = byte3;
    evt.msg.midi.duration = 0;

    // Matching: extra copy of delta is needed for the match.
    ticks = delta;
    func_80026500(&seqp->evtq, &evt, ticks, 0);
}

// Envelope mixer: voice pull, parameter handler, volume ramp math, bus pull over voices.
// Drains the voice's timestamped update queue, emitting mixer commands per 184-sample sub-frame.
TTAcmd *func_8002AD60(TTVceE *voice_in, void *start_time, TTAcmd *cmd_in)
{
    TTAcmd *cmd = cmd_in;
    TTVceE *voice = voice_in;
    s16 dmem_off;
    s32 prev_time;
    s32 time = start_time;
    s32 delta;
    s16 out_pos;
    s32 new_vol;
    TTItemE *done;
    s32 remaining;
    TTItemE *start_evt;
    s32 start_vol;
    TTItemE *alt_start_evt;
    TTItemE *free_evt;

    out_pos = 0;
    remaining = 0xB8;
    dmem_off = 0;

    while (voice->events != 0) {
        prev_time = time;
        time = voice->events->time;

        delta = (time - prev_time + 0xB7) / 0xB8 * 0xB8;
        if (delta == 0)
            time = prev_time;

        if (delta > remaining)
            break;

        switch (voice->events->type.u) {
            case 0xD: // start voice
                start_evt = voice->events;
                if (start_evt->unk_A != 0)
                    voice->unk_48 = 1;

                func_8002CC9C(voice, 5, start_evt->unk_20);
                voice->active = 1;
                voice->vol_dirty = 1;
                voice->ramp_pos = 0;
                voice->ramp_len = (start_evt->unk_1C + 0xB7) / 0xB8 * 0xB8;

                start_vol = (start_evt->arg2.s.h + start_evt->arg2.s.h) / 2;
                voice->volume = start_vol;
                voice->pan = start_evt->arg2.s.b12;
                voice->dry = (D_80041290[start_evt->arg2.s.b13 & 0x7F] & 0xFFFE) | (start_evt->arg2.s.b13 >> 7);

                if (!D_8007EA30)
                    voice->dry = voice->dry & 0xFFFE;

                voice->wet = D_8004138E[-(start_evt->arg2.s.b13 & 0x7F)] & 0xFFFE;

                if (D_8007EA32)
                    voice->pan = (voice->pan >> 1) + 0x20;
                else if (D_8007EA31)
                    voice->pan = 0x40;

                if (start_evt->unk_1C != 0) {
                    voice->vol_l = 1;
                    voice->vol_r = 1;
                } else {
                    voice->vol_l = (D_80041290[voice->pan] * voice->volume) >> 15;
                    voice->vol_r = (D_8004138E[-voice->pan] * voice->volume) >> 15;
                }

                voice->pitch = start_evt->arg.f;
                voice->unk_92 = start_evt->unk_15;
                voice->unk_90 = (s32) start_evt->unk_18;
                voice->unk_B8 = 1;
                voice->delay = start_evt->unk_14;
                break;

            case 0xB: // set volume
            case 0xC: // set pan
            case 0x10: // set fxmix
                cmd = func_8002B7C8(voice, &dmem_off, &out_pos, delta, cmd);

                if (voice->ramp_pos >= voice->ramp_len) {
                    voice->target_l = (D_80041290[voice->pan] * voice->volume) >> 15;
                    voice->target_r = (D_8004138E[-voice->pan] * voice->volume) >> 15;
                    voice->ramp_pos = voice->ramp_len;
                    voice->vol_l = voice->target_l;
                    voice->vol_r = voice->target_r;
                } else {
                    voice->vol_l = func_8002BCBC(voice->vol_l, voice->ramp_pos, voice->rate_l, voice->rate_frac_l);
                    voice->vol_r = func_8002BCBC(voice->vol_r, voice->ramp_pos, voice->rate_r, voice->rate_frac_r);
                }

                if (voice->vol_l == 0)
                    voice->vol_l = 1;
                if (voice->vol_r == 0)
                    voice->vol_r = 1;

                if (voice->events->type.s == 0xC) {
                    if (D_8007EA32)
                        voice->pan = (voice->events->arg.h.lo >> 1) + 0x20;
                    else if (D_8007EA31)
                        voice->pan = 0x40;
                    else
                        voice->pan = voice->events->arg.i;
                }

                if (voice->events->type.s == 0xB) {
                    voice->ramp_pos = 0;
                    new_vol = voice->events->arg.i;
                    new_vol = (new_vol + new_vol) / 2;
                    voice->volume = new_vol;
                    voice->ramp_len = (voice->events->arg2.i + 0xB7) / 0xB8 * 0xB8;
                }

                if (voice->events->type.s == 0x10) {
                    if (((voice->dry ^ voice->wet) & 1) ^ ((voice->events->arg.i + 1) >> 7)) {
                        if (D_8007EA30) {
                            if (voice->pan > 0x40)
                                voice->dry = voice->dry ^ 1;
                            else
                                voice->wet = voice->wet ^ 1;
                        }
                    }
                    voice->dry = (D_80041290[voice->events->arg.i & 0x7F] & 0xFFFE) | (voice->dry & 1);
                    voice->wet = (D_8004138E[-(voice->events->arg.i & 0x7F)] & 0xFFFE) | (voice->wet & 1);
                }

                voice->vol_dirty = 1;
                break;

            case 0xE: // start voice
                alt_start_evt = voice->events;
                if (alt_start_evt->unk_A != 0)
                    voice->unk_48 = 1;

                func_8002CC9C(voice, 5, alt_start_evt->arg.p);
                voice->active = 1;
                break;

            case 0xF: // stop
                cmd = func_8002B7C8(voice, &dmem_off, &out_pos, delta, cmd);
                func_8002B684(voice, 4, 0);
                break;

            case 0x0: // free
                free_evt = voice->events;
                ((TTHdlE *) free_evt->arg.p)->unk_88 = 0;
                func_80021884(free_evt->arg.p);
                break;

            case 0x7: // set pitch
                cmd = func_8002B7C8(voice, &dmem_off, &out_pos, delta, cmd);
                voice->pitch = voice->events->arg.f;
                break;

            case 0x8: // unity pitch
                cmd = func_8002B7C8(voice, &dmem_off, &out_pos, delta, cmd);
                voice->unk_48 = 1;
                break;

            case 0x5:
                cmd = func_8002B7C8(voice, &dmem_off, &out_pos, delta, cmd);
                func_8002CC9C(voice, 5, voice->events->arg.p);
                break;

            default:
                cmd = func_8002B7C8(voice, &dmem_off, &out_pos, delta, cmd);
                func_8002B684(voice, voice->events->type.s, voice->events->arg.p);
                break;
        }

        out_pos += delta * 2;
        remaining = remaining - delta;

        done = voice->events;
        voice->events = voice->events->next;
        if (voice->events == 0)
            voice->events_tail = 0;

        func_800217F4(done);
    }

    cmd = func_8002B7C8(voice, &dmem_off, &out_pos, remaining, cmd);

    if (voice->ramp_pos > voice->ramp_len)
        voice->ramp_pos = voice->ramp_len;

    return cmd;
}

// Voice parameter handler.
s32 func_8002B684(TTPlayerC *voice_in, s32 type, TTQEl *val)
{
    TTPlayerC *voice = voice_in;

    switch (type) {
        case 3:
            if (voice->events_tail) {
                voice->events_tail->next = val;
            } else {
                voice->events = val;
            }
            voice->events_tail = val;
            break;
        case 4:
            voice->vol_dirty = 1;
            voice->active = 0;
            voice->volume = 1;
            voice->ramp_len = 0;
            voice->unk_4C = 0.0f;
            voice->unk_50 = 1;
            voice->unk_48 = 0;
            func_8002D328(voice, 4, val);
            break;
        case 9:
            voice->active = 1;
            break;
        default:
            func_8002D328(voice, type, val);
            break;
    }

    return 0;
}

// Emits A_SETVOL/A_ENVMIXER commands for one stretch of samples.
TTAcmd *func_8002B7C8(void *voice_in, s16 *dmem_off, s32 out_pos, s32 samples, TTAcmd *cmd_in)
{
    TTAcmd *cmd = cmd_in;
    TTVce *voice = (TTVce *) voice_in;
    TTAcmd *vol_cmd;
    TTAcmd *rate_r_cmd;
    TTAcmd *rate_l_cmd;
    TTAcmd *mix_cmd;
    TTAcmd *mix_cmd_plain;

    if (voice->active != 1 || samples == 0)
        return cmd;

    cmd = func_8002D030(voice, dmem_off, samples, cmd_in);

    if (voice->vol_dirty != 0) {
        voice->vol_dirty = 0;

        voice->target_l = (D_80041290[voice->pan] * voice->volume) >> 15;
        voice->rate_l = func_8002BAAC((f32) voice->vol_l, (f32) voice->target_l, voice->ramp_len, &voice->rate_frac_l);

        voice->target_r = (D_8004138E[-voice->pan] * voice->volume) >> 15;
        voice->rate_r = func_8002BAAC((f32) voice->vol_r, (f32) voice->target_r, voice->ramp_len, &voice->rate_frac_r);

        vol_cmd = cmd++;
        vol_cmd->w0 = (voice->vol_l & 0xFFFF) | 0x09060000;
        vol_cmd->w1 = ((voice->dry & 0xFFFF) << 16) | (voice->wet & 0xFFFF);

        rate_r_cmd = cmd++;
        rate_r_cmd->w0 = (voice->target_r & 0xFFFF) | 0x09040000;
        rate_r_cmd->w1 = ((voice->rate_r & 0xFFFF) << 16) | (voice->rate_frac_r & 0xFFFF);

        rate_l_cmd = cmd++;
        rate_l_cmd->w0 = (voice->target_l & 0xFFFF) | 0x09000000;
        rate_l_cmd->w1 = ((voice->rate_l & 0xFFFF) << 16) | (voice->rate_frac_l & 0xFFFF);

        mix_cmd = cmd++;
        mix_cmd->w0 = (voice->vol_r & 0xFFFF) | 0x03010000;
        mix_cmd->w1 = osVirtualToPhysical(voice->env_state);
        // Matching: empty block stands in for a compiled-out debug block; it suppresses delay-slot fill.
        if (1) {
        }
    } else {
        mix_cmd_plain = cmd++;
        mix_cmd_plain->w0 = 0x03000000;
        mix_cmd_plain->w1 = osVirtualToPhysical(voice->env_state);
    }

    *dmem_off += 0x170;
    voice->ramp_pos += 0xB8;

    return cmd;
}

// Computes the volume ramp rate; integer part is returned, fraction goes to out_frac.
s16 func_8002BAAC(f32 cur, f32 tgt, s32 steps, u16 *out_frac)
{
    s16 hi;
    s16 lo;
    f32 step_inv;
    f32 rate;
    f32 frac;

    if (!steps) {
        if (cur <= tgt) {
            *out_frac = 0xFFFF;
            return 0x7FFF;
        } else {
            *out_frac = 0;
            return -0x8000;
        }
    }

    step_inv = 1.0f / (f32) steps;

    if (tgt < 1.0f)
        tgt = 1.0f;
    if (cur <= 0.0f)
        cur = 1.0f;

    rate = (tgt - cur) * step_inv * 8.0f;
    hi = (s32) rate;
    frac = rate - hi;
    hi = hi - 1;
    frac = frac + 1.0f;
    lo = (s32) frac;
    hi = hi + lo;
    frac = frac - lo;

    *out_frac = (u32) (65535.0f * frac);

    return hi;
}

// Interpolated volume after a number of ramp steps.
s16 func_8002BCBC(base, steps, delta, frac)
s16 base;
s32 steps;
s16 delta;
u16 frac;
{
    s32 inc;

    steps = steps >> 3;
    if (!steps)
        return base;

    inc = frac * steps;
    inc = inc >> 16;
    inc += delta * steps;
    base = base + inc;

    return base;
}

// Pulls all voices of one bus in two groups (delay >= 0x40 first) and emits the filter commands.
TTAcmd *func_8002BD40(void *start_time, TTAcmd *cmd_in, s32 chan, s32 *out_count)
{
    TTAcmd *cmd = cmd_in;
    TTChSlotB *slot = &D_800411F4->chan_slots[chan];
    TTNodeB **node_list = slot->nodes;
    u32 i;
    s32 delayed_count = 0;
    u32 max_delay = 1;
    u32 rate;
    TTAcmd *clear_cmd;
    TTAcmd *filter_a;
    TTAcmd *filter_b;
    TTAcmd *start_cmd;

    clear_cmd = cmd++;
    clear_cmd->w0 = 0x020007C0;
    clear_cmd->w1 = 0x2E0;

    *out_count = 0;

    for (i = 0; i < slot->num_nodes; i++) {
        if (node_list[i]->handle != 0 && node_list[i]->handle->chan == chan && node_list[i]->handle->voice != 0 &&
            node_list[i]->handle->voice->delay >= 0x40) {
            cmd = func_8002AD60(node_list[i], start_time, cmd);
            (*out_count)++;
            delayed_count++;
            if (node_list[i]->handle->voice->delay > max_delay)
                max_delay = node_list[i]->handle->voice->delay;
        }
    }

    if (delayed_count != 0) {
        max_delay -= 0x3E;

        if (max_delay >= 7)
            rate = (u32) (D_80041D90 / sqrtf((f32) max_delay));
        else
            rate = (u32) (65536.0f / (f32) max_delay);

        filter_a = cmd++;
        filter_a->w0 = 0x4E0;
        filter_a->w1 = ((rate & 0xFFFF) << 16) | (max_delay & 0xFFFF);

        filter_b = cmd++;
        filter_b->w0 = 0x650;
        filter_b->w1 = ((rate & 0xFFFF) << 16) | (max_delay & 0xFFFF);
    }

    for (i = 0; i < slot->num_nodes; i++) {
        if ((node_list[i]->handle != 0 && node_list[i]->handle->chan == chan &&
             (node_list[i]->handle->voice == 0 || node_list[i]->handle->voice->delay < 0x40)) ||
            (node_list[i]->handle == 0 && chan == 0)) {
            start_cmd = cmd;
            cmd = func_8002AD60(node_list[i], start_time, cmd);
            if (cmd != start_cmd)
                (*out_count)++;
        }
    }

    return cmd;
}

// TU-NOTE: .data of this file is defined here in C, values taken from the ROM.
// D_8004138E is a linker symbol (undefined_syms.us.txt) at D_80041290 + 0xFE.
s16 D_80041290[128] = {
    0x7FFF, 0x7FFC, 0x7FF5, 0x7FE8, 0x7FD7, 0x7FC0, 0x7FA5, 0x7F84, 0x7F5F, 0x7F34, 0x7F05, 0x7ED0,
    0x7E97, 0x7E58, 0x7E15, 0x7DCD, 0x7D7F, 0x7D2D, 0x7CD6, 0x7C7A, 0x7C1A, 0x7BB4, 0x7B49, 0x7ADA,
    0x7A66, 0x79ED, 0x796F, 0x78ED, 0x7866, 0x77DA, 0x7749, 0x76B4, 0x761A, 0x757B, 0x74D8, 0x7430,
    0x7384, 0x72D3, 0x721E, 0x7164, 0x70A6, 0x6FE3, 0x6F1C, 0x6E51, 0x6D81, 0x6CAD, 0x6BD5, 0x6AF9,
    0x6A18, 0x6933, 0x684A, 0x675D, 0x666C, 0x6577, 0x647E, 0x6381, 0x6280, 0x617C, 0x6073, 0x5F67,
    0x5E57, 0x5D43, 0x5C2C, 0x5B11, 0x59F2, 0x58D0, 0x57AA, 0x5681, 0x5555, 0x5425, 0x52F2, 0x51BC,
    0x5082, 0x4F46, 0x4E06, 0x4CC3, 0x4B7D, 0x4A35, 0x48E9, 0x479B, 0x4649, 0x44F5, 0x439E, 0x4245,
    0x40E9, 0x3F8A, 0x3E29, 0x3CC6, 0x3B60, 0x39F8, 0x388D, 0x3721, 0x35B2, 0x3441, 0x32CE, 0x3159,
    0x2FE2, 0x2E69, 0x2CEF, 0x2B72, 0x29F4, 0x2875, 0x26F3, 0x2570, 0x23EC, 0x2266, 0x20DF, 0x1F57,
    0x1DCE, 0x1C43, 0x1AB7, 0x192A, 0x179C, 0x160E, 0x147E, 0x12ED, 0x115C, 0xFCA,  0xE38,  0xCA5,
    0xB11,  0x97D,  0x7E9,  0x654,  0x4C0,  0x32A,  0x195,  0x0};
