#include "common.h"

typedef struct {
    u8 pad0[8];
    f32 qnpt; // 0x8, quarter notes per tick
} TTInner;
typedef struct {
    u8 pad0[0x18];
    TTInner *target; // 0x18, current sequence
    u8 pad1C[8];
    s32 uspt; // 0x24, microseconds per tick
} TTOuter;

// alCSPGetTempo: 0 without a target sequence.
s32 func_800260B0(TTOuter *seqp)
{
    if (!seqp->target)
        return 0;
    return (s32) ((f32) seqp->uspt / seqp->target->qnpt);
}
