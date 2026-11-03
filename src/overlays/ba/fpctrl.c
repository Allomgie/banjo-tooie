#include "common.h"
#include "playerstate.h"
extern void func_800C51A4(s32, f32);

extern void func_800F3E84(PlayerState *, f32 *);
extern f32 func_8009BFCC(PlayerState *);
extern f32 yaw_getIdeal(PlayerState *);
extern f32 baroll_get(PlayerState *);
extern PlayerState *func_800A4CA8(PlayerState *);
extern f32 func_800D8FF8(void);
extern f32 bastick_getY(PlayerState *);
extern f32 bastick_getX(PlayerState *);
extern f32 _bsdronelook_entrypoint_2(f32);
extern void yaw_setIdeal(PlayerState *, f32);
extern void _ncba1p_entrypoint_8(PlayerState *, f32 *);
typedef struct {
    u32 flags;
    u8 pad_4[0x10];
    u8 sub_mode;
    u8 aim_armed;
    u8 aim_entered;
} FpCtrl;
typedef struct {
    u8 pad_0[0x90];
    FpCtrl *ctrl;
} FpOwner;
extern u8 D_808010D0_bafpctrl[];
extern u8 D_808010C0_bafpctrl[];
extern s32 func_8009E674(FpOwner *, s32);
extern void func_8010D930(s32, s32, s32, void *);
extern void _baeggaim_entrypoint_1(FpOwner *);
extern void _baeggaim_entrypoint_2(FpOwner *);
extern s32 func_8009E71C(FpOwner *, s32);
extern s32 func_800C6E38(s32);
extern void func_800F3BD0(s32, s32, f32 *);
extern f32 yaw_get(s32);
extern void func_800EEB9C(f32 *, f32, f32);
extern void func_800EF04C(f32 *, f32 *);
extern u8 D_808010B0_bafpctrl[];
extern s32 D_808010A0_bafpctrl[];
extern void _ncba1p_entrypoint_12(PlayerState *, f32);
extern f32 _ncba1p_entrypoint_11(PlayerState *);
extern void func_800F10B4(f32, f32, f32, f32, f32);
extern s32 baflag_isTrue(PlayerState *, s32);
extern s32 bakey_held(PlayerState *, s32);
extern f32 func_800139F8(f32);
f32 bafpctrl_entrypoint_3();
s32 bafpctrl_entrypoint_4();
s32 bafpctrl_entrypoint_6();
void bafpctrl_entrypoint_9();
void bafpctrl_entrypoint_10();
void bafpctrl_entrypoint_13();
void bafpctrl_entrypoint_14();

s32 bafpctrl_entrypoint_0()
{
    return 0x1C;
}

// Exit condition check for the first-person view.
s32 func_80800008_bafpctrl(PlayerState *player)
{
    if (bakey_pressed(player, 12) && bafpctrl_entrypoint_6(player) &&
        !(**(u32 **) ((u8 *) player + 0x90) & 2))
        return 1;
    if (player_inWater(player)) {
        if (func_8008FD48() == 1 && !func_8008FF94())
            return 1;
    } else {
        if (!func_8008DF8C(player, 0x19)) {
            if (bafpctrl_entrypoint_4(player) != 1)
                return 0;
            return 1;
        }
    }
    return 0;
}

// Stores the field of view and applies the zoom.
void func_808000DC_bafpctrl(s32 player, f32 zoom, f32 fov)
{
    *(f32 *) (*(s32 *) (player + 0x90) + 0x18) = fov;
    func_800C51A4(func_800A4C68(player), zoom);
}

// Button zoom of the field of view (5.21 to 40 degrees).
void func_80800114_bafpctrl(player) PlayerState *player;
{
    f32 fov;

    if (baflag_isTrue(player, 0x3A)) {
        return;
    }
    if (baflag_isTrue(player, 0x2E) || !func_800C6E38(0x2B)) {
        return;
    }
    fov = *(f32 *) (*(u8 **) ((u8 *) player + 0x90) + 0x18);
    if (bakey_held(player, 10) && fov < 40.0f) {
        fov += 1.5f;
    }
    if (bakey_held(player, 13) && 5.21f < fov) {
        fov -= 1.5f;
    }
    func_808000DC_bafpctrl(player, 0.36397022f / func_800139F8(fov * 0.5f), fov);
}

void func_8080022C_bafpctrl(PlayerState *player)
{
    f32 rot[3];
    func_800F3E84(player, rot);
    rot[0] = -func_8009BFCC(player);
    rot[1] = yaw_getIdeal(player) + 180.0f;
    rot[2] = -baroll_get(player);
    _ncba1p_entrypoint_7(func_800A4CA8(player), rot);
}

// Stick look with pitch clamp.
void func_808002A4_bafpctrl(PlayerState *player)
{
    f32 rot[3];
    f32 dt;
    f32 turn_rate;
    if (_ncba1p_entrypoint_10(func_800A4CA8(player)) == 2) {
        _ncba1p_entrypoint_8(func_800A4CA8(player), rot);
        if (!baflag_isTrue(player, 0x25)) {
            dt = func_800D8FF8();
            turn_rate = bafpctrl_entrypoint_3(player) * 90.0f;
            rot[0] -= bastick_getY(player) * turn_rate * dt;
            rot[1] -= bastick_getX(player) * turn_rate * dt;
            rot[2] = 0.0f;
            rot[0] = _bsdronelook_entrypoint_2(rot[0]);
        }
        _ncba1p_entrypoint_7(func_800A4CA8(player), rot);
        yaw_setIdeal(player, rot[1] + 180.0f);
    }
}

void func_808003BC_bafpctrl(PlayerState *player)
{
    f32 rot[3];

    if (_ncba1p_entrypoint_10(func_800A4CA8(player)) == 2) {
        _ncba1p_entrypoint_8(func_800A4CA8(player), rot);
        yaw_setIdeal(player, rot[1] + 180.0f);
    }
}

// Switches the sub-mode (1 = look, 2 = egg aim).
void func_80800424_bafpctrl(FpOwner *player, s32 state)
{
    s32 prev;
    s32 unk_0;
    s32 unk_1;
    s32 neither;
    s32 ability_1b;
    s32 ability_1f;
    s32 ability_16;
    s32 allowed;

    prev = player->ctrl->sub_mode;
    switch (prev) {
        case 0:
            player->ctrl->aim_entered = 0;
            break;
        case 2:
            if (state == 1) {
                func_8010D930(0xC, func_8009E674(player, 2), 0, D_808010D0_bafpctrl);
            }
            _baeggaim_entrypoint_1(player);
    }
    player->ctrl->sub_mode = state;
    switch (state) {
        case 2:
            if (player->ctrl->aim_entered) {
                func_8010D930(0xC, func_8009E674(player, 2), 0, D_808010C0_bafpctrl);
            } else {
                player->ctrl->aim_entered++;
            }
            _baeggaim_entrypoint_2(player);
            break;
        case 1:
            unk_0 = func_8009E71C(player, 9);
            unk_1 = func_8009E71C(player, 0xB);
            neither = (unk_0 == 0) && (unk_1 == 0);
            ability_1b = func_800C6E38(0x1B);
            ability_1f = func_800C6E38(0x1F);
            ability_16 = func_800C6E38(0x16);
            allowed = (unk_0 && ability_1b) || (unk_1 && ability_1f) || (neither && ability_16);
            if (prev == 0 && allowed && !(player->ctrl->flags & 4)) {
                player->ctrl->aim_armed = 1;
            } else {
                player->ctrl->aim_armed = 0;
            }
    }
}

// Computes the first-person camera position into pos.
void func_808005FC_bafpctrl(s32 player, f32 *pos)
{
    f32 forward[3];
    func_800F3BD0(player, 5, pos);
    func_800EEB9C(forward, yaw_get(player), 5.0f);
    func_800EF04C(pos, forward);
}

// Leaves the first-person view.
void func_8080064C_bafpctrl(s32 player)
{
    if (!func_8009CC68(player)) {
        func_8010D930(0xC, func_8009E674(player, 2), 0, D_808010B0_bafpctrl);
    }
    func_80110C2C(func_800A4CA8(player));
    baflag_clear(player, 0x24);
    baflag_clear(player, 0x25);
    baflag_clear(player, 0x2E);
    baflag_clear(player, 0x17);
    baflag_clear(player, 0x3A);
    func_80800424_bafpctrl(player, 0);
    func_808000DC_bafpctrl(player, 1.0f, 40.0f);
}

// Enters the first-person view.
void func_80800704_bafpctrl(PlayerState *player)
{
    f32 pos[3];
    f32 rot[3];
    f32 target[3];

    if (!(**(s32 **) ((u8 *) player + 0x90) & 8)) {
        func_8010D930(0xC, func_8009E674(player, 2), 0, &D_808010A0_bafpctrl);
    }
    func_80110BF0(func_800A4CA8(player));
    func_808005FC_bafpctrl(player, pos);
    _ncba1p_entrypoint_6(func_800A4CA8(player), pos);
    if (baflag_isTrue(player, 0x25)) {
        func_80099A7C(player, target);
        _badrone_entrypoint_33(player, target);
        func_800A516C(rot, target, pos);
    } else {
        func_800F3E84(player, rot);
        rot[0] = 0.0f;
        rot[2] = 0.0f;
        rot[1] += 180.0f;
    }
    _ncba1p_entrypoint_7(func_800A4CA8(player), rot);
    yaw_setIdeal(player, 180.0f + rot[1]);
    if (**(s32 **) ((u8 *) player + 0x90) & 8) {
        yaw_applyIdeal(player);
        _ncba1p_entrypoint_12(func_800A4CA8(player), 0.01f);
    }
    baflag_set(player, 0x17);
    (*(u8 **) ((u8 *) player + 0x90))[0x14] = 0;
    func_80800424_bafpctrl(player, 1);
}

void func_80800880_bafpctrl(u8 *player)
{
    if (**(s32 **) ((s8 *) player + 0x90) & 1) {
        _ncba1p_entrypoint_7(func_800A4CA8(player), *(s32 **) ((s8 *) player + 0x90) + 1,
                             player);
    }
}

void func_808008CC_bafpctrl(s32 player)
{
    // Matching: needed for the match.
    s8 _sfpad[8];
    s32 pos;
    func_808005FC_bafpctrl(player, &pos);
    _ncba1p_entrypoint_6(func_800A4CA8(player), &pos);
}

int func_80800904_bafpctrl(PlayerState *player)
{
    return bakey_pressed(player, 0xB) && func_800C6E38(0x16) && bafpctrl_entrypoint_6(player) &&
           !(**(u32 **) ((u8 *) player + 0x90) & 4);
}

// Per-frame update. Returns 1 when the first-person view should end.
s32 func_80800970_bafpctrl(player)
PlayerState *player;
{
    s32 result;
    u8 sub_mode;

    result = 0;
    sub_mode = *(u8 *) ((s8 *) *(u8 **) ((s8 *) player + 0x90) + 0x14);
    switch (sub_mode) {
        case 1:
            if ((func_80800904_bafpctrl(player) != 0) || (baflag_isTrue(player, 0x24) != 0)) {
                *(u8 *) ((s8 *) *(u8 **) ((s8 *) player + 0x90) + 0x15) = 1U;
            }
            if ((*(u8 *) ((s8 *) *(u8 **) ((s8 *) player + 0x90) + 0x15) != 0) &&
                (_baeggcursor_entrypoint_2(player) == 1) &&
                (_ncba1p_entrypoint_11(func_800A4CA8(player)) < 0.25f)) {
                func_80800424_bafpctrl(player, 2);
            } else if ((func_80800008_bafpctrl(player) != 0) &&
                       (_ncba1p_entrypoint_10(func_800A4CA8(player)) == 2)) {
                result = 1;
            } else if (bafpctrl_entrypoint_6(player) != 0) {
                if (*(u8 *) ((s8 *) *(u8 **) ((s8 *) player + 0x90) + 0x11) != 0) {
                    func_8080022C_bafpctrl(player);
                } else {
                    func_808002A4_bafpctrl(player);
                }
                func_80800880_bafpctrl(player);
                func_808008CC_bafpctrl(player);
            }
            break;
        case 2:
            func_80094AB4(player);
            if ((func_80800904_bafpctrl(player) != 0) &&
                (_baeggcursor_entrypoint_2(player) == 2)) {
                if (baflag_isTrue(player, 0x24) != 0) {
                    result = 1;
                } else {
                    func_80800424_bafpctrl(player, 1);
                }
            } else if (func_80800008_bafpctrl(player) != 0) {
                result = 1;
            } else if (bafpctrl_entrypoint_6(player) != 0) {
                if (*(u8 *) ((s8 *) *(u8 **) ((s8 *) player + 0x90) + 0x11) != 0) {
                    func_8080022C_bafpctrl(player);
                } else {
                    func_808003BC_bafpctrl(player);
                }
                func_808008CC_bafpctrl(player);
                func_80800880_bafpctrl(player);
                _baeggaim_entrypoint_3(player);
            }
    }
    func_80800114_bafpctrl(player);
    return result;
}

s32 bafpctrl_entrypoint_1(s32 player)
{
    return ((u8 *) *(u8 **) (player + 0x90))[0x11];
}

s32 bafpctrl_entrypoint_2(s32 player)
{
    return (*(u8 **) (player + 0x90))[18];
}

// Look sensitivity scale from the current field of view.
f32 bafpctrl_entrypoint_3(player)
u8 *player;
{
    func_800F10B4(*(f32 *) (*(u8 **) (player + 0x90) + 0x18), 10.0f, 40.0f, 0.2f, 1.0f);
}

// Returns the main mode (1 = off, 2 = available, 3 = active).
s32 bafpctrl_entrypoint_4(player)
s32 player;
{
    return *(u8 *) (*(s32 *) (player + 0x90) + 0x10);
}

int bafpctrl_entrypoint_5(Actor *player)
{
    return (*((u8 *) (((char *) (*((s32 **) (((char *) player) + 0x90)))) + 0x14))) == 2;
}

s32 bafpctrl_entrypoint_6(player)
s32 player;
{
    return ((u8 *) (*(u8 **) (player + 0x90)))[0x13];
}

void bafpctrl_entrypoint_7(s32 arg0)
{
}
void bafpctrl_entrypoint_8(u8 *player)
{
    *(s8 *) ((char *) *(u8 **) ((char *) player + 0x90) + 0x10) = 0;
    bafpctrl_entrypoint_14(player, 1);
    func_800EFD24(*(u8 **) ((char *) player + 0x90) + 4);
    *(s32 *) ((char *) *(u8 **) ((char *) player + 0x90) + 0) = 0;
    bafpctrl_entrypoint_9(player, 0);
    bafpctrl_entrypoint_10(player, 0);
    bafpctrl_entrypoint_13(player, 1);
    *(f32 *) ((char *) *(u8 **) ((char *) player + 0x90) + 0x18) = 40.0f;
}

void bafpctrl_entrypoint_9(player, value) void *player;
s32 value;
{
    ((s8 *) (*(void **) ((char *) player + 0x90)))[17] = value;
}

void bafpctrl_entrypoint_10(player, value) void *player;
s32 value;
{
    ((s8 *) (*(void **) ((char *) player + 0x90)))[18] = value;
}

// Sets or clears the mask bits in the flags word.
void bafpctrl_entrypoint_11(int player, int mask, int set)
{
    int *flags;

if (set != 0) {
    flags = *(int **) (player + 0x90);
    *flags |= mask;
} else {

flags = *(int **) (player + 0x90);
*flags &= ~mask;
}
}

int bafpctrl_entrypoint_12(Actor *player)
{
    func_800EE7F8(*(s32 *) ((char *) player + 0x90) + 4);
}

void bafpctrl_entrypoint_13(player, enabled) void *player;
s32 enabled;
{
    *(s8 *) (*(s32 *) ((char *) player + 0x90) + 0x13) = enabled;
    _baeggcursor_entrypoint_6(player);
}

// Sets the main mode (1 = off, 2 = available, 3 = active).
void bafpctrl_entrypoint_14(player, mode) PlayerState *player;
s32 mode;
{
    switch ((*(u8 **) ((u8 *) player + 0x90))[0x10]) {
        case 1:
            if (mode == 1)
                return;
            break;
        case 3:
            func_8080064C_bafpctrl(player);
    }
    (*(u8 **) ((u8 *) player + 0x90))[0x10] = mode;
    switch (mode) {
        case 1:
            bafpctrl_entrypoint_9(player, 0);
            bafpctrl_entrypoint_10(player, 0);
            **(s32 **) ((u8 *) player + 0x90) = 0;
            func_8009ADF0(player, 7, 0);
            break;
        case 2:
            func_8009ADF0(player, 7, 1);
            break;
        case 3:
            func_8009ADF0(player, 7, 1);
            func_80800704_bafpctrl(player);

}
}

int func_80800E30_bafpctrl(player)
u8 *player;
{
    return bakey_pressed(player, 12) && bafpctrl_entrypoint_6(player) &&
           func_800F6774(*(void **) (player + 0x184)) &&
           _ncba1p_entrypoint_10(func_800A4CA8(player)) != 3;
}

void bafpctrl_entrypoint_15(u8 *player)
{
    u8 mode;

    mode = *(u8 *) ((s8 *) *(u8 **) ((s8 *) player + 0x90) + 0x10);
    switch (mode) {
        case 2:
            if (func_80800E30_bafpctrl() != 0) {
                bafpctrl_entrypoint_14(player, 3);
            }

case 1:
    return;

case 3:
    if (func_80800970_bafpctrl() != 0) {
        bafpctrl_entrypoint_14(player, 2);
    }

}
}

void bafpctrl_entrypoint_16(u8 *player)
{
    u8 *ctrl = *(u8 **) (player + 0x90);
    if (ctrl[0x13] && ctrl[0x10] != 3) {
        bafpctrl_entrypoint_14(player);
    }
}

void bafpctrl_entrypoint_17(u8 *player)
{
    if ((*(u8 **) (player + 0x90))[0x13] != 0) {
        bafpctrl_entrypoint_14(player, 1);
    }
}

int bafpctrl_entrypoint_18(s32 player, s32 enable)
{
    // Matching: the `| 0` and the extra copy are needed for the match.
    u32 player_copy = player | 0;
    if (enable != 0) {
        bafpctrl_entrypoint_14((player | 0) | 0, 2);
        bafpctrl_entrypoint_9(player | 0, 1);
        bafpctrl_entrypoint_10(player | 0, 1);
        func_800947EC(player_copy, 1, 1);
        func_800947EC(player | 0, 2, 1);
    } else {
        bafpctrl_entrypoint_14(player | 0, 1);
        func_800947EC(player | 0, 1, 0);
        func_800947EC(player | 0, 2, 0);
    }
}

void bafpctrl_entrypoint_19(void *player)
{
    if (bafpctrl_entrypoint_4() == 3) {
        bafpctrl_entrypoint_14(player, 1);
        func_800A3544(player, 0);
        func_8009337C(player, 1);
        func_800A4EC8(player);
        _plcamera_entrypoint_0(((int *) player)[0x61]);
    }
}

// TU-NOTE: the .data of this overlay is defined here in C (values taken from the ROM).
// The extern declarations match the object at the same addresses; D_808010A0_bafpctrl is an s32[].
s32 D_808010A0_bafpctrl[4] = {0x130487, 0xA0133, 0x162EE0, 0x0};
u8 D_808010B0_bafpctrl[16] = {0x0, 0x13, 0x4,  0x88, 0x0, 0xA, 0x1, 0x33,
                              0x0, 0x16, 0x2E, 0xE0, 0x0, 0x0, 0x0, 0x0};
u8 D_808010C0_bafpctrl[16] = {0x0, 0x13, 0x4,  0x6B, 0x0, 0xA, 0x1, 0x66,
                              0x0, 0x16, 0x27, 0x10, 0x0, 0x0, 0x0, 0x0};
u8 D_808010D0_bafpctrl[16] = {0x0, 0x13, 0x4,  0x6C, 0x0, 0xA, 0x1, 0x66,
                              0x0, 0x16, 0x27, 0x10, 0x0, 0x0, 0x0, 0x0};
