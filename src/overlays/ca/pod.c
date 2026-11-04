#include "common.h"

extern f32 _ncpod_entrypoint_30(s32);

s32 capod_entrypoint_0(s32 unk_0, s32 unk_1, s32 unk_2)
{
    s32 camera;

    camera = func_80110024(func_8008FFE8());
    if (camera != 0) {
        return _ncpod_entrypoint_6(func_8008FFE8(), camera, unk_0, unk_1, unk_2);
    }
    return -1;
}

s32 capod_entrypoint_1(s32 unk_0, s32 unk_1)
{
    s32 player;
    s32 camera;

    player = func_8008FFE8();
    camera = func_80110024(player);
    if (camera) {
        _ncpod_entrypoint_8(camera, unk_0, unk_1);
    }
}

// Dialog camera setup.
int capod_entrypoint_2(s32 unk_0, s32 unk_1, s32 unk_2)
{
    s32 player;
    player = func_8008FFE8();
    // Matching: `| 0` is needed for the match.
    if (player != 0) {
        return _ncpod_entrypoint_16(player | 0, unk_0, unk_1, unk_2);
    }
    return 0;
}

// Dialog camera setup.
int capod_entrypoint_3(s32 unk_0)
{
    s32 player;
    player = func_8008FFE8();
    // Matching: `| 0` and the extra block are needed for the match.
    if (player != 0) {
        return _ncpod_entrypoint_17(player | 0, unk_0);
    }
    {
        return 0;
    }
}

s32 capod_entrypoint_4(void)
{
    void *player = func_8008FFE8();
    if (player) {
        return _ncpod_entrypoint_18(player);
    }
    return -1;
}

void capod_entrypoint_5(Actor *this)
{
    s32 camera;

    camera = func_80110024(func_8008FFE8());
    if (camera != 0) {
        _ncpod_entrypoint_19(camera, this);
    }
}

// Dialog camera setup.
int capod_entrypoint_6(s32 unk_0, s32 unk_1, s32 unk_2)
{
    s32 player;
    player = func_8008FFE8();
    // Matching: `| 0` and the extra block are needed for the match.
    if (player != 0) {
        return _ncpod_entrypoint_20(player | 0, unk_0, unk_1, unk_2);
    }
    {
        return 0;
    }
}

// Dialog camera setup.
int capod_entrypoint_7(s32 unk_0, s32 unk_1)
{
    s32 player;
    player = func_8008FFE8();
    // Matching: `| 0` is needed for the match.
    if (player != 0) {
        _ncpod_entrypoint_21(player | 0, unk_0, unk_1);
    }
}

// Dialog camera setup.
void capod_entrypoint_8(s32 unk_0)
{
    s32 camera;

    camera = func_80110024(func_8008FFE8());
    if (camera != 0) {
        _ncpod_entrypoint_12(camera, unk_0);
    }
}

s32 capod_entrypoint_9(s32 unk_0, s32 unk_1)
{
    s32 player;
    s32 camera;

    player = func_8008FFE8();
    camera = func_80110024(player);
    if (camera) {
        _ncpod_entrypoint_22(camera, unk_0, unk_1);
    }
}

s32 capod_entrypoint_10(s32 unk_0, s32 unk_1)
{
    s32 player;
    s32 camera;

    player = func_8008FFE8();
    camera = func_80110024(player);
    if (camera) {
        _ncpod_entrypoint_23(camera, unk_0, unk_1);
    }
}

s32 capod_entrypoint_11(s32 unk_0, s32 unk_1)
{
    s32 player;
    s32 camera;

    player = func_8008FFE8();
    camera = func_80110024(player);
    if (camera) {
        _ncpod_entrypoint_24(camera, unk_0, unk_1);
    }
}

void capod_entrypoint_12(s32 unk_0)
{
    s32 camera;

    camera = func_80110024(func_8008FFE8());
    if (camera != 0) {
        _ncpod_entrypoint_25(camera, unk_0);
    }
}

// Start the event camera; returns 1 on success.
s32 capod_entrypoint_13(s32 unk_0, s32 unk_1, s32 unk_2, s32 unk_3)
{
    s32 player;

    player = func_8008FFE8();
    if ((player != 0) &&
        (_ncpod_entrypoint_26(player, unk_0, unk_1, unk_2, unk_3) != 0)) {
        return 1;
    }
    return 0;
}

// Release the camera.
int capod_entrypoint_14()
{
    s32 player;
    // Matching: inline assignment and `| 0` are needed for the match.
    if ((player = func_8008FFE8()) != 0) {
        _ncpod_entrypoint_27(player | 0, 0);
    } else {
        return 0;
    }
}

// Release the camera.
int capod_entrypoint_15()
{
    int player;
    // Matching: inline assignment and `| 0` are needed for the match.
    if ((player = func_8008FFE8()) != 0) {
        _ncpod_entrypoint_27(player | 0, 1);
    } else {
        return 0;
    }
}

s32 capod_entrypoint_16(f32 unk_0)
{
    s32 player;
    player = func_8008FFE8();
    if (player != 0) {
        return _ncpod_entrypoint_28(player, *(s32 *) &unk_0);
    }
    return 0;
}

s32 capod_entrypoint_17(f32 unk_0)
{
    s32 player;
    player = func_8008FFE8();
    if (player != 0) {
        return _ncpod_entrypoint_29(player, *(s32 *) &unk_0);
    }
    return 0;
}

f32 capod_entrypoint_18()
{
    s32 player;
    player = func_8008FFE8();
    if (player) {
        return _ncpod_entrypoint_30(player);
    }
    return 0.0f;
}

int capod_entrypoint_19(s32 unk_0)
{
    s32 player;
    player = func_8008FFE8();
    // Matching: `| 0` is needed for the match.
    if (player != 0) {
        _ncpod_entrypoint_31(player | 0, unk_0);
    }
}

int capod_entrypoint_20(s32 unk_0, s32 unk_1, s32 unk_2)
{
    s32 player;
    player = func_8008FFE8();
    // Matching: `| 0` and the extra block are needed for the match.
    if (player != 0) {
        return _ncpod_entrypoint_32(player | 0, unk_0, unk_1, unk_2);
    }
    {
        return 0;
    }
}

// Set up a fixed-position camera; returns 1 on success.
s32 capod_entrypoint_21(s32 unk_0, s32 unk_1, s32 unk_2, s32 unk_3)
{
    s32 player;

    player = func_8008FFE8();
    if ((player != 0) &&
        (_ncpod_entrypoint_33(player, unk_0, unk_1, unk_2, unk_3) != 0)) {
        return 1;
    }
    return 0;
}

// Release the camera.
int capod_entrypoint_22()
{
    s32 player;
    player = func_8008FFE8();
    // Matching: `| 0` is needed for the match.
    if (player != 0) {
        _ncpod_entrypoint_27(player | 0, 0);
    } else {
        return 0;
    }
}
