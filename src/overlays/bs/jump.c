#include "common.h"
#include "overlays/ba/playerstate.h"
#include "core2/anctrl.h"

extern AnimCtrl *baanim_getAnimCtrlPtr();
extern f32 bastick_distance(PlayerState *);
extern f32 bastick_getAngleRelativeToBanjo(PlayerState *);
extern f32 yaw_getIdeal(PlayerState *);
extern f32 baphysics_get_target_horizontal_velocity(PlayerState *);
extern void yaw_setIdeal(PlayerState *, f32);
extern void baphysics_set_target_yaw(PlayerState *, f32);
extern void baphysics_set_horizontal_velocity(PlayerState *, f32, f32);
extern void baphysics_set_vertical_velocity(PlayerState *, f32);
extern void baphysics_set_gravity(PlayerState *, f32);
extern void func_8009DE38(PlayerState *, s32, f32);
extern void baanim_setEndAndDuration(PlayerState *, f32, f32);
extern f32 func_8009C150(PlayerState *);
extern f32 func_800964DC(PlayerState *);
extern s32 D_80801110_bsjump[];
extern f32 baphysics_get_vertical_velocity(PlayerState *);
extern void func_8008B1C8(AnimCtrl *, f32);
extern void func_8009BB24();
extern s32 D_80801120_bsjump[];
extern void baphysics_set_target_horizontal_velocity(PlayerState *, f32);
extern s32 D_80801130_bsjump[];
extern f32 func_8009F308(PlayerState *);
extern void anctrl_setPlaybackType();
extern s32 D_80801140_bsjump[];
extern void baanim_playForDuration_loop(PlayerState *, s32, f32);
extern void func_80093360(PlayerState *, f32);
extern void _batimer_set(PlayerState *, s32, f32);
extern void func_8009DF18(PlayerState *, s32, f32, s32);
extern f32 func_8009BFD8(PlayerState *);
extern void func_8009BF5C(PlayerState *, f32);
extern s32 D_80801150_bsjump[];

void func_80800000_bsjump(int param_0)
{
  unsigned int new_var;
  func_8009D7A4(param_0, 0x3F68F5C3, 0x3F8B851F);
  new_var = 0;
}

void bsjump_entrypoint_0(PlayerState *param_0)
{
    AnimCtrl *local_0;
    s32 local_1;

    local_0 = baanim_getAnimCtrlPtr(param_0);
    param_0->unk164.word = baflag_isTrue(param_0, 2) && !func_8008E23C(param_0);
    local_1 = bs_getPreviousState(param_0);
    if (func_8009CBDC(param_0, local_1) == 0xA) func_80098840(param_0);
    if (local_1 == 0x11) {
        anctrl_setSubrange(local_0, 0.0f, 0.6667f);
        anctrl_setStart(local_0, 0.5042f);
        anctrl_setDuration(local_0, 8.0f);
        anctrl_setPlaybackType(local_0, 1);
        param_0->unk15C.word = 1;
    } else {
        param_0->unk160.word = func_8009CA70(param_0, local_1, 1);
        anctrl_reset(local_0);
        anctrl_setIndex(local_0, 8);
        anctrl_setDuration(local_0, 1.9f);
        func_8008B1C8(local_0, 0.134f);
        anctrl_setStart(local_0, 0.3f);
        anctrl_setSubrange(local_0, 0.0f, 0.5042f);
        anctrl_setPlaybackType(local_0, 1);
        anctrl_start(local_0);
        func_8009FFD8(param_0, 1, 1, 3, 6);
        if (bastick_distance(param_0) != 0.0f) yaw_setIdeal(param_0, bastick_getAngleRelativeToBanjo(param_0));
        baphysics_set_target_yaw(param_0, yaw_getIdeal(param_0));
        _bswalk_entrypoint_1(param_0);
        baphysics_set_horizontal_velocity(param_0, (yaw_getIdeal(param_0)), baphysics_get_target_horizontal_velocity(param_0));
        if (param_0->unk160.word) baphysics_set_vertical_velocity(param_0, 610.0f);
        else baphysics_set_vertical_velocity(param_0, 710.0f);
        baphysics_set_gravity(param_0, -1350.0f);
        param_0->unk15C.word = 0;
        if (param_0->unk164.word) func_8009DE38(param_0, 0x422, 1.0f);
        else func_80800000_bsjump((int)param_0);
    }
}

void bsjump_entrypoint_1(PlayerState *param_0)
{
    s32 local_0 = 0;
    Vec3f local_1;
    f32 local_4;

    if (*(s32 *)((u8 *)param_0 + 0x164)) {
        func_8009FC80();
    }
    if (baflag_isTrue(param_0, 0xF)) {
        func_8009B7C0(param_0);
    } else {
        _bswalk_entrypoint_1(param_0);
    }
    func_8009BB24(param_0, local_1.f);
    if ((bakey_released(param_0, 8) && local_1.pos.y > 0.0f &&
         *(s32 *)((u8 *)param_0 + 0x164) == 0) || !func_8008D544(param_0)) {
        baphysics_reset_gravity(param_0);
    }
    switch (*(s32 *)((u8 *)param_0 + 0x15C)) {
    case 0:
        if (baanim_isStopped(param_0)) {
            baanim_setEndAndDuration(param_0, 0.6667f, 4.0f);
            *(s32 *)((u8 *)param_0 + 0x15C) = 1;
        }
        if (func_8008DF8C(param_0, 0x82)) {
            baanim_setEndAndDuration(param_0, 1.0f, 1.4f);
            *(s32 *)((u8 *)param_0 + 0x15C) = 2;
        }
        break;
    case 1:
        if (baanim_isStopped(param_0)) {
            local_0 = 0x2F;
        }
        if (*(s32 *)((u8 *)param_0 + 0x164)) {
            *(s32 *)((u8 *)param_0 + 0x164) = 0;
            local_0 = 0x21;
        }
        if (func_8008DF8C(param_0, 0x5A)) {
            baanim_setEndAndDuration(param_0, 1.0f, 2.0f);
            *(s32 *)((u8 *)param_0 + 0x15C) = 2;
        }
        break;
    case 2:
        break;
    }
    if (func_8008E260(param_0)) {
        local_0 = 0x3D;
    }
    if (bakey_released(param_0, 8)) {
        *(s32 *)((u8 *)param_0 + 0x164) = 0;
    }
    switch (func_800A3274(param_0)) {
    case 1:
        if (bainput_func_80097DF4(param_0)) {
            local_0 = 0x10;
        }
        if (bainput_func_80097F08(param_0)) {
            local_4 = func_8009C150(param_0) - func_800964DC(param_0);
            if ((*(s32 *)((u8 *)param_0 + 0x160) && ((local_4 > 2.0f) != 0)) ||
                *(s32 *)((u8 *)param_0 + 0x160) == 0) {
                local_0 = 0x11;
            }
        }
        if (bainput_should_beak_bust(param_0)) {
            local_0 = 0xF;
        }
        break;
    case 10:
        if (bainput_func_80097EC8(param_0)) {
            local_0 = 0xE4;
        }
        break;
    }
    if (func_8008DA24(param_0)) {
        local_0 = 0xA8;
    }
    if (player_isStable(param_0)) {
        func_8009FE58(param_0);
        if (baphysics_get_target_horizontal_velocity(param_0) != 0.0f) {
            local_0 = 4;
        } else {
            local_0 = 0x20;
        }
    }
    if (local_1.pos.y < 0.0f && player_inWater(param_0)) {
        local_0 = 0x4C;
    }
    bs_setState(param_0, local_0);
}

int bsjump_entrypoint_2(Actor *param_0)
{
  if (func_800C6E38(0xA))
  {
    func_800C6DA0(0x3C);
  }
  if (bs_getNextState(param_0) != 0x11)
  {
    baphysics_reset_gravity(param_0);
  }
}

int bsjump_entrypoint_3(s32 param_0)
{
  return D_80801110_bsjump[param_0];
}

void bsjump_entrypoint_4(PlayerState *param_0)
{
    AnimCtrl *local_0;

    local_0 = baanim_getAnimCtrlPtr(param_0);
    if (baflag_isTrue(param_0, 7)) {
        if (baphysics_get_vertical_velocity(param_0) > 700.0f) baphysics_set_vertical_velocity(param_0, 700.0f);
    }
    anctrl_reset(local_0);
    anctrl_setIndex(local_0, 0xB0);
    func_8008B1C8(local_0, 0.3f);
    anctrl_setDuration(local_0, 0.38f);
    anctrl_start(local_0);
    func_8009FFD8(param_0, 1, 1, 3, 6);
    param_0->unk15C.word = 0;
}

void bsjump_entrypoint_5(u8 *param_0) {
    s32 local_0;
    s32 local_1;
    s32 local_2;
    s32 local_4;

    local_0 = 0;
    local_1 = baanim_getAnimCtrlPtr();
    if (baflag_isTrue(param_0, 0xF) != 0) {
        func_8009B7C0(param_0);
    } else {
        _bswalk_entrypoint_1(param_0);
    }
    func_8009BB24(param_0, (s32 *)((s8 *)&local_2 - 8));
    switch (*(s32 *)((s8 *)(param_0) + (0x15C))) {                              
    case 1:                                         
        break;
    case 0:                                         
        if (func_8008DF8C(param_0, 0x5A) != 0) {
            anctrl_reset(local_1);
            anctrl_setIndex(local_1, 8);
            anctrl_setStart(local_1, 0.6667f);
            anctrl_setDuration(local_1, 2.0f);
            anctrl_setPlaybackType(local_1, 1);
            anctrl_start(local_1);
            (*(s32 *)((s8 *)(param_0) + (0x15C))) = 1;
        }
        break;
    }
    if (baflag_isFalse(param_0, 0xF) != 0) {
        if (func_8008E260(param_0) != 0) {
            local_0 = 0x3D;
        }
        local_4 = func_800A3274(param_0);
        switch (local_4) {                        
        case 1:                                     
            if ((bainput_func_80097DF4(param_0) != 0) && (baflag_isFalse(param_0, 5) != 0)) {
                local_0 = 0x10;
            }
            if (bainput_func_80097F08(param_0) != 0) {
                local_0 = 0x11;
            }
            if (bainput_should_beak_bust(param_0) != 0) {
                local_0 = 0xF;
            }
            break;
        case 10:                                    
            if (bainput_func_80097EC8(param_0) != 0) {
                local_0 = 0xE4;
            }
            break;
        }
        if (func_8008DA24(param_0) != 0) {
            local_0 = 0xA8;
        }
        if (player_inWater(param_0) != 0) {
            local_0 = 0x4C;
        }
    } else if ((player_inWater(param_0) != 0) && ((func_800A046C(param_0), (baflag_isTrue(param_0, 6) != 0)) || (baflag_isTrue(param_0, 0x14) != 0))) {
        local_0 = 0xD;
    }
    if (player_isStable(param_0) != 0) {
        func_8009FE58(param_0);
        local_0 = 0x20;
    }
    bs_setState(param_0, local_0);
}

void bsjump_entrypoint_6(s32 arg0) 
{
}
int bsjump_entrypoint_7(s32 param_0)
{
  return D_80801120_bsjump[param_0];
}

void bsjump_entrypoint_8(PlayerState *param_0)
{
    AnimCtrl *local_0;
    local_0 = baanim_getAnimCtrlPtr(param_0);
    func_80098840(param_0);
    anctrl_reset(local_0);
    anctrl_setIndex(local_0, 8);
    anctrl_setDuration(local_0, 1.9f);
    func_8008B1C8(local_0, 0.134f);
    anctrl_setStart(local_0, 0.3f);
    anctrl_setSubrange(local_0, 0, 0.5042f);
    anctrl_setPlaybackType(local_0, 1);
    anctrl_start(local_0);
    func_8008CA4C(param_0, 1);
    yaw_setUpdateType(param_0, 1);
    func_8009D2D8(param_0, 3);
    baphysics_set_type(param_0, 3);
    baphysics_set_target_yaw(param_0, yaw_getIdeal(param_0));
    baphysics_set_target_horizontal_velocity(param_0, 120.0f);

    baphysics_set_horizontal_velocity(param_0, yaw_getIdeal(param_0), baphysics_get_target_horizontal_velocity(param_0));
    baphysics_set_vertical_velocity(param_0, 710.0f);
    baphysics_set_gravity(param_0, -1350.0f);
    func_800961AC(param_0, 6);
    param_0->unk15C.word = 0;
    func_80800000_bsjump(param_0);
}

void bsjump_entrypoint_9(Actor *param_0) {
    s32 local_2;
    void *local_0;
    f32 local_1[3];

    local_2 = 0;
    local_0 = baanim_getAnimCtrlPtr();
    func_8009BB24(param_0, local_1);
    if (local_1[1] < 0.0f) {
        func_800961AC(param_0, 1);
    }
    switch (*(s32 *)((char *)param_0 + 0x15C)) {
    case 2:
        break;
    case 0:
        if (anctrl_isStopped(local_0) != 0) {
            anctrl_setSubrange(local_0, 0.0f, 0.6667f);
            anctrl_setDuration(local_0, 4.0f);
            anctrl_setPlaybackType(local_0, 1);
            *(s32 *)((char *)param_0 + 0x15C) = 1;
        }
        if (func_8008DF8C(param_0, 0x82) != 0) {
            anctrl_setSubrange(local_0, 0.0f, 1.0f);
            anctrl_setDuration(local_0, 1.4f);
            anctrl_setPlaybackType(local_0, 1);
            *(s32 *)((char *)param_0 + 0x15C) = 2;
        }
        break;
    case 1:
        if (func_8008DF8C(param_0, 0x5A) != 0) {
            anctrl_setSubrange(local_0, 0.0f, 1.0f);
            anctrl_setDuration(local_0, 2.0f);
            anctrl_setPlaybackType(local_0, 1);
            *(s32 *)((char *)param_0 + 0x15C) = 2;
        }
        break;
    }
    if (func_8008DA24(param_0) != 0) {
        local_2 = 0xA8;
    }
    if (player_isStable(param_0) != 0) {
        func_8009FE58(param_0);
        local_2 = 0x20;
    }
    bs_setState(param_0, local_2);
}

void bsjump_entrypoint_10(s32 arg0)
{
    func_800961AC(arg0,0x1);
    baphysics_reset_gravity(arg0);
}

int bsjump_entrypoint_11(s32 param_0)
{
  return D_80801130_bsjump[param_0];
}

void bsjump_entrypoint_12(PlayerState *param_0)
{
    AnimCtrl *local_0;
    s32 local_1;
    local_0 = baanim_getAnimCtrlPtr(param_0);
    local_1 = 1;
    if (bs_getPreviousState(param_0) == 0x12) local_1 = 0;
    anctrl_reset(local_0);
    anctrl_setSmoothTransition(local_0, local_1);
    anctrl_setIndex(local_0, 8);
    func_8008B1C8(local_0, 0.3f);
    anctrl_setDuration(local_0, 1.9f);
    anctrl_setStart(local_0, 0.6667f);
    anctrl_setPlaybackType(local_0, 3);
    anctrl_start(local_0);
    yaw_setIdeal(param_0, func_8009F308(param_0));
    func_8008CA4C(param_0, 1);
    yaw_setUpdateType(param_0, 1);
    func_8009D2D8(param_0, 3);
    baphysics_set_type(param_0, 6);
    baphysics_set_target_horizontal_velocity(param_0, 0.0f);
    func_8009BA9C(param_0, 0);
    param_0->unk15C.word = 0;
    func_8008E944(param_0);
}

void bsjump_entrypoint_13(PlayerState *param_0)
{
    s32 local_0;
    AnimCtrl *local_1;
    f32 local_2[3];
    local_0 = 0;
    local_1 = baanim_getAnimCtrlPtr(param_0);
    func_8009BB24(param_0, local_2);
    switch (param_0->unk15C.word) {
    case 0:
        if (func_8008DF8C(param_0, 0x5A)) {
            anctrl_setSubrange(local_1, 0.0f, 1.0f);
            anctrl_setDuration(local_1, 2.0f);
            anctrl_setPlaybackType(local_1, 1);
            param_0->unk15C.word = 1;
        }
        break;
    case 1:
        break;
    }
    if (player_isStable(param_0)) local_0 = 1;
    bs_setState(param_0, local_0);
}

void bsjump_entrypoint_14()
{
    func_8008E95C();
}

int bsjump_entrypoint_15(s32 param_0)
{
  return D_80801140_bsjump[param_0];
}

s32 bsjump_entrypoint_16(s32 param_0) {
    return *(s32 *)(param_0 + 0x160);
}

void bsjump_entrypoint_17(PlayerState *param_0)
{
    baanim_playForDuration_loop(param_0, 0x68, 0.35f);
    func_8009FFD8(param_0, 1, 1, 3, 6);
    func_80093360(param_0, 60.0f);
    if (func_8009557C(param_0) == 1) {
        _batimer_set(param_0, 0, 0.5f);
        _batimer_set(param_0, 1, 0.41f);
        func_8009DF18(param_0, 0x439, 1.0f, 0x55F0);
    } else {
        _batimer_set(param_0, 0, 0.0f);
        _batimer_set(param_0, 1, 0.01f);
    }
    param_0->unk15C.word = 0;
}

void bsjump_entrypoint_18(PlayerState *param_0)
{
    s32 local_0 = 0;
    if (_batimer_decrement(param_0, 1)) func_8009DF18(param_0, 0x446, 1.0f, 32000);
    _batimer_decrement(param_0, 0);
    _bswalk_entrypoint_1(param_0);
    if (_batimer_isZero(param_0, 1)) func_8009BF5C(param_0, func_8009BFD8(param_0) + 20.0f);
    if (_batimer_isNonzero(param_0, 0)) {
        switch (func_800A3274(param_0)) {
        case 1:
            if (bainput_func_80097DF4(param_0)) local_0 = 0x10;
            if (bainput_func_80097F08(param_0)) local_0 = 0x11;
            if (bainput_should_beak_bust(param_0)) local_0 = 15;
            break;
        case 10:
            if (bainput_func_80097EC8(param_0)) local_0 = 0xE4;
            break;
        }
    }
    if (player_inWater(param_0)) local_0 = 0x4C;
    if (player_isStable(param_0)) local_0 = 0x72;
    bs_setState(param_0, local_0);
}

void bsjump_entrypoint_19(PlayerState *param_0)
{
    switch (bs_getNextState(param_0)) {
    case 0xF:
    case 0x10:
    case 0x11:
        func_80095588(param_0, 3);
        break;
    }
    func_800A042C(param_0);
    func_80093360(param_0, 0.0f);
    func_8009E0DC(param_0);
}

int bsjump_entrypoint_20(s32 param_0)
{
  return D_80801150_bsjump[param_0];
}
