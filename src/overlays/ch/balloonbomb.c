// Probably the balloon bomb Mr. Patch throws: lobbed on an arc towards the player's predicted spot,
// spins and inflates, then bursts on contact or an egg hit (message 0x40) into balloon shreds.
#include "common.h"

extern int D_808004B0_chballoonbomb[];
extern void *func_80100094(Actor *, s32);
extern void func_8010D09C(s32, f32 *, f32);
extern s32 func_800DC298(f32);
extern f32 func_800DC178(f32, f32);
extern f32 func_800D8FF8(void);
extern u8 D_808004F8_chballoonbomb[];
extern s32 *_fxgenlist_entrypoint_2(void);
extern void func_800BBCB8(s32, s32, s32, s32, void *);
extern void func_800E1610(s32, f32, f32, f32 *);
extern void func_80018820(s32, f32, f32);
extern s32 D_8080050C_chballoonbomb[];
extern s32 D_80800540_chballoonbomb[];
extern s32 D_8080057C_chballoonbomb[];
extern f32 func_800136E4(f32);
extern f32 func_800F15F8(f32, f32, f32);
typedef union {
    f32 delta;
    s32 delta_bits;
} BalloonUpdateTime;
void func_80800294_chballoonbomb();
s32 func_80800440_chballoonbomb();

int *chballoonbomb_entrypoint_0()
{
    return &D_808004B0_chballoonbomb;
}

// Aims the bomb at the predicted player position and picks a random spin.
void func_8080000C_chballoonbomb(Actor *bomb)
{
    s32 i;
    f32 target[3];
    f32 *spin;
    f32 speed;
    f32 sign;

    spin = func_80100094(bomb, 0);
    func_8010D09C(func_800F54E4(), target, bomb->unk58);
    for (i = 0; i < 3; i++) {
        ((f32 *) bomb->actorData)[i + 4] =
            (target[i] - bomb->position[i]) / bomb->unk58;
    }
    ((f32 *) bomb->actorData)[5] += 250.0f * bomb->unk58;
    if (func_800DC298(0.5f)) {
        sign = 1.0f;
    } else {
        sign = -1.0f;
    }
    speed = func_800DC178(300.0f, 400.0f);
    spin[0] = speed * sign;
}

void func_80800230_chballoonbomb();

void func_80800118_chballoonbomb(Actor *bomb)
{
    f32 *spin;
    BalloonUpdateTime frame;

    spin = (f32 *) func_80100094(bomb, 0);
    frame.delta = func_800D8FF8();
    if (!bomb->unk64_17) {
        if (func_800DA298(0))
            func_80800294_chballoonbomb(bomb);
        else if (!func_800DA298(0x641) && !func_8008FF18()) {
            bomb->rotation[1] = func_800136E4(*spin * frame.delta + bomb->rotation[1]);
            func_80800230_chballoonbomb(bomb, frame.delta_bits, 1);
            bomb->scale = func_800F15F8(bomb->scale, 1.4f, frame.delta * 1.5f);
        }
    }
}

s32 func_808001F8_chballoonbomb(s32 actor, s32 msg, s32 unk_0)
{
    if (msg == 0x40) {
        func_80800294_chballoonbomb(actor, msg, unk_0);
        // Matching: empty block needed for the match.
        if (unk_0) {
        }
        return 1;
    }
    return 0;
}

void func_80800230_chballoonbomb(Actor *bomb, s32 unk_0, s32 unk_1)
{
    *(f32 *) &bomb->actorData[5] -= 500.0f * func_800D8FF8();
    if (func_8010B990(bomb, 0x500007) & 0x20) {
        func_80800294_chballoonbomb(bomb);
    }
}

void func_80800294_chballoonbomb(bomb) Actor *bomb;
{
    if (!bomb->unk64_20) {
        func_80800440_chballoonbomb();
        func_800BBCB8(bomb->position, 0, 0x3F800000, 1, _fxgenlist_entrypoint_2());
        func_800C4AF0(bomb->position, D_808004F8_chballoonbomb);
        if (bomb->unk6C_0 >= 4U) {
            func_800E1610(0, 30.0f, 0.9f, bomb->position);
            func_80018820(0, 2.0f, 0.15f);
        }
        bomb->unk64_20 = 1;
        func_800FFAB0(bomb);
    }
}

void func_80800354_chballoonbomb(s32 actor)
{
    int pos;
    pos = actor + 4;
    func_800BBCB8(pos, pos, *(s32 *) ((actor ^ 0) + 0x38), 8, &D_8080050C_chballoonbomb);
}

void func_80800394_chballoonbomb(s32 *actor, s32 particle_id, s32 slot)
{
    s32 emitter;
    s32 pos;
    s32 handle;
    // Matching: needed for the match.
    if (1) {
        handle = func_800B53A4(slot);
        emitter = handle;
        func_800BA670(handle, particle_id);
        pos = actor + 1;
    }
    func_800BABB8(emitter, pos, pos, *(s32 *) ((u8 *) actor + 0x38), &D_80800540_chballoonbomb);
    func_800BA22C(emitter, slot);
}

void func_80800400_chballoonbomb(s32 actor)
{
    func_800BBCB8(actor + 4, 0, *(s32 *) ((actor + 0x38) ^ 0), 1, &D_8080057C_chballoonbomb);
}

s32 func_80800440_chballoonbomb(actor)
s32 actor;
{
    func_80800394_chballoonbomb(actor, 0x93F, 2);
    func_80800394_chballoonbomb(actor, 0x940, 3);
    func_80800394_chballoonbomb(actor, 0x941, 4);
    func_80800400_chballoonbomb(actor);
    func_80800354_chballoonbomb(actor);
}

extern void func_80105834();
extern void func_80101870();
extern void func_80108ED0();
extern void func_80107C2C();
int D_808004B0_chballoonbomb[18] = {0x18F013D,
                                    0x93E0001,
                                    0x0,
                                    (u32) func_80800118_chballoonbomb,
                                    (u32) func_80105834,
                                    (u32) func_80101870,
                                    0x752F,
                                    0x3F4CCCCD,
                                    0x0,
                                    0x406,
                                    0x0,
                                    (u32) func_80108ED0,
                                    0x40000,
                                    (u32) func_8080000C_chballoonbomb,
                                    (u32) func_80107C2C,
                                    0x0,
                                    (u32) func_808001F8_chballoonbomb,
                                    0x0};
u8 D_808004F8_chballoonbomb[20] = {0x0, 0x13, 0x4,  0x13, 0x0,  0xA,  0x0, 0xE6, 0x0, 0x18,
                                   0x0, 0x1,  0x1F, 0x40, 0x4E, 0x20, 0x0, 0x0,  0x0, 0x0};
s32 D_8080050C_chballoonbomb[13] = {0x113001D, 0x9E20016, 0x10000015, 0xB3,    0x2B0133,
                                    0x1990022, 0x4C0059,  0x260033,   0xE000A, 0x14002D,
                                    0x4B005DC, 0x1BFF9C,  -0xC80000};
s32 D_80800540_chballoonbomb[15] = {0x1130016, 0x10000015, 0xCC,     0x2B0133,  0x1990022,
                                    0x1000100, 0x660099,   0xE000A,  0x14002D,  0x4B005DC,
                                    0x1BFF9C,  -0xC7FFD9,  0xC800C8, 0x1900190, 0x0};
s32 D_8080057C_chballoonbomb[9] = {0x1D09DD, 0x2B0200, 0x2800022, 0x3000380, 0x8000A00,
                                   0x150000, 0x260019, 0x7,       0x0};
