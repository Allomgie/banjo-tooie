#include "common.h"

typedef struct { u8 pad[0x48]; u8 evtq; /* 0x48 */ } TTCSPlayer;
typedef struct { s16 type; /* 0x0 */ union { struct { void *seq; } spseq; /* ptr @4 */ struct { s16 vol; } spvol; /* s16 @4 */ struct { f32 a; f32 b; } fpair; /* @4,@8 */ struct { s32 ticks; u8 status; u8 chan; u8 ctrl; u8 val; s32 duration; } midi; /* @4,8,9,A,B */ } msg; } TTEvt;
extern void func_80026500(void *, TTEvt *, s32, s32);

void func_80025F70(TTCSPlayer *seqp, u8 chan, u8 fxmix)
{
    TTEvt evt;

    evt.type = 2;
    evt.msg.midi.ticks = 0;
    evt.msg.midi.status = 0xB0;
    evt.msg.midi.chan = chan;
    evt.msg.midi.ctrl = 0x5B;
    evt.msg.midi.val = fxmix;

    func_80026500(&seqp->evtq, &evt, 0, 0);
}

void func_80025FE0(TTCSPlayer *seqp, f32 a, f32 b)
{
    TTEvt evt;

    evt.type = 0x18;
    evt.msg.fpair.a = a;
    evt.msg.fpair.b = b;

    func_80026500(&seqp->evtq, &evt, 0, 0);
}

void func_8002603C(TTCSPlayer *seqp, u8 chan, u8 val)
{
    TTEvt evt;

    evt.type = 2;
    evt.msg.midi.ticks = 0;
    evt.msg.midi.status = 0xB0;
    evt.msg.midi.chan = chan;
    evt.msg.midi.ctrl = 0x5C;
    evt.msg.midi.val = val;

    func_80026500(&seqp->evtq, &evt, 0, 0);
}
