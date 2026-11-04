// Probably an animation-synchronised event sequence: a vector of timed calls that fire once the
// owner's animation reaches their time (or every frame for time -1).
#include "seq.h"

void anseq_entrypoint_1(s16 *pSeqIndx, s32 arg1);

typedef struct {
    f32 duration; // anim time, -1 = every frame
    u8 argCount;
    u8 unk5;
    u8 delay; // frames to wait before calling, 0xFF = done
    s32 arg0;
    s32 arg1;
    s32 arg2;
    s32 arg3;
    void *func_ptr;
} AnSeqElement;

struct {
    s32 pending_delay; // delay for the next pushed entry
    AnSeqElement *last_entry; // most recently pushed entry
} B_80800490_anseq;

void func_80800000_anseq(s16 *pSeqIndx, AnSeqElement *element)
{
    if (element->delay) {
        if (element->delay == 0xFF) {
            return;
        }

        element->delay--;
        if (element->delay) {
            return;
        }

        element->delay = 0xFF;
    }

    switch (element->argCount) {
        case 0:
            ((void (*)(void)) element->func_ptr)();
            break;
        case 1:
            ((void (*)(s32)) element->func_ptr)(element->arg0);
            break;
        case 2:
            ((void (*)(s32, s32)) element->func_ptr)(element->arg0, element->arg1);
            break;
        case 3:
            ((void (*)(s32, s32, s32)) element->func_ptr)(element->arg0, element->arg1,
                                                          element->arg2);
            break;
        case 4:
            ((void (*)(s32, s32, s32, s32)) element->func_ptr)(element->arg0, element->arg1,
                                                               element->arg2, element->arg3);
            break;
        case 5:
            ((void (*)(void *)) element->func_ptr)((void *) &element->arg0);
    }
}

void anseq_entrypoint_0(s16 *pSeqIndx)
{
    vector_clear(func_800B2890(*pSeqIndx));
}

void *func_80800134_anseq(s16 *pSeqIndx, f32 duration, s32 arg_count, void *func_ptr, s32 a0,
                          s32 a1, s32 a2, s32 a3)
{
    AnSeqElement *entry = func_800B2A58(*pSeqIndx);
    entry->duration = duration;
    entry->argCount = arg_count;
    entry->func_ptr = func_ptr;
    entry->arg0 = a0;
    entry->arg1 = a1;
    entry->arg2 = a2;
    entry->arg3 = a3;
    entry->delay = B_80800490_anseq.pending_delay;
    if (duration == -1) {
        anseq_entrypoint_1(pSeqIndx, 1);
    } else {
        entry->unk5 = 0;
    }
    B_80800490_anseq.pending_delay = 0;
    B_80800490_anseq.last_entry = entry;
    return entry;
}

void anseq_entrypoint_1(s16 *pSeqIndx, s32 arg1)
{
    B_80800490_anseq.last_entry->unk5 = arg1;
}

void anseq_entrypoint_2(s16 *pSeqIndx, f32 duration, void *func_ptr, s32 arg3, s32 arg4)
{
    func_80800134_anseq(pSeqIndx, duration, 2, func_ptr, arg3, arg4, NULL, NULL);
}

void anseq_entrypoint_3(s16 *pSeqIndx, f32 duration, void *func_ptr, s32 arg3, s32 arg4, s32 arg5)
{
    func_80800134_anseq(pSeqIndx, duration, 3, func_ptr, arg3, arg4, arg5, NULL);
}

void anseq_entrypoint_4(s16 *pSeqIndx, f32 duration, void *func_ptr, s32 arg3, s32 arg4, s32 arg5,
                        s32 arg6)
{
    func_80800134_anseq(pSeqIndx, duration, 4, func_ptr, arg3, arg4, arg5, arg6);
}

void anseq_entrypoint_5(s16 arg0)
{
    s16 *entry = (s16 *) func_8001B798(arg0);
    func_800B2D48(*entry);
    func_8001B754(arg0);
}

s16 anseq_entrypoint_6(void)
{
    s16 *seq_ref;
    s16 handle = func_8001B668(0, 2);
    seq_ref = (s16 *) func_8001B798(handle);
    *seq_ref = func_800B2DC0(sizeof(AnSeqElement), 0x2);
    anseq_entrypoint_0(seq_ref);
    return handle;
}

void anseq_entrypoint_7(s16 *pSeqIndx, s32 arg1)
{
    B_80800490_anseq.pending_delay = arg1;
}

// Calls each entry whose anim time has been reached.
void anseq_entrypoint_8(s16 *pSeqIndx, AnimCtrl *pAnCtl)
{
    void *entries = func_800B2890(*pSeqIndx);
    AnSeqElement *entry;
    for (entry = vector_begin(entries); entry != (void *) vector_end(entries); entry++) {
        if ((entry->duration == -1.0f) || anctrl_isAt(pAnCtl, entry->duration)) {
            func_80800000_anseq(pSeqIndx, entry);
        }
    }
}

void anseq_entrypoint_9(s16 arg0)
{
    func_8001B798(arg0);
}
