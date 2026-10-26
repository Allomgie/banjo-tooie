#include "common.h"
#include "overlays/ba/playerstate.h"

extern void func_800CE8D8(s32, f32, s32);
extern void func_800CE88C(s32, s32);
extern u8 unk168[];
extern void func_8009590C(PlayerState *, f32);
extern void func_800A4D6C(PlayerState *, f32, f32);
extern void func_80092864(PlayerState *, f32);
extern void func_8009EB00(f32);
extern int func_800947EC(void *, int, int);
extern int func_8001211C();
extern f32 func_8009EA7C(void);
extern void baflag_set(s32, s32);
extern s32 D_808015A0_bsstatue[];
extern s32 D_808015B0_bsstatue[];
extern void func_8009E53C(PlayerState *, s32, f32);
extern void func_8009E5A4(PlayerState *, s32, s32);
extern void func_8009E55C(PlayerState *, s32, f32);
extern void baflag_clear(PlayerState *, s32);
extern s32 D_808015C0_bsstatue[];
extern f32 bastick_getZonePosition(PlayerState *);
extern s32 bastick_getZone(PlayerState *);
extern int D_808015D0_bsstatue[];
extern void func_8009FFD8(PlayerState *, s32, s32, s32, s32);
extern void func_8009BA9C(PlayerState *, s32);
extern void func_800FC660(s32);
extern void baanim_playForDuration_loopSmooth(PlayerState *, s32, f32);
extern void baanim_playForDuration_onceSmooth(PlayerState *, s32, f32);
extern s32 D_808015E0_bsstatue[];
extern s32 D_808015F0_bsstatue[];
extern s32 D_80801600_bsstatue[];
extern s32 D_80801610_bsstatue[];
extern void *baanim_getAnimCtrlPtr(PlayerState *);
extern f32 bastick_distance(PlayerState *);
extern f32 bastick_getAngleRelativeToBanjo(PlayerState *);
extern f32 yaw_getIdeal(PlayerState *);
extern f32 baphysics_get_target_horizontal_velocity(PlayerState *);
extern void anctrl_setDuration(void *, f32);
extern void anctrl_setSubrange(void *, f32, f32);
extern void baanim_setEndAndDuration(PlayerState *, f32, f32);
extern void yaw_setIdeal(PlayerState *, f32);
extern void baphysics_set_target_yaw(PlayerState *, f32);
extern void baphysics_set_horizontal_velocity(PlayerState *, f32, f32);
extern void baphysics_set_vertical_velocity(PlayerState *, f32);
extern void baphysics_set_gravity(PlayerState *, f32);
typedef struct { u32 local_4; f32 local_1; f32 local_3; void *local_0; } StatueMotion61;
extern void baanim_setDurationRange(PlayerState *, f32, f32);
extern void func_8008C9F0(PlayerState *, f32, f32, f32, f32);
extern void func_8008CA30(PlayerState *, f32);
extern void yaw_setVelocityBounded(PlayerState *, f32, f32);
extern f32 func_800DC0C0(void);
extern f32 func_800DC178(f32, f32);
extern void func_8009DB04(PlayerState *, s32, f32, s32);
extern void func_800A2D2C(PlayerState *, f32, s32);
extern s32 baanim_isAt(PlayerState *, f32);
extern s32 bakey_pressed(PlayerState *, s32);
extern void bs_setState(PlayerState *, s32);
extern void baphysics_set_target_horizontal_velocity(PlayerState *, f32);
extern f32 func_800F1214(f32, f32, f32);
void func_80800BEC_bsstatue();
void func_8080147C_bsstatue();
void func_808003B4_bsstatue();
void func_8080054C_bsstatue();

void func_80800000_bsstatue(s32 param_0, s32 param_1)
{
  s32 local_0 = func_800CEAA8(2);
  if (((local_0 != 0) && (param_1 == 0)) || ((local_0 == 0) && (param_1 != 0)))
  {
    func_800CE88C(2, param_1);
  }
}

f32 func_80800050_bsstatue(param_0) s32 param_0;
{
  f32 local_0;
  local_0 = (f32) func_800CEA84(2);
  return local_0;
}

int func_80800078_bsstatue(s32 arg0)
{
    func_800CEAD0(0x2);
}

int func_8080009C_bsstatue(s32 arg0)
{
    func_800CEAA8(0x2);
}

void func_808000C0_bsstatue(s32 param_0, f32 param_1) {
    func_800CE8D8(2, param_1, param_1);
    func_800CE88C(2, 1);
}

int func_80800104_bsstatue(Actor *param_0)
{
  s32 local_0;
  local_0 = func_8001211C();
  return (*(s32 *)((char *)(param_0) + 0x168)) == local_0;
}

void func_80800130_bsstatue(param_0)
PlayerState *param_0;
{
    if (!func_8009E74C(param_0, 7)) {
        func_800947EC(param_0, 1, 0);
        func_8009E474(param_0);
        bastick_popZone(param_0);
        func_80095A40(param_0);
        func_8009590C(param_0, 0.0f);
        func_800A4D6C(param_0, 1.0f, 1.0f);
        func_80092864(param_0, 1.0f);
        func_80095964(param_0, 0);
        func_800A25DC(param_0, 1);
        func_800A2018(param_0, -1);
        func_8009EB00(func_80800050_bsstatue(param_0));
        func_80800000_bsstatue(param_0, 0);
    }
}

int func_808001FC_bsstatue(param_0) Actor *param_0;
{
  if (!func_8009E77C(param_0, 7))
  {
    baflag_clear(param_0, 0x40);
    func_8009E4AC(param_0);
    func_8009E55C(param_0, 0, 150.0f);
    func_8009E53C(param_0, 0, 80.0f);
    func_8009E55C(param_0, 1, 160.0f);
    func_8009E53C(param_0, 1, -90.0f);
    func_800A4D6C(param_0, 1.5f, 1.0f);
    bastick_pushZone(param_0);
    bastick_setZoneMax(param_0, 0, 0x3DF5C28F);
    bastick_setZoneMax(param_0, 1, 0x3F800000);
    func_800959C8(param_0, 0x43480000, 0x42DC0000);
    func_8009590C(param_0, 200.0f);
    func_80092864(param_0, 3.5999908f);
    if (func_8080009C_bsstatue(param_0) == 0)
    {
      func_808000C0_bsstatue(param_0, func_8009EA7C());
    }
    func_80095964(param_0, 1);
    func_800A25DC(param_0, 0);
    func_800A2018(param_0, 0);
    func_800947EC(param_0, 1, 1);
    *((int *) (((char *) param_0) + 0x168)) = (func_8001211C() - 1);
  }
}

void bsstatue_entrypoint_0(param_0) s32 param_0; {
    if (func_80800050_bsstatue() <= 1.0f) {
        baflag_set(param_0, 0x3F);
    }
}

int bsstatue_entrypoint_1(long param_0)
{
  func_808000C0_bsstatue(param_0, 75.0f);
}

void func_808003B4_bsstatue(param_0) u8 *param_0; {
    s32 local_0;

    local_0 = func_8009E6EC();
    switch (local_0) {                              
    case 0x20: ;
    case 0x21:
    case 0x23: ;
    case 0x24:
    case 0x2D: ;
    case 0x2E:
    case 0x51: ;
    case 0x52:
        func_8009E830(param_0, 1);
        return;
    case 0x82:
        (*(s32 *)((s8 *)(param_0) + (0x168))) = func_8001211C(param_0);
        func_8009E830(param_0, 2);
        return;
    default:
        func_80099B94(param_0);
        return;
    }
}

s32 func_80800474_bsstatue(Actor *this){
    if(_badrone_entrypoint_31(this)){
        func_80800000_bsstatue(this, 1);
    }
    _bsdrone_entrypoint_2(this);
    func_80800130_bsstatue(this);
}

s32 func_808004B4_bsstatue(enum bs_e param_0){
    func_808001FC_bsstatue(param_0);
    _bsdrone_entrypoint_0(param_0);
    if(_badrone_entrypoint_31(param_0)){
        func_80800000_bsstatue(param_0, 0);
    }
}

s32 func_808004F4_bsstatue(Actor *this){
    s32 next_state;
    next_state = 0;
    _bsdrone_entrypoint_1(this);
    if(func_80800078_bsstatue(this)){
        next_state = 0xFD;
    }
    bs_setState(this, next_state);
}

int bsstatue_entrypoint_2(s32 param_0)
{
  return D_808015A0_bsstatue[param_0];
}


void func_8080054C_bsstatue(param_0, param_1) PlayerState *param_0; u32 param_1;
{
    StatueMotion61 local_2;
    local_2.local_4 = param_1;
    local_2.local_0 = baanim_getAnimCtrlPtr(param_0);
    param_0->unk15C.bytes[0] = local_2.local_4;
    switch (local_2.local_4) {
    case 1:
        anctrl_reset(local_2.local_0);
        anctrl_setIndex(local_2.local_0, 0x1EF);
        anctrl_setDuration(local_2.local_0, 1.2f);
        anctrl_setSubrange(local_2.local_0, 0.0f, 0.2833f);
        anctrl_setPlaybackType(local_2.local_0, 1);
        anctrl_start(local_2.local_0);
        func_8009FFD8(param_0, 1, 1, 3, 6);
        baphysics_set_target_horizontal_velocity(param_0, 0.0f);
        if (bastick_distance(param_0) != 0.0f) yaw_setIdeal(param_0, bastick_getAngleRelativeToBanjo(param_0));
        break;
    case 2:
        baanim_setEndAndDuration(param_0, 0.4656f, 0.8f);
        baphysics_set_target_yaw(param_0, yaw_getIdeal(param_0));
        func_80800BEC_bsstatue(param_0);
        local_2.local_1 = yaw_getIdeal(param_0);
        local_2.local_3 = baphysics_get_target_horizontal_velocity(param_0);
        baphysics_set_horizontal_velocity(param_0, local_2.local_1, local_2.local_3);
        baphysics_set_vertical_velocity(param_0, 710.0f);
        baphysics_set_gravity(param_0, -2400.0f);
        break;
    case 3:
        baanim_setEndAndDuration(param_0, 0.5456f, 8.0f);
        break;
    case 4:
        func_8009E55C(param_0, 2, 250.0f);
        func_8009E53C(param_0, 2, -180.0f);
        func_8009E5A4(param_0, 2, 2);
        baflag_set(param_0, 0x2D);
        baanim_setEndAndDuration(param_0, 1.0f, 1.2f);
        break;
    case 5:
        func_800A2EAC(param_0);
        baflag_clear(param_0, 0x2D);
        func_8009E55C(param_0, 2, 0.0f);
        baphysics_set_target_horizontal_velocity(param_0, 0.0f);
        break;
    case 0:
        baphysics_reset_gravity(param_0);
        baflag_clear(param_0, 0x2D);
        break;
    }
}

int func_80800790_bsstatue(s32 param_0)
{
  if (param_0)
  {
  }
  if (baflag_isTrue(param_0, 0xF))
  {
    func_8009B7C0(param_0);
  }
  else
  {
    func_80800BEC_bsstatue();
  }
}

int func_808007D4_bsstatue(Actor *param_0)
{
  func_80800130_bsstatue(param_0);
  func_8080054C_bsstatue(param_0, 0);
  if (bs_getNextState(param_0) == 0xF9)
  {
    baphysics_set_target_horizontal_velocity(param_0, 0.0f);
  }
}

void func_8080081C_bsstatue(Actor *param_0)
{
  func_808001FC_bsstatue();
  ((char*)param_0)[0x15C] = 0;
  func_8080054C_bsstatue(param_0, 1);
}

void func_8080084C_bsstatue(u8 *arg0)
{
  s32 sp2C;
  f32 sp20[3];
  sp2C = 0;
  bsstatue_entrypoint_0(arg0);
  func_8009BB24(arg0, sp20);
  if (((bakey_released(arg0, 8) != 0) && (sp20[1] > 0.0f)) || (func_8008D544(arg0) == 0))
  {
    baphysics_reset_gravity(arg0);
  }
  switch (*((u8 *) (((char *) arg0) + 0x15C)))
  {
    case 1:
      if (baanim_isStopped(arg0) != 0)
      {
        func_8080054C_bsstatue(arg0, 2);
      }
      break;

    case 2:
      func_80800790_bsstatue(arg0);
      if (baanim_isStopped(arg0) != 0)
      {
        func_8080054C_bsstatue(arg0, 3);
      }
      break;

    case 3:
      func_80800790_bsstatue(arg0);
      if (func_8008DF8C(arg0, 0x5A) != 0)
      {
        func_8080054C_bsstatue(arg0, 4);
      }
      break;

    case 4:
      func_80800790_bsstatue(arg0);
      if (player_isStable(arg0) != 0)
      {
        func_8080054C_bsstatue(arg0, 5);
      }
      break;

    case 5:
      if (baanim_isStopped(arg0) != 0)
      {
        sp2C = 0xF9;
      }
      break;
  }

  bs_setState(arg0, sp2C);
}

int bsstatue_entrypoint_3(s32 param_0)
{
  return D_808015B0_bsstatue[param_0];
}

void func_808009C0_bsstatue(PlayerState *param_0)
{
    func_8009E53C(param_0, 2, 0.0f);
    func_8009E5A4(param_0, 2, 3);
    func_8009E55C(param_0, 2, 0.0f);
    baflag_clear(param_0, 0x2B);
    func_80800130_bsstatue(param_0);
}

int func_80800A24_bsstatue(Actor *param_0)
{
  Actor *local_0 = param_0;
  func_808001FC_bsstatue();
  func_8009E55C(param_0, 2, 1.1e+02f);
  func_8009E5A4(local_0, 2, 3);
  baanim_playForDuration_onceSmooth(local_0, 0x1F0, 1.3f);
  func_8009FFD8(local_0, 1, 1, 2, 2);
  baphysics_set_target_horizontal_velocity(local_0, 0.0f);
}

void func_80800AA8_bsstatue(Actor *param_0)
{
    s32 local_0;

    local_0 = 0;
    bsstatue_entrypoint_0();
    if (baanim_isAt(param_0, 0.05f) != 0) {
        func_8009DBB0(param_0, 0x4A1, 0x3F6147AE, 0x3F6B851F, 0x1B58);
    }
    if (baanim_isAt(param_0, 0.4f) != 0) {
        func_8009DBB0(param_0, 0x632, 0x3F19999A, 0x3F266666, 0x2EE0);
    }
    if (baanim_isAt(param_0, 0.85f) != 0) {
        func_8009DBB0(param_0, 0x4A1, 0x3F70A3D7, 0x3F7AE148, 0x1770);
    }
    if (baanim_isAt(param_0, 0.5f) != 0) {
        baflag_clear(param_0, 0x2B);
    }
    if (baanim_isAt(param_0, 0.3597f) != 0) {
        baflag_set(param_0, 0x2B);
    }
    if (baanim_isStopped(param_0) != 0) {
        local_0 = 0xF9;
    }
    bs_setState(param_0, local_0);
}

int bsstatue_entrypoint_4(s32 param_0)
{
  return D_808015C0_bsstatue[param_0];
}

void func_80800BEC_bsstatue(param_0) PlayerState *param_0;
{
    f32 local_0;

    local_0 = bastick_getZonePosition(param_0);
    switch (bastick_getZone(param_0)) {
    case 0:
        baphysics_set_target_horizontal_velocity(param_0, 0.0f);
        break;
    case 1:
        baphysics_set_target_horizontal_velocity(param_0, func_800F1214(local_0, 100.0f, 650.0f));
        break;
    }
}

s32 func_80800C64_bsstatue(Actor *this){
    func_80800000_bsstatue(this, 1);
    _bsrest_entrypoint_14(this);
    func_80800130_bsstatue(this);
}

s32 func_80800C98_bsstatue(s32 param_0){
    func_808001FC_bsstatue(param_0);
    _bsrest_entrypoint_16(param_0);
    func_80800000_bsstatue(param_0, 0);
}

int func_80800CCC_bsstatue(Actor *param_0)
{
  s32 local_0;
  local_0 = 0;
  if (_bsrest_entrypoint_20())
  {
    local_0 |= _bsrest_entrypoint_13(param_0);
  }
  bs_setState(param_0, local_0);
}

int bsstatue_entrypoint_5(s32 param_0)
{
  return D_808015D0_bsstatue[param_0];
}

void func_80800D20_bsstatue(u8 *param_0) {
    if (func_8009E6EC() == 0x81) {
        if (func_80099A58(param_0) == 0x11E8) {
            *(s32 *)((char *)param_0 + 0x164) = *(s32 *)((char *)param_0 + 0x164) + 1;
        }
        func_8009E830(param_0, 2);
        return;
    }
    func_808003B4_bsstatue(param_0);
}

s32 func_80800D84_bsstatue(s32 param_0){
    func_800A05DC();
    func_8009EBD0();
    baflag_set(param_0, 0x40);
}

void func_80800DB8_bsstatue(PlayerState *param_0, s32 param_1)
{
    *((u8 *)param_0 + 0x15C) = param_1;
    switch (param_1) {
        case 1:
            baanim_playForDuration_loopSmooth(param_0, 0x1EE, 6.5f);
            func_8009FFD8(param_0, 1, 1, 2, 2);
            baphysics_set_target_horizontal_velocity(param_0, 0.0f);
            func_8009BA9C(param_0, 0);
            *(s32 *)((u8 *)param_0 + 0x164) = 0;
            break;
        case 2:
            baanim_playForDuration_onceSmooth(param_0, 0x1F1, 2.0f);
            func_8009FFD8(param_0, 1, 1, 2, 2);
            baphysics_set_target_horizontal_velocity(param_0, 0.0f);
            func_8009BA9C(param_0, 0);
            func_800FC660(0x17);
            break;
        case 3:
            func_80800D84_bsstatue(param_0);
            break;
    }
}

void func_80800EAC_bsstatue(PlayerState *arg0)
{
    func_8008E95C();
    func_80800130_bsstatue(arg0);
}
s32 func_80800ED4_bsstatue(void *param_0)
{
    s32 s0;
    s0 = param_0;
    func_808001FC_bsstatue(s0);
    func_8008E944(s0);
    if (_badialog_entrypoint_4(s0, 0x11E8, 4, 0x51) != 0) {
        func_80800DB8_bsstatue(s0, 1);
        return;
    }
    func_80800DB8_bsstatue(s0, 2);
}

void func_80800F3C_bsstatue(u8 *param_0)
{
  u8 temp_v0;
 do { func_8080147C_bsstatue(); } while (0);
  temp_v0 = *((u8 *) (((u8 *) param_0) + 0x15C));
  switch (temp_v0)
  {
    case 1:
      if ((*((s32 *) (((u8 *) param_0) + 0x164))) != 0)
    {
      func_80800DB8_bsstatue(param_0, 2);
      return;
    }
      return;

    case 2:
      if (baanim_isAt(param_0, 0.9f) != 0)
    {
      func_80800DB8_bsstatue(param_0, 3);
    }
      break;

  }

}

int bsstatue_entrypoint_6(s32 param_0)
{
  return D_808015E0_bsstatue[param_0];
}

void func_80800FCC_bsstatue()
{
    func_80800130_bsstatue();
}

void func_80800FEC_bsstatue(PlayerState *param_0)
{
    func_808001FC_bsstatue(param_0);
    baanim_playForDuration_onceSmooth(param_0, 0x1F1, 2.0f);
    func_8009FFD8(param_0, 1, 1, 2, 2);
    baphysics_set_target_horizontal_velocity(param_0, 0.0f);
    func_8009BA9C(param_0, 0);
    func_800FC660(0x17);
}

int func_80801060_bsstatue(s32 param_0)
{
  func_8080147C_bsstatue(param_0);
  if (baanim_isAt(param_0, 0.9f) != 0)
  {
    func_80800D84_bsstatue(param_0);
  }
}

int bsstatue_entrypoint_7(s32 param_0)
{
  return D_808015F0_bsstatue[param_0];
}

void func_808010B4_bsstatue()
{
    func_80800130_bsstatue();
}

int func_808010D4_bsstatue(Actor *param_0)
{
  s32 local_0;
  int new_var;
  local_0 = param_0;
  func_808001FC_bsstatue(param_0);
  baanim_playForDuration_loopSmooth(local_0, 0x1EE, 6.5f);
  func_8009FFD8(local_0, 1, 3, 1, 2);
  yaw_setVelocityBounded(local_0, 3e+02f, 3.5f);
  new_var = 0;
  baphysics_set_target_horizontal_velocity(local_0, new_var);
}

int func_80801144_bsstatue(Actor *param_0)
{
  s32 local_0;
  unsigned long local_1;
  local_1 = 0;
  bsstatue_entrypoint_0(param_0);
  if (bainput_should_enter_first_person(param_0))
  {
    local_1 |= _badrone_entrypoint_24(param_0);
  }
  if (bastick_getZone(param_0) == 1)
  {
    local_1 = 0xFA;
  }
  if (bakey_pressed(param_0, 9))
  {
    if (func_80800104_bsstatue(param_0))
    {
      local_1 = 0xF8;
    }
    else
    {
      local_1 = 0xFC;
    }
  }
  if (bakey_pressed(param_0, 8))
  {
    local_1 = 0xFB;
  }
  if (func_80800078_bsstatue(param_0))
  {
    local_1 = 0xFD;
  }
  bs_setState(param_0, local_1);
}

int bsstatue_entrypoint_8(s32 param_0)
{
  return D_80801600_bsstatue[param_0];
}

void func_80801218_bsstatue()
{
    func_80800130_bsstatue();
}

void func_80801238_bsstatue(PlayerState *param_0)
{
    func_808001FC_bsstatue(param_0);
    baanim_playForDuration_loopSmooth(param_0, 0x1E5, 1.38f);
    func_8009FFD8(param_0, 2, 3, 1, 2);
    yaw_setVelocityBounded(param_0, 300.0f, 3.5f);
    baanim_setDurationRange(param_0, 0.3f, 4.0f);
    func_8008C9F0(param_0, 100.0f, 650.0f, 2.0f, 0.9f);
    func_8008CA30(param_0, 1.0f);
    param_0->unk160.word = 0;
}

void func_808012E8_bsstatue(PlayerState *param_0)
{
    s32 local_0;
    local_0 = 0;
    bsstatue_entrypoint_0();
    func_800A2D2C(param_0, 0.4917f, 3);
    func_800A2D2C(param_0, 0.9917f, 4);
    if (baanim_isAt(param_0, 0.4917f) || baanim_isAt(param_0, 0.9917f)) {
        if (param_0->unk160.word == 0 && func_800DC0C0() < 0.55f) {
            param_0->unk160.word = 1;
            func_8009DB04(param_0, 0x4A1, func_800DC178(0.88f, 0.96f), 5000);
        } else param_0->unk160.word = 0;
    }
    func_80800BEC_bsstatue(param_0);
    if (bastick_getZone(param_0) == 0 && func_8009BCD4(param_0, 0x40400000)) local_0 = 0xF9;
    if (bakey_pressed(param_0, 9)) {
        if (func_80800104_bsstatue(param_0)) local_0 = 0xF8;
        else local_0 = 0xFC;
    }
    if (bakey_pressed(param_0, 8)) local_0 = 0xFB;
    if (func_80800078_bsstatue(param_0)) local_0 = 0xFD;
    bs_setState(param_0, local_0);
}

int bsstatue_entrypoint_9(s32 param_0)
{
  return D_80801610_bsstatue[param_0];
}

void func_8080147C_bsstatue(param_0) s32 param_0;
{
    if (baanim_isAt(param_0, 0.16f) != 0) {
        func_8009DB04(param_0, 0x632, 0.8f, 0x2EE0);
    }
    if (baanim_isAt(param_0, 0.39f) != 0) {
        func_8009DB04(param_0, 0x632, 0.7f, 0x3E80);
    }
    if (baanim_isAt(param_0, 0.74f) != 0) {
        func_8009DB04(param_0, 0x632, 0.6f, 0x4E20);
    }
}
