#include "common.h"

extern u8 D_8012C800[];
extern void func_80020790(s16, u16, u8, f32, u8, s32, s32);

// Initializes the sound player with a fixed config.
void func_800DC380(void)
{
    *(u32 *) ((char *) &D_8012C800 + 0x0) = 0x32;
    *(u32 *) ((char *) &D_8012C800 + 0x4) = 0x100;
    *(u16 *) ((char *) &D_8012C800 + 0x10) = 0x40;
    *(u32 *) ((char *) &D_8012C800 + 0x8) = 0x18;
    *(u32 *) ((char *) &D_8012C800 + 0xC) = func_80012EDC(&D_8012C800);
    func_8001EB10(&D_8012C800);
}

// Starts a voice.
void func_800DC3D4(s32 sound_id, f32 pitch, u16 volume, u8 unk_0, u8 unk_1, s32 unk_2)
{
    func_80020790(sound_id + 1, volume, unk_0, pitch, unk_1, 0, unk_2);
}

// Matching: the volatile parameter is needed for the match.
int func_800DC42C(s32 voice, s32 volatile unk_0)
{
    func_80020C08(voice, 0x10, unk_0);
}

// Sets the voice volume, clamped to 0x7FFF.
int func_800DC454(voice, volume)
s32 voice;
u16 volume;
{
    if (volume >= 0x8000) {
        volume = 0x7FFF;
    }
    func_80020C08(voice, 8, volume);
}

void func_800DC48C(s32 voice, s32 unk_0)
{
    func_80020C08(voice, 0x100, unk_0);
}

// Sets the voice pitch.
void func_800DC4B0(s32 voice, s32 pitch)
{
    func_80020C08(voice, 0x4, pitch);
}

// Stops the voice if it is alive.
int func_800DC4D4(s32 voice)
{
    if (voice != 0 && func_80020760(voice)) {
        func_80020A60(voice);
    }
}

void func_800DC508()
{
    func_80020760();
}

int func_800DC528()
{
    func_800E9054(0);
}

int func_800DC548()
{
    s32 *entry;
    entry = (s32 *) func_800E9320();
    if (entry[1] == -1) {
        return 1;
    }
    return 0;
}
