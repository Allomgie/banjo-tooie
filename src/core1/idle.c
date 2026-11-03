#include <ultra64.h>
#include "threads.h"

void func_800131C0(void);
void func_80012548(void);
OSThread *func_80012598(void);

extern u64 D_800773F0[IDLE_THREAD_STACK_SIZE64];
extern OSThread D_800775F0;
extern __OSThreadOddFpStorage D_800777A0;

void func_80013678(void *);

void func_80013620(void)
{
    func_8001DCB0(&D_800775F0, &D_800777A0, THREAD_ID_IDLE, func_80013678, NULL,
                  &D_800773F0[IDLE_THREAD_STACK_SIZE64], IDLE_THREAD_PRIORITY);
    osStartThread(&D_800775F0);
}

void func_80013678(void *arg)
{
    func_800131C0();
    func_80012548();
    osStartThread(func_80012598());
    while (TRUE) {
    }
}
