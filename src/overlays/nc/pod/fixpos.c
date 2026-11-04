// Fixed-position pod sub-camera: placed at a camera-database node, looking at a tracked actor,
// the player or a fixed point, with optional smoothing and FOV.
#include "common.h"

extern void func_8001B754();
extern void func_8001B798();
extern void func_800EF334(f32 *, f32);
typedef struct {
    f32 cam_pos[3];
    f32 cam_rot[3];
    u8 pad_18[8];
    f32 target_pos[3];
    u32 pad_2C;
    f32 fov;
    f32 unk_34;
    u32 pad_38;
    s32 state;
} FixedCameraPod;
extern f32 func_800136E4(f32);
extern void _ncpod_entrypoint_9(s32, f32);
extern void _ncpod_entrypoint_11(s32, f32);
s32 ncpodfixpos_entrypoint_2();

// True if actor matches the tracked actor id (-1 = none).
int func_80800000_ncpodfixpos(u16 *actor, u32 actor_id)
{
    s32 ret;
    if (actor_id == -1) {
        ret = 0;
    } else {
        ret = (actor_id == ((u32) *(u16 *) (actor + 9) >> 1));
    }
    return ret;
}

s16 ncpodfixpos_entrypoint_0(void)
{
    s16 handle;
    u8 *cam;

    handle = func_8001B668(0, 0x44);
    cam = ncpodfixpos_entrypoint_2(handle);
    *(s32 *) ((u8 *) cam + 0x18) = 0;
    func_800EFD24(cam + 0x20);
    func_800EFD24(cam);
    func_800EFD24(cam + 0xC);
    *(s16 *) ((u8 *) cam + 0x2C) = 0;
    *(s16 *) ((u8 *) cam + 0x38) = -1;
    *(u8 *) ((u8 *) cam + 0x40) = 0;
    *(u8 *) ((u8 *) cam + 0x41) = 0;
    *(u8 *) ((u8 *) cam + 0x42) = 0;
    *(s32 *) ((u8 *) cam + 0x3C) = 0;
    *(s32 *) ((u8 *) cam + 0x18) = 0;
    *(s32 *) ((u8 *) cam + 0x1C) = -1;
    *(f32 *) ((u8 *) cam + 0x30) = 40.0f;
    *(f32 *) ((u8 *) cam + 0x34) = 1.0f;
    return handle;
}

s32 ncpodfixpos_entrypoint_1(handle)
s16 handle;
{
    s32 handle_s32 = handle;
    func_8001B754(handle_s32);
}

s32 ncpodfixpos_entrypoint_2(handle)
s16 handle;
{
    s32 handle_s32 = handle;
    func_8001B798(handle_s32);
}

void func_80800118_ncpodfixpos(s32 cam, s32 unused, s32 state)
{
    *(s32 *) ((char *) cam + 0x3C) = state;

if (state == 1) {
    func_800A5800(*(s16 *) ((char *) cam + 0x38));
    _cadbfunc_entrypoint_0(cam);
    _cadbfunc_entrypoint_2((s32 *) ((char *) cam + 0xC));
    *(s8 *) ((char *) cam + 0x42) = 0;
}

}

void ncpodfixpos_entrypoint_3(s32 cam, s32 unused, s32 node_id)
{
    *(u16 *) (cam + 0x38) = node_id;
    func_80800118_ncpodfixpos(cam, unused, 1);
}

void ncpodfixpos_entrypoint_4(s32 *cam, u16 actor[3])
{
    *(s32 **) (cam + 6) = (s32 *) actor;
    *(s32 *) (cam + 7) = (u32) ((u16) actor[9]) >> 1;
}

void ncpodfixpos_entrypoint_5(void *cam, unsigned long flags)
{
    char *flags_addr;
    char *flags_alias;
    flags_addr = ((char *) cam) + 0x2C;
    flags_alias = flags_addr;
    *((s16 *) flags_alias) = flags;
}

// Updates the target position from the tracked actor (flag 1) or the player (flag 0x40), with optional smoothing (0x400).
int func_808001A8_ncpodfixpos(u8 *cam)
{
    f32 pos[3];
    s16 flags;
    f32 delta_actor[3];
    f32 unk_0[3];
    f32 delta_player[3];
    flags = *(s16 *) (cam + 0x2C);

if (flags & 1) {
    if (func_80800000_ncpodfixpos(*(s32 *) (cam + 0x18), *(s32 *) (cam + 0x1C))) {
        func_80103DFC(func_80106790(*(s32 *) (cam + 0x18)), pos);
        if ((*(s16 *) (cam + 0x2C) & 0x400) && cam[0x42]) {
            func_800EFB24(delta_actor, pos, (f32 *) (cam + 0x20));
            func_800EF334(delta_actor, 0.3f);
            func_800EF04C((f32 *) (cam + 0x20), delta_actor);
            return 1;
        }
        func_800EE7F8(cam + 0x20, pos);
        cam[0x42] = 1;
    }
    return 1;
}

if (flags & 0x40) {
    func_800F5BC4(func_800F54E4(), unk_0);
    func_800F5A00(func_800F54E4(), pos);
    func_800EF04C(pos, unk_0);
    if ((*(s16 *) (cam + 0x2C) & 0x400) && cam[0x42]) {
        func_800EFB24(delta_player, pos, (f32 *) (cam + 0x20));
        func_800EF334(delta_player, 0.3f);
        func_800EF04C((f32 *) (cam + 0x20), delta_player);
        return 1;
    }
    cam[0x42] = 1;
    func_800EE7F8(cam + 0x20, pos);
    return 1;
}

if (flags & 0x80) {
    return 1;
}

return 0;
}

// Per-frame update: look at the target and send position, rotation and FOV to the pod.
s32 ncpodfixpos_entrypoint_6(handle, ctx)
s16 handle;
s32 ctx;
{
    s32 pad0;
    s32 mode;
    s32 out_cam;
    FixedCameraPod *cam;

    cam = (FixedCameraPod *) ncpodfixpos_entrypoint_2(handle);
    mode = cam->state;

if (mode != 0 && mode == 1) {
    out_cam = func_80110024(ctx);
    if (func_808001A8_ncpodfixpos(cam)) {
        func_800F18FC(cam->target_pos, cam->cam_pos, cam->cam_rot);
        cam->cam_rot[0] = func_800136E4(-cam->cam_rot[0]);
    }
    _ncpod_entrypoint_8(out_cam, cam->cam_pos, cam->cam_rot);
    _ncpod_entrypoint_9(out_cam, cam->fov);
    if (cam->fov == 40.0f)
        _ncpod_entrypoint_11(out_cam, cam->unk_34);
}

return 3;
}
