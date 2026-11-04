#include "common.h"

extern s32 func_800FB2AC(f32 *, f32);
extern s32 func_800FB338(f32 *, s32, s32 *, f32 *);
extern u8 *D_80800320_fxripple[];
extern u8 D_80800334_fxripple[];
extern void func_800EE7F8(f32 *, f32 *);
extern void func_800BA660();
extern s32 func_800BABB8(s32, f32 *, f32 *, f32, u8 *);
extern void func_800BA22C(s32, s32);

// Finds the water surface at pos and sets pos[1] to its height.
int func_80800000_fxripple(f32 *pos, s32 *surface, s32 water)
{
    f32 height;
    *surface = 0;
    if (water) {
        pos[1] += 1.0f;
    } else {
        water = func_800FB2AC(pos, 50.0f);
        if (!water)
            return 0;
    }
    if (func_800FB338(pos, water, surface, &height))
        pos[1] = height;
    return 1;
}

s32 func_80800094_fxripple(size, pos, water)
f32 *pos;
{
    s32 surface;
    f32 ripple_pos[3];
    s32 emitter;

    func_800EE7F8(ripple_pos, pos);
    if (!func_80800000_fxripple(ripple_pos, &surface, water))
        return 0;
    ripple_pos[1] += 3.0f;
    emitter = func_800B5BE4(3);
    if (surface != 0)
        func_800BA660(emitter, surface, (s16) (s32) ripple_pos[1]);
    else
        func_800BA660(emitter, 0, 0);
    func_800BABB8(emitter, ripple_pos, 0, 1.0f, D_80800334_fxripple);
    func_800BABB8(emitter, 0, 0, 1.0f, D_80800320_fxripple[size]);
    return emitter;
}

void fxripple_entrypoint_0(s32 size, s32 pos)
{
    s32 emitter = func_80800094_fxripple(size, pos, 0);
    if (emitter != 0) {
        func_800BA22C(emitter, 1);
    }
}

s32 fxripple_entrypoint_1(s32 position[3])
{
    Actor *actor = func_80800094_fxripple(position);
    if (actor) {
        func_800BA22C(actor, 1);
    }
}

void fxripple_entrypoint_2(s32 size, s32 pos)
{
    func_80800094_fxripple(size, pos, 0);
}

void fxripple_entrypoint_3()
{
    func_80800094_fxripple();
}

// Only sets the emitter height.
s32 fxripple_entrypoint_4(f32 height)
{
    s32 emitter;
    s32 height_s16;

    emitter = func_800B5BE4(3);
    height_s16 = (s16) height;
    // Matching: `| 0` is needed for the match.
    func_800BA5D0(emitter | 0, height_s16);
}

// TU-NOTE: the .data of this overlay is defined here in C; values taken from the ROM.
u32 D_80800280_fxripple[8] = {0x2B00B3, 0xE60015, 0x80,       0x220019,
                              0x190066, 0x99001F, 0xFFFFFE00, 0x0};
u32 D_808002A0_fxripple[8] = {0x2B00CC, 0x1330015, 0x80,       0x220019,
                              0x1900E6, 0x1CC001F, 0xFFFFFE00, 0x0};
u32 D_808002C0_fxripple[8] = {0x2B00CC, 0x1000015, 0x80,       0x220019,
                              0x190099, 0x100001F, 0xFFFFFE00, 0x0};
u32 D_808002E0_fxripple[8] = {0x2B00B3, 0xB30015,  0x80,       0x220066,
                              0x6601CC, 0x1E6001F, 0xFFFFFE00, 0x0};
u32 D_80800300_fxripple[8] = {0x2B0180, 0x1800015, 0x80,       0x220019,
                              0x190C00, 0xC00001F, 0xFFFFFE00, 0x0};
u8 *D_80800320_fxripple[5] = {(void *) &D_80800280_fxripple, (void *) &D_808002A0_fxripple,
                              (void *) &D_808002C0_fxripple, (void *) &D_808002E0_fxripple,
                              (void *) &D_80800300_fxripple};
u8 D_80800334_fxripple[12] = {0x0, 0x1D, 0x9, 0xDB, 0x0, 0x16, 0x10, 0x1, 0x0, 0x0, 0x0, 0x0};
