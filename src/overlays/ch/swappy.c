#include "common.h"

typedef struct {
    u8 pad_0[0x7C];
    u32 pad_1 : 17;
    u32 unk_7C : 1;
    u32 pad_2 : 14;
} SwappyFlags31;
extern s32 func_800EFFB4(f32 *, f32, f32 *);
extern void _sudeflect_entrypoint_1(f32 *, f32, f32, f32, s32);
typedef struct {
    u8 pad_0[0x1A];
    u16 unk_1A;
    u8 pad_1[8];
    u32 unk_24;
} SwappyContact;
typedef union {
    s32 value;
    s16 halves[2];
} SwappyEventValue;
extern u8 D_808006CC_chswappy[];
extern u8 D_80800690_chswappy[];
extern f32 func_800DC178(f32, f32);
extern void func_800EEB9C(f32 *, f32, f32);
extern s32 func_800BABB8(s32, f32 *, f32 *, f32, void *);
extern int D_808006D4_chswappy[];
extern void func_80102FDC(Actor *, f32);
typedef struct {
    u8 pad[0x7E];
    u8 pad_0 : 1;
    u8 flag_40 : 1;
    u8 pad_1 : 1;
    u8 flag_10 : 1;
    u8 pad_2 : 4;
} SwappyFlags;
extern s32 func_800E3E8C(f32 *, f32);
extern f32 func_800EEB40(f32 *, f32 *);
int chswappy_entrypoint_0();

// Visible only while Banjo and Kazooie are split up (party mode 2).
void func_80800000_chswappy(Actor *actor)
{
    func_80102FDC(actor, actor->scale * 0.6f);
    if (func_800F8B88() == 2) {
        _subaddiefade_entrypoint_1(actor, 255);
        func_80103110(actor, 1);
        func_8010A590(actor);
        func_808000B0_chswappy(actor, 1);
    } else {
        _subaddiefade_entrypoint_1(actor, 0);
        func_80103110(actor, 0);
        func_8010A570(actor);
        func_808000B0_chswappy(actor, 1);
    }
}

int func_808000B0_chswappy(s32 actor, s32 state)
{
    func_80101FDC();
    switch (state) {
        case 1:
            _subaddieDll_entrypoint_4(actor, 0);

        case 2:

        case 3:

            break;
    }
}

// Per-frame update; pushes solo Banjo away and finishes the interaction.
void func_80800108_chswappy(Actor *actor)
{
    int touched;
    f32 banjo_pos[3];
    s32 player;

    touched = (s32) actor->unk70_10 == 2;
    switch (actor->unk70_10) {
        case 1:
            player = _plsu_entrypoint_1(10);
            if (player != -1) {
                func_800F5A00(player, banjo_pos);
                if (func_800EFFB4(actor->position, 100.0f, banjo_pos)) {
                    _sudeflect_entrypoint_1(banjo_pos, 125.0f, 0.0f, 40.0f, 28);
                }
            }
            break;
        case 2:
            func_808000B0_chswappy(actor, 3);
            break;
        case 3:
            if (!func_800F6BE4(actor->unk79_4) || func_800F7B9C(actor->unk79_4, 0x41) == 2) {
                func_808000B0_chswappy(actor, 1);
            }
    }
    if (func_800F8B88() == 2) {
        chswappy_entrypoint_0(actor, touched);
    }
    ((SwappyFlags31 *) actor)->unk_7C = 0;
}

// Collision callback: a split-up character touches Swappy.
void func_80800234_chswappy(Actor *actor, SwappyContact *contact)
{
    u32 player;

    if ((contact->unk_24 >> 22) == 0) {
        player = (u32) contact->unk_1A >> 5;
        if (func_800F64A4(player, 0x600) && (actor->unk74_7 != 0x32 || func_800F55D0(player)) &&
            (actor->unk70_10 == 3 || func_800F7CF4(player, 0x40, actor->position) == 2)) {
            actor->unk79_4 = player;
            func_808000B0_chswappy(actor, 2);
        }
    }
}

s32 func_80800300_chswappy(Actor *actor, s32 msg, SwappyEventValue arg)
{
    switch (msg) {
        case 0x95:
            func_808000B0_chswappy(actor, 1);
            break;
        case 0x16:
            func_808000B0_chswappy(actor, 1);
            func_80103110(actor, 1);
            func_8010A590(actor);
            _subaddiefade_entrypoint_2(actor);
            break;
        case 0x17:
            func_808000B0_chswappy(actor, 1);
            func_80103110(actor, 0);
            func_8010A570(actor);
            _subaddiefade_entrypoint_5(actor);
            break;
        case 0x3E:
            func_80800234_chswappy(actor, arg.value);
            break;
        default:
            return 0;
    }
    return 1;
}

void func_808003DC_chswappy(Actor *actor, s32 unk_0)
{
    s32 in_range;
    f32 player_pos[3];

    in_range = func_800E3E8C(actor->position, 300.0f);
    func_8010A73C(actor, unk_0);
    if (in_range && func_800F8B88() == 2) {
        func_800E3980(player_pos);
        if (func_800EEB40(actor->position, player_pos) < 6250000.0f) {
            ((SwappyFlags *) actor)->flag_10 = 1;
        }
        ((SwappyFlags *) actor)->flag_40 = 1;
    }
}

// Sparkle trail toward the player; also used by ch/jamjarsdummy.c.
int chswappy_entrypoint_0(actor, touched)
Actor *actor;
s32 touched;
{
    f32 player_pos[3];
    f32 origin[3];
    f32 offset[3];
    s32 particle;
    s32 i;
    f32 angles[2];

    if (!actor->unk7C_12)
        return;
    if (touched) {
        particle = func_800B5BE4(0x1D);
        func_800BA3FC(particle, 0x9DE);
    } else {
        i = func_800DC128(0, 3);
        particle = func_800B5BE4(i + 0x1E);
        func_800BA3FC(particle, ((u16 *) D_808006CC_chswappy)[i]);
    }
    func_800E3980(player_pos);
    func_800F18FC(actor->position, player_pos, angles);
    func_800EE7F8(origin, actor->position);
    origin[1] -= 200.0f;
    for (i = 0; i != 2; i++) {
        func_800EEB9C(offset, angles[1] + func_800DC178(-90.0f, 90.0f), 50.0f);
        func_800EF04C(offset, actor->position);
        offset[1] += -30.0f + func_800DC178(0.0f, 100.0f);
        func_800BABB8(particle, offset, origin, 1.0f, D_80800690_chswappy);
    }
}

int *chswappy_entrypoint_1()
{
    return &D_808006D4_chswappy;
}

extern void func_80105834();
extern void func_80108ED0();
extern void func_80107C2C();
// TU-NOTE: the overlay .data is defined here in C. The tables hold pointers to functions of this
// file, and IDO's assembler schedules some of them differently unless they are in the same unit.
// Values are taken from the ROM; D_808006D4_chswappy is declared as int[] (same address).
u8 D_80800690_chswappy[60] = {0x0,  0x2B, 0x0, 0x66, 0x0, 0x80, 0x0, 0x2C, 0x0, 0x0,  0x0,  0x32,
                              0x0,  0x0,  0x0, 0x0,  0x0, 0x64, 0x0, 0x0,  0x0, 0x27, 0xFF, 0x38,
                              0xFF, 0x38, 0x0, 0xC8, 0x0, 0xC8, 0x0, 0x22, 0x0, 0x4C, 0x0,  0x66,
                              0x0,  0x26, 0x0, 0x33, 0x0, 0x15, 0x0, 0x33, 0x0, 0xB3, 0x0,  0x16,
                              0x0,  0x4,  0x0, 0x33, 0x0, 0x2,  0x1, 0x1A, 0x0, 0x0,  0x0,  0x0};
u8 D_808006CC_chswappy[8] = {0x9, 0xE4, 0x9, 0xE0, 0x9, 0xE2, 0x0, 0x0};
int D_808006D4_chswappy[19] = {0x26A0158,
                               0x6FB0001,
                               0x0,
                               (u32) func_80800108_chswappy,
                               (u32) func_80105834,
                               (u32) func_808003DC_chswappy,
                               0x0,
                               0x0,
                               0x0,
                               0x4,
                               0x0,
                               (u32) func_80108ED0,
                               0x0,
                               (u32) func_80800000_chswappy,
                               (u32) func_80107C2C,
                               -0x7FFFBC00,
                               (u32) func_80800300_chswappy,
                               0x0,
                               0x0};
