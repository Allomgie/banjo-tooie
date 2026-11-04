#include "common.h"

extern int D_808001F0_chidgoldhorde[];
typedef struct {
    s16 marker_id;
    s16 vertex_count;
    s16 counter;
    s16 target;
    f32 chance;
} GoldHordeState59;
extern void *func_80100094(Actor *, u32);
extern f32 func_800DC0C0(void);
extern void _chidgoldhorde_entrypoint_1(void);
typedef struct {
    s16 marker_id;
    s16 vertex_count;
    u8 pad_0[4];
    f32 chance;
} GoldHordeState;
extern s32 func_800BEA88(s32);
typedef struct {
    u32 pad_0;
    s16 counter;
    s16 target;
} GoldHordeSparkles;
extern Actor *func_80106790(s32);
extern void func_800EE88C();

int chidgoldhorde_entrypoint_0()
{
    return &D_808001F0_chidgoldhorde;
}

void func_8080000C_chidgoldhorde(Actor *actor)
{
    GoldHordeState *state;
    s32 model;
    state = func_80100094(actor, 0);
    model = func_800BEA88(0);
    state->marker_id = actor->unk74_7;
    state->vertex_count = _glidmake_entrypoint_3(model, state->marker_id);
    state->chance = actor->rotation[1] * (1.0f / 360.0f);
    actor->unk64_16 = 0;
}

// Callback per vertex: counts up and spawns a sparkle at the chosen vertex, offset along its normal.
void chidgoldhorde_entrypoint_1(vertex, unk_0, actor_ref, normal) s32 vertex;
s32 unk_0;
s32 actor_ref;
s8 normal[3];
{
    s32 i;
    GoldHordeSparkles *state;
    f32 pos[3];
    f32 offset[3];

    state = func_80100094(func_80106790(actor_ref), 0);
    if (state->counter++ == state->target) {
        func_800EE88C(pos, vertex);
        for (i = 0; i < 3; i++) {
            offset[i] = normal[i] * 0.39370078f;
        }
        func_800EF04C(pos, offset);
        _fxsparkle_entrypoint_1(pos, 9);
    }
}

// Randomly picks a vertex of the group and walks the vertices to it.
void func_8080015C_chidgoldhorde(Actor *actor)
{
    GoldHordeState59 *state;
    s32 model;

    state = func_80100094(actor, 0);
    if (func_800DC0C0() < state->chance) {
        model = func_800BEA88(0);
        state->counter = 0;
        state->target = func_800DC128(0, state->vertex_count);
        _glid_entrypoint_3(model, state->marker_id, _chidgoldhorde_entrypoint_1, actor->unk0);
    }
}

// TU-NOTE: this overlay data is defined here in C; its tables point to functions of this file,
// and IDO schedules some of them differently unless the tables are in the same unit.
extern void func_80102EC0();
extern void func_8010A730();
extern void func_80107C2C();
int D_808001F0_chidgoldhorde[20] = {0x15801BD,
                                    0x1,
                                    0x0,
                                    (u32) func_8080015C_chidgoldhorde,
                                    (u32) func_80102EC0,
                                    (u32) func_8010A730,
                                    0x0,
                                    0x0,
                                    0x0,
                                    0x4,
                                    0x0,
                                    0x0,
                                    0xC0000,
                                    (u32) func_8080000C_chidgoldhorde,
                                    (u32) func_80107C2C,
                                    -0x7FFFDDFE,
                                    0x0,
                                    0x0,
                                    0x0,
                                    0x0};
