// Air-bubble preset: spawns bubbles from shared emitter slot 2 inside a box; a pop callback spawns a
// ripple when a bubble reaches the surface. Used by the player underwater, submarine, fish, torpedo.
#include "common.h"

extern void func_800BA568();
extern s32 D_80800100_fxairbub[];
extern void _fxairbub_entrypoint_0();
extern s32 func_800BABB8(s32, f32 *, f32 *, f32, s32 *);
extern s32 func_800BA6B0(s32, s16, s16, s16, s16, s16, s16);

s32 fxairbub_entrypoint_0(s32 param_0)
{
    _fxripple_entrypoint_0(0);
}

// Spawns bubbles in a box around pos; popping a bubble spawns a ripple.
void fxairbub_entrypoint_1(f32 pos[3], f32 half_size, f32 unk_0, f32 scale)
{
    s32 emitter;

    emitter = func_800B5BE4(2);
    func_800BA568(emitter, (s16) unk_0);
    func_800BA6B0(emitter, (s16) -half_size, 0, (s16) -half_size, (s16) half_size, 0, (s16) half_size);
    func_800BA544(emitter, _fxairbub_entrypoint_0);
    func_800BABB8(emitter, pos, NULL, scale, D_80800100_fxairbub);
}

// TU-NOTE: the .data of this overlay is defined here in C; values taken from the ROM.
s32 D_80800100_fxairbub[20] = {
    0x1D09D9, 0x161004, 0x1B0096,   0x960007, 0x10015, 0xCC,     0x2B0300, 0x300002C, 0x0,  0x0,
    0x0,      0x20FFFF, -0x100FFDE, 0xC0017,  0xC0017, 0x2F0040, 0x400000, 0x19,      0x33, 0x0};
