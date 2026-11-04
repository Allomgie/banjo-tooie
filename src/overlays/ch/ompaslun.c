// Probably "Chompa's lunch", a prop that exists only during the end credits: picks one of 4 colour
// variants, plays a 3-state animation with sound cues and sets model render channels when drawn.
#include "common.h"

extern int D_808003E0_chchompaslunch[];
typedef union {
    s32 word;
    void *pointer;
} ChompaLunchEventPayload;
typedef struct {
    s16 channel[6];
} ChompaLunchChannel;
extern ChompaLunchChannel D_80800428_chchompaslunch[];
extern s32 D_808004A4_chchompaslunch[];
extern void _subaddieaudioquick_entrypoint_3(u8 *, u8 *, void *, f32);
extern s32 D_8080044C_chchompaslunch[];
extern s32 D_80800458_chchompaslunch[];
extern s32 D_80800498_chchompaslunch[];
extern s32 D_80800468_chchompaslunch[];
extern f32 D_80800478_chchompaslunch[];
extern s16 D_80800488_chchompaslunch[];
extern s16 D_80800490_chchompaslunch[];
extern f32 func_800DC178(f32, f32);
extern void func_800C31DC(u8, f32);
// Draw: applies the variant's model render channels.
void func_8080017C_chchompaslunch();
void func_8080037C_chchompaslunch();
// Animation sound cues.
void func_80800250_chchompaslunch();

int chchompaslunch_entrypoint_0()
{
    return (int) &D_808003E0_chchompaslunch;
}

// Despawns unless the end-credits sequence is running; picks a random colour variant.
void func_8080000C_chchompaslunch(Actor *actor)
{
    if (!_glcutDll_entrypoint_20()) {
        func_800FFAB0(actor);
    }
    actor->unk58 = 8.0f;
    actor->unk6C_0 = func_800DC128(0, 3);
}

void func_80800070_chchompaslunch(u8 *actor)
{
    u32 state;
    state = (u16) *(u16 *) ((s8 *) actor + 0x72);
    state = state >> 0xA;
    switch (state) {
        case 1:
            func_80800250_chchompaslunch(actor);
            if (func_800D9078(actor + 0x58) != 0) {
                func_80102424(actor, 2);
            }
            return;

        case 2:
            func_8080037C_chchompaslunch(actor);
            if (func_80101DDC(actor) != 0) {
                func_80102424(actor, 3);
            }
            break;

        case 3:
            func_80105230(actor, 0);
    }
}

s32 func_80800118_chchompaslunch(Actor *actor, s32 msg, ChompaLunchEventPayload payload)
{
    switch (msg) {
        case 0x1F:
            func_8080017C_chchompaslunch(actor);
            break;
        case 0xBC:
            func_800FFAB0(actor);
            break;
        default:
            return 0;
    }
    return 1;
}

// Draw: applies the variant's model render channels.
void func_8080017C_chchompaslunch(actor) Actor *actor;
{
    func_801015D0(actor);
    func_800DF744(4, D_80800428_chchompaslunch[actor->unk6C_0].channel[0]);
    func_800DF744(5, D_80800428_chchompaslunch[actor->unk6C_0].channel[1]);
    func_800DF744(6, D_80800428_chchompaslunch[actor->unk6C_0].channel[2]);
    func_800DF744(7, 0);
    func_800DF744(8, D_80800428_chchompaslunch[actor->unk6C_0].channel[3]);
}

// Animation sound cues.
void func_80800250_chchompaslunch(actor) Actor *actor;
{
    s32 i;

    if (!actor->unk5F) {
        actor->unk5F = func_800C4350(0, actor->position, &D_80800498_chchompaslunch);
    }
    for (i = 0; i < 4; i++) {
        if (func_80101E14(actor, D_80800468_chchompaslunch[i])) {
            func_800C301C(actor->unk5F, D_80800488_chchompaslunch[i]);
            func_800C31DC(actor->unk5F,
                          D_80800478_chchompaslunch[i] + func_800DC178(-0.02f, 0.02f));
            func_800C3058(actor->unk5F, D_80800490_chchompaslunch[i]);
            func_800C3BDC(actor->unk5F);
            break;
        }
    }
    if (!actor->unk6C_0) {
        _subaddieaudioquick_entrypoint_4(actor, actor->position, &D_8080044C_chchompaslunch,
                                         &D_80800458_chchompaslunch);
    }
}

void func_8080037C_chchompaslunch(actor) u8 *actor;
{
    _subaddieaudioquick_entrypoint_3(actor, actor + 4, &D_808004A4_chchompaslunch, 0.0f);
}

extern void func_80102EC0();
extern void func_801018A4();
extern void func_80107C2C();
u32 D_808003C0_chchompaslunch[8] = {0x0,        0x0,       0x40800000, 0x2EE0001,
                                    0x3FB33333, 0x2EF0002, 0x3F28F5C3, 0x2F00001};
int D_808003E0_chchompaslunch[18] = {0x1580501,
                                     0x7EE0001,
                                     (u32) &D_808003C0_chchompaslunch,
                                     (u32) func_80800070_chchompaslunch,
                                     (u32) func_80102EC0,
                                     (u32) func_801018A4,
                                     0x0,
                                     0x0,
                                     0x0,
                                     0x128,
                                     0x0,
                                     0x0,
                                     0x0,
                                     (u32) func_8080000C_chchompaslunch,
                                     (u32) func_80107C2C,
                                     -0x7FFFFBFE,
                                     (u32) func_80800118_chchompaslunch,
                                     0x0};
ChompaLunchChannel D_80800428_chchompaslunch[3] = {0x1, 0x1, 0x1, 0x3, 0x0, 0x0, 0x2, 0x2, 0x2,
                                                   0x1, 0x0, 0x0, 0x3, 0x2, 0x2, 0x2, 0x0, 0x0};
s32 D_8080044C_chchompaslunch[3] = {0x130417, 0xD00C0, 0xD90000};
s32 D_80800458_chchompaslunch[4] = {0x3F23D70A, 0x3F3AE148, 0x3F51EB85, -0x40800000};
s32 D_80800468_chchompaslunch[4] = {0x0, 0x3E6B851F, 0x3EA3D70A, 0x3ED70A3D};
f32 D_80800478_chchompaslunch[4] = {0.9f, 1.1f, 1.05f, 1.0f};
s16 D_80800488_chchompaslunch[4] = {0x5BE, 0x5BC, 0x5BD, 0x5BD};
s16 D_80800490_chchompaslunch[4] = {0x7D00, 0x55F0, 0x55F0, 0x55F0};
s32 D_80800498_chchompaslunch[3] = {0x3060001, 0xC80BB8, 0x70000};
s32 D_808004A4_chchompaslunch[7] = {0x1305B6, 0xD00F3, 0x10C0018, 0x0, 0x0, 0x0, 0x0};
