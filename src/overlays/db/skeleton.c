#include "common.h"

// Model skeleton section: f32 scale at +0, joint count at +4, 16-byte joints from +8.
typedef struct {
    f32 pos[3];
    s16 bone_id;
    s16 parent;
} DbSkeletonJoint;
typedef struct {
    u8 pad_0[4];
    s16 joint_count;
    s16 unk_6;
    DbSkeletonJoint joints[1];
} DbSkeleton;
extern void func_800EE7F8(f32 *, f32 *);
extern void func_800EFD24(f32 *);

typedef struct {
    u8 pad_0[0xC];
    s16 id;
    s16 pad_E;
} SkEnt;
typedef struct {
    u8 pad_0[4];
    s16 count;
    s16 pad_6;
    SkEnt ents[1];
} SkHdr;

// Bone count.
int dbskeleton_entrypoint_0(s16 *skeleton)
{
    return skeleton[2];
}

// Skeleton scale.
f32 dbskeleton_entrypoint_1(s32 skeleton)
{
    return *(f32 *) skeleton;
}

// Copy the position of bone_id to out_pos; zero it and return 0 if the bone does not exist.
s32 dbskeleton_entrypoint_2(DbSkeleton *skeleton, s32 bone_id, f32 *out_pos)
{
    DbSkeletonJoint *joint;
    DbSkeletonJoint *end;
    joint = skeleton->joints;
    end = (DbSkeletonJoint *) (skeleton->joint_count * sizeof(DbSkeletonJoint) + (u8 *) skeleton + 8);
    for (; joint < end; joint++) {
        if (bone_id == joint->bone_id) {
            func_800EE7F8(out_pos, joint->pos);
            return 1;
        }
    }
    func_800EFD24(out_pos);
    return 0;
}

// Does bone_id exist?
s32 dbskeleton_entrypoint_3(SkHdr *skeleton, s32 bone_id)
{
    SkEnt *first = skeleton->ents;
    SkEnt *ent;
    for (ent = first; ent < first + skeleton->count; ent++) {
        if (bone_id == ent->id) {
            return 1;
        }
    }
    return 0;
}

// Parent index of joint n.
s16 dbskeleton_entrypoint_4(u8 *skeleton, int n)
{
    return *(s16 *) ((u8 *) skeleton + (n << 4) + 20);
}
