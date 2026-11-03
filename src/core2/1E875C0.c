#include "common.h"

// TU-NOTE: bone matrix list layout: {s32 count, s32 capacity, bone-transform handle at +8/+0xC, base matrix at +0x10, then count 0x40-byte matrices at +0x50}.
typedef struct {
    s32 count, capacity;
    u8 pad_8[72];
    f32 mtxs[][4][4];
} local_type;
extern void *heap_realloc(void *, s32);
extern void func_80019CD4(void);
extern void mlMtxGet(f32 (*)[4]);
typedef struct {
    u8 pad[0x40];
} E40;
typedef struct {
    s32 count;
    u8 pad4[0x4C];
    E40 e[1];
} ObjA;
typedef struct {
    u8 pad[0xC];
    s16 id;
    u8 padE[2];
} EntB;
typedef struct {
    u8 pad0[4];
    s16 count;
    u8 pad6[2];
    EntB e[1];
} ObjB;
typedef struct {
    s32 count;
    u8 pad4[0x4C];
    E40 e[1];
} A800ADEC4;
extern void func_800F293C(E40 *, s32);
struct UnkStruct {
    s32 unk0;
};
typedef f32 MatrixAE40C[4][4];
typedef struct {
    s32 count;
    s32 capacity;
    u8 pad[0x48];
    MatrixAE40C mtxs[1];
} BufferAE40C;
typedef struct {
    u8 pad[12];
    s16 id;
    s16 parent;
} BoneAE40C;
typedef struct {
    s16 pad[2];
    s16 count;
    s16 pad_1;
    BoneAE40C bones[1];
} StateAE40C;
extern BufferAE40C *func_8001B710(s16, s32);
extern void func_800DFB7C(s32, s32, f32 *, f32 *, f32 *);
extern void mlMtxSet(f32[4][4]);
extern s32 func_800D9C4C(f32 *);
extern void func_800D9CE8(f32 *, f32[3][3]);
extern void func_80019BB8(f32[3][3]);
extern void mlMtxScale_xyz(f32, f32, f32);
struct UnkStruct *func_800AE080(s16);

// Resizes the list to the skeleton's bone count.
void func_800ADCD0(local_type **list_ptr, s16 *skeleton)
{
    local_type *list;
    f32(*mtx)[4][4];
    f32(*mtx_end)[4][4];
    list = *list_ptr;
    if (list->capacity < skeleton[2]) {
        list = heap_realloc(list, skeleton[2] * 64 + 0x50);
        list->capacity = skeleton[2];
        *list_ptr = list;
    }
    list->count = skeleton[2];
    mtx_end = list->count + list->mtxs;
    func_80019CD4();
    for (mtx = list->mtxs; mtx < mtx_end; mtx++)
        mlMtxGet(*mtx);
}

void func_800ADD80(s16 handle, s16 *skeleton)
{
    local_type *list;
    f32(*mtx)[4][4];
    f32(*mtx_end)[4][4];
    list = func_800AE080(handle);
    if (list->capacity < skeleton[2]) {
        list = func_8001B710(handle, skeleton[2] * 64 + 0x50);
        list->capacity = skeleton[2];
    }
    list->count = skeleton[2];
    mtx_end = list->count + list->mtxs;
    func_80019CD4();
    for (mtx = list->mtxs; mtx < mtx_end; mtx++)
        mlMtxGet(*mtx);
}

// Returns the base matrix for bone -1, else the matrix of the bone.
int func_800ADE2C(s32 list, s32 bone)
{
    long offset;
    s32 bone_copy;
    if (bone == -1) {
        return list + 0x10;
    }
    {
        bone_copy = bone;
        offset = bone_copy * 0x40;
        return (list + offset) + 0x50;
    }
}

// Returns the matrix of the bone with bone_id, or 0.
int func_800ADE50(ObjA *list, ObjB *skeleton, s32 bone_id)
{
    EntB *bone;
    E40 *mtx;
    bone = skeleton->e;
    if (skeleton->count != list->count) {
        return 0;
    }
    for (mtx = list->e; mtx < list->count + list->e; mtx++, bone++) {
        if (bone_id == bone->id) {
            return (int) mtx;
        }
    }
    return 0;
}

// Calls func_800F293C on the matrix whose skeleton bone has bone_id.
void func_800ADEC4(A800ADEC4 *list, u8 *skeleton, s32 bone_id, s32 param_3)
{
    E40 *mtx;
    E40 *mtx_end;
    u8 *bone;
    bone = skeleton + 8;
    if (list->count == *(s16 *) (skeleton + 4)) {
        mtx = list->e;
        mtx_end = (E40 *) (list->count * 0x40 + (u8 *) list + 0x50);
        for (; mtx < mtx_end; mtx++, bone += 0x10) {
            if (bone_id == *(s16 *) (bone + 0xC)) {
                func_800F293C(mtx, param_3);
            }
        }
    }
}

// Frees the bone-transform list, then the matrix list.
int func_800ADF5C(Actor *list)
{
    s32 bones = *(s32 *) ((char *) list + 0x8);
    s32 list_addr;
    if (bones != 0) {
        list_addr = (s32) list;
        // Matching: the repeated masks are needed for the match.
        func_800E0A50((Actor *) ((((bones & 0xFFFFFFFFFFFFFFFF) & 0xFFFFFFFFFFFFFFFF) &
                                  0xFFFFFFFFFFFFFFFF) &
                                 0xFFFFFFFFFFFFFFFF),
                      (Actor *) bones, (Actor *) list_addr);
    }
    heap_free((void *) list);
}

// Allocates an empty matrix list with the current matrix as base.
u8 *func_800ADF98(void)
{
    u8 *list;

    list = heap_alloc(0x50);
    *(s32 *) ((s8 *) list + 0) = 0;
    *(s32 *) ((s8 *) list + 4) = 0;
    *(s32 *) ((s8 *) list + 8) = 0;
    *(s16 *) ((s8 *) list + 0xC) = 0;
    func_80019CD4();
    mlMtxGet(list + 0x10);
    return list;
}

int func_800ADFE0(handle)
s16 handle;
{
    s16 *list;
    list = func_800AE080(handle);
    if (list[6] != 0) {
        func_800E0A70(list[6]);
    }
    func_8001B754(handle);
}

// Handle variant of func_800ADF98.
s16 func_800AE020(void)
{
    s16 handle;
    Mtx *list;

    handle = func_8001B668(0, 0x50);
    list = func_800AE080(handle);
    list->m[0][0] = 0;
    *(s32 *) ((char *) list + 4) = 0;
    *(s32 *) ((char *) list + 8) = 0;
    *(s16 *) ((char *) list + 0xC) = 0;
    func_80019CD4();
    mlMtxGet((char *) list + 0x10);
    return handle;
}

struct UnkStruct *func_800AE080(s16 handle)
{
    if (handle == 0) {
        return 0;
    }
    {
        return func_8001B798(handle);
    }
}

func_800AE0B8(param_0) s32 *param_0;
{

if (param_0 != NULL) {
    return param_0[0];
} else {

return 1;
}
}

func_800AE0D0(s32 *param_0)
{
    if (param_0 != NULL) {
        return param_0[0];
    } else {
        return 0;
    }
}

int func_800AE0E8(handle)
s16 handle;
{
    if (handle != 0) {
        return func_800AE080(handle)->unk0;
    }
    return 1;
}

int func_800AE124(handle)
s16 handle;
{
    if (handle != 0) {
        return func_800AE080(handle)->unk0;
    }
    return 0;
}

void func_800AE160(u8 **list_ptr, u8 *skeleton, s32 param_2)
{
    s16 count;
    u8 *new_list;
    u8 *list;

    list = *list_ptr;
    count = (*(s16 *) ((s8 *) (skeleton) + 4));
    if ((*(s32 *) ((s8 *) (list) + 4)) < count) {
        new_list = heap_realloc(list, (count << 6) + 0x50);
        list = new_list;
        (*(s32 *) ((s8 *) (new_list) + 4)) = (s32) (*(s16 *) ((s8 *) (skeleton) + 4));
        *list_ptr = new_list;
        count = (*(s16 *) ((s8 *) (skeleton) + 4));
    }
    (*(s32 *) ((s8 *) (list) + 0)) = (s32) count;
    func_800AE820(param_2, skeleton, list + 0x50, (*(s32 *) ((s8 *) (list) + 8)));
}

void func_800AE1E8(s16 handle, u8 *skeleton, s32 param_2)
{
    u8 *list_copy;
    // Matching: extra temporaries needed for the match.
    int size_copy;
    s16 count;
    u8 *list;
    int size;
    s8 *count_ptr;
    list = func_800AE080(handle);
    list_copy = list;
    count = *((s16 *) (((s8 *) skeleton) + 4));
    size = (count << 6) + 0x50;
    if ((*((s32 *) (((s8 *) list) + 4))) < count) {
        count_ptr = ((s8 *) skeleton) + 4;
        size_copy = size;
        list = func_8001B710(handle, size_copy);
        list_copy = list;
        *((s32 *) (((s8 *) list) + 4)) = (s32) (*((s16 *) count_ptr));
        count = *((s16 *) (((s8 *) skeleton) + 4));
    }
    *((s32 *) (((s8 *) list) + 0)) = (s32) count;
    func_800AE820(param_2, skeleton, list_copy + 0x50,
                  ((*((s16 *) (((s8 *) list) + 0xC))) != 0)
                      ? (func_800E0A28(*((s16 *) (((s8 *) list_copy) + 0xC))))
                      : (0));
}

// Builds the per-bone matrices from the skeleton and pose.
void func_800AE290(handle, skeleton, param_2) s16 handle;
StateAE40C *skeleton;
s32 param_2;
{
    BufferAE40C *list;
    MatrixAE40C *base;
    f32 rot[3][3];
    f32 quat[4];
    f32 scale[3];
    f32 trans[3];
    MatrixAE40C *mtx;
    MatrixAE40C *mtx_end;
    BoneAE40C *bone;
    list = func_800AE080(handle);
    if (list->capacity < skeleton->count) {
        list = func_8001B710(handle, skeleton->count * 64 + 0x50);
        list->capacity = skeleton->count;
    }
    list->count = skeleton->count;
    mtx_end = list->count + list->mtxs;
    mtx = list->mtxs;
    for (bone = skeleton->bones; mtx < mtx_end; mtx++, bone++) {
        func_800DFB7C(param_2, bone->id, quat, scale, trans);
        base = list->mtxs;
        if (bone->parent == -1)
            func_80019CD4();
        else if (bone->parent + 1 != mtx - base)
            mlMtxSet(*(MatrixAE40C *) ((bone->parent << 6) + (u8 *) base));

if (!func_800D9C4C(quat)) {
    func_800D9CE8(quat, rot);
    func_80019BB8(rot);
}

mlMtxGet(*mtx);
}
}

// Like func_800AE290, with the pose scale applied as well.
void func_800AE40C(handle, skeleton, param_2) s16 handle;
StateAE40C *skeleton;
s32 param_2;
{
    BufferAE40C *list;
    MatrixAE40C *base;
    f32 rot[3][3];
    f32 quat[4];
    f32 scale[3];
    f32 trans[3];
    MatrixAE40C *mtx;
    MatrixAE40C *mtx_end;
    BoneAE40C *bone;
    list = func_800AE080(handle);
    if (list->capacity < skeleton->count) {
        list = func_8001B710(handle, skeleton->count * 64 + 0x50);
        list->capacity = skeleton->count;
    }
    list->count = skeleton->count;
    mtx_end = list->count + list->mtxs;
    mtx = list->mtxs;
    for (bone = skeleton->bones; mtx < mtx_end; mtx++, bone++) {
        func_800DFB7C(param_2, bone->id, quat, scale, trans);
        base = list->mtxs;
        if (bone->parent == -1)
            func_80019CD4();
        else if (bone->parent + 1 != mtx - base)
            mlMtxSet(*(MatrixAE40C *) ((bone->parent << 6) + (u8 *) base));

if (!func_800D9C4C(quat)) {
    func_800D9CE8(quat, rot);
    func_80019BB8(rot);
}

mlMtxScale_xyz(scale[0], scale[1], scale[2]);
mlMtxGet(*mtx);
}
}

void func_800AE598(s32 *list, s32 *dst_cursor)
{
    s32 src;
    s32 dst;
    src = (s32) (list + 4);
    dst = *dst_cursor;
    func_80116684((s32 *) src, dst, *list + 1, list);
    *dst_cursor += (*list + 1) << 6;
}

void func_800AE5F0(void *list)
{
    void *bones;
    bones = *(void **) ((char *) list + 8);
    if (bones != 0) {
        *(void **) ((char *) list + 8) = func_800E0A98(bones, list);
    }
    defrag(list);
}

s32 func_800AE630(s32 *list, u8 *skeleton, s32 bone_id, s32 param_3)
{
    s32 list_addr;
    u8 *bone;
    u8 *mtx;
    u8 *mtx_end;

    list_addr = (s32) list;
    bone = skeleton + 8;
    if (list[0] != (*((s16 *) (skeleton + 4)))) {
        return 0;

}
mtx = ((u8 *) list_addr) + 0x50;
mtx_end = (u8 *) ((list[0] << 6) + list_addr + 0x50);

if (((u32) mtx) < ((u32) mtx_end)) {
loop_3:
    if (bone_id == *(s16 *) (bone + 12)) {
        func_800F23D0((u32) mtx, param_3, bone);
        return 1;
    }

mtx += 0x40;
bone += 0x10;

if ((u32) mtx >= (u32) mtx_end) {
    {
        goto block_6;
    }
}

goto loop_3;
}
block_6 : return 0;
}

s32 func_800AE6BC(u8 *list)
{
    s16 bones_handle;
    // Matching: extra temporary needed for the match.
    if ((*((s16 *) (((s8 *) list) + 0xC))) != 0) {
        bones_handle = *((s16 *) (((s8 *) list) + 0xC));
        return func_800E0A28(bones_handle, *((s16 *) (((s8 *) list) + 0xC)));
    }
    return *((s32 *) (((s8 *) list) + 0x8));
}

void func_800AE6FC(param_0, param_1) s32 param_0;
s16 param_1;
{
    *(s16 *) (param_0 + 0xc) = param_1;
}

s32 func_800AE708(s32 list, u8 *param_1, s32 *param_2, u8 *param_3)
{
    s32 found;
    s32 dst_mtx;
    u8 *bones_end;
    u8 *bone;

    if (func_800AE0B8() == 0) {
        return 0;
    }
    if ((*(s16 *) ((s8 *) (param_1) + (4))) < (*(s16 *) ((s8 *) (param_3) + (4)))) {
        return 0;
    }
    if ((*(f32 *) ((s8 *) (param_3) + (0))) != (*(f32 *) ((s8 *) (param_1) + (0)))) {
        return 0;
    }
    func_800ADCD0(param_2, param_3);
    bone = param_3 + 8;
    bones_end = ((*(s16 *) ((s8 *) (param_3) + (4))) * 0x10) + param_3 + 8;
    dst_mtx = *param_2 + 0x50;
    if ((u32) bone < (u32) bones_end) {
    loop_7:
        found = func_800ADE50(list, param_1, (*(s16 *) ((s8 *) (bone) + (0xC))));

if (found == 0) {
    return 0;
}

func_800F293C(dst_mtx, found);
bone += 0x10;
dst_mtx += 0x40;

if ((u32) bone >= (u32) bones_end) {
    goto block_10;
}

goto loop_7;
}
block_10 : return 1;
}
