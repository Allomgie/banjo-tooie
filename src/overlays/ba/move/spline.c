// Spline mover (baphysics type 0x12): snaps the player to a spline path (claw-clamber walls),
// moves along it with the stick or approaches its start, and exposes progress and end queries.

#include "common.h"
#include "overlays/ba/playerstate.h"

extern void func_800EEB9C(f32 *, f32, f32);
extern f32 func_800D8840(s32);
extern f32 func_800D8FF8(void);
extern void func_800EFA20(f32 *, f32 *, f32);
extern void func_800EF334(f32 *, f32);
extern void func_800F2168(f32 *, f32);
typedef struct {
    u8 pad_0[0x90];
    u8 state;
    u8 unk_91;
    u8 unk_92;
    u8 pad_93[9];
    f32 start_pos[3];
    f32 step;
} MoveSplineState;
typedef struct {
    u8 pad_0[0xC8];
    MoveSplineState *data;
} MoveSplinePlayer;
extern void func_800C810C(void *param_0, void *param_1, void *param_2, void *param_3);
extern void func_800EFA4C(s32 param_0, float param_1, float param_2, float param_3);
typedef struct {
    u8 pad_0[0x90];
    u8 state;
    u8 pad_91[3];
    s16 path;
    u8 pad_96[2];
    f32 progress;
    u8 pad_9C[0xC];
    f32 step;
} MoveSplineEndpoint;
extern void *func_800D7520();
extern void func_800C7A68(void *, f32, f32 *);
extern f32 func_800EEB40(f32 *, f32 *);
extern void func_800EE7F8(f32 *, f32 *);
extern void func_800EF04C(f32 *, f32 *);
extern void func_800EFB24(f32 *, f32 *, f32 *);
extern f32 func_800F1DF4(f32 *, f32 *);
extern f32 func_800F1DCC(f32, f32);
extern f32 func_800136E4(f32);
extern f32 mlAbsF(f32);
extern f32 func_800EEFFC();
extern f32 func_800EEAD4(f32 *, f32 *);
extern f32 bastick_getAngleRelativeToBanjo(void *);
extern void func_800EF368(f32 *, f32);
typedef struct {
    u8 pad0[4];
    f32 pos[3];
    f32 vel[3];
    u8 pad1C[0xC];
    f32 delta[3];
    u8 pad34[0x5D];
    u8 unk91;
    u8 unk92;
    u8 pad93;
    s16 path;
    u8 pad96[2];
    f32 progress;
    u8 pad9C[0xC];
    f32 step;
} SplineMove;
extern f32 bastick_distance(PlayerState *);
extern f32 bastick_getAngle(PlayerState *);
extern void baphysics_set_target_yaw(PlayerState *, f32);
extern f32 func_8009BB18(PlayerState *);
extern f32 func_800C7FD4(void *, f32, f32);
typedef struct {
    u8 pad_0[0x90];
    u8 state;
    u8 pad_1[3];
    s16 path;
    u8 pad_2[2];
    f32 progress;
} SplineMoveProgress;
typedef struct {
    u8 pad_0[0xC8];
    SplineMoveProgress *data;
} SplineMovePlayer;
extern f32 func_800C82CC(void *, f32 *);

void func_80800000_bamovespline(PlayerState *player)
{
    f32 unk_0[3];
    f32 unk_1[3];
    f32 horiz_vel[3];
    f32 dir[3];

    func_800EEB9C((f32 *) (*(u8 **) ((u8 *) player + 0xC8) + 0x1C),
                  *(f32 *) (*(u8 **) ((u8 *) player + 0xC8) + 0x40),
                  *(f32 *) (*(u8 **) ((u8 *) player + 0xC8) + 0x3C));
    horiz_vel[0] = *(f32 *) (*(u8 **) ((u8 *) player + 0xC8) + 0x10);
    horiz_vel[1] = 0.0f;
    horiz_vel[2] = *(f32 *) (*(u8 **) ((u8 *) player + 0xC8) + 0x18);
    func_800EE7F8(dir, (f32 *) (*(u8 **) ((u8 *) player + 0xC8) + 0x1C));
    dir[1] = 0.0f;
    func_800EFA20(unk_0, dir, func_800D8840(2));
    func_800EFA20(unk_1, horiz_vel, func_800D8840(2));
    func_800EF3DC(unk_0, unk_1);
    func_800EF334(unk_0, func_800D8FF8() * 30.0f);
    func_800EF04C((f32 *) (*(u8 **) ((u8 *) player + 0xC8) + 0x10), unk_0);
    func_800F2168((f32 *) (*(u8 **) ((u8 *) player + 0xC8) + 0x10), 0.0001f);
}

void func_808000F4_bamovespline(PlayerState *player, s32 state)
{
    switch (state) {
        case 1:
            ((MoveSplinePlayer *) player)->data->unk_91 = 0;
            ((MoveSplinePlayer *) player)->data->unk_92 = 0;
            ((MoveSplinePlayer *) player)->data->step = 0.0f;
            break;
        case 3:
            func_8009C128(player, ((MoveSplinePlayer *) player)->data->start_pos);
        case 2:
        case 4:
            break;
    }
    ((MoveSplinePlayer *) player)->data->state = state;
}

void bamovespline_entrypoint_0(u8 *player, s32 tangent)
{
    // Matching: the padding locals are needed for the match.
    s8 _sfpad[8];
    s32 pad0;
    s32 unk_0;
    u8 *data;

    data = *(u8 **) ((s8 *) player + 0xC8);
    if (*(u8 *) ((s8 *) data + 0x90) == 4) {
        func_800C810C(func_800D7520(*(s16 *) ((s8 *) data + 0x94)),
                      *(s32 *) ((s8 *) *(u8 **) ((s8 *) player + 0xC8) + 0x98), tangent, &unk_0);
        return;
    }
    func_800EFA4C(tangent, 0, 1.0f, 0);
}

// True while moving backward within radius of the path start.
s32 bamovespline_entrypoint_1(PlayerState *player, f32 radius)
{
    void *spline;
    f32 cur_pos[3];
    f32 start_pos[3];

    if ((*(MoveSplineEndpoint **) ((u8 *) player + 0xC8))->state != 4)
        return 0;
    if ((*(MoveSplineEndpoint **) ((u8 *) player + 0xC8))->step >= 0.0f)
        return 0;
    spline = func_800D7520((*(MoveSplineEndpoint **) ((u8 *) player + 0xC8))->path);
    func_800C7A68(spline, (*(MoveSplineEndpoint **) ((u8 *) player + 0xC8))->progress, cur_pos);
    func_800C7A68(spline, 0.0f, start_pos);
    return func_800EEB40(cur_pos, start_pos) < radius * radius;
}

s32 bamovespline_entrypoint_2(s32 player)
{
    // Matching: the address temporary is needed for the match.
    int player_addr;
    player_addr = player;
    player_addr = player_addr + 0xC8;
    return ((u8 *) *(int **) player_addr)[0x91];
}

s32 bamovespline_entrypoint_3(s32 player)
{
    return ((u8 *) ((s32 *) player)[0x32])[0x92];
}

s32 bamovespline_entrypoint_4(u8 *player)
{
    return *(u8 *) ((s8 *) *(u8 **) ((s8 *) player + 0xC8) + 0x90) == 4;
}

void bamovespline_entrypoint_5(s32 player)
{
}

void bamovespline_entrypoint_6(void *player)
{
    *(s8 *) (*(s32 **) ((char *) player + 0xC8) + (0x90 / 4)) = 0;
    func_808000F4_bamovespline(player, 1);
}

void bamovespline_entrypoint_7(void *player, s32 path)
{
    ((s16 *) *(void **) ((char *) player + 0xC8))[74] = path;
}

void bamovespline_entrypoint_8(s32 player)
{
    func_808000F4_bamovespline(player, 0x2);
}

void bamovespline_entrypoint_9(u8 *player, f32 progress)
{
    *(f32 *) (*(u8 **) (player + 0xC8) + 0x98) = progress;
    func_808000F4_bamovespline(player, 4);
}

// Approach phase: moves from the start position to the spline point, then enters state 4.
void func_80800374_bamovespline(void *player)
{
    f32 step;
    f32 stick_diff;
    f32 path_yaw;
    f32 yaw_diff;
    f32 path_pos[3];
    f32 start_pos[3];
    void *spline;
    f32 flipped_yaw;

    spline = func_800D7520(*(s16 *) (*(u8 **) ((u8 *) player + 0xC8) + 0x94));
    func_800EE7F8(start_pos, *(u8 **) ((u8 *) player + 0xC8) + 0x9C);
    func_800C7A68(spline, *(f32 *) (*(u8 **) ((u8 *) player + 0xC8) + 0x98), path_pos);
    path_yaw = func_800F1DF4(start_pos, path_pos);
    if (bastick_distance(player) != 0.0f) {
        stick_diff = func_800F1DCC(path_yaw, bastick_getAngleRelativeToBanjo(player));
        if (mlAbsF(stick_diff) < 90.0f) {
            baphysics_set_target_yaw(player, path_yaw);
        } else {
            flipped_yaw = func_800136E4(path_yaw + 180.0f);
            baphysics_set_target_yaw(player, flipped_yaw);
        }
    }
    func_80800000_bamovespline(player);
    yaw_diff = func_800F1DCC(path_yaw, *(f32 *) (*(u8 **) ((u8 *) player + 0xC8) + 0x40));
    *(*(u8 **) ((u8 *) player + 0xC8) + 0x92) = mlAbsF(yaw_diff) > 40.0f;
    step = func_800EEFFC((f32 *) (*(u8 **) ((u8 *) player + 0xC8) + 0x10)) * func_800D8FF8();
    *(f32 *) (*(u8 **) ((u8 *) player + 0xC8) + 0xA8) = step;
    func_800EFB24(*(u8 **) ((u8 *) player + 0xC8) + 0x28, path_pos, start_pos);
    func_800EF368(*(u8 **) ((u8 *) player + 0xC8) + 0x28, step);
    if (mlAbsF(yaw_diff) > 90.0f) {
        func_800EF334((f32 *) (*(u8 **) ((u8 *) player + 0xC8) + 0x28), -1.0f);
    }
    func_800EF04C(*(u8 **) ((u8 *) player + 0xC8) + 4, *(u8 **) ((u8 *) player + 0xC8) + 0x28);
    if (func_800EEAD4(path_pos, start_pos) <
        func_800EEAD4((f32 *) (*(u8 **) ((u8 *) player + 0xC8) + 4), start_pos)) {
        func_808000F4_bamovespline(player, 4);
    }
}

// Moves along the spline with the stick and updates the end flags.
void func_8080057C_bamovespline(PlayerState *player)
{
    f32 step;
    f32 prev_pos[3];
    void *spline;

    if (bastick_distance(player) != 0.0f) {
        baphysics_set_target_yaw(player, bastick_getAngle(player));
    }
    func_80800000_bamovespline(player);
    spline = func_800D7520((*(SplineMove **) ((u8 *) player + 0xC8))->path);
    func_800C7A68(spline, (*(SplineMove **) ((u8 *) player + 0xC8))->progress, prev_pos);
    step = func_800EEFFC((*(SplineMove **) ((u8 *) player + 0xC8))->vel);
    if (func_8009BB18(player) > 180.0f) {
        step = -step;
    }
    (*(SplineMove **) ((u8 *) player + 0xC8))->progress =
        func_800C7FD4(spline, (*(SplineMove **) ((u8 *) player + 0xC8))->progress, step);
    (*(SplineMove **) ((u8 *) player + 0xC8))->step = step;
    (*(SplineMove **) ((u8 *) player + 0xC8))->unk91 =
        (step > 0.0f) && ((*(SplineMove **) ((u8 *) player + 0xC8))->progress == 1.0f);
    (*(SplineMove **) ((u8 *) player + 0xC8))->unk92 =
        (step < 0.0f) && ((*(SplineMove **) ((u8 *) player + 0xC8))->progress == 0);
    func_800C7A68(spline, (*(SplineMove **) ((u8 *) player + 0xC8))->progress,
                  (*(SplineMove **) ((u8 *) player + 0xC8))->pos);
    func_800EFB24((*(SplineMove **) ((u8 *) player + 0xC8))->delta,
                  (*(SplineMove **) ((u8 *) player + 0xC8))->pos, prev_pos);
}

void bamovespline_entrypoint_10(PlayerState *player)
{
    f32 pos[3];
    void *spline;
    f32 progress;
    switch (((SplineMovePlayer *) player)->data->state) {
        case 2:
            func_8009C128(player, pos);
            spline = func_800D7520(((SplineMovePlayer *) player)->data->path);
            progress = func_800C82CC(spline, pos);
            ((SplineMovePlayer *) player)->data->progress = progress;
            func_808000F4_bamovespline(player, 3);
            break;
        case 3:
            func_80800374_bamovespline(player);
            break;
        case 4:
            func_8080057C_bamovespline(player);
            break;
    }
}
