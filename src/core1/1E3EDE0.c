#include "common.h"
#define CMD_MIX(param_0, param_1, param_2, param_3, param_4) { \
    Acmd *local_cmd = (Acmd *)(param_0); \
    local_cmd->words.w0 = 0x0C000000 | ((param_1) << 16) | ((param_2) & 0xFFFF); \
    local_cmd->words.w1 = (((param_3) & 0xFFFF) << 16) | ((param_4) & 0xFFFF); \
}
#define CMD_CLEAR(param_0, param_1, param_2) { \
    Acmd *local_cmd = (Acmd *)(param_0); \
    local_cmd->words.w0 = 0x02000000 | ((param_1) & 0xFFFFFF); \
    local_cmd->words.w1 = (u32)(param_2); \
}
#define CMD_MOVE(param_0, param_1, param_2, param_3) { \
    Acmd *local_cmd = (Acmd *)(param_0); \
    local_cmd->words.w0 = 0x0A000000 | ((param_1) & 0xFFFFFF); \
    local_cmd->words.w1 = (((param_2) & 0xFFFF) << 16) | ((param_3) & 0xFFFF); \
}

typedef struct { u8 pad0[0x20]; } LowPass_800272B0;
typedef struct { s32 input; s32 output; s16 ffcoef; s16 fbcoef; s16 gain; u8 padE[2]; f32 rsinc; u8 pad14[8]; f32 rsgain; LowPass_800272B0 *lp; void *rs; } Delay_800272B0;
typedef struct { s32 length; Delay_800272B0 *delay; u8 section_count; u8 pad9[0x20 - 9]; s16 *base[2]; s16 *input[2]; } Effect_800272B0;
typedef struct { u8 pad0[0x20]; Effect_800272B0 *fx; u8 pad24[0x48 - 0x24]; } AuxBus;
typedef struct { u8 pad0[0x34]; AuxBus *auxBus; } Synth_800272B0;
extern Synth_800272B0 *D_800411F4;
extern u8 D_8007EA33[];
extern u8 D_8007EA34[];
Acmd *func_8002BD40(s32, Acmd *, s32, s32 *);
typedef struct { s16 fc; } LowPass_80027AF0;
typedef struct { u32 input; u32 output; s16 ffcoef; s16 fbcoef; s16 gain; u8 padE[2]; f32 rsinc; u8 pad14[8]; f32 rsgain; LowPass_80027AF0 *lp; void *rs; } Delay_80027AF0;
typedef struct { u32 length; Delay_80027AF0 *delay; u8 section_count; } Effect_80027AF0;
typedef struct { u8 pad0[0x40]; s32 outputRate; } Synth_80027AF0;
typedef struct { u32 w0; u32 w1; } TTAcmd;
typedef struct { u8 pad0[0x14]; void *unk14[4]; /* 0x14: Tap-Quellen */ f32 unk24; /* 0x24: Frac-Akku */ s32 unk28; /* 0x28 */ } TTLine;
typedef struct { s32 unk0; /* 0x00 */ s32 unk4; /* 0x04 */ u8 pad8[8]; f32 unk10; /* 0x10 */ f32 unk14; /* 0x14 */ s32 unk18; /* 0x18 */ f32 unk1C; /* 0x1C */ u8 pad20[4]; TTLine *unk24; /* 0x24 */ } TTReverb;
typedef struct { u32 unk0; /* 0x00 */ u8 pad4[0x1C]; u8 *unk20[2]; /* 0x20 */ u8 *unk28[2]; /* 0x28 */ } TTBank;
typedef struct { u32 unk0; /* 0x00: Puffer-Laenge in Samples */ u8 pad4[0x1C]; u8 *unk20[4]; /* 0x20: Puffer-Basen */ } TTDlyD;
typedef struct { u8 pad0[2]; s16 unk2; /* 0x02 */ u8 pad4[4]; u32 unk8; /* 0x08 */ u8 padC[0x1C]; s32 unk28; /* 0x28 */ void *unk2C[2]; /* 0x2C */ } TTRvbF;
typedef struct { u8 pad0[0x10]; f32 unk10; /* 0x10: Rate */ f32 unk14; /* 0x14: Phase */ u8 pad18[4]; f32 unk1C; /* 0x1C: Depth */ } TTOscT;
extern f32 D_80041D10;
extern f32 D_80041D14;
extern f32 func_80013C48(f32, f32);
typedef struct { s16 unk0; /* 0x00 */ s16 unk2; /* 0x02 */ u8 pad4[4]; s16 unk8[16]; /* 0x08 */ s32 unk28; /* 0x28 */ } TTEnvA;
extern f32 D_80041D18;
extern f32 D_80041D1C;
typedef struct { s16 unk0; /* 0x00 */ s16 unk2; /* 0x02 */ u8 pad4[4]; s16 unk8[16]; /* 0x08 */ } TTFxC;
extern f32 D_80041D20;
extern f32 D_80041D24;
typedef struct { u8 pad0[0x14]; void *unk14; void *unk18; u8 pad1C[8]; f32 unk24; s32 unk28; u8 pad2C[0xC]; } ElemA;
typedef struct { s16 unk0; u8 pad2[0x2A]; void *unk2C; void *unk30; u8 pad34[4]; } ElemB;
typedef struct { u32 unk0; u32 unk4; s16 unk8; s16 unkA; s16 unkC; u8 padE[2]; f32 unk10; f32 unk14; s32 unk18; f32 unk1C; ElemB *unk20; ElemA *unk24; } Elem;
typedef struct { u32 unk0; Elem *unk4; u8 unk8; u8 pad9[0x17]; s16 *unk20; s16 *unk24; void *unk28; void *unk2C; } TTObj;
typedef struct { u8 pad0[0x18]; s32 unk18; u8 unk1C[4]; s32 *unk20[4]; } TTDesc;
extern void *func_80020EE4(s32, s32, void *, s32, s32);
extern s32 D_80041268[];
extern f32 D_80041D28;
typedef struct { u8 pad0[0xC]; void *unkC; /* 0x0C */ void *unk10; /* 0x10 */ u8 pad14[0x14]; void *unk28; /* 0x28 */ u8 unk2C; /* 0x2C */ u8 pad2D[7]; s32 unk34; /* 0x34 */ s32 unk38; /* 0x38 */ s32 unk3C; /* 0x3C */ void *unk40; /* 0x40 */ f32 unk44; /* 0x44 */ s32 unk48; /* 0x48 */ f32 unk4C; /* 0x4C */ s32 unk50; /* 0x50 */ void *unk54; /* 0x54 */ s16 unk58; /* 0x58 */ s16 unk5A; /* 0x5A */ s16 unk5C; /* 0x5C */ s16 unk5E; /* 0x5E */ s16 unk60; /* 0x60 */ s16 unk62; /* 0x62 */ s16 unk64; /* 0x64 */ s16 unk66; /* 0x66 */ s16 unk68; /* 0x68 */ u8 pad6A[4]; s16 unk6E; /* 0x6E */ s32 unk70; /* 0x70 */ s32 unk74; /* 0x74 */ s32 unk78; /* 0x78 */ s32 unk7C; /* 0x7C */ s32 unk80; /* 0x80 */ s32 unk84; /* 0x84 */ u8 pad88[4]; u8 unk8C; /* 0x8C */ u8 pad8D[3]; s16 unk90; /* 0x90 */ s16 unk92; /* 0x92 */ u8 pad94[0x24]; s32 unkB8; /* 0xB8 */ void *unkBC; /* 0xBC */ } TTVceI2;

/* Vorwaertsdeklarationen der Funktionen dieser TU. */
TTAcmd *func_80028010(TTBank *bank, TTReverb *r, s32 idx, s32 dmem, TTAcmd *cmdBuf);
TTAcmd *func_80028328(TTDlyD *d, s32 idx, u8 *pos, s32 dmem, s32 len, TTAcmd *cmdIn);
TTAcmd *func_80028520(TTDlyD *d, s32 idx, u8 *pos, s32 dmem, TTAcmd *cmdIn);
TTAcmd *func_800286FC(TTRvbF *r, s32 idx, s32 vol, TTAcmd *cmdIn);
f32 func_800287FC(TTOscT *p, s32 step);
void func_80028A24(TTEnvA *p);

Acmd *func_800272B0(s32 param_0, Acmd *param_1, s32 param_2)
{
    Acmd *local_0 = param_1;
    Effect_800272B0 *local_1 = D_800411F4->auxBus[param_2].fx;
    s16 local_2;
    s16 local_3;
    s16 local_4;
    s16 local_5;
    s16 local_6;
    s16 *local_7;
    s16 *local_8;
    s16 *local_10 = 0;
    Delay_800272B0 *local_11;
    s32 local_13 = 1;
    u32 local_14;

    local_0 = func_8002BD40(param_0, param_1, param_2, &local_13);
    local_5 = 0x7C0;
    local_6 = 0x930;
    local_3 = 0;
    local_4 = 0x170;

    if (D_8007EA33[param_2] == 0) {
        CMD_MIX(local_0++, 0, 0xC000, 0x7C0, local_5);
        CMD_MIX(local_0++, 0, 0x4000, 0x930, local_5);
    }

    local_0 = func_80028520(local_1, 0, local_1->input[0], local_5, local_0);
    if (D_8007EA33[param_2]) {
        local_0 = func_80028520(local_1, 1, local_1->input[1], 0x930, local_0);
    }

    for (local_14 = 0; local_14 <= D_8007EA33[param_2]; local_14++) {
        CMD_CLEAR(local_0++, local_6, 0x170);

        for (local_2 = 0; local_2 < local_1->section_count; local_2++) {
            local_11 = &local_1->delay[local_2];
            local_7 = &local_1->input[local_14][-local_11->input];
            local_8 = &local_1->input[local_14][-local_11->output];

            if (D_8007EA34[param_2] && D_8007EA33[param_2]) {
                local_11->ffcoef = -local_11->ffcoef;
                local_11->fbcoef = -local_11->fbcoef;
            }

            if (local_7 == local_10) {
                s16 local_15 = local_4;
                local_4 = local_3;
                local_3 = local_15;
            } else {
                local_0 = func_80028328(local_1, local_14, local_7, local_3, 0xB8, local_0);
            }

            local_0 = func_80028010(local_1, local_11, local_14, local_4, local_0);

            if (local_11->ffcoef) {
                CMD_MIX(local_0++, 0, (u16)local_11->ffcoef, local_3, local_4);
                if (!local_11->rs && !local_11->lp) {
                    local_0 = func_80028520(local_1, local_14, local_8, local_4, local_0);
                }
            }
            if (local_11->fbcoef) {
                CMD_MIX(local_0++, 0, (u16)local_11->fbcoef, local_4, local_3);
                local_0 = func_80028520(local_1, local_14, local_7, local_3, local_0);
            }
            if (local_11->lp) {
                local_0 = func_800286FC(local_11->lp, local_14, local_4, local_0);
            }
            if (!local_11->rs) {
                local_0 = func_80028520(local_1, local_14, local_8, local_4, local_0);
            }
            if (local_11->gain) {
                if (D_8007EA33[param_2]) {
                    CMD_MIX(local_0++, 0, (u16)local_11->gain, local_4, local_6);
                } else {
                    u32 local_16 = local_11->gain * 1.4141999483109f;
                    if (local_16 > 0x7FFF) {
                        local_16 = 0x7FFF;
                    }
                    CMD_MIX(local_0++, 0, (u16)local_16, local_4, local_6);
                }
            }
            local_10 = &local_1->input[local_14][local_11->output];
        }

        if (D_8007EA33[param_2] && local_14 == 0) {
            local_0 = func_80028328(local_1, 1, local_1->input[1], local_5, 0xB8, local_0);
            if (D_8007EA34[param_2]) {
                CMD_MIX(local_0++, 0, 0x5A82, local_6, 0x650);
            } else {
                CMD_MIX(local_0++, 0, 0x5A82, local_6, 0x4E0);
            }
        } else {
        }

        CMD_MOVE(local_0++, local_6, 0x7C0, 0x170);
        local_1->input[local_14] += 0xB8;
        if (local_1->input[local_14] > &local_1->base[local_14][local_1->length]) {
            local_1->input[local_14] -= local_1->length;
        }
    }
    return local_0;
}

s32 func_80027AF0(void *param_0, s32 param_1, void *param_2)
{
    Effect_80027AF0 *local_0 = (Effect_80027AF0 *)param_0;
    s32 local_1 = param_1 & 7;
    s32 local_2 = param_1 >> 3;
    s32 local_3 = *(s32 *)param_2;
    f32 local_4;

    if (local_2 >= local_0->section_count) {
        return 0;
    }

    switch (local_1) {
    case 0:
        local_0->delay[local_2].input =
            ((s32)local_3 * ((Synth_80027AF0 *) D_800411F4)->outputRate / 1000) & 0xFFFFFFF8;
        break;
    case 1:
        local_0->delay[local_2].output =
            ((s32)local_3 * ((Synth_80027AF0 *) D_800411F4)->outputRate / 1000) & 0xFFFFFFF8;
        break;
    case 2:
        local_0->delay[local_2].fbcoef = (s16)local_3;
        break;
    case 3:
        local_0->delay[local_2].ffcoef = (s16)local_3;
        break;
    case 4:
        local_0->delay[local_2].gain = (s16)local_3;
        break;
    case 5:
        local_0->delay[local_2].rsinc =
            ((((f32)local_3) / 1000.0f) * 2.0f) / ((Synth_80027AF0 *) D_800411F4)->outputRate;
        break;
    case 6:
        local_4 = local_3;
        break;
    case 7:
        if (local_0->delay[local_2].lp) {
            local_0->delay[local_2].lp->fc = (s16)local_3;
            func_80028A24(local_0->delay[local_2].lp);
        }
        break;
    }

    if (local_0->delay[local_2].input >= local_0->length - 16) {
        local_0->delay[local_2].input = local_0->length - 16;
    }
    if (local_0->delay[local_2].input >= local_0->length - 8) {
        local_0->delay[local_2].input = local_0->length - 8;
    }
    if (local_0->delay[local_2].input >= local_0->delay[local_2].output) {
        local_0->delay[local_2].output = local_0->delay[local_2].input + 8;
    }

    if (local_0->delay[local_2].rs) {
        if (local_1 != 6) {
            if ((local_0->delay[local_2].output - local_0->delay[local_2].input) != 0) {
                local_4 = (f32)local_0->delay[local_2].rsgain /
                    (local_0->delay[local_2].output - local_0->delay[local_2].input) *
                    173123.404906676f;
            } else {
                local_4 = 0;
            }
        }
        local_0->delay[local_2].rsgain =
            (local_0->delay[local_2].output - local_0->delay[local_2].input) *
            (local_4 / 173123.404906676f);
    }
    return 0;
}

TTAcmd *func_80028010(TTBank *bank, TTReverb *r, s32 idx, s32 dmem, TTAcmd *cmdBuf)
{
    TTAcmd *cmd = cmdBuf;
    s32 gain;
    s32 accInt;
    s32 dmemDflt = 0x2E0;
    u8 *pos;
    f32 acc;
    f32 invVal;
    f32 val;
    s32 align = 0;
    s32 len;
    s32 budget = 0xB8;
    s16 var2A;
    TTAcmd *p1;

    if (r->unk24 != 0) {
        len = r->unk4 - r->unk0;

        val = func_800287FC(r, budget);
        val = val / (f32)len;
        val = (f32)(s32)(val * 32768.0f);
        val = val / 32768.0f;
        invVal = 1.0f - val;

        acc = r->unk24->unk24 + invVal * (f32)budget;
        accInt = (s32)acc;
        r->unk24->unk24 = acc - (f32)accInt;

        pos = bank->unk28[idx] + -(r->unk4 - r->unk18) * 2;
        align = ((s32)pos & 7) >> 1;

        cmd = func_80028328(bank, idx, pos - align * 2, dmemDflt, accInt + align, cmd);

        gain = (s32)(invVal * 32768.0f);
        var2A = dmem >> 8;

        p1 = cmd++;
        p1->w0 = (osVirtualToPhysical(r->unk24->unk14[idx]) & 0xFFFFFF) | 0x05000000;
        p1->w1 = ((r->unk24->unk28 & 3) << 30) | ((gain & 0xFFFF) << 14)
               | (((dmemDflt + align * 2) & 0xFFF) << 2) | (var2A & 3);
        r->unk24->unk28 = 0;

        r->unk18 = r->unk18 + (accInt - budget);
    } else {
        pos = bank->unk28[idx] + -r->unk4 * 2;
        cmd = func_80028328(bank, idx, pos, dmem, 0xB8, cmd);
    }

    return cmd;
}

TTAcmd *func_80028328(TTDlyD *d, s32 idx, u8 *pos, s32 dmem, s32 len, TTAcmd *cmdIn)
{
    TTAcmd *cmd = cmdIn;
    s32 len2;
    s32 len1;
    u8 *end;
    u8 *loopEnd;
    TTAcmd *p1;
    TTAcmd *p2;
    TTAcmd *p3;

    loopEnd = d->unk20[idx] + d->unk0 * 2;

    if (pos < d->unk20[idx]) {
        pos += d->unk0 * 2;
    }

    end = len * 2 + pos;

    if (end > loopEnd) {
        len2 = (end - loopEnd) >> 1;
        len1 = (loopEnd - pos) >> 1;

        p1 = cmd++;
        p1->w0 = ((len1 * 2 & 0xFFF) << 12) | 0x04000000 | (dmem & 0xFFF);
        p1->w1 = osVirtualToPhysical(pos);

        p2 = cmd++;
        p2->w0 = ((len2 * 2 & 0xFFF) << 12) | 0x04000000 | ((dmem + len1 * 2) & 0xFFF);
        p2->w1 = osVirtualToPhysical(d->unk20[idx]);
        if (1) {}
    } else {
        p3 = cmd++;
        p3->w0 = ((len * 2 & 0xFFF) << 12) | 0x04000000 | (dmem & 0xFFF);
        p3->w1 = osVirtualToPhysical(pos);
    }

    return cmd;
}

TTAcmd *func_80028520(TTDlyD *d, s32 idx, u8 *pos, s32 dmem, TTAcmd *cmdIn)
{
    TTAcmd *cmd = cmdIn;
    s32 len2;
    s32 len1;
    u8 *end;
    u8 *loopEnd;
    TTAcmd *p1;
    TTAcmd *p2;
    TTAcmd *p3;

    loopEnd = d->unk20[idx] + d->unk0 * 2;

    if (pos < d->unk20[idx]) {
        pos += d->unk0 * 2;
    }

    end = pos + 0x170;

    if (end > loopEnd) {
        len2 = (end - loopEnd) >> 1;
        len1 = (loopEnd - pos) >> 1;

        p1 = cmd++;
        p1->w0 = ((len1 * 2 & 0xFFF) << 12) | 0x06000000 | (dmem & 0xFFF);
        p1->w1 = osVirtualToPhysical(pos);

        p2 = cmd++;
        p2->w0 = ((len2 * 2 & 0xFFF) << 12) | 0x06000000 | ((dmem + len1 * 2) & 0xFFF);
        p2->w1 = osVirtualToPhysical(d->unk20[idx]);
        if (1) {}
    } else {
        p3 = cmd++;
        p3->w0 = (dmem & 0xFFF) | 0x06170000;
        p3->w1 = osVirtualToPhysical(pos);
    }

    return cmd;
}

TTAcmd *func_800286FC(TTRvbF *r, s32 idx, s32 vol, TTAcmd *cmdIn)
{
    TTAcmd *c = cmdIn;
    s16 gain;
    TTAcmd *p1;
    TTAcmd *p2;

    gain = vol >> 8;

    p1 = c++;
    p1->w0 = 0x0B000020;
    p1->w1 = osVirtualToPhysical(&r->unk8);

    p2 = c++;
    p2->w0 = (((r->unk28 & 0xFF) << 16) | 0x0E000000) | (r->unk2 & 0xFFFF);
    p2->w1 = (osVirtualToPhysical(r->unk2C[idx]) & 0xFFFFFF) | ((gain & 0xFF) << 24);

    r->unk28 = 0;

    return c;
}

f32 func_800287FC(TTOscT *p, s32 step)
{
    f32 t;

    p->unk14 += p->unk10 * (f32)step;

    if (p->unk14 > 2.0f)
        p->unk14 = p->unk14 - 4.0f;
    else
        p->unk14 = p->unk14;

    t = p->unk14;
    t = (t < 0.0f) ? -t : t;

    t = t - 1.0f;
    return p->unk1C * t;
}

void func_800288C0(f32 a, f32 b, f32 c, f32 *out1, f32 *out2)
{
    f32 s;
    f32 s2;
    f32 q;

    if (b >= a - 200.0f)
        b = a - 200.0f;

    s = func_80013C48(b * D_80041D10, a);
    s2 = s * s;
    q = s * D_80041D14 / c;

    *out1 = s2 / (1.0f + s2 + q);
    out1[1] = *out1 * 2.0f;
    out1[2] = *out1;

    out2[1] = (s2 - 1.0f) * 2.0f / (1.0f + s2 + q);
    out2[2] = (1.0f + s2 - q) / (1.0f + s2 + q);
}

void func_80028A24(TTEnvA *p)
{
    s32 i;
    s32 tmp;
    s16 half;
    f32 r8;
    f32 r4;
    f32 max;

    tmp = (s32)((f32)p->unk0 * 16384.0f);
    half = tmp >> 15;
    p->unk2 = (s32)(16384.0f - (f32)half);
    p->unk28 = 0;

    for (i = 0; i < 8; i++)
        p->unk8[i] = 0;

    p->unk8[i] = half;
    i++;

    max = 16384.0f;
    r4 = r8 = (f32)half / max;

    for (; i < 0x10; i++) {
        r4 = r4 * r8;
        p->unk8[i] = (s32)(r4 * max);
    }
}

f32 func_80028B74(s32 e)
{
    f32 base;
    f32 r;

    r = 1.0f;
    if (e >= 0) {
        base = D_80041D18;
    } else {
        base = D_80041D1C;
        e = -e;
    }

    while (e != 0) {
        if (e & 1) {
            r = r * base;
        }
        base = base * base;
        e = e >> 1;
    }

    return r;
}

void func_80028C04(TTFxC *p, f32 rate)
{
    s32 i;
    f32 o1[3];
    f32 o2[3];

    if (p->unk2 == 0)
        return;

    if (p->unk2 < 0xA)
        p->unk2 = 0xA;

    func_800288C0(rate, (f32)p->unk0 + 10.0f, (f32)p->unk2 / 10.0f, o1, o2);

    for (i = 3; i < 8; i++)
        p->unk8[i] = 0;

    p->unk8[0] = (s32)(o1[0] * (D_80041D20 - (f32)p->unk2 * 128.0f));
    p->unk8[1] = (s32)(o1[1] * (D_80041D24 - (f32)p->unk2 * 128.0f));
    p->unk8[2] = 0;
    p->unk8[8] = (s32)(o2[1] * -16384.0f);
    p->unk8[9] = (s32)(o2[2] * -16384.0f);

    for (i = 0xA; i < 0x10; i++)
        p->unk8[i] = 0;
}

void func_80028DF0(TTObj **out, TTDesc *desc, s32 idx, void *heap)
{
    u16 i;
    u16 k;
    u16 j;
    s32 *tbl;
    Elem *elem;
    TTObj *obj;

    tbl = 0;
    obj = func_80020EE4(0, 0, heap, 1, 0x30);
    *out = obj;

    switch (desc->unk1C[(s16)idx]) {
    case 6:
        tbl = desc->unk20[(s16)idx];
        break;
    default:
        tbl = D_80041268;
        break;
    }

    k = 0;
    obj->unk8 = tbl[k];
    k++;
    obj->unk0 = tbl[k];
    k++;

    obj->unk4 = func_80020EE4(0, 0, heap, obj->unk8, 0x28);
    obj->unk20 = func_80020EE4(0, 0, heap, obj->unk0, 2);
    obj->unk28 = obj->unk20;
    obj->unk24 = func_80020EE4(0, 0, heap, obj->unk0, 2);
    obj->unk2C = obj->unk24;

    for (j = 0; j < obj->unk0; j++) {
        obj->unk24[j] = 0;
        obj->unk20[j] = obj->unk24[j];
    }

    for (i = 0; i < obj->unk8; i++) {
        {
            elem = &obj->unk4[i];
            elem->unk0 = tbl[k];
            k++;
            elem->unk4 = tbl[k];
            k++;
            elem->unkA = tbl[k];
            k++;
            elem->unk8 = tbl[k];
            k++;
            elem->unkC = tbl[k];
            k++;
            if (tbl[k] != 0) {
                elem->unk10 = (f32)tbl[k] / 1000.0f * 2.0f / (f32)desc->unk18;
                k++;
                elem->unk1C = (f32)tbl[k] / D_80041D28 * (f32)(u32)(elem->unk4 - elem->unk0);
                k++;
                elem->unk14 = 1.0f;
                elem->unk18 = 0;
                elem->unk24 = func_80020EE4(0, 0, heap, 1, 0x38);
                elem->unk24->unk14 = func_80020EE4(0, 0, heap, 1, 0x20);
                elem->unk24->unk18 = func_80020EE4(0, 0, heap, 1, 0x20);
                elem->unk24->unk24 = 0.0f;
                elem->unk24->unk28 = 1;
            } else {
                elem->unk24 = 0;
                k++;
                k++;
            }
            if (tbl[k] != 0) {
                elem->unk20 = func_80020EE4(0, 0, heap, 1, 0x38);
                elem->unk20->unk2C = func_80020EE4(0, 0, heap, 1, 8);
                elem->unk20->unk30 = func_80020EE4(0, 0, heap, 1, 8);
                elem->unk20->unk0 = tbl[k];
                k++;
                func_80028A24(elem->unk20);
            } else {
                elem->unk20 = 0;
                k++;
            }
        }
    }
}

void func_800293B4(TTVceI2 *v, void *(*fn)(void *), void *heap)
{
    v->unkC = func_80020EE4(0, 0, heap, 1, 0x20);
    v->unk10 = func_80020EE4(0, 0, heap, 1, 0x20);
    v->unk28 = fn(&v->unk2C);
    v->unk34 = 0;
    v->unk38 = 1;
    v->unk3C = 0;
    v->unk40 = func_80020EE4(0, 0, heap, 1, 0x20);
    v->unk4C = 0.0f;
    v->unk50 = 1;
    v->unk44 = 1.0f;
    v->unk48 = 0;
    v->unk54 = func_80020EE4(0, 0, heap, 1, 0x50);
    v->unk78 = 1;
    v->unk84 = 0;
    v->unk5A = 1;
    v->unk68 = 1;
    v->unk6E = 1;
    v->unk5C = 1;
    v->unk5E = 1;
    v->unk60 = 0;
    v->unk62 = 0;
    v->unk66 = 1;
    v->unk64 = 0;
    v->unk66 = 1;
    v->unk64 = 0;
    v->unk70 = 0;
    v->unk74 = 0;
    v->unk58 = 0;
    v->unk7C = 0;
    v->unk80 = 0;
    v->unk8C = 0;
    v->unk92 = 0;
    v->unk90 = 0;
    v->unkBC = func_80020EE4(0, 0, heap, 1, 8);
    v->unkB8 = 0;
}
