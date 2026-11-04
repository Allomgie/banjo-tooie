// Player dust and smoke puffs (PlayerState+0x5C): running/skid trails, landing rings, slide
// dust and generic puffs with configurable velocity, scale and alpha.
#include "common.h"
#include "playerstate.h"
#include "core2/1E93440.h"

extern f32 func_8009BB18(PlayerState *);
extern void _batimer_set(PlayerState *, s32, f32);
extern s32 func_80096544(void);
extern f32 func_800964DC(void *);
extern f32 func_8009C150(void *);
extern f32 func_8009BB5C(void *);
extern s32 _fxdlsmoke_entrypoint_0(f32 *);
extern void func_800BA7C4(s32, f32, f32);
extern void func_800BA7FC(s32, f32, f32);
extern void func_800BA8F8(s32, f32, f32);
extern void func_800BA5BC(s32, f32, f32);
typedef struct {
    s32 mode;
    u8 pad_4[5];
    u8 unk_9;
} DustState;
typedef struct {
    u8 pad_0[0x5C];
    DustState *dust;
} DustPlayer;
extern void func_8009C128(PlayerState *, f32 *);
extern void func_800EFCD8(f32 *, f32, f32);
extern void func_800EFA4C(f32 *, f32, f32, f32);
extern f32 yaw_get(PlayerState *);
extern f32 func_800DC178(f32, f32);
extern f32 func_800DC0C0(void);
extern f32 func_800136E4(f32);
extern void func_800EF334(f32 *, f32);
extern int func_800EF04C(f32 *, f32 *);
void badust_entrypoint_12();
void badust_entrypoint_4(PlayerState *player, f32 yaw, f32 dist);

s32 badust_entrypoint_0()
{
    return 0xC;
}

void func_80800008_badust(arg0) s32 arg0;
{
}

void func_80800010_badust(player) PlayerState *player;
{
    if (_batimer_decrement(player, 8)) {
        func_800A2EEC(player, 0);
        _batimer_set(player, 8, 0.12f);
    }
    ((u8 *) *(u8 **) ((u8 *) player + 0x5C))[9] =
        (((u8 *) *(u8 **) ((u8 *) player + 0x5C))[9] + 1) % 2;
    switch (((u8 *) *(u8 **) ((u8 *) player + 0x5C))[9]) {
        case 0:
            badust_entrypoint_4(player, func_8009BB18(player) + 180.0f - 70.0f, 20.0f);
            return;
        case 1:
            badust_entrypoint_4(player, func_8009BB18(player) + 180.0f - 10.0f, 20.0f);
            return;
        case 2:
            badust_entrypoint_4(player, func_8009BB18(player) + 180.0f + 50.0f, 20.0f);
    }
}

void badust_entrypoint_1(void *player)
{
    f32 unk_0;
    u8 *dust;
    if ((func_80096544() == 0) ||
        (unk_0 = func_800964DC(player), !(func_8009C150(player) < unk_0))) {
        dust = *(u8 **) ((u8 *) player + 0x5C);
        if (*(s32 *) ((u8 *) dust + 4) != 0) {
            *(s32 *) ((u8 *) dust + 4) = 0;
        } else {
            *(s32 *) ((u8 *) dust + 4) = 1;
        }
        if (func_8009BB5C(player) > 100.0f) {
            if (*(s32 *) ((u8 *) *(u8 **) ((u8 *) player + 0x5C) + 4) != 0) {
                badust_entrypoint_4(player, func_8009BB18(player) - 20.0f, 20.0f);
                return;
            }
            badust_entrypoint_4(player, func_8009BB18(player) + 20.0f, 20.0f);
        }
    }
}

// Spawns one smoke puff at pos with the given velocity.
void badust_entrypoint_2(PlayerState *player, f32 *pos, f32 *velocity, f32 unk_0, f32 unk_1,
                         f32 unk_2)
{
    s32 emitter;
    s16 vx;
    s16 vy;
    s16 vz;
    emitter = _fxdlsmoke_entrypoint_0(pos);
    vx = (s16) velocity[0];
    vy = (s16) velocity[1];
    vz = (s16) velocity[2];
    func_800BA930(emitter, vx, vy, vz, vx, vy, vz);
    func_800BA450(emitter, 0, 0, 0, 0, 0, 0);
    func_800BA7C4(emitter, unk_0, unk_0);
    func_800BA7FC(emitter, unk_1, unk_1);
    func_800BA8F8(emitter, unk_2, unk_2);
    func_800BA5BC(emitter, 19.0f / unk_2, 19.0f / unk_2);
    func_800BA22C(emitter, 1);
}

void badust_entrypoint_3(PlayerState *player, f32 yaw, f32 speed)
{
    f32 velocity[3];
    f32 pos[3];

    speed *= 0.51f;
    func_8009C128(player, pos);
    pos[1] += 12.0f;
    func_800EFCD8(velocity, yaw, speed);
    velocity[1] = 50.0f;
    badust_entrypoint_2(player, pos, velocity, 0.1f, 0.8f, 1.0f);
}

// Spawns a puff behind the feet: offset from the player by (yaw, dist).
void badust_entrypoint_4(PlayerState *player, f32 yaw, f32 dist)
{
    f32 offset[3];
    f32 pos[3];
    f32 velocity[3];
    s32 emitter;

    func_800EFA4C(velocity, 0.0f, 40.0f, 0.0f);
    func_8009C128(player, pos);
    func_800EFCD8(offset, yaw, dist);
    offset[1] = 15.0f;
    func_800EF04C(pos, offset);
    emitter = _fxdlsmoke_entrypoint_0(pos);
    func_800BA930(emitter, (s16) velocity[0], (s16) velocity[1], (s16) velocity[2], (s16) velocity[0],
                  (s16) velocity[1], (s16) velocity[2]);
    func_800BA450(emitter, 0, 0, 0, 0, 0, 0);
    func_800BA7C4(emitter, 0.2f, 0.2f);
    func_800BA7FC(emitter, 0.7f, 0.75f);
    func_800BA8F8(emitter, 0.6f, 0.7f);
    func_800BA5BC(emitter, 19.0f, 19.0f);
    func_800BA22C(emitter, 1);
}

void badust_entrypoint_5(PlayerState *player, f32 yaw, f32 speed)
{
    f32 velocity[3];
    f32 pos[3];

    speed *= 0.51f;
    func_8009C128(player, pos);
    pos[1] += 2.0f;
    func_800EFCD8(velocity, yaw, speed);
    velocity[1] = 50.0f;
    badust_entrypoint_2(player, pos, velocity, 0.1f, 0.8f, 1.0f);
}

void badust_entrypoint_6(PlayerState *player, f32 y_offset, f32 yaw, f32 speed, f32 velocity_y)
{
    f32 velocity[3];
    f32 pos[3];
    speed *= 0.51f;
    func_8009C128(player, pos);
    pos[1] += 12.0f + y_offset;
    func_800EFCD8(velocity, yaw, speed);
    velocity[1] = velocity_y;
    badust_entrypoint_2(player, pos, velocity, 0.1f, 0.8f, 0.7f);
}

void badust_entrypoint_7(PlayerState *player)
{
    f32 velocity[3];
    f32 pos[3];
    f32 offset[3];
    f32 side_yaw;
    func_8009C128(player, pos);
    pos[1] += 20.0f;
    ((u8 *) *(void **) ((u8 *) player + 0x5C))[8]++;
    if (((u8 *) *(void **) ((u8 *) player + 0x5C))[8] > 2)
        ((u8 *) *(void **) ((u8 *) player + 0x5C))[8] = 0;
    if (((u8 *) *(void **) ((u8 *) player + 0x5C))[8]) {
        side_yaw = func_800136E4(yaw_get(player) + func_800DC178(70.0f, 90.0f));
        func_800EFCD8(offset, side_yaw, func_800DC0C0() * 15.0f + 20.0f);
        offset[1] = 0.0f;
    }
    switch (((u8 *) *(void **) ((u8 *) player + 0x5C))[8]) {
        case 0:
            break;
        case 1:
            func_800EF334(offset, -1.0f);
            func_800EF04C(pos, offset);
            break;
        case 2:
            func_800EF04C(pos, offset);
            break;
    }
    func_800EFCD8(velocity, yaw_get(player), 40.0f);
    velocity[1] = func_800DC178(50.0f, 90.0f);
    badust_entrypoint_2(player, pos, velocity, func_800DC178(0.4f, 0.5f),
                        func_800DC178(0.7f, 0.9f), func_800DC178(0.8f, 1.3f));
}

void badust_entrypoint_8(s32 player)
{
    f32 angle;

    for (angle = 0.0f; angle < 360.0f; angle += 45.0f) {
        badust_entrypoint_5(player, angle, 230.0f);
    }
}

void badust_entrypoint_9(PlayerState *player)
{
    switch (*(s32 *) (*(u8 **) ((u8 *) player + 0x5C) + 4)) {
        case 0:
            badust_entrypoint_4(player, func_8009BB18(player) - 20.0f, 40.0f);
            break;
        case 1:
            badust_entrypoint_4(player, func_8009BB18(player) + 20.0f, 40.0f);
            break;
        case 2:
            badust_entrypoint_4(player, func_8009BB18(player), 30.0f);
    }
    (*(s32 *) (*(u8 **) ((u8 *) player + 0x5C) + 4))++;
    if (*(s32 *) (*(u8 **) ((u8 *) player + 0x5C) + 4) >= 3) {
        *(s32 *) (*(u8 **) ((u8 *) player + 0x5C) + 4) = 0;
    }
}

// Landing ring: two rings of 6 puffs, the second rotated by 30 degrees.
void badust_entrypoint_10(PlayerState *player, f32 y_offset)
{
    f32 angle;
    for (angle = 0.0f; angle < 359.0f; angle += 60.0f)
        badust_entrypoint_6(player, y_offset, angle, 730.0f, 100.0f);
    for (angle = 0.0f; angle < 359.0f; angle += 60.0f)
        badust_entrypoint_6(player, y_offset, func_800136E4(angle + 30.0f), 430.0f, 40.0f);
}

void badust_entrypoint_11(u8 *player)
{
    *(s32 *) ((s8 *) *(u8 **) ((s8 *) player + 0x5C) + 4) = 0;
    *(s8 *) ((s8 *) *(u8 **) ((s8 *) player + 0x5C) + 8) = 0;
    *(s32 *) ((s8 *) *(u8 **) ((s8 *) player + 0x5C) + 0) = 0;
    badust_entrypoint_12(player, 1);
}

void badust_entrypoint_12(player, mode) PlayerState *player;
s32 mode;
{
    ((DustPlayer *) player)->dust->mode = mode;
    switch (mode) {
        case 2:
            func_8009ADF0(player, 3, 1);
            ((DustPlayer *) player)->dust->unk_9 = 0;
            _batimer_set(player, 8, 0.01f);
            break;
        case 3:
            func_8009ADF0(player, 3, 1);
            break;
        case 1:
            func_8009ADF0(player, 3, 0);
    }
}

void badust_entrypoint_13(u8 *player)
{
    s32 mode;

    mode = **(s32 **) ((s8 *) player + 0x5C);
    switch (mode) {
        case 2:
            func_80800010_badust();
            return;
        case 3:
            func_80800008_badust();
    }
}

// TU-NOTE: the overlay .data is defined here in C; values are taken from the ROM.
u32 D_80800CB0_badust[4] = {0xFF, 0xFF, 0xFE, 0x0};
