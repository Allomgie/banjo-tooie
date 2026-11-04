// Probably marker target-class bookkeeping (class mask in marker+0x2A, per-class sorted lists
// rebuilt each frame) plus dispatch of the ActorInfo callback at +0x14.
#include "common.h"

typedef struct {
    u8 pad0[0x64];
    u32 pad64_0 : 14;
    u32 unk64_14 : 1;
    u16 unk64_15 : 1;
    u16 pad64_16 : 16;
    u8 pad68[0x14];
    s32 pad7C : 16;
    s32 unk7E_15 : 1;
    s32 pad7E : 15;
} S8010A79C;
extern u8 *func_80100368(S8010A79C *);

void func_8010A730(s32 arg0, s32 arg1)
{
}

int func_8010A73C(s32 *marker_ref, s32 unused)
{
    func_801039E4(*marker_ref);
}

// Calls the ActorInfo callback (+0x14).
void func_8010A764(s32 actor, s32 arg)
{
    ((void (*)(s32, s32)) * (s32 *) (func_80100368(actor) + 0x14))(actor, arg);
}

// Calls the ActorInfo callback (+0x14) if the actor flags allow it.
void func_8010A79C(S8010A79C *actor, s32 arg)
{
    if (actor->unk7E_15) {
        if (!actor->unk64_14) {
            if (actor->unk64_15) {
                (*(void (**)(S8010A79C *, s32))(func_80100368(actor) + 0x14))(actor, arg);
            }
        }
    }
}

// Sets the target-class mask of the marker to the single class class_idx.
void func_8010A800(u8 **actor, s32 class_idx)
{
    unsigned short class_bit;
    int two;
    u8 *marker;
    u8 *marker_copy;
    marker = *actor;
    // Matching: the extra temporaries are needed for the match.
    marker_copy = marker;
    two = 2;
    *(u16 *) ((s8 *) marker_copy + 0x2A) = (u16) ((*(u16 *) ((s8 *) marker_copy + 0x2A) & 0xFE01) |
                                              (((class_bit = 1 << class_idx) * two) & 0x1FE));
}

// Replaces the target-class mask in the marker with mask.
void func_8010A828(u8 **actor, s32 mask)
{
    unsigned short new_mask;
    u16 result;
    u16 old_bits;
    u8 *marker;
    marker = *actor;
    // Matching: the dead first assignment to result is needed for the match.
    result = (u16) (((mask * 2) & (0x1FE & 0xFFFFFFFFu)) |
                     (*(u16 *) ((s8 *) marker + 0x2A) & 0xFE01));
    new_mask = mask * 2;
    old_bits = *(u16 *) ((s8 *) marker + 0x2A);
    result = (u16) ((new_mask & (0x1FE & 0xFFFFFFFFu)) | (old_bits & 0xFE01));
    *(u16 *) ((s8 *) marker + 0x2A) = result;
}

// Returns the 8-bit target-class mask of the actor marker.
u32 func_8010A848(u8 **actor)
{
    return (u32) (*(s32 *) ((s8 *) *actor + 0x28) << 0x17) >> 0x18;
}

// Sets the 4-bit mode at actor+0x77.
int func_8010A85C(u8 *actor, s32 mode)
{
    int mode_bits;
    actor[0x77] = (actor[0x77] & 0xFFF0) | (mode_bits = (mode & 0xF) & 0xFFFF);
}

// Rebuilds the per-class marker lists: each active, in-zone marker joins the list of every class in its mask.
void func_8010A874(Image *actor)
{
    void *marker;
    u16 iter[2];
    unsigned int class_mask;
    u16 player_pos[6];
    s32 class_idx;
    s32 class_bit;
    func_800EB800();
    func_800E3A30(&player_pos);
    actor = func_801067C4(&iter);
    if (actor != 0) {
        do {
            marker = *(void **) ((char *) actor + 0x0);
            if (((*(u16 *) ((char *) marker + 0x14) != 0) &&
                 (*(u16 *) ((char *) actor + 0x64) & 1)) &&
                ((*(u8 *) ((char *) actor + 0x78) == 0) ||
                 (_subaddiezone_entrypoint_1(actor) != 0))) {
                class_bit = 1;
                class_idx = 0;
                class_mask = (u32) (*(s32 *) ((char *) marker + 0x28) << 0x17) >> 0x18;
                do {
                    if (class_mask & class_bit) {
                        func_800EB3D0(*(s32 *) ((char *) marker + 0x0), class_idx, &player_pos);
                    }
                    class_idx += 1;
                    class_bit *= 2;
                } while (class_idx != 7);
            }
            actor = func_8010682C(&iter);
        } while (actor != 0);
    }
}
