// gz crash screen entry: shows build stamp and thread name, then cycles stack, registers, threads.
#include "types.h"
#include "gfx.h"
#include "memory.h"

s32 func_80014F00();
void func_8001D96C();
void func_8001D3D8(s32, s32, const char *, ...);
void _gzthread_entrypoint_0(s32, char *);
void func_8001D9CC(s32, s32);
void _gzreg_entrypoint_0(void *);
void _gzthread_entrypoint_1(s32);
void _gztrace_entrypoint_1(void *, s32, s32, s32);
s32 func_80014F38();
void func_80015430(s32);
void func_8001DA60(s32);

struct unkD_8007E94C {
    s32 unk_0;
    s32 unk_4;
    s32 unk_8;
    s32 unk_C;
    s32 unk_10;
    s32 thread_id;
};

// Mirrors the layout of the build_data ROM segment; do not edit.
struct BuildData {
    u32 unk_0;
    u32 unk_4;
    u32 unk_8;
    u32 unk_C;
    u32 unk_10;
    u32 time;
    u32 month;
    u32 day;
};

extern u8 build_data_ROM_START[];

// 300 frames
void wait_five_seconds_gzpublic(void)
{
    s32 i;

    for (i = 0; i < 300; i++) {
        wait_one_frame();
    }
}

void func_80800040_gzpublic(s32 thread_id)
{
    uintptr_t rom_address;
    char thread_name[12];
    u32 day;
    u32 month;
    u32 time;
    u16 hour;
    u16 minute;

    aligned8_memset(func_80014F00(), 0x12211221, func_80014EC8());
    func_8001D96C();
    rom_address = (uintptr_t) build_data_ROM_START;
    rom_read_word(rom_address + offsetof(struct BuildData, day), &day);
    rom_read_word(rom_address + offsetof(struct BuildData, month), &month);
    rom_read_word(rom_address + offsetof(struct BuildData, time), &time);
    // time is stored as HHMM
    hour = (time / 100);
    minute = time - hour * 100;
    func_8001D3D8(0x22, 0, "Build: %02d:%02d %02d/%02d/00", hour, minute, month, day);
    _gzthread_entrypoint_0(thread_id, thread_name);
    func_8001D3D8(0, 0, "Thread: %s", thread_name);
    func_8001D9CC(0, 3);
}

// Cycles forever through the stack trace, CPU registers and thread list pages.
void gzpublic_entrypoint_0(struct unkD_8007E94C *fault)
{
    wait_five_seconds_gzpublic();
    func_80015430(func_80014F38());
    wait_five_seconds_gzpublic();
    while (TRUE) {
        func_80800040_gzpublic(fault->thread_id);
        _gztrace_entrypoint_1(fault, 0, 0, 0);
        func_8001DA60(func_80014F00());
        wait_five_seconds_gzpublic();

        func_80800040_gzpublic(fault->thread_id);
        _gzreg_entrypoint_0(fault);
        func_8001DA60(func_80014F00());
        wait_five_seconds_gzpublic();

        func_80800040_gzpublic(fault->thread_id);
        _gzthread_entrypoint_1(-1);
        func_8001DA60(func_80014F00());
        wait_five_seconds_gzpublic();

        func_80015430(func_80014F38());
        wait_five_seconds_gzpublic();

        func_80015430(func_80014F38());
    }
}
