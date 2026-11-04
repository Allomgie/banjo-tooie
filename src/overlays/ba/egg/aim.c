// First-person egg aiming: moves the cursor toward the stick position with smoothing, turns the
// camera at the screen edge and fires the selected egg on B (hold for golden/auto eggs).
#include "common.h"
#include "overlays/ba/playerstate.h"

extern f32 bastick_getX(PlayerState *);
extern f32 bastick_getY(PlayerState *);
extern void _baeggcursor_entrypoint_10(PlayerState *, f32, f32);
extern f32 func_800F1344(f32, f32, f32, f32, f32);
extern PlayerState *func_800A4CA8(PlayerState *);
extern void _ncba1p_entrypoint_8(PlayerState *, f32 *);
extern void _ncba1p_entrypoint_7(PlayerState *, f32 *);
extern f32 _bafpctrl_entrypoint_3(PlayerState *);
extern f32 func_800D8FF8(void);
extern f32 _bsdronelook_entrypoint_2(f32);
extern u32 func_800D8FEC(void);
extern f32 func_800F0DC0(f32, f32);

s32 baeggaim_entrypoint_0()
{
    return 0x4;
}

// Frame-rate independent smoothing of value toward target
f32 func_80800008_baeggaim(f32 value, f32 target, f32 speed)
{
    s32 i;
    for (i = 0; i < (s32) (func_800D8FEC() * 5); i++) {
        value += func_800F0DC0((target - value) * 0.04f, speed);
    }
    return value;
}

// Moves the screen cursor toward the stick position
void func_808000B4_baeggaim(PlayerState *player, f32 *cursor)
{
    f32 target_x;
    f32 target_y;
    _baeggcursor_entrypoint_3(player, cursor, cursor + 1);
    target_x = bastick_getX(player) * 114.0f + 114.0f + 38.0f;
    target_y = bastick_getY(player) * 85.5f + 85.5f + 28.5f;
    cursor[0] = func_80800008_baeggaim(cursor[0], target_x, 7.4f);
    cursor[1] = func_80800008_baeggaim(cursor[1], target_y, 5.5f);
    _baeggcursor_entrypoint_10(player, cursor[0], cursor[1]);
}

// Camera turn rate from how far the cursor is inside the screen edge zone
void func_80800170_baeggaim(f32 *cursor, f32 *turn, f32 scale)
{
    f32 dist;
    f32 edge_x;
    f32 edge_y;

    edge_y = 0;
    edge_x = 0;
    dist = 78.0f - cursor[0];
    if (dist > 0.0f)
        edge_x = dist;
    dist = 226.0f - cursor[0];
    if (dist < 0.0f)
        edge_x = dist;
    dist = 61.0f - cursor[1];
    if (dist > 0.0f)
        edge_y = dist;
    dist = 167.0f - cursor[1];
    if (dist < 0.0f)
        edge_y = dist;
    turn[0] = func_800F1344(edge_x, 0, 40.0f, 0.0f, scale);
    turn[1] = func_800F1344(edge_y, 0, 32.5f, 0.0f, scale);
}

// Turns the first-person camera when the cursor is in the edge zone
void func_80800264_baeggaim(PlayerState *player, PlayerState *cursor)
{
    s32 pad;
    f32 scale;
    f32 cam_rot[3];
    f32 turn[2];
    PlayerState *camera;

    camera = func_800A4CA8(player);
    _ncba1p_entrypoint_8(camera, cam_rot);
    scale = _bafpctrl_entrypoint_3(player) * 70.0f;
    func_80800170_baeggaim(cursor, turn, scale);
    scale = func_800D8FF8();
    cam_rot[1] += turn[0] * scale;
    if (!baflag_isTrue(player, 0x3A)) {
        cam_rot[0] += turn[1] * scale;
        cam_rot[0] = _bsdronelook_entrypoint_2(cam_rot[0]);
    }
    cam_rot[2] = 0.0f;
    _ncba1p_entrypoint_7(camera, cam_rot);
}

void baeggaim_entrypoint_1(s32 player)
{
    _baeggcursor_entrypoint_7(player, 0x4);
    _baeggfire_entrypoint_4(player);
}

void baeggaim_entrypoint_2(s32 player)
{
    _baeggcursor_entrypoint_7(player, 0x3);
    _baeggfire_entrypoint_5(player);
}

void baeggaim_entrypoint_3(s32 player)
{
    f32 cursor[2];
    s32 fire;

    if (_bafpctrl_entrypoint_2() == 0) {
        func_80094AB4(player);
    }
    func_808000B4_baeggaim(player, cursor);
    if ((baflag_isTrue(player, 0x2E) == 0) && (_bafpctrl_entrypoint_1(player) == 0)) {
        func_80800264_baeggaim(player, cursor);
    }
    // B press fires; golden/auto eggs fire while held
    fire = 0;
    if (func_80094510(player) == 7) {
        if (bakey_held(player, 1) != 0) {
            fire = 1;
        }
    } else if (bakey_pressed(player, 1) != 0) {
        fire = 1;
    }
    if ((fire != 0) && (_bafpctrl_entrypoint_2(player) == 0) && (func_80094B14(player) != 0)) {
        _baeggfire_entrypoint_7(player);
    }
    _baeggfire_entrypoint_6(player);
}
