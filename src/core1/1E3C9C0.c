#include "common.h"

typedef struct {
    u8 pad0[0x48];
    u8 evtq;
} TTSeqPlayer;
typedef struct {
    s16 type;
    u8 pad2[0xE];
} TTEvt;
extern void func_80026500(void *, TTEvt *, s32, s32);

// Posts AL_SEQP_STOPPING_EVT to the sequence player's event queue.
void func_80024E90(TTSeqPlayer *player)
{
    TTEvt evt;

    evt.type = 0x11;
    func_80026500(&player->evtq, &evt, 0, 0);
}
