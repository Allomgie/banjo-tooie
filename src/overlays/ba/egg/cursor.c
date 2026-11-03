#include "common.h"
#include "overlays/ba/playerstate.h"

extern s32 D_80800690_baeggcursor[];
extern void func_800E253C(f32);
extern void func_800E257C(s32);
typedef struct {
    f32 time;
    f32 value;
} EggCursorCurvePoint;
typedef struct {
    u8 pad_0[9];
    u8 mode;
    u8 pad_1[2];
    f32 timer;
    u8 curve;
    u8 pad_2[3];
    s32 alpha;
    f32 scale;
} EggCursorUpdateState;
int baeggcursor_entrypoint_7();

int func_80800000_baeggcursor(s32 index)
{
    return D_80800690_baeggcursor[index];
}

s32 baeggcursor_entrypoint_0()
{
    return 0x1C;
}

// Draw the crosshair sprite (asset 0x64E) for the local viewport.
void baeggcursor_entrypoint_1(PlayerState *player)
{
    s32 screen_pos[2];
    s32 viewport;
    s32 unk_0;

    viewport = func_800A89F8(player);
    if (func_800A4C68(player) == viewport && (*(u8 **) ((u8 *) player + 0x68))[8] != 0 &&
        (*(u8 **) ((u8 *) player + 0x68))[0xA] != 0 && !func_800A9C98()) {
        func_800E253C(*(f32 *) (*(u8 **) ((u8 *) player + 0x68) + 0x18));
        func_800E257C(*(s32 *) (*(u8 **) ((u8 *) player + 0x68) + 0x14));
        func_800E2434(1);
        func_800E24CC(1);
        screen_pos[0] = *(f32 *) *(u8 **) ((u8 *) player + 0x68) * 4.0f;
        screen_pos[1] = *(f32 *) (*(u8 **) ((u8 *) player + 0x68) + 4) * 4.0f;
        unk_0 = func_800A7180();
        func_800E30E0(unk_0, func_800D674C(0x64E), 0, screen_pos);
    }
}

s32 baeggcursor_entrypoint_2(s32 player)
{
    return ((u8 *) *(u8 **) (player + 104))[9];
}

void baeggcursor_entrypoint_3(u8 *player, f32 *out_x, f32 *out_y)
{
    *out_x = *(f32 *) ((s8 *) *(u8 **) ((s8 *) player + 0x68) + 0);
    *out_y = *(f32 *) ((s8 *) *(u8 **) ((s8 *) player + 0x68) + 4);
}

void baeggcursor_entrypoint_4(s32 player)
{
    baeggcursor_entrypoint_7(player, 0);
}

void baeggcursor_entrypoint_5(void *player)
{
    *(s8 *) (*(s32 *) ((char *) player + 0x68) + 0x9) = 0;
    baeggcursor_entrypoint_7(player, 1);
}

void baeggcursor_entrypoint_6(Actor *player, int enable)
{
    *(*(s8 **) ((u8 *) player + 0x68) + 0xA) = enable;
}

void baeggcursor_entrypoint_10(s32 player, f32 x, f32 y);

// Switch the cursor mode (0 off ... 5).
int baeggcursor_entrypoint_7(player, mode)
u8 *player;
s32 mode;
{
    switch ((*(u8 **) (player + 0x68))[9]) {
        case 0:
            (*(u8 **) (player + 0x68))[8] = 0;
            (*(u8 **) (player + 0x68))[0xA] = 1;
            break;
        case 1:
            (*(u8 **) (player + 0x68))[8] = 1;
            *(s32 *) (*(u8 **) (player + 0x68) + 0x14) = 0x78;
            break;
        case 3:
            *(s32 *) (*(u8 **) (player + 0x68) + 0x14) = 0x78;
            break;
    }
    (*(u8 **) (player + 0x68))[9] = mode;
    switch (mode) {
        case 0:
        case 1:
            func_8009ADF0(player, 8, 0);
            if ((*(u8 **) (player + 0x68))[8]) {
                (*(u8 **) (player + 0x68))[8] = 0;
            }
            break;
        case 2:
            func_8009ADF0(player, 8, 1);
            *(f32 *) (*(u8 **) (player + 0x68) + 0x18) = 1.0f;
            *(s32 *) (*(u8 **) (player + 0x68) + 0x14) = 0x78;
            break;
        case 3:
            func_8009ADF0(player, 8, 1);
            *(f32 *) (*(u8 **) (player + 0x68) + 0xC) = 0.3f;
            baeggcursor_entrypoint_10(player, 152.0f, 114.0f);
            *(f32 *) (*(u8 **) (player + 0x68) + 0x18) = 16.0f;
            *(s32 *) (*(u8 **) (player + 0x68) + 0x14) = 0;
            break;
        case 4:
            func_8009ADF0(player, 8, 1);
            *(f32 *) (*(u8 **) (player + 0x68) + 0xC) = 0.2f;
            break;
        case 5:
            func_8009ADF0(player, 8, 1);
            *(f32 *) (*(u8 **) (player + 0x68) + 0xC) = 0.0f;
            (*(u8 **) (player + 0x68))[0x10] = 0;
    }
}

void baeggcursor_entrypoint_8(u8 *player)
{
    u8 mode;

    mode = *(u8 *) ((s8 *) *(u8 **) ((s8 *) player + 0x68) + 9);
    if ((mode != 0) && (mode != 1) && (mode != 4)) {
        baeggcursor_entrypoint_7(player, 5);
    }
}

s32 baeggcursor_entrypoint_9(u8 *player)
{
    u8 mode;

    mode = *(u8 *) ((s8 *) *(u8 **) ((s8 *) player + 0x68) + 9);
    if ((mode != 0) && (mode != 1) && (mode != 4)) {
        return 1;
    }
    return 0;
}

void baeggcursor_entrypoint_10(s32 player, f32 x, f32 y)
{
    *(f32 *) (*(s32 *) (player + 0x68) + 0x0) = x;
    *(f32 *) (*(s32 *) (player + 0x68) + 0x4) = y;
}

// Per-frame cursor animation (scale and alpha); changes mode when an animation ends.
void baeggcursor_entrypoint_11(u8 *player)
{
    extern f32 func_800F10B4(f32, f32, f32, f32, f32);
    extern u8 func_800D9078(f32 *);
    f32 scale;
    f32 timer;
    s32 i;
    EggCursorCurvePoint *curve;
    EggCursorUpdateState *cursor;
    cursor = *(EggCursorUpdateState **) (player + 0x68);
    // Matching: the two empty if (1) blocks are needed for the match.
    if (1) {
    }
    if (1) {
    }
    switch (cursor->mode) {
        case 3:
            if (cursor->timer < 0.1f) {
                scale = func_800F10B4(cursor->timer, 0.0f, 0.1f, 1.0f, 0.8f);
            } else {
                scale = func_800F10B4(cursor->timer, 0.1f, 0.3f, 0.8f, 16.0f);
            }
            (*(EggCursorUpdateState **) (player + 0x68))->scale = scale;
            (*(EggCursorUpdateState **) (player + 0x68))->alpha = func_800F10B4(
                (*(EggCursorUpdateState **) (player + 0x68))->timer, 0.0f, 0.3f, 120.0f, 0.0f);
            if (func_800D9078(&(*(EggCursorUpdateState **) (player + 0x68))->timer)) {
                baeggcursor_entrypoint_7(player, 2);
            }
            break;
        case 4:
            (*(EggCursorUpdateState **) (player + 0x68))->scale =
                func_800F10B4(cursor->timer, 0.0f, 0.2f, 16.0f, 1.0f);
            (*(EggCursorUpdateState **) (player + 0x68))->alpha = func_800F10B4(
                (*(EggCursorUpdateState **) (player + 0x68))->timer, 0.0f, 0.2f, 0, 120.0f);
            if (func_800D9078(&(*(EggCursorUpdateState **) (player + 0x68))->timer)) {
                baeggcursor_entrypoint_7(player, 1);
            }
            break;
        case 5:
            timer = cursor->timer;
            curve = func_80800000_baeggcursor(cursor->curve);
            for (i = 0; curve[i].time <= timer; i++) {
                if (curve[i].value == 0) {
                    baeggcursor_entrypoint_7(player, 2);
                    break;
                }
            }
            (*(EggCursorUpdateState **) (player + 0x68))->scale =
                func_800F10B4(timer, curve[i - 1].time, curve[i].time,
                              curve[i - 1].value, curve[i].value);
            func_800D91B8(&(*(EggCursorUpdateState **) (player + 0x68))->timer);
    }
}

u32 D_80800670_baeggcursor[8] = {0x0,        0x3F800000, 0x3DA3D70A, 0x3F000000,
                                 0x3E99999A, 0x3F800000, 0x0,        0x0};
s32 D_80800690_baeggcursor[4] = {(u32) &D_80800670_baeggcursor, 0x0, 0x0, 0x0};
