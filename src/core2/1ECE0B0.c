/*
 * 1ECE0B0 -- split into two translation units (1ECE0B0 and 1ED2190).
 *
 * The yaml treated 0x1ECE0B0..0x1ED4440 as one file, but the ROM's .rodata
 * shows two objects: the jump table of func_800F608C ends at 0x1EFF974 and
 * is padded to 0x1EFF980, where the jump tables of the following functions
 * start. IDO aligns every object's .rodata to 16 bytes and never pads inside
 * an object, so this gap is an object boundary. The text shows none because
 * this object happens to end on a 16-byte boundary.
 *
 * The second object starts at func_800F88A0 (ROM 0x1ED2190). The functions
 * up to func_800F8874 work on the state at D_80135490..D_801354DC; from
 * func_800F88A0 on they use D_801354F0..D_80135521, and there is no other
 * 16-byte aligned function start in between.
 */

#include "core2/1ECE0B0.h"
#include "types.h"

extern void func_800F4200(void *, f32 *);
extern f32 func_800D8FF8(void);
extern void func_800EFA20(f32 *, f32 *, f32);
extern void func_800EF04C(f32 *, f32 *);
extern void func_800F4648(void *, f32 *);
extern void _badrone_entrypoint_14(s32, s32, f32);
extern void _badrone_entrypoint_15(s32 *param_0, s32 param_1, f32 param_2);
extern void _badrone_entrypoint_16(s32 *param_0, s32 param_1, f32 param_2);
extern f32 func_800A3048(s32);
extern void func_8009F678(PlayerState *, f32 *, f32 *, f32);
extern void func_8009F440(s32, s32, s32, s32, s32, f32);
extern void func_8009F860(PlayerState *, f32 *, f32, f32, f32, f32);
extern void func_8009FA20(s32, s32, s32, s32, f32);
typedef struct { u8 pad[0x17C]; s32 active; } LocalPlayer;
typedef struct { LocalPlayer *players[8]; u8 pad[8]; LocalPlayer *pending[8]; u8 count; } LocalState_800F5008;
extern u8 func_80092258(LocalPlayer *);
extern void func_80098BA8(LocalPlayer *, s32);
extern u8 D_801354B8[];
extern void func_80093528();
extern void func_80093584();
extern void func_80098BE0();
extern s32 _bafpctrl_entrypoint_5(void);
extern u32 _bafpctrl_entrypoint_4();
extern f32 bastatetimer_get(s32, s32);
extern s32* func_80106790(s32);
extern void *_bahold_entrypoint_5();
extern void func_8008E9B8(void *, f32 *);
extern void func_800A3148();
extern f32 func_80092B8C(PlayerState *);
extern void func_8009C128(PlayerState *, f32 *);
extern f32 _basnowball_entrypoint_4(s32);
extern f32 func_8009BFD8(s32);
extern f32 baroll_getIdeal(s32);
extern s32 bakey_setState(PlayerState *, ButtonId, int);
s32 _badata_entrypoint_35(u32 param);
extern s32 bakey_getControllerIndex(PlayerState *);
extern void bakey_setControllerIndex(PlayerState *, s32);
extern s32 func_800A907C(s32, s32, s32);
extern PlayerState *func_800F43A8(s32);
extern void func_800F3BB0(PlayerState *, f32 *);
extern void func_800F452C(PlayerState *, f32 *);
extern void yaw_setIdeal(PlayerState *, f32);
extern f32 yaw_getIdeal(PlayerState *);
extern void yaw_applyIdeal(PlayerState *);
extern void func_800A92A8(s32, s32);
extern s32 func_800F4244(u32, u32);
extern f32 baphysics_get_target_horizontal_velocity(s32);
extern s32 bs_getCurrentState();
extern u8 D_8012762C;
extern void func_8008DAE8(s32 *param_0, s32 param_1, f32 param_2);
extern int baflag_isTrue(s32 param_0, s32 param_1);
extern f32 func_800964DC(s32);
extern s32 func_800966BC(s32);
extern f32 func_8009C150();
int _badata_entrypoint_14();
extern s32 func_8008DDEC(s32, s32, f32);
extern s32 func_8008DEA4(void *, f32 *, f32);
typedef struct { void *local_0[8]; u8 local_1[8]; u8 pad[0x21]; u8 local_2, local_3; u8 pad2[5]; s16 local_4, local_5; } StateF73C4;
extern void func_800F80D8(u32);
void func_800F8128(s32 arg0);
u8 func_800F8B88(void);
extern s32 func_800DB9B0(void);
extern s32 _glcutDll_entrypoint_1(void);
extern s32 _plsu_entrypoint_1(s32);
extern void _basetup_entrypoint_2(void *);
extern u8 D_801354D9;
extern s32 D_801354B0[];
extern void _bamotor_entrypoint_1(void *param_0, f32 param_1, f32 param_2);
void func_8009AD20(s32, s32);
extern void func_8009AD04(s32 arg0, f32 arg1);
extern void func_8009AD44(s32 arg0, s32 arg1);
extern s32 func_8009E7C8(s32 arg0, s32 arg1);
extern void func_8009AD38(PlayerState *, s32);
extern void func_8009AD2C(PlayerState *, s32);
extern void func_8009ACF4(s32 param_0, f32 param_1);
extern void func_8009AD14(s32, Unk80132ED0 *);
extern void bastatetimer_set(s32, s32, f32);
extern void func_80098778(s32 a, s32 b, s32 c, f32 d, s32 e, s32 f, f32 g);
extern int func_80098730(int, int, int, f32, int, int);
void _bahold_entrypoint_7(s32* param_0, f32 param_1, f32 param_2);
extern void baphysics_set_vertical_velocity(s32, f32);
extern void func_8009BD18(s32, f32);
typedef struct { void *players[8]; u8 flags[8]; u8 pad28[0x21]; u8 updating; u8 pad4A[6]; s16 previous, previous_state; } LocalState_800F84FC;
extern s32 func_800F46D8(s32);
extern s32 func_8009E674(Unk80132ED0 *, s32);
typedef struct { u8 local_0; u8 local_1; u8 local_2; u8 pad3[0x19]; u8 local_1C; u8 local_1D; u8 pad1E[4]; s16 local_22; u8 local_24[0xC]; u8 local_30[0xC]; } EntryF8B94;
void func_800EFA4C(f32 *param_0, f32 param_1, f32 param_2, f32 param_3);
s32 func_800F68B8();
s32 func_800F6C1C();
int func_800F6CC8();
s32 func_800F7B1C(s32 param_0, s32 param_1, f32 param_2, f32 param_3);
void func_800F7E64(s32 param_0, f32 param_1[3]);
int func_800F8088();
void func_800F82C0();
void func_800F8B94();
void func_800F9198();
int func_800F99E8();

extern int D_80135490[];
extern u8 D_801354DA;

extern u32 D_801354DC;


void func_800F47C0(s32 (*param_0)(u8 *))
{
  s32 *local_2;
  s32 *local_3;
  u8 *local_1;
 local_3 = ((u8 *) D_801354B0); local_2 = ((u8 *) D_80135490);
  do
  {
    local_1 = *local_2;
    if ((local_1 != 0) && ((*((s32 *) (((char *) local_1) + 0x17C))) != 0))
    {
      param_0(local_1);
    }
    local_2++;
  }
  while (local_2 != local_3);
}

void func_800F482C(s32 param_0)
{
  s32 *var_s0;
  s32 temp_a0;
  s32 var_s1;
  var_s0 = &D_80135490;
  var_s1 = 0;
  do
  {
    temp_a0 = *var_s0;
    if (temp_a0 != 0)
    {
      if (param_0 != 0)
      {
        if (func_800A3274(temp_a0) == param_0)
        {
          goto block_5;
        }
      }
      else
      {
        block_5:
        func_800F3880(temp_a0 = *var_s0);

        func_800A91F4(var_s1);
        *var_s0 = 0;
      }
    }
    var_s1 += 1;
    var_s0 += 1;
  }
  while (var_s1 != 8);
}

void func_800F48BC(s32 param_0, f32 *param_1) {
    f32 sp2C[3];
    f32 sp20[3];
    void *o = ((void * *) D_80135490)[param_0];
    func_800F4200(o, sp2C);
    func_800EFA20(sp20, param_1, func_800D8FF8());
    func_800EF04C(sp2C, sp20);
    func_800F4648(o, sp2C);
}

void func_800F4924(s32 arg0,s32 a1)
{
    func_800A17A8(((PlayerState **) D_80135490)[arg0],a1);
}

void func_800F4950(s32 arg0)
{
    _baattach_entrypoint_2(((PlayerState **) D_80135490)[arg0]);
}

void func_800F497C(s32 arg0)
{
    _badrone_entrypoint_5(((PlayerState **) D_80135490)[arg0]);
}

void func_800F49A8(s32 arg0)
{
    _badrone_entrypoint_10(((PlayerState **) D_80135490)[arg0]);
}

void func_800F49D4(s32 arg0,void* arg1,s32 arg2)
{
    _badrone_entrypoint_11(((PlayerState **) D_80135490)[arg0],arg1,arg2);
}

void func_800F4A00(s32 arg0)
{
    _badrone_entrypoint_12(((PlayerState **) D_80135490)[arg0]);
}

void func_800F4A2C(s32 arg0)
{
    _badrone_entrypoint_13(((PlayerState **) D_80135490)[arg0]);
}

void func_800F4A58(s32 param_0, s32 param_1, f32 param_2) {
    _badrone_entrypoint_14(((PlayerState **) D_80135490)[param_0], param_1, param_2);
}

void func_800F4A8C(s32 param_0, s32 param_1, f32 param_2)
{
    _badrone_entrypoint_15(((PlayerState **) D_80135490)[param_0], param_1, param_2);
}

void func_800F4AC0(s32 param_0, s32 param_1, f32 param_2)
{
    _badrone_entrypoint_16(((PlayerState **) D_80135490)[param_0], param_1, param_2);
}

void func_800F4AF4(s32 arg0)
{
    func_800A4DA4(((PlayerState **) D_80135490)[arg0]);
}

void func_800F4B20(s32 arg0)
{
    func_800A4E30(((PlayerState **) D_80135490)[arg0]);
}

s32 func_800F4B4C(s32 param_0)
{
  u32 local_0;
  u32 local_1;
  local_0 = ((u32 *) D_80135490)[param_0];
  if (func_8009E674(local_0, 0x200000))
  {
    local_1 = 0;
  }
  else
  {
    local_1 = 1;
  }
  return local_1 | 0;
}

s32 func_800F4B8C(u32 a0, u32 a1, s32 a2)
{
    return func_800F3930(((PlayerState **) D_80135490)[a0],a1,a2);
}

s32 func_800F4BB8(u32 arg0, u32 arg1, s32 arg2)
{
    return func_800F3A78(((PlayerState **) D_80135490)[arg0],arg1,arg2);
}

s32 func_800F4BE4(s32 param_0)
{
  u32 local_0;
  u32 local_1;
  local_0 = ((u32 *) D_80135490)[param_0];
  if (func_8009E674(local_0, 0x20000))
  {
    local_1 = 0;
  }
  else
  {
    local_1 = 1;
  }
  return local_1 | 0;
}

s32 func_800F4C24(s32 param_0)
{
  s32 local_0;
  s32 local_1;
  if (!param_0)
  {
  }
  local_0 = D_80135490[param_0];
  if (func_800F6D24() != 0)
  {
    return 0;
  }
  if (func_800F68B8(param_0) != 0)
  {
    return 0;
  }
  if (func_800F6CC8(param_0) != 0)
  {
    return 0;
  }
  local_1 = bs_getCurrentState(local_0);
  if ((local_1 == 0xED) || (local_1 == 0x157))
  {
    return 0;
  }
  return 1;
}

void func_800F4CC0(s32 arg0)
{
    func_80091E6C(((PlayerState **) D_80135490)[arg0]);
}

void func_800F4CEC(s32 arg0,u32 arg1)
{
    func_80091E48(((PlayerState **) D_80135490)[arg0],arg1);
}

void func_800F4D18(s32 param_0, f32 param_1[3], f32 param_2[3])
{
    s32 local_2 = ((PlayerState **) D_80135490)[param_0];
    func_8009F678(local_2, param_1, param_2, func_800A3048(local_2) * 1000.0f);
}

void func_800F4D74(s32 param_0, f32 *param_1, f32 param_2, f32 param_3, f32 param_4) {
    f32 local_0[3];
    f32 local_1[3];
    PlayerState *local_2;
    local_2 = ((PlayerState * *) D_80135490)[param_0];
    func_800EFA4C(local_0, param_1[0] - param_2, param_1[1] - param_3, param_1[2] - param_4);
    func_800EFA4C(local_1, param_1[0] + param_2, param_1[1] + param_3, param_1[2] + param_4);
    func_8009F678(local_2, local_0, local_1, func_800A3048(local_2) * 1000.0f);
}

void func_800F4E5C(s32 param_0, s32 param_1, s32 param_2, s32 param_3, s32 param_4) {
    s32 temp_a0;

    temp_a0 = D_80135490[param_0];
    func_8009F440(temp_a0, param_1, param_2, param_3, param_4, func_800A3048(temp_a0) * 1000.0f);
}

void func_800F4EC8(s32 param_0, f32 *param_1, f32 param_2, f32 param_3, f32 param_4) {
    PlayerState *local_0 = ((PlayerState * *) D_80135490)[param_0];
    func_8009F860(local_0, param_1, param_2, param_3, param_4, func_800A3048(local_0) * 1000.0f);
}

void func_800F4F34(s32 param_0, s32 param_1, s32 param_2, s32 param_3)
{
  s32 local_0;
  f32 local_1;
  s32 *new_var;
  new_var = &param_1;
  local_0 = ((PlayerState **) D_80135490)[param_0];
  local_1 = func_800A3048(local_0) * 1000.0f;
  func_8009FA20(local_0, *new_var, param_2, param_3, local_1);
}

void func_800F4F98(s32 arg0)
{
    _baattach_entrypoint_5(((PlayerState **) D_80135490)[arg0]);
}

int func_800F4FC4()
{
  s32 local_0;
  local_0 = _plsu_entrypoint_1(0x11);
  if (local_0 != -1)
  {
    func_800F7B9C(local_0 | 0, 0x1F);
  }
  func_80101180(0x15E, 0x2C, 0);
}

void func_800F5008(s32 param_0)
{
    s32 i;
    s32 n;
    LocalPlayer *p;
    for (n = 0, i = 0; i < 8; i++) {
        p = (*((LocalState_800F5008 *) D_80135490)).players[i];
        if (p && p->active) {
            if (0xFF == func_80092258(p)) {
                func_80098BA8(p, param_0);
            } else {
                (*((LocalState_800F5008 *) D_80135490)).pending[n++] = p;
            }
        }
    }
    (*((LocalState_800F5008 *) D_80135490)).count = n;
}

void func_800F50D0(s32 param_0)
{
  volatile long long *new_var;
  volatile long long local_0;
  s32 i;
  if (((u8 *) D_80135490)[0x48] != 0)
  {
    new_var = &local_0;
    func_800CA7E4(func_800A8984(func_800A89F8()), new_var);
    _bainvisible_entrypoint_9(&D_801354B8, ((u8 *) D_80135490)[0x48], new_var);
    for (i = 0; i < ((u8 *) D_80135490)[0x48]; i++)
    {
      func_80098BA8(*((s32 *) ((((u8 *) D_80135490) + (i * 4)) + 0x28)), param_0);
    }

  }
}

int func_800F5184()
{
  func_800F47C0(&func_80093528);
}

int func_800F51A8()
{
  func_800F47C0(&func_80093584);
}

int func_800F51CC()
{
  func_800F47C0(&func_80098BE0);
}

void func_800F51F0(s32 arg0)
{
    func_80093504(((PlayerState **) D_80135490)[arg0]);
}

int func_800F521C(s32 param_0, f32 param_1[3])
{
  s32 local_0;
  local_0 = *(s32*)((char*)D_80135490 + param_0 * 4);
  bs_setState(local_0, _badata_entrypoint_35(local_0) | 0);
  func_800F457C(local_0, param_1);
}

int func_800F5268(int param_0)
{
    if (_bafpctrl_entrypoint_4(((u32 *) D_80135490)[param_0]) != 3)
    {
        return 0;
    }
    if (_bafpctrl_entrypoint_5 != 0)
    {
        return 2;
    }
    return 1;
}

void func_800F52B8(s32 arg0)
{
    func_8008EF3C(((PlayerState **) D_80135490)[arg0]);
}

void func_800F52E4(s32 arg0)
{
    func_8008F4F0(((PlayerState **) D_80135490)[arg0]);
}

s32 func_800F5310(void) {
    s32 n = 0;
    s32 i;
    for (i = 0; i < 8; i++) {
        if (((void * *) D_80135490)[i] != 0) {
            n++;
        }
    }
    return n;
}

AnimCtrl* func_800F5378(s32 arg0)
{
    return baanim_getAnimCtrlPtr(((PlayerState **) D_80135490)[arg0]);
}

void func_800F53A4(s32 arg0)
{
    func_8008E938(((PlayerState **) D_80135490)[arg0]);
}

PlayerState * func_800F53D0(s32 param_0)
{
  return D_80135490[param_0];
}

PlayerState * func_800F53E4(s32 param_0)
{
  if (param_0 >= 0 && param_0 < 8)
  {
    return D_80135490[param_0];
  }
  return 0;
}

s32 func_800F5410(arg0) s32 arg0;
{
    return func_800A3274(((PlayerState **) D_80135490)[arg0]);
}

s32 func_800F543C(s32 arg0)
{
    return 1 << (func_800A3274(((PlayerState **) D_80135490)[arg0]) + 0x1F);
}

void func_800F5470(s32 arg0)
{
    func_80098590(((PlayerState **) D_80135490)[arg0]);
}

f32 func_800F549C(s32 param_0, s32 param_1) {
    s32 local_0 = ((PlayerState **) D_80135490)[param_0];
    if (local_0) return bastatetimer_get(local_0, param_1);
    return 0.0f;
}

//Get Which Character is in Control
u32 func_800F54E4(void) 
{
	return D_801354DC;
}

s32 func_800F54F0(s32 arg0)
{
    return bakey_getControllerIndex(((PlayerState **) D_80135490)[arg0]);
}

void func_800F551C(s32 param_0)
{
  s32 *new_var;
  s32 local_0 = param_0;
  s32 new_var2;
  new_var = D_80135490;
  new_var2 = local_0;
  func_800A3148(new_var[new_var2]);
  if (!local_0)
  {
  }
}

void func_800F554C(s32 arg0)
{
    func_80092BDC(((PlayerState **) D_80135490)[arg0]);
}

s32 func_800F5578(s32 arg0)
{
    return func_800A1718(((PlayerState **) D_80135490)[arg0]);
}

void func_800F55A4(s32 arg0)
{
    func_800A1760(((PlayerState **) D_80135490)[arg0]);
}

void func_800F55D0(s32 arg0)
{
    func_800965D4(((PlayerState **) D_80135490)[arg0]);
}

int func_800F55FC(s32 arg0)
{
    func_80096628(((PlayerState **) D_80135490)[arg0]);
}

void func_800F5628(s32 arg0)
{
    func_80096364(((PlayerState **) D_80135490)[arg0]);
}

void func_800F5654(s32 arg0)
{
    func_80096670(((PlayerState **) D_80135490)[arg0]);
}

void func_800F5680(s32 arg0)
{
    func_800963C0(((PlayerState **) D_80135490)[arg0]);
}

void func_800F56AC(s32 arg0)
{
    func_80096694(((PlayerState **) D_80135490)[arg0]);
}

Unk80132ED0* func_800F56D8(s32 arg0)
{
    return _bahold_entrypoint_5(((PlayerState **) D_80135490)[arg0]);
}

s32 func_800F5704(s32 param_0)
{
    s32 local_0, local_1;
    s32* local_2;
    local_0 = ((volatile s32 *) D_80135490)[param_0];
    local_1 = _bahold_entrypoint_5(local_0);
    if (local_1 != 0) {
        local_2 = (s32*)((u32)func_80106790(local_1) + 0x6c);
        return (s32)(((u32)(*local_2) << 11) >> 20);
    }
    return 0;
}

int func_800F5754(s32 param_0)
{
  void *local_0;
  u32 new_var;
  local_0 = _bahold_entrypoint_5(((void * *) D_80135490)[param_0]);
  if (local_0 != 0)
  {
    new_var = (*((u32 *) (((char *) local_0) + 0x24))) >> 0x16;
    return (*((u32 *) (((char *) local_0) + 0x24))) >> 0x16;
  }
  return 0;
}

void func_800F5794(s32 arg0)
{
    func_800F3B3C(((PlayerState **) D_80135490)[arg0]);
}

void func_800F57C0(s32 param_0)
{
    f32 local_0[2];
    func_8008E9B8(D_80135490[param_0], local_0);
}

void func_800F57F0(s32 arg0)
{
    func_800F3B90(((PlayerState **) D_80135490)[arg0]);
}

s32 func_800F581C(s32 param_0)
{
    s32 val = D_80135490[param_0];
    s32 local_0;

    if (func_8009650C(val)) {
        local_0 = func_80096434(val);
    } else {
        local_0 = 0;
    }
    return local_0;
}

void func_800F586C(s32 arg0)
{
    func_80098B5C(((PlayerState **) D_80135490)[arg0]);
}

s32 func_800F5898(void) 
{
	return 8;
}

void func_800F58A0(s32 arg0)
{
    _bswalk_entrypoint_0(((PlayerState **) D_80135490)[arg0]);
}

void func_800F58CC(arg0) s32 arg0;
{
    func_80096394(((PlayerState **) D_80135490)[arg0]);
}

int func_800F58F8(s32 arg0)
{
    func_800A3354(((PlayerState **) D_80135490)[arg0]);
}

int func_800F5924(s32 arg0)
{
    return func_800A3360(((PlayerState **) D_80135490)[arg0]);
}

void func_800F5950(s32 param_0, f32 *param_1, f32 *param_2, f32 *param_3)
{
    f32 local_4;
    f32 local_0;
    f32 local_1;
    f32 local_2;
    func_800A3148(*(f32 **)(((f32 *) D_80135490) + param_0), &local_4, &local_0, &local_1);
    local_2 = (local_1 * 0.5f) + local_0;
    *param_1 = local_2;
    *param_2 = local_0 - (local_1 * 0.5f);
    *param_3 = local_4;
}

void func_800F59D4(s32 arg0)
{
    _bapackctrl_entrypoint_1(((PlayerState **) D_80135490)[arg0]);
}

void func_800F5A00(s32 arg0,f32* a1)
{
    func_800F3BB0(((PlayerState **) D_80135490)[arg0],a1);
}

void func_800F5A2C(s32 arg0)
{
    func_800F3BD0(((PlayerState **) D_80135490)[arg0]);
}

void func_800F5A58(s32 param_0, s32 *param_1)
{
    f32 local_0[3];
    s32 *temp;
    temp = &D_80135490[param_0];
    temp = (s32 *)*temp;
    func_800F3BB0(temp, local_0);
    param_1[0] = (s32)local_0[0];
    param_1[1] = (s32)local_0[1];
    param_1[2] = (s32)local_0[2];
}

f32 func_800F5AD0(s32 param_0) {
    return 4.0f;
}

void func_800F5AE0(s32 arg0)
{
    func_8009BFCC(((PlayerState **) D_80135490)[arg0]);
}

void func_800F5B0C(s32 arg0)
{
    func_8009CC68(((PlayerState **) D_80135490)[arg0]);
}

void func_800F5B38(arg0) s32 arg0;
{
    func_800F3E84(((PlayerState **) D_80135490)[arg0]);
}

f32 func_800F5B64(s32 param_0, f32 *param_1)
{
    f32 local_24;
    f32 local_20;
    s32 local_1c;

    local_1c = D_80135490[param_0];
    func_80095870(local_1c, &local_20, &local_24);
    func_8009C128(local_1c, param_1);
    param_1[1] += local_20;
    return local_24;
}

void func_800F5BC4(s32 arg0)
{
    func_80092B8C(((PlayerState **) D_80135490)[arg0]);
}

f32 func_800F5BF0(s32 param_0, s32 param_1) {
    f32 ret;
    f32 sp20[3];
    PlayerState *p = ((PlayerState * *) D_80135490)[param_0];
    ret = func_80092B8C(p);
    func_8009C128(p, sp20);
    func_800EF04C(param_1, sp20);
    return ret;
}

f32 func_800F5C44(s32 param_0) {
    s32 temp_a0;

    temp_a0 = *(s32*)(D_80135490 + param_0);
    if (func_800A3274(temp_a0) != 2) {
        return 0.0f;
    }
    return _basnowball_entrypoint_4(temp_a0);
}

void func_800F5C94(s32 arg0)
{
    func_800F3ED0(((PlayerState **) D_80135490)[arg0]);
}

void func_800F5CC0(s32 arg0)
{
    bastick_getAngle(((PlayerState **) D_80135490)[arg0]);
}

void func_800F5CEC(s32 arg0)
{
    bastick_distance(((PlayerState **) D_80135490)[arg0]);
}

void func_800F5D18(s32 arg0)
{
    func_800F40EC(((PlayerState **) D_80135490)[arg0]);
}

void func_800F5D44(s32 arg0, f32* arg1) 
{
    func_800A33CC(((PlayerState **) D_80135490)[arg0],arg1);
}

void func_800F5D70(arg0) s32 arg0;
{
    func_8009BB24(((PlayerState **) D_80135490)[arg0]);
}

void func_800F5D9C(s32 arg0, f32 *arg1)
{
    func_800F4200(((PlayerState **) D_80135490)[arg0], arg1);
}

void func_800F5DC8(s32 param_0, f32 *param_1)
{
  s32 local_0;
  local_0 = *(s32*)((char*)D_80135490 + param_0 * 4);
  param_1[0] = func_8009BFD8(local_0);
  param_1[1] = yaw_getIdeal(local_0);
  param_1[2] = baroll_getIdeal(local_0);
}

void func_800F5E24(s32 arg0)
{
    func_800966BC(((PlayerState **) D_80135490)[arg0]);
}

void func_800F5E50(s32 arg0)
{
    func_800966E0(((PlayerState **) D_80135490)[arg0]);
}

void func_800F5E7C(s32 param_0)
{
  s32 local_0;
  local_0 = ((PlayerState **) D_80135490)[param_0];
  if (func_80096544(local_0))
  {
    func_800964DC(local_0);
  }
  else
  {
    func_8009C150();
  }
}

void func_800F5ECC(s32 arg0)
{
    func_800A4C68(((PlayerState **) D_80135490)[arg0]);
}

void func_800F5EF8(s32 arg0)
{
    func_800A4C88(((PlayerState **) D_80135490)[arg0]);
}

f32 func_800F5F24(u32 arg0)
{
    return yaw_get(((PlayerState **) D_80135490)[arg0]);
}

f32 func_800F5F50(s32 arg0)
{
    return yaw_getIdeal(((PlayerState **) D_80135490)[arg0]);
}

void func_800F5F7C(s32 arg0)
{
    func_8009C150(((PlayerState **) D_80135490)[arg0]);
}

int func_800F5FA8(s32 param_0)
{
  u32 *local_0 = &D_80135490[param_0];
  bakey_setState(*local_0, 9, 2);
  return 1;
}

s32 func_800F5FE0(s32 param_0)
{
  u32 *local_0;
  local_0 = &((PlayerState **) D_80135490)[param_0];
  bakey_setState((PlayerState *)*local_0, 9, 0);
  return 1;
}

void func_800F6018(s32 param_0)
{
    u32 addr = (u32)((u8 *) D_80135490) + (param_0 << 2);
    bakey_setState(*(u8 **)addr, 8, 2);
}

int func_800F604C(s32 param_0, s32 param_1)
{
  int new_var;
  new_var = param_0;
  new_var = param_1 ^ 0;
  new_var = new_var | new_var;
  func_8009EAD0(new_var);
  bs_setState(param_0, _badata_entrypoint_35(param_0) | 0);
  func_8009EAD0(1);
}

void func_800F608C(s32 param_0, s32 param_1) {
    u32 val = ((u32 *) D_80135490)[param_0];
    switch (param_1 - 1) {
        case 0:
            bs_setState(val, _badata_entrypoint_35(val));
            break;
        case 1:
            func_800F604C(val, 4);
            break;
        case 2:
            func_800F604C(val, 3);
            break;
        case 3:
            func_800F604C(val, 2);
            break;
        case 4:
            func_800F604C(val, 5);
            break;
    }
}

s32 func_800F6140(param_0) s32 param_0;
{
  s32 limit = 8;
  s32 sp20;
  s32 *var_s0;
  s32 new_var;
  s32 temp_v0;
  s32 var_s1;
  var_s0 = &D_80135490;
  var_s1 = 0;
  while (1)
  {
    new_var = var_s1;
    if ((*var_s0) == 0)
    {
      temp_v0 = func_800A907C(var_s1, param_0, -1);
      sp20 = temp_v0;
      func_800A9768(temp_v0);
      func_800A93F8(var_s1);
      func_800A93E4(new_var);
      if (var_s1 && var_s1)
      {
      }
      *var_s0 = func_800F43A8(var_s1);
      ((s8 *) D_801354B0)[var_s1] = 0;
      bakey_setControllerIndex(*var_s0, sp20);
      return var_s1;
    }
    var_s1 += 1;
    var_s0 += 1;
    if (var_s1 == limit)
    {
      return 0;
    }
  }

}

int func_800F61E4()
{
  func_800F6140(-1);
}

int func_800F6204()
{
    func_800F6140();
}

s32 func_800F6224(s32 param_0) {
    f32 local_0[3];
    s32 local_1;
    PlayerState *local_2;
    PlayerState *local_3;
    s32 local_4;
    for (local_1 = 0; local_1 < 8; local_1++) {
        if (!((PlayerState * *) D_80135490)[local_1]) {
            local_3 = ((PlayerState * *) D_80135490)[param_0];
            local_4 = func_800A907C(local_1, bakey_getControllerIndex(local_3), -1);
            ((PlayerState * *) D_80135490)[local_1] = local_2 = func_800F43A8(local_1);
            bakey_setControllerIndex(local_2, local_4);
            func_800F3BB0(local_3, local_0);
            func_800F452C(local_2, local_0);
            yaw_setIdeal(local_2, yaw_getIdeal(local_3));
            yaw_applyIdeal(local_2);
            func_800A92A8(2, 2);
            return local_1;
        }
    }
    return 0;
}

s32 func_800F6308(s32 param_0, s32 param_1, s32 param_2)
{
    s32 local_1;
    s32 local_0;
    local_0 = func_800A8FDC();
    func_800A907C(param_0, param_1, local_0);
    local_1 = func_800F43A8(param_0);
    D_80135490[param_0] = local_1;
    bakey_setControllerIndex(local_1, param_1);
    func_800F452C(local_1, param_2);
    func_800A92A8(2, 2);
    return local_1;
}

void func_800F6388(s32 arg0, s32 arg1)
{
    func_8008F788(((PlayerState **) D_80135490)[arg0],arg1);
}

void func_800F63B4(s32 arg0)
{
    func_8008F7B4(((PlayerState **) D_80135490)[arg0]);
}

void func_800F63E0(s32 arg0, u32 arg1)
{
    func_8008F854(((PlayerState **) D_80135490)[arg0],arg1);
}

void func_800F640C(s32 arg0)
{
    func_8008F828(((PlayerState **) D_80135490)[arg0]);
}

s32 func_800F6438(u32 param_0)
{
  u32 local_0;
  u32 new_var;
  local_0 = ((u32 *) D_80135490)[param_0];
  new_var = local_0;
  if (new_var == 0)
  {
    return 0;
  }
  return func_800F4244(new_var ^ 0, local_0);
}

int func_800F6478(s32 arg0)
{
    func_800F424C(((PlayerState **) D_80135490)[arg0]);
}

//Tranformation Type is a bitfield so you can check multiple transformations at once
s32 func_800F64A4(s32 characterIndex, AllowedTransformation transformationType)
{
    return func_800F543C(characterIndex) & transformationType ? 1 : 0;
}

void func_800F64DC(s32 param_0)
{
    s32 local_1;

    local_1 = D_80135490[param_0];
    func_8009CA70(local_1, bs_getCurrentState(local_1), 0x400000);
}

int func_800F651C(s32 param_0)
{
    s32 local_1;
    f32 local_0;

    local_1 = D_80135490[param_0];
    local_0 = baphysics_get_target_horizontal_velocity(local_1);
    if (local_0 == 0.0f)
    {
        return 1;
    }
    if (bs_getCurrentState(local_1) == 1)
    {
        return 1;
    }
    return func_8009E674(local_1, 0x1000);
}

s32 func_800F6590(s32 param_0)
{
  s32 local_0;
  local_0 = D_80135490[param_0];
  return func_8009CBDC(local_0, bs_getCurrentState(local_0)) == 0xA;
}

int func_800F65D0(s32 param_0)
{
  return (D_8012762C == 0x1B) ? 1 : (D_801354DC == param_0);
}

int func_800F6604(s32 param_0)
{
  return _bacough_entrypoint_1(D_80135490[param_0]) == 2;
}

s32 func_800F6634(s32 arg0) 
{
	return 0;
}

int func_800F6640(s32 param_0)
{
  s32 x = ((u32 *) D_80135490)[param_0];
  return func_80092EA4(x) && func_80091E80(x, 1);
}

void func_800F6690(s32 arg0)
{
    func_80092EB0(((PlayerState **) D_80135490)[arg0]);
}

void func_800F66BC(s32 param_0, s32 param_1, f32 param_2)
{
    func_8008DAE8(((PlayerState **) D_80135490)[param_0], param_1, param_2);
}

int func_800F66F0(s32 param_0)
{
    return bs_getCurrentState(D_80135490[param_0]) == 0x6F;
}

int func_800F6720(param_0) s32 param_0;
{
  s32 value;

  value = D_80135490[param_0];
  return func_8009E71C(value, 9) || func_8008DE74(value);
}

int func_800F6774(u32 param_0) {
    return func_800F6D24() == 0 && func_800F8088(param_0) == 0
        && func_800F68B8(param_0) == 0 && func_800F6CC8(param_0) == 0 && func_800A8264() == 0;
}

void func_800F67EC(s32 param_0) {
    s32 local_1;

    local_1 = D_80135490[param_0];
    func_8009CA70(local_1, bs_getCurrentState(local_1), 0x200);
}

s32 func_800F682C(s32 param_0)
{
  if (func_800F6D24() != 0)
  {
    return 0;
  }
  if (func_800F6478(param_0) == 0)
  {
    return 0;
  }
  if (func_8009BD44(*((D_80135490) + param_0)) == 3)
  {
    return 0;
  }
  if (func_800F6C1C(param_0) == 0)
  {
    return 0;
  }
  return 1;
}

s32 func_800F68B8(param_0) s32 param_0;
{
  s32 local_0;
  local_0 = *(s32*)((char*)D_80135490 + param_0 * 4);
  if (func_8009E674(local_0, 8))
  {
    return _badrone_entrypoint_3(local_0) == 1;
  }
  return 0;
}

int func_800F690C(param_0) s32 param_0;
{
    baflag_isTrue(((PlayerState **) D_80135490)[param_0], 0x17);
}

void func_800F693C(s32 arg0)
{
    func_8008DD70(((PlayerState **) D_80135490)[arg0]);
}

int func_800F6968(s32 param_0) {
    s32 local_0;
    s32 local_2;
    f32 local_1;
    local_0 = ((PlayerState **) D_80135490)[param_0];
    local_1 = func_800964DC(local_0);
    return ((s32)(local_1 - func_8009C150(local_0) > 4.0f) != 0) && (func_800966BC(local_0) & 0x2000) != 0;
}

int func_800F69E8(s32 param_0)
{
  s32 local_0 = ((PlayerState **) D_80135490)[param_0];
  return player_isStable(local_0) && func_8009659C(local_0, 0x2000);
}

s32 func_800F6A38(s32 param_0)
{
  s32 tmp;
  s32 local_0;

  tmp = D_80135490[param_0];
  if (!player_inWater(tmp)) {
    return 0;
  }

  local_0 = func_800966BC(tmp);
  if ((local_0 & 0x22000) == 0x22000) {
    local_0 = 1;
  } else {
    local_0 = 0;
  }
  return local_0;
}

int func_800F6AA4(s32 param_0) {
    s32 local_0 = bs_getCurrentState(((PlayerState **) D_80135490)[param_0]);
    return local_0 == 0x1B || local_0 == 0x1C || local_0 == 0x1D || local_0 == 0x1E
        || local_0 == 0x1A || local_0 == 0xA4 || local_0 == 0xA5;
}

u8 func_800F6B34(void) {
	return D_801354DA;
}

s32 func_800F6B40(s32 param_0)
{
  if (func_800F690C() != 0)
  {
    return 1;
  }
  return _ncba1p_entrypoint_10(func_800A4CA8(D_80135490[param_0])) == 3;
}

int func_800F6B94(int param_0) {
    int local_0 = D_80135490[param_0];
    return (func_800A3274(local_0) == 2) && (func_800A1718(local_0) >= 5);
}

int func_800F6BE4(s32 param_0)
{
  if (param_0 >= 0 && param_0 < 8)
  {
    if (((PlayerState **) D_80135490)[param_0] != 0)
    {
      return 1;
    }
  }
  return 0;
}

s32 func_800F6C1C(param_0) s32 param_0;
{
    s32 local_0;
    local_0 = D_80135490[param_0];
    return func_8009CB44(local_0, bs_getCurrentState(local_0)) != 0;
}

int func_800F6C5C(s32 arg0)
{
    player_isStable(((PlayerState **) D_80135490)[arg0]);
}

s32 func_800F6C88(s32 param_0)
{
  s32 local_0;
  unsigned short new_var;
  local_0 = D_80135490[param_0];
  new_var = local_0;
  return func_8009CBDC(local_0, bs_getCurrentState(local_0)) == 2;
}

int func_800F6CC8(param_0) s32 param_0;
{
  if (func_8009E674(D_80135490[param_0], 4))
  {
    return 1;
  }
  if (func_800F8B64())
  {
    return 1;
  }
  return 0;
}

int func_800F6D24(arg0) s32 arg0;
{
    return func_8008E124(((PlayerState **) D_80135490)[arg0]);
}

int func_800F6D50(s32 param_0)
{
  s32 x = *((s32 *) (&((u8 *) D_80135490)[param_0 << 2]));
  return func_8008E124(x) && func_8009E674(x, 0x10);
}

s32 func_800F6DA0(s32 param_0)
{
  s32 local_0;
  local_0 = D_80135490[param_0];
  return func_8009CBDC(local_0, bs_getCurrentState(local_0)) == 0x12;
}

void func_800F6DE0()
{
    _bsbabykaz_entrypoint_14();
}

void func_800F6E00(s32 param_0)
{
  s32 local_1 = D_80135490[param_0];
  func_8009CA70(local_1, bs_getCurrentState(local_1), 0x100000);
}

int func_800F6E40(s32 param_0)
{
  s32 local_0;
  short new_var;
  local_0 = D_80135490[param_0];
  new_var = local_0;
  return func_8009CBDC(local_0, bs_getCurrentState(local_0)) == 0x13;
}

void func_800F6E80(s32 arg0)
{
    func_800A336C(((PlayerState **) D_80135490)[arg0]);
}

s32 func_800F6EAC(s32 param_0)
{
  s32 local_0;
  local_0 = ((PlayerState **) D_80135490)[param_0];
  if (func_8009E674(local_0, 8))
  {
    return _badrone_entrypoint_3(local_0) == 9;
  }
  return 0;
}

int func_800F6F00(s32 param_0)
{
  f32 local_0[6];
  f32 local_1;
  if (_badata_entrypoint_14(D_80135490[param_0]) == 0)
  {
    return 1;
  }
  func_800F58CC(param_0, &local_0[3]);
  if ((local_0[3] != 0.0f) || (local_0[5] != 0.0f))
  {
    return 0;
  }
  if (func_800F6C5C(param_0) == 0)
  {
    return 0;
  }
  func_800F5D70(param_0, &local_0[0]);
  if ((func_800F55FC(param_0) & 0x8000) != 0)
  {
    if ((local_0[1] < 0.0f) && (local_0[1] >= (-1.0f)))
    {
      return 1;
    }
    return 0;
  }
  if ((local_0[1] != (-1.0f)))
  {
    return 0;
  }
  return 1;
}

int func_800F7018(s32 param_0)
{
  u32 local_0;
  if (1)
  {
    local_0 = D_80135490[param_0];
  }
  return func_8009CBDC(local_0, bs_getCurrentState(local_0)) == 8;
}

s32 func_800F7058(s32 param_0)
{
  s32 local_0;
  local_0 = *((s32 *) (((char *) (D_80135490)) + ((param_0 * 4) & 0xFFFFFFFFFFFFFFFFu)));
  if (func_8009E674(local_0, 128))
  {
    return _bashoes_entrypoint_1(local_0) == 3 ? 2 : 1;
  }
  return 0;
}

void func_800F70BC(s32 param_0)
{
    func_8009E71C(((PlayerState **) D_80135490)[param_0], 0xE);
}

int func_800F70EC(s32 param_0)
{
  u32 local_0;
  local_0 = func_8009BD44(D_80135490[param_0]);
  return local_0 != 3;
}

int func_800F711C(s32 param_0)
{
    u32 local_0;
    local_0 = func_8009E674(D_80135490[param_0], 8);
    return local_0 < 1;
}

u32 func_800F7150(s32 param_0)
{
  u32 local_0;
  local_0 = func_80094510(((u32 *) D_80135490)[param_0]);
  return local_0 == 7;
}

s32 func_800F7180(s32 param_0)
{
  s32 local_0;
  local_0 = ((PlayerState **) D_80135490)[param_0];
  if (func_8009E674(local_0, 8))
  {
    return _badrone_entrypoint_3(local_0) == 0xE;
  }
  return 0;
}

void func_800F71D4(s32 arg0)
{
    func_8008E37C(((PlayerState **) D_80135490)[arg0]);
}

s32 func_800F7200(s32 param_0, s32 param_1, f32 param_2, s32 param_3, s32 param_4)
{
  s32 temp_t7;
  s32 new_var;
  temp_t7 = ((PlayerState **) D_80135490)[temp_t7 = param_0];
  if ((param_2 < 0.0f) || (func_8008DDEC(temp_t7, param_1, param_2) != 0))
  {
    new_var = temp_t7;
    return func_8008F568((0, new_var), param_3, param_4);
  }
  return 0;
}

s32 func_800F7270(s32 param_0, f32 *param_1, f32 param_2, f32 param_3, s32 param_4, s32 param_5) {
    if (func_8008DEA4(((void * *) D_80135490)[param_0], param_1, param_3) != 0) {
        return func_800F7200(param_0, param_1, param_2, param_4, param_5);
    }
    return 0;
}

int func_800F72DC(s32 param_0)
{
  s32 x = ((PlayerState **) D_80135490)[param_0];
  return func_8009640C(x) || baflag_isTrue(x, 0x26);
}

int func_800F732C()
{
  D_801354DA = 1;
  func_800F482C(0x11);
  func_800F482C(0);
  D_801354DA = 0;
}

void func_800F7364(s32 param_0)
{
  u32 *local_0 = (u32 *)((char *)D_80135490 + (param_0 << 2));
  if (*local_0 != 0)
  {
    func_80092AA4(*local_0);
  }
}

int func_800F739C(s32 param_0, s32 param_1)
{
  func_800C7074(param_1 | 0, 1);
}

void func_800F73C4(s32 param_0) {
    s32 local_0, local_1, local_2, local_3, local_4, local_6;
    (*((StateF73C4 *) D_80135490)).local_3 = 0;
    (*((StateF73C4 *) D_80135490)).local_2 = 0;
    for (local_0 = 0; local_0 < 8; local_0++) {
        (*((StateF73C4 *) D_80135490)).local_0[local_0] = 0;
        (*((StateF73C4 *) D_80135490)).local_1[local_0] = 0;
    }
    (*((StateF73C4 *) D_80135490)).local_5 = -1;
    (*((StateF73C4 *) D_80135490)).local_4 = (*((StateF73C4 *) D_80135490)).local_5;
    func_800F80D8(0);
    if (!func_800DB9B0() && !_glcutDll_entrypoint_1() && !func_800F99E8()) {
        for (local_0 = 0; local_0 < param_0; local_0++) func_800F61E4();
    }
    func_800F8B94();
    local_1 = 0;
    for (local_0 = 0; local_0 < func_800F5898(); local_0++) {
        if (func_800F6BE4(local_0)) local_1++;
    }
    if (!local_1) func_800F7E64(func_800F61E4(), 4);
    if (func_800F8B88() == 2) {
        local_2 = _plsu_entrypoint_1(10);
        local_3 = _plsu_entrypoint_1(11);
        if (local_2 != -1 && local_3 != -1) {
            if (func_800F65D0(local_3)) local_4 = local_3;
            else if (func_800F65D0(local_2)) local_4 = local_2;
            else local_4 = _plsu_entrypoint_1(17);
            func_800F8128(local_4);
        }
    }
    for (local_0 = 0; local_0 < 8; local_0++) {
        if ((*((StateF73C4 *) D_80135490)).local_0[local_0]) _basetup_entrypoint_2((*((StateF73C4 *) D_80135490)).local_0[local_0]);
    }
}

void func_800F759C(s32 param_0)
{
    if (D_801354D9 != 0) {
        func_800F82C0(param_0);
        return;
    }
    func_80101238(0xB5, param_0);
    func_800F3880(*(s32*)((char*)((u8 *) D_80135490) + (param_0 * 4)));
    func_800A91F4(param_0);
    *(s32*)((char*)((u8 *) D_80135490) + (param_0 * 4)) = 0;
    *(u8*)((char*)D_801354B0 + param_0) = 0;
}

void func_800F7620(s32 param_0, f32 param_1, f32 param_2, s32 param_3)
{
  s32 *new_var;
  new_var = &param_0;
  _bamotor_entrypoint_1(((void * *) D_80135490)[*new_var], param_1, param_2);
}

void func_800F7664(s32 p0, s32 p1, s32 p2) {
    s32 t = ((PlayerState **) D_80135490)[p0];
    func_8009AD20(t, p1);
    func_8009AD2C(t, p2);
    func_8009E7C8(t, 0x7D);
}

int func_800F76B0(s32 param_0, s32 param_1, f32 *param_2)
{
    s32 local_0;
    local_0 = *(s32*)((char*)D_80135490 + param_0 * 4);
    func_8009AD20(local_0, param_1);
    func_8009AD14(local_0, param_2);
    return func_8009E7C8(local_0, 0x24) == 2;
}

s32 func_800F7700(u32 param_0, s32 param_1, f32 *param_2) {
    s32 local_0 = ((PlayerState **) D_80135490)[param_0];
    func_8009AD20(local_0, param_1);
    func_8009AD44(local_0, param_2);
    return func_8009E7C8(local_0, 0x23) == 2;
}

s32 func_800F7750(s32 param_0, s32 param_1, f32 param_2, f32 param_3, s32 param_4)
{
  s32 local_0;
  s32 local_1;
  local_1 = ((PlayerState **) D_80135490)[param_0];
  if (param_4 != 0)
  {
    local_0 = 0x98;
  }
  else
  {
    local_0 = 0x2D;
  }
  func_8009ACF4(local_1, param_2);
  func_8009AD04(local_1, param_3);
  func_8009AD20(local_1, 0xE);
  func_8009AD44(local_1, param_1);
  return func_8009E7C8(local_1, local_0) == 2;
}

int func_800F77E8(int param_0, int param_1) {
    func_800F7750(param_0, param_1, 840.0f, -1500.0f, 0);
}

void func_800F7814(s32 p0, s32 p1) {
    func_800F7750(p0, p1, 840.0f, -1500.0f, 1);
}

void func_800F7844(s32 param_0, s32 param_1, f32 param_2, f32 param_3)
{
  func_800F7750(param_0, param_1, param_2, param_3, 0);
}

s32 func_800F7874(s32 param_0, s32 param_1, u32 param_2)
{
  s32 local_0;
  local_0 = D_80135490[param_0];
  ;
  func_8009AD44(local_0, param_2);
  func_8009AD14(local_0, param_1);
  return func_8009E7C8(local_0, 0x66) == 2;
}

void func_800F78C8(s32 arg0,s32 arg1)
{
    func_800F7C58(arg0,0x17,arg1);
}

s32 func_800F78EC(s32 param_0, f32 *param_1, f32 param_2, f32 param_3) {
  f32 *var = ((f32 * *) D_80135490)[param_0];
  func_8009ACF4(var, param_2);
  func_8009AD04(var, param_3);
  func_8009AD20(var, 0xE);
  func_8009AD44(var, param_1);
  return func_8009E7C8(var, 0x68) == 2;
}

void func_800F796C(s32 arg0,s32 arg1)
{
    func_800F798C(arg0,arg1,0x1);
}

int func_800F798C(s32 param_0, s32 param_1, f32 *param_2)
{
    s32 local_0;
    local_0 = *(s32*)((char*)D_80135490 + param_0 * 4);
    func_8009AD20(local_0, param_1);
    func_8009AD2C(local_0, param_2);
    return func_8009E7C8(local_0, 0x1f) == 2;
}

int func_800F79DC(s32 param_0, s32 param_1, f32 *param_2)
{
    s32 local_0;
    local_0 = *(s32*)((char*)D_80135490 + param_0 * 4);
    func_8009AD20(local_0, param_1);
    func_8009AD14(local_0, param_2);
    return func_8009E7C8(local_0, 0x21) == 2;
}

int func_800F7A2C(s32 param_0, s32 param_1, f32 *param_2)
{
    s32 local_0;
    local_0 = *(s32*)((char*)D_80135490 + param_0 * 4);
    func_8009AD20(local_0, param_1);
    func_8009AD44(local_0, param_2);
    return func_8009E7C8(local_0, 0x20) == 2;
}

s32 func_800F7A7C(s32 param_0, s32 param_1, s32 param_2, s32 param_3, s32 param_4) {
    PlayerState *p = ((PlayerState * *) D_80135490)[param_0];
    func_8009AD38(p, param_1);
    func_8009AD20(p, param_2);
    func_8009AD2C(p, param_3);
    func_8009AD44(p, param_4);
    return func_8009E7C8(p, 0x4E) == 2;
}

int func_800F7AF4(int param_0, int param_1)
{
  func_800F7B1C(param_0, param_1, 840.0f, -1500.0f);
}

s32 func_800F7B1C(s32 param_0, s32 param_1, f32 param_2, f32 param_3)
{
    s32 new_var;
    new_var = D_80135490[param_0];
    func_8009ACF4(new_var, param_2);
    func_8009AD04(new_var, param_3);
    func_8009AD20(new_var, 0x10);
    func_8009AD44(new_var, param_1);
    return func_8009E7C8(new_var, 0x2E) == 2;
}

void func_800F7B9C(s32 arg0,u32 a1)
{
    func_8009E7C8(((PlayerState **) D_80135490)[arg0],a1);
}

void func_800F7BC8(s32 param_0, s32 param_1, Unk80132ED0 *param_2)
{
    s32 local_0;
    local_0 = *(s32*)((char*)((u32 *) D_80135490) + param_0 * 4);
    func_8009AD14(local_0, param_2);
    func_8009E7C8(local_0, param_1);
}

void func_800F7C0C(s32 param_0, f32 param_1[3], f32 param_2)
{
  s32 local_0;
  local_0 = ((PlayerState **) D_80135490)[param_0];
  func_8009ACF4(local_0, param_2);
  func_8009E7C8(local_0, param_1);
}

int func_800F7C58(s32 param_0, f32 param_1[3], s32 param_2)
{
    s32 local_0;
    local_0 = *(s32*)((char*)D_80135490 + param_0 * 4);
    func_8009AD20(local_0, param_2);
    func_8009E7C8(local_0, param_1);
}

void func_800F7C9C(s32 param_0, s32 param_1, s32 param_2, s32 param_3)
{
  s32 local_0;
  local_0 = ((PlayerState **) D_80135490)[param_0];
  func_8009AD20(local_0, param_2 | 0);
  func_8009AD2C(local_0, param_3);
  func_8009E7C8(local_0, param_1);
}

void func_800F7CF4(s32 param_0, f32 param_1[3], s32 arg2)
{
    s32 local_0;
    local_0 = *(s32*)((char*)D_80135490 + param_0 * 4);
    func_8009AD44(local_0, arg2);
    func_8009E7C8(local_0, param_1);
}

void func_800F7D38(s32 param_0, s32 param_1, u32 param_2, f32 param_3)
{
  s32 local_0;
  local_0 = D_80135490[param_0];
  func_8009AD44(local_0, param_2);
  func_8009ACF4(local_0, param_3);
  func_8009E7C8(local_0, param_1);
}

void func_800F7D90(s32 param_0, s32 param_1, s32 param_2, s32 param_3)
{
  s32 local_0;
  local_0 = *(s32*)((char*)D_80135490 + param_0 * 4);
  func_8009AD44(local_0, param_2 | 0);
  func_8009AD20(local_0, param_3);
  func_8009E7C8(local_0, param_1);
}

int func_800F7DE8(s32 param_0, s32 param_1, s32 param_2)
{
  s32 local_0;

  local_0 = D_80135490[param_0];
  func_8009AD20(local_0, param_2);
  func_8009AD14(local_0, param_1);
  return func_8009E7C8(local_0, 0x48) == 2;
}

int func_800F7E3C(s32 param_0, s32 param_1)
{
  u32 local_0;
  local_0 = func_800F7C58(param_0, 0x84, param_1 | 0);
  return local_0 == 2;
}

void func_800F7E64(s32 param_0, f32 param_1[3])
{
  s32 local_0;
  local_0 = ((PlayerState **) D_80135490)[param_0];
  func_800A3410(local_0, param_1);
  func_80092778(local_0);
}

int func_800F7E9C(s32 param_0, s32 param_1)
{
  if (param_1 != 0) {
        func_800A4E74(D_80135490[param_0]);
    }
}

void func_800F7ECC(s32 param_0, s32 param_1, f32 param_2) {
    bastatetimer_set(((PlayerState **) D_80135490)[param_0], param_1, param_2);
}

void func_800F7F00(s32 param_0, s32 param_1, s32 param_2, f32 param_3, s32 param_4, s32 param_5, f32 param_6) {
    func_80098778(D_80135490[param_0], param_1, param_2, param_3, param_4, param_5, param_6);
}

int func_800F7F50(int param_0, int param_1, int param_2, f32 param_3, int param_4, int param_5)
{
    return func_80098730(D_80135490[param_0], param_1, param_2, param_3, param_4, param_5);
}

void func_800F7F98(s32 param_0, s32 param_1)
{
    void *local_0;
    void *local_4;
    local_0 = ((void * *) D_80135490)[param_0];
    if (param_1 != 0) {
        local_4 = local_0;
        bakey_func_80091C14(local_4, 1);
        bastick_func_8009F18C(local_0, 1);
    } else {
        local_4 = local_0;
        bakey_func_80091C14(local_4, 0);
        bastick_func_8009F18C(local_0, 0);
    }
    return;
}

int func_800F8004(s32 param_0) {
    /* HEADER DEPENDENCY: Also push data/header/include/core2/1ECE0B0.h; this function returns int, not s32 (long). */
    int local_1;
    s32 local_0;
    int local_2;
    local_0 = ((PlayerState **) D_80135490)[param_0];
    local_1 = bakey_getBitfield(local_0) != 0 || bakey_func_80091964(local_0) != 0;
    local_2 = bastick_func_8009F1A4(local_0) != 0 || bastick_func_8009EEF8(local_0) != 0;
    return local_1 && local_2;
}

int func_800F8088(param_0) s32 param_0;
{
  u32 local_0;
  u32 local_1;
  u32 local_2;

  local_2 = D_80135490[param_0];
  local_0 = bakey_getBitfield(local_2);
  local_1 = bastick_func_8009F1A4(local_2);
  return local_0 && local_1;
}

void func_800F80D8(u32 arg0) {
	D_801354DC = arg0;
}

void func_800F80E4(s32 param_0, u32 param_1)
{
    u32 local_0;
    u32 local_1;

    local_1 = ((u32 *) D_80135490)[param_0];
    if (param_1 != 0)
    {
        local_0 = 0;
    }
    else
    {
        local_0 = 1;
    }
    func_800947EC(local_1, 1, local_0);
}

void func_800F8128(s32 arg0)
{
    func_800F80D8(arg0);
    func_800A91A8(arg0);
}
void func_800F8150(s32 arg0)
{
    func_80093370(((PlayerState **) D_80135490)[arg0]);
}

void func_800F817C(s32 arg0)
{
    func_8009337C(((PlayerState **) D_80135490)[arg0]);
}

void func_800F81A8(s32 arg0)
{
    func_800A1870(((PlayerState **) D_80135490)[arg0]);
}

void func_800F81D4(s32 arg0)
{
    _bafpctrl_entrypoint_12(((PlayerState **) D_80135490)[arg0]);
}

void func_800F8200(s32 arg0)
{
    func_800F4524(((PlayerState **) D_80135490)[arg0]);
}

void func_800F822C(s32 param_0, f32 param_1, f32 param_2) {
  _bahold_entrypoint_7(((PlayerState **) D_80135490)[param_0], param_1, param_2);
}

void func_800F8268(s32 arg0,s32 a1, s32 a2)
{
    func_800A38F0(((PlayerState **) D_80135490)[arg0],a1,a2);
}

void func_800F8294(s32 arg0,f32* a1)
{
    func_800F452C(((PlayerState **) D_80135490)[arg0],a1);
}

void func_800F82C0(param_0) s32 param_0;
{
  ((u8 *) D_801354B0)[param_0] = 1;
}

void func_800F82D4(s32 arg0,s32 arg1)
{
    func_800F457C(((PlayerState **) D_80135490)[arg0],arg1);
}

void func_800F8300(s32 arg0)
{
    func_800F45B0(((PlayerState **) D_80135490)[arg0]);
}

void func_800F832C(s32 arg0,f32* a1)
{
    func_800F45E0(((PlayerState **) D_80135490)[arg0],a1);
}

void func_800F8358(s32 param_0, s32 param_1)
{
  s32 idx = param_0;
  s32 val = ((PlayerState **) D_80135490)[idx];
  _baduo_entrypoint_7(val, 3);
}

void func_800F838C(s32 arg0)
{
    func_8008F748(((PlayerState **) D_80135490)[arg0]);
}

void func_800F83B8(s32 arg0)
{
    func_800A3514(((PlayerState **) D_80135490)[arg0]);
}

void func_800F83E4(s32 param_0, f32 param_1) {
    baphysics_set_vertical_velocity(((PlayerState **) D_80135490)[param_0], param_1);
}

void func_800F8418(s32 arg0, f32 *arg1)
{
    func_800F4648(((PlayerState **) D_80135490)[arg0], arg1);
}

void func_800F8444(s32 param_0, s32 *param_1)
{
    s32 temp_a0;
    temp_a0 = ((PlayerState **) D_80135490)[param_0];
    func_8009BF5C(temp_a0, param_1[0]);
    yaw_setIdeal(temp_a0, *(f32 *)&param_1[1]);
    baroll_setIdeal(temp_a0, param_1[2]);
}

void func_800F849C(s32 param_0, f32 param_1) {
    func_8009BD18(((PlayerState **) D_80135490)[param_0], param_1);
}

void func_800F84D0(s32 arg0)
{
    func_8009659C(((PlayerState **) D_80135490)[arg0]);
}

void func_800F84FC(void)
{
    f32 local_0, local_1;
    f32 local_2;
    f32 local_3[3];
    s32 local_4, local_5;
    s32 local_6, local_7;
    s32 local_8;
    for (local_4 = 0; local_4 < 8; local_4++) {
        if ((*((LocalState_800F84FC *) D_80135490)).players[local_4] && func_800F5924(local_4)) {
            func_800F5A00(local_4, local_3);
            func_800F5950(local_4, &local_0, &local_1, &local_2);
            for (local_5 = 0; local_5 < 8; local_5++) {
                if ((*((LocalState_800F84FC *) D_80135490)).players[local_5] && local_4 != local_5 && func_800F58F8(local_5))
                    func_800F4EC8(local_5, local_3, local_0, local_1, local_2);
            }
        }
    }
    (*((LocalState_800F84FC *) D_80135490)).updating = 1;
    for (local_8 = 0; local_8 < 8; local_8++) {
        if ((*((LocalState_800F84FC *) D_80135490)).players[local_8]) func_800F468C((*((LocalState_800F84FC *) D_80135490)).players[local_8]);
    }
    (*((LocalState_800F84FC *) D_80135490)).updating = 0;
    func_800F9198();
    local_6 = func_800F54E4();
    local_7 = func_800F5410(local_6);
    if ((*((LocalState_800F84FC *) D_80135490)).previous != -1 && (local_6 != (*((LocalState_800F84FC *) D_80135490)).previous || local_7 != (*((LocalState_800F84FC *) D_80135490)).previous_state) && !func_800D5240()) func_800A1658(local_7);
    for (local_8 = 0; local_8 < 8; local_8++) {
        if ((*((LocalState_800F84FC *) D_80135490)).flags[local_8]) func_800F759C(local_8);
    }
    (*((LocalState_800F84FC *) D_80135490)).previous = local_6;
    (*((LocalState_800F84FC *) D_80135490)).previous_state = local_7;
}

void func_800F86C4(s32 param_0, s32 param_1)
{
  *(s16*)((char*)((s16 *) D_80135490) + 0x50) = (s16)param_0;
  *(s16*)((char*)((s16 *) D_80135490) + 0x52) = (s16)param_1;
}

void func_800F86D8()
{
  s32 *s0;
  s32 *s1;
 s1 = D_80135490; s0 = D_801354B0;
  do
  {
    if ((*s1) != 0)
    {
      *s1 = func_800F46D8(*s1);
    }
    s1++;
  }
  while (s1 != s0);
}

s32 func_800F8730(s32 param_0, s32 param_1) {
    s32 local_0;
    s32 local_1;

    local_0 = D_80135490[param_0];
    func_800A3538(local_0);
    local_1 = func_8009E7C8(local_0, 0xA) == 2;
    if (local_1 && (func_800F5410(param_0) != param_1)) {
        _surestart_entrypoint_0(param_1);
    }
    return local_1;
}

s32 func_800F87A4(s32 param_0)
{
  Unk80132ED0 *local_0;
  s32 new_var;
  local_0 = (Unk80132ED0 *) ((u32 *) D_80135490)[param_0];
  if (func_800F56D8(param_0))
  {
    if (func_8009E674(local_0, 0x400))
    {
      new_var = func_8009E7C8(local_0, 0x16);
      return new_var == 2;
    }
  }
  return 0;
}

void func_800F8804(s32 arg0)
{
    func_8009CD70(((PlayerState **) D_80135490)[arg0]);
}

void func_800F8830(s32 arg0)
{
    func_8009E7C8(arg0,0x99);
}

void func_800F8850()
{
  func_800F47C0(&func_800F8830);
}

void func_800F8874(s32 arg0)
{
    func_8009224C(((PlayerState **) D_80135490)[arg0]);
}
