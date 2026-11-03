#include "common.h"

extern s32 D_80800784_baflameline[];
extern s32 func_800EE7F8(s32);
extern void func_800EF2A0(int);
extern s32 D_808006F0_baflameline[];
extern f32 func_800F10B4(f32, f32, f32, f32, f32);
extern f32 func_800DC178(f32, f32);
extern void func_800EFA20(f32 *, f32 *, f32);
extern s32 func_800BABB8(s32, f32 *, f32 *, f32, void *);
extern void func_800BA77C();
typedef struct {
    u8 pad_0[0xC];
    f32 dir[3];
    f32 length;
    s32 emitter;
} FlameLineData31;
typedef struct {
    u8 pad_0[0x84];
    FlameLineData31 *data;
} FlameLineOwner31;
extern s32 D_80800738_baflameline[];
extern void func_800BA930();
extern s32 D_80800798_baflameline[];
extern void func_800EFE50(f32 *, void *, void *, f32);
extern void func_800C8E54(s32, f32, f32);
extern void func_8008EEC4(void *, f32 *, f32, s32);

s32 baflameline_entrypoint_0()
{
    return 0x28;
}

// Burst of flame sprites along the beam.
void baflameline_entrypoint_1(u8 *player)
{
    // Matching: unused local needed for the match.
    f32 unk_0;
    f32 end[3];
    f32 pos[3];
    s32 emitter;
    s32 i;
    u8 *beam;
    emitter = func_800B53A4(0xE);
    beam = *(u8 **) (player + 0x84);
    func_800EFA20(end, (f32 *) (beam + 0xC), *(f32 *) (beam + 0x18));
    func_800EF04C(end, *(void **) (player + 0x84));
    for (i = 0; i < 7; i++) {
        func_800EFE50(pos, *(void **) (player + 0x84), end,
                      func_800F10B4((i + 0.5f) / 7.0f, 0.0f, 1.0f, 0.2f, 1.0f));
        func_800BA77C(emitter, 0, 0, (s16) (s32) func_800DC178(0.0f, 359.0f));
        func_800BABB8(emitter, pos, NULL, 1.0, &D_808006F0_baflameline);
    }
}

// Spawns one flame sprite at pos.
void func_80800184_baflameline(FlameLineOwner31 *player, f32 *pos)
{
    f32 vel[3];

    func_800EFA20(vel, player->data->dir, player->data->length / 0.3f);
    vel[1] -= (player->data->length / 0.3f) * 0.1f;
    func_800BA77C(player->data->emitter, 0, 0, (s16) func_800DC178(0.0f, 359.0f));
    func_800BA930(player->data->emitter, (s16) vel[0], (s16) vel[1], (s16) vel[2],
                  (s16) vel[0], (s16) vel[1], (s16) vel[2]);
    func_800BABB8(player->data->emitter, pos, 0, 1.0f, &D_80800738_baflameline);
}

// Releases the sound, the light and the particle emitter.
void baflameline_entrypoint_2(u8 *player)
{
    s32 light;
    u8 *beam;

    func_800C2FDC(*(u8 *) ((s8 *) *(u8 **) ((s8 *) player + 0x84) + 0x20), player);
    beam = *(u8 **) ((s8 *) player + 0x84);
    light = *(s32 *) ((s8 *) beam + 0x24);
    if (light != 0) {
        func_800C8B84(light, player);
        *(s32 *) ((s8 *) *(u8 **) ((s8 *) player + 0x84) + 0x24) = 0;
        beam = *(u8 **) ((s8 *) player + 0x84);
    }
    func_800B5450(*(s32 *) ((s8 *) beam + 0x1C), player);
}

// Sets up the beam data, the emitter, the light and the looping sound.
void baflameline_entrypoint_3(u8 *player)
{
    func_800EFD24(*(u8 **) ((s8 *) player + 0x84));
    func_800EFD24(*(u8 **) ((s8 *) player + 0x84) + 0xC);
    *(f32 *) ((s8 *) *(u8 **) ((s8 *) player + 0x84) + 0x18) = 1.0f;
    *(s32 *) ((s8 *) *(u8 **) ((s8 *) player + 0x84) + 0x1C) = func_800B53A4(0x28);
    func_800B5534(*(s32 *) ((s8 *) *(u8 **) ((s8 *) player + 0x84) + 0x1C));
    if (func_800BF8E4() > 0) {
        *(s32 *) ((s8 *) *(u8 **) ((s8 *) player + 0x84) + 0x24) = func_800C8A98();
        func_800C8F64(*(s32 *) ((s8 *) *(u8 **) ((s8 *) player + 0x84) + 0x24), 0xB);
        func_800C8FE0(*(s32 *) ((s8 *) *(u8 **) ((s8 *) player + 0x84) + 0x24), 0);
    } else {
        *(s32 *) ((s8 *) *(u8 **) ((s8 *) player + 0x84) + 0x24) = 0;
    }
    *(s8 *) ((s8 *) *(u8 **) ((s8 *) player + 0x84) + 0x20) =
        func_800C4350(0, 0, &D_80800784_baflameline);
}

s32 baflameline_entrypoint_4(s32 player)
{
    return func_800EE7F8(*(s32 *) (player + 0x84));
}

int baflameline_entrypoint_5(Actor *player)
{
    func_800EE7F8(*(int *) ((char *) player + 0x84) + 0xC);
    func_800EF2A0(*(int *) ((char *) player + 0x84) + 0xC);
}

// Sets the beam length.
void baflameline_entrypoint_6(void *player, f32 length)
{
    *(f32 *) (*(s32 **) ((char *) player + 0x84) + 0x6) = length;
}

// Per-frame update: sound volume, light, flame sprites and area damage.
void baflameline_entrypoint_7(u8 *player)
{
    f32 end[3];
    f32 pos[3];
    f32 light_radius;
    s32 i;
    u8 *beam;

    beam = *(u8 **) (player + 0x84);
    if (*(f32 *) (beam + 0x18) == 0.0f) {
        if (*(s32 *) (beam + 0x24)) {
            func_800C8FE0(*(s32 *) (beam + 0x24), 0);
        }
    } else {
        func_800EFA20(end, (f32 *) (beam + 0xC), *(f32 *) (beam + 0x18));
        func_800EF04C(end, *(u8 **) (player + 0x84));
        func_800C3058((*(u8 **) (player + 0x84))[0x20],
                      (s32) func_800F10B4(*(f32 *) (*(u8 **) (player + 0x84) + 0x18), 0.0f, 300.0f,
                                          5000.0f, 32000.0f));
        func_800C35E8((*(u8 **) (player + 0x84))[0x20], end);
        func_800C3BDC((*(u8 **) (player + 0x84))[0x20]);
        beam = *(u8 **) (player + 0x84);
        if (*(s32 *) (beam + 0x24)) {
            light_radius = *(f32 *) (beam + 0x18) * 0.5f;
            func_800EFE50(pos, beam, end, 0.5);
            func_800C8FE0(*(s32 *) (*(u8 **) (player + 0x84) + 0x24), 1);
            func_800C8CB8(*(s32 *) (*(u8 **) (player + 0x84) + 0x24), pos);
            beam = *(u8 **) (player + 0x84);
            func_800C8E54(*(s32 *) (beam + 0x24), light_radius, *(f32 *) (beam + 0x18));
            func_800C8E84(*(s32 *) (*(u8 **) (player + 0x84) + 0x24),
                          (u8 *) &D_80800798_baflameline + func_8001210C(1) * 12);
        }
        for (i = 0; i < 2; i++) {
            func_800EFE50(pos, *(u8 **) (player + 0x84), end, func_800DC178(0.0f, 0.1f));
            func_80800184_baflameline(player, pos);
            func_800EFE50(pos, *(u8 **) (player + 0x84), end, func_800DC178(0.0f, 0.1f));
            func_80800184_baflameline(player, pos);
        }
        for (i = 0; i < 3; i++) {
            func_800EFE50(pos, *(u8 **) (player + 0x84), end, (i + 0.5f) / 3.0f);
            func_8008EEC4(player, pos, 45.0f, 0x26D);
        }
    }
}

// TU-NOTE: the .data of this overlay is defined here in C (values taken from the ROM).
// The extern declarations match the object at the same addresses; all four tables are s32[].
s32 D_808006F0_baflameline[18] = {0x1D09DC,   0x2CFFEC, 0x1EFFEC,   0x140050, 0x14000E,  0x50005,
                                  0x150002,   0x660020, 0x28412832, 0x22004C, 0x4C0133,  0x1660016,
                                  0x10000018, 0x3,      0x0,        0x2B0233, 0x3E6011A, 0x0};
s32 D_80800738_baflameline[19] = {0x1D09CE, 0x150002,   0xAE0016,  0x1000000E, 0x50005,
                                  0x260000, 0xFF9C,     0x0,       0x640032,   0x20018,
                                  0x0,      0x17551755, 0x220040,  0x400099,   0x99002B,
                                  0x4C004C, 0x1B015E,   0x15E011A, 0x0};
s32 D_80800784_baflameline[5] = {0x2060013, 0x483001B, 0x1655F0, 0xA0100, 0x0};
s32 D_80800798_baflameline[6] = {0xFF, 0xFF, 0x40, 0xFF, 0x40, 0x20};
