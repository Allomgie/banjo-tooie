#include "common.h"

void func_80091E48(u8 *param_0, int param_1);
void func_80091F74(u8 *param_0, s32 param_1);
int func_80091FE4();

// Player capability mask stack (PlayerState+0x48): bit 0x1 draw, 0x2 movement/physics,
// 0x4 collision, 0x10 animation, 0x20 whole update, 0x40 button input.
// Death state (PlayerState+0x4C): one byte, state 3 triggers respawn/game over.

s32 func_80091E10(void)
{
    return 0x4;
}

void func_80091E18(s32 arg0)
{
}

// Reset the mask stack to a single entry of 0x7F.
void func_80091E20(void *player)
{
    *(s8 *) (*(s32 *) ((char *) player + 0x48) + 0x3) = 0;
    func_80091E48(player, 0x7F);
}

// Push a mask.
void func_80091E48(u8 *player, int mask)
{
    u8 *stack;
    // Matching: the extra temporary is needed for the match.
    u8 *new_var;
    stack = *(u8 **) ((s8 *) player + 0x48);
    *(stack + *(u8 *) ((s8 *) stack + 3)) = mask;
    stack = *(u8 **) ((s8 *) player + 0x48);
    *(u8 *) ((s8 *) (new_var = stack) + 3) = (u8) (*(u8 *) ((s8 *) stack + 3) + 1);
}

// Pop a mask.
int func_80091E6C(u8 *player)
{
    u8 *stack;
    stack = *(u8 **) (player + 0x48);
    stack[3]--;
}

// True if all bits of `mask` are set in the top mask.
s32 func_80091E80(u8 *player, s32 mask)
{
    u8 *stack;
    stack = *(u8 **) ((s8 *) player + 0x48);
    // Matching: the "-(0, 1)" index is needed for the match.
    return (unsigned long) (mask ==
                            (*(u8 *) ((s8 *) (stack + *(u8 *) ((s8 *) stack + 3)) + -(0, 1)) &
                             mask));
}

s32 func_80091EA0(void)
{
    return 0x1;
}

void func_80091EA8(s32 player)
{
    func_80091F74(player, 0);
}

void func_80091EC8(void *player)
{
    // Matching: this temporary is needed for the match.
    int new_var;
    *(s8 *) (*(s32 **) ((char *) player + 76) + new_var) = (new_var = 0);
    func_80091F74(player, 1);
}

// Signal death: state 3 if no cutscene is active, otherwise state 2 (wait).
int func_80091EF0(s32 player)
{
    if (func_80091FE4(player)) {
        func_80091F74(player, 3);
    } else {
        func_80091F74(player, 2);
    }
}

// Death pending (state 2): trigger it once no cutscene is active.
void func_80091F30(s32 player)
{
    s32 no_cutscene;
    if (*(u8 *) *(s32 *) (player + 0x4C) != 2) {
        goto LAB_80091F68;
    }
    no_cutscene = func_80091FE4();
    if (no_cutscene == 0) {
        goto LAB_80091F64;
    }
    func_80091F74(player, 3);
LAB_80091F64:
LAB_80091F68:;
}

// Set the death state; state 3 sets the global flag, broadcasts message 0x96 and
// calls the respawn routine if nobody handles it.
void func_80091F74(u8 *player, s32 state)
{
    if (state == 3) {
        if (func_800F8B70() == 0) {
            func_800F9104(1);
            if (func_80101238(0x96, *(s32 *) ((s8 *) player + 0x184)) == 0) {
                func_800A05DC(player);
            }
            goto block_4;
        }
    } else {
    block_4:
        **(s8 **) ((s8 *) player + 0x4C) = (s8) state;
    }
}

// True if no cutscene is active.
int func_80091FE4()
{
    s32 result;
    result = func_800DB9B0() == 0;
    // Matching: the "| 0" is needed for the match.
    return result | 0;
}
