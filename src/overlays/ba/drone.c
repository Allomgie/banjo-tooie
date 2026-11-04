// Player drone controller: takes requests to drive the player through scripted states (goto,
// bitten, bubbled, fall-die, transform, vanish, look, wait), stores their parameters and picks
// the form-specific state; also answers "is in drone mode X" queries.
#include "common.h"
#include "playerstate.h"

extern u8 D_80800630_badrone[];
typedef struct {
    u8 pad_0;
    u8 mode;
    u8 pad_2[6];
    f32 duration;
    f32 speed;
    f32 target_pos[3];
} DroneTransition;
typedef struct {
    u8 pad_0[0x54];
    DroneTransition *drone;
} DronePlayerView;
extern void func_800EE7F8();
extern s32 _badata_entrypoint_21();
extern void bs_setState(void *, s32);
extern void func_8009C128(s32, f32 *);
extern void func_800EFB24(f32 *, f32 *, f32 *);
extern f32 func_800EEFFC(f32 *);
extern void _badata_entrypoint_23();
typedef struct {
    u8 pad0[0x54];
    void *drone;
} Badrones;
extern void baflag_clear(s32, s32);

s32 badrone_entrypoint_0()
{
    return 0x4C;
}

u8 badrone_entrypoint_1(u8 *player)
{
    return D_80800630_badrone[**(u8 **) (player + 0x54)];
}

void badrone_entrypoint_2(s32 player, s32 out_pos)
{
    func_800EE7F8(out_pos, *(s32 *) (player + 0x54) + 0x24);
}

u8 badrone_entrypoint_3(s32 player)
{
    return **(u8 **) (player + 0x54);
}

void badrone_entrypoint_4(u8 *player)
{
    u8 *drone;

    drone = *(u8 **) (player + 0x54);
    *(u8 *) (drone + 0) = *(u8 *) (drone + 1);
}

void badrone_entrypoint_5(u8 *player)
{
    *(s8 *) ((s8 *) *(u8 **) ((s8 *) player + 0x54) + 4) = 0;
    *(s8 *) ((s8 *) *(u8 **) ((s8 *) player + 0x54) + 5) = 1;
    *(f32 *) ((s8 *) *(u8 **) ((s8 *) player + 0x54) + 8) = 1.0f;
    func_800EFD24(*(u8 **) ((s8 *) player + 0x54) + 0x10, player);
    *(f32 *) ((s8 *) *(u8 **) ((s8 *) player + 0x54) + 0xC) = 1.0f;
    *(s32 *) ((s8 *) *(u8 **) ((s8 *) player + 0x54) + 0x1C) = 0;
}

// Calls the stored callback, if any.
void badrone_entrypoint_6(u8 *player)
{
    s32 (*callback)(s32, s32, u8 *);
    u8 *drone;

    drone = *(u8 **) ((s8 *) player + 0x54);
    callback = *(s32(**)(s32, s32, u8 *))((s8 *) drone + 0x1C);
    if (callback != NULL) {
        callback(*(s32 *) ((s8 *) drone + 0x20), *(s32 *) ((s8 *) player + 0x184), player);
    }
}

s32 badrone_entrypoint_7(s32 player)
{
    return ((u8 *) *(u8 **) (player + 0x54))[4];
}

void badrone_entrypoint_8(u8 *player, s32 out_pos, f32 *out_duration, f32 *out_speed)
{
    func_800EE7F8(out_pos, *(u8 **) ((s8 *) player + 0x54) + 0x10);
    *out_duration = *(f32 *) ((s8 *) *(u8 **) ((s8 *) player + 0x54) + 8);
    *out_speed = *(f32 *) ((s8 *) *(u8 **) ((s8 *) player + 0x54) + 0xC);
}

s32 badrone_entrypoint_9(s32 player)
{
    return ((u8 *) *(u8 **) (player + 0x54))[5];
}

void badrone_entrypoint_10(void *player, s32 value)
{
    ((s8 *) *(void **) ((char *) player + 0x54))[4] = value;
}

void badrone_entrypoint_11(u8 *player, s32 callback, s32 callback_arg)
{
    *(s32 *) ((s8 *) *(u8 **) ((s8 *) player + 0x54) + 0x1C) = callback;
    *(s32 *) ((s8 *) *(u8 **) ((s8 *) player + 0x54) + 0x20) = callback_arg;
}

void badrone_entrypoint_12(void *player, s32 value)
{
    ((s8 *) *(void **) ((char *) player + 0x54))[5] = value;
}

void badrone_entrypoint_13(u8 *player, s32 unk_0)
{
    func_800EE7F8(*(u8 **) ((s8 *) player + 0x54) + 0x10);
    if ((**(u8 **) ((s8 *) player + 0x54) == 1) && (func_8009BAF4(player) == 0xC)) {
        _bamovegoto_entrypoint_12(player, unk_0);
    }
}

// Goto request: move to target_pos at the given speed.
void badrone_entrypoint_14(DronePlayerView *player, f32 target_pos[3], f32 speed)
{
    func_800EE7F8(player->drone->target_pos, target_pos);
    player->drone->speed = speed;
    player->drone->duration = 0.0f;
    player->drone->mode = 1;
    bs_setState(player, _badata_entrypoint_21(player));
}

// Goto request: move to target_pos within the given duration.
void badrone_entrypoint_15(DronePlayerView *player, f32 target_pos[3], f32 duration)
{
    func_800EE7F8(player->drone->target_pos, target_pos);
    player->drone->duration = duration;
    player->drone->speed = 0.0f;
    player->drone->mode = 1;
    bs_setState(player, _badata_entrypoint_21(player));
}

void badrone_entrypoint_16(s32 player, f32 *target_pos, f32 speed)
{
    f32 player_pos[3];
    f32 delta[3];
    func_8009C128(player, player_pos);
    func_800EFB24(delta, target_pos, player_pos);
    badrone_entrypoint_15(player, target_pos, func_800EEFFC(delta) / speed);
}

// Sets the request mode; no return statement, the result of the call is left in v0.
int func_80800348_badrone(void *player, s32 mode)
{
    *(u8 *) (*(s32 *) ((char *) player + 0x54) + 0x1) = mode;
    _badata_entrypoint_21();
}

void badrone_entrypoint_17(s32 player)
{
    *(u8 *) (*(s32 *) (player + 0x54) + 1) = 7;
    _badata_entrypoint_23(player);
}

s32 badrone_entrypoint_18(u8 *player, s32 value)
{
    *(s32 *) (*(u8 **) (player + 0x54) + 0x48) = value;
    return func_80800348_badrone(player, 12);
}

void badrone_entrypoint_19(s32 player)
{
    func_80800348_badrone(player, 0xD);
}

void badrone_entrypoint_20(u8 *player, s32 pos, s32 value)
{
    (*(u8 **) (player + 0x54))[0x30] = value;
    func_800EE7F8(*(u8 **) (player + 0x54) + 0x34, pos);
    func_80800348_badrone(player, 8);
}

void badrone_entrypoint_21(u8 *player)
{
    *(s8 *) ((s8 *) *(u8 **) ((s8 *) player + 0x54) + 1) = 0xF;
    _badata_entrypoint_22();
}

void badrone_entrypoint_22(Actor *player)
{
    func_800EE7F8(*(s32 *) &player->unk54 + 0x34);
    func_80800348_badrone(player, 0xb);
}

void badrone_entrypoint_23(Badrones *player)
{
    func_800EE7F8((void *) ((char *) player->drone + 0x34));
    func_80800348_badrone(player, 0xa);
}

void badrone_entrypoint_24(s32 player)
{
    func_80800348_badrone(player, 0x2);
}

void badrone_entrypoint_25(s32 player)
{
    func_80800348_badrone(player, 0x9);
}

void badrone_entrypoint_26(u8 *player)
{
    *(s8 *) ((s8 *) *(u8 **) ((s8 *) player + 0x54) + 1) = 3;
    _badata_entrypoint_23();
}

void badrone_entrypoint_27(s32 player)
{
    func_80800348_badrone(player, 0x6);
}

void badrone_entrypoint_28(s32 player)
{
    baflag_clear(player, 0x19);
    func_80800348_badrone(player, 0x4);
}

void badrone_entrypoint_29(s32 player)
{
    func_80800348_badrone(player, 0xE);
}

int badrone_entrypoint_30(PlayerState *player)
{
    return badrone_entrypoint_3(player) == 2 && !player_inWater(player);
}

int badrone_entrypoint_31(s32 player)
{
    if ((*(u8 **) (player + 0x54))[0] == 1) {
        return 1;
    }
    return 0;
}

void badrone_entrypoint_32(u8 *player)
{
    u8 *drone;

    *(u8 *) ((s8 *) *(u8 **) ((s8 *) player + 0x54) + 1) = 0U;
    drone = *(u8 **) ((s8 *) player + 0x54);
    *(u8 *) ((s8 *) drone + 0) = (u8) *(u8 *) ((s8 *) drone + 1); // Matching: same-type cast, needed for the match.
}

void badrone_entrypoint_33(void *player)
{
    func_800EE7F8(*(int *) ((char *) player + 0x54) + 0x24);
}

u8 D_80800630_badrone[16] = {0x0, 0x0, 0x1, 0x0, 0x0, 0x0, 0x0, 0x0,
                             0x0, 0x0, 0x0, 0x0, 0x1, 0x0, 0x1, 0x0};
