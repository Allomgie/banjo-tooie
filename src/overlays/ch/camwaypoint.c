// Placed camera waypoint actor: when the player is in range and the camera is in mode 2, it feeds
// its position and direction into the waypoint camera mode (nc/ba/waypoint).
#include "common.h"

extern int D_80800130_chcamwaypoint[];
extern void func_800EEBF0(f32 *, f32 *, f32);
extern f32 func_800EEAA4(f32 *, f32 *);
extern void *func_80110014(s32);
extern s32 func_800EFFB4(f32 *, f32, f32 *);
extern void _ncbawaypoint_entrypoint_2(void *, f32 *, f32 *, f32);

int chcamwaypoint_entrypoint_0()
{
    return (int) &D_80800130_chcamwaypoint;
}

void func_8080000C_chcamwaypoint(Actor *actor)
{
    func_800EEBF0((f32 *) actor->actorData, actor->rotation, 1.0f);
    *(f32 *) &actor->actorData[3] = func_800EEAA4(actor->position, (f32 *) actor->actorData);
}

// Feeds position and direction to the waypoint camera mode when the player is in range and the camera is in mode 2.
void func_8080005C_chcamwaypoint(Actor *actor)
{
    void *cam;
    s32 player;
    f32 radius;
    f32 player_pos[3];

    player = func_8008FFE8();
    if (func_8010FAE4(player) == 2) {
        cam = func_80110014(player);
        radius = (f32) ((s32) actor->unk74_7 * 10);
        func_8008FE68(player_pos);
        if (!func_800EFFB4(actor->position, radius, player_pos)) {
            func_801107F0(cam, player_pos);
            if (!func_800EFFB4(actor->position, radius, player_pos))
                return;
        }
        _ncbawaypoint_entrypoint_2(cam, actor->position, (f32 *) actor->actorData,
                                   *(f32 *) &actor->actorData[3]);
    }
}

// TU-NOTE: the table below holds pointers to functions of this file; IDO's assembler schedules
// some of them differently unless it is defined in the same unit. Values are taken from the ROM.
extern void func_80102EC0();
extern void func_8010A730();
extern void func_80107C2C();
int D_80800130_chcamwaypoint[20] = {0x15801DD,
                                    0x1,
                                    0x0,
                                    (u32) func_8080005C_chcamwaypoint,
                                    (u32) func_80102EC0,
                                    (u32) func_8010A730,
                                    0x0,
                                    0x0,
                                    0x0,
                                    0x0,
                                    0x0,
                                    0x0,
                                    0x0,
                                    (u32) func_8080000C_chcamwaypoint,
                                    (u32) func_80107C2C,
                                    -0x7FFFD9FE,
                                    0x0,
                                    0x0,
                                    0x0,
                                    0x0};
