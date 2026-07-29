#include "common.h"

typedef struct { s16 type; /* 0x0 */ union { struct { s32 ticks; /* 0x4 */ u8 status; /* 0x8 */ u8 type; /* 0x9 */ u8 unkA; /* 0xA */ u8 byte1; /* 0xB */ u8 byte2; /* 0xC */ u8 byte3; /* 0xD */ } tempo; } msg; } TTEvent2;
typedef struct { u8 pad[0x48]; u8 evtq; /* 0x48: ALEventQueue (opak, nur Adresse) */ } TTCSPlayer;
extern void func_80026500(void *, TTEvent2 *, s32, s32);

void func_80026330(TTCSPlayer *seqp, s32 tempo)
{
    TTEvent2 evt;

    evt.type             = 7;
    evt.msg.tempo.status = 0xFF;
    evt.msg.tempo.type   = 0x51;
    evt.msg.tempo.byte1  = (tempo & 0xFF0000) >> 16;
    evt.msg.tempo.byte2  = (tempo & 0xFF00) >> 8;
    evt.msg.tempo.byte3  = tempo & 0xFF;

    func_80026500(&seqp->evtq, &evt, 0, 0);
}
