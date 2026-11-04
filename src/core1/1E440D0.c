// n_alSynSetPriority: sets the priority of a synth voice.
#include "common.h"

typedef struct {
    u8 pad0[0x16];
    s16 priority;
} TTHdl;

// n_alSynSetPriority
void func_8002C5A0(TTHdl *hdl, s16 priority)
{
    hdl->priority = priority;
}
