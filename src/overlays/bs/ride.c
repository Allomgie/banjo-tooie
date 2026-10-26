#include "common.h"
#include "overlays/ba/playerstate.h"
#include "core2/anctrl.h"

extern void baphysics_set_target_horizontal_velocity(Actor *param_0, f32 param_1);
extern void func_800A34E4(Actor *param_0, s32 param_1);
extern void func_800961AC(Actor *param_0, s32 param_1);
extern void func_8009FFD8(Actor *param_0, s32 param_1, s32 param_2, s32 param_3, s32 param_4);
extern void func_800947EC(Actor *param_0, s32 param_1, s32 param_2);
extern void *func_8009EA64(Actor *param_0);
extern void *_subaddiefind_entrypoint_2(void *param_0, s32 param_1);
extern void baroll_setIdeal(PlayerState *, f32);
extern void func_8009BF5C(PlayerState *, f32);
extern s32 D_808009C0_bsride[];
extern void func_8009D89C(void *, f32);
typedef struct { s16 local_0; s16 local_1; f32 local_2; u8 local_3; u8 local_4; u8 local_5; u8 local_6; f32 local_7; f32 local_8; } Mass47Ride;
extern Mass47Ride D_808009D0_bsride[];
extern void func_80093230(s32, f32);
extern int D_80800A70_bsride[];
extern f32 _chhandcart_entrypoint_1(s32);
extern s32 D_80800A80_bsride[];
extern void func_80099B94(void *);
extern int func_8009E6EC();
extern void func_8009E830(void *, int);
extern void *baanim_getAnimCtrlPtr(PlayerState *);
extern void _chflysaucer_entrypoint_0(s32, f32);
extern s32 D_80800A90_bsride[];
extern void func_800EFB24(f32 *, f32 *, f32 *);
extern void func_800EE7F8(f32 *, f32 *);
extern f32 func_800EEF94(f32 *);
extern f32 func_800D8FF8(void);
extern f32 func_800F10B4(f32, f32, f32, f32, f32);

void func_80800000_bsride(param_0) Actor *param_0;
{
  char *new_var;
  Actor *local_0;
  ;
  *((s32 *) (new_var = ((char *) param_0) + 0x15c)) = *(s32 *)_subaddiefind_entrypoint_2(func_8009EA64(param_0), 0);
  baphysics_set_target_horizontal_velocity(param_0, 0);
  func_800A34E4(param_0, 0);
  func_800961AC(param_0, 8);
  func_8009FFD8(param_0, 1, 1, 3, 7);
  func_800947EC(param_0, 1, 1);
}

int func_8080008C_bsride(param_0)
PlayerState *param_0;
{
    param_0->unk15C.word = 0;
    func_800947EC(param_0, 1, 0);
    func_800A34E4(param_0, 1);
    func_800961AC(param_0, 1);
    baroll_setIdeal(param_0, 0.0f);
    func_8009BF5C(param_0, 0.0f);
}

s32 func_808000F0_bsride(s32 param_0){
    func_8009EAE8(0);
    return func_8080008C_bsride(param_0);
}

s32 func_8080011C_bsride(s32 param_0){
    if(func_8009E6EC() == 0x28){
        func_808000F0_bsride(param_0);
        func_8009E830(param_0, 2);
    }
    else{
        func_80099B94(param_0);
    }
}

void func_8080016C_bsride()
{
    func_8080008C_bsride();
}

int func_8080018C_bsride(Actor *param_0)
{
  func_80800000_bsride();
  baanim_playForDuration_loopSmooth(param_0, 0x256, 0x3F666666);
  func_8009C128(param_0, (Actor *) (((char *) param_0) + 0x16C));
}

void func_808001CC_bsride(PlayerState *param_0)
{
    s32 local_0;
    f32 local_1;
    f32 local_2;
    f32 local_3[3];
    f32 local_4[3];

    local_0 = 0;
    func_8009C128(param_0, local_4);
    func_800EFB24(local_3, local_4, &param_0->unk16C);
    func_800EE7F8(&param_0->unk16C, local_4);
    local_1 = func_800EEF94(local_3);
    local_2 = func_800F10B4(local_1 / func_800D8FF8(), 0.0f, 2000.0f, 0.9f, 0.22f);
    anctrl_setDuration(baanim_getAnimCtrlPtr(param_0), local_2);
    if (!param_0->unk15C.word) local_0 = 0x2F;
    bs_setState(param_0, local_0);
}

int bsride_entrypoint_0(s32 param_0)
{
  return D_808009C0_bsride[param_0];
}

void func_808002A0_bsride(void *param_0)
{
    s32 local_6;
    s32 local_0;
    void *local_1;
    s32 local_2;
    s32 local_3;
    s32 local_4;
    s32 local_5;
    Mass47Ride *local_7;

    local_0 = func_8009E6EC(param_0);
    local_1 = baanim_getAnimCtrlPtr(param_0);
    for (local_7 = D_808009D0_bsride; local_7->local_0; local_7++) {
        if (local_0 == local_7->local_0) {
            local_2 = anctrl_getIndex(local_1) == local_7->local_1;
            local_3 = local_7->local_5 == 1 && *(s32 *)((u8 *)param_0 + 0x160) == 0;
            local_4 = local_7->local_5 == 1 && *(s32 *)((u8 *)param_0 + 0x160) == 1;
            local_5 = local_7->local_5 == 0 && *(s32 *)((u8 *)param_0 + 0x160) == 0;
            local_6 = local_7->local_4 == 1 && local_7->local_8 < anctrl_getAnimTimer(local_1);
            if (local_3 || (local_5 && !local_2) || (local_4 && local_6)) {
                anctrl_reset(local_1);
                anctrl_setIndex(local_1, local_7->local_1);
                anctrl_setDuration(local_1, local_7->local_2);
                if (local_7->local_3 == 1) {
                    anctrl_setPlaybackType(local_1, 2);
                } else {
                    anctrl_setPlaybackType(local_1, 1);
                    anctrl_setSubrange(local_1, 0.0f, local_7->local_7);
                }
                anctrl_start(local_1);
                if (local_7->local_5 == 1) {
                    func_8009D89C(param_0, 1.0f);
                }
                *(s32 *)((u8 *)param_0 + 0x160) = local_7->local_5;
            }
            func_8009E830(param_0, 2);
            return;
        }
    }
    func_8080011C_bsride(param_0);
}

void func_808004AC_bsride(s32 param_0)
{
  func_80093230(param_0, 1.0f);
  func_8080008C_bsride(param_0);
}

s32 func_808004D8_bsride(Actor *this)
{
  func_80800000_bsride();
  baanim_playForDuration_loopSmooth(this, 0x281, 0x3F333333);
  func_80093230(this, 1.35f);
  *(s32 *)((char *)(this) + 0x160) = 0;
}

void func_80800524_bsride(PlayerState *param_0)
{
    s32 local_0 = 0;
    if (*(s32 *)((u8 *)param_0 + 0x160) == 1 && baanim_isStopped(param_0)) {
        baanim_playForDuration_loopSmooth(param_0, 0x281, 0x3F333333);
        *(s32 *)((u8 *)param_0 + 0x160) = 0;
    }
    if (*(s32 *)((u8 *)param_0 + 0x15C) == 0) {
        local_0 = 0x2F;
    }
    bs_setState(param_0, local_0);
}

int bsride_entrypoint_1(int param_0)
{
    return D_80800A70_bsride[param_0];
}

void func_808005B8_bsride()
{
    func_8080008C_bsride();
}

s32 func_808005D8_bsride(s32 param_0)
{
    func_80800000_bsride();
    baanim_playForDuration_loopSmooth(param_0, 0x83, 0x3FE66666);
}

void func_8080060C_bsride(PlayerState *param_0)
{
    AnimCtrl *local_0;
    s32 local_1;

    local_0 = baanim_getAnimCtrlPtr(param_0);
    if (param_0->unk15C.word != 0) {
        local_1 = 0;
        if (1) {}
        func_8008B10C(local_0, _chhandcart_entrypoint_1(param_0->unk15C.word));
    } else {
        local_1 = 0x2F;
    }
    bs_setState(param_0, local_1);
}

s32 func_8080066C_bsride(Actor *this){
    if(func_8009E6EC() == 0x28){
        func_808000F0_bsride(this);
        func_8009E830(this, 2);
    }
    else{
        func_80099B94(this);
    }
}

int bsride_entrypoint_2(s32 param_0)
{
  return D_80800A80_bsride[param_0];
}

int func_808006D0_bsride(Actor *param_0, s32 param_1)
{
  s32 *local_0 = (s32 *)((char *)param_0 + 0x160);
  *local_0 = param_1;
  if (param_1 != 0)
  {
    switch (param_1)
    {
      case 1 :
        _bafpctrl_entrypoint_14(param_0, 1);
        func_800F817C(*(s32 *)((char *)param_0 + 0x184), 1);
        break;

      case 2 :
        _bafpctrl_entrypoint_9(param_0, 0);
        _bafpctrl_entrypoint_11(param_0, 0xf, 1);
        _bafpctrl_entrypoint_14(param_0, 3);
        baflag_set(param_0, 0x24);

    }

  }
  else
  {
    _bafpctrl_entrypoint_14(param_0, 1);
    _bafpctrl_entrypoint_11(param_0, 0xf, 0);
    baflag_clear(param_0, 0x2E);
  }
}

void func_80800798_bsride(Actor *param_0)
{
  switch (func_8009E6EC())
  {
    case 0x28:
      func_808000F0_bsride(param_0);
      func_8009E830(param_0, 2);
      return;

    case 0x4B:
      if ((*((s32 *) (((u8 *) param_0) + 0x160))) == 2)
      {
        func_808006D0_bsride(param_0, 1);
        func_8009E830(param_0, 2);
        return;
      }
      func_808006D0_bsride(param_0, 2);
      func_8009E830(param_0, 2);
      return;

    default:
      func_80099B94(param_0);
      return;
  }
}

void func_8080084C_bsride(s32 arg0)
{
    func_808006D0_bsride(arg0,0);
    func_8080008C_bsride(arg0);
}

void func_80800878_bsride(u8 *param_0)
{
  int new_var2;
  u8 *new_var3;
  s8 *new_var;
  ;
  func_80800000_bsride();
  baanim_playForDuration_loopSmooth(param_0, 0x481, 0x3F547AE1);
  func_8009FFD8(param_0, 1, 1, 3, 7);
  baphysics_set_target_horizontal_velocity(param_0, (long long) 0);
  func_800A34E4(param_0, 0);
  func_800961AC(param_0, 6);
  new_var2 = 0xFFFFFFFFu;
  new_var = ((s8 *) param_0) + 0x160;
  *((s32 *) new_var) = 0;
  func_808006D0_bsride(param_0, 1 & new_var2);
}

void func_80800904_bsride(PlayerState *param_0)
{
    void *local_0;
    s32 local_1;
    local_0 = baanim_getAnimCtrlPtr(param_0);
    local_1 = 0;
    switch (param_0->unk160.word) {
    case 1:
        break;
    case 2:
        baflag_set(param_0, 0x2E);
        break;
    }
    if (param_0->unk15C.word) {
        _chflysaucer_entrypoint_0(param_0->unk15C.word, anctrl_getAnimTimer(local_0));
    } else local_1 = 0x2F;
    bs_setState(param_0, local_1);
}

int bsride_entrypoint_3(s32 param_0)
{
  return D_80800A90_bsride[param_0];
}
