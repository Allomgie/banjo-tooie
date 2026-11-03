#include "core2/1EB93C0.h"

void func_800D9600(s32, s32);
s32 func_800D97E8(void *param_0, void *param_1);
void func_800D9AD4(s32 param_0, void *param_1, void *param_2, f32 param_3);

// Bone pose: {s32 bones; s32 count; bone data[109]}, 0x28 bytes per bone:
// quaternion rotation (0x00), scale vec3 (0x10), translation vec3 (0x1C).

// Resets every bone to identity: rotation (0,0,0,1), scale (1,1,1), translation (0,0,0).
void func_800DFAD0(u8 *pose)
{
    u32 end;
    u32 bone;

    bone = *(u32 *) ((s8 *) pose + 0);
    end = (*(s32 *) ((s8 *) pose + 4) * 0x28) + bone;
    if (bone < end) {
        do {
            bone += 0x28;
            *(f32 *) (bone - 0x28) = *(f32 *) (bone - 0x24) = *(f32 *) (bone - 0x20) = 0.0f;
            *(f32 *) (bone - 0x1C) = 1.0f;
            *(f32 *) (bone - 0x18) = *(f32 *) (bone - 0x14) = *(f32 *) (bone - 0x10) =
                (f32) 1;
            *(f32 *) (bone - 0xC) = *(f32 *) (bone - 0x8) = *(f32 *) (bone - 0x4) = 0.0f;
        } while (bone < end);
    }
}

// Copies the rotation of a bone to out.
void func_800DFB40(s32 pose, s32 index, s32 out)
{
    s32 *pose_ptr;
    pose_ptr = (s32 *) pose;
    func_800D9600(out, *pose_ptr + index * 40);
}

// Copies rotation, scale and translation of a bone to the three outputs.
void func_800DFB7C(s32 *pose, unsigned int index, unsigned long rotation_out, s32 scale_out,
                   s32 translation_out)
{
    volatile s32 unk_0; // Matching: unused volatile local, needed for the match.
    s32 bone;
    s32 bone_copy;
    s32 base_or_out; // Matching: reused for the pose base and the translation output.
    base_or_out = *pose;
    bone = base_or_out + ((10 * index) * 4);
    func_800D9600(rotation_out, bone);
    base_or_out = translation_out;
    bone_copy = bone;
    func_800EE7F8(scale_out, bone_copy + 0x10);
    func_800EE7F8(base_or_out, bone + 0x1C);
}

// Copies the scale of a bone to out.
void func_800DFBE0(s32 *pose, s32 index, s32 out)
{
    func_800EE7F8(out, *pose + (index * 0x28) + 0x10, out, pose);
}

// Copies the translation of a bone to out.
void func_800DFC20(s32 *pose, s32 index, s32 out)
{
    func_800EE7F8(out, *pose + (index * 0x28) + 0x1C, out, pose);
}

void func_800DFC60(void *pose)
{
    heap_free(pose);
}

// Allocates an identity pose on the heap.
int func_800DFC80()
{
    s32 *pose;
    pose = heap_alloc(0x1110);
    pose[0] = &pose[2];
    pose[1] = 0x6D;
    func_800DFAD0(pose);
    return pose;
}

int func_800DFCC0(handle)
s16 handle;
{
    func_8001B754(handle);
}

int func_800DFCE8(handle)
s16 handle;
{
    func_8001B798(handle);
}

// Allocates an identity pose through the handle table and returns its handle.
s16 func_800DFD10(void)
{
    s16 handle;
    u8 *pose;

    handle = func_8001B668(1, 0x1110);
    pose = func_8001B798(handle);
    *(s32 *) ((s8 *) pose + 0) = (s32) (pose + 8);
    *(s32 *) ((s8 *) pose + 4) = 0x6D;
    func_800DFAD0(pose);
    return handle;
}

// Blends two poses into dst: slerp rotation, lerp scale and translation.
void func_800DFD64(void *dst, void **pose_a, void **pose_b, f32 blend)
{
    u32 dst_bone;
    u8 *bone_a, *bone_b;
    s32 dst_end;

    dst_bone = *(u32 *) dst;
    dst_end = ((s32) *((u32 *) dst + 1) * 40) + dst_bone;
    bone_a = *(u8 **) pose_a;
    bone_b = *(u8 **) pose_b;

    if (dst_bone < dst_end) {
        do {
            if (func_800D97E8(bone_a, bone_b)) {
                func_800D9600(dst_bone, bone_a);
            } else {
                func_800D9AD4(dst_bone, bone_a, bone_b, blend);
            }
            dst_bone += 0x28;
            *(f32 *) (dst_bone - 0x18) =
                *(f32 *) (bone_a + 0x10) +
                (*(f32 *) (bone_b + 0x10) - *(f32 *) (bone_a + 0x10)) * blend;
            bone_a += 0x28;
            bone_b += 0x28;
            *(f32 *) (dst_bone - 0x14) =
                *(f32 *) (bone_a - 0x14) +
                (*(f32 *) (bone_b - 0x14) - *(f32 *) (bone_a - 0x14)) * blend;
            *(f32 *) (dst_bone - 0x10) =
                *(f32 *) (bone_a - 0x10) +
                (*(f32 *) (bone_b - 0x10) - *(f32 *) (bone_a - 0x10)) * blend;
            *(f32 *) (dst_bone - 0xC) = *(f32 *) (bone_a - 0xC) +
                                      (*(f32 *) (bone_b - 0xC) - *(f32 *) (bone_a - 0xC)) * blend;
            *(f32 *) (dst_bone - 8) =
                *(f32 *) (bone_a - 8) + (*(f32 *) (bone_b - 8) - *(f32 *) (bone_a - 8)) * blend;
            *(f32 *) (dst_bone - 4) =
                *(f32 *) (bone_a - 4) + (*(f32 *) (bone_b - 4) - *(f32 *) (bone_a - 4)) * blend;
        } while (dst_bone < dst_end);
    }
}

// Copies all bones of src to *dst.
void func_800DFEA8(u8 *src, s32 *dst)
{
    int scale_offset; // Matching: holds 0x10 in a register.
    s32 dst_bone;
    u32 src_end;
    u32 src_bone;
    src_bone = *(u32 *) src;
    dst_bone = *dst;
    src_end = (*(u32 *) (src + 4) * 0x28) + src_bone;
    if (src_bone < src_end) {
        scale_offset = 0x10;
        do {
            func_800D9600(dst_bone, src_bone);
            func_800EE7F8(dst_bone + scale_offset, src_bone + scale_offset);
            func_800EE7F8(dst_bone + 0x1C, src_bone + 0x1C);
            dst_bone += 0x28;
            src_bone += 0x28;
        } while (src_bone < src_end);
    }
}

// Sets the rotation of a bone.
void func_800DFF2C(s32 pose, s32 index, f32 rotation[4])
{
    func_800D9600(*(s32 *) pose + index * 40, rotation);
}

// Sets the scale of a bone.
void func_800DFF64(s32 *pose, s32 index, s32 scale)
{
    func_800EE7F8(pose[0] + (index * 0x28) + 0x10, scale);
}

// Sets the translation of a bone.
void func_800DFFA0(s32 *pose, unsigned int index, s32 translation)
{
    unsigned int bone_index;
    bone_index = index;
    func_800EE7F8((*pose + (bone_index * 0x28)) + 0x1C, translation);
}

int func_800DFFDC(s32 pose, s32 index, s32 param_2)
{
    s32 pad;
    f32 converted[3];
    func_800D93A0(converted, param_2 | 0);
    func_800DFF2C(pose, index, converted);
}

int func_800E0018()
{
    s32 *pose;
    pose = defrag();
    pose[0] = pose + 2;
}

func_800E0040(pose)
{
    *(s32 *) pose = (s32) (pose + 8);
}
