#include "common.h"
#include "overlays/ba/playerstate.h"

typedef struct {
    u8 pad_0[0x190];
    f32 anim_start;
    f32 anim_end;
} DroneJumpPlayer;
extern f32 func_800F10B4(f32, f32, f32, f32, f32);
extern void func_8008C990(PlayerState *, f32);
extern f32 _bamovegoto_entrypoint_3(PlayerState *);
extern f32 func_80013970(f32);
extern void _bsdronejump_entrypoint_0();
extern void _badata_entrypoint_8(PlayerState *, s32 *, f32 *, f32 *);
extern void baanim_playForDuration_loopStartingAt(PlayerState *, s32, f32, f32);
extern f32 func_800EEAD4(f32 *, f32 *);
extern f32 func_800F1DF4(f32 *, f32 *);
extern void yaw_setIdeal(PlayerState *, f32);
extern void _bamovegoto_entrypoint_7(PlayerState *, f32);

// Height callback: adds a sine arc to the path position.
void bsdronejump_entrypoint_0(PlayerState *player, f32 *pos, f32 progress)
{
    f32 anim_pos;
    f32 height;
    anim_pos = func_800F10B4(progress, 0.0f, 1.0f, ((DroneJumpPlayer *) player)->anim_start,
                            ((DroneJumpPlayer *) player)->anim_end);
    func_8008C990(player, anim_pos);
    height = _bamovegoto_entrypoint_3(player);
    pos[1] += func_80013970(progress * 180.0f) * height * 0.5f;
}

void bsdronejump_entrypoint_1(s32 player)
{
    func_800961A0(player, 0);
}

void bsdronejump_entrypoint_2(PlayerState *player)
{
    f32 distance;
    f32 target_yaw;
    f32 player_pos[3];
    s32 anim_id;
    _badata_entrypoint_8(player, &anim_id, (f32 *) ((u8 *) player + 0x190),
                         (f32 *) ((u8 *) player + 0x194));
    baanim_playForDuration_loopStartingAt(player, anim_id, 1000.0f,
                                          *(f32 *) ((u8 *) player + 0x190));
    func_8009FFD8(player, 1, 1, 3, 2);
    func_8009C128(player, player_pos);
    distance = func_800EEAD4(player_pos, (f32 *) (*(u8 **) ((u8 *) player + 0x54) + 0x34));
    target_yaw = func_800F1DF4(player_pos, (f32 *) (*(u8 **) ((u8 *) player + 0x54) + 0x34));
    yaw_setIdeal(player, target_yaw);
    _bamovegoto_entrypoint_0(player);
    _bamovegoto_entrypoint_7(player, func_800F10B4(distance, 100.0f, 5000.0f, 0.4f, 4.5f));
    _bamovegoto_entrypoint_12(player, *(u8 **) ((u8 *) player + 0x54) + 0x34);
    _bamovegoto_entrypoint_11(player, 0, _bsdronejump_entrypoint_0);
    _bamovegoto_entrypoint_13(player);
    func_800961A0(player, 1);
}

void bsdronejump_entrypoint_3()
{
    func_80099AA8();
}

int bsdronejump_entrypoint_4(Actor *player)
{
    int next_state;
    next_state = 0;
    if (_bamovegoto_entrypoint_4(player)) {
        next_state |= _badata_entrypoint_34(player);
    }
    bs_setState(player, next_state);
}
