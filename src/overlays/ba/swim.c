#include "common.h"
#include "playerstate.h"

extern f32 func_8009C150(PlayerState *);
extern f32 func_800964DC(PlayerState *);
extern void bastick_setZoneMax(s32, s32, f32);
extern void func_8009BB24(s32, f32 *);
extern f32 func_800EEF94(f32 *);
extern f32 func_800F10B4(f32, f32, f32, f32, f32);
extern f32 func_8009BFCC(PlayerState *);
extern f32 yaw_get(PlayerState *);
extern f32 func_800D8FF8(void);
extern f32 func_800F0E00(f32, f32);
extern void func_800EF4E4(f32 *, f32, f32, f32, f32, f32);
extern f32 bastick_getX(PlayerState *);
extern void yaw_setVelocityBounded(PlayerState *, f32, f32);
extern void baroll_setIdeal(PlayerState *, f32);
extern f32 yaw_getIdeal(PlayerState *);
extern void yaw_setIdeal(PlayerState *, f32);
extern f32 _bafpctrl_entrypoint_3(PlayerState *);
extern f32 bastick_getY(PlayerState *);
extern f32 func_800F1214(f32, f32, f32);
extern void func_8009BFE4(PlayerState *, f32, f32);
extern void func_8009BF5C(PlayerState *, f32);
void baswim_entrypoint_7();
int baswim_entrypoint_8(s32 param_0, f32 param_1);
int baswim_entrypoint_9(s32 param_0, f32 param_1);

s32 baswim_entrypoint_0()
{
    return 0x8;
}

// True when the player is within 100 units below the surface.
s32 baswim_entrypoint_1(s32 player)
{
    f32 surface_y = func_800964DC(player);
    return surface_y - func_8009C150(player) < 100.0f;
}

int baswim_entrypoint_2(PlayerState *player)
{
    f32 y;

    return func_80096544(player) != 0 &&
           (y = func_8009C150(player)) > func_800964DC(player) - 130.0f;
}

// Paddle selection: 1 or 2 for one button, 3 for both (needs the Fast Swimming ability), 0 for none.
int baswim_entrypoint_3(s32 player)
{
    s32 held_8;
    s32 held_9;
    held_8 = bakey_held(player, 8);
    held_9 = bakey_held(player, 9);
    if (func_800C6E38(0x30) && held_8 && held_9) {
        return 3;
    }
    if (held_9) {
        return 2;
    }
    if (held_8) {
        return 1;
    }
    return 0;
}

void baswim_entrypoint_4()
{
    bastick_resetZones();
}

void baswim_entrypoint_5(s32 player)
{
    bastick_setZoneMax(player, 0, 0.03f);
    bastick_setZoneMax(player, 1, 1.0f);
    baswim_entrypoint_9(player, 0.0f);
    baswim_entrypoint_8(player, 0.0f);
}

void baswim_entrypoint_6(s32 player, s32 enable)
{
    baswim_entrypoint_7(player, enable, 0);
}

// Enters or leaves first-person aiming (Sub-Aqua Egg Aim).
void baswim_entrypoint_7(player, enable, unk_0) s32 player;
s32 enable;
s32 unk_0;
{
    s32 count;
    if (enable != 0) {
        count = 0;
        _bafpctrl_entrypoint_9(player, 1);
        if (_bafpctrl_entrypoint_4(player) == 3) {
            return;
        }
        _bafpctrl_entrypoint_16(player, 2);
        if (!func_800C6E38(0x1F)) {
            count = 1;
        }
        if ((unk_0 == 0) && (func_800A3274(player) == 0xA)) {
            count++;
        }
        if (count != 0) {
            _bafpctrl_entrypoint_11(player, 4, 1);
        }
    } else {
        _bafpctrl_entrypoint_17(player);
        _bafpctrl_entrypoint_9(player, 0);
    }
}

// Sets the speed decay.
int baswim_entrypoint_8(s32 player, f32 decay)
{
    *(f32 *) (0x4 + *(s32 *) (player + 0x134)) = decay;
}

// Sets the forward speed.
baswim_entrypoint_9(s32 player, f32 speed)
{
    *(f32 *) (*(s32 *) (player + 308) + 0) = speed;
}

// Raises the forward speed to at least the given value.
void baswim_entrypoint_10(u8 *player, f32 speed)
{
    f32 *ctrl;

    ctrl = *(f32 **) ((s8 *) player + 0x134);
    if (*ctrl < speed) {
        *ctrl = speed;
    }
}

// Stick X steers roll and yaw.
void baswim_entrypoint_11(PlayerState *player)
{
    f32 yaw_delta;
    f32 yaw_rate;
    f32 max_roll;
    f32 stick_x;
    stick_x = bastick_getX(player);
    yaw_rate = 4.3f;
    max_roll = 45.0f;
    yaw_setVelocityBounded(player, 250.0f, 20.0f);
    baroll_setIdeal(player, func_800F10B4(stick_x, -1.0f, 1.0f, -max_roll, max_roll));
    yaw_delta = func_800F10B4(stick_x, -1.0f, 1.0f, yaw_rate, -yaw_rate);
    yaw_delta *= _bafpctrl_entrypoint_3(player);
    yaw_setIdeal(player, yaw_getIdeal(player) + yaw_delta);
}

f32 func_808003B8_baswim(s32 player)
{
    f32 velocity[3];
    func_8009BB24(player, velocity);
    func_800F10B4(func_800EEF94(velocity), 50.0f, 200.0f, 0.0f, 1.0f);
}

// Stick Y sets the pitch.
void baswim_entrypoint_12(PlayerState *player)
{
    f32 rate;
    f32 input;

    rate = func_800F1214(func_808003B8_baswim(player), 140.0f, 90.0f);
    input = _bafpctrl_entrypoint_3(player);
    rate *= func_800F10B4(input, 0.1f, 1.0f, input * input, 1.0f);
    func_8009BFE4(player, rate, 1.6f);
    input = bastick_getY(player);
    if (input < 0.0f) {
        func_8009BF5C(player, func_800F10B4(input, -1.0f, 0.0f, 275.0f, 360.0f));
    } else {
        func_8009BF5C(player, func_800F10B4(input, 0.0f, 1.0f, 0.0f, 85.0f));
    }
}

// Propels along pitch and yaw by the current speed, then decays the speed.
void baswim_entrypoint_13(PlayerState *player)
{
    f32 pitch;
    f32 velocity[4];
    pitch = func_8009BFCC(player);
    func_800EF4E4(velocity, pitch, yaw_get(player), 0.0f, 0.0f,
                  (*(f32 **) ((u8 *) player + 0x134))[0]);
    (*(f32 **) ((u8 *) player + 0x134))[0] =
        func_800F0E00((*(f32 **) ((u8 *) player + 0x134))[0] -
                          (*(f32 **) ((u8 *) player + 0x134))[1] * func_800D8FF8(),
                      0.0f);
    func_8009B94C(player, velocity);
    func_8009BA9C(player, velocity);
}

f32 baswim_entrypoint_14(u8 *player)
{
    return **(f32 **) ((s8 *) player + 0x134);
}
