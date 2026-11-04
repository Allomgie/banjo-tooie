#include "common.h"

extern f32 func_8010CD28(Actor *);
extern f32 func_800F1DCC(f32, f32);
extern f32 mlAbsF(f32);
extern f32 func_800F1DF4(f32 *, f32 *);
extern f32 func_80013728(f32);
extern void func_800EF1B8(f32 *, f32, f32);
extern void func_8008F990(f32 *, f32);
extern void func_8010D5DC();
typedef struct {
    u8 pad_0[0x70];
    u32 pad_1 : 16;
    u32 state : 6;
    u32 pad_2 : 10;
} MolehillMode;
extern void _chmolehill_entrypoint_0(void);
extern Actor *func_80106790();
extern int D_80800B70_chmolehill[];
typedef struct {
    f32 value[5];
} MoleHillTimes401;
extern u8 D_80800AC0_chmolehill[];
extern u8 D_80800ACC_chmolehill[];
extern u8 D_80800ADC_chmolehill[];
extern MoleHillTimes401 D_80800B5C_chmolehill;
extern s32 func_80101E14(Actor *, f32);
typedef struct {
    u8 pad_0[0x72];
    u16 state : 6;
    u16 rest : 10;
} MoleState;
extern u8 func_800D731C(s32);
extern f32 func_800D8FF8(void);
extern void func_800DBE60(u8, s32, s32);

// Returns 1 when the player's yaw is within 5 degrees of the hill's facing.
int func_80800000_chmolehill(Actor *actor)
{
    if (func_8010CAC0(actor->position, 0x87))
        return 0;
    if (mlAbsF(func_800F1DCC(func_8010CD28(actor), actor->rotation[1] + 15.0f)) > 5.0f)
        return 0;
    return 1;
}

void func_80800088_chmolehill(Actor *actor)
{
    f32 walk_to[3];
    f32 player_pos[3];
    f32 yaw;
    f32 yaw_offset;

    if (actor->unk64_20) {
        func_8010D254(player_pos);
        yaw = func_800F1DF4(actor->position, player_pos);
        yaw_offset = func_80013728(func_800F1DCC(yaw, actor->rotation[1] + 15.0f));
        if (yaw_offset < -15.0f)
            yaw_offset = -15.0f;
        if (yaw_offset > 15.0f)
            yaw_offset = 15.0f;
        yaw -= yaw_offset;
        func_800EE7F8(walk_to, actor->position);
        func_800EF1B8(walk_to, yaw, 150.0f);
        func_8008F964(walk_to);
    }
}

void chmolehill_entrypoint_2();

void chmolehill_entrypoint_1();

void func_80800160_chmolehill(Actor *actor)
{
    s32 step_sound;
    // Matching: extra temporary needed for the match.
    u32 state;
    step_sound = 0;
    actor->unk64_19 = 0;
    switch (actor->unk79_4) {
        case 0:

            break;

        case 7:
            chmolehill_entrypoint_1(actor, 0);
            chmolehill_entrypoint_2(actor, 0xD);
            break;

        case 1:
            func_80800088_chmolehill(actor);
            if (actor->unk3C && func_80800000_chmolehill(actor)) {
                func_8008F8B0();
                chmolehill_entrypoint_1(actor, 0);
                chmolehill_entrypoint_2(actor, 2);
            }
            break;

        case 3:
            func_80800088_chmolehill(actor);
            if (actor->unk3C && func_80800000_chmolehill(actor)) {
                func_8008F8B0();
                chmolehill_entrypoint_1(actor, 0);
                chmolehill_entrypoint_2(actor, 7);
            }
            break;

        case 4:
            chmolehill_entrypoint_1(actor, 0);
            chmolehill_entrypoint_2(actor, 8);
    }

    state = actor->unk70_10;
    if ((state != 2) && (state != 7)) {
        if (state != 9) {
            if (state == 10) {
                actor->unk64_19 = 1;
            }
        } else {
            actor->unk64_19 = 1;
        }
    }
    if (*(s16 *) ((u8 *) actor + 0x8C) && (anctrl_getPlaybackType(func_80104248(actor)) != 3)) {
        switch (func_801022E4(actor)) {
            case 0x229:
                if (func_80101E14(actor, 0.288f)) {
                    _subaddieaudioquick_entrypoint_2(actor, actor->position,
                                                     D_80800AC0_chmolehill);
                } else if (func_80101E14(actor, 0.69f) || func_80101E14(actor, 0.76f)) {
                    step_sound = 1;
                }
                break;

            case 0x22A:
                if (func_80101E14(actor, 0.16f)) {
                    _subaddieaudioquick_entrypoint_2(actor, actor->position,
                                                     D_80800AC0_chmolehill);
                } else if (func_80101E14(actor, 0.86f) || func_80101E14(actor, 0.98f)) {
                    step_sound = 1;
                }
                break;

            case 0x22B:
                if (func_80101E14(actor, 0.2f)) {
                    _subaddieaudioquick_entrypoint_2(actor, actor->position,
                                                     D_80800ACC_chmolehill);
                }
                break;

            case 0x22C:
                if (func_80101E14(actor, 0.48f)) {
                    _subaddieaudioquick_entrypoint_2(actor, actor->position,
                                                     D_80800AC0_chmolehill);
                } else if (func_80101E14(actor, 0.7136f) || func_80101E14(actor, 0.9336f)) {
                    step_sound = 1;
                }
                break;

            case 0x22E: {
                const MoleHillTimes401 trigger_times = D_80800B5C_chmolehill;
                if (func_80101E14(actor, 0.04f)) {
                    _subaddieaudioquick_entrypoint_2(actor, actor->position,
                                                     D_80800AC0_chmolehill);
                } else if (func_80101E4C(actor, trigger_times.value)) {
                    step_sound = 1;
                }
            }
        }
    }
    if (step_sound) {
        _subaddieaudioquick_entrypoint_2(actor, actor->position, D_80800ADC_chmolehill);
    }
}

// Spawns the mole actor (0x18F) and links both actors through +0x3C.
int chmolehill_entrypoint_0(Actor *actor)
{
    Actor *hill;
    s32 *mole;
    // Matching: the unused pad locals are needed for the match.
    s32 pad[2];
    hill = func_80106790();
    mole = func_801084B0(0x18F, &hill);
    *(s32 *) ((char *) hill + 0x3C) = *(s32 *) ((char *) mole + 0);
    *(s32 *) ((char *) mole + 0x3C) = *(s32 *) ((char *) hill + 0);
    func_80108944(mole, hill);
    _chmoley_entrypoint_1(mole, (u32) *(u16 *) ((char *) hill + 0x72) >> 10 | 0); // Matching: `| 0` is needed for the match.
}

// Starts the forced walk of the player to a point in front of the hill.
void func_8080058C_chmolehill(Actor *actor)
{
    f32 walk_to[3];
    f32 player_pos[3];
    f32 yaw;
    f32 yaw_offset;

    if (!func_80800000_chmolehill(actor)) {
        func_8010D254(player_pos);
        yaw = func_800F1DF4(actor->position, player_pos);
        yaw_offset = func_80013728(func_800F1DCC(yaw, actor->rotation[1] + 15.0f));
        if (yaw_offset < -15.0f)
            yaw_offset = -15.0f;
        if (yaw_offset > 15.0f)
            yaw_offset = 15.0f;
        yaw -= yaw_offset;
        func_800EE7F8(walk_to, actor->position);
        func_800EF1B8(walk_to, yaw, 150.0f);
        func_8008F8B0();
        func_8008F8D8(1);
        func_8008F938(1);
        func_8008F904(func_8010D5DC, actor->unk0);
        func_8008F990(walk_to, 300.0f);
        actor->unk64_20 = 1;
    }
}

void chmolehill_entrypoint_1(Actor *actor, s32 mode)
{
    actor->unk79_4 = mode;
    switch (actor->unk79_4) {
        case 1:
        case 3:
            _chbaddiesetup_entrypoint_1(_chmolehill_entrypoint_0, actor->unk0);
            func_8080058C_chmolehill(actor);
            break;
        case 7:
            ((MolehillMode *) actor)->state = 0xD;
            _chbaddiesetup_entrypoint_1(_chmolehill_entrypoint_0, actor->unk0);
    }
    if (actor->unk3C)
        _chmoley_entrypoint_0(func_80106790(actor->unk3C), mode);
}

void chmolehill_entrypoint_2(Actor *actor, s32 state)
{
    if (state != actor->unk70_10) {
        func_80102424(actor, state);
        if (actor->unk70_10 == 1 && actor->unk3C) {
            func_800FFA88(actor->unk3C);
            actor->unk3C = 0;
        }
        if (actor->unk3C)
            _chmoley_entrypoint_1(func_80106790(actor->unk3C), state);
    }
}

s32 chmolehill_entrypoint_3(MoleState *hill)
{
    switch (hill->state) {
        case 0:
        case 1:
        case 3:
        case 11:
            return 0;
        case 7:
        case 8:
        case 9:
            return 0;
        case 2:
        case 4:
        case 5:
        case 6:
        case 10:
            return 1;
    }
    return 0;
}

// Shared int slot (used by su/mole): set.
int chmolehill_entrypoint_4(s32 actor, s32 value)
{
    *(s32 *) func_80100094(actor, 0) = value;
}

// Shared int slot (used by su/mole): get.
int chmolehill_entrypoint_5(s32 actor)
{
    s32 ret = func_80100094(actor, 0);
    return *(s32 *) ret;
}

// Raises or lowers the hill's animated texture.
void func_80800884_chmolehill(actor) Actor *actor;
{
    u8 tex_id;

    tex_id = func_800D731C(actor->unk0->unk14);
    if (actor->unk74_30) {
        *(f32 *) ((u8 *) actor + 0x28) += 15.0f * func_800D8FF8();
        if (8.49f <= *(f32 *) ((u8 *) actor + 0x28)) {
            *(f32 *) ((u8 *) actor + 0x28) = 8.49f;
            actor->unk74_30 = 0;
        }
    } else {
        *(f32 *) ((u8 *) actor + 0x28) -= 15.0f * func_800D8FF8();
        if (*(f32 *) ((u8 *) actor + 0x28) <= 0.0f) {
            *(f32 *) ((u8 *) actor + 0x28) = 0.0f;
            actor->unk74_30 = 1;
        }
    }
    if (tex_id != 0) {
        func_800DBE60(tex_id, 0, *(f32 *) ((u8 *) actor + 0x28));
        func_800DBE60(tex_id, 1, *(f32 *) ((u8 *) actor + 0x28));
    }
}

s32 func_808009A0_chmolehill(Actor *actor, s32 msg, s32 msg_arg)
{
    s32 part_state;
    switch (msg) {
        case 0x32:
            func_8080058C_chmolehill(actor);
            break;
        case 0x1F:
            func_801015D0(actor);
            func_80800884_chmolehill(actor);
            part_state = actor->unk74_29 || _glcutDll_entrypoint_20() ? 2 : 1;
            func_800DF744(3, part_state);
            break;
        default:
            return 0;
    }
    return 1;
}

int *chmolehill_entrypoint_6()
{
    return &D_80800B70_chmolehill;
}

// TU-NOTE: the .data of this overlay is defined here in C; tables holding function pointers must be in
// the same unit, otherwise IDO's assembler schedules those functions differently. D_80800B70 is
// declared as int[] to match the object.
extern void func_80105834();
extern void func_801018A4();
extern void func_80107C2C();
u8 D_80800AC0_chmolehill[12] = {0x0, 0x13, 0x5, 0x56, 0x0, 0x16, 0x55, 0xF0, 0x0, 0x0, 0x0, 0x0};
u8 D_80800ACC_chmolehill[16] = {0x0, 0x13, 0x4, 0xA1, 0x0,  0xD,  0x0, 0xF3,
                                0x1, 0x0,  0x0, 0x16, 0x2E, 0xE0, 0x0, 0x0};
u8 D_80800ADC_chmolehill[16] = {0x0, 0x13, 0x4, 0xA0, 0x0,  0xD,  0x0, 0xF3,
                                0x1, 0xC,  0x0, 0x16, 0x2E, 0xE0, 0x0, 0x0};
u32 D_80800AEC_chmolehill[28] = {
    0x0,        0x0,        0x0,        0x2290044,  0x3FD9999A, 0x2290002, 0x3FCCCCCD,
    0x22A0002,  0x0,        0x2290004,  0x0,        0x2290004,  0x0,       0x2290004,
    0x3F4CCCCD, 0x22B0002,  0x3F666666, 0x22C0002,  0x40800000, 0x22D0001, 0x0,
    0x2290004,  0x40C00000, 0x22E0002,  0x40800000, 0x22D0004,  0x0,       0x2290004};
MoleHillTimes401 D_80800B5C_chmolehill = {0.1258f, 0.1558f, 0.76f, 0.96f, -1.0f};
int D_80800B70_chmolehill[20] = {0xB80247,
                                 0x7D70001,
                                 (u32) &D_80800AEC_chmolehill,
                                 (u32) func_80800160_chmolehill,
                                 (u32) func_80105834,
                                 (u32) func_801018A4,
                                 0x1F40000,
                                 0x0,
                                 0x0,
                                 0x854,
                                 0x0,
                                 0x0,
                                 0x40000,
                                 0x0,
                                 (u32) func_80107C2C,
                                 -0x7FFFDFFE,
                                 (u32) func_808009A0_chmolehill,
                                 0x0,
                                 0x0,
                                 0x0};
