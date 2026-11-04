// Camera deflection helpers: push the camera out of a vertical cylinder or a sphere plus a margin,
// so it does not enter large actors or objects.
#include "common.h"

extern void func_80111094(void *, f32 *);
extern void func_801110C4(void *, f32 *);
extern void func_800EFA4C(f32 *, f32, f32, f32);
extern f32 func_800D8FF8(void);
extern f32 func_800F13F0(f32, f32);
extern f32 func_800DC0C0(void);
extern void func_800EF368(f32 *, f32);
extern void func_800EF04C(f32 *, f32 *);
extern void func_800EFB24(f32 *, f32 *, f32 *);

// Push the camera out of a vertical cylinder (plus an 80-unit margin).
void ncbadeflect_entrypoint_0(void *camera, f32 *center, f32 top, f32 bottom, f32 radius,
                              f32 speed)
{
    f32 dist;
    f32 reach;
    f32 unk_0;
    f32 push;
    f32 unk_1;
    f32 cam_pos[3];
    f32 offset[3];
    s32 pad0;
    func_80111094(camera, cam_pos);
    if (cam_pos[1] + 40.0f < center[1] + bottom)
        return;
    if (center[1] + top < cam_pos[1] - 40.0f)
        return;
    func_800EFA4C(offset, cam_pos[0] - center[0], 0.0f, cam_pos[2] - center[2]);
    dist = offset[0] * offset[0] + offset[1] * offset[1] + offset[2] * offset[2];
    reach = radius + 80.0f;
    if (reach * reach < dist)
        return;
    dist = sqrtf(dist);
    push = func_800F13F0(func_800D8FF8() * speed, reach - dist);
    // exactly at the centre: push in a random direction
    if (dist == 0.0f) {
        dist = func_800DC0C0();
        func_800EFA4C(offset, dist, 0.0f, func_800DC0C0());
    }
    func_800EF368(offset, push);
    func_800EF04C(cam_pos, offset);
    func_801110C4(camera, cam_pos);
}

// Push the camera out of a sphere (plus an 80-unit margin).
void ncbadeflect_entrypoint_1(s32 camera, f32 *center, f32 height, f32 radius, f32 speed)
{
    s32 pad[2];
    f32 dist;
    f32 push;
    f32 cam_pos[3];
    f32 offset[3];
    f32 center_pos[3];
    f32 reach;
    f32 rand_y;

    func_800EFA4C(center_pos, center[0], center[1] + height, center[2]);
    func_80111094(camera, cam_pos);
    func_800EFB24(offset, cam_pos, center_pos);
    dist = (offset[0] * offset[0] + offset[1] * offset[1]) + offset[2] * offset[2];
    reach = radius + 80.0f;
    if (!(reach * reach < dist)) {
        dist = sqrtf(dist);
        push = func_800F13F0(func_800D8FF8() * speed, reach - dist);
        // exactly at the centre: push in a random direction
        if (dist == 0.0f) {
            dist = func_800DC0C0();
            rand_y = func_800DC0C0();
            func_800EFA4C(offset, dist, rand_y, func_800DC0C0());
        }
        func_800EF368(offset, push);
        func_800EF04C(cam_pos, offset);
        func_801110C4(camera, cam_pos);
    }
}

// TU-NOTE: the .data of this overlay is defined here in C; values are taken from the ROM.
