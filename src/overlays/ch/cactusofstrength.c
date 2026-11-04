// Cactus of Strength attraction in Witchyworld: hitting the pad launches a puck up the cactus; at the
// top the reward sequence (jiggy) starts. Three actor kinds, probably pad, puck and top.
#include "common.h"

#define D ((CactusData *) this)
extern int D_80800D00_chcactusofstrength[];
extern int D_80800D48_chcactusofstrength[];
extern int D_80800D90_chcactusofstrength[];
extern s32 func_800D9058(f32);
typedef union {
    s32 strength;
    void *unk_0;
} CactusStrengthEvent;
typedef struct {
    u8 pad_0[0x24];
    f32 velocity;
    f32 min_y;
    f32 max_y;
} CactusData;
extern void func_800EE7F8();
extern void func_800EF1B8(f32 *, f32, f32);
extern void _sudeflect_entrypoint_0(f32 *, f32, f32, s32);
extern s32 func_800D9078(f32 *);
extern void func_80101FDC(Actor *, s32);
extern Actor *_subaddiefind_entrypoint_0(f32 *, s32, s32, s32);
extern Actor *func_80106790();
extern s32 D_80800DD8_chcactusofstrength[];
extern f32 func_800DC178(f32, f32);
extern void func_800EEB9C(f32 *, f32, f32);
extern s32 func_800BABB8(s32, f32 *, f32 *, f32, void *);
extern void _subaddieaudioquick_entrypoint_2(Actor *, f32 *, void *);
extern u8 D_80800E18_chcactusofstrength[];
extern f32 _mlwave_entrypoint_5(void *, f32, f32);
extern s32 _mlwave_entrypoint_8(void *, f32);
extern void func_800CE88C(int, int);
extern int func_800CEAA8(int);
extern void func_800D1000(int, int, int, int, int);
extern int D_80800E24_chcactusofstrength[];
extern int D_80800E64_chcactusofstrength[];
extern void func_800B4470(f32 *, f32 *, s32 *, s32, f32, f32, s32, s32, s32);
extern void func_800C4104(s32, f32, s32, f32 *, f32, f32);
extern u8 D_80800E08_chcactusofstrength[];
extern f32 mlAbsF(f32);
extern f32 func_800F13F0(f32, f32);
extern f32 func_800F0E00(f32, f32);
extern f32 func_800F10B4(f32, f32, f32, f32, f32);
extern void func_800C31DC(s32, f32);
void func_808006BC_chcactusofstrength();
void func_80800718_chcactusofstrength();
void func_80800824_chcactusofstrength(Actor *param_0, f32 param_1);
void func_80800C18_chcactusofstrength();
int func_808004F8_chcactusofstrength();
void func_80800780_chcactusofstrength();
void func_8080094C_chcactusofstrength();

int chcactusofstrength_entrypoint_0()
{
    return (int) &D_80800D00_chcactusofstrength;
}

int chcactusofstrength_entrypoint_1()
{
    return (int) &D_80800D48_chcactusofstrength;
}

int *chcactusofstrength_entrypoint_2()
{
    return &D_80800D90_chcactusofstrength;
}

void func_80800024_chcactusofstrength(Actor *actor)
{
    switch (actor->unk70_10) {
        case 2:
            if (func_80101DDC(actor)) {
                if (actor->unk6C_0 != 0) {
                    actor->unk6C_0--;
                } else {
                    func_80102424(actor, 3);
                    actor->unk6C_0 = func_800D9058(0.5f);
                }
            }
            break;
        case 3:
            if (func_80101DDC(actor)) {
                func_80102424(actor, 1);
                _gcaudiolist_entrypoint_0(0);
                func_80103110(actor, 0);
            }
    }
}

void func_80800108_chcactusofstrength(s32 arg0)
{
}

// Pad hit: strength 1/2/4 depending on the player's move.
void func_80800110_chcactusofstrength(Actor *actor, s32 param_1)
{
    s32 strength;

    if (actor->unk70_10 == 1) {
        switch (func_8008FCC8(actor->unk0)) {
            case 1:
                strength = 1;
                break;
            case 0xB:
                strength = 2;
                break;
            default:
                strength = 4;
                break;
        }
        if (strength != -1) {
            func_80102424(actor, 2, strength);
            _gcaudiolist_entrypoint_0(0);
            func_80103110(actor, 1);
            actor->unk6C_0 = 8;
            func_80101180(0x13B, 0xA, strength);
        }
    }
}

s32 func_808001C4_chcactusofstrength(Actor *actor, s32 msg, CactusStrengthEvent event)
{
    switch (msg) {
        case 0x40:
            func_80800110_chcactusofstrength(actor, event.strength);
            break;
        default:
            return 0;
    }
    return 1;
}

void func_80800200_chcactusofstrength(Actor *this)
{
    f32 pos[3];
    f32 dec;

    func_800EE7F8(pos, this->position);
    func_800EF1B8(pos, 135.0f, -55.0f);
    _sudeflect_entrypoint_0(pos, 60.0f, 75.0f, 2);
    func_8080094C_chcactusofstrength(this);
    switch (this->unk70_10) {
        case 1:
            func_808006BC_chcactusofstrength(this);
            break;
        case 2:
            func_80800824_chcactusofstrength(this, 20.0f);
            if (0.0f < this->unk58) {
                // Matching: empty block steers IDO's code generation.
                if (func_800D9078(&this->unk58)) {
                }
            } else {
                this->position[1] += D->velocity;
                if (D->max_y <= this->position[1]) {
                    this->position[1] = D->max_y;
                    func_80800718_chcactusofstrength(this);
                    this->unk64_16 = 0;
                    func_80101FDC(this, 4);
                } else {
                    D->velocity -= 5.0f;
                    if (D->velocity <= 0.0f) {
                        func_80101FDC(this, 1);
                    }
                }
            }
            break;
        case 3:
            func_80800824_chcactusofstrength(this, -20.0f);
            this->position[1] += D->velocity;
            if (0 < D->velocity) {
                dec = 10.0f;
            } else {
                dec = 5.0f;
            }
            D->velocity -= dec;
            if (D->velocity < -50.0f) {
                D->velocity = -50.0f;
            }
            if (this->position[1] <= D->min_y) {
                this->position[1] = D->min_y;
                func_80800780_chcactusofstrength(this);
            }
    }
}

int func_808003EC_chcactusofstrength(f32 pos[3])
{
    Actor *actor;
    actor = pos;
    *(s32 *) ((char *) actor + 0x50) = 0;
    *(f32 *) ((char *) actor + 0x28) = pos[2];
    *(f32 *) ((char *) actor + 0x2C) = 1200.0f;
    if (func_800D0A9C(0x1E, 1, actor)) {
        func_800FFAB0(actor);
    }
}

int func_80800440_chcactusofstrength(Actor *actor, s32 msg, s32 arg)
{
    Actor *found;
    switch (msg) {
        case 0xA:
            func_808004F8_chcactusofstrength(actor, arg);
            return 1;

        case 0xB:
            if (arg == 2) {
                func_800FFAB0(actor);
            }
            func_800F7F98(func_800F54E4(), 0);
            return 3;

        case 0x95:
            found = _subaddiefind_entrypoint_0((u8 *) actor + 4, 0x13A, -1, 0);
            if (found != 0) {
                actor->unk3C = found->unk0;
            }
            goto block_11;
        default:
            return 0;
    }
block_11:
    return 1;
}

int func_808004F8_chcactusofstrength(actor, strength)
ALSeqPlayer *actor;
s32 strength;
{
    f32 height;
    f32 range;
    s32 old_flags;
    s32 *flags_ptr;

    height = 0.0f;
    old_flags = *(s32 *) ((char *) actor + 0x50);
    flags_ptr = (s32 *) ((char *) actor + 0x50);
    range = *(f32 *) ((char *) actor + 0x2C) - *(f32 *) ((char *) actor + 0x28);
    // Matching: the comma expression is needed for the match.
    if ((old_flags == 0) || (0, 0,(func_800CEAA8(0) != 0))) {
        if ((*flags_ptr & strength) == 0) {
            switch (strength) {
                case 1:
                    *(s32 *) ((char *) actor + 0x50) = *flags_ptr | 1;
                    height = range * 0.25f;
                    break;
                case 2:
                    *(s32 *) ((char *) actor + 0x50) = *flags_ptr | 2;
                    height = range * 0.25f;
                    break;
                case 4:
                    *(s32 *) ((char *) actor + 0x50) = *flags_ptr | 4;
                    height = range * 0.5000100136f;
            }
            if (old_flags == 0) {
                func_800CE8D8(0, 0x41A00000, 0x14);
                func_800CE88C(0, 1);
                _subaddieDll_entrypoint_4(actor, 1);
            }
            func_80101FDC(actor, 2);
            *(f32 *) ((char *) actor + 0x24) = sqrtf(10.0f * height);
            if ((*(s32 *) ((char *) actor + 0x50) & 7) != 7) {
                func_800FC618(0xE, -1);
                *(f32 *) ((char *) actor + 0x58) = 0.200000003f;
                _capod_entrypoint_13(*(s32 **) actor, 0, 0xAA, 0x800);
                func_800F7F98(func_800F54E4(), 1);
                return;
            }
            func_800FC618(0x10, -1);
            _capod_entrypoint_13(*(s32 **) actor, 0, 2, 0x800);
            func_800F7F98(func_800F54E4(), 1);
        }
    }
}

void func_808006BC_chcactusofstrength(actor) Actor *actor;
{
    if (*(s32 *) ((char *) actor + 0x50)) {
        if (func_800CEAD0(0) != 0) {
            if (func_800CEAA8(0) != 0) {
                func_800CE88C(0, 0);
            }
            func_80101FDC(actor, 3);
        }
    }
}

void func_80800718_chcactusofstrength(actor) u8 *actor;
{
    u8 *target;
    u8 *found;

    found = func_80106790((*(s32 *) ((s8 *) (actor) + (0x3C))));
    target = found;
    func_80101FDC(found, 2);
    func_80103110(target, 1);
    (*(f32 *) ((s8 *) (target) + (0x58))) = 2.5f;
    _mlwave_entrypoint_0(func_80100074(target, 1, 0x1C), 0x42C80000, 0x42A00000);
}

void func_80800780_chcactusofstrength(actor) Actor *actor;
{
    func_800B4470(actor->position, NULL, NULL, 1, 0.5f, 0.0f, 125, 250, 0);
    func_800C4104(0x417, 1.0f, 0x7D00, actor->position, 1250.0f, 2500.0f);
    func_80101FDC(actor, 1);
    *(s32 *) &actor->unk50 = 0;
    _subaddieDll_entrypoint_4(actor, 1);
}

void func_80800824_chcactusofstrength(Actor *actor, f32 y_offset)
{
    s32 emitter;
    f32 jitter[3];
    f32 origin[3];
    f32 target[3];
    s32 i;

    func_800EE7F8(origin, actor->position);
    func_800EE7F8(target, origin);
    target[1] += y_offset;
    emitter = func_800B53A4(2);
    for (i = 0; i < 2; i++) {
        func_800EEB9C(jitter, func_800DC178(0.0f, 270.0f), 20.0f);
        func_800EF04C(jitter, origin);
        func_800BABB8(emitter, jitter, target, 1.0f, &D_80800DD8_chcactusofstrength);

}
}

void func_8080094C_chcactusofstrength(actor) Actor *actor;
{
    f32 ratio;
    f32 pitch;
    f32 speed;

    if (actor->unk70_10 == 2 || actor->unk70_10 == 3) {
        if (actor->unk5F == 0) {
            _subaddieaudioloop_entrypoint_4(actor, actor->position, 1,
                                            D_80800E08_chcactusofstrength);
        }

if (actor->unk5F != 0) {
    speed = mlAbsF(((f32 *) actor->actorData)[3]);
    ratio = func_800F13F0(speed, 20.0f);
    ratio = func_800F0E00(5.0f, ratio);
    pitch = func_800F10B4(ratio, 5.0f, 20.0f, 1.1f, 1.4f);
    func_800C4350(actor->unk5F, actor->position, 0);
    func_800C31DC(actor->unk5F, pitch);
    func_800C3BDC(actor->unk5F);
}

}
else
{
    _subaddieaudioloop_entrypoint_2(actor);
}
}

void func_80800A44_chcactusofstrength(Actor *actor)
{
    f32 sway;
    void *wave;
    f32 spawn_pos[3];

    if (actor->unk70_10 == 2) {
        wave = (void *) func_80100094(actor, 1);
        _mlwave_entrypoint_1(wave);
        sway = _mlwave_entrypoint_5(wave, -2e+01f, 20.0f);
        actor->rotation[2] = sway;

if (_mlwave_entrypoint_8(wave, 0.75f) || _mlwave_entrypoint_8(wave, 0.25f)) {
    _subaddieaudioquick_entrypoint_2(actor, actor->position, D_80800E18_chcactusofstrength);
}

if (func_800D9078(&actor->unk58)) {
    func_800EE7F8(spawn_pos, actor->actorData);
    func_800EF1B8(spawn_pos, actor->rotation[1], -60.0f);
    spawn_pos[1] -= 40.0f;
    _chexploder_entrypoint_3(actor, spawn_pos, 3);
}

}
}

int func_80800B24_chcactusofstrength(s32 actor)
{
    s32 *unk_0 = (s32 *) ((char *) actor + 0x0);
    if (func_800D0A9C(0x1E, 1)) {
        func_800FFAB0(unk_0);
    } else {
        func_800EE7F8((s32 *) ((char *) actor + 0x18), (s32 *) ((char *) actor + 0x4));
        *(f32 *) ((char *) actor + 8) += 225.0f;
    }
}

int func_80800B90_chcactusofstrength(Actor *actor, s32 msg, s32 arg)
{
    Actor *found;
    switch (msg) {
        case 0x90:
            func_80800C18_chcactusofstrength(actor);
            func_800FFAB0(actor);
            return 1;
        case 0x95:
            found = _subaddiefind_entrypoint_0(actor->position, 0x13B, -1, 0);
            if (found)
                actor->unk3C = found->unk0;
            break;
        default:
            return 0;
    }
    return 1;
}

void func_80800C18_chcactusofstrength(actor) Actor *actor;
{
    void *linked;
    linked = func_80106790(*(int **) ((char *) actor + 0x3C));
    func_800BABB8(0, (char *) actor + 4, (char *) actor + 4, *(f32 *) ((char *) actor + 0x38),
                  &D_80800E24_chcactusofstrength);
    _subaddieaudioquick_entrypoint_2(actor, (char *) actor + 4, &D_80800E64_chcactusofstrength);
    func_800D1000(0x1E, 1, 0, 1, 0);
    *((int *) (((char *) linked) + 0x50)) = 0;
    if (func_800CEAA8(0) != 0) {
        func_800CE88C(0, 0);
    }
}

extern void func_80105834();
extern void func_80101870();
extern void func_80108ED0();
extern void func_80107C2C();
u32 D_80800CE0_chcactusofstrength[8] = {0x0,        0x0,      0x3EB33333, 0xD40044,
                                        0x3E99999A, 0xD40002, 0x3E800000, 0xD50002};
int D_80800D00_chcactusofstrength[18] = {0x18B0139,
                                         0x7540001,
                                         (u32) &D_80800CE0_chcactusofstrength,
                                         (u32) func_80800024_chcactusofstrength,
                                         (u32) func_80105834,
                                         (u32) func_80101870,
                                         0x0,
                                         0x0,
                                         0x0,
                                         0x808,
                                         0x0,
                                         (u32) func_80108ED0,
                                         0x0,
                                         (u32) func_80800108_chcactusofstrength,
                                         (u32) func_80107C2C,
                                         -0x7FFFD400,
                                         (u32) func_808001C4_chcactusofstrength,
                                         0x0};
int D_80800D48_chcactusofstrength[18] = {0x18D013B,
                                         0x78E0001,
                                         0x0,
                                         (u32) func_80800200_chcactusofstrength,
                                         (u32) func_80105834,
                                         (u32) func_80101870,
                                         0x1F40000,
                                         0x0,
                                         0x0,
                                         0x800,
                                         0x0,
                                         0x0,
                                         0x0,
                                         (u32) func_808003EC_chcactusofstrength,
                                         (u32) func_80107C2C,
                                         -0x7FFFFBFE,
                                         (u32) func_80800440_chcactusofstrength,
                                         0x0};
int D_80800D90_chcactusofstrength[18] = {0x18C013A,
                                         0x77C0001,
                                         0x0,
                                         (u32) func_80800A44_chcactusofstrength,
                                         (u32) func_80105834,
                                         (u32) func_80101870,
                                         0x0,
                                         0x0,
                                         0x0,
                                         0x800,
                                         0x0,
                                         0x0,
                                         0x0,
                                         (u32) func_80800B24_chcactusofstrength,
                                         (u32) func_80107C2C,
                                         -0x7FFFD3FE,
                                         (u32) func_80800B90_chcactusofstrength,
                                         0x0};
s32 D_80800DD8_chcactusofstrength[12] = {0x1D09E6, 0x2B0059, 0x730022,  0x4C0066,
                                         0x190026, 0x150000, 0x800027,  -0x630064,
                                         0x640064, 0x2D00E1, 0x12C011A, 0x0};
u8 D_80800E08_chcactusofstrength[16] = {0x0, 0x13, 0x4, 0xAD, 0x0, 0x1, 0x0, 0xC8,
                                        0x9, 0xC4, 0x0, 0x3,  0x0, 0x0, 0x0, 0x0};
u8 D_80800E18_chcactusofstrength[12] = {0x0,  0x13, 0x5, 0x1A, 0x0, 0x16,
                                        0x6D, 0x60, 0x0, 0x0,  0x0, 0x0};
int D_80800E24_chcactusofstrength[16] = {
    0x411001D, 0x9DD002B, 0x6000800, 0x220180,   0x2000480, 0x6000015, 0x26,     0x190000,
    0x7002D,   0x9600FA,  0x208E75,  0x16C0000A, -0x63FFE7, -0x63FF9C, 0x4B0064, 0x0};
int D_80800E64_chcactusofstrength[3] = {0x130413, 0xA00E6, 0x0};
