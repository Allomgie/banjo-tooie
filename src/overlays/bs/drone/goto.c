// Drone mode "goto": the game walks the player to a target position; waits for landing, moves
// with a fixed duration or speed, then calls the request's callback on arrival.
#include "common.h"
#include "overlays/ba/playerstate.h"

extern void baanim_playForDuration_loopSmooth(PlayerState *, s32, f32);
extern void _bamovegoto_entrypoint_7(PlayerState *, f32);
extern void _bamovegoto_entrypoint_8(PlayerState *, f32);
typedef struct {
    u8 pad_0[0x194];
    s32 arrived;
} DroneArrivalState;
void func_80800148_bsdronegoto();

void func_808000C0_bsdronegoto();

extern s32 func_800F1EA4(f32 *, f32 *);
extern void yaw_setIdeal(PlayerState *, f32);
extern void func_80091E6C();
void func_80800150_bsdronegoto();
void func_8080032C_bsdronegoto();

// Switch mode: 1 = wait until landed, 2 = move to target.
// Player state: +0x190 mode, +0x194 arrived flag, +0x198 saved flag.
void func_80800000_bsdronegoto(Actor *player, s32 new_mode)
{
    s32 old_mode;

    old_mode = *(s32 *) ((char *) player + 0x190);
    switch (old_mode) {
        case 1:
            func_80800148_bsdronegoto(player);
            break;
        case 2:
            func_8080032C_bsdronegoto(player);
    }
    *(s32 *) ((char *) player + 0x190) = new_mode;
    switch (new_mode) {
        case 1:
            func_808000C0_bsdronegoto(player, new_mode);
            return;
        case 2:
            func_80800150_bsdronegoto(player, new_mode);
    }
}

int func_8080009C_bsdronegoto()
{
    s32 transformation;
    transformation = func_800A3274();
    return transformation != 0x12;
}

void func_808000C0_bsdronegoto()
{
    func_8009B7C0();
}

void func_808000E0_bsdronegoto(player) s32 player;
{
    s32 in_water;
    func_8009B7C0();
    in_water = func_8080009C_bsdronegoto(player) != 0;
    if (in_water != 0) {
        in_water = player_inWater(player) != 0;
    }
    // Matching: multiplying by 0 is needed for the match.
    if ((in_water != (player * 0)) || (player_isStable(player) != 0)) {
        func_80800000_bsdronegoto(player, 2);
    }
}

void func_80800148_bsdronegoto(s32 arg0)
{
}

// Start the move: fixed duration if given, otherwise speed.
void func_80800150_bsdronegoto(player) PlayerState *player;
{
    f32 move_time;
    f32 move_speed;
    f32 target_pos[3];
    s32 anim_id;
    _badata_entrypoint_1(player, &anim_id, &move_time);
    baanim_playForDuration_loopSmooth(player, anim_id, move_time);
    _badrone_entrypoint_8(player, target_pos, &move_time, &move_speed);
    _bamovegoto_entrypoint_0(player);
    _bamovegoto_entrypoint_12(player, target_pos);
    if (move_time != 0.0f) {
        _bamovegoto_entrypoint_9(player, 1);
        _bamovegoto_entrypoint_7(player, move_time);
    } else {
        _bamovegoto_entrypoint_9(player, 2);
        _bamovegoto_entrypoint_8(player, move_speed);
    }
    func_8009FFD8(player, 1, 1, 3, 0);
    *(s32 *) ((u8 *) player + 0x198) = func_80095898(player);
    if (_badrone_entrypoint_7(player)) {
        func_800961A0(player, 0);
        _bamovegoto_entrypoint_10(player, 1);
    } else
        func_800961A0(player, 1);
    _bamovegoto_entrypoint_13(player);
}

void func_8080026C_bsdronegoto(player) PlayerState *player;
{
    f32 target_yaw;
    f32 target_pos[3];
    s32 was_arrived;
    s32 next_state;

    func_8009BB24(player, target_pos);
    if (func_800F1EA4(target_pos, &target_yaw))
        yaw_setIdeal(player, target_yaw);
    func_8009FF00(player);
    if (_bamovegoto_entrypoint_4(player)) {
        was_arrived = ((DroneArrivalState *) player)->arrived;
        if (!was_arrived) {
            ((DroneArrivalState *) player)->arrived = was_arrived + 1;
            if (_badrone_entrypoint_9(player) == 1) {
                if (func_8008E124(player))
                    next_state = _badata_entrypoint_32(player);
                else
                    next_state = _badata_entrypoint_34(player);
                bs_setState(player, next_state);
            }
            _badrone_entrypoint_6(player);
        }
    }
}

void func_8080032C_bsdronegoto(player) long player;
{
    func_800961A0(player, *(long *) (player + 0x198));
}

void bsdronegoto_entrypoint_0(u8 *player)
{
    *(s32 *) ((s8 *) player + 0x190) = 0;
    *(s32 *) ((s8 *) player + 0x194) = 0;
    _gcgoto_entrypoint_14(1);
    func_80091E48(player, 0x3F);
    if ((player_isStable(player) == 0) && (_badata_entrypoint_14(player) != 0)) {
        func_80800000_bsdronegoto(player, 1);
        return;
    }
    func_80800000_bsdronegoto(player, 2);
}

void bsdronegoto_entrypoint_1(void *player)
{
    switch (*(int *) ((char *) player + 0x190)) {
        case 1:
            func_808000E0_bsdronegoto();
            break;

        case 2:
            func_8080026C_bsdronegoto();
    }
}

s32 bsdronegoto_entrypoint_2(s32 player)
{
    func_80800000_bsdronegoto(player, 0);
    func_80091E6C(player);
    _gcgoto_entrypoint_14(0);
}

void bsdronegoto_entrypoint_3(u8 *player)
{
    s32 interrupt;

    if (*(s32 *) ((s8 *) player + 0x194) != 0) {
        func_80099B94();
        return;
    }
    interrupt = func_8009E6EC();
    switch (interrupt) {
        // Matching: the empty statements after some case labels are needed for the match.
        case 0x56:;
        case 0x5D:
        case 0x61:;
        case 0x62:
        case 0x63:;
        case 0x95:
        case 0x96:
            func_80099B94(player);
            return;
        case 0x8F:
            _bamovegoto_entrypoint_1(player);
            func_8009E830(player, 2);
            return;
        default:
            func_80099AA8(player);
    }
}
