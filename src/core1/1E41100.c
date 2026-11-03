#include "common.h"

typedef struct {
    u32 w0;
    u32 w1;
} TTAcmd;

typedef struct {
    u8 pad0[0x48];
    u32 out_buf; // 0x48: output buffer address for A_SAVEBUFF
} TTAMgrX;

extern TTAMgrX *D_800411F4;
extern TTAcmd *func_8002C230(void *, TTAcmd *);

// Last pull stage: bus mix, then A_INTERLEAVE and A_SAVEBUFF (n_alSavePull).
TTAcmd *func_800295D0(void *arg0, TTAcmd *list)
{
    TTAcmd *cmd = list;
    TTAcmd *interleave;
    TTAcmd *save;

    cmd = func_8002C230(arg0, cmd);

    // Acmd words are written with the post-increment macro pattern.
    interleave = cmd++;
    interleave->w0 = 0x0D000000;

    save = cmd++;
    save->w0 = 0x062E0000;
    save->w1 = D_800411F4->out_buf;

    return cmd;
}

// TU-NOTE: the .rodata below holds constants used by 1E3EDE0 (formerly part of its
// .rodata.s). They follow 1E3EDE0's literals in the ROM, so they cannot live in that file:
// IDO puts a file's const objects in front of its literals. This is the next file in link
// order without .rodata of its own.
const struct {
    f32 x;
} D_80041D10 = {3.1415927f};
const struct {
    f32 x;
} D_80041D14 = {1.4142137f};
const struct {
    f32 x;
} D_80041D18 = {1.0594631f};
const struct {
    f32 x;
} D_80041D1C = {0.9438743f};
const struct {
    f32 x;
} D_80041D20 = {26768.0f};
const struct {
    f32 x;
} D_80041D24 = {26768.0f};
const struct {
    f32 x;
    f32 pad[1];
} D_80041D28 = {173123.4f};
