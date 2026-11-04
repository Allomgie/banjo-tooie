// Reverb/FX unit (n_reverb): multi-tap delay and filter command generation, FX and voice setup.
#include "common.h"
#define CMD_MIX(param_0, param_1, param_2, param_3, param_4)                                       \
    {                                                                                              \
        Acmd *local_cmd = (Acmd *) (param_0);                                                      \
        local_cmd->words.w0 = 0x0C000000 | ((param_1) << 16) | ((param_2) & 0xFFFF);               \
        local_cmd->words.w1 = (((param_3) & 0xFFFF) << 16) | ((param_4) & 0xFFFF);                 \
    }
#define CMD_CLEAR(param_0, param_1, param_2)                                                       \
    {                                                                                              \
        Acmd *local_cmd = (Acmd *) (param_0);                                                      \
        local_cmd->words.w0 = 0x02000000 | ((param_1) & 0xFFFFFF);                                 \
        local_cmd->words.w1 = (u32) (param_2);                                                     \
    }
#define CMD_MOVE(param_0, param_1, param_2, param_3)                                               \
    {                                                                                              \
        Acmd *local_cmd = (Acmd *) (param_0);                                                      \
        local_cmd->words.w0 = 0x0A000000 | ((param_1) & 0xFFFFFF);                                 \
        local_cmd->words.w1 = (((param_2) & 0xFFFF) << 16) | ((param_3) & 0xFFFF);                 \
    }

typedef struct {
    u8 pad0[0x20];
} LowPass_800272B0;
typedef struct {
    s32 input;
    s32 output;
    s16 ffcoef;
    s16 fbcoef;
    s16 gain;
    u8 padE[2];
    f32 rsinc;
    u8 pad14[8];
    f32 rsgain;
    LowPass_800272B0 *lp;
    void *rs;
} Delay_800272B0;
typedef struct {
    s32 length;
    Delay_800272B0 *delay;
    u8 section_count;
    u8 pad9[0x20 - 9];
    s16 *base[2];
    s16 *input[2];
} Effect_800272B0;
typedef struct {
    u8 pad0[0x20];
    Effect_800272B0 *fx;
    u8 pad24[0x48 - 0x24];
} AuxBus;
typedef struct {
    u8 pad0[0x34];
    AuxBus *auxBus;
} Synth_800272B0;
extern Synth_800272B0 *D_800411F4;
extern u8 D_8007EA33[];
extern u8 D_8007EA34[];
Acmd *func_8002BD40(s32, Acmd *, s32, s32 *);
typedef struct {
    s16 fc;
} LowPass_80027AF0;
typedef struct {
    u32 input;
    u32 output;
    s16 ffcoef;
    s16 fbcoef;
    s16 gain;
    u8 padE[2];
    f32 rsinc;
    u8 pad14[8];
    f32 rsgain;
    LowPass_80027AF0 *lp;
    void *rs;
} Delay_80027AF0;
typedef struct {
    u32 length;
    Delay_80027AF0 *delay;
    u8 section_count;
} Effect_80027AF0;
typedef struct {
    u8 pad0[0x40];
    s32 outputRate;
} Synth_80027AF0;
typedef struct {
    u32 w0;
    u32 w1;
} TTAcmd;
typedef struct {
    u8 pad0[0x14];
    void *buf[4];
    f32 frac_acc;
    s32 unk28;
} TTLine;
typedef struct {
    s32 input;
    s32 output;
    u8 pad8[8];
    f32 rsinc;
    f32 unk14;
    s32 unk18;
    f32 rsgain;
    u8 pad20[4];
    TTLine *rs;
} TTReverb;
typedef struct {
    u32 length;
    u8 pad4[0x1C];
    u8 *base[2];
    u8 *input[2];
} TTBank;
typedef struct {
    u32 length;
    u8 pad4[0x1C];
    u8 *base[4];
} TTDlyD;
typedef struct {
    u8 pad0[2];
    s16 unk2;
    u8 pad4[4];
    u32 coef;
    u8 padC[0x1C];
    s32 unk28;
    void *unk2C[2];
} TTRvbF;
typedef struct {
    u8 pad0[0x10];
    f32 rate;
    f32 phase;
    u8 pad18[4];
    f32 depth;
} TTOscT;
extern f32 D_80041D10;
extern f32 D_80041D14;
extern f32 func_80013C48(f32, f32);
typedef struct {
    s16 fc;
    s16 unk2;
    u8 pad4[4];
    s16 coef[16];
    s32 unk28;
} TTEnvA;
extern f32 D_80041D18;
extern f32 D_80041D1C;
typedef struct {
    s16 fc;
    s16 unk2;
    u8 pad4[4];
    s16 coef[16];
} TTFxC;
extern f32 D_80041D20;
extern f32 D_80041D24;
typedef struct {
    u8 pad0[0x14];
    void *unk14;
    void *unk18;
    u8 pad1C[8];
    f32 frac_acc;
    s32 unk28;
    u8 pad2C[0xC];
} ElemA;
typedef struct {
    s16 fc;
    u8 pad2[0x2A];
    void *unk2C;
    void *unk30;
    u8 pad34[4];
} ElemB;
typedef struct {
    u32 input;
    u32 output;
    s16 ffcoef;
    s16 fbcoef;
    s16 gain;
    u8 padE[2];
    f32 rsinc;
    f32 unk14;
    s32 unk18;
    f32 rsgain;
    ElemB *lp;
    ElemA *rs;
} Elem;
typedef struct {
    u32 length;
    Elem *delay;
    u8 section_count;
    u8 pad9[0x17];
    s16 *base_0;
    s16 *base_1;
    void *input_0;
    void *input_1;
} TTObj;
typedef struct {
    u8 pad0[0x18];
    s32 output_rate;
    u8 fx_type[4];
    s32 *custom_tbl[4];
} TTDesc;
extern void *func_80020EE4(s32, s32, void *, s32, s32);
extern s32 D_80041268[];
extern f32 D_80041D28;
typedef struct {
    u8 pad0[0xC];
    void *unkC;
    void *unk10;
    u8 pad14[0x14];
    void *unk28;
    u8 unk2C;
    u8 pad2D[7];
    s32 unk34;
    s32 unk38;
    s32 unk3C;
    void *unk40;
    f32 unk44;
    s32 unk48;
    f32 unk4C;
    s32 unk50;
    void *unk54;
    s16 unk58;
    s16 unk5A;
    s16 unk5C;
    s16 unk5E;
    s16 unk60;
    s16 unk62;
    s16 unk64;
    s16 unk66;
    s16 unk68;
    u8 pad6A[4];
    s16 unk6E;
    s32 unk70;
    s32 unk74;
    s32 unk78;
    s32 unk7C;
    s32 unk80;
    s32 unk84;
    u8 pad88[4];
    u8 unk8C;
    u8 pad8D[3];
    s16 unk90;
    s16 unk92;
    u8 pad94[0x24];
    s32 unkB8;
    void *unkBC;
} TTVceI2;

TTAcmd *func_80028010(TTBank *bank, TTReverb *r, s32 idx, s32 dmem, TTAcmd *cmdBuf);
TTAcmd *func_80028328(TTDlyD *d, s32 idx, u8 *pos, s32 dmem, s32 len, TTAcmd *cmdIn);
TTAcmd *func_80028520(TTDlyD *d, s32 idx, u8 *pos, s32 dmem, TTAcmd *cmdIn);
TTAcmd *func_800286FC(TTRvbF *r, s32 idx, s32 vol, TTAcmd *cmdIn);
f32 func_800287FC(TTOscT *p, s32 step);
void func_80028A24(TTEnvA *p);

// Reverb/FX DSP command generation, FX params, filters, FX and voice construction.
// n_alFxPull: emit RSP audio commands for one FX bus (multi-tap delay lines, optional stereo reverb)
Acmd *func_800272B0(s32 unk_0, Acmd *cmd_start, s32 bus)
{
    Acmd *cmd = cmd_start;
    Effect_800272B0 *fx = D_800411F4->auxBus[bus].fx;
    s16 j;
    s16 buf_a;
    s16 buf_b;
    s16 in_dmem;
    s16 acc_dmem;
    s16 *in_ptr;
    s16 *out_ptr;
    s16 *prev_out = 0;
    Delay_800272B0 *delay;
    s32 unk_1 = 1;
    u32 i;

    cmd = func_8002BD40(unk_0, cmd_start, bus, &unk_1);
    in_dmem = 0x7C0;
    acc_dmem = 0x930;
    buf_a = 0;
    buf_b = 0x170;

    if (D_8007EA33[bus] == 0) {
        CMD_MIX(cmd++, 0, 0xC000, 0x7C0, in_dmem);
        CMD_MIX(cmd++, 0, 0x4000, 0x930, in_dmem);
    }

    cmd = func_80028520(fx, 0, fx->input[0], in_dmem, cmd);
    if (D_8007EA33[bus]) {
        cmd = func_80028520(fx, 1, fx->input[1], 0x930, cmd);
    }

    for (i = 0; i <= D_8007EA33[bus]; i++) {
        CMD_CLEAR(cmd++, acc_dmem, 0x170);

        for (j = 0; j < fx->section_count; j++) {
            delay = &fx->delay[j];
            in_ptr = &fx->input[i][-delay->input];
            out_ptr = &fx->input[i][-delay->output];

            if (D_8007EA34[bus] && D_8007EA33[bus]) {
                delay->ffcoef = -delay->ffcoef;
                delay->fbcoef = -delay->fbcoef;
            }

            if (in_ptr == prev_out) {
                s16 tmp = buf_b;
                buf_b = buf_a;
                buf_a = tmp;
            } else {
                cmd = func_80028328(fx, i, in_ptr, buf_a, 0xB8, cmd);
            }

            cmd = func_80028010(fx, delay, i, buf_b, cmd);

            if (delay->ffcoef) {
                CMD_MIX(cmd++, 0, (u16) delay->ffcoef, buf_a, buf_b);
                if (!delay->rs && !delay->lp) {
                    cmd = func_80028520(fx, i, out_ptr, buf_b, cmd);
                }
            }
            if (delay->fbcoef) {
                CMD_MIX(cmd++, 0, (u16) delay->fbcoef, buf_b, buf_a);
                cmd = func_80028520(fx, i, in_ptr, buf_a, cmd);
            }
            if (delay->lp) {
                cmd = func_800286FC(delay->lp, i, buf_b, cmd);
            }
            if (!delay->rs) {
                cmd = func_80028520(fx, i, out_ptr, buf_b, cmd);
            }
            if (delay->gain) {
                if (D_8007EA33[bus]) {
                    CMD_MIX(cmd++, 0, (u16) delay->gain, buf_b, acc_dmem);
                } else {
                    u32 gain = delay->gain * 1.4141999483109f;
                    if (gain > 0x7FFF) {
                        gain = 0x7FFF;
                    }
                    CMD_MIX(cmd++, 0, (u16) gain, buf_b, acc_dmem);
                }
            }
            prev_out = &fx->input[i][delay->output];
        }

        if (D_8007EA33[bus] && i == 0) {
            cmd = func_80028328(fx, 1, fx->input[1], in_dmem, 0xB8, cmd);
            if (D_8007EA34[bus]) {
                CMD_MIX(cmd++, 0, 0x5A82, acc_dmem, 0x650);
            } else {
                CMD_MIX(cmd++, 0, 0x5A82, acc_dmem, 0x4E0);
            }
        } else {
            // Matching: empty else block needed for the match.
        }

        CMD_MOVE(cmd++, acc_dmem, 0x7C0, 0x170);
        fx->input[i] += 0xB8;
        if (fx->input[i] > &fx->base[i][fx->length]) {
            fx->input[i] -= fx->length;
        }
    }
    return cmd;
}

// alFxParam: set one delay line parameter; low 3 bits of param select it, the rest the delay line
s32 func_80027AF0(void *fx, s32 param, void *value_ptr)
{
    Effect_80027AF0 *effect = (Effect_80027AF0 *) fx;
    s32 type = param & 7;
    s32 section = param >> 3;
    s32 value = *(s32 *) value_ptr;
    f32 unk_0;

    if (section >= effect->section_count) {
        return 0;
    }

    switch (type) {
        case 0:
            effect->delay[section].input =
                ((s32) value * ((Synth_80027AF0 *) D_800411F4)->outputRate / 1000) & 0xFFFFFFF8;
            break;
        case 1:
            effect->delay[section].output =
                ((s32) value * ((Synth_80027AF0 *) D_800411F4)->outputRate / 1000) & 0xFFFFFFF8;
            break;
        case 2:
            effect->delay[section].fbcoef = (s16) value;
            break;
        case 3:
            effect->delay[section].ffcoef = (s16) value;
            break;
        case 4:
            effect->delay[section].gain = (s16) value;
            break;
        case 5:
            effect->delay[section].rsinc =
                (((f32) value / 1000.0f) * 2.0f) / ((Synth_80027AF0 *) D_800411F4)->outputRate;
            break;
        case 6:
            unk_0 = value;
            break;
        case 7:
            if (effect->delay[section].lp) {
                effect->delay[section].lp->fc = (s16) value;
                func_80028A24(effect->delay[section].lp);
            }
            break;
    }

    if (effect->delay[section].input >= effect->length - 16) {
        effect->delay[section].input = effect->length - 16;
    }
    if (effect->delay[section].input >= effect->length - 8) {
        effect->delay[section].input = effect->length - 8;
    }
    if (effect->delay[section].input >= effect->delay[section].output) {
        effect->delay[section].output = effect->delay[section].input + 8;
    }

    if (effect->delay[section].rs) {
        if (type != 6) {
            if ((effect->delay[section].output - effect->delay[section].input) != 0) {
                unk_0 = (f32) effect->delay[section].rsgain /
                          (effect->delay[section].output - effect->delay[section].input) *
                          173123.404906676f;
            } else {
                unk_0 = 0;
            }
        }
        effect->delay[section].rsgain =
            (effect->delay[section].output - effect->delay[section].input) *
            (unk_0 / 173123.404906676f);
    }
    return 0;
}

// Load the delay input for one line into DMEM; reads through the modulated resampler when rs is set
TTAcmd *func_80028010(TTBank *bank, TTReverb *delay, s32 idx, s32 dmem, TTAcmd *cmd_buf)
{
    TTAcmd *cmd = cmd_buf;
    s32 gain;
    s32 acc_int;
    s32 dmem_dflt = 0x2E0;
    u8 *pos;
    f32 acc;
    f32 inv_val;
    f32 val;
    s32 align = 0;
    s32 len;
    s32 budget = 0xB8;
    s16 dmem_hi;
    TTAcmd *c1;

    if (delay->rs != 0) {
        len = delay->output - delay->input;

        val = func_800287FC(delay, budget);
        val = val / (f32) len;
        val = (f32) (s32) (val * 32768.0f);
        val = val / 32768.0f;
        inv_val = 1.0f - val;

        acc = delay->rs->frac_acc + inv_val * (f32) budget;
        acc_int = (s32) acc;
        delay->rs->frac_acc = acc - (f32) acc_int;

        pos = bank->input[idx] + -(delay->output - delay->unk18) * 2;
        align = ((s32) pos & 7) >> 1;

        cmd = func_80028328(bank, idx, pos - align * 2, dmem_dflt, acc_int + align, cmd);

        gain = (s32) (inv_val * 32768.0f);
        dmem_hi = dmem >> 8;

        c1 = cmd++;
        c1->w0 = (osVirtualToPhysical(delay->rs->buf[idx]) & 0xFFFFFF) | 0x05000000;
        c1->w1 = ((delay->rs->unk28 & 3) << 30) | ((gain & 0xFFFF) << 14) |
                 (((dmem_dflt + align * 2) & 0xFFF) << 2) | (dmem_hi & 3);
        delay->rs->unk28 = 0;

        delay->unk18 = delay->unk18 + (acc_int - budget);
    } else {
        pos = bank->input[idx] + -delay->output * 2;
        cmd = func_80028328(bank, idx, pos, dmem, 0xB8, cmd);
    }

    return cmd;
}

// Load len samples from the circular delay buffer into DMEM, splitting at the wrap point
TTAcmd *func_80028328(TTDlyD *fx, s32 idx, u8 *pos, s32 dmem, s32 len, TTAcmd *cmd_in)
{
    TTAcmd *cmd = cmd_in;
    s32 len2;
    s32 len1;
    u8 *end;
    u8 *loop_end;
    TTAcmd *c1;
    TTAcmd *c2;
    TTAcmd *c3;

    loop_end = fx->base[idx] + fx->length * 2;

    if (pos < fx->base[idx]) {
        pos += fx->length * 2;
    }

    end = len * 2 + pos;

    if (end > loop_end) {
        len2 = (end - loop_end) >> 1;
        len1 = (loop_end - pos) >> 1;

        c1 = cmd++;
        c1->w0 = ((len1 * 2 & 0xFFF) << 12) | 0x04000000 | (dmem & 0xFFF);
        c1->w1 = osVirtualToPhysical(pos);

        c2 = cmd++;
        c2->w0 = ((len2 * 2 & 0xFFF) << 12) | 0x04000000 | ((dmem + len1 * 2) & 0xFFF);
        c2->w1 = osVirtualToPhysical(fx->base[idx]);
        // Matching: empty block needed for the match.
        if (1) {
        }
    } else {
        c3 = cmd++;
        c3->w0 = ((len * 2 & 0xFFF) << 12) | 0x04000000 | (dmem & 0xFFF);
        c3->w1 = osVirtualToPhysical(pos);
    }

    return cmd;
}

// Save 0x170 bytes from DMEM into the circular delay buffer, splitting at the wrap point
TTAcmd *func_80028520(TTDlyD *fx, s32 idx, u8 *pos, s32 dmem, TTAcmd *cmd_in)
{
    TTAcmd *cmd = cmd_in;
    s32 len2;
    s32 len1;
    u8 *end;
    u8 *loop_end;
    TTAcmd *c1;
    TTAcmd *c2;
    TTAcmd *c3;

    loop_end = fx->base[idx] + fx->length * 2;

    if (pos < fx->base[idx]) {
        pos += fx->length * 2;
    }

    end = pos + 0x170;

    if (end > loop_end) {
        len2 = (end - loop_end) >> 1;
        len1 = (loop_end - pos) >> 1;

        c1 = cmd++;
        c1->w0 = ((len1 * 2 & 0xFFF) << 12) | 0x06000000 | (dmem & 0xFFF);
        c1->w1 = osVirtualToPhysical(pos);

        c2 = cmd++;
        c2->w0 = ((len2 * 2 & 0xFFF) << 12) | 0x06000000 | ((dmem + len1 * 2) & 0xFFF);
        c2->w1 = osVirtualToPhysical(fx->base[idx]);
        // Matching: empty block needed for the match.
        if (1) {
        }
    } else {
        c3 = cmd++;
        c3->w0 = (dmem & 0xFFF) | 0x06170000;
        c3->w1 = osVirtualToPhysical(pos);
    }

    return cmd;
}

// Emit the low-pass filter commands for one delay line
TTAcmd *func_800286FC(TTRvbF *lp, s32 idx, s32 dmem, TTAcmd *cmd_in)
{
    TTAcmd *cmd = cmd_in;
    s16 dmem_hi;
    TTAcmd *c1;
    TTAcmd *c2;

    dmem_hi = dmem >> 8;

    c1 = cmd++;
    c1->w0 = 0x0B000020;
    c1->w1 = osVirtualToPhysical(&lp->coef);

    c2 = cmd++;
    c2->w0 = (((lp->unk28 & 0xFF) << 16) | 0x0E000000) | (lp->unk2 & 0xFFFF);
    c2->w1 = (osVirtualToPhysical(lp->unk2C[idx]) & 0xFFFFFF) | ((dmem_hi & 0xFF) << 24);

    lp->unk28 = 0;

    return cmd;
}

// LFO: advance the phase by rate * samples and return a triangle wave scaled by depth
f32 func_800287FC(TTOscT *lfo, s32 samples)
{
    f32 value;

    lfo->phase += lfo->rate * (f32) samples;

    if (lfo->phase > 2.0f)
        lfo->phase = lfo->phase - 4.0f;
    else
        lfo->phase = lfo->phase; // Matching: self-assignment needed for the match.

    value = lfo->phase;
    value = (value < 0.0f) ? -value : value;

    value = value - 1.0f;
    return lfo->depth * value;
}

// Compute low-pass biquad coefficients: out1 = numerator, out2 = denominator
void func_800288C0(f32 rate, f32 cutoff, f32 q_factor, f32 *out1, f32 *out2)
{
    f32 w;
    f32 w2;
    f32 qw;

    if (cutoff >= rate - 200.0f)
        cutoff = rate - 200.0f;

    w = func_80013C48(cutoff * D_80041D10, rate);
    w2 = w * w;
    qw = w * D_80041D14 / q_factor;

    *out1 = w2 / (1.0f + w2 + qw);
    out1[1] = *out1 * 2.0f;
    out1[2] = *out1;

    out2[1] = (w2 - 1.0f) * 2.0f / (1.0f + w2 + qw);
    out2[2] = (1.0f + w2 - qw) / (1.0f + w2 + qw);
}

// Compute the low-pass coefficient table from the cutoff fc
void func_80028A24(TTEnvA *lp)
{
    s32 i;
    s32 scaled;
    s16 half;
    f32 ratio;
    f32 power;
    f32 scale;

    scaled = (s32) ((f32) lp->fc * 16384.0f);
    half = scaled >> 15;
    lp->unk2 = (s32) (16384.0f - (f32) half);
    lp->unk28 = 0;

    for (i = 0; i < 8; i++)
        lp->coef[i] = 0;

    lp->coef[i] = half;
    i++;

    scale = 16384.0f;
    power = ratio = (f32) half / scale;

    for (; i < 0x10; i++) {
        power = power * ratio;
        lp->coef[i] = (s32) (power * scale);
    }
}

// Pitch ratio helper (power by squaring), used only by the sequence player.
// Semitone/cents ratio helper: raises a base constant to the power by repeated squaring
f32 func_80028B74(s32 power)
{
    f32 base;
    f32 result;

    result = 1.0f;
    if (power >= 0) {
        base = D_80041D18;
    } else {
        base = D_80041D1C;
        power = -power;
    }

    while (power != 0) {
        if (power & 1) {
            result = result * base;
        }
        base = base * base;
        power = power >> 1;
    }

    return result;
}

// Compute low-pass coefficients for the given output rate
void func_80028C04(TTFxC *lp, f32 rate)
{
    s32 i;
    f32 b_coef[3];
    f32 a_coef[3];

    if (lp->unk2 == 0)
        return;

    if (lp->unk2 < 0xA)
        lp->unk2 = 0xA;

    func_800288C0(rate, (f32) lp->fc + 10.0f, (f32) lp->unk2 / 10.0f, b_coef, a_coef);

    for (i = 3; i < 8; i++)
        lp->coef[i] = 0;

    lp->coef[0] = (s32) (b_coef[0] * (D_80041D20 - (f32) lp->unk2 * 128.0f));
    lp->coef[1] = (s32) (b_coef[1] * (D_80041D24 - (f32) lp->unk2 * 128.0f));
    lp->coef[2] = 0;
    lp->coef[8] = (s32) (a_coef[1] * -16384.0f);
    lp->coef[9] = (s32) (a_coef[2] * -16384.0f);

    for (i = 0xA; i < 0x10; i++)
        lp->coef[i] = 0;
}

// alFxNew: build the effect from the preset table, or from a custom table when the type is 6
void func_80028DF0(TTObj **out, TTDesc *desc, s32 idx, void *heap)
{
    u16 i;
    u16 k;
    u16 j;
    s32 *tbl;
    Elem *elem;
    TTObj *obj;

    // Matching: the dead initialisation is needed for the match.
    tbl = 0;
    obj = func_80020EE4(0, 0, heap, 1, 0x30);
    *out = obj;

    switch (desc->fx_type[(s16) idx]) {
        case 6:
            tbl = desc->custom_tbl[(s16) idx];
            break;
        default:
            tbl = D_80041268;
            break;
    }

    k = 0;
    obj->section_count = tbl[k];
    k++;
    obj->length = tbl[k];
    k++;

    obj->delay = func_80020EE4(0, 0, heap, obj->section_count, 0x28);
    obj->base_0 = func_80020EE4(0, 0, heap, obj->length, 2);
    obj->input_0 = obj->base_0;
    obj->base_1 = func_80020EE4(0, 0, heap, obj->length, 2);
    obj->input_1 = obj->base_1;

    for (j = 0; j < obj->length; j++) {
        obj->base_1[j] = 0;
        obj->base_0[j] = obj->base_1[j];
    }

    for (i = 0; i < obj->section_count; i++) {
        // Matching: the extra block is needed for the match.
        {
            elem = &obj->delay[i];
            elem->input = tbl[k];
            k++;
            elem->output = tbl[k];
            k++;
            elem->fbcoef = tbl[k];
            k++;
            elem->ffcoef = tbl[k];
            k++;
            elem->gain = tbl[k];
            k++;
            if (tbl[k] != 0) {
                elem->rsinc = (f32) tbl[k] / 1000.0f * 2.0f / (f32) desc->output_rate;
                k++;
                elem->rsgain = (f32) tbl[k] / D_80041D28 * (f32) (u32) (elem->output - elem->input);
                k++;
                elem->unk14 = 1.0f;
                elem->unk18 = 0;
                elem->rs = func_80020EE4(0, 0, heap, 1, 0x38);
                elem->rs->unk14 = func_80020EE4(0, 0, heap, 1, 0x20);
                elem->rs->unk18 = func_80020EE4(0, 0, heap, 1, 0x20);
                elem->rs->frac_acc = 0.0f;
                elem->rs->unk28 = 1;
            } else {
                elem->rs = 0;
                k++;
                k++;
            }
            if (tbl[k] != 0) {
                elem->lp = func_80020EE4(0, 0, heap, 1, 0x38);
                elem->lp->unk2C = func_80020EE4(0, 0, heap, 1, 8);
                elem->lp->unk30 = func_80020EE4(0, 0, heap, 1, 8);
                elem->lp->fc = tbl[k];
                k++;
                func_80028A24(elem->lp);
            } else {
                elem->lp = 0;
                k++;
            }
        }
    }
}

// Initialise the envmixer/resampler/loader state of a physical voice
void func_800293B4(TTVceI2 *pvoice, void **fn(void *), void *heap)
{
    pvoice->unkC = func_80020EE4(0, 0, heap, 1, 0x20);
    pvoice->unk10 = func_80020EE4(0, 0, heap, 1, 0x20);
    pvoice->unk28 = fn(&pvoice->unk2C);
    pvoice->unk34 = 0;
    pvoice->unk38 = 1;
    pvoice->unk3C = 0;
    pvoice->unk40 = func_80020EE4(0, 0, heap, 1, 0x20);
    pvoice->unk4C = 0.0f;
    pvoice->unk50 = 1;
    pvoice->unk44 = 1.0f;
    pvoice->unk48 = 0;
    pvoice->unk54 = func_80020EE4(0, 0, heap, 1, 0x50);
    pvoice->unk78 = 1;
    pvoice->unk84 = 0;
    pvoice->unk5A = 1;
    pvoice->unk68 = 1;
    pvoice->unk6E = 1;
    pvoice->unk5C = 1;
    pvoice->unk5E = 1;
    pvoice->unk60 = 0;
    pvoice->unk62 = 0;
    // Matching: the repeated unk66/unk64 stores are needed for the match.
    pvoice->unk66 = 1;
    pvoice->unk64 = 0;
    pvoice->unk66 = 1;
    pvoice->unk64 = 0;
    pvoice->unk70 = 0;
    pvoice->unk74 = 0;
    pvoice->unk58 = 0;
    pvoice->unk7C = 0;
    pvoice->unk80 = 0;
    pvoice->unk8C = 0;
    pvoice->unk92 = 0;
    pvoice->unk90 = 0;
    pvoice->unkBC = func_80020EE4(0, 0, heap, 1, 8);
    pvoice->unkB8 = 0;
}

// TU-NOTE: the .data of this file is defined here in C; values taken from the ROM.
u32 D_80041260[2] = {0x0, 0x5000};
s32 D_80041268[10] = {0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0};
