#include "core2/1EDB4D0.h"
#include "core2/anctrl.h"
#include "core2/1EBA250.h"
void func_8008B2DC(AnimCtrl *, f32);

extern s32 anctrl_getPlaybackType(s32);
typedef struct { f32 local_0; u16 local_1; u16 local_2; } local_entry_80101BE0;
typedef struct { u8 local_0 : 6; u8 local_1 : 2; } bits_80101BE0;
extern f32 func_8008B2AC(s32);
typedef struct _AnCtrl AnCtrl;
typedef struct { f32 local_0; u16 local_1; u16 local_2; } local_entry_80101F64;
typedef struct { f32 local_0; u16 local_1; u16 local_2; } local_entry_801021BC;
extern void *func_80104248();
typedef struct { u8 pad0[0x78]; u32 f0 : 12; u32 bit : 1; u32 f2 : 19; } S_102394;
typedef struct { u8 pad0[8]; void *unk8; } R_102394;
extern s32 func_8010108C(S_102394 *, s32, s32);
extern void *func_80101080(void);
extern R_102394 *func_80100368(S_102394 *);
typedef struct { s16 field_0, field_2, field_4; u16 field_6; } LocalConfig;
extern void func_8008B4A8(AnimCtrl *, s32);
extern s32 func_800DC298(f32);
extern f32 func_800DC0C0(void);
extern void *func_800AE080(s16);
extern Unkfunc_800E0960_1 *func_800AE6BC(void *);
extern s32 func_800E09B8(s32);
extern void func_800AE6FC();
extern s32 func_800D3E40(u32);
void *func_80102394();
void func_80102424();

int func_80101BE0(void *param_0, u32 param_1)
{
  local_entry_80101BE0 *local_0;
  s32 local_2;
  local_0 = (local_entry_80101BE0 *)func_80102394(param_0);

  ((bits_80101BE0 *)((u8 *)param_0 + 0x72))->local_0 = param_1;
  if (local_0 == 0)
  {
    return 0;
  }
  if (local_0[param_1].local_1 != 0)
  {
    local_2 = func_80104248(param_0);
    if (local_2 == 0)
    {
      local_2 = func_801042B8(param_0);
      anctrl_reset(local_2);
    }
    if (anctrl_getPlaybackType(local_2) == 3)
    {
      anctrl_setPlaybackType(local_2, 2);
    }
    anctrl_setIndex(local_2, local_0[param_1].local_1);
    anctrl_setDuration(local_2, local_0[param_1].local_0);
    func_8008B188(local_2, 1);
  }
  else
  {
    func_80104328(param_0);
  }
  return 1;
}

void func_80101CDC(Actor *param_0, f32 param_1)
{
  Actor *local_0 = func_80104248(param_0);
  if (local_0)
    anctrl_setDuration(local_0, param_1);
}

f32 func_80101D0C()
{
  s32 v;
  v = func_80104248();
  if (v)
  {
    return func_8008B2AC(v);
  }
  return 0.0f;
}

int func_80101D4C()
{
  AnCtrl *local_0;
  local_0 = func_80104248();
  if (local_0 != 0)
  {
    anctrl_setPlaybackType(local_0, 1);
  }
}

void func_80101D7C()
{
  void *local_0 = func_80104248();
  if (local_0 != NULL)
  {
    anctrl_setPlaybackType(local_0, 2);
  }
}

int func_80101DAC(s32 param_0, s32 param_1)
{
  s32 local_0;
  local_0 = func_80104248(param_0);
  if (local_0 != 0)
  {
    func_8008B4A8(local_0, param_1);
  }
}

s32 func_80101DDC(Actor *param_0) {
    s32 t = func_80104248(param_0);
    if (t == 0) { return 0; }
    return anctrl_isStopped(t);
}

s32 func_80101E14(Actor *param_0, f32 param_1)
{
  void *local_0;
  local_0 = func_80104248(param_0);
  if (!local_0)
  {
    return 0;
  }
  else
  {
    return anctrl_isAt(local_0, param_1);
  }
}

s32 func_80101E4C(Actor *param_0, f32 *param_1)
{
  f32 *s0;
  f32 *s1;
  s32 s2;
  f32 f0;
  s0 = param_1;
  s2 = 0;
  if ((*param_1) != (-1.0f))
  {
    while (1)
    {
      if (func_80101E14(param_0, *s0) != 0)
      {
        return s2 + 1;
      }
      s2++;
      s0++;
      if ((*s0) == (-1.0f))
      {
        break;
      }
    }

  }
  return 0;
}

void func_80101EE4(s32 param_0, f32 param_1)
{
  Actor *local_0;
  local_0 = func_80104248(param_0);
  if (local_0 != 0)
  {
    func_8008B10C(local_0, param_1);
    func_8008B2DC(local_0, param_1);
  }
}

f32 func_80101F24(Actor *param_0) {
    void *p = func_80104248(param_0);
    if (p != 0) { return anctrl_getAnimTimer(p); }
    return 0.0f;
}

int func_80101F64(param_0, param_1) s32 param_0; s32 param_1; {
    local_entry_80101F64 *local_0;
    s32 local_1;
    local_0 = func_80102394(param_0);
    local_1 = func_80104248(param_0);
    if (local_1 == 0) return 1;
    if (local_0 != 0) return anctrl_getIndex(local_1) != local_0[param_1].local_1;
    return 1;
}

void func_80101FDC(Actor *param_0, u32 param_1)
{
    void *local_0;
    s32 local_1;

    local_0 = func_80101F64();
    if (func_80101BE0(param_0, param_1) != 0) {
        local_1 = func_80104248(param_0);
        if ((local_1 != 0) && (local_0 != 0)) {
            anctrl_start(local_1);
        }
    }
}

f32 func_8010203C(s32 param_0, s32 param_1) {
    void *temp_v0;

    temp_v0 = func_80102394(param_0);
    if (temp_v0 == 0) {
        return 0.0f;
    }
    return *( (f32 *)((double *)temp_v0 + param_1) );
}

int func_80102078(s32 param_0, f32 param_1)
{
  s32 local_0;
  local_0 = func_80104248(param_0);
  if (local_0 != 0)
  {
    func_8008B1C8(local_0, param_1);
  }
}

int func_801020A8()
{
    s32 local_0;
    local_0 = func_80104248();
    if (local_0 != 0)
    {
        func_8008B1C8(local_0, 0.2f);
    }
}

int func_801020DC(s32 param_0, s32 param_1)
{
  Actor *local_0;
  local_0 = func_80104248(param_0);
  if (local_0 != NULL)
  {
    anctrl_setSmoothTransition(local_0, param_1 == 1 ? 1 : 0);
  }
}

s32 func_80102128(s32 param_0, s32 param_1, s32 param_2, f32 param_3, s32 param_4) {
    extern s32 func_800DC298(f32);
    if ((func_8001210C(param_1) == param_2) && (func_800DC298(param_3) != 0)) {
        if (param_4 != -1) {
            func_80102424(param_0, param_4);
        }
        return 1;
    }
    return 0;
}

int func_80102190(u8 *param_0, s32 param_1)
{
  short new_var;
  new_var = 0xFFFFFFFFFFFFFFFFu;
  if (param_1 != 0)
  {
    param_0[0x74] &= (((((((((((((~0x8) & 0xFFFFFFFFFFFFFFFFu) & 0xFFFFFFFFFFFFFFFFu) & 0xFFFFFFFFFFFFFFFFu) & 0xFFFFFFFFFFFFFFFFu) & 0xFFFFFFFFFFFFFFFFu) & 0xFFFFFFFFFFFFFFFFu) & 0xFFFFFFFFFFFFFFFFu) & new_var) & 0xFFFFFFFFFFFFFFFFu) & 0xFFFFFFFFFFFFFFFFu) & 0xFFFF) & 0xFFFF) & 0xFFFF;
  }
  else
  {
    param_0[0x74] |= 0x8;
  }
}

int func_801021BC(s32 param_0, u32 param_1) {
    local_entry_801021BC *local_0 = func_80102394(param_0);
    return local_0 != 0 && local_0[param_1].local_1 != 0;
}

void func_80102204(u8 *param_0) {
    s32 sp2C;
    s32 sp28;
    s32 sp24;
    s32 *sp20;
    s32 sp1C;
    s32 sp18;
    s32 temp_v0;

    temp_v0 = func_80104248();
    sp18 = temp_v0;
    if (temp_v0 != 0) {
        sp2C = func_801039E4((*(s32 *)((s8 *)(param_0) + (0))));
        func_8008B304(sp18);
        sp24 = func_8008B4D4(sp18);
        sp20 = func_800DF330();
        sp1C = func_80103CDC(param_0, sp2C);
        sp28 = func_800B26F0(sp2C);
        func_800AE160(sp20, func_800B27E0(sp2C), sp24);
        _dbanim_entrypoint_0(sp28, sp1C, *sp20);
        if ((*(u8 *)((s8 *)(param_0) + (0x70))) & 1) {
            _dbanim_entrypoint_0(sp28, func_80103D00(param_0, sp2C), *sp20);
        }
        func_800DF41C(0);
        func_800DF72C(0);
    }
}

s32 func_801022E4(Actor *param_0)
{
  s32 local_0;
  local_0 = func_80104248(param_0);
  if (local_0 != 0)
  {
    return anctrl_getIndex(local_0);
  }
  return 0;
}

s32 func_80102320(void *param_0, f32 param_1, f32 param_2) {
    void *o;
    f32 t;
    s32 rv = 0;
    o = func_80104248(param_0);
    if (o != 0) {
        t = anctrl_getAnimTimer(o);
        return ((param_1 <= t) && (t <= param_2)) ? 1 : rv;
    }
    return 0;
}

void *func_80102394(param_0) S_102394 * param_0; {
    if (param_0->bit) {
        func_8010108C(param_0, 0x99, 0);
        return func_80101080();
    }
    return func_80100368(param_0)->unk8;
}

int func_801023E4(s32 param_0, s32 param_1)
{
  u16 *local_0;
  local_0 = func_80102394(param_0);
  if (!local_0)
  {
    return 0;
  }
  return ((u16*)((u8*)local_0 + param_1 * 8 + 6))[0];
}

void func_80102424(param_0, param_1) Actor * param_0; s32 param_1;
{
    LocalConfig *local_0;
    AnimCtrl *local_1;
    s32 local_2;
    s32 local_3;
    local_0 = func_80102394();
    local_1 = func_80104248(param_0);
    if (local_1 && local_0) {
        local_2 = local_0[param_1].field_6;
        anctrl_setSmoothTransition(local_1, local_2 & 0x200 ? 0 : 1);
    }
    func_80101FDC(param_0, param_1);
    local_1 = func_80104248(param_0);
    if (local_1) {
        local_3 = local_0[param_1].field_6;
        if (local_3 & 1) {
            anctrl_setPlaybackType(local_1, 2);
            func_8008B4A8(local_1, local_3 & 0x100 ? 0 : 1);
        }
        if (local_3 & 2) anctrl_setPlaybackType(local_1, 1);
        if (local_3 & 4) anctrl_setPlaybackType(local_1, 3);
        if (local_3 & 8) func_8008B188(local_1, 1);
        if (local_3 & 0x10) func_8008B188(local_1, 0);
        if (local_3 & 0x800) func_8008B188(local_1, func_800DC298(0.5f) ? 1 : 0);
        if (local_3 & 0x40) func_8008B10C(local_1, 0);
        if (local_3 & 0x80) func_8008B10C(local_1, 0.999f);
        if (local_3 & 0x400) func_8008B10C(local_1, func_800DC0C0());
        func_80102190(param_0, local_3 & 0x20 ? 1 : 0);
    }
}

s32 func_8010262C(Unk80132ED0 *param_0, u32 param_1)
{
    Unkfunc_800E0960_1 *local_0;
    void *local_1;
    s16 local_2;
    s16 local_3;
    local_3 = *(s16 *)((u8 *)param_0 + 0x10);
    local_0 = NULL;
    if (local_3 && param_1) {
        local_1 = func_800AE080(local_3);
        local_0 = func_800AE6BC(local_1);
        if (!local_0) {
            local_2 = func_800E09B8(param_1);
            func_800AE6FC(local_1, local_2);
            local_0 = func_800E0A28(local_2);
        }
        func_800E0ACC(local_0);
        func_800E0AF0(local_0, 1.0f);
    }
    return (s32)local_0;
}

void func_801026CC(Actor *param_0, Vec3f param_1, f32 param_2)
{
    f32 local_0;
    if (func_800D3E40(8)) param_2 *= 1.5f;
    if (param_2 < 100.0f) local_0 = param_1.pos.x;
    else local_0 = (param_2 - 100.0f) * param_1.pos.y + param_1.pos.x;
    if (local_0 < param_1.pos.z) local_0 = param_1.pos.z;
    func_80101CDC(param_0, local_0);
}
