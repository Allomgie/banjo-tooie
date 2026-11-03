#include "common.h"

// Wrappers for the ncfixposrot camera overlay, applied to the current player's camera.

void func_800A54C0(s32 param_0)
{
    s32 fixposrot;

    fixposrot = func_8011001C(func_8008FFE8());
    if (fixposrot != 0) {
        _ncfixposrot_entrypoint_2(fixposrot, param_0);
    }
}

void func_800A54F8(s32 arg0)
{
    _ncfixposrot_entrypoint_8(func_8008FFE8(), arg0);
}

int func_800A5524()
{
    s32 camera;
    camera = func_8008FFE8();
    // Matching: the no-op "| 0" is needed for the match.
    _ncfixposrot_entrypoint_9(camera | 0);
}
