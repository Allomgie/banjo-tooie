// Possibly a cutscene stand-in for Jamjars: a model (three variants) that fades in, waits for temp
// flag 0x9F1 or a 5 s timeout, then fades out and deletes itself.
#include "common.h"

extern f32 func_800D8FF8(void);
extern f32 func_800F10B4(f32, f32, f32, f32, f32);
// Per-variant model id and animation id.
typedef struct {
    u16 model;
    s16 state;
} JamjarsDummyRecord;
extern JamjarsDummyRecord D_8080032C_chjamjarsdummy[];
extern int D_80800338_chjamjarsdummy[];

// States: 0 fade in (2 s), 1 wait for the cue flag or timeout (5 s), 2 fade out (2 s).
void func_80800000_chjamjarsdummy(Actor *actor, s32 new_state)
{
    actor->unk79_4 = new_state;
    switch (actor->unk79_4) {
        case 0:
            actor->unk58 = 2.0f;
            _subaddiefade_entrypoint_8(actor, 255);
            break;
        case 1:
            switch (actor->unk6C_0) {
                case 0:
                    actor->unk58 = 5.0f;
                    break;
                case 1:
                    actor->unk58 = 5.0f;
                    break;
                case 2:
                    actor->unk58 = 5.0f;
                    break;
            }
            break;
        case 2:
            actor->unk58 = 2.0f;
            ((f32 *) actor->actorData)[4] = 0.0f;
    }
}

// Per-frame update: advances the timer at actorData[4] and runs the state machine.
void func_808000E0_chjamjarsdummy(Actor *actor)
{
    s32 alpha_in;
    s32 alpha_out;

    *(f32 *) &actor->actorData[4] += func_800D8FF8();
    // Variant 2 emits the swappy particle trail every frame.
    if (actor->unk6C_0 == 2)
        _chswappy_entrypoint_0(actor, 0);
    switch (actor->unk79_4) {
        case 0:
            alpha_in =
                func_800F10B4(*(f32 *) &actor->actorData[4], 0.0f, actor->unk58, 0.0f, 255.0f);
            _subaddiefade_entrypoint_8(actor, alpha_in);
            if (alpha_in >= 255)
                func_80800000_chjamjarsdummy(actor, 1);
            break;
        case 1:
            // Temp flag 0x9F1 ends the wait early.
            if (func_800DA9E4(0x9F1, 0))
                func_800FFAB0(actor);
            if (actor->unk58 < *(f32 *) &actor->actorData[4])
                func_80800000_chjamjarsdummy(actor, 2);
            break;
        case 2:
            alpha_out =
                func_800F10B4(*(f32 *) &actor->actorData[4], 0.0f, actor->unk58, 255.0f, 0.0f);
            _subaddiefade_entrypoint_8(actor, alpha_out);
            if (alpha_out <= 0)
                func_800FFAB0(actor);
    }
}

void func_80800238_chjamjarsdummy(s32 arg0)
{
}

void func_80800240_chjamjarsdummy(Actor *actor)
{
    func_80103140(actor, D_8080032C_chjamjarsdummy[actor->unk6C_0].model, actor->unk0->unk16);
    func_80102424(actor, D_8080032C_chjamjarsdummy[actor->unk6C_0].state);
    func_80800000_chjamjarsdummy(actor, 0);
}

void func_808002AC_chjamjarsdummy(void *actor)
{
    if ((*(s32 *) ((char *) actor + 108) & 0x1FF) == 2) {
        *(u8 *) ((u8 *) actor + 126) = (*(u8 *) ((u8 *) actor + 126) & 0xFFFF) | 0x10;
    } else {
        func_80101870();
    }
}

int chjamjarsdummy_entrypoint_0()
{
    return (int) &D_80800338_chjamjarsdummy;
}

// TU-NOTE: the .data of this overlay is defined here in C; tables holding function pointers must be in
// the same unit, otherwise IDO's assembler schedules those functions differently. D_80800338 is
// declared as int[] to match the object. D_8080032E = D_8080032C + 0x2.
extern void func_80105834();
extern void func_80107C2C();
u32 D_80800300_chjamjarsdummy[3] = {0x40A00000, 0x40A00000, 0x40A00000};
u32 D_8080030C_chjamjarsdummy[8] = {0x0,        0x0,       0x0,        0x0,
                                    0x3FE66666, 0x2990001, 0x3F4CCCCD, 0x2140001};
JamjarsDummyRecord D_8080032C_chjamjarsdummy[3] = {0x7AA, 0x2, 0x832, 0x3, 0x6FB, 0x1};
int D_80800338_chjamjarsdummy[18] = {0x15800B7,
                                     0x7D10001,
                                     (u32) &D_8080030C_chjamjarsdummy,
                                     (u32) func_808000E0_chjamjarsdummy,
                                     (u32) func_80105834,
                                     (u32) func_808002AC_chjamjarsdummy,
                                     0x0,
                                     0x0,
                                     0x0,
                                     0x4,
                                     (u32) func_80800238_chjamjarsdummy,
                                     0x0,
                                     0x0,
                                     (u32) func_80800240_chjamjarsdummy,
                                     (u32) func_80107C2C,
                                     -0x7FFFFFFE,
                                     0x0,
                                     0x0};
