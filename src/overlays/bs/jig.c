#include "common.h"
#include "overlays/ba/playerstate.h"

extern u8 D_8012762C;
extern void *baanim_getAnimCtrlPtr();
extern void yaw_setIdeal(PlayerState *, f32);
extern s32 anctrl_isAt(void *, f32);
extern f32 func_8009F308(PlayerState *);
extern void func_8009DE38(PlayerState *, s32, f32);
extern void _bsjig_entrypoint_2(void);
extern s32 D_808005B0_bsjig[];
extern void anctrl_setDuration(void *, f32);
extern void func_8009FFD8(PlayerState *, s32, s32, s32, s32);
extern void baphysics_set_target_horizontal_velocity(PlayerState *, f32);
extern s32 D_808005C0_bsjig[];

int bsjig_entrypoint_0(enum jig_e param_0)
{
  return param_0 == (enum jig_e)0x44;
}

void bsjig_entrypoint_1(u8 *param_0)
{
  s32 sp2C;
  s32 temp_v0;
  s32 var_a1;
  temp_v0 = baanim_getAnimCtrlPtr();
  sp2C = temp_v0;
  anctrl_reset(temp_v0);
  anctrl_setSmoothTransition(sp2C, 0);
  anctrl_setIndex(sp2C, 0x2E);
  anctrl_setDuration(sp2C, 4.3f);
  anctrl_setPlaybackType(sp2C, 1);
  anctrl_start(sp2C);
  yaw_setIdeal(param_0, func_8009F308(param_0));
  func_8009FFD8(param_0, 1, 1, 3, 2);
  baphysics_set_target_horizontal_velocity(param_0, (0 * 23) * (2 & 0xFFFFFFFFFFFFFFFFu));
  var_a1 = func_800D0018(1, D_8012762C) != 0;
  if (var_a1 == 0)
  {
    if (1)
    {
    }
    var_a1 = 0;
  }
  *((s32 *) (((s8 *) param_0) + 0x160)) = var_a1;
  func_800FC660(5, var_a1);
  func_800A4DFC(param_0, 9);
  func_800C52F4(func_800A4C68(param_0), 2);
  func_800A0CF4(param_0, 1);
  func_8009DE38(param_0, 0x422, 1.0f);
  baflag_clear(param_0, 7);
  baflag_clear(param_0, 0xF);
  func_8008E944(param_0);
  _chjigsawdance_entrypoint_1(func_80106790(func_800A32F8(param_0)), 1);
  *((s32 *) (((s8 *) param_0) + 0x15C)) = sp2C * 0;
}

void bsjig_entrypoint_2(void) {
    s32 local_0;
    s32 local_1;

    local_1 = func_800F53D0();
    local_0 = local_1;
    if (func_800A32F8(local_1) != 0) {
        _chjigsawdance_entrypoint_1(func_80106790(func_800A32F8(local_0)), 4);
    }
}

void bsjig_entrypoint_3(PlayerState *param_0)
{
    s32 local_0 = 0;
    void *local_1;

    local_1 = baanim_getAnimCtrlPtr(param_0);
    yaw_setIdeal(param_0, func_8009F308(param_0));
    if (anctrl_isAt(local_1, 0.6502f)) {
        func_8009D874(param_0);
    }
    if (anctrl_isAt(local_1, 0.835f)) {
        param_0->unk15C.word++;
        func_8009DE38(param_0, 0x434, 1.3f);
    }
    if (anctrl_isAt(local_1, 0.94f)) {
        func_8009DE38(param_0, 0x3EA, 1.0f);
    }
    if (anctrl_isStopped(local_1)) {
        if (param_0->unk160.word) {
            local_0 = 0x34;
        } else {
            local_0 = 1;
        }
    }
    func_8009919C(param_0, _bsjig_entrypoint_2, param_0->unk184);
    bs_setState(param_0, local_0);
}

void bsjig_entrypoint_4(param_0) Actor *param_0;
{
  s32 local_0;
  local_0 = func_800A32F8();
  if (local_0 != 0)
  {
    _chjigsawdance_entrypoint_1(func_80106790(local_0), 5);
    func_800A34D8(param_0, 0);
  }
}

int bsjig_entrypoint_5(Actor *param_0)
{
  bsjig_entrypoint_4();
  func_800A0CF4(param_0, 0);
  func_800A4E30(param_0);
  func_800C53EC(func_800A4C68(param_0), 2);
  func_8008E95C(param_0);
  func_8009CEE8(param_0);
}

int bsjig_entrypoint_6(s32 param_0)
{
  return D_808005B0_bsjig[param_0];
}

s32 bsjig_entrypoint_7(Actor *this){
    if(func_8009E6EC() == 0x26){
        func_80099B94(this);
    }
    else{
        func_80099AA8(this);
    }
}

int bsjig_entrypoint_8(Actor *param_0)
{
  s32 local_0;
  local_0 = (s32) param_0;
  func_8008E95C(local_0);
  func_800A0CF4(local_0, 0);
  func_800A4E30(local_0);
  func_800C53EC(func_800A4C68(local_0), 2);
  func_8009CEE8(local_0);
}

void bsjig_entrypoint_9(PlayerState *param_0)
{
    void *local_0;
    local_0 = baanim_getAnimCtrlPtr(param_0);
    param_0->unk164.word = bs_getPreviousState(param_0) == 0x44;
    baflag_clear(param_0, 0x1A);
    anctrl_reset(local_0);
    anctrl_setIndex(local_0, 0x282);
    anctrl_setDuration(local_0, 3.6f);
    anctrl_setPlaybackType(local_0, 1);
    anctrl_start(local_0);
    yaw_setIdeal(param_0, func_8009F308(param_0));
    func_8009FFD8(param_0, 1, 1, 3, 2);
    baphysics_set_target_horizontal_velocity(param_0, 0.0f);
    func_800FC660(0x1B);
    func_800A4DFC(param_0, 9);
    func_800C52F4(func_800A4C68(param_0), 2);
    func_800A0CF4(param_0, 1);
    func_8009DE38(param_0, 0x422, 1.0f);
    func_8008E944(param_0);
}

int bsjig_entrypoint_10(Actor *param_0)
{
  s32 local_0;
  local_0 = 0;
  if ((baanim_isAt(param_0, 0x3F170A3D) != 0) || (baanim_isAt(param_0, 0x3F570A3D) != 0))
  {
    func_8009DF18(param_0, 0x3EA, 0x3F800000, 0x7530);
  }
  if (baanim_isStopped(param_0) != 0)
  {
    local_0 = 1;
  }
  return bs_setState(param_0, local_0);
}

int bsjig_entrypoint_11(s32 param_0)
{
  return D_808005C0_bsjig[param_0];
}
