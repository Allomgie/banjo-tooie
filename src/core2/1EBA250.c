// Bone transform override list: entries of rotation, scale or translation for a set of bones,
// applied per bone during pose evaluation. Lives on the heap or in core1's handle pool.
#include "types.h"
#include "memory.h"
#include "core2/1EBA250.h"
#include "core2/1EC8070.h"

void func_800D9470(f32[4], f32[4], f32[4]);
void func_800D952C(f32[4], f32[4]);
void func_800D9888(f32[4], f32[4], f32[4], f32);
void func_800D9AD4(f32[4], f32[4], f32[4], f32);

s16 func_8001B668(s32, s32);
Unkfunc_800E0960_1 *func_8001B798(s16);
void func_8001B754(s16);

// Bone transform override list: header followed by a fixed-capacity entry array.
// Entry kinds: 0 = rotation, 3 = scale, 6 = translation.

// Heap-allocated list with room for capacity entries.
void *func_800E0960(s32 capacity)
{
    void *unk_0;
    Unkfunc_800E0960_1 *list;

    list = (Unkfunc_800E0960_1 *) heap_alloc(capacity * sizeof(Unkfunc_800E0960_2) +
                                                sizeof(Unkfunc_800E0960_1));
    list->unk0 = (Unkfunc_800E0960_2 *) &list[1];
    list->unk6 = (s16) capacity;
    list->unkC = 0.0f;
    func_800E0ACC(list);
    return list;
}

// Same as above, but allocated from core1's handle pool; returns the handle.
s16 func_800E09B8(s32 capacity)
{
    Unkfunc_800E0960_1 *list;
    s16 handle;

    handle = func_8001B668(3, capacity * sizeof(Unkfunc_800E0960_2) + sizeof(Unkfunc_800E0960_1));
    list = func_800E0A28(handle);
    list->unk0 = (Unkfunc_800E0960_2 *) &list[1];
    list->unk6 = (s16) capacity;
    list->unkC = 0.0f;
    func_800E0ACC(list);
    return handle;
}

Unkfunc_800E0960_1 *func_800E0A28(s16 handle)
{
    return func_8001B798(handle);
}

void func_800E0A50(void *list)
{
    heap_free(list);
}

void func_800E0A70(s16 handle)
{
    func_8001B754(handle);
}

// Defrag: the entry array pointer must be fixed up after the list moves.
void func_800E0A98(Unkfunc_800E0960_1 *list)
{
    Unkfunc_800E0960_1 *moved;

    moved = (Unkfunc_800E0960_1 *) defrag(list);
    moved->unk0 = (Unkfunc_800E0960_2 *) &moved[1];
}

// Fixes up the entry array pointer (e.g. after handle-pool relocation).
void func_800E0AC0(Unkfunc_800E0960_1 *list)
{
    list->unk0 = (Unkfunc_800E0960_2 *) &list[1];
}

// Clears the entry count, the affected-bone bitset and the per-kind flags.
void func_800E0ACC(Unkfunc_800E0960_1 *list)
{
    list->unk10[1] = 0;
    list->unk10[2] = 0;
    list->unk10[3] = 0;
    list->unk10[0] = 0;
    list->unk4 = 0;
    list->unk8 = 0;
    list->unk9 = 0;
    list->unkA = 0;
}

// Sets the global weight.
void func_800E0AF0(Unkfunc_800E0960_1 *list, f32 weight)
{
    list->unkC = weight;
}

// Appends a rotation entry (euler angles x, y, z) for the bone.
void func_800E0AFC(Unkfunc_800E0960_1 *list, u8 bone, f32 weight, f32 x, f32 y, f32 z)
{
    Unkfunc_800E0960_2 *entry;

    if (list->unk4 < list->unk6) {
        entry = &list->unk0[list->unk4++];
        entry->unk0 = weight;
        entry->unk4[0] = x;
        entry->unk4[1] = y;
        entry->unk4[2] = z;
        entry->unk11 = 0;
        entry->unk10 = bone;
        list->unk10[bone >> 5] |= 1 << (bone & ((1 << 5) - 1));
        list->unk8 = 1;
    }
}

// Appends a scale entry for the bone.
void func_800E0B8C(Unkfunc_800E0960_1 *list, u8 bone, f32 weight, f32 x, f32 y, f32 z)
{
    Unkfunc_800E0960_2 *entry;

    if (list->unk4 < list->unk6) {
        entry = &list->unk0[list->unk4++];
        entry->unk0 = weight;
        entry->unk4[0] = x;
        entry->unk4[1] = y;
        entry->unk4[2] = z;
        entry->unk11 = 3;
        entry->unk10 = bone;
        list->unk10[bone >> 5] |= 1 << (bone & ((1 << 5) - 1));
        list->unk9 = 1;
    }
}

// Appends a translation entry for the bone.
void func_800E0C20(Unkfunc_800E0960_1 *list, u8 bone, f32 weight, f32 x, f32 y, f32 z)
{
    Unkfunc_800E0960_2 *entry;

    if (list->unk4 < list->unk6) {
        entry = &list->unk0[list->unk4++];
        entry->unk0 = weight;
        entry->unk4[0] = x;
        entry->unk4[1] = y;
        entry->unk4[2] = z;
        entry->unk11 = 6;
        entry->unk10 = bone;
        list->unk10[bone >> 5] |= 1 << (bone & ((1 << 5) - 1));
        list->unkA = 1;
    }
}

// Applies the rotation entries for the bone to the quaternion in place.
void func_800E0CB4(Unkfunc_800E0960_1 *list, u8 bone, f32 quat[4])
{
    f32 weight;
    s32 i;
    f32 blended[4];
    f32 entry_quat[4];
    f32 euler[3];
    Unkfunc_800E0960_2 *entry;

    for (i = 0; i < list->unk4; i++) {
        entry = &list->unk0[i];
        if (entry->unk10 == bone && entry->unk11 == 0) {
            weight = entry->unk0 * list->unkC;
            euler[0] = entry->unk4[0];
            euler[1] = entry->unk4[1];
            euler[2] = entry->unk4[2];
            if (weight == -1.0f) {
                func_800D952C(quat, euler);
                return;
            }
            if (weight < 0.0f) {
                func_800D952C(entry_quat, euler);
                if (weight == -1.0f) {
                    func_800D9AD4(blended, quat, entry_quat, -weight);
                } else {
                    func_800D9888(blended, quat, entry_quat, -weight);
                }
                quat[0] = blended[0];
                quat[1] = blended[1];
                quat[2] = blended[2];
                quat[3] = blended[3];
            } else if (weight > 0.0f) {
                func_800EF334(euler, weight);
                func_800D952C(entry_quat, euler);
                func_800D9470(quat, quat, entry_quat);
            }
        }
    }
}

// Applies the scale entries for the bone to the scale vector in place.
void func_800E0E94(Unkfunc_800E0960_1 *list, u8 bone, f32 scale[3])
{
    f32 weight;
    s32 i;
    Unkfunc_800E0960_2 *entry;

    for (i = 0; i < list->unk4; i++) {
        entry = list->unk0 + i;
        if (entry->unk10 == bone && entry->unk11 == 3) {
            weight = entry->unk0 * list->unkC;
            if (weight < 0.0f) {
                scale[0] = scale[0] + ((entry->unk4[0] - scale[0]) * -weight);
                scale[1] = scale[1] + ((entry->unk4[1] - scale[1]) * -weight);
                scale[2] = scale[2] + ((entry->unk4[2] - scale[2]) * -weight);
            } else if (weight > 0.0f) {
                scale[0] *= 1.0f + ((entry->unk4[0] - 1.0f) * weight);
                scale[1] *= 1.0f + ((entry->unk4[1] - 1.0f) * weight);
                scale[2] *= 1.0f + ((entry->unk4[2] - 1.0f) * weight);
            }
        }
    }
}

// Applies the translation entries for the bone to the position in place.
void func_800E0FE8(Unkfunc_800E0960_1 *list, u8 bone, f32 pos[3])
{
    f32 weight;
    s32 i;
    Unkfunc_800E0960_2 *entry;

    for (i = 0; i < list->unk4; i++) {
        entry = &list->unk0[i];
        if (entry->unk10 == bone && entry->unk11 == 6) {
            weight = entry->unk0 * list->unkC;
            if (weight < 0.0f) {
                pos[0] = pos[0] + ((entry->unk4[0] - pos[0]) * -weight);
                pos[1] = pos[1] + ((entry->unk4[1] - pos[1]) * -weight);
                pos[2] = pos[2] + ((entry->unk4[2] - pos[2]) * -weight);
            } else if (weight > 0.0f) {
                pos[0] += entry->unk4[0] * weight;
                pos[1] += entry->unk4[1] * weight;
                pos[2] += entry->unk4[2] * weight;
            }
        }
    }
}
