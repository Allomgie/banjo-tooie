// Water-splash preset: spawns a splash (emitter slot 1) in a box around a position, sets the water
// height and a ripple callback; a variant adds a second burst. Used by the player, fish, pool kids.
#include "common.h"

extern int D_80800130_fxsplash[];
extern s32 D_80800144_fxsplash[];
extern void _fxsplash_entrypoint_0(void);
extern s32 func_800B5BE4(s32);
extern int func_800BA6B0(s32, s16, s16, s16, s16, s16, s16);
extern void func_800BA4D0();
extern s32 func_800BABB8(s32, f32 *, f32 *, f32, s32 *);
int fxsplash_entrypoint_2(f32 *param_0, f32 param_1);

s32 fxsplash_entrypoint_0(s32 unk_0)
{
    _fxripple_entrypoint_0(0);
}

// Splash with a second burst from preset D_80800130_fxsplash.
int fxsplash_entrypoint_1(s32 pos)
{
    s32 emitter;
    emitter = fxsplash_entrypoint_2(pos, 20.0f);
    func_800BABB8(emitter, 0, 0, 1.0f, &D_80800130_fxsplash);
}

// Spawns a splash in a box around pos; the callback spawns a ripple.
int fxsplash_entrypoint_2(f32 *pos, f32 size)
{
    s32 emitter;
    s32 low;
    s32 high;

    emitter = func_800B5BE4(1);
    low = (s32) -size;
    high = (s32) size;
    func_800BA6B0(emitter, (s16) low, 0, (s16) low, (s16) high, 0, (s16) high);
    func_800BA4D0((void *) emitter, (s16) (s32) pos[1]);
    func_800BA544((void *) emitter, (s32) _fxsplash_entrypoint_0);
    func_800BABB8(emitter, pos, NULL, 1.0f, D_80800144_fxsplash);
}

// TU-NOTE: the .data of this overlay is defined here in C; values taken from the ROM.
// D_80800130_fxsplash is declared as int[] to match the object (same address).
int D_80800130_fxsplash[5] = {0x2CFF4C, 0x190FF4C, 0xB402BC, 0xB4141A, 0x0};
s32 D_80800144_fxsplash[15] = {0x1D09DA,  0x20FFFF,   -0x14BFFE5, -0x5130514, 0x70001,
                               0x150000,  0xCC0022,   0x5000A,    0x20002,    0x2B0200,
                               0x2000016, 0x10000000, 0x0,        0x0,        0x0};
