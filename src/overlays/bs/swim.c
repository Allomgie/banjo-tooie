#include "common.h"
#include "overlays/ba/playerstate.h"

extern s32 func_80096544(PlayerState *);
extern f32 func_800DC0C0(void);
extern void func_80092C00(PlayerState *, f32[3]);
extern void func_80092C24(PlayerState *, f32[3]);
extern s32 func_8009FBB0(PlayerState *, f32[3], f32);
extern void func_800BA930(s32, s32, s32, s32, s32, s32, s32);
extern void func_800BA22C(s32, s32);
extern s16 D_80800B90_bsswim[10];
extern f32 anctrl_getAnimTimer(void *);
extern void anctrl_setStart(void *, f32);
extern f32 bastick_getZonePosition(PlayerState *);
extern s32 bastick_getZone(PlayerState *);
extern void baphysics_set_target_horizontal_velocity(PlayerState *, f32);
extern f32 func_800F1214(f32, f32, f32);
extern int func_8001210C(int);
extern int func_8009FC34(Actor *, int);
extern void func_8009DEC0(Actor *, int, float, float, int, int);
extern int player_inWater(Actor *);
extern int bainput_should_enter_first_person(Actor *);
extern int _badrone_entrypoint_24(Actor *);
extern int bainput_should_dive(Actor *);
extern int func_80096500(Actor *);
extern int bakey_pressed(Actor *, int);
extern int baflag_isTrue(Actor *, int);
extern void bs_setState(Actor *, int);
extern s32 D_80800BA4_bsswim[];
extern s32 D_80800BB4_bsswim[];
extern s32 D_80800BC4_bsswim[];
extern s32 D_80800BD4_bsswim[];
extern void *baanim_getAnimCtrlPtr();
extern void func_8008B1C8(void *, f32);
extern void anctrl_setDuration(void *, f32);
extern void yaw_setVelocityBounded(PlayerState *, f32, f32);
extern f32 func_800CF67C(void);
extern f32 func_800F10B4(f32, f32, f32, f32, f32);
extern void func_8009DF18(PlayerState *, s32, f32, s32);
extern void bainput_setDiveCooldown(PlayerState *, s32, f32);
extern void baanim_setDurationRange(PlayerState *, f32, f32);
extern void func_8008C9F0(PlayerState *, f32, f32, f32, f32);
extern s32 anctrl_isAt(void *, f32);
extern void func_8009DE74(void *, s32, f32, f32);
extern f32 func_800964DC(void *);
extern f32 func_8009C150(void *);

int func_80800000_bsswim()
{
  s32 local_0;
  if (func_8008E23C())
  {
    local_0 = 0x6D;
  }
  else
  {
    local_0 = 0x30;
  }
  return local_0 | 0;
}

void func_80800030_bsswim(PlayerState *param_0)
{
    f32 local_1[3];
    s32 local_0;

    if (func_80096544(param_0)) {
        if (func_800DC0C0() > 0.5f) {
            func_80092C00(param_0, local_1);
        } else {
            func_80092C24(param_0, local_1);
        }
        local_0 = func_8009FBB0(param_0, local_1, 0.0f);
        func_800BA930(local_0, -60, -100, -60, 60, 0, 60);
        func_800BA22C(local_0, 1);
    }
}

void func_808000E0_bsswim(PlayerState *param_0, void *param_1)
{
    s32 local_0;
    local_0 = D_80800B90_bsswim[param_0->unk15C.word];
    if (anctrl_getIndex(param_1) != local_0) {
        anctrl_setStart(param_1, anctrl_getAnimTimer(param_1));
        anctrl_setIndex(param_1, local_0);
        anctrl_start(param_1);
    }
    param_0->unk15C.word++;
    if ((u32)param_0->unk15C.word >= 10) param_0->unk15C.word = 0;
}

void func_80800178_bsswim(PlayerState *param_0)
{
    f32 local_0;

    local_0 = bastick_getZonePosition(param_0);
    if (bastick_getZone(param_0) == 0) {
        baphysics_set_target_horizontal_velocity(param_0, 0.0f);
    } else {
        baphysics_set_target_horizontal_velocity(param_0, func_800F1214(local_0, 30.0f, 300.0f));
    }
}

void func_808001DC_bsswim(param_0) s32 param_0;
{
  if (func_8009E6C4(param_0, 1) == 0)
  {
    baphysics_set_gravity(param_0, 0x42C80000);
    baphysics_set_terminal_velocity(param_0, 0x4305547B);
    bastick_setZoneMax(param_0, 0, 0x3CF5C28F);
    bastick_setZoneMax(param_0, 1, 0x3F800000);
    func_800961AC(param_0, 3);
    if (func_8008E0E8(param_0) != 0)
    {
      _bapackctrl_entrypoint_5(param_0, 4);
    }
  }
}

int func_80800270_bsswim(param_0) s32 param_0;
{
  if (!func_8009E69C(param_0, 1))
  {
    baphysics_reset_terminal_velocity(param_0);
    baphysics_reset_gravity(param_0);
    bastick_resetZones(param_0);
    func_800961AC(param_0, 1);
    if (func_8008E0E8(param_0))
    {
      _bapackctrl_entrypoint_5(param_0, 3);
    }
  }
}

void func_808002E0_bsswim(PlayerState *param_0)
{
    s32 local_0;
    s32 local_3;
    f32 local_1;
    void *local_2;

    local_2 = baanim_getAnimCtrlPtr(param_0);
    func_808001DC_bsswim(param_0);
    local_3 = bs_getPreviousState(param_0);
    if (local_3 == 0x4C) local_1 = 0.8f;
    else local_1 = 0.5f;
    local_0 = local_3;
    if (func_8009CA70(param_0, local_0, 2)) {
        if (local_0 == 0x54) {
            func_8009DF18(param_0, 0x461, 1.0f, 30000);
        } else if (local_0 != 0x4C) {
            func_8009DF18(param_0, 0x461, 1.0f,
                (s32)func_800F10B4(func_800CF67C(), 1.0f, 0.0f, 8000.0f, 30000.0f));
        }
        bainput_setDiveCooldown(param_0, 4, 0.7f);
    }
    if (anctrl_getIndex(local_2) == 0x57 && local_0 != 0x4C) {
        anctrl_setDuration(local_2, 1.2f);
    } else {
        anctrl_reset(local_2);
        func_8008B1C8(local_2, local_1);
        anctrl_setIndex(local_2, 0x57);
        anctrl_setPlaybackType(local_2, 2);
        anctrl_setStart(local_2, 0.3f);
        anctrl_setDuration(local_2, 1.2f);
        anctrl_start(local_2);
    }
    func_8009FFD8(param_0, 1, 3, 3, 2);
    yaw_setVelocityBounded(param_0, 500.0f, 5.0f);
    baphysics_set_target_horizontal_velocity(param_0, 0.0f);
    param_0->unk15C.word = 0;
    func_800A4DA4(param_0, 8);
}

void func_808004C4_bsswim(Actor *param_0)
{
  s32 local_0;
  s32 local_1;
  local_0 = 0;
  local_1 = baanim_getAnimCtrlPtr();
  if ((func_8001210C(7) == 0) && (func_800DC0C0() < 0.5f))
  {
    func_8009FC34(param_0, 1);
  }
  if ((func_8001210C(7) == 0) && (func_800DC0C0() < 0.5f))
  {
    func_80800030_bsswim(param_0);
  }
  if (anctrl_isAt(local_1, 0.01f) != 0)
  {
    func_8009DEC0(param_0, 0x46F, 0.85f, 1.15f, 0x3E80, 0x3E80);
  }
  if (anctrl_isAt(local_1, 0.4348f) != 0)
  {
    func_808000E0_bsswim(param_0, local_1);
  }
  if (bastick_getZone(param_0) == 1)
  {
    local_0 = 0x2E;
  }
  if (player_inWater(param_0) == 0)
  {
    local_0 = 1;
  }
  if (bainput_should_enter_first_person(param_0) != 0)
  {
    local_0 = _badrone_entrypoint_24(param_0);
  }
  if (bainput_should_dive(param_0) != 0)
  {
    local_0 = func_80800000_bsswim(param_0);
  }
  if ((func_80096500(param_0) != 0) && (bakey_pressed(param_0, 8) != 0))
  {
    local_0 = 5;
  }
  if ((baflag_isTrue(param_0, 6) != 0) || (baflag_isTrue(param_0, 0x14) != 0))
  {
    local_0 = 0xD;
  }
  bs_setState(param_0, local_0);
}

void func_80800688_bsswim(s32 arg0)
{
    func_80800270_bsswim();
    func_800A4E30(arg0);
}
int bsswim_entrypoint_0(s32 param_0)
{
  return D_80800BA4_bsswim[param_0];
}

void func_808006C4_bsswim(PlayerState *param_0)
{
    void *local_0;
    f32 local_1;

    local_0 = baanim_getAnimCtrlPtr(param_0);
    func_808001DC_bsswim(param_0);
    if (bs_getPreviousState(param_0) == 0x4C) {
        local_1 = 0.8f;
    } else {
        local_1 = 0.4f;
    }
    if (anctrl_getIndex(local_0) != 0x39) {
        anctrl_reset(local_0);
        anctrl_setIndex(local_0, 0x39);
        func_8008B1C8(local_0, local_1);
        anctrl_setStart(local_0, 0.8f);
        anctrl_setPlaybackType(local_0, 2);
        anctrl_start(local_0);
    }
    func_8008CA4C(param_0, 2);
    baanim_setDurationRange(param_0, 0.3f, 1.5f);
    func_8008C9F0(param_0, 30.0f, 300.0f, 1.2f, 0.7f);
    yaw_setUpdateType(param_0, 3);
    yaw_setVelocityBounded(param_0, 500.0f, 5.0f);
    func_8009D2D8(param_0, 1);
    baphysics_set_type(param_0, 2);
}

void func_808007F8_bsswim(PlayerState *param_0)
{
    s32 local_0;
    void *local_1;
    f32 local_2[3];
    f32 local_3;

    local_0 = 0;
    local_1 = baanim_getAnimCtrlPtr(param_0);
    if (anctrl_isAt(local_1, 0.38f)) {
        func_8009FD24(param_0, 1);
    }
    if (anctrl_isAt(local_1, 0.88f)) {
        func_8009FD24(param_0, 0);
    }
    if (anctrl_isAt(local_1, 0.2f)) {
        func_8009DE74(param_0, 0x40C, 0.9f, 1.1f);
    }
    if (anctrl_isAt(local_1, 0.7f)) {
        func_8009DE74(param_0, 0x40C, 0.9f, 1.1f);
    }
    func_80800178_bsswim(param_0);
    if (bastick_getZone(param_0) == 0) {
        local_0 = 0x2D;
    }
    if (!player_inWater(param_0)) {
        local_0 = 1;
    }
    if (func_8009650C(param_0) && func_8008D214(param_0)) {
        func_80096440(param_0, &local_2);
        if (local_2[1] < -0.7f) {
            local_3 = func_800964DC(param_0);
            if (local_3 - func_8009C150(param_0) > 90.0f) {
                local_0 = func_80800000_bsswim(param_0);
            }
        }
    }
    if (bainput_should_dive(param_0)) {
        local_0 = func_80800000_bsswim(param_0);
    }
    if (func_80096500(param_0) && bakey_pressed(param_0, 8)) {
        local_0 = 5;
    }
    if (baflag_isTrue(param_0, 6) || baflag_isTrue(param_0, 0x14)) {
        local_0 = 0xD;
    }
    bs_setState(param_0, local_0);
}

void func_808009F0_bsswim()
{
    func_80800270_bsswim();
}

int bsswim_entrypoint_1(s32 param_0)
{
  return D_80800BB4_bsswim[param_0];
}

void func_80800A24_bsswim(s32 arg0)
{
    _bsrest_entrypoint_14();
    func_80800270_bsswim(arg0);
}
void func_80800A4C_bsswim(s32 arg0)
{
    func_808001DC_bsswim();
    _bsrest_entrypoint_16(arg0);
}
s32 func_80800A74_bsswim(Actor *this){
    s32 need_rewind;
    
    need_rewind = 0;
    if(_bsrest_entrypoint_20())
        need_rewind = _bsrest_entrypoint_13(this);

    bs_setState(this, need_rewind);
}

int bsswim_entrypoint_2(s32 param_0)
{
  return D_80800BC4_bsswim[param_0];
}

void func_80800AC8_bsswim(s32 arg0)
{
    func_808001DC_bsswim();
    _bsdrone_entrypoint_0(arg0);
}
s32 func_80800AF0_bsswim(Actor *this){
    s32 next_state = 0;
    if(_badrone_entrypoint_30(this)){
        next_state = 1;
    }
    _bsdrone_entrypoint_1(this);
    bs_setState(this, next_state);
}

void func_80800B34_bsswim(s32 arg0)
{
    _bsdrone_entrypoint_2();
    func_80800270_bsswim(arg0);
}
int bsswim_entrypoint_3(s32 param_0)
{
  return D_80800BD4_bsswim[param_0];
}
