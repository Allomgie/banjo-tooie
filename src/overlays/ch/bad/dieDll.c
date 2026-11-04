#include "common.h"

// TU-NOTE: the overlay's .data is defined in C here, values taken from the ROM.

typedef struct {
    void *func;
    s32 arg[6];
    s32 argc;
} BaddieQueuedCall;
typedef struct {
    BaddieQueuedCall *calls;
    u8 count;
} BaddieCallQueue;

// Init: clears the state.
void chbaddieDll_entrypoint_0(s32 state)
{
    *(u8 *) (state + 4) = 0;
    *(u8 *) (state + 5) = 1;
}

// Map start: sets up zone bounds, cube grid and actor pools; spawns auto-baddies.
void chbaddieDll_entrypoint_1(u8 *state)
{
    *(s8 *) ((s8 *) state + 4) = 0;
    func_800CB9B4();
    func_800BDD00();
    func_800FF390();
    if (func_8001E204() == 0) {
        func_800BDCB8();
        _suautobaddies_entrypoint_0();
    }
}

// Frees the actor pools and the heap block held in the state.
void chbaddieDll_entrypoint_2(u8 *state)
{
    func_800FF564();
    func_800CB9D8();
    heap_free(*(s32 *) ((s8 *) state + 0));
    *(s32 *) ((s8 *) state + 0) = 0;
    *(s8 *) ((s8 *) state + 4) = 0;
}

// Runs the deferred calls queued by diesetup.c (up to 6 int args each), then empties the queue.
void chbaddieDll_entrypoint_3(BaddieCallQueue *queue)
{
    s32 i;

    for (i = 0; i < queue->count; i++) {
        switch (queue->calls[i].argc) {
            case 0:
                ((void (*)(void)) queue->calls[i].func)();
                break;
            case 1:
                ((void (*)(s32)) queue->calls[i].func)(queue->calls[i].arg[0]);
                break;
            case 2:
                ((void (*)(s32, s32)) queue->calls[i].func)(queue->calls[i].arg[0],
                                                              queue->calls[i].arg[1]);
                break;
            case 3:
                ((void (*)(s32, s32, s32)) queue->calls[i].func)(
                    queue->calls[i].arg[0], queue->calls[i].arg[1], queue->calls[i].arg[2]);
                break;
            case 4:
                ((void (*)(s32, s32, s32, s32)) queue->calls[i].func)(
                    queue->calls[i].arg[0], queue->calls[i].arg[1], queue->calls[i].arg[2],
                    queue->calls[i].arg[3]);
                break;
            case 5:
                ((void (*)(s32, s32, s32, s32, s32)) queue->calls[i].func)(
                    queue->calls[i].arg[0], queue->calls[i].arg[1], queue->calls[i].arg[2],
                    queue->calls[i].arg[3], queue->calls[i].arg[4]);
                break;
            case 6:
                ((void (*)(s32, s32, s32, s32, s32, s32)) queue->calls[i].func)(
                    queue->calls[i].arg[0], queue->calls[i].arg[1], queue->calls[i].arg[2],
                    queue->calls[i].arg[3], queue->calls[i].arg[4], queue->calls[i].arg[5]);
                break;
            default:
                break;
        }
    }
    queue->count = 0;
}
