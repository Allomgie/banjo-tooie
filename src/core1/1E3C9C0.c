#include "common.h"

typedef struct { u8 pad0[0x48]; u8 evtq; } TTSeqPlayer;
typedef struct { s16 type; u8 pad2[0xE]; } TTEvt;
extern void func_80026500(void *, TTEvt *, s32, s32);

void func_80024E90(TTSeqPlayer *param_0)
{
    TTEvt local_0;

    local_0.type = 0x11;
    func_80026500(&param_0->evtq, &local_0, 0, 0);
}
