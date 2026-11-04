// This seems to be the string (leash) camera mode: it keeps the entry distance as min and max,
// follows the player with waypoint support, and reacts to obstruction only beyond 1.5x min.
#include "nc/ba/string.h"

extern f32 _ncbawaypoint_entrypoint_3(void *, f32 *, f32 *);
extern f32 func_800EEF94(f32 *);
extern f32 func_80115358(void *, f32);
extern f32 func_80115750(void *, f32);
extern f32 func_80112C3C(void *, f32);
extern f32 func_800EEAD4(f32 *, f32 *);
extern void func_800EEBF0(f32 *, f32 *, f32);

typedef struct {
    f32 min_dist;
    f32 max_dist;
    u8 unk_8;
} StringCameraLimits;
typedef struct {
    u8 pad_0[0x50];
    StringCameraLimits *limits;
} StringCameraNode;

s32 ncbastring_entrypoint_0()
{
    return 0xC;
}

void func_80800008_ncbastring(PlayerState *cam, f32 *focus)
{
    func_80112524(cam, focus);
}

int ncbastring_entrypoint_1(Actor *cam)
{
    func_80111B8C(cam, 0x40800000, 0x41000000);
    func_801124D0(cam, 1);
    func_80115858(cam, 1);
    func_80115870(cam, 0x40A00000);
}

void ncbastring_entrypoint_2(s32 cam)
{
}

void func_8080007C_ncbastring(PlayerState *cam, f32 *focus)
{
    func_80112550(cam, focus);
}

void ncbastring_entrypoint_3(void *cam)
{
    f32 focus[3];
    f32 offset[3];
    f32 cam_pos[3];
    f32 cam_rot[3];
    f32 dist;
    f32 waypoint_dist;
    f32 total_dist;
    f32 angles[2];
    f32 unk_0;
    f32 unk_1;

    func_8080007C_ncbastring(cam, focus);
    func_801107F0(cam, cam_pos);
    if (**(s32 **) ((u8 *) cam + 0x5C)) {
        waypoint_dist = _ncbawaypoint_entrypoint_3(cam, focus, cam_pos);
    } else {
        waypoint_dist = 0.0f;
    }
    func_800EFB24(offset, cam_pos, focus);
    total_dist = func_800EEF94(offset) + waypoint_dist;
    func_800F1A88(offset, angles);
    if (waypoint_dist == 0.0f) {
        func_80113978(cam, 1, 0);
    }
    dist = func_80115358(cam, total_dist);
    angles[0] = func_80115750(cam, angles[0]);
    angles[1] = func_80112C3C(cam, angles[1]);
    dist -= waypoint_dist;
    func_800EEBF0(offset, angles, dist);
    func_800EE780(cam_pos, focus, offset);
    if (func_80111CC8(cam, cam_pos)) {
        if (!func_801138A0(cam)) {
            func_80115444(cam, &unk_0, &unk_1);
            func_801107F0(cam, cam_pos);
            dist = func_800EEAD4(cam_pos, focus);
            if (unk_1 * 1.5f < total_dist && unk_1 * 1.5f < dist && func_801138F4(cam)) {
                func_80110F44(cam);
            }
        } else if (func_801138F4(cam)) {
            func_80110F44(cam);
        }
    }
    func_80800008_ncbastring(cam, focus);
    func_80110A68(cam, cam_rot, focus);
    func_80110790(cam, cam_rot);
}

// On entry the current distance becomes both min and max, as if on a string.
void ncbastring_entrypoint_4(StringCameraNode *cam)
{
    f32 focus[3];
    f32 cam_pos[3];
    f32 offset[3];
    f32 unk_0;
    f32 unk_1;
    f32 dist;
    func_8080007C_ncbastring(cam, focus);
    func_801107F0(cam, cam_pos);
    func_800EFB24(offset, cam_pos, focus);
    dist = func_800EEF94(offset);
    cam->limits->max_dist = dist;
    cam->limits->min_dist = dist;
    func_80115444(cam, &unk_0, &unk_1);
    if (cam->limits->min_dist < unk_0) {
        cam->limits->unk_8 = 1;
        cam->limits->max_dist = unk_1;
    } else if (unk_1 < cam->limits->max_dist) {
        cam->limits->unk_8 = 1;
        cam->limits->min_dist = unk_0;
    } else
        cam->limits->unk_8 = 0;
}
