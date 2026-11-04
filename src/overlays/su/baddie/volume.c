// Random points on an actor's hit volumes: picks N points on the surfaces of its model-defined
// boxes, cylinders and spheres, falling back to its bounding sphere.
#include "common.h"

typedef struct {
    s16 box_count;
    s16 cylinder_count;
    s16 sphere_count;
    s16 pad_6;
} VolumeHeader;
typedef struct {
    s16 min[3];
    s16 max[3];
    s16 position[3];
    u8 rotation[3];
    u8 pad_15;
    s8 bone;
    u8 pad_17;
} VolumeBox;
typedef struct {
    s16 radius;
    s16 height;
    s16 position[3];
    u8 rotation[3];
    u8 pad_D;
    s8 bone;
    u8 pad_F;
} VolumeCylinder;
typedef struct {
    s16 radius;
    s16 position[3];
    u8 pad_8;
    s8 bone;
    u8 pad_A[2];
} VolumeSphere;
extern void *func_80103D98(void *);
extern void *func_801040A8(Actor *);
extern f32 func_80103F38(Actor *, f32 *);
extern f32 *func_801027F4(Actor *);
extern void *func_800ADE2C(void *, s32);
extern void func_80019AA0(void *, void *);
extern void func_80019750(f32 *, f32 *, f32, void *);
extern void func_80019994(f32 *, f32 *);
extern void func_800198D4(f32 *, f32 *);
extern void func_800EE88C();
extern void func_800EEC30(f32 *, f32, f32, f32);
extern void func_800EEB9C(f32 *, f32, f32);
extern void func_800EF04C(f32 *, f32 *);
extern void func_80019224(f32 *, f32 *);
extern f32 func_800DC178(f32, f32);
extern s32 func_800DC298(f32);
extern s32 func_800DC128(s32, s32);
extern s32 func_800F1418(s32, s32);
extern void mlMtxGet(void *);
extern void mlMtxPop(void);
extern void mlMtxTranslate(f32, f32, f32);

// Writes up to `count` random points on the surfaces of the actor's model volumes
// (boxes, cylinders, spheres), `per_volume` points each. `cursor` keeps the next volume
// between calls. Returns the number of points written.
s32 subaddievolume_entrypoint_0(Actor *actor, f32 (*points)[3], s32 per_volume, s32 count,
                                s32 *cursor)
{
    f32 pose[4][4];
    s32 i;
    s32 j;
    void *bones;
    VolumeHeader *header;
    VolumeBox *boxes;
    VolumeCylinder *cylinders;
    VolumeSphere *spheres;
    s32 volume_index;
    s32 volume_count;
    f32 center[3];
    VolumeBox *box;
    s32 k;
    f32 box_pos[3];
    f32 box_rot[3];
    s32 fixed_axis;
    VolumeCylinder *cylinder;
    f32 radius;
    f32 cyl_pos[3];
    f32 cyl_rot[3];
    VolumeSphere *sphere;
    f32 sph_pos[3];
    s32 fallback_count;

    if (actor == 0) {
        return 0;
    }
    if (!actor->unk7C_12) {
        return -1;
    }

    header = func_80103D98(actor->unk0);
    bones = func_801040A8(actor);
    // No volume data: use random points on the bounding sphere.
    if (bones == 0 || header == 0) {
        fallback_count = func_800F1418(per_volume * 3, count);
        radius = func_80103F38(actor, center);
        for (i = 0; i < fallback_count; i++) {
            func_800EEC30(points[i], func_800DC178(0.0f, 359.0f),
                          func_800DC178(0.0f, 359.0f), radius);
            func_800EF04C(points[i], center);
        }
        return fallback_count;
    }

    // Volumes are stored back to back after the header: boxes, cylinders, spheres.
    boxes = (VolumeBox *) (header + 1);
    cylinders = (VolumeCylinder *) (boxes + header->box_count);
    spheres = (VolumeSphere *) (cylinders + header->cylinder_count);
    volume_count = header->box_count + header->cylinder_count + header->sphere_count;
    volume_index = cursor ? *cursor : 0;
    if (volume_index >= volume_count) {
        volume_index = 0;
    }
    func_80019CD4();
    func_80019750(actor->position, func_801027F4(actor), actor->scale, 0);
    mlMtxGet(pose);

    for (i = 0; i < count;) {
        if (cursor) {
            *cursor = volume_index + 1;
        }
        if (volume_index < header->box_count) {
            // Box: random point inside, then snapped to one of the two faces on a random axis.
            box = &boxes[header->box_count - volume_index - 1];
            for (j = 0; j < per_volume; j++) {
                func_800EE88C(box_pos, box->position);
                box_rot[0] = (f32) (u32) box->rotation[0] * 2.0f;
                box_rot[1] = (f32) (u32) box->rotation[1] * 2.0f;
                box_rot[2] = (f32) (u32) box->rotation[2] * 2.0f;
                func_80019AA0(pose, func_800ADE2C(bones, box->bone));
                func_80019994(box_pos, box_rot);
                for (k = 0; k != 3; k++) {
                    points[i][k] =
                        func_800DC178(box->min[k], box->max[k]);
                }
                fixed_axis = func_800DC128(0, 3);
                if (func_800DC298(0.5f)) {
                    points[i][fixed_axis] = box->min[fixed_axis];
                } else {
                    points[i][fixed_axis] = box->max[fixed_axis];
                }
                func_80019224(points[i], points[i]);
                i++;
                if (i >= count) {
                    return i;
                }
                mlMtxPop();
            }
        } else if (volume_index < header->box_count + header->cylinder_count) {
            // Cylinder: random angle on the radius, random height.
            cylinder = &cylinders[header->box_count + header->cylinder_count - volume_index - 1];
            for (j = 0; j < per_volume; j++) {
                func_800EE88C(cyl_pos, cylinder->position);
                cyl_rot[0] = (f32) (u32) cylinder->rotation[0] * 2.0f;
                cyl_rot[1] = (f32) (u32) cylinder->rotation[1] * 2.0f;
                cyl_rot[2] = (f32) (u32) cylinder->rotation[2] * 2.0f;
                cyl_rot[0] += 90.0f;
                func_80019AA0(pose, func_800ADE2C(bones, cylinder->bone));
                func_800198D4(cyl_pos, cyl_rot);
                func_800EEB9C(points[i], func_800DC178(0.0f, 359.0f), cylinder->radius);
                points[i][1] =
                    func_800DC178(cylinder->height * -0.5f, cylinder->height * 0.5f);
                func_80019224(points[i], points[i]);
                i++;
                if (i >= count) {
                    return i;
                }
                mlMtxPop();
            }
        } else {
            // Sphere: random direction at the sphere radius.
            sphere = &spheres[volume_count - volume_index - 1];
            for (j = 0; j < per_volume; j++) {
                func_800EE88C(sph_pos, sphere->position);
                func_80019AA0(pose, func_800ADE2C(bones, sphere->bone));
                mlMtxTranslate(sph_pos[0], sph_pos[1], sph_pos[2]);
                func_800EEC30(points[i], func_800DC178(0.0f, 359.0f),
                              func_800DC178(0.0f, 359.0f), sphere->radius);
                func_80019224(points[i], points[i]);
                i++;
                if (i >= count) {
                    return i;
                }
                mlMtxPop();
            }
        }
        volume_index++;
        if (volume_index >= volume_count) {
            volume_index = 0;
        }
    }
    return i;
}

// TU-NOTE: the .data of this overlay (formerly asm/data/overlays/su/baddie/volume.data.s) is defined in C, with values taken from the ROM.
