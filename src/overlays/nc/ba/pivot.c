#include "nc/ba/pivot.h"

extern f32 _ncbawaypoint_entrypoint_3(void *, Vec3f *, Vec3f *);
extern f32 func_800EEF94(Vec3f *);
extern f32 func_80115358(void *, f32);
extern f32 func_80115750(void *, f32);
extern f32 func_80112C3C(void *, f32);
extern f32 func_801125E8(void *);
extern void func_800EEBF0(Vec3f *, f32 *, f32);

s32 ncbapivot_entrypoint_0()
{
    return 0x4;
}

void func_80800008_ncbapivot(PlayerState *arg0, f32 *arg1)
{
    func_80112524(arg0, arg1);
}

int ncbapivot_entrypoint_1(s32 cam_arg)
{
    s32 cam;
    // Matching: `| 0` copies the parameter into a local for the match.
    cam = cam_arg | 0;
    func_801120CC(cam, 0x44FA0000, 0x457A0000, 0xC57A0000);
    func_80111B8C(cam, 0x40800000, 0x41000000);
    func_801124D0(cam, 1);
    func_80115858(cam, 1);
    func_80115870(cam, 0x40A00000);
}

void ncbapivot_entrypoint_2(s32 arg0)
{
}

// Orbit camera with a yaw offset; routes the view through the waypoints when there are any.
void ncbapivot_entrypoint_3(u8 *cam)
{
    Vec3f target;
    Vec3f rot;
    Vec3f offset;
    Vec3f pos;
    f32 dist;
    f32 waypoint_dist;
    f32 total_dist;
    f32 angles[2];
    Vec3f look_at;

    func_8011607C(cam, 1);
    func_80113978(cam, 1, 0);
    func_80800008_ncbapivot(cam, &target);
    func_801107F0(cam, &pos);
    func_800EE7F8(&look_at, &target);
    if (**(s32 **) (cam + 0x5C)) {
        waypoint_dist = _ncbawaypoint_entrypoint_3(cam, &look_at, &pos);
    } else {
        waypoint_dist = 0.0f;
    }
    func_800EFB24(&offset, &pos, &look_at);
    total_dist = func_800EEF94(&offset) + waypoint_dist;
    func_800F1A88(&offset, angles);
    dist = func_80115358(cam, total_dist);
    angles[0] = func_80115750(cam, angles[0]);
    angles[1] = func_80112C3C(cam, angles[1]);
    angles[1] += func_801125E8(cam);
    dist -= waypoint_dist;
    func_800EEBF0(&offset, angles, dist);
    func_800EE780(&pos, &look_at, &offset);
    if (func_80111FD4(cam, &pos)) {
        if (func_801138A0(cam)) {
            if (func_801138F4(cam)) {
                func_80110F44(cam);
            }
        } else if (func_80115580(cam, &look_at) || func_80115580(cam, &target)) {
            if (func_801138F4(cam)) {
                func_80110F44(cam);
            }
        }
    }
    func_80110A68(cam, &rot, &target);
    func_80110790(cam, &rot);
    if (waypoint_dist != 0.0f) {
        func_80111310(cam);
    }
}

// TU-NOTE: the overlay .data (formerly asm/data/overlays/nc/ba/pivot.data.s) is defined in C; values come from the ROM.
