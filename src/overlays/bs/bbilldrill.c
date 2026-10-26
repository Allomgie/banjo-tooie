#include "common.h"
#include "overlays/ba/playerstate.h"
#include "core2/anctrl.h"
#include "overlays/ba/anim.h"

struct UnkStruct { char pad[0x168]; s32 unk168; };
extern u32 D_80800AB0_bsbbilldrill[][3];
extern void func_800C8E54(s32, f32, f32);
extern f32 func_80092BF4(s32);
extern int D_80800AC8_bsbbilldrill;
extern f32 func_800D8FF8(void);
extern void func_80093300(PlayerState *, f32);
extern void func_80098520(PlayerState *, f32);
extern void baphysics_set_gravity(PlayerState *, f32);
extern void baphysics_set_target_horizontal_velocity(PlayerState *, f32);
extern s32 D_80800B68_bsbbilldrill[];
extern f32 func_800DC0C0(void);
extern void func_800BA7C4(s32, f32, f32);
extern void func_800BA7FC(s32, f32, f32);
extern f32 baphysics_get_target_horizontal_velocity(PlayerState *);
extern u8 D_80800B30_bsbbilldrill[];
extern u8 D_80800B10_bsbbilldrill[];
extern u8 D_80800B50_bsbbilldrill[];
extern f32 yaw_get(PlayerState *);
extern s32 _batimer_set(PlayerState *, s32, f32);
extern s32 func_8009DF18(PlayerState *, s32, f32, s32);
extern s32 baphysics_set_terminal_velocity(PlayerState *, f32);
extern s32 baphysics_set_vertical_velocity(PlayerState *, f32);
extern s32 func_8009E53C(PlayerState *, s32, f32);
extern f32 func_800962D4(PlayerState *);
extern s32 func_800EFA4C(f32 *, f32, f32, f32);
extern s32 _badust_entrypoint_10(PlayerState *, f32);
extern s32 _bamotor_entrypoint_3(PlayerState *, f32, f32, f32, f32, f32, f32);
extern s32 func_8009DE38(PlayerState *, s32, f32);
extern s32 func_8009328C(PlayerState *, f32);
extern void baanim_setEndAndDuration(PlayerState *, f32, f32);
extern f32 _batimer_get(PlayerState *, s32);
extern f32 func_800F10B4(f32, f32, f32, f32, f32);
extern f32 mlAbsF(f32);
extern f32 baphysics_get_vertical_velocity(PlayerState *);
void func_808002DC_bsbbilldrill();

void func_80800000_bsbbilldrill(void* param_0)
{
    ((struct UnkStruct*)param_0)->unk168 = 0;
}

void func_80800008_bsbbilldrill(PlayerState *param_0)
{
    f32 local_0[3];

    if (func_800BF8E4() > 0) {
        if (*(s32 *)((u8 *)param_0 + 0x168) == 0) {
            *(s32 *)((u8 *)param_0 + 0x168) = func_800C8A98();
            func_800C8E54(*(s32 *)((u8 *)param_0 + 0x168), 80.0f, 350.0f);
            func_800C8F64(*(s32 *)((u8 *)param_0 + 0x168), 0xB);
        }
        func_8009C128(param_0, local_0);
        local_0[1] -= 10.0f;
        func_800C8CB8(*(s32 *)((u8 *)param_0 + 0x168), local_0);
        func_800C8E84(*(s32 *)((u8 *)param_0 + 0x168), D_80800AB0_bsbbilldrill[func_8001210C(1)]);
    }
}

void func_808000C0_bsbbilldrill(u8 *param_0)
{
  s32 temp_a3;
  temp_a3 = *((s32 *) (((u8 *) param_0) + 0x168));
  if (temp_a3 != 0)
  {
    *((s32 *) (((u8 *) param_0) + 0x168)) = _chlightfader_entrypoint_1(temp_a3, 0x3F19999A, 2);
  }
}

void func_80800100_bsbbilldrill(s32 param_0) {
    f32 local_0 = func_80092BF4(param_0);
    if (local_0 == 0.0f) {
        local_0 = 8.0f;
    }
    local_0 = -local_0;
    func_80093300(param_0, local_0);
}

int func_80800158_bsbbilldrill(s32 param_0)
{
  func_800BABB8(func_800B5BE4(9), param_0, 0, 0x3F800000, &D_80800AC8_bsbbilldrill);
}

void func_8080019C_bsbbilldrill(void *param_0)
{
    f32 local_0[3];
    f32 local_1;
    s32 local_2;

    local_1 = func_800DC0C0() <= 0.2f ? 0.15f : 0.09f;
    func_8009C128(param_0, local_0);
    local_0[1] -= 80.0f;
    local_2 = func_80800158_bsbbilldrill(local_0);
    func_800BA7C4(local_2, local_1, local_1);
    func_800BA7FC(local_2, local_1, local_1);
    func_800BA22C(local_2, 2);
}

void func_80800250_bsbbilldrill(s32 param_0) {
    f32 local_0[3];
    func_8009C128(param_0, local_0);
    local_0[1] -= 80.0f;
    func_800BA22C(_fxdlsmoke_entrypoint_0(local_0), 1);
}

void func_80800298_bsbbilldrill(PlayerState *param_0)
{
    _bswalk_entrypoint_1(param_0);
    baphysics_set_target_horizontal_velocity(param_0,
        baphysics_get_target_horizontal_velocity(param_0) * 0.1f);
}

void func_808002DC_bsbbilldrill(param_0, param_1) PlayerState *param_0; u32 param_1;
{
    f32 local_0[3];
    if (1) {}

    param_0->unk15C.bytes[0] = param_1;
    switch (param_1) {
    case 1:
        *(f32 *)((u8 *)param_0 + 0x16C) = yaw_get(param_0);
        *(f32 *)((u8 *)param_0 + 0x170) = 0.0f;
        func_80098520(param_0, 0.0f);
        _batimer_set(param_0, 0, 0.3f);
        if (func_8009EA2C()) {
            param_0->unk164.bytes[0] = func_8009D454(param_0, 0, D_80800B30_bsbbilldrill);
        } else {
            param_0->unk164.bytes[0] = func_8009D454(param_0, 0, D_80800B10_bsbbilldrill);
        }
        param_0->unk15C.bytes[1] = 0;
        break;
    case 2:
        *(f32 *)((u8 *)param_0 + 0x170) = 1500.0f;
        func_80098520(param_0, 1.0f);
        _batimer_set(param_0, 0, 0.15f);
        break;
    case 3:
        func_8009DF18(param_0, 0x442F, 1.2f, 30000);
        baphysics_set_terminal_velocity(param_0, -5000.0f);
        baphysics_set_gravity(param_0, -20000.0f);
        baphysics_set_vertical_velocity(param_0, 2300.0f);
        baphysics_set_target_horizontal_velocity(param_0, 0.0f);
        func_8009E53C(param_0, 1, -100.0f);
        break;
    case 4:
        func_800EFA4C(local_0, 0.0f, 80.0f - func_800962D4(param_0), 0.0f);
        func_8009C1F8(param_0, local_0);
        _badust_entrypoint_10(param_0, -func_800962D4(param_0));
        baflag_set(param_0, 0x26);
        baphysics_set_gravity(param_0, 0.0f);
        func_8009BA9C(param_0, 0);
        _batimer_set(param_0, 0, 0.8f);
        _bamotor_entrypoint_3(param_0, 1.0f, 0.7f, 0.01f, 0.1f, 0.7, 0.4f);
        _bashake_entrypoint_1(param_0, 3, 2);
        param_0->unk160.bytes[0] = func_8009D454(param_0, 0, D_80800B50_bsbbilldrill);
        func_8009DE38(param_0, 0x40D, 1.0f);
        break;
    case 5:
        func_8009E53C(param_0, 1, 0.0f);
        baflag_clear(param_0, 0x22);
        func_8009328C(param_0, yaw_get(param_0));
        baphysics_set_vertical_velocity(param_0, 730.0f);
        baphysics_set_gravity(param_0, -2400.0f);
        baanim_setEndAndDuration(param_0, 0.7299000025f, 2.1f);
        func_808000C0_bsbbilldrill(param_0);
        break;
    }
}

void func_808005C0_bsbbilldrill(u8 *param_0) {
    f32 local_0 = func_800D8FF8();
    *(f32 *)(param_0 + 0x16C) += *(f32 *)(param_0 + 0x170) * local_0;
    func_8009328C(param_0, *(f32 *)(param_0 + 0x16C));
}

void bsbbilldrill_entrypoint_0(PlayerState *param_0)
{
    func_800931AC(param_0, 1);
    func_80093300(param_0, 0.0f);
    func_80098520(param_0, 1.0f);
    baphysics_reset_gravity(param_0);
    baphysics_reset_terminal_velocity(param_0);
    func_800A0CF4(param_0, 0);
    baflag_clear(param_0, 0x22);
    baflag_clear(param_0, 0x26);
    func_8009E474(param_0);
    func_808000C0_bsbbilldrill(param_0);
}

void bsbbilldrill_entrypoint_1(PlayerState *param_0)
{
    AnimCtrl *local_0;
    local_0 = baanim_getAnimCtrlPtr(param_0);
    anctrl_reset(local_0);
    anctrl_setSmoothTransition(local_0, 0);
    anctrl_setIndex(local_0, 0x61);
    anctrl_setDuration(local_0, 1.02f);
    anctrl_setStart(local_0, 0.3637f);
    anctrl_setSubrange(local_0, 0, 0.4546f);
    anctrl_setPlaybackType(local_0, 1);
    anctrl_start(local_0);
    func_8009FFD8(param_0, 1, 1, 3, 6);
    baphysics_set_gravity(param_0, 0);
    baphysics_set_target_horizontal_velocity(param_0, 0);
    func_800A0CF4(param_0, 1);
    baflag_clear(param_0, 0x22);
    baflag_clear(param_0, 0x26);
    func_800931AC(param_0, 3);
    func_8009E4AC(param_0);
    param_0->unk164.bytes[0] = 0;
    param_0->unk160.bytes[0] = 0;
    param_0->unk15C.bytes[0] = 0;
    func_808002DC_bsbbilldrill(param_0, 1);
    func_80800000_bsbbilldrill(param_0);
}

void bsbbilldrill_entrypoint_2(PlayerState *param_0)
{
    s32 local_0 = 0;
    f32 local_1;
    f32 local_2[3];
    s32 local_3;

    switch (*((u8 *)param_0 + 0x15C)) {
    case 1:
        func_80800298_bsbbilldrill(param_0);
        local_1 = _batimer_get(param_0, 0);
        *(f32 *)((u8 *)param_0 + 0x170) = func_800F10B4(local_1, 0.0f, 0.3f, 1500.0f, 50.0f);
        func_808005C0_bsbbilldrill(param_0);
        func_80098520(param_0, func_800F10B4(local_1, 0.0f, 0.3f, 1.0f, 0.0f));
        if (_batimer_decrement(param_0, 0)) {
            func_808002DC_bsbbilldrill(param_0, 2);
        }
        break;
    case 2:
        func_80800298_bsbbilldrill(param_0);
        func_808005C0_bsbbilldrill(param_0);
        if (_batimer_decrement(param_0, 0)) {
            func_808002DC_bsbbilldrill(param_0, 3);
        }
        break;
    case 3:
        func_80096394(param_0, local_2);
        if (mlAbsF(local_2[1]) < 1.0f) {
            *((u8 *)param_0 + 0x15D) += 1;
        } else {
            *((u8 *)param_0 + 0x15D) = 0;
        }
        func_808005C0_bsbbilldrill(param_0);
        if (baphysics_get_vertical_velocity(param_0) < 0.0f) {
            baflag_set(param_0, 0x22);
        }
        if (player_inWater(param_0)) {
            local_0 = 0x4C;
        } else if (func_8008DF8C(param_0, 0x50) || *((u8 *)param_0 + 0x15D) >= 4) {
            if (func_800954E8(param_0, &local_3)) {
                local_0 = 0x72;
            } else {
                func_808002DC_bsbbilldrill(param_0, 4);
            }
        }
        break;
    case 4:
        baflag_clear(param_0, 0x26);
        func_808005C0_bsbbilldrill(param_0);
        func_80800250_bsbbilldrill(param_0);
        func_80800100_bsbbilldrill(param_0);
        func_8080019C_bsbbilldrill(param_0);
        func_80800008_bsbbilldrill(param_0);
        if (_batimer_decrement(param_0, 0)) {
            func_808002DC_bsbbilldrill(param_0, 5);
        }
        break;
    case 5:
        _bswalk_entrypoint_1(param_0);
        if (player_inWater(param_0)) {
            local_0 = 0x4C;
        }
        if (player_isStable(param_0)) {
            baanim_setEndAndDuration(param_0, 1.0f, 1.9f);
            local_0 = 0x20;
        }
        break;
    }
    bs_setState(param_0, local_0);
}

int bsbbilldrill_entrypoint_3(s32 param_0)
{
  return D_80800B68_bsbbilldrill[param_0];
}
