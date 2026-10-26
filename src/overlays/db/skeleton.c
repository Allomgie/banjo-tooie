#include "common.h"

typedef struct { f32 local_0[3]; s16 local_1; s16 local_2; } DbSkeletonJoint;
typedef struct { u8 pad_0[4]; s16 local_0; s16 local_1; DbSkeletonJoint local_2[1]; } DbSkeleton;
extern void func_800EE7F8(f32 *, f32 *);
extern void func_800EFD24(f32 *);
typedef struct { u8 pad[0xC]; s16 id; s16 pad2; } SkEnt;
typedef struct { u8 pad[4]; s16 count; s16 pad6; SkEnt ents[1]; } SkHdr;

int dbskeleton_entrypoint_0(s16 *param_0)
{
  return param_0[2];
}

f32 dbskeleton_entrypoint_1(s32 param_0) {
    return *(f32 *)param_0;
}

s32 dbskeleton_entrypoint_2(DbSkeleton *param_0, s32 param_1, f32 *param_2)
{
    DbSkeletonJoint *local_0;
    DbSkeletonJoint *local_1;
    local_0 = param_0->local_2;
    local_1 = (DbSkeletonJoint *)(param_0->local_0 * sizeof(DbSkeletonJoint) + (u8 *)param_0 + 8);
    for (; local_0 < local_1; local_0++) {
        if (param_1 == local_0->local_1) {
            func_800EE7F8(param_2, local_0->local_0);
            return 1;
        }
    }
    func_800EFD24(param_2);
    return 0;
}

s32 dbskeleton_entrypoint_3(SkHdr *param_0, s32 param_1) {
    SkEnt *local_1 = param_0->ents;
    SkEnt *local_0;
    for (local_0 = local_1; local_0 < local_1 + param_0->count; local_0++) {
        if (param_1 == local_0->id) {
            return 1;
        }
    }
    return 0;
}

s16 dbskeleton_entrypoint_4(u8 *param_0, int param_1)
{
  return *(s16 *)((u8 *)param_0 + (param_1 << 4) + 20);
}
