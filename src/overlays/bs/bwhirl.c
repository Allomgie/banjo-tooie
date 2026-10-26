#include "common.h"
#include "overlays/ba/playerstate.h"
extern void baanim_playForDuration_loopSmooth(Actor *a0, s32 a1, f32 a2);

extern u8 D_80800F50_bsbwhirl[];
extern f32 func_80092B8C(PlayerState *, f32 *);
extern f32 func_80092BE8(PlayerState *);
extern void func_800C8E54(s32, f32, f32);
extern void func_800EF1B8(f32 *, f32, f32);
extern f32 bastick_getZonePosition(PlayerState *);
extern s32 bastick_getZone(PlayerState *);
extern f32 func_800F1214(f32, f32, f32);
extern f32 D_80800F5C_bsbwhirl;
extern f32 yaw_get(PlayerState *);
extern f32 func_800136E4(f32);
extern void func_800EFCD8(f32 *, f32, f32);
extern s32 func_800BABB8(s32, f32 *, f32 *, f32, void *);
extern void func_800BA930();
extern f32 func_800D8FF8(void);
extern void func_8009DF18(PlayerState *, s32, f32, s32);
extern void func_8009FFD8(PlayerState *, s32, s32, s32, s32);
extern void baanim_playForDuration_once(PlayerState *, s32, f32);
extern void bastick_setZoneMax(PlayerState *, s32, f32);
extern s32 D_80800F98_bsbwhirl[];
extern s32 D_80800FA8_bsbwhirl[];
extern void func_800A2CE8(PlayerState *, f32, s32);
extern s32 func_8009BCD4(PlayerState *, f32);
extern s32 D_80800FB8_bsbwhirl[];
extern void *baanim_getAnimCtrlPtr();
extern void anctrl_reset(void *);
extern void anctrl_setIndex(void *, s32);
extern void anctrl_setDuration(void *, f32);
extern void func_8008B1C8(void *, f32);
extern void anctrl_setStart(void *, f32);
extern void anctrl_setSubrange(void *, f32, f32);
extern void anctrl_setPlaybackType(void *, s32);
extern void anctrl_start(void *);
extern f32 bastick_distance(PlayerState *);
extern f32 bastick_getAngleRelativeToBanjo(PlayerState *);
extern f32 yaw_getIdeal(PlayerState *);
extern void yaw_setIdeal(PlayerState *, f32);
extern void baphysics_set_target_yaw(PlayerState *, f32);
extern f32 baphysics_get_target_horizontal_velocity(PlayerState *);
extern void baphysics_set_horizontal_velocity(PlayerState *, f32, f32);
extern void baphysics_set_vertical_velocity(PlayerState *, f32);
extern void baphysics_set_gravity(PlayerState *, f32);
extern void func_8009D7A4(PlayerState *, f32, f32);
extern s32 D_80800FC8_bsbwhirl[];
extern s32 D_80800FD8_bsbwhirl[];
extern s32 D_80800FE8_bsbwhirl[];
extern s32 _bsrest_entrypoint_20(s32);
extern s32 _bsrest_entrypoint_13(s32);
extern void bs_setState(s32, s32);
extern s32 D_80800FF8_bsbwhirl[];
extern void func_80099B94(void);
extern void func_8008C9F0(PlayerState *, f32, f32, f32, f32);

void func_80800000_bsbwhirl(void *param_0) {
    *(u32 *)((u8 *)param_0 + 0x160) = 0;
}

void func_80800008_bsbwhirl(PlayerState *param_0)
{
    f32 local_1[3];
    f32 local_0[3];
    f32 local_2;

    if (func_800BF8E4() > 0) {
        if (!param_0->unk160.word) {
            param_0->unk160.word = func_800C8A98();
            func_800C8E54(param_0->unk160.word, 80.0f, 350.0f);
            func_800C8F64(param_0->unk160.word, 11);
            func_800C8E84(param_0->unk160.word, D_80800F50_bsbwhirl);
        }
        local_2 = func_80092B8C(param_0, local_0);
        func_8009C128(param_0, local_1);
        func_800EF04C(local_1, local_0);
        func_800EF1B8(local_1, func_80092BE8(param_0), local_2);
        local_1[1] += local_2;
        func_800C8CB8(param_0->unk160.word, local_1);
    }
}

void func_808000D8_bsbwhirl(void *param_0)
{
  s32 temp_a3;
  u8 *new_var;
  u8 *new_var2;
  u8 *new_var3;
  new_var = (u8 *) param_0;
  ;
 ; if (0 != (*((s32 *) (((u8 *) param_0) + 0x160)))) { if (1) { } if (1) { } new_var3 = ((u8 *) param_0) + 0x160; new_var2 = (u8 *) param_0; *((s32 *) new_var3) = _chlightfader_entrypoint_1((*((s32 *) (new_var + 0x160))) ^ 0, 0x3E800000, 2, *((s32 *) (new_var2 + 0x160)));
  }
}

extern void baphysics_set_target_horizontal_velocity(Actor *a0, f32 a1);

void func_80800114_bsbwhirl(PlayerState *param_0)
{
    f32 local_0;

    local_0 = bastick_getZonePosition(param_0);
    if (bastick_getZone(param_0) == 0) {
        baphysics_set_target_horizontal_velocity(param_0, 0.0f);
    } else {
        baphysics_set_target_horizontal_velocity(param_0, func_800F1214(local_0, 80.0f, 425.0f));
    }
}

void func_8080017C_bsbwhirl(param_0) Actor *param_0;
{
  int state = bs_getNextState();
  if ((state != 0x1B) && (state != 0x1C) && (state != 0x1D) && (state != 0x1E) && (state != 0xA4) && (state != 0xA5))
  {
    bastick_resetZones(param_0);
    func_800A0CF4(param_0, 0);
    func_800FC74C(0xD);
    func_808000D8_bsbwhirl(param_0);
  }
  func_8008CA4C(param_0, 1);
}

void func_80800200_bsbwhirl(param_0) PlayerState *param_0;
{
    f32 local_5;
    f32 local_0[3];
    f32 local_1[3];
    f32 local_2[3];
    f32 local_3[3];
    s32 local_4;

    func_8009C128(param_0, local_3);
    func_800EFCD8(local_0, yaw_get(param_0), 48.0f);
    local_0[1] = 0.0f;
    func_800EF04C(local_3, local_0);
    local_4 = func_800B5BE4(0xE);
    func_800BABB8(local_4, local_3, NULL, 1.0f, &D_80800F5C_bsbwhirl);
    func_8009BB24(param_0, local_0);
    func_800EFCD8(local_1, param_0->unk170, 250.0f);
    func_800EFCD8(local_2, param_0->unk170 + 45.0f, 250.0f);
    local_1[1] = local_2[1] = 0.0f;
    func_800EF04C(local_1, local_0);
    func_800EF04C(local_2, local_0);
    if (local_2[0] < local_1[0]) {
        local_5 = local_2[0];
        local_2[0] = local_1[0];
        local_1[0] = local_5;
    }
    if (local_2[2] < local_1[2]) {
        local_5 = local_2[2];
        local_2[2] = local_1[2];
        local_1[2] = local_5;
    }
    param_0->unk170 = func_800136E4(param_0->unk170 + 45.0f);
    func_800BA930(local_4, (s16)(s32)local_1[0], 250,
                 (s16)(s32)local_1[2], (s32)local_2[0], 250, (s32)local_2[2]);
    func_800BA22C(local_4, 2);
}

int func_808003A8_bsbwhirl(s32 param_0, s32 param_1)
{
  s32 local_0;
  local_0 = param_1;
  if (bastick_getZone(param_0) > 0)
  {
    local_0 = 0x1C;
  }
  if (bakey_released(param_0, 1))
  {
    local_0 = 0x1E;
  }
  if (bakey_pressed(param_0, 8) && player_isStable(param_0))
  {
    local_0 = 0x1D;
  }
  if (player_inWater(param_0))
  {
    local_0 = 0x2D;
  }
  return local_0;
}

void func_80800430_bsbwhirl(PlayerState *param_0, s32 *param_1)
{
    param_0->unk16C += func_800D8FF8();
    if (param_0->unk16C > 2.0f) {
        param_0->unk16C = 0.0f;
        _suinv_entrypoint_0(param_1, 0x1E, -1, 0x47, 1);
        if (*param_1 != 0x1E) {
            func_8009DF18(param_0, 0x3E9, 0.8f, 0x6D60);
            _chusefeather_entrypoint_1(param_0->unk184, 1);
        }
    }
}

void bsbwhirl_entrypoint_0(PlayerState *param_0)
{
    baanim_playForDuration_once(param_0, 0x22, 0.5f);
    func_8009FFD8(param_0, 1, 1, 1, 2);
    baphysics_set_target_horizontal_velocity(param_0, 0.0f);
    bastick_setZoneMax(param_0, 0, 0.03f);
    bastick_setZoneMax(param_0, 1, 1.0f);
    func_800A0CF4(param_0, 1);
    param_0->unk170 = 0.0f;
    param_0->unk16C = 0.0f;
    func_800FC660(0xD);
    func_80800000_bsbwhirl(param_0);
    func_8009D874(param_0);
    bainput_enable(param_0, 1, 0);
}

int bsbwhirl_entrypoint_1(Actor *param_0)
{
  s32 local_0;
  local_0 = 0;
  bainput_enable(param_0, 1, 1);
  if (anctrl_isStopped(baanim_getAnimCtrlPtr(param_0)))
  {
    local_0 = 0x1B;
  }
  func_80800008_bsbwhirl(param_0);
  bs_setState(param_0, local_0);
}

int bsbwhirl_entrypoint_2(Actor *param_0)
{
  bainput_enable(param_0, 1, 1);
  func_8080017C_bsbwhirl(param_0);
}

int bsbwhirl_entrypoint_3(s32 param_0)
{
  return D_80800F98_bsbwhirl[param_0];
}

void bsbwhirl_entrypoint_4(Actor *param_0)
{
  extern void baphysics_set_target_horizontal_velocity(Actor *a0, f32 a1);
  int new_var;
  new_var = 0x23;
  baanim_playForDuration_loopSmooth(param_0, new_var, 1);
  new_var = 1;
  new_var = 1;
  new_var = new_var & (new_var ^ 0);
  func_8009FFD8(param_0, 1, (0, 1), new_var, 2);
  baphysics_set_target_horizontal_velocity(param_0, 0);
}

void bsbwhirl_entrypoint_5(s32 param_0) {
    s32 local_0;

    local_0 = 0;
    func_80800200_bsbwhirl();
    local_0 = func_808003A8_bsbwhirl(param_0, local_0);
    func_80800430_bsbwhirl(param_0, &local_0);
    func_80800008_bsbwhirl(param_0);
    if (func_8008E148(param_0) != 0) {
        local_0 = _badrone_entrypoint_25(param_0);
    }
    if (player_inWater(param_0) != 0) {
        local_0 = 0x4C;
    }
    bs_setState(param_0, local_0);
}

void bsbwhirl_entrypoint_6()
{
    func_8080017C_bsbwhirl();
}

int bsbwhirl_entrypoint_7(s32 param_0)
{
  return D_80800FA8_bsbwhirl[param_0];
}

void bsbwhirl_entrypoint_8(PlayerState *param_0)
{
    baanim_playForDuration_loopSmooth(param_0, 0x11, 0.53f);
    func_8008C9F0(param_0, 80.0f, 425.0f, 0.56f, 0.4f);
    func_8009FFD8(param_0, 2, 1, 1, 2);
}

void bsbwhirl_entrypoint_9(PlayerState *param_0)
{
    s32 local_0 = 0;
    func_80800200_bsbwhirl(param_0);
    func_800A2CE8(param_0, 0.47f, 4);
    func_800A2CE8(param_0, 0.97f, 3);
    func_80800114_bsbwhirl(param_0);
    if (!bastick_getZone(param_0) && func_8009BCD4(param_0, 1.0f)) local_0 = 0x1B;
    if (bakey_released(param_0, 1)) local_0 = 0x1E;
    if (bakey_pressed(param_0, 8) && player_isStable(param_0)) local_0 = 0x1D;
    if (player_inWater(param_0)) local_0 = 0x4C;
    func_80800430_bsbwhirl(param_0, &local_0);
    func_80800008_bsbwhirl(param_0);
    if (func_8008E148(param_0)) local_0 = _badrone_entrypoint_25(param_0);
    bs_setState(param_0, local_0);
}

void bsbwhirl_entrypoint_10()
{
    func_8080017C_bsbwhirl();
}

int bsbwhirl_entrypoint_11(s32 param_0)
{
  return D_80800FB8_bsbwhirl[param_0];
}

void bsbwhirl_entrypoint_12(PlayerState *param_0)
{
    void *local_0 = baanim_getAnimCtrlPtr(param_0);

    anctrl_reset(local_0);
    anctrl_setIndex(local_0, 0x1B);
    anctrl_setDuration(local_0, 0.8f);
    func_8008B1C8(local_0, 0.134f);
    anctrl_setStart(local_0, 0.14f);
    anctrl_setSubrange(local_0, 0.0f, 0.4495f);
    anctrl_setPlaybackType(local_0, 1);
    anctrl_start(local_0);
    func_8009FFD8(param_0, 1, 1, 3, 6);
    if (bastick_distance(param_0) != 0.0f) yaw_setIdeal(param_0, bastick_getAngleRelativeToBanjo(param_0));
    baphysics_set_target_yaw(param_0, yaw_getIdeal(param_0));
    func_80800114_bsbwhirl(param_0);
    baphysics_set_horizontal_velocity(param_0, yaw_getIdeal(param_0), baphysics_get_target_horizontal_velocity(param_0));
    baphysics_set_vertical_velocity(param_0, 693.5f);
    baphysics_set_gravity(param_0, -1200.0f);
    func_8009D7A4(param_0, 0.91f, 1.09f);
    *(s32 *)((u8 *)param_0 + 0x15C) = 0;
}

void bsbwhirl_entrypoint_13(Actor *param_0)
{
    s32 local_1;
    s32 local_0;
    f32 local_2;
    f32 local_3;
    f32 local_4;

    local_1 = 0;
    local_0 = baanim_getAnimCtrlPtr();
    func_80800200_bsbwhirl(param_0);
    func_80800114_bsbwhirl(param_0);
    func_8009BB24(param_0, &local_4);
    if ((bakey_released(param_0, 8) != 0) && (local_3 > 0.0f))
    {
        baphysics_reset_gravity(param_0);
    }
    switch ((*(s32 *)((s8 *)(param_0) + (0x15C))))
    {
    case 0:
        if (func_8008DF8C(param_0, 0x82) != 0)
        {
            anctrl_setSubrange(local_0, 0.0f, 1.0f);
            anctrl_setDuration(local_0, 0.8f);
            anctrl_setPlaybackType(local_0, 1);
            (*(s32 *)((s8 *)(param_0) + (0x15C))) = 1;
        }
        break;
    case 1:
        if (player_inWater(param_0) != 0)
        {
            local_1 = 0x2D;
        }
        if (player_isStable(param_0) != 0)
        {
            (*(s32 *)((s8 *)(param_0) + (0x15C))) = 2;
            func_8009FE58(param_0);
        }
        break;
    case 2:
        if (anctrl_isStopped(local_0) != 0)
        {
            local_1 = 0x1B;
        }
        local_1 = func_808003A8_bsbwhirl(param_0, local_1);
        break;
    }
    func_80800430_bsbwhirl(param_0, &local_1);
    func_80800008_bsbwhirl(param_0);
    if (func_8008DA24(param_0) != 0)
    {
        local_1 = 0xA8;
    }
    if (player_inWater(param_0) != 0)
    {
        local_1 = 0x4C;
    }
    bs_setState(param_0, local_1);
}

void bsbwhirl_entrypoint_14(s32 arg0)
{
    baphysics_reset_gravity();
    func_8080017C_bsbwhirl(arg0);
}
int bsbwhirl_entrypoint_15(s32 param_0)
{
  return D_80800FC8_bsbwhirl[param_0];
}

void bsbwhirl_entrypoint_16(PlayerState *param_0)
{
    void *local_0;
    local_0 = baanim_getAnimCtrlPtr(param_0);
    anctrl_reset(local_0);
    anctrl_setSmoothTransition(local_0, 0);
    func_8008B188(local_0, 0);
    anctrl_setIndex(local_0, 0x22);
    anctrl_setDuration(local_0, 0.5f);
    anctrl_setPlaybackType(local_0, 1);
    anctrl_start(local_0);
    func_8008CA4C(param_0, 1);
    func_8009D2D8(param_0, 2);
    baphysics_set_target_horizontal_velocity(param_0, 0.0f);
    func_800FCAE0(13, 0, 4000);
}

int bsbwhirl_entrypoint_17(Actor *param_0)
{
  s32 local_0;
  local_0 = 0;
  if (anctrl_isStopped((s32)baanim_getAnimCtrlPtr(param_0) | 0))
  {
    local_0 = 1;
  }
  func_80800008_bsbwhirl(param_0);
  bs_setState(param_0, local_0);
}

void bsbwhirl_entrypoint_18()
{
    func_8080017C_bsbwhirl();
}

int bsbwhirl_entrypoint_19(s32 param_0)
{
  return D_80800FD8_bsbwhirl[param_0];
}

void bsbwhirl_entrypoint_20()
{
    _bsdrone_entrypoint_0();
}

void bsbwhirl_entrypoint_21(s32 arg0)
{
    func_80800200_bsbwhirl();
    func_80800008_bsbwhirl(arg0);
    _bsdrone_entrypoint_1(arg0);
}

void bsbwhirl_entrypoint_22(s32 arg0)
{
    _bsdrone_entrypoint_2();
    func_8080017C_bsbwhirl(arg0);
}
int bsbwhirl_entrypoint_23(s32 param_0)
{
  return D_80800FE8_bsbwhirl[param_0];
}

void bsbwhirl_entrypoint_24(s32 arg0)
{
    _bsrest_entrypoint_14();
    func_8080017C_bsbwhirl(arg0);
}
void bsbwhirl_entrypoint_25()
{
    _bsrest_entrypoint_16();
}

void bsbwhirl_entrypoint_26(s32 param_0) {
    s32 local_0 = 0;
    func_80800200_bsbwhirl(param_0);
    func_80800008_bsbwhirl(param_0);
    if (_bsrest_entrypoint_20(param_0)) {
        local_0 = _bsrest_entrypoint_13(param_0);
    }
    bs_setState(param_0, local_0);
}

int bsbwhirl_entrypoint_27(s32 param_0)
{
  return D_80800FF8_bsbwhirl[param_0];
}

int func_80800EA0_bsbwhirl(s32 param_0, void* param_1)
{
    s32 ret = func_8009E6EC(param_0);

    if (ret == 0x1F || ret == 0x20 || ret == 0x21 || ret == 0x4E || ret == 0x51 || ret == 0x52) {
        func_8009E830(param_0, 1);
        return;
    }

    ((void (*)(s32))param_1)(param_0);
}

void bsbwhirl_entrypoint_28(s32 param_0) {
    func_80800EA0_bsbwhirl(param_0, &func_80099B94);
}
