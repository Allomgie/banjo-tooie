#include "common.h"
#include "overlays/ba/playerstate.h"

extern s32 func_8010D5DC;
extern u8 unk74[];
extern int func_8008E938(void *param_0);
extern void *func_800CB840(int param_1, int param_2);
extern void func_800CB870(void);
extern void func_80109C4C(int param_1, int param_2, int param_3, void *param_4, int param_5, int param_6, int param_7);
extern s32 bs_getCurrentState(PlayerState *);
extern s32 func_800A3274(PlayerState *);
extern s32 baflag_isTrue(PlayerState *, s32);
extern s32 func_8008DC90(PlayerState *, f32 *, f32);
extern s32 func_8008DAE8(PlayerState *, f32 *, f32);
extern Actor *func_80106790(Unk80132ED0 *);
extern s32 func_8008E92C(PlayerState *);
extern s32 _bstrexsmall_entrypoint_7(PlayerState *, f32 *);
extern s32 _bstrexlarge_entrypoint_7(PlayerState *, f32 *);
extern f32 baphysics_get_vertical_velocity(PlayerState *);
extern s32 player_isStable(PlayerState *);
extern void func_8008E9A0(s32, s32);
extern s32 func_800D1B34(s32);
extern s32 func_800D1C38(s32);
extern void func_800904C8(s32);
typedef struct { void *marker; u8 pad[0x60]; u32 unused:8, flag:1, rest:23; } LocalObject;
extern f32 yaw_get(s32);
extern LocalObject *func_80108474(s32, f32 *, s32);
typedef struct { u8 pad0[0x6C]; u32 f1 : 11; u32 fld : 12; u32 f3 : 9; } S_8F6B8;
extern void *_bahold_entrypoint_5();
extern void _bahold_entrypoint_6(void *, void *);
extern s32 func_8008E9AC(void *);
extern void _chbaddiesetup_entrypoint_2(void *, s32, s32);
void func_8008EEC4();

s32 func_8008ED80(void)
{
	return 0x1;
}

void func_8008ED88(u8 *param_0, s32 param_1, s32 param_2)
{
  s32 *local_0;
  s8 *new_var;
  new_var = (s8 *) param_0;
  local_0 = func_80106790(param_2);
  func_800F497C(*((s32 *) (new_var + 0x184)));
  func_800F49A8(*((s32 *) (((s8 *) param_0) + 0x184)), 1);
  func_800F49D4(*((s32 *) (((s8 *) param_0) + 0x184)), &func_8010D5DC, *local_0);
  new_var = local_0;
  func_800F4A58(*((s32 *) (((s8 *) param_0) + 0x184)), new_var + 4, 0x43FA0000);
}

func_8008EE04(s32 param_0, s32 param_1){
    if(param_0 != 0)
        return param_1 | 0;
    return 0;
}

s32 func_8008EE1C(Actor *param_0, u32 param_1)
{
  struct ActorMarker *local_0;
  s32 local_1;

  local_0 = func_800F53D0(param_1);
  local_1 = bs_getCurrentState(local_0);
  switch (local_1) {
  case 15:
    return ((u32)((s32)((*(s32 *)((char *)(param_0) + 0x74)) << 12)) >> 31) == 0;
  case 19:
    return ((*(u16 *)((char *)(param_0) + 0x74)) & 1) == 0;
  default:
    return 1;
  }
}

int func_8008EE88(s32 param_0, s32 param_1)
{
  f32 local_0[3];
  func_8009C128(param_0, local_0);
  func_8008EEC4(param_0, local_0, param_1, 0x270);
}

void func_8008EEC4(param_0, param_1, param_2, param_3) void * param_0; s32 param_1; s32 param_2; s32 param_3;
{
    func_800CB840(1, *(s32 *)((char *)param_0 + 0x184));
    func_80109C4C(param_1, param_2, 2, &func_8008EE1C, *(s32 *)((char *)param_0 + 0x184), func_8008E938(param_0), param_3);
    func_800CB870();
}

s32 func_8008EF3C(param_0, param_1) PlayerState * param_0; Unk80132ED0 * param_1;
{
    struct { s32 predicate, flag, state, result; } local_4;

    local_4.state = bs_getCurrentState(param_0);
    switch (func_800A3274(param_0)) {
        case 2:
            return func_8008EE04(baflag_isTrue(param_0, 0x3C), 9);
        case 0xD:
            if (local_4.state == 0xF7) return func_8008EE04(baflag_isTrue(param_0, 0x2C), 0xF);
            return 0;
        case 0xE:
            if (local_4.state == 0xFC) return func_8008EE04(baflag_isTrue(param_0, 0x2B), 0xE);
            if (local_4.state == 0xFB) return func_8008EE04(baflag_isTrue(param_0, 0x2D), 0x10);
            return 0;
        case 0xF:
            if (local_4.state == 0x10E) return func_8008EE04(baflag_isTrue(param_0, 0x32), 0x11);
            return 0;
        case 0x10:
            return 0x12;
        case 0xB:
            switch (local_4.state) {
                case 0xC2:
                case 0xC4:
                    return func_8008EE04(baflag_isTrue(param_0, 0x36), 0x15);
                case 0x18A:
                case 0x18B:
                    return 0x19;
            }
            if (baflag_isTrue(param_0, 0x35)) {
                if (param_1) {
                    if (func_8008DC90(param_0, func_80106790(param_1)->position, 90.0f)) return 0x14;
                    return 0;
                }
                return 0x14;
            }
            return 0;
        case 9:
            local_4.flag = baflag_isTrue(param_0, 0x3B);
            local_4.predicate = !func_8008E92C(param_0);
            if (local_4.flag && local_4.predicate) return 0x16;
            return 0;
        case 0x12:
            if (param_1 && _bstrexsmall_entrypoint_7(param_0, func_80106790(param_1)->position)) return 0x18;
            return 0;
        case 0x13:
            if (param_1 && _bstrexlarge_entrypoint_7(param_0, func_80106790(param_1)->position)) return 0x17;
            return 0;
    }

    if (**(u8 **)((u8 *)param_0 + 0x18)) return 3;
    switch (local_4.state) {
        case 0x189:
            return func_8008EE04(baflag_isTrue(param_0, 0x3E), 0xD);
        case 0xE4:
            return func_8008EE04(baflag_isTrue(param_0, 0x28), 0xC);
        case 0xA9:
            return 5;
        case 0xB6:
            return func_8008EE04(baflag_isTrue(param_0, 0x22), 0xB);
        case 0xF:
            return func_8008EE04(baflag_isTrue(param_0, 0x21), 1);
        case 0x13:
            return func_8008EE04(baflag_isTrue(param_0, 0x20), 2);
        case 0xB4:
            return func_8008EE04(baflag_isTrue(param_0, 0x20), 2);
        case 0x2A:
            return func_8008EE04(baflag_isTrue(param_0, 0x1C), 3);
        case 6:
            if (param_1 && !func_8008DAE8(param_0, func_80106790(param_1)->position, 90.0f)) return 0;
            local_4.result = func_8008EE04(baflag_isTrue(param_0, 0x1F), 4);
            if (local_4.result) return local_4.result;
            return 8;
        case 0x11:
            if (param_1 && !func_8008DAE8(param_0, func_80106790(param_1)->position, 60.0f)) return 0;
            return func_8008EE04(baflag_isTrue(param_0, 0x2A), 5);
        case 0x1A: case 0x1B: case 0x1C: case 0x1D: case 0x1E: case 0xA4: case 0xA5:
            return 6;
        case 0x31:
            return func_8008EE04(baflag_isTrue(param_0, 0x29), 7);
        case 5: case 0x3D:
            if (baphysics_get_vertical_velocity(param_0) < 0.0f && !player_isStable(param_0)) return 0xA;
        case 0x2F:
            if (baphysics_get_vertical_velocity(param_0) < -1400.0f && !player_isStable(param_0)) return 0xA;
        case 0x124:
            return func_8008EE04(baflag_isTrue(param_0, 0x33), 0x13);
        case 0x18A:
            return 0x19;
    }
    return 0;
}

int func_8008F4F0(s32 param_0)
{
  s32 local_0;
  local_0 = func_8008EF3C();
  if (local_0 == 0xB && baflag_isTrue(param_0, 0x26))
  {
    return local_0 | 0;
  }
  if (local_0 == 1 && baflag_isTrue(param_0, 0x27))
  {
    return local_0 | 0;
  }
  return 0;
}

s32 func_8008F568(s32 param_0, s32 param_1, s32 **param_2)
{
    s32 local_24;
    s32 local_20;
    s32 *local_1C;

    local_24 = **param_2;
    local_20 = _bahold_entrypoint_5();
    if (local_20 != 0)
    {
        local_1C = func_80106790(local_20);
    }
    if ((local_20 != 0) && (param_1 != ((u32)(*(s32*)((char*)local_1C + 0x6C) << 11) >> 20)))
    {
        return 0;
    }
    func_8008E9A0(param_0, param_1);
    if (func_800D1C38(func_800D1B34(param_1)) != 0)
    {
        goto L_8008F600;
    }
    func_800904C8(0x12);
    goto L_8008F608;
L_8008F600:
    return 0;
L_8008F608:
    *param_2 = func_80106790(local_24);
    return 1;
}

void func_8008F62C(s32 param_0, s32 param_1)
{
    s32 local_1;
    LocalObject *local_2;
    f32 local_0[3];
    local_1 = func_800F53D0(param_0);
    func_80092D44(local_1, local_0);
    local_2 = func_80108474(param_1, local_0, (s32)yaw_get(local_1));
    local_2->flag = 1;
    _bahold_entrypoint_6(local_1, local_2->marker);
    if (!func_8009E674(local_1, 0x400)) bs_setState(local_1, 0x3A);
}

void func_8008F6B8(void *param_0, s32 param_1) {
    void *a;
    S_8F6B8 *b;
    a = _bahold_entrypoint_5(param_0);
    if (a != 0) { b = func_80106790(a); }
    if ((a != 0) && (param_1 == b->fld)) {
        _bahold_entrypoint_6(param_0, a);
    } else {
        _chbaddiesetup_entrypoint_2(func_8008F62C, *(s32 *)((u8 *)param_0 + 0x184), func_8008E9AC(param_0));
    }
}

void func_8008F748(s32 param_0, s32 param_1, s32 param_2)
{
    f32 sp1C[3];

    _gspropctrl_entrypoint_11(_gccubesearch_entrypoint_0(param_1, param_2), sp1C);
    func_800A3514(param_0, sp1C);
}

s32 func_8008F788(s32 param_0, s32 param_1){
    func_800D1844(func_800D1B34(param_1));
}

void func_8008F7B4(s32 param_0, s32 param_1) {
    s32 local_3;
    u8 *local_1;

    local_3 = _bahold_entrypoint_5();
    if (local_3 != 0) {
        local_1 = func_80106790(local_3);
    }
    if ((local_3 != 0) && (param_1 == ((u32) ((*(s32 *)((s8 *)(local_1) + (0x6C))) << 0xB) >> 0x14))) {
        _bahold_entrypoint_4(param_0);
    }
    func_800D1804(func_800D1B34(param_1));
}

s32 func_8008F828(s32 param_0, s32 param_1){
    func_800D1A04(func_800D1B34(param_1));
}

int func_8008F854(s32 param_0, s32 param_1)
{
  int new_var;
  new_var = param_0;
  func_800D1824(func_800D1B34(new_var | (new_var = param_1)));
}

int func_8008F880(s32 param_0, s32 param_1)
{
  s32 local_0;
  local_0 = func_80106790(param_0);
  func_800EE7F8(param_1, local_0 + 4);
}
