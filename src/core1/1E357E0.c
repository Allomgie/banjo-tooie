#include "threads.h"

extern OSThread *D_8007D820[];

// Creates a thread with an odd-float-register save area and registers it by id.
void func_8001DCB0(OSThread *thread, __OSThreadOddFpStorage *fp_storage, s32 id, void (*entry)(void *),
                   void *arg, void *stack, OSPri priority)
{
    osCreateThread(thread, id, entry, arg, stack, priority);
    thread->odd_float_save = fp_storage;
    if (fp_storage != NULL) {
        fp_storage->unk4 = fp_storage->unk8 = fp_storage->unkC = 0;
    }
    D_8007D820[id] = thread;
}

// Same as func_8001DCB0, but sets unkC of the save area to 1.
void func_8001DD28(OSThread *thread, __OSThreadOddFpStorage *fp_storage, s32 id, void (*entry)(void *),
                   void *arg, void *stack, OSPri priority)
{
    osCreateThread(thread, id, entry, arg, stack, priority);
    thread->odd_float_save = fp_storage;
    if (fp_storage != NULL) {
        fp_storage->unkC = 1;
        fp_storage->unk4 = fp_storage->unk8 = 0;
    }
    D_8007D820[id] = thread;
}

// get_thread
OSThread *func_8001DDA4(s32 id)
{
    return D_8007D820[id];
}
