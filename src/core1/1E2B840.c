// RSP/RDP task scheduler thread: queues audio and graphics tasks, picks the microcode, handles
// RCP events with watchdog timeouts, and blanks the display on PRE-NMI. Also holds the VI modes.
#include "threads.h"
#include "types.h"
#include "buffers.h"

extern long long int n_aspMainTextStart[];
extern long long int n_aspMainDataStart[];

typedef enum task_type_e {
    TASK_TYPE_AUDIO,
    TASK_TYPE_GFX_3D,
    TASK_TYPE_GFX_LINE,
    TASK_TYPE_DISABLE_GFX = 7
} TaskType;

typedef struct {
    TaskType type;
} TaskHeader;

typedef struct {
    TaskHeader header;
    s32 unk_4;
    Gfx *list_start;
    Gfx *list_end;
} GraphicsTask;

typedef struct {
    TaskHeader header;
    s32 unk_4;
    Acmd *list_start;
    Acmd *list_end;
    OSMesgQueue *reply_queue;
    OSMesg reply_msg;
} AudioTask;

#define audioManager_getFrameMesgQueue func_80012F00
#define pfsManager_getStartReadData func_80016810
#define rumbleManager_80018634 func_80018634

OSMesgQueue *audioManager_getFrameMesgQueue(void);
void pfsManager_getStartReadData(void);
void rumbleManager_80018634(void);
void func_80014F64(OSMesgQueue *queue, OSMesg mesg);

#define SCHEDULER_EVENT_DP 4
#define SCHEDULER_EVENT_VI 5
#define SCHEDULER_EVENT_SP 6
#define SCHEDULER_EVENT_AUDIO_TIMER 8
#define SCHEDULER_EVENT_FAULT 10
#define SCHEDULER_EVENT_PRENMI 11
#define SCHEDULER_EVENT_CONT_TIMER 13

// TU-NOTE: .data of this file: OSTask templates (audio D_8003F3B0, graphics D_8003F3F0); the
// VI mode tables follow later and must be defined after func_8001443C.
OSTask D_8003F3B0 = {
    M_AUDTASK, 0,    NULL, 0,    NULL, SP_UCODE_SIZE, NULL, SP_UCODE_DATA_SIZE, NULL,
    0,         NULL, NULL, NULL, 0,    NULL,          0,
};

OSTask D_8003F3F0 = {
    M_GFXTASK,  0,
    NULL,       0,
    NULL,       SP_UCODE_SIZE,
    NULL,       SP_UCODE_DATA_SIZE,
    D_80000400, SP_DRAM_STACK_SIZE8,
    D_80000800, &D_80000800[GFX_OUTPUT_BUFFER_SIZE64],
    NULL,       0,
    NULL,       OS_YIELD_DATA_SIZE,
};

extern u64 D_800777B0[OS_YIELD_DATA_SIZE / sizeof(u64)];
extern OSMesgQueue D_800783D0;
extern OSMesg D_800783E8[20];
extern OSMesgQueue D_80078438;
extern OSMesg D_80078450[10];
extern AudioTask *D_80078478;
extern s32 D_8007847C;
extern int D_80078480; // disable_graphics
extern s32 D_80078484;
extern s32 D_80078488;
extern s32 D_8007848C;
extern s32 D_80078490;
extern s32 D_80078494;
extern u64 D_80078498[SCHEDULER_THREAD_STACK_SIZE64]; // stack of thread D_80078C98
extern OSThread D_80078C98;
extern GraphicsTask *D_80078E58[20];
extern volatile s32 D_80078EA8;
extern volatile s32 D_80078EAC;
extern AudioTask *D_80078EB0[20];
extern volatile s32 D_80078F00;
extern volatile s32 D_80078F04;
extern void *D_80078F08;
extern s32 D_80078F0C;
extern s32 D_80078F10;
extern s32 D_80078F14;
extern OSTimer D_80078F18; // audio_timer
extern OSTimer D_80078F38; // controller_timer
// TODO: only 0x10 bytes, so probably a different struct (same as the joy thread).
extern __OSThreadOddFpStorage D_80078E48;
extern s32 D_80078F58;
extern s32 D_80078F5C;

// Scheduler thread, task queues, microcode selection, event dispatch, watchdog, PRE-NMI handling.
// Sends msg to the scheduler thread. Msg 3 also waits for the frame handshake (D_80078438),
// guarded by a watchdog timeout.
void func_80013D10(OSMesg msg)
{
    static s32 D_8003F430 = 1;
    osSendMesg(&D_800783D0, msg, 1);
    if ((s32) msg == 3) {
        D_80078F0C = 0x1e;
        if (D_8003F430) {
            osDpSetStatus(DPC_CLR_FREEZE);
            D_8003F430 = 0;
        }
        osRecvMesg(&D_80078438, NULL, OS_MESG_BLOCK);
        D_80078F0C = 0;
    }
}

// Pushes an audio task onto its ring queue (dropped when full).
void func_80013D94(AudioTask *task)
{
    s32 next = (D_80078F00 + 1) % ARRLEN(D_80078EB0);
    if (D_80078F04 != next) {
        D_80078EB0[D_80078F00] = task;
        D_80078F00 = next;
    }
}

// Pushes a graphics task onto its ring queue (dropped when full).
void func_80013DE4(GraphicsTask *task)
{
    s32 next = (D_80078EA8 + 1) % ARRLEN(D_80078E58);
    if (D_80078EAC != next) {
        D_80078E58[D_80078EA8] = task;
        D_80078EA8 = next;
    }
}

// Starts an audio task on the RSP (n_aspMain).
void func_80013E34(AudioTask *task)
{
    D_8003F3B0.t.ucode_boot = (u64 *) rspbootTextStart;
    D_8003F3B0.t.ucode_boot_size = (u8 *) rspbootTextEnd - (u8 *) rspbootTextStart;
    D_8003F3B0.t.ucode = (u64 *) n_aspMainTextStart;
    D_8003F3B0.t.ucode_data = (u64 *) n_aspMainDataStart;
    D_8003F3B0.t.data_ptr = (u64 *) task->list_start;
    D_8003F3B0.t.data_size = (task->list_end - task->list_start) * sizeof(Acmd);
    osWritebackDCache(D_8003F3B0.t.data_ptr, D_8003F3B0.t.data_size);
    osWritebackDCache(&D_8003F3B0, sizeof(OSTask));
    D_80078478 = task;
    osSpTaskStart(&D_8003F3B0);
    D_8007848C = 4;
}

// Starts a graphics task with the F3DEX2 NoN fifo microcode.
void func_80013EF0(GraphicsTask *task)
{
    D_8003F3F0.t.ucode_boot = (u64 *) rspbootTextStart;
    D_8003F3F0.t.ucode_boot_size = (u8 *) rspbootTextEnd - (u8 *) rspbootTextStart;
    D_8003F3F0.t.ucode = (u64 *) gspF3DEX2_NoN_fifoTextStart;
    D_8003F3F0.t.ucode_data = (u64 *) gspF3DEX2_NoN_fifoDataStart;
    D_8003F3F0.t.data_ptr = (u64 *) task->list_start;
    D_8003F3F0.t.data_size = (task->list_end - task->list_start) * sizeof(Gfx);
    osWritebackDCache(D_8003F3F0.t.data_ptr, D_8003F3F0.t.data_size);
    osWritebackDCache(&D_8003F3F0, sizeof(OSTask));
    osSpTaskStart(&D_8003F3F0);
    D_8007848C = task->unk_4 | 0x8;
    D_80078488 = task->unk_4 | 0x1;
    if (!(osDpGetStatus() & DPC_STATUS_FREEZE)) {
        D_80078484 = D_80078488;
        D_80078F10 = 0x1e;
    }
}

// Starts a graphics task with the L3DEX2 (line) microcode.
void func_80013FE4(GraphicsTask *task)
{
    D_8003F3F0.t.ucode_boot = (u64 *) rspbootTextStart;
    D_8003F3F0.t.ucode_boot_size = (u8 *) rspbootTextEnd - (u8 *) rspbootTextStart;
    D_8003F3F0.t.ucode = (u64 *) gspL3DEX2_fifoTextStart;
    D_8003F3F0.t.ucode_data = (u64 *) gspL3DEX2_fifoDataStart;
    D_8003F3F0.t.data_ptr = (u64 *) task->list_start;
    D_8003F3F0.t.data_size = (task->list_end - task->list_start) * sizeof(Gfx);
    osWritebackDCache(D_8003F3F0.t.data_ptr, D_8003F3F0.t.data_size);
    osWritebackDCache(&D_8003F3F0, sizeof(OSTask));
    osSpTaskStart(&D_8003F3F0);
    D_8007848C = task->unk_4 | 0x8;
    D_80078488 = task->unk_4 | 0x1;
    if (!(osDpGetStatus() & DPC_STATUS_FREEZE)) {
        D_80078484 = D_80078488;
        D_80078F10 = 0x1e;
    }
}

// Starts a graphics task with the microcode its type asks for.
void func_800140D8(GraphicsTask *task)
{
    switch (task->header.type) {
        case TASK_TYPE_GFX_3D:
            func_80013EF0(task);
            break;

        case TASK_TYPE_GFX_LINE:
            func_80013FE4(task);
    }
}

// Receives an audio task from the message loop.
void func_80014128(AudioTask *task)
{
    func_80013D94(task);
}

// Receives a 3D graphics task; starts it right away when the RSP is idle.
void func_80014148(GraphicsTask *task)
{
    func_80013DE4(task);
    if (D_8007848C == 0x10 && !D_80078480) {
        func_80013EF0(D_80078E58[D_80078EAC]);
        D_80078EAC = (D_80078EAC + 1) % ARRLEN(D_80078E58);
    }
}

// Receives a line graphics task; starts it right away when the RSP is idle.
void func_800141D0(GraphicsTask *task)
{
    func_80013DE4(task);
    if (D_8007848C == 0x10 && !D_80078480) {
        func_80013FE4(D_80078E58[D_80078EAC]);
        D_80078EAC = (D_80078EAC + 1) % ARRLEN(D_80078E58);
    }
}

// Frame handshake request: answers now if everything is idle, otherwise counts it as pending.
void func_80014258(void)
{
    if (D_8007848C == 0x10 && D_80078484 == 2 && D_80078EAC == D_80078EA8 &&
        !(osDpGetStatus() & DPC_STATUS_FREEZE)) {
        osSendMesg(&D_80078438, NULL, OS_MESG_NOBLOCK);
    } else {
        D_8007847C++;
    }
}

// DP event: freezes the display on a framebuffer change, then starts the next queued graphics
// task or answers a pending handshake.
void func_800142F0(void)
{
    if ((D_80078484 << 1) < 0) {
        osDpSetStatus(DPC_SET_FREEZE);
        D_80078F08 = osViGetCurrentFramebuffer();
        func_80015190();
    }
    D_80078484 = D_80078488 = 2;
    D_80078F10 = 0;
    if (D_8007848C == 0x10 && D_80078EAC != D_80078EA8 && !D_80078480) {
        func_800140D8(D_80078E58[D_80078EAC]);
        D_80078EAC = (D_80078EAC + 1) % ARRLEN(D_80078E58);
    } else {
        if (D_8007847C && D_80078EAC == D_80078EA8 && !(osDpGetStatus() & DPC_STATUS_FREEZE)) {
            osSendMesg(&D_80078438, NULL, 0);
            D_8007847C--;
        }
    }
}

// VI event (retrace): completes pending handshakes, runs the RCP-hang watchdogs and re-arms the
// audio and controller timers.
void func_8001443C(void)
{
    s32 handshake_ready = (D_8007847C != 0) && (D_80078EAC == D_80078EA8) && (D_80078488 == 2) &&
                          (D_8007848C == 0x10);
    s32 timed_out;
    static s32 D_8003F434 = 0;

    timed_out = FALSE;
    if (osViGetCurrentFramebuffer() != D_80078F08 || handshake_ready) {
        if (osDpGetStatus() & DPC_STATUS_FREEZE) {
            osDpSetStatus(DPC_CLR_FREEZE);

            D_80078484 = D_80078488;

            if (D_80078484 & 1) {
                D_80078F10 = 0x1E;
            }
        }

        if (handshake_ready) {
            osSendMesg(&D_80078438, NULL, OS_MESG_NOBLOCK);
            D_8007847C--;
        }
    }

    // Watchdog counters; reaching zero means the RCP hung.
    if (D_80078F0C != 0) {
        D_80078F0C--;
        if (D_80078F0C == 0) {
            timed_out = TRUE;
        }
    }

    if (D_80078F14 != 0) {
        D_80078F14--;
        if (D_80078F14 == 0) {
            timed_out = TRUE;
        }
    }

    if (D_80078F10 != 0) {
        D_80078F10--;
        if (D_80078F10 == 0) {
            timed_out = TRUE;
        }
    }
    if (timed_out) {
        func_8001E5DC(1);
    }
    D_80078480 = 0;
    D_8003F434++;
    if (!(D_8003F434 & 1)) {
        // Audio timer: approximately 6 ms.
        osStopTimer(&D_80078F18);
        osSetTimer(&D_80078F18, OS_NSEC_TO_CYCLES(5973334), 0, &D_800783D0,
                   (OSMesg) SCHEDULER_EVENT_AUDIO_TIMER);
    }

    if (D_80078F58) {
        // Controller timer: 2/3 of a VI period.
        osStopTimer(&D_80078F38);
        osSetTimer(&D_80078F38, ((osClockRate / 60) * 2) / 3, 0, &D_800783D0,
                   (OSMesg) SCHEDULER_EVENT_CONT_TIMER);
    }
}

// SP event: the RSP finished or yielded a task; resumes graphics or starts the next task.
void func_800146D8(void)
{
    AudioTask *audio_task;

    if (D_8007848C == 0x20) {
        audio_task = D_80078EB0[D_80078F04];
        D_80078F04 = (D_80078F04 + 1) % ARRLEN(D_80078EB0);
        D_80078494 = (osSpTaskYielded(&D_8003F3F0) == 1);
        func_80013E34(audio_task);
        D_80078F14 = 0;
        return;
    }

    if (D_8007848C == 4) {
        osSendMesg(D_80078478->reply_queue, D_80078478->reply_msg, 0);
    }

    if ((D_8007848C == 4) && (D_80078494 != 0)) {
        osSpTaskLoad(&D_8003F3F0);
        osSpTaskStartGo(&D_8003F3F0);
        D_8007848C = D_80078490;
        D_80078494 = 0;
        return;
    }

    D_8007848C = 0x10;
    if ((D_80078EAC != D_80078EA8) && (D_80078480 == 0)) {
        func_800140D8(D_80078E58[D_80078EAC]);
        D_80078EAC = (D_80078EAC + 1) % ARRLEN(D_80078E58);
        return;
    }

    if ((D_8007847C != 0) && (D_80078484 == 2) && !(osDpGetStatus() & 2)) {
        osSendMesg(&D_80078438, NULL, 0);
        D_8007847C -= 1;
    }
}

// Disables graphics until the next VI event.
void func_800148B0(OSMesg msg)
{
    D_80078480 = TRUE;
}

// Audio timer event: signals the audio frame queue, then starts the next audio task or yields
// the running graphics task for it.
void func_800148C4(void)
{
    AudioTask *task;
    osSendMesg(audioManager_getFrameMesgQueue(), NULL, OS_MESG_NOBLOCK);
    if ((D_8007848C == 0x10) && (D_80078F04 != D_80078F00)) {
        task = D_80078EB0[D_80078F04];
        D_80078F04 = (D_80078F04 + 1) % ARRLEN(D_80078EB0);
        func_80013E34(task);
    } else if ((D_8007848C & 0x8) && (D_80078F04 != D_80078F00)) {
        osSpTaskYield();
        D_80078490 = D_8007848C;
        D_8007848C = 0x20;
        D_80078F14 = 0x1E;
    }
}

// TU-NOTE: .data continued; must stay after func_8001443C. MPAL VI mode:
OSViMode D_8003F438 = {OS_VI_MPAL_LPN1,
                       {
                           VI_CTRL_TYPE_16 | VI_CTRL_GAMMA_DITHER_ON | VI_CTRL_GAMMA_ON | 0x3200, // ctrl
                           320, // width
                           0x4651E39, // burst
                           0x20D, // vSync
                           0x40C11, // hSync
                           0xC190C1A, // leap
                           0x6C02EC, // hStart
                           0, // xScale
                           0, // vCurrent
                       },
                       {{640, 1024, 0x2501FF, 0xE0204, 2}, {640, 1024, 0x2501FF, 0xE0204, 2}}};

// NTSC VI mode (also used for PAL).
OSViMode D_8003F488 = {OS_VI_NTSC_LPN1,
                       {
                           VI_CTRL_TYPE_16 | VI_CTRL_GAMMA_DITHER_ON | VI_CTRL_GAMMA_ON | 0x3200, // ctrl
                           320, // width
                           0x3E52239, // burst
                           0x20D, // vSync
                           0xC15, // hSync
                           0xC150C15, // leap
                           0x6C02EC, // hStart
                           0, // xScale
                           0, // vCurrent
                       },
                       {{0x280, 1024, 0x2501FF, 0xE0204, 2}, {640, 1024, 0x2501FF, 0xE0204, 2}}};

// PRE-NMI: blanks the display, sets the VI mode, stops rumble and halts.
void func_800149BC(void)
{
    // Matching: the local pointer is needed; a function-local static also matches.
    s32 *done_ptr = &D_80078F5C;

    if (!*done_ptr) {
        *done_ptr = TRUE;
        func_800155BC();
        switch (osTvType) {
            case OS_TV_PAL:
            case OS_TV_NTSC:
                osViSetMode(&D_8003F488);
                break;
            case OS_TV_MPAL:
                osViSetMode(&D_8003F438);
        }
        func_80015430(0);
        rumbleManager_80018634(); // stop controller motors
        while (TRUE) {
            osDpSetStatus(DPC_STATUS_FLUSH);
        }
    }
}

void func_80014A54(void)
{
    if (!(__osGetSR_2() & SR_IBIT5)) {
        func_800149BC();
    }
}

// scheduler_thread_entry: dispatches scheduler events and incoming tasks (msg >= 100).
void func_80014A88(void *arg)
{
    OSMesg msg = NULL;
    while (TRUE) {
        osRecvMesg(&D_800783D0, &msg, OS_MESG_BLOCK);
        func_80014A54();
        if ((s32) msg == 3) {
            func_80014258();
        } else if ((u32) msg == SCHEDULER_EVENT_VI) {
            func_8001443C();
        } else if ((u32) msg == SCHEDULER_EVENT_DP) {
            func_800142F0();
        } else if ((u32) msg == SCHEDULER_EVENT_SP) {
            func_800146D8();
        } else if ((u32) msg == SCHEDULER_EVENT_AUDIO_TIMER) {
            func_800148C4();
        } else if ((u32) msg == SCHEDULER_EVENT_FAULT) {
            func_8001E5DC(0);
        } else if ((u32) msg == SCHEDULER_EVENT_PRENMI) {
            func_800149BC();
        // Matching: the empty branch is needed for the match.
        } else if ((u32) msg == 12) {
        } else if ((u32) msg == SCHEDULER_EVENT_CONT_TIMER) {
            pfsManager_getStartReadData();
        } else if ((u32) msg >= 100) {
            if (((TaskHeader *) msg)->type == TASK_TYPE_AUDIO) {
                func_80014128((AudioTask *) msg);
            } else if (((TaskHeader *) msg)->type == TASK_TYPE_GFX_3D) {
                func_80014148((GraphicsTask *) msg);
            } else if (((TaskHeader *) msg)->type == TASK_TYPE_GFX_LINE) {
                func_800141D0((GraphicsTask *) msg);
            } else if (((TaskHeader *) msg)->type == TASK_TYPE_DISABLE_GFX) {
                func_800148B0(msg);
            }
        }
    }
}

// scheduler_init: creates the queues, sets the event messages, and starts the scheduler thread.
void func_80014C40(void)
{
    u8 *yield_buf;
    osCreateMesgQueue(&D_800783D0, D_800783E8, ARRLEN(D_800783E8));
    osCreateMesgQueue(&D_80078438, D_80078450, ARRLEN(D_80078450));
    osSetEventMesg(OS_EVENT_DP, &D_800783D0, (OSMesg) SCHEDULER_EVENT_DP);
    osSetEventMesg(OS_EVENT_SP, &D_800783D0, (OSMesg) SCHEDULER_EVENT_SP);
    osSetEventMesg(OS_EVENT_FAULT, &D_800783D0, (OSMesg) SCHEDULER_EVENT_FAULT);
    osSetEventMesg(OS_EVENT_PRENMI, &D_800783D0, (OSMesg) SCHEDULER_EVENT_PRENMI);
    func_80014F64(&D_800783D0, (OSMesg) SCHEDULER_EVENT_VI);
    D_8007847C = 0;
    D_80078480 = 0;
    D_80078484 = D_80078488 = 2;
    D_8007848C = D_80078490 = 0x10;
    D_80078494 = 0;
    D_80078EAC = 0;
    D_80078EA8 = 0;
    D_80078F04 = 0;
    D_80078F00 = 0;
    // Yield buffer, aligned to 16 bytes.
    yield_buf = (u8 *) D_800777B0;
    while ((u32) yield_buf % 0x10) {
        yield_buf++;
    }
    D_8003F3F0.t.yield_data_ptr = (u64 *) yield_buf;
    func_8001DCB0(&D_80078C98, &D_80078E48, THREAD_ID_SCHEDULER, func_80014A88, NULL,
                  &D_80078498[SCHEDULER_THREAD_STACK_SIZE64], SCHEDULER_THREAD_PRIORITY);
    osStartThread(&D_80078C98);
}

// Enables the controller timer.
void func_80014DC4(void)
{
    D_80078F58 = 1;
}

// Appends gDPPipeSync and gSPEndDisplayList.
// Ends a display list.
void func_80014DD4(Gfx **gfx)
{
    gDPPipeSync((*gfx)++);
    gSPEndDisplayList((*gfx)++);
}
