// Crash handler: records the fault reason, then starts a crash thread that enters the gz debugger.
#include "common.h"

extern s32 D_8007E950;
extern void func_8001D96C();
extern void func_8001D37C();
extern void func_8001D3D8();
extern int D_8007E948;
extern void _gzpublic_entrypoint_0(void *);
extern s32 D_8007E958;
extern s32 D_8007E94C;
// TU-NOTE: D_8007E948 starts a Struct_E948 (crash state); D_8007E94C, D_8007E950, D_8007E958 and
// D_8007E95C alias its culprit, culprit_id, caller_id and saved_pri.
typedef struct {
    s32 crash_reason;
    OSThread *culprit;
    s32 culprit_id;
    s32 culprit_pri;
    s32 caller_id;
    s32 saved_pri[10];
} Struct_E948;
extern u8 D_80041180[];
extern s32 D_8011A3F0;
extern OSThread D_8007E788;
extern u8 D_8007E938[];
extern OSThread *__osFaultedThread;
extern OSThread *__osRunningThread;
extern OSThread *func_8001DDA4(s32);
extern OSThread *func_80012598(void);
extern s32 D_8007E95C[];
extern s16 D_8007DB80;

void func_8001E7B4();

// Draws the debug console into the current framebuffer.
void func_8001E2A0()
{
    func_8001DA60(func_80014F00());
}

// Crash reason 0: CPU exception.
void func_8001E2C8(void)
{
    func_8001D96C();
    func_8001D37C("\nFault: CPU exception in thread %d!\n", D_8007E950);
    func_8001E2A0();
}

// Crash reason 1.
void func_8001E304()
{
    func_8001D96C();
    func_8001D37C("\nFault: WATCH GFX!\n");
    func_8001D9CC(0, 0xa);
    _gzreg_entrypoint_1();
    func_8001E2A0();
}

// Crash reason 2: hang detected.
s32 func_8001E34C(void)
{
    func_8001D96C();
    func_8001D37C("\nWe seem to be stuck in an infinite loop!\n");
    func_8001E2A0();
}

// Crash reason 3: no message, only draws the console.
void func_8001E380()
{
    func_8001E2A0();
}

// Any other crash reason.
void func_8001E3A0()
{
    s32 ret;
    ret = func_8001211C();
    func_8001D37C("\n[%d] Crash of unknown origin! (type = %d)\n", ret, (s32) D_8007E948);
    func_8001E2A0();
}

// Crash reason 5: out of memory.
s32 func_8001E3E0(void)
{
    func_8001D37C("\n[%d] Out of Memory!\n", func_8001211C());
    func_8001E2A0();
}

// Crash reason 4: halt.
s32 func_8001E418(void)
{
    func_8001D96C();
    func_8001D37C("\nFault: Halt!\n");
    func_8001E2A0();
}

// Crash reason 6: software lock.
s32 func_8001E44C(void)
{
    func_8001D96C();
    func_8001D3D8(0x11, 0x18, "Error: Software lock in thread %d!\n", D_8007E950);
    func_8001E2A0();
}

// Crash reason 7: destroys the current thread.
int func_8001E490()
{
    osDestroyThread(0);
}

// Shows the message for the recorded crash reason.
void func_8001E4B0()
{
    switch (D_8007E948) {
        case 0:
            func_8001E2C8();
            break;

        case 1:
            func_8001E304();
            break;

        case 2:
            func_8001E34C();
            break;

        case 3:
            func_8001E380();
            break;

        case 4:
            func_8001E418();
            break;

        case 5:
            func_8001E3E0();
            break;

        case 6:
            func_8001E44C();
            break;

        case 7:
            func_8001E490();
            break;

        default:
            func_8001E3A0();
    }
}

// Entry of the crash thread: shows the message, then enters the gz overlay.
void func_8001E578(s32 arg)
{
    func_8001E7B4(1);
    osSetThreadPri(func_8001DDA4(D_8007E958), 0);
    osSetThreadPri(func_8001DDA4(7), 0x5B);
    func_8001E4B0();
    _gzpublic_entrypoint_0(D_8007E94C);
}

// Records the crash (reason, culprit thread, thread priorities) and starts the crash thread.
void func_8001E5DC(s32 reason)
{
    s32 i;
    OSThread *thread;
    s32 id;

    if (D_8011A3F0 != 0) {
        func_8001559C(0);
        (*(Struct_E948 *) &D_8007E948).caller_id = osGetThreadId(NULL);
        for (i = 0; i != 10; i++) {
            thread = func_8001DDA4(i);
            if (thread != NULL) {
                (*(Struct_E948 *) &D_8007E948).saved_pri[i] = osGetThreadPri(thread);
            } else {
                (*(Struct_E948 *) &D_8007E948).saved_pri[i] = 0;
            }
        }
        for (i = 0; i != 10; i++) {
            if (i != (*(Struct_E948 *) &D_8007E948).caller_id) {
                thread = func_8001DDA4(i);
                if (thread != NULL) {
                    osSetThreadPri(thread, D_80041180[i]);
                }
            }
        }
        osSetThreadPri(NULL, 0xA);
        switch (reason) {
            default:
                (*(Struct_E948 *) &D_8007E948).culprit = __osRunningThread;
                break;
            case 1:
                (*(Struct_E948 *) &D_8007E948).culprit = func_8001DDA4(6);
                break;
            case 2:
                (*(Struct_E948 *) &D_8007E948).culprit = func_80012598();
                break;
            case 0:
                (*(Struct_E948 *) &D_8007E948).culprit = __osFaultedThread;
                break;
            case 7:
                (*(Struct_E948 *) &D_8007E948).culprit = __osFaultedThread;
        }
        id = osGetThreadId((*(Struct_E948 *) &D_8007E948).culprit);
        (*(Struct_E948 *) &D_8007E948).culprit_id = id;
        (*(Struct_E948 *) &D_8007E948).culprit_pri =
            (*(Struct_E948 *) &D_8007E948).saved_pri[(*(Struct_E948 *) &D_8007E948).culprit_id];
        (*(Struct_E948 *) &D_8007E948).crash_reason = reason;
        func_8001DCB0(&D_8007E788, D_8007E938, 9, func_8001E578, NULL,
                      (OSThread *) (D_8007E938 - 0x1B0), 0x5A);
        osStartThread(&D_8007E788);
    }
}

// Returns the saved priority of thread index.
int func_8001E7A0(s32 index)
{
    return D_8007E95C[index];
}

void func_8001E7B4(flag) s32 flag;
{
    D_8007DB80 = flag;
}

int func_8001E7C0()
{
    return D_8007DB80;
}

// Returns the recorded crash reason.
int func_8001E7CC()
{
    return D_8007E948;
}

// TU-NOTE: the .data of this file is defined here in C; values are from the ROM.
u8 D_80041180[16] = {0x0, 0x1, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
                     0x0, 0x1, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0};
