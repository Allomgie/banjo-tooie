// Banjo-Kazooie carrying a held object: idle, walk and run states plus drone and rest wrappers.
// TU-NOTE: the .data of this overlay is defined in this file; its tables point to functions here,
// and IDO schedules some of them differently unless they share a unit. Values come from the ROM.
#include "common.h"
#include "overlays/ba/playerstate.h"

extern f32 bastick_getZonePosition(PlayerState *);
extern s32 bastick_getZone();
extern f32 func_800F1214(f32, f32, f32);
extern void bastick_setZoneMax(PlayerState *, s32, f32);
extern s32 D_808007B0_bscarry[];
extern s32 D_808007C0_bscarry[];
extern s32 D_808007D0_bscarry[];
extern s32 D_808007E0_bscarry[];
extern s32 D_808007F0_bscarry[];
extern void baanim_playForDuration_loopSmooth(PlayerState *, s32, f32);
extern void func_8009FFD8(PlayerState *, s32, s32, s32, s32);
extern void func_8008C9F0(PlayerState *, f32, f32, f32, f32);

// Interrupt handler: hits (8, 22) change state, 18 and others are forwarded.
void func_80800000_bscarry(s32 player)
{
    s32 interrupt;

    interrupt = func_8009E6EC();
    switch (interrupt) {
        case 8:
            func_8009E830(player, 2);
            bs_setState(player, 0x3C);
            return;
        case 18:
            func_8008F6B8(player, func_8008E9AC(player));
            return;
        case 22:
            if (bastatetimer_isDone(player, 1) != 0) {
                bs_setState(player, 0x5B);
                func_8009E830(player, 2);
                return;
            }
            func_8009E830(player, 1);
            return;
        default:
            func_80099B94(player);
    }
}

int func_808000D0_bscarry(s32 player)
{
    switch (func_8009E6EC()) {
        case 8:

        case 0x12:

        case 0x16:
            // Matching: empty block steers IDO's register allocation.
            if (!player) {
            }
            func_80800000_bscarry(player);
            break;

        default:
            _bsdrone_entrypoint_3();
    }
}

extern void baphysics_set_target_horizontal_velocity(Actor *a0, f32 a1);

// Sets walk speed from the stick zone: 0 stop, 1 slow, 2 fast.
void func_80800128_bscarry(PlayerState *player)
{
    f32 stick;

    stick = bastick_getZonePosition(player);
    switch (bastick_getZone(player)) {
        case 0:
            baphysics_set_target_horizontal_velocity(player, 0.0f);
            break;
        case 1:
            baphysics_set_target_horizontal_velocity(player, func_800F1214(stick, 30.0f, 60.0f));
            break;
        case 2:
            baphysics_set_target_horizontal_velocity(player,
                                                     func_800F1214(stick, 60.0f, 300.0f));
    }
}

// Pops the carry stick zone.
int func_808001D4_bscarry(player)
s32 player;
{
    if (!func_8009E69C(player, 0x400)) {
        bastick_popZone(player);
    }
}

// Pushes the carry stick zone (0.03 / 0.2 / 1.0).
void func_80800208_bscarry(player) PlayerState *player;
{
    if (!func_8009E6C4(player, 0x400)) {
        bastick_pushZone(player);
        bastick_setZoneMax(player, 0, 0.03f);
        bastick_setZoneMax(player, 1, 0.2f);
        bastick_setZoneMax(player, 2, 1.0f);
    }
}

void func_8080027C_bscarry()
{
    func_808001D4_bscarry();
}

void func_8080029C_bscarry(PlayerState *player)
{
    func_80800208_bscarry(player);
    baanim_playForDuration_loopSmooth(player, 0x28, 0.8f);
    func_8009FFD8(player, 2, 1, 1, 2);
    func_8008C9F0(player, 30.0f, 60.0f, 1.8f, 1.2f);
}

void func_80800310_bscarry(s32 player)
{
    s32 next_state;
    s32 zone;

    next_state = 0;
    func_800A2CE8(player, 0x3ECCCCCD, 4);
    func_800A2CE8(player, 0x3F666666, 3);
    func_80800128_bscarry(player);
    zone = bastick_getZone(player);
    switch (zone) {
        case 0:
            if (func_8009BCD4(player, 0x3F800000) != 0) {
                next_state = 0x3A;
            }
            break;
        case 2:
            next_state = 0x3B;
    }
    if (_bahold_entrypoint_5(player) == 0) {
        next_state = 1;
    }
    bs_setState(player, next_state);
}

int bscarry_entrypoint_0(s32 index)
{
    return D_808007B0_bscarry[index];
}

void func_808003D8_bscarry()
{
    func_808001D4_bscarry();
}

void func_808003F8_bscarry(s32 player)
{
    func_80800208_bscarry();
    baanim_playForDuration_loopSmooth(player, 0x72, 1.2f);
    func_8009FFD8(player, 1, 1, 1, 2);
    // Matching: needed for the match.
    baphysics_set_target_horizontal_velocity(player, (double) 0);
    func_8009BFE4(player, 0x447A0000, 0x41400000);
    baroll_setAngularVelocity(player, 0x447A0000, 0x41400000);
}

int func_8080047C_bscarry(Actor *player)
{
    s32 next_state;
    next_state = 0;
    switch (bastick_getZone()) {
        case 1:
            next_state = 0x9F;
            break;
        case 2:
            next_state = 0x3B;
    }

    if (_bahold_entrypoint_5(player, next_state) == 0) {
        next_state = 1;
    }
    bs_setState(player, next_state);
}

int bscarry_entrypoint_1(s32 index)
{
    return D_808007C0_bscarry[index];
}

void func_80800500_bscarry()
{
    func_808001D4_bscarry();
}

void func_80800520_bscarry(PlayerState *player)
{
    func_80800208_bscarry(player);
    baanim_playForDuration_loopSmooth(player, 0x73, 0.8f);
    func_8009FFD8(player, 2, 1, 1, 2);
    func_8008C9F0(player, 60.0f, 300.0f, 0.84f, 0.4f);
}

void func_80800594_bscarry(Actor *player)
{
    s32 zone;
    u8 next_state = 0;
    func_800A2CE8(player, 0x3ECCCCCD, 4);
    func_800A2CE8(player, 0x3F666666, 3);
    func_80800128_bscarry(player);
    zone = bastick_getZone(player);
    switch (zone) {
        case 0:
            if (func_8009BCD4(player, 0x3F800000) != 0) {
                next_state = 0x3A;
            }
            break;

        case 1:
            next_state = 0x9F;
    }

    if (_bahold_entrypoint_5(player) == 0) {
        next_state = 1;
    }
    bs_setState(player, next_state);
}

int bscarry_entrypoint_2(s32 index)
{
    return D_808007D0_bscarry[index];
}

void func_8080065C_bscarry(s32 player)
{
    _bsdrone_entrypoint_2();
    func_808001D4_bscarry(player);
}

void func_80800684_bscarry(s32 player)
{
    func_80800208_bscarry();
    _bsdrone_entrypoint_0(player);
}

void func_808006AC_bscarry(PlayerState *player)
{
    _bsdrone_entrypoint_1(player);
}

int bscarry_entrypoint_3(s32 index)
{
    return D_808007E0_bscarry[index];
}

void func_808006E0_bscarry(s32 player)
{
    _bsrest_entrypoint_14();
    func_808001D4_bscarry(player);
}

void func_80800708_bscarry(s32 player)
{
    func_80800208_bscarry();
    _bsrest_entrypoint_16(player);
}

int func_80800730_bscarry(Actor *player)
{
    s32 next_state;
    next_state = 0;
    if (_bsrest_entrypoint_20()) {
        next_state = 0x3A;
    }
    if (!_bahold_entrypoint_5(player, next_state)) {
        next_state = 0x73;
    }
    bs_setState(player, next_state);
}

int bscarry_entrypoint_4(s32 index)
{
    return D_808007F0_bscarry[index];
}

s32 D_808007B0_bscarry[4] = {(u32) func_8080027C_bscarry, (u32) func_8080029C_bscarry,
                             (u32) func_80800310_bscarry, (u32) func_80800000_bscarry};
s32 D_808007C0_bscarry[4] = {(u32) func_808003D8_bscarry, (u32) func_808003F8_bscarry,
                             (u32) func_8080047C_bscarry, (u32) func_80800000_bscarry};
s32 D_808007D0_bscarry[4] = {(u32) func_80800500_bscarry, (u32) func_80800520_bscarry,
                             (u32) func_80800594_bscarry, (u32) func_80800000_bscarry};
s32 D_808007E0_bscarry[4] = {(u32) func_8080065C_bscarry, (u32) func_80800684_bscarry,
                             (u32) func_808006AC_bscarry, (u32) func_808000D0_bscarry};
s32 D_808007F0_bscarry[4] = {(u32) func_808006E0_bscarry, (u32) func_80800708_bscarry,
                             (u32) func_80800730_bscarry, (u32) func_80800000_bscarry};
