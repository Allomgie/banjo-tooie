#include "common.h"
// TU-NOTE: the .data of this overlay is defined here in C; values come from the ROM.

extern u8 *_gccubesearch_entrypoint_14(s32, s32);
extern f32 func_800EFC7C(f32 *, f32 *);
extern f32 func_800F1DF4(f32 *, f32 *);
extern void func_800EEB9C(f32 *, f32, f32);

// Locks control of every live player; forces state if nonzero.
int subaddiemulti_entrypoint_0(s32 state)
{
    s32 player;
    for (player = 0; player < 8; player++) {
        if (func_800F6438(player)) {
            func_800F82D4(player, 2);
            if (state) {
                func_800F608C(player, state);
            }
        }
    }
}

// Like entry 0, passing unk_1 to the lock call.
int subaddiemulti_entrypoint_1(s32 state, s32 unk_1)
{
    s32 player;
    for (player = 0; player < 8; player++) {
        if (func_800F6438(player)) {
            func_800F8300(player, 2, unk_1);
            if (state != 0) {
                func_800F608C(player, state);
            }
        }
    }
}

// Releases control of every live player.
s32 subaddiemulti_entrypoint_2(void)
{
    s32 player;
    for (player = 0; player < 8; player++) {
        if (func_800F6438(player)) {
            func_800F82D4(player, 0);
        }
    }
}

// Places each live player at successive markers starting at marker_index, with the marker yaw,
// and snaps their cameras.
void subaddiemulti_entrypoint_3(s32 marker_index)
{
    s32 player;
    u8 *marker;
    f32 pos[3];
    f32 rot[3];

    func_800EFD24(rot);
    for (player = 0; player < 8; player++) {
        if (func_800F6438(player)) {
            marker = _gccubesearch_entrypoint_14(marker_index, 0);
            func_800EE88C(pos, marker);
            rot[1] = (f32) (*(u32 *) (marker + 12) >> 23);
            func_800F8294(player, pos);
            func_800F832C(player, rot);
            _plcamera_entrypoint_8(player);
        }
        marker_index++;
    }
}

// Sets a fixed camera for every live player.
int subaddiemulti_entrypoint_4(s32 camera)
{
    s32 player;
    for (player = 0; player < 8; player++) {
        if (func_800F6438(player)) {
            _ncfixposrot_entrypoint_8(func_800F5EF8(player), camera);
        }
    }
}

// Returns the owner player of an egg or projectile.
u32 subaddiemulti_entrypoint_5(u8 *obj)
{
    if (_sueggmisc_entrypoint_0() != 0) {
        return _suegg_entrypoint_7(obj);
    }
    if (((u32) *(u32 *) ((char *) obj + 0x24) >> 0x16) == 0) {
        // Matching: the repeated masks are needed for the match.
        return (((((((((((u16) *(u16 *) ((char *) obj + 0x1A) & 0xFFFFFFFFu) & 0xFFFFFFFFu) &
                       0xFFFFFFFFu) &
                      0xFFFFFFFFu) &
                     0xFFFFFFFFu) &
                    0xFFFFFFFFu) &
                   0xFFFFFFFFu) &
                  0xFFFFFFFFu) &
                 0xFFFFFFFFu) &
                0xFFFFFFFFu) >>
               5;
    }
    return func_800F54E4(obj);
}

// Pushes every live player out of the radius (given squared) around center.
void subaddiemulti_entrypoint_6(f32 *center, f32 radius_sq)
{
    s32 player;
    f32 pos[3];
    f32 height;
    f32 angle;

    for (player = 0; player < 8; player++) {
        if (func_800F6438(player)) {
            func_800F5A00(player, pos);
            if (radius_sq < func_800EFC7C(center, pos)) {
                height = pos[1];
                angle = func_800F1DF4(center, pos);
                func_800EEB9C(pos, angle, sqrtf(radius_sq));
                func_800EF04C(pos, center);
                pos[1] = height;
                func_800F8418(player, pos);
            }
        }
    }
}
