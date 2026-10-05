#include "core2/1E79FD0.h"
extern f32 D_80125490;

#define STATE(p) (*(LocalState **)((u8 *)(p) + 0x150))
extern s32 func_80092B80(s32);
typedef struct LocalModelParams { f32 value0, value1; u8 pad08[5]; u8 part0D, part0E, part0F, part10, part11, part12; u8 part13, part14, part15, part16, part17; } LocalModelParams;
typedef struct LocalModelPlayer { u8 pad00[0x138]; LocalModelParams *model; u8 pad13C[0x48]; s32 config; } LocalModelPlayer;
extern void func_800DF3E0(void);
extern void func_800DF744(s32, s32);
extern f32 func_800F1214(f32, f32, f32);
extern s32 func_800A940C(s32);
extern u8 D_80119250[];
extern u8 D_80119254[];
extern f32 func_800D8FF8(void);
extern f32 func_800964DC(PlayerState *);
extern void func_8009C128(PlayerState *, f32 *);
extern f32 func_800DC178(f32, f32);
extern void func_8009DBF0(PlayerState *, s32, f32);
extern s32 _fxsplash_entrypoint_2(f32 *, f32);
extern s32 _fxairbub_entrypoint_1(f32 *, f32, f32, f32);
extern void _fxripple_entrypoint_0(s32, f32 *);
extern void _fxsplash25d_entrypoint_0(f32 *);
typedef struct { u8 below, active, contact, pad; f32 offset; } LocalState;
extern f32 func_8009C150(PlayerState *);
extern f32 baphysics_get_vertical_velocity(PlayerState *);
void func_800A0714();
void func_800A0CD0();
void func_800A0CDC();
void func_800A0CE8();
void func_800A0D74(s32 param_0, f32 param_1);
void func_800A0D84(s32 param_0, f32 param_1);
int func_800A0DB8();
void func_800A0DC4();
void func_800A0DD0();

s32 func_800A06E0() 
{
    return 0x18;
}

void func_800A06E8(s32 param_0) {
    func_800A0714(param_0, func_80092B80(param_0));
}

void func_800A0714(param_0, param_1) LocalModelPlayer * param_0; s32 param_1;
{
    s32 local_0;
    func_800DF3E0();
    switch (param_1) {
    case 0x607:
    case 0x608:
    case 0x61F:
    case 0x992:
        if (!param_0->model->part17) {
            func_800DF744(9, param_0->model->part10);
            func_800DF744(15, param_0->model->part10);
            func_800DF744(10, param_0->model->part0E);
            func_800DF744(16, param_0->model->part0E);
            func_800DF744(11, param_0->model->part0D);
            func_800DF744(17, param_0->model->part0D);
            local_0 = param_0->model->part0F;
            func_800DF744(34, local_0);
            func_800DF744(38, local_0);
            func_800DF744(35, local_0);
            func_800DF744(39, local_0);
            local_0 = param_0->model->part11 + 1;
            func_800DF744(42, local_0);
            func_800DF744(46, local_0);
            func_800DF744(43, local_0);
            func_800DF744(47, local_0);
        }
        func_800DF744(3, param_0->model->part12);
        func_800DF744(4, param_0->model->part12);
        func_800DF744(7, param_0->model->part12);
        func_800DF744(18, param_0->model->part12);
        local_0 = func_800F1214(param_0->model->value0, 1.0f, 8.0f);
        func_800DF744(53, local_0);
        func_800DF744(57, local_0);
        local_0 = func_800F1214(param_0->model->value1, 1.0f, 8.0f);
        func_800DF744(52, local_0);
        func_800DF744(56, local_0);

        break;
    case 0x61C:
    case 0x83A:
    case 0x993:
        if (param_0->model->part15) func_800DF744(3, 2);
        else func_800DF744(3, 1);
        local_0 = param_0->model->part0F;
        func_800DF744(6, local_0);
        func_800DF744(7, local_0);
        local_0 = param_0->model->part11 + 1;
        func_800DF744(4, local_0);
        func_800DF744(5, local_0);
        func_800DF744(0x33, (s32)func_800F1214(param_0->model->value0, 1.0f, 5.0f));
        func_800DF744(0x32, (s32)func_800F1214(param_0->model->value1, 1.0f, 5.0f));
        break;
    case 0x665:
        func_800DF744(4, param_0->model->part13);
        func_800DF744(5, param_0->model->part14);
        func_800DF744(1, (s32)func_800F1214(param_0->model->value1, 1.0f, 4.0f));
        break;
    case 0x60D:
        func_800DF744(1, (s32)func_800F1214(param_0->model->value0, 1.0f, 4.0f));
        func_800DF744(2, (s32)func_800F1214(param_0->model->value1, 1.0f, 4.0f));
        break;
    case 0x609:
        func_800DF744(0x33, (s32)func_800F1214(param_0->model->value0, 1.0f, 4.0f));
        func_800DF744(0x32, (s32)func_800F1214(param_0->model->value1, 1.0f, 4.0f));
        break;
    case 0x60B:
    case 0x60C:
    case 0x623:
    case 0x624:
    case 0x626:
    case 0x998:
        func_800DF744(0x33, (s32)func_800F1214(param_0->model->value0, 1.0f, 5.0f));
        func_800DF744(0x32, (s32)func_800F1214(param_0->model->value1, 1.0f, 5.0f));
        break;
    case 0x988:
        local_0 = D_80119250[func_800A940C(param_0->config)];
        func_800DF744(5, local_0);
        func_800DF744(4, local_0);
        func_800DF744(3, param_0->model->part16);
        break;
    case 0x98D:
        func_800DF744(4, D_80119254[func_800A940C(param_0->config)]);
        break;
    case 0x984:
    case 0x986:
        func_800DF744(1, param_0->model->part16);
        break;
    }
}

s32 func_800A0C20(PlayerState *param_0)
{
  s32 *new_var;
  s32 local_0;
  ;
  return *(((char *) (*(new_var = (s32 *) (((char *) param_0) + 0x138)))) + 0x10);
}

f32 func_800A0C2C(void *arg)
{
    return ((f32 *)(*(void **)((char *)arg + 0x138)))[0];
}

f32 func_800A0C38(u8 *param_0) {
    return (*(f32 *)((s8 *)((*(u8 **)((s8 *)(param_0) + (0x138)))) + (4)));
}

int func_800A0C44(PlayerState *param_0)
{
  PlayerState *local_0 = param_0;
  func_800A0CF4(local_0, 0);
  func_800A0CE8(local_0, 0);
  func_800A0CDC(local_0, 0);
  func_800A0D74(local_0, 0);
  func_800A0D84(local_0, 0);
  func_800A0DB8(local_0, 1);
  func_800A0DD0(local_0, 0);
  func_800A0CD0(local_0, 1);
  func_800A0DC4(local_0, 0);
}

void func_800A0CD0(arg, v) void * arg; s32 v;
{
    ((s8 *)(*(void **)((char *)arg + 0x138)))[18] = v;
}

void func_800A0CDC(param_0, param_1) PlayerState * param_0; s32 param_1;
{
  *(u8 *)(*(s32 *)((char *)param_0 + 0x138) + 0xD) = param_1;
}

void func_800A0CE8(param_0, param_1) PlayerState * param_0; s32 param_1; {

    *(s8 *)((char *)(*(s32 **)((char *)param_0 + 0x138)) + 0xE) = param_1;
}

void func_800A0CF4(PlayerState* arg0, s32 arg1) 
{
    func_800A0D14(arg0, arg1, 0.0f);
}

void func_800A0D14(PlayerState *player, s32 param_1, f32 param_2) {

    *(f32 *)((char *)((*(s32 *)((char *)(player) + 312))) + 0x8) = param_2;
    *(u8 *)((char *)((*(s32 *)((char *)(player) + 312))) + 0xC) = param_1;
    if (param_2 == 0.0f) {
        *(u8 *)((char *)((*(s32 *)((char *)(player) + 312))) + 0x10) = param_1;
    }
}

void func_800A0D44(int param_0, int param_1)
{
  func_800A0D14(param_0, param_1, 0.2f);
}

void func_800A0D68(void *arg, s32 v)
{
    ((s8 *)(*(void **)((char *)arg + 0x138)))[23] = v;
}

void func_800A0D74(s32 param_0, f32 param_1)
{
  *(f32 *)(*(s32 *)(param_0 + 0x138)) = param_1;
}

void func_800A0D84(s32 param_0, f32 param_1)
{
  *(f32 *)(*(s32 *)(param_0 + 0x138) + 0x4) = param_1;
}

void func_800A0D94(void *arg, s32 v)
{
    ((s8 *)(*(void **)((char *)arg + 0x138)))[22] = v;
}

s32 func_800A0DA0(PlayerState *param_0, s32 param_1)
{
  *(u8 *)(*(s32 *)((char *)param_0 + 0x138) + 0x14) = param_1;
}

void func_800A0DAC(PlayerState *param_0, s32 param_1)
{
  *(u8 *)(*(s32 *)((char *)param_0 + 0x138) + 0x13) = param_1;
}

int func_800A0DB8(param_0, param_1) s32 param_0; long param_1;
{
  s32 local_0;
  local_0 = param_0 ^ 0;
  local_0 += 0x138;
  *(((s8 *) (*((u8 **) local_0))) + 0xF) = param_1;
}

void func_800A0DC4(param_0, param_1) PlayerState * param_0; s32 param_1;
{
    *(u8 *)((char *)(*(s32 **)((char *)(param_0) + 0x138)) + 0x15) = (s8)param_1;
}

void func_800A0DD0(param_0, param_1) PlayerState * param_0; s32 param_1; {
    s32 *local_0;
    local_0 = (s32 *)((u8 *)param_0 + 0x138);
    *(u8 *)(*local_0 + 17) = (u8)param_1;
}

void func_800A0DDC(void *param_0)
{
  u8 *temp_v0;
  if ((*((f32 *) ((*((u8 **) (((u8 *) param_0) + 0x138))) + 8))) != 0.0f)
  {
    *((f32 *) ((*((u8 **) (((u8 *) param_0) + 0x138))) + 8)) -= func_800D8FF8();
    if ((*((f32 *) ((*((u8 **) (((u8 *) param_0) + 0x138))) + 8))) <= 0.0f)
    {
      *((u8 *) ((*((u8 **) (((u8 *) param_0) + 0x138))) + 0x10)) = *((u8 *) ((*((u8 **) (((u8 *) param_0) + 0x138))) + 0xC));
    }
  }
}

s32 func_800A0E50() 
{
    return 0x14;
}

f32 func_800A0E58(struct SomeStruct *param_0) {

    return *(f32 *)((char *)(*(s32 **)((char *)param_0 + 0x150)) + 0x8);
}

void func_800A0E64(PlayerState *param_0)
{
    f32 local_0[3];
    s32 local_1;
    f32 local_2;
    if (func_80096544(param_0)) {
        func_8009DBF0(param_0, 0x409, func_800DC178(D_80125490, 0.75f));
        func_8009C128(param_0, local_0);
        local_2 = func_800964DC(param_0);
        local_0[1] = local_2;
        local_1 = _fxsplash_entrypoint_2(local_0, 35.0f);
        _fxripple_entrypoint_0(3, local_0);
        func_800BA930(local_1, -350, 300, -350, 350, 500, 350);
        func_800BA22C(local_1, 10);
        func_800BA930(local_1, -150, 500, -150, 150, 800, 150);
        func_800BA22C(local_1, 10);
        _fxsplash25d_entrypoint_0(local_0);
        local_0[1] -= 30.0f;
        local_1 = _fxairbub_entrypoint_1(local_0, 20.0f, local_2, 1.0f);
        func_800BA930(local_1, -60, -250, -60, 60, -150, 60);
        func_800BA22C(local_1, 8);
    }
}

s32 func_800A0FCC(s32 param_0)
{
    return ((u8 *)(*(u8 **)(param_0 + 0x150)))[2];
}

s32 func_800A0FD8(s32 param_0)
{
  int new_var2;
  s32 new_var;
  new_var = -0x150;
  new_var2 = param_0 - new_var;
  new_var = ((u8 **) new_var2)[0][0];
  return new_var;
}

s32 func_800A0FE4(s32 param_0)
{
    return ((u8 *)(*(u8 **)(param_0 + 0x150)))[1];
}

void func_800A0FF0(void *param_0) {
    (*(s8 *)((s8 *)((*(u8 **)((s8 *)(param_0) + (0x150)))) + (2))) = 1;
    (*(s8 *)((s8 *)((*(u8 **)((s8 *)(param_0) + (0x150)))) + (0))) = 0;
    (*(s8 *)((s8 *)((*(u8 **)((s8 *)(param_0) + (0x150)))) + (1))) = 0;
    (*(f32 *)((s8 *)((*(u8 **)((s8 *)(param_0) + (0x150)))) + (4))) = 50.0f;
    (*(f32 *)((s8 *)((*(u8 **)((s8 *)(param_0) + (0x150)))) + (8))) = 70.0f;
    (*(f32 *)((s8 *)((*(u8 **)((s8 *)(param_0) + (0x150)))) + (0xC))) = -1.0f;
}

void func_800A1040(PlayerState *param_0)
{
  f32 *local_0;
  f32 *local_1;
  u32 *local_2;
  local_0 = *((f32 **) (((char *) param_0) + 0x150));
  local_0[1] = local_0[3];
  if (param_0 && param_0)
  {
  }
  local_1 = *((f32 **) (((char *) param_0) + 0x150));
  local_1[2] = local_1[4];
  ;
  *((f32 *) (((char *) (*((u32 **) (((char *) param_0) + 0x150)))) + 0xC)) = -1.0f;
}

void func_800A106C(PlayerState *param_0, f32 param_1, f32 param_2)
{
  f32 *temp_v0;
  f32 *temp_v0_2;
  f32 *temp_t6;
  f32 *temp_t7;
  char *new_var;
  temp_v0 = *((f32 **) (((char *) param_0) + (0x150 & 0xFFFFu)));
  temp_v0[3] = temp_v0[1] * 1.0f;
  if (1)
  {
    if (1)
    {
    }
    temp_v0 = (char *) param_0;
    temp_v0_2 = *((f32 **) (temp_v0 + 84));
    temp_v0_2[4] = temp_v0_2[2];
    new_var = temp_v0;
    ;
    (*((f32 **) (new_var + 0x150)))[1] = param_1;
    temp_t7 = *((f32 **) (new_var + 0x150));
    (*((f32 **) (new_var + 0x150)))[2] = param_2;
  }
}

void func_800A10A0(PlayerState *param_0)
{
    f32 local_0;
    s32 local_1;
    s32 local_2;
    local_1 = STATE(param_0)->below;
    local_0 = func_800964DC(param_0) - STATE(param_0)->offset;
    if (local_1) {
        STATE(param_0)->below = func_80096524(param_0) && func_8009C150(param_0) < local_0 + 2.0f;
    } else {
        STATE(param_0)->below = func_80096524(param_0) && func_8009C150(param_0) < local_0 - 2.0f;
    }
    if (!local_1 && STATE(param_0)->below && baphysics_get_vertical_velocity(param_0) < -40.0f) func_800A0E64(param_0);
    local_2 = func_800F3ED0(param_0);
    if (func_800A0FD8(param_0)) STATE(param_0)->active = 1;
    else if (player_isStable(param_0) || local_2 == 10 || local_2 == 5) STATE(param_0)->active = 0;
    STATE(param_0)->contact = func_80096518(param_0);
}
