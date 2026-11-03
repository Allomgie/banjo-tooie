#include "common.h"

typedef struct {
    u8 pad[0x48];
    u8 evtq;
} TTCSPlayer;
typedef struct {
    s16 type;
    union {
        struct {
            void *seq;
        } spseq;
        struct {
            s16 vol;
        } spvol;
        struct {
            f32 a;
            f32 b;
        } fpair;
        struct {
            s32 ticks;
            u8 status;
            u8 chan;
            u8 ctrl;
            u8 val;
            s32 duration;
        } midi;
    } msg;
} TTEvt;
extern void func_80026500(void *, TTEvt *, s32, s32);

void func_80025E80(TTCSPlayer *seqp, void *seq)
{
    TTEvt evt;

    evt.type = 0xD;
    evt.msg.spseq.seq = seq;

    func_80026500(&seqp->evtq, &evt, 0, 0);
}

void func_80025ED0(TTCSPlayer *seqp, s16 vol)
{
    TTEvt evt;

    evt.type = 0xA;
    evt.msg.spvol.vol = vol;

    func_80026500(&seqp->evtq, &evt, 0, 0);
}

void func_80025F20(TTCSPlayer *seqp)
{
    TTEvt evt;

    evt.type = 0xF;

    func_80026500(&seqp->evtq, &evt, 0, 0);
}
