#include "common.h"

typedef struct {
    s16 type;
    union {
        struct {
            s32 ticks;
            u8 status;
            u8 type;
            u8 unkA;
            u8 byte1;
            u8 byte2;
            u8 byte3;
        } tempo;
    } msg;
} TTEvent2;
typedef struct {
    u8 pad[0x48];
    u8 evtq; // 0x48, event queue (only its address is used)
} TTCSPlayer;
extern void func_80026500(void *, TTEvent2 *, s32, s32);

// alCSPSetTempo: posts a meta tempo event (0xFF 0x51, 24-bit microseconds per quarter note).
void func_80026330(TTCSPlayer *seqp, s32 tempo)
{
    TTEvent2 evt;

    evt.type = 7;
    evt.msg.tempo.status = 0xFF;
    evt.msg.tempo.type = 0x51;
    evt.msg.tempo.byte1 = (tempo & 0xFF0000) >> 16;
    evt.msg.tempo.byte2 = (tempo & 0xFF00) >> 8;
    evt.msg.tempo.byte3 = tempo & 0xFF;

    func_80026500(&seqp->evtq, &evt, 0, 0);
}
