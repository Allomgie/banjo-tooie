// Probably the debris-burst particle preset: three shared emitter slots reserved/released through
// the emitter cache, and func_800B4470, which configures one of them for a burst of debris.
#include "common.h"

extern u8 D_80127F03;
extern u8 D_80127F00[];
extern u16 D_8011A5B0[];
extern s32 func_800B56D0(s32);
extern void func_800BA3FC(s32, s32);
extern void func_800BA594(s32, f32, f32);
extern void func_800BA75C(s32, f32 *);
extern void func_800EFA20(f32 *, f32 *, f32);
extern void func_800BA930();
extern void func_800BAB80(s32, s32 *);
extern void func_800BA5A8(s32, s32);
extern void func_800BA8F8(s32, f32, f32);
extern void func_800BA7C4(s32, f32, f32);
extern void func_800BA7FC(s32, f32, f32);
extern void func_800BA5BC(s32, f32, f32);
extern void func_800BA5B0(s32, s32, s32);
extern void func_800BA22C(s32, s32);

// Reserve and release the three shared emitter slots.
// Reserves the three shared emitter slots in D_80127F00.
// Matching: the line breaks in this function are needed for the match.
// Matching: the no-op `++`/`--` pair and `^ 0` are needed for the match.
void func_800B43E0()
{
    u8 *slot = (u8 *) D_80127F00;
    slot++; slot--; do { *slot++ = func_800B5758(0x20 ^ 0);
    }
    while (slot != &D_80127F03);
}

// Releases the three shared emitter slots.
// Matching: the line breaks in this function are needed for the match.
void func_800B4428()
{
    u8 *slot;
    u8 *end;
    end = &D_80127F03; slot = D_80127F00;
    do
    {
        func_800B58D4(*slot);
        slot += 1;
    }
    while (slot != end);
}

// Spawn a debris burst with given position, velocity, size and lifetime.
// Configures an emitter slot for a burst of debris/shards.
void func_800B4470(f32 *pos, f32 *dir, s32 *unk_0, s32 unk_1, f32 scale, f32 unk_2,
                   s32 lifetime, s32 lifetime_range, s32 index)
{
    f32 unk_3; // Matching: unused local, needed for the match.
    f32 unk_4; // Matching: unused local, needed for the match.
    s32 emitter;
    f32 velocity[3];
    s32 flags = 0x228;
    u16 *sprite;
    emitter = func_800B56D0(D_80127F00[index]);
    sprite = &D_8011A5B0[index];
    func_800BA3FC(emitter, *sprite);
    func_800BA594(emitter, 0.075f, 0.4f);
    func_800BA75C(emitter, pos);
    if (dir)
        func_800EFA20(velocity, dir, 30.0f);
    else
        velocity[0] = velocity[1] = velocity[2] = 0.0f;
    if (unk_2 != 0.0f)
        velocity[1] += unk_2 / scale;
    func_800BA930(emitter, (s16) velocity[0], (s16) velocity[1], (s16) velocity[2], (s16) velocity[0],
                  (s16) velocity[1], (s16) velocity[2]);
    if (unk_0)
        func_800BAB80(emitter, unk_0);
    if (!unk_1)
        flags = 0x238;
    func_800BA5A8(emitter, flags);
    func_800BA8F8(emitter, scale, scale);
    func_800BA7C4(emitter, lifetime / 175.0f, lifetime / 175.0f);
    func_800BA7FC(emitter, (lifetime + lifetime_range) / 175.0f, (lifetime + lifetime_range) / 175.0f);
    if (sprite == D_8011A5B0)
        func_800BA5BC(emitter, 15.0f / scale, 15.0f / scale);
    else
        func_800BA5B0(emitter, 0, 12);
    func_800BA22C(emitter, 1);
}

// TU-NOTE: .data of this file is defined here in C (values taken from the ROM).
u16 D_8011A5B0[8] = {0x9C9, 0x9CA, 0x9DC, 0x0, 0x0, 0x0, 0x0, 0x0};
