#include "common.h"

extern f32 func_800EEF94();
extern void func_800EF368(f32 *, f32);
extern f32 func_800D8FF8(void);
extern void func_800EF04C(f32 *, f32 *);
extern void func_800EFB24(f32 *, f32 *, f32 *);
// Homing state of a projectile. The layout is shared with MissileS.
typedef struct {
    u8 pad_0;
    s8 target_player;
    u8 pad_2[2];
    f32 turn_rate;
    u8 track_actor;
    u8 track_player;
    u8 turn_mode;
    u8 pad_B;
    u8 link[1];
} MissileHomeTarget;
extern Actor *_subaddielink_entrypoint_4(void *);
typedef struct {
    s8 player_index;
    s8 target_player;
    s8 pad_2[2];
    f32 turn_rate;
    s8 track_actor;
    s8 track_player;
    s8 turn_mode;
    s8 pad_B;
    u8 link[4];
} MissileS;
extern void _subaddielink_entrypoint_0();

void sumissilehome_entrypoint_0(s32 projectile, MissileS *homing)
{
    homing->track_actor = 0;
    homing->track_player = 0;
    homing->player_index = -1;
    homing->target_player = -1;
    homing->turn_rate = 6000.0f;
    homing->turn_mode = 2;
    _subaddielink_entrypoint_0(homing->link, homing);
}

// Starts tracking an actor.
void sumissilehome_entrypoint_1(s32 projectile, u8 *homing, unsigned long unk_2)
{
    *(u8 *) (homing + 8) = 1;
    *(s16 *) (homing + 2) = unk_2;
}

// Limits the turn per frame to turn_rate.
void sumissilehome_entrypoint_2(void *projectile, void *homing, float turn_rate)
{
    *(u8 *) ((char *) homing + 0xA) = 1;
    *(f32 *) ((char *) homing + 4) = turn_rate;
}

// Sets the player index used for the target search.
s32 sumissilehome_entrypoint_3(s32 projectile, u8 *homing, s32 player_index)
{
    homing[0] = player_index;
}

// Enables or disables tracking a player.
void sumissilehome_entrypoint_4(s32 projectile, s32 *homing, unsigned long enable)
{
    *(u8 *) ((s8 *) homing + 9) = enable;
}

// Per-frame target search (actor via link, or player in range).
void sumissilehome_entrypoint_5(s32 projectile, u8 *homing, s32 unk_2, s32 unk_3)
{
    s32 found_player;
    s32 found_actor;

    found_player = -1;
    if ((homing[8] != 0) || (homing[9] != 0)) {
        if (homing[8] != 0) {
            found_actor = func_8010A01C(projectile + 4, projectile + 0x28, unk_2, unk_3,
                                        *(s16 *) ((char *) homing + 2));
            _subaddielink_entrypoint_1(&homing[0xc], found_actor);
            if (_subaddielink_entrypoint_4(&homing[0xc]) == 0) {
                homing[8] = 0;
            }
        }
        if (homing[9] != 0) {
            if ((homing[8] == 0) && (func_800EA068(0x4000) != 0)) {
                found_player =
                    func_8010D490(projectile + 4, projectile + 0x28, unk_2, unk_3, (s8) homing[0]);
            }
            homing[1] = found_player;
        }
    }
}

// Turns the velocity toward the target at once, keeping its speed.
void func_80800178_sumissilehome(u8 *projectile, s32 target_pos)
{
    f32 speed = func_800EEF94((f32 *) (projectile + 0x28));
    func_800EFB24((f32 *) (projectile + 0x28), target_pos, projectile + 4);
    func_800EF368((f32 *) (projectile + 0x28), speed);
}

// Turns the velocity toward the target by at most turn_rate per frame, keeping its speed.
void func_808001C8_sumissilehome(Actor *projectile, f32 *target_pos, f32 turn_rate)
{
    f32 steer[3];
    f32 speed;
    speed = func_800EEF94((f32 *) &projectile->actorData[4]);
    func_800EFB24(steer, target_pos, projectile->position);
    func_800EF368(steer, func_800D8FF8() * turn_rate);
    func_800EF04C((f32 *) &projectile->actorData[4], steer);
    func_800EF368((f32 *) &projectile->actorData[4], speed);
}

// Steers the projectile toward its target, instantly or turn-rate limited.
void sumissilehome_entrypoint_6(Actor *projectile, MissileHomeTarget *homing)
{
    f32 target_pos[3];
    Actor *target;

    if (homing->track_actor) {
        target = _subaddielink_entrypoint_4(homing->link);
        if (target == NULL) {
            homing->track_actor = 0;
            return;
        }
        func_8010A2FC(target, target_pos, projectile->position);
    } else {
        if (!homing->track_player || homing->target_player < 0)
            return;
        func_800F5A00(homing->target_player, target_pos);
        target_pos[1] += 60.0f;
    }
    if (homing->turn_mode == 1)
        func_808001C8_sumissilehome(projectile, target_pos, homing->turn_rate);
    else
        func_80800178_sumissilehome(projectile, target_pos);
}

// TU-NOTE: the .data of this overlay is defined in C (values taken from the ROM).
