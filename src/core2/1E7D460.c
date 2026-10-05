#include "core2/1E7D460.h"
struct Actor {
  u8 _[0x38];
  void *unk38;
};


#define CAMERA (((LocalCameraPlayer *)param_0)->camera)
#define QQ (*(S_A4E30 **)((u8 *)param_0 + 0x38))
typedef struct { u8 pad[2]; u8 local_0; u8 pad1[5]; s32 local_1[3], local_2[3], local_3[3]; f32 local_4, local_5; s16 local_6; } ScaleA3BA8;
typedef struct { u8 pad[0x38]; ScaleA3BA8 *local_0; } OwnerA3BA8;
extern void func_80110CC0(void *, f32, f32, f32, f32);
extern void func_80115564(void *);
extern f32 _batimer_get();
typedef struct LocalCameraControl { u8 pad00[2], mode, savedMode, requestMode, flag; u8 pad06[0x30]; s16 index; u8 loaded; } LocalCameraControl;
typedef struct LocalCameraPlayer { u8 pad00[0x38]; LocalCameraControl *camera; } LocalCameraPlayer;
extern s32 func_80090E24(PlayerState *);
extern s32 func_80090E30(PlayerState *);
extern s32 func_800A5854(s32);
extern s32 func_800A5904(s32);
extern s32 func_800A5B9C(void);
extern s32 func_800A5B7C(void);
extern s32 func_800A5BBC(void);
extern s32 func_800A5BAC(void);
extern s32 func_800A5BCC(void);
extern s32 func_800A5B6C(void);
extern f32 func_800A5B8C(void);
extern void func_80110F44(PlayerState *);
extern void func_80110D80(PlayerState *, s32);
extern void func_80110D28(PlayerState *, s32);
extern void func_80110D58(PlayerState *, f32);
extern void func_800A5800(s32);
extern void _cadbfunc_entrypoint_26(s32 *);
extern void _cadbfunc_entrypoint_29(s32, s32 *);
extern void _cadbfunc_entrypoint_22(s32 *);
extern void _cadbfunc_entrypoint_24(s32 *);
extern void _cadbfunc_entrypoint_34(s32 *);
extern void _cadbfunc_entrypoint_32(f32 *);
extern void _cadbfunc_entrypoint_0(f32 *);
extern void _cadbfunc_entrypoint_2(f32 *);
extern void _ncbadolly_entrypoint_4(PlayerState *, s32);
extern void _ncbafixpos_entrypoint_4(PlayerState *, s32);
extern void _ncbaspiral_entrypoint_5(PlayerState *, s32);
extern void func_800CA628(f32 *, f32 *, f32 *);
extern void func_801108A0(PlayerState *);
extern s32 func_80110EFC(PlayerState *, s32);
extern s32 func_800A3274(void *);
extern s32 func_800F40EC(void);
typedef struct { u8 value, pad0[5], mode, pad1[0x34], flag; } LocalState;
typedef struct { u8 pad0[0x38]; LocalState *state; u8 pad1[0x148]; s32 index; } LocalPlayer;
extern void func_80090C34(LocalPlayer *);
extern void func_80090C28(LocalPlayer *, s32);
extern void func_800A940C(s32 arg);
typedef struct { char pad[0x184]; s32 unk184; } Actor;
extern void func_800A93E4(int param_0);
extern void func_800CA7E4(f32 *, s32);
typedef struct { u8 unk0; u8 pad1[5]; u8 unk6; } S_A4E30;
f32 mlAbsF(f32 param_0);
struct unk_struct_38 { char pad[60]; int unk3C; };
struct unk_struct_0 { char pad[56]; struct unk_struct_38 *unk38; };
void func_800A4074();
f32 *func_800A4C48();
PlayerState *func_800A4CA8();
int func_800A4D40();

s32 func_800A3B70() 
{
    return 0x40;
}

void func_800A3B78(s32 param_0, s32 param_1)
{
  s32 local_0;
  local_0 = func_800A4CA8(param_0);
  if (local_0 != 0)
  {
    func_801106A8(local_0 | 0, param_1);
  }
}

void func_800A3BA8(PlayerState *param_0, s32 param_1) {
    void *local_0;
    local_0 = func_800A4CA8(param_0);
    if (local_0) {
        switch (((OwnerA3BA8 *)param_0)->local_0->local_0) {
            case 1: func_80110CC0(local_0, ((OwnerA3BA8 *)param_0)->local_0->local_1[0] * ((OwnerA3BA8 *)param_0)->local_0->local_4, ((OwnerA3BA8 *)param_0)->local_0->local_1[1] * ((OwnerA3BA8 *)param_0)->local_0->local_4, ((OwnerA3BA8 *)param_0)->local_0->local_1[2] * ((OwnerA3BA8 *)param_0)->local_0->local_5, ((OwnerA3BA8 *)param_0)->local_0->local_6); break;
            case 2: func_80110CC0(local_0, ((OwnerA3BA8 *)param_0)->local_0->local_2[0] * ((OwnerA3BA8 *)param_0)->local_0->local_4, ((OwnerA3BA8 *)param_0)->local_0->local_2[1] * ((OwnerA3BA8 *)param_0)->local_0->local_4, ((OwnerA3BA8 *)param_0)->local_0->local_2[2] * ((OwnerA3BA8 *)param_0)->local_0->local_5, ((OwnerA3BA8 *)param_0)->local_0->local_6); break;
            case 3: func_80110CC0(local_0, ((OwnerA3BA8 *)param_0)->local_0->local_3[0] * ((OwnerA3BA8 *)param_0)->local_0->local_4, ((OwnerA3BA8 *)param_0)->local_0->local_3[1] * ((OwnerA3BA8 *)param_0)->local_0->local_4, ((OwnerA3BA8 *)param_0)->local_0->local_3[2] * ((OwnerA3BA8 *)param_0)->local_0->local_5, ((OwnerA3BA8 *)param_0)->local_0->local_6); break;
            case 4: func_80110CC0(local_0, 250.0f, 300.0f, 50.0f, ((OwnerA3BA8 *)param_0)->local_0->local_6); break;
        }
        if (param_1) func_80115564(local_0);
    }
}

void func_800A3D78(param_0, param_1, param_2) struct Actor *param_0; s32 param_1; s32 param_2; {
  u8 *local_0 = param_0->unk38;
  if (local_0[2] != param_1) {
    local_0[2] = param_1;
    func_800A3BA8(param_0, param_2);
  }
}

s32 func_800A3DAC(void *arg)
{
    return ((u8 *)(*(void **)((char *)arg + 0x38)))[2];
}

void func_800A3DB8(u8 *param_0, s32 param_1, s32 param_2, s32 param_3, s32 param_4)
{
  u8 *local_0;
  u8 *local_1;
  u8 *local_2;
  ;
  if (((param_1 != (*((u8 *) (((s8 *) (*((u8 **) (((s8 *) param_0) + 0x38)))) + 1)))) || (param_2 != (*((s16 *) (((s8 *) (*((u8 **) (((s8 *) param_0) + 0x38)))) + 0x34))))) || (param_3 != (*((u8 *) (((s8 *) (*((u8 **) (((s8 *) param_0) + 0x38)))) + 0x39)))))
  {
    *((u8 *) (((s8 *) (*((u8 **) (((s8 *) param_0) + 0x38)))) + 1)) = (u8) param_1;
    local_1 = *((u8 **) (((s8 *) param_0) + 0x38));
    func_800A59B8(*((u8 *) (((s8 *) (*((u8 **) (((s8 *) param_0) + 0x38)))) + 1)), (*((u8 **) (((s8 *) param_0) + 0x38))) + 8, (*((u8 **) (((s8 *) param_0) + 0x38))) + 0xC, (*((u8 **) (((s8 *) param_0) + 0x38))) + 0x10, (*((u8 **) (((s8 *) param_0) + 0x38))) + 0x14, (*((u8 **) (((s8 *) param_0) + 0x38))) + 0x18, (*((u8 **) (((s8 *) param_0) + 0x38))) + 0x1C, (*((u8 **) (((s8 *) param_0) + 0x38))) + 0x20, (*((u8 **) (((s8 *) param_0) + 0x38))) + 0x24, local_1 + 0x28);
    *((s16 *) (((s8 *) (*((u8 **) (((s8 *) param_0) + 0x38)))) + 0x34)) = (s16) param_2;
    *((u8 *) (((s8 *) (*((u8 **) (((s8 *) param_0) + 0x38)))) + 0x39)) = (u8) param_3;
    if ((func_800A3DAC(param_0) == 3) && (((local_2 = *((u8 **) (((s8 *) param_0) + 0x38)), (*((s32 *) (((s8 *) local_2) + 0x20))) == 0)) || ((*((u8 *) (((s8 *) local_2) + 0x39))) != 0)))
    {
      func_800A3D78(param_0, 2, param_4);
      return;
    }
    func_800A3BA8(param_0, param_4);
  }
}

void func_800A3EC8(u8 *param_0, int param_1)
{
  u8 *new_var2;
  u8 *temp_v0;
  u8 *new_var;
  u8 *temp_t7;
  s32 temp_a0;
  new_var = param_0;
  temp_v0 = *((u8 **) (((char *) param_0) + 0x38));
  new_var2 = temp_v0;
  if (param_1 != new_var2[7])
  {
    temp_v0[7] = param_1;
    temp_a0 = func_800A4CA8(new_var);
    ;
    func_80110D08(temp_a0, (*((u8 **) (((char *) param_0) + 0x38)))[7], param_0);
  }
}

int func_800A3F14(u8 *param_0, s32 param_1)
{
  u8 *local_1;
  u8 **new_var;
  u8 local_0;
  local_1 = *((u8 **) (((s8 *) param_0) + 0x38));
  local_0 = *((u8 *) (((s8 *) local_1) + 6));
  if (param_1 != local_0)
  {
    switch (local_0)
    {
      case 5:
        func_80090C28(param_0, 1);
        break;

      case 7:
        func_800A3D78(param_0, *((u8 *) (((s8 *) local_1) + 0x3A)), 1);
        *((s8 *) (((s8 *) (*((u8 **) (((s8 *) param_0) + 0x38)))) + 0x3A)) = 0;
        break;

    }

    new_var = (u8 **) (((s8 *) param_0) + 0x38);
    switch (param_1)
    {
      if (1)
      {
        case 2:
          func_800A3B78(param_0, 0x13);
          break;

      }
      case 7:
        func_800A3B78(param_0, 0x1A);
        *((s8 *) (((s8 *) (*((u8 **) (((s8 *) param_0) + 0x38)))) + 0x3A)) = func_800A3DAC(param_0);
        func_800A3D78(param_0, 4U, 1);
        break;

      case 8:
        func_800A3B78(param_0, 0x18);
        break;

      case 6:
        func_800A3B78(param_0, 2);
        break;

    }

    local_1 = (s8 *) (*new_var);
    *((s8 *) (local_1 + 6)) = (s8) param_1;
  }
}

void func_800A4030(u8 *param_0) {
    if ((*(u8 *)((s8 *)((*(u8 **)((s8 *)(param_0) + (0x38)))) + (6))) == 9) {
        func_800A4074(param_0, 9);
        return;
    }
    func_800A4074(param_0, 2);
}

void func_800A4074(param_0, param_1) u8 * param_0; s32 param_1;
{
  u8 *local_0;
  int new_var;
  func_800A5A4C();
  func_80090B98(param_0);
  *((s8 *) (((s8 *) (*((u8 **) (((s8 *) param_0) + 0x38)))) + 0)) = 0;
  *((s8 *) (((s8 *) (*((u8 **) (((s8 *) param_0) + 0x38)))) + 6)) = 0;
  *((s8 *) (((s8 *) (*((u8 **) (((s8 *) param_0) + 0x38)))) + 3)) = 0;
  *((s8 *) (((s8 *) (*((u8 **) (((s8 *) param_0) + 0x38)))) + 4)) = 0;
  *((s8 *) (((s8 *) (*((u8 **) (((s8 *) param_0) + 0x38)))) + 5)) = 0;
  *((f32 *) (((s8 *) (*((u8 **) (((s8 *) param_0) + 0x38)))) + 0x30)) = 1.0f;
  local_0 = *((u8 **) (((s8 *) param_0) + 0x38));
  *((f32 *) (((s8 *) local_0) + 0x2C)) = (f32) (*((f32 *) (((s8 *) local_0) + 0x30)));
  func_800A3F14(param_0, param_1);
  new_var = 0xFF;
  *((s8 *) (((s8 *) (*((u8 **) (((s8 *) param_0) + 0x38)))) + 2)) = 2;
  *((s8 *) (((s8 *) (*((u8 **) (((s8 *) param_0) + 0x38)))) + 1)) = new_var;
  func_800A3DB8(param_0, 0, 0, 0, 1);
  *((s8 *) (((s8 *) (*((u8 **) (((s8 *) param_0) + 0x38)))) + 7)) = new_var;
  func_800A3EC8(param_0, 0);
  _batimer_set(param_0, 7, 0x3F000000);
  *((s16 *) (((s8 *) (*((u8 **) (((s8 *) param_0) + 0x38)))) + 0x36)) = -1;
}

void func_800A4160(s32 arg0) 
{
}
void func_800A4168(void *param_0)
{
  s32 *t6;
  ;
  (*((s32 **) (((char *) param_0) + 0x38)))[0x3C / 4] = 0;
  func_800A4074(param_0, 2);
}

void func_800A4190(param_0) u8 *param_0; {
    u8 temp_v1;
    u8 *temp_v0;

    if ((func_800A4D40() != 0) && (func_800F65D0((*(s32 *)((s8 *)(param_0) + (0x184)))) != 0) && (func_8009CC68(param_0) == 0) && (func_800F3ED0(param_0) != 4) && (_batimer_get(param_0, 7) == 0.0f) && (bainput_should_exit_first_person(param_0) != 0)) {
        temp_v0 = (*(u8 **)((s8 *)(param_0) + (0x38)));
        if (((*(u8 *)((s8 *)(temp_v0) + (4))) == 0) && ((*(u8 *)((s8 *)(temp_v0) + (0x3B))) == 0)) {
            temp_v1 = (*(u8 *)((s8 *)(temp_v0) + (2)));
            switch (temp_v1) {                      
            case 1:
                func_8009DB04(param_0, 0x488, 0x3F800000, 0x2EE0);
                func_800A3D78(param_0, 2, 1);
                break;
            case 2:
                if (((*(s32 *)((s8 *)(temp_v0) + (0x20))) != 0) && ((*(u8 *)((s8 *)(temp_v0) + (0x39))) == 0)) {
                    func_8009DB04(param_0, 0x488, 0x3F99999A, 0x2EE0);
                    func_800A3D78(param_0, 3, 1);
                } else {
                    func_8009DB04(param_0, 0x487, 0x3F800000, 0x2EE0);
                    func_800A3D78(param_0, 1, 1);
                }
                break;
            case 3:
                func_8009DB04(param_0, 0x487, 0x3F800000, 0x2EE0);
                func_800A3D78(param_0, 1, 1);
                break;
            }
            _batimer_set(param_0, 7, 0x3ECCCCCD);
        }
    }
}

s32 func_800A4338(PlayerState *param_0)
{
    s32 local_0;
    s32 local_1;
    s32 local_2;
    s32 local_3;
    s32 local_4;
    s32 local_5;
    s32 local_6;
    s32 local_7;
    f32 local_8;
    s32 local_9;

    local_0 = func_80090E24(param_0);
    local_6 = 0;
    local_7 = func_80090E30(param_0);
    local_9 = func_800A5854(local_0);
    if (local_0 == -1 || !func_800A5904(local_0) || (CAMERA->loaded && local_9 != 4)) {
        CAMERA->requestMode = func_800A5B9C();
        if (CAMERA->requestMode == 5) {
            local_6 = 1;
            CAMERA->requestMode = 0;
        }
        func_800A3DB8(param_0, 0, func_800A5B7C(), local_6, local_7);
        func_800A3EC8(param_0, func_800A5BBC());
        if (CAMERA->requestMode) {
            func_800A3D78(param_0, CAMERA->requestMode, local_7);
        } else if (CAMERA->loaded) {
            if (CAMERA->savedMode) {
                func_800A3D78(param_0, CAMERA->savedMode, local_7);
            } else {
                func_80110F44(func_800A4CA8(param_0));
            }
        }
        CAMERA->flag = func_800A5BAC();
        func_80110D80(func_800A4CA8(param_0), func_800A5BCC());
        func_80110D28(func_800A4CA8(param_0), func_800A5B6C());
        func_80110D58(func_800A4CA8(param_0), func_800A5B8C());
        CAMERA->loaded = 0;
        return 0;
    }
    local_1 = bs_getCurrentState(param_0);
    switch (local_9) {
    case 4:
        func_800A5800(local_0);
        _cadbfunc_entrypoint_26(&local_2);
        local_1 = local_0 + 1;
        if (!local_2 && CAMERA->loaded && local_1 != CAMERA->loaded && CAMERA->savedMode) {
            local_2 = CAMERA->savedMode;
        }
        if (local_2 == 5) {
            local_6 = 1;
            local_2 = 0;
        }
        if (!local_2 && CAMERA->mode == 4) local_2 = 1;
        if (!CAMERA->loaded) {
            _cadbfunc_entrypoint_29(0x10, &local_3);
            if (local_3) CAMERA->savedMode = func_800A3DAC(param_0);
            else CAMERA->savedMode = 0;
        }
        if (local_2) func_800A3D78(param_0, local_2, 0);
        CAMERA->requestMode = local_2;
        _cadbfunc_entrypoint_22(&local_4);
        _cadbfunc_entrypoint_24(&local_5);
        func_800A3DB8(param_0, local_5, local_4, local_6, 0);
        _cadbfunc_entrypoint_29(0x40, &local_3);
        func_800A3EC8(param_0, local_3);
        _cadbfunc_entrypoint_29(0x20, &local_3);
        CAMERA->flag = local_3;
        _cadbfunc_entrypoint_29(0x80, &local_3);
        func_80110D80(func_800A4CA8(param_0), local_3);
        _cadbfunc_entrypoint_34(&local_4);
        func_80110D28(func_800A4CA8(param_0), local_4);
        _cadbfunc_entrypoint_32(&local_8);
        func_80110D58(func_800A4CA8(param_0), local_8);
        CAMERA->loaded = local_1;
        return 0;
    case 3:
        if (func_8009CA70(param_0, local_1, 0x4000)) {
            s32 local_10 = 0;
            func_800A5800(local_0);
            _cadbfunc_entrypoint_29(4, &local_10);
            if (!local_10) return 0;
        }
        func_800A3B78(param_0, 13);
        _ncbadolly_entrypoint_4(func_800A4CA8(param_0), local_0);
        func_800A3F14(param_0, 4);
        return 1;
    case 1:
        if (func_8009CA70(param_0, local_1, 0x4000)) {
            s32 local_11 = 0;
            func_800A5800(local_0);
            _cadbfunc_entrypoint_29(4, &local_11);
            if (!local_11) return 0;
        }
        func_800A3B78(param_0, 6);
        _ncbafixpos_entrypoint_4(func_800A4CA8(param_0), local_0);
        func_800A3F14(param_0, 4);
        return 1;
    case 2:
        if (local_0 != CAMERA->index) {
            f32 local_12[3];
            f32 local_13[3];
            func_800A5800(local_0);
            _cadbfunc_entrypoint_0(local_12);
            _cadbfunc_entrypoint_2(local_13);
            func_800CA628(func_800A4C48(param_0), local_12, local_13);
            func_801108A0(func_800A4CA8(param_0));
            CAMERA->index = local_0;
        }
        return 0;
    case 7:
        func_800A3B78(param_0, 18);
        _ncbaspiral_entrypoint_5(func_800A4CA8(param_0), local_0);
        func_800A3F14(param_0, 4);
        func_800A4190(param_0);
        return 1;
    }
    return 0;
}

s32 func_800A4878(PlayerState *param_0)
{
    PlayerState *local_0;
    local_0 = func_800A4CA8(param_0);
    if ((*(u8 **)((u8 *)param_0 + 0x38))[5]) return func_80110EFC(local_0, 2);
    if (!func_800A4D40(param_0) || func_8009CC68(param_0) || !func_800F65D0(*(s32 *)((u8 *)param_0 + 0x184)) || (*(u8 **)((u8 *)param_0 + 0x38))[0x3B]) return 0;
    if (bainput_func_80097B4C(param_0)) return func_80110EFC(local_0, 2);
    if (bainput_should_rotate_camera_left(param_0)) return func_80110EFC(local_0, 0);
    if (bainput_should_rotate_camera_right(param_0)) return func_80110EFC(local_0, 1);
    return 0;
}

s32 func_800A4978(void *param_0)
{
    s32 local_0;
    if (func_800F40EC() != 2) return 0;
    switch (func_800A3274(param_0)) {
        case 11:
            local_0 = 7;
            if ((*(u8 **)((u8 *)param_0 + 0x38))[3])
                (*(u8 **)((u8 *)param_0 + 0x38))[3] = 4;
            break;
        case 12:
            local_0 = 8;
            break;
        default:
            local_0 = 6;
            break;
    }
    func_800A3F14(param_0, local_0);
    func_800A4878(param_0);
    func_800A4190(param_0);
    return 1;
}

void func_800A4A14(s32 param_0)
{
  if (!func_800A4338(param_0))
  {
    func_800A4190(param_0);
    func_800A4878(param_0);
  }
}

void func_800A4A4C(s32 arg0)
{
    func_800A4190();
    func_800A4878(arg0);
}
void func_800A4A74(s32 param_0)
{
  s32 local_0;
  local_0 = param_0 | 0;
  if (!func_800A4338(local_0))
  {
    if (!func_800A4978(local_0))
    {
      func_800A4190(local_0);
      func_800A4878(local_0);
      func_800A3F14(local_0, 2);
    }
  }
}

void func_800A4AD0(s32 param_0)
{
  s32 local_0;
  local_0 = func_800A4CA8(param_0);
  if (_ncbaspline_entrypoint_8(local_0))
  {
    func_800A3F14(param_0, 2);
  }
}

void func_800A4B08(LocalPlayer *param_0)
{
    _batimer_decrement(param_0, 7);
    if (func_800F65D0(param_0->index))
    {
        func_80090C34(param_0);
    }
    func_80090C28(param_0, 0);
    switch (param_0->state->mode)
    {
        case 4:
            if (func_800A4338(param_0))
                return;
            if (param_0->state->value != 0)
            {
                func_800A3F14(param_0, 1);
                func_800A3B78(param_0, param_0->state->value);
            }
            else
            {
                func_800A3F14(param_0, 2);
            }
            break;
        case 1:
            func_800A4A14(param_0);
            break;
        case 3:
            func_800A4A4C(param_0);
            break;
        case 5:
            func_800A4AD0(param_0);
            break;
        case 2: case 6: case 7: case 8:
        default:
            if (param_0->state->value)
            {
                func_800A3F14(param_0, 1);
                func_800A3B78(param_0, param_0->state->value);
                break;
            }
            func_800A4A74(param_0);
            break;
        case 0: case 9:
            break;
    }
    param_0->state->flag = 0;
}

f32 *func_800A4C48(param_0) PlayerState * param_0;
{
    return func_800A93F8(param_0->unk184);
}

void func_800A4C68(Actor *param_0)
{
  func_800A940C(param_0->unk184);
}

int func_800A4C88(param_0) Actor * param_0;
{
    func_800A93E4(param_0->unk184);
}

PlayerState *func_800A4CA8(param_0) PlayerState * param_0; {
    PlayerState *t = func_800A4C88(param_0);
    PlayerState *rv;
    if (t != 0) {
        rv = func_80110014(t);
    } else {
        rv = 0;
    }
    return rv;
}

void func_800A4CE8(PlayerState *param_0, s32 param_1) {
    func_800CA7E4(func_800A4C48(param_0), param_1);
}

int func_800A4D14(s32 param_0, s32 param_1)
{
  u32 local_0;
  local_0 = func_800A4C48(param_0);
  func_800CA9D8(local_0 | 0, param_1);
}

int func_800A4D40()
{
  s32 local_0;
  local_0 = func_800A4C88();
  return func_8010FAE4(local_0 | 0) == 2;
}

void func_800A4D6C(u8 *param_0, f32 param_1, f32 param_2)
{
  s32 *t6;
  ;
  *((f32 *) (((char *) (*((s32 **) (((char *) param_0) + 0x38)))) + 0x2c)) = param_1;
  *((f32 *) (((char *) (*((s32 **) (((char *) param_0) + 0x38)))) + 0x30)) = param_2;
  func_800A3BA8(param_0, 1);
}

void func_800A4DA4(PlayerState *param_0, s32 param_1)
{
  u8 *local_1;
  PlayerState *new_var;
  s32 local_0;
  local_1 = *((u8 **) (((u8 *) param_0) + 0x38));
  *(*((u8 **) (((u8 *) param_0) + 0x38))) = param_1;
  {
    u8 local_2 = *((u8 *) ((*((u8 **) (((u8 *) param_0) + 0x38))) + (6 & 0xFF)));
    if ((local_2 != 4) && (local_2 != 5))
    {
      local_0 = func_800A3F14(param_0, 1);
      func_800A3B78(new_var = param_0, param_1);
    }
  }
}

void func_800A4DFC(PlayerState *param_0, s32 param_1)
{
    func_800A3F14(param_0, 3);
    func_800A3B78(param_0, param_1);
}

void func_800A4E30(PlayerState *param_0) {
    QQ->unk0 = 0;
    if ((QQ->unk6 != 4) && (QQ->unk6 != 5)) { func_800A3F14(param_0, 2); }
}

void func_800A4E74(s32 arg0)
{
    func_800A3F14(arg0,0x5);
}

int func_800A4E94(s32 param_0)
{
  s32 local_0;
  func_800A3F14(param_0, 9);
  local_0 = func_800A4CA8(param_0);
  func_80110BF0(local_0 | 0);
}

int func_800A4EC8(s32 param_0)
{
  s32 local_0;
  func_800A3F14(param_0, 2);
  local_0 = func_800A4CA8(param_0);
  func_80110C2C(local_0 | 0);
}

void func_800A4EFC(u8 *param_0, f32 param_1)
{
  f32 local_0[3];
  s32 local_1;
  s32 local_2;
  f32 *local_3;
  u8 *local_4;
  if (param_0 != 0)
  {
    local_4 = *(u8 **)(param_0 + 0x38);
    if (*(u8 *)(local_4 + 4) == 0)
    {
      local_0[0] = mlAbsF(param_1 - (f32)*(s32 *)(local_4 + 8));
      local_0[1] = mlAbsF(param_1 - (f32)*(s32 *)(*(u8 **)(param_0 + 0x38) + 0x14));
      local_0[2] = mlAbsF(param_1 - (f32)*(s32 *)(*(u8 **)(param_0 + 0x38) + 0x20));
      local_1 = 0;
      local_2 = 1;
      local_3 = &local_0[1];
      do
      {
        if (*local_3 < local_0[local_1])
        {
          local_1 = local_2;
        }
        local_2 += 1;
        local_3 += 1;
      }
      while (local_2 != 3);
      func_800A3D78(param_0, local_1 + 1, func_80090E30(param_0), local_1);
    }
  }
}

void func_800A5004(u8 *param_0) {
    if ((*(s32 *)((s8 *)((*(u8 **)((s8 *)(param_0) + (0x38)))) + (0x3C))) == 0) {
        (*(s32 *)((s8 *)((*(u8 **)((s8 *)(param_0) + (0x38)))) + (0x3C))) = func_800CA334();
        func_800A4E94(param_0);
    }
}

int func_800A5044(void *param_0)
{
    if ((*(s32 *)(((u8 *)(*(u8 **)((u8 *)param_0 + 0x38)) + 0x3C))) != 0) {
        func_800A4EC8(param_0);
        func_800CA364(*(void **)(((u8 *)(*(void **)((u8 *)param_0 + 0x38))) + 0x3C));
        (*(s32 *)(((u8 *)(*(void **)((u8 *)param_0 + 0x38)) + 0x3C))) = 0;
    }
}

int func_800A5090(struct unk_struct_0 *param_0) {
    return param_0->unk38->unk3C;
}

int func_800A509C(s32 *param_0)
{
  s32 val = 1;
  *((u8 *) (((char *) param_0[14]) + 59)) = (u8) val;
}
