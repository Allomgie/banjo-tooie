// Camera look-at target component of the dynamic camera: picks the target point per target mode,
// smooths it with a spring, and provides the getters used by the camera modes.
#include "core2/1EEBA50.h"

extern f32 func_800F5BC4(s32, s32);
extern void *func_80110840(void *);
extern f32 func_800EEAD4(f32 *, f32 *);
extern f32 func_800F10B4(f32, f32, f32, f32, f32);
extern f32 func_800F5AE0(void *);
extern f32 func_80013728(f32);
extern void func_800EFA4C(f32 *, f32, f32, f32);
extern void func_800EF368(f32 *, f32);
extern void func_800EE7F8(void *, s32);
void func_801124D0();

s32 func_80112160()
{
    return 0x34;
}

// Copies the player position into out.
f32 func_80112168(PlayerState *camera, s32 out)
{
    f32 unk_0;
    f32 pos[3];
    s32 player;

    player = func_80110840(camera);
    unk_0 = func_800F5BC4(player, out);
    func_800F5A00(player, pos);
    func_800EF04C(out, pos);
    return unk_0;
}

void func_801121B8(PlayerState *camera, f32 *out)
{
    func_80112168(camera, out);
}

int func_801121D8(s32 camera, s32 out)
{
    s32 player;
    player = func_80110840(camera);
    // Matching: `| 0` is needed for the match.
    func_800F5A00(player | 0, out);
}

void func_80112204(PlayerState *camera, s32 out)
{
    Vec3f pos;
    func_80112168(camera, out);
    func_800F5470(func_80110840(camera), &pos);
    // Matching: needed for the match.
    if (1) {
        *(f32 *) ((char *) out + 0) = pos.f[0];
        *(f32 *) ((char *) out + 8) = pos.f[2];
    }
}

// Target mode 3: point above and ahead of the player, scaled by distance and pitch.
void func_80112250(void *camera, f32 *out)
{
    f32 offset[3];
    f32 cam_pos[3];
    f32 dist, scale, pitch;
    void *player;
    player = func_80110840(camera);
    func_80112168(camera, out);
    func_801107F0(camera, cam_pos);
    dist = func_800EEAD4(cam_pos, out);
    func_800EFA4C(offset, 0.0f, 200.0f, 0.0f);
    func_800F51F0(player, offset, offset);
    scale = func_800F10B4(dist, 700.0f, 1500.0f, 100.0f, 200.0f);
    pitch = func_80013728(func_800F5AE0(player));
    if (pitch < 0.0f)
        scale *= func_800F10B4(pitch, -30.0f, -60.0f, 1.0f, 0.0f);
    func_800EF368(offset, scale);
    func_800EF04C(out, offset);
}

// Target mode 6: xz taken from the frozen position stored in the slot.
void func_80112354(PlayerState *camera, f32 *out)
{
    func_80112168(camera, out);
    out[0] = (*(f32 **) ((char *) camera + 0x30))[10];
    out[2] = (*(f32 **) ((char *) camera + 0x30))[12];
}

int func_80112398(Actor *camera)
{
    *(s32 *) ((char *) *(s32 **) ((char *) camera + 0x30) + 0x0) = 0;
    func_801124D0(camera, 1);
    func_800EFD24(&*(s32 *) ((char *) *(s32 **) ((char *) camera + 0x30) + 0x4));
}

void func_801123D4(u8 *camera)
{
    f32 target[3];
    switch (**(s32 **) (camera + 0x30)) {
        case 1:
        case 5:
            func_801121B8(camera, target);
            break;
        case 4:
            func_801121D8(camera, target);
            break;
        case 3:
            func_80112250(camera, target);
            break;
        case 2:
            func_80112204(camera, target);
            break;
        case 6:
            func_80112354(camera, target);
    }
    if (func_8010FFD0(func_80110898(camera)) != 0) {
        func_800EE7F8(*(u8 **) (camera + 0x30) + 4, target);
        return;
    }
    func_80111F70(camera, target, *(s32 *) (camera + 0x30) + 4, *(s32 *) (camera + 0x30) + 0x10,
                  *(s32 *) (camera + 0x30) + 0x14);
}

void func_801124D0(camera, mode) void *camera;
s32 mode;
{
    if (mode == 6) {
        func_801121B8(camera, *(s32 *) ((u8 *) camera + 0x30) + 0x28);
    }
    **(s32 **) ((u8 *) camera + 0x30) = mode;
}

u32 func_80112518(void *camera)
{
    return ((u32 **) camera)[0x30 / 4][0];
}

void func_80112524(PlayerState *camera, f32 out[3])
{
    func_800EE7F8(out, *(s32 *) ((char *) camera + 0x30) + 4);
}

f32 func_80112550(PlayerState *camera, f32 *out)
{
    func_80112168(camera, out);
}

void func_80112570(void *camera, s32 vec, f32 unk_0)
{
    func_800EE7F8(*(u8 **) ((u8 *) camera + 0x30) + 0x18, vec);
    *(f32 *) (*(u8 **) ((u8 *) camera + 0x30) + 0x24) = unk_0;
}
