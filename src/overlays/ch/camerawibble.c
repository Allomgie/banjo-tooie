// Most likely a placed actor that makes the camera wobble: every frame it applies a sine-driven
// roll/tilt to view 0, with its amplitude and speed taken from the actor.
#include "common.h"

extern int D_808000E0_chcamerawibble[];
typedef struct {
    u8 pad_0[0x24];
    f32 unk_24;
    u8 pad_28[0x10];
    f32 unk_38;
    u8 pad_3C[0x18];
    f32 amplitude;
    u8 pad_58[0x1E];
    u16 unk_76 : 9;
    u16 pad_76 : 7;
} WibbleState;
extern f32 func_80013970(f32);
extern void func_800C4B90(s32, f32, f32);
extern f32 func_800D8FF8(void);

int *chcamerawibble_entrypoint_0()
{
    return &D_808000E0_chcamerawibble;
}

void func_8080000C_chcamerawibble(WibbleState *state)
{
    state->unk_24 = state->unk_76 * 10.0f;
    state->amplitude = state->unk_38;
}

void func_8080004C_chcamerawibble()
{
    func_8080006C_chcamerawibble();
}

// Per frame: sine-driven roll/tilt on view 0.
int func_8080006C_chcamerawibble(actor)
Actor *actor;
{
    f32 offset;

    offset = func_80013970(actor->unk58) * actor->unk54;
    func_800C4B90(0, offset, -offset);
    actor->unk58 += func_800D8FF8() * *(f32 *) &actor->actorData[3]; // phase speed
}

// TU-NOTE: the overlay .data is defined here in C; its tables point to functions of this file,
// and IDO schedules some of them differently unless they share the unit. D_808000E0_chcamerawibble is int[].
extern void func_80105834();
extern void func_8010A730();
extern void func_80107C2C();
int D_808000E0_chcamerawibble[20] = {0x1580148,
                                     0x1,
                                     0x0,
                                     (u32) func_8080004C_chcamerawibble,
                                     (u32) func_80105834,
                                     (u32) func_8010A730,
                                     0x0,
                                     0x0,
                                     0x0,
                                     0x4,
                                     0x0,
                                     0x0,
                                     0x0,
                                     (u32) func_8080000C_chcamerawibble,
                                     (u32) func_80107C2C,
                                     -0x7FFFF9FE,
                                     0x0,
                                     0x0,
                                     0x0,
                                     0x0};
