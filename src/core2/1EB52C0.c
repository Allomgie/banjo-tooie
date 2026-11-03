#include <ultra64.h>
#include "memory.h"
#include "freelist.h"
#include "core2/1EB2840.h"

FreeList *D_8012C7E0;

typedef struct {
    s16 stride;
    s16 frame_count;
    f32 speed;
} unkfunc_800DB9FC_inner;

typedef struct {
    unkfunc_800DB9FC_inner descs[7];
    f32 frames[7];
} unkfunc_800DB9FC;

unkfunc_800DB9FC *func_800DB9D0(u8 index)
{
    return (unkfunc_800DB9FC *) freelist_at(D_8012C7E0, index);
}

// Outputs the current frame offset (frame * stride) of an entry; returns 0 if the entry is unused.
s32 func_800DB9FC(u8 slot, s32 entry, s32 *offset_out)
{
    unkfunc_800DB9FC *anim;

    anim = func_800DB9D0(slot);
    if (anim->descs[entry].stride != 0) {
        *offset_out = (s32) anim->frames[entry] * anim->descs[entry].stride;
        return 1;
    }
    return 0;
}

// Allocates a slot and clears its entries.
u8 func_800DBA84(void)
{
    unkfunc_800DB9FC *anim;
    s32 slot;
    s32 i;
    if (D_8012C7E0 == NULL) {
        D_8012C7E0 = freelist_new(sizeof(unkfunc_800DB9FC), 2);
    }
    anim = freelist_next(&D_8012C7E0, &slot);

    for (i = 0; i < ARRLEN(anim->descs); i++) {
        anim->descs[i].stride = 0;
        anim->frames[i] = 0.0f;
    }

    return slot;
}

void func_800DBB24(void)
{
    if (D_8012C7E0 != NULL) {
        freelist_free(D_8012C7E0);
        D_8012C7E0 = NULL;
    }
}

void func_800DBB5C(void)
{
}

void func_800DBB64(void)
{
    if (D_8012C7E0 != NULL) {
        D_8012C7E0 = freelist_defrag(D_8012C7E0);
    }
}

// Frees a slot; the pool is freed once empty.
void func_800DBB9C(u8 slot)
{
    s32 used_count;
    if (D_8012C7E0 != NULL) {
        freelist_erase(D_8012C7E0, slot);
        used_count = freelist_used_count(D_8012C7E0);
        if (used_count == 0) {
            freelist_free(D_8012C7E0);
            D_8012C7E0 = NULL;
        }
    }
}

// Copies the entry descriptors from the model and resets the frames.
void func_800DBBF8(u8 slot, unkfunc_800DB9FC *src)
{
    unkfunc_800DB9FC *anim = func_800DB9D0(slot);
    s32 i;
    rare_memcpy(anim, src, sizeof(anim->descs));
    for (i = 0; i < ARRLEN(anim->descs); i++) {
        anim->frames[i] = 0.0f;
    }
}

// Advances every frame by speed * delta time and wraps at the frame count.
void func_800DBC68(void)
{
    s32 j;
    s32 i;
    f32 delta;
    unkfunc_800DB9FC *anim;

    if (D_8012C7E0 != NULL) {
        delta = func_800D8FF8();
        for (i = 1; i < freelist_capacity(D_8012C7E0); i++) {
            if (freelist_is_element_alive(D_8012C7E0, i) != 0) {
                anim = freelist_at(D_8012C7E0, i);
                for (j = 0; j < ARRLEN(anim->descs); j++) {
                    if (anim->descs[j].stride) {
                        anim->frames[j] += anim->descs[j].speed * delta;
                        if ((s32) anim->frames[j] >= anim->descs[j].frame_count) {
                            anim->frames[j] -= anim->descs[j].frame_count;
                        }
                    }
                }
            }
        }
    }
}

s32 func_800DBE28(u8 slot, s32 entry)
{
    unkfunc_800DB9FC *anim = func_800DB9D0(slot);
    return anim->descs[entry].frame_count;
}

void func_800DBE60(u8 slot, s32 entry, s32 frame)
{
    unkfunc_800DB9FC *anim = func_800DB9D0(slot);
    anim->frames[entry] = frame;
}
