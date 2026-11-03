#include "common.h"
#include "overlays/ba/playerstate.h"

extern f32 func_8009BFCC(PlayerState *);
extern f32 yaw_get(PlayerState *);
extern void func_800EEC30(f32 *, f32, f32, f32);
extern void func_800EFA98(f32 *, f32 *, f32);
extern void func_800EF04C(f32 *, f32 *);
extern s32 D_80800450_bsbkflamethrower[];
extern u8 _bsbkflamethrower_entrypoint_0[];
extern void *baanim_getAnimCtrlPtr();
extern void anctrl_setPlaybackType(void *ctrl, int type);
extern void anctrl_setSubrange(void *ctrl, float start, float end);
extern void baanim_playForDuration_onceSmooth(void *ctrl, int animId, float duration);
extern void baanim_setEnd(void *ctrl, float value);
extern void _baflamethrower_entrypoint_1(void *param_0);
extern void _baflamethrower_entrypoint_2(void *param_0, void *callback);
extern void _baflamethrower_entrypoint_3(void *param_0);
extern void _baflamethrower_entrypoint_4(void *param_0);
extern void _batimer_set(void *param_0, int timerId, float value);
extern void baphysics_set_target_horizontal_velocity(void *param_0, float value);
extern void yaw_setVelocityBounded(void *param_0, float vel, float bound);
extern int func_8009D874(void *param_0);
extern int func_800C6E38(int param_0);
extern void func_8009FFD8(void *param_0, int param_1, int param_2, int param_3, int param_4);
extern void func_800A0CF4(void *param_0, int param_1);
extern void bs_setState(Actor *param_0, s32 param_1);
extern void _baflamethrower_entrypoint_5(Actor *param_0);
extern f32 _batimer_get(Actor *param_0, s32 param_1);
extern s32 _batimer_decrement(Actor *param_0, s32 param_1);
extern s32 _batimer_isZero(Actor *param_0, s32 param_1);
extern s32 bakey_pressed(Actor *param_0, s32 param_1);
extern s32 bakey_released(Actor *param_0, s32 param_1);
extern s32 baanim_isAt(Actor *param_0, s32 param_1);
extern s32 baanim_isStopped(Actor *param_0);
extern f32 baanim_getTimer(Actor *param_0);
extern void func_8009DF18(Actor *param_0, s32 param_1, f32 param_2, s32 param_3);
extern s32 _bsstand_entrypoint_8(Actor *param_0, s32 param_1);

// Flame origin (40 units forward along pitch/yaw, 94 up) and direction.
void bsbkflamethrower_entrypoint_0(PlayerState *player, f32 *origin, f32 *direction)
{
    f32 offset[3];
    func_800EEC30(direction, -func_8009BFCC(player), yaw_get(player), 1.0f);
    func_8009C128(player, origin);
    func_800EFA98(offset, direction, 40.0f);
    func_800EF04C(origin, offset);
    origin[1] += 94.0f;
}

// Substates: 1 wind-up, 2 loop, 3 and 4 wind-down.
void func_80800094_bsbkflamethrower(player, substate) Actor *player;
s32 substate;
{
    void *anctrl;
    f32 chain_time;

    anctrl = baanim_getAnimCtrlPtr();
    *(s32 *) ((char *) player + 0x15c) = substate;
    switch (substate) {
        case 1:
            baanim_playForDuration_onceSmooth(player, 0xE0, 1.0f);
            func_8009FFD8(player, 1, 3, 8, 2);
            yaw_setVelocityBounded(player, 300.0f, 1.600000023841858f);
            baphysics_set_target_horizontal_velocity(player, 0.0f);
            func_800A0CF4(player, 1);
            func_8009D874(player);
            if (func_800C6E38(0x32) != 0) {
                chain_time = 0.24f;
            } else {
                chain_time = 0.0f;
            }
            _batimer_set(player, 0, chain_time);
            _baflamethrower_entrypoint_2(player, &_bsbkflamethrower_entrypoint_0);
            return;
        case 2:
            anctrl_setSubrange(anctrl, 0.4f, 0.6f);
            anctrl_setPlaybackType(anctrl, 4);
            _batimer_set(player, 2, 0.14f);
            _baflamethrower_entrypoint_3(player);
            return;
        case 3:
            _baflamethrower_entrypoint_4(player);
            _batimer_set(player, 1, 0.05f);
            return;
        case 4:
            anctrl_setPlaybackType(anctrl, 1);
            baanim_setEnd(player, 1.0f);
            return;
        case 0:
            _baflamethrower_entrypoint_1(player);
            func_800A0CF4(player, 0);
    }
}

void bsbkflamethrower_entrypoint_1(s32 player)
{
    func_80800094_bsbkflamethrower(player, 0);
}

void bsbkflamethrower_entrypoint_2(u8 *player)
{
    *(s32 *) ((u8 *) player + 0x15C) = 0;
    func_80800094_bsbkflamethrower(player, 1);
}

void bsbkflamethrower_entrypoint_3(Actor *player)
{
    s32 next_state;
    s32 substate;

    next_state = 0;
    // Pressing B again within the timer window chains into state 0x189.
    if ((_batimer_get(player, 0) != 0.0f) && (bakey_pressed(player, 9) != 0)) {
        next_state = 0x189;
    }
    _batimer_decrement(player, 0);
    substate = *(s32 *) ((s8 *) player + 0x15C);
    switch (substate) {
        case 1:
            if (baanim_isAt(player, 0x3E6147AE) != 0) {
                func_8009DF18(player, 0x459F, 1.0f, 0x6590);
            }
            if (baanim_isAt(player, 0x3ECCCCCD) != 0) {
                func_80800094_bsbkflamethrower(player, 2);
            }
            break;
        case 2:
            _batimer_decrement(player, 2);
            if ((_batimer_isZero(player, 2) != 0) && (bakey_released(player, 9) != 0)) {
                func_80800094_bsbkflamethrower(player, 3);
            }
            break;
        case 3:
            if (_batimer_decrement(player, 1) != 0) {
                func_80800094_bsbkflamethrower(player, 4);
            }
            break;
        case 4:
            if (baanim_isStopped(player) != 0) {
                next_state = 1;
            }
            if (baanim_getTimer(player) > 0.7f) {
                next_state = _bsstand_entrypoint_8(player, next_state);
            }
    }
    _baflamethrower_entrypoint_5(player);
    bs_setState(player, next_state);
}

int bsbkflamethrower_entrypoint_4(s32 type)
{
    return D_80800450_bsbkflamethrower[type];
}

// TU-NOTE: The overlay's .data (formerly asm/data/overlays/bs/bkflamethrower.data.s) is defined here in C.
// Its tables point to functions of this file; IDO's assembler schedules some of them differently
// unless the tables are in the same unit. Values are taken from the ROM.
extern void _bsbkflamethrower_entrypoint_1();
extern void _bsbkflamethrower_entrypoint_2();
extern void _bsbkflamethrower_entrypoint_3();
extern void func_80099B94();
s32 D_80800450_bsbkflamethrower[4] = {(u32) _bsbkflamethrower_entrypoint_1,
                                      (u32) _bsbkflamethrower_entrypoint_2,
                                      (u32) _bsbkflamethrower_entrypoint_3, (u32) func_80099B94};
