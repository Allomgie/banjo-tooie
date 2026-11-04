#include "common.h"

typedef struct {
    void *unk_0;
    s32 priority;
    void *queue;
    u8 unk_C[4];
    u16 state;
    u8 unk_12[0xDE];
    u64 sp;
    u8 unk_F8[0x24];
    u32 pc;
} ThreadStatus50;
extern void *func_8001DDA4(s32);

// TU-NOTE: the overlay data is defined here in C; IDO places the string literals in .rodata where the original has them.
// Thread names, indexed by thread id.
char *D_80800380_gzthread[10] = {"VI",        "IDLE", "TIDY", "CIC-6105", "AUDIO",
                                 "SCHEDULER", "MAIN", "JOY",  "MOTOR",    "CRASH"};
s32 D_808003A8_gzthread[2] = {-0xDFDF01, 0x0};

// Copies the name of thread `index` into `out`.
void gzthread_entrypoint_0(s32 index, u8 *out)
{
    u8 *name = ((u8 **) D_80800380_gzthread)[index];
    while ((*out++ = *name++) != 0) {
    }
}

// Draws the thread table; `row` >= 0 highlights one row.
void gzthread_entrypoint_1(s32 row)
{
    s32 i;
    s32 j;
    s32 saved_priority;
    u32 pc;
    u32 sp;
    ThreadStatus50 *thread;
    if (row >= 0) {
        row += 7;
        for (i = 0; i != 9; i++)
            func_8001DB90(func_80014ED4(), i, row, &D_808003A8_gzthread);
    }
    func_8001D3D8(0, 5, "Thread");
    func_8001D3D8(11, -1, "State");
    func_8001D3D8(21, -1, "Pri");
    func_8001D3D8(29, -1, "PC");
    func_8001D3D8(38, -1, "SP");
    func_8001D3D8(47, -1, "Queue\n\n");
    for (j = 0; j != 10; j++) {
        thread = func_8001DDA4(j);
        func_8001D3D8(0, -1, "%s", D_80800380_gzthread[j]);
        func_8001D98C(11);
        if (thread) {
            saved_priority = func_8001E7A0(j);
            pc = thread->pc;
            sp = thread->sp;
            switch (thread->state) {
                case 1:
                    func_8001D37C("Stopped");
                    break;
                case 2:
                    func_8001D37C("Runnable");
                    break;
                case 4:
                    func_8001D37C("Running");
                    break;
                case 8:
                    func_8001D37C("Waiting");
                    break;
            }
            func_8001D3D8(21, -1, "%3d/%2d", saved_priority, thread->priority);
            func_8001D3D8(29, -1, "%08X", pc);
            func_8001D3D8(38, -1, "%08X", sp);
            if (thread->state == 8)
                func_8001D3D8(47, -1, "%08X\n", thread->queue);
            else
                func_8001D37C("\n");
        } else
            func_8001D37C("(n/a)\n");
    }
}
