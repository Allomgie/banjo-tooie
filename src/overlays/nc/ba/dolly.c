// Dolly camera mode from a camera-database volume (type 3): slides on a horizontal track while
// keeping its distance to the player between limits; the height is fixed from the node.
#include "common.h"

extern void func_801124D0();
extern void func_800EFB24(f32 *, f32 *, f32 *);
extern f32 func_800EEFFC(f32 *);
extern void func_800EFA98(f32 *, f32 *, f32);
extern void func_800EF04C(f32 *, f32 *);
typedef struct {
    u8 pad_0[0xC];
    f32 unk_C[3];
    f32 max_dist;
    f32 min_dist;
    u8 unk_20;
    u8 unk_21;
    u8 pad_22[2];
    f32 unk_24;
    f32 unk_28;
} DollyCameraData;
typedef struct {
    u8 pad_0[0x1C];
    DollyCameraData *data;
} DollyCamera;
extern void func_80111B8C(DollyCamera *, f32, f32);
extern void func_80112570(DollyCamera *, f32 *, f32);

s32 ncbadolly_entrypoint_0()
{
    return 0x2C;
}

void ncbadolly_entrypoint_1(u8 *camera)
{
    (*(u8 **) (camera + 0x1c))[0x21] = 1;
    func_801124D0(camera, 1);
}

void ncbadolly_entrypoint_2(s32 arg0)
{
}

// Per-frame update: slide along the track, keeping distance to the player within limits.
void ncbadolly_entrypoint_3(u8 *camera)
{
    f32 target[3];
    f32 cam_pos[3];
    f32 rotation[3];
    f32 to_track[3];
    f32 track_dist;
    f32 offset[3];
    f32 distance;
    u8 *data;
    if (!(*(u8 **) (camera + 0x1C))[0x21]) {
        func_80112524(camera, target);
        func_801107F0(camera, cam_pos);
        func_800EFB24(offset, cam_pos, target);
        offset[1] = 0.0f;
        distance = func_800EEFFC(offset);
        data = *(u8 **) (camera + 0x1C);
        if (distance < *(f32 *) (data + 0x1C))
            distance = *(f32 *) (data + 0x1C);
        if (*(f32 *) (data + 0x18) < distance)
            distance = *(f32 *) (data + 0x18);
        func_800EFB24(to_track, (f32 *) data, target);
        to_track[1] = 0.0f;
        track_dist = func_800EEFFC(to_track);
        if (track_dist < distance)
            distance = track_dist;
        func_800EFA98(offset, to_track, distance);
        func_800EF04C(offset, target);
        offset[1] = ((f32 *) *(u8 **) (camera + 0x1C))[1];
        func_80111AE0(camera, offset);
        if ((*(u8 **) (camera + 0x1C))[0x20])
            func_8011329C(camera);
        func_80112524(camera, target);
        func_80110A68(camera, rotation, target);
        func_80110790(camera, rotation);
    }
}

// Loads the node parameters from the camera database.
void ncbadolly_entrypoint_4(DollyCamera *camera, s32 node)
{
    f32 unk_0;
    f32 unk_1;
    s32 unk_2;

    func_800A5800(node);
    _cadbfunc_entrypoint_29(1, &unk_2);
    camera->data->unk_20 = unk_2;
    _cadbfunc_entrypoint_4(camera->data->unk_C);
    _cadbfunc_entrypoint_0(camera->data);
    _cadbfunc_entrypoint_6(&unk_0, &unk_1);
    func_80111B8C(camera, unk_0, unk_1);
    _cadbfunc_entrypoint_8(&unk_0, &unk_1);
    camera->data->unk_24 = unk_0;
    camera->data->unk_28 = unk_1;
    _cadbfunc_entrypoint_18(&camera->data->min_dist);
    _cadbfunc_entrypoint_20(&camera->data->max_dist);
    camera->data->unk_21 = 0;
    func_80112570(camera, camera->data->unk_C, 150.0f);
}

// TU-NOTE: the .data of this overlay is defined here in C; values are taken from the ROM.
