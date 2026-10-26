#include "common.h"
#include "types.h"

extern s32 func_800D90A4(void *arg);
extern s32 func_800D91EC(void *arg, f32 param_1);
extern f32 func_800F10B4(f32 param_0, f32 param_1, f32 param_2, f32 param_3, f32 param_4);
extern f32 _suquiz_entrypoint_8(s32);
extern void func_80102424(Actor *, s32);
extern void func_800EFA4C(f32 *, f32, f32, f32);
extern int D_80800668_chquizremotectrl;
typedef struct Mass45QuizDisplay { u8 local_0[0x24]; f32 local_1; u8 local_2[0x2C]; f32 local_3; } Mass45QuizDisplay;
extern void func_800DE498(s32, void *, void *, f32, s32, void *);
extern void *func_800D674C(s32);
extern void func_800EF214(f32 *, f32, f32, f32);
extern void func_800E3C8C(f32, f32);
extern void func_800E39D8(f32 *, f32 *);
extern void _suquiz_entrypoint_13(f32 *);
extern void _suquiz_entrypoint_14(f32 *);
extern u8 D_80800650_chquizremotectrl[];
extern u8 D_8080065C_chquizremotectrl[];
extern f32 D_80800664_chquizremotectrl;

void func_80800000_chquizremotectrl(u8 *param_0, s32 param_1)
{
  int new_var;
  switch (param_1)
  {
    case 1:

    case 3:
      break;

    case 0:
      *((f32 *) (((s8 *) param_0) + 0x54)) = 0.0f;
      *((f32 *) (((s8 *) param_0) + 0x50)) = 0.5f;
      break;

    case 2:
      *((f32 *) (((s8 *) param_0) + 0x54)) = 1.0f;
      break;

  }

  new_var = ((*((u8 *) (((s8 *) param_0) + 0x79))) & 0xFFFFu) & 0xFFFFu;
  *((u8 *) (((s8 *) param_0) + 0x79)) = (u8) ((param_1 * 0x10) | ((new_var & 0xFFFFu) & 0xFF0F));
}

void func_80800068_chquizremotectrl(u8 *param_0)
{
  f32 var_f0;
  u32 temp_t6;
  temp_t6 = ((u32) (*((u8 *) (((u8 *) param_0) + 0x79)))) >> 4;
  switch (temp_t6)
  {
    case 1:
      if (func_800D90A4(param_0 + 0x50) != 0)
    {
      func_80800000_chquizremotectrl(param_0, 2);
    }
      var_f0 = func_800F10B4(*((f32 *) (((u8 *) param_0) + 0x50)), 0.5f, 0, 0, 1.0f);
      *((f32 *) (((u8 *) param_0) + 0x54)) = var_f0;
      goto end;

    case 3:
      if (func_800D91EC(param_0 + 0x50, 0.5f) != 0)
    {
      func_80800000_chquizremotectrl(param_0, 0);
    }
      var_f0 = func_800F10B4(*((f32 *) (((u8 *) param_0) + 0x50)), 0, 0.5f, 1.0f, (double) 0.0f);
      *((f32 *) (((u8 *) param_0) + 0x54)) = var_f0;
      goto end;

  }

  end:
  return;

}

void func_8080012C_chquizremotectrl(s32 *param_0) {
    s32 local_0;
    s32 local_2;

    local_0 = _suquiz_entrypoint_26();
    local_2 = func_800A5854(local_0);
    if (local_2 != 2) {
        if ((local_2 == 5) || (local_2 == 6) || (local_2 == 8)) {
            _capod_entrypoint_13(*param_0, 0, local_0, 0x834);
        }
    } else {
        _capod_entrypoint_21(*param_0, 0, local_0, 0x814);
    }
    func_80800000_chquizremotectrl(param_0, 0);
}

void func_808001BC_chquizremotectrl(Actor *param_0, s32 param_1)
{
    func_80102424(param_0, param_1);
    switch (param_0->unk70_10) {
    case 1:
        if (_glglobalsettings_entrypoint_3()) ((f32 *)param_0->actorData)[3] = -300.0f;
        else ((f32 *)param_0->actorData)[3] = -500.0f;
        func_800FC660(0x1E);
        ((f32 *)param_0->actorData)[7] = 1.0f;
        func_8080012C_chquizremotectrl((s32 *)param_0);
        break;
    case 2:
        func_800FC74C(0x1E);
        param_0->unk58 = _suquiz_entrypoint_8(0);
        func_80800000_chquizremotectrl(param_0, 1);
        break;
    case 3:
        func_800FC660(0x1D);
        ((f32 *)param_0->actorData)[7] = 1.0f;
        func_80800000_chquizremotectrl(param_0, 3);
        break;
    case 5:
        func_800FC74C(0x1D);
        _suquiz_entrypoint_25();
        break;
    }
}

void func_808002C8_chquizremotectrl(u8 *param_0)
{
  u32 new_var;
  u32 local_0;
  _suquiz_entrypoint_1();
  new_var = *((u16 *) (((s8 *) param_0) + 0x72));
  local_0 = (u16) new_var;
  local_0 = local_0 >> 0xA;
  new_var = local_0;
  switch (new_var)
  {
    case 5:
      break;

    case 1:
      if (func_800D90A4(param_0 + 0x34) != 0)
    {
      func_808001BC_chquizremotectrl(param_0, 2);
    }
      break;

    case 2:
      if ((func_800D90A4(param_0 + 0x58) != 0) || (_suquiz_entrypoint_5() != 0))
    {
      func_808001BC_chquizremotectrl(param_0, 3);
    }
      break;

    case 3:
      if (func_800D90A4(param_0 + 0x34) != 0)
    {
      func_808001BC_chquizremotectrl(param_0, 4);
    }
      break;

    case 4:
      func_808001BC_chquizremotectrl(param_0, 5);
      break;

  }

  func_80800068_chquizremotectrl(param_0);
}

void func_808003A0_chquizremotectrl(s32 arg0) 
{
}
void func_808003A8_chquizremotectrl(Actor *param_0)
{
    func_800CEA38(0, 1);
    func_800EFA4C(param_0->position, 0.0f, 0.0f, 0.0f);
    param_0->rotation[2] = 0.0f;
    param_0->rotation[0] = 0.0f;
    param_0->rotation[1] = 0.0f;
    func_808001BC_chquizremotectrl(param_0, 1);
}

void func_80800410_chquizremotectrl(Actor *param_0, s32 param_1)
{
    f32 local_0;
    f32 local_1[3];
    f32 local_2[3];

    _suquiz_entrypoint_13(local_1);
    _suquiz_entrypoint_14(local_2);
    func_800EF214(local_1, -local_2[0], local_2[1],
        ((Mass45QuizDisplay *)param_0)->local_3 * ((Mass45QuizDisplay *)param_0)->local_1);
    switch (param_0->unk70_10) {
        case 1:
            local_0 = func_800F10B4(((f32 *)param_0->actorData)[7], 1.0f, 0.0f, 1.0f, 0.0f);
            D_80800664_chquizremotectrl = local_0 * 360.0f;
            break;
        case 2:
            local_0 = 0.0f;
            break;
        case 3:
            local_0 = func_800F10B4(((f32 *)param_0->actorData)[7], 1.0f, 0.0f, 0.0f, 1.0f);
            D_80800664_chquizremotectrl = local_0 * 360.0f;
            break;
        case 4:
        case 5:
            local_0 = 1.0f;
            D_80800664_chquizremotectrl = 0.0f;
            break;
    }
    func_800E41CC();
    func_800E3C8C(50.0f, 2000.0f);
    func_800E39D8(local_1, local_2);
    func_800E3CE8();
    func_800E44FC(param_1);
    func_800E7C28(param_1);
    func_800E7CF4(param_1);
    if (local_0 > 0.0f) {
        func_800DE498(param_1, D_80800650_chquizremotectrl, D_8080065C_chquizremotectrl,
            local_0, 0, func_800D674C(0x9A1));
    }
    func_80101870(param_0, param_1);
    func_800E4208();
    func_800E44FC(param_1);
}

s32 func_808005E4_chquizremotectrl(s32 param_0, s32 param_1, s32 param_2){
    if(param_1 == 0xB)
        return 3;
    return 0;
}

int *chquizremotectrl_entrypoint_0()
{
    return &D_80800668_chquizremotectrl;
}
