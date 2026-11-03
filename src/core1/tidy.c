#include <ultra64.h>
#include "threads.h"

// tidy thread entry
void func_80013544(void *);

// do_tidy: heap and overlay defragmentation
void func_800A7FD4(void);

// start signal
extern OSMesgQueue D_800769E0;
extern OSMesg D_800769F8;

// stop signal
extern OSMesgQueue D_80076A00;
extern OSMesg D_80076A18;

extern OSThread D_80076A20;
// TODO: only 0x10 bytes, so a different struct (same as the joy thread).
extern __OSThreadOddFpStorage D_80076BD0;
extern u64 D_80076BE0[TIDY_THREAD_STACK_SIZE64];
// Nonzero while the thread is tidying.
extern s32 D_800773E0;

// Creates the tidy thread and its start/stop queues.
void func_800133A0(void)
{
    osCreateMesgQueue(&D_800769E0, &D_800769F8, 1);
    osCreateMesgQueue(&D_80076A00, &D_80076A18, 1);
    func_8001DCB0(&D_80076A20, &D_80076BD0, THREAD_ID_TIDY, func_80013544, NULL,
                  &D_80076BE0[TIDY_THREAD_STACK_SIZE64], TIDY_THREAD_PRIORITY);
    osStartThread(&D_80076A20);
    D_800773E0 = 0;
}

// Destroys the tidy thread.
void func_80013430(void)
{
    osStopThread(&D_80076A20);
    osDestroyThread(&D_80076A20);
}

s32 func_80013460(void)
{
    return MQ_GET_COUNT(&D_800769E0) < 1u;
}

s32 func_80013474(void)
{
    return MQ_GET_COUNT(&D_80076A00) < 1u;
}

// Sends the start signal.
void func_80013488(void)
{
    if (func_80012530() == 1) {
        osSendMesg(&D_800769E0, NULL, OS_MESG_BLOCK);
    }
}

// Sends the stop signal.
void func_800134C4(void)
{
    if (func_80012530() == 1) {
        osSendMesg(&D_80076A00, NULL, OS_MESG_BLOCK);
    }
}

// Sets the tidy thread priority.
void func_80013500(OSPri pri)
{
    if (func_80012530() == 1) {
        osSetThreadPri(&D_80076A20, pri);
    }
}

// Returns whether the tidy thread is busy.
s32 func_80013538(void)
{
    return D_800773E0;
}

// Waits for start, runs do_tidy up to twice unless stopped, then waits for stop.
void func_80013544(void *arg)
{
    s32 i;
    while (TRUE) {
        osRecvMesg(&D_800769E0, NULL, OS_MESG_BLOCK);
        D_800773E0 = 1;
        for (i = 0; i < 2 && MQ_GET_COUNT(&D_80076A00) == 0; i++) {
            func_800A7FD4();
        }
        D_800773E0 = 0;
        osRecvMesg(&D_80076A00, NULL, OS_MESG_BLOCK);
    }
}
