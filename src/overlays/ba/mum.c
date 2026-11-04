// Probably Mumbo's wand effect: while its intensity is non-zero, emits a sparkle stream between
// two wand bones, with the emission count taken from the intensity.
#include "common.h"
#include "playerstate.h"

extern u8 D_80800280_bamum[];
extern s32 func_800BABB8(s32, f32 *, f32 *, f32, void *);
extern void func_800BA994();

s32 bamum_entrypoint_0()
{
    return 0x8;
}

// Clears the wand effect intensity (PlayerState+0xD0 -> [1]).
void func_80800008_bamum(player) void *player;
{
    // Matching: extra local needed for the match.
    f32 intensity = 0.0f;
    ((f32 *) ((void **) player)[0xD0 / 4])[1] = intensity;
}

// Emits sparkles between the two wand bones while the intensity is non-zero.
void func_80800018_bamum(player) PlayerState *player;
{
    f32 rand_vec[3];
    f32 dir[3];
    f32 unk_0[3];
    f32 unk_1[3];
    f32 bone_a[3];
    f32 bone_b[3];
    f32 emit_pos[3];
    f32 angles[2];
    s32 emitter;

    emitter = func_800B5BE4(0xD);
    if (((f32 *) *(void **) ((u8 *) player + 0xD0))[1] != 0.0f) {
        func_8009C128(player, unk_0);
        func_8009C15C(player, unk_1);
        func_800EFB24(dir, unk_0, unk_1);
        func_80092C6C(player, bone_a);
        func_80092C48(player, bone_b);
        func_800EF04C(bone_a, dir);
        func_800EF04C(bone_b, dir);
        func_800EFB24(dir, bone_b, bone_a);
        func_800F1A88(dir, angles);
        angles[0] = -angles[0];
        func_800EFD24(rand_vec);
        func_800EE780(emit_pos, bone_b, rand_vec);
        func_800BA994(emitter, (s16) (s32) (angles[0] - 20.0f), (s16) (s32) (angles[1] - 40.0f),
                      400, (s32) (angles[0] + 20.0f), (s32) (angles[1] + 40.0f), 400);
        func_800BABB8(emitter, emit_pos, NULL, 1.0f, D_80800280_bamum);
        func_800BA22C(emitter,
                      (s32) (((f32 *) *(void **) ((u8 *) player + 0xD0))[1] * 3.0f + 0.5f));
    }
}

void bamum_entrypoint_1(s32 player)
{
}

int bamum_entrypoint_2(s32 player)
{
    s32 on;
    func_80800008_bamum();
    // Matching: extra local needed for the match.
    on = 0;
    func_8009ADF0(player, 5, on);
}

void bamum_entrypoint_3()
{
    func_80800018_bamum();
}

int bamum_entrypoint_4(s32 player, s32 on)
{
    if (on != 0) {
        func_8009ADF0(player, 5, 1);
        func_80800008_bamum(player);
    } else {
        func_8009ADF0(player, 5, 0 | 0);  // Matching: `| 0` needed for the match.
    }
}

bamum_entrypoint_5(s32 player, f32 intensity)
{
    *(f32 *) (*(s32 *) (player + 208) + 4) = intensity;
}

// TU-NOTE: this overlay's .data is defined here in C; values are taken from the ROM.
u8 D_80800280_bamum[48] = {0x0,  0x1D, 0x9, 0xE9, 0x0, 0x15, 0x0, 0x0,  0x0, 0x66, 0x0, 0xC,
                           0x0,  0x2,  0x0, 0x22, 0x0, 0x14, 0x0, 0x14, 0x0, 0x33, 0x0, 0x33,
                           0x0,  0x27, 0x0, 0x0,  0x1, 0x90, 0x0, 0x0,  0x1, 0xB8, 0x0, 0x16,
                           0x10, 0x0,  0x0, 0x2B, 0x0, 0x4C, 0x0, 0x54, 0x0, 0x0,  0x0, 0x0};
