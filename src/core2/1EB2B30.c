#include "core2/1EB2B30.h"

int func_800D9240()
{
    // Matching: the unused local is needed for the match.
    s32 pad0;
    s32 index;
    func_800F8E78();
    index = func_800F89BC();
    _glcutDll_entrypoint_10(func_800F8A5C(index));
    func_800F9070(index, 1);
    _glcutDll_entrypoint_12(1);
}

// Puts every existing player slot under cutscene control.
void func_800D9290()
{
    s32 i;
    i = 0;
    while (i < func_800F5898()) {
        if (func_800F6BE4(i)) {
            func_800F8EE4(i);
        }
        i++;
    }
}

void func_800D92EC(void)
{
}

void func_800D92F4()
{
    s32 index;
    index = func_800F8AA4();
    // Matching: the no-op `| 0` is needed for the match.
    if (func_800F8DA8(index | 0)) {
        func_800F8E78(index);
    }
}

// Forces a player state on every existing player slot.
void func_800D9330(u32 state)
{
    s32 i;
    s32 state_copy;
    // Matching: the copy through `| 0` is needed for the match.
    state_copy = state | 0;
    i = 0;
    while (i < func_800F5898()) {
        if (func_800F6BE4(i)) {
            func_800F78C8(i, state_copy);
        }
        i++;
    }
}
