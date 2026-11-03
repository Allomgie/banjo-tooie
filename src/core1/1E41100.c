#include "common.h"

typedef struct {
    u32 w0;
    u32 w1;
} TTAcmd;

typedef struct {
    u8 pad0[0x48];
    u32 unk48;
} TTAMgrX;

extern TTAMgrX *D_800411F4;
extern TTAcmd *func_8002C230(void *, TTAcmd *);

TTAcmd *func_800295D0(void *arg0, TTAcmd *p)
{
    TTAcmd *cmd = p;
    TTAcmd *c1;
    TTAcmd *c2;

    cmd = func_8002C230(arg0, cmd);

    c1 = cmd++;
    c1->w0 = 0x0D000000;

    c2 = cmd++;
    c2->w0 = 0x062E0000;
    c2->w1 = D_800411F4->unk48;

    return cmd;
}

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
