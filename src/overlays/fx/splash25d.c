// "2.5D" water splash preset: snaps a position to the water surface, moves it 20 units towards the
// camera and spawns a camera-facing splash sprite (emitter slot 4).
#include "common.h"

extern void func_800EF368(f32 *, f32);
extern void func_800BABB8(s32, f32 *, s32, f32, void *);
extern u8 D_80800110_fxsplash25d[];
int func_8080002C_fxsplash25d();

s32 fxsplash25d_entrypoint_0(void)
{
    s32 out;
    out = func_8080002C_fxsplash25d();
    func_800BA22C(out, 1);
}

int func_8080002C_fxsplash25d(pos)
f32 *pos;
{
    f32 to_camera[3];
    f32 cam_pos[3];
    f32 splash_pos[3];
    f32 surface_y;
    s32 emitter;
    s32 surface;

    func_800EE7F8(splash_pos, pos);
    func_800FB350(splash_pos, &surface, &surface_y);
    splash_pos[1] = surface_y + 14.0f;
    func_800E3980(cam_pos);
    func_800EFB24(to_camera, cam_pos, splash_pos);
    to_camera[1] = 0.0f;
    // Move the splash 20 units towards the camera.
    func_800EF368(to_camera, 20.0f);
    func_800EF04C(splash_pos, to_camera);
    emitter = func_800B5BE4(4);
    if (surface)
        func_800BA660(emitter, surface, (s16) splash_pos[1]);
    func_800BABB8(emitter, splash_pos, 0, 1.0f, D_80800110_fxsplash25d);
}

// TU-NOTE: the .data of this overlay is defined here in C; values taken from the ROM.
u8 D_80800110_fxsplash25d[48] = {
    0x0, 0x1D, 0x6, 0x39, 0x0, 0x20, 0xFF, 0xFF, 0xFE, 0xFF, 0x0, 0x15, 0x0, 0x0,  0x0, 0xC7,
    0x0, 0x18, 0x0, 0x0,  0x0, 0x0,  0x19, 0xB6, 0x19, 0xB6, 0x0, 0x2B, 0x0, 0xB3, 0x0, 0xB3,
    0x0, 0x23, 0x0, 0xCC, 0x0, 0x0,  0x0,  0x0,  0x0,  0x0,  0x0, 0x0,  0x0, 0x0,  0x0, 0x0};
