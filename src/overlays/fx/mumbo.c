// Most likely the particle preset for Mumbo's magic: sparkles from shared emitter slot 0xD.
#include "common.h"

extern void *func_800B5BE4(int);
extern void func_800BA22C(void *, s32);
extern void func_800BABB8(void *, s32, int, float, void *);
extern void *D_80800060_fxmumbo;

// Spawns Mumbo magic sparkles from shared emitter slot 0xD.
void fxmumbo_entrypoint_0(s32 pos, s32 count)
{
    void *emitter;
    emitter = func_800B5BE4(0xD);
    func_800BABB8(emitter, pos, 0, 1.0f, &D_80800060_fxmumbo);
    func_800BA22C(emitter, count);
}

// TU-NOTE: .data of this overlay is defined here in C; values are taken from the ROM.
void *D_80800060_fxmumbo = (void *) 0x001D09E9;
static u32 D_80800060_fxmumbo_rest[19] = {0x150033,  0x660022,  0xC000C,    0x190019,   0x270000,
                                          0x1900000, 0x1B80016, 0x1000002B, 0x4C0059,   0x2CFFE7,
                                          0x28FFE7,  0x190050,  0x19001B,   0xFF9CFF9C, 0xC0008,
                                          0x0,       0x0,       0x0,        0x0};
