// Probably the player's stack of external hold/lock requests (up to 8, PlayerState+0xF0),
// each with a type and optional target position; each frame the effective type is compared
// with the active one and an interrupt is sent. Popping the last one grants 1.2 s invulnerability.

#include "core2/1E76500.h"

s32 func_8009CC10()
{
    return 0x84;
}

// Copies the target position of the top lock request into pos; returns 0 if it has none.
s32 func_8009CC18(PlayerState *player, f32 *pos)
{
    int pos_offset;
    f32 *dst;
    u8 *lock_stack;
    u8 *stack_base;
    u8 *entry;
    lock_stack = *(u8 **) ((char *) player + 0xF0);
    pos_offset = 0xC;
    entry = (*(u8 *) ((char *) lock_stack + 0x80) * 0x10) + (stack_base = lock_stack);
    if (*(u8 *) (entry - 0xF) == 0) {
        return 0;
    }
    dst = pos;
    func_800EE7F8(dst, entry - pos_offset);
    return 1;
}

// Returns the type of the top lock request, or 0 if the stack is empty.
s32 func_8009CC68(PlayerState *player)
{
    int top_offset;
    u8 *lock_stack;
    u8 count;
    u8 *stack_base;
    lock_stack = *(u8 **) ((u8 *) player + 0xF0);
    stack_base = lock_stack;
    count = stack_base[0x80];
    if (count == 0) {
        return 0;
    }
    top_offset = (count * 0x10) - 0x10;
    return stack_base[top_offset];
}

void func_8009CC90(u8 *player)
{
    *(s8 *) ((s8 *) *(u8 **) ((s8 *) player + 0xF0) + 0x81) = 0;
    *(s8 *) ((s8 *) *(u8 **) ((s8 *) player + 0xF0) + 0x80) = 0;
}

// Pops the top request; popping the last one grants 1.2 s of invulnerability.
void func_8009CCA4(u8 *player)
{
    u8 *lock_stack;
    int count;
    lock_stack = *(u8 **) ((s8 *) player + 0xF0);
    count = *(u8 *) ((s8 *) lock_stack + 0x80);
    if (count != 0) {
        *(u8 *) ((s8 *) lock_stack + 0x80) = (u8) (count - 1);
        if (*(u8 *) ((s8 *) *(u8 **) ((s8 *) player + 0xF0) + 0x80) == 0) {
            func_8009BDAC(player, 0x3F99999A);
            *(s8 *) ((s8 *) *(u8 **) ((s8 *) player + 0xF0) + 0x81) = 0;
        }
    }
}

// Pushes a request of the given type without a target.
void func_8009CCFC(u8 *player, unsigned int type)
{
    u8 *lock_stack;
    unsigned int pos_offset;
    u8 *count_ptr;
    lock_stack = *(u8 **) (player + 0xF0);
    *(lock_stack + (*(u8 *) (lock_stack + 0x80) * 0x10)) = type;
    lock_stack = *(u8 **) (player + 0xF0);
    *(s8 *) ((lock_stack + (*(u8 *) (lock_stack + 0x80) * 0x10)) + 1) = 0;
    lock_stack = *(u8 **) (player + 0xF0);
    count_ptr = (u8 *) (lock_stack + 0x80);
    func_800EFD24((lock_stack + (*count_ptr * 0x10)) + (pos_offset = 4));
    lock_stack = *(u8 **) (player + 0xF0);
    *(u8 *) (lock_stack + 0x80) = *(u8 *) (lock_stack + 0x80) + 1;
}

// Marks the top request as having a target and sets its position.
void func_8009CD70(u8 *player, s32 unk_0)
{
    u8 *lock_stack;
    u8 *lock_stack_2;
    u8 *lock_stack_3;
    lock_stack = *(u8 **) ((char *) player + 0xF0);
    *(s8 *) (((char *) lock_stack + (*(u8 *) ((char *) lock_stack + 0x80) * 0x10)) - 0xF) = 1;
    if (unk_0 != 0) {
        lock_stack_2 = *(u8 **) ((char *) player + 0xF0);
        func_800EE7F8(((char *) lock_stack_2 + (*(u8 *) ((char *) lock_stack_2 + 0x80) * 0x10)) -
                      (0, 0xC));
    } else {
        lock_stack_3 = *(u8 **) ((char *) player + 0xF0);
        func_800EFD24(((char *) lock_stack_3 + (*(u8 *) ((char *) lock_stack_3 + 0x80) * 0x10)) -
                      (0, 0xC));
    }
}

// Matching: old-style definition so the caller can pass the two extra arguments the original
// sets up but this function never reads.
// Sends the interrupt for the given lock type and makes it the active type on success.
int func_8009CDE0(player, type)
Actor *player;
s32 type;
{
    s32 accepted;
    accepted = 0;
    switch (type) {
        case 1:
            if (func_8009E7C8(player, 0x1E) == 2) {
                accepted = 1;
            }
            break;

        case 2:
            if (func_8009E7C8(player, 0x1C) == 2) {
                accepted = 1;
            }
            break;

        case 3:
            if (func_8009E7C8(player, 0x1D) == 2) {
                accepted = 1;
            }
            break;

        case 4:
            if (func_8009E7C8(player, 0x25) == 2) {
                accepted = 1;
            }
            break;

        default:
            accepted = 1;
            break;
    }

    if (accepted != 0) {
        *(u8 *) ((char *) *(s32 **) ((char *) player + 0xF0) + 0x81) = type;
    }
}

void func_8009CEE8(u8 *player)
{
    if ((*(u8 **) (player + 0xF0))[0x80] != 0) {
        (*(u8 **) (player + 0xF0))[0x81] = 0;
    }
}

// Matching: the line breaks in this function are needed for the match.
// Per-frame: the effective type (a type 1 entry wins over the top one) is compared with the active one.
void func_8009CF04(struct Actor *player)
{
    s32 offset;
    u8 *entry_ptr;
    u8 *lock_stack;
    u8 *scan;
    int active_type_offset;
    u8 count;
    int effective_type;
    lock_stack = *(u8 **) ((u8 *) player + 0xF0);
    count = lock_stack[0x80];
    active_type_offset = 0x81;
    if (count != 0)
    {
        do { effective_type = *(u8 *) (((char *) lock_stack + ((count & 0xFFFFFFFF) * 0x10)) - 0x10); if ((s32) count > 0) { offset = 0; scan = lock_stack; do { if ((effective_type && effective_type) && effective_type) {} entry_ptr = &*scan; offset = offset + 0x10; if (*entry_ptr == 1) { effective_type = 1; } scan += 0x10; } while (offset < (count * 0x10)); } if (effective_type != lock_stack[active_type_offset]) { func_8009CDE0(player, effective_type ^ 0, effective_type, lock_stack); } } while (0);
    }
}
