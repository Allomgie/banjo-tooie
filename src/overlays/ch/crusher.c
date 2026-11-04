// Probably the Glitter Gulch Mine Crushing Shed machinery (flag 0x4FB): slamming crushers, a
// rotating part, a conveyor belt and the on/off switch.
#include "ch/crusher.h"

typedef struct {
    s16 a, b;
} S16Pair;
extern s32 func_80108474(s32, f32 *, s32);
extern int D_80800B98_chcrusher[];
extern s32 D_80800B30_chcrusher[];
extern f32 D_80800B48_chcrusher[][4];
extern s32 D_80800BE0_chcrusher[];
extern f32 func_800D8FF8(void);
extern s32 func_80101E14(Actor *, f32);
extern s32 func_800E1610(s32, f32, f32, f32 *);
extern s32 func_80018820(s32, f32, f32);
typedef struct CrusherBounds {
    f32 p0[3];
    f32 p1[3];
} CrusherBounds;
extern void func_8008FE94(s32, f32 *);
extern int D_80800C40_chcrusher[];
extern s32 D_80800C88_chcrusher[3];
extern s32 D_80800C94_chcrusher[3];
extern s32 D_80800CA0_chcrusher[3];
typedef struct {
    s32 xyz[3];
} local_struct;
extern int D_80800CC8_chcrusher[];
extern void func_800EFA4C(u8 *, f32, f32, f32);
extern s32 D_80800D20_chcrusher[];
extern int D_80800D68_chcrusher[];
extern void func_800BABB8(int, void *, int, float, void *);
extern u32 D_80800BF0_chcrusher[];
typedef struct {
    u8 local_0[0x74];
    u32 local_1 : 4;
    u32 local_2 : 1;
    u32 local_3 : 27;
} CrusherFlagsView;
extern u32 D_80800D10_chcrusher[];
extern void func_80101CDC(Actor *, f32);
void func_808003E4_chcrusher();
void func_80800508_chcrusher();
void func_80800394_chcrusher();

// On message 0x49 spawns actor 0x386.
s32 func_80800000_chcrusher(f32 *params, s32 msg, S16Pair unk_2)
{
    f32 spawn_pos[3];
    if (msg == 0x49) {
        spawn_pos[0] = params[1];
        spawn_pos[2] = params[3];
        spawn_pos[1] = 0.0f;
        func_80108474(0x386, spawn_pos, -0x5A);
    } else {
        return 0;
    }
    return 1;
}

int *chcrusher_entrypoint_0()
{
    return D_80800B98_chcrusher;
}

int func_80800068_chcrusher(Actor *actor)
{
    func_80101870();
    if (actor->unk7C_12) {
        func_800DBEFC(func_80104130(), 6, (u8 *) actor + 0x18);
        func_800DBEFC(func_80104130(), 4, (u8 *) actor + 0x28);
    }
}

// Crusher state machine, keyed on flag 0x4FB (crusher on).
void func_808000D4_chcrusher(Actor *actor)
{
    f32 *pos;

    switch (actor->unk70_10) {
        default:
            pos = actor->position;
            break;
        case 1:
            if (!func_800DA298(0x4FB)) {
                func_80101FDC(actor, 3);
            }
            pos = actor->position;
            break;
        case 2:
            if (actor->unk7C_12 && func_80101E14(actor, 0.75f)) {
                func_80800394_chcrusher(actor);
            }
            // Slam: sound, camera shake, rumble.
            if (func_80101E14(actor, 0.9f)) {
                pos = actor->position;
                _subaddieaudioquick_entrypoint_2(actor, pos, D_80800B30_chcrusher);
                func_800E1610(2, 80.0f, 0.85f, pos);
                func_80018820(0, 2.5f, 0.25f);
            }
            pos = actor->position;
            if (func_80101E14(actor, 0.48f)) {
                if (func_800DA298(0x4FB)) {
                    func_80101FDC(actor, 1);
                } else {
                    func_80101FDC(actor, 3);
                    actor->unk58 = 0.0f;
                }
            }
            break;
        case 3:
            actor->unk64_20 = 0;
            actor->unk58 += func_800D8FF8();
            if (D_80800B48_chcrusher[actor->unk6C_0][(s32) ((f32 *) actor->actorData)[7]] <=
                actor->unk58) {
                if ((s32) ((f32 *) actor->actorData)[7] < 3) {
                    ((f32 *) actor->actorData)[7] += 1.0f;
                } else {
                    ((f32 *) actor->actorData)[7] = 0.0f;
                }
                if (func_800DA298(0x4FB)) {
                    func_80101FDC(actor, 1);
                } else {
                    func_80101FDC(actor, 2);
                }
            }
            pos = actor->position;
    }
    if (actor->unk7C_12 && !actor->unk64_20 && actor->unk70_10 == 2) {
        func_808003E4_chcrusher(actor);
    }
    if (actor->unk7C_12) {
        func_80800508_chcrusher(actor);
    }
    _subaddieaudioloop_entrypoint_4(actor, pos, ((f32 *) actor->actorData)[3] > 0.0f,
                                    D_80800BE0_chcrusher);
    if (((f32 *) actor->actorData)[3] > 0.0f) {
        ((f32 *) actor->actorData)[3] -= func_800D8FF8();
    }
}

void func_80800394_chcrusher(actor) void *actor;
{
    func_800BABB8(0, (void *) ((char *) actor + 0x28), 0, 1.0f, D_80800BF0_chcrusher);
    *(f32 *) ((char *) actor + 0x24) = 0.3f;
}

// Hurts the player if inside the crush box.
void func_808003E4_chcrusher(actor) Actor *actor;
{
    CrusherBounds box;
    f32 half_x;
    f32 half_z;
    f32 player_pos[3];

    half_x = actor->position[0] - *(f32 *) actor->actorData;
    half_z = *((f32 *) actor->actorData + 2) - actor->position[2];
    half_x += 25.0f;
    half_z += 25.0f;
    func_8008FE94(5, player_pos);
    box.p1[0] = actor->position[0] + half_x;
    box.p0[0] = actor->position[0] - half_x;
    box.p1[1] = *((f32 *) actor->actorData + 1);
    box.p0[1] = *((f32 *) actor->actorData + 1) + 100.0f;
    box.p1[2] = actor->position[2] + half_z;
    box.p0[2] = actor->position[2] - half_z;
    if (player_pos[2] < box.p1[2] && *((f32 *) actor->actorData + 1) < player_pos[1] &&
        player_pos[0] < box.p1[0] && box.p0[0] < player_pos[0]) {
        actor->unk64_20 = 1;
        if (func_80090150()) {
            func_800904C8(0x59);
        }
    }
}

void func_80800508_chcrusher(actor) Actor *actor;
{
    f32 box_min[3];
    f32 box_max[3];
    f32 half_x;
    f32 half_z;
    f32 player_pos[3];

    half_x = actor->position[0] - *(f32 *) &actor->actorData[0];
    half_z = *(f32 *) &actor->actorData[2] - actor->position[2];
    half_z += 25.0f;
    func_8010D254(player_pos);
    box_min[0] = actor->position[0] - half_x;
    box_max[0] = actor->position[0] + half_x;
    box_min[1] = *(f32 *) &actor->actorData[1];
    box_max[1] = *(f32 *) &actor->actorData[1] + 1000.0f;
    box_min[2] = actor->position[2] - half_z;
    box_max[2] = actor->position[2] + half_z;
    func_8008FA94(box_min, box_max);
}

void func_808005C0_chcrusher(s32 arg0)
{
}

void func_808005C8_chcrusher(u16 *actor)
{
    u32 variant;

    variant = (u32) (u16) *(u16 *) ((s8 *) actor + 0x76) >> 7;
    switch (variant) {
        default:
            *(u16 *) ((s8 *) actor + 0x6E) = (u16) (*(u16 *) ((s8 *) actor + 0x6E) & 0xFE00);
            break;
        case 0x32:
            *(u16 *) ((s8 *) actor + 0x6E) = (u16) (*(u16 *) ((s8 *) actor + 0x6E) & 0xFE00);
            break;
        case 0x33:
            *(u16 *) ((s8 *) actor + 0x6E) =
                (u16) ((*(u16 *) ((s8 *) actor + 0x6E) & 0xFE00) | 1);
            break;
        case 0x34:
            *(u16 *) ((s8 *) actor + 0x6E) =
                (u16) ((*(u16 *) ((s8 *) actor + 0x6E) & 0xFE00) | 2);
    }
    *(f32 *) ((s8 *) actor + 0x34) = 0.0f;
    *(f32 *) ((s8 *) actor + 0xC) = -365.0f;
    *(f32 *) ((s8 *) actor + 8) = 10.0f;
    func_80101FDC(actor, 1);
    func_80101EE4(actor, 0x3EF5C28F);
}

int func_80800684_chcrusher(Actor *actor, s32 msg, s32 unk_2)
{
    switch (msg) {
        case 0x3E:
            if (actor->unk70_10 == 2) {
                func_8010D254((f32 *) actor->actorData);
                if (*(f32 *) ((u8 *) actor + 0x20) < -50.0f) {
                    *(f32 *) ((u8 *) actor + 0x18) -= 50.0f;
                    func_80090494(6, (f32 *) actor->actorData, actor);
                }
            }
            break;
        default:
            return 0;
    }
    return 1;
}

int *chcrusher_entrypoint_1()
{
    return D_80800C40_chcrusher;
}

void func_80800734_chcrusher(u8 *actor)
{
    s32 switch_on;
    local_struct bounds_min;
    local_struct bounds_max;

    switch_on = func_800DA298(0x4FB);
    if (((u32) (u16) *(u16 *) ((s8 *) actor + 0x76) >> 7) == 0x32) {
        _subaddieaudioloop_entrypoint_4(actor, actor + 4, switch_on, D_80800CA0_chcrusher);
        bounds_min = *(local_struct *) D_80800C88_chcrusher;
        bounds_max = *(local_struct *) D_80800C94_chcrusher;
        func_8008FA94(bounds_min.xyz, bounds_max.xyz);
    }
    switch ((u32) *(u16 *) ((s8 *) actor + 0x72) >> 0xA) {
        case 1:
            if (switch_on != 0) {
                func_80101FDC(actor, 2, switch_on);
            }
            return;
        case 2:
            if (switch_on == 0) {
                func_80101FDC(actor, 1, switch_on);
            }
            *(f32 *) ((s8 *) actor + 0x4C) += *(f32 *) ((s8 *) actor + 0x54);
    }
}

void func_80800838_chcrusher(Actor *actor)
{
    if (actor->unk74_7 != 0x32) {
        actor->unk54 = func_800D8FF8() * -240.0f;
        actor->position[1] = 350.0f;
        actor->rotation[2] += 22.5f;
        actor->position[2] = -635.0f;
    } else {
        actor->unk54 = func_800D8FF8() * 240.0f;
        actor->position[1] = 100.0f;
        actor->position[2] = -660.0f;
    }
    actor->position[0] = -2350.0f;
}

int *chcrusher_entrypoint_2()
{
    return D_80800CC8_chcrusher;
}

// Conveyor belt: while switched on, pushes the player along -x.
void func_808008FC_chcrusher(Actor *actor)
{
    s32 switch_on;
    f32 player_pos[3];
    switch_on = func_800DA298(0x4FB);
    _subaddieaudioloop_entrypoint_4(actor, actor->position, switch_on, D_80800D10_chcrusher);
    switch (actor->unk70_10) {
        case 1:
            if (switch_on) {
                func_80101FDC(actor, 2);
                ((CrusherFlagsView *) actor)->local_2 = 1;
            }
            break;
        case 2:
            if (!switch_on) {
                func_80101FDC(actor, 1);
                ((CrusherFlagsView *) actor)->local_2 = 0;
            }
            func_8010D254(player_pos);
            if (func_80090248() && player_pos[0] < 2000.0f && player_pos[0] > -2300.0f &&
                player_pos[2] < 0.0f) {
                if (func_800DA298(0)) {
                    player_pos[0] -= 144.0f * func_800D8FF8();
                } else {
                    player_pos[0] -= 504.0f * func_800D8FF8();
                }
                func_800907C0(player_pos);
            }
            if (func_800DA298(0)) {
                func_80101CDC(actor, 33.0f);
            } else {
                func_80101CDC(actor, 9.4285717f);
            }
    }
}

void func_80800A98_chcrusher(u8 *actor)
{
    func_800EFA4C(actor + 4, 0.0f, -10.0f, 0.0f);
}

void func_80800ACC_chcrusher(s32 arg0)
{
}

void func_80800AD4_chcrusher(s32 arg0)
{
    _chswitch_entrypoint_14(arg0, FLAG_4FB_UNK);
}

int chcrusher_entrypoint_3()
{
    return D_80800D20_chcrusher;
}

int chcrusher_entrypoint_4()
{
    return (int) D_80800D68_chcrusher;
}

extern void func_80105834();
extern void func_80107C2C();
extern int func_80101870();
extern void func_80108ED0();
extern void _chswitch_entrypoint_13();
extern void _chswitch_entrypoint_0();
// TU-NOTE: the overlay .data is defined here in C (values from the ROM); IDO schedules some functions differently unless the tables are in the same unit.
s32 D_80800B30_chcrusher[6] = {0x1304CE, 0xD00E6, 0x1330016, 0x7D000001, 0x1F41388, 0x0};
f32 D_80800B48_chcrusher[3][4] = {0.5f, 1.0f, 2.0f, 1.0f, 2.0f, 2.0f,
                                  2.0f, 2.0f, 1.0f, 2.0f, 0.5f, 2.0f};
u32 D_80800B78_chcrusher[8] = {0x0,        0x0,      0x4B189680, 0x870000,
                               0x3F4CCCCD, 0x870000, 0x4B189680, 0x870000};
int D_80800B98_chcrusher[18] = {0x25E017A,
                                0x6830001,
                                (u32) &D_80800B78_chcrusher,
                                (u32) func_808000D4_chcrusher,
                                (u32) func_80105834,
                                (u32) func_80800068_chcrusher,
                                0x0,
                                0x0,
                                0x0,
                                0x1008000E,
                                (u32) func_808005C0_chcrusher,
                                0x0,
                                0x0,
                                (u32) func_808005C8_chcrusher,
                                (u32) func_80107C2C,
                                -0x7FFEFFFE,
                                (u32) func_80800000_chcrusher,
                                0x0};
s32 D_80800BE0_chcrusher[4] = {0x1304DC, 0x164E20, 0x101F4, 0x13880000};
u32 D_80800BF0_chcrusher[20] = {0xA10001D, 0x9DD0019, 0x7,        0xAFFFB,    0xFFFB0050,
                                0x50005,   0x2C,      0xFFE2FFFB, 0xC8001E,   0x50190,
                                0x1B0005,  0xA0022,   0x33,       0xB30180,   0x2A000C,
                                0x190040,  0x800015,  0xD9,       0x64020028, 0x730000};
int D_80800C40_chcrusher[18] = {0x260017C,
                                0x6860001,
                                0x0,
                                (u32) func_80800734_chcrusher,
                                (u32) func_80105834,
                                (u32) func_80101870,
                                0x0,
                                0x0,
                                0x0,
                                0x880404,
                                0x0,
                                (u32) func_80108ED0,
                                0x0,
                                (u32) func_80800838_chcrusher,
                                (u32) func_80107C2C,
                                0x0,
                                (u32) func_80800684_chcrusher,
                                0x0};
s32 D_80800C88_chcrusher[3] = {-0x3AF04000, -0x3DB80000, -0x3BD74000};
s32 D_80800C94_chcrusher[3] = {-0x3AF3B000, 0x44340000, -0x3DB80000};
s32 D_80800CA0_chcrusher[3] = {0x1304CB, 0x167D00, 0x101F4};
static u32 D_80800CA0_chcrusher_rest[1] = {0x13880000};
u32 D_80800CB0_chcrusher[6] = {0x0, 0x0, 0x4B189680, 0x8D0000, 0x4116DB6E, 0x8D0000};
int D_80800CC8_chcrusher[18] = {0x25F017B,
                                0x6840001,
                                (u32) &D_80800CB0_chcrusher,
                                (u32) func_808008FC_chcrusher,
                                (u32) func_80105834,
                                (u32) func_80101870,
                                0x0,
                                0x0,
                                0x0,
                                0x80404,
                                (u32) func_80800ACC_chcrusher,
                                0x0,
                                0x0,
                                (u32) func_80800A98_chcrusher,
                                (u32) func_80107C2C,
                                -0x7F7FFFFE,
                                0x0,
                                0x0};
u32 D_80800D10_chcrusher[4] = {0x1304CD, 0x164650, 0x101F4, 0x13880000};
s32 D_80800D20_chcrusher[18] = {0x8017D,
                                0x6850001,
                                -0x7FEE5D68,
                                (u32) _chswitch_entrypoint_13,
                                (u32) func_80105834,
                                (u32) func_80101870,
                                0x0,
                                0x0,
                                0x0,
                                0x1008080C,
                                0x0,
                                (u32) _chswitch_entrypoint_0,
                                0x0,
                                (u32) func_80800AD4_chcrusher,
                                (u32) func_80107C2C,
                                -0x7FFEF800,
                                0x0,
                                0x0};
int D_80800D68_chcrusher[18] = {0x1580386,
                                0x6AC0001,
                                0x0,
                                0x0,
                                (u32) func_80105834,
                                (u32) func_80101870,
                                0x0,
                                0x0,
                                0x0,
                                0x20004,
                                0x0,
                                0x0,
                                0x0,
                                0x0,
                                (u32) func_80107C2C,
                                -0x7FFFF7FE,
                                0x0,
                                0x0};
