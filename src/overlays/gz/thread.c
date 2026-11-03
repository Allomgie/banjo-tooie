#include "common.h"

typedef struct {
    void *local_0;
    s32 local_1;
    void *local_2;
    u8 local_3[4];
    u16 local_4;
    u8 local_5[0xDE];
    u64 local_6;
    u8 local_7[0x24];
    u32 local_8;
} ThreadStatus50;
extern void *func_8001DDA4(s32);

char *D_80800380_gzthread[10] = {"VI",        "IDLE", "TIDY", "CIC-6105", "AUDIO",
                                 "SCHEDULER", "MAIN", "JOY",  "MOTOR",    "CRASH"};
s32 D_808003A8_gzthread[2] = {-0xDFDF01, 0x0};

void gzthread_entrypoint_0(s32 param_0, u8 *param_1)
{
    u8 *local_0 = ((u8 **) D_80800380_gzthread)[param_0];
    while ((*param_1++ = *local_0++) != 0) {
    }
}

void gzthread_entrypoint_1(s32 param_0)
{
    s32 local_0;
    s32 local_1;
    s32 local_2;
    u32 local_3;
    u32 local_4;
    ThreadStatus50 *local_5;
    if (param_0 >= 0) {
        param_0 += 7;
        for (local_0 = 0; local_0 != 9; local_0++)
            func_8001DB90(func_80014ED4(), local_0, param_0, &D_808003A8_gzthread);
    }
    func_8001D3D8(0, 5, "Thread");
    func_8001D3D8(11, -1, "State");
    func_8001D3D8(21, -1, "Pri");
    func_8001D3D8(29, -1, "PC");
    func_8001D3D8(38, -1, "SP");
    func_8001D3D8(47, -1, "Queue\n\n");
    for (local_1 = 0; local_1 != 10; local_1++) {
        local_5 = func_8001DDA4(local_1);
        func_8001D3D8(0, -1, "%s", D_80800380_gzthread[local_1]);
        func_8001D98C(11);
        if (local_5) {
            local_2 = func_8001E7A0(local_1);
            local_3 = local_5->local_8;
            local_4 = local_5->local_6;
            switch (local_5->local_4) {
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
            func_8001D3D8(21, -1, "%3d/%2d", local_2, local_5->local_1);
            func_8001D3D8(29, -1, "%08X", local_3);
            func_8001D3D8(38, -1, "%08X", local_4);
            if (local_5->local_4 == 8)
                func_8001D3D8(47, -1, "%08X\n", local_5->local_2);
            else
                func_8001D37C("\n");
        } else
            func_8001D37C("(n/a)\n");
    }
}
