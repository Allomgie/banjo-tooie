#include "common.h"
#define M127(v) ((v) >= 0x80 ? 0x7F : (v))

typedef struct TTVceU_s { struct TTVceU_s *unk0; /* 0x00 */ u8 unk4; /* 0x04: Handle-Basis */ u8 pad5[0x1B]; void *unk20; /* 0x20 */ } TTVceU;
typedef struct { u8 pad0[0x64]; TTVceU *unk64; /* 0x64 */ TTVceU *unk68; /* 0x68 */ TTVceU *unk6C; /* 0x6C */ u8 pad70[0x19]; u8 unk89; /* 0x89 */ } TTSeqV;
extern void func_800E90A4(void *, s32);
typedef struct { s16 type; /* 0x0 */ u8 pad2[2]; void *p; /* 0x4 */ u8 pad8[8]; } TTEvtP;
typedef struct TTItemS2_s { struct TTItemS2_s *unk0; /* 0x00 */ u8 pad4[4]; s32 unk8; /* 0x08 */ s16 unkC; /* 0x0C */ u8 padE[2]; void *unk10; /* 0x10 */ } TTItemS2;
typedef struct { u8 pad0[0x28]; s32 unk28; /* 0x28 */ u8 pad2C[8]; u8 unk34; /* 0x34 */ u8 pad35[2]; u8 unk37; /* 0x37 */ u8 unk38; /* 0x38 */ } TTVceS;
typedef struct { u8 pad0[0x10]; TTVceS *unk10; /* 0x10 */ } TTHdlS;
typedef struct { u8 pad0[0x1C]; s32 unk1C; /* 0x1C */ u8 pad20[0x28]; u8 evtq48; /* 0x48 */ u8 pad49[7]; TTItemS2 *unk50; /* 0x50 */ } TTSeqS;
extern void func_80020E74(void *);
extern void func_80020E40(void *, void *);
extern void func_8002C5A0(TTHdlS *, s32);
extern void func_80026BE0(TTHdlS *, s32, s32);
extern void func_80026500(void *, TTEvtP *, s32, s32);
typedef struct TTItemE2_s { struct TTItemE2_s *unk0; /* 0x00 */ u8 pad4[4]; s32 unk8; /* 0x08: delta */ s16 unkC; /* 0x0C: type */ u8 padE[2]; void *unk10; /* 0x10 */ } TTItemE2;
typedef struct { u8 pad0[0x48]; u8 evtq48; /* 0x48 */ u8 pad49[7]; TTItemE2 *unk50; /* 0x50 */ } TTSeqE;
typedef struct TTVceA_s { struct TTVceA_s *unk0; /* 0x00 */ u8 pad4[0x10]; struct TTVceA_s *unk14; /* 0x14 */ u8 pad18[0x10]; s32 unk28; /* 0x28 */ u8 pad2C[9]; u8 unk35; /* 0x35 */ u8 unk36; /* 0x36 */ u8 unk37; /* 0x37 */ } TTVceA;
typedef struct { u8 pad0[0x64]; TTVceA *unk64; /* 0x64 */ TTVceA *unk68; /* 0x68 */ TTVceA *unk6C; /* 0x6C */ u8 pad70[0x18]; u8 unk88; /* 0x88 */ u8 unk89; /* 0x89 */ } TTSeqA;
extern void func_800E9070(void *, s32);
typedef struct TTVceS2_s { struct TTVceS2_s *unk0; /* 0x00 */ u8 pad4[0x31]; u8 unk35; /* 0x35: Note */ u8 unk36; /* 0x36: Kanal */ u8 pad37[2]; u8 unk39; /* 0x39: Status */ } TTVceS2;
typedef struct { u8 pad0[0x64]; TTVceS2 *unk64; /* 0x64 */ } TTSeqS2;
typedef struct { u8 unk0; /* 0x00: velMin */ u8 unk1; /* 0x01: velMax */ u8 unk2; /* 0x02: keyMin */ u8 unk3; /* 0x03: keyMax */ } TTKmB;
typedef struct { u8 pad0[0x33]; u8 unk33; /* 0x33: Instrument */ s8 unk34; /* 0x34: Cache */ u8 pad35[3]; } TTChanB;
typedef struct { u8 pad0[0x60]; TTChanB *unk60; /* 0x60 */ } TTSeqB;
extern s32 func_800E9054(s32);
typedef struct { u8 pad0[0xD5]; u8 sampleVolume; } Sound;
typedef struct { u8 pad0[0x20]; Sound *sound; u8 pad24[0x10]; u8 envGain; u8 channel; u8 pad36; u8 velocity; u8 pad38[2]; u8 tremelo; } VoiceState;
typedef struct { u8 pad0[5]; u8 vol; u8 pad6[3]; u8 unk9; u8 padA[0x38 - 0xA]; } ChannelState_80029D54;
typedef struct { u8 pad0[0x34]; s16 vol; u8 pad36[0x60 - 0x36]; ChannelState_80029D54 *chanState; } SeqPlayer_80029D54;
typedef struct { u8 pad0[6]; u8 unk6; /* 0x06 */ u8 pad7[0x31]; } TTChanP;
typedef struct { u8 pad0[0x60]; TTChanP *unk60; /* 0x60 */ u8 pad64[0x18]; f32 unk7C; /* 0x7C */ f32 unk80; /* 0x80 */ } TTSeqP;
typedef struct { u8 pad0[0x35]; u8 unk35; /* 0x35 */ } TTVceP;
typedef struct { u8 pad0[0x28]; s32 unk28; /* 0x28 */ } TTVceR5;
typedef struct { u8 pad0[0xD4]; u8 unkD4; /* 0xD4 */ } TTPlyrR;
typedef struct { u8 pad0[0x20]; TTPlyrR *unk20; /* 0x20 */ u8 pad24[0x11]; u8 unk35; /* 0x35 */ } TTVceR6;
typedef struct { u8 pad0[3]; u8 unk3; /* 0x03 */ u8 pad4[0x34]; } TTChanR;
typedef struct { u8 pad0[0x60]; TTChanR *unk60; /* 0x60 */ } TTSeqR6;
typedef struct { u8 pad0[0x36]; u8 unk36; /* 0x36 */ } TTSeqR8;
typedef struct { u8 pad0[0x33]; u8 unk33; /* 0x33 */ u8 pad34[4]; } TTChanR2;
typedef struct { u8 pad0[0x36]; u8 unk36; /* 0x36 */ u8 pad37[0x29]; TTChanR2 *unk60; /* 0x60 */ } TTSeqR7;
typedef struct { s16 unk0; u8 unk2; u8 unk3; u8 unk4; u8 unk5; u8 unk6; u8 unk7; u8 unk8; u8 unk9; u8 unkA; u8 unkB; u8 unkC; u8 unkD; u8 unkE; u8 unkF; u8 unk10; u8 unk11; u8 unk12; u8 unk13; f32 unk14; u8 pad18[0x32 - 0x18]; u8 unk32; u8 pad33[0x38 - 0x33]; } ChannelState_8002A150;
typedef struct { u8 pad0[0x60]; ChannelState_8002A150 *chanState; } SeqPlayer_8002A150;
typedef struct { u8 unk0; /* 0x00 */ u8 unk1; /* 0x01 */ u8 unk2; /* 0x02 */ u8 pad3[1]; u8 unk4; /* 0x04 */ u8 unk5; /* 0x05 */ u8 unk6; /* 0x06 */ u8 unk7; /* 0x07 */ u8 unk8; /* 0x08 */ u8 unk9; /* 0x09 */ u8 unkA; /* 0x0A */ u8 unkB; /* 0x0B */ s16 unkC; /* 0x0C */ } TTInstrI;
typedef struct { s32 unk0; /* 0x00 */ s32 unk4; /* 0x04 */ s32 unk8; /* 0x08 */ u8 unkC; /* 0x0C */ u8 unkD; /* 0x0D */ } TTWaveI;
typedef struct { s16 unk0; /* 0x00 */ u8 pad2[1]; u8 unk3; /* 0x03 */ u8 unk4; /* 0x04 */ u8 unk5; /* 0x05 */ u8 pad6[0x12]; s32 unk18; /* 0x18 */ s32 unk1C; /* 0x1C */ s32 unk20; /* 0x20 */ u8 unk24; /* 0x24 */ u8 unk25; /* 0x25 */ u8 unk26; /* 0x26 */ u8 unk27; /* 0x27 */ u8 unk28; /* 0x28 */ u8 unk29; /* 0x29 */ u8 unk2A; /* 0x2A */ u8 unk2B; /* 0x2B */ u8 unk2C; /* 0x2C */ u8 unk2D; /* 0x2D */ u8 unk2E; /* 0x2E */ u8 unk2F; /* 0x2F */ u8 pad30[1]; u8 unk31; /* 0x31 */ u8 pad32[1]; u8 unk33; /* 0x33 */ u8 pad34[4]; } TTChanI;
typedef struct { u8 pad0[0x60]; TTChanI *unk60; /* 0x60 */ } TTSeqI;
extern TTInstrI *func_800E93AC(s32);
extern TTWaveI *func_800E9300(s32, s32);
typedef struct TTItemE3_s { struct TTItemE3_s *unk0; /* 0x00 */ u8 pad4[4]; s32 unk8; /* 0x08 */ s16 unkC; /* 0x0C */ u8 padE[2]; void *unk10; /* 0x10 */ void *unk14; /* 0x14 */ } TTItemE3;
typedef struct { u8 pad0[0x3B]; u8 unk3B; /* 0x3B */ } TTHdl2;
typedef struct { u8 pad0[0x48]; u8 evtq48; /* 0x48 */ u8 pad49[7]; TTItemE3 *unk50; /* 0x50 */ u8 pad54[0x24]; void (*unk78)(void *); /* 0x78 */ } TTSeqE2;
typedef struct { s32 unk0; /* 0x00 */ s32 unk4; /* 0x04: Zeit */ s16 type; /* 0x08 */ u8 padA[2]; union { s32 i; /* 0x0C */ f32 f; } uC; } TTQEvtV;
typedef struct { u8 pad0[0x88]; s32 unk88; /* 0x88 */ } TTVceV;
typedef struct { u8 pad0[0x8]; TTVceV *unk8; /* 0x08 */ } TTHdlV;
typedef struct { u8 pad0[0x1C]; s32 unk1C; /* 0x1C: globale Zeit */ } TTAMgrV;
extern TTAMgrV *D_800411F4;
extern TTQEvtV *func_80021794(void);
extern s32 func_8002B684(TTVceV *, s32, TTQEvtV *);
typedef struct { u8 pad0[4]; void *(*unk4)(); /* 0x04 */ } TTSynthR;
typedef struct { u8 pad0[0x20]; void *unk20; /* 0x20 */ u8 pad24[0x20]; void *unk44; /* 0x44 */ } TTSlotR;
typedef struct { u8 pad0[0x30]; TTSynthR *unk30; /* 0x30 */ TTSlotR *unk34; /* 0x34 */ } TTAMgrR;
extern void *func_800272B0();
extern void func_80027AF0();
typedef struct { s16 unk0; /* 0x00 */ s16 unk2; /* 0x02 */ } TTFxA;
typedef struct { u8 pad0[0x40]; s32 unk40; /* 0x40 */ } TTAMgrA;
extern f32 D_80041D30;
extern void func_80028C04(void *, f32);

/* Vorwaertsdeklarationen der Funktionen dieser TU. */
void func_8002A150(SeqPlayer_8002A150 *param_0, s32 param_1);
void func_8002A318(TTSeqI *p, s32 bank, s32 chan);

void func_80029670(TTSeqV *p, void *h)
{
    TTVceU *prev;
    TTVceU *it;

    prev = 0;
    for (it = p->unk64; it != 0; it = it->unk0) {
        if ((void *)&it->unk4 == h) {
            if (prev != 0)
                prev->unk0 = it->unk0;
            else
                p->unk64 = it->unk0;

            if (p->unk68 == it)
                p->unk68 = prev;

            func_800E90A4(it->unk20, 1);

            it->unk0 = p->unk6C;
            p->unk6C = it;
            p->unk89--;
            return;
        }
        prev = it;
    }
}

void func_8002976C(TTSeqS *p, TTHdlS *h, s32 t)
{
    TTEvtP evt;
    TTVceS *v;
    TTItemS2 *it;
    TTItemS2 *next;
    TTItemS2 *cur;
    TTItemS2 *nx2;

    v = h->unk10;

    if (v->unk38 == 0) {
        it = p->unk50;
        while (it != 0) {
            next = it->unk0;
            cur = it;
            nx2 = next;

            if (cur->unkC == 6) {
                if (cur->unk10 == h) {
                    if (nx2 != 0) {
                        nx2->unk8 += cur->unk8;
                    }
                    func_80020E74(it);
                    func_80020E40(it, &p->evtq48);
                }
            }

            it = next;
        }
    }

    v->unk37 = 0;
    v->unk38 = 3;
    v->unk34 = 0;
    v->unk28 = p->unk1C + t;

    func_8002C5A0(h, 0);
    func_80026BE0(h, 0, t);

    evt.type = 5;
    evt.p = h;
    t += 0x7D00;
    func_80026500(&p->evtq48, &evt, t, 0);
}

u8 func_800298E4(TTSeqE *p, void *match, s32 limit)
{
    TTItemE2 *it;
    TTItemE2 *next;
    TTItemE2 *cur;
    s32 sum;
    u8 found;

    sum = 0;
    found = 1;

    it = p->unk50;
    while (it != 0) {
        next = it->unk0;
        cur = it;

        sum += cur->unk8;

        if (cur->unkC == 5) {
          if (cur->unk10 == match) {
            if (sum > limit) {
                if (next != 0)
                    next->unk8 += cur->unk8;
                func_80020E74(it);
                func_80020E40(it, &p->evtq48);
            } else {
                found = 0;
            }
            break;
          }
        }

        it = next;
    }

    return found;
}

TTVceA *func_80029A04(TTSeqA *p, u8 b, u8 c, u8 d, void *e)
{
    TTVceA *v;

    v = p->unk6C;

    if (p->unk89 > p->unk88)
        return 0;

    if (v != 0) {
        p->unk6C = v->unk0;
        v->unk0 = 0;

        if (p->unk64 == 0)
            p->unk64 = v;
        else
            p->unk68->unk0 = v;

        p->unk68 = v;
        v->unk35 = d;
        v->unk36 = b;
        v->unk37 = c;
        v->unk14 = v;
        v->unk28 = 0;
        p->unk89++;

        func_800E9070(e, 1);
    }

    return v;
}

TTVceS2 *func_80029B18(TTSeqS2 *p, u8 chan, u8 note)
{
    TTVceS2 *v;

    for (v = p->unk64; v != 0; v = v->unk0) {
        if (v->unk36 == chan && v->unk35 == note
            && v->unk39 != 3 && v->unk39 != 4) {
            return v;
        }
    }

    return 0;
}

void *func_80029BA0(TTSeqB *p, u8 key, u8 vel, u8 chan)
{
    s32 instr;
    s32 hi;
    s32 lo;
    s32 mid;
    TTKmB *km;
    void *w;

    instr = p->unk60[chan].unk33;
    hi = 1;
    lo = func_800E9054(instr);

    while (lo >= hi) {
        mid = (hi + lo) / 2;

        w = func_800E9300(instr, mid - 1);
        km = (TTKmB *)((u8 *)w + 0x10);

        if (key >= km->unk2 && key <= km->unk3 && vel >= km->unk0 && vel <= km->unk1) {
            p->unk60[chan].unk34 = mid - 1;
            return w;
        } else if (key < km->unk2 || (vel < km->unk0 && key <= km->unk3))
            lo = mid - 1;
        else
            hi = mid + 1;
    }

    return 0;
}

s16 func_80029D54(VoiceState *param_0, SeqPlayer_80029D54 *param_1)
{
    u32 local_0;
    u32 local_1;

    local_0 = (param_0->tremelo * param_0->velocity * param_0->envGain) >> 6;
    local_1 = (param_1->chanState[param_0->channel].vol *
               (param_0->sound->sampleVolume * param_1->vol)) >> 14;
    if (param_1->chanState[param_0->channel].unk9 != 0xFF) {
        local_1 = ((param_1->chanState[param_0->channel].unk9 * local_1) + 1) >> 8;
    }
    local_0 *= local_1;
    local_0 >>= 15;
    return local_0;
}

u8 func_80029E64(TTVceP *v, TTSeqP *p)
{
    s32 hi;
    s32 x;

    hi = p->unk60[v->unk35].unk6 & 0x80;
    x = (s32)((f32)((p->unk60[v->unk35].unk6 & 0x7F) + (s32)(p->unk7C * 127.0f)) * p->unk80);

    return ((M127(x) < 0) ? 0 : M127(x)) | hi;
}

s32 func_80029F5C(TTVceR5 *v, s32 t)
{
    s32 d;

    d = v->unk28 - t;
    if (d >= 0)
        return d;
    else
        return 0x3E8;
}

u8 func_80029FA0(TTVceR6 *v, TTSeqR6 *p)
{
    s32 x;

    x = p->unk60[v->unk35].unk3 + v->unk20->unkD4 - 0x40;

    if (x > 0) {} else { x = 0; }
    if (x < 0x7F) {} else { x = 0x7F; }

    return x;
}

void func_8002A024(TTSeqR8 *p, s32 arg1)
{
    s32 i;
    s32 frame;

    for (frame = 0; func_800E9054(frame) == 0; frame++);

    for (i = 0; i < p->unk36; i++) {
        func_8002A150(p, i);
        func_8002A318(p, frame, i);
    }
}

void func_8002A0CC(TTSeqR7 *p)
{
    s32 i;

    for (i = 0; i < p->unk36; i++) {
        p->unk60[i].unk33 = 0;
        func_8002A150(p, i);
    }
}

void func_8002A150(SeqPlayer_8002A150 *param_0, s32 param_1)
{
    param_0->chanState[param_1].unk2 = 0;
    param_0->chanState[param_1].unk6 = 0;
    param_0->chanState[param_1].unk3 = 0x40;
    param_0->chanState[param_1].unk5 = 0x7F;
    param_0->chanState[param_1].unk4 = 5;
    param_0->chanState[param_1].unk8 = 0;
    param_0->chanState[param_1].unk0 = 0xC8;
    param_0->chanState[param_1].unk14 = 1.0f;
    param_0->chanState[param_1].unk10 = 0;
    param_0->chanState[param_1].unk9 = 0xFF;
    param_0->chanState[param_1].unkA = 0xFF;
    param_0->chanState[param_1].unkB = 0;
    param_0->chanState[param_1].unk7 = 0;
    param_0->chanState[param_1].unk13 = 0;
    param_0->chanState[param_1].unk12 = 0;
    param_0->chanState[param_1].unk11 = 0;
    param_0->chanState[param_1].unk32 = 0;
}

void func_8002A318(TTSeqI *p, s32 bank, s32 chan)
{
    TTInstrI *ins;
    TTWaveI *w;

    ins = func_800E93AC(bank);

    p->unk60[chan].unk33 = bank;
    p->unk60[chan].unk3 = ins->unk1;
    p->unk60[chan].unk5 = ins->unk0;
    p->unk60[chan].unk4 = ins->unk2;
    p->unk60[chan].unk0 = ins->unkC;

    if (func_800E9054(bank) == 0)
        return;

    w = func_800E9300(bank, 0);

    p->unk60[chan].unk18 = w->unk0;
    p->unk60[chan].unk1C = w->unk4;
    p->unk60[chan].unk20 = w->unk8;
    p->unk60[chan].unk25 = w->unkC;
    p->unk60[chan].unk26 = w->unkD;
    p->unk60[chan].unk27 = 0;
    p->unk60[chan].unk28 = ins->unk4;
    p->unk60[chan].unk29 = ins->unk5;
    p->unk60[chan].unk2A = ins->unk6;
    p->unk60[chan].unk2B = ins->unk7;
    p->unk60[chan].unk2C = ins->unk8;
    p->unk60[chan].unk2D = ins->unk9;
    p->unk60[chan].unk2E = ins->unkA;
    p->unk60[chan].unk2F = ins->unkB;
    p->unk60[chan].unk24 = 0;
    p->unk60[chan].unk31 = 0;
}

void func_8002A6A4(TTSeqE2 *p, TTHdl2 *h)
{
    TTItemE3 *it;
    TTItemE3 *next;
    s16 t;

    it = p->unk50;
    while (it != 0) {
        next = it->unk0;
        t = it->unkC;

        if (t == 0x16 || t == 0x17) {
            if (it->unk10 == h) {
                (p->unk78)(it->unk14);
                func_80020E74(it);

                if (next != 0) {
                    next->unk8 += it->unk8;
                }

                func_80020E40(it, &p->evtq48);

                if (t == 0x16)
                    h->unk3B = h->unk3B & 0xFE;
                else
                    h->unk3B = h->unk3B & 0xFD;

                if (h->unk3B == 0)
                    return;
            }
        }

        it = next;
    }
}

void func_8002A7E0(TTHdlV *h, f32 val)
{
    TTQEvtV *evt;

    if (h->unk8 != 0) {
        evt = func_80021794();
        if (evt == 0)
            return;

        evt->unk4 = D_800411F4->unk1C + h->unk8->unk88;
        evt->type = 0x13;
        evt->uC.f = val;
        evt->unk0 = 0;
        func_8002B684(h->unk8, 3, evt);
    }
}

void func_8002A890(TTHdlV *h, u8 val)
{
    TTQEvtV *evt;

    if (h->unk8 != 0) {
        evt = func_80021794();
        if (evt == 0)
            return;

        evt->unk4 = D_800411F4->unk1C + h->unk8->unk88;
        evt->type = 0x12;
        evt->uC.i = val;
        evt->unk0 = 0;
        func_8002B684(h->unk8, 3, evt);
    }
}

void *func_8002A940(idx) s16 idx;
{
    TTSynthR *s;

    s = ((TTAMgrR *) D_800411F4)->unk30;
    if (s->unk4 == func_800272B0)
        return ((TTAMgrR *) D_800411F4)->unk34[idx].unk20;
    else
        return 0;
}

void *func_8002A9B8(idx) s16 idx;
{
    TTSynthR *s;

    s = ((TTAMgrR *) D_800411F4)->unk30;
    if (s->unk4 == func_800272B0)
        return ((TTAMgrR *) D_800411F4)->unk34[idx].unk44;
    else
        return 0;
}

void func_8002AA30(void *p, s16 x, void *y)
{
    void *v = p;

    func_80027AF0(v, x, y);
}

void func_8002AA74(TTFxA *p, s16 type, s32 *val)
{
    if (type == 8) {
        p->unk2 = (s32)((f32)*val * D_80041D30);
    } else if (type == 9) {
        p->unk0 = *val;
    }

    func_80028C04(p, (f32)((TTAMgrA *) D_800411F4)->unk40);
}
