#include "common.h"

extern void func_800C3418(u8, s32);
extern void func_800C32C4(u8, s32);
extern u8 D_808001D0_subaddieaudioquick[];
extern s32 func_80101E14(Actor *, f32);

// Select 3D or 2D mode for a sound source.
void subaddieaudioquick_entrypoint_0(sound, mode_3d) u8 sound;
s32 mode_3d;
{

if (mode_3d) {
    func_800C3418(sound, 1);
    func_800C32C4(sound, 0x40);
} else {

func_800C3418(sound, 2);
}
}

// Create a one-shot sound source at pos; mode taken from the actor flag.
int subaddieaudioquick_entrypoint_1(actor, pos)
Actor *actor;
s32 pos;
{
    u8 sound;
    sound = func_800C4350(0, pos, D_808001D0_subaddieaudioquick);
    return subaddieaudioquick_entrypoint_0(sound, (*(s32 *) ((char *) (actor) + 0x70)) & 1),
           sound;
}

// Create and play a one-shot sound.
int subaddieaudioquick_entrypoint_2(s32 actor, s32 pos, s32 desc)
{
    u8 sound;
    sound = subaddieaudioquick_entrypoint_1(actor);
    func_800C4350(sound, pos, desc);
    func_800C3BDC(sound);
}

// Play the sound once the actor's animation has passed anim_time.
s32 subaddieaudioquick_entrypoint_3(s32 actor, s32 pos, s32 desc, f32 anim_time)
{
    if (func_80101E14(actor, anim_time)) {
        subaddieaudioquick_entrypoint_2(actor, pos, desc);
        return 1;

}
return 0;
}

// Like entrypoint_3, for a list of times terminated by -1.0.
s32 subaddieaudioquick_entrypoint_4(Actor *actor, f32 *pos, void *desc, f32 *times)
{
    while (-1.0f != *times) {
        if (func_80101E14(actor, *times)) {
            subaddieaudioquick_entrypoint_2((s32) actor, (s32) pos, (s32) desc);
            return 1;
        }

times++;
}
return 0;
}

// TU-NOTE: the overlay .data is defined here in C (values from the ROM).
u8 D_808001D0_subaddieaudioquick[16] = {0x1, 0x6, 0x0, 0x1, 0x0, 0xC8, 0xB, 0xB8,
                                        0x0, 0x7, 0x0, 0x0, 0x0, 0x0,  0x0, 0x0};
