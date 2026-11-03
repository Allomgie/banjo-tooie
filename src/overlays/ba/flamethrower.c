#include "common.h"

typedef struct {
    void (*get_ray)(void *, f32 *, f32 *);
    f32 length;
    f32 target;
} FlameThrowerData;
extern void _baflameline_entrypoint_6(void *, f32);
extern f32 func_800F15F8(f32, f32, f32);

typedef struct {
    s32 pad_0;
    f32 length;
    f32 target;
    u8 mode;
} FlamethrowerState;
typedef struct {
    u8 pad_0[0x88];
    FlamethrowerState *flame;
} FlamethrowerPlayer;

s32 baflamethrower_entrypoint_0()
{
    return 0x10;
}

// Feeds the beam with origin and direction from the callback, then ramps its length to the target.
void func_80800008_baflamethrower(u8 *player)
{
    f32 origin[3];
    f32 dir[3];
    (*(FlameThrowerData **) (player + 0x88))->get_ray(player, origin, dir);
    _baflameline_entrypoint_4(player, origin);
    _baflameline_entrypoint_5(player, dir);
    _baflameline_entrypoint_6(player, (*(FlameThrowerData **) (player + 0x88))->length);
    (*(FlameThrowerData **) (player + 0x88))->length =
        func_800F15F8((*(FlameThrowerData **) (player + 0x88))->length,
                      (*(FlameThrowerData **) (player + 0x88))->target, 20.0f);
}

// Sets the mode: 0 = off, 1 = start, 2 = firing, 3 = stopping.
void func_80800088_baflamethrower(FlamethrowerPlayer *player, s32 mode)
{
    s32 prev_mode;

    prev_mode = player->flame->mode;
    if ((prev_mode == 1 || prev_mode == 3) && mode == 3)
        return;
    player->flame->mode = mode;
    switch (mode) {
        case 0:
            break;
        case 1:
            player->flame->target = 0.0f;
            player->flame->length = player->flame->target;
            func_80800008_baflamethrower(player);
            break;
        case 2:
            player->flame->length = 150.0f;
            player->flame->target = 300.0f;
            func_80800008_baflamethrower(player);
            break;
        case 3:
            player->flame->target = 150.0f;
            _baflameline_entrypoint_1(player);
    }
}

void baflamethrower_entrypoint_1(s32 arg0)
{
    func_80800088_baflamethrower(arg0, 0);
    _baflameline_entrypoint_2(arg0);
}

void baflamethrower_entrypoint_2(u8 *player, s32 get_ray)
{
    _baflameline_entrypoint_3();
    *(s32 *) ((s8 *) *(u8 **) ((s8 *) player + 0x88) + 0) = get_ray;
    *(s8 *) ((s8 *) *(u8 **) ((s8 *) player + 0x88) + 0xC) = 0;
    func_80800088_baflamethrower(player, 1);
}

void baflamethrower_entrypoint_3(s32 arg0)
{
    func_80800088_baflamethrower(arg0, 0x2);
}

void baflamethrower_entrypoint_4(s32 arg0)
{
    func_80800088_baflamethrower(arg0, 0x3);
}

void baflamethrower_entrypoint_5(u8 *player)
{
    u8 mode;
    u8 *flame;

    mode = *(u8 *) ((s8 *) *(u8 **) ((s8 *) player + 0x88) + 0xC);
    switch (mode) {
        case 1:
            break;
        case 2:
            func_80800008_baflamethrower(player);
            break;
        case 3:
            func_80800008_baflamethrower(player);
            flame = *(u8 **) ((s8 *) player + 0x88);
            if (*(f32 *) ((s8 *) flame + 8) == *(f32 *) ((s8 *) flame + 4)) {
                func_80800088_baflamethrower(player, 1);
            }
    }
    _baflameline_entrypoint_7(player);
}
