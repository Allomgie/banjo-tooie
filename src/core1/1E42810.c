#include "common.h"

typedef struct {
    u8 pad[0x48];
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
    struct TTItemE_s *unk0;
    s32 unk4;
    union {
        s16 s;
        u16 u;
    } u8;
    s16 unkA;
    union {
        void *p;
        f32 f;
        s32 i;
        struct {
            s16 hi;
            s16 lo;
        } h;
    } uC;
    union {
        s32 i;
        struct {
            s16 h;
            u8 b12;
            u8 b13;
        } s;
    } u10;
    u8 unk14;
    u8 unk15;
    u8 pad16[2];
    f32 unk18;
    s32 unk1C;
    void *unk20;
} TTItemE;
typedef struct {
    u8 pad0[0x44];
    f32 unk44;
    s32 unk48;
    u8 pad4C[0xC];
    s16 unk58;
    s16 unk5A;
    s16 unk5C;
    s16 unk5E;
    s16 unk60;
    s16 unk62;
    u16 unk64;
    s16 unk66;
    s16 unk68;
    u16 unk6A;
    s16 unk6C;
    s16 unk6E;
    s32 unk70;
    s32 unk74;
    s32 unk78;
    TTItemE *unk7C;
    s32 unk80;
    s32 unk84;
    u8 pad88[4];
    u8 unk8C;
    u8 pad8D[3];
    s16 unk90;
    s16 unk92;
    u8 pad94[0x24];
    s32 unkB8;
} TTVceE;
typedef struct {
    u8 pad0[0x88];
    s32 unk88;
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
    struct TTQEl_s *unk0;
} TTQEl;
typedef struct {
    u8 pad0[0x48];
    s32 unk48;
    f32 unk4C;
    s32 unk50;
    u8 pad54[6];
    s16 unk5A;
    u8 pad5C[0x18];
    s32 unk74;
    s32 unk78;
    TTQEl *unk7C;
    TTQEl *unk80;
    s32 unk84;
} TTPlayerC;
extern s32 func_8002D328(TTPlayerC *, s32, TTQEl *);
typedef struct {
    u8 pad0[0x54];
    void *unk54;
    s16 unk58;
    s16 unk5A;
    s16 unk5C;
    s16 unk5E;
    s16 unk60;
    s16 unk62;
    u16 unk64;
    s16 unk66;
    s16 unk68;
    u16 unk6A;
    s16 unk6C;
    s16 unk6E;
    u32 unk70;
    s32 unk74;
    s32 unk78;
    u8 pad7C[8];
    s32 unk84;
} TTVce;
extern TTAcmd *func_8002D030();
typedef struct {
    u8 pad0[0x8C];
    u8 unk8C;
} TTVceB;
typedef struct {
    u8 pad0[0x8];
    TTVceB *unk8;
    u8 padC[0xC];
    s16 unk18;
} TTHdlB;
typedef struct {
    u8 pad0[0x8];
    TTHdlB *unk8;
} TTNodeB;
typedef struct {
    u8 pad0[0x14];
    u32 unk14;
    u8 pad18[4];
    TTNodeB **unk1C;
    u8 pad20[0x28];
} TTChSlotB;
typedef struct {
    u8 pad0[0x34];
    TTChSlotB *unk34;
} TTAMgrB;
extern TTAMgrB *D_800411F4;
extern f32 D_80041D90;

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
                v->unk90 = (s32) evt2C->unk18;
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
                ((TTHdlE *) evt20->uC.p)->unk88 = 0;
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
            } else {
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
    TTVce *v = (TTVce *) arg0;
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
        v->unk66 = func_8002BAAC((f32) v->unk5C, (f32) v->unk68, v->unk74, &v->unk64);

        v->unk6E = (D_8004138E[-v->unk58] * v->unk5A) >> 15;
        v->unk6C = func_8002BAAC((f32) v->unk5E, (f32) v->unk6E, v->unk74, &v->unk6A);

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
        if (1) {
        }
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
        } else {
            *outFrac = 0;
            return -0x8000;
        }
    }

    stepInv = 1.0f / (f32) steps;

    if (tgt < 1.0f)
        tgt = 1.0f;
    if (cur <= 0.0f)
        cur = 1.0f;

    x = (tgt - cur) * stepInv * 8.0f;
    hi = (s32) x;
    rest = x - hi;
    hi = hi - 1;
    rest = rest + 1.0f;
    lo = (s32) rest;
    hi = hi + lo;
    rest = rest - lo;

    *outFrac = (u32) (65535.0f * rest);

    return hi;
}

s16 func_8002BCBC(base, steps, delta, frac)
s16 base;
s32 steps;
s16 delta;
u16 frac;
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
        if (list[i]->unk8 != 0 && list[i]->unk8->unk18 == chan && list[i]->unk8->unk8 != 0 &&
            list[i]->unk8->unk8->unk8C >= 0x40) {
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
            rate = (u32) (D_80041D90 / sqrtf((f32) maxDelay));
        else
            rate = (u32) (65536.0f / (f32) maxDelay);

        p1 = cmd++;
        p1->w0 = 0x4E0;
        p1->w1 = ((rate & 0xFFFF) << 16) | (maxDelay & 0xFFFF);

        p2 = cmd++;
        p2->w0 = 0x650;
        p2->w1 = ((rate & 0xFFFF) << 16) | (maxDelay & 0xFFFF);
    }

    for (i = 0; i < slot->unk14; i++) {
        if ((list[i]->unk8 != 0 && list[i]->unk8->unk18 == chan &&
             (list[i]->unk8->unk8 == 0 || list[i]->unk8->unk8->unk8C < 0x40)) ||
            (list[i]->unk8 == 0 && chan == 0)) {
            saved = cmd;
            cmd = func_8002AD60(list[i], arg0, cmd);
            if (cmd != saved)
                (*outCount)++;
        }
    }

    return cmd;
}

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
