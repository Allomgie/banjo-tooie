#include "common.h"

typedef struct { u8 pad[0x48]; u8 evtq; /* 0x48 */ } TTCSPq;
typedef struct { s16 type; /* 0x0 */ union { struct { s32 ticks; /* 0x4 */ u8 status; /* 0x8 */ u8 chan; /* 0x9 */ u8 byte2; /* 0xA */ u8 byte3; /* 0xB */ s32 duration; /* 0xC */ } midi; } msg; } TTEvtA;
extern void func_80026500(void *, TTEvtA *, s32, s32);
typedef struct { u32 w0; u32 w1; } TTAcmd;
typedef struct TTItemE_s { struct TTItemE_s *unk0; /* 0x00: next */ s32 unk4; /* 0x04: Zeit */ union { s16 s; /* 0x08: Typ */ u16 u; } u8; s16 unkA; /* 0x0A */ union { void *p; /* 0x0C */ f32 f; s32 i; struct { s16 hi; /* 0x0C */ s16 lo; /* 0x0E */ } h; } uC; union { s32 i; /* 0x10 */ struct { s16 h; /* 0x10 */ u8 b12; /* 0x12 */ u8 b13; /* 0x13 */ } s; } u10; u8 unk14; /* 0x14 */ u8 unk15; /* 0x15 */ u8 pad16[2]; f32 unk18; /* 0x18 */ s32 unk1C; /* 0x1C */ void *unk20; /* 0x20 */ } TTItemE;
typedef struct { u8 pad0[0x44]; f32 unk44; /* 0x44: Pitch */ s32 unk48; /* 0x48 */ u8 pad4C[0xC]; s16 unk58; /* 0x58: Pan */ s16 unk5A; /* 0x5A: Volume */ s16 unk5C; /* 0x5C */ s16 unk5E; /* 0x5E */ s16 unk60; /* 0x60 */ s16 unk62; /* 0x62 */ u16 unk64; /* 0x64 */ s16 unk66; /* 0x66 */ s16 unk68; /* 0x68 */ u16 unk6A; /* 0x6A */ s16 unk6C; /* 0x6C */ s16 unk6E; /* 0x6E */ s32 unk70; /* 0x70 */ s32 unk74; /* 0x74 */ s32 unk78; /* 0x78 */ TTItemE *unk7C; /* 0x7C: Event-Liste */ s32 unk80; /* 0x80 */ s32 unk84; /* 0x84 */ u8 pad88[4]; u8 unk8C; /* 0x8C */ u8 pad8D[3]; s16 unk90; /* 0x90 */ s16 unk92; /* 0x92 */ u8 pad94[0x24]; s32 unkB8; /* 0xB8 */ } TTVceE;
typedef struct { u8 pad0[0x88]; s32 unk88; /* 0x88 */ } TTHdlE;
extern s16 D_80041290[];
extern s16 D_8004138E[];
extern u8 D_8007EA30;
extern u8 D_8007EA31;
extern u8 D_8007EA32;
extern s32 func_8002CC9C(TTVceE *, s32, void *);
extern void func_80021884(void *);
extern void func_800217F4(void *);
typedef struct TTQEl_s { struct TTQEl_s *unk0; /* 0x00: next */ } TTQEl;
typedef struct { u8 pad0[0x48]; s32 unk48; /* 0x48 */ f32 unk4C; /* 0x4C */ s32 unk50; /* 0x50 */ u8 pad54[6]; s16 unk5A; /* 0x5A */ u8 pad5C[0x18]; s32 unk74; /* 0x74 */ s32 unk78; /* 0x78 */ TTQEl *unk7C; /* 0x7C: Queue-Kopf */ TTQEl *unk80; /* 0x80: Queue-Ende */ s32 unk84; /* 0x84 */ } TTPlayerC;
extern s32 func_8002D328(TTPlayerC *, s32, TTQEl *);
typedef struct { u8 pad0[0x54]; void *unk54; /* 0x54 */ s16 unk58; /* 0x58: Pan */ s16 unk5A; /* 0x5A: Volume */ s16 unk5C; /* 0x5C */ s16 unk5E; /* 0x5E */ s16 unk60; /* 0x60 */ s16 unk62; /* 0x62 */ u16 unk64; /* 0x64 */ s16 unk66; /* 0x66 */ s16 unk68; /* 0x68 */ u16 unk6A; /* 0x6A */ s16 unk6C; /* 0x6C */ s16 unk6E; /* 0x6E */ u32 unk70; /* 0x70 */ s32 unk74; /* 0x74 */ s32 unk78; /* 0x78 */ u8 pad7C[8]; s32 unk84; /* 0x84 */ } TTVce;
extern TTAcmd *func_8002D030();
typedef struct { u8 pad0[0x8C]; u8 unk8C; /* 0x8C: Delay-Zaehler */ } TTVceB;
typedef struct { u8 pad0[0x8]; TTVceB *unk8; /* 0x08 */ u8 padC[0xC]; s16 unk18; /* 0x18: Kanal */ } TTHdlB;
typedef struct { u8 pad0[0x8]; TTHdlB *unk8; /* 0x08 */ } TTNodeB;
typedef struct { u8 pad0[0x14]; u32 unk14; /* 0x14: Anzahl */ u8 pad18[4]; TTNodeB **unk1C; /* 0x1C: Liste */ u8 pad20[0x28]; } TTChSlotB;
typedef struct { u8 pad0[0x34]; TTChSlotB *unk34; /* 0x34 */ } TTAMgrB;
extern TTAMgrB *D_800411F4;
extern f32 D_80041D90;

/* Vorwaertsdeklarationen der Funktionen dieser TU. */
s32 func_8002B684(TTPlayerC *arg0, s32 type, TTQEl *val);
TTAcmd *func_8002B7C8(void *arg0, s16 *param, s32 arg2, s32 flags, TTAcmd *cmdIn);
s16 func_8002BAAC(f32 cur, f32 tgt, s32 steps, u16 *outFrac);
s16 func_8002BCBC();

void func_8002ACE0(TTCSPq *seqp, s32 delta, u8 status, u8 chan, u8 byte2, u8 byte3)
{
    TTEvtA evt;
    s32 d;

    evt.type = 2;
    evt.msg.midi.ticks = 0;
    evt.msg.midi.status = status;
    evt.msg.midi.chan = chan;
    evt.msg.midi.byte2 = byte2;
    evt.msg.midi.byte3 = byte3;
    evt.msg.midi.duration = 0;

    d = delta;
    func_80026500(&seqp->evtq, &evt, d, 0);
}

TTAcmd *func_8002AD60(TTVceE *arg0, void *arg1, TTAcmd *cmdIn)
{
    TTAcmd *cmd = cmdIn;
    TTVceE *v = arg0;
    s16 var4E;
    s32 prev;
    s32 time = arg1;
    s32 delta;
    s16 var3E;
    s32 tmp38;
    TTItemE *evtSave;
    s32 budget;
    TTItemE *evt2C;
    s32 tmp28;
    TTItemE *evt24;
    TTItemE *evt20;

    var3E = 0;
    budget = 0xB8;
    var4E = 0;

    while (v->unk7C != 0) {
        prev = time;
        time = v->unk7C->unk4;

        delta = (time - prev + 0xB7) / 0xB8 * 0xB8;
        if (delta == 0)
            time = prev;

        if (delta > budget)
            break;

        switch (v->unk7C->u8.u) {
        case 0xD:
            evt2C = v->unk7C;
            if (evt2C->unkA != 0)
                v->unk48 = 1;

            func_8002CC9C(v, 5, evt2C->unk20);
            v->unk84 = 1;
            v->unk78 = 1;
            v->unk70 = 0;
            v->unk74 = (evt2C->unk1C + 0xB7) / 0xB8 * 0xB8;

            tmp28 = (evt2C->u10.s.h + evt2C->u10.s.h) / 2;
            v->unk5A = tmp28;
            v->unk58 = evt2C->u10.s.b12;
            v->unk60 = (D_80041290[evt2C->u10.s.b13 & 0x7F] & 0xFFFE) | (evt2C->u10.s.b13 >> 7);

            if (!D_8007EA30)
                v->unk60 = v->unk60 & 0xFFFE;

            v->unk62 = D_8004138E[-(evt2C->u10.s.b13 & 0x7F)] & 0xFFFE;

            if (D_8007EA32)
                v->unk58 = (v->unk58 >> 1) + 0x20;
            else if (D_8007EA31)
                v->unk58 = 0x40;

            if (evt2C->unk1C != 0) {
                v->unk5C = 1;
                v->unk5E = 1;
            } else {
                v->unk5C = (D_80041290[v->unk58] * v->unk5A) >> 15;
                v->unk5E = (D_8004138E[-v->unk58] * v->unk5A) >> 15;
            }

            v->unk44 = evt2C->uC.f;
            v->unk92 = evt2C->unk15;
            v->unk90 = (s32)evt2C->unk18;
            v->unkB8 = 1;
            v->unk8C = evt2C->unk14;
            break;

        case 0xB:
        case 0xC:
        case 0x10:
            cmd = func_8002B7C8(v, &var4E, &var3E, delta, cmd);

            if (v->unk70 >= v->unk74) {
                v->unk68 = (D_80041290[v->unk58] * v->unk5A) >> 15;
                v->unk6E = (D_8004138E[-v->unk58] * v->unk5A) >> 15;
                v->unk70 = v->unk74;
                v->unk5C = v->unk68;
                v->unk5E = v->unk6E;
            } else {
                v->unk5C = func_8002BCBC(v->unk5C, v->unk70, v->unk66, v->unk64);
                v->unk5E = func_8002BCBC(v->unk5E, v->unk70, v->unk6C, v->unk6A);
            }

            if (v->unk5C == 0)
                v->unk5C = 1;
            if (v->unk5E == 0)
                v->unk5E = 1;

            if (v->unk7C->u8.s == 0xC) {
                if (D_8007EA32)
                    v->unk58 = (v->unk7C->uC.h.lo >> 1) + 0x20;
                else if (D_8007EA31)
                    v->unk58 = 0x40;
                else
                    v->unk58 = v->unk7C->uC.i;
            }

            if (v->unk7C->u8.s == 0xB) {
                v->unk70 = 0;
                tmp38 = v->unk7C->uC.i;
                tmp38 = (tmp38 + tmp38) / 2;
                v->unk5A = tmp38;
                v->unk74 = (v->unk7C->u10.i + 0xB7) / 0xB8 * 0xB8;
            }

            if (v->unk7C->u8.s == 0x10) {
                if (((v->unk60 ^ v->unk62) & 1) ^ ((v->unk7C->uC.i + 1) >> 7)) {
                    if (D_8007EA30) {
                        if (v->unk58 > 0x40)
                            v->unk60 = v->unk60 ^ 1;
                        else
                            v->unk62 = v->unk62 ^ 1;
                    }
                }
                v->unk60 = (D_80041290[v->unk7C->uC.i & 0x7F] & 0xFFFE) | (v->unk60 & 1);
                v->unk62 = (D_8004138E[-(v->unk7C->uC.i & 0x7F)] & 0xFFFE) | (v->unk62 & 1);
            }

            v->unk78 = 1;
            break;

        case 0xE:
            evt24 = v->unk7C;
            if (evt24->unkA != 0)
                v->unk48 = 1;

            func_8002CC9C(v, 5, evt24->uC.p);
            v->unk84 = 1;
            break;

        case 0xF:
            cmd = func_8002B7C8(v, &var4E, &var3E, delta, cmd);
            func_8002B684(v, 4, 0);
            break;

        case 0x0:
            evt20 = v->unk7C;
            ((TTHdlE *)evt20->uC.p)->unk88 = 0;
            func_80021884(evt20->uC.p);
            break;

        case 0x7:
            cmd = func_8002B7C8(v, &var4E, &var3E, delta, cmd);
            v->unk44 = v->unk7C->uC.f;
            break;

        case 0x8:
            cmd = func_8002B7C8(v, &var4E, &var3E, delta, cmd);
            v->unk48 = 1;
            break;

        case 0x5:
            cmd = func_8002B7C8(v, &var4E, &var3E, delta, cmd);
            func_8002CC9C(v, 5, v->unk7C->uC.p);
            break;

        default:
            cmd = func_8002B7C8(v, &var4E, &var3E, delta, cmd);
            func_8002B684(v, v->unk7C->u8.s, v->unk7C->uC.p);
            break;
        }

        var3E += delta * 2;
        budget = budget - delta;

        evtSave = v->unk7C;
        v->unk7C = v->unk7C->unk0;
        if (v->unk7C == 0)
            v->unk80 = 0;

        func_800217F4(evtSave);
    }

    cmd = func_8002B7C8(v, &var4E, &var3E, budget, cmd);

    if (v->unk70 > v->unk74)
        v->unk70 = v->unk74;

    return cmd;
}

s32 func_8002B684(TTPlayerC *arg0, s32 type, TTQEl *val)
{
    TTPlayerC *p = arg0;

    switch (type) {
        case 3:
            if (p->unk80) {
                p->unk80->unk0 = val;
            }
            else {
                p->unk7C = val;
            }
            p->unk80 = val;
            break;
        case 4:
            p->unk78 = 1;
            p->unk84 = 0;
            p->unk5A = 1;
            p->unk74 = 0;
            p->unk4C = 0.0f;
            p->unk50 = 1;
            p->unk48 = 0;
            func_8002D328(p, 4, val);
            break;
        case 9:
            p->unk84 = 1;
            break;
        default:
            func_8002D328(p, type, val);
            break;
    }

    return 0;
}

TTAcmd *func_8002B7C8(void *arg0, s16 *param, s32 arg2, s32 flags, TTAcmd *cmdIn)
{
    TTAcmd *cmd = cmdIn;
    TTVce *v = (TTVce *)arg0;
    TTAcmd *p1;
    TTAcmd *p2;
    TTAcmd *p3;
    TTAcmd *p4;
    TTAcmd *p5;

    if (v->unk84 != 1 || flags == 0)
        return cmd;

    cmd = func_8002D030(v, param, flags, cmdIn);

    if (v->unk78 != 0) {
        v->unk78 = 0;

        v->unk68 = (D_80041290[v->unk58] * v->unk5A) >> 15;
        v->unk66 = func_8002BAAC((f32)v->unk5C, (f32)v->unk68, v->unk74, &v->unk64);

        v->unk6E = (D_8004138E[-v->unk58] * v->unk5A) >> 15;
        v->unk6C = func_8002BAAC((f32)v->unk5E, (f32)v->unk6E, v->unk74, &v->unk6A);

        p1 = cmd++;
        p1->w0 = (v->unk5C & 0xFFFF) | 0x09060000;
        p1->w1 = ((v->unk60 & 0xFFFF) << 16) | (v->unk62 & 0xFFFF);

        p2 = cmd++;
        p2->w0 = (v->unk6E & 0xFFFF) | 0x09040000;
        p2->w1 = ((v->unk6C & 0xFFFF) << 16) | (v->unk6A & 0xFFFF);

        p3 = cmd++;
        p3->w0 = (v->unk68 & 0xFFFF) | 0x09000000;
        p3->w1 = ((v->unk66 & 0xFFFF) << 16) | (v->unk64 & 0xFFFF);

        p4 = cmd++;
        p4->w0 = (v->unk5E & 0xFFFF) | 0x03010000;
        p4->w1 = osVirtualToPhysical(v->unk54);
        if (1) {}   /* wegkompilierter _DEBUG-Block: unterdrueckt Delay-Slot-Fill */
    } else {
        p5 = cmd++;
        p5->w0 = 0x03000000;
        p5->w1 = osVirtualToPhysical(v->unk54);
    }

    *param += 0x170;
    v->unk70 += 0xB8;

    return cmd;
}

s16 func_8002BAAC(f32 cur, f32 tgt, s32 steps, u16 *outFrac)
{
    s16 hi;
    s16 lo;
    f32 stepInv;
    f32 x;
    f32 rest;

    if (!steps) {
        if (cur <= tgt) {
            *outFrac = 0xFFFF;
            return 0x7FFF;
        }
        else {
            *outFrac = 0;
            return -0x8000;
        }
    }

    stepInv = 1.0f / (f32)steps;

    if (tgt < 1.0f)
        tgt = 1.0f;
    if (cur <= 0.0f)
        cur = 1.0f;

    x = (tgt - cur) * stepInv * 8.0f;
    hi = (s32)x;
    rest = x - hi;
    hi = hi - 1;
    rest = rest + 1.0f;
    lo = (s32)rest;
    hi = hi + lo;
    rest = rest - lo;

    *outFrac = (u32)(65535.0f * rest);

    return hi;
}

s16 func_8002BCBC(base, steps, delta, frac) s16 base; s32 steps; s16 delta; u16 frac;
{
    s32 x;

    steps = steps >> 3;
    if (!steps)
        return base;

    x = frac * steps;
    x = x >> 16;
    x += delta * steps;
    base = base + x;

    return base;
}

TTAcmd *func_8002BD40(void *arg0, TTAcmd *cmdIn, s32 chan, s32 *outCount)
{
    TTAcmd *cmd = cmdIn;
    TTChSlotB *slot = &D_800411F4->unk34[chan];
    TTNodeB **list = slot->unk1C;
    u32 i;
    s32 count = 0;
    u32 maxDelay = 1;
    u32 rate;
    TTAcmd *p0;
    TTAcmd *p1;
    TTAcmd *p2;
    TTAcmd *saved;

    p0 = cmd++;
    p0->w0 = 0x020007C0;
    p0->w1 = 0x2E0;

    *outCount = 0;

    for (i = 0; i < slot->unk14; i++) {
        if (list[i]->unk8 != 0 && list[i]->unk8->unk18 == chan
            && list[i]->unk8->unk8 != 0 && list[i]->unk8->unk8->unk8C >= 0x40) {
            cmd = func_8002AD60(list[i], arg0, cmd);
            (*outCount)++;
            count++;
            if (list[i]->unk8->unk8->unk8C > maxDelay)
                maxDelay = list[i]->unk8->unk8->unk8C;
        }
    }

    if (count != 0) {
        maxDelay -= 0x3E;

        if (maxDelay >= 7)
            rate = (u32)(D_80041D90 / sqrtf((f32)maxDelay));
        else
            rate = (u32)(65536.0f / (f32)maxDelay);

        p1 = cmd++;
        p1->w0 = 0x4E0;
        p1->w1 = ((rate & 0xFFFF) << 16) | (maxDelay & 0xFFFF);

        p2 = cmd++;
        p2->w0 = 0x650;
        p2->w1 = ((rate & 0xFFFF) << 16) | (maxDelay & 0xFFFF);
    }

    for (i = 0; i < slot->unk14; i++) {
        if ((list[i]->unk8 != 0 && list[i]->unk8->unk18 == chan
             && (list[i]->unk8->unk8 == 0 || list[i]->unk8->unk8->unk8C < 0x40))
            || (list[i]->unk8 == 0 && chan == 0)) {
            saved = cmd;
            cmd = func_8002AD60(list[i], arg0, cmd);
            if (cmd != saved)
                (*outCount)++;
        }
    }

    return cmd;
}
