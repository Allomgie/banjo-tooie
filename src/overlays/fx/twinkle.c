#include "fx/twinkle.h"

extern s32 D_808000F0_fxtwinkle[];
extern void *func_800B53A4(int param_0);
extern void func_800BABB8(void *param_0, s32 param_1, int param_2, float param_3, void *param_4);
extern void func_800BA3FC();
extern void func_800BA22C(void *param_0, int param_1);
extern void *D_8080010C_fxtwinkle;

void fxtwinkle_entrypoint_0(s32 pos)
{
    fxtwinkle_entrypoint_1(pos, GOLD_SPARKLE);
}

void fxtwinkle_entrypoint_1(f32 *pos, AssetId sprite)
{
    s32 emitter_copy;
    short sprite_id;
    s32 emitter;
    emitter = func_800B53A4(1);
    // Matching: the extra copies of emitter and sprite are needed for the match.
    sprite_id = sprite;
    emitter_copy = emitter;
    func_800BABB8(emitter, pos, 0, 1.0f, &D_808000F0_fxtwinkle);
    func_800BA3FC(emitter_copy, sprite_id);
    func_800BA22C(emitter_copy, 1);
}

void fxtwinkle_entrypoint_2(pos, sprite) s32 pos;
s16 sprite;
{
    void *emitter;
    emitter = func_800B53A4(1);
    func_800BABB8(emitter, pos, 0, 1.0f, &D_8080010C_fxtwinkle);
    func_800BA3FC(emitter, sprite);
    func_800BA22C(emitter, 1);
}

// TU-NOTE: the .data of this overlay is defined here in C; values taken from the ROM.
// D_808000F0_fxtwinkle is declared as s32[] to match the object (same address).
s32 D_808000F0_fxtwinkle[7] = {0x2B00B3, 0xB30022,  0x660066, 0x70007,
                               0x270000, 0x10E0000, 0x10E0000};
void *D_8080010C_fxtwinkle = (void *) 0x002B00B3;
static u32 D_8080010C_fxtwinkle_rest[8] = {0xB30016, 0x10040022, 0x660066,  0x70007,
                                           0x270000, 0x10E0000,  0x10E0000, 0x0};
