// Looping sound helpers for actors: start/stop/update a loop kept in the actor's sound handle,
// optionally only within a distance of the camera, set volume/pitch, and a fade-in variant.
#include "common.h"

extern void func_800C31DC(u8, f32);
extern void func_800C2FDC(u8);
extern f32 func_800EEB40(f32 *, f32 *);
extern s32 func_800C4350(u8, f32 *, s16 *);
extern s16 D_808003C0_subaddieaudioloop[];
extern void _subaddieaudioquick_entrypoint_0(u8, s32);
extern void func_800C3BDC(u8);
extern s16 D_808003CC_subaddieaudioloop[];
extern s32 func_800D9154(f32 *, f32);
u8 subaddieaudioloop_entrypoint_3();
u8 subaddieaudioloop_entrypoint_7();

// Set the volume/pitch of the actor's loop sound.
void subaddieaudioloop_entrypoint_0(u8 *actor, f32 value)
{
    u8 sound = actor[0x5F];
    if (sound != 0) {
        func_800C31DC(sound, value);
    }
}

void subaddieaudioloop_entrypoint_1(Actor *actor)
{
    // Matching: the goto and the `* 0` are needed for the match.
    unsigned int sound_reload;
    u8 sound;
    sound = actor->unk5F;
    goto dummy_label_322467;
dummy_label_322467:;
    sound_reload = actor->unk5F;
    if (sound != (sound_reload * 0)) {
        func_800C3058(sound & 0xFF);
    }
}

// Stop the actor's loop sound and clear the handle.
s32 subaddieaudioloop_entrypoint_2(Actor *actor)
{
    u8 sound = subaddieaudioloop_entrypoint_3(actor->unk5F);
    actor->unk5F = sound;
}

// Stop a loop sound; returns 0.
u8 subaddieaudioloop_entrypoint_3(sound)
u8 sound;
{

if (sound) {
    func_800C2FDC(sound);
    sound = 0;
}

return sound;
}

// Start/update the actor's loop sound; returns whether it is playing.
int subaddieaudioloop_entrypoint_4(Actor *actor, f32 *pos, u32 enable, u32 *desc)
{
    actor->unk5F = subaddieaudioloop_entrypoint_7(actor->unk5F, pos, enable, desc,
                                                  *(u32 *) ((u8 *) actor + 0x70) & 1);
    return actor->unk5F != 0;
}

// Like entrypoint_4, but only within max_dist of the camera (-1 = 3000).
void subaddieaudioloop_entrypoint_5(Actor *actor, f32 *pos, u32 enable, s32 max_dist,
                                    u32 *desc)
{
    f32 listener_pos[3];

if (enable != 0) {
    func_8010D640(listener_pos);
    if (max_dist == -1)
        max_dist = 3000;
    if (max_dist * max_dist < func_800EEB40(listener_pos, pos))
        enable = 0;
}

subaddieaudioloop_entrypoint_4(actor, pos, enable, desc);
}

u8 subaddieaudioloop_entrypoint_6(u8 sound, f32 *pos, u32 enable, s32 max_dist, u32 *desc,
                                  s32 mode_3d)
{
    f32 listener_pos[3];

if (enable) {
    func_8010D640(listener_pos);
    if (max_dist == -1)
        max_dist = 3000;
    if (func_800EEB40(listener_pos, pos) > max_dist * max_dist)
        enable = 0;
}

return subaddieaudioloop_entrypoint_7(sound, pos, enable, desc, mode_3d);

}

u8 subaddieaudioloop_entrypoint_7(sound, pos, enable, desc, mode_3d)
u8 sound;
f32 *pos;
u32 enable;
u32 *desc;
s32 mode_3d;
{
    if (enable) {
        if (!sound) {
            sound = func_800C4350(sound, pos, D_808003C0_subaddieaudioloop);
            func_800C4350(sound, pos, (s16 *) desc);
        }
        if (sound) {
            _subaddieaudioquick_entrypoint_0(sound, mode_3d);
            func_800C4350(sound, pos, NULL);
            func_800C3BDC(sound);
        }
    } else if (sound) {

func_800C2FDC(sound);
sound = 0;

}
return sound;
}

// Fade-in variant (0.7 s); returns the timer.
f32 subaddieaudioloop_entrypoint_8(Actor *actor, s32 unk_0, s32 enable, f32 timer)
{
    if (enable) {
        if (!actor->unk5F) {
            actor->unk5F = func_800C4350(0, actor->position, D_808003CC_subaddieaudioloop);
            timer = 0.7f;
        } else if (func_800D9154(&timer, 0.7f)) {

if (actor->unk5F)
    func_800C3BDC(actor->unk5F);
}
}
else if (actor->unk5F)
{
    func_800C2FDC(actor->unk5F);
    actor->unk5F = 0;
}
return timer;
}

// TU-NOTE: the overlay .data is defined here in C (values from the ROM).
s16 D_808003C0_subaddieaudioloop[6] = {0x206, 0x1, 0xC8, 0xBB8, 0x7, 0x0};
s16 D_808003CC_subaddieaudioloop[18] = {0x306, 0x7, 0x13, 0x560, 0x1, 0x3E8, 0xFA0, 0x16, 0x61A8,
                                        0x11,  0x0, 0x0,  0x0,   0x0, 0x0,   0x0,   0x0,  0x0};
